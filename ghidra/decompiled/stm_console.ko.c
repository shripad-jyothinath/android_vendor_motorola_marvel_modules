// Decompiled by Ghidra 12.2
// Program: stm_console.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 001000fc size=40
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  stm_source_register_device(0,&stm_console);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100128 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  stm_source_unregister_device(&stm_console);
  return;
}



//------------------------------------------------------------
// stm_console_link @ 00100150 size=80
// signature: undefined stm_console_link(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_console_link(long param_1)

{
  *(undefined8 *)(param_1 + 0x28) = s_stm_console_001003a0._0_8_;
  *(undefined4 *)(param_1 + 0x30) = 0x656c6f;
  *(undefined2 *)(param_1 + 0x70) = 5;
  *(code **)(param_1 + 0x38) = stm_console_write;
  register_console();
  return 0;
}



//------------------------------------------------------------
// stm_console_unlink @ 001001a4 size=32
// signature: undefined stm_console_unlink(void)
// callers: []
//------------------------------------------------------------

void stm_console_unlink(long param_1)

{
  unregister_console(param_1 + 0x28);
  return;
}



//------------------------------------------------------------
// stm_console_write @ 001001c8 size=48
// signature: undefined stm_console_write(void)
// callers: []
//------------------------------------------------------------

void stm_console_write(long param_1,undefined8 param_2,undefined4 param_3)

{
  stm_source_write(param_1 + -0x28,0,param_2,param_3);
  return;
}



//------------------------------------------------------------
// stm_source_register_device @ 00101000 size=1
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
// stm_source_unregister_device @ 00101008 size=1
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
// register_console @ 00101010 size=1
// signature: undefined register_console(void)
// callers: [stm_console_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_console(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_console @ 00101018 size=1
// signature: undefined unregister_console(void)
// callers: [stm_console_unlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_console(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_source_write @ 00101020 size=1
// signature: undefined stm_source_write(void)
// callers: [stm_console_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_source_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



