// Decompiled by Ghidra 12.2
// Program: msm_lmh_dcvs.ko
// Image base: 00100000

//------------------------------------------------------------
// limits_dcvs_probe @ 0010025c size=1396
// signature: undefined limits_dcvs_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void limits_dcvs_probe(long param_1)

{
  ulong *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  char *param0;
  undefined8 uVar11;
  long lVar12;
  uint *puVar13;
  undefined *puVar14;
  long lVar15;
  int *extraout_x13;
  long lVar16;
  ulong uVar17;
  long lVar18;
  undefined8 uStack_148;
  ulong uStack_140;
  long lStack_138;
  ulong *puStack_130;
  undefined1 *puStack_128;
  int local_c4;
  ulong local_c0 [12];
  
  lVar15 = sp_el0;
  local_c0[0xb] = *(long *)(lVar15 + 0x638);
  lVar15 = 0;
  lVar16 = *(long *)(param_1 + 0x2f8);
  local_c4 = -1;
  local_c0[0] = 0;
  while (uVar10 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar15),
        (uint)uVar10 < _nr_cpu_ids) {
    lVar15 = get_cpu_device(uVar10 & 0xffffffff);
    if (lVar15 == 0) {
      lVar15 = of_get_cpu_node(uVar10 & 0xffffffff,0);
    }
    else {
      lVar15 = *(long *)(lVar15 + 0x2e8);
    }
    if (lVar15 != 0) {
      local_c0[9] = 0;
      local_c0[10] = 0;
      local_c0[7] = 0;
      local_c0[8] = 0;
      local_c0[5] = 0;
      local_c0[6] = 0;
      local_c0[3] = 0;
      local_c0[4] = 0;
      local_c0[1] = 0;
      local_c0[2] = 0;
      iVar7 = __of_parse_phandle_with_args(lVar15,"qcom,lmh-dcvs",0,0,0,local_c0 + 1);
      uVar17 = local_c0[1];
      if (iVar7 != 0) {
        uVar17 = 0;
      }
      if (uVar17 == lVar16) {
        puVar1 = local_c0 + (uVar10 >> 6 & 0x3ffffff);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar5) {
            *puVar1 = *puVar1 | 1L << (uVar10 & 0x3f);
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
    }
    lVar15 = uVar10 + 1;
  }
  lVar15 = param_1 + 0x10;
  param0 = (char *)devm_kmalloc(lVar15,0x250,0xdc0);
  if (param0 == (char *)0x0) {
LAB_001004fc:
    uVar11 = 0xfffffff4;
    goto LAB_00100500;
  }
  uVar17 = (ulong)_nr_cpu_ids;
  uVar10 = _find_first_bit(local_c0,uVar17);
  if (uVar10 == uVar17) {
    limits_isens_qref_init(param_1,param0,0,"isens_vref_1p8","isens-vref-1p8-settings");
    limits_isens_qref_init(param_1,param0,1,"isens_vref_0p8","isens-vref-0p8-settings");
LAB_001003f8:
    mutex_lock(&lmh_dcvs_list_access);
    pcVar2 = param0 + 0x1e8;
    *(char **)(param0 + 0x1e8) = pcVar2;
    *(char **)(param0 + 0x1f0) = pcVar2;
    puVar14 = PTR_lmh_dcvs_hw_list_00100ef8;
    uVar10 = __list_add_valid(pcVar2,PTR_lmh_dcvs_hw_list_00100ef8,&lmh_dcvs_hw_list);
    if ((uVar10 & 1) != 0) {
      PTR_lmh_dcvs_hw_list_00100ef8 = pcVar2;
      *(undefined ***)(param0 + 0x1e8) = &lmh_dcvs_hw_list;
      *(undefined **)(param0 + 0x1f0) = puVar14;
      *(char **)puVar14 = pcVar2;
    }
    mutex_unlock(&lmh_dcvs_list_access);
    uVar11 = 0;
  }
  else {
    uVar10 = __bitmap_weight(local_c0,_nr_cpu_ids);
    lVar12 = devm_kmalloc(lVar15,(uVar10 & 0xffffffff) << 4,0xdc0);
    *(long *)(param0 + 0x230) = lVar12;
    if (lVar12 == 0) goto LAB_001004fc;
    uVar8 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
    if (8 < uVar8) {
      lVar16 = fortify_panic("memcpy");
      *extraout_x13 = *extraout_x13 + (int)lVar16;
      LORelease();
      puStack_128 = &UNK_001007e0;
      lVar15 = sp_el0;
      lStack_138 = *(long *)(lVar15 + 0x638);
      puStack_130 = local_c0 + 0xc;
      mutex_lock(lVar16 + 0x1c8);
      if (*(long *)(lVar16 + 0x88) == 0xffffffff) {
        iVar7 = 0;
        uVar8 = 0;
        uStack_148 = 0;
        uStack_140 = 0xffffffff;
        while (uVar9 = _find_next_bit(lVar16 + -8,_nr_cpu_ids,iVar7), uVar9 < _nr_cpu_ids) {
          uStack_148 = 0;
          uStack_140 = 0xffffffff;
          lVar15 = get_cpu_device(uVar9);
          if (lVar15 == 0) {
            _printk(&DAT_001013cd,"msm_lmh_dcvs","limits_dcvs_get_freq_limits",uVar9);
          }
          else {
            dev_pm_opp_find_freq_floor(lVar15,&uStack_140);
            dev_pm_opp_find_freq_ceil(lVar15,&uStack_148);
            if (0x1f < uVar8) goto LAB_001009d8;
            *(ulong *)(lVar16 + -0x38 + (ulong)uVar8 * 8 + 0xc0) = uStack_140 / 1000;
          }
          uVar8 = uVar8 + 1;
          iVar7 = uVar9 + 1;
        }
      }
      uVar10 = limits_mitigation_notify(lVar16 + -0x38);
      uVar8 = 0;
      iVar7 = 0;
      lVar15 = 0x88;
      while( true ) {
        uVar9 = _find_next_bit(lVar16 + -8,_nr_cpu_ids,(long)iVar7);
        if (_nr_cpu_ids <= uVar9) {
          uVar11 = __bitmap_weight(lVar16 + -8);
          if (uVar8 < (uint)uVar11) {
            mod_delayed_work_on(0x20,_system_highpri_wq,lVar16,3);
          }
          else {
            writel_relaxed(uVar11,*(undefined8 *)(lVar16 + -0x10));
            *(undefined1 *)(lVar16 + 0x1c0) = 1;
            enable_irq(*(undefined4 *)(lVar16 + -0x20));
          }
          mutex_unlock(lVar16 + 0x1c8);
          lVar15 = sp_el0;
          if (*(long *)(lVar15 + 0x638) != lStack_138) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return;
        }
        if (lVar15 == 0x188) break;
        puVar1 = (ulong *)(lVar16 + lVar15);
        lVar15 = lVar15 + 8;
        iVar7 = uVar9 + 1;
        if (*puVar1 <= uVar10) {
          uVar8 = uVar8 + 1;
        }
      }
LAB_001009d8:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1009dc);
      (*pcVar6)();
    }
    memcpy(param0 + 0x30,local_c0,(ulong)uVar8);
    lVar18 = 0;
    iVar7 = 0;
    lVar12 = 0xc0;
    param0[0x238] = '\0';
    param0[0x239] = '\0';
    param0[0x23a] = '\0';
    param0[0x23b] = '\0';
    while (uVar8 = _find_next_bit(param0 + 0x30,_nr_cpu_ids,(long)iVar7), uVar8 < _nr_cpu_ids) {
      *(undefined8 *)(*(long *)(param0 + 0x230) + lVar18) = 0;
      *(undefined4 *)(*(long *)(param0 + 0x230) + lVar18 + 8) = 0xffffffff;
      if (lVar12 == 0x1c0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1007d0);
        (*pcVar6)();
      }
      pcVar2 = param0 + lVar12;
      pcVar2[0] = -1;
      pcVar2[1] = -1;
      pcVar2[2] = -1;
      pcVar2[3] = -1;
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      iVar7 = uVar8 + 1;
      lVar12 = lVar12 + 8;
      lVar18 = lVar18 + 0x10;
    }
    iVar7 = of_property_read_variable_u32_array(lVar16,"qcom,affinity",&local_c4,1,0);
    if (iVar7 < 0) {
      uVar11 = 0xffffffed;
      goto LAB_00100500;
    }
    uVar3 = 0x6370302d;
    if (local_c4 == 0) {
LAB_00100574:
      *(undefined4 *)(param0 + 0x14) = uVar3;
      puVar13 = (uint *)__of_get_address(lVar16,0,0xffffffff,0,0);
      if (puVar13 == (uint *)0x0) {
        puVar14 = &DAT_001010c4;
      }
      else {
        uVar8 = *puVar13;
        puVar13 = (uint *)__of_get_address(lVar16,1,0xffffffff,0,0);
        if (puVar13 != (uint *)0x0) {
          uVar9 = (*puVar13 & 0xff00ff00) >> 8 | (*puVar13 & 0xff00ff) << 8;
          param0[0x1c0] = -1;
          param0[0x1c1] = -1;
          param0[0x1c2] = -1;
          param0[0x1c3] = -1;
          param0[0x1c4] = '\0';
          param0[0x1c5] = '\0';
          param0[0x1c6] = '\0';
          param0[0x1c7] = '\0';
          snprintf(param0,0x14,"limits_sensor-%02d",local_c4);
          __mutex_init(param0 + 0x200,"&hw->access_lock",&limits_dcvs_probe___key);
          param0[0x38] = -0x20;
          param0[0x39] = -1;
          param0[0x3a] = -1;
          param0[0x3b] = -1;
          param0[0x3c] = '\x0f';
          param0[0x3d] = '\0';
          param0[0x3e] = '\0';
          param0[0x3f] = '\0';
          *(char **)(param0 + 0x40) = param0 + 0x40;
          *(char **)(param0 + 0x48) = param0 + 0x40;
          *(code **)(param0 + 0x50) = limits_dcvs_poll;
          init_timer_key(param0 + 0x68,&delayed_work_timer_fn,0x280000,0,0);
          lVar16 = devm_ioremap(lVar15,(uVar9 >> 0x10 | uVar9 << 0x10) + 0x704,4);
          *(long *)(param0 + 0x20) = lVar16;
          if (lVar16 == 0) {
            puVar14 = &DAT_00101331;
          }
          else {
            uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
            lVar16 = devm_ioremap(lVar15,(uVar8 >> 0x10 | uVar8 << 0x10) + 8,4);
            *(long *)(param0 + 0x28) = lVar16;
            if (lVar16 != 0) {
              iVar7 = of_irq_get(*(undefined8 *)(param_1 + 0x2f8),0);
              *(int *)(param0 + 0x18) = iVar7;
              if (iVar7 < 0) {
                _printk(&DAT_0010136f,"msm_lmh_dcvs","limits_dcvs_probe",iVar7);
              }
              else {
                param0[0x1f8] = '\x01';
                iVar7 = devm_request_threaded_irq
                                  (lVar15,iVar7,0,lmh_dcvs_handle_isr,0x6084,param0,param0);
                if (iVar7 == 0) {
                  limits_isens_qref_init
                            (param_1,param0,0,"isens_vref_1p8","isens-vref-1p8-settings");
                  limits_isens_qref_init
                            (param_1,param0,1,"isens_vref_0p8","isens-vref-0p8-settings");
                  *(char **)(param0 + 0x1c8) = "lmh_freq_limit";
                  *(code **)(param0 + 0x1d8) = lmh_freq_limit_show;
                  param0[0x1d0] = '$';
                  param0[0x1d1] = '\x01';
                  device_create_file(lVar15,param0 + 0x1c8);
                }
                else {
                  _printk(&DAT_001010ee,"msm_lmh_dcvs","limits_dcvs_probe",iVar7);
                }
              }
              goto LAB_001003f8;
            }
            puVar14 = &DAT_00101250;
          }
          _printk(puVar14,"msm_lmh_dcvs","limits_dcvs_probe");
          goto LAB_001003f8;
        }
        puVar14 = &DAT_001011e8;
      }
      _printk(puVar14,"msm_lmh_dcvs","limits_dcvs_probe");
    }
    else if (local_c4 == 1) {
      uVar3 = 0x6370312d;
      goto LAB_00100574;
    }
    uVar11 = 0xffffffea;
  }
LAB_00100500:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_c0[0xb]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// limits_dcvs_poll @ 001007e4 size=508
// signature: undefined limits_dcvs_poll(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void limits_dcvs_poll(long param_1)

{
  ulong *puVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 local_78;
  ulong local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  mutex_lock(param_1 + 0x1c8);
  if (*(long *)(param_1 + 0x88) == 0xffffffff) {
    iVar7 = 0;
    uVar8 = 0;
    local_78 = 0;
    local_70 = 0xffffffff;
    while (uVar3 = _find_next_bit(param_1 + -8,_nr_cpu_ids,iVar7), uVar3 < _nr_cpu_ids) {
      local_78 = 0;
      local_70 = 0xffffffff;
      lVar4 = get_cpu_device(uVar3);
      if (lVar4 == 0) {
        _printk(&DAT_001013cd,"msm_lmh_dcvs","limits_dcvs_get_freq_limits",uVar3);
      }
      else {
        dev_pm_opp_find_freq_floor(lVar4,&local_70);
        dev_pm_opp_find_freq_ceil(lVar4,&local_78);
        if (0x1f < uVar8) goto LAB_001009d8;
        *(ulong *)(param_1 + -0x38 + (ulong)uVar8 * 8 + 0xc0) = local_70 / 1000;
      }
      uVar8 = uVar8 + 1;
      iVar7 = uVar3 + 1;
    }
  }
  uVar5 = limits_mitigation_notify(param_1 + -0x38);
  uVar8 = 0;
  iVar7 = 0;
  lVar4 = 0x88;
  while( true ) {
    uVar3 = _find_next_bit(param_1 + -8,_nr_cpu_ids,(long)iVar7);
    if (_nr_cpu_ids <= uVar3) {
      uVar6 = __bitmap_weight(param_1 + -8);
      if (uVar8 < (uint)uVar6) {
        mod_delayed_work_on(0x20,_system_highpri_wq,param_1,3);
      }
      else {
        writel_relaxed(uVar6,*(undefined8 *)(param_1 + -0x10));
        *(undefined1 *)(param_1 + 0x1c0) = 1;
        enable_irq(*(undefined4 *)(param_1 + -0x20));
      }
      mutex_unlock(param_1 + 0x1c8);
      lVar4 = sp_el0;
      if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (lVar4 == 0x188) break;
    puVar1 = (ulong *)(param_1 + lVar4);
    lVar4 = lVar4 + 8;
    iVar7 = uVar3 + 1;
    if (*puVar1 <= uVar5) {
      uVar8 = uVar8 + 1;
    }
  }
LAB_001009d8:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1009dc);
  (*pcVar2)();
}



//------------------------------------------------------------
// lmh_dcvs_handle_isr @ 001009e4 size=112
// signature: undefined lmh_dcvs_handle_isr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lmh_dcvs_handle_isr(undefined8 param_1,long param_2)

{
  mutex_lock(param_2 + 0x200);
  if (*(char *)(param_2 + 0x1f8) != '\0') {
    *(undefined1 *)(param_2 + 0x1f8) = 0;
    disable_irq_nosync(*(undefined4 *)(param_2 + 0x18));
    limits_mitigation_notify(param_2);
    mod_delayed_work_on(0x20,_system_highpri_wq,param_2 + 0x38,3);
  }
  mutex_unlock(param_2 + 0x200);
  return 1;
}



//------------------------------------------------------------
// lmh_freq_limit_show @ 00100a58 size=52
// signature: undefined lmh_freq_limit_show(void)
// callers: []
//------------------------------------------------------------

long lmh_freq_limit_show(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101119,*(undefined8 *)(param_2 + -8));
  return (long)iVar1;
}



//------------------------------------------------------------
// limits_isens_qref_init @ 00100a8c size=364
// signature: undefined limits_isens_qref_init(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

void limits_isens_qref_init
               (long param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_48 = 0;
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),param_5,&local_48,3,0);
  if (-1 < iVar3) {
    iVar3 = 0;
  }
  if (iVar3 != -0x16) {
    if (iVar3 == 0) {
      uVar4 = devm_regulator_get(param_1 + 0x10,param_4);
      param_2 = param_2 + (ulong)param_3 * 8;
      *(ulong *)(param_2 + 0x240) = uVar4;
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        _printk(&DAT_0010114e,"msm_lmh_dcvs","limits_isens_qref_init");
        goto LAB_00100b48;
      }
      iVar3 = regulator_set_voltage(uVar4,local_48 & 0xffffffff,local_48._4_4_);
      if (iVar3 == 0) {
        puVar1 = (undefined8 *)(param_2 + 0x240);
        iVar3 = regulator_set_load(*puVar1,local_40);
        if (iVar3 == 0) {
          iVar3 = regulator_enable(*puVar1);
          if (iVar3 != 0) {
            _printk(&DAT_0010127a,"msm_lmh_dcvs","limits_isens_qref_init");
          }
          goto LAB_00100b48;
        }
        puVar5 = &DAT_0010111e;
      }
      else {
        puVar5 = &DAT_001012fe;
      }
    }
    else {
      puVar5 = &DAT_0010117b;
    }
    _printk(puVar5,"msm_lmh_dcvs","limits_isens_qref_init",iVar3);
  }
LAB_00100b48:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// limits_mitigation_notify @ 00100bf8 size=456
// signature: undefined limits_mitigation_notify(void)
// callers: [lmh_dcvs_handle_isr, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong limits_mitigation_notify(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_70 = 0;
  uVar4 = readl_relaxed(*(undefined8 *)(param_1 + 0x20));
  lVar1 = param_1 + 0x30;
  uVar10 = (ulong)((uVar4 & 0x3ff) * 0x4b00);
  lVar11 = 0;
  iVar5 = 0;
  uVar12 = 0;
  while( true ) {
    uVar4 = _find_next_bit(lVar1,_nr_cpu_ids,iVar5);
    uVar8 = uVar10;
    if (_nr_cpu_ids <= uVar4) break;
    lVar6 = get_cpu_device(uVar4);
    if (lVar6 == 0) {
      uVar9 = _find_first_bit(lVar1,_nr_cpu_ids);
      _printk(&DAT_001013cd,"msm_lmh_dcvs","limits_mitigation_notify",uVar9);
      goto LAB_00100d48;
    }
    local_70 = uVar10 * 1000;
    lVar7 = dev_pm_opp_find_freq_floor(lVar6,&local_70);
    if ((lVar7 == -0x22) &&
       (uVar8 = dev_pm_opp_find_freq_ceil(lVar6,&local_70), 0xfffffffffffff000 < uVar8)) {
      _dev_err(lVar6,"frequency:%lu. opp error:%ld\n",local_70,uVar8);
    }
    if (lVar11 == 0x20) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100d2c);
      (*pcVar3)();
    }
    uVar8 = local_70 / 1000;
    if (uVar8 != *(ulong *)(param_1 + 0xc0 + lVar11 * 8)) break;
    lVar11 = lVar11 + 1;
    uVar2 = (uint)uVar8;
    if (uVar8 <= uVar12) {
      uVar2 = (uint)uVar12;
    }
    uVar12 = (ulong)uVar2;
    iVar5 = uVar4 + 1;
  }
  iVar5 = __bitmap_weight(lVar1,_nr_cpu_ids);
  uVar10 = uVar12;
  if (iVar5 != (int)lVar11) {
    uVar10 = uVar8;
  }
LAB_00100d48:
  *(ulong *)(param_1 + 0x1c0) = uVar10;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// writel_relaxed @ 00100dc0 size=128
// signature: undefined writel_relaxed(void)
// callers: [limits_dcvs_poll]
//------------------------------------------------------------

void writel_relaxed(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(0xff,0x20,param_2,writel_relaxed,uVar1);
  *param_2 = 0xff;
  log_post_write_mmio(0xff,0x20,param_2,0x100e10,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100e40 size=124
// signature: undefined readl_relaxed(void)
// callers: [limits_mitigation_notify]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100e88,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100ec4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&limits_dcvs_driver,&__this_module);
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
// _find_next_bit @ 00103018 size=1
// signature: undefined _find_next_bit(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 00103020 size=1
// signature: undefined get_cpu_device(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_cpu_node @ 00103028 size=1
// signature: undefined of_get_cpu_node(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_cpu_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00103048 size=1
// signature: undefined _find_first_bit(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103050 size=1
// signature: undefined mutex_lock(void)
// callers: [lmh_dcvs_handle_isr, limits_dcvs_probe, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103058 size=1
// signature: undefined __list_add_valid(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103060 size=1
// signature: undefined mutex_unlock(void)
// callers: [lmh_dcvs_handle_isr, limits_dcvs_probe, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00103068 size=1
// signature: undefined __bitmap_weight(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103070 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [limits_dcvs_probe, limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00103080 size=1
// signature: undefined __of_get_address(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103088 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103090 size=1
// signature: undefined __mutex_init(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001030a0 size=1
// signature: undefined init_timer_key(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001030a8 size=1
// signature: undefined devm_ioremap(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get @ 001030b0 size=1
// signature: undefined of_irq_get(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001030b8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001030c0 size=1
// signature: undefined device_create_file(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030c8 size=1
// signature: undefined _printk(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe, limits_dcvs_poll, limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030d0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [limits_mitigation_notify, limits_dcvs_probe, limits_dcvs_poll, limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030d8 size=1
// signature: undefined fortify_panic(void)
// callers: [limits_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_floor @ 001030e0 size=1
// signature: undefined dev_pm_opp_find_freq_floor(void)
// callers: [limits_mitigation_notify, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_floor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_ceil @ 001030e8 size=1
// signature: undefined dev_pm_opp_find_freq_ceil(void)
// callers: [limits_mitigation_notify, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_ceil(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_delayed_work_on @ 001030f8 size=1
// signature: undefined mod_delayed_work_on(void)
// callers: [lmh_dcvs_handle_isr, limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00103100 size=1
// signature: undefined enable_irq(void)
// callers: [limits_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00103108 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [lmh_dcvs_handle_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103110 size=1
// signature: undefined scnprintf(void)
// callers: [lmh_freq_limit_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00103118 size=1
// signature: undefined devm_regulator_get(void)
// callers: [limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00103120 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00103128 size=1
// signature: undefined regulator_set_load(void)
// callers: [limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00103130 size=1
// signature: undefined regulator_enable(void)
// callers: [limits_isens_qref_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103138 size=1
// signature: undefined _dev_err(void)
// callers: [limits_mitigation_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00103140 size=1
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
// log_post_write_mmio @ 00103148 size=1
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
// log_read_mmio @ 00103150 size=1
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
// log_post_read_mmio @ 00103158 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



