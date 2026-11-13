// Decompiled by Ghidra 12.2
// Program: watchdogtest.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 00100154 size=128
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  dbgfs_fire_softlockup =
       debugfs_create_file("fire_softlockup_reset",0x80,0,0,&fire_softlockup_reset_fops);
  dbgfs_fire_watchdog =
       debugfs_create_file("fire_watchdog_reset",0x80,0,0,&fire_watchdog_reset_fops);
  trigger_wdog_bite = &qcom_wdt_trigger_bite;
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001001d8 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (dbgfs_fire_softlockup != 0) {
    debugfs_remove();
  }
  if (dbgfs_fire_watchdog != 0) {
    debugfs_remove();
  }
  return;
}



//------------------------------------------------------------
// fire_softlockup_reset_fops_open @ 00100214 size=48
// signature: undefined fire_softlockup_reset_fops_open(void)
// callers: []
//------------------------------------------------------------

void fire_softlockup_reset_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,0,fire_softlockup_reset_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// fire_softlockup_reset_set @ 00100248 size=56
// signature: undefined fire_softlockup_reset_set(void)
// callers: []
//------------------------------------------------------------

void fire_softlockup_reset_set(void)

{
  long lVar1;
  
  _printk(&DAT_001004e4);
  _printk(&DAT_00100510);
  lVar1 = sp_el0;
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



//------------------------------------------------------------
// fire_watchdog_reset_fops_open @ 00100284 size=48
// signature: undefined fire_watchdog_reset_fops_open(void)
// callers: []
//------------------------------------------------------------

void fire_watchdog_reset_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,0,fire_watchdog_reset_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// fire_watchdog_reset_set @ 001002b8 size=172
// signature: undefined fire_watchdog_reset_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fire_watchdog_reset_set(void)

{
  code *pcVar1;
  
  _printk(&DAT_001004ba);
  _printk(&DAT_00100510);
  if (trigger_wdog_bite == (code *)0x0) {
    wdt_timeout_complete = 0;
    __init_swait_queue_head(&DAT_00100450,"&x->wait",&init_completion___key);
    queue_work_on(0,_system_wq,&wdt_timeout_work_struct);
    wait_for_completion(&wdt_timeout_complete);
  }
  else {
    if (*(int *)(trigger_wdog_bite + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100304);
      (*pcVar1)();
    }
    (*trigger_wdog_bite)();
  }
  return 0;
}



//------------------------------------------------------------
// wdt_timeout_work @ 00100368 size=16
// signature: undefined wdt_timeout_work(void)
// callers: []
//------------------------------------------------------------

void wdt_timeout_work(void)

{
  ulong uVar1;
  
  uVar1 = daif;
  daif = uVar1 | 0xc0;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



//------------------------------------------------------------
// debugfs_create_file @ 00102000 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00102010 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00102018 size=1
// signature: undefined simple_attr_open(void)
// callers: [fire_watchdog_reset_fops_open, fire_softlockup_reset_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102020 size=1
// signature: undefined _printk(void)
// callers: [fire_watchdog_reset_set, fire_softlockup_reset_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00102028 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [fire_watchdog_reset_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00102038 size=1
// signature: undefined queue_work_on(void)
// callers: [fire_watchdog_reset_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 00102040 size=1
// signature: undefined wait_for_completion(void)
// callers: [fire_watchdog_reset_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



