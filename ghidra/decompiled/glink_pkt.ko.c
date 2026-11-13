// Decompiled by Ghidra 12.2
// Program: glink_pkt.ko
// Image base: 00100000

//------------------------------------------------------------
// glink_pkt_probe @ 00100b2c size=2132
// signature: undefined glink_pkt_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong glink_pkt_probe(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  char *pcVar13;
  
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  lVar6 = of_get_next_child(uVar12,0);
  if (lVar6 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      lVar6 = of_get_next_child(uVar12,lVar6);
    } while (lVar6 != 0);
  }
  num_glink_pkt_devs = iVar4;
  uVar3 = alloc_chrdev_region(&glink_pkt_major,0,iVar4,"glinkpkt");
  if ((int)uVar3 < 0) {
    uVar7 = (ulong)uVar3;
    iVar4 = ___ratelimit(glink_pkt_probe__rs,"glink_pkt_probe");
    if (iVar4 != 0) {
      _printk("%s[%s]: alloc_chrdev_region failed ret:%d\n",&DAT_001043e9,"glink_pkt_probe",uVar7);
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: alloc_chrdev_region failed ret:%d\n",&DAT_001044f7,
                   "glink_pkt_probe",uVar7);
  }
  else {
    uVar7 = __class_create(&__this_module,"glinkpkt",&glink_pkt_probe___key);
    glink_pkt_class = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      lVar6 = of_get_next_child(*(undefined8 *)(param_1 + 0x2f8),0);
      if (lVar6 != 0) {
        do {
          pcVar13 = "qcom,glinkpkt-edge";
          lVar8 = kmalloc_trace(_dev_set_name,0xdc0,0x640);
          if (lVar8 != 0) {
            uVar3 = ida_alloc_range(glink_pkt_minor_ida,0,num_glink_pkt_devs + -1,0xcc0);
            if ((int)uVar3 < 0) {
              kfree(lVar8);
            }
            else {
              iVar4 = of_property_read_string(lVar6,"qcom,glinkpkt-edge",lVar8 + 0x5e8);
              if (-1 < iVar4) {
                pcVar13 = "qcom,glinkpkt-ch-name";
                iVar4 = of_property_read_string(lVar6,"qcom,glinkpkt-ch-name");
                if (-1 < iVar4) {
                  puVar1 = (undefined8 *)(lVar8 + 0x5d8);
                  pcVar13 = "qcom,glinkpkt-dev-name";
                  iVar4 = of_property_read_string(lVar6,"qcom,glinkpkt-dev-name",puVar1);
                  if (-1 < iVar4) {
                    lVar9 = of_find_property(lVar6,"qcom,glinkpkt-enable-ch-close",0);
                    *(bool *)(lVar8 + 0x4cd) = lVar9 != 0;
                    lVar9 = of_find_property(lVar6,"qcom,glinkpkt-fragmented-read",0);
                    uVar12 = glink_pkt_ilctxt;
                    *(bool *)(lVar8 + 0x4cc) = lVar9 != 0;
                    ipc_log_string(uVar12,
                                   "[%s]: Parsed %s:%s /dev/%s enable channel close:%d fragmented-read:%d\n"
                                   ,"glink_pkt_parse_devicetree",*(undefined8 *)(lVar8 + 0x5e8),
                                   *(undefined8 *)(lVar8 + 0x5e0),*(undefined8 *)(lVar8 + 0x5d8),
                                   *(undefined1 *)(lVar8 + 0x4cd));
                    __mutex_init(lVar8 + 0x418,"&gpdev->lock",&glink_pkt_create_device___key);
                    lVar9 = lVar8 + 0x4d0;
                    __mutex_init(lVar9,"&gpdev->drv_lock",&glink_pkt_create_device___key_11);
                    __mutex_init(lVar8 + 0x5f8,"&gpdev->rskb_read_lock",
                                 &glink_pkt_create_device___key_13);
                    *(undefined4 *)(lVar8 + 0x468) = 1;
                    *(undefined4 *)(lVar8 + 0x448) = 0;
                    __init_swait_queue_head(lVar8 + 0x450,"&x->wait",&init_completion___key);
                    *(undefined4 *)(lVar8 + 0x5f0) = 0x78;
                    *(undefined4 *)(lVar8 + 0x4c8) = 0;
                    *(undefined1 *)(lVar8 + 0x478) = 0;
                    *(long *)(lVar8 + 0x480) = lVar8 + 0x480;
                    *(long *)(lVar8 + 0x488) = lVar8 + 0x480;
                    *(undefined4 *)(lVar8 + 0x47c) = 0;
                    *(undefined8 *)(lVar8 + 0x628) = 0;
                    *(undefined8 *)(lVar8 + 0x630) = 0;
                    *(undefined8 *)(lVar8 + 0x638) = 0;
                    *(long *)(lVar8 + 0x498) = lVar8 + 0x498;
                    *(long *)(lVar8 + 0x4a0) = lVar8 + 0x498;
                    *(undefined8 *)(lVar8 + 0x490) = 0;
                    *(undefined8 *)(lVar8 + 0x4a8) = 0;
                    __init_waitqueue_head
                              (lVar8 + 0x4b0,"&gpdev->readq",&glink_pkt_create_device___key_15);
                    device_initialize(lVar8);
                    uVar7 = glink_pkt_class;
                    *(long *)(lVar8 + 0x60) = param_1 + 0x10;
                    *(long *)(lVar8 + 0x98) = lVar8;
                    *(ulong *)(lVar8 + 0x318) = uVar7;
                    *(undefined ***)(lVar8 + 800) = &glink_pkt_device_groups;
                    cdev_init(lVar8 + 0x390,&glink_pkt_fops);
                    uVar2 = glink_pkt_major;
                    *(undefined1 **)(lVar8 + 0x3f0) = &__this_module;
                    *(uint *)(lVar8 + 0x2f8) = uVar2 & 0xfff00000 | uVar3;
                    dev_set_name(lVar8,*(undefined8 *)(lVar8 + 0x5d8),uVar3);
                    iVar4 = cdev_add(lVar8 + 0x390,*(undefined4 *)(lVar8 + 0x2f8),1);
                    if (iVar4 != 0) {
                      iVar5 = ___ratelimit(glink_pkt_create_device__rs_17,"glink_pkt_create_device")
                      ;
                      if (iVar5 != 0) {
                        _printk("%s[%s]: cdev_add failed for %s ret:%d\n",&DAT_001043e9,
                                "glink_pkt_create_device",*puVar1,iVar4);
                      }
                      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: cdev_add failed for %s ret:%d\n",
                                     &DAT_001044f7,"glink_pkt_create_device",
                                     *(undefined8 *)(lVar8 + 0x5d8),iVar4);
                      ida_free(glink_pkt_minor_ida,*(uint *)(lVar8 + 0x2f8) & 0xfffff);
                      kfree(lVar8);
                      goto LAB_00100cdc;
                    }
                    *(code **)(lVar8 + 0x328) = glink_pkt_release_device;
                    iVar4 = device_add(lVar8);
                    if (iVar4 == 0) {
                      iVar4 = device_create_file(lVar8,&dev_attr_open_timeout);
                      if (iVar4 != 0) {
                        iVar4 = ___ratelimit(glink_pkt_create_device__rs_21,
                                             "glink_pkt_create_device");
                        if (iVar4 != 0) {
                          _printk("%s[%s]: device_create_file failed for %s\n",&DAT_001043e9,
                                  "glink_pkt_create_device",*puVar1);
                        }
                        ipc_log_string(glink_pkt_ilctxt,"%s[%s]: device_create_file failed for %s\n"
                                       ,&DAT_001044f7,"glink_pkt_create_device",*puVar1);
                      }
                      lVar10 = devm_kmalloc(lVar8,0x50,0xdc0);
                      if (lVar10 != 0) {
                        pcVar13 = *(char **)(lVar8 + 0x5e0);
                        uVar7 = strnlen(pcVar13,0x20);
                        if (uVar7 == 0xffffffffffffffff) {
LAB_00101374:
                          fortify_panic("strnlen");
                          lVar8 = func_0x03ca0b4c();
                          lVar6 = sp_el0;
                          ipc_log_string(glink_pkt_ilctxt,"[%s]: for %s by %s:%d ref_cnt[%d]\n",
                                         "glink_pkt_release_device",*(undefined8 *)(lVar8 + 0x5e0),
                                         lVar6 + 0x848,*(undefined4 *)(lVar6 + 0x630),
                                         *(undefined4 *)(lVar8 + 0x468));
                          ida_free(glink_pkt_minor_ida,*(uint *)(lVar8 + 0x2f8) & 0xfffff);
                          cdev_del(lVar8 + 0x390);
                          uVar7 = kfree(lVar8);
                          return uVar7;
                        }
                        if (uVar7 != 0x20) {
                          uVar7 = uVar7 + 1;
                        }
                        if (0x20 < uVar7) {
                          fortify_panic("strscpy");
                          goto LAB_00101374;
                        }
                        strscpy(lVar10,pcVar13);
                        lVar11 = devm_kasprintf(lVar8,0xcc0,"%s_%s","glink_pkt",
                                                *(undefined8 *)(lVar8 + 0x5d8));
                        if (lVar11 != 0) {
                          *(long *)(lVar8 + 0x500) = lVar11;
                          *(long *)(lVar8 + 0x5b0) = lVar10;
                          *(code **)(lVar8 + 0x5b8) = glink_pkt_rpdev_probe;
                          *(code **)(lVar8 + 0x5c0) = glink_pkt_rpdev_remove;
                          *(code **)(lVar8 + 0x5c8) = glink_pkt_rpdev_cb;
                          mutex_lock(lVar9);
                          if (*(char *)(lVar8 + 0x5d0) == '\0') {
                            iVar4 = __register_rpmsg_driver(lVar8 + 0x500,&__this_module);
                            if (iVar4 != 0) {
                              mutex_unlock(lVar9);
                              goto LAB_001010cc;
                            }
                            *(undefined1 *)(lVar8 + 0x5d0) = 1;
                          }
                          mutex_unlock(lVar9);
                          goto LAB_00100cdc;
                        }
                      }
                    }
                    else {
                      iVar5 = ___ratelimit(glink_pkt_create_device__rs_19,"glink_pkt_create_device")
                      ;
                      if (iVar5 != 0) {
                        _printk("%s[%s]: device_create failed for %s ret:%d\n",&DAT_001043e9,
                                "glink_pkt_create_device",*puVar1,iVar4);
                      }
                      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: device_create failed for %s ret:%d\n"
                                     ,&DAT_001044f7,"glink_pkt_create_device",*puVar1,iVar4);
                    }
LAB_001010cc:
                    put_device(lVar8);
                    goto LAB_00100cdc;
                  }
                }
              }
              iVar5 = ___ratelimit(glink_pkt_parse_devicetree__rs,"glink_pkt_parse_devicetree");
              if (iVar5 != 0) {
                _printk("%s[%s]: %s: missing key: %s\n",&DAT_001043e9,"glink_pkt_parse_devicetree",
                        "glink_pkt_parse_devicetree",pcVar13);
              }
              ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s: missing key: %s\n",&DAT_001044f7,
                             "glink_pkt_parse_devicetree","glink_pkt_parse_devicetree",pcVar13);
              iVar5 = ___ratelimit(glink_pkt_create_device__rs,"glink_pkt_create_device");
              if (iVar5 != 0) {
                _printk("%s[%s]: failed to parse dt ret:%d\n",&DAT_001043e9,
                        "glink_pkt_create_device",iVar4);
              }
              ipc_log_string(glink_pkt_ilctxt,"%s[%s]: failed to parse dt ret:%d\n",&DAT_001044f7,
                             "glink_pkt_create_device",iVar4);
              ida_free(glink_pkt_minor_ida,*(uint *)(lVar8 + 0x2f8) & 0xfffff);
              kfree(lVar8);
            }
          }
LAB_00100cdc:
          lVar6 = of_get_next_child(*(undefined8 *)(param_1 + 0x2f8),lVar6);
        } while (lVar6 != 0);
      }
      ipc_log_string(glink_pkt_ilctxt,"[%s]: G-Link Packet Port Driver Initialized\n",
                     "glink_pkt_probe");
      uVar7 = 0;
    }
    else {
      iVar4 = ___ratelimit(glink_pkt_probe__rs_6,"glink_pkt_probe");
      if (iVar4 != 0) {
        _printk("%s[%s]: class_create failed ret:%d\n",&DAT_001043e9,"glink_pkt_probe",
                uVar7 & 0xffffffff);
      }
      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: class_create failed ret:%d\n",&DAT_001044f7,
                     "glink_pkt_probe",uVar7 & 0xffffffff);
      class_destroy(glink_pkt_class);
      unregister_chrdev_region(glink_pkt_major >> 0x14,num_glink_pkt_devs);
    }
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// glink_pkt_release_device @ 00101384 size=120
// signature: undefined glink_pkt_release_device(void)
// callers: []
//------------------------------------------------------------

void glink_pkt_release_device(long param_1)

{
  long lVar1;
  
  lVar1 = sp_el0;
  ipc_log_string(glink_pkt_ilctxt,"[%s]: for %s by %s:%d ref_cnt[%d]\n","glink_pkt_release_device",
                 *(undefined8 *)(param_1 + 0x5e0),lVar1 + 0x848,*(undefined4 *)(lVar1 + 0x630),
                 *(undefined4 *)(param_1 + 0x468));
  ida_free(glink_pkt_minor_ida,*(uint *)(param_1 + 0x2f8) & 0xfffff);
  cdev_del(param_1 + 0x390);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// name_show @ 00101400 size=56
// signature: undefined name_show(void)
// callers: []
//------------------------------------------------------------

long name_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x20,&DAT_001047bc,*(undefined8 *)(param_1 + 0x5e0));
  return (long)iVar1;
}



//------------------------------------------------------------
// glink_pkt_read @ 0010143c size=1320
// signature: undefined glink_pkt_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void glink_pkt_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  undefined8 *puVar6;
  ulong uVar7;
  code *pcVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 uVar14;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  lVar13 = *(long *)(param_1 + 0xd8);
  if ((lVar13 == 0) || (*(int *)(lVar13 + 0x468) == 1)) {
    iVar9 = ___ratelimit(glink_pkt_read__rs,"glink_pkt_read");
    if (iVar9 != 0) {
      _printk("%s[%s]: invalid device handle\n",&DAT_001043e9,"glink_pkt_read");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: invalid device handle\n",&DAT_001044f7,"glink_pkt_read"
                  );
    lVar13 = -0x16;
    goto LAB_001018b0;
  }
  lVar1 = lVar13 + 0x418;
  iVar9 = mutex_lock_interruptible(lVar1);
  if (iVar9 == 0) {
    lVar2 = lVar13 + 0x448;
    uVar10 = completion_done(lVar2);
    if ((uVar10 & 1) == 0) {
      iVar9 = ___ratelimit(glink_pkt_read__rs_34,"glink_pkt_read");
      if (iVar9 != 0) {
        _printk("%s[%s]: %s channel in reset\n",&DAT_001043e9,"glink_pkt_read",
                *(undefined8 *)(lVar13 + 0x5e0));
      }
      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s channel in reset\n",&DAT_001044f7,"glink_pkt_read"
                     ,*(undefined8 *)(lVar13 + 0x5e0));
      mutex_unlock(lVar1);
      lVar13 = -0x66;
      goto LAB_001018b0;
    }
    puVar6 = (undefined8 *)sp_el0;
    ipc_log_string(glink_pkt_ilctxt,
                   "[%s]: begin for %s by %s:%d ref_cnt[%d], remaining[%d], count[%d]\n",
                   "glink_pkt_read",*(undefined8 *)(lVar13 + 0x5e0),puVar6 + 0x109,
                   *(undefined4 *)(puVar6 + 0xc6),*(undefined4 *)(lVar13 + 0x468),
                   *(undefined8 *)(lVar13 + 0x638),param_3);
    mutex_unlock(lVar1);
    lVar3 = lVar13 + 0x47c;
    _raw_spin_lock_irq(lVar3);
    plVar4 = (long *)(lVar13 + 0x480);
    if ((*(long **)(lVar13 + 0x480) == plVar4) && (*(long *)(lVar13 + 0x628) == 0)) {
      if ((*(byte *)(param_1 + 0x41) >> 3 & 1) != 0) {
        _raw_spin_unlock_irq(lVar3);
        lVar13 = -0xb;
        goto LAB_001018b0;
      }
      uVar10 = completion_done(lVar2);
      if ((uVar10 & 1) != 0) {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = 0;
        init_wait_entry(&local_90,0);
        lVar11 = lVar13 + 0x4b0;
        lVar12 = prepare_to_wait_event(lVar11,&local_90,1);
        if (*(long **)(lVar13 + 0x480) == plVar4) {
          do {
            uVar10 = completion_done(lVar2);
            if ((uVar10 & 1) == 0) break;
            if (lVar12 != 0) {
              _raw_spin_unlock_irq(lVar3);
              if ((int)lVar12 != 0) goto LAB_001014e0;
              goto LAB_0010156c;
            }
            _raw_spin_unlock_irq(lVar3);
            schedule();
            _raw_spin_lock_irq(lVar3);
            lVar12 = prepare_to_wait_event(lVar11,&local_90,1);
          } while ((long *)*plVar4 == plVar4);
        }
        finish_wait(lVar11,&local_90);
      }
    }
    _raw_spin_unlock_irq(lVar3);
LAB_0010156c:
    uVar10 = completion_done(lVar2);
    if ((uVar10 & 1) == 0) {
      lVar13 = -0x66;
      goto LAB_001018b0;
    }
    iVar9 = mutex_lock_interruptible(lVar1);
    if (iVar9 == 0) {
      lVar2 = lVar13 + 0x5f8;
      mutex_lock(lVar2);
      _raw_spin_lock_irq(lVar3);
      plVar5 = (long *)(lVar13 + 0x628);
      if (*(long *)(lVar13 + 0x628) == 0) {
        lVar11 = skb_dequeue(plVar4);
        *plVar5 = lVar11;
        if (lVar11 == 0) {
          _raw_spin_unlock_irq(lVar3);
          mutex_unlock(lVar2);
          mutex_unlock(lVar1);
          lVar13 = 0;
          goto LAB_001018b0;
        }
        *(undefined8 *)(lVar13 + 0x630) = *(undefined8 *)(lVar11 + 0xe0);
        *(ulong *)(lVar13 + 0x638) = (ulong)*(uint *)(lVar11 + 0x70);
      }
      _raw_spin_unlock_irq(lVar3);
      uVar10 = *(ulong *)(lVar13 + 0x638);
      if (param_3 <= *(ulong *)(lVar13 + 0x638)) {
        uVar10 = param_3;
      }
      iVar9 = (int)uVar10;
      lVar11 = (long)iVar9;
      if (0x7fffffff00000000 < uVar10 << 0x20) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x800,0x101948);
        (*pcVar8)();
      }
      uVar14 = *(undefined8 *)(lVar13 + 0x630);
      __check_object_size(uVar14,lVar11,1);
      if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
         (uVar10 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
        uVar10 = param_2 & (long)(param_2 << 8) >> 8;
      }
      lVar12 = lVar11;
      if (uVar10 <= 0x8000000000U - lVar11) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar7 = daif;
            daif = uVar7 | 0xc0;
          }
          uVar7 = ttbr1_el1;
          ttbr1_el1 = puVar6[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar6[1];
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
        lVar12 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,uVar14,lVar11);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar7 = daif;
            daif = uVar7 | 0xc0;
          }
          uVar7 = ttbr1_el1;
          ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar7 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
      }
      if (lVar12 != 0) {
        iVar9 = -0xe;
      }
      _raw_spin_lock_irq(0xfffffff2,lVar3);
      lVar12 = *(long *)(lVar13 + 0x638) - lVar11;
      *(long *)(lVar13 + 0x630) = *(long *)(lVar13 + 0x630) + lVar11;
      *(long *)(lVar13 + 0x638) = lVar12;
      if ((*(char *)(lVar13 + 0x4cc) == '\0') || (lVar12 == 0)) {
        lVar11 = *plVar5;
        *(undefined8 *)(lVar13 + 0x630) = 0;
        *(undefined8 *)(lVar13 + 0x638) = 0;
        *plVar5 = 0;
        _raw_spin_unlock_irq(lVar3);
        if (lVar11 != 0) {
          glink_pkt_kfree_skb(lVar13,lVar11);
        }
      }
      else {
        _raw_spin_unlock_irq(lVar3);
      }
      mutex_unlock(lVar2);
      ipc_log_string(glink_pkt_ilctxt,"[%s]: end for %s by %s:%d ret[%d], remaining[%d]\n",
                     "glink_pkt_read",*(undefined8 *)(lVar13 + 0x5e0),puVar6 + 0x109,
                     *(undefined4 *)(puVar6 + 0xc6),iVar9,*(undefined8 *)(lVar13 + 0x638));
      mutex_unlock(lVar1);
      lVar13 = (long)iVar9;
      goto LAB_001018b0;
    }
  }
LAB_001014e0:
  lVar13 = -0x200;
LAB_001018b0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar13);
  }
  return;
}



//------------------------------------------------------------
// glink_pkt_write @ 00101984 size=488
// signature: undefined glink_pkt_write(void)
// callers: []
//------------------------------------------------------------

ulong glink_pkt_write(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xd8);
  if ((lVar4 == 0) || (*(int *)(lVar4 + 0x468) == 1)) {
    iVar1 = ___ratelimit(glink_pkt_write__rs,"glink_pkt_write");
    if (iVar1 != 0) {
      _printk("%s[%s]: invalid device handle\n",&DAT_001043e9,"glink_pkt_write");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: invalid device handle\n",&DAT_001044f7,
                   "glink_pkt_write");
    uVar3 = 0xffffffffffffffea;
  }
  else {
    ipc_log_string(glink_pkt_ilctxt,"[%s]: begin to %s buffer_size %zu\n","glink_pkt_write",
                   *(undefined8 *)(lVar4 + 0x5e0),param_3);
    uVar3 = vmemdup_user(param_2,param_3);
    if (uVar3 < 0xfffffffffffff001) {
      iVar1 = mutex_lock_interruptible(lVar4 + 0x418);
      if (iVar1 == 0) {
        uVar2 = completion_done(lVar4 + 0x448);
        if (((uVar2 & 1) == 0) || (*(long *)(lVar4 + 0x470) == 0)) {
          iVar1 = ___ratelimit(glink_pkt_write__rs_41,"glink_pkt_write");
          if (iVar1 != 0) {
            _printk("%s[%s]: %s channel in reset\n",&DAT_001043e9,"glink_pkt_write",
                    *(undefined8 *)(lVar4 + 0x5e0));
          }
          ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s channel in reset\n",&DAT_001044f7,
                         "glink_pkt_write",*(undefined8 *)(lVar4 + 0x5e0));
          iVar1 = -0x66;
        }
        else if ((*(byte *)(param_1 + 0x41) >> 3 & 1) == 0) {
          iVar1 = rpmsg_send();
        }
        else {
          iVar1 = rpmsg_trysend(*(undefined8 *)(*(long *)(lVar4 + 0x470) + 0x3c8),uVar3,
                                param_3 & 0xffffffff);
        }
        mutex_unlock(lVar4 + 0x418);
      }
      else {
        iVar1 = -0x200;
      }
      kvfree(uVar3);
      ipc_log_string(glink_pkt_ilctxt,"[%s]: finish to %s ret %d\n","glink_pkt_write",
                     *(undefined8 *)(lVar4 + 0x5e0),iVar1);
      uVar3 = (long)iVar1;
      if (-1 < iVar1) {
        uVar3 = param_3;
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// glink_pkt_poll @ 00101b70 size=676
// signature: undefined glink_pkt_poll(void)
// callers: []
//------------------------------------------------------------

uint glink_pkt_poll(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint uVar6;
  code *pcVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0xd8);
  if ((lVar8 == 0) || (*(int *)(lVar8 + 0x468) == 1)) {
    iVar2 = ___ratelimit(glink_pkt_poll__rs,"glink_pkt_poll");
    if (iVar2 != 0) {
      _printk("%s[%s]: invalid device handle\n",&DAT_001043e9,"glink_pkt_poll");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: invalid device handle\n",&DAT_001044f7,"glink_pkt_poll"
                  );
    uVar3 = 8;
  }
  else {
    uVar4 = completion_done(lVar8 + 0x448);
    if ((uVar4 & 1) == 0) {
      iVar2 = ___ratelimit(glink_pkt_poll__rs_43,"glink_pkt_poll");
      if (iVar2 != 0) {
        _printk("%s[%s]: %s channel in reset\n",&DAT_001043e9,"glink_pkt_poll",
                *(undefined8 *)(lVar8 + 0x5e0));
      }
      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s channel in reset\n",&DAT_001044f7,"glink_pkt_poll"
                     ,*(undefined8 *)(lVar8 + 0x5e0));
      uVar3 = 0x12;
    }
    else {
      ipc_log_string(glink_pkt_ilctxt,"[%s]: Wait for pkt on channel:%s\n","glink_pkt_poll",
                     *(undefined8 *)(lVar8 + 0x5e0));
      if (((param_2 != (undefined8 *)0x0) && (lVar8 + 0x4b0 != 0)) &&
         (pcVar7 = (code *)*param_2, pcVar7 != (code *)0x0)) {
        if (*(int *)(pcVar7 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101c6c);
          (*pcVar7)();
        }
        (*pcVar7)(param_1,lVar8 + 0x4b0,param_2);
        DataMemoryBarrier(2,3);
      }
      lVar1 = lVar8 + 0x418;
      mutex_lock(lVar1);
      uVar4 = completion_done(lVar8 + 0x448);
      if (((uVar4 & 1) == 0) || (*(long *)(lVar8 + 0x470) == 0)) {
        iVar2 = ___ratelimit(glink_pkt_poll__rs_45,"glink_pkt_poll");
        if (iVar2 != 0) {
          _printk("%s[%s]: %s channel reset after wait\n",&DAT_001043e9,"glink_pkt_poll",
                  *(undefined8 *)(lVar8 + 0x5e0));
        }
        ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s channel reset after wait\n",&DAT_001044f7,
                       "glink_pkt_poll",*(undefined8 *)(lVar8 + 0x5e0));
        mutex_unlock(lVar1);
        uVar3 = 0x10;
      }
      else {
        uVar5 = _raw_spin_lock_irqsave(lVar8 + 0x47c);
        if ((*(long *)(lVar8 + 0x480) != lVar8 + 0x480) ||
           (uVar6 = 0, *(long *)(lVar8 + 0x628) != 0)) {
          uVar6 = 0x41;
        }
        if (*(int *)(lVar8 + 0x4c8) != 0) {
          uVar6 = uVar6 | 2;
        }
        _raw_spin_unlock_irqrestore(lVar8 + 0x47c,uVar5);
        uVar3 = rpmsg_poll(*(undefined8 *)(*(long *)(lVar8 + 0x470) + 0x3c8),param_1,param_2);
        uVar3 = uVar3 | uVar6;
        mutex_unlock(lVar1);
        ipc_log_string(glink_pkt_ilctxt,"[%s]: Exit channel:%s\n","glink_pkt_poll",
                       *(undefined8 *)(lVar8 + 0x5e0));
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// glink_pkt_ioctl @ 00101e18 size=1832
// signature: undefined glink_pkt_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void glink_pkt_ioctl(long param_1,int param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  size_t __n;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  long lVar9;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0xd8);
  local_58 = 0;
  uStack_50 = 0;
  if ((lVar9 == 0) || (*(int *)(lVar9 + 0x468) == 1)) {
    iVar3 = ___ratelimit(glink_pkt_ioctl__rs,"glink_pkt_ioctl");
    if (iVar3 != 0) {
      _printk("%s[%s]: invalid device handle\n",&DAT_001043e9,"glink_pkt_ioctl");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: invalid device handle\n",&DAT_001044f7,
                   "glink_pkt_ioctl");
    lVar9 = -0x16;
    goto LAB_00102468;
  }
  lVar1 = lVar9 + 0x418;
  iVar3 = mutex_lock_interruptible(lVar1);
  if (iVar3 != 0) {
    lVar9 = -0x200;
    goto LAB_00102468;
  }
  uVar4 = completion_done(lVar9 + 0x448);
  if ((uVar4 & 1) == 0) {
    iVar3 = ___ratelimit(glink_pkt_ioctl__rs_48,"glink_pkt_ioctl");
    if (iVar3 != 0) {
      _printk("%s[%s]: %s channel in reset\n",&DAT_001043e9,"glink_pkt_ioctl",
              *(undefined8 *)(lVar9 + 0x5e0));
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s channel in reset\n",&DAT_001044f7,"glink_pkt_ioctl",
                   *(undefined8 *)(lVar9 + 0x5e0));
    mutex_unlock(lVar1);
    lVar9 = -0x66;
    goto LAB_00102468;
  }
  uVar8 = (uint)_cpu_hwcaps;
  if (param_2 < 0x5416) {
    if (param_2 == -0x3fef3cff) {
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar4 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar4 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar4 < 0x7ffffffff1) {
        if ((uVar8 >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7[1];
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        __n = __arch_copy_from_user(&local_58,param_3 & 0xff7fffffffffffff,0x10);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (__n == 0) {
          iVar3 = glink_pkt_zerocopy_receive(lVar9,&local_58);
          if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
             (uVar4 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
            uVar4 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (0x7ffffffff0 < uVar4) goto LAB_00102208;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            uVar2 = ttbr1_el1;
            ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7[1];
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          lVar9 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_58,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            uVar2 = ttbr1_el1;
            ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (lVar9 != 0) {
            iVar3 = -0xe;
          }
          goto LAB_0010245c;
        }
      }
      else {
LAB_001024bc:
        __n = 0x10;
      }
LAB_001024c0:
      memset((void *)((long)&local_48 - __n),0,__n);
      iVar3 = -0xe;
    }
    else if (param_2 == -0x3fef3cfe) {
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar4 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar4 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (0x7ffffffff0 < uVar4) goto LAB_001024bc;
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      __n = __arch_copy_from_user(puVar7,&local_58,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (__n != 0) goto LAB_001024c0;
      iVar3 = glink_pkt_zerocopy_done(lVar9,&local_58);
    }
    else {
      if (param_2 != 0x5415) goto LAB_00102210;
      uVar5 = _raw_spin_lock_irqsave(lVar9 + 0x47c);
      *(undefined4 *)(lVar9 + 0x4c8) = 0;
      _raw_spin_unlock_irqrestore(lVar9 + 0x47c,uVar5);
      iVar3 = qcom_glink_get_signals(*(undefined8 *)(*(long *)(lVar9 + 0x470) + 0x3c8));
      if (-1 < iVar3) {
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar4 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar4 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (0x7ffffffffc < uVar4) goto LAB_00102208;
        uaccess_ttbr0_enable();
        *(int *)(param_3 & 0xff7fffffffffffff) = iVar3;
        uaccess_ttbr0_disable();
        iVar3 = 0;
      }
    }
  }
  else if (param_2 - 0x5416U < 3) {
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar4 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar4 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar4 < 0x7ffffffffd) {
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7[1];
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      uVar6 = *(uint *)(param_3 & 0xff7fffffffffffff);
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (param_2 == 0x5418) {
        uVar8 = ~uVar6;
      }
      else {
        uVar8 = uVar6;
        if (param_2 != 0x5417) {
          if (param_2 == 0x5416) {
            uVar8 = 0;
            goto LAB_00102414;
          }
          uVar8 = 0;
        }
        uVar6 = 0;
      }
LAB_00102414:
      ipc_log_string(glink_pkt_ilctxt,"[%s]: set[0x%x] clear[0x%x]\n","glink_pkt_tiocmset",
                     uVar6 & 0xc6,uVar8 & 0xc6);
      iVar3 = qcom_glink_set_signals
                        (*(undefined8 *)(*(long *)(lVar9 + 0x470) + 0x3c8),uVar6 & 0xc6,uVar8 & 0xc6
                        );
    }
    else {
LAB_00102208:
      iVar3 = -0xe;
    }
  }
  else if (param_2 == 0x4004c300) {
    iVar3 = 0;
  }
  else {
LAB_00102210:
    iVar3 = ___ratelimit(glink_pkt_ioctl__rs_49,"glink_pkt_ioctl");
    if (iVar3 != 0) {
      _printk("%s[%s]: unrecognized ioctl command 0x%x\n",&DAT_001043e9,"glink_pkt_ioctl",param_2);
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: unrecognized ioctl command 0x%x\n",&DAT_001044f7,
                   "glink_pkt_ioctl",param_2);
    iVar3 = -0x203;
  }
LAB_0010245c:
  mutex_unlock(lVar1);
  lVar9 = (long)iVar3;
LAB_00102468:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar9);
  }
  return;
}



//------------------------------------------------------------
// glink_pkt_mmap @ 001025a4 size=184
// signature: undefined glink_pkt_mmap(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_pkt_mmap(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  
  uVar3 = *(ulong *)(param_2 + 0x20);
  if ((uVar3 & 6) == 0) {
    lVar4 = *(long *)(param_2 + 0x10);
    iVar5 = *(int *)(lVar4 + 0xb0);
    if (*(int *)(param_2 + 0x28) != iVar5) {
      down_write(*(undefined8 *)(param_2 + 0x30));
      *(int *)(param_2 + 0x28) = iVar5;
      up_write(*(undefined8 *)(param_2 + 0x30));
      uVar3 = *(ulong *)(param_2 + 0x20);
      lVar4 = *(long *)(param_2 + 0x10);
      iVar5 = *(int *)(param_2 + 0x28);
    }
    uVar3 = uVar3 & 0xffffffffffffff9f;
    *(ulong *)(param_2 + 0x20) = uVar3;
    iVar1 = *(int *)(lVar4 + 0xb0);
    if (iVar5 != iVar1) {
      down_write(*(undefined8 *)(param_2 + 0x30));
      *(int *)(param_2 + 0x28) = iVar1;
      up_write(*(undefined8 *)(param_2 + 0x30));
      uVar3 = *(ulong *)(param_2 + 0x20);
    }
    uVar2 = 0;
    *(ulong *)(param_2 + 0x20) = uVar3 | 0x10000000;
    *(undefined1 **)(param_2 + 0x78) = glink_pkt_vm_ops;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



//------------------------------------------------------------
// glink_pkt_open @ 00102660 size=508
// signature: undefined glink_pkt_open(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_pkt_open(long param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0x290);
  iVar7 = __msecs_to_jiffies(*(int *)(lVar11 + 0x260) * 1000);
  puVar1 = (uint *)(lVar11 + 0xd8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = uVar3 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  lVar10 = lVar11 + -0x390;
  if (uVar3 == 0) {
    uVar9 = 2;
  }
  else {
    if (-1 < (int)(uVar3 + 1 | uVar3)) goto LAB_001026c0;
    uVar9 = 1;
  }
  refcount_warn_saturate(puVar1,uVar9);
LAB_001026c0:
  get_device(lVar10);
  lVar6 = sp_el0;
  lVar2 = lVar6 + 0x848;
  ipc_log_string(glink_pkt_ilctxt,"[%s]: begin for %s by %s:%d ref_cnt[%d]\n","glink_pkt_open",
                 *(undefined8 *)(lVar11 + 0x250),lVar2,*(undefined4 *)(lVar6 + 0x630),
                 *(undefined4 *)(lVar11 + 0xd8));
  if (*(char *)(lVar11 + 0x13d) != '\0') {
    mutex_lock(lVar11 + 0x140);
    if ((*(char *)(lVar11 + 0x240) == '\0') &&
       (iVar8 = __register_rpmsg_driver(lVar11 + 0x170,&__this_module), iVar8 == 0)) {
      *(undefined1 *)(lVar11 + 0x240) = 1;
    }
    mutex_unlock(lVar11 + 0x140);
  }
  iVar7 = wait_for_completion_interruptible_timeout(lVar11 + 0xb8,(long)iVar7);
  if (iVar7 < 1) {
    if (*(char *)(lVar11 + 0x13d) != '\0') {
      mutex_lock(lVar11 + 0x140);
      if (*(char *)(lVar11 + 0x240) != '\0') {
        unregister_rpmsg_driver(lVar11 + 0x170);
        *(undefined1 *)(lVar11 + 0x240) = 0;
      }
      mutex_unlock(lVar11 + 0x140);
    }
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar3 = *puVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = uVar3 - 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if ((int)uVar3 < 2) {
      refcount_warn_saturate(puVar1,4);
    }
    put_device(lVar10);
    ipc_log_string(glink_pkt_ilctxt,"[%s]: timeout for %s by %s:%d\n","glink_pkt_open",
                   *(undefined8 *)(lVar11 + 0x250),lVar2,*(undefined4 *)(lVar6 + 0x630));
    uVar9 = 0xffffff92;
  }
  else {
    *(long *)(param_2 + 0xd8) = lVar10;
    ipc_log_string(glink_pkt_ilctxt,"[%s]: end for %s by %s:%d ref_cnt[%d]\n","glink_pkt_open",
                   *(undefined8 *)(lVar11 + 0x250),lVar2,*(undefined4 *)(lVar6 + 0x630),
                   *(undefined4 *)(lVar11 + 0xd8));
    uVar9 = 0;
  }
  return uVar9;
}



//------------------------------------------------------------
// glink_pkt_release @ 00102880 size=288
// signature: undefined glink_pkt_release(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_pkt_release(long param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  int *piVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x290);
  lVar4 = sp_el0;
  piVar6 = (int *)(lVar7 + 0xd8);
  ipc_log_string(glink_pkt_ilctxt,"[%s]: for %s by %s:%d ref_cnt[%d]\n","glink_pkt_release",
                 *(undefined8 *)(lVar7 + 0x250),lVar4 + 0x848,*(undefined4 *)(lVar4 + 0x630),*piVar6
                );
  Hint_Prefetch(piVar6,2,0,1);
  do {
    iVar1 = *piVar6;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar6,0x10);
    if (bVar3) {
      *piVar6 = iVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (iVar1 < 2) {
    refcount_warn_saturate(piVar6,4);
  }
  if (*piVar6 == 1) {
    glink_pkt_clear_queues(lVar7 + -0x390);
    uVar5 = _raw_spin_lock_irqsave(lVar7 + 0xec);
    *(undefined4 *)(lVar7 + 0x138) = 0;
    __wake_up(lVar7 + 0x120,1,1,0);
    _raw_spin_unlock_irqrestore(lVar7 + 0xec,uVar5);
    if (*(char *)(lVar7 + 0x13d) != '\0') {
      mutex_lock(lVar7 + 0x140);
      if (*(char *)(lVar7 + 0x240) != '\0') {
        unregister_rpmsg_driver(lVar7 + 0x170);
        *(undefined1 *)(lVar7 + 0x240) = 0;
      }
      mutex_unlock(lVar7 + 0x140);
    }
  }
  put_device(lVar7 + -0x390);
  return 0;
}



//------------------------------------------------------------
// glink_pkt_kfree_skb @ 001029a8 size=160
// signature: undefined glink_pkt_kfree_skb(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

void glink_pkt_kfree_skb(long param_1,long param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x478) != '\0') {
    ipc_log_string(glink_pkt_ilctxt,"[%s]: channel:%s\n","glink_pkt_kfree_skb",
                   *(undefined8 *)(param_1 + 0x5e0));
    iVar1 = qcom_glink_rx_done(*(undefined8 *)(*(long *)(param_1 + 0x470) + 0x3c8),
                               *(undefined8 *)(param_2 + 0xe0));
    if (iVar1 < 0) {
      ipc_log_string(glink_pkt_ilctxt,"[%s]: Failed channel:%s ret:%d\n","glink_pkt_kfree_skb",
                     *(undefined8 *)(param_1 + 0x5e0),iVar1);
    }
    *(undefined8 *)(param_2 + 0xe0) = *(undefined8 *)(param_2 + 0xd8);
  }
  kfree_skb_reason(param_2,1);
  return;
}



//------------------------------------------------------------
// uaccess_ttbr0_enable @ 00102a48 size=72
// signature: undefined uaccess_ttbr0_enable(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_enable(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// FUN_00102a94 @ 00102a94 size=16
// signature: undefined FUN_00102a94(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00102a94(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// uaccess_ttbr0_disable @ 00102aac size=64
// signature: undefined uaccess_ttbr0_disable(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_disable(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// FUN_00102af0 @ 00102af0 size=16
// signature: undefined FUN_00102af0(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00102af0(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// glink_pkt_zerocopy_receive @ 00102b08 size=1032
// signature: undefined glink_pkt_zerocopy_receive(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

int glink_pkt_zerocopy_receive(long param_1,ulong *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  int iVar10;
  uint uVar11;
  void *__src;
  ulong uVar12;
  void *local_88;
  long local_70;
  
  uVar9 = *param_2;
  if (((uVar9 & 0xfff) != 0) || (*(char *)(param_1 + 0x478) == '\0')) {
    return -0x16;
  }
  lVar1 = param_1 + 0x47c;
  param_2[1] = 0;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  for (plVar8 = *(long **)(param_1 + 0x498);
      (plVar8 != (long *)(param_1 + 0x498) && (plVar8 != (long *)0x0)); plVar8 = (long *)*plVar8) {
    if (((ulong)plVar8[7] <= uVar9) && (uVar9 <= (ulong)(plVar8[8] + plVar8[7]))) {
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      return -0x16;
    }
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  lVar3 = sp_el0;
  down_read(*(long *)(lVar3 + 0x5a0) + 0x60);
  lVar6 = mtree_load(*(undefined8 *)(lVar3 + 0x5a0),uVar9);
  if ((lVar6 == 0) || (*(undefined1 **)(lVar6 + 0x78) != glink_pkt_vm_ops)) {
    iVar4 = -0x16;
    goto LAB_00102bf0;
  }
  iVar4 = *(int *)(lVar6 + 8);
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar7 = skb_dequeue(param_1 + 0x480);
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  if (lVar7 == 0) {
    iVar4 = -5;
    goto LAB_00102bf0;
  }
  __src = *(void **)(lVar7 + 0xe0);
  uVar2 = *(uint *)(lVar7 + 0x70);
  uVar12 = (ulong)__src & 0xfff;
  if (uVar12 == 0) {
    local_70 = 0;
    uVar11 = uVar2;
LAB_00102cd8:
    uVar12 = (ulong)uVar2 + (long)__src;
    if ((uVar12 & 0xfff) == 0) {
      local_88 = (void *)0x0;
LAB_00102d18:
      if ((uint)(iVar4 - (int)uVar9) < uVar11) {
        iVar4 = -0x1c;
      }
      else if ((uVar11 & 0xfff) == 0) {
        zap_vma_ptes(lVar6,uVar9);
        if (local_70 == 0) {
LAB_00102dd0:
          iVar10 = ((uVar11 >> 0xc) - (uint)(local_70 != 0)) - (uint)(local_88 != (void *)0x0);
          if (iVar10 != 0) {
            uVar12 = (long)__src + 0xfffU & 0xfffffffffffff000;
            do {
              uVar5 = glink_pkt_vaddr_to_page(uVar12);
              Hint_Prefetch(uVar5,2,0,0);
              iVar4 = vm_insert_page(lVar6,uVar9,uVar5);
              if (iVar4 != 0) goto LAB_00102eac;
              uVar9 = uVar9 + 0x1000;
              uVar12 = uVar12 + 0x1000;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          if ((local_88 == (void *)0x0) ||
             (iVar4 = vm_insert_page(lVar6,uVar9,
                                     ((((long)local_88 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                     -0x200000000), iVar4 == 0)) {
            *(uint *)(param_2 + 1) = uVar2;
            uVar5 = _raw_spin_lock_irqsave(lVar1);
            *(long *)(lVar7 + 0x28) = local_70;
            *(void **)(lVar7 + 0x30) = local_88;
            *(ulong *)(lVar7 + 0x38) = *param_2;
            *(ulong *)(lVar7 + 0x40) = (ulong)uVar11;
            skb_queue_tail(param_1 + 0x498,lVar7);
            _raw_spin_unlock_irqrestore(lVar1,uVar5);
            mmap_read_unlock(*(undefined8 *)(lVar3 + 0x5a0));
            return 0;
          }
        }
        else {
          iVar4 = vm_insert_page(lVar6,uVar9,
                                 (((local_70 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                 -0x200000000);
          if (iVar4 == 0) {
            uVar9 = uVar9 + 0x1000;
            goto LAB_00102dd0;
          }
        }
LAB_00102eac:
        zap_vma_ptes(lVar6,*param_2,(ulong)uVar11);
      }
      else {
        iVar4 = -0x16;
      }
      if (local_88 != (void *)0x0) {
        free_pages(local_88,0);
      }
    }
    else {
      local_88 = (void *)get_zeroed_page(0xcc0);
      if (local_88 != (void *)0x0) {
        memcpy(local_88,(void *)(uVar12 & 0xfffffffffffff000),uVar12 & 0xfff);
        uVar11 = (uVar11 - ((uint)uVar12 & 0xfff)) + 0x1000;
        goto LAB_00102d18;
      }
      iVar4 = -0xc;
    }
    if (local_70 != 0) {
      free_pages(local_70,0);
    }
  }
  else {
    local_70 = get_zeroed_page(0xcc0);
    if (local_70 != 0) {
      local_88._0_4_ = (uint)__src & 0xfff;
      memcpy((void *)(local_70 + uVar12),__src,0x1000 - uVar12);
      *(uint *)((long)param_2 + 0xc) = (uint)local_88;
      uVar11 = uVar2 + ((uint)__src | 0xfffff000) + 0x1000;
      goto LAB_00102cd8;
    }
    iVar4 = -0xc;
  }
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  skb_queue_head(param_1 + 0x480,lVar7);
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
LAB_00102bf0:
  up_read(*(long *)(lVar3 + 0x5a0) + 0x60);
  return iVar4;
}



//------------------------------------------------------------
// glink_pkt_zerocopy_done @ 00102f44 size=504
// signature: undefined glink_pkt_zerocopy_done(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

undefined8 glink_pkt_zerocopy_done(long param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  ulong uVar9;
  
  uVar9 = *param_2;
  if (((uVar9 & 0xfff) == 0) && (*(char *)(param_1 + 0x478) != '\0')) {
    lVar2 = sp_el0;
    down_read(*(long *)(lVar2 + 0x5a0) + 0x60);
    lVar4 = mtree_load(*(undefined8 *)(lVar2 + 0x5a0),uVar9);
    if ((lVar4 == 0) || (*(undefined1 **)(lVar4 + 0x78) != glink_pkt_vm_ops)) {
      up_read(*(long *)(lVar2 + 0x5a0) + 0x60);
    }
    else {
      lVar1 = param_1 + 0x47c;
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      plVar6 = *(long **)(param_1 + 0x498);
      if ((plVar6 == (long *)(param_1 + 0x498)) || (plVar6 == (long *)0x0)) {
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        plVar8 = (long *)0x0;
        plVar6 = (long *)0x0;
      }
      else {
        while (plVar7 = plVar6, uVar9 != plVar7[7]) {
          plVar6 = (long *)*plVar7;
          plVar8 = (long *)0x0;
          if ((plVar6 == (long *)(param_1 + 0x498)) || (plVar6 == (long *)0x0)) goto LAB_00103060;
        }
        skb_unlink(plVar7);
        plVar8 = plVar7;
LAB_00103060:
        plVar6 = plVar7 + 5;
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        if ((plVar6 != (long *)0x0) && (plVar7[7] == uVar9)) {
          zap_vma_ptes(lVar4,uVar9,plVar7[8]);
        }
      }
      up_read(*(long *)(lVar2 + 0x5a0) + 0x60);
      if (plVar8 != (long *)0x0) {
        if (plVar6[1] != 0) {
          free_pages(plVar6[1],0);
        }
        if (*plVar6 != 0) {
          free_pages(*plVar6,0);
        }
        if (*(char *)(param_1 + 0x478) != '\0') {
          ipc_log_string(glink_pkt_ilctxt,"[%s]: channel:%s\n","glink_pkt_kfree_skb",
                         *(undefined8 *)(param_1 + 0x5e0));
          iVar3 = qcom_glink_rx_done(*(undefined8 *)(*(long *)(param_1 + 0x470) + 0x3c8),
                                     plVar8[0x1c]);
          if (iVar3 < 0) {
            ipc_log_string(glink_pkt_ilctxt,"[%s]: Failed channel:%s ret:%d\n","glink_pkt_kfree_skb"
                           ,*(undefined8 *)(param_1 + 0x5e0),iVar3);
          }
          plVar8[0x1c] = plVar8[0x1b];
        }
        kfree_skb_reason(plVar8,1);
        return 0;
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// glink_pkt_vaddr_to_page @ 00103180 size=80
// signature: undefined glink_pkt_vaddr_to_page(void)
// callers: [glink_pkt_zerocopy_receive]
//------------------------------------------------------------

long glink_pkt_vaddr_to_page(long param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = is_vmalloc_addr();
  if ((uVar1 & 1) == 0) {
    lVar2 = (((param_1 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
  }
  else {
    lVar2 = vmalloc_to_page(param_1);
  }
  return lVar2;
}



//------------------------------------------------------------
// mmap_read_unlock @ 001031d0 size=44
// signature: undefined mmap_read_unlock(void)
// callers: [glink_pkt_zerocopy_receive]
//------------------------------------------------------------

void mmap_read_unlock(long param_1)

{
  up_read(param_1 + 0x60);
  return;
}



//------------------------------------------------------------
// glink_pkt_clear_queues @ 00103210 size=576
// signature: undefined glink_pkt_clear_queues(void)
// callers: [glink_pkt_release, glink_pkt_rpdev_remove]
//------------------------------------------------------------

void glink_pkt_clear_queues(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  mutex_lock(param_1 + 0x5f8);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x47c);
  lVar3 = *(long *)(param_1 + 0x628);
  if (lVar3 != 0) {
    if (*(char *)(param_1 + 0x478) != '\0') {
      ipc_log_string(glink_pkt_ilctxt,"[%s]: channel:%s\n","glink_pkt_kfree_skb",
                     *(undefined8 *)(param_1 + 0x5e0));
      iVar1 = qcom_glink_rx_done(*(undefined8 *)(*(long *)(param_1 + 0x470) + 0x3c8),
                                 *(undefined8 *)(lVar3 + 0xe0));
      if (iVar1 < 0) {
        ipc_log_string(glink_pkt_ilctxt,"[%s]: Failed channel:%s ret:%d\n","glink_pkt_kfree_skb",
                       *(undefined8 *)(param_1 + 0x5e0),iVar1);
      }
      *(undefined8 *)(lVar3 + 0xe0) = *(undefined8 *)(lVar3 + 0xd8);
    }
    kfree_skb_reason(lVar3,1);
    *(undefined8 *)(param_1 + 0x630) = 0;
    *(undefined8 *)(param_1 + 0x638) = 0;
    *(undefined8 *)(param_1 + 0x628) = 0;
  }
  lVar3 = skb_dequeue(param_1 + 0x480);
  if (lVar3 != 0) {
    do {
      if (*(char *)(param_1 + 0x478) != '\0') {
        ipc_log_string(glink_pkt_ilctxt,"[%s]: channel:%s\n","glink_pkt_kfree_skb",
                       *(undefined8 *)(param_1 + 0x5e0));
        iVar1 = qcom_glink_rx_done(*(undefined8 *)(*(long *)(param_1 + 0x470) + 0x3c8),
                                   *(undefined8 *)(lVar3 + 0xe0));
        if (iVar1 < 0) {
          ipc_log_string(glink_pkt_ilctxt,"[%s]: Failed channel:%s ret:%d\n","glink_pkt_kfree_skb",
                         *(undefined8 *)(param_1 + 0x5e0),iVar1);
        }
        *(undefined8 *)(lVar3 + 0xe0) = *(undefined8 *)(lVar3 + 0xd8);
      }
      kfree_skb_reason(lVar3,1);
      lVar3 = skb_dequeue(param_1 + 0x480);
    } while (lVar3 != 0);
  }
  lVar3 = skb_dequeue(param_1 + 0x498);
  if (lVar3 != 0) {
    do {
      if (*(char *)(param_1 + 0x478) != '\0') {
        ipc_log_string(glink_pkt_ilctxt,"[%s]: channel:%s\n","glink_pkt_kfree_skb",
                       *(undefined8 *)(param_1 + 0x5e0));
        iVar1 = qcom_glink_rx_done(*(undefined8 *)(*(long *)(param_1 + 0x470) + 0x3c8),
                                   *(undefined8 *)(lVar3 + 0xe0));
        if (iVar1 < 0) {
          ipc_log_string(glink_pkt_ilctxt,"[%s]: Failed channel:%s ret:%d\n","glink_pkt_kfree_skb",
                         *(undefined8 *)(param_1 + 0x5e0),iVar1);
        }
        *(undefined8 *)(lVar3 + 0xe0) = *(undefined8 *)(lVar3 + 0xd8);
      }
      kfree_skb_reason(lVar3,1);
      lVar3 = skb_dequeue(param_1 + 0x498);
    } while (lVar3 != 0);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x47c,uVar2);
  mutex_unlock(param_1 + 0x5f8);
  return;
}



//------------------------------------------------------------
// open_timeout_show @ 00103454 size=100
// signature: undefined open_timeout_show(void)
// callers: []
//------------------------------------------------------------

long open_timeout_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  mutex_lock(param_1 + 0x418);
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010446d,*(undefined4 *)(param_1 + 0x5f0));
  mutex_unlock(param_1 + 0x418);
  return (long)iVar1;
}



//------------------------------------------------------------
// open_timeout_store @ 001034bc size=268
// signature: undefined open_timeout_store(void)
// callers: []
//------------------------------------------------------------

undefined8 open_timeout_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x418;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  mutex_lock(lVar1);
  iVar3 = kstrtoll(param_3,0,&local_40);
  if (iVar3 == 0) {
    *(int *)(param_1 + 0x5f0) = (int)local_40;
    mutex_unlock(lVar1);
  }
  else {
    mutex_unlock(lVar1);
    iVar3 = ___ratelimit(open_timeout_store__rs,"open_timeout_store");
    if (iVar3 != 0) {
      _printk("%s[%s]: unable to convert string to int for /dev/%s\n",&DAT_001043e9,
              "open_timeout_store",*(undefined8 *)(param_1 + 0x5d8));
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: unable to convert string to int for /dev/%s\n",
                   &DAT_001044f7,"open_timeout_store",*(undefined8 *)(param_1 + 0x5d8));
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// glink_pkt_rpdev_probe @ 001035cc size=124
// signature: undefined glink_pkt_rpdev_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_pkt_rpdev_probe(long param_1)

{
  byte bVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x88);
  mutex_lock(lVar2 + -0xe8);
  *(long *)(lVar2 + -0x90) = param_1;
  bVar1 = qcom_glink_rx_done_supported(*(undefined8 *)(param_1 + 0x3c8));
  *(byte *)(lVar2 + -0x88) = bVar1 & 1;
  qcom_glink_register_signals_cb(*(undefined8 *)(param_1 + 0x3c8),glink_pkt_rpdev_sigs);
  mutex_unlock(lVar2 + -0xe8);
  *(long *)(param_1 + 0x98) = lVar2 + -0x500;
  complete_all(lVar2 + -0xb8);
  return 0;
}



//------------------------------------------------------------
// glink_pkt_rpdev_remove @ 0010364c size=112
// signature: undefined glink_pkt_rpdev_remove(void)
// callers: []
//------------------------------------------------------------

void glink_pkt_rpdev_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x88);
  mutex_lock(lVar1 + -0xe8);
  glink_pkt_clear_queues(lVar1 + -0x500);
  *(undefined8 *)(lVar1 + -0x90) = 0;
  mutex_unlock(lVar1 + -0xe8);
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(lVar1 + -0xb8) = 0;
  __wake_up(lVar1 + -0x50,1,1,0);
  return;
}



//------------------------------------------------------------
// glink_pkt_rpdev_cb @ 001036c0 size=84
// signature: undefined glink_pkt_rpdev_cb(void)
// callers: []
//------------------------------------------------------------

void glink_pkt_rpdev_cb(long param_1)

{
  code *pcVar1;
  
  pcVar1 = glink_pkt_rpdev_copy_cb;
  if (*(char *)(*(long *)(param_1 + 0x98) + 0x478) != '\0') {
    pcVar1 = glink_pkt_rpdev_no_copy_cb;
  }
  if (*(int *)(pcVar1 + -4) != 0x505af011) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103704);
    (*pcVar1)();
  }
  (*pcVar1)();
  return;
}



//------------------------------------------------------------
// glink_pkt_rpdev_sigs @ 00103718 size=128
// signature: undefined glink_pkt_rpdev_sigs(void)
// callers: []
//------------------------------------------------------------

undefined8
glink_pkt_rpdev_sigs(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x88);
  ipc_log_string(glink_pkt_ilctxt,"[%s]: Received signal new:0x%x old:0x%x on channel:%s\n",
                 "glink_pkt_rpdev_sigs",param_4,param_3,*(undefined8 *)(lVar2 + 0xe0));
  uVar1 = _raw_spin_lock_irqsave(lVar2 + -0x84);
  *(undefined4 *)(lVar2 + -0x38) = 1;
  _raw_spin_unlock_irqrestore(lVar2 + -0x84,uVar1);
  __wake_up(lVar2 + -0x50,1,1,0);
  return 0;
}



//------------------------------------------------------------
// glink_pkt_rpdev_no_copy_cb @ 0010379c size=348
// signature: undefined glink_pkt_rpdev_no_copy_cb(void)
// callers: [glink_pkt_rpdev_cb]
//------------------------------------------------------------

undefined8 glink_pkt_rpdev_no_copy_cb(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  ipc_log_string(glink_pkt_ilctxt,"[%s]: Data received on:%s len:%d\n","glink_pkt_rpdev_no_copy_cb",
                 *(undefined8 *)(lVar4 + 0x5e0),param_3);
  lVar2 = __alloc_skb(0,0xa20,0,0xffffffff);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(glink_pkt_rpdev_no_copy_cb__rs,"glink_pkt_rpdev_no_copy_cb");
    if (iVar1 != 0) {
      _printk("%s[%s]: Failed to allocate skb\n",&DAT_001043e9,"glink_pkt_rpdev_no_copy_cb");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: Failed to allocate skb\n",&DAT_001044f7,
                   "glink_pkt_rpdev_no_copy_cb");
    uVar3 = 0xfffffff4;
  }
  else {
    *(undefined8 *)(lVar2 + 0xe0) = param_2;
    *(int *)(lVar2 + 0xd0) = (int)param_2 - *(int *)(lVar2 + 0xd8);
    *(int *)(lVar2 + 0x70) = *(int *)(lVar2 + 0x70) + param_3;
    uVar3 = _raw_spin_lock_irqsave(lVar4 + 0x47c);
    skb_queue_tail(lVar4 + 0x480,lVar2);
    _raw_spin_unlock_irqrestore(lVar4 + 0x47c,uVar3);
    uVar3 = 1;
    __wake_up(lVar4 + 0x4b0,1,1,0);
    ipc_log_string(glink_pkt_ilctxt,"[%s]: Data queued on:%s len:%d\n","glink_pkt_rpdev_no_copy_cb",
                   *(undefined8 *)(lVar4 + 0x5e0),param_3);
  }
  return uVar3;
}



//------------------------------------------------------------
// glink_pkt_rpdev_copy_cb @ 001038fc size=440
// signature: undefined glink_pkt_rpdev_copy_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_pkt_rpdev_copy_cb(long param_1,void *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  void *__dest;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
    iVar1 = ___ratelimit(glink_pkt_rpdev_copy_cb__rs,"glink_pkt_rpdev_copy_cb");
    if (iVar1 != 0) {
      _printk("%s[%s]: channel is in reset\n",&DAT_001043e9,"glink_pkt_rpdev_copy_cb");
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: channel is in reset\n",&DAT_001044f7,
                   "glink_pkt_rpdev_copy_cb");
    uVar3 = 0xffffff9a;
  }
  else {
    param_3 = param_3 & 0xffffffff;
    ipc_log_string(glink_pkt_ilctxt,"[%s]: Data received on:%s len:%d\n","glink_pkt_rpdev_copy_cb",
                   *(undefined8 *)(lVar4 + 0x5e0),param_3);
    lVar2 = __alloc_skb(param_3,0xa20,0,0xffffffff);
    if (lVar2 == 0) {
      iVar1 = ___ratelimit(glink_pkt_rpdev_copy_cb__rs_71,"glink_pkt_rpdev_copy_cb");
      if (iVar1 != 0) {
        _printk("%s[%s]: Failed to allocate skb\n",&DAT_001043e9,"glink_pkt_rpdev_copy_cb");
      }
      ipc_log_string(glink_pkt_ilctxt,"%s[%s]: Failed to allocate skb\n",&DAT_001044f7,
                     "glink_pkt_rpdev_copy_cb");
      uVar3 = 0xfffffff4;
    }
    else {
      __dest = (void *)skb_put(lVar2,param_3);
      memcpy(__dest,param_2,param_3);
      uVar3 = _raw_spin_lock_irqsave(lVar4 + 0x47c);
      skb_queue_tail(lVar4 + 0x480,lVar2);
      _raw_spin_unlock_irqrestore(lVar4 + 0x47c,uVar3);
      __wake_up(lVar4 + 0x4b0,1,1,0);
      ipc_log_string(glink_pkt_ilctxt,"[%s]: Data queued on:%s len:%d\n","glink_pkt_rpdev_copy_cb",
                     *(undefined8 *)(lVar4 + 0x5e0),param_3);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// init_module @ 00103ba8 size=204
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __platform_driver_register(&glink_pkt_driver,&__this_module);
  if (iVar1 == 0) {
    glink_pkt_ilctxt = ipc_log_context_create(0x20,"glink_pkt",0);
  }
  else {
    iVar2 = ___ratelimit(glink_pkt_init__rs,"glink_pkt_init");
    if (iVar2 != 0) {
      _printk("%s[%s]: %s: glink_pkt register failed %d\n",&DAT_001043e9,"glink_pkt_init",
              "glink_pkt_init",iVar1);
    }
    ipc_log_string(glink_pkt_ilctxt,"%s[%s]: %s: glink_pkt register failed %d\n",&DAT_001044f7,
                   "glink_pkt_init","glink_pkt_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00103c78 size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  class_destroy(glink_pkt_class);
  unregister_chrdev_region(glink_pkt_major >> 0x14,num_glink_pkt_devs);
  platform_driver_unregister(&glink_pkt_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00107000 size=1
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
// ___ratelimit @ 00107008 size=1
// signature: undefined ___ratelimit(void)
// callers: [open_timeout_store, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, init_module, glink_pkt_poll, glink_pkt_probe, glink_pkt_read, glink_pkt_write, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00107010 size=1
// signature: undefined ipc_log_string(void)
// callers: [glink_pkt_release, open_timeout_store, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, glink_pkt_zerocopy_done, init_module, glink_pkt_rpdev_sigs, glink_pkt_poll, glink_pkt_probe, glink_pkt_ioctl, glink_pkt_open, glink_pkt_release_device, glink_pkt_kfree_skb, glink_pkt_clear_queues, glink_pkt_read, glink_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00107018 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107020 size=1
// signature: undefined _printk(void)
// callers: [open_timeout_store, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, init_module, glink_pkt_poll, glink_pkt_probe, glink_pkt_read, glink_pkt_write, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00107028 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00107030 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00107038 size=1
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
// of_get_next_child @ 00107040 size=1
// signature: undefined of_get_next_child(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00107048 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00107050 size=1
// signature: undefined __class_create(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00107060 size=1
// signature: undefined kfree(void)
// callers: [glink_pkt_release_device, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00107068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00107070 size=1
// signature: undefined ida_alloc_range(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00107078 size=1
// signature: undefined of_property_read_string(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00107080 size=1
// signature: undefined of_find_property(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00107088 size=1
// signature: undefined __mutex_init(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00107090 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00107098 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 001070a0 size=1
// signature: undefined device_initialize(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001070a8 size=1
// signature: undefined cdev_init(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001070b0 size=1
// signature: undefined dev_set_name(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001070b8 size=1
// signature: undefined cdev_add(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 001070c0 size=1
// signature: undefined ida_free(void)
// callers: [glink_pkt_release_device, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 001070c8 size=1
// signature: undefined device_add(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001070d0 size=1
// signature: undefined put_device(void)
// callers: [glink_pkt_release, glink_pkt_open, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001070d8 size=1
// signature: undefined device_create_file(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001070e0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001070e8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001070f0 size=1
// signature: undefined strscpy(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 001070f8 size=1
// signature: undefined devm_kasprintf(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00107100 size=1
// signature: undefined mutex_lock(void)
// callers: [glink_pkt_release, open_timeout_store, glink_pkt_rpdev_remove, glink_pkt_open, glink_pkt_rpdev_probe, open_timeout_show, glink_pkt_clear_queues, glink_pkt_poll, glink_pkt_probe, glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107108 size=1
// signature: undefined mutex_unlock(void)
// callers: [glink_pkt_release, open_timeout_store, glink_pkt_rpdev_remove, glink_pkt_open, glink_pkt_rpdev_probe, open_timeout_show, glink_pkt_clear_queues, glink_pkt_poll, glink_pkt_probe, glink_pkt_read, glink_pkt_write, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 00107110 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [glink_pkt_open, glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00107118 size=1
// signature: undefined fortify_panic(void)
// callers: [glink_pkt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00107120 size=1
// signature: undefined cdev_del(void)
// callers: [glink_pkt_release_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00107128 size=1
// signature: undefined scnprintf(void)
// callers: [open_timeout_show, name_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock_interruptible @ 00107130 size=1
// signature: undefined mutex_lock_interruptible(void)
// callers: [glink_pkt_read, glink_pkt_write, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 00107138 size=1
// signature: undefined completion_done(void)
// callers: [glink_pkt_poll, glink_pkt_read, glink_pkt_write, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 00107140 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 00107148 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue @ 00107150 size=1
// signature: undefined skb_dequeue(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_clear_queues, glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00107158 size=1
// signature: undefined __check_object_size(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00107170 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [glink_pkt_read, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00107178 size=1
// signature: undefined init_wait_entry(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00107180 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00107188 size=1
// signature: undefined finish_wait(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00107190 size=1
// signature: undefined schedule(void)
// callers: [glink_pkt_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107198 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [open_timeout_store, glink_pkt_read, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmemdup_user @ 001071a8 size=1
// signature: undefined vmemdup_user(void)
// callers: [glink_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmemdup_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 001071b0 size=1
// signature: undefined rpmsg_send(void)
// callers: [glink_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_trysend @ 001071b8 size=1
// signature: undefined rpmsg_trysend(void)
// callers: [glink_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_trysend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 001071c0 size=1
// signature: undefined kvfree(void)
// callers: [glink_pkt_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001071c8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [glink_pkt_release, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done, glink_pkt_clear_queues, glink_pkt_rpdev_sigs, glink_pkt_poll, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001071d0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [glink_pkt_release, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done, glink_pkt_clear_queues, glink_pkt_rpdev_sigs, glink_pkt_poll, glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_poll @ 001071d8 size=1
// signature: undefined rpmsg_poll(void)
// callers: [glink_pkt_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_poll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_get_signals @ 001071e0 size=1
// signature: undefined qcom_glink_get_signals(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_get_signals(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001071e8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_set_signals @ 001071f0 size=1
// signature: undefined qcom_glink_set_signals(void)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_set_signals(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001071f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [glink_pkt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00107200 size=1
// signature: undefined down_write(void)
// callers: [glink_pkt_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 00107208 size=1
// signature: undefined up_write(void)
// callers: [glink_pkt_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00107210 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [glink_pkt_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 00107218 size=1
// signature: undefined get_device(void)
// callers: [glink_pkt_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible_timeout @ 00107220 size=1
// signature: undefined wait_for_completion_interruptible_timeout(void)
// callers: [glink_pkt_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 00107228 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [glink_pkt_release, glink_pkt_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00107230 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [glink_pkt_release, glink_pkt_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00107238 size=1
// signature: undefined __wake_up(void)
// callers: [glink_pkt_release, glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_remove, glink_pkt_rpdev_no_copy_cb, glink_pkt_rpdev_sigs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_rx_done @ 00107240 size=1
// signature: undefined qcom_glink_rx_done(void)
// callers: [glink_pkt_zerocopy_done, glink_pkt_kfree_skb, glink_pkt_clear_queues]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_rx_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 00107248 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [glink_pkt_zerocopy_done, glink_pkt_kfree_skb, glink_pkt_clear_queues]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 00107258 size=1
// signature: undefined down_read(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mtree_load @ 00107268 size=1
// signature: undefined mtree_load(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mtree_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 00107278 size=1
// signature: undefined up_read(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done, mmap_read_unlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_zeroed_page @ 00107280 size=1
// signature: undefined get_zeroed_page(void)
// callers: [glink_pkt_zerocopy_receive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_zeroed_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00107288 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [glink_pkt_rpdev_copy_cb, glink_pkt_zerocopy_receive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zap_vma_ptes @ 00107290 size=1
// signature: undefined zap_vma_ptes(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zap_vma_ptes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vm_insert_page @ 00107298 size=1
// signature: undefined vm_insert_page(void)
// callers: [glink_pkt_zerocopy_receive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vm_insert_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 001072a0 size=1
// signature: undefined skb_queue_tail(void)
// callers: [glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb, glink_pkt_zerocopy_receive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 001072a8 size=1
// signature: undefined free_pages(void)
// callers: [glink_pkt_zerocopy_receive, glink_pkt_zerocopy_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_head @ 001072b0 size=1
// signature: undefined skb_queue_head(void)
// callers: [glink_pkt_zerocopy_receive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_unlink @ 001072d0 size=1
// signature: undefined skb_unlink(void)
// callers: [glink_pkt_zerocopy_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_unlink(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 001072d8 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [glink_pkt_vaddr_to_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 001072e0 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [glink_pkt_vaddr_to_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 001072e8 size=1
// signature: undefined kstrtoll(void)
// callers: [open_timeout_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_rx_done_supported @ 001072f0 size=1
// signature: undefined qcom_glink_rx_done_supported(void)
// callers: [glink_pkt_rpdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_rx_done_supported(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_register_signals_cb @ 001072f8 size=1
// signature: undefined qcom_glink_register_signals_cb(void)
// callers: [glink_pkt_rpdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_register_signals_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00107300 size=1
// signature: undefined complete_all(void)
// callers: [glink_pkt_rpdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00107308 size=1
// signature: undefined __alloc_skb(void)
// callers: [glink_pkt_rpdev_copy_cb, glink_pkt_rpdev_no_copy_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00107310 size=1
// signature: undefined skb_put(void)
// callers: [glink_pkt_rpdev_copy_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



