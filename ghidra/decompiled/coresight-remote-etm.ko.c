// Decompiled by Ghidra 12.2
// Program: coresight-remote-etm.ko
// Image base: 00100000

//------------------------------------------------------------
// remote_etm_reenable @ 0010028c size=88
// signature: undefined remote_etm_reenable(void)
// callers: []
//------------------------------------------------------------

undefined8 remote_etm_reenable(int param_1)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &remote_etm_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &remote_etm_list) goto LAB_001002d4;
  } while (*(int *)(ppuVar2 + -4) != param_1);
  if (ppuVar2 == (undefined **)0x1a8) {
LAB_001002d4:
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = remote_etm_enable(ppuVar2[-0x34]);
  }
  return uVar1;
}



//------------------------------------------------------------
// remote_etm_enable @ 001002e8 size=424
// signature: undefined remote_etm_enable(void)
// callers: [remote_etm_reenable]
//------------------------------------------------------------

int remote_etm_enable(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40[0] = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar6 = *(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  puVar1 = puVar6 + 2;
  local_90 = 0;
  mutex_lock(puVar1);
  if (*(char *)((long)puVar6 + 0x194) == '\0') {
    _dev_err(*puVar6,"QMI service not connected!\n");
    iVar3 = -0x16;
  }
  else {
    local_40[0] = 1;
    iVar3 = qmi_txn_init(puVar6 + 8,&local_90,coresight_set_etm_resp_msg_v01_ei,&local_48);
    if (iVar3 < 0) {
      uVar4 = *puVar6;
      pcVar5 = "QMI tx init failed , ret:%d\n";
    }
    else {
      iVar3 = qmi_send_request(puVar6 + 8,puVar6 + 0x33,&local_90,0x2c,7,
                               coresight_set_etm_req_msg_v01_ei,local_40);
      if (iVar3 < 0) {
        _dev_err(*puVar6,"QMI send ACK failed, ret:%d\n",iVar3);
        qmi_txn_cancel(&local_90);
        goto LAB_0010040c;
      }
      iVar3 = qmi_txn_wait(&local_90,0x9c4);
      if (-1 < iVar3) {
        if ((short)local_48 != 0) {
          _dev_err(*puVar6,"QMI request failed 0x%x\n",local_48._2_2_);
        }
        *(undefined1 *)((long)puVar6 + 0x18c) = 1;
        mutex_unlock(puVar1);
        _dev_info(*puVar6,"Remote ETM tracing enabled for instance %d\n",
                  *(undefined4 *)(puVar6 + 0x31));
        iVar3 = 0;
        goto LAB_00100414;
      }
      uVar4 = *puVar6;
      pcVar5 = "QMI qmi txn wait failed, ret:%d\n";
    }
    _dev_err(uVar4,pcVar5,iVar3);
  }
LAB_0010040c:
  mutex_unlock(puVar1);
LAB_00100414:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// remote_etm_etr_assign @ 00100494 size=484
// signature: undefined remote_etm_etr_assign(void)
// callers: []
//------------------------------------------------------------

int remote_etm_etr_assign
              (int param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5)

{
  undefined **ppuVar1;
  long lVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  undefined **ppuVar6;
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
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  ppuVar6 = &remote_etm_list;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c0 = 0;
  do {
    ppuVar6 = (undefined **)*ppuVar6;
    if (ppuVar6 == &remote_etm_list) goto LAB_0010051c;
  } while (*(int *)(ppuVar6 + -4) != param_1);
  ppuVar1 = ppuVar6 + -0x35;
  if (ppuVar1 == (undefined **)0x0) {
LAB_0010051c:
    iVar3 = -0x16;
    goto LAB_00100520;
  }
  mutex_lock(ppuVar6 + -0x33);
  if (*(char *)((long)ppuVar6 + -0x14) == '\0') {
    _dev_err(*ppuVar1,"QMI service not connected!\n");
    iVar3 = -0x16;
  }
  else {
    local_70 = CONCAT44(param_2,param_3);
    local_68 = param_4;
    uStack_60 = param_5;
    iVar3 = qmi_txn_init(ppuVar6 + -0x2d,&local_c0,&coresight_etr_assign_resp_msg_v01_ei,&local_78);
    if (iVar3 < 0) {
      puVar4 = *ppuVar1;
      pcVar5 = "QMI tx init failed , ret:%d\n";
LAB_001005bc:
      _dev_err(puVar4,pcVar5,iVar3);
    }
    else {
      iVar3 = qmi_send_request(ppuVar6 + -0x2d,ppuVar6 + -2,&local_c0,0x42,0x24,
                               coresight_etr_assign_req_msg_v01_ei,&local_70);
      if (iVar3 < 0) {
        _dev_err(*ppuVar1,"QMI send req failed, ret:%d\n",iVar3);
        qmi_txn_cancel(&local_c0);
      }
      else {
        iVar3 = qmi_txn_wait(&local_c0,0x9c4);
        if (iVar3 < 0) {
          puVar4 = *ppuVar1;
          pcVar5 = "QMI qmi txn wait failed, ret:%d\n";
          goto LAB_001005bc;
        }
        if ((short)local_78 == 0) {
          _dev_info(*ppuVar1,"Assign etr success\n");
          iVar3 = 0;
        }
        else {
          _dev_err(*ppuVar1,"QMI request failed 0x%x\n",local_78._2_2_);
        }
      }
    }
  }
  mutex_unlock(ppuVar6 + -0x33);
LAB_00100520:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// remote_etm_probe @ 0010067c size=552
// signature: undefined remote_etm_probe(void)
// callers: []
//------------------------------------------------------------

ulong remote_etm_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long *plVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 local_a0;
  undefined8 local_98;
  undefined1 *local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = (undefined1 *)0x0;
  local_70 = coresight_alloc_device_name(remote_etm_devs,lVar1);
  if (local_70 != 0) {
    uVar7 = coresight_get_platform_data(lVar1);
    if (0xfffffffffffff000 < uVar7) goto LAB_001007e0;
    *(ulong *)(param_1 + 0xa0) = uVar7;
    plVar8 = (long *)devm_kmalloc(lVar1,0x1b8,0xdc0);
    if (plVar8 != (long *)0x0) {
      uVar9 = *(undefined8 *)(param_1 + 0x2f8);
      *plVar8 = lVar1;
      *(long **)(param_1 + 0xa8) = plVar8;
      uVar5 = of_property_read_variable_u32_array(uVar9,"qcom,inst-id",plVar8 + 0x31,1,0);
      uVar6 = uVar5;
      if (-1 < (int)uVar5) {
        uVar6 = 0;
      }
      uVar7 = (ulong)uVar6;
      if (-1 < (int)uVar5) {
        __mutex_init(plVar8 + 2,"&drvdata->mutex",&remote_etm_probe___key);
        plVar2 = plVar8 + 8;
        uVar6 = qmi_handle_init(plVar2,7,&server_ops,0);
        if ((int)uVar6 < 0) {
          uVar7 = (ulong)uVar6;
          _dev_err(lVar1,"Remote ETM client init failed ret:%d\n",uVar7);
        }
        else {
          qmi_add_lookup(plVar2,0x33,1,(int)plVar8[0x31]);
          local_a0 = 3;
          local_88 = *(undefined8 *)(param_1 + 0xa0);
          *(int *)(plVar8 + 0x32) = remote_etm_probe_traceid;
          local_90 = remote_cs_ops;
          remote_etm_probe_traceid = remote_etm_probe_traceid + 1;
          local_80 = lVar1;
          uVar7 = coresight_register(&local_a0);
          plVar8[1] = uVar7;
          if (uVar7 < 0xfffffffffffff001) {
            _dev_info(lVar1,"Remote ETM initialized\n");
            pm_runtime_enable(lVar1);
            if (0x1f < *(uint *)(plVar8 + 0x31)) {
              _dev_err(lVar1,"inst_id greater than boot_enable bit mask\n");
            }
            puVar4 = PTR_remote_etm_list_00101010;
            plVar2 = plVar8 + 0x35;
            uVar10 = __list_add_valid(plVar2,PTR_remote_etm_list_00101010,&remote_etm_list);
            uVar7 = 0;
            if ((uVar10 & 1) != 0) {
              PTR_remote_etm_list_00101010 = (undefined *)plVar2;
              plVar8[0x35] = (long)&remote_etm_list;
              plVar8[0x36] = (long)puVar4;
              *(long **)puVar4 = plVar2;
            }
          }
          else {
            qmi_handle_release(plVar2);
          }
        }
      }
      goto LAB_001007e0;
    }
  }
  uVar7 = 0xfffffff4;
LAB_001007e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// remote_etm_remove @ 001008a8 size=116
// signature: undefined remote_etm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 remote_etm_remove(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  uVar3 = __list_del_entry_valid(lVar4 + 0x1a8);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(lVar4 + 0x1a8);
    plVar2 = *(long **)(lVar4 + 0x1b0);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(lVar4 + 0x1a8) = 0xdead000000000100;
  *(undefined8 *)(lVar4 + 0x1b0) = 0xdead000000000122;
  __pm_runtime_disable(param_1 + 0x10,1);
  qmi_handle_release(lVar4 + 0x40);
  coresight_unregister(*(undefined8 *)(lVar4 + 8));
  return 0;
}



//------------------------------------------------------------
// service_remote_etm_new_server @ 00100920 size=84
// signature: undefined service_remote_etm_new_server(void)
// callers: []
//------------------------------------------------------------

undefined8 service_remote_etm_new_server(long param_1,long param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 0x158) = 0x2a;
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_2 + 0xc);
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined1 *)(param_1 + 0x154) = 1;
  *(undefined4 *)(param_1 + 0x160) = uVar1;
  _dev_info(*(undefined8 *)(param_1 + -0x40),
            "Connection established between QMI handle and %d service\n",
            *(undefined4 *)(param_1 + 0x148));
  return 0;
}



//------------------------------------------------------------
// service_remote_etm_del_server @ 00100978 size=52
// signature: undefined service_remote_etm_del_server(void)
// callers: []
//------------------------------------------------------------

void service_remote_etm_del_server(long param_1)

{
  *(undefined1 *)(param_1 + 0x154) = 0;
  _dev_info(*(undefined8 *)(param_1 + -0x40),
            "Connection disconnected between QMI handle and %d service\n",
            *(undefined4 *)(param_1 + 0x148));
  return;
}



//------------------------------------------------------------
// remote_etm_trace_id @ 001009b0 size=16
// signature: undefined remote_etm_trace_id(void)
// callers: []
//------------------------------------------------------------

undefined4 remote_etm_trace_id(long param_1)

{
  return *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x98) + 0x98) + 400);
}



//------------------------------------------------------------
// remote_etm_disable @ 001009c4 size=388
// signature: undefined remote_etm_disable(void)
// callers: []
//------------------------------------------------------------

void remote_etm_disable(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48 [2];
  undefined4 local_40 [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0;
  local_48[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar6 = *(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  mutex_lock(puVar6 + 2);
  if (*(char *)((long)puVar6 + 0x194) == '\0') {
    _dev_err(*puVar6,"QMI service not connected!\n");
  }
  else {
    local_40[0] = 0;
    uVar2 = qmi_txn_init(puVar6 + 8,&local_90,coresight_set_etm_resp_msg_v01_ei,local_48);
    if ((int)uVar2 < 0) {
      uVar4 = *puVar6;
      pcVar5 = "QMI tx init failed , ret:%d\n";
    }
    else {
      iVar3 = qmi_send_request(puVar6 + 8,puVar6 + 0x33,&local_90,0x2c,7,
                               coresight_set_etm_req_msg_v01_ei,local_40);
      if (iVar3 < 0) {
        _dev_err(*puVar6,"QMI send req failed, ret:%d\n");
        qmi_txn_cancel(&local_90);
        goto LAB_00100b10;
      }
      uVar2 = qmi_txn_wait(&local_90,0x9c4);
      if ((int)uVar2 < 0) {
        uVar4 = *puVar6;
        pcVar5 = "QMI qmi txn wait failed, ret:%d\n";
      }
      else {
        if ((short)local_48[0] == 0) {
          *(undefined1 *)((long)puVar6 + 0x18c) = 0;
          _dev_info(*puVar6,"Remote ETM tracing disabled for instance %d\n",
                    *(undefined4 *)(puVar6 + 0x31));
          goto LAB_00100b10;
        }
        uVar4 = *puVar6;
        pcVar5 = "QMI request failed 0x%x\n";
        uVar2 = local_48[0] >> 0x10;
      }
    }
    _dev_err(uVar4,pcVar5,uVar2);
  }
LAB_00100b10:
  mutex_unlock(puVar6 + 2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// remote_etm_freeze @ 00100b4c size=40
// signature: undefined remote_etm_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 remote_etm_freeze(long param_1)

{
  coresight_disable(*(undefined8 *)(*(long *)(param_1 + 0x98) + 8));
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100ba4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&remote_etm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100bd4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&remote_etm_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103008 size=1
// signature: undefined _dev_err(void)
// callers: [remote_etm_etr_assign, remote_etm_probe, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 00103010 size=1
// signature: undefined qmi_txn_init(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 00103018 size=1
// signature: undefined qmi_send_request(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 00103020 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 00103028 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103030 size=1
// signature: undefined mutex_unlock(void)
// callers: [remote_etm_etr_assign, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103038 size=1
// signature: undefined _dev_info(void)
// callers: [remote_etm_etr_assign, remote_etm_probe, service_remote_etm_del_server, remote_etm_enable, remote_etm_disable, service_remote_etm_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [remote_etm_etr_assign, remote_etm_probe, remote_etm_enable, remote_etm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103048 size=1
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
// platform_driver_unregister @ 00103050 size=1
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
// coresight_alloc_device_name @ 00103058 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00103060 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103078 size=1
// signature: undefined __mutex_init(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 00103080 size=1
// signature: undefined qmi_handle_init(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 00103088 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00103090 size=1
// signature: undefined coresight_register(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 00103098 size=1
// signature: undefined qmi_handle_release(void)
// callers: [remote_etm_remove, remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 001030a0 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001030a8 size=1
// signature: undefined __list_add_valid(void)
// callers: [remote_etm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030b0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [remote_etm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 001030b8 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [remote_etm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 001030c0 size=1
// signature: undefined coresight_unregister(void)
// callers: [remote_etm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disable @ 001030c8 size=1
// signature: undefined coresight_disable(void)
// callers: [remote_etm_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



