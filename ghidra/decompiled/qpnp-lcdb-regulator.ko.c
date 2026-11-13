// Decompiled by Ghidra 12.2
// Program: qpnp-lcdb-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_lcdb_regulator_probe @ 001006ac size=452
// signature: undefined qpnp_lcdb_regulator_probe(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_regulator_probe(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  undefined *puVar5;
  undefined4 uVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x2f8);
  if (lVar7 == 0) {
    _printk(&DAT_00106520,"qpnp_lcdb_regulator_probe");
    iVar2 = -0x13;
  }
  else {
    lVar1 = param_1 + 0x10;
    plVar4 = (long *)devm_kmalloc(lVar1,0x3c0,0xdc0);
    if (plVar4 == (long *)0x0) {
      iVar2 = -0xc;
    }
    else {
      iVar2 = of_property_read_variable_u32_array(lVar7,&DAT_00105fe2,(long)plVar4 + 0x1c,1,0);
      if (iVar2 < 0) {
        puVar5 = &DAT_00106a51;
      }
      else {
        lVar7 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
        plVar4[2] = lVar7;
        if (lVar7 == 0) {
          _printk(&DAT_00105b12,"qpnp_lcdb_regulator_probe",0);
          return -0x16;
        }
        uVar3 = of_device_get_match_data(lVar1);
        lVar7 = *(long *)(param_1 + 0x98);
        *plVar4 = lVar1;
        plVar4[1] = param_1;
        *(uint *)(plVar4 + 3) = uVar3 & 0xff;
        lVar7 = of_match_device(*(undefined8 *)(lVar7 + 0x28),lVar1);
        uVar6 = 0x1130;
        if ((int)plVar4[3] != 4) {
          uVar6 = 4000;
        }
        *(undefined4 *)(plVar4 + 6) = uVar6;
        *(undefined4 *)((long)plVar4 + 0x34) = 6000;
        __mutex_init(plVar4 + 0xc,"&lcdb->lcdb_mutex",&qpnp_lcdb_regulator_probe___key);
        __mutex_init(plVar4 + 0x12,"&lcdb->read_write_mutex",&qpnp_lcdb_regulator_probe___key_6);
        iVar2 = qpnp_lcdb_parse_dt(plVar4);
        if (iVar2 < 0) {
          puVar5 = &DAT_001068eb;
        }
        else {
          iVar2 = qpnp_lcdb_hw_init(plVar4);
          if (-1 < iVar2) {
            _printk(&DAT_00106911,"qpnp_lcdb_regulator_probe",lVar7 + 0x40,
                    *(undefined1 *)((long)plVar4 + 0x4b),*(undefined4 *)((long)plVar4 + 0x24c),
                    *(undefined4 *)((long)plVar4 + 0x3b4),*(undefined4 *)((long)plVar4 + 0xe4));
            return iVar2;
          }
          puVar5 = &DAT_00105e64;
        }
      }
      _printk(puVar5,"qpnp_lcdb_regulator_probe",iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lcdb_regulator_remove @ 00100874 size=8
// signature: undefined qpnp_lcdb_regulator_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_lcdb_regulator_remove(void)

{
  return 0;
}



//------------------------------------------------------------
// qpnp_lcdb_parse_dt @ 0010087c size=2880
// signature: undefined qpnp_lcdb_parse_dt(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

int qpnp_lcdb_parse_dt(long *param_1)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  long lVar12;
  undefined *puVar13;
  char *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  ulong uVar17;
  int iVar18;
  int iVar19;
  ushort uVar20;
  undefined8 uVar21;
  long *plVar22;
  char *local_78;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_70 = 0;
  uVar11 = *(undefined8 *)(*param_1 + 0x2e8);
  local_78 = (char *)0x0;
  lVar12 = of_get_next_available_child(uVar11,0);
  if (lVar12 != 0) {
    plVar22 = param_1 + 0x1b;
    plVar1 = param_1 + 0x75;
    plVar2 = param_1 + 0x48;
    do {
      iVar8 = of_property_read_string(lVar12,"label",&local_78);
      pcVar14 = local_78;
      if (iVar8 < 0) {
        puVar13 = &DAT_00105e98;
        goto LAB_001012ac;
      }
      iVar8 = strcmp(local_78,"ldo");
      if (iVar8 != 0) {
        iVar8 = strcmp(pcVar14,"ncp");
        if (iVar8 == 0) {
          bVar7 = (int)param_1[3] != 4;
          iVar9 = 700;
          if (bVar7) {
            iVar9 = 0x104;
          }
          param_1[0x73] = lVar12;
          iVar18 = 1000;
          if (bVar7) {
            iVar18 = 0x32a;
          }
          *(undefined4 *)((long)param_1 + 0x3b4) = 0xffffffea;
          iVar8 = of_property_read_variable_u32_array
                            (lVar12,"qcom,ncp-voltage-mv",(long)param_1 + 0x3b4,1,0);
          if (-1 < iVar8) {
            if ((*(int *)((long)param_1 + 0x3b4) < (int)param_1[6]) ||
               (*(int *)((long)param_1 + 0x34) < *(int *)((long)param_1 + 0x3b4))) {
              puVar13 = &DAT_00105d41;
              pcVar14 = "qpnp_lcdb_ncp_dt_init";
              iVar15 = *(int *)((long)param_1 + 0x24c);
              iVar18 = *(int *)((long)param_1 + 0x34);
              iVar9 = (int)param_1[6];
              goto LAB_0010135c;
            }
          }
          *(undefined4 *)(param_1 + 0x74) = 0xffffffea;
          of_property_read_variable_u32_array(lVar12,"qcom,ncp-pd",param_1 + 0x74,1,0);
          *(undefined4 *)((long)param_1 + 0x3a4) = 0xffffffea;
          of_property_read_variable_u32_array
                    (lVar12,"qcom,ncp-pd-strength",(undefined4 *)((long)param_1 + 0x3a4),1,0);
          *(int *)plVar1 = -0x16;
          iVar8 = of_property_read_variable_u32_array(lVar12,"qcom,ncp-ilim-ma",plVar1,1,0);
          if ((iVar8 < 0) || ((iVar15 = (int)*plVar1, iVar9 <= iVar15 && (iVar15 <= iVar18)))) {
            pcVar14 = "qcom,ncp-soft-start-us";
            *(undefined4 *)((long)param_1 + 0x3ac) = 0xffffffea;
            puVar16 = (undefined4 *)((long)param_1 + 0x3ac);
            goto LAB_0010094c;
          }
          puVar13 = &DAT_0010580b;
          pcVar14 = "qpnp_lcdb_ncp_dt_init";
LAB_0010135c:
          _printk(puVar13,pcVar14,iVar15,iVar9,iVar18);
          puVar13 = &DAT_00106bde;
          pcVar14 = local_78;
        }
        else {
          iVar8 = strcmp(pcVar14,"bst");
          if (iVar8 == 0) {
            lVar6 = param_1[3];
            param_1[0x18] = lVar12;
            *(undefined4 *)(param_1 + 0x19) = 0xffffffea;
            of_property_read_variable_u32_array(lVar12,"qcom,bst-pd",param_1 + 0x19,1,0);
            *(undefined4 *)((long)param_1 + 0xcc) = 0xffffffea;
            of_property_read_variable_u32_array
                      (lVar12,"qcom,bst-pd-strength",(long)param_1 + 0xcc,1,0);
            *(undefined4 *)(param_1 + 0x1a) = 0xffffffea;
            iVar8 = of_property_read_variable_u32_array
                              (lVar12,"qcom,bst-ilim-ma",param_1 + 0x1a,1,0);
            if (-1 < iVar8) {
              bVar7 = (int)lVar6 != 4;
              iVar15 = (int)param_1[0x1a];
              iVar18 = 0x8ca;
              if (bVar7) {
                iVar18 = 0x640;
              }
              iVar9 = 0x46a;
              if (bVar7) {
                iVar9 = 200;
              }
              if ((iVar15 < iVar9) || (iVar18 < iVar15)) {
                puVar13 = &DAT_0010580b;
                pcVar14 = "qpnp_lcdb_bst_dt_init";
                goto LAB_0010135c;
              }
            }
            *(undefined4 *)((long)param_1 + 0xd4) = 0xffffffea;
            of_property_read_variable_u32_array(lVar12,"qcom,bst-ps",(long)param_1 + 0xd4,1,0);
            *(undefined4 *)(param_1 + 0x1b) = 0xffffffea;
            if ((int)param_1[3] == 4) {
              iVar8 = of_property_read_variable_u32_array
                                (lVar12,"qcom,bst-ps-threshold-mv",plVar22,1,0);
              if ((-1 < iVar8) && (iVar15 = (int)*plVar22, 0xa8 < iVar15 - 0x168U)) {
                puVar13 = &DAT_0010557e;
                pcVar14 = "qpnp_lcdb_bst_dt_init";
                iVar18 = 0x210;
                iVar9 = 0x168;
                goto LAB_0010135c;
              }
            }
            else {
              iVar8 = of_property_read_variable_u32_array
                                (lVar12,"qcom,bst-ps-threshold-ma",plVar22,1,0);
              if ((-1 < iVar8) && (iVar15 = (int)*plVar22, 0x1e < iVar15 - 0x32U)) {
                puVar13 = &DAT_00105b93;
                pcVar14 = "qpnp_lcdb_bst_dt_init";
                iVar18 = 0x50;
                iVar9 = 0x32;
                goto LAB_0010135c;
              }
            }
            uVar20 = 200;
            if ((int)param_1[3] != 1) {
              uVar20 = 0x96;
            }
            of_property_read_variable_u16_array(lVar12,"qcom,bst-headroom-mv",param_1 + 0x1d,1,0);
            if (*(ushort *)(param_1 + 0x1d) < uVar20) {
              *(ushort *)(param_1 + 0x1d) = uVar20;
            }
            goto LAB_00100958;
          }
          puVar13 = &DAT_00105ce2;
        }
        _printk(puVar13,"qpnp_lcdb_parse_dt",pcVar14);
        goto LAB_00101378;
      }
      bVar7 = (int)param_1[3] != 4;
      iVar8 = 0x23;
      if (bVar7) {
        iVar8 = 0x6e;
      }
      param_1[0x46] = lVar12;
      iVar19 = 0x348;
      if (bVar7) {
        iVar19 = 0x1cc;
      }
      *(undefined4 *)((long)param_1 + 0x24c) = 0xffffffea;
      iVar9 = of_property_read_variable_u32_array
                        (lVar12,"qcom,ldo-voltage-mv",(int *)((long)param_1 + 0x24c),1,0);
      if (-1 < iVar9) {
        iVar9 = (int)param_1[6];
        iVar18 = *(int *)((long)param_1 + 0x34);
        iVar15 = *(int *)((long)param_1 + 0x24c);
        if ((iVar15 < iVar9) || (iVar18 < iVar15)) {
          puVar13 = &DAT_00105d0b;
          pcVar14 = "qpnp_lcdb_ldo_dt_init";
          goto LAB_0010135c;
        }
      }
      *(undefined4 *)(param_1 + 0x47) = 0xffffffea;
      of_property_read_variable_u32_array(lVar12,"qcom,ldo-pd",param_1 + 0x47,1,0);
      *(undefined4 *)((long)param_1 + 0x23c) = 0xffffffea;
      of_property_read_variable_u32_array
                (lVar12,"qcom,ldo-pd-strength",(undefined4 *)((long)param_1 + 0x23c),1,0);
      *(int *)plVar2 = -0x16;
      iVar9 = of_property_read_variable_u32_array(lVar12,"qcom,ldo-ilim-ma",plVar2,1,0);
      if ((-1 < iVar9) && ((iVar15 = (int)*plVar2, iVar15 < iVar8 || (iVar19 < iVar15)))) {
        puVar13 = &DAT_0010580b;
        pcVar14 = "qpnp_lcdb_ldo_dt_init";
        iVar18 = iVar19;
        iVar9 = iVar8;
        goto LAB_0010135c;
      }
      pcVar14 = "qcom,ldo-soft-start-us";
      *(undefined4 *)((long)param_1 + 0x244) = 0xffffffea;
      puVar16 = (undefined4 *)((long)param_1 + 0x244);
LAB_0010094c:
      of_property_read_variable_u32_array(lVar12,pcVar14,puVar16,1,0);
LAB_00100958:
      lVar12 = of_get_next_available_child(uVar11,lVar12);
    } while (lVar12 != 0);
  }
  lVar12 = of_find_property(uVar11,"qcom,ttw-enable",0);
  if (lVar12 != 0) {
    local_6c = 0;
    if ((int)param_1[3] != 4) {
      uVar21 = *(undefined8 *)(*param_1 + 0x2e8);
      lVar12 = of_find_property(uVar21,"qcom,ttw-mode-sw",0);
      if (lVar12 != 0) {
        *(undefined1 *)((long)param_1 + 0x4a) = 1;
        iVar8 = of_property_read_variable_u32_array(uVar21,"qcom,attw-toff-ms",&local_6c,1,0);
        uVar4 = local_6c;
        if (iVar8 < 0) {
          puVar13 = &DAT_00105924;
LAB_00101218:
          _printk(puVar13,"qpnp_lcdb_parse_ttw");
        }
        else if (local_6c - 4 < 0x1d) {
          iVar8 = of_property_read_variable_u32_array(uVar21,"qcom,attw-ton-ms",&local_6c,1,0);
          if (iVar8 < 0) {
            puVar13 = &DAT_00105972;
            goto LAB_00101218;
          }
          if (0x1c < local_6c - 4) {
            puVar13 = &DAT_00106ff8;
            goto LAB_00101238;
          }
          plVar22 = param_1 + 0x12;
          uVar5 = local_6c >> 2;
          iVar8 = *(int *)((long)param_1 + 0x1c);
          mutex_lock(plVar22);
          uVar3 = iVar8 + 0x40U & 0xffff;
          uVar4 = (0x1fU - (int)LZCOUNT(uVar5) | (int)LZCOUNT(uVar4 >> 2) * -4 + 0x7cU) & 0xff;
          iVar8 = regmap_update_bits_base(param_1[2],uVar3,0xf,uVar4,0,0,0);
          if (-1 < iVar8) {
            mutex_unlock(plVar22);
            goto LAB_00100e28;
          }
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar3,uVar4,iVar8);
          mutex_unlock(plVar22);
          _printk(&DAT_00106ced,"qpnp_lcdb_parse_ttw",iVar8);
        }
        else {
          puVar13 = &DAT_00106633;
LAB_00101238:
          _printk(puVar13,"qpnp_lcdb_parse_ttw",local_6c,4,0x20);
          iVar8 = -0x16;
        }
        puVar13 = &DAT_00106dfa;
LAB_001012ac:
        _printk(puVar13,"qpnp_lcdb_parse_dt",iVar8);
        goto LAB_0010137c;
      }
    }
LAB_00100e28:
    *(undefined1 *)((long)param_1 + 0x49) = 1;
  }
  uVar10 = platform_get_irq_byname(param_1[1],"sc-irq");
  *(undefined4 *)((long)param_1 + 0x24) = uVar10;
  lVar12 = of_find_property(uVar11,"qcom,voltage-step-ramp",0);
  *(bool *)((long)param_1 + 0x4e) = lVar12 != 0;
  lVar12 = of_find_property(uVar11,"qcom,ncp-symmetry",0);
  plVar22 = param_1 + 7;
  *plVar22 = -0x1500000016;
  param_1[5] = -0x1500000016;
  *(bool *)(param_1 + 9) = lVar12 != 0;
  param_1[8] = -0x1500000016;
  iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,pwrdn-delay-ms",&local_70,1,0);
  if (iVar8 < 0) {
LAB_00100ee8:
    iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,pwrup-delay-ms",&local_70,1,0);
    if (-1 < iVar8) {
      uVar17 = (ulong)(int)local_70;
      if (8 < local_70) goto LAB_00101004;
      if ((0x113U >> (ulong)(local_70 & 0x1f) & 1) != 0) {
        *(undefined4 *)((long)param_1 + 0x2c) = *(undefined4 *)(&DAT_00107860 + uVar17 * 4);
      }
    }
    iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,pwrup-config",plVar22,1,0);
    if ((iVar8 < 0) || ((int)*plVar22 < 5)) {
      iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,high-p2-blank-time-ns",&local_70,1,0)
      ;
      if (iVar8 < 0) goto LAB_00101044;
      if (0xd2 < local_70 - 0x28) {
LAB_001010ec:
        uVar17 = (ulong)local_70;
        puVar13 = &DAT_00106303;
        pcVar14 = "qpnp_lcdb_p2_blk_time";
        uVar11 = 0x28;
        uVar21 = 0xfa;
        goto LAB_001011c4;
      }
      if ((int)local_70 < 0x9f) {
        if (0x62 < (int)local_70) {
          if (local_70 == 99) {
            uVar10 = 2;
          }
          else {
            if (local_70 != 0x81) goto LAB_00101044;
            uVar10 = 3;
          }
          goto LAB_00101040;
        }
        if (local_70 == 0x28) {
          *(undefined4 *)((long)param_1 + 0x3c) = 0;
        }
        else if (local_70 == 0x45) {
          uVar10 = 1;
          goto LAB_00101040;
        }
      }
      else {
        if ((int)local_70 < 0xdc) {
          if (local_70 == 0x9f) {
            uVar10 = 4;
          }
          else {
            if (local_70 != 0xbd) goto LAB_00101044;
            uVar10 = 5;
          }
        }
        else if (local_70 == 0xdc) {
          uVar10 = 6;
        }
        else {
          if (local_70 != 0xfa) goto LAB_00101044;
          uVar10 = 7;
        }
LAB_00101040:
        *(undefined4 *)((long)param_1 + 0x3c) = uVar10;
      }
LAB_00101044:
      iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,low-p2-blank-time-ns",&local_70,1,0);
      if (iVar8 < 0) goto LAB_0010112c;
      if (0xd2 < local_70 - 0x28) goto LAB_001010ec;
      if ((int)local_70 < 0x9f) {
        if (0x62 < (int)local_70) {
          if (local_70 == 99) {
            uVar10 = 2;
          }
          else {
            if (local_70 != 0x81) goto LAB_0010112c;
            uVar10 = 3;
          }
          goto LAB_00101128;
        }
        if (local_70 == 0x28) {
          *(undefined4 *)(param_1 + 8) = 0;
        }
        else if (local_70 == 0x45) {
          uVar10 = 1;
          goto LAB_00101128;
        }
      }
      else {
        if ((int)local_70 < 0xdc) {
          if (local_70 == 0x9f) {
            uVar10 = 4;
          }
          else {
            if (local_70 != 0xbd) goto LAB_0010112c;
            uVar10 = 5;
          }
        }
        else if (local_70 == 0xdc) {
          uVar10 = 6;
        }
        else {
          if (local_70 != 0xfa) goto LAB_0010112c;
          uVar10 = 7;
        }
LAB_00101128:
        *(undefined4 *)(param_1 + 8) = uVar10;
      }
LAB_0010112c:
      iVar8 = of_property_read_variable_u32_array(uVar11,"qcom,mpc-current-thr-ma",&local_70,1,0);
      if (iVar8 < 0) {
        iVar8 = 0;
        goto LAB_0010137c;
      }
      uVar17 = (ulong)local_70;
      if (local_70 - 0xa0 < 0x119) {
        iVar8 = 0;
        *(uint *)((long)param_1 + 0x44) = (local_70 - 0xa0 & 0xffff) / 0x28;
        goto LAB_0010137c;
      }
      puVar13 = &DAT_00106755;
      pcVar14 = "qpnp_lcdb_mpc_current";
      uVar11 = 0xa0;
      uVar21 = 0x1b8;
      goto LAB_001011c4;
    }
    _printk(&DAT_00105b45,"qpnp_lcdb_parse_dt",(int)*plVar22,4);
  }
  else {
    uVar17 = (ulong)(int)local_70;
    if (local_70 < 9) {
      if ((0x113U >> (ulong)(local_70 & 0x1f) & 1) != 0) {
        *(undefined4 *)(param_1 + 5) = *(undefined4 *)(&DAT_00107860 + uVar17 * 4);
      }
      goto LAB_00100ee8;
    }
LAB_00101004:
    puVar13 = &DAT_0010644a;
    pcVar14 = "qpnp_lcdb_pwrup_dn_delay";
    uVar11 = 0;
    uVar21 = 8;
LAB_001011c4:
    _printk(puVar13,pcVar14,uVar17,uVar11,uVar21);
  }
LAB_00101378:
  iVar8 = -0x16;
LAB_0010137c:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qpnp_lcdb_hw_init @ 001013bc size=5288
// signature: undefined qpnp_lcdb_hw_init(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

int qpnp_lcdb_hw_init(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined2 uVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  char local_78 [4];
  byte local_74 [4];
  byte local_70 [4];
  byte local_6c [4];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_78[0] = '\0';
  if (*(int *)(param_1 + 3) - 2U < 3) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  }
  uVar20 = *(uint *)(param_1 + 5);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x66U & 0xffff;
    uVar20 = uVar20 & 0xff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,3,uVar20,0,0,0);
    if (-1 < iVar9) {
      mutex_unlock(param_1 + 0x12);
      goto LAB_00101464;
    }
LAB_001017ec:
    _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar20,iVar9);
    mutex_unlock(param_1 + 0x12);
    goto LAB_0010279c;
  }
LAB_00101464:
  uVar20 = *(uint *)((long)param_1 + 0x2c);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x66U & 0xffff;
    uVar20 = (uVar20 & 0x3f) << 2;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,0xc,uVar20,0,0,0);
    if (iVar9 < 0) goto LAB_001017ec;
    mutex_unlock(param_1 + 0x12);
  }
  uVar20 = *(uint *)(param_1 + 7);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x43U & 0xffff;
    uVar20 = uVar20 & 0xff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,7,uVar20,0,0,0);
    if (iVar9 < 0) goto LAB_001017ec;
    mutex_unlock(param_1 + 0x12);
  }
  uVar20 = *(uint *)((long)param_1 + 0x3c);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x54U & 0xffff;
    uVar20 = (uVar20 & 0xf) << 4;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,0x70,uVar20,0,0,0);
    if (iVar9 < 0) goto LAB_001017ec;
    mutex_unlock(param_1 + 0x12);
  }
  uVar20 = *(uint *)(param_1 + 8);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x54U & 0xffff;
    uVar20 = uVar20 & 0xff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,7,uVar20,0,0,0);
    if (iVar9 < 0) goto LAB_001017ec;
    mutex_unlock(param_1 + 0x12);
  }
  uVar20 = *(uint *)((long)param_1 + 0x44);
  if (uVar20 != 0xffffffea) {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x60U & 0xffff;
    uVar20 = uVar20 & 0xff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,7,uVar20,0,0,0);
    if (iVar9 < 0) goto LAB_001017ec;
    mutex_unlock(param_1 + 0x12);
  }
  if (*(char *)(param_1 + 9) != '\0') {
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(param_1 + 0x12);
    uVar16 = iVar9 + 0x81U & 0xffff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar16,0x80,0x80,0,0,0);
    if (iVar9 < 0) {
      uVar20 = 0x80;
      goto LAB_001017ec;
    }
    mutex_unlock(param_1 + 0x12);
  }
  iVar9 = *(int *)(param_1 + 3);
  bVar8 = iVar9 == 4;
  bVar17 = 0;
  if (!bVar8) {
    bVar17 = 0x80;
  }
  iVar13 = 0x55;
  if (bVar8) {
    iVar13 = 0x56;
  }
  uVar20 = 0x80;
  if (!bVar8) {
    uVar20 = 0xfd;
  }
  iVar18 = 0x18;
  if (!bVar8) {
    iVar18 = 10;
  }
  puVar2 = &bst_dbc_us;
  if (!bVar8) {
    puVar2 = dbc_us;
  }
  iVar19 = -0x168;
  if (!bVar8) {
    iVar19 = -0x32;
  }
  local_74[0] = 0;
  uVar10 = is_lcdb_enabled(param_1);
  if ((uVar10 & 1) == 0) {
    iVar4 = *(int *)(param_1 + 0x19);
    if (iVar4 != -0x16) {
      puVar1 = param_1 + 0x12;
      iVar5 = *(int *)((long)param_1 + 0x1c);
      mutex_lock(puVar1);
      uVar14 = 0x80;
      if (iVar9 != 4) {
        uVar14 = 2;
      }
      uVar16 = iVar5 + 0x47U & 0xffff;
      uVar15 = 0xff;
      if (iVar4 != 0) {
        uVar15 = 0;
      }
      iVar9 = regmap_update_bits_base(param_1[2],uVar16,uVar14,uVar15 ^ uVar20,0,0,0);
      if (-1 < iVar9) {
        mutex_unlock(puVar1);
        goto LAB_00101740;
      }
      _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar15 ^ uVar20,iVar9);
      mutex_unlock(puVar1);
      puVar11 = &DAT_001059ae;
      goto LAB_00101dd8;
    }
LAB_00101740:
    iVar4 = *(int *)((long)param_1 + 0xcc);
    if (iVar4 == -0x16) {
LAB_00101798:
      iVar9 = *(int *)(param_1 + 0x1a);
      if (iVar9 != -0x16) {
        if (*(int *)(param_1 + 3) == 4) {
          uVar20 = (iVar9 + -0x46a) / 0xa0;
        }
        else {
          uVar20 = iVar9 / 200 - 1;
        }
        puVar1 = param_1 + 0x12;
        iVar9 = *(int *)((long)param_1 + 0x1c);
        local_74[0] = (byte)(uVar20 & 7) | bVar17;
        mutex_lock(puVar1);
        uVar16 = iVar9 + 0x4bU & 0xffff;
        uVar20 = uVar20 & 7 | (uint)bVar17;
        iVar9 = regmap_update_bits_base(param_1[2],uVar16,bVar17 | 7,uVar20,0,0,0);
        if (iVar9 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00106af2;
          goto LAB_00101dd8;
        }
        mutex_unlock(puVar1);
      }
      iVar4 = *(int *)((long)param_1 + 0xd4);
      if (iVar4 != -0x16) {
        puVar1 = param_1 + 0x12;
        iVar9 = *(int *)((long)param_1 + 0x1c);
        mutex_lock(puVar1);
        uVar20 = iVar9 + 0x50U & 0xffff;
        iVar9 = regmap_update_bits_base(param_1[2],uVar20,0x80,(ulong)(iVar4 != 0) << 7,0,0,0);
        if (iVar9 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar20,(ulong)(iVar4 != 0) << 7,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00107086;
          goto LAB_00101dd8;
        }
        mutex_unlock(puVar1);
      }
      if (*(int *)(param_1 + 0x1b) != -0x16) {
        iVar9 = *(int *)((long)param_1 + 0x1c);
        uVar20 = 0;
        if (iVar18 != 0) {
          uVar20 = (*(int *)(param_1 + 0x1b) + iVar19) / iVar18;
        }
        puVar1 = param_1 + 0x12;
        uVar16 = 3;
        if (*(int *)(param_1 + 3) != 1) {
          uVar16 = 7;
        }
        local_74[0] = (byte)(uVar16 & uVar20) | 0x80;
        mutex_lock(puVar1);
        uVar15 = iVar9 + 0x50U & 0xffff;
        uVar20 = uVar16 & uVar20 | 0x80;
        iVar9 = regmap_update_bits_base(param_1[2],uVar15,uVar16 | 0x80,uVar20,0,0,0);
        if (iVar9 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar15,uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00105d90;
          goto LAB_00101dd8;
        }
        mutex_unlock(puVar1);
      }
      goto LAB_0010194c;
    }
    puVar1 = param_1 + 0x12;
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(puVar1);
    uVar20 = iVar9 + 0x47U & 0xffff;
    iVar9 = regmap_update_bits_base(param_1[2],uVar20,1,iVar4 != 0,0,0,0);
    if (-1 < iVar9) {
      mutex_unlock(puVar1);
      goto LAB_00101798;
    }
    _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar20,iVar4 != 0,iVar9);
    mutex_unlock(puVar1);
    pcVar3 = "(weak)";
    if (*(int *)((long)param_1 + 0xcc) != 0) {
      pcVar3 = "(strong)";
    }
    _printk(&DAT_00106ab8,"qpnp_lcdb_init_bst",pcVar3,iVar9);
LAB_00101de8:
    puVar11 = &DAT_0010623a;
  }
  else {
LAB_0010194c:
    iVar9 = qpnp_lcdb_get_voltage(param_1,(long)param_1 + 0xe4,2);
    if (iVar9 < 0) {
      puVar11 = &DAT_00106995;
LAB_00101dd8:
      _printk(puVar11,"qpnp_lcdb_init_bst",iVar9);
      goto LAB_00101de8;
    }
    puVar1 = param_1 + 0x12;
    iVar9 = *(int *)((long)param_1 + 0x1c);
    mutex_lock(puVar1);
    uVar20 = iVar9 + iVar13 & 0xffff;
    iVar9 = regmap_bulk_read(param_1[2],uVar20,local_74,1);
    if (iVar9 < 0) {
      _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
      mutex_unlock(puVar1);
      puVar11 = &DAT_0010702a;
      goto LAB_00101dd8;
    }
    mutex_unlock(puVar1);
    iVar9 = *(int *)(param_1 + 3);
    iVar13 = *(int *)((long)param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(puVar2 + ((ulong)local_74[0] & 3) * 4);
    mutex_lock(puVar1);
    if (iVar9 == 1) {
      uVar20 = iVar13 + 0x5fU & 0xffff;
      iVar9 = regmap_bulk_read(param_1[2],uVar20,local_74,1);
      if (iVar9 < 0) {
        _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
        mutex_unlock(puVar1);
        puVar11 = &DAT_00105c90;
        goto LAB_00101dd8;
      }
      mutex_unlock(puVar1);
      uVar12 = 200;
      *(uint *)((long)param_1 + 0xdc) = (local_74[0] & 3) * 200 + 200;
      if (*(short *)(param_1 + 0x1d) == 0) goto LAB_00101a50;
    }
    else {
      uVar20 = iVar13 + 0x5bU & 0xffff;
      iVar9 = regmap_bulk_read(param_1[2],uVar20,local_74,1);
      if (iVar9 < 0) {
        _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
        mutex_unlock(puVar1);
        puVar11 = &DAT_001059dc;
        goto LAB_00101dd8;
      }
      mutex_unlock(puVar1);
      *(undefined4 *)((long)param_1 + 0xdc) =
           *(undefined4 *)(soft_start_us + ((ulong)local_74[0] & 3) * 4);
      if (*(short *)(param_1 + 0x1d) == 0) {
        uVar12 = 0x96;
LAB_00101a50:
        *(undefined2 *)(param_1 + 0x1d) = uVar12;
      }
    }
    iVar18 = *(int *)(param_1 + 3);
    local_70[0] = 0;
    bVar8 = iVar18 == 4;
    iVar13 = 0x7b;
    if (!bVar8) {
      iVar13 = 0x7c;
    }
    uVar20 = 0x80;
    if (!bVar8) {
      uVar20 = 0xfd;
    }
    uVar10 = is_lcdb_enabled(param_1);
    if ((uVar10 & 1) == 0) {
      if ((*(int *)((long)param_1 + 0x24c) != -0x16) &&
         (iVar9 = qpnp_lcdb_set_voltage(param_1,*(int *)((long)param_1 + 0x24c),0), iVar9 < 0)) {
        puVar11 = &DAT_0010574a;
        goto LAB_001025f8;
      }
      iVar9 = *(int *)(param_1 + 0x47);
      if (iVar9 != -0x16) {
        iVar19 = *(int *)((long)param_1 + 0x1c);
        mutex_lock(puVar1);
        uVar16 = iVar19 + 0x77U & 0xffff;
        uVar14 = 0x80;
        if (iVar18 != 4) {
          uVar14 = 2;
        }
        uVar15 = 0xff;
        if (iVar9 != 0) {
          uVar15 = 0;
        }
        iVar9 = regmap_update_bits_base(param_1[2],uVar16,uVar14,uVar15 ^ uVar20,0,0,0);
        if (iVar9 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar15 ^ uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00107058;
          goto LAB_001025f8;
        }
        mutex_unlock(puVar1);
      }
      iVar19 = *(int *)((long)param_1 + 0x23c);
      if (iVar19 == -0x16) {
LAB_00101b5c:
        uVar20 = *(uint *)(param_1 + 0x48);
        if (uVar20 == 0xffffffea) {
LAB_00101f9c:
          if ((*(int *)((long)param_1 + 0x244) == -0x16) ||
             (iVar9 = qpnp_lcdb_set_soft_start(param_1,*(int *)((long)param_1 + 0x244),0),
             -1 < iVar9)) goto LAB_00101fb8;
          puVar11 = &DAT_00105f0c;
          goto LAB_001025f8;
        }
        if (*(int *)(param_1 + 3) == 4) {
          if (uVar20 < 0x23) {
            iVar9 = 0;
          }
          else if (uVar20 < 0xaf) {
            iVar9 = 1;
          }
          else if (uVar20 < 0x118) {
            iVar9 = 2;
          }
          else if (uVar20 < 0x1a4) {
            iVar9 = 3;
          }
          else if (uVar20 < 0x1c7) {
            iVar9 = 4;
          }
          else if (uVar20 < 0x253) {
            iVar9 = 5;
          }
          else if (uVar20 < 700) {
            iVar9 = 6;
          }
          else {
            iVar9 = 7;
            if (0x347 < uVar20) {
              iVar9 = 8;
            }
          }
          uVar20 = 0;
          if (iVar9 != 0) {
            uVar20 = iVar9 - 1;
          }
        }
        else {
          uVar20 = (uint)((ulong)((long)(int)(uVar20 - 0x6e) * 0x51eb851f) >> 0x24) -
                   ((int)(uVar20 - 0x6e) >> 0x1f) & 7;
        }
        iVar9 = *(int *)((long)param_1 + 0x1c);
        mutex_lock(puVar1);
        uVar16 = iVar9 + 0x7bU & 0xffff;
        uVar15 = uVar20 & 0xff | 0x80;
        iVar9 = regmap_update_bits_base(param_1[2],uVar16,0x87,uVar15,0,0,0);
        if (iVar9 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar15,iVar9);
          mutex_unlock(puVar1);
          uVar20 = uVar20 & 0xff;
          puVar11 = &DAT_0010633b;
        }
        else {
          mutex_unlock(puVar1);
          iVar9 = *(int *)((long)param_1 + 0x1c);
          uVar20 = uVar20 << ((ulong)bVar8 << 2);
          local_70[0] = (byte)uVar20;
          mutex_lock(puVar1);
          uVar16 = iVar9 + iVar13 & 0xffff;
          uVar20 = uVar20 & 0xff;
          uVar14 = 0x70;
          if (iVar18 != 4) {
            uVar14 = 7;
          }
          iVar9 = regmap_update_bits_base(param_1[2],uVar16,uVar14,uVar20,0,0,0);
          if (-1 < iVar9) {
            mutex_unlock(puVar1);
            goto LAB_00101f9c;
          }
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_0010657a;
        }
        _printk(puVar11,"qpnp_lcdb_init_ldo",uVar20,iVar9);
      }
      else {
        iVar9 = *(int *)((long)param_1 + 0x1c);
        mutex_lock(puVar1);
        uVar20 = iVar9 + 0x77U & 0xffff;
        iVar9 = regmap_update_bits_base(param_1[2],uVar20,1,iVar19 != 0,0,0,0);
        if (-1 < iVar9) {
          mutex_unlock(puVar1);
          goto LAB_00101b5c;
        }
        _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar20,iVar19 != 0,iVar9);
        mutex_unlock(puVar1);
        pcVar3 = "(weak)";
        if (*(int *)((long)param_1 + 0x23c) != 0) {
          pcVar3 = "(strong)";
        }
        _printk(&DAT_00105ed2,"qpnp_lcdb_init_ldo",pcVar3,iVar9);
      }
LAB_00102608:
      puVar11 = &DAT_00106ece;
    }
    else {
LAB_00101fb8:
      iVar9 = qpnp_lcdb_get_voltage(param_1,(long)param_1 + 0x24c,0);
      if (iVar9 < 0) {
        puVar11 = &DAT_001070b2;
LAB_001025f8:
        _printk(puVar11,"qpnp_lcdb_init_ldo",iVar9);
        goto LAB_00102608;
      }
      iVar9 = *(int *)((long)param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x4a) = *(undefined4 *)((long)param_1 + 0x24c);
      mutex_lock(puVar1);
      uVar20 = iVar9 + 0x75U & 0xffff;
      iVar9 = regmap_bulk_read(param_1[2],uVar20,local_70,1);
      if (iVar9 < 0) {
        _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
        mutex_unlock(puVar1);
        puVar11 = &DAT_001065b7;
        goto LAB_001025f8;
      }
      mutex_unlock(puVar1);
      iVar9 = *(int *)((long)param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x49) = *(undefined4 *)(dbc_us + ((ulong)local_70[0] & 3) * 4);
      mutex_lock(puVar1);
      uVar20 = iVar9 + 0x7fU & 0xffff;
      iVar9 = regmap_bulk_read(param_1[2],uVar20,local_70,1);
      if (iVar9 < 0) {
        _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
        mutex_unlock(puVar1);
        puVar11 = &DAT_00106c08;
        goto LAB_001025f8;
      }
      mutex_unlock(puVar1);
      *(undefined4 *)((long)param_1 + 0x244) =
           *(undefined4 *)(soft_start_us + ((ulong)local_70[0] & 3) * 4);
      iVar9 = qpnp_lcdb_regulator_register(param_1,0);
      if (iVar9 < 0) {
        puVar11 = &DAT_00106d32;
        goto LAB_001025f8;
      }
      iVar18 = *(int *)(param_1 + 3);
      bVar8 = iVar18 == 4;
      iVar13 = 0x8b;
      if (!bVar8) {
        iVar13 = 0x8c;
      }
      uVar20 = 2;
      if (!bVar8) {
        uVar20 = 0xfd;
      }
      puVar2 = ncp_dbc_us;
      if (!bVar8) {
        puVar2 = dbc_us;
      }
      local_6c[0] = 0;
      uVar10 = is_lcdb_enabled(param_1);
      if ((uVar10 & 1) == 0) {
        if ((*(int *)((long)param_1 + 0x3b4) != -0x16) &&
           (iVar9 = qpnp_lcdb_set_voltage(param_1,*(int *)((long)param_1 + 0x3b4),1), iVar9 < 0)) {
          puVar11 = &DAT_0010574a;
          goto LAB_00102774;
        }
        iVar9 = *(int *)(param_1 + 0x74);
        if (iVar9 != -0x16) {
          iVar19 = *(int *)((long)param_1 + 0x1c);
          mutex_lock(puVar1);
          uVar16 = 0xff;
          if (iVar9 != 0) {
            uVar16 = 0;
          }
          uVar15 = iVar19 + 0x87U & 0xffff;
          iVar9 = regmap_update_bits_base(param_1[2],uVar15,2,uVar16 ^ uVar20,0,0,0);
          if (iVar9 < 0) {
            _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar15,uVar16 ^ uVar20,iVar9);
            mutex_unlock(puVar1);
            puVar11 = &DAT_001062d5;
            goto LAB_00102774;
          }
          mutex_unlock(puVar1);
        }
        iVar19 = *(int *)((long)param_1 + 0x3a4);
        if (iVar19 == -0x16) {
LAB_0010217c:
          uVar20 = *(uint *)(param_1 + 0x75);
          if (uVar20 == 0xffffffea) {
LAB_0010233c:
            if ((*(int *)((long)param_1 + 0x3ac) == -0x16) ||
               (iVar9 = qpnp_lcdb_set_soft_start(param_1,*(int *)((long)param_1 + 0x3ac),1),
               -1 < iVar9)) goto LAB_00102358;
            puVar11 = &DAT_00105a30;
            goto LAB_00102774;
          }
          uVar16 = 700;
          if (iVar18 != 4) {
            uVar16 = 0x104;
          }
          if (uVar20 < uVar16) {
            iVar9 = 0;
          }
          else {
            uVar16 = 800;
            if (iVar18 != 4) {
              uVar16 = 0x1cc;
            }
            if (uVar20 < uVar16) {
              iVar9 = 1;
            }
            else {
              uVar16 = 900;
              if (iVar18 != 4) {
                uVar16 = 0x280;
              }
              if (uVar20 < uVar16) {
                iVar9 = 2;
              }
              else {
                uVar16 = 1000;
                if (iVar18 != 4) {
                  uVar16 = 0x32a;
                }
                if (uVar16 <= uVar20) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(1,0x102864);
                  (*pcVar7)();
                }
                iVar9 = 3;
              }
            }
          }
          iVar19 = *(int *)((long)param_1 + 0x1c);
          uVar20 = 0;
          if (iVar9 != 0) {
            uVar20 = iVar9 - 1;
          }
          mutex_lock(puVar1);
          uVar16 = iVar19 + 0x8bU & 0xffff;
          iVar9 = regmap_update_bits_base(param_1[2],uVar16,0x83,uVar20 | 0x80,0,0,0);
          if (iVar9 < 0) {
            _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar20 | 0x80,iVar9);
            mutex_unlock(puVar1);
            puVar11 = &DAT_001057ca;
          }
          else {
            mutex_unlock(puVar1);
            iVar9 = *(int *)((long)param_1 + 0x1c);
            uVar20 = uVar20 << ((ulong)bVar8 << 2);
            local_6c[0] = (byte)uVar20;
            mutex_lock(puVar1);
            uVar16 = iVar9 + iVar13 & 0xffff;
            uVar20 = uVar20 & 0xff;
            uVar14 = 0x30;
            if (iVar18 != 4) {
              uVar14 = 3;
            }
            iVar9 = regmap_update_bits_base(param_1[2],uVar16,uVar14,uVar20,0,0,0);
            if (-1 < iVar9) {
              mutex_unlock(puVar1);
              goto LAB_0010233c;
            }
            _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar16,uVar20,iVar9);
            mutex_unlock(puVar1);
            puVar11 = &DAT_001067f9;
          }
          _printk(puVar11,"qpnp_lcdb_init_ncp",uVar20,iVar9);
        }
        else {
          iVar9 = *(int *)((long)param_1 + 0x1c);
          mutex_lock(puVar1);
          uVar20 = iVar9 + 0x87U & 0xffff;
          iVar9 = regmap_update_bits_base(param_1[2],uVar20,1,iVar19 != 0,0,0,0);
          if (-1 < iVar9) {
            mutex_unlock(puVar1);
            goto LAB_0010217c;
          }
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar20,iVar19 != 0,iVar9);
          mutex_unlock(puVar1);
          pcVar3 = "(weak)";
          if (*(int *)((long)param_1 + 0x3a4) != 0) {
            pcVar3 = "(strong)";
          }
          _printk(&DAT_00106ab8,"qpnp_lcdb_init_ncp",pcVar3,iVar9);
        }
LAB_00102784:
        puVar11 = &DAT_0010571e;
      }
      else {
LAB_00102358:
        iVar9 = qpnp_lcdb_get_voltage(param_1,(long)param_1 + 0x3b4,1);
        if (iVar9 < 0) {
          puVar11 = &DAT_001060a9;
LAB_00102774:
          _printk(puVar11,"qpnp_lcdb_init_ncp",iVar9);
          goto LAB_00102784;
        }
        iVar9 = *(int *)((long)param_1 + 0x1c);
        *(undefined4 *)(param_1 + 0x77) = *(undefined4 *)((long)param_1 + 0x3b4);
        mutex_lock(puVar1);
        uVar20 = iVar9 + 0x85U & 0xffff;
        iVar9 = regmap_bulk_read(param_1[2],uVar20,local_6c,1);
        if (iVar9 < 0) {
          _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00106a23;
          goto LAB_00102774;
        }
        mutex_unlock(puVar1);
        iVar9 = *(int *)((long)param_1 + 0x1c);
        *(undefined4 *)(param_1 + 0x76) = *(undefined4 *)(puVar2 + ((ulong)local_6c[0] & 3) * 4);
        mutex_lock(puVar1);
        uVar20 = iVar9 + 0x8fU & 0xffff;
        iVar9 = regmap_bulk_read(param_1[2],uVar20,local_6c,1);
        if (iVar9 < 0) {
          _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
          mutex_unlock(puVar1);
          puVar11 = &DAT_00106b7b;
          goto LAB_00102774;
        }
        mutex_unlock(puVar1);
        *(undefined4 *)((long)param_1 + 0x3ac) =
             *(undefined4 *)(soft_start_us + ((ulong)local_6c[0] & 3) * 4);
        iVar9 = qpnp_lcdb_regulator_register(param_1,1);
        if (iVar9 < 0) {
          puVar11 = &DAT_00105a60;
          goto LAB_00102774;
        }
        if ((-1 < *(int *)((long)param_1 + 0x24)) && (*(int *)(param_1 + 3) != 1)) {
          *(undefined4 *)(param_1 + 10) = 0;
          iVar9 = devm_request_threaded_irq
                            (*param_1,*(int *)((long)param_1 + 0x24),0,qpnp_lcdb_sc_irq_handler,
                             0x2000,"qpnp_lcdb_sc_irq",param_1);
          if (iVar9 < 0) {
            _printk(&DAT_00106268,"qpnp_lcdb_hw_init",*(undefined4 *)((long)param_1 + 0x24),iVar9);
            goto LAB_0010279c;
          }
        }
        uVar10 = is_lcdb_enabled(param_1);
        if ((uVar10 & 1) != 0) {
          iVar9 = 0;
          *(undefined1 *)((long)param_1 + 0x4b) = 1;
          goto LAB_0010279c;
        }
        iVar9 = *(int *)((long)param_1 + 0x1c);
        mutex_lock(puVar1);
        uVar20 = iVar9 + 0x45U & 0xffff;
        iVar9 = regmap_bulk_read(param_1[2],uVar20,local_78,1);
        if (-1 < iVar9) {
          mutex_unlock(puVar1);
          if (-1 < local_78[0]) {
            iVar9 = *(int *)((long)param_1 + 0x1c);
            mutex_lock(puVar1);
            uVar20 = iVar9 + 0x45U & 0xffff;
            iVar9 = regmap_update_bits_base(param_1[2],uVar20,0x80,0x80,0,0,0);
            if (iVar9 < 0) {
              _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar20,0x80,iVar9);
              mutex_unlock(puVar1);
              puVar11 = &DAT_0010678d;
              goto LAB_0010278c;
            }
            mutex_unlock(puVar1);
          }
          iVar9 = 0;
          goto LAB_0010279c;
        }
        _printk(&DAT_00107128,"qpnp_lcdb_read",uVar20,iVar9);
        mutex_unlock(puVar1);
        puVar11 = &DAT_00106e39;
      }
    }
  }
LAB_0010278c:
  _printk(puVar11,"qpnp_lcdb_hw_init",iVar9);
LAB_0010279c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// qpnp_lcdb_sc_irq_handler @ 00102868 size=660
// signature: undefined qpnp_lcdb_sc_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_lcdb_sc_irq_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  char *pcVar5;
  uint uVar6;
  byte local_40 [4];
  short local_3c [2];
  long local_38;
  
  lVar4 = sp_el0;
  lVar1 = param_2 + 0x60;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40[0] = 0;
  local_3c[0] = 0;
  mutex_lock(lVar1);
  lVar4 = param_2 + 0x90;
  iVar2 = *(int *)(param_2 + 0x1c);
  mutex_lock(lVar4);
  uVar6 = iVar2 + 0x10U & 0xffff;
  iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 0x10),uVar6,local_40,1);
  if (iVar2 < 0) {
LAB_00102a44:
    _printk(&DAT_00107128,"qpnp_lcdb_read",uVar6,iVar2);
    mutex_unlock(lVar4);
    lVar4 = lVar1;
  }
  else {
    mutex_unlock(lVar4);
    mutex_unlock(lVar1);
    if ((local_40[0] >> 1 & 1) == 0) goto LAB_00102ac8;
    iVar2 = *(int *)(param_2 + 0x1c);
    mutex_lock(lVar4);
    uVar6 = iVar2 + 0x60U & 0xffff;
    iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 0x10),uVar6,local_40,1);
    if (iVar2 < 0) {
      puVar3 = &DAT_00107128;
      pcVar5 = "qpnp_lcdb_read";
    }
    else {
      mutex_unlock(lVar4);
      if ((*(int *)(param_2 + 0x18) != 1) || ((local_40[0] >> 3 & 1) == 0)) {
        usleep_range_state(2000,0x834,2);
        mutex_lock(lVar1);
        iVar2 = *(int *)(param_2 + 0x1c);
        mutex_lock(lVar4);
        uVar6 = iVar2 + 0x10U & 0xffff;
        iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 0x10),uVar6,local_40,1);
        if (iVar2 < 0) goto LAB_00102a44;
        mutex_unlock(lVar4);
        mutex_unlock(lVar1);
        if ((local_40[0] >> 1 & 1) == 0) goto LAB_00102ac8;
LAB_00102990:
        iVar2 = qpnp_lcdb_handle_sc_event(param_2);
        if (iVar2 < 0) {
          _printk(&DAT_00106600,"qpnp_lcdb_sc_irq_handler",iVar2);
        }
        goto LAB_00102ac8;
      }
      usleep_range_state(300,0x136,2);
      iVar2 = *(int *)(param_2 + 0x1c);
      mutex_lock(lVar4);
      uVar6 = iVar2 + 10U & 0xffff;
      iVar2 = regmap_bulk_write(*(undefined8 *)(param_2 + 0x10),uVar6,local_3c,2);
      if (iVar2 < 0) {
        puVar3 = &DAT_00106181;
        pcVar5 = "qpnp_lcdb_write";
      }
      else {
        mutex_unlock(lVar4);
        iVar2 = *(int *)(param_2 + 0x1c);
        mutex_lock(lVar4);
        uVar6 = iVar2 + 10U & 0xffff;
        iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 0x10),uVar6,local_3c,2);
        if (-1 < iVar2) {
          mutex_unlock(lVar4);
          if (((char)local_3c[0] < '\0') && (local_3c[0] < 0)) goto LAB_00102ac8;
          goto LAB_00102990;
        }
        puVar3 = &DAT_00107128;
        pcVar5 = "qpnp_lcdb_read";
      }
    }
    _printk(puVar3,pcVar5,uVar6,iVar2);
  }
  mutex_unlock(lVar4);
LAB_00102ac8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// is_lcdb_enabled @ 00102afc size=232
// signature: undefined is_lcdb_enabled(void)
// callers: [qpnp_lcdb_hw_init]
//------------------------------------------------------------

void is_lcdb_enabled(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  char local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  lVar1 = param_1 + 0x90;
  local_38 = *(long *)(lVar3 + 0x638);
  iVar4 = *(int *)(param_1 + 0x1c);
  local_3c[0] = '\0';
  mutex_lock(lVar1);
  uVar2 = iVar4 + 0x46U & 0xffff;
  iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),uVar2,local_3c,1);
  if (iVar4 < 0) {
    _printk(&DAT_00107128,"qpnp_lcdb_read",uVar2,iVar4);
    mutex_unlock(lVar1);
    _printk(&DAT_00106bb0,"is_lcdb_enabled",iVar4);
  }
  else {
    mutex_unlock(lVar1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar4 == 0 && local_3c[0] < '\0');
  }
  return;
}



//------------------------------------------------------------
// qpnp_lcdb_get_voltage @ 00102be4 size=572
// signature: undefined qpnp_lcdb_get_voltage(void)
// callers: [qpnp_lcdb_ldo_regulator_get_voltage, qpnp_lcdb_hw_init, qpnp_lcdb_ncp_regulator_get_voltage]
//------------------------------------------------------------

int qpnp_lcdb_get_voltage(long param_1,int *param_2,char param_3)

{
  long lVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_50 [4];
  byte local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50[0] = 0;
  iVar4 = 0x71;
  uVar6 = 0x3f;
  if (*(int *)(param_1 + 0x18) != 4) {
    uVar6 = 0x1f;
  }
  if (param_3 == '\x01') {
    iVar4 = 0x81;
    if (*(char *)(param_1 + 0x48) != '\0') {
      iVar4 = 0x71;
    }
LAB_00102cb8:
    lVar1 = param_1 + 0x90;
    iVar5 = *(int *)(param_1 + 0x1c);
    mutex_lock(lVar1);
    uVar2 = iVar5 + iVar4 & 0xffff;
    iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),uVar2,local_50,1);
    if (iVar4 < 0) {
      _printk(&DAT_00107128,"qpnp_lcdb_read",uVar2,iVar4);
      mutex_unlock(lVar1);
      puVar3 = &DAT_00106576;
      if (param_3 != '\0') {
        puVar3 = &DAT_00106484;
      }
      _printk(&DAT_00106851,"qpnp_lcdb_get_voltage",puVar3,iVar4);
      goto LAB_00102d4c;
    }
    mutex_unlock(lVar1);
    uVar6 = local_50[0] & uVar6;
    iVar5 = uVar6 * 100 + 4000;
    if (9 < uVar6) {
      iVar5 = uVar6 * 0x32 + 0x1162;
    }
  }
  else {
    if (param_3 != '\x02') goto LAB_00102cb8;
    lVar1 = param_1 + 0x90;
    iVar4 = *(int *)(param_1 + 0x1c);
    local_4c[0] = 0;
    mutex_lock(lVar1);
    uVar6 = iVar4 + 0x41U & 0xffff;
    iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
    if (iVar4 < 0) {
      _printk(&DAT_00107128,"qpnp_lcdb_read",uVar6,iVar4);
      mutex_unlock(lVar1);
      _printk(&DAT_00106b25,"qpnp_lcdb_get_bst_voltage",iVar4);
      goto LAB_00102d4c;
    }
    mutex_unlock(lVar1);
    if (*(int *)(param_1 + 0x18) == 1) {
      uVar6 = 0x1f;
      iVar7 = 0x32;
LAB_00102d34:
      iVar5 = 0x125c;
    }
    else {
      if (*(int *)(param_1 + 0x18) != 4) {
        uVar6 = 0x3f;
        iVar7 = 0x19;
        goto LAB_00102d34;
      }
      uVar6 = 0xff;
      iVar7 = 0x19;
      iVar5 = 2000;
    }
    iVar4 = 0;
    iVar5 = iVar5 + iVar7 * (local_4c[0] & uVar6);
  }
  *param_2 = iVar5;
LAB_00102d4c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qpnp_lcdb_set_voltage @ 00102e20 size=752
// signature: undefined qpnp_lcdb_set_voltage(void)
// callers: [qpnp_lcdb_enable, qpnp_lcdb_ncp_regulator_set_voltage, qpnp_lcdb_hw_init, qpnp_lcdb_ldo_regulator_set_voltage]
//------------------------------------------------------------

int qpnp_lcdb_set_voltage(long param_1,int param_2,char param_3)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  if (param_2 < *(int *)(param_1 + 0x30) || *(int *)(param_1 + 0x34) < param_2) {
    _printk(&DAT_001067b9,"qpnp_lcdb_set_voltage",param_2);
    return -0x16;
  }
  iVar3 = *(int *)(param_1 + 0x18);
  iVar6 = *(int *)(param_1 + 0x24c);
  if (*(int *)(param_1 + 0x24c) <= *(int *)(param_1 + 0x3b4)) {
    iVar6 = *(int *)(param_1 + 0x3b4);
  }
  if (iVar6 <= param_2) {
    iVar6 = param_2;
  }
  uVar8 = iVar6 + (uint)*(ushort *)(param_1 + 0xe8);
  if ((int)uVar8 < 0x125d) {
    uVar8 = 0x125c;
  }
  if (iVar3 == 4) {
    uVar9 = 0x1900;
  }
  else if (iVar3 == 1) {
    uVar9 = 0x186a;
  }
  else {
    uVar9 = 0x1883;
  }
  if (uVar9 <= uVar8) {
    uVar8 = uVar9;
  }
  if (uVar8 == *(uint *)(param_1 + 0xe4)) goto LAB_00102f54;
  if (iVar3 == 1) {
    uVar9 = 0x32;
    uVar10 = 0x1f;
LAB_00102ef4:
    iVar6 = -0x125c;
  }
  else {
    uVar9 = 0x19;
    if (iVar3 != 4) {
      uVar10 = 0x3f;
      uVar9 = 0x19;
      goto LAB_00102ef4;
    }
    uVar10 = 0xff;
    iVar6 = -2000;
  }
  lVar1 = param_1 + 0x90;
  uVar5 = 0;
  if (uVar9 != 0) {
    uVar5 = ((iVar6 + uVar8 + uVar9) - 1 & 0xffff) / uVar9;
  }
  iVar6 = *(int *)(param_1 + 0x1c);
  mutex_lock(lVar1);
  uVar9 = iVar6 + 0x41U & 0xffff;
  iVar6 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x10),uVar9,uVar10,uVar5,0,0,0);
  if (iVar6 < 0) {
    _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar9,uVar5,iVar6);
    mutex_unlock(lVar1);
    _printk(&DAT_00105e05,"qpnp_lcdb_set_bst_voltage",uVar8,iVar6);
    _printk(&DAT_001055e6,"qpnp_lcdb_set_voltage",iVar6);
    return iVar6;
  }
  mutex_unlock(lVar1);
  *(uint *)(param_1 + 0xe4) = uVar8;
LAB_00102f54:
  if (param_2 < 0x1356) {
    uVar8 = (param_2 + -0xf3d) / 100;
  }
  else {
    uVar8 = (param_2 - 0x1325U) / 0x32 + 10;
  }
  lVar1 = param_1 + 0x90;
  iVar4 = *(int *)(param_1 + 0x1c);
  iVar6 = 0x81;
  if (param_3 != '\x01') {
    iVar6 = 0x71;
  }
  mutex_lock(lVar1);
  uVar9 = iVar4 + iVar6 & 0xffff;
  uVar7 = 0x3f;
  if (iVar3 != 4) {
    uVar7 = 0x1f;
  }
  iVar6 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x10),uVar9,uVar7,uVar8 & 0xff,0,0,0);
  if (iVar6 < 0) {
    _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar9,uVar8 & 0xff,iVar6);
    mutex_unlock(lVar1);
    puVar2 = &DAT_00106576;
    if (param_3 != '\0') {
      puVar2 = &DAT_00106484;
    }
    _printk(&DAT_00105dc8,"qpnp_lcdb_set_voltage",param_2,puVar2,iVar6);
  }
  else {
    mutex_unlock(lVar1);
  }
  return iVar6;
}



//------------------------------------------------------------
// qpnp_lcdb_set_soft_start @ 00103110 size=356
// signature: undefined qpnp_lcdb_set_soft_start(void)
// callers: [qpnp_lcdb_hw_init]
//------------------------------------------------------------

int qpnp_lcdb_set_soft_start(long param_1,uint param_2,char param_3)

{
  long lVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  iVar6 = 0x8f;
  if (param_3 != '\x01') {
    iVar6 = 0x7f;
  }
  if (param_2 < 0x7d1) {
    if (param_2 < 500) {
      uVar8 = 0;
      uVar7 = 500;
    }
    else if (param_2 < 1000) {
      uVar7 = 1000;
      uVar8 = 1;
    }
    else {
      if (1999 < param_2) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103274);
        (*pcVar5)();
      }
      uVar7 = 2000;
      uVar8 = 2;
    }
    lVar1 = param_1 + 0x90;
    iVar4 = *(int *)(param_1 + 0x1c);
    mutex_lock(lVar1);
    uVar2 = iVar4 + iVar6 & 0xffff;
    iVar6 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x10),uVar2,3,uVar8,0,0,0);
    if (iVar6 < 0) {
      _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar2,uVar8,iVar6);
      mutex_unlock(lVar1);
      puVar3 = &DAT_00106576;
      if (param_3 != '\0') {
        puVar3 = &DAT_00106484;
      }
      _printk(&DAT_0010687e,"qpnp_lcdb_set_soft_start",puVar3,uVar7,iVar6);
    }
    else {
      mutex_unlock(lVar1);
    }
  }
  else {
    _printk(&DAT_001069c2,"qpnp_lcdb_set_soft_start",param_2,0,2000);
    iVar6 = -0x16;
  }
  return iVar6;
}



//------------------------------------------------------------
// qpnp_lcdb_regulator_register @ 00103274 size=572
// signature: undefined qpnp_lcdb_regulator_register(void)
// callers: [qpnp_lcdb_hw_init]
//------------------------------------------------------------

ulong qpnp_lcdb_regulator_register(long *param_1,char param_2)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined4 uVar4;
  long *plVar5;
  long lVar6;
  long local_78;
  undefined8 *puStack_70;
  long *local_68;
  long lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  uVar4 = 0;
  if ((int)param_1[3] != 1) {
    uVar4 = 20000;
  }
  if (param_2 == '\0') {
    lVar6 = param_1[0x46];
    plVar5 = param_1 + 0x1e;
    *(undefined4 *)(param_1 + 0x42) = uVar4;
    param_1[0x26] = (long)qpnp_lcdb_ldo_ops;
    *(int *)(param_1 + 0x25) = (*(int *)((long)param_1 + 0x34) - (int)param_1[6]) / 0x32 + 1;
  }
  else {
    plVar5 = param_1 + 0x4b;
    lVar6 = param_1[0x73];
    *(undefined4 *)(param_1 + 0x6f) = uVar4;
    param_1[0x53] = (long)qpnp_lcdb_ncp_ops;
    *(int *)(param_1 + 0x52) = (*(int *)((long)param_1 + 0x34) - (int)param_1[6]) / 0x32 + 1;
  }
  puVar2 = (undefined8 *)of_get_regulator_init_data(*param_1,lVar6,plVar5);
  if (puVar2 == (undefined8 *)0x0) {
    puVar1 = &DAT_00106576;
    if (param_2 != '\0') {
      puVar1 = &DAT_00106484;
    }
    _printk(&DAT_00106efa,"qpnp_lcdb_regulator_register",puVar1);
    uVar3 = 0xfffffff4;
  }
  else if (puVar2[1] == 0) {
    puVar1 = &DAT_00106576;
    if (param_2 != '\0') {
      puVar1 = &DAT_00106484;
    }
    _printk(&DAT_001066f1,"qpnp_lcdb_regulator_register",puVar1);
    uVar3 = 0xffffffea;
  }
  else {
    *(undefined4 *)((long)plVar5 + 0x4c) = 0;
    plVar5[10] = (long)&__this_module;
    local_78 = *param_1;
    *plVar5 = puVar2[1];
    puStack_70 = puVar2;
    local_68 = param_1;
    lStack_60 = lVar6;
    lVar6 = of_get_property(*(undefined8 *)(local_78 + 0x2e8),"parent-supply",0);
    if (lVar6 != 0) {
      *puVar2 = "parent";
    }
    *(uint *)(puVar2 + 8) = *(uint *)(puVar2 + 8) | 9;
    uVar3 = devm_regulator_register(*param_1,plVar5,&local_78);
    if (uVar3 < 0xfffffffffffff001) {
      uVar3 = 0;
    }
    else {
      puVar1 = &DAT_00106576;
      if (param_2 != '\0') {
        puVar1 = &DAT_00106484;
      }
      _printk(&DAT_0010649e,"qpnp_lcdb_regulator_register",puVar1,uVar3 & 0xffffffff);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// qpnp_lcdb_ldo_regulator_set_voltage @ 001034b4 size=264
// signature: undefined qpnp_lcdb_ldo_regulator_set_voltage(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ldo_regulator_set_voltage(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = rdev_get_drvdata();
  *(int *)(lVar3 + 0x24c) = param_2 / 1000;
  if (*(char *)(lVar3 + 0x4e) == '\0') {
    iVar2 = qpnp_lcdb_set_voltage(lVar3,param_2 / 1000,0);
    if (iVar2 < 0) {
LAB_00103578:
      _printk(&DAT_00105681,"qpnp_lcdb_ldo_regulator_set_voltage",iVar2);
      return iVar2;
    }
  }
  else {
    iVar4 = *(int *)(lVar3 + 0x250);
    if (iVar4 + 500 < 0x1965) {
      do {
        iVar1 = iVar4 + 500;
        iVar2 = *(int *)(lVar3 + 0x24c);
        if (iVar1 <= *(int *)(lVar3 + 0x24c)) {
          iVar2 = iVar1;
        }
        iVar2 = qpnp_lcdb_set_voltage(lVar3,iVar2,0);
        if (iVar2 < 0) goto LAB_00103578;
        if (*(int *)(lVar3 + 0x24c) <= iVar1) break;
        usleep_range_state(1000,0x44c,2);
        iVar4 = iVar4 + 500;
      } while (iVar4 < 0x1771);
    }
    else {
      iVar2 = 0;
    }
  }
  *(undefined4 *)(lVar3 + 0x250) = *(undefined4 *)(lVar3 + 0x24c);
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lcdb_ldo_regulator_get_voltage @ 001035c0 size=148
// signature: undefined qpnp_lcdb_ldo_regulator_get_voltage(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ldo_regulator_get_voltage(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar3 = rdev_get_drvdata();
  iVar2 = qpnp_lcdb_get_voltage(uVar3,&local_2c,0);
  if (iVar2 < 0) {
    _printk(&DAT_001068be,"qpnp_lcdb_ldo_regulator_get_voltage",iVar2);
  }
  else {
    iVar2 = local_2c * 1000;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lcdb_ldo_regulator_enable @ 00103658 size=108
// signature: undefined qpnp_lcdb_ldo_regulator_enable(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ldo_regulator_enable(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  mutex_lock(lVar2 + 0x60);
  iVar1 = qpnp_lcdb_enable(lVar2);
  if (iVar1 < 0) {
    _printk(&DAT_00106c3d,"qpnp_lcdb_ldo_regulator_enable",iVar1);
  }
  mutex_unlock(lVar2 + 0x60);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_lcdb_ldo_regulator_disable @ 001036c8 size=108
// signature: undefined qpnp_lcdb_ldo_regulator_disable(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ldo_regulator_disable(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  mutex_lock(lVar2 + 0x60);
  iVar1 = qpnp_lcdb_disable(lVar2);
  if (iVar1 < 0) {
    _printk(&DAT_00105ad6,"qpnp_lcdb_ldo_regulator_disable",iVar1);
  }
  mutex_unlock(lVar2 + 0x60);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_lcdb_ldo_regulator_is_enabled @ 00103738 size=32
// signature: undefined qpnp_lcdb_ldo_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 qpnp_lcdb_ldo_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x4b);
}



//------------------------------------------------------------
// qpnp_lcdb_enable @ 00103758 size=1556
// signature: undefined qpnp_lcdb_enable(void)
// callers: [qpnp_lcdb_ldo_regulator_enable, qpnp_lcdb_handle_sc_event, qpnp_lcdb_ncp_regulator_enable]
//------------------------------------------------------------

int qpnp_lcdb_enable(long param_1)

{
  uint uVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  int iVar10;
  undefined1 *puVar11;
  ulong uVar12;
  byte local_70 [4];
  undefined1 local_6c [4];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  if ((*(char *)(param_1 + 0x4b) == '\0') && (*(char *)(param_1 + 0x4d) == '\0')) {
    if ((*(char *)(param_1 + 0x49) != '\0') && (*(char *)(param_1 + 0x4c) != '\0')) {
      if (*(int *)(param_1 + 0x18) == 1) {
        uVar9 = 0x48;
        lVar6 = 0xc;
        puVar11 = lcdb_settings_pm660l;
      }
      else if (*(int *)(param_1 + 0x18) == 4) {
        uVar9 = 0x6c;
        lVar6 = 0x12;
        puVar11 = (undefined1 *)&lcdb_settings_pm7325b;
      }
      else {
        uVar9 = 0x48;
        lVar6 = 0xc;
        puVar11 = lcdb_settings;
      }
      uVar12 = 0;
      do {
        if ((((((ulong)((int)uVar9 - 8) & 0xff) + 3) / 6) * 6 + 6 == uVar12) ||
           (uVar9 <= uVar12 + 4)) goto LAB_00103d64;
        if (*(char *)((long)puVar11 + uVar12 + 4) != '\0') {
          if (uVar9 < uVar12 + 3) {
LAB_00103d64:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x103d68);
            (*pcVar3)();
          }
          iVar4 = *(int *)(param_1 + 0x1c);
          if (*(char *)((long)puVar11 + uVar12 + 3) == '\0') {
            if (uVar9 <= uVar12) goto LAB_00103d64;
            uVar2 = *(ushort *)((long)puVar11 + uVar12);
            mutex_lock(param_1 + 0x90);
            uVar1 = (uint)uVar2 + iVar4 & 0xffff;
            iVar4 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar1,
                                      (ushort *)((long)puVar11 + uVar12) + 1,1);
            if (iVar4 < 0) {
              _printk(&DAT_00106181,"qpnp_lcdb_write",uVar1,iVar4);
            }
            mutex_unlock(param_1 + 0x90);
          }
          else {
            if ((uVar9 <= uVar12) || (uVar9 <= uVar12 + 2)) goto LAB_00103d64;
            iVar4 = qpnp_lcdb_secure_write
                              (param_1,(uint)*(ushort *)((long)puVar11 + uVar12) + iVar4,
                               *(undefined1 *)((long)puVar11 + uVar12 + 2));
          }
          if (iVar4 < 0) {
            if ((uVar9 <= uVar12) || (uVar9 <= uVar12)) goto LAB_00103d64;
            _printk(&DAT_0010668f,"qpnp_lcdb_restore_settings",
                    *(undefined2 *)((long)puVar11 + uVar12));
            _printk(&DAT_00105a8a,"qpnp_lcdb_ttw_exit",iVar4);
            puVar5 = &DAT_00106d5c;
            goto LAB_00103d50;
          }
        }
        uVar12 = uVar12 + 6;
      } while (lVar6 * 6 != uVar12);
      *(undefined1 *)(param_1 + 0x4c) = 0;
    }
    if (*(int *)(param_1 + 0x18) == 1) {
      lVar6 = param_1 + 0x90;
      iVar4 = *(int *)(param_1 + 0x1c);
      local_6c[0] = 0x80;
      mutex_lock(lVar6);
      uVar1 = iVar4 + 0x46U & 0xffff;
      iVar4 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar1,local_6c,1);
      if (iVar4 < 0) {
        _printk(&DAT_00106181,"qpnp_lcdb_write",uVar1,iVar4);
        mutex_unlock(lVar6);
        puVar5 = &DAT_00105615;
      }
      else {
        mutex_unlock(lVar6);
        iVar4 = *(int *)(param_1 + 0x1c);
        local_6c[0] = 0;
        mutex_lock(lVar6);
        uVar1 = iVar4 + 0x46U & 0xffff;
        iVar4 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar1,local_6c,1);
        if (-1 < iVar4) {
          mutex_unlock(lVar6);
          goto LAB_001039e0;
        }
        _printk(&DAT_00106181,"qpnp_lcdb_write",uVar1,iVar4);
        mutex_unlock(lVar6);
        puVar5 = &DAT_001069f8;
      }
      _printk(puVar5,"qpnp_lcdb_enable_wa",iVar4);
      puVar5 = &DAT_001064d8;
    }
    else {
LAB_001039e0:
      iVar8 = 0x1194;
      if (*(char *)(param_1 + 0x4e) != '\0') {
        iVar7 = *(int *)(param_1 + 0x24c);
        if (0x1193 < iVar7) {
          iVar7 = 0x1194;
        }
        iVar4 = qpnp_lcdb_set_voltage(param_1,iVar7,0);
        if (iVar4 < 0) goto LAB_001037a0;
        iVar8 = *(int *)(param_1 + 0x3b4);
        if (0x1193 < *(int *)(param_1 + 0x3b4)) {
          iVar8 = iVar7;
        }
        iVar4 = qpnp_lcdb_set_voltage(param_1,iVar8,1);
        if (iVar4 < 0) goto LAB_001037a0;
      }
      lVar6 = param_1 + 0x90;
      iVar4 = *(int *)(param_1 + 0x1c);
      local_70[0] = 0x80;
      mutex_lock(lVar6);
      uVar1 = iVar4 + 0x46U & 0xffff;
      iVar4 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar1,local_70,1);
      if (iVar4 < 0) {
        _printk(&DAT_00106181,"qpnp_lcdb_write",uVar1,iVar4);
        mutex_unlock(lVar6);
        _printk(&DAT_001069f8,"qpnp_lcdb_enable",iVar4);
      }
      else {
        mutex_unlock(lVar6);
        iVar10 = 9;
        iVar7 = *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0xdc) +
                *(int *)(param_1 + 0x3ac) + *(int *)(param_1 + 0xe0) +
                *(int *)(param_1 + 0x248) + *(int *)(param_1 + 0x3b0);
        do {
          iVar4 = *(int *)(param_1 + 0x1c);
          mutex_lock(lVar6);
          uVar1 = iVar4 + 0x10U & 0xffff;
          iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),uVar1,local_70,1);
          if (iVar4 < 0) {
            _printk(&DAT_00107128,"qpnp_lcdb_read",uVar1,iVar4);
            mutex_unlock(lVar6);
            _printk(&DAT_00105be6,"qpnp_lcdb_enable",iVar4);
            goto joined_r0x00103cf4;
          }
          mutex_unlock(lVar6);
          if ((local_70[0] & 1) != 0) break;
          usleep_range_state((long)iVar7,(long)(iVar7 + 100),2);
          iVar10 = iVar10 + -1;
        } while (iVar10 != -1);
        if ((iVar4 == 0) && (iVar10 != 0)) {
          *(undefined1 *)(param_1 + 0x4b) = 1;
          if ((*(char *)(param_1 + 0x4e) != '\0') &&
             (usleep_range_state(10000,11000,2), iVar8 + 500 < 0x1965)) {
            do {
              iVar7 = iVar8 + 500;
              iVar10 = *(int *)(param_1 + 0x3b4);
              iVar4 = *(int *)(param_1 + 0x24c);
              if (iVar7 <= *(int *)(param_1 + 0x24c)) {
                iVar4 = iVar7;
              }
              iVar4 = qpnp_lcdb_set_voltage(param_1,iVar4,0);
              if (iVar4 < 0) {
LAB_00103d44:
                puVar5 = &DAT_00106007;
                goto LAB_00103d50;
              }
              if (iVar7 <= iVar10) {
                iVar10 = iVar7;
              }
              iVar4 = qpnp_lcdb_set_voltage(param_1,iVar10,1);
              if (iVar4 < 0) goto LAB_00103d44;
              if ((*(int *)(param_1 + 0x3b4) <= iVar7) && (*(int *)(param_1 + 0x24c) <= iVar7))
              goto LAB_0010379c;
              usleep_range_state(1000,0x44c,2);
              iVar4 = 0;
              iVar8 = iVar8 + 500;
            } while (iVar8 < 0x1771);
            goto LAB_001037a0;
          }
          goto LAB_0010379c;
        }
joined_r0x00103cf4:
        if (iVar10 == 0) {
          _printk(&DAT_0010583c,"qpnp_lcdb_enable");
          iVar4 = -0x6e;
        }
      }
      dump_status_registers(param_1);
      puVar5 = &DAT_00106c3d;
    }
LAB_00103d50:
    _printk(puVar5,"qpnp_lcdb_enable",iVar4);
  }
  else {
LAB_0010379c:
    iVar4 = 0;
  }
LAB_001037a0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qpnp_lcdb_write @ 00103d6c size=152
// signature: undefined qpnp_lcdb_write(void)
// callers: [qpnp_lcdb_disable]
//------------------------------------------------------------

int qpnp_lcdb_write(long param_1,undefined2 param_2,undefined8 param_3,undefined1 param_4)

{
  int iVar1;
  
  mutex_lock(param_1 + 0x90);
  iVar1 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),param_2,param_3,param_4);
  if (iVar1 < 0) {
    _printk(&DAT_00106181,"qpnp_lcdb_write",param_2,iVar1);
  }
  mutex_unlock(param_1 + 0x90);
  return iVar1;
}



//------------------------------------------------------------
// dump_status_registers @ 00103e04 size=432
// signature: undefined dump_status_registers(void)
// callers: [qpnp_lcdb_enable]
//------------------------------------------------------------

void dump_status_registers(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 local_50;
  undefined2 local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x90;
  local_48 = *(long *)(lVar6 + 0x638);
  iVar4 = *(int *)(param_1 + 0x18);
  iVar5 = *(int *)(param_1 + 0x1c);
  local_4c = 0;
  local_50 = 0;
  mutex_lock(lVar1);
  uVar2 = iVar5 + 8U & 0xffff;
  uVar3 = 5;
  if (iVar4 != 4) {
    uVar3 = 6;
  }
  uVar7 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar2,&local_50,uVar3);
  if ((int)uVar7 < 0) {
    _printk(&DAT_00106181,"qpnp_lcdb_write",uVar2,uVar7);
    mutex_unlock(lVar1);
    puVar8 = &DAT_001056ae;
  }
  else {
    mutex_unlock(lVar1);
    iVar4 = *(int *)(param_1 + 0x1c);
    mutex_lock(lVar1);
    uVar2 = iVar4 + 8U & 0xffff;
    uVar7 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),uVar2,&local_50,uVar3);
    if ((int)uVar7 < 0) {
      _printk(&DAT_00107128,"qpnp_lcdb_read",uVar2,uVar7);
      mutex_unlock(lVar1);
      puVar8 = &DAT_0010604b;
    }
    else {
      mutex_unlock(lVar1);
      _printk(&DAT_001070df,"dump_status_registers",(undefined1)local_50,local_50._1_1_,
              local_50._2_1_,local_50._3_1_,(undefined1)local_4c);
      if (*(int *)(param_1 + 0x18) == 4) goto LAB_00103f68;
      uVar7 = (uint)local_4c._1_1_;
      puVar8 = &DAT_00105abd;
    }
  }
  _printk(puVar8,"dump_status_registers",uVar7);
LAB_00103f68:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qpnp_lcdb_secure_write @ 00103fb4 size=212
// signature: undefined qpnp_lcdb_secure_write(void)
// callers: [qpnp_lcdb_enable, qpnp_lcdb_disable]
//------------------------------------------------------------

int qpnp_lcdb_secure_write(long param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  
  mutex_lock(param_1 + 0x90);
  if ((*(int *)(param_1 + 0x18) == 1) &&
     (iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x10),*(int *)(param_1 + 0x1c) + 0xd0,0xa5),
     iVar1 < 0)) {
    _printk(&DAT_00106298,"qpnp_lcdb_secure_write",iVar1);
  }
  else {
    iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x10),param_2,param_3);
    if (iVar1 < 0) {
      _printk(&DAT_00106181,"qpnp_lcdb_secure_write",param_2,iVar1);
    }
  }
  mutex_unlock(param_1 + 0x90);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_lcdb_disable @ 00104088 size=3272
// signature: undefined qpnp_lcdb_disable(void)
// callers: [qpnp_lcdb_ncp_regulator_disable, qpnp_lcdb_ldo_regulator_disable, qpnp_lcdb_handle_sc_event]
//------------------------------------------------------------

int qpnp_lcdb_disable(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58[0] = 0;
  if (*(char *)(param_1 + 0x4b) == '\0') {
    iVar3 = 0;
    goto LAB_001049dc;
  }
  if (*(char *)(param_1 + 0x49) != '\0') {
    if (*(int *)(param_1 + 0x18) == 4) {
      if (*(char *)(param_1 + 0x4c) == '\0') {
        iVar3 = qpnp_lcdb_save_settings(param_1);
        if (iVar3 < 0) {
          puVar4 = &DAT_00106079;
          pcVar5 = "qpnp_lcdb_ttw_enter_pm7325b";
          goto LAB_00104cf4;
        }
        *(undefined1 *)(param_1 + 0x4c) = 1;
      }
      lVar1 = param_1 + 0x90;
      iVar3 = *(int *)(param_1 + 0x1c);
      local_50[0] = 0;
      mutex_lock(lVar1);
      uVar6 = iVar3 + 0x47U & 0xffff;
      iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
      if (-1 < iVar3) {
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_50[0] = 0;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x56U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
        if (-1 < iVar3) {
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_50[0] = 0;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x5cU & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
          if (-1 < iVar3) {
            mutex_unlock(lVar1);
            iVar3 = *(int *)(param_1 + 0x1c);
            local_50[0] = 0;
            mutex_lock(lVar1);
            uVar6 = iVar3 + 0x5dU & 0xffff;
            iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
            if (-1 < iVar3) {
              mutex_unlock(lVar1);
              iVar3 = *(int *)(param_1 + 0x1c);
              local_50[0] = 0;
              mutex_lock(lVar1);
              uVar6 = iVar3 + 0x5eU & 0xffff;
              iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
              if (-1 < iVar3) {
                mutex_unlock(lVar1);
                iVar3 = *(int *)(param_1 + 0x1c);
                local_50[0] = 0;
                mutex_lock(lVar1);
                uVar6 = iVar3 + 0x5bU & 0xffff;
                iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
                if (-1 < iVar3) {
                  mutex_unlock(lVar1);
                  iVar3 = *(int *)(param_1 + 0x1c);
                  local_50[0] = 0;
                  mutex_lock(lVar1);
                  uVar6 = iVar3 + 0x77U & 0xffff;
                  iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
                  if (-1 < iVar3) {
                    mutex_unlock(lVar1);
                    iVar3 = *(int *)(param_1 + 0x1c);
                    local_50[0] = 0;
                    mutex_lock(lVar1);
                    uVar6 = iVar3 + 0x7fU & 0xffff;
                    iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
                    if (-1 < iVar3) {
                      mutex_unlock(lVar1);
                      iVar3 = *(int *)(param_1 + 0x1c);
                      local_50[0] = 0;
                      mutex_lock(lVar1);
                      uVar6 = iVar3 + 0x87U & 0xffff;
                      iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
                      if (-1 < iVar3) {
                        mutex_unlock(lVar1);
                        iVar3 = *(int *)(param_1 + 0x1c);
                        local_50[0] = 0;
                        mutex_lock(lVar1);
                        uVar6 = iVar3 + 0x8fU & 0xffff;
                        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1);
                        if (-1 < iVar3) {
                          mutex_unlock(lVar1);
                          iVar3 = *(int *)(param_1 + 0x1c);
                          local_50[0] = 4;
                          mutex_lock(lVar1);
                          uVar6 = iVar3 + 0x42U & 0xffff;
                          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50,1
                                                   );
                          if (-1 < iVar3) {
                            mutex_unlock(lVar1);
                            iVar3 = *(int *)(param_1 + 0x1c);
                            local_50[0] = 0x80;
                            mutex_lock(lVar1);
                            uVar6 = iVar3 + 0x43U & 0xffff;
                            iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_50
                                                      ,1);
                            if (-1 < iVar3) {
                              mutex_unlock(lVar1);
                              local_50[0] = 0x40;
                              iVar3 = qpnp_lcdb_write(param_1,*(ushort *)(param_1 + 0x1c) + 0x46,
                                                      local_50,1);
                              goto joined_r0x00104778;
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
        }
      }
LAB_001049ac:
      _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
LAB_001049c8:
      mutex_unlock(param_1 + 0x90);
    }
    else {
      if (*(int *)(param_1 + 0x18) != 1) {
        if (*(char *)(param_1 + 0x4c) == '\0') {
          iVar3 = qpnp_lcdb_save_settings(param_1);
          if (iVar3 < 0) {
            puVar4 = &DAT_00106079;
            pcVar5 = "qpnp_lcdb_ttw_enter";
            goto LAB_00104cf4;
          }
          *(undefined1 *)(param_1 + 0x4c) = 1;
        }
        lVar1 = param_1 + 0x90;
        iVar3 = *(int *)(param_1 + 0x1c);
        local_4c[0] = 0x44;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x5bU & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
        if (-1 < iVar3) {
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 0;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x8fU & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 0;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x7fU & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 0;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x66U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 0;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x55U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 2;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x47U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 2;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x77U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 2;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x87U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          mutex_unlock(lVar1);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_4c[0] = 0x40;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x46U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_4c,1);
          if (iVar3 < 0) goto LAB_001049ac;
          goto LAB_001049c8;
        }
        goto LAB_001049ac;
      }
      if (*(char *)(param_1 + 0x4c) != '\0') {
LAB_001040f8:
        lVar1 = param_1 + 0x90;
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 2;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x47U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00106b53;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 5;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x53U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_001061b3;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 0x19;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x60U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00105e3a;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 0;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x5fU & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00105f55;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 0x95;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x62U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00105c36;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        local_54[0] = 0;
        iVar3 = qpnp_lcdb_secure_write(param_1,*(ushort *)(param_1 + 0x1c) + 0x66,0);
        if (iVar3 < 0) {
          puVar4 = &DAT_0010563f;
          goto LAB_00104cec;
        }
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 2;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x77U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00106e66;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 0;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x7fU & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_0010586e;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 2;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x87U & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_0010589e;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        iVar3 = *(int *)(param_1 + 0x1c);
        local_54[0] = 0;
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x8fU & 0xffff;
        iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00105786;
          goto LAB_00104cec;
        }
        mutex_unlock(lVar1);
        if (*(char *)(param_1 + 0x4a) == '\0') {
          iVar3 = *(int *)(param_1 + 0x1c);
          local_54[0] = 0x40;
          mutex_lock(lVar1);
          uVar6 = iVar3 + 0x46U & 0xffff;
          iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_54,1);
          if (-1 < iVar3) goto LAB_001049c8;
          _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00106d87;
          goto LAB_00104cec;
        }
        iVar3 = *(int *)(param_1 + 0x1c);
        mutex_lock(lVar1);
        uVar6 = iVar3 + 0x40U & 0xffff;
        iVar3 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x10),uVar6,0x80,0x80,0,0,0);
        if (iVar3 < 0) {
          _printk(&DAT_00106a7c,"qpnp_lcdb_masked_write",uVar6,0x80,iVar3);
          mutex_unlock(lVar1);
          puVar4 = &DAT_00106f30;
          goto LAB_00104cec;
        }
        goto LAB_001049c8;
      }
      iVar3 = qpnp_lcdb_save_settings(param_1);
      if (-1 < iVar3) {
        *(undefined1 *)(param_1 + 0x4c) = 1;
        goto LAB_001040f8;
      }
      puVar4 = &DAT_00106079;
LAB_00104cec:
      pcVar5 = "qpnp_lcdb_ttw_enter_pm660l";
LAB_00104cf4:
      _printk(puVar4,pcVar5,iVar3);
    }
joined_r0x00104778:
    if (iVar3 < 0) {
      _printk(&DAT_00106c7a,"qpnp_lcdb_disable",iVar3);
    }
    else {
      iVar3 = 0;
      *(undefined1 *)(param_1 + 0x4b) = 0;
    }
    goto LAB_001049dc;
  }
  if ((*(byte *)(param_1 + 0x20) >> 1 & 1) == 0) {
LAB_001043f0:
    lVar1 = param_1 + 0x90;
    iVar3 = *(int *)(param_1 + 0x1c);
    local_58[0] = 0;
    mutex_lock(lVar1);
    uVar6 = iVar3 + 0x46U & 0xffff;
    iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_58,1);
    if (iVar3 < 0) {
      _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
      mutex_unlock(lVar1);
      _printk(&DAT_001069f8,"qpnp_lcdb_disable",iVar3);
      bVar2 = *(byte *)(param_1 + 0x20);
    }
    else {
      mutex_unlock(lVar1);
      *(undefined1 *)(param_1 + 0x4b) = 0;
      bVar2 = *(byte *)(param_1 + 0x20);
    }
    if ((bVar2 >> 1 & 1) == 0) goto LAB_001049dc;
    usleep_range_state(10000,11000,2);
    iVar3 = *(int *)(param_1 + 0x1c);
    local_58[0] = 0;
    mutex_lock(lVar1);
    uVar6 = iVar3 + 0x79U & 0xffff;
    iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_58,1);
    if (iVar3 < 0) goto LAB_00104b58;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1c);
    local_58[0] = 0x81;
    mutex_lock(param_1 + 0x90);
    uVar6 = iVar3 + 0x79U & 0xffff;
    iVar3 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x10),uVar6,local_58,1);
    if (-1 < iVar3) {
      mutex_unlock(param_1 + 0x90);
      goto LAB_001043f0;
    }
LAB_00104b58:
    _printk(&DAT_00106181,"qpnp_lcdb_write",uVar6,iVar3);
  }
  mutex_unlock(param_1 + 0x90);
LAB_001049dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qpnp_lcdb_save_settings @ 00104d50 size=348
// signature: undefined qpnp_lcdb_save_settings(void)
// callers: [qpnp_lcdb_disable]
//------------------------------------------------------------

int qpnp_lcdb_save_settings(long param_1)

{
  long lVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined1 *puVar7;
  ulong uVar8;
  
  if (*(int *)(param_1 + 0x18) == 1) {
    uVar6 = 0x48;
    lVar5 = 0xc;
    puVar7 = lcdb_settings_pm660l;
  }
  else if (*(int *)(param_1 + 0x18) == 4) {
    uVar6 = 0x6c;
    lVar5 = 0x12;
    puVar7 = (undefined1 *)&lcdb_settings_pm7325b;
  }
  else {
    uVar6 = 0x48;
    lVar5 = 0xc;
    puVar7 = lcdb_settings;
  }
  uVar8 = 0;
  lVar1 = param_1 + 0x90;
  do {
    if (uVar6 <= uVar8 + 4) goto LAB_00104ea8;
    if (*(char *)((long)puVar7 + uVar8 + 4) != '\0') {
      if (uVar6 <= uVar8) {
LAB_00104ea8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x104eac);
        (*pcVar3)();
      }
      sVar2 = *(short *)((long)puVar7 + uVar8) + *(short *)(param_1 + 0x1c);
      mutex_lock(lVar1);
      iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 0x10),sVar2,
                               (short *)((long)puVar7 + uVar8) + 1,1);
      if (iVar4 < 0) {
        _printk(&DAT_00107128,"qpnp_lcdb_read",sVar2,iVar4);
        mutex_unlock(lVar1);
        if (uVar8 < uVar6) {
          _printk(&DAT_00106e92,"qpnp_lcdb_save_settings",*(undefined2 *)((long)puVar7 + uVar8));
          return iVar4;
        }
        goto LAB_00104ea8;
      }
      mutex_unlock(lVar1);
    }
    uVar8 = uVar8 + 6;
    if (lVar5 * 6 == uVar8) {
      return 0;
    }
  } while( true );
}



//------------------------------------------------------------
// qpnp_lcdb_ncp_regulator_set_voltage @ 00104eb0 size=264
// signature: undefined qpnp_lcdb_ncp_regulator_set_voltage(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ncp_regulator_set_voltage(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = rdev_get_drvdata();
  *(int *)(lVar3 + 0x3b4) = param_2 / 1000;
  if (*(char *)(lVar3 + 0x4e) == '\0') {
    iVar2 = qpnp_lcdb_set_voltage(lVar3,param_2 / 1000,1);
    if (iVar2 < 0) {
LAB_00104f74:
      _printk(&DAT_001061df,"qpnp_lcdb_ncp_regulator_set_voltage",iVar2);
      return iVar2;
    }
  }
  else {
    iVar4 = *(int *)(lVar3 + 0x3b8);
    if (iVar4 + 500 < 0x1965) {
      do {
        iVar1 = iVar4 + 500;
        iVar2 = *(int *)(lVar3 + 0x3b4);
        if (iVar1 <= *(int *)(lVar3 + 0x3b4)) {
          iVar2 = iVar1;
        }
        iVar2 = qpnp_lcdb_set_voltage(lVar3,iVar2,1);
        if (iVar2 < 0) goto LAB_00104f74;
        if (*(int *)(lVar3 + 0x3b4) <= iVar1) break;
        usleep_range_state(1000,0x44c,2);
        iVar4 = iVar4 + 500;
      } while (iVar4 < 0x1771);
    }
    else {
      iVar2 = 0;
    }
  }
  *(undefined4 *)(lVar3 + 0x3b8) = *(undefined4 *)(lVar3 + 0x3b4);
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lcdb_ncp_regulator_get_voltage @ 00104fbc size=148
// signature: undefined qpnp_lcdb_ncp_regulator_get_voltage(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ncp_regulator_get_voltage(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar3 = rdev_get_drvdata();
  iVar2 = qpnp_lcdb_get_voltage(uVar3,&local_2c,1);
  if (iVar2 < 0) {
    _printk(&DAT_001063f0,"qpnp_lcdb_ncp_regulator_get_voltage",iVar2);
  }
  else {
    iVar2 = local_2c * 1000;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lcdb_ncp_regulator_enable @ 00105054 size=108
// signature: undefined qpnp_lcdb_ncp_regulator_enable(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ncp_regulator_enable(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  mutex_lock(lVar2 + 0x60);
  iVar1 = qpnp_lcdb_enable(lVar2);
  if (iVar1 < 0) {
    _printk(&DAT_00106c3d,"qpnp_lcdb_ncp_regulator_enable",iVar1);
  }
  mutex_unlock(lVar2 + 0x60);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_lcdb_ncp_regulator_disable @ 001050c4 size=108
// signature: undefined qpnp_lcdb_ncp_regulator_disable(void)
// callers: []
//------------------------------------------------------------

int qpnp_lcdb_ncp_regulator_disable(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  mutex_lock(lVar2 + 0x60);
  iVar1 = qpnp_lcdb_disable(lVar2);
  if (iVar1 < 0) {
    _printk(&DAT_00105ad6,"qpnp_lcdb_ncp_regulator_disable",iVar1);
  }
  mutex_unlock(lVar2 + 0x60);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_lcdb_ncp_regulator_is_enabled @ 00105134 size=32
// signature: undefined qpnp_lcdb_ncp_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 qpnp_lcdb_ncp_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x4b);
}



//------------------------------------------------------------
// qpnp_lcdb_handle_sc_event @ 00105154 size=252
// signature: undefined qpnp_lcdb_handle_sc_event(void)
// callers: [qpnp_lcdb_sc_irq_handler]
//------------------------------------------------------------

int qpnp_lcdb_handle_sc_event(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  int iVar5;
  
  mutex_lock(param_1 + 0x60);
  iVar1 = qpnp_lcdb_disable(param_1);
  if (iVar1 < 0) {
    puVar4 = &DAT_00105ad6;
  }
  else {
    lVar2 = ktime_get();
    if (lVar2 - *(long *)(param_1 + 0x58) < 0x3b9acde8) {
      iVar5 = *(int *)(param_1 + 0x50);
      if (10 < iVar5) {
        _printk(&DAT_00105fa6,"qpnp_lcdb_handle_sc_event");
        *(undefined1 *)(param_1 + 0x4d) = 1;
        goto LAB_001051e8;
      }
    }
    else {
      iVar5 = 0;
    }
    *(int *)(param_1 + 0x50) = iVar5 + 1;
    uVar3 = ktime_get();
    *(undefined8 *)(param_1 + 0x58) = uVar3;
    usleep_range_state(10000,0x2774,2);
    iVar1 = qpnp_lcdb_enable(param_1);
    if (-1 < iVar1) goto LAB_001051e8;
    puVar4 = &DAT_00106c3d;
  }
  _printk(puVar4,"qpnp_lcdb_handle_sc_event",iVar1);
LAB_001051e8:
  mutex_unlock(param_1 + 0x60);
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00105254 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_lcdb_regulator_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105284 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_lcdb_regulator_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00109000 size=1
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
// platform_driver_unregister @ 00109008 size=1
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
// devm_kmalloc @ 00109010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109018 size=1
// signature: undefined _printk(void)
// callers: [qpnp_lcdb_ldo_regulator_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_ldo_regulator_get_voltage, qpnp_lcdb_ncp_regulator_set_voltage, qpnp_lcdb_hw_init, dump_status_registers, qpnp_lcdb_secure_write, qpnp_lcdb_ldo_regulator_disable, qpnp_lcdb_handle_sc_event, qpnp_lcdb_regulator_probe, qpnp_lcdb_disable, qpnp_lcdb_ncp_regulator_get_voltage, is_lcdb_enabled, qpnp_lcdb_save_settings, qpnp_lcdb_regulator_register, qpnp_lcdb_enable, qpnp_lcdb_set_soft_start, qpnp_lcdb_ncp_regulator_disable, qpnp_lcdb_get_voltage, qpnp_lcdb_write, qpnp_lcdb_ldo_regulator_set_voltage, qpnp_lcdb_ncp_regulator_enable, qpnp_lcdb_parse_dt, qpnp_lcdb_set_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00109020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_lcdb_regulator_probe, qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00109028 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00109030 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 00109038 size=1
// signature: undefined of_match_device(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00109040 size=1
// signature: undefined __mutex_init(void)
// callers: [qpnp_lcdb_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00109048 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00109050 size=1
// signature: undefined of_property_read_string(void)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00109058 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u16_array @ 00109060 size=1
// signature: undefined of_property_read_variable_u16_array(void)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u16_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00109068 size=1
// signature: undefined of_find_property(void)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109070 size=1
// signature: undefined mutex_lock(void)
// callers: [qpnp_lcdb_ldo_regulator_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_hw_init, dump_status_registers, qpnp_lcdb_secure_write, qpnp_lcdb_ldo_regulator_disable, qpnp_lcdb_handle_sc_event, qpnp_lcdb_disable, is_lcdb_enabled, qpnp_lcdb_save_settings, qpnp_lcdb_enable, qpnp_lcdb_set_soft_start, qpnp_lcdb_ncp_regulator_disable, qpnp_lcdb_get_voltage, qpnp_lcdb_write, qpnp_lcdb_ncp_regulator_enable, qpnp_lcdb_parse_dt, qpnp_lcdb_set_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00109078 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qpnp_lcdb_set_soft_start, qpnp_lcdb_hw_init, qpnp_lcdb_disable, qpnp_lcdb_parse_dt, qpnp_lcdb_set_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109080 size=1
// signature: undefined mutex_unlock(void)
// callers: [qpnp_lcdb_ldo_regulator_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_hw_init, dump_status_registers, qpnp_lcdb_secure_write, qpnp_lcdb_ldo_regulator_disable, qpnp_lcdb_handle_sc_event, qpnp_lcdb_disable, is_lcdb_enabled, qpnp_lcdb_save_settings, qpnp_lcdb_enable, qpnp_lcdb_set_soft_start, qpnp_lcdb_ncp_regulator_disable, qpnp_lcdb_get_voltage, qpnp_lcdb_write, qpnp_lcdb_ncp_regulator_enable, qpnp_lcdb_parse_dt, qpnp_lcdb_set_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00109088 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [qpnp_lcdb_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qpnp_lcdb_regulator_register, qpnp_lcdb_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_ldo_regulator_get_voltage, qpnp_lcdb_hw_init, qpnp_lcdb_get_voltage, dump_status_registers, qpnp_lcdb_disable, qpnp_lcdb_parse_dt, qpnp_lcdb_ncp_regulator_get_voltage, is_lcdb_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00109098 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [qpnp_lcdb_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_hw_init, qpnp_lcdb_get_voltage, dump_status_registers, is_lcdb_enabled, qpnp_lcdb_save_settings]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001090a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qpnp_lcdb_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001090a8 size=1
// signature: undefined usleep_range_state(void)
// callers: [qpnp_lcdb_enable, qpnp_lcdb_sc_irq_handler, qpnp_lcdb_ncp_regulator_set_voltage, qpnp_lcdb_handle_sc_event, qpnp_lcdb_ldo_regulator_set_voltage, qpnp_lcdb_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 001090b0 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [qpnp_lcdb_enable, qpnp_lcdb_sc_irq_handler, dump_status_registers, qpnp_lcdb_write, qpnp_lcdb_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 001090b8 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [qpnp_lcdb_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001090c0 size=1
// signature: undefined of_get_property(void)
// callers: [qpnp_lcdb_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 001090c8 size=1
// signature: undefined devm_regulator_register(void)
// callers: [qpnp_lcdb_regulator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 001090d0 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [qpnp_lcdb_ldo_regulator_enable, qpnp_lcdb_ldo_regulator_get_voltage, qpnp_lcdb_ncp_regulator_set_voltage, qpnp_lcdb_ncp_regulator_disable, qpnp_lcdb_ldo_regulator_disable, qpnp_lcdb_ldo_regulator_set_voltage, qpnp_lcdb_ldo_regulator_is_enabled, qpnp_lcdb_ncp_regulator_enable, qpnp_lcdb_ncp_regulator_get_voltage, qpnp_lcdb_ncp_regulator_is_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001090d8 size=1
// signature: undefined regmap_write(void)
// callers: [qpnp_lcdb_secure_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001090e0 size=1
// signature: undefined ktime_get(void)
// callers: [qpnp_lcdb_handle_sc_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



