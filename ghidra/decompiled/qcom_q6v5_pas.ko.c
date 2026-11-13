// Decompiled by Ghidra 12.2
// Program: qcom_q6v5_pas.ko
// Image base: 00100000

//------------------------------------------------------------
// adsp_segment_dump @ 001009ec size=452
// signature: undefined adsp_segment_dump(void)
// callers: []
//------------------------------------------------------------

void adsp_segment_dump(long param_1,long param_2,void *param_3,long param_4,size_t param_5)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong uVar6;
  ulong extraout_x8;
  long lVar7;
  uint uVar8;
  char *__string;
  undefined8 *puVar9;
  
  puVar9 = *(undefined8 **)(param_1 + 0x28);
  lVar5 = *(long *)(param_2 + 0x10) + param_4;
  lVar1 = lVar5 + *(long *)(param_2 + 0x30);
  uVar6 = lVar1 - puVar9[0x57];
  if ((-1 < (int)uVar6) && (uVar6 = uVar6 & 0xffffffff, uVar6 + param_5 <= (ulong)puVar9[0x5a])) {
LAB_00100a7c:
    __memcpy_fromio(param_3,puVar9[0x59] + uVar6,param_5);
    return;
  }
  __string = *(char **)(param_2 + 0x20);
  if (__string != (char *)0x0) {
    sVar4 = strnlen(__string,0xb);
    if (sVar4 == 10) {
      iVar3 = strcmp(__string,"md_dbg_buf");
      if (iVar3 == 0) {
LAB_00100b0c:
        uVar2 = 0x68000000000713;
        if (arm64_use_ng_mappings != '\0') {
          uVar2 = 0x68000000000f13;
        }
        lVar5 = ioremap_prot(lVar5,param_5,uVar2);
        if (lVar5 != 0) {
          __memcpy_fromio(param_3,lVar5,param_5);
          iounmap(lVar5);
          return;
        }
        _dev_err(*puVar9,"failed to map custom_segment region\n");
        goto LAB_00100b68;
      }
    }
    else if (sVar4 == 0xffffffffffffffff) {
      fortify_panic("strnlen");
      uVar6 = extraout_x8;
      goto LAB_00100a7c;
    }
  }
  if (((*(char *)((long)puVar9 + 0x41a) != '\0') &&
      (iVar3 = strcmp((char *)puVar9[0x39],"modem_dtb.mdt"), iVar3 == 0)) &&
     (0 < (int)*(uint *)(puVar9 + 0x86))) {
    lVar7 = 0;
    do {
      uVar8 = (int)lVar1 - (int)*(undefined8 *)(puVar9[0x84] + lVar7);
      if ((-1 < (int)uVar8) && (param_5 + uVar8 <= *(ulong *)(puVar9[0x85] + lVar7)))
      goto LAB_00100b0c;
      lVar7 = lVar7 + 8;
    } while ((ulong)*(uint *)(puVar9 + 0x86) * 8 != lVar7);
  }
LAB_00100b68:
  _dev_err(*puVar9,"invalid copy request for segment %pad with offset %zu and size %zu)\n",
           (long *)(param_2 + 0x10),param_4,param_5);
  memset(param_3,0xff,param_5);
  return;
}



//------------------------------------------------------------
// qcom_rproc_set_dtb_firmware @ 00100bb4 size=264
// signature: undefined qcom_rproc_set_dtb_firmware(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_rproc_set_dtb_firmware(long param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    uVar4 = *(undefined8 *)(param_1 + 0x98);
    lVar5 = *(long *)(param_1 + 0x28);
    iVar1 = mutex_lock_interruptible(param_1 + 0x3d8);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x3cc) == 0) {
        sVar2 = strcspn(param_2,"\n");
        if ((int)sVar2 == 0) {
          _dev_err(uVar4,"can\'t provide empty string for DTB firmware name\n");
          uVar4 = 0xffffffea;
        }
        else {
          lVar3 = kstrndup(param_2,(long)(int)sVar2,0xcc0);
          if (lVar3 == 0) {
            uVar4 = 0xfffffff4;
          }
          else {
            if (*(long *)(lVar5 + 0x1c8) != 0) {
              kfree_const();
            }
            uVar4 = 0;
            *(long *)(lVar5 + 0x1c8) = lVar3;
          }
        }
      }
      else {
        _dev_err(uVar4,"can\'t change firmware while running\n");
        uVar4 = 0xfffffff0;
      }
      mutex_unlock(param_1 + 0x3d8);
    }
    else {
      _dev_err(uVar4,"can\'t lock rproc %s: %d\n",*(undefined8 *)(param_1 + 0x18),iVar1);
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// read_early_boot_register @ 00100cc0 size=244
// signature: undefined read_early_boot_register(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void read_early_boot_register(long param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  
  puVar2 = (undefined8 *)(param_1 + -600);
  if (puVar2 != (undefined8 *)0x0) {
    irq_get_irqchip_state(*(undefined4 *)(param_1 + -0x200),3,param_1 + 0x261);
    if (*(char *)(param_1 + 0x261) != '\0') {
      _dev_err(*puVar2,"Sub system has crashed before driver probe\n");
      *(undefined4 *)(*(long *)(param_1 + -0x248) + 0x3cc) = 3;
    }
    iVar3 = irq_get_irqchip_state(*(undefined4 *)(param_1 + -0x1fc),3,param_1 + 0x260);
    if (*(char *)(param_1 + 0x260) != '\0') {
      _dev_info(*puVar2,"Sub system has boot-up before driver probe\n");
      *(undefined4 *)(*(long *)(param_1 + -0x248) + 0x3cc) = 6;
    }
    uVar1 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x38) = uVar1 + 1;
    if ((uVar1 < 5) && (iVar3 == -0x13)) {
      mod_timer(param_1,_jiffies + 0xfa);
    }
    else {
      complete(param_1 + -0x168);
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_rproc_update_recovery_status @ 00100db8 size=132
// signature: undefined qcom_rproc_update_recovery_status(void)
// callers: []
//------------------------------------------------------------

void qcom_rproc_update_recovery_status(long param_1,ulong param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    return;
  }
  lVar2 = *(long *)(param_1 + 0x28);
  mutex_lock(param_1 + 0x3d8);
  if ((param_2 & 1) == 0) {
    puVar1 = &DAT_00104519;
    *(undefined1 *)(param_1 + 0x4c4) = *(undefined1 *)(lVar2 + 0x418);
  }
  else {
    puVar1 = &DAT_00104ce2;
    *(undefined1 *)(lVar2 + 0x418) = *(undefined1 *)(param_1 + 0x4c4);
    *(undefined1 *)(param_1 + 0x4c4) = 0;
  }
  _printk(puVar1,*(undefined8 *)(param_1 + 0x18));
  mutex_unlock(param_1 + 0x3d8);
  return;
}



//------------------------------------------------------------
// adsp_probe @ 00100e40 size=2244
// signature: undefined adsp_probe(void)
// callers: []
//------------------------------------------------------------

ulong adsp_probe(undefined8 *param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  char *pcVar14;
  long lVar15;
  long *plVar16;
  undefined4 uVar17;
  undefined8 local_140;
  long local_138;
  long lStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  long local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar12 = sp_el0;
  puVar1 = param_1 + 2;
  local_68 = *(long *)(lVar12 + 0x638);
  local_140 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  puVar9 = (undefined4 *)of_device_get_match_data(puVar1);
  if (puVar9 == (undefined4 *)0x0) {
    uVar10 = 0xffffffea;
    goto LAB_00101354;
  }
  uVar10 = qcom_scm_is_available();
  if ((uVar10 & 1) == 0) {
    uVar10 = 0xfffffdfb;
    goto LAB_00101354;
  }
  local_140 = *(undefined8 *)(puVar9 + 2);
  uVar11 = of_property_read_string(param_1[0x5f],"firmware-name",&local_140);
  if (((int)uVar11 < 0) && (uVar10 = uVar11 & 0xffffffff, (int)uVar11 != -0x16)) goto LAB_00101354;
  puVar3 = adsp_ops;
  if (puVar9[9] != 0) {
    puVar3 = adsp_minidump_ops;
  }
  lVar12 = rproc_alloc(puVar1,*param_1,puVar3,local_140,0x4c0);
  if (lVar12 == 0) {
    _dev_err(puVar1,"unable to allocate remoteproc\n");
    uVar10 = 0xfffffff4;
    goto LAB_00101354;
  }
  *(undefined1 *)(lVar12 + 0x4c4) = 1;
  *(undefined1 *)(lVar12 + 0x4f1) = *(undefined1 *)((long)puVar9 + 0x2b);
  uVar17 = 1;
  if (*(char *)((long)puVar9 + 0x29) != '\0') {
    uVar17 = 2;
  }
  rproc_coredump_set_elf_info(lVar12,uVar17,0);
  plVar16 = *(long **)(lVar12 + 0x28);
  *plVar16 = (long)puVar1;
  plVar16[2] = lVar12;
  *(undefined4 *)(plVar16 + 0x3e) = puVar9[9];
  *(undefined4 *)(plVar16 + 0x38) = puVar9[6];
  *(undefined4 *)((long)plVar16 + 0x1c4) = puVar9[7];
  *(undefined1 *)((long)plVar16 + 0x419) = *(undefined1 *)((long)puVar9 + 0x2e);
  if (*(long *)(puVar9 + 4) == 0) {
LAB_00100f68:
    *(undefined1 *)(plVar16 + 0x41) = *(undefined1 *)((long)puVar9 + 0x2a);
    plVar16[0x42] = *(long *)(puVar9 + 0x14);
    *(undefined4 *)((long)plVar16 + 0x204) = puVar9[0x19];
    *(undefined1 *)((long)plVar16 + 0x20a) = *(undefined1 *)((long)puVar9 + 0x2d);
    plVar16[0x35] = *(long *)(puVar9 + 0x16);
    *(undefined1 *)((long)plVar16 + 0x209) = *(undefined1 *)(puVar9 + 0xb);
    uVar4 = *(undefined1 *)(puVar9 + 10);
    *(undefined1 *)(plVar16 + 0x83) = 1;
    *(undefined1 *)((long)plVar16 + 500) = uVar4;
    *(undefined1 *)(plVar16 + 0x96) = *(undefined1 *)(puVar9 + 0x1a);
    if (*(char *)(puVar9 + 8) != '\0') {
      lVar13 = devm_kmalloc(*plVar16,0x18,0xdc0);
      plVar16[0x3a] = lVar13;
      *(undefined1 *)((long)plVar16 + 0x1f5) = 1;
    }
    if (*(char *)((long)puVar9 + 0x2f) == '\0') {
LAB_001010dc:
      param_1[0x15] = plVar16;
      local_e8 = 0;
      uStack_e0 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_108 = 0;
      uStack_100 = 0;
      local_118 = 0;
      uStack_110 = 0;
      local_128 = 0;
      uStack_120 = 0;
      local_138 = 0;
      lStack_130 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      local_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      iVar8 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*plVar16 + 0x2e8),"memory-region",0,0,0,&local_b8);
      if ((iVar8 == 0) && (local_b8 != 0)) {
        uVar11 = of_address_to_resource(local_b8,0,&local_138);
        uVar10 = uVar11 & 0xffffffff;
        if ((int)uVar11 == 0) {
          plVar16[0x58] = local_138;
          plVar16[0x57] = local_138;
          plVar16[0x5a] = (lStack_130 - local_138) + 1;
          lVar13 = devm_ioremap_wc(*plVar16);
          plVar16[0x59] = lVar13;
          if (lVar13 == 0) {
            lVar13 = *plVar16;
            lVar15 = plVar16[0x5a];
LAB_001013e0:
            _dev_err(lVar13,"unable to map memory region: %pa+%zx\n",&local_138,lVar15);
            uVar10 = 0xfffffff0;
          }
          else {
            if (*(int *)((long)plVar16 + 0x1c4) != 0) {
              local_78 = 0;
              uStack_70 = 0;
              local_88 = 0;
              local_80 = 0;
              local_98 = 0;
              uStack_90 = 0;
              local_a8 = 0;
              uStack_a0 = 0;
              local_b8 = 0;
              uStack_b0 = 0;
              iVar8 = __of_parse_phandle_with_args
                                (*(undefined8 *)(*plVar16 + 0x2e8),"memory-region",0,0,1,&local_b8);
              if ((iVar8 != 0) || (local_b8 == 0)) {
                lVar13 = *plVar16;
                pcVar14 = "no dtb memory-region specified\n";
                goto LAB_001013bc;
              }
              uVar11 = of_address_to_resource(local_b8,0,&local_138);
              uVar10 = uVar11 & 0xffffffff;
              if ((int)uVar11 != 0) goto LAB_00101150;
              plVar16[0x54] = local_138;
              plVar16[0x53] = local_138;
              plVar16[0x56] = (lStack_130 - local_138) + 1;
              lVar13 = devm_ioremap_wc(*plVar16);
              plVar16[0x55] = lVar13;
              if (lVar13 == 0) {
                lVar13 = *plVar16;
                lVar15 = plVar16[0x56];
                goto LAB_001013e0;
              }
            }
            uVar11 = adsp_setup_32b_dma_allocs(plVar16);
            uVar10 = uVar11 & 0xffffffff;
            if ((int)uVar11 == 0) {
              uVar11 = adsp_init_clock(plVar16);
              uVar10 = uVar11 & 0xffffffff;
              if ((int)uVar11 == 0) {
                uVar11 = adsp_init_regulator(plVar16);
                uVar10 = uVar11 & 0xffffffff;
                if ((int)uVar11 == 0) {
                  adsp_init_bus_scaling(plVar16);
                  uVar11 = adsp_pds_attach(puVar1,plVar16 + 0x31,*(undefined8 *)(puVar9 + 0xc));
                  uVar10 = uVar11 & 0xffffffff;
                  if (-1 < (int)uVar11) {
                    *(int *)(plVar16 + 0x37) = (int)uVar11;
                    uVar11 = adsp_pds_attach(puVar1,plVar16 + 0x32,*(undefined8 *)(puVar9 + 0xe));
                    uVar10 = uVar11 & 0xffffffff;
                    if (-1 < (int)uVar11) {
                      *(int *)((long)plVar16 + 0x1bc) = (int)uVar11;
                      lVar13 = of_find_property(param_1[0x5f],"qcom,signal-aop",0);
                      if (lVar13 == 0) {
LAB_001012c8:
                        plVar2 = plVar16 + 3;
                        uVar11 = qcom_q6v5_init(plVar2,param_1,lVar12,*puVar9,
                                                *(undefined1 *)((long)puVar9 + 0x69),
                                                qcom_pas_handover);
                        uVar10 = uVar11 & 0xffffffff;
                        if ((int)uVar11 == 0) {
                          uVar11 = adsp_setup_wakeup(plVar16);
                          uVar10 = uVar11 & 0xffffffff;
                          if ((int)uVar11 == 0) {
                            if ((char)plVar16[0x96] == '\0') {
LAB_001014b8:
                              qcom_q6v5_register_ssr_subdev(plVar2,plVar16 + 0x72);
                              if ((plVar16[5] != 0) &&
                                 (iVar8 = readl_relaxed(plVar16[5] + 0x10), iVar8 != 0)) {
                                *(undefined4 *)(lVar12 + 0x3cc) = 6;
                              }
                              bVar6 = qcom_pil_timeouts_disabled();
                              timeout_disabled = bVar6 & 1;
                              qcom_add_glink_subdev
                                        (lVar12,plVar16 + 0x5b,*(undefined8 *)(puVar9 + 0x12));
                              qcom_add_smd_subdev(lVar12,plVar16 + 0x69);
                              uVar10 = qcom_add_sysmon_subdev
                                                 (lVar12,*(undefined8 *)(puVar9 + 0x14),puVar9[0x18]
                                                 );
                              plVar16[0x81] = uVar10;
                              if (uVar10 < 0xfffffffffffff001) {
                                qcom_add_ssr_subdev(lVar12,plVar16 + 0x72,
                                                    *(undefined8 *)(puVar9 + 0x12));
                                uVar11 = device_create_file(*plVar16,&dev_attr_txn_id);
                                uVar10 = uVar11 & 0xffffffff;
                                if ((int)uVar11 == 0) {
                                  snprintf((char *)&local_d8,0x20,"%s-md",*(char **)param_1[0x5f]);
                                  lVar13 = qcom_create_ramdump_device(&local_d8,0);
                                  plVar16[1] = lVar13;
                                  if (lVar13 == 0) {
                                    _dev_err(puVar1,"Unable to create %s minidump device.\n",
                                             &local_d8);
                                    cVar5 = (char)plVar16[0x2a];
                                  }
                                  else {
                                    cVar5 = (char)plVar16[0x2a];
                                  }
                                  if (cVar5 != '\0') {
                                    *(undefined4 *)(plVar16[2] + 0x3cc) = 6;
                                    uVar7 = ping_subsystem_init(plVar2,param_1);
                                    if (uVar7 != 0) {
                                      uVar10 = (ulong)uVar7;
                                      _dev_err(puVar1,"Unable to find ping/pong bits\n");
                                      qcom_remove_sysmon_subdev(plVar16[0x81]);
                                      goto LAB_00101354;
                                    }
                                  }
                                  uVar11 = rproc_add(lVar12);
                                  uVar10 = uVar11 & 0xffffffff;
                                  if ((int)uVar11 == 0) {
                                    mutex_lock(q6v5_pas_mutex);
                                    if ((recovery_set_cb & 1) == 0) {
                                      uVar7 = tracepoint_probe_register
                                                        (&__tracepoint_android_vh_rproc_recovery_set
                                                         ,android_vh_rproc_recovery_set,0);
                                      if (uVar7 != 0) {
                                        uVar10 = (ulong)uVar7;
                                        _dev_err(puVar1,
                                                 "Unable to register with rproc_recovery_set trace hook\n"
                                                );
                                        mutex_unlock(q6v5_pas_mutex);
                                        rproc_del(lVar12);
                                        lVar13 = plVar16[1];
                                        goto joined_r0x001016fc;
                                      }
                                      recovery_set_cb = 1;
                                    }
                                    mutex_unlock(q6v5_pas_mutex);
                                    if ((char)plVar16[0x96] != '\0') {
                                      *(undefined4 *)(plVar16 + 0x8b) = 0x7ffffffd;
                                      plVar16[0x89] = (long)rproc_panic_handler;
                                      atomic_notifier_chain_register
                                                (&panic_notifier_list,plVar16 + 0x89);
                                    }
                                    uVar10 = 0;
                                    goto LAB_00101354;
                                  }
                                  lVar13 = plVar16[1];
joined_r0x001016fc:
                                  if (lVar13 != 0) {
                                    qcom_destroy_ramdump_device();
                                  }
                                  device_remove_file(*plVar16,&dev_attr_txn_id);
                                }
                                qcom_remove_sysmon_subdev(plVar16[0x81]);
                              }
                              else {
                                uVar10 = uVar10 & 0xffffffff;
                              }
                            }
                            else {
                              iVar8 = rproc_find_status_register(plVar16);
                              if (iVar8 == 0) {
                                uVar10 = devm_qcom_smem_state_get(puVar1,"wakeup",plVar16 + 0x92);
                                plVar16[0x87] = uVar10;
                                if (uVar10 < 0xfffffffffffff001) {
                                  uVar10 = devm_qcom_smem_state_get
                                                     (puVar1,"sleep",(long)plVar16 + 0x494);
                                  plVar16[0x88] = uVar10;
                                  if (uVar10 < 0xfffffffffffff001) {
                                    __mutex_init(plVar16 + 0x8c,"&adsp->adsp_lock",&adsp_probe___key
                                                );
                                    *(undefined4 *)(plVar16 + 0x93) = 0;
                                    goto LAB_001014b8;
                                  }
                                  pcVar14 = "failed to acquire sleep state\n";
                                }
                                else {
                                  pcVar14 = "failed to acquire wake state\n";
                                }
                                _dev_err(puVar1,pcVar14);
                                uVar10 = 0;
                              }
                              else {
                                uVar10 = 0;
                              }
                            }
                          }
                          dev_pm_clear_wake_irq(*plVar16);
                          lVar13 = *plVar16;
                          device_wakeup_disable(lVar13);
                          device_set_wakeup_capable(lVar13,0);
                        }
                      }
                      else {
                        uVar11 = qmp_get(*plVar16);
                        plVar16[0x36] = uVar11;
                        if ((uVar11 != 0) && (uVar11 < 0xfffffffffffff001)) goto LAB_001012c8;
                      }
                      adsp_pds_detach(plVar16,plVar16 + 0x32,(long)*(int *)((long)plVar16 + 0x1bc));
                    }
                    adsp_pds_detach(plVar16,plVar16 + 0x31,(long)(int)plVar16[0x37]);
                  }
                }
              }
            }
          }
        }
      }
      else {
        lVar13 = *plVar16;
        pcVar14 = "no memory-region specified\n";
LAB_001013bc:
        _dev_err(lVar13,pcVar14);
        uVar10 = 0xffffffea;
      }
    }
    else {
      local_88 = 0;
      local_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      local_e8 = 0;
      uStack_e0 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_108 = 0;
      uStack_100 = 0;
      local_118 = 0;
      uStack_110 = 0;
      local_128 = 0;
      uStack_120 = 0;
      local_138 = 0;
      lStack_130 = 0;
      uVar7 = of_property_count_elems_of_size
                        (*(undefined8 *)(*plVar16 + 0x2e8),"mpss_dsm_mem_reg",4);
      uVar10 = (ulong)uVar7;
      if ((int)uVar7 < 0) {
        _dev_err(*plVar16,"mpss_dsm_mem_reg is not defined properly\n");
      }
      else {
        lVar13 = devm_kmalloc(*plVar16,uVar10 << 3,0xdc0);
        plVar16[0x84] = lVar13;
        if (lVar13 != 0) {
          lVar13 = devm_kmalloc(*plVar16,uVar10 << 3,0xdc0);
          plVar16[0x85] = lVar13;
          if (lVar13 != 0) {
            of_phandle_iterator_init
                      (&local_b8,*(undefined8 *)(*plVar16 + 0x2e8),"mpss_dsm_mem_reg",0,0);
            iVar8 = of_phandle_iterator_next(&local_b8);
            uVar7 = 0;
            if (iVar8 == 0) {
              uVar10 = 0;
              do {
                uVar7 = of_address_to_resource(local_80,0,&local_138);
                if (uVar7 != 0) {
                  uVar10 = (ulong)uVar7;
                  _dev_err(*plVar16,"address to resource failed for mpss_dsm_mem_reg[%d]\n",
                           local_88 & 0xffffffff);
                  goto LAB_00101410;
                }
                uVar11 = -(uVar10 >> 0x1f) & 0xfffffff800000000 | uVar10 << 3;
                uVar7 = (int)uVar10 + 1;
                uVar10 = (ulong)uVar7;
                *(long *)(plVar16[0x84] + uVar11) = local_138;
                *(long *)(plVar16[0x85] + uVar11) = (lStack_130 - local_138) + 1;
                iVar8 = of_phandle_iterator_next(&local_b8);
              } while (iVar8 == 0);
            }
            *(uint *)(plVar16 + 0x86) = uVar7;
            *(undefined1 *)((long)plVar16 + 0x41a) = 1;
            goto LAB_001010dc;
          }
        }
        uVar10 = 0xfffffff4;
      }
LAB_00101410:
      _dev_err(*plVar16,"failed to parse mpss dsm mem\n");
    }
LAB_00101150:
    if (plVar16[0x39] != 0) {
      kfree_const();
    }
  }
  else {
    lVar13 = kstrdup_const(*(long *)(puVar9 + 4),0xcc0);
    if (lVar13 != 0) {
      plVar16[0x39] = lVar13;
      goto LAB_00100f68;
    }
    uVar10 = 0xfffffff4;
  }
  rproc_free(lVar12);
LAB_00101354:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// adsp_remove @ 00101708 size=304
// signature: undefined adsp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 adsp_remove(long param_1)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  plVar3 = *(long **)(param_1 + 0xa8);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_rproc_recovery_set,android_vh_rproc_recovery_set,0);
  if (plVar3[0x39] != 0) {
    kfree_const();
  }
  rproc_del(plVar3[2]);
  if (plVar3[1] != 0) {
    qcom_destroy_ramdump_device();
  }
  device_remove_file(*plVar3,&dev_attr_txn_id);
  qcom_remove_glink_subdev(plVar3[2],plVar3 + 0x5b);
  qcom_remove_sysmon_subdev(plVar3[0x81]);
  qcom_remove_smd_subdev(plVar3[2],plVar3 + 0x69);
  qcom_remove_ssr_subdev(plVar3[2],plVar3 + 0x72);
  if ((char)plVar3[0x96] != '\0') {
    atomic_notifier_chain_unregister(&panic_notifier_list,plVar3 + 0x89);
  }
  uVar1 = (ulong)*(int *)((long)plVar3 + 0x1bc);
  if (uVar1 != 0) {
    if (uVar1 == 1) {
      if (*(long *)(*plVar3 + 0x268) != 0) {
        __pm_runtime_disable(*plVar3,1);
        goto LAB_001017f8;
      }
    }
    uVar4 = 0;
    do {
      dev_pm_domain_detach(plVar3[uVar4 + 0x32],0);
      uVar4 = (ulong)((int)uVar4 + 1);
    } while (uVar4 < uVar1);
  }
LAB_001017f8:
  dev_pm_clear_wake_irq(*plVar3);
  lVar2 = *plVar3;
  device_wakeup_disable(lVar2);
  device_set_wakeup_capable(lVar2,0);
  rproc_free(plVar3[2]);
  return 0;
}



//------------------------------------------------------------
// adsp_setup_32b_dma_allocs @ 00101838 size=160
// signature: undefined adsp_setup_32b_dma_allocs(void)
// callers: [adsp_probe]
//------------------------------------------------------------

int adsp_setup_32b_dma_allocs(long *param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (*(char *)((long)param_1 + 0x209) == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = of_reserved_mem_device_init_by_idx(*param_1,*(undefined8 *)(*param_1 + 0x2e8),2);
    lVar3 = *param_1;
    if (iVar1 == 0) {
      iVar1 = dma_set_mask(lVar3,0xffffffff);
      if (iVar1 == 0) {
        dma_set_coherent_mask(lVar3,0xffffffff);
        return 0;
      }
      lVar3 = *param_1;
      pcVar2 = "Unable to set the coherent mask to 32-bits!\n";
    }
    else {
      pcVar2 = "Unable to get the CMA area for performing dma_alloc_* calls\n";
    }
    _dev_err(lVar3,pcVar2);
  }
  return iVar1;
}



//------------------------------------------------------------
// adsp_init_clock @ 001018d8 size=164
// signature: undefined adsp_init_clock(void)
// callers: [adsp_probe]
//------------------------------------------------------------

ulong adsp_init_clock(undefined8 *param_1)

{
  ulong uVar1;
  char *pcVar2;
  
  uVar1 = devm_clk_get(*param_1,&DAT_001048a6);
  param_1[0x2b] = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = devm_clk_get_optional(*param_1,"aggre2");
    param_1[0x2c] = uVar1;
    if (uVar1 < 0xfffffffffffff001) {
      uVar1 = 0;
      goto LAB_00101950;
    }
    if ((int)uVar1 == -0x205) goto LAB_00101944;
    uVar1 = uVar1 & 0xffffffff;
    pcVar2 = "failed to get aggre2 clock";
  }
  else {
    if ((int)uVar1 == -0x205) {
LAB_00101944:
      uVar1 = 0xfffffdfb;
      goto LAB_00101950;
    }
    pcVar2 = "failed to get xo clock";
  }
  _dev_err(*param_1,pcVar2);
LAB_00101950:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// adsp_init_regulator @ 0010197c size=528
// signature: undefined adsp_init_regulator(void)
// callers: [adsp_probe]
//------------------------------------------------------------

int adsp_init_regulator(long *param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  char *local_98;
  undefined4 local_8c;
  undefined8 local_88;
  char local_80 [56];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_8c = 0;
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_88 = 0;
  local_98 = (char *)0x0;
  uVar1 = of_property_read_string_helper(*(undefined8 *)(*param_1 + 0x2e8),"reg-names",0,0,0);
  *(uint *)(param_1 + 0x30) = uVar1;
  if ((int)uVar1 < 1) {
    _dev_err(*param_1,"No regulators added!\n");
  }
  else {
    lVar3 = devm_kmalloc(*param_1,(ulong)uVar1 << 4,0xdc0);
    param_1[0x2f] = lVar3;
    if (lVar3 == 0) {
      iVar2 = -0xc;
      goto LAB_00101b18;
    }
    if (0 < (int)param_1[0x30]) {
      lVar3 = 0;
      uVar6 = 0;
      do {
        of_property_read_string_helper
                  (*(undefined8 *)(*param_1 + 0x2e8),"reg-names",&local_98,1,uVar6 & 0xffffffff);
        uVar4 = devm_regulator_get(*param_1,local_98);
        *(undefined8 *)(param_1[0x2f] + lVar3) = uVar4;
        if (0xfffffffffffff000 < *(ulong *)(param_1[0x2f] + lVar3)) {
          _dev_err(*param_1,"failed to get %s reg\n",local_98);
          iVar2 = *(int *)(param_1[0x2f] + lVar3);
          goto LAB_00101b18;
        }
        snprintf(local_80,0x32,"%s-uV-uA",local_98);
        lVar5 = of_find_property(*(undefined8 *)(*param_1 + 0x2e8),local_80,&local_8c);
        if (lVar5 != 0) {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(*param_1 + 0x2e8),local_80,&local_88,2,0);
          if (iVar2 < 0) {
            _dev_err(*param_1,"Failed to read uVuA value(rc:%d)\n",iVar2);
            goto LAB_00101b18;
          }
          if ((int)local_88 != 0) {
            *(int *)(param_1[0x2f] + lVar3 + 8) = (int)local_88;
          }
          if (local_88._4_4_ != 0) {
            *(int *)(param_1[0x2f] + lVar3 + 0xc) = local_88._4_4_;
          }
        }
        uVar6 = uVar6 + 1;
        lVar3 = lVar3 + 0x10;
      } while ((long)uVar6 < (long)(int)param_1[0x30]);
    }
  }
  iVar2 = 0;
LAB_00101b18:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// adsp_init_bus_scaling @ 00101b8c size=340
// signature: undefined adsp_init_bus_scaling(void)
// callers: [adsp_probe]
//------------------------------------------------------------

void adsp_init_bus_scaling(long *param_1)

{
  ulong uVar1;
  long lVar2;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (scm_perf_client == 0) {
    scm_perf_client = of_icc_get(*param_1,"crypto_ddr");
    if (0xfffffffffffff000 < scm_perf_client) {
      _dev_warn(*param_1,"Crypto scaling not setup\n");
    }
  }
  uVar1 = of_icc_get(*param_1,"rproc_ddr");
  param_1[0x3f] = uVar1;
  if (0xfffffffffffff000 < uVar1) {
    _dev_warn(*param_1,"%s: No bus client\n","adsp_init_bus_scaling");
  }
  lVar2 = of_find_property(*(undefined8 *)(*param_1 + 0x2e8),"rproc-ddr-set-icc-low-svs",0);
  if (lVar2 == 0) {
    *(undefined1 *)((long)param_1 + 0x4b1) = 0;
    _dev_info(*param_1,"Low SVS vote for ICC is not set\n");
  }
  else {
    *(undefined1 *)((long)param_1 + 0x4b1) = 1;
    of_property_read_variable_u32_array
              (*(undefined8 *)(*param_1 + 0x2e8),"rproc-ddr-lowsvs-icc-bw",&local_2c,1,0);
    if (local_2c == 0) {
      _dev_err(*param_1,"Low SVS ICC Bw is not available. Falling back to Turbo..\n");
      *(undefined4 *)((long)param_1 + 0x4b4) = 0xffffffff;
    }
    else {
      *(int *)((long)param_1 + 0x4b4) = local_2c;
      _dev_info(*param_1,"LowSVS Bus BW: %d\n");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// adsp_pds_attach @ 00101ce0 size=252
// signature: undefined adsp_pds_attach(void)
// callers: [adsp_probe]
//------------------------------------------------------------

int adsp_pds_attach(long param_1,long *param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar5 = 0;
    do {
      uVar6 = uVar5;
      uVar5 = uVar6 + 1;
    } while (*(long *)(param_3 + uVar6 * 8) != 0);
    if (uVar6 != 0) {
      if ((uVar6 == 1) && (*(long *)(param_1 + 0x268) != 0)) {
        *param_2 = param_1;
        pm_runtime_enable(param_1);
        return 1;
      }
      uVar5 = 0;
      do {
        uVar3 = dev_pm_domain_attach_by_name(param_1,*(undefined8 *)(param_3 + uVar5 * 8));
        param_2[uVar5] = uVar3;
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          iVar2 = -0x3d;
          if (uVar3 != 0) {
            iVar2 = (int)uVar3;
          }
          uVar1 = (int)uVar5 - 1;
          if ((int)uVar1 < 0) {
            return iVar2;
          }
          plVar4 = param_2 + uVar1;
          do {
            dev_pm_domain_detach(*plVar4,0);
            uVar1 = (int)uVar5 - 1;
            uVar5 = (ulong)uVar1;
            plVar4 = plVar4 + -1;
          } while (0 < (int)uVar1);
          return iVar2;
        }
        uVar5 = (ulong)((int)uVar5 + 1);
      } while (uVar5 < uVar6);
    }
    iVar2 = (int)(uVar6 + 1) + -1;
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_pas_handover @ 00101de0 size=432
// signature: undefined qcom_pas_handover(void)
// callers: [adsp_stop]
//------------------------------------------------------------

void qcom_pas_handover(long param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  if (*(char *)(param_1 + 0x498) != '\0') {
    uVar6 = *(undefined8 *)(param_1 + 0x488);
    iVar2 = -0x32;
    do {
      usleep_range_state(100,200,2);
      uVar3 = readl(uVar6);
      if ((uVar3 >> 3 & 1) != 0) {
        uVar6 = *(undefined8 *)(param_1 + -0x18);
        uVar4 = readl(*(undefined8 *)(param_1 + 0x488));
        _dev_info(uVar6,"state changed in handover for soccp! TCSR val = %d\n",uVar4);
        goto LAB_00101e04;
      }
      bVar1 = iVar2 != -1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    uVar6 = *(undefined8 *)(param_1 + -0x18);
    uVar4 = readl(*(undefined8 *)(param_1 + 0x488));
    _dev_err(uVar6,"state not changed in handover TCSR val = %d\n",uVar4);
  }
LAB_00101e04:
  uVar3 = *(int *)(param_1 + 0x168) - 1;
  if (-1 < (int)uVar3) {
    lVar5 = (ulong)uVar3 << 4;
    do {
      regulator_set_voltage(*(undefined8 *)(*(long *)(param_1 + 0x160) + lVar5),0,0x7fffffff);
      regulator_set_load(*(undefined8 *)(*(long *)(param_1 + 0x160) + lVar5),0);
      regulator_disable(*(undefined8 *)(*(long *)(param_1 + 0x160) + lVar5));
      bVar1 = lVar5 != 0;
      lVar5 = lVar5 + -0x10;
    } while (bVar1);
  }
  uVar6 = *(undefined8 *)(param_1 + 0x148);
  clk_disable(uVar6);
  clk_unprepare(uVar6);
  uVar6 = *(undefined8 *)(param_1 + 0x140);
  clk_disable(uVar6);
  clk_unprepare(uVar6);
  iVar2 = *(int *)(param_1 + 0x1a4);
  if (iVar2 != 0) {
    uVar7 = 0;
    do {
      dev_pm_genpd_set_performance_state(*(undefined8 *)(param_1 + 0x178 + uVar7 * 8),0);
      __pm_runtime_idle(*(undefined8 *)(param_1 + 0x178 + uVar7 * 8),5);
      uVar7 = (ulong)((int)uVar7 + 1);
    } while (uVar7 < (ulong)(long)iVar2);
  }
  if (*(ulong *)(param_1 + 0x1e0) < 0xfffffffffffff001) {
    iVar2 = icc_set_bw(*(ulong *)(param_1 + 0x1e0),0,0);
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + -0x18),"bandwidth request failed(rc:%d)\n",iVar2);
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + -0x18),"Bus scaling not setup for %s\n",
             *(undefined8 *)(*(long *)(param_1 + -8) + 0x18));
  }
  return;
}



//------------------------------------------------------------
// adsp_setup_wakeup @ 00101f90 size=160
// signature: undefined adsp_setup_wakeup(void)
// callers: [adsp_probe]
//------------------------------------------------------------

int adsp_setup_wakeup(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == (undefined8 *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x102030);
    (*pcVar1)();
  }
  uVar3 = *param_1;
  device_set_wakeup_capable(uVar3,1);
  iVar2 = device_wakeup_enable(uVar3);
  if (iVar2 == 0) {
    iVar2 = dev_pm_set_wake_irq(*param_1,*(undefined4 *)((long)param_1 + 0x54));
    if (iVar2 != 0) {
      _dev_err(*param_1,"failed to set wake_irq for wdog\n");
      uVar3 = *param_1;
      device_wakeup_disable(uVar3);
      device_set_wakeup_capable(uVar3,0);
    }
  }
  else {
    _dev_err(*param_1,"failed to set device for wakeup\n");
  }
  return iVar2;
}



//------------------------------------------------------------
// rproc_find_status_register @ 00102030 size=500
// signature: undefined rproc_find_status_register(void)
// callers: [adsp_probe]
//------------------------------------------------------------

int rproc_find_status_register(long *param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_100;
  long local_f8;
  long lStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  long local_98 [11];
  
  lVar3 = sp_el0;
  local_98[10] = *(long *)(lVar3 + 0x638);
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  uVar5 = *(undefined8 *)(*param_1 + 0x2e8);
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  lStack_f0 = 0;
  local_100 = 0;
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  iVar2 = __of_parse_phandle_with_args(uVar5,"soccp-tcsr",0,0,0,local_98);
  if ((iVar2 == 0) && (local_98[0] != 0)) {
    iVar2 = of_address_to_resource(local_98[0],0,&local_f8);
    if (iVar2 != 0) {
      _dev_err(*param_1,"Unable to find the tcsr base addr\n");
      goto LAB_00102174;
    }
    uVar1 = 0x6800000000070b;
    if (arm64_use_ng_mappings != '\0') {
      uVar1 = 0x68000000000f0b;
    }
    lVar3 = ioremap_prot(local_f8,(lStack_f0 - local_f8) + 1,uVar1);
    if (lVar3 != 0) {
      iVar2 = of_property_read_u32_index(uVar5,"soccp-tcsr",1,(long)&local_100 + 4);
      if (iVar2 < 0) {
        _dev_err(*param_1,"Unable to find the tcsr config offset addr\n");
        iounmap(lVar3);
        goto LAB_00102174;
      }
      param_1[0x94] = lVar3 + (local_100 >> 0x20);
      of_property_read_variable_u32_array(uVar5,"soccp-spare",&local_100,1,0);
      if ((int)local_100 == 0) {
        lVar3 = *param_1;
        pcVar4 = "Unable to find the running config register\n";
        goto LAB_00102214;
      }
      uVar5 = 0x6800000000070b;
      if (arm64_use_ng_mappings != '\0') {
        uVar5 = 0x68000000000f0b;
      }
      lVar3 = ioremap_prot(local_100 & 0xffffffff,4,uVar5);
      param_1[0x95] = lVar3;
      if (lVar3 != 0) {
        iVar2 = 0;
        goto LAB_00102174;
      }
    }
    _dev_err(*param_1,"Unable to find the tcsr base addr\n");
    iVar2 = -0xc;
  }
  else {
    lVar3 = *param_1;
    pcVar4 = "Unable to find the soccp config register\n";
LAB_00102214:
    _dev_err(lVar3,pcVar4);
    iVar2 = -0x16;
  }
LAB_00102174:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// readl_relaxed @ 00102224 size=124
// signature: undefined readl_relaxed(void)
// callers: [adsp_probe, adsp_start, adsp_attach]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10226c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// android_vh_rproc_recovery_set @ 001022a4 size=68
// signature: undefined android_vh_rproc_recovery_set(void)
// callers: []
//------------------------------------------------------------

void android_vh_rproc_recovery_set(undefined8 param_1,long param_2)

{
  char *pcVar1;
  
  pcVar1 = strstr(*(char **)(param_2 + 0x18),"spss");
  if (pcVar1 == (char *)0x0) {
    *(undefined1 *)(*(long *)(param_2 + 0x28) + 0x418) = *(undefined1 *)(param_2 + 0x4c4);
  }
  return;
}



//------------------------------------------------------------
// rproc_panic_handler @ 001022ec size=368
// signature: undefined rproc_panic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 rproc_panic_handler(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  puVar1 = (undefined8 *)(param_1 + -0x448);
  if ((puVar1 != (undefined8 *)0x0) && (*(char *)(param_1 + 0x68) != '\0')) {
    _dev_info(*puVar1,"waking SOCCP from panic path\n");
    iVar2 = qcom_smem_state_update_bits
                      (*(undefined8 *)(param_1 + -0x10),0x600,
                       1L << ((ulong)*(uint *)(param_1 + 0x48) & 0x3f));
    if (iVar2 == 0) {
      uVar6 = *(undefined8 *)(param_1 + 0x58);
      lVar3 = ktime_get();
      iVar2 = readl(uVar6);
      if (iVar2 != 2) {
        do {
          lVar4 = ktime_get();
          if (lVar3 + 10000000 < lVar4) {
            iVar2 = readl(uVar6);
            if (iVar2 != 2) {
              _dev_err(*puVar1,"failed to change to D0\n");
            }
            break;
          }
          __const_udelay(0x68dbc);
          Yield();
          iVar2 = readl(uVar6);
        } while (iVar2 != 2);
      }
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      lVar3 = ktime_get();
      iVar2 = readl(uVar6);
      if (iVar2 != 1) {
        do {
          lVar4 = ktime_get();
          if (lVar3 + 10000000 < lVar4) {
            iVar2 = readl(uVar6);
            if (iVar2 == 1) {
              return 0;
            }
            pcVar5 = "failed to change to D0\n";
            goto LAB_0010243c;
          }
          __const_udelay(0x68dbc);
          Yield();
          iVar2 = readl(uVar6);
        } while (iVar2 != 1);
      }
    }
    else {
      pcVar5 = "failed to update smem bits for D3 to D0\n";
LAB_0010243c:
      _dev_err(*puVar1,pcVar5);
    }
  }
  return 0;
}



//------------------------------------------------------------
// adsp_pds_detach @ 0010245c size=116
// signature: undefined adsp_pds_detach(void)
// callers: [adsp_probe]
//------------------------------------------------------------

void adsp_pds_detach(long *param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_3 != 0) {
    if ((param_3 == 1) && (*(long *)(*param_1 + 0x268) != 0)) {
      __pm_runtime_disable(*param_1,1);
      return;
    }
    uVar1 = 0;
    do {
      dev_pm_domain_detach(*(undefined8 *)(param_2 + uVar1 * 8),0);
      uVar1 = (ulong)((int)uVar1 + 1);
    } while (uVar1 < param_3);
  }
  return;
}



//------------------------------------------------------------
// adsp_start @ 001024d4 size=1816
// signature: undefined adsp_start(void)
// callers: []
//------------------------------------------------------------

int adsp_start(long param_1)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  long lVar10;
  char *pcVar11;
  long *plVar12;
  ulong uVar13;
  long local_138 [27];
  
  lVar10 = sp_el0;
  local_138[0x1a] = *(long *)(lVar10 + 0x638);
  plVar12 = *(long **)(param_1 + 0x28);
  local_138[0] = 0;
  lVar10 = ((long *)*plVar12)[0xe];
  if (lVar10 == 0) {
    lVar10 = *(long *)*plVar12;
  }
  if ((char)plVar12[0x96] != '\0') {
    *(undefined4 *)(plVar12 + 0x93) = 0;
  }
  plVar2 = plVar12 + 3;
  qcom_q6v5_prepare(plVar2,lVar10);
  if ((*(char *)((long)plVar12 + 0x419) == '\0') || ((global_sync_mem_setup & 1) != 0)) {
LAB_0010260c:
    if (((*(char *)((long)plVar12 + 0x41a) != '\0') &&
        (iVar6 = strcmp((char *)plVar12[0x39],"modem_dtb.mdt"), iVar6 == 0)) &&
       (0 < (int)plVar12[0x86])) {
      uVar13 = 0;
      do {
        local_138[2] = 0x60000000f;
        local_138[0x10] = 8;
        iVar7 = qcom_scm_assign_mem(*(undefined8 *)(plVar12[0x84] + uVar13 * 8),
                                    *(undefined8 *)(plVar12[0x85] + uVar13 * 8),local_138 + 0x10,
                                    local_138 + 2,1);
        if (iVar7 != 0) {
          _dev_err(*plVar12,"hyp assign for mpss_dsm_mem_reg[%d]\n",uVar13 & 0xffffffff);
          _dev_err(*plVar12,"failed to hyp assign mpss dsm mem\n");
          goto LAB_00102af0;
        }
        uVar13 = uVar13 + 1;
      } while ((long)uVar13 < (long)(int)plVar12[0x86]);
    }
    if (*(char *)((long)plVar12 + 0x4b1) == '\0') {
      uVar9 = 0xffffffff;
    }
    else {
      uVar9 = *(undefined4 *)((long)plVar12 + 0x4b4);
    }
    if ((ulong)plVar12[0x3f] < 0xfffffffffffff001) {
      iVar7 = icc_set_bw(plVar12[0x3f],uVar9,uVar9);
      if ((iVar7 != 0) && (_dev_err(*plVar12,"bandwidth request failed(rc:%d)\n",iVar7), iVar7 < 0))
      goto LAB_00102af0;
    }
    else {
      _dev_err(*plVar12,"Bus scaling not setup for %s\n",*(undefined8 *)(plVar12[2] + 0x18));
    }
    plVar3 = plVar12 + 0x31;
    iVar7 = adsp_pds_enable(plVar3,(long)(int)plVar12[0x37]);
    if (-1 < iVar7) {
      plVar4 = plVar12 + 0x32;
      iVar7 = adsp_pds_enable(plVar4,(long)*(int *)((long)plVar12 + 0x1bc));
      if (-1 < iVar7) {
        if ((plVar12[0x36] == 0) ||
           (iVar7 = qcom_rproc_toggle_load_state(plVar12[0x36],plVar12[0x35],1), iVar7 == 0)) {
          lVar10 = plVar12[0x2b];
          iVar7 = clk_prepare(lVar10);
          if (iVar7 == 0) {
            iVar7 = clk_enable(lVar10);
            if (iVar7 == 0) {
              lVar10 = plVar12[0x2c];
              iVar7 = clk_prepare(lVar10);
              if (iVar7 == 0) {
                iVar7 = clk_enable(lVar10);
                if (iVar7 == 0) {
                  iVar7 = enable_regulators(plVar12);
                  if (iVar7 == 0) {
                    scm_pas_enable_bw();
                    lVar10 = ((long *)*plVar12)[0xe];
                    if (lVar10 == 0) {
                      lVar10 = *(long *)*plVar12;
                    }
                    trace_rproc_qcom_event(lVar10,"dtb_auth_reset","enter");
                    if (((*(int *)((long)plVar12 + 0x1c4) != 0) || (plVar12[0x39] != 0)) &&
                       (iVar6 = qcom_scm_pas_auth_and_reset(), iVar6 != 0)) {
                    /* WARNING: Subroutine does not return */
                      panic("Panicking, auth and reset failed for remoteproc %s dtb ret=%d\n",
                            *(undefined8 *)(param_1 + 0x18),iVar6);
                    }
                    lVar10 = ((long *)*plVar12)[0xe];
                    if (lVar10 == 0) {
                      lVar10 = *(long *)*plVar12;
                    }
                    trace_rproc_qcom_event(lVar10,"Q6_firmware_loading","enter");
                    iVar7 = request_firmware(local_138,*(undefined8 *)(param_1 + 0x20),*plVar12);
                    if (iVar7 == 0) {
                      iVar7 = qcom_mdt_load_no_free
                                        (*plVar12,local_138[0],*(undefined8 *)(param_1 + 0x20),
                                         (int)plVar12[0x38],plVar12[0x59],plVar12[0x57],
                                         plVar12[0x5a],plVar12 + 0x58,
                                         *(undefined1 *)((long)plVar12 + 0x209),plVar12[0x3a]);
                      if (iVar7 == 0) {
                        qcom_pil_info_store(plVar12[0x42],plVar12[0x57],plVar12[0x5a]);
                        adsp_add_coredump_segments(plVar12,local_138[0]);
                        lVar10 = ((long *)*plVar12)[0xe];
                        if (lVar10 == 0) {
                          lVar10 = *(long *)*plVar12;
                        }
                        trace_rproc_qcom_event(lVar10,"Q6_auth_reset","enter");
                        iVar6 = qcom_scm_pas_auth_and_reset((int)plVar12[0x38]);
                        if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
                          panic("Panicking, auth and reset failed for remoteproc %s ret=%d\n",
                                *(undefined8 *)(param_1 + 0x18),iVar6);
                        }
                        lVar10 = ((long *)*plVar12)[0xe];
                        if (lVar10 == 0) {
                          lVar10 = *(long *)*plVar12;
                        }
                        trace_rproc_qcom_event(lVar10,"Q6_auth_reset",&DAT_00104df6);
                        if (plVar12[5] == 0) {
LAB_00102988:
                          if (timeout_disabled == 0) {
                            iVar7 = qcom_q6v5_wait_for_start(plVar2,0x4e2);
                            if ((*(char *)(param_1 + 0x4c4) != '\0') && (iVar7 != 0)) {
                    /* WARNING: Subroutine does not return */
                              panic("Panicking, remoteproc %s failed to bootup.\n",
                                    *(undefined8 *)(plVar12[2] + 0x18));
                            }
                            if (iVar7 == -0x6e) {
                              _dev_err(*plVar12,"start timed out\n");
                            }
                          }
                          else {
                            iVar7 = 0;
                          }
                          plVar12[0x28] = plVar12[0x28] + 1;
                        }
                        else {
                          iVar6 = 1;
                          do {
                            uVar8 = readl_relaxed(plVar12[5] + 8);
                            if ((int)uVar8 != 0) {
                              writel_relaxed(uVar8,plVar12[5] + 0xc);
                              break;
                            }
                            msleep(0x14);
                            iVar7 = iVar6 + 1;
                            bVar1 = iVar6 < 0xfa;
                            iVar6 = iVar7;
                          } while ((bVar1) || ((timeout_disabled & 1) != 0));
                          iVar6 = readl_relaxed(plVar12[5] + 8);
                          if (iVar6 != 0) goto LAB_00102988;
                          _dev_err(*plVar12,"Didn\'t get rmb signal from  %s\n",
                                   *(undefined8 *)(param_1 + 0x18));
                          iVar7 = 0;
                        }
                        qcom_mdt_free_metadata
                                  (*plVar12,(int)plVar12[0x38],plVar12[0x3a],
                                   *(undefined1 *)((long)plVar12 + 0x209),iVar7);
                      }
                      if (local_138[0] != 0) {
                        release_firmware();
                      }
                    }
                    if ((*(int *)((long)plVar12 + 0x1c4) != 0) || (plVar12[0x39] != 0)) {
                      qcom_mdt_free_metadata
                                (*plVar12,*(int *)((long)plVar12 + 0x1c4),plVar12 + 0x3b,
                                 *(undefined1 *)((long)plVar12 + 0x209),iVar7);
                      release_firmware(plVar12[0x82]);
                    }
                    uVar8 = scm_pas_disable_bw();
                    if (iVar7 == 0) goto LAB_00102af8;
                    disable_regulators(plVar12);
                  }
                  lVar10 = plVar12[0x2c];
                  clk_disable(lVar10);
                }
                clk_unprepare(lVar10);
              }
              lVar10 = plVar12[0x2b];
              clk_disable(lVar10);
            }
            clk_unprepare(lVar10);
          }
          if (plVar12[0x36] != 0) {
            qcom_rproc_toggle_load_state(plVar12[0x36],plVar12[0x35],0);
          }
        }
        iVar6 = *(int *)((long)plVar12 + 0x1bc);
        if (iVar6 != 0) {
          uVar13 = 0;
          do {
            dev_pm_genpd_set_performance_state(plVar4[uVar13],0);
            __pm_runtime_idle(plVar4[uVar13],5);
            uVar13 = (ulong)((int)uVar13 + 1);
          } while (uVar13 < (ulong)(long)iVar6);
        }
      }
      lVar10 = plVar12[0x37];
      if ((int)lVar10 != 0) {
        uVar13 = 0;
        do {
          dev_pm_genpd_set_performance_state(plVar3[uVar13],0);
          __pm_runtime_idle(plVar3[uVar13],5);
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (uVar13 < (ulong)(long)(int)lVar10);
      }
    }
    if ((ulong)plVar12[0x3f] < 0xfffffffffffff001) {
      iVar6 = icc_set_bw(plVar12[0x3f],0,0);
      if (iVar6 != 0) {
        _dev_err(*plVar12,"bandwidth request failed(rc:%d)\n",iVar6);
      }
    }
    else {
      _dev_err(*plVar12,"Bus scaling not setup for %s\n",*(undefined8 *)(plVar12[2] + 0x18));
    }
  }
  else {
    local_138[0xc] = 0;
    local_138[0xd] = 0;
    local_138[10] = 0;
    local_138[0xb] = 0;
    local_138[1] = 8;
    local_138[2] = 0;
    local_138[8] = 0;
    local_138[9] = 0;
    local_138[6] = 0;
    local_138[7] = 0;
    local_138[4] = 0;
    local_138[5] = 0;
    local_138[3] = 0;
    local_138[0xe] = 0x600000003;
    local_138[0xf] = 0x60000001e;
    local_138[0x18] = 0;
    local_138[0x19] = 0;
    local_138[0x16] = 0;
    local_138[0x17] = 0;
    local_138[0x14] = 0;
    local_138[0x15] = 0;
    local_138[0x12] = 0;
    local_138[0x13] = 0;
    local_138[0x10] = 0;
    local_138[0x11] = 0;
    iVar6 = __of_parse_phandle_with_args
                      (*(undefined8 *)(*plVar12 + 0x2e8),"global-sync-mem-reg",0,0,0,
                       local_138 + 0x10);
    iVar7 = -0x16;
    pcVar11 = "global sync mem region is missing\n";
    if ((iVar6 == 0) && (local_138[0x10] != 0)) {
      iVar7 = of_address_to_resource(local_138[0x10],0,local_138 + 2);
      if (iVar7 == 0) {
        iVar7 = qcom_scm_assign_mem(local_138[2],(local_138[3] - local_138[2]) + 1,local_138 + 1,
                                    local_138 + 0xe,2);
        if (iVar7 == 0) {
          global_sync_mem_setup = 1;
          goto LAB_0010260c;
        }
        pcVar11 = "hyp assign for global sync mem failed\n";
      }
      else {
        pcVar11 = "address to resource failed for global sync mem\n";
      }
    }
    _dev_err(*plVar12,pcVar11);
    _dev_err(*plVar12,"failed to setup global sync mem\n");
  }
LAB_00102af0:
  uVar8 = qcom_q6v5_unprepare(plVar2);
LAB_00102af8:
  lVar10 = ((long *)*plVar12)[0xe];
  if (lVar10 == 0) {
    lVar10 = *(long *)*plVar12;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_138[0x1a]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8,lVar10);
  }
  return iVar7;
}



//------------------------------------------------------------
// adsp_stop @ 00102cd8 size=1288
// signature: undefined adsp_stop(void)
// callers: [adsp_attach]
//------------------------------------------------------------

ulong adsp_stop(long param_1)

{
  long *plVar1;
  bool bVar2;
  undefined8 uVar3;
  char cVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  ulong uVar15;
  undefined8 local_118;
  long local_110;
  long lStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  long local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  plVar14 = *(long **)(param_1 + 0x28);
  plVar1 = plVar14 + 3;
  iVar6 = qcom_q6v5_request_stop(plVar1,plVar14[0x81]);
  if (iVar6 == -0x6e) {
    _dev_err(*plVar14,"timed out on wait\n");
  }
  scm_pas_enable_bw();
  if (*(char *)((long)plVar14 + 0x1f5) == '\0') {
    iVar6 = qcom_scm_pas_shutdown((int)plVar14[0x38]);
  }
  else {
    iVar6 = qcom_scm_pas_shutdown_retry();
  }
  if (iVar6 != 0) {
    if (*(char *)((long)plVar14 + 0x20a) == '\0') {
LAB_001031bc:
                    /* WARNING: Subroutine does not return */
      panic("Panicking, remoteproc %s failed to shutdown.\n",*(undefined8 *)(param_1 + 0x18));
    }
    iVar6 = -0x31;
    do {
      msleep(100);
      iVar7 = qcom_scm_pas_shutdown((int)plVar14[0x38]);
      if (iVar7 != -0x16) break;
      bVar2 = iVar6 != 0;
      iVar6 = iVar6 + 1;
    } while (bVar2);
    if (iVar7 != 0) goto LAB_001031bc;
  }
  if ((*(int *)((long)plVar14 + 0x1c4) != 0) && (iVar6 = qcom_scm_pas_shutdown(), iVar6 != 0)) {
                    /* WARNING: Subroutine does not return */
    panic("Panicking, remoteproc %s dtb failed to shutdown.\n",*(undefined8 *)(param_1 + 0x18));
  }
  if (scm_perf_client < 0xfffffffffffff001) {
    mutex_lock(q6v5_pas_mutex);
    scm_pas_bw_count = scm_pas_bw_count + -1;
    if (scm_pas_bw_count == 0) {
      icc_set_bw(scm_perf_client,0,0);
    }
    mutex_unlock(q6v5_pas_mutex);
  }
  lVar10 = plVar14[0x37];
  if ((int)lVar10 != 0) {
    uVar15 = 0;
    do {
      dev_pm_genpd_set_performance_state(plVar14[uVar15 + 0x31],0);
      __pm_runtime_idle(plVar14[uVar15 + 0x31],5);
      uVar15 = (ulong)((int)uVar15 + 1);
    } while (uVar15 < (ulong)(long)(int)lVar10);
  }
  if (plVar14[0x36] != 0) {
    qcom_rproc_toggle_load_state(plVar14[0x36],plVar14[0x35],0);
  }
  iVar6 = qcom_q6v5_unprepare(plVar1);
  if (iVar6 != 0) {
    qcom_pas_handover(plVar1);
  }
  if (*(int *)((long)plVar14 + 0x204) == 0) {
    uVar11 = 0;
    cVar4 = *(char *)((long)plVar14 + 0x41a);
    uVar15 = 0;
  }
  else {
    uVar15 = qcom_smem_bust_hwspin_lock_by_host();
    uVar11 = uVar15 & 0xffffffff;
    cVar4 = *(char *)((long)plVar14 + 0x41a);
  }
  if (cVar4 == '\0') goto LAB_00102f7c;
  uVar8 = strcmp((char *)plVar14[0x39],"modem_dtb.mdt");
  uVar15 = (ulong)uVar8;
  if (uVar8 != 0) goto LAB_00102f7c;
  lVar12 = plVar14[2];
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  lStack_108 = 0;
  lVar10 = of_find_compatible_node(0,0,"qcom,msm-imem-mss-dsm");
  if (lVar10 == 0) {
    puVar9 = &DAT_001048f5;
LAB_00103170:
    uVar15 = _printk(puVar9,"qcom,msm-imem-mss-dsm");
  }
  else {
    iVar6 = of_address_to_resource(lVar10,0,&local_110);
    if (iVar6 < 0) {
      puVar9 = &DAT_0010485b;
      goto LAB_00103170;
    }
    uVar3 = 0x68000000000713;
    if (arm64_use_ng_mappings != '\0') {
      uVar3 = 0x68000000000f13;
    }
    lVar10 = ioremap_prot(local_110,(lStack_108 - local_110) + 1,uVar3);
    if (lVar10 == 0) {
      uVar15 = _printk(&DAT_00104d7a);
    }
    else {
      if (lStack_108 + 1 != local_110) {
        uVar15 = 0;
        do {
          uVar5 = *(ushort *)(lVar10 + (uVar15 | 2));
          if (*(ushort *)(lVar10 + uVar15) != 0 && uVar5 != 0) {
            rproc_coredump_add_custom_segment
                      (lVar12,(ulong)*(ushort *)(lVar10 + uVar15) << 0x10,(ulong)uVar5 << 0x10,
                       adsp_segment_dump,0);
          }
          uVar15 = (ulong)((int)uVar15 + 4);
        } while (uVar15 < (lStack_108 - local_110) + 1U);
      }
      uVar15 = iounmap(lVar10);
    }
  }
  if (0 < (int)plVar14[0x86]) {
    uVar13 = 0;
    do {
      local_110 = 0x600000003;
      local_a8 = 0x8000;
      uVar15 = qcom_scm_assign_mem(*(undefined8 *)(plVar14[0x84] + uVar13 * 8),
                                   *(undefined8 *)(plVar14[0x85] + uVar13 * 8),&local_a8,&local_110,
                                   1);
      if ((int)uVar15 != 0) {
        uVar11 = uVar15 & 0xffffffff;
        _dev_err(*plVar14,"hyp assign for mpss_dsm_mem_reg[%d]\n",uVar13 & 0xffffffff);
        uVar15 = _dev_err(*plVar14,"failed to reclaim mpss dsm mem\n");
        goto LAB_00102f7c;
      }
      uVar13 = uVar13 + 1;
    } while ((long)uVar13 < (long)(int)plVar14[0x86]);
  }
  uVar11 = 0;
LAB_00102f7c:
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_b0 = 0x600000003;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  lStack_108 = 0;
  if ((*(char *)((long)plVar14 + 0x419) != '\0') && (power_state_enter_into_hibernate != '\0')) {
    local_118 = 0x40000008;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    iVar6 = __of_parse_phandle_with_args
                      (*(undefined8 *)(*plVar14 + 0x2e8),"global-sync-mem-reg",0,0,0,&local_a8);
    if ((iVar6 == 0) && (local_a8 != 0)) {
      iVar6 = of_address_to_resource(local_a8,0,&local_110);
      if (iVar6 == 0) {
        uVar15 = qcom_scm_assign_mem(local_110,(lStack_108 - local_110) + 1,&local_118,&local_b0,1);
        if ((int)uVar15 == 0) {
          global_sync_mem_setup = 0;
        }
        else {
          uVar15 = _dev_err(*plVar14,"hyp assign for global sync mem failed\n");
        }
      }
      else {
        uVar15 = _dev_err(*plVar14,"address to resource failed for global sync mem\n");
      }
    }
    else {
      uVar15 = _dev_err(*plVar14,"global sync mem region is missing\n");
    }
  }
  plVar14[0x28] = plVar14[0x28] + 1;
  lVar10 = ((long *)*plVar14)[0xe];
  if (lVar10 == 0) {
    lVar10 = *(long *)*plVar14;
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15,lVar10);
  }
  return uVar11;
}



//------------------------------------------------------------
// adsp_attach @ 001032cc size=1128
// signature: undefined adsp_attach(void)
// callers: []
//------------------------------------------------------------

int adsp_attach(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined8 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  puVar9 = *(undefined8 **)(param_1 + 0x28);
  local_60 = 0;
  puVar3 = puVar9 + 3;
  if (*(char *)(puVar9 + 0x2a) == '\0') {
    iVar7 = request_firmware(&local_60,*(undefined8 *)(param_1 + 0x20),param_1 + 0x38);
    if (iVar7 < 0) {
      _dev_err(*puVar9,"Failed to request DSP firmware\n");
      _dev_err(*puVar9,"Dumps will not be available\n");
    }
    else {
      iVar7 = qcom_register_dump_segments(param_1,local_60);
      if (iVar7 != 0) {
        _dev_err(*puVar9,"Failed to register dump segments\n");
        _dev_err(*puVar9,"Dumps will not be available\n");
      }
      release_firmware(local_60);
    }
    qcom_q6v5_prepare(puVar3);
    if (*(char *)((long)puVar9 + 0x4b1) == '\0') {
      uVar8 = 0xffffffff;
    }
    else {
      uVar8 = *(undefined4 *)((long)puVar9 + 0x4b4);
    }
    if ((ulong)puVar9[0x3f] < 0xfffffffffffff001) {
      iVar7 = icc_set_bw(puVar9[0x3f],uVar8,uVar8);
      if ((iVar7 == 0) || (_dev_err(*puVar9,"bandwidth request failed(rc:%d)\n",iVar7), -1 < iVar7))
      goto LAB_00103370;
    }
    else {
      _dev_err(*puVar9,"Bus scaling not setup for %s\n",*(undefined8 *)(puVar9[2] + 0x18));
LAB_00103370:
      puVar4 = puVar9 + 0x31;
      iVar7 = adsp_pds_enable(puVar4,(long)*(int *)(puVar9 + 0x37));
      if (-1 < iVar7) {
        if ((puVar9[5] == 0) || (iVar7 = readl_relaxed(puVar9[5] + 8), iVar7 == 0)) {
          _dev_err(*puVar9,"Remote proc is not ready to attach\n");
          adsp_stop(param_1);
          iVar7 = *(int *)(puVar9 + 0x37);
        }
        else {
          puVar5 = puVar9 + 0x32;
          iVar7 = adsp_pds_enable(puVar5,(long)*(int *)((long)puVar9 + 0x1bc));
          if (-1 < iVar7) {
            iVar7 = qcom_rproc_toggle_load_state(puVar9[0x36],puVar9[0x35],1);
            if (iVar7 == 0) {
              uVar10 = puVar9[0x2b];
              iVar7 = clk_prepare(uVar10);
              if (iVar7 == 0) {
                iVar7 = clk_enable(uVar10);
                if (iVar7 == 0) {
                  iVar7 = clk_prepare_enable(puVar9[0x2c]);
                  if (iVar7 == 0) {
                    iVar7 = enable_regulators(puVar9);
                    if (iVar7 == 0) {
                      iVar7 = 1;
                      do {
                        uVar10 = readl_relaxed(puVar9[5] + 8);
                        if ((int)uVar10 != 0) {
                          writel_relaxed(uVar10,puVar9[5] + 0xc);
                          break;
                        }
                        msleep(0x14);
                        iVar2 = iVar7 + 1;
                        bVar1 = iVar7 < 0xfa;
                        iVar7 = iVar2;
                      } while ((bVar1) || ((timeout_disabled & 1) != 0));
                      iVar7 = readl_relaxed(puVar9[5] + 8);
                      if (iVar7 == 0) {
                        _dev_err(*puVar9,"Didn\'t get rmb signal from %s\n",
                                 *(undefined8 *)(param_1 + 0x18));
                      }
                      else {
                        if (timeout_disabled != 0) {
                          iVar7 = 0;
                          goto LAB_00103528;
                        }
                        iVar7 = qcom_q6v5_wait_for_start(puVar3,0x4e2);
                        if ((*(char *)(param_1 + 0x4c4) != '\0') && (iVar7 != 0)) {
                    /* WARNING: Subroutine does not return */
                          panic("Panicking, remoteproc %s failed to bootup.\n",
                                *(undefined8 *)(puVar9[2] + 0x18));
                        }
                        if (iVar7 != -0x6e) goto LAB_00103528;
                        _dev_err(*puVar9,"start timed out\n");
                      }
                      disable_regulators(puVar9);
                    }
                    uVar10 = puVar9[0x2c];
                    clk_disable(uVar10);
                    clk_unprepare(uVar10);
                  }
                  uVar10 = puVar9[0x2b];
                  clk_disable(uVar10);
                }
                clk_unprepare(uVar10);
              }
              qcom_rproc_toggle_load_state(puVar9[0x36],puVar9[0x35],0);
            }
            iVar7 = *(int *)((long)puVar9 + 0x1bc);
            if (iVar7 != 0) {
              uVar11 = 0;
              do {
                dev_pm_genpd_set_performance_state(puVar5[uVar11],0);
                __pm_runtime_idle(puVar5[uVar11],5);
                uVar11 = (ulong)((int)uVar11 + 1);
              } while (uVar11 < (ulong)(long)iVar7);
            }
          }
          iVar7 = *(int *)(puVar9 + 0x37);
        }
        if (iVar7 != 0) {
          uVar11 = 0;
          do {
            dev_pm_genpd_set_performance_state(puVar4[uVar11],0);
            __pm_runtime_idle(puVar4[uVar11],5);
            uVar11 = (ulong)((int)uVar11 + 1);
          } while (uVar11 < (ulong)(long)iVar7);
        }
      }
      if ((ulong)puVar9[0x3f] < 0xfffffffffffff001) {
        iVar7 = icc_set_bw(puVar9[0x3f],0,0);
        if (iVar7 != 0) {
          _dev_err(*puVar9,"bandwidth request failed(rc:%d)\n",iVar7);
        }
      }
      else {
        _dev_err(*puVar9,"Bus scaling not setup for %s\n",*(undefined8 *)(puVar9[2] + 0x18));
      }
    }
    qcom_q6v5_unprepare(puVar3);
  }
  puVar4 = puVar9 + 0x4b;
  init_timer_key(puVar4,read_early_boot_register,0,0,0);
  *(undefined4 *)(puVar9 + 0x1e) = 0;
  __init_swait_queue_head(puVar9 + 0x1f,"&x->wait",&init_completion___key);
  read_early_boot_register(puVar4);
  wait_for_completion(puVar9 + 0x1e);
  del_timer(puVar4);
  iVar7 = ping_subsystem(puVar3);
  if (iVar7 != 0) {
    _dev_err(*puVar9,"Timed out on ping/pong, assuming device crashed\n");
    *(undefined4 *)(param_1 + 0x3cc) = 3;
  }
  *(undefined1 *)((long)puVar9 + 0x134) = 1;
LAB_00103528:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// adsp_da_to_va @ 00103738 size=68
// signature: undefined adsp_da_to_va(void)
// callers: []
//------------------------------------------------------------

long adsp_da_to_va(long param_1,long param_2,long param_3,undefined1 *param_4)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(param_1 + 0x28);
  uVar2 = param_2 - *(long *)(lVar1 + 0x2c0);
  if (((int)uVar2 < 0) || (uVar2 = uVar2 & 0xffffffff, *(ulong *)(lVar1 + 0x2d0) < uVar2 + param_3))
  {
    return 0;
  }
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = 1;
  }
  return *(long *)(lVar1 + 0x2c8) + uVar2;
}



//------------------------------------------------------------
// adsp_load @ 00103780 size=384
// signature: undefined adsp_load(void)
// callers: []
//------------------------------------------------------------

int adsp_load(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x28);
  lVar2 = ((long *)*puVar3)[0xe];
  if (lVar2 == 0) {
    lVar2 = *(long *)*puVar3;
  }
  rproc_coredump_cleanup(puVar3[2],lVar2);
  scm_pas_enable_bw();
  if ((*(int *)((long)puVar3 + 0x1c4) == 0) || (puVar3[0x39] == 0)) {
    if (0xfffffffffffff000 < scm_perf_client) {
      return 0;
    }
    mutex_lock(q6v5_pas_mutex);
    iVar1 = 0;
  }
  else {
    iVar1 = request_firmware(puVar3 + 0x82,puVar3[0x39],*puVar3);
    if (iVar1 == 0) {
      iVar1 = qcom_mdt_load_no_free
                        (*puVar3,puVar3[0x82],puVar3[0x39],*(undefined4 *)((long)puVar3 + 0x1c4),
                         puVar3[0x55],puVar3[0x53],puVar3[0x56],puVar3 + 0x54,
                         *(undefined1 *)((long)puVar3 + 0x209),puVar3 + 0x3b);
      if (iVar1 != 0) {
        _dev_err(*puVar3,"failed to load %s: %d\n",puVar3[0x39],iVar1);
        release_firmware(puVar3[0x82]);
      }
    }
    else {
      _dev_err(*puVar3,"request_firmware failed for %s: %d\n",puVar3[0x39],iVar1);
    }
    lVar2 = ((long *)*puVar3)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*puVar3;
    }
    if (0xfffffffffffff000 < scm_perf_client) {
      return iVar1;
    }
    mutex_lock(q6v5_pas_mutex,lVar2);
  }
  scm_pas_bw_count = scm_pas_bw_count + -1;
  if (scm_pas_bw_count == 0) {
    icc_set_bw(scm_perf_client,0,0);
  }
  mutex_unlock(q6v5_pas_mutex);
  return iVar1;
}



//------------------------------------------------------------
// adsp_panic @ 001039ec size=36
// signature: undefined adsp_panic(void)
// callers: []
//------------------------------------------------------------

void adsp_panic(long param_1)

{
  qcom_q6v5_panic(*(long *)(param_1 + 0x28) + 0x18);
  return;
}



//------------------------------------------------------------
// trace_rproc_qcom_event @ 00103a10 size=36
// signature: undefined trace_rproc_qcom_event(void)
// callers: [adsp_start]
//------------------------------------------------------------

void trace_rproc_qcom_event(void)

{
  return;
}



//------------------------------------------------------------
// adsp_pds_enable @ 00103aa4 size=256
// signature: undefined adsp_pds_enable(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

int adsp_pds_enable(long param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  
  if (param_2 != 0) {
    uVar10 = 0;
    do {
      dev_pm_genpd_set_performance_state(*(undefined8 *)(param_1 + uVar10 * 8),0x7fffffff);
      iVar6 = __pm_runtime_resume(*(undefined8 *)(param_1 + uVar10 * 8),4);
      if (iVar6 < 0) {
        lVar8 = *(long *)(param_1 + uVar10 * 8);
        piVar1 = (int *)(lVar8 + 0x1f8);
        iVar7 = *(int *)(lVar8 + 0x1f8);
        goto LAB_00103b10;
      }
      uVar10 = (ulong)((int)uVar10 + 1);
    } while (uVar10 < param_2);
  }
  return 0;
LAB_00103b10:
  do {
    if (iVar7 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar7) goto LAB_00103b30;
      cVar3 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar7 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00103b30:
    bVar5 = iVar7 != iVar2;
    iVar7 = iVar2;
  } while (bVar5);
  dev_pm_genpd_set_performance_state(*(undefined8 *)(param_1 + uVar10 * 8),0);
  uVar4 = (int)uVar10 - 1;
  if (-1 < (int)uVar4) {
    puVar9 = (undefined8 *)(param_1 + (ulong)uVar4 * 8);
    do {
      dev_pm_genpd_set_performance_state(*puVar9,0);
      __pm_runtime_idle(*puVar9,5);
      uVar4 = (int)uVar10 - 1;
      uVar10 = (ulong)uVar4;
      puVar9 = puVar9 + -1;
    } while (0 < (int)uVar4);
  }
  return iVar6;
}



//------------------------------------------------------------
// clk_prepare_enable @ 00103bb8 size=76
// signature: undefined clk_prepare_enable(void)
// callers: [adsp_attach]
//------------------------------------------------------------

int clk_prepare_enable(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = clk_prepare();
  if (iVar1 == 0) {
    iVar1 = clk_enable(param_1);
    if (iVar1 != 0) {
      clk_unprepare(param_1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// enable_regulators @ 00103c04 size=256
// signature: undefined enable_regulators(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

int enable_regulators(undefined8 *param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (0 < *(int *)(param_1 + 0x30)) {
    lVar3 = 0;
    lVar4 = 0;
    do {
      regulator_set_voltage
                (*(undefined8 *)(param_1[0x2f] + lVar3),
                 *(undefined4 *)((undefined8 *)(param_1[0x2f] + lVar3) + 1),0x7fffffff);
      regulator_set_load(*(undefined8 *)(param_1[0x2f] + lVar3),
                         *(undefined4 *)(param_1[0x2f] + lVar3 + 0xc));
      iVar2 = regulator_enable(*(undefined8 *)(param_1[0x2f] + lVar3));
      if (iVar2 != 0) {
        _dev_err(*param_1,"Regulator enable failed(rc:%d)\n",iVar2);
        if ((int)(*(int *)(param_1 + 0x30) - 1U) < 0) {
          return iVar2;
        }
        lVar4 = (ulong)(*(int *)(param_1 + 0x30) - 1U) << 4;
        do {
          regulator_set_voltage(*(undefined8 *)(param_1[0x2f] + lVar4),0,0x7fffffff);
          regulator_set_load(*(undefined8 *)(param_1[0x2f] + lVar4),0);
          regulator_disable(*(undefined8 *)(param_1[0x2f] + lVar4));
          bVar1 = lVar4 != 0;
          lVar4 = lVar4 + -0x10;
        } while (bVar1);
        return iVar2;
      }
      lVar4 = lVar4 + 1;
      lVar3 = lVar3 + 0x10;
    } while (lVar4 < *(int *)(param_1 + 0x30));
  }
  return 0;
}



//------------------------------------------------------------
// scm_pas_enable_bw @ 00103d04 size=152
// signature: undefined scm_pas_enable_bw(void)
// callers: [adsp_stop, adsp_start, adsp_load]
//------------------------------------------------------------

void scm_pas_enable_bw(void)

{
  int iVar1;
  
  if (0xfffffffffffff000 < scm_perf_client) {
    return;
  }
  mutex_lock(q6v5_pas_mutex);
  if ((scm_pas_bw_count == 0) &&
     (iVar1 = icc_set_bw(scm_perf_client,0xffffffff,0xffffffff), iVar1 != 0)) {
    _printk(&DAT_001046b3,iVar1);
    icc_set_bw(scm_perf_client,0,0);
  }
  else {
    scm_pas_bw_count = scm_pas_bw_count + 1;
  }
  mutex_unlock(q6v5_pas_mutex);
  return;
}



//------------------------------------------------------------
// adsp_add_coredump_segments @ 00103d9c size=328
// signature: undefined adsp_add_coredump_segments(void)
// callers: [adsp_start]
//------------------------------------------------------------

void adsp_add_coredump_segments(undefined8 *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  uint *puVar11;
  
  lVar9 = *(long *)(param_2 + 8);
  lVar6 = param_1[2];
  uVar4 = (ulong)*(ushort *)(lVar9 + 0x2c);
  if (*(ushort *)(lVar9 + 0x2c) == 0) {
    uVar7 = 0;
    uVar8 = 0xffffffff;
  }
  else {
    uVar10 = 0;
    uVar7 = 0;
    uVar8 = 0xffffffff;
    puVar11 = (uint *)((ulong)*(uint *)(lVar9 + 0x1c) + lVar9 + 0x18);
    do {
      if (((puVar11[-6] == 1) && (uVar1 = *puVar11, (uVar1 & 0x7000000) != 0x2000000)) &&
         (puVar11[-1] != 0)) {
        uVar2 = puVar11[-3];
        iVar3 = rproc_coredump_add_segment(lVar6,uVar2);
        if (iVar3 != 0) {
          _dev_err(*param_1,"failed to add rproc segment: %d\n",iVar3);
          rproc_coredump_cleanup(param_1[2]);
          return;
        }
        if (uVar8 <= uVar2) {
          uVar2 = uVar8;
        }
        uVar7 = uVar7 | (uVar1 & 0x8000000) >> 0x1b;
        uVar4 = (ulong)*(ushort *)(lVar9 + 0x2c);
        uVar8 = uVar2;
      }
      uVar10 = uVar10 + 1;
      puVar11 = puVar11 + 8;
    } while (uVar10 < uVar4);
  }
  plVar5 = *(long **)(lVar6 + 0x4f8);
  if (plVar5 != (long *)(lVar6 + 0x4f8)) {
    do {
      plVar5[2] = (param_1[0x57] - (ulong)uVar8) + plVar5[2];
      plVar5 = (long *)*plVar5;
    } while (plVar5 != (long *)(lVar6 + 0x4f8));
  }
  if (uVar7 != 0) {
    param_1[0x58] = (param_1[0x57] - (ulong)uVar8) + param_1[0x58];
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00103ee4 size=128
// signature: undefined writel_relaxed(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

void writel_relaxed(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(1,0x20,param_2,writel_relaxed,uVar1);
  *param_2 = 1;
  log_post_write_mmio(1,0x20,param_2,0x103f34,uVar1);
  return;
}



//------------------------------------------------------------
// scm_pas_disable_bw @ 00103f64 size=108
// signature: undefined scm_pas_disable_bw(void)
// callers: [adsp_start]
//------------------------------------------------------------

void scm_pas_disable_bw(void)

{
  if (scm_perf_client < 0xfffffffffffff001) {
    mutex_lock(q6v5_pas_mutex);
    scm_pas_bw_count = scm_pas_bw_count + -1;
    if (scm_pas_bw_count == 0) {
      icc_set_bw(scm_perf_client,0,0);
    }
    mutex_unlock(q6v5_pas_mutex);
  }
  return;
}



//------------------------------------------------------------
// disable_regulators @ 00103fd0 size=124
// signature: undefined disable_regulators(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

void disable_regulators(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = *(int *)(param_1 + 0x180);
  if (-1 < (int)(iVar1 - 1U)) {
    lVar2 = (ulong)(iVar1 - 1U) << 4;
    do {
      regulator_set_voltage(*(undefined8 *)(*(long *)(param_1 + 0x178) + lVar2),0,0x7fffffff);
      regulator_set_load(*(undefined8 *)(*(long *)(param_1 + 0x178) + lVar2),0);
      regulator_disable(*(undefined8 *)(*(long *)(param_1 + 0x178) + lVar2));
      iVar1 = iVar1 + -1;
      lVar2 = lVar2 + -0x10;
    } while (0 < iVar1);
  }
  return;
}



//------------------------------------------------------------
// adsp_minidump @ 00104050 size=116
// signature: undefined adsp_minidump(void)
// callers: []
//------------------------------------------------------------

void adsp_minidump(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x3d0) != 0) {
    qcom_minidump(param_1,*(undefined8 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x1f0),
                  adsp_segment_dump,*(undefined1 *)(lVar1 + 500));
  }
  return;
}



//------------------------------------------------------------
// readl @ 001041b8 size=140
// signature: undefined readl(void)
// callers: [qcom_pas_handover, rproc_panic_handler]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x104210,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// txn_id_show @ 00104248 size=72
// signature: undefined txn_id_show(void)
// callers: []
//------------------------------------------------------------

long txn_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = qcom_sysmon_get_txn_id(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x408));
  iVar2 = sysfs_emit(param_3,&DAT_00104cdd,uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// init_module @ 00104328 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&adsp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104358 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&adsp_driver);
  return;
}



//------------------------------------------------------------
// strnlen @ 00110000 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00110008 size=1
// signature: undefined fortify_panic(void)
// callers: [adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00110010 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00110018 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [adsp_stop, adsp_segment_dump, adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00110028 size=1
// signature: undefined ioremap_prot(void)
// callers: [rproc_find_status_register, adsp_stop, adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00110030 size=1
// signature: undefined iounmap(void)
// callers: [rproc_find_status_register, adsp_stop, adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00110038 size=1
// signature: undefined _dev_err(void)
// callers: [rproc_find_status_register, qcom_pas_handover, adsp_stop, adsp_segment_dump, adsp_setup_wakeup, adsp_init_bus_scaling, adsp_init_regulator, read_early_boot_register, adsp_start, enable_regulators, qcom_rproc_set_dtb_firmware, adsp_init_clock, adsp_probe, rproc_panic_handler, adsp_add_coredump_segments, adsp_attach, adsp_load, adsp_setup_32b_dma_allocs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00110040 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [adsp_segment_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock_interruptible @ 00110048 size=1
// signature: undefined mutex_lock_interruptible(void)
// callers: [qcom_rproc_set_dtb_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcspn @ 00110050 size=1
// signature: size_t strcspn(char * __s, char * __reject)
// callers: [qcom_rproc_set_dtb_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 00110058 size=1
// signature: undefined kstrndup(void)
// callers: [qcom_rproc_set_dtb_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_const @ 00110060 size=1
// signature: undefined kfree_const(void)
// callers: [adsp_probe, adsp_remove, qcom_rproc_set_dtb_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00110068 size=1
// signature: undefined mutex_unlock(void)
// callers: [scm_pas_enable_bw, adsp_stop, adsp_probe, qcom_rproc_update_recovery_status, scm_pas_disable_bw, adsp_load, qcom_rproc_set_dtb_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irqchip_state @ 00110070 size=1
// signature: undefined irq_get_irqchip_state(void)
// callers: [read_early_boot_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irqchip_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00110080 size=1
// signature: undefined mod_timer(void)
// callers: [read_early_boot_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00110088 size=1
// signature: undefined complete(void)
// callers: [read_early_boot_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00110090 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_pas_handover, rproc_panic_handler, adsp_init_bus_scaling, read_early_boot_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00110098 size=1
// signature: undefined mutex_lock(void)
// callers: [scm_pas_enable_bw, adsp_stop, adsp_probe, qcom_rproc_update_recovery_status, scm_pas_disable_bw, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001100a0 size=1
// signature: undefined _printk(void)
// callers: [scm_pas_enable_bw, adsp_stop, qcom_rproc_update_recovery_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001100a8 size=1
// signature: undefined __platform_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 001100b0 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 001100b8 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_is_available @ 001100c0 size=1
// signature: undefined qcom_scm_is_available(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001100c8 size=1
// signature: undefined of_property_read_string(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_alloc @ 001100d0 size=1
// signature: undefined rproc_alloc(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_set_elf_info @ 001100d8 size=1
// signature: undefined rproc_coredump_set_elf_info(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_set_elf_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup_const @ 001100e0 size=1
// signature: undefined kstrdup_const(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001100e8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [adsp_probe, adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001100f0 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_init @ 001100f8 size=1
// signature: undefined of_phandle_iterator_init(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_next @ 00110100 size=1
// signature: undefined of_phandle_iterator_next(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00110108 size=1
// signature: undefined of_address_to_resource(void)
// callers: [rproc_find_status_register, adsp_stop, adsp_probe, adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00110110 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [rproc_find_status_register, adsp_stop, adsp_probe, adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 00110118 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00110120 size=1
// signature: undefined of_find_property(void)
// callers: [adsp_probe, adsp_init_bus_scaling, adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 00110128 size=1
// signature: undefined qmp_get(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_init @ 00110130 size=1
// signature: undefined qcom_q6v5_init(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_clear_wake_irq @ 00110138 size=1
// signature: undefined dev_pm_clear_wake_irq(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_clear_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00110140 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [adsp_probe, adsp_setup_wakeup, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00110148 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [adsp_probe, adsp_setup_wakeup, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_free @ 00110150 size=1
// signature: undefined rproc_free(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_qcom_smem_state_get @ 00110158 size=1
// signature: undefined devm_qcom_smem_state_get(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00110160 size=1
// signature: undefined __mutex_init(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_register_ssr_subdev @ 00110168 size=1
// signature: undefined qcom_q6v5_register_ssr_subdev(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_register_ssr_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pil_timeouts_disabled @ 00110170 size=1
// signature: undefined qcom_pil_timeouts_disabled(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pil_timeouts_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_glink_subdev @ 00110178 size=1
// signature: undefined qcom_add_glink_subdev(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_glink_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_smd_subdev @ 00110180 size=1
// signature: undefined qcom_add_smd_subdev(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_smd_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_sysmon_subdev @ 00110188 size=1
// signature: undefined qcom_add_sysmon_subdev(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_sysmon_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_ssr_subdev @ 00110190 size=1
// signature: undefined qcom_add_ssr_subdev(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_ssr_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00110198 size=1
// signature: undefined device_create_file(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001101a0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [adsp_probe, adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_create_ramdump_device @ 001101a8 size=1
// signature: undefined qcom_create_ramdump_device(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_create_ramdump_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ping_subsystem_init @ 001101b0 size=1
// signature: undefined ping_subsystem_init(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ping_subsystem_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_add @ 001101b8 size=1
// signature: undefined rproc_add(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_destroy_ramdump_device @ 001101c0 size=1
// signature: undefined qcom_destroy_ramdump_device(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_destroy_ramdump_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 001101c8 size=1
// signature: undefined device_remove_file(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_sysmon_subdev @ 001101d0 size=1
// signature: undefined qcom_remove_sysmon_subdev(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_sysmon_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001101e0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 001101f0 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [adsp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001101f8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [rproc_find_status_register, adsp_stop, adsp_probe, adsp_init_bus_scaling, adsp_init_regulator, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_del @ 00110200 size=1
// signature: undefined rproc_del(void)
// callers: [adsp_probe, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00110208 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_glink_subdev @ 00110210 size=1
// signature: undefined qcom_remove_glink_subdev(void)
// callers: [adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_glink_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_smd_subdev @ 00110218 size=1
// signature: undefined qcom_remove_smd_subdev(void)
// callers: [adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_smd_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_ssr_subdev @ 00110220 size=1
// signature: undefined qcom_remove_ssr_subdev(void)
// callers: [adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_ssr_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00110228 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00110230 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [adsp_pds_detach, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_detach @ 00110238 size=1
// signature: undefined dev_pm_domain_detach(void)
// callers: [adsp_pds_attach, adsp_pds_detach, adsp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00110240 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [adsp_setup_32b_dma_allocs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00110248 size=1
// signature: undefined dma_set_mask(void)
// callers: [adsp_setup_32b_dma_allocs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00110250 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [adsp_setup_32b_dma_allocs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00110258 size=1
// signature: undefined devm_clk_get(void)
// callers: [adsp_init_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get_optional @ 00110260 size=1
// signature: undefined devm_clk_get_optional(void)
// callers: [adsp_init_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00110268 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00110270 size=1
// signature: undefined devm_regulator_get(void)
// callers: [adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00110278 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [rproc_find_status_register, adsp_init_bus_scaling, adsp_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00110280 size=1
// signature: undefined of_icc_get(void)
// callers: [adsp_init_bus_scaling]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00110288 size=1
// signature: undefined _dev_warn(void)
// callers: [adsp_init_bus_scaling]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00110290 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [adsp_pds_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach_by_name @ 00110298 size=1
// signature: undefined dev_pm_domain_attach_by_name(void)
// callers: [adsp_pds_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001102a0 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [qcom_pas_handover, disable_regulators, enable_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 001102a8 size=1
// signature: undefined regulator_set_load(void)
// callers: [qcom_pas_handover, disable_regulators, enable_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001102b0 size=1
// signature: undefined regulator_disable(void)
// callers: [qcom_pas_handover, disable_regulators, enable_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001102b8 size=1
// signature: undefined clk_disable(void)
// callers: [qcom_pas_handover, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001102c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [clk_prepare_enable, qcom_pas_handover, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_set_performance_state @ 001102c8 size=1
// signature: undefined dev_pm_genpd_set_performance_state(void)
// callers: [qcom_pas_handover, adsp_stop, adsp_start, adsp_pds_enable, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_set_performance_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001102d0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [qcom_pas_handover, adsp_stop, adsp_start, adsp_pds_enable, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 001102d8 size=1
// signature: undefined icc_set_bw(void)
// callers: [qcom_pas_handover, scm_pas_enable_bw, adsp_stop, scm_pas_disable_bw, adsp_start, adsp_attach, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001102e0 size=1
// signature: undefined usleep_range_state(void)
// callers: [qcom_pas_handover]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001102e8 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [adsp_setup_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_set_wake_irq @ 001102f0 size=1
// signature: undefined dev_pm_set_wake_irq(void)
// callers: [adsp_setup_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_set_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001102f8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [rproc_find_status_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00110300 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00110308 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00110310 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [android_vh_rproc_recovery_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_update_bits @ 00110318 size=1
// signature: undefined qcom_smem_state_update_bits(void)
// callers: [rproc_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00110320 size=1
// signature: undefined ktime_get(void)
// callers: [rproc_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00110328 size=1
// signature: undefined __const_udelay(void)
// callers: [rproc_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_prepare @ 00110338 size=1
// signature: undefined qcom_q6v5_prepare(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00110340 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [adsp_stop, adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_rproc_toggle_load_state @ 00110348 size=1
// signature: undefined qcom_rproc_toggle_load_state(void)
// callers: [adsp_stop, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_rproc_toggle_load_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00110350 size=1
// signature: undefined clk_prepare(void)
// callers: [clk_prepare_enable, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00110358 size=1
// signature: undefined clk_enable(void)
// callers: [clk_prepare_enable, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_auth_and_reset @ 00110360 size=1
// signature: undefined qcom_scm_pas_auth_and_reset(void)
// callers: [adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_auth_and_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 00110368 size=1
// signature: undefined request_firmware(void)
// callers: [adsp_start, adsp_attach, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_mdt_load_no_free @ 00110370 size=1
// signature: undefined qcom_mdt_load_no_free(void)
// callers: [adsp_start, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_mdt_load_no_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pil_info_store @ 00110378 size=1
// signature: undefined qcom_pil_info_store(void)
// callers: [adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pil_info_store(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00110380 size=1
// signature: undefined msleep(void)
// callers: [adsp_stop, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_wait_for_start @ 00110388 size=1
// signature: undefined qcom_q6v5_wait_for_start(void)
// callers: [adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_wait_for_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_mdt_free_metadata @ 00110390 size=1
// signature: undefined qcom_mdt_free_metadata(void)
// callers: [adsp_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_mdt_free_metadata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 00110398 size=1
// signature: undefined release_firmware(void)
// callers: [adsp_start, adsp_attach, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_unprepare @ 001103a0 size=1
// signature: undefined qcom_q6v5_unprepare(void)
// callers: [adsp_stop, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001103a8 size=1
// signature: noreturn undefined panic(void)
// callers: [adsp_stop, adsp_start, adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_request_stop @ 001103d0 size=1
// signature: undefined qcom_q6v5_request_stop(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_request_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown_retry @ 001103d8 size=1
// signature: undefined qcom_scm_pas_shutdown_retry(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_shutdown_retry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown @ 001103e0 size=1
// signature: undefined qcom_scm_pas_shutdown(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_bust_hwspin_lock_by_host @ 001103e8 size=1
// signature: undefined qcom_smem_bust_hwspin_lock_by_host(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_bust_hwspin_lock_by_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 001103f0 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_add_custom_segment @ 001103f8 size=1
// signature: undefined rproc_coredump_add_custom_segment(void)
// callers: [adsp_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_add_custom_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_dump_segments @ 00110400 size=1
// signature: undefined qcom_register_dump_segments(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_dump_segments(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00110408 size=1
// signature: undefined init_timer_key(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00110410 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 00110418 size=1
// signature: undefined wait_for_completion(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 00110420 size=1
// signature: undefined del_timer(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ping_subsystem @ 00110428 size=1
// signature: undefined ping_subsystem(void)
// callers: [adsp_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ping_subsystem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_cleanup @ 00110430 size=1
// signature: undefined rproc_coredump_cleanup(void)
// callers: [adsp_add_coredump_segments, adsp_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_q6v5_panic @ 00110438 size=1
// signature: undefined qcom_q6v5_panic(void)
// callers: [adsp_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_q6v5_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00110440 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [adsp_pds_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00110450 size=1
// signature: undefined regulator_enable(void)
// callers: [enable_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_add_segment @ 00110458 size=1
// signature: undefined rproc_coredump_add_segment(void)
// callers: [adsp_add_coredump_segments]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_add_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00110460 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00110468 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_minidump @ 00110470 size=1
// signature: undefined qcom_minidump(void)
// callers: [adsp_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_minidump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_sysmon_get_txn_id @ 00110478 size=1
// signature: undefined qcom_sysmon_get_txn_id(void)
// callers: [txn_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_sysmon_get_txn_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00110480 size=1
// signature: undefined sysfs_emit(void)
// callers: [txn_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



