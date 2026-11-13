// Decompiled by Ghidra 12.2
// Program: videocc-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// video_cc_volcano_probe @ 001000e4 size=328
// signature: undefined video_cc_volcano_probe(void)
// callers: []
//------------------------------------------------------------

ulong video_cc_volcano_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = qcom_cc_map(param_1,&video_cc_volcano_desc);
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = qcom_cc_runtime_init(param_1,&video_cc_volcano_desc);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 == 0) {
      lVar1 = param_1 + 0x10;
      uVar3 = __pm_runtime_resume(lVar1,4);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        clk_lucid_evo_pll_configure(&video_cc_pll0,uVar2,video_cc_pll0_config);
        regmap_update_bits_base(uVar2,0x80f4,1,1,0,0,0);
        regmap_update_bits_base(uVar2,0x8140,1,1,0,0,0);
        regmap_update_bits_base(uVar2,0x8124,1,1,0,0,0);
        uVar2 = qcom_cc_really_probe(param_1,&video_cc_volcano_desc,uVar2);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == 0) {
          __pm_runtime_idle(lVar1,4);
          _dev_info(lVar1,"Registered VIDEO CC clocks\n");
        }
        else {
          _dev_err(lVar1,"Failed to register VIDEO CC clocks\n");
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
// video_cc_volcano_sync_state @ 00100230 size=36
// signature: undefined video_cc_volcano_sync_state(void)
// callers: []
//------------------------------------------------------------

void video_cc_volcano_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&video_cc_volcano_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100258 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&video_cc_volcano_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100288 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&video_cc_volcano_driver);
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
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 00103018 size=1
// signature: undefined qcom_cc_runtime_init(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_runtime_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00103020 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 00103028 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00103030 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00103038 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00103040 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103048 size=1
// signature: undefined _dev_info(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103050 size=1
// signature: undefined _dev_err(void)
// callers: [video_cc_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00103058 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [video_cc_volcano_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



