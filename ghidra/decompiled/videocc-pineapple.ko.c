// Decompiled by Ghidra 12.2
// Program: videocc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// video_cc_pineapple_probe @ 001000e4 size=812
// signature: undefined video_cc_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong video_cc_pineapple_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  char *__s1;
  ulong uVar5;
  undefined8 uVar6;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = qcom_cc_map(param_1,&video_cc_pineapple_desc);
  if (uVar3 < 0xfffffffffffff001) {
    uVar4 = qcom_cc_runtime_init(param_1,&video_cc_pineapple_desc);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      lVar1 = param_1 + 0x10;
      uVar4 = __pm_runtime_resume(lVar1,4);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        clk_lucid_evo_pll_configure(&video_cc_pll0,uVar3,video_cc_pll0_config);
        clk_lucid_evo_pll_configure(&video_cc_pll1,uVar3,video_cc_pll1_config);
        local_3c = 0;
        __s1 = (char *)of_get_property(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_3c);
        if ((__s1 == (char *)0x0) || (local_3c < 1)) {
          uVar5 = 0xffffffea;
        }
        else {
          iVar2 = strcmp(__s1,"qcom,pineapple-videocc-v2");
          if (iVar2 == 0) {
            uVar6 = 0x8150;
            PTR_ftbl_video_cc_mvs0_clk_src_00101bc8 = ftbl_video_cc_mvs0_clk_src_pineapple_v2;
            *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x20) = 900000000;
            PTR_ftbl_video_cc_mvs1_clk_src_001020a8 = ftbl_video_cc_mvs1_clk_src_pineapple_v2;
            *(undefined8 *)(PTR__compoundliteral_32_00102108 + 0x20) = 1110000000;
          }
          else {
            iVar2 = strcmp(__s1,"qcom,cliffs-videocc");
            uVar6 = 0x8150;
            if (iVar2 == 0) {
              clk_lucid_evo_pll_configure(&video_cc_pll0,uVar3,video_cc_pll0_config_cliffs);
              PTR_ftbl_video_cc_mvs0_clk_src_00101bc8 = ftbl_video_cc_mvs0_clk_src_cliffs;
              *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x18) = 576000000;
              *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x20) = 720000000;
              *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x28) = 0x3c706980;
              *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x38) = 0x41722680;
              *(undefined8 *)(PTR__compoundliteral_10_00101c28 + 0x40) = 0x4f64b500;
              video_cc_mvs0_shift_clk = 0x814400008144;
              DAT_00101d70 = 0x8144;
              video_cc_mvs0c_shift_clk = 0x814800008148;
              DAT_00101f78 = 0x8148;
              _DAT_00102250 = 0x814c;
              video_cc_mvs1_shift_clk = 0x814c0000814c;
              _DAT_00102458 = 0x8150;
              uVar6 = 0x8140;
              video_cc_mvs1c_shift_clk = 0x815000008150;
              video_cc_sleep_clk_src = 0x8128;
            }
          }
          regmap_update_bits_base(uVar3,0x80f4,1,1,0,0,0);
          regmap_update_bits_base(uVar3,0x8124,1,1,0,0,0);
          regmap_update_bits_base(uVar3,uVar6,1,1,0,0,0);
          uVar3 = qcom_cc_really_probe(param_1,&video_cc_pineapple_desc,uVar3);
          uVar5 = uVar3 & 0xffffffff;
          if ((int)uVar3 == 0) {
            __pm_runtime_idle(lVar1,4);
            _dev_info(lVar1,"Registered VIDEO CC clocks\n");
          }
          else {
            _dev_err(lVar1,"Failed to register VIDEO CC clocks\n");
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
// video_cc_pineapple_sync_state @ 00100414 size=36
// signature: undefined video_cc_pineapple_sync_state(void)
// callers: []
//------------------------------------------------------------

void video_cc_pineapple_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&video_cc_pineapple_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 0010043c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&video_cc_pineapple_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010046c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&video_cc_pineapple_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// qcom_cc_map @ 00104010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 00104018 size=1
// signature: undefined qcom_cc_runtime_init(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_runtime_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00104020 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 00104028 size=1
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_lucid_evo_pll_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00104030 size=1
// signature: undefined of_get_property(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104038 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00104040 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00104048 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00104050 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00104058 size=1
// signature: undefined _dev_info(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104060 size=1
// signature: undefined _dev_err(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [video_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00104070 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [video_cc_pineapple_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



