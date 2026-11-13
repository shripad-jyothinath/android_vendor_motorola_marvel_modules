// Decompiled by Ghidra 12.2
// Program: qti_thermal_vendor_hooks.ko
// Image base: 00100000

//------------------------------------------------------------
// qti_thermal_pm_notify @ 0010008c size=12
// signature: undefined qti_thermal_pm_notify(void)
// callers: []
//------------------------------------------------------------

void qti_thermal_pm_notify(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = 1;
  return;
}



//------------------------------------------------------------
// init_module @ 0010009c size=76
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  int iVar1;
  
  iVar1 = tracepoint_probe_register
                    (&__tracepoint_android_vh_thermal_pm_notify_suspend,qti_thermal_pm_notify,0);
  if (iVar1 != 0) {
    _printk(&DAT_001001ee,iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001000ec size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_thermal_pm_notify_suspend,qti_thermal_pm_notify,0);
  return;
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
// _printk @ 00101010 size=1
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
// tracepoint_probe_unregister @ 00101018 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



