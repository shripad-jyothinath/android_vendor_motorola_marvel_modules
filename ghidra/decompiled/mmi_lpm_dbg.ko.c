// Decompiled by Ghidra 12.2
// Program: mmi_lpm_dbg.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_lpm_dbg_subsytem_sleep_call @ 0010038c size=132
// signature: undefined mmi_lpm_dbg_subsytem_sleep_call(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_lpm_dbg_subsytem_sleep_call(undefined8 param_1,long param_2,uint *param_3)

{
  if (param_3 != (uint *)0x0) {
    if (param_2 == 3) {
      DAT_001010f0 = (ulong)*param_3;
    }
    else if (param_2 == 2) {
      DAT_001010e0 = (ulong)*param_3;
    }
    else if (param_2 == 1) {
      DAT_001010d8 = (ulong)*param_3;
    }
    else {
      _printk(&DAT_001014ef,"mmi_lpm_dbg_subsytem_sleep_call",param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// sleep_dbg_show @ 00100414 size=120
// signature: undefined sleep_dbg_show(void)
// callers: []
//------------------------------------------------------------

size_t sleep_dbg_show(undefined8 param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  
  if (param_2 == (char *)0x0) {
    _printk(&DAT_00101260,"sleep_dbg_show");
    sVar2 = 0xffffffffffffffea;
  }
  else {
    iVar1 = sprintf(param_2,"%ld\n",sleep_dbg);
    if (iVar1 < 0) {
      _printk(&DAT_0010142e);
    }
    sVar2 = strlen(param_2);
  }
  return sVar2;
}



//------------------------------------------------------------
// sleep_dbg_store @ 00100490 size=152
// signature: undefined sleep_dbg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 sleep_dbg_store(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    _printk(&DAT_00101451,"sleep_dbg_store");
    param_3 = 0xffffffffffffffea;
  }
  else {
    iVar1 = kstrtoll(param_2,10,&sleep_dbg);
    if (iVar1 < 0) {
      _printk(&DAT_001012cd,"sleep_dbg_store");
    }
    _printk(&DAT_0010123f,"sleep_dbg_store",sleep_dbg);
  }
  return param_3;
}



//------------------------------------------------------------
// mmi_lpm_dbg_suspend @ 0010052c size=40
// signature: undefined mmi_lpm_dbg_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_lpm_dbg_suspend(long param_1)

{
  cancel_delayed_work(*(long *)(param_1 + 0x98) + 0x18);
  return 0;
}



//------------------------------------------------------------
// mmi_lpm_dbg_resume @ 00100558 size=72
// signature: undefined mmi_lpm_dbg_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_lpm_dbg_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  uVar1 = __msecs_to_jiffies(*(undefined4 *)(lVar2 + 0xc4));
  queue_delayed_work_on(0x20,_system_wq,lVar2 + 0x18,uVar1);
  return 0;
}



//------------------------------------------------------------
// mmi_lpm_dbg_probe @ 001005a4 size=436
// signature: undefined mmi_lpm_dbg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_lpm_dbg_probe(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return 0xfffffff4;
  }
  _printk(&DAT_001014d0,"mmi_lpm_dbg_probe");
  lVar3 = *(long *)(param_1 + 0x2f8);
  mmi_lpm_dbg_dev = param_1 + 0x10;
  *(long **)(param_1 + 0xa8) = &mmi_lpm_dbg_dev;
  if (lVar3 == 0) {
    puVar2 = &DAT_00101467;
  }
  else {
    DAT_00101018 = *(long *)(param_1 + 0x98);
    if ((param_1 + 0x10 != 0) && (DAT_00101018 != 0)) {
      iVar1 = of_property_read_variable_u32_array(lVar3,"trigger-threshold",&DAT_001010d0,1,0);
      if (iVar1 < 0) {
        DAT_001010d0 = 0x4b0;
      }
      iVar1 = of_property_read_variable_u32_array(lVar3,"check-work-delay",&DAT_001010d4,1,0);
      if (iVar1 < 0) {
        DAT_001010d4 = 200;
      }
      iVar1 = of_property_read_variable_u32_array(lVar3,"re-trigger-threshold",&DAT_001010b4,1,0);
      if (iVar1 < 0) {
        DAT_001010b4 = 0x1c20;
      }
      _printk(&DAT_0010115e,"mmi_lpm_dbg_probe",DAT_001010d0,DAT_001010d4,DAT_001010b4);
      DAT_00101028 = 0xfffffffe0;
      DAT_001010e8 = 0;
      DAT_001010b0 = 0;
      DAT_001010b8 = 0;
      DAT_001010c0 = 0;
      DAT_001010c8 = 0;
      DAT_00101030 = &DAT_00101030;
      DAT_00101038 = &DAT_00101030;
      DAT_00101040 = mmi_lpm_dbg_check_work;
      init_timer_key(&DAT_00101058,&delayed_work_timer_fn,0x200000,0,0);
      mmi_lpm_dbg_register_notifier(&subsytem_sleep_notifier);
      mmi_lpm_dbg_create_attr(DAT_00101018);
      return 0;
    }
    puVar2 = &DAT_001010f8;
  }
  _printk(puVar2,"mmi_lpm_dbg_probe");
  return 0;
}



//------------------------------------------------------------
// mmi_lpm_dbg_remove @ 0010075c size=72
// signature: undefined mmi_lpm_dbg_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_lpm_dbg_remove(long param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0xa8) == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    cancel_delayed_work(*(long *)(param_1 + 0xa8) + 0x18);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// mmi_lpm_dbg_check_work @ 001007a8 size=408
// signature: undefined mmi_lpm_dbg_check_work(void)
// callers: []
//------------------------------------------------------------

void mmi_lpm_dbg_check_work(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = sleep_dbg;
  lVar1 = param_1 + -0x18;
  if (lVar1 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x88) & 1) == 0) {
    if (sleep_dbg < 0) {
      lVar2 = *(long *)(param_1 + 0xb8);
    }
    else {
      *(long *)(param_1 + 0xb8) = sleep_dbg;
    }
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x90) = 0;
      goto LAB_001007ec;
    }
    lVar2 = *(long *)(param_1 + 0x98) + *(long *)(param_1 + 0xb0);
    *(long *)(param_1 + 0x98) = lVar2;
    _printk(&DAT_00101295,"mmi_lpm_dbg_md_check_sleep",lVar2,*(undefined4 *)(param_1 + 0x90));
    if ((*(ulong *)(param_1 + 0x98) < (ulong)*(uint *)(param_1 + 0xa8)) ||
       (*(ulong *)(param_1 + 0x98) <
        (ulong)(uint)(*(int *)(param_1 + 0x90) * *(int *)(param_1 + 0x8c)))) goto LAB_001007ec;
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
    *(byte *)(param_1 + 0x88) = *(byte *)(param_1 + 0x88) | 1;
  }
  else {
    _printk(&DAT_001013a8,"mmi_lpm_dbg_md_check_sleep");
  }
  mmi_lpm_dbg_send_uevent(lVar1);
LAB_001007ec:
  lVar2 = sleep_dbg;
  if ((*(byte *)(param_1 + 0x88) >> 1 & 1) == 0) {
    if (sleep_dbg < 0) {
      lVar2 = *(long *)(param_1 + 200);
    }
    else {
      *(long *)(param_1 + 200) = sleep_dbg;
    }
    if (lVar2 != *(long *)(param_1 + 0xc0)) {
      *(long *)(param_1 + 0xc0) = lVar2;
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined4 *)(param_1 + 0x94) = 0;
      return;
    }
    lVar2 = *(long *)(param_1 + 0xa0) + *(long *)(param_1 + 0xb0);
    *(long *)(param_1 + 0xa0) = lVar2;
    _printk(&DAT_00101295,"mmi_lpm_dbg_scp_check_sleep",lVar2,*(undefined4 *)(param_1 + 0x94));
    if (*(ulong *)(param_1 + 0xa0) < (ulong)*(uint *)(param_1 + 0xa8)) {
      return;
    }
    if (*(ulong *)(param_1 + 0xa0) <
        (ulong)(uint)(*(int *)(param_1 + 0x94) * *(int *)(param_1 + 0x8c))) {
      return;
    }
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    *(byte *)(param_1 + 0x88) = *(byte *)(param_1 + 0x88) | 2;
  }
  else {
    _printk(&DAT_001013a8,"mmi_lpm_dbg_scp_check_sleep");
  }
  mmi_lpm_dbg_send_uevent(lVar1);
  return;
}



//------------------------------------------------------------
// mmi_lpm_dbg_create_attr @ 00100940 size=176
// signature: undefined mmi_lpm_dbg_create_attr(void)
// callers: [mmi_lpm_dbg_probe]
//------------------------------------------------------------

void mmi_lpm_dbg_create_attr(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_00101481,"mmi_lpm_dbg_create_attr");
  }
  else {
    iVar1 = driver_create_file(param_1,&driver_attr_event_trigger);
    if (iVar1 == 0) {
      iVar1 = driver_create_file(param_1,&driver_attr_trigger_thresh_dbg);
      if (iVar1 == 0) {
        iVar1 = driver_create_file(param_1,&driver_attr_re_trigger_dbg);
        if (iVar1 == 0) {
          return;
        }
        uVar2 = 2;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
    _printk(&DAT_00101379,"mmi_lpm_dbg_create_attr",uVar2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// mmi_lpm_dbg_send_uevent @ 001009f0 size=504
// signature: undefined mmi_lpm_dbg_send_uevent(void)
// callers: [mmi_lpm_dbg_check_work, event_trigger_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mmi_lpm_dbg_send_uevent(undefined8 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  long lVar5;
  size_t sVar6;
  char *__s;
  undefined8 uVar7;
  byte bVar8;
  long lVar9;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  if ((param_1 == (undefined8 *)0x0) || (*(char *)(param_1 + 0x14) == '\0')) {
    puVar4 = &DAT_001011bd;
LAB_00100a38:
    _printk(puVar4,"mmi_lpm_dbg_send_uevent");
  }
  else {
    lVar5 = kmalloc_trace(_DAT_001030d8,0xdc0,0xa20);
    if (lVar5 == 0) {
      puVar4 = &DAT_001014a2;
      goto LAB_00100a38;
    }
    mutex_lock(send_uevent_mutex);
    bVar2 = *(byte *)(param_1 + 0x14);
    if ((bVar2 & 1) == 0) {
      if ((bVar2 >> 1 & 1) != 0) {
        bVar8 = 0xfd;
        lVar9 = 1;
        goto LAB_00100af4;
      }
      mutex_unlock(send_uevent_mutex);
      _printk(&DAT_001011f7,"mmi_lpm_dbg_send_uevent",*(undefined1 *)(param_1 + 0x14));
    }
    else {
      lVar9 = 0;
      bVar8 = 0xfe;
LAB_00100af4:
      __s = (&subsystem_name)[lVar9];
      sVar6 = strlen(__s);
      if (8 < sVar6 + 1) {
        fortify_panic("strcpy");
        goto LAB_00100be4;
      }
      uVar7 = param_1[lVar9 + 0x16];
      memcpy(&local_60,__s,sVar6 + 1);
      uVar1 = *(undefined4 *)((long)param_1 + lVar9 * 4 + 0xa8);
      *(byte *)(param_1 + 0x14) = bVar2 & bVar8;
      mutex_unlock(send_uevent_mutex);
      add_uevent_var(lVar5,"ABMOD=%s",&local_60);
      add_uevent_var(lVar5,"ABDUR=%ld",uVar7);
      add_uevent_var(lVar5,"CNT=%d",uVar1);
      iVar3 = kobject_uevent_env(*param_1,2,(undefined8 *)(lVar5 + 0x18));
      if (iVar3 != 0) {
        _printk(&DAT_001013f8,"mmi_lpm_dbg_send_uevent",iVar3);
      }
      _printk(&DAT_001012ae,"mmi_lpm_dbg_send_uevent",&local_60,*(undefined8 *)(lVar5 + 0x18));
    }
    kfree(lVar5);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) == local_58) {
    return;
  }
LAB_00100be4:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// event_trigger_show @ 00100bec size=136
// signature: undefined event_trigger_show(void)
// callers: []
//------------------------------------------------------------

size_t event_trigger_show(undefined8 param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  
  if (param_2 == (char *)0x0) {
    _printk(&DAT_00101260,"event_trigger_show");
    sVar2 = 0xffffffffffffffea;
  }
  else {
    iVar1 = sprintf(param_2,"%d for %s; %d for %s\n",0,"MD",1,"SCP");
    if (iVar1 < 0) {
      _printk(&DAT_0010142e);
    }
    sVar2 = strlen(param_2);
  }
  return sVar2;
}



//------------------------------------------------------------
// event_trigger_store @ 00100c78 size=288
// signature: undefined event_trigger_store(void)
// callers: []
//------------------------------------------------------------

undefined8 event_trigger_store(undefined8 param_1,char *param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    _printk(&DAT_00101451,"event_trigger_store");
  }
  else {
    iVar3 = kstrtoll(param_2,10,&local_30);
    if (iVar3 < 0) {
      _printk(&DAT_001011ab);
    }
    else {
      if ((long)local_30 < 2) {
        if (1 < local_30) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100d94);
          (*pcVar2)();
        }
        if ((local_30 & 0x1ffffffffffffffe) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x100d98);
          (*pcVar2)();
        }
        _printk(&DAT_00101139,"event_trigger_store",(&subsystem_name)[local_30]);
        DAT_001010b0 = DAT_001010b0 | (byte)(1 << (ulong)((uint)local_30 & 0x1f));
        mmi_lpm_dbg_send_uevent();
        goto LAB_00100cc0;
      }
      _printk(&DAT_001012e2,"event_trigger_store");
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00100cc0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// trigger_thresh_dbg_show @ 00100d9c size=120
// signature: undefined trigger_thresh_dbg_show(void)
// callers: []
//------------------------------------------------------------

size_t trigger_thresh_dbg_show(undefined8 param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  
  if (param_2 == (char *)0x0) {
    _printk(&DAT_00101260,"trigger_thresh_dbg_show");
    sVar2 = 0xffffffffffffffea;
  }
  else {
    iVar1 = sprintf(param_2,"%d\n",(ulong)DAT_001010d0);
    if (iVar1 < 0) {
      _printk(&DAT_0010142e);
    }
    sVar2 = strlen(param_2);
  }
  return sVar2;
}



//------------------------------------------------------------
// trigger_thresh_dbg_store @ 00100e18 size=144
// signature: undefined trigger_thresh_dbg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trigger_thresh_dbg_store(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    _printk(&DAT_00101451,"trigger_thresh_dbg_store");
    param_3 = 0xffffffffffffffea;
  }
  else {
    iVar1 = kstrtouint(param_2,10,&DAT_001010d0);
    if (iVar1 < 0) {
      _printk(&DAT_001011ab);
    }
    _printk(&DAT_00101212,"trigger_thresh_dbg_store",DAT_001010d0);
  }
  return param_3;
}



//------------------------------------------------------------
// re_trigger_dbg_show @ 00100eac size=120
// signature: undefined re_trigger_dbg_show(void)
// callers: []
//------------------------------------------------------------

size_t re_trigger_dbg_show(undefined8 param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  
  if (param_2 == (char *)0x0) {
    _printk(&DAT_00101260,"re_trigger_dbg_show");
    sVar2 = 0xffffffffffffffea;
  }
  else {
    iVar1 = sprintf(param_2,"%d\n",(ulong)DAT_001010b4);
    if (iVar1 < 0) {
      _printk(&DAT_0010142e);
    }
    sVar2 = strlen(param_2);
  }
  return sVar2;
}



//------------------------------------------------------------
// re_trigger_dbg_store @ 00100f28 size=144
// signature: undefined re_trigger_dbg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 re_trigger_dbg_store(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    _printk(&DAT_001014b8,"re_trigger_dbg_store");
    param_3 = 0xffffffffffffffea;
  }
  else {
    iVar1 = kstrtouint(param_2,10,&DAT_001010b4);
    if (iVar1 < 0) {
      _printk(&DAT_001011ab);
    }
    _printk(&DAT_00101212,"re_trigger_dbg_store",DAT_001010b4);
  }
  return param_3;
}



//------------------------------------------------------------
// init_module @ 00100fbc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_lpm_dbg_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100fec size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_lpm_dbg_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00103000 size=1
// signature: undefined _printk(void)
// callers: [re_trigger_dbg_show, event_trigger_show, sleep_dbg_store, re_trigger_dbg_store, mmi_lpm_dbg_subsytem_sleep_call, mmi_lpm_dbg_create_attr, sleep_dbg_show, mmi_lpm_dbg_probe, mmi_lpm_dbg_send_uevent, trigger_thresh_dbg_store, mmi_lpm_dbg_check_work, event_trigger_store, trigger_thresh_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00103008 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [re_trigger_dbg_show, event_trigger_show, trigger_thresh_dbg_show, sleep_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00103010 size=1
// signature: size_t strlen(char * __s)
// callers: [re_trigger_dbg_show, event_trigger_show, trigger_thresh_dbg_show, sleep_dbg_show, mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00103018 size=1
// signature: undefined kstrtoll(void)
// callers: [sleep_dbg_store, event_trigger_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00103020 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [mmi_lpm_dbg_remove, mmi_lpm_dbg_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00103028 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [mmi_lpm_dbg_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00103038 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [mmi_lpm_dbg_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103040 size=1
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
// platform_driver_unregister @ 00103048 size=1
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
// of_property_read_variable_u32_array @ 00103050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mmi_lpm_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00103060 size=1
// signature: undefined init_timer_key(void)
// callers: [mmi_lpm_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_lpm_dbg_register_notifier @ 00103068 size=1
// signature: undefined mmi_lpm_dbg_register_notifier(void)
// callers: [mmi_lpm_dbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_lpm_dbg_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_create_file @ 00103070 size=1
// signature: undefined driver_create_file(void)
// callers: [mmi_lpm_dbg_create_attr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103080 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103088 size=1
// signature: undefined mutex_lock(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103090 size=1
// signature: undefined mutex_unlock(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103098 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 001030a0 size=1
// signature: undefined add_uevent_var(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 001030a8 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001030b0 size=1
// signature: undefined kfree(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030b8 size=1
// signature: undefined fortify_panic(void)
// callers: [mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [event_trigger_store, mmi_lpm_dbg_send_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001030c8 size=1
// signature: undefined kstrtouint(void)
// callers: [trigger_thresh_dbg_store, re_trigger_dbg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



