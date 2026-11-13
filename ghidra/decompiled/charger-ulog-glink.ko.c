// Decompiled by Ghidra 12.2
// Program: charger-ulog-glink.ko
// Image base: 00100000

//------------------------------------------------------------
// chg_ulog_probe @ 00100314 size=840
// signature: undefined chg_ulog_probe(void)
// callers: []
//------------------------------------------------------------

void chg_ulog_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  char *local_60;
  ulong local_58;
  long *local_50;
  code *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  lVar6 = param_1 + 0x10;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (code *)0x0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = (long *)0x0;
  plVar2 = (long *)devm_kmalloc(lVar6,0x2118,0xdc0);
  if (plVar2 == (long *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_0010062c;
  }
  __mutex_init(plVar2 + 5,"&cd->lock",&chg_ulog_probe___key);
  *(undefined4 *)(plVar2 + 0xb) = 0;
  __init_swait_queue_head(plVar2 + 0xc,"&x->wait",&init_completion___key);
  plVar2[0xf] = 0xfffffffe0;
  plVar2[0x10] = (long)(plVar2 + 0x10);
  plVar2[0x11] = (long)(plVar2 + 0x10);
  plVar2[0x12] = (long)chg_ulog_work;
  init_timer_key(plVar2 + 0x15,&delayed_work_timer_fn,0x200000,0,0);
  *(undefined4 *)((long)plVar2 + 0x210c) = 1000;
  *(long **)(param_1 + 0xa8) = plVar2;
  *plVar2 = lVar6;
  local_58 = CONCAT44(local_58._4_4_,0x800a);
  local_60 = "chg_ulog";
  local_48 = chg_ulog_callback;
  local_50 = plVar2;
  uVar3 = pmic_glink_register_client(lVar6,&local_60);
  plVar2[1] = uVar3;
  if (0xfffffffffffff000 < uVar3) {
    uVar4 = dev_err_probe(*plVar2,uVar3,"Error in registering with pmic_glink %d\n",
                          local_58 & 0xffffffff);
    goto LAB_0010062c;
  }
  uVar3 = debugfs_create_dir("charger_ulog",0);
  if (uVar3 < 0xfffffffffffff001) {
    uVar5 = debugfs_create_file_unsafe("category",0x180,uVar3,plVar2,&ulog_cat_fops);
    if (0xfffffffffffff000 < uVar5) {
      _printk(&DAT_001010a8,"chg_ulog_add_debugfs",uVar5 & 0xffffffff);
LAB_00100604:
      iVar9 = (int)uVar5;
      debugfs_remove(uVar3);
      goto LAB_0010060c;
    }
    uVar5 = debugfs_create_file_unsafe("level",0x180,uVar3,plVar2,&ulog_level_fops);
    if (0xfffffffffffff000 < uVar5) {
      puVar7 = &DAT_00101397;
LAB_001005f4:
      _printk(puVar7,"chg_ulog_add_debugfs",uVar5 & 0xffffffff);
      goto LAB_00100604;
    }
    uVar5 = debugfs_create_file_unsafe("enable",0x180,uVar3,plVar2,&ulog_en_fops);
    if (0xfffffffffffff000 < uVar5) {
      puVar7 = &DAT_00101466;
      goto LAB_001005f4;
    }
    uVar5 = debugfs_create_file_unsafe("time_ms",0x180,uVar3,plVar2,&ulog_time_fops);
    if (0xfffffffffffff000 < uVar5) {
      puVar7 = &DAT_001012f4;
      goto LAB_001005f4;
    }
    plVar2[2] = uVar3;
LAB_001004fc:
    lVar6 = ipc_log_context_create(10,"charger_ulog",0);
    plVar2[3] = lVar6;
    if (lVar6 == 0) {
      pmic_glink_unregister_client(plVar2[1]);
      debugfs_remove(plVar2[2]);
      lVar6 = *plVar2;
      pcVar8 = "Error in creating charger_ulog\n";
    }
    else {
      lVar6 = ipc_log_context_create(8,"charger_ulog_init",0);
      uVar4 = 0;
      plVar2[4] = lVar6;
      if (lVar6 != 0) goto LAB_0010062c;
      pmic_glink_unregister_client(plVar2[1]);
      ipc_log_context_destroy(plVar2[3]);
      debugfs_remove(plVar2[2]);
      lVar6 = *plVar2;
      pcVar8 = "Error in creating charger_ulog_init\n";
    }
    uVar4 = 0xffffffed;
  }
  else {
    _printk(&DAT_001011cb,"chg_ulog_add_debugfs",uVar3 & 0xffffffff);
    iVar9 = (int)uVar3;
LAB_0010060c:
    if (iVar9 == 0) goto LAB_001004fc;
    pmic_glink_unregister_client(plVar2[1]);
    lVar6 = *plVar2;
    pcVar8 = "Error in creating debugfs\n";
    uVar4 = 0xffffffea;
  }
  uVar4 = dev_err_probe(lVar6,uVar4,pcVar8);
LAB_0010062c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// chg_ulog_remove @ 00100660 size=112
// signature: undefined chg_ulog_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 chg_ulog_remove(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  debugfs_remove(*(undefined8 *)(lVar2 + 0x10));
  cancel_delayed_work_sync(lVar2 + 0x78);
  iVar1 = pmic_glink_unregister_client(*(undefined8 *)(lVar2 + 8));
  if (iVar1 < 0) {
    _printk(&DAT_0010124e,"chg_ulog_remove",iVar1);
  }
  ipc_log_context_destroy(*(undefined8 *)(lVar2 + 0x18));
  ipc_log_context_destroy(*(undefined8 *)(lVar2 + 0x20));
  return 0;
}



//------------------------------------------------------------
// chg_ulog_work @ 001006d4 size=324
// signature: undefined chg_ulog_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void chg_ulog_work(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = param_1 + -0x50;
  local_58 = 0x10000800a;
  local_50 = 0x18;
  if (*(char *)(param_1 + 0x2099) != '\0') {
    local_50 = 0x23;
  }
  uStack_4c = 0x2000;
  mutex_lock(lVar3);
  *(undefined4 *)(param_1 + -0x20) = 0;
  iVar1 = pmic_glink_write(*(undefined8 *)(param_1 + -0x70),&local_58,0x10);
  if (iVar1 == 0) {
    iVar1 = wait_for_completion_timeout((undefined4 *)(param_1 + -0x20),0xfa);
    if (iVar1 != 0) {
      mutex_unlock(lVar3);
      if ((*(char *)(param_1 + 0x2098) != '\0') || (*(char *)(param_1 + 0x2099) != '\0')) {
        uVar2 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x2094));
        queue_delayed_work_on(0x20,_system_wq,param_1,uVar2);
      }
      goto LAB_001007a0;
    }
    _printk(&DAT_00101430,"chg_ulog_write");
    iVar1 = -0x6e;
  }
  mutex_unlock(lVar3);
  _printk(&DAT_001010da,"chg_ulog_work",iVar1);
LAB_001007a0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// chg_ulog_callback @ 0010081c size=356
// signature: undefined chg_ulog_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 chg_ulog_callback(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  iVar2 = *(int *)(param_2 + 8);
  if ((iVar2 == 0x18) || (iVar2 == 0x23)) {
    if (param_3 == 0x200c) {
      pcVar3 = (char *)(param_1 + 0x100);
      memcpy(pcVar3,(void *)(param_2 + 0xc),0x2000);
      lVar1 = 0x20;
      if (*(int *)(param_2 + 8) != 0x23) {
        lVar1 = 0x18;
      }
      uVar4 = *(undefined8 *)(param_1 + lVar1);
      local_40 = pcVar3;
      if (*(char *)(param_1 + 0x100) == '\0') {
        if (*(char *)(param_1 + 0x2111) != '\0') {
          *(undefined1 *)(param_1 + 0x2111) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x20ff) = 0;
        pcVar3 = strsep(&local_40,"\n");
        if (pcVar3 != (char *)0x0) {
          do {
            ipc_log_string(uVar4,&DAT_0010119f,pcVar3);
            pcVar3 = strsep(&local_40,"\n");
          } while (pcVar3 != (char *)0x0);
        }
      }
    }
    else {
      _printk(&DAT_00101344,"handle_ulog_message",0x200c);
    }
  }
  else if (iVar2 != 0x19) {
    _printk(&DAT_001013fc,"chg_ulog_callback");
    goto LAB_0010094c;
  }
  complete(param_1 + 0x58);
LAB_0010094c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ulog_cat_fops_open @ 00100984 size=52
// signature: undefined ulog_cat_fops_open(void)
// callers: []
//------------------------------------------------------------

void ulog_cat_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,ulog_cat_get,ulog_cat_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// ulog_cat_get @ 001009bc size=16
// signature: undefined ulog_cat_get(void)
// callers: []
//------------------------------------------------------------

undefined8 ulog_cat_get(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x2100);
  return 0;
}



//------------------------------------------------------------
// ulog_cat_set @ 001009d0 size=336
// signature: undefined ulog_cat_set(void)
// callers: []
//------------------------------------------------------------

int ulog_cat_set(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (*(char *)(param_1 + 0x2110) == '\0') {
    if (*(long *)(param_1 + 0x2100) == param_2) {
      iVar2 = 0;
    }
    else {
      lVar1 = param_1 + 0x28;
      local_68 = 0x10000800a;
      local_60 = 0x19;
      local_50 = (ulong)*(uint *)(param_1 + 0x2108);
      local_58 = param_2;
      mutex_lock(lVar1);
      *(undefined4 *)(param_1 + 0x58) = 0;
      iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + 8),&local_68,0x20);
      if (iVar2 == 0) {
        iVar2 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x58),0xfa);
        if (iVar2 != 0) {
          mutex_unlock(lVar1);
          iVar2 = 0;
          *(long *)(param_1 + 0x2100) = param_2;
          goto LAB_00100a88;
        }
        _printk(&DAT_00101430,"chg_ulog_write");
        iVar2 = -0x6e;
      }
      mutex_unlock(lVar1);
      _printk(&DAT_00101073,"ulog_cat_set",iVar2);
    }
  }
  else {
    _printk(&DAT_00101496,"ulog_cat_set");
    iVar2 = -0x16;
  }
LAB_00100a88:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ulog_level_fops_open @ 00100b24 size=52
// signature: undefined ulog_level_fops_open(void)
// callers: []
//------------------------------------------------------------

void ulog_level_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,ulog_level_get,ulog_level_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// ulog_level_get @ 00100b5c size=16
// signature: undefined ulog_level_get(void)
// callers: []
//------------------------------------------------------------

undefined8 ulog_level_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x2108);
  return 0;
}



//------------------------------------------------------------
// ulog_level_set @ 00100b70 size=336
// signature: undefined ulog_level_set(void)
// callers: []
//------------------------------------------------------------

int ulog_level_set(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (*(char *)(param_1 + 0x2110) == '\0') {
    if (*(uint *)(param_1 + 0x2108) == param_2) {
      iVar2 = 0;
    }
    else {
      lVar1 = param_1 + 0x28;
      local_58 = *(undefined8 *)(param_1 + 0x2100);
      local_68 = 0x10000800a;
      local_60 = 0x19;
      local_50 = (ulong)param_2;
      mutex_lock(lVar1);
      *(undefined4 *)(param_1 + 0x58) = 0;
      iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + 8),&local_68,0x20);
      if (iVar2 == 0) {
        iVar2 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x58),0xfa);
        if (iVar2 != 0) {
          mutex_unlock(lVar1);
          iVar2 = 0;
          *(uint *)(param_1 + 0x2108) = param_2;
          goto LAB_00100c28;
        }
        _printk(&DAT_00101430,"chg_ulog_write");
        iVar2 = -0x6e;
      }
      mutex_unlock(lVar1);
      _printk(&DAT_00101115,"ulog_level_set",iVar2);
    }
  }
  else {
    _printk(&DAT_00101296,"ulog_level_set");
    iVar2 = -0x16;
  }
LAB_00100c28:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ulog_en_fops_open @ 00100cc4 size=52
// signature: undefined ulog_en_fops_open(void)
// callers: []
//------------------------------------------------------------

void ulog_en_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,ulog_en_get,ulog_en_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// ulog_en_get @ 00100cfc size=20
// signature: undefined ulog_en_get(void)
// callers: []
//------------------------------------------------------------

undefined8 ulog_en_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(byte *)(param_1 + 0x2110);
  return 0;
}



//------------------------------------------------------------
// ulog_en_set @ 00100d14 size=148
// signature: undefined ulog_en_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ulog_en_set(long param_1,long param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  bVar1 = param_2 != 0;
  if ((bool)*(char *)(param_1 + 0x2110) != bVar1) {
    if (*(long *)(param_1 + 0x2100) == 0x100000000) {
      *(bool *)(param_1 + 0x2111) = bVar1;
    }
    else {
      *(char *)(param_1 + 0x2110) = bVar1;
    }
    if (param_2 == 0) {
      cancel_delayed_work_sync(param_1 + 0x78);
    }
    else {
      uVar2 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x210c));
      queue_delayed_work_on(0x20,_system_wq,param_1 + 0x78,uVar2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ulog_time_fops_open @ 00100dac size=52
// signature: undefined ulog_time_fops_open(void)
// callers: []
//------------------------------------------------------------

void ulog_time_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,ulog_time_get,ulog_time_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// ulog_time_get @ 00100de4 size=16
// signature: undefined ulog_time_get(void)
// callers: []
//------------------------------------------------------------

undefined8 ulog_time_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x210c);
  return 0;
}



//------------------------------------------------------------
// ulog_time_set @ 00100df8 size=48
// signature: undefined ulog_time_set(void)
// callers: []
//------------------------------------------------------------

undefined8 ulog_time_set(long param_1,ulong param_2)

{
  if (*(uint *)(param_1 + 0x210c) == param_2) {
    return 0;
  }
  if (param_2 < 500) {
    return 0xffffffea;
  }
  *(int *)(param_1 + 0x210c) = (int)param_2;
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100e2c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&chg_ulog_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100e5c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&chg_ulog_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103018 size=1
// signature: undefined __mutex_init(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103020 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00103030 size=1
// signature: undefined init_timer_key(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00103038 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00103040 size=1
// signature: undefined dev_err_probe(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00103048 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00103050 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00103058 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [chg_ulog_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00103060 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [chg_ulog_probe, chg_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00103068 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [chg_ulog_probe, chg_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103070 size=1
// signature: undefined debugfs_remove(void)
// callers: [chg_ulog_probe, chg_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103078 size=1
// signature: undefined _printk(void)
// callers: [chg_ulog_work, ulog_cat_set, chg_ulog_probe, ulog_level_set, chg_ulog_remove, chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [chg_ulog_work, ulog_cat_set, chg_ulog_probe, ulog_level_set, chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00103088 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [ulog_en_set, chg_ulog_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103090 size=1
// signature: undefined mutex_lock(void)
// callers: [chg_ulog_work, ulog_cat_set, ulog_level_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00103098 size=1
// signature: undefined pmic_glink_write(void)
// callers: [chg_ulog_work, ulog_cat_set, ulog_level_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 001030a0 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [chg_ulog_work, ulog_cat_set, ulog_level_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [chg_ulog_work, ulog_cat_set, ulog_level_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 001030b0 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [ulog_en_set, chg_ulog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001030c0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ulog_en_set, chg_ulog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001030c8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001030d0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001030d8 size=1
// signature: undefined ipc_log_string(void)
// callers: [chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001030e0 size=1
// signature: undefined complete(void)
// callers: [chg_ulog_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 001030e8 size=1
// signature: undefined simple_attr_open(void)
// callers: [ulog_cat_fops_open, ulog_level_fops_open, ulog_time_fops_open, ulog_en_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



