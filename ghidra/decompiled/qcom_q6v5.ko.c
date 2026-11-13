// Decompiled by Ghidra 12.2
// Program: qcom_q6v5.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_q6v5_prepare @ 00100404 size=60
// signature: undefined qcom_q6v5_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_q6v5_prepare(long param_1)

{
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined1 *)(param_1 + 0x11c) = 1;
  *(undefined1 *)(param_1 + 0x90) = 0;
  enable_irq(*(undefined4 *)(param_1 + 0x48));
  return 0;
}



//------------------------------------------------------------
// qcom_q6v5_unprepare @ 00100444 size=56
// signature: undefined qcom_q6v5_unprepare(void)
// callers: []
//------------------------------------------------------------

bool qcom_q6v5_unprepare(long param_1)

{
  disable_irq(*(undefined4 *)(param_1 + 0x48));
  return *(char *)(param_1 + 0x90) == '\0';
}



//------------------------------------------------------------
// qcom_q6v5_register_ssr_subdev @ 00100480 size=8
// signature: undefined qcom_q6v5_register_ssr_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_q6v5_register_ssr_subdev(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x58) = param_2;
  return;
}



//------------------------------------------------------------
// qcom_q6v5_wait_for_start @ 0010048c size=48
// signature: undefined qcom_q6v5_wait_for_start(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_q6v5_wait_for_start(long param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = wait_for_completion_timeout(param_1 + 0x98,(long)param_2);
  uVar2 = 0xffffff92;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_q6v5_request_stop @ 001004c0 size=160
// signature: undefined qcom_q6v5_request_stop(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_q6v5_request_stop(long param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  *(undefined1 *)(param_1 + 0x11c) = 0;
  uVar3 = 0;
  if (*(int *)(*(long *)(param_1 + 8) + 0x3cc) == 2) {
    uVar2 = qcom_sysmon_shutdown_acked(param_2);
    if ((uVar2 & 1) == 0) {
      uVar2 = 1L << ((ulong)*(uint *)(param_1 + 0x28) & 0x3f);
      qcom_smem_state_update_bits(*(undefined8 *)(param_1 + 0x18),uVar2,uVar2 & 0xffffffff);
      iVar1 = wait_for_completion_timeout(param_1 + 0xb8,0x4e2);
      qcom_smem_state_update_bits
                (*(undefined8 *)(param_1 + 0x18),1L << ((ulong)*(uint *)(param_1 + 0x28) & 0x3f),0);
      uVar3 = 0xffffff92;
      if (iVar1 != 0) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_q6v5_panic @ 00100564 size=52
// signature: undefined qcom_q6v5_panic(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_q6v5_panic(long param_1)

{
  ulong uVar1;
  
  uVar1 = 1L << ((ulong)*(uint *)(param_1 + 0x28) & 0x3f);
  qcom_smem_state_update_bits(*(undefined8 *)(param_1 + 0x18),uVar1,uVar1 & 0xffffffff);
  return 200;
}



//------------------------------------------------------------
// ping_subsystem @ 0010059c size=204
// signature: undefined ping_subsystem(void)
// callers: []
//------------------------------------------------------------

int ping_subsystem(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x1f) = 0;
  iVar1 = qcom_smem_state_update_bits
                    (param_1[6],0xffffffff,1L << ((ulong)*(uint *)(param_1 + 7) & 0x3f));
  if (iVar1 == 0) {
    iVar1 = wait_for_completion_timeout(param_1 + 0x1f,0x7d);
    if (iVar1 == 0) {
      _dev_err(*param_1,"Failed to get back pong\n");
      iVar1 = -0x6e;
    }
    else {
      iVar1 = 0;
    }
    iVar2 = qcom_smem_state_update_bits(param_1[6],1L << ((ulong)*(uint *)(param_1 + 7) & 0x3f),0);
    if (iVar2 != 0) {
      _printk(&DAT_00101423);
      iVar1 = iVar2;
    }
  }
  else {
    _dev_err(*param_1,"Failed to update ping bits\n");
  }
  return iVar1;
}



//------------------------------------------------------------
// ping_subsystem_init @ 0010066c size=264
// signature: undefined ping_subsystem_init(void)
// callers: []
//------------------------------------------------------------

int ping_subsystem_init(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    puVar3 = &DAT_001016e3;
  }
  else {
    uVar2 = devm_qcom_smem_state_get(param_2 + 0x10,&DAT_0010148b,param_1 + 0x38);
    *(ulong *)(param_1 + 0x30) = uVar2;
    if (0xfffffffffffff000 < uVar2) {
      _printk(&DAT_00101391,uVar2);
      return -0x13;
    }
    iVar1 = platform_get_irq_byname(param_2,&DAT_001013ff);
    *(int *)(param_1 + 0x50) = iVar1;
    if (-1 < iVar1) {
      iVar1 = devm_request_threaded_irq
                        (param_2 + 0x10,iVar1,0,q6v5_pong_interrupt,0x2001,"q6v5 pong",param_1);
      if (iVar1 != 0) {
        _printk(&DAT_001013e1);
      }
      *(undefined4 *)(param_1 + 0xf8) = 0;
      __init_swait_queue_head(param_1 + 0x100,"&x->wait",&init_completion___key);
      return iVar1;
    }
    puVar3 = &DAT_00101633;
  }
  _printk(puVar3);
  return -0x13;
}



//------------------------------------------------------------
// q6v5_pong_interrupt @ 00100778 size=60
// signature: undefined q6v5_pong_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 q6v5_pong_interrupt(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    _printk(&DAT_0010157a);
    uVar1 = 0xffffffed;
  }
  else {
    complete(param_2 + 0xf8);
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_q6v5_init @ 001007b8 size=740
// signature: undefined qcom_q6v5_init(void)
// callers: []
//------------------------------------------------------------

int qcom_q6v5_init(long *param_1,long param_2,long param_3,undefined4 param_4,undefined1 param_5,
                  long param_6)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  
  lVar1 = param_2 + 0x10;
  *(undefined4 *)(param_1 + 0x23) = param_4;
  *param_1 = lVar1;
  param_1[1] = param_3;
  param_1[0x24] = param_6;
  *(undefined1 *)(param_1 + 0x27) = param_5;
  param_1[0xb] = 0;
  *(undefined4 *)(param_1 + 0x13) = 0;
  __init_swait_queue_head(param_1 + 0x14,"&x->wait",&init_completion___key);
  *(undefined4 *)(param_1 + 0x17) = 0;
  __init_swait_queue_head(param_1 + 0x18,"&x->wait",&init_completion___key);
  lVar3 = platform_get_resource(param_2,0x200,1);
  if (lVar3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar4 = devm_ioremap_resource(lVar1,lVar3);
    uVar5 = 0;
    if (uVar4 < 0xfffffffffffff001) {
      uVar5 = uVar4;
    }
  }
  param_1[2] = uVar5;
  iVar2 = platform_get_irq_byname(param_2,&DAT_00101575);
  *(int *)((long)param_1 + 0x3c) = iVar2;
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = devm_request_threaded_irq(lVar1,iVar2,0,q6v5_wdog_interrupt,0x2000,"q6v5 wdog",param_1);
  if (iVar2 == 0) {
    iVar2 = platform_get_irq_byname(param_2,"fatal");
    *(int *)(param_1 + 8) = iVar2;
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = devm_request_threaded_irq
                      (lVar1,iVar2,0,q6v5_fatal_interrupt,0x2001,"q6v5 fatal",param_1);
    if (iVar2 == 0) {
      iVar2 = platform_get_irq_byname(param_2,"ready");
      *(int *)((long)param_1 + 0x44) = iVar2;
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = devm_request_threaded_irq
                        (lVar1,iVar2,0,q6v5_ready_interrupt,0x2001,"q6v5 ready",param_1);
      if (iVar2 == 0) {
        iVar2 = platform_get_irq_byname(param_2,"handover");
        *(int *)(param_1 + 9) = iVar2;
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = devm_request_threaded_irq
                          (lVar1,iVar2,0,q6v5_handover_interrupt,0x2001,"q6v5 handover",param_1);
        if (iVar2 == 0) {
          disable_irq((int)param_1[9]);
          iVar2 = platform_get_irq_byname(param_2,"stop-ack");
          *(int *)((long)param_1 + 0x4c) = iVar2;
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar2 = devm_request_threaded_irq
                            (lVar1,iVar2,0,q6v5_stop_interrupt,0x2001,"q6v5 stop",param_1);
          if (iVar2 == 0) {
            uVar5 = qcom_smem_state_get(lVar1,&DAT_001016d4,param_1 + 5);
            param_1[3] = uVar5;
            if (uVar5 < 0xfffffffffffff001) {
              param_1[0xc] = 0xfffffffe0;
              param_1[0xd] = (long)(param_1 + 0xd);
              param_1[0xe] = (long)(param_1 + 0xd);
              param_1[0xf] = (long)qcom_q6v5_crash_handler_work;
              return 0;
            }
            _dev_err(lVar1,"failed to acquire stop state\n");
            return (int)param_1[3];
          }
          pcVar6 = "failed to acquire stop-ack IRQ\n";
        }
        else {
          pcVar6 = "failed to acquire handover IRQ\n";
        }
      }
      else {
        pcVar6 = "failed to acquire ready IRQ\n";
      }
    }
    else {
      pcVar6 = "failed to acquire fatal IRQ\n";
    }
  }
  else {
    pcVar6 = "failed to acquire wdog IRQ\n";
  }
  _dev_err(lVar1,pcVar6);
  return iVar2;
}



//------------------------------------------------------------
// q6v5_wdog_interrupt @ 00100aa0 size=652
// signature: undefined q6v5_wdog_interrupt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 q6v5_wdog_interrupt(undefined8 param_1,undefined8 *param_2)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  char *__s;
  ulong __n;
  undefined8 extraout_x1;
  ulong local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  if (*(char *)(param_2 + 0x27) != '\0') {
    uVar4 = completion_done(param_2 + 0x1b);
    if ((uVar4 & 1) == 0) {
      complete(param_2 + 0x1b);
    }
  }
  if (*(char *)((long)param_2 + 0x11c) == '\0') {
    _dev_info(*param_2,"received wdog irq while q6 is offline\n");
    complete(param_2 + 0x17);
  }
  else {
    param_2[0x26] = param_2[0x25];
    __s = (char *)qcom_smem_get(0xffffffff,*(undefined4 *)(param_2 + 0x23),&local_50);
    if (((__s < (char *)0xfffffffffffff001) && (local_50 != 0)) && (*__s != '\0')) {
      _dev_err(*param_2,"watchdog received: %s\n",__s);
    }
    else {
      _dev_err(*param_2,"watchdog without message\n");
    }
    while( true ) {
      *(undefined1 *)((long)param_2 + 0x11c) = 0;
      pcVar1 = "enabled and kick reovery process";
      if (*(char *)(param_2[1] + 0x4c4) != '\0') {
        pcVar1 = "disabled and lead to device crash";
      }
      _dev_err(*param_2,"rproc recovery state: %s\n",pcVar1);
      DAT_001017ee = 0;
      DAT_001017f6 = 0;
      uVar4 = local_50;
      if (0xff < local_50) {
        uVar4 = 0x100;
      }
      DAT_001017de = 0;
      DAT_001017e6 = 0;
      DAT_001017ce = 0;
      DAT_001017d6 = 0;
      DAT_001017be = 0;
      DAT_001017c6 = 0;
      DAT_001017ae = 0;
      DAT_001017b6 = 0;
      DAT_0010179e = 0;
      DAT_001017a6 = 0;
      DAT_0010178e = 0;
      DAT_00101796 = 0;
      DAT_0010177e = 0;
      DAT_00101786 = 0;
      DAT_0010176e = 0;
      DAT_00101776 = 0;
      DAT_0010175e = 0;
      DAT_00101766 = 0;
      DAT_0010174e = 0;
      DAT_00101756 = 0;
      DAT_0010173e = 0;
      DAT_00101746 = 0;
      DAT_0010172e = 0;
      DAT_00101736 = 0;
      DAT_0010171e = 0;
      DAT_00101726 = 0;
      DAT_0010170e = 0;
      DAT_00101716 = 0;
      qcom_ssr_reason = 0;
      DAT_00101706 = 0;
      __n = strlen(__s);
      if (uVar4 <= __n) {
        __n = uVar4 - 1;
      }
      if (uVar4 == 0) goto LAB_00100c40;
      if (__n < 0x100) break;
      fortify_panic("strlcpy");
      lVar2 = tpidr_el1;
      if ((*(ulong *)(&__cpu_online_mask +
                     ((ulong)(*(uint *)(&cpu_number + lVar2) >> 3) & 0x1ffffff8)) >>
           ((ulong)*(uint *)(&cpu_number + lVar2) & 0x3f) & 1) != 0) {
        lVar3 = sp_el0;
        *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
        __traceiter_rproc_qcom_event(0,extraout_x1,"q6v5_wdog",__s);
        lVar2 = *(long *)(lVar3 + 0x10) + -1;
        *(int *)(lVar3 + 0x10) = (int)lVar2;
        if ((lVar2 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
          preempt_schedule_notrace();
        }
      }
    }
    memcpy(&qcom_ssr_reason,__s,__n);
    *(undefined1 *)((long)&qcom_ssr_reason + __n) = 0;
LAB_00100c40:
    if (param_2[0xb] != 0) {
      qcom_notify_early_ssr_clients();
    }
    if (*(char *)(param_2[1] + 0x4c4) == '\0') {
      rproc_report_crash(param_2[1],1);
    }
    else {
      queue_work_on(0x20,_system_wq,param_2 + 0xc);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// q6v5_fatal_interrupt @ 00100d30 size=532
// signature: undefined q6v5_fatal_interrupt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 q6v5_fatal_interrupt(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  ulong uVar2;
  char *pcVar3;
  ulong __n;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if (*(char *)(param_2 + 0x27) != '\0') {
    uVar2 = completion_done(param_2 + 0x1b);
    if ((uVar2 & 1) == 0) {
      complete(param_2 + 0x1b);
    }
  }
  if (*(char *)((long)param_2 + 0x11c) == '\0') {
    _dev_info(*param_2,"received fatal irq while q6 is offline\n");
  }
  else {
    param_2[0x26] = param_2[0x25];
    pcVar3 = (char *)qcom_smem_get(0xffffffff,*(undefined4 *)(param_2 + 0x23),&local_50);
    if (((pcVar3 < (char *)0xfffffffffffff001) && (local_50 != 0)) && (*pcVar3 != '\0')) {
      _dev_err(*param_2,"fatal error received: %s\n",pcVar3);
    }
    else {
      _dev_err(*param_2,"fatal error without message\n");
    }
    DAT_001017ee = 0;
    DAT_001017f6 = 0;
    uVar2 = local_50;
    if (0xff < local_50) {
      uVar2 = 0x100;
    }
    DAT_001017de = 0;
    DAT_001017e6 = 0;
    DAT_001017ce = 0;
    DAT_001017d6 = 0;
    DAT_001017be = 0;
    DAT_001017c6 = 0;
    DAT_001017ae = 0;
    DAT_001017b6 = 0;
    DAT_0010179e = 0;
    DAT_001017a6 = 0;
    DAT_0010178e = 0;
    DAT_00101796 = 0;
    DAT_0010177e = 0;
    DAT_00101786 = 0;
    DAT_0010176e = 0;
    DAT_00101776 = 0;
    DAT_0010175e = 0;
    DAT_00101766 = 0;
    DAT_0010174e = 0;
    DAT_00101756 = 0;
    DAT_0010173e = 0;
    DAT_00101746 = 0;
    DAT_0010172e = 0;
    DAT_00101736 = 0;
    DAT_0010171e = 0;
    DAT_00101726 = 0;
    DAT_0010170e = 0;
    DAT_00101716 = 0;
    qcom_ssr_reason = 0;
    DAT_00101706 = 0;
    __n = strlen(pcVar3);
    if (uVar2 <= __n) {
      __n = uVar2 - 1;
    }
    if (uVar2 != 0) {
      if (0xff < __n) {
        fortify_panic("strlcpy");
        goto LAB_00100f40;
      }
      memcpy(&qcom_ssr_reason,pcVar3,__n);
      *(undefined1 *)((long)&qcom_ssr_reason + __n) = 0;
    }
    *(undefined1 *)((long)param_2 + 0x11c) = 0;
    pcVar3 = "enabled and kick reovery process";
    if (*(char *)(param_2[1] + 0x4c4) != '\0') {
      pcVar3 = "disabled and lead to device crash";
    }
    _dev_err(*param_2,"rproc recovery state: %s\n",pcVar3);
    if (param_2[0xb] != 0) {
      qcom_notify_early_ssr_clients();
    }
    if (*(char *)(param_2[1] + 0x4c4) == '\0') {
      rproc_report_crash(param_2[1],2);
    }
    else {
      queue_work_on(0x20,_system_wq,param_2 + 0xc);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) == local_48) {
    return 1;
  }
LAB_00100f40:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// q6v5_ready_interrupt @ 00100fb8 size=80
// signature: undefined q6v5_ready_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 q6v5_ready_interrupt(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  complete(param_2 + 0x98);
  if (*(char *)(param_2 + 0x138) != '\0') {
    uVar1 = completion_done(param_2 + 0xd8);
    if ((uVar1 & 1) == 0) {
      complete(param_2 + 0xd8);
    }
  }
  return 1;
}



//------------------------------------------------------------
// q6v5_handover_interrupt @ 0010100c size=136
// signature: undefined q6v5_handover_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 q6v5_handover_interrupt(undefined8 param_1,long param_2)

{
  ulong uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x120);
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != -0x3425350e) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101044);
      (*pcVar2)();
    }
    (*pcVar2)(param_2);
  }
  if (*(char *)(param_2 + 0x138) != '\0') {
    uVar1 = completion_done(param_2 + 0xd8);
    if ((uVar1 & 1) == 0) {
      complete(param_2 + 0xd8);
    }
  }
  icc_set_bw(*(undefined8 *)(param_2 + 0x20),0,0);
  *(undefined1 *)(param_2 + 0x90) = 1;
  return 1;
}



//------------------------------------------------------------
// q6v5_stop_interrupt @ 00101098 size=36
// signature: undefined q6v5_stop_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 q6v5_stop_interrupt(undefined8 param_1,long param_2)

{
  complete(param_2 + 0xb8);
  return 1;
}



//------------------------------------------------------------
// qcom_q6v5_crash_handler_work @ 001010c0 size=212
// signature: undefined qcom_q6v5_crash_handler_work(void)
// callers: []
//------------------------------------------------------------

void qcom_q6v5_crash_handler_work(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + -0x58);
  lVar1 = lVar3 + 0x3d8;
  mutex_lock(lVar1);
  if ((*(int *)(lVar3 + 0x3c8) == 0) || (*(long *)(param_1 + 0xd0) != *(long *)(param_1 + 200))) {
    mutex_unlock(lVar1);
    return;
  }
  lVar4 = *(long *)(lVar3 + 0x468);
  *(undefined4 *)(lVar3 + 0x3cc) = 3;
  do {
    if (lVar4 == lVar3 + 0x460) {
      mutex_unlock(lVar1);
      msleep(100);
                    /* WARNING: Subroutine does not return */
      panic("Panicking, remoteproc %s crashed\n",*(undefined8 *)(*(long *)(param_1 + -0x58) + 0x18))
      ;
    }
    pcVar2 = *(code **)(lVar4 + 0x20);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x1b89b29f) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10118c);
        (*pcVar2)();
      }
      (*pcVar2)(lVar4,1);
    }
    lVar4 = *(long *)(lVar4 + 8);
  } while( true );
}



//------------------------------------------------------------
// enable_irq @ 00103000 size=1
// signature: undefined enable_irq(void)
// callers: [qcom_q6v5_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00103008 size=1
// signature: undefined disable_irq(void)
// callers: [qcom_q6v5_unprepare, qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00103010 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [ping_subsystem, qcom_q6v5_wait_for_start, qcom_q6v5_request_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_sysmon_shutdown_acked @ 00103018 size=1
// signature: undefined qcom_sysmon_shutdown_acked(void)
// callers: [qcom_q6v5_request_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_sysmon_shutdown_acked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_update_bits @ 00103020 size=1
// signature: undefined qcom_smem_state_update_bits(void)
// callers: [ping_subsystem, qcom_q6v5_panic, qcom_q6v5_request_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103028 size=1
// signature: undefined _dev_err(void)
// callers: [ping_subsystem, q6v5_fatal_interrupt, qcom_q6v5_init, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103030 size=1
// signature: undefined _printk(void)
// callers: [ping_subsystem_init, q6v5_pong_interrupt, ping_subsystem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_qcom_smem_state_get @ 00103038 size=1
// signature: undefined devm_qcom_smem_state_get(void)
// callers: [ping_subsystem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00103040 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [ping_subsystem_init, qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00103048 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [ping_subsystem_init, qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103050 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [ping_subsystem_init, qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00103058 size=1
// signature: undefined complete(void)
// callers: [q6v5_stop_interrupt, q6v5_handover_interrupt, q6v5_pong_interrupt, q6v5_fatal_interrupt, q6v5_ready_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00103060 size=1
// signature: undefined platform_get_resource(void)
// callers: [qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00103068 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_get @ 00103070 size=1
// signature: undefined qcom_smem_state_get(void)
// callers: [qcom_q6v5_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 00103078 size=1
// signature: undefined completion_done(void)
// callers: [q6v5_handover_interrupt, q6v5_fatal_interrupt, q6v5_ready_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103080 size=1
// signature: undefined _dev_info(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00103088 size=1
// signature: undefined qcom_smem_get(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00103098 size=1
// signature: size_t strlen(char * __s)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001030a0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_notify_early_ssr_clients @ 001030a8 size=1
// signature: undefined qcom_notify_early_ssr_clients(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_notify_early_ssr_clients(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030b8 size=1
// signature: undefined queue_work_on(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_report_crash @ 001030c0 size=1
// signature: undefined rproc_report_crash(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_report_crash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030c8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030d0 size=1
// signature: undefined fortify_panic(void)
// callers: [q6v5_fatal_interrupt, q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __traceiter_rproc_qcom_event @ 001030e8 size=1
// signature: undefined __traceiter_rproc_qcom_event(void)
// callers: [q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __traceiter_rproc_qcom_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 001030f0 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [q6v5_wdog_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 001030f8 size=1
// signature: undefined icc_set_bw(void)
// callers: [q6v5_handover_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103100 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_q6v5_crash_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103108 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_q6v5_crash_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00103110 size=1
// signature: undefined msleep(void)
// callers: [qcom_q6v5_crash_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00103118 size=1
// signature: noreturn undefined panic(void)
// callers: [qcom_q6v5_crash_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



