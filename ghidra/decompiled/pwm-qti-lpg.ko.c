// Decompiled by Ghidra 12.2
// Program: pwm-qti-lpg.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_lpg_pwm_set_output_type @ 0010044c size=2808
// signature: undefined qpnp_lpg_pwm_set_output_type(void)
// callers: []
//------------------------------------------------------------

int qpnp_lpg_pwm_set_output_type(long param_1,int param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  undefined1 uVar9;
  ushort uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  byte bVar15;
  int iVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  long lVar19;
  int *piVar20;
  long *plVar21;
  char *pcVar22;
  long lVar23;
  char *pcVar24;
  long lVar25;
  int *piVar26;
  char *pcVar27;
  long lVar28;
  undefined1 local_84 [4];
  char local_80 [4];
  char local_7c [4];
  char local_78 [4];
  byte local_74 [4];
  char local_70 [4];
  char local_6c [4];
  long local_68;
  
  lVar25 = sp_el0;
  local_68 = *(long *)(lVar25 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00104d42,"qpnp_lpg_pwm_set_output_type");
    iVar16 = -0x13;
    goto LAB_001004ec;
  }
  puVar18 = *(undefined8 **)(param_1 + 0x18);
  uVar3 = *(uint *)(param_1 + 0x10);
  if (uVar3 < *(uint *)(puVar18 + 0x17)) {
    lVar25 = puVar18[0xb];
    plVar21 = (long *)(lVar25 + (ulong)uVar3 * 0x70);
    if (plVar21 != (long *)0x0) {
      if ((*(long *)(*plVar21 + 0x60) != 0) &&
         (piVar26 = (int *)(lVar25 + (ulong)uVar3 * 0x70 + 0x48), *piVar26 != param_2)) {
        pcVar27 = (char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x5c);
        if ((bool)*pcVar27 != (param_2 != 2)) {
          cVar7 = *(char *)(param_1 + 0x4c);
          if ((cVar7 == '\0') || (iVar16 = qpnp_lpg_pwm_src_enable(plVar21,0), -1 < iVar16)) {
            if (param_2 != 2) {
LAB_00100af4:
              *pcVar27 = param_2 != 2;
              if (cVar7 != '\0') {
                iVar16 = qpnp_lpg_set_pwm_config(plVar21);
                if (iVar16 < 0) {
                  puVar18 = *(undefined8 **)(param_1 + 0x18);
                  pcVar27 = "Config PWM failed for channel %d, rc=%d\n";
                  goto LAB_00100f28;
                }
                iVar16 = qpnp_lpg_pwm_src_enable(plVar21,1);
                if (iVar16 < 0) goto LAB_00100b24;
              }
              iVar16 = 0;
              *piVar26 = param_2;
              goto LAB_001004ec;
            }
            pcVar22 = (char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x5e);
            if (*pcVar22 != '\0') {
LAB_00100580:
              lVar28 = *plVar21;
              lVar19 = lVar28 + 0x68;
              if (*(char *)(lVar28 + 200) == '\0') {
                lVar28 = lVar25 + (ulong)uVar3 * 0x70;
                uVar10 = *(ushort *)(lVar28 + 0x28);
                mutex_lock(lVar19);
                uVar1 = uVar10 & 0xff;
                piVar20 = (int *)(lVar28 + 0x50);
                iVar16 = regmap_write(*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x50,uVar1);
                if (iVar16 < 0) {
                  _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                           "Write addr 0x%x with value 0x%x failed, rc=%d\n",*piVar20 + 0x50,uVar1,
                           iVar16);
                  mutex_unlock(*plVar21 + 0x68);
                  lVar19 = *plVar21;
                  pcVar27 = "Write RAMP_STEP_DURATION_LSB failed, rc=%d\n";
                }
                else {
                  mutex_unlock(*plVar21 + 0x68);
                  uVar10 = uVar10 >> 8;
                  mutex_lock(*plVar21 + 0x68);
                  iVar16 = regmap_write(*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x51,uVar10);
                  if (iVar16 < 0) {
                    _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                             "Write addr 0x%x with value 0x%x failed, rc=%d\n",*piVar20 + 0x51,
                             uVar10,iVar16);
                    mutex_unlock(*plVar21 + 0x68);
                    lVar19 = *plVar21;
                    pcVar27 = "Write RAMP_STEP_DURATION_MSB failed, rc=%d\n";
                  }
                  else {
                    mutex_unlock(*plVar21 + 0x68);
                    uVar9 = *(undefined1 *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2c);
                    mutex_lock(*plVar21 + 0x68);
                    iVar16 = regmap_update_bits_base
                                       (*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x56,0x3f,uVar9,
                                        0,0,0);
                    if (iVar16 < 0) {
                      _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                               "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                               *piVar20 + 0x56,uVar9,0x3f,iVar16);
                      mutex_unlock(*plVar21 + 0x68);
                      lVar19 = *plVar21;
                      pcVar27 = "Write LPG_HI_IDX failed, rc=%d\n";
                    }
                    else {
                      mutex_unlock(*plVar21 + 0x68);
                      uVar9 = *(undefined1 *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2d);
                      mutex_lock(*plVar21 + 0x68);
                      iVar16 = regmap_update_bits_base
                                         (*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x57,0x3f,
                                          uVar9,0,0,0);
                      if (iVar16 < 0) {
                        _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                                 "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                                 *piVar20 + 0x57,uVar9,0x3f,iVar16);
                        mutex_unlock(*plVar21 + 0x68);
                        lVar19 = *plVar21;
                        pcVar27 = "Write LPG_LO_IDX failed, rc=%d\n";
                      }
                      else {
                        mutex_unlock(*plVar21 + 0x68);
                        pcVar22 = (char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2a);
                        cVar5 = *pcVar22;
                        mutex_lock(*plVar21 + 0x68);
                        iVar16 = regmap_write(*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x52,cVar5
                                             );
                        if (iVar16 < 0) {
                          _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                                   "Write addr 0x%x with value 0x%x failed, rc=%d\n",*piVar20 + 0x52
                                   ,cVar5,iVar16);
                          mutex_unlock(*plVar21 + 0x68);
                          lVar19 = *plVar21;
                          pcVar27 = "Write LPG_PAUSE_HI_MULTIPLIER failed, rc=%d\n";
                        }
                        else {
                          mutex_unlock(*plVar21 + 0x68);
                          pcVar24 = (char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2b);
                          cVar5 = *pcVar24;
                          mutex_lock(*plVar21 + 0x68);
                          iVar16 = regmap_write(*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x54,
                                                cVar5);
                          if (iVar16 < 0) {
                            _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                                     "Write addr 0x%x with value 0x%x failed, rc=%d\n",
                                     *piVar20 + 0x54,cVar5,iVar16);
                            mutex_unlock(*plVar21 + 0x68);
                            lVar19 = *plVar21;
                            pcVar27 = "Write LPG_PAUSE_LO_MULTIPLIER failed, rc=%d\n";
                          }
                          else {
                            mutex_unlock(*plVar21 + 0x68);
                            lVar19 = lVar25 + (ulong)uVar3 * 0x70;
                            bVar15 = *pcVar24 != '\0';
                            if (*pcVar22 != '\0') {
                              bVar15 = bVar15 | 2;
                            }
                            if (*(char *)(lVar19 + 0x2e) != '\0') {
                              bVar15 = bVar15 | 0x10;
                            }
                            if (*(char *)(lVar19 + 0x2f) != '\0') {
                              bVar15 = bVar15 | 8;
                            }
                            if (*(char *)(lVar19 + 0x30) != '\0') {
                              bVar15 = bVar15 | 4;
                            }
                            mutex_lock(*plVar21 + 0x68);
                            iVar16 = regmap_update_bits_base
                                               (*(undefined8 *)(*plVar21 + 0x48),*piVar20 + 0x40,
                                                0x1f,bVar15,0,0,0);
                            if (-1 < iVar16) {
                              lVar19 = *plVar21 + 0x68;
LAB_00100aec:
                              mutex_unlock(lVar19);
                              goto LAB_00100af4;
                            }
                            _dev_err(*(undefined8 *)(*plVar21 + 0x50),
                                     "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                                     *piVar20 + 0x40,bVar15,0x1f,iVar16);
                            mutex_unlock(*plVar21 + 0x68);
                            lVar19 = *plVar21;
                            pcVar27 = "Write LPG_PATTERN_CONFIG failed, rc=%d\n";
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_84[0] = 0;
                mutex_lock(lVar19);
                piVar20 = (int *)(lVar25 + (ulong)uVar3 * 0x70 + 0x58);
                iVar16 = nvmem_device_write(*(undefined8 *)(lVar28 + 0xa0),*piVar20 + 6,1,local_84);
                if (iVar16 < 0) {
                  _dev_err(*(undefined8 *)(lVar28 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",
                           *piVar20 + 6,iVar16);
                  mutex_unlock(lVar19);
                  lVar19 = *plVar21;
                  pcVar27 = "Write SDAM_PBS_SCRATCH_LUT_COUNTER_OFFSET failed, rc=%d\n";
                }
                else {
                  mutex_unlock(lVar19);
                  lVar28 = *plVar21;
                  lVar19 = lVar28 + 0x68;
                  uVar4 = *(uint *)(*(long *)(lVar28 + 0x60) + 0x48);
                  uVar11 = 0;
                  if (uVar4 != 0) {
                    uVar11 = ((uint)*(ushort *)(lVar25 + (ulong)uVar3 * 0x70 + 0x28) * 1000) / uVar4
                    ;
                  }
                  local_80[0] = (char)uVar11 - ((uVar11 & 0xff) != 0);
                  mutex_lock(lVar19);
                  iVar16 = nvmem_device_write(*(undefined8 *)(lVar28 + 0xa0),0x47,1,local_80);
                  if (iVar16 < 0) {
                    _dev_err(*(undefined8 *)(lVar28 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",
                             0x47,iVar16);
                    mutex_unlock(lVar19);
                    lVar19 = *plVar21;
                    pcVar27 = "Write SDAM_REG_RAMP_STEP_DURATION failed, rc=%d\n";
                  }
                  else {
                    mutex_unlock(lVar19);
                    lVar19 = *plVar21;
                    local_7c[0] = *(char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2c);
                    if (*(int *)(*(long *)(lVar19 + 0x60) + 0x38) == 2) {
                      local_7c[0] = local_7c[0] + *(char *)(*(long *)(lVar19 + 0x60) + 0x3c) + -0x40
                      ;
                    }
                    lVar28 = lVar19 + 0x68;
                    mutex_lock(lVar28);
                    iVar16 = nvmem_device_write(*(undefined8 *)(lVar19 + 0xa0),*piVar20 + 3,1,
                                                local_7c);
                    if (iVar16 < 0) {
                      _dev_err(*(undefined8 *)(lVar19 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",
                               *piVar20 + 3,iVar16);
                      mutex_unlock(lVar28);
                      lVar19 = *plVar21;
                      pcVar27 = "Write SDAM_REG_END_INDEX failed, rc=%d\n";
                    }
                    else {
                      mutex_unlock(lVar28);
                      lVar19 = *plVar21;
                      local_78[0] = *(char *)(lVar25 + (ulong)uVar3 * 0x70 + 0x2d);
                      if (*(int *)(*(long *)(lVar19 + 0x60) + 0x38) == 2) {
                        local_78[0] = local_78[0] + *(char *)(*(long *)(lVar19 + 0x60) + 0x3c) +
                                      -0x40;
                      }
                      lVar28 = lVar19 + 0x68;
                      mutex_lock(lVar28);
                      iVar16 = nvmem_device_write(*(undefined8 *)(lVar19 + 0xa0),*piVar20 + 4,1,
                                                  local_78);
                      if (iVar16 < 0) {
                        _dev_err(*(undefined8 *)(lVar19 + 0x50),
                                 "write SDAM add 0x%x failed, rc=%d\n",*piVar20 + 4,iVar16);
                        mutex_unlock(lVar28);
                        lVar19 = *plVar21;
                        pcVar27 = "Write SDAM_REG_START_INDEX failed, rc=%d\n";
                      }
                      else {
                        mutex_unlock(lVar28);
                        lVar19 = *plVar21;
                        lVar28 = lVar25 + (ulong)uVar3 * 0x70;
                        cVar5 = *(char *)(lVar28 + 0x2b);
                        cVar6 = *(char *)(lVar28 + 0x2a);
                        cVar8 = *(char *)(lVar28 + 0x2f);
                        local_74[0] = 0;
                        mutex_lock();
                        iVar16 = nvmem_device_read(*(undefined8 *)(lVar19 + 0xa0),*piVar20 + 1,1,
                                                   local_74);
                        if (iVar16 < 0) {
                          uVar17 = *(undefined8 *)(lVar19 + 0x50);
                          pcVar27 = "Read SDAM addr %d failed, rc=%d\n";
                        }
                        else {
                          bVar12 = cVar5 != '\0';
                          bVar13 = cVar8 != '\0';
                          bVar14 = cVar6 != '\0';
                          bVar15 = 8;
                          if (bVar14) {
                            bVar15 = 10;
                          }
                          bVar2 = bVar13 << 3;
                          if (bVar14) {
                            bVar2 = bVar13 << 3 | 2;
                          }
                          local_74[0] = bVar2 | local_74[0] & ((bVar15 | bVar12) ^ 0xff) | bVar12;
                          iVar16 = nvmem_device_write(*(undefined8 *)(lVar19 + 0xa0),*piVar20 + 1,1,
                                                      local_74);
                          if (-1 < iVar16) {
                            mutex_unlock(lVar19 + 0x68);
                            lVar19 = *plVar21;
                            local_70[0] = *(char *)(lVar28 + 0x2a);
                            mutex_lock();
                            iVar16 = nvmem_device_write(*(undefined8 *)(lVar19 + 0xa0),*piVar20 + 8,
                                                        1,local_70);
                            if (iVar16 < 0) {
                              _dev_err(*(undefined8 *)(lVar19 + 0x50),
                                       "write SDAM add 0x%x failed, rc=%d\n",*piVar20 + 8,iVar16);
                              mutex_unlock(lVar19 + 0x68);
                              lVar19 = *plVar21;
                              pcVar27 = "Write SDAM_REG_PAUSE_START_MULTIPLIER failed, rc=%d\n";
                            }
                            else {
                              mutex_unlock(lVar19 + 0x68);
                              lVar23 = *plVar21;
                              local_6c[0] = *(char *)(lVar28 + 0x2b);
                              lVar19 = lVar23 + 0x68;
                              mutex_lock(lVar19);
                              iVar16 = nvmem_device_write(*(undefined8 *)(lVar23 + 0xa0),
                                                          *piVar20 + 9,1,local_6c);
                              if (-1 < iVar16) goto LAB_00100aec;
                              _dev_err(*(undefined8 *)(lVar23 + 0x50),
                                       "write SDAM add 0x%x failed, rc=%d\n",*piVar20 + 9,iVar16);
                              mutex_unlock(lVar19);
                              lVar19 = *plVar21;
                              pcVar27 = "Write SDAM_REG_PAUSE_END_MULTIPLIER failed, rc=%d\n";
                            }
                            goto LAB_00100f0c;
                          }
                          uVar17 = *(undefined8 *)(lVar19 + 0x50);
                          pcVar27 = "write SDAM addr %d failed, rc=%d\n";
                        }
                        _dev_err(uVar17,pcVar27,*piVar20 + 1,iVar16);
                        mutex_unlock(lVar19 + 0x68);
                        lVar19 = *plVar21;
                        pcVar27 = "Write SDAM_REG_PATTERN_CONFIG failed, rc=%d\n";
                      }
                    }
                  }
                }
              }
LAB_00100f0c:
              _dev_err(*(undefined8 *)(lVar19 + 0x50),pcVar27,iVar16);
              puVar18 = *(undefined8 **)(param_1 + 0x18);
              pcVar27 = "Config LPG%d ramping failed, rc=%d\n";
              goto LAB_00100f28;
            }
            lVar19 = lVar25 + (ulong)uVar3 * 0x70;
            iVar16 = qpnp_lpg_set_lut_pattern
                               (plVar21,*(undefined8 *)(lVar19 + 0x38),
                                *(undefined4 *)(lVar19 + 0x40));
            if (-1 < iVar16) {
              *pcVar22 = '\x01';
              goto LAB_00100580;
            }
            pcVar27 = "set LUT pattern failed for LPG%d, rc=%d\n";
            uVar17 = *(undefined8 *)(*plVar21 + 0x50);
          }
          else {
LAB_00100b24:
            puVar18 = *(undefined8 **)(param_1 + 0x18);
            pcVar27 = "Enable PWM output failed for channel %d, rc=%d\n";
LAB_00100f28:
            uVar17 = *puVar18;
          }
          _dev_err(uVar17,pcVar27,*(undefined4 *)(lVar25 + (ulong)uVar3 * 0x70 + 0x4c),iVar16);
          goto LAB_001004ec;
        }
      }
      iVar16 = 0;
      goto LAB_001004ec;
    }
  }
  else {
    _dev_err(puVar18[10],"hw index %d out of range [0-%d]\n",uVar3,*(uint *)(puVar18 + 0x17) - 1);
    puVar18 = *(undefined8 **)(param_1 + 0x18);
  }
  _dev_err(*puVar18,"lpg not found\n");
  iVar16 = -0x13;
LAB_001004ec:
  lVar25 = sp_el0;
  if (*(long *)(lVar25 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar16;
}



//------------------------------------------------------------
// qpnp_lpg_pwm_src_enable @ 00100f44 size=1560
// signature: undefined qpnp_lpg_pwm_src_enable(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply]
//------------------------------------------------------------

int qpnp_lpg_pwm_src_enable(long *param_1,byte param_2)

{
  long lVar1;
  ulong *puVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  undefined8 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  long lVar17;
  long *plVar18;
  long *plVar19;
  byte local_7c [4];
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar17 = *param_1;
  bVar3 = *(char *)((long)param_1 + 0x5c) << 2;
  bVar7 = bVar3;
  if ((*(char *)((long)param_1 + 0x5c) == '\0') && (bVar7 = 2, *(char *)(lVar17 + 200) != '\0')) {
    bVar7 = bVar3;
  }
  plVar18 = *(long **)(lVar17 + 0x60);
  bVar3 = bVar7 | 0x80;
  if ((param_2 & 1) == 0) {
    bVar3 = bVar7;
  }
  mutex_lock(lVar17 + 0x68);
  iVar8 = regmap_update_bits_base
                    (*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x46,0x86,bVar3,0,0,0);
  if (iVar8 < 0) {
    _dev_err(*(undefined8 *)(*param_1 + 0x50),
             "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",(int)param_1[10] + 0x46,
             bVar3,0x86,iVar8);
    mutex_unlock(*param_1 + 0x68);
    uVar9 = *(undefined8 *)(lVar17 + 0x50);
    pcVar10 = "Write LPG_ENABLE_CONTROL failed, rc=%d\n";
  }
  else {
    mutex_unlock(*param_1 + 0x68);
    param_2 = *(char *)((long)param_1 + 0x5c) == '\0' & param_2;
    if (*(char *)(lVar17 + 200) == '\0') {
      if (param_2 != 0) {
        uVar12 = *(uint *)(lVar17 + 0xb8);
        uVar14 = 1 << (ulong)(*(uint *)((long)param_1 + 0x4c) & 0x1f);
        if (uVar12 != 0) {
          uVar15 = 0;
          do {
            if ((*(long *)(lVar17 + 0x98) == 0) ||
               (iVar8 = *(int *)(*(long *)(lVar17 + 0x98) + (long)(int)uVar15 * 4), iVar8 == 0))
            break;
            if (((int)param_1[9] == 2) &&
               (uVar6 = iVar8 - 1,
               *(char *)(*(long *)(lVar17 + 0x38) + (long)(int)uVar6 * 0x70 + 0x4c) != '\0')) {
              plVar19 = (long *)(*(long *)(lVar17 + 0x58) + (long)(int)uVar6 * 0x70);
              mutex_lock(*plVar19 + 0x68);
              iVar8 = regmap_update_bits_base
                                (*(undefined8 *)(*plVar19 + 0x48),(int)plVar19[10] + 0x46,0x80,0,0,0
                                 ,0);
              if (iVar8 < 0) {
                iVar13 = (int)plVar19[10];
                uVar9 = *(undefined8 *)(*plVar19 + 0x50);
                uVar11 = 0;
              }
              else {
                mutex_unlock(*plVar19 + 0x68);
                plVar19 = (long *)(*(long *)(lVar17 + 0x58) + (long)(int)uVar6 * 0x70);
                mutex_lock(*plVar19 + 0x68);
                iVar8 = regmap_update_bits_base
                                  (*(undefined8 *)(*plVar19 + 0x48),(int)plVar19[10] + 0x46,0x80,
                                   0x80,0,0,0);
                if (-1 < iVar8) {
                  mutex_unlock(*plVar19 + 0x68);
                  uVar14 = uVar14 | 1 << (ulong)(uVar6 & 0x1f);
                  uVar12 = *(uint *)(lVar17 + 0xb8);
                  goto LAB_0010110c;
                }
                iVar13 = (int)plVar19[10];
                uVar9 = *(undefined8 *)(*plVar19 + 0x50);
                uVar11 = 0x80;
              }
              _dev_err(uVar9,"Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                       iVar13 + 0x46,uVar11,0x80,iVar8);
              mutex_unlock(*plVar19 + 0x68);
              break;
            }
LAB_0010110c:
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar12);
        }
        mutex_lock(plVar18 + 1);
        mutex_lock(*plVar18 + 0x68);
        iVar8 = regmap_write(*(undefined8 *)(*plVar18 + 0x48),*(int *)((long)plVar18 + 0x3c) + 200,
                             uVar14 & 0xff);
        if (iVar8 < 0) {
          _dev_err(*(undefined8 *)(*plVar18 + 0x50),"Write addr 0x%x with value %d failed, rc=%d\n",
                   *(int *)((long)plVar18 + 0x3c) + 200,uVar14 & 0xff,iVar8);
          mutex_unlock(*plVar18 + 0x68);
          _dev_err(*(undefined8 *)(lVar17 + 0x50),"Write LPG_LUT_RAMP_CONTROL failed, rc=%d\n",iVar8
                  );
        }
        else {
          mutex_unlock(*plVar18 + 0x68);
        }
        mutex_unlock(plVar18 + 1);
      }
      goto LAB_001014b4;
    }
    lVar16 = *param_1;
    lVar1 = lVar16 + 0x68;
    local_7c[0] = param_2;
    mutex_lock(lVar1);
    iVar8 = nvmem_device_write(*(undefined8 *)(lVar16 + 0xa0),(int)param_1[0xb],1,local_7c);
    if (-1 < iVar8) {
      mutex_unlock(lVar1);
      lVar17 = *param_1;
      if (param_2 == 0) {
        uVar12 = *(uint *)((long)param_1 + 0x4c);
        puVar2 = (ulong *)(lVar17 + 0xc0 + (ulong)(uVar12 >> 6) * 8);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar5) {
            *puVar2 = *puVar2 & (1L << ((ulong)uVar12 & 0x3f) ^ 0xffffffffffffffffU);
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (*(long *)(lVar17 + 0xc0) == 0) {
          lVar1 = lVar17 + 0x68;
          local_70[0] = 0;
          mutex_lock(lVar1);
          iVar8 = nvmem_device_write(*(undefined8 *)(lVar17 + 0xa0),0x42,1,local_70);
          if (iVar8 < 0) {
            _dev_err(*(undefined8 *)(lVar17 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",0x42,iVar8
                    );
            mutex_unlock(lVar1);
            uVar9 = *(undefined8 *)(lVar17 + 0x50);
            pcVar10 = "Write SDAM_REG_PBS_SEQ_EN failed, rc=%d\n";
LAB_0010140c:
            _dev_err(uVar9,pcVar10,iVar8);
          }
          else {
            mutex_unlock(lVar1);
            if (*(int *)(*(long *)(lVar17 + 0x60) + 0x38) == 2) {
              local_6c[0] = 1;
              mutex_lock(lVar1);
              iVar8 = nvmem_device_write(*(undefined8 *)(lVar17 + 0xa0),0xe6,1,local_6c);
              if (iVar8 < 0) {
                _dev_err(*(undefined8 *)(lVar17 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",0xe6,
                         iVar8);
                mutex_unlock(lVar1);
                uVar9 = *(undefined8 *)(lVar17 + 0x50);
                pcVar10 = "Failed to fire PBS seq, rc=%d\n";
                goto LAB_0010140c;
              }
              mutex_unlock(lVar1);
            }
          }
        }
      }
      else {
        if (*(long *)(lVar17 + 0xc0) == 0) {
          lVar1 = lVar17 + 0x68;
          local_78[0] = 1;
          mutex_lock(lVar1);
          iVar8 = nvmem_device_write(*(undefined8 *)(lVar17 + 0xa0),0x42,1,local_78);
          if (iVar8 < 0) {
            _dev_err(*(undefined8 *)(lVar17 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",0x42,iVar8
                    );
            mutex_unlock(lVar1);
            uVar9 = *(undefined8 *)(lVar17 + 0x50);
            pcVar10 = "Write SDAM_REG_PBS_SEQ_EN failed, rc=%d\n";
            goto LAB_0010140c;
          }
          mutex_unlock(lVar1);
          if (*(int *)(*(long *)(lVar17 + 0x60) + 0x38) == 1) {
            if (*(long *)(lVar17 + 0xb0) == 0) {
              _dev_err(*(undefined8 *)(lVar17 + 0x50),"PBS device unavailable\n");
              goto LAB_00101410;
            }
            iVar8 = -0x13;
          }
          else {
            local_74[0] = 1;
            mutex_lock(lVar1);
            iVar8 = nvmem_device_write(*(undefined8 *)(lVar17 + 0xa0),0xe5,1,local_74);
            if (-1 < iVar8) {
              mutex_unlock(lVar1);
              goto LAB_001010c8;
            }
            _dev_err(*(undefined8 *)(lVar17 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",0xe5,iVar8
                    );
            mutex_unlock(lVar1);
          }
          uVar9 = *(undefined8 *)(lVar17 + 0x50);
          pcVar10 = "Failed to trigger PBS, rc=%d\n";
          goto LAB_0010140c;
        }
LAB_001010c8:
        uVar12 = *(uint *)((long)param_1 + 0x4c);
        puVar2 = (ulong *)((long *)(lVar17 + 0xc0) + (uVar12 >> 6));
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar5) {
            *puVar2 = *puVar2 | 1L << ((ulong)uVar12 & 0x3f);
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
LAB_00101410:
      iVar8 = 0;
      goto LAB_001014b4;
    }
    _dev_err(*(undefined8 *)(lVar16 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",(int)param_1[0xb],
             iVar8);
    mutex_unlock(lVar1);
    uVar9 = *(undefined8 *)(lVar17 + 0x50);
    pcVar10 = "Write SDAM_REG_LUT_EN failed, rc=%d\n";
  }
  _dev_err(uVar9,pcVar10,iVar8);
LAB_001014b4:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qpnp_lpg_set_lut_pattern @ 00101578 size=936
// signature: undefined qpnp_lpg_set_lut_pattern(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_pwm_apply]
//------------------------------------------------------------

int qpnp_lpg_set_lut_pattern(long *param_1,long param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  long *plVar13;
  uint uVar14;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  uVar12 = (ulong)param_3;
  local_68 = *(long *)(lVar7 + 0x638);
  lVar7 = *param_1;
  plVar13 = *(long **)(lVar7 + 0x60);
  if (*(char *)(lVar7 + 200) == '\0') {
    if (*(uint *)((long)param_1 + 0x54) < param_3) goto LAB_001017f8;
    mutex_lock();
    if (param_3 == 0) {
      iVar4 = 0;
    }
    else {
      uVar8 = 0;
      uVar14 = (uint)*(byte *)((long)param_1 + 0x2d) * 2 + 0x42;
      do {
        if (uVar8 == 0x41) goto LAB_00101918;
        uVar9 = 1 << (ulong)(*(uint *)(param_1 + 1) & 0x1f);
        uVar11 = uVar9 & 0xffff;
        uVar2 = *(int *)(param_2 + uVar8 * 4) * uVar11;
        uVar6 = uVar2 / 100 & 0xffff;
        if (uVar11 < uVar6) {
          _dev_err(*(undefined8 *)(*param_1 + 0x50),"PWM value %d exceed the max %d\n");
          iVar4 = -0x16;
          goto LAB_001017b8;
        }
        uVar9 = uVar9 - 1;
        if (uVar6 != uVar11) {
          uVar9 = uVar2 / 100;
        }
        mutex_lock(*plVar13 + 0x68);
        uVar11 = uVar9 & 0xff;
        iVar4 = regmap_write(*(undefined8 *)(*plVar13 + 0x48),
                             *(int *)((long)plVar13 + 0x3c) + (uVar14 & 0xff),uVar11);
        if (iVar4 < 0) {
          _dev_err(*(undefined8 *)(*plVar13 + 0x50),"Write addr 0x%x with value %d failed, rc=%d\n",
                   *(int *)((long)plVar13 + 0x3c) + (uVar14 & 0xff),uVar11,iVar4);
          mutex_unlock(*plVar13 + 0x68);
          lVar7 = *param_1;
          pcVar5 = "Write NO.%d LUT pattern LSB (%d) failed, rc=%d\n";
LAB_001018e4:
          _dev_err(*(undefined8 *)(lVar7 + 0x50),pcVar5,uVar8 & 0xffffffff,uVar11,iVar4);
          goto LAB_001017b8;
        }
        uVar11 = uVar9 >> 8 & 0xff;
        mutex_unlock(*plVar13 + 0x68);
        mutex_lock(*plVar13 + 0x68);
        uVar9 = uVar14 & 0xff | 1;
        iVar4 = regmap_update_bits_base
                          (*(undefined8 *)(*plVar13 + 0x48),*(int *)((long)plVar13 + 0x3c) + uVar9,1
                           ,uVar11,0,0,0);
        if (iVar4 < 0) {
          _dev_err(*(undefined8 *)(*plVar13 + 0x50),
                   "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                   *(int *)((long)plVar13 + 0x3c) + uVar9,uVar11,1,iVar4);
          mutex_unlock(*plVar13 + 0x68);
          lVar7 = *param_1;
          pcVar5 = "Write NO.%d LUT pattern MSB (%d) failed, rc=%d\n";
          goto LAB_001018e4;
        }
        mutex_unlock(*plVar13 + 0x68);
        uVar14 = uVar14 + 2;
        uVar8 = uVar8 + 1;
      } while (uVar12 != uVar8);
    }
    *(uint *)(param_1 + 8) = param_3;
  }
  else {
    local_70 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    if (*(uint *)((long)param_1 + 0x54) < param_3) {
LAB_001017f8:
      _dev_err(*(undefined8 *)(lVar7 + 0x50),"new pattern length (%d) larger than predefined (%d)\n"
               ,uVar12);
      iVar4 = -0x16;
      goto LAB_001017bc;
    }
    mutex_lock(plVar13 + 1);
    bVar1 = *(byte *)((long)param_1 + 0x2d);
    if (param_3 != 0) {
      uVar8 = 0;
      do {
        if (uVar8 == 0x41) {
LAB_00101918:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10191c);
          (*pcVar3)();
        }
        *(char *)((long)&local_b0 + uVar8) =
             (char)((ulong)(uint)(*(int *)(param_2 + uVar8 * 4) * 0xff) / 100);
        uVar8 = uVar8 + 1;
      } while (uVar12 != uVar8);
    }
    if (bVar1 < 0x40) {
      lVar10 = *plVar13;
      lVar7 = lVar10 + 0x68;
      mutex_lock(lVar7);
      iVar4 = nvmem_device_write(*(undefined8 *)(lVar10 + 0xa8),
                                 *(int *)((long)plVar13 + 0x3c) + (uint)bVar1,uVar12,&local_b0);
      if (-1 < iVar4) {
        mutex_unlock(lVar7);
        iVar4 = 0;
        *(uint *)(param_1 + 8) = param_3;
        goto LAB_001017b8;
      }
      _dev_err(*(undefined8 *)(lVar10 + 0x50),"write SDAM addr %d failed, rc=%d\n",
               *(int *)((long)plVar13 + 0x3c) + (uint)bVar1,iVar4);
      mutex_unlock(lVar7);
    }
    else {
      iVar4 = -0x16;
    }
    _dev_err(*(undefined8 *)(*param_1 + 0x50),"Write pattern in SDAM failed, rc=%d\n",iVar4);
  }
LAB_001017b8:
  mutex_unlock(plVar13 + 1);
LAB_001017bc:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qpnp_lpg_set_pwm_config @ 00101920 size=1112
// signature: undefined qpnp_lpg_set_pwm_config(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_pwm_apply]
//------------------------------------------------------------

int qpnp_lpg_set_pwm_config(long *param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  
  cVar1 = *(char *)((long)param_1 + 0x5d);
  iVar3 = (int)param_1[1];
  if (cVar1 == '\f') {
    uVar8 = iVar3 - 8;
    iVar3 = *(int *)((long)param_1 + 0xc);
    uVar7 = 0xffffffea;
    if (7 < uVar8) {
      uVar8 = 0xffffffea;
    }
    if (19199999 < iVar3) {
      if (iVar3 != 19200000) {
        if (iVar3 == 76800000) {
          uVar7 = 3;
        }
        goto LAB_00101a10;
      }
LAB_00101a04:
      uVar7 = 2;
      goto LAB_00101a10;
    }
    if (iVar3 != 0x400) {
      if (iVar3 != 0x8000) goto LAB_00101a10;
LAB_001019f4:
      uVar7 = 1;
      goto LAB_00101a10;
    }
  }
  else {
    if (iVar3 == 6) {
      uVar8 = 0;
    }
    else if (iVar3 == 9) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0xffffffea;
    }
    iVar3 = *(int *)((long)param_1 + 0xc);
    if (iVar3 != 0x400) {
      if (iVar3 != 19200000) {
        if (iVar3 != 0x8000) {
          uVar7 = 0xffffffea;
          goto LAB_00101a10;
        }
        goto LAB_001019f4;
      }
      goto LAB_00101a04;
    }
  }
  uVar7 = 0;
LAB_00101a10:
  iVar3 = -0x16;
  uVar11 = 0xffffffea;
  uVar9 = (int)param_1[2] - 1;
  if ((uVar9 < 6) && ((0x35U >> (ulong)(uVar9 & 0x1f) & 1) != 0)) {
    uVar11 = *(uint *)(&DAT_00105804 + (long)(int)uVar9 * 4);
  }
  uVar9 = *(uint *)((long)param_1 + 0x14);
  if (7 < uVar9) {
    uVar9 = 0xffffffea;
  }
  if (-1 < (int)(uVar8 | uVar7 | uVar11 | uVar9)) {
    if (cVar1 == '\v') {
      lVar6 = 2;
      uVar10 = 7;
    }
    else if (cVar1 == '\f') {
      lVar6 = 4;
      uVar10 = 0x77;
    }
    else {
      lVar6 = 4;
      uVar10 = 0x13;
    }
    mutex_lock(*param_1 + 0x68);
    uVar8 = (uVar8 << lVar6 | uVar7 + 1) & 0xff;
    iVar3 = regmap_update_bits_base
                      (*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x41,uVar10,uVar8,0,0,0);
    if (iVar3 < 0) {
      _dev_err(*(undefined8 *)(*param_1 + 0x50),
               "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",(int)param_1[10] + 0x41
               ,uVar8,uVar10,iVar3);
      mutex_unlock(*param_1 + 0x68);
      lVar6 = *param_1;
      pcVar4 = "Write LPG_PWM_SIZE_CLK failed, rc=%d\n";
    }
    else {
      mutex_unlock(*param_1 + 0x68);
      mutex_lock(*param_1 + 0x68);
      uVar8 = (uVar9 | uVar11 << 5) & 0xff;
      iVar3 = regmap_update_bits_base
                        (*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x42,0x67,uVar8,0,0,0);
      if (iVar3 < 0) {
        _dev_err(*(undefined8 *)(*param_1 + 0x50),
                 "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                 (int)param_1[10] + 0x42,uVar8,0x67,iVar3);
        mutex_unlock(*param_1 + 0x68);
        lVar6 = *param_1;
        pcVar4 = "Write LPG_PWM_FREQ_PREDIV_CLK failed, rc=%d\n";
      }
      else {
        mutex_unlock(*param_1 + 0x68);
        if (*(char *)((long)param_1 + 0x5c) == '\0') {
          return 0;
        }
        uVar2 = *(ushort *)(param_1 + 3);
        uVar5 = 0xff;
        if (*(char *)((long)param_1 + 0x5d) != '\f') {
          uVar5 = 1;
        }
        mutex_lock(0xff,*param_1 + 0x68);
        iVar3 = regmap_update_bits_base
                          (*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x45,uVar5,uVar2 >> 8
                           ,0,0,0);
        if (iVar3 < 0) {
          _dev_err(*(undefined8 *)(*param_1 + 0x50),
                   "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                   (int)param_1[10] + 0x45,uVar2 >> 8,uVar5,iVar3);
          mutex_unlock(*param_1 + 0x68);
          lVar6 = *param_1;
          pcVar4 = "Write LPG_PWM_VALUE_MSB failed, rc=%d\n";
        }
        else {
          mutex_unlock(*param_1 + 0x68);
          lVar6 = param_1[3];
          mutex_lock(*param_1 + 0x68);
          iVar3 = regmap_write(*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x44,(char)lVar6)
          ;
          if (iVar3 < 0) {
            _dev_err(*(undefined8 *)(*param_1 + 0x50),
                     "Write addr 0x%x with value 0x%x failed, rc=%d\n",(int)param_1[10] + 0x44,
                     (char)lVar6,iVar3);
            mutex_unlock(*param_1 + 0x68);
            lVar6 = *param_1;
            pcVar4 = "Write LPG_PWM_VALUE_LSB failed, rc=%d\n";
          }
          else {
            mutex_unlock(*param_1 + 0x68);
            mutex_lock(*param_1 + 0x68);
            iVar3 = regmap_write(*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x47,1);
            if (-1 < iVar3) {
              mutex_unlock(*param_1 + 0x68);
              return iVar3;
            }
            _dev_err(*(undefined8 *)(*param_1 + 0x50),
                     "Write addr 0x%x with value 0x%x failed, rc=%d\n",(int)param_1[10] + 0x47,1,
                     iVar3);
            mutex_unlock(*param_1 + 0x68);
            lVar6 = *param_1;
            pcVar4 = "Write LPG_PWM_SYNC failed, rc=%d\n";
          }
        }
      }
    }
    _dev_err(*(undefined8 *)(lVar6 + 0x50),pcVar4,iVar3);
  }
  return iVar3;
}



//------------------------------------------------------------
// qpnp_lpg_pwm_get_output_types_supported @ 00101d7c size=172
// signature: undefined qpnp_lpg_pwm_get_output_types_supported(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_lpg_pwm_get_output_types_supported(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  long *plVar4;
  
  if (param_1 == 0) {
    _printk(&DAT_00104d42,"qpnp_lpg_pwm_get_output_types_supported");
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + 0x18);
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar1 < *(uint *)(puVar3 + 0x17)) {
      plVar4 = (long *)(puVar3[0xb] + (ulong)uVar1 * 0x70);
      if (plVar4 != (long *)0x0) {
        uVar2 = 3;
        if (*(long *)(*plVar4 + 0x60) == 0) {
          uVar2 = 1;
        }
        return uVar2;
      }
    }
    else {
      _dev_err(puVar3[10],"hw index %d out of range [0-%d]\n",uVar1,*(uint *)(puVar3 + 0x17) - 1);
      puVar3 = *(undefined8 **)(param_1 + 0x18);
    }
    _dev_err(*puVar3,"lpg not found\n");
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// qpnp_lpg_probe @ 00101e2c size=2072
// signature: undefined qpnp_lpg_probe(void)
// callers: []
//------------------------------------------------------------

ulong qpnp_lpg_probe(long param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  long lVar9;
  uint *puVar10;
  ulong uVar11;
  char *pcVar12;
  undefined4 uVar13;
  long *plVar14;
  ulong uVar15;
  int *piVar16;
  long lVar17;
  long *plVar18;
  uint local_bc;
  ulong local_b8 [11];
  
  lVar9 = sp_el0;
  local_b8[10] = *(long *)(lVar9 + 0x638);
  puVar7 = (undefined8 *)devm_kmalloc(param_1 + 0x10,0xd0,0xdc0);
  if (puVar7 == (undefined8 *)0x0) {
    uVar15 = 0xfffffff4;
    goto LAB_0010259c;
  }
  uVar8 = *(undefined8 *)(param_1 + 0x70);
  plVar14 = puVar7 + 10;
  *plVar14 = param_1 + 0x10;
  lVar9 = dev_get_regmap(uVar8,0);
  puVar7[9] = lVar9;
  if (lVar9 == 0) {
    _dev_err(*plVar14,"Getting regmap failed\n");
    uVar15 = 0xffffffea;
    goto LAB_0010259c;
  }
  __mutex_init(puVar7 + 0xd,"&chip->bus_lock",&qpnp_lpg_probe___key);
  puVar10 = (uint *)__of_get_address(*(undefined8 *)(puVar7[10] + 0x2e8),0,0xffffffff,0,0);
  if (puVar10 == (uint *)0x0) {
    _dev_err(*plVar14,"Get %s address failed\n","lpg-base");
    uVar15 = 0xffffffea;
    goto LAB_00102588;
  }
  puVar1 = (uint *)(puVar7 + 0x17);
  uVar6 = *puVar10;
  uVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(puVar7[10] + 0x2e8),"qcom,num-lpg-channels",puVar1,1,0);
  if ((int)uVar3 < 0) {
    uVar15 = (ulong)uVar3;
    lVar9 = *plVar14;
    pcVar12 = "Failed to get qcom,num-lpg-channels, rc=%d\n";
LAB_00102500:
    _dev_err(lVar9,pcVar12,uVar15);
    goto LAB_00102508;
  }
  if (*puVar1 == 0) {
    _dev_err(*plVar14,"No LPG channels specified\n");
    uVar15 = 0xffffffea;
LAB_00102588:
    lVar9 = *plVar14;
    pcVar12 = "Devicetree properties parsing failed, rc=%d\n";
  }
  else {
    lVar9 = devm_kmalloc(*plVar14,(ulong)*puVar1 * 0x70,0xdc0);
    puVar7[0xb] = lVar9;
    if (lVar9 == 0) {
LAB_001023d0:
      uVar15 = 0xfffffff4;
      goto LAB_00102588;
    }
    if (*puVar1 != 0) {
      uVar15 = 0;
      uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
      uVar6 = uVar6 >> 0x10 | uVar6 << 0x10;
      do {
        iVar5 = (int)uVar15;
        lVar9 = (-(uVar15 >> 0x1f) & 0xffffff8000000000 | uVar15 << 7) + (long)iVar5 * -0x10;
        *(undefined8 **)(puVar7[0xb] + lVar9) = puVar7;
        *(int *)(puVar7[0xb] + lVar9 + 0x4c) = iVar5;
        *(uint *)(puVar7[0xb] + lVar9 + 0x50) = uVar6;
        *(undefined1 *)(puVar7[0xb] + lVar9 + 0x5c) = 1;
        lVar17 = puVar7[0xb];
        local_b8[0] = local_b8[0] & 0xffffffff00000000;
        plVar18 = (long *)(lVar17 + lVar9);
        mutex_lock(*plVar18 + 0x68);
        uVar3 = regmap_read(*(undefined8 *)(*plVar18 + 0x48),(int)plVar18[10] + 5,local_b8);
        if ((int)uVar3 < 0) {
          uVar15 = (ulong)uVar3;
          _dev_err(*(undefined8 *)(*plVar18 + 0x50),"Read addr 0x%x failed, rc=%d\n",
                   (int)plVar18[10] + 5,uVar15);
          mutex_unlock(*plVar18 + 0x68);
          pcVar12 = "Read subtype failed, rc=%d\n";
          lVar9 = *plVar14;
          goto LAB_00102500;
        }
        lVar9 = *plVar18;
        *(char *)(lVar17 + (long)iVar5 * 0x70 + 0x5d) = (char)local_b8[0];
        mutex_unlock(lVar9 + 0x68);
        uVar15 = (ulong)(iVar5 + 1U);
        uVar6 = uVar6 + 0x100;
      } while (iVar5 + 1U < *puVar1);
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar14 + 0x2e8),"qcom,pfm-chan-ids",0);
    if (lVar9 != 0) {
      local_bc = 0;
      uVar11 = of_property_count_elems_of_size
                         (*(undefined8 *)(*plVar14 + 0x2e8),"qcom,pfm-chan-ids",4);
      uVar15 = uVar11 & 0xffffffff;
      uVar6 = (uint)uVar11;
      if (-1 < (int)uVar6) {
        if ((uVar6 != 0) && (uVar6 <= *puVar1)) {
          uVar3 = 0;
          do {
            uVar4 = of_property_read_u32_index
                              (*(undefined8 *)(*plVar14 + 0x2e8),"qcom,pfm-chan-ids",uVar3,&local_bc
                              );
            if (uVar4 != 0) {
              lVar9 = *plVar14;
              pcVar12 = "Read pfm channel %d failed, rc=%d\n";
LAB_001024ac:
              _dev_err(lVar9,pcVar12,uVar3,uVar4);
              goto LAB_001024b0;
            }
            uVar4 = *puVar1;
            uVar2 = local_bc - 1;
            if (uVar4 <= uVar2) {
              lVar9 = *plVar14;
              pcVar12 = "pfm chan id %u is out of range 1~%d\n";
              uVar3 = local_bc;
              goto LAB_001024ac;
            }
            local_bc = uVar2;
            if (*(byte *)(puVar7[0xb] + (ulong)uVar2 * 0x70 + 0x5d) - 0xb < 2) {
              plVar18 = (long *)(puVar7[0xb] + (ulong)uVar2 * 0x70);
              local_b8[0] = local_b8[0] & 0xffffffff00000000;
              mutex_lock(*plVar18 + 0x68);
              uVar4 = regmap_read(*(undefined8 *)(*plVar18 + 0x48),(int)plVar18[10] + 8,local_b8);
              uVar15 = local_b8[0];
              if ((int)uVar4 < 0) {
                uVar15 = (ulong)uVar4;
                _dev_err(*(undefined8 *)(*plVar18 + 0x50),"Read addr 0x%x failed, rc=%d\n",
                         (int)plVar18[10] + 8,uVar15);
                mutex_unlock(*plVar18 + 0x68);
                _dev_err(*plVar14,"Read status1 failed, rc=%d\n",uVar15);
                goto LAB_001024b4;
              }
              mutex_unlock(*plVar18 + 0x68);
              if ((uVar15 & 1) == 0) {
                uVar15 = 0xffffffa1;
                goto LAB_001024b4;
              }
              *(undefined1 *)(puVar7[0xb] + (ulong)local_bc * 0x70 + 0x5f) = 1;
            }
            uVar3 = uVar3 + 1;
          } while (uVar6 != uVar3);
          goto LAB_00102104;
        }
LAB_001024b0:
        uVar15 = 0xffffffea;
      }
LAB_001024b4:
      _dev_err(*plVar14,"PFM channels specified incorrectly\n");
LAB_00102508:
      if ((int)uVar15 != -0x205) goto LAB_00102588;
LAB_00102510:
      uVar15 = 0xfffffdfb;
      goto LAB_0010259c;
    }
LAB_00102104:
    lVar9 = of_find_property(*(undefined8 *)(*plVar14 + 0x2e8),"nvmem",0);
    if (lVar9 != 0) {
      lVar9 = devm_kmalloc(*plVar14,0x50,0xcc0);
      puVar7[0xc] = lVar9;
      if (lVar9 == 0) goto LAB_001023d0;
      uVar15 = devm_nvmem_device_get(*plVar14,"ppg_sdam");
      if (uVar15 < 0xfffffffffffff001) {
        uVar13 = 1;
        puVar7[0x14] = uVar15;
        puVar7[0x15] = uVar15;
LAB_00102214:
        *(undefined4 *)(puVar7[0xc] + 0x38) = uVar13;
LAB_0010221c:
        *(undefined1 *)(puVar7 + 0x19) = 1;
        lVar9 = of_find_property(*(undefined8 *)(puVar7[10] + 0x2e8),"qcom,pbs-client",0);
        if (lVar9 != 0) {
          local_b8[8] = 0;
          local_b8[9] = 0;
          local_b8[6] = 0;
          local_b8[7] = 0;
          local_b8[4] = 0;
          local_b8[5] = 0;
          local_b8[2] = 0;
          local_b8[3] = 0;
          local_b8[0] = 0;
          local_b8[1] = 0;
          iVar5 = __of_parse_phandle_with_args
                            (*(undefined8 *)(puVar7[10] + 0x2e8),"qcom,pbs-client",0,0,0,local_b8);
          uVar15 = local_b8[0];
          if (iVar5 != 0) {
            uVar15 = 0;
          }
          puVar7[0x16] = uVar15;
          if (uVar15 == 0) {
            _dev_err(*plVar14,"Missing qcom,pbs-client property\n");
            uVar15 = 0xffffffed;
            goto LAB_00102588;
          }
        }
        uVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(puVar7[10] + 0x2e8),"qcom,lut-sdam-base",
                           puVar7[0xc] + 0x3c,1,0);
        if ((int)uVar6 < 0) {
          uVar15 = (ulong)uVar6;
          lVar9 = *plVar14;
          pcVar12 = "Read qcom,lut-sdam-base failed, rc=%d\n";
          goto LAB_00102500;
        }
        *(undefined4 *)(puVar7[0xc] + 0x48) = 0x1e78;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(puVar7[10] + 0x2e8),"qcom,tick-duration-us",puVar7[0xc] + 0x48,1,
                   0);
        uVar15 = qpnp_lpg_parse_pattern_dt(puVar7,0x40);
        if ((int)uVar15 < 0) goto LAB_00102204;
        goto LAB_001022f4;
      }
      uVar11 = devm_nvmem_device_get(*plVar14,"lut_sdam");
      uVar15 = uVar11;
      if ((uVar11 < 0xfffffffffffff001) &&
         (uVar15 = devm_nvmem_device_get(*plVar14,"lpg_chan_sdam"), uVar15 < 0xfffffffffffff001)) {
        uVar13 = 2;
        puVar7[0x14] = uVar15;
        puVar7[0x15] = uVar11;
        goto LAB_00102214;
      }
      if ((int)uVar15 != -0x205) {
        _dev_err(*plVar14,"Failed to get nvmem device, rc=%d\n",uVar15 & 0xffffffff);
        if ((int)uVar15 < 0) goto LAB_00102508;
        goto LAB_0010221c;
      }
      goto LAB_00102510;
    }
    puVar10 = (uint *)__of_get_address(*(undefined8 *)(*plVar14 + 0x2e8),1,0xffffffff,0,0);
    if (puVar10 != (uint *)0x0) {
      lVar9 = devm_kmalloc(puVar7[10],0x50,0xcc0);
      puVar7[0xc] = lVar9;
      if (lVar9 == 0) goto LAB_001023d0;
      uVar6 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
      *(uint *)(lVar9 + 0x3c) = uVar6 >> 0x10 | uVar6 << 0x10;
      uVar15 = qpnp_lpg_parse_pattern_dt(puVar7,0x2f);
      if (-1 < (int)uVar15) goto LAB_001022f4;
LAB_00102204:
      uVar15 = uVar15 & 0xffffffff;
      goto LAB_00102508;
    }
LAB_001022f4:
    uVar6 = qpnp_lpg_sdam_hw_init(puVar7);
    if ((int)uVar6 < 0) {
      uVar15 = (ulong)uVar6;
      lVar9 = *plVar14;
      pcVar12 = "SDAM HW init failed, rc=%d\n";
    }
    else {
      if (*puVar1 != 0) {
        uVar6 = 0;
        do {
          lVar9 = puVar7[0xb];
          plVar18 = (long *)(lVar9 + (long)(int)uVar6 * 0x70);
          *(undefined4 *)(plVar18 + 9) = 1;
          if ((puVar7[0xc] != 0) && (uVar3 = qpnp_lpg_pwm_src_enable(plVar18,0), (int)uVar3 < 0)) {
            uVar15 = (ulong)uVar3;
            _dev_err(*plVar14,"Disable PWM output failed for channel %d, rc=%d\n",
                     *(undefined4 *)(lVar9 + (long)(int)uVar6 * 0x70 + 0x4c),uVar15);
            goto LAB_0010259c;
          }
          if (*(char *)(lVar9 + (long)(int)uVar6 * 0x70 + 0x5f) != '\0') {
            mutex_lock(*plVar18 + 0x68);
            piVar16 = (int *)(lVar9 + (long)(int)uVar6 * 0x70 + 0x50);
            uVar3 = regmap_write(*(undefined8 *)(*plVar18 + 0x48),*piVar16 + 0x50,0x80);
            if ((int)uVar3 < 0) {
              uVar15 = (ulong)uVar3;
              _dev_err(*(undefined8 *)(*plVar18 + 0x50),
                       "Write addr 0x%x with value 0x%x failed, rc=%d\n",*piVar16 + 0x50,0x80,uVar15
                      );
              mutex_unlock(*plVar18 + 0x68);
              lVar9 = *plVar14;
              pcVar12 = "Write fm_mode_enable failed, rc=%d\n";
              goto LAB_00102594;
            }
            mutex_unlock(*plVar18 + 0x68);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar1);
      }
      *(undefined8 **)(puVar7[10] + 0x98) = puVar7;
      *(undefined4 *)(puVar7 + 2) = 0xffffffff;
      *(undefined4 *)((long)puVar7 + 0x14) = *(undefined4 *)(puVar7 + 0x17);
      *puVar7 = puVar7[10];
      puVar7[1] = qpnp_lpg_pwm_ops;
      uVar15 = pwmchip_add(puVar7);
      if (-1 < (int)uVar15) {
        uVar15 = 0;
        goto LAB_0010259c;
      }
      uVar15 = uVar15 & 0xffffffff;
      lVar9 = *plVar14;
      pcVar12 = "Add pwmchip failed, rc=%d\n";
    }
  }
LAB_00102594:
  _dev_err(lVar9,pcVar12,uVar15 & 0xffffffff);
LAB_0010259c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15 & 0xffffffff;
}



//------------------------------------------------------------
// qpnp_lpg_remove @ 00102648 size=56
// signature: undefined qpnp_lpg_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_lpg_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  pwmchip_remove(lVar1);
  *(undefined8 *)(*(long *)(lVar1 + 0x50) + 0x98) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_lpg_sdam_hw_init @ 00102680 size=404
// signature: undefined qpnp_lpg_sdam_hw_init(void)
// callers: [qpnp_lpg_probe, pwm_restore]
//------------------------------------------------------------

int qpnp_lpg_sdam_hw_init(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if ((*(char *)(param_1 + 200) != '\0') && (uVar5 = *(uint *)(param_1 + 0xb8), uVar5 != 0)) {
    uVar6 = 0;
    do {
      plVar7 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)uVar6 * 0x70);
      plVar8 = plVar7 + 0xb;
      if ((int)*plVar8 != 0) {
        lVar9 = *plVar7;
        local_60[0] = 0;
        lVar1 = lVar9 + 0x68;
        mutex_lock(lVar1);
        iVar2 = nvmem_device_write(*(undefined8 *)(lVar9 + 0xa0),(int)*plVar8,1,local_60);
        if (iVar2 < 0) {
          _dev_err(*(undefined8 *)(lVar9 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",(int)*plVar8,
                   iVar2);
          mutex_unlock(lVar1);
          uVar3 = *(undefined8 *)(param_1 + 0x50);
          pcVar4 = "Write SDAM_REG_LUT_EN failed, rc=%d\n";
        }
        else {
          mutex_unlock(lVar1);
          lVar9 = *plVar7;
          local_5c[0] = 0;
          lVar1 = lVar9 + 0x68;
          mutex_lock(lVar1);
          iVar2 = nvmem_device_write(*(undefined8 *)(lVar9 + 0xa0),(int)*plVar8 + 6,1,local_5c);
          if (-1 < iVar2) {
            mutex_unlock(lVar1);
            uVar5 = *(uint *)(param_1 + 0xb8);
            goto LAB_001026d8;
          }
          _dev_err(*(undefined8 *)(lVar9 + 0x50),"write SDAM add 0x%x failed, rc=%d\n",
                   (int)*plVar8 + 6,iVar2);
          mutex_unlock(lVar1);
          pcVar4 = "Write SDAM_REG_PBS_SCRATCH_LUT_COUNTER failed, rc=%d\n";
          uVar3 = *(undefined8 *)(*plVar7 + 0x50);
        }
        _dev_err(uVar3,pcVar4,iVar2);
        goto LAB_0010279c;
      }
LAB_001026d8:
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar5);
  }
  iVar2 = 0;
LAB_0010279c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_lpg_parse_pattern_dt @ 00102814 size=1640
// signature: undefined qpnp_lpg_parse_pattern_dt(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

uint qpnp_lpg_parse_pattern_dt(long param_1,uint param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  char *pcVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  undefined1 *puVar17;
  long *plVar18;
  byte *pbVar19;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_74 = 0;
  local_70 = 0;
  **(long **)(param_1 + 0x60) = param_1;
  __mutex_init(*(long *)(param_1 + 0x60) + 8,"&chip->lut->lock",&qpnp_lpg_parse_pattern_dt___key);
  plVar18 = (long *)(param_1 + 0x50);
  uVar6 = of_property_count_elems_of_size(*(undefined8 *)(*plVar18 + 0x2e8),"qcom,lut-patterns",4);
  if ((int)uVar6 < 0) {
    lVar9 = *plVar18;
    pcVar12 = "Read qcom,lut-patterns failed, rc=%d\n";
  }
  else {
    lVar9 = *plVar18;
    if (param_2 < uVar6) {
      pcVar12 = "qcom,lut-patterns length %d exceed max %d\n";
      uVar13 = (ulong)uVar6;
LAB_00102d1c:
      _dev_err(lVar9,pcVar12,uVar13,param_2);
      uVar6 = 0xffffffea;
      goto LAB_00102ca8;
    }
    uVar10 = devm_kmalloc(lVar9,(ulong)param_2 << 2,0xdc0);
    *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x40) = uVar10;
    lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x40);
    if (lVar9 == 0) {
LAB_00102ca4:
      uVar6 = 0xfffffff4;
      goto LAB_00102ca8;
    }
    uVar6 = of_property_read_variable_u32_array
                      (*(undefined8 *)(*plVar18 + 0x2e8),"qcom,lut-patterns",lVar9,uVar6,0);
    lVar9 = *plVar18;
    if (-1 < (int)uVar6) {
      uVar10 = *(undefined8 *)(lVar9 + 0x2e8);
      lVar9 = of_get_next_available_child(uVar10,0);
      if (lVar9 != 0) {
        iVar7 = 0;
        do {
          lVar9 = of_get_next_available_child(uVar10,lVar9);
          iVar7 = iVar7 + -1;
        } while (lVar9 != 0);
        if (iVar7 != 0) {
          puVar11 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(*plVar18 + 0x2e8),0);
          if (puVar11 != (undefined8 *)0x0) {
            do {
              uVar6 = of_property_read_variable_u32_array(puVar11,"qcom,lpg-chan-id",&local_70,1,0);
              if ((int)uVar6 < 0) {
                _dev_err(*plVar18,"Get qcom,lpg-chan-id failed for node %s, rc=%d\n",*puVar11,uVar6)
                ;
                goto LAB_00102ca8;
              }
              uVar8 = local_70 - 1;
              if (*(uint *)(param_1 + 0xb8) <= uVar8) {
                lVar9 = *plVar18;
                pcVar12 = "lpg-chann-id %d is out of range 1~%d\n";
                uVar13 = (ulong)local_70;
                param_2 = *(uint *)(param_1 + 0xb8);
                goto LAB_00102d1c;
              }
              lVar9 = *(long *)(param_1 + 0x58);
              if (*(char *)(lVar9 + (ulong)uVar8 * 0x70 + 0x5f) != '\0') {
                lVar9 = *plVar18;
                pcVar12 = "Cannot configure ramp for PFM-enabled channel %d\n";
                uVar8 = local_70;
                goto LAB_00102d90;
              }
              if (*(char *)(param_1 + 200) != '\0') {
                uVar6 = of_property_read_variable_u32_array
                                  (puVar11,"qcom,lpg-sdam-base",&local_74,1,0);
                if (-1 < (int)uVar6) {
                  *(undefined4 *)(*(long *)(param_1 + 0x58) + (ulong)(local_70 - 1) * 0x70 + 0x58) =
                       local_74;
                  lVar9 = *(long *)(param_1 + 0x58);
                  uVar8 = local_70 - 1;
                  goto LAB_001029e8;
                }
                lVar9 = *plVar18;
                pcVar12 = "get qcom,lpg-sdam-base failed for lpg%d, rc=%d\n";
LAB_00102e30:
                _dev_err(lVar9,pcVar12,local_70,uVar6);
                goto LAB_00102ca8;
              }
LAB_001029e8:
              uVar5 = local_70;
              local_6c = 0;
              uVar6 = of_property_read_variable_u32_array(puVar11,"qcom,ramp-step-ms",&local_6c,1,0)
              ;
              if ((int)uVar6 < 0) {
                lVar9 = *plVar18;
                pcVar12 = "get qcom,ramp-step-ms failed for lpg%d, rc=%d\n";
LAB_00102de4:
                _dev_err(lVar9,pcVar12,uVar5,uVar6);
LAB_00102e20:
                lVar9 = *plVar18;
                pcVar12 = "Parsing ramp props failed for lpg%d, rc=%d\n";
                goto LAB_00102e30;
              }
              *(short *)(lVar9 + (ulong)uVar8 * 0x70 + 0x28) = (short)local_6c;
              uVar6 = of_property_read_variable_u32_array
                                (puVar11,"qcom,ramp-low-index",&local_6c,1,0);
              if ((int)uVar6 < 0) {
                lVar9 = *plVar18;
                pcVar12 = "get qcom,ramp-low-index failed for lpg%d, rc=%d\n";
                goto LAB_00102de4;
              }
              pbVar19 = (byte *)(lVar9 + (ulong)uVar8 * 0x70 + 0x2d);
              *pbVar19 = (byte)local_6c;
              if (param_2 <= (local_6c & 0xff)) {
                lVar9 = *plVar18;
                pcVar12 = "qcom,ramp-low-index should less than max %d\n";
LAB_00102e00:
                _dev_err(lVar9,pcVar12,param_2);
LAB_00102e1c:
                uVar6 = 0xffffffea;
                goto LAB_00102e20;
              }
              uVar6 = of_property_read_variable_u32_array
                                (puVar11,"qcom,ramp-high-index",&local_6c,1,0);
              if ((int)uVar6 < 0) {
                lVar9 = *plVar18;
                pcVar12 = "get qcom,ramp-high-index failed for lpg%d, rc=%d\n";
                goto LAB_00102de4;
              }
              uVar6 = local_6c & 0xff;
              *(char *)(lVar9 + (ulong)uVar8 * 0x70 + 0x2c) = (char)local_6c;
              if (param_2 < uVar6) {
                lVar9 = *plVar18;
                pcVar12 = "qcom,ramp-high-index shouldn\'t exceed max %d\n";
                goto LAB_00102e00;
              }
              bVar4 = *pbVar19;
              if ((*(char *)(param_1 + 200) != '\0') && (uVar6 <= bVar4)) {
                _dev_err(*plVar18,
                         "high-index(%d) should be larger than low-index(%d) when SDAM used\n");
                goto LAB_00102e1c;
              }
              lVar16 = lVar9 + (ulong)uVar8 * 0x70;
              iVar7 = (uVar6 - bVar4) + 1;
              *(int *)(lVar16 + 0x40) = iVar7;
              lVar14 = *(long *)(*(long *)(param_1 + 0x60) + 0x40);
              *(int *)(lVar16 + 0x54) = iVar7;
              *(ulong *)(lVar16 + 0x38) = lVar14 + (ulong)bVar4 * 4;
              lVar14 = of_find_property(puVar11,"qcom,ramp-pattern-repeat",0);
              *(undefined1 *)(lVar16 + 0x2a) = 0;
              *(bool *)(lVar16 + 0x2f) = lVar14 != 0;
              iVar7 = of_property_read_variable_u32_array
                                (puVar11,"qcom,ramp-pause-hi-count",&local_6c,1,0);
              if (-1 < iVar7) {
                if ((*(char *)(param_1 + 200) != '\0') && (0xfe < local_6c)) goto LAB_00102e1c;
                *(undefined1 *)(lVar16 + 0x2a) = (char)local_6c;
              }
              puVar17 = (undefined1 *)(lVar9 + (ulong)uVar8 * 0x70 + 0x2b);
              *puVar17 = 0;
              uVar6 = of_property_read_variable_u32_array
                                (puVar11,"qcom,ramp-pause-lo-count",&local_6c,1,0);
              if (-1 < (int)uVar6) {
                if ((*(char *)(param_1 + 200) != '\0') && (0xfe < local_6c)) goto LAB_00102e1c;
                *puVar17 = (char)local_6c;
              }
              if (*(char *)(param_1 + 200) == '\0') {
                lVar14 = of_find_property(puVar11,"qcom,ramp-from-low-to-high",0);
                lVar9 = lVar9 + (ulong)uVar8 * 0x70;
                *(bool *)(lVar9 + 0x2e) = lVar14 != 0;
                lVar14 = of_find_property(puVar11,"qcom,ramp-toggle",0);
                *(bool *)(lVar9 + 0x30) = lVar14 != 0;
                if ((int)uVar6 < 0) goto LAB_00102e20;
              }
              puVar11 = (undefined8 *)
                        of_get_next_available_child(*(undefined8 *)(*plVar18 + 0x2e8),puVar11);
            } while (puVar11 != (undefined8 *)0x0);
          }
          uVar8 = of_property_count_elems_of_size
                            (*(undefined8 *)(*plVar18 + 0x2e8),"qcom,sync-channel-ids",4);
          if (-1 < (int)uVar8) {
            uVar15 = (ulong)uVar8;
            lVar9 = *(long *)(param_1 + 0x50);
            if (*(uint *)(param_1 + 0xb8) < uVar8) {
              pcVar12 = "qcom,sync-channel-ids has too many channels: %d\n";
LAB_00102d90:
              _dev_err(lVar9,pcVar12,uVar8);
              uVar6 = 0xffffffea;
              goto LAB_00102ca8;
            }
            lVar9 = devm_kmalloc(lVar9,(ulong)*(uint *)(param_1 + 0xb8) << 2,0xdc0);
            *(long *)(param_1 + 0x98) = lVar9;
            if (lVar9 == 0) goto LAB_00102ca4;
            uVar6 = of_property_read_variable_u32_array
                              (*(undefined8 *)(*plVar18 + 0x2e8),"qcom,sync-channel-ids",lVar9,
                               uVar15,0);
            if ((int)uVar6 < 0) {
              lVar9 = *plVar18;
              pcVar12 = "Get qcom,sync-channel-ids failed, rc=%d\n";
              goto LAB_00102d30;
            }
            if (uVar8 != 0) {
              uVar13 = 0;
              do {
                param_2 = (*(int **)(param_1 + 0x98))[uVar13];
                if ((param_2 == 0) || (*(uint *)(param_1 + 0xb8) < param_2)) {
                  lVar9 = *plVar18;
                  pcVar12 = "lpg_group[%d]: %d is not a valid channel\n";
                  goto LAB_00102d1c;
                }
                uVar13 = uVar13 + 1;
              } while (uVar15 != uVar13);
              if (1 < uVar8) {
                lVar9 = 4;
                lVar14 = *(long *)(param_1 + 0x58) + (ulong)(**(int **)(param_1 + 0x98) - 1) * 0x70;
                do {
                  piVar1 = (int *)(*(long *)(param_1 + 0x98) + lVar9);
                  lVar9 = lVar9 + 4;
                  uVar2 = *(undefined8 *)(lVar14 + 0x30);
                  lVar16 = *(long *)(param_1 + 0x58) + (ulong)(*piVar1 - 1) * 0x70;
                  uVar10 = *(undefined8 *)(lVar14 + 0x38);
                  uVar3 = *(undefined8 *)(lVar14 + 0x40);
                  *(undefined8 *)(lVar16 + 0x28) = *(undefined8 *)(lVar14 + 0x28);
                  *(undefined8 *)(lVar16 + 0x30) = uVar2;
                  *(undefined8 *)(lVar16 + 0x38) = uVar10;
                  *(undefined8 *)(lVar16 + 0x40) = uVar3;
                } while (uVar15 * 4 != lVar9);
              }
            }
          }
          uVar6 = 0;
          goto LAB_00102ca8;
        }
      }
      _dev_err(*plVar18,"No ramp configuration for any LPG\n");
      uVar6 = 0xffffffea;
      goto LAB_00102ca8;
    }
    pcVar12 = "Get qcom,lut-patterns failed, rc=%d\n";
  }
LAB_00102d30:
  _dev_err(lVar9,pcVar12,uVar6);
LAB_00102ca8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// qpnp_lpg_pwm_apply @ 00102e80 size=4828
// signature: undefined qpnp_lpg_pwm_apply(void)
// callers: [pwm_restore]
//------------------------------------------------------------

int qpnp_lpg_pwm_apply(undefined8 param_1,long param_2,ulong *param_3)

{
  long *plVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  ushort uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  char cVar16;
  undefined1 uVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  uint *puVar21;
  code *pcVar22;
  bool bVar23;
  int iVar24;
  ulong uVar25;
  undefined8 uVar26;
  char *pcVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  long lVar31;
  undefined4 uVar32;
  ulong *puVar33;
  ulong uVar34;
  ulong uVar35;
  uint uVar36;
  ulong uVar37;
  ulong uVar38;
  ulong uVar39;
  ulong uVar40;
  ulong uVar41;
  long lVar42;
  ulong uVar43;
  ulong uVar44;
  uint uVar45;
  int iVar46;
  long lVar47;
  undefined8 *puVar48;
  char *pcVar49;
  uint *puVar50;
  long *plVar51;
  ulong uVar52;
  int *piVar53;
  ulong uVar54;
  ulong local_190;
  uint local_170 [4];
  long local_160 [32];
  
  lVar47 = sp_el0;
  local_160[0x1e] = *(long *)(lVar47 + 0x638);
  uVar13 = *param_3;
  uVar14 = param_3[1];
  if ((uVar13 != *(ulong *)(param_2 + 0x38)) || (uVar14 != *(ulong *)(param_2 + 0x40))) {
    puVar48 = *(undefined8 **)(param_2 + 0x18);
    uVar45 = *(uint *)(param_2 + 0x10);
    uVar43 = (ulong)uVar45;
    uVar36 = *(uint *)(puVar48 + 0x17);
    if (uVar45 < uVar36) {
      lVar47 = puVar48[0xb];
      plVar51 = (long *)(lVar47 + uVar43 * 0x70);
      if (plVar51 != (long *)0x0) {
        if (uVar13 < uVar14) {
          _dev_err(*(undefined8 *)(*plVar51 + 0x50),"Duty %lluns is larger than period %lluns\n",
                   uVar14,uVar13);
          iVar24 = -0x16;
          goto LAB_0010400c;
        }
        puVar33 = (ulong *)(lVar47 + (ulong)uVar45 * 0x70 + 0x60);
        uVar37 = *puVar33;
        if (uVar37 == uVar13) {
LAB_0010327c:
          if (*(ulong *)(lVar47 + uVar43 * 0x70 + 0x68) == uVar14) {
            pcVar49 = (char *)(lVar47 + uVar43 * 0x70 + 0x5f);
            if (*pcVar49 != '\0') goto LAB_001032b4;
LAB_00103334:
            iVar24 = qpnp_lpg_set_pwm_config(plVar51);
            if (-1 < iVar24) {
LAB_00103c08:
              *(ulong *)(lVar47 + uVar43 * 0x70 + 0x68) = uVar14;
              *puVar33 = uVar13;
              *(ulong *)(param_2 + 0x40) = param_3[1];
              *(ulong *)(param_2 + 0x38) = *param_3;
              goto LAB_00103c34;
            }
          }
          else {
LAB_001032a4:
            pcVar49 = (char *)(lVar47 + uVar43 * 0x70 + 0x5f);
            if (*pcVar49 == '\0') {
              lVar42 = lVar47 + uVar43 * 0x70;
              uVar36 = *(uint *)(lVar42 + 8);
              uVar45 = -1 << (ulong)(uVar36 & 0x1f);
              uVar18 = 0;
              if (uVar13 != 0) {
                uVar18 = (uint)((uVar14 << ((ulong)uVar36 & 0x3f)) / uVar13);
              }
              uVar12 = (ushort)uVar18;
              if ((~uVar45 & 0xffff) < (uVar18 & 0xffff)) {
                uVar12 = ~(ushort)uVar45;
              }
              *(ushort *)(lVar42 + 0x18) = uVar12;
              goto LAB_00103334;
            }
LAB_001032b4:
            lVar42 = lVar47 + uVar43 * 0x70;
            cVar16 = *(char *)(lVar42 + 0x5d);
            iVar24 = *(int *)(lVar42 + 0xc);
            if (cVar16 == '\f') {
              if (iVar24 == 0x400) goto LAB_001032fc;
              if (iVar24 == 0x8000) goto LAB_00103ab4;
              if (iVar24 != 76800000) goto LAB_00103a9c;
              uVar26 = 4;
LAB_00103ab8:
              uVar36 = *(uint *)(lVar47 + uVar43 * 0x70 + 0x14);
              if (7 < uVar36) goto LAB_00103e78;
              uVar32 = 7;
              if (cVar16 != '\f') {
                uVar32 = 3;
              }
              mutex_lock(3,*plVar51 + 0x68);
              piVar53 = (int *)(lVar47 + uVar43 * 0x70 + 0x50);
              iVar24 = regmap_update_bits_base
                                 (*(undefined8 *)(*plVar51 + 0x48),*piVar53 + 0x41,uVar32,uVar26,0,0
                                  ,0);
              if (iVar24 < 0) {
                _dev_err(*(undefined8 *)(*plVar51 + 0x50),
                         "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                         *piVar53 + 0x41,uVar26,uVar32,iVar24);
                mutex_unlock(*plVar51 + 0x68);
                lVar42 = *plVar51;
                pcVar27 = "Write LPG_PWM_SIZE_CLK failed, rc=%d\n";
LAB_00103f88:
                _dev_err(*(undefined8 *)(lVar42 + 0x50),pcVar27,iVar24);
                goto LAB_00103f9c;
              }
              mutex_unlock(*plVar51 + 0x68);
              mutex_lock(*plVar51 + 0x68);
              iVar24 = regmap_update_bits_base
                                 (*(undefined8 *)(*plVar51 + 0x48),*piVar53 + 0x42,7,uVar36,0,0,0);
              if (iVar24 < 0) {
                _dev_err(*(undefined8 *)(*plVar51 + 0x50),
                         "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                         *piVar53 + 0x42,uVar36,7,iVar24);
                mutex_unlock(*plVar51 + 0x68);
                lVar42 = *plVar51;
                pcVar27 = "Write LPG_PWM_FREQ_PREDIV_CLK failed, rc=%d\n";
                goto LAB_00103f88;
              }
              mutex_unlock(*plVar51 + 0x68);
              uVar17 = *(undefined1 *)(lVar47 + uVar43 * 0x70 + 0x18);
              mutex_lock(*plVar51 + 0x68);
              iVar24 = regmap_update_bits_base
                                 (*(undefined8 *)(*plVar51 + 0x48),*piVar53 + 0x44,0xff,uVar17,0,0,0
                                 );
              if (iVar24 < 0) {
                _dev_err(*(undefined8 *)(*plVar51 + 0x50),
                         "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",
                         *piVar53 + 0x44,uVar17,0xff,iVar24);
                mutex_unlock(*plVar51 + 0x68);
                lVar42 = *plVar51;
                pcVar27 = "Write LPG_PWM_VALUE_LSB failed, rc=%d\n";
                goto LAB_00103f88;
              }
              mutex_unlock(*plVar51 + 0x68);
              mutex_lock(*plVar51 + 0x68);
              iVar24 = regmap_write(*(undefined8 *)(*plVar51 + 0x48),*piVar53 + 0x47,1);
              if (iVar24 < 0) {
                _dev_err(*(undefined8 *)(*plVar51 + 0x50),
                         "Write addr 0x%x with value 0x%x failed, rc=%d\n",*piVar53 + 0x47,1,iVar24)
                ;
                mutex_unlock(*plVar51 + 0x68);
                lVar42 = *plVar51;
                pcVar27 = "Write LPG_PWM_SYNC failed, rc=%d\n";
                goto LAB_00103f88;
              }
              mutex_unlock(*plVar51 + 0x68);
              goto LAB_00103c08;
            }
            if (iVar24 == 0x400) {
LAB_001032fc:
              uVar26 = 1;
              goto LAB_00103ab8;
            }
            if (iVar24 == 0x8000) {
LAB_00103ab4:
              uVar26 = 2;
              goto LAB_00103ab8;
            }
LAB_00103a9c:
            if (iVar24 == 19200000) {
              uVar26 = 3;
              goto LAB_00103ab8;
            }
LAB_00103e78:
            iVar24 = -0x16;
          }
LAB_00103f9c:
          puVar11 = &DAT_00105316;
          if (*pcVar49 != '\0') {
            puVar11 = &DAT_0010541a;
          }
          _dev_err(*(undefined8 *)(*plVar51 + 0x50),"Config %s failed for channel %d, rc=%d\n",
                   puVar11,*(undefined4 *)(lVar47 + uVar43 * 0x70 + 0x4c),iVar24);
          goto LAB_0010400c;
        }
        if (*(char *)(lVar47 + (ulong)uVar45 * 0x70 + 0x5f) != '\0') {
          lVar42 = lVar47 + uVar43 * 0x70;
          iVar24 = 0;
          uVar39 = 0;
          uVar36 = 0;
          iVar46 = 0;
          cVar16 = *(char *)(lVar42 + 0x5d);
          plVar1 = (long *)(lVar42 + 0x20);
          uVar8 = 0x10;
          if (cVar16 != '\f') {
            uVar8 = 0xc;
          }
          puVar9 = clk_period_ns_hi_res;
          if (cVar16 != '\f') {
            puVar9 = (undefined1 *)&clk_period_ns;
          }
          uVar45 = 0xffffffea;
          uVar25 = 0xffffffffffffffff;
          do {
            if ((uVar8 == uVar39) || (uVar8 <= uVar39)) goto LAB_00103dd8;
            uVar18 = *(uint *)((long)puVar9 + uVar39);
            lVar42 = (long)(int)uVar18;
            uVar44 = 0;
            if ((ulong)uVar18 != 0) {
              uVar44 = uVar13 / uVar18;
            }
            uVar18 = (int)(uVar44 >> 1) - 1;
            if (uVar18 < 0x100) {
              lVar31 = (uVar44 & 0x1fffffffe) * lVar42;
              uVar28 = uVar13 - lVar31;
              uVar29 = -uVar28;
              if (-1 < (long)uVar28) {
                uVar29 = uVar28;
              }
              if (uVar29 < uVar25) {
                uVar36 = 0;
                *plVar1 = lVar31;
                uVar25 = uVar29;
                iVar46 = iVar24;
                uVar45 = uVar18;
              }
            }
            else {
              uVar29 = 0xffffffffffffffff;
            }
            uVar18 = (int)(uVar44 >> 2) - 1;
            if (uVar18 < 0x100) {
              lVar31 = (uVar44 & 0x3fffffffc) * lVar42;
              uVar35 = uVar13 - lVar31;
              uVar28 = -uVar35;
              if (-1 < (long)uVar35) {
                uVar28 = uVar35;
              }
              if (uVar28 < uVar25) {
                uVar36 = 1;
                *plVar1 = lVar31;
                uVar25 = uVar28;
                iVar46 = iVar24;
                uVar45 = uVar18;
              }
              if (uVar28 <= uVar29) goto LAB_00103040;
            }
            else {
              uVar28 = uVar29;
LAB_00103040:
              uVar18 = (int)(uVar44 >> 3) - 1;
              if (uVar18 < 0x100) {
                lVar31 = (uVar44 & 0x7fffffff8) * lVar42;
                uVar35 = uVar13 - lVar31;
                uVar29 = -uVar35;
                if (-1 < (long)uVar35) {
                  uVar29 = uVar35;
                }
                if (uVar29 < uVar25) {
                  uVar36 = 2;
                  *plVar1 = lVar31;
                  uVar25 = uVar29;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
                if (uVar28 < uVar29) goto LAB_00102f80;
              }
              else {
                uVar29 = uVar28;
              }
              uVar18 = (int)(uVar44 >> 4) - 1;
              if (uVar18 < 0x100) {
                lVar31 = (uVar44 & 0xffffffff0) * lVar42;
                uVar35 = uVar13 - lVar31;
                uVar28 = -uVar35;
                if (-1 < (long)uVar35) {
                  uVar28 = uVar35;
                }
                if (uVar28 < uVar25) {
                  uVar36 = 3;
                  *plVar1 = lVar31;
                  uVar25 = uVar28;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
                if (uVar29 < uVar28) goto LAB_00102f80;
              }
              else {
                uVar28 = uVar29;
              }
              uVar18 = (int)(uVar44 >> 5) - 1;
              if (uVar18 < 0x100) {
                lVar31 = (uVar44 & 0x1fffffffe0) * lVar42;
                uVar35 = uVar13 - lVar31;
                uVar29 = -uVar35;
                if (-1 < (long)uVar35) {
                  uVar29 = uVar35;
                }
                if (uVar29 < uVar25) {
                  uVar36 = 4;
                  *plVar1 = lVar31;
                  uVar25 = uVar29;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
                if (uVar28 < uVar29) goto LAB_00102f80;
              }
              else {
                uVar29 = uVar28;
              }
              uVar18 = (int)(uVar44 >> 6) - 1;
              if (uVar18 < 0x100) {
                lVar31 = (uVar44 & 0x3fffffffc0) * lVar42;
                uVar35 = uVar13 - lVar31;
                uVar28 = -uVar35;
                if (-1 < (long)uVar35) {
                  uVar28 = uVar35;
                }
                if (uVar28 < uVar25) {
                  uVar36 = 5;
                  *plVar1 = lVar31;
                  uVar25 = uVar28;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
                if (uVar29 < uVar28) goto LAB_00102f80;
              }
              else {
                uVar28 = uVar29;
              }
              uVar18 = (int)(uVar44 >> 7) - 1;
              if (uVar18 < 0x100) {
                lVar31 = (uVar44 & 0x7fffffff80) * lVar42;
                uVar35 = uVar13 - lVar31;
                uVar29 = -uVar35;
                if (-1 < (long)uVar35) {
                  uVar29 = uVar35;
                }
                if (uVar29 < uVar25) {
                  uVar36 = 6;
                  *plVar1 = lVar31;
                  uVar25 = uVar29;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
                if (uVar28 < uVar29) goto LAB_00102f80;
              }
              uVar18 = (int)(uVar44 >> 8) - 1;
              if (uVar18 < 0x100) {
                lVar42 = (uVar44 & 0xffffffff00) * lVar42;
                uVar29 = uVar13 - lVar42;
                uVar44 = -uVar29;
                if (-1 < (long)uVar29) {
                  uVar44 = uVar29;
                }
                if (uVar44 < uVar25) {
                  uVar36 = 7;
                  *plVar1 = lVar42;
                  uVar25 = uVar44;
                  iVar46 = iVar24;
                  uVar45 = uVar18;
                }
              }
            }
LAB_00102f80:
            uVar39 = uVar39 + 4;
            iVar24 = iVar24 + 1;
          } while (uVar8 != uVar39);
          if ((int)uVar45 < 0) {
            _printk(&DAT_00104cfe,"__qpnp_lpg_calc_pfm_period",uVar13);
            iVar24 = -0x16;
            goto LAB_0010400c;
          }
          if (uVar8 <= (ulong)((long)iVar46 * 4)) {
LAB_00103dd8:
                    /* WARNING: Does not return */
            pcVar22 = (code *)SoftwareBreakpoint(1,0x103ddc);
            (*pcVar22)();
          }
          uVar39 = 0x10;
          if (cVar16 != '\f') {
            uVar39 = 0xc;
          }
          if (uVar39 <= (ulong)((long)iVar46 * 4)) goto LAB_00103dd8;
          puVar9 = &clk_freq_hz_hi_res;
          if (cVar16 != '\f') {
            puVar9 = &clk_freq_hz;
          }
          *(undefined4 *)(lVar47 + uVar43 * 0x70 + 0xc) = *(undefined4 *)(puVar9 + (long)iVar46 * 4)
          ;
          if (7 < uVar36) goto LAB_00103dd8;
          lVar42 = lVar47 + uVar43 * 0x70;
          uVar32 = *(undefined4 *)(pwm_exponent + (ulong)uVar36 * 4);
          *(short *)(lVar42 + 0x18) = (short)uVar45;
          *(undefined4 *)(lVar42 + 0x14) = uVar32;
LAB_00103274:
          if (uVar37 == uVar13) goto LAB_0010327c;
          goto LAB_001032a4;
        }
        lVar42 = lVar47 + (ulong)uVar45 * 0x70;
        uVar39 = 0xffffffffffffffff;
        local_160[0x1c] = 0;
        local_160[0x1d] = 0;
        bVar23 = *(char *)(lVar42 + 0x5d) == '\f';
        puVar10 = (undefined4 *)&pwm_hi_res_size;
        if (!bVar23) {
          puVar10 = &pwm_size;
        }
        uVar8 = 3;
        if (bVar23) {
          uVar8 = 4;
        }
        uVar25 = 0x20;
        if (!bVar23) {
          uVar25 = 8;
        }
        puVar9 = &clk_freq_hz_hi_res;
        if (!bVar23) {
          puVar9 = &clk_freq_hz;
        }
        uVar44 = (ulong)*(byte *)(*plVar51 + 200);
        local_160[0x1a] = 0;
        local_160[0x1b] = 0;
        uVar29 = 0x10;
        if (!bVar23) {
          uVar29 = 0xc;
        }
        puVar21 = (uint *)(lVar42 + 8);
        local_160[0x18] = 0;
        local_160[0x19] = 0;
        local_160[0x16] = 0;
        local_160[0x17] = 0;
        uVar28 = 8;
        if (!bVar23 || uVar44 != 0) {
          uVar28 = 2;
        }
        local_160[0x14] = 0;
        local_160[0x15] = 0;
        local_160[0x12] = 0;
        local_160[0x13] = 0;
        local_160[0x10] = 0;
        local_160[0x11] = 0;
        local_160[0xe] = 0;
        local_160[0xf] = 0;
        local_160[0xc] = 0;
        local_160[0xd] = 0;
        local_160[10] = 0;
        local_160[0xb] = 0;
        local_160[8] = 0;
        local_160[9] = 0;
        local_160[6] = 0;
        local_160[7] = 0;
        local_160[4] = 0;
        local_160[5] = 0;
        local_160[2] = 0;
        local_160[3] = 0;
        local_160[0] = 0;
        local_160[1] = 0;
        local_190 = 0xffffffffffffffff;
        local_170[0] = 0;
        local_170[1] = 0;
        local_170[2] = 0;
        local_170[3] = 0;
        do {
          if ((uVar25 <= uVar44 * 4) || (uVar25 <= uVar44 * 4)) goto LAB_00103dd8;
          uVar36 = puVar10[uVar44];
          uVar34 = uVar44 * 0x20;
          puVar4 = local_170 + uVar44 * 8;
          uVar35 = uVar44 << 5 | 4;
          uVar5 = uVar44 << 5 | 8;
          puVar50 = (uint *)((ulong)puVar4 | 4);
          puVar3 = local_170 + uVar44 * 8 + 2;
          uVar54 = uVar13 >> ((ulong)uVar36 & 0x3f);
          uVar6 = uVar44 << 5 | 0xc;
          puVar2 = (undefined4 *)((long)local_160 + (uVar34 - 4));
          uVar7 = uVar44 << 5 | 0x18;
          plVar1 = local_160 + uVar44 * 4 + 1;
          uVar40 = uVar8;
          do {
            uVar52 = uVar40 - 1 & 0xffffffff;
            uVar38 = 0;
            uVar41 = uVar52 * 4;
            do {
              if (uVar38 == 4) goto LAB_001040e8;
              if ((((uVar38 & 0x3fffffffffffffff) == 4) || (uVar29 <= uVar41)) || (uVar29 <= uVar41)
                 ) goto LAB_00103dd8;
              uVar45 = *(uint *)(puVar9 + uVar52 * 4);
              uVar18 = (&clk_prediv)[uVar38];
              uVar20 = 0;
              if (uVar45 != 0) {
                uVar20 = 1000000000 / uVar45;
              }
              uVar30 = uVar54 - (long)(int)uVar20 * (long)(int)uVar18;
              uVar19 = -uVar30;
              if (-1 < (long)uVar30) {
                uVar19 = uVar30;
              }
              if (uVar19 < uVar39) {
                if (7 < uVar44) goto LAB_001040e8;
                if (((((0x100 < uVar35) || (0x100 < uVar35)) ||
                     ((*puVar50 = uVar45, 0x100 < uVar5 ||
                      ((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)))))) || (0x100 < uVar6))
                   || ((((*puVar2 = 0, 0xff < uVar34 || (0xff < uVar34)) ||
                        (*puVar4 = uVar36, 0x100 < uVar7)) || (0x100 < uVar7)))) goto LAB_00103dd8;
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                uVar39 = uVar54 + lVar31 * -2;
                *plVar1 = (long)(int)uVar20 * (long)(int)uVar18;
                uVar30 = -uVar39;
                if (-1 < (long)uVar39) {
                  uVar30 = uVar39;
                }
                uVar39 = uVar19;
                if (uVar30 < uVar19) {
                  if (((uVar35 < 0x101) && (*puVar50 = uVar45, uVar5 < 0x101)) &&
                     ((*puVar3 = uVar18, uVar6 < 0x101 && (*puVar2 = 1, uVar34 < 0x100)))) {
                    *puVar4 = uVar36;
                    goto LAB_0010364c;
                  }
                  goto LAB_00103dd8;
                }
              }
              else {
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                uVar19 = uVar54 + lVar31 * -2;
                uVar30 = -uVar19;
                if (-1 < (long)uVar19) {
                  uVar30 = uVar19;
                }
                if (uVar30 < uVar39) {
                  if (7 < uVar44) goto LAB_001040e8;
                  if ((((0x100 < uVar35) || (0x100 < uVar35)) ||
                      ((*puVar50 = uVar45, 0x100 < uVar5 ||
                       (((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)) || (0x100 < uVar6)))))
                      ) || (((*puVar2 = 1, 0xff < uVar34 || (0xff < uVar34)) ||
                            (*puVar4 = uVar36, 0x100 < uVar7)))) goto LAB_00103dd8;
LAB_0010364c:
                  if (0x100 < uVar7) goto LAB_00103dd8;
                  *plVar1 = lVar31 * 2;
                  uVar39 = uVar30;
                }
              }
              uVar30 = uVar54 + (long)(int)uVar18 * (long)(int)uVar20 * -4;
              uVar19 = -uVar30;
              if (-1 < (long)uVar30) {
                uVar19 = uVar30;
              }
              if (uVar19 < uVar39) {
                if (7 < uVar44) goto LAB_001040e8;
                if ((((0x100 < uVar35) || (0x100 < uVar35)) ||
                    ((*puVar50 = uVar45, 0x100 < uVar5 ||
                     (((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)) || (0x100 < uVar6))))))
                   || (((*puVar2 = 2, 0xff < uVar34 || (0xff < uVar34)) ||
                       ((*puVar4 = uVar36, 0x100 < uVar7 || (0x100 < uVar7)))))) goto LAB_00103dd8;
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                *plVar1 = (long)(int)uVar18 * (long)(int)uVar20 * 4;
                uVar39 = uVar54 + lVar31 * -8;
                uVar30 = -uVar39;
                if (-1 < (long)uVar39) {
                  uVar30 = uVar39;
                }
                uVar39 = uVar19;
                if (uVar30 < uVar19) {
                  if (((uVar35 < 0x101) && (*puVar50 = uVar45, uVar5 < 0x101)) &&
                     ((*puVar3 = uVar18, uVar6 < 0x101 && (*puVar2 = 3, uVar34 < 0x100)))) {
                    *puVar4 = uVar36;
                    goto LAB_00103794;
                  }
                  goto LAB_00103dd8;
                }
              }
              else {
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                uVar19 = uVar54 + lVar31 * -8;
                uVar30 = -uVar19;
                if (-1 < (long)uVar19) {
                  uVar30 = uVar19;
                }
                if (uVar30 < uVar39) {
                  if (7 < uVar44) goto LAB_001040e8;
                  if (((((((0x100 < uVar35) || (0x100 < uVar35)) ||
                         (*puVar50 = uVar45, 0x100 < uVar5)) ||
                        ((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)))) || (0x100 < uVar6))
                      || ((*puVar2 = 3, 0xff < uVar34 || (0xff < uVar34)))) ||
                     (*puVar4 = uVar36, 0x100 < uVar7)) goto LAB_00103dd8;
LAB_00103794:
                  if (0x100 < uVar7) goto LAB_00103dd8;
                  *plVar1 = lVar31 * 8;
                  uVar39 = uVar30;
                }
              }
              uVar30 = uVar54 + (long)(int)uVar18 * (long)(int)uVar20 * -0x10;
              uVar19 = -uVar30;
              if (-1 < (long)uVar30) {
                uVar19 = uVar30;
              }
              if (uVar19 < uVar39) {
                if (7 < uVar44) goto LAB_001040e8;
                if (((((0x100 < uVar35) || (0x100 < uVar35)) || (*puVar50 = uVar45, 0x100 < uVar5))
                    || (((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)) ||
                        ((0x100 < uVar6 || ((*puVar2 = 4, 0xff < uVar34 || (0xff < uVar34)))))))) ||
                   ((*puVar4 = uVar36, 0x100 < uVar7 || (0x100 < uVar7)))) goto LAB_00103dd8;
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                *plVar1 = (long)(int)uVar18 * (long)(int)uVar20 * 0x10;
                uVar39 = uVar54 + lVar31 * -0x20;
                uVar30 = -uVar39;
                if (-1 < (long)uVar39) {
                  uVar30 = uVar39;
                }
                uVar39 = uVar19;
                if (uVar30 < uVar19) {
                  if ((((uVar35 < 0x101) && (*puVar50 = uVar45, uVar5 < 0x101)) &&
                      (*puVar3 = uVar18, uVar6 < 0x101)) && (*puVar2 = 5, uVar34 < 0x100)) {
                    *puVar4 = uVar36;
                    goto LAB_001038dc;
                  }
                  goto LAB_00103dd8;
                }
              }
              else {
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                uVar19 = uVar54 + lVar31 * -0x20;
                uVar30 = -uVar19;
                if (-1 < (long)uVar19) {
                  uVar30 = uVar19;
                }
                if (uVar30 < uVar39) {
                  if (7 < uVar44) goto LAB_001040e8;
                  if (((0x100 < uVar35) || (0x100 < uVar35)) ||
                     (((*puVar50 = uVar45, 0x100 < uVar5 ||
                       ((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)))) ||
                      ((0x100 < uVar6 ||
                       (((*puVar2 = 5, 0xff < uVar34 || (0xff < uVar34)) ||
                        (*puVar4 = uVar36, 0x100 < uVar7)))))))) goto LAB_00103dd8;
LAB_001038dc:
                  if (0x100 < uVar7) goto LAB_00103dd8;
                  *plVar1 = lVar31 * 0x20;
                  uVar39 = uVar30;
                }
              }
              uVar30 = uVar54 + (long)(int)uVar18 * (long)(int)uVar20 * -0x40;
              uVar19 = -uVar30;
              if (-1 < (long)uVar30) {
                uVar19 = uVar30;
              }
              if (uVar19 < uVar39) {
                if (7 < uVar44) goto LAB_001040e8;
                if (((((0x100 < uVar35) || (0x100 < uVar35)) ||
                     ((*puVar50 = uVar45, 0x100 < uVar5 ||
                      ((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)))))) || (0x100 < uVar6))
                   || ((((*puVar2 = 6, 0xff < uVar34 || (0xff < uVar34)) ||
                        (*puVar4 = uVar36, 0x100 < uVar7)) || (0x100 < uVar7)))) goto LAB_00103dd8;
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                *plVar1 = (long)(int)uVar18 * (long)(int)uVar20 * 0x40;
                uVar39 = uVar54 + lVar31 * -0x80;
                uVar30 = -uVar39;
                if (-1 < (long)uVar39) {
                  uVar30 = uVar39;
                }
                uVar39 = uVar19;
                if (uVar30 < uVar19) {
                  if (((uVar35 < 0x101) && (*puVar50 = uVar45, uVar5 < 0x101)) &&
                     ((*puVar3 = uVar18, uVar6 < 0x101 &&
                      ((*puVar2 = 7, uVar34 < 0x100 && (*puVar4 = uVar36, uVar7 < 0x101))))))
                  goto LAB_001034c4;
                  goto LAB_00103dd8;
                }
              }
              else {
                lVar31 = (long)(int)uVar18 * (long)(int)uVar20;
                uVar19 = uVar54 + lVar31 * -0x80;
                uVar30 = -uVar19;
                if (-1 < (long)uVar19) {
                  uVar30 = uVar19;
                }
                if (uVar30 < uVar39) {
                  if (7 < uVar44) goto LAB_001040e8;
                  if (((((0x100 < uVar35) || (0x100 < uVar35)) || (*puVar50 = uVar45, 0x100 < uVar5)
                       ) || (((0x100 < uVar5 || (*puVar3 = uVar18, 0x100 < uVar6)) ||
                             ((0x100 < uVar6 || ((*puVar2 = 7, 0xff < uVar34 || (0xff < uVar34))))))
                            )) || ((*puVar4 = uVar36, 0x100 < uVar7 || (0x100 < uVar7))))
                  goto LAB_00103dd8;
LAB_001034c4:
                  *plVar1 = lVar31 * 0x80;
                  uVar39 = uVar30;
                }
              }
              uVar38 = uVar38 + 1;
            } while (uVar8 != uVar38);
            bVar23 = 1 < (long)uVar40;
            uVar40 = uVar40 - 1;
          } while (bVar23);
          if (uVar44 == 8) {
LAB_001040e8:
                    /* WARNING: Does not return */
            pcVar22 = (code *)SoftwareBreakpoint(0x5512,0x1040ec);
            (*pcVar22)();
          }
          if ((0x100 < uVar7) || (0x100 < uVar7)) goto LAB_00103dd8;
          uVar35 = uVar39 << ((ulong)uVar36 & 0x3f);
          *plVar1 = *plVar1 * (long)(1 << (ulong)(uVar36 & 0x1f));
          if (uVar35 < local_190) {
            uVar26 = *(undefined8 *)(local_170 + uVar44 * 8 + 2);
            lVar31 = local_160[uVar44 * 4];
            lVar15 = local_160[uVar44 * 4 + 1];
            *(undefined8 *)puVar21 = *(undefined8 *)puVar4;
            *(undefined8 *)(lVar42 + 0x10) = uVar26;
            *(long *)(lVar42 + 0x18) = lVar31;
            *(long *)(lVar42 + 0x20) = lVar15;
            local_190 = uVar35;
          }
          uVar44 = uVar44 + 1;
        } while (uVar44 != uVar28);
        uVar36 = *puVar21;
        puVar3 = (uint *)(lVar47 + uVar43 * 0x70 + 0x14);
        lVar42 = uVar28 + 1;
        do {
          uVar39 = (ulong)((int)lVar42 - 2);
          if ((uVar25 <= uVar39 * 4) || (uVar25 <= uVar39 * 4)) goto LAB_00103dd8;
          uVar45 = puVar10[uVar39];
          uVar18 = uVar45 - uVar36;
          if (uVar45 < uVar36 || uVar18 == 0) break;
          uVar20 = *puVar3;
          if (uVar18 <= uVar20) {
            *puVar3 = uVar20 - uVar18;
            *puVar21 = uVar45;
            uVar36 = uVar45;
          }
          lVar42 = lVar42 + -1;
        } while (2 < lVar42);
        if (*(char *)(lVar47 + uVar43 * 0x70 + 0x5c) != '\0') goto LAB_00103274;
        lVar42 = lVar47 + uVar43 * 0x70;
        iVar24 = qpnp_lpg_set_lut_pattern
                           (plVar51,*(undefined8 *)(lVar42 + 0x38),*(undefined4 *)(lVar42 + 0x40));
        if (-1 < iVar24) {
          uVar37 = *puVar33;
          *(undefined1 *)(lVar47 + uVar43 * 0x70 + 0x5e) = 1;
          goto LAB_00103274;
        }
        pcVar49 = "set LUT pattern failed for LPG%d, rc=%d\n";
        lVar47 = lVar47 + uVar43 * 0x70;
        uVar26 = *(undefined8 *)(*plVar51 + 0x50);
LAB_00103d04:
        _dev_err(uVar26,pcVar49,*(undefined4 *)(lVar47 + 0x4c),iVar24);
        goto LAB_0010400c;
      }
    }
    else {
      uVar26 = puVar48[10];
LAB_00103ff4:
      _dev_err(uVar26,"hw index %d out of range [0-%d]\n",uVar45,uVar36 - 1);
    }
LAB_00103ff8:
    _dev_err(*puVar48,"lpg not found\n");
    iVar24 = -0x13;
    goto LAB_0010400c;
  }
LAB_00103c34:
  if (*(char *)((long)param_3 + 0x14) == *(char *)(param_2 + 0x4c)) {
    iVar24 = 0;
    goto LAB_0010400c;
  }
  puVar48 = *(undefined8 **)(param_2 + 0x18);
  uVar45 = *(uint *)(param_2 + 0x10);
  uVar36 = *(uint *)(puVar48 + 0x17);
  if (*(char *)((long)param_3 + 0x14) != '\0') {
    if (uVar36 <= uVar45) {
      uVar26 = puVar48[10];
      goto LAB_00103ff4;
    }
    lVar47 = puVar48[0xb];
    plVar51 = (long *)(lVar47 + (ulong)uVar45 * 0x70);
    if (plVar51 == (long *)0x0) goto LAB_00103ff8;
    if (*(char *)(lVar47 + (ulong)uVar45 * 0x70 + 0x5c) == '\x01') {
      mutex_lock(*plVar51 + 0x68);
      piVar53 = (int *)(lVar47 + (ulong)uVar45 * 0x70 + 0x50);
      iVar24 = regmap_write(*(undefined8 *)(*plVar51 + 0x48),*piVar53 + 0x47,1);
      if (-1 < iVar24) {
        mutex_unlock(*plVar51 + 0x68);
        goto LAB_00103ccc;
      }
      _dev_err(*(undefined8 *)(*plVar51 + 0x50),"Write addr 0x%x with value 0x%x failed, rc=%d\n",
               *piVar53 + 0x47,1,iVar24);
      mutex_unlock(*plVar51 + 0x68);
      lVar47 = *plVar51;
      pcVar49 = "Write LPG_PWM_SYNC failed, rc=%d\n";
    }
    else {
LAB_00103ccc:
      iVar24 = qpnp_lpg_set_glitch_removal(plVar51,1);
      if (-1 < iVar24) {
        iVar24 = qpnp_lpg_pwm_src_enable(plVar51,1);
        if (iVar24 < 0) {
          uVar26 = *puVar48;
          pcVar49 = "Enable PWM output failed for channel %d, rc=%d\n";
          lVar47 = lVar47 + (ulong)uVar45 * 0x70;
          goto LAB_00103d04;
        }
        goto LAB_00103d50;
      }
      lVar47 = *plVar51;
      pcVar49 = "Enable glitch-removal failed, rc=%d\n";
    }
    _dev_err(*(undefined8 *)(lVar47 + 0x50),pcVar49,iVar24);
    goto LAB_0010400c;
  }
  if (uVar45 < uVar36) {
    lVar47 = puVar48[0xb];
    plVar51 = (long *)(lVar47 + (ulong)uVar45 * 0x70);
    if (plVar51 == (long *)0x0) goto LAB_00104094;
    iVar24 = qpnp_lpg_pwm_src_enable(plVar51,0);
    if (iVar24 < 0) {
      _dev_err(*puVar48,"Disable PWM output failed for channel %d, rc=%d\n",
               *(undefined4 *)(lVar47 + (ulong)uVar45 * 0x70 + 0x4c),iVar24);
    }
    else {
      iVar24 = qpnp_lpg_set_glitch_removal(plVar51,0);
      if (iVar24 < 0) {
        _dev_err(*(undefined8 *)(*plVar51 + 0x50),"Disable glitch-removal failed, rc=%d\n",iVar24);
      }
    }
  }
  else {
    _dev_err(puVar48[10],"hw index %d out of range [0-%d]\n",uVar45,uVar36 - 1);
LAB_00104094:
    _dev_err(*puVar48,"lpg not found\n");
  }
LAB_00103d50:
  iVar24 = 0;
  *(undefined1 *)(param_2 + 0x4c) = *(undefined1 *)((long)param_3 + 0x14);
LAB_0010400c:
  lVar47 = sp_el0;
  if (*(long *)(lVar47 + 0x638) != local_160[0x1e]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar24;
}



//------------------------------------------------------------
// qpnp_lpg_set_glitch_removal @ 0010415c size=212
// signature: undefined qpnp_lpg_set_glitch_removal(void)
// callers: [qpnp_lpg_pwm_apply]
//------------------------------------------------------------

int qpnp_lpg_set_glitch_removal(long *param_1,ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  mutex_lock(*param_1 + 0x68);
  uVar2 = 0x20;
  if ((param_2 & 1) == 0) {
    uVar2 = 0;
  }
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(*param_1 + 0x48),(int)param_1[10] + 0x43,0x20,uVar2,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(*param_1 + 0x50),
             "Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",(int)param_1[10] + 0x43,
             uVar2,0x20,iVar1);
    mutex_unlock(*param_1 + 0x68);
    _dev_err(*(undefined8 *)(*param_1 + 0x50),"Write LPG_PWM_TYPE_CONFIG failed, rc=%d\n",iVar1);
  }
  else {
    mutex_unlock(*param_1 + 0x68);
  }
  return iVar1;
}



//------------------------------------------------------------
// pwm_suspend @ 00104234 size=8
// signature: undefined pwm_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 pwm_suspend(void)

{
  return 0;
}



//------------------------------------------------------------
// pwm_resume @ 00104240 size=52
// signature: undefined pwm_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pwm_resume(void)

{
  undefined8 uVar1;
  
  if (_pm_suspend_target_state == 3) {
    uVar1 = pwm_restore();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// pwm_freeze @ 00104278 size=8
// signature: undefined pwm_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 pwm_freeze(void)

{
  return 0;
}



//------------------------------------------------------------
// pwm_restore @ 00104284 size=324
// signature: undefined pwm_restore(void)
// callers: [pwm_resume]
//------------------------------------------------------------

int pwm_restore(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  
  lVar7 = *(long *)(param_1 + 0x98);
  iVar1 = qpnp_lpg_pwm_apply(param_1,*(long *)(lVar7 + 0x38),*(long *)(lVar7 + 0x38) + 0x38);
  if (-1 < iVar1) {
    iVar1 = qpnp_lpg_sdam_hw_init(lVar7);
    if (iVar1 < 0) {
      uVar2 = *(undefined8 *)(lVar7 + 0x50);
      pcVar3 = "SDAM HW init failed, rc=%d\n";
LAB_001043bc:
      _dev_err(uVar2,pcVar3,iVar1);
    }
    else {
      if (*(int *)(lVar7 + 0xb8) != 0) {
        uVar4 = 0;
        do {
          lVar5 = *(long *)(lVar7 + 0x58);
          lVar6 = lVar5 + (long)(int)uVar4 * 0x70;
          *(undefined4 *)(lVar6 + 0x48) = 1;
          if (*(char *)(lVar6 + 0x5f) != '\0') {
            plVar8 = (long *)(lVar5 + (long)(int)uVar4 * 0x70);
            mutex_lock(*plVar8 + 0x68);
            iVar1 = regmap_write(*(undefined8 *)(*plVar8 + 0x48),(int)plVar8[10] + 0x50,0x80);
            if (iVar1 < 0) {
              _dev_err(*(undefined8 *)(*plVar8 + 0x50),
                       "Write addr 0x%x with value 0x%x failed, rc=%d\n",(int)plVar8[10] + 0x50,0x80
                       ,iVar1);
              mutex_unlock(*plVar8 + 0x68);
              uVar2 = *(undefined8 *)(lVar7 + 0x50);
              pcVar3 = "Write fm_mode_enable failed, rc=%d\n";
              goto LAB_001043bc;
            }
            mutex_unlock(*plVar8 + 0x68);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(lVar7 + 0xb8));
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00104414 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_lpg_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104444 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_lpg_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00107000 size=1
// signature: undefined mutex_lock(void)
// callers: [qpnp_lpg_sdam_hw_init, qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply, pwm_restore, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_glitch_removal, qpnp_lpg_set_pwm_config, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_write @ 00107008 size=1
// signature: undefined nvmem_device_write(void)
// callers: [qpnp_lpg_sdam_hw_init, qpnp_lpg_pwm_set_output_type, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107010 size=1
// signature: undefined mutex_unlock(void)
// callers: [qpnp_lpg_sdam_hw_init, qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply, pwm_restore, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_glitch_removal, qpnp_lpg_set_pwm_config, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_read @ 00107018 size=1
// signature: undefined nvmem_device_read(void)
// callers: [qpnp_lpg_pwm_set_output_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107020 size=1
// signature: undefined _printk(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_pwm_apply, qpnp_lpg_pwm_get_output_types_supported]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107028 size=1
// signature: undefined _dev_err(void)
// callers: [qpnp_lpg_sdam_hw_init, qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply, pwm_restore, qpnp_lpg_parse_pattern_dt, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_glitch_removal, qpnp_lpg_pwm_get_output_types_supported, qpnp_lpg_set_pwm_config, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00107030 size=1
// signature: undefined regmap_write(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply, pwm_restore, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_pwm_config, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00107038 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qpnp_lpg_pwm_set_output_type, qpnp_lpg_pwm_apply, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_glitch_removal, qpnp_lpg_set_pwm_config, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qpnp_lpg_sdam_hw_init, qpnp_lpg_pwm_set_output_type, qpnp_lpg_probe, qpnp_lpg_pwm_apply, qpnp_lpg_parse_pattern_dt, qpnp_lpg_pwm_src_enable, qpnp_lpg_set_lut_pattern]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107050 size=1
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
// platform_driver_unregister @ 00107058 size=1
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
// devm_kmalloc @ 00107060 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qpnp_lpg_probe, qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00107068 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00107070 size=1
// signature: undefined __mutex_init(void)
// callers: [qpnp_lpg_probe, qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00107078 size=1
// signature: undefined __of_get_address(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00107080 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_lpg_probe, qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00107088 size=1
// signature: undefined regmap_read(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00107090 size=1
// signature: undefined of_find_property(void)
// callers: [qpnp_lpg_probe, qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00107098 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qpnp_lpg_probe, qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001070a0 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_device_get @ 001070a8 size=1
// signature: undefined devm_nvmem_device_get(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001070b0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pwmchip_add @ 001070b8 size=1
// signature: undefined pwmchip_add(void)
// callers: [qpnp_lpg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pwmchip_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pwmchip_remove @ 001070c0 size=1
// signature: undefined pwmchip_remove(void)
// callers: [qpnp_lpg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pwmchip_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001070c8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qpnp_lpg_parse_pattern_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



