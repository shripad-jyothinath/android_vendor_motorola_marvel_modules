// Decompiled by Ghidra 12.2
// Program: rmnet_offload.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNETd4230b6bfe @ 001007b4 size=60
// signature: undefined DATARMNETd4230b6bfe(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETd4230b6bfe(void)

{
  _rmnet_perf_chain_end = DATARMNETbe30d096c6;
  rmnet_module_hook_register(&DATARMNETcbc211d052,1);
  return;
}



//------------------------------------------------------------
// DATARMNETbe30d096c6 @ 001007f4 size=200
// signature: undefined DATARMNETbe30d096c6(void)
// callers: []
//------------------------------------------------------------

void DATARMNETbe30d096c6(void)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  undefined8 *****local_48;
  undefined8 *****pppppuStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_48 = &local_48;
  local_38 = *(long *)(lVar3 + 0x638);
  pppppuStack_40 = local_48;
  DATARMNET664568fcd0();
  lVar3 = 0;
  iVar2 = 0;
  do {
    for (plVar1 = (long *)(&DATARMNET4791268d67)[lVar3]; plVar1 != (long *)0x0;
        plVar1 = (long *)*plVar1) {
      if (*(char *)((long)plVar1 + 0x62) != '\0') {
        iVar2 = iVar2 + 1;
        DATARMNETa3055c21f2(plVar1,&local_48);
      }
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x20);
  if (iVar2 != 0) {
    DATARMNETa00cda79d0(9);
  }
  DATARMNET6a76048590();
  DATARMNETc70e73c8d4(&local_48);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET560e127137 @ 001008c0 size=48
// signature: undefined DATARMNET560e127137(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET560e127137(void)

{
  _rmnet_perf_chain_end = 0;
  rmnet_module_hook_unregister_no_sync(&DATARMNETcbc211d052,1);
  return;
}



//------------------------------------------------------------
// DATARMNET241493ab9a @ 001008f4 size=420
// signature: undefined DATARMNET241493ab9a(void)
// callers: [__DATARMNET6d2ed4b822]
//------------------------------------------------------------

undefined8 DATARMNET241493ab9a(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  undefined8 *****local_48;
  undefined8 *****pppppuStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_48 = &local_48;
  local_38 = *(long *)(lVar3 + 0x638);
  pppppuStack_40 = local_48;
  if ((param_1 != 3) && (param_2 != 0)) {
    if (param_2 == 1) {
      lVar3 = 0;
      iVar2 = 0;
      do {
        for (plVar1 = (long *)(&DATARMNET4791268d67)[lVar3]; plVar1 != (long *)0x0;
            plVar1 = (long *)*plVar1) {
          if ((*(char *)((long)plVar1 + 0x62) != '\0') && (*(char *)((long)plVar1 + 0x51) == '\x11')
             ) {
            iVar2 = iVar2 + 1;
            DATARMNETa3055c21f2(plVar1,&local_48);
          }
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0x20);
    }
    else if (param_2 == 2) {
      lVar3 = 0;
      iVar2 = 0;
      do {
        for (plVar1 = (long *)(&DATARMNET4791268d67)[lVar3]; plVar1 != (long *)0x0;
            plVar1 = (long *)*plVar1) {
          if ((*(char *)((long)plVar1 + 0x62) != '\0') && (*(char *)((long)plVar1 + 0x51) == '\x06')
             ) {
            iVar2 = iVar2 + 1;
            DATARMNETa3055c21f2(plVar1,&local_48);
          }
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0x20);
    }
    else if (param_2 == 3) {
      lVar3 = 0;
      iVar2 = 0;
      do {
        for (plVar1 = (long *)(&DATARMNET4791268d67)[lVar3]; plVar1 != (long *)0x0;
            plVar1 = (long *)*plVar1) {
          if (*(char *)((long)plVar1 + 0x62) != '\0') {
            iVar2 = iVar2 + 1;
            DATARMNETa3055c21f2(plVar1,&local_48);
          }
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0x20);
    }
    else {
      iVar2 = 0;
    }
    DATARMNETbad3b5165e(0xb,iVar2);
    DATARMNETc70e73c8d4(&local_48);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNETae70636c90 @ 00100a9c size=136
// signature: undefined DATARMNETae70636c90(void)
// callers: [DATARMNETc9dd320f49, DATARMNET95e1703026, DATARMNET345f805b34]
//------------------------------------------------------------

int DATARMNETae70636c90(undefined8 param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = 0;
  iVar1 = 0;
  do {
    for (plVar2 = (long *)(&DATARMNET4791268d67)[lVar3]; plVar2 != (long *)0x0;
        plVar2 = (long *)*plVar2) {
      if (*(char *)((long)plVar2 + 0x62) != '\0') {
        iVar1 = iVar1 + 1;
        DATARMNETa3055c21f2(plVar2,param_1);
      }
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x20);
  return iVar1;
}



//------------------------------------------------------------
// DATARMNETa3055c21f2 @ 00100b28 size=336
// signature: undefined DATARMNETa3055c21f2(void)
// callers: [DATARMNETbe30d096c6, DATARMNET8dc47eb7af, DATARMNETae70636c90, DATARMNET4c7cdc25b7, DATARMNETfbf5798e15, DATARMNET241493ab9a, DATARMNETc38c135c9f]
//------------------------------------------------------------

void DATARMNETa3055c21f2(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  undefined8 *puVar8;
  ulong uVar9;
  long *plVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  
  puVar8 = (undefined8 *)DATARMNETc2a630b113();
  if (*(char *)(param_1 + 0x62) != '\0') {
    uVar4 = *(ushort *)(param_1 + 0x4c);
    uVar5 = *(ushort *)(param_1 + 0x4e);
    puVar12 = (undefined8 *)(param_1 + 0x10);
    plVar10 = (long *)*puVar12;
    if ((short)plVar10[9] == 0) {
      *(undefined2 *)(plVar10 + 9) = 1;
    }
    *(undefined2 *)((long)plVar10 + 0x46) = *(undefined2 *)(param_1 + 0x60);
    if ((undefined8 *)*plVar10 != puVar12) {
      iVar1 = (uint)uVar5 + (uint)uVar4;
      puVar11 = (undefined8 *)*plVar10;
      do {
        puVar13 = (undefined8 *)*puVar11;
        iVar7 = rmnet_frag_descriptor_add_frags_from
                          (plVar10,puVar11,iVar1,*(int *)(puVar11 + 6) - iVar1);
        if (iVar7 == 0) {
          sVar6 = *(short *)(puVar11 + 9);
          if (sVar6 == 0) {
            sVar6 = 1;
          }
          *(short *)(plVar10 + 9) = sVar6 + (short)plVar10[9];
          *(int *)((long)plVar10 + 0x2c) =
               *(int *)((long)plVar10 + 0x2c) + *(int *)((long)puVar11 + 0x2c);
          *(int *)(plVar10 + 5) = (int)plVar10[5] + *(int *)(puVar11 + 5);
        }
        rmnet_recycle_frag_descriptor(puVar11,*puVar8);
        puVar11 = puVar13;
      } while (puVar13 != puVar12);
    }
    *(undefined4 *)((long)plVar10 + 0x34) = *(undefined4 *)(param_1 + 0x54);
    uVar9 = __list_del_entry_valid(plVar10);
    if ((uVar9 & 1) != 0) {
      lVar2 = *plVar10;
      plVar3 = (long *)plVar10[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar10 = (long)plVar10;
    plVar10[1] = (long)plVar10;
    puVar8 = *(undefined8 **)(param_2 + 8);
    uVar9 = __list_add_valid(plVar10,puVar8,param_2);
    if ((uVar9 & 1) != 0) {
      *(long **)(param_2 + 8) = plVar10;
      *plVar10 = param_2;
      plVar10[1] = (long)puVar8;
      *puVar8 = plVar10;
    }
    *(undefined1 *)(param_1 + 0x62) = 0;
    *(undefined2 *)(param_1 + 0x58) = 0;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc38c135c9f @ 00100c7c size=128
// signature: undefined DATARMNETc38c135c9f(void)
// callers: [DATARMNETb56d685c50]
//------------------------------------------------------------

void DATARMNETc38c135c9f(int param_1,undefined8 param_2)

{
  long *plVar1;
  
  for (plVar1 = (long *)(&DATARMNET4791268d67)[(uint)(param_1 * 0x61c88647) >> 0x1b];
      plVar1 != (long *)0x0; plVar1 = (long *)*plVar1) {
    if ((*(int *)((long)plVar1 + 0x54) == param_1) && (*(char *)((long)plVar1 + 0x62) != '\0')) {
      DATARMNETa3055c21f2(plVar1,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET33aa5df9ef @ 00100d00 size=232
// signature: undefined DATARMNET33aa5df9ef(void)
// callers: [DATARMNET8dc47eb7af, DATARMNET4c7cdc25b7]
//------------------------------------------------------------

void DATARMNET33aa5df9ef(long param_1,long *param_2)

{
  long lVar1;
  short sVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  undefined8 *puVar7;
  
  if (*(char *)((long)param_2 + 0x42) != '\0') {
    lVar1 = param_2[3];
    lVar4 = param_2[1];
    *(long *)(param_1 + 0x28) = param_2[2];
    *(long *)(param_1 + 0x30) = lVar1;
    *(long *)(param_1 + 0x20) = lVar4;
    lVar1 = param_2[5];
    lVar4 = param_2[6];
    lVar5 = param_2[4];
    *(int *)(param_1 + 0x50) = (int)param_2[7];
    *(long *)(param_1 + 0x40) = lVar1;
    *(long *)(param_1 + 0x48) = lVar4;
    *(long *)(param_1 + 0x38) = lVar5;
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)((long)param_2 + 0x3c);
    sVar2 = *(short *)(*param_2 + 0x46);
    if (sVar2 == 0) {
      sVar2 = (short)param_2[8];
    }
    *(short *)(param_1 + 0x60) = sVar2;
  }
  if (*(char *)((long)param_2 + 0x39) == '\x06') {
    *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + (uint)*(ushort *)(param_2 + 8);
  }
  plVar6 = (long *)*param_2;
  puVar7 = *(undefined8 **)(param_1 + 0x18);
  uVar3 = __list_add_valid(plVar6,puVar7,param_1 + 0x10);
  if ((uVar3 & 1) != 0) {
    *(long **)(param_1 + 0x18) = plVar6;
    *plVar6 = param_1 + 0x10;
    plVar6[1] = (long)puVar7;
    *puVar7 = plVar6;
  }
  *(char *)(param_1 + 0x62) = *(char *)(param_1 + 0x62) + '\x01';
  *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + (short)param_2[8];
  return;
}



//------------------------------------------------------------
// DATARMNETfbf5798e15 @ 00100dec size=808
// signature: undefined DATARMNETfbf5798e15(void)
// callers: [DATARMNETb56d685c50]
//------------------------------------------------------------

uint DATARMNETfbf5798e15(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  code *pcVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  undefined8 *****local_58;
  undefined8 *****pppppuStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  cVar3 = *(char *)(param_1 + 0x39);
  lVar7 = DATARMNETf1d1b8287f(2);
  if (((lVar7 == 0) || ((cVar3 == '\x06' && (lVar7 == 1)))) || ((cVar3 == '\x11' && (lVar7 == 2))))
  {
    for (plVar11 = (long *)(&DATARMNET4791268d67)
                           [(uint)(*(int *)(param_1 + 0x3c) * 0x61c88647) >> 0x1b];
        plVar11 != (long *)0x0; plVar11 = (long *)*plVar11) {
      if (*(char *)((long)plVar11 + 0x62) == '\0') {
        if (*(int *)((long)plVar11 + 0x54) == *(int *)(param_1 + 0x3c)) goto LAB_0010100c;
      }
      else if (((*(char *)((long)plVar11 + 0x51) == *(char *)(param_1 + 0x39)) &&
               ((short)plVar11[4] == *(short *)(param_1 + 8))) &&
              (*(short *)((long)plVar11 + 0x22) == *(short *)(param_1 + 10))) {
        if (*(char *)(param_1 + 0x38) == '\x06') {
          if ((*(long *)((long)plVar11 + 0x24) == *(long *)(param_1 + 0xc) &&
               *(long *)((long)plVar11 + 0x2c) == *(long *)(param_1 + 0x14)) &&
             (*(long *)((long)plVar11 + 0x34) == *(long *)(param_1 + 0x1c) &&
              *(long *)((long)plVar11 + 0x3c) == *(long *)(param_1 + 0x24))) goto LAB_0010100c;
        }
        else if ((*(char *)(param_1 + 0x38) == '\x04') &&
                ((*(int *)((long)plVar11 + 0x24) == *(int *)(param_1 + 0xc) &&
                 (*(int *)((long)plVar11 + 0x34) == *(int *)(param_1 + 0x1c))))) goto LAB_0010100c;
      }
    }
    lVar8 = DATARMNETc2a630b113();
    local_58 = &local_58;
    lVar7 = lVar8 + 0x60;
    bVar4 = *(byte *)(lVar8 + 0x14b0);
    pppppuStack_50 = local_58;
    if (bVar4 < 0x32) {
      plVar11 = (long *)(lVar7 + (ulong)(uint)bVar4 * 0x68);
      *(byte *)(lVar8 + 0x14b0) = bVar4 + 1;
    }
    else {
      bVar4 = *(byte *)(lVar8 + 0x14b1);
      if (0x32 < bVar4) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101114);
        (*pcVar5)();
      }
      cVar1 = bVar4 - 0x31;
      plVar11 = (long *)(lVar7 + (ulong)bVar4 * 0x68);
      if (bVar4 < 0x31) {
        cVar1 = bVar4 + 1;
      }
      *(char *)(lVar8 + 0x14b1) = cVar1;
      plVar10 = (long *)plVar11[1];
      if (plVar10 != (long *)0x0) {
        lVar8 = *plVar11;
        *plVar10 = lVar8;
        if (lVar8 != 0) {
          *(long **)(lVar8 + 8) = plVar10;
        }
        *plVar11 = 0;
        plVar11[1] = 0;
      }
      if (*(char *)(lVar7 + (ulong)bVar4 * 0x68 + 0x62) != '\0') {
        DATARMNETa00cda79d0(8);
        DATARMNETa3055c21f2(plVar11,&local_58);
      }
      DATARMNETc70e73c8d4(&local_58);
    }
    iVar2 = *(int *)(param_1 + 0x3c);
    *(int *)((long)plVar11 + 0x54) = iVar2;
    plVar10 = &DATARMNET4791268d67 + ((uint)(iVar2 * 0x61c88647) >> 0x1b);
    lVar7 = *plVar10;
    *plVar11 = lVar7;
    if (lVar7 != 0) {
      *(long **)(lVar7 + 8) = plVar11;
    }
    *plVar10 = (long)plVar11;
    plVar11[1] = (long)plVar10;
LAB_0010100c:
    if (*(char *)((long)plVar11 + 0x62) == '\0') {
LAB_00101068:
      uVar9 = 0;
    }
    else {
      if (*(char *)(param_1 + 0x38) == '\x06') {
        if (((*(uint *)(param_1 + 0x2c) ^ *(uint *)((long)plVar11 + 0x44)) & 0xf00f) == 0)
        goto LAB_00101068;
      }
      else if ((*(char *)(param_1 + 0x38) != '\x04') ||
              ((((*(char *)((long)plVar11 + 0x44) == *(char *)(param_1 + 0x2c) &&
                 (*(char *)((long)plVar11 + 0x45) == *(char *)(param_1 + 0x2d))) &&
                (*(short *)((long)plVar11 + 0x46) == *(short *)(param_1 + 0x2e))) &&
               (*(short *)((long)plVar11 + 0x4c) == *(short *)(param_1 + 0x34)))))
      goto LAB_00101068;
      uVar9 = 1;
    }
    *(undefined1 *)(param_1 + 0x42) = 1;
    if (cVar3 == '\x11') {
      uVar6 = DATARMNET8dc47eb7af(plVar11,param_1,uVar9,param_2);
      goto LAB_001010d8;
    }
    if (cVar3 == '\x06') {
      uVar6 = DATARMNET4c7cdc25b7(plVar11,param_1,uVar9,param_2);
      goto LAB_001010d8;
    }
  }
  else {
    DATARMNETa00cda79d0(10);
  }
  uVar6 = 0;
LAB_001010d8:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 1;
}



//------------------------------------------------------------
// DATARMNETb98b78b8e3 @ 00101118 size=80
// signature: undefined DATARMNETb98b78b8e3(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

void DATARMNETb98b78b8e3(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  
  lVar4 = 0;
  do {
    puVar1 = (undefined8 *)(&DATARMNET4791268d67)[lVar4];
    while (puVar3 = puVar1, puVar3 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar3;
      puVar2 = (undefined8 *)puVar3[1];
      if (puVar2 != (undefined8 *)0x0) {
        *puVar2 = puVar1;
        if (puVar1 != (undefined8 *)0x0) {
          puVar1[1] = puVar2;
        }
        *puVar3 = 0;
        puVar3[1] = 0;
      }
    }
    lVar4 = lVar4 + 1;
  } while (lVar4 != 0x20);
  return;
}



//------------------------------------------------------------
// DATARMNETdbcaf01255 @ 0010116c size=68
// signature: undefined DATARMNETdbcaf01255(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

undefined8 DATARMNETdbcaf01255(void)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  
  lVar1 = DATARMNETc2a630b113();
  lVar2 = 0x32;
  plVar3 = (long *)(lVar1 + 0x78);
  do {
    lVar2 = lVar2 + -1;
    plVar3[-1] = (long)(plVar3 + -1);
    *plVar3 = (long)(plVar3 + -1);
    plVar3[-3] = 0;
    plVar3[-2] = 0;
    plVar3 = plVar3 + 0xd;
  } while (lVar2 != 0);
  return 0;
}



//------------------------------------------------------------
// DATARMNETf1d1b8287f @ 001011b4 size=36
// signature: undefined DATARMNETf1d1b8287f(void)
// callers: [DATARMNET8dc47eb7af, DATARMNET4c7cdc25b7, DATARMNETfbf5798e15]
//------------------------------------------------------------

undefined8 DATARMNETf1d1b8287f(uint param_1)

{
  if (param_1 < 3) {
    return *(undefined8 *)(&DATARMNET07ae1e39fb + (ulong)param_1 * 0x40);
  }
  return 0xffffffffffffffff;
}



//------------------------------------------------------------
// __DATARMNETdf66588a73 @ 001011dc size=256
// signature: undefined __DATARMNETdf66588a73(void)
// callers: []
//------------------------------------------------------------

int __DATARMNETdf66588a73(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong *puVar4;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = kstrtoull(param_1,0,&local_30);
  if (((iVar3 < 0) || (iVar3 = -0x22, local_30 < DAT_00102b68)) || (DAT_00102b70 < local_30))
  goto LAB_001012ac;
  DATARMNET664568fcd0();
  puVar4 = *(ulong **)(param_2 + 0x20);
  if (local_30 == *puVar4) {
    iVar3 = 0;
  }
  else {
    if (DAT_00102b78 != (code *)0x0) {
      if (*(int *)(DAT_00102b78 + -4) != 0x6ff2262d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x101288);
        (*pcVar2)();
      }
      iVar3 = (*DAT_00102b78)();
      if (iVar3 < 0) goto LAB_001012a8;
      puVar4 = *(ulong **)(param_2 + 0x20);
    }
    iVar3 = 0;
    *puVar4 = local_30;
  }
LAB_001012a8:
  DATARMNET6a76048590();
LAB_001012ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// __DATARMNET9c85bb95a3 @ 001012e0 size=256
// signature: undefined __DATARMNET9c85bb95a3(void)
// callers: []
//------------------------------------------------------------

int __DATARMNET9c85bb95a3(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong *puVar4;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = kstrtoull(param_1,0,&local_30);
  if (((iVar3 < 0) || (iVar3 = -0x22, local_30 < DAT_00102ba8)) || (DAT_00102bb0 < local_30))
  goto LAB_001013b0;
  DATARMNET664568fcd0();
  puVar4 = *(ulong **)(param_2 + 0x20);
  if (local_30 == *puVar4) {
    iVar3 = 0;
  }
  else {
    if (DAT_00102bb8 != (code *)0x0) {
      if (*(int *)(DAT_00102bb8 + -4) != 0x6ff2262d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x10138c);
        (*pcVar2)();
      }
      iVar3 = (*DAT_00102bb8)();
      if (iVar3 < 0) goto LAB_001013ac;
      puVar4 = *(ulong **)(param_2 + 0x20);
    }
    iVar3 = 0;
    *puVar4 = local_30;
  }
LAB_001013ac:
  DATARMNET6a76048590();
LAB_001013b0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// __DATARMNET6d2ed4b822 @ 001013e4 size=256
// signature: undefined __DATARMNET6d2ed4b822(void)
// callers: []
//------------------------------------------------------------

int __DATARMNET6d2ed4b822(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong *puVar4;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = kstrtoull(param_1,0,&local_30);
  if (((iVar3 < 0) || (iVar3 = -0x22, local_30 < DAT_00102be8)) || (DAT_00102bf0 < local_30))
  goto LAB_001014b4;
  DATARMNET664568fcd0();
  puVar4 = *(ulong **)(param_2 + 0x20);
  if (local_30 == *puVar4) {
    iVar3 = 0;
  }
  else {
    if (PTR_DATARMNET241493ab9a_00102bf8 != (undefined *)0x0) {
      if (*(int *)(PTR_DATARMNET241493ab9a_00102bf8 + -4) != 0x6ff2262d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x101490);
        (*pcVar2)();
      }
      iVar3 = (*(code *)PTR_DATARMNET241493ab9a_00102bf8)();
      if (iVar3 < 0) goto LAB_001014b0;
      puVar4 = *(ulong **)(param_2 + 0x20);
    }
    iVar3 = 0;
    *puVar4 = local_30;
  }
LAB_001014b0:
  DATARMNET6a76048590();
LAB_001014b4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// DATARMNET664568fcd0 @ 001014e8 size=36
// signature: undefined DATARMNET664568fcd0(void)
// callers: [DATARMNETbe30d096c6, __DATARMNETdf66588a73, __DATARMNET9c85bb95a3, __DATARMNET6d2ed4b822]
//------------------------------------------------------------

void DATARMNET664568fcd0(void)

{
  _raw_spin_lock_bh(&DATARMNET0b5e447f18);
  return;
}



//------------------------------------------------------------
// DATARMNET6a76048590 @ 00101510 size=36
// signature: undefined DATARMNET6a76048590(void)
// callers: [DATARMNETbe30d096c6, __DATARMNETdf66588a73, __DATARMNET9c85bb95a3, __DATARMNET6d2ed4b822]
//------------------------------------------------------------

void DATARMNET6a76048590(void)

{
  _raw_spin_unlock_bh(&DATARMNET0b5e447f18);
  return;
}



//------------------------------------------------------------
// DATARMNET818b960147 @ 00101538 size=60
// signature: undefined DATARMNET818b960147(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET818b960147(void)

{
  _rmnet_perf_desc_entry = DATARMNETb56d685c50;
  rmnet_module_hook_register(DATARMNET162e7a2013,1);
  return;
}



//------------------------------------------------------------
// DATARMNETb56d685c50 @ 00101578 size=1456
// signature: undefined DATARMNETb56d685c50(void)
// callers: [DATARMNET29e8d137c4]
//------------------------------------------------------------

void DATARMNETb56d685c50(long ****param_1,undefined8 param_2)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  long ****pppplVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  byte *pbVar11;
  long lVar12;
  undefined4 *puVar13;
  undefined2 *puVar14;
  ulong uVar15;
  uint uVar16;
  long ****pppplVar17;
  long ****local_e8;
  long ****local_e0;
  char local_d4 [4];
  char local_d0 [4];
  short local_cc [2];
  ulong local_c8 [2];
  undefined4 local_b8;
  ulong local_b0;
  long ****local_a8;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  byte local_7c;
  byte bStack_7b;
  undefined2 uStack_7a;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar12 = sp_el0;
  local_38 = *(long *)(lVar12 + 0x638);
  puVar10 = (undefined8 *)DATARMNETc2a630b113();
  local_e8 = (long ****)&local_e8;
  local_a8 = (long ****)0x0;
  local_a0 = 0;
  local_9e = 0;
  local_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  local_8c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  local_7c = 0;
  bStack_7b = 0;
  uStack_7a = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_e0 = local_e8;
  _raw_spin_lock_bh(&DATARMNET0b5e447f18);
  *puVar10 = param_2;
  uVar2 = *(uint *)(param_1 + 6);
  local_68._0_4_ = CONCAT13(1,(uint3)local_68);
  if ((*(byte *)((long)param_1[4] + 0xed) & 1) == 0) goto LAB_001019c0;
  if ((*(byte *)((long)param_1 + 0x51) >> 1 & 1) == 0) {
    pppplVar17 = (long ****)param_1[2];
    if (((pppplVar17 == param_1 + 2) || (pppplVar17 == (long ****)0x0)) ||
       (pbVar11 = (byte *)((((ulong)pppplVar17[2] & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                          (ulong)*(uint *)((long)pppplVar17 + 0x1c)), pbVar11 == (byte *)0x0)) {
LAB_00101740:
      DATARMNETa00cda79d0(2);
      rmnet_recycle_frag_descriptor(param_1,param_2);
      goto LAB_00101a80;
    }
    bVar3 = *pbVar11 >> 4;
    local_70 = CONCAT71(local_70._1_7_,bVar3);
    if (bVar3 == 6) {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      local_50 = 0;
      local_60 = 0;
      local_c8[0] = local_c8[0] & 0xffffffffffff0000;
      local_b0 = local_b0 & 0xffffffffffffff00;
      puVar13 = (undefined4 *)rmnet_frag_header_ptr(param_1,0,0x28,&local_60);
      if (puVar13 != (undefined4 *)0x0) {
        local_cc[0] = CONCAT11(local_cc[0]._1_1_,*(undefined1 *)((long)puVar13 + 6));
        uVar8 = rmnet_frag_ipv6_skip_exthdr(param_1,0x28,local_cc,local_c8,&local_b0);
        if (-1 < (int)uVar8) {
          local_78._0_6_ = CONCAT24((short)uVar8,(undefined4)local_78);
          local_70._0_2_ = CONCAT11((byte)local_cc[0],(undefined1)local_70);
          local_9c = (undefined4)*(undefined8 *)(puVar13 + 2);
          uStack_98 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 2) >> 0x20);
          uStack_94 = (undefined4)*(undefined8 *)(puVar13 + 4);
          uStack_90 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 4) >> 0x20);
          local_8c = (undefined4)*(undefined8 *)(puVar13 + 6);
          uStack_88 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 6) >> 0x20);
          uStack_84 = (undefined4)*(undefined8 *)(puVar13 + 8);
          uStack_80 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 8) >> 0x20);
          uVar9 = *puVar13;
          local_7c = (byte)uVar9;
          bStack_7b = (byte)((uint)uVar9 >> 8);
          uStack_7a = (undefined2)((uint)uVar9 >> 0x10);
          if (((short)local_c8[0] == 0) && ((char)local_b0 == '\0')) {
            uVar16 = ((uint)(*(ushort *)(puVar13 + 1) >> 8) |
                     (*(ushort *)(puVar13 + 1) & 0xff00ff) << 8) + 0x28 & 0xffff;
            bVar3 = (byte)local_cc[0];
            goto LAB_00101924;
          }
          if ((byte)local_cc[0] == 0x2c) goto LAB_001019b4;
LAB_001019b8:
          DATARMNETa00cda79d0(6);
        }
      }
    }
    else {
      if (bVar3 != 4) goto LAB_00101740;
      local_50 = (ulong)local_50._4_4_ << 0x20;
      local_60 = 0;
      local_58 = 0;
      pbVar11 = (byte *)rmnet_frag_header_ptr(param_1,0,0x14,&local_60);
      if (pbVar11 != (byte *)0x0) {
        uVar8 = (*pbVar11 & 0xf) << 2;
        local_78._0_6_ = CONCAT24((short)uVar8,(undefined4)local_78);
        local_70._0_2_ = CONCAT11(pbVar11[9],(undefined1)local_70);
        local_9c = *(undefined4 *)(pbVar11 + 0xc);
        local_8c = *(undefined4 *)(pbVar11 + 0x10);
        local_7c = pbVar11[8];
        bStack_7b = pbVar11[1];
        uStack_7a = *(undefined2 *)(pbVar11 + 6);
        if ((*(ushort *)(pbVar11 + 6) & 0xff3f) != 0) goto LAB_001019b8;
        uVar16 = (uint)(*(ushort *)(pbVar11 + 2) >> 8) | (*(ushort *)(pbVar11 + 2) & 0xff00ff) << 8;
        bVar3 = pbVar11[9];
LAB_00101924:
        local_68._0_5_ = CONCAT14(uVar16 != (uVar2 & 0xffff),(uint)local_68);
        if (bVar3 == 0x11) {
          local_60 = 0;
          puVar14 = (undefined2 *)rmnet_frag_header_ptr(param_1,uVar8 & 0xffff,8,&local_60);
          if (puVar14 != (undefined2 *)0x0) {
            local_78 = CONCAT26(8,(undefined6)local_78);
            local_a0 = *puVar14;
            local_9e = puVar14[1];
LAB_00101af4:
            local_68._0_4_ = (uint)(uint3)local_68;
            uVar9 = DATARMNETcb7325e02d(&local_a8);
            uVar5 = local_70;
            local_70 = CONCAT44(uVar9,(undefined4)local_70);
            if (local_68._4_1_ == '\0') {
              local_70._0_2_ = (undefined2)uVar5;
              *(undefined2 *)((long)param_1 + 0x4e) = (undefined2)local_70;
              *(undefined4 *)((long)param_1 + 0x4a) = local_78._4_4_;
              *(byte *)((long)param_1 + 0x51) = *(byte *)((long)param_1 + 0x51) | 2;
            }
          }
        }
        else if (bVar3 == 6) {
          local_50 = local_50 & 0xffffffff00000000;
          local_60 = 0;
          local_58 = 0;
          puVar14 = (undefined2 *)rmnet_frag_header_ptr(param_1,uVar8 & 0xffff,0x14,&local_60);
          if (puVar14 != (undefined2 *)0x0) {
            local_a0 = *puVar14;
            local_9e = puVar14[1];
            uVar8 = (*(uint *)(puVar14 + 2) & 0xff00ff00) >> 8 |
                    (*(uint *)(puVar14 + 2) & 0xff00ff) << 8;
            local_78 = (ulong)CONCAT34((int3)(CONCAT16(*(byte *)(puVar14 + 6) >> 2,
                                                       (undefined6)local_78) >> 0x20),
                                       uVar8 >> 0x10 | uVar8 << 0x10) & 0x3cffffffffffff;
            goto LAB_00101af4;
          }
        }
      }
    }
LAB_001019c0:
    cVar6 = local_68._4_1_;
    local_68 = CONCAT62(local_68._2_6_,(short)uVar2 - (local_78._4_2_ + local_78._6_2_));
    if (cVar6 != '\0') {
      DATARMNETa00cda79d0(7);
    }
  }
  else {
    local_b0 = 0;
    local_b8 = 0;
    local_c8[0] = 0;
    local_c8[1] = 0;
    local_78 = CONCAT44(*(undefined4 *)((long)param_1 + 0x4a),(undefined4)local_78);
    local_70 = CONCAT62(local_70._2_6_,*(undefined2 *)((long)param_1 + 0x4e));
    if (*(char *)((long)param_1 + 0x4e) != '\x04') {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      local_50 = 0;
      local_60 = 0;
      puVar13 = (undefined4 *)rmnet_frag_header_ptr(param_1,0,0x28,&local_60);
      if (puVar13 != (undefined4 *)0x0) {
        local_9c = (undefined4)*(undefined8 *)(puVar13 + 2);
        uStack_98 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 2) >> 0x20);
        uStack_94 = (undefined4)*(undefined8 *)(puVar13 + 4);
        uStack_90 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 4) >> 0x20);
        local_8c = (undefined4)*(undefined8 *)(puVar13 + 6);
        uStack_88 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 6) >> 0x20);
        uStack_84 = (undefined4)*(undefined8 *)(puVar13 + 8);
        uStack_80 = (undefined4)((ulong)*(undefined8 *)(puVar13 + 8) >> 0x20);
        uVar9 = *puVar13;
        local_7c = (byte)uVar9;
        bStack_7b = (byte)((uint)uVar9 >> 8);
        uStack_7a = (undefined2)((uint)uVar9 >> 0x10);
        if (0x28 < local_78._4_2_) {
          local_d4[0] = *(char *)((long)puVar13 + 6);
          local_cc[0] = 0;
          local_d0[0] = '\0';
          iVar7 = rmnet_frag_ipv6_skip_exthdr(param_1,0x28,local_d4,local_cc,local_d0);
          if (((iVar7 < 0) || (local_cc[0] != 0)) || (local_d0[0] != '\0')) {
            if (local_d4[0] == ',') {
              uVar8 = (uint)local_78._4_2_;
LAB_001019b4:
              local_78._0_6_ = CONCAT24((short)uVar8 + 8,(undefined4)local_78);
            }
            goto LAB_001019b8;
          }
        }
        goto LAB_001017e4;
      }
      goto LAB_001019c0;
    }
    local_50 = (ulong)local_50._4_4_ << 0x20;
    local_60 = 0;
    local_58 = 0;
    lVar12 = rmnet_frag_header_ptr(param_1,0,0x14,&local_60);
    if (lVar12 == 0) goto LAB_001019c0;
    local_9c = *(undefined4 *)(lVar12 + 0xc);
    local_8c = *(undefined4 *)(lVar12 + 0x10);
    local_7c = *(byte *)(lVar12 + 8);
    bStack_7b = *(byte *)(lVar12 + 1);
    uStack_7a = *(undefined2 *)(lVar12 + 6);
LAB_001017e4:
    puVar14 = (undefined2 *)rmnet_frag_header_ptr(param_1,local_78._4_2_,8,&local_b0);
    if (puVar14 == (undefined2 *)0x0) goto LAB_001019c0;
    local_a0 = *puVar14;
    local_9e = puVar14[1];
    if (local_70._1_1_ == '\x06') {
      lVar12 = rmnet_frag_header_ptr(param_1,local_78._4_2_,0x14,local_c8);
      if (lVar12 == 0) goto LAB_001019c0;
      puVar1 = (uint *)(lVar12 + 4);
      if ((*(byte *)((long)param_1 + 0x51) & 8) != 0) {
        puVar1 = (uint *)((long)param_1 + 0x3c);
      }
      uVar2 = (*puVar1 & 0xff00ff00) >> 8 | (*puVar1 & 0xff00ff) << 8;
      local_78 = CONCAT44(local_78._4_4_,uVar2 >> 0x10 | uVar2 << 0x10);
    }
    uVar9 = DATARMNETcb7325e02d(&local_a8);
    local_70 = CONCAT44(uVar9,(undefined4)local_70);
    local_68._0_4_ = (uint)(uint3)local_68;
    local_68 = CONCAT62(local_68._2_6_,
                        (short)*(undefined4 *)(param_1 + 6) -
                        (*(short *)((long)param_1 + 0x4a) + *(short *)((long)param_1 + 0x4c)));
  }
  local_a8 = param_1;
  DATARMNETa00cda79d0(0);
  if (local_68._3_1_ == '\0') {
    if (local_68._4_1_ == '\0') {
      if (((*(byte *)((long)param_1 + 0x51) & 1) != 0) &&
         (uVar15 = DATARMNETfbf5798e15(&local_a8,&local_e8), (uVar15 & 1) != 0)) goto LAB_00101a80;
    }
    else {
      DATARMNETc38c135c9f(local_70._4_4_,&local_e8);
    }
  }
  pppplVar4 = local_a8;
  pppplVar17 = local_e0;
  if ((uint)local_78._4_2_ + (uint)(ushort)local_68 + (uint)local_78._6_2_ < 0x10001) {
    if (local_68._3_1_ == '\0') {
      *(undefined4 *)((long)local_a8 + 0x34) = local_70._4_4_;
    }
    uVar15 = __list_add_valid(local_a8,local_e0,&local_e8);
    if ((uVar15 & 1) != 0) {
      local_e0 = pppplVar4;
      *pppplVar4 = (long ***)&local_e8;
      pppplVar4[1] = (long ***)pppplVar17;
      *pppplVar17 = (long ***)pppplVar4;
    }
  }
LAB_00101a80:
  _raw_spin_unlock_bh(&DATARMNET0b5e447f18);
  DATARMNETc70e73c8d4(&local_e8);
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETba38823a2f @ 00101b34 size=48
// signature: undefined DATARMNETba38823a2f(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETba38823a2f(void)

{
  _rmnet_perf_desc_entry = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET162e7a2013,1);
  return;
}



//------------------------------------------------------------
// DATARMNETc70e73c8d4 @ 00101b68 size=284
// signature: undefined DATARMNETc70e73c8d4(void)
// callers: [DATARMNETbe30d096c6, DATARMNETb56d685c50, DATARMNETc9dd320f49, DATARMNETfbf5798e15, DATARMNET95e1703026, DATARMNET241493ab9a]
//------------------------------------------------------------

void DATARMNETc70e73c8d4(long *param_1)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  long *plVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined4 uVar7;
  long *plVar8;
  
  puVar5 = (undefined8 *)DATARMNETc2a630b113();
  plVar4 = (long *)*param_1;
  while (plVar4 != param_1) {
    uVar3 = *(uint *)(plVar4 + 6);
    if (uVar3 < 0xc351) {
      if (uVar3 < 0x7531) {
        if (uVar3 < 0x59d9) {
          if (uVar3 < 0x38a5) {
            if (uVar3 < 0x1b59) {
              uVar7 = 0x15;
              if (0x578 < uVar3) {
                uVar7 = 0x16;
              }
            }
            else {
              uVar7 = 0x17;
            }
          }
          else {
            uVar7 = 0x18;
          }
        }
        else {
          uVar7 = 0x19;
        }
      }
      else {
        uVar7 = 0x1a;
      }
    }
    else {
      uVar7 = 0x1b;
    }
    plVar8 = (long *)*plVar4;
    DATARMNETa00cda79d0(uVar7);
    DATARMNETa00cda79d0(1);
    uVar6 = __list_del_entry_valid(plVar4);
    if ((uVar6 & 1) != 0) {
      lVar1 = *plVar4;
      plVar2 = (long *)plVar4[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar4 = (long)plVar4;
    plVar4[1] = (long)plVar4;
    rmnet_frag_deliver(plVar4,*puVar5);
    plVar4 = plVar8;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET19d190f2bd @ 00101c88 size=128
// signature: undefined DATARMNET19d190f2bd(void)
// callers: [DATARMNET8dc47eb7af, DATARMNET4c7cdc25b7]
//------------------------------------------------------------

void DATARMNET19d190f2bd(undefined8 *param_1,long param_2)

{
  ulong uVar1;
  long *plVar2;
  undefined8 *puVar3;
  
  if ((uint)*(ushort *)((long)param_1 + 0x34) + (uint)*(ushort *)(param_1 + 8) +
      (uint)*(ushort *)((long)param_1 + 0x36) < 0x10001) {
    plVar2 = (long *)*param_1;
    if (*(char *)((long)param_1 + 0x43) == '\0') {
      *(undefined4 *)((long)plVar2 + 0x34) = *(undefined4 *)((long)param_1 + 0x3c);
    }
    puVar3 = *(undefined8 **)(param_2 + 8);
    uVar1 = __list_add_valid(plVar2,puVar3,param_2);
    if ((uVar1 & 1) != 0) {
      *(long **)(param_2 + 8) = plVar2;
      *plVar2 = param_2;
      plVar2[1] = (long)puVar3;
      *puVar3 = plVar2;
    }
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9292bebdd3 @ 00101d0c size=4
// signature: undefined DATARMNET9292bebdd3(void)
// callers: []
//------------------------------------------------------------

void DATARMNET9292bebdd3(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNETb7e47d7254 @ 00101d14 size=4
// signature: undefined DATARMNETb7e47d7254(void)
// callers: []
//------------------------------------------------------------

void DATARMNETb7e47d7254(void)

{
  return;
}



//------------------------------------------------------------
// DATARMNET95e1703026 @ 00101d1c size=180
// signature: undefined DATARMNET95e1703026(void)
// callers: []
//------------------------------------------------------------

void DATARMNET95e1703026(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 ***local_38;
  undefined8 ***pppuStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = DATARMNETc2a630b113();
  local_38 = &local_38;
  pppuStack_30 = local_38;
  _raw_spin_lock_bh(&DATARMNET0b5e447f18);
  if ((*(char *)(lVar2 + 0x39) != '\0') && (iVar1 = DATARMNETae70636c90(&local_38), iVar1 != 0)) {
    DATARMNETa00cda79d0(3);
  }
  *(undefined1 *)(lVar2 + 0x39) = 1;
  *(undefined4 *)(lVar2 + 0x30) = *param_1;
  *(undefined4 *)(lVar2 + 0x34) = param_1[2];
  _raw_spin_unlock_bh(&DATARMNET0b5e447f18);
  DATARMNETc70e73c8d4(&local_38);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc9dd320f49 @ 00101dd4 size=180
// signature: undefined DATARMNETc9dd320f49(void)
// callers: []
//------------------------------------------------------------

void DATARMNETc9dd320f49(int *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 ***local_38;
  undefined8 ***pppuStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = DATARMNETc2a630b113();
  local_38 = &local_38;
  pppuStack_30 = local_38;
  _raw_spin_lock_bh(&DATARMNET0b5e447f18);
  if (*(int *)(lVar2 + 0x30) != *param_1) {
    DATARMNETa00cda79d0(4);
  }
  iVar1 = DATARMNETae70636c90(&local_38);
  if (iVar1 != 0) {
    DATARMNETa00cda79d0(5);
  }
  *(undefined1 *)(lVar2 + 0x39) = 0;
  *(undefined8 *)(lVar2 + 0x30) = 0;
  _raw_spin_unlock_bh(&DATARMNET0b5e447f18);
  DATARMNETc70e73c8d4(&local_38);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETcb7325e02d @ 00101e88 size=780
// signature: undefined DATARMNETcb7325e02d(void)
// callers: [DATARMNETb56d685c50]
//------------------------------------------------------------

void DATARMNETcb7325e02d(long param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  uint *puVar15;
  undefined8 local_48;
  undefined8 local_40;
  uint local_38 [8];
  long local_18;
  
  lVar12 = sp_el0;
  local_18 = *(long *)(lVar12 + 0x638);
  bVar4 = *(byte *)(param_1 + 0x39);
  local_38[6] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_40 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if (bVar4 == 0x11) {
LAB_00101ed0:
    uVar9 = (uint)*(ushort *)(param_1 + 8);
    uVar10 = (uint)*(ushort *)(param_1 + 10);
  }
  else {
    uVar10 = 0;
    uVar9 = 0;
    if (bVar4 == 6) goto LAB_00101ed0;
  }
  if (*(char *)(param_1 + 0x38) == '\x04') {
    iVar7 = 5;
    lVar12 = 4;
    lVar13 = 3;
    lVar14 = 2;
    local_48 = CONCAT44(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c));
  }
  else {
    iVar7 = 0xb;
    lVar12 = 10;
    lVar13 = 9;
    local_48 = *(undefined8 *)(param_1 + 0x1c);
    local_40 = *(undefined8 *)(param_1 + 0x24);
    local_38[1] = (uint)*(undefined8 *)(param_1 + 0xc);
    local_38[2] = (uint)((ulong)*(undefined8 *)(param_1 + 0xc) >> 0x20);
    lVar14 = 8;
    local_38[3] = *(int *)(param_1 + 0x14);
  }
  local_38[lVar14 + -4] = (uint)bVar4;
  local_38[lVar13 + -4] = uVar10;
  local_38[lVar12 + -4] = uVar9;
  iVar1 = iVar7 * 4 + -0x21524111;
  uVar5 = iVar7 - 4;
  uVar9 = (int)local_40 + iVar1;
  uVar10 = ((int)local_48 + iVar1) - uVar9 ^ (uVar9 >> 0x1c | uVar9 * 0x10);
  iVar11 = uVar9 + local_48._4_4_ + iVar1;
  uVar9 = (local_48._4_4_ + iVar1) - uVar10 ^ (uVar10 >> 0x1a | uVar10 << 6);
  iVar1 = uVar10 + iVar11;
  uVar10 = iVar11 - uVar9 ^ (uVar9 >> 0x18 | uVar9 << 8);
  iVar11 = uVar9 + iVar1;
  uVar9 = iVar1 - uVar10 ^ (uVar10 >> 0x10 | uVar10 << 0x10);
  iVar1 = uVar10 + iVar11;
  uVar10 = iVar11 - uVar9 ^ (uVar9 >> 0xd | uVar9 << 0x13);
  iVar11 = uVar9 + iVar1;
  uVar9 = iVar1 - uVar10 ^ (uVar10 >> 0x1c | uVar10 << 4);
  uVar10 = uVar10 + iVar11;
  if (iVar7 - 7U < 0xfffffffc) {
    uVar9 = local_38[1] + uVar9;
    uVar3 = (local_40._4_4_ + iVar11) - uVar9 ^ (uVar9 >> 0x1c | uVar9 * 0x10);
    iVar1 = uVar9 + local_38[0] + uVar10;
    uVar9 = (local_38[0] + uVar10) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
    iVar11 = uVar3 + iVar1;
    uVar10 = iVar1 - uVar9 ^ (uVar9 >> 0x18 | uVar9 << 8);
    iVar1 = uVar9 + iVar11;
    uVar9 = iVar11 - uVar10 ^ (uVar10 >> 0x10 | uVar10 << 0x10);
    iVar2 = uVar10 + iVar1;
    uVar10 = iVar1 - uVar9 ^ (uVar9 >> 0xd | uVar9 << 0x13);
    iVar11 = uVar9 + iVar2;
    uVar9 = iVar2 - uVar10 ^ (uVar10 >> 0x1c | uVar10 << 4);
    uVar10 = uVar10 + iVar11;
    if (iVar7 - 10U < 0xfffffffc) {
      uVar9 = local_38[4] + uVar9;
      uVar3 = (local_38[2] + iVar11) - uVar9 ^ (uVar9 >> 0x1c | uVar9 * 0x10);
      iVar1 = uVar9 + local_38[3] + uVar10;
      uVar9 = (local_38[3] + uVar10) - uVar3 ^ (uVar3 >> 0x1a | uVar3 << 6);
      iVar11 = uVar3 + iVar1;
      uVar10 = iVar1 - uVar9 ^ (uVar9 >> 0x18 | uVar9 << 8);
      iVar1 = uVar9 + iVar11;
      uVar9 = iVar11 - uVar10 ^ (uVar10 >> 0x10 | uVar10 << 0x10);
      iVar2 = uVar10 + iVar1;
      iVar11 = uVar9 + iVar2;
      uVar10 = iVar1 - uVar9 ^ (uVar9 >> 0xd | uVar9 << 0x13);
      puVar15 = local_38 + 5;
      uVar9 = iVar2 - uVar10 ^ (uVar10 >> 0x1c | uVar10 << 4);
      uVar10 = uVar10 + iVar11;
    }
    else {
      puVar15 = local_38 + 2;
    }
  }
  else {
    puVar15 = (uint *)((long)&local_40 + 4);
  }
  iVar7 = ((uVar5 + ((uVar5 & 0xff) / 3) * -3 & 0xff) - uVar5) + iVar7;
  if (iVar7 != 4) {
    uVar8 = (ulong)(uVar5 & 0xff) / 3;
    if (iVar7 != 5) {
      if (iVar7 != 6) goto LAB_00102168;
      if ((uVar5 & 0xff) - 6 < 3) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x102194);
        (*pcVar6)();
      }
      uVar9 = local_38[uVar8 * 3 + 1] + uVar9;
    }
    uVar10 = local_38[uVar8 * 3] + uVar10;
  }
  uVar9 = (uVar9 ^ uVar10) - (uVar10 >> 0x12 | uVar10 << 0xe);
  uVar5 = (*puVar15 + iVar11 ^ uVar9) - (uVar9 >> 0x15 | uVar9 * 0x800);
  uVar10 = (uVar5 ^ uVar10) - (uVar5 >> 7 | uVar5 * 0x2000000);
  uVar9 = (uVar10 ^ uVar9) - (uVar10 >> 0x10 | uVar10 * 0x10000);
  uVar5 = (uVar9 ^ uVar5) - (uVar9 >> 0x1c | uVar9 * 0x10);
  uVar10 = (uVar5 ^ uVar10) - (uVar5 >> 0x12 | uVar5 * 0x4000);
  uVar9 = (uVar10 ^ uVar9) - (uVar10 >> 8 | uVar10 * 0x1000000);
LAB_00102168:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET29e8d137c4 @ 00102198 size=128
// signature: undefined DATARMNET29e8d137c4(void)
// callers: []
//------------------------------------------------------------

void DATARMNET29e8d137c4(long *param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar3 = (long *)*param_1;
  while (plVar3 != param_1) {
    plVar5 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = (long)plVar3;
    plVar3[1] = (long)plVar3;
    DATARMNETb56d685c50(plVar3,param_2);
    plVar3 = plVar5;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETc2a630b113 @ 0010221c size=12
// signature: undefined DATARMNETc2a630b113(void)
// callers: [DATARMNETc70e73c8d4, DATARMNETa3055c21f2, DATARMNETb56d685c50, DATARMNETc9dd320f49, DATARMNETfbf5798e15, DATARMNET95e1703026, DATARMNETdbcaf01255]
//------------------------------------------------------------

undefined8 DATARMNETc2a630b113(void)

{
  return DATARMNETe05748b000;
}



//------------------------------------------------------------
// DATARMNET7dec24813e @ 0010222c size=296
// signature: undefined DATARMNET7dec24813e(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET7dec24813e(undefined8 param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  char *__s1;
  
  __s1 = (char *)*param_3;
  if ((__s1 != (char *)0x0) && (iVar2 = strncmp(__s1,"rmnet_data",10), iVar2 == 0)) {
    if (param_2 == 6) {
      if ((DATARMNETe05748b000 != 0) &&
         (cVar1 = *(char *)(DATARMNETe05748b000 + 0x14b8) + -1,
         *(char *)(DATARMNETe05748b000 + 0x14b8) = cVar1, cVar1 == '\0')) {
        _printk(&DAT_00102e49,"DATARMNET7dec24813e",__s1);
        DATARMNET345f805b34();
      }
    }
    else if (param_2 == 5) {
      if (DATARMNETe05748b000 == 0) {
        lVar3 = rmnet_get_port(*(undefined8 *)(__s1 + 0xa48));
        if (lVar3 == 0) {
          _printk(&DAT_00102f07,"DATARMNET7dec24813e",__s1);
        }
        else {
          _printk(&DAT_00102fed,"DATARMNET7dec24813e",__s1);
          iVar2 = DATARMNET9f53d54812(lVar3);
          if (iVar2 == 2) {
            _printk(&DAT_00102e6e,"DATARMNET7dec24813e");
          }
        }
      }
      else {
        *(char *)(DATARMNETe05748b000 + 0x14b8) = *(char *)(DATARMNETe05748b000 + 0x14b8) + '\x01';
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET9f53d54812 @ 00102354 size=360
// signature: undefined DATARMNET9f53d54812(void)
// callers: [DATARMNET7dec24813e]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DATARMNET9f53d54812(long param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  DATARMNETe05748b000 = (long *)kmalloc_trace(_DAT_00104128,0xdc0,0x14c0);
  if (DATARMNETe05748b000 == (long *)0x0) {
    _printk(&DAT_00102f98,"DATARMNET9f53d54812");
    return 2;
  }
  *DATARMNETe05748b000 = param_1;
  iVar2 = DATARMNETdbcaf01255();
  plVar1 = DATARMNETe05748b000;
  if (iVar2 < 0) {
    kfree();
    DATARMNETe05748b000 = (long *)0x0;
    return iVar2;
  }
  lVar4 = *DATARMNETe05748b000;
  DATARMNETe05748b000[9] = (long)DATARMNETb7e47d7254;
  plVar1[8] = (long)DATARMNET9292bebdd3;
  iVar2 = qmi_rmnet_ps_ind_register(lVar4);
  if (iVar2 == 0) {
    if ((*(byte *)(lVar4 + 0xb) >> 5 & 1) == 0) goto LAB_0010240c;
LAB_001023d8:
    plVar1 = DATARMNETe05748b000;
    DATARMNETe05748b000[2] = (long)DATARMNET95e1703026;
    plVar1[3] = (long)DATARMNETc9dd320f49;
    *(undefined1 *)(plVar1 + 1) = 0;
    iVar3 = rmnet_map_dl_ind_register(lVar4);
    if (iVar3 == 0) {
      *(undefined1 *)(plVar1 + 7) = 1;
      goto LAB_0010240c;
    }
    _printk(&DAT_00102ed9,"DATARMNETd68e3594a7");
    DATARMNETd4230b6bfe();
  }
  else {
    _printk(&DAT_00102f32,"DATARMNETd68e3594a7");
    if ((*(byte *)(lVar4 + 0xb) >> 5 & 1) != 0) goto LAB_001023d8;
LAB_0010240c:
    DATARMNETd4230b6bfe();
    iVar3 = 0;
    if (iVar2 == 0) goto LAB_00102414;
  }
  _printk(&DAT_00102e8d,"DATARMNET9f53d54812");
  iVar3 = 1;
LAB_00102414:
  *(undefined1 *)(DATARMNETe05748b000 + 0x297) = 1;
  DATARMNET818b960147();
  return iVar3;
}



//------------------------------------------------------------
// DATARMNET345f805b34 @ 001024bc size=168
// signature: undefined DATARMNET345f805b34(void)
// callers: [DATARMNET7dec24813e]
//------------------------------------------------------------

void DATARMNET345f805b34(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 ***local_38;
  undefined8 ***pppuStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = &local_38;
  pppuStack_30 = local_38;
  if (DATARMNETe05748b000 != (undefined8 *)0x0) {
    uVar2 = *DATARMNETe05748b000;
    qmi_rmnet_ps_ind_deregister(uVar2,DATARMNETe05748b000 + 8);
    if (*(char *)(DATARMNETe05748b000 + 7) != '\0') {
      rmnet_map_dl_ind_deregister(uVar2,DATARMNETe05748b000 + 1);
    }
    DATARMNETba38823a2f();
    DATARMNET560e127137();
    synchronize_rcu();
    DATARMNETae70636c90(&local_38);
    DATARMNETb98b78b8e3();
    kfree(DATARMNETe05748b000);
    DATARMNETe05748b000 = (undefined8 *)0x0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETbad3b5165e @ 00102568 size=36
// signature: undefined DATARMNETbad3b5165e(void)
// callers: [DATARMNET241493ab9a]
//------------------------------------------------------------

void DATARMNETbad3b5165e(uint param_1,long param_2)

{
  if (param_1 < 0x1c) {
    *(long *)(&DATARMNET6c78aba0c8 + (ulong)param_1 * 8) =
         *(long *)(&DATARMNET6c78aba0c8 + (ulong)param_1 * 8) + param_2;
  }
  return;
}



//------------------------------------------------------------
// DATARMNETa00cda79d0 @ 00102590 size=36
// signature: undefined DATARMNETa00cda79d0(void)
// callers: [DATARMNETbe30d096c6, DATARMNETc70e73c8d4, DATARMNET8dc47eb7af, DATARMNETb56d685c50, DATARMNET4c7cdc25b7, DATARMNETc9dd320f49, DATARMNETfbf5798e15, DATARMNET95e1703026]
//------------------------------------------------------------

void DATARMNETa00cda79d0(uint param_1)

{
  if (param_1 < 0x1c) {
    *(long *)(&DATARMNET6c78aba0c8 + (ulong)param_1 * 8) =
         *(long *)(&DATARMNET6c78aba0c8 + (ulong)param_1 * 8) + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET4c7cdc25b7 @ 001025b8 size=548
// signature: undefined DATARMNET4c7cdc25b7(void)
// callers: [DATARMNETfbf5798e15]
//------------------------------------------------------------

undefined8 DATARMNET4c7cdc25b7(long param_1,long *param_2,ulong param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if ((param_3 & 1) == 0) {
    local_68 = local_68 & 0xffffffff00000000;
    local_78 = 0;
    local_70 = 0;
    lVar5 = rmnet_frag_header_ptr(*param_2,*(undefined2 *)((long)param_2 + 0x34),0x14,&local_78);
    if (lVar5 == 0) {
      uVar4 = 0xd;
    }
    else {
      if ((*(byte *)(*param_2 + 0x51) >> 5 & 1) == 0) {
        bVar2 = *(byte *)(lVar5 + 0xd);
      }
      else {
        bVar2 = *(byte *)(*param_2 + 0x43);
      }
      uVar4 = 0xd;
      bVar1 = 0;
      if ((short)param_2[8] == 0) {
        bVar1 = bVar2 >> 4 & 1;
      }
      if ((bVar1 == 0) && ((bVar2 & 0xaf) == 0)) {
        if (*(char *)(param_1 + 0x62) != '\0') {
          local_40 = 0;
          local_50 = 0;
          uStack_48 = 0;
          local_60 = 0;
          uStack_58 = 0;
          local_70 = 0;
          local_68 = 0;
          local_78 = 0;
          local_80 = 0;
          local_90 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_b8 = 0;
          lVar5 = rmnet_frag_header_ptr
                            (*(undefined8 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x4c),
                             *(undefined2 *)(param_1 + 0x4e),&local_78);
          if ((lVar5 == 0) ||
             (lVar6 = rmnet_frag_header_ptr
                                (*param_2,*(undefined2 *)((long)param_2 + 0x34),
                                 *(undefined2 *)((long)param_2 + 0x36),&local_b8), lVar6 == 0)) {
LAB_00102754:
            uVar4 = 0xe;
          }
          else {
            uVar8 = (ulong)(*(byte *)(lVar5 + 0xc) >> 2) & 0x3c;
            uVar7 = (uint)uVar8;
            if ((*(byte *)(lVar6 + 0xc) >> 2 & 0x3c) != uVar7) goto LAB_00102754;
            if (0x14 < uVar7) {
              uVar9 = 0x14;
              do {
                if (*(int *)(lVar5 + uVar9) != *(int *)(lVar6 + uVar9)) goto LAB_00102754;
                uVar9 = uVar9 + 4;
              } while (uVar9 < uVar8);
            }
            if ((int)param_2[6] != *(int *)(param_1 + 0x48)) {
              uVar4 = 0xf;
              goto LAB_0010277c;
            }
            sVar3 = *(short *)(*param_2 + 0x46);
            if (sVar3 == 0) {
              sVar3 = (short)param_2[8];
            }
            if (sVar3 == *(short *)(param_1 + 0x60)) {
              uVar8 = DATARMNETf1d1b8287f(0);
              if ((ulong)*(ushort *)(param_1 + 0x58) + (ulong)*(ushort *)(param_2 + 8) < uVar8) {
                *(undefined1 *)((long)param_2 + 0x42) = 0;
                goto LAB_00102768;
              }
              uVar4 = 0x11;
            }
            else {
              uVar4 = 0x10;
            }
          }
          DATARMNETa00cda79d0(uVar4);
          DATARMNETa3055c21f2(param_1,param_4);
        }
LAB_00102768:
        DATARMNET33aa5df9ef(param_1,param_2);
        goto LAB_00102798;
      }
    }
  }
  else {
    uVar4 = 0xc;
  }
LAB_0010277c:
  DATARMNETa00cda79d0(uVar4);
  DATARMNETa3055c21f2(param_1,param_4);
  DATARMNET19d190f2bd(param_2,param_4);
LAB_00102798:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// DATARMNET8dc47eb7af @ 001027e0 size=208
// signature: undefined DATARMNET8dc47eb7af(void)
// callers: [DATARMNETfbf5798e15]
//------------------------------------------------------------

undefined8 DATARMNET8dc47eb7af(long param_1,long *param_2,uint param_3,undefined8 param_4)

{
  short sVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if ((param_3 & 1) != 0) {
    DATARMNETa00cda79d0(0x12);
    DATARMNETa3055c21f2(param_1,param_4);
    DATARMNET19d190f2bd(param_2,param_4);
    return 1;
  }
  if (*(char *)(param_1 + 0x62) != '\0') {
    sVar1 = *(short *)(*param_2 + 0x46);
    if (sVar1 == 0) {
      sVar1 = (short)param_2[8];
    }
    if (sVar1 == *(short *)(param_1 + 0x60)) {
      uVar2 = DATARMNETf1d1b8287f(1);
      if ((ulong)*(ushort *)(param_1 + 0x58) + (ulong)*(ushort *)(param_2 + 8) < uVar2) {
        *(undefined1 *)((long)param_2 + 0x42) = 0;
        goto LAB_0010288c;
      }
      uVar3 = 0x14;
    }
    else {
      uVar3 = 0x13;
    }
    DATARMNETa00cda79d0(uVar3);
    DATARMNETa3055c21f2(param_1,param_4);
  }
LAB_0010288c:
  DATARMNET33aa5df9ef(param_1,param_2);
  return 1;
}



//------------------------------------------------------------
// init_module @ 00103028 size=56
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  _printk(&DAT_00102f74,"DATARMNETb1c42acd9c");
  register_netdevice_notifier(&DATARMNETcae9c64c41);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103064 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk(&DAT_00102f55,"DATARMNET0f6d85e415");
  unregister_netdevice_notifier(&DATARMNETcae9c64c41);
  return;
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 00104008 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [DATARMNET818b960147, DATARMNETd4230b6bfe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNETbe30d096c6, __DATARMNET6d2ed4b822, DATARMNET345f805b34, DATARMNET4c7cdc25b7, DATARMNETb56d685c50, __DATARMNET9c85bb95a3, DATARMNETc9dd320f49, DATARMNETfbf5798e15, __DATARMNETdf66588a73, DATARMNET95e1703026, DATARMNET241493ab9a, DATARMNETcb7325e02d]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 00104018 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [DATARMNETba38823a2f, DATARMNET560e127137]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_recycle_frag_descriptor @ 00104020 size=1
// signature: undefined rmnet_recycle_frag_descriptor(void)
// callers: [DATARMNETa3055c21f2, DATARMNETb56d685c50]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_recycle_frag_descriptor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_descriptor_add_frags_from @ 00104028 size=1
// signature: undefined rmnet_frag_descriptor_add_frags_from(void)
// callers: [DATARMNETa3055c21f2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_descriptor_add_frags_from(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104030 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [DATARMNET29e8d137c4, DATARMNETc70e73c8d4, DATARMNETa3055c21f2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104038 size=1
// signature: undefined __list_add_valid(void)
// callers: [DATARMNET19d190f2bd, DATARMNETa3055c21f2, DATARMNETb56d685c50, DATARMNET33aa5df9ef]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00104040 size=1
// signature: undefined kstrtoull(void)
// callers: [__DATARMNET6d2ed4b822, __DATARMNET9c85bb95a3, __DATARMNETdf66588a73]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00104050 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [DATARMNETb56d685c50, DATARMNETc9dd320f49, DATARMNET95e1703026, DATARMNET664568fcd0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00104058 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [DATARMNETb56d685c50, DATARMNETc9dd320f49, DATARMNET95e1703026, DATARMNET6a76048590]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_header_ptr @ 00104070 size=1
// signature: undefined rmnet_frag_header_ptr(void)
// callers: [DATARMNET4c7cdc25b7, DATARMNETb56d685c50]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_header_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_ipv6_skip_exthdr @ 00104078 size=1
// signature: undefined rmnet_frag_ipv6_skip_exthdr(void)
// callers: [DATARMNETb56d685c50]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_deliver @ 00104080 size=1
// signature: undefined rmnet_frag_deliver(void)
// callers: [DATARMNETc70e73c8d4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_deliver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104098 size=1
// signature: undefined _printk(void)
// callers: [DATARMNET9f53d54812, cleanup_module, DATARMNET7dec24813e, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice_notifier @ 001040a0 size=1
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
// unregister_netdevice_notifier @ 001040a8 size=1
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
// strncmp @ 001040b0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [DATARMNET7dec24813e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_get_port @ 001040b8 size=1
// signature: undefined rmnet_get_port(void)
// callers: [DATARMNET7dec24813e]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_get_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001040c8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_register @ 001040d0 size=1
// signature: undefined qmi_rmnet_ps_ind_register(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_rmnet_ps_ind_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_dl_ind_register @ 001040d8 size=1
// signature: undefined rmnet_map_dl_ind_register(void)
// callers: [DATARMNET9f53d54812]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_dl_ind_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040e0 size=1
// signature: undefined kfree(void)
// callers: [DATARMNET9f53d54812, DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_deregister @ 001040e8 size=1
// signature: undefined qmi_rmnet_ps_ind_deregister(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_rmnet_ps_ind_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_map_dl_ind_deregister @ 001040f0 size=1
// signature: undefined rmnet_map_dl_ind_deregister(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_map_dl_ind_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 001040f8 size=1
// signature: undefined synchronize_rcu(void)
// callers: [DATARMNET345f805b34]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



