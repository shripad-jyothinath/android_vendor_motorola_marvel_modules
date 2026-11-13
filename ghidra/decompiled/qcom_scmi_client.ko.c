// Decompiled by Ghidra 12.2
// Program: qcom_scmi_client.ko
// Image base: 00100000

//------------------------------------------------------------
// get_qcom_scmi_device @ 001000b4 size=56
// signature: undefined get_qcom_scmi_device(void)
// callers: []
//------------------------------------------------------------

long get_qcom_scmi_device(void)

{
  if (scmi_client_inited != '\x01') {
    return -0x205;
  }
  if ((scmi_dev == 0) || (*(long *)(scmi_dev + 0x3a0) == 0)) {
    return -0x13;
  }
  return scmi_dev;
}



//------------------------------------------------------------
// scmi_client_probe @ 001000f0 size=40
// signature: undefined scmi_client_probe(void)
// callers: []
//------------------------------------------------------------

undefined4 scmi_client_probe(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffed;
  if (param_1 != 0) {
    uVar1 = 0;
  }
  scmi_dev = param_1;
  scmi_client_inited = 1;
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00100134 size=52
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  scmi_driver_register(&qcom_scmi_client_drv,&__this_module,"qcom_scmi_client");
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010016c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  scmi_driver_unregister(&qcom_scmi_client_drv);
  return;
}



//------------------------------------------------------------
// scmi_driver_register @ 00101000 size=1
// signature: undefined scmi_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scmi_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scmi_driver_unregister @ 00101008 size=1
// signature: undefined scmi_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scmi_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



