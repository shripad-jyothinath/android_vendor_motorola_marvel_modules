// Decompiled by Ghidra 12.2
// Program: dispcc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// disp_cc_pineapple_probe @ 001000e4 size=492
// signature: undefined disp_cc_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

ulong disp_cc_pineapple_probe(long param_1)

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
  uVar3 = qcom_cc_map(param_1,&disp_cc_pineapple_desc);
  if (uVar3 < 0xfffffffffffff001) {
    uVar4 = qcom_cc_runtime_init(param_1,&disp_cc_pineapple_desc);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      lVar1 = param_1 + 0x10;
      uVar4 = __pm_runtime_resume(lVar1,4);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        clk_lucid_evo_pll_configure(&disp_cc_pll0,uVar3,disp_cc_pll0_config);
        clk_lucid_evo_pll_configure(&disp_cc_pll1,uVar3,disp_cc_pll1_config);
        local_3c = 0;
        __s1 = (char *)of_get_property(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_3c);
        if ((__s1 == (char *)0x0) || (local_3c < 1)) {
          uVar5 = 0xffffffea;
        }
        else {
          iVar2 = strcmp(__s1,"qcom,cliffs-dispcc");
          if (iVar2 == 0) {
            PTR_ftbl_disp_cc_mdss_mdp_clk_src_001056c0 = ftbl_disp_cc_mdss_mdp_clk_src_cliffs;
            *(undefined8 *)(PTR__compoundliteral_207_00105720 + 0x18) = 155000000;
            *(undefined8 *)(PTR__compoundliteral_207_00105720 + 0x28) = 342000000;
            *(undefined8 *)(PTR__compoundliteral_207_00105720 + 0x50) = 600000000;
          }
          regmap_update_bits_base(uVar3,0xf000,0x10,0x10,0,0,0);
          regmap_update_bits_base(uVar3,0xe054,1,1,0,0,0);
          uVar3 = qcom_cc_really_probe(param_1,&disp_cc_pineapple_desc,uVar3);
          uVar5 = uVar3 & 0xffffffff;
          if ((int)uVar3 == 0) {
            __pm_runtime_idle(lVar1,4);
            _dev_info(lVar1,"Registered DISP CC clocks\n");
          }
          else {
            _dev_err(lVar1,"Failed to register DISP CC clocks\n");
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
// disp_cc_pineapple_sync_state @ 001002d4 size=36
// signature: undefined disp_cc_pineapple_sync_state(void)
// callers: []
//------------------------------------------------------------

void disp_cc_pineapple_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&disp_cc_pineapple_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 001002fc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&disp_cc_pineapple_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010032c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&disp_cc_pineapple_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00109000 size=1
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
// platform_driver_unregister @ 00109008 size=1
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
// qcom_cc_map @ 00109010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 00109018 size=1
// signature: undefined qcom_cc_runtime_init(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_runtime_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00109020 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 00109028 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00109030 size=1
// signature: undefined of_get_property(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00109038 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00109040 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00109048 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00109050 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00109058 size=1
// signature: undefined _dev_info(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109060 size=1
// signature: undefined _dev_err(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [disp_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00109070 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [disp_cc_pineapple_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



