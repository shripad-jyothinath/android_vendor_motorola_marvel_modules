// Decompiled by Ghidra 12.2
// Program: reboot-mode.ko
// Image base: 00100000

//------------------------------------------------------------
// reboot_mode_register @ 001001e4 size=400
// signature: undefined reboot_mode_register(void)
// callers: [devm_reboot_mode_register]
//------------------------------------------------------------

undefined8 reboot_mode_register(long *param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  
  plVar1 = param_1 + 1;
  lVar8 = *(long *)(*param_1 + 0x2e8);
  param_1[1] = (long)plVar1;
  param_1[2] = (long)plVar1;
  plVar10 = *(long **)(lVar8 + 0x60);
  do {
    if (plVar10 == (long *)0x0) {
      param_1[4] = (long)reboot_mode_notify;
      register_reboot_notifier(param_1 + 4);
      return 0;
    }
    iVar3 = strncmp((char *)*plVar10,"mode-",5);
    if (iVar3 == 0) {
      puVar4 = (undefined8 *)devm_kmalloc(*param_1,0x20,0xdc0);
      if (puVar4 == (undefined8 *)0x0) {
LAB_0010030c:
        uVar7 = 0xfffffff4;
LAB_00100310:
        for (plVar10 = (long *)*plVar1; plVar10 != plVar1; plVar10 = (long *)*plVar10) {
          kfree_const(plVar10[-2]);
        }
        return uVar7;
      }
      iVar3 = of_property_read_variable_u32_array(lVar8,*plVar10,puVar4 + 1,1,0);
      if (iVar3 < 0) {
        _dev_err(*param_1,"reboot mode %s without magic number\n",*puVar4);
        devm_kfree(*param_1,puVar4);
      }
      else {
        pcVar5 = (char *)kstrdup_const(*plVar10 + 5,0xcc0);
        *puVar4 = pcVar5;
        if (pcVar5 == (char *)0x0) goto LAB_0010030c;
        if (*pcVar5 == '\0') {
          kfree_const();
          _dev_err(*param_1,"invalid mode name(%s): too short!\n",*plVar10);
          uVar7 = 0xffffffea;
          goto LAB_00100310;
        }
        plVar9 = (long *)param_1[2];
        puVar2 = puVar4 + 2;
        uVar6 = __list_add_valid(puVar2,plVar9,plVar1);
        if ((uVar6 & 1) != 0) {
          param_1[2] = (long)puVar2;
          puVar4[2] = plVar1;
          puVar4[3] = plVar9;
          *plVar9 = (long)puVar2;
        }
      }
    }
    plVar10 = (long *)plVar10[3];
  } while( true );
}



//------------------------------------------------------------
// reboot_mode_notify @ 00100378 size=156
// signature: undefined reboot_mode_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 reboot_mode_notify(long param_1,undefined8 param_2,char *param_3)

{
  char *__s2;
  code *pcVar1;
  int iVar2;
  long *plVar3;
  
  __s2 = "normal";
  if (param_3 != (char *)0x0) {
    __s2 = param_3;
  }
  plVar3 = (long *)(param_1 + -0x18);
  do {
    plVar3 = (long *)*plVar3;
    if (plVar3 == (long *)(param_1 + -0x18)) {
      return 0;
    }
    iVar2 = strcmp((char *)plVar3[-2],__s2);
  } while (iVar2 != 0);
  if (*(int *)(plVar3 + -1) != 0) {
    if (*(int *)(*(code **)(param_1 + -8) + -4) != -0x2c77e5a5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1003f4);
      (*pcVar1)();
    }
    (**(code **)(param_1 + -8))(param_1 + -0x20);
  }
  return 0;
}



//------------------------------------------------------------
// reboot_mode_unregister @ 00100418 size=80
// signature: undefined reboot_mode_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 reboot_mode_unregister(long param_1)

{
  long *plVar1;
  
  unregister_reboot_notifier(param_1 + 0x20);
  for (plVar1 = *(long **)(param_1 + 8); plVar1 != (long *)(param_1 + 8); plVar1 = (long *)*plVar1)
  {
    kfree_const(plVar1[-2]);
  }
  return 0;
}



//------------------------------------------------------------
// devm_reboot_mode_register @ 0010046c size=144
// signature: undefined devm_reboot_mode_register(void)
// callers: []
//------------------------------------------------------------

int devm_reboot_mode_register(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)
           __devres_alloc_node(devm_reboot_mode_release,8,0xcc0,0xffffffff,
                               "devm_reboot_mode_release");
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0xc;
  }
  else {
    iVar1 = reboot_mode_register(param_2);
    if (iVar1 == 0) {
      *puVar2 = param_2;
      devres_add(param_1,puVar2);
    }
    else {
      devres_free(puVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// devm_reboot_mode_release @ 00100500 size=76
// signature: undefined devm_reboot_mode_release(void)
// callers: []
//------------------------------------------------------------

void devm_reboot_mode_release(undefined8 param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  
  lVar1 = *param_2;
  unregister_reboot_notifier(lVar1 + 0x20);
  plVar2 = (long *)(lVar1 + 8);
  for (plVar3 = (long *)*plVar2; plVar3 != plVar2; plVar3 = (long *)*plVar3) {
    kfree_const(plVar3[-2]);
  }
  return;
}



//------------------------------------------------------------
// devm_reboot_mode_unregister @ 00100550 size=56
// signature: undefined devm_reboot_mode_unregister(void)
// callers: []
//------------------------------------------------------------

void devm_reboot_mode_unregister(undefined4 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = devres_release(param_1,devm_reboot_mode_release,devm_reboot_mode_match,param_2);
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100588);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// devm_reboot_mode_match @ 00100590 size=32
// signature: undefined devm_reboot_mode_match(void)
// callers: []
//------------------------------------------------------------

bool devm_reboot_mode_match(undefined8 param_1,long *param_2,long param_3)

{
  code *pcVar1;
  
  if ((param_2 == (long *)0x0) || (*param_2 == 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1005b0);
    (*pcVar1)();
  }
  return *param_2 == param_3;
}



//------------------------------------------------------------
// _dev_err @ 00102000 size=1
// signature: undefined _dev_err(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00102008 size=1
// signature: undefined devm_kfree(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00102010 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup_const @ 00102028 size=1
// signature: undefined kstrdup_const(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102030 size=1
// signature: undefined __list_add_valid(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00102038 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_const @ 00102040 size=1
// signature: undefined kfree_const(void)
// callers: [reboot_mode_unregister, reboot_mode_register, devm_reboot_mode_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102048 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [reboot_mode_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 00102050 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [reboot_mode_unregister, devm_reboot_mode_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 00102058 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 00102060 size=1
// signature: undefined devres_free(void)
// callers: [devm_reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 00102068 size=1
// signature: undefined devres_add(void)
// callers: [devm_reboot_mode_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_release @ 00102070 size=1
// signature: undefined devres_release(void)
// callers: [devm_reboot_mode_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



