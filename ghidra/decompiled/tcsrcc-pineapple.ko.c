// Decompiled by Ghidra 12.2
// Program: tcsrcc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// tcsr_cc_pineapple_probe @ 001000dc size=272
// signature: undefined tcsr_cc_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

ulong tcsr_cc_pineapple_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  char *__s1;
  ulong uVar4;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = qcom_cc_map(param_1,&tcsr_cc_pineapple_desc);
  if (uVar3 < 0xfffffffffffff001) {
    local_2c = 0;
    __s1 = (char *)of_get_property(*(undefined8 *)(param_1 + 0x2f8),"compatible",&local_2c);
    if ((__s1 == (char *)0x0) || (local_2c < 1)) {
      uVar3 = 0xffffffea;
    }
    else {
      iVar2 = strcmp(__s1,"qcom,volcano-tcsrcc");
      if (iVar2 == 0) {
        tcsr_ufs_clkref_en._4_4_ = 0xb1118;
        tcsr_ufs_clkref_en._64_4_ = 0xb1118;
        tcsr_cc_pineapple_clocks._32_8_ = 0;
        tcsr_cc_pineapple_clocks._40_8_ = 0;
      }
      uVar4 = qcom_cc_really_probe(param_1,&tcsr_cc_pineapple_desc,uVar3);
      uVar3 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        _dev_info(param_1 + 0x10,"Registered TCSR CC clocks\n");
      }
      else {
        _dev_err(param_1 + 0x10,"Failed to register TCSR CC clocks\n");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// tcsr_cc_pineapple_sync_state @ 001001f0 size=36
// signature: undefined tcsr_cc_pineapple_sync_state(void)
// callers: []
//------------------------------------------------------------

void tcsr_cc_pineapple_sync_state(undefined8 param_1)

{
  qcom_cc_sync_state(param_1,&tcsr_cc_pineapple_desc);
  return;
}



//------------------------------------------------------------
// init_module @ 00100218 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&tcsr_cc_pineapple_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100248 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&tcsr_cc_pineapple_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// qcom_cc_map @ 00102010 size=1
// signature: undefined qcom_cc_map(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00102018 size=1
// signature: undefined of_get_property(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102020 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00102028 size=1
// signature: undefined qcom_cc_really_probe(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_really_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102030 size=1
// signature: undefined _dev_info(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [tcsr_cc_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00102048 size=1
// signature: undefined qcom_cc_sync_state(void)
// callers: [tcsr_cc_pineapple_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_cc_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



