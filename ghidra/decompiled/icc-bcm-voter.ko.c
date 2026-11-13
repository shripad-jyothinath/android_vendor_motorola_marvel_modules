// Decompiled by Ghidra 12.2
// Program: icc-bcm-voter.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_bcm_voter_commit @ 0010037c size=116
// signature: undefined __traceiter_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_bcm_voter_commit(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00101ce0;
  plVar2 = DAT_00101ce0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7fd7a6a2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1003cc);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_bcm_voter_commit @ 001003f4 size=260
// signature: undefined trace_event_raw_event_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bcm_voter_commit(long param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x18;
      strcpy((char *)(lVar3 + 0x18),__s);
      *(undefined4 *)(lVar3 + 0xc) = *param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_3[1];
      *(undefined4 *)(lVar3 + 0x14) = param_3[2];
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_bcm_voter_commit @ 001004fc size=348
// signature: undefined perf_trace_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bcm_voter_commit(long param_1,char *param_2,undefined4 *param_3)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10018;
      strcpy((char *)(lVar5 + 0x18),__s);
      *(undefined4 *)(lVar5 + 0xc) = *param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_3[1];
      *(undefined4 *)(lVar5 + 0x14) = param_3[2];
      perf_trace_run_bpf_submit(lVar5,iVar3,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_bcm_voter_commit @ 0010065c size=28
// signature: undefined __bpf_trace_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bcm_voter_commit(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// of_bcm_voter_get @ 0010067c size=276
// signature: undefined of_bcm_voter_get(void)
// callers: []
//------------------------------------------------------------

undefined ** of_bcm_voter_get(long param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  undefined **ppuVar4;
  undefined *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0x2e8), lVar3 == 0)) {
    ppuVar4 = (undefined **)0xffffffffffffffed;
  }
  else {
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = of_property_match_string(lVar3,"qcom,bcm-voter-names",param_2);
      if (iVar2 < 0) {
        ppuVar4 = (undefined **)(long)iVar2;
        goto LAB_00100760;
      }
    }
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = (undefined *)0x0;
    uStack_70 = 0;
    iVar2 = __of_parse_phandle_with_args(lVar3,"qcom,bcm-voters",0,0,iVar2,&local_78);
    puVar1 = local_78;
    if (iVar2 != 0) {
      puVar1 = (undefined *)0x0;
    }
    mutex_lock(bcm_voter_lock);
    ppuVar4 = &bcm_voters;
    do {
      ppuVar4 = (undefined **)*ppuVar4;
      if (ppuVar4 == &bcm_voters) {
        ppuVar4 = (undefined **)0xfffffffffffffdfb;
        goto LAB_00100754;
      }
    } while (ppuVar4[-0xc] != puVar1);
    ppuVar4 = ppuVar4 + -0xd;
LAB_00100754:
    mutex_unlock(bcm_voter_lock);
  }
LAB_00100760:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ppuVar4;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_add @ 00100794 size=256
// signature: undefined qcom_icc_bcm_voter_add(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_bcm_voter_add(undefined **param_1,long param_2)

{
  ulong uVar1;
  undefined **ppuVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_1 != (undefined **)0x0) {
    mutex_lock(bcm_voter_lock);
    ppuVar2 = &bcm_voters;
    do {
      ppuVar2 = (undefined **)*ppuVar2;
    } while (ppuVar2 != &bcm_voters && ppuVar2 + -0xd != param_1);
    mutex_unlock(bcm_voter_lock);
    if (ppuVar2 != &bcm_voters) {
      mutex_lock(param_1 + 3);
      puVar3 = (undefined8 *)(param_2 + 0x80);
      if ((undefined8 *)*puVar3 == puVar3) {
        puVar4 = (undefined8 *)param_1[10];
        uVar1 = __list_add_valid(puVar3,puVar4,param_1 + 9);
        if ((uVar1 & 1) != 0) {
          param_1[10] = (undefined *)puVar3;
          *(undefined ***)(param_2 + 0x80) = param_1 + 9;
          *(undefined8 **)(param_2 + 0x88) = puVar4;
          *puVar4 = puVar3;
        }
      }
      puVar3 = (undefined8 *)(param_2 + 0x90);
      if ((undefined8 *)*puVar3 == puVar3) {
        puVar4 = (undefined8 *)param_1[0xc];
        uVar1 = __list_add_valid(puVar3,puVar4,param_1 + 0xb);
        if ((uVar1 & 1) != 0) {
          param_1[0xc] = (undefined *)puVar3;
          *(undefined ***)(param_2 + 0x90) = param_1 + 0xb;
          *(undefined8 **)(param_2 + 0x98) = puVar4;
          *puVar4 = puVar3;
        }
      }
      mutex_unlock(param_1 + 3);
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_commit @ 00100898 size=2760
// signature: undefined qcom_icc_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

int qcom_icc_bcm_voter_commit(undefined **param_1)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  long lVar16;
  undefined8 uVar17;
  undefined *puVar18;
  undefined *puVar19;
  undefined **ppuVar20;
  undefined **ppuVar21;
  ulong uVar22;
  undefined **ppuVar23;
  undefined **ppuVar24;
  undefined8 *puVar25;
  uint uVar26;
  ulong uVar27;
  undefined8 local_398;
  undefined8 local_390;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 uStack_378;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  if (param_1 == (undefined **)0x0) {
    iVar8 = 0;
    goto LAB_001012d4;
  }
  mutex_lock(bcm_voter_lock);
  ppuVar20 = &bcm_voters;
  do {
    ppuVar20 = (undefined **)*ppuVar20;
  } while (ppuVar20 != &bcm_voters && ppuVar20 + -0xd != param_1);
  mutex_unlock(bcm_voter_lock);
  if (ppuVar20 == &bcm_voters) {
    iVar8 = -0x13;
    goto LAB_001012d4;
  }
  mutex_lock(param_1 + 3);
  ppuVar21 = param_1 + 9;
  for (ppuVar20 = (undefined **)*ppuVar21; ppuVar20 != ppuVar21; ppuVar20 = (undefined **)*ppuVar20)
  {
    if (*(int *)(ppuVar20 + -3) == 0) {
      cVar3 = *(char *)((long)param_1 + 0x7d);
      local_380 = 0;
      uStack_378 = 0;
      local_390 = 0;
      local_388 = 0;
      local_398 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_98 = 0;
      lVar16 = 0;
      do {
        puVar18 = ppuVar20[5];
        if (puVar18 == (undefined *)0x0) {
          uVar14 = (&local_398)[lVar16];
        }
        else {
          uVar14 = (&local_398)[lVar16];
          uVar27 = (&local_98)[lVar16];
          ppuVar23 = ppuVar20 + 6;
          do {
            puVar19 = *ppuVar23;
            uVar11 = (ulong)*(ushort *)(puVar19 + 0x10e);
            uVar12 = *(long *)(puVar19 + lVar16 * 8 + 0x110) *
                     (ulong)*(ushort *)((long)ppuVar20 + -4);
            uVar22 = *(ushort *)(puVar19 + 0x10c) * uVar11;
            if (uVar12 == 0 || uVar22 <= uVar12) {
              uVar13 = 0;
              if (uVar22 != 0) {
                uVar13 = uVar12 / uVar22;
              }
            }
            else {
              uVar13 = 1;
            }
            if (uVar14 <= uVar13) {
              uVar14 = uVar13;
            }
            uVar12 = *(long *)(puVar19 + lVar16 * 8 + 0x138) *
                     (ulong)*(ushort *)((long)ppuVar20 + -4);
            if (uVar12 == 0 || uVar11 <= uVar12) {
              uVar22 = 0;
              if (uVar11 != 0) {
                uVar22 = uVar12 / uVar11;
              }
            }
            else {
              uVar22 = 1;
            }
            ppuVar23 = ppuVar23 + 1;
            if (uVar27 <= uVar22) {
              uVar27 = uVar22;
            }
            puVar18 = puVar18 + -1;
          } while (puVar18 != (undefined *)0x0);
          (&local_398)[lVar16] = uVar14;
          (&local_98)[lVar16] = uVar27;
        }
        uVar14 = (long)ppuVar20[-4] * uVar14;
        uVar27 = (ulong)*(uint *)(ppuVar20 + -1);
        puVar18 = (undefined *)0x0;
        if (uVar27 != 0) {
          puVar18 = (undefined *)(uVar14 / uVar27);
        }
        puVar19 = (undefined *)0x1;
        if (uVar14 == 0 || uVar27 <= uVar14) {
          puVar19 = puVar18;
        }
        ppuVar20[lVar16 + -0xe] = puVar19;
        uVar27 = (long)ppuVar20[-4] * (&local_98)[lVar16];
        uVar14 = (ulong)*(uint *)(ppuVar20 + -1);
        if ((uVar27 == 0) || (uVar14 <= uVar27)) {
          puVar18 = (undefined *)0x0;
          if (uVar14 != 0) {
            puVar18 = (undefined *)(uVar27 / uVar14);
          }
        }
        else {
          puVar18 = (undefined *)0x1;
        }
        lVar1 = lVar16 + 1;
        ppuVar20[lVar16 + -9] = puVar18;
        lVar16 = lVar1;
      } while (lVar1 != 5);
      if ((*(char *)((long)ppuVar20 + -0xf) != '\0') || (*(char *)((long)ppuVar20 + -0xe) != '\0'))
      {
        if (cVar3 == '\0') {
          if ((ppuVar20[-0xe] != (undefined *)0x0) || (ppuVar20[-9] != (undefined *)0x0))
          goto LAB_00100948;
          lVar16 = -0x40;
          uVar17 = 1;
          ppuVar20[-0xe] = (undefined *)0x1;
          ppuVar20[-0xd] = (undefined *)0x1;
          ppuVar20[-9] = (undefined *)0x1;
        }
        else {
          ppuVar20[-0xe] = (undefined *)0x3e80;
          ppuVar20[-0xd] = (undefined *)0x3e80;
          lVar16 = -0x38;
          ppuVar20[-0xc] = (undefined *)0x3e80;
          uVar17 = 16000;
          ppuVar20[-9] = (undefined *)0x3e80;
          ppuVar20[-8] = (undefined *)0x3e80;
        }
        *(undefined8 *)((long)ppuVar20 + lVar16) = uVar17;
      }
    }
    else {
      lVar16 = 0;
      do {
        ppuVar23 = ppuVar20 + lVar16 + -9;
        *ppuVar23 = (undefined *)0x0;
        ppuVar20[lVar16 + -0xe] = (undefined *)0x0;
        if (ppuVar20[5] != (undefined *)0x0) {
          puVar18 = (undefined *)0x0;
          puVar19 = (undefined *)0x0;
          do {
            puVar10 = ppuVar20[(long)(puVar19 + 6)];
            if ((*(long *)(puVar10 + lVar16 * 8 + 0x110) != 0) ||
               (*(long *)(puVar10 + lVar16 * 8 + 0x138) != 0)) {
              puVar18 = (undefined *)((ulong)puVar18 | (ulong)*(uint *)(ppuVar20 + -3));
              *ppuVar23 = puVar18;
            }
            if (puVar10[lVar16 + 0x160] != '\0') {
              puVar18 = (undefined *)((ulong)puVar18 | (ulong)*(uint *)((long)ppuVar20 + -0x14));
              *ppuVar23 = puVar18;
            }
            puVar19 = (undefined *)(long)((int)puVar19 + 1);
          } while (puVar19 < ppuVar20[5]);
        }
        lVar16 = lVar16 + 1;
      } while (lVar16 != 5);
      if (*(char *)((long)ppuVar20 + -0xf) != '\0') {
        ppuVar20[-9] = (undefined *)((ulong)ppuVar20[-9] | (ulong)*(uint *)(ppuVar20 + -3));
        ppuVar20[-8] = (undefined *)((ulong)ppuVar20[-8] | (ulong)*(uint *)(ppuVar20 + -3));
      }
    }
LAB_00100948:
  }
  puVar18 = param_1[2];
  if (puVar18 == (undefined *)0x0) {
    local_70 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_98 = 0;
    memset(&local_398,0,0x300);
    if (*(char *)((long)param_1 + 0x7c) != '\0') {
      list_sort(0,ppuVar21,cmp_vcd);
      ppuVar20 = (undefined **)*ppuVar21;
      local_70 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_98 = 0;
      if (ppuVar20 != ppuVar21) {
        uVar14 = 0;
        lVar16 = 0;
        iVar8 = 0;
        do {
          if (((undefined **)*ppuVar20 == ppuVar21) ||
             (*(char *)((long)ppuVar20 + -2) != *(char *)((long)*ppuVar20 + -2))) {
            iVar8 = 0;
            uVar26 = *(byte *)(param_1 + 0xf) & 1;
            bVar4 = true;
          }
          else {
            bVar4 = false;
            uVar26 = 0;
            iVar8 = iVar8 + 1;
          }
          if ((long)&local_398 + uVar14 != 0) {
            if ((0x2ff < uVar14) || (0x2ff < uVar14)) goto LAB_00101358;
            puVar18 = ppuVar20[-0xe];
            puVar19 = ppuVar20[-9];
            *(undefined4 *)((long)&local_398 + uVar14) = *(undefined4 *)((long)ppuVar20 + -0x74);
            if (uVar14 - 0x2fc < 0xfffffffffffffd00) goto LAB_00101358;
            uVar15 = 0x40000000;
            if (!bVar4) {
              uVar15 = 0;
            }
            bVar5 = puVar19 != (undefined *)0x0;
            bVar6 = puVar18 != (undefined *)0x0;
            if ((undefined *)0x3ffe < puVar18) {
              puVar18 = (undefined *)0x3fff;
            }
            if ((undefined *)0x3ffe < puVar19) {
              puVar19 = (undefined *)0x3fff;
            }
            *(uint *)((long)&local_398 + uVar14 + 4) =
                 uVar15 | (uint)(bVar5 || bVar6) << 0x1d | (int)puVar18 << 0xe | (uint)puVar19;
            if (uVar14 - 0x2f8 < 0xfffffffffffffd00) goto LAB_00101358;
            *(uint *)((long)&local_390 + uVar14) = uVar26;
          }
          uVar27 = lVar16 * 4;
          if ((0x2b < uVar27) || (0x2b < uVar27)) goto LAB_00101358;
          iVar9 = *(int *)((long)&local_98 + uVar27) + 1;
          *(int *)((long)&local_98 + uVar27) = iVar9;
          if (0xf < iVar9) {
            if (bVar4) {
              lVar16 = lVar16 + 1;
            }
            else {
              if (0x2b < uVar27) goto LAB_00101358;
              *(int *)((long)&local_98 + lVar16 * 4) = iVar9 - iVar8;
              lVar16 = lVar16 + 1;
              if ((0x2b < (ulong)(lVar16 * 4)) || (0x2b < (ulong)(lVar16 * 4))) goto LAB_00101358;
              *(int *)((long)&local_98 + lVar16 * 4) = iVar8;
            }
          }
          ppuVar20 = (undefined **)*ppuVar20;
          uVar14 = uVar14 + 0xc;
        } while (ppuVar20 != ppuVar21);
        if ((int)local_98 != 0) {
          qcom_icc_bcm_log(2,&local_398,&local_98);
          iVar8 = rpmh_write_batch(*param_1,2,&local_398,&local_98);
          if ((iVar8 == -0x10) || (iVar8 == 0)) goto LAB_00100e6c;
          puVar18 = &DAT_00102138;
          goto LAB_00100e0c;
        }
      }
      goto LAB_00100e60;
    }
    iVar8 = 0;
LAB_00100e6c:
    rpmh_invalidate(*param_1);
    ppuVar20 = (undefined **)param_1[9];
    while (ppuVar20 != ppuVar21) {
      ppuVar23 = (undefined **)*ppuVar20;
      uVar14 = __list_del_entry_valid(ppuVar20);
      if ((uVar14 & 1) != 0) {
        puVar18 = *ppuVar20;
        plVar2 = (long *)ppuVar20[1];
        *(long **)(puVar18 + 8) = plVar2;
        *plVar2 = (long)puVar18;
      }
      *ppuVar20 = (undefined *)ppuVar20;
      ppuVar20[1] = (undefined *)ppuVar20;
      ppuVar20 = ppuVar23;
    }
    ppuVar20 = (undefined **)param_1[0xb];
    while (ppuVar23 = ppuVar20, ppuVar23 != param_1 + 0xb) {
      ppuVar20 = (undefined **)*ppuVar23;
      if (((*(char *)((long)param_1 + 0x7c) == '\0') || (ppuVar23[-0xf] != ppuVar23[-0xe])) ||
         (ppuVar23[-10] != ppuVar23[-9])) {
        puVar25 = (undefined8 *)param_1[10];
        ppuVar24 = ppuVar23 + -2;
        uVar14 = __list_add_valid(ppuVar24,puVar25,ppuVar21);
        if ((uVar14 & 1) != 0) {
          param_1[10] = (undefined *)ppuVar24;
          ppuVar23[-2] = (undefined *)ppuVar21;
          ppuVar23[-1] = (undefined *)puVar25;
          *puVar25 = ppuVar24;
        }
      }
      else {
        uVar14 = __list_del_entry_valid(ppuVar23);
        if ((uVar14 & 1) != 0) {
          puVar18 = *ppuVar23;
          plVar2 = (long *)ppuVar23[1];
          *(long **)(puVar18 + 8) = plVar2;
          *plVar2 = (long)puVar18;
        }
        *ppuVar23 = (undefined *)ppuVar23;
        ppuVar23[1] = (undefined *)ppuVar23;
      }
    }
    if ((undefined **)*ppuVar21 != ppuVar21) {
      list_sort(0,ppuVar21,cmp_vcd);
      ppuVar20 = (undefined **)*ppuVar21;
      local_70 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_98 = 0;
      if (ppuVar20 != ppuVar21) {
        uVar14 = 0;
        lVar16 = 0;
        iVar8 = 0;
        do {
          if (((undefined **)*ppuVar20 == ppuVar21) ||
             (*(char *)((long)ppuVar20 + -2) != *(char *)((long)*ppuVar20 + -2))) {
            iVar8 = 0;
            uVar26 = *(byte *)(param_1 + 0xf) >> 1 & 1;
            bVar4 = true;
          }
          else {
            bVar4 = false;
            uVar26 = 0;
            iVar8 = iVar8 + 1;
          }
          if ((long)&local_398 + uVar14 != 0) {
            if ((0x2ff < uVar14) || (0x2ff < uVar14)) goto LAB_00101358;
            puVar18 = ppuVar20[-0xd];
            puVar19 = ppuVar20[-8];
            *(undefined4 *)((long)&local_398 + uVar14) = *(undefined4 *)((long)ppuVar20 + -0x74);
            if (uVar14 - 0x2fc < 0xfffffffffffffd00) goto LAB_00101358;
            uVar15 = 0x40000000;
            if (!bVar4) {
              uVar15 = 0;
            }
            bVar5 = puVar19 != (undefined *)0x0;
            bVar6 = puVar18 != (undefined *)0x0;
            if ((undefined *)0x3ffe < puVar18) {
              puVar18 = (undefined *)0x3fff;
            }
            if ((undefined *)0x3ffe < puVar19) {
              puVar19 = (undefined *)0x3fff;
            }
            *(uint *)((long)&local_398 + uVar14 + 4) =
                 uVar15 | (uint)(bVar5 || bVar6) << 0x1d | (int)puVar18 << 0xe | (uint)puVar19;
            if (uVar14 - 0x2f8 < 0xfffffffffffffd00) goto LAB_00101358;
            *(uint *)((long)&local_390 + uVar14) = uVar26;
          }
          uVar27 = lVar16 * 4;
          if ((0x2b < uVar27) || (0x2b < uVar27)) goto LAB_00101358;
          iVar9 = *(int *)((long)&local_98 + uVar27) + 1;
          *(int *)((long)&local_98 + uVar27) = iVar9;
          if (0xf < iVar9) {
            if (bVar4) {
              lVar16 = lVar16 + 1;
            }
            else {
              if (0x2b < uVar27) goto LAB_00101358;
              *(int *)((long)&local_98 + lVar16 * 4) = iVar9 - iVar8;
              lVar16 = lVar16 + 1;
              if ((0x2b < (ulong)(lVar16 * 4)) || (0x2b < (ulong)(lVar16 * 4))) goto LAB_00101358;
              *(int *)((long)&local_98 + lVar16 * 4) = iVar8;
            }
          }
          ppuVar20 = (undefined **)*ppuVar20;
          uVar14 = uVar14 + 0xc;
        } while (ppuVar20 != ppuVar21);
      }
      qcom_icc_bcm_log(1,&local_398,&local_98);
      iVar8 = rpmh_write_batch(*param_1,1,&local_398,&local_98);
      if (iVar8 == 0) {
        ppuVar20 = (undefined **)*ppuVar21;
        local_70 = 0;
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        if (ppuVar20 != ppuVar21) {
          uVar14 = 0;
          lVar16 = 0;
          iVar8 = 0;
          do {
            if (((undefined **)*ppuVar20 == ppuVar21) ||
               (*(char *)((long)ppuVar20 + -2) != *(char *)((long)*ppuVar20 + -2))) {
              iVar8 = 0;
              uVar26 = *(byte *)(param_1 + 0xf) >> 2 & 1;
              bVar4 = true;
            }
            else {
              bVar4 = false;
              uVar26 = 0;
              iVar8 = iVar8 + 1;
            }
            if ((long)&local_398 + uVar14 != 0) {
              if ((0x2ff < uVar14) || (0x2ff < uVar14)) {
LAB_00101358:
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(1,0x10135c);
                (*pcVar7)();
              }
              puVar18 = ppuVar20[-0xc];
              puVar19 = ppuVar20[-7];
              *(undefined4 *)((long)&local_398 + uVar14) = *(undefined4 *)((long)ppuVar20 + -0x74);
              if (uVar14 - 0x2fc < 0xfffffffffffffd00) goto LAB_00101358;
              uVar15 = 0x40000000;
              if (!bVar4) {
                uVar15 = 0;
              }
              bVar5 = puVar19 != (undefined *)0x0;
              bVar6 = puVar18 != (undefined *)0x0;
              if ((undefined *)0x3ffe < puVar18) {
                puVar18 = (undefined *)0x3fff;
              }
              if ((undefined *)0x3ffe < puVar19) {
                puVar19 = (undefined *)0x3fff;
              }
              *(uint *)((long)&local_398 + uVar14 + 4) =
                   uVar15 | (uint)(bVar5 || bVar6) << 0x1d | (int)puVar18 << 0xe | (uint)puVar19;
              if (uVar14 - 0x2f8 < 0xfffffffffffffd00) goto LAB_00101358;
              *(uint *)((long)&local_390 + uVar14) = uVar26;
            }
            uVar27 = lVar16 * 4;
            if ((0x2b < uVar27) || (0x2b < uVar27)) goto LAB_00101358;
            iVar9 = *(int *)((long)&local_98 + uVar27) + 1;
            *(int *)((long)&local_98 + uVar27) = iVar9;
            if (0xf < iVar9) {
              if (bVar4) {
                lVar16 = lVar16 + 1;
              }
              else {
                if (0x2b < uVar27) goto LAB_00101358;
                *(int *)((long)&local_98 + lVar16 * 4) = iVar9 - iVar8;
                lVar16 = lVar16 + 1;
                if ((0x2b < (ulong)(lVar16 * 4)) || (0x2b < (ulong)(lVar16 * 4))) goto LAB_00101358;
                *(int *)((long)&local_98 + lVar16 * 4) = iVar8;
              }
            }
            ppuVar20 = (undefined **)*ppuVar20;
            uVar14 = uVar14 + 0xc;
          } while (ppuVar20 != ppuVar21);
        }
        qcom_icc_bcm_log(0,&local_398,&local_98);
        iVar9 = rpmh_write_batch(*param_1,0,&local_398,&local_98);
        iVar8 = 0;
        if (iVar9 != 0) {
          _printk(&DAT_00102079,iVar9);
          iVar8 = iVar9;
        }
      }
      else {
        puVar18 = &DAT_00101fba;
LAB_00100e0c:
        _printk(puVar18,iVar8);
      }
    }
  }
  else {
    ppuVar20 = (undefined **)*ppuVar21;
    local_398 = 0;
    local_390 = 0;
    if (ppuVar20 != ppuVar21) {
      uVar14 = (ulong)*(uint *)(puVar18 + 0x18);
      do {
        if ((int)uVar14 != 0) {
          uVar27 = 0;
          do {
            if (uVar27 == 5) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x101358);
              (*pcVar7)();
            }
            puVar10 = ppuVar20[uVar27 - 0xe];
            puVar19 = ppuVar20[uVar27 - 9];
            local_398 = 0;
            local_390 = 0;
            uVar26 = (uint)uVar27;
            if (*(int *)(puVar18 + 0x10) != 0) {
              if (2 < uVar26) {
                _printk(&DAT_00102055,0xffffffea);
                iVar8 = -0x16;
                goto LAB_001012c0;
              }
              uVar26 = (&DAT_00101ea8)[uVar27];
            }
            if ((undefined *)0x3ffe < puVar19) {
              puVar19 = (undefined *)0x3fff;
            }
            if ((undefined *)0x3ffe < puVar10) {
              puVar10 = (undefined *)0x3fff;
            }
            local_398 = (ulong)CONCAT14(*(undefined1 *)((long)ppuVar20 + 0x24),uVar26);
            local_390 = CONCAT44(1,(uint)puVar19 | (int)puVar10 << 0xe | 0x60000000);
            iVar8 = crm_write_bw_vote(*(undefined8 *)(puVar18 + 8),*(int *)(puVar18 + 0x10),
                                      *(undefined4 *)(puVar18 + 0x14),&local_398);
            if (iVar8 != 0) {
              puVar18 = &DAT_001020b0;
              goto LAB_00100e0c;
            }
            uVar14 = (ulong)*(uint *)(puVar18 + 0x18);
            uVar27 = uVar27 + 1;
          } while (uVar27 < uVar14);
        }
        ppuVar20 = (undefined **)*ppuVar20;
      } while (ppuVar20 != ppuVar21);
    }
LAB_00100e60:
    iVar8 = 0;
  }
LAB_001012c0:
  ppuVar20 = (undefined **)*ppuVar21;
  while (ppuVar20 != ppuVar21) {
    ppuVar23 = (undefined **)*ppuVar20;
    uVar14 = __list_del_entry_valid(ppuVar20);
    if ((uVar14 & 1) != 0) {
      puVar18 = *ppuVar20;
      plVar2 = (long *)ppuVar20[1];
      *(long **)(puVar18 + 8) = plVar2;
      *plVar2 = (long)puVar18;
    }
    *ppuVar20 = (undefined *)ppuVar20;
    ppuVar20[1] = (undefined *)ppuVar20;
    ppuVar20 = ppuVar23;
  }
  mutex_unlock(param_1 + 3);
LAB_001012d4:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_clear_init @ 00101364 size=136
// signature: undefined qcom_icc_bcm_voter_clear_init(void)
// callers: []
//------------------------------------------------------------

void qcom_icc_bcm_voter_clear_init(undefined **param_1)

{
  undefined **ppuVar1;
  
  if (param_1 != (undefined **)0x0) {
    mutex_lock(bcm_voter_lock);
    ppuVar1 = &bcm_voters;
    do {
      ppuVar1 = (undefined **)*ppuVar1;
    } while (ppuVar1 != &bcm_voters && ppuVar1 + -0xd != param_1);
    mutex_unlock(bcm_voter_lock);
    if (ppuVar1 != &bcm_voters) {
      mutex_lock(param_1 + 3);
      *(undefined1 *)((long)param_1 + 0x7d) = 0;
      mutex_unlock(param_1 + 3);
    }
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_bcm_voter_commit @ 001013f0 size=112
// signature: undefined trace_raw_output_bcm_voter_commit(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bcm_voter_commit(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s cmd_addr=0x%x cmd_data=0x%x cmd_wait=%u\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// cmp_vcd @ 00101464 size=16
// signature: undefined cmp_vcd(void)
// callers: []
//------------------------------------------------------------

int cmp_vcd(undefined8 param_1,long param_2,long param_3)

{
  return (uint)*(byte *)(param_2 + -2) - (uint)*(byte *)(param_3 + -2);
}



//------------------------------------------------------------
// qcom_icc_bcm_log @ 00101474 size=144
// signature: undefined qcom_icc_bcm_log(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

void qcom_icc_bcm_log(uint param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    iVar3 = -1;
    do {
      iVar3 = iVar3 + 1;
    } while (*(int *)(param_3 + (long)iVar3 * 4) != 0);
    if (0 < iVar3) {
      if (2 < param_1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1015ec);
        (*pcVar2)();
      }
      iVar4 = 0;
      uVar1 = sp_el0;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar3 != iVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_probe @ 001015f0 size=580
// signature: undefined qcom_icc_bcm_voter_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_icc_bcm_voter_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  undefined8 local_50;
  long local_48;
  
  lVar10 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x2f8);
  local_50 = 0;
  plVar6 = (long *)devm_kmalloc(lVar1,0x80,0xdc0);
  if (plVar6 != (long *)0x0) {
    *plVar6 = lVar1;
    plVar6[1] = lVar10;
    *(undefined1 *)((long)plVar6 + 0x7d) = 1;
    lVar7 = of_find_property(lVar10,"qcom,no-amc",0);
    *(bool *)((long)plVar6 + 0x7c) = lVar7 == 0;
    iVar4 = of_property_read_variable_u32_array(lVar10,"qcom,tcs-wait",plVar6 + 0xf,1,0);
    if (iVar4 < 0) {
      *(undefined4 *)(plVar6 + 0xf) = 3;
    }
    __mutex_init(plVar6 + 3,"&voter->lock",&qcom_icc_bcm_voter_probe___key);
    plVar6[9] = (long)(plVar6 + 9);
    plVar6[10] = (long)(plVar6 + 9);
    plVar6[0xb] = (long)(plVar6 + 0xb);
    plVar6[0xc] = (long)(plVar6 + 0xb);
    iVar4 = of_property_read_string(lVar10,"qcom,crm-name",&local_50);
    if (iVar4 != 0) {
LAB_001016dc:
      mutex_lock(bcm_voter_lock);
      puVar3 = PTR_bcm_voters_00101ba0;
      plVar2 = plVar6 + 0xd;
      uVar8 = __list_add_valid(plVar2,PTR_bcm_voters_00101ba0,&bcm_voters);
      if ((uVar8 & 1) != 0) {
        PTR_bcm_voters_00101ba0 = (undefined *)plVar2;
        plVar6[0xd] = (long)&bcm_voters;
        plVar6[0xe] = (long)puVar3;
        *(long **)puVar3 = plVar2;
      }
      mutex_unlock(bcm_voter_lock);
      uVar8 = 0;
      goto LAB_00101784;
    }
    lVar7 = devm_kmalloc(lVar1,0x20,0xdc0);
    if (lVar7 != 0) {
      uVar8 = crm_get_device(local_50);
      *(ulong *)(lVar7 + 8) = uVar8;
      if (0xfffffffffffff000 < uVar8) {
        if (uVar8 == 0xffffffffffffffed) {
          _dev_err(lVar1,"crm_name=%s unavailable\n",local_50);
          uVar8 = 0xfffffdfb;
        }
        goto LAB_00101784;
      }
      *(undefined4 *)(lVar7 + 0x10) = 0;
      uVar5 = of_property_read_variable_u32_array(lVar10,"qcom,crm-client-idx",lVar7 + 0x14,1,0);
      if ((int)uVar5 < 0) {
        pcVar9 = "Error getting crm-client-idx, ret=%d\n";
      }
      else {
        uVar5 = of_property_read_variable_u32_array(lVar10,"qcom,crm-pwr-states",lVar7 + 0x18,1,0);
        if (-1 < (int)uVar5) {
          plVar6[2] = lVar7;
          goto LAB_001016dc;
        }
        pcVar9 = "Error getting crm-pwr-states, ret=%d\n";
      }
      uVar8 = (ulong)uVar5;
      _dev_err(lVar1,pcVar9,uVar8);
      goto LAB_00101784;
    }
  }
  uVar8 = 0xfffffff4;
LAB_00101784:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_icc_bcm_voter_remove @ 00101838 size=144
// signature: undefined qcom_icc_bcm_voter_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_bcm_voter_remove(long param_1)

{
  long *plVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  puVar4 = *(undefined **)(param_1 + 0x2f8);
  mutex_lock(bcm_voter_lock);
  ppuVar3 = &bcm_voters;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &bcm_voters) goto LAB_001018a8;
  } while (ppuVar3[-0xc] != puVar4);
  uVar2 = __list_del_entry_valid(ppuVar3);
  if ((uVar2 & 1) != 0) {
    puVar4 = *ppuVar3;
    plVar1 = (long *)ppuVar3[1];
    *(long **)(puVar4 + 8) = plVar1;
    *plVar1 = (long)puVar4;
  }
  *ppuVar3 = (undefined *)0xdead000000000100;
  ppuVar3[1] = (undefined *)0xdead000000000122;
LAB_001018a8:
  mutex_unlock(bcm_voter_lock);
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010193c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_icc_bcm_voter_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// strlen @ 00104000 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_bcm_voter_commit, trace_event_raw_event_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00104008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00104010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_bcm_voter_commit, trace_event_raw_event_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00104018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00104020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_bcm_voter_commit, qcom_icc_bcm_voter_commit, trace_event_raw_event_bcm_voter_commit, of_bcm_voter_get, qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00104030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00104038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00104040 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00104048 size=1
// signature: undefined of_property_match_string(void)
// callers: [of_bcm_voter_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104050 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [of_bcm_voter_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104058 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_icc_bcm_voter_add, qcom_icc_bcm_voter_commit, qcom_icc_bcm_voter_remove, qcom_icc_bcm_voter_clear_init, of_bcm_voter_get, qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104060 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_icc_bcm_voter_add, qcom_icc_bcm_voter_commit, qcom_icc_bcm_voter_remove, qcom_icc_bcm_voter_clear_init, of_bcm_voter_get, qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104068 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_icc_bcm_voter_add, qcom_icc_bcm_voter_commit, qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_write_bw_vote @ 00104070 size=1
// signature: undefined crm_write_bw_vote(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_write_bw_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104078 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// list_sort @ 00104080 size=1
// signature: undefined list_sort(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void list_sort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104088 size=1
// signature: undefined _printk(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_write_batch @ 00104090 size=1
// signature: undefined rpmh_write_batch(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_write_batch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmh_invalidate @ 00104098 size=1
// signature: undefined rpmh_invalidate(void)
// callers: [qcom_icc_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmh_invalidate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040a0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_icc_bcm_voter_commit, qcom_icc_bcm_voter_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001040a8 size=1
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
// trace_raw_output_prep @ 001040b0 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 001040b8 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 001040c0 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_bcm_voter_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001040e0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040e8 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001040f0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001040f8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104100 size=1
// signature: undefined of_property_read_string(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_get_device @ 00104108 size=1
// signature: undefined crm_get_device(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104110 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_icc_bcm_voter_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



