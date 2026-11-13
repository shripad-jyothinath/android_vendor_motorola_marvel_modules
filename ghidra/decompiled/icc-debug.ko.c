// Decompiled by Ghidra 12.2
// Program: icc-debug.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_icc_debug_register @ 001001cc size=156
// signature: undefined qcom_icc_debug_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_icc_debug_register(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  puVar2 = (undefined8 *)kmalloc_trace(___list_del_entry_valid,0xdc0,0x18);
  if (puVar2 == (undefined8 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    puVar2[2] = param_1;
    mutex_lock(&debug_lock);
    puVar1 = PTR_icc_providers_001006c8;
    uVar3 = __list_add_valid(puVar2,PTR_icc_providers_001006c8,&icc_providers);
    if ((uVar3 & 1) != 0) {
      PTR_icc_providers_001006c8 = (undefined *)puVar2;
      *puVar2 = &icc_providers;
      puVar2[1] = puVar1;
      *(undefined8 **)puVar1 = puVar2;
    }
    mutex_unlock(&debug_lock);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// qcom_icc_debug_unregister @ 0010026c size=184
// signature: undefined qcom_icc_debug_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_icc_debug_unregister(undefined *param_1)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  mutex_lock(&debug_lock);
  ppuVar4 = (undefined **)icc_providers;
  if ((undefined **)icc_providers != &icc_providers) {
    do {
      ppuVar5 = (undefined **)*ppuVar4;
      if (ppuVar4[2] == param_1) {
        uVar3 = __list_del_entry_valid(ppuVar4);
        if ((uVar3 & 1) != 0) {
          puVar1 = *ppuVar4;
          plVar2 = (long *)ppuVar4[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar4 = &DAT_dead000000000100;
        ppuVar4[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar4);
      }
      ppuVar4 = ppuVar5;
    } while (ppuVar5 != &icc_providers);
  }
  mutex_unlock(&debug_lock);
  return 0;
}



//------------------------------------------------------------
// icc_debug_suspend_fops_open @ 00100328 size=52
// signature: undefined icc_debug_suspend_fops_open(void)
// callers: []
//------------------------------------------------------------

void icc_debug_suspend_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,icc_debug_suspend_get,icc_debug_suspend_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// icc_debug_suspend_get @ 00100360 size=20
// signature: undefined icc_debug_suspend_get(void)
// callers: []
//------------------------------------------------------------

undefined8 icc_debug_suspend_get(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)debug_suspend;
  return 0;
}



//------------------------------------------------------------
// icc_debug_suspend_set @ 00100378 size=196
// signature: undefined icc_debug_suspend_set(void)
// callers: []
//------------------------------------------------------------

int icc_debug_suspend_set(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  
  if ((bool)debug_suspend == (param_2 != 0)) {
    iVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = tracepoint_probe_unregister
                        (&__tracepoint_suspend_resume,icc_debug_suspend_trace_probe,0);
    }
    else {
      iVar2 = tracepoint_probe_register
                        (&__tracepoint_suspend_resume,icc_debug_suspend_trace_probe,0);
    }
    if (iVar2 == 0) {
      debug_suspend = param_2 != 0;
    }
    else {
      puVar1 = &DAT_00100870;
      if (param_2 == 0) {
        puVar1 = &DAT_001008ef;
      }
      _printk(&DAT_00100916,"icc_debug_suspend_set",puVar1,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// icc_debug_suspend_trace_probe @ 00100440 size=328
// signature: undefined icc_debug_suspend_trace_probe(void)
// callers: []
//------------------------------------------------------------

void icc_debug_suspend_trace_probe(undefined8 param_1,char *param_2,int param_3,ulong param_4)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  long *plVar7;
  
  if (((0 < param_3) && ((param_4 & 1) != 0)) &&
     (iVar1 = strcmp("machine_suspend",param_2), iVar1 == 0)) {
    _printk(&DAT_00100871);
    _printk(&DAT_0010080e);
    _printk(&DAT_001007ad);
    ppuVar4 = (undefined **)icc_providers;
    if ((undefined **)icc_providers != &icc_providers) {
      do {
        puVar5 = ppuVar4[2];
        for (puVar6 = *(undefined8 **)(puVar5 + 0x10); puVar6 != (undefined8 *)(puVar5 + 0x10);
            puVar6 = (undefined8 *)*puVar6) {
          if (*(int *)(puVar6 + 7) != 0 || *(int *)((long)puVar6 + 0x3c) != 0) {
            _printk(&DAT_001007fb,puVar6[-4]);
            for (plVar7 = (long *)puVar6[6]; plVar7 != (long *)0x0; plVar7 = (long *)*plVar7) {
              while (((plVar3 = (long *)plVar7[3], plVar3 != (long *)0x0 &&
                      ((char)plVar7[4] != '\0')) &&
                     ((int)plVar7[5] != 0 || *(int *)((long)plVar7 + 0x2c) != 0))) {
                lVar2 = plVar3[0xe];
                if (lVar2 == 0) {
                  lVar2 = *plVar3;
                }
                _printk(&DAT_00100856,lVar2,*(undefined4 *)((long)plVar7 + 0x24));
                plVar7 = (long *)*plVar7;
                if (plVar7 == (long *)0x0) goto LAB_001004f8;
              }
            }
          }
LAB_001004f8:
        }
        ppuVar4 = (undefined **)*ppuVar4;
      } while (ppuVar4 != &icc_providers);
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001005c0 size=128
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  qcom_icc_debug_init_dir = debugfs_lookup("interconnect",0);
  if ((qcom_icc_debug_init_dir == 0) || (0xfffffffffffff000 < qcom_icc_debug_init_dir)) {
    _printk(&DAT_001008ad,"qcom_icc_debug_init");
  }
  else {
    dentry_suspend =
         debugfs_create_file_unsafe
                   ("debug_suspend",0x1a4,qcom_icc_debug_init_dir,0,&icc_debug_suspend_fops);
  }
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00100644 size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(dentry_suspend);
  if (debug_suspend != '\0') {
    tracepoint_probe_unregister(&__tracepoint_suspend_resume,icc_debug_suspend_trace_probe,0);
  }
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00102008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_icc_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102010 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_icc_debug_register, qcom_icc_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102018 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_icc_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102020 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_icc_debug_register, qcom_icc_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102028 size=1
// signature: undefined kfree(void)
// callers: [qcom_icc_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00102030 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_icc_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 00102038 size=1
// signature: undefined debugfs_lookup(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00102040 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102048 size=1
// signature: undefined _printk(void)
// callers: [icc_debug_suspend_trace_probe, init_module, icc_debug_suspend_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00102050 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00102060 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module, icc_debug_suspend_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00102068 size=1
// signature: undefined simple_attr_open(void)
// callers: [icc_debug_suspend_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102070 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [icc_debug_suspend_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102078 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [icc_debug_suspend_trace_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



