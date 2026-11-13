// Decompiled by Ghidra 12.2
// Program: thermal_minidump.ko
// Image base: 00100000

//------------------------------------------------------------
// thermal_minidump_update_data @ 001000f4 size=220
// signature: undefined thermal_minidump_update_data(void)
// callers: []
//------------------------------------------------------------

int thermal_minidump_update_data(long param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0x4ec);
  uVar1 = *(uint *)(param_1 + 0x4b0);
  uVar5 = (ulong)uVar1;
  if (uVar1 == 0x32) {
    uVar5 = 0;
    *(undefined4 *)(param_1 + 0x4b0) = 0;
  }
  else if (0x31 < uVar1) goto LAB_001001cc;
  strscpy(param_1 + uVar5 * 0x14,param_2,0x14);
  if (*(uint *)(param_1 + 0x4b0) < 0x32) {
    *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 0x4b0) * 4 + 1000) = *param_3;
    *(int *)(param_1 + 0x4b0) = *(int *)(param_1 + 0x4b0) + 1;
    iVar3 = msm_minidump_update_region(*(undefined4 *)(param_1 + 0x4e8),param_1 + 0x4b8);
    _raw_spin_unlock_irqrestore(param_1 + 0x4ec,uVar4);
    if (iVar3 < 0) {
      _printk(&DAT_00100378,iVar3);
    }
    return iVar3;
  }
LAB_001001cc:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1001d0);
  (*pcVar2)();
}



//------------------------------------------------------------
// thermal_minidump_register @ 001001d4 size=268
// signature: undefined thermal_minidump_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long thermal_minidump_register(char *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  
  lVar5 = kmalloc_trace(_DAT_00101080,0xdc0,0x4f0);
  if (lVar5 == 0) {
    return 0;
  }
  uVar6 = strnlen(param_1,0xd);
  if (uVar6 == 0xffffffffffffffff) {
    fortify_panic("strnlen");
  }
  else {
    if (uVar6 != 0xd) {
      uVar6 = uVar6 + 1;
    }
    if (uVar6 < 0xe) {
      strscpy(lVar5 + 0x4b8,param_1);
      lVar3 = _kimage_voffset;
      lVar1 = _memstart_addr;
      lVar2 = (lVar5 << 8) >> 8;
      uVar6 = lVar2 + 0x8000000000;
      *(long *)(lVar5 + 0x4d0) = lVar5;
      lVar1 = lVar1 + uVar6;
      if (uVar6 >> 0x26 != 0) {
        lVar1 = lVar2 - lVar3;
      }
      *(long *)(lVar5 + 0x4d8) = lVar1;
      *(undefined8 *)(lVar5 + 0x4e0) = 0x4f0;
      iVar4 = msm_minidump_add_region(lVar5 + 0x4b8);
      *(int *)(lVar5 + 0x4e8) = iVar4;
      if (iVar4 < 0) {
        kfree(lVar5);
        _printk(&DAT_001003a5,param_1);
        return 0;
      }
      *(undefined4 *)(lVar5 + 0x4ec) = 0;
      return lVar5;
    }
  }
  fortify_panic("strscpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_unregister @ 001002e4 size=56
// signature: undefined thermal_minidump_unregister(void)
// callers: []
//------------------------------------------------------------

void thermal_minidump_unregister(long param_1)

{
  if (param_1 != 0) {
    msm_minidump_remove_region(param_1 + 0x4b8);
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00101000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [thermal_minidump_update_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00101008 size=1
// signature: undefined strscpy(void)
// callers: [thermal_minidump_update_data, thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_update_region @ 00101010 size=1
// signature: undefined msm_minidump_update_region(void)
// callers: [thermal_minidump_update_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_update_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00101018 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [thermal_minidump_update_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101020 size=1
// signature: undefined _printk(void)
// callers: [thermal_minidump_update_data, thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00101030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00101038 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00101050 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00101058 size=1
// signature: undefined kfree(void)
// callers: [thermal_minidump_unregister, thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00101060 size=1
// signature: undefined fortify_panic(void)
// callers: [thermal_minidump_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_remove_region @ 00101068 size=1
// signature: undefined msm_minidump_remove_region(void)
// callers: [thermal_minidump_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_remove_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



