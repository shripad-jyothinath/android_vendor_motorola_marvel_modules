// Decompiled by Ghidra 12.2
// Program: dispcc-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// disp_cc_volcano_probe @ 001000dc size=252
// signature: undefined disp_cc_volcano_probe(void)
// callers: []
//------------------------------------------------------------

ulong disp_cc_volcano_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = qcom_cc_map(param_1,&disp_cc_volcano_desc);
  if (uVar1 < 0xfffffffffffff001) {
    clk_lucid_evo_pll_configure(&disp_cc_pll0,uVar1,disp_cc_pll0_config);
    regmap_update_bits_base(uVar1,0xf000,0x10,0x10,0,0,0);
    regmap_update_bits_base(uVar1,0xe06c,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0xe04c,1,1,0,0,0);
    uVar2 = qcom_cc_really_probe(param_1,&disp_cc_volcano_desc,uVar1);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      _dev_info(param_1 + 0x10,"Registered DISP CC clocks\n");
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to register DISP CC clocks\n");
    }
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// disp_cc_volcano_sync_state @ 001001dc size=36
// signature: undefined disp_cc_volcano_sync_state(void)
// callers: []
//------------------------------------------------------------

void disp_cc_volcano_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&disp_cc_volcano_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100204 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&disp_cc_volcano_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100234 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&disp_cc_volcano_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// platform_driver_unregister @ 00105008 size=1
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
// qcom_cc_map @ 00105010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 00105018 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00105020 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00105028 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00105030 size=1
// signature: undefined _dev_info(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105038 size=1
// signature: undefined _dev_err(void)
// callers: [disp_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00105040 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [disp_cc_volcano_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



