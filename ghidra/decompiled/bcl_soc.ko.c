// Decompiled by Ghidra 12.2
// Program: bcl_soc.ko
// Image base: 00100000

//------------------------------------------------------------
// bcl_soc_probe @ 0010021c size=660
// signature: undefined bcl_soc_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 bcl_soc_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  lVar6 = param_1 + 0x10;
  local_38 = *(long *)(lVar1 + 0x638);
  bcl_perph = (long *)devm_kmalloc(lVar6,0x120,0xdc0);
  if (bcl_perph == (long *)0x0) {
    uVar5 = 0xfffffff4;
    goto LAB_001003ac;
  }
  __mutex_init(bcl_perph + 0xc,"&bcl_perph->state_trans_lock",&bcl_soc_probe___key);
  plVar2 = bcl_perph;
  *bcl_perph = lVar6;
  plVar2[0x16] = (long)bcl_read_soc;
  plVar2[0x17] = (long)bcl_set_soc;
  plVar2[4] = 0xfffffffe0;
  plVar2[0x20] = (long)bcl_soc_get_trend;
  plVar2[5] = (long)(plVar2 + 5);
  plVar2[6] = (long)(plVar2 + 5);
  plVar2[7] = (long)bcl_evaluate_soc;
  plVar2[1] = (long)battery_supply_callback;
  iVar3 = power_supply_reg_notifier();
  if (iVar3 < 0) {
    _printk(&DAT_00100bfe,"bcl_soc","bcl_soc_probe",iVar3);
LAB_0010045c:
    uVar5 = 0xfffffdfb;
  }
  else {
    local_40 = 0;
    if (bcl_read_soc_batt_psy == 0) {
      bcl_read_soc_batt_psy = power_supply_get_by_name("battery");
      if (bcl_read_soc_batt_psy != 0) goto LAB_001002fc;
    }
    else {
LAB_001002fc:
      iVar3 = power_supply_get_property(bcl_read_soc_batt_psy,0x2f,&local_40);
      if ((iVar3 != 0) && (_printk(&DAT_00100bd4,"bcl_soc","bcl_read_soc",iVar3), iVar3 == -0x3d))
      goto LAB_0010045c;
    }
    uVar4 = devm_thermal_of_zone_register(lVar6,0,bcl_perph,bcl_perph + 0x14);
    bcl_perph[0x13] = uVar4;
    if (uVar4 < 0xfffffffffffff001) {
      if ((uVar4 != 0) && (*(long *)(uVar4 + 0x440) != 0)) {
        mutex_lock(uVar4 + 0x480);
        if (*(long *)(*(long *)(uVar4 + 0x440) + 0x20) == 0) {
          *(code **)(*(long *)(uVar4 + 0x440) + 0x20) = qti_tz_change_mode;
        }
        mutex_unlock(uVar4 + 0x480);
        uVar4 = bcl_perph[0x13];
      }
      thermal_zone_device_update(uVar4,5);
      queue_work_on(0x20,_system_wq,bcl_perph + 4);
      uVar5 = 0;
      *(long **)(param_1 + 0xa8) = bcl_perph;
      goto LAB_001003ac;
    }
    _printk(&DAT_00100bab,"bcl_soc","bcl_soc_probe",uVar4);
    uVar5 = (undefined4)bcl_perph[0x13];
    bcl_perph[0x13] = 0;
  }
  power_supply_unreg_notifier(bcl_perph + 1);
  flush_work(bcl_perph + 4);
  lVar6 = bcl_perph[0x13];
  if ((lVar6 != 0) && (*(long *)(lVar6 + 0x440) != 0)) {
    mutex_lock(lVar6 + 0x480);
    *(undefined8 *)(*(long *)(lVar6 + 0x440) + 0x20) = 0;
    mutex_unlock(lVar6 + 0x480);
  }
LAB_001003ac:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// bcl_soc_remove @ 001004b4 size=112
// signature: undefined bcl_soc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_soc_remove(void)

{
  long lVar1;
  
  power_supply_unreg_notifier(bcl_perph + 8);
  flush_work(bcl_perph + 0x20);
  lVar1 = *(long *)(bcl_perph + 0x98);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x440) != 0)) {
    mutex_lock(lVar1 + 0x480);
    *(undefined8 *)(*(long *)(lVar1 + 0x440) + 0x20) = 0;
    mutex_unlock(lVar1 + 0x480);
  }
  return 0;
}



//------------------------------------------------------------
// bcl_read_soc @ 00100528 size=204
// signature: undefined bcl_read_soc(void)
// callers: []
//------------------------------------------------------------

int bcl_read_soc(undefined8 param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  *param_2 = 0;
  local_30 = 0;
  if (bcl_read_soc_batt_psy == 0) {
    bcl_read_soc_batt_psy = power_supply_get_by_name("battery");
    if (bcl_read_soc_batt_psy == 0) {
      iVar2 = 0;
      goto LAB_00100598;
    }
  }
  iVar2 = power_supply_get_property(bcl_read_soc_batt_psy,0x2f,&local_30);
  if (iVar2 == 0) {
    *param_2 = 100 - (int)local_30;
  }
  else {
    _printk(&DAT_00100bd4,"bcl_soc","bcl_read_soc",iVar2);
  }
LAB_00100598:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bcl_set_soc @ 001005f8 size=148
// signature: undefined bcl_set_soc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 bcl_set_soc(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(long *)(bcl_perph + 0x50) != (long)param_3) {
    mutex_lock(bcl_perph + 0x60);
    lVar2 = bcl_perph;
    *(long *)(bcl_perph + 0x50) = (long)param_3;
    uVar1 = _system_wq;
    if (param_3 == 0x7fffffff) {
      *(undefined1 *)(lVar2 + 0x90) = 0;
    }
    else {
      *(undefined1 *)(lVar2 + 0x90) = 1;
      queue_work_on(0x20,uVar1,lVar2 + 0x20);
      lVar2 = bcl_perph;
    }
    mutex_unlock(lVar2 + 0x60);
  }
  return 0;
}



//------------------------------------------------------------
// bcl_soc_get_trend @ 00100690 size=276
// signature: undefined bcl_soc_get_trend(void)
// callers: []
//------------------------------------------------------------

void bcl_soc_get_trend(long param_1,ulong param_2,int *param_3)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  code *pcVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x440) + 0x30);
    if (*(int *)(pcVar4 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1006ec);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(param_1,param_2,(long)&local_40 + 4);
    if ((int)uVar2 == 0) {
      pcVar4 = *(code **)(*(long *)(param_1 + 0x440) + 0x40);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100724);
          (*pcVar4)();
        }
        uVar2 = (*pcVar4)(param_1,param_2 & 0xffffffff,&local_40);
        if ((int)uVar2 != 0) goto LAB_00100774;
      }
      if (*(int *)(param_1 + 0x420) < local_40._4_4_) {
        if ((int)local_40 == 0) {
          iVar3 = 2;
        }
        else {
          iVar3 = (uint)(*(int *)(param_1 + 0x420) <= local_40._4_4_ - (int)local_40) << 1;
        }
      }
      else {
        iVar3 = 1;
      }
      uVar2 = 0;
      *param_3 = iVar3;
    }
  }
LAB_00100774:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// bcl_evaluate_soc @ 001007a8 size=276
// signature: undefined bcl_evaluate_soc(void)
// callers: []
//------------------------------------------------------------

void bcl_evaluate_soc(void)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*(long *)(bcl_perph + 0x98) == 0) goto LAB_00100864;
  local_30 = 0;
  if (bcl_read_soc_batt_psy == 0) {
    bcl_read_soc_batt_psy = power_supply_get_by_name("battery");
    if (bcl_read_soc_batt_psy != 0) goto LAB_001007fc;
    iVar2 = 0;
  }
  else {
LAB_001007fc:
    iVar2 = power_supply_get_property(bcl_read_soc_batt_psy,0x2f,&local_30);
    if (iVar2 != 0) {
      _printk(&DAT_00100bd4,"bcl_soc","bcl_read_soc",iVar2);
      goto LAB_00100864;
    }
    iVar2 = 100 - (int)local_30;
  }
  mutex_lock(bcl_perph + 0x60);
  if ((*(char *)(bcl_perph + 0x90) == '\0') || ((long)iVar2 < *(long *)(bcl_perph + 0x50))) {
    mutex_unlock(bcl_perph + 0x60);
  }
  else {
    lVar1 = bcl_perph + 0x60;
    *(int *)(bcl_perph + 0x58) = iVar2;
    mutex_unlock(lVar1);
    thermal_zone_device_update(*(undefined8 *)(bcl_perph + 0x98),2);
  }
LAB_00100864:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// battery_supply_callback @ 001008c0 size=80
// signature: undefined battery_supply_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 battery_supply_callback(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)*param_3,"battery");
  if (iVar1 == 0) {
    queue_work_on(0x20,_system_wq,bcl_perph + 0x20);
  }
  return 1;
}



//------------------------------------------------------------
// qti_tz_change_mode @ 00100914 size=156
// signature: undefined qti_tz_change_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_tz_change_mode(long param_1,int param_2)

{
  long *plVar1;
  
  if (param_1 != 0) {
    plVar1 = *(long **)(param_1 + 0x460);
    *(undefined8 *)(param_1 + 0x42c) = 0x8000000100000000;
    *(undefined4 *)(param_1 + 0x420) = 0xfffbd1b0;
    *(undefined4 *)(param_1 + 0x434) = 0x7fffffff;
    for (; plVar1 != (long *)(param_1 + 0x460); plVar1 = (long *)*plVar1) {
      *(undefined1 *)((long)plVar1 + -0x8c) = 0;
      if (param_2 == 0) {
        plVar1[-0xf] = 0xffffffffffffffff;
        *(undefined1 *)(plVar1[-0x13] + 0x3c8) = 0;
        thermal_cdev_update(plVar1[-0x13]);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 001009b4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&bcl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001009e4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&bcl_driver);
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
// callers: [bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00102018 size=1
// signature: undefined __mutex_init(void)
// callers: [bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00102020 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00102028 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [bcl_evaluate_soc, bcl_soc_probe, bcl_read_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00102030 size=1
// signature: undefined power_supply_get_property(void)
// callers: [bcl_evaluate_soc, bcl_soc_probe, bcl_read_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 00102038 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102040 size=1
// signature: undefined mutex_lock(void)
// callers: [bcl_soc_remove, bcl_evaluate_soc, bcl_soc_probe, bcl_set_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102048 size=1
// signature: undefined mutex_unlock(void)
// callers: [bcl_soc_remove, bcl_evaluate_soc, bcl_soc_probe, bcl_set_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00102050 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [bcl_evaluate_soc, bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00102060 size=1
// signature: undefined queue_work_on(void)
// callers: [battery_supply_callback, bcl_soc_probe, bcl_set_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102068 size=1
// signature: undefined _printk(void)
// callers: [bcl_evaluate_soc, bcl_soc_probe, bcl_read_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 00102070 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [bcl_soc_remove, bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 00102078 size=1
// signature: undefined flush_work(void)
// callers: [bcl_soc_remove, bcl_soc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [bcl_soc_get_trend, bcl_evaluate_soc, bcl_soc_probe, bcl_read_soc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102088 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [battery_supply_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cdev_update @ 00102090 size=1
// signature: undefined thermal_cdev_update(void)
// callers: [qti_tz_change_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cdev_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



