// Decompiled by Ghidra 12.2
// Program: rmnet_sch.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNET3a797cc4e9 @ 00100214 size=520
// signature: undefined DATARMNET3a797cc4e9(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET3a797cc4e9(long *param_1,long param_2,long *param_3)

{
  long lVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  long *plVar9;
  undefined8 *puVar10;
  long *plVar11;
  undefined8 *puVar12;
  long lVar13;
  
  lVar1 = param_2 + 0x180;
  lVar6 = param_1[5];
  bVar3 = (&DATARMNET93bdeed8cb)[(ulong)*(uint *)((long)param_1 + 0x8c) & 0xf];
  if (*(uint *)(**(long **)(param_2 + 0x40) + 0x3d8) <= *(uint *)(param_2 + 0xa8)) {
    uVar7 = DATARMNETdaae0b9ea8(lVar1);
    if ((3 < (int)uVar7) || (uVar7 == bVar3)) {
      *param_1 = *param_3;
      *param_3 = (long)param_1;
      *(int *)(param_2 + 200) = *(int *)(param_2 + 200) + 1;
      return 1;
    }
    plVar11 = (long *)(lVar1 + (long)(int)uVar7 * 0x28);
    plVar9 = (long *)*plVar11;
    if (plVar9 != (long *)0x0) {
      lVar13 = *plVar9;
      *plVar11 = lVar13;
      *(int *)(plVar11 + 2) = (int)plVar11[2] + -1;
      if (lVar13 == 0) {
        plVar11[1] = 0;
      }
      *plVar9 = 0;
      *(int *)(param_2 + 0xc4) = *(int *)(param_2 + 0xc4) - (int)plVar9[5];
      *(int *)(param_2 + 0xa8) = *(int *)(param_2 + 0xa8) + -1;
      *plVar9 = *param_3;
      *param_3 = (long)plVar9;
      *(int *)(param_2 + 200) = *(int *)(param_2 + 200) + 1;
    }
  }
  puVar8 = (undefined8 *)(lVar1 + (ulong)bVar3 * 0x28);
  puVar10 = (undefined8 *)puVar8[1];
  puVar12 = puVar8;
  if (puVar10 != (undefined8 *)0x0) {
    *param_1 = 0;
    puVar12 = puVar10;
  }
  *puVar12 = param_1;
  puVar8[1] = param_1;
  bVar3 = *(byte *)(param_2 + 0x10);
  *(int *)(puVar8 + 2) = *(int *)(puVar8 + 2) + 1;
  if ((bVar3 >> 5 & 1) == 0) {
    *(int *)(param_2 + 0xc4) = *(int *)(param_2 + 0xc4) + (int)lVar6;
    *(int *)(param_2 + 0xa8) = *(int *)(param_2 + 0xa8) + 1;
  }
  else {
    lVar1 = sp_el0;
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    lVar13 = tpidr_el1;
    piVar2 = (int *)(lVar13 + *(long *)(param_2 + 0x58));
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar5) {
        *piVar2 = *piVar2 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    lVar13 = *(long *)(lVar1 + 0x10) + -1;
    *(int *)(lVar1 + 0x10) = (int)lVar13;
    if ((lVar13 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    lVar13 = tpidr_el1;
    piVar2 = (int *)(*(long *)(param_2 + 0x58) + lVar13 + 4);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar5) {
        *piVar2 = *piVar2 + (int)lVar6;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    lVar6 = *(long *)(lVar1 + 0x10) + -1;
    *(int *)(lVar1 + 0x10) = (int)lVar6;
    if ((lVar6 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET11bbc6360d @ 00100420 size=840
// signature: undefined DATARMNET11bbc6360d(void)
// callers: []
//------------------------------------------------------------

long * DATARMNET11bbc6360d(long param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  long *plVar11;
  long lVar12;
  long *plVar13;
  
  if (*(int *)(param_1 + 400) == 0) {
    uVar10 = 4;
    if (*(int *)(param_1 + 0x1b8) == 0) goto LAB_00100468;
LAB_00100488:
    if ((0 < *(int *)(param_1 + 0x1c0)) && (0 < *(int *)(param_1 + 0x1c4))) {
      uVar10 = 1;
      goto LAB_00100550;
    }
    uVar10 = (uint)(uVar10 != 0);
    if (*(int *)(param_1 + 0x1e0) != 0) goto LAB_001004b8;
LAB_00100470:
    iVar2 = *(int *)(param_1 + 0x208);
  }
  else {
    if ((0 < *(int *)(param_1 + 0x198)) && (uVar10 = 0, 0 < *(int *)(param_1 + 0x19c)))
    goto LAB_00100550;
    uVar10 = 0;
    if (*(int *)(param_1 + 0x1b8) != 0) goto LAB_00100488;
LAB_00100468:
    if (*(int *)(param_1 + 0x1e0) == 0) goto LAB_00100470;
LAB_001004b8:
    if ((0 < *(int *)(param_1 + 0x1e8)) && (0 < *(int *)(param_1 + 0x1ec))) {
      uVar10 = 2;
      goto LAB_00100550;
    }
    if (1 < uVar10) {
      uVar10 = 2;
    }
    iVar2 = *(int *)(param_1 + 0x208);
  }
  if (iVar2 != 0) {
    if ((0 < *(int *)(param_1 + 0x210)) && (0 < *(int *)(param_1 + 0x214))) {
      uVar10 = 3;
      goto LAB_00100550;
    }
    if (2 < uVar10) {
      uVar10 = 3;
    }
  }
  *(undefined8 *)(param_1 + 0x198) = 0x4000000000008;
  *(undefined8 *)(param_1 + 0x1c0) = 0x2000000000006;
  *(undefined8 *)(param_1 + 0x1e8) = 0x1000000000004;
  *(undefined8 *)(param_1 + 0x210) = 0x800000000002;
  if (3 < uVar10) {
    return (long *)0x0;
  }
LAB_00100550:
  plVar11 = (long *)(param_1 + 0x180 + (ulong)uVar10 * 0x28);
  plVar13 = (long *)*plVar11;
  if (plVar13 != (long *)0x0) {
    lVar12 = *plVar13;
    *plVar11 = lVar12;
    *(int *)(plVar11 + 2) = (int)plVar11[2] + -1;
    if (lVar12 == 0) {
      plVar11[1] = 0;
    }
    *plVar13 = 0;
    lVar12 = param_1 + 0x180 + (ulong)uVar10 * 0x28;
    *(int *)(lVar12 + 0x18) = *(int *)(lVar12 + 0x18) + -1;
    bVar3 = *(byte *)(param_1 + 0x10);
    *(int *)(lVar12 + 0x1c) = *(int *)(lVar12 + 0x1c) - (int)plVar13[5];
    if ((bVar3 >> 5 & 1) == 0) {
      *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) - (int)plVar13[5];
      lVar12 = plVar13[0x1b] + (ulong)*(uint *)((long)plVar13 + 0xd4);
      uVar10 = *(uint *)(plVar13 + 5);
      if (*(short *)(lVar12 + 4) == 0) {
        uVar8 = 1;
      }
      else {
        uVar8 = (ulong)*(ushort *)(lVar12 + 6);
      }
      plVar11 = (long *)(param_1 + 0xb0);
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar5) {
          *plVar11 = *plVar11 + (ulong)uVar10;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      plVar11 = (long *)(param_1 + 0xb8);
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar5) {
          *plVar11 = *plVar11 + uVar8;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -1;
    }
    else {
      lVar12 = sp_el0;
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      lVar6 = tpidr_el1;
      lVar7 = plVar13[5];
      piVar1 = (int *)(*(long *)(param_1 + 0x58) + lVar6 + 4);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = *piVar1 - (int)lVar7;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      lVar6 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar6;
      if ((lVar6 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
      lVar9 = *(long *)(param_1 + 0x50);
      lVar7 = tpidr_el1;
      lVar6 = plVar13[0x1b] + (ulong)*(uint *)((long)plVar13 + 0xd4);
      uVar10 = *(uint *)(plVar13 + 5);
      if (*(short *)(lVar6 + 4) == 0) {
        uVar8 = 1;
      }
      else {
        uVar8 = (ulong)*(ushort *)(lVar6 + 6);
      }
      plVar11 = (long *)(lVar9 + lVar7);
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar5) {
          *plVar11 = *plVar11 + (ulong)uVar10;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      plVar11 = (long *)(lVar7 + lVar9 + 8);
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar5) {
          *plVar11 = *plVar11 + uVar8;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      lVar6 = tpidr_el1;
      piVar1 = (int *)(lVar6 + *(long *)(param_1 + 0x58));
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = *piVar1 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      lVar6 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar6;
      if ((lVar6 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
    }
  }
  return plVar13;
}



//------------------------------------------------------------
// DATARMNET5842e6aac7 @ 0010078c size=308
// signature: undefined DATARMNET5842e6aac7(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET5842e6aac7(long param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 400) == 0) {
    uVar2 = 4;
    if (*(int *)(param_1 + 0x1b8) == 0) goto LAB_001007bc;
LAB_001007dc:
    if ((0 < *(int *)(param_1 + 0x1c0)) && (0 < *(int *)(param_1 + 0x1c4))) {
      uVar2 = 1;
      goto LAB_001008a4;
    }
    uVar2 = (uint)(uVar2 != 0);
    if (*(int *)(param_1 + 0x1e0) == 0) goto LAB_001007c4;
LAB_0010080c:
    if ((0 < *(int *)(param_1 + 0x1e8)) && (0 < *(int *)(param_1 + 0x1ec))) {
      uVar2 = 2;
      goto LAB_001008a4;
    }
    if (1 < uVar2) {
      uVar2 = 2;
    }
    iVar1 = *(int *)(param_1 + 0x208);
  }
  else {
    if ((0 < *(int *)(param_1 + 0x198)) && (uVar2 = 0, 0 < *(int *)(param_1 + 0x19c)))
    goto LAB_001008a4;
    uVar2 = 0;
    if (*(int *)(param_1 + 0x1b8) != 0) goto LAB_001007dc;
LAB_001007bc:
    if (*(int *)(param_1 + 0x1e0) != 0) goto LAB_0010080c;
LAB_001007c4:
    iVar1 = *(int *)(param_1 + 0x208);
  }
  if (iVar1 != 0) {
    if ((0 < *(int *)(param_1 + 0x210)) && (0 < *(int *)(param_1 + 0x214))) {
      uVar2 = 3;
      goto LAB_001008a4;
    }
    if (2 < uVar2) {
      uVar2 = 3;
    }
  }
  *(undefined8 *)(param_1 + 0x198) = 0x4000000000008;
  *(undefined8 *)(param_1 + 0x1c0) = 0x2000000000006;
  *(undefined8 *)(param_1 + 0x1e8) = 0x1000000000004;
  *(undefined8 *)(param_1 + 0x210) = 0x800000000002;
  if (3 < uVar2) {
    return 0;
  }
LAB_001008a4:
  return *(undefined8 *)(param_1 + 0x180 + (ulong)uVar2 * 0x28);
}



//------------------------------------------------------------
// DATARMNET757a7de682 @ 001008c4 size=208
// signature: undefined DATARMNET757a7de682(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET757a7de682(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 0x198) = 0x4000000000008;
  uVar1 = *(uint *)(*plVar2 + 0x3d8);
  *(undefined8 *)(param_1 + 0x1c0) = 0x2000000000006;
  uVar1 = uVar1 / 10;
  *(uint *)(param_1 + 0x1a0) = uVar1 << 2;
  *(uint *)(param_1 + 0x1a4) = uVar1 << 3;
  uVar1 = *(uint *)(*plVar2 + 0x3d8);
  *(undefined8 *)(param_1 + 0x1e8) = 0x1000000000004;
  uVar1 = uVar1 / 10;
  *(uint *)(param_1 + 0x1c8) = uVar1 * 3;
  *(uint *)(param_1 + 0x1cc) = uVar1 * 6;
  uVar1 = *(uint *)(*plVar2 + 0x3d8);
  *(undefined8 *)(param_1 + 0x210) = 0x800000000002;
  uVar1 = uVar1 / 10;
  *(uint *)(param_1 + 0x1f0) = uVar1 << 1;
  *(uint *)(param_1 + 500) = uVar1 << 2;
  uVar1 = *(uint *)(*plVar2 + 0x3d8);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 4;
  uVar1 = uVar1 / 10;
  *(uint *)(param_1 + 0x218) = uVar1;
  *(uint *)(param_1 + 0x21c) = uVar1 << 1;
  return 0;
}



//------------------------------------------------------------
// DATARMNET9593ab9587 @ 00100998 size=312
// signature: undefined DATARMNET9593ab9587(void)
// callers: []
//------------------------------------------------------------

void DATARMNET9593ab9587(long param_1)

{
  uint uVar1;
  
  kfree_skb_list_reason(*(undefined8 *)(param_1 + 0x180),1);
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(undefined8 *)(param_1 + 0x188) = 0;
  *(undefined8 *)(param_1 + 0x198) = 0x4000000000008;
  uVar1 = *(uint *)(**(long **)(param_1 + 0x40) + 0x3d8) / 10;
  *(uint *)(param_1 + 0x1a0) = uVar1 << 2;
  *(uint *)(param_1 + 0x1a4) = uVar1 << 3;
  kfree_skb_list_reason(*(undefined8 *)(param_1 + 0x1a8),1);
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0x2000000000006;
  uVar1 = *(uint *)(**(long **)(param_1 + 0x40) + 0x3d8) / 10;
  *(uint *)(param_1 + 0x1c8) = uVar1 * 3;
  *(uint *)(param_1 + 0x1cc) = uVar1 * 6;
  kfree_skb_list_reason(*(undefined8 *)(param_1 + 0x1d0),1);
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0x1000000000004;
  uVar1 = *(uint *)(**(long **)(param_1 + 0x40) + 0x3d8) / 10;
  *(uint *)(param_1 + 0x1f0) = uVar1 << 1;
  *(uint *)(param_1 + 500) = uVar1 << 2;
  kfree_skb_list_reason(*(undefined8 *)(param_1 + 0x1f8),1);
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = 0;
  *(undefined8 *)(param_1 + 0x200) = 0;
  *(undefined8 *)(param_1 + 0x210) = 0x800000000002;
  uVar1 = *(uint *)(**(long **)(param_1 + 0x40) + 0x3d8) / 10;
  *(uint *)(param_1 + 0x218) = uVar1;
  *(uint *)(param_1 + 0x21c) = uVar1 << 1;
  return;
}



//------------------------------------------------------------
// DATARMNET6647342968 @ 00100ad4 size=80
// signature: undefined DATARMNET6647342968(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET6647342968(long param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_2 / 10 << 2;
  uVar2 = param_2 / 10;
  *(uint *)(param_1 + 0x218) = uVar2;
  *(uint *)(param_1 + 0x1a4) = param_2 / 10 << 3;
  *(int *)(param_1 + 0x1a0) = iVar1;
  *(int *)(param_1 + 500) = iVar1;
  *(uint *)(param_1 + 0x1f0) = uVar2 * 2;
  *(uint *)(param_1 + 0x1c8) = uVar2 * 3;
  *(uint *)(param_1 + 0x1cc) = uVar2 * 6;
  *(uint *)(param_1 + 0x21c) = uVar2 * 2;
  return 0;
}



//------------------------------------------------------------
// DATARMNETdaae0b9ea8 @ 00100b24 size=208
// signature: undefined DATARMNETdaae0b9ea8(void)
// callers: [DATARMNET3a797cc4e9]
//------------------------------------------------------------

uint DATARMNETdaae0b9ea8(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = *(uint *)(param_1 + 0x24);
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x38);
  iVar5 = uVar1 - uVar8;
  if (iVar5 < 0) {
    iVar5 = -1;
  }
  if (uVar1 <= uVar8) {
    iVar5 = -1;
  }
  uVar7 = (uint)((int)(uVar1 - uVar8) < -1) << 2;
  uVar3 = *(uint *)(param_1 + 0x60);
  if (uVar1 <= uVar8) {
    uVar7 = 4;
  }
  iVar6 = uVar2 - *(uint *)(param_1 + 0x4c);
  uVar8 = uVar7;
  if (iVar5 <= iVar6) {
    uVar8 = 1;
  }
  if (iVar6 <= iVar5) {
    iVar6 = iVar5;
  }
  if (uVar2 <= *(uint *)(param_1 + 0x4c)) {
    iVar6 = iVar5;
    uVar8 = uVar7;
  }
  uVar4 = *(uint *)(param_1 + 0x88);
  iVar5 = uVar3 - *(uint *)(param_1 + 0x74);
  uVar7 = uVar8;
  if (iVar6 <= iVar5) {
    uVar7 = 2;
  }
  if (iVar5 <= iVar6) {
    iVar5 = iVar6;
  }
  if (uVar3 <= *(uint *)(param_1 + 0x74)) {
    uVar7 = uVar8;
    iVar5 = iVar6;
  }
  uVar8 = uVar7;
  if (iVar5 <= (int)(uVar4 - *(uint *)(param_1 + 0x9c))) {
    uVar8 = 3;
  }
  if (uVar4 <= *(uint *)(param_1 + 0x9c)) {
    uVar8 = uVar7;
  }
  uVar1 = (uint)(uVar1 <= *(uint *)(param_1 + 0x20)) << 2;
  if (*(uint *)(param_1 + 0x48) < uVar2) {
    uVar1 = 1;
  }
  uVar2 = 2;
  if (uVar3 <= *(uint *)(param_1 + 0x70)) {
    uVar2 = uVar1;
  }
  uVar1 = 3;
  if (uVar4 <= *(uint *)(param_1 + 0x98)) {
    uVar1 = uVar2;
  }
  if (3 < uVar8) {
    uVar8 = uVar1;
  }
  return uVar8;
}



//------------------------------------------------------------
// init_module @ 00100c4c size=56
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  _printk(&DAT_00100e18,&DAT_00100df9);
  register_qdisc(&DATARMNET9afaec21de);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c88 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_qdisc(&DATARMNET9afaec21de);
  return;
}



//------------------------------------------------------------
// _printk @ 00102000 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_qdisc @ 00102008 size=1
// signature: undefined register_qdisc(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_qdisc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_qdisc @ 00102010 size=1
// signature: undefined unregister_qdisc(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_qdisc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 00102018 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [DATARMNET3a797cc4e9, DATARMNET11bbc6360d]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_list_reason @ 00102028 size=1
// signature: undefined kfree_skb_list_reason(void)
// callers: [DATARMNET9593ab9587]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_list_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



