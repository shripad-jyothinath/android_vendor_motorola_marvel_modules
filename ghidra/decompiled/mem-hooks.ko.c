// Decompiled by Ghidra 12.2
// Program: mem-hooks.ko
// Image base: 00100000

//------------------------------------------------------------
// balance_reclaim @ 0010012c size=12
// signature: undefined balance_reclaim(void)
// callers: []
//------------------------------------------------------------

void balance_reclaim(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 1;
  return;
}



//------------------------------------------------------------
// scan_abort_checks @ 0010013c size=12
// signature: undefined scan_abort_checks(void)
// callers: []
//------------------------------------------------------------

void scan_abort_checks(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 1;
  return;
}



//------------------------------------------------------------
// can_fixup_sea @ 0010014c size=32
// signature: undefined can_fixup_sea(void)
// callers: []
//------------------------------------------------------------

void can_fixup_sea(undefined8 param_1,undefined8 param_2,ulong param_3,long param_4,
                  undefined8 param_5)

{
  *(bool *)param_5 =
       (*(ulong *)(param_4 + 0x108) & 0xf) != 0 && (param_3 & 0xfc000000) != 0x84000000;
  return;
}



//------------------------------------------------------------
// kswapd_threads_set @ 00100170 size=152
// signature: undefined kswapd_threads_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kswapd_threads_set(undefined8 param_1,undefined4 param_2,undefined1 *param_3,uint param_4)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  
  *param_3 = 1;
  uVar2 = (ulong)kswapd_threads;
  if ((param_4 & 1) == 0) {
    if (kswapd_threads != 0) {
      lVar3 = 0;
      do {
        if (lVar3 == 0x80) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100208);
          (*pcVar1)();
        }
        if (*(long *)(&DAT_00102a88 + lVar3) != 0) {
          kthread_stop();
          *(undefined8 *)(&DAT_00102a88 + lVar3) = 0;
        }
        lVar3 = lVar3 + 8;
      } while (uVar2 * 8 != lVar3);
    }
    _DAT_00102a80 = 0;
  }
  else {
    kswapd_per_node_run(param_2);
  }
  return;
}



//------------------------------------------------------------
// kswapd_per_node_run @ 00100208 size=324
// signature: undefined kswapd_per_node_run(void)
// callers: [init_module, kswapd_threads_set]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kswapd_per_node_run(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if (_DAT_00102a80 == 0) {
    uVar3 = 0;
    if (param_2 == 0) {
      return;
    }
  }
  else {
    uVar3 = 1;
    _DAT_00102a88 = _DAT_00102a80;
    if (param_2 < 2) {
      _DAT_00102a88 = _DAT_00102a80;
      return;
    }
  }
  uVar3 = uVar3 | 0x34a;
  do {
    uVar4 = uVar3 - 0x34a;
    uVar2 = kthread_create_on_node
                      (&kswapd,&contig_page_data,0xffffffff,"kswapd%d:%d",param_1,uVar4 & 0xffffffff
                      );
    if (uVar2 < 0xfffffffffffff001) {
      wake_up_process(uVar2);
      if (0xf < uVar4) {
LAB_0010034c:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100350);
        (*pcVar1)();
      }
      *(ulong *)(&contig_page_data + uVar3 * 8) = uVar2;
      if (_DAT_00102a80 == 0) {
        _DAT_00102a80 = uVar2;
      }
    }
    else {
      if (0xf < uVar4) goto LAB_0010034c;
      *(ulong *)(&contig_page_data + uVar3 * 8) = uVar2;
      if (_system_state < 3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100328);
        (*pcVar1)();
      }
      _printk(&DAT_001005de,uVar4 & 0xffffffff,param_1);
      *(undefined8 *)(&contig_page_data + uVar3 * 8) = 0;
    }
    uVar3 = uVar3 + 1;
    if (uVar3 - param_2 == 0x34a) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// init_module @ 00100354 size=268
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  uint uVar1;
  ulong uVar2;
  undefined *puVar3;
  
  if (kswapd_threads < 0x11) {
    if (1 < kswapd_threads) {
      uVar2 = tracepoint_probe_register
                        (&__tracepoint_android_vh_kswapd_per_node,kswapd_threads_set,0);
      if ((int)uVar2 != 0) {
        uVar2 = uVar2 & 0xffffffff;
        puVar3 = &DAT_0010066b;
        goto LAB_00100458;
      }
      kswapd_per_node_run(uVar2,kswapd_threads);
    }
  }
  else {
    _printk(&DAT_00100697,kswapd_threads,0x10);
  }
  uVar1 = android_rvh_probe_register
                    (&__tracepoint_android_rvh_set_balance_anon_file_reclaim,balance_reclaim,0);
  if (uVar1 == 0) {
    uVar1 = tracepoint_probe_register
                      (&__tracepoint_android_vh_scan_abort_check_wmarks,scan_abort_checks,0);
    if (uVar1 == 0) {
      uVar1 = tracepoint_probe_register(&__tracepoint_android_vh_try_fixup_sea,can_fixup_sea,0);
      uVar2 = (ulong)uVar1;
      if (uVar1 == 0) {
        return 0;
      }
      puVar3 = &DAT_00100647;
    }
    else {
      uVar2 = (ulong)uVar1;
      puVar3 = &DAT_001005b0;
    }
  }
  else {
    uVar2 = (ulong)uVar1;
    puVar3 = &DAT_00100611;
  }
LAB_00100458:
  _printk(puVar3);
  return uVar2;
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00101008 size=1
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
// android_rvh_probe_register @ 00101018 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101030 size=1
// signature: undefined _printk(void)
// callers: [init_module, kswapd_per_node_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00101040 size=1
// signature: undefined kthread_stop(void)
// callers: [kswapd_threads_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00101050 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [kswapd_per_node_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00101058 size=1
// signature: undefined wake_up_process(void)
// callers: [kswapd_per_node_run]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



