// Decompiled by Ghidra 12.2
// Program: msm_show_epoch.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_show_suspend_epoch_val @ 001000a4 size=36
// signature: undefined msm_show_suspend_epoch_val(void)
// callers: []
//------------------------------------------------------------

void msm_show_suspend_epoch_val(void)

{
  _printk(&DAT_00100228);
  return;
}



//------------------------------------------------------------
// msm_show_resume_epoch_val @ 001000cc size=36
// signature: undefined msm_show_resume_epoch_val(void)
// callers: []
//------------------------------------------------------------

void msm_show_resume_epoch_val(void)

{
  _printk(&DAT_00100210);
  return;
}



//------------------------------------------------------------
// init_module @ 001000f4 size=76
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  tracepoint_probe_register
            (&__tracepoint_android_vh_show_suspend_epoch_val,msm_show_suspend_epoch_val,0);
  tracepoint_probe_register
            (&__tracepoint_android_vh_show_resume_epoch_val,msm_show_resume_epoch_val,0);
  return 0;
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
// _printk @ 00101018 size=1
// signature: undefined _printk(void)
// callers: [msm_show_resume_epoch_val, msm_show_suspend_epoch_val]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



