// Decompiled by Ghidra 12.2
// Program: qcom-reboot-reason.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_reboot_reason_probe @ 00100134 size=184
// signature: undefined qcom_reboot_reason_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_reboot_reason_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  lVar1 = param_1 + 0x10;
  plVar2 = (long *)devm_kmalloc(lVar1,0x30,0xdc0);
  if (plVar2 == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *plVar2 = lVar1;
    lVar3 = of_match_device(&of_qcom_reboot_reason_match,lVar1);
    if (lVar3 == 0) {
      uVar4 = 0xffffffed;
    }
    else {
      plVar2[5] = *(long *)(lVar3 + 0xc0);
      uVar4 = devm_nvmem_cell_get(lVar1,"restart_reason");
      plVar2[4] = uVar4;
      if (uVar4 < 0xfffffffffffff001) {
        *(undefined4 *)(plVar2 + 3) = 0xff;
        plVar2[1] = (long)qcom_reboot_reason_reboot;
        register_reboot_notifier();
        uVar4 = 0;
        *(long **)(param_1 + 0xa8) = plVar2;
      }
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// qcom_reboot_reason_remove @ 001001f0 size=40
// signature: undefined qcom_reboot_reason_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_reboot_reason_remove(long param_1)

{
  unregister_reboot_notifier(*(long *)(param_1 + 0xa8) + 8);
  return 0;
}



//------------------------------------------------------------
// qcom_reboot_reason_reboot @ 0010021c size=284
// signature: undefined qcom_reboot_reason_reboot(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_reboot_reason_reboot(long param_1,undefined8 param_2,char *param_3)

{
  undefined *__s1;
  code *pcVar1;
  int iVar2;
  char *__s2;
  long *plVar3;
  
  if (param_3 != (char *)0x0) {
    iVar2 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + -8) + 0x2e8),"qcom,imem-reboot-reason");
    if (iVar2 != 0) {
      _reboot_mode = 1;
    }
    __s2 = (char *)**(long **)(param_1 + 0x20);
    if (__s2 != (char *)0x0) {
      plVar3 = *(long **)(param_1 + 0x20) + 1;
      do {
        iVar2 = strcmp(param_3,__s2);
        if (iVar2 == 0) {
          iVar2 = nvmem_cell_write(*(undefined8 *)(param_1 + 0x18),plVar3,
                                   *(undefined4 *)((long)plVar3 + 4));
          if (iVar2 < 0) {
            _printk(&DAT_001009df,"qcom_reboot_reason_reboot",iVar2);
          }
          break;
        }
        __s2 = (char *)plVar3[1];
        plVar3 = plVar3 + 2;
      } while (__s2 != (char *)0x0);
    }
    _printk(&DAT_00100a38,"qcom_reboot_reason_reboot","qcom_reboot_reason_reboot",sys_restart_mode);
    __s1 = sys_restart_mode;
    iVar2 = strcmp(sys_restart_mode,"panic");
    if (iVar2 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100338);
      (*pcVar1)();
    }
    iVar2 = strcmp(__s1,"recovery_panic");
    if ((iVar2 == 0) && (iVar2 = strcmp(param_3,"recovery"), iVar2 == 0)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100334);
      (*pcVar1)();
    }
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 0010033c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_reboot_reason_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010036c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_reboot_reason_driver);
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
// callers: [qcom_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 00102018 size=1
// signature: undefined of_match_device(void)
// callers: [qcom_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_cell_get @ 00102020 size=1
// signature: undefined devm_nvmem_cell_get(void)
// callers: [qcom_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00102028 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [qcom_reboot_reason_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 00102030 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [qcom_reboot_reason_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00102038 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [qcom_reboot_reason_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102048 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_reboot_reason_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 00102050 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [qcom_reboot_reason_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102058 size=1
// signature: undefined _printk(void)
// callers: [qcom_reboot_reason_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



