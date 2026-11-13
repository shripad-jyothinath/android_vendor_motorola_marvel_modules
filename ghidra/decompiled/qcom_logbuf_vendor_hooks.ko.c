// Decompiled by Ghidra 12.2
// Program: qcom_logbuf_vendor_hooks.ko
// Image base: 00100000

//------------------------------------------------------------
// register_log_minidump @ 00100104 size=480
// signature: undefined register_log_minidump(void)
// callers: [logbuf_vh_driver_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void register_log_minidump(uint *param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  long lVar8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  long local_80;
  long local_78;
  long local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((param_1 != (uint *)0x0) && ((register_log_minidump_log_buf_registered & 1) == 0)) {
    lVar2 = *(long *)(param_1 + 2);
    lVar3 = *(long *)(param_1 + 4);
    uVar4 = *param_1;
    uVar5 = param_1[0xc];
    lVar8 = *(long *)(param_1 + 0xe);
    register_log_minidump_log_buf_registered = 1;
    strscpy(&local_98,"KLOGBUF",8);
    lVar6 = (lVar8 << 8) >> 8;
    uVar1 = lVar6 + 0x8000000000;
    local_78 = uVar1 + _memstart_addr;
    if (uVar1 >> 0x26 != 0) {
      local_78 = lVar6 - _kimage_voffset;
    }
    local_70 = 1L << ((ulong)uVar5 & 0x3f);
    local_80 = lVar8;
    iVar7 = msm_minidump_add_region(&local_98);
    if (iVar7 < 0) {
      _printk(&DAT_0010039a);
    }
    strscpy(&local_98,"LOG_DESC",9);
    lVar6 = (lVar2 << 8) >> 8;
    lVar8 = 1L << ((ulong)uVar4 & 0x3f);
    uVar1 = lVar6 + 0x8000000000;
    local_78 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      local_78 = lVar6 - _kimage_voffset;
    }
    local_70 = lVar8 * 0x18;
    local_80 = lVar2;
    iVar7 = msm_minidump_add_region(&local_98);
    if (iVar7 < 0) {
      _printk(&DAT_001003d7);
    }
    strscpy(&local_98,"LOG_INFO",9);
    lVar2 = (lVar3 << 8) >> 8;
    uVar1 = lVar2 + 0x8000000000;
    local_78 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      local_78 = lVar2 - _kimage_voffset;
    }
    local_70 = lVar8 * 0x58;
    local_80 = lVar3;
    iVar7 = msm_minidump_add_region(&local_98);
    if (iVar7 < 0) {
      _printk(&DAT_0010042b);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// logbuf_vh_driver_probe @ 001002e8 size=64
// signature: undefined logbuf_vh_driver_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 logbuf_vh_driver_probe(void)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = debug_symbol_available();
  if ((uVar1 & 1) == 0) {
    uVar3 = 0xfffffdfb;
  }
  else {
    puVar2 = (undefined8 *)debug_symbol_lookup_name(&DAT_00100396);
    register_log_minidump(*puVar2);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// logbuf_vh_driver_remove @ 0010032c size=8
// signature: undefined logbuf_vh_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 logbuf_vh_driver_remove(void)

{
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100338 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&logbuf_vh_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100368 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&logbuf_vh_driver);
  return;
}



//------------------------------------------------------------
// strscpy @ 00101000 size=1
// signature: undefined strscpy(void)
// callers: [register_log_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00101018 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [register_log_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101020 size=1
// signature: undefined _printk(void)
// callers: [register_log_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [register_log_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00101030 size=1
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
// platform_driver_unregister @ 00101038 size=1
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
// debug_symbol_available @ 00101040 size=1
// signature: undefined debug_symbol_available(void)
// callers: [logbuf_vh_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debug_symbol_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debug_symbol_lookup_name @ 00101048 size=1
// signature: undefined debug_symbol_lookup_name(void)
// callers: [logbuf_vh_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debug_symbol_lookup_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



