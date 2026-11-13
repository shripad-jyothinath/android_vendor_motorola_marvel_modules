// Decompiled by Ghidra 12.2
// Program: moto_binder.ko
// Image base: 00100000

//------------------------------------------------------------
// binder_trans_handler @ 00100a44 size=992
// signature: undefined binder_trans_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void binder_trans_handler
               (undefined8 param_1,long param_2,long param_3,undefined8 param_4,long param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  bool bVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 local_d8;
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
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
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
  local_d8 = 0;
  if ((((param_2 != 0) && ((*(uint *)(param_5 + 0x14) & 1) == 0)) &&
      (*(long *)(param_2 + 0x48) != 0)) && (*(long *)(param_3 + 0x48) != 0)) {
    __rcu_read_lock();
    uVar2 = *(uint *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
    __rcu_read_unlock();
    if (((10000 < uVar2) && (*(int *)(param_3 + 0x40) != *(int *)(param_2 + 0x40))) &&
       (((lVar11 = *(long *)(param_2 + 0x48), (*(ushort *)(lVar11 + 0x5e8) >> 6 & 1) != 0 &&
         (*(char *)(lVar11 + 0x5da) < '\0')) ||
        ((*(uint *)(*(long *)(lVar11 + 0x670) + 0x30) >> 0xf & 1) != 0)))) {
      __rcu_read_lock();
      uVar4 = *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x48) + 0x830) + 4);
      __rcu_read_unlock();
      uVar5 = *(undefined4 *)(*(long *)(param_3 + 0x48) + 0x634);
      __rcu_read_lock();
      uVar6 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
      __rcu_read_unlock();
      uVar3 = *(undefined4 *)(*(long *)(param_2 + 0x48) + 0x634);
      Hint_Prefetch(0x102ac8,2,0,1);
      do {
        iVar1 = moto_binder_last_id + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102ac8,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_last_id = iVar1;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      Hint_Prefetch(0x102acc,2,0,1);
      do {
        uVar2 = moto_binder_transaction_log + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102acc,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_transaction_log = uVar2;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      if (0x1f < uVar2) {
        DAT_00102ad0 = 1;
      }
      lVar11 = (ulong)(uVar2 & 0x1f) * 0x20;
      *(undefined8 *)(&DAT_00102ad8 + lVar11) = 0;
      *(undefined8 *)(&DAT_00102ae0 + lVar11) = 0;
      *(undefined8 *)(&DAT_00102ae8 + lVar11) = 0;
      *(int *)(&DAT_00102ad4 + lVar11) = iVar1;
      *(undefined4 *)(&DAT_00102ad8 + lVar11) = 0;
      *(undefined4 *)(&DAT_00102adc + lVar11) = uVar4;
      *(undefined4 *)(&DAT_00102ae0 + lVar11) = uVar5;
      *(undefined4 *)(&DAT_00102ae4 + lVar11) = uVar6;
      *(undefined4 *)(&DAT_00102ae8 + lVar11) = uVar3;
      *(undefined8 *)(&DAT_00102aec + lVar11) = 0;
      moto_binder_send_uevent(0,uVar4,uVar5,uVar6,uVar3,0,0);
    }
  }
  if (((param_2 != 0) && ((*(uint *)(param_5 + 0x14) & 1) != 0)) &&
     ((*(long *)(param_2 + 0x48) != 0 && (*(long *)(param_3 + 0x48) != 0)))) {
    __rcu_read_lock();
    uVar2 = *(uint *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
    __rcu_read_unlock();
    if (((10000 < uVar2) && (*(int *)(param_3 + 0x40) != *(int *)(param_2 + 0x40))) &&
       (((lVar11 = *(long *)(param_2 + 0x48), (*(ushort *)(lVar11 + 0x5e8) >> 6 & 1) != 0 &&
         (*(char *)(lVar11 + 0x5da) < '\0')) ||
        ((*(uint *)(*(long *)(lVar11 + 0x670) + 0x30) >> 0xf & 1) != 0)))) {
      uVar12 = *(ulong *)(param_5 + 0x20);
      puVar9 = (undefined8 *)sp_el0;
      uVar14 = *(ulong *)(param_5 + 0x30);
      if (0x8b < uVar12) {
        uVar12 = 0x8c;
      }
      if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = uVar14, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
        uVar13 = uVar14 & (long)(uVar14 << 8) >> 8;
      }
      if (uVar13 <= 0x8000000000 - uVar12) {
        *(int *)(puVar9 + 0x16d) = *(int *)(puVar9 + 0x16d) + 1;
        __check_object_size(&local_d8,uVar12,0);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar10 = daif;
            daif = uVar10 | 0xc0;
          }
          uVar10 = ttbr1_el1;
          ttbr1_el1 = puVar9[1] & 0xffff000000000000 | uVar10 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar9[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        lVar11 = __arch_copy_from_user(&local_d8,uVar14 & 0xff7fffffffffffff,uVar12);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar14 = daif;
            daif = uVar14 | 0xc0;
          }
          uVar14 = ttbr1_el1;
          ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar14 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        *(int *)(puVar9 + 0x16d) = *(int *)(puVar9 + 0x16d) + -1;
        if ((lVar11 == 0) &&
           (*(short *)(*(long *)(*(long *)(param_2 + 0x48) + 0x890) + 0x3ca) < 0xfb)) {
          __rcu_read_lock();
          uVar4 = *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x48) + 0x830) + 4);
          __rcu_read_unlock();
          uVar5 = *(undefined4 *)(*(long *)(param_3 + 0x48) + 0x634);
          __rcu_read_lock();
          uVar6 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
          __rcu_read_unlock();
          moto_binder_write_status
                    (1,uVar4,uVar5,uVar6,*(undefined4 *)(*(long *)(param_2 + 0x48) + 0x634),0,
                     *(undefined4 *)(param_5 + 0x10));
        }
      }
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// moto_binder_write_status @ 00100e80 size=172
// signature: undefined moto_binder_write_status(void)
// callers: [binder_trans_handler, report_first_packet_after_wakeup]
//------------------------------------------------------------

void moto_binder_write_status
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  
  Hint_Prefetch(0x102ac8,2,0,1);
  do {
    iVar2 = moto_binder_last_id + 1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(0x102ac8,0x10);
    if (bVar5) {
      cVar4 = ExclusiveMonitorsStatus();
      moto_binder_last_id = iVar2;
    }
  } while (cVar4 != '\0');
  DataMemoryBarrier(2,3);
  Hint_Prefetch(0x102acc,2,0,1);
  do {
    uVar3 = moto_binder_transaction_log + 1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(0x102acc,0x10);
    if (bVar5) {
      cVar4 = ExclusiveMonitorsStatus();
      moto_binder_transaction_log = uVar3;
    }
  } while (cVar4 != '\0');
  DataMemoryBarrier(2,3);
  if (0x1f < uVar3) {
    DAT_00102ad0 = 1;
  }
  lVar1 = (ulong)(uVar3 & 0x1f) * 0x20;
  *(undefined8 *)(&DAT_00102ad8 + lVar1) = 0;
  *(undefined8 *)(&DAT_00102ae0 + lVar1) = 0;
  *(undefined8 *)(&DAT_00102ae8 + lVar1) = 0;
  *(int *)(&DAT_00102ad4 + lVar1) = iVar2;
  *(undefined4 *)(&DAT_00102ad8 + lVar1) = param_1;
  *(undefined4 *)(&DAT_00102adc + lVar1) = param_2;
  *(undefined4 *)(&DAT_00102ae0 + lVar1) = param_3;
  *(undefined4 *)(&DAT_00102ae4 + lVar1) = param_4;
  *(undefined4 *)(&DAT_00102ae8 + lVar1) = param_5;
  *(undefined4 *)(&DAT_00102aec + lVar1) = param_6;
  *(undefined4 *)(&DAT_00102af0 + lVar1) = param_7;
  moto_binder_send_uevent();
  return;
}



//------------------------------------------------------------
// binder_reply_handler @ 00100f60 size=384
// signature: undefined binder_reply_handler(void)
// callers: []
//------------------------------------------------------------

void binder_reply_handler(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  bool bVar8;
  long lVar9;
  
  if (((param_2 != 0) && (*(long *)(param_2 + 0x48) != 0)) && (*(long *)(param_3 + 0x48) != 0)) {
    __rcu_read_lock();
    uVar2 = *(uint *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
    __rcu_read_unlock();
    if (((uVar2 < 0x7d1) && (*(int *)(param_3 + 0x40) != *(int *)(param_2 + 0x40))) &&
       (((lVar9 = *(long *)(param_2 + 0x48), (*(ushort *)(lVar9 + 0x5e8) >> 6 & 1) != 0 &&
         (*(char *)(lVar9 + 0x5da) < '\0')) ||
        ((*(uint *)(*(long *)(lVar9 + 0x670) + 0x30) >> 0xf & 1) != 0)))) {
      __rcu_read_lock();
      uVar3 = *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x48) + 0x830) + 4);
      __rcu_read_unlock();
      uVar4 = *(undefined4 *)(*(long *)(param_3 + 0x48) + 0x634);
      __rcu_read_lock();
      uVar5 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x48) + 0x830) + 4);
      __rcu_read_unlock();
      uVar6 = *(undefined4 *)(*(long *)(param_2 + 0x48) + 0x634);
      Hint_Prefetch(0x102ac8,2,0,1);
      do {
        iVar1 = moto_binder_last_id + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102ac8,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_last_id = iVar1;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      Hint_Prefetch(0x102acc,2,0,1);
      do {
        uVar2 = moto_binder_transaction_log + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102acc,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_transaction_log = uVar2;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      if (0x1f < uVar2) {
        DAT_00102ad0 = 1;
      }
      lVar9 = (ulong)(uVar2 & 0x1f) * 0x20;
      *(undefined8 *)(&DAT_00102ad8 + lVar9) = 0;
      *(undefined8 *)(&DAT_00102ae0 + lVar9) = 0;
      *(undefined8 *)(&DAT_00102ae8 + lVar9) = 0;
      *(int *)(&DAT_00102ad4 + lVar9) = iVar1;
      *(undefined4 *)(&DAT_00102ad8 + lVar9) = 2;
      *(undefined4 *)(&DAT_00102adc + lVar9) = uVar3;
      *(undefined4 *)(&DAT_00102ae0 + lVar9) = uVar4;
      *(undefined4 *)(&DAT_00102ae4 + lVar9) = uVar5;
      *(undefined4 *)(&DAT_00102ae8 + lVar9) = uVar6;
      *(undefined8 *)(&DAT_00102aec + lVar9) = 0;
      moto_binder_send_uevent(2,uVar3,uVar4,uVar5,uVar6,0,0);
    }
  }
  return;
}



//------------------------------------------------------------
// binder_alloc_handler @ 0010111c size=368
// signature: undefined binder_alloc_handler(void)
// callers: []
//------------------------------------------------------------

void binder_alloc_handler(undefined8 param_1,long param_2,ulong *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  bool bVar8;
  long lVar9;
  long lVar10;
  
  if (((param_3 != (ulong *)0x68) && (param_4 != 0)) &&
     ((*param_3 < param_2 * 3 + 0x138U || (*param_3 >> 0xc < 0x19)))) {
    __rcu_read_lock();
    lVar10 = find_task_by_vpid((int)param_3[3]);
    __rcu_read_unlock();
    if ((lVar10 != 0) &&
       ((((*(ushort *)(lVar10 + 0x5e8) >> 6 & 1) != 0 && (*(char *)(lVar10 + 0x5da) < '\0')) ||
        ((*(uint *)(*(long *)(lVar10 + 0x670) + 0x30) >> 0xf & 1) != 0)))) {
      __rcu_read_lock();
      lVar9 = sp_el0;
      uVar3 = *(undefined4 *)(*(long *)(lVar9 + 0x830) + 4);
      __rcu_read_unlock();
      uVar4 = *(undefined4 *)(lVar9 + 0x634);
      __rcu_read_lock();
      uVar5 = *(undefined4 *)(*(long *)(lVar10 + 0x830) + 4);
      __rcu_read_unlock();
      uVar6 = *(undefined4 *)(lVar10 + 0x634);
      Hint_Prefetch(0x102ac8,2,0,1);
      do {
        iVar1 = moto_binder_last_id + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102ac8,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_last_id = iVar1;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      Hint_Prefetch(0x102acc,2,0,1);
      do {
        uVar2 = moto_binder_transaction_log + 1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(0x102acc,0x10);
        if (bVar8) {
          cVar7 = ExclusiveMonitorsStatus();
          moto_binder_transaction_log = uVar2;
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      if (0x1f < uVar2) {
        DAT_00102ad0 = 1;
      }
      lVar10 = (ulong)(uVar2 & 0x1f) * 0x20;
      *(undefined8 *)(&DAT_00102ad8 + lVar10) = 0;
      *(undefined8 *)(&DAT_00102ae0 + lVar10) = 0;
      *(undefined8 *)(&DAT_00102ae8 + lVar10) = 0;
      *(int *)(&DAT_00102ad4 + lVar10) = iVar1;
      *(undefined4 *)(&DAT_00102ad8 + lVar10) = 3;
      *(undefined4 *)(&DAT_00102adc + lVar10) = uVar3;
      *(undefined4 *)(&DAT_00102ae0 + lVar10) = uVar4;
      *(undefined4 *)(&DAT_00102ae4 + lVar10) = uVar5;
      *(undefined4 *)(&DAT_00102ae8 + lVar10) = uVar6;
      *(undefined8 *)(&DAT_00102aec + lVar10) = 0;
      moto_binder_send_uevent(3,uVar3,uVar4,uVar5,uVar6,0,0);
    }
  }
  return;
}



//------------------------------------------------------------
// binder_preset_handler @ 001012c8 size=40
// signature: undefined binder_preset_handler(void)
// callers: []
//------------------------------------------------------------

void binder_preset_handler(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (binder_procs == 0) {
    binder_procs = param_2;
  }
  if (binder_procs_lock == 0) {
    binder_procs_lock = param_3;
    return;
  }
  return;
}



//------------------------------------------------------------
// proc_binder_status_show @ 001012f4 size=240
// signature: undefined proc_binder_status_show(void)
// callers: []
//------------------------------------------------------------

undefined8 proc_binder_status_show(undefined8 param_1)

{
  long lVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = moto_binder_transaction_log + 1;
  iVar4 = 0x20;
  if (DAT_00102ad0 == '\0' && uVar2 < 0x21) {
    iVar4 = moto_binder_transaction_log + 1;
  }
  if (iVar4 != 0) {
    uVar5 = 0;
    if (DAT_00102ad0 != '\0' || 0x1f < uVar2) {
      uVar5 = uVar2 & 0x1f;
    }
    do {
      pcVar3 = "unknown";
      lVar1 = (ulong)(uVar5 & 0x1f) * 0x20;
      if (*(uint *)(&DAT_00102ad8 + lVar1) < 5) {
        pcVar3 = (&PTR_DAT_001034e8)[(int)*(uint *)(&DAT_00102ad8 + lVar1)];
      }
      seq_printf(param_1,"%d: %s from %d:%d to %d:%d %d %d\n",*(undefined4 *)(&DAT_00102ad4 + lVar1)
                 ,pcVar3,*(undefined4 *)(&DAT_00102adc + lVar1),
                 *(undefined4 *)(&DAT_00102ae0 + lVar1),*(undefined4 *)(&DAT_00102ae4 + lVar1),
                 *(undefined4 *)(&DAT_00102ae8 + lVar1),*(undefined4 *)(&DAT_00102aec + lVar1),
                 *(undefined4 *)(&DAT_00102af0 + lVar1));
      iVar4 = iVar4 + -1;
      uVar5 = uVar5 + 1;
    } while (iVar4 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// proc_binder_check_status_print @ 001013e8 size=60
// signature: undefined proc_binder_check_status_print(void)
// callers: []
//------------------------------------------------------------

void proc_binder_check_status_print
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  seq_printf(param_1,"from %d:%d to %d:%d %d %d\n",param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// proc_binder_check_status_show_detail @ 00101428 size=1132
// signature: undefined proc_binder_check_status_show_detail(void)
// callers: [proc_binder_check_status_show]
//------------------------------------------------------------

void proc_binder_check_status_show_detail(undefined8 param_1,long param_2,int param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long *plVar13;
  
  lVar1 = param_2 + 0x248;
  _raw_spin_lock();
  lVar3 = rb_first(param_2 + 0x10);
  if (lVar3 == 0) {
    plVar13 = (long *)0x0;
  }
  else {
    do {
      puVar10 = *(undefined8 **)(lVar3 + 0x40);
      plVar13 = (long *)(lVar3 + -8);
      if (*(long *)(lVar3 + 0x1a0) != 0) {
        for (; puVar10 != (undefined8 *)(lVar3 + 0x40); puVar10 = (undefined8 *)*puVar10) {
          if (puVar10 != (undefined8 *)0x0) {
            iVar4 = *(int *)(puVar10 + 2);
            if ((iVar4 == 1) && (puVar10 != (undefined8 *)0x8)) {
              _raw_spin_lock(puVar10 + 0x13);
              plVar9 = (long *)puVar10[3];
              if (plVar9 == (long *)0x0) {
                uVar11 = 0xffffffff;
              }
              else {
                if (plVar9[0x35] == 0) {
                  lVar7 = *plVar9;
                  if (lVar7 == 0) {
                    plVar9 = plVar9 + 6;
                  }
                  else if (*(long *)(lVar7 + 0x48) == 0) {
                    plVar9 = (long *)(lVar7 + 0x40);
                  }
                  else {
                    plVar9 = (long *)(*(long *)(lVar7 + 0x48) + 0x634);
                  }
                }
                else {
                  plVar9 = (long *)(plVar9[0x35] + 0x634);
                }
                uVar11 = (undefined4)*plVar9;
              }
              plVar9 = (long *)puVar10[7];
              iVar4 = *(int *)((long)puVar10 + 0x74);
              if (((plVar9 == (long *)0x0) ||
                  ((lVar7 = plVar9[0x35], lVar7 == 0 &&
                   ((*plVar9 == 0 || (lVar7 = *(long *)(*plVar9 + 0x48), lVar7 == 0)))))) &&
                 ((puVar10[6] == 0 || (lVar7 = *(long *)(puVar10[6] + 0x48), lVar7 == 0)))) {
                uVar12 = 0xffffffff;
              }
              else {
                uVar12 = *(undefined4 *)(lVar7 + 0x634);
              }
              uVar6 = *(uint *)((long)puVar10 + 0x5c);
              _raw_spin_unlock(puVar10 + 0x13);
              if ((((plVar9 != (long *)0x0) && (plVar9 == plVar13)) && ((uVar6 & 1) == 0)) &&
                 (iVar4 != param_3)) {
                _raw_spin_unlock(lVar1);
                uVar5 = 0;
                goto LAB_00101830;
              }
            }
            else if ((iVar4 != 2) && (iVar4 != 5)) {
              _raw_spin_unlock(lVar1);
              iVar4 = -1;
              uVar11 = 0xffffffff;
              uVar12 = 0xffffffff;
              uVar5 = 1;
              goto LAB_00101830;
            }
          }
        }
        lVar7 = *(long *)(lVar3 + 0x38);
        if (lVar7 != 0) {
          lVar2 = lVar7 + 0xa0;
          _raw_spin_lock(lVar2);
          if ((*(long **)(lVar7 + 0x40) == (long *)0x0) || (*(long **)(lVar7 + 0x40) != plVar13)) {
            _raw_spin_unlock(lVar2);
          }
          else {
            plVar9 = *(long **)(lVar7 + 0x20);
            if (plVar9 == (long *)0x0) {
              uVar11 = 0xffffffff;
              lVar8 = *(long *)(lVar3 + 0x1a0);
              if (lVar8 == 0) goto LAB_001015f8;
LAB_00101618:
              uVar12 = *(undefined4 *)(lVar8 + 0x634);
            }
            else {
              if (plVar9[0x35] == 0) {
                lVar8 = *plVar9;
                if (lVar8 == 0) {
                  plVar9 = plVar9 + 6;
                }
                else if (*(long *)(lVar8 + 0x48) == 0) {
                  plVar9 = (long *)(lVar8 + 0x40);
                }
                else {
                  plVar9 = (long *)(*(long *)(lVar8 + 0x48) + 0x634);
                }
              }
              else {
                plVar9 = (long *)(plVar9[0x35] + 0x634);
              }
              uVar11 = (undefined4)*plVar9;
              lVar8 = *(long *)(lVar3 + 0x1a0);
              if (lVar8 != 0) goto LAB_00101618;
LAB_001015f8:
              if (((*plVar13 != 0) && (lVar8 = *(long *)(*plVar13 + 0x48), lVar8 != 0)) ||
                 ((*(long *)(lVar7 + 0x38) != 0 &&
                  (lVar8 = *(long *)(*(long *)(lVar7 + 0x38) + 0x48), lVar8 != 0))))
              goto LAB_00101618;
              uVar12 = 0xffffffff;
            }
            uVar6 = *(uint *)(lVar7 + 100);
            iVar4 = *(int *)(lVar7 + 0x7c);
            _raw_spin_unlock(lVar2);
            if (iVar4 != param_3) {
              uVar6 = (uVar6 ^ 0xffffffff) & 1;
              _raw_spin_unlock(lVar1);
              uVar5 = 2;
              goto LAB_00101834;
            }
          }
        }
      }
      lVar3 = rb_next(lVar3);
    } while (lVar3 != 0);
  }
  puVar10 = *(undefined8 **)(param_2 + 0x90);
  if (*(long *)(param_2 + 0x48) != 0) {
    for (; puVar10 != (undefined8 *)(param_2 + 0x90); puVar10 = (undefined8 *)*puVar10) {
      if (puVar10 != (undefined8 *)0x0) {
        iVar4 = *(int *)(puVar10 + 2);
        if ((iVar4 == 1) && (puVar10 != (undefined8 *)0x8)) {
          _raw_spin_lock(puVar10 + 0x13);
          plVar9 = (long *)puVar10[3];
          if (plVar9 == (long *)0x0) {
            uVar11 = 0xffffffff;
          }
          else {
            if (plVar9[0x35] == 0) {
              lVar3 = *plVar9;
              if (lVar3 == 0) {
                plVar9 = plVar9 + 6;
              }
              else if (*(long *)(lVar3 + 0x48) == 0) {
                plVar9 = (long *)(lVar3 + 0x40);
              }
              else {
                plVar9 = (long *)(*(long *)(lVar3 + 0x48) + 0x634);
              }
            }
            else {
              plVar9 = (long *)(plVar9[0x35] + 0x634);
            }
            uVar11 = (undefined4)*plVar9;
          }
          plVar9 = (long *)puVar10[7];
          iVar4 = *(int *)((long)puVar10 + 0x74);
          if (((plVar9 == (long *)0x0) ||
              ((lVar3 = plVar9[0x35], lVar3 == 0 &&
               ((*plVar9 == 0 || (lVar3 = *(long *)(*plVar9 + 0x48), lVar3 == 0)))))) &&
             ((puVar10[6] == 0 || (lVar3 = *(long *)(puVar10[6] + 0x48), lVar3 == 0)))) {
            uVar12 = 0xffffffff;
          }
          else {
            uVar12 = *(undefined4 *)(lVar3 + 0x634);
          }
          uVar6 = *(uint *)((long)puVar10 + 0x5c);
          _raw_spin_unlock(puVar10 + 0x13);
          if ((((plVar9 != (long *)0x0) && (plVar9 == plVar13)) && ((uVar6 & 1) == 0)) &&
             (iVar4 != param_3)) {
            _raw_spin_unlock(lVar1);
            uVar5 = 3;
            goto LAB_00101830;
          }
        }
        else if ((iVar4 != 2) && (iVar4 != 5)) {
          _raw_spin_unlock(lVar1);
          iVar4 = -1;
          uVar11 = 0xffffffff;
          uVar12 = 0xffffffff;
          uVar5 = 4;
LAB_00101830:
          uVar6 = 1;
LAB_00101834:
          seq_printf(param_1,"from %d:%d to %d:%d %d %d\n",iVar4,uVar11,param_3,uVar12,uVar5,uVar6);
          return;
        }
      }
    }
  }
  _raw_spin_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// proc_binder_check_status_show @ 00101898 size=196
// signature: undefined proc_binder_check_status_show(void)
// callers: []
//------------------------------------------------------------

undefined8 proc_binder_check_status_show(undefined8 param_1)

{
  int iVar1;
  long *plVar2;
  
  if ((binder_procs_lock != 0 && binder_procs != (long *)0x0) && 10000 < moto_binder_check_uid) {
    mutex_lock(binder_procs_lock);
    for (plVar2 = (long *)*binder_procs; plVar2 != (long *)0x0; plVar2 = (long *)*plVar2) {
      if (plVar2[9] != 0) {
        __rcu_read_lock();
        iVar1 = *(int *)(*(long *)(plVar2[9] + 0x830) + 4);
        __rcu_read_unlock();
        if (iVar1 == moto_binder_check_uid) {
          proc_binder_check_status_show_detail(param_1,plVar2,iVar1);
        }
      }
    }
    mutex_unlock(binder_procs_lock);
  }
  return 0;
}



//------------------------------------------------------------
// register_moto_binder_hooks @ 00101960 size=216
// signature: undefined register_moto_binder_hooks(void)
// callers: [moto_binder_status_init]
//------------------------------------------------------------

int register_moto_binder_hooks(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = tracepoint_probe_register(&__tracepoint_android_vh_binder_preset,binder_preset_handler,0);
  if (iVar1 == 0) {
    iVar1 = tracepoint_probe_register(&__tracepoint_android_vh_binder_trans,binder_trans_handler,0);
    if (iVar1 == 0) {
      iVar1 = tracepoint_probe_register
                        (&__tracepoint_android_vh_binder_reply,binder_reply_handler,0);
      if (iVar1 == 0) {
        iVar1 = tracepoint_probe_register
                          (&__tracepoint_android_vh_binder_alloc_new_buf_locked,binder_alloc_handler
                           ,0);
        if (iVar1 == 0) {
          return 0;
        }
        puVar2 = &DAT_0010324f;
      }
      else {
        puVar2 = &DAT_001030a4;
      }
    }
    else {
      puVar2 = &DAT_00102faf;
    }
  }
  else {
    puVar2 = &DAT_00103326;
  }
  _printk(puVar2,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// unregister_moto_binder_hooks @ 00101a3c size=120
// signature: undefined unregister_moto_binder_hooks(void)
// callers: []
//------------------------------------------------------------

void unregister_moto_binder_hooks(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_preset,binder_preset_handler,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_trans,binder_trans_handler,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_reply,binder_reply_handler,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_binder_alloc_new_buf_locked,binder_alloc_handler,0);
  return;
}



//------------------------------------------------------------
// moto_binder_status_init @ 00101ab8 size=160
// signature: undefined moto_binder_status_init(void)
// callers: [moto_binder_init]
//------------------------------------------------------------

int moto_binder_status_init(void)

{
  int iVar1;
  
  iVar1 = register_moto_binder_hooks();
  if (iVar1 == 0) {
    _printk(&DAT_001031c8);
  }
  else {
    tracepoint_probe_unregister(&__tracepoint_android_vh_binder_preset,binder_preset_handler,0);
    tracepoint_probe_unregister(&__tracepoint_android_vh_binder_trans,binder_trans_handler,0);
    tracepoint_probe_unregister(&__tracepoint_android_vh_binder_reply,binder_reply_handler,0);
    tracepoint_probe_unregister
              (&__tracepoint_android_vh_binder_alloc_new_buf_locked,binder_alloc_handler,0);
  }
  return iVar1;
}



//------------------------------------------------------------
// moto_binder_status_exit @ 00101b5c size=132
// signature: undefined moto_binder_status_exit(void)
// callers: [moto_binder_exit, moto_binder_init]
//------------------------------------------------------------

void moto_binder_status_exit(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_preset,binder_preset_handler,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_trans,binder_trans_handler,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_binder_reply,binder_reply_handler,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_binder_alloc_new_buf_locked,binder_alloc_handler,0);
  _printk(&DAT_00102ff5);
  return;
}



//------------------------------------------------------------
// proc_binder_status_start @ 00101c0c size=16
// signature: undefined proc_binder_status_start(void)
// callers: []
//------------------------------------------------------------

bool proc_binder_status_start(undefined8 param_1,long *param_2)

{
  return *param_2 < 1;
}



//------------------------------------------------------------
// proc_binder_status_stop @ 00101c20 size=4
// signature: undefined proc_binder_status_stop(void)
// callers: []
//------------------------------------------------------------

void proc_binder_status_stop(void)

{
  return;
}



//------------------------------------------------------------
// proc_binder_status_next @ 00101c28 size=20
// signature: undefined proc_binder_status_next(void)
// callers: []
//------------------------------------------------------------

undefined8 proc_binder_status_next(undefined8 param_1,undefined8 param_2,long *param_3)

{
  *param_3 = *param_3 + 1;
  return 0;
}



//------------------------------------------------------------
// proc_binder_check_status_start @ 00101c40 size=16
// signature: undefined proc_binder_check_status_start(void)
// callers: []
//------------------------------------------------------------

bool proc_binder_check_status_start(undefined8 param_1,long *param_2)

{
  return *param_2 < 1;
}



//------------------------------------------------------------
// proc_binder_check_status_stop @ 00101c54 size=4
// signature: undefined proc_binder_check_status_stop(void)
// callers: []
//------------------------------------------------------------

void proc_binder_check_status_stop(void)

{
  return;
}



//------------------------------------------------------------
// proc_binder_check_status_next @ 00101c5c size=20
// signature: undefined proc_binder_check_status_next(void)
// callers: []
//------------------------------------------------------------

undefined8 proc_binder_check_status_next(undefined8 param_1,undefined8 param_2,long *param_3)

{
  *param_3 = *param_3 + 1;
  return 0;
}



//------------------------------------------------------------
// proc_binder_status_enabled_read @ 00101c74 size=156
// signature: undefined proc_binder_status_enabled_read(void)
// callers: []
//------------------------------------------------------------

void proc_binder_status_enabled_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)moto_binder_status_enabled);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_binder_status_enabled_write @ 00101d14 size=432
// signature: undefined proc_binder_status_enabled_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_binder_status_enabled_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  int local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,0x10,&local_3c);
    if (iVar3 == 0) {
      moto_binder_status_enabled = local_3c;
      if (local_3c < 1) {
        moto_binder_exit();
      }
      else {
        moto_binder_init();
      }
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_binder_status_open @ 00101ee0 size=40
// signature: undefined proc_binder_status_open(void)
// callers: []
//------------------------------------------------------------

void proc_binder_status_open(undefined8 param_1,undefined8 param_2)

{
  seq_open(param_2,&proc_binder_status_op);
  return;
}



//------------------------------------------------------------
// proc_binder_check_uid_read @ 00101f0c size=156
// signature: undefined proc_binder_check_uid_read(void)
// callers: []
//------------------------------------------------------------

void proc_binder_check_uid_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char acStack_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  acStack_48[8] = '\0';
  acStack_48[9] = '\0';
  acStack_48[10] = '\0';
  acStack_48[0xb] = '\0';
  acStack_48[0xc] = '\0';
  acStack_48[0] = '\0';
  acStack_48[1] = '\0';
  acStack_48[2] = '\0';
  acStack_48[3] = '\0';
  acStack_48[4] = '\0';
  acStack_48[5] = '\0';
  acStack_48[6] = '\0';
  acStack_48[7] = '\0';
  iVar2 = snprintf(acStack_48,0xd,"%d\n",(ulong)moto_binder_check_uid);
  simple_read_from_buffer(param_2,param_3,param_4,acStack_48,(long)iVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// proc_binder_check_uid_write @ 00101fac size=412
// signature: undefined proc_binder_check_uid_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong proc_binder_check_uid_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined4 local_3c;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  if (0xb < param_3) {
    param_3 = 0xc;
  }
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_38 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  __check_object_size(&local_38,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar7 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = __arch_copy_from_user(puVar6,&local_38,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar4 == 0) {
    *(undefined1 *)((long)&local_38 + param_3) = 0;
    uVar5 = strim(&local_38);
    iVar3 = kstrtoint(uVar5,10,&local_3c);
    if (iVar3 == 0) {
      moto_binder_check_uid = local_3c;
    }
    else {
      param_3 = (ulong)iVar3;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// proc_binder_check_status_open @ 00102164 size=40
// signature: undefined proc_binder_check_status_open(void)
// callers: []
//------------------------------------------------------------

void proc_binder_check_status_open(undefined8 param_1,undefined8 param_2)

{
  seq_open(param_2,&proc_binder_check_status_op);
  return;
}



//------------------------------------------------------------
// moto_binder_send_uevent @ 001021e0 size=272
// signature: undefined moto_binder_send_uevent(void)
// callers: [binder_trans_handler, binder_reply_handler, binder_alloc_handler, moto_binder_write_status]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void moto_binder_send_uevent
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if (*(int *)(g_context + 0x30) < 0x65) {
    puVar5 = (undefined4 *)kmalloc_trace(_kobject_uevent,0xb20,0x50);
    if (puVar5 == (undefined4 *)0x0) {
      puVar6 = &DAT_001034ad;
    }
    else {
      *puVar5 = param_1;
      puVar5[1] = param_2;
      puVar5[2] = param_3;
      puVar5[3] = param_4;
      puVar5[4] = param_5;
      puVar5[5] = param_6;
      puVar5[6] = param_7;
      *(undefined8 *)(puVar5 + 8) = 0xfffffffe0;
      *(undefined4 **)(puVar5 + 10) = puVar5 + 10;
      *(undefined4 **)(puVar5 + 0xc) = puVar5 + 10;
      lVar4 = g_context;
      *(code **)(puVar5 + 0xe) = moto_binder_report_event;
      piVar1 = (int *)(lVar4 + 0x30);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (g_context != 0) {
        queue_work_on(0x20,*(undefined8 *)(g_context + 0x88));
        return;
      }
      puVar6 = &DAT_00103409;
    }
  }
  else {
    puVar6 = &DAT_00102f22;
  }
  _printk(puVar6);
  return;
}



//------------------------------------------------------------
// moto_binder_report_event @ 00102308 size=392
// signature: undefined moto_binder_report_event(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void moto_binder_report_event(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  
  lVar5 = kmalloc_trace(_net_namespace_list,0xdc0,0xa20);
  if (lVar5 != 0) {
    puVar6 = (undefined4 *)(param_1 + -0x20);
    iVar4 = add_uevent_var(lVar5,"type=%d",*puVar6);
    if ((((iVar4 == 0) &&
         (iVar4 = add_uevent_var(lVar5,"caller_uid=%d",*(undefined4 *)(param_1 + -0x1c)), iVar4 == 0
         )) && (iVar4 = add_uevent_var(lVar5,"caller_pid=%d",*(undefined4 *)(param_1 + -0x18)),
               iVar4 == 0)) &&
       (((iVar4 = add_uevent_var(lVar5,"target_uid=%d",*(undefined4 *)(param_1 + -0x14)), iVar4 == 0
         && (iVar4 = add_uevent_var(lVar5,"target_pid=%d",*(undefined4 *)(param_1 + -0x10)),
            iVar4 == 0)) &&
        ((iVar4 = add_uevent_var(lVar5,"arg1=%d",*(undefined4 *)(param_1 + -0xc)), iVar4 == 0 &&
         (iVar4 = add_uevent_var(lVar5,"arg2=%d",*(undefined4 *)(param_1 + -8)), iVar4 == 0)))))) {
      kobject_uevent_env(*(undefined8 *)(g_context + 0x68),2,lVar5 + 0x18);
      kfree(lVar5);
      kfree(puVar6);
      piVar1 = (int *)(g_context + 0x30);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      kfree(lVar5);
      kfree(puVar6);
      piVar1 = (int *)(g_context + 0x30);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      _printk(&DAT_00103040);
    }
  }
  return;
}



//------------------------------------------------------------
// moto_binder_init @ 001024b0 size=324
// signature: undefined moto_binder_init(void)
// callers: [proc_binder_status_enabled_write]
//------------------------------------------------------------

int moto_binder_init(void)

{
  int iVar1;
  
  if ((moto_binder_initialized & 1) != 0) {
    return 0;
  }
  iVar1 = moto_binder_status_init();
  if (iVar1 != 0) goto LAB_001025a4;
  iVar1 = misc_register(&DAT_00103990);
  if (iVar1 == 0) {
    iVar1 = kobject_uevent(DAT_001039c0,0);
    if (iVar1 == 0) {
      DAT_001039e0 = alloc_workqueue("moto_binder",2,1);
      if (DAT_001039e0 != 0) {
        DAT_00103988 = 0;
        g_context = &moto_binder_context;
        iVar1 = moto_netfilter_init();
        if (iVar1 == 0) {
          _printk(&DAT_00103430);
          moto_binder_initialized = 1;
          return 0;
        }
        moto_binder_uevent_exit();
        goto LAB_001025a0;
      }
      _printk(&DAT_001032a3);
      kobject_uevent(DAT_001039c0,1);
    }
    else {
      misc_deregister(&DAT_00103990);
      _printk(&DAT_00103301,iVar1);
    }
    misc_deregister(&DAT_00103990);
    iVar1 = -1;
  }
  else {
    _printk(&DAT_00103228,iVar1);
  }
LAB_001025a0:
  moto_binder_status_exit();
LAB_001025a4:
  _printk(&DAT_001031ff);
  return iVar1;
}



//------------------------------------------------------------
// moto_binder_uevent_exit @ 001025f4 size=84
// signature: undefined moto_binder_uevent_exit(void)
// callers: [moto_binder_init]
//------------------------------------------------------------

void moto_binder_uevent_exit(void)

{
  if (g_context != 0) {
    destroy_workqueue(*(undefined8 *)(g_context + 0x88));
    kobject_uevent(*(undefined8 *)(g_context + 0x68),1);
    misc_deregister(g_context + 0x38);
    g_context = 0;
  }
  return;
}



//------------------------------------------------------------
// moto_binder_exit @ 0010264c size=128
// signature: undefined moto_binder_exit(void)
// callers: [proc_binder_status_enabled_write]
//------------------------------------------------------------

void moto_binder_exit(void)

{
  if (moto_binder_initialized == '\x01') {
    moto_binder_status_exit();
    if (g_context != 0) {
      destroy_workqueue(*(undefined8 *)(g_context + 0x88));
      kobject_uevent(*(undefined8 *)(g_context + 0x68),1);
      misc_deregister(g_context + 0x38);
      g_context = 0;
    }
    moto_netfilter_deinit();
    moto_binder_initialized = '\0';
    _printk(&DAT_00103374);
  }
  return;
}



//------------------------------------------------------------
// moto_netfilter_deinit @ 001026d0 size=128
// signature: undefined moto_netfilter_deinit(void)
// callers: [moto_binder_exit]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void moto_netfilter_deinit(void)

{
  undefined8 *puVar1;
  
  rtnl_lock();
  puVar1 = _net_namespace_list;
  if (_net_namespace_list != (undefined8 *)&net_namespace_list) {
    do {
      nf_unregister_net_hooks(puVar1 + -4,&moto_binder_nf_ops,2);
      puVar1 = (undefined8 *)*puVar1;
    } while (puVar1 != (undefined8 *)&net_namespace_list);
  }
  rtnl_unlock();
  tracepoint_probe_unregister(&__tracepoint_suspend_resume,moto_binder_suspend_resume_hook,0);
  return;
}



//------------------------------------------------------------
// moto_binder_suspend_resume_hook @ 00102754 size=72
// signature: undefined moto_binder_suspend_resume_hook(void)
// callers: []
//------------------------------------------------------------

void moto_binder_suspend_resume_hook
               (undefined8 param_1,char *param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = strcmp(param_2,"suspend_enter");
  if ((iVar1 == 0) && ((param_4 & 1) == 0)) {
    global_dump_first_pkg = 1;
  }
  return;
}



//------------------------------------------------------------
// moto_netfilter_init @ 001027a0 size=284
// signature: undefined moto_netfilter_init(void)
// callers: [moto_binder_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 moto_netfilter_init(void)

{
  int iVar1;
  undefined8 *puVar2;
  
  rtnl_lock();
  puVar2 = (undefined8 *)&net_namespace_list;
  do {
    puVar2 = (undefined8 *)*puVar2;
    if (puVar2 == (undefined8 *)&net_namespace_list) {
      rtnl_unlock();
      tracepoint_probe_register(&__tracepoint_suspend_resume,moto_binder_suspend_resume_hook,0);
      _printk(&DAT_00102f7b,"moto_netfilter_init");
      return 0;
    }
    iVar1 = nf_register_net_hooks(puVar2 + -4,&moto_binder_nf_ops,2);
  } while (iVar1 == 0);
  _printk(&DAT_0010310e,"moto_netfilter_init");
  rtnl_unlock();
  tracepoint_probe_register(&__tracepoint_suspend_resume,moto_binder_suspend_resume_hook,0);
  rtnl_lock();
  puVar2 = _net_namespace_list;
  if (_net_namespace_list != (undefined8 *)&net_namespace_list) {
    do {
      nf_unregister_net_hooks(puVar2 + -4,&moto_binder_nf_ops,2);
      puVar2 = (undefined8 *)*puVar2;
    } while (puVar2 != (undefined8 *)&net_namespace_list);
  }
  rtnl_unlock();
  tracepoint_probe_unregister(&__tracepoint_suspend_resume,moto_binder_suspend_resume_hook,0);
  return 0xffffffff;
}



//------------------------------------------------------------
// moto_nf_ipv4_in @ 001028c0 size=52
// signature: undefined moto_nf_ipv4_in(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_nf_ipv4_in(undefined8 param_1,undefined8 param_2)

{
  if (global_dump_first_pkg != 0) {
    global_dump_first_pkg = 0;
    report_first_packet_after_wakeup(param_2);
  }
  return 1;
}



//------------------------------------------------------------
// moto_nf_ipv6_in @ 001028f8 size=52
// signature: undefined moto_nf_ipv6_in(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_nf_ipv6_in(undefined8 param_1,undefined8 param_2)

{
  if (global_dump_first_pkg != 0) {
    global_dump_first_pkg = 0;
    report_first_packet_after_wakeup(param_2);
  }
  return 1;
}



//------------------------------------------------------------
// report_first_packet_after_wakeup @ 0010292c size=356
// signature: undefined report_first_packet_after_wakeup(void)
// callers: [moto_nf_ipv6_in, moto_nf_ipv4_in]
//------------------------------------------------------------

void report_first_packet_after_wakeup(long param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  _STACK *p_Var5;
  _STACK *p_Var6;
  uint uVar7;
  uint uVar8;
  
  if ((((param_1 != 0) && (p_Var5 = *(_STACK **)(param_1 + 0x18), p_Var5 != (_STACK *)0x0)) &&
      ((*(char *)((long)&p_Var5->sorted + 2) != '\f' ||
       (p_Var5 = *(_STACK **)(p_Var5 + 3), p_Var5 != (_STACK *)0x0)))) &&
     ((1 << (ulong)(*(byte *)((long)&p_Var5->sorted + 2) & 0x1f) & 0xffffefbfU) != 0)) {
    p_Var6 = p_Var5 + 4;
    uVar7 = p_Var6->num;
    if (p_Var6->num == 0) {
      uVar8 = 0;
    }
    else {
      do {
        Hint_Prefetch(p_Var6,2,0,1);
        do {
          uVar1 = p_Var6->num;
          if (uVar1 != uVar7) break;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(p_Var6,0x10);
          if (bVar4) {
            p_Var6->num = uVar7 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        uVar8 = uVar7;
      } while ((uVar7 != uVar1) && (uVar8 = 0, uVar7 = uVar1, uVar1 != 0));
    }
    if ((int)(uVar8 + 1 | uVar8) < 0) {
      refcount_warn_saturate(p_Var6,0);
    }
    if (uVar8 != 0) {
      uVar7 = p_Var5[0x12].num;
      Hint_Prefetch(p_Var6,2,0,1);
      do {
        iVar2 = p_Var6->num;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(p_Var6,0x10);
        if (bVar4) {
          p_Var6->num = iVar2 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (iVar2 == 1) {
        DataMemoryBarrier(2,1);
        sk_free(p_Var5);
      }
      else if (iVar2 < 1) {
        refcount_warn_saturate(p_Var6,3);
      }
      if (0x270 < uVar7 >> 4) {
        moto_binder_write_status(4,0,0,uVar7,0,0,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001036d4 size=340
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  
  d_moto_binder = proc_mkdir("moto_binder",0);
  if (d_moto_binder == 0) {
    _printk(&DAT_0010306e);
  }
  else {
    lVar1 = proc_create("binder_status_enabled",0x1b6,d_moto_binder,proc_binder_status_enabled_fops)
    ;
    if (lVar1 == 0) {
      _printk(&DAT_0010313d);
    }
    else {
      lVar1 = proc_create("binder_status",0x124,d_moto_binder,proc_binder_status_fops);
      if (lVar1 == 0) {
        _printk(&DAT_001033c1);
      }
      else {
        lVar1 = proc_create("binder_check_uid",0x1b6,d_moto_binder,proc_binder_check_uid_fops);
        if (lVar1 == 0) {
          _printk(&DAT_0010317e);
        }
        else {
          lVar1 = proc_create("binder_check_status",0x124,d_moto_binder,
                              proc_binder_check_status_fops);
          if (lVar1 != 0) {
            return 0;
          }
          _printk(&DAT_0010346e);
          remove_proc_entry("binder_check_uid",0);
        }
        remove_proc_entry("binder_status",0);
      }
      remove_proc_entry("binder_status_enabled",0);
    }
    remove_proc_entry("moto_binder",0);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// cleanup_module @ 0010382c size=76
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  remove_proc_entry("binder_status",0);
  remove_proc_entry("binder_status_enabled",d_moto_binder);
  remove_proc_entry("moto_binder",0);
  return;
}



//------------------------------------------------------------
// __rcu_read_lock @ 00105000 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [binder_trans_handler, binder_reply_handler, binder_alloc_handler, proc_binder_check_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00105008 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [binder_trans_handler, binder_reply_handler, binder_alloc_handler, proc_binder_check_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00105028 size=1
// signature: undefined __check_object_size(void)
// callers: [proc_binder_status_enabled_write, binder_trans_handler, proc_binder_check_uid_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00105038 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [proc_binder_status_enabled_write, binder_trans_handler, proc_binder_check_uid_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [proc_binder_status_enabled_write, binder_trans_handler, proc_binder_check_uid_read, proc_binder_status_enabled_read, proc_binder_check_uid_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_task_by_vpid @ 00105050 size=1
// signature: undefined find_task_by_vpid(void)
// callers: [binder_alloc_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_task_by_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105058 size=1
// signature: undefined seq_printf(void)
// callers: [proc_binder_check_status_print, proc_binder_check_status_show_detail, proc_binder_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00105060 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [proc_binder_check_status_show_detail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_first @ 00105068 size=1
// signature: undefined rb_first(void)
// callers: [proc_binder_check_status_show_detail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_first(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00105070 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [proc_binder_check_status_show_detail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_next @ 00105078 size=1
// signature: undefined rb_next(void)
// callers: [proc_binder_check_status_show_detail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105080 size=1
// signature: undefined mutex_lock(void)
// callers: [proc_binder_check_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105088 size=1
// signature: undefined mutex_unlock(void)
// callers: [proc_binder_check_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00105098 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [moto_netfilter_init, register_moto_binder_hooks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050b8 size=1
// signature: undefined _printk(void)
// callers: [moto_binder_report_event, moto_netfilter_init, moto_binder_send_uevent, moto_binder_status_exit, register_moto_binder_hooks, moto_binder_status_init, moto_binder_exit, init_module, moto_binder_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001050c0 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [moto_netfilter_deinit, moto_netfilter_init, moto_binder_status_exit, moto_binder_status_init, unregister_moto_binder_hooks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 001050c8 size=1
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
// proc_create @ 001050d0 size=1
// signature: undefined proc_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 001050d8 size=1
// signature: undefined remove_proc_entry(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001050e0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [proc_binder_check_uid_read, proc_binder_status_enabled_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 001050e8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [proc_binder_check_uid_read, proc_binder_status_enabled_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strim @ 001050f0 size=1
// signature: undefined strim(void)
// callers: [proc_binder_status_enabled_write, proc_binder_check_uid_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001050f8 size=1
// signature: undefined kstrtoint(void)
// callers: [proc_binder_status_enabled_write, proc_binder_check_uid_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_open @ 00105100 size=1
// signature: undefined seq_open(void)
// callers: [proc_binder_check_status_open, proc_binder_status_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105128 size=1
// signature: undefined kmalloc_trace(void)
// callers: [moto_binder_report_event, moto_binder_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105130 size=1
// signature: undefined queue_work_on(void)
// callers: [moto_binder_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 00105138 size=1
// signature: undefined add_uevent_var(void)
// callers: [moto_binder_report_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 00105140 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [moto_binder_report_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105148 size=1
// signature: undefined kfree(void)
// callers: [moto_binder_report_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 00105150 size=1
// signature: undefined misc_register(void)
// callers: [moto_binder_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent @ 00105158 size=1
// signature: undefined kobject_uevent(void)
// callers: [moto_binder_uevent_exit, moto_binder_exit, moto_binder_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00105160 size=1
// signature: undefined alloc_workqueue(void)
// callers: [moto_binder_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 00105168 size=1
// signature: undefined misc_deregister(void)
// callers: [moto_binder_uevent_exit, moto_binder_exit, moto_binder_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00105170 size=1
// signature: undefined destroy_workqueue(void)
// callers: [moto_binder_uevent_exit, moto_binder_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_lock @ 00105178 size=1
// signature: undefined rtnl_lock(void)
// callers: [moto_netfilter_deinit, moto_netfilter_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nf_unregister_net_hooks @ 00105188 size=1
// signature: undefined nf_unregister_net_hooks(void)
// callers: [moto_netfilter_deinit, moto_netfilter_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nf_unregister_net_hooks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_unlock @ 00105190 size=1
// signature: undefined rtnl_unlock(void)
// callers: [moto_netfilter_deinit, moto_netfilter_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001051a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [moto_binder_suspend_resume_hook]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nf_register_net_hooks @ 001051a8 size=1
// signature: undefined nf_register_net_hooks(void)
// callers: [moto_netfilter_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nf_register_net_hooks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_free @ 001051b0 size=1
// signature: void sk_free(_STACK * param_1)
// callers: [report_first_packet_after_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sk_free(_STACK *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 001051b8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [report_first_packet_after_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



