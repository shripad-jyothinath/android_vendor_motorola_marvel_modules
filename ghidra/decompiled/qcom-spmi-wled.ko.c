// Decompiled by Ghidra 12.2
// Program: qcom-spmi-wled.ko
// Image base: 00100000

//------------------------------------------------------------
// wled_flash_led_prepare @ 001005e4 size=440
// signature: undefined wled_flash_led_prepare(void)
// callers: []
//------------------------------------------------------------

int wled_flash_led_prepare(undefined8 *param_1,uint param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  char *__s1;
  undefined8 *puVar6;
  
  if ((param_2 & 0xf) == 0) {
    _printk(&DAT_00104595,"wled_flash_led_prepare",param_2);
  }
  else if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00103f44,"wled_flash_led_prepare");
  }
  else {
    puVar1 = param_1 + 4;
    _raw_spin_lock(puVar1);
    puVar6 = param_1 + 5;
    do {
      puVar6 = (undefined8 *)*puVar6;
      if (puVar6 == param_1 + 5) {
        _raw_spin_unlock(puVar1);
        goto LAB_00100724;
      }
      iVar3 = strcmp((char *)puVar6[-0x1c],(char *)*param_1);
    } while (iVar3 != 0);
    puVar6 = puVar6 + -0x2a;
    _raw_spin_unlock(puVar1);
    if (puVar6 != (undefined8 *)0x0) {
      if (1 < param_2 - 1) {
        if (param_2 != 4) {
          if (param_2 != 8) {
            return -0x16;
          }
          __s1 = (char *)*puVar6;
          iVar3 = strcmp(__s1,"wled_flash");
          if (iVar3 == 0) {
            lVar5 = -0xd0;
          }
          else {
            iVar4 = strcmp(__s1,"wled_torch");
            if (iVar4 != 0) {
              _printk(&DAT_00104fee,"wled_flash_led_prepare",__s1);
              return -0x13;
            }
            lVar5 = -0x278;
          }
          lVar2 = 0xdc;
          if (iVar3 != 0) {
            lVar2 = 0x284;
          }
          *param_3 = *(undefined4 *)((long)puVar6 + lVar2 + lVar5);
          return 0;
        }
        iVar3 = wled_get_max_avail_current(puVar6,param_3);
        if (iVar3 < 0) {
          _printk(&DAT_00104da1,"wled_flash_led_prepare",*puVar6);
          return iVar3;
        }
      }
      return 0;
    }
LAB_00100724:
    _printk(&DAT_001047fb,"wled_flash_led_prepare",*param_1);
  }
  return -0x16;
}



//------------------------------------------------------------
// wled_get_max_avail_current @ 0010079c size=1188
// signature: undefined wled_get_max_avail_current(void)
// callers: [wled_flash_led_prepare, wled_flash_max_avail_current_show]
//------------------------------------------------------------

int wled_get_max_avail_current(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined1 auVar4 [16];
  int iVar5;
  long lVar6;
  undefined *puVar7;
  long lVar8;
  int iVar9;
  undefined8 *puVar10;
  uint uVar11;
  int iVar12;
  long *plVar13;
  undefined8 local_70;
  int local_64;
  int local_60;
  int local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_5c = 0;
  local_64 = 0;
  local_60 = 0;
  local_70 = 0;
  iVar5 = strcmp((char *)*param_1,"wled_switch");
  if (iVar5 != 0) {
LAB_001007f0:
    iVar5 = -0x13;
    goto LAB_00100b50;
  }
  uVar1 = *(uint *)((long)param_1 + -0x344);
  if (*(uint *)((long)param_1 + -0x344) <= *(uint *)((long)param_1 + -0x19c)) {
    uVar1 = *(uint *)((long)param_1 + -0x19c);
  }
  if ((*(int *)((long)param_1 + 0x1cc) == 0) ||
     ((*(char *)(param_1 + 0x39) == '\x02' && (*(int *)((long)param_1 + 0x1cc) == 8)))) {
    iVar5 = 0;
    *param_2 = uVar1;
    goto LAB_00100b50;
  }
  if (*(char *)((long)param_1 + -0x35b) == '\0') {
    puVar10 = param_1 + -0x84;
    iVar5 = wled_iio_get_prop(puVar10,1,&local_5c);
    if (iVar5 < 0) {
      puVar7 = &DAT_00104f7e;
    }
    else {
      local_5c = local_5c / 1000;
      iVar5 = wled_iio_get_prop(puVar10,2,&local_64);
      if (iVar5 < 0) {
        puVar7 = &DAT_0010426b;
      }
      else {
        local_64 = local_64 / 1000;
        iVar5 = wled_iio_get_prop(puVar10,0,&local_60);
        if (-1 < iVar5) {
          iVar9 = local_5c;
          iVar12 = local_64;
          goto LAB_00100978;
        }
        puVar7 = &DAT_00104a5e;
      }
    }
  }
  else {
    plVar13 = param_1 + -0x80;
    lVar6 = *plVar13;
    if (lVar6 == 0) {
      lVar6 = power_supply_get_by_name("battery");
      *plVar13 = lVar6;
      if (lVar6 == 0) {
        iVar5 = ___ratelimit(&wled_get_max_avail_current__rs,"wled_get_max_avail_current");
        if (iVar5 != 0) {
          _printk(&DAT_001043fe,"wled_get_max_avail_current");
          iVar5 = -0x13;
          goto LAB_00100b50;
        }
        goto LAB_001007f0;
      }
    }
    iVar5 = power_supply_get_property(lVar6,0xe,&local_70);
    if (iVar5 < 0) {
      puVar7 = &DAT_00103ffa;
    }
    else {
      iVar9 = (int)local_70 / 1000;
      local_5c = iVar9;
      iVar5 = power_supply_get_property(*plVar13,0x11,&local_70);
      if (iVar5 < 0) {
        puVar7 = &DAT_001051a7;
      }
      else {
        iVar12 = -(int)local_70;
        local_64 = iVar12 / 1000;
        iVar5 = qti_battery_charger_get_prop("battery",0,&local_60);
        iVar12 = iVar12 / 1000;
        if (-1 < iVar5) {
LAB_00100978:
          local_60 = local_60 / 1000;
          iVar5 = (int)((ulong)((long)(iVar12 * local_60) * -0x10624dd3) >> 0x20);
          iVar5 = iVar9 + ((iVar5 >> 6) - (iVar5 >> 0x1f)) + -400;
          if (iVar5 < 1) {
            _printk(&DAT_0010442e,"wled_get_max_avail_current");
            iVar5 = 0;
            *param_2 = 0;
            goto LAB_00100b50;
          }
          iVar2 = *(int *)((long)param_1 + 0x1cc);
          bVar3 = *(byte *)(param_1 + 0x39);
          lVar6 = 0;
          if ((long)iVar5 != 0) {
            lVar6 = (long)(((ulong)(iVar2 * 0x2d690 + 24000) * (ulong)bVar3 * 1000) / 700) /
                    (long)iVar5;
          }
          lVar6 = SUB168(SEXT816((lVar6 + iVar12) * (long)local_60) * SEXT816(-0x20c49ba5e353f7cf),8
                        );
          lVar6 = ((lVar6 >> 7) - (lVar6 >> 0x3f)) + (long)iVar9;
          uVar11 = uVar1;
          if ((bVar3 == 3) && (iVar2 == 8)) {
            if (lVar6 < 0xd52) {
              lVar6 = lVar6 * 0x6334;
              lVar8 = -0x662a;
LAB_00100a70:
              auVar4 = SEXT816(lVar6 / 1000 + lVar8) * SEXT816(0x20c49ba5e353f7cf);
              uVar11 = ((int)(auVar4._8_8_ >> 7) - (auVar4._12_4_ >> 0x1f)) * 3;
            }
          }
          else if (bVar3 == 3) {
            if (iVar2 == 6) {
              if (lVar6 < 0xaf0) {
                lVar6 = lVar6 * 0xa15f;
                lVar8 = -0xcc6e;
                goto LAB_00100a70;
              }
            }
            else {
LAB_00100b2c:
              if (lVar6 < 0xc80) {
                if ((int)uVar1 < 0) {
                  uVar11 = uVar1 + 1;
                }
                uVar11 = (int)uVar11 >> 1;
              }
            }
          }
          else {
            if ((bVar3 != 4) || (iVar2 != 6)) goto LAB_00100b2c;
            if (lVar6 < 0xd48) {
              auVar4 = SEXT816((lVar6 * 0x6680) / 1000 + -0x6102) * SEXT816(0x20c49ba5e353f7cf);
              uVar11 = ((int)(auVar4._8_8_ >> 7) - (auVar4._12_4_ >> 0x1f)) * 4;
            }
          }
          iVar5 = 0;
          if ((int)uVar1 <= (int)uVar11) {
            uVar11 = uVar1;
          }
          *param_2 = uVar11;
          goto LAB_00100b50;
        }
        puVar7 = &DAT_00104c74;
      }
    }
  }
  _printk(puVar7,"wled_get_max_avail_current",iVar5);
LAB_00100b50:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// wled_iio_get_prop @ 00100c40 size=268
// signature: undefined wled_iio_get_prop(void)
// callers: [wled_get_max_avail_current]
//------------------------------------------------------------

ulong wled_iio_get_prop(long param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined *puVar4;
  ulong uVar5;
  
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x18) + (ulong)param_2 * 8);
  if (0xfffffffffffff000 < uVar3) {
    uVar3 = 0xffffffea;
    goto LAB_00100d10;
  }
  if (uVar3 == 0) {
    if (2 < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x100d4c);
      (*pcVar1)();
    }
    uVar5 = (ulong)param_2;
    puVar4 = (&wled_iio_prop_names)[uVar5];
    uVar2 = devm_iio_channel_get(*(long *)(param_1 + 8) + 0x10,puVar4);
    *(undefined8 *)(*(long *)(param_1 + 0x18) + uVar5 * 8) = uVar2;
    uVar3 = *(ulong *)(*(long *)(param_1 + 0x18) + uVar5 * 8);
    if (0xfffffffffffff000 < uVar3) {
      if ((int)uVar3 == -0x205) {
        uVar3 = 0xfffffdfb;
        *(undefined8 *)(*(long *)(param_1 + 0x18) + uVar5 * 8) = 0;
        goto LAB_00100d10;
      }
      _printk(&DAT_0010470e,"wled_get_iio_chan",puVar4,uVar3 & 0xffffffff);
      if ((int)uVar3 < 0) goto LAB_00100d10;
      uVar3 = *(ulong *)(*(long *)(param_1 + 0x18) + uVar5 * 8);
    }
  }
  uVar5 = iio_read_channel_processed(uVar3,param_3);
  uVar3 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    _printk(&DAT_00104028,"wled_iio_get_prop",uVar3);
  }
LAB_00100d10:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// wled_probe @ 00100d50 size=5936
// signature: undefined wled_probe(void)
// callers: []
//------------------------------------------------------------

int wled_probe(long param_1)

{
  long lVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  char **ppcVar9;
  uint uVar10;
  byte bVar11;
  char cVar12;
  bool bVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  long lVar18;
  undefined8 *puVar19;
  int *piVar20;
  uint *puVar21;
  undefined4 *puVar22;
  undefined8 uVar23;
  long lVar24;
  undefined *puVar25;
  char *pcVar26;
  code *pcVar27;
  undefined8 *puVar28;
  ulong uVar29;
  long *plVar30;
  ulong uVar31;
  ulong uVar32;
  uint uVar33;
  char **ppcVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  undefined4 local_1cc;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined4 local_1b0;
  int local_1ac;
  undefined8 local_1a8;
  undefined8 *local_1a0;
  undefined8 *local_198;
  char *pcStack_190;
  long local_188;
  undefined **ppuStack_180;
  char *local_178;
  long lStack_170;
  undefined1 *local_168;
  char *pcStack_160;
  int *local_158;
  undefined1 *puStack_150;
  char *local_148;
  int *piStack_140;
  undefined1 *local_138;
  char *pcStack_130;
  uint *local_128;
  undefined1 *puStack_120;
  char *local_118;
  int *piStack_110;
  undefined1 *local_108;
  char *pcStack_100;
  long local_f8;
  undefined **ppuStack_f0;
  char *local_e8;
  undefined8 *puStack_e0;
  undefined **local_d8;
  char *pcStack_d0;
  long local_c8;
  undefined **ppuStack_c0;
  char *local_b8;
  long lStack_b0;
  undefined **local_a8;
  char *pcStack_a0;
  int *local_98;
  undefined1 *puStack_90;
  char *local_88;
  int *piStack_80;
  undefined1 *local_78;
  long local_70;
  
  lVar18 = sp_el0;
  local_70 = *(long *)(lVar18 + 0x638);
  local_1b0 = 0;
  local_1c0 = 0;
  local_1b8 = 0;
  local_1c8 = 0;
  local_1cc = 0;
  lVar18 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  if (lVar18 == 0) {
    _printk(&DAT_0010501f,"wled_probe");
    iVar15 = -0x16;
    goto LAB_001022dc;
  }
  lVar1 = param_1 + 0x10;
  puVar19 = (undefined8 *)devm_kmalloc(lVar1,0x9f0,0xdc0);
  if (puVar19 == (undefined8 *)0x0) {
    iVar15 = -0xc;
    goto LAB_001022dc;
  }
  puVar19[1] = param_1;
  puVar19[2] = lVar18;
  piVar20 = (int *)of_device_get_match_data(lVar1);
  puVar19[0x15] = piVar20;
  if (piVar20 == (int *)0x0) {
    _dev_err(lVar1,"Unknown device version\n");
    iVar15 = -0x13;
    goto LAB_001022dc;
  }
  if (*piVar20 == 7) {
    *(undefined1 *)((long)puVar19 + 0xc5) = 1;
  }
  puVar28 = puVar19 + 0xb;
  local_e8 = "qcom,boost-current-limit";
  local_1a8 = "qcom,boost-current-limit";
  local_188 = (long)puVar19 + 100;
  local_d8 = &wled4_boost_i_limit_cfg;
  pcStack_d0 = "qcom,fs-current-limit";
  local_198 = &wled5_boost_i_limit_cfg;
  pcStack_190 = "qcom,fs-current-limit";
  ppuStack_c0 = &wled_fs_current_cfg;
  ppuStack_180 = &wled_fs_current_cfg;
  local_168 = wled5_ovp_cfg;
  pcStack_160 = "qcom,switching-freq";
  lStack_170 = (long)puVar19 + 0x5c;
  local_138 = wled_string_cfg;
  pcStack_130 = "qcom,modulator-sel";
  piVar20 = (int *)(puVar19 + 0xc);
  local_a8 = &wled4_ovp_cfg;
  pcStack_a0 = "qcom,switching-freq";
  piVar2 = (int *)(puVar19 + 0xd);
  local_78 = wled_string_cfg;
  puStack_120 = wled5_mod_sel_cfg;
  local_118 = "qcom,cabc-sel";
  local_f8 = (long)puVar19 + 0x74;
  local_1ac = 0;
  local_b8 = "qcom,ovp";
  puStack_90 = wled_switch_freq_cfg;
  local_88 = "qcom,string-cfg";
  local_178 = "qcom,ovp";
  puStack_150 = wled_switch_freq_cfg;
  local_148 = "qcom,string-cfg";
  local_108 = wled5_cabc_sel_cfg;
  pcStack_100 = "qcom,slew-ramp-time";
  ppuStack_f0 = &wled5_slew_ramp_time_cfg;
  local_1a0 = puVar28;
  local_158 = piVar20;
  piStack_140 = piVar2;
  local_128 = (uint *)((long)puVar19 + 0x6c);
  piStack_110 = (int *)(puVar19 + 0xe);
  puStack_e0 = puVar28;
  local_c8 = local_188;
  lStack_b0 = lStack_170;
  local_98 = piVar20;
  piStack_80 = piVar2;
  puVar21 = (uint *)__of_get_address(*(undefined8 *)(param_1 + 0x2f8),0,0xffffffff,0,0);
  if (puVar21 == (uint *)0x0) {
LAB_0010162c:
    _printk(&DAT_0010406b,"wled_configure");
    iVar15 = -0x16;
LAB_001011fc:
    pcVar26 = "wled configure failed rc:%d\n";
  }
  else {
    uVar14 = (*puVar21 & 0xff00ff00) >> 8 | (*puVar21 & 0xff00ff) << 8;
    *(short *)((long)puVar19 + 0x92) = (short)(uVar14 >> 0x10);
    uVar14 = regmap_read(puVar19[2],(uVar14 >> 0x10) + 1,(long)puVar19 + 0xa4);
    if ((int)uVar14 < 0) {
      puVar25 = &DAT_00104742;
LAB_00101694:
      _printk(puVar25,"wled_configure",uVar14);
      iVar15 = -0x16;
      goto LAB_001011fc;
    }
    puVar22 = (undefined4 *)__of_get_address(*(undefined8 *)(param_1 + 0x2f8),1,0xffffffff,0,0);
    if (puVar22 == (undefined4 *)0x0) goto LAB_0010162c;
    uVar23 = *(undefined8 *)(param_1 + 0x2f8);
    *(ushort *)(puVar19 + 0x12) =
         (ushort)(byte)((uint)*puVar22 >> 0x18) | (ushort)((uint)*puVar22 >> 8) & 0xff00;
    iVar15 = of_property_read_string(uVar23,"label",puVar19);
    if (iVar15 < 0) {
      *puVar19 = **(undefined8 **)(param_1 + 0x2f8);
    }
    uVar14 = *(uint *)puVar19[0x15];
    if ((uVar14 & 0xfffffffe) == 4) {
      ppcVar34 = &local_e8;
      puVar19[0xd] = 0xffffffea0000000f;
      puVar19[0xe] = 0xffffffeaffffffea;
      uVar35 = 0x78;
      uVar36 = 5;
      pcVar27 = wled4_cabc_config;
      *(undefined4 *)(puVar19 + 0xf) = 0;
      *puVar28 = 0x100000004;
      puVar19[0xc] = 0xa0000000b;
    }
    else {
      if ((uVar14 & 0xfffffffe) != 6) {
        puVar25 = &DAT_00104378;
        goto LAB_00101694;
      }
      *(undefined4 *)(puVar19 + 0xf) = 0;
      ppcVar34 = (char **)&local_1a8;
      uVar35 = 0xc0;
      *puVar28 = 0x600000005;
      puVar19[0xc] = 0xaffffffea;
      uVar36 = 8;
      puVar19[0xd] = 0xf;
      puVar19[0xe] = 0x600000000;
      pcVar27 = wled5_cabc_config;
    }
    uVar37 = 0;
    puVar19[0x19] = pcVar27;
    do {
      if ((uVar37 == ((int)uVar35 - 1U & 0xff) / 0x18 + 1) ||
         (uVar32 = uVar37 * 0x18, uVar35 <= uVar32)) goto LAB_001023cc;
      ppcVar9 = ppcVar34 + uVar37 * 3;
      iVar16 = of_property_read_variable_u32_array
                         (*(undefined8 *)(param_1 + 0x2f8),*ppcVar9,&local_1ac,1,0);
      iVar15 = iVar16;
      if (-1 < iVar16) {
        iVar15 = 0;
      }
      if (iVar15 != -0x16) {
        if (iVar16 < 0) {
          if (uVar35 <= uVar32) {
LAB_001023cc:
                    /* WARNING: Does not return */
            pcVar27 = (code *)SoftwareBreakpoint(1,0x1023d0);
            (*pcVar27)();
          }
          _printk(&DAT_0010439d,"wled_configure",*ppcVar9);
          goto LAB_001011fc;
        }
        if (local_1ac != -1) {
          if (((uVar32 + 0x10 <= uVar35) && (7 < uVar35 - (uVar32 + 0x10))) &&
             (uVar29 = uVar37 * 0x18 + 0x10, bVar13 = uVar35 - uVar29 < 8,
             uVar35 >= uVar29 && !bVar13)) {
            uVar31 = 0;
            iVar15 = local_1ac;
            do {
              plVar30 = (long *)ppcVar34[uVar37 * 3 + 2];
              if ((plVar30 == (long *)0x0) || (*(uint *)(plVar30 + 2) <= uVar31)) {
LAB_001011d4:
                if (uVar35 <= uVar32) break;
                _printk(&DAT_0010408d,"wled_configure",*ppcVar9);
                iVar15 = -0x16;
                goto LAB_001011fc;
              }
              pcVar27 = (code *)plVar30[1];
              if (pcVar27 == (code *)0x0) {
                if (*plVar30 != 0) {
                  iVar16 = *(int *)(*plVar30 + uVar31 * 4);
                  if (iVar16 == -1) goto LAB_001011d4;
                  goto LAB_00101134;
                }
                if ((int)uVar31 == iVar15) goto LAB_00101190;
              }
              else {
                if (*(int *)(pcVar27 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
                  pcVar27 = (code *)SoftwareBreakpoint(0x822a,0x101128);
                  (*pcVar27)();
                }
                iVar16 = (*pcVar27)(uVar31 & 0xffffffff);
                if (iVar16 == -1) goto LAB_001011d4;
LAB_00101134:
                iVar15 = local_1ac;
                if (iVar16 == local_1ac) goto LAB_00101190;
              }
              uVar31 = uVar31 + 1;
              if (uVar35 < uVar29 || bVar13) break;
            } while( true );
          }
          goto LAB_001023cc;
        }
        uVar31 = 0;
LAB_00101190:
        if (((uVar35 < uVar32 + 8) || (uVar35 - (uVar32 + 8) < 8)) ||
           ((uVar32 = uVar37 * 0x18 + 8, uVar35 < uVar32 || (uVar35 - uVar32 < 8))))
        goto LAB_001023cc;
        *(int *)ppcVar34[uVar37 * 3 + 1] = (int)uVar31;
      }
      uVar37 = uVar37 + 1;
    } while (uVar37 != uVar36);
    lVar18 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,en-cabc",0);
    if (lVar18 != 0) {
      *(undefined1 *)(puVar19 + 0xf) = 1;
    }
    lVar18 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,ext-pfet-sc-pro",0);
    if (lVar18 != 0) {
      *(undefined1 *)((long)puVar19 + 0x79) = 1;
    }
    lVar18 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,auto-calibration",0);
    if (lVar18 != 0) {
      *(undefined1 *)((long)puVar19 + 0x7a) = 1;
    }
    lVar18 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,use-exp-dimming",0);
    if (lVar18 == 0) {
      if (*(char *)((long)puVar19 + 0x7b) != '\0') goto LAB_001012a8;
    }
    else {
      *(undefined1 *)((long)puVar19 + 0x7b) = 1;
LAB_001012a8:
      if (*(int *)puVar19[0x15] == 7) {
        uVar23 = *(undefined8 *)(param_1 + 0x2f8);
        iVar15 = of_property_count_elems_of_size(uVar23,"qcom,exp-dimming-map",4);
        if (iVar15 == 0x100) {
          iVar15 = of_property_read_variable_u32_array
                             (uVar23,"qcom,exp-dimming-map",puVar19 + 0xbe,0x100,0);
          if (-1 < iVar15) goto LAB_001012f8;
          _dev_err(puVar19[1] + 0x10,"Error in reading qcom,exp-dimming-map, rc=%d\n",iVar15);
        }
        else {
          _dev_err(puVar19[1] + 0x10,"Invalid exponential map length: %d, must be %d bytes length\n"
                   ,iVar15,0x100);
          iVar15 = -0x16;
        }
        _dev_err(puVar19[1] + 0x10,"Reading exponential dimming map failed, rc=%d\n",iVar15);
        goto LAB_001011fc;
      }
    }
LAB_001012f8:
    uVar17 = platform_get_irq_byname(puVar19[1],"sc-irq");
    *(undefined4 *)(puVar19 + 0x16) = uVar17;
    uVar17 = platform_get_irq_byname(puVar19[1],"ovp-irq");
    *(undefined4 *)((long)puVar19 + 0xb4) = uVar17;
    uVar17 = platform_get_irq_byname(puVar19[1],"flash-irq");
    *(undefined4 *)(puVar19 + 0x17) = uVar17;
    uVar17 = platform_get_irq_byname(puVar19[1],"pre-flash-irq");
    *(undefined4 *)((long)puVar19 + 0xbc) = uVar17;
    local_1a8 = (char *)0x0;
    lVar18 = puVar19[1];
    if ((*(uint *)puVar19[0x15] & 0xfffffffe) != 4) {
      of_property_read_variable_u32_array
                (*(undefined8 *)(lVar18 + 0x2f8),"qcom,leds-per-string",(long)puVar19 + 0x5ec,1,0);
      lVar24 = of_get_next_available_child(*(undefined8 *)(puVar19[1] + 0x2f8),0);
      if (lVar24 != 0) {
        piVar3 = (int *)((long)puVar19 + 0x5d4);
        piVar4 = (int *)(puVar19 + 0xbb);
        piVar5 = (int *)((long)puVar19 + 0x5dc);
        piVar6 = (int *)(puVar19 + 0xb9);
        piVar7 = (int *)((long)puVar19 + 0x5cc);
        piVar8 = (int *)(puVar19 + 0xba);
        do {
          iVar15 = of_property_read_string(lVar24,"label",&local_1a8);
          pcVar26 = local_1a8;
          if (-1 < iVar15) {
            iVar15 = strcmp(local_1a8,"flash");
            if (iVar15 == 0) {
              *piVar6 = 0x32;
              iVar15 = of_property_read_variable_u32_array(lVar24,"qcom,wled-flash-fsc",piVar6,1,0);
              if ((iVar15 < 0) || (0xffffffc3 < *piVar6 - 0x3dU)) {
                *piVar7 = 200;
                iVar15 = of_property_read_variable_u32_array
                                   (lVar24,"qcom,wled-flash-step",piVar7,1,0);
                if ((iVar15 < 0) || (0xfffffea0 < *piVar7 - 0x191U)) {
                  *piVar8 = 100;
                  iVar15 = of_property_read_variable_u32_array
                                     (lVar24,"qcom,wled-flash-timer",piVar8,1,0);
                  if ((iVar15 < 0) || (0xfffffb80 < *piVar8 - 0x4b1U)) {
                    iVar15 = of_property_read_string
                                       (lVar24,"qcom,default-led-trigger",puVar19 + 0x28);
                    if (iVar15 < 0) {
                      pcVar26 = "wled_flash";
                      puVar28 = puVar19 + 0x28;
                      goto LAB_001013f0;
                    }
                    goto LAB_001013f4;
                  }
                  pcVar26 = "Incorrect WLED flash safety time rc:%d\n";
                }
                else {
                  pcVar26 = "Incorrect WLED flash step delay rc:%d\n";
                }
              }
              else {
                pcVar26 = "Incorrect WLED flash FSC rc:%d\n";
              }
            }
            else {
              iVar15 = strcmp(pcVar26,"torch");
              if (iVar15 != 0) {
                iVar15 = strcmp(pcVar26,"switch");
                if (iVar15 == 0) {
                  iVar15 = of_property_read_string(lVar24,"qcom,default-led-trigger",puVar19 + 0x92)
                  ;
                  if (iVar15 < 0) {
                    pcVar26 = "wled_switch";
                    puVar28 = puVar19 + 0x92;
LAB_001013f0:
                    *puVar28 = pcVar26;
                  }
                  goto LAB_001013f4;
                }
                iVar15 = -0x16;
                _dev_err(lVar1,"wled configure failed rc:%d\n",0xffffffea);
                goto LAB_001022dc;
              }
              *piVar3 = 0x32;
              iVar15 = of_property_read_variable_u32_array(lVar24,"qcom,wled-torch-fsc",piVar3,1,0);
              if ((iVar15 < 0) || (0xffffffc3 < *piVar3 - 0x3dU)) {
                *piVar4 = 200;
                iVar15 = of_property_read_variable_u32_array
                                   (lVar24,"qcom,wled-torch-step",piVar4,1,0);
                if ((iVar15 < 0) || (0xfffffea0 < *piVar4 - 0x191U)) {
                  *piVar5 = 600;
                  iVar15 = of_property_read_variable_u32_array
                                     (lVar24,"qcom,wled-torch-timer",piVar5,1,0);
                  if ((iVar15 < 0) || (0xfffffb80 < *piVar5 - 0x4b1U)) {
                    iVar15 = of_property_read_string
                                       (lVar24,"qcom,default-led-trigger",puVar19 + 0x5d);
                    if (iVar15 < 0) {
                      pcVar26 = "wled_torch";
                      puVar28 = puVar19 + 0x5d;
                      goto LAB_001013f0;
                    }
                    goto LAB_001013f4;
                  }
                  pcVar26 = "Incorrect WLED torch safety time rc:%d\n";
                }
                else {
                  pcVar26 = "Incorrect WLED torch step delay rc:%d\n";
                }
              }
              else {
                pcVar26 = "Incorrect WLED torch FSC rc:%d\n";
              }
            }
            _dev_err(lVar18 + 0x10,pcVar26,0);
            break;
          }
LAB_001013f4:
          lVar24 = of_get_next_available_child(*(undefined8 *)(puVar19[1] + 0x2f8),lVar24);
        } while (lVar24 != 0);
      }
    }
    __mutex_init(puVar19 + 5,"&wled->lock",&wled_probe___key);
    local_1cc = 0x800;
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"default-brightness",&local_1cc,1,0);
    uVar23 = *(undefined8 *)(param_1 + 0x2f8);
    *(undefined4 *)(puVar19 + 0x13) = local_1cc;
    local_1cc = 0xfff;
    of_property_read_variable_u32_array(uVar23,"max-brightness",&local_1cc,1,0);
    *(undefined4 *)((long)puVar19 + 0x9c) = local_1cc;
    uVar14 = *(uint *)puVar19[0x15];
    if (((uVar14 & 0xfffffffe) == 6) && (*(int *)(puVar19 + 0xe) != 0)) {
      *(undefined4 *)((long)puVar19 + 0x9c) = 0xfff;
      uVar14 = *(uint *)puVar19[0x15];
    }
    if ((uVar14 & 0xfffffffe) == 4) {
      bVar11 = *(byte *)(puVar19 + 0xd);
      local_1a8 = (char *)((ulong)local_1a8._4_4_ << 0x20);
      iVar15 = regmap_update_bits_base
                         (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4d,3,
                          *(undefined4 *)((long)puVar19 + 0x5c),0,0,0);
      if (((-1 < iVar15) &&
          (iVar15 = regmap_update_bits_base
                              (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4e,7,
                               *(undefined4 *)(puVar19 + 0xb),0,0,0), -1 < iVar15)) &&
         (iVar15 = regmap_update_bits_base
                             (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4c,0xf,
                              *(undefined4 *)(puVar19 + 0xc),0,0,0), -1 < iVar15)) {
        uVar14 = 0;
        if (bVar11 != 0) {
          uVar35 = 0;
          do {
            iVar16 = (int)uVar35;
            if ((bVar11 >> (uVar35 & 0x3f) & 1) != 0) {
              iVar15 = regmap_update_bits_base
                                 (puVar19[2],
                                  iVar16 * 0x10 + (uint)*(ushort *)(puVar19 + 0x12) + 0x50 & 0xffff,
                                  0x80,0x80,0,0,0);
              if ((iVar15 < 0) ||
                 (iVar15 = regmap_update_bits_base
                                     (puVar19[2],
                                      iVar16 * 0x10 + (uint)*(ushort *)(puVar19 + 0x12) + 0x52 &
                                      0xffff,0xf,*(undefined4 *)((long)puVar19 + 100),0,0,0),
                 iVar15 < 0)) goto LAB_00102144;
              uVar14 = uVar14 | 1 << (ulong)(iVar16 + 4U & 0x1f);
            }
            uVar35 = (ulong)(iVar16 + 1U);
          } while (bVar11 >> (ulong)(iVar16 + 1U & 0x1f) != 0);
        }
        if (*(char *)((long)puVar19 + 0xc4) == '\0') {
          cVar12 = *(char *)(puVar19 + 0xf);
          if (*piVar2 != 0) {
            iVar16 = 0x56;
            uVar33 = 1;
            do {
              iVar15 = regmap_update_bits_base
                                 (puVar19[2],iVar16 + (uint)*(ushort *)(puVar19 + 0x12),0x80,
                                  (ulong)(cVar12 != '\0') << 7,0,0,0);
              if (iVar15 < 0) goto LAB_00102144;
              iVar16 = iVar16 + 0x10;
              uVar10 = uVar33 & 0x1f;
              uVar33 = uVar33 + 1;
            } while (*piVar2 >> uVar10 != 0);
            cVar12 = *(char *)(puVar19 + 0xf);
          }
          if (cVar12 == '\0') {
            *(undefined1 *)((long)puVar19 + 0xc4) = 1;
          }
        }
        iVar15 = regmap_write(puVar19[2],*(ushort *)(puVar19 + 0x12) + 0x46,uVar14 & 0xff);
        if (-1 < iVar15) {
          iVar15 = regmap_update_bits_base
                             (puVar19[2],*(ushort *)(puVar19 + 0x12) + 0x47,0xf,0,0,0,0);
          if ((iVar15 < 0) ||
             (iVar15 = regmap_update_bits_base
                                 (puVar19[2],*(ushort *)(puVar19 + 0x12) + 0x47,0xf,0xf,0,0,0),
             iVar15 < 0)) {
            _printk(&DAT_001040f0,"wled4_setup",iVar15);
            goto LAB_00102144;
          }
          iVar15 = wled_auto_calibrate_at_init(puVar19);
          if (iVar15 < 0) goto LAB_00102144;
          if (*(int *)(puVar19 + 0x16) < 0) {
LAB_00101c6c:
            if ((*(char *)((long)puVar19 + 0x79) != '\0') &&
               ((iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0xd0,0xa5),
                iVar15 < 0 ||
                (iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0xe2,9),
                iVar15 < 0)))) goto LAB_00102144;
            if (-1 < *(int *)((long)puVar19 + 0xb4)) {
              iVar15 = devm_request_threaded_irq
                                 (puVar19[1] + 0x10,*(int *)((long)puVar19 + 0xb4),0,
                                  wled_ovp_irq_handler,0x2000,"wled_ovp_irq",puVar19);
              if (iVar15 < 0) {
                uVar17 = *(undefined4 *)((long)puVar19 + 0xb4);
                puVar25 = &DAT_0010452a;
                goto LAB_001023e0;
              }
              iVar15 = regmap_read(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x46,&local_1a8);
              if ((iVar15 == 0) && (-1 < (char)local_1a8)) {
                disable_irq(*(undefined4 *)((long)puVar19 + 0xb4));
                iVar15 = 0;
                *(undefined1 *)((long)puVar19 + 0xc1) = 1;
                goto LAB_00102144;
              }
            }
LAB_00102138:
            iVar15 = 0;
          }
          else {
            iVar15 = devm_request_threaded_irq
                               (puVar19[1] + 0x10,*(int *)(puVar19 + 0x16),0,wled_sc_irq_handler,
                                0x2000,"wled_sc_irq",puVar19);
            if (-1 < iVar15) {
              iVar15 = regmap_update_bits_base
                                 (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x5e,0x80,0x80,0,0,
                                  0);
              if (iVar15 < 0) goto LAB_00102144;
              goto LAB_00101c6c;
            }
            uVar17 = *(undefined4 *)(puVar19 + 0x16);
            puVar25 = &DAT_00104bd9;
LAB_001023e0:
            pcVar26 = "wled4_setup";
LAB_001023e8:
            _printk(puVar25,pcVar26,uVar17,iVar15);
          }
        }
      }
    }
    else {
      local_1a8 = (char *)((ulong)local_1a8._4_4_ << 0x20);
      bVar11 = *(byte *)(puVar19 + 0xd);
      iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x69,0xf);
      if (((((iVar15 < 0) ||
            (iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x61,0xff),
            iVar15 < 0)) ||
           (iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x62,0), iVar15 < 0
           )) || ((iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x62,1),
                  iVar15 < 0 ||
                  (iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 99,0xff),
                  iVar15 < 0)))) ||
         ((iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 100,0), iVar15 < 0
          || (iVar15 = regmap_write(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 100,1),
             iVar15 < 0)))) {
LAB_00101ad4:
        _dev_err(puVar19[1] + 0x10,"failed to setup WLED flash/torch rc:%d\n",iVar15);
      }
      else {
        iVar15 = *piVar2;
        if (iVar15 == 0) {
          uVar14 = 0;
        }
        else {
          uVar14 = 0;
          uVar35 = 0;
          do {
            if (((ulong)(long)iVar15 >> (uVar35 & 0x3f) & 1) != 0) {
              uVar14 = uVar14 | 1 << (ulong)((int)uVar35 + 4U & 0x1f);
              *(char *)(puVar19 + 0xbd) = *(char *)(puVar19 + 0xbd) + '\x01';
            }
            uVar33 = (int)uVar35 + 1;
            uVar35 = (ulong)uVar33;
          } while (iVar15 >> (uVar33 & 0x1f) != 0);
        }
        iVar15 = regmap_update_bits_base
                           (puVar19[2],*(ushort *)(puVar19 + 0x12) + 0xb1,0xf0,uVar14 & 0xff,0,0,0);
        if (iVar15 < 0) goto LAB_00101ad4;
        iVar15 = *(int *)((long)puVar19 + 0x5dc);
        uVar14 = 0;
        if (iVar15 < 600) {
          if (iVar15 == 100) {
            uVar14 = 0x10;
          }
          else if (iVar15 == 200) {
            uVar14 = 0x20;
          }
          else if (iVar15 == 400) {
            uVar14 = 0x30;
          }
        }
        else if (iVar15 < 1000) {
          if (iVar15 == 600) {
            uVar14 = 0x40;
          }
          else if (iVar15 == 800) {
            uVar14 = 0x50;
          }
        }
        else if (iVar15 == 1000) {
          uVar14 = 0x60;
        }
        else if (iVar15 == 0x4b0) {
          uVar14 = 0x70;
        }
        iVar15 = *(int *)(puVar19 + 0xba);
        uVar33 = 0;
        if (iVar15 < 600) {
          if (iVar15 == 100) {
            uVar33 = 1;
          }
          else if (iVar15 == 200) {
            uVar33 = 2;
          }
          else if (iVar15 == 400) {
            uVar33 = 3;
          }
        }
        else if (iVar15 < 1000) {
          if (iVar15 == 600) {
            uVar33 = 4;
          }
          else if (iVar15 == 800) {
            uVar33 = 5;
          }
        }
        else if (iVar15 == 1000) {
          uVar33 = 6;
        }
        else if (iVar15 == 0x4b0) {
          uVar33 = 7;
        }
        iVar16 = regmap_write(puVar19[2],*(ushort *)(puVar19 + 0x12) + 0xb5,uVar33 | uVar14);
        iVar15 = iVar16;
        if (-1 < iVar16) {
          iVar15 = 0;
        }
        if (iVar16 < 0) goto LAB_00101ad4;
      }
      iVar15 = regmap_update_bits_base
                         (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4d,0xf,
                          *(undefined4 *)((long)puVar19 + 0x5c),0,0,0);
      if (((-1 < iVar15) &&
          (iVar15 = regmap_update_bits_base
                              (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4e,7,
                               *(undefined4 *)(puVar19 + 0xb),0,0,0), -1 < iVar15)) &&
         ((*piVar20 == -0x16 ||
          (iVar15 = regmap_update_bits_base
                              (puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x4c,0xf,*piVar20,0,0,
                               0), -1 < iVar15)))) {
        if (bVar11 == 0) {
          uVar14 = 0;
        }
        else {
          uVar35 = 0;
          uVar14 = 0;
          do {
            iVar16 = (int)uVar35;
            if ((bVar11 >> (uVar35 & 0x3f) & 1) != 0) {
              iVar15 = regmap_update_bits_base
                                 (puVar19[2],
                                  iVar16 * 0x10 + (uint)*(ushort *)(puVar19 + 0x12) + 0x72 & 0xffff,
                                  0xf,*(undefined4 *)((long)puVar19 + 100),0,0,0);
              if (iVar15 < 0) goto LAB_00102144;
              regmap_update_bits_base
                        (puVar19[2],
                         iVar16 * 0x10 + (uint)*(ushort *)(puVar19 + 0x12) + 0x73 & 0xffff,3,
                         *(int *)((long)puVar19 + 0x6c) != 0,0,0,0);
              uVar14 = uVar14 | 1 << (ulong)(iVar16 + 4U & 0x1f);
            }
            uVar35 = (ulong)(iVar16 + 1U);
          } while (bVar11 >> (ulong)(iVar16 + 1U & 0x1f) != 0);
        }
        iVar15 = wled5_cabc_config(puVar19,*(int *)(puVar19 + 0xe) != 0);
        if (((-1 < iVar15) &&
            (iVar15 = regmap_update_bits_base
                                (puVar19[2],*(short *)(puVar19 + 0x12) + 0x50,0x80,
                                 (ulong)(*(int *)((long)puVar19 + 0x6c) == 0) << 7,0,0,0),
            -1 < iVar15)) &&
           (iVar15 = regmap_update_bits_base
                               (puVar19[2],*(short *)(puVar19 + 0x12) + 0x60,0x80,
                                (ulong)(*(int *)((long)puVar19 + 0x6c) == 1) << 7,0,0,0),
           -1 < iVar15)) {
          uVar33 = *(uint *)((long)puVar19 + 0x6c);
          if (1 < uVar33) {
                    /* WARNING: Does not return */
            pcVar27 = (code *)SoftwareBreakpoint(0x5512,0x102480);
            (*pcVar27)();
          }
          local_1a8 = (char *)CONCAT44(local_1a8._4_4_,
                                       (uint)(*(int *)((long)puVar19 + 0x9c) == 0x7fff));
          iVar15 = regmap_write(puVar19[2],
                                *(short *)(puVar19 + 0x12) +
                                (ushort)*(byte *)((long)&wled5_brt_wid_sel_reg + (ulong)uVar33));
          if ((-1 < iVar15) &&
             (iVar15 = regmap_write(puVar19[2],*(ushort *)(puVar19 + 0x12) + 0x46,uVar14 & 0xff),
             -1 < iVar15)) {
            iVar15 = wled_sync_toggle(puVar19);
            if (iVar15 < 0) {
              _printk(&DAT_001040f0,"wled5_setup",iVar15);
            }
            else {
              iVar15 = wled_auto_calibrate_at_init(puVar19);
              if (-1 < iVar15) {
                if (*(int *)puVar19[0x15] == 7) {
                  local_1a8 = (char *)(CONCAT44(local_1a8._4_4_,*(uint *)((long)puVar19 + 0x74)) |
                                      0x80);
                  iVar15 = regmap_update_bits_base
                                     (puVar19[2],*(ushort *)(puVar19 + 0x12) + 0xb8,0x8f,
                                      *(uint *)((long)puVar19 + 0x74) | 0x80,0,0,0);
                  if (iVar15 < 0) goto LAB_00102144;
                }
                if ((*(char *)((long)puVar19 + 0x7b) == '\0') ||
                   (iVar15 = wled_program_exp_dimming(puVar19), -1 < iVar15)) {
                  if (-1 < *(int *)((long)puVar19 + 0xb4)) {
                    iVar15 = devm_request_threaded_irq
                                       (puVar19[1] + 0x10,*(int *)((long)puVar19 + 0xb4),0,
                                        wled_ovp_irq_handler,0x2000,"wled_ovp_irq",puVar19);
                    if (iVar15 < 0) {
                      uVar17 = *(undefined4 *)((long)puVar19 + 0xb4);
                      puVar25 = &DAT_0010452a;
                      pcVar26 = "wled5_setup";
                      goto LAB_001023e8;
                    }
                    iVar15 = regmap_read(puVar19[2],*(ushort *)((long)puVar19 + 0x92) + 0x46,
                                         &local_1a8);
                    if ((iVar15 == 0) && (-1 < (char)local_1a8)) {
                      disable_irq(*(undefined4 *)((long)puVar19 + 0xb4));
                      *(undefined1 *)((long)puVar19 + 0xc1) = 1;
                    }
                  }
                  if ((*(int *)(puVar19 + 0x17) < 0) ||
                     (iVar15 = devm_request_threaded_irq
                                         (puVar19[1] + 0x10,*(int *)(puVar19 + 0x17),0,
                                          wled_flash_irq_handler,0x2000,"wled_flash_irq",puVar19),
                     -1 < iVar15)) {
                    iVar15 = *(int *)((long)puVar19 + 0xbc);
                  }
                  else {
                    _printk(&DAT_00104165,"wled5_setup",*(undefined4 *)(puVar19 + 0x17),iVar15);
                    iVar15 = *(int *)((long)puVar19 + 0xbc);
                  }
                  if ((-1 < iVar15) &&
                     (iVar15 = devm_request_threaded_irq
                                         (puVar19[1] + 0x10,iVar15,0,wled_flash_irq_handler,0x2000,
                                          "wled_pre_flash_irq",puVar19), iVar15 < 0)) {
                    _printk(&DAT_001042dd,"wled5_setup",*(undefined4 *)((long)puVar19 + 0xbc),iVar15
                           );
                  }
                  goto LAB_00102138;
                }
                _dev_err(puVar19[1] + 0x10,"Programming exponential dimming map failed, rc=%d\n",
                         iVar15);
              }
            }
          }
        }
      }
    }
LAB_00102144:
    if (iVar15 < 0) {
      pcVar26 = "wled setup failed rc:%d\n";
    }
    else {
      uVar17 = *(undefined4 *)((long)puVar19 + 0x9c);
      *(undefined8 **)(param_1 + 0xa8) = puVar19;
      local_1c0 = 0;
      local_1b0 = 0;
      local_1b8 = 1;
      local_1c8 = CONCAT44(uVar17,local_1cc);
      uVar35 = devm_backlight_device_register(lVar1,*puVar19,lVar1,puVar19,wled_ops,&local_1c8);
      if ((uVar35 == 0) || (0xfffffffffffff000 < uVar35)) {
        iVar16 = (int)uVar35;
        if (uVar35 < 0xfffffffffffff001) {
          iVar16 = 0;
        }
        pcVar26 = "failed to register backlight rc:%d\n";
        iVar15 = -0x13;
        if (iVar16 != 0) {
          iVar15 = iVar16;
        }
      }
      else {
        if ((*(uint *)puVar19[0x15] & 0xfffffffe) == 4) {
LAB_001022bc:
          lVar18 = devm_kmalloc(lVar1,0x18,0xdc0);
          iVar15 = -0xc;
          if (lVar18 != 0) {
            iVar15 = 0;
          }
          puVar19[3] = lVar18;
          goto LAB_001022dc;
        }
        iVar15 = 0;
        *(undefined4 *)(puVar19 + 0xbc) = 0;
        if (*(int *)(puVar19 + 0xd) != 0) {
          uVar14 = 1;
          do {
            uVar33 = uVar14 & 0x1f;
            iVar15 = iVar15 + *(int *)(puVar19 + 0xb9);
            uVar14 = uVar14 + 1;
          } while (*(int *)(puVar19 + 0xd) >> uVar33 != 0);
        }
        puVar19[0x1a] = "wled_flash";
        *(int *)((long)puVar19 + 0xdc) = iVar15;
        puVar19[0x1e] = wled_flash_brightness_set;
        iVar15 = devm_led_classdev_register_ext(puVar19[1] + 0x10,puVar19 + 0x1a,0);
        if (-1 < iVar15) {
          if (*piVar2 == 0) {
            iVar15 = 0;
          }
          else {
            iVar15 = 0;
            uVar14 = 1;
            do {
              uVar33 = uVar14 & 0x1f;
              iVar15 = iVar15 + *(int *)((long)puVar19 + 0x5d4);
              uVar14 = uVar14 + 1;
            } while (*piVar2 >> uVar33 != 0);
          }
          *(int *)((long)puVar19 + 0x284) = iVar15;
          puVar19[0x4f] = "wled_torch";
          puVar19[0x53] = wled_torch_brightness_set;
          iVar15 = devm_led_classdev_register_ext(puVar19[1] + 0x10,puVar19 + 0x4f,0);
          if (-1 < iVar15) {
            puVar19[0x84] = "wled_switch";
            puVar19[0x88] = wled_switch_brightness_set;
            iVar15 = devm_led_classdev_register_ext(puVar19[1] + 0x10,puVar19 + 0x84,0);
            if (-1 < iVar15) {
              iVar15 = sysfs_create_file_ns(puVar19[0x8e],&wled_flash_attrs,0);
              if (-1 < iVar15) goto LAB_001022bc;
              _printk(&DAT_001044ca,"wled_flash_device_register",iVar15);
            }
          }
        }
        pcVar26 = "failed to register WLED flash/torch rc:%d\n";
      }
    }
  }
  _dev_err(lVar1,pcVar26,iVar15);
LAB_001022dc:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar15;
}



//------------------------------------------------------------
// wled5_cabc_config @ 00102484 size=284
// signature: undefined wled5_cabc_config(void)
// callers: [wled_probe]
//------------------------------------------------------------

int wled5_cabc_config(long param_1,ulong param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (*(char *)(param_1 + 0xc4) == '\0') {
    if ((param_2 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined1 *)(param_1 + 0x70);
    }
    if (1 < *(uint *)(param_1 + 0x6c)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1025a0);
      (*pcVar1)();
    }
    iVar2 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x10),
                       (uint)*(ushort *)(param_1 + 0x90) +
                       (uint)*(byte *)((long)&wled5_src_sel_reg + (ulong)*(uint *)(param_1 + 0x6c)),
                       3,uVar3,0,0,0);
    if (iVar2 < 0) {
      _printk(&DAT_0010483c,"wled5_cabc_config",iVar2);
      return iVar2;
    }
    if (((*(int *)(param_1 + 0x70) == 0) &&
        (*(undefined1 *)(param_1 + 0xc4) = 1, **(int **)(param_1 + 0xa8) == 7)) &&
       ((iVar2 = regmap_update_bits_base
                           (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x57,0x80,
                            0,0,0,0), iVar2 < 0 ||
        (iVar2 = regmap_update_bits_base
                           (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xbc,7,0,0
                            ,0,0), iVar2 < 0)))) {
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// wled4_cabc_config @ 001025a4 size=168
// signature: undefined wled4_cabc_config(void)
// callers: []
//------------------------------------------------------------

undefined8 wled4_cabc_config(long param_1,ulong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 0xc4) == '\0') {
    if (*(int *)(param_1 + 0x68) != 0) {
      uVar3 = 0x80;
      if ((param_2 & 1) == 0) {
        uVar3 = 0;
      }
      iVar4 = 0x56;
      uVar5 = 1;
      do {
        uVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x10),iVar4 + (uint)*(ushort *)(param_1 + 0x90)
                           ,0x80,uVar3,0,0,0);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        iVar4 = iVar4 + 0x10;
        uVar1 = uVar5 & 0x1f;
        uVar5 = uVar5 + 1;
      } while (*(int *)(param_1 + 0x68) >> uVar1 != 0);
    }
    if (*(char *)(param_1 + 0x78) == '\0') {
      *(undefined1 *)(param_1 + 0xc4) = 1;
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// wled_switch_freq_values_fn @ 00102650 size=16
// signature: undefined wled_switch_freq_values_fn(void)
// callers: []
//------------------------------------------------------------

uint wled_switch_freq_values_fn(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 + 1U != 0) {
    uVar1 = 0x2580 / (param_1 + 1U);
  }
  return uVar1;
}



//------------------------------------------------------------
// wled5_boost_i_limit_values_fn @ 00102664 size=16
// signature: undefined wled5_boost_i_limit_values_fn(void)
// callers: [wled_probe]
//------------------------------------------------------------

int wled5_boost_i_limit_values_fn(int param_1)

{
  return param_1 * 0xaf + 0x20d;
}



//------------------------------------------------------------
// wled5_ovp_values_fn @ 00102678 size=16
// signature: undefined wled5_ovp_values_fn(void)
// callers: []
//------------------------------------------------------------

int wled5_ovp_values_fn(int param_1)

{
  return param_1 * -0x5dc + 0x9664;
}



//------------------------------------------------------------
// wled_sync_toggle @ 00102688 size=112
// signature: undefined wled_sync_toggle(void)
// callers: [wled_probe]
//------------------------------------------------------------

void wled_sync_toggle(long param_1)

{
  int iVar1;
  
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x47,0xf,0,0,0,0)
  ;
  if (-1 < iVar1) {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x47,0xf,0xf,0,0,0);
  }
  return;
}



//------------------------------------------------------------
// wled_auto_calibrate_at_init @ 001026f8 size=348
// signature: undefined wled_auto_calibrate_at_init(void)
// callers: [wled_probe]
//------------------------------------------------------------

int wled_auto_calibrate_at_init(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char local_40 [4];
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = '\0';
  if (*(char *)(param_1 + 0x7a) == '\0') {
    iVar3 = 0;
    goto LAB_00102820;
  }
  iVar3 = wled_get_ovp_fault_status(param_1,local_40);
  if (-1 < iVar3) {
    if (local_40[0] == '\0') goto LAB_00102820;
    local_3c = 0;
    if ((**(uint **)(param_1 + 0xa8) & 0xfffffffe) == 4) {
      uVar4 = 10000;
LAB_00102760:
      usleep_range_state(uVar4,uVar4 + 1000,2);
    }
    else {
      iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x5f,
                          &local_3c);
      if (iVar3 == 0) {
        bVar2 = (&DAT_00105b4d)[(ulong)local_3c & 7];
        uVar4 = (uint)bVar2 * 1000;
        if (uVar4 >> 5 < 0x271) goto LAB_00102760;
      }
      else {
        bVar2 = 0x14;
      }
      msleep(bVar2);
    }
    iVar3 = wled_get_ovp_fault_status(param_1,local_40);
    if (-1 < iVar3) {
      if (local_40[0] != '\0') {
        mutex_lock(param_1 + 0x28);
        iVar3 = wled_auto_calibrate(param_1);
        mutex_unlock(param_1 + 0x28);
      }
      goto LAB_00102820;
    }
  }
  _printk(&DAT_00104638,"wled_auto_calibrate_at_init",iVar3);
LAB_00102820:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wled_sc_irq_handler @ 00102858 size=348
// signature: undefined wled_sc_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 wled_sc_irq_handler(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar1 = regmap_read(*(undefined8 *)(param_2 + 0x10),*(ushort *)(param_2 + 0x92) + 8,&local_2c);
  if (iVar1 < 0) {
    _printk(&DAT_00104c0b,"wled_sc_irq_handler",iVar1);
    goto LAB_0010294c;
  }
  iVar1 = *(int *)(param_2 + 0xa0) + 1;
  *(int *)(param_2 + 0xa0) = iVar1;
  _printk(&DAT_001048f3,"wled_sc_irq_handler",iVar1,local_2c);
  mutex_lock(param_2 + 0x28);
  uVar2 = wled_module_enable(param_2,0);
  if ((int)uVar2 < 0) {
    puVar5 = &DAT_00104995;
LAB_001029a0:
    _printk(puVar5,"wled_sc_irq_handler",uVar2);
  }
  else {
    lVar3 = ktime_get();
    if (lVar3 - *(long *)(param_2 + 0x80) < 0x3b9acde8) {
      uVar2 = *(uint *)(param_2 + 0xa0);
      if (5 < uVar2) {
        puVar5 = &DAT_00105054;
        goto LAB_001029a0;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0xa0) = 0;
    }
    uVar4 = ktime_get();
    *(undefined8 *)(param_2 + 0x80) = uVar4;
    msleep(0x14);
    uVar2 = wled_module_enable(param_2,1);
    if ((int)uVar2 < 0) {
      puVar5 = &DAT_00104e31;
      goto LAB_001029a0;
    }
  }
  mutex_unlock(param_2 + 0x28);
LAB_0010294c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wled_ovp_irq_handler @ 001029b8 size=492
// signature: undefined wled_ovp_irq_handler(void)
// callers: []
//------------------------------------------------------------

int wled_ovp_irq_handler(undefined8 param_1,long param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ushort uVar6;
  char local_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_2c[0] = '\0';
  iVar3 = wled_get_ovp_fault_status(param_2,local_2c);
  if (iVar3 < 0) {
    _printk(&DAT_00104638,"wled_ovp_irq_handler",iVar3);
    goto LAB_00102b2c;
  }
  if ((local_2c[0] != '\0') && (*(char *)(param_2 + 0x7a) != '\0')) {
    mutex_lock(param_2 + 0x28);
    if (*(char *)(param_2 + 0xc2) == '\0') {
      if ((*(int *)(param_2 + 0xb4) < 1) || (*(char *)(param_2 + 0xc1) != '\0')) {
        uVar6 = *(ushort *)(param_2 + 0x94);
        if (uVar6 != 0) goto LAB_00102a30;
LAB_00102a74:
        uVar4 = ktime_get();
        *(undefined8 *)(param_2 + 0x88) = uVar4;
        *(short *)(param_2 + 0x94) = *(short *)(param_2 + 0x94) + 1;
      }
      else {
        disable_irq_nosync();
        *(undefined1 *)(param_2 + 0xc1) = 1;
        uVar6 = *(ushort *)(param_2 + 0x94);
        if (uVar6 == 0) goto LAB_00102a74;
LAB_00102a30:
        uVar1 = **(uint **)(param_2 + 0xa8) & 0xfffffffe;
        if (uVar1 == 4) {
          lVar5 = ktime_get();
          if (lVar5 - *(long *)(param_2 + 0x88) < 0x3b9acde8) {
            uVar6 = *(short *)(param_2 + 0x94) + 1;
            sVar2 = 0;
            if (uVar6 < 5) {
              sVar2 = *(short *)(param_2 + 0x94) + 1;
            }
            *(short *)(param_2 + 0x94) = sVar2;
            if (4 < uVar6) goto LAB_00102afc;
          }
          else {
            *(undefined2 *)(param_2 + 0x94) = 0;
          }
        }
        else if (uVar1 == 6) {
          if (uVar6 < 2) {
            *(undefined2 *)(param_2 + 0x94) = 2;
          }
          else {
            ktime_get();
            *(undefined2 *)(param_2 + 0x94) = 0;
LAB_00102afc:
            wled_auto_calibrate(param_2);
          }
        }
      }
      if ((0 < *(int *)(param_2 + 0xb4)) && (*(char *)(param_2 + 0xc1) != '\0')) {
        enable_irq();
        *(undefined1 *)(param_2 + 0xc1) = 0;
      }
    }
    else {
      _printk(&DAT_00104935,"handle_ovp_fault");
      iVar3 = regmap_update_bits_base
                        (*(undefined8 *)(param_2 + 0x10),*(ushort *)(param_2 + 0x92) + 0x46,0x80,0,0
                         ,0,0);
      if (iVar3 == 0) {
        *(undefined1 *)(param_2 + 0xc3) = 1;
      }
    }
    mutex_unlock(param_2 + 0x28);
  }
  iVar3 = 1;
LAB_00102b2c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wled_get_ovp_fault_status @ 00102ba4 size=280
// signature: undefined wled_get_ovp_fault_status(void)
// callers: [wled_ovp_irq_handler, wled_auto_calibrate, wled_auto_calibrate_at_init]
//------------------------------------------------------------

int wled_get_ovp_fault_status(long param_1,undefined1 *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  *param_2 = 0;
  local_40 = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x10,
                      (long)&local_40 + 4);
  if (iVar3 < 0) {
    puVar4 = &DAT_001045fe;
  }
  else {
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 8,&local_40);
    if (-1 < iVar3) {
      if ((local_40._4_1_ >> 1 & 1) != 0) {
        *param_2 = 1;
      }
      uVar1 = **(uint **)(param_1 + 0xa8) & 0xfffffffe;
      if (uVar1 == 6) {
        if ((local_40 & 0x12) == 0) goto LAB_00102c88;
      }
      else if ((uVar1 != 4) || (((byte)local_40 >> 1 & 1) == 0)) goto LAB_00102c88;
      *param_2 = 1;
      goto LAB_00102c88;
    }
    puVar4 = &DAT_001050fb;
  }
  _printk(puVar4,"wled_get_ovp_fault_status",iVar3);
LAB_00102c88:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wled_auto_calibrate @ 00102cbc size=1260
// signature: undefined wled_auto_calibrate(void)
// callers: [wled_ovp_irq_handler, wled_auto_calibrate_at_init]
//------------------------------------------------------------

int wled_auto_calibrate(long param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  char cVar5;
  code *pcVar6;
  byte bVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char local_74 [4];
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar4 = sp_el0;
  iVar8 = 0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  bVar1 = *(byte *)(param_1 + 0x68);
  local_74[0] = '\0';
  if (*(char *)(param_1 + 0xc2) != '\0') goto LAB_00103168;
  iVar8 = regmap_read(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x46,&local_70);
  if (iVar8 < 0) {
    puVar9 = &DAT_00104eae;
  }
  else {
    iVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x46,0x80,0,0,0
                       ,0);
    if (iVar8 < 0) {
LAB_00103060:
      puVar9 = &DAT_00104cef;
    }
    else {
      iVar8 = wled_set_brightness(param_1,0x200);
      if (iVar8 < 0) {
        puVar9 = &DAT_00104129;
      }
      else {
        if (*(int *)(*(code **)(param_1 + 200) + -4) != 0x2d8a8bf7) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102d7c);
          (*pcVar6)();
        }
        iVar8 = (**(code **)(param_1 + 200))(param_1,0);
        if (iVar8 < 0) goto LAB_00103168;
        iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x46,0);
        if (iVar8 < 0) {
          puVar9 = &DAT_00104dee;
        }
        else {
          if (bVar1 == 0) {
            uVar12 = 0;
          }
          else {
            uVar12 = 0;
            uVar13 = 4;
            do {
              uVar3 = uVar13 - 3;
              iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),
                                   *(ushort *)(param_1 + 0x92) + 0x48,uVar3);
              if (iVar8 < 0) {
                puVar9 = &DAT_00103fae;
LAB_001030f4:
                _printk(puVar9,"wled_auto_calibrate",uVar3,iVar8);
                goto LAB_00103168;
              }
              uVar2 = 1 << (ulong)(uVar13 & 0x1f);
              iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),
                                   *(ushort *)(param_1 + 0x90) + 0x46,uVar2 & 0xff);
              if (iVar8 < 0) {
                puVar9 = &DAT_00104966;
                goto LAB_001030f4;
              }
              iVar8 = regmap_update_bits_base
                                (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x46,
                                 0x80,0x80,0,0,0);
              if (iVar8 < 0) goto LAB_00103110;
              local_6c = 0;
              if ((**(uint **)(param_1 + 0xa8) & 0xfffffffe) == 4) {
                uVar10 = 10000;
LAB_00102e34:
                usleep_range_state(uVar10,uVar10 + 1000,2);
              }
              else {
                iVar8 = regmap_read(*(undefined8 *)(param_1 + 0x10),
                                    *(ushort *)(param_1 + 0x92) + 0x5f,&local_6c);
                if (iVar8 == 0) {
                  bVar7 = (&DAT_00105b4d)[(ulong)local_6c & 7];
                  uVar10 = (uint)bVar7 * 1000;
                  if (uVar10 >> 5 < 0x271) goto LAB_00102e34;
                }
                else {
                  bVar7 = 0x14;
                }
                msleep(bVar7);
              }
              iVar8 = wled_get_ovp_fault_status(param_1,local_74);
              cVar5 = local_74[0];
              if (iVar8 < 0) {
                puVar9 = &DAT_00104638;
                goto LAB_00103158;
              }
              iVar8 = regmap_update_bits_base
                                (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x46,
                                 0x80,0,0,0,0);
              if (iVar8 < 0) goto LAB_00103060;
              if (cVar5 != '\0') {
                uVar2 = 0;
              }
              uVar13 = uVar13 + 1;
              uVar12 = uVar2 | uVar12;
            } while (bVar1 >> (ulong)(uVar3 & 0x1f) != 0);
            uVar12 = uVar12 & 0xff;
          }
          if (local_70 != uVar12) {
            _printk(&DAT_0010466b,"wled_auto_calibrate",local_70,uVar12);
            local_70 = uVar12;
          }
          if (uVar12 == 0) {
            _printk(&DAT_001048cc,"wled_auto_calibrate");
            *(undefined1 *)(param_1 + 0xc3) = 1;
            goto LAB_00103168;
          }
          iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x46,
                               uVar12);
          if (iVar8 < 0) {
            puVar9 = &DAT_001042a3;
          }
          else {
            uVar12 = **(uint **)(param_1 + 0xa8);
            if ((uVar12 & 0xfffffffe) == 6) {
              iVar8 = regmap_update_bits_base
                                (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb1,
                                 0xf0,local_70,0,0,0);
              if (iVar8 < 0) goto LAB_00103168;
              uVar12 = **(uint **)(param_1 + 0xa8);
            }
            if (((uVar12 & 0xfffffffe) == 4) && (bVar1 != 0)) {
              iVar11 = 0x50;
              uVar12 = 4;
              do {
                iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),
                                     iVar11 + (uint)*(ushort *)(param_1 + 0x90),
                                     (local_70 >> (ulong)(uVar12 & 0x1f) & 1) << 7);
                if (iVar8 < 0) {
                  puVar9 = &DAT_00104a88;
                  goto LAB_00103158;
                }
                uVar13 = uVar12 - 3;
                iVar11 = iVar11 + 0x10;
                uVar12 = uVar12 + 1;
              } while (bVar1 >> (ulong)(uVar13 & 0x1f) != 0);
            }
            if (*(int *)(*(code **)(param_1 + 200) + -4) != 0x2d8a8bf7) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102fcc);
              (*pcVar6)();
            }
            iVar8 = (**(code **)(param_1 + 200))(param_1,1);
            if (iVar8 < 0) goto LAB_00103168;
            iVar8 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x48,
                                 0);
            if (iVar8 < 0) {
              puVar9 = &DAT_00104461;
            }
            else {
              iVar8 = wled_set_brightness(param_1,*(undefined4 *)(param_1 + 0x98));
              if (iVar8 < 0) {
                puVar9 = &DAT_00104af0;
              }
              else {
                iVar8 = regmap_update_bits_base
                                  (*(undefined8 *)(param_1 + 0x10),
                                   *(ushort *)(param_1 + 0x92) + 0x46,0x80,0x80,0,0,0);
                if (-1 < iVar8) {
                  usleep_range_state(10000,11000,2);
                  *(undefined1 *)(param_1 + 0xc2) = 1;
                  goto LAB_00103168;
                }
LAB_00103110:
                puVar9 = &DAT_00104f1d;
              }
            }
          }
        }
      }
    }
  }
LAB_00103158:
  _printk(puVar9,"wled_auto_calibrate",iVar8);
LAB_00103168:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// wled_set_brightness @ 001031a8 size=496
// signature: undefined wled_set_brightness(void)
// callers: [wled_update_status, wled_auto_calibrate]
//------------------------------------------------------------

void wled_set_brightness(long param_1,ulong param_2)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined1 local_40;
  byte local_3f;
  undefined1 local_3c;
  byte local_3b;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar9 = **(uint **)(param_1 + 0xa8) & 0xfffffffe;
  bVar6 = (byte)(param_2 >> 8);
  if (uVar9 == 6) {
    uVar9 = *(uint *)(param_1 + 0x9c);
    if ((param_2 & 0xffff) == 0) {
      param_2 = 0;
    }
    else if (((uint)param_2 & 0xffff) < (uVar9 / 1000 & 0xffff)) {
      bVar6 = (byte)(uVar9 / 0x3e800);
      param_2 = (ulong)uVar9 / 1000;
    }
    local_3c = (undefined1)param_2;
    local_3b = 0x7f;
    if (uVar9 != 0x7fff) {
      local_3b = 0xf;
    }
    local_3b = bVar6 & local_3b;
    if (1 < *(uint *)(param_1 + 0x6c)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x103398);
      (*pcVar4)();
    }
    uVar5 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),
                              (uint)*(ushort *)(param_1 + 0x90) +
                              (uint)*(byte *)((long)&wled5_brt_reg +
                                             (ulong)*(uint *)(param_1 + 0x6c)),&local_3c,2);
    if ((-1 < (int)uVar5) &&
       (uVar5 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x65,0xf,0,
                           0,0,0), -1 < (int)uVar5)) {
      uVar7 = 1;
      if (*(int *)(param_1 + 0x6c) != 0) {
        uVar7 = 2;
      }
      uVar5 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0x65,3,uVar7,
                         0,0,0);
    }
  }
  else {
    if (uVar9 == 4) {
      bVar1 = *(byte *)(param_1 + 0x68);
      if ((param_2 & 0xffff) == 0) {
        param_2 = 0;
      }
      else {
        uVar9 = *(int *)(param_1 + 0x9c) << 2;
        if (((uint)param_2 & 0xffff) < (uVar9 / 1000 & 0xffff)) {
          bVar6 = (byte)(uVar9 / 0x3e800);
          param_2 = (ulong)uVar9 / 1000;
        }
      }
      local_3f = bVar6 & 0xf;
      local_40 = (undefined1)param_2;
      if (bVar1 != 0) {
        iVar8 = 0x57;
        uVar9 = 1;
        do {
          uVar5 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),
                                    iVar8 + (uint)*(ushort *)(param_1 + 0x90),&local_40,2);
          if ((int)uVar5 < 0) goto LAB_001032b0;
          uVar2 = uVar9 & 0x1f;
          iVar8 = iVar8 + 0x10;
          uVar9 = uVar9 + 1;
        } while (bVar1 >> (ulong)uVar2 != 0);
      }
    }
    uVar5 = 0;
  }
LAB_001032b0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wled_module_enable @ 00103398 size=304
// signature: undefined wled_module_enable(void)
// callers: [wled_update_status, wled_sc_irq_handler, wled_program_exp_dimming]
//------------------------------------------------------------

int wled_module_enable(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0xc3) == '\0') {
    if (**(int **)(param_1 + 0xa8) == 6) {
      uVar2 = 3;
      if (param_2 != 0) {
        uVar2 = 0;
      }
      iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0xef,uVar2)
      ;
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x92) + 0x46,0x80,
                       param_2 << 7,0,0,0);
    if (-1 < iVar1) {
      if ((param_2 == 0) || (**(int **)(param_1 + 0xa8) != 6)) {
        if (param_2 == 0) {
          if (*(int *)(param_1 + 0xb4) < 1) {
            return iVar1;
          }
          if (*(char *)(param_1 + 0xc1) == '\0') {
            disable_irq();
            *(undefined1 *)(param_1 + 0xc1) = 1;
            return iVar1;
          }
          return iVar1;
        }
      }
      else {
        iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb6,0);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
      usleep_range_state(10000,11000,2);
      if ((0 < *(int *)(param_1 + 0xb4)) && (*(char *)(param_1 + 0xc1) != '\0')) {
        enable_irq();
        *(undefined1 *)(param_1 + 0xc1) = 0;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// wled_program_exp_dimming @ 001034c8 size=364
// signature: undefined wled_program_exp_dimming(void)
// callers: [wled_probe]
//------------------------------------------------------------

int wled_program_exp_dimming(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  iVar2 = 0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (**(int **)(param_1 + 0xa8) == 7) {
    iVar2 = wled_module_enable(param_1,0);
    if (iVar2 < 0) {
      _dev_err(*(long *)(param_1 + 8) + 0x10,"wled disable failed rc:%d\n",iVar2);
    }
    else {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb8,0x40,
                         0x40,0,0,0);
      if (-1 < iVar2) {
        uVar3 = 0;
        puVar4 = (undefined4 *)(param_1 + 0x5f4);
        do {
          local_3c = CONCAT13((char)((uint)*puVar4 >> 8),CONCAT12((char)*puVar4,(short)puVar4[-1]))
                     & 0x7fff7fff;
          iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xc9,
                               uVar3 & 0xffffffff);
          if ((iVar2 < 0) ||
             (iVar2 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),
                                        *(ushort *)(param_1 + 0x90) + 0xc0,&local_3c,4), iVar2 < 0))
          {
            iVar2 = regmap_update_bits_base
                              (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb8,
                               0x40,0,0,0,0);
            break;
          }
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 2;
        } while (uVar3 != 0x80);
      }
      wled_module_enable(param_1,1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wled_flash_irq_handler @ 00103638 size=128
// signature: undefined wled_flash_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 wled_flash_irq_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_2 + 0x10),*(ushort *)(param_2 + 0x92) + 8,&local_2c);
  regmap_read(*(undefined8 *)(param_2 + 0x10),*(ushort *)(param_2 + 0x92) + 7,&local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wled_update_status @ 001036bc size=904
// signature: undefined wled_update_status(void)
// callers: []
//------------------------------------------------------------

int wled_update_status(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  uint uVar8;
  
  lVar7 = *(long *)(param_1 + 0xa4);
  if (((*(int *)(param_1 + 4) == 0) && (*(int *)(param_1 + 6) == 0)) &&
     (((byte)param_1[10] >> 1 & 1) == 0)) {
    uVar1 = *param_1;
    uVar8 = (uint)uVar1;
    mutex_lock(lVar7 + 0x28);
    if (uVar1 == 0) goto LAB_001037c8;
    iVar2 = wled_set_brightness(lVar7,uVar1);
    if (-1 < iVar2) {
      if ((**(uint **)(lVar7 + 0xa8) & 0xfffffffe) == 6) {
        if (((*(char *)(lVar7 + 0xc0) == '\0') && (*(char *)(lVar7 + 0xc4) != '\0')) &&
           (uVar8 <= ((*(int *)(lVar7 + 0x9c) + 99U) / 100 & 0xffff))) {
          iVar5 = 0x58;
          if (*(uint *)(lVar7 + 0xa4) < 6) {
            iVar5 = 0xe5;
          }
          uVar6 = 0x20;
          if (5 < *(uint *)(lVar7 + 0xa4)) {
            uVar6 = 1;
          }
          iVar2 = regmap_update_bits_base
                            (*(undefined8 *)(lVar7 + 0x10),iVar5 + (uint)*(ushort *)(lVar7 + 0x92),
                             uVar6,0,0,0,0);
          if (iVar2 < 0) {
            _printk(&DAT_00104d20,"wled5_sample_hold_control",iVar5,iVar2);
            puVar3 = &DAT_00104316;
            goto LAB_001038d8;
          }
        }
        else {
          iVar2 = 0;
        }
      }
      if (*(char *)(lVar7 + 0xc0) == '\x01') {
LAB_00103794:
        if ((**(uint **)(lVar7 + 0xa8) & 0xfffffffe) == 6) {
          if (((*(char *)(lVar7 + 0xc0) == '\0') && (*(char *)(lVar7 + 0xc4) != '\0')) &&
             (uVar8 <= ((*(int *)(lVar7 + 0x9c) + 99U) / 100 & 0xffff))) {
            usleep_range_state(5000,0x1392,2);
            iVar5 = 0x58;
            if (*(uint *)(lVar7 + 0xa4) < 6) {
              iVar5 = 0xe5;
            }
            uVar6 = 0x20;
            if (5 < *(uint *)(lVar7 + 0xa4)) {
              uVar6 = 1;
            }
            iVar2 = regmap_update_bits_base
                              (*(undefined8 *)(lVar7 + 0x10),iVar5 + (uint)*(ushort *)(lVar7 + 0x92)
                               ,uVar6,uVar6,0,0,0);
            if (iVar2 < 0) {
              _printk(&DAT_00104d20,"wled5_sample_hold_control",iVar5,iVar2);
              puVar3 = &DAT_0010455d;
              goto LAB_001038d8;
            }
            goto LAB_001039fc;
          }
          iVar2 = 0;
          uVar4 = 1;
        }
        else {
LAB_001039fc:
          uVar4 = 1;
        }
        goto LAB_0010381c;
      }
      iVar2 = wled_module_enable(lVar7,1);
      if (iVar2 < 0) {
        puVar3 = &DAT_00104e31;
        goto LAB_001038d8;
      }
      if ((**(int **)(lVar7 + 0xa8) != 7) ||
         (iVar2 = regmap_update_bits_base
                            (*(undefined8 *)(lVar7 + 0x10),*(ushort *)(lVar7 + 0x90) + 0xb8,0xf,
                             *(undefined4 *)(lVar7 + 0x74),0,0,0), -1 < iVar2)) goto LAB_00103794;
      goto LAB_001038c0;
    }
    puVar3 = &DAT_00104f4d;
  }
  else {
    mutex_lock(lVar7 + 0x28);
LAB_001037c8:
    if ((**(int **)(lVar7 + 0xa8) == 7) &&
       (iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(lVar7 + 0x10),*(ushort *)(lVar7 + 0x90) + 0xb8,0xf,0,0,0,
                           0), iVar2 < 0)) {
LAB_001038c0:
      puVar3 = &DAT_001043bd;
    }
    else {
      iVar2 = wled_module_enable(lVar7,0);
      if (iVar2 < 0) {
        puVar3 = &DAT_00104995;
      }
      else {
        uVar4 = 0;
        uVar8 = 0;
LAB_0010381c:
        *(undefined1 *)(lVar7 + 0xc0) = uVar4;
        if (((**(uint **)(lVar7 + 0xa8) & 0xfffffffe) != 4) ||
           ((iVar2 = regmap_update_bits_base
                               (*(undefined8 *)(lVar7 + 0x10),*(ushort *)(lVar7 + 0x90) + 0x47,0xf,0
                                ,0,0,0), -1 < iVar2 &&
            (iVar2 = regmap_update_bits_base
                               (*(undefined8 *)(lVar7 + 0x10),*(ushort *)(lVar7 + 0x90) + 0x47,0xf,
                                0xf,0,0,0), -1 < iVar2)))) {
          *(uint *)(lVar7 + 0x98) = uVar8;
          goto LAB_0010388c;
        }
        puVar3 = &DAT_001046bd;
      }
    }
  }
LAB_001038d8:
  _printk(puVar3,"wled_update_status",iVar2);
LAB_0010388c:
  mutex_unlock(lVar7 + 0x28);
  return iVar2;
}



//------------------------------------------------------------
// wled_get_brightness @ 00103a48 size=12
// signature: undefined wled_get_brightness(void)
// callers: []
//------------------------------------------------------------

undefined4 wled_get_brightness(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0x148) + 0x98);
}



//------------------------------------------------------------
// wled_flash_brightness_set @ 00103a58 size=236
// signature: undefined wled_flash_brightness_set(void)
// callers: []
//------------------------------------------------------------

void wled_flash_brightness_set(long param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  _raw_spin_lock(param_1 + 0x510);
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_1 + 0x4fc);
    if ((int)uVar2 < 0x32) {
      uVar2 = 0;
    }
    else if (uVar2 < 0x191) {
      uVar2 = (uVar2 + 0x19 >> 1 & 0x7fff) / 0x19 - 1 & 0xff;
    }
    else {
      uVar2 = 7;
    }
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + -0xc0),*(ushort *)(param_1 + -0x3e) + 0x65,7,uVar2,
                       0,0,0);
    if (iVar1 < 0) {
      _printk(&DAT_0010419a,"wled_flash_set_step_delay",iVar1);
      goto LAB_00103b0c;
    }
  }
  iVar1 = wled_flash_set_fsc(param_1 + -0xd0,param_2,*(undefined4 *)(param_1 + 0x4f8));
  if (-1 < iVar1) {
    *(uint *)(param_1 + 0x514) = (uint)(param_2 != 0) << 1;
  }
LAB_00103b0c:
  _raw_spin_unlock(param_1 + 0x510);
  return;
}



//------------------------------------------------------------
// wled_torch_brightness_set @ 00103b48 size=240
// signature: undefined wled_torch_brightness_set(void)
// callers: []
//------------------------------------------------------------

void wled_torch_brightness_set(long param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  _raw_spin_lock(param_1 + 0x368);
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_1 + 0x360);
    if ((int)uVar2 < 0x32) {
      uVar2 = 0;
    }
    else if (uVar2 < 0x191) {
      uVar2 = (uVar2 + 0x19 >> 1 & 0x7fff) / 0x19 - 1 & 0xff;
    }
    else {
      uVar2 = 7;
    }
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + -0x268),*(ushort *)(param_1 + -0x1e6) + 0x65,7,
                       uVar2,0,0,0);
    if (iVar1 < 0) {
      _printk(&DAT_0010419a,"wled_flash_set_step_delay",iVar1);
      goto LAB_00103c00;
    }
  }
  iVar1 = wled_flash_set_fsc(param_1 + -0x278,param_2,*(undefined4 *)(param_1 + 0x35c));
  if (-1 < iVar1) {
    *(uint *)(param_1 + 0x36c) = (uint)(param_2 != 0);
  }
LAB_00103c00:
  _raw_spin_unlock(param_1 + 0x368);
  return;
}



//------------------------------------------------------------
// wled_switch_brightness_set @ 00103c3c size=236
// signature: undefined wled_switch_brightness_set(void)
// callers: []
//------------------------------------------------------------

void wled_switch_brightness_set(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c4) == 0) {
      return;
    }
    uVar2 = 0x40;
    uVar3 = 0x80;
  }
  _raw_spin_lock(param_1 + 0x1c0);
  if (*(int *)(param_1 + 0x1c4) != 1) {
    uVar2 = uVar3;
  }
  iVar1 = regmap_write(*(undefined8 *)(param_1 + -0x410),*(ushort *)(param_1 + -0x390) + 0xb0,uVar2)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00104c41,"wled_switch_brightness_set",iVar1);
  }
  if ((param_2 == 0) &&
     (iVar1 = regmap_write(*(undefined8 *)(param_1 + -0x410),*(ushort *)(param_1 + -0x390) + 0xb6,1)
     , iVar1 < 0)) {
    _printk(&DAT_001041ce,"wled_switch_brightness_set",iVar1);
  }
  _raw_spin_unlock(param_1 + 0x1c0);
  return;
}



//------------------------------------------------------------
// wled_flash_set_fsc @ 00103d28 size=268
// signature: undefined wled_flash_set_fsc(void)
// callers: [wled_flash_brightness_set, wled_torch_brightness_set]
//------------------------------------------------------------

int wled_flash_set_fsc(long param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 0x5e8);
  if (bVar1 == 0) {
    _printk(&DAT_00104e57,"wled_flash_set_fsc");
    iVar2 = -0x16;
  }
  else {
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar2 = param_2 / (int)(uint)bVar1;
    }
    if (param_3 <= iVar2) {
      iVar2 = param_3;
    }
    iVar4 = -2;
    if (0 < iVar2) {
      iVar4 = 2;
    }
    iVar2 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb2,0xf,
                       (uint)((ulong)((long)(iVar4 + iVar2) * 0x66666667) >> 0x21) -
                       (iVar4 + iVar2 >> 0x1f) & 0xff,0,0,0);
    if (iVar2 < 0) {
      puVar3 = &DAT_00105174;
    }
    else {
      iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb3,0);
      if ((-1 < iVar2) &&
         (iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(ushort *)(param_1 + 0x90) + 0xb3,1)
         , -1 < iVar2)) {
        return iVar2;
      }
      puVar3 = &DAT_0010508e;
    }
    _printk(puVar3,"wled_flash_set_fsc",iVar2);
  }
  return iVar2;
}



//------------------------------------------------------------
// wled_flash_max_avail_current_show @ 00103e38 size=156
// signature: undefined wled_flash_max_avail_current_show(void)
// callers: []
//------------------------------------------------------------

long wled_flash_max_avail_current_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = wled_get_max_avail_current(*(undefined8 *)(param_1 + 0x98),&local_2c);
  if (iVar2 < 0) {
    _printk(&DAT_001046e1,"wled_flash_max_avail_current_show",iVar2);
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_001045eb,local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// init_module @ 00103ef0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wled_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103f20 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wled_driver);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock @ 00107000 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [wled_flash_brightness_set, wled_torch_brightness_set, wled_switch_brightness_set, wled_flash_led_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00107008 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [wled_probe, wled_get_max_avail_current, wled_flash_led_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00107010 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [wled_flash_brightness_set, wled_torch_brightness_set, wled_switch_brightness_set, wled_flash_led_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107018 size=1
// signature: undefined _printk(void)
// callers: [wled_get_ovp_fault_status, wled_update_status, wled_iio_get_prop, wled_probe, wled_ovp_irq_handler, wled_sc_irq_handler, wled_torch_brightness_set, wled_flash_set_fsc, wled5_cabc_config, wled_switch_brightness_set, wled_flash_max_avail_current_show, wled_flash_brightness_set, wled_auto_calibrate, wled_get_max_avail_current, wled_flash_led_prepare, wled_auto_calibrate_at_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00107020 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [wled_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00107028 size=1
// signature: undefined power_supply_get_property(void)
// callers: [wled_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_battery_charger_get_prop @ 00107030 size=1
// signature: undefined qti_battery_charger_get_prop(void)
// callers: [wled_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_battery_charger_get_prop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00107038 size=1
// signature: undefined ___ratelimit(void)
// callers: [wled_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wled_get_ovp_fault_status, wled_probe, wled_ovp_irq_handler, wled_sc_irq_handler, wled_set_brightness, wled_program_exp_dimming, wled_auto_calibrate, wled_get_max_avail_current, wled_auto_calibrate_at_init, wled_flash_irq_handler, wled_flash_max_avail_current_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107048 size=1
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
// platform_driver_unregister @ 00107050 size=1
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
// devm_iio_channel_get @ 00107058 size=1
// signature: undefined devm_iio_channel_get(void)
// callers: [wled_iio_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iio_channel_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iio_read_channel_processed @ 00107060 size=1
// signature: undefined iio_read_channel_processed(void)
// callers: [wled_iio_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iio_read_channel_processed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00107068 size=1
// signature: undefined dev_get_regmap(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00107070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00107078 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00107080 size=1
// signature: undefined __of_get_address(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00107088 size=1
// signature: undefined regmap_read(void)
// callers: [wled_get_ovp_fault_status, wled_probe, wled_sc_irq_handler, wled_auto_calibrate, wled_auto_calibrate_at_init, wled_flash_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00107090 size=1
// signature: undefined of_property_read_string(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00107098 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001070a0 size=1
// signature: undefined _dev_err(void)
// callers: [wled_probe, wled_program_exp_dimming]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001070a8 size=1
// signature: undefined of_find_property(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001070b0 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 001070b8 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001070c0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001070c8 size=1
// signature: undefined __mutex_init(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001070d0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wled_update_status, wled_probe, wled_sync_toggle, wled_ovp_irq_handler, wled_torch_brightness_set, wled_program_exp_dimming, wled4_cabc_config, wled_flash_set_fsc, wled5_cabc_config, wled_module_enable, wled_flash_brightness_set, wled_set_brightness, wled_auto_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001070d8 size=1
// signature: undefined regmap_write(void)
// callers: [wled_probe, wled_program_exp_dimming, wled_auto_calibrate, wled_flash_set_fsc, wled_switch_brightness_set, wled_module_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001070e0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001070e8 size=1
// signature: undefined disable_irq(void)
// callers: [wled_probe, wled_module_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_backlight_device_register @ 001070f0 size=1
// signature: undefined devm_backlight_device_register(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_backlight_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_register_ext @ 001070f8 size=1
// signature: undefined devm_led_classdev_register_ext(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00107100 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [wled_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00107108 size=1
// signature: undefined usleep_range_state(void)
// callers: [wled_update_status, wled_auto_calibrate, wled_module_enable, wled_auto_calibrate_at_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00107110 size=1
// signature: undefined msleep(void)
// callers: [wled_sc_irq_handler, wled_auto_calibrate, wled_auto_calibrate_at_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00107118 size=1
// signature: undefined mutex_lock(void)
// callers: [wled_update_status, wled_ovp_irq_handler, wled_sc_irq_handler, wled_auto_calibrate_at_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107120 size=1
// signature: undefined mutex_unlock(void)
// callers: [wled_update_status, wled_ovp_irq_handler, wled_sc_irq_handler, wled_auto_calibrate_at_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00107128 size=1
// signature: undefined ktime_get(void)
// callers: [wled_ovp_irq_handler, wled_sc_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00107130 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [wled_ovp_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00107138 size=1
// signature: undefined enable_irq(void)
// callers: [wled_ovp_irq_handler, wled_module_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00107140 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [wled_set_brightness, wled_program_exp_dimming]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00107148 size=1
// signature: undefined scnprintf(void)
// callers: [wled_flash_max_avail_current_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



