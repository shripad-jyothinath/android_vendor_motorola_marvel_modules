// Decompiled by Ghidra 12.2
// Program: qcom_lpm.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_lpm_gov_select @ 00101184 size=140
// signature: undefined __traceiter_lpm_gov_select(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_lpm_gov_select
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00106108;
  plVar2 = DAT_00106108;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7193a523) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1011e8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gov_pred_select @ 00101214 size=124
// signature: undefined __traceiter_gov_pred_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gov_pred_select
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00106150;
  plVar2 = _DAT_00106150;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5f3561e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10126c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_gov_pred_hist @ 00101294 size=124
// signature: undefined __traceiter_gov_pred_hist(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_gov_pred_hist
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00106198;
  plVar2 = _DAT_00106198;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4822cf30) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_4,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1012ec);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_lpm_gov_select @ 00101314 size=200
// signature: undefined trace_event_raw_event_lpm_gov_select(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_lpm_gov_select
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x28), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined8 *)(lVar1 + 0x20) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_lpm_gov_select @ 001013e0 size=272
// signature: undefined perf_trace_lpm_gov_select(void)
// callers: []
//------------------------------------------------------------

void perf_trace_lpm_gov_select
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

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
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined8 *)(lVar3 + 0x18) = param_4;
    *(undefined8 *)(lVar3 + 0x20) = param_5;
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
// trace_event_raw_event_gov_pred_select @ 001014f4 size=196
// signature: undefined trace_event_raw_event_gov_pred_select(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gov_pred_select
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gov_pred_select @ 001015bc size=260
// signature: undefined perf_trace_gov_pred_select(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gov_pred_select
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x24,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x24,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_gov_pred_hist @ 001016c4 size=192
// signature: undefined trace_event_raw_event_gov_pred_hist(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gov_pred_hist
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_4;
    *(undefined4 *)(lVar1 + 0x10) = param_3;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gov_pred_hist @ 00101788 size=256
// signature: undefined perf_trace_gov_pred_hist(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gov_pred_hist(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_lpm_gov_select @ 0010188c size=32
// signature: undefined __bpf_trace_lpm_gov_select(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_lpm_gov_select(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run4(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gov_pred_select @ 001018b0 size=36
// signature: undefined __bpf_trace_gov_pred_select(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gov_pred_select
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_gov_pred_hist @ 001018d8 size=44
// signature: undefined __bpf_trace_gov_pred_hist(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gov_pred_hist
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_4,param_3);
  return;
}



//------------------------------------------------------------
// clear_cpu_predict_history @ 00101908 size=188
// signature: undefined clear_cpu_predict_history(void)
// callers: [cluster_power_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clear_cpu_predict_history(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  if (prediction_disabled == '\0') {
    iVar3 = 0;
    while (uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3), uVar2 < _nr_cpu_ids
          ) {
      if ((uVar2 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1019c4);
        (*pcVar1)();
      }
      lVar4 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
      iVar3 = uVar2 + 1;
      *(undefined8 *)(&DAT_00106880 + lVar4) = 0xffffffffffffffff;
      *(undefined4 *)(&DAT_00106890 + lVar4) = 0xffffffff;
      *(undefined8 *)(&DAT_00106888 + lVar4) = 0xffffffffffffffff;
      *(undefined8 *)(&DAT_00106894 + lVar4) = 0;
      *(undefined8 *)(&DAT_0010689c + lVar4) = 0;
      *(undefined8 *)(&DAT_001068a4 + lVar4) = 0;
      *(undefined4 *)(&DAT_001068ac + lVar4) = 0;
      *(undefined8 *)(&DAT_001068e0 + lVar4) = 0;
      *(undefined4 *)(&DAT_001068e8 + lVar4) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// update_ipi_history @ 001019c8 size=124
// signature: undefined update_ipi_history(void)
// callers: []
//------------------------------------------------------------

void update_ipi_history(uint param_1,long param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  long lVar4;
  
  if (param_1 < 0x20) {
    lVar4 = *(long *)(&__per_cpu_offset + (ulong)param_1 * 8);
    if (*(uint *)(&DAT_001068c4 + lVar4) < 5) {
      auVar2 = SEXT816(param_2 - *(long *)(&DAT_001068c8 + lVar4)) * SEXT816(0x20c49ba5e353f7cf);
      *(int *)(lVar4 + (ulong)*(uint *)(&DAT_001068c4 + lVar4) * 4 + 0x1068b0) =
           (int)(auVar2._8_8_ >> 7) - (auVar2._12_4_ >> 0x1f);
      *(long *)(&DAT_001068c8 + lVar4) = param_2;
      iVar1 = 0;
      if (*(int *)(&DAT_001068c4 + lVar4) + 1U < 5) {
        iVar1 = *(int *)(&DAT_001068c4 + lVar4) + 1;
      }
      *(int *)(&DAT_001068c4 + lVar4) = iVar1;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101a44);
  (*pcVar3)();
}



//------------------------------------------------------------
// register_cluster_governor_ops @ 00101a48 size=16
// signature: undefined register_cluster_governor_ops(void)
// callers: [lpm_cluster_gov_probe]
//------------------------------------------------------------

void register_cluster_governor_ops(long param_1)

{
  if (param_1 != 0) {
    cluster_gov_ops = param_1;
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_lpm_gov_select @ 00101a5c size=108
// signature: undefined trace_raw_output_lpm_gov_select(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_lpm_gov_select(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"state:%d qos-us:%lld sleep-us:%llu reason:%#x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gov_pred_select @ 00101acc size=108
// signature: undefined trace_raw_output_gov_pred_select(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gov_pred_select(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pred:%u time:%lu tmr_time:%u\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gov_pred_hist @ 00101b3c size=104
// signature: undefined trace_raw_output_gov_pred_hist(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gov_pred_hist(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"idx:%d residency=%d, tmr=%d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// qcom_lpm_suspend_trace @ 00101ba8 size=224
// signature: undefined qcom_lpm_suspend_trace(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_lpm_suspend_trace(undefined8 param_1,char *param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_4 & 1) == 0) {
    iVar1 = strcmp("dpm_resume_early",param_2);
    if (iVar1 == 0) {
      iVar1 = 0;
      suspend_in_progress = 0;
      while( true ) {
        uVar2 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar1);
        if (_nr_cpu_ids <= uVar2) break;
        wake_up_if_idle(uVar2);
        iVar1 = uVar2 + 1;
      }
    }
  }
  else {
    iVar1 = strcmp("dpm_suspend_late",param_2);
    if (iVar1 == 0) {
      iVar1 = 0;
      suspend_in_progress = 1;
      while( true ) {
        uVar2 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar1);
        if (_nr_cpu_ids <= uVar2) break;
        wake_up_if_idle(uVar2);
        iVar1 = uVar2 + 1;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// lpm_online_cpu @ 00101c8c size=104
// signature: undefined lpm_online_cpu(void)
// callers: []
//------------------------------------------------------------

undefined8 lpm_online_cpu(uint param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101cf4);
    (*pcVar1)();
  }
  lVar3 = *(long *)(&__per_cpu_offset + (ulong)param_1 * 8);
  lVar2 = get_cpu_device();
  if ((lVar2 != 0) && (lVar3 != -0x1067a0)) {
    *(code **)(&DAT_001067b0 + lVar3) = lpm_cpu_qos_notify;
    dev_pm_qos_add_notifier(lVar2,&DAT_001067b0 + lVar3,1);
  }
  return 0;
}



//------------------------------------------------------------
// lpm_offline_cpu @ 00101cf8 size=96
// signature: undefined lpm_offline_cpu(void)
// callers: []
//------------------------------------------------------------

undefined8 lpm_offline_cpu(uint param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101d58);
    (*pcVar1)();
  }
  lVar3 = *(long *)(&__per_cpu_offset + (ulong)param_1 * 8);
  lVar2 = get_cpu_device();
  if ((lVar2 != 0) && (lVar3 != -0x1067a0)) {
    dev_pm_qos_remove_notifier(lVar2,&DAT_001067b0 + lVar3,1);
  }
  return 0;
}



//------------------------------------------------------------
// lpm_enable_device @ 00101d5c size=512
// signature: undefined lpm_enable_device(void)
// callers: []
//------------------------------------------------------------

int lpm_enable_device(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  code *pcVar4;
  long lVar5;
  
  if (0x1f < *(uint *)(param_2 + 4)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101f5c);
    (*pcVar4)();
  }
  lVar5 = *(long *)(&__per_cpu_offset + (ulong)*(uint *)(param_2 + 4) * 8);
  *(undefined4 *)(&DAT_001068f0 + lVar5) = 0;
  hrtimer_init(lVar5 + 0x1067f0,1,1);
  hrtimer_init(lVar5 + 0x106838,1,1);
  if ((traces_registered & 1) == 0) {
    iVar2 = tracepoint_probe_register(&__tracepoint_ipi_raise,ipi_raise,0);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = tracepoint_probe_register(&__tracepoint_ipi_entry,ipi_entry,0);
    if (iVar2 == 0) {
      iVar2 = tracepoint_probe_register_prio
                        (&__tracepoint_android_vh_cpu_idle_enter,lpm_idle_enter,0,0x80000000);
      if (iVar2 == 0) {
        iVar2 = tracepoint_probe_register_prio
                          (&__tracepoint_android_vh_cpu_idle_exit,lpm_idle_exit,0,0x80000000);
        if (iVar2 == 0) {
          if ((cluster_gov_ops != 0) &&
             (pcVar4 = *(code **)(cluster_gov_ops + 8), pcVar4 != (code *)0x0)) {
            if (*(int *)(pcVar4 + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101f48);
              (*pcVar4)();
            }
            (*pcVar4)();
          }
          traces_registered = 1;
          goto LAB_00101dd4;
        }
        tracepoint_probe_unregister(&__tracepoint_ipi_raise,ipi_raise,0);
        tracepoint_probe_unregister(&__tracepoint_ipi_entry,ipi_entry,0);
        puVar3 = &__tracepoint_android_vh_cpu_idle_enter;
        pcVar4 = lpm_idle_enter;
      }
      else {
        tracepoint_probe_unregister(&__tracepoint_ipi_raise,ipi_raise,0);
        puVar3 = &__tracepoint_ipi_entry;
        pcVar4 = ipi_entry;
      }
    }
    else {
      puVar3 = &__tracepoint_ipi_raise;
      pcVar4 = ipi_raise;
    }
    tracepoint_probe_unregister(puVar3,pcVar4,0);
  }
  else {
LAB_00101dd4:
    iVar2 = 0;
    uVar1 = *(undefined4 *)(param_2 + 4);
    *(undefined8 *)(&DAT_001067c8 + lVar5) = param_1;
    *(long *)(&DAT_001067d0 + lVar5) = param_2;
    *(undefined4 *)(&lpm_cpu_data + lVar5) = uVar1;
    *(undefined8 *)(&DAT_001067a4 + lVar5) = 0xffffffff00000001;
  }
  return iVar2;
}



//------------------------------------------------------------
// lpm_disable_device @ 00101f60 size=328
// signature: undefined lpm_disable_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lpm_disable_device(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = _nr_cpu_ids;
  if (*(uint *)(param_2 + 4) < 0x20) {
    iVar4 = 0;
    *(undefined8 *)
     (&DAT_001067a4 + *(long *)(&__per_cpu_offset + (ulong)*(uint *)(param_2 + 4) * 8)) =
         0xffffffff00000000;
    while( true ) {
      uVar2 = _find_next_bit(&__cpu_possible_mask,uVar3,(long)iVar4);
      if (_nr_cpu_ids <= uVar2) {
        if (traces_registered != '\x01') {
          return;
        }
        tracepoint_probe_unregister(&__tracepoint_ipi_raise,ipi_raise,0);
        tracepoint_probe_unregister(&__tracepoint_ipi_entry,ipi_entry,0);
        tracepoint_probe_unregister(&__tracepoint_android_vh_cpu_idle_enter,lpm_idle_enter,0);
        tracepoint_probe_unregister(&__tracepoint_android_vh_cpu_idle_exit,lpm_idle_exit,0);
        if ((cluster_gov_ops != 0) &&
           (pcVar1 = *(code **)(cluster_gov_ops + 0x10), pcVar1 != (code *)0x0)) {
          if (*(int *)(pcVar1 + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102088);
            (*pcVar1)();
          }
          (*pcVar1)();
        }
        traces_registered = 0;
        return;
      }
      if ((uVar2 & 0xffffffe0) != 0) break;
      iVar4 = uVar2 + 1;
      uVar3 = _nr_cpu_ids;
      if (*(int *)(&DAT_001067a4 + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8)) != 0) {
        return;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1020a8);
  (*pcVar1)();
}



//------------------------------------------------------------
// lpm_select @ 001020ac size=1904
// signature: undefined lpm_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong lpm_select(long param_1,long param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  code *pcVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  lVar4 = tpidr_el1;
  uVar17 = *(uint *)(param_2 + 4);
  lVar13 = 0;
  puVar1 = &lpm_cpu_data + lVar4;
  uVar10 = 2000000000000;
  while (uVar6 = _find_next_bit(&__cpu_active_mask +
                                (((ulong)uVar17 & 0x3f) * 8 - ((ulong)(uVar17 >> 3) & 0x1ffffff8)),
                                _nr_cpu_ids,(long)(int)lVar13), (uint)uVar6 < _nr_cpu_ids) {
    uVar7 = uVar10;
    if ((*(ulong *)(&__cpu_active_mask + (uVar6 >> 6 & 0x3ffffff) * 8) >> (uVar6 & 0x3f) & 1) != 0)
    {
      uVar7 = cpuidle_governor_latency_req(uVar6 & 0xffffffff);
      if ((long)uVar10 <= (long)uVar7) {
        uVar7 = uVar10;
      }
    }
    lVar13 = uVar6 + 1;
    uVar10 = uVar7;
  }
  local_78 = 0;
  if (puVar1 == (undefined1 *)0x0) {
    uVar6 = 0;
    goto LAB_00102310;
  }
  *(undefined8 *)(&DAT_001067e0 + lVar4) = 0;
  (&DAT_001067ec)[lVar4] = 0;
  uVar8 = ktime_get();
  *(undefined8 *)(&DAT_001068d0 + lVar4) = uVar8;
  uVar7 = tick_nohz_get_sleep_length(&local_78);
  if ((((sleep_disabled == '\0') && (prediction_disabled == '\0')) &&
      (uVar17 = *(uint *)(&DAT_001067a8 + lVar4), -1 < (int)uVar17)) &&
     ((int)uVar17 <= *(int *)(*(long *)(&DAT_001067c8 + lVar4) + 0x428) + -1)) {
    if (10 < uVar17) goto LAB_001028b4;
    uVar15 = *(uint *)(*(long *)(&DAT_001067c8 + lVar4) + (ulong)uVar17 * 0x68 + 0x5c);
    uVar6 = *(long *)(*(long *)(&DAT_001067d0 + lVar4) + 0x18) / 1000;
    if (uVar6 <= uVar15) {
      uVar15 = 0;
    }
    iVar5 = (int)uVar6 - uVar15;
    uVar15 = *(uint *)(&DAT_001068ac + lVar4);
    if ((&DAT_001067ed)[lVar4] == '\0') {
      if (4 < uVar15) goto LAB_001028b4;
      *(int *)(puVar1 + (ulong)uVar15 * 4 + 0xf4) = iVar5;
    }
    else {
      uVar2 = 4;
      if (uVar15 != 0) {
        uVar2 = uVar15 - 1;
      }
      *(uint *)(&DAT_001068ac + lVar4) = uVar2;
      if (4 < uVar2) goto LAB_001028b4;
      *(int *)(puVar1 + (ulong)uVar2 * 4 + 0xf4) =
           *(int *)(puVar1 + (ulong)uVar2 * 4 + 0xf4) + iVar5;
      (&DAT_001067ed)[lVar4] = 0;
    }
    if (4 < *(uint *)(&DAT_001068ac + lVar4)) goto LAB_001028b4;
    *(uint *)(&DAT_00106880 + (ulong)*(uint *)(&DAT_001068ac + lVar4) * 4 + lVar4) = uVar17;
    *(undefined4 *)(&DAT_001068e8 + lVar4) = 0;
    if (4 < *(uint *)(&DAT_001068ac + lVar4)) goto LAB_001028b4;
    if (*(int *)(&DAT_001068a8 + lVar4) < 5) {
      *(int *)(&DAT_001068a8 + lVar4) = *(int *)(&DAT_001068a8 + lVar4) + 1;
    }
    iVar5 = 0;
    if (*(int *)(&DAT_001068ac + lVar4) + 1U < 5) {
      iVar5 = *(int *)(&DAT_001068ac + lVar4) + 1;
    }
    *(int *)(&DAT_001068ac + lVar4) = iVar5;
  }
  uVar17 = *(uint *)(param_2 + 4);
  uVar6 = (ulong)uVar17;
  if (0x1f < uVar17) {
LAB_001028b4:
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x5512,0x1028b8);
    (*pcVar12)();
  }
  local_70 = 0;
  lVar13 = *(long *)(&__per_cpu_offset + uVar6 * 8);
  if ((suspend_in_progress & 1) == 0) {
    if ((*(ulong *)(&__cpu_active_mask + ((ulong)(uVar17 >> 3) & 0x1ffffff8)) >> (uVar6 & 0x3f) & 1)
        != 0) {
      if ((-1 < (long)uVar7) && (sleep_disabled == '\0')) {
        iVar5 = sched_lpm_disallowed_time(uVar6,&local_70);
        if (iVar5 != 0) goto LAB_00102378;
        *(undefined4 *)(&DAT_001067a8 + lVar13) = 0;
        *(undefined8 *)(&DAT_001068d8 + lVar13) = local_70;
      }
      goto LAB_001021fc;
    }
LAB_00102378:
    iVar5 = *(int *)(param_1 + 0x428);
    uVar6 = (ulong)(iVar5 - 1U);
    if (0 < (int)(iVar5 - 1U)) {
      do {
        if (9 < uVar6) goto LAB_001028b4;
        if (((*(long *)(param_2 + uVar6 * 0x40 + 0x30) == 0) &&
            ((ulong)*(uint *)(param_1 + uVar6 * 0x68 + 0x5c) <= uVar10 / 1000)) &&
           (*(ulong *)(param_1 + uVar6 * 0x68 + 0x50) <= uVar7)) {
          if (((*(ulong *)(&__cpu_active_mask + ((ulong)(*(uint *)(param_2 + 4) >> 3) & 0x1ffffff8))
                >> ((ulong)*(uint *)(param_2 + 4) & 0x3f) & 1) != 0) &&
             ((&DAT_001067ec)[lVar4] == '\0')) {
            if (prediction_disabled == '\0') {
              if (*(int *)(&DAT_001067e8 + lVar4) == 0) {
                lVar13 = *(long *)(&DAT_001067c8 + lVar4);
                if (*(ulong *)(lVar13 + 0x50) <= uVar7) {
                  if (*(int *)(&DAT_001068a8 + lVar4) < 5) {
                    *(undefined8 *)(&DAT_001068e0 + lVar4) = 0;
                  }
                  else {
                    lVar9 = find_deviation(puVar1,&DAT_00106894 + lVar4,uVar7);
                    *(long *)(&DAT_001067e0 + lVar4) = lVar9;
                    if (lVar9 == 0) {
                      if (1 < (int)*(uint *)(lVar13 + 0x428)) {
                        lVar9 = 0;
                        do {
                          if (lVar9 == 0x410) goto LAB_001028b4;
                          uVar17 = *(uint *)(lVar13 + 0xcc + lVar9);
                          if ((ulong)*(uint *)(&DAT_00106880 + lVar4) * 0x68 + -0x68 == lVar9) {
                            uVar2 = *(uint *)(&DAT_00106894 + lVar4);
                            uVar15 = (uint)(uVar2 < uVar17);
                            if (uVar2 >= uVar17) {
                              uVar2 = 0;
                            }
                            uVar14 = (ulong)uVar2;
                          }
                          else {
                            uVar15 = 0;
                            uVar14 = 0;
                          }
                          if (((ulong)*(uint *)(&DAT_00106884 + lVar4) * 0x68 + -0x68 == lVar9) &&
                             (*(uint *)(&DAT_00106898 + lVar4) < uVar17)) {
                            uVar15 = uVar15 + 1;
                            uVar14 = uVar14 + *(uint *)(&DAT_00106898 + lVar4);
                          }
                          if (((ulong)*(uint *)(&DAT_00106888 + lVar4) * 0x68 + -0x68 == lVar9) &&
                             (*(uint *)(&DAT_0010689c + lVar4) < uVar17)) {
                            uVar15 = uVar15 + 1;
                            uVar14 = uVar14 + *(uint *)(&DAT_0010689c + lVar4);
                          }
                          if (((ulong)*(uint *)(&DAT_0010688c + lVar4) * 0x68 + -0x68 == lVar9) &&
                             (*(uint *)(&DAT_001068a0 + lVar4) < uVar17)) {
                            uVar15 = uVar15 + 1;
                            uVar14 = uVar14 + *(uint *)(&DAT_001068a0 + lVar4);
                          }
                          if (((ulong)*(uint *)(&DAT_00106890 + lVar4) * 0x68 + -0x68 == lVar9) &&
                             (*(uint *)(&DAT_001068a4 + lVar4) < uVar17)) {
                            uVar15 = uVar15 + 1;
                            uVar14 = uVar14 + *(uint *)(&DAT_001068a4 + lVar4);
                          }
                          if (2 < uVar15) {
                            uVar11 = (ulong)uVar15;
                            *(undefined4 *)(&DAT_001068e8 + lVar4) = 2;
                            uVar3 = 0;
                            if (uVar11 != 0) {
                              uVar3 = uVar14 / uVar11;
                            }
                            *(ulong *)(&DAT_001067e0 + lVar4) = uVar3;
                            *(ulong *)(&DAT_001068e0 + lVar4) =
                                 *(long *)(&DAT_001068d0 + lVar4) / 1000 + uVar3;
                            if (uVar11 <= uVar14) goto LAB_00102640;
                            break;
                          }
                          lVar9 = lVar9 + 0x68;
                        } while ((ulong)*(uint *)(lVar13 + 0x428) * 0x68 + -0x68 != lVar9);
                      }
                      uVar8 = _raw_spin_lock_irqsave();
                      lVar13 = find_deviation(puVar1,lVar4 + 0x1068b0,uVar7);
                      *(long *)(&DAT_001067e0 + lVar4) = lVar13;
                      if (lVar13 != 0) {
                        *(undefined4 *)(&DAT_001068e8 + lVar4) = 3;
                      }
                      _raw_spin_unlock_irqrestore(&DAT_001068f0 + lVar4,uVar8);
                    }
                    else {
                      *(undefined4 *)(&DAT_001068e8 + lVar4) = 1;
                    }
                  }
                }
              }
              else {
                *(undefined4 *)(&DAT_001067e8 + lVar4) = 0;
                (&DAT_001067ed)[lVar4] = 1;
                *(undefined8 *)(&DAT_001068e0 + lVar4) = 0;
              }
            }
LAB_00102640:
            (&DAT_001067ec)[lVar4] = 1;
          }
          if ((*(ulong *)(&DAT_001067e0 + lVar4) == 0) ||
             ((ulong)*(uint *)(param_1 + uVar6 * 0x68 + 100) <= *(ulong *)(&DAT_001067e0 + lVar4)))
          goto LAB_00102714;
        }
        iVar5 = (int)uVar6;
        uVar6 = uVar6 - 1;
      } while (0 < (int)uVar6);
      uVar6 = 0;
      iVar5 = 1;
    }
LAB_00102714:
    uVar17 = (uint)uVar6;
    *(uint *)(&DAT_001067a8 + lVar4) = uVar17;
    lVar13 = *(long *)(&DAT_001068d0 + lVar4) + (uVar7 / 1000) * 1000;
    *(long *)(&DAT_001067d8 + lVar4) = lVar13;
    if ((*(long *)(&DAT_001067e0 + lVar4) != 0) &&
       (uVar17 < *(int *)(*(long *)(&DAT_001067c8 + lVar4) + 0x428) - 1U)) {
      if (*(long *)(&DAT_001068e0 + lVar4) < lVar13) {
        *(long *)(&DAT_001067d8 + lVar4) = *(long *)(&DAT_001068e0 + lVar4);
      }
      uVar15 = (int)*(long *)(&DAT_001067e0 + lVar4) + 100;
      uVar2 = *(int *)(*(long *)(&DAT_001067c8 + lVar4) + (long)iVar5 * 0x68 + 100) - 1;
      if (uVar2 <= uVar15) {
        uVar15 = uVar2;
      }
      uVar16 = (uint)(uVar7 / 1000);
      if ((uVar15 < uVar16) && (uVar2 < uVar16 - uVar15)) {
        lVar13 = tpidr_el1;
        *(code **)(&DAT_00106818 + lVar13) = histtimer_fn;
        hrtimer_start_range_ns(lVar13 + 0x1067f0,(ulong)uVar15 * 1000,0,3);
        uVar17 = *(uint *)(&DAT_001067a8 + lVar4);
      }
    }
    if (((uVar17 == *(int *)(param_1 + 0x428) - 1U) && (cluster_gov_ops != (undefined8 *)0x0)) &&
       (pcVar12 = (code *)*cluster_gov_ops, pcVar12 != (code *)0x0)) {
      if (*(int *)(pcVar12 + -4) != -0x2b218292) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x102820);
        (*pcVar12)();
      }
      (*pcVar12)(puVar1);
    }
  }
  else {
LAB_001021fc:
    uVar6 = 0;
  }
  if ((*(int *)(&DAT_001067a8 + lVar4) == 0) &&
     (uVar10 = *(ulong *)(&DAT_001068d8 + lVar4), uVar10 != 0)) {
    lVar13 = tpidr_el1;
    *(code **)(&DAT_00106860 + lVar13) = biastimer_fn;
    hrtimer_start_range_ns(lVar13 + 0x106838,uVar10 & 0xffffffff,0,3);
  }
LAB_00102310:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// lpm_reflect @ 00102a20 size=4
// signature: undefined lpm_reflect(void)
// callers: []
//------------------------------------------------------------

void lpm_reflect(void)

{
  return;
}



//------------------------------------------------------------
// ipi_raise @ 00102a28 size=356
// signature: undefined ipi_raise(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ipi_raise(undefined8 param_1,undefined8 param_2)

{
  undefined1 auVar1 [16];
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  
  if ((suspend_in_progress & 1) != 0) {
    return;
  }
  lVar7 = ktime_get();
  iVar6 = 0;
LAB_00102ab4:
  uVar5 = _find_next_bit(param_2,_nr_cpu_ids,(long)iVar6);
  if (_nr_cpu_ids <= uVar5) {
    return;
  }
  if ((uVar5 & 0xffffffe0) == 0) {
    lVar9 = *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8);
    if (*(int *)(&DAT_001067a4 + lVar9) == 0) {
      return;
    }
    uVar2 = daif;
    uVar8 = (uint)uVar2 & 0x80;
    if ((uVar2 & 0x80) == 0) {
      uVar8 = 0x60;
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    iVar6 = _raw_spin_trylock(uVar8,&DAT_001068f0 + lVar9);
    if (iVar6 == 0) {
      daif = uVar2;
      iVar6 = uVar5 + 1;
      goto LAB_00102ab4;
    }
    (&DAT_001068ec)[lVar9] = 1;
    if (0x1f < uVar5) goto LAB_00102b90;
    lVar10 = *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8);
    if (*(uint *)(&DAT_001068c4 + lVar10) < 5) {
      auVar1 = SEXT816(lVar7 - *(long *)(&DAT_001068c8 + lVar10)) * SEXT816(0x20c49ba5e353f7cf);
      *(int *)(lVar10 + (ulong)*(uint *)(&DAT_001068c4 + lVar10) * 4 + 0x1068b0) =
           (int)(auVar1._8_8_ >> 7) - (auVar1._12_4_ >> 0x1f);
      *(long *)(&DAT_001068c8 + lVar10) = lVar7;
      iVar6 = 0;
      if (*(int *)(&DAT_001068c4 + lVar10) + 1U < 5) {
        iVar6 = *(int *)(&DAT_001068c4 + lVar10) + 1;
      }
      *(int *)(&DAT_001068c4 + lVar10) = iVar6;
      _raw_spin_unlock_irqrestore(&DAT_001068f0 + lVar9,uVar2);
      iVar6 = uVar5 + 1;
      goto LAB_00102ab4;
    }
  }
LAB_00102b90:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102b94);
  (*pcVar4)();
}



//------------------------------------------------------------
// ipi_entry @ 00102b98 size=132
// signature: undefined ipi_entry(void)
// callers: []
//------------------------------------------------------------

void ipi_entry(void)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((suspend_in_progress & 1) == 0) {
    lVar3 = tpidr_el1;
    if (0x1f < *(uint *)(&cpu_number + lVar3)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102c1c);
      (*pcVar1)();
    }
    lVar3 = *(long *)(&__per_cpu_offset + (ulong)*(uint *)(&cpu_number + lVar3) * 8);
    if (*(int *)(&DAT_001067a4 + lVar3) != 0) {
      uVar2 = _raw_spin_lock_irqsave(&DAT_001068f0 + lVar3);
      (&DAT_001068ec)[lVar3] = 0;
      _raw_spin_unlock_irqrestore(&DAT_001068f0 + lVar3,uVar2);
    }
  }
  return;
}



//------------------------------------------------------------
// lpm_idle_enter @ 00102c20 size=140
// signature: undefined lpm_idle_enter(void)
// callers: []
//------------------------------------------------------------

void lpm_idle_enter(undefined8 param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  lVar2 = tpidr_el1;
  if ((*param_2 != 0) && (*(int *)(&DAT_001067a4 + lVar2) != 0)) {
    uVar3 = _raw_spin_lock_irqsave(&DAT_001068f0 + lVar2);
    uVar4 = (ulong)(byte)(&DAT_001068ec)[lVar2];
    if ((&DAT_001068ec)[lVar2] != 0) {
      iVar1 = *param_2;
      *param_2 = 0;
      uVar4 = 0x10L << ((ulong)(uint)(iVar1 << 3) & 0x3f);
    }
    _raw_spin_unlock_irqrestore(uVar4,&DAT_001068f0 + lVar2,uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpm_idle_exit @ 00102d6c size=184
// signature: undefined lpm_idle_exit(void)
// callers: []
//------------------------------------------------------------

void lpm_idle_exit(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  
  if (0x1f < *(uint *)(param_3 + 4)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102e24);
    (*pcVar2)();
  }
  if (*(int *)(&DAT_001067a4 + *(long *)(&__per_cpu_offset + (ulong)*(uint *)(param_3 + 4) * 8)) !=
      0) {
    lVar1 = tpidr_el1;
    lVar1 = lVar1 + 0x1067f0;
    uVar3 = hrtimer_active(lVar1);
    if (((uVar3 & 1) != 0) && (lVar4 = __hrtimer_get_remaining(lVar1,0), 999 < lVar4)) {
      hrtimer_try_to_cancel(lVar1);
    }
    lVar1 = tpidr_el1;
    if (*(long *)(&DAT_001068d8 + lVar1) != 0) {
      *(undefined8 *)(&DAT_001068d8 + lVar1) = 0;
      lVar4 = __hrtimer_get_remaining(lVar1 + 0x106838,0);
      if (999 < lVar4) {
        hrtimer_try_to_cancel(lVar1 + 0x106838);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// find_deviation @ 00102e24 size=532
// signature: undefined find_deviation(void)
// callers: [lpm_select]
//------------------------------------------------------------

ulong find_deviation(long param_1,int *param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  code *pcVar16;
  ulong uVar17;
  long lVar18;
  uint uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  
  lVar18 = *(long *)(param_1 + 0x28);
  uVar12 = *(int *)(lVar18 + 0x428) - 1;
  if (10 < uVar12) {
                    /* WARNING: Does not return */
    pcVar16 = (code *)SoftwareBreakpoint(0x5512,0x103038);
    (*pcVar16)();
  }
  uVar22 = 0x7fffffffffffffff;
  while( true ) {
    uVar8 = (ulong)*param_2;
    uVar10 = (ulong)param_2[1];
    uVar9 = (ulong)param_2[2];
    uVar11 = (ulong)param_2[3];
    uVar21 = (ulong)param_2[4];
    uVar17 = uVar10;
    if (uVar10 > uVar22) {
      uVar17 = 0;
    }
    uVar1 = uVar8;
    if (uVar22 < uVar8) {
      uVar1 = 0;
    }
    uVar19 = (uint)(uVar10 <= uVar22);
    if (uVar22 >= uVar8) {
      uVar19 = uVar19 + 1;
    }
    if (uVar22 < uVar9) {
      uVar2 = 0;
    }
    else {
      uVar19 = uVar19 + 1;
      uVar2 = uVar9;
    }
    if (uVar22 < uVar11) {
      uVar14 = 0;
    }
    else {
      uVar19 = uVar19 + 1;
      uVar14 = uVar11;
    }
    if (uVar22 < uVar21) {
      uVar15 = 0;
    }
    else {
      uVar19 = uVar19 + 1;
      uVar15 = uVar21;
    }
    uVar20 = (ulong)uVar19;
    uVar13 = 0;
    if (uVar20 != 0) {
      uVar13 = (uVar15 + uVar14 + uVar2 + uVar17 + uVar1) / uVar20;
    }
    lVar3 = 0;
    if (uVar8 <= uVar22) {
      lVar3 = (uVar8 - uVar13) * (uVar8 - uVar13);
    }
    lVar4 = 0;
    if (uVar10 <= uVar22) {
      lVar4 = (uVar10 - uVar13) * (uVar10 - uVar13);
    }
    lVar5 = 0;
    if (uVar9 <= uVar22) {
      lVar5 = (uVar9 - uVar13) * (uVar9 - uVar13);
    }
    lVar6 = 0;
    if (uVar11 <= uVar22) {
      lVar6 = (uVar11 - uVar13) * (uVar11 - uVar13);
    }
    lVar7 = 0;
    if (uVar21 <= uVar22) {
      lVar7 = (uVar21 - uVar13) * (uVar21 - uVar13);
    }
    uVar17 = 0;
    if (uVar20 != 0) {
      uVar17 = (ulong)(lVar7 + lVar6 + lVar5 + lVar4 + lVar3) / uVar20;
    }
    uVar17 = int_sqrt(uVar17);
    if (((uVar19 >= 4 && uVar17 * 6 <= uVar13) && (uVar19 < 4 || uVar13 != uVar17 * 6)) ||
       (uVar17 < 0x1f5)) break;
    uVar17 = uVar1;
    if (uVar1 <= uVar10) {
      uVar17 = uVar10;
    }
    if (uVar22 < uVar10) {
      uVar17 = uVar1;
    }
    uVar8 = uVar17;
    if (uVar17 <= uVar9) {
      uVar8 = uVar9;
    }
    if (uVar22 < uVar9) {
      uVar8 = uVar17;
    }
    uVar17 = uVar8;
    if (uVar8 <= uVar11) {
      uVar17 = uVar11;
    }
    if (uVar22 < uVar11) {
      uVar17 = uVar8;
    }
    uVar8 = uVar17;
    if (uVar17 <= uVar21) {
      uVar8 = uVar21;
    }
    if (uVar22 < uVar21) {
      uVar8 = uVar17;
    }
    uVar22 = uVar8 - 1;
    if (uVar19 < 5) {
      return 0;
    }
  }
  if (param_3 / 1000 <= uVar13) {
    return 0;
  }
  if (*(uint *)(lVar18 + (ulong)uVar12 * 0x68 + 100) < uVar13) {
    return 0;
  }
  *(ulong *)(param_1 + 0x140) = *(long *)(param_1 + 0x130) / 1000 + uVar13;
  return uVar13;
}



//------------------------------------------------------------
// histtimer_fn @ 0010303c size=32
// signature: undefined histtimer_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 histtimer_fn(void)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  *(undefined4 *)(&DAT_001067e8 + lVar1) = 1;
  return 0;
}



//------------------------------------------------------------
// biastimer_fn @ 00103060 size=8
// signature: undefined biastimer_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 biastimer_fn(void)

{
  return 0;
}



//------------------------------------------------------------
// lpm_cpu_qos_notify @ 0010306c size=176
// signature: undefined lpm_cpu_qos_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 lpm_cpu_qos_notify(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  if (*(int *)(param_1 + -0xc) != 0) {
    uVar1 = *(uint *)(param_1 + -0x10);
    lVar3 = sp_el0;
    *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
    lVar2 = tpidr_el1;
    if (uVar1 != *(uint *)(&cpu_number + lVar2)) {
      uVar4 = 1L << ((ulong)uVar1 & 0x3f);
      if (((*(ulong *)(&__cpu_online_mask + (ulong)(uVar1 >> 6) * 8) & uVar4) != 0) &&
         ((*(ulong *)(&__cpu_active_mask + (ulong)(uVar1 >> 6) * 8) & uVar4) != 0)) {
        wake_up_if_idle();
      }
    }
    lVar2 = *(long *)(lVar3 + 0x10) + -1;
    *(int *)(lVar3 + 0x10) = (int)lVar2;
    if ((lVar2 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
      preempt_schedule();
    }
  }
  return 1;
}



//------------------------------------------------------------
// suspend_lpm_notify @ 00103120 size=144
// signature: undefined suspend_lpm_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 suspend_lpm_notify(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 3) {
    suspend_in_progress = 1;
  }
  else if (param_2 == 4) {
    suspend_in_progress = 0;
  }
  iVar2 = 0;
  while (uVar1 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar2), uVar1 < _nr_cpu_ids) {
    wake_up_if_idle(uVar1);
    iVar2 = uVar1 + 1;
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_cluster_pred_select @ 00103204 size=148
// signature: undefined __traceiter_cluster_pred_select(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_cluster_pred_select
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001061e0;
  plVar2 = DAT_001061e0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x22a00524) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103270);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_cluster_pred_hist @ 0010329c size=140
// signature: undefined __traceiter_cluster_pred_hist(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_cluster_pred_hist
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00106228;
  plVar2 = _DAT_00106228;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x2900707a) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103300);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_cluster_exit @ 0010332c size=124
// signature: undefined __traceiter_cluster_exit(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_cluster_exit
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00106270;
  plVar2 = _DAT_00106270;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cf04426) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103384);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_cluster_enter @ 001033ac size=124
// signature: undefined __traceiter_cluster_enter(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_cluster_enter
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001062b8;
  plVar2 = _DAT_001062b8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4cf04426) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103404);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_cluster_pred_select @ 0010342c size=212
// signature: undefined trace_event_raw_event_cluster_pred_select(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_cluster_pred_select
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
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
// perf_trace_cluster_pred_select @ 00103504 size=276
// signature: undefined perf_trace_cluster_pred_select(void)
// callers: []
//------------------------------------------------------------

void perf_trace_cluster_pred_select
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_cluster_pred_hist @ 0010361c size=196
// signature: undefined trace_event_raw_event_cluster_pred_hist(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_cluster_pred_hist
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_cluster_pred_hist @ 001036e4 size=268
// signature: undefined perf_trace_cluster_pred_hist(void)
// callers: []
//------------------------------------------------------------

void perf_trace_cluster_pred_hist
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_cluster_exit @ 001037f4 size=192
// signature: undefined trace_event_raw_event_cluster_exit(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_cluster_exit
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_cluster_exit @ 001038b8 size=256
// signature: undefined perf_trace_cluster_exit(void)
// callers: []
//------------------------------------------------------------

void perf_trace_cluster_exit(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_cluster_enter @ 001039bc size=192
// signature: undefined trace_event_raw_event_cluster_enter(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_cluster_enter
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_cluster_enter @ 00103a80 size=256
// signature: undefined perf_trace_cluster_enter(void)
// callers: []
//------------------------------------------------------------

void perf_trace_cluster_enter(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_cluster_pred_select @ 00103b84 size=48
// signature: undefined __bpf_trace_cluster_pred_select(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_cluster_pred_select
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_cluster_pred_hist @ 00103bb8 size=44
// signature: undefined __bpf_trace_cluster_pred_hist(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_cluster_pred_hist
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_cluster_exit @ 00103be8 size=40
// signature: undefined __bpf_trace_cluster_exit(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_cluster_exit
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_cluster_enter @ 00103c14 size=40
// signature: undefined __bpf_trace_cluster_enter(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_cluster_enter
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// get_cluster_sleep_time @ 00103c40 size=152
// signature: undefined get_cluster_sleep_time(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long get_cluster_sleep_time(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x90);
  iVar3 = 0;
  lVar6 = 0x7fffffffffffffff;
  while( true ) {
    uVar2 = _find_next_and_bit(lVar5 + 0x530,&__cpu_online_mask,_nr_cpu_ids,(long)iVar3);
    if (_nr_cpu_ids <= uVar2) {
      return lVar6;
    }
    if ((uVar2 & 0xfffffff8) != 0) break;
    lVar4 = *(long *)(param_1 + (ulong)uVar2 * 8 + 0x170);
    if (lVar6 <= lVar4) {
      lVar4 = lVar6;
    }
    iVar3 = uVar2 + 1;
    lVar6 = lVar4;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103cd8);
  (*pcVar1)();
}



//------------------------------------------------------------
// update_cluster_select @ 00103cdc size=348
// signature: undefined update_cluster_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void update_cluster_select(uint *param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined *puVar8;
  
  if ((undefined **)cluster_dev_list != &cluster_dev_list) {
    uVar1 = *param_1;
    ppuVar7 = (undefined **)cluster_dev_list;
    do {
      if ((*(char *)((long)ppuVar7 + 0x15) != '\0') &&
         ((*(ulong *)(ppuVar7[-0x25] + (ulong)(uVar1 >> 6) * 8 + 0x530) &
          1L << ((ulong)uVar1 & 0x3f)) != 0)) {
        _raw_spin_lock(ppuVar7 + 2);
        ppuVar7[-10] = *(undefined **)(param_1 + 0x4c);
        if (7 < uVar1) {
LAB_00103e34:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103e38);
          (*pcVar2)();
        }
        puVar6 = ppuVar7[-0x25];
        iVar4 = 0;
        ppuVar7[(ulong)uVar1 - 9] = *(undefined **)(param_1 + 0xe);
        puVar8 = (undefined *)0x7fffffffffffffff;
        while (uVar3 = _find_next_and_bit(puVar6 + 0x530,&__cpu_online_mask,_nr_cpu_ids,(long)iVar4)
              , uVar3 < _nr_cpu_ids) {
          if ((uVar3 & 0xfffffff8) != 0) goto LAB_00103e34;
          puVar5 = (ppuVar7 + -0x37)[(ulong)uVar3 + 0x2e];
          if ((long)puVar8 <= (long)puVar5) {
            puVar5 = puVar8;
          }
          iVar4 = uVar3 + 1;
          puVar8 = puVar5;
        }
        puVar6 = ppuVar7[-0xb];
        if ((long)puVar8 <= (long)puVar6 || puVar6 == (undefined *)0x0) {
          puVar6 = puVar8;
        }
        ppuVar7[-0xc] = puVar6;
        dev_pm_genpd_set_next_wakeup(ppuVar7[-0x37]);
        _raw_spin_unlock(ppuVar7 + 2);
      }
      ppuVar7 = (undefined **)*ppuVar7;
    } while (ppuVar7 != &cluster_dev_list);
  }
  return;
}



//------------------------------------------------------------
// cluster_gov_enable @ 00103e3c size=4
// signature: undefined cluster_gov_enable(void)
// callers: []
//------------------------------------------------------------

void cluster_gov_enable(void)

{
  return;
}



//------------------------------------------------------------
// cluster_gov_disable @ 00103e44 size=4
// signature: undefined cluster_gov_disable(void)
// callers: []
//------------------------------------------------------------

void cluster_gov_disable(void)

{
  return;
}



//------------------------------------------------------------
// qcom_cluster_lpm_governor_deinit @ 00103e4c size=36
// signature: undefined qcom_cluster_lpm_governor_deinit(void)
// callers: [init_module]
//------------------------------------------------------------

void qcom_cluster_lpm_governor_deinit(void)

{
  platform_driver_unregister(&qcom_cluster_lpm_driver);
  return;
}



//------------------------------------------------------------
// qcom_cluster_lpm_governor_init @ 00103e74 size=44
// signature: undefined qcom_cluster_lpm_governor_init(void)
// callers: [init_module]
//------------------------------------------------------------

void qcom_cluster_lpm_governor_init(void)

{
  __platform_driver_register(&qcom_cluster_lpm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// trace_raw_output_cluster_pred_select @ 00103ea4 size=108
// signature: undefined trace_raw_output_cluster_pred_select(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_cluster_pred_select(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"idx:%d sleep_time:%u latency:%u pred:%d pred_us:%u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_cluster_pred_hist @ 00103f14 size=104
// signature: undefined trace_raw_output_cluster_pred_hist(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_cluster_pred_hist(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"idx:%d resi:%u sample:%u tmr:%u\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_cluster_exit @ 00103f80 size=104
// signature: undefined trace_raw_output_cluster_exit(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_cluster_exit(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"first cpu:%d idx:%u suspend_param:0x%x\n",*(undefined4 *)(lVar2 + 8)
                       ,*(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_cluster_enter @ 00103fec size=104
// signature: undefined trace_raw_output_cluster_enter(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_cluster_enter(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"last cpu:%d idx:%u suspend_param:0x%x\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// lpm_cluster_gov_probe @ 00104058 size=384
// signature: undefined lpm_cluster_gov_probe(void)
// callers: []
//------------------------------------------------------------

int lpm_cluster_gov_probe(long param_1)

{
  long *plVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  
  param_1 = param_1 + 0x10;
  plVar5 = (long *)devm_kmalloc(param_1,0x1d0,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar4 = -0xc;
  }
  else {
    *(undefined4 *)(plVar5 + 0x39) = 0;
    *plVar5 = param_1;
    plVar5[0x2c] = 0x7fffffffffffffff;
    pm_runtime_enable(param_1);
    hrtimer_init(plVar5 + 0x21,1,1);
    lVar7 = *(long *)(*plVar5 + 0x268);
    plVar5[0x18] = (long)cluster_power_cb;
    plVar5[0x12] = lVar7 + -0x390;
    *(uint *)(lVar7 + 0x1f8) = *(uint *)(lVar7 + 0x1f8) | 0x40;
    iVar4 = dev_pm_genpd_add_notifier(*plVar5);
    if (iVar4 == 0) {
      iVar4 = create_cluster_sysfs_nodes(plVar5);
      puVar2 = PTR_cluster_dev_list_00105f28;
      if (iVar4 == 0) {
        plVar1 = plVar5 + 0x37;
        uVar6 = __list_add_valid(plVar1,PTR_cluster_dev_list_00105f28,&cluster_dev_list);
        if ((uVar6 & 1) != 0) {
          PTR_cluster_dev_list_00105f28 = (undefined *)plVar1;
          plVar5[0x37] = (long)&cluster_dev_list;
          plVar5[0x38] = (long)puVar2;
          *(long **)puVar2 = plVar1;
        }
        lVar7 = plVar5[0x12];
        *(undefined1 *)((long)plVar5 + 0x1cd) = 1;
        if ((((*(int *)(lVar7 + 0x5a0) != 0) &&
             (*(undefined1 *)(plVar5 + 0x36) = 1, 1 < *(uint *)(lVar7 + 0x5a0))) &&
            (*(undefined1 *)((long)plVar5 + 0x1b1) = 1, 2 < *(uint *)(lVar7 + 0x5a0))) &&
           (*(undefined1 *)((long)plVar5 + 0x1b2) = 1, 3 < *(uint *)(lVar7 + 0x5a0))) {
          *(undefined1 *)((long)plVar5 + 0x1b3) = 1;
          if (4 < *(uint *)(lVar7 + 0x5a0)) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1041d8);
            (*pcVar3)();
          }
        }
        register_cluster_governor_ops(gov_ops);
      }
      else {
        __pm_runtime_disable(param_1,1);
      }
      iVar4 = 0;
    }
    else {
      __pm_runtime_disable(param_1,1);
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// lpm_cluster_gov_remove @ 001041dc size=144
// signature: undefined lpm_cluster_gov_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpm_cluster_gov_remove(long param_1)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  ppuVar3 = &cluster_dev_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &cluster_dev_list) goto LAB_00104258;
  } while (ppuVar3[-0x25] != (undefined *)(*(long *)(param_1 + 0x278) + -0x390));
  ppuVar1 = ppuVar3 + -0x37;
  if (ppuVar1 == (undefined **)0x0) {
LAB_00104258:
    uVar2 = 0xffffffed;
  }
  else {
    __pm_runtime_disable(param_1 + 0x10,1);
    puVar4 = ppuVar3[-0x25];
    *(uint *)(puVar4 + 0x588) = *(uint *)(puVar4 + 0x588) & 0xffffffbf;
    remove_cluster_sysfs_nodes(ppuVar1);
    dev_pm_genpd_remove_notifier(*ppuVar1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// cluster_power_cb @ 00104270 size=1556
// signature: undefined cluster_power_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cluster_power_cb(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  int iVar14;
  ulong uVar15;
  long lVar16;
  
  lVar13 = *(long *)(param_1 + -0x30);
  if (param_2 != 0) {
    if (param_2 == 1) {
      uVar7 = tpidr_el1;
      return 1;
    }
    if (param_2 != 3) {
      return 1;
    }
    uVar7 = tpidr_el1;
    if (*(int *)(*(long *)(param_1 + -0x30) + 0x524) != 0) {
      return 1;
    }
    uVar7 = ktime_get();
    *(undefined8 *)(param_1 + 0xa8) = uVar7;
    lVar13 = __hrtimer_get_remaining(param_1 + 0x48,0);
    if (999 < lVar13) {
      hrtimer_try_to_cancel(param_1 + 0x48);
    }
    lVar13 = *(long *)(param_1 + -0x30);
    uVar12 = *(uint *)(lVar13 + 0x5a4);
    if (prediction_disabled == '\0') {
      uVar11 = *(uint *)(param_1 + -0xb8);
      if ((*(uint *)(param_1 + -0xb0) == 0xffffffff) || (*(uint *)(param_1 + -0xb0) == uVar12)) {
        if (4 < uVar11) goto LAB_00104880;
        lVar13 = param_1 + -0xc0;
        cVar1 = *(char *)(param_1 + -0xb3);
        uVar15 = (ulong)(uint)(*(int *)(param_1 + 0xa8) - (int)*(long *)(param_1 + 0x90)) / 1000;
        *(long *)(lVar13 + (ulong)uVar11 * 0x18 + 0x28) = *(long *)(param_1 + 0x90) / 1000;
        if (cVar1 == '\0') {
          lVar16 = lVar13 + (ulong)uVar11 * 0x18;
        }
        else {
          uVar9 = uVar11 - 1;
          bVar5 = uVar11 != 0;
          *(undefined1 *)(param_1 + -0xb3) = 0;
          uVar11 = 4;
          if (bVar5) {
            uVar11 = uVar9;
          }
          lVar16 = lVar13 + (ulong)uVar11 * 0x18;
          uVar15 = *(long *)(lVar16 + 0x18) + uVar15;
        }
        *(ulong *)(lVar16 + 0x18) = uVar15;
        iVar14 = *(int *)(param_1 + -0xac);
        *(undefined4 *)(param_1 + -0xb0) = 0x80000000;
        *(uint *)(lVar13 + (ulong)uVar11 * 0x18 + 0x20) = uVar12;
        *(undefined8 *)(param_1 + 0x90) = 0;
        if (iVar14 < 5) {
          *(int *)(param_1 + -0xac) = iVar14 + 1;
        }
        lVar13 = *(long *)(param_1 + -0x30);
        iVar14 = 0;
        if ((int)(uVar11 + 1) < 5) {
          iVar14 = uVar11 + 1;
        }
        *(int *)(param_1 + -0xb8) = iVar14;
        uVar12 = *(uint *)(lVar13 + 0x5a4);
      }
    }
    *(undefined1 *)(param_1 + 0x10c) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0x7fffffffffffffff;
    lVar16 = *(long *)(param_1 + 0xa8);
    if (prediction_disabled != '\0') {
      return 1;
    }
    if (*(char *)(param_1 + -0xb4) != '\0') {
      *(undefined2 *)(param_1 + -0xb4) = 0x100;
      return 1;
    }
    iVar14 = *(int *)(param_1 + -0xac);
    if (iVar14 == 5) {
      lVar2 = lVar16 / 1000;
      if ((ulong)(lVar2 - *(long *)(param_1 + -0x98)) < 0x9c41) {
        iVar14 = 5;
      }
      else {
        iVar14 = 4;
        *(undefined4 *)(param_1 + -0xac) = 4;
      }
      if (40000 < (ulong)(lVar2 - *(long *)(param_1 + -0x80))) {
        iVar14 = iVar14 + -1;
        *(int *)(param_1 + -0xac) = iVar14;
      }
      if (40000 < (ulong)(lVar2 - *(long *)(param_1 + -0x68))) {
        iVar14 = iVar14 + -1;
        *(int *)(param_1 + -0xac) = iVar14;
      }
      if (40000 < (ulong)(lVar2 - *(long *)(param_1 + -0x50))) {
        iVar14 = iVar14 + -1;
        *(int *)(param_1 + -0xac) = iVar14;
      }
      if (40000 < (ulong)(lVar2 - *(long *)(param_1 + -0x38))) {
        *(int *)(param_1 + -0xac) = iVar14 + -1;
        return 1;
      }
    }
    if (iVar14 < 5) {
      return 1;
    }
    uVar11 = *(uint *)(lVar13 + 0x5a0);
    if (uVar12 < uVar11 - 1) {
      lVar16 = lVar16 * 1000 +
               (ulong)(*(long *)(param_1 + -0x90) + *(long *)(param_1 + -0xa8) +
                       *(long *)(param_1 + -0x78) + *(long *)(param_1 + -0x60) +
                      *(long *)(param_1 + -0x48)) / 5;
    }
    else {
      if (uVar11 < 2) {
        return 1;
      }
      uVar12 = 1;
      while( true ) {
        uVar9 = *(uint *)(*(long *)(lVar13 + 0x590) + (long)(int)uVar12 * 0x40 + 0x10);
        if (*(uint *)(param_1 + -0xa0) == uVar12) {
          uVar15 = *(ulong *)(param_1 + -0xa8);
          bVar5 = uVar15 < uVar9 % 1000;
          uVar6 = (uint)bVar5;
          if (!bVar5) {
            uVar15 = 0;
          }
          uVar9 = uVar9 / 1000;
        }
        else {
          uVar6 = 0;
          uVar15 = 0;
        }
        if (*(uint *)(param_1 + -0x88) == uVar12) {
          uVar8 = (ulong)uVar9 / 1000;
          if (*(ulong *)(param_1 + -0x90) < (ulong)(uVar9 % 1000)) {
            uVar6 = uVar6 + 1;
            uVar15 = *(ulong *)(param_1 + -0x90) + uVar15;
          }
        }
        else {
          uVar8 = (ulong)uVar9;
        }
        iVar14 = (int)uVar8;
        if (*(uint *)(param_1 + -0x70) == uVar12) {
          uVar10 = uVar8 / 1000;
          uVar3 = uVar8 / 1000;
          uVar8 = uVar10;
          if (*(ulong *)(param_1 + -0x78) < (ulong)(uint)(iVar14 + (int)uVar3 * -1000)) {
            uVar6 = uVar6 + 1;
            uVar15 = *(ulong *)(param_1 + -0x78) + uVar15;
          }
        }
        iVar14 = (int)uVar8;
        if (*(uint *)(param_1 + -0x58) == uVar12) {
          uVar10 = uVar8 / 1000;
          uVar3 = uVar8 / 1000;
          uVar8 = uVar10;
          if (*(ulong *)(param_1 + -0x60) < (ulong)(uint)(iVar14 + (int)uVar3 * -1000)) {
            uVar6 = uVar6 + 1;
            uVar15 = *(ulong *)(param_1 + -0x60) + uVar15;
          }
        }
        if ((*(uint *)(param_1 + -0x40) == uVar12) &&
           (*(ulong *)(param_1 + -0x48) < (ulong)(uint)((int)uVar8 + (int)(uVar8 / 1000) * -1000)))
        {
          uVar6 = uVar6 + 1;
          uVar15 = *(ulong *)(param_1 + -0x48) + uVar15;
        }
        if (3 < uVar6) break;
        uVar12 = uVar12 + 1;
        if (uVar11 == uVar12) {
          return 1;
        }
      }
      uVar8 = 0;
      if ((ulong)uVar6 != 0) {
        uVar8 = uVar15 / uVar6;
      }
      lVar16 = lVar16 + uVar8 * 1000;
    }
    *(long *)(param_1 + 0xa0) = lVar16;
    *(undefined1 *)(param_1 + 0x10c) = 1;
    return 1;
  }
  if (*(long *)(lVar13 + 0x4c8) != 0) {
    if (3 < *(uint *)(lVar13 + 0x5a4)) {
LAB_00104880:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104884);
      (*pcVar4)();
    }
    if (*(char *)(param_1 + (ulong)*(uint *)(lVar13 + 0x5a4) + 0xf0) != '\0') {
      if (*(int *)(lVar13 + 0x524) != 0) {
LAB_0010440c:
        clear_cpu_predict_history();
        *(undefined8 *)(param_1 + -0xa8) = 0;
        *(undefined8 *)(param_1 + -0x98) = 0;
        *(undefined8 *)(param_1 + -0x90) = 0;
        *(undefined8 *)(param_1 + -0x80) = 0;
        *(undefined8 *)(param_1 + -0x78) = 0;
        *(undefined4 *)(param_1 + -0xa0) = 0xffffffff;
        *(undefined4 *)(param_1 + -0x88) = 0xffffffff;
        *(undefined4 *)(param_1 + -0x70) = 0xffffffff;
        *(undefined8 *)(param_1 + -0x68) = 0;
        *(undefined8 *)(param_1 + -0x60) = 0;
        *(undefined4 *)(param_1 + -0x58) = 0xffffffff;
        *(undefined8 *)(param_1 + -0x50) = 0;
        *(undefined8 *)(param_1 + -0x48) = 0;
        *(undefined4 *)(param_1 + -0x40) = 0xffffffff;
        *(undefined8 *)(param_1 + -0x38) = 0;
        *(undefined4 *)(param_1 + -0xb8) = 0;
        *(undefined4 *)(param_1 + -0xac) = 0;
        *(undefined2 *)(param_1 + -0xb4) = 0;
        return 1;
      }
      lVar16 = 0;
      uVar15 = (ulong)_nr_cpu_ids;
      while( true ) {
        uVar8 = _find_next_bit(lVar13 + 0x530,uVar15,(long)(int)lVar16);
        uVar15 = (ulong)_nr_cpu_ids;
        if (uVar15 <= (uVar8 & 0xffffffff)) break;
        if ((*(ulong *)(&__cpu_online_mask + (uVar8 >> 6 & 0x3ffffff) * 8) >> (uVar8 & 0x3f) & 1) !=
            0) {
          if ((uVar8 & 0xffffffe0) != 0) goto LAB_00104880;
          if ((&DAT_001068ec)[*(long *)(&__per_cpu_offset + (uVar8 & 0xffffffff) * 8)] != '\0') {
            return 0x8002;
          }
        }
        lVar13 = *(long *)(param_1 + -0x30);
        lVar16 = uVar8 + 1;
      }
      uVar7 = ktime_get();
      lVar13 = *(long *)(param_1 + -0x30);
      *(undefined8 *)(param_1 + 0xa8) = uVar7;
      uVar12 = *(uint *)(lVar13 + 0x5a4);
      if (-1 < (int)uVar12) {
        *(undefined8 *)(param_1 + 0x90) = uVar7;
        *(uint *)(param_1 + -0xb0) = uVar12;
        if (*(int *)(lVar13 + 0x5a0) - 1U <= uVar12) goto LAB_0010440c;
        if (*(long *)(param_1 + 0x98) == *(long *)(param_1 + 0xa0)) {
          uVar12 = *(uint *)(*(long *)(lVar13 + 0x590) + (long)(int)(uVar12 + 1) * 0x40 + 0x10);
          *(code **)(param_1 + 0x70) = clusttimer_fn;
          hrtimer_start_range_ns(param_1 + 0x48,(ulong)(uVar12 / 1000 + 100) * 1000,0,3);
        }
      }
      return 1;
    }
  }
  return 0x8002;
}



//------------------------------------------------------------
// clusttimer_fn @ 00104b24 size=20
// signature: undefined clusttimer_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 clusttimer_fn(long param_1)

{
  *(undefined1 *)(param_1 + -0xfc) = 1;
  return 0;
}



//------------------------------------------------------------
// remove_cluster_sysfs_nodes @ 00104b64 size=180
// signature: undefined remove_cluster_sysfs_nodes(void)
// callers: [lpm_cluster_gov_remove]
//------------------------------------------------------------

void remove_cluster_sysfs_nodes(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (qcom_lpm_kobj != 0) {
    lVar3 = *(long *)(param_1 + 0x90);
    uVar2 = *(undefined8 *)(param_1 + 0xb8);
    if (*(int *)(lVar3 + 0x5a0) != 0) {
      kobject_put(*(undefined8 *)(*(long *)(param_1 + 0x98) + 8));
      if (1 < *(uint *)(lVar3 + 0x5a0)) {
        kobject_put(*(undefined8 *)(*(long *)(param_1 + 0xa0) + 8));
        if (2 < *(uint *)(lVar3 + 0x5a0)) {
          kobject_put(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 8));
          if (3 < *(uint *)(lVar3 + 0x5a0)) {
            kobject_put(*(undefined8 *)(*(long *)(param_1 + 0xb0) + 8));
            if (4 < *(uint *)(lVar3 + 0x5a0)) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104c18);
              (*pcVar1)();
            }
          }
        }
      }
    }
    kobject_put(uVar2);
  }
  return;
}



//------------------------------------------------------------
// create_cluster_sysfs_nodes @ 00104c1c size=440
// signature: undefined create_cluster_sysfs_nodes(void)
// callers: [lpm_cluster_gov_probe]
//------------------------------------------------------------

void create_cluster_sysfs_nodes(undefined8 *param_1)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 local_78;
  undefined2 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  local_78 = 0;
  if (qcom_lpm_kobj == 0) {
    uVar8 = 0xfffffdfb;
  }
  else {
    lVar9 = param_1[0x12];
    lVar4 = kobject_create_and_add(*(undefined8 *)(lVar9 + 0x510));
    param_1[0x17] = lVar4;
    if (lVar4 == 0) {
LAB_00104d90:
      uVar8 = 0xfffffff4;
    }
    else {
      if (*(int *)(lVar9 + 0x5a0) != 0) {
        uVar7 = 0;
        do {
          plVar5 = (long *)devm_kmalloc(*param_1,0x48,0xdc0);
          if (plVar5 == (long *)0x0) {
LAB_00104d88:
            kobject_put(param_1[0x17]);
            goto LAB_00104d90;
          }
          *(int *)(plVar5 + 2) = (int)uVar7;
          *plVar5 = (long)param_1;
          scnprintf(&local_78,0x1000,&DAT_00106b77,uVar7 & 0xffffffff);
          lVar4 = kobject_create_and_add(&local_78,param_1[0x17]);
          plVar5[1] = lVar4;
          if (lVar4 == 0) goto LAB_00104d88;
          uVar8 = *param_1;
          lVar4 = devm_kmalloc(uVar8,0x28,0xdc0);
          plVar5[7] = lVar4;
          if (lVar4 == 0) {
LAB_00104d80:
            kobject_put(plVar5[1]);
            goto LAB_00104d88;
          }
          plVar6 = (long *)devm_kmalloc(uVar8,0x10,0xdc0);
          plVar5[8] = (long)plVar6;
          if (plVar6 == (long *)0x0) goto LAB_00104d80;
          lVar4 = plVar5[7];
          plVar5[3] = (long)"disable";
          *(undefined2 *)(plVar5 + 4) = 0x1a4;
          plVar5[5] = (long)cluster_idle_get;
          plVar5[6] = (long)cluster_idle_set;
          *plVar6 = (long)(plVar5 + 3);
          plVar6[1] = 0;
          *(long **)(lVar4 + 0x18) = plVar6;
          iVar3 = sysfs_create_group(plVar5[1],plVar5[7]);
          if (iVar3 != 0) goto LAB_00104d80;
          if (uVar7 == 4) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104dd0);
            (*pcVar2)();
          }
          uVar1 = uVar7 + 1;
          param_1[uVar7 + 0x13] = plVar5;
          uVar7 = uVar1;
        } while (uVar1 < *(uint *)(lVar9 + 0x5a0));
      }
      uVar8 = 0;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// remove_global_sysfs_nodes @ 00104dd8 size=36
// signature: undefined remove_global_sysfs_nodes(void)
// callers: [init_module]
//------------------------------------------------------------

void remove_global_sysfs_nodes(void)

{
  kobject_put(qcom_lpm_kobj);
  return;
}



//------------------------------------------------------------
// create_global_sysfs_nodes @ 00104e00 size=76
// signature: undefined create_global_sysfs_nodes(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 create_global_sysfs_nodes(void)

{
  undefined8 uVar1;
  
  qcom_lpm_kobj = kobject_create_and_add("qcom_lpm",__printk);
  if (qcom_lpm_kobj == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    uVar1 = sysfs_create_group(qcom_lpm_kobj,&lpm_gov_attr_group);
  }
  return uVar1;
}



//------------------------------------------------------------
// cluster_idle_get @ 00104e50 size=88
// signature: undefined cluster_idle_get(void)
// callers: []
//------------------------------------------------------------

long cluster_idle_get(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (3 < *(uint *)(param_2 + -8)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104ea8);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_00106a59,
                    *(char *)(*(long *)(param_2 + -0x18) + (ulong)*(uint *)(param_2 + -8) + 0x1b0)
                    == '\0');
  return (long)iVar2;
}



//------------------------------------------------------------
// cluster_idle_set @ 00104eac size=152
// signature: undefined cluster_idle_set(void)
// callers: []
//------------------------------------------------------------

undefined8 cluster_idle_set(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar3 = kstrtobool(param_3,local_2c);
  if (iVar3 == 0) {
    if (3 < *(uint *)(param_2 + -8)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104f44);
      (*pcVar2)();
    }
    *(byte *)(*(long *)(param_2 + -0x18) + (ulong)*(uint *)(param_2 + -8) + 0x1b0) = local_2c[0] ^ 1
    ;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sleep_disabled_show @ 00104f48 size=56
// signature: undefined sleep_disabled_show(void)
// callers: []
//------------------------------------------------------------

long sleep_disabled_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106a18,sleep_disabled);
  return (long)iVar1;
}



//------------------------------------------------------------
// sleep_disabled_store @ 00104f84 size=140
// signature: undefined sleep_disabled_store(void)
// callers: []
//------------------------------------------------------------

long sleep_disabled_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = kstrtobool(param_3,local_2c);
  if (iVar2 == 0) {
    sleep_disabled = local_2c[0];
  }
  else {
    _printk(&DAT_00106bdc);
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// prediction_disabled_show @ 00105014 size=56
// signature: undefined prediction_disabled_show(void)
// callers: []
//------------------------------------------------------------

long prediction_disabled_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106a18,prediction_disabled);
  return (long)iVar1;
}



//------------------------------------------------------------
// prediction_disabled_store @ 00105050 size=140
// signature: undefined prediction_disabled_store(void)
// callers: []
//------------------------------------------------------------

long prediction_disabled_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = kstrtobool(param_3,local_2c);
  if (iVar2 == 0) {
    prediction_disabled = local_2c[0];
  }
  else {
    _printk(&DAT_00106bdc);
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 001050fc size=216
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = create_global_sysfs_nodes();
  if (iVar1 == 0) {
    iVar1 = qcom_cluster_lpm_governor_init();
    if (iVar1 == 0) {
      iVar1 = cpuidle_register_governor(lpm_governor);
      if (iVar1 == 0) {
        iVar1 = tracepoint_probe_register(&__tracepoint_suspend_resume,qcom_lpm_suspend_trace,0);
        if (iVar1 == 0) {
          iVar1 = __cpuhp_setup_state(200,"qcom-cpu-lpm",1,lpm_online_cpu,lpm_offline_cpu,0);
          if (-1 < iVar1) {
            register_pm_notifier(&suspend_lpm_nb);
            return 0;
          }
          tracepoint_probe_unregister(&__tracepoint_suspend_resume,qcom_lpm_suspend_trace,0);
        }
      }
      qcom_cluster_lpm_governor_deinit();
    }
    remove_global_sysfs_nodes();
  }
  return iVar1;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00109000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_cluster_exit, trace_event_raw_event_lpm_gov_select, trace_event_raw_event_cluster_pred_hist, trace_event_raw_event_cluster_enter, trace_event_raw_event_gov_pred_select, trace_event_raw_event_cluster_pred_select, trace_event_raw_event_gov_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00109008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_cluster_exit, trace_event_raw_event_lpm_gov_select, trace_event_raw_event_cluster_pred_hist, trace_event_raw_event_cluster_enter, trace_event_raw_event_gov_pred_select, trace_event_raw_event_cluster_pred_select, trace_event_raw_event_gov_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00109010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_cluster_exit, trace_event_raw_event_lpm_gov_select, trace_event_raw_event_cluster_pred_hist, trace_event_raw_event_cluster_enter, trace_event_raw_event_gov_pred_select, trace_event_raw_event_cluster_pred_select, trace_event_raw_event_gov_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_cluster_exit, trace_event_raw_event_cluster_pred_hist, trace_event_raw_event_cluster_enter, create_cluster_sysfs_nodes, trace_event_raw_event_cluster_pred_select, perf_trace_cluster_pred_select, perf_trace_cluster_enter, sleep_disabled_store, cluster_idle_set, perf_trace_gov_pred_select, trace_event_raw_event_cluster_exit, trace_event_raw_event_lpm_gov_select, prediction_disabled_store, trace_event_raw_event_gov_pred_select, lpm_select, perf_trace_gov_pred_hist, perf_trace_cluster_pred_hist, perf_trace_lpm_gov_select, trace_event_raw_event_gov_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00109020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_gov_pred_select, perf_trace_cluster_exit, perf_trace_cluster_pred_select, perf_trace_cluster_enter, perf_trace_gov_pred_hist, perf_trace_cluster_pred_hist, perf_trace_lpm_gov_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00109028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_gov_pred_select, perf_trace_cluster_exit, perf_trace_cluster_pred_select, perf_trace_cluster_enter, perf_trace_gov_pred_hist, perf_trace_cluster_pred_hist, perf_trace_lpm_gov_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00109030 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_lpm_gov_select, __bpf_trace_cluster_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00109038 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_gov_pred_hist, __bpf_trace_gov_pred_select, __bpf_trace_cluster_exit, __bpf_trace_cluster_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00109058 size=1
// signature: undefined _find_next_bit(void)
// callers: [ipi_raise, clear_cpu_predict_history, qcom_lpm_suspend_trace, lpm_select, lpm_disable_device, cluster_power_cb, suspend_lpm_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpuidle_register_governor @ 00109060 size=1
// signature: undefined cpuidle_register_governor(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpuidle_register_governor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00109070 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [lpm_enable_device, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 00109078 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00109080 size=1
// signature: undefined register_pm_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00109088 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [lpm_enable_device, init_module, lpm_disable_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00109090 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_cluster_exit, trace_raw_output_gov_pred_select, trace_raw_output_cluster_enter, trace_raw_output_gov_pred_hist, trace_raw_output_lpm_gov_select, trace_raw_output_cluster_pred_select, trace_raw_output_cluster_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00109098 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_cluster_exit, trace_raw_output_gov_pred_select, trace_raw_output_cluster_enter, trace_raw_output_gov_pred_hist, trace_raw_output_lpm_gov_select, trace_raw_output_cluster_pred_select, trace_raw_output_cluster_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 001090a0 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_cluster_exit, trace_raw_output_gov_pred_select, trace_raw_output_cluster_enter, trace_raw_output_gov_pred_hist, trace_raw_output_lpm_gov_select, trace_raw_output_cluster_pred_select, trace_raw_output_cluster_pred_hist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001090a8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_lpm_suspend_trace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_if_idle @ 001090b8 size=1
// signature: undefined wake_up_if_idle(void)
// callers: [lpm_cpu_qos_notify, qcom_lpm_suspend_trace, suspend_lpm_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_if_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 001090c0 size=1
// signature: undefined get_cpu_device(void)
// callers: [lpm_online_cpu, lpm_offline_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_notifier @ 001090c8 size=1
// signature: undefined dev_pm_qos_add_notifier(void)
// callers: [lpm_online_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_notifier @ 001090d0 size=1
// signature: undefined dev_pm_qos_remove_notifier(void)
// callers: [lpm_offline_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 001090d8 size=1
// signature: undefined hrtimer_init(void)
// callers: [lpm_enable_device, lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register_prio @ 001090f8 size=1
// signature: undefined tracepoint_probe_register_prio(void)
// callers: [lpm_enable_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register_prio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpuidle_governor_latency_req @ 00109118 size=1
// signature: undefined cpuidle_governor_latency_req(void)
// callers: [lpm_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpuidle_governor_latency_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00109120 size=1
// signature: undefined ktime_get(void)
// callers: [ipi_raise, lpm_select, cluster_power_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tick_nohz_get_sleep_length @ 00109128 size=1
// signature: undefined tick_nohz_get_sleep_length(void)
// callers: [lpm_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tick_nohz_get_sleep_length(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00109130 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [lpm_select, cluster_power_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_lpm_disallowed_time @ 00109148 size=1
// signature: undefined sched_lpm_disallowed_time(void)
// callers: [lpm_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_lpm_disallowed_time(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00109150 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ipi_entry, lpm_select, lpm_idle_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00109158 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ipi_raise, ipi_entry, lpm_select, lpm_idle_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_trylock @ 00109168 size=1
// signature: undefined _raw_spin_trylock(void)
// callers: [ipi_raise]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 00109170 size=1
// signature: undefined hrtimer_active(void)
// callers: [lpm_idle_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __hrtimer_get_remaining @ 00109178 size=1
// signature: undefined __hrtimer_get_remaining(void)
// callers: [lpm_idle_exit, cluster_power_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __hrtimer_get_remaining(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_try_to_cancel @ 00109180 size=1
// signature: undefined hrtimer_try_to_cancel(void)
// callers: [lpm_idle_exit, cluster_power_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_try_to_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// int_sqrt @ 00109188 size=1
// signature: undefined int_sqrt(void)
// callers: [find_deviation]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void int_sqrt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 00109190 size=1
// signature: undefined preempt_schedule(void)
// callers: [lpm_cpu_qos_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 001091a8 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_cluster_pred_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_and_bit @ 001091b0 size=1
// signature: undefined _find_next_and_bit(void)
// callers: [get_cluster_sleep_time, update_cluster_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_and_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_set_next_wakeup @ 001091b8 size=1
// signature: undefined dev_pm_genpd_set_next_wakeup(void)
// callers: [update_cluster_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_set_next_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001091c0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [update_cluster_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001091c8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [update_cluster_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 001091d0 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [qcom_cluster_lpm_governor_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001091d8 size=1
// signature: undefined __platform_driver_register(void)
// callers: [qcom_cluster_lpm_governor_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001091e0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [create_cluster_sysfs_nodes, lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 001091e8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_add_notifier @ 001091f0 size=1
// signature: undefined dev_pm_genpd_add_notifier(void)
// callers: [lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_add_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 001091f8 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpm_cluster_gov_remove, lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00109200 size=1
// signature: undefined __list_add_valid(void)
// callers: [lpm_cluster_gov_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_remove_notifier @ 00109208 size=1
// signature: undefined dev_pm_genpd_remove_notifier(void)
// callers: [lpm_cluster_gov_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_remove_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00109210 size=1
// signature: undefined kobject_put(void)
// callers: [remove_cluster_sysfs_nodes, remove_global_sysfs_nodes, create_cluster_sysfs_nodes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00109218 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [create_cluster_sysfs_nodes, create_global_sysfs_nodes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00109220 size=1
// signature: undefined scnprintf(void)
// callers: [sleep_disabled_show, create_cluster_sysfs_nodes, prediction_disabled_show, cluster_idle_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00109228 size=1
// signature: undefined sysfs_create_group(void)
// callers: [create_cluster_sysfs_nodes, create_global_sysfs_nodes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00109238 size=1
// signature: undefined kstrtobool(void)
// callers: [prediction_disabled_store, sleep_disabled_store, cluster_idle_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109240 size=1
// signature: undefined _printk(void)
// callers: [prediction_disabled_store, sleep_disabled_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



