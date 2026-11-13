// Decompiled by Ghidra 12.2
// Program: moto_mmap_fault.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_moto_disable_fault_around @ 001001bc size=116
// signature: undefined __traceiter_moto_disable_fault_around(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_moto_disable_fault_around(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001009c8;
  plVar2 = DAT_001009c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x3c50a1b9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10020c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_moto_disable_fault_around @ 00100234 size=196
// signature: undefined trace_event_raw_event_moto_disable_fault_around(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_moto_disable_fault_around
               (long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) &&
     (lVar3 = trace_event_buffer_reserve(&local_58,param_1,0x28), lVar3 != 0)) {
    lVar2 = sp_el0;
    uVar5 = *(undefined8 *)(lVar2 + 0x850);
    *(undefined8 *)(lVar3 + 8) = *(undefined8 *)(lVar2 + 0x848);
    *(undefined8 *)(lVar3 + 0x10) = uVar5;
    uVar1 = *(undefined4 *)(lVar2 + 0x630);
    *(undefined8 *)(lVar3 + 0x20) = param_2;
    *(undefined4 *)(lVar3 + 0x18) = uVar1;
    *(undefined4 *)(lVar3 + 0x1c) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_moto_disable_fault_around @ 001002fc size=272
// signature: undefined perf_trace_moto_disable_fault_around(void)
// callers: []
//------------------------------------------------------------

void perf_trace_moto_disable_fault_around(long param_1,undefined8 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar5 = perf_trace_buf_alloc(0x2c,&local_50,&local_54), lVar5 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    lVar4 = sp_el0;
    uVar6 = *(undefined8 *)(lVar4 + 0x850);
    *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(lVar4 + 0x848);
    *(undefined8 *)(lVar5 + 0x10) = uVar6;
    uVar3 = *(undefined4 *)(lVar4 + 0x630);
    *(undefined8 *)(lVar5 + 0x20) = param_2;
    *(undefined4 *)(lVar5 + 0x18) = uVar3;
    *(undefined4 *)(lVar5 + 0x1c) = param_3;
    perf_trace_run_bpf_submit(lVar5,0x2c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_moto_disable_fault_around @ 00100410 size=32
// signature: undefined __bpf_trace_moto_disable_fault_around(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_moto_disable_fault_around(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// trace_raw_output_moto_disable_fault_around @ 00100434 size=108
// signature: undefined trace_raw_output_moto_disable_fault_around(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_moto_disable_fault_around(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"disable_fault_around comm=%s pid=%d prio=%d address=%#lx\n",
                       lVar2 + 8,*(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c),
                       *(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// adjust_alloc_flags @ 001004a4 size=40
// signature: undefined adjust_alloc_flags(void)
// callers: []
//------------------------------------------------------------

void adjust_alloc_flags(undefined8 param_1,uint param_2,uint *param_3)

{
  if ((8 < param_2) && (param_3 != (uint *)0x0)) {
    *param_3 = *param_3 & 0xfffe73ff | 0x10000;
  }
  return;
}



//------------------------------------------------------------
// tune_mmap_readaround @ 001004d0 size=68
// signature: undefined tune_mmap_readaround(void)
// callers: []
//------------------------------------------------------------

void tune_mmap_readaround
               (undefined8 param_1,undefined8 param_2,long param_3,long *param_4,int *param_5,
               int *param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = max_ra_pages;
  iVar1 = max_ra_pages;
  if (max_ra_pages < 0) {
    iVar1 = max_ra_pages + 1;
  }
  param_3 = param_3 - (iVar1 >> 1);
  if (param_3 < 1) {
    param_3 = 0;
  }
  *param_4 = param_3;
  *param_5 = iVar2;
  iVar1 = max_ra_pages + 3;
  if (-1 < max_ra_pages) {
    iVar1 = max_ra_pages;
  }
  *param_6 = iVar1 >> 2;
  return;
}



//------------------------------------------------------------
// init_module @ 00100520 size=168
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 init_module(void)

{
  int iVar1;
  undefined4 uVar2;
  
  ramsize_GB = (int)(__totalram_pages >> 0x12) + 1;
  if ((max_ra_pages == -1) && (max_ra_pages = 8, 7 < ramsize_GB)) {
    max_ra_pages = 0x10;
  }
  tracepoint_probe_register(&__tracepoint_android_vh_adjust_alloc_flags,adjust_alloc_flags,0);
  _printk(&DAT_00100ac3,ramsize_GB);
  iVar1 = tracepoint_probe_register
                    (&__tracepoint_android_vh_tune_mmap_readaround,tune_mmap_readaround,0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}



//------------------------------------------------------------
// cleanup_module @ 001005cc size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_adjust_alloc_flags,adjust_alloc_flags,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_tune_mmap_readaround,tune_mmap_readaround,0);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00102000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00102008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00102010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_moto_disable_fault_around, trace_event_raw_event_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00102020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00102028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00102030 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102048 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102050 size=1
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
// tracepoint_probe_unregister @ 00102060 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00102068 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00102070 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00102078 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_moto_disable_fault_around]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



