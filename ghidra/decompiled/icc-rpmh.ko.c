// Decompiled by Ghidra 12.2
// Program: icc-rpmh.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_icc_pre_aggregate @ 0010033c size=176
// signature: undefined qcom_icc_pre_aggregate(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_pre_aggregate(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x70);
  lVar3 = *(long *)(param_1 + 0x20);
  *(undefined8 *)(lVar2 + 0x150) = 0;
  *(undefined8 *)(lVar2 + 0x158) = 0;
  *(undefined8 *)(lVar2 + 0x140) = 0;
  *(undefined8 *)(lVar2 + 0x148) = 0;
  *(undefined8 *)(lVar2 + 0x130) = 0;
  *(undefined8 *)(lVar2 + 0x138) = 0;
  *(undefined8 *)(lVar2 + 0x15d) = 0;
  *(undefined8 *)(lVar2 + 0x120) = 0;
  *(undefined8 *)(lVar2 + 0x128) = 0;
  *(undefined8 *)(lVar2 + 0x110) = 0;
  *(undefined8 *)(lVar2 + 0x118) = 0;
  if ((((*(long *)(lVar2 + 0x180) != 0) &&
       (qcom_icc_bcm_voter_add
                  (*(undefined8 *)
                    (*(long *)(lVar3 + 0xb8) + (long)*(int *)(*(long *)(lVar2 + 0x168) + 0xa0) * 8))
       , 1 < *(ulong *)(lVar2 + 0x180))) &&
      (qcom_icc_bcm_voter_add
                 (*(undefined8 *)
                   (*(long *)(lVar3 + 0xb8) + (long)*(int *)(*(long *)(lVar2 + 0x170) + 0xa0) * 8)),
      2 < *(ulong *)(lVar2 + 0x180))) &&
     (qcom_icc_bcm_voter_add
                (*(undefined8 *)
                  (*(long *)(lVar3 + 0xb8) + (long)*(int *)(*(long *)(lVar2 + 0x178) + 0xa0) * 8)),
     3 < *(ulong *)(lVar2 + 0x180))) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1003ec);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_aggregate @ 001003f0 size=212
// signature: undefined qcom_icc_aggregate(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_icc_aggregate(long param_1,uint param_2,uint param_3,uint param_4,int *param_5,uint *param_6)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  
  uVar3 = 7;
  if (param_2 != 0) {
    uVar3 = param_2;
  }
  uVar6 = 0;
  lVar1 = *(long *)(param_1 + 0x70) + 0x160;
  do {
    if ((uVar3 >> (uVar6 & 0x3f) & 1) != 0) {
      lVar2 = lVar1 + uVar6 * 8;
      uVar5 = *(uint *)(lVar2 + -0x28);
      if (*(uint *)(lVar2 + -0x28) <= param_4) {
        uVar5 = param_4;
      }
      *(ulong *)(lVar2 + -0x50) = *(long *)(lVar2 + -0x50) + (ulong)param_3;
      *(ulong *)(lVar2 + -0x28) = (ulong)uVar5;
      if ((uVar3 & 0x100) != 0 && (param_4 != 0 || param_3 != 0)) {
        *(undefined1 *)(lVar1 + uVar6) = 1;
      }
    }
    uVar5 = *(uint *)(param_1 + 0x68);
    if ((uVar5 != 0) || (*(int *)(param_1 + 0x6c) != 0)) {
      lVar2 = lVar1 + uVar6 * 8;
      uVar4 = *(ulong *)(lVar2 + -0x50);
      if (*(ulong *)(lVar2 + -0x50) <= (ulong)uVar5) {
        uVar4 = (ulong)uVar5;
      }
      *(ulong *)(lVar2 + -0x50) = uVar4;
      uVar4 = *(ulong *)(lVar2 + -0x28);
      if (*(ulong *)(lVar2 + -0x28) <= (ulong)*(uint *)(param_1 + 0x6c)) {
        uVar4 = (ulong)*(uint *)(param_1 + 0x6c);
      }
      *(ulong *)(lVar2 + -0x28) = uVar4;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 5);
  *param_5 = *param_5 + param_3;
  uVar3 = *param_6;
  if (*param_6 <= param_4) {
    uVar3 = param_4;
  }
  *param_6 = uVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_icc_aggregate_stub @ 001004c8 size=8
// signature: undefined qcom_icc_aggregate_stub(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_aggregate_stub(void)

{
  return 0;
}



//------------------------------------------------------------
// qcom_icc_set @ 001004d4 size=420
// signature: undefined qcom_icc_set(void)
// callers: []
//------------------------------------------------------------

int qcom_icc_set(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 *puVar9;
  
  if (param_1 != 0) {
    param_2 = param_1;
  }
  puVar9 = *(undefined8 **)(param_2 + 0x70);
  lVar8 = *(long *)(param_2 + 0x20);
  if ((*(ushort *)((long)puVar9 + 0x1b2) != 0) && (*(short *)((long)puVar9 + 0x1b4) != 0)) {
    uVar2 = *(int *)(param_2 + 0x60) * (uint)*(ushort *)((long)puVar9 + 0x1b2);
    *(uint *)(param_2 + 0x60) = uVar2;
    uVar3 = 0;
    if (*(ushort *)((long)puVar9 + 0x1b4) != 0) {
      uVar3 = uVar2 / *(ushort *)((long)puVar9 + 0x1b4);
    }
    *(uint *)(param_2 + 0x60) = uVar3;
    uVar2 = *(int *)(param_2 + 100) * (uint)*(ushort *)((long)puVar9 + 0x1b2);
    *(uint *)(param_2 + 100) = uVar2;
    uVar3 = 0;
    if (*(ushort *)((long)puVar9 + 0x1b4) != 0) {
      uVar3 = uVar2 / *(ushort *)((long)puVar9 + 0x1b4);
    }
    *(uint *)(param_2 + 100) = uVar3;
  }
  lVar5 = puVar9[0x34];
  if (lVar5 != 0) {
    uVar2 = *(uint *)(param_2 + 0x60);
    if (*(uint *)(param_2 + 0x60) <= *(uint *)(param_2 + 100)) {
      uVar2 = *(uint *)(param_2 + 100);
    }
    uVar6 = 0;
    if ((ulong)*(ushort *)((long)puVar9 + 0x10e) != 0) {
      uVar6 = ((ulong)uVar2 * 1000) / (ulong)*(ushort *)((long)puVar9 + 0x10e);
    }
    if (0xfffffffe < uVar6) {
      uVar6 = 0xffffffff;
    }
    if (uVar6 == 0) {
      if ((*(char *)(puVar9 + 0x36) != '\0') && (*(char *)((long)puVar9 + 0x1b1) != '\0')) {
        clk_disable(lVar5);
        clk_unprepare(lVar5);
        *(undefined1 *)((long)puVar9 + 0x1b1) = 0;
      }
    }
    else {
      iVar4 = clk_set_rate(lVar5,uVar6);
      if (iVar4 == 0) {
        cVar1 = *(char *)(puVar9 + 0x36);
      }
      else {
        _dev_warn(*(undefined8 *)(lVar8 + 0x68),"Failed to set %s rate to %d for %s\n",puVar9[0x35],
                  uVar6,*puVar9);
        cVar1 = *(char *)(puVar9 + 0x36);
      }
      if ((cVar1 != '\0') && (*(char *)((long)puVar9 + 0x1b1) == '\0')) {
        uVar7 = puVar9[0x34];
        iVar4 = clk_prepare(uVar7);
        if (iVar4 == 0) {
          iVar4 = clk_enable(uVar7);
          if (iVar4 == 0) {
            *(undefined1 *)((long)puVar9 + 0x1b1) = 1;
            goto LAB_001005d8;
          }
          clk_unprepare(uVar7);
        }
        _dev_err(*(undefined8 *)(lVar8 + 0x68),"Failed to enable %s for %s\n",puVar9[0x35],*puVar9);
        return iVar4;
      }
    }
  }
LAB_001005d8:
  if (*(long *)(lVar8 + 0xc0) != 0) {
    uVar6 = 0;
    do {
      qcom_icc_bcm_voter_commit(*(undefined8 *)(*(long *)(lVar8 + 0xb8) + uVar6 * 8));
      uVar6 = (ulong)((int)uVar6 + 1);
    } while (uVar6 < *(ulong *)(lVar8 + 0xc0));
  }
  return 0;
}



//------------------------------------------------------------
// qcom_icc_set_stub @ 0010067c size=8
// signature: undefined qcom_icc_set_stub(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_set_stub(void)

{
  return 0;
}



//------------------------------------------------------------
// qcom_icc_get_bw_stub @ 00100688 size=16
// signature: undefined qcom_icc_get_bw_stub(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_get_bw_stub(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_icc_bcm_init @ 0010069c size=488
// signature: undefined qcom_icc_bcm_init(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

ulong qcom_icc_bcm_init(long param_1,undefined8 *param_2,undefined8 param_3)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  int *piVar8;
  long local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_40 = 0;
  if ((*(char *)((long)param_2 + 0x74) == '\0') && (*(int *)((long)param_2 + 0xc) == 0)) {
    iVar3 = cmd_db_read_addr(*param_2);
    uVar5 = *param_2;
    *(int *)((long)param_2 + 0xc) = iVar3;
    if (iVar3 == 0) {
      pcVar4 = "%s could not find RPMh address\n";
    }
    else {
      piVar8 = (int *)cmd_db_read_aux_data(uVar5,&local_40);
      if ((int *)0xfffffffffffff000 < piVar8) {
        _dev_err(param_3,"%s command db read error (%ld)\n",*param_2,piVar8);
        goto LAB_001006dc;
      }
      if (local_40 != 0) {
        iVar3 = *piVar8;
        if (iVar3 == 0) {
          iVar3 = 1;
        }
        *(int *)(param_2 + 0xf) = iVar3;
        sVar1 = (short)piVar8[1];
        if (sVar1 == 0) {
          sVar1 = 1;
        }
        *(short *)((long)param_2 + 0x7c) = sVar1;
        *(undefined1 *)((long)param_2 + 0x7e) = *(undefined1 *)((long)piVar8 + 6);
        *(undefined1 *)((long)param_2 + 0x7f) = *(undefined1 *)((long)piVar8 + 7);
        param_2[0x10] = param_2 + 0x10;
        param_2[0x11] = param_2 + 0x10;
        param_2[0x12] = param_2 + 0x12;
        param_2[0x13] = param_2 + 0x12;
        if (param_2[0xc] == 0) {
          param_2[0xc] = 1000;
        }
        if (param_2[0x15] != 0) {
          uVar6 = 0;
          do {
            lVar7 = param_2[uVar6 + 0x16];
            if (2 < *(ulong *)(lVar7 + 0x180)) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100880);
              (*pcVar2)();
            }
            uVar6 = (ulong)((int)uVar6 + 1);
            *(undefined8 **)(lVar7 + *(ulong *)(lVar7 + 0x180) * 8 + 0x168) = param_2;
            *(long *)(lVar7 + 0x180) = *(long *)(lVar7 + 0x180) + 1;
          } while (uVar6 < (ulong)param_2[0x15]);
        }
        if ((*(char *)((long)param_2 + 0x71) != '\0') || (*(char *)((long)param_2 + 0x72) != '\0'))
        {
          uVar5 = *(undefined8 *)(*(long *)(param_1 + 0xb8) + (long)*(int *)(param_2 + 0x14) * 8);
          qcom_icc_bcm_voter_add(uVar5,param_2);
          uVar6 = qcom_icc_bcm_voter_commit(uVar5);
          piVar8 = (int *)(uVar6 & 0xffffffff);
          if ((int)uVar6 != 0) {
            _dev_err(param_3,"failed to place initial vote for %s\n",*param_2);
          }
          goto LAB_001006dc;
        }
        goto LAB_001006d8;
      }
      uVar5 = *param_2;
      pcVar4 = "%s command db missing or partial aux data\n";
    }
    _dev_err(param_3,pcVar4,uVar5);
    piVar8 = (int *)0xffffffea;
  }
  else {
LAB_001006d8:
    piVar8 = (int *)0x0;
  }
LAB_001006dc:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)piVar8 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_icc_rpmh_configure_qos @ 00100888 size=600
// signature: undefined qcom_icc_rpmh_configure_qos(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

int qcom_icc_rpmh_configure_qos(long param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  
  uVar6 = *(ulong *)(param_1 + 0x78);
  if (uVar6 != 0) {
    uVar10 = 0;
    do {
      puVar8 = *(undefined8 **)(*(long *)(param_1 + 0x70) + uVar10 * 8);
      iVar4 = *(int *)(puVar8 + 0x14);
      if (*(char *)((long)puVar8 + 0x73) == '\0') {
        if ((iVar4 == 0) && (puVar8[0x15] != 0)) {
          uVar7 = 0;
          do {
            if (*(long *)(puVar8[uVar7 + 0x16] + 400) != 0) {
              iVar4 = 0;
              goto LAB_001008e0;
            }
            uVar7 = (ulong)((int)uVar7 + 1);
          } while (uVar7 < (ulong)puVar8[0x15]);
        }
      }
      else {
LAB_001008e0:
        uVar2 = *(undefined1 *)((long)puVar8 + 0x71);
        *(undefined1 *)((long)puVar8 + 0x71) = 1;
        uVar9 = *(undefined8 *)(*(long *)(param_1 + 0xb8) + (long)iVar4 * 8);
        qcom_icc_bcm_voter_add(uVar9,puVar8);
        iVar4 = qcom_icc_bcm_voter_commit(uVar9);
        *(undefined1 *)((long)puVar8 + 0x71) = uVar2;
        if (iVar4 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x68),"failed to vote BW to %s for QoS\n",*puVar8);
          return iVar4;
        }
        uVar6 = *(ulong *)(param_1 + 0x78);
      }
      uVar10 = (ulong)((int)uVar10 + 1);
    } while (uVar10 < uVar6);
  }
  uVar1 = *(undefined4 *)(param_1 + 0xb0);
  uVar9 = *(undefined8 *)(param_1 + 0xa8);
  iVar4 = clk_bulk_prepare(uVar1,uVar9);
  if (iVar4 == 0) {
    iVar4 = clk_bulk_enable(uVar1,uVar9);
    if (iVar4 == 0) {
      uVar6 = *(ulong *)(param_1 + 0x88);
      if (uVar6 != 0) {
        uVar10 = 0;
        do {
          lVar5 = *(long *)(*(long *)(param_1 + 0x80) + uVar10 * 8);
          if ((lVar5 != 0) && (*(long *)(lVar5 + 400) != 0)) {
            if (*(int *)((code *)**(undefined8 **)(lVar5 + 0x198) + -4) != 0x77c21e4c) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1009c4);
              (*pcVar3)();
            }
            (*(code *)**(undefined8 **)(lVar5 + 0x198))();
            uVar6 = *(ulong *)(param_1 + 0x88);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar6);
      }
      uVar1 = *(undefined4 *)(param_1 + 0xb0);
      uVar9 = *(undefined8 *)(param_1 + 0xa8);
      clk_bulk_disable(uVar1,uVar9);
      clk_bulk_unprepare(uVar1,uVar9);
      uVar6 = *(ulong *)(param_1 + 0x78);
      if (uVar6 != 0) {
        uVar10 = 0;
        do {
          lVar5 = *(long *)(*(long *)(param_1 + 0x70) + uVar10 * 8);
          iVar4 = *(int *)(lVar5 + 0xa0);
          if (*(char *)(lVar5 + 0x73) == '\0') {
            if ((iVar4 == 0) && (*(ulong *)(lVar5 + 0xa8) != 0)) {
              uVar7 = 0;
              do {
                if (*(long *)(*(long *)(lVar5 + uVar7 * 8 + 0xb0) + 400) != 0) {
                  iVar4 = 0;
                  goto LAB_00100a04;
                }
                uVar7 = (ulong)((int)uVar7 + 1);
              } while (uVar7 < *(ulong *)(lVar5 + 0xa8));
            }
          }
          else {
LAB_00100a04:
            uVar9 = *(undefined8 *)(*(long *)(param_1 + 0xb8) + (long)iVar4 * 8);
            qcom_icc_bcm_voter_add(uVar9);
            qcom_icc_bcm_voter_commit(uVar9);
            uVar6 = *(ulong *)(param_1 + 0x78);
          }
          uVar10 = (ulong)((int)uVar10 + 1);
        } while (uVar10 < uVar6);
      }
      return 0;
    }
    clk_bulk_unprepare(uVar1,uVar9);
  }
  _dev_err(*(undefined8 *)(param_1 + 0x68),"failed to enable clocks for QoS\n");
  return iVar4;
}



//------------------------------------------------------------
// qcom_icc_rpmh_probe @ 00100ae4 size=1448
// signature: undefined qcom_icc_rpmh_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_icc_rpmh_probe(long param_1)

{
  long lVar1;
  undefined *puVar2;
  long lVar3;
  char cVar4;
  undefined *puVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined4 *puVar11;
  long lVar12;
  undefined8 uVar13;
  long *plVar14;
  size_t sVar15;
  size_t sVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  long lVar20;
  undefined8 *puVar21;
  char *__s;
  ulong uVar22;
  char *__s_00;
  
  lVar1 = param_1 + 0x10;
  puVar9 = (undefined8 *)of_device_get_match_data(lVar1);
  if (puVar9 == (undefined8 *)0x0) {
LAB_00100d7c:
    uVar19 = 0xffffffea;
    goto LAB_00100d80;
  }
  lVar3 = puVar9[1];
  uVar18 = puVar9[2];
  lVar10 = devm_kmalloc(lVar1,0xd0,0xdc0);
  if (lVar10 != 0) {
    uVar19 = uVar18 << 3;
    if (uVar18 >> 0x3d != 0) {
      uVar19 = 0xffffffffffffffff;
    }
    lVar12 = uVar19 + 8;
    if (0xfffffffffffffff7 < uVar19) {
      lVar12 = -1;
    }
    puVar11 = (undefined4 *)devm_kmalloc(lVar1,lVar12,0xdc0);
    if (puVar11 != (undefined4 *)0x0) {
      lVar12 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,stub",0);
      uVar13 = *(undefined8 *)(param_1 + 0x2f8);
      *(bool *)(lVar10 + 200) = lVar12 != 0;
      lVar12 = of_find_property(uVar13,"qcom,skip-qos",0);
      *(undefined4 **)(lVar10 + 0x60) = puVar11;
      *(bool *)(lVar10 + 0xc9) = lVar12 != 0;
      *(code **)(lVar10 + 0x20) = qcom_icc_set_stub;
      *(code **)(lVar10 + 0x28) = qcom_icc_aggregate_stub;
      *(undefined **)(lVar10 + 0x48) = &qcom_icc_xlate_extended;
      *(long *)(lVar10 + 0x50) = lVar1;
      *(code **)(lVar10 + 0x30) = qcom_icc_pre_aggregate_stub;
      *(code **)(lVar10 + 0x38) = qcom_icc_get_bw_stub;
      icc_provider_init(lVar10);
      *(long *)(lVar10 + 0x68) = lVar1;
      *(undefined8 *)(lVar10 + 0x70) = puVar9[3];
      *(undefined8 *)(lVar10 + 0x80) = puVar9[1];
      *(undefined8 *)(lVar10 + 0x88) = puVar9[2];
      if (*(char *)(lVar10 + 200) == '\0') {
        *(undefined8 *)(lVar10 + 0x78) = puVar9[4];
        uVar19 = puVar9[6];
        *(ulong *)(lVar10 + 0xc0) = uVar19;
        if (uVar19 >> 0x3d != 0) {
          uVar19 = 0xfffffff4;
          *(undefined8 *)(lVar10 + 0xb8) = 0;
          goto LAB_00100d80;
        }
        lVar12 = devm_kmalloc(lVar1,uVar19 << 3,0xdc0);
        *(long *)(lVar10 + 0xb8) = lVar12;
        if (lVar12 == 0) goto LAB_00100d74;
        lVar12 = of_device_get_match_data(*(undefined8 *)(lVar10 + 0x68));
        if (lVar12 == 0) goto LAB_00100d7c;
        if (*(long *)(lVar10 + 0x78) != 0) {
          uVar19 = 0;
          do {
            lVar20 = *(long *)(*(long *)(lVar10 + 0x70) + uVar19 * 8);
            __s = *(char **)(*(long *)(lVar12 + 0x28) + (long)*(int *)(lVar20 + 0xa0) * 8);
            uVar22 = is_voter_disabled(__s);
            if ((uVar22 & 1) != 0) {
              *(undefined1 *)(lVar20 + 0x74) = 1;
              uVar22 = *(ulong *)(lVar10 + 0x88);
              if (uVar22 != 0) {
                uVar17 = 0;
                lVar20 = *(long *)(lVar10 + 0x80);
                do {
                  puVar21 = *(undefined8 **)(lVar20 + uVar17 * 8);
                  if (puVar21 != (undefined8 *)0x0) {
                    __s_00 = (char *)*puVar21;
                    sVar15 = strlen(__s_00);
                    sVar16 = strlen(__s);
                    iVar8 = strcmp(__s_00 + (sVar15 - sVar16),__s);
                    if (iVar8 == 0) {
                      *(undefined1 *)((long)puVar21 + 0x1b6) = 1;
                      uVar22 = *(ulong *)(lVar10 + 0x88);
                    }
                  }
                  uVar17 = (ulong)((int)uVar17 + 1);
                } while (uVar17 < uVar22);
              }
            }
            uVar19 = (ulong)((int)uVar19 + 1);
          } while (uVar19 < *(ulong *)(lVar10 + 0x78));
        }
        if (*(long *)(lVar10 + 0xc0) != 0) {
          uVar22 = 0;
          do {
            if ((*(long *)(puVar9[5] + uVar22 * 8) != 0) &&
               (uVar19 = is_voter_disabled(), (uVar19 & 1) == 0)) {
              lVar12 = uVar22 * 8;
              uVar13 = of_bcm_voter_get(*(undefined8 *)(lVar10 + 0x68),
                                        *(undefined8 *)(puVar9[5] + lVar12));
              *(undefined8 *)(*(long *)(lVar10 + 0xb8) + lVar12) = uVar13;
              uVar19 = *(ulong *)(*(long *)(lVar10 + 0xb8) + lVar12);
              if (0xfffffffffffff000 < uVar19) {
                uVar19 = uVar19 & 0xffffffff;
                goto LAB_00100d80;
              }
            }
            uVar22 = uVar22 + 1;
          } while (uVar22 < *(ulong *)(lVar10 + 0xc0));
        }
      }
      plVar14 = (long *)platform_get_resource(param_1,0x200,0);
      if (plVar14 == (long *)0x0) {
        *(undefined8 *)(lVar10 + 0xa0) = 0;
      }
      else {
        uVar19 = devm_ioremap(lVar1,*plVar14,(plVar14[1] - *plVar14) + 1);
        if (uVar19 < 0xfffffffffffff001) {
          uVar19 = __devm_regmap_init_mmio_clk(lVar1,0,uVar19,*puVar9,0,0);
        }
        *(ulong *)(lVar10 + 0xa0) = uVar19;
        if (0xfffffffffffff000 < uVar19) {
          uVar19 = uVar19 & 0xffffffff;
          goto LAB_00100d80;
        }
      }
      uVar7 = devm_clk_bulk_get_all(*(undefined8 *)(lVar10 + 0x68),lVar10 + 0xa8);
      *(uint *)(lVar10 + 0xb0) = uVar7;
      if ((int)uVar7 < 0) {
        uVar19 = (ulong)uVar7;
        goto LAB_00100d80;
      }
      if (*(long *)(lVar10 + 0x78) != 0) {
        uVar19 = 0;
        do {
          qcom_icc_bcm_init(lVar10,*(undefined8 *)(*(long *)(lVar10 + 0x70) + uVar19 * 8),lVar1);
          uVar19 = uVar19 + 1;
        } while (uVar19 < *(ulong *)(lVar10 + 0x78));
      }
      if (uVar18 != 0) {
        uVar22 = 0;
        do {
          puVar9 = *(undefined8 **)(lVar3 + uVar22 * 8);
          if ((puVar9 != (undefined8 *)0x0) && (*(char *)((long)puVar9 + 0x1b6) == '\0')) {
            uVar13 = dev_get_regmap(*(undefined8 *)(lVar10 + 0x68),0);
            puVar9[0x31] = uVar13;
            uVar17 = icc_node_create(*(undefined2 *)(puVar9 + 0x21));
            if (0xfffffffffffff000 < uVar17) {
              uVar19 = uVar17 & 0xffffffff;
              goto LAB_00101048;
            }
            if (puVar9[0x35] != 0) {
              uVar19 = devm_clk_get(*(undefined8 *)(lVar10 + 0x68));
              puVar9[0x34] = uVar19;
              if (0xfffffffffffff000 < uVar19) {
                if ((int)uVar19 == -0x205) {
                  uVar19 = 0xfffffdfb;
                }
                else {
                  _dev_err(*(undefined8 *)(lVar10 + 0x68),"failed to get %s, err:(%d)\n",
                           puVar9[0x35],uVar19 & 0xffffffff);
                }
                goto LAB_00101048;
              }
            }
            uVar13 = *puVar9;
            *(undefined8 **)(uVar17 + 0x70) = puVar9;
            *(undefined8 *)(uVar17 + 8) = uVar13;
            icc_node_add(uVar17,lVar10);
            if (*(short *)((long)puVar9 + 0x10a) != 0) {
              uVar19 = 0;
              do {
                if (uVar19 == 0x80) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10108c);
                  (*pcVar6)();
                }
                icc_link_create(uVar17,*(undefined2 *)((long)puVar9 + uVar19 * 2 + 8));
                uVar19 = uVar19 + 1;
              } while (uVar19 < *(ushort *)((long)puVar9 + 0x10a));
            }
            *(ulong *)(puVar11 + uVar22 * 2 + 2) = uVar17;
          }
          uVar22 = uVar22 + 1;
        } while (uVar22 != uVar18);
      }
      cVar4 = *(char *)(lVar10 + 0xc9);
      *puVar11 = (int)uVar18;
      if (cVar4 == '\0') {
        uVar18 = qcom_icc_rpmh_configure_qos(lVar10);
        uVar19 = uVar18 & 0xffffffff;
        if ((int)uVar18 == 0) goto LAB_00100ed4;
      }
      else {
LAB_00100ed4:
        uVar18 = icc_provider_register(lVar10);
        uVar19 = uVar18 & 0xffffffff;
        if ((int)uVar18 == 0) {
          cVar4 = *(char *)(lVar10 + 200);
          *(long *)(param_1 + 0xa8) = lVar10;
          if (cVar4 == '\0') {
            *(code **)(lVar10 + 0x20) = qcom_icc_set;
            *(code **)(lVar10 + 0x28) = qcom_icc_aggregate;
            *(code **)(lVar10 + 0x30) = qcom_icc_pre_aggregate;
          }
          qcom_icc_debug_register(lVar10);
          mutex_lock(&probe_list_lock);
          puVar5 = PTR_qnoc_probe_list_001015a8;
          puVar2 = (undefined *)(lVar10 + 0x90);
          uVar18 = __list_add_valid(puVar2,PTR_qnoc_probe_list_001015a8,&qnoc_probe_list);
          if ((uVar18 & 1) != 0) {
            PTR_qnoc_probe_list_001015a8 = puVar2;
            *(undefined ***)(lVar10 + 0x90) = &qnoc_probe_list;
            *(undefined **)(lVar10 + 0x98) = puVar5;
            *(undefined **)puVar5 = puVar2;
          }
          mutex_unlock(&probe_list_lock);
          iVar8 = of_get_child_count(*(undefined8 *)(param_1 + 0x2f8));
          if (iVar8 < 1) {
            uVar19 = 0;
            goto LAB_00100d80;
          }
          uVar18 = of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,lVar1);
          uVar19 = uVar18 & 0xffffffff;
          if ((int)uVar18 == 0) goto LAB_00100d80;
          icc_provider_deregister(lVar10);
        }
      }
LAB_00101048:
      clk_bulk_put_all(*(undefined4 *)(lVar10 + 0xb0),*(undefined8 *)(lVar10 + 0xa8));
      icc_nodes_remove(lVar10);
      goto LAB_00100d80;
    }
  }
LAB_00100d74:
  uVar19 = 0xfffffff4;
LAB_00100d80:
  return uVar19 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_icc_pre_aggregate_stub @ 00101090 size=4
// signature: undefined qcom_icc_pre_aggregate_stub(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_pre_aggregate_stub(void)

{
  return;
}



//------------------------------------------------------------
// is_voter_disabled @ 00101094 size=152
// signature: undefined is_voter_disabled(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

undefined8 is_voter_disabled(char *param_1)

{
  int iVar1;
  ulong uVar2;
  size_t sVar3;
  long lVar4;
  
  iVar1 = strcmp(param_1,"disp");
  if (((iVar1 != 0) || (uVar2 = socinfo_get_part_info(4), (uVar2 & 1) == 0)) &&
     ((iVar1 = strcmp(param_1,"disp2"), iVar1 != 0 ||
      (uVar2 = socinfo_get_part_info(0xe), (uVar2 & 1) == 0)))) {
    sVar3 = strlen(param_1);
    lVar4 = strnstr(param_1,&DAT_0010143b,sVar3);
    if ((lVar4 == 0) || (uVar2 = socinfo_get_part_info(3), (uVar2 & 1) == 0)) {
      return 0;
    }
  }
  return 1;
}



//------------------------------------------------------------
// of_get_child_count @ 0010112c size=88
// signature: undefined of_get_child_count(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

int of_get_child_count(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = of_get_next_child(param_1,0);
  if (lVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      lVar1 = of_get_next_child(param_1,lVar1);
    } while (lVar1 != 0);
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_icc_rpmh_remove @ 00101188 size=76
// signature: undefined qcom_icc_rpmh_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_rpmh_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  icc_provider_deregister(lVar1);
  qcom_icc_debug_unregister(lVar1);
  clk_bulk_put_all(*(undefined4 *)(lVar1 + 0xb0),*(undefined8 *)(lVar1 + 0xa8));
  icc_nodes_remove(lVar1);
  return 0;
}



//------------------------------------------------------------
// qcom_icc_rpmh_sync_state @ 001011d8 size=332
// signature: undefined qcom_icc_rpmh_sync_state(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_rpmh_sync_state(long param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
  } while (*(long *)(*(long *)(*(long *)(param_1 + 0x88) + 0x28) + (long)iVar2 * 200 + 0xc0) != 0);
  mutex_lock(&probe_list_lock);
  qcom_icc_rpmh_sync_state_probe_count = qcom_icc_rpmh_sync_state_probe_count + 1;
  if (qcom_icc_rpmh_sync_state_probe_count < iVar2) {
    mutex_unlock(&probe_list_lock);
  }
  else {
    for (ppuVar5 = (undefined **)qnoc_probe_list; ppuVar5 != &qnoc_probe_list;
        ppuVar5 = (undefined **)*ppuVar5) {
      if (ppuVar5[6] != (undefined *)0x0) {
        puVar3 = (undefined *)0x0;
        do {
          qcom_icc_bcm_voter_clear_init(*(undefined8 *)(ppuVar5[5] + (long)puVar3 * 8));
          puVar3 = (undefined *)(long)((int)puVar3 + 1);
        } while (puVar3 < ppuVar5[6]);
      }
      puVar3 = ppuVar5[-3];
      if (puVar3 != (undefined *)0x0) {
        puVar6 = (undefined *)0x0;
        do {
          lVar1 = *(long *)(ppuVar5[-4] + (long)puVar6 * 8);
          if ((*(char *)(lVar1 + 0x71) != '\0') || (*(char *)(lVar1 + 0x72) != '\0')) {
            *(undefined1 *)(lVar1 + 0x72) = 0;
            uVar4 = *(undefined8 *)(ppuVar5[5] + (long)*(int *)(lVar1 + 0xa0) * 8);
            qcom_icc_bcm_voter_add(uVar4);
            qcom_icc_bcm_voter_commit(uVar4);
            puVar3 = ppuVar5[-3];
          }
          puVar6 = (undefined *)(long)((int)puVar6 + 1);
        } while (puVar6 < puVar3);
      }
    }
    mutex_unlock(&probe_list_lock);
    _dev_info(param_1,"sync-state\n");
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_add @ 00103000 size=1
// signature: undefined qcom_icc_bcm_voter_add(void)
// callers: [qcom_icc_bcm_init, qcom_icc_rpmh_configure_qos, qcom_icc_rpmh_sync_state, qcom_icc_pre_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_bcm_voter_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00103008 size=1
// signature: undefined clk_set_rate(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103010 size=1
// signature: undefined clk_prepare(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00103018 size=1
// signature: undefined clk_enable(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103020 size=1
// signature: undefined clk_disable(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00103028 size=1
// signature: undefined clk_unprepare(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_commit @ 00103030 size=1
// signature: undefined qcom_icc_bcm_voter_commit(void)
// callers: [qcom_icc_bcm_init, qcom_icc_rpmh_configure_qos, qcom_icc_set, qcom_icc_rpmh_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_bcm_voter_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00103038 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103040 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_bcm_init, qcom_icc_rpmh_configure_qos, qcom_icc_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_addr @ 00103048 size=1
// signature: undefined cmd_db_read_addr(void)
// callers: [qcom_icc_bcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_read_aux_data @ 00103050 size=1
// signature: undefined cmd_db_read_aux_data(void)
// callers: [qcom_icc_bcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_read_aux_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_icc_bcm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_prepare @ 00103060 size=1
// signature: undefined clk_bulk_prepare(void)
// callers: [qcom_icc_rpmh_configure_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_enable @ 00103068 size=1
// signature: undefined clk_bulk_enable(void)
// callers: [qcom_icc_rpmh_configure_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_disable @ 00103070 size=1
// signature: undefined clk_bulk_disable(void)
// callers: [qcom_icc_rpmh_configure_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_unprepare @ 00103078 size=1
// signature: undefined clk_bulk_unprepare(void)
// callers: [qcom_icc_rpmh_configure_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00103080 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103088 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103090 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_provider_init @ 001030a0 size=1
// signature: undefined icc_provider_init(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_provider_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 001030a8 size=1
// signature: undefined platform_get_resource(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001030b0 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 001030b8 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001030c0 size=1
// signature: size_t strlen(char * __s)
// callers: [qcom_icc_rpmh_probe, is_voter_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030c8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_icc_rpmh_probe, is_voter_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_bulk_get_all @ 001030d0 size=1
// signature: undefined devm_clk_bulk_get_all(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_bulk_get_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 001030d8 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_node_create @ 001030e0 size=1
// signature: undefined icc_node_create(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_node_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001030e8 size=1
// signature: undefined devm_clk_get(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_node_add @ 001030f0 size=1
// signature: undefined icc_node_add(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_node_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_link_create @ 001030f8 size=1
// signature: undefined icc_link_create(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_link_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_provider_register @ 00103100 size=1
// signature: undefined icc_provider_register(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_provider_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_icc_debug_register @ 00103108 size=1
// signature: undefined qcom_icc_debug_register(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103110 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_rpmh_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103118 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103120 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_rpmh_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00103128 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_provider_deregister @ 00103130 size=1
// signature: undefined icc_provider_deregister(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_rpmh_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_provider_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_bcm_voter_get @ 00103138 size=1
// signature: undefined of_bcm_voter_get(void)
// callers: [qcom_icc_rpmh_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_bcm_voter_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_put_all @ 00103140 size=1
// signature: undefined clk_bulk_put_all(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_rpmh_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_put_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_nodes_remove @ 00103148 size=1
// signature: undefined icc_nodes_remove(void)
// callers: [qcom_icc_rpmh_probe, qcom_icc_rpmh_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_nodes_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// socinfo_get_part_info @ 00103150 size=1
// signature: undefined socinfo_get_part_info(void)
// callers: [is_voter_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void socinfo_get_part_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00103158 size=1
// signature: undefined strnstr(void)
// callers: [is_voter_disabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 00103160 size=1
// signature: undefined of_get_next_child(void)
// callers: [of_get_child_count]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_icc_debug_unregister @ 00103168 size=1
// signature: undefined qcom_icc_debug_unregister(void)
// callers: [qcom_icc_rpmh_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_debug_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_clear_init @ 00103170 size=1
// signature: undefined qcom_icc_bcm_voter_clear_init(void)
// callers: [qcom_icc_rpmh_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_bcm_voter_clear_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103178 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_icc_rpmh_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



