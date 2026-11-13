// Decompiled by Ghidra 12.2
// Program: mmi_relay.ko
// Image base: 00100000

//------------------------------------------------------------
// relay_notifier_fire @ 001001fc size=160
// signature: undefined relay_notifier_fire(void)
// callers: []
//------------------------------------------------------------

undefined8 relay_notifier_fire(uint param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (relay_dev == 0) {
    _printk(&DAT_001008a1);
    uVar2 = 0xffffffea;
  }
  else if ((param_1 < 2) && (param_2 < 4)) {
    if (param_1 == 1) {
      uVar2 = blocking_notifier_call_chain
                        (relay_dev + (ulong)param_2 * 0x68 + 0x1e8,param_3,param_4);
    }
    else {
      if (param_1 != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10029c);
        (*pcVar1)();
      }
      uVar2 = atomic_notifier_call_chain(relay_dev + (ulong)param_2 * 0x68 + 0x48,param_3,param_4);
    }
  }
  else {
    _printk(&DAT_0010084a);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



//------------------------------------------------------------
// relay_register_action @ 001002a0 size=296
// signature: undefined relay_register_action(void)
// callers: []
//------------------------------------------------------------

int relay_register_action(uint param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (relay_dev == 0) {
    _printk(&DAT_001008a1);
    return -0x16;
  }
  if ((1 < param_1) || (3 < param_2)) {
    _printk(&DAT_0010084a);
    return -1;
  }
  mutex_lock(relay_dev + 8);
  if (param_1 == 1) {
    iVar2 = blocking_notifier_chain_register(relay_dev + (ulong)param_2 * 0x68 + 0x1e8,param_3);
    if (iVar2 != 0) goto LAB_00100368;
    if (relay_dev == 0) {
LAB_001003b4:
      _printk(&DAT_001008a1);
    }
    else {
      blocking_notifier_call_chain(relay_dev + 0x2b8,0,0);
    }
  }
  else {
    if (param_1 != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1003c8);
      (*pcVar1)();
    }
    iVar2 = atomic_notifier_chain_register(relay_dev + (ulong)param_2 * 0x68 + 0x48,param_3);
    if (iVar2 != 0) goto LAB_00100368;
    if (relay_dev == 0) goto LAB_001003b4;
    atomic_notifier_call_chain(relay_dev + 0x118,0,0);
  }
  iVar2 = 0;
LAB_00100368:
  mutex_unlock(relay_dev + 8);
  return iVar2;
}



//------------------------------------------------------------
// relay_unregister_action @ 001003cc size=296
// signature: undefined relay_unregister_action(void)
// callers: []
//------------------------------------------------------------

int relay_unregister_action(uint param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (relay_dev == 0) {
    _printk(&DAT_001008a1);
    return -0x16;
  }
  if ((1 < param_1) || (3 < param_2)) {
    _printk(&DAT_0010084a);
    return -1;
  }
  mutex_lock(relay_dev + 8);
  if (param_1 == 1) {
    iVar2 = blocking_notifier_chain_unregister(relay_dev + (ulong)param_2 * 0x68 + 0x1e8,param_3);
    if (iVar2 != 0) goto LAB_00100494;
    if (relay_dev == 0) {
LAB_001004e0:
      _printk(&DAT_001008a1);
    }
    else {
      blocking_notifier_call_chain(relay_dev + 0x2b8,1,0);
    }
  }
  else {
    if (param_1 != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1004f4);
      (*pcVar1)();
    }
    iVar2 = atomic_notifier_chain_unregister(relay_dev + (ulong)param_2 * 0x68 + 0x48,param_3);
    if (iVar2 != 0) goto LAB_00100494;
    if (relay_dev == 0) goto LAB_001004e0;
    atomic_notifier_call_chain(relay_dev + 0x118,1,0);
  }
  iVar2 = 0;
LAB_00100494:
  mutex_unlock(relay_dev + 8);
  return iVar2;
}



//------------------------------------------------------------
// mmi_relay_probe @ 001004f8 size=576
// signature: undefined mmi_relay_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_relay_probe(undefined8 param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  
  puVar2 = (undefined8 *)kmalloc_trace(_DAT_001020a8,0xdc0,0x380);
  relay_dev = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    _printk(&DAT_00100876);
    uVar3 = 0xfffffff4;
  }
  else {
    *puVar2 = param_1;
    *(undefined4 *)(puVar2 + 0x6f) = 8;
    __mutex_init(puVar2 + 1,"&relay_dev->lock",&mmi_relay_probe___key);
    iVar6 = 0;
    lVar7 = 0x1d0;
    iVar8 = 3;
    puVar2 = relay_dev;
    do {
      lVar5 = (long)puVar2 + lVar7 + -0x198;
      *(int *)((long)puVar2 + lVar7 + -0x13c) = iVar6;
      *(undefined4 *)((long)puVar2 + lVar7 + -0x138) = 0;
      *(int *)((long)puVar2 + lVar7 + -0x140) = iVar8 + -3;
      *(long *)lVar5 = lVar5;
      *(long *)((long)puVar2 + lVar7 + -400) = lVar5;
      if (lVar7 == 0x1d0) {
        *(undefined4 *)(puVar2 + 9) = 0;
        puVar2[10] = 0;
        puVar2 = relay_dev;
      }
      else {
        __init_rwsem((long)puVar2 + lVar7 + -0x188,"&(&relay_dev->nodes[i][j].blocking_head)->rwsem"
                     ,&mmi_relay_probe___key_5);
        puVar2 = relay_dev;
        *(undefined8 *)((long)relay_dev + lVar7 + -0x148) = 0;
      }
      lVar5 = (long)puVar2 + lVar7 + -0x130;
      *(int *)((long)puVar2 + lVar7 + -0xd4) = iVar6;
      *(undefined4 *)((long)puVar2 + lVar7 + -0xd0) = 1;
      *(int *)((long)puVar2 + lVar7 + -0xd8) = iVar8 + -2;
      *(long *)lVar5 = lVar5;
      *(long *)((long)puVar2 + lVar7 + -0x128) = lVar5;
      if (lVar7 == 0x1d0) {
        puVar4 = puVar2 + 0x17;
        *(undefined4 *)(puVar2 + 0x16) = 0;
      }
      else {
        __init_rwsem((long)puVar2 + lVar7 + -0x120,"&(&relay_dev->nodes[i][j].blocking_head)->rwsem"
                     ,&mmi_relay_probe___key_5);
        puVar4 = (undefined8 *)((long)relay_dev + lVar7 + -0xe0);
        puVar2 = relay_dev;
      }
      *puVar4 = 0;
      lVar5 = (long)puVar2 + lVar7 + -200;
      *(int *)((long)puVar2 + lVar7 + -0x6c) = iVar6;
      *(undefined4 *)((long)puVar2 + lVar7 + -0x68) = 2;
      *(int *)((long)puVar2 + lVar7 + -0x70) = iVar8 + -1;
      *(long *)((long)puVar2 + lVar7 + -200) = lVar5;
      *(long *)((long)puVar2 + lVar7 + -0xc0) = lVar5;
      if (lVar7 == 0x1d0) {
        *(undefined4 *)(puVar2 + 0x23) = 0;
        puVar2[0x24] = 0;
        puVar2 = relay_dev;
      }
      else {
        __init_rwsem((long)puVar2 + lVar7 + -0xb8,"&(&relay_dev->nodes[i][j].blocking_head)->rwsem",
                     &mmi_relay_probe___key_5);
        puVar2 = relay_dev;
        *(undefined8 *)((long)relay_dev + lVar7 + -0x78) = 0;
      }
      puVar1 = (undefined4 *)((long)puVar2 + lVar7);
      puVar1[-1] = iVar6;
      *puVar1 = 3;
      puVar1[-2] = iVar8;
      *(undefined4 **)(puVar1 + -0x18) = puVar1 + -0x18;
      *(undefined4 **)(puVar1 + -0x16) = puVar1 + -0x18;
      if (lVar7 == 0x1d0) {
        puVar4 = puVar2 + 0x31;
        *(undefined4 *)(puVar2 + 0x30) = 0;
      }
      else {
        __init_rwsem(puVar1 + -0x14,"&(&relay_dev->nodes[i][j].blocking_head)->rwsem",
                     &mmi_relay_probe___key_5);
        puVar4 = (undefined8 *)((long)relay_dev + lVar7 + -0x10);
        puVar2 = relay_dev;
      }
      lVar7 = lVar7 + 0x1a0;
      iVar8 = iVar8 + 0x10000;
      iVar6 = iVar6 + 1;
      *puVar4 = 0;
    } while (lVar7 != 0x510);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// mmi_relay_remove @ 0010073c size=40
// signature: undefined mmi_relay_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_relay_remove(void)

{
  kfree(relay_dev);
  return 0;
}



//------------------------------------------------------------
// init_module @ 001007e8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_relay_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100818 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_relay_driver);
  return;
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00102000 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [relay_notifier_fire, relay_register_action, relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_call_chain @ 00102008 size=1
// signature: undefined atomic_notifier_call_chain(void)
// callers: [relay_notifier_fire, relay_register_action, relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102010 size=1
// signature: undefined _printk(void)
// callers: [mmi_relay_probe, relay_notifier_fire, relay_register_action, relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102018 size=1
// signature: undefined mutex_lock(void)
// callers: [relay_register_action, relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00102020 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [relay_register_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00102028 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [relay_register_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102030 size=1
// signature: undefined mutex_unlock(void)
// callers: [relay_register_action, relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00102038 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00102040 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [relay_unregister_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102048 size=1
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
// platform_driver_unregister @ 00102050 size=1
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
// kmalloc_trace @ 00102060 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mmi_relay_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00102068 size=1
// signature: undefined __mutex_init(void)
// callers: [mmi_relay_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 00102070 size=1
// signature: undefined __init_rwsem(void)
// callers: [mmi_relay_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102078 size=1
// signature: undefined kfree(void)
// callers: [mmi_relay_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



