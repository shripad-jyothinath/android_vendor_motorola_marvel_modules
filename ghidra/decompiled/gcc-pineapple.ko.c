// Decompiled by Ghidra 12.2
// Program: gcc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// gcc_pineapple_probe @ 001000dc size=524
// signature: undefined gcc_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

ulong gcc_pineapple_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = qcom_cc_map(param_1,&gcc_pineapple_desc);
  if (uVar1 < 0xfffffffffffff001) {
    regmap_update_bits_base(uVar1,0x26004,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x26028,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x63020,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x27004,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x27018,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x71004,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x32004,1,1,0,0,0);
    regmap_update_bits_base(uVar1,0x32030,1,1,0,0,0);
    uVar2 = qcom_cc_register_rcg_dfs(uVar1,&gcc_dfs_clocks,0x11);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      regmap_update_bits_base(uVar1,gcc_ufs_phy_ice_core_clk._4_4_,0x4000,0x4000,0,0,0);
      regmap_write(uVar1,0x52150,0);
      uVar1 = qcom_cc_really_probe(param_1,&gcc_pineapple_desc,uVar1);
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
// gcc_pineapple_sync_state @ 001002ec size=36
// signature: undefined gcc_pineapple_sync_state(void)
// callers: []
//------------------------------------------------------------

void gcc_pineapple_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&gcc_pineapple_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100314 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gcc_pineapple_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100344 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gcc_pineapple_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00111000 size=1
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
// platform_driver_unregister @ 00111008 size=1
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
// qcom_cc_map @ 00111010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00111018 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_register_rcg_dfs @ 00111020 size=1
// signature: undefined qcom_cc_register_rcg_dfs(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_register_rcg_dfs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00111028 size=1
// signature: undefined regmap_write(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00111030 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00111038 size=1
// signature: undefined _dev_info(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00111040 size=1
// signature: undefined _dev_err(void)
// callers: [gcc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00111048 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [gcc_pineapple_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



