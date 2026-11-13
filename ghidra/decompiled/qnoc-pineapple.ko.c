// Decompiled by Ghidra 12.2
// Program: qnoc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// qnoc_probe @ 0010007c size=92
// signature: undefined qnoc_probe(void)
// callers: []
//------------------------------------------------------------

int qnoc_probe(long param_1)

{
  int iVar1;
  
  iVar1 = qcom_icc_rpmh_probe();
  if (iVar1 == 0) {
    _dev_info(param_1 + 0x10,"Registered ICC provider\n");
  }
  else {
    _dev_err(param_1 + 0x10,"failed to register ICC provider: %d\n",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 001000dc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qnoc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00160000 size=1
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
// qcom_icc_rpmh_probe @ 00160008 size=1
// signature: undefined qcom_icc_rpmh_probe(void)
// callers: [qnoc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_icc_rpmh_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00160010 size=1
// signature: undefined _dev_info(void)
// callers: [qnoc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00160018 size=1
// signature: undefined _dev_err(void)
// callers: [qnoc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



