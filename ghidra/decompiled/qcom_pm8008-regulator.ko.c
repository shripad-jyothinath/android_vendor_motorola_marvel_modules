// Decompiled by Ghidra 12.2
// Program: qcom_pm8008-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// pm8008_chip_probe @ 00100534 size=648
// signature: undefined pm8008_chip_probe(void)
// callers: []
//------------------------------------------------------------

ulong pm8008_chip_probe(long param_1)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  undefined *puVar6;
  long *plVar7;
  long local_70 [2];
  long *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  byte local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar3 = (long *)devm_kmalloc(param_1 + 0x10,400,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar5 = 0xfffffff4;
    goto LAB_001006bc;
  }
  lVar4 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  plVar3[1] = lVar4;
  if (lVar4 == 0) {
    _printk(&DAT_00102f13,"pm8008_chip_probe");
    uVar5 = 0xffffffea;
    goto LAB_001006bc;
  }
  *plVar3 = param_1 + 0x10;
  __mutex_init(plVar3 + 0x2a,"&chip->lock",&pm8008_chip_probe___key);
  local_70[0] = *plVar3;
  local_50 = 0;
  uStack_48 = 0;
  local_70[1] = 0;
  uStack_58 = 0;
  *(undefined4 *)((long)plVar3 + 100) = 0;
  local_3c[0] = 0;
  plVar3[0xb] = (long)pm8008_chip_ops;
  plVar7 = plVar3 + 3;
  *plVar7 = (long)"qcom,pm8008-chip-en";
  plVar3[5] = (long)"qcom,pm8008-chip-en";
  local_60 = plVar3;
  uVar1 = regmap_bulk_read(plVar3[1],0x950,local_3c,1);
  if ((int)uVar1 < 0) {
    uVar5 = (ulong)uVar1;
    _printk(&DAT_00102ce9,"pm8008_read",0x950);
    _printk(&DAT_00102a14,"_pm8008_chip_is_enabled",*plVar7,uVar5);
LAB_00100740:
    puVar6 = &DAT_00102cab;
  }
  else {
    *(byte *)(plVar3 + 0x31) = local_3c[0] & 1;
    *(byte *)((long)plVar3 + 0x189) = local_3c[0] & 1;
    uVar5 = devm_regulator_register(*plVar3,plVar7,local_70);
    plVar3[2] = uVar5;
    if (uVar5 < 0xfffffffffffff001) {
      iVar2 = devm_regulator_debug_register(*plVar3,uVar5);
      if (iVar2 != 0) {
        _printk(&DAT_00102832,"pm8008_chip_init_regulator",iVar2);
      }
    }
    else {
      plVar3[2] = 0;
      if ((int)uVar5 < 0) goto LAB_00100740;
    }
    iVar2 = of_irq_get_byname(*(undefined8 *)(*plVar3 + 0x2e8),&DAT_00102fcc);
    *(int *)(plVar3 + 0x30) = iVar2;
    if (iVar2 < 0) {
LAB_001006b4:
      uVar5 = 0;
      *(long **)(param_1 + 0xa8) = plVar3;
      goto LAB_001006bc;
    }
    uVar1 = devm_request_threaded_irq(*plVar3,iVar2,0,pm8008_ocp_irq,0x2000,&DAT_00102fcc,plVar3);
    if ((int)uVar1 < 0) {
      uVar5 = (ulong)uVar1;
      puVar6 = &DAT_00102b91;
    }
    else {
      uVar5 = regmap_update_bits_base(plVar3[1],0x959,8,8,0,0,0);
      if (-1 < (int)uVar5) goto LAB_001006b4;
      uVar5 = uVar5 & 0xffffffff;
      _printk(&DAT_00102872,"pm8008_masked_write",8,0x959,8);
      puVar6 = &DAT_00102b21;
    }
  }
  _printk(puVar6,"pm8008_chip_probe",uVar5 & 0xffffffff);
LAB_001006bc:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// pm8008_chip_remove @ 001007c0 size=140
// signature: undefined pm8008_chip_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8008_chip_remove(long param_1)

{
  int iVar1;
  
  iVar1 = regmap_update_bits_base(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 8),0x950,1,0,0,0,0);
  if (iVar1 < 0) {
    _printk(&DAT_00102872,"pm8008_masked_write",0,0x950,1);
    _printk(&DAT_00102e62,"pm8008_chip_remove",iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// pm8008_ocp_irq @ 00100850 size=44
// signature: undefined pm8008_ocp_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8008_ocp_irq(undefined8 param_1,long param_2)

{
  regulator_notifier_call_chain(*(undefined8 *)(param_2 + 0x10),2,0);
  return 1;
}



//------------------------------------------------------------
// pm8008_chip_enable @ 00100880 size=248
// signature: undefined pm8008_chip_enable(void)
// callers: []
//------------------------------------------------------------

int pm8008_chip_enable(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  if (*(char *)(lVar2 + 0x18a) == '\0') {
    mutex_lock(lVar2 + 0x150);
    *(undefined1 *)(lVar2 + 0x188) = 1;
    if (*(char *)(lVar2 + 0x189) == '\x01') {
      iVar1 = 0;
    }
    else {
      iVar1 = regmap_update_bits_base(*(undefined8 *)(lVar2 + 8),0x950,1,1,0,0,0);
      if (iVar1 < 0) {
        _printk(&DAT_00102872,"pm8008_masked_write",1,0x950,1);
        _printk(&DAT_00102e37,"pm8008_chip_aggregate",*(undefined8 *)(lVar2 + 0x18),"enable",iVar1);
        *(undefined1 *)(lVar2 + 0x188) = 0;
      }
      else {
        iVar1 = 0;
        *(undefined1 *)(lVar2 + 0x189) = 1;
      }
    }
    mutex_unlock(lVar2 + 0x150);
  }
  else {
    iVar1 = *(char *)(lVar2 + 0x188) + -1;
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8008_chip_disable @ 0010097c size=292
// signature: undefined pm8008_chip_disable(void)
// callers: []
//------------------------------------------------------------

int pm8008_chip_disable(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = rdev_get_drvdata();
  if (*(char *)(lVar4 + 0x18a) == '\0') {
    mutex_lock(lVar4 + 0x150);
    iVar2 = *(int *)(lVar4 + 0x184);
    iVar3 = 0;
    *(undefined1 *)(lVar4 + 0x188) = 0;
    if ((bool)*(char *)(lVar4 + 0x189) != (iVar2 != 0)) {
      iVar3 = regmap_update_bits_base(*(undefined8 *)(lVar4 + 8),0x950,1,iVar2 != 0,0,0,0);
      if (iVar3 < 0) {
        _printk(&DAT_00102872,"pm8008_masked_write",iVar2 != 0,0x950,1);
        pcVar1 = "enable";
        if (iVar2 == 0) {
          pcVar1 = "disable";
        }
        _printk(&DAT_00102e37,"pm8008_chip_aggregate",*(undefined8 *)(lVar4 + 0x18),pcVar1,iVar3);
        *(undefined1 *)(lVar4 + 0x188) = 1;
      }
      else {
        iVar3 = 0;
        *(bool *)(lVar4 + 0x189) = iVar2 != 0;
      }
    }
    mutex_unlock(lVar4 + 0x150);
  }
  else {
    iVar3 = -(int)*(char *)(lVar4 + 0x188);
  }
  return iVar3;
}



//------------------------------------------------------------
// pm8008_chip_is_enabled @ 00100aa4 size=32
// signature: undefined pm8008_chip_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 pm8008_chip_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x188);
}



//------------------------------------------------------------
// pm8008_chip_suspend @ 00100ac8 size=20
// signature: undefined pm8008_chip_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8008_chip_suspend(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x18a) = 1;
  return 0;
}



//------------------------------------------------------------
// pm8008_chip_resume @ 00100ae0 size=20
// signature: undefined pm8008_chip_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8008_chip_resume(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x18a) = 0;
  return 0;
}



//------------------------------------------------------------
// pm8008_regulator_probe @ 00100af8 size=2196
// signature: undefined pm8008_regulator_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100bd0) */
/* WARNING: Removing unreachable block (ram,0x00100be0) */

ulong pm8008_regulator_probe(long param_1)

{
  byte *pbVar1;
  long lVar2;
  long *plVar3;
  short sVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long *plVar15;
  size_t sVar16;
  long lVar17;
  ulong uVar18;
  char *pcVar19;
  char *__s;
  long lVar20;
  long lVar21;
  undefined *puVar22;
  long lVar23;
  int iVar24;
  char *local_b8;
  byte local_ac [4];
  undefined4 local_a8;
  int local_a4;
  long local_a0;
  long local_98;
  long *local_90;
  long local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 local_6c [4];
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  if (lVar10 == 0) {
    _printk(&DAT_00102f13,"pm8008_regulator_probe");
    uVar12 = 0xffffffea;
    goto LAB_00101340;
  }
  lVar2 = param_1 + 0x10;
  local_b8 = (char *)0x0;
  lVar11 = of_match_node(&pm8008_regulator_match_table,*(undefined8 *)(param_1 + 0x2f8));
  if (lVar11 == 0) {
    _dev_err(lVar2,"could not find compatible string match\n");
    uVar18 = 0xffffffed;
LAB_00101324:
    uVar12 = uVar18 & 0xffffffff;
  }
  else {
    uVar6 = *(undefined4 *)(lVar11 + 0xc0);
    lVar11 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,enable-ocp-broadcast",0);
    uVar12 = devm_regulator_get(lVar2,"pm8008_en");
    if (uVar12 < 0xfffffffffffff001) {
      lVar13 = rdev_get_drvdata(*(undefined8 *)(uVar12 + 0x78));
      if (lVar13 != 0) {
        lVar14 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0);
        if (lVar14 != 0) {
          do {
            plVar15 = (long *)devm_kmalloc(lVar2,0x1a0,0xdc0);
            if (plVar15 == (long *)0x0) {
              uVar18 = 0xfffffff4;
              goto LAB_00101324;
            }
            *plVar15 = lVar2;
            plVar15[1] = lVar10;
            *(bool *)((long)plVar15 + 0x18c) = lVar11 != 0;
            plVar15[0x2a] = uVar12;
            plVar15[0x2b] = lVar14;
            plVar15[0x2c] = lVar13;
            *(undefined4 *)(plVar15 + 0x33) = uVar6;
            iVar7 = of_property_read_string(lVar14,"regulator-name",&local_b8);
            __s = local_b8;
            if (iVar7 == 0) {
              lVar23 = plVar15[0x2b];
              local_80 = 0;
              uStack_78 = 0;
              ppuVar5 = &pm8008_reg_data;
              if ((int)plVar15[0x33] != 0) {
                ppuVar5 = &pm8010_reg_data;
              }
              lVar20 = *plVar15;
              local_90 = (long *)0x0;
              local_88 = 0;
              local_a0 = 0;
              local_98 = 0;
              puVar22 = *ppuVar5;
              local_a8 = 0;
              local_ac[0] = 0;
              sVar16 = strlen(local_b8);
              lVar17 = strnstr(__s,puVar22,sVar16);
              lVar21 = 0;
              if (lVar17 == 0) {
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_00102f10,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 1;
                  goto LAB_00100d98;
                }
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_001027bc,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 2;
                  goto LAB_00100d98;
                }
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_00102ae8,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 3;
                  goto LAB_00100d98;
                }
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_0010266c,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 4;
                  goto LAB_00100d98;
                }
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_00102b8e,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 5;
                  goto LAB_00100d98;
                }
                sVar16 = strlen(__s);
                lVar17 = strnstr(__s,&DAT_00102e8e,sVar16);
                if (lVar17 != 0) {
                  lVar21 = 6;
                  goto LAB_00100d98;
                }
                puVar22 = &DAT_00102a95;
LAB_00101204:
                _printk(puVar22,"pm8008_register_ldo",__s);
                uVar18 = 0xffffffea;
              }
              else {
LAB_00100d98:
                uVar8 = of_property_read_variable_u32_array(lVar23,&DAT_00102931,&local_a8,1,0);
                if ((int)uVar8 < 0) {
                  uVar18 = (ulong)uVar8;
                  puVar22 = &DAT_00102fd0;
LAB_001012f4:
                  pcVar19 = "pm8008_register_ldo";
LAB_00101300:
                  _printk(puVar22,pcVar19,__s,uVar18);
                }
                else {
                  *(short *)(plVar15 + 0x30) = (short)local_a8;
                  puVar22 = ppuVar5[lVar21 * 6 + 4];
                  if ((puVar22 != (undefined *)0x0) &&
                     (iVar7 = *(int *)(ppuVar5 + lVar21 * 6 + 5), iVar7 != 0)) {
                    iVar24 = 0;
                    do {
                      pbVar1 = puVar22 + (long)iVar24 * 2;
                      sVar4 = (short)plVar15[0x30] + (ushort)*pbVar1;
                      uVar8 = regmap_bulk_write(plVar15[1],sVar4,pbVar1 + 1,1);
                      if ((int)uVar8 < 0) {
                        uVar18 = (ulong)uVar8;
                        _printk(&DAT_001025a2,"pm8008_write",sVar4);
                        goto LAB_00101308;
                      }
                      iVar24 = iVar24 + 1;
                    } while (iVar7 != iVar24);
                  }
                  *(undefined4 *)((long)plVar15 + 0x184) = *(undefined4 *)(ppuVar5 + lVar21 * 6 + 3)
                  ;
                  of_property_read_variable_u32_array
                            (lVar23,"qcom,hpm-min-load",(long)plVar15 + 0x184,1,0);
                  local_a4 = -0x16;
                  of_property_read_variable_u32_array(lVar23,"qcom,init-voltage",&local_a4,1,0);
                  lVar17 = of_find_property(lVar23,"qcom,strong-pd",0);
                  if (lVar17 != 0) {
                    sVar4 = (short)plVar15[0x30] + 0xa0;
                    uVar8 = regmap_update_bits_base(plVar15[1],sVar4,0x80,0x80,0,0,0);
                    if ((int)uVar8 < 0) {
                      uVar18 = (ulong)uVar8;
                      _printk(&DAT_00102872,"pm8008_masked_write",0x80,sVar4,0x80);
                      puVar22 = &DAT_0010271c;
                      goto LAB_001012f4;
                    }
                  }
                  if (*(char *)((long)plVar15 + 0x18c) != '\0') {
                    sVar4 = (short)plVar15[0x30] + 0x88;
                    uVar8 = regmap_update_bits_base(plVar15[1],sVar4,4,4,0,0,0);
                    if ((int)uVar8 < 0) {
                      uVar18 = (ulong)uVar8;
                      _printk(&DAT_00102872,"pm8008_masked_write",4,sVar4,4);
                      puVar22 = &DAT_001028e8;
                      goto LAB_001012f4;
                    }
                  }
                  if ((int)plVar15[0x33] == 0) {
                    sVar4 = (short)plVar15[0x30] + 0x3b;
                    uVar8 = regmap_bulk_read(plVar15[1],sVar4,local_ac,1);
                    if ((int)uVar8 < 0) {
                      uVar18 = (ulong)uVar8;
                      _printk(&DAT_00102ce9,"pm8008_read",sVar4);
                      puVar22 = &DAT_00102935;
                      goto LAB_001012f4;
                    }
                    uVar8 = 0x9600 >> (ulong)(local_ac[0] & 3);
                  }
                  else {
                    uVar8 = 0x12c0;
                  }
                  plVar3 = plVar15 + 2;
                  *(uint *)(plVar15 + 0x31) = uVar8;
                  lVar17 = of_get_regulator_init_data(lVar20,lVar23,plVar3);
                  if (lVar17 == 0) {
                    _printk(&DAT_00102572,"pm8008_register_ldo",__s);
                    uVar18 = 0xffffffc3;
                  }
                  else {
                    if (*(long *)(lVar17 + 8) == 0) {
                      puVar22 = &DAT_00102990;
                      goto LAB_00101204;
                    }
                    if ((0 < local_a4) &&
                       (iVar7 = pm8008_write_voltage
                                          (plVar15,local_a4,*(undefined4 *)(lVar17 + 0x14)),
                       iVar7 < 0)) {
                      _printk(&DAT_00102f47,"pm8008_register_ldo",__s,iVar7);
                    }
                    *(uint *)(lVar17 + 0x40) = *(uint *)(lVar17 + 0x40) | 0x1d;
                    *(undefined4 *)(lVar17 + 0x44) = *(undefined4 *)(lVar17 + 0x14);
                    iVar7 = *(int *)(ppuVar5 + lVar21 * 6 + 2);
                    iVar24 = *(int *)((long)ppuVar5 + lVar21 * 0x30 + 0x14);
                    plVar15[10] = (long)&pm8008_regulator_ops;
                    uVar9 = *(undefined4 *)((long)ppuVar5 + lVar21 * 0x30 + 0x1c);
                    puVar22 = ppuVar5[lVar21 * 6 + 1];
                    *(undefined4 *)((long)plVar15 + 0x5c) = 0;
                    lVar21 = *(long *)(lVar17 + 8);
                    *(undefined4 *)((long)plVar15 + 0x7c) = uVar9;
                    plVar15[3] = (long)puVar22;
                    plVar15[2] = lVar21;
                    *(int *)(plVar15 + 0xd) = iVar7;
                    *(undefined4 *)((long)plVar15 + 0x6c) = 8000;
                    *(uint *)(plVar15 + 9) = (uint)(iVar24 - iVar7) / 8000 + 1;
                    local_a0 = lVar20;
                    local_98 = lVar17;
                    local_90 = plVar15;
                    local_88 = lVar23;
                    of_property_read_variable_u32_array
                              (lVar23,"qcom,min-dropout-voltage",
                               (undefined4 *)((long)plVar15 + 0x7c),1,0);
                    local_6c[0] = 0;
                    sVar4 = (short)plVar15[0x30] + 0x46;
                    uVar8 = regmap_bulk_read(plVar15[1],sVar4,local_6c,1);
                    if ((int)uVar8 < 0) {
                      uVar18 = (ulong)uVar8;
                      _printk(&DAT_00102ce9,"pm8008_read",sVar4);
                      __s = (char *)*plVar3;
                      puVar22 = &DAT_00102789;
                      pcVar19 = "_pm8008_regulator_is_enabled";
                      goto LAB_00101300;
                    }
                    uVar18 = devm_regulator_register(lVar20,plVar3,&local_a0);
                    plVar15[0x29] = uVar18;
                    if (uVar18 < 0xfffffffffffff001) {
                      uVar9 = pm8008_regulator_get_voltage(uVar18);
                      *(undefined4 *)((long)plVar15 + 0x194) = uVar9;
                      uVar9 = pm8008_regulator_get_mode(plVar15[0x29]);
                      *(undefined4 *)(plVar15 + 0x32) = uVar9;
                      if (*(char *)((long)plVar15 + 0x18c) != '\0') {
                        plVar15[0x2d] = (long)pm8008_ldo_cb;
                        uVar8 = devm_regulator_register_notifier(plVar15[0x2a],plVar15 + 0x2d);
                        if ((int)uVar8 < 0) {
                          uVar18 = (ulong)uVar8;
                          _printk(&DAT_00102f7e,"pm8008_register_ldo",uVar18);
                          goto LAB_00101308;
                        }
                      }
                      iVar7 = devm_regulator_debug_register(lVar20,plVar15[0x29]);
                      if (iVar7 != 0) {
                        _printk(&DAT_00102832,"pm8008_register_ldo",iVar7);
                      }
                      goto LAB_00100be8;
                    }
                    _printk(&DAT_00102753,"pm8008_register_ldo",*plVar3,uVar18 & 0xffffffff);
                    if (-1 < (int)uVar18) goto LAB_00100be8;
                  }
                }
              }
LAB_00101308:
              _printk(&DAT_001028b3,"pm8008_parse_regulator",local_b8,uVar18 & 0xffffffff);
              goto LAB_00101324;
            }
LAB_00100be8:
            lVar14 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),lVar14);
          } while (lVar14 != 0);
        }
LAB_001011bc:
        uVar12 = 0;
        goto LAB_00101340;
      }
      _dev_err(lVar2,"failed to get pm8008_en supply data\n");
      uVar18 = 0xffffffc3;
      goto LAB_00101324;
    }
    if ((int)uVar12 == -0x205) {
      uVar18 = 0xfffffdfb;
      goto LAB_00101324;
    }
    _dev_err(lVar2,"failed to get pm8008_en supply\n");
    if (-1 < (int)uVar12) goto LAB_001011bc;
  }
  _printk(&DAT_00102b5d,"pm8008_regulator_probe",uVar12 & 0xffffffff);
LAB_00101340:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12 & 0xffffffff;
}



//------------------------------------------------------------
// pm8008_write_voltage @ 0010138c size=308
// signature: undefined pm8008_write_voltage(void)
// callers: [pm8008_regulator_set_voltage, pm8008_regulator_probe]
//------------------------------------------------------------

int pm8008_write_voltage(long param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  iVar4 = (param_2 + 999) / 1000;
  if (param_3 < iVar4 * 1000) {
    _printk(&DAT_001025dc,"pm8008_write_voltage",*(undefined8 *)(param_1 + 0x10));
    iVar4 = -0x16;
  }
  else {
    iVar2 = iVar4 + 0xe;
    if (-1 < iVar4 + 7) {
      iVar2 = iVar4 + 7;
    }
    local_3c[0] = (ushort)iVar2 & 0xfff8;
    sVar1 = *(short *)(param_1 + 0x180) + 0x40;
    iVar4 = regmap_bulk_write(*(undefined8 *)(param_1 + 8),sVar1,local_3c,2);
    if (iVar4 < 0) {
      _printk(&DAT_001025a2,"pm8008_write",sVar1);
      _printk(&DAT_0010266f,"pm8008_write_voltage",*(undefined8 *)(param_1 + 0x10),iVar4);
    }
    else {
      iVar4 = 0;
      *(int *)(param_1 + 0x194) = (iVar2 >> 3) * 8000;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// pm8008_chip_internal_enable @ 001014c0 size=284
// signature: undefined pm8008_chip_internal_enable(void)
// callers: [pm8008_regulator_enable, pm8008_regulator_probe]
//------------------------------------------------------------

int pm8008_chip_internal_enable(long param_1)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  if (*(char *)(param_1 + 0x18d) != '\0') {
    return 0;
  }
  lVar6 = *(long *)(param_1 + 0x160);
  mutex_lock(lVar6 + 0x150);
  iVar1 = *(int *)(lVar6 + 0x184) + 1;
  bVar3 = *(char *)(lVar6 + 0x188) != '\0';
  bVar4 = bVar3 || iVar1 != 0;
  *(int *)(lVar6 + 0x184) = iVar1;
  if ((bool)*(char *)(lVar6 + 0x189) != bVar4) {
    iVar5 = regmap_update_bits_base(*(undefined8 *)(lVar6 + 8),0x950,1,bVar4,0,0,0);
    if (iVar5 < 0) {
      _printk(&DAT_00102872,"pm8008_masked_write",bVar4,0x950,1);
      pcVar2 = "enable";
      if (!bVar3 && iVar1 == 0) {
        pcVar2 = "disable";
      }
      _printk(&DAT_00102e37,"pm8008_chip_aggregate",*(undefined8 *)(lVar6 + 0x18),pcVar2,iVar5);
      *(int *)(lVar6 + 0x184) = *(int *)(lVar6 + 0x184) + -1;
      goto LAB_00101550;
    }
    *(bool *)(lVar6 + 0x189) = bVar4;
  }
  iVar5 = 0;
  *(undefined1 *)(param_1 + 0x18d) = 1;
LAB_00101550:
  mutex_unlock(*(long *)(param_1 + 0x160) + 0x150);
  return iVar5;
}



//------------------------------------------------------------
// pm8008_regulator_get_voltage @ 001015e0 size=228
// signature: undefined pm8008_regulator_get_voltage(void)
// callers: [pm8008_regulator_enable, pm8008_regulator_probe]
//------------------------------------------------------------

int pm8008_regulator_get_voltage(void)

{
  short sVar1;
  int iVar2;
  long lVar3;
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = rdev_get_drvdata();
  local_3c[0] = 0;
  if (*(char *)(*(long *)(lVar3 + 0x160) + 0x18a) == '\0') {
    sVar1 = *(short *)(lVar3 + 0x180) + 0x40;
    iVar2 = regmap_bulk_read(*(undefined8 *)(lVar3 + 8),sVar1,local_3c,2);
    if (iVar2 < 0) {
      _printk(&DAT_00102ce9,"pm8008_read",sVar1);
      _printk(&DAT_00102bee,"pm8008_regulator_get_voltage",*(undefined8 *)(lVar3 + 0x10),iVar2);
    }
    else {
      iVar2 = (uint)local_3c[0] * 1000;
    }
  }
  else {
    iVar2 = *(int *)(lVar3 + 0x194);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8008_regulator_get_mode @ 001016c8 size=240
// signature: undefined pm8008_regulator_get_mode(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

int pm8008_regulator_get_mode(void)

{
  short sVar1;
  int iVar2;
  long lVar3;
  byte local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = rdev_get_drvdata();
  local_3c[0] = 0;
  if (*(char *)(*(long *)(lVar3 + 0x160) + 0x18a) == '\0') {
    sVar1 = *(short *)(lVar3 + 0x180) + 8;
    iVar2 = regmap_bulk_read(*(undefined8 *)(lVar3 + 8),sVar1,local_3c,1);
    if (iVar2 < 0) {
      _printk(&DAT_00102ce9,"pm8008_read",sVar1);
      _printk(&DAT_00102a46,"pm8008_regulator_get_mode",*(undefined8 *)(lVar3 + 0x10),iVar2);
    }
    else {
      iVar2 = 2;
      if (((local_3c[0] ^ 0xff) & 3) != 0) {
        iVar2 = 4;
      }
    }
  }
  else {
    iVar2 = *(int *)(lVar3 + 400);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8008_ldo_cb @ 001017bc size=448
// signature: undefined pm8008_ldo_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8008_ldo_cb(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  short sVar5;
  undefined8 *puVar6;
  byte local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c[0] = 0;
  if (param_2 == 2) {
    puVar6 = (undefined8 *)(param_1 + -0x160);
    sVar5 = *(short *)(param_1 + 0x18) + 8;
    iVar2 = regmap_bulk_read(*puVar6,sVar5,local_4c,1);
    if (iVar2 < 0) {
      _printk(&DAT_00102ce9,"pm8008_read",sVar5);
      puVar3 = &DAT_00102dec;
      uVar4 = *(undefined8 *)(param_1 + -0x158);
    }
    else {
      if ((local_4c[0] >> 5 & 1) == 0) goto LAB_00101824;
      _printk(&DAT_001026a0,"pm8008_ldo_cb",*(undefined8 *)(param_1 + -0x158));
      sVar5 = *(short *)(param_1 + 0x18) + 0x88;
      iVar2 = regmap_update_bits_base(*puVar6,sVar5,2,2,0,0,0);
      if (iVar2 < 0) {
        uVar4 = 2;
      }
      else {
        sVar5 = *(short *)(param_1 + 0x18) + 0x88;
        iVar2 = regmap_update_bits_base(*puVar6,sVar5,2,0,0,0,0);
        if (-1 < iVar2) {
          regulator_notifier_call_chain(*(undefined8 *)(param_1 + -0x20),2,0);
          goto LAB_00101824;
        }
        uVar4 = 0;
      }
      _printk(&DAT_00102872,"pm8008_masked_write",uVar4,sVar5,2);
      uVar4 = *(undefined8 *)(param_1 + -0x158);
      puVar3 = &DAT_00102ed8;
    }
    _printk(puVar3,"pm8008_ldo_cb",uVar4,iVar2);
  }
LAB_00101824:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// pm8008_regulator_set_voltage @ 00101980 size=156
// signature: undefined pm8008_regulator_set_voltage(void)
// callers: []
//------------------------------------------------------------

ulong pm8008_regulator_set_voltage(undefined8 param_1,int param_2,int param_3,uint *param_4)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = rdev_get_drvdata();
  if (*(char *)(*(long *)(lVar1 + 0x160) + 0x18a) == '\0') {
    uVar2 = pm8008_write_voltage(lVar1,param_2,param_3);
    if (-1 < (int)uVar2) {
      uVar2 = 0;
      *param_4 = ((param_2 - *(int *)(lVar1 + 0x68)) + 7999U) / 8000;
    }
  }
  else {
    uVar2 = (ulong)-(uint)(*(int *)(lVar1 + 0x194) < param_2 || param_3 < *(int *)(lVar1 + 0x194));
  }
  return uVar2;
}



//------------------------------------------------------------
// pm8008_regulator_enable @ 00101a20 size=744
// signature: undefined pm8008_regulator_enable(void)
// callers: []
//------------------------------------------------------------

int pm8008_regulator_enable(undefined8 param_1)

{
  short sVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined *puVar7;
  undefined8 uVar8;
  uint uVar9;
  char local_6c [4];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = rdev_get_drvdata();
  local_6c[0] = '\0';
  if (*(char *)(*(long *)(lVar6 + 0x160) + 0x18a) != '\0') {
    iVar5 = *(char *)(lVar6 + 0x18d) + -1;
    goto LAB_00101b64;
  }
  iVar4 = pm8008_regulator_get_voltage(param_1);
  if (iVar4 < 0) {
    uVar8 = *(undefined8 *)(lVar6 + 0x10);
    puVar7 = &DAT_00102615;
    iVar5 = iVar4;
  }
  else {
    iVar5 = pm8008_chip_internal_enable(lVar6);
    if (iVar5 < 0) {
      _printk(&DAT_00102ea9,"pm8008_regulator_enable",*(undefined8 *)(lVar6 + 0x10),iVar5);
      goto LAB_00101b64;
    }
    sVar1 = *(short *)(lVar6 + 0x180) + 0x46;
    iVar5 = regmap_update_bits_base(*(undefined8 *)(lVar6 + 8),sVar1,0x80,0x80,0,0,0);
    if (-1 < iVar5) {
      iVar5 = *(int *)(lVar6 + 0x188);
      uVar9 = 0xfffffff5;
      iVar2 = 0;
      if (iVar5 != 0) {
        iVar2 = (iVar4 + iVar5 + -1) / iVar5;
      }
      do {
        bVar3 = 0xfffffffe < uVar9;
        uVar9 = uVar9 + 1;
        if (bVar3) {
          _printk(&DAT_00102d87,"pm8008_regulator_enable",*(undefined8 *)(lVar6 + 0x10));
          iVar5 = -0x3e;
LAB_00101c88:
          sVar1 = *(short *)(lVar6 + 0x180) + 0x46;
          iVar4 = regmap_update_bits_base(*(undefined8 *)(lVar6 + 8),sVar1,0x80,0,0,0,0);
          if (iVar4 < 0) {
            _printk(&DAT_00102872,"pm8008_masked_write",0,sVar1,0x80);
          }
          goto LAB_00101cb8;
        }
        if (iVar2 + 0x3fb < 21000) {
          usleep_range_state((long)(iVar2 + 0x14),(long)(iVar2 + 0x78),2);
        }
        else {
          msleep((iVar2 + 0x3fb) / 1000);
        }
        sVar1 = *(short *)(lVar6 + 0x180) + 8;
        iVar5 = regmap_bulk_read(*(undefined8 *)(lVar6 + 8),sVar1,local_6c,1);
        if (iVar5 < 0) {
          _printk(&DAT_00102ce9,"pm8008_read",sVar1);
          _printk(&DAT_00102dec,"pm8008_regulator_enable",*(undefined8 *)(lVar6 + 0x10),iVar5);
          goto LAB_00101c88;
        }
      } while (-1 < local_6c[0]);
      iVar5 = 0;
      goto LAB_00101b64;
    }
    _printk(&DAT_00102872,"pm8008_masked_write",0x80,sVar1,0x80);
    _printk(&DAT_00102d39,"pm8008_regulator_enable",*(undefined8 *)(lVar6 + 0x10),iVar5);
LAB_00101cb8:
    iVar4 = pm8008_chip_internal_disable(lVar6);
    if (-1 < iVar4) goto LAB_00101b64;
    uVar8 = *(undefined8 *)(lVar6 + 0x10);
    puVar7 = &DAT_00102c4f;
  }
  _printk(puVar7,"pm8008_regulator_enable",uVar8,iVar4);
LAB_00101b64:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// pm8008_regulator_disable @ 00101d0c size=228
// signature: undefined pm8008_regulator_disable(void)
// callers: []
//------------------------------------------------------------

int pm8008_regulator_disable(void)

{
  short sVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  undefined8 uVar5;
  
  lVar3 = rdev_get_drvdata();
  if (*(char *)(*(long *)(lVar3 + 0x160) + 0x18a) == '\0') {
    sVar1 = *(short *)(lVar3 + 0x180) + 0x46;
    iVar2 = regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),sVar1,0x80,0,0,0,0);
    if (iVar2 < 0) {
      _printk(&DAT_00102872,"pm8008_masked_write",0,sVar1,0x80);
      uVar5 = *(undefined8 *)(lVar3 + 0x10);
      puVar4 = &DAT_001027bf;
    }
    else {
      iVar2 = pm8008_chip_internal_disable(lVar3);
      if (-1 < iVar2) {
        return 0;
      }
      uVar5 = *(undefined8 *)(lVar3 + 0x10);
      puVar4 = &DAT_00102c4f;
    }
    _printk(puVar4,"pm8008_regulator_disable",uVar5,iVar2);
  }
  else {
    iVar2 = -(int)*(char *)(lVar3 + 0x18d);
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8008_regulator_is_enabled @ 00101df4 size=224
// signature: undefined pm8008_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

uint pm8008_regulator_is_enabled(void)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = rdev_get_drvdata();
  if (*(char *)(*(long *)(lVar2 + 0x160) + 0x18a) == '\0') {
    local_3c[0] = 0;
    sVar1 = *(short *)(lVar2 + 0x180) + 0x46;
    uVar3 = regmap_bulk_read(*(undefined8 *)(lVar2 + 8),sVar1,local_3c,1);
    if ((int)uVar3 < 0) {
      _printk(&DAT_00102ce9,"pm8008_read",sVar1);
      _printk(&DAT_00102789,"_pm8008_regulator_is_enabled",*(undefined8 *)(lVar2 + 0x10),uVar3);
    }
    else {
      uVar3 = (uint)(local_3c[0] >> 7);
    }
  }
  else {
    uVar3 = (uint)*(byte *)(lVar2 + 0x18d);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// pm8008_regulator_set_mode @ 00101ed8 size=204
// signature: undefined pm8008_regulator_set_mode(void)
// callers: []
//------------------------------------------------------------

int pm8008_regulator_set_mode(undefined8 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar3 = rdev_get_drvdata();
  if (*(char *)(*(long *)(lVar3 + 0x160) + 0x18a) == '\0') {
    uVar4 = 7;
    if (param_2 != 2) {
      uVar4 = 4;
    }
    sVar1 = *(short *)(lVar3 + 0x180) + 0x45;
    iVar2 = regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),sVar1,7,uVar4,0,0,0);
    if (iVar2 < 0) {
      _printk(&DAT_00102872,"pm8008_masked_write",uVar4,sVar1,7);
    }
    else if (iVar2 == 0) {
      *(int *)(lVar3 + 400) = param_2;
    }
  }
  else {
    iVar2 = -(uint)(*(int *)(lVar3 + 400) != param_2);
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8008_regulator_set_voltage_time @ 00101fa8 size=68
// signature: undefined pm8008_regulator_set_voltage_time(void)
// callers: []
//------------------------------------------------------------

int pm8008_regulator_set_voltage_time(undefined8 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = rdev_get_drvdata();
  iVar2 = *(int *)(lVar4 + 0x188);
  param_3 = param_3 - param_2;
  iVar1 = -param_3;
  if (-1 < param_3) {
    iVar1 = param_3;
  }
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = (iVar1 + iVar2 + -1) / iVar2;
  }
  return iVar3;
}



//------------------------------------------------------------
// pm8008_regulator_set_load @ 00101ff0 size=232
// signature: undefined pm8008_regulator_set_load(void)
// callers: []
//------------------------------------------------------------

int pm8008_regulator_set_load(undefined8 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  
  lVar3 = rdev_get_drvdata();
  iVar2 = *(int *)(lVar3 + 0x184);
  iVar4 = 4;
  if (iVar2 <= param_2) {
    iVar4 = 2;
  }
  lVar3 = rdev_get_drvdata(param_1);
  if (*(char *)(*(long *)(lVar3 + 0x160) + 0x18a) == '\0') {
    uVar5 = 4;
    if (iVar2 <= param_2) {
      uVar5 = 7;
    }
    sVar1 = *(short *)(lVar3 + 0x180) + 0x45;
    iVar2 = regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),sVar1,7,uVar5,0,0,0);
    if (iVar2 < 0) {
      _printk(&DAT_00102872,"pm8008_masked_write",uVar5,sVar1,7);
    }
    else if (iVar2 == 0) {
      *(int *)(lVar3 + 400) = iVar4;
    }
  }
  else {
    iVar2 = -(uint)(*(int *)(lVar3 + 400) != iVar4);
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8008_chip_internal_disable @ 001020d8 size=316
// signature: undefined pm8008_chip_internal_disable(void)
// callers: [pm8008_regulator_enable, pm8008_regulator_disable]
//------------------------------------------------------------

int pm8008_chip_internal_disable(long param_1)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  if (*(char *)(param_1 + 0x18d) == '\0') {
    return 0;
  }
  lVar6 = *(long *)(param_1 + 0x160);
  mutex_lock(lVar6 + 0x150);
  if (*(int *)(lVar6 + 0x184) == 0) {
    _printk(&DAT_001026d5,"pm8008_chip_internal_disable",*(undefined8 *)(lVar6 + 0x18));
    iVar5 = -0x16;
  }
  else {
    iVar2 = *(int *)(lVar6 + 0x184) + -1;
    *(int *)(lVar6 + 0x184) = iVar2;
    bVar3 = *(char *)(lVar6 + 0x188) != '\0';
    bVar4 = bVar3 || iVar2 != 0;
    if ((bool)*(char *)(lVar6 + 0x189) != bVar4) {
      iVar5 = regmap_update_bits_base(*(undefined8 *)(lVar6 + 8),0x950,1,bVar4,0,0,0);
      if (iVar5 < 0) {
        _printk(&DAT_00102872,"pm8008_masked_write",bVar4,0x950,1);
        pcVar1 = "enable";
        if (!bVar3 && iVar2 == 0) {
          pcVar1 = "disable";
        }
        _printk(&DAT_00102e37,"pm8008_chip_aggregate",*(undefined8 *)(lVar6 + 0x18),pcVar1,iVar5);
        *(int *)(lVar6 + 0x184) = *(int *)(lVar6 + 0x184) + 1;
        goto LAB_00102160;
      }
      *(bool *)(lVar6 + 0x189) = bVar4;
    }
    iVar5 = 0;
    *(undefined1 *)(param_1 + 0x18d) = 0;
  }
LAB_00102160:
  mutex_unlock(*(long *)(param_1 + 0x160) + 0x150);
  return iVar5;
}



//------------------------------------------------------------
// init_module @ 00102218 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&pm8008_chip_driver,&__this_module);
  if (iVar1 == 0) {
    __platform_driver_register(&pm8008_regulator_driver,&__this_module);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102260 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pm8008_regulator_driver);
  platform_driver_unregister(&pm8008_chip_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// platform_driver_unregister @ 00105008 size=1
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
// devm_kmalloc @ 00105010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pm8008_chip_probe, pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00105018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pm8008_chip_probe, pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105020 size=1
// signature: undefined __mutex_init(void)
// callers: [pm8008_chip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00105028 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [pm8008_regulator_get_mode, pm8008_regulator_enable, pm8008_regulator_get_voltage, pm8008_chip_probe, pm8008_regulator_is_enabled, pm8008_regulator_probe, pm8008_ldo_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00105030 size=1
// signature: undefined devm_regulator_register(void)
// callers: [pm8008_chip_probe, pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 00105038 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [pm8008_chip_probe, pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 00105040 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [pm8008_chip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00105048 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [pm8008_chip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00105050 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [pm8008_regulator_enable, pm8008_chip_internal_disable, pm8008_chip_disable, pm8008_regulator_set_mode, pm8008_chip_remove, pm8008_chip_probe, pm8008_regulator_disable, pm8008_chip_enable, pm8008_regulator_set_load, pm8008_chip_internal_enable, pm8008_regulator_probe, pm8008_ldo_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105058 size=1
// signature: undefined _printk(void)
// callers: [pm8008_chip_disable, pm8008_regulator_get_voltage, pm8008_regulator_set_mode, pm8008_chip_probe, pm8008_chip_enable, pm8008_regulator_set_load, pm8008_regulator_is_enabled, pm8008_regulator_probe, pm8008_ldo_cb, pm8008_regulator_get_mode, pm8008_regulator_enable, pm8008_chip_internal_disable, pm8008_write_voltage, pm8008_chip_remove, pm8008_regulator_disable, pm8008_chip_internal_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pm8008_regulator_get_mode, pm8008_regulator_enable, pm8008_regulator_get_voltage, pm8008_write_voltage, pm8008_chip_probe, pm8008_regulator_is_enabled, pm8008_regulator_probe, pm8008_ldo_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_notifier_call_chain @ 00105068 size=1
// signature: undefined regulator_notifier_call_chain(void)
// callers: [pm8008_ocp_irq, pm8008_ldo_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00105070 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [pm8008_chip_is_enabled, pm8008_chip_disable, pm8008_regulator_get_voltage, pm8008_regulator_set_mode, pm8008_chip_enable, pm8008_regulator_set_load, pm8008_regulator_is_enabled, pm8008_regulator_probe, pm8008_regulator_set_voltage, pm8008_regulator_get_mode, pm8008_regulator_enable, pm8008_regulator_disable, pm8008_regulator_set_voltage_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105078 size=1
// signature: undefined mutex_lock(void)
// callers: [pm8008_chip_internal_disable, pm8008_chip_disable, pm8008_chip_enable, pm8008_chip_internal_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105080 size=1
// signature: undefined mutex_unlock(void)
// callers: [pm8008_chip_internal_disable, pm8008_chip_disable, pm8008_chip_enable, pm8008_chip_internal_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00105088 size=1
// signature: undefined of_match_node(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105090 size=1
// signature: undefined of_find_property(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00105098 size=1
// signature: undefined devm_regulator_get(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001050a0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001050a8 size=1
// signature: undefined of_property_read_string(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001050b0 size=1
// signature: size_t strlen(char * __s)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001050b8 size=1
// signature: undefined strnstr(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001050c0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 001050c8 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [pm8008_write_voltage, pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 001050d0 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register_notifier @ 001050d8 size=1
// signature: undefined devm_regulator_register_notifier(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001050e0 size=1
// signature: undefined _dev_err(void)
// callers: [pm8008_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 001050e8 size=1
// signature: undefined msleep(void)
// callers: [pm8008_regulator_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001050f0 size=1
// signature: undefined usleep_range_state(void)
// callers: [pm8008_regulator_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



