// Decompiled by Ghidra 12.2
// Program: camcc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// cam_cc_pineapple_probe @ 001000e4 size=672
// signature: undefined cam_cc_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

ulong cam_cc_pineapple_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  char *__s1;
  ulong uVar5;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = qcom_cc_map(param_1,&cam_cc_pineapple_desc);
  if (uVar3 < 0xfffffffffffff001) {
    uVar4 = qcom_cc_runtime_init(param_1,&cam_cc_pineapple_desc);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      lVar1 = param_1 + 0x10;
      uVar4 = __pm_runtime_resume(lVar1,4);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        clk_lucid_evo_pll_configure(&cam_cc_pll0,uVar3,cam_cc_pll0_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll1,uVar3,cam_cc_pll1_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll10,uVar3,cam_cc_pll10_config);
        clk_rivian_evo_pll_configure(&cam_cc_pll2,uVar3,cam_cc_pll2_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll3,uVar3,cam_cc_pll3_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll4,uVar3,cam_cc_pll4_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll5,uVar3,cam_cc_pll5_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll6,uVar3,cam_cc_pll6_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll7,uVar3,cam_cc_pll7_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll8,uVar3,cam_cc_pll8_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll9,uVar3,cam_cc_pll9_config);
        local_3c = 0;
        __s1 = (char *)of_get_property(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_3c);
        if ((__s1 == (char *)0x0) || (local_3c < 1)) {
          uVar5 = 0xffffffea;
        }
        else {
          iVar2 = strcmp(__s1,"qcom,pineapple-camcc-v2");
          if (iVar2 == 0) {
            clk_lucid_evo_pll_configure(&cam_cc_pll1,uVar3,cam_cc_pll1_config_pineapple_v2);
            PTR_ftbl_cam_cc_ipe_nps_clk_src_00108c10 = ftbl_cam_cc_ipe_nps_clk_src_pineapple_v2;
            *(undefined8 *)(PTR__compoundliteral_285_00108c70 + 0x20) = 475000000;
          }
          regmap_update_bits_base(uVar3,0x132ec,1,1,0,0,0);
          uVar3 = qcom_cc_really_probe(param_1,&cam_cc_pineapple_desc,uVar3);
          uVar5 = uVar3 & 0xffffffff;
          if ((int)uVar3 == 0) {
            __pm_runtime_idle(lVar1,4);
            _dev_info(lVar1,"Registered CAM CC clocks\n");
          }
          else {
            _dev_err(lVar1,"Failed to register CAM CC clocks\n");
          }
        }
      }
    }
  }
  else {
    uVar5 = uVar3 & 0xffffffff;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// cam_cc_pineapple_sync_state @ 00100388 size=36
// signature: undefined cam_cc_pineapple_sync_state(void)
// callers: []
//------------------------------------------------------------

void cam_cc_pineapple_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&cam_cc_pineapple_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 001003b0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cam_cc_pineapple_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001003e0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cam_cc_pineapple_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010f000 size=1
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
// platform_driver_unregister @ 0010f008 size=1
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
// qcom_cc_map @ 0010f010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 0010f018 size=1
// signature: undefined qcom_cc_runtime_init(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_runtime_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010f020 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 0010f028 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_rivian_evo_pll_configure @ 0010f030 size=1
// signature: undefined clk_rivian_evo_pll_configure(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_rivian_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0010f038 size=1
// signature: undefined of_get_property(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010f040 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010f048 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 0010f050 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010f058 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010f060 size=1
// signature: undefined _dev_info(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010f068 size=1
// signature: undefined _dev_err(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010f070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cam_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 0010f078 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [cam_cc_pineapple_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



