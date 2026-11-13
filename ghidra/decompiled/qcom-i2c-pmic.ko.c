// Decompiled by Ghidra 12.2
// Program: qcom-i2c-pmic.ko
// Image base: 00100000

//------------------------------------------------------------
// i2c_pmic_probe @ 001003ec size=1036
// signature: undefined i2c_pmic_probe(void)
// callers: []
//------------------------------------------------------------

int i2c_pmic_probe(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined *puVar7;
  long lVar8;
  ulong uVar9;
  undefined4 local_6c;
  long local_68;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x20;
  local_68 = *(long *)(lVar6 + 0x638);
  plVar5 = (long *)devm_kmalloc(lVar1,0x70,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar4 = -0xc;
    goto LAB_001004e0;
  }
  *plVar5 = lVar1;
  lVar6 = __devm_regmap_init_i2c(param_1,i2c_pmic_regmap_config,0,0);
  plVar5[1] = lVar6;
  if (lVar6 == 0) {
    iVar4 = -0x13;
    goto LAB_001004e0;
  }
  devm_regmap_qti_debugfs_register(*plVar5,lVar6);
  lVar6 = *plVar5;
  *(long **)(param_1 + 0xb8) = plVar5;
  *(undefined4 *)((long)plVar5 + 100) = 0xffffffea;
  lVar6 = of_find_property(*(undefined8 *)(lVar6 + 0x2e8),"interrupt-controller",0);
  if (lVar6 == 0) {
    iVar4 = 0;
LAB_00100520:
    of_platform_populate(*(undefined8 *)(*plVar5 + 0x2e8),0,0);
    _printk(&DAT_001022e7,"i2c_pmic_probe");
    goto LAB_001004e0;
  }
  lVar6 = 0;
  if (*(long *)(param_1 + 0x308) != 0) {
    lVar6 = *(long *)(param_1 + 0x308) + 0x18;
  }
  lVar6 = __irq_domain_add(lVar6,0,0xffffffffffffffff,0,i2c_pmic_domain_ops,plVar5);
  plVar5[2] = lVar6;
  if (lVar6 == 0) {
    iVar4 = -0xc;
    *(undefined8 *)(param_1 + 0xb8) = 0;
    goto LAB_001004e0;
  }
  local_6c = 0;
  lVar6 = *(long *)(*plVar5 + 0x2e8);
  if (lVar6 == 0) {
    puVar7 = &DAT_00102660;
LAB_00100564:
    _printk(puVar7,"i2c_pmic_parse_dt");
    iVar4 = -0x16;
LAB_00100574:
    puVar7 = &DAT_0010224b;
LAB_0010057c:
    _printk(puVar7,"i2c_pmic_probe",iVar4);
  }
  else {
    uVar3 = of_property_count_elems_of_size(lVar6,"qcom,periph-map",4);
    *(uint *)(plVar5 + 0xc) = uVar3;
    if (-1 < (int)uVar3) {
      if (uVar3 == 0) {
        puVar7 = &DAT_00102514;
        goto LAB_00100564;
      }
      lVar8 = devm_kmalloc(*plVar5,(ulong)uVar3 * 0x48,0xdc0);
      plVar5[3] = lVar8;
      if (lVar8 != 0) {
        if (0 < (int)plVar5[0xc]) {
          lVar8 = 0;
          uVar9 = 0;
          do {
            iVar4 = of_property_read_u32_index(lVar6,"qcom,periph-map",uVar9 & 0xffffffff,&local_6c)
            ;
            if (iVar4 < 0) {
              _printk(&DAT_0010236d,"i2c_pmic_parse_dt",uVar9 & 0xffffffff,iVar4);
              goto LAB_00100574;
            }
            *(short *)(plVar5[3] + lVar8 + 8) = (short)local_6c << 8;
            *(long **)(plVar5[3] + lVar8) = plVar5;
            __mutex_init(plVar5[3] + lVar8 + 0x18,"&chip->periph[i].lock",&i2c_pmic_parse_dt___key);
            uVar9 = uVar9 + 1;
            lVar8 = lVar8 + 0x48;
          } while ((long)uVar9 < (long)(int)plVar5[0xc]);
        }
        of_property_read_string(lVar6,"pinctrl-names",plVar5 + 0xb);
        lVar6 = of_find_property(lVar6,"qcom,enable-toggle-stat",0);
        *(bool *)((long)plVar5 + 0x6a) = lVar6 != 0;
        goto LAB_001006d4;
      }
      iVar4 = -0xc;
      goto LAB_00100574;
    }
    _printk(&DAT_001027e7,"i2c_pmic_parse_dt");
    iVar4 = (int)plVar5[0xc];
    if (iVar4 < 0) goto LAB_00100574;
LAB_001006d4:
    iVar4 = i2c_pmic_determine_initial_status(plVar5);
    if (iVar4 < 0) {
      puVar7 = &DAT_001027ae;
      goto LAB_0010057c;
    }
    if (plVar5[0xb] == 0) {
LAB_00100730:
      *(undefined1 *)(plVar5 + 0xd) = 1;
      __mutex_init(plVar5 + 5,"&chip->irq_complete",&i2c_pmic_probe___key);
      iVar4 = i2c_pmic_toggle_stat(plVar5);
      if (iVar4 < 0) {
        puVar7 = &DAT_001023b5;
        goto LAB_0010057c;
      }
      iVar4 = devm_request_threaded_irq
                        (lVar1,*(undefined4 *)(param_1 + 0x3b4),0,i2c_pmic_irq_handler,0x2080,
                         "i2c_pmic_stat_irq",plVar5);
      uVar2 = *(undefined4 *)(param_1 + 0x3b4);
      if (-1 < iVar4) {
        *(undefined4 *)((long)plVar5 + 100) = uVar2;
        irq_set_irq_wake(uVar2,1);
        goto LAB_00100520;
      }
      _printk(&DAT_001023e1,"i2c_pmic_probe",uVar2,iVar4);
    }
    else {
      uVar9 = devm_pinctrl_get_select(*plVar5);
      plVar5[4] = uVar9;
      if (uVar9 < 0xfffffffffffff001) goto LAB_00100730;
      _printk(&DAT_001022ab,"i2c_pmic_probe",plVar5[0xb],uVar9);
      iVar4 = (int)plVar5[4];
    }
  }
  if (plVar5[2] != 0) {
    irq_domain_remove();
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
LAB_001004e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// i2c_pmic_remove @ 001007fc size=64
// signature: undefined i2c_pmic_remove(void)
// callers: []
//------------------------------------------------------------

void i2c_pmic_remove(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xb8);
  of_platform_depopulate(*puVar1);
  if (puVar1[2] != 0) {
    irq_domain_remove();
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  return;
}



//------------------------------------------------------------
// i2c_pmic_determine_initial_status @ 0010083c size=380
// signature: undefined i2c_pmic_determine_initial_status(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

int i2c_pmic_determine_initial_status(long param_1)

{
  long lVar1;
  long lVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  if (0 < *(int *)(param_1 + 0x60)) {
    lVar7 = 0;
    lVar8 = 0;
    do {
      uVar6 = *(undefined8 *)(param_1 + 8);
      lVar2 = *(long *)(param_1 + 0x18) + lVar7;
      lVar1 = lVar2 + 10;
      uVar3 = *(ushort *)(lVar2 + 8) | 0x11;
      iVar4 = regmap_bulk_read(uVar6,uVar3,lVar1,5);
      if ((iVar4 == -0x6b) && (iVar4 = regmap_bulk_read(uVar6,uVar3,lVar1,5), iVar4 == -0x6b)) {
        iVar4 = regmap_bulk_read(uVar6,uVar3,lVar1,5);
        if (iVar4 == -0x6b) {
          iVar4 = regmap_bulk_read(uVar6,uVar3,lVar1,5);
          uVar5 = 2;
          if (iVar4 == -0x6b) {
            uVar5 = 3;
          }
        }
        else {
          uVar5 = 1;
        }
        _printk(&DAT_00102115,"i2c_pmic_read",uVar5,iVar4);
      }
      if (iVar4 < 0) {
        _printk(&DAT_0010227d,"i2c_pmic_determine_initial_status",iVar4);
        return iVar4;
      }
      lVar8 = lVar8 + 1;
      lVar1 = *(long *)(param_1 + 0x18) + lVar7;
      lVar7 = lVar7 + 0x48;
      *(undefined4 *)(lVar1 + 0xf) = *(undefined4 *)(lVar1 + 10);
      *(undefined1 *)(lVar1 + 0x13) = *(undefined1 *)(lVar1 + 0xe);
    } while (lVar8 < *(int *)(param_1 + 0x60));
  }
  return 0;
}



//------------------------------------------------------------
// devm_pinctrl_get_select @ 001009b8 size=132
// signature: undefined devm_pinctrl_get_select(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

ulong devm_pinctrl_get_select(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = devm_pinctrl_get();
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = pinctrl_lookup_state(uVar2,param_2);
    if (0xfffffffffffff000 < uVar3) {
      devm_pinctrl_put(uVar2);
      return uVar3;
    }
    iVar1 = pinctrl_select_state(uVar2,uVar3);
    if (iVar1 < 0) {
      devm_pinctrl_put(uVar2);
      return (long)iVar1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// i2c_pmic_toggle_stat @ 00100a3c size=424
// signature: undefined i2c_pmic_toggle_stat(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

int i2c_pmic_toggle_stat(long param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  if ((*(char *)(param_1 + 0x6a) == '\0') || (*(int *)(param_1 + 0x60) == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = regmap_write(*(undefined8 *)(param_1 + 8),
                         *(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0x15,1);
    if (iVar1 < 0) {
      puVar3 = &DAT_00102882;
    }
    else {
      iVar1 = regmap_write(*(undefined8 *)(param_1 + 8),
                           *(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0xe0,0x80);
      if (-1 < iVar1) {
        iVar1 = 5;
        do {
          iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),
                               *(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0xe1,1);
          if (iVar2 < 0) {
LAB_00100b88:
            puVar3 = &DAT_001026b2;
LAB_00100bd0:
            _printk(puVar3,"i2c_pmic_toggle_stat",iVar2);
            break;
          }
          usleep_range_state(5000,0x157c,2);
          iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),
                               *(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0xe1,0);
          if (iVar2 < 0) goto LAB_00100b88;
          iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),
                               *(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0x14,1);
          if (iVar2 < 0) {
            puVar3 = &DAT_0010274a;
            goto LAB_00100bd0;
          }
          usleep_range_state(5000,0x157c,2);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        regmap_write(*(undefined8 *)(param_1 + 8),*(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0xe0,
                     0);
        regmap_write(*(undefined8 *)(param_1 + 8),*(ushort *)(*(long *)(param_1 + 0x18) + 8) | 0x16,
                     1);
        return iVar2;
      }
      puVar3 = &DAT_00102602;
    }
    _printk(puVar3,"i2c_pmic_toggle_stat",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// i2c_pmic_irq_handler @ 00100be8 size=972
// signature: undefined i2c_pmic_irq_handler(void)
// callers: [i2c_pmic_resume]
//------------------------------------------------------------

undefined8 i2c_pmic_irq_handler(undefined4 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ushort *puVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  uint local_74;
  uint local_70;
  int local_6c;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_74 = 0;
  mutex_lock();
  *(undefined1 *)(param_2 + 0x69) = 1;
  if (*(char *)(param_2 + 0x68) == '\0') {
    disable_irq_nosync(param_1);
  }
  else {
    *(undefined1 *)(param_2 + 0x69) = 0;
    if (7 < *(int *)(param_2 + 0x60) + 7) {
      uVar7 = 0;
      do {
        iVar1 = regmap_read(*(undefined8 *)(param_2 + 8),(int)uVar7 + 0x550,&local_74);
        if (iVar1 < 0) {
          iVar2 = ___ratelimit(i2c_pmic_irq_handler__rs,"i2c_pmic_irq_handler");
          if (iVar2 != 0) {
            _printk(&DAT_001024aa,"i2c_pmic_irq_handler",uVar7 & 0xffffffff,iVar1);
          }
        }
        else if (local_74 != 0) {
          lVar4 = *(long *)(param_2 + 0x18);
          local_70 = 0;
          if ((local_74 & 0xff) != 0) {
            uVar10 = local_74;
            do {
              uVar14 = (uVar10 & 0xaaaaaaaa) >> 1 | (uVar10 & 0x55555555) << 1;
              uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
              uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
              uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
              lVar6 = LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10);
              puVar8 = (ushort *)(lVar4 + uVar7 * 0x240 + lVar6 * 0x48 + 8);
              iVar1 = regmap_read(*(undefined8 *)(param_2 + 8),*puVar8 | 0x18,&local_70);
              if (iVar1 < 0) {
                iVar2 = ___ratelimit(i2c_pmic_summary_status_handler__rs,
                                     "i2c_pmic_summary_status_handler");
                if (iVar2 != 0) {
                  _printk(&DAT_00102578,"i2c_pmic_summary_status_handler",*puVar8,iVar1);
                }
              }
              else if ((local_70 & 0xff) != 0) {
                uVar11 = (ulong)*puVar8;
                uVar14 = local_70;
                do {
                  uVar12 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
                  uVar12 = (uVar12 & 0xcccccccc) >> 2 | (uVar12 & 0x33333333) << 2;
                  uVar12 = (uVar12 & 0xf0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f) << 4;
                  uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
                  local_6c = 0;
                  uVar9 = 1L << LZCOUNT(uVar12 >> 0x10 | uVar12 << 0x10);
                  uVar13 = uVar9 | uVar11;
                  lVar3 = __irq_resolve_mapping(*(undefined8 *)(param_2 + 0x10),uVar13,&local_6c);
                  uVar12 = (uint)uVar13;
                  if (lVar3 == 0 || local_6c == 0) {
                    iVar1 = ___ratelimit(i2c_pmic_periph_status_handler__rs,
                                         "i2c_pmic_periph_status_handler");
                    if (iVar1 != 0) {
                      _printk(&DAT_00102946,"i2c_pmic_periph_status_handler",
                              uVar9 & 0xffffffff | uVar11);
                    }
                    uVar5 = (ulong)*(uint *)(param_2 + 0x60);
                    if (0 < (int)*(uint *)(param_2 + 0x60)) {
                      lVar3 = *(long *)(param_2 + 0x18) + 0x18;
                      do {
                        if ((uVar11 & 0xff00) == (ulong)*(ushort *)(lVar3 + -0x10)) {
                          if (lVar3 != 0x18) {
                            mutex_lock(lVar3);
                            *(byte *)(lVar3 + -10) = *(byte *)(lVar3 + -10) & ((byte)uVar13 ^ 0xff);
                            iVar1 = regmap_write(*(undefined8 *)(param_2 + 8),uVar12 & 0xff00 | 0x16
                                                 ,uVar12 & 0xff);
                            if (iVar1 < 0) {
                              iVar2 = ___ratelimit(i2c_pmic_irq_disable_now__rs,
                                                   "i2c_pmic_irq_disable_now");
                              if (iVar2 != 0) {
                                _printk(&DAT_001024e1,"i2c_pmic_irq_disable_now",
                                        uVar9 & 0xffffffff | uVar11,iVar1);
                              }
                            }
                            else {
                              *(undefined1 *)(lVar3 + -5) = *(undefined1 *)(lVar3 + -10);
                            }
                            mutex_unlock(lVar3);
                          }
                          goto LAB_00100d5c;
                        }
                        lVar3 = lVar3 + 0x48;
                        uVar5 = uVar5 - 1;
                      } while (uVar5 != 0);
                    }
                    iVar1 = ___ratelimit(i2c_pmic_find_periph__rs,"i2c_pmic_find_periph");
                    if (iVar1 != 0) {
                      _printk(&DAT_001026e8,"i2c_pmic_find_periph",uVar13);
                    }
                  }
                  else {
                    handle_nested_irq(local_6c);
                    iVar1 = regmap_write(*(undefined8 *)(param_2 + 8),uVar12 & 0xff00 | 0x14,
                                         uVar12 & 0xff);
                    if ((iVar1 < 0) &&
                       (iVar2 = ___ratelimit(i2c_pmic_irq_ack_now__rs,"i2c_pmic_irq_ack_now"),
                       iVar2 != 0)) {
                      _printk(&DAT_00102783,"i2c_pmic_irq_ack_now",uVar9 & 0xffffffff | uVar11,iVar1
                             );
                    }
                  }
LAB_00100d5c:
                  uVar14 = uVar14 & ((uint)uVar9 ^ 0xffffffff);
                } while ((uVar14 & 0xff) != 0);
              }
              uVar10 = uVar10 & (1 << (ulong)((uint)lVar6 & 0x1f) ^ 0xffffffffU);
            } while ((uVar10 & 0xff) != 0);
          }
        }
        uVar7 = uVar7 + 1;
        iVar1 = *(int *)(param_2 + 0x60) + 7;
        iVar2 = *(int *)(param_2 + 0x60) + 0xe;
        if (-1 < iVar1) {
          iVar2 = iVar1;
        }
      } while ((long)uVar7 < (long)(iVar2 >> 3));
    }
  }
  mutex_unlock(param_2 + 0x28);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// i2c_pmic_domain_map @ 00100fb8 size=224
// signature: undefined i2c_pmic_domain_map(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_pmic_domain_map(long param_1,undefined4 param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x20) + 0x60);
  uVar4 = (ulong)uVar1;
  if (0 < (int)uVar1) {
    lVar3 = *(long *)(*(long *)(param_1 + 0x20) + 0x18);
    do {
      if ((param_3 & 0xff00) == (ulong)*(ushort *)(lVar3 + 8)) {
        if (lVar3 == 0) {
          return 0xffffffed;
        }
        irq_set_chip_data(param_2);
        irq_set_chip_and_handler_name(param_2,&i2c_pmic_irq_chip,&handle_level_irq,0);
        irq_modify_status(param_2,0,0x8000);
        irq_modify_status(param_2,0,0x400);
        return 0;
      }
      lVar3 = lVar3 + 0x48;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  iVar2 = ___ratelimit(i2c_pmic_find_periph__rs,"i2c_pmic_find_periph");
  if (iVar2 != 0) {
    _printk(&DAT_001026e8,"i2c_pmic_find_periph",param_3);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// i2c_pmic_domain_xlate @ 0010109c size=88
// signature: undefined i2c_pmic_domain_xlate(void)
// callers: []
//------------------------------------------------------------

undefined8
i2c_pmic_domain_xlate
          (undefined8 param_1,undefined8 param_2,uint *param_3,int param_4,ulong *param_5,
          uint *param_6)

{
  if ((((param_4 == 3) && (*param_3 < 0x100)) && (param_3[1] < 8)) && (param_3[2] < 0x10)) {
    *param_5 = 1L << ((ulong)param_3[1] & 0x3f) | (ulong)*param_3 << 8;
    *param_6 = param_3[2] & 0xf;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// i2c_pmic_irq_enable @ 001010f8 size=24
// signature: undefined i2c_pmic_irq_enable(void)
// callers: []
//------------------------------------------------------------

void i2c_pmic_irq_enable(long param_1)

{
  *(byte *)(*(long *)(param_1 + 0x30) + 0xe) =
       *(byte *)(*(long *)(param_1 + 0x30) + 0xe) | *(byte *)(param_1 + 8);
  return;
}



//------------------------------------------------------------
// i2c_pmic_irq_disable @ 00101114 size=24
// signature: undefined i2c_pmic_irq_disable(void)
// callers: []
//------------------------------------------------------------

void i2c_pmic_irq_disable(long param_1)

{
  *(byte *)(*(long *)(param_1 + 0x30) + 0xe) =
       *(byte *)(*(long *)(param_1 + 0x30) + 0xe) & (*(byte *)(param_1 + 8) ^ 0xff);
  return;
}



//------------------------------------------------------------
// i2c_pmic_irq_set_type @ 00101130 size=260
// signature: undefined i2c_pmic_irq_set_type(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_pmic_irq_set_type(long param_1,int param_2)

{
  long lVar1;
  byte bVar2;
  
  if (7 < param_2 - 1U) {
switchD_00101164_caseD_5:
    _printk(&DAT_0010205d,"i2c_pmic_irq_set_type",param_2);
    return 0xffffffea;
  }
  lVar1 = *(long *)(param_1 + 0x30);
  switch(param_2) {
  case 1:
    bVar2 = *(byte *)(lVar1 + 10) | *(byte *)(param_1 + 8);
    break;
  case 2:
    bVar2 = *(byte *)(lVar1 + 10) | *(byte *)(param_1 + 8);
    goto LAB_001011e4;
  case 3:
    *(byte *)(lVar1 + 10) = *(byte *)(lVar1 + 10) | *(byte *)(param_1 + 8);
    bVar2 = *(byte *)(lVar1 + 0xb) | *(byte *)(param_1 + 8);
    goto LAB_001011f4;
  case 4:
    bVar2 = *(byte *)(lVar1 + 10) & (*(byte *)(param_1 + 8) ^ 0xff);
    break;
  default:
    goto switchD_00101164_caseD_5;
  case 8:
    bVar2 = *(byte *)(lVar1 + 10) & (*(byte *)(param_1 + 8) ^ 0xff);
LAB_001011e4:
    *(byte *)(lVar1 + 10) = bVar2;
    bVar2 = *(byte *)(lVar1 + 0xb) & (*(byte *)(param_1 + 8) ^ 0xff);
LAB_001011f4:
    *(byte *)(lVar1 + 0xb) = bVar2;
    bVar2 = *(byte *)(lVar1 + 0xc) | *(byte *)(param_1 + 8);
    goto LAB_00101204;
  }
  *(byte *)(lVar1 + 10) = bVar2;
  *(byte *)(lVar1 + 0xb) = *(byte *)(lVar1 + 0xb) | *(byte *)(param_1 + 8);
  bVar2 = *(byte *)(lVar1 + 0xc) & (*(byte *)(param_1 + 8) ^ 0xff);
LAB_00101204:
  *(byte *)(lVar1 + 0xc) = bVar2;
  return 0;
}



//------------------------------------------------------------
// i2c_pmic_irq_set_wake @ 00101238 size=40
// signature: undefined i2c_pmic_irq_set_wake(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_pmic_irq_set_wake(long param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(*(long *)(param_1 + 0x30) + 0x14);
  bVar1 = bVar2 & (*(byte *)(param_1 + 8) ^ 0xff);
  if (param_2 != 0) {
    bVar1 = bVar2 | *(byte *)(param_1 + 8);
  }
  *(byte *)(*(long *)(param_1 + 0x30) + 0x14) = bVar1;
  return 0;
}



//------------------------------------------------------------
// i2c_pmic_irq_bus_lock @ 00101264 size=36
// signature: undefined i2c_pmic_irq_bus_lock(void)
// callers: []
//------------------------------------------------------------

void i2c_pmic_irq_bus_lock(long param_1)

{
  mutex_lock(*(long *)(param_1 + 0x30) + 0x18);
  return;
}



//------------------------------------------------------------
// i2c_pmic_irq_bus_sync_unlock @ 0010128c size=444
// signature: undefined i2c_pmic_irq_bus_sync_unlock(void)
// callers: []
//------------------------------------------------------------

void i2c_pmic_irq_bus_sync_unlock(long param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  byte bVar7;
  long *plVar8;
  long lVar9;
  
  plVar8 = *(long **)(param_1 + 0x30);
  lVar9 = *plVar8;
  if (*(char *)((long)plVar8 + 10) == *(char *)((long)plVar8 + 0xf)) {
LAB_001012dc:
    if (*(char *)((long)plVar8 + 0xb) != (char)plVar8[2]) {
      iVar3 = regmap_write(*(undefined8 *)(lVar9 + 8),*(ushort *)(plVar8 + 1) | 0x12);
      if (iVar3 < 0) {
        uVar5 = (undefined2)plVar8[1];
        uVar6 = *(undefined1 *)((long)plVar8 + 0xb);
        puVar4 = &DAT_001020b3;
        goto LAB_00101438;
      }
      *(undefined1 *)(plVar8 + 2) = *(undefined1 *)((long)plVar8 + 0xb);
    }
    if (*(char *)((long)plVar8 + 0xc) != *(char *)((long)plVar8 + 0x11)) {
      iVar3 = regmap_write(*(undefined8 *)(lVar9 + 8),*(ushort *)(plVar8 + 1) | 0x13);
      if (iVar3 < 0) {
        uVar5 = (undefined2)plVar8[1];
        uVar6 = *(undefined1 *)((long)plVar8 + 0xc);
        puVar4 = &DAT_00102410;
        goto LAB_00101438;
      }
      *(undefined1 *)((long)plVar8 + 0x11) = *(undefined1 *)((long)plVar8 + 0xc);
    }
  }
  else {
    iVar3 = regmap_write(*(undefined8 *)(lVar9 + 8),*(ushort *)(plVar8 + 1) | 0x11);
    if (-1 < iVar3) {
      *(undefined1 *)((long)plVar8 + 0xf) = *(undefined1 *)((long)plVar8 + 10);
      goto LAB_001012dc;
    }
    uVar5 = (undefined2)plVar8[1];
    uVar6 = *(undefined1 *)((long)plVar8 + 10);
    puVar4 = &DAT_0010283f;
LAB_00101438:
    _printk(puVar4,"i2c_pmic_sync_type_polarity",uVar5,uVar6,iVar3);
  }
  bVar1 = *(byte *)((long)plVar8 + 0xe);
  bVar2 = *(byte *)((long)plVar8 + 0x13);
  bVar7 = bVar2 & (bVar1 ^ 0xff);
  if ((bVar7 == 0) ||
     (iVar3 = regmap_write(*(undefined8 *)(lVar9 + 8),*(ushort *)(plVar8 + 1) | 0x16,bVar7),
     -1 < iVar3)) {
    bVar7 = bVar1 & (bVar2 ^ 0xff);
    if ((bVar7 == 0) ||
       (iVar3 = regmap_write(*(undefined8 *)(lVar9 + 8),*(ushort *)(plVar8 + 1) | 0x15,bVar7),
       -1 < iVar3)) {
      *(undefined1 *)((long)plVar8 + 0x13) = *(undefined1 *)((long)plVar8 + 0xe);
      goto LAB_0010139c;
    }
    uVar5 = (undefined2)plVar8[1];
    puVar4 = &DAT_0010245b;
  }
  else {
    uVar5 = (undefined2)plVar8[1];
    puVar4 = &DAT_0010232b;
  }
  _printk(puVar4,"i2c_pmic_sync_enable",uVar5,bVar7,iVar3);
LAB_0010139c:
  mutex_unlock(plVar8 + 3);
  return;
}



//------------------------------------------------------------
// i2c_pmic_suspend @ 0010144c size=344
// signature: undefined i2c_pmic_suspend(void)
// callers: []
//------------------------------------------------------------

int i2c_pmic_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (-1 < *(int *)(lVar4 + 100)) {
    if (0 < *(int *)(lVar4 + 0x60)) {
      lVar5 = 0;
      lVar6 = 0;
      do {
        lVar1 = *(long *)(lVar4 + 0x18) + lVar5;
        iVar2 = regmap_write(*(undefined8 *)(lVar4 + 8),*(ushort *)(lVar1 + 8) | 0x16,0xff);
        if (iVar2 < 0) {
          iVar3 = ___ratelimit(i2c_pmic_suspend__rs,"i2c_pmic_suspend");
          if (iVar3 != 0) {
            _printk(&DAT_001028b6,"i2c_pmic_suspend",*(undefined2 *)(lVar1 + 8),iVar2);
          }
        }
        else {
          iVar2 = regmap_write(*(undefined8 *)(lVar4 + 8),*(ushort *)(lVar1 + 8) | 0x15,
                               *(undefined1 *)(lVar1 + 0x14));
          if ((iVar2 < 0) &&
             (iVar3 = ___ratelimit(i2c_pmic_suspend__rs_41,"i2c_pmic_suspend"), iVar3 != 0)) {
            _printk(&DAT_00102153,"i2c_pmic_suspend",*(undefined2 *)(lVar1 + 8),
                    *(undefined1 *)(lVar1 + 0x14),iVar2);
          }
        }
        lVar6 = lVar6 + 1;
        lVar5 = lVar5 + 0x48;
      } while (lVar6 < *(int *)(lVar4 + 0x60));
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    mutex_lock(lVar4 + 0x28);
    *(undefined1 *)(lVar4 + 0x68) = 0;
    mutex_unlock(lVar4 + 0x28);
  }
  return 0;
}



//------------------------------------------------------------
// i2c_pmic_resume @ 001015a8 size=336
// signature: undefined i2c_pmic_resume(void)
// callers: []
//------------------------------------------------------------

int i2c_pmic_resume(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar4 + 100) < 0) {
    iVar3 = 0;
  }
  else {
    if (*(int *)(lVar4 + 0x60) < 1) {
      iVar3 = 0;
    }
    else {
      lVar5 = 0;
      lVar6 = 0;
      do {
        lVar1 = *(long *)(lVar4 + 0x18) + lVar5;
        iVar3 = regmap_write(*(undefined8 *)(lVar4 + 8),*(ushort *)(lVar1 + 8) | 0x16,0xff);
        if (iVar3 < 0) {
          _printk(&DAT_001028b6,"i2c_pmic_resume",*(undefined2 *)(lVar1 + 8),iVar3);
        }
        else {
          iVar3 = regmap_write(*(undefined8 *)(lVar4 + 8),*(ushort *)(lVar1 + 8) | 0x15,
                               *(undefined1 *)(lVar1 + 0x13));
          if (iVar3 < 0) {
            _printk(&DAT_001028e8,"i2c_pmic_resume",*(undefined2 *)(lVar1 + 8),
                    *(undefined1 *)(lVar1 + 0x13),iVar3);
          }
        }
        lVar6 = lVar6 + 1;
        lVar5 = lVar5 + 0x48;
      } while (lVar6 < *(int *)(lVar4 + 0x60));
    }
    mutex_lock(lVar4 + 0x28);
    cVar2 = *(char *)(lVar4 + 0x69);
    *(undefined1 *)(lVar4 + 0x68) = 1;
    mutex_unlock(lVar4 + 0x28);
    if (cVar2 != '\0') {
      i2c_pmic_irq_handler(*(undefined4 *)(lVar4 + 100),lVar4);
      enable_irq(*(undefined4 *)(lVar4 + 100));
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// i2c_pmic_suspend_noirq @ 001016fc size=96
// signature: undefined i2c_pmic_suspend_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_pmic_suspend_noirq(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(char *)(*(long *)(param_1 + 0x98) + 0x69) == '\0') {
    uVar2 = 0;
  }
  else {
    iVar1 = ___ratelimit(i2c_pmic_suspend_noirq__rs,"i2c_pmic_suspend_noirq");
    if (iVar1 != 0) {
      _printk(&DAT_001021ce,"i2c_pmic_suspend_noirq");
    }
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00101760 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&i2c_pmic_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101790 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&i2c_pmic_driver);
  return;
}



//------------------------------------------------------------
// i2c_register_driver @ 00104000 size=1
// signature: undefined i2c_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 00104008 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_i2c @ 00104018 size=1
// signature: undefined __devm_regmap_init_i2c(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_i2c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 00104020 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104028 size=1
// signature: undefined of_find_property(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00104030 size=1
// signature: undefined __irq_domain_add(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00104038 size=1
// signature: undefined of_platform_populate(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104040 size=1
// signature: undefined _printk(void)
// callers: [i2c_pmic_probe, i2c_pmic_toggle_stat, i2c_pmic_irq_handler, i2c_pmic_irq_set_type, i2c_pmic_suspend, i2c_pmic_determine_initial_status, i2c_pmic_resume, i2c_pmic_domain_map, i2c_pmic_irq_bus_sync_unlock, i2c_pmic_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_remove @ 00104048 size=1
// signature: undefined irq_domain_remove(void)
// callers: [i2c_pmic_probe, i2c_pmic_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00104050 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00104058 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104060 size=1
// signature: undefined __mutex_init(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104068 size=1
// signature: undefined of_property_read_string(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00104070 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00104078 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [i2c_pmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [i2c_pmic_probe, i2c_pmic_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_depopulate @ 00104088 size=1
// signature: undefined of_platform_depopulate(void)
// callers: [i2c_pmic_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_depopulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00104090 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [i2c_pmic_determine_initial_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00104098 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [devm_pinctrl_get_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 001040a0 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [devm_pinctrl_get_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 001040a8 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [devm_pinctrl_get_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 001040b0 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [devm_pinctrl_get_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001040b8 size=1
// signature: undefined regmap_write(void)
// callers: [i2c_pmic_toggle_stat, i2c_pmic_irq_handler, i2c_pmic_suspend, i2c_pmic_resume, i2c_pmic_irq_bus_sync_unlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001040c0 size=1
// signature: undefined usleep_range_state(void)
// callers: [i2c_pmic_toggle_stat]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040c8 size=1
// signature: undefined mutex_lock(void)
// callers: [i2c_pmic_irq_handler, i2c_pmic_suspend, i2c_pmic_resume, i2c_pmic_irq_bus_lock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001040d0 size=1
// signature: undefined regmap_read(void)
// callers: [i2c_pmic_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001040d8 size=1
// signature: undefined ___ratelimit(void)
// callers: [i2c_pmic_irq_handler, i2c_pmic_suspend, i2c_pmic_domain_map, i2c_pmic_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 001040e0 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [i2c_pmic_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_nested_irq @ 001040e8 size=1
// signature: undefined handle_nested_irq(void)
// callers: [i2c_pmic_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_nested_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001040f0 size=1
// signature: undefined mutex_unlock(void)
// callers: [i2c_pmic_irq_handler, i2c_pmic_suspend, i2c_pmic_resume, i2c_pmic_irq_bus_sync_unlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 001040f8 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [i2c_pmic_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_data @ 00104100 size=1
// signature: undefined irq_set_chip_data(void)
// callers: [i2c_pmic_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_and_handler_name @ 00104110 size=1
// signature: undefined irq_set_chip_and_handler_name(void)
// callers: [i2c_pmic_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_and_handler_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 00104118 size=1
// signature: undefined irq_modify_status(void)
// callers: [i2c_pmic_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00104120 size=1
// signature: undefined enable_irq(void)
// callers: [i2c_pmic_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



