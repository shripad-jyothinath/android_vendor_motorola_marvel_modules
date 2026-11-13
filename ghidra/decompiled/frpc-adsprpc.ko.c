// Decompiled by Ghidra 12.2
// Program: frpc-adsprpc.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_fastrpc_transport_send @ 00108034 size=172
// signature: undefined __traceiter_fastrpc_transport_send(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_fastrpc_transport_send
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0014ad88;
  plVar2 = DAT_0014ad88;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5fb5cb77) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1080b4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_transport_response @ 001080e4 size=148
// signature: undefined __traceiter_fastrpc_transport_response(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_transport_response
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014add0;
  plVar2 = _DAT_0014add0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1c552f57) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108150);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_context_interrupt @ 0010817c size=148
// signature: undefined __traceiter_fastrpc_context_interrupt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_context_interrupt
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014ae18;
  plVar2 = _DAT_0014ae18;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x99b2500) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1081e8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_context_restore @ 00108214 size=148
// signature: undefined __traceiter_fastrpc_context_restore(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_context_restore
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014ae60;
  plVar2 = _DAT_0014ae60;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x99b2500) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108280);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_dma_map @ 001082ac size=172
// signature: undefined __traceiter_fastrpc_dma_map(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_dma_map
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014aea8;
  plVar2 = _DAT_0014aea8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x83677e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10832c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_dma_unmap @ 0010835c size=124
// signature: undefined __traceiter_fastrpc_dma_unmap(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_dma_unmap
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014aef0;
  plVar2 = _DAT_0014aef0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x13e07d95) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1083b4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_dma_alloc @ 001083dc size=148
// signature: undefined __traceiter_fastrpc_dma_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_dma_alloc
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014af38;
  plVar2 = _DAT_0014af38;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7c740c12) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108448);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_dma_free @ 00108474 size=124
// signature: undefined __traceiter_fastrpc_dma_free(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_dma_free
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014af80;
  plVar2 = _DAT_0014af80;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x13e07d95) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1084cc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_context_complete @ 001084f4 size=164
// signature: undefined __traceiter_fastrpc_context_complete(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_context_complete
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014afc8;
  plVar2 = _DAT_0014afc8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x6169cac2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10856c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_context_alloc @ 0010859c size=140
// signature: undefined __traceiter_fastrpc_context_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_context_alloc
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014b010;
  plVar2 = _DAT_0014b010;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7993864f) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108600);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_context_free @ 0010862c size=140
// signature: undefined __traceiter_fastrpc_context_free(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_context_free
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014b058;
  plVar2 = _DAT_0014b058;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7993864f) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108690);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_perf_counters @ 001086bc size=240
// signature: undefined __traceiter_fastrpc_perf_counters(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_perf_counters
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
          undefined8 param_13)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014b0a0;
  plVar2 = _DAT_0014b0a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x228b6370) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12,param_13);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108778);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_msg @ 001087b0 size=100
// signature: undefined __traceiter_fastrpc_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_fastrpc_msg(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014b0e8;
  plVar2 = _DAT_0014b0e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xe742f40) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1087f4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_fastrpc_dspsignal @ 00108818 size=140
// signature: undefined __traceiter_fastrpc_dspsignal(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_fastrpc_dspsignal
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0014b130;
  plVar2 = _DAT_0014b130;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7a7ac272) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10887c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_transport_send @ 001088a8 size=232
// signature: undefined trace_event_raw_event_fastrpc_transport_send(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_transport_send
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x38), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x20) = param_5;
    *(undefined4 *)(lVar1 + 0x24) = param_6;
    *(undefined8 *)(lVar1 + 0x28) = param_7;
    *(undefined8 *)(lVar1 + 0x30) = param_8;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_fastrpc_transport_send @ 00108994 size=296
// signature: undefined perf_trace_fastrpc_transport_send(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_transport_send
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x3c,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined8 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x20) = param_5;
    *(undefined4 *)(lVar3 + 0x24) = param_6;
    *(undefined8 *)(lVar3 + 0x28) = param_7;
    *(undefined8 *)(lVar3 + 0x30) = param_8;
    perf_trace_run_bpf_submit(lVar3,0x3c,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_transport_response @ 00108ac0 size=216
// signature: undefined trace_event_raw_event_fastrpc_transport_response(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_transport_response
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x28), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
    *(undefined4 *)(lVar1 + 0x20) = param_6;
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
// perf_trace_fastrpc_transport_response @ 00108b9c size=280
// signature: undefined perf_trace_fastrpc_transport_response(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_transport_response
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
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
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    *(undefined4 *)(lVar3 + 0x20) = param_6;
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
// trace_event_raw_event_fastrpc_context_interrupt @ 00108cb8 size=212
// signature: undefined trace_event_raw_event_fastrpc_context_interrupt(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_context_interrupt
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x28), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x20) = param_5;
    *(undefined4 *)(lVar1 + 0x24) = param_6;
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
// perf_trace_fastrpc_context_interrupt @ 00108d90 size=276
// signature: undefined perf_trace_fastrpc_context_interrupt(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_context_interrupt
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
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
    *(undefined4 *)(lVar3 + 0x20) = param_5;
    *(undefined4 *)(lVar3 + 0x24) = param_6;
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
// trace_event_raw_event_fastrpc_context_restore @ 00108ea8 size=212
// signature: undefined trace_event_raw_event_fastrpc_context_restore(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_context_restore
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x28), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x20) = param_5;
    *(undefined4 *)(lVar1 + 0x24) = param_6;
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
// perf_trace_fastrpc_context_restore @ 00108f80 size=276
// signature: undefined perf_trace_fastrpc_context_restore(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_context_restore
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
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
    *(undefined4 *)(lVar3 + 0x20) = param_5;
    *(undefined4 *)(lVar3 + 0x24) = param_6;
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
// trace_event_raw_event_fastrpc_dma_map @ 00109098 size=232
// signature: undefined trace_event_raw_event_fastrpc_dma_map(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_dma_map
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined8 *)(lVar1 + 0x10) = param_4;
    *(undefined8 *)(lVar1 + 0x18) = param_5;
    *(undefined8 *)(lVar1 + 0x20) = param_6;
    *(undefined4 *)(lVar1 + 0x28) = param_7;
    *(undefined4 *)(lVar1 + 0x2c) = param_8;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_fastrpc_dma_map @ 00109184 size=296
// signature: undefined perf_trace_fastrpc_dma_map(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_dma_map
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined8 *)(lVar3 + 0x10) = param_4;
    *(undefined8 *)(lVar3 + 0x18) = param_5;
    *(undefined8 *)(lVar3 + 0x20) = param_6;
    *(undefined4 *)(lVar3 + 0x28) = param_7;
    *(undefined4 *)(lVar3 + 0x2c) = param_8;
    perf_trace_run_bpf_submit(lVar3,0x34,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_dma_unmap @ 001092b0 size=192
// signature: undefined trace_event_raw_event_fastrpc_dma_unmap(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_dma_unmap
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

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
    *(undefined8 *)(lVar1 + 0x18) = param_4;
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
// perf_trace_fastrpc_dma_unmap @ 00109374 size=256
// signature: undefined perf_trace_fastrpc_dma_unmap(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_dma_unmap
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

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
    *(undefined8 *)(lVar3 + 0x18) = param_4;
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
// trace_event_raw_event_fastrpc_dma_alloc @ 00109478 size=216
// signature: undefined trace_event_raw_event_fastrpc_dma_alloc(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_dma_alloc
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined8 *)(lVar1 + 0x20) = param_5;
    *(undefined4 *)(lVar1 + 0x28) = param_6;
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
// perf_trace_fastrpc_dma_alloc @ 00109554 size=280
// signature: undefined perf_trace_fastrpc_dma_alloc(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_dma_alloc
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

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
     (lVar3 = perf_trace_buf_alloc(0x34,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x28) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x34,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_dma_free @ 00109670 size=192
// signature: undefined trace_event_raw_event_fastrpc_dma_free(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_dma_free
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

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
    *(undefined8 *)(lVar1 + 0x18) = param_4;
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
// perf_trace_fastrpc_dma_free @ 00109734 size=256
// signature: undefined perf_trace_fastrpc_dma_free(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_dma_free
               (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

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
    *(undefined8 *)(lVar3 + 0x18) = param_4;
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
// trace_event_raw_event_fastrpc_context_complete @ 00109838 size=224
// signature: undefined trace_event_raw_event_fastrpc_context_complete(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_context_complete
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,undefined4 param_7)

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
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x30), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined8 *)(lVar1 + 0x20) = param_5;
    *(undefined4 *)(lVar1 + 0x28) = param_6;
    *(undefined4 *)(lVar1 + 0x2c) = param_7;
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
// perf_trace_fastrpc_context_complete @ 0010991c size=296
// signature: undefined perf_trace_fastrpc_context_complete(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_context_complete
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x34,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined8 *)(lVar3 + 0x20) = param_5;
    *(undefined4 *)(lVar3 + 0x28) = param_6;
    *(undefined4 *)(lVar3 + 0x2c) = param_7;
    perf_trace_run_bpf_submit(lVar3,0x34,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_context_alloc @ 00109a48 size=196
// signature: undefined trace_event_raw_event_fastrpc_context_alloc(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_context_alloc
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
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
// perf_trace_fastrpc_context_alloc @ 00109b10 size=268
// signature: undefined perf_trace_fastrpc_context_alloc(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_context_alloc
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_context_free @ 00109c20 size=196
// signature: undefined trace_event_raw_event_fastrpc_context_free(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_context_free
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
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
// perf_trace_fastrpc_context_free @ 00109ce8 size=268
// signature: undefined perf_trace_fastrpc_context_free(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_context_free
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_perf_counters @ 00109df8 size=268
// signature: undefined trace_event_raw_event_fastrpc_perf_counters(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_perf_counters
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x60), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined8 *)(lVar1 + 0x10) = param_4;
    *(undefined8 *)(lVar1 + 0x18) = param_5;
    *(undefined8 *)(lVar1 + 0x20) = param_6;
    *(undefined8 *)(lVar1 + 0x38) = param_9;
    *(undefined8 *)(lVar1 + 0x28) = param_7;
    *(undefined8 *)(lVar1 + 0x30) = param_8;
    *(undefined8 *)(lVar1 + 0x40) = param_10;
    *(undefined8 *)(lVar1 + 0x48) = param_11;
    *(undefined8 *)(lVar1 + 0x50) = param_12;
    *(undefined8 *)(lVar1 + 0x58) = param_13;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_fastrpc_perf_counters @ 00109f08 size=320
// signature: undefined perf_trace_fastrpc_perf_counters(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_perf_counters
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(100,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined8 *)(lVar3 + 0x10) = param_4;
    *(undefined8 *)(lVar3 + 0x18) = param_5;
    *(undefined8 *)(lVar3 + 0x20) = param_6;
    *(undefined8 *)(lVar3 + 0x28) = param_7;
    *(undefined8 *)(lVar3 + 0x30) = param_8;
    *(undefined8 *)(lVar3 + 0x38) = param_9;
    *(undefined8 *)(lVar3 + 0x40) = param_10;
    *(undefined8 *)(lVar3 + 0x48) = param_11;
    *(undefined8 *)(lVar3 + 0x50) = param_12;
    *(undefined8 *)(lVar3 + 0x58) = param_13;
    perf_trace_run_bpf_submit(lVar3,100,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_msg @ 0010a04c size=256
// signature: undefined trace_event_raw_event_fastrpc_msg(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_msg(long param_1,char *param_2)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
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
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0xc);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0xc;
      if (param_2 == (char *)0x0) {
        uVar5 = 0x296c6c;
        uVar6 = 0x6c756e28;
      }
      else {
        uVar5 = *(undefined4 *)(param_2 + 3);
        uVar6 = *(undefined4 *)param_2;
        *(undefined1 *)(lVar3 + 0x13) = 0;
      }
      *(undefined4 *)(lVar3 + 0xf) = uVar5;
      *(undefined4 *)(lVar3 + 0xc) = uVar6;
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
// perf_trace_fastrpc_msg @ 0010a150 size=336
// signature: undefined perf_trace_fastrpc_msg(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_msg(long param_1,char *param_2)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_50 = 0;
  local_54 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x14;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_50,&local_54);
    if (lVar5 != 0) {
      *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
      *(undefined1 **)(local_50 + 0xf8) = auStack_60;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_50 + 0x100) = uVar3;
      *(undefined8 *)(local_50 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x1000c;
      if (param_2 == (char *)0x0) {
        uVar6 = 0x296c6c;
        uVar7 = 0x6c756e28;
      }
      else {
        uVar6 = *(undefined4 *)(param_2 + 3);
        uVar7 = *(undefined4 *)param_2;
        *(undefined1 *)(lVar5 + 0x13) = 0;
      }
      *(undefined4 *)(lVar5 + 0xf) = uVar6;
      *(undefined4 *)(lVar5 + 0xc) = uVar7;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_54,param_1,1,local_50,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_fastrpc_dspsignal @ 0010a2a4 size=284
// signature: undefined trace_event_raw_event_fastrpc_dspsignal(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_fastrpc_dspsignal
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
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
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x18;
      if (param_2 == (char *)0x0) {
        uVar5 = 0x296c6c;
        uVar6 = 0x6c756e28;
      }
      else {
        uVar5 = *(undefined4 *)(param_2 + 3);
        uVar6 = *(undefined4 *)param_2;
        *(undefined1 *)(lVar3 + 0x1f) = 0;
      }
      *(undefined4 *)(lVar3 + 0x1b) = uVar5;
      *(undefined4 *)(lVar3 + 0x18) = uVar6;
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_fastrpc_dspsignal @ 0010a3c4 size=376
// signature: undefined perf_trace_fastrpc_dspsignal(void)
// callers: []
//------------------------------------------------------------

void perf_trace_fastrpc_dspsignal
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10018;
      if (param_2 == (char *)0x0) {
        uVar6 = 0x296c6c;
        uVar7 = 0x6c756e28;
      }
      else {
        uVar6 = *(undefined4 *)(param_2 + 3);
        uVar7 = *(undefined4 *)param_2;
        *(undefined1 *)(lVar5 + 0x1f) = 0;
      }
      *(undefined4 *)(lVar5 + 0x1b) = uVar6;
      *(undefined4 *)(lVar5 + 0x18) = uVar7;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_transport_send @ 0010a540 size=40
// signature: undefined __bpf_trace_fastrpc_transport_send(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_transport_send
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run7(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_transport_response @ 0010a56c size=44
// signature: undefined __bpf_trace_fastrpc_transport_response(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_transport_response
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_context_interrupt @ 0010a59c size=40
// signature: undefined __bpf_trace_fastrpc_context_interrupt(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_context_interrupt
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_context_restore @ 0010a5c8 size=40
// signature: undefined __bpf_trace_fastrpc_context_restore(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_context_restore
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_dma_map @ 0010a5f4 size=44
// signature: undefined __bpf_trace_fastrpc_dma_map(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_dma_map(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run7(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_dma_unmap @ 0010a624 size=32
// signature: undefined __bpf_trace_fastrpc_dma_unmap(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_dma_unmap(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run3(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_dma_alloc @ 0010a648 size=36
// signature: undefined __bpf_trace_fastrpc_dma_alloc(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_dma_alloc(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run5(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_dma_free @ 0010a670 size=32
// signature: undefined __bpf_trace_fastrpc_dma_free(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_dma_free(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run3(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_context_complete @ 0010a694 size=44
// signature: undefined __bpf_trace_fastrpc_context_complete(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_context_complete
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_context_alloc @ 0010a6c4 size=36
// signature: undefined __bpf_trace_fastrpc_context_alloc(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_context_alloc(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_context_free @ 0010a6ec size=36
// signature: undefined __bpf_trace_fastrpc_context_free(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_context_free(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_perf_counters @ 0010a714 size=68
// signature: undefined __bpf_trace_fastrpc_perf_counters(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_perf_counters(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run12(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_msg @ 0010a75c size=28
// signature: undefined __bpf_trace_fastrpc_msg(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_msg(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_fastrpc_dspsignal @ 0010a77c size=40
// signature: undefined __bpf_trace_fastrpc_dspsignal(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_fastrpc_dspsignal
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// fastrpc_internal_invoke @ 0010a7a8 size=12296
// signature: undefined fastrpc_internal_invoke(void)
// callers: [fastrpc_mmap_on_dsp, fastrpc_send_cpuinfo_to_dsp, fastrpc_create_persistent_headers, fastrpc_internal_invoke2, fastrpc_internal_mem_unmap, fastrpc_device_ioctl, fastrpc_init_create_static_process, fastrpc_get_info_from_dsp, fastrpc_dsp_restart_handler, fastrpc_internal_mem_map, fastrpc_munmap_on_dsp, fastrpc_release_current_dsp_process, compat_fastrpc_device_ioctl, fastrpc_get_info_from_kernel, fastrpc_unmap_on_dsp, fastrpc_init_attach_process, fastrpc_init_create_dynamic_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fastrpc_internal_invoke(long param_1,undefined8 param_2,int param_3,uint *param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long *plVar12;
  size_t __n;
  undefined *puVar13;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  void *pvVar17;
  ulong *puVar18;
  undefined8 uVar19;
  int iVar20;
  undefined8 *puVar21;
  long lVar22;
  long *plVar23;
  long lVar24;
  ulong *puVar25;
  ulong uVar26;
  uint uVar27;
  ulong uVar28;
  long lVar29;
  void *pvVar30;
  undefined4 *puVar31;
  ulong uVar32;
  long *plVar33;
  ulong uVar34;
  long *plVar35;
  int iVar36;
  long lVar37;
  long lVar38;
  ulong uVar39;
  ulong uVar40;
  ulong uVar41;
  ulong uVar42;
  size_t __n_00;
  ulong *puVar43;
  long lVar44;
  int *piVar45;
  long lVar46;
  size_t __n_01;
  int iVar47;
  long *plVar48;
  ulong *puVar49;
  long lVar50;
  ulong local_2f8;
  ulong local_2b0;
  long *local_278;
  long local_248;
  long lStack_240;
  undefined1 local_234 [4];
  long local_230;
  long lStack_228;
  uint local_21c;
  long local_218;
  long local_210;
  long local_a8;
  long local_a0;
  long local_98;
  long local_90;
  long local_88;
  long local_80;
  long local_78;
  long local_70;
  
  lVar29 = sp_el0;
  local_70 = *(long *)(lVar29 + 0x638);
  iVar5 = 0;
  if (param_3 != 3) {
    iVar5 = param_3;
  }
  uVar27 = *(uint *)(param_1 + 0xc0);
  local_21c = 0;
  local_230 = 0;
  lStack_228 = 0;
  local_234[0] = 0;
  if ((4 < uVar27) || (*(long *)(param_1 + 0x68) == 0)) {
    lVar29 = sp_el0;
    _printk(&DAT_0014deab,0xd48,lVar29 + 0x848,"fastrpc_internal_invoke",lVar29 + 0x848);
    uVar11 = 0;
    bVar8 = false;
    plVar48 = (long *)0x0;
    uVar41 = 0xffffffcb;
    goto LAB_0010c248;
  }
  if (*(int *)(param_1 + 0xac) != 0) {
    ktime_get_real_ts64(&local_230);
  }
  if (iVar5 != 0) {
code_r0x0010a82c:
    lVar29 = param_1 + 0x10;
    uVar11 = *(uint *)(param_1 + 0xc0);
    uVar42 = (ulong)uVar11;
    _raw_spin_lock(lVar29);
    if (((param_3 == 0 || param_3 == 3) && (0x40 < *(uint *)(param_1 + 0x48))) && (0x13 < *param_4))
    {
      _raw_spin_unlock(lVar29);
      uVar40 = 0;
      plVar12 = (long *)0x0;
      uVar41 = 0xffffff86;
    }
    else {
      _raw_spin_unlock(lVar29);
      uVar9 = param_4[1];
      lVar22 = ((ulong)uVar9 & 0xf) + (ulong)(byte)(uVar9 >> 8) + (ulong)(byte)(uVar9 >> 0x10) +
               ((ulong)(uVar9 >> 4) & 0xf);
      uVar40 = (ulong)((int)lVar22 * 0x60 + 0x170);
      plVar12 = (long *)__kmalloc(uVar40,0xdc0);
      if (plVar12 == (long *)0x0) {
        uVar40 = 0;
        uVar41 = 0xfffffff4;
      }
      else {
        plVar48 = plVar12 + 0x2e + lVar22;
        __n_01 = lVar22 * 4;
        plVar12[2] = 0;
        plVar12[3] = (long)(plVar12 + 2);
        lVar44 = (long)(plVar48 + lVar22 * 2) + __n_01;
        __n_00 = lVar22 * 0x10;
        plVar12[0x13] = param_1;
        plVar12[0xe] = lVar44;
        plVar12[0xf] = (long)(plVar12 + 0x2e);
        lVar44 = lVar44 + __n_01;
        *plVar12 = 0;
        plVar12[1] = (long)plVar12;
        plVar12[0xd] = (long)(plVar48 + lVar22 * 2);
        plVar12[10] = (long)plVar48;
        plVar12[0x15] = lVar44;
        plVar12[0x16] = lVar44 + lVar22 * 0x38;
        if (param_3 == 0) {
          uVar41 = *(ulong *)(param_4 + 2);
          __check_object_size(plVar48,__n_00,0);
          puVar21 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
             (uVar28 = uVar41, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
            uVar28 = uVar41 & (long)(uVar41 << 8) >> 8;
          }
          __n = __n_00;
          if (uVar28 <= lVar22 * -0x10 + 0x8000000000U) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar28 = daif;
              if ((uVar28 & 0x80) == 0) {
                uVar32 = daif;
                daif = uVar32 | 0xc0;
              }
              puVar21 = (undefined8 *)puVar21[1];
              uVar32 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar21 & 0xffff000000000000 | uVar32 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar21;
              InstructionSynchronizationBarrier();
              daif = uVar28;
            }
            __n = __arch_copy_from_user(puVar21,plVar48,uVar41 & 0xff7fffffffffffff,__n_00);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar41 = daif;
              if ((uVar41 & 0x80) == 0) {
                uVar28 = daif;
                daif = uVar28 | 0xc0;
              }
              uVar28 = ttbr1_el1;
              ttbr0_el1 = (uVar28 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar28 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar41;
            }
          }
          if ((__n == 0) || (memset((void *)((long)plVar48 + (__n_00 - __n)),0,__n), (int)__n == 0))
          goto LAB_0010ac00;
          lVar29 = sp_el0;
          lVar29 = lVar29 + 0x848;
          puVar13 = &DAT_0014dffb;
          uVar19 = 0x768;
LAB_0010d6e8:
          _printk(puVar13,uVar19,lVar29,"context_alloc",__n & 0xffffffff);
          uVar41 = 0xfffffff2;
        }
        else {
          memmove((void *)plVar12[10],*(void **)(param_4 + 2),__n_00);
LAB_0010ac00:
          uVar41 = *(ulong *)(param_4 + 4);
          if (uVar41 == 0) {
            plVar12[0xd] = 0;
LAB_0010ad34:
            uVar41 = *(ulong *)(param_4 + 6);
          }
          else {
            if ((param_3 == 3) || (param_3 == 0)) {
              lVar44 = plVar12[0xd];
              __check_object_size(lVar44,__n_01,0);
              puVar21 = (undefined8 *)sp_el0;
              if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
                 (uVar28 = uVar41, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
                uVar28 = uVar41 & (long)(uVar41 << 8) >> 8;
              }
              __n = __n_01;
              if (uVar28 <= lVar22 * -4 + 0x8000000000U) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar28 = daif;
                  if ((uVar28 & 0x80) == 0) {
                    uVar32 = daif;
                    daif = uVar32 | 0xc0;
                  }
                  puVar21 = (undefined8 *)puVar21[1];
                  uVar32 = ttbr1_el1;
                  ttbr1_el1 = (ulong)puVar21 & 0xffff000000000000 | uVar32 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar21;
                  InstructionSynchronizationBarrier();
                  daif = uVar28;
                }
                __n = __arch_copy_from_user(puVar21,lVar44,uVar41 & 0xff7fffffffffffff,__n_01);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar41 = daif;
                  if ((uVar41 & 0x80) == 0) {
                    uVar28 = daif;
                    daif = uVar28 | 0xc0;
                  }
                  uVar28 = ttbr1_el1;
                  ttbr0_el1 = (uVar28 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar28 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar41;
                }
              }
              if ((__n != 0) && (memset((void *)(lVar44 + (__n_01 - __n)),0,__n), (int)__n != 0)) {
                lVar29 = sp_el0;
                lVar29 = lVar29 + 0x848;
                puVar13 = &DAT_0014f172;
                uVar19 = 0x773;
                goto LAB_0010d6e8;
              }
              goto LAB_0010ad34;
            }
            memmove((void *)plVar12[0xd],*(void **)(param_4 + 4),__n_01);
            uVar41 = *(ulong *)(param_4 + 6);
          }
          if (uVar41 != 0) {
            if ((param_3 == 3) || (param_3 == 0)) {
              lVar44 = plVar12[0xe];
              __check_object_size(lVar44,__n_01,0);
              puVar21 = (undefined8 *)sp_el0;
              if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
                 (uVar28 = uVar41, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
                uVar28 = uVar41 & (long)(uVar41 << 8) >> 8;
              }
              __n = __n_01;
              if (uVar28 <= lVar22 * -4 + 0x8000000000U) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar28 = daif;
                  if ((uVar28 & 0x80) == 0) {
                    uVar32 = daif;
                    daif = uVar32 | 0xc0;
                  }
                  puVar21 = (undefined8 *)puVar21[1];
                  uVar32 = ttbr1_el1;
                  ttbr1_el1 = (ulong)puVar21 & 0xffff000000000000 | uVar32 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar21;
                  InstructionSynchronizationBarrier();
                  daif = uVar28;
                }
                __n = __arch_copy_from_user(puVar21,lVar44,uVar41 & 0xff7fffffffffffff,__n_01);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar41 = daif;
                  if ((uVar41 & 0x80) == 0) {
                    uVar28 = daif;
                    daif = uVar28 | 0xc0;
                  }
                  uVar28 = ttbr1_el1;
                  ttbr0_el1 = (uVar28 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar28 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar41;
                }
              }
              if ((__n != 0) && (memset((void *)(lVar44 + (__n_01 - __n)),0,__n), (int)__n != 0)) {
                lVar29 = sp_el0;
                lVar29 = lVar29 + 0x848;
                puVar13 = &DAT_0014e5b3;
                uVar19 = 0x780;
                goto LAB_0010d6e8;
              }
            }
            else {
              memmove((void *)plVar12[0xe],*(void **)(param_4 + 6),__n_01);
            }
          }
          lVar44 = *(long *)(param_4 + 0xc);
          lVar38 = *(long *)(param_4 + 8);
          plVar12[0x1d] = *(long *)(param_4 + 10);
          plVar12[0x1e] = lVar44;
          uVar9 = *param_4;
          uVar10 = param_4[1];
          plVar12[0x1c] = lVar38;
          *(uint *)(plVar12 + 0x14) = uVar9;
          *(uint *)((long)plVar12 + 0xa4) = uVar10;
          if ((int)lVar22 != 0) {
            uVar41 = (ulong)(uVar10 >> 0x10) & 0xff;
            lVar22 = uVar41 + (byte)(uVar10 >> 8);
            if ((int)lVar22 == 0) {
              sort(plVar12[0x16],0,8,overlap_ptr_cmp,0);
            }
            else {
              lVar44 = 0;
              lVar38 = 0;
              plVar48 = (long *)(plVar12[10] + 8);
              do {
                *(long *)(plVar12[0x15] + lVar44) = plVar48[-1];
                ((long *)(plVar12[0x15] + lVar44))[1] = *plVar48 + *(long *)(plVar12[0x15] + lVar44)
                ;
                if ((*plVar48 != 0) &&
                   (puVar25 = (ulong *)(plVar12[0x15] + lVar44), puVar25[1] <= *puVar25)) {
                  lVar29 = sp_el0;
                  _printk(&DAT_0014f1bc,0x6f9,lVar29 + 0x848,"context_build_overlap",plVar48[-1]);
                  uVar41 = 0xfffffff2;
                  goto LAB_0010b32c;
                }
                plVar48 = plVar48 + 2;
                *(int *)(plVar12[0x15] + lVar44 + 0x10) = (int)lVar38;
                lVar50 = plVar12[0x15] + lVar44;
                lVar44 = lVar44 + 0x38;
                *(long *)(plVar12[0x16] + lVar38 * 8) = lVar50;
                lVar38 = lVar38 + 1;
              } while (lVar22 * 0x38 != lVar44);
              sort(plVar12[0x16],lVar22,8,overlap_ptr_cmp,0);
              lVar44 = 0;
              iVar47 = 0;
              uVar28 = 0;
              do {
                puVar25 = *(ulong **)(plVar12[0x16] + lVar44);
                if (*puVar25 < uVar28) {
                  puVar25[3] = uVar28;
                  *(undefined8 *)(*(long *)(plVar12[0x16] + lVar44) + 0x20) =
                       *(undefined8 *)(*(long *)(plVar12[0x16] + lVar44) + 8);
                  (*(long **)(plVar12[0x16] + lVar44))[5] =
                       uVar28 - **(long **)(plVar12[0x16] + lVar44);
                  lVar38 = *(long *)(plVar12[0x16] + lVar44);
                  if (uVar28 < *(ulong *)(lVar38 + 8)) {
                    uVar28 = *(ulong *)(lVar38 + 8);
                  }
                  else {
                    iVar36 = (int)uVar41;
                    if (((iVar47 < iVar36) && (iVar36 < *(int *)(lVar38 + 0x10) + 1)) ||
                       ((*(int *)(lVar38 + 0x10) < iVar36 && (iVar36 < iVar47 + 1)))) {
                      *(undefined4 *)(lVar38 + 0x30) = 1;
                      lVar38 = *(long *)(plVar12[0x16] + lVar44);
                    }
                    *(undefined8 *)(lVar38 + 0x20) = 0;
                    *(undefined8 *)(*(long *)(plVar12[0x16] + lVar44) + 0x18) = 0;
                  }
                }
                else {
                  puVar25[4] = puVar25[1];
                  (*(undefined8 **)(plVar12[0x16] + lVar44))[3] =
                       **(undefined8 **)(plVar12[0x16] + lVar44);
                  *(undefined8 *)(*(long *)(plVar12[0x16] + lVar44) + 0x28) = 0;
                  uVar28 = *(ulong *)(*(long *)(plVar12[0x16] + lVar44) + 8);
                  iVar47 = *(int *)(*(long *)(plVar12[0x16] + lVar44) + 0x10);
                }
                lVar44 = lVar44 + 8;
              } while (lVar22 * 8 != lVar44);
            }
          }
          puVar21 = (undefined8 *)sp_el0;
          uVar6 = *(undefined4 *)(param_1 + 0xb8);
          *(undefined4 *)(plVar12 + 8) = 0xffffffff;
          uVar3 = *(undefined4 *)(puVar21 + 0xc6);
          *(undefined4 *)(plVar12 + 4) = 0;
          *(undefined4 *)((long)plVar12 + 0x44) = uVar3;
          *(undefined4 *)(plVar12 + 9) = uVar6;
          __init_swait_queue_head(plVar12 + 5,"&x->wait",&init_completion___key);
          *(undefined4 *)(plVar12 + 0x22) = 0;
          *(undefined1 *)(plVar12 + 0x23) = 0;
          plVar12[0x11] = 0;
          *(undefined4 *)(plVar12 + 0x1f) = 0xbeeddeed;
          *(undefined1 *)(plVar12 + 0x27) = 0;
          *(undefined1 *)((long)plVar12 + 0x16c) = 0;
          if (*(int *)(plVar12[0x13] + 0xac) != 0) {
            puVar14 = (undefined8 *)kmalloc_trace(_down_read,0xdc0,0x50);
            plVar12[0x21] = (long)puVar14;
            if ((puVar14 == (undefined8 *)0x0) || ((undefined8 *)0xfffffffffffff000 < puVar14)) {
              kfree();
              uVar41 = 0xfffffff4;
              goto LAB_0010b32c;
            }
            iVar47 = *(int *)(param_1 + 0xb8);
            puVar14[6] = 0;
            puVar14[7] = 0;
            puVar14[4] = 0;
            puVar14[5] = 0;
            puVar14[2] = 0;
            puVar14[3] = 0;
            *puVar14 = 0;
            puVar14[1] = 0;
            puVar14[8] = 0;
            puVar14[9] = (long)iVar47;
          }
          plVar48 = *(long **)(param_4 + 0xe);
          if (plVar48 != (long *)0x0) {
            if ((param_3 == 3) || (param_3 == 0)) {
              if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
                 (plVar23 = plVar48, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
                plVar23 = (long *)((ulong)plVar48 & ((long)plVar48 << 8) >> 8);
              }
              if (plVar23 < (long *)0x7fffffffe9) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar41 = daif;
                  if ((uVar41 & 0x80) == 0) {
                    uVar28 = daif;
                    daif = uVar28 | 0xc0;
                  }
                  uVar28 = ttbr1_el1;
                  ttbr1_el1 = puVar21[1] & 0xffff000000000000 | uVar28 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar21[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar41;
                }
                uVar41 = __arch_copy_from_user
                                   (plVar12 + 0x24,(ulong)plVar48 & 0xff7fffffffffffff,0x18);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar28 = daif;
                  if ((uVar28 & 0x80) == 0) {
                    uVar32 = daif;
                    daif = uVar32 | 0xc0;
                  }
                  uVar32 = ttbr1_el1;
                  ttbr0_el1 = (uVar32 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar32 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar28;
                }
                if (uVar41 == 0) goto LAB_0010b2b8;
              }
              else {
                uVar41 = 0x18;
              }
              memset((void *)((long)(plVar12 + 0x24) + (0x18 - uVar41)),0,uVar41);
              if ((int)uVar41 != 0) goto LAB_0010b32c;
            }
            else {
              lVar22 = plVar48[2];
              lVar44 = *plVar48;
              plVar12[0x25] = plVar48[1];
              plVar12[0x26] = lVar22;
              plVar12[0x24] = lVar44;
            }
          }
LAB_0010b2b8:
          lVar22 = gfa;
          if (uVar11 < 5) {
            lVar44 = gfa + uVar42 * 0x6a68 + 0x2e40;
            uVar19 = _raw_spin_lock_irqsave(lVar44);
            plVar48 = &DAT_001505f0 + uVar42;
            *plVar48 = *plVar48 + 1;
            if ((param_3 == 3) || (param_3 == 0)) {
              lVar38 = 0;
              if (0x13 < *(uint *)(plVar12 + 0x14)) {
                lVar38 = 0x46;
              }
            }
            else {
              lVar38 = 0;
            }
            uVar41 = lVar38 << 6;
            do {
              if (*(long *)(lVar22 + uVar42 * 0x6a68 + 0xe40 + lVar38 * 8) == 0) {
                *(long **)(lVar22 + uVar42 * 0x6a68 + lVar38 * 8 + 0xe40) = plVar12;
                if (0x16 < uVar11) goto LAB_0010d724;
                plVar12[0x20] =
                     uVar41 & 0xffffffc0 | *plVar48 << 0x10 | (ulong)((int)plVar12[0x24] != 0) << 4;
                _raw_spin_unlock_irqrestore(lVar44,uVar19);
                InstructionSynchronizationBarrier();
                lVar22 = cntvct_el0;
                plVar12[0x2a] = (ulong)(lVar22 * 10) / 0xc0;
                _raw_spin_lock(lVar29);
                lVar22 = *(long *)(param_1 + 0x38);
                *plVar12 = lVar22;
                if (lVar22 != 0) {
                  *(long **)(lVar22 + 8) = plVar12;
                }
                *(long **)(param_1 + 0x38) = plVar12;
                plVar12[1] = param_1 + 0x38;
                *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
                _raw_spin_unlock(lVar29);
                uVar41 = 0;
                goto code_r0x0010b46c;
              }
              lVar38 = lVar38 + 1;
              uVar41 = uVar41 + 0x40;
            } while (lVar38 != 0x400);
            _raw_spin_unlock_irqrestore(lVar44,uVar19);
            _printk(&DAT_0014d3da,1999,puVar21 + 0x109,"context_alloc",(int)plVar12[0x14],
                    *(undefined4 *)((long)plVar12 + 0xa4));
            uVar41 = 0xffffff82;
          }
          else {
            uVar41 = 0xffffffd4;
          }
        }
LAB_0010b32c:
        context_free(plVar12);
        uVar40 = 0;
        plVar12 = (long *)0x0;
      }
    }
code_r0x0010b46c:
    if ((int)uVar41 == 0) {
      if (*(long *)(param_1 + 0xd8) != 0) {
        uVar9 = fastrpc_check_pd_status(param_1,"audio_pdr_adsprpc");
        uVar10 = fastrpc_check_pd_status(param_1,"sensors_pdr_adsprpc");
        uVar11 = fastrpc_check_pd_status(param_1,"sensors_pdr_sdsprpc");
        uVar11 = uVar10 | uVar9 | uVar11;
        uVar41 = (ulong)uVar11;
        if (uVar11 != 0) goto LAB_0010b470;
      }
      if ((uVar40 < 0x120) || (uVar40 == 0x120)) goto LAB_0010d724;
      lVar29 = plVar12[0x24];
      bVar8 = (int)lVar29 != 0;
      if (*(int *)(param_1 + 0xac) == 0) {
        plVar48 = (long *)0x0;
      }
      else {
        if ((uVar40 < 0x108) || (uVar40 == 0x108)) goto LAB_0010d724;
        plVar48 = (long *)plVar12[0x21];
      }
      plVar23 = (long *)0x0;
      if (plVar48 != (long *)0x0) {
        plVar23 = plVar48 + 5;
      }
      local_248 = 0;
      lStack_240 = 0;
      if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
        ktime_get_real_ts64(&local_248);
      }
      if ((((uVar40 < 0x50) || (uVar40 == 0x50)) || (uVar40 < 0xa4)) ||
         ((uVar40 == 0xa4 || (uVar40 == 0x98)))) goto LAB_0010d724;
      lVar22 = plVar12[10];
      uVar11 = *(uint *)((long)plVar12 + 0xa4);
      if (*(int *)(plVar12[0x13] + 0xac) == 0) {
        lVar44 = 0;
      }
      else {
        if ((uVar40 < 0x108) || (uVar40 == 0x108)) goto LAB_0010d724;
        lVar44 = plVar12[0x21];
      }
      uVar32 = (ulong)(uVar11 >> 0x10) & 0xff;
      uVar42 = uVar32 + (byte)(uVar11 >> 8);
      lVar38 = ((ulong)(uVar11 >> 4) & 0xf) + ((ulong)uVar11 & 0xf);
      uVar28 = lVar38 + uVar42;
      plVar33 = (long *)0x0;
      if (lVar44 != 0) {
        plVar33 = (long *)(lVar44 + 0x10);
      }
      local_80 = 0;
      local_78 = 0;
      if ((*(int *)(plVar12[0x13] + 0xac) != 0) && (plVar33 != (long *)0x0)) {
        ktime_get_real_ts64(&local_80);
      }
      uVar9 = (uint)uVar42;
      if (uVar9 == 0) {
        local_2b0 = uVar28 * 0x18;
      }
      else {
        lVar37 = 0;
        lVar50 = 0;
        local_2b0 = uVar28 * 0x18 + uVar42 * 0x10;
        puVar21 = (undefined8 *)(lVar22 + 8);
        do {
          if (uVar40 < 0x99) goto LAB_0010d724;
          uVar19 = puVar21[-1];
          uVar1 = *puVar21;
          mutex_lock(plVar12[0x13] + 0x110);
          if (uVar40 == 0x68) goto LAB_0010d724;
          if ((plVar12[0xd] == 0) || (iVar47 = *(int *)(plVar12[0xd] + lVar50), iVar47 == -1)) {
            uVar41 = 0;
          }
          else {
            if ((uVar40 == 0x70) || (uVar40 < 0x79)) goto LAB_0010d724;
            uVar41 = fastrpc_mmap_create(plVar12[0x13],iVar47,0,
                                         *(undefined4 *)(plVar12[0xe] + lVar50),uVar19,uVar1,0,
                                         plVar12[0xf] + lVar37);
            uVar41 = uVar41 & 0xffffffff;
          }
          if (uVar40 < 0x79) goto LAB_0010d724;
          lVar24 = *(long *)(plVar12[0xf] + lVar37);
          if (lVar24 != 0) {
            *(int *)(lVar24 + 200) = *(int *)(lVar24 + 200) + 1;
          }
          mutex_unlock(plVar12[0x13] + 0x110);
          if ((int)uVar41 != 0) goto LAB_0010ce78;
          lVar50 = lVar50 + 4;
          lVar37 = lVar37 + 8;
          puVar21 = puVar21 + 2;
        } while (uVar42 * 4 != lVar50);
      }
      if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
      lVar50 = plVar12[0x13];
      if ((*(int *)(lVar50 + 0xac) != 0) && (plVar33 != (long *)0x0)) {
        local_a8 = 0;
        local_a0 = 0;
        ktime_get_real_ts64(&local_a8);
        local_218 = 0;
        local_210 = 0;
        set_normalized_timespec64(&local_218,local_a8 - local_80,local_a0 - local_78);
        if (local_218 < 0x225c17d04) {
          if (local_218 < -0x225c17d03) {
            lVar50 = -0x8000000000000000;
          }
          else {
            lVar50 = local_210 + local_218 * 1000000000;
          }
        }
        else {
          lVar50 = 0x7fffffffffffffff;
        }
        *plVar33 = *plVar33 + lVar50;
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        lVar50 = plVar12[0x13];
      }
      mutex_lock(lVar50 + 0x110);
      iVar47 = (int)lVar38;
      if (iVar47 != 0) {
        lVar38 = 0;
        uVar16 = uVar42;
        do {
          if (uVar40 < 0x71) goto LAB_0010d724;
          if (plVar12[0xe] == 0) {
            uVar10 = 0;
          }
          else {
            uVar10 = *(uint *)(plVar12[0xe] + uVar16 * 4) & 0x10;
          }
          if (uVar40 < 0x99) goto LAB_0010d724;
          lVar50 = plVar12[0x13];
          uVar4 = *(uint *)(lVar50 + 0xc0);
          if (4 < uVar4) {
            mutex_unlock(lVar50 + 0x110);
            uVar41 = 0xffffffd4;
            goto LAB_0010ce78;
          }
          if (0x207d8 < (ulong)uVar4 * 0x6a68) goto LAB_0010d724;
          if (*(int *)(&DAT_00129fa8 + (ulong)uVar4 * 0x6a68) == 0) {
            if (uVar40 < 0x69) goto LAB_0010d724;
            if ((plVar12[0xd] != 0) && (iVar36 = *(int *)(plVar12[0xd] + uVar16 * 4), iVar36 != -1))
            {
              if (uVar40 < 0x79) goto LAB_0010d724;
              uVar41 = fastrpc_mmap_create(lVar50,iVar36,0,1,0,0,uVar10,plVar12[0xf] + uVar16 * 8);
              if ((int)uVar41 != 0) {
                if ((uint)uVar16 <= uVar9) goto LAB_0010c394;
                lVar22 = uVar42 * 8;
                goto LAB_0010bdbc;
              }
            }
          }
          if (uVar40 < 0x79) goto LAB_0010d724;
          lVar50 = *(long *)(plVar12[0xf] + uVar16 * 8);
          if (lVar50 != 0) {
            *(int *)(lVar50 + 0xcc) = *(int *)(lVar50 + 0xcc) + 1;
          }
          local_2b0 = local_2b0 + 0x10;
          uVar16 = uVar16 + 1;
          lVar38 = lVar38 + 1;
        } while (uVar16 < uVar28);
      }
      if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
      mutex_unlock(plVar12[0x13] + 0x110);
      uVar16 = local_2b0 + 0x1e4;
      if (uVar16 == 0) {
LAB_0010bd50:
        if ((uVar40 < 0x90) || (uVar40 == 0x90)) goto LAB_0010d724;
        plVar12[0x12] = uVar16;
        if (uVar28 == 0) {
          uVar15 = 0;
        }
        else {
          uVar15 = __kmalloc(uVar28 * 0x10,0xdc0);
          uVar41 = 0xfffffff4;
          if ((uVar15 == 0) || (0xfffffffffffff000 < uVar15)) goto LAB_0010ce78;
        }
        if ((uVar40 < 0x60) || (uVar40 == 0x60)) goto LAB_0010d724;
        plVar12[0xc] = uVar15;
        if (uVar9 == 0) {
          uVar15 = 0;
        }
        else {
          lVar38 = 0;
          uVar15 = 0;
          lVar50 = sp_el0;
          do {
            if (uVar40 < 0xb1) goto LAB_0010d724;
            lVar37 = *(long *)(plVar12[0x16] + lVar38);
            if (*(long *)(lVar22 + (long)*(int *)(lVar37 + 0x10) * 0x10 + 8) != 0) {
              if (uVar40 < 0x79) goto LAB_0010d724;
              if (*(long *)(plVar12[0xf] + (long)*(int *)(lVar37 + 0x10) * 8) == 0) {
                uVar41 = 0xfffffff2;
                uVar39 = uVar15 + 0x7f & 0xffffffffffffff80;
                if (*(long *)(lVar37 + 0x28) != 0) {
                  uVar39 = uVar15;
                }
                uVar15 = *(long *)(lVar37 + 0x20) - *(long *)(lVar37 + 0x18);
                if (((long)uVar15 < 0) || ((uVar15 ^ 0x7fffffffffffffff) < uVar39))
                goto LAB_0010ce78;
                if (0x80000 < uVar15) {
                  if (uVar40 < 0xa1) goto LAB_0010d724;
                  _printk(&DAT_0014fc71,0xa1d,lVar50 + 0x848,"get_args",uVar15,
                          *(long *)(lVar37 + 0x20),*(long *)(lVar37 + 0x18),(ulong)uVar11);
                }
                uVar15 = uVar15 + uVar39;
              }
            }
            lVar38 = lVar38 + 8;
          } while (uVar42 * 8 != lVar38);
        }
        local_2f8 = uVar15 + (local_2b0 + 0x263 & 0xffffffffffffff80);
        uVar41 = (uVar16 & 0xffffffff) + 0xfff & 0x1fffff000;
        if (uVar41 < 0x1001) {
          uVar41 = 0x1000;
        }
        if (uVar41 < local_2f8) {
          if (uVar15 == 0) {
            uVar41 = 0;
          }
          else {
            if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
            plVar35 = plVar12 + 0x11;
            uVar16 = fastrpc_buf_alloc(plVar12[0x13],uVar15,0,0,1,plVar35);
            uVar41 = uVar16 & 0xffffffff;
            if ((int)uVar16 != 0) goto LAB_0010ce78;
            if ((((uVar40 < 0x88) || (uVar40 == 0x88)) || (uVar40 == 0x88)) ||
               (memset(*(void **)(*plVar35 + 0x38),0,uVar15), uVar40 == 0x88)) goto LAB_0010d724;
            uVar41 = *(ulong *)(*plVar35 + 0x38);
            local_2f8 = uVar15;
          }
        }
        else {
          if (((uVar40 < 0x80) || (uVar40 == 0x80)) || ((uVar40 < 0x88 || (uVar40 == 0x88))))
          goto LAB_0010d724;
          lVar38 = *(long *)(plVar12[0x10] + 0x38);
          plVar12[0x11] = plVar12[0x10];
          uVar41 = uVar16 + lVar38;
          uVar15 = local_2f8 - uVar16;
        }
        if (((uVar40 < 0x80) || (uVar40 == 0x80)) || (uVar40 == 0x58)) goto LAB_0010d724;
        puVar25 = *(ulong **)(plVar12[0x10] + 0x38);
        plVar12[0xb] = (long)puVar25;
        if ((int)uVar28 != 0) {
          uVar16 = 0;
          puVar31 = (undefined4 *)((long)puVar25 + uVar28 * 0x10 + 4);
          plVar35 = (long *)(lVar22 + 8);
          do {
            lVar38 = *plVar35;
            *puVar31 = (int)uVar16;
            uVar16 = uVar16 + 1;
            puVar31[-1] = (uint)(lVar38 != 0);
            puVar31 = puVar31 + 2;
            plVar35 = plVar35 + 2;
          } while (uVar28 != uVar16);
        }
        local_218 = 0;
        local_210 = 0;
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        if ((*(int *)(plVar12[0x13] + 0xac) != 0) && (plVar33 != (long *)0x0)) {
          ktime_get_real_ts64(&local_218);
        }
        if (puVar25 != (ulong *)0x0 && uVar9 != 0) {
          uVar16 = 0;
          lVar38 = sp_el0;
          piVar45 = (int *)((long)puVar25 + uVar28 * 0x10 + 4);
          puVar43 = (ulong *)(lVar22 + 8);
          puVar49 = puVar25;
          do {
            if (uVar40 < 0x79) goto LAB_0010d724;
            uVar39 = puVar43[-1];
            uVar26 = *puVar43;
            lVar50 = *(long *)(plVar12[0xf] + uVar16 * 8);
            *puVar49 = 0;
            puVar49[1] = uVar26;
            if (uVar26 != 0) {
              if (lVar50 != 0) {
                uVar34 = uVar39 & 0xfffffffffffff000;
                iVar36 = *piVar45;
                if ((*(byte *)(lVar50 + 0x88) & 1) == 0) {
                  down_read(*(long *)(lVar38 + 0x5a0) + 0x60);
                  puVar18 = (ulong *)find_vma(*(undefined8 *)(lVar38 + 0x5a0),
                                              *(undefined8 *)(lVar50 + 0x58));
                  if (puVar18 == (ulong *)0x0) goto LAB_0010d5d4;
                  lVar37 = uVar34 - *puVar18;
                  if (uVar34 < *puVar18) {
                    up_read(*(long *)(lVar38 + 0x5a0) + 0x60);
                    _printk(&DAT_0014d439,0xa65,lVar38 + 0x848,"get_args",
                            *(undefined4 *)(lVar50 + 0x20),*(undefined8 *)(lVar50 + 0x48),
                            *(undefined8 *)(lVar50 + 0x58),*puVar18);
                    uVar41 = 0xfffffff2;
                    goto LAB_0010ce78;
                  }
                  up_read(*(long *)(lVar38 + 0x5a0) + 0x60);
                  if (*(ulong *)(lVar50 + 0x50) < lVar37 + uVar26) {
                    _printk(&DAT_0014ef95,0xa70,lVar38 + 0x848,"get_args",uVar16 & 0xffffffff,
                            puVar43[-1],*puVar43);
                    uVar41 = 0xfffffff2;
                    goto LAB_0010ce78;
                  }
                }
                else {
                  lVar37 = 0;
                }
                puVar25[uVar28 * 3 + (long)iVar36 * 2] = *(long *)(lVar50 + 0x48) + lVar37;
                (puVar25 + uVar28 * 3 + (long)iVar36 * 2)[1] =
                     ((uVar39 + uVar26) - uVar34) + 0xfff & 0xfffffffffffff000;
              }
              *puVar49 = uVar39;
            }
            uVar16 = uVar16 + 1;
            piVar45 = piVar45 + 2;
            puVar49 = puVar49 + 2;
            puVar43 = puVar43 + 2;
          } while (uVar42 != uVar16);
        }
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        lVar38 = plVar12[0x13];
        if ((*(int *)(lVar38 + 0xac) != 0) && (plVar33 != (long *)0x0)) {
          lVar38 = getnstimediff(&local_218);
          *plVar33 = *plVar33 + lVar38;
          if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
          lVar38 = plVar12[0x13];
        }
        mutex_lock(lVar38 + 0x110);
        if (iVar47 != 0) {
          uVar16 = uVar42;
          do {
            if (uVar40 < 0x79) goto LAB_0010d724;
            if (*(long *)(plVar12[0xf] + uVar16 * 8) != 0) {
              if ((uVar40 < 0x99) || (uVar40 == 0x68)) goto LAB_0010d724;
              plVar33 = *(long **)(plVar12[0x13] + 0x18);
              if (plVar33 == (long *)0x0) {
LAB_0010cab4:
                mutex_unlock(plVar12[0x13] + 0x110);
                if ((uVar40 < 0x68) || (uVar40 == 0x68)) goto LAB_0010d724;
                lVar22 = sp_el0;
                _printk(&DAT_0014e801,0xa90,lVar22 + 0x848,"get_args",
                        *(undefined4 *)(plVar12[0xd] + uVar16 * 4));
                goto LAB_0010ce74;
              }
              while ((plVar35 = (long *)*plVar33, plVar33[0xb] != 0 ||
                     ((int)plVar33[4] != *(int *)(plVar12[0xd] + uVar16 * 4)))) {
                plVar33 = plVar35;
                if (plVar35 == (long *)0x0) goto LAB_0010cab4;
              }
              puVar25[uVar28 * 3 + uVar16 * 2] = plVar33[9];
              (puVar25 + uVar28 * 3 + uVar16 * 2)[1] = plVar33[10];
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < uVar28);
        }
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        mutex_unlock(plVar12[0x13] + 0x110);
        memset(puVar25 + uVar28 * 5,0,0x1e4);
        plVar33 = (long *)0x0;
        if (lVar44 != 0) {
          plVar33 = (long *)(lVar44 + 0x18);
        }
        local_218 = 0;
        local_210 = 0;
        if (uVar40 == 0x98) goto LAB_0010d724;
        if ((*(int *)(plVar12[0x13] + 0xac) != 0) && (plVar33 != (long *)0x0)) {
          ktime_get_real_ts64(&local_218);
        }
        iVar36 = (int)uVar32;
        if (puVar25 != (ulong *)0x0 && uVar9 != 0) {
          lVar38 = 0;
          puVar21 = (undefined8 *)sp_el0;
          do {
            if (uVar40 < 0xb1) goto LAB_0010d724;
            lVar50 = *(long *)(plVar12[0x16] + lVar38);
            iVar20 = *(int *)(lVar50 + 0x10);
            lVar37 = (long)iVar20;
            puVar43 = (ulong *)(lVar22 + lVar37 * 0x10);
            uVar32 = puVar43[1];
            if (uVar32 != 0) {
              if (uVar40 < 0x79) goto LAB_0010d724;
              if (*(long *)(plVar12[0xf] + lVar37 * 8) == 0) {
                uVar16 = uVar41 + 0x7f & 0xffffffffffffff80;
                lVar24 = uVar41 - uVar16;
                uVar39 = *(long *)(lVar50 + 0x20) - *(long *)(lVar50 + 0x18);
                if (*(long *)(lVar50 + 0x28) != 0) {
                  lVar24 = 0;
                  uVar16 = uVar41;
                }
                uVar41 = lVar24 + uVar15;
                uVar15 = uVar41 - uVar39;
                if (uVar41 < uVar39) {
LAB_0010d75c:
                  uVar41 = 0xfffffff2;
                  goto LAB_0010ce78;
                }
                puVar25[lVar37 * 2] = uVar16 - *(long *)(lVar50 + 0x28);
                if (uVar40 < 0x89) goto LAB_0010d724;
                lVar50 = lVar37 * 8 + uVar28 * 0x10;
                puVar25[uVar28 * 3 + (long)*(int *)((long)puVar25 + lVar50 + 4) * 2] =
                     ((local_2f8 + *(long *)(plVar12[0x11] + 0x40)) -
                     *(long *)(*(long *)(plVar12[0x16] + lVar38) + 0x28)) - uVar41;
                lVar24 = (long)*(int *)((long)puVar25 + lVar50 + 4);
                puVar25[uVar28 * 3 + lVar24 * 2] =
                     puVar25[uVar28 * 3 + lVar24 * 2] & 0xfffffffffffff000;
                pvVar17 = (void *)puVar25[lVar37 * 2];
                puVar25[uVar28 * 3 + (long)*(int *)((long)puVar25 + lVar50 + 4) * 2 + 1] =
                     (long)pvVar17 + (uVar32 - ((ulong)pvVar17 & 0xfffffffffffff000)) + 0xfff &
                     0xfffffffffffff000;
                if (iVar20 < iVar36) {
                  if (iVar5 == 0) {
                    if (uVar32 >> 0x1f != 0) {
                    /* WARNING: Does not return */
                      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10ca44);
                      (*pcVar7)();
                    }
                    uVar41 = *puVar43;
                    __check_object_size(pvVar17,uVar32,0);
                    if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
                       (uVar26 = uVar41, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
                      uVar26 = uVar41 & (long)(uVar41 << 8) >> 8;
                    }
                    uVar34 = uVar32;
                    if (uVar26 <= 0x8000000000 - uVar32) {
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar26 = daif;
                        if ((uVar26 & 0x80) == 0) {
                          uVar34 = daif;
                          daif = uVar34 | 0xc0;
                        }
                        uVar34 = ttbr1_el1;
                        ttbr1_el1 = puVar21[1] & 0xffff000000000000 | uVar34 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        ttbr0_el1 = puVar21[1];
                        InstructionSynchronizationBarrier();
                        daif = uVar26;
                      }
                      uVar34 = __arch_copy_from_user(pvVar17,uVar41 & 0xff7fffffffffffff,uVar32);
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar41 = daif;
                        if ((uVar41 & 0x80) == 0) {
                          uVar26 = daif;
                          daif = uVar26 | 0xc0;
                        }
                        uVar26 = ttbr1_el1;
                        ttbr0_el1 = (uVar26 & 0xffffffffffff) - 0x1000;
                        InstructionSynchronizationBarrier();
                        ttbr1_el1 = uVar26 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        daif = uVar41;
                      }
                      if (uVar34 == 0) goto LAB_0010c7f8;
                    }
                    memset((void *)((long)pvVar17 + (uVar32 - uVar34)),0,uVar34);
                    if ((int)uVar34 != 0) {
                      lVar22 = sp_el0;
                      _printk(&DAT_0014f004,0xac3,lVar22 + 0x848,"get_args",uVar34,pvVar17,*puVar43,
                              uVar32);
                      goto LAB_0010d75c;
                    }
                  }
                  else {
                    memmove(pvVar17,(void *)*puVar43,uVar32);
                  }
                }
LAB_0010c7f8:
                uVar41 = uVar39 + uVar16;
              }
            }
            lVar38 = lVar38 + 8;
          } while (uVar42 * 8 != lVar38);
        }
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        iVar20 = *(int *)(plVar12[0x13] + 0xac);
        if ((iVar20 != 0) && (plVar33 != (long *)0x0)) {
          lVar38 = getnstimediff(&local_218);
          *plVar33 = *plVar33 + lVar38;
          if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
          iVar20 = *(int *)(plVar12[0x13] + 0xac);
        }
        plVar33 = (long *)0x0;
        if (lVar44 != 0) {
          plVar33 = (long *)(lVar44 + 8);
        }
        local_218 = 0;
        local_210 = 0;
        if ((iVar20 != 0) && (plVar33 != (long *)0x0)) {
          ktime_get_real_ts64(&local_218);
        }
        if (uVar9 != 0) {
          lVar44 = 0;
          lVar38 = sp_el0;
          do {
            if ((uVar40 < 0xb1) || (uVar40 == 0x78)) goto LAB_0010d724;
            lVar50 = *(long *)(plVar12[0x16] + lVar44);
            iVar20 = *(int *)(lVar50 + 0x10);
            if (iVar20 + 1 <= iVar36) {
              if (uVar40 < 0x99) goto LAB_0010d724;
              lVar37 = *(long *)(plVar12[0xf] + (long)iVar20 * 8);
              if ((((*(long *)(plVar12[0x13] + 0x68) == 0) ||
                   (*(int *)(*(long *)(plVar12[0x13] + 0x68) + 0x28) == 0)) &&
                  ((lVar37 == 0 || ((*(byte *)(lVar37 + 0x88) >> 5 & 1) == 0)))) &&
                 ((puVar25 != (ulong *)0x0 &&
                  (puVar43 = puVar25 + (long)iVar20 * 2, puVar43[1] != 0)))) {
                if (*(long *)(lVar50 + 0x18) == 0) {
                  if ((lVar37 != 0) && (*(int *)(lVar50 + 0x30) == 1)) goto LAB_0010cc74;
                }
                else if (lVar37 != 0) {
LAB_0010cc74:
                  if (*(long *)(lVar37 + 0x28) != 0) {
                    uVar41 = (ulong)(uint)(*(int *)(lVar50 + 0x20) - (int)*(long *)(lVar50 + 0x18))
                             + 0xfff & 0x1fffff000;
                    if (uVar41 < 0x1001) {
                      uVar41 = 0x1000;
                    }
                    if ((uVar41 == *(ulong *)(lVar37 + 0x50)) || (*(int *)(lVar50 + 0x30) != 0)) {
                      dma_buf_begin_cpu_access(*(long *)(lVar37 + 0x28),1);
                      dma_buf_end_cpu_access(*(undefined8 *)(lVar37 + 0x28),1);
                    }
                    else {
                      down_read(*(long *)(lVar38 + 0x5a0) + 0x60);
                      plVar35 = (long *)find_vma(*(undefined8 *)(lVar38 + 0x5a0),*puVar43);
                      if (plVar35 == (long *)0x0) goto LAB_0010d5d4;
                      lVar50 = *(long *)(plVar12[0x16] + lVar44);
                      if (*(int *)(lVar50 + 0x30) == 0) {
                        uVar41 = *(long *)(lVar50 + 0x18) - *plVar35;
                        local_2b0 = *(long *)(lVar50 + 0x20) - *(long *)(lVar50 + 0x18);
                      }
                      else {
                        local_2b0 = puVar43[1];
                        uVar41 = *puVar43 - *plVar35;
                      }
                      up_read(*(long *)(lVar38 + 0x5a0) + 0x60);
                      dma_buf_begin_cpu_access_partial
                                (*(undefined8 *)(lVar37 + 0x28),1,uVar41 & 0xffffffff,local_2b0);
                      dma_buf_end_cpu_access_partial
                                (*(undefined8 *)(lVar37 + 0x28),1,uVar41 & 0xffffffff,local_2b0);
                    }
                  }
                }
              }
            }
            lVar44 = lVar44 + 8;
          } while (uVar42 * 8 != lVar44);
        }
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        if ((*(int *)(plVar12[0x13] + 0xac) != 0) && (plVar33 != (long *)0x0)) {
          lVar44 = getnstimediff(&local_218);
          *plVar33 = *plVar33 + lVar44;
        }
        if ((uVar40 < 0x68) || (uVar40 == 0x68)) goto LAB_0010d724;
        if ((puVar25 != (ulong *)0x0) && ((lVar44 = plVar12[0xd], lVar44 != 0 && (iVar47 != 0)))) {
          puVar21 = (undefined8 *)(uVar42 * 0x10 + lVar22 + 8);
          puVar31 = (undefined4 *)((long)puVar25 + uVar42 * 0x10 + 4);
          do {
            puVar31[-1] = *(undefined4 *)(lVar44 + uVar42 * 4);
            puVar31[1] = (int)*puVar21;
            *puVar31 = (int)puVar21[-1];
            if (uVar40 < 0x69) goto LAB_0010d724;
            lVar44 = plVar12[0xd];
            if (lVar44 == 0) break;
            uVar42 = uVar42 + 1;
            puVar21 = puVar21 + 2;
            puVar31 = puVar31 + 4;
          } while (uVar42 < uVar28);
        }
        if ((uVar40 < 0x60) || (uVar40 == 0x60)) goto LAB_0010d724;
        uVar41 = 0;
        if ((puVar25 != (ulong *)0x0) && ((uVar28 != 0 && (plVar12[0xc] != 0)))) {
          if ((uVar40 < 0x60) || (uVar40 == 0x60)) goto LAB_0010d724;
          memcpy((void *)plVar12[0xc],puVar25,uVar28 * 0x10);
LAB_0010ce74:
          uVar41 = 0;
        }
      }
      else {
        if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
        plVar35 = plVar12 + 0x10;
        uVar15 = fastrpc_buf_alloc(plVar12[0x13],uVar16,0,0,0,plVar35);
        uVar41 = uVar15 & 0xffffffff;
        if ((int)uVar15 == 0) {
          if ((uVar40 < 0x80) || (uVar40 == 0x80)) goto LAB_0010d724;
          uVar41 = 0xffffffff;
          uVar15 = *(ulong *)(*plVar35 + 0x38);
          if ((uVar15 != 0) && (uVar15 < 0xfffffffffffff001)) {
            if ((uVar40 < 0x80) || (uVar40 == 0x80)) goto LAB_0010d724;
            memset(*(void **)(*plVar35 + 0x38),0,*(size_t *)(*plVar35 + 0x48));
            goto LAB_0010bd50;
          }
        }
      }
      goto LAB_0010ce78;
    }
LAB_0010b470:
    bVar8 = false;
    plVar48 = (long *)0x0;
    goto LAB_0010b478;
  }
  if (*param_4 - 3 < 0xfffffffe) {
    lVar29 = param_1 + 0x10;
    _raw_spin_lock(lVar29);
    plVar12 = (long *)(param_1 + 0x40);
    lVar22 = sp_el0;
    do {
      plVar12 = (long *)*plVar12;
      if (plVar12 == (long *)0x0) {
        _raw_spin_unlock(lVar29);
        if (*(int *)(*(long *)(param_1 + 0x68) + 0x20) == 0) goto code_r0x0010a82c;
        uVar11 = 0;
        bVar8 = false;
        plVar48 = (long *)0x0;
        uVar41 = 0xffffffd9;
        goto LAB_0010c248;
      }
    } while (*(int *)((long)plVar12 + 0x44) != *(int *)(lVar22 + 0x630));
    if ((param_4[1] != *(uint *)((long)plVar12 + 0xa4)) || (plVar12[0x13] != param_1)) {
      *(uint *)((long)plVar12 + 0x13c) = param_4[1];
      plVar12[0x28] = param_1;
      *(uint *)(plVar12 + 0x29) = *param_4;
      _printk(&DAT_0014e254,0x6ad,lVar22 + 0x848,"context_restore_interrupted",
              *(uint *)((long)plVar12 + 0xa4),plVar12[0x13],param_4[1],param_1);
      _raw_spin_unlock(lVar29);
      uVar11 = 0;
      bVar8 = false;
      plVar48 = (long *)0x0;
      uVar41 = 0xffffffea;
      goto LAB_0010c248;
    }
    InstructionSynchronizationBarrier();
    lVar44 = cntvct_el0;
    lVar38 = plVar12[0x13];
    plVar12[0x2c] = (ulong)(lVar44 * 10) / 0xc0;
    if (lVar38 == 0) {
      uVar19 = 0xfffffff7;
LAB_0010c0ac:
      _printk(&DAT_0014c249,0x241,lVar22 + 0x848,"fastrpc_update_txmsg_buf",
              "fastrpc_update_txmsg_buf",uVar19,plVar12[0x18]);
      plVar48 = (long *)plVar12[1];
    }
    else {
      uVar11 = *(uint *)(lVar38 + 0xc0);
      if (4 < uVar11) {
        uVar19 = 0xffffffd4;
        goto LAB_0010c0ac;
      }
      lVar44 = **(long **)(lVar38 + 0xf0);
      lVar22 = lVar44 + (ulong)uVar11 * 0x6a68 + 0x6a50;
      uVar19 = _raw_spin_lock_irqsave(lVar22);
      uVar9 = *(uint *)(plVar12 + 0x2d);
      if ((uVar9 < 0x80) &&
         (*(long *)(lVar44 + (ulong)uVar11 * 0x6a68 + (ulong)uVar9 * 0x50 + 0x2e58) == plVar12[0x18]
         )) {
        lVar44 = lVar44 + (ulong)uVar11 * 0x6a68 + (ulong)uVar9 * 0x50;
        *(long *)(lVar44 + 0x2e90) = plVar12[0x2b];
        *(long *)(lVar44 + 0x2e98) = plVar12[0x2c];
      }
      _raw_spin_unlock_irqrestore(lVar22,uVar19);
      plVar48 = (long *)plVar12[1];
    }
    if (plVar48 != (long *)0x0) {
      lVar22 = *plVar12;
      *plVar48 = lVar22;
      if (lVar22 != 0) {
        *(long **)(lVar22 + 8) = plVar48;
      }
      *plVar12 = 0;
      plVar12[1] = 0;
    }
    lVar22 = *(long *)(param_1 + 0x38);
    *plVar12 = lVar22;
    if (lVar22 != 0) {
      *(long **)(lVar22 + 8) = plVar12;
    }
    *(long **)(param_1 + 0x38) = plVar12;
    plVar12[1] = param_1 + 0x38;
    _raw_spin_unlock(lVar29);
    if (*(int *)(*(long *)(param_1 + 0x68) + 0x20) != 0) {
      plVar48 = (long *)0x0;
      uVar41 = 0xffffffd9;
      bVar8 = false;
      goto LAB_0010b478;
    }
    plVar48 = (long *)0x0;
    goto LAB_0010b248;
  }
  lVar29 = sp_el0;
  _printk(&DAT_0014d5aa,0xd59,lVar29 + 0x848,"fastrpc_internal_invoke",uVar27);
  uVar11 = 0;
  bVar8 = false;
  plVar48 = (long *)0x0;
  uVar41 = 0xffffffea;
  goto LAB_0010c248;
LAB_0010d5d4:
  up_read(*(long *)(lVar38 + 0x5a0) + 0x60);
  uVar41 = 0xffffffff;
  goto LAB_0010ce78;
  while( true ) {
    lVar44 = *(long *)(plVar12[0xf] + lVar22);
    if ((lVar44 != 0) && (*(int *)(lVar44 + 0xcc) != 0)) {
      *(int *)(lVar44 + 0xcc) = *(int *)(lVar44 + 0xcc) + -1;
      if (uVar40 < 0x79) goto LAB_0010d724;
      fastrpc_mmap_free(*(undefined8 *)(plVar12[0xf] + lVar22),0);
    }
    lVar38 = lVar38 + -1;
    lVar22 = lVar22 + 8;
    if (lVar38 == 0) break;
LAB_0010bdbc:
    if (uVar40 < 0x79) goto LAB_0010d724;
  }
LAB_0010c394:
  if ((uVar40 < 0x98) || (uVar40 == 0x98)) goto LAB_0010d724;
  mutex_unlock(plVar12[0x13] + 0x110);
LAB_0010ce78:
  if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
    local_a8 = 0;
    local_a0 = 0;
    ktime_get_real_ts64(&local_a8);
    local_218 = 0;
    local_210 = 0;
    set_normalized_timespec64(&local_218,local_a8 - local_248,local_a0 - lStack_240);
    if (local_218 < 0x225c17d04) {
      if (local_218 < -0x225c17d03) {
        lVar22 = -0x8000000000000000;
      }
      else {
        lVar22 = local_210 + local_218 * 1000000000;
      }
    }
    else {
      lVar22 = 0x7fffffffffffffff;
    }
    *plVar23 = *plVar23 + lVar22;
  }
  if ((int)uVar41 == 0) {
    plVar23 = (long *)0x0;
    if (plVar48 != (long *)0x0) {
      plVar23 = plVar48 + 7;
    }
    local_80 = 0;
    local_78 = 0;
    if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
      ktime_get_real_ts64(&local_80);
    }
    inv_args(plVar12);
    if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
      local_a8 = 0;
      local_a0 = 0;
      ktime_get_real_ts64(&local_a8);
      local_218 = 0;
      local_210 = 0;
      set_normalized_timespec64(&local_218,local_a8 - local_80,local_a0 - local_78);
      if (local_218 < 0x225c17d04) {
        if (local_218 < -0x225c17d03) {
          lVar22 = -0x8000000000000000;
        }
        else {
          lVar22 = local_210 + local_218 * 1000000000;
        }
      }
      else {
        lVar22 = 0x7fffffffffffffff;
      }
      *plVar23 = *plVar23 + lVar22;
    }
    plVar23 = (long *)0x0;
    if (plVar48 != (long *)0x0) {
      plVar23 = plVar48 + 4;
    }
    local_248 = 0;
    lStack_240 = 0;
    if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
      ktime_get_real_ts64(&local_248);
    }
    uVar11 = *param_4;
    local_90 = 0;
    local_88 = 0;
    local_a0 = 0;
    local_98 = 0;
    local_a8 = 0;
    memset(&local_218,0,0x170);
    if ((((uVar40 < 0x98) || (uVar40 == 0x98)) || (uVar40 < 0xa4)) ||
       (((uVar40 == 0xa4 || (uVar40 < 0x120)) || (uVar40 == 0x120)))) goto LAB_0010d724;
    lVar22 = plVar12[0x13];
    if (lVar22 == 0) {
      uVar41 = 0xfffffff7;
      iVar47 = *(int *)(param_1 + 0xac);
    }
    else {
      uVar9 = *(uint *)(lVar22 + 0xc0);
      if (uVar9 < 5) {
        lVar38 = plVar12[0x24];
        uVar6 = *(undefined4 *)((long)plVar12 + 0xa4);
        lVar50 = **(long **)(lVar22 + 0xf0);
        lVar44 = lVar50 + (ulong)uVar9 * 0x6a68 + 0x9a0;
        mutex_lock(lVar44);
        if ((uVar40 < 0xb8) || (uVar40 == 0xb8)) goto LAB_0010d724;
        plVar33 = plVar12 + 0x17;
        *(undefined4 *)plVar33 = *(undefined4 *)(lVar22 + 0xbc);
        if ((uVar40 < 0xbc) || (uVar40 == 0xbc)) goto LAB_0010d724;
        lVar37 = sp_el0;
        *(undefined4 *)((long)plVar12 + 0xbc) = *(undefined4 *)(lVar37 + 0x630);
        if (iVar5 == 1) {
          if ((uVar40 < 0xb8) || (uVar40 == 0xb8)) goto LAB_0010d724;
          *(undefined4 *)plVar33 = 0;
        }
        if ((((((uVar40 < 0x100) || (uVar40 == 0x100)) || (uVar40 == 0xc0)) ||
             ((plVar12[0x18] = plVar12[0x20] | (long)*(int *)(lVar22 + 0xd0), uVar40 < 200 ||
              (uVar40 == 200)))) || (*(uint *)(plVar12 + 0x19) = uVar11, uVar40 < 0xcc)) ||
           ((uVar40 == 0xcc || (*(undefined4 *)((long)plVar12 + 0xcc) = uVar6, uVar40 == 0x80))))
        goto LAB_0010d724;
        lVar24 = 0;
        if (plVar12[0x10] != 0) {
          lVar24 = *(long *)(plVar12[0x10] + 0x40);
        }
        if ((((uVar40 < 0xd0) || (uVar40 == 0xd0)) || (plVar12[0x1a] = lVar24, uVar40 == 0x90)) ||
           ((uVar40 < 0xd8 || (uVar40 == 0xd8)))) goto LAB_0010d724;
        uVar41 = (ulong)*(uint *)(plVar12 + 0x12) + 0xfff & 0x1fffff000;
        if (uVar41 < 0x1001) {
          uVar41 = 0x1000;
        }
        plVar12[0x1b] = uVar41;
        lVar24 = *(long *)(lVar22 + 200);
        lVar46 = *(long *)(lVar50 + (ulong)uVar9 * 0x6a68 + 0x9d8);
        mutex_unlock(lVar44);
        if (lVar24 == lVar46) {
          InstructionSynchronizationBarrier();
          lVar44 = cntvct_el0;
          if ((int)lVar38 == 0) {
            uVar41 = fastrpc_transport_send(uVar9,plVar33,0x28,*(undefined4 *)(lVar22 + 0xc4));
            uVar41 = uVar41 & 0xffffffff;
            lVar22 = 0xb8;
            uVar42 = uVar40;
            local_278 = plVar12;
          }
          else {
            local_98 = plVar12[0x19];
            local_90 = plVar12[0x1a];
            local_88 = plVar12[0x1b];
            local_a8 = *plVar33;
            local_a0 = plVar12[0x18];
            memcpy(&local_218,plVar12,0x170);
            if ((uVar40 < 0x100) || (uVar40 == 0x100)) goto LAB_0010d724;
            uVar41 = plVar12[0x20];
            plVar33 = &local_a8;
            uVar11 = fastrpc_transport_send(uVar9,&local_a8,0x28,*(undefined4 *)(lVar22 + 0xc4));
            if (uVar11 == 0) {
              lVar50 = lVar50 + (ulong)uVar9 * 0x6a68;
              lVar22 = lVar50 + 0x2e40;
              uVar19 = _raw_spin_lock_irqsave(lVar22);
              if (*(long **)(lVar50 + (uVar41 >> 6 & 0x3ff) * 8 + 0xe40) == plVar12) {
                if (uVar40 < 0x16c) goto LAB_0010d724;
                *(undefined1 *)((long)plVar12 + 0x16c) = 1;
              }
              _raw_spin_unlock_irqrestore(lVar22,uVar19);
              uVar41 = 0;
            }
            else {
              uVar41 = (ulong)uVar11;
            }
            lVar22 = 0;
            uVar40 = 0x28;
            uVar42 = 0x170;
            local_278 = &local_218;
          }
          if ((((uVar40 < lVar22 + 8U) || (uVar40 - (lVar22 + 8U) < 8)) || (uVar40 < lVar22 + 0x18U)
              ) || (((uVar40 - (lVar22 + 0x18U) < 8 || (uVar40 < lVar22 + 0x20U)) ||
                    (uVar40 - (lVar22 + 0x20U) < 8)))) goto LAB_0010d724;
          local_80 = 0;
          local_78 = 0;
          ktime_get_real_ts64(&local_80);
          if (local_80 < 0x225c17d04) {
            if (local_80 < -0x225c17d03) {
              lVar22 = -0x8000000000000000;
            }
            else {
              lVar22 = local_78 + local_80 * 1000000000;
            }
          }
          else {
            lVar22 = 0x7fffffffffffffff;
          }
          if ((uVar42 < 0x98) || (uVar42 == 0x98)) goto LAB_0010d724;
          lVar38 = local_278[0x13];
          if (lVar38 == 0) {
            uVar19 = 0xfffffff7;
          }
          else {
            uVar11 = *(uint *)(lVar38 + 0xc0);
            if (uVar11 < 5) {
              lVar50 = **(long **)(lVar38 + 0xf0);
              lVar38 = lVar50 + (ulong)uVar11 * 0x6a68;
              uVar19 = _raw_spin_lock_irqsave(lVar38 + 0x6a50);
              if ((uVar42 < 0x168) || (uVar42 == 0x168)) goto LAB_0010d724;
              uVar9 = *(uint *)(lVar38 + 0x2e48);
              *(uint *)(local_278 + 0x2d) = uVar9;
              if (0x80 < uVar9) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10d768);
                (*pcVar7)();
              }
              lVar50 = lVar50 + (ulong)uVar11 * 0x6a68 + (ulong)uVar9 * 0x50;
              iVar47 = 0;
              if (uVar9 < 0x7f) {
                iVar47 = uVar9 + 1;
              }
              *(long *)(lVar50 + 0x2e50) = *plVar33;
              lVar37 = plVar33[1];
              lVar46 = plVar33[2];
              lVar24 = plVar33[3];
              lVar2 = plVar33[4];
              *(long *)(lVar50 + 0x2e80) = lVar22;
              *(ulong *)(lVar50 + 0x2e88) = (ulong)(lVar44 * 10) / 0xc0;
              *(int *)(lVar50 + 0x2e78) = (int)uVar41;
              *(long *)(lVar50 + 0x2e68) = lVar24;
              *(long *)(lVar50 + 0x2e70) = lVar2;
              *(long *)(lVar50 + 0x2e60) = lVar46;
              *(long *)(lVar50 + 0x2e58) = lVar37;
              *(int *)(lVar38 + 0x2e48) = iVar47;
              _raw_spin_unlock_irqrestore(lVar38 + 0x6a50,uVar19);
              goto LAB_0010d4dc;
            }
            uVar19 = 0xffffffd4;
          }
          if ((uVar42 < 0xc0) || (uVar42 == 0xc0)) {
LAB_0010d724:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(1,0x10d728);
            (*pcVar7)();
          }
          _printk(&DAT_0014c249,0x241,lVar37 + 0x848,"fastrpc_update_txmsg_buf",
                  "fastrpc_update_txmsg_buf",uVar19,local_278[0x18]);
          iVar47 = *(int *)(param_1 + 0xac);
        }
        else {
          uVar41 = 0xffffff98;
LAB_0010d4dc:
          iVar47 = *(int *)(param_1 + 0xac);
        }
      }
      else {
        uVar41 = 0xffffffd4;
        iVar47 = *(int *)(param_1 + 0xac);
      }
    }
    if ((iVar47 != 0) && (plVar23 != (long *)0x0)) {
      local_a8 = 0;
      local_a0 = 0;
      ktime_get_real_ts64(&local_a8);
      local_218 = 0;
      local_210 = 0;
      set_normalized_timespec64(&local_218,local_a8 - local_248,local_a0 - lStack_240);
      if (local_218 < 0x225c17d04) {
        if (local_218 < -0x225c17d03) {
          lVar22 = -0x8000000000000000;
        }
        else {
          lVar22 = local_210 + local_218 * 1000000000;
        }
      }
      else {
        lVar22 = 0x7fffffffffffffff;
      }
      *plVar23 = *plVar23 + lVar22;
    }
    if ((int)uVar41 == 0) {
      if ((int)lVar29 != 0) {
        uVar41 = 0;
        bVar8 = true;
        iVar5 = *(int *)(param_1 + 0xac);
        uVar11 = local_21c;
        goto joined_r0x0010c29c;
      }
LAB_0010b248:
      if ((((*(char *)(param_1 + 0x220) != '\0') && (0x14 < *param_4)) && (uVar27 == 3)) &&
         (*(int *)(param_1 + 0x21c) == 1)) {
        *(undefined4 *)(plVar12 + 0x22) = 5;
      }
      fastrpc_wait_for_completion(plVar12,&local_21c,iVar5,0,local_234);
      uVar41 = (ulong)local_21c;
      if (local_21c == 0) {
        if ((char)plVar12[0x23] == '\0') {
          lVar29 = sp_el0;
          _printk(&DAT_0014db79,0xda7,lVar29 + 0x848,"fastrpc_internal_invoke",*param_4,
                  *(undefined4 *)((long)plVar12 + 0xa4));
          bVar8 = false;
          uVar41 = 0xffffff92;
        }
        else {
          plVar23 = (long *)0x0;
          if (plVar48 != (long *)0x0) {
            plVar23 = plVar48 + 7;
          }
          local_218 = 0;
          local_210 = 0;
          if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
            ktime_get_real_ts64(&local_218);
          }
          inv_args(plVar12);
          if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
            lVar29 = getnstimediff(&local_218);
            *plVar23 = *plVar23 + lVar29;
          }
          trace_fastrpc_msg("inv_args_2: end");
          plVar23 = (long *)0x0;
          if (plVar48 != (long *)0x0) {
            plVar23 = plVar48 + 6;
          }
          local_218 = 0;
          local_210 = 0;
          if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
            ktime_get_real_ts64(&local_218);
          }
          uVar42 = put_args(iVar5,plVar12);
          uVar41 = uVar42 & 0xffffffff;
          if ((*(int *)(param_1 + 0xac) != 0) && (plVar23 != (long *)0x0)) {
            lVar29 = getnstimediff(&local_218);
            *plVar23 = *plVar23 + lVar29;
          }
          trace_fastrpc_msg("put_args: end");
          bVar8 = false;
          if ((int)uVar42 == 0) {
            uVar41 = (ulong)*(uint *)(plVar12 + 8);
          }
        }
      }
      else {
        bVar8 = false;
      }
    }
  }
LAB_0010b478:
  uVar11 = local_21c;
  if ((plVar12 == (long *)0x0) || (local_21c != 0xfffffe00)) {
    if (plVar12 != (long *)0x0) {
      iVar47 = *(int *)(param_1 + 0xac);
      if ((iVar47 != 0) && (local_21c == 0)) {
        uVar9 = *param_4;
        if (uVar9 != 3) {
          if ((plVar48 != (long *)0x0) && (plVar23 = plVar48 + 8, plVar23 != (long *)0x0)) {
            local_a8 = 0;
            local_a0 = 0;
            ktime_get_real_ts64(&local_a8);
            local_218 = 0;
            local_210 = 0;
            set_normalized_timespec64(&local_218,local_a8 - local_230,local_a0 - lStack_228);
            if (local_218 < 0x225c17d04) {
              if (local_218 < -0x225c17d03) {
                lVar29 = -0x8000000000000000;
              }
              else {
                lVar29 = local_210 + local_218 * 1000000000;
              }
            }
            else {
              lVar29 = 0x7fffffffffffffff;
            }
            *plVar23 = *plVar23 + lVar29;
          }
          if ((plVar48 != (long *)0x0) && (0x14 < uVar9)) {
            *plVar48 = *plVar48 + 1;
          }
        }
        iVar47 = *(int *)(param_1 + 0xac);
      }
      if ((((iVar47 != 0) && (plVar12[0x21] != 0)) && (0x14 < *(uint *)(plVar12 + 0x14))) &&
         (pvVar17 = (void *)plVar12[0x1d], pvVar17 != (void *)0x0)) {
        if (iVar5 == 0) {
          puVar21 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar21 + 0x46) >> 5 & 1) != 0) ||
             (pvVar30 = pvVar17, ((uint)*puVar21 >> 0x1a & 1) != 0)) {
            pvVar30 = (void *)((ulong)pvVar17 & ((long)pvVar17 << 8) >> 8);
          }
          if (pvVar30 < (void *)0x7fffffffb1) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar42 = daif;
              if ((uVar42 & 0x80) == 0) {
                uVar40 = daif;
                daif = uVar40 | 0xc0;
              }
              puVar21 = (undefined8 *)puVar21[1];
              uVar40 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar21 & 0xffff000000000000 | uVar40 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar21;
              InstructionSynchronizationBarrier();
              daif = uVar42;
            }
            uVar19 = __arch_copy_to_user(puVar21,(ulong)pvVar17 & 0xff7fffffffffffff,
                                         (void *)plVar12[0x21],0x50);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar42 = daif;
              if ((uVar42 & 0x80) == 0) {
                uVar40 = daif;
                daif = uVar40 | 0xc0;
              }
              uVar40 = ttbr1_el1;
              ttbr0_el1 = (uVar40 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar40 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar42;
            }
            if ((int)uVar19 == 0) goto LAB_0010c230;
          }
          else {
            uVar19 = 0x50;
          }
          lVar29 = sp_el0;
          _printk(&DAT_0014d347,0xdcd,lVar29 + 0x848,"fastrpc_internal_invoke",uVar19);
        }
        else {
          memmove(pvVar17,(void *)plVar12[0x21],0x50);
        }
      }
LAB_0010c230:
      context_free(plVar12);
      plVar48 = (long *)0x0;
    }
  }
  else {
    lVar44 = plVar12[0x13];
    InstructionSynchronizationBarrier();
    lVar29 = cntvct_el0;
    lVar22 = plVar12[0x13];
    plVar12[0x2b] = (ulong)(lVar29 * 10) / 0xc0;
    if (lVar22 == 0) {
      uVar19 = 0xfffffff7;
LAB_0010ba40:
      lVar29 = sp_el0;
      _printk(&DAT_0014c249,0x241,lVar29 + 0x848,"fastrpc_update_txmsg_buf",
              "fastrpc_update_txmsg_buf",uVar19,plVar12[0x18]);
    }
    else {
      uVar11 = *(uint *)(lVar22 + 0xc0);
      if (4 < uVar11) {
        uVar19 = 0xffffffd4;
        goto LAB_0010ba40;
      }
      lVar22 = **(long **)(lVar22 + 0xf0);
      lVar29 = lVar22 + (ulong)uVar11 * 0x6a68 + 0x6a50;
      uVar19 = _raw_spin_lock_irqsave(lVar29);
      uVar9 = *(uint *)(plVar12 + 0x2d);
      if ((uVar9 < 0x80) &&
         (*(long *)(lVar22 + (ulong)uVar11 * 0x6a68 + (ulong)uVar9 * 0x50 + 0x2e58) == plVar12[0x18]
         )) {
        lVar22 = lVar22 + (ulong)uVar11 * 0x6a68 + (ulong)uVar9 * 0x50;
        *(long *)(lVar22 + 0x2e90) = plVar12[0x2b];
        *(long *)(lVar22 + 0x2e98) = plVar12[0x2c];
      }
      _raw_spin_unlock_irqrestore(lVar29,uVar19);
    }
    _raw_spin_lock(plVar12[0x13] + 0x10);
    plVar23 = (long *)plVar12[1];
    if (plVar23 != (long *)0x0) {
      lVar29 = *plVar12;
      *plVar23 = lVar29;
      if (lVar29 != 0) {
        *(long **)(lVar29 + 8) = plVar23;
      }
      *plVar12 = 0;
      plVar12[1] = 0;
    }
    plVar23 = (long *)(lVar44 + 0x40);
    lVar29 = *plVar23;
    *plVar12 = lVar29;
    if (lVar29 != 0) {
      *(long **)(lVar29 + 8) = plVar12;
    }
    *plVar23 = (long)plVar12;
    plVar12[1] = (long)plVar23;
    _raw_spin_unlock(plVar12[0x13] + 0x10);
    uVar11 = 0xfffffe00;
  }
LAB_0010c248:
  if (((iVar5 == 0) && (-1 < (int)uVar27)) && ((int)uVar27 < 5)) {
    mutex_lock(**(long **)(param_1 + 0xf0) + (ulong)uVar27 * 0x6a68 + 0x9a0);
    lVar29 = **(long **)(param_1 + 0xf0) + (ulong)uVar27 * 0x6a68;
    uVar27 = (uint)uVar41;
    if (*(long *)(param_1 + 200) != *(long *)(lVar29 + 0x9d8)) {
      uVar27 = 0xffffff98;
    }
    uVar41 = (ulong)uVar27;
    mutex_unlock(lVar29 + 0x9a0);
  }
  iVar5 = *(int *)(param_1 + 0xac);
joined_r0x0010c29c:
  if (((iVar5 != 0) && (uVar11 == 0)) && ((bVar8 && (uVar27 = *param_4, uVar27 != 3)))) {
    if ((plVar48 != (long *)0x0) && (plVar12 = plVar48 + 8, plVar12 != (long *)0x0)) {
      local_a8 = 0;
      local_a0 = 0;
      ktime_get_real_ts64(&local_a8);
      local_218 = 0;
      local_210 = 0;
      set_normalized_timespec64(&local_218,local_a8 - local_230,local_a0 - lStack_228);
      if (local_218 < 0x225c17d04) {
        if (local_218 < -0x225c17d03) {
          lVar29 = -0x8000000000000000;
        }
        else {
          lVar29 = local_210 + local_218 * 1000000000;
        }
      }
      else {
        lVar29 = 0x7fffffffffffffff;
      }
      *plVar12 = *plVar12 + lVar29;
    }
    if ((plVar48 != (long *)0x0) && (0x14 < uVar27)) {
      *plVar48 = *plVar48 + 1;
    }
  }
  lVar29 = sp_el0;
  if (*(long *)(lVar29 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar41 & 0xffffffff;
}



//------------------------------------------------------------
// trace_fastrpc_msg @ 0010e088 size=44
// signature: undefined trace_fastrpc_msg(void)
// callers: [fastrpc_internal_invoke]
//------------------------------------------------------------

void trace_fastrpc_msg(void)

{
  return;
}



//------------------------------------------------------------
// fastrpc_check_pd_status @ 0010e150 size=548
// signature: undefined fastrpc_check_pd_status(void)
// callers: [fastrpc_internal_invoke]
//------------------------------------------------------------

void fastrpc_check_pd_status(long param_1,char *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  char *__s1;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  int local_50;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  lVar5 = 0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_50 = -1;
  local_4c = 0xffffffff;
  if ((param_2 == (char *)0x0) || (*(char **)(param_1 + 0xd8) == (char *)0x0)) goto LAB_0010e1c0;
  iVar3 = strcmp(*(char **)(param_1 + 0xd8),param_2);
  if (iVar3 == 0) {
    lVar5 = fastrpc_get_spd_session(param_2,&local_4c,&local_50);
    iVar3 = local_50;
    if ((int)lVar5 != 0) goto LAB_0010e1c0;
    if (local_50 == *(int *)(param_1 + 0xc0)) {
      __s1 = *(char **)(param_1 + 0xd8);
      iVar4 = strcmp(__s1,"audio_pdr_adsprpc");
      if (iVar4 == 0) {
        if (0xd < local_4c) goto LAB_0010e370;
        lVar6 = gfa + (long)iVar3 * 0x6a68 + (ulong)local_4c * 0x48;
        if ((*(long *)(lVar6 + 0x570) != *(long *)(lVar6 + 0x578)) &&
           (*(int *)(param_1 + 0xe4) == 0)) {
          lVar5 = 0xffffff98;
          goto LAB_0010e1c0;
        }
      }
      else {
        iVar4 = strcmp(__s1,"sensors_pdr_adsprpc");
        if ((iVar4 != 0) && (iVar4 = strcmp(__s1,"sensors_pdr_sdsprpc"), iVar4 != 0))
        goto LAB_0010e1a4;
      }
      uVar1 = local_4c;
      uVar7 = (ulong)local_4c;
      if (0xd < local_4c) {
LAB_0010e370:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10e374);
        (*pcVar2)();
      }
      if (*(int *)(gfa + (long)iVar3 * 0x6a68 + uVar7 * 0x48 + 0x580) == 0) {
        local_60 = 0;
        uStack_58 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_78 = 0;
        init_wait_entry(&local_78,0);
        lVar5 = prepare_to_wait_event(gfa + (long)iVar3 * 0x6a68 + uVar7 * 0x48 + 0x588,&local_78,1)
        ;
        iVar4 = *(int *)(gfa + (long)iVar3 * 0x6a68 + uVar7 * 0x48 + 0x580);
        while (iVar4 == 0) {
          if (lVar5 != 0) goto LAB_0010e1c0;
          schedule();
          lVar5 = prepare_to_wait_event
                            (gfa + (long)iVar3 * 0x6a68 + uVar7 * 0x48 + 0x588,&local_78,1);
          iVar4 = *(int *)(gfa + (long)iVar3 * 0x6a68 + uVar7 * 0x48 + 0x580);
        }
        finish_wait(gfa + (long)iVar3 * 0x6a68 + (ulong)uVar1 * 0x48 + 0x588,&local_78);
        lVar5 = 0;
        goto LAB_0010e1c0;
      }
    }
  }
LAB_0010e1a4:
  lVar5 = 0;
LAB_0010e1c0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// getnstimediff @ 0010e374 size=196
// signature: undefined getnstimediff(void)
// callers: [fastrpc_internal_invoke, fastrpc_restart_notifier_cb]
//------------------------------------------------------------

void getnstimediff(long *param_1)

{
  long lVar1;
  long lVar2;
  long local_48;
  long lStack_40;
  long local_38;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  lStack_40 = 0;
  ktime_get_real_ts64(&local_48);
  local_38 = 0;
  local_30 = 0;
  set_normalized_timespec64(&local_38,local_48 - *param_1,lStack_40 - param_1[1]);
  if (local_38 < 0x225c17d04) {
    if (local_38 < -0x225c17d03) {
      lVar2 = -0x8000000000000000;
    }
    else {
      lVar2 = local_30 + local_38 * 1000000000;
    }
  }
  else {
    lVar2 = 0x7fffffffffffffff;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// inv_args @ 0010e438 size=468
// signature: undefined inv_args(void)
// callers: [fastrpc_internal_invoke2, fastrpc_internal_invoke]
//------------------------------------------------------------

void inv_args(long param_1)

{
  long lVar1;
  ulong *puVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  
  uVar10 = (ulong)(*(uint *)(param_1 + 0xa4) >> 0x10) & 0xff;
  lVar1 = uVar10 + (byte)(*(uint *)(param_1 + 0xa4) >> 8);
  if ((int)lVar1 != 0) {
    lVar11 = 0;
    uVar12 = *(ulong *)(param_1 + 0x60);
    lVar4 = sp_el0;
    do {
      lVar6 = *(long *)(*(long *)(param_1 + 0xb0) + lVar11);
      iVar3 = *(int *)(lVar6 + 0x10);
      if (((int)uVar10 < iVar3 + 1) &&
         (puVar2 = (ulong *)(uVar12 + (long)iVar3 * 0x10), puVar2[1] != 0)) {
        lVar13 = *(long *)(*(long *)(param_1 + 0x78) + (long)iVar3 * 8);
        if ((((*(long *)(param_1 + 0x98) == 0) ||
             ((lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0x68), lVar7 == 0 ||
              (*(int *)(lVar7 + 0x28) == 0)))) &&
            ((lVar13 == 0 || ((*(byte *)(lVar13 + 0x88) >> 6 & 1) == 0)))) &&
           (0xfff < (*puVar2 ^ uVar12))) {
          if (*(long *)(lVar6 + 0x18) == 0) {
            if ((lVar13 != 0) && (*(int *)(lVar6 + 0x30) == 1)) goto LAB_0010e528;
          }
          else if (lVar13 != 0) {
LAB_0010e528:
            if (*(long *)(lVar13 + 0x28) != 0) {
              uVar8 = (ulong)(uint)(*(int *)(lVar6 + 0x20) - (int)*(long *)(lVar6 + 0x18)) + 0xfff &
                      0x1fffff000;
              if (uVar8 < 0x1001) {
                uVar8 = 0x1000;
              }
              if ((uVar8 == *(ulong *)(lVar13 + 0x50)) || (*(int *)(lVar6 + 0x30) != 0)) {
                dma_buf_begin_cpu_access(*(long *)(lVar13 + 0x28),2);
                dma_buf_end_cpu_access(*(undefined8 *)(lVar13 + 0x28),1);
              }
              else {
                down_read(*(long *)(lVar4 + 0x5a0) + 0x60);
                plVar5 = (long *)find_vma(*(undefined8 *)(lVar4 + 0x5a0),*puVar2);
                if (plVar5 == (long *)0x0) {
                  up_read(*(long *)(lVar4 + 0x5a0) + 0x60);
                  return;
                }
                lVar6 = *(long *)(*(long *)(param_1 + 0xb0) + lVar11);
                if (*(int *)(lVar6 + 0x30) == 0) {
                  uVar9 = *(long *)(lVar6 + 0x18) - *plVar5;
                  uVar8 = *(long *)(lVar6 + 0x20) - *(long *)(lVar6 + 0x18);
                }
                else {
                  uVar8 = puVar2[1];
                  uVar9 = *puVar2 - *plVar5;
                }
                up_read(*(long *)(lVar4 + 0x5a0) + 0x60);
                dma_buf_begin_cpu_access_partial
                          (*(undefined8 *)(lVar13 + 0x28),2,uVar9 & 0xffffffff,uVar8 & 0xffffffff);
                dma_buf_end_cpu_access_partial
                          (*(undefined8 *)(lVar13 + 0x28),1,uVar9 & 0xffffffff,uVar8 & 0xffffffff);
              }
            }
          }
        }
      }
      lVar11 = lVar11 + 8;
    } while (lVar1 * 8 != lVar11);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_wait_for_completion @ 0010e60c size=684
// signature: undefined fastrpc_wait_for_completion(void)
// callers: [fastrpc_internal_invoke2, fastrpc_internal_invoke]
//------------------------------------------------------------

void fastrpc_wait_for_completion
               (long param_1,int *param_2,int param_3,int param_4,undefined1 *param_5)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  
  if (param_1 == 0) {
    lVar5 = sp_el0;
    *param_2 = 0xe;
    *param_5 = 0;
    _printk(&DAT_0014d8e5,0xcac,lVar5 + 0x848,"fastrpc_wait_for_completion",0xe);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x114);
  lVar5 = sp_el0;
  do {
    switch(*(undefined4 *)(param_1 + 0x110)) {
    case 0:
    case 3:
      if (param_4 != 0) {
LAB_0010ea54:
        uVar8 = _raw_spin_lock_irqsave(*(long *)(param_1 + 0x98) + 0x1b8);
        bVar1 = *(char *)(param_1 + 0x118) == '\0';
        if (bVar1) {
          *(undefined1 *)(param_1 + 0x138) = 0;
        }
        *param_5 = !bVar1;
        _raw_spin_unlock_irqrestore(*(long *)(param_1 + 0x98) + 0x1b8,uVar8);
        return;
      }
      break;
    case 1:
      iVar6 = poll_for_remote_response(param_1,4000);
      if (iVar6 == 0) {
        *(undefined1 *)(param_1 + 0x118) = 1;
        *param_5 = 1;
        return;
      }
      _printk(&DAT_0014f415,0xce1,lVar5 + 0x848,"fastrpc_wait_for_completion",4000,
              *(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4));
      if (param_4 != 0) goto LAB_0010ea54;
      if (*(char *)(param_1 + 0x118) != '\0') {
        return;
      }
      break;
    case 2:
      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
      if (uVar2 < 500) {
        uVar9 = 0xffffffff;
        do {
          uVar7 = try_wait_for_completion(param_1 + 0x20);
          uVar10 = uVar7 & 0xffffffff;
          if ((uVar7 & 1) != 0) break;
          __const_udelay(0x10c7);
          uVar9 = uVar9 + 1;
        } while (uVar9 < 499);
      }
      else {
        uVar10 = 0;
      }
      lVar4 = *(long *)(lVar5 + 0x10) + -1;
      *(int *)(lVar5 + 0x10) = (int)lVar4;
      if ((lVar4 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
        preempt_schedule();
      }
      if (param_4 != 0) goto LAB_0010ea54;
      if ((uVar10 & 1) != 0) goto LAB_0010e780;
      break;
    default:
      *param_2 = 0x35;
      lVar5 = sp_el0;
      *param_5 = 0;
      _printk(&DAT_0014e2c7,0xd1b,lVar5 + 0x848,"fastrpc_wait_for_completion",
              *(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0xa0),
              *(undefined4 *)(param_1 + 0xa4));
      return;
    case 5:
      iVar6 = poll_for_remote_response(param_1,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x224));
      if (iVar6 == 0) {
        *param_2 = 0;
        *param_5 = 1;
      }
      else {
        _printk(&DAT_00150061,0xd0f,lVar5 + 0x848,"fastrpc_wait_for_completion",
                *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x224),*(undefined4 *)(param_1 + 0xa0),
                *(undefined4 *)(param_1 + 0xa4));
        *(undefined4 *)(param_1 + 0x110) = 0;
      }
LAB_0010e780:
      cVar3 = *(char *)(param_1 + 0x118);
      goto joined_r0x0010e784;
    }
    if (param_3 == 0) {
      iVar6 = wait_for_completion_interruptible();
      *param_2 = iVar6;
      if (iVar6 != 0) {
        return;
      }
    }
    else {
      wait_for_completion(param_1 + 0x20);
      *param_2 = 0;
    }
    cVar3 = *(char *)(param_1 + 0x118);
joined_r0x0010e784:
    if (cVar3 != '\0') {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// put_args @ 0010eb18 size=1384
// signature: undefined put_args(void)
// callers: [fastrpc_internal_invoke2, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 put_args(int param_1,long param_2)

{
  ulong uVar1;
  void *__src;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  code *pcVar9;
  undefined4 uVar10;
  long lVar11;
  void *pvVar12;
  void *pvVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 *puVar17;
  void *pvVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  
  uVar5 = *(uint *)(param_2 + 0xa4);
  lVar3 = *(long *)(param_2 + 0x58);
  lVar4 = *(long *)(param_2 + 0x60);
  uVar15 = (ulong)(uVar5 >> 8) & 0xff;
  uVar1 = uVar15 + (byte)(uVar5 >> 0x10);
  if ((int)uVar15 != 0) {
    puVar17 = (undefined8 *)sp_el0;
    uVar15 = (ulong)(uVar5 >> 0x10) & 0xff;
    lVar21 = uVar15 << 4;
    do {
      if (*(long *)(*(long *)(param_2 + 0x78) + uVar15 * 8) == 0) {
        puVar2 = (undefined8 *)(lVar4 + lVar21);
        if (param_1 == 0) {
          uVar19 = puVar2[1];
          if (uVar19 >> 0x1f != 0) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x800,0x10ed00);
            (*pcVar9)();
          }
          uVar14 = *puVar2;
          uVar20 = *(ulong *)(*(long *)(param_2 + 0x50) + lVar21);
          __check_object_size(uVar14,uVar19,1);
          if (((*(byte *)((long)puVar17 + 0x46) >> 5 & 1) != 0) ||
             (uVar16 = uVar20, ((uint)*puVar17 >> 0x1a & 1) != 0)) {
            uVar16 = uVar20 & (long)(uVar20 << 8) >> 8;
          }
          if (uVar16 <= 0x8000000000 - uVar19) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar16 = daif;
              if ((uVar16 & 0x80) == 0) {
                uVar6 = daif;
                daif = uVar6 | 0xc0;
              }
              uVar6 = ttbr1_el1;
              ttbr1_el1 = puVar17[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar17[1];
              InstructionSynchronizationBarrier();
              daif = uVar16;
            }
            uVar19 = __arch_copy_to_user(uVar20 & 0xff7fffffffffffff,uVar14,uVar19);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar20 = daif;
              if ((uVar20 & 0x80) == 0) {
                uVar16 = daif;
                daif = uVar16 | 0xc0;
              }
              uVar16 = ttbr1_el1;
              ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar16 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar20;
            }
          }
          if ((int)uVar19 != 0) {
            lVar3 = sp_el0;
            _printk(&DAT_0014f46c,0xb4b,lVar3 + 0x848,"put_args",*(undefined8 *)(lVar4 + lVar21 + 8)
                    ,(int)uVar15 + 1,uVar19 & 0xffffffff);
            return 0xfffffff2;
          }
        }
        else {
          memmove(*(void **)(*(long *)(param_2 + 0x50) + lVar21),(void *)*puVar2,puVar2[1]);
        }
      }
      else {
        mutex_lock(*(long *)(param_2 + 0x98) + 0x110);
        lVar11 = *(long *)(*(long *)(param_2 + 0x78) + uVar15 * 8);
        if (*(int *)(lVar11 + 200) != 0) {
          *(int *)(lVar11 + 200) = *(int *)(lVar11 + 200) + -1;
          lVar11 = *(long *)(*(long *)(param_2 + 0x78) + uVar15 * 8);
        }
        fastrpc_mmap_free(lVar11,0);
        mutex_unlock(*(long *)(param_2 + 0x98) + 0x110);
        *(undefined8 *)(*(long *)(param_2 + 0x78) + uVar15 * 8) = 0;
      }
      uVar15 = uVar15 + 1;
      lVar21 = lVar21 + 0x10;
    } while (uVar15 < uVar1);
  }
  uVar15 = (ulong)(uVar5 >> 4) & 0xf;
  lVar3 = lVar3 + (uVar1 + ((ulong)uVar5 & 0xf) + uVar15) * 0x18 +
          ((ulong)(uVar5 >> 0x10) & 0xff) * 0x10 + ((ulong)(uVar5 >> 8) & 0xff) * 0x10 +
          (ulong)(uint)((int)uVar15 + (int)((ulong)uVar5 & 0xf)) * 0x10;
  pvVar13 = (void *)(lVar3 + 0x80);
  __src = (void *)(lVar3 + 0x184);
  mutex_lock(*(long *)(param_2 + 0x98) + 0x110);
  lVar21 = 0;
  do {
    lVar11 = *(long *)(lVar3 + lVar21 * 8);
    if (lVar11 == 0) break;
    plVar8 = (long *)*(long *)(*(long *)(param_2 + 0x98) + 0x18);
    do {
      plVar7 = plVar8;
      if (plVar7 == (long *)0x0) goto LAB_0010ed8c;
      plVar8 = (long *)*plVar7;
    } while ((plVar7[0xb] != 0) || (*(int *)(plVar7 + 4) != (int)lVar11));
    if (*(int *)((long)plVar7 + 0xcc) != 0) {
      *(undefined4 *)((long)plVar7 + 0xcc) = 0;
      fastrpc_mmap_free(plVar7,0);
    }
LAB_0010ed8c:
    lVar21 = lVar21 + 1;
  } while (lVar21 != 0x10);
  mutex_unlock(*(long *)(param_2 + 0x98) + 0x110);
  pvVar12 = *(void **)(param_2 + 0xe0);
  if (((pvVar12 != (void *)0x0) && (pvVar13 != (void *)0x0)) && (lVar4 != 0)) {
    if (param_1 == 0) {
      puVar17 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar17 + 0x46) >> 5 & 1) != 0) ||
         (pvVar18 = pvVar12, ((uint)*puVar17 >> 0x1a & 1) != 0)) {
        pvVar18 = (void *)((ulong)pvVar12 & ((long)pvVar12 << 8) >> 8);
      }
      uVar10 = 0x100;
      if (pvVar18 < (void *)0x7fffffff01) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar1 = daif;
          if ((uVar1 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          puVar17 = (undefined8 *)puVar17[1];
          uVar15 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar17 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar17;
          InstructionSynchronizationBarrier();
          daif = uVar1;
        }
        uVar10 = __arch_copy_to_user(puVar17,(ulong)pvVar12 & 0xff7fffffffffffff,pvVar13,0x100);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar1 = daif;
          if ((uVar1 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar1;
        }
      }
      pvVar13 = *(void **)(param_2 + 0xf0);
      if (pvVar13 == (void *)0x0) {
        return uVar10;
      }
      if (__src == (void *)0x0) {
        return uVar10;
      }
      goto LAB_0010ef18;
    }
    memmove(pvVar12,pvVar13,0x100);
  }
  pvVar13 = *(void **)(param_2 + 0xf0);
  if (pvVar13 == (void *)0x0) {
    return 0;
  }
  if (__src == (void *)0x0) {
    return 0;
  }
  if (param_1 != 0) {
    memmove(pvVar13,__src,0x60);
    return 0;
  }
  uVar10 = 0;
LAB_0010ef18:
  puVar17 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar17 + 0x46) >> 5 & 1) != 0) ||
     (pvVar12 = pvVar13, ((uint)*puVar17 >> 0x1a & 1) != 0)) {
    pvVar12 = (void *)((ulong)pvVar13 & ((long)pvVar13 << 8) >> 8);
  }
  if (pvVar12 < (void *)0x7fffffffa1) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar1 = daif;
      if ((uVar1 & 0x80) == 0) {
        uVar15 = daif;
        daif = uVar15 | 0xc0;
      }
      puVar17 = (undefined8 *)puVar17[1];
      uVar15 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar17 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar17;
      InstructionSynchronizationBarrier();
      daif = uVar1;
    }
    uVar14 = __arch_copy_to_user(puVar17,(ulong)pvVar13 & 0xff7fffffffffffff,__src,0x60);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar1 = daif;
      if ((uVar1 & 0x80) == 0) {
        uVar15 = daif;
        daif = uVar15 | 0xc0;
      }
      uVar15 = ttbr1_el1;
      ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar15 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar1;
    }
    if ((int)uVar14 == 0) {
      return uVar10;
    }
  }
  else {
    uVar14 = 0x60;
  }
  lVar3 = sp_el0;
  _printk(&DAT_0014d347,0xb74,lVar3 + 0x848,"put_args",uVar14);
  return uVar10;
}



//------------------------------------------------------------
// context_free @ 0010f0cc size=524
// signature: undefined context_free(void)
// callers: [fastrpc_file_put, fastrpc_internal_invoke2, fastrpc_internal_invoke]
//------------------------------------------------------------

void context_free(long *param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  
  lVar6 = gfa;
  uVar3 = *(uint *)(param_1[0x13] + 0xc0);
  if (uVar3 < 5) {
    uVar8 = param_1[0x20];
    lVar1 = ((ulong)(*(uint *)((long)param_1 + 0xa4) >> 0x10) & 0xff) +
            (ulong)(byte)(*(uint *)((long)param_1 + 0xa4) >> 8);
    lVar7 = gfa + (ulong)uVar3 * 0x6a68;
    lVar2 = lVar7 + 0x2e40;
    uVar4 = _raw_spin_lock_irqsave(lVar2);
    lVar7 = lVar7 + (uVar8 >> 6 & 0x3ff) * 8;
    if (*(long **)(lVar7 + 0xe40) == param_1) {
LAB_0010f180:
      *(undefined8 *)(lVar7 + 0xe40) = 0;
    }
    else {
      lVar7 = 0;
      do {
        if (*(long **)(lVar6 + (ulong)uVar3 * 0x6a68 + 0xe40 + lVar7) == param_1) {
          lVar7 = lVar6 + (ulong)uVar3 * 0x6a68 + lVar7;
          goto LAB_0010f180;
        }
        lVar7 = lVar7 + 8;
      } while (lVar7 != 0x2000);
    }
    _raw_spin_unlock_irqrestore(lVar2,uVar4);
    _raw_spin_lock(param_1[0x13] + 0x10);
    plVar5 = (long *)param_1[1];
    if (plVar5 != (long *)0x0) {
      lVar6 = *param_1;
      *plVar5 = lVar6;
      if (lVar6 != 0) {
        *(long **)(lVar6 + 8) = plVar5;
      }
      *param_1 = 0;
      param_1[1] = 0;
      *(int *)(param_1[0x13] + 0x48) = *(int *)(param_1[0x13] + 0x48) + -1;
    }
    _raw_spin_unlock(param_1[0x13] + 0x10);
    mutex_lock(param_1[0x13] + 0x110);
    if ((int)lVar1 != 0) {
      lVar6 = 0;
      do {
        lVar7 = *(long *)(param_1[0xf] + lVar6);
        if ((lVar7 != 0) && (*(int *)(lVar7 + 200) != 0)) {
          *(int *)(lVar7 + 200) = *(int *)(lVar7 + 200) + -1;
          lVar7 = *(long *)(param_1[0xf] + lVar6);
        }
        fastrpc_mmap_free(lVar7,0);
        lVar6 = lVar6 + 8;
      } while (lVar1 * 8 != lVar6);
    }
    mutex_unlock(param_1[0x13] + 0x110);
    fastrpc_buf_free(param_1[0x10],1);
    if (param_1[0x11] != param_1[0x10]) {
      fastrpc_buf_free(param_1[0x11],1);
    }
    kfree(param_1[0xc]);
    param_1[0xc] = 0;
    *(undefined4 *)(param_1 + 0x1f) = 0;
    param_1[0x20] = 0;
    if (*(int *)(param_1[0x13] + 0xac) != 0) {
      kfree(param_1[0x21]);
    }
    kfree(*(undefined4 *)((long)param_1 + 0xa4),param_1);
  }
  else {
    lVar6 = sp_el0;
    _printk(&DAT_0014e617,0x7fd,lVar6 + 0x848,"context_free",uVar3);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_internal_invoke2 @ 0010f384 size=4004
// signature: undefined fastrpc_internal_invoke2(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_ioctl_invoke2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fastrpc_internal_invoke2(long param_1,int *param_2,ulong param_3)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  size_t sVar9;
  undefined8 uVar10;
  ulong uVar11;
  long *plVar12;
  undefined8 *puVar13;
  long lVar14;
  ulong uVar15;
  void *pvVar16;
  uint uVar17;
  long lVar18;
  ulong uVar19;
  void *pvVar20;
  long *plVar21;
  long lVar22;
  undefined8 local_100;
  undefined8 local_f8;
  long local_f0;
  long lStack_e8;
  long local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  long local_c0;
  long lStack_b8;
  char local_b0 [4];
  undefined4 local_ac;
  long local_a8;
  long lStack_a0;
  long local_98;
  long local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar14 = sp_el0;
  local_70 = *(long *)(lVar14 + 0x638);
  local_d0 = 0;
  local_c8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_f0 = 0;
  lStack_e8 = 0;
  local_100 = 0;
  local_f8 = 0;
  if (*param_2 - 1U < 2) {
    if ((*(int *)(param_1 + 0xc0) != 3) || (*(long *)(param_1 + 0x68) == 0)) {
      uVar19 = 0xffffffcb;
      goto LAB_0010fd7c;
    }
    if (DAT_0013dd00 != 1) {
      uVar19 = 0xffffffa3;
      goto LAB_0010fd7c;
    }
  }
  uVar17 = (uint)_cpu_hwcaps;
  switch(*param_2 - 1U) {
  case 0:
    if ((uint)param_2[4] < 0x41) {
      pvVar20 = *(void **)(param_2 + 2);
      if (param_2[4] == 0x40) {
        if ((param_3 & 1) == 0) {
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (pvVar16 = pvVar20, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            pvVar16 = (void *)((ulong)pvVar20 & ((long)pvVar20 << 8) >> 8);
          }
          if (pvVar16 < (void *)0x7fffffffc1) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar19 = daif;
              if ((uVar19 & 0x80) == 0) {
                uVar11 = daif;
                daif = uVar11 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar11 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar11 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar19;
            }
            sVar9 = __arch_copy_from_user
                              (puVar13,&local_100,(ulong)pvVar20 & 0xff7fffffffffffff,0x40);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar19 = daif;
              if ((uVar19 & 0x80) == 0) {
                uVar11 = daif;
                daif = uVar11 | 0xc0;
              }
              uVar11 = ttbr1_el1;
              ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar11 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar19;
            }
            if (sVar9 == 0) goto LAB_0010fd60;
          }
          else {
            sVar9 = 0x40;
          }
          memset(local_b0 + (-0x10 - sVar9),0,sVar9);
          uVar19 = sVar9 & 0xffffffff;
          if ((int)sVar9 != 0) goto LAB_0010fd7c;
        }
        else {
          memmove(&local_100,pvVar20,0x40);
        }
      }
      else {
        if ((param_3 & 1) == 0) {
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (pvVar16 = pvVar20, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            pvVar16 = (void *)((ulong)pvVar20 & ((long)pvVar20 << 8) >> 8);
          }
          if (pvVar16 < (void *)0x7fffffffd1) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar19 = daif;
              if ((uVar19 & 0x80) == 0) {
                uVar11 = daif;
                daif = uVar11 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar11 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar11 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar19;
            }
            sVar9 = __arch_copy_from_user
                              (puVar13,&local_100,(ulong)pvVar20 & 0xff7fffffffffffff,0x30);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar19 = daif;
              if ((uVar19 & 0x80) == 0) {
                uVar11 = daif;
                daif = uVar11 | 0xc0;
              }
              uVar11 = ttbr1_el1;
              ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar11 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar19;
            }
            if (sVar9 == 0) goto LAB_0010fd58;
          }
          else {
            sVar9 = 0x30;
          }
          memset(local_b0 + (-0x20 - sVar9),0,sVar9);
          uVar19 = sVar9 & 0xffffffff;
          if ((int)sVar9 != 0) goto LAB_0010fd7c;
        }
        else {
          memmove(&local_100,pvVar20,0x30);
        }
LAB_0010fd58:
        local_c8 = local_d8;
      }
LAB_0010fd60:
      uVar19 = fastrpc_internal_invoke(param_1);
LAB_0010fd78:
      uVar19 = uVar19 & 0xffffffff;
      goto LAB_0010fd7c;
    }
    break;
  case 1:
    if ((uint)param_2[4] < 0x29) {
      uVar11 = *(ulong *)(param_2 + 2);
      local_b0[0] = '\0';
      if (param_1 == 0) {
        uVar19 = 0xfffffff7;
        goto LAB_0010fd7c;
      }
      lVar22 = 0;
      plVar21 = (long *)0x0;
      lVar14 = param_1 + 0x1a0;
      lVar1 = param_1 + 0x1b8;
      lVar5 = sp_el0;
      do {
        iVar7 = *(int *)(param_1 + 0x198);
joined_r0x0010f860:
        if (iVar7 == 0) {
          local_80 = 0;
          uStack_78 = 0;
          local_90 = 0;
          uStack_88 = 0;
          local_98 = 0;
          init_wait_entry(&local_98,0);
          uVar19 = prepare_to_wait_event(lVar14,&local_98,1);
          if (*(int *)(param_1 + 0x198) == 0) {
            do {
              if (uVar19 != 0) goto LAB_0010f8f4;
              schedule();
              uVar19 = prepare_to_wait_event(lVar14,&local_98,1);
            } while (*(int *)(param_1 + 0x198) == 0);
          }
          finish_wait(lVar14,&local_98);
          uVar19 = 0;
        }
        else {
          uVar19 = 0;
        }
LAB_0010f8f4:
        if (0 < *(int *)(param_1 + 0xe0)) {
          uVar19 = 0xfffffff7;
joined_r0x0010fdc8:
          if (plVar21 == (long *)0x0) goto LAB_0010fd7c;
          goto LAB_0010ffa4;
        }
        if (*(char *)(param_1 + 0x2a9) != '\0') {
          uVar19 = 0xfffffff2;
          goto joined_r0x0010fdc8;
        }
        if ((int)uVar19 != 0) goto joined_r0x0010fdc8;
        uVar10 = _raw_spin_lock_irqsave(lVar1);
        plVar12 = *(long **)(param_1 + 0x50);
        if ((plVar12 == (long *)0x0) || (plVar12 + -2 == (long *)0x0)) {
          _raw_spin_unlock_irqrestore(lVar1,uVar10);
          if (plVar21 == (long *)0x0) goto LAB_0010f868;
          local_ac = 0;
          iVar7 = *(int *)(param_1 + 0xac);
        }
        else {
          plVar21 = (long *)plVar12[1];
          local_ac = 0;
          if (plVar21 != (long *)0x0) {
            lVar18 = *plVar12;
            *plVar21 = lVar18;
            if (lVar18 != 0) {
              *(long **)(lVar18 + 8) = plVar21;
            }
            *plVar12 = 0;
            plVar12[1] = 0;
          }
          piVar2 = (int *)(param_1 + 0x198);
          Hint_Prefetch(piVar2,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar4) {
              *piVar2 = *piVar2 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          _raw_spin_unlock_irqrestore(lVar1,uVar10);
          iVar7 = *(int *)(param_1 + 0xac);
          plVar21 = plVar12 + -2;
        }
        if (iVar7 != 0) {
          lVar22 = plVar21[0x21];
        }
        fastrpc_wait_for_completion(plVar21,&local_ac,0,1,local_b0);
      } while (local_b0[0] == '\0');
      local_e0 = plVar21[0x14];
      local_100 = plVar21[0x25];
      local_c0 = 0;
      lStack_b8 = 0;
      local_f8 = CONCAT44(local_f8._4_4_,(int)plVar21[8]);
      local_f0 = plVar21[0x1d];
      lStack_e8 = plVar21[0x1e];
      plVar12 = (long *)0x0;
      if (lVar22 != 0) {
        plVar12 = (long *)(lVar22 + 0x38);
      }
      if ((*(int *)(plVar21[0x13] + 0xac) != 0) && (plVar12 != (long *)0x0)) {
        ktime_get_real_ts64(&local_c0);
      }
      inv_args(plVar21);
      if ((*(int *)(plVar21[0x13] + 0xac) != 0) && (plVar12 != (long *)0x0)) {
        local_a8 = 0;
        lStack_a0 = 0;
        ktime_get_real_ts64(&local_a8);
        local_98 = 0;
        local_90 = 0;
        set_normalized_timespec64(&local_98,local_a8 - local_c0,lStack_a0 - lStack_b8);
        if (local_98 < 0x225c17d04) {
          if (local_98 < -0x225c17d03) {
            lVar14 = -0x8000000000000000;
          }
          else {
            lVar14 = local_90 + local_98 * 1000000000;
          }
        }
        else {
          lVar14 = 0x7fffffffffffffff;
        }
        *plVar12 = *plVar12 + lVar14;
      }
      if ((int)plVar21[8] == 0) {
        local_c0 = 0;
        lStack_b8 = 0;
        plVar12 = (long *)0x0;
        if (lVar22 != 0) {
          plVar12 = (long *)(lVar22 + 0x30);
        }
        if ((*(int *)(plVar21[0x13] + 0xac) != 0) && (plVar12 != (long *)0x0)) {
          ktime_get_real_ts64(&local_c0);
        }
        iVar7 = put_args(0,plVar21);
        if ((*(int *)(plVar21[0x13] + 0xac) != 0) && (plVar12 != (long *)0x0)) {
          local_a8 = 0;
          lStack_a0 = 0;
          ktime_get_real_ts64(&local_a8);
          local_98 = 0;
          local_90 = 0;
          set_normalized_timespec64(&local_98,local_a8 - local_c0,lStack_a0 - lStack_b8);
          if (local_98 < 0x225c17d04) {
            if (local_98 < -0x225c17d03) {
              lVar14 = -0x8000000000000000;
            }
            else {
              lVar14 = local_90 + local_98 * 1000000000;
            }
          }
          else {
            lVar14 = 0x7fffffffffffffff;
          }
          *plVar12 = *plVar12 + lVar14;
        }
        if (iVar7 == 0) goto LAB_0010fec0;
        uVar19 = 0;
        local_f8 = CONCAT44(local_f8._4_4_,iVar7);
      }
      else {
LAB_0010fec0:
        uVar19 = 0;
      }
LAB_0010ffa4:
      if ((((*(int *)(param_1 + 0xac) != 0) && (plVar21[0x21] != 0)) &&
          (0x14 < *(uint *)(plVar21 + 0x14))) && (uVar15 = plVar21[0x1d], uVar15 != 0)) {
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar8 = uVar15, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar8 = uVar15 & (long)(uVar15 << 8) >> 8;
        }
        if (uVar8 < 0x7fffffffb1) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar8 = daif;
            if ((uVar8 & 0x80) == 0) {
              uVar6 = daif;
              daif = uVar6 | 0xc0;
            }
            uVar6 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar8;
          }
          uVar10 = __arch_copy_to_user(uVar15 & 0xff7fffffffffffff,plVar21[0x21],0x50);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar8 = daif;
              daif = uVar8 | 0xc0;
            }
            uVar8 = ttbr1_el1;
            ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar8 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          if ((int)uVar10 == 0) goto LAB_001100b0;
        }
        else {
          uVar10 = 0x50;
        }
        lVar14 = sp_el0;
        _printk(&DAT_0014d347,0xe37,lVar14 + 0x848,"fastrpc_wait_on_async_queue",uVar10);
      }
LAB_001100b0:
      context_free(plVar21);
      if ((int)uVar19 == 0) {
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar15 = uVar11, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar15 = uVar11 & (long)(uVar11 << 8) >> 8;
        }
        uVar19 = 0x28;
        if (uVar15 < 0x7fffffffd9) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar19 = daif;
            if ((uVar19 & 0x80) == 0) {
              uVar15 = daif;
              daif = uVar15 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar15 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar19;
          }
          uVar19 = __arch_copy_to_user(puVar13,uVar11 & 0xff7fffffffffffff,&local_100,0x28);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar15 = daif;
              daif = uVar15 | 0xc0;
            }
            uVar15 = ttbr1_el1;
            ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar15 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
        }
LAB_0010fb98:
        uVar19 = uVar19 & 0xffffffff;
      }
      goto LAB_0010fd7c;
    }
    break;
  case 2:
    if (param_2[4] == 4) {
      puVar13 = (undefined8 *)sp_el0;
      uVar19 = *(ulong *)(param_2 + 2);
      if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
         (uVar11 = uVar19, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
        uVar11 = uVar19 & (long)(uVar19 << 8) >> 8;
      }
      if (uVar11 < 0x7ffffffffd) {
        if ((uVar17 >> 0x1d & 1) == 0) {
          uVar11 = daif;
          if ((uVar11 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar13[1];
          InstructionSynchronizationBarrier();
          daif = uVar11;
        }
        sVar9 = __arch_copy_from_user(&local_100,uVar19 & 0xff7fffffffffffff,4);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar19 = daif;
          if ((uVar19 & 0x80) == 0) {
            uVar11 = daif;
            daif = uVar11 | 0xc0;
          }
          uVar11 = ttbr1_el1;
          ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar11 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar19;
        }
        if (sVar9 != 0) goto LAB_001101e0;
      }
      else {
        sVar9 = 4;
LAB_001101e0:
        memset(local_b0 + (-0x4c - sVar9),0,sVar9);
        uVar19 = sVar9 & 0xffffffff;
        if ((int)sVar9 != 0) goto LAB_0010fd7c;
      }
      uVar19 = fastrpc_create_persistent_headers(param_1,local_100 & 0xffffffff);
      goto LAB_0010fd78;
    }
    break;
  case 3:
    if ((uint)param_2[4] < 0xd) {
      if (param_1 != 0) {
        uVar11 = *(ulong *)(param_2 + 2);
        lVar14 = param_1 + 0x1c8;
        lVar1 = param_1 + 0x1e0;
        lVar5 = sp_el0;
        if (*(int *)(param_1 + 0x1c0) == 0) goto LAB_0010f684;
        do {
          uVar19 = 0;
LAB_0010f6ec:
          if (*(char *)(param_1 + 0x2a8) != '\0') {
            uVar19 = 0xfffffff2;
            goto LAB_0010fba4;
          }
          if (0 < *(int *)(param_1 + 0xe0)) goto LAB_0010fba0;
          if ((int)uVar19 != 0) goto LAB_0010fba4;
          uVar10 = _raw_spin_lock_irqsave(lVar1);
          plVar21 = *(long **)(param_1 + 0x58);
          if (plVar21 == (long *)(param_1 + 0x58)) {
            _raw_spin_unlock_irqrestore(lVar1,uVar10);
          }
          else {
            uVar19 = __list_del_entry_valid(plVar21);
            if ((uVar19 & 1) != 0) {
              lVar22 = *plVar21;
              plVar12 = (long *)plVar21[1];
              *(long **)(lVar22 + 8) = plVar12;
              *plVar12 = lVar22;
            }
            *plVar21 = (long)plVar21;
            plVar21[1] = (long)plVar21;
            piVar2 = (int *)(param_1 + 0x1c0);
            Hint_Prefetch(piVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar4) {
                *piVar2 = *piVar2 + -1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            _raw_spin_unlock_irqrestore(lVar1,uVar10);
            if (plVar21 != (long *)0x0) {
              local_100 = plVar21[2];
              local_f8 = CONCAT44(local_f8._4_4_,(int)plVar21[3]);
              kfree(plVar21);
              puVar13 = (undefined8 *)sp_el0;
              if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                 (uVar15 = uVar11, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                uVar15 = uVar11 & (long)(uVar11 << 8) >> 8;
              }
              uVar19 = 0xc;
              if (uVar15 < 0x7ffffffff5) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar19 = daif;
                  if ((uVar19 & 0x80) == 0) {
                    uVar15 = daif;
                    daif = uVar15 | 0xc0;
                  }
                  puVar13 = (undefined8 *)puVar13[1];
                  uVar15 = ttbr1_el1;
                  ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar13;
                  InstructionSynchronizationBarrier();
                  daif = uVar19;
                }
                uVar19 = __arch_copy_to_user(puVar13,uVar11 & 0xff7fffffffffffff,&local_100,0xc);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar11 = daif;
                  if ((uVar11 & 0x80) == 0) {
                    uVar15 = daif;
                    daif = uVar15 | 0xc0;
                  }
                  uVar15 = ttbr1_el1;
                  ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar15 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar11;
                }
              }
              goto LAB_0010fb98;
            }
          }
          _printk(&DAT_0014e855,0xe67,lVar5 + 0x848,"fastrpc_wait_on_notif_queue");
        } while (*(int *)(param_1 + 0x1c0) != 0);
LAB_0010f684:
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        init_wait_entry(&local_98,0);
        uVar19 = prepare_to_wait_event(lVar14,&local_98,1);
        if (*(int *)(param_1 + 0x1c0) == 0) {
          do {
            if (uVar19 != 0) goto LAB_0010f6ec;
            schedule();
            uVar19 = prepare_to_wait_event(lVar14,&local_98,1);
          } while (*(int *)(param_1 + 0x1c0) == 0);
        }
        finish_wait(lVar14,&local_98);
        uVar19 = 0;
        goto LAB_0010f6ec;
      }
LAB_0010fba0:
      uVar19 = 0xfffffff7;
LAB_0010fba4:
      kfree(0);
      uVar19 = uVar19 & 0xffffffff;
      goto LAB_0010fd7c;
    }
    break;
  case 4:
    uVar19 = (ulong)(uint)param_2[4];
    if ((uint)param_2[4] < 9) {
      uVar11 = *(ulong *)(param_2 + 2);
      __check_object_size(&local_100,uVar19,0);
      puVar13 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
         (uVar15 = uVar11, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
        uVar15 = uVar11 & (long)(uVar11 << 8) >> 8;
      }
      uVar8 = uVar19;
      if (uVar15 <= 0x8000000000 - uVar19) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar15 = daif;
          if ((uVar15 & 0x80) == 0) {
            uVar8 = daif;
            daif = uVar8 | 0xc0;
          }
          puVar13 = (undefined8 *)puVar13[1];
          uVar8 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar13;
          InstructionSynchronizationBarrier();
          daif = uVar15;
        }
        uVar8 = __arch_copy_from_user(puVar13,&local_100,uVar11 & 0xff7fffffffffffff,uVar19);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar11 = daif;
          if ((uVar11 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar11;
        }
      }
      if (uVar8 != 0) {
        memset(local_b0 + (uVar19 - uVar8) + -0x50,0,uVar8);
        uVar19 = uVar8 & 0xffffffff;
        if ((int)uVar8 != 0) goto LAB_0010fd7c;
      }
      uVar19 = 0;
      *(undefined4 *)(param_1 + 0x2ac) = (undefined4)local_100;
      *(undefined4 *)(param_1 + 0x2b0) = local_100._4_4_;
      goto LAB_0010fd7c;
    }
    break;
  case 5:
    uVar19 = (ulong)(uint)param_2[4];
    if ((uint)param_2[4] < 0x11) {
      pvVar20 = *(void **)(param_2 + 2);
      if ((param_3 & 1) == 0) {
        __check_object_size(&local_100,uVar19,0);
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (pvVar16 = pvVar20, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          pvVar16 = (void *)((ulong)pvVar20 & ((long)pvVar20 << 8) >> 8);
        }
        uVar11 = uVar19;
        if (pvVar16 <= (void *)(0x8000000000 - uVar19)) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar15 = daif;
              daif = uVar15 | 0xc0;
            }
            puVar13 = (undefined8 *)puVar13[1];
            uVar15 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13;
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          uVar11 = __arch_copy_from_user
                             (puVar13,&local_100,(ulong)pvVar20 & 0xff7fffffffffffff,uVar19);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar8 = daif;
              daif = uVar8 | 0xc0;
            }
            uVar8 = ttbr1_el1;
            ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar8 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
        }
        if (uVar11 != 0) {
          memset(local_b0 + (uVar19 - uVar11) + -0x50,0,uVar11);
          uVar19 = uVar11 & 0xffffffff;
          if ((int)uVar11 != 0) goto LAB_0010fd7c;
        }
      }
      else {
        memmove(&local_100,pvVar20,uVar19);
      }
      uVar19 = fastrpc_set_session_info(&local_100,*(undefined8 *)(param_2 + 2),param_1);
      goto LAB_0010fd78;
    }
    break;
  default:
    uVar19 = 0xffffffe7;
    goto LAB_0010fd7c;
  }
  uVar19 = 0xffffffcc;
LAB_0010fd7c:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar19 & 0xffffffff;
LAB_0010f868:
  _printk(&DAT_0014c823,0xe26,lVar5 + 0x848,"fastrpc_wait_on_async_queue");
  iVar7 = *(int *)(param_1 + 0x198);
  goto joined_r0x0010f860;
}



//------------------------------------------------------------
// fastrpc_create_persistent_headers @ 001104d8 size=600
// signature: undefined fastrpc_create_persistent_headers(void)
// callers: [fastrpc_internal_invoke2]
//------------------------------------------------------------

int fastrpc_create_persistent_headers(long param_1,uint param_2)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined4 uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  undefined8 extraout_x1;
  uint uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined8 local_114;
  undefined4 local_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined4 **ppuStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 *local_a8;
  undefined8 uStack_a0;
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  iVar5 = 0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_128 = 0;
  if ((param_2 == 0) || (*(long *)(param_1 + 0x80) != 0)) goto LAB_00110688;
  uVar7 = param_2;
  if (0x18 < param_2) {
    uVar7 = 0x19;
  }
  uVar10 = (ulong)uVar7;
  iVar5 = fastrpc_buf_alloc(param_1,uVar10 << 0xc,0,0,0,&local_128);
  uVar4 = local_128;
  if (iVar5 == 0) {
    local_118 = *(undefined4 *)(param_1 + 0xbc);
    local_a8 = &local_118;
    local_114 = 0xffffffff;
    local_10c = 0x4000;
    local_f8 = *(undefined8 *)(local_128 + 0x40);
    uStack_f0 = *(undefined8 *)(local_128 + 0x48);
    uStack_a0 = 0x20;
    local_98 = &local_f8;
    local_108 = 0;
    uStack_100 = 0x10;
    local_78 = &local_120;
    lVar11 = *(long *)(local_128 + 0x38);
    local_120 = 0;
    uStack_90 = 0x10;
    uStack_80 = 0;
    ppuStack_e0 = &local_a8;
    uStack_70 = 8;
    puVar1 = (undefined8 *)(local_128 + 0x58);
    local_b8 = 0;
    uStack_b0 = 0;
    local_e8 = 0xa03010000000001;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_88 = local_98;
    iVar5 = fastrpc_internal_invoke(param_1,extraout_x1,1,&local_e8);
    if ((puVar1 == (undefined8 *)0x0) || (iVar5 != 0)) {
      if (iVar5 != 0) goto LAB_001106d0;
    }
    else {
      *puVar1 = local_120;
    }
    lVar6 = __kmalloc(uVar10 * 0x90,0xdc0);
    if (lVar6 != 0) {
      _raw_spin_lock(param_1 + 0x10);
      lVar8 = 0;
      lVar9 = 0x38;
      *(uint *)(param_1 + 0x7c) = uVar7;
      *(ulong *)(param_1 + 0x80) = uVar4;
      *(long *)(param_1 + 0x88) = lVar6;
      do {
        uVar10 = uVar10 - 1;
        plVar2 = (long *)(*(long *)(param_1 + 0x88) + lVar9);
        lVar9 = lVar9 + 0x90;
        plVar2[-1] = param_1;
        *plVar2 = lVar11 + lVar8;
        lVar6 = lVar8 + *(long *)(uVar4 + 0x40);
        lVar8 = lVar8 + 0x1000;
        plVar2[1] = lVar6;
        plVar2[2] = 0x1000;
        plVar2[3] = *(long *)(uVar4 + 0x50);
        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(uVar4 + 0x60);
        uVar3 = *(undefined4 *)(uVar4 + 100);
        *(undefined1 *)(plVar2 + 6) = 0;
        *(undefined4 *)((long)plVar2 + 0x2c) = uVar3;
      } while (uVar10 != 0);
      _raw_spin_unlock(param_1 + 0x10);
      iVar5 = 0;
      goto LAB_00110688;
    }
    iVar5 = -0xc;
  }
LAB_001106d0:
  lVar11 = sp_el0;
  _printk(&DAT_0014ba79,0xf08,lVar11 + 0x848,"fastrpc_create_persistent_headers",uVar10 << 0xc,
          0x4000,param_2,uVar10,iVar5);
  *(undefined8 *)(param_1 + 0x7c) = 0;
  *(undefined8 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
    fastrpc_buf_free(uVar4,0);
  }
LAB_00110688:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// fastrpc_set_session_info @ 00110730 size=544
// signature: undefined fastrpc_set_session_info(void)
// callers: [fastrpc_internal_invoke2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fastrpc_set_session_info(long param_1,ulong param_2,long param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  int iVar5;
  ulong uVar6;
  
  puVar1 = (undefined8 *)sp_el0;
  if (*(char *)(param_3 + 0x2b5) == '\0') {
    if (*(int *)((long)puVar1 + 0x634) != *(int *)(param_3 + 0xb4)) {
      *(undefined1 *)(param_3 + 0x1ec) = 1;
    }
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 - 9U < 0xfffffff8) {
      puVar4 = &DAT_0014f982;
      uVar3 = 0xea5;
    }
    else {
      if ((*(char *)(param_3 + 0x1ec) == '\0') || (iVar5 == 7)) {
        if (DAT_00150698 != '\0') {
          *(int *)(param_3 + 0xec) = iVar5;
          iVar5 = *(int *)(param_1 + 8);
        }
        if (iVar5 == 3) {
          *(undefined4 *)(param_3 + 0xe8) = 1;
        }
        if (DAT_001506a4 <= *(uint *)(param_1 + 4)) {
          _printk(&DAT_0014ced3,0xebc,puVar1 + 0x109,"fastrpc_set_session_info");
          return 0xffffffcb;
        }
        *(uint *)(param_3 + 0xb0) = *(uint *)(param_1 + 4);
        *(undefined1 *)(param_3 + 0x2b4) = 1;
        uVar3 = fastrpc_get_info(param_3,param_1);
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
           (uVar6 = param_2, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
          uVar6 = param_2 & (long)(param_2 << 8) >> 8;
        }
        if (0x7ffffffff0 < uVar6) {
          return 0x10;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar6 = daif;
          if ((uVar6 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar1[1];
          InstructionSynchronizationBarrier();
          daif = uVar6;
        }
        uVar3 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,param_1,0x10);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) != 0) {
          return uVar3;
        }
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
        return uVar3;
      }
      puVar4 = &DAT_0014d675;
      uVar3 = 0xeac;
    }
    _printk(puVar4,uVar3,puVar1 + 0x109,"fastrpc_set_session_info");
  }
  else {
    _printk(&DAT_0014bfbf,0xe95,puVar1 + 0x109,"fastrpc_set_session_info");
  }
  return 0xffffffcb;
}



//------------------------------------------------------------
// fastrpc_init_process @ 0011096c size=840
// signature: undefined fastrpc_init_process(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fastrpc_init_process(long param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  ulong uVar10;
  char *__s1;
  ulong uVar11;
  ulong uVar12;
  
  uVar1 = param_2[4];
  if ((uVar1 >> 0x15 != 0) || (0xc800000 < (uint)param_2[8])) {
    lVar3 = sp_el0;
    _printk(&DAT_0014d021,0x1202,lVar3 + 0x848,"fastrpc_init_process",(ulong)uVar1,param_2[8],
            0x200000,0xc800000);
    return 0xffffffe5;
  }
  uVar2 = *(uint *)(param_1 + 0xc0);
  if (4 < uVar2) {
    return 0xffffffd4;
  }
  if ((((*(char *)(gfa + (ulong)uVar2 * 0x6a68 + 0xa24) != '\0') && (*(int *)(param_1 + 0x170) == 0)
       ) && (*(int *)(gfa + (ulong)uVar2 * 0x6a68 + 0xa20) != 0)) &&
     (*(char *)(param_1 + 0x22c) == '\0')) {
    return 0xffffff91;
  }
  iVar5 = *param_2;
  if (*(int *)(param_1 + 0xe8) == 1) {
    if (iVar5 != 3) {
      return 0xfffffff3;
    }
LAB_00110a10:
    __s1 = (char *)0x0;
    if (uVar2 == 0) {
      pcVar8 = "sensors_pdr_adsprpc";
    }
    else {
      if (uVar2 != 2) goto LAB_00110bc0;
      __s1 = (char *)0x0;
      pcVar8 = "sensors_pdr_sdsprpc";
    }
  }
  else {
    if (iVar5 != 2) {
      if (iVar5 != 3) goto LAB_00110bac;
      goto LAB_00110a10;
    }
    if (uVar1 == 0) {
LAB_00110bac:
      __s1 = (char *)0x0;
      goto LAB_00110bc0;
    }
    __s1 = (char *)__kmalloc((ulong)uVar1 + 1,0xdc0);
    if ((__s1 == (char *)0x0) || ((char *)0xfffffffffffff000 < __s1)) goto LAB_00110bc0;
    uVar11 = (ulong)(uint)param_2[4];
    if (param_2[4] < 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x110c78);
      (*pcVar4)();
    }
    uVar12 = *(ulong *)(param_2 + 2);
    __check_object_size(__s1,uVar11,0);
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = uVar12, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar10 = uVar12 & (long)(uVar12 << 8) >> 8;
    }
    uVar6 = uVar11;
    if (uVar10 <= 0x8000000000 - uVar11) {
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
      uVar6 = __arch_copy_from_user(puVar9,__s1,uVar12 & 0xff7fffffffffffff,uVar11);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
    }
    if (((uVar6 != 0) && (memset(__s1 + (uVar11 - uVar6),0,uVar6), (int)uVar6 != 0)) ||
       (iVar5 = strcmp(__s1,"audiopd"), iVar5 != 0)) goto LAB_00110bc0;
    pcVar8 = "audio_pdr_adsprpc";
  }
  *(char **)(param_1 + 0xd8) = pcVar8;
LAB_00110bc0:
  kfree(__s1);
  uVar7 = fastrpc_set_tvm_remote_domain(param_1,param_2);
  if (((int)uVar7 == 0) && (uVar7 = fastrpc_channel_open(param_1,*param_2), (int)uVar7 == 0)) {
    *(int *)(param_1 + 0x21c) = *param_2;
    switch(*param_2) {
    case 0:
    case 3:
      uVar7 = fastrpc_init_attach_process(param_1,param_2);
      break;
    case 1:
      uVar7 = fastrpc_init_create_dynamic_process(param_1,param_2);
      break;
    case 2:
      uVar7 = fastrpc_init_create_static_process(param_1,param_2);
      break;
    default:
      return 0xffffffe7;
    }
    if ((int)uVar7 == 0) {
      *(undefined4 *)(param_1 + 0xe4) = 1;
      uVar7 = fastrpc_device_create(param_1);
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// fastrpc_channel_open @ 00110cd0 size=480
// signature: undefined fastrpc_channel_open(void)
// callers: [fastrpc_get_info_from_kernel, fastrpc_get_info_from_dsp, fastrpc_init_process]
//------------------------------------------------------------

int fastrpc_channel_open(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x68) == 0)) ||
     (uVar1 = *(uint *)(param_1 + 0xc0), 4 < uVar1)) {
    lVar3 = sp_el0;
    _printk(&DAT_0014deab,0x1936,lVar3 + 0x848,"fastrpc_channel_open",lVar3 + 0x848);
    iVar2 = -0x35;
  }
  else {
    iVar2 = fastrpc_wait_for_transport_interrupt(uVar1);
    if (iVar2 == 0) {
      iVar2 = verify_transport_device(uVar1,*(undefined4 *)(param_1 + 0xc4));
      if (iVar2 == 0) {
        mutex_lock(gfa + (ulong)uVar1 * 0x6a68 + 0x9a0);
        lVar3 = gfa;
        lVar4 = gfa + (ulong)uVar1 * 0x6a68;
        if ((*(long *)(lVar4 + 0x9d8) == *(long *)(lVar4 + 0x9f0)) ||
           (*(int *)(gfa + (ulong)uVar1 * 0x6a68 + 0x9f8) == 2)) {
          *(long *)(param_1 + 200) = *(long *)(lVar4 + 0x9d8);
          if ((uVar1 == 0) && (*(long *)(lVar4 + 0x9d8) != *(long *)(lVar4 + 0x9f0))) {
            mutex_unlock(lVar3 + 0x9a0);
            mutex_lock(param_1 + 0x110);
            iVar2 = fastrpc_dsp_restart_handler(param_1,1,1);
            mutex_unlock(param_1 + 0x110);
            if (iVar2 != 0) {
              lVar3 = sp_el0;
              _printk(&DAT_0014c40e,0x195a,lVar3 + 0x848,"fastrpc_channel_open",
                      *(undefined8 *)(gfa + 8),iVar2);
            }
            mutex_lock(gfa + 0x9a0);
            *(undefined8 *)(gfa + 0x9f0) = *(undefined8 *)(gfa + 0x9d8);
            lVar3 = gfa;
          }
          else {
            iVar2 = 0;
          }
          *(undefined4 *)(lVar3 + (ulong)uVar1 * 0x6a68 + 0x9e0) = 0;
          mutex_unlock(gfa + (ulong)uVar1 * 0x6a68 + 0x9a0);
        }
        else {
          mutex_unlock(gfa + (ulong)uVar1 * 0x6a68 + 0x9a0);
          iVar2 = -0x6f;
        }
      }
      else {
        iVar2 = -0x6f;
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// fastrpc_init_attach_process @ 00110eb0 size=444
// signature: undefined fastrpc_init_attach_process(void)
// callers: [fastrpc_init_process]
//------------------------------------------------------------

ulong fastrpc_init_attach_process(long param_1,int *param_2)

{
  uint uVar1;
  long lVar2;
  char *__string;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  bool bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  size_t sVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 extraout_x1;
  long lVar16;
  undefined4 uVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  undefined1 auVar21 [16];
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  long lStack_210;
  long lStack_208;
  long lStack_200;
  undefined8 uStack_1f8;
  undefined8 **ppuStack_1f0;
  undefined8 *puStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 *puStack_1a0;
  undefined8 uStack_198;
  char *pcStack_190;
  ulong uStack_188;
  undefined8 uStack_180;
  ulong uStack_178;
  undefined8 *puStack_170;
  undefined8 uStack_168;
  undefined8 *puStack_160;
  undefined8 uStack_158;
  long lStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  long lStack_120;
  long lStack_110;
  code *pcStack_108;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 uStack_50;
  char *local_48;
  ulong uStack_40;
  undefined8 local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar17 = *(undefined4 *)(param_1 + 0xbc);
  local_48 = (char *)0x0;
  uStack_40 = 0;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  local_60 = 0;
  local_64 = uVar17;
  if (*(int *)(param_1 + 0x170) == 0) {
    lVar2 = sp_el0;
    _printk(&DAT_0014da24,0xfd6,lVar2 + 0x848,"fastrpc_init_attach_process");
    uVar12 = 0xffffff91;
    goto LAB_00110ff4;
  }
  uVar10 = *(uint *)(param_1 + 0xc0);
  if (4 < uVar10) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x11104c);
    (*pcVar8)();
  }
  if (0x207c4 < (ulong)uVar10 * 0x6a68) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(1,0x111050);
    (*pcVar8)();
  }
  iVar3 = *param_2;
  if ((*(int *)(&DAT_00129fbc + (ulong)uVar10 * 0x6a68) == 0) || (iVar3 != 3)) {
    local_58 = (undefined8 *)&local_64;
    uStack_50 = 4;
    uVar17 = 0;
    if (iVar3 == 0) {
LAB_00110fe0:
      *(undefined4 *)(param_1 + 0xd0) = uVar17;
    }
    else if (iVar3 == 3) goto LAB_00110fdc;
    uVar12 = fastrpc_internal_invoke(param_1);
LAB_00110ff4:
    lVar2 = sp_el0;
    if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar12);
    }
    return uVar12;
  }
  lVar2 = sp_el0;
  sVar11 = strnlen((char *)(lVar2 + 0x848),0x10);
  if (sVar11 < 0x11) {
    if (sVar11 != 0x10) {
      local_58 = &local_60;
      uVar10 = (int)sVar11 + 1;
      uStack_40 = (ulong)uVar10;
      uStack_50 = 8;
      local_60 = CONCAT44(uVar10,uVar17);
      local_48 = (char *)(lVar2 + 0x848);
LAB_00110fdc:
      uVar17 = 2;
      goto LAB_00110fe0;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  auVar21 = fortify_panic("__fortify_strlen");
  lVar15 = auVar21._8_8_;
  lVar13 = auVar21._0_8_;
  pcStack_108 = fastrpc_init_create_dynamic_process;
  lVar19 = sp_el0;
  lVar2 = lVar13 + 0x10;
  lStack_120 = *(long *)(lVar19 + 0x638);
  uStack_1c8 = 0;
  uStack_1c0 = 0;
  uStack_1d8 = 0;
  uStack_1d0 = 0;
  puStack_1e8 = (undefined8 *)0x0;
  uStack_1e0 = 0;
  uStack_1f8 = 0;
  ppuStack_1f0 = (undefined8 **)0x0;
  uStack_130 = 0;
  uStack_128 = 0;
  uStack_140 = 0;
  uStack_138 = 0;
  lStack_208 = 0;
  lStack_200 = 0;
  lStack_150 = 0;
  uStack_148 = 0;
  puStack_160 = (undefined8 *)0x0;
  uStack_158 = 0;
  puStack_170 = (undefined8 *)0x0;
  uStack_168 = 0;
  uStack_180 = 0;
  uStack_178 = 0;
  pcStack_190 = (char *)0x0;
  uStack_188 = 0;
  puStack_1a0 = (undefined8 *)0x0;
  uStack_198 = 0;
  uStack_1b0 = 0;
  uStack_1a8 = 0;
  uStack_1b8 = 0;
  uStack_218 = 0;
  lStack_210 = 0;
  uStack_228 = 0;
  uStack_220 = 0;
  lStack_110 = (long)register0x00000008 + -0x30;
  _raw_spin_lock(lVar2);
  if (*(int *)(lVar13 + 0x228) == 0) {
    *(undefined4 *)(lVar13 + 0x228) = 1;
    uVar10 = *(uint *)(lVar15 + 0x20);
    if (uVar10 == 0) {
      uVar10 = 0x300000;
LAB_00111164:
      _raw_spin_unlock(lVar2);
      puVar6 = (undefined8 *)sp_el0;
      __string = (char *)(puVar6 + 0x109);
      uStack_228 = CONCAT44(uStack_228._4_4_,*(undefined4 *)(lVar13 + 0xbc));
      sVar11 = strnlen(__string,0x10);
      if (sVar11 < 0x11) {
        if (sVar11 != 0x10) {
          uVar4 = *(uint *)(lVar15 + 0x10);
          uVar1 = (int)sVar11 + 1;
          *(undefined4 *)(lVar13 + 0xd0) = 1;
          uStack_228 = CONCAT44(uVar1,(undefined4)uStack_228);
          uStack_220 = CONCAT44(uStack_220._4_4_,uVar4);
          if ((*(byte *)(lVar15 + 0x28) >> 3 & 1) != 0) {
            *(undefined1 *)(lVar13 + 0x22c) = 1;
          }
          uVar12 = *(ulong *)(lVar15 + 8);
          if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) || (((uint)*puVar6 >> 0x1a & 1) != 0)
             ) {
            uVar12 = uVar12 & (long)(uVar12 << 8) >> 8;
          }
          if (0x8000000000 - (ulong)*(uint *)(lVar15 + 0x10) < uVar12) {
            uVar12 = 0xffffffff;
            goto LAB_00111554;
          }
          if (*(uint *)(lVar15 + 0x10) == 0) {
            lVar19 = 0;
LAB_00111240:
            uVar9 = *(uint *)(lVar15 + 0x28) & 0xfffdffff;
            uStack_220 = CONCAT44(1,(undefined4)uStack_220);
            *(uint *)(lVar15 + 0x28) = uVar9;
            if (*(char *)(lVar13 + 0x1ec) == '\0') {
              uVar9 = uVar9 | (uint)(*(char *)(lVar13 + 0x22c) != '\0') << 0x11;
            }
            else if (*(char *)(lVar13 + 0x22c) == '\0') {
              _printk(&DAT_001500bf,0x1064,__string,"fastrpc_init_create_dynamic_process");
              uVar12 = 0xffffff91;
              goto joined_r0x00111284;
            }
            *(uint *)(lVar15 + 0x28) = uVar9 & 0xffffffbf;
            if ((*(uint *)(lVar13 + 400) != 0) && ((ulong)DAT_00150620 != 0)) {
              uVar18 = 0;
              uVar12 = 0;
              do {
                uVar9 = *(uint *)(*(long *)(lVar13 + 0x188) + uVar12 * 4);
                uVar5 = *(uint *)(DAT_00150618 + uVar18 * 4);
                if (uVar9 < uVar5) {
                  uVar12 = uVar12 + 1;
                }
                else {
                  if (uVar9 == uVar5) {
                    if (uVar9 != 0) {
                      _printk(&DAT_0014fd7b,0x1078,__string,"fastrpc_init_create_dynamic_process",
                              *(undefined4 *)(lVar13 + 0xb8));
                      *(uint *)(lVar15 + 0x28) = *(uint *)(lVar15 + 0x28) | 0x40;
                      lVar16 = *(long *)(lVar15 + 0x18);
                      goto joined_r0x0011160c;
                    }
                    break;
                  }
                  uVar18 = uVar18 + 1;
                }
                if ((*(uint *)(lVar13 + 400) <= uVar12) || (DAT_00150620 <= uVar18)) break;
              } while( true );
            }
            lVar16 = *(long *)(lVar15 + 0x18);
joined_r0x0011160c:
            if (lVar16 == 0) {
              if (*(char *)(lVar13 + 0x22c) != '\0') {
                uVar10 = 0x500000;
              }
              uVar9 = *(int *)(lVar15 + 0x10) * 4;
              if (uVar10 <= uVar9) {
                uVar10 = uVar9;
              }
              auVar21 = fastrpc_buf_alloc(lVar13,(long)(int)(uVar10 + 0xfffff & 0xfff00000),0x20010,
                                          0,2,&lStack_208);
              lVar16 = lStack_208;
              uVar14 = auVar21._8_8_;
              uVar12 = auVar21._0_8_;
              if (auVar21._0_4_ == 0) {
                uStack_220 = CONCAT44(1,(undefined4)uStack_220);
                *(long *)(lVar13 + 0x70) = lStack_208;
                if ((*(int *)(lVar13 + 0x2ac) == -1) || (*(int *)(lVar13 + 0x2b0) == 0)) {
                  lVar20 = 0;
                  bVar7 = false;
                  uStack_168 = 0x10;
                }
                else {
                  mutex_lock();
                  uVar10 = fastrpc_mmap_create(lVar13,*(undefined4 *)(lVar13 + 0x2ac),0,0,0,
                                               (long)*(int *)(lVar13 + 0x2b0),0,&lStack_210);
                  lVar20 = lStack_210;
                  uVar12 = (ulong)uVar10;
                  if (lStack_210 != 0) {
                    *(undefined1 *)(lStack_210 + 0xb8) = 1;
                  }
                  mutex_unlock(lVar13 + 0x110);
                  if (uVar10 != 0) goto joined_r0x00111284;
                  bVar7 = true;
                  uStack_168 = 0x20;
                  uStack_220 = CONCAT44(2,(undefined4)uStack_220);
                  uVar14 = extraout_x1;
                }
                puStack_1a0 = &uStack_228;
                uStack_198 = 0x18;
                uStack_180 = *(undefined8 *)(lVar15 + 8);
                uStack_1b8 = 0xffffffffffffffff;
                uStack_140 = *(undefined8 *)(lVar16 + 0x40);
                uStack_138 = *(undefined8 *)(lVar16 + 0x48);
                if (bVar7) {
                  uStack_130 = *(undefined8 *)(lVar20 + 0x48);
                  uStack_128 = *(undefined8 *)(lVar20 + 0x50);
                }
                puStack_170 = &uStack_140;
                puStack_160 = &uStack_218;
                lStack_150 = (long)&uStack_218 + 4;
                uStack_1a8 = 0xffffffffffffffff;
                uStack_1b0 = CONCAT44(0xffffffff,*(undefined4 *)(lVar15 + 0x14));
                uStack_218 = *(undefined8 *)(lVar15 + 0x28);
                uStack_158 = 4;
                uStack_148 = 4;
                ppuStack_1f0 = &puStack_1a0;
                puStack_1e8 = &uStack_1b8;
                uVar17 = 0x6040000;
                if (*(int *)(lVar15 + 0x28) != 0) {
                  uVar17 = 0x7040000;
                }
                uStack_1e0 = 0;
                uStack_1d8 = 0;
                uStack_1d0 = 0;
                uStack_1c8 = 0;
                uStack_1f8 = CONCAT44(uVar17,1);
                uStack_1c0 = 0;
                pcStack_190 = __string;
                uStack_188 = (ulong)uVar1;
                uStack_178 = (ulong)uVar4;
                uVar12 = fastrpc_internal_invoke(lVar13,uVar14,1,&uStack_1f8);
              }
              uVar12 = uVar12 & 0xffffffff;
            }
            else {
              _printk(&DAT_0014cf15,0x1084,__string,"fastrpc_init_create_dynamic_process");
              uVar12 = 0xffffffea;
            }
          }
          else {
            mutex_lock(lVar13 + 0x110);
            uVar9 = fastrpc_mmap_create(lVar13,*(undefined4 *)(lVar15 + 0x14),0,0,
                                        *(undefined8 *)(lVar15 + 8),*(undefined4 *)(lVar15 + 0x10),0
                                        ,&lStack_200);
            lVar19 = lStack_200;
            uVar12 = (ulong)uVar9;
            if (lStack_200 != 0) {
              *(undefined1 *)(lStack_200 + 0xb8) = 1;
            }
            mutex_unlock(lVar13 + 0x110);
            if (uVar9 == 0) goto LAB_00111240;
          }
joined_r0x00111284:
          if (lVar19 != 0) {
            mutex_lock(lVar13 + 0x110);
            fastrpc_mmap_free(lVar19,0);
            mutex_unlock(lVar13 + 0x110);
          }
          _raw_spin_lock(lVar2);
          if ((int)uVar12 == 0) {
            *(undefined4 *)(lVar13 + 0x228) = 2;
            _raw_spin_unlock(lVar2);
            goto LAB_001114e4;
          }
          goto LAB_0011155c;
        }
      }
      else {
        fortify_panic("strnlen");
      }
      fortify_panic("__fortify_strlen");
      goto LAB_00111650;
    }
    if (0xf3affffe < uVar10 + 0xf37fffff) goto LAB_00111164;
    lVar19 = sp_el0;
    _printk(&DAT_0014c547,0x1036,lVar19 + 0x848,"fastrpc_init_create_dynamic_process",uVar10,
            0x300000,0xc800000);
    _raw_spin_unlock(lVar2);
    uVar12 = 0xffffffea;
LAB_00111554:
    _raw_spin_lock(lVar2);
LAB_0011155c:
    lVar19 = sp_el0;
    _printk(&DAT_0014e67e,0x10ee,lVar19 + 0x848,"fastrpc_init_create_dynamic_process",uVar12);
    *(undefined4 *)(lVar13 + 0x228) = 0;
    _raw_spin_unlock(lVar2);
    uVar14 = _raw_spin_lock_irqsave(&DAT_001505c8);
    uVar18 = *(ulong *)(lVar13 + 0x70);
    if ((uVar18 == 0) || (0xfffffffffffff000 < uVar18)) {
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar14);
    }
    else {
      *(undefined8 *)(lVar13 + 0x70) = 0;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar14);
      fastrpc_buf_free(uVar18,0);
    }
  }
  else {
    lVar19 = sp_el0;
    _printk(&DAT_0014fd39,0x102c,lVar19 + 0x848,"fastrpc_init_create_dynamic_process");
    _raw_spin_unlock(lVar2);
    uVar12 = 0xffffff8e;
  }
LAB_001114e4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) == lStack_120) {
    return uVar12;
  }
LAB_00111650:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// fastrpc_init_create_dynamic_process @ 0011106c size=1512
// signature: undefined fastrpc_init_create_dynamic_process(void)
// callers: [fastrpc_init_process]
//------------------------------------------------------------

ulong fastrpc_init_create_dynamic_process(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  char *__string;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  bool bVar6;
  size_t sVar7;
  undefined8 uVar8;
  undefined8 extraout_x1;
  uint uVar9;
  uint uVar10;
  long lVar11;
  undefined4 uVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  undefined1 auVar17 [16];
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  long local_160;
  long local_158;
  long local_150;
  undefined8 local_148;
  undefined8 **local_140;
  undefined8 *local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined8 uStack_e8;
  char *local_e0;
  ulong uStack_d8;
  undefined8 local_d0;
  ulong uStack_c8;
  undefined8 *local_c0;
  undefined8 uStack_b8;
  undefined8 *local_b0;
  undefined8 uStack_a8;
  long local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar14 = sp_el0;
  lVar2 = param_1 + 0x10;
  local_70 = *(long *)(lVar14 + 0x638);
  local_118 = 0;
  local_110 = 0;
  local_128 = 0;
  local_120 = 0;
  local_138 = (undefined8 *)0x0;
  local_130 = 0;
  local_148 = 0;
  local_140 = (undefined8 **)0x0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_158 = 0;
  local_150 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = (undefined8 *)0x0;
  uStack_a8 = 0;
  local_c0 = (undefined8 *)0x0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = (char *)0x0;
  uStack_d8 = 0;
  local_f0 = (undefined8 *)0x0;
  uStack_e8 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_168 = 0;
  local_160 = 0;
  local_178 = 0;
  uStack_170 = 0;
  _raw_spin_lock(lVar2);
  if (*(int *)(param_1 + 0x228) == 0) {
    *(undefined4 *)(param_1 + 0x228) = 1;
    uVar10 = *(uint *)(param_2 + 0x20);
    if (uVar10 == 0) {
      uVar10 = 0x300000;
LAB_00111164:
      _raw_spin_unlock(lVar2);
      puVar5 = (undefined8 *)sp_el0;
      __string = (char *)(puVar5 + 0x109);
      local_178 = CONCAT44(local_178._4_4_,*(undefined4 *)(param_1 + 0xbc));
      sVar7 = strnlen(__string,0x10);
      if (sVar7 < 0x11) {
        if (sVar7 != 0x10) {
          uVar3 = *(uint *)(param_2 + 0x10);
          uVar1 = (int)sVar7 + 1;
          *(undefined4 *)(param_1 + 0xd0) = 1;
          local_178 = CONCAT44(uVar1,(undefined4)local_178);
          uStack_170 = CONCAT44(uStack_170._4_4_,uVar3);
          if ((*(byte *)(param_2 + 0x28) >> 3 & 1) != 0) {
            *(undefined1 *)(param_1 + 0x22c) = 1;
          }
          uVar16 = *(ulong *)(param_2 + 8);
          if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) || (((uint)*puVar5 >> 0x1a & 1) != 0)
             ) {
            uVar16 = uVar16 & (long)(uVar16 << 8) >> 8;
          }
          if (0x8000000000 - (ulong)*(uint *)(param_2 + 0x10) < uVar16) {
            uVar16 = 0xffffffff;
            goto LAB_00111554;
          }
          if (*(uint *)(param_2 + 0x10) == 0) {
            lVar14 = 0;
LAB_00111240:
            uVar9 = *(uint *)(param_2 + 0x28) & 0xfffdffff;
            uStack_170 = CONCAT44(1,(undefined4)uStack_170);
            *(uint *)(param_2 + 0x28) = uVar9;
            if (*(char *)(param_1 + 0x1ec) == '\0') {
              uVar9 = uVar9 | (uint)(*(char *)(param_1 + 0x22c) != '\0') << 0x11;
            }
            else if (*(char *)(param_1 + 0x22c) == '\0') {
              _printk(&DAT_001500bf,0x1064,__string,"fastrpc_init_create_dynamic_process");
              uVar16 = 0xffffff91;
              goto joined_r0x00111284;
            }
            *(uint *)(param_2 + 0x28) = uVar9 & 0xffffffbf;
            if ((*(uint *)(param_1 + 400) != 0) && ((ulong)DAT_00150620 != 0)) {
              uVar13 = 0;
              uVar16 = 0;
              do {
                uVar9 = *(uint *)(*(long *)(param_1 + 0x188) + uVar16 * 4);
                uVar4 = *(uint *)(DAT_00150618 + uVar13 * 4);
                if (uVar9 < uVar4) {
                  uVar16 = uVar16 + 1;
                }
                else {
                  if (uVar9 == uVar4) {
                    if (uVar9 != 0) {
                      _printk(&DAT_0014fd7b,0x1078,__string,"fastrpc_init_create_dynamic_process",
                              *(undefined4 *)(param_1 + 0xb8));
                      *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | 0x40;
                      lVar11 = *(long *)(param_2 + 0x18);
                      goto joined_r0x0011160c;
                    }
                    break;
                  }
                  uVar13 = uVar13 + 1;
                }
                if ((*(uint *)(param_1 + 400) <= uVar16) || (DAT_00150620 <= uVar13)) break;
              } while( true );
            }
            lVar11 = *(long *)(param_2 + 0x18);
joined_r0x0011160c:
            if (lVar11 == 0) {
              if (*(char *)(param_1 + 0x22c) != '\0') {
                uVar10 = 0x500000;
              }
              uVar9 = *(int *)(param_2 + 0x10) * 4;
              if (uVar10 <= uVar9) {
                uVar10 = uVar9;
              }
              auVar17 = fastrpc_buf_alloc(param_1,(long)(int)(uVar10 + 0xfffff & 0xfff00000),0x20010
                                          ,0,2,&local_158);
              lVar11 = local_158;
              uVar8 = auVar17._8_8_;
              uVar16 = auVar17._0_8_;
              if (auVar17._0_4_ == 0) {
                uStack_170 = CONCAT44(1,(undefined4)uStack_170);
                *(long *)(param_1 + 0x70) = local_158;
                if ((*(int *)(param_1 + 0x2ac) == -1) || (*(int *)(param_1 + 0x2b0) == 0)) {
                  lVar15 = 0;
                  bVar6 = false;
                  uStack_b8 = 0x10;
                }
                else {
                  mutex_lock();
                  uVar13 = fastrpc_mmap_create(param_1,*(undefined4 *)(param_1 + 0x2ac),0,0,0,
                                               (long)*(int *)(param_1 + 0x2b0),0,&local_160);
                  lVar15 = local_160;
                  uVar16 = uVar13 & 0xffffffff;
                  if (local_160 != 0) {
                    *(undefined1 *)(local_160 + 0xb8) = 1;
                  }
                  mutex_unlock(param_1 + 0x110);
                  if ((int)uVar13 != 0) goto joined_r0x00111284;
                  bVar6 = true;
                  uStack_b8 = 0x20;
                  uStack_170 = CONCAT44(2,(undefined4)uStack_170);
                  uVar8 = extraout_x1;
                }
                local_f0 = &local_178;
                uStack_e8 = 0x18;
                local_d0 = *(undefined8 *)(param_2 + 8);
                local_108 = 0xffffffffffffffff;
                local_90 = *(undefined8 *)(lVar11 + 0x40);
                uStack_88 = *(undefined8 *)(lVar11 + 0x48);
                if (bVar6) {
                  local_80 = *(undefined8 *)(lVar15 + 0x48);
                  uStack_78 = *(undefined8 *)(lVar15 + 0x50);
                }
                local_c0 = &local_90;
                local_b0 = &local_168;
                local_a0 = (long)&local_168 + 4;
                local_f8 = 0xffffffffffffffff;
                local_100 = CONCAT44(0xffffffff,*(undefined4 *)(param_2 + 0x14));
                local_168 = *(undefined8 *)(param_2 + 0x28);
                uStack_a8 = 4;
                uStack_98 = 4;
                local_140 = &local_f0;
                local_138 = &local_108;
                uVar12 = 0x6040000;
                if (*(int *)(param_2 + 0x28) != 0) {
                  uVar12 = 0x7040000;
                }
                local_130 = 0;
                local_128 = 0;
                local_120 = 0;
                local_118 = 0;
                local_148 = CONCAT44(uVar12,1);
                local_110 = 0;
                local_e0 = __string;
                uStack_d8 = (ulong)uVar1;
                uStack_c8 = (ulong)uVar3;
                uVar16 = fastrpc_internal_invoke(param_1,uVar8,1,&local_148);
              }
              uVar16 = uVar16 & 0xffffffff;
            }
            else {
              _printk(&DAT_0014cf15,0x1084,__string,"fastrpc_init_create_dynamic_process");
              uVar16 = 0xffffffea;
            }
          }
          else {
            mutex_lock(param_1 + 0x110);
            uVar13 = fastrpc_mmap_create(param_1,*(undefined4 *)(param_2 + 0x14),0,0,
                                         *(undefined8 *)(param_2 + 8),
                                         *(undefined4 *)(param_2 + 0x10),0,&local_150);
            lVar14 = local_150;
            uVar16 = uVar13 & 0xffffffff;
            if (local_150 != 0) {
              *(undefined1 *)(local_150 + 0xb8) = 1;
            }
            mutex_unlock(param_1 + 0x110);
            if ((int)uVar13 == 0) goto LAB_00111240;
          }
joined_r0x00111284:
          if (lVar14 != 0) {
            mutex_lock(param_1 + 0x110);
            fastrpc_mmap_free(lVar14,0);
            mutex_unlock(param_1 + 0x110);
          }
          _raw_spin_lock(lVar2);
          if ((int)uVar16 == 0) {
            *(undefined4 *)(param_1 + 0x228) = 2;
            _raw_spin_unlock(lVar2);
            goto LAB_001114e4;
          }
          goto LAB_0011155c;
        }
      }
      else {
        fortify_panic("strnlen");
      }
      fortify_panic("__fortify_strlen");
      goto LAB_00111650;
    }
    if (0xf3affffe < uVar10 + 0xf37fffff) goto LAB_00111164;
    lVar14 = sp_el0;
    _printk(&DAT_0014c547,0x1036,lVar14 + 0x848,"fastrpc_init_create_dynamic_process",uVar10,
            0x300000,0xc800000);
    _raw_spin_unlock(lVar2);
    uVar16 = 0xffffffea;
LAB_00111554:
    _raw_spin_lock(lVar2);
LAB_0011155c:
    lVar14 = sp_el0;
    _printk(&DAT_0014e67e,0x10ee,lVar14 + 0x848,"fastrpc_init_create_dynamic_process",uVar16);
    *(undefined4 *)(param_1 + 0x228) = 0;
    _raw_spin_unlock(lVar2);
    uVar8 = _raw_spin_lock_irqsave(&DAT_001505c8);
    uVar13 = *(ulong *)(param_1 + 0x70);
    if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar8);
    }
    else {
      *(undefined8 *)(param_1 + 0x70) = 0;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar8);
      fastrpc_buf_free(uVar13,0);
    }
  }
  else {
    lVar14 = sp_el0;
    _printk(&DAT_0014fd39,0x102c,lVar14 + 0x848,"fastrpc_init_create_dynamic_process");
    _raw_spin_unlock(lVar2);
    uVar16 = 0xffffff8e;
  }
LAB_001114e4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) == local_70) {
    return uVar16;
  }
LAB_00111650:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// fastrpc_init_create_static_process @ 00111654 size=1880
// signature: undefined fastrpc_init_create_static_process(void)
// callers: [fastrpc_init_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fastrpc_init_create_static_process(long param_1,long param_2)

{
  long *plVar1;
  uint *puVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *__s1;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 *puVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  undefined4 *puVar15;
  long lVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  undefined1 auVar21 [16];
  undefined8 local_118;
  ulong local_110;
  undefined8 local_108;
  undefined4 local_100;
  long local_f8 [2];
  undefined8 **ppuStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 *local_b0;
  undefined8 uStack_a8;
  char *local_a0;
  ulong uStack_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long lStack_78;
  long local_70;
  
  lVar13 = gfa;
  lVar16 = sp_el0;
  local_70 = *(long *)(lVar16 + 0x638);
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  iVar7 = *(int *)(param_1 + 0xc0);
  local_e0 = 0;
  uStack_d8 = 0;
  local_f8[1] = 0;
  ppuStack_e8 = (undefined8 **)0x0;
  local_80 = 0;
  lStack_78 = 0;
  local_f8[0] = 0;
  local_90 = (undefined8 *)0x0;
  uStack_88 = 0;
  local_a0 = (char *)0x0;
  uStack_98 = 0;
  local_b0 = (undefined8 *)0x0;
  uStack_a8 = 0;
  local_100 = 0;
  local_108 = 0;
  if (*(int *)(param_1 + 0x170) == 0) {
    lVar16 = sp_el0;
    _printk(&DAT_0014dc7d,0x1126,lVar16 + 0x848,"fastrpc_init_create_static_process");
    uVar17 = 0xffffff91;
    goto LAB_00111a04;
  }
  if (0x800000 < *(uint *)(param_2 + 0x20)) {
    lVar16 = sp_el0;
    _printk(&DAT_0014bb0e,0x112d,lVar16 + 0x848,"fastrpc_init_create_static_process",
            *(uint *)(param_2 + 0x20),0x800000);
    lVar16 = 0;
    __s1 = (char *)0x0;
    uVar17 = 0xffffffe5;
    goto LAB_001119d4;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    __s1 = (char *)0x0;
LAB_00111928:
    kfree(__s1);
    uVar17 = 0;
    goto LAB_00111a04;
  }
  __s1 = (char *)__kmalloc(*(int *)(param_2 + 0x10) + 1,0xdc0);
  lVar16 = 0;
  uVar17 = 0xfffffff4;
  if ((__s1 == (char *)0x0) || ((char *)0xfffffffffffff000 < __s1)) {
LAB_001119d4:
    kfree(__s1);
    DAT_001505b0 = 0;
  }
  else {
    uVar17 = (ulong)*(uint *)(param_2 + 0x10);
    if ((int)*(uint *)(param_2 + 0x10) < 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x111d30);
      (*pcVar4)();
    }
    uVar20 = *(ulong *)(param_2 + 8);
    __check_object_size(__s1,uVar17,0);
    puVar11 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
       (uVar12 = uVar20, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
      uVar12 = uVar20 & (long)(uVar20 << 8) >> 8;
    }
    uVar8 = uVar17;
    if (uVar12 <= 0x8000000000 - uVar17) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar8 = daif;
          daif = uVar8 | 0xc0;
        }
        puVar11 = (undefined8 *)puVar11[1];
        uVar8 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar11 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar11;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      uVar8 = __arch_copy_from_user(puVar11,__s1,uVar20 & 0xff7fffffffffffff,uVar17);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar20 = daif;
        if ((uVar20 & 0x80) == 0) {
          uVar12 = daif;
          daif = uVar12 | 0xc0;
        }
        uVar12 = ttbr1_el1;
        ttbr0_el1 = (uVar12 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar12 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar20;
      }
    }
    if ((uVar8 != 0) && (memset(__s1 + (uVar17 - uVar8),0,uVar8), (int)uVar8 != 0)) {
      lVar16 = 0;
      uVar17 = 0xfffffff2;
      goto LAB_001119d4;
    }
    local_100 = 0;
    *(undefined4 *)(param_1 + 0xd0) = 1;
    local_108 = CONCAT44(*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_1 + 0xbc));
    iVar5 = strcmp(__s1,"audiopd");
    if (iVar5 != 0) {
      lVar16 = sp_el0;
      _printk(&DAT_0014e325,0x1152,lVar16 + 0x848,"fastrpc_init_create_static_process",__s1);
      goto LAB_00111928;
    }
    local_110 = local_110 & 0xffffffff00000000;
    local_118 = CONCAT44(local_118._4_4_,0xffffffff);
    if (param_1 == 0) {
      uVar17 = 0xfffffff7;
LAB_001119d0:
      lVar16 = 0;
      goto LAB_001119d4;
    }
    auVar21 = fastrpc_get_spd_session(*(undefined8 *)(param_1 + 0xd8),&local_110,&local_118);
    uVar20 = local_110;
    uVar9 = auVar21._8_8_;
    uVar17 = auVar21._0_8_ & 0xffffffff;
    if (auVar21._0_4_ != 0) goto LAB_001119d0;
    iVar5 = (int)local_118;
    if ((int)local_118 != *(int *)(param_1 + 0xc0)) {
      uVar17 = 0xffffffcb;
      goto LAB_001119d0;
    }
    if (0xd < (uint)local_110) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x111d98);
      (*pcVar4)();
    }
    if (*(int *)(gfa + (long)(int)local_118 * 0x6a68 + (local_110 & 0xffffffff) * 0x48 + 0x580) == 0
       ) {
      uVar17 = 0xffffff95;
      goto LAB_001119d0;
    }
    lVar16 = gfa + (long)(int)local_118 * 0x6a68 + (local_110 & 0xffffffff) * 0x48;
    if (*(long *)(lVar16 + 0x570) != *(long *)(lVar16 + 0x578)) {
      uVar6 = fastrpc_dsp_restart_handler(param_1,0,0);
      if (uVar6 != 0) {
        uVar17 = (ulong)uVar6;
        lVar16 = sp_el0;
        _printk(&DAT_0014c59e,0x1535,lVar16 + 0x848,"fastrpc_mmap_remove_pdr",uVar17);
        lVar13 = gfa + (long)iVar5 * 0x6a68 + (uVar20 & 0xffffffff) * 0x48;
        lVar16 = 0;
        *(undefined8 *)(lVar13 + 0x578) = *(undefined8 *)(lVar13 + 0x570);
        goto LAB_001119d4;
      }
      lVar16 = gfa + (long)iVar5 * 0x6a68 + (uVar20 & 0xffffffff) * 0x48;
      *(undefined8 *)(lVar16 + 0x578) = *(undefined8 *)(lVar16 + 0x570);
      uVar9 = extraout_x1;
    }
    bVar3 = false;
    lVar16 = 0;
    plVar1 = (long *)(lVar13 + (long)iVar7 * 0x6a68 + 0xa00);
    if (DAT_001505b0 == 0) {
      lVar19 = 0;
      uVar14 = 0;
      if (DAT_001505ec != '\0') goto LAB_00111c1c;
      local_100 = 1;
      auVar21 = fastrpc_get_persistent_map(*(undefined4 *)(param_2 + 0x20),local_f8);
      uVar9 = auVar21._8_8_;
      if ((auVar21._0_8_ & 1) != 0) {
        lVar16 = local_f8[0];
        if (local_f8[0] != 0) goto LAB_00111ad4;
LAB_00111b78:
        uVar17 = 0xffffffff;
        goto LAB_001119d4;
      }
      mutex_lock(param_1 + 0x110);
      uVar20 = fastrpc_mmap_create(param_1,0xffffffff,0,0,*(undefined8 *)(param_2 + 0x18),
                                   *(undefined4 *)(param_2 + 0x20),8,local_f8);
      lVar16 = local_f8[0];
      if (local_f8[0] != 0) {
        *(undefined1 *)(local_f8[0] + 0xb8) = 1;
      }
      mutex_unlock(param_1 + 0x110);
      bVar3 = false;
      lVar19 = 0;
      if (((int)uVar20 == 0) && (lVar16 != 0)) {
        uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
        *(undefined1 *)(lVar16 + 0x90) = 1;
        _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
        fastrpc_mmap_add_global(lVar16);
        uVar9 = extraout_x1_00;
LAB_00111ad4:
        uVar14 = *(undefined8 *)(lVar16 + 0x48);
        lVar19 = *(long *)(lVar16 + 0x50);
        if (*plVar1 == 0) {
          bVar3 = false;
        }
        else {
          bVar3 = false;
          if ((*(int *)(lVar16 + 0x68) == 1) && (lVar19 != 0)) {
            lVar18 = lVar13 + (long)iVar7 * 0x6a68;
            local_110 = 8;
            iVar5 = *(int *)(lVar18 + 0xa10);
            if ((iVar5 < 0) || (lVar10 = __kmalloc((long)iVar5 << 3,0xdc0), lVar10 == 0))
            goto LAB_00111b78;
            puVar2 = (uint *)(lVar18 + 0xa10);
            if (*puVar2 == 0) {
              uVar17 = 0;
            }
            else {
              uVar20 = 0;
              puVar15 = (undefined4 *)(lVar10 + 4);
              do {
                lVar18 = uVar20 * 4;
                uVar20 = uVar20 + 1;
                puVar15[-1] = *(undefined4 *)(*plVar1 + lVar18);
                *puVar15 = *(undefined4 *)
                            (*(long *)(lVar13 + (long)iVar7 * 0x6a68 + 0xa08) + lVar18);
                uVar17 = (ulong)*puVar2;
                puVar15 = puVar15 + 2;
              } while (uVar20 < uVar17);
            }
            iVar5 = qcom_scm_assign_mem(uVar14,lVar19,&local_110,lVar10,uVar17);
            kfree(lVar10);
            if (iVar5 != 0) {
              lVar13 = sp_el0;
              _printk(&DAT_0014bd5c,0x1183,lVar13 + 0x848,"fastrpc_init_create_static_process",iVar5
                      ,uVar14,lVar19);
              uVar17 = 0xffffff9d;
              goto LAB_001119d4;
            }
            bVar3 = true;
            uVar9 = extraout_x1_01;
          }
        }
        DAT_001505b0 = 1;
        *(undefined1 *)(lVar16 + 0x7c) = 1;
        goto LAB_00111c1c;
      }
      uVar14 = 0;
    }
    else {
      lVar19 = 0;
      uVar14 = 0;
LAB_00111c1c:
      local_b0 = &local_108;
      uStack_98 = local_108 >> 0x20;
      uStack_a8 = 0xc;
      local_90 = &local_80;
      local_e0 = 0;
      uStack_d8 = 0;
      uStack_88 = 0x10;
      ppuStack_e8 = &local_b0;
      local_d0 = 0;
      uStack_c8 = 0;
      local_c0 = 0;
      uStack_b8 = 0;
      local_f8[1] = 0x803000000000001;
      local_a0 = __s1;
      local_80 = uVar14;
      lStack_78 = lVar19;
      uVar20 = fastrpc_internal_invoke(param_1,uVar9,1,local_f8 + 1);
    }
    uVar17 = uVar20 & 0xffffffff;
    kfree(__s1);
    if ((int)uVar20 == 0) goto LAB_00111a04;
    DAT_001505b0 = 0;
    if (bVar3) {
      lVar13 = lVar13 + (long)iVar7 * 0x6a68;
      local_118 = 0x700000003;
      local_110 = 0;
      if (*(int *)(lVar13 + 0xa10) != 0) {
        local_110 = 0;
        uVar20 = 0;
        do {
          lVar18 = uVar20 * 4;
          uVar20 = uVar20 + 1;
          local_110 = 1L << ((ulong)*(uint *)(*plVar1 + lVar18) & 0x3f) | local_110;
        } while (uVar20 < *(uint *)(lVar13 + 0xa10));
      }
      iVar7 = qcom_scm_assign_mem(uVar14,lVar19,&local_110,&local_118,1);
      if (iVar7 != 0) {
        lVar13 = sp_el0;
        _printk(&DAT_0014b8af,0x11c2,lVar13 + 0x848,"fastrpc_init_create_static_process",iVar7,
                uVar14,lVar19);
      }
    }
  }
  mutex_lock(param_1 + 0x110);
  fastrpc_mmap_free(lVar16,0);
  mutex_unlock(param_1 + 0x110);
LAB_00111a04:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
}



//------------------------------------------------------------
// fastrpc_device_create @ 00111dc8 size=312
// signature: undefined fastrpc_device_create(void)
// callers: [fastrpc_init_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int fastrpc_device_create(long param_1)

{
  long *plVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined *puVar7;
  int iVar8;
  long *plVar9;
  undefined8 uVar10;
  
  plVar9 = (long *)kmalloc_trace(_cpu_hwcaps,0xdc0,0x3b8);
  puVar7 = PTR_s_fastrpc_0014a7f0;
  if (plVar9 == (long *)0x0) {
    iVar8 = -0xc;
  }
  else {
    plVar1 = plVar9 + 2;
    uVar3 = *(undefined4 *)(param_1 + 0xb8);
    uVar4 = *(undefined4 *)(param_1 + 0xbc);
    plVar9[0xe] = (long)&fastrpc_bus;
    uVar5 = *(undefined4 *)(param_1 + 0xc0);
    puVar2 = fastrpc_bus;
    if (puVar7 != (undefined *)0x0) {
      puVar2 = puVar7;
    }
    plVar9[0x12] = (long)&fastrpc_bus_type;
    dev_set_name(plVar1,"%s-%d-%d-%d",puVar2,uVar3,uVar4,uVar5);
    uVar3 = *(undefined4 *)(param_1 + 0xbc);
    plVar9[0x75] = param_1;
    plVar9[0x67] = (long)fastrpc_dev_release;
    *(undefined4 *)(plVar9 + 0x74) = uVar3;
    iVar8 = device_register(plVar1);
    if (iVar8 == 0) {
      *(long **)(param_1 + 0x1f0) = plVar9;
      uVar10 = _raw_spin_lock_irqsave(&DAT_001505c8);
      *plVar9 = (long)DAT_00150650;
      if (DAT_00150650 != (long *)0x0) {
        DAT_00150650[1] = (long)plVar9;
      }
      DAT_00150650 = plVar9;
      plVar9[1] = (long)&DAT_00150650;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar10);
      iVar8 = 0;
    }
    else {
      put_device(plVar1);
      lVar6 = sp_el0;
      _printk(&DAT_0014d77c,0x232d,lVar6 + 0x848,"fastrpc_device_create",
              *(undefined4 *)(param_1 + 0xb8),*(undefined4 *)(param_1 + 0xbc),
              *(undefined4 *)(param_1 + 0xb0),iVar8);
    }
  }
  return iVar8;
}



//------------------------------------------------------------
// fastrpc_get_info_from_dsp @ 00111f04 size=264
// signature: undefined fastrpc_get_info_from_dsp(void)
// callers: []
//------------------------------------------------------------

int fastrpc_get_info_from_dsp(undefined8 param_1,undefined4 *param_2,uint param_3,int param_4)

{
  long lVar1;
  int iVar2;
  undefined8 extraout_x1;
  undefined8 local_a0;
  uint **ppuStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  uint local_5c;
  uint *local_58;
  undefined8 uStack_50;
  undefined4 *local_48;
  long lStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  iVar2 = 0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (undefined4 *)0x0;
  lStack_40 = 0;
  local_58 = (uint *)0x0;
  uStack_50 = 0;
  *param_2 = 0;
  local_5c = param_3;
  if (param_4 != 1) {
    iVar2 = fastrpc_channel_open(param_1,0xffffffff);
    if (iVar2 == 0) {
      local_58 = &local_5c;
      local_48 = param_2 + 1;
      lStack_40 = (ulong)param_3 << 2;
      uStack_50 = 4;
      ppuStack_98 = &local_58;
      local_90 = 0;
      uStack_88 = 0;
      local_a0 = 0x1010000000002;
      local_80 = 0;
      uStack_78 = 0;
      local_70 = 0;
      uStack_68 = 0;
      iVar2 = fastrpc_internal_invoke(param_1,extraout_x1,1,&local_a0);
      if (iVar2 == 0) goto LAB_00111fac;
    }
    lVar1 = sp_el0;
    _printk(&DAT_0014f32c,0x1297,lVar1 + 0x848,"fastrpc_get_info_from_dsp",iVar2);
  }
LAB_00111fac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// fastrpc_get_info_from_kernel @ 00112010 size=604
// signature: undefined fastrpc_get_info_from_kernel(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_get_dsp_info]
//------------------------------------------------------------

ulong fastrpc_get_info_from_kernel(uint *param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined1 auVar7 [16];
  undefined8 local_d0;
  undefined4 **ppuStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_8c;
  undefined4 *local_88;
  undefined8 uStack_80;
  long local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar4 = *param_1;
  if (4 < uVar4) {
    uVar5 = 0xffffffd4;
    goto LAB_001120f4;
  }
  uVar1 = param_1[1];
  uVar6 = (ulong)uVar1;
  if (0x103 < uVar1) {
    uVar5 = 0xffffffb5;
    goto LAB_001120f4;
  }
  if (uVar1 < 0x100) {
    if (0x209e0 < (ulong)uVar4 * 0x6a68) goto LAB_00112268;
    if (*(int *)(&DAT_00129da0 + (ulong)uVar4 * 0x6a68) == 0) {
      local_78 = 0;
      uStack_70 = 0;
      local_88 = (undefined4 *)0x0;
      uStack_80 = 0;
      local_8c = 0xff;
      if (0x209dc < (ulong)uVar4 * 0x6a68) goto LAB_00112268;
      *(undefined4 *)(&DAT_00129da4 + (ulong)uVar4 * 0x6a68) = 0;
      if (uVar4 == 1) {
LAB_001121c8:
        if (((0x209b8 < (ulong)uVar4 * 0x6a68) ||
            (*(uint *)(&DAT_00129dc8 + (ulong)uVar4 * 0x6a68) =
                  (uint)(*(int *)(&DAT_00129dc8 + (ulong)uVar4 * 0x6a68) != 0),
            0x21404 < uVar6 * 4 + (ulong)uVar4 * 0x6a68 + 0xa2c)) ||
           (param_1[2] = *(uint *)(&DAT_00129da4 + (ulong)uVar4 * 0x6a68 + uVar6 * 4),
           0x209e0 < (ulong)uVar4 * 0x6a68)) {
LAB_00112268:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x11226c);
          (*pcVar3)();
        }
        uVar5 = 0;
        *(int *)(&DAT_00129da0 + (ulong)uVar4 * 0x6a68) = 1;
      }
      else {
        auVar7 = fastrpc_channel_open(param_2,0xffffffff);
        uVar5 = auVar7._0_8_;
        if (auVar7._0_4_ == 0) {
          local_88 = &local_8c;
          local_78 = (ulong)uVar4 * 0x6a68 + 0x129da8;
          uStack_80 = 4;
          ppuStack_c8 = &local_88;
          uStack_70 = 0x3fc;
          local_c0 = 0;
          uStack_b8 = 0;
          local_d0 = 0x1010000000002;
          local_b0 = 0;
          uStack_a8 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          uVar5 = fastrpc_internal_invoke(param_2,auVar7._8_8_,1,&local_d0);
          if ((int)uVar5 == 0) goto LAB_001121c8;
        }
        uVar5 = uVar5 & 0xffffffff;
        lVar2 = sp_el0;
        _printk(&DAT_0014f32c,0x1297,lVar2 + 0x848,"fastrpc_get_info_from_dsp",uVar5);
      }
      goto LAB_001120f4;
    }
    if (0x21404 < uVar6 * 4 + (ulong)uVar4 * 0x6a68 + 0xa2c) goto LAB_00112268;
    uVar4 = *(uint *)(&DAT_00129da4 + (ulong)uVar4 * 0x6a68 + uVar6 * 4);
  }
  else {
    if (3 < uVar1 - 0x100) goto LAB_00112268;
    uVar4 = *(uint *)(kernel_capabilities + (ulong)(uVar1 - 0x100) * 4);
  }
  uVar5 = 0;
  param_1[2] = uVar4;
LAB_001120f4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// fastrpc_internal_munmap @ 00112270 size=596
// signature: undefined fastrpc_internal_munmap(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl]
//------------------------------------------------------------

int fastrpc_internal_munmap(long param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long *local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_50 = (long *)0x0;
  if (*(int *)(param_1 + 0xe4) == 1) {
    mutex_lock(param_1 + 0x140);
    lVar5 = param_1 + 0x10;
    _raw_spin_lock(lVar5);
    plVar3 = (long *)*(long *)(param_1 + 0x30);
    do {
      plVar4 = plVar3;
      if ((plVar4 == (long *)0x0) || (plVar4 + -2 == (long *)0x0)) {
        _raw_spin_unlock(lVar5);
        lVar5 = param_1 + 0x110;
        mutex_lock(lVar5);
        iVar1 = fastrpc_mmap_remove(param_1,0xffffffff,*param_2,param_2[1],&local_50);
        mutex_unlock(lVar5);
        plVar3 = local_50;
        if (iVar1 == 0) {
          if (local_50 == (long *)0x0) {
            iVar1 = -0x16;
            goto LAB_00112430;
          }
          if (*(char *)((long)local_50 + 0x7c) == '\0') {
            iVar1 = fastrpc_munmap_on_dsp
                              (param_1,local_50[0xe],local_50[9],local_50[10],
                               *(undefined4 *)((long)local_50 + 0x24));
            if (iVar1 != 0) goto LAB_00112310;
          }
          mutex_lock(lVar5);
          fastrpc_mmap_free(plVar3,0);
          iVar1 = 0;
        }
        else {
          if (local_50 == (long *)0x0) goto LAB_00112430;
LAB_00112310:
          mutex_lock(param_1 + 0x110);
          if ((*(int *)((long)plVar3 + 0x24) == 8) || (*(int *)((long)plVar3 + 0x24) == 4)) {
            uVar2 = _raw_spin_lock_irqsave(&DAT_001505c8);
            *plVar3 = (long)DAT_001505a8;
            if (DAT_001505a8 != (long *)0x0) {
              DAT_001505a8[1] = (long)plVar3;
            }
            DAT_001505a8 = plVar3;
            plVar3[1] = (long)&DAT_001505a8;
            _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
          }
          else {
            plVar4 = (long *)(plVar3[2] + 0x18);
            lVar5 = *plVar4;
            *plVar3 = lVar5;
            if (lVar5 != 0) {
              *(long **)(lVar5 + 8) = plVar3;
            }
            *plVar4 = (long)plVar3;
            plVar3[1] = (long)plVar4;
          }
        }
        mutex_unlock(param_1 + 0x110);
        goto LAB_00112430;
      }
      plVar3 = (long *)*plVar4;
    } while ((plVar4[9] == 0) ||
            ((((*(uint *)(plVar4 + 10) | 0x2000) != 0x3000 || (plVar4[9] != *param_2)) ||
             (plVar4[7] != param_2[1]))));
    _raw_spin_unlock(lVar5);
    iVar1 = fastrpc_munmap_on_dsp
                      (param_1,plVar4[9],plVar4[6],plVar4[7],*(undefined4 *)(plVar4 + 10));
    if (iVar1 == 0) {
      fastrpc_buf_free(plVar4 + -2,0);
    }
LAB_00112430:
    mutex_unlock(param_1 + 0x140);
  }
  else {
    lVar5 = sp_el0;
    _printk(&DAT_0014ff3d,0x1562,lVar5 + 0x848,"fastrpc_internal_munmap",lVar5 + 0x848);
    iVar1 = -0x70;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// fastrpc_munmap_on_dsp @ 001124c4 size=528
// signature: undefined fastrpc_munmap_on_dsp(void)
// callers: [fastrpc_internal_munmap, fastrpc_dev_unmap_dma]
//------------------------------------------------------------

void fastrpc_munmap_on_dsp
               (long param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4,int param_5)

{
  long lVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined1 auVar5 [16];
  undefined1 local_b0 [8];
  undefined8 local_a8;
  undefined8 ***local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 ***local_68;
  undefined8 uStack_60;
  undefined8 ***local_58;
  undefined8 uStack_50;
  undefined1 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_68 = &local_58;
  local_38 = *(long *)(lVar1 + 0x638);
  uStack_60 = 0x18;
  local_a0 = &local_68;
  local_58 = (undefined8 ***)(ulong)*(uint *)(param_1 + 0xbc);
  local_98 = 0;
  uVar3 = 0x3010000;
  if (*(int *)(*(long *)(param_1 + 0xf0) + 0xb8) != 0) {
    uVar3 = 0x5010000;
  }
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_a8 = CONCAT44(uVar3,1);
  uStack_50 = param_2;
  local_48 = param_4;
  auVar5 = fastrpc_internal_invoke(param_1,param_2,1,&local_a8);
  uVar2 = auVar5._0_8_;
  if (auVar5._0_4_ == 0) {
    if (param_5 == 8) {
      if ((*(uint **)(gfa + 0xa00) != (uint *)0x0) && (*(int *)(gfa + 0x9e0) == 0)) {
        uVar2 = (ulong)*(uint *)(gfa + 0xa10);
        local_a8 = 0;
        local_58 = (undefined8 ***)0x700000003;
        if (*(uint *)(gfa + 0xa10) != 0) {
          local_a8 = 0;
          puVar4 = *(uint **)(gfa + 0xa00);
          do {
            uVar2 = uVar2 - 1;
            local_a8 = 1L << ((ulong)*puVar4 & 0x3f) | local_a8;
            puVar4 = puVar4 + 1;
          } while (uVar2 != 0);
        }
        uVar2 = qcom_scm_assign_mem(param_3,param_4,&local_a8,&local_58,1);
        if ((int)uVar2 != 0) {
          lVar1 = sp_el0;
          _printk(&DAT_0014dcc8,0x146c,lVar1 + 0x848,"fastrpc_munmap_rh",uVar2 & 0xffffffff,param_3,
                  param_4);
          uVar2 = 0xffffff9d;
        }
        goto LAB_001125ec;
      }
    }
    else if (param_5 == 4) {
      local_b0[0] = 0;
      if (param_1 == 0) {
        uVar2 = 0xfffffff7;
      }
      else if (*(uint *)(param_1 + 0xc0) < 5) {
        local_58 = &local_68;
        uStack_50 = 4;
        local_68 = (undefined8 ***)CONCAT44(local_68._4_4_,*(undefined4 *)(param_1 + 0xbc));
        local_a0 = &local_58;
        local_98 = 0;
        local_90 = 0;
        uStack_40 = 1;
        local_a8 = 0x901010000000001;
        local_88 = 0;
        local_80 = 0;
        local_78 = 0;
        local_70 = 0;
        local_48 = local_b0;
        uVar2 = fastrpc_internal_invoke(param_1,auVar5._8_8_,1,&local_a8);
      }
      else {
        lVar1 = sp_el0;
        _printk(&DAT_0014e617,0x1430,lVar1 + 0x848,"fastrpc_munmap_on_dsp_rh");
        uVar2 = 0xffffffd4;
      }
      goto LAB_001125ec;
    }
    uVar2 = 0;
  }
LAB_001125ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_buf_free @ 001126d4 size=604
// signature: undefined fastrpc_buf_free(void)
// callers: [fastrpc_file_put, fastrpc_create_persistent_headers, fastrpc_buf_alloc, fastrpc_cached_buf_list_free, context_free, fastrpc_internal_munmap, fastrpc_internal_mmap, fastrpc_init_create_dynamic_process]
//------------------------------------------------------------

void fastrpc_buf_free(long *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 local_58;
  ulong local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  if ((param_1 == (long *)0x0) || (lVar7 = param_1[6], lVar7 == 0)) goto LAB_00112874;
  if ((char)param_1[0xd] == '\0') {
    if ((param_2 != 0) && ((ulong)param_1[9] >> 0x17 == 0)) {
      _raw_spin_lock(lVar7 + 0x10);
      if (*(uint *)(lVar7 + 0x28) < 0x21) {
        lVar6 = *(long *)(lVar7 + 0x20);
        *param_1 = lVar6;
        if (lVar6 != 0) {
          *(long **)(lVar6 + 8) = param_1;
        }
        *(long **)(lVar7 + 0x20) = param_1;
        param_1[1] = lVar7 + 0x20;
        *(int *)(lVar7 + 0x28) = *(int *)(lVar7 + 0x28) + 1;
        *(undefined4 *)((long)param_1 + 100) = 0xffffffff;
        goto LAB_00112724;
      }
      _raw_spin_unlock(lVar7 + 0x10);
    }
    if (*(int *)((long)param_1 + 100) == 3) {
      _raw_spin_lock(lVar7 + 0x10);
      plVar4 = (long *)param_1[3];
      if (plVar4 != (long *)0x0) {
        lVar6 = param_1[2];
        *plVar4 = lVar6;
        if (lVar6 != 0) {
          *(long **)(lVar6 + 8) = plVar4;
        }
        param_1[2] = 0;
        param_1[3] = 0;
      }
      _raw_spin_unlock(lVar7 + 0x10);
      param_1[0xb] = 0;
    }
    if (((param_1[7] != 0) && ((ulong)param_1[7] < 0xfffffffffffff001)) &&
       (*(long *)(lVar7 + 0x68) != 0)) {
      uVar1 = *(uint *)(*(long *)(lVar7 + 0x68) + 0x18);
      if (uVar1 != 0) {
        param_1[8] = param_1[8] & ((ulong)uVar1 << 0x20 ^ 0xffffffffffffffff);
      }
      uVar1 = *(uint *)(lVar7 + 0xc0);
      if (uVar1 < 5) {
        uVar2 = *(uint *)(**(long **)(lVar7 + 0xf0) + (ulong)uVar1 * 0x6a68 + 0x9fc);
        if ((uVar2 != 0) &&
           (*(int *)(**(long **)(lVar7 + 0xf0) + (ulong)uVar1 * 0x6a68 + 0x9e0) == 0)) {
          local_50 = 1L << ((ulong)uVar2 & 0x3f) | 8;
          uVar5 = (ulong)*(uint *)(param_1 + 9) + 0xfff & 0x1fffff000;
          if (uVar5 < 0x1001) {
            uVar5 = 0x1000;
          }
          local_58 = 0x700000003;
          iVar3 = qcom_scm_assign_mem(param_1[8],uVar5,&local_50,&local_58,1);
          if (iVar3 != 0) {
            lVar6 = sp_el0;
            _printk(&DAT_0014dcc8,0x309,lVar6 + 0x848,"fastrpc_buf_free",iVar3,param_1[8],param_1[9]
                   );
          }
        }
        dma_free_attrs(*(undefined8 *)(*(long *)(lVar7 + 0x68) + 8),param_1[9],param_1[7],param_1[8]
                       ,param_1[10]);
      }
      else {
        lVar7 = sp_el0;
        _printk(&DAT_0014e617,0x2f7,lVar7 + 0x848,"fastrpc_buf_free",uVar1);
      }
    }
    kfree(param_1);
  }
  else {
    _raw_spin_lock(lVar7 + 0x10);
    *(undefined1 *)(param_1 + 0xd) = 0;
LAB_00112724:
    _raw_spin_unlock(lVar7 + 0x10);
  }
LAB_00112874:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_mmap_remove @ 001129d0 size=364
// signature: undefined fastrpc_mmap_remove(void)
// callers: [fastrpc_internal_munmap, fastrpc_internal_mem_unmap]
//------------------------------------------------------------

undefined8
fastrpc_mmap_remove(long param_1,int param_2,long param_3,long param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  uVar1 = _raw_spin_lock_irqsave(&DAT_001505c8);
  puVar2 = DAT_001505a8;
  do {
    puVar4 = puVar2;
    if (puVar4 == (undefined8 *)0x0) {
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar1);
      puVar2 = *(undefined8 **)(param_1 + 0x18);
      do {
        puVar4 = puVar2;
        if (puVar4 == (undefined8 *)0x0) {
          return 0xffffff93;
        }
        puVar2 = (undefined8 *)*puVar4;
      } while ((((-1 < param_2) && (*(int *)(puVar4 + 4) != param_2)) || (puVar4[0xe] != param_3))
              || (((puVar4[0xc] != param_4 || (*(int *)(puVar4 + 0xd) != 1)) ||
                  ((*(int *)(puVar4 + 0x19) != 0 ||
                   ((*(int *)((long)puVar4 + 0xcc) != 0 || (*(char *)(puVar4 + 0x17) != '\0'))))))))
      ;
      puVar3 = (undefined8 *)puVar4[1];
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = puVar2;
        if (puVar2 != (undefined8 *)0x0) {
          puVar2[1] = puVar3;
        }
        *puVar4 = 0;
        puVar4[1] = 0;
      }
      goto LAB_00112abc;
    }
    puVar2 = (undefined8 *)*puVar4;
  } while (((((-1 < param_2) && (*(int *)(puVar4 + 4) != param_2)) || (puVar4[0xe] != param_3)) ||
           ((puVar4[0xc] != param_4 || (*(int *)(puVar4 + 0xd) != 1)))) ||
          ((*(char *)((long)puVar4 + 0x7c) != '\0' || (*(char *)(puVar4 + 0x17) != '\0'))));
  puVar3 = (undefined8 *)puVar4[1];
  if (puVar3 != (undefined8 *)0x0) {
    *puVar3 = puVar2;
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = puVar3;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar1);
LAB_00112abc:
  *param_5 = puVar4;
  return 0;
}



//------------------------------------------------------------
// fastrpc_mmap_free @ 00112b3c size=1164
// signature: undefined fastrpc_mmap_free(void)
// callers: [fastrpc_device_ioctl, fastrpc_dev_unmap_dma, fastrpc_init_create_static_process, fastrpc_dsp_restart_handler, fastrpc_internal_invoke, fastrpc_internal_mem_map, fastrpc_internal_munmap, fastrpc_file_put, fastrpc_dev_map_dma, fastrpc_mmap_create, fastrpc_internal_mem_unmap, context_free, put_args, fastrpc_internal_mmap, fastrpc_init_create_dynamic_process]
//------------------------------------------------------------

void fastrpc_mmap_free(long *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  undefined8 local_90;
  ulong local_88 [7];
  
  lVar8 = sp_el0;
  local_88[6] = *(long *)(lVar8 + 0x638);
  if (param_1 == (long *)0x0) goto LAB_00112ee8;
  lVar8 = param_1[2];
  iVar2 = *(int *)((long)param_1 + 0x24);
  uVar7 = 0xffffffff;
  if ((((lVar8 != 0) && (iVar2 != 4)) && (iVar2 != 8)) &&
     (uVar7 = *(uint *)(lVar8 + 0xc0), 4 < uVar7)) {
    _printk(&DAT_0014ebf3,"fastrpc_mmap_free",uVar7,0xffffffd4);
    goto LAB_00112ee8;
  }
  if ((iVar2 == 8) || (iVar2 == 4)) {
    uVar3 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if ((int)param_1[0xd] == 0) {
LAB_00112bd0:
      if ((*(char *)((long)param_1 + 0x7c) == '\0') &&
         (plVar5 = (long *)param_1[1], plVar5 != (long *)0x0)) {
        lVar6 = *param_1;
        *plVar5 = lVar6;
        if (lVar6 != 0) {
          *(long **)(lVar6 + 8) = plVar5;
        }
        iVar2 = (int)param_1[0xd];
        *param_1 = 0;
        param_1[1] = 0;
        goto LAB_00112bf8;
      }
    }
    else {
      iVar2 = (int)param_1[0xd] + -1;
      *(int *)(param_1 + 0xd) = iVar2;
      if (iVar2 == 0) goto LAB_00112bd0;
LAB_00112bf8:
      if (0 < iVar2) {
        lVar8 = sp_el0;
        _printk(&DAT_0014fabb,0x3ee,lVar8 + 0x848,"fastrpc_mmap_free",param_1[10],param_1[0xb]);
        _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
        goto LAB_00112ee8;
      }
    }
    if ((*(char *)((long)param_1 + 0x7c) != '\0') && ((char)param_1[0x12] != '\0')) {
      *(undefined1 *)(param_1 + 0x12) = 0;
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
  }
  else {
    if ((int)param_1[0xd] == 0) {
      if (param_2 == 0) goto LAB_00112f40;
    }
    else {
      iVar2 = (int)param_1[0xd] + -1;
      *(int *)(param_1 + 0xd) = iVar2;
      if (param_2 == 0) {
        if (iVar2 != 0) goto LAB_00112ee8;
LAB_00112f40:
        if (((int)param_1[0x19] != 0) || (*(int *)((long)param_1 + 0xcc) != 0)) goto LAB_00112ee8;
      }
    }
    plVar5 = (long *)param_1[1];
    if (plVar5 != (long *)0x0) {
      lVar6 = *param_1;
      *plVar5 = lVar6;
      if (lVar6 != 0) {
        *(long **)(lVar6 + 8) = plVar5;
      }
      *param_1 = 0;
      param_1[1] = 0;
    }
  }
  iVar2 = *(int *)((long)param_1 + 0x24);
  if (iVar2 == 4) {
LAB_00112c40:
    if (DAT_001505d0 == 0) {
      lVar8 = sp_el0;
      _printk(&DAT_0014bb75,0x405,lVar8 + 0x848,"fastrpc_mmap_free");
      goto LAB_00112ee8;
    }
    uVar4 = msm_minidump_enabled();
    if (((uVar4 & 1) != 0) && (*(char *)((long)param_1 + 0x7c) == '\0')) {
      local_88[4] = 0;
      local_88[5] = 0;
      local_88[2] = 0;
      local_88[3] = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      if (*(uint *)(param_1 + 0x10) < 5) {
        scnprintf(local_88,0xc,"FRPC_%d",*(uint *)(param_1 + 0x10));
        local_88[5] = param_1[10];
        local_88[3] = param_1[0xb];
        local_88[4] = param_1[9];
        iVar2 = msm_minidump_remove_region(local_88);
        if (iVar2 < 0) {
          lVar6 = sp_el0;
          _printk(&DAT_0014c85d,0x2bf,lVar6 + 0x848,"fastrpc_minidump_remove_region",param_1[9],
                  param_1[10],(int)param_1[0x10]);
        }
        else {
          uVar7 = *(uint *)(param_1 + 0x10);
          mutex_lock(&DAT_00150660);
          if (uVar7 < 5) {
            (&md_unique_index_flag)[uVar7] = 0;
          }
          mutex_unlock(&DAT_00150660);
          *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
        }
      }
      else {
        lVar6 = sp_el0;
        _printk(&DAT_0014cd68,0x2c5,lVar6 + 0x848,"fastrpc_minidump_remove_region");
      }
    }
    if ((param_1[9] != 0) && (*(char *)((long)param_1 + 0x7c) == '\0')) {
      dma_free_attrs(DAT_001505d0,param_1[10],param_1[0xb],param_1[9],param_1[0x11]);
    }
LAB_00112e94:
    if (lVar8 != 0) {
      _raw_spin_lock(lVar8 + 0x10);
      if ((*(uint *)((long)param_1 + 0x24) | 0x2000) == 0x3000) {
        plVar5 = (long *)(lVar8 + 0x90);
      }
      else {
        plVar5 = (long *)(lVar8 + 0x98);
      }
      *plVar5 = *plVar5 - param_1[10];
      _raw_spin_unlock(lVar8 + 0x10);
    }
  }
  else {
    if (iVar2 == 0x10) {
      lVar6 = param_1[10];
LAB_00112e4c:
      uVar4 = param_1[6];
      if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
        dma_buf_unmap_attachment(lVar6,param_1[7],uVar4,0);
      }
      if ((param_1[7] != 0) && ((ulong)param_1[7] < 0xfffffffffffff001)) {
        dma_buf_detach(param_1[5]);
      }
      if ((param_1[5] != 0) && ((ulong)param_1[5] < 0xfffffffffffff001)) {
        dma_buf_put();
      }
      goto LAB_00112e94;
    }
    if (iVar2 == 8) goto LAB_00112c40;
    if (lVar8 != 0) {
      uVar1 = *(uint *)(**(long **)(lVar8 + 0xf0) + (long)(int)uVar7 * 0x6a68 + 0x9fc);
      if (((uVar1 != 0) && (param_1[9] != 0)) &&
         (*(int *)(gfa + (long)(int)uVar7 * 0x6a68 + 0x9e0) == 0)) {
        local_88[0] = 1L << ((ulong)uVar1 & 0x3f) | 8;
        uVar4 = (ulong)*(uint *)(param_1 + 10) + 0xfff & 0x1fffff000;
        if (uVar4 < 0x1001) {
          uVar4 = 0x1000;
        }
        local_90 = 0x700000003;
        iVar2 = qcom_scm_assign_mem(param_1[9],uVar4,local_88,&local_90,1);
        if (iVar2 != 0) {
          lVar6 = sp_el0;
          _printk(&DAT_0014dcc8,0x431,lVar6 + 0x848,"fastrpc_mmap_free",iVar2,param_1[9],param_1[10]
                 );
        }
      }
      lVar6 = param_1[10];
      goto LAB_00112e4c;
    }
  }
  if (*(char *)((long)param_1 + 0x7c) == '\0') {
    kfree(param_1);
  }
LAB_00112ee8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_88[6]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_mmap_add_global @ 00113194 size=100
// signature: undefined fastrpc_mmap_add_global(void)
// callers: [fastrpc_init_create_static_process]
//------------------------------------------------------------

void fastrpc_mmap_add_global(long *param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(&DAT_001505c8);
  *param_1 = (long)DAT_001505a8;
  if (DAT_001505a8 != (long *)0x0) {
    *(long **)((long)DAT_001505a8 + 8) = param_1;
  }
  DAT_001505a8 = param_1;
  param_1[1] = (long)&DAT_001505a8;
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar1);
  return;
}



//------------------------------------------------------------
// fastrpc_internal_mem_map @ 001131fc size=604
// signature: undefined fastrpc_internal_mem_map(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl]
//------------------------------------------------------------

int fastrpc_internal_mem_map(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 extraout_x1;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_118;
  long local_110;
  undefined4 local_108;
  undefined8 local_104;
  undefined4 local_fc;
  long local_f8;
  undefined8 uStack_f0;
  long local_e8;
  long lStack_e0;
  undefined8 local_d8;
  undefined4 **ppuStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 *local_98;
  undefined8 uStack_90;
  long *local_88;
  undefined8 uStack_80;
  long *local_78;
  undefined8 uStack_70;
  long *local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_118 = (long *)0x0;
  mutex_lock(param_1 + 0x140);
  if (*(int *)(param_1 + 0xe4) == 1) {
    mutex_lock(param_1 + 0x110);
    iVar1 = fastrpc_mmap_create(param_1,*(undefined4 *)(param_2 + 8),0,
                                *(undefined4 *)(param_2 + 0x14),*(undefined8 *)(param_2 + 0x18),
                                *(undefined8 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x10),
                                &local_118);
    mutex_unlock(param_1 + 0x110);
    plVar4 = local_118;
    if (iVar1 == 0) {
      plVar5 = local_118 + 0xe;
      if (*plVar5 == 0) {
        local_104 = *(undefined8 *)(param_2 + 8);
        local_fc = *(undefined4 *)(param_2 + 0x10);
        local_108 = *(undefined4 *)(param_1 + 0xbc);
        lStack_e0 = local_118[10];
        local_f8 = local_118[0xb];
        local_98 = &local_108;
        local_110 = 0;
        uStack_90 = 0x20;
        local_88 = &local_e8;
        uStack_f0 = 0x10;
        local_e8 = local_118[9];
        local_a8 = 0;
        uStack_a0 = 0;
        uStack_80 = 0x10;
        local_68 = &local_110;
        uStack_70 = 0;
        ppuStack_d0 = &local_98;
        uStack_60 = 8;
        local_b8 = 0;
        uStack_b0 = 0;
        local_d8 = 0xa03010000000001;
        local_c8 = 0;
        uStack_c0 = 0;
        local_78 = local_88;
        iVar1 = fastrpc_internal_invoke(param_1,extraout_x1,1,&local_d8);
        if ((plVar5 == (long *)0x0) || (iVar1 != 0)) {
          if (iVar1 != 0) goto LAB_001133f8;
          lVar3 = *plVar5;
        }
        else {
          *plVar5 = local_110;
          lVar3 = local_110;
        }
        *(long *)(param_2 + 0x28) = lVar3;
        if ((*(int *)(param_2 + 0x10) == 8) || (*(int *)(param_2 + 0x10) == 4)) {
          uVar2 = _raw_spin_lock_irqsave(&DAT_001505c8);
          *plVar4 = (long)DAT_001505a8;
          if (DAT_001505a8 != (long *)0x0) {
            DAT_001505a8[1] = (long)plVar4;
          }
          DAT_001505a8 = plVar4;
          plVar4[1] = (long)&DAT_001505a8;
          _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
        }
        iVar1 = 0;
        goto LAB_0011338c;
      }
      iVar1 = -0x11;
    }
  }
  else {
    lVar3 = sp_el0;
    _printk(&DAT_0014bcf1,"fastrpc_internal_mem_map",lVar3 + 0x848);
    plVar4 = (long *)0x0;
    iVar1 = 0x35;
  }
LAB_001133f8:
  lVar3 = sp_el0;
  _printk(&DAT_0014e53b,0x15f7,lVar3 + 0x848,"fastrpc_internal_mem_map",*(undefined4 *)(param_2 + 8)
          ,*(undefined8 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x10),plVar4,iVar1);
  if (plVar4 != (long *)0x0) {
    mutex_lock(param_1 + 0x110);
    fastrpc_mmap_free(plVar4,0);
    mutex_unlock(param_1 + 0x110);
  }
LAB_0011338c:
  mutex_unlock(param_1 + 0x140);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// fastrpc_mmap_create @ 00113458 size=2488
// signature: undefined fastrpc_mmap_create(void)
// callers: [fastrpc_internal_invoke, fastrpc_internal_mem_map, fastrpc_dev_map_dma, fastrpc_init_create_static_process, fastrpc_internal_mmap, fastrpc_init_create_dynamic_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int fastrpc_mmap_create(long param_1,int param_2,long param_3,ulong param_4,ulong param_5,
                       ulong param_6,uint param_7,long *param_8)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  undefined *puVar9;
  undefined8 uVar10;
  long lVar11;
  ulong *puVar12;
  long *plVar13;
  long lVar14;
  uint uVar15;
  int local_84;
  long local_80;
  int *local_78;
  int local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if (param_1 == 0) {
    iVar4 = -9;
    goto LAB_00113b1c;
  }
  uVar1 = *(uint *)(param_1 + 0xc0);
  if (4 < uVar1) {
    iVar4 = -0x2c;
    goto LAB_00113b1c;
  }
  lVar14 = **(long **)(param_1 + 0xf0);
  if (((!CARRY8(param_6,param_5)) && (param_7 != 4)) && (param_7 != 8)) {
    if (param_7 == 6) {
      plVar13 = (long *)(param_1 + 0x18);
      do {
        plVar13 = (long *)*plVar13;
        if (plVar13 == (long *)0x0) goto LAB_001134c4;
      } while (plVar13[5] != 0);
    }
    else {
      plVar6 = (long *)*(long *)(param_1 + 0x18);
      do {
        plVar13 = plVar6;
        if (plVar13 == (long *)0x0) goto LAB_001134c4;
        plVar6 = (long *)*plVar13;
      } while (((param_5 < (ulong)plVar13[0xb]) ||
               ((ulong)(plVar13[0xc] + plVar13[0xb]) < param_6 + param_5)) ||
              (*(int *)(plVar13 + 4) != param_2));
    }
    iVar4 = *(int *)((long)plVar13 + 0x68) + 1;
    if (iVar4 != 0x7fffffff) {
      *(int *)((long)plVar13 + 0x68) = iVar4;
      iVar4 = 0;
      *param_8 = (long)plVar13;
      goto LAB_00113b1c;
    }
  }
LAB_001134c4:
  plVar6 = (long *)kmalloc_trace(_find_vma,0xdc0,0xd0);
  iVar4 = -0xc;
  if ((plVar6 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar6)) goto LAB_00113b00;
  *plVar6 = 0;
  plVar6[1] = 0;
  plVar6[2] = param_1;
  *(undefined4 *)(plVar6 + 0xd) = 1;
  *(int *)(plVar6 + 4) = param_2;
  *(uint *)((long)plVar6 + 0x24) = param_7;
  plVar6[0x11] = param_4 & 0xffffffff;
  plVar6[5] = param_3;
  *(undefined4 *)(plVar6 + 0x10) = 0xffffffff;
  *(undefined1 *)(plVar6 + 0x17) = 0;
  ktime_get_real_ts64(plVar6 + 0x13);
  if (param_7 == 4) {
LAB_0011353c:
    local_78 = (int *)0x0;
    local_80 = 0;
    plVar6[2] = 0;
    plVar6[3] = (long)&gfa;
    plVar6[0x11] = plVar6[0x11] | 0x10;
    iVar4 = fastrpc_alloc_cma_memory(&local_78,&local_80,param_6);
    if (iVar4 != 0) goto LAB_00113574;
    lVar14 = *(long *)(param_1 + 0xd8);
    plVar6[9] = (long)local_78;
    plVar6[10] = param_6;
    plVar6[0xb] = local_80;
    plVar6[0x18] = lVar14;
    uVar7 = msm_minidump_enabled();
    if (((uVar7 & 1) != 0) && (iVar4 = fastrpc_minidump_add_region(plVar6), iVar4 != 0))
    goto LAB_00113b00;
LAB_00113a8c:
    plVar6[0xc] = param_6;
    _raw_spin_lock(param_1 + 0x10);
    lVar14 = 0x90;
    if ((param_7 & 0xffffdfff) != 0x1000) {
      lVar14 = 0x98;
    }
    *(long *)(param_1 + lVar14) = *(long *)(param_1 + lVar14) + plVar6[10];
    _raw_spin_unlock(param_1 + 0x10);
    if ((param_7 != 4) && (param_7 != 8)) {
      plVar13 = (long *)(plVar6[2] + 0x18);
      lVar14 = *plVar13;
      *plVar6 = lVar14;
      if (lVar14 != 0) {
        *(long **)(lVar14 + 8) = plVar6;
      }
      *plVar13 = (long)plVar6;
      plVar6[1] = (long)plVar13;
    }
    iVar4 = 0;
    *param_8 = (long)plVar6;
LAB_00113b00:
    if ((plVar6 == (long *)0x0) || (ktime_get_real_ts64(plVar6 + 0x15), iVar4 == 0))
    goto LAB_00113b1c;
  }
  else {
    if (param_7 == 0x10) {
      if (((uint)plVar6[0x11] >> 3 & 1) != 0) {
        lVar14 = sp_el0;
        _printk(&DAT_0014fb23,0x508,lVar14 + 0x848,"fastrpc_mmap_create",plVar6[0x11],param_2);
        iVar4 = -0x16;
        goto LAB_00113574;
      }
      uVar7 = dma_buf_get(param_2);
      plVar6[5] = uVar7;
      if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
        lVar14 = sp_el0;
        uVar10 = 0x50f;
LAB_00113d30:
        _printk(&DAT_0014cc46,uVar10,lVar14 + 0x848,"fastrpc_mmap_create",param_2);
        iVar4 = -0x4d;
        goto LAB_00113574;
      }
      local_78 = (int *)0x0;
      local_80 = 0;
      local_84 = 0;
      iVar4 = mem_buf_dma_buf_get_vmperm(uVar7,&local_78,&local_80,&local_84);
      if ((iVar4 != 0) || (local_84 != 1)) {
        if (iVar4 == 0) {
          uVar15 = 1;
          goto LAB_00113718;
        }
        lVar14 = sp_el0;
        goto LAB_00113d4c;
      }
      iVar4 = *local_78;
      iVar5 = mem_buf_current_vmid();
      uVar15 = (uint)(iVar4 != iVar5);
LAB_00113718:
      *(uint *)(plVar6 + 0xf) = uVar15;
      plVar6[0xb] = 0;
      plVar13 = DAT_001505d0;
      plVar6[9] = 0;
      uVar7 = dma_buf_attach(plVar6[5],plVar13);
      plVar6[7] = uVar7;
      if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
        *(ulong *)(uVar7 + 0x48) = *(ulong *)(uVar7 + 0x48) | 0x20;
        plVar13 = (long *)dma_buf_map_attachment(plVar6[7],0);
        plVar6[6] = (long)plVar13;
        if ((plVar13 != (long *)0x0) && (plVar13 < (long *)0xfffffffffffff001)) {
          iVar4 = (int)plVar13[1];
          if (iVar4 == 1) {
            lVar14 = *(long *)(*plVar13 + 0x10);
            plVar6[9] = lVar14;
            plVar6[10] = param_6;
            *(undefined4 *)((long)plVar6 + 0x24) = 3;
            trace_fastrpc_dma_map
                      (uVar1,param_2,lVar14,param_6,param_6,*(undefined4 *)(plVar6[7] + 0x48),0x10);
            goto LAB_00113a8c;
          }
          lVar14 = sp_el0;
          puVar9 = &DAT_001503a2;
          uVar10 = 0x534;
          goto LAB_00113dc0;
        }
        lVar14 = sp_el0;
        lVar11 = DAT_001505d0[0xe];
        if (lVar11 == 0) {
          lVar11 = *DAT_001505d0;
        }
        puVar9 = &DAT_0014bdb3;
        uVar10 = 0x52c;
        goto LAB_00113c98;
      }
      lVar14 = sp_el0;
      lVar11 = DAT_001505d0[0xe];
      if (lVar11 == 0) {
        lVar11 = *DAT_001505d0;
      }
      puVar9 = &DAT_0015032c;
      uVar10 = 0x51f;
LAB_00113c00:
      _printk(puVar9,uVar10,lVar14 + 0x848,"fastrpc_mmap_create",param_2,param_6,lVar11);
      lVar14 = sp_el0;
      _printk(&DAT_0014c5e5,0x5de,lVar14 + 0x848,"fastrpc_mmap_create",*(long *)(param_1 + 0x90),
              *(long *)(param_1 + 0x98),*(long *)(param_1 + 0x98) + *(long *)(param_1 + 0x90));
      iVar4 = -0xe;
    }
    else {
      if (param_7 == 8) goto LAB_0011353c;
      if (((uint)plVar6[0x11] >> 3 & 1) == 0) {
        if (param_7 == 6) goto LAB_001136a4;
LAB_00113814:
        uVar7 = dma_buf_get(param_2);
        plVar6[5] = uVar7;
        if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
          lVar14 = sp_el0;
          uVar10 = 0x553;
          goto LAB_00113d30;
        }
      }
      else {
        lVar11 = sp_el0;
        _printk(&DAT_0014d49e,0x540,lVar11 + 0x848,"fastrpc_mmap_create");
        *(undefined4 *)(plVar6 + 0xd) = 2;
        if (param_7 != 6) goto LAB_00113814;
LAB_001136a4:
        uVar7 = plVar6[5];
        if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
          lVar14 = sp_el0;
          _printk(&DAT_0014b924,0x547,lVar14 + 0x848,"fastrpc_mmap_create");
          iVar4 = -0xe;
          goto LAB_00113574;
        }
        plVar13 = (long *)(*(long *)(uVar7 + 8) + 0x38);
        Hint_Prefetch(plVar13,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(plVar13,0x10);
          if (bVar3) {
            *plVar13 = *plVar13 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      local_78 = (int *)0x0;
      local_80 = 0;
      local_84 = 0;
      iVar4 = mem_buf_dma_buf_get_vmperm(plVar6[5],&local_78,&local_80,&local_84);
      if ((iVar4 == 0) && (local_84 == 1)) {
        iVar4 = *local_78;
        iVar5 = mem_buf_current_vmid();
        *(uint *)(plVar6 + 0xf) = (uint)(iVar4 != iVar5);
        if (iVar4 != iVar5) goto LAB_0011389c;
        iVar4 = 0;
LAB_001138e4:
        puVar12 = (ulong *)(param_1 + 0x68);
      }
      else {
        if (iVar4 != 0) {
          lVar14 = sp_el0;
LAB_00113d4c:
          _printk(&DAT_0014d6ca,0x4a9,lVar14 + 0x848,"set_buffer_secure_type",(int)plVar6[4]);
          iVar4 = -0x4d;
          goto LAB_00113574;
        }
        *(undefined4 *)(plVar6 + 0xf) = 1;
LAB_0011389c:
        if (*(long *)(param_1 + 0xa0) == 0) {
          iVar4 = fastrpc_session_alloc_secure_memory
                            (lVar14 + (ulong)uVar1 * 0x6a68,DAT_00150694,
                             *(undefined4 *)(param_1 + 0xec));
          if (iVar4 != 0) {
            lVar14 = sp_el0;
            _printk(&DAT_0014f4e4,0x563,lVar14 + 0x848,"fastrpc_mmap_create",param_2,iVar4);
            iVar4 = -0x3f;
            goto LAB_00113574;
          }
          iVar4 = (int)plVar6[0xf];
          if (iVar4 == 0) goto LAB_001138e4;
          puVar12 = (ulong *)(param_1 + 0xa0);
        }
        else {
          puVar12 = (ulong *)(param_1 + 0xa0);
          iVar4 = 1;
        }
      }
      uVar7 = *puVar12;
      if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
        lVar14 = sp_el0;
        _printk(&DAT_0014cdb7,0x571,lVar14 + 0x848,"fastrpc_mmap_create",param_2,iVar4);
        iVar4 = -0x35;
      }
      else {
        uVar8 = dma_buf_attach(plVar6[5],*(undefined8 *)(uVar7 + 8));
        plVar6[7] = uVar8;
        if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
          lVar14 = sp_el0;
          lVar11 = (*(long **)(uVar7 + 8))[0xe];
          if (lVar11 == 0) {
            lVar11 = **(long **)(uVar7 + 8);
          }
          puVar9 = &DAT_00150118;
          uVar10 = 0x57c;
          goto LAB_00113c00;
        }
        *(ulong *)(uVar8 + 0x48) = *(ulong *)(uVar8 + 0x48) | 0x20000;
        if (*(int *)(uVar7 + 0x28) == 0) {
          *(ulong *)(plVar6[7] + 0x48) = *(ulong *)(plVar6[7] + 0x48) | 0x20;
        }
        plVar13 = (long *)dma_buf_map_attachment(plVar6[7],0);
        plVar6[6] = (long)plVar13;
        if ((plVar13 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar13)) {
          lVar14 = sp_el0;
          lVar11 = (*(long **)(uVar7 + 8))[0xe];
          if (lVar11 == 0) {
            lVar11 = **(long **)(uVar7 + 8);
          }
          puVar9 = &DAT_0014c2a8;
          uVar10 = 0x591;
LAB_00113c98:
          _printk(puVar9,uVar10,lVar14 + 0x848,"fastrpc_mmap_create",param_2,param_6,lVar11);
          iVar4 = -0xe;
        }
        else {
          if ((*(int *)(uVar7 + 0x1c) != 0) || (iVar4 = (int)plVar13[1], iVar4 == 1)) {
            lVar14 = *(long *)(*plVar13 + 0x10);
            plVar6[9] = lVar14;
            if (*(uint *)(uVar7 + 0x18) == 0) {
              uVar7 = (param_6 & 0xffffffff) + 0xfff & 0x1fffff000;
              if (uVar7 < 0x1001) {
                uVar7 = 0x1000;
              }
              plVar6[10] = uVar7;
            }
            else {
              lVar14 = lVar14 + ((ulong)*(uint *)(uVar7 + 0x18) << 0x20);
              plVar6[9] = lVar14;
              if ((int)plVar13[1] != 0) {
                uVar15 = 0;
                lVar14 = *plVar13;
                do {
                  uVar15 = uVar15 + 1;
                  plVar6[10] = plVar6[10] + (ulong)*(uint *)(lVar14 + 0x18);
                  lVar14 = sg_next();
                } while (uVar15 < *(uint *)(plVar6[6] + 8));
                lVar14 = plVar6[9];
              }
            }
            trace_fastrpc_dma_map
                      (uVar1,param_2,lVar14,plVar6[10],param_6,*(undefined4 *)(plVar6[7] + 0x48),
                       param_7);
            uVar7 = plVar6[10];
            if ((param_6 <= uVar7) && (uVar7 < DAT_0015064c)) {
              iVar4 = *(int *)(**(long **)(param_1 + 0xf0) + (ulong)uVar1 * 0x6a68 + 0x9fc);
              if (iVar4 != 0) {
                local_80 = 8;
                uVar7 = (uVar7 & 0xffffffff) + 0xfff & 0x1fffff000;
                local_78 = (int *)0x600000003;
                if (uVar7 < 0x1001) {
                  uVar7 = 0x1000;
                }
                uStack_6c = 7;
                local_70 = iVar4;
                iVar4 = qcom_scm_assign_mem(plVar6[9],uVar7,&local_80,&local_78,2);
                if (iVar4 != 0) {
                  lVar14 = sp_el0;
                  _printk(&DAT_0014bd5c,0x5c4,lVar14 + 0x848,"fastrpc_mmap_create",iVar4,plVar6[9],
                          plVar6[10]);
                  iVar4 = -99;
                  goto LAB_00113b00;
                }
              }
              plVar6[0xb] = param_5;
              goto LAB_00113a8c;
            }
            _printk(&DAT_0014e3a2,"fastrpc_mmap_create",uVar7,param_6);
            iVar4 = -0xe;
            goto LAB_00113b00;
          }
          lVar14 = sp_el0;
          puVar9 = &DAT_0014d173;
          uVar10 = 0x59a;
LAB_00113dc0:
          _printk(puVar9,uVar10,lVar14 + 0x848,"fastrpc_mmap_create",iVar4,param_2);
          iVar4 = -0xe;
        }
      }
    }
LAB_00113574:
    ktime_get_real_ts64(plVar6 + 0x15);
  }
  fastrpc_mmap_free(plVar6,0);
LAB_00113b1c:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// fastrpc_internal_mem_unmap @ 00113ecc size=560
// signature: undefined fastrpc_internal_mem_unmap(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl]
//------------------------------------------------------------

int fastrpc_internal_mem_unmap(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 extraout_x1;
  long *plVar4;
  long *plVar5;
  long lVar6;
  long *local_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  long local_b8;
  long lStack_b0;
  undefined8 local_a8;
  undefined4 **ppuStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 *local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_c8 = (long *)0x0;
  mutex_lock(param_1 + 0x140);
  if (*(int *)(param_1 + 0xe4) == 1) {
    lVar1 = param_1 + 0x110;
    mutex_lock(lVar1);
    iVar2 = fastrpc_mmap_remove(param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10)
                                ,*(undefined8 *)(param_2 + 0x18),&local_c8);
    mutex_unlock(lVar1);
    plVar5 = local_c8;
    lVar6 = 0;
    if (iVar2 != 0) goto LAB_00114048;
    iVar2 = -0x4a;
    if ((3 < *(uint *)((long)local_c8 + 0x24)) || (*(uint *)((long)local_c8 + 0x24) == 1))
    goto LAB_00114048;
    local_b8 = local_c8[0xe];
    ppuStack_a0 = &local_68;
    lVar6 = local_c8[10];
    local_c0 = *(undefined4 *)(param_1 + 0xbc);
    uStack_bc = (undefined4)local_c8[4];
    local_98 = 0;
    uStack_90 = 0;
    local_68 = &local_c0;
    local_88 = 0;
    uStack_80 = 0;
    local_a8 = 0xb01000000000001;
    local_78 = 0;
    uStack_70 = 0;
    uStack_60 = 0x18;
    lStack_b0 = lVar6;
    iVar2 = fastrpc_internal_invoke(param_1,extraout_x1,1,&local_a8);
    if (iVar2 != 0) goto LAB_00114048;
    mutex_lock(lVar1);
    fastrpc_mmap_free(plVar5,0);
  }
  else {
    lVar6 = sp_el0;
    _printk(&DAT_0014bcf1,"fastrpc_internal_mem_unmap",lVar6 + 0x848);
    plVar5 = (long *)0x0;
    lVar6 = 0;
    iVar2 = 0x35;
LAB_00114048:
    lVar1 = sp_el0;
    _printk(&DAT_0014d09d,0x1630,lVar1 + 0x848,"fastrpc_internal_mem_unmap",
            *(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10),
            *(undefined8 *)(param_2 + 0x18),lVar6,iVar2);
    if (plVar5 == (long *)0x0) goto LAB_00113fe0;
    mutex_lock(param_1 + 0x110);
    if ((*(int *)((long)plVar5 + 0x24) == 8) || (*(int *)((long)plVar5 + 0x24) == 4)) {
      uVar3 = _raw_spin_lock_irqsave(&DAT_001505c8);
      *plVar5 = (long)DAT_001505a8;
      if (DAT_001505a8 != (long *)0x0) {
        DAT_001505a8[1] = (long)plVar5;
      }
      DAT_001505a8 = plVar5;
      plVar5[1] = (long)&DAT_001505a8;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
    }
    else {
      plVar4 = (long *)(plVar5[2] + 0x18);
      lVar6 = *plVar4;
      *plVar5 = lVar6;
      if (lVar6 != 0) {
        *(long **)(lVar6 + 8) = plVar5;
      }
      *plVar4 = (long)plVar5;
      plVar5[1] = (long)plVar4;
    }
  }
  mutex_unlock(param_1 + 0x110);
LAB_00113fe0:
  mutex_unlock(param_1 + 0x140);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// fastrpc_internal_mmap @ 00114100 size=692
// signature: undefined fastrpc_internal_mmap(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl]
//------------------------------------------------------------

int fastrpc_internal_mmap(long param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 uVar6;
  long lVar7;
  long local_60;
  ulong local_58;
  long *local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  local_50 = (long *)0x0;
  local_60 = 0;
  if (*(int *)(param_1 + 0xe4) != 1) {
    lVar7 = sp_el0;
    _printk(&DAT_0014f8db,0x164d,lVar7 + 0x848,"fastrpc_internal_mmap",lVar7 + 0x848);
    iVar4 = -0x70;
    goto LAB_00114300;
  }
  mutex_lock(param_1 + 0x140);
  uVar1 = param_2[1];
  if ((uVar1 | 0x2000) == 0x3000) {
    if (*(char *)(param_1 + 0x22c) != '\0') {
LAB_001141d8:
      mutex_lock(param_1 + 0x110);
      iVar4 = fastrpc_mmap_create(param_1,*param_2,0,0,*(undefined8 *)(param_2 + 2),
                                  *(undefined8 *)(param_2 + 4),param_2[1],&local_50);
      mutex_unlock(param_1 + 0x110);
      plVar3 = local_50;
      if (iVar4 == 0) {
        iVar4 = param_2[1];
        lVar7 = 0;
        if ((iVar4 != 4) && (iVar4 != 8)) {
          lVar7 = local_50[0xb];
        }
        iVar4 = fastrpc_mmap_on_dsp(param_1,iVar4,lVar7,local_50[9],local_50[10],(int)local_50[0xd],
                                    &local_60);
        lVar7 = local_60;
        if (iVar4 == 0) {
          plVar3[0xe] = local_60;
          if ((param_2[1] == 8) || (param_2[1] == 4)) {
            uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
            *plVar3 = (long)DAT_001505a8;
            if (DAT_001505a8 != (long *)0x0) {
              DAT_001505a8[1] = (long)plVar3;
            }
            DAT_001505a8 = plVar3;
            plVar3[1] = (long)&DAT_001505a8;
            _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
          }
          goto LAB_001142f0;
        }
      }
      if (plVar3 != (long *)0x0) {
        mutex_lock(param_1 + 0x110);
        fastrpc_mmap_free(plVar3,0);
        mutex_unlock(param_1 + 0x110);
      }
      goto joined_r0x001143a8;
    }
    if (*(long *)(param_2 + 2) != 0) {
      lVar7 = sp_el0;
      puVar5 = &DAT_0014f706;
      uVar6 = 0x1658;
      goto LAB_0011439c;
    }
    iVar4 = fastrpc_buf_alloc(param_1,*(undefined8 *)(param_2 + 4),0x20010,uVar1,3,&local_58);
    uVar2 = local_58;
    if ((iVar4 != 0) ||
       (iVar4 = fastrpc_mmap_on_dsp(param_1,param_2[1],0,*(undefined8 *)(local_58 + 0x40),
                                    *(undefined8 *)(local_58 + 0x48),0,&local_60), iVar4 != 0))
    goto joined_r0x001143a8;
    *(long *)(uVar2 + 0x58) = local_60;
    lVar7 = local_60;
LAB_001142f0:
    iVar4 = 0;
    *(long *)(param_2 + 6) = lVar7;
  }
  else {
    if ((uVar1 != 8) || (*(char *)(param_1 + 0x22c) == '\0')) goto LAB_001141d8;
    lVar7 = sp_el0;
    puVar5 = &DAT_0014bf67;
    uVar6 = 0x166c;
LAB_0011439c:
    _printk(puVar5,uVar6,lVar7 + 0x848,"fastrpc_internal_mmap");
    iVar4 = -0x16;
joined_r0x001143a8:
    if ((local_58 != 0) && (local_58 < 0xfffffffffffff001)) {
      fastrpc_buf_free(local_58,0);
    }
  }
  mutex_unlock(param_1 + 0x140);
LAB_00114300:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// fastrpc_buf_alloc @ 001143b4 size=940
// signature: undefined fastrpc_buf_alloc(void)
// callers: [fastrpc_internal_invoke, fastrpc_create_persistent_headers, fastrpc_internal_mmap, fastrpc_init_create_dynamic_process]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
fastrpc_buf_alloc(long param_1,ulong param_2,undefined8 param_3,undefined4 param_4,int param_5,
                 long *param_6)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  long *plVar10;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0) || (*(long *)(param_1 + 0x68) == 0)) {
    uVar9 = 0xffffffcb;
    goto LAB_001146d4;
  }
  uVar3 = *(uint *)(param_1 + 0xc0);
  if (4 < uVar3) {
    uVar9 = 0xffffffd4;
    goto LAB_001146d4;
  }
  if ((param_2 == 0) || (DAT_0015064c <= param_2)) {
    _printk(&DAT_0014c3c9,"fastrpc_buf_alloc",param_2);
    uVar9 = 0xfffffff2;
    goto LAB_001146d4;
  }
  if (*(long *)(*(long *)(param_1 + 0x68) + 8) == 0) {
    uVar9 = 0xffffffed;
    goto LAB_001146d4;
  }
  lVar1 = param_1 + 0x10;
  _raw_spin_lock(lVar1);
  uVar6 = (ulong)*(uint *)(param_1 + 0x7c);
  if (((*(uint *)(param_1 + 0x7c) != 0) && (param_2 < 0x1001)) && (param_5 == 0)) {
    lVar8 = *(long *)(param_1 + 0x88);
    do {
      if (*(char *)(lVar8 + 0x68) == '\0') {
        *(undefined1 *)(lVar8 + 0x68) = 1;
        *param_6 = lVar8;
        _raw_spin_unlock(lVar1);
        goto LAB_001146d0;
      }
      lVar8 = lVar8 + 0x90;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  _raw_spin_unlock(lVar1);
  if (param_5 != 3) {
    _raw_spin_lock(lVar1);
    plVar7 = *(long **)(param_1 + 0x20);
    if (plVar7 != (long *)0x0) {
      plVar10 = (long *)0x0;
      do {
        if ((param_2 <= (ulong)plVar7[9]) &&
           ((plVar10 == (long *)0x0 || ((ulong)plVar7[9] < (ulong)plVar10[9])))) {
          plVar10 = plVar7;
        }
        plVar7 = (long *)*plVar7;
      } while (plVar7 != (long *)0x0);
      if (plVar10 != (long *)0x0) {
        plVar7 = (long *)plVar10[1];
        if (plVar7 != (long *)0x0) {
          lVar8 = *plVar10;
          *plVar7 = lVar8;
          if (lVar8 != 0) {
            *(long **)(lVar8 + 8) = plVar7;
          }
          *plVar10 = 0;
          plVar10[1] = 0;
        }
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
        _raw_spin_unlock(lVar1);
        uVar9 = 0;
        *(int *)((long)plVar10 + 100) = param_5;
        *param_6 = (long)plVar10;
        goto LAB_001146d4;
      }
    }
    _raw_spin_unlock(lVar1);
  }
  puVar5 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x90);
  if (puVar5 == (undefined8 *)0x0) {
    uVar9 = 0xfffffff4;
    goto LAB_001146d4;
  }
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[6] = param_1;
  puVar5[7] = 0;
  puVar5[9] = param_2;
  puVar5[10] = param_3;
  puVar5[0xb] = 0;
  plVar7 = puVar5 + 8;
  *plVar7 = 0;
  *(undefined4 *)(puVar5 + 0xc) = param_4;
  *(int *)((long)puVar5 + 100) = param_5;
  ktime_get_real_ts64(puVar5 + 0xe);
  uVar6 = dma_alloc_attrs(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),puVar5[9],plVar7,0xcc0,
                          puVar5[10]);
  puVar5[7] = uVar6;
  if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
    fastrpc_cached_buf_list_free(param_1);
    uVar6 = dma_alloc_attrs(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),puVar5[9],plVar7,0xcc0,
                            puVar5[10]);
    puVar5[7] = uVar6;
    if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) goto LAB_001145bc;
    lVar1 = sp_el0;
    _printk(&DAT_0014ec28,0x66c,lVar1 + 0x848,"fastrpc_buf_alloc",param_2);
    uVar9 = 0xffffff97;
LAB_00114674:
    ktime_get_real_ts64(puVar5 + 0x10);
    fastrpc_buf_free(puVar5,0);
  }
  else {
LAB_001145bc:
    uVar2 = *(uint *)(*(long *)(param_1 + 0x68) + 0x18);
    if (uVar2 == 0) {
      lVar8 = *plVar7;
    }
    else {
      lVar8 = *plVar7 + ((ulong)uVar2 << 0x20);
      *plVar7 = lVar8;
    }
    trace_fastrpc_dma_alloc(uVar3,lVar8,param_2,param_3,param_4);
    iVar4 = *(int *)(**(long **)(param_1 + 0xf0) + (long)(int)uVar3 * 0x6a68 + 0x9fc);
    if (iVar4 != 0) {
      local_80 = 8;
      uStack_78 = 0x600000003;
      uVar6 = (param_2 & 0xffffffff) + 0xfff & 0x1fffff000;
      if (uVar6 < 0x1001) {
        uVar6 = 0x1000;
      }
      uStack_6c = 7;
      local_70 = iVar4;
      iVar4 = qcom_scm_assign_mem(*plVar7,uVar6,&local_80,&uStack_78,2);
      if (iVar4 != 0) {
        uVar9 = 0xffffff9d;
        goto LAB_00114674;
      }
    }
    if (param_5 == 3) {
      plVar10 = puVar5 + 2;
      *plVar10 = 0;
      puVar5[3] = 0;
      _raw_spin_lock(lVar1);
      plVar7 = (long *)(param_1 + 0x30);
      lVar8 = *plVar7;
      *plVar10 = lVar8;
      if (lVar8 != 0) {
        *(long **)(lVar8 + 8) = plVar10;
      }
      *plVar7 = (long)plVar10;
      puVar5[3] = plVar7;
      _raw_spin_unlock(lVar1);
    }
    *param_6 = (long)puVar5;
    ktime_get_real_ts64(puVar5 + 0x10);
LAB_001146d0:
    uVar9 = 0;
  }
LAB_001146d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// fastrpc_mmap_on_dsp @ 00114760 size=712
// signature: undefined fastrpc_mmap_on_dsp(void)
// callers: [fastrpc_dev_map_dma, fastrpc_internal_mmap]
//------------------------------------------------------------

void fastrpc_mmap_on_dsp(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                        undefined8 param_5,int param_6,undefined8 *param_7)

{
  uint *puVar1;
  undefined4 uVar2;
  long lVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  undefined4 *puVar11;
  long lVar12;
  long lVar13;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  int iStack_fc;
  undefined8 local_f8;
  ulong local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined4 **local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 *local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  local_d0 = (undefined4 **)0x0;
  local_f0 = 0;
  local_108 = 0;
  if (param_1 == 0) {
    uVar6 = 0xfffffff7;
  }
  else {
    local_100 = *(undefined4 *)(param_1 + 0xbc);
    local_98 = &local_100;
    local_88 = &local_e8;
    uStack_90 = 0x18;
    local_78 = &local_108;
    bVar4 = *(int *)(*(long *)(param_1 + 0xf0) + 0xb8) == 0;
    uVar10 = 0x10;
    if (bVar4) {
      uVar10 = 1;
    }
    uStack_80 = 0x10;
    local_f0 = (ulong)uVar10;
    uStack_70 = 8;
    uVar2 = 0x2020100;
    if (!bVar4) {
      uVar2 = 0x4020100;
    }
    local_d0 = &local_98;
    uVar10 = *(uint *)(param_1 + 0xc0);
    local_d8 = CONCAT44(uVar2,1);
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    iStack_fc = (int)param_2;
    local_f8 = param_3;
    local_e8 = param_4;
    uStack_e0 = param_5;
    uVar6 = fastrpc_internal_invoke(param_1,param_2,1,&local_d8);
    *param_7 = local_108;
    lVar3 = gfa;
    if ((int)uVar6 == 0) {
      if ((int)param_2 == 8) {
        if (4 < uVar10) {
          lVar3 = sp_el0;
          _printk(&DAT_0014e617,0x13ee,lVar3 + 0x848,"fastrpc_mmap_on_dsp",uVar10);
          uVar6 = 0xffffffd4;
          goto LAB_00114948;
        }
        uVar6 = 0;
        if ((param_6 != 1) ||
           (lVar12 = gfa + (ulong)uVar10 * 0x6a68, *(long *)(lVar12 + 0xa00) == 0))
        goto LAB_00114948;
        lVar13 = gfa + (ulong)uVar10 * 0x6a68;
        local_110 = 8;
        iVar5 = *(int *)(lVar13 + 0xa10);
        if ((iVar5 < 0) || (lVar7 = __kmalloc((long)iVar5 << 3,0xdc0), lVar7 == 0)) {
          uVar6 = 0xffffffff;
          goto LAB_00114948;
        }
        puVar1 = (uint *)(lVar13 + 0xa10);
        if (*puVar1 == 0) {
          uVar8 = 0;
        }
        else {
          uVar9 = 0;
          puVar11 = (undefined4 *)(lVar7 + 4);
          do {
            lVar13 = uVar9 * 4;
            uVar9 = uVar9 + 1;
            puVar11[-1] = *(undefined4 *)(*(long *)(lVar12 + 0xa00) + lVar13);
            *puVar11 = *(undefined4 *)(*(long *)(lVar3 + (ulong)uVar10 * 0x6a68 + 0xa08) + lVar13);
            uVar8 = (ulong)*puVar1;
            puVar11 = puVar11 + 2;
          } while (uVar9 < uVar8);
        }
        iVar5 = qcom_scm_assign_mem(param_4,param_5,&local_110,lVar7,uVar8);
        kfree(lVar7);
        if (iVar5 != 0) {
          lVar3 = sp_el0;
          _printk(&DAT_0014bd5c,0x1409,lVar3 + 0x848,"fastrpc_mmap_on_dsp",iVar5,param_4,param_5);
          iVar5 = fastrpc_unmap_on_dsp(param_1,*param_7,param_5);
          if (iVar5 != 0) {
            _printk(&DAT_001503ff,0x1410,lVar3 + 0x848,"fastrpc_mmap_on_dsp",iVar5,param_4,param_5);
          }
          uVar6 = 0xffffff9d;
          goto LAB_00114948;
        }
      }
      uVar6 = 0;
    }
  }
LAB_00114948:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_handle_rpc_response @ 00114a2c size=1420
// signature: undefined fastrpc_handle_rpc_response(void)
// callers: [fastrpc_rpmsg_callback]
//------------------------------------------------------------

undefined8 fastrpc_handle_rpc_response(ulong *param_1,uint param_2,int param_3)

{
  ulong *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long *plVar6;
  long *plVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  undefined8 uVar12;
  uint *puVar13;
  long lVar14;
  uint uVar15;
  long lVar16;
  ulong uVar17;
  undefined8 *puVar18;
  long lVar19;
  uint uVar20;
  long lVar21;
  int *piVar22;
  ulong uVar23;
  long lVar24;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  long local_78;
  long local_70;
  long local_68;
  
  lVar19 = gfa;
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  InstructionSynchronizationBarrier();
  lVar14 = cntvct_el0;
  if (param_2 == 8) {
    uVar17 = *param_1;
    if ((uint)uVar17 < 0x400) {
      uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
      plVar7 = (long *)DAT_001505c0;
      do {
        plVar6 = plVar7;
        if (plVar6 == (long *)0x0) goto LAB_00114ef0;
        plVar7 = (long *)*plVar6;
      } while ((*(int *)((long)plVar6 + 0xbc) != (int)(uVar17 >> 0x20)) ||
              (*(int *)(plVar6 + 0x18) != param_3));
      uVar10 = _raw_spin_lock_irqsave(plVar6 + 0x4a);
      if (plVar6[(uVar17 >> 8 & 0xffffff) + 0x46] == 0) {
        lVar14 = sp_el0;
        uVar12 = 0x16eb;
LAB_00114ed8:
        _printk(&DAT_0014ec7c,uVar12,lVar14 + 0x848,"handle_remote_signal",uVar17 & 0xffffffff,
                uVar17 >> 0x20);
      }
      else {
        piVar22 = (int *)(plVar6[(uVar17 >> 8 & 0xffffff) + 0x46] + (uVar17 & 0xff) * 0x28 + 0x20);
        iVar2 = *piVar22;
        if (iVar2 - 1U < 2) {
          complete();
          *piVar22 = 2;
        }
        else if (iVar2 == 0) {
          lVar14 = sp_el0;
          uVar12 = 0x16e7;
          goto LAB_00114ed8;
        }
      }
      _raw_spin_unlock_irqrestore(plVar6 + 0x4a,uVar10);
LAB_00114ef0:
      puVar11 = &DAT_001505c8;
      goto LAB_00114f80;
    }
    lVar14 = sp_el0;
    _printk(&DAT_0014c8c7,0x16cd,lVar14 + 0x848,"handle_remote_signal",uVar17 & 0xffffffff,
            uVar17 >> 0x20);
  }
  else {
    if ((param_1 == (ulong *)0x0) || (param_2 < 0x10)) {
LAB_00114f0c:
      lVar14 = sp_el0;
      uVar9 = 0xffffff82;
      _printk(&DAT_0014ef30,0x1758,lVar14 + 0x848,"fastrpc_handle_rpc_response",param_1,param_2,
              0xffffff82);
      goto LAB_00114f88;
    }
    if (*param_1 == 0xabcdabcd) {
      if ((param_2 < 0x18) || ((int)param_1[1] != 4)) goto LAB_00114f0c;
      puVar18 = &DAT_001505c0;
      uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
      do {
        puVar18 = (undefined8 *)*puVar18;
        if (puVar18 == (undefined8 *)0x0) goto LAB_00114f74;
      } while (*(int *)((long)puVar18 + 0xbc) != *(int *)((long)param_1 + 0xc));
      puVar13 = (uint *)(puVar18 + 0xf);
      uVar15 = *puVar13;
      if (*puVar13 == 0) {
        uVar20 = 0;
      }
      else {
        do {
          Hint_Prefetch(puVar13,2,0,1);
          do {
            uVar3 = *puVar13;
            if (uVar3 != uVar15) break;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar13,0x10);
            if (bVar5) {
              *puVar13 = uVar15 + 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          uVar20 = uVar15;
        } while ((uVar15 != uVar3) && (uVar20 = 0, uVar15 = uVar3, uVar3 != 0));
      }
      if ((int)(uVar20 + 1 | uVar20) < 0) {
        refcount_warn_saturate(puVar13,0);
      }
      if (uVar20 != 0) {
        _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
        fastrpc_queue_pd_status(puVar18,param_3,(int)param_1[2],*(undefined4 *)(puVar18 + 0x16));
        fastrpc_file_put(puVar18);
        goto LAB_00114f84;
      }
      lVar14 = sp_el0;
      _printk(&DAT_0014c4e8,0x86b,lVar14 + 0x848,"fastrpc_notif_find_process",puVar18);
LAB_00114f74:
      puVar11 = &DAT_001505c8;
    }
    else {
      puVar1 = param_1;
      if (param_2 < 0x18) {
        puVar1 = (ulong *)0x0;
      }
      if (puVar1 == (ulong *)0x0) {
        local_80 = 0;
        local_7c = 0;
        local_84 = 0;
      }
      else {
        local_7c = (undefined4)puVar1[2];
        local_80 = *(int *)((long)puVar1 + 0xc);
        local_84 = *(undefined4 *)((long)puVar1 + 0x14);
      }
      local_78 = 0;
      local_70 = 0;
      ktime_get_real_ts64(&local_78);
      if (local_78 < 0x225c17d04) {
        if (local_78 < -0x225c17d03) {
          lVar21 = -0x8000000000000000;
        }
        else {
          lVar21 = local_70 + local_78 * 1000000000;
        }
      }
      else {
        lVar21 = 0x7fffffffffffffff;
      }
      uVar23 = *param_1;
      uVar17 = param_1[1];
      lVar24 = lVar19 + (long)param_3 * 0x6a68;
      uVar9 = _raw_spin_lock_irqsave(lVar24 + 0x6a50);
      uVar15 = *(uint *)(lVar24 + 0x2e4c);
      if (0x80 < uVar15) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x114fcc);
        (*pcVar8)();
      }
      lVar19 = lVar19 + (long)param_3 * 0x6a68;
      lVar16 = lVar19 + (ulong)uVar15 * 0x28;
      *(ulong *)(lVar16 + 0x5650) = uVar23;
      iVar2 = 0;
      if (uVar15 < 0x7f) {
        iVar2 = uVar15 + 1;
      }
      *(int *)(lVar16 + 0x5658) = (int)uVar17;
      *(int *)(lVar16 + 0x565c) = local_80;
      *(undefined4 *)(lVar16 + 0x5660) = local_7c;
      *(undefined4 *)(lVar16 + 0x5664) = local_84;
      *(long *)(lVar16 + 0x5668) = lVar21;
      *(ulong *)(lVar16 + 0x5670) = (ulong)(lVar14 * 10) / 0xc0;
      *(int *)(lVar24 + 0x2e4c) = iVar2;
      _raw_spin_unlock_irqrestore(lVar24 + 0x6a50,uVar9);
      uVar17 = *param_1;
      puVar11 = (undefined *)(lVar19 + 0x2e40);
      uVar9 = _raw_spin_lock_irqsave(puVar11);
      uVar17 = *(ulong *)(lVar19 + (uVar17 >> 6 & 0x3ff) * 8 + 0xe40);
      if ((((uVar17 == 0) || (0xfffffffffffff000 < uVar17)) ||
          (*(ulong *)(uVar17 + 0x100) != (*param_1 & 0xfffffffffffffffc))) ||
         (*(int *)(uVar17 + 0xf8) != -0x41122113)) {
        if ((local_80 == 3) || (uVar17 == 0)) {
          _raw_spin_unlock_irqrestore(puVar11,uVar9);
        }
        else {
          uVar23 = *param_1;
          uVar17 = *(ulong *)(uVar17 + 0x100);
          _raw_spin_unlock_irqrestore(puVar11,uVar9);
          if (uVar17 == (uVar23 & 0xfffffffffffffffc)) goto LAB_00114f0c;
        }
        uVar9 = 0;
        DAT_00150648 = DAT_00150648 + 1;
        goto LAB_00114f88;
      }
      if (((puVar1 != (ulong *)0x0) && (*(int *)((long)puVar1 + 0x14) != 2)) ||
         (4 < *(uint *)(*(long *)(uVar17 + 0x98) + 0xc0))) {
        _raw_spin_unlock_irqrestore(puVar11,uVar9);
        goto LAB_00114f0c;
      }
      context_notify_user(uVar17,(int)param_1[1],local_80,local_7c);
    }
LAB_00114f80:
    _raw_spin_unlock_irqrestore(puVar11,uVar9);
  }
LAB_00114f84:
  uVar9 = 0;
LAB_00114f88:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// context_notify_user @ 001151d8 size=628
// signature: undefined context_notify_user(void)
// callers: [fastrpc_handle_rpc_response]
//------------------------------------------------------------

void context_notify_user(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0x98);
  uVar3 = *(uint *)(lVar8 + 0xc0);
  if (4 < uVar3) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1154ac);
    (*pcVar6)();
  }
  if (*(int *)(lVar8 + 0x184) != 0) {
    if (0x209e8 < (ulong)uVar3 * 0x6a68) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(1,0x1154b0);
      (*pcVar6)();
    }
    lVar9 = DAT_00150638;
    if (((*(int *)(&DAT_00129d98 + (ulong)uVar3 * 0x6a68) == 1) ||
        (lVar9 = DAT_00150640, *(int *)(&DAT_00129d98 + (ulong)uVar3 * 0x6a68) == 0)) &&
       (lVar9 != 0)) {
      pm_wakeup_ws_event(lVar9,*(undefined4 *)(lVar8 + 0x1e8),1);
    }
  }
  *(undefined4 *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x110) = param_3;
  switch(param_3) {
  case 0:
  case 3:
    *(undefined1 *)(param_1 + 0x118) = 1;
    if (*(int *)(param_1 + 0x120) != 0) {
      lVar8 = *(long *)(param_1 + 0x98);
      uVar7 = _raw_spin_lock_irqsave(lVar8 + 0x1b8);
      if ((*(char *)(param_1 + 0x138) == '\0') && (*(long *)(param_1 + 0x18) != 0)) {
        plVar1 = (long *)(param_1 + 0x10);
        lVar9 = *(long *)(lVar8 + 0x50);
        *plVar1 = lVar9;
        if (lVar9 != 0) {
          *(long **)(lVar9 + 8) = plVar1;
        }
        *(long **)(lVar8 + 0x50) = plVar1;
        *(long **)(param_1 + 0x18) = (long *)(lVar8 + 0x50);
        piVar2 = (int *)(lVar8 + 0x198);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = *piVar2 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        *(undefined1 *)(param_1 + 0x138) = 1;
        __wake_up(lVar8 + 0x1a0,1,1,0);
      }
      _raw_spin_unlock_irqrestore(lVar8 + 0x1b8,uVar7);
    }
    complete(param_1 + 0x20);
    return;
  case 1:
    if (*(int *)(param_1 + 0x120) != 0) {
      lVar8 = *(long *)(param_1 + 0x98);
      uVar7 = _raw_spin_lock_irqsave(lVar8 + 0x1b8);
      if ((*(char *)(param_1 + 0x138) == '\0') && (*(long *)(param_1 + 0x18) != 0)) {
        plVar1 = (long *)(param_1 + 0x10);
        lVar9 = *(long *)(lVar8 + 0x50);
        *plVar1 = lVar9;
        if (lVar9 != 0) {
          *(long **)(lVar9 + 8) = plVar1;
        }
        *(long **)(lVar8 + 0x50) = plVar1;
        *(long **)(param_1 + 0x18) = (long *)(lVar8 + 0x50);
        piVar2 = (int *)(lVar8 + 0x198);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = *piVar2 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        *(undefined1 *)(param_1 + 0x138) = 1;
        __wake_up(lVar8 + 0x1a0,1,1,0);
      }
      _raw_spin_unlock_irqrestore(lVar8 + 0x1b8,uVar7);
      return;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x114) = param_4;
    if (*(int *)(param_1 + 0x120) != 0) {
      return;
    }
    break;
  default:
    goto switchD_001152ac_default;
  }
  complete(param_1 + 0x20);
switchD_001152ac_default:
  return;
}



//------------------------------------------------------------
// fastrpc_get_info @ 00115784 size=1540
// signature: undefined fastrpc_get_info(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_device_ioctl, fastrpc_set_session_info]
//------------------------------------------------------------

int fastrpc_get_info(long param_1,uint *param_2)

{
  char cVar1;
  bool bVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  size_t sVar10;
  char *param0;
  ulong uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  long lVar16;
  int *piVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  undefined1 auVar21 [16];
  undefined1 *puVar22;
  undefined8 local_88;
  ulong uStack_80;
  undefined8 local_78;
  undefined2 local_70;
  undefined8 local_68;
  
  lVar12 = (long)register0x00000008 + -0x60;
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  if (param_1 == 0) {
    iVar5 = -9;
    uVar7 = 0;
    goto LAB_001157fc;
  }
  lVar13 = param_1 + 0x10;
  uVar15 = *param_2;
  uVar18 = (ulong)uVar15;
  _raw_spin_lock(lVar13);
  if (*(char *)(param_1 + 0x2b5) != '\0') {
    _raw_spin_unlock(lVar13);
    lVar13 = sp_el0;
    uVar7 = _printk(&DAT_0014bfbf,0x1a45,lVar13 + 0x848,"fastrpc_get_info");
    iVar5 = -0x35;
    goto LAB_001157fc;
  }
  *(undefined1 *)(param_1 + 0x2b5) = 1;
  uVar7 = _raw_spin_unlock(lVar13);
  if (4 < uVar15) {
    iVar5 = -0x2c;
    goto LAB_001157fc;
  }
  lVar16 = sp_el0;
  lVar20 = *(long *)(*(long *)(lVar16 + 0x838) + 0x98);
  iVar5 = *(int *)(lVar20 + 4);
  uVar4 = iVar5 + 1;
  if ((int)uVar4 < 0) {
LAB_00115894:
    kfree(0);
  }
  else {
    uVar7 = -(ulong)(uVar4 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar4 << 2;
    puVar8 = (undefined4 *)__kmalloc(uVar7,0xdc0);
    if (puVar8 == (undefined4 *)0x0) goto LAB_00115894;
    if (uVar4 == 0) {
LAB_00115d64:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x115d68);
      (*pcVar3)();
    }
    *puVar8 = *(undefined4 *)(*(long *)(lVar16 + 0x838) + 8);
    if (iVar5 != 0) {
      lVar19 = 0;
      do {
        if (((uVar7 <= lVar19 + 4U) || ((long)(lVar19 + 4U) < 0)) || (uVar7 <= lVar19 + 4U))
        goto LAB_00115d64;
        *(undefined4 *)((long)puVar8 + lVar19 + 4) = *(undefined4 *)(lVar20 + 8 + lVar19);
        lVar19 = lVar19 + 4;
      } while ((ulong)uVar4 * 4 + -4 != lVar19);
    }
    sort(puVar8,(long)(int)uVar4,4,uint_cmp_func,0);
    *(undefined4 **)(param_1 + 0x188) = puVar8;
    *(uint *)(param_1 + 400) = uVar4;
  }
  local_88 = *(undefined8 *)(lVar16 + 0x848);
  local_70 = 0;
  local_78 = 0;
  lVar20 = lVar16 + 0x848;
  uStack_80 = *(ulong *)(lVar16 + 0x850) & 0xffffffffffffff;
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(lVar16 + 0x634);
  uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
  lVar19 = 0;
  while (frpc_tgid_usage_array[lVar19 + 1] != '\0') {
    lVar19 = lVar19 + 1;
    if (lVar19 == 0xff) goto code_r0x00115978;
  }
  uVar11 = lVar19 + 1;
  frpc_tgid_usage_array[lVar19 + 1] = 1;
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
  *(int *)(param_1 + 0xbc) = (int)uVar11;
  if ((int)lVar19 == -2) goto LAB_001159b4;
  _printk(&DAT_0014ce04,0x1a03,lVar20,"fastrpc_set_process_info",*(undefined4 *)(param_1 + 0xb8),
          uVar18,uVar11 & 0xffffffff);
  if (*(int *)(lVar16 + 0x634) != *(int *)(param_1 + 0xb4)) {
    *(undefined1 *)(param_1 + 0x1ec) = 1;
  }
  uVar4 = snprintf((char *)&local_78,10,"%d",(ulong)*(uint *)(lVar16 + 0x630));
  uVar7 = (ulong)uVar4;
  if (debugfs_root == 0) {
LAB_00115b30:
    lVar13 = gfa;
    if (*(int *)(param_1 + 0xc0) != -1) goto LAB_00115c84;
    if (((*(int *)(param_1 + 0x170) == 0) && (*(int *)(gfa + (ulong)uVar15 * 0x6a68 + 0xa20) == 1))
       && (*(char *)(gfa + (ulong)uVar15 * 0x6a68 + 0xa24) == '\0')) {
      uVar7 = _printk(&DAT_0014e1f8,0x1a68,lVar20,"fastrpc_get_info",uVar15);
      iVar5 = -0xd;
      goto LAB_001157fc;
    }
    *(uint *)(param_1 + 0xc0) = uVar15;
    mutex_lock(**(long **)(param_1 + 0xf0) + (ulong)uVar15 * 0x6a68 + 0x9a0);
    *(undefined8 *)(param_1 + 200) =
         *(undefined8 *)(**(long **)(param_1 + 0xf0) + (ulong)uVar15 * 0x6a68 + 0x9d8);
    lVar12 = **(long **)(param_1 + 0xf0);
    lVar16 = lVar12 + (ulong)uVar15 * 0x6a68;
    uVar7 = *(ulong *)(lVar16 + 0x9d0);
    if (uVar7 != 0) {
      uVar18 = 0;
      piVar17 = (int *)(lVar12 + (ulong)uVar15 * 0x6a68 + 0x70);
      goto LAB_00115bdc;
    }
    if (DAT_001505d0 != 0) {
      lVar13 = lVar12 + (ulong)uVar15 * 0x6a68;
      *(long *)(lVar13 + 0x18) = DAT_001505d0;
      uVar18 = 0;
      *(long *)(lVar13 + 0x20) = DAT_001505d0;
      goto LAB_00115c58;
    }
    uVar7 = mutex_unlock(lVar12 + (ulong)uVar15 * 0x6a68 + 0x9a0);
    iVar5 = -0x13;
    goto LAB_001157fc;
  }
  uVar7 = strnlen((char *)&local_88,0x10);
  if (uVar7 < 0x11) {
    if (uVar7 != 0x10) {
      sVar10 = strnlen((char *)&local_78,10);
      uVar11 = uVar7;
      if (10 < sVar10) goto LAB_00115d70;
      if (sVar10 != 10) {
        _raw_spin_lock(lVar13);
        if (*(int *)(param_1 + 0x180) != 0) {
          uVar7 = _raw_spin_unlock(lVar13);
          goto LAB_00115b30;
        }
        *(undefined4 *)(param_1 + 0x180) = 1;
        _raw_spin_unlock(lVar13);
        sVar10 = uVar7 + sVar10 + 5;
        param0 = (char *)__kmalloc(sVar10,0xdc0);
        *(char **)(param_1 + 0x178) = param0;
        if (param0 == (char *)0x0) {
          iVar5 = -0xc;
          uVar7 = 0;
          goto LAB_001157fc;
        }
        snprintf(param0,sVar10,"%.10s%s%d%s%d%s%d",(char *)&local_88,"_",*(int *)(lVar16 + 0x630),
                 "_",*(int *)(param_1 + 0xbc),"_",uVar15);
        uVar7 = debugfs_create_file(*(undefined8 *)(param_1 + 0x178),0x1a4,debugfs_root,param_1,
                                    debugfs_fops);
        *(ulong *)(param_1 + 0xf8) = uVar7;
        if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
          _printk(&DAT_0014fbad,&local_88,"fastrpc_set_process_info",
                  *(undefined8 *)(param_1 + 0x178));
          *(undefined8 *)(param_1 + 0xf8) = 0;
        }
        uVar7 = kfree(*(undefined8 *)(param_1 + 0x178));
        *(undefined8 *)(param_1 + 0x178) = 0;
        goto LAB_00115b30;
      }
    }
  }
  else {
LAB_00115d70:
    uVar7 = uVar11;
    fortify_panic("strnlen");
  }
  auVar21 = fortify_panic("__fortify_strlen");
  puVar8 = auVar21._8_8_;
  uVar11 = auVar21._0_8_;
  puVar22 = &UNK_00115d88;
  if (uVar11 == 0) {
    return -9;
  }
  if (0xfffffffffffff000 < uVar11) {
    return -9;
  }
  uVar14 = *(ulong *)(uVar11 + 0xf0);
  if (uVar14 == 0) {
    return -9;
  }
  if (0xfffffffffffff000 < uVar14) {
    return -9;
  }
  if (puVar8 == (undefined4 *)0x0) {
    return -0x16;
  }
  if ((undefined4 *)0xfffffffffffff000 < puVar8) {
    return -0x16;
  }
  switch(*puVar8) {
  case 1:
    if (puVar8[1] == 1) {
      iVar5 = *(int *)(uVar14 + 0xe0);
      if (iVar5 == 0) {
        return -0x16;
      }
    }
    else {
      iVar5 = 0x7fffffff;
    }
    if ((DAT_0015069c == 0) || (*(long *)(uVar11 + 0x100) == 0)) {
      lVar13 = sp_el0;
      _printk(&DAT_0014cb9c,0x1ac5,lVar13 + 0x848,"fastrpc_internal_control");
      return -0x16;
    }
    lVar16 = 0;
    uVar14 = 0;
    goto LAB_00115f64;
  case 2:
    *(undefined4 *)(uVar11 + 0xe8) = puVar8[1];
    return 0;
  case 3:
    puVar8[1] = 1;
    return 0;
  case 4:
    if (*(int *)(uVar11 + 0x170) == 1) {
      *(undefined4 *)(uVar11 + 0x184) = puVar8[1];
      return 0;
    }
    lVar13 = sp_el0;
    _printk(&DAT_001502a3,0x1af0,lVar13 + 0x848,"fastrpc_internal_control");
    return -1;
  case 5:
    if (*(int *)(uVar11 + 0x184) == 0) {
      return -0xd;
    }
    uVar15 = puVar8[1];
    uVar4 = *(uint *)(uVar11 + 0xc0);
    if (0x31 < uVar15) {
      uVar15 = 0x32;
    }
    *(uint *)(uVar11 + 0x1e8) = uVar15;
    if (4 < uVar4) {
      return -0x2c;
    }
    if (0x209e8 < (ulong)uVar4 * 0x6a68) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x1160b4);
      (*pcVar3)();
    }
    fastrpc_pm_awake(uVar11,*(undefined4 *)(&DAT_00129d98 + (ulong)uVar4 * 0x6a68));
    return 0;
  case 6:
    fastrpc_release_current_dsp_process(uVar11);
    fastrpc_queue_pd_status(uVar11,*(undefined4 *)(uVar11 + 0xc0),2,*(undefined4 *)(uVar11 + 0xb0));
    return 0;
  case 7:
    iVar5 = fastrpc_manage_poll_mode(uVar11,puVar8[1],puVar8[2]);
    return iVar5;
  case 8:
    lVar13 = uVar11 + 0x1b8;
    *(undefined1 *)(uVar11 + 0x2a9) = 1;
    uVar9 = _raw_spin_lock_irqsave(lVar13);
    piVar17 = (int *)(uVar11 + 0x198);
    Hint_Prefetch(piVar17,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(piVar17,0x10);
      if (bVar2) {
        *piVar17 = *piVar17 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    lVar12 = uVar11 + 0x1a0;
    break;
  case 9:
    lVar13 = uVar11 + 0x1e0;
    *(undefined1 *)(uVar11 + 0x2a8) = 1;
    uVar9 = _raw_spin_lock_irqsave(lVar13);
    piVar17 = (int *)(uVar11 + 0x1c0);
    Hint_Prefetch(piVar17,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(piVar17,0x10);
      if (bVar2) {
        *piVar17 = *piVar17 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    lVar12 = uVar11 + 0x1c8;
    break;
  default:
    return -0x38;
  }
  __wake_up(lVar12,1,1,0);
  _raw_spin_unlock_irqrestore(lVar13,uVar9);
  return 0;
code_r0x00115978:
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
  *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
LAB_001159b4:
  uVar7 = _printk(&DAT_0014fb64,0x19fe,lVar20,"fastrpc_set_process_info",0x100);
  iVar5 = -0x57;
  goto LAB_001157fc;
LAB_00115f64:
  if (*(int *)(uVar11 + 0x108) == 0) {
    uVar9 = get_cpu_device(uVar14 & 0xffffffff);
    iVar6 = dev_pm_qos_add_request(uVar9,*(long *)(uVar11 + 0x100) + lVar16,1,iVar5);
  }
  else {
    iVar6 = dev_pm_qos_update_request(*(long *)(uVar11 + 0x100) + lVar16,iVar5);
  }
  if (iVar6 < 0) {
    lVar16 = sp_el0;
    _printk(&DAT_0014c786,0x1ade,lVar16 + 0x848,"fastrpc_internal_control",iVar5,uVar14 & 0xffffffff
            ,iVar6,*(undefined4 *)(uVar11 + 0x108),lVar12,puVar22,uVar7,lVar13,lVar20,param_1,
            param_2,uVar18);
    goto LAB_00115fcc;
  }
  uVar14 = uVar14 + 1;
  lVar16 = lVar16 + 0x50;
  if (DAT_0015069c <= uVar14) {
    iVar6 = 0;
    *(undefined4 *)(uVar11 + 0x108) = 1;
LAB_00115fcc:
    fastrpc_send_cpuinfo_to_dsp(uVar11);
    return iVar6;
  }
  goto LAB_00115f64;
  while( true ) {
    uVar18 = uVar18 + 1;
    piVar17 = piVar17 + 0x18;
    if (uVar7 == uVar18) break;
LAB_00115bdc:
    if (uVar18 == 0xe) {
LAB_00115d6c:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x115d70);
      (*pcVar3)();
    }
    if ((((*piVar17 == 0) && (piVar17[-0xd] == 0)) && (piVar17[-0xb] == *(int *)(param_1 + 0xe8)))
       && ((*(int *)(param_1 + 0xec) == 0 || (piVar17[-10] == *(int *)(param_1 + 0xec))))) {
      *piVar17 = 1;
      if (uVar18 < *(ulong *)(lVar16 + 0x9d0)) {
        if (0xd < uVar18) goto LAB_00115d6c;
        piVar17[-0xe] = 0;
LAB_00115c58:
        *(ulong *)(param_1 + 0x68) = lVar12 + (ulong)uVar15 * 0x6a68 + uVar18 * 0x60 + 0x18;
        uVar7 = mutex_unlock(**(long **)(param_1 + 0xf0) + (ulong)uVar15 * 0x6a68 + 0x9a0);
LAB_00115c84:
        if (*(long *)(param_1 + 0x68) == 0) {
          iVar5 = -0x35;
        }
        else {
          iVar5 = 0;
          *param_2 = (uint)(*(int *)(*(long *)(param_1 + 0x68) + 0x1c) != 0);
        }
        goto LAB_001157fc;
      }
      lVar12 = **(long **)(param_1 + 0xf0);
      break;
    }
  }
  mutex_unlock(lVar12 + (ulong)uVar15 * 0x6a68 + 0x9a0);
  lVar13 = lVar13 + (ulong)uVar15 * 0x6a68;
  iVar5 = -0x57;
  uVar7 = _printk(&DAT_0014fa00,0x1a76,lVar20,"fastrpc_get_info",*(undefined8 *)(lVar13 + 0x9d0),
                  *(undefined8 *)(lVar13 + 8),0xffffffa9);
LAB_001157fc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return iVar5;
}



//------------------------------------------------------------
// fastrpc_internal_control @ 00115d8c size=836
// signature: undefined fastrpc_internal_control(void)
// callers: [compat_fastrpc_control, fastrpc_control]
//------------------------------------------------------------

int fastrpc_internal_control(ulong param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  
  if (param_1 == 0) {
    return -9;
  }
  if (0xfffffffffffff000 < param_1) {
    return -9;
  }
  uVar9 = *(ulong *)(param_1 + 0xf0);
  if (uVar9 == 0) {
    return -9;
  }
  if (0xfffffffffffff000 < uVar9) {
    return -9;
  }
  iVar6 = -0x16;
  if (param_2 == (undefined4 *)0x0) {
    return -0x16;
  }
  if ((undefined4 *)0xfffffffffffff000 < param_2) {
    return -0x16;
  }
  switch(*param_2) {
  case 1:
    if (param_2[1] == 1) {
      iVar11 = *(int *)(uVar9 + 0xe0);
      if (iVar11 == 0) {
        return -0x16;
      }
    }
    else {
      iVar11 = 0x7fffffff;
    }
    if ((DAT_0015069c == 0) || (*(long *)(param_1 + 0x100) == 0)) {
      lVar12 = sp_el0;
      _printk(&DAT_0014cb9c,0x1ac5,lVar12 + 0x848,"fastrpc_internal_control");
    }
    else {
      lVar12 = 0;
      uVar9 = 0;
      do {
        if (*(int *)(param_1 + 0x108) == 0) {
          uVar7 = get_cpu_device(uVar9 & 0xffffffff);
          iVar6 = dev_pm_qos_add_request(uVar7,*(long *)(param_1 + 0x100) + lVar12,1,iVar11);
        }
        else {
          iVar6 = dev_pm_qos_update_request(*(long *)(param_1 + 0x100) + lVar12,iVar11);
        }
        if (iVar6 < 0) {
          lVar12 = sp_el0;
          _printk(&DAT_0014c786,0x1ade,lVar12 + 0x848,"fastrpc_internal_control",iVar11,
                  uVar9 & 0xffffffff,iVar6,*(undefined4 *)(param_1 + 0x108));
          goto LAB_00115fcc;
        }
        uVar9 = uVar9 + 1;
        lVar12 = lVar12 + 0x50;
      } while (uVar9 < DAT_0015069c);
      iVar6 = 0;
      *(undefined4 *)(param_1 + 0x108) = 1;
LAB_00115fcc:
      fastrpc_send_cpuinfo_to_dsp(param_1);
    }
    break;
  case 2:
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0xe8) = param_2[1];
    break;
  case 3:
    iVar6 = 0;
    param_2[1] = 1;
    break;
  case 4:
    if (*(int *)(param_1 + 0x170) == 1) {
      iVar6 = 0;
      *(undefined4 *)(param_1 + 0x184) = param_2[1];
    }
    else {
      lVar12 = sp_el0;
      _printk(&DAT_001502a3,0x1af0,lVar12 + 0x848,"fastrpc_internal_control");
      iVar6 = -1;
    }
    break;
  case 5:
    if (*(int *)(param_1 + 0x184) == 0) {
      return -0xd;
    }
    uVar10 = param_2[1];
    uVar2 = *(uint *)(param_1 + 0xc0);
    if (0x31 < uVar10) {
      uVar10 = 0x32;
    }
    *(uint *)(param_1 + 0x1e8) = uVar10;
    if (4 < uVar2) {
      return -0x2c;
    }
    if (0x209e8 < (ulong)uVar2 * 0x6a68) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(1,0x1160b4);
      (*pcVar5)();
    }
    fastrpc_pm_awake(param_1,*(undefined4 *)(&DAT_00129d98 + (ulong)uVar2 * 0x6a68));
    goto LAB_00115f34;
  case 6:
    fastrpc_release_current_dsp_process(param_1);
    fastrpc_queue_pd_status
              (param_1,*(undefined4 *)(param_1 + 0xc0),2,*(undefined4 *)(param_1 + 0xb0));
    goto LAB_00115f34;
  case 7:
    iVar6 = fastrpc_manage_poll_mode(param_1,param_2[1],param_2[2]);
    break;
  case 8:
    lVar12 = param_1 + 0x1b8;
    *(undefined1 *)(param_1 + 0x2a9) = 1;
    uVar7 = _raw_spin_lock_irqsave(lVar12);
    piVar1 = (int *)(param_1 + 0x198);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar8 = param_1 + 0x1a0;
    goto LAB_00115f18;
  case 9:
    lVar12 = param_1 + 0x1e0;
    *(undefined1 *)(param_1 + 0x2a8) = 1;
    uVar7 = _raw_spin_lock_irqsave(lVar12);
    piVar1 = (int *)(param_1 + 0x1c0);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar8 = param_1 + 0x1c8;
LAB_00115f18:
    __wake_up(lVar8,1,1,0);
    _raw_spin_unlock_irqrestore(lVar12,uVar7);
LAB_00115f34:
    iVar6 = 0;
    break;
  default:
    iVar6 = -0x38;
  }
  return iVar6;
}



//------------------------------------------------------------
// fastrpc_send_cpuinfo_to_dsp @ 001160f0 size=248
// signature: undefined fastrpc_send_cpuinfo_to_dsp(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

void fastrpc_send_cpuinfo_to_dsp(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 local_90;
  undefined8 **ppuStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0xc0);
    if (uVar1 < 5) {
      lVar3 = gfa + (ulong)uVar1 * 0x6a68;
      local_50 = *(undefined8 *)(lVar3 + 0xe30);
      if (*(char *)(lVar3 + 0xe38) == '\0') {
        local_48 = &local_50;
        ppuStack_88 = &local_48;
        local_80 = 0;
        uStack_78 = 0;
        uStack_40 = 8;
        local_90 = 0x101000000000002;
        local_70 = 0;
        uStack_68 = 0;
        local_60 = 0;
        uStack_58 = 0;
        iVar2 = fastrpc_internal_invoke(param_1,param_2,1,&local_90);
        if (iVar2 == 0) {
          *(undefined1 *)(gfa + (ulong)uVar1 * 0x6a68 + 0xe38) = 1;
        }
      }
    }
    else {
      lVar3 = sp_el0;
      _printk(&DAT_0014e617,0x1255,lVar3 + 0x848,"fastrpc_send_cpuinfo_to_dsp",uVar1);
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
// fastrpc_pm_awake @ 001161e8 size=96
// signature: undefined fastrpc_pm_awake(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

void fastrpc_pm_awake(long param_1,int param_2)

{
  long lVar1;
  
  if ((*(int *)(param_1 + 0x184) != 0) &&
     (((lVar1 = DAT_00150638, param_2 == 1 || (lVar1 = DAT_00150640, param_2 == 0)) && (lVar1 != 0))
     )) {
    pm_wakeup_ws_event(lVar1,*(undefined4 *)(param_1 + 0x1e8),1);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_release_current_dsp_process @ 00116248 size=400
// signature: undefined fastrpc_release_current_dsp_process(void)
// callers: [fastrpc_file_put, fastrpc_internal_control]
//------------------------------------------------------------

void fastrpc_release_current_dsp_process(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 extraout_x1;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 **ppuStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = (undefined4 *)0x0;
  uStack_30 = 0;
  local_7c = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0xc0);
    if (((uVar1 < 5) && (*(long *)(param_1 + 0x68) != 0)) &&
       (iVar3 = verify_transport_device(uVar1,*(undefined4 *)(param_1 + 0xc4)), iVar3 == 0)) {
      if (*(int *)(**(long **)(param_1 + 0xf0) + (ulong)uVar1 * 0x6a68 + 0x9f8) == 0) {
        wait_for_completion(param_1 + 0x288);
      }
      else {
        local_7c = *(undefined4 *)(param_1 + 0xbc);
        local_38 = &local_7c;
        ppuStack_70 = &local_38;
        uStack_30 = 4;
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0x101000000000001;
        local_58 = 0;
        uStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        uVar4 = _raw_spin_lock_irqsave(*(long **)(param_1 + 0xf0) + 0x19);
        *(undefined4 *)(param_1 + 0xe0) = 2;
        _raw_spin_unlock_irqrestore(*(long *)(param_1 + 0xf0) + 200,uVar4);
        iVar3 = fastrpc_internal_invoke(param_1,extraout_x1,2,&local_78);
        uVar4 = _raw_spin_lock_irqsave(*(long *)(param_1 + 0xf0) + 200);
        *(undefined4 *)(param_1 + 0xe0) = 3;
        _raw_spin_unlock_irqrestore(*(long *)(param_1 + 0xf0) + 200,uVar4);
        if (iVar3 == 0) goto LAB_001162c4;
        if (*(int *)(param_1 + 0xe4) != 0) {
          lVar2 = sp_el0;
          _printk(&DAT_0014e0a3,0x131b,lVar2 + 0x848,"fastrpc_release_current_dsp_process",iVar3,
                  iVar3,lVar2 + 0x848);
        }
      }
    }
    if (*(long *)(param_1 + 0xf0) != 0) {
      uVar4 = _raw_spin_lock_irqsave(*(long *)(param_1 + 0xf0) + 200);
      *(undefined4 *)(param_1 + 0xe0) = 4;
      _raw_spin_unlock_irqrestore(*(long *)(param_1 + 0xf0) + 200,uVar4);
    }
  }
LAB_001162c4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_queue_pd_status @ 001163d8 size=260
// signature: undefined fastrpc_queue_pd_status(void)
// callers: [fastrpc_handle_rpc_response, fastrpc_internal_control, fastrpc_notify_drivers]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fastrpc_queue_pd_status(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  
  plVar5 = (long *)kmalloc_trace(___arch_copy_to_user,0xb20,0x20);
  if (plVar5 == (long *)0x0) {
    lVar4 = sp_el0;
    _printk(&DAT_0014dd9f,0x84e,lVar4 + 0x848,"fastrpc_queue_pd_status",0x20);
  }
  else {
    *(undefined4 *)((long)plVar5 + 0x14) = param_4;
    *(undefined4 *)(plVar5 + 3) = param_3;
    *(undefined4 *)(plVar5 + 2) = param_2;
    uVar6 = _raw_spin_lock_irqsave(param_1 + 0x1e0);
    puVar8 = *(undefined8 **)(param_1 + 0x60);
    uVar7 = __list_add_valid(plVar5,puVar8,param_1 + 0x58);
    if ((uVar7 & 1) != 0) {
      *(long **)(param_1 + 0x60) = plVar5;
      *plVar5 = param_1 + 0x58;
      plVar5[1] = (long)puVar8;
      *puVar8 = plVar5;
    }
    piVar1 = (int *)(param_1 + 0x1c0);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    __wake_up(param_1 + 0x1c8,1,1,0);
    _raw_spin_unlock_irqrestore(param_1 + 0x1e0,uVar6);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_manage_poll_mode @ 001164e8 size=264
// signature: undefined fastrpc_manage_poll_mode(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

undefined8 fastrpc_manage_poll_mode(long param_1,int param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((*(int *)(param_1 + 0xc0) == 3) && (*(int *)(param_1 + 0x21c) == 1)) {
    if (param_3 < 0x2711) {
      _raw_spin_lock(param_1 + 0x10);
      uVar1 = param_3;
      if (param_2 == 0) {
        uVar1 = 0;
      }
      *(bool *)(param_1 + 0x220) = param_2 != 0;
      *(uint *)(param_1 + 0x224) = uVar1;
      _raw_spin_unlock(param_1 + 0x10);
      lVar2 = sp_el0;
      _printk(&DAT_0014d20d,0x1a9f,lVar2 + 0x848,"fastrpc_manage_poll_mode",param_2,param_3);
      uVar3 = 0;
    }
    else {
      lVar2 = sp_el0;
      _printk(&DAT_001501e7,0x1a93,lVar2 + 0x848,"fastrpc_manage_poll_mode",param_3,10000);
      uVar3 = 0xffffffb6;
    }
  }
  else {
    lVar2 = sp_el0;
    _printk(&DAT_0014ecd0,0x1a8d,lVar2 + 0x848,"fastrpc_manage_poll_mode",
            *(undefined4 *)(param_1 + 0x21c));
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



//------------------------------------------------------------
// fastrpc_setmode @ 001165f4 size=88
// signature: undefined fastrpc_setmode(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

undefined8 fastrpc_setmode(uint param_1,long param_2)

{
  if (param_1 < 2) {
    *(uint *)(param_2 + 0xa8) = param_1;
    return 0;
  }
  if (param_1 == 2) {
    *(undefined4 *)(param_2 + 0xac) = 2;
    return 0;
  }
  if (param_1 != 4) {
    return 0xffffffe7;
  }
  if (*(char *)(param_2 + 0x2b4) == '\0') {
    *(undefined4 *)(param_2 + 0xb0) = 1;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// fastrpc_control @ 00116650 size=584
// signature: undefined fastrpc_control(void)
// callers: [fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fastrpc_control(int *param_1,ulong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  int iVar3;
  size_t __n;
  uint uVar4;
  ulong uVar5;
  
  puVar1 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 < 0x7ffffffff5) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    __n = __arch_copy_from_user(param_1,param_2 & 0xff7fffffffffffff,0xc);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    if (__n == 0) goto LAB_00116740;
  }
  else {
    __n = 0xc;
  }
  memset((void *)((long)param_1 + (0xc - __n)),0,__n);
  if ((int)__n != 0) {
    return 0xfffffff2;
  }
LAB_00116740:
  uVar5 = fastrpc_internal_control(param_3,param_1);
  if ((int)uVar5 == 0) {
    if (*param_1 == 3) {
      if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
         (uVar5 = param_2, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
        uVar5 = param_2 & (long)(param_2 << 8) >> 8;
      }
      iVar3 = 0xc;
      if (uVar5 < 0x7ffffffff5) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar1[1];
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
        iVar3 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,param_1,0xc);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
      }
      uVar4 = 0;
      if (iVar3 != 0) {
        uVar4 = 0xfffffff2;
      }
      uVar5 = (ulong)uVar4;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// fastrpc_dspsignal_signal @ 001168cc size=296
// signature: undefined fastrpc_dspsignal_signal(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_dspsignal_signal]
//------------------------------------------------------------

undefined4 fastrpc_dspsignal_signal(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (*param_2 < 0x400) {
    uVar2 = *(uint *)(param_1 + 0xc0);
    if ((uVar2 < 5) && (*(long *)(param_1 + 0x68) != 0)) {
      lVar4 = **(long **)(param_1 + 0xf0) + (ulong)uVar2 * 0x6a68;
      lVar1 = lVar4 + 0x9a0;
      mutex_lock(lVar1);
      if (*(long *)(param_1 + 200) == *(long *)(lVar4 + 0x9d8)) {
        local_50 = CONCAT44(*(undefined4 *)(param_1 + 0xbc),*param_2);
        uVar3 = fastrpc_transport_send(uVar2,&local_50,8,*(undefined4 *)(param_1 + 0xc4));
        mutex_unlock(lVar1);
      }
      else {
        mutex_unlock(lVar1);
        uVar3 = 0xffffff98;
      }
      goto LAB_00116a68;
    }
  }
  else {
    lVar1 = sp_el0;
    _printk(&DAT_0014d871,0x1bae,lVar1 + 0x848,"fastrpc_dspsignal_signal",*param_2,
            *(undefined4 *)(param_1 + 0xb8));
  }
  uVar3 = 0xffffffcb;
LAB_00116a68:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// fastrpc_dspsignal_wait @ 00116aa4 size=564
// signature: undefined fastrpc_dspsignal_wait(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_dspsignal_wait]
//------------------------------------------------------------

ulong fastrpc_dspsignal_wait(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 *puVar9;
  int *piVar10;
  
  uVar2 = param_2[1];
  uVar5 = __usecs_to_jiffies(uVar2);
  uVar3 = *param_2;
  if (0x3ff < uVar3) {
    lVar1 = sp_el0;
    _printk(&DAT_0014ba27,0x1bda,lVar1 + 0x848,"fastrpc_dspsignal_wait",uVar3);
    uVar8 = 0xffffffea;
    goto LAB_00116c48;
  }
  if ((4 < *(uint *)(param_1 + 0xc0)) || (*(long *)(param_1 + 0x68) == 0)) {
    uVar8 = 0xffffffcb;
    goto LAB_00116c48;
  }
  lVar1 = param_1 + 0x250;
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  lVar7 = *(long *)(param_1 + ((ulong)(uVar3 >> 5) & 0x7fffff8) + 0x230);
  if (lVar7 != 0) {
    puVar9 = (undefined4 *)(lVar7 + ((ulong)uVar3 & 0xff) * 0x28);
    if (puVar9 != (undefined4 *)0x0) {
      piVar10 = (int *)(lVar7 + ((ulong)uVar3 & 0xff) * 0x28 + 0x20);
      uVar8 = 0xfffffffc;
      switch(*piVar10) {
      case 0:
        goto switchD_00116b60_caseD_0;
      case 1:
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        if (uVar2 == 0xffffffff) {
          iVar4 = wait_for_completion_interruptible(param_2[1],puVar9);
          uVar8 = (ulong)iVar4;
        }
        else {
          uVar8 = wait_for_completion_interruptible_timeout(puVar9,uVar5);
          if (uVar8 == 0) {
            uVar8 = 0xffffff92;
            goto LAB_00116c48;
          }
        }
        if ((long)uVar8 < 0) {
          lVar1 = sp_el0;
          _printk(&DAT_0014d111,0x1c0e,lVar1 + 0x848,"fastrpc_dspsignal_wait",uVar3,
                  uVar8 & 0xffffffff);
          goto LAB_00116c48;
        }
        uVar6 = _raw_spin_lock_irqsave(lVar1);
        iVar4 = *piVar10;
        if ((iVar4 == 0) || (iVar4 == 3)) {
          uVar8 = 0xfffffffc;
        }
        else {
          if (iVar4 != 2) goto switchD_00116b60_default;
          uVar8 = 0;
          *piVar10 = 1;
        }
        break;
      case 2:
        uVar8 = 0;
        *puVar9 = 0;
        *piVar10 = 1;
        break;
      case 3:
        break;
      default:
switchD_00116b60_default:
        uVar8 = 0;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar6);
      goto LAB_00116c48;
    }
  }
switchD_00116b60_caseD_0:
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  lVar1 = sp_el0;
  _printk(&DAT_0014d389,0x1bee,lVar1 + 0x848,"fastrpc_dspsignal_wait",uVar3);
  uVar8 = 0xfffffffe;
LAB_00116c48:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// fastrpc_dspsignal_create @ 00116e40 size=440
// signature: undefined fastrpc_dspsignal_create(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_dspsignal_create]
//------------------------------------------------------------

undefined8 fastrpc_dspsignal_create(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  undefined4 *puVar7;
  long lVar8;
  
  uVar3 = *param_2;
  if (uVar3 < 0x400) {
    if ((*(uint *)(param_1 + 0xc0) < 5) && (*(long *)(param_1 + 0x68) != 0)) {
      lVar1 = param_1 + 600;
      mutex_lock(lVar1);
      lVar2 = param_1 + 0x250;
      uVar4 = _raw_spin_lock_irqsave(lVar2);
      param_1 = param_1 + ((ulong)(uVar3 >> 5) & 0x7fffff8);
      lVar5 = *(long *)(param_1 + 0x230);
      if (lVar5 == 0) {
        _raw_spin_unlock_irqrestore(lVar2,uVar4);
        lVar5 = kmalloc_large(0x2800,0xdc0);
        if (lVar5 == 0) {
          lVar2 = sp_el0;
          _printk(&DAT_0014dbcc,0x1c46,lVar2 + 0x848,"fastrpc_dspsignal_create");
          mutex_unlock(lVar1);
          return 0xfffffff4;
        }
        lVar8 = 0x100;
        puVar7 = (undefined4 *)(lVar5 + 0x20);
        do {
          puVar7[-8] = 0;
          __init_swait_queue_head(puVar7 + -6,"&x->wait",&init_completion___key);
          lVar8 = lVar8 + -1;
          *puVar7 = 0;
          puVar7 = puVar7 + 10;
        } while (lVar8 != 0);
        uVar4 = _raw_spin_lock_irqsave(lVar2);
        *(long *)(param_1 + 0x230) = lVar5;
      }
      piVar6 = (int *)(lVar5 + (ulong)(uVar3 & 0xff) * 0x28 + 0x20);
      if (*piVar6 == 0) {
        *piVar6 = 1;
        *(undefined4 *)(lVar5 + (ulong)(uVar3 & 0xff) * 0x28) = 0;
        _raw_spin_unlock_irqrestore(lVar2,uVar4);
        mutex_unlock(lVar1);
        uVar4 = 0;
      }
      else {
        _raw_spin_unlock_irqrestore(lVar2,uVar4);
        mutex_unlock(lVar1);
        lVar1 = sp_el0;
        _printk(&DAT_0014c007,0x1c5b,lVar1 + 0x848,"fastrpc_dspsignal_create",uVar3,*piVar6);
        uVar4 = 0xfffffff0;
      }
    }
    else {
      uVar4 = 0xffffffcb;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// fastrpc_dspsignal_destroy @ 00116ffc size=240
// signature: undefined fastrpc_dspsignal_destroy(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_dspsignal_destroy]
//------------------------------------------------------------

undefined8 fastrpc_dspsignal_destroy(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  int *piVar5;
  
  uVar2 = *param_2;
  if (uVar2 < 0x400) {
    if ((*(uint *)(param_1 + 0xc0) < 5) && (*(long *)(param_1 + 0x68) != 0)) {
      lVar1 = param_1 + 0x250;
      uVar3 = _raw_spin_lock_irqsave(lVar1);
      lVar4 = *(long *)(param_1 + ((ulong)(uVar2 >> 5) & 0x7fffff8) + 0x230);
      if (((lVar4 != 0) && (lVar4 + (ulong)(uVar2 & 0xff) * 0x28 != 0)) &&
         (piVar5 = (int *)(lVar4 + (ulong)(uVar2 & 0xff) * 0x28 + 0x20), *piVar5 != 0)) {
        *piVar5 = 0;
        complete_all();
        _raw_spin_unlock_irqrestore(lVar1,uVar3);
        return 0;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      lVar1 = sp_el0;
      _printk(&DAT_0014f380,0x1c8c,lVar1 + 0x848,"fastrpc_dspsignal_destroy",uVar2);
      uVar3 = 0xfffffffe;
    }
    else {
      uVar3 = 0xffffffcb;
    }
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// fastrpc_dspsignal_cancel_wait @ 001170f0 size=272
// signature: undefined fastrpc_dspsignal_cancel_wait(void)
// callers: [fastrpc_device_ioctl, compat_fastrpc_dspsignal_cancel_wait]
//------------------------------------------------------------

undefined8 fastrpc_dspsignal_cancel_wait(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  ulong uVar7;
  
  uVar2 = *param_2;
  if (0x3ff < uVar2) {
    return 0xffffffea;
  }
  if ((4 < *(uint *)(param_1 + 0xc0)) || (*(long *)(param_1 + 0x68) == 0)) {
    return 0xffffffcb;
  }
  lVar1 = param_1 + 0x250;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  lVar5 = *(long *)(param_1 + ((ulong)(uVar2 >> 5) & 0x7fffff8) + 0x230);
  if ((lVar5 == 0) || (uVar7 = (ulong)uVar2 & 0xff, lVar5 + uVar7 * 0x28 == 0)) {
LAB_001171c8:
    _raw_spin_unlock_irqrestore(lVar1,uVar4);
    lVar1 = sp_el0;
    _printk(&DAT_0014dc0c,0x1cbc,lVar1 + 0x848,"fastrpc_dspsignal_cancel_wait",(ulong)uVar2);
    return 0xfffffffe;
  }
  piVar6 = (int *)(lVar5 + uVar7 * 0x28 + 0x20);
  iVar3 = *piVar6;
  if (iVar3 != 3) {
    if (iVar3 == 0) goto LAB_001171c8;
    *piVar6 = 3;
    complete_all();
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  return 0;
}



//------------------------------------------------------------
// fastrpc_restart_drivers @ 001172bc size=108
// signature: undefined fastrpc_restart_drivers(void)
// callers: []
//------------------------------------------------------------

void fastrpc_restart_drivers(int param_1)

{
  long lVar1;
  
  fastrpc_notify_drivers();
  mutex_lock(gfa + (long)param_1 * 0x6a68 + 0x9a0);
  lVar1 = gfa + (long)param_1 * 0x6a68;
  *(long *)(lVar1 + 0x9d8) = *(long *)(lVar1 + 0x9d8) + 1;
  mutex_unlock(gfa + (long)param_1 * 0x6a68 + 0x9a0);
  return;
}



//------------------------------------------------------------
// fastrpc_notify_drivers @ 00117328 size=496
// signature: undefined fastrpc_notify_drivers(void)
// callers: [fastrpc_restart_drivers, fastrpc_restart_notifier_cb]
//------------------------------------------------------------

void fastrpc_notify_drivers(int param_1)

{
  long *plVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  long *plVar13;
  
  uVar5 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if (DAT_001505c0 != (long *)0x0) {
    uVar6 = sp_el0;
    plVar10 = DAT_001505c0;
    do {
      plVar9 = (long *)*plVar10;
      if ((int)plVar10[0x18] == param_1) {
        fastrpc_queue_pd_status(plVar10,param_1,4,(int)plVar10[0x16]);
        uVar6 = _raw_spin_lock_irqsave(plVar10 + 2);
        plVar12 = (long *)plVar10[7];
        while (plVar13 = plVar12, plVar12 != (long *)0x0) {
          while( true ) {
            *(undefined1 *)(plVar13 + 0x23) = 1;
            plVar12 = (long *)*plVar13;
            *(undefined4 *)(plVar13 + 8) = 0xffffff98;
            if (((int)plVar13[0x24] == 0) || (*(char *)((long)plVar13 + 0x16c) == '\0')) break;
            lVar11 = plVar13[0x13];
            uVar7 = _raw_spin_lock_irqsave(lVar11 + 0x1b8);
            if (((char)plVar13[0x27] == '\0') && (plVar13[3] != 0)) {
              plVar1 = plVar13 + 2;
              lVar8 = *(long *)(lVar11 + 0x50);
              *plVar1 = lVar8;
              if (lVar8 != 0) {
                *(long **)(lVar8 + 8) = plVar1;
              }
              *(long **)(lVar11 + 0x50) = plVar1;
              plVar13[3] = lVar11 + 0x50;
              piVar2 = (int *)(lVar11 + 0x198);
              Hint_Prefetch(piVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                if (bVar4) {
                  *piVar2 = *piVar2 + 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              *(undefined1 *)(plVar13 + 0x27) = 1;
              __wake_up(lVar11 + 0x1a0,1,1,0);
            }
            _raw_spin_unlock_irqrestore(lVar11 + 0x1b8,uVar7);
            plVar13 = plVar12;
            if (plVar12 == (long *)0x0) goto LAB_001173d8;
          }
          complete(plVar13 + 4);
        }
LAB_001173d8:
        plVar12 = (long *)plVar10[8];
        while (plVar12 != (long *)0x0) {
          lVar11 = *plVar12;
          *(undefined1 *)(plVar12 + 0x23) = 1;
          *(undefined4 *)(plVar12 + 8) = 0xffffff98;
          complete((int)plVar10[0x18],plVar12 + 4);
          plVar12 = (long *)lVar11;
        }
        _raw_spin_unlock_irqrestore(plVar10 + 2,uVar6);
      }
      plVar10 = plVar9;
    } while (plVar9 != (long *)0x0);
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar5);
  return;
}



//------------------------------------------------------------
// fastrpc_dev_map_dma @ 0011769c size=656
// signature: undefined fastrpc_dev_map_dma(void)
// callers: [fastrpc_driver_invoke]
//------------------------------------------------------------

void fastrpc_dev_map_dma(long param_1,undefined8 *param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  local_50 = 0;
  uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if ((param_1 == 0) || (*(char *)(param_1 + 0x3b0) == '\x01')) {
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
    lVar7 = -3;
    goto LAB_0011790c;
  }
  lVar7 = *(long *)(param_1 + 0x3a8);
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
  if (lVar7 == 0) {
    lVar7 = -9;
    goto LAB_0011790c;
  }
  puVar8 = (uint *)(lVar7 + 0x78);
  uVar9 = *puVar8;
  if (*puVar8 == 0) {
    uVar10 = 0;
  }
  else {
    do {
      Hint_Prefetch(puVar8,2,0,1);
      do {
        uVar1 = *puVar8;
        if (uVar1 != uVar9) break;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar8,0x10);
        if (bVar3) {
          *puVar8 = uVar9 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar10 = uVar9;
    } while ((uVar9 != uVar1) && (uVar10 = 0, uVar9 = uVar1, uVar1 != 0));
  }
  if ((int)(uVar10 + 1 | uVar10) < 0) {
    refcount_warn_saturate(puVar8,0);
    if (uVar10 != 0) goto LAB_00117798;
LAB_00117890:
    lVar4 = sp_el0;
    _printk(&DAT_0014c4e8,0x2228,lVar4 + 0x848,"fastrpc_dev_map_dma",lVar7);
    iVar5 = -2;
  }
  else {
    if (uVar10 == 0) goto LAB_00117890;
LAB_00117798:
    mutex_lock(lVar7 + 0x140);
    uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if (*(int *)(lVar7 + 0xe0) == 0) {
      *(undefined1 *)(lVar7 + 0x218) = 1;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
      mutex_lock(lVar7 + 0x110);
      iVar5 = fastrpc_mmap_create(lVar7,0xffffffff,*param_2,*(undefined4 *)(param_2 + 1),0,
                                  param_2[2],6,&local_50);
      mutex_unlock(lVar7 + 0x110);
      lVar4 = local_50;
      if ((iVar5 == 0) &&
         (iVar5 = fastrpc_mmap_on_dsp(lVar7,*(undefined4 *)(local_50 + 0x24),0,
                                      *(undefined8 *)(local_50 + 0x48),
                                      *(undefined8 *)(local_50 + 0x50),
                                      *(undefined4 *)(local_50 + 0x68),&local_58), iVar5 == 0)) {
        *(undefined8 *)(lVar4 + 0x70) = local_58;
        param_2[3] = local_58;
      }
      else if (lVar4 != 0) {
        mutex_lock(lVar7 + 0x110);
        fastrpc_mmap_free(lVar4,0);
        mutex_unlock(lVar7 + 0x110);
      }
    }
    else {
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
      iVar5 = -3;
    }
  }
  uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if ((*(int *)(lVar7 + 0xe0) != 0) && (*(char *)(lVar7 + 0x218) != '\0')) {
    complete(lVar7 + 0x1f8);
  }
  *(undefined1 *)(lVar7 + 0x218) = 0;
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
  mutex_unlock(lVar7 + 0x140);
  if (uVar10 != 0) {
    fastrpc_file_put(lVar7);
  }
  lVar7 = (long)iVar5;
LAB_0011790c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_file_put @ 00117940 size=1532
// signature: undefined fastrpc_file_put(void)
// callers: [fastrpc_device_ioctl, fastrpc_handle_rpc_response, cleanup_module, fastrpc_dev_unmap_dma, fastrpc_device_release, fastrpc_dev_map_dma, fastrpc_debugfs_read, fastrpc_ramdump_collection]
//------------------------------------------------------------

void fastrpc_file_put(long *param_1)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  bool bVar16;
  
  if (param_1 != (long *)0x0) {
    plVar11 = param_1 + 0xf;
    Hint_Prefetch(plVar11,2,0,1);
    do {
      iVar5 = (int)*plVar11;
      cVar6 = '\x01';
      bVar16 = (bool)ExclusiveMonitorPass(plVar11,0x10);
      if (bVar16) {
        *(int *)plVar11 = iVar5 + -1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (iVar5 != 1) {
      if (iVar5 < 1) {
        refcount_warn_saturate(plVar11,3);
        return;
      }
      return;
    }
    DataMemoryBarrier(2,1);
    uVar3 = *(uint *)(param_1 + 0x18);
    uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if (param_1[0x3e] == 0) {
      bVar16 = true;
    }
    else {
      *(undefined1 *)(param_1[0x3e] + 0x3b0) = 1;
      bVar16 = true;
      plVar11 = (long *)param_1[0x3e];
      if (*(int *)((long)plVar11 + 0x3b4) == 0) {
        plVar12 = (long *)plVar11[1];
        if (plVar12 == (long *)0x0) {
          bVar16 = false;
        }
        else {
          lVar13 = *plVar11;
          *plVar12 = lVar13;
          if (lVar13 != 0) {
            *(long **)(lVar13 + 8) = plVar12;
          }
          bVar16 = false;
          *plVar11 = 0;
          plVar11[1] = 0;
        }
      }
    }
    *(undefined4 *)(param_1 + 0x1c) = 1;
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
    fastrpc_release_current_dsp_process(param_1);
    uVar9 = _raw_spin_lock_irqsave(param_1[0x1e] + 200);
    if ((char)param_1[0x43] != '\0') {
      _raw_spin_unlock_irqrestore(param_1[0x1e] + 200,uVar9);
      wait_for_completion(param_1 + 0x3f);
      uVar9 = _raw_spin_lock_irqsave(param_1[0x1e] + 200);
    }
    plVar11 = (long *)param_1[1];
    if (plVar11 != (long *)0x0) {
      lVar13 = *param_1;
      *plVar11 = lVar13;
      if (lVar13 != 0) {
        *(long **)(lVar13 + 8) = plVar11;
      }
      *param_1 = 0;
      param_1[1] = 0;
    }
    *(undefined1 *)(param_1 + 0x43) = 0;
    *(undefined4 *)(param_1 + 0x45) = 0;
    _raw_spin_unlock_irqrestore(param_1[0x1e] + 200,uVar9);
    if (param_1[0xd] != 0) {
      uVar9 = _raw_spin_lock_irqsave(param_1 + 0x37);
      plVar11 = param_1 + 0x33;
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar7) {
          *(int *)plVar11 = (int)*plVar11 + 1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      __wake_up(param_1 + 0x34,1,1,0);
      _raw_spin_unlock_irqrestore(param_1 + 0x37,uVar9);
      plVar11 = param_1 + 0x3c;
      uVar9 = _raw_spin_lock_irqsave(plVar11);
      plVar12 = param_1 + 0x38;
      Hint_Prefetch(plVar12,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(plVar12,0x10);
        if (bVar7) {
          *(int *)plVar12 = (int)*plVar12 + 1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      __wake_up(param_1 + 0x39,1,1,0);
      _raw_spin_unlock_irqrestore(plVar11,uVar9);
      uVar9 = _raw_spin_lock_irqsave(param_1[0x1e] + 200);
      uVar14 = param_1[0xe];
      if ((uVar14 == 0) || (0xfffffffffffff000 < uVar14)) {
        _raw_spin_unlock_irqrestore(param_1[0x1e] + 200,uVar9);
      }
      else {
        param_1[0xe] = 0;
        _raw_spin_unlock_irqrestore(param_1[0x1e] + 200,uVar9);
        fastrpc_buf_free(uVar14,0);
      }
      plVar12 = param_1 + 2;
      while( true ) {
        _raw_spin_lock(plVar12);
        plVar15 = (long *)param_1[8];
        if (plVar15 == (long *)0x0) break;
        plVar10 = (long *)plVar15[1];
        if (plVar10 != (long *)0x0) {
          lVar13 = *plVar15;
          *plVar10 = lVar13;
          if (lVar13 != 0) {
            *(long **)(lVar13 + 8) = plVar10;
          }
          *plVar15 = 0;
          plVar15[1] = 0;
        }
        *(int *)(param_1 + 9) = (int)param_1[9] + -1;
        _raw_spin_unlock(plVar12);
        context_free(plVar15);
      }
      _raw_spin_unlock(plVar12);
      while( true ) {
        _raw_spin_lock(plVar12);
        plVar15 = (long *)param_1[7];
        if (plVar15 == (long *)0x0) break;
        plVar10 = (long *)plVar15[1];
        if (plVar10 != (long *)0x0) {
          lVar13 = *plVar15;
          *plVar10 = lVar13;
          if (lVar13 != 0) {
            *(long **)(lVar13 + 8) = plVar10;
          }
          *plVar15 = 0;
          plVar15[1] = 0;
        }
        *(int *)(param_1 + 9) = (int)param_1[9] + -1;
        _raw_spin_unlock(plVar12);
        context_free(plVar15);
      }
      _raw_spin_unlock(plVar12);
      uVar9 = _raw_spin_lock_irqsave(plVar11);
      plVar15 = (long *)param_1[0xb];
      while (plVar15 != param_1 + 0xb) {
        plVar10 = (long *)*plVar15;
        uVar14 = __list_del_entry_valid(plVar15);
        if ((uVar14 & 1) != 0) {
          lVar13 = *plVar15;
          plVar2 = (long *)plVar15[1];
          *(long **)(lVar13 + 8) = plVar2;
          *plVar2 = lVar13;
        }
        *plVar15 = (long)plVar15;
        plVar15[1] = (long)plVar15;
        plVar2 = param_1 + 0x38;
        Hint_Prefetch(plVar2,2,0,1);
        do {
          cVar6 = '\x01';
          bVar7 = (bool)ExclusiveMonitorPass(plVar2,0x10);
          if (bVar7) {
            *(int *)plVar2 = (int)*plVar2 + -1;
            cVar6 = ExclusiveMonitorsStatus();
          }
        } while (cVar6 != '\0');
        kfree(plVar15);
        plVar15 = plVar10;
      }
      _raw_spin_unlock_irqrestore(plVar11,uVar9);
      fastrpc_cached_buf_list_free(param_1);
      if ((param_1[0x11] != 0) && ((ulong)param_1[0x11] < 0xfffffffffffff001)) {
        kfree();
      }
      uVar14 = param_1[0x10];
      if ((uVar14 != 0) && (uVar14 < 0xfffffffffffff001)) {
        fastrpc_buf_free(uVar14,0);
      }
      mutex_lock(param_1 + 0x28);
      mutex_lock(param_1 + 0x22);
      while (plVar11 = (long *)param_1[3], plVar11 != (long *)0x0) {
        plVar15 = (long *)plVar11[1];
        if (plVar15 != (long *)0x0) {
          lVar13 = *plVar11;
          *plVar15 = lVar13;
          if (lVar13 != 0) {
            *(long **)(lVar13 + 8) = plVar15;
          }
          *plVar11 = 0;
          plVar11[1] = 0;
        }
        fastrpc_mmap_free(plVar11,1);
      }
      mutex_unlock(param_1 + 0x22);
      mutex_unlock(param_1 + 0x28);
      uVar4 = *(uint *)(param_1 + 0x18);
      if (4 < uVar4) goto LAB_00117ed8;
      if (*(int *)((long)param_1 + 0x184) != 0) {
        if (0x209e8 < (ulong)uVar4 * 0x6a68) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(1,0x117ee0);
          (*pcVar8)();
        }
        if (*(int *)(&DAT_00129d98 + (ulong)uVar4 * 0x6a68) == 0) {
          lVar13 = DAT_00150640;
        }
        else if (*(int *)(&DAT_00129d98 + (ulong)uVar4 * 0x6a68) == 1) {
          lVar13 = DAT_00150638;
        }
        else {
          lVar13 = 0;
        }
        lVar1 = sp_el0;
        _printk(&DAT_0014f7c0,0xc8a,lVar1 + 0x848,"fastrpc_pm_relax",(int)param_1[0x17]);
        if (lVar13 != 0) {
          __pm_relax(lVar13);
        }
      }
      if (param_1[0x3e] == 0) {
        bVar16 = true;
      }
      if (!bVar16) {
        device_unregister(param_1[0x3e] + 0x10);
      }
      if (uVar3 < 5) {
        lVar13 = param_1[0xd];
        if (lVar13 != 0) {
          lVar1 = *(long *)param_1[0x1e] + (ulong)uVar3 * 0x6a68 + 0x9a0;
          mutex_lock(lVar1);
          *(undefined4 *)(lVar13 + 0x58) = 0;
          mutex_unlock(lVar1);
        }
        lVar13 = param_1[0x14];
        if (lVar13 != 0) {
          lVar1 = *(long *)param_1[0x1e] + (ulong)uVar3 * 0x6a68 + 0x9a0;
          mutex_lock(lVar1);
          *(undefined4 *)(lVar13 + 0x58) = 0;
          mutex_unlock(lVar1);
        }
      }
      kfree(param_1[0x46]);
      kfree(param_1[0x47]);
      kfree(param_1[0x48]);
      kfree(param_1[0x49]);
      while( true ) {
        _raw_spin_lock(plVar12);
        lVar13 = param_1[6];
        _raw_spin_unlock(plVar12);
        if ((lVar13 == 0) || (lVar13 = lVar13 + -0x10, lVar13 == 0)) break;
        fastrpc_buf_free(lVar13,0);
      }
    }
    uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
    uVar3 = *(uint *)((long)param_1 + 0xbc);
    if (uVar3 != 0xffffffff) {
      if (0xff < uVar3) {
LAB_00117ed8:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x117edc);
        (*pcVar8)();
      }
      frpc_tgid_usage_array[uVar3] = 0;
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
    kfree(param_1[0x20]);
    kfree(param_1[0x31]);
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_dev_unmap_dma @ 00117f70 size=560
// signature: undefined fastrpc_dev_unmap_dma(void)
// callers: [fastrpc_driver_invoke]
//------------------------------------------------------------

long fastrpc_dev_unmap_dma(long param_1,long *param_2)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  long lVar9;
  long *plVar10;
  uint uVar11;
  
  uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if ((param_1 == 0) || (*(char *)(param_1 + 0x3b0) == '\x01')) {
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
    return -3;
  }
  lVar9 = *(long *)(param_1 + 0x3a8);
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
  if (lVar9 == 0) {
    return -9;
  }
  puVar7 = (uint *)(lVar9 + 0x78);
  uVar8 = *puVar7;
  if (*puVar7 == 0) {
    uVar11 = 0;
  }
  else {
    do {
      Hint_Prefetch(puVar7,2,0,1);
      do {
        uVar2 = *puVar7;
        if (uVar2 != uVar8) break;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar7,0x10);
        if (bVar4) {
          *puVar7 = uVar8 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      uVar11 = uVar8;
    } while ((uVar8 != uVar2) && (uVar11 = 0, uVar8 = uVar2, uVar2 != 0));
  }
  if ((int)(uVar11 + 1 | uVar11) < 0) {
    refcount_warn_saturate(puVar7,0);
  }
  if (uVar11 == 0) {
    lVar1 = sp_el0;
    _printk(&DAT_0014c4e8,0x2275,lVar1 + 0x848,"fastrpc_dev_unmap_dma",lVar9);
    iVar5 = -2;
  }
  else {
    mutex_lock(lVar9 + 0x140);
    uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if (*(int *)(lVar9 + 0xe0) == 0) {
      *(undefined1 *)(lVar9 + 0x218) = 1;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
      lVar1 = lVar9 + 0x110;
      mutex_lock(lVar1);
      plVar10 = (long *)(lVar9 + 0x18);
      do {
        plVar10 = (long *)*plVar10;
        if (plVar10 == (long *)0x0) goto LAB_00118100;
      } while (plVar10[5] != *param_2);
      mutex_unlock(lVar1);
      iVar5 = fastrpc_munmap_on_dsp
                        (lVar9,plVar10[0xe],plVar10[9],plVar10[10],
                         *(undefined4 *)((long)plVar10 + 0x24));
      if (iVar5 == 0) {
        mutex_lock(lVar1);
        fastrpc_mmap_free(plVar10,0);
LAB_00118100:
        mutex_unlock(lVar1);
        iVar5 = 0;
      }
    }
    else {
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
      iVar5 = -3;
    }
  }
  uVar6 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if ((*(int *)(lVar9 + 0xe0) != 0) && (*(char *)(lVar9 + 0x218) != '\0')) {
    complete(lVar9 + 0x1f8);
  }
  *(undefined1 *)(lVar9 + 0x218) = 0;
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar6);
  mutex_unlock(lVar9 + 0x140);
  if (uVar11 != 0) {
    fastrpc_file_put(lVar9);
  }
  return (long)iVar5;
}



//------------------------------------------------------------
// fastrpc_dev_get_hlos_pid @ 001181b8 size=124
// signature: undefined fastrpc_dev_get_hlos_pid(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_dev_get_hlos_pid(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if ((param_1 == 0) || (*(char *)(param_1 + 0x3b0) == '\x01')) {
    uVar2 = 0xfffffffffffffffd;
  }
  else if (*(long *)(param_1 + 0x3a8) == 0) {
    uVar2 = 0xfffffffffffffff7;
  }
  else {
    uVar2 = 0;
    *param_2 = *(undefined4 *)(*(long *)(param_1 + 0x3a8) + 0xb8);
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// fastrpc_driver_invoke @ 00118238 size=196
// signature: undefined fastrpc_driver_invoke(void)
// callers: []
//------------------------------------------------------------

long fastrpc_driver_invoke(long param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == 3) {
    uVar2 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if ((param_1 == 0) || (*(char *)(param_1 + 0x3b0) == '\x01')) {
      iVar1 = -3;
    }
    else if (*(long *)(param_1 + 0x3a8) == 0) {
      iVar1 = -9;
    }
    else {
      iVar1 = 0;
      *param_3 = *(undefined4 *)(*(long *)(param_1 + 0x3a8) + 0xb8);
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
  }
  else if (param_2 == 2) {
    iVar1 = fastrpc_dev_unmap_dma(param_1,param_3);
  }
  else if (param_2 == 1) {
    iVar1 = fastrpc_dev_map_dma(param_1,param_3);
  }
  else {
    iVar1 = -0x19;
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// fastrpc_driver_unregister @ 00118300 size=372
// signature: undefined fastrpc_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void fastrpc_driver_unregister(long *param_1)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  
  uVar3 = _raw_spin_lock_irqsave(&DAT_001505c8);
  lVar6 = param_1[0x18];
  if (lVar6 == 0) {
    plVar7 = (long *)0x0;
    plVar4 = (long *)param_1[1];
  }
  else {
    plVar7 = (long *)(lVar6 + -0x10);
    if (*(int *)(lVar6 + 0x3a4) == 0) {
      lVar5 = sp_el0;
      _printk(&DAT_0014c353,0x2348,lVar5 + 0x848,"fastrpc_driver_unregister",param_1[2]);
      cVar1 = *(char *)(lVar6 + 0x3a0);
    }
    else {
      *(int *)(lVar6 + 0x3a4) = *(int *)(lVar6 + 0x3a4) + -1;
      cVar1 = *(char *)(lVar6 + 0x3a0);
    }
    if (cVar1 != '\0') {
      plVar4 = *(long **)(lVar6 + -8);
      if (plVar4 == (long *)0x0) {
        plVar4 = (long *)param_1[1];
      }
      else {
        lVar5 = *plVar7;
        *plVar4 = lVar5;
        if (lVar5 != 0) {
          *(long **)(lVar5 + 8) = plVar4;
        }
        *plVar7 = 0;
        *(undefined8 *)(lVar6 + -8) = 0;
        plVar4 = (long *)param_1[1];
      }
      bVar2 = true;
      goto joined_r0x001183d4;
    }
    plVar4 = (long *)param_1[1];
  }
  bVar2 = false;
joined_r0x001183d4:
  if (plVar4 != (long *)0x0) {
    lVar5 = *param_1;
    *plVar4 = lVar5;
    if (lVar5 != 0) {
      *(long **)(lVar5 + 8) = plVar4;
    }
    *param_1 = 0;
    param_1[1] = 0;
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
  if (bVar2) {
    lVar5 = sp_el0;
    _printk(&DAT_0014fa69,0x2352,lVar5 + 0x848,"fastrpc_driver_unregister",(int)plVar7[0x74]);
    device_unregister(lVar6);
  }
  driver_unregister(param_1 + 2);
  lVar6 = sp_el0;
  _printk(&DAT_0014eb22,0x2357,lVar6 + 0x848,"fastrpc_driver_unregister",param_1[2],
          (int)param_1[0x19]);
  return;
}



//------------------------------------------------------------
// fastrpc_driver_register @ 00118478 size=212
// signature: undefined fastrpc_driver_register(void)
// callers: []
//------------------------------------------------------------

int fastrpc_driver_register(long *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  param_1[3] = (long)&fastrpc_bus_type;
  param_1[4] = (long)&__this_module;
  iVar2 = driver_register(param_1 + 2);
  lVar1 = sp_el0;
  if (iVar2 == 0) {
    _printk(&DAT_0014ffeb,0x236a,lVar1 + 0x848,"fastrpc_driver_register",param_1[2],
            (int)param_1[0x19]);
    uVar3 = _raw_spin_lock_irqsave(&DAT_001505c8);
    *param_1 = (long)DAT_00150658;
    if (DAT_00150658 != (long *)0x0) {
      DAT_00150658[1] = (long)param_1;
    }
    DAT_00150658 = param_1;
    param_1[1] = (long)&DAT_00150658;
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
  }
  else {
    _printk(&DAT_0014ff98,0x2366,lVar1 + 0x848,"fastrpc_driver_register",param_1[2],iVar2);
  }
  return iVar2;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_transport_send @ 00118550 size=124
// signature: undefined trace_raw_output_fastrpc_transport_send(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_transport_send(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "to cid %d: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x, addr 0x%llx, size %llu\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x24),*(undefined8 *)(lVar2 + 0x28),
                       *(undefined8 *)(lVar2 + 0x30));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_transport_response @ 001185d0 size=112
// signature: undefined trace_raw_output_fastrpc_transport_response(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_transport_response(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "from cid %d: ctx 0x%llx, retval 0x%x, rsp_flags %u, early_wake_time %u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c),
                       *(undefined4 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_context_interrupt @ 00118644 size=108
// signature: undefined trace_raw_output_fastrpc_context_interrupt(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_context_interrupt(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"to cid %d: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x24));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_context_restore @ 001186b4 size=108
// signature: undefined trace_raw_output_fastrpc_context_restore(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_context_restore(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"for cid %d: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x24));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_dma_map @ 00118724 size=124
// signature: undefined trace_raw_output_fastrpc_dma_map(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_dma_map(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "cid %d, fd %d, phys 0x%llx, size %zu (len %zu), attr 0x%x, flags 0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x28),
                       *(undefined4 *)(lVar2 + 0x2c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_dma_unmap @ 001187a4 size=104
// signature: undefined trace_raw_output_fastrpc_dma_unmap(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_dma_unmap(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"cid %d, phys 0x%llx, size %zu\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_dma_alloc @ 00118810 size=112
// signature: undefined trace_raw_output_fastrpc_dma_alloc(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_dma_alloc(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"cid %d, phys 0x%llx, size %zu, attr 0x%lx, flags 0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x28));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_dma_free @ 00118884 size=104
// signature: undefined trace_raw_output_fastrpc_dma_free(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_dma_free(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"cid %d, phys 0x%llx, size %zu\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_context_complete @ 001188f0 size=116
// signature: undefined trace_raw_output_fastrpc_context_complete(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_context_complete(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "from cid %d: smq_ctx 0x%llx, retval 0x%x, ctx 0x%llx, handle 0x%x, sc 0x%x\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_context_alloc @ 00118968 size=104
// signature: undefined trace_raw_output_fastrpc_context_alloc(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_context_alloc(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"for: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_context_free @ 001189d4 size=104
// signature: undefined trace_raw_output_fastrpc_context_free(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_context_free(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"for: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_perf_counters @ 00118a40 size=140
// signature: undefined trace_raw_output_fastrpc_perf_counters(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_perf_counters(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "for: handle 0x%x, sc 0x%x, count %lld, flush %lld ns, map %lld ns, copy %lld ns, link %lld ns, getargs %lld ns, putargs %lld ns, invargs %lld ns, invoke %lld ns, tid %lld\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar2 + 0x28),
                       *(undefined8 *)(lVar2 + 0x30),*(undefined8 *)(lVar2 + 0x38),
                       *(undefined8 *)(lVar2 + 0x40),*(undefined8 *)(lVar2 + 0x48),
                       *(undefined8 *)(lVar2 + 0x50),*(undefined8 *)(lVar2 + 0x58));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_msg @ 00118ad0 size=104
// signature: undefined trace_raw_output_fastrpc_msg(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_msg(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,&DAT_0014ba74,lVar2 + (ulong)*(ushort *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_fastrpc_dspsignal @ 00118b3c size=112
// signature: undefined trace_raw_output_fastrpc_dspsignal(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_fastrpc_dspsignal(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s for sig id %u, state %d, timeout %u\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// overlap_ptr_cmp @ 00118bb0 size=48
// signature: undefined overlap_ptr_cmp(void)
// callers: []
//------------------------------------------------------------

undefined4 overlap_ptr_cmp(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  uVar2 = *(ulong *)*param_2;
  uVar4 = ((ulong *)*param_2)[1];
  uVar3 = *(ulong *)*param_1;
  uVar5 = ((ulong *)*param_1)[1];
  uVar6 = 1;
  if (uVar4 < uVar5) {
    uVar6 = 0xffffffff;
  }
  uVar1 = 0;
  if (uVar4 != uVar5) {
    uVar1 = uVar6;
  }
  uVar6 = 1;
  if (uVar3 < uVar2) {
    uVar6 = 0xffffffff;
  }
  if (uVar3 != uVar2) {
    uVar1 = uVar6;
  }
  return uVar1;
}



//------------------------------------------------------------
// poll_for_remote_response @ 00118be0 size=544
// signature: undefined poll_for_remote_response(void)
// callers: [fastrpc_wait_for_completion]
//------------------------------------------------------------

void poll_for_remote_response(long param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long local_68;
  long local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  if (param_2 != 0) {
    uVar3 = *(uint *)(param_1 + 0xa4);
    lVar9 = *(long *)(param_1 + 0x58);
    bVar1 = (byte)(uVar3 >> 8);
    bVar2 = (byte)(uVar3 >> 0x10);
    iVar10 = 0;
    do {
      iVar4 = *(int *)(lVar9 + (((ulong)(uVar3 >> 4) & 0xf) + ((ulong)uVar3 & 0xf)) * 0x28 +
                               (ulong)bVar1 * 0x18 + (ulong)bVar2 * 0x18 + (ulong)bVar2 * 0x10 +
                       (ulong)bVar1 * 0x10 + 0x180);
      if (iVar4 == -0x54433222) {
LAB_00118dc0:
        uVar7 = 0;
        goto LAB_00118dc4;
      }
      if (iVar4 == 0xdecaf) {
        *(undefined4 *)(param_1 + 0x40) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0xc0);
        *(undefined1 *)(param_1 + 0x118) = 1;
        lVar9 = gfa;
        iVar10 = *(int *)(*(long *)(param_1 + 0x98) + 0xc0);
        local_68 = 0;
        local_60 = 0;
        ktime_get_real_ts64(&local_68);
        if (local_68 < 0x225c17d04) {
          if (local_68 < -0x225c17d03) {
            lVar11 = -0x8000000000000000;
          }
          else {
            lVar11 = local_60 + local_68 * 1000000000;
          }
        }
        else {
          lVar11 = 0x7fffffffffffffff;
        }
        InstructionSynchronizationBarrier();
        lVar5 = cntvct_el0;
        lVar12 = lVar9 + (long)iVar10 * 0x6a68;
        uVar8 = _raw_spin_lock_irqsave(lVar12 + 0x6a50);
        uVar3 = *(uint *)(lVar12 + 0x2e4c);
        if (0x80 < uVar3) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x118e00);
          (*pcVar6)();
        }
        lVar9 = lVar9 + (long)iVar10 * 0x6a68 + (ulong)uVar3 * 0x28;
        iVar10 = 0;
        if (uVar3 < 0x7f) {
          iVar10 = uVar3 + 1;
        }
        *(undefined8 *)(lVar9 + 0x5650) = uVar7;
        *(undefined8 *)(lVar9 + 0x5658) = 0x500000000;
        *(undefined8 *)(lVar9 + 0x5660) = 0x200000000;
        *(long *)(lVar9 + 0x5668) = lVar11;
        *(ulong *)(lVar9 + 0x5670) = (ulong)(lVar5 * 10) / 0xc0;
        *(int *)(lVar12 + 0x2e4c) = iVar10;
        _raw_spin_unlock_irqrestore(lVar12 + 0x6a50,uVar8);
        goto LAB_00118dc0;
      }
      if (iVar10 == 500) {
        DataSynchronizationBarrier(3,1,0);
        iVar10 = 0;
      }
      __const_udelay(0x10c7);
      iVar10 = iVar10 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  uVar7 = 0xfffffffb;
LAB_00118dc4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_get_persistent_map @ 00118e00 size=164
// signature: undefined fastrpc_get_persistent_map(void)
// callers: [fastrpc_init_create_static_process]
//------------------------------------------------------------

undefined8 fastrpc_get_persistent_map(long param_1,long *param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 uVar4;
  
  uVar2 = _raw_spin_lock_irqsave(&DAT_001505c8);
  plVar3 = (long *)DAT_001505a8;
  do {
    plVar1 = plVar3;
    if (plVar1 == (long *)0x0) {
      uVar4 = 0;
      goto LAB_00118e3c;
    }
    plVar3 = (long *)*plVar1;
  } while (((plVar1[0xc] != param_1) || (*(char *)((long)plVar1 + 0x7c) == '\0')) ||
          (*(char *)(plVar1 + 0x12) != '\0'));
  *param_2 = (long)plVar1;
  uVar4 = 1;
  *(undefined1 *)(plVar1 + 0x12) = 1;
  *(int *)(plVar1 + 0xd) = *(int *)(plVar1 + 0xd) + 1;
LAB_00118e3c:
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
  return uVar4;
}



//------------------------------------------------------------
// fastrpc_get_spd_session @ 00118ea4 size=584
// signature: undefined fastrpc_get_spd_session(void)
// callers: [fastrpc_check_pd_status, fastrpc_init_create_static_process, fastrpc_setup_service_locator]
//------------------------------------------------------------

undefined8 fastrpc_get_spd_session(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  
  bVar2 = true;
  puVar6 = (undefined8 *)(gfa + 0x558);
  uVar5 = 0;
  do {
    if (((char *)*puVar6 != (char *)0x0) && (iVar3 = strcmp(param_1,(char *)*puVar6), iVar3 == 0)) {
      uVar4 = 0;
joined_r0x00119020:
      if (bVar2) {
        *param_3 = (int)uVar5;
        *param_2 = uVar4;
        return 0;
      }
      return 0xffffffa9;
    }
    if (((char *)puVar6[9] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[9]), iVar3 == 0)) {
      uVar4 = 1;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x12] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x12]), iVar3 == 0)) {
      uVar4 = 2;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x1b] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x1b]), iVar3 == 0)) {
      uVar4 = 3;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x24] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x24]), iVar3 == 0)) {
      uVar4 = 4;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x2d] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x2d]), iVar3 == 0)) {
      uVar4 = 5;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x36] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x36]), iVar3 == 0)) {
      uVar4 = 6;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x3f] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x3f]), iVar3 == 0)) {
      uVar4 = 7;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x48] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x48]), iVar3 == 0)) {
      uVar4 = 8;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x51] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x51]), iVar3 == 0)) {
      uVar4 = 9;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x5a] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x5a]), iVar3 == 0)) {
      uVar4 = 10;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[99] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[99]), iVar3 == 0)) {
      uVar4 = 0xb;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x6c] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x6c]), iVar3 == 0)) {
      uVar4 = 0xc;
      goto joined_r0x00119020;
    }
    if (((char *)puVar6[0x75] != (char *)0x0) &&
       (iVar3 = strcmp(param_1,(char *)puVar6[0x75]), iVar3 == 0)) {
      uVar4 = 0xd;
      goto joined_r0x00119020;
    }
    uVar1 = uVar5 + 1;
    bVar2 = uVar5 < 4;
    puVar6 = puVar6 + 0xd4d;
    uVar5 = uVar1;
    if (uVar1 == 5) {
      return 0xffffffa9;
    }
  } while( true );
}



//------------------------------------------------------------
// fastrpc_dsp_restart_handler @ 001190ec size=1436
// signature: undefined fastrpc_dsp_restart_handler(void)
// callers: [fastrpc_hibernation_suspend, fastrpc_init_create_static_process, fastrpc_channel_open]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int fastrpc_dsp_restart_handler(long param_1,int param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 uVar6;
  undefined8 *puVar7;
  uint *puVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  undefined8 *******local_128;
  undefined8 *******local_120;
  undefined8 *******local_118;
  undefined8 *******local_110;
  undefined8 *******local_108;
  undefined8 *******local_100;
  undefined8 local_f8;
  ulong local_f0;
  undefined8 uStack_e8;
  undefined1 local_e0 [8];
  ulong local_d8;
  undefined4 **local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_94;
  undefined4 *local_90;
  undefined8 local_88;
  undefined1 *puStack_80;
  undefined8 local_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  local_128 = &local_128;
  local_120 = local_128;
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc0) == 0)) {
    uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if (DAT_001505a8 != (undefined8 *)0x0) {
      lVar1 = param_1 + 0x110;
      puVar11 = DAT_001505a8;
      do {
        while ((puVar13 = (undefined8 *)*puVar11, *(char *)((long)puVar11 + 0xb9) != '\0' ||
               ((param_1 != 0 &&
                ((((char *)puVar11[0x18] == (char *)0x0 ||
                  (*(char **)(param_1 + 0xd8) == (char *)0x0)) ||
                 (iVar2 = strcmp((char *)puVar11[0x18],*(char **)(param_1 + 0xd8)), iVar2 != 0))))))
              ) {
          puVar11 = puVar13;
          if (puVar13 == (undefined8 *)0x0) goto LAB_001194dc;
        }
        *(undefined1 *)((long)puVar11 + 0xb9) = 1;
        if ((*(char *)((long)puVar11 + 0x7c) == '\0') &&
           (puVar7 = (undefined8 *)puVar11[1], puVar7 != (undefined8 *)0x0)) {
          *puVar7 = puVar13;
          if (puVar13 != (undefined8 *)0x0) {
            puVar13[1] = puVar7;
          }
          *puVar11 = 0;
          puVar11[1] = 0;
        }
        _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
        local_f0 = 0;
        uStack_e8 = 0;
        local_100 = (undefined8 *******)0x0;
        local_f8 = 0;
        local_110 = (undefined8 *******)0x0;
        local_108 = (undefined8 *******)0x0;
        local_118 = (undefined8 *******)0x0;
        uVar4 = extraout_x1;
        if (*(char *)((long)puVar11 + 0x7c) == '\0') {
LAB_001192a0:
          if (*(int *)((long)puVar11 + 0x24) == 4) {
            if (param_1 != 0) {
              local_e0[0] = 0;
              if (*(uint *)(param_1 + 0xc0) < 5) {
                local_94 = *(undefined4 *)(param_1 + 0xbc);
                local_90 = &local_94;
                local_78 = 1;
                puStack_80 = local_e0;
                local_c8 = 0;
                uStack_c0 = 0;
                local_b8 = 0;
                uStack_b0 = 0;
                local_88 = 4;
                local_a8 = 0;
                uStack_a0 = 0;
                local_d8 = 0x901010000000001;
                local_d0 = &local_90;
                iVar2 = fastrpc_internal_invoke(param_1,uVar4,1,&local_d8);
                if (iVar2 == 0) goto joined_r0x001194b8;
              }
              else {
                lVar9 = sp_el0;
                _printk(&DAT_0014e617,0x1430,lVar9 + 0x848,"fastrpc_munmap_on_dsp_rh");
                iVar2 = -0x2c;
              }
LAB_00119590:
              if (puVar11 != (undefined8 *)0x0) {
                if (param_1 == 0 || param_2 != 0) {
                  uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
                  *puVar11 = DAT_001505a8;
                  if (DAT_001505a8 != (undefined8 *)0x0) {
                    DAT_001505a8[1] = puVar11;
                  }
                  DAT_001505a8 = puVar11;
                  puVar11[1] = &DAT_001505a8;
                  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
                }
                else {
                  mutex_lock(lVar1);
                  uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
                  *puVar11 = DAT_001505a8;
                  if (DAT_001505a8 != (undefined8 *)0x0) {
                    DAT_001505a8[1] = puVar11;
                  }
                  DAT_001505a8 = puVar11;
                  puVar11[1] = &DAT_001505a8;
                  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
                  mutex_unlock(lVar1);
                }
              }
              goto LAB_001194f0;
            }
            _printk(&DAT_0014ee79);
            uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
            *puVar11 = DAT_001505a8;
            if (DAT_001505a8 != (undefined8 *)0x0) {
              DAT_001505a8[1] = puVar11;
            }
            DAT_001505a8 = puVar11;
            puVar11[1] = &DAT_001505a8;
            _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
          }
          else if (((*(int *)((long)puVar11 + 0x24) == 8) &&
                   (*(uint **)(gfa + 0xa00) != (uint *)0x0)) && (*(int *)(gfa + 0x9e0) == 0)) {
            uVar4 = puVar11[9];
            uVar12 = puVar11[10];
            local_d8 = 0;
            uVar10 = (ulong)*(uint *)(gfa + 0xa10);
            local_90 = (undefined4 *)0x700000003;
            if (*(uint *)(gfa + 0xa10) != 0) {
              local_d8 = 0;
              puVar8 = *(uint **)(gfa + 0xa00);
              do {
                uVar10 = uVar10 - 1;
                local_d8 = 1L << ((ulong)*puVar8 & 0x3f) | local_d8;
                puVar8 = puVar8 + 1;
              } while (uVar10 != 0);
            }
            iVar2 = qcom_scm_assign_mem(uVar4,uVar12,&local_d8,&local_90,1);
            if (iVar2 != 0) {
              lVar9 = sp_el0;
              pcVar5 = "fastrpc_munmap_rh";
              uVar6 = 0x146c;
              goto LAB_00119630;
            }
          }
        }
        else if (*(char *)(puVar11 + 0x12) != '\0') {
          if (*(uint **)(gfa + 0xa00) != (uint *)0x0) {
            uVar4 = puVar11[9];
            uVar12 = puVar11[10];
            local_d8 = 0;
            uVar10 = (ulong)*(uint *)(gfa + 0xa10);
            local_90 = (undefined4 *)0x700000003;
            if (*(uint *)(gfa + 0xa10) != 0) {
              local_d8 = 0;
              puVar8 = *(uint **)(gfa + 0xa00);
              do {
                uVar10 = uVar10 - 1;
                local_d8 = 1L << ((ulong)*puVar8 & 0x3f) | local_d8;
                puVar8 = puVar8 + 1;
              } while (uVar10 != 0);
            }
            iVar2 = qcom_scm_assign_mem(uVar4,uVar12,&local_d8,&local_90,1);
            if (iVar2 == 0) goto LAB_0011926c;
            lVar9 = sp_el0;
            pcVar5 = "fastrpc_mmap_dump";
            uVar6 = 0x14ac;
LAB_00119630:
            _printk(&DAT_0014dcc8,uVar6,lVar9 + 0x848,pcVar5,iVar2,uVar4,uVar12);
            iVar2 = -99;
            goto LAB_00119590;
          }
LAB_0011926c:
          uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
          *(undefined1 *)(puVar11 + 0x12) = 0;
          *(int *)(puVar11 + 0xd) = *(int *)(puVar11 + 0xd) + -1;
          _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
          uVar4 = extraout_x1_00;
          if (*(char *)((long)puVar11 + 0x7c) == '\0') goto LAB_001192a0;
        }
joined_r0x001194b8:
        if ((param_3 & 1) != 0) {
          local_f8 = puVar11[9];
          local_108 = (undefined8 *******)0x0;
          local_100 = (undefined8 *******)0x0;
          local_f0 = (puVar11[0xb] & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
          uStack_e8 = puVar11[10];
          local_118 = &local_118;
          local_110 = local_118;
          uVar10 = __list_add_valid(&local_108,&local_118,&local_118);
          if ((uVar10 & 1) != 0) {
            local_118 = &local_108;
            local_108 = &local_118;
            local_110 = local_118;
            local_100 = local_108;
          }
          if (((DAT_001505d0 != 0) && (uVar10 = dump_enabled(), (uVar10 & 1) != 0)) &&
             (iVar2 = qcom_elf_dump(&local_118,DAT_001505d0,2), iVar2 < 0)) {
            _printk(&DAT_0014e375,"fastrpc_mmap_dump",iVar2);
          }
        }
        if (*(char *)((long)puVar11 + 0x7c) == '\0') {
          if (param_1 == 0 || param_2 != 0) {
            fastrpc_mmap_free(puVar11,0);
          }
          else {
            mutex_lock(lVar1);
            fastrpc_mmap_free(puVar11,0);
            mutex_unlock(lVar1);
          }
        }
        uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
        puVar11 = DAT_001505a8;
      } while (DAT_001505a8 != (undefined8 *)0x0);
    }
LAB_001194dc:
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
    iVar2 = 0;
  }
  else {
    iVar2 = -0x35;
  }
LAB_001194f0:
  uVar4 = _raw_spin_lock_irqsave(&DAT_001505c8);
  puVar11 = DAT_001505a8;
joined_r0x00119500:
  do {
    do {
      do {
        do {
          puVar13 = puVar11;
          if (puVar13 == (undefined8 *)0x0) {
            _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar4);
            lVar1 = sp_el0;
            if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return iVar2;
          }
          puVar11 = (undefined8 *)*puVar13;
        } while (*(char *)((long)puVar13 + 0xb9) == '\0');
        pcVar5 = (char *)puVar13[0x18];
        if (param_1 == 0) goto LAB_00119550;
      } while (pcVar5 == (char *)0x0);
    } while (*(char **)(param_1 + 0xd8) == (char *)0x0);
    iVar3 = strcmp(pcVar5,*(char **)(param_1 + 0xd8));
  } while (iVar3 != 0);
  goto LAB_00119554;
LAB_00119550:
  if (pcVar5 != (char *)0x0) {
LAB_00119554:
    *(undefined1 *)((long)puVar13 + 0xb9) = 0;
  }
  goto joined_r0x00119500;
}



//------------------------------------------------------------
// fastrpc_unmap_on_dsp @ 00119694 size=160
// signature: undefined fastrpc_unmap_on_dsp(void)
// callers: [fastrpc_mmap_on_dsp]
//------------------------------------------------------------

void fastrpc_unmap_on_dsp(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined1 **local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 uStack_20;
  long local_18;
  
  local_28 = (undefined1 *)&local_80;
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_60 = &local_28;
  uStack_58 = 0;
  uStack_20 = 0x18;
  local_50 = 0;
  uStack_48 = 0;
  uStack_64 = 0x3010000;
  if (*(int *)(*(long *)(param_1 + 0xf0) + 0xb8) != 0) {
    uStack_64 = 0x5010000;
  }
  local_40 = 0;
  uStack_38 = 0;
  local_80 = (ulong)*(uint *)(param_1 + 0xbc);
  local_30 = 0;
  local_68 = 1;
  local_78 = param_2;
  uStack_70 = param_3;
  fastrpc_internal_invoke(param_1,param_2,1,&local_68);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_minidump_add_region @ 00119734 size=432
// signature: undefined fastrpc_minidump_add_region(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

int fastrpc_minidump_add_region(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  long lVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  mutex_lock(&DAT_00150660);
  if (md_unique_index_flag == 0) {
    lVar4 = 0;
    puVar3 = &md_unique_index_flag;
  }
  else {
    puVar3 = &DAT_001506ac;
    if (DAT_001506ac == 0) {
      lVar4 = 1;
    }
    else {
      puVar3 = &DAT_001506b0;
      if (DAT_001506b0 == 0) {
        lVar4 = 2;
      }
      else {
        puVar3 = &DAT_001506b4;
        if (DAT_001506b4 == 0) {
          lVar4 = 3;
        }
        else {
          puVar3 = &DAT_001506b8;
          if (DAT_001506b8 != 0) {
            mutex_unlock(&DAT_00150660);
            _printk(&DAT_0014f21d,5);
            iVar2 = 0;
            goto LAB_0011983c;
          }
          lVar4 = 4;
        }
      }
    }
  }
  *puVar3 = 1;
  mutex_unlock(&DAT_00150660);
  scnprintf(&local_68,0xc,"FRPC_%d",lVar4);
  local_40 = *(undefined8 *)(param_1 + 0x50);
  local_50 = *(undefined8 *)(param_1 + 0x58);
  local_48 = *(undefined8 *)(param_1 + 0x48);
  iVar2 = msm_minidump_add_region(&local_68);
  if (iVar2 < 0) {
    lVar1 = sp_el0;
    _printk(&DAT_0014e933,0x29e,lVar1 + 0x848,"fastrpc_minidump_add_region",
            *(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x50),lVar4,&local_68);
    mutex_lock(&DAT_00150660);
    (&md_unique_index_flag)[lVar4] = 0;
    mutex_unlock(&DAT_00150660);
  }
  else {
    iVar2 = 0;
    *(int *)(param_1 + 0x80) = (int)lVar4;
  }
LAB_0011983c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// trace_fastrpc_dma_map @ 001198e4 size=44
// signature: undefined trace_fastrpc_dma_map(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

void trace_fastrpc_dma_map(void)

{
  return;
}



//------------------------------------------------------------
// fastrpc_session_alloc_secure_memory @ 001199d8 size=372
// signature: undefined fastrpc_session_alloc_secure_memory(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

undefined8 fastrpc_session_alloc_secure_memory(long param_1,int param_2,int param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  int *piVar6;
  undefined8 uVar7;
  
  lVar1 = param_1 + 0x9a0;
  iVar4 = param_3;
  if (DAT_00150698 != '\0') {
    iVar4 = 6;
  }
  iVar2 = 0;
  if (param_3 != 0) {
    iVar2 = iVar4;
  }
  mutex_lock(lVar1);
  uVar7 = 0;
  if (*param_4 == 0) {
    if (*(ulong *)(param_1 + 0x9d0) != 0) {
      uVar5 = 0;
      piVar6 = (int *)(param_1 + 0x70);
      do {
        if (uVar5 == 0xe) {
LAB_00119b48:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x119b4c);
          (*pcVar3)();
        }
        if ((((*piVar6 == 0) && (piVar6[-0xd] == 1)) && (piVar6[-0xb] == param_2)) &&
           ((iVar2 == 0 || (piVar6[-10] == iVar2)))) {
          *piVar6 = 1;
          if (uVar5 < *(ulong *)(param_1 + 0x9d0)) {
            if (0xd < uVar5) goto LAB_00119b48;
            piVar6[-0xe] = 0;
            goto LAB_00119acc;
          }
          goto LAB_00119b04;
        }
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 0x18;
        if (*(ulong *)(param_1 + 0x9d0) == uVar5) {
LAB_00119b04:
          mutex_unlock(lVar1);
          lVar1 = sp_el0;
          _printk(&DAT_0014fa00,0x1777,lVar1 + 0x848,"fastrpc_session_alloc_secure_memory",
                  *(undefined8 *)(param_1 + 0x9d0),*(undefined8 *)(param_1 + 8),0xffffffa9);
          return 0xffffffa9;
        }
      } while( true );
    }
    if (DAT_001505d0 == 0) {
      uVar7 = 0xffffffed;
    }
    else {
      *(long *)(param_1 + 0x18) = DAT_001505d0;
      uVar5 = 0;
      *(long *)(param_1 + 0x20) = DAT_001505d0;
LAB_00119acc:
      uVar7 = 0;
      *param_4 = param_1 + uVar5 * 0x60 + 0x18;
    }
  }
  mutex_unlock(lVar1);
  return uVar7;
}



//------------------------------------------------------------
// fastrpc_alloc_cma_memory @ 00119b4c size=268
// signature: undefined fastrpc_alloc_cma_memory(void)
// callers: [init_module, fastrpc_mmap_create]
//------------------------------------------------------------

undefined8
fastrpc_alloc_cma_memory(undefined8 param_1,ulong *param_2,ulong param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (DAT_001505d0 == (long *)0x0) {
    lVar1 = sp_el0;
    _printk(&DAT_0014be1e,900,lVar1 + 0x848,"fastrpc_alloc_cma_memory");
    uVar3 = 0xffffffed;
  }
  else if ((param_3 == 0) || (DAT_0015064c <= param_3)) {
    _printk(&DAT_0014c3c9,"fastrpc_alloc_cma_memory",param_3);
    uVar3 = 0xfffffff2;
  }
  else {
    uVar2 = dma_alloc_attrs(DAT_001505d0,param_3,param_1,0xcc0,param_4);
    *param_2 = uVar2;
    if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
      lVar1 = sp_el0;
      lVar4 = DAT_001505d0[0xe];
      if (lVar4 == 0) {
        lVar4 = *DAT_001505d0;
      }
      _printk(&DAT_0014e8c8,0x393,lVar1 + 0x848,"fastrpc_alloc_cma_memory",lVar4,param_3,param_4);
      uVar3 = 0xffffff97;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// trace_fastrpc_dma_alloc @ 00119c58 size=44
// signature: undefined trace_fastrpc_dma_alloc(void)
// callers: [fastrpc_buf_alloc]
//------------------------------------------------------------

void trace_fastrpc_dma_alloc(void)

{
  return;
}



//------------------------------------------------------------
// fastrpc_cached_buf_list_free @ 00119d3c size=140
// signature: undefined fastrpc_cached_buf_list_free(void)
// callers: [fastrpc_file_put, fastrpc_buf_alloc]
//------------------------------------------------------------

void fastrpc_cached_buf_list_free(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  
  lVar1 = param_1 + 0x10;
  while( true ) {
    _raw_spin_lock(lVar1);
    plVar4 = *(long **)(param_1 + 0x20);
    if (plVar4 == (long *)0x0) break;
    plVar2 = (long *)plVar4[1];
    if (plVar2 != (long *)0x0) {
      lVar3 = *plVar4;
      *plVar2 = lVar3;
      if (lVar3 != 0) {
        *(long **)(lVar3 + 8) = plVar2;
      }
      *plVar4 = 0;
      plVar4[1] = 0;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
    _raw_spin_unlock(lVar1);
    fastrpc_buf_free(plVar4,0);
  }
  _raw_spin_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// uint_cmp_func @ 00119dcc size=28
// signature: undefined uint_cmp_func(void)
// callers: []
//------------------------------------------------------------

undefined4 uint_cmp_func(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_1 < *param_2) {
    uVar2 = 0xffffffff;
  }
  uVar1 = 0;
  if (*param_1 != *param_2) {
    uVar1 = uVar2;
  }
  return uVar1;
}



//------------------------------------------------------------
// fastrpc_debugfs_read @ 00119dec size=3464
// signature: undefined fastrpc_debugfs_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long fastrpc_debugfs_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  char cVar8;
  bool bVar9;
  code *pcVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  undefined8 uVar14;
  int iVar15;
  uint *puVar16;
  long lVar17;
  long *plVar18;
  ulong uVar19;
  int *piVar20;
  ulong uVar21;
  uint uVar22;
  int *piVar23;
  long lVar24;
  ulong uVar25;
  char local_a0 [8];
  char acStack_98 [8];
  char local_90 [8];
  undefined2 local_88;
  char local_80 [8];
  char acStack_78 [8];
  undefined1 local_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  lVar24 = *(long *)(param_1 + 0xd8);
  local_70 = 0;
  local_80 = (char  [8])s__________________0014ce5a._0_8_;
  acStack_78 = (char  [8])s__________________0014ce5a._8_8_;
  local_a0 = (char  [8])s___________________________0014bbd6._0_8_;
  acStack_98 = (char  [8])s___________________________0014bbd6._8_8_;
  local_90 = (char  [8])s___________________________0014bbd6._16_8_;
  local_88 = 0x3d;
  lVar13 = kmalloc_trace(_dma_buf_end_cpu_access,0xdc0,0xc00);
  if (lVar13 == 0) {
    lVar24 = -0xc;
  }
  else {
    if (lVar24 == 0) {
      uVar11 = scnprintf(lVar13,0xc00,"\n%s %s %s\n",local_a0," CHANNEL INFO ",local_a0);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-7s|%-10s|%-15s|%-9s|%-13s\n",
                         "subsys","sesscount","subsystemstate","ssrcount","session_used");
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"-%s%s%s%s-\n",local_80,local_80,
                         local_80,local_80);
      lVar24 = 0;
      uVar11 = uVar11 + iVar12;
      piVar23 = &DAT_001293e8;
      uVar25 = 0xfffffffffffdec6b;
      do {
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,&DAT_0014e3d3,
                           (&PTR_s_lpass_00129380)[lVar24 * 0xd4d]);
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"|%-10u",
                           (&DAT_00129d48)[lVar24 * 0xd4d]);
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"|%-15d",
                           (&DAT_00129d70)[lVar24 * 0x1a9a]);
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"|%-9u",
                           (&DAT_00129d50)[lVar24 * 0xd4d]);
        lVar17 = (&DAT_00129d48)[lVar24 * 0xd4d];
        if (lVar17 == 0) {
          iVar15 = 0;
        }
        else {
          iVar15 = 0;
          uVar19 = lVar17 - 0xf;
          piVar20 = piVar23;
          uVar21 = uVar25;
          do {
            if (uVar19 < 0xfffffffffffffff2) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x11ab80);
              (*pcVar10)();
            }
            if (uVar21 < 0xfffffffffffdebfb) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(1,0x11ab84);
              (*pcVar10)();
            }
            uVar21 = uVar21 + 0x60;
            lVar17 = lVar17 + -1;
            iVar15 = *piVar20 + iVar15;
            piVar20 = piVar20 + 0x18;
          } while (lVar17 != 0);
        }
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"|%-13d\n",iVar15);
        lVar24 = lVar24 + 1;
        uVar11 = iVar12 + uVar11;
        uVar25 = uVar25 + 0x6a68;
        piVar23 = piVar23 + 0x1a9a;
      } while (lVar24 != 5);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n%s%s%s\n","=============",
                         " CMA HEAP ","==============");
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s\n",&DAT_0014f3c7,
                         &DAT_0014c1ad);
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"--%s%s---\n",local_80,local_80);
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n==========%s %s %s===========\n",
                         local_a0," GMAPS ",local_a0);
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s|%-20s|%-20s\n",
                         &DAT_0014cbfc,&DAT_0014eb71,&DAT_0014c1ad,&DAT_0014ecc2);
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      uVar11 = uVar11 + iVar12;
      uVar14 = _raw_spin_lock_irqsave(&DAT_001505c8);
      plVar18 = (long *)DAT_001505a8;
      while (plVar18 != (long *)0x0) {
        puVar1 = (undefined4 *)(plVar18 + 4);
        puVar3 = plVar18 + 9;
        puVar5 = (undefined4 *)(plVar18 + 10);
        puVar4 = plVar18 + 0xb;
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "%-20d|0x%-18llX|0x%-18X|0x%-20lX\n\n",*puVar1,*puVar3,*puVar5,*puVar4);
        uVar11 = iVar12 + uVar11;
      }
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar14);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s|%-20s|%-20s\n",
                         &DAT_00150041,&DAT_0014eea6,"raddr","flags");
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      uVar11 = uVar11 + iVar12;
      uVar14 = _raw_spin_lock_irqsave(&DAT_001505c8);
      plVar18 = (long *)DAT_001505a8;
      while (plVar18 != (long *)0x0) {
        puVar1 = (undefined4 *)(plVar18 + 0xc);
        puVar5 = (undefined4 *)(plVar18 + 0xd);
        puVar3 = plVar18 + 0xe;
        puVar2 = (undefined4 *)((long)plVar18 + 0x24);
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"0x%-18X|%-20d|%-20lu|%-20u\n",
                           *puVar1,*puVar5,*puVar3,*puVar2);
        uVar11 = iVar12 + uVar11;
      }
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar14);
    }
    else {
      puVar16 = (uint *)(lVar24 + 0x78);
      uVar11 = *puVar16;
      if (*puVar16 == 0) {
        uVar22 = 0;
      }
      else {
        do {
          Hint_Prefetch(puVar16,2,0,1);
          do {
            uVar7 = *puVar16;
            if (uVar7 != uVar11) break;
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar16,0x10);
            if (bVar9) {
              *puVar16 = uVar11 + 1;
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          uVar22 = uVar11;
        } while ((uVar11 != uVar7) && (uVar22 = 0, uVar11 = uVar7, uVar7 != 0));
      }
      if ((int)(uVar22 + 1 | uVar22) < 0) {
        refcount_warn_saturate(puVar16,0);
      }
      if (uVar22 == 0) {
        lVar24 = sp_el0;
        _printk(&DAT_0014dd4f,0x188c,lVar24 + 0x848,"fastrpc_debugfs_read");
        lVar24 = -2;
        goto LAB_0011ab00;
      }
      uVar11 = scnprintf(lVar13,0xc00,"\n%s %13s %d\n",&DAT_0014dc68,&DAT_0014e3df,
                         *(undefined4 *)(lVar24 + 0xc0));
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %12s %d\n",&DAT_0014d511,
                         &DAT_0014e3df,*(undefined4 *)(lVar24 + 0xb8));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %14s %d\n","tgid_frpc",
                         &DAT_0014e3df,*(undefined4 *)(lVar24 + 0xbc));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %7s %d\n","sessionid",
                         &DAT_0014e3df,*(undefined4 *)(lVar24 + 0xb0));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %8s %u\n","ssrcount",
                         &DAT_0014e3df,*(undefined8 *)(lVar24 + 200));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %14s %d\n",&DAT_0014fdca,
                         &DAT_0014e3df,*(undefined4 *)(lVar24 + 0xd0));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %9s %s\n","servloc_name",
                         &DAT_0014e3df,*(undefined8 *)(lVar24 + 0xd8));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %6s %d\n","file_close",
                         &DAT_0014e3df,*(undefined4 *)(lVar24 + 0xe0));
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %9s %d\n","profile",&DAT_0014e3df
                         ,*(undefined4 *)(lVar24 + 0xac));
      uVar11 = iVar12 + uVar11;
      if (*(long *)(lVar24 + 0x68) != 0) {
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %3s %d\n","smmu.coherent",
                           &DAT_0014e3df,*(undefined4 *)(*(long *)(lVar24 + 0x68) + 0x28));
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %4s %d\n","smmu.enabled",
                           &DAT_0014e3df,*(undefined4 *)(*(long *)(lVar24 + 0x68) + 0x1c));
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %9s %d\n","smmu.cb",
                           &DAT_0014e3df,*(undefined4 *)(*(long *)(lVar24 + 0x68) + 0x18));
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %5s %d\n","smmu.secure",
                           &DAT_0014e3df,*(undefined4 *)(*(long *)(lVar24 + 0x68) + 0x24));
        uVar11 = iVar12 + uVar11;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s %5s %d\n","smmu.faults",
                           &DAT_0014e3df,*(undefined4 *)(*(long *)(lVar24 + 0x68) + 0x20));
        uVar11 = iVar12 + uVar11;
      }
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n=======%s %s %s======\n",local_a0,
                         " LIST OF MAPS ",local_a0);
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s|%-20s|%-20s\n",
                         &DAT_0014ecc2,&DAT_0014eb71,&DAT_0014c1ad,"flags");
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      lVar17 = lVar24 + 0x110;
      uVar11 = uVar11 + iVar12;
      mutex_lock(lVar17);
      plVar18 = *(long **)(lVar24 + 0x18);
      while (plVar18 != (long *)0x0) {
        puVar4 = plVar18 + 10;
        puVar6 = plVar18 + 0xb;
        puVar3 = plVar18 + 9;
        puVar1 = (undefined4 *)((long)plVar18 + 0x24);
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "0x%-20lX|0x%-20llX|0x%-20zu|0x%-17llX\n\n",*puVar6,*puVar3,*puVar4,
                           *puVar1);
        uVar11 = iVar12 + uVar11;
      }
      mutex_unlock(lVar17);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s|%-20s\n",&DAT_00150041,
                         &DAT_0014eea6,"raddr");
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      uVar11 = uVar11 + iVar12;
      mutex_lock(lVar17);
      plVar18 = *(long **)(lVar24 + 0x18);
      while (plVar18 != (long *)0x0) {
        puVar3 = plVar18 + 0xc;
        puVar1 = (undefined4 *)(plVar18 + 0xd);
        puVar4 = plVar18 + 0xe;
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20zu|%-20d|0x%-20lX\n\n",*puVar3
                           ,*puVar1,*puVar4);
        uVar11 = iVar12 + uVar11;
      }
      mutex_unlock(lVar17);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-20s\n","secure",
                         &DAT_001502fc);
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      uVar11 = uVar11 + iVar12;
      mutex_lock(lVar17);
      plVar18 = *(long **)(lVar24 + 0x18);
      while (plVar18 != (long *)0x0) {
        puVar1 = (undefined4 *)(plVar18 + 0xf);
        puVar3 = plVar18 + 0x11;
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20d|0x%-20lX\n\n",*puVar1,
                           *puVar3);
        uVar11 = iVar12 + uVar11;
      }
      mutex_unlock(lVar17);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n======%s %s %s======\n",local_a0,
                         " LIST OF BUFS ",local_a0);
      uVar11 = iVar12 + uVar11;
      _raw_spin_lock(lVar24 + 0x10);
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-19s|%-19s|%-19s|%-19s\n",
                         &DAT_0014b97a,&DAT_0014eb71,&DAT_0014c1ad,"flags");
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      plVar18 = *(long **)(lVar24 + 0x20);
      uVar11 = uVar11 + iVar12;
      while (plVar18 != (long *)0x0) {
        puVar4 = plVar18 + 7;
        puVar6 = plVar18 + 8;
        puVar3 = plVar18 + 9;
        puVar1 = (undefined4 *)(plVar18 + 0xc);
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "0x%-17p|0x%-17llX|%-19zu|0x%-17llX\n",*puVar4,*puVar6,*puVar3,*puVar1);
        uVar11 = iVar12 + uVar11;
      }
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n======%s %s %s======\n",local_a0,
                         " LIST OF REMOTE BUFS ",local_a0);
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-19s|%-19s|%-19s|%-19s\n",
                         &DAT_0014b97a,&DAT_0014eb71,&DAT_0014c1ad,"flags");
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      plVar18 = *(long **)(lVar24 + 0x30);
      uVar11 = uVar11 + iVar12;
      while ((plVar18 != (long *)0x0 && (plVar18 != (long *)0x10))) {
        puVar4 = plVar18 + 5;
        puVar6 = plVar18 + 6;
        puVar3 = plVar18 + 7;
        puVar1 = (undefined4 *)(plVar18 + 10);
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "0x%-17p|0x%-17llX|%-19zu|0x%-17llX\n",*puVar4,*puVar6,*puVar3,*puVar1);
        uVar11 = iVar12 + uVar11;
      }
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n%s %s %s\n",local_a0,
                         " LIST OF PENDING SMQCONTEXTS ",local_a0);
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-10s|%-10s|%-10s|%-20s\n",
                         &DAT_0014d14e,&DAT_0014eeab,&DAT_0014d511,&DAT_0014d95d,"ctxid");
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      plVar18 = *(long **)(lVar24 + 0x38);
      uVar11 = uVar11 + iVar12;
      while (plVar18 != (long *)0x0) {
        puVar5 = (undefined4 *)((long)plVar18 + 0x44);
        puVar2 = (undefined4 *)(plVar18 + 9);
        puVar1 = (undefined4 *)((long)plVar18 + 0xa4);
        puVar3 = plVar18 + 0x12;
        puVar4 = plVar18 + 0x20;
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "0x%-18X|%-10d|%-10d|%-10zu|0x%-20llX\n\n",*puVar1,*puVar5,*puVar2,
                           *puVar3,*puVar4);
        uVar11 = iVar12 + uVar11;
      }
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"\n%s %s %s\n",local_a0,
                         " LIST OF INTERRUPTED SMQCONTEXTS ",local_a0);
      uVar11 = iVar12 + uVar11;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%-20s|%-10s|%-10s|%-10s|%-20s\n",
                         &DAT_0014d14e,&DAT_0014eeab,&DAT_0014d511,&DAT_0014d95d,"ctxid");
      uVar11 = uVar11 + iVar12;
      iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,"%s%s%s%s%s\n",local_80,local_80,
                         local_80,local_80,local_80);
      plVar18 = *(long **)(lVar24 + 0x40);
      uVar11 = uVar11 + iVar12;
      while (plVar18 != (long *)0x0) {
        puVar5 = (undefined4 *)((long)plVar18 + 0x44);
        puVar2 = (undefined4 *)(plVar18 + 9);
        puVar1 = (undefined4 *)((long)plVar18 + 0xa4);
        puVar3 = plVar18 + 0x12;
        puVar4 = plVar18 + 0x20;
        plVar18 = (long *)*plVar18;
        iVar12 = scnprintf(lVar13 + (ulong)uVar11,0xc00 - uVar11,
                           "%-20u|%-20d|%-20d|%-20zu|0x%-20llX\n\n",*puVar1,*puVar5,*puVar2,*puVar3,
                           *puVar4);
        uVar11 = iVar12 + uVar11;
      }
      _raw_spin_unlock(lVar24 + 0x10);
      fastrpc_file_put(lVar24);
    }
    if (0xbff < uVar11) {
      uVar11 = 0xc00;
    }
    iVar12 = simple_read_from_buffer(param_2,param_3,param_4,lVar13,uVar11);
    lVar24 = (long)iVar12;
  }
LAB_0011ab00:
  kfree(lVar13);
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar24;
}



//------------------------------------------------------------
// fastrpc_dev_release @ 0011ab8c size=32
// signature: undefined fastrpc_dev_release(void)
// callers: []
//------------------------------------------------------------

void fastrpc_dev_release(long param_1)

{
  kfree(param_1 + -0x10);
  return;
}



//------------------------------------------------------------
// fastrpc_bus_match @ 0011abb0 size=140
// signature: undefined fastrpc_bus_match(void)
// callers: []
//------------------------------------------------------------

bool fastrpc_bus_match(long param_1,long param_2)

{
  undefined8 uVar1;
  bool bVar2;
  
  if (*(int *)(param_1 + 0x390) == *(int *)(param_2 + 0xb8)) {
    uVar1 = _raw_spin_lock_irqsave(&DAT_001505c8);
    bVar2 = *(char *)(param_1 + 0x3a0) == '\0';
    if (bVar2) {
      *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
      *(long *)(param_2 + 0xb0) = param_1;
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar1);
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



//------------------------------------------------------------
// fastrpc_bus_probe @ 0011ac40 size=84
// signature: undefined fastrpc_bus_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_bus_probe(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if ((*(long *)(param_1 + 0x88) == 0x10) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x88) + 0xc0), pcVar2 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x460020e6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11ac7c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1 + -0x10);
  }
  return uVar1;
}



//------------------------------------------------------------
// fastrpc_bus_remove @ 0011ac98 size=80
// signature: undefined fastrpc_bus_remove(void)
// callers: []
//------------------------------------------------------------

void fastrpc_bus_remove(long param_1)

{
  code *pcVar1;
  
  if ((*(long *)(param_1 + 0x88) != 0x10) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + 200), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x241c031d) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11acd8);
      (*pcVar1)();
    }
    (*pcVar1)(param_1 + -0x10,0);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_restart_notifier_cb @ 0011acec size=1000
// signature: undefined fastrpc_restart_notifier_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_restart_notifier_cb(long param_1,undefined8 param_2)

{
  long *plVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  uVar7 = ((param_1 - gfa) + -0x988 >> 3) * 0xe83df385;
  iVar6 = (int)uVar7;
  mutex_lock(gfa + (long)iVar6 * 0x6a68 + 0x9a0);
  lVar8 = *(long *)(param_1 + 0x50);
  mutex_unlock(gfa + (long)iVar6 * 0x6a68 + 0x9a0);
  switch(param_2) {
  case 0:
    if (4 < (uVar7 & 0xffffffff)) {
LAB_0011b0cc:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11b0d0);
      (*pcVar2)();
    }
    if ((long)iVar6 * 0x6a68 - 0x21401U < 0xfffffffffffdebf7) goto LAB_0011b0c8;
    fastrpc_rproc_trace_events
              ((&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d],"QCOM_SSR_BEFORE_POWERUP",
               "fastrpc_restart_notifier-enter");
    _printk(&DAT_0014ee2b,"fastrpc_restart_notifier_cb",(&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d]
           );
    if (iVar6 != 3) {
      fastrpc_notify_drivers(uVar7 & 0xffffffff);
      break;
    }
    uVar7 = dump_enabled();
    if (((uVar7 & 1) != 0) && (lVar8 != 0)) {
      fastrpc_update_ramdump_status();
    }
    fastrpc_notify_drivers(3);
    uVar7 = dump_enabled();
    if (((uVar7 & 1) == 0) || (lVar8 == 0)) break;
    mutex_lock(gfa + 0x148d8);
    fastrpc_print_debug_data();
    mutex_unlock(gfa + 0x148d8);
    ktime_get_real_ts64(&local_68);
    fastrpc_ramdump_collection();
    puVar5 = (undefined *)getnstimediff(&local_68);
    puVar4 = &DAT_0014eabc;
    goto LAB_0011b088;
  case 1:
    if (4 < (uVar7 & 0xffffffff)) goto LAB_0011b0cc;
    if ((long)iVar6 * 0x6a68 - 0x21401U < 0xfffffffffffdebf7) goto LAB_0011b0c8;
    fastrpc_rproc_trace_events
              ((&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d],"QCOM_SSR_AFTER_POWERUP",
               "fastrpc_restart_notifier-enter");
    _printk(&DAT_0014eaf1,"fastrpc_restart_notifier_cb",(&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d]
           );
    *(undefined4 *)(param_1 + 0x70) = 2;
    break;
  case 2:
    if (4 < (uVar7 & 0xffffffff)) goto LAB_0011b0cc;
    if ((long)iVar6 * 0x6a68 - 0x21401U < 0xfffffffffffdebf7) goto LAB_0011b0c8;
    fastrpc_rproc_trace_events
              ((&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d],"QCOM_SSR_BEFORE_SHUTDOWN",
               "fastrpc_restart_notifier-enter");
    _printk(&DAT_0014ee00,"fastrpc_restart_notifier_cb",(&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d]
           );
    mutex_lock(gfa + (long)iVar6 * 0x6a68 + 0x9a0);
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(long *)(param_1 + 0x50) = *(long *)(param_1 + 0x50) + 1;
    mutex_unlock(gfa + (long)iVar6 * 0x6a68 + 0x9a0);
    if (iVar6 == 0) {
      DAT_001505b0 = 0;
    }
    break;
  case 3:
    if (4 < (uVar7 & 0xffffffff)) goto LAB_0011b0cc;
    uVar7 = (long)iVar6 * 0x6a68 + 8;
    if (0x21408 < uVar7) {
LAB_0011b0c8:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x11b0cc);
      (*pcVar2)();
    }
    fastrpc_rproc_trace_events
              ((&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d],"QCOM_SSR_AFTER_SHUTDOWN",
               "fastrpc_restart_notifier-enter");
    uVar3 = _raw_spin_lock_irqsave(&DAT_001505c8);
    plVar9 = (long *)DAT_001505c0;
    while (plVar1 = plVar9, plVar1 != (long *)0x0) {
      plVar9 = (long *)*plVar1;
      if (*(int *)(plVar1 + 0x18) == iVar6) {
        complete(plVar1 + 0x51);
      }
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar3);
    *(undefined4 *)(param_1 + 0x70) = 1;
    if (0x21408 < uVar7) goto LAB_0011b0c8;
    puVar5 = (&PTR_s_lpass_00129380)[(long)iVar6 * 0xd4d];
    puVar4 = &DAT_0014ea87;
LAB_0011b088:
    _printk(puVar4,"fastrpc_restart_notifier_cb",puVar5);
  }
  lVar8 = DAT_001505d0[0xe];
  if (lVar8 == 0) {
    lVar8 = *DAT_001505d0;
  }
  fastrpc_rproc_trace_events(lVar8,"fastrpc_restart_notifier",&DAT_0014f15b);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// fastrpc_register_wakeup_source @ 0011b0d4 size=128
// signature: undefined fastrpc_register_wakeup_source(void)
// callers: [init_module]
//------------------------------------------------------------

void fastrpc_register_wakeup_source(long *param_1,undefined8 param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  uVar2 = wakeup_source_register();
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    lVar1 = sp_el0;
    lVar3 = param_1[0xe];
    if (lVar3 == 0) {
      lVar3 = *param_1;
    }
    _printk(&DAT_0014e4da,0x196f,lVar1 + 0x848,"fastrpc_register_wakeup_source",lVar3,param_2);
  }
  else {
    *param_3 = uVar2;
  }
  return;
}



//------------------------------------------------------------
// fastrpc_deinit @ 0011b154 size=256
// signature: undefined fastrpc_deinit(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

void fastrpc_deinit(void)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  undefined **ppuVar5;
  long lVar6;
  
  iVar4 = 0;
  ppuVar5 = &gcinfo;
  do {
    lVar6 = 0;
    do {
      lVar1 = (long)ppuVar5 + lVar6;
      if (lVar1 != -0x18) {
        lVar2 = *(long *)(lVar1 + 0x58);
        if (*(long *)(lVar1 + 0x50) != 0) {
          gen_pool_destroy();
          *(undefined8 *)(lVar1 + 0x50) = 0;
        }
        if ((lVar2 != 0) && (*(long *)(lVar1 + 0x20) != 0)) {
          uVar3 = iommu_get_domain_for_dev();
          iommu_unmap(uVar3,*(undefined8 *)((long)ppuVar5 + lVar6 + 0x60),
                      *(undefined8 *)((long)ppuVar5 + lVar6 + 0x68));
          if (*(long *)(lVar2 + 0x40) != 0) {
            dma_free_attrs(*(undefined8 *)(lVar1 + 0x20),*(undefined8 *)(lVar2 + 0x48),
                           *(undefined8 *)(lVar2 + 0x38),*(long *)(lVar2 + 0x40),
                           *(undefined8 *)(lVar2 + 0x50));
          }
          kfree(lVar2);
          *(undefined8 *)(lVar1 + 0x58) = 0;
        }
      }
      if (*(long *)(lVar1 + 0x20) != 0) {
        *(undefined8 *)(lVar1 + 0x20) = 0;
      }
      lVar6 = lVar6 + 0x60;
    } while (lVar6 != 0x540);
    kfree(ppuVar5[0x140]);
    kfree(ppuVar5[0x141]);
    fastrpc_transport_session_deinit(iVar4);
    iVar4 = iVar4 + 1;
    ppuVar5 = ppuVar5 + 0xd4d;
  } while (iVar4 != 5);
  if (DAT_001505e4 != 0) {
    fastrpc_transport_deinit();
  }
  DAT_001505e4 = 0;
  return;
}



//------------------------------------------------------------
// fastrpc_probe @ 0011b258 size=4024
// signature: undefined fastrpc_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fastrpc_probe(long param_1)

{
  long *plVar1;
  ulong *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  char *__s1;
  long lVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  ulong uVar16;
  undefined *puVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  long lVar20;
  long *plVar21;
  ulong uVar22;
  long lVar23;
  long lVar24;
  uint local_ec;
  undefined8 local_e8;
  ulong local_e0;
  uint local_d4;
  ulong local_d0;
  undefined8 local_c8;
  ulong local_c0;
  undefined8 uStack_b8;
  uint uStack_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar10 = sp_el0;
  local_70 = *(long *)(lVar10 + 0x638);
  plVar1 = (long *)(param_1 + 0x10);
  puVar15 = (undefined8 *)(param_1 + 0x2f8);
  local_ec = 0;
  iVar7 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,msm-fastrpc-compute");
  if (iVar7 == 0) {
LAB_0011b570:
    uVar11 = 0;
  }
  else {
    uVar8 = sysfs_create_group(plVar1,msm_remote_dsp_attr_group);
    if (uVar8 != 0) {
      uVar11 = (ulong)uVar8;
      lVar10 = sp_el0;
      _printk(&DAT_0014fdcd,0x2146,lVar10 + 0x848,"fastrpc_probe",uVar11);
      goto LAB_0011bf9c;
    }
    local_c0 = local_c0 & 0xffffffff00000000;
    lVar10 = of_find_property(*puVar15,"qcom,adsp-remoteheap-vmid",&local_c0);
    if ((lVar10 != 0) && ((uint)local_c0 != 0)) {
      uVar11 = local_c0 & 0xfffffffc;
      local_c0 = CONCAT44(local_c0._4_4_,(uint)local_c0 >> 2);
      lVar10 = __kmalloc(uVar11,0xdc0);
      if (lVar10 == 0) {
        lVar12 = 0;
      }
      else {
        uVar11 = (local_c0 & 0xffffffff) * 4;
        lVar12 = __kmalloc(uVar11,0xdc0);
        if (lVar12 != 0) {
          uVar18 = 0;
          if ((uint)local_c0 != 0) {
            uVar22 = 0;
            lVar13 = sp_el0;
            do {
              puVar19 = (undefined4 *)(lVar10 + uVar22 * 4);
              iVar7 = of_property_read_u32_index
                                (*puVar15,"qcom,adsp-remoteheap-vmid",uVar22 & 0xffffffff,puVar19);
              if (iVar7 != 0) {
                _printk(&DAT_0014f0d2,"init_secure_vmid_list");
                goto LAB_0011b3ac;
              }
              _printk(&DAT_0014f281,0x209f,lVar13 + 0x848,"init_secure_vmid_list",*puVar19);
              if (uVar11 <= uVar22 * 4) goto LAB_0011c204;
              *(undefined4 *)(lVar12 + uVar22 * 4) = 7;
              uVar22 = uVar22 + 1;
              uVar18 = (uint)local_c0;
            } while (uVar22 < (local_c0 & 0xffffffff));
          }
          DAT_00129d78 = lVar10;
          DAT_00129d80 = lVar12;
          DAT_00129d88 = uVar18;
          goto LAB_0011b3bc;
        }
      }
LAB_0011b3ac:
      kfree(lVar10);
      kfree(lVar12);
    }
LAB_0011b3bc:
    local_c0 = local_c0 & 0xffffffff00000000;
    lVar10 = of_find_property(*puVar15,"qcom,fastrpc-gids",&local_c0);
    if ((lVar10 != 0) && ((uint)local_c0 != 0)) {
      uVar11 = local_c0 & 0xfffffffc;
      local_c0 = CONCAT44(local_c0._4_4_,(uint)local_c0 >> 2);
      lVar10 = __kmalloc(uVar11,0xdc0);
      if (lVar10 == 0) {
LAB_0011b4dc:
        kfree(lVar10);
      }
      else {
        if ((uint)local_c0 == 0) {
          uVar11 = 0;
        }
        else {
          lVar12 = 0;
          uVar22 = 0;
          do {
            iVar7 = of_property_read_u32_index
                              (*puVar15,"qcom,fastrpc-gids",uVar22 & 0xffffffff,lVar10 + lVar12);
            if (iVar7 != 0) {
              _printk(&DAT_0014e6ca,"fastrpc_init_privileged_gids",uVar22 & 0xffffffff);
              goto LAB_0011b4dc;
            }
            _printk(&DAT_0014e6f7,"fastrpc_init_privileged_gids",
                    *(undefined4 *)(lVar10 + uVar22 * 4));
            uVar11 = local_c0 & 0xffffffff;
            uVar22 = uVar22 + 1;
            lVar12 = lVar12 + 4;
          } while (uVar22 < uVar11);
        }
        sort(lVar10,uVar11,4,uint_cmp_func,0);
        DAT_00150620 = (uint)local_c0;
        DAT_00150618 = lVar10;
      }
    }
    lVar10 = of_find_property(*puVar15,"qcom,single-core-latency-vote",0);
    DAT_001506a0 = lVar10 != 0;
    if (lVar10 != 0) {
      DAT_0015069c = 1;
    }
    of_property_read_variable_u32_array(*puVar15,"qcom,rpc-latency-us",&DAT_001505e0,1,0);
    of_property_read_variable_u32_array(*puVar15,"qcom,max-sessions",&DAT_001506a4,1,0);
    lVar10 = of_get_property(*puVar15,"qcom,secure-domains",0);
    if (lVar10 == 0) goto LAB_0011b570;
    iVar7 = of_property_read_variable_u32_array(*puVar15,"qcom,secure-domains",&local_ec,1,0);
    uVar8 = local_ec;
    if (-1 < iVar7) {
      lVar10 = sp_el0;
      lVar10 = lVar10 + 0x848;
      *(uint *)(gfa + 0xa20) = local_ec & 1;
      _printk(&DAT_0015023c,0x20de,lVar10,"configure_secure_channels",0);
      *(uint *)(gfa + 0x7488) = uVar8 >> 1 & 1;
      _printk(&DAT_0015023c,0x20de,lVar10,"configure_secure_channels",1);
      *(uint *)(gfa + 0xdef0) = uVar8 >> 2 & 1;
      _printk(&DAT_0015023c,0x20de,lVar10,"configure_secure_channels",2);
      *(uint *)(gfa + 0x14958) = uVar8 >> 3 & 1;
      _printk(&DAT_0015023c,0x20de,lVar10,"configure_secure_channels",3);
      goto LAB_0011b570;
    }
    _printk(&DAT_0014bc23);
    uVar11 = 0xffffffff;
  }
  iVar7 = of_device_is_compatible(*puVar15,"qcom,msm-fastrpc-compute-cb");
  if (iVar7 == 0) {
    iVar7 = of_device_is_compatible(*puVar15,"qcom,msm-adsprpc-mem-region");
    if (iVar7 == 0) {
      lVar10 = of_find_property(*puVar15,"qcom,fastrpc-legacy-remote-heap",0);
      DAT_001505ec = lVar10 != 0;
      uVar22 = fastrpc_setup_service_locator
                         (plVar1,"qcom,fastrpc-adsp-audio-pdr","audio_pdr_adsprpc","avs/audio",
                          "msm/adsp/audio_pd");
      uVar11 = uVar22 & 0xffffffff;
      if ((int)uVar22 == 0) {
        uVar22 = fastrpc_setup_service_locator
                           (plVar1,"qcom,fastrpc-adsp-sensors-pdr","sensors_pdr_adsprpc",
                            "tms/servreg","msm/adsp/sensor_pd");
        uVar11 = uVar22 & 0xffffffff;
        if ((int)uVar22 == 0) {
          uVar22 = fastrpc_setup_service_locator
                             (plVar1,"qcom,fastrpc-slpi-sensors-pdr","sensors_pdr_sdsprpc",
                              "tms/servreg","msm/slpi/sensor_pd");
          uVar11 = uVar22 & 0xffffffff;
          if ((int)uVar22 == 0) {
            uVar11 = of_platform_populate(*puVar15,&fastrpc_match_table,0,plVar1);
            uVar11 = uVar11 & 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_001505d0 = plVar1;
      iVar7 = of_reserved_mem_device_init_by_idx(plVar1,*puVar15,0);
      if (iVar7 != 0) {
        _printk(&DAT_0014dde0,"fastrpc_probe",iVar7);
      }
    }
    goto LAB_0011bf9c;
  }
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
  local_d4 = 0;
  local_c8 = 0;
  __s1 = (char *)of_get_property(*puVar15,"label",0);
  if (__s1 != (char *)0x0) {
    if ((gcinfo == (undefined *)0x0) || (iVar7 = strcmp(__s1,gcinfo), iVar7 != 0)) {
      if ((PTR_s_mdsprpc_smd_0012fde0 == (undefined *)0x0) ||
         (iVar7 = strcmp(__s1,PTR_s_mdsprpc_smd_0012fde0), iVar7 != 0)) {
        if ((PTR_s_sdsprpc_smd_00136848 == (undefined *)0x0) ||
           (iVar7 = strcmp(__s1,PTR_s_sdsprpc_smd_00136848), iVar7 != 0)) {
          if ((PTR_s_cdsprpc_smd_0013d2b0 == (undefined *)0x0) ||
             (iVar7 = strcmp(__s1,PTR_s_cdsprpc_smd_0013d2b0), iVar7 != 0)) {
            if ((DAT_00143d18 == (char *)0x0) || (iVar7 = strcmp(__s1,DAT_00143d18), iVar7 != 0)) {
              uVar11 = 0xffffffd4;
              goto LAB_0011bf9c;
            }
            lVar10 = 4;
          }
          else {
            lVar10 = 3;
          }
        }
        else {
          lVar10 = 2;
        }
      }
      else {
        lVar10 = 1;
      }
    }
    else {
      lVar10 = 0;
    }
    if ((ulong)(&DAT_00129d48)[lVar10 * 0xd4d] < 0xe) {
      uVar8 = __of_parse_phandle_with_args(*puVar15,"iommus","#iommu-cells",0xffffffff,0,&local_c0);
      if (uVar8 == 0) {
        puVar2 = &DAT_00129d48 + lVar10 * 0xd4d;
        uVar22 = *puVar2;
        if (0xe < uVar22) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x11c210);
          (*pcVar6)();
        }
        lVar12 = uVar22 * 0x60 + lVar10 * 0x6a68;
        if (lVar12 - 0x21395U < 0xfffffffffffdebfb) goto LAB_0011c204;
        lVar23 = uVar22 * 0x60 + lVar10 * 0x6a68;
        (&DAT_001293e8)[lVar10 * 0x1a9a + uVar22 * 0x18] = 0;
        lVar13 = of_find_property(*puVar15,"dma-coherent",0);
        if (lVar23 - 0x213c5U < 0xfffffffffffdebfb) goto LAB_0011c204;
        lVar24 = uVar22 * 0x60 + lVar10 * 0x6a68;
        *(uint *)(lVar24 + 0x1293b8) = (uint)(lVar13 != 0);
        lVar13 = of_find_property(*puVar15,"qcom,secure-context-bank",0);
        if (lVar24 - 0x213c9U < 0xfffffffffffdebfb) goto LAB_0011c204;
        *(uint *)(lVar24 + 0x1293b4) = (uint)(lVar13 != 0);
        if ((uVar22 * 0x60 + lVar10 * 0x6a68) - 0x213d5 < 0xfffffffffffdebfb) goto LAB_0011c204;
        *(uint *)(lVar10 * 0x6a68 + uVar22 * 0x60 + 0x1293a8) = uStack_b4 & 0xf;
        if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
        plVar21 = (long *)(&DAT_00129398 + lVar23);
        *plVar21 = (long)plVar1;
        lVar13 = *(long *)(param_1 + 0x80);
        if (lVar13 == 0) {
          lVar13 = *plVar1;
        }
        if (((uVar22 * 0x60 + lVar10 * 0x6a68) - 0x213d9 < 0xfffffffffffdebff) ||
           (lVar20 = uVar22 * 0x60 + lVar10 * 0x6a68, *(long *)(lVar20 + 0x1293a0) = lVar13,
           lVar20 - 0x213d1U < 0xfffffffffffdebfb)) goto LAB_0011c204;
        *(undefined4 *)(lVar10 * 0x6a68 + uVar22 * 0x60 + 0x1293ac) = 1;
        puVar19 = *(undefined4 **)(param_1 + 0x2c8);
        if (puVar19 == (undefined4 *)0x0) {
          uVar14 = devm_kmalloc(plVar1,0x10,0xdc0);
          if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
          *(undefined8 *)(*plVar21 + 0x2b8) = uVar14;
          puVar19 = *(undefined4 **)(*plVar21 + 0x2b8);
          if (puVar19 != (undefined4 *)0x0) goto LAB_0011bab4;
        }
        else {
LAB_0011bab4:
          *puVar19 = 0xffffffff;
          if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
          if (*(long *)(*plVar21 + 0x2b8) != 0) {
            *(undefined8 *)(*(long *)(*plVar21 + 0x2b8) + 8) = 0xffffffffffffffff;
          }
        }
        of_property_read_variable_u32_array(*puVar15,"qcom,iommu-dma-addr-pool",&local_c8,2,0);
        DAT_0015064c = 0x78000000;
        if (local_c8._4_4_ != 0) {
          DAT_0015064c = local_c8._4_4_;
        }
        lVar13 = of_get_property(*puVar15,"pd-type",0);
        if (lVar13 != 0) {
          uVar9 = of_property_read_variable_u32_array
                            (*puVar15,"pd-type",lVar10 * 0x6a68 + uVar22 * 0x60 + 0x1293c0,1,0);
          uVar8 = uVar9;
          if (-1 < (int)uVar9) {
            uVar8 = 0;
          }
          uVar11 = (ulong)uVar8;
          DAT_00150698 = 1;
          if ((int)uVar9 < 0) goto LAB_0011bf9c;
        }
        lVar13 = of_get_property(*puVar15,"shared-cb",0);
        if (lVar13 != 0) {
          if (((uVar22 * 0x60 + lVar10 * 0x6a68) - 0x213c1 < 0xfffffffffffdebfb) ||
             (*(undefined4 *)(lVar10 * 0x6a68 + uVar22 * 0x60 + 0x1293bc) = 1,
             lVar24 - 0x213c9U < 0xfffffffffffdebfb)) goto LAB_0011c204;
          if (*(uint *)(lVar24 + 0x1293b4) != 0) {
            DAT_00150694 = 1;
          }
          uVar9 = of_property_read_variable_u32_array(*puVar15,"shared-cb",&local_d4,1,0);
          uVar8 = uVar9;
          if (-1 < (int)uVar9) {
            uVar8 = 0;
          }
          uVar11 = (ulong)uVar8;
          if ((int)uVar9 < 0) goto LAB_0011bf9c;
          if (1 < local_d4) {
            iVar7 = local_d4 - 1;
            do {
              if (0xc < *puVar2) break;
              uVar11 = *puVar2 + 1;
              puVar17 = *(undefined **)(lVar12 + 0x129390);
              puVar4 = *(undefined **)(&DAT_00129398 + lVar12);
              iVar7 = iVar7 + -1;
              *puVar2 = uVar11;
              puVar3 = *(undefined **)(lVar12 + 0x1293a0);
              puVar5 = *(undefined **)(lVar12 + 0x1293a8);
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 3] = puVar17;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 4] = puVar4;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 5] = puVar3;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 6] = puVar5;
              puVar3 = *(undefined **)(&DAT_001293c8 + lVar12);
              puVar17 = *(undefined **)(lVar12 + 0x1293b0);
              puVar4 = *(undefined **)(lVar12 + 0x1293b8);
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 9] = *(undefined **)(lVar12 + 0x1293c0);
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 10] = puVar3;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 7] = puVar17;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 8] = puVar4;
              puVar3 = *(undefined **)(&DAT_001293e8 + lVar10 * 0x1a9a + uVar22 * 0x18);
              puVar17 = *(undefined **)(&DAT_001293d0 + lVar12);
              puVar4 = *(undefined **)(&DAT_001293d8 + lVar12);
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 0xd] =
                   *(undefined **)(&DAT_001293e0 + lVar12);
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 0xe] = puVar3;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 0xb] = puVar17;
              (&gcinfo)[lVar10 * 0xd4d + uVar11 * 0xc + 0xc] = puVar4;
            } while (iVar7 != 0);
          }
        }
        lVar13 = of_get_property(*puVar15,"qrtr-gen-pool",0);
        if (lVar13 == 0) {
LAB_0011bf38:
          lVar10 = debugfs_root;
          uVar11 = 0;
          *puVar2 = *puVar2 + 1;
          if ((lVar10 != 0) && (debugfs_global_file == 0)) {
            debugfs_global_file = debugfs_create_file("global",0x1a4,lVar10,0,debugfs_fops);
            if ((debugfs_global_file == 0) || (0xfffffffffffff000 < debugfs_global_file)) {
              lVar10 = sp_el0;
              _printk(&DAT_0014b9c7,lVar10 + 0x848,"fastrpc_cb_probe");
              uVar11 = 0;
              debugfs_global_file = 0;
            }
            else {
              uVar11 = 0;
            }
          }
          goto LAB_0011bf9c;
        }
        local_d0 = 0;
        local_e8 = 0;
        local_e0 = 0;
        uVar8 = of_property_read_variable_u32_array(*puVar15,"frpc-gen-addr-pool",&local_d0,2,0);
        if (-1 < (int)uVar8) {
          if ((lVar12 - 0x213a1U < 0xfffffffffffdebff) ||
             (lVar13 = uVar22 * 0x60 + lVar10 * 0x6a68, lVar13 - 0x213a1U < 0xfffffffffffdebff))
          goto LAB_0011c204;
          *(ulong *)(&DAT_001293d8 + lVar13) = local_d0 & 0xffffffff;
          uVar14 = _kfree;
          if ((lVar12 - 0x21399U < 0xfffffffffffdebff) ||
             (lVar24 = uVar22 * 0x60 + lVar10 * 0x6a68, lVar24 - 0x21399U < 0xfffffffffffdebff))
          goto LAB_0011c204;
          *(ulong *)(&DAT_001293e0 + lVar24) = local_d0 >> 0x20;
          puVar15 = (undefined8 *)kmalloc_trace(uVar14,0xdc0,0x90);
          if (puVar15 == (undefined8 *)0x0) {
            lVar10 = sp_el0;
            _printk(&DAT_0014dd9f,0x2031,lVar10 + 0x848,"fastrpc_cb_probe",0x90);
            uVar11 = 0xfffffff4;
            goto LAB_0011bf9c;
          }
          *puVar15 = 0;
          puVar15[1] = 0;
          puVar15[9] = local_d0 >> 0x20;
          puVar15[10] = 0x20000;
          puVar15[7] = 0;
          puVar15[8] = 0;
          if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
          uVar11 = dma_alloc_attrs(*plVar21,local_d0 >> 0x20,puVar15 + 8,0xcc0,0x20000);
          puVar15[7] = uVar11;
          if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
            lVar10 = sp_el0;
            _printk(&DAT_0014ec28,0x2040,lVar10 + 0x848,"fastrpc_cb_probe",puVar15[9],uVar11);
            uVar11 = 0xffffff97;
          }
          else {
            if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
            uVar8 = dma_get_sgtable_attrs
                              (*plVar21,&local_e8,uVar11,puVar15[8],puVar15[9],puVar15[10]);
            if (uVar8 == 0) {
              if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
              lVar20 = iommu_get_domain_for_dev(*plVar21);
              if (lVar20 == 0) {
                lVar10 = sp_el0;
                _printk(&DAT_0014f0fd,0x204c,lVar10 + 0x848,"fastrpc_cb_probe");
                uVar11 = 0;
              }
              else {
                uVar11 = iommu_map_sg(lVar20,local_d0 & 0xffffffff,local_e8,local_e0 & 0xffffffff,7)
                ;
                if ((int)uVar11 < 0) {
                  lVar10 = sp_el0;
                  puVar17 = &DAT_0014fe21;
                  uVar14 = 0x2053;
                  goto LAB_0011c10c;
                }
                if (lVar23 - 0x213e1U < 0xfffffffffffdebff) goto LAB_0011c204;
                uVar16 = devm_gen_pool_create(*plVar21,0,0xffffffff,0);
                if (uVar16 < 0xfffffffffffff001) {
                  uVar11 = gen_pool_add_owner(uVar16,puVar15[7],puVar15[8],puVar15[9],0xffffffff,0);
                  if ((int)uVar11 == 0) {
                    if (((lVar12 - 0x213b1U < 0xfffffffffffdebff) ||
                        ((uVar22 * 0x60 + lVar10 * 0x6a68) - 0x213b1 < 0xfffffffffffdebff)) ||
                       (lVar12 = uVar22 * 0x60 + lVar10 * 0x6a68,
                       *(ulong *)(&DAT_001293c8 + lVar12) = uVar16,
                       lVar12 - 0x213a9U < 0xfffffffffffdebff)) goto LAB_0011c204;
                    *(undefined8 **)(&DAT_001293d0 + lVar10 * 0x6a68 + uVar22 * 0x60) = puVar15;
                    goto LAB_0011bf38;
                  }
                  uVar11 = uVar11 & 0xffffffff;
                  lVar10 = sp_el0;
                  _printk(&DAT_0014f65a,0x2062,lVar10 + 0x848,"fastrpc_cb_probe",uVar11);
                  gen_pool_destroy(uVar16);
                }
                else {
                  lVar10 = sp_el0;
                  _printk(&DAT_0014f2c2,0x205b,lVar10 + 0x848,"fastrpc_cb_probe",uVar16 & 0xffffffff
                         );
                  uVar11 = uVar16 & 0xffffffff;
                }
                if ((lVar13 - 0x213a1U < 0xfffffffffffdebff) ||
                   (lVar24 - 0x21399U < 0xfffffffffffdebff)) goto LAB_0011c204;
                iommu_unmap(lVar20,*(ulong *)(&DAT_001293d8 + lVar13),
                            *(ulong *)(&DAT_001293e0 + lVar24));
              }
            }
            else {
              uVar11 = (ulong)uVar8;
              lVar10 = sp_el0;
              puVar17 = &DAT_0014bc7c;
              uVar14 = 0x2047;
LAB_0011c10c:
              _printk(puVar17,uVar14,lVar10 + 0x848,"fastrpc_cb_probe",uVar11 & 0xffffffff);
            }
            if (lVar23 - 0x213e1U < 0xfffffffffffdebff) {
LAB_0011c204:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(1,0x11c208);
              (*pcVar6)();
            }
            dma_free_attrs(*plVar21,puVar15[9],puVar15[7],puVar15[8],puVar15[10]);
          }
          kfree(puVar15);
          goto LAB_0011bf9c;
        }
        lVar10 = *(long *)(param_1 + 0x80);
        if (lVar10 == 0) {
          lVar10 = *plVar1;
        }
        puVar17 = &DAT_0014c970;
      }
      else {
        lVar10 = *(long *)(param_1 + 0x80);
        if (lVar10 == 0) {
          lVar10 = *plVar1;
        }
        puVar17 = &DAT_0014f611;
      }
      uVar11 = (ulong)uVar8;
      _printk(puVar17,"fastrpc_cb_probe",lVar10,uVar11);
      goto LAB_0011bf9c;
    }
  }
  uVar11 = 0xffffffea;
LAB_0011bf9c:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// fastrpc_setup_service_locator @ 0011c210 size=400
// signature: undefined fastrpc_setup_service_locator(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

ulong fastrpc_setup_service_locator
                (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  int local_60;
  uint local_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = -1;
  local_5c = 0xffffffff;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),param_2,0);
  if (lVar5 == 0) {
LAB_0011c35c:
    uVar6 = 0;
  }
  else {
    uVar4 = fastrpc_get_spd_session(param_3,&local_5c,&local_60);
    uVar2 = local_5c;
    iVar1 = local_60;
    if (uVar4 == 0) {
      if (0xe < local_5c) {
LAB_0011c39c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11c3a0);
        (*pcVar3)();
      }
      uVar6 = pdr_handle_alloc(fastrpc_pdr_cb,
                               gfa + (long)local_60 * 0x6a68 + (ulong)local_5c * 0x48 + 0x558);
      if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
        if (0xd < uVar2) goto LAB_0011c39c;
        *(ulong *)(gfa + (long)iVar1 * 0x6a68 + (ulong)uVar2 * 0x48 + 0x568) = uVar6;
        uVar6 = pdr_add_lookup(uVar6,param_4,param_5);
        if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
          _printk(&DAT_0014e43e,"fastrpc_setup_service_locator",param_4,param_3,param_5,param_2);
          goto LAB_0011c35c;
        }
      }
      if ((int)uVar6 == 0) goto LAB_0011c360;
    }
    else {
      uVar6 = (ulong)uVar4;
    }
    _printk(&DAT_0014c0eb,"fastrpc_setup_service_locator",param_4,param_3,param_5,param_2,
            uVar6 & 0xffffffff);
  }
LAB_0011c360:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// fastrpc_nsp_status_show @ 0011c3a4 size=140
// signature: undefined fastrpc_nsp_status_show(void)
// callers: []
//------------------------------------------------------------

long fastrpc_nsp_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x88) == 0)) ||
     (iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,msm-fastrpc-compute"),
     iVar1 == 0)) {
    lVar2 = sp_el0;
    _printk(&DAT_0014eecd,0x2122,lVar2 + 0x848,"fastrpc_nsp_status_show");
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0015044c,DAT_00150690);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// fastrpc_pdr_cb @ 0011c434 size=856
// signature: undefined fastrpc_pdr_cb(void)
// callers: []
//------------------------------------------------------------

void fastrpc_pdr_cb(int param_1,undefined8 param_2,undefined8 *param_3)

{
  long *plVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long *plVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  char *__s1;
  long *plVar16;
  
  if (param_3 == (undefined8 *)0x0) {
    _printk(&DAT_0014e11c,"fastrpc_pdr_cb",param_2,param_1,0);
  }
  else if (param_1 == 0x1fffffff) {
    uVar3 = *(uint *)((long)param_3 + 0x2c);
    if (4 < uVar3) {
LAB_0011c8f4:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x11c8f8);
      (*pcVar7)();
    }
    if (0x21400 < (ulong)uVar3 * 0x6a68) {
LAB_0011c8f8:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(1,0x11c8fc);
      (*pcVar7)();
    }
    _printk(&DAT_0014e4ae,"fastrpc_pdr_cb",param_3[1],*param_3,
            (&PTR_s_lpass_00129380)[(ulong)uVar3 * 0xd4d]);
    *(undefined4 *)(param_3 + 5) = 1;
    __wake_up(param_3 + 6,1,1,0);
  }
  else if (param_1 == 0xfffffff) {
    uVar3 = *(uint *)((long)param_3 + 0x2c);
    if (4 < uVar3) goto LAB_0011c8f4;
    if (0x21400 < (ulong)uVar3 * 0x6a68) goto LAB_0011c8f8;
    _printk(&DAT_0014e480,"fastrpc_pdr_cb",param_3[1],*param_3,
            (&PTR_s_lpass_00129380)[(ulong)uVar3 * 0xd4d]);
    mutex_lock(gfa + (long)*(int *)((long)param_3 + 0x2c) * 0x6a68 + 0x9a0);
    param_3[3] = param_3[3] + 1;
    *(undefined4 *)(param_3 + 5) = 0;
    mutex_unlock(gfa + (long)*(int *)((long)param_3 + 0x2c) * 0x6a68 + 0x9a0);
    __s1 = (char *)*param_3;
    iVar8 = strcmp(__s1,"audio_pdr_adsprpc");
    if (iVar8 == 0) {
      DAT_001505b0 = 0;
      __s1 = (char *)*param_3;
    }
    uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
    if (DAT_001505c0 != (long *)0x0) {
      uVar10 = sp_el0;
      plVar14 = DAT_001505c0;
      do {
        plVar15 = (long *)*plVar14;
        if (((char *)plVar14[0x1b] != (char *)0x0) &&
           (iVar8 = strcmp(__s1,(char *)plVar14[0x1b]), iVar8 == 0)) {
          uVar10 = _raw_spin_lock_irqsave(plVar14 + 2);
          plVar16 = (long *)plVar14[7];
          while (plVar6 = plVar16, plVar6 != (long *)0x0) {
            plVar16 = (long *)*plVar6;
            if (*(int *)(plVar6 + 0x17) != 0) {
              *(undefined1 *)(plVar6 + 0x23) = 1;
              *(undefined4 *)(plVar6 + 8) = 0xffffff98;
              if ((*(int *)(plVar6 + 0x24) == 0) || (*(char *)((long)plVar6 + 0x16c) == '\0')) {
                complete(plVar6 + 4);
              }
              else {
                lVar13 = plVar6[0x13];
                uVar11 = _raw_spin_lock_irqsave(lVar13 + 0x1b8);
                if ((*(char *)(plVar6 + 0x27) == '\0') && (plVar6[3] != 0)) {
                  plVar1 = plVar6 + 2;
                  lVar12 = *(long *)(lVar13 + 0x50);
                  *plVar1 = lVar12;
                  if (lVar12 != 0) {
                    *(long **)(lVar12 + 8) = plVar1;
                  }
                  *(long **)(lVar13 + 0x50) = plVar1;
                  plVar6[3] = lVar13 + 0x50;
                  piVar2 = (int *)(lVar13 + 0x198);
                  Hint_Prefetch(piVar2,2,0,1);
                  do {
                    cVar4 = '\x01';
                    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                    if (bVar5) {
                      *piVar2 = *piVar2 + 1;
                      cVar4 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar4 != '\0');
                  *(undefined1 *)(plVar6 + 0x27) = 1;
                  __wake_up(lVar13 + 0x1a0,1,1,0);
                }
                _raw_spin_unlock_irqrestore(lVar13 + 0x1b8,uVar11);
              }
            }
          }
          plVar16 = (long *)plVar14[8];
          while (plVar6 = plVar16, plVar6 != (long *)0x0) {
            plVar16 = (long *)*plVar6;
            if (*(int *)(plVar6 + 0x17) != 0) {
              *(undefined1 *)(plVar6 + 0x23) = 1;
              *(undefined4 *)(plVar6 + 8) = 0xffffff98;
              complete((int)plVar14[0x18],plVar6 + 4);
            }
          }
          _raw_spin_unlock_irqrestore(plVar14 + 2,uVar10);
        }
        plVar14 = plVar15;
      } while (plVar15 != (long *)0x0);
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_hibernation_suspend @ 0011c900 size=124
// signature: undefined fastrpc_hibernation_suspend(void)
// callers: []
//------------------------------------------------------------

ulong fastrpc_hibernation_suspend(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,msm-fastrpc-compute");
  if ((int)uVar3 != 0) {
    uVar2 = fastrpc_dsp_restart_handler(0,0,1);
    uVar3 = 0;
    if (uVar2 != 0) {
      lVar1 = sp_el0;
      _printk(&DAT_0014c59e,0x21e2,lVar1 + 0x848,"fastrpc_hibernation_suspend",uVar2);
      uVar3 = (ulong)uVar2;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// fastrpc_restore @ 0011c980 size=124
// signature: undefined fastrpc_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_restore(void)

{
  _printk(&DAT_0014c129);
  *(undefined4 *)(gfa + 0x9e0) = 1;
  *(undefined4 *)(gfa + 0x7448) = 1;
  *(undefined4 *)(gfa + 0xdeb0) = 1;
  *(undefined4 *)(gfa + 0x14918) = 1;
  *(undefined4 *)(gfa + 0x1b380) = 1;
  _printk(&DAT_0014fe60);
  return 0;
}



//------------------------------------------------------------
// fastrpc_device_ioctl @ 0011ca00 size=7584
// signature: undefined fastrpc_device_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long fastrpc_device_ioctl(long param_1,int param_2,ulong param_3)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  size_t sVar11;
  uint *puVar12;
  undefined8 *puVar13;
  long *plVar14;
  ulong uVar15;
  long lVar16;
  uint uVar17;
  uint uVar18;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  ulong local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulong local_60;
  ulong local_58;
  undefined8 local_50;
  long local_48;
  
  lVar16 = sp_el0;
  local_48 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0xd8);
  local_a8 = 0;
  local_a0 = 0;
  local_ac = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (lVar16 != 0) {
    puVar12 = (uint *)(lVar16 + 0x78);
    uVar17 = *puVar12;
    if (*puVar12 == 0) {
      uVar18 = 0;
    }
    else {
      do {
        Hint_Prefetch(puVar12,2,0,1);
        do {
          uVar2 = *puVar12;
          if (uVar2 != uVar17) break;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar12,0x10);
          if (bVar4) {
            *puVar12 = uVar17 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        uVar18 = uVar17;
        if (uVar17 == uVar2) break;
        uVar18 = 0;
        uVar17 = uVar2;
      } while (uVar2 != 0);
    }
    if ((int)(uVar18 + 1 | uVar18) < 0) {
      refcount_warn_saturate(puVar12,0);
    }
    if (uVar18 != 0) {
      lVar1 = lVar16 + 0x10;
      _raw_spin_lock(lVar1);
      if (0 < *(int *)(lVar16 + 0xe0)) {
        _printk(&DAT_0014f7f8);
        _raw_spin_unlock(lVar1);
        iVar9 = -0x6c;
        goto LAB_0011e38c;
      }
      _raw_spin_unlock(lVar1);
      uVar17 = (uint)_cpu_hwcaps;
      if (param_2 < -0x3fe7adfc) {
        if (-0x3ff7ade7 < param_2) {
          if (-0x3fefae00 < param_2) {
            if (param_2 != -0x3fefadff) {
              if (param_2 != -0x3fefadfd) {
                iVar9 = -0x3fefadf1;
                goto LAB_0011cf68;
              }
              goto LAB_0011cf70;
            }
            sVar10 = 0x10;
            goto code_r0x0011dc4c;
          }
          if (param_2 != -0x3ff7ade6) {
            if (param_2 == -0x3ff3adf4) {
              iVar9 = fastrpc_control(&local_a8,param_3,lVar16);
              goto LAB_0011e38c;
            }
            if (param_2 != -0x3ff3adef) goto switchD_0011cb2c_caseD_c0045206;
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7ffffffff5) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              uVar15 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0xc);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar5 = daif;
                if ((uVar5 & 0x80) == 0) {
                  uVar6 = daif;
                  daif = uVar6 | 0xc0;
                }
                uVar6 = ttbr1_el1;
                ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar6 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar5;
              }
              if (uVar15 != 0) goto LAB_0011e4c0;
            }
            else {
              uVar15 = 0xc;
LAB_0011e4c0:
              memset((void *)((long)&local_a0 + (4 - uVar15)),0,uVar15);
            }
            iVar9 = -0x2c;
            if (((uint)local_a8 < 5) && ((uVar15 & 0xffffffff) == 0)) {
              local_a0 = local_a0 & 0xffffffff00000000;
              iVar9 = fastrpc_get_info_from_kernel(&local_a8,lVar16);
              if (iVar9 == 0) {
                param_3 = param_3 + 8;
                if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                   (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                  uVar15 = param_3 & (long)(param_3 * 0x100) >> 8;
                }
                iVar9 = 4;
                if (uVar15 < 0x7ffffffffd) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar15 = daif;
                    if ((uVar15 & 0x80) == 0) {
                      uVar5 = daif;
                      daif = uVar5 | 0xc0;
                    }
                    uVar5 = ttbr1_el1;
                    ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar13[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar15;
                  }
                  iVar9 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a0,4);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar15 = daif;
                    if ((uVar15 & 0x80) == 0) {
                      uVar5 = daif;
                      daif = uVar5 | 0xc0;
                    }
                    uVar5 = ttbr1_el1;
                    ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar5 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar15;
                  }
                }
              }
            }
            goto LAB_0011e38c;
          }
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7ffffffff9) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar5 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,8);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e4e0;
          }
          else {
            sVar10 = 8;
LAB_0011e4e0:
            memset((void *)((long)&local_a0 - sVar10),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_dspsignal_wait(lVar16,&local_a8);
          goto LAB_0011e38c;
        }
        switch(param_2) {
        case -0x3ffbadfb:
          uVar17 = (uint)param_3;
          if (uVar17 < 2) {
            iVar9 = 0;
            *(uint *)(lVar16 + 0xa8) = uVar17;
            goto LAB_0011e38c;
          }
          if (uVar17 == 2) {
            iVar9 = 0;
            *(undefined4 *)(lVar16 + 0xac) = 2;
            goto LAB_0011e38c;
          }
          if (uVar17 == 4) {
            if (*(char *)(lVar16 + 0x2b4) == '\0') {
              iVar9 = 0;
              *(undefined4 *)(lVar16 + 0xb0) = 1;
            }
            else {
              iVar9 = 0;
            }
            goto LAB_0011e38c;
          }
          break;
        case -0x3ffbadf8:
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7ffffffffd) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(&local_ac,param_3 & 0xff7fffffffffffff,4);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e430;
          }
          else {
            sVar10 = 4;
LAB_0011e430:
            memset((void *)((long)&local_a8 - sVar10),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_get_info(lVar16,&local_ac);
          if (iVar9 != 0) goto LAB_0011e38c;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          iVar8 = 4;
          if (uVar15 < 0x7ffffffffd) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_ac,4);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
          }
LAB_0011e120:
          iVar9 = 0;
          if (iVar8 != 0) {
            iVar9 = -0xe;
          }
          goto LAB_0011e38c;
        case -0x3ffbade8:
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7ffffffffd) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar5 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,4);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e40c;
          }
          else {
            sVar10 = 4;
LAB_0011e40c:
            memset((void *)((long)&local_a8 + (4 - sVar10)),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_dspsignal_destroy(lVar16,&local_a8);
          goto LAB_0011e38c;
        case -0x3ffbade7:
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7ffffffffd) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar5 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,4);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e478;
          }
          else {
            sVar10 = 4;
LAB_0011e478:
            memset((void *)((long)&local_a8 + (4 - sVar10)),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_dspsignal_signal(lVar16,&local_a8);
          goto LAB_0011e38c;
        case -0x3ffbade5:
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7ffffffffd) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar5 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,4);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e454;
          }
          else {
            sVar10 = 4;
LAB_0011e454:
            memset((void *)((long)&local_a8 + (4 - sVar10)),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_dspsignal_cancel_wait(lVar16,&local_a8);
          goto LAB_0011e38c;
        default:
          if (param_2 == -0x3ff7ade9) {
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7ffffffff9) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                puVar13 = (undefined8 *)puVar13[1];
                uVar5 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,8);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e504;
            }
            else {
              sVar10 = 8;
LAB_0011e504:
              memset((void *)((long)&local_a0 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            iVar9 = fastrpc_dspsignal_create(lVar16,&local_a8);
            goto LAB_0011e38c;
          }
        case -0x3ffbadfa:
        case -0x3ffbadf9:
        case -0x3ffbadf7:
        case -0x3ffbadf6:
        case -0x3ffbadf5:
        case -0x3ffbadf4:
        case -0x3ffbadf3:
        case -0x3ffbadf2:
        case -0x3ffbadf1:
        case -0x3ffbadf0:
        case -0x3ffbadef:
        case -0x3ffbadee:
        case -0x3ffbaded:
        case -0x3ffbadec:
        case -0x3ffbadeb:
        case -0x3ffbadea:
        case -0x3ffbade9:
        case -0x3ffbade6:
switchD_0011cb2c_caseD_c0045206:
          _printk(&DAT_0014e71a,param_2);
        }
        iVar9 = -0x19;
      }
      else if (param_2 < -0x3fd7adfa) {
        if (param_2 < -0x3fdfadfe) {
          if (param_2 != -0x3fe7adfc) {
            if (param_2 == -0x3fe7adf3) goto LAB_0011cf70;
            if (param_2 != -0x3fe7adee) goto switchD_0011cb2c_caseD_c0045206;
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7fffffffe9) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                puVar13 = (undefined8 *)puVar13[1];
                uVar5 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,0x18);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e49c;
            }
            else {
              sVar10 = 0x18;
LAB_0011e49c:
              memset((void *)((long)&local_90 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            iVar9 = fastrpc_internal_invoke2(lVar16,&local_a8,0);
            goto LAB_0011e38c;
          }
          sVar10 = 0x18;
        }
        else {
          if (param_2 == -0x3fdfadfe) goto LAB_0011cf70;
          if (param_2 != -0x3fdfadf9) {
            iVar9 = -0x3fdfadf2;
            goto LAB_0011cf68;
          }
          sVar10 = 0x20;
        }
code_r0x0011dc4c:
        __check_object_size(&local_a8,sVar10,0);
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar15 = param_3 & (long)(param_3 << 8) >> 8;
        }
        sVar11 = sVar10;
        if (0x8000000000 - sVar10 < uVar15) {
LAB_0011e3c8:
          memset((void *)((long)&local_a8 + (sVar10 - sVar11)),0,sVar11);
          if ((int)sVar11 != 0) goto LAB_0011e61c;
        }
        else {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          sVar11 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,sVar10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          if (sVar11 != 0) goto LAB_0011e3c8;
        }
        iVar9 = fastrpc_internal_invoke(lVar16);
      }
      else {
        if (param_2 < -0x3fcfadec) {
          if (param_2 == -0x3fd7adfa) {
            sVar10 = 0x28;
            local_80 = 0;
          }
          else {
            if (param_2 == -0x3fd7adf5) {
              sVar10 = 0x28;
              goto code_r0x0011dc4c;
            }
            if (param_2 != -0x3fcfadf6) goto switchD_0011cb2c_caseD_c0045206;
            sVar10 = 0x30;
          }
          __check_object_size(&local_a8,sVar10,0);
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          sVar11 = sVar10;
          if (0x8000000000 - sVar10 < uVar15) {
LAB_0011e3e8:
            memset((void *)((long)&local_a8 + (sVar10 - sVar11)),0,sVar11);
            if ((int)sVar11 != 0) goto LAB_0011e61c;
          }
          else {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              puVar13 = (undefined8 *)puVar13[1];
              uVar5 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar11 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,sVar10);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar11 != 0) goto LAB_0011e3e8;
          }
          iVar9 = fastrpc_init_process(lVar16,&local_a8);
          goto LAB_0011e38c;
        }
        if (param_2 != -0x3fcfadec) {
          if (param_2 == -0x3fc7adeb) {
            sVar10 = 0x38;
            goto code_r0x0011dc4c;
          }
          iVar9 = -0x3fbfaded;
LAB_0011cf68:
          if (param_2 != iVar9) goto switchD_0011cb2c_caseD_c0045206;
        }
LAB_0011cf70:
        local_58 = 0;
        local_50 = 0;
        local_68 = 0;
        local_60 = 0;
        if (param_2 < -0x3fdfadfe) {
          if (param_2 == -0x3fefadfd) {
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7ffffffff1) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                puVar13 = (undefined8 *)puVar13[1];
                uVar5 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,0x10);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e600;
            }
            else {
              sVar10 = 0x10;
LAB_0011e600:
              memset((void *)((long)&local_98 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            puVar13 = &local_a8;
          }
          else {
            if (param_2 != -0x3fefadf1) {
              if (param_2 != -0x3fe7adf3) goto switchD_0011cb2c_caseD_c0045206;
              puVar13 = (undefined8 *)sp_el0;
              if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
                 (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
                uVar15 = param_3 & (long)(param_3 << 8) >> 8;
              }
              if (uVar15 < 0x7fffffffe9) {
                if ((uVar17 >> 0x1d & 1) == 0) {
                  uVar15 = daif;
                  if ((uVar15 & 0x80) == 0) {
                    uVar5 = daif;
                    daif = uVar5 | 0xc0;
                  }
                  uVar5 = ttbr1_el1;
                  ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar13[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar15;
                }
                sVar10 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x18);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar15 = daif;
                  if ((uVar15 & 0x80) == 0) {
                    uVar5 = daif;
                    daif = uVar5 | 0xc0;
                  }
                  uVar5 = ttbr1_el1;
                  ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar5 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar15;
                }
                if (sVar10 != 0) goto LAB_0011e5b8;
              }
              else {
                sVar10 = 0x18;
LAB_0011e5b8:
                memset((void *)((long)&local_90 - sVar10),0,sVar10);
                if ((int)sVar10 != 0) goto LAB_0011e61c;
              }
              if (*(int *)(lVar16 + 0xe4) == 1) {
                mutex_lock(lVar16 + 0x140);
                mutex_lock(lVar16 + 0x110);
                if (CARRY8(local_98,local_a0)) {
                  iVar9 = -0xe;
LAB_0011d2b0:
                  _printk(&DAT_0014fe79,0x15c0,puVar13 + 0x109,"fastrpc_internal_munmap_fd");
                }
                else {
                  plVar14 = (long *)*(long *)(lVar16 + 0x18);
                  do {
                    plVar7 = plVar14;
                    if (plVar7 == (long *)0x0) {
                      iVar9 = -6;
                      goto LAB_0011d2b0;
                    }
                    plVar14 = (long *)*plVar7;
                  } while (((local_a0 < (ulong)plVar7[0xb]) ||
                           ((ulong)(plVar7[0xc] + plVar7[0xb]) < local_98 + local_a0)) ||
                          (*(int *)(plVar7 + 4) != (uint)local_a8));
                  if (((uint)plVar7[0x11] >> 3 & 1) != 0) {
                    plVar7[0x11] = plVar7[0x11] & 0xfffffffffffffff7;
                    fastrpc_mmap_free(plVar7,0);
                  }
                  iVar9 = 0;
                }
                mutex_unlock(lVar16 + 0x110);
                mutex_unlock(lVar16 + 0x140);
              }
              else {
                _printk(&DAT_0014ff3d,0x15b5,puVar13 + 0x109,"fastrpc_internal_munmap_fd",
                        puVar13 + 0x109);
                iVar9 = -0x70;
              }
              goto LAB_0011e38c;
            }
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7ffffffff1) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                puVar13 = (undefined8 *)puVar13[1];
                uVar5 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(puVar13,&local_a8,param_3 & 0xff7fffffffffffff,0x10);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e5dc;
            }
            else {
              sVar10 = 0x10;
LAB_0011e5dc:
              memset((void *)((long)&local_98 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            puVar13 = &local_68;
            local_68 = local_a8;
            local_60 = local_a0;
          }
          iVar9 = fastrpc_internal_munmap(lVar16,puVar13);
          goto LAB_0011e38c;
        }
        if (-0x3fcfaded < param_2) {
          if (param_2 == -0x3fcfadec) {
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7fffffffd1) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x30);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e594;
            }
            else {
              sVar10 = 0x30;
LAB_0011e594:
              memset((void *)((long)&local_78 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            iVar9 = fastrpc_internal_mem_unmap(lVar16,&local_a8);
            if (iVar9 != 0) goto LAB_0011e38c;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            iVar8 = 0x30;
            if (uVar15 < 0x7fffffffd1) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,0x30);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
            }
          }
          else {
            if (param_2 != -0x3fbfaded) goto switchD_0011cb2c_caseD_c0045206;
            puVar13 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            if (uVar15 < 0x7fffffffc1) {
              if ((uVar17 >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              sVar10 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x40);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              if (sVar10 != 0) goto LAB_0011e54c;
            }
            else {
              sVar10 = 0x40;
LAB_0011e54c:
              memset((void *)((long)&local_68 - sVar10),0,sVar10);
              if ((int)sVar10 != 0) goto LAB_0011e61c;
            }
            iVar9 = fastrpc_internal_mem_map(lVar16,&local_a8);
            if (iVar9 != 0) goto LAB_0011e38c;
            if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 << 8) >> 8;
            }
            iVar8 = 0x40;
            if (uVar15 < 0x7fffffffc1) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar13[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,0x40);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
            }
          }
          goto LAB_0011e120;
        }
        if (param_2 == -0x3fdfadfe) {
          puVar13 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar15 < 0x7fffffffe1) {
            if ((uVar17 >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            sVar10 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x20);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            if (sVar10 != 0) goto LAB_0011e570;
          }
          else {
            sVar10 = 0x20;
LAB_0011e570:
            memset((void *)((long)&local_88 - sVar10),0,sVar10);
            if ((int)sVar10 != 0) goto LAB_0011e61c;
          }
          iVar9 = fastrpc_internal_mmap(lVar16,&local_a8);
          if (iVar9 != 0) goto LAB_0011e38c;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          iVar8 = 0x20;
          if (uVar15 < 0x7fffffffe1) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,0x20);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
          }
          goto LAB_0011e120;
        }
        if (param_2 != -0x3fdfadf2) goto switchD_0011cb2c_caseD_c0045206;
        puVar13 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
           (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
          uVar15 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar15 < 0x7fffffffe1) {
          if ((uVar17 >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar13[1];
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          sVar10 = __arch_copy_from_user(&local_a8,param_3 & 0xff7fffffffffffff,0x20);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          if (sVar10 != 0) goto LAB_0011e528;
LAB_0011d080:
          local_60 = local_a0;
          local_58 = local_98;
          local_68 = local_a8;
          iVar9 = fastrpc_internal_mmap(lVar16,&local_68);
          if (iVar9 != 0) goto LAB_0011e38c;
          local_90 = local_50;
          if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = param_3, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
            uVar15 = param_3 & (long)(param_3 << 8) >> 8;
          }
          iVar8 = 0x20;
          if (uVar15 < 0x7fffffffe1) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr1_el1 = puVar13[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar13[1];
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_a8,0x20);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar5 = daif;
                daif = uVar5 | 0xc0;
              }
              uVar5 = ttbr1_el1;
              ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar5 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
          }
          goto LAB_0011e120;
        }
        sVar10 = 0x20;
LAB_0011e528:
        memset((void *)((long)&local_88 - sVar10),0,sVar10);
        if ((int)sVar10 == 0) goto LAB_0011d080;
LAB_0011e61c:
        iVar9 = -0xe;
      }
      goto LAB_0011e38c;
    }
  }
  lVar1 = sp_el0;
  _printk(&DAT_0014dd4f,0x1d5f,lVar1 + 0x848,"fastrpc_device_ioctl");
  iVar9 = -2;
LAB_0011e38c:
  fastrpc_file_put(lVar16);
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar9;
}



//------------------------------------------------------------
// fastrpc_device_open @ 0011eb1c size=568
// signature: undefined fastrpc_device_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fastrpc_device_open(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x4c) & 0xfffff;
  if (uVar1 < 2) {
    puVar4 = (undefined8 *)kmalloc_trace(_cpu_hwcaps,0xdc0,0x2b8);
    if (puVar4 == (undefined8 *)0x0) {
      uVar5 = 0xfffffff4;
    }
    else {
      puVar4[10] = 0;
      puVar4[7] = 0;
      puVar4[8] = 0;
      *(undefined4 *)(puVar4 + 9) = 0;
      puVar4[0xb] = puVar4 + 0xb;
      puVar4[0xc] = puVar4 + 0xb;
      *(undefined4 *)(puVar4 + 2) = 0;
      *(undefined4 *)(puVar4 + 0x37) = 0;
      *(undefined4 *)(puVar4 + 0x3c) = 0;
      puVar4[6] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      *(undefined4 *)(puVar4 + 5) = 0;
      __init_waitqueue_head(puVar4 + 0x34,"&fl->async_wait_queue",&fastrpc_device_open___key);
      __init_waitqueue_head
                (puVar4 + 0x39,"&fl->proc_state_notif.notif_wait_queue",
                 &fastrpc_device_open___key_482);
      *puVar4 = 0;
      puVar4[1] = 0;
      lVar3 = sp_el0;
      *(undefined4 *)(puVar4 + 0x16) = 0;
      uVar2 = *(undefined4 *)(lVar3 + 0x634);
      *(undefined4 *)((long)puVar4 + 0xec) = 0;
      *(undefined4 *)((long)puVar4 + 0xb4) = uVar2;
      *(undefined8 *)((long)puVar4 + 0xbc) = 0xffffffffffffffff;
      puVar4[0x1e] = &gfa;
      *(undefined4 *)(puVar4 + 0x15) = 1;
      *(undefined4 *)((long)puVar4 + 0xc4) = 0xffffffff;
      *(uint *)(puVar4 + 0x2e) = uVar1;
      puVar4[0xe] = 0;
      *(undefined4 *)(puVar4 + 0x21) = 0;
      *(undefined4 *)((long)puVar4 + 0xe4) = 0;
      *(undefined4 *)(puVar4 + 0x45) = 0;
      *(undefined1 *)((long)puVar4 + 0x22c) = 0;
      *(undefined2 *)(puVar4 + 0x55) = 0;
      *(undefined2 *)((long)puVar4 + 0x2b4) = 0;
      *(undefined4 *)(puVar4 + 0x3f) = 0;
      __init_swait_queue_head(puVar4 + 0x40,"&x->wait",&init_completion___key);
      *(undefined4 *)(puVar4 + 0x1c) = 0;
      *(undefined8 **)(param_2 + 0xd8) = puVar4;
      *(undefined4 *)((long)puVar4 + 0x2ac) = 0xffffffff;
      __mutex_init(puVar4 + 0x28,"&fl->internal_map_mutex",&fastrpc_device_open___key_484);
      __mutex_init(puVar4 + 0x22,"&fl->map_mutex",&fastrpc_device_open___key_486);
      uVar5 = _raw_spin_lock_irqsave(&DAT_001505c8);
      *puVar4 = DAT_001505c0;
      if (DAT_001505c0 != (undefined8 *)0x0) {
        DAT_001505c0[1] = puVar4;
      }
      DAT_001505c0 = puVar4;
      puVar4[1] = &DAT_001505c0;
      _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar5);
      *(undefined4 *)(puVar4 + 0xf) = 1;
      if (DAT_0015069c != 0) {
        uVar5 = __kmalloc((ulong)DAT_0015069c * 0x50,0xdc0);
        puVar4[0x20] = uVar5;
      }
      *(undefined4 *)(puVar4 + 0x4a) = 0;
      __mutex_init(puVar4 + 0x4b,"&fl->signal_create_mutex",&fastrpc_device_open___key_488);
      *(undefined4 *)(puVar4 + 0x51) = 0;
      __init_swait_queue_head(puVar4 + 0x52,"&x->wait",&init_completion___key);
      uVar5 = 0;
    }
  }
  else {
    lVar3 = sp_el0;
    _printk(&DAT_0014c45c,0x1986,lVar3 + 0x848,"fastrpc_device_open",uVar1);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



//------------------------------------------------------------
// fastrpc_device_release @ 0011ed58 size=168
// signature: undefined fastrpc_device_release(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_device_release(undefined8 param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  lVar2 = *(long *)(param_2 + 0xd8);
  if (lVar2 != 0) {
    if (((*(int *)(lVar2 + 0x108) != 0) && (*(long *)(lVar2 + 0x100) != 0)) &&
       (uVar1 = (ulong)DAT_0015069c, uVar1 != 0)) {
      lVar3 = 0;
      uVar4 = 0;
      do {
        if (*(long *)(*(long *)(lVar2 + 0x100) + lVar3 + 0x48) != 0) {
          dev_pm_qos_remove_request();
          uVar1 = (ulong)DAT_0015069c;
        }
        uVar4 = uVar4 + 1;
        lVar3 = lVar3 + 0x50;
      } while (uVar4 < uVar1);
    }
    debugfs_remove(*(undefined8 *)(lVar2 + 0xf8));
    fastrpc_file_put(lVar2);
    *(undefined8 *)(param_2 + 0xd8) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// fastrpc_update_ramdump_status @ 0011ee00 size=408
// signature: undefined fastrpc_update_ramdump_status(void)
// callers: [fastrpc_restart_notifier_cb]
//------------------------------------------------------------

void fastrpc_update_ramdump_status(void)

{
  long *plVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  uint *puVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  uint uVar14;
  
  lVar8 = gfa;
  plVar1 = (long *)(gfa + 0x1a990);
  uVar5 = _raw_spin_lock_irqsave(&DAT_001505c8);
  if (DAT_001505c0 != (long *)0x0) {
    lVar12 = sp_el0;
    plVar10 = DAT_001505c0;
    do {
      plVar13 = (long *)*plVar10;
      if (((((int)plVar10[0x18] == 3) && (plVar10[0xe] != 0)) && ((int)plVar10[0x1c] < 3)) &&
         (*(int *)((long)plVar10 + 0xe4) != 0)) {
        puVar6 = (uint *)(plVar10 + 0xf);
        uVar9 = *puVar6;
        if (*puVar6 == 0) {
          uVar14 = 0;
        }
        else {
          do {
            Hint_Prefetch(puVar6,2,0,1);
            do {
              uVar2 = *puVar6;
              if (uVar2 != uVar9) break;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar6,0x10);
              if (bVar4) {
                *puVar6 = uVar9 + 1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            uVar14 = uVar9;
          } while ((uVar9 != uVar2) && (uVar14 = 0, uVar9 = uVar2, uVar2 != 0));
        }
        if ((int)(uVar14 + 1 | uVar14) < 0) {
          refcount_warn_saturate(puVar6,0);
        }
        if (uVar14 == 0) {
          _printk(&DAT_0014c4e8,0x8f0,lVar12 + 0x848,"fastrpc_update_ramdump_status",plVar10);
        }
        else {
          lVar7 = plVar10[0xe];
          lVar11 = *plVar1;
          plVar10 = (long *)(lVar7 + 0x20);
          *plVar10 = lVar11;
          if (lVar11 != 0) {
            *(long **)(lVar11 + 8) = plVar10;
          }
          *plVar1 = (long)plVar10;
          *(long **)(lVar7 + 0x28) = plVar1;
        }
      }
      plVar10 = plVar13;
    } while (plVar13 != (long *)0x0);
  }
  lVar8 = *(long *)(lVar8 + 0x1a998);
  if (lVar8 != 0) {
    lVar12 = *plVar1;
    plVar10 = (long *)(lVar8 + 0x20);
    *plVar10 = lVar12;
    if (lVar12 != 0) {
      *(long **)(lVar12 + 8) = plVar10;
    }
    *plVar1 = (long)plVar10;
    *(long **)(lVar8 + 0x28) = plVar1;
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar5);
  return;
}



//------------------------------------------------------------
// fastrpc_print_debug_data @ 0011efac size=2444
// signature: undefined fastrpc_print_debug_data(void)
// callers: [fastrpc_restart_notifier_cb]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fastrpc_print_debug_data(void)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  size_t sVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  char *__s;
  long lVar15;
  long lVar16;
  long lVar17;
  
  lVar6 = kmalloc_trace(_cpu_hwcaps,0xdc0,1000);
  if (lVar6 == 0) {
    lVar7 = 0;
  }
  else {
    lVar7 = kmalloc_trace(_cpu_hwcaps,0xdc0,1000);
    lVar15 = gfa;
    if ((lVar7 == 0) || (gfa == -0x13f38)) goto LAB_0011f900;
    if ((*(long *)(gfa + 0x1a998) == 0) ||
       (__s = *(char **)(*(long *)(gfa + 0x1a998) + 0x38), __s == (char *)0x0)) goto LAB_0011f900;
    uVar1 = *(uint *)(gfa + 0x16d80);
    uVar14 = (ulong)uVar1;
    plVar11 = *(long **)(gfa + 0x1a990);
    uVar12 = *(uint *)(gfa + 0x16d84);
    uVar13 = (ulong)uVar12;
    while ((plVar11 != (long *)0x0 && (plVar11 != (long *)0x20))) {
      lVar17 = plVar11[2];
      plVar11 = (long *)*plVar11;
      if ((lVar17 != 0) && (*(int *)(lVar17 + 0xc0) == 3)) {
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\nfastrpc_file : %p\n",lVar17);
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,
                  "fl->tgid: %d, fl->cid: %d, fl->ssrcount: %p, fl->pd: %d, fl->profile: %p, fl->mode: %p, fl->tgid_open: %d, fl->num_cached_buf: %d, num_pers_hdrs: %d, fl->sessionid: %d, fl->servloc_name: %s, fl->file_close: %d, fl->dsp_proc_init: %d,fl->apps: %p, fl->qos_request: %d, fl->dev_minor: %d, fl->debug_buf: %s fl->debug_buf_alloced_attempted: %d, fl->wake_enable: %d, fl->ws_timeout: %d, fl->untrusted_process: %d\n"
                  ,*(undefined4 *)(lVar17 + 0xb8),*(undefined4 *)(lVar17 + 0xc0),
                  *(undefined8 *)(lVar17 + 200),*(undefined4 *)(lVar17 + 0xd0),
                  *(undefined4 *)(lVar17 + 0xac),*(undefined4 *)(lVar17 + 0xa8),
                  *(undefined4 *)(lVar17 + 0xb4),*(undefined4 *)(lVar17 + 0x28),
                  *(undefined4 *)(lVar17 + 0x7c),*(undefined4 *)(lVar17 + 0xb0),
                  *(undefined8 *)(lVar17 + 0xd8),*(undefined4 *)(lVar17 + 0xe0),
                  *(undefined4 *)(lVar17 + 0xe4),*(undefined8 *)(lVar17 + 0xf0),
                  *(undefined4 *)(lVar17 + 0x108),*(undefined4 *)(lVar17 + 0x170),
                  *(undefined8 *)(lVar17 + 0x178),*(undefined4 *)(lVar17 + 0x180),
                  *(undefined4 *)(lVar17 + 0x184),*(undefined4 *)(lVar17 + 0x1e8),
                  *(undefined1 *)(lVar17 + 0x1ec));
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\nSession Maps\n");
        uVar9 = _raw_spin_lock_irqsave(&DAT_001505c8);
        plVar10 = DAT_001505a8;
        if (DAT_001505a8 != (long *)0x0) {
          do {
            plVar11 = (long *)*plVar10;
            sVar8 = strlen(__s);
            scnprintf(__s + sVar8,0x32000 - sVar8,
                      "fd: %d, flags: %p, buf: %p, phys: %p, size : %d, va : %p, map->raddr: %p, len : %d, refs : %d, secure: %d\n"
                      ,(int)plVar10[4],*(undefined4 *)((long)plVar10 + 0x24),plVar10[5],plVar10[9],
                      plVar10[10],plVar10[0xb],plVar10[0xe],plVar10[0xc],(int)plVar10[0xd],
                      (int)plVar10[0xf]);
            plVar10 = plVar11;
          } while (plVar11 != (long *)0x0);
          plVar11 = (long *)0x0;
        }
        _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar9);
        mutex_lock(lVar17 + 0x110);
        plVar10 = *(long **)(lVar17 + 0x18);
        if (*(long **)(lVar17 + 0x18) != (long *)0x0) {
          do {
            plVar11 = (long *)*plVar10;
            sVar8 = strlen(__s);
            scnprintf(__s + sVar8,0x32000 - sVar8,
                      "fd: %d, flags: %p, buf: %p, phys: %p, size : %d, va : %p, map->raddr: %p, len : %d, refs : %d, secure: %d\n"
                      ,(int)plVar10[4],*(undefined4 *)((long)plVar10 + 0x24),plVar10[5],plVar10[9],
                      plVar10[10],plVar10[0xb],plVar10[0xe],plVar10[0xc],(int)plVar10[0xd],
                      (int)plVar10[0xf]);
            plVar10 = plVar11;
          } while (plVar11 != (long *)0x0);
          plVar11 = (long *)0x0;
        }
        mutex_unlock(lVar17 + 0x110);
        _raw_spin_lock(lVar17 + 0x10);
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\ncached_bufs\n");
        plVar10 = *(long **)(lVar17 + 0x20);
        if (*(long **)(lVar17 + 0x20) != (long *)0x0) {
          do {
            plVar11 = (long *)*plVar10;
            sVar8 = strlen(__s);
            scnprintf(__s + sVar8,0x32000 - sVar8,
                      "buf->fl: %p, buf->phys: %p, buf->virt: %p, buf->size: %d, buf->dma_attr: %ld, buf->raddr: %p, buf->flags: %d, buf->type: %d, buf->in_use: %d\n"
                      ,plVar10[6],plVar10[8],plVar10[7],plVar10[9],plVar10[10],plVar10[0xb],
                      (int)plVar10[0xc],*(undefined4 *)((long)plVar10 + 100),(char)plVar10[0xd]);
            plVar10 = plVar11;
          } while (plVar11 != (long *)0x0);
          plVar11 = (long *)0x0;
        }
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\ninit_mem: %p\n",*(undefined8 *)(lVar17 + 0x70));
        lVar16 = *(long *)(lVar17 + 0x70);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,
                    "buf->fl: %p, buf->phys: %p, buf->virt: %p, buf->size: %d, buf->dma_attr: %ld, buf->raddr: %p, buf->flags: %d, buf->type: %d, buf->in_use: %d\n"
                    ,*(undefined8 *)(lVar16 + 0x30),*(undefined8 *)(lVar16 + 0x40),
                    *(undefined8 *)(lVar16 + 0x38),*(undefined8 *)(lVar16 + 0x48),
                    *(undefined8 *)(lVar16 + 0x50),*(undefined8 *)(lVar16 + 0x58),
                    *(undefined4 *)(lVar16 + 0x60),*(undefined4 *)(lVar16 + 100),
                    *(undefined1 *)(lVar16 + 0x68));
        }
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\npers_hdr_buf: %p\n",*(undefined8 *)(lVar17 + 0x80))
        ;
        lVar16 = *(long *)(lVar17 + 0x80);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,
                    "buf->fl: %p, buf->phys: %p, buf->virt: %p, buf->size: %d, buf->dma_attr: %ld, buf->raddr: %p, buf->flags: %d, buf->type: %d, buf->in_use: %d\n"
                    ,*(undefined8 *)(lVar16 + 0x30),*(undefined8 *)(lVar16 + 0x40),
                    *(undefined8 *)(lVar16 + 0x38),*(undefined8 *)(lVar16 + 0x48),
                    *(undefined8 *)(lVar16 + 0x50),*(undefined8 *)(lVar16 + 0x58),
                    *(undefined4 *)(lVar16 + 0x60),*(undefined4 *)(lVar16 + 100),
                    *(undefined1 *)(lVar16 + 0x68));
        }
        sVar8 = strlen(__s);
        snprintf(__s + sVar8,0x32000 - sVar8,"\nhdr_bufs: %p\n",*(void **)(lVar17 + 0x88));
        lVar16 = *(long *)(lVar17 + 0x88);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,
                    "buf->fl: %p, buf->phys: %p, buf->virt: %p, buf->size: %d, buf->dma_attr: %ld, buf->raddr: %p, buf->flags: %d, buf->type: %d, buf->in_use: %d\n"
                    ,*(undefined8 *)(lVar16 + 0x30),*(undefined8 *)(lVar16 + 0x40),
                    *(undefined8 *)(lVar16 + 0x38),*(undefined8 *)(lVar16 + 0x48),
                    *(undefined8 *)(lVar16 + 0x50),*(undefined8 *)(lVar16 + 0x58),
                    *(undefined4 *)(lVar16 + 0x60),*(undefined4 *)(lVar16 + 100),
                    *(undefined1 *)(lVar16 + 0x68));
        }
        lVar16 = *(long *)(lVar17 + 0xf8);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,"\nfl->debugfs_file.d_iname : %s\n",lVar16 + 0x38);
        }
        lVar16 = *(long *)(lVar17 + 0x68);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,"\nfl->sctx->smmu.cb : %d\n",
                    *(undefined4 *)(lVar16 + 0x18));
        }
        lVar16 = *(long *)(lVar17 + 0xa0);
        if (lVar16 != 0) {
          sVar8 = strlen(__s);
          scnprintf(__s + sVar8,0x32000 - sVar8,"\nfl->secsctx->smmu.cb : %d\n",
                    *(undefined4 *)(lVar16 + 0x18));
        }
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\nPending Ctx:\n");
        plVar10 = *(long **)(lVar17 + 0x38);
        if (*(long **)(lVar17 + 0x38) != (long *)0x0) {
          do {
            plVar11 = (long *)*plVar10;
            fastrpc_smq_ctx_detail(plVar10,__s);
            plVar10 = plVar11;
          } while (plVar11 != (long *)0x0);
          plVar11 = (long *)0x0;
        }
        sVar8 = strlen(__s);
        scnprintf(__s + sVar8,0x32000 - sVar8,"\nInterrupted Ctx:\n");
        plVar10 = *(long **)(lVar17 + 0x40);
        if (*(long **)(lVar17 + 0x40) != (long *)0x0) {
          do {
            plVar11 = (long *)*plVar10;
            fastrpc_smq_ctx_detail(plVar10,__s);
            plVar10 = plVar11;
          } while (plVar11 != (long *)0x0);
          plVar11 = (long *)0x0;
        }
        _raw_spin_unlock(lVar17 + 0x10);
      }
    }
    uVar9 = _raw_spin_lock_irqsave(lVar15 + 0x1a988);
    if (uVar12 != 0) {
      uVar5 = uVar12 - 1;
      if (2 < uVar5) {
        uVar5 = 3;
      }
      if (0x7f < uVar12) goto LAB_0011f934;
      lVar17 = lVar15 + uVar13 * 0x28;
      uVar3 = scnprintf(lVar7,1000,
                        "ctx: 0x%x, retval: %d, flags: %d, early_wake_time: %d, version: %d\n",
                        *(undefined8 *)(lVar17 + 0x19588),*(undefined4 *)(lVar17 + 0x19590),
                        *(undefined4 *)(lVar17 + 0x19594),*(undefined4 *)(lVar17 + 0x19598),
                        *(undefined4 *)(lVar17 + 0x1959c));
      if (uVar5 != 0) {
        if (0x80 < uVar12) goto LAB_0011f934;
        lVar17 = lVar15 + (uVar13 - 1) * 0x28;
        iVar4 = scnprintf(lVar7 + (ulong)uVar3,1000 - uVar3,
                          "ctx: 0x%x, retval: %d, flags: %d, early_wake_time: %d, version: %d\n",
                          *(undefined8 *)(lVar17 + 0x19588),*(undefined4 *)(lVar17 + 0x19590),
                          *(undefined4 *)(lVar17 + 0x19594),*(undefined4 *)(lVar17 + 0x19598),
                          *(undefined4 *)(lVar17 + 0x1959c));
        if (uVar5 != 1) {
          if (0x7f < uVar13 - 2) goto LAB_0011f934;
          uVar3 = iVar4 + uVar3;
          lVar17 = lVar15 + (uVar13 - 2) * 0x28;
          iVar4 = scnprintf(lVar7 + (ulong)uVar3,1000 - uVar3,
                            "ctx: 0x%x, retval: %d, flags: %d, early_wake_time: %d, version: %d\n",
                            *(undefined8 *)(lVar17 + 0x19588),*(undefined4 *)(lVar17 + 0x19590),
                            *(undefined4 *)(lVar17 + 0x19594),*(undefined4 *)(lVar17 + 0x19598),
                            *(undefined4 *)(lVar17 + 0x1959c));
          if (uVar5 != 2) {
            if (0x7f < uVar13 - 3) goto LAB_0011f934;
            lVar17 = lVar15 + (uVar13 - 3) * 0x28;
            scnprintf(lVar7 + (ulong)(iVar4 + uVar3),1000 - (iVar4 + uVar3),
                      "ctx: 0x%x, retval: %d, flags: %d, early_wake_time: %d, version: %d\n",
                      *(undefined8 *)(lVar17 + 0x19588),*(undefined4 *)(lVar17 + 0x19590),
                      *(undefined4 *)(lVar17 + 0x19594),*(undefined4 *)(lVar17 + 0x19598),
                      *(undefined4 *)(lVar17 + 0x1959c));
          }
        }
      }
    }
    if (uVar1 != 0) {
      uVar12 = uVar1 - 1;
      if (2 < uVar12) {
        uVar12 = 3;
      }
      if (0x80 < uVar1) {
LAB_0011f934:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11f938);
        (*pcVar2)();
      }
      lVar17 = lVar15 + uVar14 * 0x50;
      uVar5 = scnprintf(lVar6,1000,
                        "pid: %d, tid: %d, ctx: 0x%x, handle: 0x%x, sc: 0x%x, addr: 0x%x, size:%d\n"
                        ,*(undefined4 *)(lVar17 + 0x16d88),*(undefined4 *)(lVar17 + 0x16d8c),
                        *(undefined8 *)(lVar17 + 0x16d90),*(undefined4 *)(lVar17 + 0x16d98),
                        *(undefined4 *)(lVar17 + 0x16d9c),*(undefined8 *)(lVar17 + 0x16da0),
                        *(undefined8 *)(lVar17 + 0x16da8));
      if (uVar12 != 0) {
        if (0x81 < uVar1) goto LAB_0011f934;
        lVar17 = lVar15 + (uVar14 - 1) * 0x50;
        iVar4 = scnprintf(lVar6 + (ulong)uVar5,1000 - uVar5,
                          "pid: %d, tid: %d, ctx: 0x%x, handle: 0x%x, sc: 0x%x, addr: 0x%x, size:%d\n"
                          ,*(undefined4 *)(lVar17 + 0x16d88),*(undefined4 *)(lVar17 + 0x16d8c),
                          *(undefined8 *)(lVar17 + 0x16d90),*(undefined4 *)(lVar17 + 0x16d98),
                          *(undefined4 *)(lVar17 + 0x16d9c),*(undefined8 *)(lVar17 + 0x16da0),
                          *(undefined8 *)(lVar17 + 0x16da8));
        if (uVar12 != 1) {
          if (0x80 < uVar14 - 2) goto LAB_0011f934;
          uVar5 = iVar4 + uVar5;
          lVar17 = lVar15 + (uVar14 - 2) * 0x50;
          iVar4 = scnprintf(lVar6 + (ulong)uVar5,1000 - uVar5,
                            "pid: %d, tid: %d, ctx: 0x%x, handle: 0x%x, sc: 0x%x, addr: 0x%x, size:%d\n"
                            ,*(undefined4 *)(lVar17 + 0x16d88),*(undefined4 *)(lVar17 + 0x16d8c),
                            *(undefined8 *)(lVar17 + 0x16d90),*(undefined4 *)(lVar17 + 0x16d98),
                            *(undefined4 *)(lVar17 + 0x16d9c),*(undefined8 *)(lVar17 + 0x16da0),
                            *(undefined8 *)(lVar17 + 0x16da8));
          if (uVar12 != 2) {
            if (0x80 < uVar14 - 3) goto LAB_0011f934;
            lVar17 = lVar15 + (uVar14 - 3) * 0x50;
            scnprintf(lVar6 + (ulong)(iVar4 + uVar5),1000 - (iVar4 + uVar5),
                      "pid: %d, tid: %d, ctx: 0x%x, handle: 0x%x, sc: 0x%x, addr: 0x%x, size:%d\n",
                      *(undefined4 *)(lVar17 + 0x16d88),*(undefined4 *)(lVar17 + 0x16d8c),
                      *(undefined8 *)(lVar17 + 0x16d90),*(undefined4 *)(lVar17 + 0x16d98),
                      *(undefined4 *)(lVar17 + 0x16d9c),*(undefined8 *)(lVar17 + 0x16da0),
                      *(undefined8 *)(lVar17 + 0x16da8));
          }
        }
      }
    }
    _raw_spin_unlock_irqrestore(lVar15 + 0x1a988,uVar9);
    sVar8 = strlen(__s);
    scnprintf(__s + sVar8,0x32000 - sVar8,"gmsg_log_tx:\n%s\n",lVar6);
    sVar8 = strlen(__s);
    scnprintf(__s + sVar8,0x32000 - sVar8,"gmsg_log_rx:\n %s\n",lVar7);
    lVar15 = *(long *)(lVar15 + 0x1a998);
    if (lVar15 != 0) {
      sVar8 = strlen(__s);
      *(size_t *)(lVar15 + 0x48) = sVar8;
    }
  }
LAB_0011f900:
  kfree(lVar6);
  kfree(lVar7);
  return;
}



//------------------------------------------------------------
// fastrpc_ramdump_collection @ 0011f938 size=408
// signature: undefined fastrpc_ramdump_collection(void)
// callers: [fastrpc_restart_notifier_cb]
//------------------------------------------------------------

void fastrpc_ramdump_collection(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  undefined1 **local_a0;
  undefined1 **local_98;
  undefined1 *local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = (undefined1 *)0x0;
  local_80 = 0;
  local_90 = (undefined1 *)0x0;
  lVar6 = *(long *)(gfa + 0x1a990) + -0x20;
  if (*(long *)(gfa + 0x1a990) != 0 && lVar6 != 0) {
    iVar2 = 0;
    lVar1 = sp_el0;
    do {
      local_90 = (undefined1 *)0x0;
      local_88 = (undefined1 *)0x0;
      plVar9 = (long *)(lVar6 + 0x20);
      lVar8 = *plVar9;
      local_78 = *(undefined8 *)(lVar6 + 0x38);
      local_80 = *(undefined8 *)(lVar6 + 0x40);
      local_70 = *(undefined8 *)(lVar6 + 0x48);
      lVar7 = *(long *)(lVar6 + 0x30);
      local_a0 = (undefined1 **)&local_a0;
      local_98 = (undefined1 **)&local_a0;
      uVar3 = __list_add_valid(&local_90,&local_a0,&local_a0);
      if ((uVar3 & 1) != 0) {
        local_a0 = &local_90;
        local_98 = &local_90;
        local_90 = (undefined1 *)&local_a0;
        local_88 = (undefined1 *)&local_a0;
      }
      if ((((lVar7 != 0) && (*(long *)(lVar7 + 0x68) != 0)) &&
          (lVar4 = *(long *)(*(long *)(lVar7 + 0x68) + 8), lVar4 != 0)) ||
         (lVar4 = DAT_001505d0, DAT_001505d0 != 0)) {
        iVar2 = qcom_elf_dump(&local_a0,lVar4,2);
      }
      if (iVar2 < 0) {
        _printk(&DAT_0014d997,0x917,lVar1 + 0x848,"fastrpc_ramdump_collection",
                "fastrpc_ramdump_collection",iVar2);
        plVar5 = *(long **)(lVar6 + 0x28);
      }
      else {
        plVar5 = *(long **)(lVar6 + 0x28);
      }
      if (plVar5 != (long *)0x0) {
        lVar4 = *plVar9;
        *plVar5 = lVar4;
        if (lVar4 != 0) {
          *(long **)(lVar4 + 8) = plVar5;
        }
        *plVar9 = 0;
        *(undefined8 *)(lVar6 + 0x28) = 0;
      }
      if (lVar7 != 0) {
        fastrpc_file_put(lVar7);
      }
    } while ((lVar8 != 0) && (lVar6 = lVar8 + -0x20, lVar6 != 0));
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_smq_ctx_detail @ 0011fad0 size=260
// signature: undefined fastrpc_smq_ctx_detail(void)
// callers: [fastrpc_print_debug_data]
//------------------------------------------------------------

void fastrpc_smq_ctx_detail(long param_1,char *param_2)

{
  uint uVar1;
  size_t sVar2;
  long lVar3;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulong)in_stack_ffffffffffffff98 >> 0x20);
  if (((*(long *)(param_1 + 0x80) != 0) && (*(long *)(*(long *)(param_1 + 0x80) + 0x38) != 0)) &&
     (uVar1 = *(uint *)(param_1 + 0xa4), (uVar1 >> 8 & 0xff) + (uVar1 >> 0x10 & 0xff) != 0)) {
    lVar3 = **(long **)(param_1 + 0x78);
    sVar2 = strlen(param_2);
    scnprintf(param_2 + sVar2,0x32000 - sVar2,
              "pid: %d, tgid: %d, handle: %d, sc: 0x%x, fl: %p, fd: %p, magic: %d\n",
              *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
              *(undefined4 *)(param_1 + 0xa0),uVar1,*(undefined8 *)(param_1 + 0x98),
              *(undefined8 *)(param_1 + 0x68),CONCAT44(uVar4,*(undefined4 *)(param_1 + 0xf8)));
    if (lVar3 != 0) {
      sVar2 = strlen(param_2);
      scnprintf(param_2 + sVar2,0x32000 - sVar2,
                "fd: %d, flags: %p, buf: %p, phys: %p, size : %d, va : %p, map->raddr: %p, len : %d, refs : %d, secure: %d\n"
                ,*(undefined4 *)(lVar3 + 0x20),*(undefined4 *)(lVar3 + 0x24),
                *(undefined8 *)(lVar3 + 0x28),*(undefined8 *)(lVar3 + 0x48),
                *(undefined8 *)(lVar3 + 0x50),*(undefined8 *)(lVar3 + 0x58),
                *(undefined8 *)(lVar3 + 0x70),*(undefined8 *)(lVar3 + 0x60),
                *(undefined4 *)(lVar3 + 0x68),*(undefined4 *)(lVar3 + 0x78));
    }
  }
  return;
}



//------------------------------------------------------------
// fastrpc_hibernation_notifier @ 0011fbd8 size=8
// signature: undefined fastrpc_hibernation_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_hibernation_notifier(void)

{
  return 1;
}



//------------------------------------------------------------
// compat_fastrpc_device_ioctl @ 00120404 size=7864
// signature: undefined compat_fastrpc_device_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00121cd4) */
/* WARNING: Removing unreachable block (ram,0x00121ea4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long compat_fastrpc_device_ioctl(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  long lVar9;
  int *piVar10;
  undefined4 *puVar11;
  
  if ((*(long *)(param_1 + 0x28) == 0) || (*(long *)(*(long *)(param_1 + 0x28) + 0x50) == 0)) {
    return -0x19;
  }
  lVar8 = *(long *)(param_1 + 0xd8);
  lVar9 = -0x19;
  if (param_2 < -0x3fefadfc) {
    if (param_2 < -0x3ff7adfd) {
      switch(param_2) {
      case -0x3ffbadfb:
        iVar6 = fastrpc_setmode(param_3,lVar8);
        goto LAB_00121d08;
      case -0x3ffbadf8:
        puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,4);
        if (puVar7 == (undefined4 *)0x0) {
          return -0xe;
        }
        uVar3 = sp_el0;
        uaccess_ttbr0_enable();
        uVar2 = *(undefined4 *)(param_3 & 0xffffffff);
        uaccess_ttbr0_disable();
        *puVar7 = uVar2;
        iVar6 = fastrpc_get_info(lVar8,puVar7);
        uVar2 = *puVar7;
        uaccess_ttbr0_enable();
        *(undefined4 *)(param_3 & 0xffffffff) = uVar2;
        uaccess_ttbr0_disable();
        goto LAB_00121f44;
      case -0x3ffbade8:
        lVar9 = compat_fastrpc_dspsignal_destroy(lVar8,param_3);
        break;
      case -0x3ffbade7:
        lVar9 = compat_fastrpc_dspsignal_signal(lVar8,param_3);
        break;
      case -0x3ffbade5:
        lVar9 = compat_fastrpc_dspsignal_cancel_wait(lVar8,param_3);
      }
      goto switchD_00120594_caseD_c0045206;
    }
    if (param_2 < -0x3ff3adff) {
      if (param_2 != -0x3ff7adfd) {
        if (param_2 == -0x3ff7ade9) {
          lVar9 = compat_fastrpc_dspsignal_create(lVar8,param_3);
        }
        else {
          if (param_2 != -0x3ff7ade6) {
            return -0x19;
          }
          lVar9 = compat_fastrpc_dspsignal_wait(lVar8,param_3);
        }
        goto switchD_00120594_caseD_c0045206;
      }
      puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x10);
      if (puVar7 == (undefined4 *)0x0) {
        return -0xe;
      }
      lVar9 = sp_el0;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      *puVar7 = *(undefined4 *)(param_3 & 0xffffffff);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[2] = ((undefined4 *)(param_3 & 0xffffffff))[1];
LAB_00121ecc:
      iVar6 = fastrpc_internal_munmap(lVar8,puVar7);
      goto LAB_00121f44;
    }
    if (param_2 == -0x3ff3adff) goto LAB_00120b38;
    if (param_2 == -0x3ff3adf4) {
      iVar6 = compat_fastrpc_control(lVar8,param_3);
    }
    else {
      if (param_2 != -0x3ff3adef) {
        return -0x19;
      }
      iVar6 = compat_fastrpc_get_dsp_info(lVar8,param_3);
    }
  }
  else {
    if (-0x3fe3adfb < param_2) {
      if (param_2 < -0x3fdbadf6) {
        if (param_2 != -0x3fe3adfa) {
          if (param_2 != -0x3fdfadf2) {
            iVar6 = -0x3fdfadeb;
            goto LAB_001205d0;
          }
          puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x20);
          if (puVar7 == (undefined4 *)0x0) {
            return -0xe;
          }
          lVar9 = sp_el0;
          puVar11 = (undefined4 *)(param_3 & 0xffffffff);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          *puVar7 = *puVar11;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[1] = puVar11[1];
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          *(undefined8 *)(puVar7 + 2) = *(undefined8 *)(puVar11 + 2);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[4] = puVar11[4];
          iVar6 = fastrpc_internal_mmap(lVar8,puVar7);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          *(undefined8 *)(puVar11 + 6) = *(undefined8 *)(puVar7 + 6);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          goto LAB_00121cc8;
        }
      }
      else if (param_2 != -0x3fdbadf6) {
        if (param_2 != -0x3fcfadec) {
          if (param_2 != -0x3fbfaded) {
            return -0x19;
          }
          puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x40);
          if (puVar7 == (undefined4 *)0x0) {
            return -0xe;
          }
          lVar9 = sp_el0;
          piVar10 = (int *)(param_3 & 0xffffffff);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (*piVar10 != 0) {
            kfree(puVar7);
            return -0x16;
          }
          *puVar7 = 0;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[2] = piVar10[2];
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[3] = piVar10[3];
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[4] = piVar10[4];
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[6] = 0;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[8] = piVar10[7];
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar9 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          puVar7[5] = piVar10[5];
          iVar6 = fastrpc_internal_mem_map(lVar8,puVar7);
          if (iVar6 != 0) goto LAB_00121f44;
          iVar6 = compat_put_fastrpc_ioctl_mem_map(piVar10,puVar7);
          lVar9 = -(ulong)(iVar6 != 0);
          goto LAB_00121cdc;
        }
        puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x30);
        if (puVar7 == (undefined4 *)0x0) {
          return -0xe;
        }
        lVar9 = sp_el0;
        piVar10 = (int *)(param_3 & 0xffffffff);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (*piVar10 != 0) {
          kfree(puVar7);
          return -0x16;
        }
        *puVar7 = 0;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        puVar7[2] = piVar10[2];
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        *(undefined8 *)(puVar7 + 4) = *(undefined8 *)(piVar10 + 4);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        puVar7[6] = piVar10[6];
        iVar6 = fastrpc_internal_mem_unmap(lVar8,puVar7);
        goto LAB_00121f44;
      }
      puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x30);
      if (puVar7 == (undefined4 *)0x0) {
        return -0xe;
      }
      lVar9 = sp_el0;
      puVar11 = (undefined4 *)(param_3 & 0xffffffff);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      *puVar7 = *puVar11;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[2] = puVar11[1];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[4] = puVar11[2];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[5] = puVar11[3];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[6] = puVar11[4];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[8] = puVar11[5];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[9] = puVar11[6];
      puVar7[10] = 0;
      if (param_2 == -0x3fdbadf6) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        puVar7[10] = puVar11[7];
        puVar7[0xb] = 0;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        puVar7[0xb] = puVar11[8];
      }
      else {
        puVar7[0xb] = 0;
      }
      iVar6 = fastrpc_init_process(lVar8,puVar7);
LAB_00121f44:
      kfree(puVar7);
      return (long)iVar6;
    }
    if (-0x3febadff < param_2) {
      if (param_2 != -0x3febadfe) {
        if (param_2 == -0x3febadf9) goto LAB_00120b38;
        iVar6 = -0x3fe7adf5;
LAB_001205d0:
        if (param_2 != iVar6) {
          return -0x19;
        }
LAB_00120b38:
        lVar9 = sp_el0;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = *(ulong *)(lVar9 + 8);
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        uVar1 = *(uint *)((param_3 & 0xffffffff) + 4);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar4 = daif;
          if ((uVar4 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar4;
        }
        lVar9 = __kmalloc((uVar1 & 0xf0) +
                          ((uVar1 & 0xf) + (uVar1 >> 8 & 0xff) + (uVar1 >> 0x10 & 0xff)) * 0x10 +
                          0x40,0xdc0);
        if (lVar9 == 0) {
          return -0xe;
        }
        iVar6 = compat_get_fastrpc_ioctl_invoke(param_3 & 0xffffffff,lVar9,param_2,uVar1);
        if (iVar6 == 0) {
          iVar6 = fastrpc_internal_invoke(lVar8,*(undefined4 *)(lVar8 + 0xa8),3,lVar9);
        }
        else {
          iVar6 = -1;
        }
        kfree(lVar9);
        return (long)iVar6;
      }
      puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x20);
      if (puVar7 == (undefined4 *)0x0) {
        return -0xe;
      }
      lVar9 = sp_el0;
      puVar11 = (undefined4 *)(param_3 & 0xffffffff);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      *puVar7 = *puVar11;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[1] = puVar11[1];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[2] = puVar11[2];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar7[4] = puVar11[3];
      iVar6 = fastrpc_internal_mmap(lVar8,puVar7);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar9 + 8) & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar9 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      puVar11[4] = puVar7[6];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
LAB_00121cc8:
      lVar9 = (long)iVar6;
LAB_00121cdc:
      kfree(puVar7);
      return lVar9;
    }
    if (param_2 == -0x3fefadfc) goto LAB_00120b38;
    if (param_2 == -0x3fefadf1) {
      puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x10);
      if (puVar7 == (undefined4 *)0x0) {
        return -0xe;
      }
      iVar6 = compat_get_fastrpc_ioctl_munmap_64(param_3 & 0xffffffff,puVar7);
      if (iVar6 != 0) {
        kfree(puVar7);
        return -1;
      }
      goto LAB_00121ecc;
    }
    if (param_2 != -0x3fefadee) {
      return -0x19;
    }
    iVar6 = compat_fastrpc_ioctl_invoke2(param_1,param_3);
  }
LAB_00121d08:
  lVar9 = (long)iVar6;
switchD_00120594_caseD_c0045206:
  return lVar9;
}



//------------------------------------------------------------
// compat_fastrpc_ioctl_invoke2 @ 001225d4 size=1316
// signature: undefined compat_fastrpc_ioctl_invoke2(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 compat_fastrpc_ioctl_invoke2(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined8 uVar10;
  ulong uVar11;
  uint uVar12;
  
  lVar2 = sp_el0;
  uVar10 = *(undefined8 *)(param_1 + 0xd8);
  puVar8 = (undefined4 *)(param_2 & 0xffffffff);
  uVar9 = (uint)_cpu_hwcaps;
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar2 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar2 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  uVar6 = *puVar8;
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar2 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar2 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  uVar1 = puVar8[1];
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar2 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar2 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  uVar12 = puVar8[2];
  if ((uVar9 >> 0x1d & 1) == 0) {
    uVar11 = daif;
    if ((uVar11 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar11;
  }
  switch(uVar6) {
  case 1:
    if (uVar12 < 0x25) {
      uVar11 = (ulong)uVar1;
      if ((uVar9 >> 0x1d & 1) == 0) {
        uVar3 = daif;
        if ((uVar3 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar2 + 8) & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar2 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar3;
      }
      uVar1 = *(uint *)(uVar11 + 4);
      if ((uVar9 >> 0x1d & 1) == 0) {
        uVar3 = daif;
        if ((uVar3 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar3;
      }
      puVar8 = (undefined4 *)
               __kmalloc((uVar1 & 0xf0) +
                         ((uVar1 & 0xf) + (uVar1 >> 8 & 0xff) + (uVar1 >> 0x10 & 0xff)) * 0x10 +
                         0x58,0xdc0);
      if (puVar8 != (undefined4 *)0x0) {
        puVar7 = puVar8 + 6;
        if (uVar12 < 0x24) {
          iVar5 = compat_get_fastrpc_ioctl_invoke(uVar11,puVar7,0xc018520b,uVar1);
          if (iVar5 != 0) goto LAB_001227e8;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar3 = daif;
            if ((uVar3 & 0x80) == 0) {
              uVar4 = daif;
              daif = uVar4 | 0xc0;
            }
            uVar4 = ttbr1_el1;
            ttbr1_el1 = *(ulong *)(lVar2 + 8) & 0xffff000000000000 | uVar4 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = *(ulong *)(lVar2 + 8);
            InstructionSynchronizationBarrier();
            daif = uVar3;
          }
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar3 = daif;
            if ((uVar3 & 0x80) == 0) {
              uVar4 = daif;
              daif = uVar4 | 0xc0;
            }
            uVar4 = ttbr1_el1;
            ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar4 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar3;
          }
          puVar8[0x14] = *(undefined4 *)(uVar11 + 0x18);
        }
        else {
          iVar5 = compat_get_fastrpc_ioctl_invoke(uVar11,puVar7,1,uVar1);
          if (iVar5 != 0) goto LAB_001227e8;
        }
        uVar12 = 0x40;
        *(undefined4 **)(puVar8 + 2) = puVar7;
        *puVar8 = 1;
        goto LAB_00122a30;
      }
      goto LAB_001227e8;
    }
    break;
  case 2:
    if (uVar12 < 0x21) {
LAB_00122a0c:
      puVar7 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x18);
      puVar8 = (undefined4 *)0x0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = uVar6;
        puVar7[2] = uVar1;
        puVar8 = puVar7;
LAB_00122a30:
        puVar8[4] = uVar12;
        uVar6 = fastrpc_internal_invoke2(uVar10,puVar8,1);
        kfree(puVar8);
        return uVar6;
      }
      goto LAB_001227e8;
    }
    break;
  case 3:
    if (uVar12 == 4) goto LAB_00122a0c;
    break;
  case 4:
    if (uVar12 == 0xc) goto LAB_00122a0c;
  }
  puVar8 = (undefined4 *)0x0;
LAB_001227e8:
  kfree(puVar8);
  return 0xffffffff;
}



//------------------------------------------------------------
// compat_get_fastrpc_ioctl_munmap_64 @ 00122b70 size=460
// signature: undefined compat_get_fastrpc_ioctl_munmap_64(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint compat_get_fastrpc_ioctl_munmap_64(ulong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  puVar1 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_1, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar7 = param_1 & (long)(param_1 << 8) >> 8;
  }
  uVar6 = 0;
  uVar3 = 0xfffffff2;
  if (uVar7 < 0x7ffffffff9) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar3 = 0;
    uVar6 = *(undefined8 *)(param_1 & 0xff7fffffffffffff);
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
  *param_2 = uVar6;
  param_1 = param_1 + 8;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_1, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar7 = param_1 & (long)(param_1 * 0x100) >> 8;
  }
  uVar5 = 0;
  uVar4 = 0xfffffff2;
  if (uVar7 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar4 = 0;
    uVar5 = *(undefined4 *)(param_1 & 0xff7fffffffffffff);
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
  *(undefined4 *)(param_2 + 1) = uVar5;
  return uVar4 | uVar3;
}



//------------------------------------------------------------
// uaccess_ttbr0_enable @ 00122d6c size=72
// signature: undefined uaccess_ttbr0_enable(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_enable(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// FUN_00122db8 @ 00122db8 size=16
// signature: undefined FUN_00122db8(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00122db8(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// uaccess_ttbr0_disable @ 00122dd0 size=64
// signature: undefined uaccess_ttbr0_disable(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_disable(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// FUN_00122e14 @ 00122e14 size=16
// signature: undefined FUN_00122e14(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00122e14(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// compat_fastrpc_control @ 00122e2c size=1520
// signature: undefined compat_fastrpc_control(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int compat_fastrpc_control(undefined8 param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  
  piVar5 = (int *)kmalloc_trace(___arch_copy_to_user,0xdc0,0xc);
  if (piVar5 == (int *)0x0) {
    return -0xe;
  }
  lVar1 = sp_el0;
  piVar7 = (int *)(param_2 & 0xffffffff);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  iVar4 = *piVar7;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  *piVar5 = iVar4;
  uVar6 = (uint)_cpu_hwcaps;
  switch(iVar4) {
  case 1:
  case 7:
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    piVar5[1] = piVar7[1];
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    piVar5[2] = piVar7[2];
  default:
    goto LAB_001231ec;
  case 4:
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    iVar4 = piVar7[1];
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    break;
  case 5:
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    iVar4 = piVar7[1];
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
  }
  piVar5[1] = iVar4;
LAB_001231ec:
  iVar4 = fastrpc_internal_control(param_1,piVar5);
  if (iVar4 == 0) {
    uVar6 = (uint)_cpu_hwcaps;
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    iVar4 = 0;
    if ((uVar6 >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    if (*piVar7 == 3) {
      if ((uVar6 >> 0x1d & 1) == 0) {
        uVar2 = daif;
        if ((uVar2 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar1 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar2;
      }
      iVar4 = 0;
      piVar7[1] = piVar5[1];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar2 = daif;
        if ((uVar2 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar2;
      }
    }
  }
  kfree(piVar5);
  return iVar4;
}



//------------------------------------------------------------
// compat_fastrpc_get_dsp_info @ 001234c4 size=732
// signature: undefined compat_fastrpc_get_dsp_info(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int compat_fastrpc_get_dsp_info(undefined8 param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)kmalloc_trace(___arch_copy_to_user,0xdc0,0xc);
  lVar1 = sp_el0;
  if (puVar5 == (undefined4 *)0x0) {
    _printk(&DAT_0014dd9f,0x30d,lVar1 + 0x848,"compat_fastrpc_get_dsp_info",0xc);
    iVar4 = -1;
  }
  else {
    puVar6 = (undefined4 *)(param_2 & 0xffffffff);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    *puVar5 = *puVar6;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = *(ulong *)(lVar1 + 8);
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar2 = daif;
      if ((uVar2 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar2;
    }
    puVar5[1] = puVar6[1];
    iVar4 = fastrpc_get_info_from_kernel(puVar5,param_1);
    if (iVar4 == 0) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar2 = daif;
        if ((uVar2 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = *(ulong *)(lVar1 + 8);
        InstructionSynchronizationBarrier();
        daif = uVar2;
      }
      iVar4 = 0;
      puVar6[2] = puVar5[2];
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar2 = daif;
        if ((uVar2 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar2;
      }
    }
    kfree(puVar5);
  }
  return iVar4;
}



//------------------------------------------------------------
// compat_fastrpc_dspsignal_create @ 001237e8 size=336
// signature: undefined compat_fastrpc_dspsignal_create(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void compat_fastrpc_dspsignal_create(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined8 local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = sp_el0;
  local_30 = 0;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar5 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar5 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  __n = __arch_copy_from_user(&local_30,param_2,8);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  if ((__n == 0) || (memset((void *)((long)&local_28 - __n),0,__n), (int)__n == 0)) {
    iVar4 = fastrpc_dspsignal_create(param_1,&local_30);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = -0xe;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// compat_fastrpc_dspsignal_destroy @ 00123950 size=336
// signature: undefined compat_fastrpc_dspsignal_destroy(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void compat_fastrpc_dspsignal_destroy(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = sp_el0;
  local_30 = 0;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar5 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar5 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  __n = __arch_copy_from_user(&local_30,param_2,4);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  if ((__n == 0) || (memset(auStack_2c + -__n,0,__n), (int)__n == 0)) {
    iVar4 = fastrpc_dspsignal_destroy(param_1,&local_30);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = -0xe;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// compat_fastrpc_dspsignal_signal @ 00123ab8 size=336
// signature: undefined compat_fastrpc_dspsignal_signal(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void compat_fastrpc_dspsignal_signal(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = sp_el0;
  local_30 = 0;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar5 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar5 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  __n = __arch_copy_from_user(&local_30,param_2,4);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  if ((__n == 0) || (memset(auStack_2c + -__n,0,__n), (int)__n == 0)) {
    iVar4 = fastrpc_dspsignal_signal(param_1,&local_30);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = -0xe;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// compat_fastrpc_dspsignal_wait @ 00123c20 size=336
// signature: undefined compat_fastrpc_dspsignal_wait(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void compat_fastrpc_dspsignal_wait(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined8 local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = sp_el0;
  local_30 = 0;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar5 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar5 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  __n = __arch_copy_from_user(&local_30,param_2,8);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  if ((__n == 0) || (memset((void *)((long)&local_28 - __n),0,__n), (int)__n == 0)) {
    iVar4 = fastrpc_dspsignal_wait(param_1,&local_30);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = -0xe;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// compat_fastrpc_dspsignal_cancel_wait @ 00123d88 size=336
// signature: undefined compat_fastrpc_dspsignal_cancel_wait(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void compat_fastrpc_dspsignal_cancel_wait(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = sp_el0;
  local_30 = 0;
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar5 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar5 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  __n = __arch_copy_from_user(&local_30,param_2,4);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  if ((__n == 0) || (memset(auStack_2c + -__n,0,__n), (int)__n == 0)) {
    iVar4 = fastrpc_dspsignal_cancel_wait(param_1,&local_30);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = -0xe;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// compat_get_fastrpc_ioctl_invoke @ 00123ef0 size=2404
// signature: undefined compat_get_fastrpc_ioctl_invoke(void)
// callers: [compat_fastrpc_device_ioctl, compat_fastrpc_ioctl_invoke2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint compat_get_fastrpc_ioctl_invoke
               (ulong param_1,undefined4 *param_2,int param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined4 uVar7;
  ulong uVar8;
  uint uVar9;
  undefined4 uVar10;
  ulong uVar11;
  undefined4 *puVar12;
  uint uVar13;
  ulong uVar14;
  
  uVar3 = (uint)param_4;
  *(undefined4 **)(param_2 + 2) = param_2 + 0x10;
  param_2[1] = uVar3;
  puVar1 = (undefined8 *)sp_el0;
  uVar3 = (uVar3 & 0xf) + ((uint)((ulong)param_4 >> 8) & 0xff) + (uVar3 >> 0x10 & 0xff) +
          (uVar3 >> 4 & 0xf);
  uVar6 = (ulong)uVar3;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar11 = param_1, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar11 = param_1 & (long)(param_1 << 8) >> 8;
  }
  uVar7 = 0;
  uVar4 = 0xfffffff2;
  if (uVar11 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
    uVar4 = 0;
    uVar7 = *(undefined4 *)(param_1 & 0xff7fffffffffffff);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
  }
  *param_2 = uVar7;
  uVar11 = param_1 + 8;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar14 = uVar11, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar14 = uVar11 & (long)(uVar11 * 0x100) >> 8;
  }
  uVar8 = 0;
  uVar9 = 0xfffffff2;
  if (uVar14 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar8 = daif;
        daif = uVar8 | 0xc0;
      }
      uVar8 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    uVar9 = 0;
    uVar8 = (ulong)*(uint *)(uVar11 & 0xff7fffffffffffff);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
  }
  if ((uVar9 | uVar4) != 0) {
    return uVar9 | uVar4;
  }
  if (uVar3 != 0) {
    puVar12 = param_2 + 0x12;
    do {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        uVar14 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        uVar14 = ttbr1_el1;
        ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      puVar12[-2] = *(undefined4 *)(uVar8 & 0xff7fffffffffffff);
      uVar11 = uVar8 + 4;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      uVar8 = uVar8 + 8;
      uVar6 = uVar6 - 1;
      *puVar12 = *(undefined4 *)(uVar11 & 0xff7fffffffffffff);
      puVar12 = puVar12 + 4;
    } while (uVar6 != 0);
  }
  if (param_3 == -0x3ff3adff) {
    return 0;
  }
  uVar6 = param_1 + 0xc;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar11 = uVar6, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar11 = uVar6 & (long)(uVar6 * 0x100) >> 8;
  }
  uVar7 = 0;
  uVar3 = 0xfffffff2;
  if (uVar11 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
    uVar3 = 0;
    uVar7 = *(undefined4 *)(uVar6 & 0xff7fffffffffffff);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar11 = daif;
        daif = uVar11 | 0xc0;
      }
      uVar11 = ttbr1_el1;
      ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar11 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
  }
  param_2[4] = uVar7;
  if (param_3 < -0x3fdfadeb) {
    if (param_3 == -0x3febadf9) goto LAB_00124390;
    iVar5 = -0x3fe7adf5;
LAB_00124388:
    if (param_3 == iVar5) goto LAB_00124390;
  }
  else {
    if (param_3 != 1) {
      iVar5 = -0x3fdfadeb;
      goto LAB_00124388;
    }
LAB_00124390:
    uVar6 = param_1 + 0x10;
    if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = uVar6, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
      uVar11 = uVar6 & (long)(uVar6 * 0x100) >> 8;
    }
    uVar7 = 0;
    uVar4 = 0xfffffff2;
    if (uVar11 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        uVar14 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar4 = 0;
      uVar7 = *(undefined4 *)(uVar6 & 0xff7fffffffffffff);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar11 = daif;
          daif = uVar11 | 0xc0;
        }
        uVar11 = ttbr1_el1;
        ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar11 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    uVar3 = uVar4 | uVar3;
    param_2[6] = uVar7;
  }
  uVar4 = (uint)_cpu_hwcaps;
  if (param_3 == -0x3fe7adf5) {
LAB_00124480:
    uVar6 = param_1 + 0x14;
    if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = uVar6, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
      uVar11 = uVar6 & (long)(uVar6 * 0x100) >> 8;
    }
    uVar7 = 0;
    uVar9 = 0xfffffff2;
    if (uVar11 < 0x7ffffffffd) {
      if ((uVar4 >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        uVar14 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar9 = 0;
      uVar7 = *(undefined4 *)(uVar6 & 0xff7fffffffffffff);
      if ((uVar4 >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar11 = daif;
          daif = uVar11 | 0xc0;
        }
        uVar11 = ttbr1_el1;
        ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar11 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    uVar3 = uVar9 | uVar3;
    param_2[8] = uVar7;
  }
  else {
    if (param_3 == 1) {
      uVar6 = param_1 + 0x20;
      if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
         (uVar11 = uVar6, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
        uVar11 = uVar6 & (long)(uVar6 * 0x100) >> 8;
      }
      uVar7 = 0;
      uVar9 = 0xfffffff2;
      if (uVar11 < 0x7ffffffffd) {
        if ((uVar4 >> 0x1d & 1) == 0) {
          uVar11 = daif;
          if ((uVar11 & 0x80) == 0) {
            uVar14 = daif;
            daif = uVar14 | 0xc0;
          }
          uVar14 = ttbr1_el1;
          ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar1[1];
          InstructionSynchronizationBarrier();
          daif = uVar11;
        }
        uVar9 = 0;
        uVar7 = *(undefined4 *)(uVar6 & 0xff7fffffffffffff);
        if ((uVar4 >> 0x1d & 1) == 0) {
          uVar6 = daif;
          if ((uVar6 & 0x80) == 0) {
            uVar11 = daif;
            daif = uVar11 | 0xc0;
          }
          uVar11 = ttbr1_el1;
          ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar11 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar6;
        }
      }
      uVar3 = uVar9 | uVar3;
      param_2[0xe] = uVar7;
      goto LAB_0012462c;
    }
    if (param_3 == -0x3fdfadeb) goto LAB_00124480;
  }
  if ((param_3 != 1) && (param_3 != -0x3fdfadeb)) {
    return uVar3;
  }
LAB_0012462c:
  uVar6 = param_1 + 0x18;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar11 = uVar6, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar11 = uVar6 & (long)(uVar6 * 0x100) >> 8;
  }
  uVar7 = 0;
  uVar9 = 0xfffffff2;
  uVar4 = (uint)_cpu_hwcaps;
  if (uVar11 < 0x7ffffffffd) {
    if ((uVar4 >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
    uVar9 = 0;
    uVar7 = *(undefined4 *)(uVar6 & 0xff7fffffffffffff);
    if ((uVar4 >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar11 = daif;
        daif = uVar11 | 0xc0;
      }
      uVar11 = ttbr1_el1;
      ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar11 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
  }
  param_1 = param_1 + 0x1c;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar6 = param_1, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar6 = param_1 & (long)(param_1 * 0x100) >> 8;
  }
  uVar10 = 0;
  uVar13 = 0xfffffff2;
  if (uVar6 < 0x7ffffffffd) {
    if ((uVar4 >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar11 = daif;
        daif = uVar11 | 0xc0;
      }
      uVar11 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar11 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    uVar13 = 0;
    uVar10 = *(undefined4 *)(param_1 & 0xff7fffffffffffff);
    if ((uVar4 >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar11 = daif;
        daif = uVar11 | 0xc0;
      }
      uVar11 = ttbr1_el1;
      ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar11 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
  }
  param_2[10] = uVar7;
  param_2[0xc] = uVar10;
  return uVar9 | uVar13 | uVar3;
}



//------------------------------------------------------------
// compat_put_fastrpc_ioctl_mem_map @ 00124944 size=228
// signature: undefined compat_put_fastrpc_ioctl_mem_map(void)
// callers: [compat_fastrpc_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 compat_put_fastrpc_ioctl_mem_map(long param_1,long param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  puVar2 = (undefined8 *)sp_el0;
  uVar1 = param_1 + 0x20;
  if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = uVar1, ((uint)*puVar2 >> 0x1a & 1) != 0)) {
    uVar5 = uVar1 & (long)(uVar1 * 0x100) >> 8;
  }
  uVar4 = 0xfffffff2;
  if (uVar5 < 0x7ffffffff9) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar2[1];
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar4 = 0;
    *(undefined8 *)(uVar1 & 0xff7fffffffffffff) = *(undefined8 *)(param_2 + 0x28);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar1 = daif;
      if ((uVar1 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      uVar5 = ttbr1_el1;
      ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar1;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// verify_transport_device @ 001254bc size=152
// signature: undefined verify_transport_device(void)
// callers: [fastrpc_release_current_dsp_process, fastrpc_channel_open]
//------------------------------------------------------------

undefined4 verify_transport_device(uint param_1)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  
  if (5 < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x125550);
    (*pcVar2)();
  }
  uVar5 = ((ulong)param_1 + (ulong)param_1 * 2) * 0x20;
  lVar1 = uVar5 + 0x1507e8;
  mutex_lock(lVar1);
  if ((0x1e0 < uVar5) || (param_1 == 5)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x125554);
    (*pcVar2)();
  }
  lVar4 = *(long *)(&rpmsg_session_control + (ulong)param_1 * 0x60);
  mutex_unlock(lVar1);
  uVar3 = 0xffffffed;
  if (lVar4 != 0) {
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// fastrpc_wait_for_transport_interrupt @ 00125558 size=244
// signature: undefined fastrpc_wait_for_transport_interrupt(void)
// callers: [fastrpc_channel_open]
//------------------------------------------------------------

void fastrpc_wait_for_transport_interrupt(uint param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = 0;
  if ((param_2 < 4) && (param_2 != 1)) {
    if (5 < param_1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x12564c);
      (*pcVar2)();
    }
    if (*(int *)(&DAT_00150838 + (ulong)param_1 * 0x60) == 0) {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_60 = 0;
      init_wait_entry(&local_60,0);
      lVar1 = (ulong)param_1 * 0x60 + 0x150820;
      while( true ) {
        lVar3 = prepare_to_wait_event(lVar1,&local_60,1);
        if (*(int *)(&DAT_00150838 + (ulong)param_1 * 0x60) != 0) break;
        if (lVar3 != 0) goto LAB_00125618;
        schedule();
      }
      finish_wait(lVar1,&local_60);
      lVar3 = 0;
    }
    else {
      lVar3 = 0;
    }
  }
LAB_00125618:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_transport_send @ 00125650 size=240
// signature: undefined fastrpc_transport_send(void)
// callers: [fastrpc_internal_invoke, fastrpc_dspsignal_signal]
//------------------------------------------------------------

undefined4 fastrpc_transport_send(uint param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  ulong uVar5;
  
  if (5 < param_1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x12573c);
    (*pcVar3)();
  }
  uVar5 = ((ulong)param_1 + (ulong)param_1 * 2) * 0x20;
  lVar1 = uVar5 + 0x1507e8;
  mutex_lock(lVar1);
  if ((0x1e0 < uVar5) || (param_1 == 5)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x125740);
    (*pcVar3)();
  }
  uVar5 = *(ulong *)(&rpmsg_session_control + (ulong)param_1 * 0x60);
  if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
    lVar2 = sp_el0;
    uVar4 = 0xffffffed;
    _printk(&DAT_0014d56b,0xd3,lVar2 + 0x848,"fastrpc_transport_send",lVar2 + 0x848,0xffffffed);
  }
  else {
    uVar4 = rpmsg_send(*(undefined8 *)(uVar5 + 0x3c8),param_2,param_3);
  }
  mutex_unlock(lVar1);
  return uVar4;
}



//------------------------------------------------------------
// fastrpc_rproc_trace_events @ 00125744 size=4
// signature: undefined fastrpc_rproc_trace_events(void)
// callers: [fastrpc_restart_notifier_cb]
//------------------------------------------------------------

void fastrpc_rproc_trace_events(void)

{
  return;
}



//------------------------------------------------------------
// fastrpc_transport_session_init @ 0012574c size=136
// signature: undefined fastrpc_transport_session_init(void)
// callers: [init_module]
//------------------------------------------------------------

void fastrpc_transport_session_init(uint param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  
  if (4 < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1257d0);
    (*pcVar2)();
  }
  if (0x1a8 < ((ulong)param_1 + (ulong)param_1 * 2) * 0x20) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x1257d4);
    (*pcVar2)();
  }
  lVar1 = (ulong)param_1 * 0x60;
  *(undefined8 *)(&DAT_00150818 + lVar1) = param_2;
  __mutex_init(lVar1 + 0x1507e8,"&rpmsg_session_control[cid].rpmsg_mutex",
               &fastrpc_transport_session_init___key);
  __init_waitqueue_head
            (lVar1 + 0x150820,"&rpmsg_session_control[cid].wait_for_rpmsg_ch",
             &fastrpc_transport_session_init___key_2);
  return;
}



//------------------------------------------------------------
// fastrpc_transport_session_deinit @ 001257d8 size=16
// signature: undefined fastrpc_transport_session_deinit(void)
// callers: [fastrpc_deinit]
//------------------------------------------------------------

void fastrpc_transport_session_deinit(uint param_1)

{
  code *pcVar1;
  
  if (4 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1257e8);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// fastrpc_set_tvm_remote_domain @ 001257ec size=20
// signature: undefined fastrpc_set_tvm_remote_domain(void)
// callers: [fastrpc_init_process]
//------------------------------------------------------------

undefined8 fastrpc_set_tvm_remote_domain(long param_1)

{
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  return 0;
}



//------------------------------------------------------------
// fastrpc_transport_init @ 00125804 size=92
// signature: undefined fastrpc_transport_init(void)
// callers: [init_module]
//------------------------------------------------------------

int fastrpc_transport_init(void)

{
  int iVar1;
  
  iVar1 = __register_rpmsg_driver(&fastrpc_rpmsg_client,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_0014f6c6,"fastrpc_transport_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// fastrpc_transport_deinit @ 00125864 size=36
// signature: undefined fastrpc_transport_deinit(void)
// callers: [fastrpc_deinit, cleanup_module]
//------------------------------------------------------------

void fastrpc_transport_deinit(void)

{
  unregister_rpmsg_driver(&fastrpc_rpmsg_client);
  return;
}



//------------------------------------------------------------
// fastrpc_rpmsg_probe @ 0012588c size=320
// signature: undefined fastrpc_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 fastrpc_rpmsg_probe(ulong param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar4 = 0xffffffed;
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    uVar3 = get_cid_from_rpdev(param_1);
    uVar5 = (ulong)uVar3;
    if (-1 < (int)uVar3) {
      if (5 < uVar3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1259cc);
        (*pcVar2)();
      }
      uVar6 = (uVar5 + (ulong)uVar3 * 2) * 0x20;
      lVar1 = uVar6 + 0x1507e8;
      mutex_lock(lVar1);
      if ((uVar6 < 0x1e1) && (uVar3 != 5)) {
        uVar6 = uVar5 * 0x60;
        *(ulong *)(&rpmsg_session_control + uVar6) = param_1;
        mutex_unlock(lVar1);
        *(undefined4 *)(&DAT_00150838 + uVar6) = 1;
        __wake_up(uVar6 + 0x150820,1,1,0);
        if (uVar6 < 0x1a9) {
          lVar1 = sp_el0;
          _printk(&DAT_001504c3,99,lVar1 + 0x848,"fastrpc_rpmsg_probe",
                  *(undefined8 *)(&DAT_00150818 + uVar5 * 0x60));
          return 0;
        }
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1259c8);
      (*pcVar2)();
    }
    lVar1 = sp_el0;
    _printk(&DAT_0014e19d,0x67,lVar1 + 0x848,"fastrpc_rpmsg_probe",
            **(undefined8 **)(*(long *)(param_1 + 0x60) + 0x2e8),uVar5);
    uVar4 = 0xffffffd4;
  }
  return uVar4;
}



//------------------------------------------------------------
// fastrpc_rpmsg_remove @ 001259d0 size=284
// signature: undefined fastrpc_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void fastrpc_rpmsg_remove(ulong param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    uVar3 = get_cid_from_rpdev(param_1);
    uVar4 = (ulong)uVar3;
    if (-1 < (int)uVar3) {
      if (5 < uVar3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x125aec);
        (*pcVar2)();
      }
      uVar5 = (uVar4 + (ulong)uVar3 * 2) * 0x20;
      lVar1 = uVar5 + 0x1507e8;
      mutex_lock(lVar1);
      if ((uVar5 < 0x1e1) && (uVar3 != 5)) {
        uVar5 = uVar4 * 0x60;
        *(undefined8 *)(&rpmsg_session_control + uVar5) = 0;
        mutex_unlock(lVar1);
        *(undefined4 *)(&DAT_00150838 + uVar5) = 0;
        if (uVar5 < 0x1a9) {
          lVar1 = sp_el0;
          _printk(&DAT_0014db2a,0x89,lVar1 + 0x848,"fastrpc_rpmsg_remove",
                  *(undefined8 *)(&DAT_00150818 + uVar4 * 0x60));
          return;
        }
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x125ae8);
      (*pcVar2)();
    }
    lVar1 = sp_el0;
    _printk(&DAT_0014feec,0x8d,lVar1 + 0x848,"fastrpc_rpmsg_remove",
            **(undefined8 **)(*(long *)(param_1 + 0x60) + 0x2e8),uVar4);
  }
  return;
}



//------------------------------------------------------------
// fastrpc_rpmsg_callback @ 00125af0 size=140
// signature: undefined fastrpc_rpmsg_callback(void)
// callers: []
//------------------------------------------------------------

undefined4 fastrpc_rpmsg_callback(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = get_cid_from_rpdev();
  if (iVar2 < 0) {
    lVar1 = sp_el0;
    uVar3 = 0xffffff82;
    _printk(&DAT_0014ef30,0xa5,lVar1 + 0x848,"fastrpc_rpmsg_callback",param_2,param_3,0xffffff82);
  }
  else {
    uVar3 = fastrpc_handle_rpc_response(param_2,param_3,iVar2);
  }
  return uVar3;
}



//------------------------------------------------------------
// get_cid_from_rpdev @ 00125c60 size=284
// signature: undefined get_cid_from_rpdev(void)
// callers: [fastrpc_rpmsg_callback, fastrpc_rpmsg_probe, fastrpc_rpmsg_remove]
//------------------------------------------------------------

void get_cid_from_rpdev(ulong param_1)

{
  long lVar1;
  char *__s1;
  int iVar2;
  undefined4 uVar3;
  char *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = 0xffffffed;
  local_30 = (char *)0x0;
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    iVar2 = of_property_read_string
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"label",&local_30);
    if (iVar2 != 0) {
      local_30 = (char *)**(undefined8 **)(*(long *)(param_1 + 0x60) + 0x2e8);
    }
    __s1 = local_30;
    iVar2 = strcmp(local_30,"cdsp");
    if (iVar2 == 0) {
      uVar3 = 3;
    }
    else {
      iVar2 = strcmp(__s1,"adsp");
      uVar3 = 0;
      if (iVar2 != 0) {
        iVar2 = strcmp(__s1,"slpi");
        if (iVar2 == 0) {
          uVar3 = 2;
        }
        else {
          iVar2 = strcmp(__s1,"mdsp");
          if (iVar2 == 0) {
            uVar3 = 1;
          }
          else {
            iVar2 = strcmp(__s1,"cdsp1");
            uVar3 = 4;
            if (iVar2 != 0) {
              uVar3 = 0xffffffff;
            }
          }
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0012684c size=2372
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined **ppuVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  debugfs_root = debugfs_create_dir("adsprpc",0);
  if ((debugfs_root == 0) || (0xfffffffffffff000 < debugfs_root)) {
    lVar11 = sp_el0;
    _printk(&DAT_0014d250,lVar11 + 0x848,"fastrpc_device_init");
    debugfs_remove(debugfs_root);
    debugfs_root = 0;
  }
  memset(&DAT_00150508,0,0x1a0);
  gfa = &gcinfo;
  __mutex_init(&DAT_00150660,"&me->mut_uid",&fastrpc_init___key);
  lVar11 = 0;
  uVar9 = 0;
  DAT_001506a4 = 4;
  do {
    lVar10 = (long)gfa + lVar11 + 0x950;
    *(undefined4 *)((long)gfa + lVar11 + 0x948) = 0;
    __init_swait_queue_head(lVar10,"&x->wait",&init_completion___key);
    lVar10 = (long)gfa + lVar11 + 0x970;
    *(undefined4 *)((long)gfa + lVar11 + 0x968) = 0;
    __init_swait_queue_head(lVar10,"&x->wait",&init_completion___key);
    *(undefined8 *)((long)gfa + lVar11 + 0x9d0) = 0;
    *(undefined4 *)((long)gfa + lVar11 + 0xa20) = 1;
    *(undefined1 *)((long)gfa + lVar11 + 0xa24) = 0;
    __mutex_init((long)gfa + lVar11 + 0x9a0,"&me->channel[i].smd_mutex",&fastrpc_init___key_416);
    fastrpc_transport_session_init(uVar9 & 0xffffffff,*(undefined8 *)((long)gfa + lVar11 + 8));
    *(undefined4 *)((long)gfa + lVar11 + 0x2e40) = 0;
    *(undefined4 *)((long)gfa + lVar11 + 0x6a50) = 0;
    *(undefined8 *)((long)gfa + lVar11 + 0x6a58) = 0;
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x588,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x5d0,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x618,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x660,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x6a8,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x6f0,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x738,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x780,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x7c8,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x810,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x858,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x8a0,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x8e8,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    __init_waitqueue_head
              ((long)gfa + lVar11 + 0x930,"&me->channel[i].spd[jj].wait_for_pdup",
               &fastrpc_init___key_418);
    uVar9 = uVar9 + 1;
    lVar11 = lVar11 + 0x6a68;
  } while (uVar9 != 5);
  *(undefined4 *)(gfa + 0x292b) = 0;
  *(undefined1 *)((long)gfa + 0x1495c) = 1;
  uVar9 = socinfo_get_part_info(0xf);
  lVar11 = sp_el0;
  bVar1 = (uVar9 & 1) == 0;
  if (bVar1) {
    puVar5 = &DAT_0014bec3;
    uVar7 = 0xc33;
  }
  else {
    puVar5 = &DAT_0014cf8c;
    uVar7 = 0xc30;
  }
  DAT_00150690 = (uint)bVar1;
  _printk(puVar5,uVar7,lVar11 + 0x848,"fastrpc_get_nsp_status",bVar1);
  DAT_001505d0 = 0;
  DAT_001505ec = 0;
  iVar3 = bus_register(&fastrpc_bus_type);
  if (iVar3 == 0) {
    iVar3 = device_register(&fastrpc_bus);
    if (iVar3 == 0) {
      DAT_001505e8 = 1;
      _find_first_bit(&__cpu_possible_mask,_nr_cpu_ids);
      iVar3 = 0;
      while( true ) {
        uVar4 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar3);
        if (_nr_cpu_ids <= uVar4) break;
        if (0x1f < (ulong)uVar4) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x12718c);
          (*pcVar2)();
        }
        if (*(int *)(_find_next_bit + (ulong)uVar4 * 0x38) == 0) {
          DAT_0015069c = DAT_0015069c + 1;
        }
        iVar3 = uVar4 + 1;
      }
      lVar11 = sp_el0;
      lVar11 = lVar11 + 0x848;
      _printk(&DAT_0014f5a0,0xc48,lVar11,"fastrpc_lowest_capacity_corecount",DAT_0015069c);
      iVar3 = __platform_driver_register(&fastrpc_driver,&__this_module);
      if (iVar3 == 0) {
        iVar3 = alloc_chrdev_region(&DAT_001505b4,0,5,"adsprpc-smd");
        if (iVar3 == 0) {
          cdev_init(&DAT_00150508,fops);
          DAT_00150568 = &__this_module;
          iVar3 = cdev_add(&DAT_00150508,DAT_001505b4 & 0xfff00000,2);
          if (iVar3 == 0) {
            DAT_00150590 = __class_create(&__this_module,"fastrpc",&fastrpc_device_init___key);
            if (DAT_00150590 < 0xfffffffffffff001) {
              DAT_001505b8 = 1;
              DAT_00150630 = (undefined *)
                             device_create(DAT_00150590,0,DAT_001505b4 & 0xfff00000,0,"adsprpc-smd")
              ;
              iVar3 = -0x13;
              if ((DAT_00150630 != (undefined *)0x0) &&
                 (DAT_00150630 < (undefined *)0xfffffffffffff001)) {
                DAT_00150628 = device_create(DAT_00150590,0,DAT_001505b4 & 0xfff00000 | 1,0,
                                             "adsprpc-smd-secure");
                iVar3 = -1;
                if ((DAT_00150628 != 0) && (DAT_00150628 < 0xfffffffffffff001)) {
                  lVar10 = 0xf0;
                  lVar12 = 0xa18;
                  do {
                    *(undefined8 *)((long)&gfa + lVar10) = 1;
                    *(ulong *)((long)gfa + lVar12 + -0xa08) = DAT_00150628;
                    *(undefined8 *)((long)gfa + lVar12 + -0x40) = 0;
                    *(undefined4 *)((long)gfa + lVar12 + -0x38) = 0;
                    *(undefined8 *)((long)gfa + lVar12 + -0x28) = 0;
                    *(undefined4 *)((long)gfa + lVar12 + -0x20) = 2;
                    *(undefined8 *)((long)gfa + lVar12) = 0;
                    *(code **)((long)gfa + lVar12 + -0x90) = fastrpc_restart_notifier_cb;
                    uVar7 = qcom_register_ssr_notifier
                                      (*(undefined8 *)(event_fastrpc_context_alloc + lVar12 + 0x38),
                                       (long)gfa + lVar12 + -0x90);
                    *(undefined8 *)((long)gfa + lVar12 + -0x30) = uVar7;
                    if (lVar10 == 0x108) {
                      gfa[0x27e9] = DAT_00150630;
                      iVar3 = fastrpc_alloc_cma_memory(&uStack_70,&local_78,0x32000,0);
                      if (iVar3 != 0) {
                        _printk(&DAT_0014c934,0x23dd,lVar11,"fastrpc_device_init",iVar3);
                      }
                      puVar6 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x90);
                      if (puVar6 == (undefined8 *)0x0) {
                        _printk(&DAT_0014b97f,0x23e3,lVar11,"fastrpc_device_init",0xfffffff4);
                      }
                      else {
                        *puVar6 = 0;
                        puVar6[1] = 0;
                        puVar6[0xb] = 0;
                        puVar6[7] = local_78;
                        puVar6[8] = uStack_70;
                        puVar6[9] = 0x32000;
                        puVar6[10] = 0;
                        gfa[0x3533] = (undefined *)puVar6;
                      }
                    }
                    uVar7 = *(undefined8 *)(event_fastrpc_context_alloc + lVar12 + 0x38);
                    uVar9 = *(ulong *)((long)gfa + lVar12 + -0x30);
                    if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
                      _printk(&DAT_0014cca9,"fastrpc_device_init",uVar7);
                    }
                    else {
                      _printk(&DAT_0014d2d3,"fastrpc_device_init",uVar7);
                    }
                    lVar10 = lVar10 + 8;
                    lVar12 = lVar12 + 0x6a68;
                  } while (lVar10 != 0x118);
                  iVar3 = fastrpc_transport_init();
                  if (iVar3 == 0) {
                    DAT_001505e4 = 1;
                    iVar3 = register_pm_notifier(&fastrpc_notif_block);
                    if (iVar3 == 0) {
                      fastrpc_register_wakeup_source
                                (DAT_00150630,"adsprpc-non_secure",&DAT_00150640);
                      fastrpc_register_wakeup_source(DAT_00150628,"adsprpc-secure",&DAT_00150638);
                      goto LAB_00127118;
                    }
                  }
                }
              }
              lVar11 = 0x9e8;
              lVar10 = 5;
              ppuVar8 = gfa;
              do {
                if (*(long *)((long)ppuVar8 + lVar11) != 0) {
                  qcom_unregister_ssr_notifier
                            (*(long *)((long)ppuVar8 + lVar11),(long)ppuVar8 + lVar11 + -0x60);
                  ppuVar8 = gfa;
                }
                lVar11 = lVar11 + 0x6a68;
                lVar10 = lVar10 + -1;
              } while (lVar10 != 0);
              if ((DAT_00150630 != (undefined *)0x0) &&
                 (DAT_00150630 < (undefined *)0xfffffffffffff001)) {
                device_destroy(DAT_00150590,DAT_001505b4 & 0xfff00000);
              }
              if ((DAT_00150628 != 0) && (DAT_00150628 < 0xfffffffffffff001)) {
                device_destroy(DAT_00150590,DAT_001505b4 & 0xfff00000 | 1);
              }
              class_destroy(DAT_00150590);
            }
            else {
              iVar3 = -1;
            }
            cdev_del(&DAT_00150508);
          }
          else {
            iVar3 = -1;
          }
          unregister_chrdev_region(DAT_001505b4,5);
        }
        else {
          iVar3 = -1;
        }
        platform_driver_unregister(&fastrpc_driver);
      }
      else {
        iVar3 = -1;
      }
      device_unregister(&fastrpc_bus);
    }
    else {
      lVar11 = sp_el0;
      _printk(&DAT_0014d284,0x2392,lVar11 + 0x848,"fastrpc_device_init",iVar3);
    }
    bus_unregister(&fastrpc_bus_type);
  }
  else {
    lVar11 = sp_el0;
    _printk(&DAT_0014ed32,0x238c,lVar11 + 0x848,"fastrpc_device_init",iVar3);
  }
  fastrpc_deinit();
LAB_00127118:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// cleanup_module @ 00127194 size=420
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  long *plVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  while( true ) {
    uVar2 = _raw_spin_lock_irqsave(&DAT_001505c8);
    plVar1 = DAT_001505c0;
    if (DAT_001505c0 == (long *)0x0) break;
    plVar3 = (long *)DAT_001505c0[1];
    if (plVar3 != (long *)0x0) {
      lVar4 = *DAT_001505c0;
      *plVar3 = lVar4;
      if (lVar4 != 0) {
        *(long **)(lVar4 + 8) = plVar3;
      }
      *plVar1 = 0;
      plVar1[1] = 0;
    }
    _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
    fastrpc_file_put(plVar1);
  }
  _raw_spin_unlock_irqrestore(&DAT_001505c8,uVar2);
  fastrpc_deinit();
  wakeup_source_unregister(DAT_00150640);
  wakeup_source_unregister(DAT_00150638);
  lVar4 = 0;
  lVar5 = 5;
  do {
    if (lVar5 == 2) {
      kfree(*(undefined8 *)(gfa + 0x1a998));
    }
    if (*(long *)((long)&gcinfo + lVar4) != 0) {
      qcom_unregister_ssr_notifier(*(undefined8 *)(gfa + lVar4 + 0x9e8),gfa + lVar4 + 0x988);
    }
    lVar4 = lVar4 + 0x6a68;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  device_destroy(DAT_00150590,DAT_001505b4 & 0xfff00000);
  device_destroy(DAT_00150590,DAT_001505b4 & 0xfff00000 | 1);
  of_reserved_mem_device_release(DAT_001505d0);
  class_destroy(DAT_00150590);
  cdev_del(&DAT_00150508);
  unregister_chrdev_region(DAT_001505b4,5);
  if (DAT_001505e4 != 0) {
    fastrpc_transport_deinit();
  }
  DAT_001505e4 = 0;
  if (DAT_001505e8 != 0) {
    bus_unregister(&fastrpc_bus_type);
    device_unregister(&fastrpc_bus);
  }
  kfree(DAT_00150618);
  debugfs_remove(debugfs_root);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00154000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_fastrpc_context_restore, trace_event_raw_event_fastrpc_msg, trace_event_raw_event_fastrpc_dma_unmap, trace_event_raw_event_fastrpc_dma_alloc, trace_event_raw_event_fastrpc_perf_counters, trace_event_raw_event_fastrpc_transport_send, trace_event_raw_event_fastrpc_context_alloc, trace_event_raw_event_fastrpc_dspsignal, trace_event_raw_event_fastrpc_context_interrupt, trace_event_raw_event_fastrpc_dma_map, trace_event_raw_event_fastrpc_transport_response, trace_event_raw_event_fastrpc_dma_free, trace_event_raw_event_fastrpc_context_complete, trace_event_raw_event_fastrpc_context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00154008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_fastrpc_context_restore, trace_event_raw_event_fastrpc_msg, trace_event_raw_event_fastrpc_dma_unmap, trace_event_raw_event_fastrpc_dma_alloc, trace_event_raw_event_fastrpc_perf_counters, trace_event_raw_event_fastrpc_transport_send, trace_event_raw_event_fastrpc_context_alloc, trace_event_raw_event_fastrpc_dspsignal, trace_event_raw_event_fastrpc_context_interrupt, trace_event_raw_event_fastrpc_dma_map, trace_event_raw_event_fastrpc_transport_response, trace_event_raw_event_fastrpc_dma_free, trace_event_raw_event_fastrpc_context_complete, trace_event_raw_event_fastrpc_context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00154010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_fastrpc_context_restore, trace_event_raw_event_fastrpc_msg, trace_event_raw_event_fastrpc_dma_unmap, trace_event_raw_event_fastrpc_dma_alloc, trace_event_raw_event_fastrpc_perf_counters, trace_event_raw_event_fastrpc_transport_send, trace_event_raw_event_fastrpc_context_alloc, trace_event_raw_event_fastrpc_dspsignal, trace_event_raw_event_fastrpc_context_interrupt, trace_event_raw_event_fastrpc_dma_map, trace_event_raw_event_fastrpc_transport_response, trace_event_raw_event_fastrpc_dma_free, trace_event_raw_event_fastrpc_context_complete, trace_event_raw_event_fastrpc_context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00154018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_fastrpc_context_complete, perf_trace_fastrpc_dma_map, getnstimediff, fastrpc_internal_mem_unmap, fastrpc_internal_mmap, fastrpc_get_info_from_dsp, trace_event_raw_event_fastrpc_context_alloc, trace_event_raw_event_fastrpc_dspsignal, fastrpc_internal_invoke, fastrpc_create_persistent_headers, fastrpc_setup_service_locator, fastrpc_dsp_restart_handler, fastrpc_mmap_on_dsp, fastrpc_dspsignal_signal, get_cid_from_rpdev, perf_trace_fastrpc_transport_response, perf_trace_fastrpc_context_free, trace_event_raw_event_fastrpc_msg, compat_fastrpc_dspsignal_cancel_wait, fastrpc_ramdump_collection, fastrpc_unmap_on_dsp, compat_fastrpc_dspsignal_destroy, fastrpc_minidump_add_region, fastrpc_get_info_from_kernel, perf_trace_fastrpc_dma_free, trace_event_raw_event_fastrpc_transport_send, fastrpc_dev_map_dma, fastrpc_probe, fastrpc_get_info, perf_trace_fastrpc_dma_alloc, init_module, fastrpc_internal_invoke2, fastrpc_internal_mem_map, fastrpc_init_create_static_process, fastrpc_init_attach_process, trace_event_raw_event_fastrpc_dma_unmap, fastrpc_init_create_dynamic_process, perf_trace_fastrpc_msg, fastrpc_buf_alloc, perf_trace_fastrpc_context_alloc, fastrpc_check_pd_status, trace_event_raw_event_fastrpc_perf_counters, perf_trace_fastrpc_context_restore, fastrpc_send_cpuinfo_to_dsp, compat_fastrpc_dspsignal_create, fastrpc_buf_free, trace_event_raw_event_fastrpc_dma_map, trace_event_raw_event_fastrpc_dma_free, perf_trace_fastrpc_dspsignal, fastrpc_device_ioctl, perf_trace_fastrpc_dma_unmap, trace_event_raw_event_fastrpc_context_restore, trace_event_raw_event_fastrpc_dma_alloc, poll_for_remote_response, fastrpc_mmap_create, compat_fastrpc_dspsignal_wait, perf_trace_fastrpc_perf_counters, perf_trace_fastrpc_transport_send, fastrpc_release_current_dsp_process, fastrpc_wait_for_transport_interrupt, fastrpc_restart_notifier_cb, fastrpc_debugfs_read, fastrpc_internal_munmap, perf_trace_fastrpc_context_interrupt, fastrpc_mmap_free, trace_event_raw_event_fastrpc_context_interrupt, fastrpc_munmap_on_dsp, trace_event_raw_event_fastrpc_transport_response, compat_fastrpc_dspsignal_signal, trace_event_raw_event_fastrpc_context_complete, trace_event_raw_event_fastrpc_context_free, fastrpc_handle_rpc_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00154020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_fastrpc_context_free, perf_trace_fastrpc_context_complete, perf_trace_fastrpc_dma_map, perf_trace_fastrpc_msg, perf_trace_fastrpc_context_alloc, perf_trace_fastrpc_dma_free, perf_trace_fastrpc_perf_counters, perf_trace_fastrpc_transport_send, perf_trace_fastrpc_context_restore, perf_trace_fastrpc_context_interrupt, perf_trace_fastrpc_dma_alloc, perf_trace_fastrpc_dspsignal, perf_trace_fastrpc_dma_unmap, perf_trace_fastrpc_transport_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00154028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_fastrpc_context_free, perf_trace_fastrpc_context_complete, perf_trace_fastrpc_dma_map, perf_trace_fastrpc_msg, perf_trace_fastrpc_context_alloc, perf_trace_fastrpc_dma_free, perf_trace_fastrpc_perf_counters, perf_trace_fastrpc_transport_send, perf_trace_fastrpc_context_restore, perf_trace_fastrpc_context_interrupt, perf_trace_fastrpc_dma_alloc, perf_trace_fastrpc_dspsignal, perf_trace_fastrpc_dma_unmap, perf_trace_fastrpc_transport_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00154030 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_fastrpc_msg, fastrpc_smq_ctx_detail, perf_trace_fastrpc_msg, perf_trace_fastrpc_dspsignal, fastrpc_print_debug_data, trace_event_raw_event_fastrpc_dspsignal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run7 @ 00154038 size=1
// signature: undefined bpf_trace_run7(void)
// callers: [__bpf_trace_fastrpc_dma_map, __bpf_trace_fastrpc_transport_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run7(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00154040 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_fastrpc_transport_response, __bpf_trace_fastrpc_dma_alloc, __bpf_trace_fastrpc_context_restore, __bpf_trace_fastrpc_context_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00154048 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_fastrpc_dma_free, __bpf_trace_fastrpc_dma_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 00154050 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_fastrpc_context_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00154058 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_fastrpc_dspsignal, __bpf_trace_fastrpc_context_alloc, __bpf_trace_fastrpc_context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run12 @ 00154060 size=1
// signature: undefined bpf_trace_run12(void)
// callers: [__bpf_trace_fastrpc_perf_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run12(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 00154068 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_fastrpc_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 00154070 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [getnstimediff, poll_for_remote_response, fastrpc_buf_alloc, fastrpc_mmap_create, fastrpc_internal_invoke2, fastrpc_handle_rpc_response, fastrpc_internal_invoke, fastrpc_restart_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00154078 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [fastrpc_init_create_dynamic_process, fastrpc_buf_alloc, fastrpc_mmap_create, fastrpc_file_put, fastrpc_print_debug_data, fastrpc_internal_invoke, fastrpc_create_persistent_headers, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_buf_free, fastrpc_mmap_free, fastrpc_get_info, fastrpc_cached_buf_list_free, fastrpc_device_ioctl, fastrpc_manage_poll_mode, context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00154080 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [fastrpc_init_create_dynamic_process, fastrpc_buf_alloc, fastrpc_mmap_create, fastrpc_file_put, fastrpc_print_debug_data, fastrpc_internal_invoke, fastrpc_create_persistent_headers, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_buf_free, fastrpc_mmap_free, fastrpc_get_info, fastrpc_cached_buf_list_free, fastrpc_device_ioctl, fastrpc_manage_poll_mode, context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00154088 size=1
// signature: undefined __kmalloc(void)
// callers: [fastrpc_create_persistent_headers, fastrpc_probe, fastrpc_device_open, fastrpc_get_info, compat_fastrpc_device_ioctl, compat_fastrpc_ioctl_invoke2, fastrpc_mmap_on_dsp, fastrpc_init_process, fastrpc_internal_invoke, fastrpc_init_create_static_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memmove @ 00154090 size=1
// signature: void * memmove(void * __dest, void * __src, size_t __n)
// callers: [fastrpc_internal_invoke2, fastrpc_internal_invoke, put_args]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00154098 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [fastrpc_driver_register, fastrpc_dspsignal_wait, fastrpc_init_create_dynamic_process, fastrpc_internal_mem_unmap, context_notify_user, fastrpc_internal_mmap, fastrpc_file_put, fastrpc_dspsignal_destroy, fastrpc_dev_unmap_dma, fastrpc_bus_match, fastrpc_driver_invoke, fastrpc_internal_invoke, cleanup_module, fastrpc_internal_control, fastrpc_mmap_remove, fastrpc_dsp_restart_handler, fastrpc_mmap_add_global, fastrpc_device_open, fastrpc_update_ramdump_status, fastrpc_dspsignal_cancel_wait, poll_for_remote_response, fastrpc_queue_pd_status, fastrpc_driver_unregister, fastrpc_device_create, fastrpc_print_debug_data, fastrpc_release_current_dsp_process, fastrpc_pdr_cb, fastrpc_restart_notifier_cb, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_dev_map_dma, fastrpc_mmap_free, fastrpc_get_info, fastrpc_notify_drivers, fastrpc_internal_invoke2, fastrpc_get_persistent_map, fastrpc_dspsignal_create, fastrpc_handle_rpc_response, fastrpc_dev_get_hlos_pid, fastrpc_internal_mem_map, fastrpc_init_create_static_process, context_free, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001540a0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [fastrpc_driver_register, fastrpc_dspsignal_wait, fastrpc_init_create_dynamic_process, fastrpc_internal_mem_unmap, context_notify_user, fastrpc_internal_mmap, fastrpc_file_put, fastrpc_dspsignal_destroy, fastrpc_dev_unmap_dma, fastrpc_bus_match, fastrpc_driver_invoke, fastrpc_internal_invoke, cleanup_module, fastrpc_internal_control, fastrpc_mmap_remove, fastrpc_dsp_restart_handler, fastrpc_mmap_add_global, fastrpc_device_open, fastrpc_update_ramdump_status, fastrpc_dspsignal_cancel_wait, poll_for_remote_response, fastrpc_queue_pd_status, fastrpc_driver_unregister, fastrpc_device_create, fastrpc_print_debug_data, fastrpc_release_current_dsp_process, fastrpc_pdr_cb, fastrpc_restart_notifier_cb, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_dev_map_dma, fastrpc_mmap_free, fastrpc_get_info, fastrpc_notify_drivers, fastrpc_internal_invoke2, fastrpc_get_persistent_map, fastrpc_dspsignal_create, fastrpc_handle_rpc_response, fastrpc_dev_get_hlos_pid, fastrpc_internal_mem_map, fastrpc_init_create_static_process, context_free, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001540a8 size=1
// signature: undefined _printk(void)
// callers: [fastrpc_driver_register, fastrpc_internal_mem_unmap, fastrpc_internal_mmap, fastrpc_get_info_from_dsp, fastrpc_internal_invoke, fastrpc_create_persistent_headers, fastrpc_setup_service_locator, fastrpc_register_wakeup_source, fastrpc_dsp_restart_handler, fastrpc_mmap_on_dsp, fastrpc_dspsignal_signal, fastrpc_channel_open, fastrpc_ramdump_collection, fastrpc_dspsignal_cancel_wait, fastrpc_driver_unregister, fastrpc_minidump_add_region, fastrpc_restore, fastrpc_get_info_from_kernel, fastrpc_dev_map_dma, fastrpc_probe, fastrpc_get_info, init_module, fastrpc_internal_invoke2, fastrpc_dspsignal_create, fastrpc_manage_poll_mode, fastrpc_internal_mem_map, fastrpc_init_create_static_process, context_free, fastrpc_init_attach_process, fastrpc_dspsignal_wait, fastrpc_init_create_dynamic_process, fastrpc_buf_alloc, fastrpc_transport_send, fastrpc_rpmsg_probe, fastrpc_alloc_cma_memory, fastrpc_file_put, fastrpc_dspsignal_destroy, fastrpc_dev_unmap_dma, fastrpc_rpmsg_remove, fastrpc_transport_init, fastrpc_send_cpuinfo_to_dsp, fastrpc_rpmsg_callback, fastrpc_buf_free, fastrpc_internal_control, fastrpc_nsp_status_show, fastrpc_device_ioctl, fastrpc_set_session_info, fastrpc_init_process, fastrpc_session_alloc_secure_memory, fastrpc_device_open, fastrpc_update_ramdump_status, fastrpc_queue_pd_status, fastrpc_mmap_create, fastrpc_device_create, compat_fastrpc_get_dsp_info, fastrpc_release_current_dsp_process, fastrpc_pdr_cb, fastrpc_restart_notifier_cb, put_args, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_mmap_free, fastrpc_munmap_on_dsp, fastrpc_handle_rpc_response, fastrpc_hibernation_suspend, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001540b0 size=1
// signature: undefined __check_object_size(void)
// callers: [fastrpc_internal_invoke2, fastrpc_device_ioctl, fastrpc_init_process, fastrpc_internal_invoke, fastrpc_init_create_static_process, put_args]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001540c8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [fastrpc_control, compat_fastrpc_dspsignal_create, compat_fastrpc_dspsignal_cancel_wait, compat_fastrpc_dspsignal_destroy, fastrpc_internal_invoke2, compat_fastrpc_dspsignal_wait, fastrpc_device_ioctl, compat_fastrpc_dspsignal_signal, fastrpc_init_process, fastrpc_internal_invoke, fastrpc_init_create_static_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001540d0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [fastrpc_control, compat_fastrpc_dspsignal_create, compat_fastrpc_dspsignal_cancel_wait, compat_fastrpc_dspsignal_destroy, init_module, fastrpc_internal_invoke2, compat_fastrpc_dspsignal_wait, fastrpc_device_ioctl, compat_fastrpc_dspsignal_signal, fastrpc_init_process, fastrpc_internal_invoke, fastrpc_init_create_static_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sort @ 001540d8 size=1
// signature: undefined sort(void)
// callers: [fastrpc_probe, fastrpc_get_info, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001540e0 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [fastrpc_device_open, init_module, fastrpc_dspsignal_create, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001540f0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [fastrpc_device_open, fastrpc_queue_pd_status, fastrpc_buf_alloc, fastrpc_mmap_create, fastrpc_device_create, compat_fastrpc_get_dsp_info, fastrpc_print_debug_data, fastrpc_internal_invoke, fastrpc_debugfs_read, fastrpc_probe, init_module, compat_fastrpc_control, compat_fastrpc_device_ioctl, compat_fastrpc_ioctl_invoke2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001540f8 size=1
// signature: undefined kfree(void)
// callers: [compat_fastrpc_get_dsp_info, fastrpc_file_put, fastrpc_print_debug_data, fastrpc_internal_invoke, fastrpc_dev_release, fastrpc_debugfs_read, fastrpc_probe, fastrpc_buf_free, fastrpc_mmap_free, fastrpc_deinit, cleanup_module, fastrpc_get_info, compat_fastrpc_control, fastrpc_internal_invoke2, compat_fastrpc_device_ioctl, compat_fastrpc_ioctl_invoke2, fastrpc_mmap_on_dsp, fastrpc_init_process, fastrpc_init_create_static_process, context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_normalized_timespec64 @ 00154100 size=1
// signature: undefined set_normalized_timespec64(void)
// callers: [getnstimediff, fastrpc_internal_invoke2, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_normalized_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00154108 size=1
// signature: undefined mutex_lock(void)
// callers: [fastrpc_init_create_dynamic_process, fastrpc_internal_mem_unmap, fastrpc_transport_send, fastrpc_internal_mmap, fastrpc_rpmsg_probe, fastrpc_file_put, fastrpc_dev_unmap_dma, fastrpc_rpmsg_remove, fastrpc_internal_invoke, fastrpc_restart_drivers, fastrpc_dsp_restart_handler, fastrpc_dspsignal_signal, fastrpc_device_ioctl, fastrpc_channel_open, fastrpc_session_alloc_secure_memory, fastrpc_minidump_add_region, fastrpc_print_debug_data, fastrpc_pdr_cb, fastrpc_restart_notifier_cb, put_args, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_dev_map_dma, fastrpc_mmap_free, fastrpc_get_info, verify_transport_device, fastrpc_dspsignal_create, fastrpc_internal_mem_map, fastrpc_init_create_static_process, context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00154110 size=1
// signature: undefined mutex_unlock(void)
// callers: [fastrpc_init_create_dynamic_process, fastrpc_internal_mem_unmap, fastrpc_transport_send, fastrpc_internal_mmap, fastrpc_rpmsg_probe, fastrpc_file_put, fastrpc_dev_unmap_dma, fastrpc_rpmsg_remove, fastrpc_internal_invoke, fastrpc_restart_drivers, fastrpc_dsp_restart_handler, fastrpc_dspsignal_signal, fastrpc_device_ioctl, fastrpc_channel_open, fastrpc_session_alloc_secure_memory, fastrpc_minidump_add_region, fastrpc_print_debug_data, fastrpc_pdr_cb, fastrpc_restart_notifier_cb, put_args, fastrpc_debugfs_read, fastrpc_internal_munmap, fastrpc_dev_map_dma, fastrpc_mmap_free, fastrpc_get_info, verify_transport_device, fastrpc_dspsignal_create, fastrpc_internal_mem_map, fastrpc_init_create_static_process, context_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00154118 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [fastrpc_control, fastrpc_internal_invoke2, fastrpc_device_ioctl, fastrpc_set_session_info, fastrpc_internal_invoke, put_args]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 00154120 size=1
// signature: undefined down_read(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_vma @ 00154128 size=1
// signature: undefined find_vma(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_vma(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 00154130 size=1
// signature: undefined up_read(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_begin_cpu_access @ 00154140 size=1
// signature: undefined dma_buf_begin_cpu_access(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_begin_cpu_access(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_end_cpu_access @ 00154148 size=1
// signature: undefined dma_buf_end_cpu_access(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_end_cpu_access(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_begin_cpu_access_partial @ 00154150 size=1
// signature: undefined dma_buf_begin_cpu_access_partial(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_begin_cpu_access_partial(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_end_cpu_access_partial @ 00154158 size=1
// signature: undefined dma_buf_end_cpu_access_partial(void)
// callers: [inv_args, fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_end_cpu_access_partial(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00154160 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [fastrpc_internal_invoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00154180 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [fastrpc_get_spd_session, fastrpc_probe, fastrpc_check_pd_status, fastrpc_dsp_restart_handler, fastrpc_init_process, fastrpc_pdr_cb, get_cid_from_rpdev, fastrpc_init_create_static_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00154188 size=1
// signature: undefined init_wait_entry(void)
// callers: [fastrpc_internal_invoke2, fastrpc_check_pd_status, fastrpc_wait_for_transport_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00154190 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [fastrpc_internal_invoke2, fastrpc_check_pd_status, fastrpc_wait_for_transport_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00154198 size=1
// signature: undefined schedule(void)
// callers: [fastrpc_internal_invoke2, fastrpc_check_pd_status, fastrpc_wait_for_transport_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001541a0 size=1
// signature: undefined finish_wait(void)
// callers: [fastrpc_internal_invoke2, fastrpc_check_pd_status, fastrpc_wait_for_transport_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 001541a8 size=1
// signature: undefined wait_for_completion(void)
// callers: [fastrpc_file_put, fastrpc_release_current_dsp_process, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_wait_for_completion @ 001541b0 size=1
// signature: undefined try_wait_for_completion(void)
// callers: [fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001541b8 size=1
// signature: undefined __const_udelay(void)
// callers: [poll_for_remote_response, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 001541c0 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [fastrpc_dspsignal_wait, fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 001541c8 size=1
// signature: undefined preempt_schedule(void)
// callers: [fastrpc_wait_for_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001541d0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [fastrpc_internal_invoke2, fastrpc_file_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001541d8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [fastrpc_get_info, fastrpc_init_create_dynamic_process, fastrpc_init_attach_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001541e0 size=1
// signature: undefined fortify_panic(void)
// callers: [fastrpc_get_info, fastrpc_init_create_dynamic_process, fastrpc_init_attach_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 001541e8 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [fastrpc_buf_free, fastrpc_mmap_free, fastrpc_munmap_on_dsp, fastrpc_buf_alloc, fastrpc_mmap_create, fastrpc_dsp_restart_handler, fastrpc_mmap_on_dsp, fastrpc_init_create_static_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001541f0 size=1
// signature: undefined dev_set_name(void)
// callers: [fastrpc_device_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 001541f8 size=1
// signature: undefined device_register(void)
// callers: [init_module, fastrpc_device_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00154200 size=1
// signature: undefined put_device(void)
// callers: [fastrpc_device_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00154208 size=1
// signature: undefined dma_free_attrs(void)
// callers: [fastrpc_probe, fastrpc_buf_free, fastrpc_mmap_free, fastrpc_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_enabled @ 00154210 size=1
// signature: undefined msm_minidump_enabled(void)
// callers: [fastrpc_mmap_free, fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00154218 size=1
// signature: undefined scnprintf(void)
// callers: [fastrpc_debugfs_read, fastrpc_smq_ctx_detail, fastrpc_mmap_free, fastrpc_minidump_add_region, fastrpc_nsp_status_show, fastrpc_print_debug_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_remove_region @ 00154220 size=1
// signature: undefined msm_minidump_remove_region(void)
// callers: [fastrpc_mmap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_remove_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_unmap_attachment @ 00154228 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [fastrpc_mmap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 00154230 size=1
// signature: undefined dma_buf_detach(void)
// callers: [fastrpc_mmap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 00154238 size=1
// signature: undefined dma_buf_put(void)
// callers: [fastrpc_mmap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 00154240 size=1
// signature: undefined dma_buf_get(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_get_vmperm @ 00154248 size=1
// signature: undefined mem_buf_dma_buf_get_vmperm(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_get_vmperm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_current_vmid @ 00154250 size=1
// signature: undefined mem_buf_current_vmid(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_current_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 00154258 size=1
// signature: undefined dma_buf_attach(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 00154260 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 00154268 size=1
// signature: undefined sg_next(void)
// callers: [fastrpc_mmap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00154270 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [fastrpc_probe, fastrpc_buf_alloc, fastrpc_alloc_cma_memory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00154278 size=1
// signature: undefined complete(void)
// callers: [fastrpc_dev_map_dma, fastrpc_notify_drivers, context_notify_user, fastrpc_dev_unmap_dma, fastrpc_handle_rpc_response, fastrpc_pdr_cb, fastrpc_restart_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00154280 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [fastrpc_debugfs_read, fastrpc_dev_map_dma, fastrpc_update_ramdump_status, fastrpc_file_put, fastrpc_dev_unmap_dma, fastrpc_device_ioctl, fastrpc_handle_rpc_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 00154288 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [context_notify_user, fastrpc_pm_awake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00154290 size=1
// signature: undefined __wake_up(void)
// callers: [fastrpc_notify_drivers, fastrpc_queue_pd_status, context_notify_user, fastrpc_internal_control, fastrpc_rpmsg_probe, fastrpc_file_put, fastrpc_pdr_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00154298 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [fastrpc_get_info, fastrpc_print_debug_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001542a0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [fastrpc_probe, fastrpc_get_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 001542a8 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 001542b0 size=1
// signature: undefined get_cpu_device(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 001542b8 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [fastrpc_internal_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001542c0 size=1
// signature: undefined __list_add_valid(void)
// callers: [fastrpc_ramdump_collection, fastrpc_queue_pd_status, fastrpc_dsp_restart_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __usecs_to_jiffies @ 001542c8 size=1
// signature: undefined __usecs_to_jiffies(void)
// callers: [fastrpc_dspsignal_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __usecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible_timeout @ 001542d0 size=1
// signature: undefined wait_for_completion_interruptible_timeout(void)
// callers: [fastrpc_dspsignal_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 001542d8 size=1
// signature: undefined kmalloc_large(void)
// callers: [fastrpc_dspsignal_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 001542e0 size=1
// signature: undefined complete_all(void)
// callers: [fastrpc_dspsignal_cancel_wait, fastrpc_dspsignal_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001542e8 size=1
// signature: undefined device_unregister(void)
// callers: [cleanup_module, fastrpc_driver_unregister, init_module, fastrpc_file_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 001542f0 size=1
// signature: undefined __pm_relax(void)
// callers: [fastrpc_file_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 001542f8 size=1
// signature: undefined driver_unregister(void)
// callers: [fastrpc_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 00154300 size=1
// signature: undefined driver_register(void)
// callers: [fastrpc_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00154308 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00154310 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module, init_module, fastrpc_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00154318 size=1
// signature: undefined __mutex_init(void)
// callers: [fastrpc_device_open, init_module, fastrpc_transport_session_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00154320 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [fastrpc_device_open, init_module, fastrpc_transport_session_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// socinfo_get_part_info @ 00154328 size=1
// signature: undefined socinfo_get_part_info(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void socinfo_get_part_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 00154330 size=1
// signature: undefined bus_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00154348 size=1
// signature: undefined _find_first_bit(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00154358 size=1
// signature: undefined _find_next_bit(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00154360 size=1
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
// alloc_chrdev_region @ 00154368 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00154370 size=1
// signature: undefined cdev_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00154378 size=1
// signature: undefined cdev_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00154380 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00154388 size=1
// signature: undefined device_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 00154390 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00154398 size=1
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
// qcom_unregister_ssr_notifier @ 001543a0 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001543a8 size=1
// signature: undefined device_destroy(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001543b0 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001543b8 size=1
// signature: undefined cdev_del(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001543c0 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 001543c8 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_unregister @ 001543d0 size=1
// signature: undefined bus_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 001543d8 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_release @ 001543e0 size=1
// signature: undefined of_reserved_mem_device_release(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 001543e8 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_fastrpc_dma_alloc, trace_raw_output_fastrpc_dma_free, trace_raw_output_fastrpc_dma_map, trace_raw_output_fastrpc_dma_unmap, trace_raw_output_fastrpc_context_free, trace_raw_output_fastrpc_context_restore, trace_raw_output_fastrpc_msg, trace_raw_output_fastrpc_transport_send, trace_raw_output_fastrpc_perf_counters, trace_raw_output_fastrpc_context_complete, trace_raw_output_fastrpc_dspsignal, trace_raw_output_fastrpc_transport_response, trace_raw_output_fastrpc_context_interrupt, trace_raw_output_fastrpc_context_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 001543f0 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_fastrpc_dma_alloc, trace_raw_output_fastrpc_dma_free, trace_raw_output_fastrpc_dma_map, trace_raw_output_fastrpc_dma_unmap, trace_raw_output_fastrpc_context_free, trace_raw_output_fastrpc_context_restore, trace_raw_output_fastrpc_msg, trace_raw_output_fastrpc_transport_send, trace_raw_output_fastrpc_perf_counters, trace_raw_output_fastrpc_context_complete, trace_raw_output_fastrpc_dspsignal, trace_raw_output_fastrpc_transport_response, trace_raw_output_fastrpc_context_interrupt, trace_raw_output_fastrpc_context_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 001543f8 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_fastrpc_dma_alloc, trace_raw_output_fastrpc_dma_free, trace_raw_output_fastrpc_dma_map, trace_raw_output_fastrpc_dma_unmap, trace_raw_output_fastrpc_context_free, trace_raw_output_fastrpc_context_restore, trace_raw_output_fastrpc_msg, trace_raw_output_fastrpc_transport_send, trace_raw_output_fastrpc_perf_counters, trace_raw_output_fastrpc_context_complete, trace_raw_output_fastrpc_dspsignal, trace_raw_output_fastrpc_transport_response, trace_raw_output_fastrpc_context_interrupt, trace_raw_output_fastrpc_context_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dump_enabled @ 00154408 size=1
// signature: undefined dump_enabled(void)
// callers: [fastrpc_dsp_restart_handler, fastrpc_restart_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_elf_dump @ 00154410 size=1
// signature: undefined qcom_elf_dump(void)
// callers: [fastrpc_ramdump_collection, fastrpc_dsp_restart_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_elf_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00154418 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [fastrpc_minidump_add_region]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00154420 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [fastrpc_debugfs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 00154428 size=1
// signature: undefined wakeup_source_register(void)
// callers: [fastrpc_register_wakeup_source]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 00154430 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [fastrpc_probe, fastrpc_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 00154438 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [fastrpc_probe, fastrpc_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_unmap @ 00154440 size=1
// signature: undefined iommu_unmap(void)
// callers: [fastrpc_probe, fastrpc_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_unmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00154448 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [fastrpc_probe, fastrpc_nsp_status_show, fastrpc_hibernation_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00154450 size=1
// signature: undefined sysfs_create_group(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00154458 size=1
// signature: undefined of_find_property(void)
// callers: [fastrpc_probe, fastrpc_setup_service_locator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00154460 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00154468 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00154470 size=1
// signature: undefined of_get_property(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00154478 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00154480 size=1
// signature: undefined of_platform_populate(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00154488 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00154490 size=1
// signature: undefined devm_kmalloc(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_sgtable_attrs @ 00154498 size=1
// signature: undefined dma_get_sgtable_attrs(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_sgtable_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map_sg @ 001544a0 size=1
// signature: undefined iommu_map_sg(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map_sg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gen_pool_create @ 001544a8 size=1
// signature: undefined devm_gen_pool_create(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 001544b0 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [fastrpc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_alloc @ 001544b8 size=1
// signature: undefined pdr_handle_alloc(void)
// callers: [fastrpc_setup_service_locator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_add_lookup @ 001544c0 size=1
// signature: undefined pdr_add_lookup(void)
// callers: [fastrpc_setup_service_locator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_request @ 001544c8 size=1
// signature: undefined dev_pm_qos_remove_request(void)
// callers: [fastrpc_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 001544e8 size=1
// signature: undefined rpmsg_send(void)
// callers: [fastrpc_transport_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 001544f0 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [fastrpc_transport_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 001544f8 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [fastrpc_transport_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00154500 size=1
// signature: undefined of_property_read_string(void)
// callers: [get_cid_from_rpdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



