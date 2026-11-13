// Decompiled by Ghidra 12.2
// Program: stm_p_ost.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 001000cc size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  stm_register_protocol(&ost_pdrv);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001000f4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  stm_unregister_protocol(&ost_pdrv);
  return;
}



//------------------------------------------------------------
// ost_write @ 0010011c size=340
// signature: undefined ost_write(void)
// callers: []
//------------------------------------------------------------

long ost_write(long param_1,long param_2,int param_3,undefined8 param_4,undefined8 param_5)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  undefined4 local_68;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  long lStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  uVar1 = *(undefined4 *)(param_2 + 4);
  local_64[0] = 0;
  local_68 = 0x11010;
  param_3 = *(int *)(param_2 + 8) + param_3;
  lVar3 = (**(code **)(param_1 + 0x28))(param_1,uVar1,param_3,0,1,4,&local_68);
  if (0 < lVar3) {
    local_60 = 0x59530003;
    lVar3 = tpidr_el1;
    local_5c = *(undefined4 *)(&cpu_number + lVar3);
    local_58 = sched_clock();
    lVar3 = sp_el0;
    lStack_50 = (long)*(int *)(lVar3 + 0x634);
    lVar3 = stm_data_write(param_1,uVar1,param_3,0,&local_60,0x18);
    if ((0 < lVar3) && (lVar3 = stm_data_write(param_1,uVar1,param_3,0,param_4,param_5), 0 < lVar3))
    {
      (**(code **)(param_1 + 0x28))(param_1,uVar1,param_3,1,2,0,local_64);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// stm_register_protocol @ 00101000 size=1
// signature: undefined stm_register_protocol(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_register_protocol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_unregister_protocol @ 00101008 size=1
// signature: undefined stm_unregister_protocol(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_unregister_protocol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00101018 size=1
// signature: undefined sched_clock(void)
// callers: [ost_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_data_write @ 00101020 size=1
// signature: undefined stm_data_write(void)
// callers: [ost_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_data_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ost_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



