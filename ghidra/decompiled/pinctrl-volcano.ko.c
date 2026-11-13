// Decompiled by Ghidra 12.2
// Program: pinctrl-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// volcano_pinctrl_probe @ 001000a4 size=68
// signature: undefined volcano_pinctrl_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 volcano_pinctrl_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_device_get_match_data(param_1 + 0x10);
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = msm_pinctrl_probe(param_1,lVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 001000ec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&volcano_pinctrl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010011c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&volcano_pinctrl_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010c000 size=1
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
// platform_driver_unregister @ 0010c008 size=1
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
// of_device_get_match_data @ 0010c010 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [volcano_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_pinctrl_probe @ 0010c018 size=1
// signature: undefined msm_pinctrl_probe(void)
// callers: [volcano_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_pinctrl_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



