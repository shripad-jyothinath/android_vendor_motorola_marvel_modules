// Decompiled by Ghidra 12.2
// Program: health_monitor.ko
// Image base: 00100000

//------------------------------------------------------------
// kern_check_system_health @ 00100334 size=616
// signature: undefined kern_check_system_health(void)
// callers: [system_health_monitor_ioctl]
//------------------------------------------------------------

int kern_check_system_health(void)

{
  int *piVar1;
  undefined **ppuVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined **ppuVar10;
  int iVar11;
  
  mutex_lock(hma_info_list_lock);
  if ((undefined **)hma_info_list == &hma_info_list) {
    iVar8 = 0;
  }
  else {
    lVar5 = sp_el0;
    ppuVar10 = (undefined **)hma_info_list;
    iVar11 = 0;
    do {
      iVar8 = iVar11;
      if (((*(char *)(ppuVar10 + 0x42) != '\0') && (*(int *)(ppuVar10 + 0x45) == 0)) &&
         (iVar7 = ___ratelimit(ppuVar10 + 0x4a,"shm_send_health_check_ind"), iVar7 != 0)) {
        piVar1 = (int *)((long)ppuVar10 + 0x224);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar7 = *piVar1;
          if (iVar7 != 0) goto LAB_001005b0;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_001005b0:
        if (iVar7 == 0) {
          ppuVar10[0x50] = (undefined *)0xfffffffe0;
          ppuVar10[0x51] = (undefined *)(ppuVar10 + 0x51);
          ppuVar10[0x52] = (undefined *)(ppuVar10 + 0x51);
          ppuVar10[0x53] = shm_svc_restart_worker;
          init_timer_key(ppuVar10 + 0x56,&delayed_work_timer_fn,0x200000,0,0);
          uVar6 = shm_svc_handle;
          ppuVar10[0x61] = (undefined *)ppuVar10;
          *(undefined1 *)(ppuVar10 + 0x62) = *(undefined1 *)(ppuVar10 + 0x42);
          *(undefined4 *)((long)ppuVar10 + 0x314) = *(undefined4 *)(ppuVar10 + 0x43);
          *(undefined4 *)(ppuVar10 + 99) = *(undefined4 *)((long)ppuVar10 + 0x21c);
          iVar8 = qmi_send_indication(uVar6,(long)ppuVar10 + 0x214,0x21,0,
                                      &hmon_health_check_ind_msg_v01_ei,0);
          uVar6 = shm_svc_workqueue;
          if (iVar8 < 0) {
            ppuVar2 = ppuVar10 + 2;
            ipc_log_string(shm_ilctxt,"%s: Send Error %d to %s\n","shm_send_health_check_ind",iVar8,
                           ppuVar2);
            _printk(&DAT_00102659,"shm_send_health_check_ind",iVar8,ppuVar2);
            *(undefined4 *)((long)ppuVar10 + 0x224) = 0;
            ipc_log_string(shm_ilctxt,"%s by %s failed for %s - rc %d\n","kern_check_system_health",
                           lVar5 + 0x848,ppuVar2,iVar8);
            _printk(&DAT_00102637,"kern_check_system_health",lVar5 + 0x848,ppuVar2,iVar8);
          }
          else {
            uVar9 = __msecs_to_jiffies(*(undefined4 *)(ppuVar10 + 0x44));
            queue_delayed_work_on(0x20,uVar6,ppuVar10 + 0x50,uVar9);
            iVar8 = iVar11;
          }
        }
        else {
          ipc_log_string(shm_ilctxt,"%s: Already checking\n","shm_send_health_check_ind");
          _printk(&DAT_001024e4,"shm_send_health_check_ind");
        }
      }
      ppuVar10 = (undefined **)*ppuVar10;
      iVar11 = iVar8;
    } while (ppuVar10 != &hma_info_list);
  }
  mutex_unlock(hma_info_list_lock);
  return iVar8;
}



//------------------------------------------------------------
// shm_svc_restart_worker @ 001005bc size=436
// signature: undefined shm_svc_restart_worker(void)
// callers: []
//------------------------------------------------------------

void shm_svc_restart_worker(long param_1)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x88);
  if (*(int *)(lVar4 + 0x224) == 1) {
    if (((*(char *)(lVar4 + 0x210) == '\0') || (*(int *)(param_1 + 0x94) != *(int *)(lVar4 + 0x218))
        ) || (*(int *)(param_1 + 0x98) != *(int *)(lVar4 + 0x21c))) {
      if (((byte)shm_debug_mask & 1) == 0) {
        return;
      }
      pcVar3 = "%s: Connection to %s is reset. No further action\n";
    }
    else {
      if (*(int *)(lVar4 + 0x228) == 0) {
        if (*(char *)(*(long *)(lVar4 + 0x278) + 0x4c4) != '\0') {
                    /* WARNING: Subroutine does not return */
          panic("%s: HMA in %s failed to respond in time, panic!\n","shm_svc_restart_worker",
                lVar4 + 0x10);
        }
        lVar1 = lVar4 + 0x110;
        ipc_log_string(shm_ilctxt,"%s: HMA in %s failed to respond in time. Restarting %s...\n",
                       "shm_svc_restart_worker",lVar4 + 0x10,lVar1);
        _printk(&DAT_001025c7,"shm_svc_restart_worker",lVar4 + 0x10,lVar1);
        iVar2 = *(int *)(*(long *)(lVar4 + 0x278) + 0x3cc);
        if ((iVar2 != 5) && (iVar2 != 2)) {
          return;
        }
        rproc_shutdown();
        iVar2 = rproc_boot(*(undefined8 *)(lVar4 + 0x278));
        if (iVar2 < 0) {
          ipc_log_string(shm_ilctxt,"%s: Error %d restarting %s\n","shm_svc_restart_worker",iVar2,
                         lVar1);
          _printk(&DAT_00102766,"shm_svc_restart_worker",iVar2,lVar1);
          return;
        }
        return;
      }
      if (((byte)shm_debug_mask & 1) == 0) {
        return;
      }
      pcVar3 = "%s: %s is going thru restart. No further action\n";
    }
  }
  else {
    if (((byte)shm_debug_mask & 1) == 0) {
      return;
    }
    pcVar3 = "%s: %s restart worker unexpected\n";
  }
  ipc_log_string(shm_ilctxt,pcVar3,"shm_svc_restart_worker",lVar4 + 0x10);
  return;
}



//------------------------------------------------------------
// system_health_monitor_probe @ 00100774 size=1504
// signature: undefined system_health_monitor_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int system_health_monitor_probe(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  long *plVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 *puVar8;
  char *pcVar9;
  ulong uVar10;
  long lVar11;
  undefined **ppuVar12;
  char *pcVar13;
  undefined **ppuVar14;
  undefined4 local_6c;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  mutex_lock(hma_info_list_lock);
  lVar7 = of_get_next_child(*(undefined8 *)(param_1 + 0x2f8),0);
  if (lVar7 != 0) {
    pcVar13 = "qcom,subsys-name";
    do {
      puVar8 = (undefined8 *)kmalloc_trace(_qmi_handle_init,0xdc0,800);
      if (puVar8 == (undefined8 *)0x0) {
        ipc_log_string(shm_ilctxt,"%s: Error allocation hma_info\n","system_health_monitor_probe");
        _printk(&DAT_001024c3,"system_health_monitor_probe");
        iVar6 = -0xc;
        goto LAB_00100c88;
      }
      local_6c = 0;
      pcVar9 = (char *)of_get_property(lVar7,"qcom,subsys-name",0);
      if (pcVar9 == (char *)0x0) {
LAB_00100bd8:
        ipc_log_string(shm_ilctxt,"%s: missing key: %s\n","parse_devicetree",pcVar13);
        _printk(&DAT_00102373,"parse_devicetree",pcVar13);
        iVar6 = -0x13;
LAB_00100c54:
        ipc_log_string(shm_ilctxt,"%s Failed to parse Device Tree\n","system_health_monitor_probe");
        _printk(&DAT_00102544,"system_health_monitor_probe");
        kfree(puVar8);
        goto LAB_00100c88;
      }
      uVar10 = strnlen(pcVar9,0x100);
      if (uVar10 == 0xffffffffffffffff) {
LAB_00100d38:
        fortify_panic("strnlen");
LAB_00100d44:
        fortify_panic("strscpy");
        goto LAB_00100d50;
      }
      if (uVar10 != 0x100) {
        uVar10 = uVar10 + 1;
      }
      if (0x100 < uVar10) goto LAB_00100d44;
      puVar1 = puVar8 + 2;
      strscpy(puVar1,pcVar9);
      pcVar9 = (char *)of_get_property(lVar7,"qcom,ssrestart-string",0);
      if (pcVar9 == (char *)0x0) {
        pcVar13 = "qcom,ssrestart-string";
        goto LAB_00100bd8;
      }
      uVar10 = strnlen(pcVar9,0x100);
      if (uVar10 == 0xffffffffffffffff) goto LAB_00100d38;
      if (uVar10 != 0x100) {
        uVar10 = uVar10 + 1;
      }
      if (0x100 < uVar10) goto LAB_00100d44;
      puVar2 = puVar8 + 0x22;
      strscpy(puVar2,pcVar9);
      lVar11 = of_find_property(lVar7,"qcom,rproc_phandle",&local_6c);
      if (lVar11 == 0) {
        pcVar13 = "qcom,rproc_phandle";
        goto LAB_00100bd8;
      }
      uVar5 = (**(uint **)(lVar11 + 0x10) & 0xff00ff00) >> 8 |
              (**(uint **)(lVar11 + 0x10) & 0xff00ff) << 8;
      lVar11 = rproc_get_by_phandle(uVar5 >> 0x10 | uVar5 << 0x10);
      puVar8[0x4f] = lVar11;
      if (lVar11 == 0) {
        ipc_log_string(shm_ilctxt,"%s: [%s]rproc phandle not ready\n",puVar1,"parse_devicetree");
        _printk(&DAT_0010214f,puVar1,"parse_devicetree");
        iVar6 = -0x205;
        goto LAB_00100c54;
      }
      puVar8[0x46] = restart_notifier_cb;
      uVar10 = qcom_register_ssr_notifier(puVar2,puVar8 + 0x46);
      puVar8[0x49] = uVar10;
      puVar3 = PTR_hma_info_list_001017e8;
      if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
        ipc_log_string(shm_ilctxt,"%s: Error registering restart notif for %s\n",
                       "system_health_monitor_probe",puVar2);
        _printk(&DAT_00102c42,"system_health_monitor_probe",puVar2);
        kfree(puVar8);
        iVar6 = -0xe;
        goto LAB_00100c88;
      }
      uVar10 = __list_add_valid(puVar8,PTR_hma_info_list_001017e8,&hma_info_list);
      if ((uVar10 & 1) != 0) {
        PTR_hma_info_list_001017e8 = (undefined *)puVar8;
        *puVar8 = &hma_info_list;
        puVar8[1] = puVar3;
        *(undefined8 **)puVar3 = puVar8;
      }
      if (((byte)shm_debug_mask & 1) != 0) {
        ipc_log_string(shm_ilctxt,"%s: Added HMA info for %s\n","system_health_monitor_probe",puVar1
                      );
      }
      lVar7 = of_get_next_child(*(undefined8 *)(param_1 + 0x2f8),lVar7);
    } while (lVar7 != 0);
  }
  shm_svc_workqueue = alloc_workqueue(&DAT_00102452,0xe000a,1,"shm_svc");
  if (shm_svc_workqueue == 0) {
    ipc_log_string(shm_ilctxt,"%s: Error creating workqueue\n","start_system_health_monitor_service"
                  );
    _printk(&DAT_00102229,"start_system_health_monitor_service");
    iVar6 = -0xe;
  }
  else {
    shm_svc_handle = kmalloc_trace(_alloc_workqueue,0xdc0,0x148);
    if (shm_svc_handle == 0) {
      ipc_log_string(shm_ilctxt,"%s: Error kzalloc for qmi handle\n",
                     "start_system_health_monitor_service");
      _printk(&DAT_00102504,"start_system_health_monitor_service");
      destroy_workqueue(shm_svc_workqueue);
      iVar6 = -0xc;
    }
    else {
      iVar6 = qmi_handle_init(shm_svc_handle,0x200,server_ops,qmi_shm_handlers);
      if (iVar6 < 0) {
        ipc_log_string(shm_ilctxt,"%s: Create qmi handle failed: %d\n",
                       "start_system_health_monitor_service",iVar6);
        _printk(&DAT_00102ca7,"start_system_health_monitor_service",iVar6);
      }
      else {
        iVar6 = qmi_add_server(shm_svc_handle,0x3c,1,0);
        if (-1 < iVar6) {
          if (((byte)shm_debug_mask & 1) != 0) {
            ipc_log_string(shm_ilctxt,"%s: Successfully\n","start_system_health_monitor_service");
          }
          iVar6 = 0;
          goto LAB_001009fc;
        }
        ipc_log_string(shm_ilctxt,"%s: qmi add server failed: %d\n",
                       "start_system_health_monitor_service",iVar6);
        _printk(&DAT_00102935,"start_system_health_monitor_service",iVar6);
        qmi_handle_release(shm_svc_handle);
      }
      kfree(shm_svc_handle);
      destroy_workqueue(shm_svc_workqueue);
    }
  }
  ipc_log_string(shm_ilctxt,"%s Failed to start service %d\n","system_health_monitor_probe",iVar6);
  _printk(&DAT_00102431,"system_health_monitor_probe",iVar6);
LAB_00100c88:
  ppuVar12 = (undefined **)hma_info_list;
  if ((undefined **)hma_info_list != &hma_info_list) {
    do {
      ppuVar14 = (undefined **)*ppuVar12;
      uVar10 = __list_del_entry_valid(ppuVar12);
      if ((uVar10 & 1) != 0) {
        puVar3 = *ppuVar12;
        plVar4 = (long *)ppuVar12[1];
        *(long **)(puVar3 + 8) = plVar4;
        *plVar4 = (long)puVar3;
      }
      *ppuVar12 = (undefined *)0xdead000000000100;
      ppuVar12[1] = (undefined *)0xdead000000000122;
      qcom_unregister_ssr_notifier(ppuVar12[0x49],ppuVar12 + 0x46);
      kfree(ppuVar12);
      ppuVar12 = ppuVar14;
    } while (ppuVar14 != &hma_info_list);
  }
LAB_001009fc:
  mutex_unlock(hma_info_list_lock);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) == local_68) {
    return iVar6;
  }
LAB_00100d50:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// restart_notifier_cb @ 00100d58 size=148
// signature: undefined restart_notifier_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 restart_notifier_cb(long param_1,long param_2)

{
  char *pcVar1;
  
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + -8) = 0;
    if (((byte)shm_debug_mask & 1) == 0) {
      return 0;
    }
    pcVar1 = "%s: %s powered up\n";
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    *(undefined4 *)(param_1 + -8) = 1;
    *(undefined1 *)(param_1 + -0x20) = 0;
    cancel_delayed_work(param_1 + 0x50);
    if (((byte)shm_debug_mask & 1) == 0) {
      return 0;
    }
    pcVar1 = "%s: %s going to shutdown\n";
  }
  ipc_log_string(shm_ilctxt,pcVar1,"restart_notifier_cb",param_1 + -0x120);
  return 0;
}



//------------------------------------------------------------
// shm_svc_disconnect_cb @ 00100df0 size=4
// signature: undefined shm_svc_disconnect_cb(void)
// callers: []
//------------------------------------------------------------

void shm_svc_disconnect_cb(void)

{
  return;
}



//------------------------------------------------------------
// shm_reg_req_handler @ 00100df8 size=840
// signature: undefined shm_reg_req_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shm_reg_req_handler(undefined8 param_1,undefined8 *param_2,undefined8 param_3,char *param_4)

{
  char *__s2;
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  bool bVar6;
  
  if (((byte)shm_debug_mask & 1) != 0) {
    ipc_log_string(shm_ilctxt,"%s, from [0x%x,0x%x]\n","shm_reg_req_handler",
                   *(undefined4 *)((long)param_2 + 4),*(undefined4 *)(param_2 + 1));
  }
  puVar3 = (undefined4 *)kmalloc_trace(_rproc_get_by_phandle,0xdc0,4);
  if (puVar3 == (undefined4 *)0x0) {
    ipc_log_string(shm_ilctxt,"%s: malloc for resp failed\n","shm_reg_req_handler");
    _printk(&DAT_001023bb,"shm_reg_req_handler");
    return;
  }
  if (*param_4 == '\0') {
    ipc_log_string(shm_ilctxt,"%s: host name invalid\n","shm_reg_req_handler");
    _printk(&DAT_001028ff,"shm_reg_req_handler");
  }
  else {
    if (((byte)shm_debug_mask & 1) != 0) {
      ipc_log_string(shm_ilctxt,"recv reg list: name_valid: %d, name: %s\n",*param_4,param_4 + 1);
    }
    mutex_lock(hma_info_list_lock);
    if ((undefined **)hma_info_list == &hma_info_list) {
      mutex_unlock(hma_info_list_lock);
    }
    else {
      bVar6 = false;
      __s2 = param_4 + 1;
      ppuVar5 = (undefined **)hma_info_list;
      do {
        iVar2 = strcmp((char *)(ppuVar5 + 2),__s2);
        if ((iVar2 == 0) && (*(int *)(ppuVar5 + 0x45) == 0)) {
          if (*(char *)(ppuVar5 + 0x42) != '\0') {
            ipc_log_string(shm_ilctxt,"%s: Duplicate HMA from %s-cur[0x%x:0x%x] new[0x%x:0x%x]\n",
                           "shm_reg_req_handler",__s2,*(undefined4 *)(ppuVar5 + 0x43),
                           *(undefined4 *)((long)ppuVar5 + 0x21c),*(undefined4 *)((long)param_2 + 4)
                           ,*(undefined4 *)(param_2 + 1));
            _printk(&DAT_00102566,"shm_reg_req_handler",__s2,*(undefined4 *)(ppuVar5 + 0x43),
                    *(undefined4 *)((long)ppuVar5 + 0x21c),*(undefined4 *)((long)param_2 + 4),
                    *(undefined4 *)(param_2 + 1));
          }
          *(undefined1 *)(ppuVar5 + 0x42) = 1;
          *(undefined4 *)((long)ppuVar5 + 0x224) = 0;
          uVar4 = *param_2;
          *(undefined4 *)((long)ppuVar5 + 0x21c) = *(undefined4 *)(param_2 + 1);
          *(undefined8 *)((long)ppuVar5 + 0x214) = uVar4;
          bVar1 = (byte)shm_debug_mask;
          if (param_4[0x101] == '\0') {
            iVar2 = shm_default_timeout_ms;
          }
          else {
            iVar2 = shm_default_timeout_ms + *(int *)(param_4 + 0x104);
          }
          *(int *)(ppuVar5 + 0x44) = iVar2;
          ppuVar5[0x4a] = (undefined *)0x0;
          ppuVar5[0x4b] = (undefined *)0x0;
          ppuVar5[0x4c] = (undefined *)0x0;
          ppuVar5[0x4d] = (undefined *)0x0;
          ppuVar5[0x4e] = (undefined *)0x0;
          *(undefined4 *)((long)ppuVar5 + 0x254) = 0x32;
          *(undefined4 *)(ppuVar5 + 0x4b) = 2;
          if ((bVar1 & 1) != 0) {
            ipc_log_string(shm_ilctxt,"%s: from %s timeout_ms %d [0x%x:0x%x]\n",
                           "shm_reg_req_handler",__s2,iVar2,*(undefined4 *)((long)param_2 + 4),
                           *(undefined4 *)(param_2 + 1));
          }
          bVar6 = true;
        }
        ppuVar5 = (undefined **)*ppuVar5;
      } while (ppuVar5 != &hma_info_list);
      mutex_unlock(hma_info_list_lock);
      if (bVar6) {
        *puVar3 = 0;
        goto LAB_0010101c;
      }
    }
  }
  *puVar3 = 0x290001;
LAB_0010101c:
  iVar2 = qmi_send_response(shm_svc_handle,param_2,param_3,0x20,7,hmon_register_resp_msg_v01_ei,
                            puVar3);
  if (iVar2 < 0) {
    ipc_log_string(shm_ilctxt,"%s: send_resp failed to %s - rc %d\n","shm_reg_req_handler",
                   param_4 + 1,iVar2);
    _printk(&DAT_001025a1,"shm_reg_req_handler",param_4 + 1,iVar2);
  }
  else if (((byte)shm_debug_mask & 1) != 0) {
    ipc_log_string(shm_ilctxt,"%s: send resp: %d\n","shm_reg_req_handler",iVar2);
  }
  kfree(puVar3);
  return;
}



//------------------------------------------------------------
// shm_chk_comp_req_handler @ 00101144 size=648
// signature: undefined shm_chk_comp_req_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void shm_chk_comp_req_handler(undefined8 param_1,long param_2,undefined8 param_3,char *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  bool bVar6;
  undefined **ppuVar7;
  
  puVar4 = (undefined4 *)kmalloc_trace(_rproc_get_by_phandle,0xdc0,4);
  if (puVar4 == (undefined4 *)0x0) {
    ipc_log_string(shm_ilctxt,"%s: malloc for resp failed\n","shm_chk_comp_req_handler");
    _printk(&DAT_001023bb,"shm_chk_comp_req_handler");
    return;
  }
  if (*param_4 == '\0') {
    ipc_log_string(shm_ilctxt,"%s: Invalid result\n","shm_chk_comp_req_handler");
    _printk(&DAT_001028b8,"shm_chk_comp_req_handler");
  }
  else {
    mutex_lock(hma_info_list_lock);
    if ((undefined **)hma_info_list == &hma_info_list) {
      mutex_unlock(hma_info_list_lock);
    }
    else {
      bVar6 = false;
      ppuVar7 = (undefined **)hma_info_list;
      do {
        if (((*(char *)(ppuVar7 + 0x42) != '\0') &&
            (*(int *)(ppuVar7 + 0x43) == *(int *)(param_2 + 4))) &&
           (*(int *)((long)ppuVar7 + 0x21c) == *(int *)(param_2 + 8))) {
          if (*(int *)(param_4 + 4) == 0) {
            piVar1 = (int *)((long)ppuVar7 + 0x224);
            Hint_Prefetch(piVar1,2,0,1);
            do {
              iVar3 = *piVar1;
              if (iVar3 != 1) goto LAB_001012a0;
              cVar2 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar6) {
                *piVar1 = 0;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            DataMemoryBarrier(2,3);
LAB_001012a0:
            if (iVar3 == 0) {
              if ((shm_debug_mask & 1) != 0) {
                pcVar5 = "%s: %s Health Check Unexpected.\n";
                goto LAB_0010122c;
              }
            }
            else {
              if ((shm_debug_mask & 1) != 0) {
                ipc_log_string(shm_ilctxt,"%s: %s Health Check Success\n","shm_chk_comp_req_handler"
                               ,ppuVar7 + 2);
              }
              cancel_delayed_work_sync(ppuVar7 + 0x50);
            }
          }
          else if ((shm_debug_mask & 1) != 0) {
            pcVar5 = "%s: %s Health Check Failure\n";
LAB_0010122c:
            ipc_log_string(shm_ilctxt,pcVar5,"shm_chk_comp_req_handler",ppuVar7 + 2);
          }
          bVar6 = true;
        }
        ppuVar7 = (undefined **)*ppuVar7;
      } while (ppuVar7 != &hma_info_list);
      mutex_unlock(hma_info_list_lock);
      if (bVar6) {
        *puVar4 = 0;
        goto LAB_001012f0;
      }
    }
  }
  *puVar4 = 0x290001;
LAB_001012f0:
  iVar3 = qmi_send_response(shm_svc_handle,param_2,param_3,0x22,7,
                            hmon_health_check_complete_resp_msg_v01_ei,puVar4);
  if (iVar3 < 0) {
    ipc_log_string(shm_ilctxt,"%s: send_resp failed - rc %d\n","shm_chk_comp_req_handler",iVar3);
    _printk(&DAT_00102b06,"shm_chk_comp_req_handler",iVar3);
  }
  kfree(puVar4);
  return;
}



//------------------------------------------------------------
// system_health_monitor_read @ 001013f0 size=100
// signature: undefined system_health_monitor_read(void)
// callers: []
//------------------------------------------------------------

undefined8 system_health_monitor_read(void)

{
  long lVar1;
  
  lVar1 = sp_el0;
  ipc_log_string(shm_ilctxt,"%s by %s\n","system_health_monitor_read",lVar1 + 0x848);
  _printk(&DAT_00102470,"system_health_monitor_read",lVar1 + 0x848);
  return 0xffffffffffffffa1;
}



//------------------------------------------------------------
// system_health_monitor_write @ 00101458 size=100
// signature: undefined system_health_monitor_write(void)
// callers: []
//------------------------------------------------------------

undefined8 system_health_monitor_write(void)

{
  long lVar1;
  
  lVar1 = sp_el0;
  ipc_log_string(shm_ilctxt,"%s by %s\n","system_health_monitor_write",lVar1 + 0x848);
  _printk(&DAT_00102470,"system_health_monitor_write",lVar1 + 0x848);
  return 0xffffffffffffffa1;
}



//------------------------------------------------------------
// system_health_monitor_ioctl @ 001014c0 size=196
// signature: undefined system_health_monitor_ioctl(void)
// callers: []
//------------------------------------------------------------

long system_health_monitor_ioctl(undefined8 param_1,int param_2)

{
  int iVar1;
  long lVar2;
  
  if (param_2 == -0x7ffb3d00) {
    if (((byte)shm_debug_mask & 1) != 0) {
      lVar2 = sp_el0;
      ipc_log_string(shm_ilctxt,"%s by %s\n","system_health_monitor_ioctl",lVar2 + 0x848);
    }
    iVar1 = kern_check_system_health();
    lVar2 = (long)iVar1;
  }
  else {
    lVar2 = sp_el0;
    ipc_log_string(shm_ilctxt,"%s: Invalid cmd %d by %s\n","system_health_monitor_ioctl",param_2,
                   lVar2 + 0x848);
    _printk(&DAT_001026d5,"system_health_monitor_ioctl",param_2,lVar2 + 0x848);
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// system_health_monitor_open @ 00101588 size=76
// signature: undefined system_health_monitor_open(void)
// callers: []
//------------------------------------------------------------

undefined8 system_health_monitor_open(void)

{
  long lVar1;
  
  if (((byte)shm_debug_mask >> 1 & 1) != 0) {
    lVar1 = sp_el0;
    ipc_log_string(shm_ilctxt,"%s by %s\n","system_health_monitor_open",lVar1 + 0x848);
  }
  return 0;
}



//------------------------------------------------------------
// system_health_monitor_release @ 001015d8 size=76
// signature: undefined system_health_monitor_release(void)
// callers: []
//------------------------------------------------------------

undefined8 system_health_monitor_release(void)

{
  long lVar1;
  
  if (((byte)shm_debug_mask >> 1 & 1) != 0) {
    lVar1 = sp_el0;
    ipc_log_string(shm_ilctxt,"%s by %s\n","system_health_monitor_release",lVar1 + 0x848);
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00101a70 size=700
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong init_module(void)

{
  uint uVar1;
  undefined *puVar2;
  ulong uVar3;
  
  shm_ilctxt = ipc_log_context_create(2,&DAT_00102a59,0);
  if (shm_ilctxt == 0) {
    ipc_log_string(0,"%s: Unable to create SHM logging context\n","system_health_monitor_init");
    _printk(&DAT_001023f7,"system_health_monitor_init");
    shm_debug_mask = 0;
  }
  uVar1 = __platform_driver_register(&system_health_monitor_driver,&__this_module);
  if (uVar1 == 0) {
    uVar1 = alloc_chrdev_region(&system_health_monitor_dev,0,1,"system_health_monitor");
    if (-1 < (int)uVar1) {
      system_health_monitor_classp =
           __class_create(&__this_module,"system_health_monitor",&system_health_monitor_init___key);
      if ((system_health_monitor_classp == 0) || (0xfffffffffffff000 < system_health_monitor_classp)
         ) {
        ipc_log_string(shm_ilctxt,"%s: class_create() failed\n","system_health_monitor_init");
        _printk(&DAT_001024a6,"system_health_monitor_init");
        uVar3 = 0xfffffff4;
      }
      else {
        cdev_init(system_health_monitor_cdev,&system_health_monitor_fops);
        system_health_monitor_cdev._96_8_ = &__this_module;
        uVar1 = cdev_add(system_health_monitor_cdev,system_health_monitor_dev,1);
        uVar3 = (ulong)uVar1;
        if ((int)uVar1 < 0) {
          ipc_log_string(shm_ilctxt,"%s: cdev_add() failed - rc %d\n","system_health_monitor_init",
                         uVar3);
          _printk(&DAT_00102352,"system_health_monitor_init",uVar3);
        }
        else {
          _system_health_monitor_devp =
               device_create(system_health_monitor_classp,0,system_health_monitor_dev,0,
                             "system_health_monitor");
          if ((_system_health_monitor_devp != 0) &&
             (_system_health_monitor_devp < 0xfffffffffffff001)) {
            if ((shm_debug_mask & 1) != 0) {
              ipc_log_string(shm_ilctxt,"%s: Complete\n","system_health_monitor_init");
            }
            return 0;
          }
          ipc_log_string(shm_ilctxt,"%s: device_create() failed - rc %d\n",
                         "system_health_monitor_init",uVar3);
          _printk(&DAT_0010279f,"system_health_monitor_init",uVar3);
          uVar3 = _system_health_monitor_devp & 0xffffffff;
          cdev_del(system_health_monitor_cdev);
        }
        class_destroy(system_health_monitor_classp);
      }
      unregister_chrdev_region(system_health_monitor_dev >> 0x14,1);
      return uVar3;
    }
    uVar3 = (ulong)uVar1;
    ipc_log_string(shm_ilctxt,"%s: alloc_chrdev_region() failed %d\n","system_health_monitor_init",
                   uVar3);
    puVar2 = &DAT_001022d6;
  }
  else {
    uVar3 = (ulong)uVar1;
    ipc_log_string(shm_ilctxt,"%s: system_health_monitor_driver register failed %d\n",
                   "system_health_monitor_init",uVar3);
    puVar2 = &DAT_0010229f;
  }
  _printk(puVar2,"system_health_monitor_init",uVar3);
  return uVar3;
}



//------------------------------------------------------------
// mutex_lock @ 00104008 size=1
// signature: undefined mutex_lock(void)
// callers: [kern_check_system_health, system_health_monitor_probe, shm_reg_req_handler, shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104018 size=1
// signature: undefined mutex_unlock(void)
// callers: [kern_check_system_health, system_health_monitor_probe, shm_reg_req_handler, shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104020 size=1
// signature: undefined ipc_log_string(void)
// callers: [kern_check_system_health, system_health_monitor_read, shm_svc_restart_worker, system_health_monitor_release, system_health_monitor_probe, restart_notifier_cb, system_health_monitor_write, shm_reg_req_handler, shm_chk_comp_req_handler, system_health_monitor_open, init_module, system_health_monitor_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104028 size=1
// signature: undefined _printk(void)
// callers: [kern_check_system_health, system_health_monitor_read, shm_svc_restart_worker, system_health_monitor_probe, system_health_monitor_write, shm_reg_req_handler, shm_chk_comp_req_handler, init_module, system_health_monitor_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104030 size=1
// signature: undefined ___ratelimit(void)
// callers: [kern_check_system_health]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00104040 size=1
// signature: undefined init_timer_key(void)
// callers: [kern_check_system_health]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_indication @ 00104048 size=1
// signature: undefined qmi_send_indication(void)
// callers: [kern_check_system_health]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_indication(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00104050 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [kern_check_system_health]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00104058 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [kern_check_system_health]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00104060 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104068 size=1
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
// alloc_chrdev_region @ 00104070 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00104078 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00104080 size=1
// signature: undefined cdev_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00104088 size=1
// signature: undefined cdev_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00104090 size=1
// signature: undefined device_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00104098 size=1
// signature: undefined cdev_del(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001040a0 size=1
// signature: undefined class_destroy(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001040a8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_shutdown @ 001040b0 size=1
// signature: undefined rproc_shutdown(void)
// callers: [shm_svc_restart_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_boot @ 001040b8 size=1
// signature: undefined rproc_boot(void)
// callers: [shm_svc_restart_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_boot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001040c0 size=1
// signature: noreturn undefined panic(void)
// callers: [shm_svc_restart_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 001040c8 size=1
// signature: undefined of_get_next_child(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001040d8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [system_health_monitor_probe, shm_reg_req_handler, shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001040e0 size=1
// signature: undefined of_get_property(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001040e8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001040f0 size=1
// signature: undefined strscpy(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040f8 size=1
// signature: undefined of_find_property(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 00104100 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 00104108 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104110 size=1
// signature: undefined __list_add_valid(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00104118 size=1
// signature: undefined alloc_workqueue(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 00104120 size=1
// signature: undefined qmi_handle_init(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_server @ 00104128 size=1
// signature: undefined qmi_add_server(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_server(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00104130 size=1
// signature: undefined destroy_workqueue(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 00104138 size=1
// signature: undefined qmi_handle_release(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104140 size=1
// signature: undefined kfree(void)
// callers: [system_health_monitor_probe, shm_reg_req_handler, shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 00104148 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104150 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104158 size=1
// signature: undefined fortify_panic(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104160 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [system_health_monitor_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00104168 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [restart_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104170 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [shm_reg_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_response @ 00104178 size=1
// signature: undefined qmi_send_response(void)
// callers: [shm_reg_req_handler, shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00104180 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [shm_chk_comp_req_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



