// Decompiled by Ghidra 12.2
// Program: stm_ftrace.ko
// Image base: 00100000

//------------------------------------------------------------
// stm_ftrace_link @ 00100114 size=56
// signature: undefined stm_ftrace_link(void)
// callers: []
//------------------------------------------------------------

void stm_ftrace_link(long param_1)

{
  *(undefined4 *)(param_1 + 0x38) = 7;
  *(code **)(param_1 + 0x30) = stm_ftrace_write;
  register_ftrace_export(param_1 + 0x28);
  return;
}



//------------------------------------------------------------
// stm_ftrace_unlink @ 00100150 size=32
// signature: undefined stm_ftrace_unlink(void)
// callers: []
//------------------------------------------------------------

void stm_ftrace_unlink(long param_1)

{
  unregister_ftrace_export(param_1 + 0x28);
  return;
}



//------------------------------------------------------------
// stm_ftrace_write @ 00100174 size=60
// signature: undefined stm_ftrace_write(void)
// callers: []
//------------------------------------------------------------

void stm_ftrace_write(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  stm_source_write(param_1 + -0x28,*(undefined4 *)(&cpu_number + lVar1),param_2,param_3);
  return;
}



//------------------------------------------------------------
// init_module @ 001001b8 size=128
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  
  uVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
  lVar1 = (uVar3 & 0xffffffff) - 1;
  DAT_00100364 = (undefined4)(1L << (-LZCOUNT(lVar1) & 0x3fU));
  if (lVar1 == 0) {
    DAT_00100364 = 1;
  }
  iVar2 = stm_source_register_device(0);
  if (iVar2 != 0) {
    _printk(&DAT_00100397);
  }
  return iVar2;
}



//------------------------------------------------------------
// cleanup_module @ 0010023c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  stm_source_unregister_device(&stm_ftrace);
  return;
}



//------------------------------------------------------------
// __bitmap_weight @ 00101010 size=1
// signature: undefined __bitmap_weight(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_register_device @ 00101018 size=1
// signature: undefined stm_source_register_device(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101020 size=1
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
// stm_source_unregister_device @ 00101028 size=1
// signature: undefined stm_source_unregister_device(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_ftrace_export @ 00101030 size=1
// signature: undefined register_ftrace_export(void)
// callers: [stm_ftrace_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_ftrace_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_ftrace_export @ 00101038 size=1
// signature: undefined unregister_ftrace_export(void)
// callers: [stm_ftrace_unlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_ftrace_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_write @ 00101048 size=1
// signature: undefined stm_source_write(void)
// callers: [stm_ftrace_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



