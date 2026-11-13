// Decompiled by Ghidra 12.2
// Program: gh_mem_notifier.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_mem_notifier_register @ 00100144 size=168
// signature: undefined gh_mem_notifier_register(void)
// callers: []
//------------------------------------------------------------

long * gh_mem_notifier_register(uint param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = (long *)0xffffffffffffffea;
  if ((param_1 < 0x3b) && (param_2 != 0)) {
    mutex_lock(&mem_notifier_entries_lock);
    plVar2 = (long *)(&mem_notifier_entries + (ulong)param_1 * 0x10);
    if (*plVar2 == 0) {
      if (0x3a < param_1) {
LAB_001001e8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x1001ec);
        (*pcVar1)();
      }
      *plVar2 = param_2;
      if (0x3b0 < ((ulong)param_1 << 4 | 8)) goto LAB_001001e8;
      *(undefined8 *)(&DAT_00100448 + (ulong)param_1 * 0x10) = param_3;
    }
    else {
      plVar2 = (long *)0xffffffffffffffef;
    }
    mutex_unlock(&mem_notifier_entries_lock);
  }
  return plVar2;
}



//------------------------------------------------------------
// gh_mem_notifier_unregister @ 001001f0 size=68
// signature: undefined gh_mem_notifier_unregister(void)
// callers: []
//------------------------------------------------------------

void gh_mem_notifier_unregister(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    mutex_lock(&mem_notifier_entries_lock);
    *param_1 = 0;
    param_1[1] = 0;
    mutex_unlock(&mem_notifier_entries_lock);
  }
  return;
}



//------------------------------------------------------------
// gh_mem_notifier_call @ 00100238 size=264
// signature: undefined gh_mem_notifier_call(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_mem_notifier_call(undefined8 param_1,long param_2,long param_3)

{
  uint *puVar1;
  ulong uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if (0xfffffffffffffffc < param_2 - 0x51100014U) {
    if (param_2 == 0x51100012) {
      puVar1 = (uint *)(param_3 + 8);
    }
    else {
      puVar1 = (uint *)(param_3 + 8);
      if (param_2 == 0x51100011) {
        puVar1 = (uint *)(param_3 + 0x10);
      }
    }
    uVar2 = (ulong)*puVar1;
    if (*puVar1 < 0x3b) {
      mutex_lock(&mem_notifier_entries_lock);
      if (0x3b0 < (uVar2 << 4 | 8)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x100340);
        (*pcVar4)();
      }
      pcVar4 = *(code **)(&mem_notifier_entries + uVar2 * 0x10);
      uVar3 = *(undefined8 *)(&DAT_00100448 + uVar2 * 0x10);
      mutex_unlock(&mem_notifier_entries_lock);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x5751ec4a) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8237,0x100314);
          (*pcVar4)();
        }
        (*pcVar4)(uVar2,param_2,uVar3,param_3);
      }
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010037c size=84
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = gh_rm_register_notifier(&gh_mem_notifier_blk);
  if (iVar1 != 0) {
    _printk(&DAT_001008d0,"gh_mem_notifier_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001003d4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gh_rm_unregister_notifier(&gh_mem_notifier_blk);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00101000 size=1
// signature: undefined mutex_lock(void)
// callers: [gh_mem_notifier_register, gh_mem_notifier_unregister, gh_mem_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00101008 size=1
// signature: undefined mutex_unlock(void)
// callers: [gh_mem_notifier_register, gh_mem_notifier_unregister, gh_mem_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00101010 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101018 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00101020 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



