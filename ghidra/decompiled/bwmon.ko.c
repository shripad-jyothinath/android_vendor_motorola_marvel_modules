// Decompiled by Ghidra 12.2
// Program: bwmon.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_bwmon_driver_probe @ 00100f3c size=2896
// signature: undefined qcom_bwmon_driver_probe(void)
// callers: []
//------------------------------------------------------------

void qcom_bwmon_driver_probe(long param_1)

{
  int *piVar1;
  long *plVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *puVar5;
  ulong uVar6;
  bool bVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined4 *puVar13;
  ulong uVar14;
  char *pcVar15;
  uint uVar16;
  code *pcVar17;
  code *pcVar18;
  long lVar19;
  ulong uVar20;
  uint local_d0;
  uint local_cc;
  undefined8 local_c8;
  int local_c0;
  undefined4 local_bc;
  ulong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  plVar2 = (long *)(param_1 + 0x10);
  local_68 = *(long *)(lVar10 + 0x638);
  local_c0 = 0;
  local_c8 = 0;
  local_d0 = 3;
  local_cc = 3;
  plVar9 = (long *)devm_kmalloc(plVar2,0x128,0xdc0);
  if (plVar9 == (long *)0x0) {
    iVar8 = -0xc;
    goto LAB_00101a2c;
  }
  plVar9[4] = (long)plVar2;
  plVar9[0xc] = (long)plVar2;
  lVar10 = of_device_get_match_data(plVar2);
  plVar9[3] = lVar10;
  if (lVar10 == 0) {
    _dev_err(plVar2,"Unknown device type!\n");
    iVar8 = -0x13;
    goto LAB_00101a2c;
  }
  plVar11 = (long *)platform_get_resource_byname(param_1,0x200,&DAT_00105ec4);
  if (plVar11 == (long *)0x0) {
    pcVar15 = "base not found!\n";
    goto LAB_001018d8;
  }
  lVar10 = devm_ioremap(plVar2,*plVar11,(plVar11[1] - *plVar11) + 1);
  *plVar9 = lVar10;
  if (lVar10 == 0) {
    pcVar15 = "Unable map base!\n";
LAB_00101884:
    _dev_err(plVar2,pcVar15);
    iVar8 = -0xc;
    goto LAB_00101a2c;
  }
  if (*(char *)(plVar9[3] + 4) != '\0') {
    plVar11 = (long *)platform_get_resource_byname(param_1,0x200,"global_base");
    if (plVar11 == (long *)0x0) {
      pcVar15 = "global_base not found!\n";
      goto LAB_001018d8;
    }
    lVar10 = devm_ioremap(plVar2,*plVar11,(plVar11[1] - *plVar11) + 1);
    plVar9[1] = lVar10;
    if (lVar10 == 0) {
      pcVar15 = "Unable map global_base!\n";
      goto LAB_00101884;
    }
    local_c0 = of_property_read_variable_u32_array
                         (*(undefined8 *)(param_1 + 0x2f8),"qcom,mport",(long)&local_c8 + 4,1,0);
    if (-1 < local_c0) {
      local_c0 = 0;
      *(undefined4 *)(plVar9 + 2) = local_c8._4_4_;
      goto LAB_0010105c;
    }
    pcVar15 = "mport not found! (%d)\n";
    goto LAB_00101a24;
  }
LAB_0010105c:
  iVar8 = platform_get_irq(param_1,0);
  *(int *)((long)plVar9 + 0x14) = iVar8;
  if (iVar8 < 0) {
    _dev_err(plVar2,"Unable to get IRQ number\n");
    iVar8 = *(int *)((long)plVar9 + 0x14);
    goto LAB_00101a2c;
  }
  if (*(char *)(plVar9[3] + 3) == '\0') {
LAB_001010a8:
    iVar8 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,count-unit",&local_c8,1,0);
    if (iVar8 < 0) {
      uVar16 = 0x100000;
      local_c8 = CONCAT44(local_c8._4_4_,0x100000);
    }
    else {
      uVar16 = (uint)local_c8;
    }
    uVar4 = 0x40 - (int)LZCOUNT((ulong)uVar16 - 1);
    if (uVar16 < 2) {
      uVar4 = 0;
    }
    *(char *)(plVar9 + 0x23) = (char)uVar4;
    *(uint *)((long)plVar9 + 0x11c) = 0xffffffff >> (ulong)(uVar4 & 0x1f);
    iVar8 = *(int *)(plVar9[3] + 8);
    if (iVar8 == 0) {
      plVar9[5] = (long)start_bw_hwmon;
      plVar9[6] = (long)stop_bw_hwmon;
      plVar9[9] = (long)get_bytes_and_clear;
      plVar9[7] = (long)set_thres;
    }
    else {
      if (iVar8 == 1) {
        plVar9[5] = (long)start_bw_hwmon2;
        plVar9[6] = (long)stop_bw_hwmon2;
        pcVar17 = get_bytes_and_clear2;
        pcVar18 = set_hw_events;
      }
      else {
        if (iVar8 != 2) goto LAB_001011a8;
        plVar9[5] = (long)start_bw_hwmon3;
        plVar9[6] = (long)stop_bw_hwmon3;
        pcVar17 = get_bytes_and_clear3;
        pcVar18 = set_hw_events3;
      }
      plVar9[8] = (long)pcVar18;
      plVar9[9] = (long)pcVar17;
    }
LAB_001011a8:
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,byte-mid-match",(long)plVar9 + 0x124,1,0);
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,byte-mid-mask",plVar9 + 0x24,1,0);
    if (*(char *)(plVar9[3] + 2) != '\0') {
      plVar9[10] = (long)mon_set_throttle_adj;
      plVar9[0xb] = (long)mon_get_throttle_adj;
    }
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    iVar8 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,target-dev",0,0,0,&local_b8);
    uVar14 = local_b8;
    if ((iVar8 != 0) || (local_b8 == 0)) {
      pcVar15 = "Unable to find target-dev for bwmon device\n";
      goto LAB_001018d8;
    }
    iVar8 = of_property_read_variable_u32_array(local_b8,"qcom,dcvs-hw-type",&local_cc,1,0);
    local_c0 = iVar8;
    if (-1 < iVar8) {
      local_c0 = 0;
    }
    if ((iVar8 < 0) || (5 < local_cc)) {
      pcVar15 = "invalid dcvs_hw=%d, ret=%d\n";
    }
    else {
      *(uint *)(plVar9 + 0xd) = local_cc;
      local_c0 = of_property_read_variable_u32_array(uVar14,"qcom,bus-width",plVar9 + 0xe,1,0);
      if ((-1 < local_c0) && (local_c0 = 0, (int)plVar9[0xe] != 0)) {
        uVar12 = *(undefined8 *)(param_1 + 0x2f8);
        *(undefined4 *)((long)plVar9 + 0x6c) = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        iVar8 = __of_parse_phandle_with_args(uVar12,"qcom,second-vote",0,0,0,&local_b8);
        uVar14 = local_b8;
        if ((iVar8 == 0) && (local_b8 != 0)) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_b8 = 0;
          uStack_b0 = 0;
          iVar8 = __of_parse_phandle_with_args(uVar14,"qcom,target-dev",0,0,0,&local_b8);
          uVar6 = local_b8;
          if ((iVar8 == 0) && (local_b8 != 0)) {
            iVar8 = of_property_read_variable_u32_array(local_b8,"qcom,dcvs-hw-type",&local_d0,1,0);
            local_c0 = iVar8;
            if (-1 < iVar8) {
              local_c0 = 0;
            }
            if ((iVar8 < 0) || (5 < local_d0)) {
              pcVar15 = "invalid sec dcvs_hw=%d, ret=%d\n";
              goto LAB_00101900;
            }
            *(uint *)((long)plVar9 + 0x74) = local_d0;
            lVar10 = of_find_property(uVar14,"qcom,secondary-map",&local_c0);
            if (lVar10 == 0) {
              puVar13 = (undefined4 *)plVar9[0x11];
joined_r0x00101480:
              if (puVar13 == (undefined4 *)0x0) {
                iVar8 = of_property_read_variable_u32_array(uVar6,"qcom,bus-width",plVar9 + 0xf,1,0)
                ;
                local_c0 = iVar8;
                if (-1 < iVar8) {
                  local_c0 = 0;
                }
                if ((iVar8 < 0) || ((int)plVar9[0xf] == 0)) {
                  pcVar15 = "invalid sec hw width=%d, ret=%d\n";
                  goto LAB_00101900;
                }
              }
LAB_001014d8:
              *(undefined1 *)((long)plVar9 + 0x7c) = 1;
              goto LAB_001014e0;
            }
            local_bc = 0;
            local_b8 = local_b8 & 0xffffffff00000000;
            lVar10 = of_find_property(uVar14,"qcom,secondary-map",&local_b8);
            if (lVar10 != 0) {
              uVar16 = (uint)local_b8;
              iVar8 = (int)(uint)local_b8 >> 2;
              bVar7 = 3 < (uint)local_b8;
              local_b8 = CONCAT44(local_b8._4_4_,iVar8);
              if ((bVar7) && ((uVar16 >> 2 & 1) == 0)) {
                if (iVar8 < 0) {
                  iVar8 = iVar8 + 1;
                }
                uVar4 = iVar8 >> 1;
                puVar13 = (undefined4 *)
                          devm_kmalloc(plVar2,-(ulong)(uVar4 + 1 >> 0x1f) & 0xfffffff800000000 |
                                              (ulong)(uVar4 + 1) << 3,0xdc0);
                if (puVar13 != (undefined4 *)0x0) {
                  if (7 < (int)uVar16) {
                    if ((int)uVar4 < 2) {
                      uVar4 = 1;
                    }
                    uVar20 = 0;
                    do {
                      iVar8 = of_property_read_u32_index
                                        (uVar14,"qcom,secondary-map",uVar20 & 0xffffffff,&local_bc);
                      if (iVar8 < 0) goto LAB_00101860;
                      puVar13[uVar20] = local_bc;
                      iVar8 = of_property_read_u32_index
                                        (uVar14,"qcom,secondary-map",uVar20 + 1 & 0xffffffff,
                                         &local_bc);
                      if (iVar8 < 0) goto LAB_00101860;
                      lVar10 = uVar20 + 2;
                      puVar13[uVar20 + 1] = local_bc;
                      uVar20 = uVar20 + 2;
                    } while ((ulong)uVar4 * 2 != lVar10);
                    plVar9[0x11] = (long)puVar13;
                    puVar13[(ulong)uVar4 * 2] = 0;
                    goto joined_r0x00101480;
                  }
                  *puVar13 = 0;
                  plVar9[0x11] = (long)puVar13;
                  goto LAB_001014d8;
                }
              }
            }
LAB_00101860:
            plVar9[0x11] = 0;
            pcVar15 = "error importing second map!\n";
          }
          else {
            pcVar15 = "Unable to find target-dev for second vote\n";
          }
LAB_001018d8:
          _dev_err(plVar2,pcVar15);
          iVar8 = -0x16;
          goto LAB_00101a2c;
        }
LAB_001014e0:
        lVar10 = *(long *)(param_1 + 0x80);
        if (lVar10 == 0) {
          lVar10 = *plVar2;
        }
        local_c0 = qcom_dcvs_register_voter(lVar10,local_cc,*(undefined4 *)((long)plVar9 + 0x6c));
        if (local_c0 < 0) {
          if (local_c0 == -0x205) {
            iVar8 = -0x205;
            goto LAB_00101a2c;
          }
          pcVar15 = "qcom dcvs registration error: %d\n";
        }
        else {
          if (*(char *)((long)plVar9 + 0x7c) != '\0') {
            lVar10 = *(long *)(param_1 + 0x80);
            if (lVar10 == 0) {
              lVar10 = *plVar2;
            }
            local_c0 = qcom_dcvs_register_voter(lVar10,local_d0,0);
            if (local_c0 < 0) {
              pcVar15 = "second hw qcom dcvs reg err: %d\n";
              goto LAB_00101a24;
            }
          }
          lVar10 = devm_kmalloc(plVar9[0xc],0x1e0,0xdc0);
          if (lVar10 == 0) {
            pcVar15 = "bwmon node configuration failed: %d\n";
            local_c0 = -0xc;
          }
          else {
            *(undefined8 *)(lVar10 + 0x28) = 0x6400000032;
            *(undefined8 *)(lVar10 + 0x30) = 0x100000005a;
            plVar9[0x12] = lVar10;
            plVar11 = plVar9 + 5;
            *(undefined8 *)(lVar10 + 0x38) = 0x32000000be;
            *(undefined8 *)(lVar10 + 0x40) = 0xa00000000;
            *(undefined8 *)(lVar10 + 0x48) = 0x300000000;
            *(undefined8 *)(lVar10 + 0x50) = 0x300000000;
            *(undefined8 *)(lVar10 + 0x58) = 0;
            *(undefined8 *)(lVar10 + 0x60) = 0x6400000190;
            *(undefined4 *)(lVar10 + 0x68) = 0;
            *(long **)(lVar10 + 0x118) = plVar11;
            __mutex_init(lVar10 + 0x180,"&node->mon_lock",&configure_hwmon_node___key);
            __mutex_init(lVar10 + 0x1b0,"&node->update_lock",&configure_hwmon_node___key_44);
            uVar12 = _raw_spin_lock_irqsave(&list_lock);
            puVar5 = PTR_hwmon_list_001057b8;
            puVar3 = (undefined *)(lVar10 + 0x108);
            uVar14 = __list_add_valid(puVar3,PTR_hwmon_list_001057b8,&hwmon_list);
            if ((uVar14 & 1) != 0) {
              PTR_hwmon_list_001057b8 = puVar3;
              *(undefined ***)(lVar10 + 0x108) = &hwmon_list;
              *(undefined **)(lVar10 + 0x110) = puVar5;
              *(undefined **)puVar5 = puVar3;
            }
            _raw_spin_unlock_irqrestore(&list_lock,uVar12);
            puVar13 = (undefined4 *)plVar9[0x12];
            local_c0 = 0;
            local_c0 = qcom_dcvs_hw_minmax_get(local_cc,puVar13,puVar13 + 1);
            if (-1 < local_c0) {
              puVar13[2] = *puVar13;
              puVar13[3] = puVar13[1];
              puVar13[4] = *puVar13;
              puVar13[5] = 0;
              puVar13[6] = local_cc;
              puVar13[9] = local_d0;
              if (plVar9[0x11] != 0) {
                lVar10 = plVar9[0x11] + -4;
                do {
                  piVar1 = (int *)(lVar10 + 4);
                  lVar10 = lVar10 + 8;
                } while (1 < *piVar1 + 1U);
                lVar19 = -8;
                if (*piVar1 != 0) {
                  lVar19 = 0;
                }
                *(undefined4 *)(plVar9 + 0x10) = *(undefined4 *)(lVar10 + lVar19);
              }
              *(undefined1 *)(plVar9 + 0x1d) = 0;
              mutex_lock(bwmon_lock);
              if (bwmon_wq == 0) {
                bwmon_wq = alloc_workqueue(&DAT_00105cbc,0x4000e,1,"bwmon_wq");
                if (bwmon_wq == 0) {
                  _dev_err(plVar2,"Couldn\'t create bwmon workqueue.\n");
                  mutex_unlock(bwmon_lock);
                  iVar8 = -0xc;
                  goto LAB_00101a2c;
                }
                tracepoint_probe_register
                          (&__tracepoint_android_vh_jiffies_update,bwmon_jiffies_update_cb,0);
              }
              mutex_unlock(bwmon_lock);
              plVar9[0x1a] = (long)bwmon_pm_notifier;
              plVar9[0x14] = 0xfffffffe0;
              plVar9[0x15] = (long)(plVar9 + 0x15);
              plVar9[0x16] = (long)(plVar9 + 0x15);
              plVar9[0x17] = (long)bwmon_monitor_work;
              register_pm_notifier(plVar9 + 0x1a);
              lVar10 = plVar9[0x12];
              uVar12 = ktime_get();
              *(undefined8 *)(lVar10 + 0x90) = 0;
              *(undefined8 *)(lVar10 + 0xf0) = uVar12;
              plVar9[0x1e] = (((((ulong)*(uint *)(plVar9 + 0xe) * 1000 & 0xffff8) *
                                (ulong)*(uint *)(lVar10 + 0x10) >> 0x14) +
                              ((ulong)*(uint *)(plVar9 + 0xe) * 1000 >> 0x14) *
                              (ulong)*(uint *)(lVar10 + 0x10)) * (ulong)*(uint *)(lVar10 + 0x34)) /
                             100;
              plVar9[0x1f] = 500;
              if (*(int *)((code *)plVar9[5] + -4) != -0x1a868a4) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8229,0x101794);
                (*pcVar17)();
              }
              iVar8 = (*(code *)plVar9[5])(plVar11);
              if (iVar8 < 0) {
                _dev_err(plVar9[0xc],"Unable to start HW monitor! (%d)\n",iVar8);
                local_c0 = iVar8;
                _dev_err(plVar2,"Error starting BWMON monitor: %d\n",iVar8);
              }
              else {
                local_c0 = 0;
                *(undefined1 *)(lVar10 + 0x101) = 1;
                uVar14 = qcom_dcvs_kobject_get(local_cc);
                if (uVar14 < 0xfffffffffffff001) {
                  lVar10 = *(long *)(param_1 + 0x80);
                  if (lVar10 == 0) {
                    lVar10 = *plVar2;
                  }
                  local_c0 = kobject_init_and_add(puVar13 + 0x48,bwmon_ktype,uVar14,lVar10);
                  if (-1 < local_c0) {
                    iVar8 = 0;
                    goto LAB_00101a2c;
                  }
                  _dev_err(plVar2,"failed to init bwmon kobj: %d\n",local_c0);
                  kobject_put(puVar13 + 0x48);
                }
                else {
                  local_c0 = (int)uVar14;
                  _dev_err(plVar2,"error getting kobj from qcom_dcvs: %d\n");
                }
              }
              lVar19 = plVar9[0x12];
              lVar10 = lVar19 + 0x180;
              mutex_lock(lVar10);
              *(undefined1 *)(lVar19 + 0x101) = 0;
              mutex_unlock(lVar10);
              if (*(int *)((code *)plVar9[6] + -4) != -0x10d1b2cc) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x1019b4);
                (*pcVar17)();
              }
              (*(code *)plVar9[6])(plVar11);
              uVar12 = _raw_spin_lock_irqsave(&list_lock);
              uVar14 = __list_del_entry_valid(puVar13 + 0x42);
              if ((uVar14 & 1) != 0) {
                lVar10 = *(long *)(puVar13 + 0x42);
                plVar2 = *(long **)(puVar13 + 0x44);
                *(long **)(lVar10 + 8) = plVar2;
                *plVar2 = lVar10;
              }
              *(undefined8 *)(puVar13 + 0x42) = 0xdead000000000100;
              *(undefined8 *)(puVar13 + 0x44) = 0xdead000000000122;
              _raw_spin_unlock_irqrestore(&list_lock,uVar12);
              goto LAB_00101a28;
            }
            pcVar15 = "error getting minmax from qcom dcvs: %d\n";
          }
        }
LAB_00101a24:
        _dev_err(plVar2,pcVar15,local_c0);
        goto LAB_00101a28;
      }
      pcVar15 = "invalid hw width=%d, ret=%d\n";
    }
LAB_00101900:
    _dev_err(plVar2,pcVar15);
    iVar8 = -0x16;
  }
  else {
    local_c0 = of_property_read_variable_u32_array
                         (*(undefined8 *)(param_1 + 0x2f8),"qcom,hw-timer-hz",plVar9 + 0x21,1,0);
    if (-1 < local_c0) {
      local_c0 = 0;
      goto LAB_001010a8;
    }
    _dev_err(plVar2,"HW sampling rate not specified!\n");
LAB_00101a28:
    iVar8 = local_c0;
  }
LAB_00101a2c:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar8);
  }
  return;
}



//------------------------------------------------------------
// start_bw_hwmon3 @ 00101a90 size=768
// signature: undefined start_bw_hwmon3(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

int start_bw_hwmon3(long param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  
  lVar5 = (*(long **)(param_1 + -8))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + -8);
  }
  iVar2 = request_threaded_irq
                    (*(undefined4 *)(param_1 + -0x14),bwmon_intr_handler3,bwmon_intr_thread,0x2080,
                     lVar5,(long *)(param_1 + -0x28));
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -8),"Unable to register interrupt handler! (%d)\n",iVar2);
  }
  else {
    writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x10);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x14);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 0x14);
    DataSynchronizationBarrier(3,3,0);
    uVar3 = *(uint *)(*(long *)(param_1 + 0x68) + 0x28);
    if (*(uint *)(param_1 + 0xe8) != uVar3) {
      *(uint *)(param_1 + 0xe8) = uVar3;
      uVar7 = (*(int *)(param_1 + 0xe0) * (uVar3 % 1000)) / 1000 +
              *(int *)(param_1 + 0xe0) * (uVar3 / 1000);
      if (uVar7 >> 0x18 != 0) {
        uVar7 = 0xffffff;
        _printk(&DAT_00105f71,0xffffff,0xffffff);
      }
      writel_relaxed(uVar7,*(long *)(param_1 + -0x28) + 0x20);
    }
    uVar7 = *(uint *)(param_1 + 0xd8);
    bVar1 = *(byte *)(param_1 + 0xf0);
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    uVar6 = *(long *)(param_1 + 200) * (ulong)uVar3;
    uVar9 = (ulong)(0x14 - bVar1);
    uVar10 = bVar1 - 0x14;
    uVar8 = *(long *)(param_1 + 0xd0) * (ulong)uVar3;
    uVar11 = uVar8 >> ((ulong)uVar10 & 0x3f);
    uVar12 = uVar6 >> ((ulong)uVar10 & 0x3f);
    if (bVar1 < 0x14 || uVar10 == 0) {
      uVar11 = uVar8 << (uVar9 & 0x3f);
      uVar12 = uVar6 << (uVar9 & 0x3f);
    }
    uVar12 = (uVar12 + 999) / 1000;
    uVar11 = (uVar11 + 999) / 1000;
    uVar3 = (uint)uVar12;
    uVar10 = (uint)uVar11;
    if ((*(uint *)(param_1 + 0xf4) < uVar3) || (uVar3 < uVar10)) {
      _printk(&DAT_00105e39,uVar12 & 0xffffffff,uVar11 & 0xffffffff,0);
      if (*(uint *)(param_1 + 0xf4) <= uVar3) {
        uVar3 = *(uint *)(param_1 + 0xf4);
      }
      uVar12 = (ulong)uVar3;
      if (uVar3 - 1 <= uVar10) {
        uVar10 = uVar3 - 1;
      }
      uVar11 = (ulong)uVar10;
    }
    writel_relaxed(uVar12 & 0xffffffff,*(long *)(param_1 + -0x28) + 0x24);
    writel_relaxed(uVar11 & 0xffffffff,*(long *)(param_1 + -0x28) + 0x28);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 0x2c);
    writel_relaxed(uVar7 << 8 | 0x1ff00ff,*(long *)(param_1 + -0x28) + 0x34);
    writel_relaxed(0x95250901,*(long *)(param_1 + -0x28) + 0x30);
    if (*(int *)(param_1 + 0xf8) != 0) {
      writel_relaxed(*(int *)(param_1 + 0xf8),*(long *)(param_1 + -0x28) + 0x18);
      writel_relaxed(*(undefined4 *)(param_1 + 0xfc),*(long *)(param_1 + -0x28) + 0x1c);
    }
    writel_relaxed(0xf,*(long *)(param_1 + -0x28) + 8);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 8);
    _raw_spin_lock(&mon_irq_lock);
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0xc);
    writel_relaxed(uVar3 | 0xf,*(long *)(param_1 + -0x28) + 0xc);
    _raw_spin_unlock(&mon_irq_lock);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x10);
    uVar4 = ktime_get();
    iVar2 = 0;
    *(undefined8 *)(param_1 + 0x70) = uVar4;
    *(undefined1 *)(param_1 + 0xc0) = 1;
  }
  return iVar2;
}



//------------------------------------------------------------
// stop_bw_hwmon3 @ 00101d94 size=220
// signature: undefined stop_bw_hwmon3(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

void stop_bw_hwmon3(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  *(undefined1 *)(param_1 + 0xc0) = 0;
  cancel_work_sync(param_1 + 0x78);
  _raw_spin_lock(&mon_irq_lock);
  plVar2 = (long *)(param_1 + -0x28);
  uVar1 = readl_relaxed(*plVar2 + 0xc);
  writel_relaxed(uVar1 & 0xfffffff0,*plVar2 + 0xc);
  _raw_spin_unlock(&mon_irq_lock);
  DataSynchronizationBarrier(3,3,0);
  synchronize_irq(*(undefined4 *)(param_1 + -0x14));
  free_irq(*(undefined4 *)(param_1 + -0x14),plVar2);
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*plVar2 + 0x10);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(2,*plVar2 + 0x14);
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(0,*plVar2 + 0x14);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0xf,*plVar2 + 8);
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(0,*plVar2 + 8);
  return;
}



//------------------------------------------------------------
// get_bytes_and_clear3 @ 00101e74 size=256
// signature: undefined get_bytes_and_clear3(void)
// callers: []
//------------------------------------------------------------

long get_bytes_and_clear3(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x10);
  DataSynchronizationBarrier(3,3,0);
  if (*(int *)(param_1 + 0xec) == 0) {
    iVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x40);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (uint)((ulong)LZCOUNT(iVar3) >> 3) ^ 3;
    }
  }
  else {
    uVar4 = (uint)LZCOUNT(*(int *)(param_1 + 0xec)) ^ 0x1f;
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  uVar4 = readl_relaxed(*(long *)(param_1 + -0x28) + (ulong)(uVar4 << 2) + 0x44);
  bVar2 = *(byte *)(param_1 + 0xf0);
  lVar1 = 0;
  if (uVar4 != 0) {
    lVar1 = (ulong)uVar4 + 1;
  }
  writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x14);
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(0,*(long *)(param_1 + -0x28) + 0x14);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0xf,*(long *)(param_1 + -0x28) + 8);
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(0,*(long *)(param_1 + -0x28) + 8);
  writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x10);
  return lVar1 << ((ulong)bVar2 & 0x3f);
}



//------------------------------------------------------------
// set_hw_events3 @ 00101f78 size=36
// signature: undefined set_hw_events3(void)
// callers: []
//------------------------------------------------------------

undefined8 set_hw_events3(undefined8 param_1,undefined8 param_2)

{
  __set_hw_events(param_1,param_2,2);
  return 0;
}



//------------------------------------------------------------
// start_bw_hwmon2 @ 00101fa0 size=792
// signature: undefined start_bw_hwmon2(void)
// callers: []
//------------------------------------------------------------

int start_bw_hwmon2(long param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  
  lVar5 = (*(long **)(param_1 + -8))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + -8);
  }
  iVar2 = request_threaded_irq
                    (*(undefined4 *)(param_1 + -0x14),bwmon_intr_handler2,bwmon_intr_thread,0x2080,
                     lVar5,(long *)(param_1 + -0x28));
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -8),"Unable to register interrupt handler! (%d)\n",iVar2);
  }
  else {
    writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x2a0);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x2a4);
    DataSynchronizationBarrier(3,3,0);
    uVar3 = *(uint *)(*(long *)(param_1 + 0x68) + 0x28);
    if (*(uint *)(param_1 + 0xe8) != uVar3) {
      *(uint *)(param_1 + 0xe8) = uVar3;
      uVar7 = (*(int *)(param_1 + 0xe0) * (uVar3 % 1000)) / 1000 +
              *(int *)(param_1 + 0xe0) * (uVar3 / 1000);
      if (uVar7 >> 0x18 != 0) {
        uVar7 = 0xffffff;
        _printk(&DAT_00105f71,0xffffff,0xffffff);
      }
      writel_relaxed(uVar7,*(long *)(param_1 + -0x28) + 0x2a8);
    }
    uVar7 = *(uint *)(param_1 + 0xd8);
    bVar1 = *(byte *)(param_1 + 0xf0);
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    uVar6 = *(long *)(param_1 + 200) * (ulong)uVar3;
    uVar9 = (ulong)(0x14 - bVar1);
    uVar10 = bVar1 - 0x14;
    uVar8 = *(long *)(param_1 + 0xd0) * (ulong)uVar3;
    uVar11 = uVar8 >> ((ulong)uVar10 & 0x3f);
    uVar12 = uVar6 >> ((ulong)uVar10 & 0x3f);
    if (bVar1 < 0x14 || uVar10 == 0) {
      uVar11 = uVar8 << (uVar9 & 0x3f);
      uVar12 = uVar6 << (uVar9 & 0x3f);
    }
    uVar12 = (uVar12 + 999) / 1000;
    uVar11 = (uVar11 + 999) / 1000;
    uVar3 = (uint)uVar12;
    uVar10 = (uint)uVar11;
    if ((*(uint *)(param_1 + 0xf4) < uVar3) || (uVar3 < uVar10)) {
      _printk(&DAT_00105e39,uVar12 & 0xffffffff,uVar11 & 0xffffffff,0);
      if (*(uint *)(param_1 + 0xf4) <= uVar3) {
        uVar3 = *(uint *)(param_1 + 0xf4);
      }
      uVar12 = (ulong)uVar3;
      if (uVar3 - 1 <= uVar10) {
        uVar10 = uVar3 - 1;
      }
      uVar11 = (ulong)uVar10;
    }
    writel_relaxed(uVar12 & 0xffffffff,*(long *)(param_1 + -0x28) + 0x2ac);
    writel_relaxed(uVar11 & 0xffffffff,*(long *)(param_1 + -0x28) + 0x2b0);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 0x2b4);
    writel_relaxed(uVar7 << 8 | 0x1ff00ff,*(long *)(param_1 + -0x28) + 700);
    writel_relaxed(0x95250901,*(long *)(param_1 + -0x28) + 0x2b8);
    if (*(int *)(param_1 + 0xf8) != 0) {
      writel_relaxed(*(int *)(param_1 + 0xf8),*(long *)(param_1 + -0x28) + 0x298);
      writel_relaxed(*(undefined4 *)(param_1 + 0xfc),*(long *)(param_1 + -0x28) + 0x29c);
    }
    writel_relaxed(0xf0,*(long *)(param_1 + -0x28) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),
                   *(long *)(param_1 + -0x20) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    _raw_spin_lock(&mon_irq_lock);
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x20) + 0x10c);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f) | uVar3,
                   *(long *)(param_1 + -0x20) + 0x10c);
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x10c);
    writel_relaxed(uVar3 | 0xf0,*(long *)(param_1 + -0x28) + 0x10c);
    _raw_spin_unlock(&mon_irq_lock);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x2a0);
    uVar4 = ktime_get();
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0xc0) = 1;
    *(undefined8 *)(param_1 + 0x70) = uVar4;
  }
  return iVar2;
}



//------------------------------------------------------------
// stop_bw_hwmon2 @ 001022bc size=260
// signature: undefined stop_bw_hwmon2(void)
// callers: []
//------------------------------------------------------------

void stop_bw_hwmon2(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  *(undefined1 *)(param_1 + 0xc0) = 0;
  cancel_work_sync(param_1 + 0x78);
  _raw_spin_lock(&mon_irq_lock);
  uVar1 = readl_relaxed(*(long *)(param_1 + -0x20) + 0x10c);
  writel_relaxed(uVar1 & (1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f) ^ 0xffffffffU),
                 *(long *)(param_1 + -0x20) + 0x10c);
  plVar2 = (long *)(param_1 + -0x28);
  uVar1 = readl_relaxed(*plVar2 + 0x10c);
  writel_relaxed(uVar1 & 0xffffff0f,*plVar2 + 0x10c);
  _raw_spin_unlock(&mon_irq_lock);
  DataSynchronizationBarrier(3,3,0);
  synchronize_irq(*(undefined4 *)(param_1 + -0x14));
  free_irq(*(undefined4 *)(param_1 + -0x14),plVar2);
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*plVar2 + 0x2a0);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(2,*plVar2 + 0x2a4);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0xf0,*plVar2 + 0x108);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),*(long *)(param_1 + -0x20) + 0x108)
  ;
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// get_bytes_and_clear2 @ 001023c4 size=256
// signature: undefined get_bytes_and_clear2(void)
// callers: []
//------------------------------------------------------------

long get_bytes_and_clear2(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x2a0);
  DataSynchronizationBarrier(3,3,0);
  if (*(int *)(param_1 + 0xec) == 0) {
    iVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x2d8);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (uint)((ulong)LZCOUNT(iVar3) >> 3) ^ 3;
    }
  }
  else {
    uVar4 = (uint)LZCOUNT(*(int *)(param_1 + 0xec)) ^ 0x1f;
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  uVar4 = readl_relaxed(*(long *)(param_1 + -0x28) + (ulong)(uVar4 << 2) + 0x2e0);
  bVar2 = *(byte *)(param_1 + 0xf0);
  lVar1 = 0;
  if (uVar4 != 0) {
    lVar1 = (ulong)uVar4 + 1;
  }
  writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x2a4);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0xf0,*(long *)(param_1 + -0x28) + 0x108);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),*(long *)(param_1 + -0x20) + 0x108)
  ;
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x2a0);
  return lVar1 << ((ulong)bVar2 & 0x3f);
}



//------------------------------------------------------------
// set_hw_events @ 001024c8 size=36
// signature: undefined set_hw_events(void)
// callers: []
//------------------------------------------------------------

undefined8 set_hw_events(undefined8 param_1,undefined8 param_2)

{
  __set_hw_events(param_1,param_2,1);
  return 0;
}



//------------------------------------------------------------
// start_bw_hwmon @ 001024f0 size=448
// signature: undefined start_bw_hwmon(void)
// callers: []
//------------------------------------------------------------

int start_bw_hwmon(long param_1,long param_2)

{
  undefined1 auVar1 [16];
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = (*(long **)(param_1 + -8))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + -8);
  }
  uVar3 = *(uint *)(*(long *)(param_1 + 0x68) + 0x28);
  iVar2 = request_threaded_irq
                    (*(undefined4 *)(param_1 + -0x14),bwmon_intr_handler,bwmon_intr_thread,0x2080,
                     lVar5,param_1 + -0x28);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -8),"Unable to register interrupt handler! (%d)\n",iVar2);
  }
  else {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = (ulong)uVar3 * param_2 + 999 >> 3;
    writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x280);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x284);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed((SUB164(auVar1 * ZEXT816(0x20c49ba5e353f7cf),8) & 0xfff0) << 0x10,
                   *(long *)(param_1 + -0x28) + 0x290);
    if (*(int *)(param_1 + 0xf8) != 0) {
      writel_relaxed(*(int *)(param_1 + 0xf8),*(long *)(param_1 + -0x28) + 0x298);
      writel_relaxed(*(undefined4 *)(param_1 + 0xfc),*(long *)(param_1 + -0x28) + 0x29c);
    }
    writel_relaxed(3,*(long *)(param_1 + -0x28) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),
                   *(long *)(param_1 + -0x20) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    _raw_spin_lock(&mon_irq_lock);
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x20) + 0x10c);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f) | uVar3,
                   *(long *)(param_1 + -0x20) + 0x10c);
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x10c);
    writel_relaxed(uVar3 | 1,*(long *)(param_1 + -0x28) + 0x10c);
    _raw_spin_unlock(&mon_irq_lock);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x280);
    uVar4 = ktime_get();
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0xc0) = 1;
    *(undefined8 *)(param_1 + 0x70) = uVar4;
  }
  return iVar2;
}



//------------------------------------------------------------
// stop_bw_hwmon @ 001026b4 size=260
// signature: undefined stop_bw_hwmon(void)
// callers: []
//------------------------------------------------------------

void stop_bw_hwmon(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  *(undefined1 *)(param_1 + 0xc0) = 0;
  cancel_work_sync(param_1 + 0x78);
  _raw_spin_lock(&mon_irq_lock);
  uVar1 = readl_relaxed(*(long *)(param_1 + -0x20) + 0x10c);
  writel_relaxed(uVar1 & (1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f) ^ 0xffffffffU),
                 *(long *)(param_1 + -0x20) + 0x10c);
  plVar2 = (long *)(param_1 + -0x28);
  uVar1 = readl_relaxed(*plVar2 + 0x10c);
  writel_relaxed(uVar1 & 0xfffffffe,*plVar2 + 0x10c);
  _raw_spin_unlock(&mon_irq_lock);
  DataSynchronizationBarrier(3,3,0);
  synchronize_irq(*(undefined4 *)(param_1 + -0x14));
  free_irq(*(undefined4 *)(param_1 + -0x14),plVar2);
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*plVar2 + 0x280);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1,*plVar2 + 0x284);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(3,*plVar2 + 0x108);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),*(long *)(param_1 + -0x20) + 0x108)
  ;
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// get_bytes_and_clear @ 001027bc size=244
// signature: undefined get_bytes_and_clear(void)
// callers: []
//------------------------------------------------------------

ulong get_bytes_and_clear(long param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x280);
  DataSynchronizationBarrier(3,3,0);
  uVar2 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x288);
  uVar2 = uVar2 & 0xffffffff;
  uVar1 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x100);
  if ((uVar1 >> 1 & 1) != 0) {
    if (*(char *)(*(long *)(param_1 + -0x10) + 1) != '\0') {
      uVar2 = uVar2 + 0xffffffff;
    }
  }
  if (((uVar1 & 1) != 0) && (**(char **)(param_1 + -0x10) != '\0')) {
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x290);
    uVar2 = uVar2 + (uVar3 & 0xffffffff);
  }
  writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x284);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(3,*(long *)(param_1 + -0x28) + 0x108);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),*(long *)(param_1 + -0x20) + 0x108)
  ;
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x280);
  return uVar2;
}



//------------------------------------------------------------
// set_thres @ 001028b4 size=296
// signature: undefined set_thres(void)
// callers: []
//------------------------------------------------------------

ulong set_thres(long param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  writel_relaxed(*(undefined4 *)(param_1 + 0xe4),*(long *)(param_1 + -0x28) + 0x280);
  DataSynchronizationBarrier(3,3,0);
  uVar2 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x288);
  uVar2 = uVar2 & 0xffffffff;
  uVar1 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x100);
  if ((uVar1 >> 1 & 1) != 0) {
    if (*(char *)(*(long *)(param_1 + -0x10) + 1) != '\0') {
      uVar2 = uVar2 + 0xffffffff;
    }
  }
  if (((uVar1 & 1) != 0) && (**(char **)(param_1 + -0x10) != '\0')) {
    uVar3 = readl_relaxed(*(long *)(param_1 + -0x28) + 0x290);
    uVar2 = uVar2 + (uVar3 & 0xffffffff);
  }
  writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x284);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(3,*(long *)(param_1 + -0x28) + 0x108);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),*(long *)(param_1 + -0x20) + 0x108)
  ;
  DataSynchronizationBarrier(3,3,0);
  if (**(char **)(param_1 + -0x10) != '\0') {
    if (param_2 < 0x7a121) {
      param_2 = 500000;
    }
  }
  writel_relaxed(param_2 & 0xffffffff,*(long *)(param_1 + -0x28) + 0x290);
  writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + 0x280);
  return uVar2;
}



//------------------------------------------------------------
// mon_set_throttle_adj @ 001029e0 size=32
// signature: undefined mon_set_throttle_adj(void)
// callers: []
//------------------------------------------------------------

undefined8 mon_set_throttle_adj(long param_1,uint param_2)

{
  if (param_2 < 0x20) {
    *(uint *)(param_1 + 0xe4) = (param_2 & 0x1f) << 0x10;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mon_get_throttle_adj @ 00102a04 size=8
// signature: undefined mon_get_throttle_adj(void)
// callers: []
//------------------------------------------------------------

undefined2 mon_get_throttle_adj(long param_1)

{
  return *(undefined2 *)(param_1 + 0xe6);
}



//------------------------------------------------------------
// bwmon_jiffies_update_cb @ 00102a10 size=212
// signature: undefined bwmon_jiffies_update_cb(void)
// callers: []
//------------------------------------------------------------

void bwmon_jiffies_update_cb(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  lVar1 = ktime_get();
  uVar2 = _raw_spin_lock_irqsave(&list_lock);
  if ((undefined **)hwmon_list != &hwmon_list) {
    ppuVar3 = (undefined **)hwmon_list;
    do {
      puVar4 = ppuVar3[2];
      if ((puVar4[0xc0] != '\0') &&
         ((long)((ulong)*(uint *)(*(long *)(puVar4 + 0x68) + 0x28) * 1000000) <
          (lVar1 + 2000000) - *(long *)(puVar4 + 0x70))) {
        queue_work_on(0x20,bwmon_wq,puVar4 + 0x78);
        *(long *)(puVar4 + 0x70) = lVar1;
      }
      ppuVar3 = (undefined **)*ppuVar3;
    } while (ppuVar3 != &hwmon_list);
  }
  _raw_spin_unlock_irqrestore(&list_lock,uVar2);
  return;
}



//------------------------------------------------------------
// bwmon_monitor_work @ 00102ae8 size=148
// signature: undefined bwmon_monitor_work(void)
// callers: []
//------------------------------------------------------------

void bwmon_monitor_work(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + -0x10);
  mutex_lock(lVar4 + 0x1b0);
  uVar2 = bwmon_update_cur_freq(lVar4);
  if ((uVar2 & 1) != 0) {
    lVar3 = (*(long **)(param_1 + -0x40))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + -0x40);
    }
    iVar1 = qcom_dcvs_update_votes
                      (lVar3,lVar4 + 0x10,(uint)*(byte *)(param_1 + -0x24) << 1 | 1,
                       *(undefined4 *)(param_1 + -0x34));
    if (iVar1 < 0) {
      _dev_err(*(undefined8 *)(param_1 + -0x40),"bwmon monitor update failed: %d\n",iVar1);
    }
  }
  mutex_unlock(lVar4 + 0x1b0);
  return;
}



//------------------------------------------------------------
// bwmon_pm_notifier @ 00102b80 size=304
// signature: undefined bwmon_pm_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 bwmon_pm_notifier(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  if (param_2 == 2) {
    lVar5 = *(long *)(param_1 + -0x40);
    uVar3 = ktime_get();
    *(undefined8 *)(lVar5 + 0x90) = 0;
    *(undefined8 *)(lVar5 + 0xf0) = uVar3;
    uVar4 = (ulong)*(uint *)(param_1 + -0x60) * 1000;
    *(ulong *)(param_1 + 0x20) =
         ((((uVar4 & 0xffff8) * (ulong)*(uint *)(lVar5 + 0x10) >> 0x14) +
          (uVar4 >> 0x14) * (ulong)*(uint *)(lVar5 + 0x10)) * (ulong)*(uint *)(lVar5 + 0x34)) / 100;
    *(undefined8 *)(param_1 + 0x28) = 500;
    if (*(int *)(*(code **)(param_1 + -0xa8) + -4) != -0x1a868a4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x102c70);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(param_1 + -0xa8))(param_1 + -0xa8);
    if (iVar2 < 0) {
      _dev_err(*(undefined8 *)(param_1 + -0x70),"Unable to start HW monitor! (%d)\n",iVar2);
    }
    else {
      *(undefined1 *)(lVar5 + 0x101) = 1;
    }
  }
  else if (param_2 == 1) {
    lVar6 = *(long *)(param_1 + -0x40);
    lVar5 = lVar6 + 0x180;
    mutex_lock(lVar5);
    *(undefined1 *)(lVar6 + 0x101) = 0;
    mutex_unlock(lVar5);
    if (*(int *)(*(code **)(param_1 + -0xa0) + -4) != -0x10d1b2cc) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102be8);
      (*pcVar1)();
    }
    (**(code **)(param_1 + -0xa0))(param_1 + -0xa8);
  }
  return 1;
}



//------------------------------------------------------------
// bwmon_intr_handler @ 00102cb4 size=136
// signature: undefined bwmon_intr_handler(void)
// callers: []
//------------------------------------------------------------

undefined4 bwmon_intr_handler(undefined8 param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar1 = readl_relaxed(*param_2 + 0x100);
  *(uint *)((long)param_2 + 0x114) = uVar1 & 3;
  if ((uVar1 & 3) == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = _raw_spin_lock_irqsave(&sample_irq_lock);
    iVar2 = __bw_hwmon_sample_end(param_2 + 5);
    _raw_spin_unlock_irqrestore(&sample_irq_lock,uVar3);
    uVar4 = 1;
    if (0 < iVar2) {
      uVar4 = 2;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// bwmon_intr_handler2 @ 00102d40 size=136
// signature: undefined bwmon_intr_handler2(void)
// callers: []
//------------------------------------------------------------

undefined4 bwmon_intr_handler2(undefined8 param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar1 = readl_relaxed(*param_2 + 0x100);
  uVar1 = uVar1 >> 4 & 0xf;
  *(uint *)((long)param_2 + 0x114) = uVar1;
  if (uVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = _raw_spin_lock_irqsave(&sample_irq_lock);
    iVar2 = __bw_hwmon_sample_end(param_2 + 5);
    _raw_spin_unlock_irqrestore(&sample_irq_lock,uVar3);
    uVar4 = 1;
    if (0 < iVar2) {
      uVar4 = 2;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// bwmon_intr_handler3 @ 00102dcc size=132
// signature: undefined bwmon_intr_handler3(void)
// callers: []
//------------------------------------------------------------

undefined4 bwmon_intr_handler3(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar1 = readl_relaxed(*param_2);
  *(uint *)((long)param_2 + 0x114) = uVar1 & 0xf;
  if ((uVar1 & 0xf) == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = _raw_spin_lock_irqsave(&sample_irq_lock);
    iVar2 = __bw_hwmon_sample_end(param_2 + 5);
    _raw_spin_unlock_irqrestore(&sample_irq_lock,uVar3);
    uVar4 = 1;
    if (0 < iVar2) {
      uVar4 = 2;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// bwmon_intr_thread @ 00102e54 size=208
// signature: undefined bwmon_intr_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 bwmon_intr_thread(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0x90);
  mutex_lock(lVar5 + 0x180);
  if (*(char *)(lVar5 + 0x101) != '\0') {
    *(undefined1 *)(param_2 + 0xe8) = 0;
    cancel_work_sync(param_2 + 0xa0);
    mutex_lock(lVar5 + 0x1b0);
    uVar2 = bwmon_update_cur_freq(lVar5);
    if ((uVar2 & 1) != 0) {
      lVar3 = (*(long **)(param_2 + 0x60))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(param_2 + 0x60);
      }
      iVar1 = qcom_dcvs_update_votes
                        (lVar3,lVar5 + 0x10,(uint)*(byte *)(param_2 + 0x7c) << 1 | 1,
                         *(undefined4 *)(param_2 + 0x6c));
      if (iVar1 < 0) {
        _dev_err(*(undefined8 *)(param_2 + 0x60),"bwmon irq update failed: %d\n",iVar1);
      }
    }
    mutex_unlock(lVar5 + 0x1b0);
    uVar4 = ktime_get();
    *(undefined8 *)(param_2 + 0x98) = uVar4;
    *(undefined1 *)(param_2 + 0xe8) = 1;
  }
  mutex_unlock(lVar5 + 0x180);
  return 1;
}



//------------------------------------------------------------
// writel_relaxed @ 00102f24 size=132
// signature: undefined writel_relaxed(void)
// callers: [start_bw_hwmon, set_thres, get_bytes_and_clear2, stop_bw_hwmon2, stop_bw_hwmon, start_bw_hwmon3, start_bw_hwmon2, get_bytes_and_clear3, __set_hw_events, get_bytes_and_clear, stop_bw_hwmon3]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102f3c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102f78,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00102fa8 size=124
// signature: undefined readl_relaxed(void)
// callers: [start_bw_hwmon, bwmon_intr_handler, bwmon_intr_handler2, start_bw_hwmon3, set_thres, get_bytes_and_clear2, stop_bw_hwmon2, bwmon_intr_handler3, stop_bw_hwmon, start_bw_hwmon2, get_bytes_and_clear3, get_bytes_and_clear, stop_bw_hwmon3]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102ff0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// __bw_hwmon_sample_end @ 00103024 size=460
// signature: undefined __bw_hwmon_sample_end(void)
// callers: [bwmon_intr_handler, bwmon_intr_handler2, bwmon_update_cur_freq, bwmon_intr_handler3]
//------------------------------------------------------------

int __bw_hwmon_sample_end(long param_1)

{
  undefined1 auVar1 [16];
  int iVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x68);
  if (*(long *)(param_1 + 0x18) == 0) {
    lVar4 = ktime_get();
    auVar1 = SEXT816(lVar4 - *(long *)(lVar9 + 0xf0)) * SEXT816(0x20c49ba5e353f7cf);
    uVar6 = (ulong)(uint)((int)(auVar1._8_8_ >> 7) - (auVar1._12_4_ >> 0x1f));
    if (*(int *)(*(code **)(param_1 + 0x20) + -4) != -0x676a6d1c) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103140);
      (*pcVar3)();
    }
    lVar5 = (**(code **)(param_1 + 0x20))(param_1);
    iVar7 = 1;
    uVar8 = 0;
    if (uVar6 != 0) {
      uVar8 = (ulong)((*(long *)(lVar9 + 0x98) + lVar5) * 1000000) / uVar6;
    }
    uVar8 = uVar8 + 0xfffff >> 0x14;
    uVar6 = *(ulong *)(lVar9 + 0xa0);
    if (*(ulong *)(lVar9 + 0xa0) <= uVar8) {
      uVar6 = uVar8;
    }
    *(undefined8 *)(lVar9 + 0x98) = 0;
    *(ulong *)(lVar9 + 0xa0) = uVar6;
    if (uVar8 <= *(ulong *)(*(long *)(lVar9 + 0x118) + 200)) {
      if (uVar8 < *(ulong *)(*(long *)(lVar9 + 0x118) + 0xd0)) {
        if (*(int *)(lVar9 + 0xec) == 0) {
          iVar7 = 2;
        }
        else {
          iVar2 = *(int *)(lVar9 + 0xec) + -1;
          iVar7 = (uint)(iVar2 == 0) << 1;
          *(int *)(lVar9 + 0xec) = iVar2;
        }
      }
      else {
        iVar7 = 0;
      }
    }
    *(long *)(lVar9 + 0xf0) = lVar4;
    *(int *)(lVar9 + 0xe8) = iVar7;
    *(undefined1 *)(lVar9 + 0x100) = 1;
  }
  else {
    if (*(int *)(*(code **)(param_1 + 0x20) + -4) != -0x676a6d1c) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103074);
      (*pcVar3)();
    }
    lVar4 = (**(code **)(param_1 + 0x20))(param_1);
    iVar7 = 1;
    uVar8 = (ulong)(uint)(*(int *)(lVar9 + 0x3c) * 1000);
    uVar6 = 0;
    if (uVar8 != 0) {
      uVar6 = (ulong)(lVar4 * 1000000) / uVar8;
    }
    uVar6 = uVar6 + 0xfffff >> 0x14;
    *(ulong *)(lVar9 + 0xa0) = uVar6;
    if (uVar6 <= *(ulong *)(*(long *)(lVar9 + 0x118) + 200)) {
      iVar7 = (uint)(uVar6 < *(ulong *)(*(long *)(lVar9 + 0x118) + 0xd0)) << 1;
    }
    *(int *)(lVar9 + 0xe8) = iVar7;
    *(undefined1 *)(lVar9 + 0x100) = 1;
    iVar7 = 1;
  }
  return iVar7;
}



//------------------------------------------------------------
// bwmon_update_cur_freq @ 001032e0 size=1668
// signature: undefined bwmon_update_cur_freq(void)
// callers: [bwmon_monitor_work, bwmon_intr_thread]
//------------------------------------------------------------

undefined1  [16] bwmon_update_cur_freq(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  undefined1 auVar6 [16];
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  code *pcVar16;
  long lVar17;
  ulong uVar18;
  int iVar19;
  long lVar20;
  ulong uVar21;
  undefined1 auVar22 [16];
  
  lVar20 = *(long *)(param_1 + 0x118);
  uVar11 = *(uint *)(param_1 + 0x34);
  uVar21 = (ulong)uVar11;
  uVar7 = _raw_spin_lock_irqsave(&sample_irq_lock);
  if (*(long *)(lVar20 + 0x18) == 0) {
    lVar15 = ktime_get();
    auVar6 = SEXT816(lVar15 - *(long *)(param_1 + 0xf0)) * SEXT816(0x431bde82d7b634db);
    uVar9 = (int)(auVar6._8_8_ >> 0x12) - (auVar6._12_4_ >> 0x1f);
    if (*(char *)(param_1 + 0x100) != '\0') goto LAB_00103364;
LAB_00103370:
    __bw_hwmon_sample_end(*(undefined8 *)(param_1 + 0x118));
  }
  else {
    uVar9 = 0;
    if (*(char *)(param_1 + 0x100) == '\0') goto LAB_00103370;
LAB_00103364:
    if (*(uint *)(param_1 + 0x3c) <= uVar9) goto LAB_00103370;
  }
  uVar18 = *(ulong *)(param_1 + 0xa0);
  uVar13 = *(ulong *)(param_1 + 0xa8);
  *(undefined1 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  if ((uVar13 < uVar18) || (*(long *)(param_1 + 0xb0) == 0)) {
    uVar14 = (ulong)*(uint *)(param_1 + 0x50);
    *(ulong *)(param_1 + 0xa8) = uVar18;
    uVar13 = uVar18;
  }
  else if (uVar18 < (uVar13 * 0x4b) / 100) {
    uVar14 = *(long *)(param_1 + 0xb0) - 1;
  }
  else {
    uVar14 = (ulong)*(uint *)(param_1 + 0x50);
  }
  *(ulong *)(param_1 + 0xb0) = uVar14;
  uVar14 = (ulong)*(uint *)(param_1 + 0x68);
  if (*(uint *)(param_1 + 0x68) == 0) {
LAB_00103484:
    uVar14 = (ulong)*(uint *)(*(long *)(param_1 + 0x118) + 0x48) * 1000;
    uVar14 = ((uVar14 & 0xffff8) * (ulong)*(uint *)(param_1 + 0xc) >> 0x14) +
             (uVar14 >> 0x14) * (ulong)*(uint *)(param_1 + 0xc);
  }
  else {
    uVar5 = 0;
    if (uVar21 != 0) {
      uVar5 = (uVar18 * 100) / uVar21;
    }
    if ((uVar14 < uVar5) &&
       ((uVar14 = (ulong)*(uint *)(param_1 + 0x6c), *(uint *)(param_1 + 0x6c) == 0 ||
        ((uVar14 < uVar5 &&
         ((uVar14 = (ulong)*(uint *)(param_1 + 0x70), *(uint *)(param_1 + 0x70) == 0 ||
          ((uVar14 < uVar5 &&
           ((uVar14 = (ulong)*(uint *)(param_1 + 0x74), *(uint *)(param_1 + 0x74) == 0 ||
            ((uVar14 < uVar5 &&
             ((uVar14 = (ulong)*(uint *)(param_1 + 0x78), *(uint *)(param_1 + 0x78) == 0 ||
              ((uVar14 < uVar5 &&
               ((uVar14 = (ulong)*(uint *)(param_1 + 0x7c), *(uint *)(param_1 + 0x7c) == 0 ||
                ((uVar14 < uVar5 &&
                 ((uVar14 = (ulong)*(uint *)(param_1 + 0x80), *(uint *)(param_1 + 0x80) == 0 ||
                  ((uVar14 < uVar5 &&
                   ((uVar14 = (ulong)*(uint *)(param_1 + 0x84), *(uint *)(param_1 + 0x84) == 0 ||
                    ((uVar14 < uVar5 &&
                     ((uVar14 = (ulong)*(uint *)(param_1 + 0x88), *(uint *)(param_1 + 0x88) == 0 ||
                      ((uVar14 < uVar5 &&
                       ((uVar14 = (ulong)*(uint *)(param_1 + 0x8c), *(uint *)(param_1 + 0x8c) == 0
                        || (uVar14 < uVar5)))))))))))))))))))))))))))))))))))) goto LAB_00103484;
  }
  uVar14 = (uVar14 * uVar21) / 100;
  uVar21 = uVar18;
  if (uVar18 <= uVar14) {
    uVar21 = uVar14;
  }
  uVar14 = uVar18;
  if (*(int *)(param_1 + 0xe8) == 1) {
    uVar14 = uVar18 + ((uVar18 - *(long *)(param_1 + 0xe0)) * (ulong)*(uint *)(param_1 + 0x40)) /
                      100;
    if (uVar14 <= uVar13 || uVar13 <= uVar18) {
      uVar13 = uVar14;
    }
    uVar14 = uVar13;
    if (uVar21 <= uVar13) {
      uVar14 = uVar21;
    }
  }
  uVar21 = *(ulong *)(param_1 + 0xc0);
  if ((500 < uVar18) && (uVar21 < uVar18)) {
    *(undefined8 *)(param_1 + 0xb8) = 0;
    *(ulong *)(param_1 + 0xc0) = uVar18;
    *(ulong *)(param_1 + 200) = (ulong)*(uint *)(param_1 + 0x58);
    uVar21 = uVar18;
    if (*(long *)(param_1 + 0xd0) != 0) {
      *(ulong *)(param_1 + 0xd0) = (ulong)*(uint *)(param_1 + 0x58);
    }
  }
  if (((500 < uVar18) && ((uVar21 * 0x4b) / 100 <= uVar18)) &&
     (uVar13 = *(long *)(param_1 + 0xb8) + 1, *(ulong *)(param_1 + 0xb8) = uVar13,
     *(uint *)(param_1 + 0x54) <= uVar13)) {
    *(undefined8 *)(param_1 + 0xb8) = 0;
    *(ulong *)(param_1 + 0xd0) = (ulong)*(uint *)(param_1 + 0x58);
  }
  if (*(long *)(param_1 + 200) == 0) {
    if (*(long *)(param_1 + 0xd0) != 0) {
      lVar15 = *(long *)(param_1 + 0xd0) + -1;
      *(long *)(param_1 + 0xd0) = lVar15;
LAB_001035dc:
      if (lVar15 != 0) goto LAB_001035e0;
    }
  }
  else {
    lVar17 = *(long *)(param_1 + 200) + -1;
    *(long *)(param_1 + 200) = lVar17;
    if (*(long *)(param_1 + 0xd0) != 0) {
      lVar15 = *(long *)(param_1 + 0xd0) + -1;
      *(long *)(param_1 + 0xd0) = lVar15;
      if (lVar17 == 0) goto LAB_001035dc;
      if (lVar15 == 0) goto LAB_00103618;
LAB_001035e0:
      if (*(uint *)(param_1 + 0x60) < uVar18) {
        uVar13 = (ulong)*(uint *)(param_1 + 0x5c);
      }
      else {
        if (*(long *)(param_1 + 0xd8) == 0) goto LAB_00103618;
        uVar13 = *(long *)(param_1 + 0xd8) - 1;
      }
      if (uVar14 <= uVar21) {
        uVar14 = uVar21;
      }
      *(ulong *)(param_1 + 0xd8) = uVar13;
      goto LAB_00103618;
    }
    if (lVar17 != 0) goto LAB_00103618;
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
LAB_00103618:
  if (uVar18 < 500) {
    uVar21 = 0;
    uVar13 = uVar14;
    if (uVar14 < 0x1f5) {
      uVar13 = 500;
    }
    uVar18 = uVar14 >> 1;
    if (uVar18 < 0x1f5) {
      uVar18 = 500;
    }
    *(ulong *)(lVar20 + 200) = (uVar13 * (*(int *)(param_1 + 0x44) + 100)) / 100;
  }
  else {
    *(ulong *)(lVar20 + 200) = (uVar14 * (*(int *)(param_1 + 0x44) + 100)) / 100;
    uVar21 = (uVar18 * *(uint *)(param_1 + 0x48)) / 100;
  }
  pcVar16 = *(code **)(lVar20 + 0x18);
  *(ulong *)(lVar20 + 0xd0) = uVar21;
  if (pcVar16 == (code *)0x0) {
    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x4c);
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar18 * *(uint *)(param_1 + 0x3c) + 999 >> 3;
    if (*(int *)(*(code **)(lVar20 + 0x10) + -4) != 0x68c9de78) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10373c);
      (*pcVar16)();
    }
    uVar8 = (**(code **)(lVar20 + 0x10))
                      (lVar20,(SUB164(auVar6 * ZEXT816(0x20c49ba5e353f7cf),8) & 0xfff0) << 0x10);
    *(undefined8 *)(param_1 + 0x98) = uVar8;
  }
  else {
    *(undefined4 *)(lVar20 + 0xd8) = *(undefined4 *)(param_1 + 0x4c);
    if (*(int *)(pcVar16 + -4) != -0x44a3f1b) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x822a,0x1036e0);
      (*pcVar16)();
    }
    (*pcVar16)(lVar20,*(undefined4 *)(param_1 + 0x3c));
  }
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(ulong *)(param_1 + 0xe0) = uVar14;
  _raw_spin_unlock_irqrestore(&sample_irq_lock,uVar7);
  uVar14 = uVar14 + *(uint *)(param_1 + 0x2c);
  if (uVar14 <= *(ulong *)(param_1 + 0x90)) {
    uVar14 = (ulong)(uint)((int)uVar14 * *(int *)(param_1 + 0x30) +
                          (int)*(ulong *)(param_1 + 0x90) * (100 - *(int *)(param_1 + 0x30))) / 100;
  }
  uVar9 = *(uint *)(param_1 + 100);
  iVar10 = (int)uVar14;
  uVar2 = iVar10 * 100;
  *(ulong *)(param_1 + 0x90) = uVar14 & 0xffffffff;
  if (uVar9 < 100) {
    iVar19 = (int)((uVar14 & 0xffffffff) / 100);
    iVar10 = uVar9 * iVar19 + (uVar9 * (iVar10 + iVar19 * -100) >> 2 & 0x3fff) / 0x19;
  }
  uVar9 = *(uint *)(param_1 + 0x38);
  uVar3 = 0;
  if (uVar9 != 0) {
    uVar3 = ((iVar10 + uVar9) - 1) / uVar9;
  }
  uVar4 = 0;
  if (uVar11 != 0) {
    uVar4 = uVar2 / uVar11;
  }
  plVar12 = *(long **)(*(long *)(param_1 + 0x118) + 0x38);
  lVar15 = plVar12[0xe];
  if (lVar15 == 0) {
    lVar15 = *plVar12;
  }
  uVar13 = (ulong)*(uint *)(lVar20 + 0x48) * 1000;
  uVar21 = 0;
  if (uVar13 != 0) {
    uVar21 = uVar4 / uVar13;
  }
  uVar18 = 0;
  if (uVar13 != 0) {
    uVar18 = (uVar3 * uVar9) / uVar13;
  }
  iVar10 = 0;
  if (uVar13 != 0) {
    iVar10 = (int)((((ulong)uVar4 - uVar21 * uVar13) * 0x100000) / uVar13);
  }
  uVar11 = iVar10 + (int)uVar21 * 0x100000;
  iVar10 = 0;
  if (uVar13 != 0) {
    iVar10 = (int)((((ulong)(uVar3 * uVar9) - uVar18 * uVar13) * 0x100000) / uVar13);
  }
  uVar9 = *(uint *)(param_1 + 8);
  if (*(uint *)(param_1 + 8) <= uVar11) {
    uVar9 = uVar11;
  }
  if (*(uint *)(param_1 + 0xc) <= uVar9) {
    uVar9 = *(uint *)(param_1 + 0xc);
  }
  iVar10 = iVar10 + (int)uVar18 * 0x100000;
  if ((uVar9 == *(uint *)(param_1 + 0x10)) && (*(int *)(param_1 + 0x14) == iVar10)) {
    uVar7 = 0;
  }
  else {
    *(uint *)(param_1 + 0x10) = uVar9;
    *(int *)(param_1 + 0x14) = iVar10;
    if (*(char *)(lVar20 + 0x54) == '\0') {
      uVar7 = 1;
    }
    else {
      if (*(long *)(lVar20 + 0x60) == 0) {
        if (*(uint *)(lVar20 + 0x50) == 0) {
          uVar11 = 0;
        }
        else {
          uVar18 = (ulong)*(uint *)(lVar20 + 0x50) * 1000;
          uVar13 = ((uVar13 & 0xffff8) * (ulong)uVar9 >> 0x14) + (uVar13 >> 0x14) * (ulong)uVar9 &
                   0xffffffff;
          uVar21 = 0;
          if (uVar18 != 0) {
            uVar21 = uVar13 / uVar18;
          }
          iVar10 = 0;
          if (uVar18 != 0) {
            iVar10 = (int)(((uVar13 - uVar21 * uVar18) * 0x100000) / uVar18);
          }
          uVar11 = iVar10 + (int)uVar21 * 0x100000;
        }
      }
      else {
        lVar17 = *(long *)(lVar20 + 0x60) + -4;
        do {
          uVar11 = *(uint *)(lVar17 + 4);
          lVar17 = lVar17 + 8;
          if (uVar11 == 0) break;
        } while (uVar11 < uVar9);
        lVar1 = -8;
        if (uVar11 != 0) {
          lVar1 = 0;
        }
        uVar11 = *(uint *)(lVar17 + lVar1);
      }
      *(uint *)(param_1 + 0x1c) = uVar11;
      uVar7 = 1;
      if (*(uint *)(lVar20 + 0x58) <= uVar11) {
        uVar11 = *(uint *)(lVar20 + 0x58);
      }
      *(uint *)(param_1 + 0x1c) = uVar11;
    }
  }
  auVar22._8_8_ = lVar15;
  auVar22._0_8_ = uVar7;
  return auVar22;
}



//------------------------------------------------------------
// __set_hw_events @ 00103a54 size=884
// signature: undefined __set_hw_events(void)
// callers: [set_hw_events3, set_hw_events]
//------------------------------------------------------------

void __set_hw_events(long param_1,uint param_2,uint param_3)

{
  byte bVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  
  if (param_3 < 3) {
    writel_relaxed(*(undefined4 *)(param_1 + 0xe4),
                   *(long *)(param_1 + -0x28) + (&DAT_00106658)[(int)param_3]);
  }
  DataSynchronizationBarrier(3,3,0);
  if (param_3 == 2) {
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x14);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 0x14);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0xf,*(long *)(param_1 + -0x28) + 8);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + 8);
  }
  else if (param_3 == 1) {
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x2a4);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0xf0,*(long *)(param_1 + -0x28) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),
                   *(long *)(param_1 + -0x20) + 0x108);
    DataSynchronizationBarrier(3,3,0);
  }
  else if (param_3 == 0) {
    writel_relaxed(1,*(long *)(param_1 + -0x28) + 0x284);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(3,*(long *)(param_1 + -0x28) + 0x108);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1 << (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),
                   *(long *)(param_1 + -0x20) + 0x108);
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    DataSynchronizationBarrier(3,3,0);
  }
  if (*(uint *)(param_1 + 0xe8) == param_2) goto LAB_00103ba8;
  *(uint *)(param_1 + 0xe8) = param_2;
  uVar4 = (*(int *)(param_1 + 0xe0) * (param_2 % 1000)) / 1000 +
          *(int *)(param_1 + 0xe0) * (param_2 / 1000);
  if (uVar4 >> 0x18 == 0) {
    if (param_3 != 1) goto LAB_00103d80;
LAB_00103db0:
    lVar3 = 0x2a8;
  }
  else {
    uVar4 = 0xffffff;
    _printk(&DAT_00105f71,0xffffff,0xffffff);
    if (param_3 == 1) goto LAB_00103db0;
LAB_00103d80:
    if (param_3 != 2) goto LAB_00103ba8;
    lVar3 = 0x20;
  }
  writel_relaxed(uVar4,*(long *)(param_1 + -0x28) + lVar3);
LAB_00103ba8:
  uVar4 = *(uint *)(param_1 + 0xd8);
  bVar1 = *(byte *)(param_1 + 0xf0);
  if (0xfe < uVar4) {
    uVar4 = 0xff;
  }
  uVar2 = *(long *)(param_1 + 200) * (ulong)param_2;
  uVar6 = (ulong)(0x14 - bVar1);
  uVar9 = bVar1 - 0x14;
  uVar5 = *(long *)(param_1 + 0xd0) * (ulong)param_2;
  uVar8 = uVar5 >> ((ulong)uVar9 & 0x3f);
  uVar10 = uVar2 >> ((ulong)uVar9 & 0x3f);
  if (bVar1 < 0x14 || uVar9 == 0) {
    uVar8 = uVar5 << (uVar6 & 0x3f);
    uVar10 = uVar2 << (uVar6 & 0x3f);
  }
  uVar10 = (uVar10 + 999) / 1000;
  uVar8 = (uVar8 + 999) / 1000;
  uVar9 = (uint)uVar10;
  uVar7 = (uint)uVar8;
  if ((*(uint *)(param_1 + 0xf4) < uVar9) || (uVar9 < uVar7)) {
    _printk(&DAT_00105e39,uVar10 & 0xffffffff,uVar8 & 0xffffffff,0);
    if (*(uint *)(param_1 + 0xf4) <= uVar9) {
      uVar9 = *(uint *)(param_1 + 0xf4);
    }
    uVar10 = (ulong)uVar9;
    if (uVar9 - 1 <= uVar7) {
      uVar7 = uVar9 - 1;
    }
    uVar8 = (ulong)uVar7;
  }
  if (param_3 == 0) {
    lVar3 = 0x280;
  }
  else {
    if (param_3 == 1) {
      lVar11 = 700;
      lVar12 = 0x2b4;
      lVar13 = 0x2b0;
      lVar3 = 0x2ac;
    }
    else {
      if (param_3 != 2) {
        return;
      }
      lVar11 = 0x34;
      lVar12 = 0x2c;
      lVar13 = 0x28;
      lVar3 = 0x24;
    }
    writel_relaxed(uVar10 & 0xffffffff,*(long *)(param_1 + -0x28) + lVar3);
    writel_relaxed(uVar8 & 0xffffffff,*(long *)(param_1 + -0x28) + lVar13);
    writel_relaxed(0,*(long *)(param_1 + -0x28) + lVar12);
    writel_relaxed(uVar4 << 8 | 0x1ff00ff,*(long *)(param_1 + -0x28) + lVar11);
    if (param_3 == 1) {
      lVar3 = 0x2a0;
    }
    else {
      if (param_3 != 2) {
        return;
      }
      lVar3 = 0x10;
    }
  }
  writel_relaxed(*(uint *)(param_1 + 0xe4) | 1,*(long *)(param_1 + -0x28) + lVar3);
  return;
}



//------------------------------------------------------------
// attr_show @ 00103dcc size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103df8);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00103e14 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5800598) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103e40);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_min_freq @ 00103e5c size=60
// signature: undefined show_min_freq(void)
// callers: []
//------------------------------------------------------------

long show_min_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0x118));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_min_freq @ 00103e9c size=168
// signature: undefined store_min_freq(void)
// callers: []
//------------------------------------------------------------

long store_min_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    param_4 = (long)iVar3;
  }
  else {
    uVar1 = local_2c;
    if (local_2c <= *(uint *)(param_1 + -0x120)) {
      uVar1 = *(uint *)(param_1 + -0x120);
    }
    if (*(uint *)(param_1 + -0x114) <= uVar1) {
      uVar1 = *(uint *)(param_1 + -0x114);
    }
    *(uint *)(param_1 + -0x118) = uVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_max_freq @ 00103f48 size=60
// signature: undefined show_max_freq(void)
// callers: []
//------------------------------------------------------------

long show_max_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0x114));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_max_freq @ 00103f88 size=168
// signature: undefined store_max_freq(void)
// callers: []
//------------------------------------------------------------

long store_max_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    param_4 = (long)iVar3;
  }
  else {
    uVar1 = local_2c;
    if (local_2c <= *(uint *)(param_1 + -0x118)) {
      uVar1 = *(uint *)(param_1 + -0x118);
    }
    if (*(uint *)(param_1 + -0x11c) <= uVar1) {
      uVar1 = *(uint *)(param_1 + -0x11c);
    }
    *(uint *)(param_1 + -0x114) = uVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_cur_freq @ 00104034 size=60
// signature: undefined show_cur_freq(void)
// callers: []
//------------------------------------------------------------

long show_cur_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0x110));
  return (long)iVar1;
}



//------------------------------------------------------------
// show_window_ms @ 00104074 size=56
// signature: undefined show_window_ms(void)
// callers: []
//------------------------------------------------------------

long show_window_ms(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xf8));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_window_ms @ 001040b0 size=156
// signature: undefined store_window_ms(void)
// callers: []
//------------------------------------------------------------

long store_window_ms(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (local_2c < 9) {
      uVar3 = 8;
    }
    if (999 < uVar3) {
      uVar3 = 1000;
    }
    *(uint *)(param_1 + -0xf8) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_guard_band_mbps @ 00104150 size=56
// signature: undefined show_guard_band_mbps(void)
// callers: []
//------------------------------------------------------------

long show_guard_band_mbps(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xf4));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_guard_band_mbps @ 0010418c size=144
// signature: undefined store_guard_band_mbps(void)
// callers: []
//------------------------------------------------------------

long store_guard_band_mbps(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (1999 < local_2c) {
      uVar3 = 2000;
    }
    *(uint *)(param_1 + -0xf4) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_decay_rate @ 00104220 size=56
// signature: undefined show_decay_rate(void)
// callers: []
//------------------------------------------------------------

long show_decay_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xf0));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_decay_rate @ 0010425c size=144
// signature: undefined store_decay_rate(void)
// callers: []
//------------------------------------------------------------

long store_decay_rate(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (99 < local_2c) {
      uVar3 = 100;
    }
    *(uint *)(param_1 + -0xf0) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_io_percent @ 001042f0 size=56
// signature: undefined show_io_percent(void)
// callers: []
//------------------------------------------------------------

long show_io_percent(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xec));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_io_percent @ 0010432c size=152
// signature: undefined store_io_percent(void)
// callers: []
//------------------------------------------------------------

long store_io_percent(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (local_2c < 2) {
      uVar3 = 1;
    }
    if (399 < uVar3) {
      uVar3 = 400;
    }
    *(uint *)(param_1 + -0xec) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_bw_step @ 001043c8 size=56
// signature: undefined show_bw_step(void)
// callers: []
//------------------------------------------------------------

long show_bw_step(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xe8));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_bw_step @ 00104404 size=156
// signature: undefined store_bw_step(void)
// callers: []
//------------------------------------------------------------

long store_bw_step(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (local_2c < 0x33) {
      uVar3 = 0x32;
    }
    if (999 < uVar3) {
      uVar3 = 1000;
    }
    *(uint *)(param_1 + -0xe8) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_sample_ms @ 001044a4 size=56
// signature: undefined show_sample_ms(void)
// callers: []
//------------------------------------------------------------

long show_sample_ms(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xe4));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_sample_ms @ 001044e0 size=172
// signature: undefined store_sample_ms(void)
// callers: []
//------------------------------------------------------------

long store_sample_ms(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,10,&local_2c);
  if (iVar2 == 0) {
    uVar3 = local_2c;
    if (local_2c < 2) {
      uVar3 = 1;
    }
    if (0x31 < uVar3) {
      uVar3 = 0x32;
    }
    if (*(uint *)(param_1 + -0xf8) < uVar3) {
      param_4 = -0x16;
    }
    else {
      *(uint *)(param_1 + -0xe4) = uVar3;
    }
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_up_scale @ 00104590 size=56
// signature: undefined show_up_scale(void)
// callers: []
//------------------------------------------------------------

long show_up_scale(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xe0));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_up_scale @ 001045cc size=144
// signature: undefined store_up_scale(void)
// callers: []
//------------------------------------------------------------

long store_up_scale(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (499 < local_2c) {
      uVar3 = 500;
    }
    *(uint *)(param_1 + -0xe0) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_up_thres @ 00104660 size=56
// signature: undefined show_up_thres(void)
// callers: []
//------------------------------------------------------------

long show_up_thres(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xdc));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_up_thres @ 0010469c size=152
// signature: undefined store_up_thres(void)
// callers: []
//------------------------------------------------------------

long store_up_thres(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (local_2c < 2) {
      uVar3 = 1;
    }
    if (99 < uVar3) {
      uVar3 = 100;
    }
    *(uint *)(param_1 + -0xdc) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_down_thres @ 00104738 size=56
// signature: undefined show_down_thres(void)
// callers: []
//------------------------------------------------------------

long show_down_thres(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xd8));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_down_thres @ 00104774 size=144
// signature: undefined store_down_thres(void)
// callers: []
//------------------------------------------------------------

long store_down_thres(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -0xd8) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_down_count @ 00104808 size=56
// signature: undefined show_down_count(void)
// callers: []
//------------------------------------------------------------

long show_down_count(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xd4));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_down_count @ 00104844 size=144
// signature: undefined store_down_count(void)
// callers: []
//------------------------------------------------------------

long store_down_count(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -0xd4) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_hist_memory @ 001048d8 size=56
// signature: undefined show_hist_memory(void)
// callers: []
//------------------------------------------------------------

long show_hist_memory(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xd0));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_hist_memory @ 00104914 size=144
// signature: undefined store_hist_memory(void)
// callers: []
//------------------------------------------------------------

long store_hist_memory(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -0xd0) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_hyst_trigger_count @ 001049a8 size=56
// signature: undefined show_hyst_trigger_count(void)
// callers: []
//------------------------------------------------------------

long show_hyst_trigger_count(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xcc));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_hyst_trigger_count @ 001049e4 size=144
// signature: undefined store_hyst_trigger_count(void)
// callers: []
//------------------------------------------------------------

long store_hyst_trigger_count(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -0xcc) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_hyst_length @ 00104a78 size=56
// signature: undefined show_hyst_length(void)
// callers: []
//------------------------------------------------------------

long show_hyst_length(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -200));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_hyst_length @ 00104ab4 size=144
// signature: undefined store_hyst_length(void)
// callers: []
//------------------------------------------------------------

long store_hyst_length(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -200) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_idle_length @ 00104b48 size=56
// signature: undefined show_idle_length(void)
// callers: []
//------------------------------------------------------------

long show_idle_length(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xc4));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_idle_length @ 00104b84 size=144
// signature: undefined store_idle_length(void)
// callers: []
//------------------------------------------------------------

long store_idle_length(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (0x59 < local_2c) {
      uVar3 = 0x5a;
    }
    *(uint *)(param_1 + -0xc4) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_idle_mbps @ 00104c18 size=56
// signature: undefined show_idle_mbps(void)
// callers: []
//------------------------------------------------------------

long show_idle_mbps(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xc0));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_idle_mbps @ 00104c54 size=144
// signature: undefined store_idle_mbps(void)
// callers: []
//------------------------------------------------------------

long store_idle_mbps(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (1999 < local_2c) {
      uVar3 = 2000;
    }
    *(uint *)(param_1 + -0xc0) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_ab_scale @ 00104ce8 size=56
// signature: undefined show_ab_scale(void)
// callers: []
//------------------------------------------------------------

long show_ab_scale(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(param_1 + -0xbc));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_ab_scale @ 00104d24 size=144
// signature: undefined store_ab_scale(void)
// callers: []
//------------------------------------------------------------

long store_ab_scale(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar3 = local_2c;
    if (99 < local_2c) {
      uVar3 = 100;
    }
    *(uint *)(param_1 + -0xbc) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_mbps_zones @ 00104db8 size=452
// signature: undefined show_mbps_zones(void)
// callers: []
//------------------------------------------------------------

int show_mbps_zones(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  
  if (*(int *)(param_1 + -0xb8) == 0) {
    uVar4 = 0;
  }
  else {
    uVar1 = scnprintf(param_3,0x1000,&DAT_001060df);
    uVar4 = (ulong)uVar1;
    if (*(int *)(param_1 + -0xb4) != 0) {
      iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
      uVar4 = (ulong)(iVar2 + uVar1);
      if (*(int *)(param_1 + -0xb0) != 0) {
        iVar3 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
        uVar1 = iVar3 + iVar2 + uVar1;
        uVar4 = (ulong)uVar1;
        if (*(int *)(param_1 + -0xac) != 0) {
          iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
          uVar1 = iVar2 + uVar1;
          uVar4 = (ulong)uVar1;
          if (*(int *)(param_1 + -0xa8) != 0) {
            iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
            uVar1 = iVar2 + uVar1;
            uVar4 = (ulong)uVar1;
            if (*(int *)(param_1 + -0xa4) != 0) {
              iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
              uVar1 = iVar2 + uVar1;
              uVar4 = (ulong)uVar1;
              if (*(int *)(param_1 + -0xa0) != 0) {
                iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
                uVar1 = iVar2 + uVar1;
                uVar4 = (ulong)uVar1;
                if (*(int *)(param_1 + -0x9c) != 0) {
                  iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
                  uVar1 = iVar2 + uVar1;
                  uVar4 = (ulong)uVar1;
                  if (*(int *)(param_1 + -0x98) != 0) {
                    iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
                    uVar1 = iVar2 + uVar1;
                    uVar4 = (ulong)uVar1;
                    if (*(int *)(param_1 + -0x94) != 0) {
                      iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060df);
                      uVar4 = (ulong)(iVar2 + uVar1);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar2 = scnprintf(param_3 + uVar4,0x1000 - uVar4,&DAT_001060a9);
  return iVar2 + (int)uVar4;
}



//------------------------------------------------------------
// store_mbps_zones @ 00104f80 size=772
// signature: undefined store_mbps_zones(void)
// callers: []
//------------------------------------------------------------

void store_mbps_zones(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  undefined4 local_50;
  uint uStack_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  uStack_4c = 0;
  puVar3 = (undefined8 *)argv_split(0xcc0,param_3,&uStack_4c);
  if (puVar3 == (undefined8 *)0x0) {
    lVar4 = -0xc;
    goto LAB_00105220;
  }
  if (8 < (int)uStack_4c) {
    uStack_4c = 9;
  }
  if (uStack_4c == 0) {
    lVar5 = 0;
LAB_00105208:
    iVar2 = param_4;
  }
  else {
    iVar2 = kstrtouint(*puVar3,10,&local_50);
    if (iVar2 < 0) {
      lVar5 = 0;
    }
    else {
      *(undefined4 *)(param_1 + -0xb8) = local_50;
      if (uStack_4c < 2) {
        lVar5 = 1;
        goto LAB_00105208;
      }
      iVar2 = kstrtouint(puVar3[1],10,&local_50);
      if (iVar2 < 0) {
        lVar5 = 1;
      }
      else {
        *(undefined4 *)(param_1 + -0xb4) = local_50;
        if (uStack_4c < 3) {
          lVar5 = 2;
          goto LAB_00105208;
        }
        iVar2 = kstrtouint(puVar3[2],10,&local_50);
        if (iVar2 < 0) {
          lVar5 = 2;
        }
        else {
          *(undefined4 *)(param_1 + -0xb0) = local_50;
          if (uStack_4c < 4) {
            lVar5 = 3;
            goto LAB_00105208;
          }
          iVar2 = kstrtouint(puVar3[3],10,&local_50);
          if (iVar2 < 0) {
            lVar5 = 3;
          }
          else {
            *(undefined4 *)(param_1 + -0xac) = local_50;
            if (uStack_4c < 5) {
              lVar5 = 4;
              goto LAB_00105208;
            }
            iVar2 = kstrtouint(puVar3[4],10,&local_50);
            if (iVar2 < 0) {
              lVar5 = 4;
            }
            else {
              *(undefined4 *)(param_1 + -0xa8) = local_50;
              if (uStack_4c < 6) {
                lVar5 = 5;
                goto LAB_00105208;
              }
              iVar2 = kstrtouint(puVar3[5],10,&local_50);
              if (iVar2 < 0) {
                lVar5 = 5;
              }
              else {
                *(undefined4 *)(param_1 + -0xa4) = local_50;
                if (uStack_4c < 7) {
                  lVar5 = 6;
                  goto LAB_00105208;
                }
                iVar2 = kstrtouint(puVar3[6],10,&local_50);
                if (iVar2 < 0) {
                  lVar5 = 6;
                }
                else {
                  *(undefined4 *)(param_1 + -0xa0) = local_50;
                  if (uStack_4c < 8) {
                    lVar5 = 7;
                    goto LAB_00105208;
                  }
                  iVar2 = kstrtouint(puVar3[7],10,&local_50);
                  if (iVar2 < 0) {
                    lVar5 = 7;
                  }
                  else {
                    *(undefined4 *)(param_1 + -0x9c) = local_50;
                    if (uStack_4c < 9) {
                      lVar5 = 8;
                      goto LAB_00105208;
                    }
                    iVar2 = kstrtouint(puVar3[8],10,&local_50);
                    if (iVar2 < 0) {
                      lVar5 = 8;
                    }
                    else {
                      *(undefined4 *)(param_1 + -0x98) = local_50;
                      if (uStack_4c < 10) {
                        lVar5 = 9;
                        goto LAB_00105208;
                      }
                      iVar2 = kstrtouint(puVar3[9],10,&local_50);
                      if (-1 < iVar2) {
                        *(undefined4 *)(param_1 + -0x94) = local_50;
                        if ((uStack_4c < 0xb) ||
                           (iVar2 = kstrtouint(puVar3[10],10,&local_50), iVar2 < 0)) {
                          argv_free(puVar3);
                        }
                    /* WARNING: Does not return */
                        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x105284);
                        (*pcVar1)();
                      }
                      lVar5 = 9;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  argv_free(puVar3);
  lVar4 = (long)iVar2;
  *(undefined4 *)(param_1 + lVar5 * 4 + -0xb8) = 0;
LAB_00105220:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_throttle_adj @ 00105288 size=112
// signature: undefined show_throttle_adj(void)
// callers: []
//------------------------------------------------------------

long show_throttle_adj(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*(long *)(param_1 + -8) + 0x30);
  if (pcVar3 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x276bad2f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1052c0);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_00105c85,uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// store_throttle_adj @ 001052fc size=188
// signature: undefined store_throttle_adj(void)
// callers: []
//------------------------------------------------------------

void store_throttle_adj(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(long *)(*(long *)(param_1 + -8) + 0x28) == 0) {
    param_4 = -1;
  }
  else {
    iVar2 = kstrtouint(param_3,10,&local_2c);
    if (iVar2 < 0) {
      param_4 = (long)iVar2;
    }
    else {
      pcVar3 = *(code **)(*(long *)(param_1 + -8) + 0x28);
      if (*(int *)(pcVar3 + -4) != -0x7bd740ab) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10536c);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*(long *)(param_1 + -8),local_2c);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// show_second_vote_limit @ 001053bc size=60
// signature: undefined show_second_vote_limit(void)
// callers: []
//------------------------------------------------------------

long show_second_vote_limit(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105c85,*(undefined4 *)(*(long *)(param_1 + -8) + 0x58));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_second_vote_limit @ 001053fc size=276
// signature: undefined store_second_vote_limit(void)
// callers: []
//------------------------------------------------------------

long store_second_vote_limit(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + -8);
  local_3c = 0;
  if (*(char *)(lVar3 + 0x54) == '\0') {
    param_4 = -0x13;
  }
  else {
    iVar1 = kstrtouint(param_3,10,&local_3c);
    if (iVar1 < 0) {
      param_4 = (long)iVar1;
    }
    else if (local_3c != *(uint *)(lVar3 + 0x58)) {
      mutex_lock(param_1 + 0x90);
      if (local_3c < *(uint *)(param_1 + -0x104)) {
        *(uint *)(param_1 + -0x104) = local_3c;
        lVar2 = (*(long **)(lVar3 + 0x38))[0xe];
        if (lVar2 == 0) {
          lVar2 = **(long **)(lVar3 + 0x38);
        }
        iVar1 = qcom_dcvs_update_votes(lVar2,param_1 + -0x110,3,*(undefined4 *)(lVar3 + 0x44));
        if (iVar1 < 0) {
          _dev_err(*(undefined8 *)(lVar3 + 0x38),"second vote update failed: %d\n",iVar1);
        }
      }
      *(uint *)(lVar3 + 0x58) = local_3c;
      mutex_unlock(param_1 + 0x90);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00105528 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_bwmon_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105558 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_bwmon_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00108000 size=1
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
// platform_driver_unregister @ 00108008 size=1
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
// devm_kmalloc @ 00108010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00108018 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00108020 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00108028 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00108030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00108038 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00108040 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00108048 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00108050 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_register_voter @ 00108058 size=1
// signature: undefined qcom_dcvs_register_voter(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_register_voter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00108060 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00108068 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_bwmon_driver_probe, bwmon_intr_handler, bwmon_intr_handler2, bwmon_update_cur_freq, bwmon_intr_handler3, bwmon_jiffies_update_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00108070 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00108078 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_bwmon_driver_probe, bwmon_intr_handler, bwmon_intr_handler2, bwmon_update_cur_freq, bwmon_intr_handler3, bwmon_jiffies_update_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_hw_minmax_get @ 00108080 size=1
// signature: undefined qcom_dcvs_hw_minmax_get(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_hw_minmax_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00108088 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_bwmon_driver_probe, bwmon_monitor_work, bwmon_intr_thread, store_second_vote_limit, bwmon_pm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00108090 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001080a0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001080a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_bwmon_driver_probe, bwmon_monitor_work, bwmon_intr_thread, store_second_vote_limit, bwmon_pm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 001080b0 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001080b8 size=1
// signature: undefined ktime_get(void)
// callers: [qcom_bwmon_driver_probe, start_bw_hwmon, bwmon_update_cur_freq, start_bw_hwmon3, start_bw_hwmon2, bwmon_jiffies_update_cb, __bw_hwmon_sample_end, bwmon_intr_thread, bwmon_pm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_kobject_get @ 001080c0 size=1
// signature: undefined qcom_dcvs_kobject_get(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_kobject_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 001080c8 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001080d0 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_bwmon_driver_probe, start_bw_hwmon, start_bw_hwmon3, start_bw_hwmon2, bwmon_monitor_work, bwmon_intr_thread, store_second_vote_limit, bwmon_pm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 001080d8 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001080e0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_bwmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001080e8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [store_io_percent, store_bw_step, store_up_scale, store_ab_scale, store_guard_band_mbps, store_idle_mbps, store_throttle_adj, store_second_vote_limit, qcom_bwmon_driver_probe, store_min_freq, store_down_count, store_max_freq, store_idle_length, store_hist_memory, store_up_thres, store_hyst_trigger_count, store_hyst_length, store_down_thres, store_mbps_zones, store_window_ms, store_decay_rate, store_sample_ms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 001080f0 size=1
// signature: undefined request_threaded_irq(void)
// callers: [start_bw_hwmon, start_bw_hwmon3, start_bw_hwmon2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001080f8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [start_bw_hwmon, stop_bw_hwmon2, stop_bw_hwmon, start_bw_hwmon3, start_bw_hwmon2, stop_bw_hwmon3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00108100 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [start_bw_hwmon, stop_bw_hwmon2, stop_bw_hwmon, start_bw_hwmon3, start_bw_hwmon2, stop_bw_hwmon3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00108108 size=1
// signature: undefined _printk(void)
// callers: [start_bw_hwmon3, start_bw_hwmon2, __set_hw_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00108110 size=1
// signature: undefined cancel_work_sync(void)
// callers: [stop_bw_hwmon2, stop_bw_hwmon, bwmon_intr_thread, stop_bw_hwmon3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_irq @ 00108118 size=1
// signature: undefined synchronize_irq(void)
// callers: [stop_bw_hwmon2, stop_bw_hwmon, stop_bw_hwmon3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00108120 size=1
// signature: undefined free_irq(void)
// callers: [stop_bw_hwmon2, stop_bw_hwmon, stop_bw_hwmon3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00108128 size=1
// signature: undefined queue_work_on(void)
// callers: [bwmon_jiffies_update_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_update_votes @ 00108130 size=1
// signature: undefined qcom_dcvs_update_votes(void)
// callers: [bwmon_monitor_work, bwmon_intr_thread, store_second_vote_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_update_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00108138 size=1
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
// log_post_write_mmio @ 00108140 size=1
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
// log_read_mmio @ 00108148 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00108150 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001081a0 size=1
// signature: undefined scnprintf(void)
// callers: [show_window_ms, show_guard_band_mbps, show_min_freq, show_down_count, show_decay_rate, show_bw_step, show_sample_ms, show_ab_scale, show_up_thres, show_hyst_trigger_count, show_mbps_zones, show_up_scale, show_cur_freq, show_io_percent, show_throttle_adj, show_idle_length, show_hist_memory, show_idle_mbps, show_second_vote_limit, show_hyst_length, show_down_thres, show_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001081a8 size=1
// signature: undefined kstrtouint(void)
// callers: [store_io_percent, store_bw_step, store_up_scale, store_ab_scale, store_guard_band_mbps, store_idle_mbps, store_throttle_adj, store_second_vote_limit, store_min_freq, store_down_count, store_max_freq, store_idle_length, store_hist_memory, store_up_thres, store_hyst_trigger_count, store_hyst_length, store_down_thres, store_mbps_zones, store_window_ms, store_decay_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001081b0 size=1
// signature: undefined kstrtoint(void)
// callers: [store_sample_ms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// argv_split @ 001081b8 size=1
// signature: undefined argv_split(void)
// callers: [store_mbps_zones]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void argv_split(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// argv_free @ 001081c0 size=1
// signature: undefined argv_free(void)
// callers: [store_mbps_zones]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void argv_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



