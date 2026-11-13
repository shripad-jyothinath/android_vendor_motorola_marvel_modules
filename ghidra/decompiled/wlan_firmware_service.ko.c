// Decompiled by Ghidra 12.2
// Program: wlan_firmware_service.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 001080ec size=108
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = of_find_node_with_property(0,"qcom,wlan");
  if (lVar1 != 0) {
    do {
      uVar2 = of_device_is_available(lVar1);
      if ((uVar2 & 1) != 0) {
        return 0;
      }
      lVar1 = of_find_node_with_property(lVar1,"qcom,wlan");
    } while (lVar1 != 0);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// of_find_node_with_property @ 00109008 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00109010 size=1
// signature: undefined of_device_is_available(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



