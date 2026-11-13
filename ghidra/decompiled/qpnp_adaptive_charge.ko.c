// Decompiled by Ghidra 12.2
// Program: qpnp_adaptive_charge.ko
// Image base: 00100000

//------------------------------------------------------------
// cleanup_module @ 00100294 size=180
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (DAT_00100eb0 != '\0') {
    cancel_work_sync(&DAT_00100e80);
    power_supply_unreg_notifier(&DAT_00100e68);
  }
  if (DAT_00100eb2 != '\0') {
    mmi_vote_charging_disable("ADAPTIVE_CHARGING_VOTER",0);
    DAT_00100eb2 = '\0';
    _printk(&DAT_0010123e,"stop_charging");
  }
  if (DAT_00100eb1 != '\0') {
    mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",0);
    DAT_00100eb1 = '\0';
    _printk(&DAT_00101367,"suspend_charging");
  }
  return;
}



//------------------------------------------------------------
// set_upper_limit @ 0010034c size=208
// signature: undefined set_upper_limit(void)
// callers: []
//------------------------------------------------------------

void set_upper_limit(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  long local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = 0;
  if (DAT_00100eb0 == '\0') {
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = kstrtoll(param_1,0,&local_20);
    if ((int)uVar2 == 0) {
      if ((lower_limit == -1) && (local_20 == -1)) {
        upper_limit = 0xffffffff;
      }
      else {
        upper_limit = (undefined4)local_20;
        if (local_20 <= lower_limit || 99 < local_20 - 1U) {
          upper_limit = 100;
        }
      }
      _printk(&DAT_0010126b,"set_upper_limit");
      update(&adap_chg_data);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// update @ 0010041c size=616
// signature: undefined update(void)
// callers: [set_lower_limit, update_work, set_upper_limit]
//------------------------------------------------------------

void update(long *param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (*param_1 == 0) {
LAB_0010047c:
    *(undefined4 *)(param_1 + 3) = 0xffffffff;
LAB_00100484:
    puVar3 = &DAT_001010cf;
    pcVar4 = "update";
  }
  else {
    iVar2 = power_supply_get_property(*param_1,0x2f,&local_40);
    if (iVar2 < 0) {
      _printk(&DAT_001012b8,"get_ps_int_prop",0x2f,iVar2);
      goto LAB_0010047c;
    }
    *(int *)(param_1 + 3) = (int)local_40;
    if ((int)local_40 < 0) goto LAB_00100484;
    _printk(&DAT_0010116b,"update",local_40 & 0xffffffff,upper_limit,lower_limit);
    if (upper_limit == -1) {
LAB_00100520:
      if (DAT_00100eb1 != '\0') {
        mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",0);
        puVar3 = &DAT_00101367;
        DAT_00100eb1 = '\0';
LAB_00100644:
        _printk(puVar3,"suspend_charging");
      }
LAB_00100590:
      if (DAT_00100eb2 == '\0') goto LAB_00100498;
      mmi_vote_charging_disable("ADAPTIVE_CHARGING_VOTER",0);
      puVar3 = &DAT_0010123e;
      DAT_00100eb2 = '\0';
    }
    else {
      iVar2 = (int)param_1[3];
      if (lower_limit != -1) {
        if (iVar2 < upper_limit) {
          if (lower_limit < iVar2) goto LAB_00100498;
          goto LAB_00100520;
        }
        if (DAT_00100eb1 == '\0') {
          mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",1);
          DAT_00100eb1 = '\x01';
          puVar3 = &DAT_00101105;
          goto LAB_00100644;
        }
        goto LAB_00100590;
      }
      if (upper_limit < iVar2) {
        if (DAT_00100eb1 == '\0') {
          mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",1);
          puVar3 = &DAT_00101105;
          DAT_00100eb1 = '\x01';
LAB_00100670:
          _printk(puVar3,"suspend_charging");
        }
      }
      else {
        if (iVar2 != upper_limit) {
          if (iVar2 < upper_limit + -1) {
            suspend_charging(0);
            stop_charging(0);
          }
          goto LAB_00100498;
        }
        if (DAT_00100eb1 != '\0') {
          mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",0);
          DAT_00100eb1 = '\0';
          puVar3 = &DAT_00101367;
          goto LAB_00100670;
        }
      }
      if (DAT_00100eb2 != '\0') goto LAB_00100498;
      mmi_vote_charging_disable("ADAPTIVE_CHARGING_VOTER",1);
      DAT_00100eb2 = '\x01';
      puVar3 = &DAT_001012ed;
    }
    pcVar4 = "stop_charging";
  }
  _printk(puVar3,pcVar4);
LAB_00100498:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// suspend_charging @ 00100684 size=168
// signature: undefined suspend_charging(void)
// callers: [update]
//------------------------------------------------------------

void suspend_charging(ulong param_1)

{
  if ((DAT_00100eb1 == '\0') && ((param_1 & 1) != 0)) {
    mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",1);
    DAT_00100eb1 = '\x01';
    _printk(&DAT_00101105,"suspend_charging");
  }
  if ((DAT_00100eb1 != '\0') && ((param_1 & 1) == 0)) {
    mmi_vote_charger_suspend("ADAPTIVE_CHARGING_VOTER",0);
    DAT_00100eb1 = '\0';
    _printk(&DAT_00101367,"suspend_charging");
  }
  return;
}



//------------------------------------------------------------
// stop_charging @ 0010072c size=168
// signature: undefined stop_charging(void)
// callers: [update]
//------------------------------------------------------------

void stop_charging(ulong param_1)

{
  if ((DAT_00100eb2 == '\0') && ((param_1 & 1) != 0)) {
    mmi_vote_charging_disable("ADAPTIVE_CHARGING_VOTER",1);
    DAT_00100eb2 = '\x01';
    _printk(&DAT_001012ed,"stop_charging");
  }
  if ((DAT_00100eb2 != '\0') && ((param_1 & 1) == 0)) {
    mmi_vote_charging_disable("ADAPTIVE_CHARGING_VOTER",0);
    DAT_00100eb2 = '\0';
    _printk(&DAT_0010123e,"stop_charging");
  }
  return;
}



//------------------------------------------------------------
// set_lower_limit @ 001007d8 size=180
// signature: undefined set_lower_limit(void)
// callers: []
//------------------------------------------------------------

void set_lower_limit(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  long local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = 0;
  if (DAT_00100eb0 == '\0') {
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = kstrtoll(param_1,0,&local_20);
    if ((int)uVar2 == 0) {
      lower_limit = (undefined4)local_20;
      if (upper_limit <= local_20 || local_20 < -1) {
        lower_limit = 0xffffffff;
      }
      _printk(&DAT_001011b7,"set_lower_limit");
      update(&adap_chg_data);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// set_blocking @ 00100890 size=8
// signature: undefined set_blocking(void)
// callers: []
//------------------------------------------------------------

undefined8 set_blocking(void)

{
  return 0xffffffea;
}



//------------------------------------------------------------
// get_blocking @ 0010089c size=312
// signature: undefined get_blocking(void)
// callers: []
//------------------------------------------------------------

void get_blocking(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (DAT_00100eb0 == '\0') {
    blocking = 0;
    goto LAB_0010096c;
  }
  local_30 = 0;
  if (DAT_00100e58 == 0) {
LAB_00100920:
    uVar3 = 0;
  }
  else {
    iVar2 = power_supply_get_property(DAT_00100e58,4,&local_30);
    if (iVar2 < 0) {
      _printk(&DAT_001012b8,"get_ps_int_prop",4,iVar2);
      goto LAB_00100920;
    }
    uVar3 = (uint)(0 < (int)local_30);
  }
  local_30 = 0;
  if (DAT_00100e50 != 0) {
    iVar2 = power_supply_get_property(DAT_00100e50,4,&local_30);
    if (iVar2 < 0) {
      _printk(&DAT_001012b8,"get_ps_int_prop",4,iVar2);
    }
    else if (0 < (int)local_30) {
      uVar3 = 1;
    }
  }
  blocking = 0;
  if (DAT_00100eb1 != '\0' || DAT_00100eb2 != '\0') {
    blocking = uVar3;
  }
LAB_0010096c:
  scnprintf(param_1,0x1000,&DAT_0010140f);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qpnp_adap_chg_init_work @ 001009d4 size=472
// signature: undefined qpnp_adap_chg_init_work(void)
// callers: [init_module, adap_reinit_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qpnp_adap_chg_init_work(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  upper_limit = 0xffffffff;
  lower_limit = 0xffffffff;
  _DAT_00100eb0 = 0;
  DAT_00100eb2 = 0;
  adap_chg_data = power_supply_get_by_name("battery");
  if (adap_chg_data == 0) {
    puVar4 = &DAT_00101204;
  }
  else {
    DAT_00100e58 = power_supply_get_by_name(&DAT_00101363);
    if (DAT_00100e58 != 0) {
      DAT_00100e50 = power_supply_get_by_name("wireless");
      if (DAT_00100e50 == 0) {
        _printk(&DAT_001013d9,"qpnp_adap_chg_init_work");
      }
      local_30 = 0;
      if (adap_chg_data == 0) {
LAB_00100b50:
        DAT_00100e60 = -1;
LAB_00100b5c:
        puVar4 = &DAT_00101325;
      }
      else {
        iVar2 = power_supply_get_property(adap_chg_data,0x2f,&local_30);
        if (iVar2 < 0) {
          _printk(&DAT_001012b8,"get_ps_int_prop",0x2f,iVar2);
          goto LAB_00100b50;
        }
        DAT_00100e60 = (int)local_30;
        if ((int)local_30 < 0) goto LAB_00100b5c;
        DAT_00100e68 = ps_notify_callback;
        iVar2 = power_supply_reg_notifier();
        if (iVar2 == 0) {
          DAT_00100e80 = 0xfffffffe0;
          DAT_00100e88 = &DAT_00100e88;
          DAT_00100e90 = &DAT_00100e88;
          DAT_00100e98 = update_work;
          queue_work_on(0x20,_system_wq,&DAT_00100e80);
          uVar3 = 0;
          _DAT_00100eb0 = CONCAT11(DAT_00100eb1,1);
          goto LAB_00100b80;
        }
        puVar4 = &DAT_001013a6;
      }
      _printk(puVar4,"qpnp_adap_chg_init_work");
      uVar3 = 1;
      goto LAB_00100b80;
    }
    puVar4 = &DAT_00101412;
  }
  _printk(puVar4,"qpnp_adap_chg_init_work");
  uVar3 = 2;
LAB_00100b80:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// adap_reinit_work @ 00100bb0 size=84
// signature: undefined adap_reinit_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void adap_reinit_work(void)

{
  int iVar1;
  
  iVar1 = qpnp_adap_chg_init_work();
  if (iVar1 == 2) {
    cancel_delayed_work(&DAT_00100eb8);
    queue_delayed_work_on(0x20,_system_wq,&DAT_00100eb8,0x4e2);
  }
  return;
}



//------------------------------------------------------------
// ps_notify_callback @ 00100c08 size=124
// signature: undefined ps_notify_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ps_notify_callback(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  char *__s1;
  
  if ((((param_2 == 0) && (param_3 != (undefined8 *)0x0)) && (((undefined8 *)*param_3)[6] != 0)) &&
     (((__s1 = *(char **)*param_3, __s1 != (char *)0x0 &&
       (iVar1 = strncmp(__s1,"battery",8), iVar1 == 0)) && (upper_limit != -1)))) {
    queue_work_on(0x20,_system_wq,param_1 + 0x18);
  }
  return 0;
}



//------------------------------------------------------------
// update_work @ 00100c88 size=192
// signature: undefined update_work(void)
// callers: []
//------------------------------------------------------------

void update_work(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + -0x38);
  local_30 = 0;
  if (lVar2 != 0) {
    iVar1 = power_supply_get_property(lVar2,0x2f,&local_30);
    if (iVar1 < 0) {
      _printk(&DAT_001012b8,"get_ps_int_prop",0x2f,iVar1);
    }
    else if (-1 < (int)local_30) {
      if ((int)local_30 != *(int *)(param_1 + -0x20)) {
        update((long *)(param_1 + -0x38));
      }
      goto LAB_00100d1c;
    }
  }
  _printk(&DAT_001010cf,"update_work");
LAB_00100d1c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100d4c size=140
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  undefined8 uVar1;
  
  uVar1 = qpnp_adap_chg_init_work();
  if ((int)uVar1 == 2) {
    _DAT_00100eb8 = 0xfffffffe0;
    _DAT_00100ec0 = &DAT_00100ec0;
    _DAT_00100ec8 = &DAT_00100ec0;
    _DAT_00100ed0 = adap_reinit_work;
    init_timer_key(&DAT_00100ee8,&delayed_work_timer_fn,0x200000,0,0);
    queue_delayed_work_on(0x20,_system_wq,&DAT_00100eb8,0x4e2);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_timer_key @ 00102008 size=1
// signature: undefined init_timer_key(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00102018 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [init_module, adap_reinit_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00102020 size=1
// signature: undefined cancel_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 00102028 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_vote_charging_disable @ 00102030 size=1
// signature: undefined mmi_vote_charging_disable(void)
// callers: [stop_charging, cleanup_module, update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_vote_charging_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102038 size=1
// signature: undefined _printk(void)
// callers: [set_lower_limit, update_work, stop_charging, get_blocking, cleanup_module, qpnp_adap_chg_init_work, update, set_upper_limit, suspend_charging]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_vote_charger_suspend @ 00102040 size=1
// signature: undefined mmi_vote_charger_suspend(void)
// callers: [cleanup_module, update, suspend_charging]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_vote_charger_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00102048 size=1
// signature: undefined kstrtoll(void)
// callers: [set_lower_limit, set_upper_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [set_lower_limit, update_work, get_blocking, qpnp_adap_chg_init_work, update, set_upper_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00102058 size=1
// signature: undefined power_supply_get_property(void)
// callers: [update_work, get_blocking, qpnp_adap_chg_init_work, update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102060 size=1
// signature: undefined scnprintf(void)
// callers: [get_blocking]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00102068 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [qpnp_adap_chg_init_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00102070 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [qpnp_adap_chg_init_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00102078 size=1
// signature: undefined queue_work_on(void)
// callers: [ps_notify_callback, qpnp_adap_chg_init_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00102080 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [adap_reinit_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00102088 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [ps_notify_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



