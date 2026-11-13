// Decompiled by Ghidra 12.2
// Program: mpam.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_mpam_set_cache_portion @ 0010012c size=164
// signature: undefined qcom_mpam_set_cache_portion(void)
// callers: []
//------------------------------------------------------------

void qcom_mpam_set_cache_portion(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined8 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = param_1;
  uStack_24 = param_2;
  local_20 = param_3;
  if (ops == (undefined8 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10019c);
      (*pcVar2)();
    }
    uVar3 = (*(code *)*ops)(ph,&local_28,0x4d50414d4558544e,1,0x10);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_mpam_get_cache_portion @ 001001d4 size=192
// signature: undefined qcom_mpam_get_cache_portion(void)
// callers: []
//------------------------------------------------------------

void qcom_mpam_get_cache_portion(ulong param_1,ulong *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = param_1 & 0xffffffff;
  if (ops == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100250);
      (*pcVar2)();
    }
    uVar3 = (**(code **)(ops + 8))(ph,&local_30,0x4d50414d4558544e,1,4,8);
    if ((int)uVar3 == 0) {
      *param_2 = local_30;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mpam_dev_probe @ 00100298 size=208
// signature: undefined mpam_dev_probe(void)
// callers: []
//------------------------------------------------------------

ulong mpam_dev_probe(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  
  uVar1 = get_qcom_scmi_device();
  sdev = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    pcVar3 = *(code **)(*(long *)(uVar1 + 0x3a0) + 0x18);
    if (*(int *)(pcVar3 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100304);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(uVar1,0x80,&ph);
    if (uVar2 < 0xfffffffffffff001) {
      uVar1 = 0;
      ops = uVar2;
    }
    else {
      ops = 0;
      _dev_err(param_1 + 0x10,"Error getting vendor protocol ops: %d\n",uVar2 & 0xffffffff);
      uVar1 = uVar2;
    }
  }
  else if ((int)uVar1 == -0x205) {
    uVar1 = 0xfffffdfb;
  }
  else {
    _dev_err(param_1 + 0x10,"Error getting scmi_dev ret=%d\n",uVar1 & 0xffffffff);
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 001003a8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_mpam_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001003d8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_mpam_driver);
  return;
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101000 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_mpam_set_cache_portion, qcom_mpam_get_cache_portion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00101008 size=1
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
// platform_driver_unregister @ 00101010 size=1
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
// get_qcom_scmi_device @ 00101018 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [mpam_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00101020 size=1
// signature: undefined _dev_err(void)
// callers: [mpam_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



