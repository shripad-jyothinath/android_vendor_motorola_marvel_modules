// Decompiled by Ghidra 12.2
// Program: slim-qcom-ngd-ctrl.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_slimbus_dbg @ 00100abc size=116
// signature: undefined __traceiter_slimbus_dbg(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_slimbus_dbg(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00106f20;
  plVar2 = DAT_00106f20;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x3e01ec59) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100b0c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_slimbus_dbg @ 00100b34 size=312
// signature: undefined trace_event_raw_event_slimbus_dbg(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_slimbus_dbg(long param_1,char *param_2,undefined8 *param_3)

{
  char *__s;
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong uVar6;
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
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar6 = __trace_trigger_soft_disabled(param_1), (uVar6 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar4 = strlen(__s);
    iVar3 = (int)sVar4;
    lVar5 = trace_event_buffer_reserve(&local_78,param_1,(long)(iVar3 + 0x65) + 0x10);
    if (lVar5 != 0) {
      *(int *)(lVar5 + 8) = iVar3 * 0x10000 + 0x10010;
      *(uint *)(lVar5 + 0xc) = iVar3 + 0x11U | 0x640000;
      strcpy((char *)(lVar5 + 0x10),__s);
      puVar1 = (undefined8 *)param_3[1];
      local_88 = puVar1[2];
      uStack_80 = puVar1[3];
      local_98 = *puVar1;
      uStack_90 = puVar1[1];
      iVar3 = vsnprintf((char *)(lVar5 + (ulong)(iVar3 + 0x11U & 0xffff)),100,(char *)*param_3,
                        &local_98);
      if (99 < iVar3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100c68);
        (*pcVar2)();
      }
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_slimbus_dbg @ 00100c74 size=384
// signature: undefined perf_trace_slimbus_dbg(void)
// callers: []
//------------------------------------------------------------

void perf_trace_slimbus_dbg(long param_1,char *param_2,undefined8 *param_3)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  int iVar6;
  size_t sVar7;
  long lVar8;
  uint uVar9;
  ulong unaff_x30;
  undefined1 auStack_90 [8];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar8 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_58 = *(long *)(lVar8 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar7 = strlen(__s);
  lVar8 = tpidr_el1;
  plVar2 = (long *)(lVar8 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    uVar9 = (uint)sVar7;
    iVar1 = (uVar9 & 0xfffffff8) + 0x7c;
    lVar8 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar8 != 0) {
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xe8) = auStack_90 + 0x40;
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(undefined1 **)(local_60 + 0xf8) = auStack_90;
      *(uint *)(lVar8 + 8) = uVar9 * 0x10000 + 0x10010;
      *(uint *)(lVar8 + 0xc) = uVar9 + 0x11 | 0x640000;
      strcpy((char *)(lVar8 + 0x10),__s);
      puVar4 = (undefined8 *)param_3[1];
      local_78 = puVar4[2];
      uStack_70 = puVar4[3];
      local_88 = *puVar4;
      uStack_80 = puVar4[1];
      iVar6 = vsnprintf((char *)(lVar8 + (ulong)(uVar9 + 0x11 & 0xffff)),100,(char *)*param_3,
                        &local_88);
      if (99 < iVar6) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100df0);
        (*pcVar5)();
      }
      perf_trace_run_bpf_submit(lVar8,iVar1,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_slimbus_dbg @ 00100dfc size=28
// signature: undefined __bpf_trace_slimbus_dbg(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_slimbus_dbg(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// __slimbus_dbg @ 00100e1c size=124
// signature: undefined __slimbus_dbg(void)
// callers: [qcom_slim_ngd_qmi_del_server, qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_disable_stream, qcom_slim_ngd_up_worker, qcom_slim_qmi_power_request, qcom_slim_ngd_ctrl_probe, qcom_ngd_set_suspend, qcom_slim_ngd_exit_dma, qcom_slim_ngd_get_laddr, qcom_slim_ngd_runtime_resume, qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_enable, qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_interrupt, qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_master_worker, qcom_slim_ngd_probe, qcom_slim_ngd_ssr_pdr_notify, qcom_slim_ngd_setup, qcom_slim_ngd_enable_stream, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post, qcom_slim_ngd_qmi_new_server, qcom_slim_ngd_runtime_idle]
//------------------------------------------------------------

void __slimbus_dbg(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sp_el0;
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != *(long *)(lVar1 + 0x638)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_slimbus_dbg @ 00100f3c size=112
// signature: undefined trace_raw_output_slimbus_dbg(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_slimbus_dbg(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: %s\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_ctrl_probe @ 00100fb0 size=2148
// signature: undefined qcom_slim_ngd_ctrl_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_slim_ngd_ctrl_probe(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  int *piVar12;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined6 uStack_78;
  undefined2 local_72;
  undefined6 uStack_70;
  long local_68;
  
  lVar5 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_68 = *(long *)(lVar5 + 0x638);
  uStack_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_72 = 0;
  local_88 = 0;
  lVar5 = devm_kmalloc(plVar1,0x15e0,0xdc0);
  if (lVar5 == 0) {
    uVar7 = 0xfffffff4;
    goto LAB_00101718;
  }
  *(long *)(param_1 + 0xa8) = lVar5;
  uVar6 = platform_get_resource(param_1,0x200,0);
  uVar7 = devm_ioremap_resource(plVar1,uVar6);
  *(ulong *)(lVar5 + 0x7f0) = uVar7;
  if (0xfffffffffffff000 < uVar7) goto LAB_00101718;
  uVar8 = platform_get_irq(param_1,0);
  uVar7 = uVar8 & 0xffffffff;
  if ((int)uVar8 < 0) goto LAB_00101718;
  *(int *)(lVar5 + 0x15d8) = (int)uVar8;
  iVar3 = devm_request_threaded_irq(plVar1,uVar7,qcom_slim_ngd_interrupt,0,4,"slim-ngd",lVar5);
  if (iVar3 != 0) {
    uVar7 = dev_err_probe(plVar1,iVar3,"request IRQ failed\n");
    uVar7 = uVar7 & 0xffffffff;
    goto LAB_00101718;
  }
  *(undefined1 *)(lVar5 + 0x15dc) = 0;
  *(undefined1 *)(lVar5 + 0x15b4) = 0;
  plVar9 = (long *)platform_get_resource_byname(param_1,0x200,"slimbus_remote_mem");
  iVar3 = dma_set_mask(plVar1,0xffffffff);
  if (iVar3 != 0) {
    _dev_err(plVar1,"could not set 32 bit mask\n");
    uVar7 = 0xffffffed;
    goto LAB_00101718;
  }
  dma_set_coherent_mask(plVar1,0xffffffff);
  if (plVar9 == (long *)0x0) {
    _dev_err(plVar1,"no Remote mem\n");
  }
  else {
    *(undefined1 *)(lVar5 + 0x15b4) = 1;
    *(int *)(lVar5 + 0x15b0) = (int)*plVar9;
    lVar10 = devm_ioremap(plVar1,*plVar9,(plVar9[1] - *plVar9) + 1);
    *(long *)(lVar5 + 0x15a0) = lVar10;
    if (lVar10 == 0) {
      _dev_err(plVar1,"Remote mem ioremap failed\n");
      uVar7 = 0xfffffff4;
      goto LAB_00101718;
    }
    *(long *)(lVar5 + 0x15a8) = lVar10;
    *(long **)(lVar5 + 0x1598) = plVar9;
  }
  lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wait_for_adsp_up",0);
  lVar11 = *(long *)(param_1 + 0x80);
  *(bool *)(lVar5 + 0x15c1) = lVar10 != 0;
  if (lVar11 == 0) {
    lVar11 = *plVar1;
  }
  lVar10 = ipc_log_context_create(10,lVar11,0);
  *(long *)(lVar5 + 0x15c8) = lVar10;
  if (lVar10 == 0) {
    _dev_err(plVar1,"error creating ipc_logging context\n");
  }
  else {
    lVar10 = *(long *)(param_1 + 0x80);
    *(undefined8 *)(lVar5 + 0x15b8) = 0x300000003;
    if (lVar10 == 0) {
      lVar10 = *plVar1;
    }
    __slimbus_dbg("qcom_slim_ngd_ctrl_probe","start logging for slim dev %s\n",lVar10);
    iVar3 = *(int *)(lVar5 + 0x15bc);
    if (2 < iVar3) {
      lVar10 = *(long *)(param_1 + 0x80);
      if (lVar10 == 0) {
        lVar10 = *plVar1;
      }
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"start logging for slim dev %s\n",lVar10);
      iVar3 = *(int *)(lVar5 + 0x15bc);
    }
    if (iVar3 == 0) {
      lVar10 = *(long *)(param_1 + 0x80);
      if (lVar10 == 0) {
        lVar10 = *plVar1;
      }
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"start logging for slim dev %s\n",lVar10);
    }
  }
  lVar10 = *(long *)(param_1 + 0x80);
  uStack_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_72 = 0;
  local_88 = 0;
  if (lVar10 == 0) {
    lVar10 = *plVar1;
  }
  scnprintf(&local_88,0x1e,&DAT_00107d54,lVar10,&DAT_00108b02);
  lVar10 = ipc_log_context_create(10,&local_88,0);
  *(long *)(lVar5 + 0x15d0) = lVar10;
  if (lVar10 == 0) {
    _dev_err(plVar1,"error creating ipc_error_logging context\n");
  }
  else {
    __slimbus_dbg("qcom_slim_ngd_ctrl_probe","start error logging for slim dev %s\n",&local_88);
    iVar3 = *(int *)(lVar5 + 0x15bc);
    if (2 < iVar3) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"start error logging for slim dev %s\n",
                     &local_88);
      iVar3 = *(int *)(lVar5 + 0x15bc);
    }
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"start error logging for slim dev %s\n",
                     &local_88);
    }
  }
  iVar3 = sysfs_create_file_ns(plVar1,&dev_attr_debug_mask,0);
  if (iVar3 != 0) {
    _dev_err(plVar1,"Failed to create sysfs ret:%d\n",iVar3);
  }
  *(bool *)(lVar5 + 0x15c0) = iVar3 == 0;
  *(code **)(lVar5 + 0x1538) = qcom_slim_ngd_ssr_notify;
  uVar7 = qcom_register_ssr_notifier("lpass",lVar5 + 0x1538);
  *(ulong *)(lVar5 + 0x1550) = uVar7;
  if (uVar7 < 0xfffffffffffff001) {
    *(undefined4 *)(lVar5 + 0x3d4) = 10;
    *(undefined8 *)(lVar5 + 0x398) = 0xfa0002ee000;
    *(code **)(lVar5 + 0x4b8) = qcom_slim_ngd_get_laddr;
    *(code **)(lVar5 + 0x4d8) = qcom_ngd_set_suspend;
    *(code **)(lVar5 + 0x4a8) = qcom_slim_ngd_xfer_msg;
    *(long **)(lVar5 + 0x7e8) = plVar1;
    *(long *)(lVar5 + 1000) = lVar5;
    *(code **)(lVar5 + 0x4c0) = qcom_slim_ngd_enable_stream;
    *(undefined8 *)(lVar5 + 0x4d0) = 0;
    *(code **)(lVar5 + 0x4c8) = qcom_slim_ngd_disable_stream;
    *(undefined4 *)(lVar5 + 0x1560) = 3;
    __mutex_init(lVar5 + 0x1478,"&ctrl->tx_lock",&qcom_slim_ngd_ctrl_probe___key);
    __mutex_init(lVar5 + 0x14a8,"&ctrl->suspend_resume_lock",&qcom_slim_ngd_ctrl_probe___key_27);
    __mutex_init(lVar5 + 0x14d8,"&ctrl->ssr_lock",&qcom_slim_ngd_ctrl_probe___key_29);
    __mutex_init(lVar5 + 0x1508,"&ctrl->qmi_handle_lock",&qcom_slim_ngd_ctrl_probe___key_31);
    *(undefined4 *)(lVar5 + 0x1470) = 0;
    *(undefined4 *)(lVar5 + 0x1348) = 0;
    __init_swait_queue_head(lVar5 + 0x1350,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x1368) = 0;
    __init_swait_queue_head(lVar5 + 0x1370,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x7c0) = 0;
    __init_swait_queue_head(lVar5 + 0x7c8,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x13f0) = 0;
    __init_swait_queue_head(lVar5 + 0x13f8,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x1410) = 0;
    __init_swait_queue_head(lVar5 + 0x1418,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x1430) = 0;
    __init_swait_queue_head(lVar5 + 0x1438,"&x->wait",&init_completion___key);
    *(undefined4 *)(lVar5 + 0x1450) = 0;
    __init_swait_queue_head(lVar5 + 0x1458,"&x->wait",&init_completion___key);
    uVar7 = pdr_handle_alloc(slim_pd_status,lVar5);
    *(ulong *)(lVar5 + 0x1558) = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      uVar7 = pdr_add_lookup(uVar7,"avs/audio","msm/adsp/audio_pd");
      if ((uVar7 < 0xfffffffffffff001) || (uVar7 == 0xffffffffffffff8e)) {
        local_8c = 0;
        lVar10 = of_match_node(&qcom_slim_ngd_dt_match,*(undefined8 *)(param_1 + 0x2f8));
        piVar12 = *(int **)(lVar10 + 0xc0);
        lVar10 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0);
        if (lVar10 != 0) {
          do {
            iVar3 = of_property_read_variable_u32_array(lVar10,&DAT_00107d0b,&local_8c,1,0);
            if (-1 < iVar3) {
              plVar9 = (long *)kmalloc_trace(_platform_device_put,0xdc0,0x18);
              if (plVar9 == (long *)0x0) {
                uVar7 = 0xfffffff4;
                goto LAB_001016a0;
              }
              lVar11 = platform_device_alloc("qcom,slim-ngd",local_8c);
              *plVar9 = lVar11;
              if (lVar11 == 0) {
                uVar7 = 0xfffffff4;
              }
              else {
                *(undefined4 *)(plVar9 + 2) = local_8c;
                *(long **)(lVar11 + 0x70) = plVar1;
                lVar11 = *plVar9;
                uVar4 = driver_set_override(lVar11 + 0x10,lVar11 + 0x3d0,"qcom,slim-ngd",0xd);
                if (uVar4 == 0) {
                  *(long *)(lVar11 + 0x2f8) = lVar10;
                  lVar10 = *plVar9;
                  *(long **)(lVar5 + 0x7e0) = plVar9;
                  uVar4 = platform_device_add(lVar10);
                  if (uVar4 == 0) {
                    plVar9[1] = *(long *)(lVar5 + 0x7f0) + (ulong)(uint)(*piVar12 * (int)plVar9[2])
                                + (ulong)(uint)(piVar12[1] * ((int)plVar9[2] + -1));
                    __platform_driver_register(&qcom_slim_ngd_driver,&__this_module);
                    __slimbus_dbg("qcom_slim_ngd_ctrl_probe","NGD SB controller is up!\n");
                    iVar3 = *(int *)(lVar5 + 0x15bc);
                    if (2 < iVar3) {
                      ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"NGD SB controller is up!\n");
                      iVar3 = *(int *)(lVar5 + 0x15bc);
                    }
                    if (iVar3 == 0) {
                      ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"NGD SB controller is up!\n");
                    }
                    uVar7 = 0;
                    goto LAB_00101718;
                  }
                  lVar11 = *plVar9;
                }
                uVar7 = (ulong)uVar4;
                platform_device_put(lVar11);
              }
              kfree(plVar9);
              goto LAB_001016a0;
            }
            lVar10 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),lVar10);
          } while (lVar10 != 0);
        }
        uVar7 = 0xffffffed;
LAB_001016a0:
        __slimbus_dbg("qcom_slim_ngd_ctrl_probe","qcom_slim_ngd_register failed ret:%d\n",uVar7);
        if (*(int *)(lVar5 + 0x15bc) < 1) {
          if (*(int *)(lVar5 + 0x15bc) != 0) goto LAB_001016dc;
        }
        else {
          _printk(&DAT_00108764,uVar7);
          ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"qcom_slim_ngd_register failed ret:%d\n",
                         uVar7);
          uVar2 = *(undefined4 *)(lVar5 + 0x15bc);
          *(undefined4 *)(lVar5 + 0x15bc) = 0;
          *(undefined4 *)(lVar5 + 0x15b8) = uVar2;
        }
        ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"qcom_slim_ngd_register failed ret:%d\n",
                       uVar7);
      }
      else {
        uVar7 = dev_err_probe(plVar1,uVar7,"pdr add lookup failed: %d\n",iVar3);
        uVar7 = uVar7 & 0xffffffff;
      }
LAB_001016dc:
      pdr_handle_release(*(undefined8 *)(lVar5 + 0x1558));
    }
    else {
      uVar7 = dev_err_probe(plVar1,uVar7 & 0xffffffff,"Failed to init PDR handle: %d\n",iVar3);
      uVar7 = uVar7 & 0xffffffff;
    }
    qcom_unregister_ssr_notifier(*(undefined8 *)(lVar5 + 0x1550),lVar5 + 0x1538);
  }
  else {
    _dev_err(plVar1,"Failed to register SSR notification: %d\n",uVar7 & 0xffffffff);
    uVar7 = uVar7 & 0xffffffff;
  }
  if (*(long *)(lVar5 + 0x15c8) != 0) {
    ipc_log_context_destroy();
  }
  if (*(char *)(lVar5 + 0x15c0) != '\0') {
    sysfs_remove_file_ns(plVar1,&dev_attr_debug_mask,0);
  }
LAB_00101718:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_slim_ngd_ctrl_remove @ 00101818 size=100
// signature: undefined qcom_slim_ngd_ctrl_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_ctrl_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  platform_driver_unregister(&qcom_slim_ngd_driver);
  if (*(char *)(lVar1 + 0x15c0) != '\0') {
    sysfs_remove_file_ns(param_1 + 0x10,&dev_attr_debug_mask,0);
  }
  ipc_log_context_destroy(*(undefined8 *)(lVar1 + 0x15c8));
  *(undefined8 *)(lVar1 + 0x15c8) = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_slim_ngd_interrupt @ 00101880 size=324
// signature: undefined qcom_slim_ngd_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_interrupt(undefined8 param_1,long param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_2 + 0x7e0) + 8);
  if ((*(int *)(*(long *)(param_2 + 0x3a0) + 0x20c) == 2) &&
     ((*(ushort *)(*(long *)(param_2 + 0x3a0) + 0x200) & 7) == 0)) {
    puVar1 = (undefined1 *)(param_2 + 0x15dc);
    __slimbus_dbg("qcom_slim_ngd_interrupt","Slimbus is in suspend state %d\n",*puVar1);
    iVar3 = *(int *)(param_2 + 0x15bc);
    if (2 < iVar3) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x15c8),"Slimbus is in suspend state %d\n",*puVar1);
      iVar3 = *(int *)(param_2 + 0x15bc);
    }
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x15d0),"Slimbus is in suspend state %d\n",*puVar1);
    }
  }
  else {
    uVar2 = readl(lVar4 + 0x14);
    if ((uVar2 & 0x2e000000) != 0) {
      __slimbus_dbg("qcom_slim_ngd_interrupt","Error Interrupt received 0x%x\n",uVar2);
      iVar3 = *(int *)(param_2 + 0x15bc);
      if (1 < iVar3) {
        _printk(&DAT_001081cb,uVar2);
        ipc_log_string(*(undefined8 *)(param_2 + 0x15c8),"Error Interrupt received 0x%x\n",uVar2);
        iVar3 = *(int *)(param_2 + 0x15bc);
      }
      if (iVar3 == 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x15d0),"Error Interrupt received 0x%x\n",uVar2);
      }
    }
    writel(uVar2,lVar4 + 0x18);
  }
  return 1;
}



//------------------------------------------------------------
// qcom_slim_ngd_ssr_notify @ 001019c8 size=40
// signature: undefined qcom_slim_ngd_ssr_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_ssr_notify(long param_1)

{
  qcom_slim_ngd_ssr_pdr_notify(param_1 + -0x1538);
  return 1;
}



//------------------------------------------------------------
// qcom_slim_ngd_get_laddr @ 001019f4 size=420
// signature: undefined qcom_slim_ngd_get_laddr(void)
// callers: []
//------------------------------------------------------------

int qcom_slim_ngd_get_laddr(long param_1,undefined4 *param_2,undefined1 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  int local_60;
  short local_5c;
  undefined8 local_58;
  undefined2 local_50;
  undefined8 local_48;
  undefined2 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_90 = &local_80;
  local_80 = 0x70000;
  local_78 = &local_58;
  uStack_88 = 0;
  local_70 = &local_48;
  uStack_68 = 0;
  local_5c = 0;
  local_60 = 0;
  local_40 = 0;
  local_48 = 0;
  local_50 = 0;
  local_58 = 0;
  local_98 = 0xff000000000d020b;
  iVar3 = slim_alloc_txn_tid(param_1,&local_98);
  uVar2 = local_48;
  if (-1 < iVar3) {
    local_48._7_1_ = SUB81(uVar2,7);
    local_48._0_7_ = CONCAT25(*(undefined2 *)(param_2 + 1),CONCAT41(*param_2,local_98._6_1_));
    iVar3 = qcom_slim_ngd_xfer_msg_sync(param_1,&local_98);
    if (iVar3 == 0) {
      if ((int)local_58 == local_60 && local_58._4_2_ == local_5c) {
        iVar3 = -6;
      }
      else {
        *param_3 = local_58._6_1_;
        __slimbus_dbg("qcom_slim_ngd_get_laddr","%s end ret : %d\n","qcom_slim_ngd_get_laddr",0);
        iVar3 = *(int *)(param_1 + 0x121c);
        if (2 < iVar3) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x1228),"%s end ret : %d\n",
                         "qcom_slim_ngd_get_laddr",0);
          iVar3 = *(int *)(param_1 + 0x121c);
        }
        if (iVar3 == 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x1230),"%s end ret : %d\n",
                         "qcom_slim_ngd_get_laddr",0);
        }
        iVar3 = 0;
      }
    }
    else {
      slim_free_txn_tid(param_1,&local_98);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qcom_ngd_set_suspend @ 00101b9c size=196
// signature: undefined qcom_ngd_set_suspend(void)
// callers: []
//------------------------------------------------------------

int qcom_ngd_set_suspend(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = qcom_slim_ngd_runtime_suspend(*param_1);
  if (iVar1 == 0) {
    __pm_runtime_disable(*param_1,1);
    __pm_runtime_set_status(*param_1,2);
    pm_runtime_enable(*param_1);
  }
  else {
    __slimbus_dbg("qcom_ngd_set_suspend","%s: Failed to suspend:%d\n","qcom_ngd_set_suspend",iVar1);
    iVar2 = *(int *)((long)param_1 + 0x121c);
    if (2 < iVar2) {
      ipc_log_string(param_1[0x245],"%s: Failed to suspend:%d\n","qcom_ngd_set_suspend",iVar1);
      iVar2 = *(int *)((long)param_1 + 0x121c);
    }
    if (iVar2 == 0) {
      ipc_log_string(param_1[0x246],"%s: Failed to suspend:%d\n","qcom_ngd_set_suspend",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_slim_ngd_enable_stream @ 00101c64 size=1956
// signature: undefined qcom_slim_ngd_enable_stream(void)
// callers: []
//------------------------------------------------------------

int qcom_slim_ngd_enable_stream(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  char *pcVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  undefined4 *puVar19;
  undefined1 local_f0 [2];
  undefined1 uStack_ee;
  byte bStack_ea;
  undefined5 uStack_ed;
  undefined1 uStack_e9;
  undefined8 *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 *local_d0;
  byte *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  byte local_90 [40];
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  lVar16 = *(long *)(param_1 + 8);
  local_c8 = (byte *)0x0;
  uStack_c0 = 0;
  local_d8 = 0;
  local_d0 = (undefined8 *)0x0;
  lVar15 = *(long *)(lVar16 + 0x398);
  local_90[0x18] = 0;
  local_90[0x19] = 0;
  local_90[0x1a] = 0;
  local_90[0x1b] = 0;
  local_90[0x1c] = 0;
  local_90[0x1d] = 0;
  local_90[0x1e] = 0;
  local_90[0x1f] = 0;
  local_90[0x20] = 0;
  local_90[0x21] = 0;
  local_90[0x22] = 0;
  local_90[0x23] = 0;
  local_90[0x24] = 0;
  local_90[0x25] = 0;
  local_90[0x26] = 0;
  local_90[0x27] = 0;
  local_90[8] = 0;
  local_90[9] = 0;
  local_90[10] = 0;
  local_90[0xb] = 0;
  local_90[0xc] = 0;
  local_90[0xd] = 0;
  local_90[0xe] = 0;
  local_90[0xf] = 0;
  local_90[0x10] = 0;
  local_90[0x11] = 0;
  local_90[0x12] = 0;
  local_90[0x13] = 0;
  local_90[0x14] = 0;
  local_90[0x15] = 0;
  local_90[0x16] = 0;
  local_90[0x17] = 0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[6] = 0;
  local_90[7] = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_e8 = (undefined8 *)0x0;
  uStack_e0 = 0;
  _local_f0 = 0;
  __slimbus_dbg("qcom_slim_ngd_enable_stream","%s start %d\n","qcom_slim_ngd_enable_stream",1);
  iVar7 = *(int *)(lVar15 + 0x121c);
  if (2 < iVar7) {
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s start %d\n","qcom_slim_ngd_enable_stream",1)
    ;
    iVar7 = *(int *)(lVar15 + 0x121c);
  }
  if (iVar7 == 0) {
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s start %d\n","qcom_slim_ngd_enable_stream",1)
    ;
  }
  uVar8 = _local_f0;
  local_e8 = &local_d8;
  _local_f0 = (uint)_local_f0;
  local_f0 = (undefined1  [2])CONCAT11(2,(char)uVar8);
  uVar8 = _local_f0;
  _local_f0 = CONCAT17(0xff,_local_f0);
  local_d0 = &local_b8;
  _local_f0 = (uint)uVar8;
  _local_f0 = (uint6)_local_f0;
  local_d8._0_3_ = (uint3)(ushort)local_d8;
  local_c8 = local_90;
  if (*(int *)(param_1 + 0x24) < 1) {
    pcVar9 = (char *)((ulong)&local_d8 | 2);
  }
  else {
    lVar17 = 0;
    do {
      lVar18 = *(long *)(param_1 + 0x28);
      bVar11 = *(byte *)((long)local_e8 + 2);
      if (bVar11 == 0) {
        uVar3 = *(undefined1 *)(lVar16 + 0x3a4);
        *(undefined1 *)((long)local_e8 + 2) = 1;
        local_90[0] = uVar3;
        __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: wbuf[0] = 0x%x\n",
                      "qcom_slim_ngd_enable_stream",*(undefined1 *)(lVar16 + 0x3a4));
        iVar7 = *(int *)(lVar15 + 0x121c);
        if (3 < iVar7) {
          ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: wbuf[0] = 0x%x\n",
                         "qcom_slim_ngd_enable_stream",*(undefined1 *)(lVar16 + 0x3a4));
          iVar7 = *(int *)(lVar15 + 0x121c);
        }
        if (iVar7 == 0) {
          ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s: wbuf[0] = 0x%x\n",
                         "qcom_slim_ngd_enable_stream",*(undefined1 *)(lVar16 + 0x3a4));
        }
        if (0x27 < (ulong)*(byte *)((long)local_e8 + 2)) goto LAB_00102400;
        uVar1 = *(uint *)(param_1 + 0x18);
        lVar14 = *(long *)(param_1 + 8);
        local_90[*(byte *)((long)local_e8 + 2)] =
             (byte)(*(int *)(lVar18 + lVar17 * 0x24 + 0x1c) << 6) |
             (byte)(*(uint *)(param_1 + 0x1c) >> 2);
        uVar12 = *(uint *)(param_1 + 0x20);
        if (*(int *)(*(long *)(*(long *)(lVar14 + 0x398) + 0x48) + 0x39c) * uVar12 < uVar1) {
          uVar12 = uVar12 + 1;
          *(uint *)(param_1 + 0x20) = uVar12;
        }
        iVar7 = 0;
        uVar1 = uVar12;
        do {
          while (uVar5 = uVar1, (uVar12 & 1) == 0) {
            iVar7 = iVar7 + 1;
            uVar1 = (int)uVar5 >> 1;
            uVar12 = uVar5 >> 1;
          }
          uVar12 = uVar5 + 1;
          uVar1 = uVar12;
        } while (3 < (int)uVar5);
        if (uVar5 == 1) {
          if (iVar7 < 10) {
LAB_00101ee0:
            *(char *)((long)local_e8 + 2) = *(char *)((long)local_e8 + 2) + '\x01';
            uVar2 = *(undefined4 *)(param_1 + 0x14);
            bVar11 = *(byte *)((long)local_e8 + 2);
            *(byte *)((long)local_e8 + 2) = bVar11 + 1;
            if (0x27 < (ulong)bVar11) goto LAB_00102400;
            iVar10 = *(int *)(param_1 + 0x14);
            local_90[bVar11] = (byte)uVar2 | (byte)(iVar7 << 4);
            bVar4 = *(byte *)((long)local_e8 + 2);
            bVar11 = (byte)*(undefined4 *)(lVar18 + lVar17 * 0x24 + 0x10);
            *(byte *)((long)local_e8 + 2) = bVar4 + 1;
            if (iVar10 == 0) {
              if (0x27 < bVar4) goto LAB_00102400;
              bVar11 = bVar11 | 0x80;
            }
            else if (0x27 < bVar4) goto LAB_00102400;
            local_90[bVar4] = bVar11;
            iVar7 = slim_alloc_txn_tid(lVar15,local_f0);
            if (iVar7 == 0) {
              bVar11 = *(byte *)((long)local_e8 + 2);
              *(byte *)((long)local_e8 + 2) = bVar11 + 1;
              if (0x27 < (ulong)bVar11) goto LAB_00102400;
              local_90[bVar11] = bStack_ea;
              bVar11 = *(byte *)((long)local_e8 + 2);
              goto LAB_00101f80;
            }
            __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: Fail to allocate TID\n",
                          "qcom_slim_ngd_enable_stream");
            if (*(int *)(lVar15 + 0x121c) < 1) {
              if (*(int *)(lVar15 + 0x121c) == 0) goto LAB_00102154;
            }
            else {
              _printk(&DAT_00108035,"qcom_slim_ngd_enable_stream");
              ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: Fail to allocate TID\n",
                             "qcom_slim_ngd_enable_stream");
              uVar2 = *(undefined4 *)(lVar15 + 0x121c);
              *(undefined4 *)(lVar15 + 0x121c) = 0;
              *(undefined4 *)(lVar15 + 0x1218) = uVar2;
LAB_00102154:
              ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s: Fail to allocate TID\n",
                             "qcom_slim_ngd_enable_stream");
            }
            iVar7 = -6;
            goto LAB_0010233c;
          }
        }
        else if (iVar7 < 9) {
          uVar13 = (ulong)*(byte *)((long)local_e8 + 2);
          if (0x27 < uVar13) goto LAB_00102400;
          local_90[uVar13] = local_90[uVar13] | 0x20;
          goto LAB_00101ee0;
        }
        __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: error calculating coef %d\n",
                      "qcom_slim_ngd_enable_stream",0xfffffffb);
        if (*(int *)(lVar15 + 0x121c) < 1) {
          if (*(int *)(lVar15 + 0x121c) != 0) {
            iVar7 = -5;
            goto LAB_0010233c;
          }
        }
        else {
          _printk(&DAT_00108b70,"qcom_slim_ngd_enable_stream",0xfffffffb);
          ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: error calculating coef %d\n",
                         "qcom_slim_ngd_enable_stream",0xfffffffb);
          uVar2 = *(undefined4 *)(lVar15 + 0x121c);
          *(undefined4 *)(lVar15 + 0x121c) = 0;
          *(undefined4 *)(lVar15 + 0x1218) = uVar2;
        }
        uVar8 = *(undefined8 *)(lVar15 + 0x1230);
        pcVar9 = "%s: error calculating coef %d\n";
        iVar7 = -5;
        goto LAB_00102338;
      }
LAB_00101f80:
      puVar19 = (undefined4 *)(lVar18 + lVar17 * 0x24 + 0xc);
      uVar2 = *puVar19;
      *(byte *)((long)local_e8 + 2) = bVar11 + 1;
      if (0x27 < bVar11) {
LAB_00102400:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102404);
        (*pcVar6)();
      }
      local_90[bVar11] = (byte)uVar2;
      __slimbus_dbg("qcom_slim_ngd_enable_stream","%s Channel ID %d\n","qcom_slim_ngd_enable_stream"
                    ,*puVar19);
      iVar7 = *(int *)(lVar15 + 0x121c);
      if (2 < iVar7) {
        ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s Channel ID %d\n",
                       "qcom_slim_ngd_enable_stream",*puVar19);
        iVar7 = *(int *)(lVar15 + 0x121c);
      }
      if (iVar7 == 0) {
        ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s Channel ID %d\n",
                       "qcom_slim_ngd_enable_stream",*puVar19);
      }
      lVar17 = lVar17 + 1;
    } while (lVar17 < *(int *)(param_1 + 0x24));
    pcVar9 = (char *)((long)local_e8 + 2);
  }
  _local_f0 = CONCAT12(0x21,local_f0);
  _local_f0 = CONCAT71(stack0xffffffffffffff11,*pcVar9 + '\x04');
  iVar7 = qcom_slim_ngd_xfer_msg_sync(lVar15,local_f0);
  if (iVar7 != 0) {
    slim_free_txn_tid(lVar15,local_f0);
    __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: TX ACT_CHAN timed out:MC:0x%x,mt:0x%x",
                  "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
    if (*(int *)(lVar15 + 0x121c) < 1) {
      if (*(int *)(lVar15 + 0x121c) != 0) goto LAB_0010233c;
    }
    else {
      _printk(&DAT_00107ba1,"qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
      ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: TX ACT_CHAN timed out:MC:0x%x,mt:0x%x",
                     "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
      uVar2 = *(undefined4 *)(lVar15 + 0x121c);
      *(undefined4 *)(lVar15 + 0x121c) = 0;
      *(undefined4 *)(lVar15 + 0x1218) = uVar2;
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s: TX ACT_CHAN timed out:MC:0x%x,mt:0x%x",
                   "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
    goto LAB_0010233c;
  }
  _local_f0 = CONCAT12(0x24,local_f0);
  *(undefined1 *)((long)local_e8 + 2) = 2;
  local_90[1] = *(undefined1 *)(lVar16 + 0x3a4);
  _local_f0 = CONCAT71(stack0xffffffffffffff11,*(char *)((long)local_e8 + 2) + '\x04');
  iVar7 = slim_alloc_txn_tid(lVar15,local_f0);
  if (iVar7 != 0) {
    __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: Fail to allocate TID\n",
                  "qcom_slim_ngd_enable_stream");
    if (*(int *)(lVar15 + 0x121c) < 1) {
      if (*(int *)(lVar15 + 0x121c) != 0) goto LAB_0010233c;
    }
    else {
      _printk(&DAT_00108035,"qcom_slim_ngd_enable_stream");
      ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: Fail to allocate TID\n",
                     "qcom_slim_ngd_enable_stream");
      uVar2 = *(undefined4 *)(lVar15 + 0x121c);
      *(undefined4 *)(lVar15 + 0x121c) = 0;
      *(undefined4 *)(lVar15 + 0x1218) = uVar2;
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s: Fail to allocate TID\n",
                   "qcom_slim_ngd_enable_stream");
    goto LAB_0010233c;
  }
  local_90[0] = bStack_ea;
  iVar7 = qcom_slim_ngd_xfer_msg_sync(lVar15,local_f0);
  if (iVar7 != 0) {
    slim_free_txn_tid(lVar15,local_f0);
    __slimbus_dbg("qcom_slim_ngd_enable_stream","%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x",
                  "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
    if (*(int *)(lVar15 + 0x121c) < 1) {
      if (*(int *)(lVar15 + 0x121c) != 0) goto LAB_001021ec;
    }
    else {
      _printk(&DAT_00108369,"qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
      ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x",
                     "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
      uVar2 = *(undefined4 *)(lVar15 + 0x121c);
      *(undefined4 *)(lVar15 + 0x121c) = 0;
      *(undefined4 *)(lVar15 + 0x1218) = uVar2;
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1230),"%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x",
                   "qcom_slim_ngd_enable_stream",uStack_ee,local_f0[1]);
  }
LAB_001021ec:
  __slimbus_dbg("qcom_slim_ngd_enable_stream","%s End ret : %d\n","qcom_slim_ngd_enable_stream",
                iVar7);
  iVar10 = *(int *)(lVar15 + 0x121c);
  if (2 < iVar10) {
    ipc_log_string(*(undefined8 *)(lVar15 + 0x1228),"%s End ret : %d\n",
                   "qcom_slim_ngd_enable_stream",iVar7);
    iVar10 = *(int *)(lVar15 + 0x121c);
  }
  if (iVar10 == 0) {
    uVar8 = *(undefined8 *)(lVar15 + 0x1230);
    pcVar9 = "%s End ret : %d\n";
LAB_00102338:
    ipc_log_string(uVar8,pcVar9,"qcom_slim_ngd_enable_stream",iVar7);
  }
LAB_0010233c:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// qcom_slim_ngd_disable_stream @ 0010240c size=1556
// signature: undefined qcom_slim_ngd_disable_stream(void)
// callers: []
//------------------------------------------------------------

int qcom_slim_ngd_disable_stream(long param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined1 local_f0 [2];
  undefined1 uStack_ee;
  undefined1 uStack_ea;
  undefined5 uStack_ed;
  undefined1 uStack_e9;
  undefined8 *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 *local_d0;
  undefined8 *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar10 = *(long *)(param_1 + 8);
  local_c8 = (undefined8 *)0x0;
  uStack_c0 = 0;
  local_d8 = 0;
  local_d0 = (undefined8 *)0x0;
  lVar9 = *(long *)(lVar10 + 0x398);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_e8 = (undefined8 *)0x0;
  uStack_e0 = 0;
  _local_f0 = 0;
  __slimbus_dbg("qcom_slim_ngd_disable_stream","%s start %d\n","qcom_slim_ngd_disable_stream",1);
  iVar5 = *(int *)(lVar9 + 0x121c);
  if (2 < iVar5) {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"%s start %d\n","qcom_slim_ngd_disable_stream",1)
    ;
    iVar5 = *(int *)(lVar9 + 0x121c);
  }
  if (iVar5 == 0) {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),"%s start %d\n","qcom_slim_ngd_disable_stream",1)
    ;
  }
  uVar6 = _local_f0;
  local_e8 = &local_d8;
  _local_f0 = (uint)_local_f0;
  local_f0 = (undefined1  [2])CONCAT11(2,(char)uVar6);
  uVar6 = _local_f0;
  _local_f0 = CONCAT17(0xff,_local_f0);
  local_d0 = &local_b8;
  _local_f0 = (uint)uVar6;
  _local_f0 = (uint6)_local_f0;
  local_d8._0_3_ = (uint3)(ushort)local_d8;
  local_c8 = &local_90;
  if (*(int *)(param_1 + 0x24) < 1) {
    pcVar7 = (char *)((ulong)&local_d8 | 2);
  }
  else {
    lVar11 = 0;
    lVar12 = 0xc;
    do {
      lVar13 = *(long *)(param_1 + 0x28);
      bVar2 = *(byte *)((long)local_e8 + 2);
      if (bVar2 == 0) {
        uVar3 = *(undefined1 *)(lVar10 + 0x3a4);
        *(undefined1 *)((long)local_e8 + 2) = 1;
        local_90 = CONCAT71(local_90._1_7_,uVar3) & 0xffffffffffffff1f | 0x80;
        __slimbus_dbg("qcom_slim_ngd_disable_stream","%s: wbuf[0] = 0x%x\n",
                      "qcom_slim_ngd_disable_stream",*(undefined1 *)(lVar10 + 0x3a4));
        iVar5 = *(int *)(lVar9 + 0x121c);
        if (3 < iVar5) {
          ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"%s: wbuf[0] = 0x%x\n",
                         "qcom_slim_ngd_disable_stream",*(undefined1 *)(lVar10 + 0x3a4));
          iVar5 = *(int *)(lVar9 + 0x121c);
        }
        if (iVar5 == 0) {
          ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),"%s: wbuf[0] = 0x%x\n",
                         "qcom_slim_ngd_disable_stream",*(undefined1 *)(lVar10 + 0x3a4));
        }
        iVar5 = slim_alloc_txn_tid(lVar9,local_f0);
        if (iVar5 != 0) {
          __slimbus_dbg("qcom_slim_ngd_disable_stream","Fail to allocate TID ret:%d\n",0xfffffffa);
          if (*(int *)(lVar9 + 0x121c) < 1) {
            if (*(int *)(lVar9 + 0x121c) != 0) {
              iVar5 = -6;
              goto LAB_00102988;
            }
          }
          else {
            _printk(&DAT_00107a2f,0xfffffffa);
            ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"Fail to allocate TID ret:%d\n",
                           0xfffffffa);
            uVar1 = *(undefined4 *)(lVar9 + 0x121c);
            *(undefined4 *)(lVar9 + 0x121c) = 0;
            *(undefined4 *)(lVar9 + 0x1218) = uVar1;
          }
          iVar5 = -6;
          ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),"Fail to allocate TID ret:%d\n",0xfffffffa)
          ;
          goto LAB_00102988;
        }
        bVar2 = *(byte *)((long)local_e8 + 2);
        *(byte *)((long)local_e8 + 2) = bVar2 + 1;
        if (0x27 < (ulong)bVar2) goto LAB_00102a18;
        *(undefined1 *)((long)&local_90 + (ulong)bVar2) = uStack_ea;
        bVar2 = *(byte *)((long)local_e8 + 2);
      }
      uVar1 = *(undefined4 *)(lVar13 + lVar12);
      *(byte *)((long)local_e8 + 2) = bVar2 + 1;
      if (0x27 < bVar2) {
LAB_00102a18:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102a1c);
        (*pcVar4)();
      }
      *(char *)((long)&local_90 + (ulong)bVar2) = (char)uVar1;
      __slimbus_dbg("qcom_slim_ngd_disable_stream","%s Channel ID %d\n",
                    "qcom_slim_ngd_disable_stream",*(undefined4 *)(lVar13 + lVar12));
      iVar5 = *(int *)(lVar9 + 0x121c);
      if (2 < iVar5) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"%s Channel ID %d\n",
                       "qcom_slim_ngd_disable_stream",*(undefined4 *)(lVar13 + lVar12));
        iVar5 = *(int *)(lVar9 + 0x121c);
      }
      if (iVar5 == 0) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),"%s Channel ID %d\n",
                       "qcom_slim_ngd_disable_stream",*(undefined4 *)(lVar13 + lVar12));
      }
      lVar11 = lVar11 + 1;
      lVar12 = lVar12 + 0x24;
    } while (lVar11 < *(int *)(param_1 + 0x24));
    pcVar7 = (char *)((long)local_e8 + 2);
  }
  _local_f0 = CONCAT12(0x23,local_f0);
  _local_f0 = CONCAT71(stack0xffffffffffffff11,*pcVar7 + '\x04');
  iVar5 = qcom_slim_ngd_xfer_msg_sync(lVar9,local_f0);
  if (iVar5 != 0) {
    slim_free_txn_tid(lVar9,local_f0);
    __slimbus_dbg("qcom_slim_ngd_disable_stream",
                  "%s: TX CHAN_CTRL timed out:MC:0x%x,mt:0x%x ret:%d\n",
                  "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
    if (*(int *)(lVar9 + 0x121c) < 1) {
      if (*(int *)(lVar9 + 0x121c) != 0) goto LAB_00102988;
    }
    else {
      _printk(&DAT_00107bcd,"qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
      ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),
                     "%s: TX CHAN_CTRL timed out:MC:0x%x,mt:0x%x ret:%d\n",
                     "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
      uVar1 = *(undefined4 *)(lVar9 + 0x121c);
      *(undefined4 *)(lVar9 + 0x121c) = 0;
      *(undefined4 *)(lVar9 + 0x1218) = uVar1;
    }
    ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),
                   "%s: TX CHAN_CTRL timed out:MC:0x%x,mt:0x%x ret:%d\n",
                   "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
    goto LAB_00102988;
  }
  _local_f0 = CONCAT12(0x24,local_f0);
  *(undefined1 *)((long)local_e8 + 2) = 2;
  local_90._0_2_ = CONCAT11(*(undefined1 *)(lVar10 + 0x3a4),(undefined1)local_90);
  _local_f0 = CONCAT71(stack0xffffffffffffff11,*(char *)((long)local_e8 + 2) + '\x04');
  iVar5 = slim_alloc_txn_tid(lVar9,local_f0);
  if (iVar5 == 0) {
    local_90 = CONCAT71(local_90._1_7_,uStack_ea);
    iVar5 = qcom_slim_ngd_xfer_msg_sync(lVar9,local_f0);
    if (iVar5 != 0) {
      slim_free_txn_tid(lVar9,local_f0);
      __slimbus_dbg("qcom_slim_ngd_disable_stream",
                    "%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x ret:%d\n",
                    "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
      if (*(int *)(lVar9 + 0x121c) < 1) {
        if (*(int *)(lVar9 + 0x121c) != 0) goto LAB_0010283c;
      }
      else {
        _printk(&DAT_00107a4e,"qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
        ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),
                       "%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x ret:%d\n",
                       "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
        uVar1 = *(undefined4 *)(lVar9 + 0x121c);
        *(undefined4 *)(lVar9 + 0x121c) = 0;
        *(undefined4 *)(lVar9 + 0x1218) = uVar1;
      }
      ipc_log_string(*(undefined8 *)(lVar9 + 0x1230),
                     "%s: TX RECONFIG timed out:MC:0x%x,mt:0x%x ret:%d\n",
                     "qcom_slim_ngd_disable_stream",uStack_ee,local_f0[1],iVar5);
    }
LAB_0010283c:
    __slimbus_dbg("qcom_slim_ngd_disable_stream","%s End ret %d\n","qcom_slim_ngd_disable_stream",
                  iVar5);
    iVar8 = *(int *)(lVar9 + 0x121c);
    if (2 < iVar8) {
      ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"%s End ret %d\n",
                     "qcom_slim_ngd_disable_stream",iVar5);
      iVar8 = *(int *)(lVar9 + 0x121c);
    }
    if (iVar8 != 0) goto LAB_00102988;
    uVar6 = *(undefined8 *)(lVar9 + 0x1230);
    pcVar7 = "%s End ret %d\n";
  }
  else {
    __slimbus_dbg("qcom_slim_ngd_disable_stream","%s: Fail to allocate TID ret:%d\n",
                  "qcom_slim_ngd_disable_stream",iVar5);
    if (*(int *)(lVar9 + 0x121c) < 1) {
      if (*(int *)(lVar9 + 0x121c) != 0) goto LAB_00102988;
    }
    else {
      _printk(&DAT_00107e03,"qcom_slim_ngd_disable_stream",iVar5);
      ipc_log_string(*(undefined8 *)(lVar9 + 0x1228),"%s: Fail to allocate TID ret:%d\n",
                     "qcom_slim_ngd_disable_stream",iVar5);
      uVar1 = *(undefined4 *)(lVar9 + 0x121c);
      *(undefined4 *)(lVar9 + 0x121c) = 0;
      *(undefined4 *)(lVar9 + 0x1218) = uVar1;
    }
    uVar6 = *(undefined8 *)(lVar9 + 0x1230);
    pcVar7 = "%s: Fail to allocate TID ret:%d\n";
  }
  ipc_log_string(uVar6,pcVar7,"qcom_slim_ngd_disable_stream",iVar5);
LAB_00102988:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qcom_slim_ngd_xfer_msg @ 00102a24 size=2940
// signature: undefined qcom_slim_ngd_xfer_msg(void)
// callers: [qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_master_worker]
//------------------------------------------------------------

int qcom_slim_ngd_xfer_msg(long *param_1,byte *param_2)

{
  long lVar1;
  undefined4 uVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  uint uVar16;
  ulong uVar17;
  long lVar18;
  uint *puVar19;
  uint uVar20;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  uVar20 = (uint)param_2[7];
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  lVar15 = *(long *)(*param_1 + 0x98);
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  *(undefined4 *)(lVar15 + 0x1410) = 0;
  *(undefined4 *)(lVar15 + 0x1450) = 0;
  if ((param_2[1] == 0) && ((param_2[2] & 0xe0) == 0x40)) {
LAB_00102a9c:
    iVar5 = 0;
    goto LAB_00102f64;
  }
  if (param_2[3] == 1) {
    __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: proto not supported\n","qcom_slim_ngd_xfer_msg");
    if (*(int *)(lVar15 + 0x15bc) < 1) {
      if (*(int *)(lVar15 + 0x15bc) != 0) {
        iVar5 = -0x5d;
        goto LAB_00102f64;
      }
    }
    else {
      _printk(&DAT_001088ab,"qcom_slim_ngd_xfer_msg");
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"%s: proto not supported\n",
                     "qcom_slim_ngd_xfer_msg");
      uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
      *(undefined4 *)(lVar15 + 0x15bc) = 0;
      *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"%s: proto not supported\n",
                   "qcom_slim_ngd_xfer_msg");
    iVar5 = -0x5d;
    goto LAB_00102f64;
  }
  if ((0x28 < *(byte *)(*(long *)(param_2 + 8) + 2)) || (0x28 < *param_2)) {
    __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: msg exceeds HW limit\n","qcom_slim_ngd_xfer_msg");
    if (*(int *)(lVar15 + 0x15bc) < 1) {
      if (*(int *)(lVar15 + 0x15bc) != 0) {
LAB_00102b24:
        iVar5 = -0x16;
        goto LAB_00102f64;
      }
    }
    else {
      _printk(&DAT_00107702,"qcom_slim_ngd_xfer_msg");
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"%s: msg exceeds HW limit\n",
                     "qcom_slim_ngd_xfer_msg");
      uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
      *(undefined4 *)(lVar15 + 0x15bc) = 0;
      *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"%s: msg exceeds HW limit\n",
                   "qcom_slim_ngd_xfer_msg");
    iVar5 = -0x16;
    goto LAB_00102f64;
  }
  lVar1 = lVar15 + 0x1478;
  iVar5 = mutex_trylock(lVar1);
  if (iVar5 != 0) {
    bVar11 = param_2[2];
    if (((bVar11 == 1) && (param_2[1] == 6)) || (*(int *)(lVar15 + 0x1560) != 3)) {
LAB_00102d10:
      lVar13 = lVar15 + 0x1470;
      uVar6 = _raw_spin_lock_irqsave(lVar13);
      uVar12 = *(uint *)(lVar15 + 0x1588);
      if (((int)(uVar12 + 1) % 0x1e == *(int *)(lVar15 + 0x158c)) ||
         (lVar14 = *(long *)(lVar15 + 0x1580), lVar14 == 0)) {
        _raw_spin_unlock_irqrestore(lVar13,uVar6);
      }
      else {
        if (0x1e < uVar12) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1035a0);
          (*pcVar4)();
        }
        lVar18 = lVar15 + (ulong)uVar12 * 0x30;
        *(long *)(lVar18 + 0xdb8) = lVar15 + 0x1450;
        iVar5 = *(int *)(lVar15 + 0x1588);
        *(ulong *)(lVar18 + 0xdd0) = lVar14 + (ulong)(uVar12 * 0x28);
        *(int *)(lVar15 + 0x1588) = (iVar5 + 1) % 0x1e;
        _raw_spin_unlock_irqrestore(lVar13,uVar6);
        puVar19 = *(uint **)(lVar18 + 0xdd0);
        if (puVar19 != (uint *)0x0) {
          mutex_unlock(lVar1);
          uVar6 = local_90;
          if (param_2[1] == 0) {
            bVar3 = false;
            if ((param_2[2] < 0x15) &&
               (uVar12 = (uint)param_2[2], (1 << (ulong)(uVar12 & 0x1f) & 0x130000U) != 0)) {
              param_2[1] = 2;
              if (uVar12 == 0x10) {
                bVar11 = 0x2c;
LAB_00103278:
                param_2[2] = bVar11;
                uVar17 = 3;
                local_90._0_2_ =
                     CONCAT11(**(undefined1 **)(*(long *)(param_2 + 8) + 0x10),param_2[7]);
                local_90._3_5_ = SUB85(uVar6,3);
                local_90._0_3_ =
                     CONCAT12((*(undefined1 **)(*(long *)(param_2 + 8) + 0x10))[1],
                              (undefined2)local_90);
              }
              else {
                if (uVar12 != 0x14) {
                  if (uVar12 != 0x11) goto LAB_00102b24;
                  bVar11 = 0x2d;
                  goto LAB_00103278;
                }
                uVar17 = 2;
                param_2[2] = 0x2e;
                local_90._0_2_ =
                     CONCAT11(**(undefined1 **)(*(long *)(param_2 + 8) + 0x10),param_2[7]);
              }
              *(long *)(param_2 + 0x10) = lVar15 + 0x1410;
              iVar5 = slim_alloc_txn_tid(param_1,param_2);
              if (iVar5 != 0) {
                __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: Unable to allocate TID\n",
                              "qcom_slim_ngd_xfer_msg");
                if (*(int *)(lVar15 + 0x15bc) < 1) {
                  if (*(int *)(lVar15 + 0x15bc) != 0) goto LAB_00102f64;
                }
                else {
                  _printk(&DAT_00108ca6,"qcom_slim_ngd_xfer_msg");
                  ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"%s: Unable to allocate TID\n",
                                 "qcom_slim_ngd_xfer_msg");
                  uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
                  *(undefined4 *)(lVar15 + 0x15bc) = 0;
                  *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
                }
                ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"%s: Unable to allocate TID\n",
                               "qcom_slim_ngd_xfer_msg");
                goto LAB_00102f64;
              }
              lVar13 = *(long *)(param_2 + 8);
              uVar20 = 0xff;
              bVar3 = true;
              *(byte *)((ulong)&local_90 | uVar17) = param_2[6];
              *(char *)(lVar13 + 2) = (char)uVar17 + '\x01';
              *(undefined8 **)(*(long *)(param_2 + 8) + 0x10) = &local_90;
              *(undefined8 **)(*(long *)(param_2 + 8) + 8) = &local_b8;
              *param_2 = *(char *)(*(long *)(param_2 + 8) + 2) + 4;
            }
          }
          else {
            bVar3 = false;
          }
          *param_2 = *param_2 - 1;
          *puVar19 = 0;
          bVar11 = param_2[3];
          uVar20 = (uint)*param_2 | (uint)param_2[1] << 5 | (uint)param_2[2] << 8 | uVar20 << 0x10;
          if (bVar11 != 0) {
            uVar20 = uVar20 | 0x8000;
          }
          *puVar19 = uVar20;
          bVar10 = param_2[1];
          lVar13 = 2;
          if (bVar11 == 0) {
            lVar13 = 3;
          }
          pbVar8 = (byte *)((long)puVar19 + lVar13);
          pbVar7 = pbVar8;
          if ((param_2[2] - 0x20 & 0xbe) == 0 && bVar10 == 0) {
            pbVar7 = pbVar8 + 1;
            *pbVar8 = param_2[6];
            bVar10 = param_2[1];
          }
          pbVar8 = pbVar7;
          if ((bVar10 == 0) && ((param_2[2] - 0x20 < 10 || (param_2[2] - 0x60 < 9)))) {
            pbVar8 = pbVar7 + 2;
            *pbVar7 = param_2[4];
            pbVar7[1] = param_2[5];
          }
          lVar13 = *(long *)(param_2 + 8);
          if ((lVar13 != 0) && (*(long *)(lVar13 + 0x10) != 0)) {
            if (*(char *)(lVar15 + 0x15b4) == '\0') {
              memcpy(pbVar8,*(void **)(*(long *)(param_2 + 8) + 0x10),(ulong)*(byte *)(lVar13 + 2));
            }
            else {
              __memcpy_toio();
            }
          }
          iVar5 = mutex_trylock(lVar1);
          if (iVar5 != 0) {
            iVar5 = qcom_slim_ngd_tx_msg_post(lVar15,puVar19,*param_2);
            if (iVar5 != 0) {
              mutex_unlock(lVar1);
              param_2[0x10] = 0;
              param_2[0x11] = 0;
              param_2[0x12] = 0;
              param_2[0x13] = 0;
              param_2[0x14] = 0;
              param_2[0x15] = 0;
              param_2[0x16] = 0;
              param_2[0x17] = 0;
              goto LAB_00102f64;
            }
            iVar5 = wait_for_completion_timeout(lVar15 + 0x1450,500);
            if (iVar5 != 0) {
              if ((!bVar3) ||
                 (iVar5 = wait_for_completion_timeout(lVar15 + 0x1410,0xfa), iVar5 != 0)) {
                mutex_unlock(lVar1);
                goto LAB_00102a9c;
              }
              __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: TX usr_msg timed out:MC:0x%x,mt:0x%x",
                            "qcom_slim_ngd_xfer_msg",param_2[2],param_2[1]);
              if (*(int *)(lVar15 + 0x15bc) < 1) {
                if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_00103414;
              }
              else {
                _printk(&DAT_00107673,"qcom_slim_ngd_xfer_msg",param_2[2],param_2[1]);
                ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                               "%s: TX usr_msg timed out:MC:0x%x,mt:0x%x","qcom_slim_ngd_xfer_msg",
                               param_2[2],param_2[1]);
                uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
                *(undefined4 *)(lVar15 + 0x15bc) = 0;
                *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_00103414:
                ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),
                               "%s: TX usr_msg timed out:MC:0x%x,mt:0x%x","qcom_slim_ngd_xfer_msg",
                               param_2[2],param_2[1]);
              }
              *(undefined1 *)(lVar15 + 0x15dd) = 1;
              param_2[0x10] = 0;
              param_2[0x11] = 0;
              param_2[0x12] = 0;
              param_2[0x13] = 0;
              param_2[0x14] = 0;
              param_2[0x15] = 0;
              param_2[0x16] = 0;
              param_2[0x17] = 0;
              mutex_unlock(lVar1);
              iVar5 = -0x6e;
              goto LAB_00102f64;
            }
            __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: TX timed out:MC:0x%x,mt:0x%x",param_2[2],
                          "qcom_slim_ngd_xfer_msg",param_2[1]);
            if (*(int *)(lVar15 + 0x15bc) < 1) {
              if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_001033a8;
            }
            else {
              _printk(&DAT_001088c6,param_2[2],"qcom_slim_ngd_xfer_msg",param_2[1]);
              ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"%s: TX timed out:MC:0x%x,mt:0x%x",
                             param_2[2],"qcom_slim_ngd_xfer_msg",param_2[1]);
              uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
              *(undefined4 *)(lVar15 + 0x15bc) = 0;
              *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_001033a8:
              ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"%s: TX timed out:MC:0x%x,mt:0x%x",
                             param_2[2],"qcom_slim_ngd_xfer_msg",param_2[1]);
            }
            mutex_unlock(lVar1);
            iVar5 = -0x6e;
            *(undefined1 *)(lVar15 + 0x15dd) = 1;
            param_2[0x10] = 0;
            param_2[0x11] = 0;
            param_2[0x12] = 0;
            param_2[0x13] = 0;
            param_2[0x14] = 0;
            param_2[0x15] = 0;
            param_2[0x16] = 0;
            param_2[0x17] = 0;
            goto LAB_00102f64;
          }
          __slimbus_dbg("qcom_slim_ngd_xfer_msg",
                        "%s: ngd going down due SSR/PDR, skipping tx msg post\n",
                        "qcom_slim_ngd_xfer_msg");
          if (*(int *)(lVar15 + 0x15bc) < 1) {
            if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_00103220;
          }
          else {
            _printk(&DAT_00108133,"qcom_slim_ngd_xfer_msg");
            ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                           "%s: ngd going down due SSR/PDR, skipping tx msg post\n",
                           "qcom_slim_ngd_xfer_msg");
            uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
            *(undefined4 *)(lVar15 + 0x15bc) = 0;
            *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_00103220:
            ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),
                           "%s: ngd going down due SSR/PDR, skipping tx msg post\n",
                           "qcom_slim_ngd_xfer_msg");
          }
          iVar5 = -0xb;
          param_2[0x10] = 0;
          param_2[0x11] = 0;
          param_2[0x12] = 0;
          param_2[0x13] = 0;
          param_2[0x14] = 0;
          param_2[0x15] = 0;
          param_2[0x16] = 0;
          param_2[0x17] = 0;
          goto LAB_00102f64;
        }
      }
      __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: Message buffer unavailable\n",
                    "qcom_slim_ngd_xfer_msg");
      if (*(int *)(lVar15 + 0x15bc) < 1) {
        if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_00102ee8;
      }
      else {
        _printk(&DAT_00107d9d,"qcom_slim_ngd_xfer_msg");
        ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"%s: Message buffer unavailable\n",
                       "qcom_slim_ngd_xfer_msg");
        uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
        *(undefined4 *)(lVar15 + 0x15bc) = 0;
        *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_00102ee8:
        ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"%s: Message buffer unavailable\n",
                       "qcom_slim_ngd_xfer_msg");
      }
      mutex_unlock(lVar1);
      iVar5 = -0xc;
      goto LAB_00102f64;
    }
    __slimbus_dbg("check_hw_state","ADSP slimbus not up yet MC:0x%x,mt:0x%x\n",bVar11,param_2[1]);
    uVar12 = (uint)bVar11;
    uVar16 = (uint)bVar11;
    if (*(int *)(lVar15 + 0x15bc) < 3) {
      if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_00102bb4;
LAB_00102cb4:
      bVar10 = param_2[1];
      if (bVar10 == 0) goto LAB_00102bd4;
LAB_00102cbc:
      if (bVar10 != 2) goto LAB_00102cf0;
      if (((0x2e < uVar16) || ((1L << ((ulong)bVar11 & 0x3f) & 0x401800000000U) == 0)) &&
         (0xd < uVar12 - 0x20)) {
        bVar10 = 2;
        goto LAB_00102cf0;
      }
LAB_00103080:
      iVar5 = -0x79;
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),"ADSP slimbus not up yet MC:0x%x,mt:0x%x\n",
                     uVar12,param_2[1]);
      if (*(int *)(lVar15 + 0x15bc) != 0) goto LAB_00102cb4;
LAB_00102bb4:
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),"ADSP slimbus not up yet MC:0x%x,mt:0x%x\n",
                     uVar12,param_2[1]);
      bVar10 = param_2[1];
      if (bVar10 != 0) goto LAB_00102cbc;
LAB_00102bd4:
      iVar5 = -0x16;
      if (((uVar12 != 0x14) && (uVar16 != 0x24)) &&
         ((uVar16 != 0x58 && ((iVar5 = -0x79, 8 < uVar16 - 0x10 && ((uVar16 & 0xe0) != 0x40)))))) {
LAB_00102cf0:
        if (*(char *)(lVar15 + 0x15c1) == '\0') {
          __slimbus_dbg("check_hw_state","Not waiting for ADSP up MC:0x%x,mt:0x%x\n",uVar16,bVar10);
          iVar5 = *(int *)(lVar15 + 0x15bc);
          if (2 < iVar5) {
            ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                           "Not waiting for ADSP up MC:0x%x,mt:0x%x\n",uVar16,param_2[1]);
            iVar5 = *(int *)(lVar15 + 0x15bc);
          }
          if (iVar5 == 0) {
            pcVar9 = "Not waiting for ADSP up MC:0x%x,mt:0x%x\n";
LAB_00103070:
            ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),pcVar9,uVar16,param_2[1]);
          }
        }
        else {
          *(undefined4 *)(lVar15 + 0x1368) = 0;
          iVar5 = wait_for_completion_timeout(lVar15 + 0x1368,0xfa);
          if (iVar5 != 0) goto LAB_00102d10;
          __slimbus_dbg("check_hw_state","ADSP slimbus not up timeout MC:0x%x,mt:0x%x\n",uVar12,
                        param_2[1]);
          iVar5 = *(int *)(lVar15 + 0x15bc);
          if (1 < iVar5) {
            _printk(&DAT_0010796c,uVar12,param_2[1]);
            ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                           "ADSP slimbus not up timeout MC:0x%x,mt:0x%x\n",uVar16,param_2[1]);
            iVar5 = *(int *)(lVar15 + 0x15bc);
          }
          if (iVar5 == 0) {
            pcVar9 = "ADSP slimbus not up timeout MC:0x%x,mt:0x%x\n";
            goto LAB_00103070;
          }
        }
        goto LAB_00103080;
      }
    }
    __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: ADSP slimbus not up MC:0x%x,mt:0x%x ret:%d\n",
                  "qcom_slim_ngd_xfer_msg",param_2[2],param_2[1],iVar5);
    if (*(int *)(lVar15 + 0x15bc) < 1) {
      if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_001030b8;
    }
    else {
      _printk(&DAT_0010771e,"qcom_slim_ngd_xfer_msg",param_2[2],param_2[1],iVar5);
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                     "%s: ADSP slimbus not up MC:0x%x,mt:0x%x ret:%d\n","qcom_slim_ngd_xfer_msg",
                     param_2[2],param_2[1],iVar5);
      uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
      *(undefined4 *)(lVar15 + 0x15bc) = 0;
      *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_001030b8:
      ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),
                     "%s: ADSP slimbus not up MC:0x%x,mt:0x%x ret:%d\n","qcom_slim_ngd_xfer_msg",
                     param_2[2],param_2[1],iVar5);
    }
    mutex_unlock(lVar1);
    goto LAB_00102f64;
  }
  __slimbus_dbg("qcom_slim_ngd_xfer_msg","%s: ngd going down due SSR/PDR. skipping check hw state\n"
                ,"qcom_slim_ngd_xfer_msg");
  if (*(int *)(lVar15 + 0x15bc) < 1) {
    if (*(int *)(lVar15 + 0x15bc) == 0) goto LAB_00102c38;
  }
  else {
    _printk(&DAT_00108258,"qcom_slim_ngd_xfer_msg");
    ipc_log_string(*(undefined8 *)(lVar15 + 0x15c8),
                   "%s: ngd going down due SSR/PDR. skipping check hw state\n",
                   "qcom_slim_ngd_xfer_msg");
    uVar2 = *(undefined4 *)(lVar15 + 0x15bc);
    *(undefined4 *)(lVar15 + 0x15bc) = 0;
    *(undefined4 *)(lVar15 + 0x15b8) = uVar2;
LAB_00102c38:
    ipc_log_string(*(undefined8 *)(lVar15 + 0x15d0),
                   "%s: ngd going down due SSR/PDR. skipping check hw state\n",
                   "qcom_slim_ngd_xfer_msg");
  }
  iVar5 = -0xb;
LAB_00102f64:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// slim_pd_status @ 001035a4 size=36
// signature: undefined slim_pd_status(void)
// callers: []
//------------------------------------------------------------

void slim_pd_status(int param_1,undefined8 param_2,undefined8 param_3)

{
  qcom_slim_ngd_ssr_pdr_notify(param_3,(long)param_1);
  return;
}



//------------------------------------------------------------
// readl @ 001035c8 size=140
// signature: undefined readl(void)
// callers: [qcom_slim_ngd_interrupt]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x103620,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00103654 size=136
// signature: undefined writel(void)
// callers: [qcom_slim_ngd_interrupt]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10366c,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1036ac,uVar1);
  return;
}



//------------------------------------------------------------
// debug_mask_show @ 001036e0 size=60
// signature: undefined debug_mask_show(void)
// callers: []
//------------------------------------------------------------

long debug_mask_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,4,&DAT_001078d0,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x15bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// debug_mask_store @ 00103720 size=36
// signature: undefined debug_mask_store(void)
// callers: []
//------------------------------------------------------------

undefined8 debug_mask_store(long param_1,undefined8 param_2,byte *param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = 4;
  if (*param_3 < 0x35) {
    iVar1 = *param_3 - 0x30;
  }
  *(int *)(*(long *)(param_1 + 0x98) + 0x15bc) = iVar1;
  return param_4;
}



//------------------------------------------------------------
// qcom_slim_ngd_ssr_pdr_notify @ 00103744 size=1012
// signature: undefined qcom_slim_ngd_ssr_pdr_notify(void)
// callers: [qcom_slim_ngd_ssr_notify, slim_pd_status]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_slim_ngd_ssr_pdr_notify(long param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  
  __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM DSP SSR/PDR notify cb:0x%lx\n",param_2);
  if (*(int *)(param_1 + 0x15bc) < 3) {
    if (*(int *)(param_1 + 0x15bc) == 0) goto LAB_001037e0;
LAB_00103794:
    if (param_2 < 3) goto LAB_001037fc;
LAB_0010379c:
    if (param_2 == 3) {
      __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM SSR After Shutdown\n");
      iVar4 = *(int *)(param_1 + 0x15bc);
      if (2 < iVar4) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM SSR After Shutdown\n");
        iVar4 = *(int *)(param_1 + 0x15bc);
      }
      if (iVar4 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM SSR After Shutdown\n");
      }
      goto LAB_00103ad8;
    }
    if (param_2 == 0x1fffffff) {
LAB_001039fc:
      if (*(char *)(param_1 + 0x15b4) != '\0') {
        *(undefined8 *)(param_1 + 0x15a0) = *(undefined8 *)(param_1 + 0x15a8);
        **(ulong **)(param_1 + 0x1598) = (ulong)*(uint *)(param_1 + 0x15b0);
      }
      queue_work_on(0x20,_system_wq,param_1 + 0x13b8);
      __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM SSR up\n");
      iVar4 = *(int *)(param_1 + 0x15bc);
      if (2 < iVar4) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM SSR up\n");
        iVar4 = *(int *)(param_1 + 0x15bc);
      }
      if (iVar4 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM SSR up\n");
        return;
      }
      return;
    }
    if (param_2 != 0xfffffff) {
      return;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM DSP SSR/PDR notify cb:0x%lx\n",param_2);
    if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_00103794;
LAB_001037e0:
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM DSP SSR/PDR notify cb:0x%lx\n",param_2);
    if (2 < param_2) goto LAB_0010379c;
LAB_001037fc:
    if (param_2 == 1) goto LAB_001039fc;
    if (param_2 != 2) {
      return;
    }
  }
  __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM SSR Before Shutdown\n");
  iVar4 = *(int *)(param_1 + 0x15bc);
  if (2 < iVar4) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM SSR Before Shutdown\n");
    iVar4 = *(int *)(param_1 + 0x15bc);
  }
  if (iVar4 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM SSR Before Shutdown\n");
  }
  if (*(int *)(param_1 + 0x1560) != 3) {
    mutex_lock(param_1 + 0x14a8);
    mutex_lock(param_1 + 0x1478);
    *(undefined1 *)(param_1 + 0x15dd) = 0;
    *(undefined4 *)(param_1 + 0x1560) = 4;
    __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM SSR going down\n");
    iVar4 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar4) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM SSR going down\n");
      iVar4 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM SSR going down\n");
    }
    piVar1 = (int *)(*(long *)(param_1 + 0x3a0) + 0x1f8);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM %s: PM get_no_resume count:%d\n",
                  "qcom_slim_ngd_ssr_pdr_notify",*(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8)
                 );
    iVar4 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar4) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM %s: PM get_no_resume count:%d\n",
                     "qcom_slim_ngd_ssr_pdr_notify",
                     *(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8));
      iVar4 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM %s: PM get_no_resume count:%d\n",
                     "qcom_slim_ngd_ssr_pdr_notify",
                     *(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8));
    }
    device_for_each_child(*(undefined8 *)(param_1 + 0x3a0),0,qcom_slim_ngd_update_device_status);
    qcom_slim_ngd_exit_dma(param_1);
    *(undefined4 *)(param_1 + 0x1560) = 3;
    __slimbus_dbg("qcom_slim_ngd_ssr_pdr_notify","SLIM SSR down\n");
    iVar4 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar4) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM SSR down\n");
      iVar4 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM SSR down\n");
    }
    mutex_unlock(param_1 + 0x1478);
    mutex_unlock(param_1 + 0x14a8);
  }
  if (param_2 != 0xfffffff) {
    return;
  }
LAB_00103ad8:
  mutex_lock(param_1 + 0x14d8);
  qcom_slim_ngd_enable(param_1,0);
  mutex_unlock(param_1 + 0x14d8);
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_update_device_status @ 00103ca4 size=32
// signature: undefined qcom_slim_ngd_update_device_status(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_update_device_status(void)

{
  slim_report_absent();
  return 0;
}



//------------------------------------------------------------
// qcom_slim_ngd_exit_dma @ 00103cc4 size=436
// signature: undefined qcom_slim_ngd_exit_dma(void)
// callers: [qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_ssr_pdr_notify, qcom_slim_ngd_remove]
//------------------------------------------------------------

void qcom_slim_ngd_exit_dma(long param_1)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  long *plVar4;
  
  uVar3 = *(undefined8 *)(param_1 + 0x7e8);
  __slimbus_dbg("qcom_slim_ngd_exit_dma","SLIM: NGD exit dma\n");
  iVar1 = *(int *)(param_1 + 0x15bc);
  if (2 < iVar1) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM: NGD exit dma\n");
    iVar1 = *(int *)(param_1 + 0x15bc);
  }
  if (iVar1 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM: NGD exit dma\n");
  }
  plVar4 = *(long **)(param_1 + 0x7f8);
  if (plVar4 != (long *)0x0) {
    pcVar2 = *(code **)(*plVar4 + 0x148);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103d5c);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(plVar4);
      if ((iVar1 == 0) && (pcVar2 = *(code **)(*plVar4 + 0x150), pcVar2 != (code *)0x0)) {
        if (*(int *)(pcVar2 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103d8c);
          (*pcVar2)();
        }
        (*pcVar2)(plVar4);
      }
    }
    dma_release_channel(*(undefined8 *)(param_1 + 0x7f8));
  }
  plVar4 = *(long **)(param_1 + 0x800);
  if (plVar4 != (long *)0x0) {
    pcVar2 = *(code **)(*plVar4 + 0x148);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103dc8);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(plVar4);
      if ((iVar1 == 0) && (pcVar2 = *(code **)(*plVar4 + 0x150), pcVar2 != (code *)0x0)) {
        if (*(int *)(pcVar2 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103df8);
          (*pcVar2)();
        }
        (*pcVar2)(plVar4);
      }
    }
    dma_release_channel(*(undefined8 *)(param_1 + 0x800));
  }
  if (*(char *)(param_1 + 0x15b4) == '\0') {
    dma_free_attrs(uVar3,0x4b0,*(undefined8 *)(param_1 + 0x1578),*(undefined8 *)(param_1 + 0x1568),0
                  );
    dma_free_attrs(uVar3,0x4d8,*(undefined8 *)(param_1 + 0x1580),*(undefined8 *)(param_1 + 0x1570),0
                  );
    *(undefined8 *)(param_1 + 0x1580) = 0;
    *(undefined8 *)(param_1 + 0x1578) = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0x15a0) = *(undefined8 *)(param_1 + 0x15a8);
    **(ulong **)(param_1 + 0x1598) = (ulong)*(uint *)(param_1 + 0x15b0);
  }
  *(undefined8 *)(param_1 + 0x7f8) = 0;
  *(undefined8 *)(param_1 + 0x800) = 0;
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_enable @ 00103e78 size=1700
// signature: undefined qcom_slim_ngd_enable(void)
// callers: [qcom_slim_ngd_up_worker, qcom_slim_ngd_ssr_pdr_notify]
//------------------------------------------------------------

void qcom_slim_ngd_enable(long param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  int iVar7;
  undefined8 local_98;
  undefined4 local_90;
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
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if ((param_2 & 1) == 0) {
    mutex_lock(param_1 + 0x1508);
    if (*(long *)(param_1 + 0x7b8) != 0) {
      qmi_handle_release();
      devm_kfree(*(undefined8 *)(param_1 + 0x7e8),*(undefined8 *)(param_1 + 0x7b8));
      *(undefined8 *)(param_1 + 0x7b8) = 0;
    }
    mutex_unlock(param_1 + 0x1508);
    __slimbus_dbg("qcom_slim_ngd_enable","SLIM NGD Disable\n");
    iVar2 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM NGD Disable\n");
      iVar2 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar2 != 0) goto LAB_001041d4;
    uVar5 = *(undefined8 *)(param_1 + 0x15d0);
    pcVar6 = "SLIM NGD Disable\n";
  }
  else {
    local_90 = 0;
    local_98 = 0;
    if (*(long *)(param_1 + 0x7b8) == 0) {
      puVar3 = (undefined8 *)devm_kmalloc(*(undefined8 *)(param_1 + 0x7e8),0x148,0xdc0);
      if (puVar3 == (undefined8 *)0x0) {
        iVar2 = -0xc;
      }
      else {
        iVar2 = qmi_handle_init(puVar3,0xe,0,qcom_slim_qmi_msg_handlers);
        if (iVar2 < 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x7e8),"QMI client init failed: %d\n",iVar2);
        }
        else {
          iVar2 = kernel_connect(*puVar3,param_1 + 0x658,0xc,0);
          if (iVar2 < 0) {
            __slimbus_dbg("qcom_slim_qmi_init","Remote Service connect failed: %d\n",iVar2);
            if (*(int *)(param_1 + 0x15bc) < 1) {
              if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_00104480;
            }
            else {
              _printk(&DAT_0010844d,iVar2);
              ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"Remote Service connect failed: %d\n"
                             ,iVar2);
              uVar1 = *(undefined4 *)(param_1 + 0x15bc);
              *(undefined4 *)(param_1 + 0x15bc) = 0;
              *(undefined4 *)(param_1 + 0x15b8) = uVar1;
            }
            ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"Remote Service connect failed: %d\n",
                           iVar2);
          }
          else {
            local_98 = CONCAT35(local_98._5_3_,0x100000000);
            local_90 = 2;
            local_40[0] = 0;
            iVar2 = *(int *)(*(long *)(param_1 + 0x7e0) + 0x10);
            *(undefined8 **)(param_1 + 0x7b8) = puVar3;
            local_50 = 0;
            uStack_48 = 0;
            local_60 = 0;
            uStack_58 = 0;
            local_70 = 0;
            uStack_68 = 0;
            local_80 = 0;
            uStack_78 = 0;
            local_88 = 0;
            local_98 = CONCAT44(local_98._4_4_,iVar2 >> 1);
            iVar2 = qmi_txn_init(puVar3,&local_88,slimbus_select_inst_resp_msg_v01_ei,local_40);
            if (iVar2 < 0) {
              __slimbus_dbg("qcom_slim_qmi_send_select_inst_req","QMI TXN init fail: %d\n",iVar2);
              if (*(int *)(param_1 + 0x15bc) < 1) {
                if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_0010446c;
              }
              else {
                _printk(&DAT_0010881c,iVar2);
                ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI TXN init fail: %d\n",iVar2);
                uVar1 = *(undefined4 *)(param_1 + 0x15bc);
                *(undefined4 *)(param_1 + 0x15bc) = 0;
                *(undefined4 *)(param_1 + 0x15b8) = uVar1;
              }
              uVar5 = *(undefined8 *)(param_1 + 0x15d0);
              pcVar6 = "QMI TXN init fail: %d\n";
LAB_00104444:
              ipc_log_string(uVar5,pcVar6,iVar2);
            }
            else {
              iVar2 = qmi_send_request(*(undefined8 *)(param_1 + 0x7b8),0,&local_88,0x20,0xe,
                                       slimbus_select_inst_req_msg_v01_ei,&local_98);
              if (iVar2 < 0) {
                __slimbus_dbg("qcom_slim_qmi_send_select_inst_req","QMI send req fail %d\n",iVar2);
                if (*(int *)(param_1 + 0x15bc) < 1) {
                  if (*(int *)(param_1 + 0x15bc) == 0) goto LAB_00104414;
                }
                else {
                  _printk(&DAT_00108001,iVar2);
                  ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI send req fail %d\n",iVar2);
                  uVar1 = *(undefined4 *)(param_1 + 0x15bc);
                  *(undefined4 *)(param_1 + 0x15bc) = 0;
                  *(undefined4 *)(param_1 + 0x15b8) = uVar1;
LAB_00104414:
                  ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"QMI send req fail %d\n",iVar2);
                }
                qmi_txn_cancel(&local_88);
              }
              else {
                iVar2 = qmi_txn_wait(&local_88,1000);
                if (iVar2 < 0) {
                  __slimbus_dbg("qcom_slim_qmi_send_select_inst_req","QMI TXN wait fail: %d\n",iVar2
                               );
                  if (*(int *)(param_1 + 0x15bc) < 1) {
                    if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_0010446c;
                  }
                  else {
                    _printk(&DAT_0010780f,iVar2);
                    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI TXN wait fail: %d\n",iVar2
                                  );
                    uVar1 = *(undefined4 *)(param_1 + 0x15bc);
                    *(undefined4 *)(param_1 + 0x15bc) = 0;
                    *(undefined4 *)(param_1 + 0x15b8) = uVar1;
                  }
                  uVar5 = *(undefined8 *)(param_1 + 0x15d0);
                  pcVar6 = "QMI TXN wait fail: %d\n";
                  goto LAB_00104444;
                }
                if ((short)local_40[0] == 0) {
                  __slimbus_dbg("qcom_slim_qmi_send_select_inst_req","%s end RC=%d\n",
                                "qcom_slim_qmi_send_select_inst_req",iVar2);
                  iVar7 = *(int *)(param_1 + 0x15bc);
                  if (2 < iVar7) {
                    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"%s end RC=%d\n",
                                   "qcom_slim_qmi_send_select_inst_req",iVar2);
                    iVar7 = *(int *)(param_1 + 0x15bc);
                  }
                  if (iVar7 == 0) {
                    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"%s end RC=%d\n",
                                   "qcom_slim_qmi_send_select_inst_req",iVar2);
                  }
                  goto LAB_001040cc;
                }
                __slimbus_dbg("qcom_slim_qmi_send_select_inst_req","QMI request failed 0x%x\n");
                if (*(int *)(param_1 + 0x15bc) < 1) {
                  if (*(int *)(param_1 + 0x15bc) == 0) goto LAB_00104454;
                }
                else {
                  _printk(&DAT_00107d82,(short)local_40[0]);
                  ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI request failed 0x%x\n",
                                 (short)local_40[0]);
                  uVar1 = *(undefined4 *)(param_1 + 0x15bc);
                  *(undefined4 *)(param_1 + 0x15bc) = 0;
                  *(undefined4 *)(param_1 + 0x15b8) = uVar1;
LAB_00104454:
                  ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"QMI request failed 0x%x\n",
                                 (short)local_40[0]);
                }
                iVar2 = -0x79;
              }
            }
LAB_0010446c:
            _dev_err(*(undefined8 *)(param_1 + 0x7e8),"failed to select h/w instance\n");
            *(undefined8 *)(param_1 + 0x7b8) = 0;
          }
LAB_00104480:
          qmi_handle_release(puVar3);
        }
        devm_kfree(*(undefined8 *)(param_1 + 0x7e8),puVar3);
      }
      __slimbus_dbg("qcom_slim_ngd_enable","qmi init fail, ret:%d, state:%d\n",iVar2,
                    *(undefined4 *)(param_1 + 0x1560));
      if (*(int *)(param_1 + 0x15bc) < 1) {
        if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_001041d4;
      }
      else {
        _printk(&DAT_00108a63,iVar2,*(undefined4 *)(param_1 + 0x1560));
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"qmi init fail, ret:%d, state:%d\n",iVar2,
                       *(undefined4 *)(param_1 + 0x1560));
        uVar1 = *(undefined4 *)(param_1 + 0x15bc);
        *(undefined4 *)(param_1 + 0x15bc) = 0;
        *(undefined4 *)(param_1 + 0x15b8) = uVar1;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"qmi init fail, ret:%d, state:%d\n",iVar2,
                     *(undefined4 *)(param_1 + 0x1560));
      goto LAB_001041d4;
    }
    __slimbus_dbg("qcom_slim_qmi_init","qmi handle already allocated\n");
    iVar2 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"qmi handle already allocated\n");
      iVar2 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"qmi handle already allocated\n");
    }
LAB_001040cc:
    complete(param_1 + 0x7c0);
    lVar4 = *(long *)(param_1 + 0x3a0);
    if (((*(ushort *)(lVar4 + 0x200) & 7) == 0) && (*(int *)(lVar4 + 0x20c) == 2)) {
      __pm_runtime_resume(lVar4,0);
    }
    else {
      qcom_slim_ngd_runtime_resume();
    }
    lVar4 = *(long *)(param_1 + 0x3a0);
    uVar5 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar4 + 0x220) = uVar5;
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0x3a0),5);
    __slimbus_dbg("qcom_slim_ngd_enable","SLIM %s: PM put count:%d\n","qcom_slim_ngd_enable",
                  *(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8));
    iVar2 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM %s: PM put count:%d\n",
                     "qcom_slim_ngd_enable",*(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8));
      iVar2 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM %s: PM put count:%d\n",
                     "qcom_slim_ngd_enable",*(undefined4 *)(*(long *)(param_1 + 0x3a0) + 0x1f8));
    }
    __slimbus_dbg("qcom_slim_ngd_enable","SLIM NGD Enable\n");
    iVar2 = *(int *)(param_1 + 0x15bc);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM NGD Enable\n");
      iVar2 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar2 != 0) goto LAB_001041d4;
    uVar5 = *(undefined8 *)(param_1 + 0x15d0);
    pcVar6 = "SLIM NGD Enable\n";
  }
  ipc_log_string(uVar5,pcVar6);
LAB_001041d4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_runtime_resume @ 00104520 size=1676
// signature: undefined qcom_slim_ngd_runtime_resume(void)
// callers: [qcom_slim_ngd_enable]
//------------------------------------------------------------

undefined8 qcom_slim_ngd_runtime_resume(long param_1)

{
  long lVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint extraout_var;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  
  lVar8 = *(long *)(param_1 + 0x98);
  __slimbus_dbg("qcom_slim_ngd_runtime_resume","Slim runtime resume\n");
  iVar4 = *(int *)(lVar8 + 0x15bc);
  if (2 < iVar4) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"Slim runtime resume\n");
    iVar4 = *(int *)(lVar8 + 0x15bc);
  }
  if (iVar4 == 0) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"Slim runtime resume\n");
  }
  lVar1 = lVar8 + 0x14a8;
  mutex_lock(lVar1);
  if (*(long *)(lVar8 + 0x7b8) == 0) {
    __slimbus_dbg("qcom_slim_ngd_runtime_resume","%s QMI handle is NULL\n",
                  "qcom_slim_ngd_runtime_resume");
    iVar4 = *(int *)(lVar8 + 0x15bc);
    if (1 < iVar4) {
      _printk(&DAT_00107ee3,"qcom_slim_ngd_runtime_resume");
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"%s QMI handle is NULL\n",
                     "qcom_slim_ngd_runtime_resume");
      iVar4 = *(int *)(lVar8 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"%s QMI handle is NULL\n",
                     "qcom_slim_ngd_runtime_resume");
    }
    mutex_unlock(lVar1);
    return 0;
  }
  pcVar2 = (char *)(lVar8 + 0x15dc);
  if (*pcVar2 != '\0') {
    enable_irq(*(undefined4 *)(lVar8 + 0x15d8));
    *pcVar2 = '\0';
    __slimbus_dbg("qcom_slim_ngd_enable_irq","Slim ngd IRQ enabled\n");
    iVar4 = *(int *)(lVar8 + 0x15bc);
    if (2 < iVar4) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"Slim ngd IRQ enabled\n");
      iVar4 = *(int *)(lVar8 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"Slim ngd IRQ enabled\n");
    }
  }
  if (1 < *(uint *)(lVar8 + 0x1560)) {
    lVar10 = *(long *)(lVar8 + 0x7e0);
    __slimbus_dbg("qcom_slim_ngd_power_up","SLIM: NGD power up\n");
    iVar4 = *(int *)(lVar8 + 0x15bc);
    if (2 < iVar4) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"SLIM: NGD power up\n");
      iVar4 = *(int *)(lVar8 + 0x15bc);
    }
    if (iVar4 == 0) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"SLIM: NGD power up\n");
    }
    uVar5 = *(uint *)(lVar8 + 0x1560);
    if (uVar5 == 3) {
      iVar4 = wait_for_completion_timeout(lVar8 + 0x7c0,0xfa);
      if (iVar4 != 0) {
        uVar5 = *(uint *)(lVar8 + 0x1560);
        goto LAB_00104678;
      }
      __slimbus_dbg("qcom_slim_ngd_power_up","slimbus QMI init timed out\n");
      if (*(int *)(lVar8 + 0x15bc) < 1) {
        if (*(int *)(lVar8 + 0x15bc) == 0) goto LAB_0010487c;
      }
      else {
        _printk(&DAT_00108083);
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"slimbus QMI init timed out\n");
        uVar6 = *(undefined4 *)(lVar8 + 0x15bc);
        *(undefined4 *)(lVar8 + 0x15bc) = 0;
        *(undefined4 *)(lVar8 + 0x15b8) = uVar6;
LAB_0010487c:
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"slimbus QMI init timed out\n");
      }
LAB_0010488c:
      if (*(int *)(lVar8 + 0x1560) == 3) {
        __slimbus_dbg("qcom_slim_ngd_runtime_resume","HW wakeup attempt during SSR\n");
        iVar4 = *(int *)(lVar8 + 0x15bc);
        if (1 < iVar4) {
          _printk(&DAT_001075b7);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"HW wakeup attempt during SSR\n");
          iVar4 = *(int *)(lVar8 + 0x15bc);
        }
        if (iVar4 == 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"HW wakeup attempt during SSR\n");
        }
      }
      else {
        *(undefined4 *)(lVar8 + 0x1560) = 2;
      }
      __slimbus_dbg("qcom_slim_ngd_runtime_resume","%s Power up request failed, try resume again\n",
                    "qcom_slim_ngd_runtime_resume");
      if (*(int *)(lVar8 + 0x15bc) < 2) {
        if (*(int *)(lVar8 + 0x15bc) != 0) goto LAB_00104900;
LAB_00104978:
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),
                       "%s Power up request failed, try resume again\n",
                       "qcom_slim_ngd_runtime_resume");
        cVar3 = *pcVar2;
      }
      else {
        _printk(&DAT_00107911,"qcom_slim_ngd_runtime_resume");
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),
                       "%s Power up request failed, try resume again\n",
                       "qcom_slim_ngd_runtime_resume");
        if (*(int *)(lVar8 + 0x15bc) == 0) goto LAB_00104978;
LAB_00104900:
        cVar3 = *pcVar2;
      }
      if (cVar3 == '\0') {
        disable_irq(*(undefined4 *)(lVar8 + 0x15d8));
        *pcVar2 = '\x01';
        __slimbus_dbg("qcom_slim_ngd_disable_irq","Slim ngd IRQ disabled\n");
        iVar4 = *(int *)(lVar8 + 0x15bc);
        if (2 < iVar4) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"Slim ngd IRQ disabled\n");
          iVar4 = *(int *)(lVar8 + 0x15bc);
        }
        if (iVar4 == 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"Slim ngd IRQ disabled\n");
        }
      }
      uVar9 = 0xfffffff5;
      goto LAB_001049f4;
    }
LAB_00104678:
    if ((uVar5 & 0xfffffffe) == 2) {
      __slimbus_dbg("qcom_slim_ngd_power_up","Sending QMI power on request\n");
      iVar4 = *(int *)(lVar8 + 0x15bc);
      if (2 < iVar4) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"Sending QMI power on request\n");
        iVar4 = *(int *)(lVar8 + 0x15bc);
      }
      if (iVar4 == 0) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"Sending QMI power on request\n");
      }
      iVar4 = qcom_slim_qmi_power_request(lVar8,1);
      if (iVar4 != 0) {
        __slimbus_dbg("qcom_slim_ngd_power_up","SLIM QMI power request failed:%d\n",iVar4);
        if (*(int *)(lVar8 + 0x15bc) < 1) {
          if (*(int *)(lVar8 + 0x15bc) != 0) goto LAB_0010488c;
        }
        else {
          _printk(&DAT_00108677,iVar4);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"SLIM QMI power request failed:%d\n",iVar4)
          ;
          uVar6 = *(undefined4 *)(lVar8 + 0x15bc);
          *(undefined4 *)(lVar8 + 0x15bc) = 0;
          *(undefined4 *)(lVar8 + 0x15b8) = uVar6;
        }
        ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"SLIM QMI power request failed:%d\n",iVar4);
        goto LAB_0010488c;
      }
    }
    readl_relaxed(*(undefined8 *)(lVar8 + 0x7f0));
    *(uint *)(lVar8 + 0x1590) = extraout_var & 0xffff;
    uVar5 = readl_relaxed(*(long *)(lVar10 + 8) + 4);
    if ((uVar5 >> 1 & 1) == 0) {
      *(undefined4 *)(lVar8 + 0x1348) = 0;
      writel_relaxed(0xfe000000,*(long *)(lVar10 + 8) + 0x10);
      uVar5 = readl_relaxed(*(long *)(lVar10 + 8) + 8);
      writel_relaxed(uVar5 | 0x10000,*(long *)(lVar10 + 8) + 8);
      qcom_slim_ngd_setup(lVar8);
      iVar4 = wait_for_completion_timeout(lVar8 + 0x1348,0x9c4);
      if (iVar4 == 0) {
        _dev_err(*(undefined8 *)(lVar8 + 0x7e8),"capability exchange timed-out\n");
        uVar6 = readl_relaxed(*(undefined8 *)(lVar10 + 8));
        uVar7 = readl_relaxed(*(long *)(lVar10 + 8) + 4);
        __slimbus_dbg("qcom_slim_ngd_power_up","slim capability time-out stat:0x%x,cfg:0x%x\n",uVar7
                      ,uVar6);
        iVar4 = *(int *)(lVar8 + 0x15bc);
        if (1 < iVar4) {
          _printk(&DAT_0010869b,uVar7,uVar6);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),
                         "slim capability time-out stat:0x%x,cfg:0x%x\n",uVar7,uVar6);
          iVar4 = *(int *)(lVar8 + 0x15bc);
        }
        if (iVar4 == 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),
                         "slim capability time-out stat:0x%x,cfg:0x%x\n",uVar7,uVar6);
        }
        goto LAB_0010488c;
      }
      if (*(int *)(lVar8 + 0x1560) == 3) {
        __slimbus_dbg("qcom_slim_ngd_power_up","ADSP slimbus power up now\n");
        iVar4 = *(int *)(lVar8 + 0x15bc);
        if (2 < iVar4) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"ADSP slimbus power up now\n");
          iVar4 = *(int *)(lVar8 + 0x15bc);
        }
        if (iVar4 == 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"ADSP slimbus power up now\n");
        }
        complete_all(lVar8 + 0x1368);
      }
    }
    else {
      qcom_slim_ngd_setup(lVar8);
    }
  }
  uVar9 = 0;
  *(undefined4 *)(lVar8 + 0x1560) = 0;
LAB_001049f4:
  mutex_unlock(lVar1);
  __slimbus_dbg("qcom_slim_ngd_runtime_resume","Slim runtime resume: ret %d irq_disabled %d\n",uVar9
                ,*pcVar2);
  iVar4 = *(int *)(lVar8 + 0x15bc);
  if (2 < iVar4) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x15c8),"Slim runtime resume: ret %d irq_disabled %d\n",
                   uVar9,*pcVar2);
    iVar4 = *(int *)(lVar8 + 0x15bc);
  }
  if (iVar4 == 0) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x15d0),"Slim runtime resume: ret %d irq_disabled %d\n",
                   uVar9,*pcVar2);
  }
  return uVar9;
}



//------------------------------------------------------------
// qcom_slim_qmi_power_resp_cb @ 00104bb0 size=68
// signature: undefined qcom_slim_qmi_power_resp_cb(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_qmi_power_resp_cb(undefined8 param_1,undefined8 param_2,long param_3,short *param_4)

{
  if (*param_4 != 0) {
    _printk(&DAT_001077ee);
  }
  complete(param_3 + 0x10);
  return;
}



//------------------------------------------------------------
// qcom_slim_qmi_power_request @ 00104bf4 size=748
// signature: undefined qcom_slim_qmi_power_request(void)
// callers: [qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

int qcom_slim_qmi_power_request(long param_1,ulong param_2)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_98;
  undefined8 local_94;
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
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_98 = 1;
  if ((param_2 & 1) != 0) {
    local_98 = 2;
  }
  local_94 = 0;
  local_40[0] = 0;
  lVar1 = param_1 + 0x1508;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_88 = 0;
  mutex_lock(lVar1);
  if (*(long *)(param_1 + 0x7b8) == 0) {
    mutex_unlock(lVar1);
    iVar3 = -0x16;
    goto LAB_00104e10;
  }
  qmi_txn_init(*(long *)(param_1 + 0x7b8),&local_88,slimbus_power_resp_msg_v01_ei,local_40);
  iVar3 = qmi_send_request(*(undefined8 *)(param_1 + 0x7b8),0,&local_88,0x21,0xe,
                           slimbus_power_req_msg_v01_ei,&local_98);
  if (-1 < iVar3) {
    mutex_unlock(lVar1);
    iVar3 = qmi_txn_wait(&local_88,1000);
    if (iVar3 < 0) {
      __slimbus_dbg("qcom_slim_qmi_send_power_request","QMI TXN wait fail: %d\n",iVar3);
      if (*(int *)(param_1 + 0x15bc) < 1) {
        if (*(int *)(param_1 + 0x15bc) != 0) goto LAB_00104e10;
      }
      else {
        _printk(&DAT_0010780f,iVar3);
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI TXN wait fail: %d\n",iVar3);
        uVar2 = *(undefined4 *)(param_1 + 0x15bc);
        *(undefined4 *)(param_1 + 0x15bc) = 0;
        *(undefined4 *)(param_1 + 0x15b8) = uVar2;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"QMI TXN wait fail: %d\n",iVar3);
      goto LAB_00104e10;
    }
    if ((short)local_40[0] == 0) {
      __slimbus_dbg("qcom_slim_qmi_send_power_request","%s end %d\n",
                    "qcom_slim_qmi_send_power_request",local_98);
      iVar3 = *(int *)(param_1 + 0x15bc);
      if (2 < iVar3) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"%s end %d\n",
                       "qcom_slim_qmi_send_power_request",local_98);
        iVar3 = *(int *)(param_1 + 0x15bc);
      }
      if (iVar3 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"%s end %d\n",
                       "qcom_slim_qmi_send_power_request",local_98);
      }
      iVar3 = 0;
      goto LAB_00104e10;
    }
    __slimbus_dbg("qcom_slim_qmi_send_power_request","QMI request failed 0x%x\n");
    if (*(int *)(param_1 + 0x15bc) < 1) {
      if (*(int *)(param_1 + 0x15bc) == 0) goto LAB_00104ce4;
    }
    else {
      _printk(&DAT_00107d82,(short)local_40[0]);
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI request failed 0x%x\n",
                     (short)local_40[0]);
      uVar2 = *(undefined4 *)(param_1 + 0x15bc);
      *(undefined4 *)(param_1 + 0x15bc) = 0;
      *(undefined4 *)(param_1 + 0x15b8) = uVar2;
LAB_00104ce4:
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"QMI request failed 0x%x\n",
                     (short)local_40[0]);
    }
    iVar3 = -0x79;
    goto LAB_00104e10;
  }
  __slimbus_dbg("qcom_slim_qmi_send_power_request","QMI send req fail %d\n",iVar3);
  if (*(int *)(param_1 + 0x15bc) < 1) {
    if (*(int *)(param_1 + 0x15bc) == 0) goto LAB_00104d38;
  }
  else {
    _printk(&DAT_00108001,iVar3);
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"QMI send req fail %d\n",iVar3);
    uVar2 = *(undefined4 *)(param_1 + 0x15bc);
    *(undefined4 *)(param_1 + 0x15bc) = 0;
    *(undefined4 *)(param_1 + 0x15b8) = uVar2;
LAB_00104d38:
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"QMI send req fail %d\n",iVar3);
  }
  mutex_unlock(lVar1);
  qmi_txn_cancel(&local_88);
LAB_00104e10:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// readl_relaxed @ 00104ee0 size=124
// signature: undefined readl_relaxed(void)
// callers: [qcom_slim_ngd_setup, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x104f28,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_slim_ngd_setup @ 00104f5c size=1132
// signature: undefined qcom_slim_ngd_setup(void)
// callers: [qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

void qcom_slim_ngd_setup(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  int iVar6;
  long lVar7;
  code *pcVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78;
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  uVar1 = readl_relaxed(*(undefined8 *)(*(long *)(param_1 + 0x7e0) + 8));
  __slimbus_dbg("qcom_slim_ngd_setup","SLIM: NGD setup\n");
  iVar6 = *(int *)(param_1 + 0x15bc);
  if (2 < iVar6) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM: NGD setup\n");
    iVar6 = *(int *)(param_1 + 0x15bc);
  }
  if (iVar6 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM: NGD setup\n");
  }
  if ((*(uint *)(param_1 + 0x1560) & 0xfffffffe) != 2) goto LAB_0010533c;
  __slimbus_dbg("qcom_slim_ngd_init_dma","SLIM: NGD init dma\n");
  iVar6 = *(int *)(param_1 + 0x15bc);
  if (2 < iVar6) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"SLIM: NGD init dma\n");
    iVar6 = *(int *)(param_1 + 0x15bc);
  }
  if (iVar6 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"SLIM: NGD init dma\n");
  }
  uVar9 = *(undefined8 *)(param_1 + 0x7e8);
  local_90 = 0;
  uVar3 = dma_request_chan(uVar9,&DAT_00107b9e);
  *(ulong *)(param_1 + 0x7f8) = uVar3;
  if (uVar3 < 0xfffffffffffff001) {
    pcVar5 = (char *)(param_1 + 0x15b4);
    if (*pcVar5 == '\0') {
      lVar4 = dma_alloc_attrs(uVar9,0x4b0,&local_90,0xcc0,0);
      *(long *)(param_1 + 0x1578) = lVar4;
    }
    else {
      lVar4 = *(long *)(param_1 + 0x15a0);
      *(long *)(param_1 + 0x1578) = lVar4;
    }
    if (lVar4 == 0) {
LAB_00105324:
      dma_release_channel(*(undefined8 *)(param_1 + 0x7f8));
      goto LAB_0010532c;
    }
    if (*pcVar5 == '\0') {
      *(undefined8 *)(param_1 + 0x1568) = local_90;
    }
    else {
      *(undefined8 *)(param_1 + 0x1568) = **(undefined8 **)(param_1 + 0x1598);
      __memset_io(lVar4,0,0x4b0);
      *(long *)(param_1 + 0x15a0) = *(long *)(param_1 + 0x15a0) + 0x4b0;
      **(long **)(param_1 + 0x1598) = **(long **)(param_1 + 0x1598) + 0x4b0;
    }
    lVar4 = 0;
    plVar11 = (long *)(param_1 + 0x808);
    do {
      lVar7 = *(long *)(param_1 + 0x1568);
      plVar11[1] = param_1;
      local_78 = 0;
      local_70 = 0;
      lVar7 = lVar4 + lVar7;
      local_88 = 0;
      uStack_80 = 0;
      plVar11[4] = lVar7;
      plVar11[5] = *(long *)(param_1 + 0x1578) + lVar4;
      plVar10 = *(long **)(param_1 + 0x7f8);
      sg_init_table(&local_88,1);
      local_70 = CONCAT44(local_70._4_4_,0x28);
      local_78 = lVar7;
      if (((plVar10 == (long *)0x0) || (*plVar10 == 0)) ||
         (pcVar8 = *(code **)(*plVar10 + 0x108), pcVar8 == (code *)0x0)) {
        *plVar11 = 0;
LAB_001052e0:
        _dev_err(*(undefined8 *)(param_1 + 0x7e8),"Unable to prepare rx channel\n");
        _dev_err(uVar9,"post_rx_msgq() failed 0x%x\n",0xffffffea);
        if (*pcVar5 == '\0') {
          dma_free_attrs(uVar9,0x4b0,*(undefined8 *)(param_1 + 0x1578),
                         *(undefined8 *)(param_1 + 0x1568),0);
        }
        goto LAB_00105324;
      }
      if (*(int *)(pcVar8 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x105180);
        (*pcVar8)();
      }
      lVar7 = (*pcVar8)(plVar10,&local_88,1,2,1,0);
      *plVar11 = lVar7;
      if (lVar7 == 0) goto LAB_001052e0;
      *(code **)(lVar7 + 0x28) = qcom_slim_ngd_rx_msgq_cb;
      *(long **)(*plVar11 + 0x38) = plVar11;
      if (*(int *)(*(code **)(*plVar11 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1051b8);
        (*pcVar8)();
      }
      uVar2 = (**(code **)(*plVar11 + 0x18))();
      lVar4 = lVar4 + 0x28;
      *(undefined4 *)*plVar11 = uVar2;
      plVar11 = plVar11 + 6;
    } while (lVar4 != 0x4b0);
    pcVar8 = *(code **)(**(long **)(param_1 + 0x7f8) + 0x160);
    if (*(int *)(pcVar8 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1051f4);
      (*pcVar8)();
    }
    (*pcVar8)();
LAB_001051f8:
    uVar9 = *(undefined8 *)(param_1 + 0x7e8);
    local_88 = 0;
    uVar3 = dma_request_chan(uVar9,&DAT_00108761);
    *(ulong *)(param_1 + 0x800) = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      if (*(char *)(param_1 + 0x15b4) == '\0') {
        lVar4 = dma_alloc_attrs(uVar9,0x4d8,&local_88,0xcc0,0);
        *(long *)(param_1 + 0x1580) = lVar4;
      }
      else {
        lVar4 = *(long *)(param_1 + 0x15a0);
        *(long *)(param_1 + 0x1580) = lVar4;
      }
      if (lVar4 != 0) {
        if (*(char *)(param_1 + 0x15b4) == '\0') {
          *(undefined8 *)(param_1 + 0x1570) = local_88;
        }
        else {
          *(undefined8 *)(param_1 + 0x1570) = **(undefined8 **)(param_1 + 0x1598);
          __memset_io(lVar4,0,0x4d8);
          *(long *)(param_1 + 0x15a0) = *(long *)(param_1 + 0x15a0) + 0x4d8;
          **(long **)(param_1 + 0x1598) = **(long **)(param_1 + 0x1598) + 0x4d8;
        }
        uVar9 = _raw_spin_lock_irqsave(param_1 + 0x1470);
        *(undefined8 *)(param_1 + 0x1588) = 0;
        _raw_spin_unlock_irqrestore(param_1 + 0x1470,uVar9);
        goto LAB_0010533c;
      }
      dma_release_channel(*(undefined8 *)(param_1 + 0x800));
    }
    else {
      _dev_err(uVar9,"Failed to request TX dma channel");
      iVar6 = *(int *)(param_1 + 0x800);
      *(undefined8 *)(param_1 + 0x800) = 0;
      if (iVar6 == 0) goto LAB_0010533c;
    }
    uVar9 = *(undefined8 *)(param_1 + 0x7e8);
    pcVar5 = "tx dma init failed\n";
  }
  else {
    _dev_err(uVar9,"Failed to request RX dma channel");
    iVar6 = *(int *)(param_1 + 0x7f8);
    *(undefined8 *)(param_1 + 0x7f8) = 0;
    if (iVar6 == 0) goto LAB_001051f8;
LAB_0010532c:
    uVar9 = *(undefined8 *)(param_1 + 0x7e8);
    pcVar5 = "rx dma init failed\n";
  }
  _dev_err(uVar9,pcVar5);
LAB_0010533c:
  writel_relaxed(uVar1 | 7,*(undefined8 *)(*(long *)(param_1 + 0x7e0) + 8));
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 001053c8 size=132
// signature: undefined writel_relaxed(void)
// callers: [qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_setup, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1053e0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10541c,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_rx_msgq_cb @ 00105450 size=620
// signature: undefined qcom_slim_ngd_rx_msgq_cb(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_ngd_rx_msgq_cb(long *param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  byte *pbVar12;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  undefined8 local_60;
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  if (param_1 != (long *)0x0) {
    pbVar12 = (byte *)param_1[5];
    lVar11 = param_1[1];
    bVar3 = *pbVar12;
    bVar4 = pbVar12[1];
    uVar1 = bVar3 & 0x1f;
    __slimbus_dbg("qcom_slim_ngd_rx","BAM RX len = %d buf[0]:0x%x buf[1]:0x%x\n",uVar1,(uint)bVar3,
                  bVar4);
    iVar2 = *(int *)(lVar11 + 0x15bc);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x15c8),"BAM RX len = %d buf[0]:0x%x buf[1]:0x%x\n",
                     uVar1,*pbVar12,pbVar12[1]);
      iVar2 = *(int *)(lVar11 + 0x15bc);
    }
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x15d0),"BAM RX len = %d buf[0]:0x%x buf[1]:0x%x\n",
                     uVar1,*pbVar12,pbVar12[1]);
    }
    if (((bVar4 & 0x7f) == 0) && ((bVar3 & 0xe0) == 0xc0)) {
      queue_work_on(0x20,*(undefined8 *)(lVar11 + 0x13e8),lVar11 + 5000);
    }
    bVar5 = (bVar3 & 0xe0) == 0xc0;
    if ((((bVar4 & 0x3f) == 0x24) || (bVar5 && (bVar4 & 0x7f) == 0xe)) ||
       (bVar5 && (bVar4 & 0x7f) == 0x25)) {
      slim_msg_response(lVar11 + 0x3a0,pbVar12 + 4,pbVar12[3],uVar1 - 4);
      lVar9 = *(long *)(lVar11 + 0x3a0);
      uVar7 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar9 + 0x220) = uVar7;
    }
    plVar10 = *(long **)(lVar11 + 0x7f8);
    local_68 = 0;
    local_60 = 0;
    lVar9 = param_1[4];
    local_78 = 0;
    uStack_70 = 0;
    sg_init_table(&local_78,1);
    local_60 = CONCAT44(local_60._4_4_,0x28);
    local_68 = lVar9;
    if (((plVar10 == (long *)0x0) || (*plVar10 == 0)) ||
       (pcVar8 = *(code **)(*plVar10 + 0x108), pcVar8 == (code *)0x0)) {
      *param_1 = 0;
    }
    else {
      if (*(int *)(pcVar8 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1055f8);
        (*pcVar8)();
      }
      lVar9 = (*pcVar8)(plVar10,&local_78,1,2,1,0);
      *param_1 = lVar9;
      if (lVar9 != 0) {
        *(code **)(lVar9 + 0x28) = qcom_slim_ngd_rx_msgq_cb;
        *(long **)(*param_1 + 0x38) = param_1;
        if (*(int *)(*(code **)(*param_1 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x105638);
          (*pcVar8)();
        }
        uVar6 = (**(code **)(*param_1 + 0x18))();
        *(undefined4 *)*param_1 = uVar6;
        pcVar8 = *(code **)(**(long **)(lVar11 + 0x7f8) + 0x160);
        if (*(int *)(pcVar8 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x105668);
          (*pcVar8)();
        }
        (*pcVar8)();
        goto LAB_00105684;
      }
    }
    _dev_err(*(undefined8 *)(lVar11 + 0x7e8),"Unable to prepare rx channel\n");
  }
LAB_00105684:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_xfer_msg_sync @ 001056bc size=872
// signature: undefined qcom_slim_ngd_xfer_msg_sync(void)
// callers: [qcom_slim_ngd_disable_stream, qcom_slim_ngd_enable_stream, qcom_slim_ngd_get_laddr]
//------------------------------------------------------------

int qcom_slim_ngd_xfer_msg_sync(long *param_1,long param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  
  *(undefined4 *)(param_1 + 0x212) = 0;
  iVar6 = __pm_runtime_resume(*param_1,4);
  if (iVar6 < 0) {
    __slimbus_dbg("qcom_slim_ngd_xfer_msg_sync",
                  "SLIM %s: PM get_sync failed ret :%d count:%d TID:%d\n",
                  "qcom_slim_ngd_xfer_msg_sync",iVar6,*(undefined4 *)(*param_1 + 0x1f8),
                  *(undefined1 *)(param_2 + 6));
    if (*(int *)((long)param_1 + 0x121c) < 1) {
      if (*(int *)((long)param_1 + 0x121c) != 0) goto LAB_001058b8;
    }
    else {
      _printk(&DAT_00107dbf,"qcom_slim_ngd_xfer_msg_sync",iVar6,*(undefined4 *)(*param_1 + 0x1f8),
              *(undefined1 *)(param_2 + 6));
      ipc_log_string(param_1[0x245],"SLIM %s: PM get_sync failed ret :%d count:%d TID:%d\n",
                     "qcom_slim_ngd_xfer_msg_sync",iVar6,*(undefined4 *)(*param_1 + 0x1f8),
                     *(undefined1 *)(param_2 + 6));
      uVar2 = *(undefined4 *)((long)param_1 + 0x121c);
      *(undefined4 *)((long)param_1 + 0x121c) = 0;
      *(undefined4 *)(param_1 + 0x243) = uVar2;
    }
    ipc_log_string(param_1[0x246],"SLIM %s: PM get_sync failed ret :%d count:%d TID:%d\n",
                   "qcom_slim_ngd_xfer_msg_sync",iVar6,*(undefined4 *)(*param_1 + 0x1f8),
                   *(undefined1 *)(param_2 + 6));
    goto LAB_001058b8;
  }
  __slimbus_dbg("qcom_slim_ngd_xfer_msg_sync","SLIM %s: PM get_sync count:%d TID:%d\n",
                "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                *(undefined1 *)(param_2 + 6));
  iVar6 = *(int *)((long)param_1 + 0x121c);
  if (2 < iVar6) {
    ipc_log_string(param_1[0x245],"SLIM %s: PM get_sync count:%d TID:%d\n",
                   "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                   *(undefined1 *)(param_2 + 6));
    iVar6 = *(int *)((long)param_1 + 0x121c);
  }
  if (iVar6 == 0) {
    ipc_log_string(param_1[0x246],"SLIM %s: PM get_sync count:%d TID:%d\n",
                   "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                   *(undefined1 *)(param_2 + 6));
  }
  *(long **)(param_2 + 0x10) = param_1 + 0x212;
  iVar6 = qcom_slim_ngd_xfer_msg(param_1,param_2);
  if (iVar6 != 0) {
    __slimbus_dbg("qcom_slim_ngd_xfer_msg_sync","SLIM %s: xfer_msg failed PM put count:%d TID:%d\n",
                  "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                  *(undefined1 *)(param_2 + 6));
    if (*(int *)((long)param_1 + 0x121c) < 1) {
      if (*(int *)((long)param_1 + 0x121c) != 0) goto LAB_001058b8;
    }
    else {
      _printk(&DAT_0010783f,"qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
              *(undefined1 *)(param_2 + 6));
      ipc_log_string(param_1[0x245],"SLIM %s: xfer_msg failed PM put count:%d TID:%d\n",
                     "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                     *(undefined1 *)(param_2 + 6));
      uVar2 = *(undefined4 *)((long)param_1 + 0x121c);
      *(undefined4 *)((long)param_1 + 0x121c) = 0;
      *(undefined4 *)(param_1 + 0x243) = uVar2;
    }
    ipc_log_string(param_1[0x246],"SLIM %s: xfer_msg failed PM put count:%d TID:%d\n",
                   "qcom_slim_ngd_xfer_msg_sync",*(undefined4 *)(*param_1 + 0x1f8),
                   *(undefined1 *)(param_2 + 6));
    goto LAB_001058b8;
  }
  iVar6 = wait_for_completion_timeout(param_1 + 0x212,0xfa);
  if (iVar6 != 0) {
    return 0;
  }
  __slimbus_dbg("qcom_slim_ngd_xfer_msg_sync","%s: TX sync timed out:MC:0x%x,mt:0x%x",
                *(undefined1 *)(param_2 + 2),"qcom_slim_ngd_xfer_msg_sync",
                *(undefined1 *)(param_2 + 1));
  if (*(int *)((long)param_1 + 0x121c) < 1) {
    if (*(int *)((long)param_1 + 0x121c) == 0) goto LAB_00105894;
  }
  else {
    _printk(&DAT_001076da,*(undefined1 *)(param_2 + 2),"qcom_slim_ngd_xfer_msg_sync",
            *(undefined1 *)(param_2 + 1));
    ipc_log_string(param_1[0x245],"%s: TX sync timed out:MC:0x%x,mt:0x%x",
                   *(undefined1 *)(param_2 + 2),"qcom_slim_ngd_xfer_msg_sync",
                   *(undefined1 *)(param_2 + 1));
    uVar2 = *(undefined4 *)((long)param_1 + 0x121c);
    *(undefined4 *)((long)param_1 + 0x121c) = 0;
    *(undefined4 *)(param_1 + 0x243) = uVar2;
LAB_00105894:
    ipc_log_string(param_1[0x246],"%s: TX sync timed out:MC:0x%x,mt:0x%x",
                   *(undefined1 *)(param_2 + 2),"qcom_slim_ngd_xfer_msg_sync",
                   *(undefined1 *)(param_2 + 1));
  }
  iVar6 = -0x6e;
LAB_001058b8:
  piVar1 = (int *)(*param_1 + 0x1f8);
  iVar7 = *(int *)(*param_1 + 0x1f8);
  do {
    if (iVar7 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      if (iVar3 != iVar7) goto LAB_001058e4;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar7 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
LAB_001058e4:
    bVar5 = iVar7 != iVar3;
    iVar7 = iVar3;
  } while (bVar5);
  __pm_runtime_set_status(*param_1,2);
  return iVar6;
}



//------------------------------------------------------------
// qcom_slim_ngd_runtime_suspend @ 00105a3c size=732
// signature: undefined qcom_slim_ngd_runtime_suspend(void)
// callers: [qcom_ngd_set_suspend]
//------------------------------------------------------------

int qcom_slim_ngd_runtime_suspend(long param_1)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar6 = *(long *)(lVar5 + 0x7e0);
  __slimbus_dbg("qcom_slim_ngd_runtime_suspend","Slim runtime suspend\n");
  iVar3 = *(int *)(lVar5 + 0x15bc);
  if (2 < iVar3) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"Slim runtime suspend\n");
    iVar3 = *(int *)(lVar5 + 0x15bc);
  }
  if (iVar3 == 0) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"Slim runtime suspend\n");
  }
  lVar1 = lVar5 + 0x14a8;
  mutex_lock(lVar1);
  if (*(long *)(lVar5 + 0x7b8) == 0) {
    __slimbus_dbg("qcom_slim_ngd_runtime_suspend","%s QMI handle is NULL\n",
                  "qcom_slim_ngd_runtime_suspend");
    iVar3 = *(int *)(lVar5 + 0x15bc);
    if (1 < iVar3) {
      _printk(&DAT_00107ee3,"qcom_slim_ngd_runtime_suspend");
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"%s QMI handle is NULL\n",
                     "qcom_slim_ngd_runtime_suspend");
      iVar3 = *(int *)(lVar5 + 0x15bc);
    }
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"%s QMI handle is NULL\n",
                     "qcom_slim_ngd_runtime_suspend");
    }
    mutex_unlock(lVar1);
    return 0;
  }
  qcom_slim_ngd_exit_dma(lVar5);
  pcVar2 = (char *)(lVar5 + 0x15dc);
  if (*pcVar2 == '\0') {
    disable_irq(*(undefined4 *)(lVar5 + 0x15d8));
    *pcVar2 = '\x01';
    __slimbus_dbg("qcom_slim_ngd_disable_irq","Slim ngd IRQ disabled\n");
    iVar3 = *(int *)(lVar5 + 0x15bc);
    if (2 < iVar3) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"Slim ngd IRQ disabled\n");
      iVar3 = *(int *)(lVar5 + 0x15bc);
    }
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"Slim ngd IRQ disabled\n");
    }
  }
  writel_relaxed(0,*(long *)(lVar6 + 8) + 0x10);
  __slimbus_dbg("qcom_slim_ngd_runtime_suspend","Sending QMI power off request\n");
  iVar3 = *(int *)(lVar5 + 0x15bc);
  if (2 < iVar3) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"Sending QMI power off request\n");
    iVar3 = *(int *)(lVar5 + 0x15bc);
  }
  if (iVar3 == 0) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"Sending QMI power off request\n");
  }
  iVar3 = qcom_slim_qmi_power_request(lVar5,0);
  if (iVar3 != -0x10) {
    if (iVar3 != 0) {
      __slimbus_dbg("qcom_slim_ngd_runtime_suspend","slim resource not idle:%d\n",iVar3);
      iVar4 = *(int *)(lVar5 + 0x15bc);
      if (2 < iVar4) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"slim resource not idle:%d\n",iVar3);
        iVar4 = *(int *)(lVar5 + 0x15bc);
      }
      if (iVar4 == 0) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"slim resource not idle:%d\n",iVar3);
      }
      if ((iVar3 != 0) && (iVar3 != -0x6e)) goto LAB_00105c60;
    }
    *(undefined4 *)(lVar5 + 0x1560) = 2;
  }
LAB_00105c60:
  mutex_unlock(lVar1);
  __slimbus_dbg("qcom_slim_ngd_runtime_suspend","Slim runtime suspend: ret %d irq_disabled %d\n",
                iVar3,*pcVar2);
  iVar4 = *(int *)(lVar5 + 0x15bc);
  if (2 < iVar4) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15c8),"Slim runtime suspend: ret %d irq_disabled %d\n",
                   iVar3,*pcVar2);
    iVar4 = *(int *)(lVar5 + 0x15bc);
  }
  if (iVar4 == 0) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x15d0),"Slim runtime suspend: ret %d irq_disabled %d\n",
                   iVar3,*pcVar2);
  }
  return iVar3;
}



//------------------------------------------------------------
// qcom_slim_ngd_tx_msg_post @ 00105d18 size=756
// signature: undefined qcom_slim_ngd_tx_msg_post(void)
// callers: [qcom_slim_ngd_xfer_msg]
//------------------------------------------------------------

undefined8 qcom_slim_ngd_tx_msg_post(long param_1,long param_2,int param_3)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  uVar5 = _raw_spin_lock_irqsave(param_1 + 0x1470);
  lVar6 = *(long *)(param_1 + 0x1580);
  iVar8 = (int)param_2 - (int)lVar6;
  if (0x1e < (uint)(iVar8 / 0x28)) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x106008);
    (*pcVar7)();
  }
  lVar12 = param_1 + (ulong)(uint)(iVar8 / 0x28) * 0x30;
  uVar2 = param_3 + 3U & 0xfc;
  *(long *)(lVar12 + 0xdc8) = *(long *)(param_1 + 0x1570) + (long)iVar8;
  *(long *)(lVar12 + 0xdd0) = lVar6 + iVar8;
  *(long *)(lVar12 + 0xdb0) = param_1;
  if (uVar2 != 0) {
    uVar3 = uVar2 >> 2;
    uVar10 = 0;
    if (uVar3 < 2) {
      uVar3 = 1;
    }
    do {
      __slimbus_dbg("qcom_slim_ngd_tx_msg_post","BAM TX len = %d buf[%d]:0x%x\n",uVar2,
                    uVar10 & 0xffffffff,*(undefined4 *)(param_2 + uVar10 * 4));
      iVar8 = *(int *)(param_1 + 0x15bc);
      if (2 < iVar8) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15c8),"BAM TX len = %d buf[%d]:0x%x\n",uVar2,
                       uVar10 & 0xffffffff,*(undefined4 *)(param_2 + uVar10 * 4));
        iVar8 = *(int *)(param_1 + 0x15bc);
      }
      if (iVar8 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x15d0),"BAM TX len = %d buf[%d]:0x%x\n",uVar2,
                       uVar10 & 0xffffffff,*(undefined4 *)(param_2 + uVar10 * 4));
      }
      uVar10 = uVar10 + 1;
    } while (uVar3 != uVar10);
  }
  plVar9 = *(long **)(param_1 + 0x800);
  plVar1 = (long *)(lVar12 + 0xda8);
  if (plVar9 == (long *)0x0) {
    __slimbus_dbg("qcom_slim_ngd_tx_msg_post"," tx channel not available\n");
    iVar8 = *(int *)(param_1 + 0x15bc);
    if (1 < iVar8) {
      _printk(&DAT_00107c20);
      ipc_log_string(*(undefined8 *)(param_1 + 0x15c8)," tx channel not available\n");
      iVar8 = *(int *)(param_1 + 0x15bc);
    }
    if (iVar8 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x15d0)," tx channel not available\n");
    }
    plVar9 = *(long **)(param_1 + 0x800);
  }
  uVar11 = *(undefined8 *)(lVar12 + 0xdc8);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  sg_init_table(&local_88,1);
  local_70 = CONCAT44(local_70._4_4_,param_3 + 3U) & 0xffffffff000000fc;
  local_78 = uVar11;
  if (((plVar9 == (long *)0x0) || (*plVar9 == 0)) ||
     (pcVar7 = *(code **)(*plVar9 + 0x108), pcVar7 == (code *)0x0)) {
    *plVar1 = 0;
  }
  else {
    if (*(int *)(pcVar7 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105f00);
      (*pcVar7)();
    }
    lVar6 = (*pcVar7)(plVar9,&local_88,1,1,1,0);
    *plVar1 = lVar6;
    if (lVar6 != 0) {
      *(code **)(lVar6 + 0x28) = qcom_slim_ngd_tx_msg_dma_cb;
      *(long **)(*plVar1 + 0x38) = plVar1;
      if (*(int *)(*(code **)(*plVar1 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105f40);
        (*pcVar7)();
      }
      uVar4 = (**(code **)(*plVar1 + 0x18))();
      *(undefined4 *)*plVar1 = uVar4;
      pcVar7 = *(code **)(**(long **)(param_1 + 0x800) + 0x160);
      if (*(int *)(pcVar7 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105f70);
        (*pcVar7)();
      }
      (*pcVar7)();
      uVar11 = 0;
      goto LAB_00105f94;
    }
  }
  _dev_err(*(undefined8 *)(param_1 + 0x7e8),"unable to prepare channel\n");
  uVar11 = 0xffffffea;
LAB_00105f94:
  _raw_spin_unlock_irqrestore(param_1 + 0x1470,uVar5);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// qcom_slim_ngd_tx_msg_dma_cb @ 00106010 size=268
// signature: undefined qcom_slim_ngd_tx_msg_dma_cb(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_ngd_tx_msg_dma_cb(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 8);
  if (*(char *)(lVar3 + 0x15dd) == '\0') {
    uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x1470);
    if (*(long *)(param_1 + 0x10) != 0) {
      complete(*(long *)(param_1 + 0x10));
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    *(int *)(lVar3 + 0x158c) = (*(int *)(lVar3 + 0x158c) + 1) % 0x1e;
    _raw_spin_unlock_irqrestore(lVar3 + 0x1470,uVar2);
  }
  else {
    *(char *)(lVar3 + 0x15dd) = '\0';
    __slimbus_dbg("qcom_slim_ngd_tx_msg_dma_cb","Timedout due to delayed interrupt\n");
    iVar1 = *(int *)(lVar3 + 0x15bc);
    if (1 < iVar1) {
      _printk(&DAT_00107e4f);
      ipc_log_string(*(undefined8 *)(lVar3 + 0x15c8),"Timedout due to delayed interrupt\n");
      iVar1 = *(int *)(lVar3 + 0x15bc);
    }
    if (iVar1 == 0) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x15d0),"Timedout due to delayed interrupt\n");
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_probe @ 00106120 size=612
// signature: undefined qcom_slim_ngd_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_slim_ngd_probe(long param_1)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  lVar1 = param_1 + 0x10;
  lVar7 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
  *(long *)(lVar7 + 0x3a0) = lVar1;
  iVar5 = slim_register_controller(lVar7 + 0x3a0);
  if (iVar5 == 0) {
    *(long *)(param_1 + 0xa8) = lVar7;
    __pm_runtime_use_autosuspend(lVar1,1);
    pm_runtime_set_autosuspend_delay(lVar1,100);
    __pm_runtime_set_status(lVar1,2);
    pm_runtime_enable(lVar1);
    piVar2 = (int *)(param_1 + 0x208);
    Hint_Prefetch(piVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar4) {
        *piVar2 = *piVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    __slimbus_dbg("qcom_slim_ngd_probe","SLIM %s:PM get_noresume count:%d\n","qcom_slim_ngd_probe",
                  *(undefined4 *)(*(long *)(lVar7 + 0x3a0) + 0x1f8));
    iVar5 = *(int *)(lVar7 + 0x15bc);
    if (2 < iVar5) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x15c8),"SLIM %s:PM get_noresume count:%d\n",
                     "qcom_slim_ngd_probe",*(undefined4 *)(*(long *)(lVar7 + 0x3a0) + 0x1f8));
      iVar5 = *(int *)(lVar7 + 0x15bc);
    }
    if (iVar5 == 0) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x15d0),"SLIM %s:PM get_noresume count:%d\n",
                     "qcom_slim_ngd_probe",*(undefined4 *)(*(long *)(lVar7 + 0x3a0) + 0x1f8));
    }
    *(undefined8 *)(lVar7 + 5000) = 0xfffffffe0;
    *(long *)(lVar7 + 0x1390) = lVar7 + 0x1390;
    *(long *)(lVar7 + 0x1398) = lVar7 + 0x1390;
    *(undefined8 *)(lVar7 + 0x13b8) = 0xfffffffe0;
    *(code **)(lVar7 + 0x13a0) = qcom_slim_ngd_master_worker;
    *(long *)(lVar7 + 0x13c0) = lVar7 + 0x13c0;
    *(long *)(lVar7 + 0x13c8) = lVar7 + 0x13c0;
    *(code **)(lVar7 + 0x13d0) = qcom_slim_ngd_up_worker;
    lVar6 = alloc_workqueue(&DAT_00107c3d,0xe000a,1,"ngd_master");
    *(long *)(lVar7 + 0x13e8) = lVar6;
    if (lVar6 == 0) {
      _dev_err(lVar1,"Failed to start master worker\n");
      qmi_handle_release(lVar7 + 0x668);
      if (*(long *)(lVar7 + 0x13e8) != 0) {
        destroy_workqueue();
      }
      iVar5 = -0xc;
    }
    else {
      lVar6 = lVar7 + 0x668;
      iVar5 = qmi_handle_init(lVar6,0,&qcom_slim_ngd_qmi_svc_event_ops,0);
      if (iVar5 < 0) {
        _dev_err(*(undefined8 *)(lVar7 + 0x7e8),"qmi_handle_init failed: %d\n",iVar5);
      }
      else {
        iVar5 = qmi_add_lookup(lVar6,0x301,1,0);
        if (iVar5 < 0) {
          _dev_err(*(undefined8 *)(lVar7 + 0x7e8),"qmi_add_lookup failed: %d\n",iVar5);
          qmi_handle_release(lVar6);
        }
        else if (iVar5 == 0) {
          return 0;
        }
      }
      _dev_err(lVar1,"QMI service registration failed:%d\n",iVar5);
    }
    slim_unregister_controller(lVar7 + 0x3a0);
  }
  else {
    _dev_err(lVar1,"error adding slim controller\n");
  }
  return iVar5;
}



//------------------------------------------------------------
// qcom_slim_ngd_remove @ 00106394 size=128
// signature: undefined qcom_slim_ngd_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  __pm_runtime_disable(param_1 + 0x10,1);
  pdr_handle_release(*(undefined8 *)(lVar1 + 0x1558));
  qcom_unregister_ssr_notifier(*(undefined8 *)(lVar1 + 0x1550),lVar1 + 0x1538);
  slim_unregister_controller(lVar1 + 0x3a0);
  qcom_slim_ngd_exit_dma(lVar1);
  qmi_handle_release(lVar1 + 0x668);
  if (*(long *)(lVar1 + 0x13e8) != 0) {
    destroy_workqueue();
  }
  kfree(*(undefined8 *)(lVar1 + 0x7e0));
  *(undefined8 *)(lVar1 + 0x7e0) = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_slim_ngd_master_worker @ 00106418 size=744
// signature: undefined qcom_slim_ngd_master_worker(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_ngd_master_worker(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  uStack_70 = 0;
  local_50 = 0x101c5d9;
  local_60 = &local_88;
  uStack_80 = 0;
  local_88 = 0x40000;
  uStack_58 = 0;
  local_78 = &local_50;
  local_68 = 0xff00000000010608;
  __slimbus_dbg("qcom_slim_ngd_master_worker","SLIM SAT: Rcvd master capability\n");
  iVar2 = *(int *)(param_1 + 0x234);
  if (2 < iVar2) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x240),"SLIM SAT: Rcvd master capability\n");
    iVar2 = *(int *)(param_1 + 0x234);
  }
  if (iVar2 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x248),"SLIM SAT: Rcvd master capability\n");
  }
  iVar2 = 10;
  while (iVar1 = qcom_slim_ngd_xfer_msg(param_1 + -0xfe8,&local_68), iVar1 == -5) {
    __slimbus_dbg("qcom_slim_ngd_master_worker","capability message NACKed, retrying\n");
    iVar1 = *(int *)(param_1 + 0x234);
    if (1 < iVar1) {
      _printk(&DAT_00107f69);
      ipc_log_string(*(undefined8 *)(param_1 + 0x240),"capability message NACKed, retrying\n");
      iVar1 = *(int *)(param_1 + 0x234);
    }
    if (iVar1 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x248),"capability message NACKed, retrying\n");
    }
    if (iVar2 == 0) goto LAB_0010669c;
    msleep(10);
    iVar2 = iVar2 + -1;
  }
  if (iVar1 == 0) {
    __slimbus_dbg("qcom_slim_ngd_master_worker","SLIM SAT: capability exchange successful\n");
    iVar2 = *(int *)(param_1 + 0x234);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x240),"SLIM SAT: capability exchange successful\n");
      iVar2 = *(int *)(param_1 + 0x234);
    }
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x248),"SLIM SAT: capability exchange successful\n");
    }
    if (*(uint *)(param_1 + 0x1d8) < 2) {
      __slimbus_dbg("qcom_slim_ngd_master_worker","capability due to noise, Unexpected state:%d\n");
      iVar2 = *(int *)(param_1 + 0x234);
      if (1 < iVar2) {
        _printk(&DAT_00108293,*(undefined4 *)(param_1 + 0x1d8));
        ipc_log_string(*(undefined8 *)(param_1 + 0x240),
                       "capability due to noise, Unexpected state:%d\n",
                       *(undefined4 *)(param_1 + 0x1d8));
        iVar2 = *(int *)(param_1 + 0x234);
      }
      if (iVar2 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x248),
                       "capability due to noise, Unexpected state:%d\n",
                       *(undefined4 *)(param_1 + 0x1d8));
      }
    }
    else {
      complete(param_1 + -0x40);
    }
    if (*(int *)(param_1 + 0x1d8) == 3) {
      lVar3 = of_get_next_child(*(undefined8 *)(**(long **)(param_1 + -0xba8) + 0x2f8),0);
      if (lVar3 != 0) {
        do {
          lVar4 = of_slim_get_device(param_1 + -0xfe8,lVar3);
          if ((lVar4 != 0) && (iVar2 = slim_get_logical_addr(), iVar2 != 0)) {
            _dev_err(*(undefined8 *)(param_1 + -0xba0),"Failed to get logical address\n");
          }
          lVar3 = of_get_next_child(*(undefined8 *)(**(long **)(param_1 + -0xba8) + 0x2f8),lVar3);
        } while (lVar3 != 0);
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + -0xba0),"SLIM: capability TX failed:%d\n",iVar1);
  }
LAB_0010669c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_up_worker @ 00106704 size=168
// signature: undefined qcom_slim_ngd_up_worker(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_ngd_up_worker(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = wait_for_completion_interruptible_timeout(param_1 + 0x38,0xfa);
  if (lVar1 == 0) {
    __slimbus_dbg("qcom_slim_ngd_up_worker","QMI wait timeout\n");
    iVar2 = *(int *)(param_1 + 0x204);
    if (2 < iVar2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x210),"QMI wait timeout\n");
      iVar2 = *(int *)(param_1 + 0x204);
    }
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x218),"QMI wait timeout\n");
    }
  }
  else {
    mutex_lock(param_1 + 0x120);
    qcom_slim_ngd_enable(param_1 + -0x13b8,1);
    mutex_unlock(param_1 + 0x120);
  }
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_qmi_new_server @ 001067b0 size=148
// signature: undefined qcom_slim_ngd_qmi_new_server(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_qmi_new_server(long param_1,long param_2)

{
  int iVar1;
  
  __slimbus_dbg("qcom_slim_ngd_qmi_new_server","Slimbus QMI new server event received\n");
  iVar1 = *(int *)(param_1 + 0xf54);
  if (2 < iVar1) {
    ipc_log_string(*(undefined8 *)(param_1 + 0xf60),"Slimbus QMI new server event received\n");
    iVar1 = *(int *)(param_1 + 0xf54);
  }
  if (iVar1 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0xf68),"Slimbus QMI new server event received\n");
  }
  *(undefined2 *)(param_1 + -0x10) = 0x2a;
  *(undefined4 *)(param_1 + -0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + -8) = *(undefined4 *)(param_2 + 0x10);
  complete(param_1 + 0xd88);
  return 0;
}



//------------------------------------------------------------
// qcom_slim_ngd_qmi_del_server @ 00106848 size=116
// signature: undefined qcom_slim_ngd_qmi_del_server(void)
// callers: []
//------------------------------------------------------------

void qcom_slim_ngd_qmi_del_server(long param_1)

{
  int iVar1;
  
  __slimbus_dbg("qcom_slim_ngd_qmi_del_server","Slimbus QMI del server event received\n");
  iVar1 = *(int *)(param_1 + 0xf54);
  if (2 < iVar1) {
    ipc_log_string(*(undefined8 *)(param_1 + 0xf60),"Slimbus QMI del server event received\n");
    iVar1 = *(int *)(param_1 + 0xf54);
  }
  if (iVar1 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0xf68),"Slimbus QMI del server event received\n");
  }
  *(undefined4 *)(param_1 + 0xd88) = 0;
  *(undefined8 *)(param_1 + -0xc) = 0;
  return;
}



//------------------------------------------------------------
// qcom_slim_ngd_runtime_idle @ 001068c0 size=144
// signature: undefined qcom_slim_ngd_runtime_idle(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_slim_ngd_runtime_idle(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar2 + 0x1560) == 0) {
    *(undefined4 *)(lVar2 + 0x1560) = 1;
  }
  __slimbus_dbg("qcom_slim_ngd_runtime_idle","pm_runtime: idle...\n");
  iVar1 = *(int *)(lVar2 + 0x15bc);
  if (3 < iVar1) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x15c8),"pm_runtime: idle...\n");
    iVar1 = *(int *)(lVar2 + 0x15bc);
  }
  if (iVar1 == 0) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x15d0),"pm_runtime: idle...\n");
  }
  __pm_runtime_suspend(param_1,9);
  return 0xfffffff5;
}



//------------------------------------------------------------
// init_module @ 0010698c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_slim_ngd_ctrl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001069bc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_slim_ngd_ctrl_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 0010b000 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_slimbus_dbg, trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010b008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010b010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_slimbus_dbg, trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 0010b018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [perf_trace_slimbus_dbg, trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010b020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010b028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010b030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_slim_ngd_disable_stream, qcom_slim_qmi_power_request, qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_get_laddr, perf_trace_slimbus_dbg, qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_enable, qcom_slim_ngd_master_worker, __slimbus_dbg, qcom_slim_ngd_setup, qcom_slim_ngd_enable_stream, trace_event_raw_event_slimbus_dbg, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010b038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010b040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0010b048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010b068 size=1
// signature: undefined __platform_driver_register(void)
// callers: [qcom_slim_ngd_ctrl_probe, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010b070 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module, qcom_slim_ngd_ctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0010b078 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010b080 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010b088 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_slimbus_dbg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010b090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 0010b098 size=1
// signature: undefined platform_get_resource(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0010b0a0 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0010b0a8 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010b0b0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 0010b0b8 size=1
// signature: undefined dev_err_probe(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0010b0c0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010b0c8 size=1
// signature: undefined dma_set_mask(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010b0d0 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010b0d8 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010b0e0 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010b0e8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010b0f0 size=1
// signature: undefined ipc_log_string(void)
// callers: [qcom_slim_ngd_qmi_del_server, qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_disable_stream, qcom_slim_ngd_up_worker, qcom_slim_qmi_power_request, qcom_slim_ngd_ctrl_probe, qcom_ngd_set_suspend, qcom_slim_ngd_exit_dma, qcom_slim_ngd_get_laddr, qcom_slim_ngd_runtime_resume, qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_enable, qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_interrupt, qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_master_worker, qcom_slim_ngd_probe, qcom_slim_ngd_ssr_pdr_notify, qcom_slim_ngd_setup, qcom_slim_ngd_enable_stream, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post, qcom_slim_ngd_qmi_new_server, qcom_slim_ngd_runtime_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010b0f8 size=1
// signature: undefined scnprintf(void)
// callers: [qcom_slim_ngd_ctrl_probe, debug_mask_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0010b100 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 0010b108 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010b110 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010b118 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_alloc @ 0010b120 size=1
// signature: undefined pdr_handle_alloc(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_add_lookup @ 0010b128 size=1
// signature: undefined pdr_add_lookup(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 0010b130 size=1
// signature: undefined of_match_node(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010b138 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010b140 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010b150 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0010b158 size=1
// signature: undefined platform_device_alloc(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_set_override @ 0010b160 size=1
// signature: undefined driver_set_override(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_set_override(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010b168 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_enable, qcom_slim_ngd_master_worker, qcom_slim_ngd_probe, qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_setup, qcom_slim_ngd_tx_msg_post, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0010b170 size=1
// signature: undefined platform_device_add(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0010b178 size=1
// signature: undefined platform_device_put(void)
// callers: [qcom_slim_ngd_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010b180 size=1
// signature: undefined kfree(void)
// callers: [qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_release @ 0010b188 size=1
// signature: undefined pdr_handle_release(void)
// callers: [qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 0010b190 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0010b198 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_ctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 0010b1a0 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [qcom_slim_ngd_ctrl_probe, qcom_slim_ngd_ctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010b1a8 size=1
// signature: undefined _printk(void)
// callers: [qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_disable_stream, qcom_slim_qmi_power_request, qcom_slim_ngd_ctrl_probe, qcom_slim_qmi_power_resp_cb, qcom_slim_ngd_runtime_resume, qcom_slim_ngd_enable, qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_interrupt, qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_master_worker, qcom_slim_ngd_enable_stream, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_alloc_txn_tid @ 0010b1b0 size=1
// signature: undefined slim_alloc_txn_tid(void)
// callers: [qcom_slim_ngd_disable_stream, qcom_slim_ngd_enable_stream, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_get_laddr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_alloc_txn_tid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_free_txn_tid @ 0010b1b8 size=1
// signature: undefined slim_free_txn_tid(void)
// callers: [qcom_slim_ngd_disable_stream, qcom_slim_ngd_enable_stream, qcom_slim_ngd_get_laddr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_free_txn_tid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010b1c0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [qcom_ngd_set_suspend, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010b1c8 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_probe, qcom_ngd_set_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010b1d0 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [qcom_slim_ngd_probe, qcom_ngd_set_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 0010b1d8 size=1
// signature: undefined mutex_trylock(void)
// callers: [qcom_slim_ngd_xfer_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010b1e0 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qcom_slim_ngd_xfer_msg_sync, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010b1e8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_setup, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010b1f0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_setup, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_tx_msg_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010b1f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_up_worker, qcom_slim_qmi_power_request, qcom_slim_ngd_ssr_pdr_notify, qcom_slim_ngd_xfer_msg, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 0010b200 size=1
// signature: undefined __memcpy_toio(void)
// callers: [qcom_slim_ngd_xfer_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010b208 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_slim_ngd_xfer_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010b210 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010b218 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010b220 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010b228 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010b238 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_up_worker, qcom_slim_qmi_power_request, qcom_slim_ngd_ssr_pdr_notify, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 0010b248 size=1
// signature: undefined device_for_each_child(void)
// callers: [qcom_slim_ngd_ssr_pdr_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010b258 size=1
// signature: undefined queue_work_on(void)
// callers: [qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_ssr_pdr_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_report_absent @ 0010b268 size=1
// signature: undefined slim_report_absent(void)
// callers: [qcom_slim_ngd_update_device_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_report_absent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_release_channel @ 0010b270 size=1
// signature: undefined dma_release_channel(void)
// callers: [qcom_slim_ngd_setup, qcom_slim_ngd_exit_dma]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_release_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0010b278 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qcom_slim_ngd_setup, qcom_slim_ngd_exit_dma]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 0010b280 size=1
// signature: undefined qmi_handle_release(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010b288 size=1
// signature: undefined devm_kfree(void)
// callers: [qcom_slim_ngd_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 0010b290 size=1
// signature: undefined qmi_handle_init(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_connect @ 0010b298 size=1
// signature: undefined kernel_connect(void)
// callers: [qcom_slim_ngd_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 0010b2a0 size=1
// signature: undefined qmi_txn_init(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_qmi_power_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 0010b2a8 size=1
// signature: undefined qmi_send_request(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_qmi_power_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 0010b2b0 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_qmi_power_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010b2b8 size=1
// signature: undefined complete(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_tx_msg_dma_cb, qcom_slim_ngd_master_worker, qcom_slim_qmi_power_resp_cb, qcom_slim_ngd_qmi_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010b2c0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_ngd_xfer_msg_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010b2c8 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010b2d0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [qcom_slim_ngd_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 0010b2d8 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [qcom_slim_ngd_enable, qcom_slim_qmi_power_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0010b2e0 size=1
// signature: undefined enable_irq(void)
// callers: [qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010b2e8 size=1
// signature: undefined complete_all(void)
// callers: [qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0010b2f0 size=1
// signature: undefined disable_irq(void)
// callers: [qcom_slim_ngd_runtime_suspend, qcom_slim_ngd_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_request_chan @ 0010b2f8 size=1
// signature: undefined dma_request_chan(void)
// callers: [qcom_slim_ngd_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_request_chan(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 0010b300 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qcom_slim_ngd_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 0010b308 size=1
// signature: undefined __memset_io(void)
// callers: [qcom_slim_ngd_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 0010b310 size=1
// signature: undefined sg_init_table(void)
// callers: [qcom_slim_ngd_rx_msgq_cb, qcom_slim_ngd_setup, qcom_slim_ngd_tx_msg_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_msg_response @ 0010b318 size=1
// signature: undefined slim_msg_response(void)
// callers: [qcom_slim_ngd_rx_msgq_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_msg_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_register_controller @ 0010b320 size=1
// signature: undefined slim_register_controller(void)
// callers: [qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_register_controller(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010b328 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010b330 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010b338 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 0010b340 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [qcom_slim_ngd_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0010b348 size=1
// signature: undefined destroy_workqueue(void)
// callers: [qcom_slim_ngd_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_unregister_controller @ 0010b350 size=1
// signature: undefined slim_unregister_controller(void)
// callers: [qcom_slim_ngd_probe, qcom_slim_ngd_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_unregister_controller(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010b358 size=1
// signature: undefined msleep(void)
// callers: [qcom_slim_ngd_master_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 0010b360 size=1
// signature: undefined of_get_next_child(void)
// callers: [qcom_slim_ngd_master_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_slim_get_device @ 0010b368 size=1
// signature: undefined of_slim_get_device(void)
// callers: [qcom_slim_ngd_master_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_slim_get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// slim_get_logical_addr @ 0010b370 size=1
// signature: undefined slim_get_logical_addr(void)
// callers: [qcom_slim_ngd_master_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void slim_get_logical_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible_timeout @ 0010b378 size=1
// signature: undefined wait_for_completion_interruptible_timeout(void)
// callers: [qcom_slim_ngd_up_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010b380 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [qcom_slim_ngd_runtime_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



