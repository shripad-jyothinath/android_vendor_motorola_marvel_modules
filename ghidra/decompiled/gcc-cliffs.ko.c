// Decompiled by Ghidra 12.2
// Program: gcc-cliffs.ko
// Image base: 00100000

//------------------------------------------------------------
// gcc_cliffs_probe @ 001000dc size=464
// signature: undefined gcc_cliffs_probe(void)
// callers: []
//------------------------------------------------------------

ulong gcc_cliffs_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = qcom_cc_map(param_1,&gcc_cliffs_desc);
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = qcom_cc_register_rcg_dfs(uVar1,&gcc_dfs_clocks,0x10);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      regmap_update_bits_base(uVar1,0x26004,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x26028,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x2602c,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x27004,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x27018,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x71004,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x32004,1,1,0,0,0);
      regmap_update_bits_base(uVar1,0x32030,1,1,0,0,0);
      uVar1 = qcom_cc_really_probe(param_1,&gcc_cliffs_desc,uVar1);
      uVar3 = uVar1 & 0xffffffff;
      if ((int)uVar1 == 0) {
        _dev_info(param_1 + 0x10,"Registered GCC clocks\n");
      }
      else {
        _dev_err(param_1 + 0x10,"Failed to register GCC clocks\n");
      }
    }
  }
  else {
    uVar3 = uVar1 & 0xffffffff;
  }
  return uVar3;
}



//------------------------------------------------------------
// gcc_cliffs_sync_state @ 001002b0 size=36
// signature: undefined gcc_cliffs_sync_state(void)
// callers: []
//------------------------------------------------------------

void gcc_cliffs_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&gcc_cliffs_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 001002d8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gcc_cliffs_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100308 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gcc_cliffs_driver);
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
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_register_rcg_dfs @ 0010d018 size=1
// signature: undefined qcom_cc_register_rcg_dfs(void)
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_register_rcg_dfs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010d020 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 0010d028 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d030 size=1
// signature: undefined _dev_info(void)
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d038 size=1
// signature: undefined _dev_err(void)
// callers: [gcc_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 0010d040 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [gcc_cliffs_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



