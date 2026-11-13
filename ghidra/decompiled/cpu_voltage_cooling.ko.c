// Decompiled by Ghidra 12.2
// Program: cpu_voltage_cooling.ko
// Image base: 00100000

//------------------------------------------------------------
// cc_cooling_probe @ 001001a4 size=2720
// signature: undefined cc_cooling_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong cc_cooling_probe(long param_1)

{
  undefined4 uVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  long lVar13;
  long lVar14;
  undefined8 *puVar15;
  undefined4 *puVar16;
  undefined8 uVar17;
  int iVar18;
  int *piVar19;
  undefined **ppuVar20;
  ulong uVar21;
  uint uVar22;
  long lVar23;
  uint uVar24;
  ulong uVar25;
  long lVar26;
  uint *puVar27;
  int iVar28;
  uint uVar29;
  ulong uVar30;
  ulong uVar31;
  undefined8 *puVar32;
  ulong uVar33;
  uint *puVar34;
  long local_108;
  long local_100;
  long local_e0;
  long local_d8;
  undefined8 local_d0;
  long local_c8 [10];
  uint local_78;
  uint local_74;
  long local_70;
  
  lVar14 = sp_el0;
  local_70 = *(long *)(lVar14 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  local_d0 = 0xffffffffffffffff;
  puVar12 = (undefined8 *)of_get_next_available_child(uVar11,0);
  if (puVar12 == (undefined8 *)0x0) {
    puVar32 = (undefined8 *)0x0;
LAB_00100be0:
    lVar14 = sp_el0;
    if (*(long *)(lVar14 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return (ulong)puVar32 & 0xffffffff;
  }
  bVar2 = false;
  uVar33 = 0;
LAB_00100244:
  iVar6 = of_count_phandle_with_args(puVar12,"qcom,cluster0",0);
  if (0 < iVar6) {
    iVar28 = 0;
    do {
      local_c8[8] = 0;
      local_c8[9] = 0;
      local_c8[6] = 0;
      local_c8[7] = 0;
      local_c8[4] = 0;
      local_c8[5] = 0;
      local_c8[2] = 0;
      local_c8[3] = 0;
      local_c8[0] = 0;
      local_c8[1] = 0;
      iVar7 = __of_parse_phandle_with_args(puVar12,"qcom,cluster0",0,0,iVar28,local_c8);
      iVar18 = 0;
      lVar14 = local_c8[0];
      if (iVar7 != 0) {
        lVar14 = 0;
      }
      while (uVar8 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar18),
            uVar8 < _nr_cpu_ids) {
        lVar13 = get_cpu_device(uVar8);
        if ((lVar13 != 0) && (*(long *)(lVar13 + 0x2e8) == lVar14)) {
          if (1 < uVar33) goto LAB_00100c3c;
          bVar2 = true;
          *(uint *)((long)local_c8 + uVar33 * 4 + -8) = uVar8;
          uVar33 = uVar33 + 1;
          goto LAB_0010031c;
        }
        iVar18 = uVar8 + 1;
      }
      if (bVar2) break;
      bVar2 = false;
      iVar28 = iVar28 + 1;
    } while (iVar28 != iVar6);
  }
LAB_0010031c:
  iVar6 = of_count_phandle_with_args(puVar12,"qcom,cluster1",0);
  if (0 < iVar6) {
    iVar28 = 0;
    do {
      local_c8[8] = 0;
      local_c8[9] = 0;
      local_c8[6] = 0;
      local_c8[7] = 0;
      local_c8[4] = 0;
      local_c8[5] = 0;
      local_c8[2] = 0;
      local_c8[3] = 0;
      local_c8[0] = 0;
      local_c8[1] = 0;
      iVar7 = __of_parse_phandle_with_args(puVar12,"qcom,cluster1",0,0,iVar28,local_c8);
      iVar18 = 0;
      lVar14 = local_c8[0];
      if (iVar7 != 0) {
        lVar14 = 0;
      }
      while (uVar8 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar18),
            uVar8 < _nr_cpu_ids) {
        lVar13 = get_cpu_device(uVar8);
        if ((lVar13 != 0) && (*(long *)(lVar13 + 0x2e8) == lVar14)) {
          if (1 < uVar33) {
LAB_00100c3c:
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100c40);
            (*pcVar5)();
          }
          *(uint *)((long)local_c8 + uVar33 * 4 + -8) = uVar8;
          uVar33 = uVar33 + 1;
          break;
        }
        iVar18 = uVar8 + 1;
      }
      if ((bVar2) && (uVar33 == 2)) goto LAB_00100474;
      if ((!bVar2) && (uVar33 == 1)) goto LAB_00100410;
      iVar28 = iVar28 + 1;
    } while (iVar28 != iVar6);
  }
  if (uVar33 == 2) {
LAB_00100474:
    mutex_lock(cc_list_lock);
    uVar33 = local_d0;
    uVar8 = (uint)local_d0;
    if ((undefined **)cc_cdev_list != &cc_cdev_list) {
      ppuVar20 = (undefined **)cc_cdev_list;
      do {
        if (((uint)local_d0 == *(uint *)(ppuVar20 + 3) &&
             local_d0._4_4_ == *(uint *)((long)ppuVar20 + 0x1c)) ||
           (((uint)local_d0 == *(uint *)((long)ppuVar20 + 0x1c) &&
            (local_d0._4_4_ == *(uint *)(ppuVar20 + 3))))) goto LAB_001004cc;
        ppuVar20 = (undefined **)*ppuVar20;
      } while (ppuVar20 != &cc_cdev_list);
    }
    lVar14 = cpufreq_cpu_get(local_d0 & 0xffffffff);
    if (lVar14 == 0) {
      _printk(&DAT_0010132d,"cpu_voltage_cooling","cc_init",uVar33 & 0xffffffff);
      mutex_unlock(cc_list_lock);
      puVar32 = (undefined8 *)0xfffffdfb;
      uVar33 = 2;
    }
    else {
      uVar29 = local_d0._4_4_;
      uVar30 = (ulong)local_d0._4_4_;
      if ((*(ulong *)(lVar14 + ((ulong)(local_d0._4_4_ >> 3) & 0x1ffffff8) + 8) >> (uVar30 & 0x3f) &
          1) == 0) {
        cpufreq_cpu_put(lVar14);
        local_e0 = 0;
        local_d8 = 0;
        lVar14 = get_cpu_device(uVar33 & 0xffffffff);
        if (lVar14 == 0) {
          uVar30 = uVar33 & 0xffffffff;
LAB_00100858:
          _printk(&DAT_0010125c,"cpu_voltage_cooling","opp_init",uVar30);
          puVar32 = (undefined8 *)0xffffffffffffffed;
        }
        else {
          lVar13 = get_cpu_device(uVar30);
          if (lVar13 == 0) goto LAB_00100858;
          uVar9 = fetch_opp_table(lVar14,&local_d8);
          uVar24 = uVar9 - 1;
          local_78 = uVar9;
          if ((int)uVar9 < 1) {
            puVar32 = (undefined8 *)0xfffffffffffffff4;
          }
          else {
            uVar10 = fetch_opp_table(lVar13,&local_e0);
            local_74 = uVar10;
            if (0 < (int)uVar10) {
              puVar15 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,200);
              lVar13 = local_d8;
              lVar14 = local_e0;
              if (puVar15 != (undefined8 *)0x0) {
                local_c8[0] = local_d8;
                local_c8[1] = local_e0;
                iVar6 = *(int *)(local_d8 + (ulong)uVar24 * 0x10 + 8);
                iVar28 = *(int *)(local_e0 + (ulong)(uVar10 - 1) * 0x10 + 8);
                if (iVar6 < 1) {
                  iVar6 = 0;
                }
                if ((iVar6 < iVar28) || ((iVar6 == iVar28 && (uVar9 < uVar10)))) {
                  local_108 = 1;
                  local_100 = 0;
                  uVar24 = uVar10 - 1;
                  uVar22 = uVar8;
                  uVar8 = uVar29;
                  uVar9 = uVar10;
                }
                else {
                  local_108 = 0;
                  local_100 = 1;
                  uVar22 = uVar29;
                }
                uVar30 = (ulong)uVar9;
                uVar33 = uVar30 << 4;
                puVar27 = (uint *)(puVar15 + 3);
                *puVar27 = uVar8;
                *(uint *)(puVar15 + 2) = uVar24;
                *(undefined4 *)((long)puVar15 + 0x14) = 0;
                puVar34 = (uint *)((long)puVar15 + 0x1c);
                *puVar34 = uVar22;
                lVar26 = __kmalloc(uVar33,0xdc0);
                if (lVar26 != 0) {
                  _printk(&DAT_00101314,"cpu_voltage_cooling","build_unified_table",uVar8,uVar22);
                  uVar31 = 0;
                  uVar21 = (ulong)(*(int *)((ulong)&local_78 | local_100 << 2) - 1);
                  do {
                    uVar29 = (uint)uVar21;
                    if (uVar31 == uVar30) break;
                    uVar25 = uVar31 * 0x10;
                    if (uVar33 <= uVar25) goto LAB_00100c38;
                    puVar32 = (undefined8 *)(local_c8[local_108] + (ulong)uVar24 * 0x10);
                    uVar17 = puVar32[1];
                    lVar23 = local_c8[local_100];
                    *(undefined8 *)(lVar26 + uVar25) = *puVar32;
                    if (-1 < (int)uVar29) {
                      do {
                        uVar29 = (uint)uVar21;
                        if (*(ulong *)(lVar23 + uVar21 * 0x10 + 8) <= (ulong)(long)(int)uVar17)
                        goto LAB_001009e8;
                        uVar21 = (ulong)(uVar29 - 1);
                      } while (0 < (int)uVar29);
                      uVar29 = 0xffffffff;
                    }
LAB_001009e8:
                    if (uVar33 < (uVar25 | 8)) goto LAB_00100c38;
                    if ((int)uVar29 < 1) {
                      uVar29 = 0;
                    }
                    uVar21 = (ulong)uVar29;
                    ((undefined8 *)(lVar26 + uVar25))[1] = *(undefined8 *)(lVar23 + uVar21 * 0x10);
                    _printk(&DAT_0010127a,"cpu_voltage_cooling","build_unified_table");
                    uVar31 = uVar31 + 1;
                    uVar24 = uVar24 - 1;
                  } while (uVar31 != uVar30);
                  puVar15[4] = lVar26;
                  kfree(lVar13);
                  kfree(lVar14);
                  puVar32 = puVar15;
                  if ((undefined8 *)0xfffffffffffff000 < puVar15) goto LAB_001008c4;
                  lVar14 = cpufreq_cpu_get(uVar8);
                  if (lVar14 == 0) {
LAB_00100b80:
                    _printk(&DAT_00101353,"cpu_voltage_cooling","cc_init",*puVar27);
                    puVar32 = (undefined8 *)0xffffffed;
                  }
                  else {
                    uVar33 = freq_qos_add_request
                                       (lVar14 + 0xa0,puVar15 + 5,2,*(undefined4 *)puVar15[4]);
                    cpufreq_cpu_put(lVar14);
                    if (-1 < (int)uVar33) {
                      lVar14 = cpufreq_cpu_get(*puVar34);
                      puVar27 = puVar34;
                      if (lVar14 == 0) goto LAB_00100b80;
                      uVar33 = freq_qos_add_request
                                         (lVar14 + 0xa0,puVar15 + 0xd,2,
                                          *(undefined4 *)(puVar15[4] + 8));
                      cpufreq_cpu_put(lVar14);
                      if (-1 < (int)uVar33) {
                        scnprintf(puVar15 + 0x15,0x14,*puVar12);
                        uVar17 = thermal_of_cooling_device_register
                                           (puVar12,puVar15 + 0x15,puVar15,&cc_cooling_ops);
                        puVar15[0x18] = uVar17;
                        puVar3 = cc_cdev_list;
                        uVar33 = __list_add_valid(puVar15,&cc_cdev_list,cc_cdev_list);
                        if ((uVar33 & 1) != 0) {
                          *(undefined8 **)(puVar3 + 8) = puVar15;
                          *puVar15 = puVar3;
                          puVar15[1] = &cc_cdev_list;
                          cc_cdev_list = (undefined *)puVar15;
                        }
LAB_001004cc:
                        mutex_unlock(cc_list_lock);
                        puVar32 = (undefined8 *)0x0;
                        uVar33 = 2;
                        goto LAB_00100230;
                      }
                    }
                    puVar32 = (undefined8 *)(uVar33 & 0xffffffff);
                    _printk(&DAT_001012b7,"cpu_voltage_cooling","cc_init",*puVar27,puVar32);
                  }
                  mutex_unlock(cc_list_lock);
                  freq_qos_remove_request(puVar15 + 5);
                  freq_qos_remove_request(puVar15 + 0xd);
                  kfree(puVar15[4]);
                  kfree(puVar15);
                  uVar33 = 2;
                  goto LAB_00100230;
                }
                kfree(puVar15[4]);
                kfree(puVar15);
              }
              kfree(lVar14);
            }
            kfree(local_d8);
            puVar32 = (undefined8 *)0xfffffffffffffdfb;
          }
        }
LAB_001008c4:
        mutex_unlock(cc_list_lock);
        uVar33 = 2;
      }
      else {
        _printk(&DAT_001013c9,"cpu_voltage_cooling","cc_init",uVar33 & 0xffffffff,uVar30);
        cpufreq_cpu_put(lVar14);
        mutex_unlock(cc_list_lock);
        puVar32 = (undefined8 *)0xffffffea;
        uVar33 = 2;
      }
    }
    goto LAB_00100230;
  }
  if (uVar33 != 0) {
LAB_00100410:
    uVar30 = local_d0;
    uVar4 = (uint)local_d0;
    lVar14 = cpufreq_cpu_get(local_d0 & 0xffffffff);
    if (lVar14 == 0) {
      _printk(&DAT_001011e0,"cpu_voltage_cooling","cc_init_single_cluster",uVar30 & 0xffffffff);
      puVar32 = (undefined8 *)0xfffffdfb;
      goto LAB_00100230;
    }
    puVar15 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,200);
    if (puVar15 != (undefined8 *)0x0) {
      if (*(long *)(lVar14 + 400) != 0) {
        uVar31 = 0;
        piVar19 = (int *)(*(long *)(lVar14 + 400) + 8);
        do {
          if (*piVar19 != -1) {
            iVar6 = (int)uVar31;
            if (*piVar19 == -2) goto LAB_001004e4;
            uVar31 = (ulong)(iVar6 + 1);
          }
          piVar19 = piVar19 + 3;
        } while( true );
      }
      goto LAB_00100778;
    }
    cpufreq_cpu_put(lVar14);
    goto LAB_00100224;
  }
  _dev_err(param_1 + 0x10,"No cluster available\n");
  puVar32 = (undefined8 *)0xffffffea;
  goto LAB_00100be0;
LAB_001004e4:
  if (iVar6 == 0) {
LAB_00100778:
    _printk(&DAT_0010138d,"cpu_voltage_cooling","cc_init_single_cluster",uVar30 & 0xffffffff);
    puVar32 = (undefined8 *)0x0;
LAB_00100910:
    cpufreq_cpu_put(lVar14);
    kfree(puVar15[4]);
    kfree(puVar15);
  }
  else {
    if (-1 < iVar6) {
      uVar30 = -(uVar31 >> 0x1f) & 0xfffffff000000000 | uVar31 << 4;
      puVar16 = (undefined4 *)__kmalloc(uVar30,0xdc0);
      if (puVar16 != (undefined4 *)0x0) {
        uVar25 = (long)iVar6 & 0xfffffffffffffff;
        uVar21 = 0;
        lVar13 = 0;
        if (((long)iVar6 & 0x800000000000000U) != 0) {
          uVar25 = 0x800000000000000;
        }
        iVar28 = iVar6 + -1;
        do {
          if (((uVar25 == 0) || ((long)uVar21 < 0)) || (uVar30 <= uVar21)) {
LAB_00100c38:
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x100c3c);
            (*pcVar5)();
          }
          lVar26 = (long)iVar28;
          uVar25 = uVar25 - 1;
          iVar28 = iVar28 + -1;
          if (*(int *)(lVar14 + 0x198) != 1) {
            lVar26 = lVar13;
          }
          lVar13 = lVar13 + 1;
          *(ulong *)((long)puVar16 + uVar21) =
               (ulong)*(uint *)(*(long *)(lVar14 + 400) + lVar26 * 0xc + 8);
          uVar21 = uVar21 + 0x10;
        } while (uVar31 * 0x10 != uVar21);
        uVar1 = *puVar16;
        puVar15[4] = puVar16;
        *(int *)(puVar15 + 2) = iVar6 + -1;
        *(undefined4 *)((long)puVar15 + 0x14) = 0;
        *(undefined4 *)(puVar15 + 3) = uVar4;
        uVar8 = freq_qos_add_request(lVar14 + 0xa0,puVar15 + 5,2,uVar1);
        if (-1 < (int)uVar8) {
          cpufreq_cpu_put(lVar14);
          scnprintf(puVar15 + 0x15,0x14,*puVar12);
          uVar30 = thermal_of_cooling_device_register
                             (puVar12,puVar15 + 0x15,puVar15,&cc_cooling_ops);
          puVar15[0x18] = uVar30;
          puVar3 = cc_cdev_list;
          if (uVar30 < 0xfffffffffffff001) {
            uVar30 = __list_add_valid(puVar15,&cc_cdev_list,cc_cdev_list);
            puVar32 = (undefined8 *)0x0;
            if ((uVar30 & 1) != 0) {
              *(undefined8 **)(puVar3 + 8) = puVar15;
              *puVar15 = puVar3;
              puVar15[1] = &cc_cdev_list;
              cc_cdev_list = (undefined *)puVar15;
            }
          }
          else {
            puVar32 = (undefined8 *)(uVar30 & 0xffffffff);
          }
          goto LAB_00100230;
        }
        puVar32 = (undefined8 *)(ulong)uVar8;
        _printk(&DAT_001012b7,"cpu_voltage_cooling","cc_init_single_cluster",
                *(undefined4 *)(puVar15 + 3),puVar32);
        freq_qos_remove_request(puVar15 + 5);
        goto LAB_00100910;
      }
    }
    cpufreq_cpu_put(lVar14);
    kfree(puVar15);
LAB_00100224:
    puVar32 = (undefined8 *)0xfffffff4;
  }
LAB_00100230:
  puVar12 = (undefined8 *)of_get_next_available_child(uVar11,puVar12);
  if (puVar12 == (undefined8 *)0x0) goto LAB_00100be0;
  goto LAB_00100244;
}



//------------------------------------------------------------
// cc_cooling_remove @ 00100c48 size=196
// signature: undefined cc_cooling_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cc_cooling_remove(void)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  mutex_lock(cc_list_lock);
  ppuVar4 = (undefined **)cc_cdev_list;
  if ((undefined **)cc_cdev_list != &cc_cdev_list) {
    do {
      ppuVar5 = (undefined **)*ppuVar4;
      if (ppuVar4[0x18] != (undefined *)0x0) {
        thermal_cooling_device_unregister();
      }
      uVar3 = __list_del_entry_valid(ppuVar4);
      if ((uVar3 & 1) != 0) {
        puVar1 = *ppuVar4;
        plVar2 = (long *)ppuVar4[1];
        *(long **)(puVar1 + 8) = plVar2;
        *plVar2 = (long)puVar1;
      }
      *ppuVar4 = (undefined *)0xdead000000000100;
      ppuVar4[1] = (undefined *)0xdead000000000122;
      freq_qos_remove_request(ppuVar4 + 5);
      freq_qos_remove_request(ppuVar4 + 0xd);
      kfree(ppuVar4[4]);
      kfree(ppuVar4);
      ppuVar4 = ppuVar5;
    } while (ppuVar5 != &cc_cdev_list);
  }
  mutex_unlock(cc_list_lock);
  return 0;
}



//------------------------------------------------------------
// fetch_opp_table @ 00100d0c size=356
// signature: undefined fetch_opp_table(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

ulong fetch_opp_table(undefined8 param_1,long *param_2)

{
  ulong uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = 0;
  uVar3 = dev_pm_opp_get_opp_count();
  uVar7 = (ulong)uVar3;
  if (0 < (int)uVar3) {
    uVar1 = uVar7 * 0x10;
    lVar4 = __kmalloc(uVar1,0xdc0);
    if (lVar4 == 0) {
      uVar7 = 0xfffffff4;
    }
    else {
      uVar8 = 0;
      do {
        uVar5 = dev_pm_opp_find_freq_ceil(param_1,&local_60);
        if (0xfffffffffffff000 < uVar5) {
          _printk(&DAT_001012f7,"cpu_voltage_cooling","fetch_opp_table");
          kfree(lVar4);
          uVar7 = 0xffffffea;
          goto LAB_00100e04;
        }
        if (uVar1 <= uVar8) {
LAB_00100e68:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x100e6c);
          (*pcVar2)();
        }
        *(ulong *)(lVar4 + uVar8) = local_60 / 1000;
        uVar6 = dev_pm_opp_get_voltage();
        if (uVar1 < uVar8 + 8) goto LAB_00100e68;
        *(ulong *)(lVar4 + uVar8 + 8) = uVar6 / 1000;
        dev_pm_opp_put(uVar5);
        uVar8 = uVar8 + 0x10;
        local_60 = local_60 + 1;
      } while (uVar1 != uVar8);
      *param_2 = lVar4;
    }
  }
LAB_00100e04:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// cc_get_max_state @ 00100e74 size=20
// signature: undefined cc_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cc_get_max_state(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x10);
  return 0;
}



//------------------------------------------------------------
// cc_get_cur_state @ 00100e8c size=20
// signature: undefined cc_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cc_get_cur_state(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x14);
  return 0;
}



//------------------------------------------------------------
// cc_set_cur_state @ 00100ea4 size=160
// signature: undefined cc_set_cur_state(void)
// callers: []
//------------------------------------------------------------

ulong cc_set_cur_state(long param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3b0);
  if ((ulong)(long)*(int *)(lVar3 + 0x10) < param_2) {
    return 0xffffffea;
  }
  if (((long)*(int *)(lVar3 + 0x14) != param_2) &&
     (*(int *)(lVar3 + 0x14) = (int)param_2, *(int *)(lVar3 + 0x18) != -1)) {
    uVar2 = freq_qos_update_request
                      (lVar3 + 0x28,*(undefined4 *)(*(long *)(lVar3 + 0x20) + param_2 * 0x10));
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (*(int *)(lVar3 + 0x1c) != -1) {
      uVar1 = freq_qos_update_request
                        (lVar3 + 0x68,*(undefined4 *)(*(long *)(lVar3 + 0x20) + param_2 * 0x10 + 8))
      ;
      if (-1 < (int)uVar1) {
        uVar1 = 0;
      }
      return (ulong)uVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100f48 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cc_cooling_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100f78 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cc_cooling_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// of_get_next_available_child @ 00103010 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_put @ 00103028 size=1
// signature: undefined cpufreq_cpu_put(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00103030 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103038 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00103040 size=1
// signature: undefined _find_next_bit(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 00103048 size=1
// signature: undefined get_cpu_device(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 00103050 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103060 size=1
// signature: undefined kmalloc_trace(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103068 size=1
// signature: undefined mutex_lock(void)
// callers: [cc_cooling_remove, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103070 size=1
// signature: undefined mutex_unlock(void)
// callers: [cc_cooling_remove, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103078 size=1
// signature: undefined __kmalloc(void)
// callers: [fetch_opp_table, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 00103080 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103088 size=1
// signature: undefined scnprintf(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 00103090 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103098 size=1
// signature: undefined kfree(void)
// callers: [fetch_opp_table, cc_cooling_remove, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001030a0 size=1
// signature: undefined __list_add_valid(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030a8 size=1
// signature: undefined _printk(void)
// callers: [fetch_opp_table, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_remove_request @ 001030b0 size=1
// signature: undefined freq_qos_remove_request(void)
// callers: [cc_cooling_remove, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030b8 size=1
// signature: undefined _dev_err(void)
// callers: [cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [fetch_opp_table, cc_cooling_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 001030c8 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [cc_cooling_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030d0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cc_cooling_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_get_opp_count @ 001030d8 size=1
// signature: undefined dev_pm_opp_get_opp_count(void)
// callers: [fetch_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_get_opp_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_ceil @ 001030e0 size=1
// signature: undefined dev_pm_opp_find_freq_ceil(void)
// callers: [fetch_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_ceil(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_get_voltage @ 001030e8 size=1
// signature: undefined dev_pm_opp_get_voltage(void)
// callers: [fetch_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_put @ 001030f0 size=1
// signature: undefined dev_pm_opp_put(void)
// callers: [fetch_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_update_request @ 001030f8 size=1
// signature: undefined freq_qos_update_request(void)
// callers: [cc_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



