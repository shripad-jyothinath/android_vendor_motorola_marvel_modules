// Decompiled by Ghidra 12.2
// Program: stub_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_stub_dev_probe @ 001000d4 size=52
// signature: undefined msm_stub_dev_probe(void)
// callers: []
//------------------------------------------------------------

void msm_stub_dev_probe(long param_1)

{
  snd_soc_register_component(param_1 + 0x10,&soc_msm_stub,&msm_stub_dais,2);
  return;
}



//------------------------------------------------------------
// msm_stub_dev_remove @ 0010010c size=36
// signature: undefined msm_stub_dev_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_stub_dev_remove(long param_1)

{
  snd_soc_unregister_component(param_1 + 0x10);
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100134 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_stub_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100164 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_stub_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00101000 size=1
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
// platform_driver_unregister @ 00101008 size=1
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
// snd_soc_register_component @ 00101010 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [msm_stub_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 00101018 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [msm_stub_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



