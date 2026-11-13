// Decompiled by Ghidra 12.2
// Program: mmi_qcom_minidump.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_qcom_minidump_probe @ 001000b4 size=348
// signature: undefined mmi_qcom_minidump_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int mmi_qcom_minidump_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long local_108;
  long lStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulong local_90;
  long local_88;
  long local_80;
  long local_78 [11];
  
  lVar1 = sp_el0;
  local_78[10] = *(long *)(lVar1 + 0x638);
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  lStack_100 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  iVar2 = __of_parse_phandle_with_args(*(undefined8 *)(param_1 + 0x2f8),"cpusys-mem",0,0,0,local_78)
  ;
  if ((iVar2 == 0) && (local_78[0] != 0)) {
    iVar2 = of_address_to_resource(local_78[0],0,&local_108);
    if (iVar2 != 0) {
      _printk(&DAT_0010065f);
      goto LAB_001001cc;
    }
    strscpy(&local_a8,"CPUSYS",7);
    local_90 = local_108 - _memstart_addr | 0xffffff8000000000;
    local_80 = (lStack_100 - local_108) + 1;
    local_88 = local_108;
    iVar2 = msm_minidump_add_region(&local_a8);
    if (iVar2 < 0) {
      _printk(&DAT_001006e3);
      iVar2 = -0x16;
      goto LAB_001001cc;
    }
    _printk(&DAT_00100692,local_88,local_80);
  }
  else {
    _printk(&DAT_0010064c,"cpusys memory-region");
  }
  iVar2 = 0;
LAB_001001cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00100214 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_qcom_minidump_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100244 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_qcom_minidump_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00101000 size=1
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
// platform_driver_unregister @ 00101008 size=1
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
// __of_parse_phandle_with_args @ 00101010 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00101018 size=1
// signature: undefined of_address_to_resource(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00101020 size=1
// signature: undefined strscpy(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00101030 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101038 size=1
// signature: undefined _printk(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mmi_qcom_minidump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



