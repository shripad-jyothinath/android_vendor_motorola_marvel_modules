// Decompiled by Ghidra 12.2
// Program: moto_reboot_reason.ko
// Image base: 00100000

//------------------------------------------------------------
// moto_reboot_reason_probe @ 00100174 size=296
// signature: undefined moto_reboot_reason_probe(void)
// callers: []
//------------------------------------------------------------

void moto_reboot_reason_probe(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  lVar5 = param_1 + 0x10;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0x80;
  plVar3 = (long *)devm_kmalloc(lVar5,0x60,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *plVar3 = lVar5;
    uVar4 = nvmem_cell_get(lVar5,"extra_restart_reason");
    plVar3[0xb] = uVar4;
    if (uVar4 < 0xfffffffffffff001) {
      *(undefined4 *)(plVar3 + 10) = 0x7fffffff;
      plVar3[8] = (long)moto_reboot_reason_panic;
      atomic_notifier_chain_register(&panic_notifier_list);
      *(undefined4 *)(plVar3 + 1) = 0;
      *(undefined4 *)(plVar3 + 4) = 0xff;
      plVar3[2] = (long)moto_reboot_reason_reboot;
      register_reboot_notifier();
      *(undefined4 *)(plVar3 + 7) = 0xff;
      plVar3[5] = (long)moto_reboot_reason_restart;
      register_restart_handler();
      lVar5 = plVar3[0xb];
      *(long **)(param_1 + 0xa8) = plVar3;
      uVar2 = nvmem_cell_write(lVar5,local_3c,1);
      _printk(&DAT_0010095a,uVar2);
      uVar4 = 0;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// moto_reboot_reason_remove @ 001002a0 size=72
// signature: undefined moto_reboot_reason_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_reboot_reason_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  atomic_notifier_chain_unregister(&panic_notifier_list,lVar1 + 0x40);
  unregister_reboot_notifier(lVar1 + 0x10);
  unregister_restart_handler(lVar1 + 0x28);
  return 0;
}



//------------------------------------------------------------
// moto_reboot_reason_panic @ 001002ec size=116
// signature: undefined moto_reboot_reason_panic(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_reboot_reason_panic(long param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 8;
  nvmem_cell_write(*(undefined8 *)(param_1 + 0x18),local_1c,1);
  _printk(&DAT_0010097b,"moto_reboot_reason_panic");
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// moto_reboot_reason_reboot @ 00100364 size=212
// signature: undefined moto_reboot_reason_reboot(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_reboot_reason_reboot(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  char *__s2;
  undefined *puVar3;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 1;
  nvmem_cell_write(*(undefined8 *)(param_1 + 0x48),local_3c,1);
  *(undefined4 *)(param_1 + -8) = 1;
  if ((param_3 != (char *)0x0) && (extra_reasons != (undefined *)0x0)) {
    puVar3 = &DAT_001008c8;
    __s2 = extra_reasons;
    do {
      iVar2 = strcmp(param_3,__s2);
      if (iVar2 == 0) {
        nvmem_cell_write(*(undefined8 *)(param_1 + 0x48),puVar3,1);
        _printk(&DAT_001009ac,"moto_reboot_reason_reboot");
        break;
      }
      __s2 = *(char **)(puVar3 + 8);
      puVar3 = puVar3 + 0x10;
    } while (__s2 != (char *)0x0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// moto_reboot_reason_restart @ 0010043c size=128
// signature: undefined moto_reboot_reason_restart(void)
// callers: []
//------------------------------------------------------------

undefined8 moto_reboot_reason_restart(long param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 1;
  if (*(int *)(param_1 + -0x20) == 0) {
    nvmem_cell_write(*(undefined8 *)(param_1 + 0x30),local_1c,1);
    _printk(&DAT_001008fb,"moto_reboot_reason_restart");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 001004c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&moto_reboot_reason_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001004f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&moto_reboot_reason_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [moto_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 00102018 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [moto_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00102028 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [moto_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00102030 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [moto_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_restart_handler @ 00102038 size=1
// signature: undefined register_restart_handler(void)
// callers: [moto_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 00102040 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [moto_reboot_reason_restart, moto_reboot_reason_probe, moto_reboot_reason_reboot, moto_reboot_reason_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102048 size=1
// signature: undefined _printk(void)
// callers: [moto_reboot_reason_restart, moto_reboot_reason_probe, moto_reboot_reason_reboot, moto_reboot_reason_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [moto_reboot_reason_restart, moto_reboot_reason_probe, moto_reboot_reason_reboot, moto_reboot_reason_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00102058 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [moto_reboot_reason_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 00102060 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [moto_reboot_reason_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_restart_handler @ 00102068 size=1
// signature: undefined unregister_restart_handler(void)
// callers: [moto_reboot_reason_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102070 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [moto_reboot_reason_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



