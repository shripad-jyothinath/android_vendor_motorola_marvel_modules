// Decompiled by Ghidra 12.2
// Program: msm_hw_fence.ko
// Image base: 00100000

//------------------------------------------------------------
// _get_client_node @ 001029b4 size=116
// signature: undefined _get_client_node(void)
// callers: []
//------------------------------------------------------------

long _get_client_node(long param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  
  mutex_lock(param_1 + 0x208);
  plVar1 = (long *)(param_1 + 0x1f8);
  do {
    plVar1 = (long *)*plVar1;
    if (plVar1 == (long *)(param_1 + 0x1f8)) {
      lVar2 = 0;
      goto LAB_00102a08;
    }
  } while (*(int *)(plVar1 + -8) != param_2);
  lVar2 = (long)(plVar1 + -8);
LAB_00102a08:
  mutex_unlock(param_1 + 0x208);
  return lVar2;
}



//------------------------------------------------------------
// hw_fence_debug_dump_fence @ 00102a2c size=100
// signature: undefined hw_fence_debug_dump_fence(void)
// callers: [msm_hw_fence_dump_fence]
//------------------------------------------------------------

void hw_fence_debug_dump_fence
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined2 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 0;
  _dump_fence_helper(param_1,param_2,&local_48,param_3,param_4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _dump_fence_helper @ 00102a90 size=516
// signature: undefined _dump_fence_helper(void)
// callers: [hw_fence_debug_dump_table, hw_fence_dbg_dump_table_rd, hw_fence_debug_dump_fence]
//------------------------------------------------------------

void _dump_fence_helper(uint param_1,undefined4 *param_2,undefined8 *param_3,undefined8 param_4,
                       undefined4 param_5)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulong unaff_x30;
  undefined8 local_88;
  undefined8 local_80;
  undefined7 uStack_78;
  undefined4 local_71;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_71 = 0;
  local_88 = 0;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    uVar5 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar5 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001169c3,"_dump_fence_helper",0x1ed,uVar5,param_2,param_3);
  }
  else {
    *(undefined2 *)(param_3 + 5) = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    *param_3 = 0;
    uVar6 = param_2[0x14];
    uVar5 = (ulong)uVar6;
    if (uVar6 != 0) {
      if (3 < uVar6) {
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00116a11,"_dump_fence_helper",0x1f5,uVar1,param_4,uVar5,3);
        uVar5 = 3;
      }
      uVar6 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_71 = 0;
      local_88 = 0;
      puVar7 = (undefined8 *)(param_2 + 0xe);
      do {
        if (0x1b < uVar6) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102c90);
          (*pcVar3)();
        }
        iVar4 = scnprintf((long)&local_88 + (ulong)uVar6,0x1b - uVar6,&DAT_00117165,*puVar7);
        uVar5 = uVar5 - 1;
        uVar6 = iVar4 + uVar6;
        puVar7 = puVar7 + 1;
      } while (uVar5 != 0);
      scnprintf(param_3,0x2a," p:[%s]",&local_88);
    }
    if (((msm_hw_fence_debug_level & param_1) != 0) && ((msm_hw_fence_debug_level >> 0x10 & 1) != 0)
       ) {
      _printk(&DAT_001185bd,"_dump_fence_helper",0x206,param_5,param_4,*param_2,param_2[1],
              *(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6)
              ,param_2[8],*(undefined8 *)(param_2 + 0xc),param_2[0x15],param_3,
              *(undefined8 *)(param_2 + 0x16),*(undefined8 *)(param_2 + 0x18),
              *(undefined8 *)(param_2 + 0x1a));
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// hw_fence_debug_dump_table @ 00102c98 size=204
// signature: undefined hw_fence_debug_dump_table(void)
// callers: [msm_hw_fence_dump_debug_data]
//------------------------------------------------------------

void hw_fence_debug_dump_table(undefined4 param_1,long param_2)

{
  int *piVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined2 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar2 = (ulong)*(uint *)(param_2 + 0x40);
  if (*(uint *)(param_2 + 0x40) != 0) {
    lVar5 = 0;
    uVar3 = 0;
    iVar4 = 0;
    do {
      piVar1 = (int *)(*(long *)(param_2 + 0x38) + lVar5);
      if (*piVar1 != 0) {
        local_50 = 0;
        local_60 = 0;
        uStack_58 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_78 = 0;
        _dump_fence_helper(param_1,piVar1,&local_78,uVar3,iVar4);
        iVar4 = iVar4 + 1;
        uVar2 = (ulong)*(uint *)(param_2 + 0x40);
      }
      uVar3 = uVar3 + 1;
      lVar5 = lVar5 + 0xa0;
    } while (uVar3 < uVar2);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// hw_fence_debug_dump_events @ 00102d68 size=380
// signature: undefined hw_fence_debug_dump_events(void)
// callers: [msm_hw_fence_dump_debug_data]
//------------------------------------------------------------

void hw_fence_debug_dump_events(undefined4 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong unaff_x30;
  undefined8 local_a8;
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
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
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
  local_a8 = 0;
  if (*(long *)(param_2 + 0x48) == 0) {
    uVar4 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar4 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001151be,"hw_fence_debug_dump_events",0x29a,uVar4);
  }
  else {
    DataSynchronizationBarrier(3,3,0);
    uVar8 = *(uint *)(param_2 + 0x50);
    if (uVar8 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = 0;
      lVar3 = 0;
      uVar4 = 0;
      uVar7 = (ulong)uVar8;
      plVar5 = *(long **)(param_2 + 0x48);
      do {
        uVar6 = uVar8;
        lVar1 = *plVar5;
        uVar2 = (uint)uVar4;
        if (lVar3 - 1U <= *plVar5 - 1U) {
          uVar6 = (uint)uVar7;
          lVar1 = lVar3;
          uVar2 = uVar9;
        }
        uVar9 = uVar2;
        lVar3 = lVar1;
        uVar7 = (ulong)uVar6;
        uVar4 = uVar4 + 1;
        plVar5 = plVar5 + 8;
      } while (uVar4 < uVar7);
      if (uVar9 < uVar8) {
        uVar8 = uVar9;
        do {
          plVar5 = (long *)(*(long *)(param_2 + 0x48) + (long)(int)uVar8 * 0x40);
          if (*plVar5 == 0) break;
          _dump_event(param_1,plVar5,&local_a8,uVar8);
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_2 + 0x50));
      }
    }
    if (uVar9 != 0) {
      uVar8 = 0;
      do {
        _dump_event(param_1,*(long *)(param_2 + 0x48) + (long)(int)uVar8 * 0x40,&local_a8,uVar8);
        uVar8 = uVar8 + 1;
      } while (uVar9 != uVar8);
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
// _dump_event @ 00102ee4 size=376
// signature: undefined _dump_event(void)
// callers: [hw_fence_debug_dump_events, hw_fence_dbg_dump_events_rd]
//------------------------------------------------------------

void _dump_event(uint param_1,undefined8 *param_2,undefined8 *param_3,undefined4 param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  undefined8 *puVar6;
  ulong unaff_x30;
  
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    uVar4 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar4 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00112fde,"_dump_event",0x27e,uVar4,param_2,param_3);
    return;
  }
  *(undefined4 *)(param_3 + 0xd) = 0;
  param_3[0xb] = 0;
  param_3[0xc] = 0;
  param_3[9] = 0;
  param_3[10] = 0;
  param_3[7] = 0;
  param_3[8] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  *param_3 = 0;
  uVar2 = *(uint *)((long)param_2 + 0xc);
  uVar4 = (ulong)uVar2;
  if (uVar2 < 0xd) {
    if (uVar2 == 0) goto LAB_00102f88;
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113021,"_dump_event",0x285,uVar1,param_4,uVar4,0xc);
    uVar4 = 0xc;
  }
  iVar5 = 0;
  puVar6 = param_2 + 2;
  do {
    iVar3 = scnprintf((long)param_3 + (long)iVar5,(long)(0x6c - iVar5),&DAT_001173cd,
                      *(undefined4 *)puVar6);
    uVar4 = uVar4 - 1;
    iVar5 = iVar3 + iVar5;
    puVar6 = (undefined8 *)((long)puVar6 + 4);
  } while (uVar4 != 0);
LAB_00102f88:
  if (((msm_hw_fence_debug_level & param_1) != 0) && ((msm_hw_fence_debug_level >> 0x10 & 1) != 0))
  {
    _printk(&DAT_001151f0,"_dump_event",0x28f,param_4,*(undefined4 *)(param_2 + 1),*param_2,
            *(undefined4 *)((long)param_2 + 0xc),param_3);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_debug_dump_queues @ 00103060 size=200
// signature: undefined hw_fence_debug_dump_queues(void)
// callers: [msm_hw_fence_dump_debug_data]
//------------------------------------------------------------

void hw_fence_debug_dump_queues(uint param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011643a,"hw_fence_debug_dump_queues",0x330,uVar1,0);
  }
  else {
    if ((msm_hw_fence_debug_level & param_1) != 0 && (msm_hw_fence_debug_level & 0x10000) != 0) {
      _printk(&DAT_001134a4,"hw_fence_debug_dump_queues",0x334,*param_2);
    }
    if (param_2[0x22] == 2) {
      _dump_queue(param_1,param_2,2);
    }
    _dump_queue(param_1,param_2,1);
  }
  return;
}



//------------------------------------------------------------
// _dump_queue @ 00103128 size=536
// signature: undefined _dump_queue(void)
// callers: [hw_fence_debug_dump_queues, hw_fence_dbg_dump_queues_wr]
//------------------------------------------------------------

void _dump_queue(uint param_1,undefined4 *param_2,int param_3)

{
  long *plVar1;
  undefined *puVar2;
  char *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  uVar4 = param_3 - 1;
  plVar1 = (long *)(param_2 + (ulong)uVar4 * 0xc + 10);
  if (((plVar1 == (long *)0x0 || (int)param_2[0x22] < param_3) ||
      (lVar7 = *(long *)(param_2 + (ulong)uVar4 * 0xc + 0xe), lVar7 == 0)) || (*plVar1 == 0)) {
    uVar9 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar9 = unaff_x30 | 0xffffff8000000000;
    }
    pcVar3 = "TX QUEUE";
    if (param_3 != 1) {
      pcVar3 = "RX QUEUE";
    }
    if (plVar1 == (long *)0x0) {
      uVar5 = 0;
      lVar7 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(param_2 + (ulong)uVar4 * 0xc + 0xe);
      lVar7 = *plVar1;
    }
    _printk(&DAT_00118953,"_dump_queue",0x312,uVar9,*param_2,pcVar3,plVar1,uVar5,lVar7);
  }
  else {
    DataSynchronizationBarrier(3,3,0);
    if (((msm_hw_fence_debug_level & param_1) != 0) && ((msm_hw_fence_debug_level >> 0x10 & 1) != 0)
       ) {
      pcVar3 = "TX QUEUE";
      if (param_3 != 1) {
        pcVar3 = "RX QUEUE";
      }
      _printk(&DAT_00114b36,"_dump_queue",0x31b,pcVar3,*plVar1,*(undefined4 *)(lVar7 + 0x30),
              *(undefined4 *)(lVar7 + 0x34),*(undefined4 *)(lVar7 + 0x1c),
              param_2[(ulong)uVar4 * 0xc + 0xc]);
    }
    uVar4 = param_2[(ulong)uVar4 * 0xc + 0xc];
    if (0x3f < uVar4) {
      iVar8 = 0;
      uVar9 = 0;
      puVar2 = &UNK_00116e77;
      if (param_3 != 1) {
        puVar2 = &DAT_00113a98;
      }
      uVar6 = msm_hw_fence_debug_level;
      do {
        if (((uVar6 & param_1) != 0) && ((uVar6 >> 0x10 & 1) != 0)) {
          lVar7 = *plVar1 + uVar9;
          _printk(&DAT_001158a5,"_dump_queue",0x328,puVar2,iVar8,*(undefined8 *)(lVar7 + 0x18),
                  *(undefined8 *)(lVar7 + 8),*(undefined8 *)(lVar7 + 0x10),
                  *(undefined8 *)(lVar7 + 0x20),*(undefined8 *)(lVar7 + 0x28),
                  *(undefined4 *)(lVar7 + 0x30),*(undefined8 *)(lVar7 + 0x34));
          uVar6 = msm_hw_fence_debug_level;
        }
        uVar9 = uVar9 + 0x40;
        iVar8 = iVar8 + 1;
      } while (((ulong)uVar4 & 0xffffffc0) != uVar9);
    }
  }
  return;
}



//------------------------------------------------------------
// process_validation_client_loopback @ 00103344 size=320
// signature: undefined process_validation_client_loopback(void)
// callers: [hw_fence_utils_process_doorbell_mask, _fence_ctl_signal]
//------------------------------------------------------------

undefined8 process_validation_client_loopback(long param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  ulong unaff_x30;
  
  uVar4 = (ulong)param_2;
  if (param_2 - 0xf < 0xfffffff9) {
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117986,"process_validation_client_loopback",0x470,uVar2,uVar4,8,0xe);
    uVar3 = 0xffffffea;
  }
  else {
    lVar1 = param_1 + 0x280;
    mutex_lock(lVar1);
    lVar5 = *(long *)(*(long *)(param_1 + 0x2b0) + uVar4 * 8);
    if (lVar5 == 0) {
      mutex_unlock(lVar1);
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011412e,"process_validation_client_loopback",0x478,uVar2,uVar4);
      uVar3 = 0xffffffea;
    }
    else {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
        _printk(&DAT_001179c9,"process_validation_client_loopback",0x47e,uVar4);
      }
      *(undefined4 *)(lVar5 + 0xf8) = 1;
      __wake_up(lVar5 + 0xe0,3,0,0);
      mutex_unlock(lVar1);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// hw_fence_debug_debugfs_register @ 00103488 size=664
// signature: undefined hw_fence_debug_debugfs_register(void)
// callers: [hw_fence_init]
//------------------------------------------------------------

undefined8 hw_fence_debug_debugfs_register(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar2 = debugfs_create_dir("hw_fence",0);
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117e89,"hw_fence_debug_debugfs_register",0x4bb,uVar1,uVar2);
    uVar3 = 0xffffffea;
    *(undefined8 *)(param_1 + 0x1d0) = 0;
  }
  else {
    __mutex_init(param_1 + 0x208,"&drv_data->debugfs_data.clients_list_lock",
                 &hw_fence_debug_debugfs_register___key);
    *(long *)(param_1 + 0x1f8) = param_1 + 0x1f8;
    *(long *)(param_1 + 0x200) = param_1 + 0x1f8;
    *(ulong *)(param_1 + 0x1d0) = uVar2;
    *(undefined1 *)(param_1 + 500) = 1;
    *(undefined4 *)(param_1 + 0x1f0) = 0x208d;
    debugfs_create_file("ipc_trigger",0x180,uVar2,param_1,&hw_fence_dbg_ipcc_fops);
    debugfs_create_file("dpu_trigger",0x180,uVar2,param_1,hw_fence_dbg_ipcc_dpu_fops);
    debugfs_create_file("hw_fence_reset_client",0x180,uVar2,param_1,hw_fence_reset_client_fops);
    debugfs_create_file("hw_fence_register_clients",0x180,uVar2,param_1,
                        hw_fence_register_clients_fops);
    debugfs_create_file("hw_fence_tx_and_signal",0x180,uVar2,param_1,
                        hw_fence_tx_and_signal_clients_fops);
    debugfs_create_file("hw_fence_create_join_fence",0x180,uVar2,param_1,
                        hw_fence_create_join_fence_fops);
    debugfs_create_bool("create_hw_fences",0x180,uVar2,param_1 + 500);
    debugfs_create_u32("sleep_range_us",0x180,uVar2,param_1 + 0x1f0);
    debugfs_create_file("hw_fence_create",0x180,uVar2,param_1,hw_fence_create_fops);
    debugfs_create_u32("hw_fence_debug_level",0x180,uVar2,&msm_hw_fence_debug_level);
    debugfs_create_file("hw_fence_dump_table",0x180,uVar2,param_1,hw_fence_dump_table_fops);
    debugfs_create_file("hw_fence_dump_queues",0x180,uVar2,param_1,hw_fence_dump_queues_fops);
    debugfs_create_file("hw_sync",0x180,uVar2,0,&hw_sync_debugfs_fops);
    debugfs_create_u64("hw_fence_lock_wake_cnt",0x180,uVar2,param_1 + 0x238);
    debugfs_create_file("hw_fence_dump_events",0x180,uVar2,param_1,hw_fence_dump_events_fops);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// hw_fence_dbg_ipcc_write @ 00103724 size=44
// signature: undefined hw_fence_dbg_ipcc_write(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_ipcc_write(void)

{
  int iVar1;
  
  iVar1 = _debugfs_ipcc_trigger();
  return (long)iVar1;
}



//------------------------------------------------------------
// _debugfs_ipcc_trigger @ 00103750 size=260
// signature: undefined _debugfs_ipcc_trigger(void)
// callers: [hw_fence_dbg_ipcc_write, hw_fence_dbg_ipcc_dpu_write]
//------------------------------------------------------------

undefined4
_debugfs_ipcc_trigger
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  iVar2 = _get_debugfs_input_client();
  if (-1 < iVar2) {
    iVar3 = hw_fence_ipcc_get_signal_id(0,iVar2);
    if (-1 < iVar3) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
        uVar4 = hw_fence_get_qtime(0);
        _printk(&DAT_00114189,"_debugfs_ipcc_trigger",0x67,iVar2,param_4,param_5,iVar3,uVar4);
      }
      hw_fence_ipcc_trigger_signal(0,param_4,param_5,iVar3);
      goto LAB_001037e4;
    }
  }
  param_3 = 0xffffffea;
LAB_001037e4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// _get_debugfs_input_client @ 00103854 size=564
// signature: undefined _get_debugfs_input_client(void)
// callers: [hw_fence_dbg_register_clients_wr, hw_fence_dbg_create_wr, hw_fence_dbg_dump_queues_wr, hw_fence_dbg_reset_client_wr, _debugfs_ipcc_trigger]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _get_debugfs_input_client(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  ulong unaff_x30;
  int local_4c;
  undefined8 local_48;
  undefined2 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  local_4c = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 0xd8) == 0)) {
    uVar7 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar7 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"_get_debugfs_input_client",0x3e,uVar7,param_1 == 0);
LAB_00103a60:
    iVar4 = -0x16;
  }
  else {
    *param_4 = *(long *)(param_1 + 0xd8);
    if (param_3 < 10) {
      __check_object_size(&local_48,param_3,0);
      puVar6 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
         (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
        uVar7 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar5 = param_3;
      if (uVar7 <= 0x8000000000 - param_3) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar7 = daif;
          if ((uVar7 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          puVar6 = (undefined8 *)puVar6[1];
          uVar5 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar6;
          InstructionSynchronizationBarrier();
          daif = uVar7;
        }
        uVar5 = __arch_copy_from_user(puVar6,&local_48,param_2 & 0xff7fffffffffffff,param_3);
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
      if (uVar5 == 0) {
        if (9 < param_3) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x103a70);
          (*pcVar3)();
        }
        *(undefined1 *)((long)&local_48 + param_3) = 0;
        iVar4 = kstrtouint(&local_48,0,&local_4c);
        if (iVar4 == 0) {
          iVar4 = local_4c;
          if (0xfffffd71 < local_4c - 0x28fU) goto LAB_001039ac;
          uVar7 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar7 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00117a18,"_get_debugfs_input_client",0x50,uVar7,local_4c,1,0x28f);
          goto LAB_00103a60;
        }
      }
    }
    iVar4 = -0xe;
  }
LAB_001039ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hw_fence_dbg_ipcc_dpu_write @ 00103aa4 size=96
// signature: undefined hw_fence_dbg_ipcc_dpu_write(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_ipcc_dpu_write(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(*(long *)(param_1 + 0xd8) + 0x25c);
  uVar2 = hw_fence_ipcc_get_client_virt_id(*(long *)(param_1 + 0xd8),2);
  iVar3 = _debugfs_ipcc_trigger(param_1,param_2,param_3,uVar1,uVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// hw_fence_dbg_reset_client_wr @ 00103b08 size=392
// signature: undefined hw_fence_dbg_reset_client_wr(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_fence_dbg_reset_client_wr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  iVar2 = _get_debugfs_input_client();
  if (-1 < iVar2) {
    mutex_lock(0x208);
    plVar6 = (long *)0x1f8;
    do {
      plVar6 = (long *)*plVar6;
      if (plVar6 == (long *)0x1f8) {
        mutex_unlock(0x208);
        goto LAB_00103bfc;
      }
    } while (*(int *)(plVar6 + -8) != iVar2);
    mutex_unlock(0x208);
    if (((plVar6 != (long *)0x40) && (uVar4 = plVar6[-5], uVar4 != 0)) &&
       (uVar4 < 0xfffffffffffff001)) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00113088,"hw_fence_dbg_reset_client_wr",0xcb,iVar2);
        uVar4 = plVar6[-5];
      }
      iVar3 = msm_hw_fence_reset_client(uVar4,0);
      if (iVar3 != 0) {
        uVar4 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar4 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00117a58,"hw_fence_dbg_reset_client_wr",0xce,uVar4,iVar2);
      }
      goto LAB_00103c34;
    }
LAB_00103bfc:
    uVar4 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar4 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001155f0,"hw_fence_dbg_reset_client_wr",199,uVar4,iVar2);
  }
  param_3 = 0xffffffffffffffea;
LAB_00103c34:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_register_clients_wr @ 00103c94 size=508
// signature: undefined hw_fence_dbg_register_clients_wr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
hw_fence_dbg_register_clients_wr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  long lVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  ulong unaff_x30;
  
  lVar8 = sp_el0;
  lVar8 = *(long *)(lVar8 + 0x638);
  iVar4 = _get_debugfs_input_client();
  if (-1 < iVar4) {
    mutex_lock(0x208);
    plVar9 = (long *)0x1f8;
    do {
      plVar9 = (long *)*plVar9;
      if (plVar9 == (long *)0x1f8) {
        mutex_unlock(0x208);
        goto LAB_00103d5c;
      }
    } while (*(int *)(plVar9 + -8) != iVar4);
    mutex_unlock(0x208);
    if (plVar9 == (long *)0x40) {
LAB_00103d5c:
      piVar5 = (int *)kmalloc_trace(_dma_fence_release,0xdc0,0x50);
      if (piVar5 == (int *)0x0) {
        param_3 = 0xfffffffffffffff4;
      }
      else {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00113d75,"hw_fence_dbg_register_clients_wr",0xf4,iVar4);
        }
        uVar6 = msm_hw_fence_register(iVar4,piVar5 + 8);
        *(ulong *)(piVar5 + 6) = uVar6;
        if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
          uVar6 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar6 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00116a68,"hw_fence_dbg_register_clients_wr",0xf8,uVar6,iVar4);
          param_3 = 0xfffffffffffffff2;
          piVar5[6] = 0;
          piVar5[7] = 0;
        }
        else {
          uVar7 = dma_fence_context_alloc(1);
          *(undefined8 *)(piVar5 + 2) = uVar7;
          *piVar5 = iVar4;
          mutex_lock(0x208);
          piVar3 = piRam00000000000001f8;
          piVar1 = piVar5 + 0x10;
          uVar6 = __list_add_valid(piVar1,0x1f8,piRam00000000000001f8);
          if ((uVar6 & 1) != 0) {
            *(int **)(piVar3 + 2) = piVar1;
            *(int **)(piVar5 + 0x10) = piVar3;
            piVar5[0x12] = 0x1f8;
            piVar5[0x13] = 0;
            piRam00000000000001f8 = piVar1;
          }
          mutex_unlock(0x208);
        }
      }
      goto LAB_00103df8;
    }
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001123a9,"hw_fence_dbg_register_clients_wr",0xec,uVar6,iVar4);
  }
  param_3 = 0xffffffffffffffea;
LAB_00103df8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_tx_and_signal_clients_wr @ 00103e94 size=1316
// signature: undefined hw_fence_dbg_tx_and_signal_clients_wr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong hw_fence_dbg_tx_and_signal_clients_wr(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  undefined *puVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  long *plVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  ulong unaff_x30;
  undefined8 local_88;
  uint local_7c;
  undefined8 local_78;
  undefined2 local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_7c = 0;
  local_88 = 0;
  local_70 = 0;
  local_78 = 0;
  if ((param_1 == 0) || (lVar14 = *(long *)(param_1 + 0xd8), lVar14 == 0)) {
    uVar13 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar13 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_tx_and_signal_clients_wr",0x120,uVar13);
    param_3 = 0xffffffffffffffea;
  }
  else {
    if (param_3 < 10) {
      __check_object_size(&local_78,param_3,0);
      puVar11 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_2, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
        uVar13 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar8 = param_3;
      if (uVar13 <= 0x8000000000 - param_3) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar8 = daif;
            daif = uVar8 | 0xc0;
          }
          puVar11 = (undefined8 *)puVar11[1];
          uVar8 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar11 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar11;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        uVar8 = __arch_copy_from_user(puVar11,&local_78,param_2 & 0xff7fffffffffffff,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
      }
      if (uVar8 == 0) {
        if (9 < param_3) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x1043a0);
          (*pcVar6)();
        }
        *(undefined1 *)((long)&local_78 + param_3) = 0;
        iVar7 = kstrtouint(&local_78,0,&local_7c);
        if (iVar7 == 0) {
          if (local_7c == 0) {
            uVar13 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar13 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00117a8f,"hw_fence_dbg_tx_and_signal_clients_wr",0x131,uVar13);
            param_3 = 0;
          }
          else {
            if (200 < local_7c) {
              uVar13 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar13 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_001130b5,"hw_fence_dbg_tx_and_signal_clients_wr",0x135,uVar13,local_7c,
                      200);
              local_7c = 200;
            }
            lVar1 = lVar14 + 0x208;
            mutex_lock(lVar1);
            plVar2 = (long *)(lVar14 + 0x1f8);
            plVar12 = plVar2;
            do {
              plVar12 = (long *)*plVar12;
              if (plVar12 == plVar2) {
                lVar15 = 0;
                goto LAB_001040b8;
              }
            } while (*(int *)(plVar12 + -8) != 2);
            lVar15 = (long)(plVar12 + -8);
LAB_001040b8:
            mutex_unlock(lVar1);
            mutex_lock(lVar1);
            plVar12 = plVar2;
            do {
              plVar12 = (long *)*plVar12;
              if (plVar12 == plVar2) {
                plVar12 = (long *)0x0;
                goto LAB_001040f0;
              }
            } while ((int)plVar12[-8] != 3);
            plVar12 = plVar12 + -8;
LAB_001040f0:
            mutex_unlock(lVar1);
            if (((((lVar15 == 0) || (plVar12 == (long *)0x0)) ||
                 (uVar13 = *(ulong *)(lVar15 + 0x18), uVar13 == 0)) ||
                ((0xfffffffffffff000 < uVar13 || (uVar8 = plVar12[3], uVar8 == 0)))) ||
               (0xfffffffffffff000 < uVar8)) {
              uVar13 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar13 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00115a64,"hw_fence_dbg_tx_and_signal_clients_wr",0x143,uVar13,2,3);
              param_3 = 0xffffffffffffffea;
            }
            else if ((*(char *)(lVar14 + 500) != '\0') && (local_7c != 0)) {
              while( true ) {
                uVar10 = *(undefined8 *)(lVar15 + 8);
                lVar1 = *(long *)(lVar15 + 0x10);
                *(long *)(lVar15 + 0x10) = lVar1 + 1;
                iVar7 = hw_fence_create(lVar14,uVar13,uVar10,lVar1,&local_88);
                if (iVar7 != 0) break;
                hw_fence_update_queue(lVar14,uVar13,uVar10,lVar1,local_88,0,0,0,0);
                iVar7 = hw_fence_register_wait_client(lVar14,0,uVar8,uVar10,lVar1,&local_88,0);
                if (iVar7 != 0) {
                  uVar13 = unaff_x30 & 0xff80007fffffffff;
                  if ((unaff_x30 & 0x80000000000000) != 0) {
                    uVar13 = unaff_x30 | 0xffffff8000000000;
                  }
                  _printk(&DAT_00116e7a,"hw_fence_dbg_tx_and_signal_clients_wr",0x169,uVar13);
                  param_3 = 0xffffffffffffffea;
                  goto LAB_00103ffc;
                }
                uVar3 = *(undefined4 *)(lVar14 + 0x25c);
                uVar4 = *(undefined4 *)(lVar14 + 600);
                if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
                  _printk(&DAT_0011491c,"hw_fence_dbg_tx_and_signal_clients_wr",0x17f,2,uVar3,uVar4,
                          2,*(undefined4 *)(lVar14 + 0x1f0),local_7c);
                }
                hw_fence_ipcc_trigger_signal(lVar14,uVar3,uVar4,2);
                usleep_range_state(*(int *)(lVar14 + 0x1f0),*(int *)(lVar14 + 0x1f0) + 5,2);
                iVar7 = hw_fence_destroy(lVar14,uVar13,uVar10,lVar1);
                if (iVar7 != 0) {
                  puVar9 = &DAT_00114bc0;
                  uVar10 = 0x192;
                  goto code_r0x00104380;
                }
                local_7c = local_7c - 1;
                if ((*(char *)(lVar14 + 500) == '\0') || (local_7c == 0)) goto LAB_00103ffc;
              }
              puVar9 = &DAT_00114b8b;
              uVar10 = 0x15a;
code_r0x00104380:
              uVar13 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar13 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(puVar9,"hw_fence_dbg_tx_and_signal_clients_wr",uVar10,uVar13);
            }
          }
          goto LAB_00103ffc;
        }
      }
    }
    param_3 = 0xfffffffffffffff2;
  }
LAB_00103ffc:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_create_join_fence @ 001043d4 size=1588
// signature: undefined hw_fence_dbg_create_join_fence(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 hw_fence_dbg_create_join_fence(long param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  undefined4 *puVar8;
  long lVar9;
  undefined4 *puVar10;
  long lVar11;
  undefined8 uVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong unaff_x30;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 *local_88;
  long local_80;
  undefined8 uStack_78;
  long local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  local_88 = (undefined8 *)0x0;
  local_98 = 0;
  if ((param_1 == 0) || (lVar14 = *(long *)(param_1 + 0xd8), lVar14 == 0)) {
    uVar15 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar15 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_create_join_fence",0x3fe,uVar15);
    param_3 = 0xffffffffffffffea;
    goto LAB_00104914;
  }
  lVar16 = lVar14 + 0x208;
  mutex_lock(lVar16);
  plVar6 = (long *)(lVar14 + 0x1f8);
  plVar13 = plVar6;
  do {
    plVar13 = (long *)*plVar13;
    if (plVar13 == plVar6) {
      lVar17 = 0;
      goto LAB_00104468;
    }
  } while (*(int *)(plVar13 + -8) != 2);
  lVar17 = (long)(plVar13 + -8);
LAB_00104468:
  mutex_unlock(lVar16);
  mutex_lock(lVar16);
  plVar13 = plVar6;
  do {
    plVar13 = (long *)*plVar13;
    if (plVar13 == plVar6) {
      plVar13 = (long *)0x0;
      goto LAB_0010449c;
    }
  } while ((int)plVar13[-8] != 3);
  plVar13 = plVar13 + -8;
LAB_0010449c:
  mutex_unlock(lVar16);
  if (((((lVar17 == 0) || (plVar13 == (long *)0x0)) ||
       (uVar15 = *(ulong *)(lVar17 + 0x18), uVar15 == 0)) ||
      ((0xfffffffffffff000 < uVar15 || (plVar13[3] == 0)))) ||
     (0xfffffffffffff000 < (ulong)plVar13[3])) {
    uVar15 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar15 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001173f1,"hw_fence_dbg_create_join_fence",0x409,uVar15,2,3);
    param_3 = 0xffffffffffffffea;
    goto LAB_00104914;
  }
  plVar6 = (long *)kmalloc_trace(_dma_fence_array_create,0xdc0,0x18);
  if (plVar6 != (long *)0x0) {
    plVar7 = (long *)kmalloc_trace(_dma_fence_array_create,0xdc0,0x18);
    if (plVar7 != (long *)0x0) {
      puVar8 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,4);
      *plVar6 = (long)puVar8;
      if (puVar8 == (undefined4 *)0x0) {
        lVar16 = 0;
LAB_001047f4:
        kfree(plVar6[lVar16]);
        kfree(plVar7[lVar16]);
        if (puVar8 != (undefined4 *)0x0) {
          lVar14 = lVar16 + -1;
          if ((0x17 < (ulong)(lVar14 * 8)) || (kfree(plVar6[lVar14]), 0x17 < (ulong)(lVar14 * 8))) {
LAB_001049d4:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x1049d8);
            (*pcVar4)();
          }
          kfree(plVar7[lVar14]);
          if (lVar14 != 0) {
            lVar16 = lVar16 + -2;
            if ((0x17 < (ulong)(lVar16 * 8)) || (kfree(plVar6[lVar16]), 0x17 < (ulong)(lVar16 * 8)))
            goto LAB_001049d4;
            kfree(plVar7[lVar16]);
          }
        }
        kfree(plVar6);
        plVar6 = plVar7;
      }
      else {
        lVar9 = kmalloc_trace(_dma_fence_context_alloc,0xdc0,0x88);
        if (lVar9 != 0) {
          *plVar7 = lVar9;
          uVar12 = *(undefined8 *)(lVar17 + 8);
          lVar16 = 1;
          *puVar8 = 0;
          dma_fence_init(lVar9,hw_fence_dbg_ops,puVar8,uVar12,1);
          puVar10 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,4);
          plVar6[1] = (long)puVar10;
          if (puVar10 == (undefined4 *)0x0) goto LAB_001047f4;
          lVar11 = kmalloc_trace(_dma_fence_context_alloc,0xdc0,0x88);
          if (lVar11 == 0) {
            lVar14 = 1;
            goto LAB_00104890;
          }
          *puVar10 = 0;
          plVar7[1] = lVar11;
          lVar16 = 2;
          dma_fence_init(lVar11,hw_fence_dbg_ops,puVar10,*(undefined8 *)(lVar17 + 8),2);
          puVar10 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,4);
          plVar6[2] = (long)puVar10;
          if (puVar10 == (undefined4 *)0x0) goto LAB_001047f4;
          lVar16 = kmalloc_trace(_dma_fence_context_alloc,0xdc0,0x88);
          if (lVar16 == 0) {
            lVar14 = 2;
            goto LAB_00104890;
          }
          *puVar10 = 0;
          plVar7[2] = lVar16;
          dma_fence_init(lVar16,hw_fence_dbg_ops,puVar10,*(undefined8 *)(lVar17 + 8),3);
          lVar16 = dma_fence_array_create(3,plVar7,*(undefined8 *)(lVar17 + 8),4,0);
          if (lVar16 == 0) {
            uVar15 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar15 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00115ac6,"hw_fence_dbg_create_join_fence",0x432,uVar15);
            _cleanup_fences(2,plVar7,plVar6);
            param_3 = 0xffffffffffffffea;
            goto LAB_00104914;
          }
          local_80 = *plVar7;
          local_88 = &local_98;
          iVar5 = msm_hw_fence_create(*(undefined8 *)(lVar17 + 0x18),&local_90);
          if (iVar5 == 0) {
            hw_fence_update_queue(lVar14,uVar15,*(undefined8 *)(lVar17 + 8),1,local_98,0,0,0,0);
            local_80 = plVar7[1];
            local_88 = &local_98;
            iVar5 = msm_hw_fence_create(*(undefined8 *)(lVar17 + 0x18),&local_90);
            if (iVar5 != 0) goto LAB_00104950;
            hw_fence_update_queue(lVar14,uVar15,*(undefined8 *)(lVar17 + 8),2,local_98,0,0,0,0);
            local_80 = plVar7[2];
            local_88 = &local_98;
            iVar5 = msm_hw_fence_create(*(undefined8 *)(lVar17 + 0x18),&local_90);
            if (iVar5 != 0) goto LAB_00104950;
            hw_fence_update_queue(lVar14,uVar15,*(undefined8 *)(lVar17 + 8),3,local_98,0,0,0,0);
            local_70 = lVar16;
            msm_hw_fence_wait_update_v2(plVar13[3],&local_70,0,0,1,1);
            hw_fence_ipcc_trigger_signal
                      (lVar14,*(undefined4 *)(lVar14 + 0x25c),*(undefined4 *)(lVar14 + 600),2);
            usleep_range_state(*(int *)(lVar14 + 0x1f0),*(int *)(lVar14 + 0x1f0) + 5,2);
          }
          else {
LAB_00104950:
            uVar15 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar15 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00114b8b,"hw_fence_dbg_create_join_fence",0x43e,uVar15);
            param_3 = 0xffffffffffffffea;
          }
          piVar1 = (int *)(lVar16 + 0x38);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar5 = *piVar1;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar3) {
              *piVar1 = iVar5 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (iVar5 == 1) {
            DataMemoryBarrier(2,1);
            dma_fence_release();
          }
          else if (iVar5 < 1) {
            refcount_warn_saturate(piVar1,3);
          }
          kfree(plVar6);
          goto LAB_00104914;
        }
        lVar14 = 0;
LAB_00104890:
        kfree(plVar6[lVar14]);
        kfree(plVar7[lVar14]);
        if (lVar9 != 0) {
          lVar16 = lVar14 + -1;
          if ((0x17 < (ulong)(lVar16 * 8)) || (kfree(plVar6[lVar16]), 0x17 < (ulong)(lVar16 * 8)))
          goto LAB_001049d4;
          kfree(plVar7[lVar16]);
          if (lVar16 != 0) {
            lVar14 = lVar14 + -2;
            if ((0x17 < (ulong)(lVar14 * 8)) || (kfree(plVar6[lVar14]), 0x17 < (ulong)(lVar14 * 8)))
            goto LAB_001049d4;
            kfree(plVar7[lVar14]);
          }
        }
        kfree(plVar6);
        plVar6 = plVar7;
      }
    }
    kfree(plVar6);
  }
  param_3 = 0xfffffffffffffff4;
LAB_00104914:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// _cleanup_fences @ 00104a18 size=100
// signature: undefined _cleanup_fences(void)
// callers: [hw_fence_dbg_create_join_fence]
//------------------------------------------------------------

void _cleanup_fences(uint param_1,long param_2,long param_3)

{
  bool bVar1;
  long lVar2;
  
  if (-1 < (int)param_1) {
    lVar2 = (ulong)param_1 << 3;
    do {
      kfree(*(undefined8 *)(param_3 + lVar2));
      kfree(*(undefined8 *)(param_2 + lVar2));
      bVar1 = lVar2 != 0;
      lVar2 = lVar2 + -8;
    } while (bVar1);
  }
  kfree(param_3);
  kfree(param_2);
  return;
}



//------------------------------------------------------------
// dma_fence_put @ 00104a7c size=96
// signature: undefined dma_fence_put(void)
// callers: [hw_fence_dbg_create_wr]
//------------------------------------------------------------

void dma_fence_put(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  piVar1 = (int *)(param_1 + 0x38);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 == 1) {
    DataMemoryBarrier(2,1);
    dma_fence_release();
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_dbg_get_driver_name @ 00104af0 size=8
// signature: undefined hw_fence_dbg_get_driver_name(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_get_driver_name(long param_1)

{
  return param_1 + 0x40;
}



//------------------------------------------------------------
// hw_fence_dbg_get_timeline_name @ 00104afc size=8
// signature: undefined hw_fence_dbg_get_timeline_name(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_get_timeline_name(long param_1)

{
  return param_1 + 0x40;
}



//------------------------------------------------------------
// hw_fence_dbg_enable_signaling @ 00104b08 size=8
// signature: undefined hw_fence_dbg_enable_signaling(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_fence_dbg_enable_signaling(void)

{
  return 1;
}



//------------------------------------------------------------
// hw_fence_dbg_release @ 00104b14 size=236
// signature: undefined hw_fence_dbg_release(void)
// callers: []
//------------------------------------------------------------

void hw_fence_dbg_release(undefined8 *param_1)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00114bf7,"hw_fence_dbg_release",0xbd,param_1);
    iVar1 = (int)param_1[6];
  }
  else {
    iVar1 = (int)param_1[6];
  }
  if (iVar1 < 0) {
    uVar2 = param_1[0x10];
    if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
      puVar3 = &DAT_00116aaa;
      uVar4 = 0xad;
    }
    else {
      iVar1 = msm_hw_fence_destroy(uVar2,param_1);
      if (iVar1 == 0) goto LAB_00104b68;
      puVar3 = &DAT_00114633;
      uVar4 = 0xb3;
    }
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(puVar3,"_hw_fence_release",uVar4,uVar2);
  }
LAB_00104b68:
  kfree(*param_1);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// hw_fence_dbg_create_wr @ 00104c04 size=612
// signature: undefined hw_fence_dbg_create_wr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 hw_fence_dbg_create_wr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  int param3;
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  ulong unaff_x30;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  undefined8 *local_70;
  long local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  local_70 = (undefined8 *)0x0;
  local_88 = 0;
  local_80 = 0;
  param3 = _get_debugfs_input_client();
  lVar5 = local_80;
  if (-1 < param3) {
    lVar1 = local_80 + 0x208;
    mutex_lock(lVar1);
    plVar7 = (long *)(lVar5 + 0x1f8);
    do {
      plVar7 = (long *)*plVar7;
      if (plVar7 == (long *)(lVar5 + 0x1f8)) {
        mutex_unlock(lVar1);
        goto LAB_00104d84;
      }
    } while (*(int *)(plVar7 + -8) != param3);
    mutex_unlock(lVar1);
    if (((plVar7 == (long *)0x40) || (plVar7[-5] == 0)) || (0xfffffffffffff000 < (ulong)plVar7[-5]))
    {
LAB_00104d84:
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001155f0,"hw_fence_dbg_create_wr",0x1bb,uVar2,param3);
    }
    else {
      puVar4 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,4);
      if (puVar4 == (undefined4 *)0x0) {
        param_3 = 0xfffffffffffffff4;
        goto LAB_00104dbc;
      }
      lVar5 = kmalloc_trace(_dma_fence_context_alloc,0xdc0,0x88);
      if (lVar5 == 0) {
        kfree(puVar4);
        param_3 = 0xfffffffffffffff4;
        goto LAB_00104dbc;
      }
      snprintf((char *)(lVar5 + 0x40),0x40,"hwfence:id:%d:ctx=%lu:seqno:%lu",param3,plVar7[-7],
               hw_fence_dbg_create_wr_hw_fence_dbg_seqno);
      uVar2 = hw_fence_dbg_create_wr_hw_fence_dbg_seqno;
      uVar6 = plVar7[-7];
      *puVar4 = 0;
      dma_fence_init(lVar5,hw_fence_dbg_ops,puVar4,uVar6,uVar2);
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00113da0,"hw_fence_dbg_create_wr",0x1d2,param3,plVar7[-7],
                hw_fence_dbg_create_wr_hw_fence_dbg_seqno);
      }
      local_70 = &local_88;
      local_68 = lVar5;
      iVar3 = msm_hw_fence_create(plVar7[-5],&local_78);
      if (iVar3 == 0) {
        hw_fence_dbg_create_wr_hw_fence_dbg_seqno = hw_fence_dbg_create_wr_hw_fence_dbg_seqno + 1;
        *(long *)(lVar5 + 0x80) = plVar7[-5];
        goto LAB_00104dbc;
      }
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00113100,"hw_fence_dbg_create_wr",0x1d8,uVar2,param3,plVar7[-7],
              hw_fence_dbg_create_wr_hw_fence_dbg_seqno);
      dma_fence_put(lVar5);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00104dbc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_dump_table_rd @ 00104e6c size=1436
// signature: undefined hw_fence_dbg_dump_table_rd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_fence_dbg_dump_table_rd(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  ulong uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  int *piVar13;
  ulong uVar14;
  ulong unaff_x30;
  ulong local_a8 [6];
  undefined2 local_78;
  long local_70;
  
  lVar12 = sp_el0;
  local_70 = *(long *)(lVar12 + 0x638);
  if ((param_1 == 0) || (lVar12 = *(long *)(param_1 + 0xd8), lVar12 == 0)) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_dump_table_rd",0x373,uVar6);
    lVar12 = -0x16;
    goto LAB_0010523c;
  }
  if (*(long *)(lVar12 + 0x38) == 0) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001182da,"hw_fence_dbg_dump_table_rd",0x379,uVar6);
    lVar12 = -0x16;
    goto LAB_0010523c;
  }
  if (*(uint *)(lVar12 + 0x40) <= hw_fence_dbg_dump_table_rd_index) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_0011677f,"hw_fence_dbg_dump_table_rd",0x37e);
    }
    lVar12 = 0;
    hw_fence_dbg_dump_table_rd_index = 0;
    hw_fence_dbg_dump_table_rd_cnt = 0;
    goto LAB_0010523c;
  }
  if (param_3 < 0xa0) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001123f3,"hw_fence_dbg_dump_table_rd",0x385,uVar6,param_3,0xa0);
    lVar12 = -0x16;
    goto LAB_0010523c;
  }
  lVar4 = kmalloc_trace(___copy_overflow,0xdc0,0x1000);
  if (lVar4 == 0) {
    lVar12 = -0xc;
    goto LAB_0010523c;
  }
  if (*(char *)(lVar12 + 0x1d8) == '\0') {
    uVar6 = 0;
    do {
      iVar3 = hw_fence_dbg_dump_table_rd_cnt;
      uVar8 = (ulong)hw_fence_dbg_dump_table_rd_index;
      do {
        if ((*(uint *)(lVar12 + 0x40) <= uVar8) || (iVar10 = (int)uVar6, 0xf5f < iVar10)) {
          hw_fence_dbg_dump_table_rd_index = (int)uVar8 + 1;
          goto LAB_00105128;
        }
        lVar9 = *(long *)(lVar12 + 0x38);
        uVar14 = uVar8 + 1 & 0xffffffff;
        uVar8 = uVar8 + 1;
        piVar13 = (int *)(lVar9 + uVar14 * 0xa0);
      } while (*piVar13 == 0);
      hw_fence_dbg_dump_table_rd_index = (uint)uVar8;
      local_78 = 0;
      local_a8[4] = 0;
      local_a8[5] = 0;
      local_a8[2] = 0;
      local_a8[3] = 0;
      local_a8[1] = 0;
      _dump_fence_helper(4,piVar13,local_a8 + 1,uVar14);
      lVar9 = lVar9 + uVar14 * 0xa0;
      iVar3 = scnprintf(lVar4 + iVar10,(long)(0x1000 - iVar10),
                        "[%d]hfence[%d] v:%d err:%lu ctx:%llu seq:%llu wait:0x%llx alloc:%d f:0x%llx child_cnt:%d%s ct:%llu tt:%llu wt:%llu\n"
                        ,iVar3,uVar8 & 0xffffffff,*piVar13,*(undefined4 *)(lVar9 + 4),
                        *(undefined8 *)(lVar9 + 8),*(undefined8 *)(lVar9 + 0x10),
                        *(undefined8 *)(lVar9 + 0x18),*(undefined4 *)(lVar9 + 0x20),
                        *(undefined8 *)(lVar9 + 0x30),*(undefined4 *)(lVar9 + 0x54),local_a8 + 1,
                        *(undefined8 *)(lVar9 + 0x58),*(undefined8 *)(lVar9 + 0x60),
                        *(undefined8 *)(lVar9 + 0x68));
      uVar6 = (ulong)(uint)(iVar3 + iVar10);
      hw_fence_dbg_dump_table_rd_cnt = hw_fence_dbg_dump_table_rd_cnt + 1;
    } while( true );
  }
  uVar1 = *(undefined8 *)(lVar12 + 0x1e0);
  uVar2 = *(undefined8 *)(lVar12 + 0x1e8);
  local_a8[0] = 0;
  puVar5 = (undefined4 *)msm_hw_fence_find(lVar12,0,uVar1,uVar2,local_a8);
  uVar6 = local_a8[0];
  if (puVar5 == (undefined4 *)0x0) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011865f,"dump_single_entry",0x23d,uVar6,uVar1,uVar2,local_a8[0]);
    uVar6 = scnprintf(lVar4,0x1000,"no valid hfence found for context:%lu seqno:%lu hash:%lu\n",
                      uVar1,uVar2,local_a8[0]);
  }
  else {
    local_78 = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[1] = 0;
    _dump_fence_helper(4,puVar5,local_a8 + 1,local_a8[0] & 0xffffffff,0);
    uVar6 = scnprintf(lVar4,0x1000,
                      "[%d]hfence[%d] v:%d err:%lu ctx:%llu seq:%llu wait:0x%llx alloc:%d f:0x%llx child_cnt:%d%s ct:%llu tt:%llu wt:%llu\n"
                      ,0,uVar6 & 0xffffffff,*puVar5,puVar5[1],*(undefined8 *)(puVar5 + 2),
                      *(undefined8 *)(puVar5 + 4),*(undefined8 *)(puVar5 + 6),puVar5[8],
                      *(undefined8 *)(puVar5 + 0xc),puVar5[0x15],local_a8 + 1,
                      *(undefined8 *)(puVar5 + 0x16),*(undefined8 *)(puVar5 + 0x18),
                      *(undefined8 *)(puVar5 + 0x1a));
  }
  hw_fence_dbg_dump_table_rd_index = *(uint *)(lVar12 + 0x40);
  uVar6 = uVar6 & 0xffffffff;
LAB_00105128:
  uVar11 = (uint)uVar6;
  if (((int)uVar11 < 1) || (param_3 < uVar6)) {
    uVar8 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar8 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00116af5,"hw_fence_dbg_dump_table_rd",0x392,uVar8,uVar6,param_3);
    uVar11 = 0;
  }
  else {
    if (uVar11 < 0x1001) {
      __check_object_size(lVar4,uVar6,1);
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar8 = param_2 & (long)(param_2 << 8) >> 8;
      }
      if (uVar8 <= 0x8000000000 - uVar6) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar14 = daif;
            daif = uVar14 | 0xc0;
          }
          puVar7 = (undefined8 *)puVar7[1];
          uVar14 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar14 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        lVar12 = __arch_copy_to_user(puVar7,param_2 & 0xff7fffffffffffff,lVar4,uVar6);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar14 = daif;
            daif = uVar14 | 0xc0;
          }
          uVar14 = ttbr1_el1;
          ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar14 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        if (lVar12 == 0) {
          *param_4 = *param_4 + uVar6;
          goto LAB_00105230;
        }
      }
    }
    else {
      __copy_overflow(0x1000,uVar6);
    }
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113a9b,"hw_fence_dbg_dump_table_rd",0x398,uVar6);
    uVar11 = 0xfffffff2;
  }
LAB_00105230:
  kfree(lVar4);
  lVar12 = (long)(int)uVar11;
LAB_0010523c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar12);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_dbg_dump_table_wr @ 00105424 size=644
// signature: undefined hw_fence_dbg_dump_table_wr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong hw_fence_dbg_dump_table_wr(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  ulong unaff_x30;
  ulong local_60;
  ulong uStack_58;
  char local_50 [24];
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_50[8] = '\0';
  local_50[9] = '\0';
  local_50[10] = '\0';
  local_50[0xb] = '\0';
  local_50[0xc] = '\0';
  local_50[0xd] = '\0';
  local_50[0xe] = '\0';
  local_50[0xf] = '\0';
  local_50[0x10] = '\0';
  local_50[0x11] = '\0';
  local_50[0x12] = '\0';
  local_50[0x13] = '\0';
  local_50[0x14] = '\0';
  local_50[0x15] = '\0';
  local_50[0x16] = '\0';
  local_50[0x17] = '\0';
  local_50[0] = '\0';
  local_50[1] = '\0';
  local_50[2] = '\0';
  local_50[3] = '\0';
  local_50[4] = '\0';
  local_50[5] = '\0';
  local_50[6] = '\0';
  local_50[7] = '\0';
  if ((param_1 == 0) || (lVar7 = *(long *)(param_1 + 0xd8), lVar7 == 0)) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_dump_table_wr",0x3b9,uVar6);
    param_3 = 0xffffffffffffffea;
    goto LAB_00105658;
  }
  if (param_3 < 0x18) {
    __check_object_size(local_50,param_3,0);
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar6 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar4 = param_3;
    if (uVar6 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        puVar5 = (undefined8 *)puVar5[1];
        uVar4 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      uVar4 = __arch_copy_from_user(puVar5,local_50,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    if (uVar4 == 0) {
      if (0x17 < param_3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x105690);
        (*pcVar2)();
      }
      local_50[param_3] = '\0';
      iVar3 = sscanf(local_50,"%lu %lu",&uStack_58,&local_60);
      if (iVar3 == 1) {
        *(undefined1 *)(lVar7 + 0x1d8) = 0;
        *(undefined8 *)(lVar7 + 0x1e0) = 0;
        *(undefined8 *)(lVar7 + 0x1e8) = 0;
        goto LAB_00105658;
      }
      if (iVar3 == 2) {
        *(undefined1 *)(lVar7 + 0x1d8) = 1;
        *(ulong *)(lVar7 + 0x1e0) = uStack_58;
        *(ulong *)(lVar7 + 0x1e8) = local_60;
        goto LAB_00105658;
      }
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00111e4b,"hw_fence_dbg_dump_table_wr",0x3d4,uVar6,iVar3);
    }
  }
  else {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00111e18,"hw_fence_dbg_dump_table_wr",0x3bf,uVar6,param_3,0x18);
  }
  param_3 = 0xfffffffffffffff2;
LAB_00105658:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_dump_queues_wr @ 001056c4 size=348
// signature: undefined hw_fence_dbg_dump_queues_wr(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_fence_dbg_dump_queues_wr(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulong unaff_x30;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if ((param_1 == 0) || (*(long *)(param_1 + 0xd8) == 0)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_dump_queues_wr",0x34b,uVar1);
  }
  else {
    local_40 = *(long *)(param_1 + 0xd8);
    uVar3 = _get_debugfs_input_client(param_1,param_2,param_3,&local_40);
    if (-1 < (int)uVar3) {
      puVar4 = *(undefined4 **)(*(long *)(local_40 + 0x2b0) + (ulong)uVar3 * 8);
      if (puVar4 != (undefined4 *)0x0) {
        if ((msm_hw_fence_debug_level._2_1_ & 1) != 0) {
          _printk(&DAT_001134a4,"hw_fence_debug_dump_queues",0x334,*puVar4,uVar3);
        }
        if (puVar4[0x22] == 2) {
          _dump_queue(0x10000,puVar4,2);
        }
        _dump_queue(0x10000,puVar4,1);
        goto LAB_001057cc;
      }
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001189d4,"hw_fence_dbg_dump_queues_wr",0x355,uVar1,uVar3);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_001057cc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// hw_fence_dbg_dump_events_rd @ 00105824 size=1444
// signature: undefined hw_fence_dbg_dump_events_rd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_fence_dbg_dump_events_rd(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  byte bVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  long lVar14;
  ulong unaff_x30;
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
  undefined4 local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if ((param_1 == 0) || (lVar14 = *(long *)(param_1 + 0xd8), lVar14 == 0)) {
    uVar8 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar8 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001148ec,"hw_fence_dbg_dump_events_rd",0x2b8,uVar8);
  }
  else {
    if (*(long *)(lVar14 + 0x48) != 0) {
      if ((hw_fence_dbg_dump_events_rd_wraparound == 1) &&
         ((int)hw_fence_dbg_dump_events_rd_start_index <= (int)hw_fence_dbg_dump_events_rd_index)) {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00114f64,"hw_fence_dbg_dump_events_rd",0x2c4,
                  hw_fence_dbg_dump_events_rd_index,*(undefined4 *)(lVar14 + 0x50));
        }
        lVar14 = 0;
        hw_fence_dbg_dump_events_rd_index = 0;
        hw_fence_dbg_dump_events_rd_wraparound = 0;
        hw_fence_dbg_dump_events_rd_start_time = 0;
        goto LAB_00105c40;
      }
      if (param_3 < 0x40) {
        uVar8 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar8 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_001123f3,"hw_fence_dbg_dump_events_rd",0x2cd,uVar8,param_3,0x40);
        goto LAB_00105c3c;
      }
      lVar4 = kmalloc_trace(___copy_overflow,0xdc0,0x1000);
      if (lVar4 == 0) {
        lVar14 = -0xc;
        goto LAB_00105c40;
      }
      if (hw_fence_dbg_dump_events_rd_start_time == 0) {
        DataSynchronizationBarrier(3,3,0);
        if (*(uint *)(lVar14 + 0x50) != 0) {
          uVar8 = 0;
          plVar10 = *(long **)(lVar14 + 0x48);
          lVar11 = 0;
          do {
            lVar12 = *plVar10;
            if (lVar12 - 1U < lVar11 - 1U) {
              hw_fence_dbg_dump_events_rd_start_index = (uint)uVar8;
              lVar11 = lVar12;
              hw_fence_dbg_dump_events_rd_start_time = lVar12;
            }
            uVar8 = uVar8 + 1;
            plVar10 = plVar10 + 8;
          } while (uVar8 < *(uint *)(lVar14 + 0x50));
        }
        hw_fence_dbg_dump_events_rd_index = hw_fence_dbg_dump_events_rd_start_index;
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00117ae6,"hw_fence_dbg_dump_events_rd",0x2da,*(undefined8 *)(lVar14 + 0x48),
                  hw_fence_dbg_dump_events_rd_start_index,hw_fence_dbg_dump_events_rd_start_time);
        }
      }
      uVar2 = hw_fence_dbg_dump_events_rd_index;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        uVar5 = hw_fence_get_qtime(lVar14);
        _printk(&DAT_00115226,"hw_fence_dbg_dump_events_rd",0x2dd,uVar2,uVar5);
      }
      uVar8 = 0;
      bVar6 = hw_fence_dbg_dump_events_rd_wraparound;
      while (((uVar2 = hw_fence_dbg_dump_events_rd_index, uVar13 = (uint)uVar8, (bVar6 & 1) == 0 ||
              ((int)hw_fence_dbg_dump_events_rd_index < (int)hw_fence_dbg_dump_events_rd_start_index
              )) && (uVar13 < 0xfc0))) {
        local_70 = 0;
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
        plVar10 = (long *)(*(long *)(lVar14 + 0x48) +
                          (long)(int)hw_fence_dbg_dump_events_rd_index * 0x40);
        local_d0 = 0;
        uStack_c8 = 0;
        local_d8 = 0;
        if (*plVar10 != 0) {
          _dump_event(4,plVar10,&local_d8);
          puVar7 = (undefined8 *)
                   (*(long *)(lVar14 + 0x48) + (long)(int)hw_fence_dbg_dump_events_rd_index * 0x40);
          iVar3 = scnprintf(lVar4 + uVar8,0x1000 - uVar13,"[%d][cpu:%d][%lu] data[%d]:%s\n",
                            (long)(int)hw_fence_dbg_dump_events_rd_index,*(undefined4 *)(puVar7 + 1)
                            ,*puVar7,*(undefined4 *)((long)puVar7 + 0xc),&local_d8);
          uVar8 = (ulong)(iVar3 + uVar13);
          bVar6 = hw_fence_dbg_dump_events_rd_wraparound;
        }
        hw_fence_dbg_dump_events_rd_index = hw_fence_dbg_dump_events_rd_index + 1;
        if (*(uint *)(lVar14 + 0x50) <= hw_fence_dbg_dump_events_rd_index) {
          bVar6 = 1;
          hw_fence_dbg_dump_events_rd_index = 0;
          hw_fence_dbg_dump_events_rd_wraparound = 1;
        }
      }
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        uVar5 = hw_fence_get_qtime(lVar14);
        _printk(&DAT_001160a1,"hw_fence_dbg_dump_events_rd",0x2ee,uVar2,uVar5);
        if (0 < (int)uVar13) goto LAB_00105a8c;
LAB_00105ce0:
        uVar9 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar9 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00116af5,"hw_fence_dbg_dump_events_rd",0x2f1,uVar9,uVar8,param_3);
        uVar13 = 0;
      }
      else {
        if ((int)uVar13 < 1) goto LAB_00105ce0;
LAB_00105a8c:
        if (param_3 < uVar8) goto LAB_00105ce0;
        if (uVar13 < 0x1001) {
          __check_object_size(lVar4,uVar8,1);
          puVar7 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
             (uVar9 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
            uVar9 = param_2 & (long)(param_2 << 8) >> 8;
          }
          if (0x8000000000 - uVar8 < uVar9) goto LAB_00105d74;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar1 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          lVar14 = __arch_copy_to_user(puVar7,param_2 & 0xff7fffffffffffff,lVar4,uVar8);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            uVar1 = ttbr1_el1;
            ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          if (lVar14 != 0) goto LAB_00105d74;
          *param_4 = *param_4 + uVar8;
        }
        else {
          __copy_overflow(0x1000,uVar8);
LAB_00105d74:
          uVar8 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar8 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00113a9b,"hw_fence_dbg_dump_events_rd",0x2f7,uVar8);
          uVar13 = 0xfffffff2;
        }
      }
      kfree(lVar4);
      lVar14 = (long)(int)uVar13;
      goto LAB_00105c40;
    }
    uVar8 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar8 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001151be,"hw_fence_dbg_dump_events_rd",0x2be,uVar8);
  }
LAB_00105c3c:
  lVar14 = -0x16;
LAB_00105c40:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar14);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_ipcc_get_client_virt_id @ 00105eac size=40
// signature: undefined hw_fence_ipcc_get_client_virt_id(void)
// callers: [msm_hw_fence_register, hw_fence_dbg_ipcc_dpu_write]
//------------------------------------------------------------

undefined4 hw_fence_ipcc_get_client_virt_id(long param_1,uint param_2)

{
  if ((param_1 == 0) || (*(uint *)(param_1 + 0x34) <= param_2)) {
    return 0xffffffea;
  }
  return *(undefined4 *)(*(long *)(param_1 + 0x260) + (ulong)param_2 * 0x10);
}



//------------------------------------------------------------
// hw_fence_ipcc_get_client_phys_id @ 00105ed8 size=40
// signature: undefined hw_fence_ipcc_get_client_phys_id(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

undefined4 hw_fence_ipcc_get_client_phys_id(long param_1,uint param_2)

{
  if ((param_1 == 0) || (*(uint *)(param_1 + 0x34) <= param_2)) {
    return 0xffffffea;
  }
  return *(undefined4 *)(*(long *)(param_1 + 0x260) + (ulong)param_2 * 0x10 + 4);
}



//------------------------------------------------------------
// hw_fence_ipcc_get_signal_id @ 00105f04 size=40
// signature: undefined hw_fence_ipcc_get_signal_id(void)
// callers: [msm_hw_fence_register, _debugfs_ipcc_trigger]
//------------------------------------------------------------

undefined4 hw_fence_ipcc_get_signal_id(long param_1,uint param_2)

{
  if ((param_1 == 0) || (*(uint *)(param_1 + 0x34) <= param_2)) {
    return 0xffffffea;
  }
  return *(undefined4 *)(*(long *)(param_1 + 0x260) + (ulong)param_2 * 0x10 + 8);
}



//------------------------------------------------------------
// hw_fence_ipcc_needs_rxq_update @ 00105f30 size=48
// signature: undefined hw_fence_ipcc_needs_rxq_update(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

bool hw_fence_ipcc_needs_rxq_update(long param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x34) <= param_2) {
      return false;
    }
    bVar1 = *(char *)(*(long *)(param_1 + 0x260) + (long)(int)param_2 * 0x10 + 0xc) != '\0';
  }
  return bVar1;
}



//------------------------------------------------------------
// hw_fence_ipcc_needs_ipc_irq @ 00105f64 size=44
// signature: undefined hw_fence_ipcc_needs_ipc_irq(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

bool hw_fence_ipcc_needs_ipc_irq(long param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((param_1 != 0) && (param_2 < 0x28f)) {
    bVar1 = *(char *)(*(long *)(param_1 + 0x260) + (long)param_2 * 0x10 + 0xd) != '\0';
  }
  return bVar1;
}



//------------------------------------------------------------
// hw_fence_ipcc_trigger_signal @ 00105f94 size=452
// signature: undefined hw_fence_ipcc_trigger_signal(void)
// callers: [msm_hw_fence_trigger_signal, _fence_ctl_signal, hw_fence_dbg_create_join_fence, _debugfs_ipcc_trigger, hw_fence_dbg_tx_and_signal_clients_wr, global_atomic_store]
//------------------------------------------------------------

void hw_fence_ipcc_trigger_signal(long param_1,int param_2,int param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar2 = param_4 | param_3 << 0x10;
  lVar1 = *(long *)(param_1 + 0x248) + (ulong)(uint)(param_2 << 0xc) +
          (ulong)(uint)(*(int *)(param_1 + 0x254) << 0x12) + 0xc;
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
    if (param_2 - 3U < 0x10) {
      pcVar3 = (&PTR_s_APPS_PID_00119a90)[(int)(param_2 - 3U)];
    }
    else {
      pcVar3 = "UNKNOWN_PID";
    }
    pcVar4 = "APPS_VID";
    switch(param_3) {
    case 8:
      break;
    case 9:
      pcVar4 = "GPU_VID";
      break;
    default:
      pcVar4 = "UNKNOWN_VID";
      break;
    case 0xb:
      pcVar4 = "IPE_VID";
      break;
    case 0xc:
      pcVar4 = "VPU_VID";
      break;
    case 0x19:
      pcVar4 = "DPU_VID";
      break;
    case 0x80:
      pcVar4 = "IFE0_VID";
      break;
    case 0x81:
      pcVar4 = "IFE1_VID";
      break;
    case 0x82:
      pcVar4 = "IFE2_VID";
      break;
    case 0x83:
      pcVar4 = "IFE3_VID";
      break;
    case 0x84:
      pcVar4 = "IFE4_VID";
      break;
    case 0x85:
      pcVar4 = "IFE5_VID";
      break;
    case 0x86:
      pcVar4 = "IFE6_VID";
      break;
    case 0x87:
      pcVar4 = "IFE7_VID";
    }
    _printk(&DAT_00113ad0,"hw_fence_ipcc_trigger_signal",0xfa,pcVar3,param_2,pcVar4,param_3,param_4,
            uVar2,lVar1);
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00114c3e,"hw_fence_ipcc_trigger_signal",0xfb,uVar2,lVar1);
  }
  writel_relaxed(uVar2,lVar1);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00106158 size=132
// signature: undefined writel_relaxed(void)
// callers: [hw_fence_ipcc_enable_dpu_signaling, hw_fence_ipcc_enable_signaling, hw_fence_ipcc_trigger_signal]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x106170,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1061ac,uVar1);
  return;
}



//------------------------------------------------------------
// hw_fence_ipcc_enable_signaling @ 001061e0 size=1000
// signature: undefined hw_fence_ipcc_enable_signaling(void)
// callers: [hw_fence_utils_map_ipcc]
//------------------------------------------------------------

void hw_fence_ipcc_enable_signaling(long *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  void *__dest;
  undefined8 uVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  ulong unaff_x30;
  int local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_4c = 0;
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00117f0b,"hw_fence_ipcc_enable_signaling",0x151);
  }
  iVar5 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*param_1 + 0x2e8),"qcom,hw-fence-ipc-ver",&local_4c,1,0);
  if ((iVar5 < 0) || (local_4c == 0)) {
    if (-1 < iVar5) {
      iVar5 = 0;
    }
    uVar9 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar9 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113159,"hw_fence_ipcc_enable_signaling",0x155,uVar9,iVar5);
LAB_001065bc:
    uVar6 = 0xffffffea;
  }
  else {
    if (local_4c == 0x20003) {
      *(undefined4 *)((long)param_1 + 0x25c) = 3;
      *(undefined8 *)((long)param_1 + 0x254) = 0x800000004;
      __dest = (void *)__kmalloc((ulong)*(uint *)((long)param_1 + 0x34) << 4,0xdc0);
      param_1[0x4c] = (long)__dest;
      if (__dest == (void *)0x0) {
        bVar4 = false;
      }
      else {
        memcpy(__dest,hw_fence_clients_ipc_map_v2,0xf0);
        lVar7 = 0;
        iVar5 = 0xf;
        do {
          iVar3 = *(int *)(param_1[5] + (lVar7 + 3) * 0x38 + 0x10);
          if (0 < iVar3) {
            iVar8 = 0;
            do {
              uVar2 = iVar5 + iVar8;
              if (*(uint *)((long)param_1 + 0x34) <= uVar2) {
                uVar9 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar9 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_00118a52,"_hw_fence_ipcc_init_map_with_configurable_clients",0x11d,
                        uVar9,*(undefined8 *)(param_1[5] + (lVar7 + 3) * 0x38));
                bVar4 = false;
                goto LAB_001063e0;
              }
              uVar9 = -(ulong)(uVar2 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar2 << 4;
              uVar6 = *(undefined8 *)(hw_fence_clients_ipc_map_v2 + lVar7 * 0x10 + 0xf8);
              puVar1 = (undefined8 *)(param_1[0x4c] + uVar9);
              *puVar1 = *(undefined8 *)(hw_fence_clients_ipc_map_v2 + lVar7 * 0x10 + 0xf0);
              puVar1[1] = uVar6;
              *(int *)(param_1[0x4c] + uVar9 + 8) = iVar8;
              iVar8 = iVar8 + 1;
            } while (iVar3 != iVar8);
            iVar5 = iVar5 + iVar8;
          }
          lVar7 = lVar7 + 1;
        } while (lVar7 != 10);
        bVar4 = true;
      }
LAB_001063e0:
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
        _printk(&DAT_00117478,"_hw_fence_ipcc_hwrev_init",0x142);
      }
      if (!bVar4) goto LAB_0010658c;
    }
    else {
      if (local_4c != 0x10700) {
LAB_0010658c:
        uVar9 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar9 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00113b33,"hw_fence_ipcc_enable_signaling",0x15a,uVar9);
        goto LAB_001065bc;
      }
      uVar2 = msm_hw_fence_debug_level ^ 0xffffffff;
      *(undefined4 *)((long)param_1 + 0x25c) = 8;
      *(undefined8 *)((long)param_1 + 0x254) = 0x800000002;
      param_1[0x4c] = (long)&hw_fence_clients_ipc_map;
      if ((uVar2 & 0x10008) == 0) {
        _printk(&DAT_001134e5,"_hw_fence_ipcc_hwrev_init",0x13a);
      }
    }
    local_4c = 0;
    lVar7 = param_1[0x49] + (ulong)(uint)(*(int *)((long)param_1 + 0x254) << 0x12) +
            (ulong)(uint)(*(int *)((long)param_1 + 0x25c) << 0xc) + 8;
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00114c3e,"hw_fence_ipcc_enable_signaling",0x162,0,lVar7);
    }
    writel_relaxed(local_4c,lVar7);
    local_4c = 0x80000;
    lVar7 = param_1[0x49] + (ulong)(uint)(*(int *)((long)param_1 + 0x254) << 0x12) +
            (ulong)(uint)(*(int *)((long)param_1 + 0x25c) << 0xc) + 0x14;
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00114c3e,"hw_fence_ipcc_enable_signaling",0x169,0x80000,lVar7);
    }
    writel_relaxed(local_4c,lVar7);
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_0011243b,"hw_fence_ipcc_enable_signaling",0x16c);
    }
    uVar6 = 0;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_ipcc_enable_dpu_signaling @ 001065cc size=656
// signature: undefined hw_fence_ipcc_enable_dpu_signaling(void)
// callers: [hw_fence_init_controller_signal]
//------------------------------------------------------------

undefined8 hw_fence_ipcc_enable_dpu_signaling(long param_1)

{
  int *piVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ulong unaff_x30;
  
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_001131af,"hw_fence_ipcc_enable_dpu_signaling",0x179);
  }
  if (((param_1 == 0) || (*(int *)(param_1 + 0x254) == 0)) || (*(long *)(param_1 + 0x260) == 0)) {
    uVar3 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar3 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001160dd,"hw_fence_ipcc_enable_dpu_signaling",0x17c,uVar3);
    return 0xffffffff;
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_0011831e,"hw_fence_ipcc_enable_dpu_signaling",0x180,
            *(undefined8 *)(param_1 + 0x248));
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00117449,"hw_fence_ipcc_enable_dpu_signaling",0x182);
    uVar4 = *(uint *)(param_1 + 0x34);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x34);
  }
  if (uVar4 != 0) {
    bVar5 = false;
    uVar6 = 0;
    do {
      lVar8 = *(long *)(param_1 + 0x260);
      lVar7 = (long)(int)uVar6;
      piVar1 = (int *)(lVar8 + (long)(int)uVar6 * 0x10);
      if (*piVar1 == 0x19) {
        if (!bVar5) {
          lVar2 = *(long *)(param_1 + 0x248) + (ulong)(uint)(*(int *)(param_1 + 0x254) << 0x12) +
                  (long)(*(int *)(lVar8 + lVar7 * 0x10 + 4) << 0xc) + 8;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00118a0b,"hw_fence_ipcc_enable_dpu_signaling",0x195,1,lVar2);
          }
          writel_relaxed(1,lVar2);
        }
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          lVar2 = lVar8 + lVar7 * 0x10;
          _printk(&DAT_00117f30,"hw_fence_ipcc_enable_dpu_signaling",0x19e,uVar6,*piVar1,
                  *(undefined4 *)(lVar2 + 4),*(undefined4 *)(lVar2 + 8));
        }
        lVar8 = lVar8 + lVar7 * 0x10;
        uVar4 = *(ushort *)(lVar8 + 8) | 0x80000;
        lVar8 = *(long *)(param_1 + 0x248) + (ulong)(uint)(*(int *)(param_1 + 0x254) << 0x12) +
                (long)(*(int *)(lVar8 + 4) << 0xc) + 0x14;
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00118a0b,"hw_fence_ipcc_enable_dpu_signaling",0x1a5,uVar4,lVar8);
        }
        writel_relaxed(uVar4,lVar8);
        uVar4 = *(uint *)(param_1 + 0x34);
        bVar5 = true;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_001156aa,"hw_fence_ipcc_enable_dpu_signaling",0x1a9);
  }
  return 0;
}



//------------------------------------------------------------
// hw_fence_get_qtime @ 00106860 size=60
// signature: undefined hw_fence_get_qtime(void)
// callers: [_hw_fence_cb, hw_fence_dbg_dump_events_rd, msm_hw_fence_driver_doorbell_sim, _debugfs_ipcc_trigger]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_fence_get_qtime(void)

{
  code *pcVar1;
  
  if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10688c);
    (*pcVar1)();
  }
  (*_arch_timer_read_counter)();
  return;
}



//------------------------------------------------------------
// _get_queue_type @ 001068a0 size=28
// signature: undefined _get_queue_type(void)
// callers: []
//------------------------------------------------------------

undefined * _get_queue_type(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_00118ad6;
  if (param_1 != 1) {
    puVar1 = &DAT_0011420d;
  }
  return puVar1;
}



//------------------------------------------------------------
// hw_fence_read_queue @ 001068c0 size=212
// signature: undefined hw_fence_read_queue(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

undefined8 hw_fence_read_queue(undefined4 *param_1,long param_2,uint param_3)

{
  ulong uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (((param_2 == 0) || (param_1 == (undefined4 *)0x0)) || (1 < (int)param_3)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00118351,"hw_fence_read_queue",0xd6,uVar1,param_3,param_1,param_2);
    uVar3 = 0xffffffea;
  }
  else {
    if (2 < param_3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106994);
      (*pcVar2)();
    }
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00113b6f,"hw_fence_read_queue",0xdb,*param_1,param_1 + (ulong)param_3 * 0xc + 10)
      ;
    }
    uVar3 = hw_fence_read_queue_helper(param_1 + (ulong)param_3 * 0xc + 10,param_2);
  }
  return uVar3;
}



//------------------------------------------------------------
// hw_fence_read_queue_helper @ 00106998 size=660
// signature: undefined hw_fence_read_queue_helper(void)
// callers: [hw_fence_read_queue, hw_fence_utils_process_doorbell_mask]
//------------------------------------------------------------

ulong hw_fence_read_queue_helper(long *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  ulong unaff_x30;
  
  lVar12 = param_1[2];
  uVar6 = *(uint *)(param_1 + 1);
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
    _printk(&DAT_00113515,"hw_fence_read_queue_helper",0xed,0x40);
  }
  if ((param_2 == (undefined8 *)0x0) || (lVar12 == 0)) {
    uVar13 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar13 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00116ebc,"hw_fence_read_queue_helper",0xf0,uVar13);
    uVar13 = 0xffffffea;
  }
  else {
    lVar2 = lVar12 + 0x30;
    DataSynchronizationBarrier(3,3,0);
    uVar10 = readl_relaxed(lVar2);
    uVar13 = (ulong)uVar10;
    uVar11 = readl_relaxed(lVar12 + 0x34);
    iVar7 = *(int *)((long)param_1 + 0x24);
    if ((iVar7 != 0) && ((iVar8 = (int)param_1[4], iVar8 != 0 || (iVar7 != 1)))) {
      uVar13 = (ulong)((uVar10 - iVar8) * iVar7);
      uVar11 = (uVar11 - iVar8) * iVar7;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00113934,"_translate_queue_indexes_custom_to_default",0xcb,uVar13,uVar11);
      }
    }
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00112ca5,"hw_fence_read_queue_helper",0xff,lVar2,lVar12 + 0x34,uVar13,uVar11,
              param_1);
    }
    if ((uint)uVar13 == uVar11) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00115db6,"hw_fence_read_queue_helper",0x102);
        uVar13 = 0xffffffea;
      }
      else {
        uVar13 = 0xffffffea;
      }
    }
    else {
      puVar1 = (undefined8 *)(*param_1 + uVar13 * 4);
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00116114,"hw_fence_read_queue_helper",0x10a,puVar1,*param_1,param_1[3],puVar1);
      }
      uVar10 = (uint)uVar13 + 0x10;
      uVar9 = *(uint *)((long)param_1 + 0x24);
      if (uVar6 >> 2 <= uVar10) {
        uVar10 = 0;
      }
      if ((uVar9 != 0) && (((int)param_1[4] != 0 || (uVar9 != 1)))) {
        uVar6 = 0;
        if (uVar9 != 0) {
          uVar6 = uVar10 / uVar9;
        }
        uVar10 = uVar6 + (int)param_1[4];
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
          _printk(&DAT_00114c74,"hw_fence_read_queue_helper",0x11b,uVar10);
        }
      }
      uVar4 = puVar1[3];
      uVar3 = *puVar1;
      uVar5 = puVar1[1];
      param_2[2] = puVar1[2];
      param_2[3] = uVar4;
      *param_2 = uVar3;
      param_2[1] = uVar5;
      uVar4 = puVar1[7];
      uVar3 = puVar1[4];
      uVar5 = puVar1[5];
      param_2[6] = puVar1[6];
      param_2[7] = uVar4;
      param_2[4] = uVar3;
      param_2[5] = uVar5;
      writel_relaxed(uVar10,lVar2);
      DataSynchronizationBarrier(3,2,0);
      uVar13 = (ulong)(uVar10 != uVar11);
    }
  }
  return uVar13;
}



//------------------------------------------------------------
// readl_relaxed @ 00106c2c size=124
// signature: undefined readl_relaxed(void)
// callers: [hw_fence_utils_reset_queues, hw_fence_update_queue, hw_fence_read_queue_helper]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x106c74,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00106ca8 size=132
// signature: undefined writel_relaxed(void)
// callers: [hw_fence_utils_reset_queues, hw_fence_update_queue, hw_fence_read_queue_helper]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x106cc0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x106cfc,uVar1);
  return;
}



//------------------------------------------------------------
// hw_fence_update_queue @ 00106d30 size=1580
// signature: undefined hw_fence_update_queue(void)
// callers: [msm_hw_fence_update_txq, _fence_ctl_signal, hw_fence_dbg_create_join_fence, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
hw_fence_update_queue
          (long param_1,int *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,undefined4 param_8,uint param_9)

{
  long *plVar1;
  long lVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined8 uVar12;
  long lVar13;
  ulong unaff_x30;
  ulong local_a0;
  
  if (param_2[0x22] <= (int)param_9) {
    uVar10 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar10 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001186ea,"hw_fence_update_queue",0x161,uVar10,param_9,*param_2);
    return 0xffffffea;
  }
  if (2 < param_9) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10735c);
    (*pcVar7)();
  }
  plVar1 = (long *)(param_2 + (ulong)param_9 * 0xc + 10);
  if (plVar1 == (long *)0x0) {
    puVar11 = &DAT_00115e93;
    uVar10 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar10 = unaff_x30 | 0xffffff8000000000;
    }
    uVar12 = 0x130;
  }
  else {
    lVar13 = *(long *)(param_2 + (ulong)param_9 * 0xc + 0xe);
    if (lVar13 != 0) {
      uVar5 = param_2[(ulong)param_9 * 0xc + 0xc];
      lVar2 = lVar13 + 0x34;
      if ((char)param_2[(ulong)param_9 * 0xc + 0x14] != '\0') {
        lVar2 = lVar13 + 0x1c;
      }
      if (param_9 != 1) {
        local_a0 = 0;
LAB_00106e3c:
        DataSynchronizationBarrier(3,3,0);
        uVar8 = readl_relaxed(lVar13 + 0x30);
        uVar9 = readl_relaxed(lVar2);
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
          pcVar3 = "false";
          if ((char)param_2[(ulong)param_9 * 0xc + 0x14] != '\0') {
            pcVar3 = "true";
          }
          _printk(&DAT_00114fa2,"hw_fence_update_queue",0x18a,*param_2,lVar13 + 0x30,lVar2,uVar8,
                  uVar9,plVar1,param_9,pcVar3);
        }
        uVar6 = param_2[(ulong)param_9 * 0xc + 0x13];
        if ((uVar6 != 0) &&
           ((iVar4 = param_2[(ulong)param_9 * 0xc + 0x12], iVar4 != 0 || (uVar6 != 1)))) {
          uVar8 = (uVar8 - iVar4) * uVar6;
          uVar9 = (uVar9 - iVar4) * uVar6;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_00113934,"_translate_queue_indexes_custom_to_default",0xcb,uVar8,uVar9);
          }
        }
        uVar6 = 0;
        if (uVar8 < uVar9 || uVar8 - uVar9 == 0) {
          uVar6 = uVar5 >> 2;
        }
        uVar6 = uVar6 + (uVar8 - uVar9);
        if (uVar6 < 0x11) {
          uVar10 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar10 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_001174ab,"hw_fence_update_queue",0x193,uVar10,0x10);
          uVar12 = 0xffffffea;
        }
        else {
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_00111e86,"hw_fence_update_queue",0x197,uVar6,0x10);
          }
          lVar13 = *plVar1 + (ulong)uVar9 * 4;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_00116eed,"hw_fence_update_queue",0x19d,lVar13,*plVar1,
                    *(undefined8 *)(param_2 + (ulong)param_9 * 0xc + 0x10),lVar13);
          }
          uVar8 = uVar9 + 0x10;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_001183a8,"hw_fence_update_queue",0x1a3,uVar8,uVar9,0x10);
          }
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
            puVar11 = &DAT_00118ad6;
            if (param_9 != 1) {
              puVar11 = &DAT_0011420d;
            }
            _printk(&DAT_001149a5,"hw_fence_update_queue",0x1a6,*param_2,puVar11,param_5,param_3,
                    param_4,param_6,param_8);
          }
          uVar9 = param_2[(ulong)param_9 * 0xc + 0x13];
          if (uVar5 >> 2 <= uVar8) {
            uVar8 = 0;
          }
          if ((uVar9 != 0) && ((param_2[(ulong)param_9 * 0xc + 0x12] != 0 || (uVar9 != 1)))) {
            uVar5 = 0;
            if (uVar9 != 0) {
              uVar5 = uVar8 / uVar9;
            }
            uVar8 = uVar5 + param_2[(ulong)param_9 * 0xc + 0x12];
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
              _printk(&DAT_00112d12,"hw_fence_update_queue",0x1b4,uVar8);
            }
          }
          writeq_relaxed(0x40,lVar13);
          writew_relaxed(1,lVar13 + 4);
          writew_relaxed(0x100,lVar13 + 6);
          writeq_relaxed(param_3,lVar13 + 8);
          writeq_relaxed(param_4,lVar13 + 0x10);
          writeq_relaxed(param_5,lVar13 + 0x18);
          writeq_relaxed(param_6,lVar13 + 0x20);
          writeq_relaxed(param_7,lVar13 + 0x28);
          writel_relaxed(param_8,lVar13 + 0x30);
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10702c);
            (*pcVar7)();
          }
          uVar10 = (*_arch_timer_read_counter)();
          writel_relaxed(uVar10,lVar13 + 0x34);
          writel_relaxed(uVar10 >> 0x20,lVar13 + 0x38);
          DataSynchronizationBarrier(3,2,0);
          writel_relaxed(uVar8,lVar2);
          DataSynchronizationBarrier(3,2,0);
          uVar12 = 0;
        }
        if (param_9 == 1) {
          global_atomic_store(param_1,*(long *)(param_1 + 0x58) + local_a0 * 8,0);
          return uVar12;
        }
        return uVar12;
      }
      iVar4 = *param_2;
      uVar8 = iVar4 - 1;
      local_a0 = (ulong)uVar8;
      if (uVar8 < *(uint *)(param_1 + 0x60)) {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
          _printk(&DAT_00114d07,"hw_fence_update_queue",0x17b,iVar4,uVar8);
        }
        global_atomic_store(param_1,*(long *)(param_1 + 0x58) + local_a0 * 8,1);
        goto LAB_00106e3c;
      }
      puVar11 = &DAT_00114cc6;
      uVar12 = 0x178;
      uVar10 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar10 = unaff_x30 | 0xffffff8000000000;
      }
      param_9 = *(uint *)(param_1 + 0x60);
      goto LAB_00107134;
    }
    puVar11 = &DAT_00118010;
    uVar10 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar10 = unaff_x30 | 0xffffff8000000000;
    }
    uVar12 = 0x136;
  }
  _printk(puVar11,"_get_update_queue_params",uVar12,uVar10);
  iVar4 = *param_2;
  puVar11 = &DAT_001171af;
  uVar12 = 0x169;
LAB_00107134:
  _printk(puVar11,"hw_fence_update_queue",uVar12,uVar10,iVar4,param_9);
  return 0xffffffea;
}



//------------------------------------------------------------
// writeq_relaxed @ 0010735c size=124
// signature: undefined writeq_relaxed(void)
// callers: [hw_fence_update_queue]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x1073a8,uVar1);
  return;
}



//------------------------------------------------------------
// writew_relaxed @ 001073d8 size=132
// signature: undefined writew_relaxed(void)
// callers: [hw_fence_update_queue]
//------------------------------------------------------------

void writew_relaxed(undefined2 param_1,undefined2 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x10,param_2,0x1073f4,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x10,param_2,0x10742c,uVar1);
  return;
}



//------------------------------------------------------------
// hw_fence_update_existing_txq_payload @ 00107460 size=1076
// signature: undefined hw_fence_update_existing_txq_payload(void)
// callers: [msm_hw_fence_update_txq_error]
//------------------------------------------------------------

void hw_fence_update_existing_txq_payload
               (undefined8 param_1,undefined4 *param_2,long param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined8 uVar18;
  undefined *puVar19;
  long lVar20;
  long lVar21;
  undefined8 uVar22;
  uint uVar23;
  uint uVar24;
  ulong unaff_x30;
  
  lVar20 = sp_el0;
  lVar20 = *(long *)(lVar20 + 0x638);
  plVar4 = (long *)(param_2 + 10);
  if (plVar4 == (long *)0x0) {
    puVar19 = &DAT_00115e93;
    uVar18 = 0x130;
  }
  else {
    lVar21 = *(long *)(param_2 + 0xe);
    if (lVar21 != 0) {
      uVar15 = param_2[0xc];
      DataSynchronizationBarrier(3,3,0);
      lVar5 = 0x34;
      if (*(char *)(param_2 + 0x14) != '\0') {
        lVar5 = 0x1c;
      }
      iVar16 = param_2[0x13];
      uVar23 = *(uint *)(lVar21 + 0x30);
      uVar24 = *(uint *)(lVar21 + lVar5);
      if (iVar16 == 0) {
LAB_00107514:
        if (uVar23 != uVar24) {
LAB_00107600:
          puVar1 = (undefined8 *)(*plVar4 + (ulong)uVar23 * 4);
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_001183ed,"hw_fence_update_existing_txq_payload",0x1f7,*param_2,*plVar4,
                    *(undefined8 *)(param_2 + 0x10),uVar23,puVar1);
          }
          if (puVar1[3] == param_3) {
            *(undefined4 *)(puVar1 + 6) = param_4;
          }
          else {
            uVar3 = uVar23 + 0x10;
            if (uVar15 >> 2 <= uVar3) {
              uVar3 = 0;
            }
            if (uVar3 == uVar24) {
              uVar6 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar6 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00117b3a,"hw_fence_update_existing_txq_payload",0x205,uVar6,param_3);
              uVar18 = 0xffffffea;
              goto LAB_001076fc;
            }
            puVar2 = (undefined8 *)(*plVar4 + (ulong)uVar3 * 4);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
              _printk(&DAT_001183ed,"hw_fence_update_existing_txq_payload",0x20d,*param_2,*plVar4,
                      *(undefined8 *)(param_2 + 0x10),uVar3,puVar2);
            }
            if (puVar2[3] != param_3) {
              uVar6 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar6 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_0011353f,"hw_fence_update_existing_txq_payload",0x211,uVar6,param_3,
                      uVar23,uVar3);
              uVar18 = 0xffffffea;
              goto LAB_001076fc;
            }
            uVar8 = puVar2[7];
            uVar18 = puVar2[4];
            uVar9 = puVar2[5];
            uVar7 = puVar1[5];
            uVar10 = puVar1[6];
            uVar22 = puVar1[7];
            lVar21 = puVar1[3];
            uVar11 = puVar1[4];
            puVar1[6] = puVar2[6];
            puVar1[7] = uVar8;
            puVar1[4] = uVar18;
            puVar1[5] = uVar9;
            uVar18 = puVar2[2];
            uVar12 = puVar2[3];
            uVar8 = *puVar2;
            uVar13 = puVar2[1];
            *(undefined4 *)(puVar1 + 6) = param_4;
            uVar9 = puVar1[1];
            uVar14 = puVar1[2];
            puVar1[2] = uVar18;
            puVar1[3] = uVar12;
            uVar18 = *puVar1;
            *puVar1 = uVar8;
            puVar1[1] = uVar13;
            *puVar2 = uVar18;
            puVar2[1] = uVar9;
            puVar2[2] = uVar14;
            puVar2[4] = uVar11;
            puVar2[5] = uVar7;
            puVar2[6] = uVar10;
            puVar2[7] = uVar22;
            puVar2[3] = lVar21;
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
              _printk(&DAT_0011616b,"hw_fence_update_existing_txq_payload",0x21d,*param_2,uVar23,
                      uVar3,param_3,uVar9,uVar14);
            }
          }
          DataSynchronizationBarrier(3,2,0);
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
            _printk(&DAT_00112460,"hw_fence_update_existing_txq_payload",0x224,*param_2,uVar23,
                    param_3,param_4);
          }
          uVar18 = 0;
          goto LAB_001076fc;
        }
      }
      else {
        iVar17 = param_2[0x12];
        if ((iVar17 == 0) && (iVar16 == 1)) goto LAB_00107514;
        uVar23 = (uVar23 - iVar17) * iVar16;
        uVar24 = (uVar24 - iVar17) * iVar16;
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) != 0) goto LAB_00107514;
        _printk(&DAT_00113934,"_translate_queue_indexes_custom_to_default",0xcb,uVar23,uVar24);
        if (uVar23 != uVar24) goto LAB_00107600;
      }
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00115ddf,"hw_fence_update_existing_txq_payload",0x1f0,param_3);
        uVar18 = 0xffffffea;
      }
      else {
        uVar18 = 0xffffffea;
      }
      goto LAB_001076fc;
    }
    puVar19 = &DAT_00118010;
    uVar18 = 0x136;
  }
  uVar6 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar6 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(puVar19,"_get_update_queue_params",uVar18,uVar6);
  _printk(&DAT_00115006,"hw_fence_update_existing_txq_payload",0x1e1,uVar6,*param_2);
  uVar18 = 0xffffffea;
LAB_001076fc:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != lVar20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar18);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_init @ 00107898 size=1216
// signature: undefined hw_fence_init(void)
// callers: [msm_hw_fence_probe]
//------------------------------------------------------------

int hw_fence_init(long param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  uint local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  iVar4 = hw_fence_utils_parse_dt_props();
  if (iVar4 == 0) {
    iVar4 = hw_fence_utils_alloc_mem(param_1);
    if (iVar4 == 0) {
      iVar4 = init_hw_fences_queues(param_1,0,param_1 + 0xa8,param_1 + 200,2,0);
      if (iVar4 == 0) {
        local_58 = 0;
        uStack_50 = 0;
        local_5c = 0;
        iVar4 = hw_fence_utils_reserve_mem(param_1,1,&uStack_50,&local_58,&local_5c,0);
        if (iVar4 == 0) {
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00115c03,"init_global_locks",0x237,uStack_50,local_58,local_5c);
          }
          uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
          *(ulong *)(param_1 + 0x98) = (ulong)local_5c;
          *(undefined8 *)(param_1 + 0xa0) = 0;
          *(undefined8 *)(param_1 + 0x58) = local_58;
          *(undefined8 *)(param_1 + 0x88) = local_58;
          *(undefined8 *)(param_1 + 0x90) = uStack_50;
          *(uint *)(param_1 + 0x60) = local_5c >> 3;
          if ((uVar1 & 0x10008) == 0) {
            _printk(&DAT_00114211,"hw_fence_init",0x2aa);
          }
          local_58 = 0;
          uStack_50 = 0;
          local_5c = 0;
          iVar4 = hw_fence_utils_reserve_mem(param_1,2,&uStack_50,&local_58,&local_5c,0);
          if (iVar4 == 0) {
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
              _printk(&DAT_00115c03,"init_hw_fences_table",0x255,uStack_50,local_58,local_5c);
            }
            uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
            *(ulong *)(param_1 + 0x78) = (ulong)local_5c;
            *(undefined8 *)(param_1 + 0x80) = 0;
            *(undefined8 *)(param_1 + 0x38) = local_58;
            *(undefined8 *)(param_1 + 0x68) = local_58;
            *(undefined8 *)(param_1 + 0x70) = uStack_50;
            *(uint *)(param_1 + 0x40) = local_5c / 0xa0;
            if ((uVar1 & 0x10008) == 0) {
              _printk(&DAT_00114732,"init_hw_fences_table",0x264);
            }
            local_58 = 0;
            uStack_50 = 0;
            local_5c = 0;
            iVar4 = hw_fence_utils_reserve_mem(param_1,4,&uStack_50,&local_58,&local_5c,0);
            if (iVar4 == 0) {
              uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
              *(undefined8 *)(param_1 + 0x48) = local_58;
              *(uint *)(param_1 + 0x50) = local_5c >> 6;
              if ((uVar1 & 0x10008) == 0) {
                _printk(&DAT_00113617,"init_hw_fences_events",0x279,local_58,local_5c >> 6,0x40);
              }
            }
            else {
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10004) == 0) {
                _printk(&DAT_00114294,"init_hw_fences_events",0x273,iVar4);
              }
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10004) == 0) {
                _printk(&DAT_0011467e,"hw_fence_init",0x2b4);
              }
            }
            iVar4 = hw_fence_utils_map_ipcc(param_1);
            if (iVar4 == 0) {
              iVar4 = hw_fence_utils_map_qtime(param_1);
              if (iVar4 == 0) {
                iVar4 = hw_fence_debug_debugfs_register(param_1);
                if (iVar4 == 0) {
                  iVar4 = hw_fence_utils_init_virq(param_1);
                  if (iVar4 == 0) {
                    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
                      _printk(&DAT_001146ac,"hw_fence_init",0x2d3,*(undefined4 **)(param_1 + 0x128),
                              **(undefined4 **)(param_1 + 0x128));
                    }
                    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                      _printk(&DAT_00113df1,"hw_fence_init",0x2d6,*(undefined8 *)(param_1 + 0x38),
                              *(undefined4 *)(param_1 + 0x40));
                    }
                    iVar4 = 0;
                    goto LAB_00107c84;
                  }
                  puVar5 = &DAT_00115afe;
                  pcVar6 = "hw_fence_init";
                  uVar7 = 0x2ce;
                }
                else {
                  puVar5 = &DAT_001124b1;
                  pcVar6 = "hw_fence_init";
                  uVar7 = 0x2c7;
                }
              }
              else {
                puVar5 = &DAT_001164a8;
                pcVar6 = "hw_fence_init";
                uVar7 = 0x2c0;
              }
            }
            else {
              puVar5 = &DAT_001174e7;
              pcVar6 = "hw_fence_init";
              uVar7 = 0x2b9;
            }
            goto LAB_00107c70;
          }
          puVar5 = &DAT_00115ebe;
          pcVar6 = "init_hw_fences_table";
          uVar7 = 0x252;
        }
        else {
          puVar5 = &DAT_00114250;
          pcVar6 = "init_global_locks";
          uVar7 = 0x234;
        }
        uVar2 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar2 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(puVar5,pcVar6,uVar7,uVar2,iVar4);
        iVar4 = -0xc;
        goto LAB_00107c84;
      }
      puVar5 = &DAT_001162a4;
      pcVar6 = "init_ctrl_queue";
      uVar7 = 0x28a;
    }
    else {
      puVar5 = &DAT_00117f88;
      pcVar6 = "hw_fence_init";
      uVar7 = 0x29d;
    }
  }
  else {
    puVar5 = &DAT_001171ee;
    pcVar6 = "hw_fence_init";
    uVar7 = 0x296;
  }
LAB_00107c70:
  uVar2 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar2 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(puVar5,pcVar6,uVar7,uVar2);
LAB_00107c84:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hw_fence_alloc_client_resources @ 00107d5c size=248
// signature: undefined hw_fence_alloc_client_resources(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

int hw_fence_alloc_client_resources(long param_1,uint *param_2,undefined8 *param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  ulong unaff_x30;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x20) + (ulong)*param_2 * 0x10);
  if (lVar6 == 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00111ec0,"hw_fence_alloc_client_resources",0x2e4,uVar1,(ulong)*param_2);
    iVar5 = -0x16;
  }
  else {
    iVar5 = init_hw_fences_queues(param_1,3,param_2 + 2,param_2 + 10,*(undefined4 *)(lVar6 + 0x14));
    if (iVar5 == 0) {
      uVar3 = *(undefined8 *)(param_2 + 8);
      uVar2 = *(undefined8 *)(param_2 + 2);
      uVar4 = *(undefined8 *)(param_2 + 4);
      param_3[2] = *(undefined8 *)(param_2 + 6);
      param_3[3] = uVar3;
      *param_3 = uVar2;
      param_3[1] = uVar4;
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011751d,"hw_fence_alloc_client_resources",0x2ef,uVar1,*param_2);
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// init_hw_fences_queues @ 00107e54 size=1404
// signature: undefined init_hw_fences_queues(void)
// callers: [hw_fence_alloc_client_resources, hw_fence_init]
//------------------------------------------------------------

void init_hw_fences_queues
               (long param_1,int param_2,undefined8 *param_3,long param_4,uint param_5,uint param_6)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  char *pcVar4;
  char *pcVar5;
  ulong uVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  int iVar10;
  undefined8 uVar11;
  int iVar12;
  undefined4 uVar13;
  long lVar14;
  undefined4 uVar15;
  ulong uVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  int iVar20;
  ulong unaff_x30;
  int iStack_84;
  int local_80;
  uint local_7c;
  long local_78;
  undefined4 *local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  uVar16 = (ulong)param_6;
  local_78 = 0;
  local_70 = (undefined4 *)0x0;
  local_7c = 0;
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
    _printk(&DAT_00115efa,"init_hw_fences_queues",0x37,param_2,uVar16);
    if (param_2 == 3) goto LAB_00107f18;
LAB_00107ec8:
    if (param_2 != 0) {
      uVar16 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar16 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112908,"init_hw_fences_queues",0x52,uVar16,param_2);
      uVar11 = 0xffffffea;
      goto LAB_00108358;
    }
    iVar20 = *(int *)(param_1 + 0x18);
    iVar18 = 0;
    iVar12 = 0;
    iStack_84 = 0;
    bVar9 = false;
    uVar17 = 0x88;
    local_80 = 1;
    uVar13 = 0x18;
  }
  else {
    if (param_2 != 3) goto LAB_00107ec8;
LAB_00107f18:
    if ((*(uint *)(param_1 + 0x34) <= param_6) ||
       (lVar14 = *(long *)(*(long *)(param_1 + 0x20) +
                          (-(ulong)(param_6 >> 0x1f) & 0xfffffff000000000 | uVar16 << 4)),
       lVar14 == 0)) {
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112db0,"init_hw_fences_queues",0x42,uVar6,uVar16);
      uVar11 = 0xffffffea;
      goto LAB_00108358;
    }
    iStack_84 = *(int *)(lVar14 + 0x28);
    local_80 = *(int *)(lVar14 + 0x2c);
    iVar18 = *(int *)(lVar14 + 0x1c);
    iVar12 = *(int *)(lVar14 + 0x20);
    iVar20 = *(int *)(lVar14 + 0x18) << 6;
    if (local_80 == 0) {
      local_80 = 1;
    }
    bVar9 = *(char *)(lVar14 + 0x30) != '\0';
    uVar17 = iVar18 + param_5 * 0x38 + iVar12 + 0x18;
    uVar13 = 0x40;
  }
  iVar10 = hw_fence_utils_reserve_mem(param_1,param_2,&local_78,&local_70,&local_7c,uVar16);
  if (iVar10 == 0) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
      _printk(&DAT_00115c03,"init_hw_fences_queues",0x5c,local_78,local_70,local_7c);
    }
    *param_3 = local_70;
    param_3[1] = local_78;
    uVar7 = msm_hw_fence_debug_level;
    param_3[2] = (ulong)local_7c;
    param_3[3] = 0;
    if (((uVar7 ^ 0xffffffff) & 0x10008) == 0) {
      _printk(&DAT_00116bec,"init_hw_fences_queues",0x65,uVar17,iVar18,iVar12);
    }
    puVar8 = local_70;
    *local_70 = 0;
    uVar7 = msm_hw_fence_debug_level;
    local_70[5] = param_5;
    local_70[3] = 0x38;
    local_70[4] = param_5;
    local_70[1] = local_7c;
    local_70[2] = iVar18 + 0x18;
    if (((uVar7 ^ 0xffffffff) & 0x10008) == 0) {
      _printk(&DAT_001167bc,"init_hw_fences_queues",0x76);
    }
    if (0 < (int)param_5) {
      iVar18 = 0;
      lVar19 = 0;
      lVar14 = (long)local_70 + (ulong)(uint)puVar8[2];
      pcVar4 = "wr_idx=tx_wm";
      if (!bVar9) {
        pcVar4 = "wr_idx";
      }
      do {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          _printk(&DAT_001175c5,"init_hw_fences_queues",0x7a,iVar18);
        }
        puVar8 = local_70;
        *(int *)(lVar14 + 0xc) = iVar20;
        *(undefined4 *)(lVar14 + 0x10) = uVar13;
        lVar1 = local_78 + (ulong)uVar17;
        uVar15 = 1;
        if (lVar19 != 0) {
          uVar15 = 2;
        }
        *(int *)(lVar14 + 4) = (int)lVar1;
        *(undefined4 *)(lVar14 + 8) = uVar15;
        if (((iStack_84 != 0) && (lVar19 == 0)) && (*(int *)(lVar14 + 0x34) == 0)) {
          if (bVar9) {
            *(int *)(lVar14 + 0x1c) = iStack_84;
          }
          *(int *)(lVar14 + 0x30) = iStack_84;
          *(int *)(lVar14 + 0x34) = iStack_84;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00118046,"init_hw_fences_queues",0x96,uVar16,pcVar4,iStack_84);
          }
        }
        lVar2 = (long)puVar8 + (ulong)uVar17;
        plVar3 = (long *)(param_4 + lVar19);
        DataSynchronizationBarrier(3,2,0);
        *plVar3 = lVar2;
        plVar3[2] = lVar14;
        plVar3[3] = lVar1;
        *(int *)(plVar3 + 1) = iVar20;
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          pcVar5 = "TX_QUEUE";
          if (*(int *)(lVar14 + 8) != 1) {
            pcVar5 = "RX_QUEUE";
          }
          _printk(&DAT_001142d6,"init_hw_fences_queues",0xa4,pcVar5,uVar16,iVar18,lVar2,lVar1,lVar14
                  ,iVar20,uVar13);
          if (lVar19 != 0) goto LAB_00108058;
LAB_001080fc:
          *(int *)(param_4 + 0x20) = iStack_84;
          *(bool *)(param_4 + 0x28) = bVar9;
          iVar12 = local_80;
        }
        else {
          if (lVar19 == 0) goto LAB_001080fc;
LAB_00108058:
          iVar12 = 1;
        }
        lVar1 = param_4 + lVar19;
        *(int *)(lVar1 + 0x24) = iVar12;
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          pcVar5 = "false";
          if (*(char *)(lVar1 + 0x28) != '\0') {
            pcVar5 = "true";
          }
          _printk(&DAT_00116556,"init_hw_fences_queues",0xb0,*(undefined4 *)(lVar1 + 0x20),iVar12,
                  pcVar5);
        }
        lVar14 = lVar14 + 0x38;
        lVar19 = lVar19 + 0x30;
        iVar18 = iVar18 + 1;
        uVar17 = uVar17 + iVar20;
      } while ((ulong)param_5 * 0x30 != lVar19);
    }
    uVar11 = 0;
  }
  else {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113989,"init_hw_fences_queues",0x59,uVar6,param_2,uVar16);
    uVar11 = 0xfffffff4;
  }
LAB_00108358:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_init_controller_signal @ 001083d4 size=248
// signature: undefined hw_fence_init_controller_signal(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

undefined8 hw_fence_init_controller_signal(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  char cVar3;
  ulong unaff_x30;
  
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 - 8U < 0x87) {
    return 0;
  }
  if (iVar2 - 2U < 6) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00118734,"hw_fence_init_controller_signal",799,iVar2,
              *(undefined1 *)(param_1 + 0x2b9));
      cVar3 = *(char *)(param_1 + 0x2b9);
    }
    else {
      cVar3 = *(char *)(param_1 + 0x2b9);
    }
    if (cVar3 == '\0') {
      *(undefined1 *)(param_1 + 0x2b9) = 1;
      hw_fence_ipcc_enable_dpu_signaling(param_1);
      return 0;
    }
  }
  else {
    if (iVar2 == 1) {
      return 0;
    }
    if (0x1ff < iVar2 - 0x8fU) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00113ba3,"hw_fence_init_controller_signal",0x334,uVar1,iVar2);
      return 0xffffffea;
    }
  }
  return 0;
}



//------------------------------------------------------------
// hw_fence_init_controller_resources @ 001084d0 size=8
// signature: undefined hw_fence_init_controller_resources(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

undefined8 hw_fence_init_controller_resources(void)

{
  return 0;
}



//------------------------------------------------------------
// hw_fence_cleanup_client @ 001084dc size=144
// signature: undefined hw_fence_cleanup_client(void)
// callers: [msm_hw_fence_deregister, msm_hw_fence_register]
//------------------------------------------------------------

void hw_fence_cleanup_client(long param_1,uint *param_2)

{
  mutex_lock(param_1 + 0x280);
  *(undefined8 *)(*(long *)(param_1 + 0x2b0) + (ulong)*param_2 * 8) = 0;
  mutex_unlock(param_1 + 0x280);
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
    _printk(&DAT_00118ae8,"hw_fence_cleanup_client",0x363,*param_2);
  }
  kfree(param_2);
  return;
}



//------------------------------------------------------------
// _get_op_mode @ 00108570 size=40
// signature: undefined _get_op_mode(void)
// callers: []
//------------------------------------------------------------

char * _get_op_mode(int param_1)

{
  if (param_1 - 1U < 4) {
    return (&PTR_s_CREATE_00119c18)[(int)(param_1 - 1U)];
  }
  return "UNKNOWN";
}



//------------------------------------------------------------
// _hw_fence_lookup_and_process @ 0010859c size=1344
// signature: undefined _hw_fence_lookup_and_process(void)
// callers: [hw_fence_destroy, hw_fence_process_fence_array, msm_hw_fence_find, hw_fence_create, hw_fence_register_wait_client, hw_fence_utils_cleanup_fence, hw_fence_destroy_with_hash]
//------------------------------------------------------------

undefined4 *
_hw_fence_lookup_and_process
          (long param_1,long param_2,long param_3,long param_4,undefined4 param_5,undefined4 param_6
          ,uint param_7,ulong *param_8)

{
  undefined4 *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  code *pcVar9;
  ulong uVar10;
  undefined4 *puVar11;
  code *pcVar12;
  ulong unaff_x30;
  
  if (((param_2 == 0) || (param_1 == 0)) || (param_8 == (ulong *)0x0)) {
    uVar7 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar7 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001121aa,"_hw_fence_lookup_and_process",0x42a,uVar7);
    puVar11 = (undefined4 *)0x0;
  }
  else {
    *param_8 = 0xffffffffffffffff;
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
      _printk(&DAT_00114a09,"_hw_fence_lookup_and_process",0x430,param_7);
    }
    uVar2 = param_7 - 1;
    if (uVar2 < 4) {
      uVar7 = (ulong)*(uint *)(param_1 + 0xc);
      if (*(uint *)(param_1 + 0xc) == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = -(ulong)(uVar2 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar2 << 3;
        pcVar9 = *(code **)((long)&PTR__reserve_hw_fence_00119bd8 + uVar10);
        pcVar12 = *(code **)((long)&PTR__is_hw_fence_free_00119bf8 + uVar10);
        uVar10 = 0;
        do {
          uVar4 = param_3 * 0x38b + param_4 * (param_3 * 2 + -1) * 0x1369;
          if (uVar10 != 0) {
            uVar4 = *param_8 + 1;
          }
          uVar3 = 0;
          if (uVar7 != 0) {
            uVar3 = uVar4 / uVar7;
          }
          uVar4 = uVar4 - uVar3 * uVar7;
          *param_8 = uVar4;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
            _printk(&DAT_00116f50,"_hw_fence_lookup_and_process",0x452,uVar4,param_3,param_4);
            uVar4 = *param_8;
          }
          if (*(uint *)(param_1 + 0xc) <= uVar4) {
            uVar7 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar7 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00113e68,"_get_hw_fence",0x396,uVar7);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
              uVar7 = *param_8;
              puVar11 = (undefined4 *)0x0;
              uVar6 = 0xbad;
              goto LAB_0010881c;
            }
LAB_00108840:
            uVar7 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar7 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00113bdc,"_hw_fence_lookup_and_process",0x45a,uVar7,param_3,param_4,
                    *param_8);
            break;
          }
          puVar11 = (undefined4 *)(param_2 + uVar4 * 0xa0);
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
            uVar7 = *param_8;
            if (puVar11 == (undefined4 *)0x0) {
              uVar6 = 0xbad;
            }
            else {
              uVar6 = *puVar11;
            }
LAB_0010881c:
            _printk(&DAT_001156db,"_hw_fence_lookup_and_process",0x457,param_2,puVar11,uVar7,uVar6);
          }
          if (puVar11 == (undefined4 *)0x0) goto LAB_00108840;
          puVar1 = puVar11 + 10;
          global_atomic_store(param_1,puVar1,1);
          if (*(int *)(pcVar12 + -4) != -0x1bc0f568) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x823a,0x10873c);
            (*pcVar9)();
          }
          uVar7 = (*pcVar12)(puVar11,param_3,param_4);
          if ((uVar7 & 1) != 0) {
            if (*(int *)(pcVar9 + -4) != -0x6749ed09) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1088b0);
              (*pcVar9)();
            }
            (*pcVar9)(param_1,puVar11,param_5,param_3,param_4,(int)*param_8,param_6);
            DataSynchronizationBarrier(3,2,0);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
              if (uVar2 < 4) {
                pcVar5 = (&PTR_s_CREATE_00119c18)[(int)uVar2];
              }
              else {
                pcVar5 = "UNKNOWN";
              }
              _printk(&DAT_001146de,"_hw_fence_lookup_and_process",0x46d,param_5,pcVar5,param_3,
                      param_4,*param_8,uVar10);
            }
            global_atomic_store(param_1,puVar1,0);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) != 0) {
              return puVar11;
            }
            uVar8 = *(undefined8 *)(puVar11 + 0xc);
            goto LAB_001089e8;
          }
          if ((((param_7 & 0xfffffffd) == 1) && (*(long *)(puVar11 + 4) == param_4)) &&
             (*(long *)(puVar11 + 2) == param_3)) {
            uVar7 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar7 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00116b7e,"_hw_fence_lookup_and_process",0x476,uVar7,param_3,param_4);
            global_atomic_store(param_1,puVar1,0);
            break;
          }
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00114d3c,"_hw_fence_lookup_and_process",0x47c,*param_8,param_3,param_4);
          }
          global_atomic_store(param_1,puVar1,0);
          uVar7 = (ulong)*(uint *)(param_1 + 0xc);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar7);
      }
      uVar7 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar7 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001161c7,"_hw_fence_lookup_and_process",0x487,uVar7,uVar10);
      puVar11 = (undefined4 *)0x0;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
        uVar8 = 0xffffffffffffffff;
LAB_001089e8:
        _printk(&DAT_001121e9,"_hw_fence_lookup_and_process",0x48c,param_7,puVar11,param_3,param_4,
                *param_8,uVar8);
      }
    }
    else {
      uVar7 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar7 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00113593,"_hw_fence_lookup_and_process",0x444,uVar7,param_7);
      puVar11 = (undefined4 *)0x0;
    }
  }
  return puVar11;
}



//------------------------------------------------------------
// _is_hw_fence_free @ 00108ae0 size=16
// signature: undefined _is_hw_fence_free(void)
// callers: []
//------------------------------------------------------------

bool _is_hw_fence_free(int *param_1)

{
  return *param_1 == 0;
}



//------------------------------------------------------------
// _reserve_hw_fence @ 00108af4 size=256
// signature: undefined _reserve_hw_fence(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _reserve_hw_fence(undefined8 param_1,undefined4 *param_2,undefined4 param_3,undefined8 param_4,
                      undefined8 param_5,undefined4 param_6)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  param_2[1] = 0;
  DataSynchronizationBarrier(3,2,0);
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined8 *)(param_2 + 0xe) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x10) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x12) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 2) = 0;
  *(undefined8 *)(param_2 + 4) = 0;
  *(undefined8 *)(param_2 + 6) = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  *param_2 = 1;
  *(undefined8 *)(param_2 + 0x14) = 0;
  *(undefined8 *)(param_2 + 0x16) = 0;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x1a) = 0;
  pcVar2 = _arch_timer_read_counter;
  *(undefined8 *)(param_2 + 0x1c) = 0;
  *(undefined8 *)(param_2 + 0x1e) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x22) = 0;
  *(undefined8 *)(param_2 + 0x24) = 0;
  *(undefined8 *)(param_2 + 0x26) = 0;
  *(undefined8 *)(param_2 + 2) = param_4;
  *(undefined8 *)(param_2 + 4) = param_5;
  *(undefined8 *)(param_2 + 0xc) = 0;
  param_2[8] = param_3;
  if (*(int *)(pcVar2 + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108b84);
    (*pcVar2)();
  }
  uVar3 = (*pcVar2)();
  *(undefined8 *)(param_2 + 0x16) = uVar3;
  uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
  *(long *)(param_2 + 0x1c) = *(long *)(param_2 + 0x1c) + 1;
  if ((uVar1 & 0x10020) == 0) {
    _printk(&DAT_00113c24,"_reserve_hw_fence",0x3d6,param_3,param_4,param_5,param_6);
  }
  return;
}



//------------------------------------------------------------
// _hw_fence_match @ 00108bf8 size=36
// signature: undefined _hw_fence_match(void)
// callers: []
//------------------------------------------------------------

bool _hw_fence_match(long param_1,long param_2,long param_3)

{
  if (*(long *)(param_1 + 8) == param_2) {
    return *(long *)(param_1 + 0x10) == param_3;
  }
  return false;
}



//------------------------------------------------------------
// _unreserve_hw_fence @ 00108c20 size=144
// signature: undefined _unreserve_hw_fence(void)
// callers: []
//------------------------------------------------------------

void _unreserve_hw_fence(undefined8 param_1,undefined4 *param_2,undefined4 param_3,
                        undefined8 param_4,undefined8 param_5,undefined4 param_6)

{
  uint uVar1;
  
  param_2[1] = 0;
  DataSynchronizationBarrier(3,2,0);
  *param_2 = 0;
  *(undefined8 *)(param_2 + 2) = 0;
  *(undefined8 *)(param_2 + 4) = 0;
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined8 *)(param_2 + 0xe) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x10) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x12) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 6) = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  *(undefined8 *)(param_2 + 0x14) = 0;
  *(undefined8 *)(param_2 + 0x16) = 0;
  uVar1 = msm_hw_fence_debug_level;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x1a) = 0;
  *(undefined8 *)(param_2 + 0x1c) = 0;
  *(undefined8 *)(param_2 + 0x1e) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x22) = 0;
  *(undefined8 *)(param_2 + 0x24) = 0;
  *(undefined8 *)(param_2 + 0x26) = 0;
  if (((uVar1 ^ 0xffffffff) & 0x10020) == 0) {
    _printk(&DAT_001172aa,"_unreserve_hw_fence",0x3e4,param_3,param_4,param_5,param_6);
  }
  return;
}



//------------------------------------------------------------
// _reserve_join_fence @ 00108cb4 size=260
// signature: undefined _reserve_join_fence(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _reserve_join_fence(undefined8 param_1,undefined4 *param_2,undefined4 param_3,
                        undefined8 param_4,undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  param_2[1] = 0;
  DataSynchronizationBarrier(3,2,0);
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined8 *)(param_2 + 0xe) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x10) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x12) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 2) = 0;
  *(undefined8 *)(param_2 + 4) = 0;
  *param_2 = 1;
  *(undefined8 *)(param_2 + 6) = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  *(undefined8 *)(param_2 + 0x14) = 0;
  *(undefined8 *)(param_2 + 0x16) = 0;
  pcVar2 = _arch_timer_read_counter;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x1a) = 0;
  *(undefined8 *)(param_2 + 0x1c) = 0;
  *(undefined8 *)(param_2 + 0x1e) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x22) = 0;
  *(undefined8 *)(param_2 + 0x24) = 0;
  *(undefined8 *)(param_2 + 0x26) = 0;
  *(undefined8 *)(param_2 + 2) = param_4;
  *(undefined8 *)(param_2 + 4) = param_5;
  param_2[8] = param_3;
  if (*(int *)(pcVar2 + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108d44);
    (*pcVar2)();
  }
  uVar3 = (*pcVar2)();
  *(undefined8 *)(param_2 + 0x16) = uVar3;
  param_2[0x15] = param_7;
  uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
  *(long *)(param_2 + 0x1c) = *(long *)(param_2 + 0x1c) + 1;
  if ((uVar1 & 0x10020) == 0) {
    _printk(&DAT_001124ee,"_reserve_join_fence",0x3fa,param_3,param_4,param_5,param_6);
  }
  return;
}



//------------------------------------------------------------
// _fence_found @ 00108dbc size=92
// signature: undefined _fence_found(void)
// callers: []
//------------------------------------------------------------

void _fence_found(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined8 param_5,undefined4 param_6)

{
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10020) == 0) {
    _printk(&DAT_00113200,"_fence_found",0x408,param_3,param_4,param_5,param_6);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_create @ 00108e1c size=160
// signature: undefined hw_fence_create(void)
// callers: [msm_hw_fence_create, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

undefined8
hw_fence_create(long param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  uVar2 = *param_2;
  lVar3 = _hw_fence_lookup_and_process
                    (param_1,*(undefined8 *)(param_1 + 0x38),param_3,param_4,uVar2,0,1,param_5);
  uVar4 = 0;
  if (lVar3 == 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115b2f,"hw_fence_create",0x49e,uVar1,uVar2,param_3,param_4);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// hw_fence_destroy @ 00108ec0 size=208
// signature: undefined hw_fence_destroy(void)
// callers: [msm_hw_fence_destroy, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

void hw_fence_destroy(long param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar2 = *param_2;
  local_40 = 0;
  lVar3 = _hw_fence_lookup_and_process
                    (param_1,*(undefined8 *)(param_1 + 0x38),param_3,param_4,uVar2,0,2,&local_40);
  uVar4 = 0;
  if (lVar3 == 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117562,"hw_fence_destroy",0x4bb,uVar1,uVar2,param_3,param_4);
    uVar4 = 0xffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_destroy_with_hash @ 00108f94 size=456
// signature: undefined hw_fence_destroy_with_hash(void)
// callers: [msm_hw_fence_destroy_with_handle]
//------------------------------------------------------------

void hw_fence_destroy_with_hash(long param_1,int *param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong unaff_x30;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  iVar2 = *param_2;
  if (param_3 < *(uint *)(param_1 + 0xc)) {
    lVar4 = *(long *)(param_1 + 0x38);
    if (lVar4 + param_3 * 0xa0 == 0) goto LAB_001090c0;
    if (*(int *)(lVar4 + param_3 * 0xa0 + 0x20) == iVar2) {
      lVar6 = lVar4 + param_3 * 0xa0;
      puVar7 = (undefined8 *)(lVar6 + 8);
      puVar5 = (undefined8 *)(lVar6 + 0x10);
      local_50 = 0;
      lVar4 = _hw_fence_lookup_and_process(param_1,lVar4,*puVar7,*puVar5,iVar2,0,2,&local_50);
      uVar3 = 0;
      if (lVar4 != 0) goto LAB_00109128;
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011288f,"hw_fence_destroy_with_hash",0x4da,uVar1,iVar2,*puVar7,*puVar5,param_3);
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00118b17,"hw_fence_destroy_with_hash",0x4d2,uVar1,iVar2,param_3);
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113e68,"_get_hw_fence",0x396,uVar1,param_3);
LAB_001090c0:
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117227,"hw_fence_destroy_with_hash",0x4cc,uVar1,param_3,iVar2);
  }
  uVar3 = 0xffffffea;
LAB_00109128:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_hw_fence_find @ 00109160 size=188
// signature: undefined msm_hw_fence_find(void)
// callers: [hw_fence_dbg_dump_table_rd, msm_hw_fence_dump_fence]
//------------------------------------------------------------

long msm_hw_fence_find(long param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5)

{
  ulong uVar1;
  long lVar2;
  undefined4 uVar3;
  ulong unaff_x30;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0xff;
  }
  else {
    uVar3 = *param_2;
  }
  lVar2 = _hw_fence_lookup_and_process
                    (param_1,*(undefined8 *)(param_1 + 0x38),param_3,param_4,uVar3,0,4,param_5);
  if (lVar2 == 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00116206,"msm_hw_fence_find",0x519,uVar1,uVar3,param_3,param_4);
  }
  return lVar2;
}



//------------------------------------------------------------
// hw_fence_process_fence_array @ 00109220 size=1976
// signature: undefined hw_fence_process_fence_array(void)
// callers: [msm_hw_fence_wait_update_v2]
//------------------------------------------------------------

void hw_fence_process_fence_array
               (long param_1,uint *param_2,long param_3,long *param_4,long param_5)

{
  ulong *puVar1;
  ulong uVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined *puVar10;
  long lVar11;
  undefined8 uVar12;
  long *plVar13;
  long lVar14;
  long lVar15;
  uint uVar16;
  uint uVar17;
  ulong uVar18;
  ulong unaff_x30;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_80 = 0;
  if (param_5 == 0) {
    lVar14 = 0;
    goto switchD_00109294_caseD_1;
  }
  lVar14 = 0;
  switch(param_2[1]) {
  case 1:
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
switchD_00109294_caseD_2:
    uVar18 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar18 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00111f1c,"hw_fence_process_fence_array",0x58e,uVar18);
    goto LAB_00109914;
  case 8:
    lVar14 = 3;
    break;
  case 9:
    lVar14 = 4;
    break;
  case 0xf:
    lVar14 = 1;
    break;
  default:
    if (param_2[1] != 0x4f) goto switchD_00109294_caseD_2;
    lVar14 = 2;
  }
switchD_00109294_caseD_1:
  uVar12 = *(undefined8 *)(param_3 + 0x20);
  uVar3 = *(undefined8 *)(param_3 + 0x28);
  lVar7 = _hw_fence_lookup_and_process
                    (param_1,*(undefined8 *)(param_1 + 0x38),uVar12,uVar3,0xffffffff,
                     *(undefined4 *)(param_3 + 0x44),3,param_4);
  if (lVar7 == 0) {
    uVar18 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar18 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001162dc,"_hw_fence_process_join_fence",0x501,uVar18,0xffffffff,uVar12,uVar3);
    _printk(&DAT_00115b80,"hw_fence_process_fence_array",0x59b,uVar18);
  }
  else {
    lVar11 = lVar7 + 0x28;
    global_atomic_store(param_1,lVar11,1);
    *(ulong *)(lVar7 + 0x18) = 1L << ((ulong)*param_2 & 0x3f) | *(ulong *)(lVar7 + 0x18);
    global_atomic_store(param_1,lVar11,0);
    if (*(int *)(param_3 + 0x44) == 0) {
      uVar16 = 0;
      bVar5 = false;
    }
    else {
      bVar5 = false;
      uVar16 = 0;
      do {
        lVar15 = *(long *)(*(long *)(param_3 + 0x50) + (long)(int)uVar16 * 8);
        if ((lVar15 != 0) && (*(undefined **)(lVar15 + 8) == &dma_fence_array_ops)) {
          puVar10 = &DAT_00115bc8;
          uVar12 = 0x5aa;
LAB_00109688:
          uVar18 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar18 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(puVar10,"hw_fence_process_fence_array",uVar12,uVar18);
          goto LAB_00109700;
        }
        if (-1 < (int)*(undefined8 *)(lVar15 + 0x30)) {
          puVar10 = &DAT_00117b84;
          uVar12 = 0x5b1;
          goto LAB_00109688;
        }
        if (param_2 == (uint *)0x0) {
          uVar17 = 0xff;
        }
        else {
          uVar17 = *param_2;
        }
        uVar12 = *(undefined8 *)(lVar15 + 0x20);
        uVar3 = *(undefined8 *)(lVar15 + 0x28);
        lVar8 = _hw_fence_lookup_and_process
                          (param_1,*(undefined8 *)(param_1 + 0x38),uVar12,uVar3,uVar17,0,4,&local_80
                          );
        if (lVar8 == 0) {
          uVar18 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar18 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00116206,"msm_hw_fence_find",0x519,uVar18,uVar17,uVar12,uVar3);
          _printk(&DAT_00115915,"hw_fence_process_fence_array",0x5bb,uVar18,
                  *(undefined8 *)(lVar15 + 0x20),*(undefined8 *)(lVar15 + 0x28),local_80);
          goto LAB_00109700;
        }
        lVar15 = lVar8 + 0x28;
        global_atomic_store(param_1,lVar15,1);
        if ((*(byte *)(lVar8 + 0x30) & 1) == 0) {
          uVar17 = *(uint *)(lVar8 + 0x50);
          *(uint *)(lVar8 + 0x50) = uVar17 + 1;
          if (1 < uVar17) {
            uVar18 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar18 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_001152ab,"hw_fence_process_fence_array",0x5d7,uVar18);
            *(int *)(lVar8 + 0x50) = *(int *)(lVar8 + 0x50) + -1;
            DataSynchronizationBarrier(3,2,0);
            global_atomic_store(param_1,lVar15,0);
            goto LAB_00109700;
          }
          *(long *)(lVar8 + (ulong)uVar17 * 8 + 0x38) = *param_4;
          DataSynchronizationBarrier(3,2,0);
        }
        else {
          global_atomic_store(param_1,lVar11,1);
          iVar6 = *(int *)(lVar7 + 0x54) + -1;
          *(uint *)(lVar7 + 4) = *(uint *)(lVar7 + 4) | *(uint *)(lVar8 + 4);
          *(int *)(lVar7 + 0x54) = iVar6;
          bVar5 = (bool)(iVar6 == 0 | bVar5);
          DataSynchronizationBarrier(3,2,0);
          global_atomic_store(param_1,lVar11,0);
        }
        global_atomic_store(param_1,lVar15,0);
        uVar16 = uVar16 + 1;
      } while (uVar16 < *(uint *)(param_3 + 0x44));
    }
    if (param_5 != 0) {
      *(long *)(lVar7 + lVar14 * 8 + 0x78) = param_5;
    }
    if (bVar5) {
      _fence_ctl_signal(param_1,param_2,lVar7,*param_4,param_5,*(undefined4 *)(lVar7 + 4));
      puVar1 = (ulong *)(param_3 + 0x30);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 0x40000000;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      uVar12 = *(undefined8 *)(param_3 + 0x20);
      uVar3 = *(undefined8 *)(param_3 + 0x28);
      local_70 = 0;
      lVar14 = _hw_fence_lookup_and_process
                         (param_1,*(undefined8 *)(param_1 + 0x38),uVar12,uVar3,0xffffffff,0,2,
                          &local_70);
      uVar9 = 0;
      if (lVar14 == 0) {
        uVar18 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar18 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00118453,"_hw_fence_process_join_fence",0x506,uVar18,0xffffffff,uVar12,uVar3);
        uVar9 = 0;
      }
      goto LAB_00109918;
    }
    if (*(int *)(param_3 + 0x44) != 0) {
      uVar9 = 0;
      goto LAB_00109918;
    }
    uVar18 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar18 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115e3f,"hw_fence_process_fence_array",0x605,uVar18,
            *(undefined8 *)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x28));
LAB_00109700:
    local_78 = 0;
    lVar14 = *param_4;
    if ((-1 < (int)uVar16) && (*(long *)(param_3 + 0x50) != 0)) {
      uVar18 = (ulong)uVar16;
      do {
        lVar7 = *(long *)(*(long *)(param_3 + 0x50) + uVar18 * 8);
        if (lVar7 == 0) {
          uVar2 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar2 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00114766,"_cleanup_join_and_child_fences",0x54f,uVar2,uVar18 & 0xffffffff);
        }
        else {
          if (param_2 == (uint *)0x0) {
            uVar16 = 0xff;
          }
          else {
            uVar16 = *param_2;
          }
          uVar12 = *(undefined8 *)(lVar7 + 0x20);
          uVar3 = *(undefined8 *)(lVar7 + 0x28);
          lVar11 = _hw_fence_lookup_and_process
                             (param_1,*(undefined8 *)(param_1 + 0x38),uVar12,uVar3,uVar16,0,4,
                              &local_78);
          if (lVar11 == 0) {
            uVar2 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar2 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00116206,"msm_hw_fence_find",0x519,uVar2,uVar16,uVar12,uVar3);
            _printk(&DAT_00118083,"_cleanup_join_and_child_fences",0x557,uVar2,
                    *(undefined8 *)(lVar7 + 0x20),*(undefined8 *)(lVar7 + 0x28),local_78);
          }
          else {
            global_atomic_store(param_1,lVar11 + 0x28,1);
            uVar16 = *(uint *)(lVar11 + 0x50);
            if (0 < (int)uVar16) {
              do {
                uVar17 = uVar16;
                if (3 < uVar16) {
                  uVar2 = unaff_x30 & 0xff80007fffffffff;
                  if ((unaff_x30 & 0x80000000000000) != 0) {
                    uVar2 = unaff_x30 | 0xffffff8000000000;
                  }
                  uVar17 = 3;
                  _printk(&DAT_00117be0,"_cleanup_join_and_child_fences",0x566,uVar2,
                          *(undefined4 *)(lVar11 + 0x50),3);
                }
                uVar16 = uVar17 - 1;
                plVar13 = (long *)(lVar11 + (ulong)uVar16 * 8 + 0x38);
                if (*plVar13 == lVar14) {
                  *plVar13 = -1;
                  if (*(int *)(lVar11 + 0x50) != 0) {
                    *(int *)(lVar11 + 0x50) = *(int *)(lVar11 + 0x50) + -1;
                  }
                  DataSynchronizationBarrier(3,2,0);
                }
              } while (1 < uVar17);
            }
            global_atomic_store(param_1,lVar11 + 0x28,0);
          }
        }
        bVar5 = 0 < (long)uVar18;
        uVar18 = uVar18 - 1;
      } while (bVar5);
    }
    uVar12 = *(undefined8 *)(param_3 + 0x20);
    uVar3 = *(undefined8 *)(param_3 + 0x28);
    local_70 = 0;
    lVar14 = _hw_fence_lookup_and_process
                       (param_1,*(undefined8 *)(param_1 + 0x38),uVar12,uVar3,0xffffffff,0,2,
                        &local_70);
    if (lVar14 == 0) {
      uVar18 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar18 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00118453,"_hw_fence_process_join_fence",0x506,uVar18,0xffffffff,uVar12,uVar3);
    }
  }
LAB_00109914:
  uVar9 = 0xffffffea;
LAB_00109918:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_get_client_data_id @ 001099e8 size=88
// signature: undefined hw_fence_get_client_data_id(void)
// callers: [msm_hw_fence_wait_update_v2]
//------------------------------------------------------------

undefined8 hw_fence_get_client_data_id(int param_1)

{
  switch(param_1) {
  case 1:
    return 0;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    goto switchD_00109a0c_caseD_1;
  case 8:
    return 3;
  case 9:
    return 4;
  case 0xf:
    return 1;
  default:
    if (param_1 == 0x4f) {
      return 2;
    }
switchD_00109a0c_caseD_1:
    return 5;
  }
}



//------------------------------------------------------------
// _fence_ctl_signal @ 00109a40 size=288
// signature: undefined _fence_ctl_signal(void)
// callers: [hw_fence_process_fence_array, hw_fence_register_wait_client, hw_fence_utils_cleanup_fence]
//------------------------------------------------------------

void _fence_ctl_signal(long param_1,int *param_2,long param_3,undefined8 param_4,undefined8 param_5,
                      int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x25c);
  iVar2 = param_2[0x35];
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_001152f3,"_fence_ctl_signal",0x525,param_4);
  }
  if ((param_6 == 0) || (*(long *)(param_2 + 0x24) == 0)) {
    if ((char)param_2[0x37] != '\0') {
      hw_fence_update_queue
                (param_1,param_2,*(undefined8 *)(param_3 + 8),*(undefined8 *)(param_3 + 0x10),
                 param_4,0,param_5,param_6,1);
    }
    if (*(char *)((long)param_2 + 0xdd) != '\0') {
      hw_fence_ipcc_trigger_signal(param_1,uVar1,iVar2,param_2[0x34]);
    }
  }
  else {
    hw_fence_utils_fence_error_cb
              (param_2,*(undefined8 *)(param_3 + 8),*(undefined8 *)(param_3 + 0x10),param_4,0,
               param_6);
  }
  if (*param_2 - 8U < 7) {
    process_validation_client_loopback(param_1);
  }
  return;
}



//------------------------------------------------------------
// hw_fence_register_wait_client @ 00109b64 size=632
// signature: undefined hw_fence_register_wait_client(void)
// callers: [hw_fence_process_fence, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
hw_fence_register_wait_client
          (long param_1,long param_2,uint *param_3,undefined8 param_4,undefined8 param_5,
          undefined8 *param_6,long param_7)

{
  ulong *puVar1;
  ulong uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  ulong unaff_x30;
  
  if (param_7 == 0) {
    lVar8 = 0;
  }
  else {
    lVar8 = 0;
    switch(param_3[1]) {
    case 1:
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
code_r0x00109d94:
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00111f1c,"hw_fence_register_wait_client",0x61d,uVar2,param_7,*param_3);
      return 0xffffffea;
    case 8:
      lVar8 = 3;
      break;
    case 9:
      lVar8 = 4;
      break;
    case 0xf:
      lVar8 = 1;
      break;
    default:
      if (param_3[1] != 0x4f) goto code_r0x00109d94;
      lVar8 = 2;
    }
  }
  if (param_3 == (uint *)0x0) {
    uVar9 = 0xff;
  }
  else {
    uVar9 = *param_3;
  }
  lVar6 = _hw_fence_lookup_and_process
                    (param_1,*(undefined8 *)(param_1 + 0x38),param_4,param_5,uVar9,0,4,param_6);
  if (lVar6 == 0) {
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00116206,"msm_hw_fence_find",0x519,uVar2,uVar9,param_4,param_5);
    _printk(&DAT_001164fb,"hw_fence_register_wait_client",0x625,uVar2);
    uVar7 = 0xffffffea;
  }
  else {
    global_atomic_store(param_1,lVar6 + 0x28,1);
    pcVar5 = _arch_timer_read_counter;
    *(ulong *)(lVar6 + 0x18) = 1L << ((ulong)*param_3 & 0x3f) | *(ulong *)(lVar6 + 0x18);
    if (*(int *)(pcVar5 + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x109c94);
      (*pcVar5)();
    }
    uVar7 = (*pcVar5)();
    *(undefined8 *)(lVar6 + 0x68) = uVar7;
    *(long *)(lVar6 + 0x70) = *(long *)(lVar6 + 0x70) + 1;
    if (param_7 != 0) {
      *(long *)(lVar6 + lVar8 * 8 + 0x78) = param_7;
    }
    DataSynchronizationBarrier(3,2,0);
    global_atomic_store(param_1,lVar6 + 0x28,0);
    uVar7 = 0;
    if ((*(byte *)(lVar6 + 0x30) & 1) != 0) {
      if (param_2 != 0) {
        puVar1 = (ulong *)(param_2 + 0x30);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 0x40000000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      _fence_ctl_signal(param_1,param_3,lVar6,*param_6,param_7,0);
      uVar7 = 0;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// hw_fence_process_fence @ 00109dec size=272
// signature: undefined hw_fence_process_fence(void)
// callers: [msm_hw_fence_wait_update_v2]
//------------------------------------------------------------

int hw_fence_process_fence
              (long param_1,undefined4 *param_2,long param_3,undefined8 param_4,undefined8 param_5,
              undefined8 param_6)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if (((param_1 == 0) || (param_2 == (undefined4 *)0x0)) || (param_3 == 0)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115969,"hw_fence_process_fence",0x648,uVar1);
    iVar2 = -0x16;
  }
  else if ((int)*(undefined8 *)(param_3 + 0x30) < 0) {
    iVar2 = hw_fence_register_wait_client
                      (param_1,param_3,param_2,*(undefined8 *)(param_3 + 0x20),
                       *(undefined8 *)(param_3 + 0x28),param_4);
    if (iVar2 != 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001135c3,"hw_fence_process_fence",0x654,uVar1,*param_2);
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011572d,"hw_fence_process_fence",0x64d,uVar1,*(undefined8 *)(param_3 + 0x30),
            param_6,param_5);
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// hw_fence_utils_reset_queues @ 00109f00 size=448
// signature: undefined hw_fence_utils_reset_queues(void)
// callers: [msm_hw_fence_reset_client]
//------------------------------------------------------------

void hw_fence_utils_reset_queues(long param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  ulong unaff_x30;
  
  lVar6 = *(long *)(param_2 + 0xe);
  DataSynchronizationBarrier(3,3,0);
  uVar4 = readl_relaxed(lVar6 + 0x34);
  if ((char)param_2[0x14] != '\0') {
    *(undefined4 *)(lVar6 + 0x1c) = uVar4;
  }
  writel_relaxed(uVar4,lVar6 + 0x30);
  DataSynchronizationBarrier(3,2,0);
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
    pcVar1 = "read_index";
    if ((char)param_2[0x14] != '\0') {
      pcVar1 = "read_index=tx_wm";
    }
    _printk(&DAT_00117266,"hw_fence_utils_reset_queues",0x686,pcVar1,uVar4);
    cVar2 = (char)param_2[0x37];
  }
  else {
    cVar2 = (char)param_2[0x37];
  }
  if (cVar2 != '\0') {
    uVar3 = *param_2 - 1;
    if (uVar3 < *(uint *)(param_1 + 0x60)) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00114d07,"hw_fence_utils_reset_queues",0x691,*param_2,uVar3);
      }
      global_atomic_store(param_1,*(long *)(param_1 + 0x58) + (ulong)uVar3 * 8,1);
      lVar6 = *(long *)(param_2 + 0x1a);
      DataSynchronizationBarrier(3,3,0);
      uVar5 = readl_relaxed(lVar6 + 0x30);
      writel_relaxed(uVar5,lVar6 + 0x34);
      DataSynchronizationBarrier(3,2,0);
      global_atomic_store(param_1,*(long *)(param_1 + 0x58) + (ulong)uVar3 * 8,0);
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
        _printk(&DAT_00116258,"hw_fence_utils_reset_queues",0x6a0,uVar5 & 0xffffffff);
      }
    }
    else {
      uVar5 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar5 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001138e1,"hw_fence_utils_reset_queues",0x68e,uVar5);
    }
  }
  return;
}



//------------------------------------------------------------
// hw_fence_utils_cleanup_fence @ 0010a0c4 size=644
// signature: undefined hw_fence_utils_cleanup_fence(void)
// callers: [msm_hw_fence_reset_client]
//------------------------------------------------------------

void hw_fence_utils_cleanup_fence
               (long param_1,uint *param_2,long param_3,undefined8 param_4,uint param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong unaff_x30;
  undefined8 local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  global_atomic_store(param_1,param_3 + 0x28,1);
  uVar6 = *(ulong *)(param_3 + 0x18);
  uVar8 = 1L << ((ulong)*param_2 & 0x3f);
  if ((uVar8 & uVar6) != 0) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00114d87,"hw_fence_utils_cleanup_fence",0x6af,(ulong)*param_2,
              *(undefined8 *)(param_3 + 8),*(undefined8 *)(param_3 + 0x10));
      uVar6 = *(ulong *)(param_3 + 0x18);
      uVar8 = 1L << ((ulong)*param_2 & 0x3f);
    }
    *(ulong *)(param_3 + 0x18) = uVar6 & (uVar8 ^ 0xffffffffffffffff);
    DataSynchronizationBarrier(3,2,0);
  }
  global_atomic_store(param_1,param_3 + 0x28,0);
  uVar4 = 0;
  if (*(uint *)(param_3 + 0x20) == *param_2) {
    if ((*(byte *)(param_3 + 0x30) & 1) == 0) {
      uVar4 = 0;
      uVar6 = 0;
      do {
        if (((*(ulong *)(param_3 + 0x18) >> (uVar6 & 0x3f) & 1) == 0) ||
           (lVar5 = *(long *)(*(long *)(param_1 + 0x2b0) + uVar6 * 8), lVar5 == 0))
        goto LAB_0010a1c0;
        lVar7 = 0;
        switch(*(int *)(lVar5 + 4)) {
        case 1:
          break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
          goto switchD_0010a20c_caseD_2;
        case 8:
          lVar7 = 3;
          break;
        case 9:
          lVar7 = 4;
          break;
        case 0xf:
          lVar7 = 1;
          break;
        default:
          if (*(int *)(lVar5 + 4) == 0x4f) {
            lVar7 = 2;
            break;
          }
          goto switchD_0010a20c_caseD_2;
        }
        uVar4 = *(undefined8 *)(param_3 + lVar7 * 8 + 0x78);
switchD_0010a20c_caseD_2:
        _fence_ctl_signal(param_1,lVar5,param_3,param_4,uVar4,(param_5 & 1) == 0);
LAB_0010a1c0:
        uVar1 = (int)uVar6 + 1;
        uVar6 = (ulong)uVar1;
      } while (uVar1 <= *(uint *)(param_1 + 0x30));
    }
    if ((param_5 >> 1 & 1) == 0) {
      uVar2 = *(undefined8 *)(param_3 + 8);
      uVar3 = *(undefined8 *)(param_3 + 0x10);
      uVar1 = *param_2;
      local_70 = 0;
      lVar5 = _hw_fence_lookup_and_process
                        (param_1,*(undefined8 *)(param_1 + 0x38),uVar2,uVar3,uVar1,0,2,&local_70);
      uVar4 = 0;
      if (lVar5 == 0) {
        uVar6 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar6 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00117562,"hw_fence_destroy",0x4bb,uVar6,uVar1,uVar2,uVar3);
        _printk(&DAT_00117fc8,"hw_fence_utils_cleanup_fence",0x6c4,uVar6,
                *(undefined8 *)(param_3 + 8),*(undefined8 *)(param_3 + 0x10));
        uVar4 = 0xffffffea;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// global_atomic_store @ 0010a350 size=292
// signature: undefined global_atomic_store(void)
// callers: [_hw_fence_lookup_and_process, hw_fence_utils_reset_queues, hw_fence_process_fence_array, hw_fence_register_wait_client, hw_fence_update_queue, hw_fence_utils_cleanup_fence]
//------------------------------------------------------------

void global_atomic_store(long param_1,uint *param_2,ulong param_3)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 1) == 0) {
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(param_2,0x10);
      if (bVar3) {
        *param_2 = *param_2 & 0xfffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataSynchronizationBarrier(3,3,0);
    uVar6 = *(undefined8 *)param_2;
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10080) == 0) {
      _printk(&DAT_00115818,"_unlock",0xb1,uVar6);
    }
    if (((uint)uVar6 >> 1 & 1) != 0) {
      uVar1 = msm_hw_fence_debug_level ^ 0xffffffff;
      *(long *)(param_1 + 0x238) = *(long *)(param_1 + 0x238) + 1;
      if ((uVar1 & 0x10080) == 0) {
        _printk(&DAT_0011328b,"_unlock",0xba,uVar6);
      }
      hw_fence_ipcc_trigger_signal
                (param_1,*(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 600),0x1e);
    }
    lVar5 = sp_el0;
    lVar4 = *(long *)(lVar5 + 0x10) + -1;
    *(int *)(lVar5 + 0x10) = (int)lVar4;
    if ((lVar4 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
      preempt_schedule();
    }
  }
  else {
    lVar4 = sp_el0;
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    Hint_Prefetch(param_2,2,0,0);
    do {
      do {
      } while (*param_2 != 0);
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(param_2,0x10);
      if (bVar3) {
        *param_2 = 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return;
}



//------------------------------------------------------------
// hw_fence_utils_fence_error_cb @ 0010a478 size=464
// signature: undefined hw_fence_utils_fence_error_cb(void)
// callers: [hw_fence_utils_process_doorbell_mask, _fence_ctl_signal]
//------------------------------------------------------------

undefined8
hw_fence_utils_fence_error_cb
          (undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined8 param_5,int param_6)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 *puStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  puStack_60 = (undefined8 *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  if ((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011324c,"hw_fence_utils_fence_error_cb",0xd5,uVar1,param_1);
    uVar4 = 0xffffffea;
  }
  else {
    mutex_lock(param_1 + 0x28);
    pcVar3 = *(code **)(param_1 + 0x24);
    if ((param_6 == 0) || (pcVar3 == (code *)0x0)) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001187b5,"hw_fence_utils_fence_error_cb",0xdc,uVar1,param_6);
      uVar4 = 0xffffffea;
    }
    else {
      puStack_60 = &local_a8;
      uStack_70 = CONCAT44(param_6,(undefined4)uStack_70);
      local_68 = *(undefined8 *)(param_1 + 0x26);
      local_88 = param_2;
      uStack_80 = param_3;
      local_78 = param_5;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_00117609,"hw_fence_utils_fence_error_cb",0xeb,*param_1,param_2,param_3,param_5,
                param_6,local_68);
        pcVar3 = *(code **)(param_1 + 0x24);
      }
      if (*(int *)(pcVar3 + -4) != -0x545bedb5) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8225,0x10a54c);
        (*pcVar3)();
      }
      (*pcVar3)(param_4,param_6,&local_68);
      uVar4 = 0;
    }
    mutex_unlock(param_1 + 0x28);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// hw_fence_utils_process_doorbell_mask @ 0010a64c size=1020
// signature: undefined hw_fence_utils_process_doorbell_mask(void)
// callers: [_hw_fence_cb, msm_hw_fence_driver_doorbell_sim]
//------------------------------------------------------------

void hw_fence_utils_process_doorbell_mask(long param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong unaff_x30;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  uVar8 = 0;
  local_68 = *(long *)(lVar7 + 0x638);
  do {
    uVar10 = (ulong)(1 << (ulong)(uVar8 & 0x1f));
    if ((param_2 & uVar10) != 0) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00117c2e,"hw_fence_utils_process_doorbell_mask",0x150,uVar8,param_2);
      }
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_001143f8,"_process_doorbell_id",0x130,uVar8);
      }
      if (uVar8 - 8 < 7) {
        iVar4 = process_validation_client_loopback(param_1,uVar8);
joined_r0x0010a928:
        if (iVar4 != 0) goto LAB_0010a940;
      }
      else {
        if (uVar8 == 0) {
          iVar4 = 0;
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          local_80 = 0;
          local_98 = 0;
          local_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          uVar9 = 0;
          while( true ) {
            iVar5 = hw_fence_read_queue_helper(param_1 + 0xf8,&local_a8);
            uVar1 = local_80;
            if (iVar5 < 0) break;
            if (local_a8._4_2_ == 2) {
              if ((local_80 == 0) || (*(uint *)(param_1 + 0x34) <= local_80)) {
                uVar1 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar1 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_00118c54,"_process_fence_error_client_loopback",0x10e,uVar1,local_80,1)
                ;
                iVar4 = -0x16;
              }
              else {
                if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
                  _printk(&DAT_00116cdb,"_process_fence_error_client_loopback",0x116,uVar9,local_90,
                          local_a0,local_98,local_88,(undefined4)local_78,(int)local_80);
                }
                lVar7 = *(long *)(*(long *)(param_1 + 0x2b0) + (uVar1 & 0xffffffff) * 8);
                if (lVar7 == 0) {
                  uVar2 = unaff_x30 & 0xff80007fffffffff;
                  if ((unaff_x30 & 0x80000000000000) != 0) {
                    uVar2 = unaff_x30 | 0xffffff8000000000;
                  }
                  _printk(&DAT_00117caf,"_process_fence_error_client_loopback",0x11b,uVar2,
                          uVar1 & 0xffffffff);
                  iVar4 = -0x16;
                }
                else {
                  iVar6 = hw_fence_utils_fence_error_cb
                                    (lVar7,local_a0,local_98,local_90,local_88,local_78 & 0xffffffff
                                    );
                  if (iVar6 != 0) {
                    uVar2 = unaff_x30 & 0xff80007fffffffff;
                    if ((unaff_x30 & 0x80000000000000) != 0) {
                      uVar2 = unaff_x30 | 0xffffff8000000000;
                    }
                    _printk(&DAT_001125da,"_process_fence_error_client_loopback",0x124,uVar2,
                            uVar1 & 0xffffffff,local_a0,local_98,local_78 & 0xffffffff);
                    iVar4 = iVar6;
                  }
                }
              }
            }
            else {
              uVar1 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar1 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00117701,"_process_fence_error_client_loopback",0x106,uVar1,
                      local_a8._4_2_,2);
              iVar4 = -0x16;
            }
            if ((iVar5 == 0) || (bVar3 = 0x62 < uVar9, uVar9 = uVar9 + 1, bVar3))
            goto joined_r0x0010a928;
          }
          iVar4 = iVar5;
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10010) == 0) {
            _printk(&DAT_00118c12,"_process_fence_error_client_loopback",0x101,0);
          }
          goto joined_r0x0010a928;
        }
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00118be2,"_process_doorbell_id",0x141,uVar1,uVar8);
LAB_0010a940:
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_001184aa,"hw_fence_utils_process_doorbell_mask",0x153,uVar1,uVar8);
      }
      param_2 = param_2 & (uVar10 ^ 0xffffffffffffffff);
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00114a37,"hw_fence_utils_process_doorbell_mask",0x158,uVar8,param_2,uVar10,
                ~uVar10);
      }
      if (param_2 == 0) break;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0xf);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// hw_fence_utils_init_virq @ 0010aa4c size=388
// signature: undefined hw_fence_utils_init_virq(void)
// callers: [hw_fence_init]
//------------------------------------------------------------

ulong hw_fence_utils_init_virq(long *param_1)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  lVar3 = of_find_compatible_node(*(undefined8 *)(*param_1 + 0x2e8),0,"qcom,msm-hw-fence-db");
  if (lVar3 == 0) {
    uVar4 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar4 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115f47,"hw_fence_utils_init_virq",0x17e,uVar4,"qcom,msm-hw-fence-db");
    uVar4 = 0xffffffea;
  }
  else {
    uVar2 = of_property_read_variable_u32_array(lVar3,"gunyah-label",param_1 + 0x38,1,0);
    if ((int)uVar2 < 0) {
      uVar4 = (ulong)uVar2;
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011254f,"hw_fence_utils_init_virq",0x184,uVar1,uVar4);
    }
    else {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
        _printk(&DAT_00115c36,"hw_fence_utils_init_virq",0x188,(int)param_1[0x38]);
      }
      uVar4 = gh_dbl_rx_register((int)param_1[0x38],_hw_fence_cb,param_1);
      param_1[0x39] = uVar4;
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00117c68,"hw_fence_utils_init_virq",0x18c,uVar1);
      }
      else {
        uVar4 = 0;
      }
    }
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// _hw_fence_cb @ 0010abd4 size=280
// signature: undefined _hw_fence_cb(void)
// callers: []
//------------------------------------------------------------

void _hw_fence_cb(undefined4 param_1,long param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0x7fff;
  if (param_2 != 0) {
    iVar5 = gh_dbl_read_and_clean(*(undefined8 *)(param_2 + 0x1c8),&local_40,0);
    uVar4 = local_40;
    if (iVar5 == 0) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
        uVar2 = *(undefined4 *)(param_2 + 0x1c0);
        uVar6 = hw_fence_get_qtime(param_2);
        _printk(&DAT_0011442f,"_hw_fence_cb",0x170,uVar2,param_1,uVar4,uVar6);
      }
      hw_fence_utils_process_doorbell_mask(param_2,local_40);
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011775b,"_hw_fence_cb",0x16b,uVar1,iVar5);
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
// hw_fence_utils_alloc_mem @ 0010acf0 size=944
// signature: undefined hw_fence_utils_alloc_mem(void)
// callers: [hw_fence_init, msm_hw_fence_probe]
//------------------------------------------------------------

int hw_fence_utils_alloc_mem(long *param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong unaff_x30;
  long local_98;
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
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar7 = *param_1;
  lVar5 = of_find_compatible_node(*(undefined8 *)(lVar7 + 0x2e8),0,"qcom,msm-hw-fence-mem");
  if (lVar5 == 0) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115f47,"hw_fence_utils_alloc_mem",0x22e,uVar6,"qcom,msm-hw-fence-mem");
    iVar3 = -0x16;
  }
  else {
    iVar3 = of_property_read_variable_u32_array(lVar5,"gunyah-label",param_1 + 0x33,1,0);
    if (iVar3 < 0) {
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011254f,"hw_fence_utils_alloc_mem",0x234,uVar6,iVar3);
    }
    else {
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
      iVar3 = __of_parse_phandle_with_args(lVar5,"shared-buffer",0,0,0,&local_98);
      if ((iVar3 == 0) && (local_98 != 0)) {
        iVar3 = of_address_to_resource(local_98,0,param_1 + 0x26);
        if (iVar3 == 0) {
          lVar7 = devm_ioremap_wc(lVar7,param_1[0x26],(param_1[0x27] - param_1[0x26]) + 1);
          param_1[0x25] = lVar7;
          if (lVar7 == 0) {
            uVar6 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar6 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00115079,"hw_fence_utils_alloc_mem",0x248,uVar6);
            iVar3 = -6;
          }
          else {
            uVar6 = (param_1[0x27] - param_1[0x26]) + 1;
            param_1[0x32] = uVar6;
            if (uVar6 < *(uint *)((long)param_1 + 0x1bc)) {
              uVar2 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar2 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00116c5a,"hw_fence_utils_alloc_mem",0x24e,uVar2,uVar6,
                      (ulong)*(uint *)((long)param_1 + 0x1bc));
              iVar3 = -0xc;
            }
            else {
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                _printk(&DAT_0011533f,"hw_fence_utils_alloc_mem",0x254);
                lVar7 = param_1[0x25];
                uVar6 = param_1[0x32];
              }
              __memset_io(lVar7,0,uVar6);
              puVar1 = (undefined4 *)((long)param_1 + 0x19c);
              iVar4 = of_property_read_variable_u32_array(lVar5,"peer-name",puVar1,1,0);
              iVar3 = iVar4;
              if (-1 < iVar4) {
                iVar3 = 0;
              }
              if (iVar4 < 0) {
                *puVar1 = 0;
              }
              *(undefined4 *)(param_1 + 0x36) = 0x7fffffff;
              param_1[0x34] = (long)hw_fence_rm_cb;
              iVar4 = gh_rm_register_notifier(param_1 + 0x34);
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                _printk(&DAT_0011633c,"hw_fence_utils_alloc_mem",0x261,iVar3,*puVar1,iVar4);
              }
              if (iVar4 == 0) {
                iVar3 = 0;
              }
              else {
                uVar6 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar6 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_00118507,"hw_fence_utils_alloc_mem",0x263,uVar6,iVar4);
                iVar3 = -0x205;
              }
            }
          }
        }
        else {
          uVar6 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar6 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00114e0e,"hw_fence_utils_alloc_mem",0x241,uVar6,iVar3);
          iVar3 = -0x16;
        }
      }
      else {
        uVar6 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar6 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00118b9b,"hw_fence_utils_alloc_mem",0x23a,uVar6);
        iVar3 = -0xc;
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hw_fence_rm_cb @ 0010b0a4 size=708
// signature: undefined hw_fence_rm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_fence_rm_cb(long param_1,long param_2,short *param_3)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  undefined2 local_b0 [2];
  short local_ac [2];
  long local_a8;
  long local_a0;
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
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
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
  local_a0 = 0;
  local_ac[0] = 0;
  local_b0[0] = 0;
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
    _printk(&DAT_001180da,"hw_fence_rm_cb",0x1e8,param_2);
  }
  if (param_2 == 0x56100008) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
      _printk(&DAT_00112e12,"hw_fence_rm_cb",0x1ed,(char)param_3[2]);
    }
    if (((((char)param_3[2] == '\v') || ((char)param_3[2] == '\x02')) &&
        (iVar2 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -4),local_ac), iVar2 == 0)) &&
       ((iVar2 = ghd_rm_get_vmid(1,local_b0), iVar2 == 0 && (local_ac[0] == *param_3)))) {
      if ((char)param_3[2] == '\v') {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          _printk(&DAT_001177a9,"hw_fence_rm_cb",0x21a);
        }
      }
      else if ((char)param_3[2] == '\x02') {
        iVar2 = gh_cpusys_vm_get_share_mem_info(&local_a8);
        if (iVar2 == 0) {
          lVar3 = *(long *)(param_1 + -0x70);
          if (lVar3 == local_a8) {
            lVar4 = (*(long *)(param_1 + -0x68) - lVar3) + 1;
            if (*(long *)(param_1 + -0x68) == local_a0) {
              *(undefined1 *)(param_1 + 0x118) = 1;
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                _printk(&DAT_00116381,"hw_fence_rm_cb",0x211,lVar3,lVar4,0);
              }
              goto LAB_0010b268;
            }
          }
          else {
            lVar4 = (*(long *)(param_1 + -0x68) - lVar3) + 1;
          }
          uVar1 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar1 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00112e3e,"hw_fence_rm_cb",0x215,uVar1,local_a8,(local_a0 - local_a8) + 1,
                  lVar3,lVar4);
        }
        else {
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00112634,"hw_fence_rm_cb",0x207,iVar2);
          }
          iVar2 = hw_fence_gunyah_share_mem(param_1 + -0x1a0,local_b0[0],local_ac[0]);
          if (iVar2 == 0) {
            *(undefined1 *)(param_1 + 0x118) = 1;
          }
          else {
            uVar1 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar1 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00112670,"hw_fence_rm_cb",0x209,uVar1);
          }
        }
      }
    }
  }
LAB_0010b268:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// _get_mem_reserve_type @ 0010b36c size=36
// signature: undefined _get_mem_reserve_type(void)
// callers: []
//------------------------------------------------------------

char * _get_mem_reserve_type(uint param_1)

{
  if (param_1 < 5) {
    return (&PTR_s_HW_FENCE_MEM_RESERVE_CTRL_QUEUE_00119c40)[(int)param_1];
  }
  return "Unknown";
}



//------------------------------------------------------------
// hw_fence_utils_reserve_mem @ 0010b394 size=732
// signature: undefined hw_fence_utils_reserve_mem(void)
// callers: [init_hw_fences_queues, hw_fence_init]
//------------------------------------------------------------

undefined8
hw_fence_utils_reserve_mem
          (long param_1,uint param_2,long *param_3,long *param_4,int *param_5,ulong param_6)

{
  undefined *puVar1;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  uint uVar10;
  ulong unaff_x30;
  
  switch(param_2) {
  case 0:
    uVar10 = 0;
    iVar6 = *(int *)(param_1 + 0x1c);
    break;
  case 1:
    uVar10 = *(uint *)(param_1 + 0x1c);
    iVar6 = *(int *)(param_1 + 0x30) << 3;
    break;
  case 2:
    iVar6 = *(int *)(param_1 + 0x10);
    uVar10 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x30) * 8;
    break;
  case 3:
    if (*(uint *)(param_1 + 0x34) <= (uint)param_6) {
LAB_0010b5cc:
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112947,"hw_fence_utils_reserve_mem",0x299,uVar2,param_6 & 0xffffffff,
              *(uint *)(param_1 + 0x34));
      return 0xffffffea;
    }
    lVar8 = *(long *)(*(long *)(param_1 + 0x20) +
                     (-(param_6 >> 0x1f & 1) & 0xfffffff000000000 | (param_6 & 0xffffffff) << 4));
    if (lVar8 == 0) goto LAB_0010b5cc;
    iVar6 = *(int *)(lVar8 + 0x24);
    uVar10 = *(uint *)(*(long *)(param_1 + 0x20) + (long)(int)(uint)param_6 * 0x10 + 8);
    break;
  case 4:
    uVar10 = *(uint *)(param_1 + 0x1bc);
    uVar4 = (ulong)uVar10;
    uVar2 = *(ulong *)(param_1 + 400);
    if ((uVar4 < uVar2) && (uVar7 = (int)uVar2 - uVar10, 0x3f < uVar7)) {
      uVar7 = uVar7 >> 6;
      if (999 < uVar7) {
        uVar7 = 1000;
      }
      iVar6 = uVar7 << 6;
      break;
    }
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10004) != 0) {
      return 0xfffffff4;
    }
    puVar1 = &DAT_00117668;
    uVar9 = 0x2a7;
    uVar5 = 0x40;
    goto LAB_0010b554;
  default:
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115f8b,"hw_fence_utils_reserve_mem",0x2b2,uVar2,param_2);
    uVar10 = 0;
    iVar6 = *param_5;
    uVar9 = 0xffffffea;
    goto LAB_0010b494;
  }
  uVar9 = 0;
  *param_5 = iVar6;
LAB_0010b494:
  uVar5 = *(ulong *)(param_1 + 400);
  uVar4 = (ulong)(iVar6 + uVar10);
  if (uVar5 < uVar4) {
    puVar1 = &DAT_00112990;
    uVar9 = 0x2b9;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
LAB_0010b554:
    _printk(puVar1,"hw_fence_utils_reserve_mem",uVar9,uVar2,uVar4,uVar5);
    uVar9 = 0xfffffff4;
  }
  else {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
      if (param_2 < 5) {
        pcVar3 = (&PTR_s_HW_FENCE_MEM_RESERVE_CTRL_QUEUE_00119c40)[(int)param_2];
      }
      else {
        pcVar3 = "Unknown";
      }
      _printk(&DAT_001129db,"hw_fence_utils_reserve_mem",0x2bf,pcVar3,param_2,
              *(undefined8 *)(param_1 + 0x128),*(undefined8 *)(param_1 + 0x130),uVar10,iVar6);
    }
    *param_3 = *(long *)(param_1 + 0x130) + (ulong)uVar10;
    *param_4 = *(long *)(param_1 + 0x128) + (ulong)uVar10;
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00113ea5,"hw_fence_utils_reserve_mem",0x2c4,*param_3);
    }
  }
  return uVar9;
}



//------------------------------------------------------------
// hw_fence_utils_parse_dt_props @ 0010b674 size=3048
// signature: undefined hw_fence_utils_parse_dt_props(void)
// callers: [hw_fence_init]
//------------------------------------------------------------

int hw_fence_utils_parse_dt_props(long *param_1)

{
  undefined8 *puVar1;
  char *pcVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined *puVar15;
  long lVar16;
  long lVar17;
  int *piVar18;
  undefined4 uVar19;
  long lVar20;
  int iVar21;
  ulong uVar22;
  undefined **ppuVar23;
  ulong uVar24;
  ulong unaff_x30;
  uint local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined7 uStack_b0;
  undefined1 local_a9;
  undefined7 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_d4 = 0;
  iVar5 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*param_1 + 0x2e8),"qcom,hw-fence-table-entries",&local_d4,1,0);
  if ((iVar5 < 0) || (local_d4 == 0)) {
    if (-1 < iVar5) {
      iVar5 = 0;
    }
    puVar11 = &DAT_0011436b;
    uVar14 = 0x3ae;
LAB_0010be24:
    uVar22 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar22 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(puVar11,"hw_fence_utils_parse_dt_props",uVar14,uVar22,iVar5);
  }
  else {
    *(uint *)((long)param_1 + 0xc) = local_d4;
    if (local_d4 < 0x1999999) {
      *(uint *)(param_1 + 2) = local_d4 * 0xa0;
      iVar5 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*param_1 + 0x2e8),"qcom,hw-fence-queue-entries",&local_d4,1
                         ,0);
      if ((iVar5 < 0) || (local_d4 == 0)) {
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        puVar11 = &DAT_001187f8;
        uVar14 = 0x3bd;
        goto LAB_0010be24;
      }
      *(uint *)((long)param_1 + 0x14) = local_d4;
      if (0xaaaaaa9 < local_d4) {
        puVar11 = &DAT_001157cb;
        uVar14 = 0x3c6;
        goto code_r0x0010be50;
      }
      *(uint *)(param_1 + 3) = local_d4 * 0x18;
      if (0x5555552 < local_d4) {
        puVar11 = &DAT_00111f77;
        uVar14 = 0x3cf;
        uVar22 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar22 = unaff_x30 | 0xffffff8000000000;
        }
        uVar7 = local_d4 * 0x18;
        goto LAB_0010be94;
      }
      uVar22 = 0;
      iVar5 = 0;
      ppuVar23 = &hw_fence_client_types;
      *(undefined4 *)(param_1 + 6) = 0xe;
      *(uint *)((long)param_1 + 0x1c) = local_d4 * 0x30 + 0x88;
      do {
        uStack_a8 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_a9 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d0 = 0;
        snprintf((char *)&uStack_c0,0x1f,"qcom,hw-fence-client-type-%s",*ppuVar23);
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*param_1 + 0x2e8),&uStack_c0,&local_d0,4,0);
        if (-1 < iVar6) {
          *(int *)(ppuVar23 + 3) = (int)local_c8;
          *(uint *)(ppuVar23 + 2) = (uint)local_d0;
          *(int *)((long)ppuVar23 + 0x14) = local_d0._4_4_;
          if (local_c8._4_4_ < 2) {
            *(bool *)(ppuVar23 + 6) = local_c8._4_4_ != 0;
            uVar7 = (uint)local_d0;
            iVar21 = (int)local_c8;
            iVar6 = local_d0._4_4_;
            goto LAB_0010b848;
          }
          puVar11 = &DAT_001147a3;
          uVar14 = 0x335;
          puVar15 = *ppuVar23;
          uVar7 = local_c8._4_4_;
LAB_0010bf80:
          uVar22 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar22 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(puVar11,"_parse_client_queue_dt_props_indv",uVar14,uVar22,puVar15,uVar7);
LAB_0010c064:
          uVar22 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar22 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_001126a4,"_parse_client_queue_dt_props",0x377,uVar22,*ppuVar23);
          goto LAB_0010c088;
        }
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          _printk(&DAT_001153c8,"_parse_client_queue_dt_props_indv",0x32d,*ppuVar23,iVar6);
        }
        iVar21 = *(int *)((long)param_1 + 0x14);
        uVar7 = *(uint *)(ppuVar23 + 2);
        iVar6 = *(int *)((long)ppuVar23 + 0x14);
        *(int *)(ppuVar23 + 3) = iVar21;
LAB_0010b848:
        if (((*(uint *)((long)ppuVar23 + 0xc) < uVar7) || (iVar6 - 3U < 0xfffffffe)) ||
           (iVar21 == 0)) {
          uVar22 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar22 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00114a93,"_parse_client_queue_dt_props_indv",0x33e,uVar22,*ppuVar23);
          goto LAB_0010c064;
        }
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = 0;
        local_a0 = 0;
        local_98 = 0;
        snprintf((char *)&local_90,0x28,"qcom,hw-fence-client-type-%s-extra",*ppuVar23);
        lVar9 = of_find_property(*(undefined8 *)(*param_1 + 0x2e8),&local_90,0);
        if (lVar9 != 0) {
          uVar10 = of_property_count_elems_of_size(*(undefined8 *)(*param_1 + 0x2e8),&local_90,4);
          uVar24 = uVar10 & 0xffffffff;
          uVar7 = (uint)uVar10;
          if (uVar7 - 5 < 0xfffffffc) {
            puVar11 = &DAT_00111fda;
            uVar14 = 0x2dc;
            puVar15 = *ppuVar23;
LAB_0010bfbc:
            uVar22 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar22 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(puVar11,"_parse_client_queue_dt_props_extra",uVar14,uVar22,puVar15,uVar24);
          }
          else {
            uVar8 = of_property_read_variable_u32_array
                              (*(undefined8 *)(*param_1 + 0x2e8),&local_90,&local_a0,uVar24,0);
            if ((int)uVar8 < 0) {
              uVar10 = (ulong)uVar8;
              puVar11 = &DAT_00118ca9;
              puVar15 = *ppuVar23;
              uVar14 = 0x2e3;
              uVar22 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar22 = unaff_x30 | 0xffffff8000000000;
              }
            }
            else {
              *(int *)((long)ppuVar23 + 0x1c) = (int)local_a0;
              if (uVar7 < 2) {
                uVar8 = *(uint *)(ppuVar23 + 4);
LAB_0010b93c:
                bVar4 = false;
              }
              else {
                *(uint *)(ppuVar23 + 4) = local_a0._4_4_;
                uVar8 = local_a0._4_4_;
                if (uVar7 == 2) goto LAB_0010b93c;
                *(undefined4 *)(ppuVar23 + 5) = (undefined4)local_98;
                if (uVar7 < 4) goto LAB_0010b93c;
                uVar24 = (ulong)local_98._4_4_;
                if (1 < local_98._4_4_) {
                  puVar11 = &DAT_00117d04;
                  uVar14 = 0x2ef;
                  puVar15 = *ppuVar23;
                  goto LAB_0010bfbc;
                }
                bVar4 = local_98._4_4_ != 0;
                uVar19 = 0x10;
                if (!bVar4) {
                  uVar19 = 1;
                }
                *(undefined4 *)((long)ppuVar23 + 0x2c) = uVar19;
              }
              if ((((local_a0 & 3) == 0) && ((uVar8 & 3) == 0)) &&
                 ((uVar8 + (int)local_a0 & 7) == 0)) {
                uVar10 = (ulong)*(uint *)((long)ppuVar23 + 0x14);
                uVar24 = uVar10 * -0x38 + 0xffffffe7;
                if ((local_a0 & 0xffffffff) < uVar24) {
                  if ((ulong)uVar8 < uVar24 - (local_a0 & 0xffffffff)) {
                    uVar3 = *(uint *)(ppuVar23 + 5);
                    uVar7 = *(uint *)(ppuVar23 + 3);
                    if (!bVar4) {
                      uVar7 = *(uint *)(ppuVar23 + 3) << 4;
                    }
                    if (uVar3 < ~uVar7) {
                      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                        pcVar2 = "true";
                        if (!bVar4) {
                          pcVar2 = "false";
                        }
                        _printk(&DAT_00117d48,"_parse_client_queue_dt_props_extra",0x31a,*ppuVar23,
                                local_a0 & 0xffffffff,uVar8,uVar3,pcVar2);
                      }
                      goto LAB_0010b9b0;
                    }
                    uVar22 = unaff_x30 & 0xff80007fffffffff;
                    if ((unaff_x30 & 0x80000000000000) != 0) {
                      uVar22 = unaff_x30 | 0xffffff8000000000;
                    }
                    pcVar2 = "true";
                    if (!bVar4) {
                      pcVar2 = "false";
                    }
                    _printk(&DAT_00118cfc,"_parse_client_queue_dt_props_extra",0x313,uVar22,
                            *ppuVar23,uVar3,pcVar2);
                  }
                  else {
                    uVar22 = unaff_x30 & 0xff80007fffffffff;
                    if ((unaff_x30 & 0x80000000000000) != 0) {
                      uVar22 = unaff_x30 | 0xffffff8000000000;
                    }
                    _printk(&DAT_00114e4c,"_parse_client_queue_dt_props_extra",0x309,uVar22,
                            *ppuVar23,uVar10,local_a0 & 0xffffffff,uVar8);
                  }
                  goto LAB_0010c044;
                }
                puVar11 = &DAT_00116fb6;
                uVar14 = 0x301;
                puVar15 = *ppuVar23;
                uVar24 = local_a0 & 0xffffffff;
                uVar22 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar22 = unaff_x30 | 0xffffff8000000000;
                }
              }
              else {
                puVar11 = &DAT_00116d35;
                uVar14 = 0x2fa;
                puVar15 = *ppuVar23;
                uVar10 = local_a0 & 0xffffffff;
                uVar22 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar22 = unaff_x30 | 0xffffff8000000000;
                }
                uVar24 = (ulong)uVar8;
              }
            }
            _printk(puVar11,"_parse_client_queue_dt_props_extra",uVar14,uVar22,puVar15,uVar10,uVar24
                   );
          }
LAB_0010c044:
          _printk(&DAT_00116632,"_parse_client_queue_dt_props_indv",0x345,uVar22,*ppuVar23);
          goto LAB_0010c064;
        }
LAB_0010b9b0:
        uVar7 = *(uint *)(ppuVar23 + 3);
        if (0x3fffffe < uVar7) {
          puVar11 = &DAT_0011447d;
          uVar14 = 0x34c;
          puVar15 = *ppuVar23;
          goto LAB_0010bf80;
        }
        uVar8 = *(uint *)((long)ppuVar23 + 0x1c);
        uVar3 = *(uint *)((long)ppuVar23 + 0x14);
        uVar24 = (ulong)uVar3;
        uVar10 = 0;
        if (uVar24 != 0) {
          uVar10 = ((0xffffefe8 - ((ulong)uVar8 + (ulong)*(uint *)(ppuVar23 + 4))) + uVar24 * -0x38)
                   / uVar24;
        }
        uVar24 = (ulong)uVar7 * 0x40;
        if (uVar10 <= uVar24) {
          uVar22 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar22 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_001147e4,"_parse_client_queue_dt_props_indv",0x355,uVar22,*ppuVar23,
                  uVar24 & 0xffffffff,(ulong)uVar8);
          goto LAB_0010c064;
        }
        uVar7 = uVar8 + uVar3 * (int)uVar24 + *(uint *)(ppuVar23 + 4) + uVar3 * 0x38 + 0x1017 &
                0xfffff000;
        *(uint *)((long)ppuVar23 + 0x24) = uVar7;
        if (0x100000 < uVar7) {
          uVar22 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar22 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00118850,"_parse_client_queue_dt_props_indv",0x35e,uVar22,*ppuVar23,uVar7,
                  0x100000);
          goto LAB_0010c064;
        }
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
          _printk(&DAT_00113f14,"_parse_client_queue_dt_props_indv",0x364,*ppuVar23,
                  *(undefined4 *)(ppuVar23 + 2));
        }
        if (2 < uVar22) {
          if (*(int *)((long)ppuVar23 + 0x14) == 2) {
            *(int *)(param_1 + 6) = (int)param_1[6] + *(int *)(ppuVar23 + 2);
          }
          iVar5 = *(int *)(ppuVar23 + 2) + iVar5;
        }
        uVar22 = uVar22 + 1;
        ppuVar23 = ppuVar23 + 7;
      } while (uVar22 != 0xd);
      *(uint *)((long)param_1 + 0x34) = iVar5 + 0xfU;
      param_1[5] = (long)&hw_fence_client_types;
      lVar9 = __kmalloc((ulong)(iVar5 + 0xfU) << 4,0xdc0);
      param_1[4] = lVar9;
      if (lVar9 != 0) {
        lVar9 = 0;
        uVar7 = *(int *)((long)param_1 + 0x1c) + (int)param_1[6] * 8 + (int)param_1[2] + 0xfffU &
                0xfffff000;
        do {
          if ((&DAT_00111a10)[lVar9 * 0xe] != 0) {
            uVar8 = 0;
            iVar5 = -0xf;
            do {
              iVar6 = (&DAT_00111a08)[lVar9 * 0xe];
              uVar3 = iVar6 + uVar8;
              uVar13 = uVar3 - 0xf;
              uVar22 = (ulong)uVar3;
              if (0xe < uVar3) {
                lVar17 = param_1[5];
                uVar12 = (uVar13 >> 6) + 3;
                if ((uVar13 & 0x3f) < *(uint *)(lVar17 + (ulong)uVar12 * 0x38 + 0x10)) {
                  uVar22 = (ulong)((uVar13 & 0x3f) + 0xf);
                  if (0x3f < uVar13) {
                    if (uVar12 < 5) {
                      uVar12 = 4;
                    }
                    uVar10 = (ulong)uVar12 - 3;
                    if (uVar10 < 2) {
                      lVar20 = 3;
                    }
                    else {
                      iVar21 = 0;
                      uVar13 = ((uint)(iVar6 + iVar5) >> 6) + 3;
                      if (uVar13 < 5) {
                        uVar13 = 4;
                      }
                      lVar20 = (uVar10 & 0xfffffffffffffffe) + 3;
                      uVar24 = (ulong)uVar13 - 3 & 0xfffffffffffffffe;
                      piVar18 = (int *)(lVar17 + 0xf0);
                      do {
                        uVar24 = uVar24 - 2;
                        uVar13 = piVar18[-0xe] + (int)uVar22;
                        uVar22 = (ulong)uVar13;
                        iVar21 = *piVar18 + iVar21;
                        piVar18 = piVar18 + 0x1c;
                      } while (uVar24 != 0);
                      uVar22 = (ulong)(iVar21 + uVar13);
                      if (uVar10 == (uVar10 & 0xfffffffffffffffe)) goto LAB_0010bb90;
                    }
                    uVar13 = ((uint)(iVar6 + iVar5) >> 6) + 3;
                    if (uVar13 < 5) {
                      uVar13 = 4;
                    }
                    lVar16 = lVar20 - (ulong)uVar13;
                    piVar18 = (int *)(lVar17 + (long)(int)lVar20 * 0x38 + 0x10);
                    do {
                      bVar4 = lVar16 != -1;
                      lVar16 = lVar16 + 1;
                      uVar22 = (ulong)(uint)(*piVar18 + (int)uVar22);
                      piVar18 = piVar18 + 0xe;
                    } while (bVar4);
                  }
                }
                else {
                  uVar22 = 0x28f;
                }
              }
LAB_0010bb90:
              puVar1 = (undefined8 *)(param_1[4] + uVar22 * 0x10);
              *puVar1 = &hw_fence_client_types + lVar9 * 7;
              *(uint *)(puVar1 + 1) = uVar7;
              if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
                _printk(&DAT_001180fe,"_parse_client_queue_dt_props",0x39d,
                        (&hw_fence_client_types)[lVar9 * 7],(ulong)uVar3,uVar22,uVar7);
              }
              uVar8 = uVar8 + 1;
              iVar5 = iVar5 + 1;
              uVar7 = (&DAT_00111a24)[lVar9 * 0xe] + uVar7;
            } while (uVar8 < (uint)(&DAT_00111a10)[lVar9 * 0xe]);
          }
          lVar9 = lVar9 + 1;
        } while (lVar9 != 0xd);
        *(uint *)((long)param_1 + 0x1bc) = uVar7;
        lVar9 = __kmalloc((ulong)*(uint *)((long)param_1 + 0x34) << 3,0xdc0);
        param_1[0x56] = lVar9;
        if (lVar9 == 0) {
          iVar5 = -0xc;
        }
        else {
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_001176b7,"hw_fence_utils_parse_dt_props",0x3e6,
                    *(undefined4 *)((long)param_1 + 0xc),(int)param_1[2],
                    *(undefined4 *)((long)param_1 + 0x14));
          }
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00112589,"hw_fence_utils_parse_dt_props",1000,(int)param_1[3],
                    *(undefined4 *)((long)param_1 + 0x1c));
          }
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00113c8c,"hw_fence_utils_parse_dt_props",0x3ea,
                    *(undefined4 *)((long)param_1 + 0x34),*(undefined4 *)((long)param_1 + 0x1bc));
          }
          iVar5 = 0;
        }
        goto LAB_0010c0bc;
      }
LAB_0010c088:
      uVar22 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar22 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001165aa,"hw_fence_utils_parse_dt_props",0x3d9,uVar22);
    }
    else {
      puVar11 = &UNK_00112a36;
      uVar14 = 0x3b5;
code_r0x0010be50:
      uVar22 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar22 = unaff_x30 | 0xffffff8000000000;
      }
      uVar7 = local_d4;
LAB_0010be94:
      _printk(puVar11,"hw_fence_utils_parse_dt_props",uVar14,uVar22,uVar7);
    }
    iVar5 = -0x16;
  }
LAB_0010c0bc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// hw_fence_utils_map_ipcc @ 0010c260 size=352
// signature: undefined hw_fence_utils_map_ipcc(void)
// callers: [hw_fence_init]
//------------------------------------------------------------

int hw_fence_utils_map_ipcc(long *param_1)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  ulong unaff_x30;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*param_1 + 0x2e8),"qcom,ipcc-reg",&local_40,2,0);
  if (iVar2 < 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001143bf,"hw_fence_utils_map_ipcc",0x3f9,uVar1,iVar2);
  }
  else {
    param_1[0x48] = local_40 & 0xffffffff;
    *(undefined4 *)(param_1 + 0x4a) = local_40._4_4_;
    lVar3 = devm_ioremap(*param_1);
    if (lVar3 == 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00115ca8,"hw_fence_utils_map_ipcc",0x402,uVar1);
      iVar2 = -0xc;
    }
    else {
      param_1[0x49] = lVar3;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00112a7e,"hw_fence_utils_map_ipcc",0x409,param_1[0x48],(int)param_1[0x4a],lVar3
               );
      }
      hw_fence_ipcc_enable_signaling(param_1);
      iVar2 = 0;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// hw_fence_utils_map_qtime @ 0010c3c4 size=284
// signature: undefined hw_fence_utils_map_qtime(void)
// callers: [hw_fence_init]
//------------------------------------------------------------

int hw_fence_utils_map_qtime(long *param_1)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  ulong unaff_x30;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*param_1 + 0x2e8),"qcom,qtime-reg",&local_40,2,0);
  if (iVar2 < 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011538d,"hw_fence_utils_map_qtime",0x419,uVar1,iVar2);
  }
  else {
    param_1[0x4d] = local_40 & 0xffffffff;
    *(undefined4 *)(param_1 + 0x4f) = local_40._4_4_;
    lVar3 = devm_ioremap(*param_1);
    if (lVar3 == 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001159c4,"hw_fence_utils_map_qtime",0x422,uVar1);
      iVar2 = -0xc;
    }
    else {
      iVar2 = 0;
      param_1[0x4e] = lVar3;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// hw_fence_utils_get_client_id_priv @ 0010c4e4 size=196
// signature: undefined hw_fence_utils_get_client_id_priv(void)
// callers: [msm_hw_fence_reset_client_by_id, msm_hw_fence_register]
//------------------------------------------------------------

uint hw_fence_utils_get_client_id_priv(long param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  
  uVar1 = param_2 - 0xf;
  if (0xe < param_2) {
    lVar3 = *(long *)(param_1 + 0x28);
    uVar5 = (uVar1 >> 6) + 3;
    if (*(uint *)(lVar3 + (ulong)uVar5 * 0x38 + 0x10) <= (uVar1 & 0x3f)) {
      return 0x28f;
    }
    param_2 = (uVar1 & 0x3f) + 0xf;
    if (0x3f < uVar1) {
      if (uVar5 < 5) {
        uVar5 = 4;
      }
      uVar8 = (ulong)uVar5 - 3;
      if (uVar8 < 2) {
        lVar7 = 3;
      }
      else {
        uVar9 = uVar8 & 0xfffffffffffffffe;
        iVar10 = 0;
        lVar7 = uVar9 + 3;
        piVar4 = (int *)(lVar3 + 0xf0);
        uVar11 = uVar9;
        do {
          uVar11 = uVar11 - 2;
          param_2 = piVar4[-0xe] + param_2;
          iVar10 = *piVar4 + iVar10;
          piVar4 = piVar4 + 0x1c;
        } while (uVar11 != 0);
        param_2 = iVar10 + param_2;
        if (uVar8 == uVar9) {
          return param_2;
        }
      }
      lVar6 = lVar7 - (ulong)uVar5;
      piVar4 = (int *)(lVar3 + (long)(int)lVar7 * 0x38 + 0x10);
      do {
        bVar2 = lVar6 != -1;
        lVar6 = lVar6 + 1;
        param_2 = *piVar4 + param_2;
        piVar4 = piVar4 + 0xe;
      } while (bVar2);
    }
  }
  return param_2;
}



//------------------------------------------------------------
// hw_fence_utils_get_queues_num @ 0010c5ac size=116
// signature: undefined hw_fence_utils_get_queues_num(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

undefined4 hw_fence_utils_get_queues_num(long param_1,uint param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (((param_1 == 0) || (*(uint *)(param_1 + 0x34) <= param_2)) ||
     (lVar3 = *(long *)(*(long *)(param_1 + 0x20) +
                       (-(ulong)(param_2 >> 0x1f) & 0xfffffff000000000 | (ulong)param_2 << 4)),
     lVar3 == 0)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113ed0,"hw_fence_utils_get_queues_num",1099,uVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(lVar3 + 0x14);
  }
  return uVar2;
}



//------------------------------------------------------------
// hw_fence_gunyah_share_mem @ 0010c620 size=564
// signature: undefined hw_fence_gunyah_share_mem(void)
// callers: [hw_fence_rm_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hw_fence_gunyah_share_mem(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  ulong unaff_x30;
  ulong local_80;
  ulong uStack_78;
  uint local_70 [3];
  undefined4 uStack_64;
  uint local_60 [2];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_70[0] = (uint)param_2 & 0xffff;
  uStack_78 = 1L << (param_2 & 0x3f);
  local_60[1] = 7;
  local_70[2] = (uint)param_3 & 0xffff;
  local_70[1] = 6;
  local_80 = 1L << (param_3 & 0x3f) | uStack_78;
  uStack_64 = 6;
  local_60[0] = local_70[0];
  iVar5 = qcom_scm_assign_mem(*(long *)(param_1 + 0x130),
                              (*(long *)(param_1 + 0x138) - *(long *)(param_1 + 0x130)) + 1,
                              &uStack_78,local_70,2);
  if (iVar5 == 0) {
    puVar7 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,0xc);
    if (puVar7 == (undefined4 *)0x0) {
      iVar5 = -0xc;
    }
    else {
      puVar8 = (undefined2 *)kmalloc_trace(_dma_fence_array_create,0xdc0,0x14);
      if (puVar8 == (undefined2 *)0x0) {
        kfree(puVar7);
        iVar5 = -0xc;
      }
      else {
        lVar2 = *(long *)(param_1 + 0x130);
        lVar3 = *(long *)(param_1 + 0x138);
        *puVar7 = 2;
        *(undefined1 *)((long)puVar7 + 6) = 6;
        uVar4 = *(undefined4 *)(param_1 + 0x198);
        *(undefined1 *)((long)puVar7 + 10) = 6;
        *puVar8 = 1;
        *(long *)(puVar8 + 2) = lVar2;
        *(short *)(puVar7 + 1) = (short)param_2;
        *(long *)(puVar8 + 6) = (lVar3 - lVar2) + 1;
        *(short *)(puVar7 + 2) = (short)param_3;
        iVar6 = ghd_rm_mem_share(0,0,uVar4,puVar7,puVar8,0,param_1 + 0x1b8);
        iVar5 = 0;
        if (iVar6 != 0) {
          uVar1 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar1 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00112ae9,"hw_fence_gunyah_share_mem",0x1c7,uVar1,"hw_fence_gunyah_share_mem",
                  *(undefined8 *)(param_1 + 0x130),*(undefined8 *)(param_1 + 400),iVar6);
          qcom_scm_assign_mem(*(long *)(param_1 + 0x130),
                              (*(long *)(param_1 + 0x138) - *(long *)(param_1 + 0x130)) + 1,
                              &local_80,local_60,1);
          iVar5 = -0x205;
        }
        kfree(puVar7);
        kfree(puVar8);
      }
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001172fb,"hw_fence_gunyah_share_mem",0x1a8,uVar1,"hw_fence_gunyah_share_mem",
            *(undefined8 *)(param_1 + 0x130),*(undefined8 *)(param_1 + 400),iVar5);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// msm_hw_fence_register @ 0010c858 size=1152
// signature: undefined msm_hw_fence_register(void)
// callers: [hw_fence_dbg_register_clients_wr, synx_hwfence_initialize, hw_sync_ioctl_reg_client]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * msm_hw_fence_register(uint param_1,long param_2)

{
  ulong uVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined *puVar8;
  undefined8 uVar9;
  char cVar10;
  ulong uVar11;
  ulong unaff_x30;
  
  if (hw_fence_driver_enable == '\0') {
    return (uint *)0xffffffffffffffed;
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00113f6e,"msm_hw_fence_register",0x1e,param_1);
  }
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar11 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar11 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_register",0x21,uVar11);
    return (uint *)0xfffffffffffffff5;
  }
  if ((0x28e < param_1) || (param_2 == 0)) {
    uVar11 = (ulong)(param_2 == 0);
    puVar8 = &DAT_00113a19;
    uVar9 = 0x27;
LAB_0010cb14:
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(puVar8,"msm_hw_fence_register",uVar9,uVar1,uVar11,param_1);
    return (uint *)0xffffffffffffffea;
  }
  uVar4 = hw_fence_utils_get_client_id_priv(hw_fence_drv_data,param_1);
  uVar11 = (ulong)uVar4;
  if (0x28e < uVar4) {
    puVar8 = &DAT_00114eaa;
    uVar9 = 0x2e;
    goto LAB_0010cb14;
  }
  puVar7 = (uint *)kmalloc_trace(_kfree,0xdc0,0x100);
  if (puVar7 == (uint *)0x0) {
    return (uint *)0xfffffffffffffff4;
  }
  mutex_lock(hw_fence_drv_data + 0x280);
  if (*(long *)(*(long *)(hw_fence_drv_data + 0x2b0) + uVar11 * 8) != 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011704c,"msm_hw_fence_register",0x3a,uVar1,uVar11);
    mutex_unlock(hw_fence_drv_data + 0x280);
    kfree(puVar7);
    return (uint *)0xffffffffffffffea;
  }
  *(uint **)(*(long *)(hw_fence_drv_data + 0x2b0) + uVar11 * 8) = puVar7;
  mutex_unlock(hw_fence_drv_data + 0x280);
  uVar1 = hw_fence_drv_data;
  *puVar7 = uVar4;
  puVar7[1] = param_1;
  uVar5 = hw_fence_ipcc_get_client_virt_id(uVar1,uVar11);
  uVar1 = hw_fence_drv_data;
  puVar7[0x35] = uVar5;
  uVar5 = hw_fence_ipcc_get_client_phys_id(uVar1,uVar4);
  puVar7[0x36] = uVar5;
  if (((int)puVar7[0x35] < 1) || ((int)uVar5 < 1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00114845,"msm_hw_fence_register",0x4d,uVar1,uVar11);
  }
  else {
    uVar5 = hw_fence_ipcc_get_signal_id(hw_fence_drv_data,uVar11);
    puVar7[0x34] = uVar5;
    if ((int)uVar5 < 0) {
      uVar11 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar11 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00116671,"msm_hw_fence_register",0x54,uVar11,uVar4);
    }
    else {
      bVar3 = hw_fence_ipcc_needs_rxq_update(hw_fence_drv_data,uVar4);
      uVar1 = hw_fence_drv_data;
      *(byte *)(puVar7 + 0x37) = bVar3 & 1;
      bVar3 = hw_fence_ipcc_needs_ipc_irq(uVar1,uVar4);
      uVar1 = hw_fence_drv_data;
      *(byte *)((long)puVar7 + 0xdd) = bVar3 & 1;
      uVar4 = hw_fence_utils_get_queues_num(uVar1,uVar11);
      cVar10 = (char)puVar7[0x37];
      puVar7[0x22] = uVar4;
      if (uVar4 != 0) {
        if ((cVar10 == '\0') || (1 < (int)uVar4)) {
          iVar6 = hw_fence_alloc_client_resources(hw_fence_drv_data,puVar7,param_2);
          if ((iVar6 == 0) &&
             ((iVar6 = hw_fence_init_controller_signal(hw_fence_drv_data,puVar7), iVar6 == 0 &&
              (iVar6 = hw_fence_init_controller_resources(puVar7), iVar6 == 0)))) {
            __mutex_init(puVar7 + 0x28,"&hw_fence_client->error_cb_lock",
                         &msm_hw_fence_register___key);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10008) == 0) {
              _printk(&DAT_00115431,"msm_hw_fence_register",0x7e,puVar7,*puVar7,puVar7[0x22],
                      puVar7[0x34],puVar7[0x35],puVar7[0x36]);
            }
            __init_waitqueue_head
                      (puVar7 + 0x38,"&hw_fence_client->wait_queue",&msm_hw_fence_register___key_12)
            ;
            return puVar7;
          }
          goto LAB_0010cc3c;
        }
        cVar10 = '\x01';
      }
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      pcVar2 = "false";
      if (cVar10 != '\0') {
        pcVar2 = "true";
      }
      _printk(&DAT_001177e9,"msm_hw_fence_register",0x61,uVar1,uVar11,uVar4,pcVar2);
    }
  }
  iVar6 = -0x16;
LAB_0010cc3c:
  hw_fence_cleanup_client(hw_fence_drv_data,puVar7);
  uVar11 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar11 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(&DAT_00117835,"msm_hw_fence_register",0x8a,uVar11,iVar6);
  return (uint *)(long)iVar6;
}



//------------------------------------------------------------
// msm_hw_fence_deregister @ 0010ccdc size=288
// signature: undefined msm_hw_fence_deregister(void)
// callers: [hw_sync_ioctl_unreg_client, synx_hwfence_uninitialize]
//------------------------------------------------------------

undefined8 msm_hw_fence_deregister(uint *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((param_1 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001132d9,"msm_hw_fence_deregister",0x94,uVar1);
    uVar2 = 0xffffffea;
  }
  else if (*param_1 < *(uint *)(hw_fence_drv_data + 0x34)) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00112ea9,"msm_hw_fence_deregister",0x9e);
    }
    hw_fence_cleanup_client(hw_fence_drv_data,param_1);
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00113698,"msm_hw_fence_deregister",0xa3);
    }
    uVar2 = 0;
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001144d6,"msm_hw_fence_deregister",0x9a,uVar1);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_create @ 0010ce00 size=516
// signature: undefined msm_hw_fence_create(void)
// callers: [hw_fence_dbg_create_wr, synx_hwfence_create, hw_sync_ioctl_create_fence, hw_fence_dbg_create_join_fence]
//------------------------------------------------------------

int msm_hw_fence_create(ulong param_1,long param_2)

{
  ulong *puVar1;
  ulong uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  long lVar8;
  ulong unaff_x30;
  
  if ((((param_2 == 0) || (param_1 == 0)) || (0xfffffffffffff000 < param_1)) ||
     ((lVar8 = *(long *)(param_2 + 0x10), lVar8 == 0 || (*(long *)(param_2 + 8) == 0)))) {
    puVar6 = &DAT_0011488d;
    uVar7 = 0xb2;
  }
  else {
    if (*(char *)(hw_fence_drv_data + 0x2b8) == '\0') {
      if ((msm_hw_fence_debug_level & 0x10001) == 0x10001) {
        _printk(&DAT_00117867,"msm_hw_fence_create",0xb7);
        return -0xb;
      }
      return -0xb;
    }
    if ((msm_hw_fence_debug_level & 0x10001) == 0x10001) {
      _printk(&DAT_00112ea9,"msm_hw_fence_create",0xbe);
    }
    if (*(undefined **)(lVar8 + 8) == &dma_fence_array_ops) {
      puVar6 = &DAT_001188a8;
      uVar7 = 0xc3;
    }
    else {
      if (-1 < (int)*(undefined8 *)(lVar8 + 0x30)) {
        iVar5 = hw_fence_create(hw_fence_drv_data,param_1,*(undefined8 *)(lVar8 + 0x20),
                                *(undefined8 *)(lVar8 + 0x28),*(undefined8 *)(param_2 + 8));
        if (iVar5 != 0) {
          uVar2 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar2 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00114b8b,"msm_hw_fence_create",0xd1,uVar2);
          return iVar5;
        }
        puVar1 = (ulong *)(lVar8 + 0x30);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 0x80000000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00113698,"msm_hw_fence_create",0xd8);
        }
        return 0;
      }
      puVar6 = &DAT_00114af1;
      uVar7 = 0xc9;
    }
  }
  uVar2 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar2 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(puVar6,"msm_hw_fence_create",uVar7,uVar2);
  return -0x16;
}



//------------------------------------------------------------
// msm_hw_fence_destroy @ 0010d014 size=456
// signature: undefined msm_hw_fence_destroy(void)
// callers: [hw_fence_dbg_release, hw_fence_dbg_release]
//------------------------------------------------------------

int msm_hw_fence_destroy(ulong param_1,long param_2)

{
  ulong *puVar1;
  ulong uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  
  if (((param_2 == 0) || (param_1 == 0)) || (0xfffffffffffff000 < param_1)) {
    puVar6 = &DAT_00118568;
    uVar7 = 0xe6;
  }
  else {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00112ea9,"msm_hw_fence_destroy",0xeb);
    }
    if (*(undefined **)(param_2 + 8) != &dma_fence_array_ops) {
      if (-1 < (int)*(undefined8 *)(param_2 + 0x30)) {
        uVar2 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar2 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_001166ae,"msm_hw_fence_destroy",0xf6,uVar2);
        return -0x16;
      }
      iVar5 = hw_fence_destroy(hw_fence_drv_data,param_1,*(undefined8 *)(param_2 + 0x20),
                               *(undefined8 *)(param_2 + 0x28));
      if (iVar5 != 0) {
        uVar2 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar2 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_0011680f,"msm_hw_fence_destroy",0xfe,uVar2);
        return iVar5;
      }
      puVar1 = (ulong *)(param_2 + 0x30);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffff7fffffff;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00113698,"msm_hw_fence_destroy",0x105);
      }
      return 0;
    }
    puVar6 = &DAT_00112ed7;
    uVar7 = 0xf0;
  }
  uVar2 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar2 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(puVar6,"msm_hw_fence_destroy",uVar7,uVar2);
  return -0x16;
}



//------------------------------------------------------------
// msm_hw_fence_destroy_with_handle @ 0010d1ec size=388
// signature: undefined msm_hw_fence_destroy_with_handle(void)
// callers: [synx_hwfence_create, synx_hwfence_release]
//------------------------------------------------------------

int msm_hw_fence_destroy_with_handle(uint *param_1,undefined8 param_2)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if ((param_1 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00118568,"msm_hw_fence_destroy_with_handle",0x111,uVar1);
    iVar2 = -0x16;
  }
  else if (*param_1 < *(uint *)(hw_fence_drv_data + 0x34)) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00112ea9,"msm_hw_fence_destroy_with_handle",0x11b);
    }
    iVar2 = hw_fence_destroy_with_hash(hw_fence_drv_data,param_1,param_2);
    if (iVar2 == 0) {
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00113698,"msm_hw_fence_destroy_with_handle",0x125);
      }
      iVar2 = 0;
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011548f,"msm_hw_fence_destroy_with_handle",0x121,uVar1,param_2,*param_1);
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001144d6,"msm_hw_fence_destroy_with_handle",0x117,uVar1);
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_hw_fence_wait_update_v2 @ 0010d374 size=784
// signature: undefined msm_hw_fence_wait_update_v2(void)
// callers: [msm_hw_fence_wait_update, synx_hwfence_import_indv, hw_sync_ioctl_reg_for_wait, hw_fence_dbg_create_join_fence]
//------------------------------------------------------------

int msm_hw_fence_wait_update_v2(uint *param_1,long *param_2,long param_3,long param_4,int param_5)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  ulong unaff_x30;
  undefined8 local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  if ((((param_2 == (long *)0x0) || (param_1 == (uint *)0x0)) ||
      ((uint *)0xfffffffffffff000 < param_1)) || (*param_2 == 0)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00118568,"msm_hw_fence_wait_update_v2",0x135,uVar1);
    iVar3 = -0x16;
  }
  else if (*(char *)(hw_fence_drv_data + 0x2b8) == '\0') {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001166f4,"msm_hw_fence_wait_update_v2",0x13a);
      iVar3 = -0xb;
    }
    else {
      iVar3 = -0xb;
    }
  }
  else {
    uVar2 = hw_fence_get_client_data_id(param_1[1]);
    if ((param_4 == 0) || (uVar2 < 5)) {
      if (*(uint *)(hw_fence_drv_data + 0x30) < *param_1) {
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00112256,"msm_hw_fence_wait_update_v2",0x148,uVar1,*param_1,param_1[1]);
        iVar3 = -0x16;
      }
      else {
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00112ea9,"msm_hw_fence_wait_update_v2",0x14c);
        }
        if (param_5 != 0) {
          iVar7 = 0;
          do {
            lVar5 = param_2[iVar7];
            local_70 = 0;
            if (param_4 == 0) {
              uVar6 = 0;
              if (lVar5 == 0) goto LAB_0010d470;
LAB_0010d464:
              if (*(undefined **)(lVar5 + 8) != &dma_fence_array_ops) goto LAB_0010d470;
              iVar3 = hw_fence_process_fence_array(hw_fence_drv_data,param_1,lVar5,&local_70,uVar6);
              if (iVar3 != 0) {
                puVar4 = &DAT_00114508;
                uVar6 = 0x15c;
                goto LAB_0010d668;
              }
            }
            else {
              uVar6 = *(undefined8 *)(param_4 + (long)iVar7 * 8);
              if (lVar5 != 0) goto LAB_0010d464;
LAB_0010d470:
              iVar3 = hw_fence_process_fence(hw_fence_drv_data,param_1,lVar5,&local_70);
              if (iVar3 != 0) {
                puVar4 = &DAT_001181a9;
                uVar6 = 0x164;
LAB_0010d668:
                uVar1 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar1 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(puVar4,"msm_hw_fence_wait_update_v2",uVar6,uVar1);
                goto LAB_0010d5ac;
              }
            }
            if (param_3 != 0) {
              *(undefined8 *)(param_3 + (long)iVar7 * 8) = local_70;
            }
            iVar7 = iVar7 + 1;
          } while (param_5 != iVar7);
        }
        if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00113698,"msm_hw_fence_wait_update_v2",0x16d);
        }
        iVar3 = 0;
      }
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00118149,"msm_hw_fence_wait_update_v2",0x142,uVar1,param_1[1]);
      iVar3 = -0x16;
    }
  }
LAB_0010d5ac:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_hw_fence_wait_update @ 0010d688 size=44
// signature: undefined msm_hw_fence_wait_update(void)
// callers: []
//------------------------------------------------------------

void msm_hw_fence_wait_update(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  msm_hw_fence_wait_update_v2(param_1,param_2,0,0,param_3,0);
  return;
}



//------------------------------------------------------------
// msm_hw_fence_reset_client @ 0010d6b8 size=328
// signature: undefined msm_hw_fence_reset_client(void)
// callers: [hw_fence_dbg_reset_client_wr, msm_hw_fence_reset_client_by_id, hw_sync_ioctl_reset_client]
//------------------------------------------------------------

undefined8 msm_hw_fence_reset_client(undefined4 *param_1,undefined4 param_2)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  ulong unaff_x30;
  
  if ((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011684a,"msm_hw_fence_reset_client",0x182,uVar1);
    uVar3 = 0xffffffea;
  }
  else if (*(char *)(hw_fence_drv_data + 0x2b8) == '\0') {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00113fb2,"msm_hw_fence_reset_client",0x187);
    }
    uVar3 = 0xfffffff5;
  }
  else {
    lVar4 = *(long *)(hw_fence_drv_data + 0x38);
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00114542,"msm_hw_fence_reset_client",0x18e,*param_1);
      iVar2 = *(int *)(hw_fence_drv_data + 0x40);
    }
    else {
      iVar2 = *(int *)(hw_fence_drv_data + 0x40);
    }
    if (iVar2 != 0) {
      uVar5 = 0;
      do {
        hw_fence_utils_cleanup_fence
                  (hw_fence_drv_data,param_1,lVar4 + (long)(int)uVar5 * 0xa0,(long)(int)uVar5,
                   param_2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(hw_fence_drv_data + 0x40));
    }
    hw_fence_utils_reset_queues(hw_fence_drv_data,param_1);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_hw_fence_reset_client_by_id @ 0010d804 size=228
// signature: undefined msm_hw_fence_reset_client_by_id(void)
// callers: [synx_hwfence_recover]
//------------------------------------------------------------

undefined8 msm_hw_fence_reset_client_by_id(uint param_1,undefined4 param_2)

{
  ulong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (param_1 < 0x28f) {
    uVar2 = hw_fence_utils_get_client_id_priv(hw_fence_drv_data,param_1);
    if (uVar2 < 0x28f) {
      uVar3 = msm_hw_fence_reset_client
                        (*(undefined8 *)(*(long *)(hw_fence_drv_data + 0x2b0) + (ulong)uVar2 * 8),
                         param_2);
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001126f6,"msm_hw_fence_reset_client_by_id",0x1a5,uVar1,(ulong)uVar2,param_1);
      uVar3 = 0xffffffea;
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00118d5f,"msm_hw_fence_reset_client_by_id",0x19e,uVar1,param_1);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_hw_fence_update_txq @ 0010d8ec size=260
// signature: undefined msm_hw_fence_update_txq(void)
// callers: [hw_sync_ioctl_fence_signal, synx_hwfence_signal]
//------------------------------------------------------------

undefined8
msm_hw_fence_update_txq(ulong param_1,ulong param_2,undefined8 param_3,undefined4 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  if ((((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
      (*(char *)(hw_fence_drv_data + 8) == '\0')) || (*(char *)(hw_fence_drv_data + 0x2b8) == '\0'))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00114580,"msm_hw_fence_update_txq",0x1b4,uVar1);
    uVar2 = 0xfffffff5;
  }
  else if ((param_1 == 0 || 0xfffffffffffff000 < param_1) ||
          (*(uint *)(hw_fence_drv_data + 0x40) <= param_2)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001181de,"msm_hw_fence_update_txq",0x1b9,uVar1,param_2,
            param_1 == 0 || 0xfffffffffffff000 < param_1);
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(hw_fence_drv_data + 0x38) + param_2 * 0xa0;
    hw_fence_update_queue
              (hw_fence_drv_data,param_1,*(undefined8 *)(lVar3 + 8),*(undefined8 *)(lVar3 + 0x10),
               param_2,param_3,0,param_4,0);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_update_txq_error @ 0010d9f4 size=300
// signature: undefined msm_hw_fence_update_txq_error(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_update_txq_error(ulong param_1,ulong param_2,int param_3,int param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
      (*(char *)(hw_fence_drv_data + 8) == '\0')) || (*(char *)(hw_fence_drv_data + 0x2b8) == '\0'))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00112739,"msm_hw_fence_update_txq_error",0x1cf,uVar1);
    uVar2 = 0xfffffff5;
  }
  else if (((param_1 == 0) || (0xfffffffffffff000 < param_1)) ||
          ((param_3 == 0 || (*(uint *)(hw_fence_drv_data + 0x40) <= param_2)))) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011330c,"msm_hw_fence_update_txq_error",0x1d4,uVar1,param_1);
    uVar2 = 0xffffffea;
  }
  else if (param_4 == 1) {
    hw_fence_update_existing_txq_payload(hw_fence_drv_data,param_1,param_2,param_3);
    uVar2 = 0;
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011201a,"msm_hw_fence_update_txq_error",0x1d8,uVar1,param_4,1);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_trigger_signal @ 0010db24 size=284
// signature: undefined msm_hw_fence_trigger_signal(void)
// callers: [hw_sync_ioctl_fence_signal]
//------------------------------------------------------------

undefined8
msm_hw_fence_trigger_signal
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
      (*(char *)(hw_fence_drv_data + 8) == '\0')) || (*(char *)(hw_fence_drv_data + 0x2b8) == '\0'))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00112739,"msm_hw_fence_trigger_signal",0x1ee,uVar1);
    uVar2 = 0xfffffff5;
  }
  else if ((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011708e,"msm_hw_fence_trigger_signal",0x1f1,uVar1);
    uVar2 = 0xffffffea;
  }
  else {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001154e3,"msm_hw_fence_trigger_signal",0x1f6,*param_1);
    }
    hw_fence_ipcc_trigger_signal(hw_fence_drv_data,param_2,param_3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_register_error_cb @ 0010dc44 size=288
// signature: undefined msm_hw_fence_register_error_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_register_error_cb(undefined4 *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_register_error_cb",0x203,uVar1);
    uVar2 = 0xfffffff5;
  }
  else if ((((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) ||
           ((param_2 == 0 || ((0xfffffffffffff000 < param_2 || (param_3 == 0)))))) ||
          (0xfffffffffffff000 < param_3)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011400b,"msm_hw_fence_register_error_cb",0x207,uVar1,param_1,param_2,param_3);
    uVar2 = 0xffffffea;
  }
  else if (*(long *)(param_1 + 0x24) == 0) {
    uVar2 = 0;
    *(ulong *)(param_1 + 0x24) = param_2;
    *(ulong *)(param_1 + 0x26) = param_3;
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001136ce,"msm_hw_fence_register_error_cb",0x20f,uVar1,*param_1,param_1[1],
            *(long *)(param_1 + 0x24),*(undefined8 *)(param_1 + 0x26));
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_deregister_error_cb @ 0010dd68 size=376
// signature: undefined msm_hw_fence_deregister_error_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_deregister_error_cb(undefined4 *param_1)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_deregister_error_cb",0x220,uVar1);
    uVar3 = 0xfffffff5;
  }
  else if ((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115fc4,"msm_hw_fence_deregister_error_cb",0x223,uVar1,param_1);
    uVar3 = 0xffffffea;
  }
  else {
    iVar2 = mutex_trylock(param_1 + 0x28);
    if (iVar2 == 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011207c,"msm_hw_fence_deregister_error_cb",0x22b,uVar1,*param_1,
              *(undefined8 *)(param_1 + 0x24),*(undefined8 *)(param_1 + 0x26));
      uVar3 = 0xfffffff5;
    }
    else {
      if (*(long *)(param_1 + 0x24) == 0) {
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00115ce1,"msm_hw_fence_deregister_error_cb",0x232,uVar1,*param_1,param_1[1],0,
                *(undefined8 *)(param_1 + 0x26));
      }
      else {
        *(long *)(param_1 + 0x24) = 0;
        *(undefined8 *)(param_1 + 0x26) = 0;
      }
      mutex_unlock(param_1 + 0x28);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_hw_fence_dump_debug_data @ 0010dee4 size=312
// signature: undefined msm_hw_fence_dump_debug_data(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_dump_debug_data(ulong param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_dump_debug_data",0x248,uVar1);
    uVar2 = 0xfffffff5;
  }
  else if ((param_1 == 0) || (0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001120dc,"msm_hw_fence_dump_debug_data",0x24b,uVar1,1);
    uVar2 = 0xffffffea;
  }
  else {
    if ((param_2 & 1) != 0) {
      hw_fence_debug_dump_queues(0x10000,param_1);
      if (param_3 != 0) {
        lVar3 = 0;
        do {
          if ((param_3 >> (ulong)((uint)lVar3 & 0x1f) & 1) != 0) {
            if (*(long *)(*(long *)(hw_fence_drv_data + 0x2b0) + lVar3 * 8) != 0) {
              hw_fence_debug_dump_queues(0x10000);
            }
          }
          lVar3 = lVar3 + 1;
        } while (lVar3 != 0x28f);
      }
    }
    if ((param_2 >> 1 & 1) != 0) {
      hw_fence_debug_dump_table(0x10000,hw_fence_drv_data);
    }
    if ((param_2 >> 2 & 1) != 0) {
      hw_fence_debug_dump_events(0x10000,hw_fence_drv_data);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_dump_fence @ 0010e020 size=440
// signature: undefined msm_hw_fence_dump_fence(void)
// callers: []
//------------------------------------------------------------

void msm_hw_fence_dump_fence(undefined4 *param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_dump_fence",0x26c,uVar1);
    uVar3 = 0xfffffff5;
  }
  else if ((param_1 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < param_1)) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001120dc,"msm_hw_fence_dump_fence",0x26f,uVar1,1);
    uVar3 = 0xffffffea;
  }
  else if ((int)*(undefined8 *)(param_2 + 0x30) < 0) {
    lVar2 = msm_hw_fence_find(hw_fence_drv_data,param_1,*(undefined8 *)(param_2 + 0x20),
                              *(undefined8 *)(param_2 + 0x28),&local_40);
    if (lVar2 == 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001170ba,"msm_hw_fence_dump_fence",0x27c,uVar1,*param_1,param_2,
              *(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x28));
      uVar3 = 0xffffffea;
    }
    else {
      hw_fence_debug_dump_fence(0x10000,lVar2,local_40,0);
      uVar3 = 0;
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011336b,"msm_hw_fence_dump_fence",0x273,uVar1,*(undefined8 *)(param_2 + 0x20),
            *(undefined8 *)(param_2 + 0x28));
    uVar3 = 0xffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_hw_fence_driver_doorbell_sim @ 0010e1dc size=204
// signature: undefined msm_hw_fence_driver_doorbell_sim(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_driver_doorbell_sim(undefined8 param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (((hw_fence_drv_data == 0) || (0xfffffffffffff000 < hw_fence_drv_data)) ||
     (*(char *)(hw_fence_drv_data + 8) == '\0')) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117015,"msm_hw_fence_driver_doorbell_sim",0x28a,uVar1);
    uVar2 = 0xfffffff5;
  }
  else {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10040) == 0) {
      uVar2 = hw_fence_get_qtime(hw_fence_drv_data);
      _printk(&DAT_001133c5,"msm_hw_fence_driver_doorbell_sim",0x28f,param_1,uVar2);
    }
    hw_fence_utils_process_doorbell_mask(hw_fence_drv_data,param_1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_hw_fence_probe @ 0010e2ac size=680
// signature: undefined msm_hw_fence_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_hw_fence_probe(long param_1)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  ulong unaff_x30;
  
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00112ea9,"msm_hw_fence_probe",0x2ca);
  }
  if (param_1 == 0) {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113731,"msm_hw_fence_probe",0x2cd,uVar1);
    return -0x16;
  }
  iVar3 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,msm-hw-fence");
  if (iVar3 == 0) {
    iVar3 = -0x16;
  }
  else {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00112ea9,"msm_hw_fence_probe_init",0x29b);
    }
    plVar4 = (long *)kmalloc_trace(_snprintf,0xdc0,0x2c0);
    if (plVar4 == (long *)0x0) {
      iVar3 = -0xc;
      hw_fence_drv_data = (long *)0x0;
    }
    else {
      hw_fence_drv_data = plVar4;
      *(long **)(param_1 + 0xa8) = plVar4;
      cVar2 = hw_fence_driver_enable;
      *plVar4 = param_1 + 0x10;
      if (cVar2 == '\0') {
        iVar3 = hw_fence_utils_alloc_mem();
        if (iVar3 == 0) {
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10004) == 0) {
            _printk(&DAT_00116d8e,"msm_hw_fence_probe_init",0x2b6);
          }
          goto LAB_0010e388;
        }
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00117f88,"msm_hw_fence_probe_init",0x2b2,uVar1);
      }
      else {
        iVar3 = hw_fence_init();
        if (iVar3 == 0) {
          __mutex_init(hw_fence_drv_data + 0x50,"&hw_fence_drv_data->clients_register_lock",
                       &msm_hw_fence_probe_init___key);
          *(undefined1 *)(hw_fence_drv_data + 1) = 1;
LAB_0010e388:
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00113698,"msm_hw_fence_probe_init",0x2b9);
          }
          if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00113698,"msm_hw_fence_probe",0x2d6);
          }
          return 0;
        }
      }
      plVar4 = hw_fence_drv_data;
      *(undefined8 *)(param_1 + 0xa8) = 0;
      kfree(plVar4);
      hw_fence_drv_data = (long *)0xfffffffffffffdfb;
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00113a72,"msm_hw_fence_probe_init",0x2c2,uVar1,iVar3);
    }
  }
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(&DAT_00113a72,"msm_hw_fence_probe",0x2db,uVar1,iVar3);
  return iVar3;
}



//------------------------------------------------------------
// msm_hw_fence_remove @ 0010e558 size=268
// signature: undefined msm_hw_fence_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hw_fence_remove(long param_1)

{
  ulong uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00112ea9,"msm_hw_fence_remove",0x2e1);
  }
  if (param_1 == 0) {
    puVar2 = &DAT_00113731;
    uVar3 = 0x2e4;
  }
  else {
    hw_fence_drv_data = *(long *)(param_1 + 0xa8);
    if (hw_fence_drv_data != 0) {
      *(undefined8 *)(param_1 + 0xa8) = 0;
      kfree();
      hw_fence_drv_data = 0xfffffffffffffdfb;
      if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00113698,"msm_hw_fence_remove",0x2f2);
      }
      return 0;
    }
    puVar2 = &DAT_001163c8;
    uVar3 = 0x2ea;
    hw_fence_drv_data = 0;
  }
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(puVar2,"msm_hw_fence_remove",uVar3,uVar1);
  return 0xffffffea;
}



//------------------------------------------------------------
// synx_hwfence_initialize @ 0010e668 size=484
// signature: undefined synx_hwfence_initialize(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * synx_hwfence_initialize(ulong param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  
  if (hw_fence_driver_enable == '\0') {
    puVar5 = (undefined4 *)0xffffffffffffffea;
  }
  else if (((param_1 == 0 || 0xfffffffffffff000 < param_1) || (*(ulong *)(param_1 + 8) == 0)) ||
          (0xfffffffffffff000 < *(ulong *)(param_1 + 8))) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == 0 || 0xfffffffffffff000 < param_1) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(param_1 + 8);
    }
    _printk(&DAT_001122b8,"synx_hwfence_initialize",0x6d,uVar6,param_1,uVar7);
    puVar5 = (undefined4 *)0xffffffffffffffea;
  }
  else {
    iVar4 = _get_hw_fence_client_id(*(undefined4 *)(param_1 + 0x10));
    if ((*(int *)(param_1 + 0x10) - 0x400U < 0xc00) && (iVar4 != 0x28f)) {
      puVar5 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,0x10);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0xfffffffffffffff4;
      }
      else {
        uVar6 = msm_hw_fence_register(iVar4,*(undefined8 *)(param_1 + 8));
        if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
          kfree(puVar5);
          uVar1 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar1 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_001163f6,"synx_hwfence_initialize",0x80,uVar1,*(undefined4 *)(param_1 + 0x10)
                  ,uVar6);
          puVar5 = (undefined4 *)(long)(int)uVar6;
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + 0x10);
          *(ulong *)(puVar5 + 2) = uVar6;
          uVar3 = msm_hw_fence_debug_level;
          *puVar5 = uVar2;
          if (((uVar3 ^ 0xffffffff) & 0x10008) == 0) {
            _printk(&DAT_00113760,"synx_hwfence_initialize",0x85,uVar2,iVar4);
          }
        }
      }
    }
    else {
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00116dc2,"synx_hwfence_initialize",0x73,uVar6);
      puVar5 = (undefined4 *)0xffffffffffffffea;
    }
  }
  return puVar5;
}



//------------------------------------------------------------
// _get_hw_fence_client_id @ 0010e84c size=152
// signature: undefined _get_hw_fence_client_id(void)
// callers: [synx_hwfence_initialize, synx_hwfence_recover]
//------------------------------------------------------------

int _get_hw_fence_client_id(int param_1)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  iVar2 = 1;
  switch(param_1) {
  case 0x400:
    goto switchD_0010e874_caseD_400;
  default:
    if (param_1 - 0x540U < 0x200) {
      return param_1 + -0x4b1;
    }
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117da1,"_get_hw_fence_client_id",0x54,uVar1);
    iVar2 = 0x28f;
switchD_0010e874_caseD_400:
    return iVar2;
  case 0x440:
  case 0x441:
  case 0x442:
  case 0x443:
  case 0x444:
  case 0x445:
  case 0x446:
  case 0x447:
  case 0x448:
  case 0x449:
  case 0x44a:
  case 1099:
  case 0x44c:
  case 0x44d:
  case 0x44e:
  case 0x44f:
  case 0x450:
  case 0x451:
  case 0x452:
  case 0x453:
  case 0x454:
  case 0x455:
  case 0x456:
  case 0x457:
  case 0x458:
  case 0x459:
  case 0x45a:
  case 0x45b:
  case 0x45c:
  case 0x45d:
  case 0x45e:
  case 0x45f:
  case 0x460:
  case 0x461:
  case 0x462:
  case 0x463:
  case 0x464:
  case 0x465:
  case 0x466:
  case 0x467:
  case 0x468:
  case 0x469:
  case 0x46a:
  case 0x46b:
  case 0x46c:
  case 0x46d:
  case 0x46e:
  case 0x46f:
  case 0x470:
  case 0x471:
  case 0x472:
  case 0x473:
  case 0x474:
  case 0x475:
  case 0x476:
  case 0x477:
  case 0x478:
  case 0x479:
  case 0x47a:
  case 0x47b:
  case 0x47c:
  case 0x47d:
  case 0x47e:
  case 0x47f:
  case 0x480:
  case 0x481:
  case 0x482:
  case 0x483:
  case 0x484:
  case 0x485:
  case 0x486:
  case 0x487:
  case 0x488:
  case 0x489:
  case 0x48a:
  case 0x48b:
  case 0x48c:
  case 0x48d:
  case 0x48e:
  case 0x48f:
  case 0x490:
  case 0x491:
  case 0x492:
  case 0x493:
  case 0x494:
  case 0x495:
  case 0x496:
  case 0x497:
  case 0x498:
  case 0x499:
  case 0x49a:
  case 0x49b:
  case 0x49c:
  case 0x49d:
  case 0x49e:
  case 0x49f:
  case 0x4a0:
  case 0x4a1:
  case 0x4a2:
  case 0x4a3:
  case 0x4a4:
  case 0x4a5:
  case 0x4a6:
  case 0x4a7:
  case 0x4a8:
  case 0x4a9:
  case 0x4aa:
  case 0x4ab:
  case 0x4ac:
  case 0x4ad:
  case 0x4ae:
  case 0x4af:
  case 0x4b0:
  case 0x4b1:
  case 0x4b2:
  case 0x4b3:
  case 0x4b4:
  case 0x4b5:
  case 0x4b6:
  case 0x4b7:
  case 0x4b8:
  case 0x4b9:
  case 0x4ba:
  case 0x4bb:
  case 0x4bc:
  case 0x4bd:
  case 0x4be:
  case 0x4bf:
    return param_1 + -0x431;
  case 0x4c0:
  case 0x4c1:
  case 0x4c2:
  case 0x4c3:
  case 0x4c4:
  case 0x4c5:
    return param_1 + -0x4be;
  }
}



//------------------------------------------------------------
// synx_hwfence_uninitialize @ 0010e8e8 size=248
// signature: undefined synx_hwfence_uninitialize(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_uninitialize(int *param_1)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if ((param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) || (0xbff < *param_1 - 0x400U))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) {
      iVar2 = -1;
    }
    else {
      iVar2 = *param_1;
    }
    _printk(&DAT_001178c2,"synx_hwfence_uninitialize",0x91,uVar1,param_1,iVar2);
    iVar2 = -0x16;
  }
  else {
    iVar2 = msm_hw_fence_deregister(*(undefined8 *)(param_1 + 2));
    if (iVar2 == 0) {
      kfree(param_1);
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001188f4,"synx_hwfence_uninitialize",0x97,uVar1,*param_1,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// synx_hwfence_create @ 0010e9e4 size=540
// signature: undefined synx_hwfence_create(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_create(int *param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong unaff_x30;
  ulong local_60 [2];
  undefined1 *local_50;
  ulong local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_60[1] = 0;
  local_50 = (undefined1 *)0x0;
  local_60[0] = 0;
  if ((((param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) ||
       (0xbff < *param_1 - 0x400U)) || (param_2 == 0)) || (0xfffffffffffff000 < param_2)) {
    uVar3 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar3 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) {
      iVar2 = -1;
    }
    else {
      iVar2 = *param_1;
    }
    _printk(&DAT_00116e0b,"synx_hwfence_create",0xa8,uVar3,param_1,iVar2,param_2);
  }
  else if ((((*(ulong *)(param_2 + 8) == 0) || (0xfffffffffffff000 < *(ulong *)(param_2 + 8))) ||
           ((0x10 < *(uint *)(param_2 + 0x18) ||
            (((*(uint *)(param_2 + 0x18) & 0xc) != 4 ||
             (uVar3 = *(ulong *)(param_2 + 0x10), uVar3 == 0)))))) || (0xfffffffffffff000 < uVar3))
  {
    uVar3 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar3 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001140b1,"synx_hwfence_create",0xb1,uVar3);
  }
  else {
    local_50 = (undefined1 *)local_60;
    local_48 = uVar3;
    iVar2 = msm_hw_fence_create(*(undefined8 *)(param_1 + 2),local_60 + 1);
    if (iVar2 != 0) {
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112b72,"synx_hwfence_create",0xba,uVar3,*param_1,
              *(undefined8 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x18),iVar2);
      goto LAB_0010eb40;
    }
    if (local_60[0] >> 0x20 == 0) {
      iVar2 = 0;
      **(undefined4 **)(param_2 + 8) = (int)local_60[0];
      goto LAB_0010eb40;
    }
    uVar3 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar3 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011672f,"synx_hwfence_create",0xbf,uVar3,*param_1);
    msm_hw_fence_destroy_with_handle(*(undefined8 *)(param_1 + 2),local_60[0]);
  }
  iVar2 = -0x16;
LAB_0010eb40:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// synx_hwfence_release @ 0010ec04 size=252
// signature: undefined synx_hwfence_release(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_release(int *param_1,undefined4 param_2)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if ((param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) || (0xbff < *param_1 - 0x400U))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) {
      iVar2 = -1;
    }
    else {
      iVar2 = *param_1;
    }
    _printk(&DAT_001178c2,"synx_hwfence_release",0xcf,uVar1,param_1,iVar2);
    iVar2 = -0x16;
  }
  else {
    iVar2 = msm_hw_fence_destroy_with_handle(*(undefined8 *)(param_1 + 2),param_2);
    if (iVar2 != 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112f59,"synx_hwfence_release",0xd6,uVar1,*param_1,param_2,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// synx_hwfence_signal @ 0010ed04 size=276
// signature: undefined synx_hwfence_signal(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_signal(int *param_1,undefined4 param_2,undefined4 param_3)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if ((param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) || (0xbff < *param_1 - 0x400U))
  {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) {
      iVar2 = -1;
    }
    else {
      iVar2 = *param_1;
    }
    _printk(&DAT_001178c2,"synx_hwfence_signal",0xe2,uVar1,param_1,iVar2);
    iVar2 = -0x16;
  }
  else {
    iVar2 = msm_hw_fence_update_txq(*(undefined8 *)(param_1 + 2),param_2,0,param_3);
    if (iVar2 != 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_0011734e,"synx_hwfence_signal",0xe9,uVar1,*param_1,param_2,param_3,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// synx_hwfence_recover @ 0010ee1c size=208
// signature: undefined synx_hwfence_recover(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_recover(int param_1)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (param_1 - 0x400U < 0xc00) {
    uVar3 = _get_hw_fence_client_id(param_1);
    iVar2 = msm_hw_fence_reset_client_by_id(uVar3,2);
    if (iVar2 != 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001150e0,"synx_hwfence_recover",0xfb,uVar1,param_1,iVar2);
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00113cc8,"synx_hwfence_recover",0xf4,uVar1,param_1);
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// synx_hwfence_import @ 0010eef0 size=588
// signature: undefined synx_hwfence_import(void)
// callers: []
//------------------------------------------------------------

int synx_hwfence_import(int *param_1,int *param_2)

{
  ulong uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  if ((((param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) ||
       (0xbff < *param_1 - 0x400U)) || (param_2 == (int *)0x0)) ||
     ((int *)0xfffffffffffff000 < param_2)) {
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    if (param_1 == (int *)0x0 || (int *)0xfffffffffffff000 < param_1) {
      iVar3 = -1;
    }
    else {
      iVar3 = *param_1;
    }
    _printk(&DAT_00116e0b,"synx_hwfence_import",0x140,uVar6,param_1,iVar3,param_2);
    iVar3 = -0x16;
  }
  else {
    uVar6 = *(ulong *)(param_1 + 2);
    plVar5 = (long *)(param_2 + 2);
    if (*param_2 == 2) {
      if (((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) ||
         ((plVar5 == (long *)0x0 ||
          (((long *)0xffffffffffffefff < plVar5 && param_2 != (int *)0xffffffffffffeff8 ||
           (param_2[4] == 0)))))) {
        iVar3 = -1;
        uVar1 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar1 = unaff_x30 | 0xffffff8000000000;
        }
        if ((plVar5 != (long *)0x0) &&
           (plVar5 < (long *)0xfffffffffffff000 || param_2 == (int *)0xffffffffffffeff8)) {
          iVar3 = param_2[4];
        }
        _printk(&DAT_00117de9,"synx_hwfence_import_arr",0x129,uVar1,uVar6,plVar5,iVar3);
        iVar3 = -0x16;
      }
      else {
        uVar4 = 0;
        while (iVar3 = synx_hwfence_import_indv(uVar6,*plVar5 + (long)(int)uVar4 * 0x18), iVar3 == 0
              ) {
          uVar4 = uVar4 + 1;
          if ((uint)param_2[4] <= uVar4) {
            return 0;
          }
        }
        uVar6 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar6 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00115d54,"synx_hwfence_import_arr",0x131,uVar6,uVar4,
                *(undefined8 *)(*plVar5 + (long)(int)uVar4 * 0x18 + 0x10),iVar3);
      }
    }
    else {
      iVar3 = synx_hwfence_import_indv(uVar6,plVar5);
      if (iVar3 == 0) {
        return 0;
      }
    }
    uVar6 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar6 = unaff_x30 | 0xffffff8000000000;
    }
    puVar2 = &DAT_001168f6;
    if (*param_2 != 2) {
      puVar2 = &DAT_00115d4f;
    }
    _printk(&DAT_00115515,"synx_hwfence_import",0x14b,uVar6,*param_1,puVar2,iVar3);
  }
  return iVar3;
}



//------------------------------------------------------------
// synx_hwfence_import_indv @ 0010f13c size=496
// signature: undefined synx_hwfence_import_indv(void)
// callers: [synx_hwfence_import]
//------------------------------------------------------------

int synx_hwfence_import_indv(ulong param_1,ulong *param_2)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong unaff_x30;
  ulong local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  if (((((param_1 == 0) || (0xfffffffffffff000 < param_1)) || (param_2 == (ulong *)0x0)) ||
      (((ulong *)0xfffffffffffff000 < param_2 || (*param_2 == 0)))) ||
     ((0xfffffffffffff000 < *param_2 || ((param_2[1] & 0xc) != 8)))) {
LAB_0010f1fc:
    uVar4 = 0;
    uVar5 = 0;
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    uVar6 = 0;
    if ((param_2 != (ulong *)0x0) && (param_2 < (ulong *)0xfffffffffffff001)) {
      uVar4 = *param_2;
      uVar5 = (undefined4)param_2[1];
      uVar6 = param_2[2];
    }
    _printk(&DAT_001137a5,"synx_hwfence_import_indv",0x10d,uVar1,param_1,param_2,uVar4,uVar5,uVar6);
  }
  else {
    puVar7 = param_2 + 2;
    if ((*puVar7 == 0) || (0xfffffffffffff000 < *puVar7)) goto LAB_0010f1fc;
    iVar3 = msm_hw_fence_wait_update_v2(param_1,puVar7,&local_50,0,1,1);
    if (iVar3 != 0) {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00117900,"synx_hwfence_import_indv",0x115,uVar1,param_2[2],(int)param_2[1],iVar3)
      ;
      goto LAB_0010f260;
    }
    if (local_50 >> 0x20 == 0) {
      iVar3 = 0;
      *(int *)*param_2 = (int)local_50;
      goto LAB_0010f260;
    }
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00115564,"synx_hwfence_import_indv",0x119,uVar1);
    msm_hw_fence_wait_update_v2(param_1,puVar7,&local_50,0,1,0);
  }
  iVar3 = -0x16;
LAB_0010f260:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hw_sync_debugfs_ioctl @ 0010f330 size=236
// signature: undefined hw_sync_debugfs_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_sync_debugfs_ioctl(long param_1,ulong param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  uVar4 = (param_2 & 0xff) - 2;
  uVar3 = (uint)uVar4;
  if (uVar3 < 0x12) {
    if ((0x28ffUL >> (uVar4 & 0x3f) & 1) == 0) {
      if ((long)(int)uVar3 * 0x18 - 0x1a9U < 0xfffffffffffffe4f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x10f41c);
        (*pcVar1)();
      }
      if (*(int *)(*(code **)(hw_sync_debugfs_ioctls + (long)(int)uVar3 * 0x18 + 8) + -4) !=
          0x5518c917) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f3a0);
        (*pcVar1)();
      }
      uVar2 = (**(code **)(hw_sync_debugfs_ioctls + (long)(int)uVar3 * 0x18 + 8))
                        (*(undefined8 *)(param_1 + 0xd8),param_3);
    }
    else {
      uVar4 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar4 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112794,"hw_sync_debugfs_ioctl",0x26a,uVar4);
      uVar2 = 0xffffffffffffffe7;
    }
  }
  else {
    uVar4 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar4 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00112faa,"hw_sync_debugfs_ioctl",0x264,uVar4);
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// hw_sync_debugfs_open @ 0010f420 size=96
// signature: undefined hw_sync_debugfs_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 hw_sync_debugfs_open(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)kmalloc_trace(_dma_fence_array_create,0xdc0,0x38);
  if (puVar1 == (undefined8 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    uVar2 = dma_fence_context_alloc(1);
    uVar3 = 0;
    *(undefined8 **)(param_2 + 0xd8) = puVar1;
    *puVar1 = uVar2;
  }
  return uVar3;
}



//------------------------------------------------------------
// hw_sync_debugfs_release @ 0010f484 size=48
// signature: undefined hw_sync_debugfs_release(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_sync_debugfs_release(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_2 + 0xd8) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    kfree();
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// hw_sync_ioctl_reg_client @ 0010f4b8 size=220
// signature: undefined hw_sync_ioctl_reg_client(void)
// callers: []
//------------------------------------------------------------

void hw_sync_ioctl_reg_client(long param_1)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong unaff_x30;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = _get_client_id();
  if (&local_2c < (uint *)0xfffffffffffff001) {
    if (*(long *)(param_1 + 0x10) == 0) {
      *(uint *)(param_1 + 8) = local_2c;
      uVar3 = msm_hw_fence_register(local_2c,param_1 + 0x18);
      lVar2 = -0x16;
      if (uVar3 < 0xfffffffffffff001 && uVar3 != 0) {
        lVar2 = 0;
      }
      *(ulong *)(param_1 + 0x10) = uVar3;
    }
    else {
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112345,"hw_sync_ioctl_reg_client",200,uVar3);
      lVar2 = -0x16;
    }
  }
  else {
    lVar2 = (long)(int)local_2c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// hw_sync_ioctl_unreg_client @ 0010f598 size=196
// signature: undefined hw_sync_ioctl_unreg_client(void)
// callers: []
//------------------------------------------------------------

void hw_sync_ioctl_unreg_client(long param_1)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong unaff_x30;
  int local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = _get_client_id();
  if (&local_2c < (int *)0xfffffffffffff001) {
    if (local_2c == *(int *)(param_1 + 8)) {
      iVar3 = msm_hw_fence_deregister(*(undefined8 *)(param_1 + 0x10));
      lVar4 = (long)iVar3;
    }
    else {
      uVar1 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar1 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_001127df,"hw_sync_ioctl_unreg_client",0xdc,uVar1);
      lVar4 = -0x16;
    }
  }
  else {
    lVar4 = (long)local_2c;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// hw_sync_ioctl_create_fence @ 0010f660 size=1448
// signature: undefined hw_sync_ioctl_create_fence(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long hw_sync_ioctl_create_fence(ulong *param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 *puVar5;
  long lVar6;
  ulong uVar7;
  int iVar8;
  long lVar9;
  undefined4 *puVar10;
  undefined8 *puVar11;
  ulong uVar12;
  ulong unaff_x30;
  undefined8 local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 *local_70;
  long local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  local_70 = (undefined8 *)0x0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  if (param_1 == (ulong *)0x0) {
    lVar9 = -0x16;
  }
  else if ((int)param_1[1] - 0xfU < 0xfffffff9) {
    uVar12 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar12 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar12,(int)param_1[1],8,0xe);
    lVar9 = -0x16;
  }
  else if ((param_1[2] == 0) || (0xfffffffffffff000 < param_1[2])) {
    uVar12 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar12 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001145db,"hw_sync_ioctl_create_fence",0xf0,uVar12);
    lVar9 = -0x16;
  }
  else {
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar12 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar12 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar12 < 0x7fffffffe9) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        uVar7 = ttbr1_el1;
        ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5[1];
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      lVar9 = __arch_copy_from_user(&local_90,param_2 & 0xff7fffffffffffff,0x18);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        uVar7 = ttbr1_el1;
        ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      if (lVar9 == 0) {
        puVar10 = (undefined4 *)kmalloc_trace(_dma_fence_array_create,0xdc0,4);
        if (puVar10 == (undefined4 *)0x0) {
          lVar9 = -0xc;
        }
        else {
          lVar9 = kmalloc_trace(_dma_fence_context_alloc,0xdc0,0x88);
          if (lVar9 == 0) {
            kfree(puVar10);
            lVar9 = -0xc;
          }
          else {
            snprintf((char *)(lVar9 + 0x40),0x40,"hwfence:id:%d:ctx=%lu:seqno:%lu",(int)param_1[1],
                     *param_1,local_90);
            uVar12 = *param_1;
            *puVar10 = 0;
            dma_fence_init(lVar9,&hw_fence_dbg_ops,puVar10,uVar12,local_90);
            if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
              _printk(&DAT_00113da0,"hw_sync_ioctl_create_fence",0x109,(int)param_1[1],*param_1,
                      local_90);
            }
            local_70 = &local_98;
            local_68 = lVar9;
            iVar8 = msm_hw_fence_create(param_1[2],&local_78);
            if (iVar8 == 0) {
              *(ulong *)(lVar9 + 0x80) = param_1[2];
              if ((char)local_88 != '\0') {
                uVar12 = dma_fence_context_alloc(1);
                *param_1 = uVar12;
              }
              iVar8 = get_unused_fd_flags(0);
              if (iVar8 < 0) {
                uVar12 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar12 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_0011692c,"hw_sync_ioctl_create_fence",0x11f,uVar12,(int)param_1[1]);
                dma_fence_put(lVar9);
                lVar9 = (long)iVar8;
              }
              else {
                puVar11 = (undefined8 *)sync_file_create(lVar9);
                if (puVar11 == (undefined8 *)0x0) {
                  uVar12 = unaff_x30 & 0xff80007fffffffff;
                  if ((unaff_x30 & 0x80000000000000) != 0) {
                    uVar12 = unaff_x30 | 0xffffff8000000000;
                  }
                  _printk(&DAT_0011794c,"hw_sync_ioctl_create_fence",0x126,uVar12,iVar8);
                  dma_fence_put(lVar9);
                  lVar9 = -0x16;
                }
                else {
                  piVar1 = (int *)(lVar9 + 0x38);
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    iVar2 = *piVar1;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar4) {
                      *piVar1 = iVar2 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar2 == 1) {
                    DataMemoryBarrier(2,1);
                    dma_fence_release(piVar1);
                  }
                  else if (iVar2 < 1) {
                    refcount_warn_saturate(piVar1,3);
                  }
                  local_88 = CONCAT44(iVar8,(undefined4)local_88);
                  local_80 = local_98;
                  if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
                     (uVar12 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
                    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
                  }
                  if (uVar12 < 0x7fffffffe9) {
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar12 = daif;
                      if ((uVar12 & 0x80) == 0) {
                        uVar7 = daif;
                        daif = uVar7 | 0xc0;
                      }
                      uVar7 = ttbr1_el1;
                      ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      ttbr0_el1 = puVar5[1];
                      InstructionSynchronizationBarrier();
                      daif = uVar12;
                    }
                    lVar9 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,&local_90,0x18);
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar12 = daif;
                      if ((uVar12 & 0x80) == 0) {
                        uVar7 = daif;
                        daif = uVar7 | 0xc0;
                      }
                      uVar7 = ttbr1_el1;
                      ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
                      InstructionSynchronizationBarrier();
                      ttbr1_el1 = uVar7 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      daif = uVar12;
                    }
                    if (lVar9 == 0) {
                      fd_install(iVar8,*puVar11);
                      lVar9 = 0;
                      goto LAB_0010fbdc;
                    }
                  }
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    iVar2 = *piVar1;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar4) {
                      *piVar1 = iVar2 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar2 == 1) {
                    DataMemoryBarrier(2,1);
                    dma_fence_release(piVar1);
                  }
                  else if (iVar2 < 1) {
                    refcount_warn_saturate(piVar1,3);
                  }
                  fput(*puVar11);
                  lVar9 = -0xe;
                }
                put_unused_fd(iVar8);
              }
            }
            else {
              uVar12 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar12 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00113100,"hw_sync_ioctl_create_fence",0x111,uVar12,(int)param_1[1],
                      *param_1,local_90);
              dma_fence_put(lVar9);
              lVar9 = -0x16;
            }
          }
        }
        goto LAB_0010fbdc;
      }
    }
    lVar9 = -0xe;
  }
LAB_0010fbdc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar9;
}



//------------------------------------------------------------
// hw_sync_ioctl_create_fence_array @ 0010fc5c size=2032
// signature: undefined hw_sync_ioctl_create_fence_array(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long hw_sync_ioctl_create_fence_array(undefined8 *param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 *puVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long *plVar9;
  undefined8 *puVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  ulong uVar14;
  ulong uVar15;
  ulong unaff_x30;
  ulong local_d0;
  ulong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_d0 = 0;
  if (param_1 == (undefined8 *)0x0) {
    lVar8 = -0x16;
    goto LAB_00110414;
  }
  if (*(int *)(param_1 + 1) - 0xfU < 0xfffffff9) {
    uVar12 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar12 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar12,*(int *)(param_1 + 1),8,0xe);
    lVar8 = -0x16;
    goto LAB_00110414;
  }
  if ((param_1[2] == 0) || (0xfffffffffffff000 < (ulong)param_1[2])) {
    uVar12 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar12 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_001145db,"hw_sync_ioctl_create_fence_array",0x155,uVar12);
    lVar8 = -0x16;
    goto LAB_00110414;
  }
  puVar5 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar12 < 0x7fffffff99) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar5[1];
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    lVar8 = __arch_copy_from_user(&local_d0,param_2 & 0xff7fffffffffffff,0x68);
    uVar12 = local_c8;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar15 = daif;
        daif = uVar15 | 0xc0;
      }
      uVar15 = ttbr1_el1;
      ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar15 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    if (lVar8 == 0) {
      iVar7 = (int)local_c8;
      uVar14 = local_c8 & 0xffffffff;
      if (10 < (int)local_c8) {
        uVar12 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar12 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00115121,"hw_sync_ioctl_create_fence_array",0x15f,uVar12,uVar14,10);
        lVar8 = -0x16;
        goto LAB_00110414;
      }
      if (-1 < (int)local_c8) {
        uVar15 = (long)(int)local_c8 * 8;
        plVar9 = (long *)__kmalloc(uVar15,0xdc0);
        if (plVar9 != (long *)0x0) {
          if (iVar7 == 0) {
LAB_0010fdf0:
            lVar8 = dma_fence_array_create
                              (uVar12 & 0xffffffff,plVar9,*param_1,local_d0 & 0xffffffff,0);
            if (lVar8 != 0) {
              iVar7 = get_unused_fd_flags(0);
              if (iVar7 < 1) {
                uVar12 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar12 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_0011692c,"hw_sync_ioctl_create_fence_array",0x185,uVar12,
                        *(undefined4 *)(param_1 + 1));
                dma_fence_put(lVar8);
                lVar8 = (long)iVar7;
              }
              else {
                puVar10 = (undefined8 *)sync_file_create(lVar8);
                if (puVar10 == (undefined8 *)0x0) {
                  uVar12 = unaff_x30 & 0xff80007fffffffff;
                  if ((unaff_x30 & 0x80000000000000) != 0) {
                    uVar12 = unaff_x30 | 0xffffff8000000000;
                  }
                  _printk(&DAT_0011794c,"hw_sync_ioctl_create_fence_array",0x18c,uVar12,iVar7);
                  dma_fence_put(lVar8);
                  kfree(lVar8);
                  lVar8 = -0x16;
                }
                else {
                  piVar1 = (int *)(lVar8 + 0x38);
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    iVar2 = *piVar1;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar4) {
                      *piVar1 = iVar2 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar2 == 1) {
                    DataMemoryBarrier(2,1);
                    dma_fence_release();
                  }
                  else if (iVar2 < 1) {
                    refcount_warn_saturate(piVar1,3);
                  }
                  local_70 = CONCAT44(local_70._4_4_,iVar7);
                  if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
                     (uVar12 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
                    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
                  }
                  if (uVar12 < 0x7fffffff99) {
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar12 = daif;
                      if ((uVar12 & 0x80) == 0) {
                        uVar14 = daif;
                        daif = uVar14 | 0xc0;
                      }
                      uVar14 = ttbr1_el1;
                      ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      ttbr0_el1 = puVar5[1];
                      InstructionSynchronizationBarrier();
                      daif = uVar12;
                    }
                    lVar11 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,&local_d0,0x68);
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
                    if (lVar11 == 0) {
                      fd_install(iVar7,*puVar10);
                      lVar8 = 0;
                      goto LAB_00110414;
                    }
                  }
                  fput(*puVar10);
                  dma_fence_put(lVar8);
                  lVar8 = -0xe;
                }
                put_unused_fd(iVar7);
              }
              goto LAB_00110414;
            }
            uVar12 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar12 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00115ac6,"hw_sync_ioctl_create_fence_array",0x17a,uVar12);
            if (iVar7 != 0) {
              plVar13 = plVar9;
              do {
                if (*plVar13 != 0) {
                  piVar1 = (int *)(*plVar13 + 0x38);
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    iVar7 = *piVar1;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar4) {
                      *piVar1 = iVar7 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar7 == 1) {
                    DataMemoryBarrier(2,1);
                    dma_fence_release();
                  }
                  else if (iVar7 < 1) {
                    refcount_warn_saturate(piVar1,3);
                  }
                }
                plVar13 = plVar13 + 1;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
          }
          else if ((0 < (int)local_c0) && (lVar8 = sync_file_get_fence(), lVar8 != 0)) {
            *plVar9 = lVar8;
            if (iVar7 == 1) goto LAB_0010fdf0;
            if (0 < (int)local_b8) {
              lVar8 = sync_file_get_fence();
              if (lVar8 != 0) {
                if (iVar7 == 1) {
LAB_001102cc:
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(1,0x1102d0);
                  (*pcVar6)();
                }
                plVar9[1] = lVar8;
                if (iVar7 != 2) {
                  if ((int)local_b0 < 1) goto LAB_00110238;
                  lVar8 = sync_file_get_fence();
                  if (lVar8 == 0) {
                    lVar8 = 1;
                    goto LAB_001101b4;
                  }
                  if ((uVar15 < 0x10) || (iVar7 == 2)) goto LAB_001102cc;
                  plVar9[2] = lVar8;
                  if (iVar7 != 3) {
                    if ((int)local_a8 < 1) goto LAB_00110238;
                    lVar8 = sync_file_get_fence();
                    if (lVar8 == 0) {
                      lVar8 = 2;
                      goto LAB_001101b4;
                    }
                    if ((uVar15 < 0x18) || (iVar7 == 3)) goto LAB_001102cc;
                    plVar9[3] = lVar8;
                    if (iVar7 != 4) {
                      if ((int)local_a0 < 1) goto LAB_00110238;
                      lVar8 = sync_file_get_fence();
                      if (lVar8 == 0) {
                        lVar8 = 3;
                        goto LAB_001101b4;
                      }
                      if ((uVar15 < 0x20) || (iVar7 == 4)) goto LAB_001102cc;
                      plVar9[4] = lVar8;
                      if (iVar7 != 5) {
                        if ((int)local_98 < 1) goto LAB_00110238;
                        lVar8 = sync_file_get_fence();
                        if (lVar8 == 0) {
                          lVar8 = 4;
                          goto LAB_001101b4;
                        }
                        if ((uVar15 < 0x28) || (iVar7 == 5)) goto LAB_001102cc;
                        plVar9[5] = lVar8;
                        if (iVar7 != 6) {
                          if ((int)local_90 < 1) goto LAB_00110238;
                          lVar8 = sync_file_get_fence();
                          if (lVar8 == 0) {
                            lVar8 = 5;
                            goto LAB_001101b4;
                          }
                          if ((uVar15 < 0x30) || (iVar7 == 6)) goto LAB_001102cc;
                          plVar9[6] = lVar8;
                          if (iVar7 != 7) {
                            if ((int)local_88 < 1) goto LAB_00110238;
                            lVar8 = sync_file_get_fence();
                            if (lVar8 == 0) {
                              lVar8 = 6;
                              goto LAB_001101b4;
                            }
                            if ((uVar15 < 0x38) || (iVar7 == 7)) goto LAB_001102cc;
                            plVar9[7] = lVar8;
                            if (iVar7 != 8) {
                              if ((int)local_80 < 1) goto LAB_00110238;
                              lVar8 = sync_file_get_fence();
                              if (lVar8 == 0) {
                                lVar8 = 7;
                                goto LAB_001101b4;
                              }
                              if ((uVar15 < 0x40) || (iVar7 == 8)) goto LAB_001102cc;
                              plVar9[8] = lVar8;
                              if (iVar7 != 9) {
                                if ((int)local_78 < 1) goto LAB_00110238;
                                lVar8 = sync_file_get_fence();
                                if (lVar8 == 0) {
                                  lVar8 = 8;
                                  goto LAB_001101b4;
                                }
                                if ((uVar15 < 0x48) || (iVar7 == 9)) goto LAB_001102cc;
                                plVar9[9] = lVar8;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                goto LAB_0010fdf0;
              }
              lVar8 = 0;
LAB_001101b4:
              iVar7 = (int)lVar8 + 1;
              do {
                if (uVar15 <= (ulong)(lVar8 * 8)) goto LAB_001102cc;
                if (plVar9[lVar8] != 0) {
                  piVar1 = (int *)(plVar9[lVar8] + 0x38);
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    iVar2 = *piVar1;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar4) {
                      *piVar1 = iVar2 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar2 == 1) {
                    DataMemoryBarrier(2,1);
                    dma_fence_release();
                  }
                  else if (iVar2 < 1) {
                    refcount_warn_saturate(piVar1,3);
                  }
                }
                iVar7 = iVar7 + -1;
              } while (0 < iVar7);
            }
          }
LAB_00110238:
          kfree(plVar9);
          lVar8 = -0x16;
          goto LAB_00110414;
        }
      }
      lVar8 = -0xc;
      goto LAB_00110414;
    }
  }
  lVar8 = -0xe;
LAB_00110414:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar8;
}



//------------------------------------------------------------
// hw_sync_ioctl_reg_for_wait @ 001104a8 size=608
// signature: undefined hw_sync_ioctl_reg_for_wait(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_sync_ioctl_reg_for_wait(long param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  ulong unaff_x30;
  int local_34;
  long local_30;
  long local_28;
  
  lVar8 = sp_el0;
  local_28 = *(long *)(lVar8 + 0x638);
  local_34 = 0;
  if (param_1 == 0) {
    lVar8 = -0x16;
  }
  else if (*(int *)(param_1 + 8) - 0xfU < 0xfffffff9) {
    uVar10 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar10 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar10,*(int *)(param_1 + 8),8,0xe);
    lVar8 = -0x16;
  }
  else {
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar10 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar6 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      lVar8 = __arch_copy_from_user(puVar9,&local_34,param_2 & 0xff7fffffffffffff,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        uVar6 = ttbr1_el1;
        ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if (lVar8 == 0) {
        if ((local_34 < 0) || (local_30 = sync_file_get_fence(local_34), local_30 == 0)) {
          uVar10 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar10 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00117133,"hw_sync_ioctl_reg_for_wait",0x1b9,uVar10,local_34);
          lVar8 = -0x16;
        }
        else {
          iVar7 = msm_hw_fence_wait_update_v2(*(undefined8 *)(param_1 + 0x10),&local_30,0,0,1,1);
          if (local_30 != 0) {
            piVar1 = (int *)(local_30 + 0x38);
            Hint_Prefetch(piVar1,2,0,1);
            do {
              iVar2 = *piVar1;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar4) {
                *piVar1 = iVar2 + -1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            if (iVar2 == 1) {
              DataMemoryBarrier(2,1);
              dma_fence_release();
            }
            else if (iVar2 < 1) {
              refcount_warn_saturate(piVar1,3);
            }
          }
          lVar8 = (long)iVar7;
        }
        goto LAB_001106e8;
      }
    }
    lVar8 = -0xe;
  }
LAB_001106e8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar8);
  }
  return;
}



//------------------------------------------------------------
// hw_sync_ioctl_fence_signal @ 00110734 size=700
// signature: undefined hw_sync_ioctl_fence_signal(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_sync_ioctl_fence_signal(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  undefined8 local_48;
  ulong local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_48 = 0;
  local_40 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) - 0xfU < 0xfffffff9) {
      uVar9 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar9 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar9,*(int *)(param_1 + 8),8,0xe);
    }
    else {
      uVar9 = *(ulong *)(param_1 + 0x10);
      if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar8 = param_2 & (long)(param_2 << 8) >> 8;
        }
        if (uVar8 < 0x7ffffffff1) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar8 = daif;
            if ((uVar8 & 0x80) == 0) {
              uVar3 = daif;
              daif = uVar3 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar3 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar8;
          }
          lVar6 = __arch_copy_from_user(puVar7,&local_48,param_2 & 0xff7fffffffffffff,0x10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar8 = daif;
            if ((uVar8 & 0x80) == 0) {
              uVar3 = daif;
              daif = uVar3 | 0xc0;
            }
            uVar3 = ttbr1_el1;
            ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar3 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar8;
          }
          if (lVar6 == 0) {
            iVar5 = msm_hw_fence_update_txq
                              (*(undefined8 *)(param_1 + 0x10),local_48,0,local_40 & 0xffffffff);
            if (iVar5 == 0) {
              uVar1 = *(uint *)(param_1 + 8);
              if (0xe < uVar1) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1109d4);
                (*pcVar4)();
              }
              if (0xac < (ulong)uVar1 * 0xc) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(1,0x1109d8);
                (*pcVar4)();
              }
              iVar5 = msm_hw_fence_trigger_signal
                                (*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(uVar9 + 0xd8),
                                 *(undefined4 *)(uVar9 + 0xd4),
                                 *(undefined4 *)
                                  (dbg_out_clients_signal_map_no_dpu + (ulong)uVar1 * 0xc + 8));
              if (iVar5 == 0) {
                lVar6 = 0;
              }
              else {
                uVar9 = unaff_x30 & 0xff80007fffffffff;
                if ((unaff_x30 & 0x80000000000000) != 0) {
                  uVar9 = unaff_x30 | 0xffffff8000000000;
                }
                _printk(&DAT_00115a24,"hw_sync_ioctl_fence_signal",0x1e9,uVar9);
                lVar6 = (long)iVar5;
              }
            }
            else {
              uVar9 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar9 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00115174,"hw_sync_ioctl_fence_signal",0x1dd,uVar9,
                      *(undefined4 *)(param_1 + 8));
              lVar6 = (long)iVar5;
            }
            goto LAB_0011091c;
          }
        }
        lVar6 = -0xe;
        goto LAB_0011091c;
      }
      uVar9 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar9 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112bc6,"hw_sync_ioctl_fence_signal",0x1ce,uVar9);
    }
  }
  lVar6 = -0x16;
LAB_0011091c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// hw_sync_ioctl_fence_wait @ 00110a0c size=1384
// signature: undefined hw_sync_ioctl_fence_wait(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long hw_sync_ioctl_fence_wait(long param_1,ulong param_2)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  undefined8 *puVar12;
  ulong uVar13;
  ulong unaff_x30;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulong local_a8;
  ulong local_a0;
  undefined8 local_98;
  long local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulong local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  if (param_1 == 0) {
    lVar7 = -0x16;
  }
  else if (*(int *)(param_1 + 8) - 0xfU < 0xfffffff9) {
    uVar13 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar13 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar13,*(int *)(param_1 + 8),8,0xe);
    lVar7 = -0x16;
  }
  else {
    puVar12 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
       (uVar13 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
      uVar13 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar13 < 0x7ffffffff1) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar13 = daif;
        if ((uVar13 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        puVar12 = (undefined8 *)puVar12[1];
        uVar10 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar12;
        InstructionSynchronizationBarrier();
        daif = uVar13;
      }
      lVar7 = __arch_copy_from_user(puVar12,&local_a8,param_2 & 0xff7fffffffffffff,0x10);
      uVar13 = local_a8;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if (lVar7 == 0) {
        if (((int)local_a8 < 0) || (lVar8 = sync_file_get_fence(local_a8 & 0xffffffff), lVar8 == 0))
        {
          uVar10 = unaff_x30 & 0xff80007fffffffff;
          if ((unaff_x30 & 0x80000000000000) != 0) {
            uVar10 = unaff_x30 | 0xffffff8000000000;
          }
          _printk(&DAT_00117133,"hw_sync_ioctl_fence_wait",0x202,uVar10,uVar13 & 0xffffffff);
          lVar7 = -0x16;
        }
        else {
          lVar7 = *(long *)(param_1 + 0x10);
          if (lVar7 == 0) {
            uVar10 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar10 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00116045,"hw_sync_ioctl_fence_wait",0x208,uVar10,uVar13 & 0xffffffff);
            dma_fence_put(lVar8);
            lVar7 = -0x16;
          }
          else {
            lVar9 = ktime_get();
            lVar1 = lVar7 + 0xe0;
            lVar9 = lVar9 + local_a0 * 1000000;
            while( true ) {
              uVar13 = __msecs_to_jiffies(local_a0 & 0xffffffff);
              if (uVar13 == 0 && 0 < *(int *)(lVar7 + 0xf8)) {
                uVar13 = 1;
              }
              if ((*(int *)(lVar7 + 0xf8) < 1) && (uVar13 != 0)) {
                local_b8 = 0;
                uStack_b0 = 0;
                local_c8 = 0;
                uStack_c0 = 0;
                local_d0 = 0;
                uVar10 = __msecs_to_jiffies(local_a0 & 0xffffffff);
                init_wait_entry(&local_d0,0);
                prepare_to_wait_event(lVar1,&local_d0,2);
                iVar6 = *(int *)(lVar7 + 0xf8);
                if (uVar10 == 0 && 0 < iVar6) {
                  uVar10 = 1;
                }
                while ((uVar13 = uVar10, iVar6 < 1 && (uVar13 = 0, uVar10 != 0))) {
                  uVar10 = schedule_timeout(uVar10);
                  prepare_to_wait_event(lVar1,&local_d0,2);
                  iVar6 = *(int *)(lVar7 + 0xf8);
                  if (uVar10 == 0 && 0 < iVar6) {
                    uVar10 = 1;
                  }
                }
                finish_wait(lVar1,&local_d0);
              }
              lVar11 = ktime_get();
              if ((0 < *(int *)(lVar7 + 0xf8)) || ((uVar13 & 0xffffffff) != 0)) break;
              if ((lVar9 == lVar11) || (lVar9 - lVar11 < 0)) goto LAB_00110d40;
            }
            if ((uVar13 & 0xffffffff) != 0) {
              *(undefined4 *)(lVar7 + 0xf8) = 0;
              goto LAB_00110c70;
            }
LAB_00110d40:
            uVar13 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar13 = unaff_x30 | 0xffffff8000000000;
            }
            _printk(&DAT_00117e41,"hw_sync_ioctl_fence_wait",0x218,uVar13,local_a0);
            dma_fence_put(lVar8);
            lVar7 = -0x6e;
          }
        }
        goto LAB_00110f64;
      }
    }
    lVar7 = -0xe;
  }
  goto LAB_00110f64;
  while( true ) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_0011827d,"hw_sync_ioctl_fence_wait",0x228,local_80,local_78,local_68 & 0xffffffff
             );
    }
    if ((local_90 == *(long *)(lVar8 + 0x20)) && (local_88 == *(long *)(lVar8 + 0x28))) {
      piVar2 = (int *)(lVar8 + 0x38);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar6 = *piVar2;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar4) {
          *piVar2 = iVar6 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (iVar6 == 1) {
        DataMemoryBarrier(2,1);
        dma_fence_release();
        lVar7 = 0;
      }
      else if (iVar6 < 1) {
        refcount_warn_saturate(piVar2,3);
        lVar7 = 0;
      }
      else {
        lVar7 = 0;
      }
      goto LAB_00110f64;
    }
    if (iVar6 == 0) break;
LAB_00110c70:
    iVar6 = hw_fence_read_queue(*(undefined8 *)(param_1 + 0x10),&local_98,1);
    if (iVar6 < 0) {
      uVar13 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar13 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00112c0f,"hw_sync_ioctl_fence_wait",0x224,uVar13,*(undefined4 *)(param_1 + 8));
      lVar7 = (long)iVar6;
      goto LAB_00110dc4;
    }
  }
  lVar7 = 0;
LAB_00110dc4:
  piVar2 = (int *)(lVar8 + 0x38);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    iVar6 = *piVar2;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = iVar6 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar6 == 1) {
    DataMemoryBarrier(2,1);
    dma_fence_release();
  }
  else if (iVar6 < 1) {
    refcount_warn_saturate(piVar2,3);
  }
  uVar13 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar13 = unaff_x30 | 0xffffff8000000000;
  }
  _printk(&DAT_00113d11,"hw_sync_ioctl_fence_wait",0x233,uVar13);
  _printk(&DAT_0011343f,"hw_sync_ioctl_fence_wait",0x235,uVar13,local_90,local_88,
          *(undefined8 *)(lVar8 + 0x20),*(undefined8 *)(lVar8 + 0x28));
LAB_00110f64:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}



//------------------------------------------------------------
// hw_sync_ioctl_reset_client @ 00110fb0 size=548
// signature: undefined hw_sync_ioctl_reset_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_sync_ioctl_reset_client(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong unaff_x30;
  undefined8 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) - 0xfU < 0xfffffff9) {
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00117a18,"_is_valid_client",0x88,uVar6,*(int *)(param_1 + 8),8,0xe);
    }
    else {
      if ((*(ulong *)(param_1 + 0x10) != 0) && (*(ulong *)(param_1 + 0x10) < 0xfffffffffffff001)) {
        puVar5 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
           (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
          uVar6 = param_2 & (long)(param_2 << 8) >> 8;
        }
        if (uVar6 < 0x7ffffffff9) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar6 = daif;
            if ((uVar6 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            puVar5 = (undefined8 *)puVar5[1];
            uVar2 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar5;
            InstructionSynchronizationBarrier();
            daif = uVar6;
          }
          lVar4 = __arch_copy_from_user(puVar5,&local_30,param_2 & 0xff7fffffffffffff,8);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar6 = daif;
            if ((uVar6 & 0x80) == 0) {
              uVar2 = daif;
              daif = uVar2 | 0xc0;
            }
            uVar2 = ttbr1_el1;
            ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar2 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar6;
          }
          if (lVar4 == 0) {
            iVar3 = msm_hw_fence_reset_client(*(undefined8 *)(param_1 + 0x10),local_30._4_4_);
            if (iVar3 == 0) {
              lVar4 = 0;
            }
            else {
              uVar6 = unaff_x30 & 0xff80007fffffffff;
              if ((unaff_x30 & 0x80000000000000) != 0) {
                uVar6 = unaff_x30 | 0xffffff8000000000;
              }
              _printk(&DAT_00113860,"hw_sync_ioctl_reset_client",0x24b,uVar6);
              lVar4 = (long)iVar3;
            }
            goto LAB_0011114c;
          }
        }
        lVar4 = -0xe;
        goto LAB_0011114c;
      }
      uVar6 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar6 = unaff_x30 | 0xffffff8000000000;
      }
      _printk(&DAT_00113823,"hw_sync_ioctl_reset_client",0x242,uVar6);
    }
  }
  lVar4 = -0x16;
LAB_0011114c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// _get_client_id @ 001111ec size=400
// signature: undefined _get_client_id(void)
// callers: [hw_sync_ioctl_reg_client, hw_sync_ioctl_unreg_client]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _get_client_id(long param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  ulong unaff_x30;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  puVar4 = (undefined8 *)sp_el0;
  local_2c = 0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    lVar2 = __arch_copy_from_user(puVar4,&local_2c,param_2 & 0xff7fffffffffffff,4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    if (lVar2 == 0) {
      if (param_1 != 0) {
        iVar3 = local_2c;
        if (0xfffffff8 < local_2c - 0xfU) goto LAB_0011132c;
        uVar5 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar5 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_00117a18,"_get_client_id",0x9b,uVar5,local_2c,8,0xe);
      }
      iVar3 = -0x16;
      goto LAB_0011132c;
    }
  }
  iVar3 = -0xe;
LAB_0011132c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// dma_fence_put @ 00111394 size=100
// signature: undefined dma_fence_put(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_fence_wait, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

void dma_fence_put(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x38);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 == 1) {
      DataMemoryBarrier(2,1);
      dma_fence_release();
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return;
}



//------------------------------------------------------------
// hw_fence_dbg_get_driver_name @ 0011140c size=8
// signature: undefined hw_fence_dbg_get_driver_name(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_get_driver_name(long param_1)

{
  return param_1 + 0x40;
}



//------------------------------------------------------------
// hw_fence_dbg_get_timeline_name @ 00111418 size=8
// signature: undefined hw_fence_dbg_get_timeline_name(void)
// callers: []
//------------------------------------------------------------

long hw_fence_dbg_get_timeline_name(long param_1)

{
  return param_1 + 0x40;
}



//------------------------------------------------------------
// hw_fence_dbg_enable_signaling @ 00111424 size=8
// signature: undefined hw_fence_dbg_enable_signaling(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_fence_dbg_enable_signaling(void)

{
  return 1;
}



//------------------------------------------------------------
// hw_fence_dbg_release @ 00111430 size=236
// signature: undefined hw_fence_dbg_release(void)
// callers: []
//------------------------------------------------------------

void hw_fence_dbg_release(undefined8 *param_1)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00114bf7,"hw_fence_dbg_release",0xbd,param_1);
    iVar1 = (int)param_1[6];
  }
  else {
    iVar1 = (int)param_1[6];
  }
  if (iVar1 < 0) {
    uVar2 = param_1[0x10];
    if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
      puVar3 = &DAT_00116aaa;
      uVar4 = 0xad;
    }
    else {
      iVar1 = msm_hw_fence_destroy(uVar2,param_1);
      if (iVar1 == 0) goto LAB_00111484;
      puVar3 = &DAT_00114633;
      uVar4 = 0xb3;
    }
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(puVar3,"_hw_fence_release",uVar4,uVar2);
  }
LAB_00111484:
  kfree(*param_1);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// init_module @ 0011a4a8 size=220
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  ulong uVar1;
  int iVar2;
  ulong unaff_x30;
  
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00112ea9,"msm_hw_fence_init",0x309);
  }
  iVar2 = __platform_driver_register(&msm_hw_fence_driver,&__this_module);
  if (iVar2 == 0) {
    if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00113698,"msm_hw_fence_init",0x312);
    }
  }
  else {
    uVar1 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar1 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0011689f,"msm_hw_fence_init",0x30e,uVar1,"msm_hw_fence_init");
  }
  return iVar2;
}



//------------------------------------------------------------
// cleanup_module @ 0011a588 size=132
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00112ea9,"msm_hw_fence_exit",0x319);
  }
  platform_driver_unregister(&msm_hw_fence_driver);
  if (((msm_hw_fence_debug_level ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00113698,"msm_hw_fence_exit",0x31d);
  }
  return;
}



//------------------------------------------------------------
// mutex_lock @ 0011c000 size=1
// signature: undefined mutex_lock(void)
// callers: [hw_fence_cleanup_client, _get_client_node, hw_fence_dbg_create_join_fence, msm_hw_fence_register, process_validation_client_loopback, hw_fence_utils_fence_error_cb, hw_fence_dbg_register_clients_wr, hw_fence_dbg_tx_and_signal_clients_wr, hw_fence_dbg_reset_client_wr, hw_fence_dbg_create_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011c008 size=1
// signature: undefined mutex_unlock(void)
// callers: [hw_fence_cleanup_client, msm_hw_fence_deregister_error_cb, _get_client_node, hw_fence_dbg_create_join_fence, msm_hw_fence_register, process_validation_client_loopback, hw_fence_utils_fence_error_cb, hw_fence_dbg_register_clients_wr, hw_fence_dbg_tx_and_signal_clients_wr, hw_fence_dbg_reset_client_wr, hw_fence_dbg_create_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011c010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hw_sync_ioctl_reg_client, hw_fence_utils_cleanup_fence, hw_sync_ioctl_fence_signal, _debugfs_ipcc_trigger, hw_fence_utils_map_ipcc, hw_fence_utils_alloc_mem, hw_fence_update_existing_txq_payload, hw_fence_dbg_create_join_fence, hw_fence_dbg_dump_events_rd, msm_hw_fence_wait_update_v2, hw_fence_ipcc_enable_signaling, hw_fence_debug_dump_table, hw_fence_init, hw_fence_utils_fence_error_cb, hw_fence_dbg_register_clients_wr, msm_hw_fence_dump_fence, hw_fence_dbg_dump_table_rd, hw_sync_ioctl_create_fence, _hw_fence_cb, hw_sync_ioctl_create_fence_array, hw_sync_ioctl_reg_for_wait, _get_client_id, hw_sync_ioctl_fence_wait, hw_fence_rm_cb, hw_fence_process_fence_array, hw_fence_debug_dump_events, hw_sync_ioctl_reset_client, hw_fence_dbg_dump_table_wr, hw_fence_dbg_tx_and_signal_clients_wr, hw_fence_dbg_create_wr, hw_fence_utils_parse_dt_props, hw_fence_debug_dump_fence, synx_hwfence_import_indv, hw_fence_destroy, hw_fence_gunyah_share_mem, init_hw_fences_queues, _get_debugfs_input_client, hw_fence_dbg_dump_queues_wr, hw_fence_utils_map_qtime, hw_fence_utils_process_doorbell_mask, synx_hwfence_create, hw_sync_ioctl_unreg_client, _dump_fence_helper, hw_fence_dbg_reset_client_wr, hw_fence_destroy_with_hash]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0011c018 size=1
// signature: undefined scnprintf(void)
// callers: [_dump_event, hw_fence_dbg_dump_events_rd, _dump_fence_helper, hw_fence_dbg_dump_table_rd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011c020 size=1
// signature: undefined _printk(void)
// callers: [msm_hw_fence_create, hw_fence_utils_alloc_mem, hw_fence_register_wait_client, hw_fence_dbg_create_join_fence, msm_hw_fence_register, hw_fence_alloc_client_resources, _unreserve_hw_fence, msm_hw_fence_register_error_cb, msm_hw_fence_driver_doorbell_sim, hw_sync_ioctl_create_fence, hw_fence_utils_get_queues_num, _hw_fence_cb, cleanup_module, hw_fence_create, init_module, hw_fence_destroy, hw_fence_process_fence, hw_fence_dbg_dump_queues_wr, hw_fence_utils_map_qtime, msm_hw_fence_destroy_with_handle, hw_sync_debugfs_ioctl, _dump_fence_helper, hw_fence_dbg_reset_client_wr, hw_sync_ioctl_reg_client, hw_sync_ioctl_fence_signal, msm_hw_fence_deregister, _get_hw_fence_client_id, hw_fence_update_queue, synx_hwfence_initialize, msm_hw_fence_wait_update_v2, synx_hwfence_signal, hw_fence_dbg_release, msm_hw_fence_reset_client_by_id, hw_fence_ipcc_trigger_signal, msm_hw_fence_dump_fence, hw_fence_ipcc_enable_dpu_signaling, hw_fence_debug_dump_queues, synx_hwfence_import, hw_sync_ioctl_fence_wait, hw_fence_dbg_create_wr, msm_hw_fence_trigger_signal, hw_fence_utils_reserve_mem, synx_hwfence_import_indv, hw_fence_debug_debugfs_register, _reserve_hw_fence, init_hw_fences_queues, _get_debugfs_input_client, msm_hw_fence_reset_client, hw_fence_utils_process_doorbell_mask, hw_sync_ioctl_unreg_client, msm_hw_fence_dump_debug_data, msm_hw_fence_remove, _dump_event, hw_fence_cleanup_client, hw_fence_utils_map_ipcc, _fence_found, hw_fence_dbg_dump_events_rd, synx_hwfence_release, hw_fence_read_queue_helper, msm_hw_fence_destroy, hw_fence_ipcc_enable_signaling, hw_fence_read_queue, hw_fence_utils_fence_error_cb, hw_fence_dbg_register_clients_wr, hw_fence_dbg_dump_table_rd, msm_hw_fence_update_txq, hw_fence_init_controller_signal, hw_sync_ioctl_create_fence_array, hw_fence_utils_init_virq, _get_client_id, _hw_fence_lookup_and_process, hw_fence_dbg_dump_table_wr, hw_fence_utils_reset_queues, hw_fence_utils_parse_dt_props, synx_hwfence_uninitialize, hw_fence_gunyah_share_mem, hw_fence_destroy_with_hash, hw_fence_utils_cleanup_fence, _debugfs_ipcc_trigger, msm_hw_fence_deregister_error_cb, hw_fence_update_existing_txq_payload, _reserve_join_fence, synx_hwfence_recover, hw_fence_init, msm_hw_fence_find, _fence_ctl_signal, hw_sync_ioctl_reg_for_wait, hw_fence_rm_cb, hw_fence_process_fence_array, hw_fence_dbg_release, hw_fence_debug_dump_events, hw_sync_ioctl_reset_client, global_atomic_store, hw_fence_dbg_tx_and_signal_clients_wr, msm_hw_fence_probe, msm_hw_fence_update_txq_error, _dump_queue, process_validation_client_loopback, synx_hwfence_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0011c028 size=1
// signature: undefined __wake_up(void)
// callers: [process_validation_client_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0011c030 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [hw_fence_debug_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011c038 size=1
// signature: undefined __mutex_init(void)
// callers: [hw_fence_debug_debugfs_register, msm_hw_fence_register, msm_hw_fence_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0011c040 size=1
// signature: undefined debugfs_create_file(void)
// callers: [hw_fence_debug_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 0011c048 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [hw_fence_debug_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 0011c050 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [hw_fence_debug_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u64 @ 0011c058 size=1
// signature: undefined debugfs_create_u64(void)
// callers: [hw_fence_debug_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0011c060 size=1
// signature: undefined __check_object_size(void)
// callers: [_get_debugfs_input_client, hw_fence_dbg_dump_events_rd, hw_fence_dbg_dump_table_wr, hw_fence_dbg_tx_and_signal_clients_wr, hw_fence_dbg_dump_table_rd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0011c078 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [hw_sync_ioctl_fence_signal, hw_sync_ioctl_create_fence_array, hw_sync_ioctl_reg_for_wait, _get_client_id, hw_sync_ioctl_fence_wait, _get_debugfs_input_client, hw_sync_ioctl_reset_client, hw_fence_dbg_dump_table_wr, hw_fence_dbg_tx_and_signal_clients_wr, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0011c080 size=1
// signature: undefined kstrtouint(void)
// callers: [_get_debugfs_input_client, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0011c098 size=1
// signature: undefined kmalloc_trace(void)
// callers: [hw_sync_debugfs_open, hw_fence_gunyah_share_mem, hw_fence_dbg_create_join_fence, msm_hw_fence_register, hw_fence_dbg_dump_events_rd, hw_fence_dbg_register_clients_wr, msm_hw_fence_probe, hw_fence_dbg_create_wr, hw_fence_dbg_dump_table_rd, synx_hwfence_initialize, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_context_alloc @ 0011c0a0 size=1
// signature: undefined dma_fence_context_alloc(void)
// callers: [hw_sync_debugfs_open, hw_fence_dbg_register_clients_wr, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_context_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0011c0a8 size=1
// signature: undefined __list_add_valid(void)
// callers: [hw_fence_dbg_register_clients_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0011c0b0 size=1
// signature: undefined usleep_range_state(void)
// callers: [hw_fence_dbg_create_join_fence, hw_fence_dbg_tx_and_signal_clients_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_init @ 0011c0b8 size=1
// signature: undefined dma_fence_init(void)
// callers: [hw_fence_dbg_create_join_fence, hw_fence_dbg_create_wr, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_array_create @ 0011c0c0 size=1
// signature: undefined dma_fence_array_create(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_fence_dbg_create_join_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_array_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_release @ 0011c0c8 size=1
// signature: undefined dma_fence_release(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_reg_for_wait, hw_sync_ioctl_fence_wait, dma_fence_put, hw_fence_dbg_create_join_fence, dma_fence_put, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011c0d0 size=1
// signature: undefined kfree(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_fence_cleanup_client, hw_sync_debugfs_release, hw_fence_dbg_create_join_fence, msm_hw_fence_register, hw_fence_dbg_release, hw_fence_dbg_dump_events_rd, msm_hw_fence_probe, hw_fence_dbg_create_wr, synx_hwfence_initialize, synx_hwfence_uninitialize, hw_fence_gunyah_share_mem, hw_fence_dbg_release, _cleanup_fences, hw_fence_dbg_dump_table_rd, msm_hw_fence_remove, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0011c0d8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_reg_for_wait, hw_sync_ioctl_fence_wait, dma_fence_put, hw_fence_dbg_create_join_fence, dma_fence_put, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0011c0e0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [hw_fence_dbg_create_wr, hw_fence_utils_parse_dt_props, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0011c0e8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_fence_dbg_dump_events_rd, hw_fence_dbg_dump_table_rd, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 0011c0f0 size=1
// signature: undefined __copy_overflow(void)
// callers: [hw_fence_dbg_dump_events_rd, hw_fence_dbg_dump_table_rd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0011c0f8 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [hw_fence_dbg_dump_table_wr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0011c110 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writeq_relaxed, writel_relaxed, writew_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0011c118 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writeq_relaxed, writel_relaxed, writew_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011c120 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [hw_fence_ipcc_enable_signaling, hw_fence_utils_map_ipcc, hw_fence_utils_init_virq, hw_fence_utils_alloc_mem, hw_fence_utils_map_qtime, hw_fence_utils_parse_dt_props]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0011c128 size=1
// signature: undefined __kmalloc(void)
// callers: [hw_fence_ipcc_enable_signaling, hw_sync_ioctl_create_fence_array, hw_fence_utils_parse_dt_props]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011c130 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [hw_fence_ipcc_enable_signaling]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0011c140 size=1
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
// log_post_read_mmio @ 0011c148 size=1
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
// preempt_schedule @ 0011c158 size=1
// signature: undefined preempt_schedule(void)
// callers: [global_atomic_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 0011c160 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [hw_fence_utils_init_virq, hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_register @ 0011c168 size=1
// signature: undefined gh_dbl_rx_register(void)
// callers: [hw_fence_utils_init_virq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_read_and_clean @ 0011c170 size=1
// signature: undefined gh_dbl_read_and_clean(void)
// callers: [_hw_fence_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_read_and_clean(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011c178 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 0011c180 size=1
// signature: undefined of_address_to_resource(void)
// callers: [hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 0011c188 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 0011c190 size=1
// signature: undefined __memset_io(void)
// callers: [hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 0011c198 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [hw_fence_utils_alloc_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 0011c1a0 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [hw_fence_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_cpusys_vm_get_share_mem_info @ 0011c1a8 size=1
// signature: undefined gh_cpusys_vm_get_share_mem_info(void)
// callers: [hw_fence_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_cpusys_vm_get_share_mem_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011c1b0 size=1
// signature: undefined of_find_property(void)
// callers: [hw_fence_utils_parse_dt_props]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0011c1b8 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [hw_fence_utils_parse_dt_props]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0011c1c0 size=1
// signature: undefined devm_ioremap(void)
// callers: [hw_fence_utils_map_ipcc, hw_fence_utils_map_qtime]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 0011c1c8 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [hw_fence_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 0011c1d0 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [hw_fence_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0011c1d8 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [msm_hw_fence_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 0011c1e0 size=1
// signature: undefined mutex_trylock(void)
// callers: [msm_hw_fence_deregister_error_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011c1e8 size=1
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
// platform_driver_unregister @ 0011c1f0 size=1
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
// of_device_is_compatible @ 0011c1f8 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_hw_fence_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_unused_fd_flags @ 0011c208 size=1
// signature: undefined get_unused_fd_flags(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_unused_fd_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sync_file_create @ 0011c210 size=1
// signature: undefined sync_file_create(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sync_file_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fd_install @ 0011c218 size=1
// signature: undefined fd_install(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fd_install(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fput @ 0011c220 size=1
// signature: undefined fput(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_unused_fd @ 0011c228 size=1
// signature: undefined put_unused_fd(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_create_fence]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_unused_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sync_file_get_fence @ 0011c230 size=1
// signature: undefined sync_file_get_fence(void)
// callers: [hw_sync_ioctl_create_fence_array, hw_sync_ioctl_reg_for_wait, hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sync_file_get_fence(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0011c238 size=1
// signature: undefined ktime_get(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0011c240 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0011c248 size=1
// signature: undefined init_wait_entry(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0011c250 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0011c258 size=1
// signature: undefined schedule_timeout(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0011c260 size=1
// signature: undefined finish_wait(void)
// callers: [hw_sync_ioctl_fence_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



