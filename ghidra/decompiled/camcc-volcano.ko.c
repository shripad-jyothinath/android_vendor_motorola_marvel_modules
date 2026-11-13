// Decompiled by Ghidra 12.2
// Program: camcc-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// cam_cc_volcano_probe @ 001000dc size=384
// signature: undefined cam_cc_volcano_probe(void)
// callers: []
//------------------------------------------------------------

ulong cam_cc_volcano_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = qcom_cc_map(param_1,&cam_cc_volcano_desc);
  if (uVar1 < 0xfffffffffffff001) {
    clk_lucid_evo_pll_configure(&cam_cc_pll0,uVar1,cam_cc_pll0_config);
    clk_lucid_evo_pll_configure(&cam_cc_pll1,uVar1,cam_cc_pll1_config);
    clk_rivian_evo_pll_configure(&cam_cc_pll2,uVar1,cam_cc_pll2_config);
    clk_lucid_evo_pll_configure(&cam_cc_pll3,uVar1,cam_cc_pll3_config);
    clk_lucid_evo_pll_configure(&cam_cc_pll4,uVar1,cam_cc_pll4_config);
    clk_lucid_evo_pll_configure(&cam_cc_pll5,uVar1,cam_cc_pll5_config);
    clk_lucid_evo_pll_configure(&cam_cc_pll6,uVar1,cam_cc_pll6_config);
    regmap_update_bits_base(uVar1,0x25038,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x2505c,1,1,0,0,0);
    uVar2 = qcom_cc_really_probe(param_1,&cam_cc_volcano_desc,uVar1);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      _dev_info(param_1 + 0x10,"Registered CAM CC clocks\n");
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to register CAM CC clocks\n");
    }
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// cam_cc_volcano_sync_state @ 00100260 size=36
// signature: undefined cam_cc_volcano_sync_state(void)
// callers: []
//------------------------------------------------------------

void cam_cc_volcano_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&cam_cc_volcano_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100288 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cam_cc_volcano_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001002b8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cam_cc_volcano_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a000 size=1
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
// platform_driver_unregister @ 0010a008 size=1
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
// qcom_cc_map @ 0010a010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 0010a018 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_rivian_evo_pll_configure @ 0010a020 size=1
// signature: undefined clk_rivian_evo_pll_configure(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_rivian_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010a028 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 0010a030 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010a038 size=1
// signature: undefined _dev_info(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a040 size=1
// signature: undefined _dev_err(void)
// callers: [cam_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 0010a048 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [cam_cc_volcano_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



