// Decompiled by Ghidra 12.2
// Program: dynpf_scmi.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_dynpf_probe @ 00100164 size=264
// signature: undefined qcom_dynpf_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_dynpf_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  
  uVar2 = get_qcom_scmi_device();
  sdev = uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    pcVar3 = *(code **)(*(long *)(uVar2 + 0x3a0) + 0x18);
    if (*(int *)(pcVar3 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1001d0);
      (*pcVar3)();
    }
    ops = (*pcVar3)(uVar2,0x80,&ph);
    if (ops < 0xfffffffffffff001) {
      iVar1 = kobject_init_and_add(dynpf_kobj,dynpf_settings_ktype,__dev_err,"dynpf");
      if (iVar1 < 0) {
        _dev_err(param_1 + 0x10,"failed to init dynpf kobj: %d\n",iVar1);
        kobject_put(dynpf_kobj);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = ops & 0xffffffff;
      ops = 0;
    }
  }
  else if ((int)uVar2 == -0x205) {
    uVar2 = 0xfffffdfb;
  }
  else {
    _dev_err(param_1 + 0x10,"Error getting scmi_dev ret = %d\n",uVar2 & 0xffffffff);
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// attr_show @ 00100270 size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10029c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 001002b8 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5800598) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1002e4);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_enable_dynpf @ 00100300 size=196
// signature: undefined show_enable_dynpf(void)
// callers: []
//------------------------------------------------------------

long show_enable_dynpf(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100374);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(ops + 8))(ph,&local_2c,0x53434d495f444750,1,0,4);
  if (-1 < iVar3) {
    iVar3 = scnprintf(param_3,0x1000,&DAT_00100758,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// store_enable_dynpf @ 001003c8 size=200
// signature: undefined store_enable_dynpf(void)
// callers: []
//------------------------------------------------------------

void store_enable_dynpf(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10044c);
      (*pcVar2)();
    }
    iVar3 = (*(code *)*ops)(ph,&local_2c,0x53434d495f444750,1,4);
    lVar4 = (long)iVar3;
    if (-1 < iVar3) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100494 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&dynpf_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001004c4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&dynpf_driver);
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
// get_qcom_scmi_device @ 00102010 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [qcom_dynpf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00102020 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_dynpf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102028 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_dynpf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00102030 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_dynpf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102038 size=1
// signature: undefined scnprintf(void)
// callers: [show_enable_dynpf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [show_enable_dynpf, store_enable_dynpf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00102048 size=1
// signature: undefined kstrtouint(void)
// callers: [store_enable_dynpf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



