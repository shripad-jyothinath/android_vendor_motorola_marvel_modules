// Decompiled by Ghidra 12.2
// Program: rmnet_aps.ko
// Image base: 00100000

//------------------------------------------------------------
// DATARMNETcfa8d492f8 @ 00100674 size=36
// signature: undefined DATARMNETcfa8d492f8(void)
// callers: [init_module]
//------------------------------------------------------------

void DATARMNETcfa8d492f8(void)

{
  genl_register_family(&DATARMNETcdba30eca9);
  return;
}



//------------------------------------------------------------
// DATARMNETca7606cfd1 @ 0010069c size=36
// signature: undefined DATARMNETca7606cfd1(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void DATARMNETca7606cfd1(void)

{
  genl_unregister_family(&DATARMNETcdba30eca9);
  return;
}



//------------------------------------------------------------
// DATARMNET37a9efbbcb @ 001006c4 size=580
// signature: undefined DATARMNET37a9efbbcb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET37a9efbbcb(undefined8 param_1,undefined8 *param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  char *__s1;
  undefined **ppuVar7;
  undefined8 uVar8;
  long lVar9;
  undefined **ppuVar10;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (((param_2 == (undefined8 *)0x0) || (*(long *)(param_2[4] + 8) == 0)) ||
     (iVar5 = nla_memcpy(&local_50,*(long *)(param_2[4] + 8),0x14), iVar5 < 1)) {
    uVar8 = 0xffffffea;
    goto LAB_00100830;
  }
  mutex_lock(&DATARMNETd7b5a80f84);
  if (DATARMNET54b95e4416 == '\x01') {
    if ((int)local_50 - 2U < 3) {
      if ((uStack_48._4_4_ == 0) ||
         (__s1 = (char *)dev_get_by_index(&init_net), __s1 == (char *)0x0)) goto LAB_001007f8;
      iVar5 = strncmp(__s1,"rmnet_data",10);
      if (iVar5 == 0) {
        lVar9 = *(long *)(__s1 + 0xc30);
        if ((lVar9 != 0) || ((int)local_50 != 2)) {
          if (lVar9 != 0) goto LAB_001008a4;
          goto LAB_00100774;
        }
        lVar9 = kmalloc_trace(_jiffies,0xdc0,0x20);
        if (lVar9 == 0) goto LAB_00100774;
        *(long *)(lVar9 + 0x10) = lVar9 + 0x10;
        *(long *)(lVar9 + 0x18) = lVar9 + 0x10;
        *(long *)(__s1 + 0xc30) = lVar9;
LAB_001008a4:
        uVar6 = DATARMNET82d65f9ca6(lVar9 + 0x10,&local_50);
      }
      else {
LAB_00100774:
        uVar6 = 0xffffffea;
      }
      lVar9 = sp_el0;
      *(int *)(lVar9 + 0x10) = *(int *)(lVar9 + 0x10) + 1;
      lVar4 = tpidr_el1;
      piVar1 = (int *)(lVar4 + *(long *)(__s1 + 0x4d8));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar4 = *(long *)(lVar9 + 0x10) + -1;
      *(int *)(lVar9 + 0x10) = (int)lVar4;
      if ((lVar4 == 0) || (*(long *)(lVar9 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
    }
    else {
      if ((int)local_50 != 1) goto LAB_001007f8;
      DATARMNET7d98961cbe = *param_2;
      DAT_001033f8 = param_2[3];
      DAT_00103400 = param_2[4];
      DAT_001033e8 = param_2[1];
      DAT_001033f0 = param_2[2];
      DAT_00103418 = param_2[7];
      DAT_00103420 = param_2[8];
      DAT_00103408 = param_2[5];
      DAT_00103410 = param_2[6];
      ppuVar10 = (undefined **)DATARMNET7520901fb5;
      while (ppuVar10 != &DATARMNET7520901fb5) {
        ppuVar7 = ppuVar10 + -4;
        ppuVar10 = (undefined **)*ppuVar10;
        DATARMNET7fa3dd63cb(ppuVar7);
      }
      uVar6 = 0;
      DATARMNET2fe4661b82 = (undefined2)((ulong)local_50 >> 0x20);
    }
  }
  else {
LAB_001007f8:
    uVar6 = 0xffffffea;
  }
  mutex_unlock(&DATARMNETd7b5a80f84);
  local_60 = (int)local_50;
  local_58 = local_50._4_4_;
  uStack_5c = uVar6;
  uVar8 = DATARMNETbd1d5c8f28(param_2,1,2,0xc,&local_60,0xcc0);
LAB_00100830:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET82d65f9ca6 @ 00100908 size=648
// signature: undefined DATARMNET82d65f9ca6(void)
// callers: [DATARMNET37a9efbbcb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET82d65f9ca6(long *param_1,long *param_2)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  
  plVar10 = param_1;
  do {
    plVar10 = (long *)*plVar10;
    if (plVar10 == param_1) {
      if ((int)*param_2 == 3) {
        return 0;
      }
      goto LAB_00100a14;
    }
  } while (*(int *)((long)plVar10 + 0x24) != *(int *)((long)param_2 + 4));
  if ((int)*param_2 == 3) {
    if (plVar10 == (long *)0x10) {
      return 0;
    }
    DATARMNET7fa3dd63cb();
  }
  else {
    if (((int)*param_2 == 2) && (plVar10 != (long *)0x10)) {
      DATARMNET7fa3dd63cb();
    }
    else if (plVar10 != (long *)0x10) {
      uVar9 = 0x9b6d0000;
      _raw_spin_lock_bh(&DATARMNET33bd4139f4);
      uVar3 = *(uint *)(param_2 + 2);
      lVar7 = *param_2;
      lVar2 = param_2[1];
      *(uint *)(plVar10 + 6) = uVar3;
      uVar3 = uVar3 >> 8 & 0xff;
      plVar10[4] = lVar7;
      plVar10[5] = lVar2;
      *(bool *)(plVar10 + 0xb) = uVar3 != 0;
      *(bool *)((long)plVar10 + 0x59) = *(char *)((long)plVar10 + 0x32) != '\0';
      if ((ulong)*(byte *)(plVar10 + 6) < 5) {
        uVar9 = *(byte *)((long)&DATARMNET9628311a6b + (ulong)*(byte *)(plVar10 + 6)) | 0x9b6d0000;
      }
      uVar4 = uVar9 | 0x100;
      if (uVar3 == 0) {
        uVar4 = uVar9;
      }
      uVar3 = uVar4 | 0x200;
      if (*(char *)((long)plVar10 + 0x32) == '\0') {
        uVar3 = uVar4;
      }
      *(uint *)(plVar10 + 8) = uVar3;
      _raw_spin_unlock_bh(&DATARMNET33bd4139f4);
      return 0;
    }
LAB_00100a14:
    if (0xfe < DATARMNETfef55eaf9a) {
      return 0xffffffea;
    }
    lVar7 = kmalloc_trace(___list_add_valid,0xdc0,0x70);
    if (lVar7 == 0) {
      return 0xfffffff4;
    }
    uVar3 = *(uint *)(param_2 + 2);
    lVar2 = *param_2;
    lVar11 = param_2[1];
    uVar4 = uVar3 >> 8 & 0xff;
    uVar5 = uVar3 >> 0x10 & 0xff;
    *(uint *)(lVar7 + 0x40) = uVar3;
    *(long *)(lVar7 + 0x30) = lVar2;
    *(long *)(lVar7 + 0x38) = lVar11;
    uVar9 = 0x9b6d0000;
    *(bool *)(lVar7 + 0x68) = uVar4 != 0;
    *(bool *)(lVar7 + 0x69) = uVar5 != 0;
    if (((ulong)uVar3 & 0xff) < 5) {
      uVar9 = *(byte *)((long)&DATARMNET9628311a6b + ((ulong)uVar3 & 0xff)) | 0x9b6d0000;
    }
    uVar3 = uVar9 | 0x100;
    if (uVar4 == 0) {
      uVar3 = uVar9;
    }
    uVar9 = uVar3 | 0x200;
    if (uVar5 == 0) {
      uVar9 = uVar3;
    }
    lVar2 = param_2[1];
    *(uint *)(lVar7 + 0x50) = uVar9;
    if ((int)lVar2 != 0) {
      uVar3 = (int)lVar2 * 0xfa;
      *(uint *)(lVar7 + 0x54) = uVar3;
      *(ulong *)(lVar7 + 0x58) = _jiffies + (ulong)uVar3;
    }
    lVar11 = *param_1;
    lVar2 = lVar7 + 0x10;
    uVar8 = __list_add_valid(lVar2,param_1,lVar11);
    if ((uVar8 & 1) != 0) {
      *(long *)(lVar7 + 0x10) = lVar11;
      *(long **)(lVar7 + 0x18) = param_1;
      *param_1 = lVar2;
      *(long *)(lVar11 + 8) = lVar2;
    }
    puVar6 = DATARMNET7520901fb5;
    puVar1 = (undefined *)(lVar7 + 0x20);
    uVar8 = __list_add_valid(puVar1,&DATARMNET7520901fb5,DATARMNET7520901fb5);
    if ((uVar8 & 1) != 0) {
      *(undefined **)(puVar6 + 8) = puVar1;
      *(undefined **)(lVar7 + 0x20) = puVar6;
      *(undefined ***)(lVar7 + 0x28) = &DATARMNET7520901fb5;
      DATARMNET7520901fb5 = puVar1;
    }
    DATARMNETfef55eaf9a = DATARMNETfef55eaf9a + 1;
    if ((*(long *)(lVar7 + 0x58) != 0) &&
       ((DATARMNETd21629e047._8_8_ == 0 ||
        (*(long *)(lVar7 + 0x58) - DATARMNETd21629e047._16_8_ < 0)))) {
      mod_timer(DATARMNETd21629e047);
    }
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNETbd1d5c8f28 @ 00100b90 size=268
// signature: undefined DATARMNETbd1d5c8f28(void)
// callers: [cleanup_module, DATARMNET5ff569bc33, DATARMNET37a9efbbcb, DATARMNET998f6cbce7, DATARMNET1998d09852, DATARMNETd1a02b8188, DATARMNETae6b282c61, DATARMNET568dffe281]
//------------------------------------------------------------

undefined8
DATARMNETbd1d5c8f28(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (param_1 == (int *)0x0) {
    uVar4 = 0xffffffea;
  }
  else {
    lVar2 = __alloc_skb((param_4 + 7U & 0xfffffffc) + 0x14,param_6,0,0xffffffff);
    if (lVar2 != 0) {
      lVar3 = genlmsg_put(lVar2,0,*param_1 + 1,&DATARMNETcdba30eca9,0,param_2);
      if ((lVar3 == 0) || (iVar1 = nla_put(lVar2,param_3,param_4,param_5), iVar1 != 0)) {
        kfree_skb_reason(lVar2,1);
      }
      else {
        *(int *)(lVar3 + -0x14) =
             (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
        iVar1 = netlink_unicast(*(undefined8 *)(*(long *)(param_1 + 10) + 0x118),lVar2,param_1[1],
                                0x40);
        if (-1 < iVar1) {
          return 0;
        }
      }
    }
    uVar4 = 0xfffffff2;
  }
  return uVar4;
}



//------------------------------------------------------------
// DATARMNETae6b282c61 @ 00100ca0 size=508
// signature: undefined DATARMNETae6b282c61(void)
// callers: []
//------------------------------------------------------------

void DATARMNETae6b282c61(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  char *__s1;
  undefined8 uVar7;
  long lVar8;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
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
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
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
  uStack_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  if (((param_2 == 0) || (lVar8 = *(long *)(*(long *)(param_2 + 0x20) + 0x28), lVar8 == 0)) ||
     (iVar5 = nla_memcpy(&local_b8,lVar8,0x80), iVar5 < 1)) {
    uVar7 = 0xffffffea;
    goto LAB_00100de8;
  }
  mutex_lock(&DATARMNETd7b5a80f84);
  if (((DATARMNET54b95e4416 == '\x01') && ((int)local_b0 != 0)) &&
     (__s1 = (char *)dev_get_by_index(&init_net), __s1 != (char *)0x0)) {
    iVar5 = strncmp(__s1,"rmnet_data",10);
    if (iVar5 == 0) {
      if (((int)local_b8 == 6) && (*(long *)(__s1 + 0xc30) != 0)) {
        uVar6 = DATARMNET9e18f3d501(*(long *)(__s1 + 0xc30) + 0x10,&local_b8);
      }
      else {
        uVar6 = 0xffffffea;
      }
      lVar8 = sp_el0;
      *(int *)(lVar8 + 0x10) = *(int *)(lVar8 + 0x10) + 1;
      lVar4 = tpidr_el1;
      piVar1 = (int *)(lVar4 + *(long *)(__s1 + 0x4d8));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar4 = *(long *)(lVar8 + 0x10) + -1;
      *(int *)(lVar8 + 0x10) = (int)lVar4;
      if (lVar4 != 0) {
        lVar8 = *(long *)(lVar8 + 0x10);
        goto joined_r0x00100e84;
      }
    }
    else {
      lVar8 = sp_el0;
      *(int *)(lVar8 + 0x10) = *(int *)(lVar8 + 0x10) + 1;
      lVar4 = tpidr_el1;
      piVar1 = (int *)(lVar4 + *(long *)(__s1 + 0x4d8));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar4 = *(long *)(lVar8 + 0x10) + -1;
      *(int *)(lVar8 + 0x10) = (int)lVar4;
      if (lVar4 == 0) {
        uVar6 = 0xffffffea;
      }
      else {
        lVar8 = *(long *)(lVar8 + 0x10);
        uVar6 = 0xffffffea;
joined_r0x00100e84:
        if (lVar8 != 0) goto LAB_00100db4;
      }
    }
    preempt_schedule_notrace();
  }
  else {
    uVar6 = 0xffffffea;
  }
LAB_00100db4:
  mutex_unlock(&DATARMNETd7b5a80f84);
  local_c8 = (int)local_b8;
  local_c0 = local_b8._4_4_;
  uStack_c4 = uVar6;
  uVar7 = DATARMNETbd1d5c8f28(param_2,3,6,0xc,&local_c8,0xcc0);
LAB_00100de8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET9e18f3d501 @ 00100e9c size=244
// signature: undefined DATARMNET9e18f3d501(void)
// callers: [DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DATARMNET9e18f3d501(long *param_1,int *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  byte bVar6;
  long *plVar7;
  
  plVar7 = param_1;
  do {
    plVar7 = (long *)*plVar7;
    if (plVar7 == param_1) goto LAB_00100eec;
  } while (*(int *)((long)plVar7 + 0x24) != param_2[1]);
  if (((plVar7 == (long *)0x10) || (*param_2 != 6)) || (plVar7[7] != 0)) {
LAB_00100eec:
    uVar4 = 0xffffffea;
  }
  else {
    lVar5 = kmalloc_trace(_preempt_schedule_notrace,0xdc0,0x90);
    if (lVar5 == 0) {
      uVar4 = 0xfffffff4;
    }
    else {
      uVar1 = *(undefined8 *)(param_2 + 0x1a);
      uVar4 = *(undefined8 *)(param_2 + 0x1c);
      uVar2 = *(undefined8 *)(param_2 + 0x1e);
      *(undefined8 *)(lVar5 + 0x70) = *(undefined8 *)(param_2 + 0x18);
      *(undefined8 *)(lVar5 + 0x78) = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x10);
      uVar3 = *(undefined8 *)(param_2 + 0x12);
      *(undefined8 *)(lVar5 + 0x80) = uVar4;
      *(undefined8 *)(lVar5 + 0x88) = uVar2;
      uVar4 = *(undefined8 *)(param_2 + 0x14);
      uVar2 = *(undefined8 *)(param_2 + 0x16);
      *(undefined8 *)(lVar5 + 0x50) = uVar1;
      *(undefined8 *)(lVar5 + 0x58) = uVar3;
      uVar1 = *(undefined8 *)(param_2 + 8);
      uVar3 = *(undefined8 *)(param_2 + 10);
      *(undefined8 *)(lVar5 + 0x60) = uVar4;
      *(undefined8 *)(lVar5 + 0x68) = uVar2;
      uVar4 = *(undefined8 *)(param_2 + 0xc);
      uVar2 = *(undefined8 *)(param_2 + 0xe);
      *(undefined8 *)(lVar5 + 0x30) = uVar1;
      *(undefined8 *)(lVar5 + 0x38) = uVar3;
      uVar1 = *(undefined8 *)param_2;
      uVar3 = *(undefined8 *)(param_2 + 2);
      *(undefined8 *)(lVar5 + 0x40) = uVar4;
      *(undefined8 *)(lVar5 + 0x48) = uVar2;
      uVar4 = *(undefined8 *)(param_2 + 4);
      uVar2 = *(undefined8 *)(param_2 + 6);
      *(undefined8 *)(lVar5 + 0x10) = uVar1;
      *(undefined8 *)(lVar5 + 0x18) = uVar3;
      *(undefined8 *)(lVar5 + 0x20) = uVar4;
      *(undefined8 *)(lVar5 + 0x28) = uVar2;
      if (*(byte *)(lVar5 + 0x48) != 0) {
        bVar6 = *(byte *)(lVar5 + 0x49);
        if (bVar6 == 0) {
          bVar6 = 0xff;
          *(undefined1 *)(lVar5 + 0x49) = 0xff;
        }
        *(byte *)(lVar5 + 0x48) = *(byte *)(lVar5 + 0x48) & bVar6;
      }
      plVar7[7] = lVar5;
      uVar4 = 0;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// DATARMNET1998d09852 @ 00100f94 size=372
// signature: undefined DATARMNET1998d09852(void)
// callers: []
//------------------------------------------------------------

void DATARMNET1998d09852(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  char *__s1;
  undefined8 uVar6;
  long lVar7;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined4 local_64;
  ulong local_60 [2];
  ulong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_60[1] = 0;
  local_50 = 0;
  local_60[0] = 0;
  if (param_2 != 0) {
    lVar7 = *(long *)(*(long *)(param_2 + 0x20) + 0x18);
    if ((lVar7 != 0) && (iVar5 = nla_memcpy(local_60,lVar7,0x38), 0 < iVar5)) {
      if (((int)local_50 != 0) &&
         (lVar7 = (local_50 & 0xffffffff) * 1000000, DATARMNETe7a1ab1dab != lVar7)) {
        DATARMNETe7a1ab1dab = lVar7;
      }
      __s1 = (char *)dev_get_by_index(&init_net,local_60[0] & 0xffffffff);
      if (__s1 != (char *)0x0) {
        iVar5 = strncmp(__s1,"rmnet_data",10);
        if (iVar5 == 0) {
          __s1[0xc28] = (int)local_50 != 0;
        }
        lVar7 = sp_el0;
        *(int *)(lVar7 + 0x10) = *(int *)(lVar7 + 0x10) + 1;
        lVar4 = tpidr_el1;
        piVar1 = (int *)(lVar4 + *(long *)(__s1 + 0x4d8));
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar4 = *(long *)(lVar7 + 0x10) + -1;
        *(int *)(lVar7 + 0x10) = (int)lVar4;
        if ((lVar4 == 0) || (*(long *)(lVar7 + 0x10) == 0)) {
          preempt_schedule_notrace();
        }
      }
      local_64 = 0;
      local_6c = 0;
      local_74 = 0;
      local_7c = 0;
      local_80 = (undefined4)local_60[0];
      uVar6 = DATARMNETbd1d5c8f28(param_2,2,4,0x20,&local_80,0xcc0);
      goto LAB_001010d4;
    }
  }
  uVar6 = 0xffffffea;
LAB_001010d4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET5ff569bc33 @ 0010110c size=532
// signature: undefined DATARMNET5ff569bc33(void)
// callers: []
//------------------------------------------------------------

void DATARMNET5ff569bc33(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  ulong uVar6;
  undefined **ppuVar7;
  long lVar8;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  char local_4d;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  long local_28;
  
  lVar8 = sp_el0;
  local_28 = *(long *)(lVar8 + 0x638);
  local_34 = 0;
  local_3c = 0;
  local_44 = 0;
  local_4c = 0;
  if ((((0x2f < *(uint *)(param_1 + 0x70)) && (lVar8 = *(long *)(param_1 + 0xe0), lVar8 != 0)) &&
      (*(char *)(lVar8 + 4) == '\"')) &&
     (((*(byte *)(lVar8 + 5) & 3) == 1 && (*(byte *)(lVar8 + 0xf) < 9)))) {
    _raw_spin_lock_bh(&DATARMNETc3c07e6644);
    ppuVar7 = &DATARMNET5e3c62e3a4;
    do {
      ppuVar7 = (undefined **)*ppuVar7;
      if (ppuVar7 == &DATARMNET5e3c62e3a4) {
        _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
        goto LAB_001012f0;
      }
    } while (*(int *)(ppuVar7 + 0xb) != *(int *)(lVar8 + 8));
    uVar6 = __list_del_entry_valid(ppuVar7);
    if ((uVar6 & 1) != 0) {
      puVar1 = *ppuVar7;
      plVar2 = (long *)ppuVar7[1];
      *(long **)(puVar1 + 8) = plVar2;
      *plVar2 = (long)puVar1;
    }
    *ppuVar7 = &DAT_dead000000000100;
    ppuVar7[1] = (undefined *)0xdead000000000122;
    DATARMNETb666ba3e85 = DATARMNETb666ba3e85 + -1;
    _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
    if (ppuVar7 != (undefined **)0x0) {
      local_50 = *(undefined1 *)(lVar8 + 1);
      local_4f = *(undefined1 *)(lVar8 + 0xd);
      local_4e = *(undefined1 *)(lVar8 + 0xe);
      local_4d = *(char *)(lVar8 + 0xf);
      if (local_4d != '\0') {
        uVar3 = (*(uint *)(lVar8 + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)(lVar8 + 0x10) & 0xff00ff) << 8;
        uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
        local_4c = CONCAT44(local_4c._4_4_,uVar3);
        if (((local_4d != '\x01') &&
            (uVar4 = (*(uint *)(lVar8 + 0x14) & 0xff00ff00) >> 8 |
                     (*(uint *)(lVar8 + 0x14) & 0xff00ff) << 8,
            local_4c = CONCAT44(uVar4 >> 0x10 | uVar4 << 0x10,uVar3), local_4d != '\x02')) &&
           ((uVar3 = (*(uint *)(lVar8 + 0x18) & 0xff00ff00) >> 8 |
                     (*(uint *)(lVar8 + 0x18) & 0xff00ff) << 8,
            uVar3 = uVar3 >> 0x10 | uVar3 << 0x10, local_44 = CONCAT44(local_44._4_4_,uVar3),
            local_4d != '\x03' &&
            (uVar4 = (*(uint *)(lVar8 + 0x1c) & 0xff00ff00) >> 8 |
                     (*(uint *)(lVar8 + 0x1c) & 0xff00ff) << 8,
            local_44 = CONCAT44(uVar4 >> 0x10 | uVar4 << 0x10,uVar3), local_4d != '\x04')))) {
          uVar3 = (*(uint *)(lVar8 + 0x20) & 0xff00ff00) >> 8 |
                  (*(uint *)(lVar8 + 0x20) & 0xff00ff) << 8;
          uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
          local_3c = CONCAT44(local_3c._4_4_,uVar3);
          if ((((local_4d != '\x05') &&
               (uVar4 = (*(uint *)(lVar8 + 0x24) & 0xff00ff00) >> 8 |
                        (*(uint *)(lVar8 + 0x24) & 0xff00ff) << 8,
               local_3c = CONCAT44(uVar4 >> 0x10 | uVar4 << 0x10,uVar3), local_4d != '\x06')) &&
              (uVar3 = (*(uint *)(lVar8 + 0x28) & 0xff00ff00) >> 8 |
                       (*(uint *)(lVar8 + 0x28) & 0xff00ff) << 8,
              uVar3 = uVar3 >> 0x10 | uVar3 << 0x10, local_34 = CONCAT44(local_34._4_4_,uVar3),
              local_4d != '\a')) &&
             (uVar4 = (*(uint *)(lVar8 + 0x2c) & 0xff00ff00) >> 8 |
                      (*(uint *)(lVar8 + 0x2c) & 0xff00ff) << 8,
             local_34 = CONCAT44(uVar4 >> 0x10 | uVar4 << 0x10,uVar3), local_4d != '\b')) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x101320);
            (*pcVar5)();
          }
        }
      }
      DATARMNETbd1d5c8f28(ppuVar7 + 2,4,7,0x24,&local_50,0xa20);
      kfree(ppuVar7);
    }
  }
LAB_001012f0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET568dffe281 @ 00101324 size=604
// signature: undefined DATARMNET568dffe281(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET568dffe281(undefined8 param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  undefined8 uVar14;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if (param_2 != (undefined8 *)0x0) {
    if ((*(long *)(param_2[4] + 0x38) != 0) &&
       (iVar7 = nla_memcpy(&local_80,*(long *)(param_2[4] + 0x38),0x24), 0 < iVar7)) {
      _raw_spin_lock_bh(&DATARMNETc3c07e6644);
      if (((DATARMNET5500f4ed98 & 1) == 0) && (DATARMNETb666ba3e85 < 5)) {
        uVar5 = local_80._1_1_;
        uVar1 = (undefined1)local_80;
        cVar6 = local_80._2_1_;
        lVar9 = __alloc_skb(0x30,0xa20,0,0xffffffff);
        if (lVar9 != 0) {
          *(undefined2 *)(lVar9 + 0xb4) = 0xf900;
          puVar10 = (undefined1 *)skb_put(lVar9,0x30);
          if (cVar6 != '\0') {
            uVar1 = 0xff;
          }
          *(undefined8 *)(puVar10 + 4) = 0;
          *puVar10 = 0x80;
          *(undefined8 *)(puVar10 + 0xc) = 0;
          *(undefined8 *)(puVar10 + 0x14) = 0;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
          *(undefined8 *)(puVar10 + 0x24) = 0;
          *(undefined4 *)(puVar10 + 0x2c) = 0;
          puVar10[1] = uVar1;
          *(undefined2 *)(puVar10 + 2) = 0x2c00;
          puVar10[4] = 0x22;
          uVar8 = rmnet_qmap_next_txid();
          uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
          uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
          puVar10[0xd] = uVar5;
          puVar10[0xc] = 1;
          *(uint *)(puVar10 + 8) = uVar8;
          puVar10[0xe] = cVar6 != '\0';
          iVar7 = rmnet_qmap_send(lVar9,0xff,0);
          if ((iVar7 == 0) &&
             (puVar12 = (undefined8 *)kmalloc_trace(___list_add_valid,0xb20,0x68),
             puVar12 != (undefined8 *)0x0)) {
            uVar11 = param_2[6];
            uVar2 = param_2[7];
            *(uint *)(puVar12 + 0xb) = uVar8;
            uVar14 = param_2[8];
            puVar12[8] = uVar11;
            puVar12[9] = uVar2;
            uVar11 = param_2[2];
            uVar3 = param_2[3];
            puVar12[10] = uVar14;
            uVar2 = param_2[4];
            uVar14 = param_2[5];
            puVar12[4] = uVar11;
            puVar12[5] = uVar3;
            uVar11 = *param_2;
            uVar3 = param_2[1];
            puVar12[6] = uVar2;
            puVar12[7] = uVar14;
            puVar12[2] = uVar11;
            puVar12[3] = uVar3;
            lVar9 = _jiffies + 0xfa;
            puVar12[0xc] = lVar9;
            puVar4 = DATARMNET5e3c62e3a4;
            if ((undefined **)DATARMNET5e3c62e3a4 != &DATARMNET5e3c62e3a4) {
              lVar9 = 0;
            }
            uVar13 = __list_add_valid(puVar12,&DATARMNET5e3c62e3a4,DATARMNET5e3c62e3a4);
            if ((uVar13 & 1) != 0) {
              *(undefined8 **)(puVar4 + 8) = puVar12;
              *puVar12 = puVar4;
              puVar12[1] = &DATARMNET5e3c62e3a4;
              DATARMNET5e3c62e3a4 = (undefined *)puVar12;
            }
            DATARMNETb666ba3e85 = DATARMNETb666ba3e85 + 1;
            _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
            if (lVar9 != 0) {
              mod_timer(DATARMNET2d8efce4f0,lVar9);
            }
            uVar11 = 0;
            goto LAB_0010148c;
          }
        }
      }
      _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
      local_80._0_4_ = (uint)(uint3)local_80;
      uVar11 = DATARMNETbd1d5c8f28(param_2,4,7,0x24,&local_80,0xcc0);
      goto LAB_0010148c;
    }
  }
  uVar11 = 0xffffffea;
LAB_0010148c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET7fa3dd63cb @ 00101580 size=180
// signature: undefined DATARMNET7fa3dd63cb(void)
// callers: [cleanup_module, DATARMNET37a9efbbcb, DATARMNET82d65f9ca6, DATARMNET998f6cbce7, DATARMNETd1a02b8188]
//------------------------------------------------------------

void DATARMNET7fa3dd63cb(long param_1)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  uVar3 = __list_del_entry_valid(param_1 + 0x10);
  if ((uVar3 & 1) != 0) {
    lVar4 = *(long *)(param_1 + 0x10);
    plVar1 = *(long **)(param_1 + 0x18);
    *(long **)(lVar4 + 8) = plVar1;
    *plVar1 = lVar4;
  }
  *(undefined8 *)(param_1 + 0x18) = 0xdead000000000122;
  uVar3 = __list_del_entry_valid(param_1 + 0x20);
  if ((uVar3 & 1) != 0) {
    lVar4 = *(long *)(param_1 + 0x20);
    plVar1 = *(long **)(param_1 + 0x28);
    *(long **)(lVar4 + 8) = plVar1;
    *plVar1 = lVar4;
  }
  iVar2 = DATARMNETfef55eaf9a;
  *(undefined1 **)(param_1 + 0x20) = &DAT_dead000000000100;
  *(undefined8 *)(param_1 + 0x28) = 0xdead000000000122;
  if ((iVar2 == 0) || (DATARMNETfef55eaf9a = iVar2 + -1, DATARMNETfef55eaf9a == 0)) {
    del_timer(DATARMNETd21629e047);
    lVar4 = *(long *)(param_1 + 0x48);
  }
  else {
    lVar4 = *(long *)(param_1 + 0x48);
  }
  if (lVar4 != 0) {
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  if (param_1 != 0) {
    kvfree_call_rcu(param_1,0);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETf844db79d9 @ 00101638 size=48
// signature: undefined DATARMNETf844db79d9(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETf844db79d9(void)

{
  queue_work_on(0x20,_system_wq,&DATARMNET8e3aef0760);
  return;
}



//------------------------------------------------------------
// DATARMNETd1a02b8188 @ 0010166c size=360
// signature: undefined DATARMNETd1a02b8188(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETd1a02b8188(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined *puVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  puVar3 = _jiffies;
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  mutex_lock(&DATARMNETd7b5a80f84);
  if (DATARMNET54b95e4416 == '\x01') {
    _raw_spin_lock_bh(&DATARMNET33bd4139f4);
    if ((undefined **)DATARMNET7520901fb5 != &DATARMNET7520901fb5) {
      ppuVar5 = (undefined **)DATARMNET7520901fb5;
      puVar8 = puVar3;
      do {
        puVar6 = ppuVar5[7];
        ppuVar9 = (undefined **)*ppuVar5;
        puVar7 = puVar8;
        if (puVar6 != (undefined *)0x0) {
          if ((long)puVar3 - (long)puVar6 < 0) {
            puVar7 = puVar6;
            if (-1 < (long)puVar6 - (long)puVar8 && puVar8 != puVar3) {
              puVar7 = puVar8;
            }
          }
          else {
            uVar1 = *(undefined4 *)((long)ppuVar5 + 0x14);
            DATARMNET7fa3dd63cb(ppuVar5 + -4);
            if (DATARMNET7d98961cbe._4_4_ != 0) {
              local_68 = 0x100000005;
              local_60 = uVar1;
              iVar4 = DATARMNETbd1d5c8f28(&DATARMNET7d98961cbe,1,2,0xc,&local_68,0xa20);
              if (iVar4 != 0) {
                DATARMNET7d98961cbe._4_4_ = 0;
              }
            }
          }
        }
        ppuVar5 = ppuVar9;
        puVar8 = puVar7;
      } while (ppuVar9 != &DATARMNET7520901fb5);
      if (puVar7 != puVar3) {
        mod_timer(DATARMNETd21629e047,puVar7);
      }
    }
    _raw_spin_unlock_bh(&DATARMNET33bd4139f4);
  }
  mutex_unlock(&DATARMNETd7b5a80f84);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET8871996254 @ 001017d8 size=244
// signature: undefined DATARMNET8871996254(void)
// callers: []
//------------------------------------------------------------

void DATARMNET8871996254(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_1,10,&local_2c);
  if (iVar2 == 0) {
    _raw_spin_lock_bh(&DATARMNET86e81617f0);
    if (local_2c == 0) {
      DATARMNET6736d5e29d = 0;
      rmnet_module_hook_unregister_no_sync(DATARMNETbdf157f06a,2);
    }
    else {
      DATARMNET6736d5e29d = (ulong)(uint)(local_2c * 1000) * 1000000;
      DATARMNETd4b2cd928c = ktime_get_coarse_with_offset(1);
      rmnet_module_hook_register(DATARMNETbdf157f06a,2);
    }
    _raw_spin_unlock_bh(&DATARMNET86e81617f0);
    uVar3 = param_set_uint(param_1,param_2);
  }
  else {
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET71e03e7287 @ 001018d0 size=72
// signature: undefined DATARMNET71e03e7287(void)
// callers: []
//------------------------------------------------------------

void DATARMNET71e03e7287(void)

{
  _raw_spin_lock_bh(&DATARMNET86e81617f0);
  DATARMNETd4b2cd928c = ktime_get_coarse_with_offset(1);
  _raw_spin_unlock_bh(&DATARMNET86e81617f0);
  return;
}



//------------------------------------------------------------
// DATARMNETfb7a2ce025 @ 0010191c size=884
// signature: undefined DATARMNETfb7a2ce025(void)
// callers: []
//------------------------------------------------------------

void DATARMNETfb7a2ce025(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  long lVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  byte *pbVar9;
  uint *puVar10;
  ushort *puVar11;
  long *plVar12;
  char cVar13;
  byte local_ac [4];
  byte local_a8 [4];
  ushort local_a4 [2];
  undefined1 local_a0;
  char cStack_9f;
  char cStack_9e;
  byte bStack_9d;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  ushort uStack_7c;
  ushort uStack_7a;
  undefined8 local_78;
  ulong local_70 [6];
  
  lVar8 = sp_el0;
  local_70[5] = *(long *)(lVar8 + 0x638);
  local_80 = 0;
  uStack_7c = 0;
  uStack_7a = 0;
  local_78 = 0;
  local_90 = 0;
  uStack_8c = 0;
  local_88 = 0;
  uStack_84 = 0;
  local_a0 = 0;
  cStack_9f = '\0';
  cStack_9e = '\0';
  bStack_9d = 0;
  uStack_9c = 0;
  local_98 = 0;
  uStack_94 = 0;
  if (param_1 == 0 && param_2 == 0) goto LAB_00101c20;
  _raw_spin_lock_bh(&DATARMNET86e81617f0);
  if ((DATARMNET6736d5e29d != 0) &&
     (lVar8 = ktime_get_coarse_with_offset(1), DATARMNET6736d5e29d < lVar8 - DATARMNETd4b2cd928c)) {
    if (param_1 == 0) {
      if ((param_2 != 0) && (iVar7 = DATARMNET481989429b(param_2,&local_a0), iVar7 == 0)) {
        cVar6 = cStack_9f;
        cVar13 = cStack_9e;
        goto LAB_00101ba8;
      }
    }
    else {
      plVar12 = *(long **)(param_1 + 0x10);
      if (((plVar12 != (long *)(param_1 + 0x10)) && (plVar12 != (long *)0x0)) &&
         (pbVar9 = (byte *)(((plVar12[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                           (ulong)*(uint *)((long)plVar12 + 0x1c)), pbVar9 != (byte *)0x0)) {
        bVar2 = *pbVar9 & 0xf0;
        if (bVar2 == 0x60) {
          local_70[3] = 0;
          local_70[4] = 0;
          local_70[1] = 0;
          local_70[2] = 0;
          local_70[0] = 0;
          local_a4[0] = 0;
          local_ac[0] = 0;
          puVar10 = (uint *)rmnet_frag_header_ptr(param_1,0,0x28,local_70);
          if (puVar10 != (uint *)0x0) {
            local_a8[0] = *(byte *)((long)puVar10 + 6);
            iVar7 = rmnet_frag_ipv6_skip_exthdr(param_1,0x28,local_a8,local_a4,local_ac);
            if (-1 < iVar7) {
              cVar6 = local_a4[0] != 0 || (local_ac[0] & 1) != 0;
              if ((bool)cVar6) {
                cStack_9e = (local_a4[0] & 0xf8ff) == 0;
                cStack_9f = '\x01';
              }
              cVar13 = (bool)cVar6 && (local_a4[0] & 0xf8ff) == 0;
              local_a0 = 6;
              uStack_94 = (undefined4)*(undefined8 *)(puVar10 + 4);
              local_90 = (undefined4)((ulong)*(undefined8 *)(puVar10 + 4) >> 0x20);
              uStack_9c = (undefined4)*(undefined8 *)(puVar10 + 2);
              local_98 = (undefined4)((ulong)*(undefined8 *)(puVar10 + 2) >> 0x20);
              bStack_9d = local_a8[0];
              uStack_8c = (undefined4)*(undefined8 *)(puVar10 + 6);
              local_88 = (undefined4)((ulong)*(undefined8 *)(puVar10 + 6) >> 0x20);
              uStack_84 = (undefined4)*(undefined8 *)(puVar10 + 8);
              local_80 = (undefined4)((ulong)*(undefined8 *)(puVar10 + 8) >> 0x20);
              uVar1 = (*puVar10 & 0xff000f00) >> 8;
              local_78 = CONCAT44(CONCAT31(local_78._5_3_,
                                           (char)(((*puVar10 & 0xf00f) >> 8 | (*puVar10 & 0xf) << 8)
                                                 >> 4)),
                                  (uVar1 | (*puVar10 & 0xff0000) << 8) >> 0x10 | uVar1 << 0x10);
              goto LAB_00101b50;
            }
          }
        }
        else if (bVar2 == 0x40) {
          local_70[2] = local_70[2] & 0xffffffff00000000;
          local_70[0] = 0;
          local_70[1] = 0;
          pbVar9 = (byte *)rmnet_frag_header_ptr(param_1,0,0x14,local_70);
          if ((pbVar9 != (byte *)0x0) && (bVar2 = *pbVar9, 4 < (bVar2 & 0xf))) {
            uVar3 = *(ushort *)(pbVar9 + 6);
            cVar6 = (uVar3 & 0xff3f) != 0;
            if ((bool)cVar6) {
              cStack_9e = (uVar3 & 0xff1f) == 0;
              cStack_9f = '\x01';
              bVar2 = *pbVar9;
            }
            cVar13 = (bool)cVar6 && (uVar3 & 0xff1f) == 0;
            uStack_9c = *(undefined4 *)(pbVar9 + 0xc);
            uStack_8c = *(undefined4 *)(pbVar9 + 0x10);
            bStack_9d = pbVar9[9];
            iVar7 = (bVar2 & 0xf) << 2;
            local_a0 = 4;
            local_78._0_5_ = CONCAT14(pbVar9[1],(undefined4)local_78);
LAB_00101b50:
            if (((bool)cVar6 == false) || ((bool)cVar13 != false)) {
              if ((bStack_9d == 0x11) || (bStack_9d == 6)) {
                local_70[0] = local_70[0] & 0xffffffff00000000;
                puVar11 = (ushort *)rmnet_frag_header_ptr(param_1,iVar7,4,local_70);
                if (puVar11 == (ushort *)0x0) goto LAB_00101c14;
                uStack_7c = *puVar11 >> 8 | *puVar11 << 8;
                uStack_7a = puVar11[1] >> 8 | puVar11[1] << 8;
              }
            }
            else {
              cVar6 = '\x01';
            }
LAB_00101ba8:
            if ((cVar6 == '\0') || (cVar13 != '\0')) {
              if (10 < DATARMNET04583f0705) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101c94);
                (*pcVar5)();
              }
              if ((0x230 < (ulong)DATARMNET04583f0705 * 0x38) || (DATARMNET04583f0705 == 10)) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(1,0x101c98);
                (*pcVar5)();
              }
              lVar4 = (ulong)DATARMNET04583f0705 * 0x38;
              uVar1 = 0;
              if (DATARMNET04583f0705 < 9) {
                uVar1 = DATARMNET04583f0705 + 1;
              }
              *(undefined8 *)(DATARMNETeb47903253 + lVar4 + 0x30) = local_78;
              DATARMNET04583f0705 = uVar1;
              *(ulong *)(DATARMNETeb47903253 + lVar4 + 0x20) = CONCAT44(uStack_84,local_88);
              *(ulong *)(DATARMNETeb47903253 + lVar4 + 0x28) =
                   CONCAT26(uStack_7a,CONCAT24(uStack_7c,local_80));
              *(long *)(DATARMNETeb47903253 + lVar4) = lVar8;
              *(ulong *)(DATARMNETeb47903253 + lVar4 + 8) =
                   CONCAT44(uStack_9c,
                            CONCAT13(bStack_9d,CONCAT12(cStack_9e,CONCAT11(cStack_9f,local_a0))));
              *(ulong *)(DATARMNETeb47903253 + lVar4 + 0x10) = CONCAT44(uStack_94,local_98);
              *(ulong *)(DATARMNETeb47903253 + lVar4 + 0x18) = CONCAT44(uStack_8c,local_90);
            }
          }
        }
      }
    }
  }
LAB_00101c14:
  _raw_spin_unlock_bh(&DATARMNET86e81617f0);
LAB_00101c20:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_70[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET481989429b @ 00101c98 size=692
// signature: undefined DATARMNET481989429b(void)
// callers: [DATARMNETe0c7b9d5a4, DATARMNETfb7a2ce025]
//------------------------------------------------------------

void DATARMNET481989429b(long param_1,undefined1 *param_2)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  byte bVar7;
  ulong *puVar8;
  byte local_68 [4];
  ushort local_64 [2];
  ulong local_60 [6];
  
  lVar2 = sp_el0;
  local_60[5] = *(long *)(lVar2 + 0x638);
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    local_60[3] = 0;
    local_60[4] = 0;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[0] = 0;
    local_64[0] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x28) {
      if (param_1 != 0) {
        puVar8 = local_60;
        iVar4 = skb_copy_bits(param_1,0,local_60,0x28);
        if (-1 < iVar4) goto LAB_00101d78;
      }
    }
    else {
      puVar8 = *(ulong **)(param_1 + 0xe0);
      if (puVar8 != (ulong *)0x0) {
LAB_00101d78:
        local_68[0] = *(byte *)((long)puVar8 + 6);
        uVar3 = ipv6_skip_exthdr(param_1,0x28,local_68,local_64);
        if ((int)uVar3 < 0) {
          uVar5 = 0xfffffff2;
          goto LAB_00101ed4;
        }
        uVar6 = (ulong)uVar3;
        if (local_64[0] != 0) {
          param_2[1] = 1;
          param_2[2] = (local_64[0] & 0xf8ff) == 0;
        }
        *param_2 = 6;
        param_2[3] = local_68[0];
        uVar1 = puVar8[2];
        *(ulong *)(param_2 + 4) = puVar8[1];
        *(ulong *)(param_2 + 0xc) = uVar1;
        uVar1 = puVar8[4];
        *(ulong *)(param_2 + 0x14) = puVar8[3];
        *(ulong *)(param_2 + 0x1c) = uVar1;
        param_2[0x2c] = (char)((((uint)*puVar8 & 0xf00f) >> 8 | ((uint)*puVar8 & 0xf) << 8) >> 4);
        uVar3 = ((uint)*puVar8 & 0xff000f00) >> 8;
        *(uint *)(param_2 + 0x28) =
             (uVar3 | ((uint)*puVar8 & 0xff0000) << 8) >> 0x10 | uVar3 << 0x10;
        bVar7 = local_68[0];
        if (param_2[1] == '\0') {
LAB_00101e08:
          if ((bVar7 == 0x11) || (bVar7 == 6)) {
            local_60[0] = local_60[0] & 0xffffffff00000000;
            if ((*(int *)(param_1 + 0x70) - (int)uVar6) - *(int *)(param_1 + 0x74) < 4) {
              if (param_1 != 0) {
                puVar8 = local_60;
                iVar4 = skb_copy_bits(param_1,uVar6,local_60,4);
                if (-1 < iVar4) goto LAB_00101e3c;
              }
            }
            else {
              puVar8 = (ulong *)(*(long *)(param_1 + 0xe0) + uVar6);
              if (puVar8 != (ulong *)0x0) {
LAB_00101e3c:
                uVar5 = 0;
                *(ushort *)(param_2 + 0x24) = (ushort)*puVar8 >> 8 | (ushort)*puVar8 << 8;
                *(ushort *)(param_2 + 0x26) =
                     *(ushort *)((long)puVar8 + 2) >> 8 | *(ushort *)((long)puVar8 + 2) << 8;
                goto LAB_00101ed4;
              }
            }
            goto LAB_00101ed0;
          }
        }
        else {
LAB_00101e00:
          if (param_2[2] != '\0') goto LAB_00101e08;
        }
        uVar5 = 0;
        goto LAB_00101ed4;
      }
    }
  }
  else if (*(short *)(param_1 + 0xb4) == 8) {
    local_60[2] = local_60[2] & 0xffffffff00000000;
    local_60[0] = 0;
    local_60[1] = 0;
    if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74) < 0x14) {
      if (param_1 != 0) {
        puVar8 = local_60;
        iVar4 = skb_copy_bits(param_1,0,local_60,0x14);
        if (-1 < iVar4) goto LAB_00101cfc;
      }
    }
    else {
      puVar8 = *(ulong **)(param_1 + 0xe0);
      if (puVar8 != (ulong *)0x0) {
LAB_00101cfc:
        bVar7 = (byte)*puVar8;
        if (4 < (bVar7 & 0xf)) {
          if ((*puVar8 & 0xff3f000000000000) != 0) {
            param_2[1] = 1;
            param_2[2] = (*puVar8 & 0xff1f000000000000) == 0;
            bVar7 = (byte)*puVar8;
          }
          uVar6 = (ulong)((bVar7 & 0xf) << 2);
          *param_2 = 4;
          bVar7 = *(byte *)((long)puVar8 + 9);
          param_2[3] = bVar7;
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)((long)puVar8 + 0xc);
          *(int *)(param_2 + 0x14) = (int)puVar8[2];
          param_2[0x2c] = *(byte *)((long)puVar8 + 1);
          if (param_2[1] != '\0') goto LAB_00101e00;
          goto LAB_00101e08;
        }
      }
    }
  }
LAB_00101ed0:
  uVar5 = 0xffffffea;
LAB_00101ed4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_60[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET2cc15953ac @ 00101f50 size=240
// signature: undefined DATARMNET2cc15953ac(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET2cc15953ac(void)

{
  undefined *puVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  lVar3 = _jiffies;
  _raw_spin_lock_bh(&DATARMNETc3c07e6644);
  ppuVar5 = (undefined **)DATARMNET5e3c62e3a4;
  if ((undefined **)DATARMNET5e3c62e3a4 != &DATARMNET5e3c62e3a4) {
    do {
      ppuVar6 = (undefined **)*ppuVar5;
      if (-1 < lVar3 - (long)ppuVar5[0xc]) {
        uVar4 = __list_del_entry_valid(ppuVar5);
        if ((uVar4 & 1) != 0) {
          puVar1 = *ppuVar5;
          plVar2 = (long *)ppuVar5[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar5 = &DAT_dead000000000100;
        ppuVar5[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar5);
        DATARMNETb666ba3e85 = DATARMNETb666ba3e85 + -1;
      }
      ppuVar5 = ppuVar6;
    } while (ppuVar6 != &DATARMNET5e3c62e3a4);
  }
  puVar1 = DATARMNET5e3c62e3a4;
  _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
  if ((undefined **)puVar1 != &DATARMNET5e3c62e3a4) {
    mod_timer(DATARMNET2d8efce4f0,_jiffies + 0xfa);
  }
  return;
}



//------------------------------------------------------------
// DATARMNETe0c7b9d5a4 @ 00102044 size=816
// signature: undefined DATARMNETe0c7b9d5a4(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNETe0c7b9d5a4(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  undefined1 local_78;
  char cStack_77;
  undefined1 uStack_76;
  char cStack_75;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  short sStack_54;
  short sStack_52;
  undefined8 local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  if (*(char *)(param_1 + 0xc28) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = ktime_get_with_offset(1);
  }
  *(undefined8 *)(*(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + 0x10) = uVar2;
  if (DATARMNETfef55eaf9a != 0) {
    if (DATARMNET2fe4661b82 == 0) {
      if (*(long *)(param_1 + 0xc30) != 0) {
        local_58 = 0;
        sStack_54 = 0;
        sStack_52 = 0;
        local_50 = 0;
        local_68 = 0;
        iStack_64 = 0;
        uStack_60 = 0;
        uStack_5c = 0;
        plVar6 = (long *)(*(long *)(param_1 + 0xc30) + 0x10);
        plVar5 = (long *)*plVar6;
        local_78 = 0;
        cStack_77 = '\0';
        uStack_76 = 0;
        cStack_75 = '\0';
        iStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 0;
        if (plVar5 != plVar6) {
          bVar3 = false;
          do {
            lVar7 = plVar5[7];
            if (lVar7 != 0) {
              if (*(int *)(lVar7 + 0x1c) == 10) {
                if (*(short *)(param_2 + 0xb4) == -0x227a) goto LAB_00102178;
              }
              else if ((*(int *)(lVar7 + 0x1c) != 2) || (*(short *)(param_2 + 0xb4) == 8)) {
LAB_00102178:
                if ((!bVar3) &&
                   ((iVar1 = DATARMNET481989429b(param_2,&local_78), iVar1 != 0 ||
                    (cStack_77 != '\0')))) break;
                cVar4 = *(char *)(lVar7 + 0x4a);
                if (cVar4 == -3) {
                  cVar4 = cStack_75;
                  if ((cStack_75 == '\x06') || (cStack_75 == '\x11')) goto LAB_001021d4;
                }
                else {
                  if (cVar4 == '\0') {
                    cVar4 = cStack_75;
                  }
                  else if (cVar4 != cStack_75) goto LAB_001022bc;
LAB_001021d4:
                  if (((cVar4 != '\x11') && (cVar4 != '\x06')) ||
                     (((*(short *)(lVar7 + 0x42) == 0 || (*(short *)(lVar7 + 0x42) == sStack_52)) &&
                      ((*(short *)(lVar7 + 0x40) == 0 || (*(short *)(lVar7 + 0x40) == sStack_54)))))
                     ) {
                    if (*(int *)(lVar7 + 0x1c) == 10) {
                      if ((((((*(byte *)(lVar7 + 0x4b) >> 1 & 1) == 0) ||
                            (*(long *)(lVar7 + 0x30) == CONCAT44(uStack_60,iStack_64) &&
                             *(long *)(lVar7 + 0x38) == CONCAT44(local_58,uStack_5c))) &&
                           (((*(byte *)(lVar7 + 0x4b) & 1) == 0 ||
                            (*(long *)(lVar7 + 0x20) == CONCAT44(uStack_70,iStack_74) &&
                             *(long *)(lVar7 + 0x28) == CONCAT44(local_68,uStack_6c))))) &&
                          ((*(byte *)(lVar7 + 0x48) == 0 ||
                           (*(byte *)(lVar7 + 0x48) == (*(byte *)(lVar7 + 0x49) & local_50._4_1_))))
                          ) && ((*(int *)(lVar7 + 0x44) == 0 ||
                                (*(int *)(lVar7 + 0x44) == (int)local_50))))
                      goto joined_r0x00102368;
                    }
                    else if ((((*(int *)(lVar7 + 0x1c) == 2) &&
                              (((*(byte *)(lVar7 + 0x4b) >> 1 & 1) == 0 ||
                               (*(int *)(lVar7 + 0x30) == iStack_64)))) &&
                             (((*(byte *)(lVar7 + 0x4b) & 1) == 0 ||
                              (*(int *)(lVar7 + 0x20) == iStack_74)))) &&
                            ((*(byte *)(lVar7 + 0x48) == 0 ||
                             (*(byte *)(lVar7 + 0x48) == (*(byte *)(lVar7 + 0x49) & local_50._4_1_))
                             ))) goto joined_r0x00102368;
                  }
                }
LAB_001022bc:
                bVar3 = true;
              }
            }
            plVar5 = (long *)*plVar5;
          } while (plVar5 != plVar6);
        }
      }
    }
    else if (((uint)DATARMNET2fe4661b82 == *(uint *)(param_2 + 0x8c) >> 0x10) &&
            (*(long *)(param_1 + 0xc30) != 0)) {
      plVar6 = (long *)(*(long *)(param_1 + 0xc30) + 0x10);
      plVar5 = plVar6;
      do {
        plVar5 = (long *)*plVar5;
        if (plVar5 == plVar6) goto LAB_00102334;
      } while (*(uint *)((long)plVar5 + 0x24) != *(uint *)(param_2 + 0x8c));
joined_r0x00102368:
      plVar6 = plVar5 + -2;
      if (plVar6 != (long *)0x0) {
        _raw_spin_lock_bh(&DATARMNET33bd4139f4);
        *(int *)(param_2 + 0x8c) = (int)plVar6[10];
        plVar6[0xb] = _jiffies + (ulong)*(uint *)((long)plVar5 + 0x44);
        plVar6[0xc] = plVar6[0xc] + (ulong)*(uint *)(param_2 + 0x70);
        _raw_spin_unlock_bh(&DATARMNET33bd4139f4);
        queue_delayed_work_on(0x20,_system_wq,DATARMNET3481998252,0x2ee);
      }
    }
  }
LAB_00102334:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// DATARMNET6ab4bbdaf4 @ 00102378 size=132
// signature: undefined DATARMNET6ab4bbdaf4(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET6ab4bbdaf4(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (((*(char *)(param_1 + 0xc28) == '\0') ||
      (*(long *)(*(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + 0x10) == 0 ||
       DATARMNETe7a1ab1dab == 0)) ||
     (lVar1 = ktime_get_with_offset(1),
     lVar1 - *(long *)(*(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + 0x10) <=
     DATARMNETe7a1ab1dab)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffff92;
  }
  return uVar2;
}



//------------------------------------------------------------
// DATARMNET998f6cbce7 @ 00102400 size=532
// signature: undefined DATARMNET998f6cbce7(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNET998f6cbce7(undefined8 param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined **ppuVar5;
  char *__s1;
  undefined **ppuVar6;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  __s1 = (char *)*param_3;
  if (__s1 != (char *)0x0) {
    iVar2 = strncmp(__s1,"rmnet_data",10);
    if (iVar2 == 0) {
      if (param_2 == 6) {
        mutex_lock(&DATARMNETd7b5a80f84);
        if ((undefined **)DATARMNET7520901fb5 != &DATARMNET7520901fb5) {
          iVar2 = *(int *)(__s1 + 0xd8);
          ppuVar5 = (undefined **)DATARMNET7520901fb5;
          do {
            ppuVar6 = (undefined **)*ppuVar5;
            if (*(int *)((long)ppuVar5 + 0x1c) == iVar2) {
              if (DATARMNET7d98961cbe._4_4_ != 0) {
                local_60 = *(undefined4 *)((long)ppuVar5 + 0x14);
                local_68 = 0x200000005;
                iVar3 = DATARMNETbd1d5c8f28(&DATARMNET7d98961cbe,1,2,0xc,&local_68,0xa20);
                if (iVar3 != 0) {
                  DATARMNET7d98961cbe._4_4_ = 0;
                }
              }
              DATARMNET7fa3dd63cb(ppuVar5 + -4);
            }
            ppuVar5 = ppuVar6;
          } while (ppuVar6 != &DATARMNET7520901fb5);
        }
        lVar4 = *(long *)(__s1 + 0xc30);
        if (lVar4 != 0) {
          if (*(long **)(lVar4 + 0x10) != (long *)(lVar4 + 0x10)) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102610);
            (*pcVar1)();
          }
          __s1[0xc30] = '\0';
          __s1[0xc31] = '\0';
          __s1[0xc32] = '\0';
          __s1[0xc33] = '\0';
          __s1[0xc34] = '\0';
          __s1[0xc35] = '\0';
          __s1[0xc36] = '\0';
          __s1[0xc37] = '\0';
          kvfree_call_rcu(lVar4,0);
        }
      }
      else {
        if (param_2 != 2) goto LAB_001025d4;
        __s1[0xc28] = '\0';
        mutex_lock(&DATARMNETd7b5a80f84);
        if ((undefined **)DATARMNET7520901fb5 != &DATARMNET7520901fb5) {
          iVar2 = *(int *)(__s1 + 0xd8);
          ppuVar5 = (undefined **)DATARMNET7520901fb5;
          do {
            ppuVar6 = (undefined **)*ppuVar5;
            if (*(int *)((long)ppuVar5 + 0x1c) == iVar2) {
              if (DATARMNET7d98961cbe._4_4_ != 0) {
                local_60 = *(undefined4 *)((long)ppuVar5 + 0x14);
                local_68 = 0x200000005;
                iVar3 = DATARMNETbd1d5c8f28(&DATARMNET7d98961cbe,1,2,0xc,&local_68,0xa20);
                if (iVar3 != 0) {
                  DATARMNET7d98961cbe._4_4_ = 0;
                }
              }
              DATARMNET7fa3dd63cb(ppuVar5 + -4);
            }
            ppuVar5 = ppuVar6;
          } while (ppuVar6 != &DATARMNET7520901fb5);
        }
      }
      mutex_unlock(&DATARMNETd7b5a80f84);
    }
  }
LAB_001025d4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// DATARMNET5979020f87 @ 0010261c size=364
// signature: undefined DATARMNET5979020f87(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DATARMNET5979020f87(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  bool bVar6;
  
  mutex_lock(&DATARMNETd7b5a80f84);
  if (DATARMNET54b95e4416 == '\x01') {
    _raw_spin_lock_bh(&DATARMNET33bd4139f4);
    list_sort(0,&DATARMNET7520901fb5,DATARMNET772c0b87c5);
    if ((undefined **)DATARMNET7520901fb5 == &DATARMNET7520901fb5) {
      bVar6 = false;
    }
    else {
      puVar3 = (undefined *)0x0;
      puVar4 = (undefined *)0x0;
      bVar6 = false;
      ppuVar2 = (undefined **)DATARMNET7520901fb5;
      do {
        if (*(char *)((long)ppuVar2 + 0x21) != '\0') {
          if ((ulong)(ppuVar2[8] + (long)puVar3) >> 0x13 < 0x177) {
            *(undefined1 *)(ppuVar2 + 9) = 1;
            uVar5 = *(uint *)(ppuVar2 + 6) | 0x100;
            puVar3 = ppuVar2[8] + (long)puVar3;
          }
          else {
            *(undefined1 *)(ppuVar2 + 9) = 0;
            uVar5 = *(uint *)(ppuVar2 + 6) & 0xfffffeff;
          }
          *(uint *)(ppuVar2 + 6) = uVar5;
        }
        if (*(char *)((long)ppuVar2 + 0x22) != '\0') {
          puVar1 = ppuVar2[8] + (long)puVar4;
          if ((ulong)puVar1 >> 0x14 < 0x4b) {
            *(undefined1 *)((long)ppuVar2 + 0x49) = 1;
            uVar5 = *(uint *)(ppuVar2 + 6) | 0x200;
            puVar4 = puVar1;
          }
          else {
            *(undefined1 *)((long)ppuVar2 + 0x49) = 0;
            uVar5 = *(uint *)(ppuVar2 + 6) & 0xfffffdff;
          }
          *(uint *)(ppuVar2 + 6) = uVar5;
        }
        if (ppuVar2[8] != (undefined *)0x0) {
          bVar6 = true;
          ppuVar2[8] = (undefined *)0x0;
        }
        ppuVar2 = (undefined **)*ppuVar2;
      } while (ppuVar2 != &DATARMNET7520901fb5);
    }
    _raw_spin_unlock_bh(&DATARMNET33bd4139f4);
    mutex_unlock(&DATARMNETd7b5a80f84);
    if (bVar6) {
      queue_delayed_work_on(0x20,_system_wq,DATARMNET3481998252,0x2ee);
    }
  }
  else {
    mutex_unlock(&DATARMNETd7b5a80f84);
  }
  return;
}



//------------------------------------------------------------
// DATARMNET772c0b87c5 @ 0010278c size=20
// signature: undefined DATARMNET772c0b87c5(void)
// callers: []
//------------------------------------------------------------

bool DATARMNET772c0b87c5(undefined8 param_1,long param_2,long param_3)

{
  return *(ulong *)(param_3 + 0x40) < *(ulong *)(param_2 + 0x40);
}



//------------------------------------------------------------
// DATARMNETd7fae4b1c9 @ 001027a4 size=744
// signature: undefined DATARMNETd7fae4b1c9(void)
// callers: []
//------------------------------------------------------------

undefined8 DATARMNETd7fae4b1c9(undefined8 param_1)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  code *pcVar8;
  char *pcVar9;
  ulong uVar10;
  long lVar11;
  int iVar12;
  ulong uVar13;
  
  _raw_spin_lock_bh(&DATARMNET86e81617f0);
  if (9 < DATARMNET04583f0705) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x102a8c);
    (*pcVar8)();
  }
  if (0x230 < (ulong)DATARMNET04583f0705 * 0x38) {
LAB_00102a84:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(1,0x102a88);
    (*pcVar8)();
  }
  uVar7 = 0;
  if (*(long *)(DATARMNETeb47903253 + (ulong)DATARMNET04583f0705 * 0x38) != 0) {
    uVar7 = DATARMNET04583f0705;
  }
  do {
    uVar10 = (ulong)uVar7;
    if ((0x230 < uVar10 * 0x38) || (uVar7 == 10)) goto LAB_00102a84;
    lVar11 = *(long *)(DATARMNETeb47903253 + uVar10 * 0x38);
    if (lVar11 == 0) break;
    uVar6 = uVar10 * 0x38;
    if (0x225 < uVar6) goto LAB_00102a84;
    lVar5 = lVar11 / 1000000000;
    iVar12 = (int)lVar5;
    iVar4 = iVar12 + ((int)(SUB168(SEXT816(lVar5) * SEXT816(0x48d159e26af37c05),8) >> 10) -
                     (SUB164(SEXT816(lVar5) * SEXT816(0x48d159e26af37c05),0xc) >> 0x1f)) * -0xe10;
    uVar1 = iVar4 + ((uint)((short)iVar4 * -0x7777) >> 0x10);
    cVar2 = DATARMNETeb47903253[uVar10 * 0x38 + 0xb];
    if ((cVar2 == '\x11') || (cVar2 == '\x06')) {
      if (0x228 < uVar6) goto LAB_00102a84;
      if (DATARMNETeb47903253[uVar6 + 8] == '\x04') {
        if ((0x204 < uVar6) || (0x202 < uVar6)) goto LAB_00102a84;
        uVar3 = *(ushort *)(DATARMNETeb47903253 + uVar6 + 0x2c);
        pcVar9 = "[%6lld %02d:%02d:%02d] %2u %pI4/%u %pI4/%u\n";
      }
      else {
        if ((0x204 < uVar6) || (0x202 < uVar6)) goto LAB_00102a84;
        uVar3 = *(ushort *)(DATARMNETeb47903253 + uVar6 + 0x2c);
        pcVar9 = "[%6lld %02d:%02d:%02d] %2u %pI6/%u %pI6/%u\n";
      }
      uVar13 = (ulong)uVar3;
    }
    else {
      if (0x228 < uVar6) goto LAB_00102a84;
      uVar13 = uVar10 * 0x38 + 0x103484;
      if (DATARMNETeb47903253[uVar6 + 8] == '\x04') {
        pcVar9 = "[%6lld %02d:%02d:%02d] %2u %pI4 %pI4\n";
      }
      else {
        pcVar9 = "[%6lld %02d:%02d:%02d] %2u %pI6 %pI6\n";
      }
    }
    seq_printf(param_1,pcVar9,lVar11 / 86400000000000,
               (iVar12 + (int)(lVar5 / 0x15180) * -0x15180) / 0xe10 & 0xff,
               ((uint)(int)(short)uVar1 >> 5) + ((uVar1 & 0x8000) >> 0xf) & 0xff,
               iVar12 + ((int)(SUB168(SEXT816(lVar5) * ZEXT816(0x8888888888888889),8) >> 5) -
                        (SUB164(SEXT816(lVar5) * ZEXT816(0x8888888888888889),0xc) >> 0x1f)) * -0x3c
               & 0xff,cVar2,uVar10 * 0x38 + 0x103474,uVar13);
    uVar1 = 0;
    if (uVar7 < 9) {
      uVar1 = uVar7 + 1;
    }
    uVar7 = uVar1;
  } while (uVar1 != DATARMNET04583f0705);
  _raw_spin_unlock_bh(&DATARMNET86e81617f0);
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102f1c size=308
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  undefined *puVar2;
  
  _printk(&DAT_001036fd,&DAT_00103834);
  iVar1 = DATARMNETcfa8d492f8();
  if (iVar1 == 0) {
    register_netdevice_notifier(&DATARMNETc580548769);
    _rmnet_aps_pre_queue = DATARMNETe0c7b9d5a4;
    _rmnet_aps_post_queue = DATARMNET6ab4bbdaf4;
    rmnet_module_hook_register(DATARMNET509284caa6,2);
    rmnet_module_hook_register(DATARMNET644887c40e,1);
    mutex_lock(&DATARMNETd7b5a80f84);
    DATARMNET54b95e4416 = 1;
    mutex_unlock(&DATARMNETd7b5a80f84);
    DATARMNET147f9b9f22 = proc_mkdir(&DAT_00103784,0);
    if (DATARMNET147f9b9f22 == 0) {
      puVar2 = &DAT_001037dd;
    }
    else {
      DATARMNETf9422af3b0 =
           proc_create_single_data("dl_activity",0x124,DATARMNET147f9b9f22,DATARMNETd7fae4b1c9,0);
      if (DATARMNETf9422af3b0 != 0) {
        return 0;
      }
      puVar2 = &DAT_0010372d;
      DATARMNETf9422af3b0 = 0;
    }
  }
  else {
    puVar2 = &DAT_001036b9;
  }
  _printk(puVar2);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00103054 size=508
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cleanup_module(void)

{
  undefined *puVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  proc_remove(DATARMNETf9422af3b0);
  proc_remove(DATARMNET147f9b9f22);
  rmnet_module_hook_unregister_no_sync(DATARMNETbdf157f06a,2);
  rmnet_module_hook_unregister_no_sync(DATARMNET644887c40e,1);
  _rmnet_aps_pre_queue = 0;
  _rmnet_aps_post_queue = 0;
  rmnet_module_hook_unregister_no_sync(DATARMNET509284caa6,2);
  synchronize_rcu();
  mutex_lock(&DATARMNETd7b5a80f84);
  DATARMNET54b95e4416 = 0;
  ppuVar6 = (undefined **)DATARMNET7520901fb5;
  while (ppuVar6 != &DATARMNET7520901fb5) {
    ppuVar7 = ppuVar6 + -4;
    ppuVar6 = (undefined **)*ppuVar6;
    DATARMNET7fa3dd63cb(ppuVar7);
  }
  mutex_unlock(&DATARMNETd7b5a80f84);
  if (DATARMNET7d98961cbe._4_4_ != 0) {
    local_48 = 0x300000005;
    local_40 = 0;
    iVar4 = DATARMNETbd1d5c8f28(&DATARMNET7d98961cbe,1,2,0xc,&local_48,0xa20);
    if (iVar4 != 0) {
      DATARMNET7d98961cbe._4_4_ = 0;
    }
  }
  cancel_delayed_work_sync(DATARMNET3481998252);
  del_timer_sync(DATARMNETd21629e047);
  cancel_work_sync(&DATARMNET8e3aef0760);
  _raw_spin_lock_bh(&DATARMNETc3c07e6644);
  ppuVar6 = (undefined **)DATARMNET5e3c62e3a4;
  if ((undefined **)DATARMNET5e3c62e3a4 != &DATARMNET5e3c62e3a4) {
    do {
      ppuVar7 = (undefined **)*ppuVar6;
      uVar5 = __list_del_entry_valid(ppuVar6);
      if ((uVar5 & 1) != 0) {
        puVar1 = *ppuVar6;
        plVar2 = (long *)ppuVar6[1];
        *(long **)(puVar1 + 8) = plVar2;
        *plVar2 = (long)puVar1;
      }
      *ppuVar6 = &DAT_dead000000000100;
      ppuVar6[1] = (undefined *)0xdead000000000122;
      kfree(ppuVar6);
      ppuVar6 = ppuVar7;
    } while (ppuVar7 != &DATARMNET5e3c62e3a4);
  }
  DATARMNET5500f4ed98 = 1;
  DATARMNETb666ba3e85 = 0;
  _raw_spin_unlock_bh(&DATARMNETc3c07e6644);
  del_timer_sync(DATARMNET2d8efce4f0);
  unregister_netdevice_notifier(&DATARMNETc580548769);
  DATARMNETca7606cfd1();
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// genl_register_family @ 00105000 size=1
// signature: undefined genl_register_family(void)
// callers: [DATARMNETcfa8d492f8]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 00105008 size=1
// signature: undefined genl_unregister_family(void)
// callers: [DATARMNETca7606cfd1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_memcpy @ 00105010 size=1
// signature: undefined nla_memcpy(void)
// callers: [DATARMNET37a9efbbcb, DATARMNET1998d09852, DATARMNETae6b282c61, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_memcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105018 size=1
// signature: undefined mutex_lock(void)
// callers: [DATARMNET5979020f87, cleanup_module, DATARMNET37a9efbbcb, DATARMNET998f6cbce7, DATARMNETd1a02b8188, init_module, DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_index @ 00105028 size=1
// signature: undefined dev_get_by_index(void)
// callers: [DATARMNET37a9efbbcb, DATARMNET1998d09852, DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00105030 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [DATARMNET37a9efbbcb, DATARMNET998f6cbce7, DATARMNET1998d09852, DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105038 size=1
// signature: undefined mutex_unlock(void)
// callers: [DATARMNET5979020f87, cleanup_module, DATARMNET37a9efbbcb, DATARMNET998f6cbce7, DATARMNETd1a02b8188, init_module, DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105048 size=1
// signature: undefined kmalloc_trace(void)
// callers: [DATARMNET37a9efbbcb, DATARMNET82d65f9ca6, DATARMNET9e18f3d501, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 00105050 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [DATARMNET37a9efbbcb, DATARMNET1998d09852, DATARMNETae6b282c61]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [DATARMNETe0c7b9d5a4, cleanup_module, DATARMNETfb7a2ce025, DATARMNET5ff569bc33, DATARMNET37a9efbbcb, DATARMNET8871996254, DATARMNET998f6cbce7, DATARMNET1998d09852, DATARMNETd1a02b8188, DATARMNET481989429b, DATARMNETae6b282c61, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00105060 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [DATARMNETe0c7b9d5a4, DATARMNET5979020f87, cleanup_module, DATARMNETfb7a2ce025, DATARMNET5ff569bc33, DATARMNET71e03e7287, DATARMNET82d65f9ca6, DATARMNET8871996254, DATARMNETd7fae4b1c9, DATARMNETd1a02b8188, DATARMNET2cc15953ac, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00105068 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [DATARMNETe0c7b9d5a4, DATARMNET5979020f87, cleanup_module, DATARMNETfb7a2ce025, DATARMNET5ff569bc33, DATARMNET71e03e7287, DATARMNET82d65f9ca6, DATARMNET8871996254, DATARMNETd7fae4b1c9, DATARMNETd1a02b8188, DATARMNET2cc15953ac, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105078 size=1
// signature: undefined __list_add_valid(void)
// callers: [DATARMNET82d65f9ca6, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00105080 size=1
// signature: undefined mod_timer(void)
// callers: [DATARMNET82d65f9ca6, DATARMNETd1a02b8188, DATARMNET2cc15953ac, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00105088 size=1
// signature: undefined __alloc_skb(void)
// callers: [DATARMNETbd1d5c8f28, DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 00105090 size=1
// signature: undefined genlmsg_put(void)
// callers: [DATARMNETbd1d5c8f28]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 00105098 size=1
// signature: undefined nla_put(void)
// callers: [DATARMNETbd1d5c8f28]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 001050a0 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [DATARMNETbd1d5c8f28]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 001050a8 size=1
// signature: undefined netlink_unicast(void)
// callers: [DATARMNETbd1d5c8f28]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001050b0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cleanup_module, DATARMNET5ff569bc33, DATARMNET2cc15953ac, DATARMNET7fa3dd63cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050b8 size=1
// signature: undefined kfree(void)
// callers: [cleanup_module, DATARMNET5ff569bc33, DATARMNET2cc15953ac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 001050c0 size=1
// signature: undefined skb_put(void)
// callers: [DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_qmap_next_txid @ 001050c8 size=1
// signature: undefined rmnet_qmap_next_txid(void)
// callers: [DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_qmap_next_txid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_qmap_send @ 001050d0 size=1
// signature: undefined rmnet_qmap_send(void)
// callers: [DATARMNET568dffe281]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_qmap_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050d8 size=1
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
// register_netdevice_notifier @ 001050e0 size=1
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
// rmnet_module_hook_register @ 001050f8 size=1
// signature: undefined rmnet_module_hook_register(void)
// callers: [DATARMNET8871996254, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 00105100 size=1
// signature: undefined proc_mkdir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create_single_data @ 00105108 size=1
// signature: undefined proc_create_single_data(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create_single_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_remove @ 00105110 size=1
// signature: undefined proc_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 00105118 size=1
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: [cleanup_module, DATARMNET8871996254]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_module_hook_unregister_no_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 00105120 size=1
// signature: undefined synchronize_rcu(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00105128 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 00105130 size=1
// signature: undefined del_timer_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00105138 size=1
// signature: undefined cancel_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_notifier @ 00105140 size=1
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
// kvfree_call_rcu @ 00105148 size=1
// signature: undefined kvfree_call_rcu(void)
// callers: [DATARMNET998f6cbce7, DATARMNET7fa3dd63cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree_call_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 00105150 size=1
// signature: undefined del_timer(void)
// callers: [DATARMNET7fa3dd63cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105160 size=1
// signature: undefined queue_work_on(void)
// callers: [DATARMNETf844db79d9]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00105168 size=1
// signature: undefined kstrtouint(void)
// callers: [DATARMNET8871996254]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_coarse_with_offset @ 00105170 size=1
// signature: undefined ktime_get_coarse_with_offset(void)
// callers: [DATARMNETfb7a2ce025, DATARMNET71e03e7287, DATARMNET8871996254]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_coarse_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// param_set_uint @ 00105178 size=1
// signature: undefined param_set_uint(void)
// callers: [DATARMNET8871996254]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void param_set_uint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_header_ptr @ 00105188 size=1
// signature: undefined rmnet_frag_header_ptr(void)
// callers: [DATARMNETfb7a2ce025]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_header_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_frag_ipv6_skip_exthdr @ 00105190 size=1
// signature: undefined rmnet_frag_ipv6_skip_exthdr(void)
// callers: [DATARMNETfb7a2ce025]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_frag_ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_skip_exthdr @ 00105198 size=1
// signature: undefined ipv6_skip_exthdr(void)
// callers: [DATARMNET481989429b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 001051a0 size=1
// signature: undefined skb_copy_bits(void)
// callers: [DATARMNET481989429b]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 001051a8 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [DATARMNETe0c7b9d5a4, DATARMNET6ab4bbdaf4]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001051b0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [DATARMNETe0c7b9d5a4, DATARMNET5979020f87]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// list_sort @ 001051b8 size=1
// signature: undefined list_sort(void)
// callers: [DATARMNET5979020f87]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void list_sort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001051c0 size=1
// signature: undefined seq_printf(void)
// callers: [DATARMNETd7fae4b1c9]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



