// Decompiled by Ghidra 12.2
// Program: mmi_lpd_mitigate.ko
// Image base: 00100000

//------------------------------------------------------------
// def_mitigate_mode_show @ 00100244 size=92
// signature: undefined def_mitigate_mode_show(void)
// callers: []
//------------------------------------------------------------

long def_mitigate_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_00100e5e,"def_mitigate_mode_show");
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x80,&DAT_00100d01,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x1c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// def_mitigate_mode_store @ 001002a4 size=212
// signature: undefined def_mitigate_mode_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
def_mitigate_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  ulong local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  if (lVar4 == 0) {
    _printk(&DAT_00100e5e,"def_mitigate_mode_store");
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    uVar1 = _system_wq;
    if (iVar2 == 0) {
      uVar3 = 4;
      if (local_30 < 4) {
        uVar3 = (undefined4)local_30;
      }
      *(undefined4 *)(lVar4 + 0x1c) = uVar3;
      queue_work_on(0x20,uVar1,lVar4 + 0x20);
    }
    else {
      _printk(&DAT_00101071,"def_mitigate_mode_store");
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mitigate_mode_show @ 0010037c size=92
// signature: undefined mitigate_mode_show(void)
// callers: []
//------------------------------------------------------------

long mitigate_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_00100e5e,"mitigate_mode_show");
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x80,&DAT_00100d01,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x18));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// mitigate_mode_store @ 001003dc size=212
// signature: undefined mitigate_mode_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
mitigate_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  ulong local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  if (lVar4 == 0) {
    _printk(&DAT_00100e5e,"mitigate_mode_store");
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    uVar1 = _system_wq;
    if (iVar2 == 0) {
      uVar3 = 4;
      if (local_30 < 4) {
        uVar3 = (undefined4)local_30;
      }
      *(undefined4 *)(lVar4 + 0x18) = uVar3;
      queue_work_on(0x20,uVar1,lVar4 + 0x20);
    }
    else {
      _printk(&DAT_00101071,"mitigate_mode_store");
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// lpd_mitigate_probe @ 001004b4 size=440
// signature: undefined lpd_mitigate_probe(void)
// callers: []
//------------------------------------------------------------

int lpd_mitigate_probe(long param_1)

{
  uint *puVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined *puVar5;
  
  plVar3 = (long *)devm_kmalloc(param_1 + 0x10,0x98,0xdc0);
  if (plVar3 == (long *)0x0) {
    iVar2 = -0xc;
  }
  else {
    plVar3[4] = 0xfffffffe0;
    plVar3[5] = (long)(plVar3 + 5);
    plVar3[6] = (long)(plVar3 + 5);
    plVar3[7] = (long)lpd_mitigate_work;
    *(long **)(param_1 + 0xa8) = plVar3;
    plVar3[2] = 0x7fffffff7fffffff;
    uVar4 = *(undefined8 *)(param_1 + 0x2f8);
    *plVar3 = param_1 + 0x10;
    plVar3[1] = 0x7fffffff7fffffff;
    iVar2 = of_property_read_variable_u32_array
                      (uVar4,"mmi,default-mitigate-mode-cfg",(uint *)((long)plVar3 + 0x1c),1,0);
    if ((iVar2 < 0) || (4 < *(uint *)((long)plVar3 + 0x1c))) {
      *(undefined4 *)(plVar3 + 3) = 1;
    }
    puVar1 = (uint *)(plVar3 + 3);
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"mmi,mitigate-mode-cfg",puVar1,1,0);
    if ((iVar2 < 0) || (4 < *puVar1)) {
      *puVar1 = 3;
    }
    plVar3[10] = (long)lpd_mitigate_notify_cb;
    iVar2 = relay_register_action(1,3);
    if (iVar2 < 0) {
      puVar5 = &DAT_00100d18;
    }
    else {
      plVar3[0xd] = (long)lpd_psy_notifier_call;
      iVar2 = power_supply_reg_notifier();
      if (iVar2 == 0) {
        iVar2 = device_create_file(*plVar3,&dev_attr_def_mitigate_mode);
        if (iVar2 == 0) {
          iVar2 = device_create_file(*plVar3,&dev_attr_mitigate_mode);
          if (iVar2 == 0) {
            puVar5 = &DAT_00101039;
          }
          else {
            puVar5 = &DAT_00100c7c;
          }
        }
        else {
          puVar5 = &DAT_00100ee4;
        }
        _printk(puVar5,"lpd_mitigate_probe");
        return iVar2;
      }
      puVar5 = &DAT_001010e0;
    }
    _printk(puVar5,"lpd_mitigate_probe",iVar2);
  }
  return iVar2;
}



//------------------------------------------------------------
// lpd_mitigate_remove @ 00100670 size=120
// signature: undefined lpd_mitigate_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpd_mitigate_remove(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  cancel_work_sync(puVar1 + 4);
  device_remove_file(*puVar1,&dev_attr_mitigate_mode);
  device_remove_file(*puVar1,&dev_attr_def_mitigate_mode);
  power_supply_unreg_notifier(puVar1 + 0xd);
  relay_unregister_action(1,3,puVar1 + 10);
  if (puVar1[0x10] != 0) {
    power_supply_put();
    puVar1[0x10] = 0;
  }
  return 0;
}



//------------------------------------------------------------
// lpd_mitigate_work @ 001006ec size=1040
// signature: undefined lpd_mitigate_work(void)
// callers: []
//------------------------------------------------------------

void lpd_mitigate_work(long param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  int local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulong local_b8 [17];
  
  lVar4 = sp_el0;
  local_b8[0x10] = *(long *)(lVar4 + 0x638);
  local_c8 = 0;
  uStack_c0 = 0;
  if (param_1 == 0x20) {
    _printk(&DAT_00100d84,"lpd_mitigate_work");
    goto LAB_0010089c;
  }
  iVar3 = *(int *)(param_1 + -0x14);
  if ((lpd_mitigate_work_tud_status != iVar3) || (iVar3 == 0x7fffffff)) {
    lpd_mitigate_work_tud_status = iVar3;
    if (iVar3 == 0x7fffffff) {
      lpd_mitigate_work_tud_status = 0;
      *(undefined4 *)(param_1 + -0x14) = 0;
    }
    iVar3 = lpd_mitigate_work_tud_status;
    if (*(long *)(param_1 + 0x60) == 0) {
      lVar4 = power_supply_get_by_name("battery");
      *(long *)(param_1 + 0x60) = lVar4;
      if (lVar4 == 0) {
        _printk(&DAT_00100dde,"lpd_notify_uevent");
        goto LAB_001007e8;
      }
      iVar3 = *(int *)(param_1 + -0x14);
    }
    pcVar1 = "false";
    if (iVar3 != 0) {
      pcVar1 = "true";
    }
    local_b8[0xe] = 0;
    local_b8[0xf] = 0;
    local_b8[0xc] = 0;
    local_b8[0xd] = 0;
    local_b8[10] = 0;
    local_b8[0xb] = 0;
    local_b8[8] = 0;
    local_b8[9] = 0;
    local_b8[6] = 0;
    local_b8[7] = 0;
    local_b8[4] = 0;
    local_b8[5] = 0;
    local_b8[2] = 0;
    local_b8[3] = 0;
    local_b8[0] = 0;
    local_b8[1] = 0;
    scnprintf(local_b8,0x80,"POWER_SUPPLY_TUD_PRESENT=%s",pcVar1);
    *(ulong **)(param_1 + 0x68) = local_b8;
    *(undefined8 *)(param_1 + 0x70) = 0;
    kobject_uevent_env(*(long *)(param_1 + 0x60) + 0x38,2);
  }
LAB_001007e8:
  iVar3 = qti_charger_get_property(0x15,&local_c8,0x10);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + -0x18);
    local_cc = iVar3;
    if ((int)local_c8 == 0) {
      iVar7 = 0;
      if (iVar3 != 0) {
        local_cc = 0;
      }
    }
    else {
      iVar7 = 1;
      if (iVar3 != 1) {
        local_cc = 1;
      }
    }
    if (iVar7 != iVar3) {
      _printk(&DAT_00100fe0,"lpd_mitigate_work",iVar3,iVar7);
      *(int *)(param_1 + -0x18) = iVar7;
      relay_notifier_fire(1,3,1,&local_cc);
      if (*(long *)(param_1 + 0x60) == 0) {
        lVar4 = power_supply_get_by_name("battery");
        *(long *)(param_1 + 0x60) = lVar4;
        if (lVar4 == 0) {
          _printk(&DAT_00100dde,"lpd_notify_uevent");
          goto LAB_00100834;
        }
      }
      pcVar1 = "false";
      if (*(int *)(param_1 + -0x18) != 0) {
        pcVar1 = "true";
      }
      local_b8[0xe] = 0;
      local_b8[0xf] = 0;
      local_b8[0xc] = 0;
      local_b8[0xd] = 0;
      local_b8[10] = 0;
      local_b8[0xb] = 0;
      local_b8[8] = 0;
      local_b8[9] = 0;
      local_b8[6] = 0;
      local_b8[7] = 0;
      local_b8[4] = 0;
      local_b8[5] = 0;
      local_b8[2] = 0;
      local_b8[3] = 0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      scnprintf(local_b8,0x80,"POWER_SUPPLY_LPD_PRESENT=%s",pcVar1);
      *(ulong **)(param_1 + 0x68) = local_b8;
      *(undefined8 *)(param_1 + 0x70) = 0;
      kobject_uevent_env(*(long *)(param_1 + 0x60) + 0x38,2);
    }
LAB_00100834:
    if (uStack_c0._4_4_ != *(int *)(param_1 + -0x10)) {
      _printk(&DAT_00100eb2,"lpd_mitigate_work");
      *(int *)(param_1 + -0x10) = uStack_c0._4_4_;
      relay_notifier_fire(1,3,3,(int *)(param_1 + -0x10));
      if (*(long *)(param_1 + 0x60) == 0) {
        lVar4 = power_supply_get_by_name("battery");
        *(long *)(param_1 + 0x60) = lVar4;
        if (lVar4 == 0) {
          _printk(&DAT_00100dde,"lpd_notify_uevent");
          goto LAB_00100848;
        }
      }
      local_b8[0xe] = 0;
      local_b8[0xf] = 0;
      local_b8[0xc] = 0;
      local_b8[0xd] = 0;
      local_b8[10] = 0;
      local_b8[0xb] = 0;
      local_b8[8] = 0;
      local_b8[9] = 0;
      local_b8[6] = 0;
      local_b8[7] = 0;
      local_b8[4] = 0;
      local_b8[5] = 0;
      local_b8[2] = 0;
      local_b8[3] = 0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      scnprintf(local_b8,0x80,"POWER_SUPPLY_CID_STATUS=%d",*(undefined4 *)(param_1 + -0x10));
      *(ulong **)(param_1 + 0x68) = local_b8;
      *(undefined8 *)(param_1 + 0x70) = 0;
      kobject_uevent_env(*(long *)(param_1 + 0x60) + 0x38,2);
    }
LAB_00100848:
    uVar2 = *(uint *)(param_1 + -0xc);
    if (*(int *)(param_1 + -0x18) == 0) {
      uVar6 = *(uint *)(param_1 + -4);
joined_r0x00100880:
      if (uVar2 == uVar6) goto LAB_00100884;
    }
    else {
      if ((*(int *)(param_1 + -0x18) == 1) && (*(int *)(param_1 + -0x14) == 1)) {
        uVar6 = *(uint *)(param_1 + -8);
        goto joined_r0x00100880;
      }
LAB_00100884:
      if (uVar2 < 4) goto LAB_0010089c;
      uVar6 = *(uint *)(param_1 + -4);
    }
    local_b8[0] = CONCAT44(local_b8[0]._4_4_,uVar6);
    if (uVar6 == uVar2) goto LAB_0010089c;
    iVar3 = qti_charger_set_property(0x2e,local_b8,4);
    if (iVar3 == 0) {
      _printk(&DAT_00100f29,"lpd_mitigate_work",*(undefined4 *)(param_1 + -0xc),
              local_b8[0] & 0xffffffff);
      *(undefined4 *)(param_1 + -0xc) = (undefined4)local_b8[0];
      goto LAB_0010089c;
    }
    puVar5 = &DAT_0010111d;
  }
  else {
    puVar5 = &DAT_00100caf;
  }
  _printk(puVar5,"lpd_mitigate_work",iVar3);
LAB_0010089c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_b8[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpd_mitigate_notify_cb @ 00100b00 size=156
// signature: undefined lpd_mitigate_notify_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lpd_mitigate_notify_cb(long param_1,long param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 != 0x50) && (param_2 == 2)) {
    iVar1 = *param_3;
    _printk(&DAT_00100fb5,"lpd_mitigate_notify_cb",iVar1);
    uVar2 = (uint)(iVar1 != 0);
    if (*(uint *)(param_1 + -0x44) != uVar2) {
      _printk(&DAT_00100dac,"lpd_mitigate_notify_cb",*(uint *)(param_1 + -0x44),uVar2);
      *(uint *)(param_1 + -0x44) = (uint)(iVar1 != 0);
      queue_work_on(0x20,_system_wq,param_1 + -0x30);
    }
  }
  return 0;
}



//------------------------------------------------------------
// lpd_psy_notifier_call @ 00100ba0 size=132
// signature: undefined lpd_psy_notifier_call(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lpd_psy_notifier_call(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0x68) {
    _printk(&DAT_001010ab,"lpd_psy_notifier_call");
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if ((param_2 == 0) && (param_3 != (undefined8 *)0x0)) {
      iVar1 = strcmp(*(char **)*param_3,"usb");
      if (iVar1 == 0) {
        queue_work_on(0x20,_system_wq,param_1 + -0x48);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100c28 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpd_mitigate_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c58 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpd_mitigate_driver);
  return;
}



//------------------------------------------------------------
// scnprintf @ 00103000 size=1
// signature: undefined scnprintf(void)
// callers: [def_mitigate_mode_show, mitigate_mode_show, lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103008 size=1
// signature: undefined _printk(void)
// callers: [def_mitigate_mode_store, mitigate_mode_store, def_mitigate_mode_show, lpd_psy_notifier_call, mitigate_mode_show, lpd_mitigate_work, lpd_mitigate_probe, lpd_mitigate_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00103010 size=1
// signature: undefined kstrtoull(void)
// callers: [def_mitigate_mode_store, mitigate_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00103020 size=1
// signature: undefined queue_work_on(void)
// callers: [def_mitigate_mode_store, mitigate_mode_store, lpd_psy_notifier_call, lpd_mitigate_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [def_mitigate_mode_store, mitigate_mode_store, lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103030 size=1
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
// platform_driver_unregister @ 00103038 size=1
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
// devm_kmalloc @ 00103040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpd_mitigate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103048 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpd_mitigate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_register_action @ 00103050 size=1
// signature: undefined relay_register_action(void)
// callers: [lpd_mitigate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_register_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00103058 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [lpd_mitigate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00103060 size=1
// signature: undefined device_create_file(void)
// callers: [lpd_mitigate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00103068 size=1
// signature: undefined cancel_work_sync(void)
// callers: [lpd_mitigate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00103070 size=1
// signature: undefined device_remove_file(void)
// callers: [lpd_mitigate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 00103078 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [lpd_mitigate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_unregister_action @ 00103080 size=1
// signature: undefined relay_unregister_action(void)
// callers: [lpd_mitigate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_unregister_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 00103088 size=1
// signature: undefined power_supply_put(void)
// callers: [lpd_mitigate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00103090 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 00103098 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_charger_get_property @ 001030a0 size=1
// signature: undefined qti_charger_get_property(void)
// callers: [lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_charger_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_notifier_fire @ 001030a8 size=1
// signature: undefined relay_notifier_fire(void)
// callers: [lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_notifier_fire(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_charger_set_property @ 001030b0 size=1
// signature: undefined qti_charger_set_property(void)
// callers: [lpd_mitigate_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_charger_set_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030b8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lpd_psy_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



