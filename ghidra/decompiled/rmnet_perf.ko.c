// Decompiled by Ghidra 12.2
// Program: rmnet_perf.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNETf2958615b1 @ 001005b4 size=500
// signature: undefined DATARMNETf2958615b1(void)
// callers: []
//------------------------------------------------------------

void DATARMNETf2958615b1(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  byte *pbVar6;
  char local_58 [4];
  short local_54 [2];
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    local_40 = 0;
    local_50 = 0;
    local_54[0] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if ((param_1 != 0) && (iVar2 = skb_copy_bits(param_1,0,&local_50,0x28), -1 < iVar2)) {
        pcVar5 = (char *)((ulong)&local_50 | 6);
        goto LAB_00100688;
      }
    }
    else if (*(long *)(param_1 + 0xe0) != 0) {
      pcVar5 = (char *)(*(long *)(param_1 + 0xe0) + 6);
LAB_00100688:
      local_58[0] = *pcVar5;
      iVar2 = ipv6_skip_exthdr(param_1,0x28,local_58,local_54);
      uVar4 = 0xffffffea;
      if ((iVar2 < 0) || (local_54[0] != 0)) goto LAB_00100730;
      if (local_58[0] != '\x06') {
        if (local_58[0] != '\x11') goto LAB_00100730;
        if (DATARMNET21c7a3c377 != '\0') {
          DATARMNET2a6d02a6a5(param_1);
        }
        uVar3 = DATARMNET77ab42949f(param_1,iVar2);
        goto joined_r0x001006ec;
      }
      if (DATARMNETc03b668e4c == '\0') goto LAB_00100730;
LAB_00100724:
      DATARMNET9250714999(param_1);
    }
  }
  else if (*(short *)(param_1 + 0xb4) == 8) {
    local_40 = local_40 & 0xffffffff00000000;
    local_50 = 0;
    local_48 = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 != 0) {
        pbVar6 = (byte *)&local_50;
        iVar2 = skb_copy_bits(param_1,0,&local_50,0x14);
        if (-1 < iVar2) goto LAB_00100610;
      }
    }
    else {
      pbVar6 = *(byte **)(param_1 + 0xe0);
      if (pbVar6 != (byte *)0x0) {
LAB_00100610:
        if ((*(ushort *)(pbVar6 + 6) & 0xff3f) == 0) {
          if (pbVar6[9] == 6) {
            if (DATARMNETc03b668e4c == '\0') goto LAB_0010072c;
            goto LAB_00100724;
          }
          if (pbVar6[9] != 0x11) goto LAB_0010072c;
          if (DATARMNET21c7a3c377 != '\0') {
            DATARMNET2a6d02a6a5(param_1);
          }
          uVar3 = DATARMNET77ab42949f(param_1,(*pbVar6 & 0xf) << 2);
joined_r0x001006ec:
          if ((uVar3 & 1) != 0) {
            uVar4 = 0;
            *(undefined4 *)(param_1 + 0x94) = 0;
            *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x200;
            goto LAB_00100730;
          }
        }
      }
    }
  }
LAB_0010072c:
  uVar4 = 0xffffffea;
LAB_00100730:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET7b0253229f @ 001007ac size=348
// signature: undefined DATARMNET7b0253229f(void)
// callers: []
//------------------------------------------------------------

void DATARMNET7b0253229f(long param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  char local_58 [4];
  short local_54 [2];
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    local_40 = 0;
    local_50 = 0;
    local_54[0] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if ((param_1 == 0) || (iVar3 = skb_copy_bits(param_1,0,&local_50,0x28), iVar3 < 0))
      goto LAB_00100890;
      pcVar5 = (char *)((ulong)&local_50 | 6);
    }
    else {
      if (*(long *)(param_1 + 0xe0) == 0) goto LAB_00100890;
      pcVar5 = (char *)(*(long *)(param_1 + 0xe0) + 6);
    }
    local_58[0] = *pcVar5;
    iVar3 = ipv6_skip_exthdr(param_1,0x28,local_58,local_54);
    if ((iVar3 < 0) || (local_54[0] != 0)) goto LAB_00100890;
    cVar1 = local_58[0];
  }
  else {
    if (*(short *)(param_1 + 0xb4) != 8) goto LAB_00100890;
    local_40 = local_40 & 0xffffffff00000000;
    local_50 = 0;
    local_48 = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 == 0) goto LAB_00100890;
      iVar3 = skb_copy_bits(param_1,0,&local_50,0x14);
      puVar4 = &local_50;
      if (iVar3 < 0) goto LAB_00100890;
    }
    else {
      puVar4 = *(undefined8 **)(param_1 + 0xe0);
      if (puVar4 == (undefined8 *)0x0) goto LAB_00100890;
    }
    if ((*(ushort *)((long)puVar4 + 6) & 0xff3f) != 0) goto LAB_00100890;
    cVar1 = *(char *)((long)puVar4 + 9);
  }
  if ((cVar1 == '\x06') && (DATARMNETc03b668e4c != '\0')) {
    DATARMNETd8fdde8978(param_1);
  }
LAB_00100890:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET324fe25dad @ 0010090c size=460
// signature: undefined DATARMNET324fe25dad(void)
// callers: []
//------------------------------------------------------------

void DATARMNET324fe25dad(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  byte *pbVar5;
  char local_58 [4];
  short local_54 [2];
  byte local_50 [16];
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    local_38 = 0;
    uStack_30 = 0;
    local_50[8] = 0;
    local_50[9] = 0;
    local_50[10] = 0;
    local_50[0xb] = 0;
    local_50[0xc] = 0;
    local_50[0xd] = 0;
    local_50[0xe] = 0;
    local_50[0xf] = 0;
    local_40 = 0;
    local_50[0] = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    local_50[7] = 0;
    local_54[0] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if ((param_1 == 0) || (iVar2 = skb_copy_bits(param_1,0,local_50,0x28), iVar2 < 0))
      goto LAB_00100a60;
      pcVar4 = (char *)((ulong)local_50 | 6);
    }
    else {
      if (*(long *)(param_1 + 0xe0) == 0) goto LAB_00100a60;
      pcVar4 = (char *)(*(long *)(param_1 + 0xe0) + 6);
    }
    local_58[0] = *pcVar4;
    iVar2 = ipv6_skip_exthdr(param_1,0x28,local_58,local_54);
    if ((iVar2 < 0) || (local_54[0] != 0)) goto LAB_00100a60;
    if (local_58[0] == '\x06') goto LAB_00100a4c;
    if (local_58[0] != '\x11') goto LAB_00100a60;
    if (DATARMNET21c7a3c377 != '\0') {
      DATARMNET5ecc30669c(param_1);
    }
  }
  else {
    if (*(short *)(param_1 + 0xb4) != 8) goto LAB_00100a60;
    local_40 = local_40 & 0xffffffff00000000;
    local_50[0] = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    local_50[7] = 0;
    local_50[8] = 0;
    local_50[9] = 0;
    local_50[10] = 0;
    local_50[0xb] = 0;
    local_50[0xc] = 0;
    local_50[0xd] = 0;
    local_50[0xe] = 0;
    local_50[0xf] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 == 0) goto LAB_00100a60;
      pbVar5 = local_50;
      iVar2 = skb_copy_bits(param_1,0,local_50,0x14);
      if (iVar2 < 0) goto LAB_00100a60;
    }
    else {
      pbVar5 = *(byte **)(param_1 + 0xe0);
      if (pbVar5 == (byte *)0x0) goto LAB_00100a60;
    }
    if ((*(ushort *)(pbVar5 + 6) & 0xff3f) != 0) goto LAB_00100a60;
    if (pbVar5[9] == 6) {
LAB_00100a4c:
      if (DATARMNETc03b668e4c != '\0') {
        DATARMNET9d574e64b1(param_1);
      }
      goto LAB_00100a60;
    }
    if (pbVar5[9] != 0x11) goto LAB_00100a60;
    if (DATARMNET21c7a3c377 != '\0') {
      DATARMNET5ecc30669c(param_1);
    }
    iVar2 = (*pbVar5 & 0xf) << 2;
  }
  uVar3 = DATARMNET77ab42949f(param_1,iVar2);
  if ((uVar3 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0xda001a;
  }
LAB_00100a60:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET49c17a32bc @ 00100adc size=60
// signature: undefined DATARMNET49c17a32bc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET49c17a32bc(void)

{
  _rmnet_perf_egress_hook1 = DATARMNET324fe25dad;
  rmnet_module_hook_register(DATARMNET95a71e03c1,4);
  return;
}



//------------------------------------------------------------
// DATARMNET41e8cc085c @ 00100b1c size=52
// signature: undefined DATARMNET41e8cc085c(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET41e8cc085c(void)

{
  _rmnet_perf_egress_hook1 = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET95a71e03c1,4);
  synchronize_rcu();
  return;
}



//------------------------------------------------------------
// DATARMNET77ab42949f @ 00100b50 size=304
// signature: undefined DATARMNET77ab42949f(void)
// callers: [DATARMNETf2958615b1, DATARMNET324fe25dad]
//------------------------------------------------------------

void DATARMNET77ab42949f(long param_1,int param_2)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  short *psVar5;
  short local_48 [6];
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  if (*(int *)(param_1 + 0x70) - (*(int *)(param_1 + 0x74) + param_2) < 8) {
    if (param_1 != 0) {
      psVar5 = local_48;
      iVar3 = skb_copy_bits(param_1,param_2,local_48,8);
      if (-1 < iVar3) goto LAB_00100ba4;
    }
  }
  else {
    psVar5 = (short *)(*(long *)(param_1 + 0xe0) + (long)param_2);
    if (psVar5 != (short *)0x0) {
LAB_00100ba4:
      if (((*psVar5 == -0x44ff) || (psVar5[1] == -0x44ff)) &&
         (8 < (ushort)((ushort)psVar5[2] >> 8 | psVar5[2] << 8))) {
        if ((*(int *)(param_1 + 0x70) - (*(int *)(param_1 + 0x74) + param_2)) + -8 < 1) {
          if (param_1 != 0) {
            pbVar4 = local_3c;
            iVar3 = skb_copy_bits(param_1,param_2 + 8,local_3c,1);
            if (-1 < iVar3) goto LAB_00100bfc;
          }
        }
        else {
          pbVar4 = (byte *)(*(long *)(param_1 + 0xe0) + (long)(param_2 + 8));
          if (pbVar4 != (byte *)0x0) {
LAB_00100bfc:
            bVar2 = 0xbf < *pbVar4;
            goto LAB_00100c50;
          }
        }
      }
    }
  }
  bVar2 = false;
LAB_00100c50:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9250714999 @ 00100c84 size=368
// signature: undefined DATARMNET9250714999(void)
// callers: [DATARMNETf2958615b1]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET9250714999(long param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  long lVar3;
  undefined1 uVar4;
  ulong local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  if (((ulong)*(ushort *)(param_1 + 0xb6) != 0xffff) && ((*(ushort *)(param_1 + 0x80) & 0x60) != 0))
  {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
    uVar2 = *(ushort *)(puVar1 + 3);
    if (((uVar2 >> 9 & 1) == 0) &&
       (((*(int *)(param_1 + 0x70) - (int)puVar1) - (uVar2 >> 2 & 0x3c)) + *(int *)(param_1 + 0xe0)
        != 0 || (uVar2 & 0x1000) == 0)) {
      lVar3 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
      if (*(short *)(param_1 + 0xb4) == 8) {
        local_50 = (ulong)*(uint *)(lVar3 + 0xc);
        uVar4 = 4;
        local_40 = (ulong)*(uint *)(lVar3 + 0x10);
      }
      else {
        local_50 = *(ulong *)(lVar3 + 8);
        local_48 = *(undefined8 *)(lVar3 + 0x10);
        local_40 = *(ulong *)(lVar3 + 0x18);
        local_38 = *(undefined8 *)(lVar3 + 0x20);
        uVar4 = 6;
      }
      local_30 = (ulong)CONCAT14(uVar4,*puVar1);
      __rcu_read_lock();
      lVar3 = DATARMNET9f0aaf07cc(&local_50,param_1,0);
      if ((lVar3 != 0) && ((ulong)(_jiffies - *(long *)(lVar3 + 0x48)) < 0x1f5)) {
        if (*(char *)(lVar3 + 100) == '\0') {
          *(int *)(param_1 + 0x34) = *(int *)(lVar3 + 0x50) - *(int *)(lVar3 + 0x54);
          *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(lVar3 + 0x5c);
          *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(lVar3 + 0x60);
        }
        else {
          *(undefined1 *)(param_1 + 0x2a) = 1;
        }
      }
      __rcu_read_unlock();
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9f0aaf07cc @ 00100df4 size=624
// signature: undefined DATARMNET9f0aaf07cc(void)
// callers: [DATARMNETd8fdde8978, DATARMNET9250714999, DATARMNET9d574e64b1]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * DATARMNET9f0aaf07cc(long *param_1,long param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  
  uVar5 = _raw_spin_lock_irqsave(&DATARMNET8e3721c47d);
  plVar8 = (long *)(&DATARMNET1fd012f255)[(uint)((int)param_1[4] * 0x61c88647) >> 0x1c];
  do {
    if (plVar8 == (long *)0x0) {
      if (DATARMNET1c62a8e2c9 < DATARMNET84337b8855) {
        plVar8 = (long *)kmalloc_trace(_call_rcu,0xb20,0x68);
        if (plVar8 != (long *)0x0) {
          lVar6 = param_1[3];
          lVar7 = param_1[4];
          plVar8[6] = param_1[2];
          plVar8[7] = lVar6;
          lVar6 = *param_1;
          lVar2 = param_1[1];
          plVar8[8] = lVar7;
          *(undefined4 *)((long)plVar8 + 0x5c) = 0x2ee00;
          plVar8[4] = lVar6;
          plVar8[5] = lVar2;
          lVar6 = param_1[4];
          plVar8[9] = _jiffies;
          plVar1 = &DATARMNET1fd012f255 + ((uint)((int)lVar6 * 0x61c88647) >> 0x1c);
          lVar6 = *plVar1;
          *plVar8 = lVar6;
          plVar8[1] = (long)plVar1;
          *plVar1 = (long)plVar8;
          if (lVar6 != 0) {
            *(long **)(lVar6 + 8) = plVar8;
          }
          DATARMNETeb09e391b5 = DATARMNETeb09e391b5 + 1;
          if (DATARMNET1c62a8e2c9 == 0) {
            queue_delayed_work_on(0x20,_system_wq,&DATARMNETac6535da80,0x7d);
          }
          DATARMNET1c62a8e2c9 = DATARMNET1c62a8e2c9 + 1;
          _raw_spin_unlock_irqrestore(&DATARMNET8e3721c47d,uVar5);
          lVar6 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb6);
          *(undefined4 *)(plVar8 + 0xb) = *(undefined4 *)(param_2 + 0x94);
          if ((param_3 & 1) == 0) {
            uVar3 = *(uint *)(lVar6 + 4);
            uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
            uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
            *(uint *)(plVar8 + 10) = uVar3;
            *(uint *)((long)plVar8 + 0x54) = uVar3 - 1;
            uVar4 = *(undefined4 *)((long)plVar8 + 0x5c);
            *(undefined4 *)(param_2 + 0x34) = 0;
            *(undefined4 *)(param_2 + 0x38) = uVar4;
            return plVar8;
          }
          uVar3 = *(uint *)(lVar6 + 8);
          uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
          uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
          *(uint *)((long)plVar8 + 0x54) = uVar3;
          *(uint *)(plVar8 + 10) = uVar3;
          return plVar8;
        }
        DAT_00102758 = DAT_00102758 + 1;
      }
      _raw_spin_unlock_irqrestore(&DATARMNET8e3721c47d,uVar5);
      return (long *)0x0;
    }
    if ((((*(char *)((long)plVar8 + 0x65) == '\0') &&
         (*(char *)((long)plVar8 + 0x44) == *(char *)((long)param_1 + 0x24))) &&
        (*(short *)(plVar8 + 8) == (short)param_1[4])) &&
       (*(short *)((long)plVar8 + 0x42) == *(short *)((long)param_1 + 0x22))) {
      if (*(char *)((long)plVar8 + 0x44) == '\x04') {
        if ((*(int *)(plVar8 + 4) == (int)*param_1) && (*(int *)(plVar8 + 6) == (int)param_1[2])) {
LAB_00100fec:
          _raw_spin_unlock_irqrestore(&DATARMNET8e3721c47d,uVar5);
          return plVar8;
        }
      }
      else if ((plVar8[4] == *param_1 && plVar8[5] == param_1[1]) &&
              (plVar8[6] == param_1[2] && plVar8[7] == param_1[3])) goto LAB_00100fec;
    }
    plVar8 = (long *)*plVar8;
  } while( true );
}



//------------------------------------------------------------
// DATARMNETd8fdde8978 @ 00101068 size=460
// signature: undefined DATARMNETd8fdde8978(void)
// callers: [DATARMNET7b0253229f]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETd8fdde8978(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  uint uVar3;
  ushort uVar4;
  long lVar5;
  undefined1 uVar6;
  ulong local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_60 = 0;
  if (((ulong)*(ushort *)(param_1 + 0xb6) != 0xffff) && ((*(ushort *)(param_1 + 0x80) & 0x60) != 0))
  {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
    uVar4 = *(ushort *)(puVar1 + 3);
    if (((uVar4 >> 9 & 1) == 0) &&
       (((*(int *)(param_1 + 0x70) - (int)puVar1) - (uVar4 >> 2 & 0x3c)) + *(int *)(param_1 + 0xe0)
        != 0 || (uVar4 & 0x1000) == 0)) {
      lVar5 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
      if (*(short *)(param_1 + 0xb4) == 8) {
        local_60 = (ulong)*(uint *)(lVar5 + 0xc);
        uVar6 = 4;
        local_50 = (ulong)*(uint *)(lVar5 + 0x10);
      }
      else {
        local_60 = *(ulong *)(lVar5 + 8);
        local_58 = *(undefined8 *)(lVar5 + 0x10);
        local_50 = *(ulong *)(lVar5 + 0x18);
        local_48 = *(undefined8 *)(lVar5 + 0x20);
        uVar6 = 6;
      }
      local_40 = (ulong)CONCAT14(uVar6,*puVar1);
      __rcu_read_lock();
      lVar5 = DATARMNET9f0aaf07cc(&local_60,param_1,0);
      if ((lVar5 != 0) && ((ulong)(_jiffies - *(long *)(lVar5 + 0x48)) < 0x1f5)) {
        uVar3 = *(uint *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6) + 4);
        *(long *)(lVar5 + 0x48) = _jiffies;
        if ((*(char *)(lVar5 + 100) == '\0') &&
           (uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8,
           uVar3 = uVar3 >> 0x10 | uVar3 << 0x10, (int)(*(int *)(lVar5 + 0x50) - uVar3) < 0)) {
          lVar2 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6);
          if (*(uint *)(lVar5 + 0x5c) <
              (uVar3 - *(int *)(lVar5 + 0x54)) +
              (((*(int *)(param_1 + 0xe0) + *(int *)(param_1 + 0x70)) - (int)lVar2) -
              (*(ushort *)(lVar2 + 0xc) >> 2 & 0x3c))) {
            DATARMNET31a7673e56(lVar5,param_1);
          }
          *(uint *)(lVar5 + 0x50) = uVar3;
        }
      }
      __rcu_read_unlock();
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9d574e64b1 @ 00101238 size=404
// signature: undefined DATARMNET9d574e64b1(void)
// callers: [DATARMNET324fe25dad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET9d574e64b1(long param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  long lVar5;
  undefined1 uVar6;
  ulong local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_60 = 0;
  if ((ulong)*(ushort *)(param_1 + 0xb6) != 0xffff) {
    puVar1 = (undefined2 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
    uVar4 = puVar1[6];
    if (((uVar4 >> 9 & 1) == 0) &&
       (((*(int *)(param_1 + 0x70) - (int)puVar1) - (uVar4 >> 2 & 0x3c)) + *(int *)(param_1 + 0xe0)
        == 0 && (uVar4 & 0x1000) != 0)) {
      lVar5 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
      if (*(short *)(param_1 + 0xb4) == 8) {
        local_60 = (ulong)*(uint *)(lVar5 + 0x10);
        uVar6 = 4;
        local_50 = (ulong)*(uint *)(lVar5 + 0xc);
      }
      else {
        local_60 = *(ulong *)(lVar5 + 0x18);
        local_58 = *(undefined8 *)(lVar5 + 0x20);
        local_50 = *(ulong *)(lVar5 + 8);
        local_48 = *(undefined8 *)(lVar5 + 0x10);
        uVar6 = 6;
      }
      local_40 = (ulong)CONCAT14(uVar6,CONCAT22(*puVar1,puVar1[1]));
      __rcu_read_lock();
      lVar5 = DATARMNET9f0aaf07cc(&local_60,param_1,1);
      if ((lVar5 != 0) && ((ulong)(_jiffies - *(long *)(lVar5 + 0x48)) < 0x1f5)) {
        uVar3 = *(uint *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6) + 8);
        *(long *)(lVar5 + 0x48) = _jiffies;
        if ((*(char *)(lVar5 + 100) == '\0') &&
           (uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8,
           uVar3 = uVar3 >> 0x10 | uVar3 << 0x10, (int)(*(int *)(lVar5 + 0x54) - uVar3) < 0)) {
          uVar2 = 0;
          if (*(uint *)(lVar5 + 0x50) <= uVar3) {
            uVar2 = uVar3 - *(uint *)(lVar5 + 0x50);
          }
          if (*(uint *)(lVar5 + 0x5c) < uVar2) {
            DATARMNET31a7673e56(lVar5,param_1);
          }
          *(uint *)(lVar5 + 0x54) = uVar3;
        }
      }
      __rcu_read_unlock();
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET7fa1835595 @ 001013d0 size=160
// signature: undefined DATARMNET7fa1835595(void)
// callers: []
//------------------------------------------------------------

void DATARMNET7fa1835595(int param_1,int param_2)

{
  long lVar1;
  long *plVar2;
  
  if (param_1 == 0) {
    if (param_2 == 1) {
      DATARMNETc03b668e4c = 1;
    }
    else if (param_2 == 0) {
      DATARMNETc03b668e4c = 0;
    }
  }
  else {
    __rcu_read_lock();
    lVar1 = 0;
    do {
      for (plVar2 = (long *)(&DATARMNET1fd012f255)[lVar1]; plVar2 != (long *)0x0;
          plVar2 = (long *)*plVar2) {
        if (*(int *)(plVar2 + 0xb) == param_1) {
          *(int *)((long)plVar2 + 0x5c) = param_2;
        }
      }
      lVar1 = lVar1 + 1;
    } while (lVar1 != 0x10);
    __rcu_read_unlock();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET7e9995246e @ 00101474 size=96
// signature: undefined DATARMNET7e9995246e(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 DATARMNET7e9995246e(void)

{
  DATARMNETac6535da80 = 0xfffffffe0;
  DAT_001026c8 = &DAT_001026c8;
  DAT_001026d0 = &DAT_001026c8;
  DAT_001026d8 = DATARMNETfec9085d8e;
  init_timer_key(&DAT_001026f0,&delayed_work_timer_fn,0x200000,0,0);
  return 0;
}



//------------------------------------------------------------
// DATARMNETfec9085d8e @ 001014d8 size=320
// signature: undefined DATARMNETfec9085d8e(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETfec9085d8e(long param_1)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  
  uVar4 = _raw_spin_lock_irqsave(&DATARMNET8e3721c47d);
  lVar3 = _jiffies;
  lVar7 = 0;
  cVar1 = *(char *)(param_1 + 0x88);
  do {
    plVar6 = (long *)(&DATARMNET1fd012f255)[lVar7];
    while (plVar2 = plVar6, plVar2 != (long *)0x0) {
      plVar6 = (long *)*plVar2;
      if ((*(char *)((long)plVar2 + 0x65) == '\0') &&
         ((cVar1 != '\0' || (500 < (ulong)(lVar3 - plVar2[9]))))) {
        plVar5 = (long *)plVar2[1];
        *(undefined1 *)((long)plVar2 + 0x65) = 1;
        if (plVar5 != (long *)0x0) {
          *plVar5 = (long)plVar6;
          if (plVar6 != (long *)0x0) {
            plVar6[1] = (long)plVar5;
          }
          plVar2[1] = 0;
        }
        call_rcu(plVar2 + 2,DATARMNET776e08992c);
        _DAT_00102760 = _DAT_00102760 + 1;
        DATARMNET1c62a8e2c9 = DATARMNET1c62a8e2c9 + -1;
      }
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 0x10);
  if (DATARMNET1c62a8e2c9 != 0) {
    queue_delayed_work_on(0x20,_system_wq,param_1,0x7d);
  }
  _raw_spin_unlock_irqrestore(&DATARMNET8e3721c47d,uVar4);
  return;
}



//------------------------------------------------------------
// DATARMNET38bb6f2b7a @ 0010161c size=88
// signature: undefined DATARMNET38bb6f2b7a(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET38bb6f2b7a(void)

{
  cancel_delayed_work_sync(&DATARMNETac6535da80);
  DAT_00102748 = 1;
  queue_delayed_work_on(0x20,_system_wq,&DATARMNETac6535da80,0);
  cancel_delayed_work_sync(&DATARMNETac6535da80);
  return;
}



//------------------------------------------------------------
// DATARMNET31a7673e56 @ 00101674 size=452
// signature: undefined DATARMNET31a7673e56(void)
// callers: [DATARMNETd8fdde8978, DATARMNET9d574e64b1]
//------------------------------------------------------------

void DATARMNET31a7673e56(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x18);
  if (lVar1 == 0) {
    lVar1 = *(long *)(param_2 + 0x10);
    if (*(char *)(param_1 + 0x44) == '\x04') {
      lVar1 = __inet_lookup_established
                        (*(undefined8 *)(lVar1 + 0x500),&tcp_hashinfo,
                         *(undefined4 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x40),
                         *(undefined4 *)(param_1 + 0x30),
                         *(ushort *)(param_1 + 0x42) >> 8 | *(ushort *)(param_1 + 0x42) << 8,
                         *(undefined4 *)(lVar1 + 0xd8),0);
    }
    else {
      lVar1 = __inet6_lookup_established
                        (*(undefined8 *)(lVar1 + 0x500),&tcp_hashinfo,param_1 + 0x20,
                         *(undefined2 *)(param_1 + 0x40),param_1 + 0x30,
                         *(ushort *)(param_1 + 0x42) >> 8 | *(ushort *)(param_1 + 0x42) << 8,
                         *(undefined4 *)(lVar1 + 0xd8),0);
    }
    if (lVar1 == 0) {
      *(undefined1 *)(param_1 + 100) = 1;
      *(undefined1 *)(param_2 + 0x2a) = 1;
      DAT_00102768 = DAT_00102768 + 1;
    }
    else {
      if ((1 << (ulong)(*(byte *)(lVar1 + 0x12) & 0x1f) & 0xffffefbfU) != 0) {
        _raw_spin_lock(lVar1 + 0x98);
        if (((*(char *)(lVar1 + 0x12) == '\x01') && ((*(ulong *)(lVar1 + 0x60) & 1) == 0)) &&
           ((*(long *)(lVar1 + 0x70) != 0 && (*(char *)(lVar1 + 0x272) != '\x03')))) {
          *(byte *)(lVar1 + 0x560) = *(byte *)(lVar1 + 0x560) | 0x11;
          DAT_00102770 = DAT_00102770 + 1;
          *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
        }
        _raw_spin_unlock(lVar1 + 0x98);
      }
      sock_gen_put(lVar1);
    }
  }
  else if (((((1 << (ulong)(*(byte *)(lVar1 + 0x12) & 0x1f) & 0xffffefbfU) != 0) &&
            (*(char *)(lVar1 + 0x12) == '\x01')) && ((*(ulong *)(lVar1 + 0x60) & 1) == 0)) &&
          ((*(long *)(lVar1 + 0x70) != 0 && (*(char *)(lVar1 + 0x272) != '\x03')))) {
    *(byte *)(lVar1 + 0x560) = *(byte *)(lVar1 + 0x560) | 0x10;
    DAT_00102778 = DAT_00102778 + 1;
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET776e08992c @ 0010183c size=32
// signature: undefined DATARMNET776e08992c(void)
// callers: []
//------------------------------------------------------------

void DATARMNET776e08992c(long param_1)

{
  kfree(param_1 + -0x10);
  return;
}



//------------------------------------------------------------
// DATARMNET2a6d02a6a5 @ 00101860 size=264
// signature: undefined DATARMNET2a6d02a6a5(void)
// callers: [DATARMNETf2958615b1]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET2a6d02a6a5(long param_1)

{
  long lVar1;
  undefined1 uVar2;
  ulong local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  if (((ulong)*(ushort *)(param_1 + 0xb6) != 0xffff) && ((*(ushort *)(param_1 + 0x80) & 0x60) != 0))
  {
    lVar1 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
    if (*(short *)(param_1 + 0xb4) == 8) {
      local_50 = (ulong)*(uint *)(lVar1 + 0xc);
      uVar2 = 4;
      local_40 = (ulong)*(uint *)(lVar1 + 0x10);
    }
    else {
      local_50 = *(ulong *)(lVar1 + 8);
      local_48 = *(undefined8 *)(lVar1 + 0x10);
      local_40 = *(ulong *)(lVar1 + 0x18);
      local_38 = *(undefined8 *)(lVar1 + 0x20);
      uVar2 = 6;
    }
    local_30 = (ulong)CONCAT14(uVar2,*(undefined4 *)
                                      (*(long *)(param_1 + 0xd8) +
                                      (ulong)*(ushort *)(param_1 + 0xb6)));
    __rcu_read_lock();
    lVar1 = DATARMNET270a2369fc(&local_50);
    if ((lVar1 != 0) && ((ulong)(_jiffies - *(long *)(lVar1 + 0x50)) < 0x1f5)) {
      DATARMNET991df48508(lVar1,param_1);
    }
    __rcu_read_unlock();
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET270a2369fc @ 00101968 size=468
// signature: undefined DATARMNET270a2369fc(void)
// callers: [DATARMNET2a6d02a6a5, DATARMNET5ecc30669c]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * DATARMNET270a2369fc(long *param_1)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  uVar3 = _raw_spin_lock_irqsave(&DATARMNETa125272ee8);
  for (plVar6 = (long *)(&DATARMNET187c01aba9)[(uint)((int)param_1[4] * 0x61c88647) >> 0x1c];
      plVar6 != (long *)0x0; plVar6 = (long *)*plVar6) {
    if ((((*(char *)(plVar6 + 0xb) == '\0') &&
         (*(char *)((long)plVar6 + 0x44) == *(char *)((long)param_1 + 0x24))) &&
        (*(short *)(plVar6 + 8) == (short)param_1[4])) &&
       (*(short *)((long)plVar6 + 0x42) == *(short *)((long)param_1 + 0x22))) {
      if (*(char *)((long)plVar6 + 0x44) == '\x04') {
        if ((*(int *)(plVar6 + 4) == (int)*param_1) && (*(int *)(plVar6 + 6) == (int)param_1[2]))
        goto LAB_00101b10;
      }
      else if ((plVar6[4] == *param_1 && plVar6[5] == param_1[1]) &&
              (plVar6[6] == param_1[2] && plVar6[7] == param_1[3])) goto LAB_00101b10;
    }
  }
  plVar6 = (long *)kmalloc_trace(_call_rcu,0xb20,0x60);
  if (plVar6 == (long *)0x0) {
    DAT_00102820 = DAT_00102820 + 1;
  }
  else {
    lVar4 = param_1[3];
    lVar5 = param_1[4];
    plVar6[6] = param_1[2];
    plVar6[7] = lVar4;
    lVar4 = *param_1;
    lVar2 = param_1[1];
    plVar6[8] = lVar5;
    plVar6[4] = lVar4;
    plVar6[5] = lVar2;
    lVar4 = param_1[4];
    plVar6[10] = _jiffies;
    plVar1 = &DATARMNET187c01aba9 + ((uint)((int)lVar4 * 0x61c88647) >> 0x1c);
    lVar4 = *plVar1;
    *plVar6 = lVar4;
    plVar6[1] = (long)plVar1;
    *plVar1 = (long)plVar6;
    if (lVar4 != 0) {
      *(long **)(lVar4 + 8) = plVar6;
    }
    DATARMNETf41987fea1 = DATARMNETf41987fea1 + 1;
    if (DATARMNETe0c4a54a69 == 0) {
      queue_delayed_work_on(0x20,_system_wq,&DATARMNET3ed0b852e9,0x7d);
    }
    DATARMNETe0c4a54a69 = DATARMNETe0c4a54a69 + 1;
  }
LAB_00101b10:
  _raw_spin_unlock_irqrestore(&DATARMNETa125272ee8,uVar3);
  return plVar6;
}



//------------------------------------------------------------
// DATARMNET991df48508 @ 00101b3c size=400
// signature: undefined DATARMNET991df48508(void)
// callers: [DATARMNET2a6d02a6a5, DATARMNET5ecc30669c]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET991df48508(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  long lVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  *(undefined8 *)(param_1 + 0x50) = _jiffies;
  if (*(ulong *)(param_1 + 0x48) < 0xfffffffffffff001) {
    if (*(ulong *)(param_1 + 0x48) == 0) {
      uVar6 = *(undefined8 *)(*(long *)(param_2 + 0x10) + 0x500);
      if (*(char *)(param_1 + 0x44) == '\x04') {
        uVar1 = *(ulong *)(param_2 + 0x58) & 0xfffffffffffffffe;
        if ((uVar1 == 0) || (iVar2 = *(int *)(uVar1 + 0x7c), iVar2 == 0)) {
          iVar2 = *(int *)(param_2 + 0x90);
        }
        lVar7 = __udp4_lib_lookup(uVar6,*(undefined4 *)(param_1 + 0x20),
                                  *(undefined2 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x30),
                                  *(undefined2 *)(param_1 + 0x42),iVar2,0,&udp_table,0);
      }
      else {
        lVar7 = __udp6_lib_lookup(uVar6,param_1 + 0x20,*(undefined2 *)(param_1 + 0x40),
                                  param_1 + 0x30,*(undefined2 *)(param_1 + 0x42),
                                  *(undefined4 *)(param_2 + 0x28),0,&udp_table,0);
      }
      if (lVar7 != 0) {
        puVar8 = (uint *)(lVar7 + 0x80);
        uVar9 = *puVar8;
        if (*puVar8 == 0) {
          uVar10 = 0;
        }
        else {
          do {
            Hint_Prefetch(puVar8,2,0,1);
            do {
              uVar3 = *puVar8;
              if (uVar3 != uVar9) break;
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(puVar8,0x10);
              if (bVar5) {
                *puVar8 = uVar9 + 1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            uVar10 = uVar9;
          } while ((uVar9 != uVar3) && (uVar10 = 0, uVar9 = uVar3, uVar3 != 0));
        }
        if ((int)(uVar10 + 1 | uVar10) < 0) {
          refcount_warn_saturate(puVar8,0);
        }
        if (uVar10 != 0) {
          *(long *)(param_1 + 0x48) = lVar7;
          return;
        }
      }
      *(undefined8 *)(param_1 + 0x48) = 0xffffffffffffffea;
      *(undefined1 *)(param_2 + 0x2a) = 1;
      DAT_00102830 = DAT_00102830 + 1;
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x2a) = 1;
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5ecc30669c @ 00101ce4 size=252
// signature: undefined DATARMNET5ecc30669c(void)
// callers: [DATARMNET324fe25dad]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET5ecc30669c(long param_1)

{
  undefined2 *puVar1;
  long lVar2;
  undefined1 uVar3;
  ulong local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  if ((ulong)*(ushort *)(param_1 + 0xb6) != 0xffff) {
    puVar1 = (undefined2 *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb6));
    lVar2 = *(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8);
    if (*(short *)(param_1 + 0xb4) == 8) {
      local_50 = (ulong)*(uint *)(lVar2 + 0x10);
      uVar3 = 4;
      local_40 = (ulong)*(uint *)(lVar2 + 0xc);
    }
    else {
      local_50 = *(ulong *)(lVar2 + 0x18);
      local_48 = *(undefined8 *)(lVar2 + 0x20);
      local_40 = *(ulong *)(lVar2 + 8);
      local_38 = *(undefined8 *)(lVar2 + 0x10);
      uVar3 = 6;
    }
    local_30 = (ulong)CONCAT14(uVar3,CONCAT22(*puVar1,puVar1[1]));
    __rcu_read_lock();
    lVar2 = DATARMNET270a2369fc(&local_50);
    if ((lVar2 != 0) && ((ulong)(_jiffies - *(long *)(lVar2 + 0x50)) < 0x1f5)) {
      DATARMNET991df48508(lVar2,param_1);
    }
    __rcu_read_unlock();
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNETe80a33d544 @ 00101de4 size=96
// signature: undefined DATARMNETe80a33d544(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 DATARMNETe80a33d544(void)

{
  DATARMNET3ed0b852e9 = 0xfffffffe0;
  DAT_00102790 = &DAT_00102790;
  DAT_00102798 = &DAT_00102790;
  DAT_001027a0 = DATARMNET47ed281d61;
  init_timer_key(&DAT_001027b8,&delayed_work_timer_fn,0x200000,0,0);
  return 0;
}



//------------------------------------------------------------
// DATARMNET47ed281d61 @ 00101e48 size=320
// signature: undefined DATARMNET47ed281d61(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET47ed281d61(long param_1)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  
  uVar4 = _raw_spin_lock_irqsave(&DATARMNETa125272ee8);
  lVar3 = _jiffies;
  lVar7 = 0;
  cVar1 = *(char *)(param_1 + 0x88);
  do {
    plVar6 = (long *)(&DATARMNET187c01aba9)[lVar7];
    while (plVar2 = plVar6, plVar2 != (long *)0x0) {
      plVar6 = (long *)*plVar2;
      if (((char)plVar2[0xb] == '\0') && ((cVar1 != '\0' || (500 < (ulong)(lVar3 - plVar2[10]))))) {
        plVar5 = (long *)plVar2[1];
        *(undefined1 *)(plVar2 + 0xb) = 1;
        if (plVar5 != (long *)0x0) {
          *plVar5 = (long)plVar6;
          if (plVar6 != (long *)0x0) {
            plVar6[1] = (long)plVar5;
          }
          plVar2[1] = 0;
        }
        call_rcu(plVar2 + 2,DATARMNETfcb3ce7715);
        _DAT_00102828 = _DAT_00102828 + 1;
        DATARMNETe0c4a54a69 = DATARMNETe0c4a54a69 + -1;
      }
    }
    lVar7 = lVar7 + 1;
  } while (lVar7 != 0x10);
  if (DATARMNETe0c4a54a69 != 0) {
    queue_delayed_work_on(0x20,_system_wq,param_1,0x7d);
  }
  _raw_spin_unlock_irqrestore(&DATARMNETa125272ee8,uVar4);
  return;
}



//------------------------------------------------------------
// DATARMNET4b5170a1ef @ 00101f8c size=88
// signature: undefined DATARMNET4b5170a1ef(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET4b5170a1ef(void)

{
  cancel_delayed_work_sync(&DATARMNET3ed0b852e9);
  DAT_00102810 = 1;
  queue_delayed_work_on(0x20,_system_wq,&DATARMNET3ed0b852e9,0);
  cancel_delayed_work_sync(&DATARMNET3ed0b852e9);
  return;
}



//------------------------------------------------------------
// DATARMNETfcb3ce7715 @ 00101fe8 size=136
// signature: undefined DATARMNETfcb3ce7715(void)
// callers: []
//------------------------------------------------------------

void DATARMNETfcb3ce7715(long param_1)

{
  _STACK *p_Var1;
  int iVar2;
  char cVar3;
  bool bVar4;
  _STACK *p_Var5;
  
  p_Var5 = *(_STACK **)(param_1 + 0x38);
  if ((p_Var5 != (_STACK *)0x0) && (p_Var5 < (_STACK *)0xfffffffffffff001)) {
    p_Var1 = p_Var5 + 4;
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar2 = p_Var1->num;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar4) {
        p_Var1->num = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 == 1) {
      DataMemoryBarrier(2,1);
      sk_free(p_Var5);
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(p_Var1,3);
    }
  }
  kfree(param_1 + -0x10);
  return;
}



//------------------------------------------------------------
// init_module @ 00102084 size=124
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_001025f9,"DATARMNET63abbdc3d3");
  iVar1 = DATARMNET7e9995246e();
  if (iVar1 == 0) {
    iVar1 = DATARMNETe80a33d544();
    if (iVar1 == 0) {
      _rmnet_perf_egress_hook1 = DATARMNET324fe25dad;
      rmnet_module_hook_register(DATARMNET95a71e03c1,4);
    }
    else {
      DATARMNET38bb6f2b7a();
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00102104 size=80
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cleanup_module(void)

{
  _rmnet_perf_egress_hook1 = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET95a71e03c1,4);
  synchronize_rcu();
  DATARMNET4b5170a1ef();
  DATARMNET38bb6f2b7a();
  _printk(&DAT_001025c4,"DATARMNETa343229e33");
  return;
}



//------------------------------------------------------------
// ipv6_skip_exthdr @ 00104000 size=1
// signature: undefined ipv6_skip_exthdr(void)
// callers: [DATARMNETf2958615b1, DATARMNET7b0253229f, DATARMNET324fe25dad]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 00104008 size=1
// signature: undefined skb_copy_bits(void)
// callers: [DATARMNET77ab42949f, DATARMNETf2958615b1, DATARMNET7b0253229f, DATARMNET324fe25dad]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNET2a6d02a6a5, DATARMNET77ab42949f, DATARMNETd8fdde8978, DATARMNETf2958615b1, DATARMNET7b0253229f, DATARMNET5ecc30669c, DATARMNET9250714999, DATARMNET324fe25dad, DATARMNET9d574e64b1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 00104020 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [init_module, DATARMNET49c17a32bc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 00104028 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [cleanup_module, DATARMNET41e8cc085c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 00104030 size=1
// signature: undefined synchronize_rcu(void)
// callers: [cleanup_module, DATARMNET41e8cc085c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104038 size=1
// signature: undefined _printk(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00104058 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [DATARMNET2a6d02a6a5, DATARMNETd8fdde8978, DATARMNET7fa1835595, DATARMNET5ecc30669c, DATARMNET9250714999, DATARMNET9d574e64b1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00104068 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [DATARMNET2a6d02a6a5, DATARMNETd8fdde8978, DATARMNET7fa1835595, DATARMNET5ecc30669c, DATARMNET9250714999, DATARMNET9d574e64b1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104070 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [DATARMNET9f0aaf07cc, DATARMNETfec9085d8e, DATARMNET270a2369fc, DATARMNET47ed281d61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104080 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNET9f0aaf07cc, DATARMNET270a2369fc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00104090 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [DATARMNET9f0aaf07cc, DATARMNET38bb6f2b7a, DATARMNETfec9085d8e, DATARMNET270a2369fc, DATARMNET4b5170a1ef, DATARMNET47ed281d61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104098 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [DATARMNET9f0aaf07cc, DATARMNETfec9085d8e, DATARMNET270a2369fc, DATARMNET47ed281d61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001040a8 size=1
// signature: undefined init_timer_key(void)
// callers: [DATARMNET7e9995246e, DATARMNETe80a33d544]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// call_rcu @ 001040b0 size=1
// signature: undefined call_rcu(void)
// callers: [DATARMNETfec9085d8e, DATARMNET47ed281d61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void call_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 001040b8 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [DATARMNET38bb6f2b7a, DATARMNET4b5170a1ef]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __inet_lookup_established @ 001040c8 size=1
// signature: undefined __inet_lookup_established(void)
// callers: [DATARMNET31a7673e56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __inet_lookup_established(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001040d0 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [DATARMNET31a7673e56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001040d8 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [DATARMNET31a7673e56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_gen_put @ 001040e0 size=1
// signature: undefined sock_gen_put(void)
// callers: [DATARMNET31a7673e56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_gen_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __inet6_lookup_established @ 001040e8 size=1
// signature: undefined __inet6_lookup_established(void)
// callers: [DATARMNET31a7673e56]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __inet6_lookup_established(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040f0 size=1
// signature: undefined kfree(void)
// callers: [DATARMNETfcb3ce7715, DATARMNET776e08992c]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udp4_lib_lookup @ 00104110 size=1
// signature: undefined __udp4_lib_lookup(void)
// callers: [DATARMNET991df48508]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udp4_lib_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udp6_lib_lookup @ 00104118 size=1
// signature: undefined __udp6_lib_lookup(void)
// callers: [DATARMNET991df48508]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udp6_lib_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00104128 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [DATARMNET991df48508, DATARMNETfcb3ce7715]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_free @ 00104130 size=1
// signature: void sk_free(_STACK * param_1)
// callers: [DATARMNETfcb3ce7715]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sk_free(_STACK *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



