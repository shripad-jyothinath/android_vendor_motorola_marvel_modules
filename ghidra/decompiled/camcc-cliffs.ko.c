// Decompiled by Ghidra 12.2
// Program: camcc-cliffs.ko
// Image base: 00100000

//------------------------------------------------------------
// cam_cc_cliffs_probe @ 001000e4 size=588
// signature: undefined cam_cc_cliffs_probe(void)
// callers: []
//------------------------------------------------------------

ulong cam_cc_cliffs_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = qcom_cc_map(param_1,&cam_cc_cliffs_desc);
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = qcom_cc_runtime_init(param_1,&cam_cc_cliffs_desc);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 == 0) {
      lVar1 = param_1 + 0x10;
      uVar3 = __pm_runtime_resume(lVar1,4);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        clk_lucid_evo_pll_configure(&cam_cc_pll0,uVar2,cam_cc_pll0_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll1,uVar2,cam_cc_pll1_config);
        clk_rivian_evo_pll_configure(&cam_cc_pll2,uVar2,cam_cc_pll2_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll3,uVar2,cam_cc_pll3_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll4,uVar2,cam_cc_pll4_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll5,uVar2,cam_cc_pll5_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll6,uVar2,cam_cc_pll6_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll7,uVar2,cam_cc_pll7_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll8,uVar2,cam_cc_pll8_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll9,uVar2,cam_cc_pll9_config);
        regmap_update_bits_base(uVar2,0x13318,1,1,0,0,0);
        regmap_update_bits_base(uVar2,0x13314,1,1,0,0,0);
        regmap_update_bits_base(uVar2,0x132ec,1,1,0,0,0);
        regmap_update_bits_base(uVar2,0x13308,1,1,0,0,0);
        uVar2 = qcom_cc_really_probe(param_1,&cam_cc_cliffs_desc,uVar2);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == 0) {
          __pm_runtime_idle(lVar1,4);
          _dev_info(lVar1,"Registered CAM CC clocks\n");
        }
        else {
          _dev_err(lVar1,"Failed to register CAM CC clocks\n");
        }
      }
    }
  }
  else {
    uVar4 = uVar2 & 0xffffffff;
  }
  return uVar4;
}



//------------------------------------------------------------
// cam_cc_cliffs_sync_state @ 00100334 size=36
// signature: undefined cam_cc_cliffs_sync_state(void)
// callers: []
//------------------------------------------------------------

void cam_cc_cliffs_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&cam_cc_cliffs_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 0010035c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cam_cc_cliffs_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010038c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cam_cc_cliffs_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010d000 size=1
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
// platform_driver_unregister @ 0010d008 size=1
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
// qcom_cc_map @ 0010d010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 0010d018 size=1
// signature: undefined qcom_cc_runtime_init(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_runtime_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010d020 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 0010d028 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_rivian_evo_pll_configure @ 0010d030 size=1
// signature: undefined clk_rivian_evo_pll_configure(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_rivian_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010d038 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 0010d040 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010d048 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d050 size=1
// signature: undefined _dev_info(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d058 size=1
// signature: undefined _dev_err(void)
// callers: [cam_cc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 0010d060 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [cam_cc_cliffs_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



