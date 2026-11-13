// Decompiled by Ghidra 12.2
// Program: qcom-dcvs.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_dcvs_update_votes @ 00101404 size=1448
// signature: undefined qcom_dcvs_update_votes(void)
// callers: []
//------------------------------------------------------------

int qcom_dcvs_update_votes
              (char *param_1,long param_2,uint param_3,ulong param_4,ulong param_5,ulong param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  long *plVar13;
  long *plVar14;
  bool bVar15;
  ulong uVar16;
  uint uVar17;
  uint *puVar18;
  ulong uVar19;
  uint local_b0 [2];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  iVar7 = (int)param_4;
  if (iVar7 == 2) {
    lVar8 = tpidr_el1;
    iVar6 = -0x16;
    uVar12 = *(uint *)(&cpu_number + lVar8);
    local_a8 = (ulong)local_a8._4_4_ << 0x20;
    local_b0[0] = 0;
    local_b0[1] = 0;
    if (((param_1 != (char *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
      uVar16 = 0;
      iVar6 = 0;
      uVar3 = sp_el0;
LAB_00101904:
      if ((param_3 >> (uVar16 & 0x3f) & 1) == 0) {
LAB_001018f8:
        uVar16 = uVar16 + 1;
        if (uVar16 == 6) goto LAB_00101a94;
        goto LAB_00101904;
      }
      if (dcvs_data != 0) {
        puVar18 = (uint *)(param_2 + uVar16 * 0xc);
        uVar17 = puVar18[2];
        if (5 < uVar17) goto LAB_00101b20;
        lVar8 = *(long *)(dcvs_data + (ulong)uVar17 * 8 + 0x60);
        if (((lVar8 != 0) && (lVar8 = *(long *)(lVar8 + 0xa0), lVar8 != 0)) &&
           ((puVar2 = (undefined8 *)(*(long *)(lVar8 + 0x30) + -0x18), puVar2 != (undefined8 *)0x0
            && (iVar7 = strcmp((char *)*puVar2,param_1), iVar7 == 0)))) {
          uVar10 = *puVar18;
          lVar9 = *(long *)(lVar8 + 0x10);
          uVar11 = uVar10;
          if ((*(int *)(lVar8 + 8) == 0) &&
             (uVar11 = *(uint *)(lVar9 + 0x88), *(uint *)(lVar9 + 0x88) <= uVar10)) {
            uVar11 = uVar10;
          }
          iVar5 = *(int *)(lVar9 + 0x78);
          iVar7 = 0;
          if (iVar5 == 0) {
            uVar10 = 0;
LAB_001019a8:
            if (iVar7 == iVar5) goto LAB_001019b0;
          }
          else {
            do {
              uVar10 = *(uint *)(*(long *)(lVar9 + 0x70) + (long)iVar7 * 4);
              if (uVar11 <= uVar10) goto LAB_001019a8;
              iVar7 = iVar7 + 1;
            } while (iVar5 != iVar7);
LAB_001019b0:
            uVar10 = *(uint *)(*(long *)(lVar9 + 0x70) + (ulong)(iVar5 - 1) * 4);
          }
          local_b0[0] = uVar10;
          local_a8 = CONCAT44(local_a8._4_4_,uVar17);
          if (uVar10 == *(uint *)(*(long *)(lVar8 + 0x28) + (ulong)uVar12 * 4)) goto LAB_001018f8;
          if (*(int *)(*(code **)(lVar8 + 0x80) + -4) != 0x1268cd6f) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1019f8);
            (*pcVar4)();
          }
          iVar6 = (**(code **)(lVar8 + 0x80))(lVar8,local_b0,1);
          if (iVar6 < 0) goto LAB_00101a94;
          goto LAB_001018f8;
        }
      }
      iVar6 = -0x16;
    }
  }
  else if (iVar7 == 1) {
    iVar6 = -0x16;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b0[0] = 0;
    local_b0[1] = 0;
    if (((param_1 != (char *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
      uVar16 = 0;
      lVar8 = 0;
      uVar12 = 0;
      uVar3 = sp_el0;
      do {
        uVar19 = 1L << (uVar16 & 0x3f);
        if ((uVar19 & param_3) != 0) {
          if (dcvs_data == 0) goto LAB_00101a84;
          puVar18 = (uint *)(param_2 + uVar16 * 0xc);
          uVar17 = puVar18[2];
          if (5 < uVar17) goto LAB_00101b20;
          lVar8 = *(long *)(dcvs_data + (ulong)uVar17 * 8 + 0x60);
          if (((lVar8 == 0) || (lVar8 = *(long *)(lVar8 + 0x98), lVar8 == 0 || uVar16 != uVar17)) ||
             ((puVar2 = (undefined8 *)(*(long *)(lVar8 + 0x30) + -0x18), puVar2 == (undefined8 *)0x0
              || (iVar7 = strcmp((char *)*puVar2,param_1), iVar7 != 0)))) goto LAB_00101a84;
          uVar11 = *puVar18;
          param_5 = (ulong)uVar11;
          lVar9 = *(long *)(lVar8 + 0x10);
          uVar17 = uVar11;
          if ((*(int *)(lVar8 + 8) == 0) &&
             (uVar17 = *(uint *)(lVar9 + 0x88), *(uint *)(lVar9 + 0x88) <= uVar11)) {
            uVar17 = uVar11;
          }
          iVar6 = *(int *)(lVar9 + 0x78);
          iVar7 = 0;
          if (iVar6 == 0) {
            uVar11 = 0;
LAB_001017d8:
            if (iVar7 == iVar6) goto LAB_001017e0;
          }
          else {
            do {
              uVar11 = *(uint *)(*(long *)(lVar9 + 0x70) + (long)iVar7 * 4);
              if (uVar17 <= uVar11) goto LAB_001017d8;
              iVar7 = iVar7 + 1;
            } while (iVar6 != iVar7);
LAB_001017e0:
            uVar11 = *(uint *)(*(long *)(lVar9 + 0x70) + (ulong)(iVar6 - 1) * 4);
          }
          param_6 = (ulong)uVar11;
          local_b0[uVar16 * 3] = uVar11;
          param_4 = (ulong)*(uint *)(lVar8 + 8);
          uVar17 = 0;
          if (uVar11 != *(uint *)(lVar8 + 0x18)) {
            uVar17 = (uint)uVar19;
          }
          uVar12 = uVar17 | uVar12;
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 != 6);
      if (uVar12 == 0) {
        iVar6 = 0;
      }
      else {
        if (*(int *)(*(code **)(lVar8 + 0x80) + -4) != 0x1268cd6f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101b0c);
          (*pcVar4)();
        }
        iVar6 = (**(code **)(lVar8 + 0x80))(lVar8,local_b0,uVar12,param_4,param_5,param_6);
      }
    }
  }
  else {
    iVar6 = -0x16;
    if (iVar7 == 0) {
      local_a8 = (ulong)local_a8._4_4_ << 0x20;
      local_b0[0] = 0;
      local_b0[1] = 0;
      if (((param_1 != (char *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
        uVar16 = 0;
        iVar6 = 0;
        uVar3 = sp_el0;
        do {
          if ((param_3 >> (uVar16 & 0x3f) & 1) != 0) {
            if (dcvs_data == 0) goto LAB_00101a84;
            puVar18 = (uint *)(param_2 + uVar16 * 0xc);
            uVar12 = puVar18[2];
            if (5 < uVar12) {
LAB_00101b20:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101b24);
              (*pcVar4)();
            }
            lVar8 = *(long *)(dcvs_data + (ulong)uVar12 * 8 + 0x60);
            if ((lVar8 == 0) || (lVar8 = *(long *)(lVar8 + 0x90), lVar8 == 0)) goto LAB_00101a84;
            mutex_lock();
            local_b0[0] = 0;
            local_b0[1] = 0;
            local_a8 = CONCAT44(local_a8._4_4_,uVar12);
            plVar14 = (long *)(lVar8 + 0x30);
            plVar13 = (long *)*plVar14;
            if (plVar13 != plVar14) {
              iVar7 = 0;
              uVar12 = 0;
              bVar15 = false;
              do {
                iVar5 = strcmp((char *)plVar13[-3],param_1);
                if (iVar5 == 0) {
                  uVar17 = *puVar18;
                  bVar15 = true;
                  *(uint *)(plVar13 + -2) = uVar17;
                  *(undefined4 *)((long)plVar13 + -0xc) =
                       *(undefined4 *)(param_2 + uVar16 * 0xc + 4);
                }
                else {
                  uVar17 = *(uint *)(plVar13 + -2);
                  local_b0[0] = uVar12;
                  local_b0[1] = iVar7;
                }
                uVar12 = uVar17;
                if (uVar17 <= local_b0[0]) {
                  uVar12 = local_b0[0];
                }
                iVar7 = *(int *)((long)plVar13 + -0xc) + local_b0[1];
                local_b0[1] = iVar7;
                local_b0[0] = uVar12;
                plVar13 = (long *)*plVar13;
              } while (plVar13 != plVar14);
              if (bVar15) {
                lVar9 = *(long *)(lVar8 + 0x10);
                uVar17 = uVar12;
                if ((*(int *)(lVar8 + 8) == 0) &&
                   (uVar17 = *(uint *)(lVar9 + 0x88), *(uint *)(lVar9 + 0x88) <= uVar12)) {
                  uVar17 = uVar12;
                }
                iVar1 = *(int *)(lVar9 + 0x78);
                iVar5 = 0;
                if (iVar1 == 0) {
                  local_b0[0] = 0;
LAB_001015c0:
                  if (iVar5 == iVar1) goto LAB_001015c8;
                }
                else {
                  do {
                    local_b0[0] = *(uint *)(*(long *)(lVar9 + 0x70) + (long)iVar5 * 4);
                    if (uVar17 <= local_b0[0]) goto LAB_001015c0;
                    iVar5 = iVar5 + 1;
                  } while (iVar1 != iVar5);
LAB_001015c8:
                  local_b0[0] = *(uint *)(*(long *)(lVar9 + 0x70) + (ulong)(iVar1 - 1) * 4);
                }
                if ((local_b0[0] != *(uint *)(lVar8 + 0x18)) || (iVar7 != *(int *)(lVar8 + 0x1c))) {
                  if (*(int *)(*(code **)(lVar8 + 0x80) + -4) != 0x1268cd6f) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101614);
                    (*pcVar4)();
                  }
                  iVar6 = (**(code **)(lVar8 + 0x80))(lVar8,local_b0,1);
                }
                mutex_unlock(lVar8 + 0x48);
                if (-1 < iVar6) goto LAB_00101488;
                break;
              }
            }
            mutex_unlock(lVar8 + 0x48);
            iVar6 = -0x16;
            break;
          }
LAB_00101488:
          uVar16 = uVar16 + 1;
        } while (uVar16 != 6);
      }
    }
  }
  goto LAB_00101a94;
LAB_00101a84:
  iVar6 = -0x16;
LAB_00101a94:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qcom_dcvs_register_voter @ 00101b2c size=320
// signature: undefined qcom_dcvs_register_voter(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_dcvs_register_voter(char *param_1,uint param_2,uint param_3)

{
  long *plVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined8 *puVar9;
  
  uVar7 = 0xffffffea;
  if (((param_1 != (char *)0x0) && (param_2 < 6)) && (param_3 < 3)) {
    if (*(char *)(dcvs_data + 0x98) == '\0') {
      uVar7 = 0xfffffdfb;
    }
    else {
      if (((dcvs_data != 0) &&
          (lVar5 = *(long *)(dcvs_data + (ulong)param_2 * 8 + 0x60), lVar5 != 0)) &&
         (lVar5 = *(long *)(lVar5 + (ulong)param_3 * 8 + 0x90), lVar5 != 0)) {
        mutex_lock(lVar5 + 0x48);
        if ((param_3 != 1) || (*(int *)(lVar5 + 0x40) == 0)) {
          plVar1 = (long *)(lVar5 + 0x30);
          plVar8 = plVar1;
          do {
            plVar8 = (long *)*plVar8;
            if (plVar8 == plVar1) {
              puVar3 = (undefined8 *)kmalloc_trace(_of_property_read_variable_u32_array,0xdc0,0x28);
              if (puVar3 == (undefined8 *)0x0) {
                uVar7 = 0xfffffff4;
              }
              else {
                puVar9 = puVar3 + 3;
                *puVar3 = param_1;
                puVar6 = *(undefined8 **)(lVar5 + 0x38);
                uVar4 = __list_add_valid(puVar9,puVar6,plVar1);
                if ((uVar4 & 1) != 0) {
                  *(undefined8 **)(lVar5 + 0x38) = puVar9;
                  puVar3[3] = plVar1;
                  puVar3[4] = puVar6;
                  *puVar6 = puVar9;
                }
                uVar7 = 0;
                *(int *)(lVar5 + 0x40) = *(int *)(lVar5 + 0x40) + 1;
              }
              goto LAB_00101c48;
            }
            iVar2 = strcmp((char *)plVar8[-3],param_1);
          } while (iVar2 != 0);
          uVar7 = 0xffffffea;
        }
LAB_00101c48:
        mutex_unlock(lVar5 + 0x48);
        return uVar7;
      }
      uVar7 = 0xffffffed;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// qcom_dcvs_unregister_voter @ 00101c70 size=260
// signature: undefined qcom_dcvs_unregister_voter(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dcvs_unregister_voter(char *param_1,uint param_2,uint param_3)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  
  uVar6 = 0xffffffea;
  if (((param_1 != (char *)0x0) && (param_2 < 6)) && (param_3 < 3)) {
    if (((dcvs_data != 0) && (lVar5 = *(long *)(dcvs_data + (ulong)param_2 * 8 + 0x60), lVar5 != 0))
       && (lVar5 = *(long *)(lVar5 + (ulong)param_3 * 8 + 0x90), lVar5 != 0)) {
      mutex_lock(lVar5 + 0x48);
      plVar7 = (long *)(lVar5 + 0x30);
      do {
        plVar7 = (long *)*plVar7;
        if (plVar7 == (long *)(lVar5 + 0x30)) {
          uVar6 = 0xffffffea;
          goto LAB_00101d50;
        }
        iVar3 = strcmp((char *)plVar7[-3],param_1);
      } while (iVar3 != 0);
      *(int *)(lVar5 + 0x40) = *(int *)(lVar5 + 0x40) + -1;
      uVar4 = __list_del_entry_valid(plVar7);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar7;
        plVar2 = (long *)plVar7[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar7 = -0x2152ffffffffff00;
      plVar7[1] = -0x2152fffffffffede;
      kfree(plVar7 + -3);
      uVar6 = 0;
LAB_00101d50:
      mutex_unlock(lVar5 + 0x48);
      return uVar6;
    }
    uVar6 = 0xffffffed;
  }
  return uVar6;
}



//------------------------------------------------------------
// qcom_dcvs_kobject_get @ 00101d78 size=92
// signature: undefined qcom_dcvs_kobject_get(void)
// callers: []
//------------------------------------------------------------

long qcom_dcvs_kobject_get(uint param_1)

{
  long lVar1;
  long lVar2;
  
  if (6 < param_1) {
    return -0x16;
  }
  if (*(char *)(dcvs_data + 0x98) == '\0') {
    return -0x205;
  }
  lVar2 = dcvs_data;
  if (param_1 != 6) {
    lVar2 = *(long *)(dcvs_data + (ulong)param_1 * 8 + 0x60);
    if (lVar2 == 0) {
      return -0x13;
    }
    lVar2 = lVar2 + 8;
  }
  lVar1 = -0x13;
  if ((*(byte *)(lVar2 + 0x3c) & 1) != 0) {
    lVar1 = lVar2;
  }
  return lVar1;
}



//------------------------------------------------------------
// qcom_dcvs_hw_minmax_get @ 00101dd8 size=84
// signature: undefined qcom_dcvs_hw_minmax_get(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dcvs_hw_minmax_get(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  long lVar1;
  
  if (5 < param_1) {
    return 0xffffffea;
  }
  if (*(char *)(dcvs_data + 0x98) == '\0') {
    return 0xfffffdfb;
  }
  lVar1 = *(long *)(dcvs_data + (ulong)param_1 * 8 + 0x60);
  if (lVar1 == 0) {
    return 0xffffffed;
  }
  *param_2 = *(undefined4 *)(lVar1 + 0x80);
  *param_3 = *(undefined4 *)(lVar1 + 0x84);
  return 0;
}



//------------------------------------------------------------
// qcom_dcvs_get_ddr_child_node @ 00101e30 size=252
// signature: undefined qcom_dcvs_get_ddr_child_node(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

long qcom_dcvs_get_ddr_child_node(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int local_40;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = -1;
  local_3c = 0;
  lVar3 = of_find_node_opts_by_path("/memory",0);
  iVar4 = -2;
  if (lVar3 != 0) {
    iVar2 = of_property_read_variable_u32_array(lVar3,"ddr_device_type",&local_3c,1,0);
    iVar4 = -2;
    if (-1 < iVar2) {
      iVar4 = local_3c;
    }
  }
  lVar3 = of_get_next_child(param_1,0);
  while ((lVar3 != 0 &&
         ((iVar2 = of_property_read_variable_u32_array(lVar3,"qcom,ddr-type",&local_40,1,0),
          iVar2 < 0 || (local_40 != iVar4))))) {
    lVar3 = of_get_next_child(param_1,lVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// qcom_dcvs_probe @ 00101f30 size=2444
// signature: undefined qcom_dcvs_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint qcom_dcvs_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  long *plVar11;
  char *pcVar12;
  undefined8 uVar13;
  uint local_a0;
  uint local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar7 + 0x638);
  piVar6 = (int *)of_device_get_match_data(lVar1);
  if (piVar6 == (int *)0x0) {
    iVar4 = 3;
LAB_001022fc:
    _dev_err(lVar1,"Invalid qcom-dcvs type: %u\n",iVar4);
    uVar3 = 0xffffffea;
    goto LAB_00102828;
  }
  iVar4 = *piVar6;
  if (iVar4 == 2) {
    local_60 = 0;
    local_58 = 0;
    local_70 = 0;
    local_68 = 0;
    lVar7 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
    local_9c = 3;
    local_80 = 0;
    local_78 = 0;
    local_90 = 0;
    local_88 = 0;
    local_98 = 0;
    if (lVar7 == 0) {
      _dev_err(lVar1,"QCOM DCVS HW not configured\n");
      uVar3 = 0xffffffed;
    }
    else {
      iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,dcvs-path-type",&local_9c,1,0);
      if ((iVar4 < 0) || (2 < local_9c)) {
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        _dev_err(lVar1,"Invalid path type:%d, ret:%d\n",local_9c,iVar4);
        uVar3 = 0xffffffed;
      }
      else {
        plVar8 = (long *)devm_kmalloc(lVar1,0x88,0xdc0);
        if (plVar8 != (long *)0x0) {
          *plVar8 = lVar1;
          plVar8[2] = lVar7;
          *(uint *)(plVar8 + 1) = local_9c;
          if (local_9c != 2) {
            if (local_9c == 1) {
              if (1 < *(uint *)(lVar7 + 0x68)) {
                pcVar12 = "Unsupported HW for dcvs fp: %d\n";
                goto LAB_00102898;
              }
              uVar3 = setup_ddrllcc_fp_device(lVar1,lVar7,plVar8);
              if ((int)uVar3 < 0) {
                pcVar12 = "Error setting up fp dev: %d\n";
LAB_0010287c:
                _dev_err(lVar1,pcVar12,uVar3);
                goto joined_r0x00102888;
              }
            }
            else {
              if (local_9c != 0) {
                uVar3 = 0xffffffea;
                goto LAB_00102814;
              }
              if (*(uint *)(lVar7 + 0x68) < 6) {
                if ((1 << (ulong)(*(uint *)(lVar7 + 0x68) & 0x1f) & 0x1bU) == 0) {
                  uVar3 = setup_epss_l3_sp_device(lVar1,lVar7,plVar8);
                }
                else {
                  uVar3 = setup_icc_sp_device();
                }
                if ((int)uVar3 < 0) {
                  pcVar12 = "Error setting up sp dev: %d\n";
                  goto LAB_0010287c;
                }
              }
              else {
                uVar3 = 0;
              }
            }
LAB_001024b0:
            plVar8[6] = (long)(plVar8 + 6);
            plVar8[7] = (long)(plVar8 + 6);
            __mutex_init(plVar8 + 9,"&path->voter_lock",&qcom_dcvs_path_probe___key);
            if ((int)plVar8[1] == 0) {
              uVar3 = *(uint *)(lVar7 + 0x68);
              *(undefined4 *)(lVar7 + 0x88) = *(undefined4 *)(lVar7 + 0x84);
              if (5 < uVar3) goto LAB_001028b4;
              if (0x48 < (ulong)uVar3 * 0xc) {
LAB_001028b8:
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(1,0x1028bc);
                (*pcVar2)();
              }
              *(undefined4 *)((long)&local_98 + (ulong)uVar3 * 0xc) = *(undefined4 *)(lVar7 + 0x84);
              uVar3 = *(uint *)(lVar7 + 0x68);
              if (5 < uVar3) goto LAB_001028b4;
              if (0x44 < (ulong)uVar3 * 0xc) goto LAB_001028b8;
              *(undefined4 *)((long)&local_98 + (ulong)uVar3 * 0xc + 4) = 0;
              uVar3 = *(uint *)(lVar7 + 0x68);
              if (5 < uVar3) goto LAB_001028b4;
              if (0x40 < (ulong)uVar3 * 0xc) goto LAB_001028b8;
              *(uint *)((long)&local_90 + (ulong)uVar3 * 0xc) = uVar3;
              if (6 < *(uint *)(lVar7 + 0x68)) goto LAB_001028b4;
              if (*(int *)((code *)plVar8[0x10] + -4) != 0x1268cd6f) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1025a0);
                (*pcVar2)();
              }
              uVar3 = (*(code *)plVar8[0x10])
                                (plVar8,(long)&local_98 + (ulong)*(uint *)(lVar7 + 0x68) * 0xc,1);
              if ((int)uVar3 < 0) {
                _dev_err(lVar1,"Err committing freq for path=%d\n",uVar3);
              }
            }
            if (2 < local_9c) {
LAB_001028b4:
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1028b8);
              (*pcVar2)();
            }
            *(long **)(lVar7 + (ulong)local_9c * 8 + 0x90) = plVar8;
            plVar8 = dcvs_data;
            *(int *)(lVar7 + 0xac) = *(int *)(lVar7 + 0xac) + 1;
            if (((((*(uint *)(plVar8 + 0x12) <= *(uint *)((long)plVar8 + 0x94)) &&
                  ((lVar7 = plVar8[0xc], lVar7 == 0 ||
                   (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))))) &&
                 ((lVar7 = plVar8[0xd], lVar7 == 0 ||
                  (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))))) &&
                ((((lVar7 = plVar8[0xe], lVar7 == 0 ||
                   (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))) &&
                  ((lVar7 = plVar8[0xf], lVar7 == 0 ||
                   (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))))) &&
                 ((lVar7 = plVar8[0x10], lVar7 == 0 ||
                  (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))))))) &&
               ((lVar7 = plVar8[0x11], lVar7 == 0 ||
                (*(uint *)(lVar7 + 0xa8) <= *(uint *)(lVar7 + 0xac))))) {
              *(undefined1 *)(plVar8 + 0x13) = 1;
            }
joined_r0x00102888:
            if (-1 < (int)uVar3) {
LAB_001027f0:
              uVar3 = 0;
              goto LAB_00102828;
            }
            goto LAB_00102814;
          }
          if ((*(int *)(lVar7 + 0x68) != 2) && (*(int *)(lVar7 + 0x68) != 5)) {
            pcVar12 = "Unsupported HW for path: %d\n";
LAB_00102898:
            _dev_err(lVar1,pcVar12,0);
            uVar3 = 0xffffffea;
            goto LAB_00102814;
          }
          uVar10 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
          lVar9 = devm_kmalloc(lVar1,(uVar10 & 0xffffffff) << 2,0xdc0);
          plVar8[5] = lVar9;
          if (lVar9 != 0) {
            uVar3 = setup_epss_l3_percpu_device(lVar1,lVar7,plVar8);
            if ((int)uVar3 < 0) {
              pcVar12 = "Error setting up percpu dev: %d\n";
              goto LAB_0010287c;
            }
            goto LAB_001024b0;
          }
        }
        uVar3 = 0xfffffff4;
      }
    }
  }
  else {
    if (iVar4 == 1) {
      local_a0 = 6;
      if (dcvs_data == (long *)0x0) {
        pcVar12 = "Missing QCOM DCVS dev data\n";
        goto LAB_00102474;
      }
      iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,dcvs-hw-type",&local_a0,1,0);
      if ((iVar4 < 0) || (5 < local_a0)) {
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        _dev_err(lVar1,"Invalid dcvs hw type:%d, ret:%d\n",local_a0,iVar4);
        uVar3 = 0xffffffed;
        goto LAB_00102814;
      }
      plVar8 = (long *)devm_kmalloc(lVar1,0xb0,0xdc0);
      if (plVar8 == (long *)0x0) goto LAB_001023c0;
      uVar13 = *(undefined8 *)(param_1 + 0x2f8);
      *plVar8 = lVar1;
      *(uint *)(plVar8 + 0xd) = local_a0;
      lVar7 = of_get_next_available_child(uVar13,0);
      if (lVar7 == 0) {
        *(undefined4 *)(plVar8 + 0x15) = 0;
      }
      else {
        iVar4 = 0;
        do {
          lVar7 = of_get_next_available_child(uVar13,lVar7);
          iVar4 = iVar4 + -1;
        } while (lVar7 != 0);
        *(int *)(plVar8 + 0x15) = -iVar4;
        if (iVar4 != 0) {
          if ((local_a0 == 5) || (local_a0 == 2)) {
            uVar3 = populate_l3_table(lVar1,plVar8 + 0xe);
          }
          else {
            lVar7 = *(long *)(param_1 + 0x2f8);
            local_9c = 0;
            local_58 = 0;
            uStack_50 = 0;
            local_68 = 0;
            local_60 = 0;
            local_78 = 0;
            local_70 = 0;
            local_88 = 0;
            local_80 = 0;
            local_98 = 0;
            local_90 = 0;
            iVar4 = __of_parse_phandle_with_args(lVar7,"qcom,freq-tbl",0,0,0,&local_98);
            if ((iVar4 == 0) && (local_98 != 0)) {
              local_58 = 0;
              uStack_50 = 0;
              local_68 = 0;
              local_60 = 0;
              local_78 = 0;
              local_70 = 0;
              local_88 = 0;
              local_80 = 0;
              local_98 = 0;
              local_90 = 0;
              iVar4 = __of_parse_phandle_with_args(lVar7,"qcom,freq-tbl",0,0,0,&local_98);
              lVar7 = local_98;
              if (iVar4 != 0) {
                lVar7 = 0;
              }
            }
            lVar9 = of_get_next_child(lVar7,0);
            if (lVar9 != 0) {
              iVar4 = 0;
              do {
                lVar9 = of_get_next_child(lVar7,lVar9);
                iVar4 = iVar4 + -1;
              } while (lVar9 != 0);
              if (iVar4 != 0) {
                lVar7 = qcom_dcvs_get_ddr_child_node(lVar7);
              }
            }
            lVar9 = of_find_property(lVar7,"qcom,freq-tbl",&local_9c);
            if (lVar9 == 0) {
              pcVar12 = "Unable to find freq tbl prop\n";
            }
            else {
              uVar3 = (int)local_9c >> 2;
              if (3 < local_9c) {
                local_9c = uVar3;
                lVar9 = devm_kmalloc(lVar1,-(ulong)(uVar3 >> 0x1f) & 0xfffffffc00000000 |
                                           (ulong)uVar3 << 2,0xdc0);
                plVar8[0xe] = lVar9;
                if (lVar9 == 0) {
                  uVar3 = 0xfffffff4;
                }
                else {
                  uVar3 = of_property_read_variable_u32_array
                                    (lVar7,"qcom,freq-tbl",lVar9,(long)(int)local_9c,0);
                  if ((int)uVar3 < 0) {
                    _dev_err(lVar1,"Error reading freq table from DT: %d\n",uVar3);
                  }
                  else {
                    uVar3 = local_9c;
                  }
                }
                goto LAB_001026b4;
              }
              pcVar12 = "Error: empty freq table\n";
              local_9c = uVar3;
            }
            _dev_err(lVar1,pcVar12);
            uVar3 = 0xffffffea;
          }
LAB_001026b4:
          if ((int)uVar3 < 1) {
            _dev_err(lVar1,"Error reading freq table: %d\n",uVar3);
          }
          else {
            *(uint *)(plVar8 + 0xf) = uVar3;
            uVar13 = *(undefined8 *)(param_1 + 0x2f8);
            *(undefined4 *)((long)plVar8 + 0x84) = ((undefined4 *)plVar8[0xe])[uVar3 - 1];
            *(undefined4 *)(plVar8 + 0x10) = *(undefined4 *)plVar8[0xe];
            iVar5 = of_property_read_variable_u32_array
                              (uVar13,"qcom,bus-width",(int *)((long)plVar8 + 0x7c),1,0);
            iVar4 = iVar5;
            if (-1 < iVar5) {
              iVar4 = 0;
            }
            if ((iVar5 < 0) || (*(int *)((long)plVar8 + 0x7c) == 0)) {
              _dev_err(lVar1,"Missing or invalid bus-width: %d\n",iVar4);
              uVar3 = 0xffffffea;
              goto LAB_00102814;
            }
            if (5 < local_a0) goto LAB_001028b4;
            plVar11 = plVar8 + 1;
            uVar3 = kobject_init_and_add(plVar11,dcvs_hw_ktype,dcvs_data,(&dcvs_hw_names)[local_a0])
            ;
            if ((int)uVar3 < 0) {
              _dev_err(lVar1,"failed to init dcvs hw kobj: %d\n",uVar3);
              goto LAB_00102810;
            }
            *(long **)(param_1 + 0xa8) = plVar8;
            plVar11 = dcvs_data;
            if (5 < local_a0) goto LAB_001028b4;
            dcvs_data[(ulong)local_a0 + 0xc] = (long)plVar8;
            *(int *)((long)plVar11 + 0x94) = *(int *)((long)plVar11 + 0x94) + 1;
          }
          if (uVar3 == 0) {
            uVar13 = *(undefined8 *)(param_1 + 0x2f8);
            lVar7 = of_get_next_available_child(uVar13,0);
            if (lVar7 != 0) {
              iVar4 = 0;
              do {
                lVar7 = of_get_next_available_child(uVar13,lVar7);
                iVar4 = iVar4 + -1;
              } while (lVar7 != 0);
              goto LAB_001027d8;
            }
            goto LAB_001027f0;
          }
          goto joined_r0x00102888;
        }
      }
      pcVar12 = "No dcvs paths provided!\n";
    }
    else {
      if (iVar4 != 0) goto LAB_001022fc;
      if (dcvs_data == (long *)0x0) {
        dcvs_data = (long *)devm_kmalloc(lVar1,0xa0,0xdc0);
        if (dcvs_data == (long *)0x0) {
LAB_001023c0:
          uVar3 = 0xfffffff4;
          goto LAB_00102814;
        }
        uVar13 = *(undefined8 *)(param_1 + 0x2f8);
        lVar7 = of_get_next_available_child(uVar13,0);
        if (lVar7 == 0) {
          pcVar12 = "No dcvs hw nodes provided!\n";
          *(undefined4 *)(dcvs_data + 0x12) = 0;
        }
        else {
          iVar4 = 0;
          do {
            lVar7 = of_get_next_available_child(uVar13,lVar7);
            plVar8 = dcvs_data;
            iVar4 = iVar4 + -1;
          } while (lVar7 != 0);
          *(int *)(dcvs_data + 0x12) = -iVar4;
          if (iVar4 != 0) {
            uVar3 = kobject_init_and_add
                              (plVar8,qcom_dcvs_ktype,___of_parse_phandle_with_args,"bus_dcvs");
            if (-1 < (int)uVar3) {
              uVar13 = *(undefined8 *)(param_1 + 0x2f8);
              lVar7 = of_get_next_available_child(uVar13,0);
              if (lVar7 != 0) {
                iVar4 = 0;
                do {
                  lVar7 = of_get_next_available_child(uVar13,lVar7);
                  iVar4 = iVar4 + -1;
                } while (lVar7 != 0);
LAB_001027d8:
                if (iVar4 != 0) {
                  of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,lVar1);
                }
              }
              goto LAB_001027f0;
            }
            _dev_err(lVar1,"failed to init qcom-dcvs kobj: %d\n",uVar3);
            plVar11 = dcvs_data;
LAB_00102810:
            kobject_put(plVar11);
            goto LAB_00102814;
          }
          pcVar12 = "No dcvs hw nodes provided!\n";
        }
      }
      else {
        pcVar12 = "Only one qcom-dcvs device allowed\n";
      }
    }
LAB_00102474:
    _dev_err(lVar1,pcVar12);
    uVar3 = 0xffffffed;
  }
LAB_00102814:
  _dev_err(lVar1,"Failed to probe qcom-dcvs device: %d\n",uVar3);
LAB_00102828:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// attr_show @ 001028c0 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1028ec);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00102908 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102934);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_hw_min_freq @ 00102950 size=56
// signature: undefined show_hw_min_freq(void)
// callers: []
//------------------------------------------------------------

long show_hw_min_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106133,*(undefined4 *)(param_1 + 0x78));
  return (long)iVar1;
}



//------------------------------------------------------------
// show_hw_max_freq @ 0010298c size=56
// signature: undefined show_hw_max_freq(void)
// callers: []
//------------------------------------------------------------

long show_hw_max_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106133,*(undefined4 *)(param_1 + 0x7c));
  return (long)iVar1;
}



//------------------------------------------------------------
// show_boost_freq @ 001029c8 size=56
// signature: undefined show_boost_freq(void)
// callers: []
//------------------------------------------------------------

long show_boost_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106133,*(undefined4 *)(param_1 + 0x80));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_boost_freq @ 00102a04 size=480
// signature: undefined store_boost_freq(void)
// callers: []
//------------------------------------------------------------

long store_boost_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  int iVar10;
  long lVar11;
  undefined1 auVar12 [16];
  uint local_48;
  int local_44;
  undefined4 uStack_40;
  uint local_3c;
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  local_3c = 0;
  auVar12 = kstrtouint(param_3,10,&local_3c);
  if (auVar12._0_4_ < 0) {
    param_4 = (long)auVar12._0_4_;
    goto LAB_00102b9c;
  }
  if (*(uint *)(param_1 + 0x7c) < local_3c) {
    param_4 = -0x16;
    goto LAB_00102b9c;
  }
  lVar11 = *(long *)(param_1 + 0x88);
  if (lVar11 == 0) {
    param_4 = -1;
    goto LAB_00102b9c;
  }
  if (local_3c <= *(uint *)(param_1 + 0x78)) {
    local_3c = *(uint *)(param_1 + 0x78);
  }
  *(uint *)(param_1 + 0x80) = local_3c;
  mutex_lock(lVar11 + 0x48);
  uStack_40 = *(undefined4 *)(param_1 + 0x60);
  plVar7 = (long *)(lVar11 + 0x30);
  plVar8 = (long *)*plVar7;
  local_44 = 0;
  uVar6 = 0;
  if (plVar8 != plVar7) {
    local_44 = 0;
    uVar5 = uVar6;
    do {
      local_44 = local_44 + *(int *)((long)plVar8 + -0xc);
      puVar1 = (uint *)(plVar8 + -2);
      plVar8 = (long *)*plVar8;
      uVar6 = *puVar1;
      if (*puVar1 <= uVar5) {
        uVar6 = uVar5;
      }
      uVar5 = uVar6;
    } while (plVar8 != plVar7);
  }
  lVar9 = *(long *)(lVar11 + 0x10);
  iVar3 = *(int *)(lVar9 + 0x78);
  if (*(int *)(lVar11 + 8) == 0) {
    uVar5 = *(uint *)(lVar9 + 0x88);
    if (*(uint *)(lVar9 + 0x88) <= uVar6) {
      uVar5 = uVar6;
    }
    iVar10 = 0;
    if (iVar3 != 0) goto LAB_00102af4;
LAB_00102b2c:
    iVar10 = 0;
    local_48 = 0;
LAB_00102b30:
    if (iVar10 == iVar3) goto LAB_00102b38;
  }
  else {
    iVar10 = 0;
    uVar5 = uVar6;
    if (iVar3 == 0) goto LAB_00102b2c;
LAB_00102af4:
    do {
      local_48 = *(uint *)(*(long *)(lVar9 + 0x70) + (long)iVar10 * 4);
      if (uVar5 <= local_48) goto LAB_00102b30;
      iVar10 = iVar10 + 1;
    } while (iVar3 != iVar10);
LAB_00102b38:
    local_48 = *(uint *)(*(long *)(lVar9 + 0x70) + (ulong)(iVar3 - 1) * 4);
  }
  if (local_48 != *(uint *)(lVar11 + 0x18)) {
    if (*(int *)(*(code **)(lVar11 + 0x80) + -4) != 0x1268cd6f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102b78);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(lVar11 + 0x80))(lVar11,&local_48,1);
    if (iVar3 < 0) {
      _printk(&DAT_001063e8,iVar3);
    }
  }
  uVar4 = mutex_unlock(lVar11 + 0x48);
  auVar12._8_4_ = *(undefined4 *)(param_1 + 0x60);
  auVar12._0_8_ = uVar4;
  auVar12._12_4_ = 0;
LAB_00102b9c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar12._0_8_,auVar12._8_8_);
  }
  return param_4;
}



//------------------------------------------------------------
// show_cur_freq @ 00102c4c size=408
// signature: undefined show_cur_freq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long show_cur_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x88);
  if (lVar7 == 0) {
    uVar6 = 0;
  }
  else {
    if (*(int *)(lVar7 + 8) != 2) {
      uVar6 = *(uint *)(lVar7 + 0x18);
      lVar7 = *(long *)(param_1 + 0x90);
      goto joined_r0x00102cd4;
    }
    uVar6 = 0;
    lVar5 = 0;
    uVar4 = (ulong)_nr_cpu_ids;
    while( true ) {
      uVar3 = _find_next_bit(&__cpu_possible_mask,uVar4,(long)(int)lVar5);
      uVar4 = (ulong)_nr_cpu_ids;
      if (uVar4 <= (uVar3 & 0xffffffff)) break;
      uVar1 = *(uint *)(*(long *)(lVar7 + 0x28) +
                       (-(uVar3 >> 0x1f & 1) & 0xfffffffc00000000 | (uVar3 & 0xffffffff) << 2));
      if (uVar6 <= uVar1) {
        uVar6 = uVar1;
      }
      lVar5 = uVar3 + 1;
    }
  }
  lVar7 = *(long *)(param_1 + 0x90);
joined_r0x00102cd4:
  if (lVar7 != 0) {
    if (*(int *)(lVar7 + 8) == 2) {
      lVar5 = 0;
      uVar4 = (ulong)_nr_cpu_ids;
      while( true ) {
        uVar3 = _find_next_bit(&__cpu_possible_mask,uVar4,(long)(int)lVar5);
        uVar4 = (ulong)_nr_cpu_ids;
        if (uVar4 <= (uVar3 & 0xffffffff)) break;
        uVar1 = *(uint *)(*(long *)(lVar7 + 0x28) +
                         (-(uVar3 >> 0x1f & 1) & 0xfffffffc00000000 | (uVar3 & 0xffffffff) << 2));
        if (uVar6 <= uVar1) {
          uVar6 = uVar1;
        }
        lVar5 = uVar3 + 1;
      }
    }
    else if (uVar6 <= *(uint *)(lVar7 + 0x18)) {
      uVar6 = *(uint *)(lVar7 + 0x18);
    }
  }
  lVar7 = *(long *)(param_1 + 0x98);
  if (lVar7 != 0) {
    if (*(int *)(lVar7 + 8) == 2) {
      lVar5 = 0;
      uVar4 = (ulong)_nr_cpu_ids;
      while( true ) {
        uVar3 = _find_next_bit(&__cpu_possible_mask,uVar4,(long)(int)lVar5);
        uVar4 = (ulong)_nr_cpu_ids;
        if (uVar4 <= (uVar3 & 0xffffffff)) break;
        uVar1 = *(uint *)(*(long *)(lVar7 + 0x28) +
                         (-(uVar3 >> 0x1f & 1) & 0xfffffffc00000000 | (uVar3 & 0xffffffff) << 2));
        if (uVar6 <= uVar1) {
          uVar6 = uVar1;
        }
        lVar5 = uVar3 + 1;
      }
    }
    else if (uVar6 <= *(uint *)(lVar7 + 0x18)) {
      uVar6 = *(uint *)(lVar7 + 0x18);
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010604d,uVar6);
  return (long)iVar2;
}



//------------------------------------------------------------
// show_available_frequencies @ 00102de8 size=184
// signature: undefined show_available_frequencies(void)
// callers: []
//------------------------------------------------------------

long show_available_frequencies(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    uVar3 = 0;
    do {
      iVar1 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_001060a4,
                        *(undefined4 *)(*(long *)(param_1 + 0x68) + (long)(int)uVar3 * 4));
      iVar2 = iVar1 + iVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x70));
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = iVar2 + -1;
  }
  iVar2 = scnprintf(param_3 + iVar1,0x1000 - (long)iVar1,&DAT_00106644);
  return (long)(iVar2 + iVar1);
}



//------------------------------------------------------------
// setup_icc_sp_device @ 00102eb8 size=244
// signature: undefined setup_icc_sp_device(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

ulong setup_icc_sp_device(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  ulong *puVar2;
  ulong uVar3;
  
  if (*(uint *)(param_2 + 0x68) < 5 && *(uint *)(param_2 + 0x68) != 2) {
    puVar2 = (ulong *)devm_kmalloc(param_1,8,0xdc0);
    if (puVar2 == (ulong *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      uVar3 = of_icc_get(param_1,0);
      *puVar2 = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        uVar1 = *(uint *)(param_2 + 0x68);
        if ((uVar1 < 5) && ((0x1bU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
          icc_set_tag(uVar3,*(undefined4 *)(&DAT_00108664 + (long)(int)uVar1 * 4));
        }
        uVar3 = 0;
        *(ulong **)(param_3 + 0x78) = puVar2;
        *(code **)(param_3 + 0x80) = commit_icc_freq;
      }
      else if ((int)uVar3 == -0x205) {
        uVar3 = 0xfffffdfb;
      }
      else {
        _dev_err(param_1,"Unable to register icc path: %d\n",uVar3 & 0xffffffff);
      }
    }
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// commit_icc_freq @ 00102fb0 size=132
// signature: undefined commit_icc_freq(void)
// callers: []
//------------------------------------------------------------

int commit_icc_freq(undefined8 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = icc_set_bw(*(undefined8 *)param_1[0xf],param_2[1] * *(int *)(param_1[2] + 0x7c),
                     *(int *)(param_1[2] + 0x7c) * *param_2);
  if (iVar1 < 0) {
    _dev_err(*param_1,"icc set bw request failed: %d\n",iVar1);
  }
  else {
    *(int *)(param_1 + 3) = *param_2;
    *(int *)((long)param_1 + 0x1c) = param_2[1];
  }
  return iVar1;
}



//------------------------------------------------------------
// populate_l3_table @ 00103038 size=612
// signature: undefined populate_l3_table(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong populate_l3_table(long param_1,long *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  ulong uVar11;
  int local_cc;
  long local_c8;
  long lStack_c0;
  undefined8 local_b8;
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
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
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
  local_c8 = 0;
  lStack_c0 = 0;
  local_cc = 0;
  iVar4 = of_property_match_string(*(undefined8 *)(param_1 + 0x2e8),"reg-names","l3tbl-base");
  if (iVar4 < 0) {
    pcVar9 = "Unable to find l3tbl-base: %d\n";
  }
  else {
    iVar4 = of_address_to_resource(*(undefined8 *)(param_1 + 0x2e8),iVar4,&local_c8);
    if (-1 < iVar4) {
      uVar1 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar1 = 0x68000000000f13;
      }
      lVar6 = ioremap_prot(local_c8,(lStack_c0 - local_c8) + 1,uVar1);
      if (lVar6 == 0) {
        _dev_err(param_1,"Unable to map l3tbl-base!\n");
      }
      else {
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2e8),"qcom,ftbl-row-size",&local_cc,1,0);
        if (iVar4 < 0) {
          local_cc = 4;
        }
        lVar7 = kmalloc_trace(___list_add_valid,0xdc0,0xa0);
        if (lVar7 != 0) {
          uVar11 = 0;
          uVar10 = 0;
          do {
            uVar5 = readl_relaxed(lVar6 + (ulong)(uint)(local_cc * (int)uVar11));
            uVar2 = 300000000;
            if (uVar5 >> 0x1e != 0) {
              uVar2 = (ulong)(uVar5 & 0xff) * 19200000;
            }
            if ((uVar11 != 0) && (uVar10 == uVar2)) break;
            *(int *)(lVar7 + uVar11 * 4) = (int)(uVar2 / 1000);
            uVar11 = uVar11 + 1;
            uVar10 = uVar2;
          } while (uVar11 != 0x28);
          lVar8 = devm_kmalloc(param_1,(uVar11 & 0xffffffff) << 2,0xdc0);
          *param_2 = lVar8;
          if (lVar8 != 0) {
            if ((int)uVar11 != 0) {
              uVar10 = 0;
              do {
                if (0x9f < uVar10) {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(1,0x103298);
                  (*pcVar3)();
                }
                *(undefined4 *)(*param_2 + uVar10) = *(undefined4 *)(lVar7 + uVar10);
                uVar10 = uVar10 + 4;
              } while ((uVar11 & 0xffffffff) * 4 != uVar10);
            }
            iounmap(lVar6);
            kfree(lVar7);
            goto LAB_00103214;
          }
        }
        iounmap(lVar6);
      }
      uVar11 = 0xfffffff4;
      goto LAB_00103214;
    }
    pcVar9 = "Unable to get resource from address: %d\n";
  }
  _dev_err(param_1,pcVar9,iVar4);
  uVar11 = 0xffffffea;
LAB_00103214:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// readl_relaxed @ 0010329c size=124
// signature: undefined readl_relaxed(void)
// callers: [populate_l3_table]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1032e4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// setup_epss_l3_sp_device @ 0010331c size=36
// signature: undefined setup_epss_l3_sp_device(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

void setup_epss_l3_sp_device(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  setup_epss_l3_device(param_1,param_3,1);
  return;
}



//------------------------------------------------------------
// setup_epss_l3_device @ 00103340 size=856
// signature: undefined setup_epss_l3_device(void)
// callers: [setup_epss_l3_percpu_device, setup_epss_l3_sp_device]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int setup_epss_l3_device(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int local_ac;
  long local_a8;
  long lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  mutex_lock(&epss_lock);
  if (epss_data != (long *)0x0) {
LAB_00103420:
    mutex_unlock(&epss_lock);
    plVar1 = epss_data;
    if ((param_3 & 1) == 0) {
      lVar4 = *(long *)(param_1 + 0x2e8);
      local_ac = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      lStack_a0 = 0;
      iVar2 = __of_parse_phandle_with_args(lVar4,"qcom,percpu-offsets",0,0,0,&local_a8);
      if ((iVar2 == 0) && (local_a8 != 0)) {
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        lStack_a0 = 0;
        iVar2 = __of_parse_phandle_with_args(lVar4,"qcom,percpu-offsets",0,0,0,&local_a8);
        lVar4 = local_a8;
        if (iVar2 != 0) {
          lVar4 = 0;
        }
      }
      lVar5 = of_find_property(lVar4,"qcom,percpu-offsets",&local_ac);
      if (lVar5 == 0) {
        _dev_err(param_1,"Unable to find percpu offsets prop!\n");
        iVar2 = -0x16;
      }
      else {
        iVar2 = local_ac >> 2;
        local_ac = iVar2;
        iVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
        if (iVar2 == iVar3) {
          lVar5 = devm_kmalloc(param_1,(long)local_ac << 2,0xdc0);
          plVar1[2] = lVar5;
          if (lVar5 == 0) {
            iVar2 = -0xc;
          }
          else {
            iVar2 = of_property_read_variable_u32_array
                              (lVar4,"qcom,percpu-offsets",lVar5,(long)local_ac,0);
            if (iVar2 < 0) {
              _dev_err(param_1,"Error reading percpu offsets from DT: %d\n",iVar2);
            }
            else {
              iVar2 = 0;
            }
          }
        }
        else {
          _dev_err(param_1,"Invalid percpu offsets table len=%d\n");
          iVar2 = -0x16;
        }
      }
      *(code **)(param_2 + 0x80) = commit_epss_l3_percpu;
    }
    else {
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),"qcom,shared-offset",epss_data + 1,1,0);
      iVar2 = iVar3;
      if (-1 < iVar3) {
        iVar2 = 0;
      }
      if (iVar3 < 0) {
        _dev_err(param_1,"Error reading shared offset: %d\n",iVar2);
      }
      *(code **)(param_2 + 0x80) = commit_epss_l3_shared;
    }
    if (-1 < iVar2) {
      iVar2 = 0;
      *(long **)(param_2 + 0x78) = epss_data;
    }
    goto LAB_00103660;
  }
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  epss_data = (long *)devm_kmalloc(param_1,0x18,0xdc0);
  if (epss_data == (long *)0x0) {
LAB_00103650:
    iVar2 = -0xc;
  }
  else {
    iVar2 = of_property_match_string
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"reg-names","l3-base");
    if (iVar2 < 0) {
      _dev_err(param_1,"%s: Unable to find l3-base: %d\n","init_epss_data");
      iVar2 = -0x16;
    }
    else {
      iVar2 = of_address_to_resource
                        (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),iVar2,&local_a8);
      if (-1 < iVar2) {
        lVar4 = devm_ioremap(*(undefined8 *)(param_1 + 0x60),local_a8,(lStack_a0 - local_a8) + 1);
        *epss_data = lVar4;
        if (*epss_data != 0) goto LAB_00103420;
        _dev_err(param_1,"Unable to map l3-base!\n");
        goto LAB_00103650;
      }
      _dev_err(param_1,"Unable to get resource from address: %d\n",iVar2);
    }
  }
  mutex_unlock(&epss_lock);
LAB_00103660:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// setup_epss_l3_percpu_device @ 0010369c size=36
// signature: undefined setup_epss_l3_percpu_device(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

void setup_epss_l3_percpu_device(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  setup_epss_l3_device(param_1,param_3,0);
  return;
}



//------------------------------------------------------------
// commit_epss_l3_shared @ 001036c4 size=148
// signature: undefined commit_epss_l3_shared(void)
// callers: []
//------------------------------------------------------------

undefined8 commit_epss_l3_shared(long param_1,uint *param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar3 + 0x78);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    do {
      if (*param_2 <= *(uint *)(*(long *)(lVar3 + 0x70) + uVar2 * 4)) goto LAB_00103718;
      uVar2 = uVar2 + 1;
    } while (uVar1 != uVar2);
    uVar2 = (ulong)uVar1;
  }
LAB_00103718:
  if (*(int *)(lVar3 + 0x68) == 5 || *(int *)(lVar3 + 0x68) == 2) {
    writel_relaxed(uVar2,**(long **)(param_1 + 0x78) +
                         (ulong)*(uint *)(*(long **)(param_1 + 0x78) + 1));
  }
  *(uint *)(param_1 + 0x18) = *param_2;
  return 0;
}



//------------------------------------------------------------
// commit_epss_l3_percpu @ 0010375c size=168
// signature: undefined commit_epss_l3_percpu(void)
// callers: []
//------------------------------------------------------------

undefined8 commit_epss_l3_percpu(long param_1,uint *param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar3 + 0x78);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    do {
      if (*param_2 <= *(uint *)(*(long *)(lVar3 + 0x70) + uVar2 * 4)) goto LAB_001037b0;
      uVar2 = uVar2 + 1;
    } while (uVar1 != uVar2);
    uVar2 = (ulong)uVar1;
  }
LAB_001037b0:
  if (*(int *)(lVar3 + 0x68) == 5 || *(int *)(lVar3 + 0x68) == 2) {
    lVar3 = tpidr_el1;
    writel_relaxed(uVar2,**(long **)(param_1 + 0x78) +
                         (ulong)*(uint *)((*(long **)(param_1 + 0x78))[2] +
                                         (long)*(int *)(&cpu_number + lVar3) * 4));
  }
  *(uint *)(param_1 + 0x18) = *param_2;
  return 0;
}



//------------------------------------------------------------
// writel_relaxed @ 00103804 size=132
// signature: undefined writel_relaxed(void)
// callers: [commit_epss_l3_percpu, commit_epss_l3_shared]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10381c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103858,uVar1);
  return;
}



//------------------------------------------------------------
// __traceiter_qcom_dcvs_update @ 00103894 size=196
// signature: undefined __traceiter_qcom_dcvs_update(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_qcom_dcvs_update
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00108780;
  plVar2 = DAT_00108780;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x584c6261) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103924);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_qcom_dcvs_boost @ 0010395c size=148
// signature: undefined __traceiter_qcom_dcvs_boost(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qcom_dcvs_boost
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001087c8;
  plVar2 = _DAT_001087c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4a631a53) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1039c8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_memlat_dev_meas @ 001039f4 size=204
// signature: undefined __traceiter_memlat_dev_meas(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_memlat_dev_meas
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108810;
  plVar2 = _DAT_00108810;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x1fecb0e5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103a8c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_memlat_dev_update @ 00103ac4 size=164
// signature: undefined __traceiter_memlat_dev_update(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_memlat_dev_update
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108858;
  plVar2 = _DAT_00108858;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7c25bb1f) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103b3c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_bw_hwmon_meas @ 00103b6c size=140
// signature: undefined __traceiter_bw_hwmon_meas(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_bw_hwmon_meas
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001088a0;
  plVar2 = _DAT_001088a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x6bd7d67) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103bd0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_bw_hwmon_update @ 00103bfc size=148
// signature: undefined __traceiter_bw_hwmon_update(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_bw_hwmon_update
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001088e8;
  plVar2 = _DAT_001088e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1b85a5fe) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c68);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_bw_hwmon_debug @ 00103c94 size=172
// signature: undefined __traceiter_bw_hwmon_debug(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_bw_hwmon_debug
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108930;
  plVar2 = _DAT_00108930;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x74001bb6) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103d14);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_bwprof_last_sample @ 00103d44 size=164
// signature: undefined __traceiter_bwprof_last_sample(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_bwprof_last_sample
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108978;
  plVar2 = _DAT_00108978;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x66835a5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103dbc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_bwprof_last_sample_meas @ 00103dec size=172
// signature: undefined __traceiter_bwprof_last_sample_meas(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_bwprof_last_sample_meas
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001089c0;
  plVar2 = _DAT_001089c0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x778bf415) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103e6c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_dcvs_update @ 00103e9c size=300
// signature: undefined trace_event_raw_event_qcom_dcvs_update(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_dcvs_update
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x40);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x40;
      strcpy((char *)(lVar3 + 0x40),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined8 *)(lVar3 + 0x18) = param_5;
      *(undefined8 *)(lVar3 + 0x20) = param_6;
      *(undefined8 *)(lVar3 + 0x28) = param_7;
      *(undefined8 *)(lVar3 + 0x30) = param_8;
      *(undefined8 *)(lVar3 + 0x38) = param_9;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qcom_dcvs_update @ 00103fcc size=380
// signature: undefined perf_trace_qcom_dcvs_update(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_dcvs_update
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_90 = param_6;
  local_88 = param_7;
  local_80 = param_8;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x4cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined8 **)(local_70 + 0xf8) = &local_90;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10040;
      strcpy((char *)(lVar5 + 0x40),__s);
      *(undefined8 *)(lVar5 + 0x18) = param_5;
      *(undefined8 *)(lVar5 + 0x20) = local_90;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined8 *)(lVar5 + 0x28) = local_88;
      *(undefined8 *)(lVar5 + 0x30) = local_80;
      *(undefined8 *)(lVar5 + 0x38) = param_9;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_dcvs_boost @ 0010414c size=212
// signature: undefined trace_event_raw_event_qcom_dcvs_boost(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_dcvs_boost
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x28), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined8 *)(lVar1 + 0x10) = param_4;
    *(undefined8 *)(lVar1 + 0x18) = param_5;
    *(undefined8 *)(lVar1 + 0x20) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qcom_dcvs_boost @ 00104224 size=276
// signature: undefined perf_trace_qcom_dcvs_boost(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_dcvs_boost
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined8 *)(lVar3 + 0x10) = param_4;
    *(undefined8 *)(lVar3 + 0x18) = param_5;
    *(undefined8 *)(lVar3 + 0x20) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_memlat_dev_meas @ 0010433c size=308
// signature: undefined trace_event_raw_event_memlat_dev_meas(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_memlat_dev_meas
               (long param_1,char *param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x38);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x38;
      strcpy((char *)(lVar3 + 0x38),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined8 *)(lVar3 + 0x10) = param_4;
      *(undefined8 *)(lVar3 + 0x18) = param_5;
      *(undefined8 *)(lVar3 + 0x20) = param_6;
      *(undefined4 *)(lVar3 + 0x28) = param_7;
      *(undefined4 *)(lVar3 + 0x2c) = param_8;
      *(undefined4 *)(lVar3 + 0x30) = param_9;
      *(undefined4 *)(lVar3 + 0x34) = param_10;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_memlat_dev_meas @ 00104474 size=388
// signature: undefined perf_trace_memlat_dev_meas(void)
// callers: []
//------------------------------------------------------------

void perf_trace_memlat_dev_meas
               (long param_1,char *param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_90 [8];
  undefined8 local_88;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_88 = param_6;
  local_7c = param_7;
  local_78 = param_8;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x44U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10038;
      strcpy((char *)(lVar5 + 0x38),__s);
      *(undefined8 *)(lVar5 + 0x20) = local_88;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined8 *)(lVar5 + 0x10) = param_4;
      *(undefined8 *)(lVar5 + 0x18) = param_5;
      *(undefined4 *)(lVar5 + 0x28) = local_7c;
      *(undefined4 *)(lVar5 + 0x2c) = local_78;
      *(undefined4 *)(lVar5 + 0x30) = param_9;
      *(undefined4 *)(lVar5 + 0x34) = param_10;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_memlat_dev_update @ 001045fc size=280
// signature: undefined trace_event_raw_event_memlat_dev_update(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_memlat_dev_update
               (long param_1,char *param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x30);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x30;
      strcpy((char *)(lVar3 + 0x30),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined8 *)(lVar3 + 0x10) = param_4;
      *(undefined8 *)(lVar3 + 0x18) = param_5;
      *(undefined8 *)(lVar3 + 0x20) = param_6;
      *(undefined8 *)(lVar3 + 0x28) = param_7;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_memlat_dev_update @ 00104718 size=364
// signature: undefined perf_trace_memlat_dev_update(void)
// callers: []
//------------------------------------------------------------

void perf_trace_memlat_dev_update
               (long param_1,char *param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_90 [8];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_88 = param_6;
  local_80 = param_7;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x3cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10030;
      strcpy((char *)(lVar5 + 0x30),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined8 *)(lVar5 + 0x10) = param_4;
      *(undefined8 *)(lVar5 + 0x18) = param_5;
      *(undefined8 *)(lVar5 + 0x20) = local_88;
      *(undefined8 *)(lVar5 + 0x28) = local_80;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_bw_hwmon_meas @ 00104888 size=260
// signature: undefined trace_event_raw_event_bw_hwmon_meas(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bw_hwmon_meas
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x28);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x24;
      strcpy((char *)(lVar3 + 0x24),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_3;
      *(undefined8 *)(lVar3 + 0x18) = param_4;
      *(undefined4 *)(lVar3 + 0x20) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bw_hwmon_meas @ 00104990 size=348
// signature: undefined perf_trace_bw_hwmon_meas(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bw_hwmon_meas
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x34U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10024;
      strcpy((char *)(lVar5 + 0x24),__s);
      *(undefined8 *)(lVar5 + 0x10) = param_3;
      *(undefined8 *)(lVar5 + 0x18) = param_4;
      *(undefined4 *)(lVar5 + 0x20) = param_5;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_bw_hwmon_update @ 00104af0 size=272
// signature: undefined trace_event_raw_event_bw_hwmon_update(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bw_hwmon_update
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x30);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x30;
      strcpy((char *)(lVar3 + 0x30),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_3;
      *(undefined8 *)(lVar3 + 0x18) = param_4;
      *(undefined8 *)(lVar3 + 0x20) = param_5;
      *(undefined8 *)(lVar3 + 0x28) = param_6;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bw_hwmon_update @ 00104c04 size=356
// signature: undefined perf_trace_bw_hwmon_update(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bw_hwmon_update
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined8 local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_80 = param_6;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x3cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined8 **)(local_70 + 0xf8) = &local_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10030;
      strcpy((char *)(lVar5 + 0x30),__s);
      *(undefined8 *)(lVar5 + 0x10) = param_3;
      *(undefined8 *)(lVar5 + 0x18) = param_4;
      *(undefined8 *)(lVar5 + 0x20) = param_5;
      *(undefined8 *)(lVar5 + 0x28) = local_80;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_bw_hwmon_debug @ 00104d6c size=292
// signature: undefined trace_event_raw_event_bw_hwmon_debug(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bw_hwmon_debug
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x40);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x40;
      strcpy((char *)(lVar3 + 0x40),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_3;
      *(undefined8 *)(lVar3 + 0x18) = param_4;
      *(undefined8 *)(lVar3 + 0x20) = param_5;
      *(undefined8 *)(lVar3 + 0x28) = param_6;
      *(undefined8 *)(lVar3 + 0x30) = param_7;
      *(undefined8 *)(lVar3 + 0x38) = param_8;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bw_hwmon_debug @ 00104e94 size=372
// signature: undefined perf_trace_bw_hwmon_debug(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bw_hwmon_debug
               (long param_1,char *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_90 = param_6;
  local_88 = param_7;
  local_80 = param_8;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x4cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined8 **)(local_70 + 0xf8) = &local_90;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10040;
      strcpy((char *)(lVar5 + 0x40),__s);
      *(undefined8 *)(lVar5 + 0x20) = param_5;
      *(undefined8 *)(lVar5 + 0x28) = local_90;
      *(undefined8 *)(lVar5 + 0x10) = param_3;
      *(undefined8 *)(lVar5 + 0x18) = param_4;
      *(undefined8 *)(lVar5 + 0x30) = local_88;
      *(undefined8 *)(lVar5 + 0x38) = local_80;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_bwprof_last_sample @ 0010500c size=336
// signature: undefined trace_event_raw_event_bwprof_last_sample(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bwprof_last_sample
               (long param_1,char *param_2,char *param_3,undefined8 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar7 = __trace_trigger_soft_disabled(param_1), (uVar7 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar4 = strlen(__s);
    __s_00 = "(null)";
    if (param_3 != (char *)0x0) {
      __s_00 = param_3;
    }
    iVar1 = (int)sVar4 + 1;
    sVar5 = strlen(__s_00);
    iVar2 = (int)sVar5 + 1;
    lVar6 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar2 + iVar1) + 0x28);
    if (lVar6 != 0) {
      uVar3 = (int)sVar4 + 0x25;
      *(uint *)(lVar6 + 8) = iVar1 * 0x10000 | 0x24;
      *(uint *)(lVar6 + 0xc) = uVar3 | iVar2 * 0x10000;
      strcpy((char *)(lVar6 + 0x24),__s);
      strcpy((char *)(lVar6 + (ulong)(uVar3 & 0xffff)),__s_00);
      *(undefined8 *)(lVar6 + 0x10) = param_4;
      *(undefined4 *)(lVar6 + 0x18) = param_5;
      *(undefined4 *)(lVar6 + 0x1c) = param_6;
      *(undefined4 *)(lVar6 + 0x20) = param_7;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bwprof_last_sample @ 00105160 size=412
// signature: undefined perf_trace_bwprof_last_sample(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bwprof_last_sample
               (long param_1,char *param_2,char *param_3,undefined8 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  ulong unaff_x30;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_5;
  local_7c = param_6;
  local_78 = param_7;
  sVar5 = strlen(__s);
  __s_00 = "(null)";
  if (param_3 != (char *)0x0) {
    __s_00 = param_3;
  }
  sVar6 = strlen(__s_00);
  lVar7 = tpidr_el1;
  plVar2 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar6 + 1;
    iVar8 = (int)sVar5;
    iVar4 = (iVar8 + iVar1 + 0x34U & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar7 != 0) {
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      *(undefined4 **)(local_70 + 0xf8) = &local_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar7 + 8) = iVar8 * 0x10000 + 0x10024;
      *(uint *)(lVar7 + 0xc) = iVar8 + 0x25U | iVar1 * 0x10000;
      strcpy((char *)(lVar7 + 0x24),__s);
      strcpy((char *)(lVar7 + (ulong)(iVar8 + 0x25U & 0xffff)),__s_00);
      *(undefined4 *)(lVar7 + 0x18) = local_80;
      *(undefined4 *)(lVar7 + 0x1c) = local_7c;
      *(undefined8 *)(lVar7 + 0x10) = param_4;
      *(undefined4 *)(lVar7 + 0x20) = local_78;
      perf_trace_run_bpf_submit(lVar7,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_bwprof_last_sample_meas @ 00105300 size=296
// signature: undefined trace_event_raw_event_bwprof_last_sample_meas(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bwprof_last_sample_meas
               (long param_1,char *param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x30);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x2c;
      strcpy((char *)(lVar3 + 0x2c),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_3;
      *(undefined4 *)(lVar3 + 0x18) = param_4;
      *(undefined4 *)(lVar3 + 0x1c) = param_5;
      *(undefined4 *)(lVar3 + 0x20) = param_6;
      *(undefined4 *)(lVar3 + 0x24) = param_7;
      *(undefined4 *)(lVar3 + 0x28) = param_8;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bwprof_last_sample_meas @ 0010542c size=372
// signature: undefined perf_trace_bwprof_last_sample_meas(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bwprof_last_sample_meas
               (long param_1,char *param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_6;
  local_7c = param_7;
  local_78 = param_8;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x3cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined4 **)(local_70 + 0xf8) = &local_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x1002c;
      strcpy((char *)(lVar5 + 0x2c),__s);
      *(undefined4 *)(lVar5 + 0x20) = local_80;
      *(undefined4 *)(lVar5 + 0x24) = local_7c;
      *(undefined8 *)(lVar5 + 0x10) = param_3;
      *(undefined4 *)(lVar5 + 0x18) = param_4;
      *(undefined4 *)(lVar5 + 0x1c) = param_5;
      *(undefined4 *)(lVar5 + 0x28) = local_78;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_qcom_dcvs_update @ 001055a4 size=52
// signature: undefined __bpf_trace_qcom_dcvs_update(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_dcvs_update
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run8(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qcom_dcvs_boost @ 001055dc size=36
// signature: undefined __bpf_trace_qcom_dcvs_boost(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_dcvs_boost(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run5(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_memlat_dev_meas @ 00105604 size=60
// signature: undefined __bpf_trace_memlat_dev_meas(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_memlat_dev_meas(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run9(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_memlat_dev_update @ 00105644 size=32
// signature: undefined __bpf_trace_memlat_dev_update(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_memlat_dev_update(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run6(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_bw_hwmon_meas @ 00105668 size=32
// signature: undefined __bpf_trace_bw_hwmon_meas(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bw_hwmon_meas(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_bw_hwmon_update @ 0010568c size=28
// signature: undefined __bpf_trace_bw_hwmon_update(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bw_hwmon_update(void)

{
  bpf_trace_run5();
  return;
}



//------------------------------------------------------------
// __bpf_trace_bw_hwmon_debug @ 001056ac size=28
// signature: undefined __bpf_trace_bw_hwmon_debug(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bw_hwmon_debug(void)

{
  bpf_trace_run7();
  return;
}



//------------------------------------------------------------
// __bpf_trace_bwprof_last_sample @ 001056cc size=40
// signature: undefined __bpf_trace_bwprof_last_sample(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bwprof_last_sample(void)

{
  bpf_trace_run6();
  return;
}



//------------------------------------------------------------
// __bpf_trace_bwprof_last_sample_meas @ 001056f8 size=48
// signature: undefined __bpf_trace_bwprof_last_sample_meas(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bwprof_last_sample_meas(void)

{
  bpf_trace_run7();
  return;
}



//------------------------------------------------------------
// trace_raw_output_qcom_dcvs_update @ 0010572c size=132
// signature: undefined trace_raw_output_qcom_dcvs_update(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_dcvs_update(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "name=%s hw=%d path=%d ib=%lu path_ib=%lu ab=%lu path_ab=%lu boost=%lu\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar2 + 0x28),
                       *(undefined8 *)(lVar2 + 0x30),*(undefined8 *)(lVar2 + 0x38));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qcom_dcvs_boost @ 001057b4 size=108
// signature: undefined trace_raw_output_qcom_dcvs_boost(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_dcvs_boost(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"hw=%d path=%d boost=%lu path_ib=%lu path_ab=%lu\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_memlat_dev_meas @ 00105824 size=144
// signature: undefined trace_raw_output_memlat_dev_meas(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_memlat_dev_meas(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "dev: %s, id=%u, inst=%lu, mem=%lu, freq=%lu, stall=%u, wb=%u, ratio=%u, fe_stall=%u\n"
                       ,lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x28),
                       *(undefined4 *)(lVar2 + 0x2c),*(undefined4 *)(lVar2 + 0x30),
                       *(undefined4 *)(lVar2 + 0x34));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_memlat_dev_update @ 001058b8 size=116
// signature: undefined trace_raw_output_memlat_dev_update(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_memlat_dev_update(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev: %s, id=%u, inst=%lu, mem=%lu, freq=%lu, vote=%lu\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bw_hwmon_meas @ 00105930 size=112
// signature: undefined trace_raw_output_bw_hwmon_meas(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bw_hwmon_meas(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev: %s, mbps = %lu, us = %lu, wake = %d\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bw_hwmon_update @ 001059a4 size=112
// signature: undefined trace_raw_output_bw_hwmon_update(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bw_hwmon_update(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev: %s, mbps = %lu, freq = %lu, up = %lu, down = %lu\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined8 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bw_hwmon_debug @ 00105a18 size=128
// signature: undefined trace_raw_output_bw_hwmon_debug(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bw_hwmon_debug(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "dev=%s mbps=%lu zone=%lu hist_max=%lu hist_mem=%lu hyst_mbps=%lu hyst_len=%lu\n"
                       ,lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined8 *)(lVar2 + 0x28),*(undefined8 *)(lVar2 + 0x30),
                       *(undefined8 *)(lVar2 + 0x38));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bwprof_last_sample @ 00105a9c size=124
// signature: undefined trace_raw_output_bwprof_last_sample(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bwprof_last_sample(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev=%s client=%s ts=%llu meas_mbps=%u max_mbps=%u mem_freq=%u\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),lVar2 + (ulong)*(ushort *)(lVar2 + 0xc)
                       ,*(undefined8 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18),
                       *(undefined4 *)(lVar2 + 0x1c),*(undefined4 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bwprof_last_sample_meas @ 00105b1c size=132
// signature: undefined trace_raw_output_bwprof_last_sample_meas(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bwprof_last_sample_meas(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "dev=%s ts=%llu meas_mbps_0=%u meas_mbps_1=%u meas_mbps_2=%u max_mbps=%u mem_freq=%u\n"
                       ,lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c),
                       *(undefined4 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x24),
                       *(undefined4 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00105f98 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_dcvs_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105fc8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_dcvs_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 0010b000 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_dcvs_register_voter, setup_epss_l3_device, qcom_dcvs_unregister_voter, qcom_dcvs_update_votes, store_boost_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010b008 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_dcvs_register_voter, qcom_dcvs_unregister_voter, qcom_dcvs_update_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010b010 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_dcvs_register_voter, setup_epss_l3_device, qcom_dcvs_unregister_voter, qcom_dcvs_update_votes, store_boost_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010b030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [setup_epss_l3_device, trace_event_raw_event_memlat_dev_meas, perf_trace_memlat_dev_meas, perf_trace_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, perf_trace_bw_hwmon_update, perf_trace_bwprof_last_sample, perf_trace_bw_hwmon_meas, perf_trace_qcom_dcvs_update, trace_event_raw_event_memlat_dev_update, qcom_dcvs_get_ddr_child_node, perf_trace_memlat_dev_update, trace_event_raw_event_qcom_dcvs_boost, trace_event_raw_event_bw_hwmon_meas, qcom_dcvs_probe, perf_trace_qcom_dcvs_boost, populate_l3_table, perf_trace_bw_hwmon_debug, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bwprof_last_sample, qcom_dcvs_update_votes, store_boost_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010b040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_dcvs_register_voter, populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010b048 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_dcvs_register_voter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010b050 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_dcvs_unregister_voter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010b058 size=1
// signature: undefined kfree(void)
// callers: [qcom_dcvs_unregister_voter, populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0010b060 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [qcom_dcvs_get_ddr_child_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010b068 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe, populate_l3_table, qcom_dcvs_get_ddr_child_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 0010b070 size=1
// signature: undefined of_get_next_child(void)
// callers: [qcom_dcvs_probe, qcom_dcvs_get_ddr_child_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010b078 size=1
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
// platform_driver_unregister @ 0010b080 size=1
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
// of_device_get_match_data @ 0010b088 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010b090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe, populate_l3_table, setup_icc_sp_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010b098 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 0010b0a8 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010b0b0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010b0b8 size=1
// signature: undefined of_find_property(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010b0c0 size=1
// signature: undefined _dev_err(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe, populate_l3_table, setup_icc_sp_device, commit_icc_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 0010b0d8 size=1
// signature: undefined __bitmap_weight(void)
// callers: [setup_epss_l3_device, qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// setup_ddrllcc_fp_device @ 0010b0e0 size=1
// signature: undefined setup_ddrllcc_fp_device(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void setup_ddrllcc_fp_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010b0e8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 0010b0f0 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 0010b0f8 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010b100 size=1
// signature: undefined scnprintf(void)
// callers: [show_cur_freq, show_hw_max_freq, show_boost_freq, show_available_frequencies, show_hw_min_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010b108 size=1
// signature: undefined kstrtouint(void)
// callers: [store_boost_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010b110 size=1
// signature: undefined _printk(void)
// callers: [store_boost_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010b118 size=1
// signature: undefined _find_next_bit(void)
// callers: [show_cur_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 0010b120 size=1
// signature: undefined of_icc_get(void)
// callers: [setup_icc_sp_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_tag @ 0010b128 size=1
// signature: undefined icc_set_tag(void)
// callers: [setup_icc_sp_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_tag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0010b130 size=1
// signature: undefined icc_set_bw(void)
// callers: [commit_icc_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 0010b138 size=1
// signature: undefined of_property_match_string(void)
// callers: [setup_epss_l3_device, populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 0010b140 size=1
// signature: undefined of_address_to_resource(void)
// callers: [setup_epss_l3_device, populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 0010b150 size=1
// signature: undefined ioremap_prot(void)
// callers: [populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 0010b158 size=1
// signature: undefined iounmap(void)
// callers: [populate_l3_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010b160 size=1
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
// log_post_read_mmio @ 0010b168 size=1
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
// devm_ioremap @ 0010b170 size=1
// signature: undefined devm_ioremap(void)
// callers: [setup_epss_l3_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010b178 size=1
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
// log_post_write_mmio @ 0010b180 size=1
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
// strlen @ 0010b188 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_memlat_dev_meas, perf_trace_memlat_dev_meas, perf_trace_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, perf_trace_bw_hwmon_update, perf_trace_bwprof_last_sample, perf_trace_bw_hwmon_meas, perf_trace_qcom_dcvs_update, trace_event_raw_event_memlat_dev_update, perf_trace_memlat_dev_update, trace_event_raw_event_bw_hwmon_meas, perf_trace_bw_hwmon_debug, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bwprof_last_sample]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010b190 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_qcom_dcvs_boost, trace_event_raw_event_bw_hwmon_meas, trace_event_raw_event_memlat_dev_meas, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, trace_event_raw_event_memlat_dev_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010b198 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_memlat_dev_meas, perf_trace_memlat_dev_meas, perf_trace_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, perf_trace_bw_hwmon_update, perf_trace_bwprof_last_sample, perf_trace_bw_hwmon_meas, perf_trace_qcom_dcvs_update, trace_event_raw_event_memlat_dev_update, perf_trace_memlat_dev_update, trace_event_raw_event_bw_hwmon_meas, perf_trace_bw_hwmon_debug, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bwprof_last_sample]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010b1a0 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_qcom_dcvs_boost, trace_event_raw_event_bw_hwmon_meas, trace_event_raw_event_memlat_dev_meas, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, trace_event_raw_event_memlat_dev_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010b1a8 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_qcom_dcvs_boost, trace_event_raw_event_bw_hwmon_meas, trace_event_raw_event_memlat_dev_meas, trace_event_raw_event_qcom_dcvs_update, trace_event_raw_event_bw_hwmon_debug, trace_event_raw_event_bwprof_last_sample, trace_event_raw_event_bwprof_last_sample_meas, trace_event_raw_event_bw_hwmon_update, trace_event_raw_event_memlat_dev_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010b1b0 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_memlat_dev_update, perf_trace_memlat_dev_meas, perf_trace_bwprof_last_sample_meas, perf_trace_qcom_dcvs_boost, perf_trace_bw_hwmon_debug, perf_trace_bw_hwmon_update, perf_trace_bwprof_last_sample, perf_trace_bw_hwmon_meas, perf_trace_qcom_dcvs_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010b1b8 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_memlat_dev_update, perf_trace_memlat_dev_meas, perf_trace_bwprof_last_sample_meas, perf_trace_qcom_dcvs_boost, perf_trace_bw_hwmon_debug, perf_trace_bw_hwmon_update, perf_trace_bwprof_last_sample, perf_trace_bw_hwmon_meas, perf_trace_qcom_dcvs_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run8 @ 0010b1c0 size=1
// signature: undefined bpf_trace_run8(void)
// callers: [__bpf_trace_qcom_dcvs_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0010b1c8 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_bw_hwmon_update, __bpf_trace_qcom_dcvs_boost]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run9 @ 0010b1d0 size=1
// signature: undefined bpf_trace_run9(void)
// callers: [__bpf_trace_memlat_dev_meas]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run9(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 0010b1d8 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_bwprof_last_sample, __bpf_trace_memlat_dev_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0010b1e0 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_bw_hwmon_meas]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run7 @ 0010b1e8 size=1
// signature: undefined bpf_trace_run7(void)
// callers: [__bpf_trace_bwprof_last_sample_meas, __bpf_trace_bw_hwmon_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run7(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0010b1f0 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_bwprof_last_sample, trace_raw_output_memlat_dev_meas, trace_raw_output_bw_hwmon_meas, trace_raw_output_qcom_dcvs_boost, trace_raw_output_bw_hwmon_update, trace_raw_output_bwprof_last_sample_meas, trace_raw_output_memlat_dev_update, trace_raw_output_qcom_dcvs_update, trace_raw_output_bw_hwmon_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010b1f8 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_bwprof_last_sample, trace_raw_output_memlat_dev_meas, trace_raw_output_bw_hwmon_meas, trace_raw_output_qcom_dcvs_boost, trace_raw_output_bw_hwmon_update, trace_raw_output_bwprof_last_sample_meas, trace_raw_output_memlat_dev_update, trace_raw_output_qcom_dcvs_update, trace_raw_output_bw_hwmon_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010b200 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_bwprof_last_sample, trace_raw_output_memlat_dev_meas, trace_raw_output_bw_hwmon_meas, trace_raw_output_qcom_dcvs_boost, trace_raw_output_bw_hwmon_update, trace_raw_output_bwprof_last_sample_meas, trace_raw_output_memlat_dev_update, trace_raw_output_qcom_dcvs_update, trace_raw_output_bw_hwmon_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



