// Decompiled by Ghidra 12.2
// Program: qpnp-amoled-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_amoled_regulator_probe @ 00100454 size=2428
// signature: undefined qpnp_amoled_regulator_probe(void)
// callers: []
//------------------------------------------------------------

int qpnp_amoled_regulator_probe(long param_1)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  long *plVar8;
  undefined8 uVar9;
  long lVar10;
  uint *puVar11;
  char *pcVar12;
  uint uVar13;
  long lVar14;
  uint uVar15;
  undefined1 uVar16;
  ulong uVar17;
  undefined2 local_84;
  undefined1 local_82;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if (*(long *)(param_1 + 0x2f8) == 0) {
    _printk(&DAT_00101a1e,"qpnp_amoled_regulator_probe");
    iVar5 = -0x13;
    goto LAB_00100d48;
  }
  lVar14 = param_1 + 0x10;
  plVar8 = (long *)devm_kmalloc(lVar14,0x458,0xdc0);
  if (plVar8 == (long *)0x0) {
    iVar5 = -0xc;
    goto LAB_00100d48;
  }
  uVar9 = *(undefined8 *)(param_1 + 0x70);
  *plVar8 = lVar14;
  lVar10 = dev_get_regmap(uVar9,0);
  plVar8[1] = lVar10;
  if (lVar10 == 0) {
    _dev_err(lVar14,"Failed to get the regmap handle\n");
    iVar5 = -0x16;
    goto LAB_00100d48;
  }
  lVar14 = *plVar8;
  *(long **)(param_1 + 0xa8) = plVar8;
  local_82 = 0;
  local_84 = 0;
  uVar9 = *(undefined8 *)(lVar14 + 0x2e8);
  lVar14 = of_get_next_available_child(uVar9,0);
  if (lVar14 != 0) {
    do {
      puVar11 = (uint *)__of_get_address(lVar14,0,0xffffffff,0,0);
      if (puVar11 == (uint *)0x0) {
        _printk(&DAT_0010192d,"qpnp_amoled_parse_dt");
LAB_00100c84:
        iVar5 = -0x16;
LAB_00100c88:
        lVar14 = *plVar8;
        pcVar12 = "Failed to parse DT params rc=%d\n";
        goto LAB_00100d40;
      }
      uVar15 = (*puVar11 & 0xff00ff00) >> 8 | (*puVar11 & 0xff00ff) << 8;
      uVar6 = uVar15 >> 0x10 | uVar15 << 0x10;
      uVar15 = uVar6 + 3 & 0xffff;
      iVar5 = regmap_bulk_read(plVar8[1],uVar15,&local_84,3);
      if (iVar5 < 0) {
        _printk(&DAT_00101bb2,"qpnp_amoled_read",uVar15,iVar5);
        _printk(&DAT_00101b5c,"qpnp_amoled_parse_dt",uVar6);
        goto LAB_00100c88;
      }
      if (local_84._1_1_ == ' ') {
        *(uint *)(plVar8 + 0x8a) = uVar6;
        *(undefined1 *)(plVar8 + 0x82) = local_82;
        *(undefined1 *)((long)plVar8 + 0x411) = (undefined1)local_84;
        plVar8[0x80] = lVar14;
        lVar10 = of_find_property(lVar14,"qcom,swire-control",0);
        *(bool *)((long)plVar8 + 0x412) = lVar10 != 0;
        lVar10 = of_find_property(lVar14,"qcom,aod-pd-control",0);
        *(bool *)((long)plVar8 + 0x413) = lVar10 != 0;
        lVar10 = of_find_property(lVar14,"qcom,ibb-single-phase",0);
        *(bool *)((long)plVar8 + 0x414) = lVar10 != 0;
        if (((char)plVar8[0x82] == '\x04') && (1 < *(byte *)((long)plVar8 + 0x411))) {
          local_78 = 0;
          local_70 = 0;
          local_80 = 0;
          uVar6 = of_property_read_variable_u32_array
                            (lVar14,"qcom,ibb-spur-mitigation-level",plVar8 + 0x83,1,0);
          uVar15 = uVar6;
          if (-1 < (int)uVar6) {
            uVar15 = 0;
          }
          uVar17 = (ulong)uVar15;
          if ((int)uVar6 < 0) {
LAB_001007cc:
            if ((int)uVar17 < 0) goto LAB_001007d0;
          }
          else {
            iVar5 = (int)plVar8[0x83];
            if (iVar5 != 0) {
              if (iVar5 == 2) {
                of_property_read_variable_u32_array
                          (lVar14,"qcom,ibb-spur-sqm-timer-ms",(long)plVar8 + 0x41c,1,0);
                uVar17 = devm_nvmem_cell_get(*plVar8,"ibb_spur_sqm_timer");
                plVar8[0x88] = uVar17;
                if (0xfffffffffffff000 < uVar17) {
                  if ((int)uVar17 != -0x205) {
                    _dev_err(*plVar8,"Failed to get nvmem-cells, rc=%d\n",uVar17 & 0xffffffff);
                    goto LAB_001007cc;
                  }
                  goto LAB_001007d0;
                }
              }
              lVar10 = of_find_property(lVar14,"qcom,ibb-spur-2khz-step-size",0);
              *(bool *)(plVar8 + 0x87) = lVar10 != 0;
              iVar5 = of_property_count_elems_of_size(lVar14,"qcom,ibb-spur-freq-thresholds",4);
              if (iVar5 == 6) {
                iVar5 = of_property_read_variable_u32_array
                                  (lVar14,"qcom,ibb-spur-freq-thresholds",&local_80,6,0);
                if (-1 < iVar5) {
                  *(undefined4 *)((long)plVar8 + 0x42c) = (undefined4)local_80;
                  *(undefined4 *)(plVar8 + 0x84) = local_80._4_4_;
                  *(undefined4 *)(plVar8 + 0x86) = (undefined4)local_78;
                  *(undefined4 *)((long)plVar8 + 0x424) = local_78._4_4_;
                  *(undefined4 *)((long)plVar8 + 0x434) = (undefined4)local_70;
                  *(undefined4 *)(plVar8 + 0x85) = local_70._4_4_;
                  goto LAB_00100558;
                }
                _dev_err(*plVar8,"failed to read thresholds = %d\n",iVar5);
              }
              else {
                _dev_err(*plVar8,"invalid ibb spur freq threshold array size = %d\n",iVar5);
                *(undefined4 *)(plVar8 + 0x83) = 0;
              }
LAB_001007d0:
              _printk(&DAT_00101d9c,"qpnp_amoled_parse_dt");
            }
          }
        }
      }
      else if (local_84._1_1_ == '$') {
        *(uint *)((long)plVar8 + 0x44c) = uVar6;
        plVar8[0x55] = lVar14;
        lVar10 = of_find_property(lVar14,"qcom,swire-control",0);
        *(bool *)(plVar8 + 0x57) = lVar10 != 0;
        lVar10 = of_find_property(lVar14,"qcom,aod-pd-control",0);
        *(bool *)((long)plVar8 + 0x2b9) = lVar10 != 0;
      }
      else {
        if (local_84._1_1_ != ',') {
          _printk(&DAT_00101dec,"qpnp_amoled_parse_dt",(undefined1)local_84);
          goto LAB_00100c84;
        }
        *(uint *)(plVar8 + 0x89) = uVar6;
        plVar8[0x2a] = lVar14;
        lVar10 = of_find_property(lVar14,"qcom,swire-control",0);
        *(bool *)(plVar8 + 0x2c) = lVar10 != 0;
      }
LAB_00100558:
      lVar14 = of_get_next_available_child(uVar9,lVar14);
    } while (lVar14 != 0);
  }
  iVar7 = qpnp_amoled_regulator_register(plVar8,0);
  if (iVar7 < 0) {
    lVar14 = *plVar8;
    pcVar12 = "Failed to register OLEDB regulator rc=%d\n";
LAB_00100908:
    _dev_err(lVar14,pcVar12,iVar7);
LAB_00100910:
    _dev_err(*plVar8,"Failed to initialize HW rc=%d\n",iVar7);
    iVar5 = iVar7;
  }
  else {
    iVar7 = qpnp_amoled_regulator_register(plVar8,1);
    if (iVar7 < 0) {
      lVar14 = *plVar8;
      pcVar12 = "Failed to register AB regulator rc=%d\n";
      goto LAB_00100908;
    }
    iVar7 = qpnp_amoled_regulator_register(plVar8,2);
    if (iVar7 < 0) {
      lVar14 = *plVar8;
      pcVar12 = "Failed to register IBB regulator rc=%d\n";
      goto LAB_00100908;
    }
    if (((char)plVar8[0x82] == '\x04') && (*(char *)((long)plVar8 + 0x414) != '\0')) {
      uVar15 = (int)plVar8[0x8a] + 0x70U & 0xffff;
      iVar7 = regmap_update_bits_base(plVar8[1],uVar15,7,1,0,0,0);
      iVar5 = 0;
      if (-1 < iVar7) goto LAB_00100924;
      _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar15,1,iVar7);
      goto LAB_00100910;
    }
    iVar5 = 0;
  }
LAB_00100924:
  if (((char)plVar8[0x82] != '\x04') || (*(byte *)((long)plVar8 + 0x411) < 2)) goto LAB_00100d48;
  if ((int)plVar8[0x83] == 1) goto LAB_001009ac;
  if ((int)plVar8[0x83] == 2) {
    uVar15 = (int)plVar8[0x8a] + 0xb6U & 0xffff;
    iVar5 = regmap_update_bits_base(plVar8[1],uVar15,0x40,0x40,0,0,0);
    if (iVar5 < 0) {
      _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar15,0x40,iVar5);
      pcVar12 = "failed to enable spur SQM mode!\n";
      goto LAB_00100d2c;
    }
    if (0x26aa < *(int *)((long)plVar8 + 0x41c) - 0x65U) {
LAB_001009ac:
      local_80 = local_80 & 0xffffffffffff0000;
      if ((char)plVar8[0x87] == '\0') {
        if ((((*(uint *)(plVar8 + 0x84) - 0xf9 < 0xf7) &&
             (*(uint *)((long)plVar8 + 0x42c) <= *(uint *)(plVar8 + 0x84))) ||
            ((*(uint *)((long)plVar8 + 0x424) - 0xf9 < 0xf7 &&
             (*(uint *)(plVar8 + 0x86) <= *(uint *)((long)plVar8 + 0x424))))) ||
           ((*(uint *)(plVar8 + 0x85) - 0xf9 < 0xf7 &&
            (*(uint *)((long)plVar8 + 0x434) <= *(uint *)(plVar8 + 0x85))))) {
          uVar16 = 1;
        }
        else {
          uVar16 = 0;
        }
        *(undefined1 *)(plVar8 + 0x87) = uVar16;
      }
      else {
        uVar16 = 1;
      }
      uVar15 = (int)plVar8[0x8a] + 0xb7U & 0xffff;
      iVar5 = regmap_update_bits_base(plVar8[1],uVar15,1,uVar16,0,0,0);
      if (iVar5 < 0) {
        _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar15,uVar16,iVar5);
        pcVar12 = "failed to write IBB_SPUR_CTL register!\n";
LAB_00100d1c:
        _dev_err(*plVar8,pcVar12);
        pcVar12 = "failed to set spur thresholds!\n";
      }
      else {
        lVar14 = 0;
        puVar11 = (uint *)((long)plVar8 + 0x42c);
        uVar15 = 0xf8;
        if ((char)plVar8[0x87] != '\0') {
          uVar15 = 0x1f0;
        }
        do {
          uVar2 = (ushort)*puVar11;
          uVar3 = (ushort)puVar11[-3];
          uVar6 = (uint)uVar2;
          uVar13 = (uint)uVar3;
          if (((uint)uVar3 < (uint)uVar2 || uVar15 <= uVar2 && uVar2 != uVar15) ||
              uVar15 <= uVar3 && uVar3 != uVar15) {
            _dev_err(*plVar8,"ibb spur freq band%d threshold invalid!\n",(int)lVar14 + 1);
            puVar11[-3] = uVar15;
            *puVar11 = uVar15;
            uVar6 = uVar15;
            uVar13 = uVar15;
          }
          uVar4 = (int)lVar14 << 1;
          uVar2 = 0;
          if (*(byte *)(plVar8 + 0x87) != 0) {
            uVar2 = (ushort)uVar13 & 1;
          }
          uVar1 = (int)plVar8[0x8a] + (uVar4 | 0xb8) & 0xffff;
          local_80 = CONCAT62(local_80._2_6_,
                              uVar2 + (short)(uVar13 >> (ulong)(*(byte *)(plVar8 + 0x87) & 0x1f)));
          iVar5 = regmap_bulk_write(plVar8[1],uVar1,&local_80,1);
          if (iVar5 < 0) {
            _printk(&DAT_001018f9,"qpnp_amoled_write",uVar1,iVar5);
            pcVar12 = "failed to write IBB_SPUR_FREQ_HIGH register!\n";
            goto LAB_00100d1c;
          }
          uVar13 = (int)plVar8[0x8a] + (uVar4 | 0xb9) & 0xffff;
          local_80 = CONCAT62(local_80._2_6_,
                              (short)(uVar6 >> (ulong)(*(byte *)(plVar8 + 0x87) & 0x1f)));
          iVar5 = regmap_bulk_write(plVar8[1],uVar13,&local_80,1);
          if (iVar5 < 0) {
            _printk(&DAT_001018f9,"qpnp_amoled_write",uVar13,iVar5);
            pcVar12 = "failed to write IBB_SPUR_FREQ_LOW register!\n";
            goto LAB_00100d1c;
          }
          lVar14 = lVar14 + 1;
          puVar11 = puVar11 + 1;
        } while (lVar14 != 3);
        uVar15 = (int)plVar8[0x8a] + 0xb6U & 0xffff;
        iVar7 = regmap_update_bits_base(plVar8[1],uVar15,0x80,0x80,0,0,0);
        iVar5 = 0;
        if (-1 < iVar7) goto LAB_00100d48;
        _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar15,0x80,iVar7);
        pcVar12 = "failed to enable spur FSM!\n";
        iVar5 = iVar7;
      }
      goto LAB_00100d2c;
    }
    local_80 = CONCAT62(local_80._2_6_,(short)*(int *)((long)plVar8 + 0x41c));
    iVar5 = nvmem_cell_write(plVar8[0x88],&local_80,2);
    if (-1 < iVar5) goto LAB_001009ac;
    if (iVar5 != -0x205) {
      pcVar12 = "failed to enable spur SQM timer\n";
      goto LAB_00100d2c;
    }
  }
  else {
    uVar15 = (int)plVar8[0x8a] + 0xb6U & 0xffff;
    iVar7 = regmap_update_bits_base(plVar8[1],uVar15,0x80,0,0,0,0);
    iVar5 = 0;
    if (-1 < iVar7) goto LAB_00100d48;
    _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar15,0,iVar7);
    pcVar12 = "failed to disable spur FSM!\n";
    iVar5 = iVar7;
LAB_00100d2c:
    _dev_err(*plVar8,pcVar12);
  }
  lVar14 = *plVar8;
  pcVar12 = "Failed to init ibb spur settings rc=%d\n";
LAB_00100d40:
  _dev_err(lVar14,pcVar12,iVar5);
LAB_00100d48:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qpnp_amoled_regulator_remove @ 00100dd4 size=8
// signature: undefined qpnp_amoled_regulator_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_amoled_regulator_remove(void)

{
  return 0;
}



//------------------------------------------------------------
// qpnp_amoled_regulator_register @ 00100ddc size=532
// signature: undefined qpnp_amoled_regulator_register(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

ulong qpnp_amoled_regulator_register(long *param_1,int param_2)

{
  int iVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  long local_78;
  undefined8 *puStack_70;
  long *local_68;
  long lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  if (param_2 == 0) {
    lVar5 = param_1[0x2a];
    plVar4 = param_1 + 2;
    param_1[10] = (long)qpnp_amoled_oledb_ops;
  }
  else if (param_2 == 1) {
    lVar5 = param_1[0x55];
    plVar4 = param_1 + 0x2d;
    param_1[0x35] = (long)qpnp_amoled_ab_ops;
  }
  else {
    plVar4 = param_1 + 0x58;
    lVar5 = param_1[0x80];
    param_1[0x60] = (long)qpnp_amoled_ibb_ops;
  }
  puVar2 = (undefined8 *)of_get_regulator_init_data(*param_1,lVar5,plVar4);
  if (puVar2 == (undefined8 *)0x0) {
    _printk(&DAT_001019e1,"qpnp_amoled_regulator_register",param_2);
    uVar3 = 0xfffffff4;
  }
  else if (puVar2[1] == 0) {
    _printk(&DAT_00101887,"qpnp_amoled_regulator_register",param_2);
    uVar3 = 0xffffffea;
  }
  else {
    *(undefined4 *)((long)plVar4 + 0x4c) = 0;
    plVar4[10] = (long)&__this_module;
    local_78 = *param_1;
    *plVar4 = puVar2[1];
    puStack_70 = puVar2;
    local_68 = param_1;
    lStack_60 = lVar5;
    lVar5 = of_get_property(*(undefined8 *)(local_78 + 0x2e8),"parent-supply",0);
    if (lVar5 != 0) {
      *puVar2 = "parent";
    }
    *(uint *)((long)puVar2 + 0x3c) = *(uint *)((long)puVar2 + 0x3c) | 0xe;
    *(uint *)(puVar2 + 8) = *(uint *)(puVar2 + 8) | 0xd;
    uVar3 = devm_regulator_register(*param_1,plVar4,&local_78);
    if (uVar3 < 0xfffffffffffff001) {
      iVar1 = devm_regulator_debug_register(*param_1,uVar3);
      if (iVar1 != 0) {
        _printk(&DAT_00101d36,"qpnp_amoled_regulator_register",iVar1);
      }
      if (param_2 == 0) {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x2b) = 2;
      }
      else if (param_2 == 2) {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x81) = 2;
      }
      else {
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x56) = 2;
      }
    }
    else {
      _printk(&DAT_00101cbd,"qpnp_amoled_regulator_register",param_2,uVar3 & 0xffffffff);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_set_voltage @ 00100ff4 size=32
// signature: undefined qpnp_oledb_regulator_set_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_oledb_regulator_set_voltage(void)

{
  rdev_get_drvdata();
  return 0;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_get_voltage @ 00101018 size=32
// signature: undefined qpnp_oledb_regulator_get_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_oledb_regulator_get_voltage(void)

{
  rdev_get_drvdata();
  return 0;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_enable @ 0010103c size=44
// signature: undefined qpnp_oledb_regulator_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_oledb_regulator_enable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x15c) = 1;
  return 0;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_disable @ 0010106c size=40
// signature: undefined qpnp_oledb_regulator_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_oledb_regulator_disable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x15c) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_is_enabled @ 00101098 size=32
// signature: undefined qpnp_oledb_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 qpnp_oledb_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x15c);
}



//------------------------------------------------------------
// qpnp_oledb_regulator_set_mode @ 001010bc size=52
// signature: undefined qpnp_oledb_regulator_set_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_oledb_regulator_set_mode(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined4 *)(lVar1 + 0x158) = param_2;
  return 0;
}



//------------------------------------------------------------
// qpnp_oledb_regulator_get_mode @ 001010f4 size=32
// signature: undefined qpnp_oledb_regulator_get_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_oledb_regulator_get_mode(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)(lVar1 + 0x158);
}



//------------------------------------------------------------
// qpnp_ab_ibb_regulator_set_voltage @ 00101118 size=32
// signature: undefined qpnp_ab_ibb_regulator_set_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ab_ibb_regulator_set_voltage(void)

{
  rdev_get_drvdata();
  return 0;
}



//------------------------------------------------------------
// qpnp_ab_ibb_regulator_get_voltage @ 0010113c size=32
// signature: undefined qpnp_ab_ibb_regulator_get_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ab_ibb_regulator_get_voltage(void)

{
  rdev_get_drvdata();
  return 0;
}



//------------------------------------------------------------
// qpnp_ab_regulator_enable @ 00101160 size=44
// signature: undefined qpnp_ab_regulator_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ab_regulator_enable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x2b4) = 1;
  return 0;
}



//------------------------------------------------------------
// qpnp_ab_regulator_disable @ 00101190 size=40
// signature: undefined qpnp_ab_regulator_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ab_regulator_disable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x2b4) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_ab_regulator_is_enabled @ 001011bc size=32
// signature: undefined qpnp_ab_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 qpnp_ab_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x2b4);
}



//------------------------------------------------------------
// qpnp_ab_ibb_regulator_set_mode @ 001011e0 size=592
// signature: undefined qpnp_ab_ibb_regulator_set_mode(void)
// callers: []
//------------------------------------------------------------

int qpnp_ab_ibb_regulator_set_mode(undefined8 param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  puVar6 = local_40;
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = rdev_get_drvdata();
  if ((8 < param_2) || ((1 << (ulong)(param_2 & 0x1f) & 0x114U) == 0)) {
    _printk(&DAT_00101c93,"qpnp_ab_ibb_regulator_set_mode",param_2);
    iVar3 = -0x16;
    goto LAB_00101364;
  }
  if ((*(uint *)(lVar4 + 0x2b0) == param_2) || (*(uint *)(lVar4 + 0x408) == param_2)) {
    iVar3 = 0;
    goto LAB_00101364;
  }
  if (param_2 == 8) {
LAB_00101264:
    if (*(char *)(lVar4 + 0x413) != '\0') {
      uVar1 = *(int *)(lVar4 + 0x450) + 0x47U & 0xffff;
      iVar3 = regmap_update_bits_base(*(undefined8 *)(lVar4 + 8),uVar1,0x80,0x80,0,0,0);
      if (-1 < iVar3) {
        cVar2 = *(char *)(lVar4 + 0x2b9);
        goto joined_r0x00101304;
      }
      uVar5 = 0x80;
LAB_00101408:
      _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar1,uVar5,iVar3);
LAB_00101410:
      _printk(&DAT_001019b2,"qpnp_ab_ibb_regulator_set_mode",param_2);
      goto LAB_00101364;
    }
    iVar3 = 0;
    cVar2 = *(char *)(lVar4 + 0x2b9);
joined_r0x00101304:
    if (cVar2 != '\0') {
      iVar3 = *(int *)(lVar4 + 0x44c);
      uVar5 = *(undefined8 *)(lVar4 + 8);
      local_40[0] = 0x80;
      goto LAB_00101344;
    }
  }
  else if (param_2 == 4) {
    if (*(char *)(lVar4 + 0x413) == '\0') {
      iVar3 = 0;
      cVar2 = *(char *)(lVar4 + 0x2b9);
    }
    else {
      uVar1 = *(int *)(lVar4 + 0x450) + 0x47U & 0xffff;
      iVar3 = regmap_update_bits_base(*(undefined8 *)(lVar4 + 8),uVar1,0x80,0,0,0,0);
      if (iVar3 < 0) {
        uVar5 = 0;
        goto LAB_00101408;
      }
      cVar2 = *(char *)(lVar4 + 0x2b9);
    }
    if (cVar2 != '\0') {
      iVar3 = *(int *)(lVar4 + 0x44c);
      puVar6 = local_3c;
      uVar5 = *(undefined8 *)(lVar4 + 8);
      local_3c[0] = 0;
LAB_00101344:
      uVar1 = iVar3 + 0x78U & 0xffff;
      iVar3 = regmap_bulk_write(uVar5,uVar1,puVar6,1);
      if (iVar3 < 0) {
        _printk(&DAT_001018f9,"qpnp_amoled_write",uVar1,iVar3);
        goto LAB_00101410;
      }
    }
  }
  else {
    if (param_2 == 2) goto LAB_00101264;
    iVar3 = 0;
  }
  *(uint *)(lVar4 + 0x408) = param_2;
  *(uint *)(lVar4 + 0x2b0) = param_2;
LAB_00101364:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qpnp_ab_ibb_regulator_get_mode @ 00101434 size=32
// signature: undefined qpnp_ab_ibb_regulator_get_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_ab_ibb_regulator_get_mode(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)(lVar1 + 0x408);
}



//------------------------------------------------------------
// qpnp_ibb_regulator_enable @ 00101458 size=44
// signature: undefined qpnp_ibb_regulator_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ibb_regulator_enable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x40c) = 1;
  return 0;
}



//------------------------------------------------------------
// qpnp_ibb_regulator_disable @ 00101488 size=40
// signature: undefined qpnp_ibb_regulator_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_ibb_regulator_disable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x40c) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_ibb_regulator_is_enabled @ 001014b4 size=32
// signature: undefined qpnp_ibb_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 qpnp_ibb_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x40c);
}



//------------------------------------------------------------
// qpnp_ibb_regulator_set_load @ 001014d8 size=196
// signature: undefined qpnp_ibb_regulator_set_load(void)
// callers: []
//------------------------------------------------------------

int qpnp_ibb_regulator_set_load(undefined8 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar3 = rdev_get_drvdata();
  if ((*(char *)(lVar3 + 0x410) == '\x04') && (*(char *)(lVar3 + 0x414) == '\0')) {
    if ((int)param_2 < 0) {
      iVar2 = -0x16;
    }
    else {
      uVar4 = 4;
      if (30000 < param_2) {
        uVar4 = 2;
      }
      uVar1 = *(int *)(lVar3 + 0x450) + 0x70U & 0xffff;
      iVar2 = regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),uVar1,7,uVar4,0,0,0);
      if (iVar2 < 0) {
        _printk(&DAT_001017fc,"qpnp_amoled_masked_write",uVar1,uVar4,iVar2);
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 001015a0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_amoled_regulator_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001015d0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_amoled_regulator_driver);
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00103018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00103020 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103028 size=1
// signature: undefined of_find_property(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00103030 size=1
// signature: undefined __of_get_address(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00103038 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103040 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_cell_get @ 00103048 size=1
// signature: undefined devm_nvmem_cell_get(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00103050 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103058 size=1
// signature: undefined _dev_err(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103060 size=1
// signature: undefined _printk(void)
// callers: [qpnp_amoled_regulator_probe, qpnp_ibb_regulator_set_load, qpnp_ab_ibb_regulator_set_mode, qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00103068 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qpnp_amoled_regulator_probe, qpnp_ibb_regulator_set_load, qpnp_ab_ibb_regulator_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 00103070 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [qpnp_amoled_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00103078 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [qpnp_amoled_regulator_probe, qpnp_ab_ibb_regulator_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qpnp_amoled_regulator_probe, qpnp_ab_ibb_regulator_set_mode, qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 00103088 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00103090 size=1
// signature: undefined of_get_property(void)
// callers: [qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00103098 size=1
// signature: undefined devm_regulator_register(void)
// callers: [qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 001030a0 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [qpnp_amoled_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 001030a8 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [qpnp_ibb_regulator_set_load, qpnp_ab_regulator_enable, qpnp_oledb_regulator_set_mode, qpnp_ibb_regulator_disable, qpnp_oledb_regulator_get_voltage, qpnp_oledb_regulator_get_mode, qpnp_ab_ibb_regulator_get_mode, qpnp_ibb_regulator_enable, qpnp_oledb_regulator_is_enabled, qpnp_ab_ibb_regulator_set_voltage, qpnp_ab_regulator_is_enabled, qpnp_ab_ibb_regulator_set_mode, qpnp_ab_ibb_regulator_get_voltage, qpnp_oledb_regulator_set_voltage, qpnp_ibb_regulator_is_enabled, qpnp_oledb_regulator_enable, qpnp_ab_regulator_disable, qpnp_oledb_regulator_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



