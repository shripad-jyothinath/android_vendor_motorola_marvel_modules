// Decompiled by Ghidra 12.2
// Program: q6_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_aud_evt_register_client @ 001001cc size=40
// signature: undefined msm_aud_evt_register_client(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_register_client(undefined8 param_1)

{
  atomic_notifier_chain_register(&msm_aud_evt_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// msm_aud_evt_unregister_client @ 001001f8 size=40
// signature: undefined msm_aud_evt_unregister_client(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_unregister_client(undefined8 param_1)

{
  atomic_notifier_chain_unregister(&msm_aud_evt_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// msm_aud_evt_notifier_call_chain @ 00100224 size=44
// signature: undefined msm_aud_evt_notifier_call_chain(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_notifier_call_chain(undefined8 param_1,undefined8 param_2)

{
  atomic_notifier_call_chain(&msm_aud_evt_notifier_list,param_1,param_2);
  return;
}



//------------------------------------------------------------
// msm_aud_evt_blocking_register_client @ 00100254 size=40
// signature: undefined msm_aud_evt_blocking_register_client(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_blocking_register_client(undefined8 param_1)

{
  blocking_notifier_chain_register(&msm_aud_evt_blocking_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// msm_aud_evt_blocking_unregister_client @ 00100280 size=40
// signature: undefined msm_aud_evt_blocking_unregister_client(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_blocking_unregister_client(undefined8 param_1)

{
  blocking_notifier_chain_unregister(&msm_aud_evt_blocking_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// msm_aud_evt_blocking_notifier_call_chain @ 001002ac size=44
// signature: undefined msm_aud_evt_blocking_notifier_call_chain(void)
// callers: []
//------------------------------------------------------------

void msm_aud_evt_blocking_notifier_call_chain(undefined8 param_1,undefined8 param_2)

{
  blocking_notifier_call_chain(&msm_aud_evt_blocking_notifier_list,param_1,param_2);
  return;
}



//------------------------------------------------------------
// init_module @ 00100404 size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00100410 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00101000 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [msm_aud_evt_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00101008 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [msm_aud_evt_unregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_call_chain @ 00101010 size=1
// signature: undefined atomic_notifier_call_chain(void)
// callers: [msm_aud_evt_notifier_call_chain]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00101018 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [msm_aud_evt_blocking_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00101020 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [msm_aud_evt_blocking_unregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00101028 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [msm_aud_evt_blocking_notifier_call_chain]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



