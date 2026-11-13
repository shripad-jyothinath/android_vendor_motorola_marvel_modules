// Decompiled by Ghidra 12.2
// Program: rpmh-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 0010043c size=72
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  rpmh_reg_ipc_log = ipc_log_context_create(10,"rpmh_regulator",0);
  __platform_driver_register(&rpmh_regulator_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100488 size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (rpmh_reg_ipc_log != 0) {
    ipc_log_context_destroy();
  }
  platform_driver_unregister(&rpmh_regulator_driver);
  return;
}



//------------------------------------------------------------
// rpmh_regulator_probe @ 001004c0 size=5584
// signature: undefined rpmh_regulator_probe(void)
// callers: []
//------------------------------------------------------------

ulong rpmh_regulator_probe(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  uint uVar6;
  byte bVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  code *pcVar10;
  uint uVar11;
  int iVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  void *__dest;
  char *pcVar16;
  size_t sVar17;
  undefined *puVar18;
  uint *puVar19;
  undefined8 uVar20;
  long lVar21;
  uint uVar22;
  undefined4 uVar23;
  long lVar24;
  long lVar25;
  int *piVar26;
  long lVar27;
  long lVar28;
  long lVar29;
  int *piVar30;
  long *plVar31;
  long lVar32;
  char *pcVar33;
  undefined8 *puVar34;
  byte *pbVar35;
  uint local_a4;
  char *local_a0;
  long lStack_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  uint local_6c;
  long local_68;
  
  lVar32 = sp_el0;
  lVar21 = param_1 + 0x10;
  local_68 = *(long *)(lVar32 + 0x638);
  lVar32 = *(long *)(param_1 + 0x2f8);
  if (lVar32 == 0) {
    _dev_err(lVar21,"Device tree node is missing\n");
    pbVar35 = (byte *)0xffffffea;
    goto LAB_00101a4c;
  }
  plVar13 = (long *)devm_kmalloc(lVar21,0xe0,0xdc0);
  if (plVar13 == (long *)0x0) {
    pbVar35 = (byte *)0xfffffff4;
    goto LAB_00101a4c;
  }
  plVar31 = plVar13 + 3;
  *plVar13 = lVar21;
  __mutex_init(plVar31,"&aggr_vreg->lock",&rpmh_regulator_probe___key);
  lVar14 = of_match_node(&rpmh_regulator_match_table,lVar32);
  if (lVar14 == 0) {
    _dev_err(lVar21,"could not find compatible string match\n");
    pbVar35 = (byte *)0xffffffed;
    goto LAB_00101a4c;
  }
  plVar1 = plVar13 + 1;
  *(int *)(plVar13 + 9) = (int)*(undefined8 *)(lVar14 + 0xc0);
  uVar11 = of_property_read_string(lVar32,"qcom,resource-name",plVar1);
  if (uVar11 != 0) {
    pbVar35 = (byte *)(ulong)uVar11;
    _dev_err(lVar21,"qcom,resource-name missing in DT node\n");
    goto LAB_00101a4c;
  }
  iVar12 = cmd_db_read_addr(plVar13[1]);
  *(int *)(plVar13 + 2) = iVar12;
  if (iVar12 == 0) {
    _printk(&DAT_00103e34,"rpmh_regulator_probe");
    pbVar35 = (byte *)0xffffffed;
    goto LAB_00101a4c;
  }
  uVar15 = cmd_db_read_slave_id(plVar13[1]);
  pbVar35 = (byte *)(uVar15 & 0xffffffff);
  iVar12 = (int)uVar15;
  if (iVar12 < 0) {
    lVar21 = *plVar1;
    puVar18 = &DAT_001043b7;
LAB_00101994:
    _printk(puVar18,"rpmh_regulator_probe",lVar21,(ulong)pbVar35 & 0xffffffff);
LAB_00101a4c:
    lVar21 = sp_el0;
    if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return (ulong)pbVar35 & 0xffffffff;
  }
  uVar11 = *(uint *)(plVar13 + 9);
  if (((uVar11 == 1) && (iVar12 != 3)) ||
     (((uVar11 & 0xfffffffe) == 2 || uVar11 == 0 && (iVar12 != 4)))) {
    puVar18 = &DAT_0010422a;
    if (uVar11 != 0) {
      puVar18 = &DAT_00103fea;
    }
    puVar5 = &DAT_00104712;
    if (uVar11 != 1) {
      puVar5 = puVar18;
    }
    _printk(&DAT_00103ec9,"rpmh_regulator_probe",*plVar1,uVar11,puVar5,pbVar35);
    pbVar35 = (byte *)0xffffffea;
    goto LAB_00101a4c;
  }
  if (uVar11 == 1) {
    local_a0 = (char *)0x0;
    pbVar35 = (byte *)cmd_db_read_aux_data(*plVar1,&local_a0);
    if (pbVar35 < (byte *)0xfffffffffffff001) {
      if (local_a0 == (char *)0x0) {
        _printk(&DAT_00103bea,"rpmh_regulator_load_arc_level_mapping",*plVar1);
      }
      else if (local_a0 < (char *)0x21) {
        if (((ulong)local_a0 & 1) == 0) {
          iVar12 = (int)((ulong)local_a0 >> 1);
          *(int *)(plVar13 + 0x12) = iVar12;
          if (iVar12 != 0) {
            uVar11 = *(uint *)(plVar13 + 10);
            bVar7 = *pbVar35;
            *(uint *)(plVar13 + 10) = uVar11 | bVar7;
            *(uint *)(plVar13 + 10) = uVar11 | bVar7 | (uint)pbVar35[1] << 8;
            if (((ulong)local_a0 & 0x1fffffffc) != 0) {
              pbVar35 = pbVar35 + 3;
              lVar14 = 0;
              do {
                if (lVar14 == 0xf) goto LAB_00101a88;
                lVar28 = lVar14 * 4;
                uVar11 = *(uint *)((long)plVar13 + lVar28 + 0x54) | (uint)pbVar35[-1];
                *(uint *)((long)plVar13 + lVar28 + 0x54) = uVar11;
                uVar11 = uVar11 | (uint)*pbVar35 << 8;
                *(uint *)((long)plVar13 + lVar28 + 0x54) = uVar11;
                if (uVar11 == 0) {
                  *(int *)(plVar13 + 0x12) = (int)lVar14 + 1;
                  break;
                }
                lVar28 = lVar14 + 2;
                pbVar35 = pbVar35 + 2;
                lVar14 = lVar14 + 1;
              } while (lVar28 < (int)plVar13[0x12]);
            }
          }
          goto LAB_00100694;
        }
        _printk(&DAT_0010402b,"rpmh_regulator_load_arc_level_mapping",*plVar1);
      }
      else {
        _printk(&DAT_001041b3,"rpmh_regulator_load_arc_level_mapping",*plVar1,local_a0,0x20);
      }
      pbVar35 = (byte *)0xffffffea;
    }
    else {
      _printk(&DAT_00103f08,"rpmh_regulator_load_arc_level_mapping",*plVar1,pbVar35);
      if ((int)pbVar35 == 0) goto LAB_00100694;
    }
    lVar21 = *plVar1;
    puVar18 = &DAT_00103b50;
    goto LAB_00101994;
  }
  if (uVar11 == 0) {
    uVar20 = *(undefined8 *)(*plVar13 + 0x2e8);
    local_6c = 0;
    local_a0 = "";
    local_a4 = 0;
    *(undefined4 *)((long)plVar13 + 0x4c) = 0;
    *(undefined4 *)((long)plVar13 + 0xb4) = 0xffffffea;
    lVar14 = of_find_property(uVar20,"qcom,regulator-type",&local_6c);
    if (lVar14 != 0) {
      uVar11 = of_property_read_string(uVar20,"qcom,regulator-type",&local_a0);
      pcVar33 = local_a0;
      if (uVar11 == 0) {
        iVar12 = strcmp(local_a0,"pmic4-ldo");
        if (iVar12 == 0) {
          lVar14 = 1;
        }
        else {
          iVar12 = strcmp(pcVar33,"pmic4-hfsmps");
          if (iVar12 == 0) {
            lVar14 = 2;
          }
          else {
            iVar12 = strcmp(pcVar33,"pmic4-ftsmps");
            if (iVar12 == 0) {
              lVar14 = 3;
            }
            else {
              iVar12 = strcmp(pcVar33,"pmic4-bob");
              if (iVar12 == 0) {
                lVar14 = 4;
              }
              else {
                iVar12 = strcmp(pcVar33,"pmic5-ldo");
                if (iVar12 == 0) {
                  lVar14 = 5;
                }
                else {
                  iVar12 = strcmp(pcVar33,"pmic5-hfsmps");
                  if (iVar12 == 0) {
                    lVar14 = 6;
                  }
                  else {
                    iVar12 = strcmp(pcVar33,"pmic5-ftsmps");
                    if (iVar12 == 0) {
                      lVar14 = 7;
                    }
                    else {
                      iVar12 = strcmp(pcVar33,"pmic5-bob");
                      if (iVar12 == 0) {
                        lVar14 = 8;
                      }
                      else {
                        iVar12 = strcmp(pcVar33,"pmic7-ldo");
                        if (iVar12 == 0) {
                          lVar14 = 9;
                        }
                        else {
                          iVar12 = strcmp(pcVar33,"pmic7-hfsmps");
                          if (iVar12 == 0) {
                            lVar14 = 10;
                          }
                          else {
                            iVar12 = strcmp(pcVar33,"pmic7-ftsmps");
                            if (iVar12 == 0) {
                              lVar14 = 0xb;
                            }
                            else {
                              iVar12 = strcmp(pcVar33,"pmic7-bob");
                              if (iVar12 != 0) {
                                _printk(&DAT_00103c22,"rpmh_regulator_parse_hw_type",*plVar1,pcVar33
                                       );
                                pbVar35 = (byte *)0xffffffea;
                                goto LAB_00101988;
                              }
                              lVar14 = 0xc;
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
        lVar28 = *(long *)(&rpmh_regulator_mode_map + lVar14 * 8);
        *(int *)((long)plVar13 + 0x4c) = (int)lVar14;
        iVar12 = of_property_read_variable_u32_array(uVar20,"qcom,disable-mode",&local_a4,1,0);
        if (iVar12 < 0) {
LAB_00101628:
          lVar14 = of_find_property(uVar20,"qcom,supported-modes",&local_6c);
          if (lVar14 == 0) goto LAB_00100694;
          uVar15 = (long)((ulong)local_6c << 0x20) >> 0x22;
          local_6c = (int)local_6c >> 2;
          auVar9._8_8_ = 0;
          auVar9._0_8_ = uVar15;
          if (SUB168(auVar9 * ZEXT816(0xc),8) != 0) {
            pbVar35 = (byte *)0xfffffff4;
            plVar13[0x15] = 0;
            goto LAB_00101988;
          }
          lVar14 = devm_kmalloc(*plVar13,(uVar15 + (long)(int)local_6c * 2) * 4,0xdc0);
          plVar13[0x15] = lVar14;
          if (lVar14 != 0) {
            *(uint *)(plVar13 + 0x16) = local_6c;
            if ((-1 < (int)local_6c) &&
               (puVar19 = (uint *)__kmalloc((long)(int)local_6c << 2,0xdc0), puVar19 != (uint *)0x0)
               ) {
              uVar11 = of_property_read_variable_u32_array
                                 (uVar20,"qcom,supported-modes",puVar19,(long)(int)local_6c,0);
              if ((int)uVar11 < 0) {
                lVar21 = *plVar1;
                pcVar33 = "qcom,supported-modes";
LAB_001018d4:
                pbVar35 = (byte *)(ulong)uVar11;
                _printk(&DAT_0010477d,"rpmh_regulator_parse_vrm_modes",lVar21,pcVar33,pbVar35);
              }
              else {
                if ((int)local_6c < 1) {
LAB_0010179c:
                  uVar11 = of_property_read_variable_u32_array
                                     (uVar20,"qcom,mode-threshold-currents",puVar19,
                                      (long)(int)local_6c,0);
                  if (-1 < (int)uVar11) {
                    if ((0 < (int)local_6c) &&
                       (*(uint *)(plVar13[0x15] + 8) = *puVar19, 1 < (int)local_6c)) {
                      lVar28 = plVar13[0x15];
                      lVar14 = 0x14;
                      uVar15 = 0;
LAB_001017f4:
                      *(uint *)(lVar28 + lVar14) = puVar19[uVar15 + 1];
                      lVar28 = plVar13[0x15];
                      if (*(int *)(lVar28 + (uVar15 & 0xffffffff) * 0xc + 8) <
                          *(int *)(lVar28 + lVar14)) goto code_r0x00101818;
                      lVar21 = *plVar1;
                      pcVar33 = "qcom,mode-threshold-currents";
LAB_00101978:
                      _printk(&DAT_0010467c,"rpmh_regulator_parse_vrm_modes",lVar21,pcVar33);
                      goto LAB_0010197c;
                    }
LAB_00101834:
                    kfree(puVar19);
                    goto LAB_00100694;
                  }
                  lVar21 = *plVar1;
                  pcVar33 = "qcom,mode-threshold-currents";
                  goto LAB_001018d4;
                }
                uVar11 = *puVar19;
                uVar15 = (ulong)uVar11;
                if (uVar11 < 5) {
                  if (*(int *)(lVar28 + uVar15 * 0xc + 4) != 0) {
                    *(undefined4 *)plVar13[0x15] = *(undefined4 *)(lVar28 + (ulong)uVar11 * 0xc);
                    *(undefined4 *)(plVar13[0x15] + 4) =
                         *(undefined4 *)(lVar28 + (ulong)*puVar19 * 0xc + 4);
                    if (1 < (int)local_6c) {
                      lVar24 = 0;
                      lVar14 = 1;
                      do {
                        uVar11 = puVar19[lVar14];
                        uVar15 = (ulong)uVar11;
                        if (4 < uVar11) goto LAB_00101910;
                        if (*(int *)(lVar28 + (ulong)uVar11 * 0xc + 4) == 0) goto LAB_00101934;
                        *(undefined4 *)(plVar13[0x15] + lVar24 + 0xc) =
                             *(undefined4 *)(lVar28 + uVar15 * 0xc);
                        *(undefined4 *)(plVar13[0x15] + lVar24 + 0x10) =
                             *(undefined4 *)(lVar28 + (ulong)puVar19[lVar14] * 0xc + 4);
                        if (((uint *)(plVar13[0x15] + lVar24))[3] <=
                            *(uint *)(plVar13[0x15] + lVar24)) {
                          lVar21 = *plVar1;
                          pcVar33 = "qcom,supported-modes";
                          goto LAB_00101978;
                        }
                        lVar14 = lVar14 + 1;
                        lVar24 = lVar24 + 0xc;
                      } while (lVar14 < (int)local_6c);
                    }
                    goto LAB_0010179c;
                  }
                  lVar14 = 0;
LAB_00101934:
                  _printk(&DAT_001047a1,"rpmh_regulator_parse_vrm_modes",*plVar1,lVar14,
                          "qcom,supported-modes",uVar15,local_a0);
                }
                else {
                  lVar14 = 0;
LAB_00101910:
                  _printk(&DAT_00103cd1,"rpmh_regulator_parse_vrm_modes",*plVar1,lVar14,
                          "qcom,supported-modes");
                }
LAB_0010197c:
                pbVar35 = (byte *)0xffffffea;
              }
              kfree(puVar19);
              goto LAB_00101988;
            }
          }
          pbVar35 = (byte *)0xfffffff4;
        }
        else if (local_a4 < 5) {
          if (*(int *)(lVar28 + (ulong)local_a4 * 0xc + 4) != 0) {
            *(undefined4 *)((long)plVar13 + 0xb4) = *(undefined4 *)(lVar28 + (ulong)local_a4 * 0xc);
            goto LAB_00101628;
          }
          _printk(&DAT_001042a3,"rpmh_regulator_parse_vrm_modes",*plVar1,(ulong)local_a4,local_a0);
          pbVar35 = (byte *)0xffffffea;
        }
        else {
          _printk(&DAT_0010454e,"rpmh_regulator_parse_vrm_modes",*plVar1);
          pbVar35 = (byte *)0xffffffea;
        }
      }
      else {
        pbVar35 = (byte *)(ulong)uVar11;
        _printk(&DAT_0010477d,"rpmh_regulator_parse_vrm_modes",*plVar1,"qcom,regulator-type",pbVar35
               );
      }
LAB_00101988:
      lVar21 = *plVar1;
      puVar18 = &DAT_00103c9e;
      goto LAB_00101994;
    }
  }
LAB_00100694:
  lVar14 = of_find_property(lVar32,"qcom,always-wait-for-ack",0);
  *(undefined4 *)(plVar13 + 0x14) = 0;
  *(bool *)((long)plVar13 + 0x94) = lVar14 != 0;
  lVar14 = of_get_next_available_child(*(undefined8 *)(*plVar13 + 0x2e8),0);
  if (lVar14 != 0) {
    do {
      lVar28 = of_find_property(lVar14,"compatible",0);
      if (lVar28 == 0) {
        *(int *)(plVar13 + 0x14) = (int)plVar13[0x14] + 1;
      }
      lVar14 = of_get_next_available_child(*(undefined8 *)(*plVar13 + 0x2e8),lVar14);
    } while (lVar14 != 0);
  }
  iVar12 = (int)plVar13[0x14];
  if (iVar12 == 0) {
    _printk(&DAT_00103c4e,"rpmh_regulator_allocate_vreg",*plVar1);
    pbVar35 = (byte *)0xffffffed;
LAB_00101370:
    lVar21 = *plVar1;
    puVar18 = &DAT_001040ae;
    goto LAB_00101994;
  }
  auVar8._8_8_ = 0;
  auVar8._0_8_ = (long)iVar12;
  if (SUB168(auVar8 * ZEXT816(0x170),8) != 0) {
    pbVar35 = (byte *)0xfffffff4;
    plVar13[0x13] = 0;
    goto LAB_00101370;
  }
  lVar14 = devm_kmalloc(*plVar13,(long)iVar12 * 0x170,0xdc0);
  plVar13[0x13] = lVar14;
  if (lVar14 == 0) {
    pbVar35 = (byte *)0xfffffff4;
    goto LAB_00101370;
  }
  lVar14 = of_get_next_available_child(*(undefined8 *)(*plVar13 + 0x2e8),0);
  if (lVar14 != 0) {
    iVar12 = 0;
    do {
      lVar28 = of_find_property(lVar14,"compatible",0);
      if (lVar28 == 0) {
        *(long *)(plVar13[0x13] + (long)iVar12 * 0x170) = lVar14;
        *(long **)(plVar13[0x13] + (long)iVar12 * 0x170 + 0x148) = plVar13;
        uVar11 = of_property_read_string
                           (lVar14,"regulator-name",plVar13[0x13] + (long)iVar12 * 0x170 + 8);
        if (uVar11 != 0) {
          pbVar35 = (byte *)(ulong)uVar11;
          _printk(&DAT_00104735,"rpmh_regulator_allocate_vreg",*plVar1,pbVar35);
          goto LAB_00101370;
        }
        iVar12 = iVar12 + 1;
      }
      lVar14 = of_get_next_available_child(*(undefined8 *)(*plVar13 + 0x2e8),lVar14);
    } while (lVar14 != 0);
  }
  if ((int)plVar13[0x14] < 1) {
LAB_001010d0:
    lVar32 = of_find_property(lVar32,"qcom,send-defaults",0);
    if (lVar32 != 0) {
      mutex_lock(plVar31);
      uVar11 = rpmh_regulator_send_aggregate_requests(plVar13[0x13]);
      if (uVar11 != 0) {
        pbVar35 = (byte *)(ulong)uVar11;
        _printk(&DAT_00104627,"rpmh_regulator_probe",*plVar1,pbVar35);
        mutex_unlock(plVar31);
        goto LAB_00101a4c;
      }
      mutex_unlock(plVar31);
    }
    of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,lVar21);
    pbVar35 = (byte *)0x0;
    *(long **)(param_1 + 0xa8) = plVar13;
    goto LAB_00101a4c;
  }
  lVar14 = 0;
LAB_00100858:
  lVar28 = plVar13[0x13];
  local_a4 = 0;
  puVar34 = (undefined8 *)(lVar28 + lVar14 * 0x170);
  pcVar33 = *(char **)puVar34[0x29];
  local_80 = 0;
  uStack_78 = 0;
  uVar11 = *(uint *)((undefined8 *)puVar34[0x29] + 9);
  local_90 = (undefined8 *)0x0;
  uStack_88 = 0;
  local_a0 = (char *)0x0;
  lStack_98 = 0;
  __dest = (void *)devm_kmalloc(pcVar33,0x128,0xdc0);
  if (__dest == (void *)0x0) {
LAB_00101380:
    pbVar35 = (byte *)0xfffffff4;
    goto LAB_00101a20;
  }
  if (3 < uVar11) goto LAB_00101a88;
  memcpy(__dest,(&rpmh_regulator_ops)[uVar11],0x128);
  uVar20 = *puVar34;
  lVar24 = lVar28 + lVar14 * 0x170;
  puVar2 = (undefined8 *)(lVar24 + 8);
  *(undefined1 **)(lVar24 + 0x58) = &__this_module;
  *(undefined4 *)(lVar24 + 0x54) = 0;
  *(void **)(lVar24 + 0x48) = __dest;
  lVar24 = of_get_regulator_init_data(pcVar33,uVar20,puVar2);
  if (lVar24 == 0) goto LAB_00101380;
  uVar22 = *(uint *)(lVar24 + 0x14);
  *(uint *)(lVar24 + 0x44) = uVar22;
  if (uVar11 == 0) {
    uVar6 = *(uint *)(lVar24 + 0x10);
    if ((int)uVar6 < 1) {
      uVar6 = 0;
    }
    if (0x7cfc17 < uVar6) {
      uVar6 = 0x7cfc18;
    }
    if ((int)uVar22 < 1) {
      uVar22 = 0;
    }
    if (0x7cfc17 < uVar22) {
      uVar22 = 0x7cfc18;
    }
    *(uint *)(lVar24 + 0x10) = uVar6;
    *(uint *)(lVar24 + 0x14) = uVar22;
    if (*(long *)((long)__dest + 8) == 0) goto LAB_0010093c;
LAB_00100944:
    *(uint *)(lVar24 + 0x40) = *(uint *)(lVar24 + 0x40) | 1;
  }
  else {
    if (*(long *)((long)__dest + 8) != 0) goto LAB_00100944;
LAB_0010093c:
    if (*(long *)((long)__dest + 0x18) != 0) goto LAB_00100944;
  }
  if (((uVar11 & 0xfffffffe) == 2) && (*(uint *)(lVar24 + 0x10) == uVar22)) {
    *(uint *)(lVar28 + lVar14 * 0x170 + 0x6c) = uVar22;
  }
  plVar3 = puVar34 + 0x29;
  lVar25 = *plVar3;
  if (*(int *)(lVar25 + 0xb0) == 0) {
    *(undefined8 *)((long)__dest + 0xd8) = 0;
    *(undefined8 *)((long)__dest + 0x88) = 0;
    *(undefined8 *)((long)__dest + 0x90) = 0;
  }
  else {
    *(uint *)(lVar24 + 0x40) = *(uint *)(lVar24 + 0x40) | 0x14;
    lVar25 = *plVar3;
    if (0 < *(int *)(lVar25 + 0xb0)) {
      lVar27 = 0;
      uVar22 = *(uint *)(lVar24 + 0x3c);
      lVar29 = 4;
      do {
        lVar27 = lVar27 + 1;
        puVar19 = (uint *)(*(long *)(lVar25 + 0xa8) + lVar29);
        lVar29 = lVar29 + 0xc;
        uVar22 = *puVar19 | uVar22;
        *(uint *)(lVar24 + 0x3c) = uVar22;
        lVar25 = *plVar3;
      } while (lVar27 < *(int *)(lVar25 + 0xb0));
    }
  }
  if ((uVar11 == 1) && (*(int *)(lVar25 + 0x50) != 0)) {
    *(undefined8 *)((long)__dest + 0x78) = 0;
    *(undefined8 *)((long)__dest + 0x80) = 0;
    *(undefined8 *)((long)__dest + 0x70) = 0;
  }
  if (*(long *)((long)__dest + 0x70) != 0) {
    *(uint *)(lVar24 + 0x40) = *(uint *)(lVar24 + 0x40) | 8;
  }
  if (1 < uVar11 - 2) {
    if (uVar11 == 0) {
      uVar23 = 2;
      goto LAB_00100a48;
    }
    if (uVar11 == 1) {
      uVar23 = *(undefined4 *)(*plVar3 + 0x90);
      goto LAB_00100a48;
    }
    pbVar35 = (byte *)0xffffffea;
    goto LAB_00101a20;
  }
  uVar23 = 1;
LAB_00100a48:
  uVar20 = *puVar34;
  *(undefined4 *)(lVar28 + lVar14 * 0x170 + 0x40) = uVar23;
  uVar11 = of_property_read_variable_u32_array(uVar20,"qcom,set",&local_a4,1,0);
  if ((int)uVar11 < 0) {
    pbVar35 = (byte *)(ulong)uVar11;
    uVar20 = *puVar2;
    puVar18 = &DAT_00104522;
    goto LAB_00101a1c;
  }
  if ((local_a4 & 3) == 0) {
    uVar20 = *puVar2;
    puVar18 = &DAT_001044d2;
    uVar11 = local_a4;
    goto LAB_001010a0;
  }
  pcVar16 = (char *)*puVar2;
  lVar25 = lVar28 + lVar14 * 0x170;
  *(byte *)(lVar25 + 0x150) = (byte)local_a4 & 1;
  *(byte *)(lVar25 + 0x151) = (byte)(local_a4 >> 1) & 1;
  sVar17 = strlen(pcVar16);
  lVar25 = __kmalloc(sVar17 + 0x10,0xdc0);
  if (lVar25 == 0) {
LAB_00101394:
    uVar20 = *puVar2;
    puVar18 = &DAT_001045a1;
    pbVar35 = (byte *)0xfffffff4;
    goto LAB_00101a1c;
  }
  scnprintf(lVar25,sVar17 + 0x10,"%s-parent-supply",*puVar2);
  lVar27 = of_find_property(*(undefined8 *)(*(long *)*plVar3 + 0x2e8),lVar25,0);
  if ((lVar27 == 0) && (lVar27 = of_find_property(*puVar34,lVar25,0), lVar27 == 0)) {
    lVar27 = of_find_property(*puVar34,"vin-supply",0);
    kfree(lVar25);
    puVar18 = &DAT_0010433a;
    if (lVar27 != 0) goto LAB_00100b40;
  }
  else {
    kfree(lVar25);
    sVar17 = strlen((char *)*puVar2);
    puVar18 = (undefined *)devm_kmalloc(*(undefined8 *)*plVar3,sVar17 + 10,0xdc0);
    if (puVar18 == (undefined *)0x0) goto LAB_00101394;
    scnprintf(puVar18,sVar17 + 10,"%s-parent",*puVar2);
LAB_00100b40:
    *(undefined **)(lVar28 + lVar14 * 0x170 + 0x10) = puVar18;
  }
  uStack_88 = *puVar34;
  local_6c = 0;
  local_a0 = pcVar33;
  lStack_98 = lVar24;
  local_90 = puVar34;
  switch(*(undefined4 *)(*plVar3 + 0x48)) {
  case 0:
    iVar12 = of_property_read_variable_u32_array(uStack_88,"qcom,init-enable",&local_6c,1,0);
    if (-1 < iVar12) {
      lVar24 = lVar28 + lVar14 * 0x170;
      *(uint *)(lVar24 + 0x158) = (uint)(local_6c != 0);
      *(uint *)(lVar24 + 0x164) = *(uint *)(lVar24 + 0x164) | 2;
    }
    iVar12 = of_property_read_variable_u32_array(*puVar34,"qcom,init-voltage",&local_6c,1,0);
    if (-1 < iVar12) {
      if (0x7cfc18 < local_6c) {
        uVar20 = *puVar2;
        pcVar33 = "qcom,init-voltage";
        goto LAB_001019fc;
      }
      lVar24 = lVar28 + lVar14 * 0x170;
      *(uint *)(lVar24 + 0x154) = local_6c / 1000;
      *(uint *)(lVar24 + 0x164) = *(uint *)(lVar24 + 0x164) | 1;
    }
    iVar12 = of_property_read_variable_u32_array(*puVar34,"qcom,init-mode",&local_6c,1,0);
    if (iVar12 < 0) {
LAB_00100f24:
      iVar12 = of_property_read_variable_u32_array
                         (*puVar34,"qcom,init-headroom-voltage",&local_6c,1,0);
      if (-1 < iVar12) {
        if (0x7cc18 < local_6c) {
          uVar20 = *puVar2;
          pcVar33 = "qcom,init-headroom-voltage";
          goto LAB_001019fc;
        }
        lVar24 = lVar28 + lVar14 * 0x170;
        *(uint *)(lVar24 + 0x160) = local_6c / 1000;
        *(uint *)(lVar24 + 0x164) = *(uint *)(lVar24 + 0x164) | 8;
      }
      uVar20 = *puVar34;
      pcVar16 = "qcom,min-dropout-voltage";
LAB_00101028:
      iVar12 = of_property_read_variable_u32_array(uVar20,pcVar16,&local_6c,1,0);
      if (-1 < iVar12) {
        *(uint *)(lVar28 + lVar14 * 0x170 + 0x74) = local_6c;
      }
      break;
    }
    if (4 < local_6c) {
      uVar20 = *puVar2;
      pcVar33 = "qcom,init-mode";
      goto LAB_001019fc;
    }
    lVar24 = *plVar3;
    uVar11 = *(uint *)(lVar24 + 0x4c);
    if (uVar11 == 0) {
      _printk(&DAT_00104451,"rpmh_regulator_load_default_parameters",*puVar2,"qcom,init-mode");
      goto LAB_00101a00;
    }
    if (0xc < uVar11) goto LAB_00101a88;
    if (*(int *)(*(long *)(&rpmh_regulator_mode_map + (ulong)uVar11 * 8) + (ulong)local_6c * 0xc + 4
                ) != 0) {
      lVar25 = lVar28 + lVar14 * 0x170;
      piVar30 = (int *)(*(long *)(&rpmh_regulator_mode_map + (ulong)uVar11 * 8) +
                       (ulong)local_6c * 0xc);
      *(int *)(lVar25 + 0x15c) = *piVar30;
      *(uint *)(lVar25 + 0x164) = *(uint *)(lVar25 + 0x164) | 4;
      if (0 < (int)*(uint *)(lVar24 + 0xb0)) {
        uVar15 = 0;
        piVar26 = *(int **)(lVar24 + 0xa8);
        do {
          if (*piVar26 == *piVar30) {
            *(int *)(lVar28 + lVar14 * 0x170 + 0x168) = (int)uVar15;
            break;
          }
          uVar15 = uVar15 + 1;
          piVar26 = piVar26 + 3;
        } while (*(uint *)(lVar24 + 0xb0) != uVar15);
      }
      goto LAB_00100f24;
    }
    _printk(&DAT_001046b9,"rpmh_regulator_load_default_parameters",*puVar2,"qcom,init-mode");
    goto LAB_00101a00;
  case 1:
    iVar12 = of_property_read_variable_u32_array(uStack_88,"qcom,init-voltage-level",&local_6c,1,0);
    if (iVar12 < 0) {
LAB_00101018:
      uVar20 = *puVar34;
      pcVar16 = "qcom,min-dropout-voltage-level";
      goto LAB_00101028;
    }
    lVar24 = *plVar3;
    iVar12 = *(int *)(lVar24 + 0x90);
    if (0 < iVar12) {
      if (local_6c <= *(uint *)(lVar24 + 0x50)) {
        uVar23 = 0;
LAB_00101000:
        lVar24 = lVar28 + lVar14 * 0x170;
        *(undefined4 *)(lVar24 + 0x154) = uVar23;
        *(uint *)(lVar24 + 0x164) = *(uint *)(lVar24 + 0x164) | 1;
        goto LAB_00101018;
      }
      if (iVar12 != 1) {
        if (local_6c <= *(uint *)(lVar24 + 0x54)) {
          uVar23 = 1;
          goto LAB_00101000;
        }
        if (iVar12 != 2) {
          if (local_6c <= *(uint *)(lVar24 + 0x58)) {
            uVar23 = 2;
            goto LAB_00101000;
          }
          if (iVar12 != 3) {
            if (local_6c <= *(uint *)(lVar24 + 0x5c)) {
              uVar23 = 3;
              goto LAB_00101000;
            }
            if (iVar12 != 4) {
              if (local_6c <= *(uint *)(lVar24 + 0x60)) {
                uVar23 = 4;
                goto LAB_00101000;
              }
              if (iVar12 != 5) {
                if (local_6c <= *(uint *)(lVar24 + 100)) {
                  uVar23 = 5;
                  goto LAB_00101000;
                }
                if (iVar12 != 6) {
                  if (local_6c <= *(uint *)(lVar24 + 0x68)) {
                    uVar23 = 6;
                    goto LAB_00101000;
                  }
                  if (iVar12 != 7) {
                    if (local_6c <= *(uint *)(lVar24 + 0x6c)) {
                      uVar23 = 7;
                      goto LAB_00101000;
                    }
                    if (iVar12 != 8) {
                      if (local_6c <= *(uint *)(lVar24 + 0x70)) {
                        uVar23 = 8;
                        goto LAB_00101000;
                      }
                      if (iVar12 != 9) {
                        if (local_6c <= *(uint *)(lVar24 + 0x74)) {
                          uVar23 = 9;
                          goto LAB_00101000;
                        }
                        if (iVar12 != 10) {
                          if (local_6c <= *(uint *)(lVar24 + 0x78)) {
                            uVar23 = 10;
                            goto LAB_00101000;
                          }
                          if (iVar12 != 0xb) {
                            if (local_6c <= *(uint *)(lVar24 + 0x7c)) {
                              uVar23 = 0xb;
                              goto LAB_00101000;
                            }
                            if (iVar12 != 0xc) {
                              if (local_6c <= *(uint *)(lVar24 + 0x80)) {
                                uVar23 = 0xc;
                                goto LAB_00101000;
                              }
                              if (iVar12 != 0xd) {
                                if (local_6c <= *(uint *)(lVar24 + 0x84)) {
                                  uVar23 = 0xd;
                                  goto LAB_00101000;
                                }
                                if (iVar12 != 0xe) {
                                  if (local_6c <= *(uint *)(lVar24 + 0x88)) {
                                    uVar23 = 0xe;
                                    goto LAB_00101000;
                                  }
                                  if (iVar12 != 0xf) {
                                    if (local_6c <= *(uint *)(lVar24 + 0x8c)) {
                                      uVar23 = 0xf;
                                      goto LAB_00101000;
                                    }
                                    if (iVar12 != 0x10) {
LAB_00101a88:
                    /* WARNING: Does not return */
                                      pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x101a8c);
                                      (*pcVar10)();
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
            }
          }
        }
      }
    }
    uVar20 = *puVar2;
    pcVar33 = "qcom,init-voltage-level";
LAB_001019fc:
    _printk(&DAT_0010433e,"rpmh_regulator_load_default_parameters",uVar20,pcVar33);
LAB_00101a00:
    uVar20 = *puVar2;
    puVar18 = &DAT_00103d1a;
    pbVar35 = (byte *)0xffffffea;
LAB_00101a1c:
    _printk(puVar18,"rpmh_regulator_init_vreg",uVar20,pbVar35);
    goto LAB_00101a20;
  case 2:
    iVar12 = of_property_read_variable_u32_array(uStack_88,"qcom,init-enable",&local_6c,1,0);
    if (-1 < iVar12) {
      lVar24 = lVar28 + lVar14 * 0x170;
      *(uint *)(lVar24 + 0x158) = (uint)(local_6c != 0);
      uVar11 = *(uint *)(lVar24 + 0x164) | 2;
LAB_00100ec8:
      *(uint *)(lVar24 + 0x164) = uVar11;
    }
    break;
  case 3:
    iVar12 = of_property_read_variable_u32_array(uStack_88,"qcom,init-enable",&local_6c,1,0);
    if (-1 < iVar12) {
      lVar24 = lVar28 + lVar14 * 0x170;
      *(uint *)(lVar24 + 0x154) = (uint)(local_6c != 0);
      uVar11 = *(uint *)(lVar24 + 0x164) | 1;
      goto LAB_00100ec8;
    }
  }
  pbVar35 = (byte *)devm_regulator_register(pcVar33,puVar2,&local_a0);
  lVar28 = lVar28 + lVar14 * 0x170;
  puVar4 = (undefined8 *)(lVar28 + 0x140);
  *(byte **)(lVar28 + 0x140) = pbVar35;
  if (pbVar35 < (byte *)0xfffffffffffff001) {
    iVar12 = devm_regulator_proxy_consumer_register(pcVar33,*puVar34);
    if (iVar12 != 0) {
      _printk(&DAT_0010441d,"rpmh_regulator_init_vreg",*puVar2,iVar12);
    }
    uVar11 = devm_regulator_debug_register(pcVar33,*puVar4);
    if (uVar11 != 0) {
      uVar20 = *puVar2;
      puVar18 = &DAT_00104062;
LAB_001010a0:
      _printk(puVar18,"rpmh_regulator_init_vreg",uVar20,uVar11);
    }
  }
  else {
    uVar20 = *puVar2;
    *puVar4 = 0;
    _printk(&DAT_00103d58,"rpmh_regulator_init_vreg",uVar20,(ulong)pbVar35 & 0xffffffff);
    if ((int)pbVar35 != 0) {
LAB_00101a20:
      _printk(&DAT_00103e68,"rpmh_regulator_probe",
              *(undefined8 *)(plVar13[0x13] + lVar14 * 0x170 + 8),plVar13[1],
              (ulong)pbVar35 & 0xffffffff);
      goto LAB_00101a4c;
    }
  }
  lVar14 = lVar14 + 1;
  if ((int)plVar13[0x14] <= lVar14) goto LAB_001010d0;
  goto LAB_00100858;
code_r0x00101818:
  lVar24 = uVar15 + 2;
  lVar14 = lVar14 + 0xc;
  uVar15 = uVar15 + 1;
  if ((int)local_6c <= lVar24) goto LAB_00101834;
  goto LAB_001017f4;
}



//------------------------------------------------------------
// rpmh_regulator_send_aggregate_requests @ 00101a90 size=2404
// signature: undefined rpmh_regulator_send_aggregate_requests(void)
// callers: [rpmh_regulator_enable, rpmh_regulator_vrm_set_mode, rpmh_regulator_pbs_enable, rpmh_regulator_probe, rpmh_regulator_pbs_disable, rpmh_regulator_disable, rpmh_regulator_vrm_set_voltage, rpmh_regulator_vrm_set_load, rpmh_regulator_arc_set_voltage_sel]
//------------------------------------------------------------

int rpmh_regulator_send_aggregate_requests(long param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  undefined *puVar13;
  ulong uVar14;
  uint *puVar15;
  ulong uVar16;
  undefined8 uVar17;
  char *pcVar18;
  uint uVar19;
  ulong uVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  uint uVar23;
  uint uVar24;
  long lVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  ulong uVar32;
  undefined8 *puVar33;
  uint uVar34;
  uint uVar35;
  undefined8 local_c8;
  undefined1 local_c0 [8];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [8];
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  uint local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70;
  long local_68;
  
  lVar25 = sp_el0;
  local_68 = *(long *)(lVar25 + 0x638);
  puVar33 = *(undefined8 **)(param_1 + 0x148);
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  local_88 = 0;
  local_98 = 0;
  local_90 = 0;
  cVar6 = *(char *)((long)puVar33 + 0x96);
  local_a8 = (undefined1  [8])0x0;
  uStack_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_c8 = 0;
  local_c0 = (undefined1  [8])0x0;
  if (*(char *)((long)puVar33 + 0x94) == '\0') {
    bVar9 = *(char *)((long)puVar33 + 0x95) != '\0';
  }
  else {
    bVar9 = true;
  }
  uVar2 = *(uint *)(puVar33 + 9);
  if (uVar2 < 4) {
    uVar34 = *(uint *)(&max_reg_index_map + (ulong)uVar2 * 4);
  }
  else {
    uVar34 = 0xffffffea;
  }
  uVar14 = (ulong)*(uint *)(puVar33 + 0x14);
  if ((int)*(uint *)(puVar33 + 0x14) < 1) {
    uVar19 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar26 = 0;
    uVar29 = 0;
    uVar31 = 0;
    uVar27 = 0;
    uVar28 = 0;
    if (uVar2 == 0) goto LAB_00101cac;
LAB_00101c60:
    if (uVar2 == 1) {
      if (*(int *)(puVar33 + 10) == 0) {
        if ((local_70 >> 1 & 1) == 0) {
          local_70 = local_70 & 0xfffffffe;
        }
        else if (uVar28 == 0) {
          uVar31 = 0;
          local_80 = local_80 & 0xffffffff00000000;
        }
        local_70 = local_70 & 0xfffffffd;
        if ((local_88 >> 1 & 1) == 0) {
          local_88 = local_88 & 0xfffffffe;
        }
        else if (uVar27 == 0) {
          uVar29 = 0;
          local_98 = local_98 & 0xffffffff00000000;
        }
        local_88 = local_88 & 0xfffffffd;
      }
      else {
        local_88 = local_88 & 0xfffffffd;
        local_70 = local_70 & 0xfffffffd;
      }
LAB_00101d24:
    }
  }
  else {
    uVar30 = 0;
    uVar19 = 0;
    uVar24 = 0;
    uVar27 = 0;
    uVar29 = 0;
    uVar35 = 0;
    uVar23 = 0;
    uVar26 = 0;
    uVar28 = 0;
    uVar31 = 0;
    puVar15 = (uint *)(puVar33[0x13] + 0x164);
    do {
      if ((char)puVar15[-5] != '\0') {
        if (0 < (int)uVar34) {
          if (uVar31 <= puVar15[-4]) {
            uVar31 = puVar15[-4];
          }
          if (uVar34 != 1) {
            if (uVar28 <= puVar15[-3]) {
              uVar28 = puVar15[-3];
            }
            if (uVar34 != 2) {
              if (uVar26 <= puVar15[-2]) {
                uVar26 = puVar15[-2];
              }
              if (uVar34 != 3) {
                if (uVar23 <= puVar15[-1]) {
                  uVar23 = puVar15[-1];
                }
                if (uVar34 != 4) goto LAB_00101c40;
              }
            }
          }
        }
        uVar35 = uVar35 | *puVar15;
      }
      if (*(char *)((long)puVar15 + -0x13) != '\0') {
        if (0 < (int)uVar34) {
          if (uVar29 <= puVar15[-4]) {
            uVar29 = puVar15[-4];
          }
          if (uVar34 != 1) {
            if (uVar27 <= puVar15[-3]) {
              uVar27 = puVar15[-3];
            }
            if (uVar34 != 2) {
              if (uVar24 <= puVar15[-2]) {
                uVar24 = puVar15[-2];
              }
              if (uVar34 != 3) {
                if (uVar19 <= puVar15[-1]) {
                  uVar19 = puVar15[-1];
                }
                if (uVar34 != 4) goto LAB_00101c40;
              }
            }
          }
        }
        uVar30 = uVar30 | *puVar15;
      }
      puVar15 = puVar15 + 0x5c;
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
    local_80 = CONCAT44(uVar28,uVar31);
    local_78 = CONCAT44(uVar23,uVar26);
    local_70 = uVar35;
    local_98 = CONCAT44(uVar27,uVar29);
    local_90 = CONCAT44(uVar19,uVar24);
    local_88 = uVar30;
    if (uVar2 != 0) goto LAB_00101c60;
LAB_00101cac:
    uVar2 = *(uint *)((long)puVar33 + 0xb4);
    if (0 < (int)uVar2) {
      if (((local_70 >> 1 & 1) != 0) && (uVar28 == 0)) {
        local_78 = CONCAT44(local_78._4_4_,uVar2);
        local_70 = local_70 | 2;
        uVar26 = uVar2;
      }
      if (((local_88 >> 1 & 1) == 0) || (uVar27 != 0)) goto LAB_00101d28;
      local_88 = local_88 | 2;
      local_90 = CONCAT44(local_90._4_4_,uVar2);
      uVar24 = uVar2;
      goto LAB_00101d24;
    }
  }
LAB_00101d28:
  uVar2 = local_70;
  uVar14 = (ulong)local_88;
  bVar7 = cVar6 == '\0';
  bVar1 = (bVar7 && uVar34 != 0) && (cVar6 != '\0' || -1 < (int)uVar34);
  if (bVar7 && 0 < (int)uVar34) {
    if ((uVar31 == uVar29) || ((local_88 & 1) == 0)) {
      if (uVar34 != 1) {
        if ((uVar28 != uVar27) && ((local_88 >> 1 & 1) != 0)) goto LAB_00101da8;
        if (uVar34 != 2) {
          if ((uVar26 != uVar24) && ((local_88 >> 2 & 1) != 0)) goto LAB_00101da8;
          if (uVar34 != 3) {
            if ((uVar23 != uVar19) && ((local_88 >> 3 & 1) != 0)) goto LAB_00101da8;
            if (uVar34 != 4) {
LAB_00101c40:
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101c44);
              (*pcVar8)();
            }
          }
        }
      }
      bVar1 = false;
      bVar7 = false;
    }
    else {
LAB_00101da8:
      uVar32 = 0;
      uVar20 = 0;
      uVar31 = 0;
      uVar12 = 0;
      do {
        uVar16 = 1L << (uVar20 & 0x3f);
        if ((uVar16 & uVar14) != 0) {
          if ((uVar16 & *(uint *)((long)puVar33 + 0xdc)) != 0) {
            if (3 < uVar20) goto LAB_00101c40;
            if (0x13 < uVar32) goto LAB_00101e8c;
            if (*(int *)((long)puVar33 + uVar32 + 0xcc) == *(int *)((long)&local_98 + uVar32))
            goto LAB_00101de0;
          }
          if (3 < (uint)uVar12) goto LAB_00101c40;
          if (0x30 < uVar12 * 0xc) goto LAB_00101e8c;
          *(int *)(local_c0 + uVar12 * 0xc + -8) = (int)uVar32 + *(int *)(puVar33 + 2);
          if (3 < uVar20) goto LAB_00101c40;
          if (((0x13 < uVar32) || (uVar11 = uVar12 * 0xc, 0x2c < uVar11)) ||
             (*(undefined4 *)(local_c0 + (uVar11 - 4)) = *(undefined4 *)((long)&local_98 + uVar32),
             0x28 < uVar11)) goto LAB_00101e8c;
          lVar25 = uVar12 * 0xc;
          uVar12 = (ulong)((uint)uVar12 + 1);
          uVar31 = uVar31 | (uint)uVar16;
          *(undefined4 *)(local_c0 + lVar25) = 1;
        }
LAB_00101de0:
        uVar20 = uVar20 + 1;
        uVar32 = uVar32 + 4;
      } while (uVar34 != uVar20);
      iVar10 = (int)uVar12;
      if (0 < iVar10) {
        if ((iVar10 - 1U != 0) && (*(int *)(puVar33 + 9) == 0)) {
          iVar3 = *(int *)(puVar33 + 2);
          if (((int)local_c8 - iVar3 & 0xfffffffcU) == 4) {
            lVar25 = 0;
            puVar21 = &local_c8;
LAB_00102164:
            if (0x2c < (ulong)(lVar25 * 0xc)) goto LAB_00101e8c;
            if (*(int *)(local_c0 + lVar25 * 0xc + -4) == 0) {
              if (puVar21 != &local_c8) {
                uVar17 = *puVar21;
                uVar4 = *(undefined4 *)(puVar21 + 1);
                uVar5 = local_c0._0_4_;
                *puVar21 = local_c8;
                *(undefined4 *)(puVar21 + 1) = uVar5;
                local_c0._0_4_ = uVar4;
                local_c8 = uVar17;
              }
            }
            else {
              lVar25 = (ulong)(iVar10 - 1U) * 0xc;
              puVar22 = (undefined8 *)((long)&local_c8 + lVar25);
              if (puVar21 != puVar22) {
                uVar17 = *puVar21;
                uVar4 = *(undefined4 *)(puVar21 + 1);
                uVar5 = *(undefined4 *)(local_c0 + lVar25);
                *puVar21 = *puVar22;
                *(undefined4 *)(puVar21 + 1) = uVar5;
                *puVar22 = uVar17;
                *(undefined4 *)(local_c0 + lVar25) = uVar4;
              }
            }
          }
          else if (iVar10 != 1) {
            if ((local_c0._4_4_ - iVar3 & 0xfffffffcU) == 4) {
              lVar25 = 1;
              puVar21 = (undefined8 *)(local_c0 + 4);
              goto LAB_00102164;
            }
            if (iVar10 != 2) {
              if (((int)local_b0 - iVar3 & 0xfffffffcU) == 4) {
                lVar25 = 2;
                puVar21 = &local_b0;
                goto LAB_00102164;
              }
              if (iVar10 != 3) {
                if ((local_a8._4_4_ - iVar3 & 0xfffffffcU) == 4) {
                  lVar25 = 3;
                  puVar21 = (undefined8 *)(local_a8 + 4);
                  goto LAB_00102164;
                }
                if (iVar10 != 4) goto LAB_00101e8c;
              }
            }
          }
        }
        iVar10 = rpmh_write_async(*puVar33,0,&local_c8);
        if (iVar10 != 0) {
          _printk(&DAT_0010435a,"rpmh_regulator_send_aggregate_requests",puVar33[1],iVar10);
          goto LAB_001020e4;
        }
        rpmh_regulator_req(param_1,&local_98,(long)puVar33 + 0xcc,uVar31,0);
        *(undefined1 *)((long)puVar33 + 0x96) = 1;
        *(ulong *)((long)puVar33 + 0xcc) = local_98;
        *(undefined8 *)((long)puVar33 + 0xd4) = local_90;
        *(uint *)((long)puVar33 + 0xdc) = local_88;
      }
      bVar7 = true;
      if ((int)uVar34 < 1) goto LAB_001020a4;
    }
LAB_00101f14:
    uVar20 = 0;
    uVar14 = 0;
    uVar28 = 0;
    uVar31 = 0;
    do {
      uVar32 = 1L << (uVar14 & 0x3f);
      if ((uVar32 & uVar2) != 0) {
        if ((uVar32 & *(uint *)(puVar33 + 0x19)) != 0) {
          if (3 < uVar14) goto LAB_00101c40;
          if (0x13 < uVar20) goto LAB_00101e8c;
          if ((bool)(*(int *)((long)puVar33 + uVar20 + 0xb8) == *(int *)((long)&local_80 + uVar20) &
                    (bVar1 ^ 1U))) goto LAB_00101f40;
        }
        if (3 < uVar31) goto LAB_00101c40;
        uVar12 = (ulong)uVar31;
        if (0x30 < (uVar12 + (ulong)uVar31 * 2) * 4) goto LAB_00101e8c;
        *(int *)(local_c0 + uVar12 * 0xc + -8) = (int)uVar20 + *(int *)(puVar33 + 2);
        if (3 < uVar14) goto LAB_00101c40;
        if ((0x13 < uVar20) || (uVar16 = uVar12 * 0xc, 0x2c < uVar16)) goto LAB_00101e8c;
        uVar26 = *(uint *)((long)&local_80 + uVar20);
        *(uint *)(local_c0 + (uVar16 - 4)) = uVar26;
        if (0x28 < uVar16) goto LAB_00101e8c;
        uVar31 = uVar31 + 1;
        uVar28 = uVar28 | (uint)uVar32;
        *(undefined4 *)(local_c0 + uVar12 * 0xc) = 1;
        bVar9 = (bool)(*(uint *)((long)puVar33 + uVar20 + 0xb8) < uVar26 | bVar9);
      }
LAB_00101f40:
      uVar14 = uVar14 + 1;
      uVar20 = uVar20 + 4;
    } while (uVar34 != uVar14);
    if (0 < (int)uVar31) {
      if ((uVar31 - 1 != 0) && (*(int *)(puVar33 + 9) == 0)) {
        iVar10 = *(int *)(puVar33 + 2);
        if (((int)local_c8 - iVar10 & 0xfffffffcU) == 4) {
          lVar25 = 0;
          puVar21 = &local_c8;
LAB_0010231c:
          if (0x2c < (ulong)(lVar25 * 0xc)) {
LAB_00101e8c:
                    /* WARNING: Does not return */
            pcVar8 = (code *)SoftwareBreakpoint(1,0x101e90);
            (*pcVar8)();
          }
          if (*(int *)(local_c0 + lVar25 * 0xc + -4) == 0) {
            if (puVar21 != &local_c8) {
              uVar17 = *puVar21;
              uVar4 = *(undefined4 *)(puVar21 + 1);
              uVar5 = local_c0._0_4_;
              *puVar21 = local_c8;
              *(undefined4 *)(puVar21 + 1) = uVar5;
              local_c0._0_4_ = uVar4;
              local_c8 = uVar17;
            }
          }
          else {
            lVar25 = (ulong)(uVar31 - 1) * 0xc;
            puVar22 = (undefined8 *)((long)&local_c8 + lVar25);
            if (puVar21 != puVar22) {
              uVar17 = *puVar21;
              uVar4 = *(undefined4 *)(puVar21 + 1);
              uVar5 = *(undefined4 *)(local_c0 + lVar25);
              *puVar21 = *puVar22;
              *(undefined4 *)(puVar21 + 1) = uVar5;
              *puVar22 = uVar17;
              *(undefined4 *)(local_c0 + lVar25) = uVar4;
            }
          }
        }
        else if (uVar31 != 1) {
          if ((local_c0._4_4_ - iVar10 & 0xfffffffcU) == 4) {
            lVar25 = 1;
            puVar21 = (undefined8 *)(local_c0 + 4);
            goto LAB_0010231c;
          }
          if (uVar31 != 2) {
            if (((int)local_b0 - iVar10 & 0xfffffffcU) == 4) {
              lVar25 = 2;
              puVar21 = &local_b0;
              goto LAB_0010231c;
            }
            if (uVar31 != 3) {
              if ((local_a8._4_4_ - iVar10 & 0xfffffffcU) == 4) {
                lVar25 = 3;
                puVar21 = (undefined8 *)(local_a8 + 4);
                goto LAB_0010231c;
              }
              if (uVar31 != 4) goto LAB_00101e8c;
            }
          }
        }
      }
      if (bVar7) {
        iVar10 = rpmh_write_async(*puVar33,1,&local_c8,uVar31);
        if (iVar10 == 0) {
          rpmh_regulator_req(param_1,&local_80,puVar33 + 0x17,uVar28,1);
          goto LAB_00102064;
        }
        uVar17 = puVar33[1];
        puVar13 = &DAT_00104127;
        pcVar18 = "wake  ";
      }
      else {
LAB_00102064:
        if (bVar9) {
          iVar10 = rpmh_write();
        }
        else {
          iVar10 = rpmh_write_async(*puVar33,2,&local_c8,uVar31);
        }
        if (iVar10 == 0) {
          rpmh_regulator_req(param_1,&local_80,puVar33 + 0x17,uVar28,2);
          *(undefined1 *)((long)puVar33 + 0x95) = 0;
          puVar33[0x17] = local_80;
          puVar33[0x18] = local_78;
          *(uint *)(puVar33 + 0x19) = local_70;
          goto LAB_001020e4;
        }
        uVar17 = puVar33[1];
        puVar13 = &DAT_00103d8b;
        pcVar18 = "active";
      }
      _printk(puVar13,"rpmh_regulator_send_aggregate_requests",uVar17,pcVar18,iVar10);
      goto LAB_001020e4;
    }
  }
  else if (cVar6 == '\0') {
    bVar1 = false;
    bVar7 = false;
    if (0 < (int)uVar34) goto LAB_00101f14;
  }
  else if (0 < (int)uVar34) goto LAB_00101da8;
LAB_001020a4:
  iVar10 = 0;
LAB_001020e4:
  lVar25 = sp_el0;
  if (*(long *)(lVar25 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}



//------------------------------------------------------------
// rpmh_regulator_vrm_set_voltage @ 001023f8 size=288
// signature: undefined rpmh_regulator_vrm_set_voltage(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_vrm_set_voltage(undefined8 param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = rdev_get_drvdata();
  iVar2 = (param_2 + 999) / 1000;
  if ((int)param_3 < iVar2 * 1000) {
    _printk(&DAT_00103b8d,"rpmh_regulator_vrm_set_voltage",*(undefined8 *)(lVar4 + 8),param_2,
            param_3);
    iVar3 = -0x16;
  }
  else {
    mutex_lock(*(long *)(lVar4 + 0x148) + 0x18);
    uVar1 = *(undefined4 *)(lVar4 + 0x154);
    *(int *)(lVar4 + 0x154) = iVar2;
    lVar5 = *(long *)(lVar4 + 0x148);
    *(uint *)(lVar4 + 0x164) = *(uint *)(lVar4 + 0x164) | 1;
    if (((*(byte *)(lVar5 + 200) & 1) != 0) && (param_3 < *(uint *)(lVar5 + 0xb8))) {
      *(undefined1 *)(lVar5 + 0x95) = 1;
    }
    iVar3 = rpmh_regulator_send_aggregate_requests(lVar4);
    if (iVar3 != 0) {
      _printk(&DAT_001040eb,"rpmh_regulator_vrm_set_voltage",*(undefined8 *)(lVar4 + 8),iVar2,iVar3)
      ;
      *(undefined4 *)(lVar4 + 0x154) = uVar1;
      *(uint *)(lVar4 + 0x164) = *(uint *)(lVar4 + 0x164) | 1;
    }
    mutex_unlock(*(long *)(lVar4 + 0x148) + 0x18);
  }
  return iVar3;
}



//------------------------------------------------------------
// rpmh_regulator_vrm_get_voltage @ 0010251c size=48
// signature: undefined rpmh_regulator_vrm_get_voltage(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_vrm_get_voltage(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  iVar1 = *(int *)(lVar2 + 0x154) * 1000;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  return iVar1;
}



//------------------------------------------------------------
// rpmh_regulator_enable @ 00102550 size=164
// signature: undefined rpmh_regulator_enable(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_enable(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  mutex_lock(*(long *)(lVar3 + 0x148) + 0x18);
  uVar1 = *(undefined4 *)(lVar3 + 0x158);
  *(undefined4 *)(lVar3 + 0x158) = 1;
  *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 2;
  iVar2 = rpmh_regulator_send_aggregate_requests(lVar3);
  if (iVar2 != 0) {
    _printk(&DAT_00104255,"rpmh_regulator_enable",*(undefined8 *)(lVar3 + 8),iVar2);
    *(undefined4 *)(lVar3 + 0x158) = uVar1;
    *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 2;
  }
  mutex_unlock(*(long *)(lVar3 + 0x148) + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// rpmh_regulator_disable @ 001025f8 size=160
// signature: undefined rpmh_regulator_disable(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_disable(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  mutex_lock(*(long *)(lVar3 + 0x148) + 0x18);
  uVar1 = *(undefined4 *)(lVar3 + 0x158);
  *(undefined4 *)(lVar3 + 0x158) = 0;
  *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 2;
  iVar2 = rpmh_regulator_send_aggregate_requests(lVar3);
  if (iVar2 != 0) {
    _printk(&DAT_00103bc2,"rpmh_regulator_disable",*(undefined8 *)(lVar3 + 8),iVar2);
    *(undefined4 *)(lVar3 + 0x158) = uVar1;
    *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 2;
  }
  mutex_unlock(*(long *)(lVar3 + 0x148) + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// rpmh_regulator_is_enabled @ 0010269c size=40
// signature: undefined rpmh_regulator_is_enabled(void)
// callers: []
//------------------------------------------------------------

bool rpmh_regulator_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(int *)(lVar1 + 0x158) != 0;
}



//------------------------------------------------------------
// rpmh_regulator_vrm_set_mode @ 001026c8 size=284
// signature: undefined rpmh_regulator_vrm_set_mode(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_vrm_set_mode(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  
  lVar4 = rdev_get_drvdata();
  lVar5 = *(long *)(lVar4 + 0x148);
  if (0 < (int)*(uint *)(lVar5 + 0xb0)) {
    iVar6 = 0;
    lVar7 = 0;
    do {
      if (*(int *)(*(long *)(lVar5 + 0xa8) + 4 + lVar7) == param_2) {
        mutex_lock(lVar5 + 0x18);
        uVar2 = *(undefined4 *)(*(long *)(*(long *)(lVar4 + 0x148) + 0xa8) + lVar7);
        uVar1 = *(undefined4 *)(lVar4 + 0x15c);
        *(uint *)(lVar4 + 0x164) = *(uint *)(lVar4 + 0x164) | 4;
        *(undefined4 *)(lVar4 + 0x15c) = uVar2;
        iVar3 = rpmh_regulator_send_aggregate_requests(lVar4);
        if (iVar3 == 0) {
          *(int *)(lVar4 + 0x168) = iVar6;
        }
        else {
          _printk(&DAT_001044fd,"rpmh_regulator_vrm_set_mode_index",*(undefined8 *)(lVar4 + 8),
                  *(undefined4 *)(lVar4 + 0x15c),iVar3);
          *(undefined4 *)(lVar4 + 0x15c) = uVar1;
          *(uint *)(lVar4 + 0x164) = *(uint *)(lVar4 + 0x164) | 4;
        }
        mutex_unlock(*(long *)(lVar4 + 0x148) + 0x18);
        return iVar3;
      }
      lVar7 = lVar7 + 0xc;
      iVar6 = iVar6 + 1;
    } while ((ulong)*(uint *)(lVar5 + 0xb0) * 0xc != lVar7);
  }
  _printk(&DAT_001045f4,"rpmh_regulator_vrm_set_mode",*(undefined8 *)(lVar4 + 8),param_2);
  return -0x16;
}



//------------------------------------------------------------
// rpmh_regulator_vrm_get_mode @ 001027e8 size=52
// signature: undefined rpmh_regulator_vrm_get_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 rpmh_regulator_vrm_get_mode(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)
          (*(long *)(*(long *)(lVar1 + 0x148) + 0xa8) + (long)*(int *)(lVar1 + 0x168) * 0xc + 4);
}



//------------------------------------------------------------
// rpmh_regulator_vrm_set_load @ 00102820 size=252
// signature: undefined rpmh_regulator_vrm_set_load(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_vrm_set_load(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  
  lVar5 = rdev_get_drvdata();
  lVar6 = *(long *)(lVar5 + 0x148);
  uVar7 = *(uint *)(lVar6 + 0xb0);
  uVar3 = uVar7 - 1;
  if (-1 < (int)uVar3) {
    uVar3 = 0;
  }
  do {
    uVar7 = uVar7 - 1;
    if ((int)uVar7 < 1) {
      uVar7 = uVar3;
      break;
    }
  } while (param_2 < *(int *)(*(long *)(lVar6 + 0xa8) + (ulong)uVar7 * 0xc + 8));
  mutex_lock(lVar6 + 0x18);
  uVar1 = *(undefined4 *)(lVar5 + 0x15c);
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(lVar5 + 0x148) + 0xa8) + (long)(int)uVar7 * 0xc);
  *(uint *)(lVar5 + 0x164) = *(uint *)(lVar5 + 0x164) | 4;
  *(undefined4 *)(lVar5 + 0x15c) = uVar2;
  iVar4 = rpmh_regulator_send_aggregate_requests(lVar5);
  if (iVar4 == 0) {
    *(uint *)(lVar5 + 0x168) = uVar7;
  }
  else {
    _printk(&DAT_001044fd,"rpmh_regulator_vrm_set_mode_index",*(undefined8 *)(lVar5 + 8),
            *(undefined4 *)(lVar5 + 0x15c),iVar4);
    *(undefined4 *)(lVar5 + 0x15c) = uVar1;
    *(uint *)(lVar5 + 0x164) = *(uint *)(lVar5 + 0x164) | 4;
  }
  mutex_unlock(*(long *)(lVar5 + 0x148) + 0x18);
  return iVar4;
}



//------------------------------------------------------------
// rpmh_regulator_arc_list_voltage @ 00102920 size=84
// signature: undefined rpmh_regulator_arc_list_voltage(void)
// callers: []
//------------------------------------------------------------

undefined4 rpmh_regulator_arc_list_voltage(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  if (param_2 < *(uint *)(*(long *)(lVar3 + 0x148) + 0x90)) {
    if (0xf < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102974);
      (*pcVar1)();
    }
    uVar2 = *(undefined4 *)(*(long *)(lVar3 + 0x148) + (ulong)param_2 * 4 + 0x50);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rpmh_regulator_arc_set_voltage_sel @ 00102978 size=168
// signature: undefined rpmh_regulator_arc_set_voltage_sel(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_arc_set_voltage_sel(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  mutex_lock(*(long *)(lVar3 + 0x148) + 0x18);
  uVar1 = *(undefined4 *)(lVar3 + 0x154);
  *(undefined4 *)(lVar3 + 0x154) = param_2;
  *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  iVar2 = rpmh_regulator_send_aggregate_requests(lVar3);
  if (iVar2 != 0) {
    _printk(&DAT_00103dba,"rpmh_regulator_arc_set_voltage_sel",*(undefined8 *)(lVar3 + 8),
            *(undefined4 *)(lVar3 + 0x154),iVar2);
    *(undefined4 *)(lVar3 + 0x154) = uVar1;
    *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  }
  mutex_unlock(*(long *)(lVar3 + 0x148) + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// rpmh_regulator_arc_get_voltage_sel @ 00102a24 size=32
// signature: undefined rpmh_regulator_arc_get_voltage_sel(void)
// callers: []
//------------------------------------------------------------

undefined4 rpmh_regulator_arc_get_voltage_sel(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)(lVar1 + 0x154);
}



//------------------------------------------------------------
// rpmh_regulator_pbs_enable @ 00102a48 size=164
// signature: undefined rpmh_regulator_pbs_enable(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_pbs_enable(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  mutex_lock(*(long *)(lVar3 + 0x148) + 0x18);
  uVar1 = *(undefined4 *)(lVar3 + 0x154);
  *(undefined4 *)(lVar3 + 0x154) = 1;
  *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  iVar2 = rpmh_regulator_send_aggregate_requests(lVar3);
  if (iVar2 != 0) {
    _printk(&DAT_00104255,"rpmh_regulator_pbs_enable",*(undefined8 *)(lVar3 + 8),iVar2);
    *(undefined4 *)(lVar3 + 0x154) = uVar1;
    *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  }
  mutex_unlock(*(long *)(lVar3 + 0x148) + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// rpmh_regulator_pbs_disable @ 00102af0 size=160
// signature: undefined rpmh_regulator_pbs_disable(void)
// callers: []
//------------------------------------------------------------

int rpmh_regulator_pbs_disable(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  mutex_lock(*(long *)(lVar3 + 0x148) + 0x18);
  uVar1 = *(undefined4 *)(lVar3 + 0x154);
  *(undefined4 *)(lVar3 + 0x154) = 0;
  *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  iVar2 = rpmh_regulator_send_aggregate_requests(lVar3);
  if (iVar2 != 0) {
    _printk(&DAT_00103bc2,"rpmh_regulator_pbs_disable",*(undefined8 *)(lVar3 + 8),iVar2);
    *(undefined4 *)(lVar3 + 0x154) = uVar1;
    *(uint *)(lVar3 + 0x164) = *(uint *)(lVar3 + 0x164) | 1;
  }
  mutex_unlock(*(long *)(lVar3 + 0x148) + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// rpmh_regulator_pbs_is_enabled @ 00102b94 size=40
// signature: undefined rpmh_regulator_pbs_is_enabled(void)
// callers: []
//------------------------------------------------------------

bool rpmh_regulator_pbs_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(int *)(lVar1 + 0x154) != 0;
}



//------------------------------------------------------------
// rpmh_regulator_req @ 00102bbc size=800
// signature: undefined rpmh_regulator_req(void)
// callers: [rpmh_regulator_send_aggregate_requests]
//------------------------------------------------------------

void rpmh_regulator_req(long param_1,uint *param_2,long param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  bool bVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  undefined *puVar12;
  ulong uVar13;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
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
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar10 = sp_el0;
  local_70 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x148);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
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
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  uVar3 = *(uint *)(lVar10 + 0x48);
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_170 = 0;
  uStack_168 = 0;
  if (uVar3 < 4) {
    if (2 < param_5) {
LAB_00102ed4:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x102ed8);
      (*pcVar4)();
    }
    lVar8 = (long)(int)uVar3 * 8;
    uVar11 = *(ulong *)(&DAT_00104978 + lVar8);
    puVar12 = (&PTR_rpmh_regulator_vrm_param_names_00103a30)[(int)uVar3];
    uVar13 = *(ulong *)(&DAT_00104998 + lVar8);
    uVar6 = scnprintf(&local_170,0x100,"%s (%s), addr=0x%05X: s=%s; sent: ",
                      *(undefined8 *)(lVar10 + 8),*(undefined8 *)(param_1 + 8),
                      *(undefined4 *)(lVar10 + 0x10),(&rpmh_regulator_state_names)[param_5]);
    uVar6 = uVar6 & 0xffffffff;
    uVar9 = 0;
    bVar7 = true;
    do {
      if ((param_4 >> (uVar9 & 0x3f) & 1) != 0) {
        if (0x100 < (uint)uVar6) goto LAB_00102ed0;
        if (uVar11 <= uVar9 * 8) goto LAB_00102ed4;
        puVar2 = &DAT_00103f7e;
        if (!bVar7) {
          puVar2 = &UNK_001046e8;
        }
        iVar5 = scnprintf((long)&local_170 + uVar6,0x100 - uVar6,"%s%s=%u",puVar2,
                          *(undefined8 *)(puVar12 + uVar9 * 8),param_2[uVar9]);
        bVar7 = false;
        uVar3 = iVar5 + (uint)uVar6;
        uVar6 = (ulong)uVar3;
        if ((*(int *)(lVar10 + 0x48) == 1) && (uVar9 == 0)) {
          if ((0x100 < uVar3) || (0xf < *param_2)) goto LAB_00102ed0;
          iVar5 = scnprintf((long)&local_170 + uVar6,0x100 - uVar6," (vlvl=%u)",
                            *(undefined4 *)(lVar10 + (ulong)*param_2 * 4 + 0x50));
          bVar7 = false;
          uVar6 = (ulong)(iVar5 + uVar3);
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != uVar13);
    uVar3 = *(uint *)(param_3 + 0x10) & ~param_4;
    if (uVar3 != 0) {
      if (0x100 < (uint)uVar6) {
LAB_00102ed0:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102ed4);
        (*pcVar4)();
      }
      iVar5 = scnprintf((long)&local_170 + uVar6,0x100 - uVar6,"; prev: ");
      uVar6 = (ulong)(iVar5 + (uint)uVar6);
    }
    uVar9 = 0;
    bVar7 = true;
    do {
      if ((uVar3 >> (uVar9 & 0x3f) & 1) != 0) {
        if (0x100 < (uint)uVar6) goto LAB_00102ed0;
        if (uVar11 <= uVar9 * 8) goto LAB_00102ed4;
        puVar2 = &DAT_00103f7e;
        if (!bVar7) {
          puVar2 = &UNK_001046e8;
        }
        iVar5 = scnprintf((long)&local_170 + uVar6,0x100 - uVar6,"%s%s=%u",puVar2,
                          *(undefined8 *)(puVar12 + uVar9 * 8),param_2[uVar9]);
        bVar7 = false;
        uVar1 = iVar5 + (uint)uVar6;
        uVar6 = (ulong)uVar1;
        if ((*(int *)(lVar10 + 0x48) == 1) && (uVar9 == 0)) {
          if ((0x100 < uVar1) || (0xf < *param_2)) goto LAB_00102ed0;
          iVar5 = scnprintf((long)&local_170 + uVar6,0x100 - uVar6," (vlvl=%u)",
                            *(undefined4 *)(lVar10 + (ulong)*param_2 * 4 + 0x50));
          bVar7 = false;
          uVar6 = (ulong)(iVar5 + uVar1);
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != uVar13);
    ipc_log_string(rpmh_reg_ipc_log,&DAT_0010448d,&local_170);
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ipc_log_context_create @ 00106000 size=1
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
// __platform_driver_register @ 00106008 size=1
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
// ipc_log_context_destroy @ 00106010 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00106018 size=1
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
// devm_kmalloc @ 00106020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00106028 size=1
// signature: undefined __mutex_init(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00106030 size=1
// signature: undefined of_match_node(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00106038 size=1
// signature: undefined of_property_read_string(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_addr @ 00106040 size=1
// signature: undefined cmd_db_read_addr(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_slave_id @ 00106048 size=1
// signature: undefined cmd_db_read_slave_id(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_slave_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_aux_data @ 00106050 size=1
// signature: undefined cmd_db_read_aux_data(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_aux_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00106058 size=1
// signature: undefined of_find_property(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00106060 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106068 size=1
// signature: undefined _printk(void)
// callers: [rpmh_regulator_enable, rpmh_regulator_vrm_set_mode, rpmh_regulator_send_aggregate_requests, rpmh_regulator_pbs_enable, rpmh_regulator_probe, rpmh_regulator_pbs_disable, rpmh_regulator_disable, rpmh_regulator_vrm_set_voltage, rpmh_regulator_vrm_set_load, rpmh_regulator_arc_set_voltage_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00106070 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 00106078 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00106080 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00106088 size=1
// signature: size_t strlen(char * __s)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00106090 size=1
// signature: undefined __kmalloc(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106098 size=1
// signature: undefined scnprintf(void)
// callers: [rpmh_regulator_probe, rpmh_regulator_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001060a0 size=1
// signature: undefined kfree(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 001060a8 size=1
// signature: undefined devm_regulator_register(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_register @ 001060b0 size=1
// signature: undefined devm_regulator_proxy_consumer_register(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_proxy_consumer_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 001060b8 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001060c0 size=1
// signature: undefined mutex_lock(void)
// callers: [rpmh_regulator_enable, rpmh_regulator_vrm_set_mode, rpmh_regulator_pbs_enable, rpmh_regulator_probe, rpmh_regulator_pbs_disable, rpmh_regulator_disable, rpmh_regulator_vrm_set_voltage, rpmh_regulator_vrm_set_load, rpmh_regulator_arc_set_voltage_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001060c8 size=1
// signature: undefined mutex_unlock(void)
// callers: [rpmh_regulator_enable, rpmh_regulator_vrm_set_mode, rpmh_regulator_pbs_enable, rpmh_regulator_probe, rpmh_regulator_pbs_disable, rpmh_regulator_disable, rpmh_regulator_vrm_set_voltage, rpmh_regulator_vrm_set_load, rpmh_regulator_arc_set_voltage_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 001060d0 size=1
// signature: undefined of_platform_populate(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001060d8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001060e0 size=1
// signature: undefined _dev_err(void)
// callers: [rpmh_regulator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001060e8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [rpmh_regulator_send_aggregate_requests, rpmh_regulator_probe, rpmh_regulator_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write_async @ 001060f0 size=1
// signature: undefined rpmh_write_async(void)
// callers: [rpmh_regulator_send_aggregate_requests]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write_async(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write @ 001060f8 size=1
// signature: undefined rpmh_write(void)
// callers: [rpmh_regulator_send_aggregate_requests]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00106100 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [rpmh_regulator_arc_list_voltage, rpmh_regulator_enable, rpmh_regulator_pbs_disable, rpmh_regulator_is_enabled, rpmh_regulator_vrm_get_voltage, rpmh_regulator_vrm_set_mode, rpmh_regulator_arc_get_voltage_sel, rpmh_regulator_vrm_get_mode, rpmh_regulator_pbs_enable, rpmh_regulator_pbs_is_enabled, rpmh_regulator_disable, rpmh_regulator_vrm_set_voltage, rpmh_regulator_vrm_set_load, rpmh_regulator_arc_set_voltage_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00106108 size=1
// signature: undefined ipc_log_string(void)
// callers: [rpmh_regulator_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



