// Decompiled by Ghidra 12.2
// Program: qcom_sysmon.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_sysmon_get_txn_id @ 00100534 size=8
// signature: undefined qcom_sysmon_get_txn_id(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_sysmon_get_txn_id(long param_1)

{
  return *(undefined4 *)(param_1 + 0xf8);
}



//------------------------------------------------------------
// qcom_sysmon_get_reason @ 00100540 size=452
// signature: undefined qcom_sysmon_get_reason(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

int qcom_sysmon_get_reason(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  size_t sVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b4 [4];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  iVar2 = -0x16;
  local_48 = *(long *)(lVar1 + 0x638);
  local_b4[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_100 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) goto LAB_00100664;
  uVar5 = *(undefined8 *)(param_1 + 0x80);
  iVar2 = qmi_txn_init(param_1 + 0x1c0,&local_100,&qmi_ssctl_get_failure_reason_resp_msg_ei,
                       &local_b0);
  if (iVar2 < 0) {
    puVar4 = &DAT_00101e26;
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x1c0,param_1 + 0x308,&local_100,0x22,0,
                             &qmi_ssctl_get_failure_reason_req_msg_ei,local_b4);
    if (iVar2 < 0) {
      _printk(&DAT_00101ea7,uVar5,iVar2);
      qmi_txn_cancel(&local_100);
      goto LAB_00100664;
    }
    iVar2 = qmi_txn_wait(&local_100,0x4e2);
    if (-1 < iVar2) {
      if ((short)local_b0 == 0) {
        sVar3 = param_3;
        if (0x59 < param_3) {
          sVar3 = 0x5a;
        }
        sVar3 = strnlen((char *)((long)&local_a8 + 4),sVar3);
        if ((0x59 < sVar3) && (sVar3 != param_3)) {
          fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if (sVar3 != param_3) {
          param_3 = sVar3 + 1;
        }
        strscpy(param_2,(char *)((long)&local_a8 + 4),param_3);
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + 0xf0),"failed to receive req. response result: %d\n");
      }
      goto LAB_00100664;
    }
    puVar4 = &DAT_00101eda;
  }
  _printk(puVar4,uVar5,iVar2);
LAB_00100664:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_add_sysmon_subdev @ 00100708 size=696
// signature: undefined qcom_add_sysmon_subdev(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long qcom_add_sysmon_subdev(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  
  lVar3 = kmalloc_trace(_rproc_add_subdev,0xdc0,0x318);
  if (lVar3 == 0) {
    return -0xc;
  }
  *(undefined8 *)(lVar3 + 0x80) = param_2;
  *(undefined4 *)(lVar3 + 0x90) = param_3;
  uVar5 = *(undefined8 *)(param_1 + 0x98);
  *(long *)(lVar3 + 0x30) = param_1;
  *(undefined8 *)(lVar3 + 0xf0) = uVar5;
  *(undefined4 *)(lVar3 + 0x108) = 0;
  __init_swait_queue_head(lVar3 + 0x110,"&x->wait",&init_completion___key);
  *(undefined4 *)(lVar3 + 0x128) = 0;
  __init_swait_queue_head(lVar3 + 0x130,"&x->wait",&init_completion___key);
  *(undefined4 *)(lVar3 + 0x148) = 0;
  __init_swait_queue_head(lVar3 + 0x150,"&x->wait",&init_completion___key);
  *(undefined4 *)(lVar3 + 0x168) = 0;
  __init_swait_queue_head(lVar3 + 0x170,"&x->wait",&init_completion___key);
  init_timer_key(lVar3 + 0xa0,sysmon_notif_timeout_handler,0,0,0);
  __mutex_init(lVar3 + 0x188,"&sysmon->lock",&qcom_add_sysmon_subdev___key);
  __mutex_init(lVar3 + 0x40,"&sysmon->state_lock",&qcom_add_sysmon_subdev___key_5);
  if (*(int *)(lVar3 + 0x90) != -0x16) {
    iVar2 = of_irq_get_byname(*(undefined8 *)(*(long *)(lVar3 + 0xf0) + 0x2e8),"shutdown-ack");
    *(int *)(lVar3 + 0x88) = iVar2;
    if (iVar2 < 0) {
      if (iVar2 != -0x3d) {
        _dev_err(*(undefined8 *)(lVar3 + 0xf0),"failed to retrieve shutdown-ack IRQ\n");
        iVar2 = *(int *)(lVar3 + 0x88);
        kfree(lVar3);
        return (long)iVar2;
      }
    }
    else {
      iVar2 = devm_request_threaded_irq
                        (*(undefined8 *)(lVar3 + 0xf0),iVar2,0,sysmon_shutdown_interrupt,0x2001,
                         "q6v5 shutdown-ack",lVar3);
      if (iVar2 != 0) {
        _dev_err(*(undefined8 *)(lVar3 + 0xf0),"failed to acquire shutdown-ack IRQ\n");
        kfree(lVar3);
        return (long)iVar2;
      }
    }
    iVar2 = qmi_handle_init(lVar3 + 0x1c0,7,&ssctl_ops,qmi_indication_handler);
    if (iVar2 < 0) {
      _dev_err(*(undefined8 *)(lVar3 + 0xf0),"failed to initialize qmi handle\n");
      kfree(lVar3);
      return (long)iVar2;
    }
    qmi_add_lookup(lVar3 + 0x1c0,0x2b,0,0);
  }
  *(code **)(lVar3 + 0x10) = sysmon_prepare;
  *(code **)(lVar3 + 0x18) = sysmon_start;
  *(code **)(lVar3 + 0x20) = sysmon_stop;
  *(code **)(lVar3 + 0x28) = sysmon_unprepare;
  rproc_add_subdev(param_1,lVar3);
  *(undefined8 *)(lVar3 + 0xd8) = sysmon_notify;
  blocking_notifier_chain_register(sysmon_notifiers,(undefined8 *)(lVar3 + 0xd8));
  mutex_lock(sysmon_lock);
  puVar1 = sysmon_list;
  puVar6 = (undefined *)(lVar3 + 0x70);
  uVar4 = __list_add_valid(puVar6,&sysmon_list,sysmon_list);
  if ((uVar4 & 1) != 0) {
    *(undefined **)(puVar1 + 8) = puVar6;
    *(undefined **)(lVar3 + 0x70) = puVar1;
    *(undefined ***)(lVar3 + 0x78) = &sysmon_list;
    sysmon_list = puVar6;
  }
  mutex_unlock(sysmon_lock);
  return lVar3;
}



//------------------------------------------------------------
// sysmon_notif_timeout_handler @ 001009c4 size=144
// signature: undefined sysmon_notif_timeout_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sysmon_notif_timeout_handler(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *(uint *)(param_1 + -0x68);
  if (_system_state - 7U < 0xfffffffd && qcom_device_shutdown_in_progress == '\0') {
    if (uVar1 < 4) {
                    /* WARNING: Subroutine does not return */
      panic("sysmon msg from %s to %s for %s taking too long",*(undefined8 *)(param_1 + -0x20),
            *(undefined8 *)(*(long *)(param_1 + -8) + 0x80),(&subdevice_state_string)[uVar1]);
    }
  }
  else if (uVar1 < 4) {
    __warn_printk("sysmon msg from %s to %s for %s taking too long",*(undefined8 *)(param_1 + -0x20)
                  ,*(undefined8 *)(*(long *)(param_1 + -8) + 0x80),(&subdevice_state_string)[uVar1])
    ;
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100a24);
    (*pcVar2)();
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100a60);
  (*pcVar2)();
}



//------------------------------------------------------------
// sysmon_shutdown_interrupt @ 00100a64 size=36
// signature: undefined sysmon_shutdown_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_shutdown_interrupt(undefined8 param_1,long param_2)

{
  complete(param_2 + 0x148);
  return 1;
}



//------------------------------------------------------------
// sysmon_prepare @ 00100a8c size=108
// signature: undefined sysmon_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_prepare(long param_1)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x30) + 0x98);
  lVar1 = plVar2[0xe];
  if (lVar1 == 0) {
    lVar1 = *plVar2;
  }
  mutex_lock(param_1 + 0x40,lVar1);
  *(undefined4 *)(param_1 + 0x38) = 0;
  blocking_notifier_call_chain(sysmon_notifiers,0,param_1);
  mutex_unlock(param_1 + 0x40);
  return 0;
}



//------------------------------------------------------------
// sysmon_start @ 00100b70 size=244
// signature: undefined sysmon_start(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_start(undefined **param_1)

{
  long lVar1;
  undefined **ppuVar2;
  
  lVar1 = (*(long **)(param_1[6] + 0x98))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1[6] + 0x98);
  }
  *(undefined4 *)(param_1 + 0x2d) = 0;
  mutex_lock(param_1 + 8,lVar1);
  *(undefined4 *)(param_1 + 7) = 1;
  blocking_notifier_call_chain(sysmon_notifiers,0,param_1);
  mutex_unlock(param_1 + 8);
  mutex_lock(sysmon_lock);
  for (ppuVar2 = (undefined **)sysmon_list; ppuVar2 != &sysmon_list;
      ppuVar2 = (undefined **)*ppuVar2) {
    mutex_lock(ppuVar2 + -6);
    if ((ppuVar2 + -0xe != param_1) && (*(int *)(ppuVar2 + -7) == 1)) {
      send_event(param_1,ppuVar2 + -0xe);
    }
    mutex_unlock(ppuVar2 + -6);
  }
  mutex_unlock(sysmon_lock);
  return 0;
}



//------------------------------------------------------------
// sysmon_stop @ 00100cdc size=764
// signature: undefined sysmon_stop(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sysmon_stop(long param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  long *plVar7;
  undefined1 uVar8;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  plVar7 = *(long **)(*(long *)(param_1 + 0x30) + 0x98);
  lVar6 = plVar7[0xe];
  if (lVar6 == 0) {
    lVar6 = *plVar7;
  }
  pcVar5 = "crash stop";
  if ((param_2 & 1) == 0) {
    pcVar5 = "stop";
  }
  *(undefined1 *)(param_1 + 0x1b9) = 0;
  mutex_lock(lVar6,param_1 + 0x40,param_2,param_3,pcVar5);
  *(undefined4 *)(param_1 + 0x38) = 2;
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  _dev_info(*(undefined8 *)(param_1 + 0xf0),"Incrementing tid for %s to %d\n",
            *(undefined8 *)(param_1 + 0x80));
  blocking_notifier_call_chain(sysmon_notifiers,0,param_1);
  mutex_unlock(param_1 + 0x40);
  if ((param_2 & 1) != 0) goto LAB_00100efc;
  *(code **)(param_1 + 0xb8) = sysmon_shutdown_notif_timeout_handler;
  lVar6 = _jiffies + 0x9c4;
  if ((*(int *)(param_1 + 0x90) != 0) &&
     (lVar2 = wait_for_completion_timeout(param_1 + 0x168,0x7d), lVar2 == 0)) {
    _dev_err(*(undefined8 *)(param_1 + 0xf0),"timeout waiting for ssctl service\n");
  }
  mod_timer(param_1 + 0xa0,lVar6);
  if (*(int *)(param_1 + 0x8c) == 0) {
    if (*(long *)(param_1 + 0x100) != 0) {
      mutex_lock(param_1 + 0x188);
      *(undefined4 *)(param_1 + 0x108) = 0;
      *(undefined1 *)(param_1 + 0x1b8) = 0;
      iVar1 = rpmsg_send(*(undefined8 *)(param_1 + 0x100),"ssr:shutdown",0xd);
      if (iVar1 < 0) {
        pcVar5 = "send sysmon shutdown request failed\n";
LAB_00100fb4:
        _dev_err(*(undefined8 *)(param_1 + 0xf0),pcVar5);
        uVar8 = 0;
      }
      else {
        iVar1 = wait_for_completion_timeout(param_1 + 0x108,0x4e2);
        if (iVar1 == 0) {
          pcVar5 = "timeout waiting for sysmon ack\n";
          goto LAB_00100fb4;
        }
        if (*(char *)(param_1 + 0x1b8) == '\0') {
          pcVar5 = "unexpected response to sysmon shutdown request\n";
          goto LAB_00100fb4;
        }
        uVar8 = 1;
      }
      mutex_unlock(param_1 + 0x188);
      goto LAB_00100ef0;
    }
  }
  else {
    uVar8 = 0;
    local_40[0] = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_60 = 0;
    uStack_58 = 0;
    local_70 = 0;
    uStack_68 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_88 = 0;
    if (*(int *)(param_1 + 0x90) != -0x16) {
      *(undefined4 *)(param_1 + 0x128) = 0;
      *(undefined4 *)(param_1 + 0x148) = 0;
      iVar1 = qmi_txn_init(param_1 + 0x1c0,&local_88,ssctl_shutdown_resp_ei,local_40);
      if (iVar1 < 0) {
        uVar4 = *(undefined8 *)(param_1 + 0xf0);
        pcVar5 = "failed to allocate QMI txn\n";
LAB_00100f48:
        _dev_err(uVar4,pcVar5);
      }
      else {
        iVar1 = qmi_send_request(param_1 + 0x1c0,param_1 + 0x308,&local_88,0x21,0,0,0);
        if (-1 < iVar1) {
          iVar1 = qmi_txn_wait(&local_88,0x4e2);
          if (iVar1 < 0) {
            pcVar5 = "failed receiving QMI response\n";
LAB_00100f84:
            _dev_err(*(undefined8 *)(param_1 + 0xf0),pcVar5);
            uVar8 = 0;
          }
          else {
            if ((short)local_40[0] != 0) {
              pcVar5 = "shutdown request failed\n";
              goto LAB_00100f84;
            }
            uVar8 = 1;
          }
          if (0 < *(int *)(param_1 + 0x88)) {
            iVar1 = wait_for_completion_timeout(param_1 + 0x148,0x9c4);
            if ((iVar1 == 0) && (uVar3 = try_wait_for_completion(param_1 + 0x128), (uVar3 & 1) == 0)
               ) {
              uVar4 = *(undefined8 *)(param_1 + 0xf0);
              pcVar5 = "timeout waiting for shutdown ack\n";
              goto LAB_00100f48;
            }
            uVar8 = 1;
          }
          goto LAB_00100ef0;
        }
        _dev_err(*(undefined8 *)(param_1 + 0xf0),"failed to send shutdown request\n");
        qmi_txn_cancel(&local_88);
      }
      uVar8 = 0;
    }
LAB_00100ef0:
    *(undefined1 *)(param_1 + 0x1b9) = uVar8;
  }
  del_timer_sync(param_1 + 0xa0);
LAB_00100efc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sysmon_unprepare @ 0010104c size=108
// signature: undefined sysmon_unprepare(void)
// callers: []
//------------------------------------------------------------

void sysmon_unprepare(long param_1)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x30) + 0x98);
  lVar1 = plVar2[0xe];
  if (lVar1 == 0) {
    lVar1 = *plVar2;
  }
  mutex_lock(param_1 + 0x40,lVar1);
  *(undefined4 *)(param_1 + 0x38) = 3;
  blocking_notifier_call_chain(sysmon_notifiers,0,param_1);
  mutex_unlock(param_1 + 0x40);
  return;
}



//------------------------------------------------------------
// sysmon_notify @ 00101130 size=84
// signature: undefined sysmon_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_notify(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + -0xa0) == 1) &&
     (iVar1 = strcmp(*(char **)(param_3 + 0x80),*(char **)(param_1 + -0x58)), iVar1 != 0)) {
    send_event(param_1 + -0xd8,param_3);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_remove_sysmon_subdev @ 00101188 size=164
// signature: undefined qcom_remove_sysmon_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_remove_sysmon_subdev(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  if (param_1 != 0) {
    mutex_lock(sysmon_lock);
    uVar3 = __list_del_entry_valid(param_1 + 0x70);
    if ((uVar3 & 1) != 0) {
      lVar1 = *(long *)(param_1 + 0x70);
      plVar2 = *(long **)(param_1 + 0x78);
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *(undefined8 *)(param_1 + 0x70) = 0xdead000000000100;
    *(undefined8 *)(param_1 + 0x78) = 0xdead000000000122;
    mutex_unlock(sysmon_lock);
    blocking_notifier_chain_unregister(sysmon_notifiers,param_1 + 0xd8);
    rproc_remove_subdev(*(undefined8 *)(param_1 + 0x30),param_1);
    if (*(int *)(param_1 + 0x90) != -0x16) {
      qmi_handle_release(param_1 + 0x1c0);
    }
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// qcom_sysmon_shutdown_acked @ 00101230 size=20
// signature: undefined qcom_sysmon_shutdown_acked(void)
// callers: []
//------------------------------------------------------------

bool qcom_sysmon_shutdown_acked(long param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(char *)(param_1 + 0x1b9) != '\0';
  }
  return bVar1;
}



//------------------------------------------------------------
// ssctl_new_server @ 00101248 size=180
// signature: undefined ssctl_new_server(void)
// callers: []
//------------------------------------------------------------

undefined8 ssctl_new_server(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 2) {
    if (*(int *)(param_2 + 8) == *(int *)(param_1 + -0x130)) goto LAB_001012b4;
  }
  else if (((iVar1 == 1) && (*(int *)(param_2 + 8) == 0)) &&
          (iVar2 = strcmp(*(char **)(param_1 + -0x140),"modem"), iVar2 == 0)) {
LAB_001012b4:
    *(int *)(param_1 + -0x134) = iVar1;
    *(undefined2 *)(param_1 + 0x148) = 0x2a;
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_2 + 0x10);
    *(long *)(param_2 + 0x18) = param_1 + -0x1c0;
    complete(param_1 + -0x58);
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// ssctl_del_server @ 00101300 size=12
// signature: undefined ssctl_del_server(void)
// callers: []
//------------------------------------------------------------

void ssctl_del_server(undefined8 param_1,long param_2)

{
  *(undefined4 *)(*(long *)(param_2 + 0x18) + 0x8c) = 0;
  return;
}



//------------------------------------------------------------
// sysmon_ind_cb @ 00101310 size=32
// signature: undefined sysmon_ind_cb(void)
// callers: []
//------------------------------------------------------------

void sysmon_ind_cb(long param_1)

{
  complete(param_1 + -0x98);
  return;
}



//------------------------------------------------------------
// send_event @ 00101330 size=420
// signature: undefined send_event(void)
// callers: [sysmon_start, sysmon_notify]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void send_event(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined2 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  *(code **)(param_2 + 0xb8) = sysmon_notif_timeout_handler;
  *(long *)(param_2 + 0x98) = param_1;
  mod_timer(param_2 + 0xa0,_jiffies + 5000);
  if (*(int *)(param_1 + 0x8c) == 2) {
    iVar3 = ssctl_send_event(param_1,param_2,0);
    if (iVar3 == 1) {
      iVar3 = ssctl_send_event(param_1,param_2,1);
    }
    if (iVar3 != 0) {
      _printk(&DAT_00101fab);
    }
    goto LAB_0010146c;
  }
  if (*(long *)(param_1 + 0x100) == 0) goto LAB_0010146c;
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if (3 < *(uint *)(param_2 + 0x38)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1014d4);
    (*pcVar2)();
  }
  uVar4 = scnprintf(&local_70,0x32,"ssr:%s:%s",*(undefined8 *)(param_2 + 0x80),
                    (&subdevice_state_string)[*(uint *)(param_2 + 0x38)]);
  if (0x31 < uVar4) goto LAB_0010146c;
  mutex_lock(param_1 + 0x188);
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined1 *)(param_1 + 0x1b8) = 0;
  iVar3 = rpmsg_send(*(undefined8 *)(param_1 + 0x100),&local_70,uVar4);
  if (iVar3 < 0) {
    pcVar5 = "failed to send sysmon event\n";
LAB_001014c0:
    _dev_err(*(undefined8 *)(param_1 + 0xf0),pcVar5);
  }
  else {
    iVar3 = wait_for_completion_timeout(param_1 + 0x108,0x4e2);
    if (iVar3 == 0) {
      pcVar5 = "timeout waiting for sysmon ack\n";
      goto LAB_001014c0;
    }
    if (*(char *)(param_1 + 0x1b8) == '\0') {
      pcVar5 = "unexpected response to sysmon event\n";
      goto LAB_001014c0;
    }
  }
  mutex_unlock(param_1 + 0x188);
LAB_0010146c:
  del_timer_sync(param_2 + 0xa0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ssctl_send_event @ 001014d4 size=580
// signature: undefined ssctl_send_event(void)
// callers: [send_event]
//------------------------------------------------------------

uint ssctl_send_event(long param_1,long param_2,byte param_3)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  size_t sVar5;
  undefined4 uVar6;
  char *__string;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c0 = 0;
  if (*(int *)(param_1 + 0x90) == -0x16) {
    uVar3 = 0xffffffea;
LAB_00101634:
    lVar1 = sp_el0;
    if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar3;
  }
  local_78 = 0;
  uVar3 = qmi_txn_init(param_1 + 0x1c0,&local_c0,ssctl_subsys_event_with_tid_resp_ei,&local_78);
  if ((int)uVar3 < 0) {
    _dev_err(*(undefined8 *)(param_1 + 0xf0),"failed to allocate QMI txn\n");
    goto LAB_00101634;
  }
  __string = *(char **)(param_2 + 0x80);
  local_50 = 0;
  local_60 = 0;
  local_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  uVar4 = strnlen(__string,0xf);
  if (uVar4 == 0xffffffffffffffff) {
LAB_001016f0:
    fortify_panic("strnlen");
LAB_001016fc:
    fortify_panic("strscpy");
  }
  else {
    if (uVar4 != 0xf) {
      uVar4 = uVar4 + 1;
    }
    if (0xf < uVar4) goto LAB_001016fc;
    strscpy((char *)((ulong)&local_70 | 1),__string);
    sVar5 = strnlen((char *)((ulong)&local_70 | 1),0xf);
    if (0xf < sVar5) goto LAB_001016f0;
    if (sVar5 != 0xf) {
      local_70 = CONCAT71(local_70._1_7_,(char)sVar5);
      local_60 = CONCAT35(local_60._5_3_,0x100000000);
      local_60 = CONCAT44(local_60._4_4_,*(undefined4 *)(param_2 + 0x38));
      local_50 = *(undefined4 *)(param_1 + 0xf8);
      uVar6 = 0x23;
      if ((param_3 & 1) == 0) {
        uVar6 = 0x25;
      }
      local_58 = (ulong)((CONCAT31(local_58._5_3_,param_3) ^ 0xff) & 0xffffff01) << 0x20;
      uVar3 = qmi_send_request(param_1 + 0x1c0,param_1 + 0x308,&local_c0,uVar6,0x28,
                               ssctl_subsys_event_with_tid_req_ei,&local_70);
      if ((int)uVar3 < 0) {
        _dev_err(*(undefined8 *)(param_1 + 0xf0),"failed to send shutdown request\n");
        qmi_txn_cancel(&local_c0);
        goto LAB_00101634;
      }
      uVar3 = qmi_txn_wait(&local_c0,0x4e2);
      if ((int)uVar3 < 0) {
        _dev_err(*(undefined8 *)(param_1 + 0xf0),"failed receiving QMI response\n");
        goto LAB_00101634;
      }
      if ((short)local_78 == 0) {
        uVar3 = 0;
        goto LAB_00101634;
      }
      if (*(uint *)(param_2 + 0x38) < 4) {
        _dev_err(*(undefined8 *)(param_1 + 0xf0),
                 "failed to receive %s ssr %s event. response result: %d error: %d\n",
                 *(undefined8 *)(param_2 + 0x80),
                 (&subdevice_state_string)[*(uint *)(param_2 + 0x38)],(short)local_78,local_78._2_2_
                );
        uVar3 = local_78 & 0xffff;
        goto LAB_00101634;
      }
      goto LAB_00101714;
    }
  }
  fortify_panic("__fortify_strlen");
LAB_00101714:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101718);
  (*pcVar2)();
}



//------------------------------------------------------------
// sysmon_shutdown_notif_timeout_handler @ 0010171c size=32
// signature: undefined sysmon_shutdown_notif_timeout_handler(void)
// callers: []
//------------------------------------------------------------

void sysmon_shutdown_notif_timeout_handler(long param_1)

{
  code *pcVar1;
  
  __warn_printk("sysmon_send_shutdown to %s taking too long",*(undefined8 *)(param_1 + -0x20));
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10173c);
  (*pcVar1)();
}



//------------------------------------------------------------
// sysmon_probe @ 0010174c size=188
// signature: undefined sysmon_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_probe(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined **ppuVar4;
  
  puVar1 = (undefined *)rproc_get_by_child();
  if (puVar1 == (undefined *)0x0) {
    pcVar3 = "sysmon device not child of rproc\n";
LAB_001017f8:
    _dev_err(param_1,pcVar3);
    uVar2 = 0xffffffea;
  }
  else {
    mutex_lock(sysmon_lock);
    ppuVar4 = &sysmon_list;
    do {
      ppuVar4 = (undefined **)*ppuVar4;
      if (ppuVar4 == &sysmon_list) {
        mutex_unlock(sysmon_lock);
        pcVar3 = "no sysmon associated with parent rproc\n";
        goto LAB_001017f8;
      }
    } while (ppuVar4[-8] != puVar1);
    mutex_unlock(sysmon_lock);
    uVar2 = 0;
    *(undefined ***)(*(long *)(param_1 + 0x3c8) + 0x50) = ppuVar4 + -0xe;
    ppuVar4[0x12] = *(undefined **)(param_1 + 0x3c8);
  }
  return uVar2;
}



//------------------------------------------------------------
// sysmon_remove @ 0010180c size=16
// signature: undefined sysmon_remove(void)
// callers: []
//------------------------------------------------------------

void sysmon_remove(long param_1)

{
  *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x3c8) + 0x50) + 0x100) = 0;
  return;
}



//------------------------------------------------------------
// sysmon_callback @ 00101820 size=92
// signature: undefined sysmon_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_callback(undefined8 param_1,long *param_2,int param_3,long param_4)

{
  if (param_4 == 0) {
    return 0xffffffea;
  }
  if ((7 < param_3) && (*param_2 == 0x6b63613a727373)) {
    *(undefined1 *)(param_4 + 0x1b8) = 1;
  }
  complete(param_4 + 0x108);
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010192c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __register_rpmsg_driver(&sysmon_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010195c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_rpmsg_driver(&sysmon_driver);
  return;
}



//------------------------------------------------------------
// qmi_txn_init @ 00104000 size=1
// signature: undefined qmi_txn_init(void)
// callers: [ssctl_send_event, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 00104008 size=1
// signature: undefined qmi_send_request(void)
// callers: [ssctl_send_event, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 00104010 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [ssctl_send_event, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104018 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [ssctl_send_event, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104020 size=1
// signature: undefined strscpy(void)
// callers: [ssctl_send_event, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104028 size=1
// signature: undefined _printk(void)
// callers: [send_event, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 00104030 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [ssctl_send_event, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104038 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_add_sysmon_subdev, send_event, ssctl_send_event, sysmon_probe, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [send_event, ssctl_send_event, sysmon_stop, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104048 size=1
// signature: undefined fortify_panic(void)
// callers: [ssctl_send_event, qcom_sysmon_get_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104058 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104060 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00104068 size=1
// signature: undefined init_timer_key(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104070 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 00104078 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00104080 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104088 size=1
// signature: undefined kfree(void)
// callers: [qcom_add_sysmon_subdev, qcom_remove_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 00104090 size=1
// signature: undefined qmi_handle_init(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 00104098 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_add_subdev @ 001040a0 size=1
// signature: undefined rproc_add_subdev(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_add_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 001040a8 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040b0 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_add_sysmon_subdev, send_event, sysmon_probe, sysmon_unprepare, sysmon_prepare, sysmon_start, qcom_remove_sysmon_subdev, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001040b8 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_add_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001040c0 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_add_sysmon_subdev, send_event, sysmon_probe, sysmon_unprepare, sysmon_prepare, sysmon_start, qcom_remove_sysmon_subdev, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001040d8 size=1
// signature: undefined __warn_printk(void)
// callers: [sysmon_shutdown_notif_timeout_handler, sysmon_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001040e0 size=1
// signature: noreturn undefined panic(void)
// callers: [sysmon_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001040e8 size=1
// signature: undefined complete(void)
// callers: [ssctl_new_server, sysmon_shutdown_interrupt, sysmon_ind_cb, sysmon_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 001040f8 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [sysmon_unprepare, sysmon_prepare, sysmon_start, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00104120 size=1
// signature: undefined _dev_info(void)
// callers: [sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00104130 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [send_event, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00104138 size=1
// signature: undefined mod_timer(void)
// callers: [send_event, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_wait_for_completion @ 00104140 size=1
// signature: undefined try_wait_for_completion(void)
// callers: [sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 00104148 size=1
// signature: undefined rpmsg_send(void)
// callers: [send_event, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 00104150 size=1
// signature: undefined del_timer_sync(void)
// callers: [send_event, sysmon_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104158 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [ssctl_new_server, sysmon_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104160 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_remove_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00104168 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [qcom_remove_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_remove_subdev @ 00104170 size=1
// signature: undefined rproc_remove_subdev(void)
// callers: [qcom_remove_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_remove_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 00104178 size=1
// signature: undefined qmi_handle_release(void)
// callers: [qcom_remove_sysmon_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 00104180 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 00104188 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00104190 size=1
// signature: undefined scnprintf(void)
// callers: [send_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_child @ 00104198 size=1
// signature: undefined rproc_get_by_child(void)
// callers: [sysmon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



