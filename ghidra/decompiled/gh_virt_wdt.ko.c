// Decompiled by Ghidra 12.2
// Program: gh_virt_wdt.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_wdt_probe @ 0010021c size=96
// signature: undefined gh_wdt_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_wdt_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = devm_kmalloc(param_1 + 0x10,0x410,0xdc0);
  if (lVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    *(undefined ***)(lVar1 + 0x10) = &gh_wdt_ops;
    uVar2 = qcom_wdt_register(param_1,lVar1,"gh-watchdog");
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_set_wdt_bark @ 00100280 size=140
// signature: undefined gh_set_wdt_bark(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001002c0) */

undefined8 gh_set_wdt_bark(undefined8 param_1,long param_2)

{
  CallSecureMonitor(0);
  _dev_err(*(undefined8 *)(param_2 + 8),"failed to set bark time for vDOG, hret = %d ret = %d\n",
           0x86000008,0xffffffea);
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_set_wdt_bite @ 00100330 size=136
// signature: undefined gh_set_wdt_bite(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010036c) */

undefined8 gh_set_wdt_bite(undefined8 param_1,long param_2)

{
  CallSecureMonitor(0);
  _dev_err(*(undefined8 *)(param_2 + 8),"failed to set bite time for vWDOG, hret = %d ret = %d\n",
           0x86000008,0xffffffea);
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_reset_wdt @ 001003dc size=132
// signature: undefined gh_reset_wdt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100414) */

undefined8 gh_reset_wdt(long param_1)

{
  CallSecureMonitor(0);
  _dev_err(*(undefined8 *)(param_1 + 8),"failed to reset vWDOG, hret = %d ret = %d\n",0x86000007,
           0xffffffea);
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_enable_wdt @ 00100484 size=164
// signature: undefined gh_enable_wdt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001004c4) */

undefined4 gh_enable_wdt(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_2 + 0xd0) == '\0') {
    CallSecureMonitor(0);
    _dev_err(*(undefined8 *)(param_2 + 8),"failed enabling vWDOG, hret = %d ret = %d\n",0x86000005,
             0xffffffea);
    uVar1 = 0xffffffea;
  }
  else {
    _dev_err(*(undefined8 *)(param_2 + 8),"vWDT already enabled\n");
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gh_disable_wdt @ 0010054c size=164
// signature: undefined gh_disable_wdt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010058c) */

undefined4 gh_disable_wdt(long param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xd0) == '\0') {
    _dev_err(*(undefined8 *)(param_1 + 8),"vWDT already disabled\n");
    uVar1 = 0;
  }
  else {
    CallSecureMonitor(0);
    _dev_err(*(undefined8 *)(param_1 + 8),"failed disabling VDOG, hret = %d ret = %d\n",0x86000005,
             0xffffffea);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// gh_show_wdt_status @ 00100614 size=132
// signature: undefined gh_show_wdt_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100650) */

undefined8 gh_show_wdt_status(long param_1)

{
  CallSecureMonitor(0);
  _dev_err(*(undefined8 *)(param_1 + 8),"failed to get vWDOG status, hret = %d ret = %d\n",
           0x86000006,0xffffffea);
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 001006f4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gh_wdt_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100724 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gh_wdt_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gh_wdt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_wdt_register @ 00102018 size=1
// signature: undefined qcom_wdt_register(void)
// callers: [gh_wdt_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_wdt_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arm_smccc_sve_check @ 00102020 size=1
// signature: undefined __arm_smccc_sve_check(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arm_smccc_sve_check(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102028 size=1
// signature: undefined _dev_err(void)
// callers: [gh_set_wdt_bite, gh_disable_wdt, gh_set_wdt_bark, gh_show_wdt_status, gh_enable_wdt, gh_reset_wdt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



