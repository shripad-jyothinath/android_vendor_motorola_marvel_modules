// Decompiled by Ghidra 12.2
// Program: rmnet_perf_tether.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNETe70d5ec61a @ 00100284 size=844
// signature: undefined DATARMNETe70d5ec61a(void)
// callers: []
//------------------------------------------------------------

void DATARMNETe70d5ec61a(long param_1,long param_2)

{
  ushort *puVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  long *plVar9;
  uint uVar10;
  long lVar11;
  char *pcVar12;
  undefined8 *puVar13;
  int local_5c;
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  local_5c = 0;
  if ((configure_knob1 != 0 || configure_knob2 != 0) &&
     (iVar6 = DATARMNET233bccd449(param_2,&local_5c,1,0), local_5c != 0)) {
    uVar7 = _raw_spin_lock_irqsave(&DATARMNETcf56327171);
    if (((&DATARMNET031f18e039)[(uint)(iVar6 * 0x61c88647) >> 0x1b] != 0) &&
       (puVar13 = (undefined8 *)((&DATARMNET031f18e039)[(uint)(iVar6 * 0x61c88647) >> 0x1b] + -0x10)
       , puVar13 != (undefined8 *)0x0)) {
      do {
        if (*(short *)(param_2 + 0xb4) == -0x227a) {
          lVar11 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8);
          if (((((*(long *)((long)puVar13 + 0x24) == *(long *)(lVar11 + 8) &&
                  *(long *)((long)puVar13 + 0x2c) == *(long *)(lVar11 + 0x10)) &&
                (lVar11 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8),
                puVar13[7] == *(long *)(lVar11 + 0x18) && puVar13[8] == *(long *)(lVar11 + 0x20)))
               && (*(uint *)((long)puVar13 + 0x44) ==
                   (uint)*(byte *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8) +
                                  6))) &&
              ((puVar1 = (ushort *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb6)),
               *(uint *)(puVar13 + 9) == (uint)*puVar1 &&
               (*(uint *)((long)puVar13 + 0x4c) == (uint)puVar1[1])))) &&
             (*(int *)(puVar13 + 10) == 0xb)) {
LAB_001004a0:
            plVar9 = (long *)puVar13[3];
            if (plVar9 != (long *)0x0) {
              lVar11 = puVar13[2];
              *plVar9 = lVar11;
              if (lVar11 != 0) {
                *(long **)(lVar11 + 8) = plVar9;
              }
              puVar13[2] = 0;
              puVar13[3] = 0;
            }
            puVar4 = PTR_DATARMNETc588a190d4_00101568;
            uVar8 = __list_add_valid(puVar13,PTR_DATARMNETc588a190d4_00101568,&DATARMNETc588a190d4);
            if ((uVar8 & 1) != 0) {
              PTR_DATARMNETc588a190d4_00101568 = (undefined *)puVar13;
              *puVar13 = &DATARMNETc588a190d4;
              puVar13[1] = puVar4;
              *(undefined8 **)puVar4 = puVar13;
            }
            _raw_spin_unlock_irqrestore(&DATARMNETcf56327171,uVar7);
            if (((*(ushort *)(param_1 + 0xc) ^ 0xffff) & 0x1200) != 0) goto LAB_0010046c;
            if (configure_knob1 != 0) {
              if (0xffff < knob1) {
                knob1 = 0xffff;
              }
              *(ushort *)(param_1 + 0xe) =
                   (ushort)(knob1 >> 8) & 0xff | (ushort)((knob1 & 0xff00ff) << 8);
            }
            if (configure_knob2 == 0) goto LAB_0010046c;
            if (0xe < knob2) {
              knob2 = 0xe;
            }
            uVar10 = (*(ushort *)(param_1 + 0xc) >> 2 & 0x3c) - 0x14;
            if (uVar10 == 0) goto LAB_0010046c;
            pcVar12 = (char *)(param_1 + 0x14);
            goto LAB_0010057c;
          }
        }
        else if (*(short *)(param_2 + 0xb4) == 8) {
          lVar11 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8);
          if (((*(int *)((long)puVar13 + 0x24) == *(int *)(lVar11 + 0xc)) &&
              (*(int *)(puVar13 + 5) == *(int *)(lVar11 + 0x10))) &&
             ((*(uint *)((long)puVar13 + 0x2c) == (uint)*(byte *)(lVar11 + 9) &&
              (((puVar1 = (ushort *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb6))
                , *(uint *)(puVar13 + 6) == (uint)*puVar1 &&
                (*(uint *)((long)puVar13 + 0x34) == (uint)puVar1[1])) &&
               (*(int *)(puVar13 + 10) == 5)))))) goto LAB_001004a0;
        }
      } while ((puVar13[2] != 0) &&
              (puVar13 = (undefined8 *)(puVar13[2] + -0x10), puVar13 != (undefined8 *)0x0));
    }
    _raw_spin_unlock_irqrestore(&DATARMNETcf56327171,uVar7);
  }
  goto LAB_0010046c;
  while (uVar10 = uVar10 - 1, pcVar12 = pcVar12 + 1, uVar10 != 0) {
LAB_0010057c:
    cVar2 = *pcVar12;
    if (cVar2 != '\x01') {
      if ((cVar2 == '\0') || (uVar10 < 2)) break;
      bVar3 = pcVar12[1];
      if ((bVar3 < 2) || (bVar5 = uVar10 < bVar3, uVar10 = uVar10 - bVar3, bVar5)) break;
      if (cVar2 == '\x03') {
        pcVar12[2] = (char)knob2;
      }
      pcVar12 = pcVar12 + 2 + (bVar3 - 2);
      if (uVar10 == 0) break;
      goto LAB_0010057c;
    }
  }
LAB_0010046c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET233bccd449 @ 001005d0 size=944
// signature: undefined DATARMNET233bccd449(void)
// callers: [DATARMNET6ab362e985, DATARMNETe70d5ec61a]
//------------------------------------------------------------

void DATARMNET233bccd449(long param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  ushort *puVar11;
  int iVar12;
  undefined4 *puVar13;
  long lVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined4 *puVar17;
  long lVar18;
  ushort *puVar19;
  uint *puVar20;
  undefined8 local_48;
  undefined8 local_40;
  uint local_38 [8];
  long local_18;
  
  lVar9 = sp_el0;
  local_18 = *(long *)(lVar9 + 0x638);
  local_38[6] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_40 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    lVar9 = *(long *)(param_1 + 0xd8);
    puVar11 = (ushort *)(lVar9 + (ulong)*(ushort *)(param_1 + 0xb6));
    uVar4 = puVar11[6];
    if ((uVar4 >> 9 & 1) != 0) {
      if (param_3 == 0) {
        if ((uVar4 >> 0xc & 1) == 0) goto LAB_0010067c;
      }
      else if ((uVar4 >> 0xc & 1) != 0) {
LAB_0010067c:
        lVar14 = lVar9 + (ulong)*(ushort *)(param_1 + 0xb8);
        if (param_4 == 0) {
          local_48 = *(undefined8 *)(lVar14 + 8);
          local_40 = *(ulong *)(lVar14 + 0x10);
          puVar15 = (undefined8 *)(lVar14 + 0x18);
        }
        else {
          local_48 = *(undefined8 *)(lVar14 + 0x18);
          local_40 = *(ulong *)(lVar14 + 0x20);
          puVar15 = (undefined8 *)(lVar14 + 8);
        }
        lVar14 = 10;
        lVar18 = 9;
        uVar4 = puVar11[1];
        iVar8 = 0xb;
        local_38[1] = (uint)*puVar15;
        local_38[2] = (uint)((ulong)*puVar15 >> 0x20);
        local_38[3] = (uint)puVar15[1];
        local_38[4] = (uint)*(byte *)(lVar9 + (ulong)*(ushort *)(param_1 + 0xb8) + 6);
LAB_00100734:
        local_38[lVar18 + -4] = (uint)uVar4;
        iVar1 = iVar8 * 4 + -0x21524111;
        local_38[lVar14 + -4] = (uint)*puVar11;
        uVar5 = iVar8 - 4;
        *param_2 = 1;
        uVar7 = (int)local_40 + iVar1;
        uVar16 = ((int)local_48 + iVar1) - uVar7 ^ (uVar7 >> 0x1c | uVar7 * 0x10);
        iVar12 = uVar7 + local_48._4_4_ + iVar1;
        uVar7 = (local_48._4_4_ + iVar1) - uVar16 ^ (uVar16 >> 0x1a | uVar16 << 6);
        iVar1 = uVar16 + iVar12;
        uVar16 = iVar12 - uVar7 ^ (uVar7 >> 0x18 | uVar7 << 8);
        iVar12 = uVar7 + iVar1;
        uVar7 = iVar1 - uVar16 ^ (uVar16 >> 0x10 | uVar16 << 0x10);
        iVar1 = uVar16 + iVar12;
        uVar16 = iVar12 - uVar7 ^ (uVar7 >> 0xd | uVar7 << 0x13);
        iVar12 = uVar7 + iVar1;
        uVar7 = iVar1 - uVar16 ^ (uVar16 >> 0x1c | uVar16 << 4);
        uVar16 = uVar16 + iVar12;
        if (iVar8 - 7U < 0xfffffffc) {
          uVar7 = local_38[1] + uVar7;
          uVar3 = (local_40._4_4_ + iVar12) - uVar7 ^ (uVar7 >> 0x1c | uVar7 * 0x10);
          iVar1 = uVar7 + local_38[0] + uVar16;
          uVar7 = (local_38[0] + uVar16) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
          iVar12 = uVar3 + iVar1;
          uVar16 = iVar1 - uVar7 ^ (uVar7 >> 0x18 | uVar7 << 8);
          iVar1 = uVar7 + iVar12;
          uVar7 = iVar12 - uVar16 ^ (uVar16 >> 0x10 | uVar16 << 0x10);
          iVar2 = uVar16 + iVar1;
          uVar16 = iVar1 - uVar7 ^ (uVar7 >> 0xd | uVar7 << 0x13);
          iVar12 = uVar7 + iVar2;
          uVar7 = iVar2 - uVar16 ^ (uVar16 >> 0x1c | uVar16 << 4);
          uVar16 = uVar16 + iVar12;
          if (iVar8 - 10U < 0xfffffffc) {
            uVar7 = local_38[4] + uVar7;
            uVar3 = (local_38[2] + iVar12) - uVar7 ^ (uVar7 >> 0x1c | uVar7 * 0x10);
            iVar1 = uVar7 + local_38[3] + uVar16;
            uVar7 = (local_38[3] + uVar16) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
            iVar12 = uVar3 + iVar1;
            uVar16 = iVar1 - uVar7 ^ (uVar7 >> 0x18 | uVar7 << 8);
            iVar1 = uVar7 + iVar12;
            uVar7 = iVar12 - uVar16 ^ (uVar16 >> 0x10 | uVar16 << 0x10);
            iVar2 = uVar16 + iVar1;
            iVar12 = uVar7 + iVar2;
            uVar16 = iVar1 - uVar7 ^ (uVar7 >> 0xd | uVar7 << 0x13);
            puVar20 = local_38 + 5;
            uVar7 = iVar2 - uVar16 ^ (uVar16 >> 0x1c | uVar16 << 4);
            uVar16 = uVar16 + iVar12;
          }
          else {
            puVar20 = local_38 + 2;
          }
        }
        else {
          puVar20 = (uint *)((long)&local_40 + 4);
        }
        iVar8 = ((uVar5 + ((uVar5 & 0xff) / 3) * -3 & 0xff) - uVar5) + iVar8;
        if (iVar8 != 4) {
          uVar10 = (ulong)(uVar5 & 0xff) / 3;
          if (iVar8 != 5) {
            if (iVar8 != 6) goto LAB_001006a4;
            if ((uVar5 & 0xff) - 6 < 3) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(1,0x100980);
              (*pcVar6)();
            }
            uVar7 = local_38[uVar10 * 3 + 1] + uVar7;
          }
          uVar16 = local_38[uVar10 * 3] + uVar16;
        }
        uVar7 = (uVar7 ^ uVar16) - (uVar16 >> 0x12 | uVar16 << 0xe);
        uVar5 = (*puVar20 + iVar12 ^ uVar7) - (uVar7 >> 0x15 | uVar7 * 0x800);
        uVar16 = (uVar5 ^ uVar16) - (uVar5 >> 7 | uVar5 * 0x2000000);
        uVar7 = (uVar16 ^ uVar7) - (uVar16 >> 0x10 | uVar16 * 0x10000);
        uVar5 = (uVar7 ^ uVar5) - (uVar7 >> 0x1c | uVar7 * 0x10);
        uVar16 = (uVar5 ^ uVar16) - (uVar5 >> 0x12 | uVar5 * 0x4000);
        uVar7 = (uVar16 ^ uVar7) - (uVar16 >> 8 | uVar16 * 0x1000000);
        goto LAB_001006a4;
      }
    }
  }
  else if (*(short *)(param_1 + 0xb4) == 8) {
    lVar9 = *(long *)(param_1 + 0xd8);
    puVar19 = (ushort *)(lVar9 + (ulong)*(ushort *)(param_1 + 0xb6));
    uVar4 = puVar19[6];
    if ((uVar4 >> 9 & 1) != 0) {
      if (param_3 == 0) {
        if ((uVar4 >> 0xc & 1) == 0) goto LAB_00100658;
      }
      else if ((uVar4 >> 0xc & 1) != 0) {
LAB_00100658:
        lVar14 = lVar9 + (ulong)*(ushort *)(param_1 + 0xb8);
        if (param_4 == 0) {
          puVar13 = (undefined4 *)(lVar14 + 0xc);
          puVar17 = (undefined4 *)(lVar14 + 0x10);
          puVar11 = puVar19 + 1;
        }
        else {
          puVar13 = (undefined4 *)(lVar14 + 0x10);
          puVar17 = (undefined4 *)(lVar14 + 0xc);
          puVar11 = puVar19;
          puVar19 = puVar19 + 1;
        }
        uVar4 = *puVar19;
        lVar18 = 3;
        lVar14 = 4;
        iVar8 = 5;
        local_48 = CONCAT44(*puVar17,*puVar13);
        local_40 = (ulong)*(byte *)(lVar9 + (ulong)*(ushort *)(param_1 + 0xb8) + 9);
        goto LAB_00100734;
      }
    }
  }
  uVar7 = 0;
  *param_2 = 0;
LAB_001006a4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET6ab362e985 @ 00100984 size=924
// signature: undefined DATARMNET6ab362e985(void)
// callers: []
//------------------------------------------------------------

void DATARMNET6ab362e985(long param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  undefined *puVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined4 uVar9;
  long *plVar10;
  long *plVar11;
  long lVar12;
  byte *pbVar13;
  long lVar14;
  int local_3c;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_3c = 0;
  if ((((configure_knob1 == 0 && configure_knob2 == 0) || (*(int *)(param_1 + 0x90) == 0)) ||
      (lVar6 = __dev_get_by_index(&init_net), lVar6 == 0)) ||
     (iVar5 = DATARMNET233bccd449(param_1,&local_3c,0,1), local_3c == 0)) goto LAB_00100cf0;
  uVar7 = _raw_spin_lock_irqsave(&DATARMNETcf56327171);
  puVar3 = DATARMNETc588a190d4;
  if (((undefined **)DATARMNETc588a190d4 == &DATARMNETc588a190d4) ||
     (DATARMNETc588a190d4 == (undefined *)0x0)) {
    uVar8 = 0;
    do {
      plVar10 = (long *)(&DATARMNET031f18e039)[uVar8];
      if (plVar10 != (long *)0x0 && plVar10 != (long *)0x10) {
        plVar11 = (long *)plVar10[1];
        if (plVar11 != (long *)0x0) {
          lVar6 = *plVar10;
          *plVar11 = lVar6;
          if (lVar6 != 0) {
            *(long **)(lVar6 + 8) = plVar11;
          }
          *plVar10 = 0;
          plVar10[1] = 0;
        }
        *(int *)(plVar10 + 2) = iVar5;
        if (*(short *)(param_1 + 0xb4) == -0x227a) {
          lVar14 = 0x34;
          lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
          uVar1 = *(undefined8 *)(lVar6 + 0x20);
          *(undefined8 *)((long)plVar10 + 0x14) = *(undefined8 *)(lVar6 + 0x18);
          *(undefined8 *)((long)plVar10 + 0x1c) = uVar1;
          lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
          lVar12 = *(long *)(lVar6 + 0x10);
          plVar10[5] = *(long *)(lVar6 + 8);
          plVar10[6] = lVar12;
          uVar9 = 0xb;
          lVar6 = 0x3c;
          pbVar13 = (byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 6);
          lVar12 = 0x38;
LAB_00100c84:
          *(uint *)((long)plVar10 + lVar14) = (uint)*pbVar13;
          *(uint *)((long)plVar10 + lVar12) =
               (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6) + 2)
          ;
          uVar2 = *(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
          *(undefined4 *)(plVar10 + 8) = uVar9;
          *(uint *)((long)plVar10 + lVar6) = (uint)uVar2;
        }
        else if (*(short *)(param_1 + 0xb4) == 8) {
          lVar14 = 0x1c;
          *(undefined4 *)((long)plVar10 + 0x14) =
               *(undefined4 *)
                (*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 0x10);
          *(undefined4 *)(plVar10 + 3) =
               *(undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 0xc)
          ;
          uVar9 = 5;
          lVar6 = 0x24;
          pbVar13 = (byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 9);
          lVar12 = 0x20;
          goto LAB_00100c84;
        }
        plVar11 = &DATARMNET031f18e039 + ((uint)(iVar5 * 0x61c88647) >> 0x1b);
        lVar6 = *plVar11;
        *plVar10 = lVar6;
        if (lVar6 != 0) {
          *(long **)(lVar6 + 8) = plVar10;
        }
        *plVar11 = (long)plVar10;
        plVar10[1] = (long)plVar11;
        break;
      }
      bVar4 = uVar8 < 0x1f;
      uVar8 = uVar8 + 1;
    } while (bVar4);
  }
  else {
    uVar8 = __list_del_entry_valid(DATARMNETc588a190d4);
    if ((uVar8 & 1) != 0) {
      lVar6 = *(long *)puVar3;
      plVar10 = *(long **)(puVar3 + 8);
      *(long **)(lVar6 + 8) = plVar10;
      *plVar10 = lVar6;
    }
    *(int *)(puVar3 + 0x20) = iVar5;
    *(undefined8 *)puVar3 = 0xdead000000000100;
    *(undefined8 *)(puVar3 + 8) = 0xdead000000000122;
    if (*(short *)(param_1 + 0xb4) == -0x227a) {
      lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
      uVar1 = *(undefined8 *)(lVar6 + 0x20);
      *(undefined8 *)(puVar3 + 0x24) = *(undefined8 *)(lVar6 + 0x18);
      *(undefined8 *)(puVar3 + 0x2c) = uVar1;
      lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
      uVar1 = *(undefined8 *)(lVar6 + 0x10);
      *(undefined8 *)(puVar3 + 0x38) = *(undefined8 *)(lVar6 + 8);
      *(undefined8 *)(puVar3 + 0x40) = uVar1;
      *(uint *)(puVar3 + 0x44) =
           (uint)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 6);
      *(uint *)(puVar3 + 0x48) =
           (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6) + 2);
      uVar9 = 0xb;
      *(uint *)(puVar3 + 0x4c) =
           (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
LAB_00100bf8:
      *(undefined4 *)(puVar3 + 0x50) = uVar9;
    }
    else if (*(short *)(param_1 + 0xb4) == 8) {
      *(undefined4 *)(puVar3 + 0x24) =
           *(undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 0x10);
      *(undefined4 *)(puVar3 + 0x28) =
           *(undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 0xc);
      *(uint *)(puVar3 + 0x2c) =
           (uint)*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8) + 9);
      *(uint *)(puVar3 + 0x30) =
           (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6) + 2);
      uVar9 = 5;
      *(uint *)(puVar3 + 0x34) =
           (uint)*(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
      goto LAB_00100bf8;
    }
    plVar10 = &DATARMNET031f18e039 + ((uint)(iVar5 * 0x61c88647) >> 0x1b);
    lVar6 = *plVar10;
    plVar11 = (long *)(puVar3 + 0x10);
    *plVar11 = lVar6;
    if (lVar6 != 0) {
      *(long **)(lVar6 + 8) = plVar11;
    }
    *plVar10 = (long)plVar11;
    *(long **)(puVar3 + 0x18) = plVar10;
  }
  _raw_spin_unlock_irqrestore(&DATARMNETcf56327171,uVar7);
LAB_00100cf0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET136e008d70 @ 00100d24 size=300
// signature: undefined DATARMNET136e008d70(void)
// callers: []
//------------------------------------------------------------

void DATARMNET136e008d70(char param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  byte *pbVar7;
  long lVar8;
  
  lVar4 = dev_get_by_name(&init_net,"rmnet_ipa0");
  if (lVar4 != 0) {
    if ((param_1 == '\x01') && (lVar5 = __alloc_skb(0x10,0xa20,0,0xffffffff), lVar5 != 0)) {
      skb_put(lVar5,0x10);
      puVar6 = *(undefined8 **)(lVar5 + 0xe0);
      *puVar6 = 0;
      puVar6[1] = 0;
      pbVar7 = *(byte **)(lVar5 + 0xe0);
      pbVar7[2] = 0;
      pbVar7[3] = 0xc;
      *pbVar7 = *pbVar7 | 0x80;
      *(undefined1 *)(*(long *)(lVar5 + 0xe0) + 4) = 0x1b;
      lVar8 = *(long *)(lVar5 + 0xe0);
      *(undefined1 *)(lVar8 + 0xc) = 1;
      *(bool *)(lVar8 + 0xe) = param_2 == 0;
      *(long *)(lVar5 + 0x10) = lVar4;
      *(undefined2 *)(lVar5 + 0xb4) = 0xf900;
      rmnet_qmap_send(lVar5,0xff,0);
    }
    lVar5 = sp_el0;
    *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
    lVar8 = tpidr_el1;
    piVar1 = (int *)(lVar8 + *(long *)(lVar4 + 0x4d8));
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    lVar4 = *(long *)(lVar5 + 0x10) + -1;
    *(int *)(lVar5 + 0x10) = (int)lVar4;
    if ((lVar4 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5fe3ffe2ab @ 00100e54 size=100
// signature: undefined DATARMNET5fe3ffe2ab(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET5fe3ffe2ab(void)

{
  _rmnet_perf_tether_ingress_hook = DATARMNETe70d5ec61a;
  _rmnet_perf_tether_egress_hook = DATARMNET6ab362e985;
  _rmnet_perf_tether_cmd_hook = DATARMNET136e008d70;
  rmnet_module_hook_register(DATARMNET0762b4f121,3);
  return;
}



//------------------------------------------------------------
// DATARMNET229327cbd2 @ 00100ebc size=68
// signature: undefined DATARMNET229327cbd2(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET229327cbd2(void)

{
  _rmnet_perf_tether_ingress_hook = 0;
  _rmnet_perf_tether_egress_hook = 0;
  _rmnet_perf_tether_cmd_hook = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET0762b4f121,3);
  synchronize_rcu();
  return;
}



//------------------------------------------------------------
// DATARMNET6e31e62d2e @ 00100f04 size=236
// signature: undefined DATARMNET6e31e62d2e(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET6e31e62d2e(undefined8 param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  char *__s1;
  
  __s1 = (char *)*param_3;
  if ((__s1 != (char *)0x0) && (iVar2 = strncmp(__s1,"rmnet_data",10), iVar2 == 0)) {
    if (param_2 == 6) {
      if ((DATARMNET8a1e9920bf != (char *)0x0) &&
         (cVar1 = *DATARMNET8a1e9920bf, *DATARMNET8a1e9920bf = cVar1 + -1,
         (char)(cVar1 + -1) == '\0')) {
        _printk(&DAT_001016cc,"DATARMNET6e31e62d2e",__s1);
        DATARMNET3ece352201();
      }
    }
    else if (param_2 == 5) {
      if (DATARMNET8a1e9920bf == (char *)0x0) {
        _printk(&DAT_001017cc,"DATARMNET6e31e62d2e",__s1);
        iVar2 = DATARMNETaa549ce89a();
        if (iVar2 != 0) {
          _printk(&DAT_00101724,"DATARMNET6e31e62d2e");
        }
      }
      else {
        *DATARMNET8a1e9920bf = *DATARMNET8a1e9920bf + '\x01';
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNETaa549ce89a @ 00100ff0 size=300
// signature: undefined DATARMNETaa549ce89a(void)
// callers: [DATARMNET6e31e62d2e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNETaa549ce89a(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  int iVar5;
  
  DATARMNET8a1e9920bf = (char *)kmalloc_trace(_DAT_001030e0,0xdc0,1);
  if (DATARMNET8a1e9920bf == (char *)0x0) {
    _printk(&DAT_001017a8,"DATARMNETaa549ce89a");
    uVar4 = 0xffffffff;
  }
  else {
    iVar5 = 0x32;
    *DATARMNET8a1e9920bf = *DATARMNET8a1e9920bf + '\x01';
    do {
      puVar2 = (undefined8 *)kmalloc_trace(_DAT_001030e8,0xb20,0x58);
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = puVar2;
        puVar2[1] = puVar2;
        puVar1 = PTR_DATARMNETc588a190d4_00101568;
        puVar2[2] = 0;
        puVar2[3] = 0;
        uVar3 = __list_add_valid(puVar2,puVar1,&DATARMNETc588a190d4);
        if ((uVar3 & 1) != 0) {
          PTR_DATARMNETc588a190d4_00101568 = (undefined *)puVar2;
          *puVar2 = &DATARMNETc588a190d4;
          puVar2[1] = puVar1;
          *(undefined8 **)puVar1 = puVar2;
        }
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    _rmnet_perf_tether_ingress_hook = DATARMNETe70d5ec61a;
    _rmnet_perf_tether_egress_hook = DATARMNET6ab362e985;
    _rmnet_perf_tether_cmd_hook = DATARMNET136e008d70;
    rmnet_module_hook_register(DATARMNET0762b4f121,3);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// DATARMNET3ece352201 @ 0010111c size=288
// signature: undefined DATARMNET3ece352201(void)
// callers: [DATARMNET6e31e62d2e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET3ece352201(void)

{
  undefined *puVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  undefined **ppuVar6;
  long lVar7;
  undefined **ppuVar8;
  
  _rmnet_perf_tether_ingress_hook = 0;
  _rmnet_perf_tether_egress_hook = 0;
  _rmnet_perf_tether_cmd_hook = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET0762b4f121,3);
  synchronize_rcu();
  ppuVar6 = (undefined **)DATARMNETc588a190d4;
  if ((undefined **)DATARMNETc588a190d4 != &DATARMNETc588a190d4) {
    do {
      ppuVar8 = (undefined **)*ppuVar6;
      uVar4 = __list_del_entry_valid(ppuVar6);
      if ((uVar4 & 1) != 0) {
        puVar1 = *ppuVar6;
        plVar3 = (long *)ppuVar6[1];
        *(long **)(puVar1 + 8) = plVar3;
        *plVar3 = (long)puVar1;
      }
      *ppuVar6 = (undefined *)0xdead000000000100;
      ppuVar6[1] = (undefined *)0xdead000000000122;
      kfree(ppuVar6);
      ppuVar6 = ppuVar8;
    } while (ppuVar8 != &DATARMNETc588a190d4);
  }
  lVar7 = 0;
  do {
    lVar5 = (&DATARMNET031f18e039)[lVar7] + -0x10;
    if ((&DATARMNET031f18e039)[lVar7] != 0 && lVar5 != 0) {
      do {
        lVar2 = *(long *)(lVar5 + 0x10);
        plVar3 = *(long **)(lVar5 + 0x18);
        if (plVar3 != (long *)0x0) {
          *plVar3 = lVar2;
          if (lVar2 != 0) {
            *(long **)(lVar2 + 8) = plVar3;
          }
          *(long *)(lVar5 + 0x10) = 0;
          *(undefined8 *)(lVar5 + 0x18) = 0;
        }
        kfree();
      } while ((lVar2 != 0) && (lVar5 = lVar2 + -0x10, lVar5 != 0));
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 0x20);
  kfree(DATARMNET8a1e9920bf);
  DATARMNET8a1e9920bf = 0;
  return;
}



//------------------------------------------------------------
// init_module @ 00101254 size=56
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  _printk(&DAT_0010177a,"DATARMNET5e4be08a32");
  register_netdevice_notifier(0x101590);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101290 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk(&DAT_00101760,"DATARMNET50e3d76d94");
  unregister_netdevice_notifier(0x101590);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [DATARMNET6ab362e985, DATARMNETe70d5ec61a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [DATARMNET6ab362e985, DATARMNETe70d5ec61a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103010 size=1
// signature: undefined __list_add_valid(void)
// callers: [DATARMNETe70d5ec61a, DATARMNETaa549ce89a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNET233bccd449, DATARMNET6ab362e985, DATARMNETe70d5ec61a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_get_by_index @ 00103028 size=1
// signature: undefined __dev_get_by_index(void)
// callers: [DATARMNET6ab362e985]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_get_by_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103030 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [DATARMNET6ab362e985, DATARMNET3ece352201]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_name @ 00103038 size=1
// signature: undefined dev_get_by_name(void)
// callers: [DATARMNET136e008d70]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00103040 size=1
// signature: undefined __alloc_skb(void)
// callers: [DATARMNET136e008d70]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00103048 size=1
// signature: undefined skb_put(void)
// callers: [DATARMNET136e008d70]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_qmap_send @ 00103050 size=1
// signature: undefined rmnet_qmap_send(void)
// callers: [DATARMNET136e008d70]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_qmap_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 00103058 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [DATARMNET136e008d70]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 00103078 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [DATARMNET5fe3ffe2ab, DATARMNETaa549ce89a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 00103080 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [DATARMNET3ece352201, DATARMNET229327cbd2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 00103088 size=1
// signature: undefined synchronize_rcu(void)
// callers: [DATARMNET3ece352201, DATARMNET229327cbd2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103090 size=1
// signature: undefined _printk(void)
// callers: [DATARMNET6e31e62d2e, DATARMNETaa549ce89a, init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice_notifier @ 00103098 size=1
// signature: undefined register_netdevice_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_notifier @ 001030a0 size=1
// signature: undefined unregister_netdevice_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001030a8 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [DATARMNET6e31e62d2e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001030b8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNETaa549ce89a]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001030c0 size=1
// signature: undefined kfree(void)
// callers: [DATARMNET3ece352201]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



