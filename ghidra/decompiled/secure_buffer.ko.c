// Decompiled by Ghidra 12.2
// Program: secure_buffer.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_hyp_assign_info @ 0010077c size=148
// signature: undefined __traceiter_hyp_assign_info(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_hyp_assign_info
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00102b98;
  plVar2 = DAT_00102b98;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x708bdfa5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1007e8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_hyp_assign_batch_start @ 00100814 size=116
// signature: undefined __traceiter_hyp_assign_batch_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_hyp_assign_batch_start(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00102be0;
  plVar2 = _DAT_00102be0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x39ef4fe8) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100864);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_hyp_assign_batch_end @ 0010088c size=116
// signature: undefined __traceiter_hyp_assign_batch_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_hyp_assign_batch_end(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00102c28;
  plVar2 = _DAT_00102c28;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x527b6ea3) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1008dc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_hyp_assign_end @ 00100904 size=116
// signature: undefined __traceiter_hyp_assign_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_hyp_assign_end(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00102c70;
  plVar2 = _DAT_00102c70;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x743ce23f) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100954);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_hyp_assign_info @ 0010097c size=332
// signature: undefined trace_event_raw_event_hyp_assign_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hyp_assign_info
               (long param_1,void *param_2,uint param_3,void *param_4,void *param_5,uint param_6)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) {
    iVar1 = param_6 * 4 + param_3 * 4;
    lVar2 = trace_event_buffer_reserve(&local_88,param_1,(long)(int)(iVar1 + param_6 * 4) + 0x1c);
    if (lVar2 != 0) {
      *(uint *)(lVar2 + 0x10) = param_3 << 0x12 | 0x1c;
      *(uint *)(lVar2 + 0x14) = param_6 << 0x12 | param_3 * 4 + 0x1c;
      *(uint *)(lVar2 + 0x18) = iVar1 + 0x1cU | param_6 << 0x12;
      *(uint *)(lVar2 + 8) = param_3;
      *(uint *)(lVar2 + 0xc) = param_6;
      memcpy((void *)(lVar2 + 0x1c),param_2,
             -(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_3 << 2);
      uVar3 = -(ulong)(param_6 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_6 << 2;
      memcpy((void *)(lVar2 + (ulong)*(ushort *)(lVar2 + 0x14)),param_4,uVar3);
      memcpy((void *)(lVar2 + (ulong)*(ushort *)(lVar2 + 0x18)),param_5,uVar3);
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hyp_assign_info @ 00100acc size=404
// signature: undefined perf_trace_hyp_assign_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hyp_assign_info
               (long param_1,void *param_2,uint param_3,void *param_4,void *param_5,uint param_6)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong unaff_x30;
  undefined1 auStack_90 [8];
  void *local_88;
  void *local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar4 = tpidr_el1;
  plVar2 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  local_88 = param_4;
  local_80 = param_5;
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = param_6 * 4 + param_3 * 4;
    iVar3 = (param_6 * 4 + iVar1 + 0x27 & 0xfffffff8) - 4;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar4 != 0) {
      uVar5 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar5 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(ulong *)(local_70 + 0x100) = uVar5;
      *(uint *)(lVar4 + 8) = param_3;
      *(uint *)(lVar4 + 0xc) = param_6;
      *(uint *)(lVar4 + 0x10) = param_3 << 0x12 | 0x1c;
      *(uint *)(lVar4 + 0x14) = param_6 << 0x12 | param_3 * 4 + 0x1c;
      *(uint *)(lVar4 + 0x18) = iVar1 + 0x1cU | param_6 << 0x12;
      memcpy((void *)(lVar4 + 0x1c),param_2,
             -(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_3 << 2);
      uVar5 = -(ulong)(param_6 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_6 << 2;
      memcpy((void *)(lVar4 + (ulong)*(ushort *)(lVar4 + 0x14)),local_88,uVar5);
      memcpy((void *)(lVar4 + (ulong)*(ushort *)(lVar4 + 0x18)),local_80,uVar5);
      perf_trace_run_bpf_submit(lVar4,iVar3,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_hyp_assign_batch_start @ 00100c64 size=276
// signature: undefined trace_event_raw_event_hyp_assign_batch_start(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hyp_assign_batch_start(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  uVar6 = (ulong)param_3;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar3 = __trace_trigger_soft_disabled(param_1), (uVar3 & 1) == 0)) &&
     (lVar2 = trace_event_buffer_reserve(&local_58,param_1,(long)(int)(param_3 << 4) + 0x20),
     lVar2 != 0)) {
    uVar1 = param_3 * 8 + 0x20;
    *(uint *)(lVar2 + 8) = param_3;
    *(undefined8 *)(lVar2 + 0x10) = 0;
    *(uint *)(lVar2 + 0x18) = param_3 << 0x13 | 0x20;
    *(uint *)(lVar2 + 0x1c) = uVar1 | param_3 << 0x13;
    if (param_3 != 0) {
      plVar4 = (long *)(param_2 + 8);
      lVar5 = lVar2;
      do {
        uVar6 = uVar6 - 1;
        *(long *)(lVar5 + 0x20) = plVar4[-1];
        *(long *)(lVar5 + ((ulong)uVar1 & 0xfff8)) = *plVar4;
        lVar5 = lVar5 + 8;
        *(long *)(lVar2 + 0x10) = *(long *)(lVar2 + 0x10) + *plVar4;
        plVar4 = plVar4 + 2;
      } while (uVar6 != 0);
    }
    trace_event_buffer_commit(&local_58);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hyp_assign_batch_start @ 00100d7c size=360
// signature: undefined perf_trace_hyp_assign_batch_start(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hyp_assign_batch_start(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar4 = tpidr_el1;
  plVar2 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar3 = param_3 * 0x10 + 0x24;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_50,&local_54);
    if (lVar4 != 0) {
      uVar1 = param_3 * 8 + 0x20;
      uVar5 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar5 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
      *(undefined1 **)(local_50 + 0xf8) = auStack_60;
      *(ulong *)(local_50 + 0x100) = uVar5;
      *(undefined8 *)(local_50 + 0x108) = 5;
      *(uint *)(lVar4 + 0x18) = param_3 << 0x13 | 0x20;
      *(uint *)(lVar4 + 0x1c) = uVar1 | param_3 << 0x13;
      *(uint *)(lVar4 + 8) = param_3;
      *(undefined8 *)(lVar4 + 0x10) = 0;
      if (param_3 != 0) {
        uVar5 = (ulong)param_3;
        plVar6 = (long *)(param_2 + 8);
        lVar7 = lVar4;
        do {
          uVar5 = uVar5 - 1;
          *(long *)(lVar7 + 0x20) = plVar6[-1];
          *(long *)(lVar7 + ((ulong)uVar1 & 0xffff)) = *plVar6;
          lVar7 = lVar7 + 8;
          *(long *)(lVar4 + 0x10) = *(long *)(lVar4 + 0x10) + *plVar6;
          plVar6 = plVar6 + 2;
        } while (uVar5 != 0);
      }
      perf_trace_run_bpf_submit(lVar4,iVar3,local_54,param_1,1,local_50,plVar2,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_hyp_assign_batch_end @ 00100ee8 size=176
// signature: undefined trace_event_raw_event_hyp_assign_batch_end(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hyp_assign_batch_end(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hyp_assign_batch_end @ 00100f9c size=252
// signature: undefined perf_trace_hyp_assign_batch_end(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hyp_assign_batch_end(long param_1,undefined4 param_2,undefined8 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
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
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_hyp_assign_end @ 0010109c size=172
// signature: undefined trace_event_raw_event_hyp_assign_end(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_hyp_assign_end(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_hyp_assign_end @ 0010114c size=248
// signature: undefined perf_trace_hyp_assign_end(void)
// callers: []
//------------------------------------------------------------

void perf_trace_hyp_assign_end(long param_1,undefined8 param_2,undefined8 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_hyp_assign_info @ 00101248 size=36
// signature: undefined __bpf_trace_hyp_assign_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hyp_assign_info
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_hyp_assign_batch_start @ 00101270 size=32
// signature: undefined __bpf_trace_hyp_assign_batch_start(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hyp_assign_batch_start(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_hyp_assign_batch_end @ 00101294 size=32
// signature: undefined __bpf_trace_hyp_assign_batch_end(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hyp_assign_batch_end(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run2(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_hyp_assign_end @ 001012b8 size=28
// signature: undefined __bpf_trace_hyp_assign_end(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_hyp_assign_end(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// page_accessible @ 001012d8 size=48
// signature: undefined page_accessible(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool page_accessible(long param_1)

{
  return *(long *)(param_1 * 0x40 + (_memstart_addr >> 0xc) * -0x40 + -0x1ffffffd8) != 0xeeeeeeee;
}



//------------------------------------------------------------
// hyp_assign_table @ 0010130c size=884
// signature: undefined hyp_assign_table(void)
// callers: []
//------------------------------------------------------------

int hyp_assign_table(long *param_1,long param_2,uint param_3,undefined4 *param_4,undefined4 *param_5
                    ,uint param_6)

{
  undefined4 uVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  ulong uVar15;
  
  if (qcom_secure_buffer_dev == (long *)0x0) {
    iVar4 = -0x205;
  }
  else if (param_1 == (long *)0x0) {
    iVar4 = -0x16;
  }
  else {
    iVar4 = -0x16;
    if ((((param_6 != 0) && (param_5 != (undefined4 *)0x0)) && (param_4 != (undefined4 *)0x0)) &&
       (((param_3 != 0 && (param_2 != 0)) && ((*param_1 != 0 && ((int)param_1[1] != 0)))))) {
      uVar15 = -(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_3 << 2;
      uVar5 = kmemdup(param_2,uVar15,0xcc0);
      plVar2 = qcom_secure_buffer_dev;
      if (uVar5 == 0) {
        iVar4 = -0xc;
      }
      else {
        uVar6 = is_vmalloc_addr();
        if (((uVar6 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar10 = dev_driver_string(plVar2);
          lVar7 = plVar2[0xe];
          if (lVar7 == 0) {
            lVar7 = *plVar2;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar10,lVar7);
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10164c);
          (*pcVar3)();
        }
        if (((uVar6 & 1) == 0) &&
           (lVar7 = dma_map_page_attrs(plVar2,(((long)(uVar5 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                              0x40 + -0x200000000,uVar5 & 0xfff,uVar15,1,0),
           lVar7 != -1)) {
          uVar6 = (long)(int)param_6 * 0x18;
          if (uVar6 < 0x1001) {
            lVar8 = __kmalloc(uVar6,0xdc0);
            if (lVar8 == 0) {
              iVar4 = -0xc;
            }
            else {
              if (0 < (int)param_6) {
                uVar11 = 0;
                uVar12 = uVar6 - 0x10;
                puVar13 = param_5;
                puVar14 = param_4;
                do {
                  if ((undefined4 *)(lVar8 + uVar11) != (undefined4 *)0x0) {
                    if (((uVar6 <= uVar11) || ((long)uVar11 < 0)) || (uVar6 <= uVar11)) {
LAB_00101544:
                    /* WARNING: Does not return */
                      pcVar3 = (code *)SoftwareBreakpoint(1,0x101548);
                      (*pcVar3)();
                    }
                    uVar1 = *puVar13;
                    *(undefined4 *)(lVar8 + uVar11) = *puVar14;
                    if (((uVar6 < uVar11 + 4) || ((long)(uVar11 + 4) < 0)) || (uVar6 < uVar11 + 4))
                    goto LAB_00101544;
                    *(undefined4 *)(lVar8 + uVar11 + 4) = uVar1;
                    if ((uVar6 < uVar11 + 8) || (0xfffffffffffffff7 < uVar12)) goto LAB_00101544;
                    if (((((long)(uVar11 + 8) < 0) ||
                         ((((uVar6 < uVar11 + 8 || (0xfffffffffffffff7 < uVar12)) ||
                           (*(undefined8 *)(lVar8 + uVar11 + 8) = 0, uVar6 < uVar11 + 0x10)) ||
                          ((uVar12 < 4 || ((long)(uVar11 + 0x10) < 0)))))) ||
                        (uVar6 < uVar11 + 0x10)) || (uVar12 < 4)) goto LAB_00101544;
                    *(undefined4 *)(lVar8 + uVar11 + 0x10) = 0;
                  }
                  uVar12 = uVar12 - 0x18;
                  uVar11 = uVar11 + 0x18;
                  puVar14 = puVar14 + 1;
                  puVar13 = puVar13 + 1;
                } while ((ulong)param_6 * 0x18 != uVar11);
              }
              lVar9 = dma_map_single_attrs(qcom_secure_buffer_dev,lVar8,uVar6);
              if (lVar9 == -1) {
                iVar4 = -0xc;
              }
              else {
                trace_hyp_assign_info(param_2,(ulong)param_3,param_4,param_5,param_6);
                iVar4 = batched_hyp_assign(param_1,uVar5,uVar15,lVar8,uVar6);
                if (iVar4 == 0) {
                  uVar10 = 0xeeeeeeee;
                  do {
                    param_6 = param_6 - 1;
                    if (param_6 == 0xffffffff) goto LAB_001015c4;
                  } while (param_4[(int)param_6] != 3);
                  uVar10 = 0;
LAB_001015c4:
                  set_each_page_of_sg(param_1,uVar10);
                }
                dma_unmap_page_attrs(qcom_secure_buffer_dev,lVar9,uVar6,1,0);
              }
              kfree(lVar8);
            }
          }
          else {
            iVar4 = -0xc;
          }
          dma_unmap_page_attrs(qcom_secure_buffer_dev,lVar7,uVar15,1,0);
        }
        else {
          iVar4 = -0xc;
        }
        kfree(uVar5);
      }
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// dma_map_single_attrs @ 00101684 size=188
// signature: undefined dma_map_single_attrs(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

undefined8 dma_map_single_attrs(long *param_1,ulong param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = is_vmalloc_addr(param_2);
  if (((uVar2 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar3 = dev_driver_string(param_1);
    lVar4 = param_1[0xe];
    if (lVar4 == 0) {
      lVar4 = *param_1;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar3,lVar4);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1016fc);
    (*pcVar1)();
  }
  if ((uVar2 & 1) == 0) {
    uVar3 = dma_map_page_attrs(param_1,(((long)(param_2 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                       -0x200000000,param_2 & 0xfff,param_3,1,0);
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}



//------------------------------------------------------------
// trace_hyp_assign_info @ 00101744 size=44
// signature: undefined trace_hyp_assign_info(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

void trace_hyp_assign_info(void)

{
  return;
}



//------------------------------------------------------------
// batched_hyp_assign @ 00101828 size=744
// signature: undefined batched_hyp_assign(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
batched_hyp_assign(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  undefined8 uVar11;
  uint uVar12;
  ulong *puVar13;
  
  puVar13 = (ulong *)*param_1;
  uVar6 = kmalloc_trace(_trace_print_array_seq,0xdc0,0x200);
  if (uVar6 == 0) {
    uVar11 = 0xfffffff4;
  }
  else {
    ktime_get();
    if ((int)param_1[1] == 0) {
      uVar11 = 0;
    }
    else {
      uVar12 = 0;
      uVar11 = sp_el0;
      do {
        lVar10 = 0;
        lVar3 = 0;
        uVar7 = 0;
        do {
          uVar9 = uVar7;
          lVar8 = lVar3;
          if (uVar6 + lVar8 != 0) {
            uVar1 = *(uint *)((long)puVar13 + 0xc);
            *(long *)(uVar6 + lVar8) =
                 ((*puVar13 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                 0x8000000000;
            ((long *)(uVar6 + lVar8))[1] = (ulong)uVar1;
          }
          uVar1 = *(uint *)((long)puVar13 + 0xc);
          puVar13 = (ulong *)sg_next(puVar13);
          plVar2 = qcom_secure_buffer_dev;
          if ((puVar13 == (ulong *)0x0) || (0x1e < uVar9)) break;
          lVar10 = lVar10 + (ulong)uVar1;
          lVar3 = lVar8 + 0x10;
          uVar7 = uVar9 + 1;
        } while (lVar10 + (ulong)*(uint *)((long)puVar13 + 0xc) < 0x200000);
        uVar7 = is_vmalloc_addr(uVar6);
        if (((uVar7 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar11 = dev_driver_string(plVar2);
          lVar10 = plVar2[0xe];
          if (lVar10 == 0) {
            lVar10 = *plVar2;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar11,lVar10);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x101a64);
          (*pcVar4)();
        }
        if ((uVar7 & 1) != 0) {
LAB_00101bc8:
          uVar11 = 0xffffff9d;
          goto LAB_00101bec;
        }
        lVar8 = lVar8 + 0x10;
        lVar10 = dma_map_page_attrs(plVar2,(((long)(uVar6 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40
                                           + -0x200000000,uVar6 & 0xfc0,lVar8,1,0);
        if (lVar10 == -1) goto LAB_00101bc8;
        ktime_get();
        iVar5 = qcom_scm_assign_mem_regions(uVar6,lVar8,param_2,param_3,param_4,param_5);
        ktime_get();
        dma_unmap_page_attrs(qcom_secure_buffer_dev,lVar10,lVar8,1,0);
        if (iVar5 != 0) {
          _printk(&DAT_0010347f,"batched_hyp_assign",iVar5);
          uVar11 = 0xffffff9d;
          goto LAB_00101bec;
        }
        uVar12 = uVar12 + (int)uVar9 + 1;
      } while (uVar12 < *(uint *)(param_1 + 1));
      uVar11 = 0;
    }
LAB_00101bec:
    ktime_get();
    kfree(uVar6);
  }
  return uVar11;
}



//------------------------------------------------------------
// set_each_page_of_sg @ 00101d08 size=168
// signature: undefined set_each_page_of_sg(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

void set_each_page_of_sg(long *param_1,undefined8 param_2)

{
  uint uVar1;
  ulong *puVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  
  if ((int)param_1[1] != 0) {
    uVar5 = 0;
    puVar2 = (ulong *)*param_1;
    do {
      uVar1 = *(uint *)((long)puVar2 + 0xc);
      if (-(uint)((uVar1 & 0xfff) != 0) != uVar1 >> 0xc) {
        uVar3 = (ulong)(uVar1 >> 0xc);
        if ((uVar1 & 0xfff) != 0) {
          uVar3 = uVar3 + 1;
        }
        lVar4 = uVar3 * 0x40 + -0x18;
        do {
          uVar3 = uVar3 - 1;
          *(undefined8 *)((*puVar2 & 0xfffffffffffffffc) + lVar4) = param_2;
          lVar4 = lVar4 + -0x40;
        } while ((int)uVar3 != 0);
      }
      uVar5 = uVar5 + 1;
      puVar2 = (ulong *)sg_next();
    } while (uVar5 < *(uint *)(param_1 + 1));
  }
  return;
}



//------------------------------------------------------------
// msm_secure_vmid_to_string @ 00101db4 size=40
// signature: undefined msm_secure_vmid_to_string(void)
// callers: []
//------------------------------------------------------------

char * msm_secure_vmid_to_string(int param_1)

{
  if (param_1 + 1U < 0x2d) {
    return (&PTR_s_VMID_INVAL_00102e18)[(int)(param_1 + 1U)];
  }
  return "Unknown VMID";
}



//------------------------------------------------------------
// msm_secure_get_vmid_perms @ 00101de0 size=60
// signature: undefined msm_secure_get_vmid_perms(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_secure_get_vmid_perms(int param_1)

{
  if (param_1 != 0x11) {
    if (param_1 == 0x2a) {
      return 7;
    }
    if ((param_1 != 0x1d) || (vmid_cp_camera_preview_ro == '\0')) {
      return 6;
    }
  }
  return 4;
}



//------------------------------------------------------------
// trace_raw_output_hyp_assign_info @ 00101e20 size=200
// signature: undefined trace_raw_output_hyp_assign_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hyp_assign_info(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    lVar1 = param_1 + 0x90;
    uVar3 = trace_print_array_seq
                      (lVar1,lVar6 + (ulong)*(ushort *)(lVar6 + 0x10),*(undefined4 *)(lVar6 + 8),4);
    uVar4 = trace_print_array_seq
                      (lVar1,lVar6 + (ulong)*(ushort *)(lVar6 + 0x14),*(undefined4 *)(lVar6 + 0xc),4
                      );
    uVar5 = trace_print_array_seq
                      (lVar1,lVar6 + (ulong)*(ushort *)(lVar6 + 0x18),*(undefined4 *)(lVar6 + 0xc),4
                      );
    trace_event_printf(param_1,"srcVMIDs: %s dstVMIDs: %s dstPerms: %s\n",uVar3,uVar4,uVar5);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_hyp_assign_batch_start @ 00101eec size=192
// signature: undefined trace_raw_output_hyp_assign_batch_start(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hyp_assign_batch_start(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(undefined4 *)(lVar6 + 8);
    uVar5 = *(undefined8 *)(lVar6 + 0x10);
    uVar3 = trace_print_array_seq(param_1 + 0x90,lVar6 + (ulong)*(ushort *)(lVar6 + 0x18),uVar1,8);
    uVar4 = trace_print_array_seq
                      (param_1 + 0x90,lVar6 + (ulong)*(ushort *)(lVar6 + 0x1c),
                       *(undefined4 *)(lVar6 + 8),8);
    trace_event_printf(param_1,"num entries: %d batch size: %llu phys addrs: %s sizes: %s\n",uVar1,
                       uVar5,uVar3,uVar4);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_hyp_assign_batch_end @ 00101fb0 size=104
// signature: undefined trace_raw_output_hyp_assign_batch_end(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hyp_assign_batch_end(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"ret: %d time delta: %lld us\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_hyp_assign_end @ 0010201c size=100
// signature: undefined trace_raw_output_hyp_assign_end(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_hyp_assign_end(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"total time delta: %lld us avg batch delta: %lld us\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// qcom_secure_buffer_probe @ 00102084 size=116
// signature: undefined qcom_secure_buffer_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_secure_buffer_probe(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = dma_set_mask(param_1 + 0x10,0xffffffffffffffff);
  if (iVar1 == 0) {
    qcom_secure_buffer_dev = param_1 + 0x10;
    lVar2 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,vmid-cp-camera-preview-ro",0);
    vmid_cp_camera_preview_ro = lVar2 != 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00102190 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_secure_buffer_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001021c0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_secure_buffer_driver);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00105000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_hyp_assign_info, trace_event_raw_event_hyp_assign_batch_start, trace_event_raw_event_hyp_assign_end, trace_event_raw_event_hyp_assign_batch_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105008 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [perf_trace_hyp_assign_info, trace_event_raw_event_hyp_assign_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00105010 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_hyp_assign_info, trace_event_raw_event_hyp_assign_batch_start, trace_event_raw_event_hyp_assign_end, trace_event_raw_event_hyp_assign_batch_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00105018 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_hyp_assign_info, trace_event_raw_event_hyp_assign_batch_start, trace_event_raw_event_hyp_assign_end, trace_event_raw_event_hyp_assign_batch_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_hyp_assign_batch_end, perf_trace_hyp_assign_info, trace_event_raw_event_hyp_assign_info, perf_trace_hyp_assign_batch_start, trace_event_raw_event_hyp_assign_batch_start, perf_trace_hyp_assign_end, trace_event_raw_event_hyp_assign_end, trace_event_raw_event_hyp_assign_batch_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00105028 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_hyp_assign_batch_end, perf_trace_hyp_assign_info, perf_trace_hyp_assign_batch_start, perf_trace_hyp_assign_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00105030 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_hyp_assign_batch_end, perf_trace_hyp_assign_info, perf_trace_hyp_assign_batch_start, perf_trace_hyp_assign_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00105038 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_hyp_assign_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00105040 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_hyp_assign_end, __bpf_trace_hyp_assign_batch_start, __bpf_trace_hyp_assign_batch_end]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00105050 size=1
// signature: undefined kmemdup(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00105058 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [dma_map_single_attrs, batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00105060 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [dma_map_single_attrs, batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105068 size=1
// signature: undefined __kmalloc(void)
// callers: [hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 00105070 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105078 size=1
// signature: undefined kfree(void)
// callers: [batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 00105080 size=1
// signature: undefined dev_driver_string(void)
// callers: [dma_map_single_attrs, batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00105088 size=1
// signature: undefined __warn_printk(void)
// callers: [dma_map_single_attrs, batched_hyp_assign, hyp_assign_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001050b0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [batched_hyp_assign]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001050b8 size=1
// signature: undefined ktime_get(void)
// callers: [batched_hyp_assign]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 001050c0 size=1
// signature: undefined sg_next(void)
// callers: [batched_hyp_assign, set_each_page_of_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem_regions @ 001050c8 size=1
// signature: undefined qcom_scm_assign_mem_regions(void)
// callers: [batched_hyp_assign]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem_regions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050d0 size=1
// signature: undefined _printk(void)
// callers: [batched_hyp_assign]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001050d8 size=1
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
// platform_driver_unregister @ 001050e0 size=1
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
// trace_raw_output_prep @ 001050e8 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_hyp_assign_info, trace_raw_output_hyp_assign_batch_end, trace_raw_output_hyp_assign_end, trace_raw_output_hyp_assign_batch_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_array_seq @ 001050f0 size=1
// signature: undefined trace_print_array_seq(void)
// callers: [trace_raw_output_hyp_assign_info, trace_raw_output_hyp_assign_batch_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_array_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 001050f8 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_hyp_assign_info, trace_raw_output_hyp_assign_batch_end, trace_raw_output_hyp_assign_end, trace_raw_output_hyp_assign_batch_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00105100 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_hyp_assign_info, trace_raw_output_hyp_assign_batch_end, trace_raw_output_hyp_assign_end, trace_raw_output_hyp_assign_batch_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00105108 size=1
// signature: undefined dma_set_mask(void)
// callers: [qcom_secure_buffer_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105110 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_secure_buffer_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



