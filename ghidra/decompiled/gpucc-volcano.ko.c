// Decompiled by Ghidra 12.2
// Program: gpucc-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// gpu_cc_volcano_probe @ 001000dc size=380
// signature: undefined gpu_cc_volcano_probe(void)
// callers: []
//------------------------------------------------------------

ulong gpu_cc_volcano_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = qcom_cc_map(param_1,&gpu_cc_volcano_desc);
  if (uVar1 < 0xfffffffffffff001) {
    clk_lucid_evo_pll_configure(&gpu_cc_pll0,uVar1,gpu_cc_pll0_config);
    regmap_update_bits_base(uVar1,0x93a4,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x9008,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x9010,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x9064,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x93a8,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x9004,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x90cc,1,1,0,0,0);
    uVar2 = qcom_cc_really_probe(param_1,&gpu_cc_volcano_desc,uVar1);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      _dev_info(param_1 + 0x10,"Registered GPU CC clocks\n");
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to register GPU CC clocks\n");
    }
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// gpu_cc_volcano_sync_state @ 0010025c size=36
// signature: undefined gpu_cc_volcano_sync_state(void)
// callers: []
//------------------------------------------------------------

void gpu_cc_volcano_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&gpu_cc_volcano_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100284 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gpu_cc_volcano_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001002b4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gpu_cc_volcano_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// qcom_cc_map @ 00103010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 00103018 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00103020 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00103028 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103030 size=1
// signature: undefined _dev_info(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103038 size=1
// signature: undefined _dev_err(void)
// callers: [gpu_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00103040 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [gpu_cc_volcano_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



