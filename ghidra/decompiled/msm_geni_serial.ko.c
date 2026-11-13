// Decompiled by Ghidra 12.2
// Program: msm_geni_serial.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_serial_info @ 00101ca4 size=116
// signature: undefined __traceiter_serial_info(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_serial_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0010f500;
  plVar2 = DAT_0010f500;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101cf4);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_serial_info @ 00101d1c size=312
// signature: undefined trace_event_raw_event_serial_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_serial_info(long param_1,char *param_2,undefined8 *param_3)

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
    lVar5 = trace_event_buffer_reserve(&local_78,param_1,(long)(iVar3 + 0xc9) + 0x10);
    if (lVar5 != 0) {
      *(int *)(lVar5 + 8) = iVar3 * 0x10000 + 0x10010;
      *(uint *)(lVar5 + 0xc) = iVar3 + 0x11U | 0xc80000;
      strcpy((char *)(lVar5 + 0x10),__s);
      puVar1 = (undefined8 *)param_3[1];
      local_88 = puVar1[2];
      uStack_80 = puVar1[3];
      local_98 = *puVar1;
      uStack_90 = puVar1[1];
      iVar3 = vsnprintf((char *)(lVar5 + (ulong)(iVar3 + 0x11U & 0xffff)),200,(char *)*param_3,
                        &local_98);
      if (199 < iVar3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101e50);
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
// perf_trace_serial_info @ 00101e5c size=388
// signature: undefined perf_trace_serial_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_serial_info(long param_1,char *param_2,undefined8 *param_3)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  undefined8 *puVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  size_t sVar7;
  long lVar8;
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
  plVar1 = (long *)(lVar8 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar6 = (int)sVar7;
    iVar4 = (iVar6 + 0xe4U & 0xfffffff8) - 4;
    lVar8 = perf_trace_buf_alloc(iVar4,&local_60,&local_64);
    if (lVar8 != 0) {
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xe8) = auStack_90 + 0x40;
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(undefined1 **)(local_60 + 0xf8) = auStack_90;
      *(int *)(lVar8 + 8) = iVar6 * 0x10000 + 0x10010;
      *(uint *)(lVar8 + 0xc) = iVar6 + 0x11U | 0xc80000;
      strcpy((char *)(lVar8 + 0x10),__s);
      puVar3 = (undefined8 *)param_3[1];
      local_78 = puVar3[2];
      uStack_70 = puVar3[3];
      local_88 = *puVar3;
      uStack_80 = puVar3[1];
      iVar6 = vsnprintf((char *)(lVar8 + (ulong)(iVar6 + 0x11U & 0xffff)),200,(char *)*param_3,
                        &local_88);
      if (199 < iVar6) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101fdc);
        (*pcVar5)();
      }
      perf_trace_run_bpf_submit(lVar8,iVar4,local_64,param_1,1,local_60,plVar1,0);
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
// __bpf_trace_serial_info @ 00101fe8 size=28
// signature: undefined __bpf_trace_serial_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_serial_info(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// geni_se_dump_dbg_regs @ 00102008 size=1772
// signature: undefined geni_se_dump_dbg_regs(void)
// callers: [stop_rx_sequencer, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_serial_ioctl, wait_for_transfers_inflight, handle_rx_dma_xfer]
//------------------------------------------------------------

void geni_se_dump_dbg_regs(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  undefined4 uVar51;
  undefined4 uVar52;
  undefined4 uVar53;
  undefined4 uVar54;
  long lVar55;
  
  lVar55 = *(long *)(param_1 + 0x10);
  if (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2 &&
      *(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Device is suspended, Return\n",
                   "geni_se_dump_dbg_regs");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Device is suspended, Return\n",
                 "geni_se_dump_dbg_regs");
  }
  else {
    uVar1 = *(undefined4 *)(lVar55 + 0x600);
    uVar2 = *(undefined4 *)(lVar55 + 0x610);
    uVar3 = *(undefined4 *)(lVar55 + 0x640);
    uVar4 = *(undefined4 *)(lVar55 + 0x40);
    uVar5 = *(undefined4 *)(lVar55 + 0x908);
    uVar6 = *(undefined4 *)(lVar55 + 0xc40);
    uVar7 = *(undefined4 *)(lVar55 + 0xd40);
    uVar8 = *(undefined4 *)(lVar55 + 0x804);
    uVar9 = *(undefined4 *)(lVar55 + 0x800);
    uVar10 = *(undefined4 *)(lVar55 + 0xe40);
    uVar11 = *(undefined4 *)(lVar55 + 0x604);
    uVar12 = *(undefined4 *)(lVar55 + 0xd3c);
    uVar13 = *(undefined4 *)(lVar55 + 0xd54);
    uVar14 = *(undefined4 *)(lVar55 + 0xc3c);
    uVar15 = *(undefined4 *)(lVar55 + 0xc54);
    uVar16 = *(undefined4 *)(lVar55 + 0x614);
    uVar17 = *(undefined4 *)(lVar55 + 0x644);
    uVar18 = *(undefined4 *)(lVar55 + 0xc48);
    uVar19 = *(undefined4 *)(lVar55 + 0xd48);
    uVar20 = *(undefined4 *)(lVar55 + 0x48);
    uVar21 = *(undefined4 *)(lVar55 + 0x4c);
    uVar22 = *(undefined4 *)(lVar55 + 0x22c);
    uVar23 = *(undefined4 *)(lVar55 + 0x240);
    uVar24 = *(undefined4 *)(lVar55 + 0x248);
    uVar25 = *(undefined4 *)(lVar55 + 0x25c);
    uVar26 = *(undefined4 *)(lVar55 + 0x280);
    uVar27 = *(undefined4 *)(lVar55 + 0x268);
    uVar28 = *(undefined4 *)(lVar55 + 0x26c);
    uVar29 = *(undefined4 *)(lVar55 + 0x270);
    uVar30 = *(undefined4 *)(lVar55 + 0x28c);
    uVar31 = *(undefined4 *)(lVar55 + 0x294);
    uVar32 = *(undefined4 *)(lVar55 + 0x2a4);
    uVar33 = *(undefined4 *)(lVar55 + 0x2a8);
    uVar34 = *(undefined4 *)(lVar55 + 0x2ac);
    uVar35 = *(undefined4 *)(lVar55 + 0x80c);
    uVar36 = *(undefined4 *)(lVar55 + 0x810);
    uVar37 = *(undefined4 *)(lVar55 + 0x814);
    uVar38 = *(undefined4 *)(lVar55 + 0x10);
    uVar39 = *(undefined4 *)(lVar55 + 0x624);
    uVar40 = *(undefined4 *)(lVar55 + 0x628);
    uVar41 = *(undefined4 *)(lVar55 + 0xd54);
    uVar42 = *(undefined4 *)(lVar55 + 0x910);
    uVar43 = *(undefined4 *)(lVar55 + 0x914);
    uVar44 = *(undefined4 *)(lVar55 + 0xc30);
    uVar45 = *(undefined4 *)(lVar55 + 0xc34);
    uVar46 = *(undefined4 *)(lVar55 + 0xc38);
    uVar47 = *(undefined4 *)(lVar55 + 0xc5c);
    uVar48 = *(undefined4 *)(lVar55 + 0xd30);
    uVar49 = *(undefined4 *)(lVar55 + 0xd34);
    uVar50 = *(undefined4 *)(lVar55 + 0xd38);
    uVar51 = *(undefined4 *)(lVar55 + 0xd5c);
    uVar52 = *(undefined4 *)(lVar55 + 4);
    uVar53 = *(undefined4 *)(lVar55 + 0x60);
    uVar54 = *(undefined4 *)(lVar55 + 100);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                   "geni_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                 "geni_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",uVar7,
                   uVar6,uVar8,uVar9);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",uVar7,
                 uVar6,uVar8,uVar9);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",uVar10,
                   uVar11,uVar12,uVar13);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",uVar10,
                 uVar11,uVar12,uVar13);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",uVar14,uVar15,uVar3);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",uVar14,uVar15,uVar3);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                   uVar18,uVar19,uVar16,uVar17);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                 uVar18,uVar19,uVar16,uVar17);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "ser_m_clk_cfg:0x%x, ser_s_clk_cfg:0x%x loopback_cfg:0x%x io_macro_ctrl:0x%x\n",
                   uVar20,uVar21,uVar22,uVar23);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "ser_m_clk_cfg:0x%x, ser_s_clk_cfg:0x%x loopback_cfg:0x%x io_macro_ctrl:0x%x\n",
                 uVar20,uVar21,uVar22,uVar23);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "io3_val:0x%x, tx_trans_cfg:0x%x rx_trans_cfg:0x%x tx_word_len:0x%x\n",uVar24,
                   uVar25,uVar26,uVar27);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "io3_val:0x%x, tx_trans_cfg:0x%x rx_trans_cfg:0x%x tx_word_len:0x%x\n",uVar24,
                 uVar25,uVar26,uVar27);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "stop_bit_len:0x%x, tx_trans_len:0x%x rx_word_len:0x%x rx_stale_cnt:0x%x\n",
                   uVar28,uVar29,uVar30,uVar31);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "stop_bit_len:0x%x, tx_trans_len:0x%x rx_word_len:0x%x rx_stale_cnt:0x%x\n",uVar28,
                 uVar29,uVar30,uVar31);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "tx_parity_cfg:0x%x, rx_parity_cfg:0x%x manual_rfr:0x%x tx_watermark:0x%x\n",
                   uVar32,uVar33,uVar34,uVar35);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "tx_parity_cfg:0x%x, rx_parity_cfg:0x%x manual_rfr:0x%x tx_watermark:0x%x\n",uVar32
                 ,uVar33,uVar34,uVar35);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "rx_watermark:0x%x, rx_watermark_rfr:0x%x se_geni_general_cfg:0x%x m_cmd_err:0x%x\n"
                   ,uVar36,uVar37,uVar38,uVar39);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "rx_watermark:0x%x, rx_watermark_rfr:0x%x se_geni_general_cfg:0x%x m_cmd_err:0x%x\n"
                 ,uVar36,uVar37,uVar38,uVar39);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "m_fw_err:0x%x, rx_len_in:0x%x m_gp_length:0x%x s_gp_length:0x%x\n",uVar40,uVar41
                   ,uVar42,uVar43);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "m_fw_err:0x%x, rx_len_in:0x%x m_gp_length:0x%x s_gp_length:0x%x\n",uVar40,uVar41,
                 uVar42,uVar43);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_tx_ptr_l:0x%x, dma_tx_ptr_h:0x%x dma_tx_attr:0x%x dma_tx_max_burst_size:0x%x\n"
                   ,uVar44,uVar45,uVar46,uVar47);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_tx_ptr_l:0x%x, dma_tx_ptr_h:0x%x dma_tx_attr:0x%x dma_tx_max_burst_size:0x%x\n"
                 ,uVar44,uVar45,uVar46,uVar47);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_rx_ptr_l:0x%x, dma_rx_ptr_h:0x%x dma_rx_attr:0x%x dma_rx_max_burst_size:0x%x\n"
                   ,uVar48,uVar49,uVar50,uVar51);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_rx_ptr_l:0x%x, dma_rx_ptr_h:0x%x dma_rx_attr:0x%x dma_rx_max_burst_size:0x%x\n"
                 ,uVar48,uVar49,uVar50,uVar51);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "dma_if_en:0x%x, geni_clk_ctrl:0x%x fifo_if_disable:0x%x\n",uVar52,uVar53,uVar54)
    ;
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "dma_if_en:0x%x, geni_clk_ctrl:0x%x fifo_if_disable:0x%x\n",uVar52,uVar53,uVar54);
  }
  return;
}



//------------------------------------------------------------
// __ftrace_dbg @ 001026f4 size=136
// signature: undefined __ftrace_dbg(void)
// callers: [geni_se_dump_dbg_regs, msm_geni_allocate_chan, msm_geni_wakeup_work, msm_geni_serial_runtime_resume, msm_geni_uart_gsi_tx_cb, msm_geni_serial_ioctl, msm_geni_serial_power_on, msm_geni_serial_enable_interrupts, msm_geni_serial_stop_rx, msm_geni_serial_cons_pm, hs_uart_operation_store, msm_geni_serial_sys_hib_resume, msm_geni_serial_get_mctrl, msm_geni_uart_gsi_rx_cb, msm_geni_serial_config_baud_rate, msm_geni_serial_set_termios, stop_rx_sequencer, msm_geni_serial_hs_pm, msm_geni_serial_handle_dma_tx, msm_geni_uart_ev_cb, msm_geni_serial_resources_off, start_rx_sequencer, msm_geni_serial_sys_suspend, wait_for_transfers_inflight, msm_geni_serial_ssr_down, msm_geni_wakeup_isr, xfer_mode_store, msm_geni_check_stop_engine, msm_geni_uart_gsi_cancel_rx, msm_geni_serial_set_mctrl, msm_geni_serial_probe, msm_geni_serial_start_tx, msm_serial_try_disable_interrupts, msm_geni_serial_allow_rx, geni_wait_for_cmd_done, msm_geni_serial_break_ctl, stop_tx_sequencer, msm_geni_serial_ssr_up, msm_geni_update_uart_error_code, msm_geni_serial_set_manual_flow, msm_geni_serial_sys_resume, msm_geni_serial_resources_on, handle_rx_hs, msm_geni_serial_handle_isr, msm_geni_uart_gsi_xfer_tx, hs_uart_version_show, msm_geni_serial_stop_tx, msm_geni_serial_shutdown, msm_geni_serial_startup, msm_geni_serial_runtime_suspend, msm_geni_serial_prep_dma_tx, msm_geni_serial_port_setup, msm_geni_serial_flush, handle_rx_dma_xfer]
//------------------------------------------------------------

void __ftrace_dbg(void)

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
// msm_geni_serial_resources_on @ 00102820 size=460
// signature: undefined msm_geni_serial_resources_on(void)
// callers: [msm_geni_serial_hs_pm, msm_geni_serial_runtime_resume, msm_geni_serial_cons_pm]
//------------------------------------------------------------

int msm_geni_serial_resources_on(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  
  lVar5 = *(long *)(param_1 + 0x3b8);
  if (lVar5 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_resources_on",uVar2,
                   uVar2 / 1000);
  }
  if (param_1 == -0x268) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x290),*(undefined8 *)(param_1 + 0x2a0));
    if (iVar1 == 0) {
      iVar1 = geni_icc_enable(param_1 + 0x2b8);
      if (iVar1 == 0) {
        iVar1 = geni_icc_set_bw(param_1 + 0x2b8);
        if (iVar1 == 0) {
          iVar1 = geni_se_common_clks_on
                            (*(undefined8 *)(param_1 + 0x278),*(undefined8 *)(param_1 + 0x280),
                             *(undefined8 *)(param_1 + 0x288));
          if (iVar1 == 0) {
            lVar5 = *(long *)(param_1 + 0x3b8);
            if (((lVar5 != 0) && (uVar2 != 0)) && (*(int *)(param_1 + 900) != 0)) {
              lVar4 = sched_clock();
              ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_resources_on",
                             lVar4 - uVar2,(lVar4 - uVar2) / 1000);
            }
            *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x24) = 0x7f;
            __const_udelay(0xa7c6);
            return 0;
          }
          uVar3 = *(undefined8 *)(param_1 + 0x3b0);
          pcVar6 = "%s: Error %d geni_se_common_clks_on failed\n";
        }
        else {
          uVar3 = *(undefined8 *)(param_1 + 0x3b0);
          pcVar6 = "%s: Error %d ICC BW voting failed\n";
        }
      }
      else {
        uVar3 = *(undefined8 *)(param_1 + 0x3b0);
        pcVar6 = "%s: Error %d geni_icc_enable failed\n";
      }
    }
    else {
      uVar3 = *(undefined8 *)(param_1 + 0x3b0);
      pcVar6 = "%s: Error %d pinctrl_select_state failed\n";
    }
    ipc_log_string(uVar3,pcVar6,"msm_geni_serial_resources_on",iVar1);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar6,"msm_geni_serial_resources_on",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// geni_se_common_clks_on @ 001029ec size=192
// signature: undefined geni_se_common_clks_on(void)
// callers: [msm_geni_serial_resources_on, msm_geni_serial_probe]
//------------------------------------------------------------

int geni_se_common_clks_on(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = clk_prepare(param_2);
  if (iVar1 == 0) {
    iVar1 = clk_enable(param_2);
    if (iVar1 == 0) {
      iVar1 = clk_prepare(param_3);
      if (iVar1 == 0) {
        iVar1 = clk_enable(param_3);
        if (iVar1 == 0) {
          iVar1 = clk_prepare(param_1);
          if (iVar1 == 0) {
            iVar1 = clk_enable(param_1);
            if (iVar1 == 0) {
              return 0;
            }
            clk_unprepare(param_1);
          }
          clk_disable(param_3);
        }
        clk_unprepare(param_3);
      }
      clk_disable(param_2);
    }
    clk_unprepare(param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_geni_serial_resources_off @ 00102ab0 size=288
// signature: undefined msm_geni_serial_resources_off(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_hs_pm, msm_geni_serial_cons_pm]
//------------------------------------------------------------

int msm_geni_serial_resources_off(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (param_1 == -0x268) {
    return -0x16;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x278);
  uVar3 = *(undefined8 *)(param_1 + 0x280);
  uVar5 = *(undefined8 *)(param_1 + 0x288);
  clk_disable(uVar2);
  clk_unprepare(uVar2);
  clk_disable(uVar3);
  clk_unprepare(uVar3);
  clk_disable(uVar5);
  clk_unprepare(uVar5);
  iVar1 = geni_icc_disable(param_1 + 0x2b8);
  if (iVar1 == 0) {
    if (((*(ulong *)(param_1 + 0x298) == 0) || (0xfffffffffffff000 < *(ulong *)(param_1 + 0x298)))
       || (*(int *)(param_1 + 0x808) != 0)) {
      iVar1 = pinctrl_select_state
                        (*(undefined8 *)(param_1 + 0x290),*(undefined8 *)(param_1 + 0x2a8));
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = *(undefined8 *)(param_1 + 0x3b0);
      pcVar4 = "%s: Error %d pinctrl sleep failed\n";
    }
    else {
      iVar1 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x290));
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = *(undefined8 *)(param_1 + 0x3b0);
      pcVar4 = "%s: Error %d pinctrl shutdown state failed\n";
    }
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x3b0);
    pcVar4 = "%s: Error %d geni_icc_disable failed\n";
  }
  ipc_log_string(uVar2,pcVar4,"msm_geni_serial_resources_off",iVar1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar4,"msm_geni_serial_resources_off",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// trace_raw_output_serial_info @ 00102bd4 size=112
// signature: undefined trace_raw_output_serial_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_serial_info(long param_1,undefined8 param_2,undefined8 param_3)

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
// msm_geni_serial_tx_empty @ 00102c48 size=108
// signature: undefined msm_geni_serial_tx_empty(void)
// callers: []
//------------------------------------------------------------

bool msm_geni_serial_tx_empty(long param_1)

{
  uint uVar1;
  
  if (((*(long *)(param_1 + 0x100) == 0) ||
      (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2 &&
      *(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0)) {
    return true;
  }
  if (*(int *)(param_1 + 0x238) == 2) {
    uVar1 = (uint)(*(long *)(param_1 + 0x318) != 0);
  }
  else {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x10) + 0x800);
  }
  return uVar1 == 0;
}



//------------------------------------------------------------
// msm_geni_serial_set_mctrl @ 00102cb8 size=492
// signature: undefined msm_geni_serial_set_mctrl(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_set_mctrl(long param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  long lVar3;
  bool bVar4;
  undefined8 uVar5;
  
  if (*(char *)(param_1 + 0x840) != '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_set_mctrl");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_set_mctrl");
    return;
  }
  if (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2 &&
      *(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0) {
    lVar3 = sp_el0;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended, %s: mctrl=0x%x\n",
                   "msm_geni_serial_set_mctrl",lVar3 + 0x848,param_2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended, %s: mctrl=0x%x\n",
                 "msm_geni_serial_set_mctrl",lVar3 + 0x848,param_2);
    return;
  }
  bVar4 = (param_2 & 4) == 0;
  uVar2 = 0x80000002;
  if (!bVar4) {
    uVar2 = 0;
  }
  *(bool *)(param_1 + 0x3e0) = bVar4;
  *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac) = uVar2;
  DataSynchronizationBarrier(3,3,0);
  if (*(char *)(param_1 + 0x3e0) == '\0') {
    if ((*(int *)(param_1 + 0x450) != 0x15) || (*(char *)(param_1 + 0x3fc) != '\0'))
    goto LAB_00102e10;
    uVar5 = 0;
    *(undefined4 *)(param_1 + 0x450) = 0;
  }
  else {
    if (*(char *)(param_1 + 0x3fc) != '\0') goto LAB_00102e10;
    uVar5 = 0x15;
    *(undefined4 *)(param_1 + 0x450) = 0x15;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                 "msm_geni_update_uart_error_code",uVar5);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
               "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
LAB_00102e10:
  lVar3 = sp_el0;
  puVar1 = &DAT_0010ff55;
  if (*(char *)(param_1 + 0x3e0) != '\0') {
    puVar1 = &DAT_0010f9c7;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:%s, mctrl=0x%x, manual_rfr=0x%x, flow=%s\n",
                 "msm_geni_serial_set_mctrl",lVar3 + 0x848,param_2,uVar2,puVar1);
  puVar1 = &DAT_0010ff55;
  if (*(char *)(param_1 + 0x3e0) != '\0') {
    puVar1 = &DAT_0010f9c7;
  }
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:%s, mctrl=0x%x, manual_rfr=0x%x, flow=%s\n",
               "msm_geni_serial_set_mctrl",lVar3 + 0x848,param_2,uVar2,puVar1);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_get_mctrl @ 00102ea8 size=572
// signature: undefined msm_geni_serial_get_mctrl(void)
// callers: []
//------------------------------------------------------------

uint msm_geni_serial_get_mctrl(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 0x840) != '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_get_mctrl");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_get_mctrl");
    return 0;
  }
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    iVar4 = mutex_trylock(param_1 + 0x888);
    if (iVar4 == 0) {
      lVar3 = sp_el0;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is being suspended, %s\n",
                     "msm_geni_serial_get_mctrl",lVar3 + 0x848);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is being suspended, %s\n",
                   "msm_geni_serial_get_mctrl",lVar3 + 0x848);
      return 0x140;
    }
    if ((*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2) &&
       (*(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0)) {
      lVar3 = sp_el0;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended, %s\n",
                     "msm_geni_serial_get_mctrl",lVar3 + 0x848);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended, %s\n",
                   "msm_geni_serial_get_mctrl",lVar3 + 0x848);
      mutex_unlock(param_1 + 0x888);
      return 0x160;
    }
  }
  uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x908);
  if ((uVar2 >> 1 & 1) == 0) {
    uVar5 = 0x160;
  }
  else {
    if (((*(long *)(param_1 + 0x100) == 0) ||
        (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
       (*(char *)(param_1 + 0x3fc) == '\0')) {
      *(undefined4 *)(param_1 + 0x450) = 0x14;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x14);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
    }
    uVar5 = 0x140;
  }
  uVar1 = uVar5 | 4;
  if (*(char *)(param_1 + 0x3e0) != '\0') {
    uVar1 = uVar5;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: geni_ios:0x%x, mctrl:0x%x\n",
                 "msm_geni_serial_get_mctrl",uVar2,uVar1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: geni_ios:0x%x, mctrl:0x%x\n",
               "msm_geni_serial_get_mctrl",uVar2,uVar1);
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    mutex_unlock(param_1 + 0x888);
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_geni_serial_stop_tx @ 001030e8 size=164
// signature: undefined msm_geni_serial_stop_tx(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_stop_tx(long param_1)

{
  long lVar1;
  
  if (((*(long *)(param_1 + 0x100) == 0) ||
      (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (lVar1 = *(long *)(param_1 + 0x150),
     *(int *)(lVar1 + 0x20c) == 2 && *(int *)(lVar1 + 0x1f8) == 0)) {
    _dev_err(lVar1,"%s.Device is suspended.\n","msm_geni_serial_stop_tx");
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended.\n",
                   "msm_geni_serial_stop_tx");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended.\n",
                 "msm_geni_serial_stop_tx");
  }
  else {
    stop_tx_sequencer(param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_start_tx @ 00103190 size=1380
// signature: undefined msm_geni_serial_start_tx(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_start_tx(long param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  char *pcVar9;
  char *pcVar10;
  long lVar11;
  
  if (*(char *)(param_1 + 0x840) != '\0') {
    uVar4 = *(undefined8 *)(param_1 + 0x3b0);
    pcVar9 = "%s: SSR Down event set\n";
    pcVar10 = "msm_geni_serial_start_tx";
    goto LAB_001031c8;
  }
  lVar11 = *(long *)(param_1 + 0x3b8);
  if (lVar11 == 0) {
    uVar5 = 0xffffffffffffffea;
    lVar11 = *(long *)(param_1 + 0x100);
joined_r0x00103270:
    if (lVar11 == 0) goto LAB_001032b0;
LAB_00103274:
    if (*(int *)(param_1 + 0x134) != (int)*(short *)(lVar11 + 0x4a)) goto LAB_001032b0;
    if ((*(char *)(param_1 + 0x167) != '\0') || (*(int *)(param_1 + 0x44c) != 0)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s. Console in suspend state\n",
                     "msm_geni_serial_start_tx");
      return;
    }
LAB_00103328:
    if (*(int *)(param_1 + 0x610) != 0) {
      *(undefined4 *)(param_1 + 0x610) = 0;
    }
    iVar3 = *(int *)(param_1 + 0x238);
    if (iVar3 == 3) {
      if (*(long *)(param_1 + 0x318) == 0) {
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x500),param_1 + 0x470);
        goto LAB_00103648;
      }
    }
    else if (iVar3 == 2) {
      if (*(long *)(param_1 + 0x318) == 0) {
        if (*(int *)(param_1 + 900) != 0) {
          if (4 < *(uint *)(param_1 + 0x230)) {
LAB_001036f0:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1036f4);
            (*pcVar2)();
          }
          *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 0x230) * 0x30 + 0x628) =
               *(undefined4 *)(param_1 + 800);
          uVar4 = sched_clock();
          if (4 < *(uint *)(param_1 + 0x230)) goto LAB_001036f0;
          *(undefined8 *)(param_1 + (ulong)*(uint *)(param_1 + 0x230) * 0x30 + 0x630) = uVar4;
        }
        iVar3 = msm_geni_serial_prep_dma_tx(param_1);
        if (iVar3 != -1) goto LAB_00103648;
        ipc_log_string(*(undefined8 *)(param_1 + 0x398),"%s: tx_en=0,\n","msm_geni_serial_start_tx")
        ;
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx_en=0,\n","msm_geni_serial_start_tx");
        goto LAB_001035b0;
      }
    }
    else {
      if (iVar3 != 1) goto LAB_00103648;
      if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 1) == 0) {
        if ((((*(long *)(param_1 + 0x100) != 0) &&
             (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) ||
            (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) != 2)) ||
           (*(int *)(*(long *)(param_1 + 0x150) + 0x1f8) != 0)) {
          if (*(int *)(param_1 + 0x238) == 2) {
            uVar7 = (uint)(*(long *)(param_1 + 0x318) != 0);
          }
          else {
            uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x800);
          }
          if (uVar7 != 0) goto LAB_001034a4;
        }
        uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x614);
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x80c) = *(undefined4 *)(param_1 + 0x224);
        *(uint *)(*(long *)(param_1 + 0x10) + 0x614) = uVar7 | 0x40000001;
        DataSynchronizationBarrier(3,3,0);
LAB_00103648:
        lVar11 = *(long *)(param_1 + 0x3b8);
        if (lVar11 == 0) {
          return;
        }
        if (uVar5 == 0) {
          return;
        }
        if (*(int *)(param_1 + 900) == 0) {
          return;
        }
        iVar3 = *(int *)(param_1 + 800);
        iVar1 = *(int *)(param_1 + 0x3d8);
        lVar8 = sched_clock();
        uVar5 = lVar8 - uVar5;
        uVar6 = uVar5 / 1000;
        if (iVar3 == 0) {
          ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_start_tx",uVar5,
                         uVar6);
          return;
        }
        if (iVar1 == 0) {
          ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec) for %u bytes\n",
                         "msm_geni_serial_start_tx",uVar5,uVar6,iVar3);
          return;
        }
        ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                       "msm_geni_serial_start_tx",uVar5,uVar6,iVar3,iVar1);
        return;
      }
    }
LAB_001034a4:
    uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x908);
    if (((uVar7 >> 1 & 1) != 0) && (*(char *)(param_1 + 0x3fc) == '\0')) {
      *(undefined4 *)(param_1 + 0x450) = 0x14;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x14);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
    }
    msm_geni_serial_start_tx_ios_log_limit = msm_geni_serial_start_tx_ios_log_limit + 1;
    if ((uint)(msm_geni_serial_start_tx_ios_log_limit * -0x33333333) < 0x33333334) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: ios: 0x%x\n","msm_geni_serial_start_tx",
                     uVar7);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: ios: 0x%x\n","msm_geni_serial_start_tx",
                   uVar7);
      msm_geni_serial_start_tx_ios_log_limit = 0;
    }
    lVar11 = *(long *)(param_1 + 0x3b8);
    if (((lVar11 != 0) && (uVar5 != 0)) && (*(int *)(param_1 + 900) != 0)) {
      lVar8 = sched_clock();
      ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_start_tx",
                     lVar8 - uVar5,(lVar8 - uVar5) / 1000);
    }
  }
  else {
    if (*(int *)(param_1 + 900) == 0) {
      uVar5 = 0;
      lVar11 = *(long *)(param_1 + 0x100);
      goto joined_r0x00103270;
    }
    uVar5 = sched_clock();
    ipc_log_string(lVar11,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_start_tx",uVar5,
                   uVar5 / 1000);
    lVar11 = *(long *)(param_1 + 0x100);
    if (lVar11 != 0) goto LAB_00103274;
LAB_001032b0:
    lVar8 = *(long *)(param_1 + 0x150);
    if ((*(int *)(lVar8 + 0x20c) == 0) || ((*(ushort *)(lVar8 + 0x200) & 7) != 0)) {
      if (lVar11 != 0) {
        if (*(int *)(param_1 + 0x134) == (int)*(short *)(lVar11 + 0x4a)) goto LAB_00103328;
        lVar8 = *(long *)(param_1 + 0x150);
      }
      if ((*(ushort *)(lVar8 + 0x200) & 7) == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Power on.\n","msm_geni_serial_start_tx")
        ;
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Power on.\n","msm_geni_serial_start_tx");
        __pm_runtime_resume(*(undefined8 *)(param_1 + 0x150),5);
      }
      goto LAB_00103328;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Putting in async RPM vote\n",
                   "msm_geni_serial_start_tx");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Putting in async RPM vote\n",
                 "msm_geni_serial_start_tx");
    __pm_runtime_resume(*(undefined8 *)(param_1 + 0x150),5);
  }
LAB_001035b0:
  if ((*(long *)(param_1 + 0x100) != 0) &&
     (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    return;
  }
  lVar11 = *(long *)(param_1 + 0x150);
  if (*(int *)(lVar11 + 0x1f8) != 0) {
    if ((*(ushort *)(lVar11 + 0x200) & 7) == 0) {
      uVar4 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar11 + 0x220) = uVar4;
      __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
      return;
    }
    return;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x3a8);
  pcVar9 = "%s: Usage Count is already 0\n";
  pcVar10 = "msm_geni_serial_power_off";
LAB_001031c8:
  ipc_log_string(uVar4,pcVar9,pcVar10);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar9,pcVar10);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_stop_rx @ 001036f8 size=224
// signature: undefined msm_geni_serial_stop_rx(void)
// callers: [xfer_mode_store, msm_geni_serial_runtime_resume, start_rx_sequencer, msm_geni_serial_set_termios]
//------------------------------------------------------------

void msm_geni_serial_stop_rx(long param_1)

{
  int iVar1;
  
  if (((*(long *)(param_1 + 0x100) == 0) ||
      (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2 &&
      *(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended.\n",
                   "msm_geni_serial_stop_rx");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended.\n",
                 "msm_geni_serial_stop_rx");
    complete(param_1 + 0x510);
  }
  else {
    iVar1 = stop_rx_sequencer(param_1);
    if (iVar1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: stop rx failed %d\n",
                     "msm_geni_serial_stop_rx",iVar1);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: stop rx failed %d\n",
                   "msm_geni_serial_stop_rx",iVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_break_ctl @ 001037dc size=284
// signature: undefined msm_geni_serial_break_ctl(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_break_ctl(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  
  if (((*(long *)(param_1 + 0x100) == 0) ||
      (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (*(int *)(*(long *)(param_1 + 0x150) + 0x20c) == 2 &&
      *(int *)(*(long *)(param_1 + 0x150) + 0x1f8) == 0)) {
    lVar1 = sp_el0;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended, %s\n",
                   "msm_geni_serial_break_ctl",lVar1 + 0x848);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended, %s\n",
                 "msm_geni_serial_break_ctl",lVar1 + 0x848);
  }
  else {
    if (param_2 == 0) {
      DataMemoryBarrier(0,2);
      *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x600) = 0x28000000;
    }
    else {
      iVar2 = wait_for_transfers_inflight(param_1);
      if (iVar2 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                       "%s.wait_for_transfer_inflight return ret: %d\n","msm_geni_serial_break_ctl",
                       iVar2);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                     "%s.wait_for_transfer_inflight return ret: %d\n","msm_geni_serial_break_ctl",
                     iVar2);
      }
      DataMemoryBarrier(0,2);
      *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x600) = 0x20000000;
    }
    DataSynchronizationBarrier(3,3,0);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_startup @ 001038fc size=936
// signature: undefined msm_geni_serial_startup(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int msm_geni_serial_startup(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x3b8);
  if (lVar9 == 0) {
    uVar4 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar9,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_startup",uVar4,
                   uVar4 / 1000);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Start %d\n","msm_geni_serial_startup",1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Start %d\n","msm_geni_serial_startup",1);
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    *(undefined1 *)(param_1 + 0x620) = 0;
    iVar2 = msm_geni_serial_power_on(param_1);
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x150),"%s:Failed to power on %d\n",
               "msm_geni_serial_startup",iVar2);
      return iVar2;
    }
  }
  if (param_1 == 0) {
LAB_00103a98:
    cVar1 = *(char *)(param_1 + 0x248);
  }
  else {
    uVar3 = geni_se_get_qup_hw_version(param_1 + 0x2b8);
    uVar8 = 0xff0000;
    if (((uVar3 & 0xffe0000) < 0x90001 || uVar3 >> 0x1c != 3) && (uVar3 & 0xc0000000) == 0) {
      uVar8 = 0x3f0000;
    }
    uVar8 = uVar8 & *(uint *)(*(long *)(param_1 + 0x2b8) + 0xe24);
    *(uint *)(param_1 + 0x218) = uVar8 >> 0x10;
    if (uVar8 == 0) {
      uVar6 = *(undefined8 *)(param_1 + 0x150);
      pcVar7 = "%s:Invalid TX FIFO depth read\n";
    }
    else {
      uVar8 = *(uint *)(*(long *)(param_1 + 0x2b8) + 0xe24) >> 0x18 & 0x3f;
      *(uint *)(param_1 + 0x21c) = uVar8;
      if (uVar8 == 0) {
        uVar6 = *(undefined8 *)(param_1 + 0x150);
        pcVar7 = "%s:Invalid TX FIFO width read\n";
      }
      else {
        uVar3 = geni_se_get_qup_hw_version(param_1 + 0x2b8);
        uVar8 = 0xff0000;
        if (((uVar3 & 0xffe0000) < 0x90001 || uVar3 >> 0x1c != 3) && (uVar3 & 0xc0000000) == 0) {
          uVar8 = 0x3f0000;
        }
        uVar8 = uVar8 & *(uint *)(*(long *)(param_1 + 0x2b8) + 0xe28);
        *(uint *)(param_1 + 0x220) = uVar8 >> 0x10;
        if (uVar8 != 0) {
          *(uint *)(param_1 + 0xb4) =
               (uint)(*(int *)(param_1 + 0x21c) * *(int *)(param_1 + 0x218)) >> 3;
          goto LAB_00103a98;
        }
        uVar6 = *(undefined8 *)(param_1 + 0x150);
        pcVar7 = "%s:Invalid RX FIFO depth read\n";
      }
    }
    _dev_err(uVar6,pcVar7,"get_tx_fifo_size");
    cVar1 = *(char *)(param_1 + 0x248);
  }
  if ((cVar1 == '\0') && (iVar2 = msm_geni_serial_port_setup(param_1), iVar2 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: port_setup Fail ret:%d\n",
                   "msm_geni_serial_startup",iVar2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: port_setup Fail ret:%d\n",
                 "msm_geni_serial_startup",iVar2);
    lVar9 = *(long *)(param_1 + 0x100);
  }
  else {
    DataSynchronizationBarrier(3,3,0);
    if (((*(long *)(param_1 + 0x100) != 0) &&
        (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) ||
       (*(char *)(param_1 + 0x558) != '\0')) {
      enable_irq(*(undefined4 *)(param_1 + 0xa0));
    }
    lVar9 = *(long *)(param_1 + 0x3b8);
    *(undefined4 *)(param_1 + 0x808) = 2;
    if (((lVar9 != 0) && (uVar4 != 0)) && (*(int *)(param_1 + 900) != 0)) {
      lVar5 = sched_clock();
      ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_startup",lVar5 - uVar4,
                     (lVar5 - uVar4) / 1000);
    }
    iVar2 = 0;
    lVar9 = *(long *)(param_1 + 0x100);
  }
  if ((lVar9 == 0) || (*(int *)(param_1 + 0x134) != (int)*(short *)(lVar9 + 0x4a))) {
    lVar9 = *(long *)(param_1 + 0x150);
    if (*(int *)(lVar9 + 0x1f8) == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Usage Count is already 0\n",
                     "msm_geni_serial_power_off");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Usage Count is already 0\n",
                   "msm_geni_serial_power_off");
    }
    else if ((*(ushort *)(lVar9 + 0x200) & 7) == 0) {
      uVar6 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar9 + 0x220) = uVar6;
      __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
    }
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: ret:%d\n","msm_geni_serial_startup",iVar2);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: ret:%d\n","msm_geni_serial_startup",iVar2);
  return iVar2;
}



//------------------------------------------------------------
// msm_geni_serial_shutdown @ 00103ca8 size=1664
// signature: undefined msm_geni_serial_shutdown(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_shutdown(long param_1)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  
  lVar5 = *(long *)(param_1 + 0x260);
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: %d\n","msm_geni_serial_shutdown",1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: %d\n","msm_geni_serial_shutdown",1);
  lVar6 = *(long *)(param_1 + 0x3b8);
  *(undefined4 *)(param_1 + 0x808) = 1;
  if (lVar6 == 0) {
    uVar3 = 0xffffffffffffffea;
    lVar6 = *(long *)(param_1 + 0x100);
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar3 = 0;
    lVar6 = *(long *)(param_1 + 0x100);
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_shutdown",uVar3,
                   uVar3 / 1000);
    lVar6 = *(long *)(param_1 + 0x100);
  }
  if ((lVar6 != 0) && (*(int *)(param_1 + 0x134) == (int)*(short *)(lVar6 + 0x4a))) {
    console_stop();
    disable_irq(*(undefined4 *)(param_1 + 0xa0));
    iVar2 = 0;
    goto LAB_00104284;
  }
  if (*(int *)(param_1 + 0x3dc) == 0) {
    msm_geni_serial_power_on(param_1);
  }
  if (*(int *)(param_1 + 0x238) == 3) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Stop Rx Engine\n",
                   "msm_geni_serial_shutdown");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Stop Rx Engine\n","msm_geni_serial_shutdown")
    ;
    iVar2 = wait_for_completion_timeout(param_1 + 0x510,0x19);
    if (iVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Timeout for Rx reset\n",
                     "msm_geni_serial_shutdown");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Timeout for Rx reset\n",
                   "msm_geni_serial_shutdown");
    }
    plVar4 = *(long **)(param_1 + 0x468);
    if (plVar4[1] != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:GSI DMA-Rx ch\n",
                     "msm_geni_serial_shutdown");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:GSI DMA-Rx ch\n","msm_geni_serial_shutdown")
      ;
      dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
      if (*(long *)(param_1 + 0x360) != 0) {
        if (((param_1 != -0x360) && (*(long *)(param_1 + 0x330) != 0)) && (lVar5 != 0)) {
          dma_free_attrs(lVar5,0x800,*(long *)(param_1 + 0x330),*(long *)(param_1 + 0x360),0);
        }
        *(undefined8 *)(param_1 + 0x330) = 0;
      }
      if (*(long *)(param_1 + 0x368) != 0) {
        if (((param_1 != -0x368) && (*(long *)(param_1 + 0x338) != 0)) && (lVar5 != 0)) {
          dma_free_attrs(lVar5,0x800,*(long *)(param_1 + 0x338),*(long *)(param_1 + 0x368),0);
        }
        *(undefined8 *)(param_1 + 0x338) = 0;
      }
      if (*(long *)(param_1 + 0x370) != 0) {
        if (((param_1 != -0x370) && (*(long *)(param_1 + 0x340) != 0)) && (lVar5 != 0)) {
          dma_free_attrs(lVar5,0x800,*(long *)(param_1 + 0x340),*(long *)(param_1 + 0x370),0);
        }
        *(undefined8 *)(param_1 + 0x340) = 0;
      }
      if (*(long *)(param_1 + 0x378) != 0) {
        if (((param_1 != -0x378) && (*(long *)(param_1 + 0x348) != 0)) && (lVar5 != 0)) {
          dma_free_attrs(lVar5,0x800,*(long *)(param_1 + 0x348),*(long *)(param_1 + 0x378),0);
        }
        *(undefined8 *)(param_1 + 0x348) = 0;
      }
      *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:Unmap buf done\n",
                     "msm_geni_serial_shutdown");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Unmap buf done\n","msm_geni_serial_shutdown"
                  );
      plVar4 = *(long **)(param_1 + 0x468);
    }
    if (*plVar4 == 0) goto LAB_00104038;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:GSI DMA-Tx ch\n","msm_geni_serial_shutdown")
    ;
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:GSI DMA-Tx ch\n","msm_geni_serial_shutdown");
    dma_release_channel(**(undefined8 **)(param_1 + 0x468));
    lVar6 = *(long *)(param_1 + 0x318);
    if (lVar6 == -1) {
LAB_00103fbc:
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:Unmap buf done\n",
                     "msm_geni_serial_shutdown");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Unmap buf done\n","msm_geni_serial_shutdown"
                  );
    }
    else if (lVar6 != 0) {
      dma_unmap_page_attrs(lVar5,lVar6,*(undefined4 *)(param_1 + 800),1,0);
      goto LAB_00103fbc;
    }
    **(undefined8 **)(param_1 + 0x468) = 0;
    cVar1 = *(char *)(param_1 + 0x558);
  }
  else {
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      lVar5 = *(long *)(param_1 + 0x150);
      if ((*(int *)(lVar5 + 0x20c) == 2) && (*(int *)(lVar5 + 0x1f8) == 0)) {
        _dev_err(lVar5,"%s.Device is suspended.\n","msm_geni_serial_stop_tx");
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended.\n",
                       "msm_geni_serial_stop_tx");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended.\n",
                     "msm_geni_serial_stop_tx");
        cVar1 = *(char *)(param_1 + 0x558);
        goto joined_r0x0010403c;
      }
    }
    stop_tx_sequencer(param_1);
LAB_00104038:
    cVar1 = *(char *)(param_1 + 0x558);
  }
joined_r0x0010403c:
  if (cVar1 != '\0') {
    disable_irq(*(undefined4 *)(param_1 + 0xa0));
  }
  if (*(int *)(param_1 + 0x3dc) != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),
                   "%s: IOCTL vote present. Resetting ioctl count\n","msm_geni_serial_shutdown");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: IOCTL vote present. Resetting ioctl count\n",
                 "msm_geni_serial_shutdown");
    *(undefined4 *)(param_1 + 0x3dc) = 0;
  }
  if ((*(ushort *)(*(long *)(param_1 + 0x150) + 0x200) & 7) == 0) {
    iVar2 = __pm_runtime_suspend(*(long *)(param_1 + 0x150),4);
    if (iVar2 < 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Failed to suspend ret=%d\n",
                     "msm_geni_serial_shutdown",iVar2);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Failed to suspend ret=%d\n",
                   "msm_geni_serial_shutdown",iVar2);
      if (iVar2 == -0x10) {
        iVar2 = 0;
        do {
          ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Failed to suspend ret:%d retry:%d\n",
                         "msm_geni_serial_shutdown",0xfffffff0,iVar2);
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Failed to suspend ret:%d retry:%d\n",
                       "msm_geni_serial_shutdown",0xfffffff0,iVar2);
          usleep_range_state(45000,50000,2);
          lVar5 = *(long *)(param_1 + 0x150);
          if ((*(int *)(lVar5 + 0x20c) == 2) && (*(int *)(lVar5 + 0x1f8) == 0)) {
            pcVar7 = "%s Uport Suspended\n";
            ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s Uport Suspended\n",
                           "msm_geni_serial_shutdown");
            iVar2 = 0;
            goto LAB_00104208;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x33);
        if ((*(int *)(lVar5 + 0x20c) == 2) && (*(int *)(lVar5 + 0x1f8) == 0)) {
          pcVar7 = "%s Uport Suspended\n";
        }
        else {
          pcVar7 = "%s Error! Unable to put uport to Suspend\n";
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),pcVar7,"msm_geni_serial_shutdown");
        iVar2 = -0x10;
LAB_00104208:
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar7,"msm_geni_serial_shutdown");
      }
    }
  }
  else {
    iVar2 = 0;
  }
  if (((*(ulong *)(param_1 + 0x298) != 0) && (*(ulong *)(param_1 + 0x298) < 0xfffffffffffff001)) &&
     (iVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x290)), iVar2 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Error %d pinctrl_select_state\n",
                   "msm_geni_serial_shutdown",iVar2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Error %d pinctrl_select_state\n",
                 "msm_geni_serial_shutdown",iVar2);
  }
  *(undefined4 *)(param_1 + 0x450) = 0;
  *(undefined4 *)(param_1 + 0x610) = 0;
  *(undefined8 *)(param_1 + 0x618) = 0;
  *(undefined4 *)(param_1 + 0x550) = 0;
LAB_00104284:
  lVar5 = *(long *)(param_1 + 0x3b8);
  *(undefined4 *)(param_1 + 0x808) = 0;
  if (((lVar5 != 0) && (uVar3 != 0)) && (*(int *)(param_1 + 900) != 0)) {
    lVar6 = sched_clock();
    ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_shutdown",lVar6 - uVar3,
                   (lVar6 - uVar3) / 1000);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: End %d\n","msm_geni_serial_shutdown",iVar2);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: End %d\n","msm_geni_serial_shutdown",iVar2);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_flush @ 0010432c size=180
// signature: undefined msm_geni_serial_flush(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_flush(long param_1)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x3dc) != 0) {
    *(undefined4 *)(param_1 + 0x610) = 1;
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      lVar1 = *(long *)(param_1 + 0x150);
      if ((*(int *)(lVar1 + 0x20c) == 2) && (*(int *)(lVar1 + 0x1f8) == 0)) {
        _dev_err(lVar1,"%s.Device is suspended.\n","msm_geni_serial_stop_tx");
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended.\n",
                       "msm_geni_serial_stop_tx");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended.\n",
                     "msm_geni_serial_stop_tx");
        return;
      }
    }
    stop_tx_sequencer(param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_set_termios @ 001043e4 size=920
// signature: undefined msm_geni_serial_set_termios(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_set_termios(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  
  lVar6 = *(long *)(param_1 + 0x3b8);
  if (lVar6 == 0) {
    uVar3 = 0xffffffffffffffea;
    lVar6 = *(long *)(param_1 + 0x100);
joined_r0x0010446c:
    if (lVar6 == 0) goto LAB_00104490;
LAB_00104480:
    if (*(int *)(param_1 + 0x134) != (int)*(short *)(lVar6 + 0x4a)) goto LAB_00104490;
  }
  else {
    if (*(int *)(param_1 + 900) == 0) {
      uVar3 = 0;
      lVar6 = *(long *)(param_1 + 0x100);
      goto joined_r0x0010446c;
    }
    uVar3 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_set_termios",uVar3,
                   uVar3 / 1000);
    lVar6 = *(long *)(param_1 + 0x100);
    if (lVar6 != 0) goto LAB_00104480;
LAB_00104490:
    iVar1 = msm_geni_serial_power_on(param_1);
    if (iVar1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Failed to vote clock on:%d\n",
                     "msm_geni_serial_set_termios",iVar1);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Failed to vote clock on:%d\n",
                   "msm_geni_serial_set_termios",iVar1);
      return;
    }
  }
  if (*(long *)(param_1 + 0x500) != 0) {
    __flush_workqueue();
  }
  if (*(long *)(param_1 + 0x508) != 0) {
    __flush_workqueue();
  }
  *(undefined4 *)(param_1 + 0x510) = 0;
  msm_geni_serial_stop_rx(param_1);
  if (((*(long *)(param_1 + 0x100) == 0) ||
      (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (lVar6 = wait_for_completion_timeout(param_1 + 0x510,0x19), lVar6 == 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:Timeout for stop_rx\n",
                   "msm_geni_serial_set_termios");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Timeout for stop_rx\n",
                 "msm_geni_serial_set_termios");
  }
  mutex_lock(param_1 + 0x810);
  if (*(char *)(param_1 + 0x840) == '\0') {
    uVar2 = uart_get_baud_rate(param_1,param_2,param_3,300,8000000);
    *(undefined4 *)(param_1 + 0x3d8) = uVar2;
    iVar1 = msm_geni_serial_config_baud_rate(param_1,param_2,uVar2);
    if (iVar1 == 0) {
      if ((*(long *)(param_1 + 0x100) == 0) ||
         (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
        *(undefined8 *)(param_1 + 0x618) = param_2;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: baud %d\n","msm_geni_serial_set_termios",
                     uVar2);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: baud %d\n","msm_geni_serial_set_termios",
                   uVar2);
      lVar6 = *(long *)(param_1 + 0x3b8);
      if (((lVar6 != 0) && (uVar3 != 0)) && (*(int *)(param_1 + 900) != 0)) {
        lVar5 = sched_clock();
        ipc_log_string(lVar6,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_set_termios",
                       lVar5 - uVar3,(lVar5 - uVar3) / 1000);
      }
    }
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      lVar6 = *(long *)(param_1 + 0x150);
      if ((*(int *)(lVar6 + 0x20c) != 2) || (*(int *)(lVar6 + 0x1f8) != 0)) goto LAB_00104624;
      _dev_err(lVar6,"%s.Device is suspended.\n","msm_geni_serial_start_rx");
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Device is suspended.\n",
                     "msm_geni_serial_start_rx");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Device is suspended.\n",
                   "msm_geni_serial_start_rx");
      lVar6 = *(long *)(param_1 + 0x100);
    }
    else {
LAB_00104624:
      start_rx_sequencer(param_1);
      lVar6 = *(long *)(param_1 + 0x100);
    }
    if ((lVar6 != 0) && (*(int *)(param_1 + 0x134) == (int)*(short *)(lVar6 + 0x4a)))
    goto LAB_0010459c;
    lVar6 = *(long *)(param_1 + 0x150);
    if (*(int *)(lVar6 + 0x1f8) != 0) {
      if ((*(ushort *)(lVar6 + 0x200) & 7) == 0) {
        uVar4 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar6 + 0x220) = uVar4;
        __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
      }
      goto LAB_0010459c;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x3a8);
    pcVar7 = "%s: Usage Count is already 0\n";
    pcVar8 = "msm_geni_serial_power_off";
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x3b0);
    pcVar7 = "%s. SSR Down event set\n";
    pcVar8 = "msm_geni_serial_set_termios";
  }
  ipc_log_string(uVar4,pcVar7,pcVar8);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar7,pcVar8);
LAB_0010459c:
  mutex_unlock(param_1 + 0x810);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_hs_pm @ 00104780 size=336
// signature: undefined msm_geni_serial_hs_pm(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_hs_pm(long param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((*(ushort *)(*(long *)(param_1 + 0x150) + 0x200) & 7) != 0) {
    iVar1 = 3;
    if (param_3 != 4) {
      iVar1 = param_3;
    }
    if ((param_2 == 0) && (iVar1 == 3)) {
      msm_geni_serial_resources_on(param_1);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                     "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(param_1 + 0x458));
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                   "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(param_1 + 0x458));
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48) = *(undefined4 *)(param_1 + 0x458);
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x4c) = *(undefined4 *)(param_1 + 0x458);
      *(undefined4 *)(param_1 + 0x44c) = 0;
    }
    else if ((param_2 == 3) && (iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x44c) = 1;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                     "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(param_1 + 0x458));
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                   "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(param_1 + 0x458));
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48) = 1;
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x4c) = 1;
      msm_geni_serial_resources_off(*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48),param_1);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_get_type @ 001048d4 size=12
// signature: undefined msm_geni_serial_get_type(void)
// callers: []
//------------------------------------------------------------

undefined * msm_geni_serial_get_type(void)

{
  return &DAT_0010fce8;
}



//------------------------------------------------------------
// msm_geni_serial_config_port @ 001048e4 size=16
// signature: undefined msm_geni_serial_config_port(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_config_port(long param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x120) = 0x58;
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_ioctl @ 001048f8 size=1400
// signature: undefined msm_geni_serial_ioctl(void)
// callers: [hs_uart_operation_store]
//------------------------------------------------------------

uint msm_geni_serial_ioctl(long param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  
  lVar7 = sp_el0;
  lVar7 = lVar7 + 0x848;
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:%s cmd 0x%x\n","msm_geni_serial_ioctl",lVar7,
                 param_2);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:%s cmd 0x%x\n","msm_geni_serial_ioctl",lVar7,
               param_2);
  if (*(char *)(param_1 + 0x558) != '\0') {
LAB_0010496c:
    return 0xfffffdfd;
  }
  switch(param_2) {
  case 0x54ec:
    uVar2 = *(uint *)(param_1 + 0x450);
    *(undefined4 *)(param_1 + 0x450) = 0;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "%s TIOCFAULT - uart_error_set %d new_uart_error %d","msm_geni_serial_ioctl",
                   uVar2,0);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "%s TIOCFAULT - uart_error_set %d new_uart_error %d","msm_geni_serial_ioctl",uVar2,
                 *(undefined4 *)(param_1 + 0x450));
    if (*(int *)(param_1 + 0x3dc) != 0) {
      geni_se_dump_dbg_regs(param_1);
    }
    uVar5 = *(undefined8 *)(param_1 + 0x3c0);
    *(undefined8 *)(param_1 + 0x3a0) = uVar5;
    *(undefined8 *)(param_1 + 0x398) = uVar5;
    *(undefined8 *)(param_1 + 0x3b0) = uVar5;
    *(undefined8 *)(param_1 + 0x3a8) = uVar5;
    *(undefined8 *)(param_1 + 0x3d0) = uVar5;
    return uVar2;
  case 0x54ed:
    lVar8 = *(long *)(param_1 + 0x3b8);
    if (lVar8 == 0) {
      uVar4 = 0xffffffffffffffea;
    }
    else if (*(int *)(param_1 + 900) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = sched_clock();
      ipc_log_string(lVar8,"%s:start at %llu nsec(%llu usec)\n","vote_clock_on",uVar4,uVar4 / 1000);
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"Enter %s:%s ioctl_count:%d\n","vote_clock_on",
                   lVar7,*(undefined4 *)(param_1 + 0x3dc));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"Enter %s:%s ioctl_count:%d\n","vote_clock_on",
                 lVar7,*(undefined4 *)(param_1 + 0x3dc));
    if (*(int *)(param_1 + 0x3dc) != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s clock already on\n","vote_clock_on");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s clock already on\n","vote_clock_on");
      return 0;
    }
    uVar2 = msm_geni_serial_power_on(param_1);
    if (uVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x150),"Failed to vote clock on\n");
      return uVar2;
    }
    *(undefined4 *)(param_1 + 0x55c) = 0;
    complete(param_1 + 0x5f0);
    iVar3 = *(int *)(param_1 + 0x3dc) + 1;
    *(int *)(param_1 + 0x3dc) = iVar3;
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x150) + 0x1f8);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s :%s ioctl:%d usage_count:%d\n",
                   "vote_clock_on",lVar7,iVar3,uVar1);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s :%s ioctl:%d usage_count:%d\n","vote_clock_on"
                 ,lVar7,*(undefined4 *)(param_1 + 0x3dc),uVar1);
    lVar7 = *(long *)(param_1 + 0x3b8);
    if (lVar7 == 0) {
      return 0;
    }
    if (uVar4 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 900) == 0) {
      return 0;
    }
    lVar8 = sched_clock();
    uVar4 = lVar8 - uVar4;
    pcVar6 = "vote_clock_on";
    break;
  case 0x54ee:
    lVar8 = *(long *)(param_1 + 0x3b8);
    if (lVar8 == 0) {
      uVar4 = 0xffffffffffffffea;
    }
    else if (*(int *)(param_1 + 900) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = sched_clock();
      ipc_log_string(lVar8,"%s:start at %llu nsec(%llu usec)\n","vote_clock_off",uVar4,uVar4 / 1000)
      ;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"Enter %s:%s ioctl_count:%d\n","vote_clock_off",
                   lVar7,*(undefined4 *)(param_1 + 0x3dc));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"Enter %s:%s ioctl_count:%d\n","vote_clock_off",
                 lVar7,*(undefined4 *)(param_1 + 0x3dc));
    lVar8 = *(long *)(param_1 + 0x150);
    if ((*(ushort *)(lVar8 + 0x200) & 7) != 0) {
      _dev_err(lVar8,"RPM not available.Can\'t enable clocks\n");
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x3dc) == 0) {
      _dev_warn(lVar8,"%s:Imbalanced vote off ioctl %d\n","vote_clock_off",0);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s Imbalanced vote_off from userspace. %d",
                     "vote_clock_off",*(undefined4 *)(param_1 + 0x3dc));
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s Imbalanced vote_off from userspace. %d",
                   "vote_clock_off",*(undefined4 *)(param_1 + 0x3dc));
      return 0xffffffff;
    }
    iVar3 = wait_for_transfers_inflight(param_1);
    if (iVar3 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s wait_for_transfer_inflight return ret: %d"
                     ,"vote_clock_off",iVar3);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s wait_for_transfer_inflight return ret: %d",
                   "vote_clock_off",iVar3);
      return 0xfffffff5;
    }
    lVar8 = *(long *)(param_1 + 0x150);
    *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + -1;
    if (*(int *)(lVar8 + 0x1f8) == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Usage Count is already 0\n",
                     "msm_geni_serial_power_off");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Usage Count is already 0\n",
                   "msm_geni_serial_power_off");
    }
    else if ((*(ushort *)(lVar8 + 0x200) & 7) == 0) {
      uVar5 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar8 + 0x220) = uVar5;
      __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
    }
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x150) + 0x1f8);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s:%s ioctl:%d usage_count:%d\n",
                   "vote_clock_off",lVar7,*(undefined4 *)(param_1 + 0x3dc),uVar1);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:%s ioctl:%d usage_count:%d\n","vote_clock_off"
                 ,lVar7,*(undefined4 *)(param_1 + 0x3dc),uVar1);
    lVar7 = *(long *)(param_1 + 0x3b8);
    if (lVar7 == 0) {
      return 0;
    }
    if (uVar4 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 900) == 0) {
      return 0;
    }
    lVar8 = sched_clock();
    uVar4 = lVar8 - uVar4;
    pcVar6 = "vote_clock_off";
    break;
  case 0x54ef:
    return (uint)(*(int *)(*(long *)(param_1 + 0x150) + 0x20c) != 2);
  default:
    goto LAB_0010496c;
  }
  ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n",pcVar6,uVar4,uVar4 / 1000);
  return 0;
}



//------------------------------------------------------------
// msm_geni_update_uart_error_code @ 00104e70 size=112
// signature: undefined msm_geni_update_uart_error_code(void)
// callers: [stop_rx_sequencer, msm_geni_serial_runtime_suspend, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_serial_handle_isr, handle_rx_dma_xfer]
//------------------------------------------------------------

void msm_geni_update_uart_error_code(long param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x3fc) == '\0') {
    *(undefined4 *)(param_1 + 0x450) = param_2;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",param_2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                 "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
  }
  return;
}



//------------------------------------------------------------
// stop_tx_sequencer @ 00104ee0 size=1192
// signature: undefined stop_tx_sequencer(void)
// callers: [msm_geni_serial_runtime_suspend, xfer_mode_store, msm_geni_serial_stop_tx, msm_geni_serial_shutdown, msm_geni_serial_flush]
//------------------------------------------------------------

void stop_tx_sequencer(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(char *)(param_1 + 0x840) == '\0') {
    if (*(int *)(param_1 + 0x238) == 3) {
      queue_work_on(0x20,*(undefined8 *)(param_1 + 0x500),param_1 + 0x4d0);
    }
    else {
      uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
      if ((uVar2 & 1) != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Start GENI: 0x%x\n","stop_tx_sequencer"
                       ,uVar2);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Start GENI: 0x%x\n","stop_tx_sequencer",
                     uVar2);
        *(undefined1 *)(param_1 + 0x3fe) = 0;
        *(undefined4 *)(param_1 + 0x408) = 0;
        *(undefined1 *)(param_1 + 0x400) = 1;
        uVar2 = msm_serial_try_disable_interrupts(param_1);
        *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 4;
        uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
        if ((uVar3 & 1) != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s: tx_cancel failed 0x%x\n",
                         "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx_cancel failed 0x%x\n",
                         "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx_cancel failed 0x%x\n",
                       "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
          if (*(char *)(param_1 + 0x3fc) == '\0') {
            *(undefined4 *)(param_1 + 0x450) = 8;
            ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                           "msm_geni_update_uart_error_code",8);
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                         "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
          }
          geni_se_dump_dbg_regs(param_1);
          *(undefined1 *)(param_1 + 0x3fe) = 0;
          *(undefined4 *)(param_1 + 0x408) = 0;
          *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 2;
          uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
          if ((uVar3 & 1) != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s: tx abort failed 0x%x\n",
                           "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx abort failed 0x%x\n",
                           "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx abort failed 0x%x\n",
                         "stop_tx_sequencer",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            if (*(char *)(param_1 + 0x3fc) == '\0') {
              *(undefined4 *)(param_1 + 0x450) = 9;
              ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                             "msm_geni_update_uart_error_code",9);
              __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                           "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
            }
            geni_se_dump_dbg_regs(param_1);
          }
          *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac) = 0x80000001;
          DataSynchronizationBarrier(3,3,0);
          uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac);
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s(): rfr = 0x%x\n",
                         "msm_geni_serial_allow_rx",uVar1);
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s(): rfr = 0x%x\n",
                       "msm_geni_serial_allow_rx",uVar1);
          msm_geni_serial_set_manual_flow(1,param_1);
          *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x20) = 1;
        }
        if (*(int *)(param_1 + 0x238) == 2) {
          if ((*(uint *)(*(long *)(param_1 + 0x10) + 0xe40) & 1) != 0) {
            *(undefined1 *)(param_1 + 0x3fe) = 0;
            *(undefined4 *)(param_1 + 0x408) = 0;
            *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc58) = 1;
            uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
            uVar4 = 0;
            if ((uVar3 & 1) != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx fsm reset failed\n",
                             "stop_tx_sequencer");
              __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx fsm reset failed\n",
                           "stop_tx_sequencer");
              uVar4 = 10;
            }
            msm_geni_update_uart_error_code(param_1,uVar4);
          }
          if (*(long *)(param_1 + 0x318) != 0) {
            geni_se_tx_dma_unprep
                      (param_1 + 0x2b8,*(long *)(param_1 + 0x318),*(undefined4 *)(param_1 + 800));
            *(undefined8 *)(param_1 + 0x318) = 0;
          }
        }
        msm_geni_serial_enable_interrupts(param_1);
        *(undefined1 *)(param_1 + 0x400) = 0;
        *(undefined4 *)(param_1 + 800) = 0;
        if ((*(long *)(param_1 + 0x100) == 0) ||
           (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s:Removing vote\n","stop_tx_sequencer");
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Removing vote\n","stop_tx_sequencer");
          lVar5 = *(long *)(param_1 + 0x150);
          if (*(int *)(lVar5 + 0x1f8) == 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Usage Count is already 0\n",
                           "msm_geni_serial_power_off");
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Usage Count is already 0\n",
                         "msm_geni_serial_power_off");
          }
          else if ((*(ushort *)(lVar5 + 0x200) & 7) == 0) {
            uVar4 = ktime_get_mono_fast_ns();
            *(undefined8 *)(lVar5 + 0x220) = uVar4;
            __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
          }
        }
        uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: End GENI:0x%x\n","stop_tx_sequencer",
                       uVar1);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: End GENI:0x%x\n","stop_tx_sequencer",
                     uVar1);
      }
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n","stop_tx_sequencer");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n","stop_tx_sequencer");
  }
  return;
}



//------------------------------------------------------------
// msm_serial_try_disable_interrupts @ 00105388 size=424
// signature: undefined msm_serial_try_disable_interrupts(void)
// callers: [stop_rx_sequencer, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_check_stop_engine, msm_geni_serial_port_setup]
//------------------------------------------------------------

bool msm_serial_try_disable_interrupts(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  uVar7 = daif;
  uVar10 = (uint)uVar7 & 0x80;
  if ((uVar7 & 0x80) == 0) {
    uVar10 = 0x60;
    uVar8 = daif;
    daif = uVar8 | 0xc0;
  }
  iVar9 = _raw_spin_trylock(uVar10,param_1);
  if (iVar9 == 0) {
    daif = uVar7;
    uVar1 = *(uint *)(*(long *)(param_1 + 0x10) + 0x614);
    uVar10 = uVar1 & 0xf33fffcf;
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x644);
    uVar11 = uVar10;
    if ((*(char *)(param_1 + 0x8c1) != '\0') &&
       (uVar11 = uVar1 & 0xf33ffdcf, *(char *)(param_1 + 0x8c0) != '\0')) {
      uVar11 = uVar10;
    }
    *(uint *)(*(long *)(param_1 + 0x10) + 0x614) = uVar11;
    *(uint *)(*(long *)(param_1 + 0x10) + 0x644) = uVar2 & 0xf3ffffcf;
    if (*(int *)(param_1 + 0x238) == 2) {
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc50) = 0x400f;
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xd50) = 0x9ef;
    }
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x614);
      uVar4 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x644);
      uVar5 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc48);
      uVar6 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xd48);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),
                     "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
                     "msm_serial_try_disable_interrupts",uVar3,uVar4,uVar5,uVar6);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                   "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
                   "msm_serial_try_disable_interrupts",uVar3,uVar4,uVar5,uVar6);
    }
  }
  else {
    _raw_spin_unlock_irqrestore(param_1,uVar7);
  }
  return iVar9 == 0;
}



//------------------------------------------------------------
// geni_wait_for_cmd_done @ 00105538 size=396
// signature: undefined geni_wait_for_cmd_done(void)
// callers: [stop_rx_sequencer, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_check_stop_engine]
//------------------------------------------------------------

void geni_wait_for_cmd_done(long param_1,uint param_2)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  undefined8 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s polling:%d\n","geni_wait_for_cmd_done",
                   param_2 & 1);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s polling:%d\n","geni_wait_for_cmd_done",
                 param_2 & 1);
  }
  if ((param_2 & 1) == 0) {
    if (*(char *)(param_1 + 0x400) == '\0') {
      if (*(char *)(param_1 + 0x401) == '\0') goto LAB_00105684;
      param_1 = param_1 + 0x428;
    }
    else {
      param_1 = param_1 + 0x408;
    }
    lVar2 = wait_for_completion_timeout(param_1,7);
  }
  else {
    if (*(char *)(param_1 + 0x400) == '\0') {
      if ((*(char *)(param_1 + 0x401) != '\0') && (*(char *)(param_1 + 0x3ff) == '\0')) {
        lVar3 = 1000;
        do {
          msm_geni_serial_handle_isr(param_1,&local_50,1);
          lVar2 = lVar3 + -1;
          __const_udelay(0x68dbc);
          if (*(char *)(param_1 + 0x3ff) != '\0') break;
          bVar1 = lVar3 != 1;
          lVar3 = lVar2;
        } while (bVar1);
        goto LAB_00105688;
      }
    }
    else if (*(char *)(param_1 + 0x3fe) == '\0') {
      lVar3 = 1000;
      do {
        msm_geni_serial_handle_isr(param_1,&local_50,1);
        lVar2 = lVar3 + -1;
        __const_udelay(0x68dbc);
        if (*(char *)(param_1 + 0x3fe) != '\0') break;
        bVar1 = lVar3 != 1;
        lVar3 = lVar2;
      } while (bVar1);
      goto LAB_00105688;
    }
LAB_00105684:
    lVar2 = 1000;
  }
LAB_00105688:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2 == 0);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_allow_rx @ 001056c4 size=144
// signature: undefined msm_geni_serial_allow_rx(void)
// callers: [stop_rx_sequencer]
//------------------------------------------------------------

void msm_geni_serial_allow_rx(long param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac) = 0x80000001;
  DataSynchronizationBarrier(3,3,0);
  uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac);
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s(): rfr = 0x%x\n","msm_geni_serial_allow_rx",
                 uVar1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s(): rfr = 0x%x\n","msm_geni_serial_allow_rx",
               uVar1);
  msm_geni_serial_set_manual_flow(1,param_1);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_enable_interrupts @ 00105754 size=488
// signature: undefined msm_geni_serial_enable_interrupts(void)
// callers: [stop_rx_sequencer, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_serial_port_setup, start_rx_sequencer, msm_geni_serial_probe]
//------------------------------------------------------------

void msm_geni_serial_enable_interrupts(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x10) + 0x614);
  uVar7 = uVar1 | 0xcc00030;
  uVar8 = *(uint *)(*(long *)(param_1 + 0x10) + 0x644);
  if ((*(long *)(param_1 + 200) == 0) || (*(long *)(*(long *)(param_1 + 200) + 0xa8) == 0)) {
    uVar7 = uVar7 & 0xf73fffff;
    uVar8 = uVar8 & 0xffffe3ff | 0xc000030;
  }
  else {
    uVar8 = uVar8 | 0xc001c30;
    if ((*(char *)(param_1 + 0x8c1) != '\0') && (*(char *)(param_1 + 0x8c0) == '\0')) {
      *(undefined4 *)(param_1 + 0x8b8) = 0;
      uVar7 = uVar1 | 0xcc00230;
    }
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),"%s: geni_m_irq_en = 0x%x geni_s_irq_en = 0x%x\n",
                 "msm_geni_serial_enable_interrupts",uVar7,uVar8);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: geni_m_irq_en = 0x%x geni_s_irq_en = 0x%x\n",
               "msm_geni_serial_enable_interrupts",uVar7,uVar8);
  bVar6 = *(char *)(param_1 + 0x460) != '\0';
  if (bVar6) {
    uVar7 = uVar7 & 0xfbffffff;
  }
  *(uint *)(*(long *)(param_1 + 0x10) + 0x614) = uVar7;
  if (bVar6) {
    uVar8 = uVar8 & 0xfbffffff;
  }
  *(uint *)(*(long *)(param_1 + 0x10) + 0x644) = uVar8;
  if (*(int *)(param_1 + 0x238) == 2) {
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc4c) = 0x400f;
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xd4c) = 0x9ef;
  }
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x614);
    uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x644);
    uVar4 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc48);
    uVar5 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xd48);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),
                   "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
                   "msm_geni_serial_enable_interrupts",uVar2,uVar3,uVar4,uVar5);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
                 "msm_geni_serial_enable_interrupts",uVar2,uVar3,uVar4,uVar5);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_handle_isr @ 0010593c size=2420
// signature: undefined msm_geni_serial_handle_isr(void)
// callers: [stop_rx_sequencer, geni_wait_for_cmd_done, msm_geni_serial_isr]
//------------------------------------------------------------

void msm_geni_serial_handle_isr(long param_1,undefined8 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  bool bVar11;
  byte bVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  long lVar22;
  undefined8 uVar23;
  long lVar24;
  char *pcVar25;
  long lVar26;
  
  lVar24 = *(long *)(param_1 + 200);
  lVar22 = *(long *)(param_1 + 0x3b8);
  lVar26 = *(long *)(lVar24 + 0xa8);
  if (lVar22 == 0) {
    uVar14 = 0xffffffffffffffea;
    cVar7 = *(char *)(param_1 + 0x840);
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar14 = 0;
    cVar7 = *(char *)(param_1 + 0x840);
  }
  else {
    uVar14 = sched_clock();
    ipc_log_string(lVar22,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_handle_isr",uVar14,
                   uVar14 / 1000);
    cVar7 = *(char *)(param_1 + 0x840);
  }
  if (cVar7 != '\0') {
    uVar6 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x640);
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x618) =
         *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x610);
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x648) = uVar6;
    iVar8 = *(int *)(*(long *)(param_1 + 0x10) + 0xc40);
    if (iVar8 != 0) {
      *(int *)(*(long *)(param_1 + 0x10) + 0xc44) = iVar8;
    }
    iVar8 = *(int *)(*(long *)(param_1 + 0x10) + 0xd40);
    if (iVar8 != 0) {
      *(int *)(*(long *)(param_1 + 0x10) + 0xd44) = iVar8;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.SSR Down event set\n",
                   "msm_geni_serial_handle_isr");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.SSR Down event set\n",
                 "msm_geni_serial_handle_isr");
    return;
  }
  if (((*(long *)(param_1 + 0x100) != 0) &&
      (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
     (*(int *)(param_1 + 0x44c) != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s. Console in suspend state\n",
                   "msm_geni_serial_handle_isr");
    return;
  }
  uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x610);
  uVar3 = *(uint *)(*(long *)(param_1 + 0x10) + 0x640);
  if ((*(long *)(param_1 + 0x100) != 0) &&
     (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s. sirq 0x%x mirq:0x%x\n",
                   "msm_geni_serial_handle_isr",uVar3,uVar2);
  }
  *(uint *)(*(long *)(param_1 + 0x10) + 0x618) = uVar2;
  *(uint *)(*(long *)(param_1 + 0x10) + 0x648) = uVar3;
  if (((*(char *)(param_1 + 0x8c1) != '\0') && (*(char *)(param_1 + 0x8c0) == '\0')) &&
     ((uVar2 >> 9 & 1) != 0)) {
    *(undefined4 *)(param_1 + 0x8b8) = 0x17;
  }
  if ((uVar2 >> 2 & 1) != 0) {
    if ((*(long *)(param_1 + 0x100) != 0) &&
       (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s Illegal interrupt sirq:0x%x mirq:0x%x\n",
                     "msm_geni_serial_handle_isr",uVar3,uVar2);
      return;
    }
    if (*(char *)(param_1 + 0x3fc) == '\0') {
      *(undefined4 *)(param_1 + 0x450) = 0xf;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0xf);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s Illegal interrupt sirq:0x%x mirq:0x%x\n",
                   "msm_geni_serial_handle_isr",uVar3,uVar2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s Illegal interrupt sirq:0x%x mirq:0x%x\n",
                 "msm_geni_serial_handle_isr",uVar3,uVar2);
    return;
  }
  if ((uVar2 & 0xc00000) != 0) {
    *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
  }
  if ((uVar3 >> 0x19 & 1) != 0) {
    *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
    lVar22 = *(long *)(lVar24 + 0xa0);
    if ((*(byte *)(lVar22 + 0x1c) & 1) == 0) {
      if (*(int *)(lVar22 + 0xc) <= *(int *)(lVar22 + 8)) goto LAB_00105c8c;
      *(undefined1 *)(lVar22 + 0x20 + (long)*(int *)(lVar22 + 8) + (long)*(int *)(lVar22 + 0xc)) = 4
      ;
      iVar8 = *(int *)(lVar22 + 8);
      *(int *)(lVar22 + 8) = iVar8 + 1;
      *(undefined1 *)(lVar22 + 0x20 + (long)iVar8) = 0;
    }
    else {
LAB_00105c8c:
      __tty_insert_flip_char(lVar24,0,4);
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.sirq 0x%x buf_overrun:%d\n",
                   "msm_geni_serial_handle_isr",uVar3,*(undefined4 *)(param_1 + 0xf8));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.sirq 0x%x buf_overrun:%d\n",
                 "msm_geni_serial_handle_isr",uVar3,*(undefined4 *)(param_1 + 0xf8));
    if (*(char *)(param_1 + 0x3fc) == '\0') {
      *(undefined4 *)(param_1 + 0x450) = 0x10;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x10);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
    }
  }
  if (*(int *)(*(long *)(param_1 + 0x10) + 600) != 0) {
    iVar8 = *(int *)(*(long *)(param_1 + 0x10) + 0xc40);
    iVar4 = *(int *)(*(long *)(param_1 + 0x10) + 0xd40);
    if (((uVar2 != 0) || (uVar3 != 0)) || ((iVar8 != 0 || (iVar4 != 0)))) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),"%s: sirq:0x%x mirq:0x%x dma_txirq:0x%x\n",
                     "msm_geni_serial_handle_isr",uVar3,uVar2,iVar8);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: sirq:0x%x mirq:0x%x dma_txirq:0x%x\n",
                   "msm_geni_serial_handle_isr",uVar3,uVar2,iVar8);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),
                     "%s: dma_rxirq:0x%x is_irq_masked:%d cts_count:%d\n",
                     "msm_geni_serial_handle_isr",iVar4,param_3 & 1,*(undefined4 *)(param_1 + 0xd0))
      ;
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                   "%s: dma_rxirq:0x%x is_irq_masked:%d cts_count:%d\n","msm_geni_serial_handle_isr"
                   ,iVar4,param_3 & 1,*(undefined4 *)(param_1 + 0xd0));
    }
    if (lVar26 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3d0),"Port is closed!\n");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"Port is closed!\n");
      iVar8 = *(int *)(*(long *)(param_1 + 0x10) + 0xc40);
      if (iVar8 != 0) {
        *(int *)(*(long *)(param_1 + 0x10) + 0xc44) = iVar8;
      }
      iVar8 = *(int *)(*(long *)(param_1 + 0x10) + 0xd40);
      if (iVar8 == 0) {
        bVar12 = 0;
        bVar11 = false;
      }
      else {
        bVar12 = 0;
        bVar11 = false;
        *(int *)(*(long *)(param_1 + 0x10) + 0xd44) = iVar8;
      }
      goto LAB_0010622c;
    }
    uVar16 = *(uint *)(*(long *)(param_1 + 0x10) + 0xc40);
    if (uVar16 == 0) {
LAB_00105f34:
      bVar11 = (uVar2 & 0x30) != 0;
    }
    else {
      *(uint *)(*(long *)(param_1 + 0x10) + 0xc44) = uVar16;
      if ((uVar16 & 0x4008) == 0) {
        if (((uVar16 & 1) != 0) &&
           (msm_geni_serial_handle_dma_tx(param_1), *(int *)(param_1 + 0x450) == 0x14)) {
          msm_geni_update_uart_error_code(param_1,0);
        }
        goto LAB_00105f34;
      }
      bVar11 = true;
    }
    bVar12 = handle_rx_dma_xfer(uVar3,param_1);
    goto LAB_0010622c;
  }
  if ((uVar2 & *(uint *)(*(long *)(param_1 + 0x10) + 0x614) & 0x40000001) != 0) {
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      uVar16 = *(uint *)(param_1 + 0x21c) >> 3;
    }
    else {
      uVar16 = 1;
    }
    if (*(char *)(param_1 + 0x840) == '\0') {
      lVar22 = *(long *)(param_1 + 200);
      uVar5 = *(uint *)(*(long *)(param_1 + 0x10) + 0x800);
      if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 1) == 0) {
        uVar18 = *(int *)(lVar22 + 0x1d0) - *(int *)(lVar22 + 0x1d4) & 0xfff;
      }
      else {
        uVar18 = *(uint *)(param_1 + 0x3f8);
      }
      if ((((uVar2 & 1) == 0) || (uVar18 != 0)) || (uVar5 != 0)) {
        uVar5 = (*(int *)(param_1 + 0x218) - (uVar5 & 0xfffffff)) * uVar16;
        if ((int)uVar5 < 1) {
          uVar5 = 0;
        }
        if (uVar18 <= uVar5) {
          uVar5 = uVar18;
        }
        if (uVar5 != 0) {
          uVar17 = *(uint *)(lVar22 + 0x1d4);
          if (*(int *)(param_1 + 0x3f8) == 0) {
            *(uint *)(*(long *)(param_1 + 0x10) + 0x270) = uVar18;
            *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x600) = 0x8000000;
            DataSynchronizationBarrier(3,3,0);
            *(uint *)(param_1 + 0x3f8) = uVar18;
            uVar18 = *(uint *)(*(long *)(param_1 + 0x10) + 0x614);
            if ((uVar18 >> 0x1e & 1) == 0) {
              *(uint *)(*(long *)(param_1 + 0x10) + 0x614) = uVar18 | 0x40000000;
            }
          }
          uVar18 = 0;
          uVar19 = uVar5;
          do {
            if (*(char *)(param_1 + 0x840) != '\0') goto LAB_00105edc;
            uVar1 = uVar19;
            if (uVar16 <= uVar19) {
              uVar1 = uVar16;
            }
            if (uVar1 == 0) {
              uVar20 = 0;
            }
            else {
              uVar21 = 0;
              uVar20 = 0;
              uVar13 = uVar1;
              do {
                lVar24 = (long)(int)uVar17;
                uVar17 = uVar17 + 1 & 0xfff;
                uVar13 = uVar13 - 1;
                uVar9 = uVar21 & 0x1f;
                uVar21 = uVar21 + 8;
                uVar20 = (uint)*(byte *)(*(long *)(lVar22 + 0x1c8) + lVar24) << (ulong)uVar9 |
                         uVar20;
              } while (uVar13 != 0);
            }
            uVar18 = uVar1 + uVar18;
            uVar19 = uVar19 - uVar1;
            *(uint *)(*(long *)(param_1 + 0x10) + 0x700) = uVar20;
            *(uint *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + uVar1;
            *(uint *)(param_1 + 0x3f8) = *(int *)(param_1 + 0x3f8) - uVar1;
            DataSynchronizationBarrier(3,2,0);
          } while (uVar18 < uVar5);
          *(uint *)(lVar22 + 0x1d4) = uVar17;
          *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x618) = 0x40000000;
        }
      }
      if (*(int *)(param_1 + 0x3f8) == 0) {
        *(uint *)(*(long *)(param_1 + 0x10) + 0x614) =
             *(uint *)(*(long *)(param_1 + 0x10) + 0x614) & 0xbfffffff;
      }
      if ((*(int *)(lVar22 + 0x1d0) - *(int *)(lVar22 + 0x1d4) & 0xf00U) == 0) {
        uart_write_wakeup(param_1);
      }
    }
    else {
LAB_00105edc:
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.SSR Down event set\n",
                     "msm_geni_serial_handle_tx");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.SSR Down event set\n",
                   "msm_geni_serial_handle_tx");
    }
  }
  bVar11 = (uVar2 & 0x30) != 0;
  uVar23 = *(undefined8 *)(param_1 + 200);
  if ((uVar3 & 0x600) == 0) {
    if ((uVar3 & 0x1800) != 0) {
      pcVar25 = "%s.sirq 0x%x break:%d\n";
      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.sirq 0x%x break:%d\n",
                     "handle_rx_fifo_xfer",uVar3);
      uVar15 = *(undefined8 *)(param_1 + 0x150);
      uVar6 = *(undefined4 *)(param_1 + 0xf4);
      goto LAB_00106184;
    }
  }
  else {
    if ((uVar3 >> 9 & 1) != 0) {
      *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
    }
    pcVar25 = "%s.sirq 0x%x parity:%d\n";
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.sirq 0x%x parity:%d\n","handle_rx_fifo_xfer"
                   ,uVar3);
    uVar15 = *(undefined8 *)(param_1 + 0x150);
    uVar6 = *(undefined4 *)(param_1 + 0xf0);
LAB_00106184:
    __ftrace_dbg(uVar15,pcVar25,"handle_rx_fifo_xfer",uVar3,uVar6);
  }
  if ((uVar3 & 0xc000000) != 0) {
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x804);
    if ((uVar2 & 0x1ffffff) != 0) {
      if (*(int *)(*(code **)(param_1 + 600) + -4) != 0x9042c64) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1061e8);
        (*pcVar10)();
      }
      (**(code **)(param_1 + 600))
                (param_1,uVar2 & 0x1ffffff,uVar2 >> 0x1c & 7,uVar2 & 0x80000000,(uVar3 & 0x630) != 0
                );
    }
    if (((uVar3 & 0x630) == 0) && ((param_3 & 1) == 0)) {
      _raw_spin_unlock_irqrestore(param_1,*param_2);
      tty_flip_buffer_push(uVar23);
      uVar23 = _raw_spin_lock_irqsave(param_1);
      *param_2 = uVar23;
    }
    else if ((uVar3 & 0x630) == 0) {
      tty_flip_buffer_push(uVar23);
    }
  }
  bVar12 = (uVar3 & 0x30) != 0;
LAB_0010622c:
  lVar22 = *(long *)(param_1 + 0x3b8);
  if (((lVar22 != 0) && (uVar14 != 0)) && (*(int *)(param_1 + 900) != 0)) {
    lVar24 = sched_clock();
    ipc_log_string(lVar22,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_handle_isr",
                   lVar24 - uVar14,(lVar24 - uVar14) / 1000);
  }
  if (bVar11) {
    *(undefined1 *)(param_1 + 0x3fe) = 1;
    complete(param_1 + 0x408);
  }
  if ((bVar12 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x3ff) = 1;
    complete(param_1 + 0x428);
  }
  return;
}



//------------------------------------------------------------
// handle_rx_dma_xfer @ 001062b0 size=2916
// signature: undefined handle_rx_dma_xfer(void)
// callers: [stop_rx_sequencer, msm_geni_serial_handle_isr]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void handle_rx_dma_xfer(ulong param_1,long param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  char *pcVar14;
  uint uVar15;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar13 = sp_el0;
  local_70 = *(long *)(lVar13 + 0x638);
  lVar13 = *(long *)(param_2 + 0x3b8);
  if (lVar13 == 0) {
    uVar5 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_2 + 900) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = sched_clock();
    ipc_log_string(lVar13,"%s:start at %llu nsec(%llu usec)\n","handle_rx_dma_xfer",uVar5,
                   uVar5 / 1000);
  }
  uVar6 = _raw_spin_lock_irqsave(param_2 + 0x448);
  uVar1 = *(uint *)(*(long *)(param_2 + 0x10) + 0xd40);
  if (uVar1 == 0) {
    bVar2 = false;
    goto LAB_00106d1c;
  }
  *(uint *)(*(long *)(param_2 + 0x10) + 0xd44) = uVar1;
  if ((uVar1 >> 3 & 1) != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s Rx Reset done dma_rx_status=0x%x\n",
                   "handle_rx_dma_xfer",uVar1);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s Rx Reset done dma_rx_status=0x%x\n",
                 "handle_rx_dma_xfer",uVar1);
  }
  if ((uVar1 >> 5 & 1) != 0) {
    iVar12 = *(int *)(param_2 + 0xf0) + 1;
    *(int *)(param_2 + 0xf0) = iVar12;
    if (*(char *)(param_2 + 0x3fc) == '\0') {
      *(undefined4 *)(param_2 + 0x450) = 0x11;
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x11);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
      iVar12 = *(int *)(param_2 + 0xf0);
    }
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s dma_rx_status:0x%x Rx Parity error:%d\n",
                   "handle_rx_dma_xfer",uVar1,iVar12);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s dma_rx_status:0x%x Rx Parity error:%d\n",
                 "handle_rx_dma_xfer",uVar1,*(undefined4 *)(param_2 + 0xf0));
  }
  if ((uVar1 >> 6 & 1) != 0) {
    iVar12 = *(int *)(param_2 + 0xe8) + 1;
    *(int *)(param_2 + 0xe8) = iVar12;
    if (*(char *)(param_2 + 0x3fc) == '\0') {
      *(undefined4 *)(param_2 + 0x450) = 0x16;
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x16);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
      iVar12 = *(int *)(param_2 + 0xe8);
    }
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s dma_rx_status:0x%x Rx Framing error:%d\n",
                   "handle_rx_dma_xfer",uVar1,iVar12);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s dma_rx_status:0x%x Rx Framing error:%d\n",
                 "handle_rx_dma_xfer",uVar1,*(undefined4 *)(param_2 + 0xe8));
  }
  if ((uVar1 & 0x180) != 0) {
    *(int *)(param_2 + 0xf4) = *(int *)(param_2 + 0xf4) + 1;
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s dma_rx_status:0x%x Rx Break error:%d\n",
                   "handle_rx_dma_xfer",uVar1);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s dma_rx_status:0x%x Rx Break error:%d\n",
                 "handle_rx_dma_xfer",uVar1,*(undefined4 *)(param_2 + 0xf4));
    if (*(char *)(param_2 + 0x3fc) == '\0') {
      *(undefined4 *)(param_2 + 0x450) = 0x12;
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x12);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
    }
  }
  if ((uVar1 & 3) != 0) {
    if (*(char *)(param_2 + 0x840) == '\0') {
      lVar13 = *(long *)(param_2 + 0x3b8);
      if (lVar13 == 0) {
        uVar8 = 0xffffffffffffffea;
      }
      else if (*(int *)(param_2 + 900) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = sched_clock();
        ipc_log_string(lVar13,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_handle_dma_rx",
                       uVar8,uVar8 / 1000);
      }
      uVar15 = *(uint *)(*(long *)(param_2 + 0x10) + 0x40);
      if ((uVar15 >> 0xc & 1) == 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s: GENI: 0x%x\n",
                       "msm_geni_serial_handle_dma_rx",uVar15);
        __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: GENI: 0x%x\n",
                     "msm_geni_serial_handle_dma_rx",uVar15);
      }
      else {
        if (*(long *)(param_2 + 0x328) == 0) {
          uVar7 = *(undefined8 *)(param_2 + 0x3a0);
          pcVar14 = "%s: NULL Rx_buf\n";
          goto LAB_001065b4;
        }
        uVar15 = *(uint *)(*(long *)(param_2 + 0x10) + 0xd54);
        if (uVar15 == 0) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s: Size %d\n",
                         "msm_geni_serial_handle_dma_rx",0);
          __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: Size %d\n",
                       "msm_geni_serial_handle_dma_rx",0);
          uVar15 = 0;
        }
        else {
          if (((*(char *)(param_2 + 0x38c) != '\0') && (**(int **)(param_2 + 0x328) == 0)) &&
             (((int)uVar15 < 5 ||
              (*(int *)((long)*(int **)(param_2 + 0x328) + (ulong)(uVar15 - 4)) == 0)))) {
            ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s RX Invalid packet\n","check_rx_buf")
            ;
            __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s RX Invalid packet\n","check_rx_buf");
            geni_se_dump_dbg_regs(param_2);
            __const_udelay(0x8312b0);
          }
          if ((uVar1 >> 5 & 1) != 0) goto LAB_00106bd8;
          if (*(int *)(param_2 + 0x55c) == 0) {
LAB_00106784:
            uVar7 = *(undefined8 *)(param_2 + 200);
            uVar3 = tty_insert_flip_string_fixed_flag
                              (uVar7,*(undefined8 *)(param_2 + 0x328),0,uVar15);
            if (uVar15 == uVar3) {
              uVar3 = uVar15;
            }
            else {
              ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s: ret %d rx_bytes %d\n",
                             "msm_geni_serial_handle_dma_rx",uVar3,uVar15);
              __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: ret %d rx_bytes %d\n",
                           "msm_geni_serial_handle_dma_rx",uVar3,uVar15);
              uVar15 = uVar15 - uVar3;
              if (uVar15 != 0) {
                lVar9 = *(long *)(param_2 + 0x328);
                iVar12 = 0;
                lVar13 = (long)(int)uVar3;
                do {
                  uVar11 = uVar15;
                  if (0xff < uVar15) {
                    uVar11 = 0x100;
                  }
                  ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s: To copy %d, try copying %d\n"
                                 ,"msm_geni_serial_handle_dma_rx",uVar15,uVar11);
                  __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: To copy %d, try copying %d\n",
                               "msm_geni_serial_handle_dma_rx",uVar15,uVar11);
                  uVar4 = tty_insert_flip_string_fixed_flag
                                    (uVar7,lVar9 + lVar13 + (long)iVar12,0,uVar11);
                  if (uVar4 != uVar11) {
                    ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),
                                   "%s: Unable to copy %d bytes rx_bytes %d\n",
                                   "msm_geni_serial_handle_dma_rx",uVar11,uVar15);
                    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),
                                 "%s: Unable to copy %d bytes rx_bytes %d\n",
                                 "msm_geni_serial_handle_dma_rx",uVar11,uVar15);
                    msm_geni_update_uart_error_code(param_2,0xe);
                    break;
                  }
                  iVar12 = iVar12 + uVar11;
                  uVar15 = uVar15 - uVar11;
                  uVar3 = uVar11 + uVar3;
                } while (uVar15 != 0);
              }
            }
            *(uint *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + uVar3;
            tty_flip_buffer_push(uVar7);
            uVar7 = *(undefined8 *)(param_2 + 0x3a0);
            local_110 = 0;
            uVar11 = uVar3;
            if (0x1f < (int)uVar3) {
              uVar11 = 0x20;
            }
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_b0 = 0;
            uStack_a8 = 0;
            local_c0 = 0;
            uStack_b8 = 0;
            local_d0 = 0;
            uStack_c8 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            local_f0 = 0;
            uStack_e8 = 0;
            local_100 = 0;
            uStack_f8 = 0;
            local_108 = 0;
            hex_dump_to_buffer(*(undefined8 *)(param_2 + 0x328),(long)(int)uVar11,0x20,1,&local_b0,
                               0x40,0);
            scnprintf(&local_110,0x60,"%s[0x%.10x:%d] : %s","DMA Rx",0,uVar3,&local_b0);
            ipc_log_string(uVar7,"%s : %s\n","dump_ipc",&local_110);
            __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s : %s\n","dump_ipc",&local_110);
          }
          else {
            uVar7 = *(undefined8 *)(param_2 + 0x3a0);
            if (**(char **)(param_2 + 0x328) == *(char *)(param_2 + 0x38c)) {
              ipc_log_string(uVar7,"%s Found wakeup byte\n","msm_geni_find_wakeup_byte");
              __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s Found wakeup byte\n",
                           "msm_geni_find_wakeup_byte");
              *(undefined4 *)(param_2 + 0x55c) = 0;
              goto LAB_00106784;
            }
            uVar3 = uVar15;
            if (0x1f < (int)uVar15) {
              uVar3 = 0x20;
            }
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_b0 = 0;
            uStack_a8 = 0;
            local_c0 = 0;
            uStack_b8 = 0;
            local_d0 = 0;
            uStack_c8 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            local_f0 = 0;
            uStack_e8 = 0;
            local_100 = 0;
            uStack_f8 = 0;
            local_110 = 0;
            local_108 = 0;
            hex_dump_to_buffer(*(char **)(param_2 + 0x328),(long)(int)uVar3,0x20,1,&local_b0,0x40,0)
            ;
            scnprintf(&local_110,0x60,"%s[0x%.10x:%d] : %s","Dropped Rx",0,uVar15,&local_b0);
            ipc_log_string(uVar7,"%s : %s\n","dump_ipc",&local_110);
            __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s : %s\n","dump_ipc",&local_110);
            ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),
                           "%s dropping Rx data as wakeup byte not found in %d bytes\n",
                           "msm_geni_serial_handle_dma_rx",uVar15);
            __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),
                         "%s dropping Rx data as wakeup byte not found in %d bytes\n",
                         "msm_geni_serial_handle_dma_rx",uVar15);
            uVar3 = uVar15;
          }
          memset(*(void **)(param_2 + 0x328),0,(ulong)uVar3);
        }
        if (*(char *)(param_2 + 0x840) != '\0') goto LAB_001065a8;
        if (((*(uint *)(param_2 + 0x450) < 0x17) &&
            ((1 << (ulong)(*(uint *)(param_2 + 0x450) & 0x1f) & 0x460000U) != 0)) &&
           (*(char *)(param_2 + 0x3fc) == '\0')) {
          *(undefined4 *)(param_2 + 0x450) = 0;
          ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s uart_error_code %d",
                         "msm_geni_update_uart_error_code",0);
          __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                       "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
        }
        lVar13 = *(long *)(param_2 + 0x3b8);
        if (((lVar13 != 0) && (uVar8 != 0)) && (*(int *)(param_2 + 900) != 0)) {
          iVar12 = *(int *)(param_2 + 0x3d8);
          lVar9 = sched_clock();
          uVar8 = lVar9 - uVar8;
          uVar10 = uVar8 / 1000;
          if (uVar15 == 0) {
            ipc_log_string(lVar13,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_handle_dma_rx",
                           uVar8,uVar10);
          }
          else if (iVar12 == 0) {
            ipc_log_string(lVar13,"%s:took %llu nsec(%llu usec) for %u bytes\n",
                           "msm_geni_serial_handle_dma_rx",uVar8,uVar10,uVar15);
          }
          else {
            ipc_log_string(lVar13,"%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                           "msm_geni_serial_handle_dma_rx",uVar8,uVar10,uVar15,iVar12);
          }
        }
      }
    }
    else {
LAB_001065a8:
      uVar7 = *(undefined8 *)(param_2 + 0x3b0);
      pcVar14 = "%s: SSR Down event set\n";
LAB_001065b4:
      ipc_log_string(uVar7,pcVar14,"msm_geni_serial_handle_dma_rx");
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),pcVar14,"msm_geni_serial_handle_dma_rx");
    }
LAB_00106bd8:
    if ((uVar1 >> 0xb & 1) == 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s mapping rx dma\n","handle_rx_dma_xfer");
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s mapping rx dma\n","handle_rx_dma_xfer");
      lVar13 = *(long *)(param_2 + 0x10);
      if ((lVar13 != 0) && (*(long *)(param_2 + 0x358) != 0)) {
        *(undefined4 *)(lVar13 + 0xd4c) = 7;
        *(undefined4 *)(lVar13 + 0xd30) = *(undefined4 *)(param_2 + 0x358);
        *(undefined4 *)(lVar13 + 0xd34) = *(undefined4 *)(param_2 + 0x35c);
        *(undefined4 *)(lVar13 + 0xd38) = 0;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(lVar13 + 0xd3c) = 0x800;
      }
    }
    else {
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s not mapping rx dma\n","handle_rx_dma_xfer"
                    );
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s not mapping rx dma\n","handle_rx_dma_xfer");
    }
  }
  if ((uVar1 >> 2 & 1) != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s dma_rx_status:0x%x\n","handle_rx_dma_xfer",
                   uVar1);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s dma_rx_status:0x%x\n","handle_rx_dma_xfer",
                 uVar1);
    if (*(char *)(param_2 + 0x3fc) == '\0') {
      *(undefined4 *)(param_2 + 0x450) = 0x13;
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",0x13);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
    }
  }
  bVar2 = (uVar1 & 0x80b) != 0;
LAB_00106d1c:
  _raw_spin_unlock_irqrestore(param_2 + 0x448,uVar6);
  lVar13 = *(long *)(param_2 + 0x3b8);
  if (((lVar13 != 0) && (uVar5 != 0)) && (*(int *)(param_2 + 900) != 0)) {
    lVar9 = sched_clock();
    ipc_log_string(lVar13,"%s:took %llu nsec(%llu usec)\n","handle_rx_dma_xfer",lVar9 - uVar5,
                   (lVar9 - uVar5) / 1000);
  }
  lVar13 = sp_el0;
  if ((param_1 & 0x30) != 0) {
    bVar2 = true;
  }
  if (*(long *)(lVar13 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_handle_dma_tx @ 00106e14 size=740
// signature: undefined msm_geni_serial_handle_dma_tx(void)
// callers: [msm_geni_serial_handle_isr]
//------------------------------------------------------------

void msm_geni_serial_handle_dma_tx(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  if (*(char *)(param_1 + 0x840) == '\0') {
    lVar9 = *(long *)(param_1 + 200);
    *(uint *)(lVar9 + 0x1d4) = *(int *)(param_1 + 800) + *(int *)(lVar9 + 0x1d4) & 0xfff;
    if (*(long *)(param_1 + 0x318) != 0) {
      geni_se_tx_dma_unprep
                (param_1 + 0x2b8,*(long *)(param_1 + 0x318),*(undefined4 *)(param_1 + 800));
    }
    if (*(int *)(param_1 + 900) != 0) {
      if (4 < *(uint *)(param_1 + 0x234)) {
LAB_001070f4:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1070f8);
        (*pcVar4)();
      }
      *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 0x234) * 0x30 + 0x648) =
           *(undefined4 *)(param_1 + 800);
      lVar5 = sched_clock();
      if (4 < *(uint *)(param_1 + 0x234)) goto LAB_001070f4;
      lVar7 = param_1 + (ulong)*(uint *)(param_1 + 0x234) * 0x30;
      uVar2 = *(undefined4 *)(param_1 + 0x3d8);
      uVar3 = *(undefined4 *)(lVar7 + 0x648);
      *(long *)(lVar7 + 0x650) = lVar5;
      uVar8 = lVar5 - *(long *)(lVar7 + 0x630);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b8),
                     "%s:TX transfer time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n"
                     ,"msm_geni_serial_handle_dma_tx",uVar8,uVar8 / 1000,uVar3,uVar2);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                   "%s:TX transfer time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n",
                   "msm_geni_serial_handle_dma_tx",uVar8,uVar8 / 1000,uVar3,
                   *(undefined4 *)(param_1 + 0x3d8),*(undefined4 *)(param_1 + 0x234));
      if (4 < *(uint *)(param_1 + 0x234)) goto LAB_001070f4;
      uVar8 = lVar5 - *(long *)(param_1 + (ulong)*(uint *)(param_1 + 0x234) * 0x30 + 0x640);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b8),
                     "%s:TX Hardware time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n"
                     ,"msm_geni_serial_handle_dma_tx",uVar8,uVar8 / 1000,uVar3,
                     *(undefined4 *)(param_1 + 0x3d8));
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                   "%s:TX Hardware time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n",
                   "msm_geni_serial_handle_dma_tx",uVar8,uVar8 / 1000,uVar3,
                   *(undefined4 *)(param_1 + 0x3d8),*(undefined4 *)(param_1 + 0x234));
      iVar1 = 0;
      if (*(int *)(param_1 + 0x234) + 1U < 5) {
        iVar1 = *(int *)(param_1 + 0x234) + 1;
      }
      *(int *)(param_1 + 0x234) = iVar1;
    }
    iVar1 = *(int *)(param_1 + 800);
    *(undefined8 *)(param_1 + 0x318) = 0;
    *(undefined4 *)(param_1 + 800) = 0;
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + iVar1;
    if (*(int *)(lVar9 + 0x1d0) == *(int *)(lVar9 + 0x1d4)) {
      if ((*(long *)(param_1 + 0x100) == 0) ||
         (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s.Tx sent out, Power off\n",
                       "msm_geni_serial_handle_dma_tx");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s.Tx sent out, Power off\n",
                     "msm_geni_serial_handle_dma_tx");
        lVar9 = *(long *)(param_1 + 0x150);
        if (*(int *)(lVar9 + 0x1f8) == 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s: Usage Count is already 0\n",
                         "msm_geni_serial_power_off");
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Usage Count is already 0\n",
                       "msm_geni_serial_power_off");
        }
        else if ((*(ushort *)(lVar9 + 0x200) & 7) == 0) {
          uVar6 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar9 + 0x220) = uVar6;
          __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x150),0xd);
        }
      }
      uart_write_wakeup(param_1);
    }
    else {
      msm_geni_serial_prep_dma_tx(param_1);
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_handle_dma_tx");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_handle_dma_tx");
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_prep_dma_tx @ 001070f8 size=1820
// signature: undefined msm_geni_serial_prep_dma_tx(void)
// callers: [msm_geni_serial_handle_dma_tx, msm_geni_serial_start_tx]
//------------------------------------------------------------

int msm_geni_serial_prep_dma_tx(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  uint uVar10;
  long lVar11;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  if (*(char *)(param_1 + 0x840) == '\0') {
    lVar8 = *(long *)(param_1 + 0x3b8);
    lVar11 = *(long *)(param_1 + 200);
    if (lVar8 == 0) {
      uVar6 = 0xffffffffffffffea;
      iVar4 = *(int *)(param_1 + 0x610);
    }
    else if (*(int *)(param_1 + 900) == 0) {
      uVar6 = 0;
      iVar4 = *(int *)(param_1 + 0x610);
    }
    else {
      uVar6 = sched_clock();
      ipc_log_string(lVar8,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_prep_dma_tx",uVar6,
                     uVar6 / 1000);
      iVar4 = *(int *)(param_1 + 0x610);
    }
    if (iVar4 == 0) {
      iVar4 = *(int *)(lVar11 + 0x1d4);
      uVar5 = *(int *)(lVar11 + 0x1d0) - iVar4 & 0xfff;
      if (uVar5 < 0x100) {
        uart_write_wakeup(param_1);
        iVar4 = *(int *)(lVar11 + 0x1d4);
      }
      uVar7 = 0x1000 - (long)iVar4;
      uVar10 = (uint)uVar7;
      if (uVar5 <= uVar7) {
        uVar10 = uVar5;
      }
      if (uVar10 == 0) {
        iVar4 = -1;
      }
      else {
        uVar5 = uVar10;
        if (0x1f < (int)uVar10) {
          uVar5 = 0x20;
        }
        uVar9 = *(undefined8 *)(param_1 + 0x398);
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d8 = 0;
        uStack_d0 = 0;
        local_e8 = 0;
        uStack_e0 = 0;
        local_f8 = 0;
        uStack_f0 = 0;
        local_108 = 0;
        uStack_100 = 0;
        hex_dump_to_buffer(*(long *)(lVar11 + 0x1c8) + (long)iVar4,(long)(int)uVar5,0x20,1,&local_a8
                           ,0x40,0);
        scnprintf(&local_108,0x60,"%s[0x%.10x:%d] : %s","DMA Tx",0,uVar10,&local_a8);
        ipc_log_string(uVar9,"%s : %s\n","dump_ipc",&local_108);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s : %s\n","dump_ipc",&local_108);
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: cts_count:%d\n",
                       "msm_geni_serial_prep_dma_tx",*(undefined4 *)(param_1 + 0xd0));
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: cts_count:%d\n",
                     "msm_geni_serial_prep_dma_tx",*(undefined4 *)(param_1 + 0xd0));
        if (*(int *)(param_1 + 900) != 0) {
          if (4 < *(uint *)(param_1 + 0x230)) {
LAB_00107810:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x107814);
            (*pcVar3)();
          }
          *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 0x230) * 0x30 + 0x638) =
               *(undefined4 *)(param_1 + 800);
          uVar9 = sched_clock();
          uVar5 = *(uint *)(param_1 + 0x230);
          if (4 < uVar5) goto LAB_00107810;
          iVar4 = 0;
          if (uVar5 != 4) {
            iVar4 = uVar5 + 1;
          }
          *(int *)(param_1 + 0x230) = iVar4;
          *(undefined8 *)(param_1 + (ulong)uVar5 * 0x30 + 0x640) = uVar9;
        }
        *(uint *)(*(long *)(param_1 + 0x10) + 0x270) = uVar10;
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x600) = 0x8000000;
        DataSynchronizationBarrier(3,3,0);
        iVar4 = geni_se_tx_dma_prep(param_1 + 0x2b8,
                                    *(long *)(lVar11 + 0x1c8) + (long)*(int *)(lVar11 + 0x1d4),
                                    uVar10,(long *)(param_1 + 0x318));
        if (iVar4 == 0) {
          *(uint *)(param_1 + 800) = uVar10;
        }
        else {
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: TX DMA map Fail %d\n",
                         "msm_geni_serial_prep_dma_tx",iVar4);
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: TX DMA map Fail %d\n",
                       "msm_geni_serial_prep_dma_tx",iVar4);
          if (*(char *)(param_1 + 0x3fc) == '\0') {
            *(undefined4 *)(param_1 + 0x450) = 7;
            ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                           "msm_geni_update_uart_error_code",7);
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                         "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
          }
          *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x270) = 0;
          *(undefined1 *)(param_1 + 0x3fe) = 0;
          *(undefined1 *)(param_1 + 0x400) = 1;
          *(undefined4 *)(param_1 + 0x408) = 0;
          uVar5 = msm_serial_try_disable_interrupts(param_1);
          *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 4;
          uVar7 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
          if ((uVar7 & 1) != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s: tx_cancel fail 0x%x\n",
                           "msm_geni_serial_prep_dma_tx",
                           *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx_cancel failed 0x%x\n",
                           "msm_geni_serial_prep_dma_tx",
                           *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx_cancel failed 0x%x\n",
                         "msm_geni_serial_prep_dma_tx",
                         *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
            if (*(char *)(param_1 + 0x3fc) == '\0') {
              *(undefined4 *)(param_1 + 0x450) = 8;
              ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                             "msm_geni_update_uart_error_code",8);
              __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                           "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
            }
            geni_se_dump_dbg_regs(param_1);
            *(undefined1 *)(param_1 + 0x3fe) = 0;
            *(undefined4 *)(param_1 + 0x408) = 0;
            *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 2;
            uVar7 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
            if ((uVar7 & 1) == 0) {
              msm_geni_update_uart_error_code(param_1,0);
            }
            else {
              ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),"%s: tx abort failed 0x%x\n",
                             "msm_geni_serial_prep_dma_tx",
                             *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
              ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx abort failed 0x%x\n",
                             "msm_geni_serial_prep_dma_tx",
                             *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
              __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx abort failed 0x%x\n",
                           "msm_geni_serial_prep_dma_tx",
                           *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
              msm_geni_update_uart_error_code(param_1,9);
              geni_se_dump_dbg_regs(param_1);
            }
            *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac) = 0x80000001;
            DataSynchronizationBarrier(3,3,0);
            uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac);
            ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s(): rfr = 0x%x\n",
                           "msm_geni_serial_allow_rx",uVar1);
            __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s(): rfr = 0x%x\n",
                         "msm_geni_serial_allow_rx",uVar1);
            msm_geni_serial_set_manual_flow(1,param_1);
            *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x20) = 1;
          }
          if (*(int *)(param_1 + 0x238) == 2) {
            if ((*(uint *)(*(long *)(param_1 + 0x10) + 0xe40) & 1) != 0) {
              *(undefined1 *)(param_1 + 0x3fe) = 0;
              *(undefined4 *)(param_1 + 0x408) = 0;
              *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xc58) = 1;
              uVar7 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
              if ((uVar7 & 1) == 0) {
                msm_geni_update_uart_error_code(param_1,0);
              }
              else {
                ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: tx fsm reset failed\n",
                               "msm_geni_serial_prep_dma_tx");
                __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: tx fsm reset failed\n",
                             "msm_geni_serial_prep_dma_tx");
                msm_geni_update_uart_error_code(param_1,10);
                geni_se_dump_dbg_regs(param_1);
              }
            }
            lVar8 = *(long *)(param_1 + 0x318);
            if (lVar8 != 0) {
              geni_se_tx_dma_unprep(param_1 + 0x2b8,lVar8,*(undefined4 *)(param_1 + 800));
              *(undefined8 *)(param_1 + 0x318) = 0;
            }
          }
          *(undefined4 *)(param_1 + 800) = 0;
          msm_geni_serial_enable_interrupts(param_1);
          uVar10 = *(uint *)(param_1 + 800);
          *(undefined1 *)(param_1 + 0x400) = 0;
        }
        lVar8 = *(long *)(param_1 + 0x3b8);
        if (((lVar8 != 0) && (uVar6 != 0)) && (*(int *)(param_1 + 900) != 0)) {
          iVar2 = *(int *)(param_1 + 0x3d8);
          lVar11 = sched_clock();
          uVar6 = lVar11 - uVar6;
          uVar7 = uVar6 / 1000;
          if (uVar10 == 0) {
            ipc_log_string(lVar8,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_prep_dma_tx",
                           uVar6,uVar7);
          }
          else if (iVar2 == 0) {
            ipc_log_string(lVar8,"%s:took %llu nsec(%llu usec) for %u bytes\n",
                           "msm_geni_serial_prep_dma_tx",uVar6,uVar7,uVar10);
          }
          else {
            ipc_log_string(lVar8,"%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                           "msm_geni_serial_prep_dma_tx",uVar6,uVar7,uVar10,iVar2);
          }
        }
      }
    }
    else {
      iVar4 = -5;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_prep_dma_tx");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_prep_dma_tx");
    iVar4 = -0x16;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_geni_serial_set_manual_flow @ 00107814 size=432
// signature: undefined msm_geni_serial_set_manual_flow(void)
// callers: [stop_rx_sequencer, msm_geni_serial_runtime_suspend, stop_tx_sequencer, msm_geni_serial_prep_dma_tx, msm_geni_serial_allow_rx, msm_geni_serial_config_baud_rate]
//------------------------------------------------------------

void msm_geni_serial_set_manual_flow(ulong param_1,long param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (*(char *)(param_2 + 0x840) == '\0') {
    puVar1 = (undefined4 *)(*(long *)(param_2 + 0x10) + 0x2ac);
    if ((param_1 & 1) == 0) {
      *puVar1 = 0x80000000;
      __const_udelay(0xa7c6);
      *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x2ac) = 0x80000002;
      DataSynchronizationBarrier(3,3,0);
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),
                     "%s: Manual Flow Enabled, HW Flow OFF rfr = 0x%x\n",
                     "msm_geni_serial_set_manual_flow",0x80000002);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),
                   "%s: Manual Flow Enabled, HW Flow OFF rfr = 0x%x\n",
                   "msm_geni_serial_set_manual_flow",0x80000002);
      if (*(char *)(param_2 + 0x3fc) != '\0') {
        return;
      }
      uVar3 = *(undefined8 *)(param_2 + 0x3b0);
      *(undefined4 *)(param_2 + 0x450) = 0x15;
      uVar4 = 0x15;
    }
    else {
      *puVar1 = 0;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x2ac);
      ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),
                     "%s: Manual Flow Disabled, HW Flow ON rfr = 0x%x\n",
                     "msm_geni_serial_set_manual_flow",uVar2);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),
                   "%s: Manual Flow Disabled, HW Flow ON rfr = 0x%x\n",
                   "msm_geni_serial_set_manual_flow",uVar2);
      if (*(int *)(param_2 + 0x450) != 0x15) {
        return;
      }
      if (*(char *)(param_2 + 0x3fc) != '\0') {
        return;
      }
      uVar3 = *(undefined8 *)(param_2 + 0x3b0);
      uVar4 = 0;
      *(undefined4 *)(param_2 + 0x450) = 0;
    }
    ipc_log_string(uVar3,"%s uart_error_code %d","msm_geni_update_uart_error_code",uVar4);
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s uart_error_code %d",
                 "msm_geni_update_uart_error_code",*(undefined4 *)(param_2 + 0x450));
  }
  else {
    ipc_log_string(*(undefined8 *)(param_2 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_set_manual_flow");
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_set_manual_flow");
  }
  return;
}



//------------------------------------------------------------
// stop_rx_sequencer @ 001079c4 size=1912
// signature: undefined stop_rx_sequencer(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_stop_rx]
//------------------------------------------------------------

void stop_rx_sequencer(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  local_60 = 0;
  if (*(char *)(param_1 + 0x840) != '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n","stop_rx_sequencer");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n","stop_rx_sequencer");
    uVar7 = 0;
    goto LAB_001080b0;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s %d\n","stop_rx_sequencer",1);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s %d\n","stop_rx_sequencer",1);
  if (*(int *)(param_1 + 0x554) != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: already in progress, return\n",
                   "stop_rx_sequencer");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: already in progress, return\n",
                 "stop_rx_sequencer");
    uVar7 = 0xfffffff0;
    goto LAB_001080b0;
  }
  *(undefined4 *)(param_1 + 0x554) = 1;
  uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
  if ((uVar7 >> 0xc & 1) == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: RX is Inactive, geni_sts: 0x%x\n",
                   "stop_rx_sequencer",uVar7);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: RX is Inactive, geni_sts: 0x%x\n",
                 "stop_rx_sequencer",uVar7);
    *(undefined4 *)(param_1 + 0x554) = 0;
    complete(param_1 + 0x510);
    uVar7 = 0;
    goto LAB_001080b0;
  }
  if (*(char *)(param_1 + 0x460) == '\0') {
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      msm_geni_serial_set_manual_flow(0,param_1);
      uVar6 = 0;
      if (*(uint *)(param_1 + 0x3d8) != 0) {
        uVar6 = 160000000 / *(uint *)(param_1 + 0x3d8);
      }
      uVar6 = uVar6 << 1;
      if (0x251b < uVar6) {
        uVar6 = 0x251c;
      }
      iVar1 = uVar6 + 500;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"stale_delay = %d usecs\n",iVar1);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"stale_delay = %d usecs\n",iVar1);
      __udelay(iVar1);
      if (*(int *)(*(long *)(param_1 + 0x10) + 0xd40) != 0) {
        uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x640);
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x648) = uVar2;
        geni_se_dump_dbg_regs(param_1);
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Interrupt delay\n","stop_rx_sequencer")
        ;
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Interrupt delay\n","stop_rx_sequencer");
        handle_rx_dma_xfer(uVar2,param_1);
        if (((*(ushort *)(*(long *)(param_1 + 0x150) + 0x200) & 7) == 0) &&
           (*(int *)(param_1 + 0x3dc) == 0)) {
          uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x150) + 0x1f8);
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                         "%s: Abort Stop Rx, extend the PM timer, usage_count:%d\n",
                         "stop_rx_sequencer",uVar2);
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                       "%s: Abort Stop Rx, extend the PM timer, usage_count:%d\n",
                       "stop_rx_sequencer",uVar2);
          lVar10 = *(long *)(param_1 + 0x150);
          uVar9 = ktime_get_mono_fast_ns();
          uVar7 = 0xfffffff0;
          *(undefined8 *)(lVar10 + 0x220) = uVar9;
          goto LAB_001080ac;
        }
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Start 0x%x\n","stop_rx_sequencer",uVar7);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Start 0x%x\n","stop_rx_sequencer",uVar7);
    uVar5 = msm_serial_try_disable_interrupts(param_1);
    *(undefined1 *)(param_1 + 0x3ff) = 0;
    *(undefined4 *)(param_1 + 0x428) = 0;
    *(undefined1 *)(param_1 + 0x401) = 1;
    *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x634) = 4;
    DataSynchronizationBarrier(3,3,0);
    uVar6 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
    uVar3 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
    uVar7 = uVar3 & 0x1000;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: geni_status 0x%x, dma_dbg:0x%x\n",
                   "stop_rx_sequencer",uVar3,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: geni_status 0x%x, dma_dbg:0x%x\n",
                 "stop_rx_sequencer",uVar3,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    if (((uVar6 & 1) == 0) && (uVar7 == 0)) goto LAB_00108008;
    uVar6 = uVar6 & 1;
    uVar4 = uVar7 >> 0xc;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                   "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6,
                   uVar4,uVar3);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                 "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6,
                 uVar4,uVar3);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),
                   "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6,
                   uVar4,uVar3);
    msm_geni_update_uart_error_code(param_1,0xb);
    geni_se_dump_dbg_regs(param_1);
    if ((*(long *)(param_1 + 0x100) == 0) ||
       ((*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a) ||
        (uVar7 != 0)))) {
      *(undefined1 *)(param_1 + 0x3ff) = 0;
      uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x640);
      if ((uVar7 >> 4 & 1) == 0) {
        *(undefined4 *)(param_1 + 0x428) = 0;
        *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x634) = 2;
        DataSynchronizationBarrier(3,3,0);
        uVar6 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
        uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 0x1000;
        if (((uVar6 & 1) == 0) && (uVar7 == 0)) {
          msm_geni_update_uart_error_code(param_1,0);
        }
        else {
          uVar6 = uVar6 & 1;
          uVar7 = uVar7 >> 0xc;
          uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                         "%s abort fail timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6
                         ,uVar7,uVar2);
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                       "%s abort fail timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6,
                       uVar7,uVar2);
          ipc_log_string(*(undefined8 *)(param_1 + 0x3c8),
                         "%s abort fail timeout:%d is_rx_active:%d 0x%x\n","stop_rx_sequencer",uVar6
                         ,uVar7,uVar2);
          msm_geni_update_uart_error_code(param_1,0xc);
          geni_se_dump_dbg_regs(param_1);
        }
        if (((*(long *)(param_1 + 0x100) == 0) ||
            (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
           (*(char *)(param_1 + 0x3e0) == '\0')) {
          msm_geni_serial_allow_rx(param_1);
        }
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x20) = 1;
        if (*(int *)(param_1 + 0x238) == 2) {
          *(undefined1 *)(param_1 + 0x3ff) = 0;
          *(undefined4 *)(param_1 + 0x428) = 0;
          *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xd58) = 1;
          uVar8 = geni_wait_for_cmd_done(param_1,uVar5 & 1);
          if ((uVar8 & 1) == 0) goto LAB_00107ffc;
          ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: rx fsm reset failed\n",
                         "stop_rx_sequencer");
          __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: rx fsm reset failed\n",
                       "stop_rx_sequencer");
          msm_geni_update_uart_error_code(param_1,0xd);
          geni_se_dump_dbg_regs(param_1);
        }
      }
      else {
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x648) = 0x10;
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s Cancel Command succeeded 0x%x\n",
                       "stop_rx_sequencer",uVar7);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s Cancel Command succeeded 0x%x\n",
                     "stop_rx_sequencer",uVar7);
LAB_00107ffc:
        msm_geni_update_uart_error_code(param_1,0);
      }
LAB_00108008:
      msm_geni_serial_enable_interrupts(param_1);
      *(undefined1 *)(param_1 + 0x401) = 0;
    }
    else {
      msm_geni_serial_handle_isr(param_1,&local_60,1);
    }
    if (((*(long *)(param_1 + 0x100) == 0) ||
        (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) &&
       (*(char *)(param_1 + 0x3e0) == '\0')) {
      msm_geni_serial_set_manual_flow(1,param_1);
    }
    uVar7 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: End geni_status : 0x%x dma_dbg:0x%x\n",
                   "stop_rx_sequencer",uVar7,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: End geni_status : 0x%x dma_dbg:0x%x\n",
                 "stop_rx_sequencer",uVar7,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    complete(param_1 + 0x510);
    uVar7 = -(uVar7 >> 0xc & 1) & 0xfffffff0;
  }
  else {
    if ((*(char *)(param_1 + 0x248) != '\0') || (*(char *)(param_1 + 0x559) != '\0')) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Queue Rx Work\n","stop_rx_sequencer");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Queue Rx Work\n","stop_rx_sequencer");
      *(undefined4 *)(param_1 + 0x510) = 0;
      queue_work_on(0x20,*(undefined8 *)(param_1 + 0x508),param_1 + 0x4a0);
      uVar7 = 0;
      goto LAB_001080b0;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Port setup not yet done\n",
                   "stop_rx_sequencer");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Port setup not yet done\n",
                 "stop_rx_sequencer");
    uVar7 = 0;
  }
LAB_001080ac:
  *(undefined4 *)(param_1 + 0x554) = 0;
LAB_001080b0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// wait_for_transfers_inflight @ 0010813c size=604
// signature: undefined wait_for_transfers_inflight(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_break_ctl, msm_geni_serial_ioctl]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 wait_for_transfers_inflight(long param_1)

{
  bool bVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x840) != '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "wait_for_transfers_inflight");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "wait_for_transfers_inflight");
    return 0xffffffea;
  }
  if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) >> 0xc & 1) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x238) == 2) {
    bVar1 = *(long *)(param_1 + 0x318) == 0;
    iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0xd54);
  }
  else {
    bVar1 = *(int *)(*(long *)(param_1 + 0x10) + 0x800) == 0;
    iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0x804);
  }
  if ((((iVar2 != 0) || ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 1) != 0)) || (!bVar1)) ||
     (*(int *)(*(long *)(param_1 + 200) + 0x1d0) != *(int *)(*(long *)(param_1 + 200) + 0x1d4))) {
    usleep_range_state(100,0x96,2);
    if (*(int *)(param_1 + 0x238) == 2) {
      bVar1 = *(long *)(param_1 + 0x318) == 0;
      iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0xd54);
    }
    else {
      bVar1 = *(int *)(*(long *)(param_1 + 0x10) + 0x800) == 0;
      iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0x804);
    }
    if (((iVar2 != 0) || ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 1) != 0)) ||
       ((!bVar1 ||
        (*(int *)(*(long *)(param_1 + 200) + 0x1d0) != *(int *)(*(long *)(param_1 + 200) + 0x1d4))))
       ) {
      usleep_range_state(100,0x96,2);
    }
  }
  if (*(int *)(param_1 + 0x238) == 2) {
    bVar1 = *(long *)(param_1 + 0x318) == 0;
    iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0xd54);
  }
  else {
    bVar1 = *(int *)(*(long *)(param_1 + 0x10) + 0x800) == 0;
    iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0x804);
  }
  if (((iVar2 != 0) || ((*(uint *)(*(long *)(param_1 + 0x10) + 0x40) & 1) != 0)) ||
     ((!bVar1 ||
      (*(int *)(*(long *)(param_1 + 200) + 0x1d0) != *(int *)(*(long *)(param_1 + 200) + 0x1d4)))))
  {
    iVar2 = *(int *)(*(long *)(param_1 + 0x10) + 0xd54);
    if (iVar2 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Bailout rx_len_in is set %d\n",
                     "wait_for_transfers_inflight",iVar2);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Bailout rx_len_in is set %d\n",
                   "wait_for_transfers_inflight",iVar2);
      return 0xfffffff0;
    }
    geni_se_dump_dbg_regs(param_1);
  }
  return 0;
}



//------------------------------------------------------------
// msm_geni_serial_power_on @ 00108398 size=568
// signature: undefined msm_geni_serial_power_on(void)
// callers: [msm_geni_serial_startup, msm_geni_wakeup_work, xfer_mode_store, msm_geni_serial_runtime_resume, msm_geni_serial_shutdown, msm_geni_serial_ioctl, msm_geni_serial_set_termios]
//------------------------------------------------------------

int msm_geni_serial_power_on(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  
  mutex_lock(param_1 + 0x810);
  if (*(char *)(param_1 + 0x840) == '\0') {
    lVar7 = *(long *)(param_1 + 0x150);
    if ((*(ushort *)(lVar7 + 0x200) & 7) == 0) {
      iVar5 = __pm_runtime_resume(lVar7,4);
      if (iVar5 < 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s Err\n","msm_geni_serial_power_on");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s Err\n","msm_geni_serial_power_on");
        piVar1 = (int *)(*(long *)(param_1 + 0x150) + 0x1f8);
        iVar6 = *(int *)(*(long *)(param_1 + 0x150) + 0x1f8);
        do {
          if (iVar6 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar6) goto LAB_00108528;
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = iVar6 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00108528:
          bVar4 = iVar6 != iVar2;
          iVar6 = iVar2;
        } while (bVar4);
        __pm_runtime_set_status(*(undefined8 *)(param_1 + 0x150),2);
        goto LAB_001085ac;
      }
    }
    else if (*(int *)(lVar7 + 0x20c) == 2) {
      lVar7 = *(long *)(param_1 + 200) + 0x120;
      iVar5 = mutex_trylock(lVar7);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s:Manual resume\n",
                     "msm_geni_serial_power_on");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Manual resume\n","msm_geni_serial_power_on")
      ;
      __pm_runtime_disable(*(undefined8 *)(param_1 + 0x150),1);
      iVar6 = msm_geni_serial_runtime_resume(*(undefined8 *)(param_1 + 0x150));
      if (iVar6 == 0) {
        piVar1 = (int *)(*(long *)(param_1 + 0x150) + 0x1f8);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        __pm_runtime_set_status(*(undefined8 *)(param_1 + 0x150),0);
      }
      else {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3a8),"%s:Manual RPM CB failed %d\n",
                       "msm_geni_serial_power_on",iVar6);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s:Manual RPM CB failed %d\n",
                     "msm_geni_serial_power_on",iVar6);
      }
      pm_runtime_enable(*(undefined8 *)(param_1 + 0x150));
      if (iVar5 != 0) {
        mutex_unlock(lVar7);
        iVar5 = 0;
        goto LAB_001085ac;
      }
    }
    iVar5 = 0;
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_power_on");
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n",
                 "msm_geni_serial_power_on");
    iVar5 = -0x16;
  }
LAB_001085ac:
  mutex_unlock(param_1 + 0x810);
  return iVar5;
}



//------------------------------------------------------------
// msm_geni_serial_port_setup @ 001085f0 size=1988
// signature: undefined msm_geni_serial_port_setup(void)
// callers: [msm_geni_serial_startup, msm_geni_serial_sys_hib_resume, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

void msm_geni_serial_port_setup(long param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_7c;
  undefined8 local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x3b8);
  local_70 = 0;
  if (lVar9 == 0) {
    uVar5 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = sched_clock();
    ipc_log_string(lVar9,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_port_setup",uVar5,
                   uVar5 / 1000);
  }
  lVar9 = param_1 + 0x2b8;
  *(uint *)(param_1 + 0x22c) = *(uint *)(param_1 + 0x220) - 2;
  if ((*(long *)(param_1 + 0x100) == 0) ||
     (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
    uVar8 = *(uint *)(param_1 + 0x220) >> 1;
  }
  else {
    uVar8 = 2;
  }
  *(uint *)(param_1 + 0x228) = uVar8;
  *(undefined4 *)(param_1 + 0x224) = 2;
  *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x294) = 0xa0;
  if (*(char *)(param_1 + 0x460) == '\0') {
    if ((*(long *)(param_1 + 0x100) == 0) ||
       (*(int *)(param_1 + 0x134) != (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))) {
      *(undefined4 *)(param_1 + 0x238) = 2;
      geni_se_config_packing(lVar9,8,4,0,1,0);
      geni_se_config_packing(lVar9,8,4,0,0,1);
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x240) = 0x431c;
      if (*(long *)(param_1 + 0x250) == 0) {
LAB_00108b48:
        uVar6 = 0xfffffff4;
        goto LAB_00108b4c;
      }
      if (*(long *)(param_1 + 0x328) == 0) {
        if (*(long *)(param_1 + 0x260) == 0) {
          *(undefined8 *)(param_1 + 0x358) = 0;
          *(undefined8 *)(param_1 + 0x328) = 0xffffffffffffffea;
        }
        else {
          local_70 = 0xffffffffffffffff;
          lVar7 = dma_alloc_attrs(*(long *)(param_1 + 0x260),0x800,&local_70,0xcc0,0);
          *(long *)(param_1 + 0x328) = lVar7;
          if (lVar7 == 0) goto LAB_00108b48;
          *(undefined8 *)(param_1 + 0x358) = local_70;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x238) = 1;
      msm_serial_try_disable_interrupts(param_1);
      if ((*(long *)(param_1 + 0x1f8) == 0) ||
         ((*(long *)(param_1 + 0x100) != 0 &&
          (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))))) {
        uVar10 = 1000;
      }
      else {
        uVar8 = 0x1c200;
        if (*(uint *)(param_1 + 0x3d8) != 0) {
          uVar8 = *(uint *)(param_1 + 0x3d8);
        }
        uVar10 = 0;
        if ((ulong)uVar8 != 0) {
          uVar10 = ((ulong)(uint)(*(int *)(param_1 + 0x21c) * *(int *)(param_1 + 0x218)) * 1000000)
                   / (ulong)uVar8;
        }
        uVar10 = uVar10 / 10 + 0x32;
      }
      iVar11 = 1;
      do {
        if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x610) & 1) != 0) goto LAB_00108d54;
        __const_udelay(0xa7c6);
        uVar1 = (ulong)iVar11;
        iVar11 = iVar11 + 1;
      } while (uVar1 < uVar10);
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x604) = 4;
      if ((*(long *)(param_1 + 0x1f8) == 0) ||
         ((*(long *)(param_1 + 0x100) != 0 &&
          (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))))) {
        uVar10 = 1000;
      }
      else {
        uVar8 = 0x1c200;
        if (*(uint *)(param_1 + 0x3d8) != 0) {
          uVar8 = *(uint *)(param_1 + 0x3d8);
        }
        uVar10 = 0;
        if ((ulong)uVar8 != 0) {
          uVar10 = ((ulong)(uint)(*(int *)(param_1 + 0x21c) * *(int *)(param_1 + 0x218)) * 1000000)
                   / (ulong)uVar8;
        }
        uVar10 = uVar10 / 10 + 0x32;
      }
      iVar11 = 1;
      do {
        if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x610) >> 4 & 1) != 0) goto LAB_00108d54;
        __const_udelay(0xa7c6);
        uVar1 = (ulong)iVar11;
        iVar11 = iVar11 + 1;
      } while (uVar1 < uVar10);
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x604) = 2;
      if ((*(long *)(param_1 + 0x1f8) == 0) ||
         ((*(long *)(param_1 + 0x100) != 0 &&
          (*(int *)(param_1 + 0x134) == (int)*(short *)(*(long *)(param_1 + 0x100) + 0x4a))))) {
        uVar10 = 1000;
      }
      else {
        uVar8 = 0x1c200;
        if (*(uint *)(param_1 + 0x3d8) != 0) {
          uVar8 = *(uint *)(param_1 + 0x3d8);
        }
        uVar10 = 0;
        if ((ulong)uVar8 != 0) {
          uVar10 = ((ulong)(uint)(*(int *)(param_1 + 0x21c) * *(int *)(param_1 + 0x218)) * 1000000)
                   / (ulong)uVar8;
        }
        uVar10 = uVar10 / 10 + 0x32;
      }
      iVar11 = 1;
      do {
        if ((*(uint *)(*(long *)(param_1 + 0x10) + 0x610) >> 5 & 1) != 0) break;
        __const_udelay(0xa7c6);
        uVar1 = (ulong)iVar11;
        iVar11 = iVar11 + 1;
      } while (uVar1 < uVar10);
LAB_00108d54:
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x618) =
           *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x610);
      msm_geni_serial_enable_interrupts(param_1);
      geni_se_config_packing(lVar9,8,1,0,1,0);
      geni_se_config_packing(lVar9,8,4,0,0,1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x238) = 3;
  }
  if (*(char *)(param_1 + 0x8c1) == '\0') {
LAB_00108ac0:
    geni_se_init(lVar9,*(undefined4 *)(param_1 + 0x228),*(undefined4 *)(param_1 + 0x22c));
    geni_se_select_mode(lVar9,*(undefined4 *)(param_1 + 0x238));
    *(undefined1 *)(param_1 + 0x248) = 1;
    DataSynchronizationBarrier(3,3,0);
    lVar9 = *(long *)(param_1 + 0x3b8);
    if (lVar9 != 0) {
      uVar6 = 0;
      if ((uVar5 == 0) || (*(int *)(param_1 + 900) == 0)) goto LAB_00108b4c;
      lVar7 = sched_clock(0);
      ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_port_setup",
                     lVar7 - uVar5,(lVar7 - uVar5) / 1000);
    }
    uVar6 = 0;
  }
  else {
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x240);
    uVar8 = uVar2 & 0xffffff8f | 0x40;
    if (*(int *)(param_1 + 0x8bc) != 3) {
      uVar8 = uVar2 & 0xfffffcff | 0x200;
    }
    *(uint *)(*(long *)(param_1 + 0x10) + 0x240) = uVar8;
    if (*(char *)(param_1 + 0x8c0) == '\0') {
      local_7c = *(uint *)(*(long *)(param_1 + 0x10) + 0x20c);
      *(uint *)(*(long *)(param_1 + 0x10) + 0x20c) = local_7c & 0xffffbfff;
      local_7c = local_7c & 0xffff9fff;
      *(uint *)(*(long *)(param_1 + 0x10) + 0x20c) = local_7c;
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x20) = 1;
    }
    else {
      local_7c = 0;
    }
    uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x200) | 0x40000;
    *(uint *)(*(long *)(param_1 + 0x10) + 0x200) = uVar2;
    *(uint *)(*(long *)(param_1 + 0x10) + 0x25c) = *(uint *)(*(long *)(param_1 + 0x10) + 0x25c) | 2;
    if (*(char *)(param_1 + 0x8c0) == '\0') {
      uVar14 = *(uint *)(*(long *)(param_1 + 0x10) + 0x230) | 1;
      *(uint *)(*(long *)(param_1 + 0x10) + 0x230) = uVar14;
      uVar13 = *(uint *)(*(long *)(param_1 + 0x10) + 0x244) | 1;
      *(uint *)(*(long *)(param_1 + 0x10) + 0x244) = uVar13;
      uVar12 = *(uint *)(*(long *)(param_1 + 0x10) + 0x25c) | 8;
      *(uint *)(*(long *)(param_1 + 0x10) + 0x25c) = uVar12;
    }
    else {
      uVar14 = 0;
      uVar13 = 0;
      uVar12 = 0;
    }
    iVar11 = 1000;
    uVar4 = *(uint *)(*(long *)(param_1 + 0x10) + 0x84) | 1;
    *(uint *)(*(long *)(param_1 + 0x10) + 0x84) = uVar4;
    do {
      uVar3 = *(uint *)(*(long *)(param_1 + 0x10) + 0x88);
      if ((uVar3 >> 1 & 1) != 0) goto LAB_00108ac0;
      usleep_range_state(10,0x14,2);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: uart_io_macro_reg:0x%x\n",
                   "msm_geni_one_wire_uart_config",uVar8);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: uart_io_macro_reg:0x%x\n",
                 "msm_geni_one_wire_uart_config",uVar8);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_reg64:0x%x\n",uVar2);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_reg64:0x%x\n",uVar2);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_reg67:0x%x\n",local_7c);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_reg67:0x%x\n",local_7c);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_reg76:0x%x\n",uVar14);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_reg76:0x%x\n",uVar14);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_reg81:0x%x\n",uVar13);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_reg81:0x%x\n",uVar13);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_reg87:0x%x\n",uVar12);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_reg87:0x%x\n",uVar12);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_seq_start: 0x%x\n",uVar4);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_seq_start: 0x%x\n",uVar4);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"geni_cfg_status: 0x%x\n",uVar3);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"geni_cfg_status: 0x%x\n",uVar3);
    uVar6 = 0xfffffff5;
  }
LAB_00108b4c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_runtime_resume @ 00108db8 size=1672
// signature: undefined msm_geni_serial_runtime_resume(void)
// callers: [msm_geni_serial_power_on]
//------------------------------------------------------------

int msm_geni_serial_runtime_resume(long param_1)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x98);
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: Start %d\n","msm_geni_serial_runtime_resume",1)
  ;
  __ftrace_dbg(param_1,"%s: Start %d\n","msm_geni_serial_runtime_resume",1);
  lVar7 = *(long *)(lVar6 + 0x3b8);
  if (lVar7 == 0) {
    uVar3 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar6 + 0x840);
  }
  else if (*(int *)(lVar6 + 900) == 0) {
    uVar3 = 0;
    cVar1 = *(char *)(lVar6 + 0x840);
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar7,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_runtime_resume",uVar3
                   ,uVar3 / 1000);
    cVar1 = *(char *)(lVar6 + 0x840);
  }
  if (cVar1 != '\0') {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: SSR Down event set\n",
                   "msm_geni_serial_runtime_resume");
    __ftrace_dbg(param_1,"%s: SSR Down event set\n","msm_geni_serial_runtime_resume");
    return -0x16;
  }
  __pm_relax(*(undefined8 *)(lVar6 + 0x390));
  __pm_stay_awake(*(undefined8 *)(lVar6 + 0x390));
  if (((0 < *(int *)(lVar6 + 0x388)) && (*(char *)(lVar6 + 0x402) != '\0')) &&
     (*(long *)(*(long *)(lVar6 + 200) + 0xa8) != 0)) {
    iVar2 = irq_set_irq_wake(*(int *)(lVar6 + 0x388),0);
    if (iVar2 != 0) {
      _dev_err(param_1,"%s:Failed to unset IRQ wake:%d\n","msm_geni_serial_runtime_resume",iVar2);
    }
    disable_irq(*(undefined4 *)(lVar6 + 0x388));
    *(undefined1 *)(lVar6 + 0x402) = 0;
  }
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: Enabling Resources\n",
                 "msm_geni_serial_runtime_resume");
  __ftrace_dbg(param_1,"%s: Enabling Resources\n","msm_geni_serial_runtime_resume");
  iVar2 = msm_geni_serial_resources_on(lVar6);
  if (iVar2 != 0) {
    _dev_err(param_1,"%s: Error ret %d\n","msm_geni_serial_runtime_resume",iVar2);
    if (*(char *)(lVar6 + 0x3fc) == '\0') {
      *(undefined4 *)(lVar6 + 0x450) = 5;
      ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",5);
      __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(lVar6 + 0x450));
    }
    __pm_relax(*(undefined8 *)(lVar6 + 0x390));
    return iVar2;
  }
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                 "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(lVar6 + 0x458));
  __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
               "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(lVar6 + 0x458));
  *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x48) = *(undefined4 *)(lVar6 + 0x458);
  *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x4c) = *(undefined4 *)(lVar6 + 0x458);
  if (*(int *)(lVar6 + 0x808) == 2) {
    start_rx_sequencer(lVar6);
  }
  if (*(char *)(lVar6 + 0x620) != '\0') {
    msm_geni_serial_port_setup(lVar6);
  }
  DataSynchronizationBarrier(3,3,0);
  enable_irq(*(undefined4 *)(lVar6 + 0xa0));
  lVar7 = *(long *)(lVar6 + 0x3b8);
  if (((lVar7 != 0) && (uVar3 != 0)) && (*(int *)(lVar6 + 900) != 0)) {
    lVar4 = sched_clock();
    ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_runtime_resume",
                   lVar4 - uVar3,(lVar4 - uVar3) / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: End %d\n","msm_geni_serial_runtime_resume",0);
  __ftrace_dbg(param_1,"%s: End %d\n","msm_geni_serial_runtime_resume",0);
  if (*(char *)(lVar6 + 0x620) == '\0') {
    return 0;
  }
  lVar4 = *(long *)(lVar6 + 0x3b8);
  lVar7 = *(long *)(lVar6 + 0x618);
  if (lVar4 == 0) {
    uVar3 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar6 + 900) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n",
                   "msm_geni_serial_reconfigure_baud_rate",uVar3,uVar3 / 1000);
  }
  if (lVar7 == 0) goto LAB_001093b4;
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: start %d\n",
                 "msm_geni_serial_reconfigure_baud_rate",1);
  __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: start %d\n",
               "msm_geni_serial_reconfigure_baud_rate",1);
  if (((*(long *)(lVar6 + 0x100) == 0) ||
      (*(int *)(lVar6 + 0x134) != (int)*(short *)(*(long *)(lVar6 + 0x100) + 0x4a))) &&
     (iVar2 = msm_geni_serial_power_on(lVar6), iVar2 != 0)) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: Failed to vote clock on:%d\n",
                   "msm_geni_serial_reconfigure_baud_rate",iVar2);
    __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: Failed to vote clock on:%d\n",
                 "msm_geni_serial_reconfigure_baud_rate",iVar2);
    goto LAB_001093b4;
  }
  if (*(long *)(lVar6 + 0x500) != 0) {
    __flush_workqueue();
  }
  if (*(long *)(lVar6 + 0x508) != 0) {
    __flush_workqueue();
  }
  *(undefined4 *)(lVar6 + 0x510) = 0;
  msm_geni_serial_stop_rx(lVar6);
  if (((*(long *)(lVar6 + 0x100) == 0) ||
      (*(int *)(lVar6 + 0x134) != (int)*(short *)(*(long *)(lVar6 + 0x100) + 0x4a))) &&
     (lVar4 = wait_for_completion_timeout(lVar6 + 0x510,0x19), lVar4 == 0)) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s:Timeout for stop_rx\n",
                   "msm_geni_serial_reconfigure_baud_rate");
    __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s:Timeout for stop_rx\n",
                 "msm_geni_serial_reconfigure_baud_rate");
  }
  iVar2 = msm_geni_serial_config_baud_rate(lVar6,lVar7,*(undefined4 *)(lVar6 + 0x3d8));
  if (iVar2 == 0) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: baud %d\n",
                   "msm_geni_serial_reconfigure_baud_rate",*(undefined4 *)(lVar6 + 0x3d8));
    __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: baud %d\n",
                 "msm_geni_serial_reconfigure_baud_rate",*(undefined4 *)(lVar6 + 0x3d8));
  }
  if ((*(long *)(lVar6 + 0x100) == 0) ||
     (*(int *)(lVar6 + 0x134) != (int)*(short *)(*(long *)(lVar6 + 0x100) + 0x4a))) {
    lVar7 = *(long *)(lVar6 + 0x150);
    if ((*(int *)(lVar7 + 0x20c) != 2) || (*(int *)(lVar7 + 0x1f8) != 0)) goto LAB_00109270;
    _dev_err(lVar7,"%s.Device is suspended.\n","msm_geni_serial_start_rx");
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s.Device is suspended.\n",
                   "msm_geni_serial_start_rx");
    __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s.Device is suspended.\n",
                 "msm_geni_serial_start_rx");
    lVar7 = *(long *)(lVar6 + 0x100);
    if (lVar7 != 0) goto LAB_00109280;
LAB_00109290:
    lVar7 = *(long *)(lVar6 + 0x150);
    if (*(int *)(lVar7 + 0x1f8) == 0) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: Usage Count is already 0\n",
                     "msm_geni_serial_power_off");
      __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: Usage Count is already 0\n",
                   "msm_geni_serial_power_off");
    }
    else if ((*(ushort *)(lVar7 + 0x200) & 7) == 0) {
      uVar5 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar7 + 0x220) = uVar5;
      __pm_runtime_suspend(*(undefined8 *)(lVar6 + 0x150),0xd);
    }
  }
  else {
LAB_00109270:
    start_rx_sequencer(lVar6);
    lVar7 = *(long *)(lVar6 + 0x100);
    if (lVar7 == 0) goto LAB_00109290;
LAB_00109280:
    if (*(int *)(lVar6 + 0x134) != (int)*(short *)(lVar7 + 0x4a)) goto LAB_00109290;
  }
  lVar7 = *(long *)(lVar6 + 0x3b8);
  if (((lVar7 != 0) && (uVar3 != 0)) && (*(int *)(lVar6 + 900) != 0)) {
    lVar4 = sched_clock();
    ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_reconfigure_baud_rate",
                   lVar4 - uVar3,(lVar4 - uVar3) / 1000);
  }
LAB_001093b4:
  *(undefined1 *)(lVar6 + 0x620) = 0;
  return 0;
}



//------------------------------------------------------------
// start_rx_sequencer @ 00109440 size=2024
// signature: undefined start_rx_sequencer(void)
// callers: [xfer_mode_store, msm_geni_serial_runtime_resume, msm_geni_serial_set_termios]
//------------------------------------------------------------

void start_rx_sequencer(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  char *pcVar8;
  long lVar9;
  long lVar10;
  code *pcVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  
  if (*(int *)(param_1 + 0x808) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x840) != '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SSR Down event set\n","start_rx_sequencer")
    ;
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SSR Down event set\n","start_rx_sequencer");
    return;
  }
  uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: geni_status 0x%x\n","start_rx_sequencer",
                 uVar2);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: geni_status 0x%x\n","start_rx_sequencer",uVar2)
  ;
  iVar4 = *(int *)(param_1 + 0x238);
  if ((uVar2 >> 0xc & 1) != 0) {
    if (iVar4 == 3) {
      return;
    }
    if (iVar4 == 2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: mapping rx dma GENI: 0x%x\n",
                     "start_rx_sequencer",uVar2);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: mapping rx dma GENI: 0x%x\n",
                   "start_rx_sequencer",uVar2);
      lVar12 = *(long *)(param_1 + 0x10);
      if ((lVar12 != 0) && (*(long *)(param_1 + 0x358) != 0)) {
        *(undefined4 *)(lVar12 + 0xd4c) = 7;
        *(undefined4 *)(lVar12 + 0xd30) = *(undefined4 *)(param_1 + 0x358);
        *(undefined4 *)(lVar12 + 0xd34) = *(undefined4 *)(param_1 + 0x35c);
        *(undefined4 *)(lVar12 + 0xd38) = 0;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(lVar12 + 0xd3c) = 0x800;
      }
    }
    msm_geni_serial_stop_rx(param_1);
    iVar4 = *(int *)(param_1 + 0x238);
LAB_001097b8:
    if (iVar4 == 2) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s. mapping rx dma\n","start_rx_sequencer");
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s. mapping rx dma\n","start_rx_sequencer");
      lVar12 = *(long *)(param_1 + 0x10);
      if ((lVar12 != 0) && (*(long *)(param_1 + 0x358) != 0)) {
        *(undefined4 *)(lVar12 + 0xd4c) = 7;
        *(undefined4 *)(lVar12 + 0xd30) = *(undefined4 *)(param_1 + 0x358);
        *(undefined4 *)(lVar12 + 0xd34) = *(undefined4 *)(param_1 + 0x35c);
        *(undefined4 *)(lVar12 + 0xd38) = 0;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(lVar12 + 0xd3c) = 0x800;
      }
    }
    DataMemoryBarrier(0,2);
    *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x630) = 0x80000e0;
    msm_geni_serial_enable_interrupts(param_1);
    DataSynchronizationBarrier(3,3,0);
    uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: geni_status 0x%x, dma_dbg:0x%x\n",
                   "start_rx_sequencer",uVar3,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: geni_status 0x%x, dma_dbg:0x%x\n",
                 "start_rx_sequencer",uVar3,*(undefined4 *)(*(long *)(param_1 + 0x10) + 0xe40));
    return;
  }
  if (iVar4 != 3) goto LAB_001097b8;
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: start xfer_rx\n","start_rx_sequencer");
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: start xfer_rx\n","start_rx_sequencer");
  if (*(char *)(param_1 + 0x248) == '\0') {
    uVar7 = *(undefined8 *)(param_1 + 0x150);
    pcVar8 = "%s: Port setup not yet done\n";
LAB_00109ae4:
    _dev_err(uVar7,pcVar8,"msm_geni_uart_gsi_xfer_rx");
  }
  else {
    lVar13 = *(long *)(param_1 + 0x468);
    lVar12 = *(long *)(param_1 + 0x260);
    iVar4 = msm_geni_allocate_chan(param_1);
    if (iVar4 != 0) {
      uVar7 = *(undefined8 *)(param_1 + 0x150);
      pcVar8 = "%s: Allocation of Channel failed\n";
      goto LAB_00109ae4;
    }
    sg_init_table(*(long *)(param_1 + 0x468) + 400,6);
    lVar9 = *(long *)(param_1 + 0x468);
    *(undefined4 *)(lVar9 + 0x19c) = 0x10;
    *(uint *)(lVar9 + 0x198) = (uint)(lVar9 + 0x20) & 0xfff;
    lVar14 = 0;
    uVar15 = 0;
    lVar16 = 0x1d0;
    lVar17 = 0x60;
    *(ulong *)(lVar9 + 400) =
         (*(ulong *)(lVar9 + 400) & 3 | (((lVar9 + 0x20) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6)
         - 0x200000000;
    *(undefined8 *)(lVar13 + 0x40) = 1;
    *(undefined8 *)(lVar13 + 0x48) = 0x20000100000000;
    lVar9 = *(long *)(param_1 + 0x468);
    *(uint *)(lVar9 + 0x1b8) = (uint)(lVar13 + 0x40) & 0xfff;
    *(undefined4 *)(lVar9 + 0x1bc) = 0x10;
    *(ulong *)(lVar9 + 0x1b0) =
         (*(ulong *)(lVar9 + 0x1b0) & 3 |
         (((lVar13 + 0x40) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000;
    do {
      lVar13 = param_1 + lVar14;
      if ((lVar12 == 0) || (puVar1 = (undefined8 *)(lVar13 + 0x360), puVar1 == (undefined8 *)0x0)) {
        *(undefined8 *)(lVar13 + 0x330) = 0xffffffffffffffea;
LAB_001098d0:
        if (lVar14 != 0) {
          lVar13 = param_1 + lVar14;
          if (((lVar12 != 0) && ((undefined8 *)(lVar13 + 0x358) != (undefined8 *)0x0)) &&
             (*(long *)(lVar13 + 0x328) != 0)) {
            dma_free_attrs(lVar12,0x800,*(long *)(lVar13 + 0x328),*(undefined8 *)(lVar13 + 0x358),0)
            ;
          }
          *(undefined8 *)(lVar13 + 0x328) = 0;
          if (1 < uVar15) {
            lVar13 = param_1 + lVar14;
            if (((lVar12 != 0) && ((undefined8 *)(lVar13 + 0x350) != (undefined8 *)0x0)) &&
               (*(long *)(lVar13 + 800) != 0)) {
              dma_free_attrs(lVar12,0x800,*(long *)(lVar13 + 800),*(undefined8 *)(lVar13 + 0x350),0)
              ;
            }
            *(undefined8 *)(lVar13 + 800) = 0;
            if (1 < uVar15 - 1) {
              lVar14 = param_1 + lVar14;
              if (((lVar12 != 0) && ((undefined8 *)(lVar14 + 0x348) != (undefined8 *)0x0)) &&
                 (*(long *)(lVar14 + 0x318) != 0)) {
                dma_free_attrs(lVar12,0x800,*(long *)(lVar14 + 0x318),
                               *(undefined8 *)(lVar14 + 0x348),0);
              }
              *(undefined8 *)(lVar14 + 0x318) = 0;
            }
          }
        }
        dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
        dma_release_channel(**(undefined8 **)(param_1 + 0x468));
        *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
        **(undefined8 **)(param_1 + 0x468) = 0;
        goto LAB_001099a0;
      }
      *puVar1 = 0xffffffffffffffff;
      uVar5 = dma_alloc_attrs(lVar12,0x800,puVar1,0xcc0,0);
      *(ulong *)(param_1 + lVar14 + 0x330) = uVar5;
      if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) goto LAB_001098d0;
      uVar15 = uVar15 + 1;
      *(int *)(*(long *)(param_1 + 0x468) + lVar17) = (int)*puVar1;
      *(undefined4 *)(*(long *)(param_1 + 0x468) + lVar17 + 4) = *(undefined4 *)(lVar13 + 0x364);
      *(undefined4 *)(*(long *)(param_1 + 0x468) + lVar17 + 8) = 0x800;
      *(undefined4 *)(*(long *)(param_1 + 0x468) + lVar17 + 0xc) = 0x100301;
      lVar10 = *(long *)(param_1 + 0x468);
      lVar13 = lVar17 + lVar10;
      lVar17 = lVar17 + 0x10;
      lVar9 = lVar10 + lVar14 * 4;
      lVar14 = lVar14 + 8;
      *(ulong *)(lVar10 + lVar16) =
           (*(ulong *)(lVar10 + lVar16) & 3 | ((lVar13 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
           0x200000000;
      lVar16 = lVar16 + 0x20;
      *(uint *)(lVar9 + 0x1d8) = (uint)lVar13 & 0xfff;
      *(undefined4 *)(lVar9 + 0x1dc) = 0x10;
    } while (lVar14 != 0x20);
    lVar13 = *(long *)(param_1 + 0x468);
    plVar6 = *(long **)(lVar13 + 8);
    uVar7 = 0;
    if (plVar6 != (long *)0x0) {
      if ((*plVar6 == 0) || (pcVar11 = *(code **)(*plVar6 + 0x108), pcVar11 == (code *)0x0)) {
        uVar7 = 0;
      }
      else {
        if (*(int *)(pcVar11 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8229,0x109714);
          (*pcVar11)();
        }
        uVar7 = (*pcVar11)(plVar6,lVar13 + 400,6,2,3,0);
        lVar13 = *(long *)(param_1 + 0x468);
      }
    }
    *(undefined8 *)(lVar13 + 600) = uVar7;
    lVar13 = *(long *)(*(long *)(param_1 + 0x468) + 600);
    if (lVar13 == 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x150),"%s: Rx desc is failed\n",
               "msm_geni_uart_gsi_xfer_rx");
      if (((undefined8 *)(param_1 + 0x360) != (undefined8 *)0x0) &&
         (*(long *)(param_1 + 0x330) != 0)) {
        dma_free_attrs(lVar12,0x800,*(long *)(param_1 + 0x330),*(undefined8 *)(param_1 + 0x360),0);
      }
      *(undefined8 *)(param_1 + 0x330) = 0;
      if (((undefined8 *)(param_1 + 0x368) != (undefined8 *)0x0) &&
         (*(long *)(param_1 + 0x338) != 0)) {
        dma_free_attrs(lVar12,0x800,*(long *)(param_1 + 0x338),*(undefined8 *)(param_1 + 0x368),0);
      }
      *(undefined8 *)(param_1 + 0x338) = 0;
      if (((undefined8 *)(param_1 + 0x370) != (undefined8 *)0x0) &&
         (*(long *)(param_1 + 0x340) != 0)) {
        dma_free_attrs(lVar12,0x800,*(long *)(param_1 + 0x340),*(undefined8 *)(param_1 + 0x370),0);
      }
      *(undefined8 *)(param_1 + 0x340) = 0;
      if (((undefined8 *)(param_1 + 0x378) != (undefined8 *)0x0) &&
         (*(long *)(param_1 + 0x348) != 0)) {
        dma_free_attrs(lVar12,0x800,*(long *)(param_1 + 0x348),*(undefined8 *)(param_1 + 0x378),0);
      }
      *(undefined8 *)(param_1 + 0x348) = 0;
      dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
      dma_release_channel(**(undefined8 **)(param_1 + 0x468));
      *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
      **(undefined8 **)(param_1 + 0x468) = 0;
      *(undefined1 *)(param_1 + 0x559) = 0;
    }
    else {
      *(code **)(lVar13 + 0x28) = msm_geni_uart_gsi_rx_cb;
      *(long *)(*(long *)(*(long *)(param_1 + 0x468) + 600) + 0x38) =
           *(long *)(param_1 + 0x468) + 0x290;
      pcVar11 = *(code **)(*(long *)(*(long *)(param_1 + 0x468) + 600) + 0x18);
      if (*(int *)(pcVar11 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x109a28);
        (*pcVar11)();
      }
      iVar4 = (*pcVar11)();
      if (-1 < iVar4) {
        pcVar11 = *(code **)(**(long **)(*(long *)(param_1 + 0x468) + 8) + 0x160);
        if (*(int *)(pcVar11 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x109a58);
          (*pcVar11)();
        }
        (*pcVar11)();
        *(undefined1 *)(param_1 + 0x559) = 1;
        goto LAB_00109a64;
      }
      _printk(&DAT_0011163d,"msm_geni_uart_gsi_xfer_rx",iVar4);
      pcVar11 = *(code **)(**(long **)(*(long *)(param_1 + 0x468) + 8) + 0x148);
      if (pcVar11 != (code *)0x0) {
        if (*(int *)(pcVar11 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x109c20);
          (*pcVar11)();
        }
        (*pcVar11)();
      }
    }
  }
LAB_001099a0:
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: RX xfer is failed\n","start_rx_sequencer");
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: RX xfer is failed\n","start_rx_sequencer");
LAB_00109a64:
  uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: xfer_rx done. geni_status:0x%x\n",
                 "start_rx_sequencer",uVar3);
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: xfer_rx done. geni_status:0x%x\n",
               "start_rx_sequencer",uVar3);
  return;
}



//------------------------------------------------------------
// msm_geni_allocate_chan @ 00109c28 size=672
// signature: undefined msm_geni_allocate_chan(void)
// callers: [start_rx_sequencer, msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

int msm_geni_allocate_chan(long param_1)

{
  ulong uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  code *pcVar6;
  
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Start\n","msm_geni_allocate_chan");
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Start\n","msm_geni_allocate_chan");
  if ((*(long **)(param_1 + 0x468))[1] == 0) {
    uVar4 = dma_request_chan(*(undefined8 *)(param_1 + 0x150),&DAT_00110048);
    uVar1 = 0;
    if (uVar4 < 0xfffffffffffff001) {
      uVar1 = uVar4;
    }
    *(ulong *)(*(long *)(param_1 + 0x468) + 8) = uVar1;
    if (*(long *)(*(long *)(param_1 + 0x468) + 8) == 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x150),"%s:Failed to allocate RX slv ch\n",
               "msm_geni_allocate_chan");
      iVar2 = -5;
      goto LAB_00109dc0;
    }
    *(code **)(*(long *)(param_1 + 0x468) + 0xe0) = msm_geni_uart_ev_cb;
    *(long *)(*(long *)(param_1 + 0x468) + 0xe8) = param_1;
    *(undefined4 *)(*(long *)(param_1 + 0x468) + 0xd8) = 1;
    *(long *)(*(long *)(*(long *)(param_1 + 0x468) + 8) + 0x68) = *(long *)(param_1 + 0x468) + 0xd8;
    plVar3 = *(long **)(*(long *)(param_1 + 0x468) + 8);
    pcVar6 = *(code **)(*plVar3 + 0x130);
    if (pcVar6 == (code *)0x0) {
      iVar2 = -0x26;
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x109d18);
        (*pcVar6)();
      }
      iVar2 = (*pcVar6)(plVar3,0);
      if (iVar2 == 0) {
        lVar5 = **(long **)(param_1 + 0x468);
        goto joined_r0x00109d28;
      }
    }
    _dev_err(*(undefined8 *)(param_1 + 0x150),"Failed to Config Rx\n");
    dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
  }
  else {
    lVar5 = **(long **)(param_1 + 0x468);
joined_r0x00109d28:
    if (lVar5 == 0) {
      uVar4 = dma_request_chan(*(undefined8 *)(param_1 + 0x150),&DAT_001114f1);
      uVar1 = 0;
      if (uVar4 < 0xfffffffffffff001) {
        uVar1 = uVar4;
      }
      **(ulong **)(param_1 + 0x468) = uVar1;
      if (**(long **)(param_1 + 0x468) == 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x150),"%s:Failed to allocate TX slv ch\n",
                 "msm_geni_allocate_chan");
        dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
        iVar2 = -5;
        *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
      }
      else {
        (*(long **)(param_1 + 0x468))[0x19] = (long)msm_geni_uart_ev_cb;
        *(long *)(*(long *)(param_1 + 0x468) + 0xd0) = param_1;
        *(undefined4 *)(*(long *)(param_1 + 0x468) + 0xc0) = 1;
        *(long **)(**(long **)(param_1 + 0x468) + 0x68) = *(long **)(param_1 + 0x468) + 0x18;
        pcVar6 = *(code **)(*(long *)**(undefined8 **)(param_1 + 0x468) + 0x130);
        if (pcVar6 == (code *)0x0) {
          iVar2 = -0x26;
        }
        else {
          if (*(int *)(pcVar6 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x109db4);
            (*pcVar6)();
          }
          iVar2 = (*pcVar6)((long *)**(undefined8 **)(param_1 + 0x468),0);
          if (iVar2 == 0) goto LAB_00109dc0;
        }
        _dev_err(*(undefined8 *)(param_1 + 0x150),"Failed to Config Tx\n");
        dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
        dma_release_channel(**(undefined8 **)(param_1 + 0x468));
        *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
        **(undefined8 **)(param_1 + 0x468) = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
LAB_00109dc0:
  ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: End\n","msm_geni_allocate_chan");
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: End\n","msm_geni_allocate_chan");
  return iVar2;
}



//------------------------------------------------------------
// msm_geni_deallocate_chan @ 00109ec8 size=76
// signature: undefined msm_geni_deallocate_chan(void)
// callers: [msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

void msm_geni_deallocate_chan(long param_1)

{
  dma_release_channel(*(undefined8 *)(*(long *)(param_1 + 0x468) + 8));
  dma_release_channel(**(undefined8 **)(param_1 + 0x468));
  *(undefined8 *)(*(long *)(param_1 + 0x468) + 8) = 0;
  **(undefined8 **)(param_1 + 0x468) = 0;
  return;
}



//------------------------------------------------------------
// msm_geni_uart_gsi_rx_cb @ 00109f18 size=1056
// signature: undefined msm_geni_uart_gsi_rx_cb(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_gsi_rx_cb(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  ulong local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
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
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 8);
  iVar3 = *param_1;
  uVar8 = *(undefined8 *)(lVar9 + 200);
  ipc_log_string(*(undefined8 *)(lVar9 + 0x3a0),"%s: Start\n","msm_geni_uart_gsi_rx_cb");
  __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s: Start\n","msm_geni_uart_gsi_rx_cb");
  if (*(uint *)(lVar9 + 0x550) < 5) {
    iVar2 = tty_insert_flip_string_fixed_flag
                      (uVar8,*(undefined8 *)(lVar9 + (ulong)*(uint *)(lVar9 + 0x550) * 8 + 0x330),0,
                       iVar3);
    if (iVar2 != iVar3) {
      ipc_log_string(*(undefined8 *)(lVar9 + 0x3a0),"%s: ret %d rx_bytes %d\n",
                     "msm_geni_uart_gsi_rx_cb",iVar2,iVar3);
      __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s: ret %d rx_bytes %d\n",
                   "msm_geni_uart_gsi_rx_cb",iVar2,iVar3);
    }
    *(int *)(lVar9 + 0xe0) = *(int *)(lVar9 + 0xe0) + iVar2;
    tty_flip_buffer_push(uVar8);
    if (*(uint *)(lVar9 + 0x550) < 5) {
      iVar2 = iVar3;
      if (0x1f < iVar3) {
        iVar2 = 0x20;
      }
      uVar8 = *(undefined8 *)(lVar9 + 0x3a0);
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
      local_b8 = 0;
      uStack_b0 = 0;
      local_c8 = 0;
      uStack_c0 = 0;
      local_d8 = 0;
      uStack_d0 = 0;
      local_e8 = 0;
      local_e0 = 0;
      hex_dump_to_buffer(*(undefined8 *)(lVar9 + (ulong)*(uint *)(lVar9 + 0x550) * 8 + 0x330),
                         (long)iVar2,0x20,1,&local_88,0x40,0);
      scnprintf(&local_e8,0x60,"%s[0x%.10x:%d] : %s","GSI Rx",0,iVar3,&local_88);
      ipc_log_string(uVar8,"%s : %s\n","dump_ipc",&local_e8);
      __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s : %s\n","dump_ipc",&local_e8);
      uVar1 = *(uint *)(lVar9 + 0x550);
      local_d8 = 0;
      uStack_d0 = 0;
      local_e8 = 0;
      local_e0 = 0;
      ipc_log_string(*(undefined8 *)(lVar9 + 0x3b0),"%s: Start\n","msm_geni_uart_rx_queue_dma_tre");
      __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s: Start\n","msm_geni_uart_rx_queue_dma_tre");
      sg_init_table(&local_e8,1);
      if (uVar1 < 6) {
        lVar5 = *(long *)(lVar9 + 0x468);
        lVar6 = lVar5 + (ulong)uVar1 * 0x10 + 0x60;
        local_e0 = CONCAT44(0x10,(uint)lVar6 & 0xfff);
        plVar4 = *(long **)(lVar5 + 8);
        local_e8 = (local_e8 & 3 | ((lVar6 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000
        ;
        uVar8 = 0;
        if (plVar4 != (long *)0x0) {
          if ((*plVar4 == 0) || (pcVar7 = *(code **)(*plVar4 + 0x108), pcVar7 == (code *)0x0)) {
            uVar8 = 0;
          }
          else {
            if (*(int *)(pcVar7 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x10a19c);
              (*pcVar7)();
            }
            uVar8 = (*pcVar7)(plVar4,&local_e8,1,2,3,0);
            lVar5 = *(long *)(lVar9 + 0x468);
          }
        }
        *(undefined8 *)(lVar5 + 600) = uVar8;
        lVar6 = *(long *)(*(long *)(lVar9 + 0x468) + 600);
        if (lVar6 == 0) {
          _dev_err(*(undefined8 *)(lVar9 + 0x150),"%s:Prep_slave_sg failed\n",
                   "msm_geni_uart_rx_queue_dma_tre");
        }
        else {
          *(code **)(lVar6 + 0x28) = msm_geni_uart_gsi_rx_cb;
          *(long *)(*(long *)(*(long *)(lVar9 + 0x468) + 600) + 0x38) =
               *(long *)(lVar9 + 0x468) + 0x290;
          pcVar7 = *(code **)(*(long *)(*(long *)(lVar9 + 0x468) + 600) + 0x18);
          if (*(int *)(pcVar7 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10a1fc);
            (*pcVar7)();
          }
          iVar3 = (*pcVar7)();
          if (iVar3 < 0) {
            _printk(&DAT_0011163d,"msm_geni_uart_rx_queue_dma_tre",iVar3);
            pcVar7 = *(code **)(**(long **)(*(long *)(lVar9 + 0x468) + 8) + 0x148);
            if (pcVar7 != (code *)0x0) {
              if (*(int *)(pcVar7 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10a328);
                (*pcVar7)();
              }
              (*pcVar7)();
            }
          }
          else {
            pcVar7 = *(code **)(**(long **)(*(long *)(lVar9 + 0x468) + 8) + 0x160);
            if (*(int *)(pcVar7 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10a22c);
              (*pcVar7)();
            }
            (*pcVar7)();
            ipc_log_string(*(undefined8 *)(lVar9 + 0x3b0),"%s: End\n",
                           "msm_geni_uart_rx_queue_dma_tre");
            __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s: End\n","msm_geni_uart_rx_queue_dma_tre"
                        );
          }
        }
        *(uint *)(lVar9 + 0x550) = *(int *)(lVar9 + 0x550) + 1U & 3;
        ipc_log_string(*(undefined8 *)(lVar9 + 0x3a0),"%s: End\n","msm_geni_uart_gsi_rx_cb");
        __ftrace_dbg(*(undefined8 *)(lVar9 + 0x150),"%s: End\n","msm_geni_uart_gsi_rx_cb");
        lVar9 = sp_el0;
        if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10a334);
  (*pcVar7)();
}



//------------------------------------------------------------
// msm_geni_uart_ev_cb @ 0010a33c size=228
// signature: undefined msm_geni_uart_ev_cb(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_ev_cb(undefined8 param_1,int *param_2,long param_3)

{
  code *pcVar1;
  ulong uVar2;
  
  uVar2 = *(ulong *)(param_2 + 2);
  ipc_log_string(*(undefined8 *)(param_3 + 0x3b0),"%s: Start\n","msm_geni_uart_ev_cb");
  __ftrace_dbg(*(undefined8 *)(param_3 + 0x150),"%s: Start\n","msm_geni_uart_ev_cb");
  if (*param_2 == 0) {
    if (((uint)uVar2 >> 2 & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a3d8);
      (*pcVar1)();
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_3 + 0x3b0),"GSI QN err:0x%x, status:0x%x, err:%d\n",
                   param_2[10],uVar2 & 0xffffffff);
    __ftrace_dbg(*(undefined8 *)(param_3 + 0x150),"GSI QN err:0x%x, status:0x%x, err:%d\n",
                 param_2[10],uVar2 & 0xffffffff,*param_2);
  }
  ipc_log_string(*(undefined8 *)(param_3 + 0x3b0),"%s: End\n","msm_geni_uart_ev_cb");
  __ftrace_dbg(*(undefined8 *)(param_3 + 0x150),"%s: End\n","msm_geni_uart_ev_cb");
  return;
}



//------------------------------------------------------------
// msm_geni_serial_config_baud_rate @ 0010a420 size=1604
// signature: undefined msm_geni_serial_config_baud_rate(void)
// callers: [msm_geni_serial_runtime_resume, msm_geni_serial_set_termios]
//------------------------------------------------------------

void msm_geni_serial_config_baud_rate(long param_1,long param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_74;
  ulong local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = param_1 + 0x2b8;
  lVar13 = *(long *)(param_1 + 0x3b8);
  local_70 = 0;
  local_74 = 0;
  if (lVar13 == 0) {
    uVar9 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 900) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = sched_clock();
    ipc_log_string(lVar13,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_config_baud_rate",
                   uVar9,uVar9 / 1000);
  }
  if ((*(int *)(param_1 + 0x3e4) < 3) &&
     ((*(int *)(param_1 + 0x3e4) != 2 || (*(int *)(param_1 + 1000) < 5)))) {
    iVar7 = 0x20;
  }
  else {
    iVar7 = 0x10;
  }
  uVar15 = iVar7 * param_3;
  uVar14 = (ulong)uVar15;
  iVar7 = geni_se_clk_freq_match(lVar11,uVar14,&local_74,&local_70,0);
  if (iVar7 == 0) {
    uVar6 = 0;
    if (uVar14 != 0) {
      uVar6 = ((uVar14 + local_70) - 1) / uVar14;
    }
    iVar7 = (int)uVar6;
    if (0 < iVar7) {
      uVar17 = 0;
      if ((uVar6 & 0xffffffff) != 0) {
        uVar17 = (uint)(local_70 / (uVar6 & 0xffffffff));
      }
      if (uVar15 != uVar17) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                       "%s src_clk freq_diff:%d baud:%d clk_rate:%lu clk_div:%d\n",
                       "msm_geni_serial_config_baud_rate",uVar15 - uVar17,param_3,local_70,
                       uVar6 & 0xffffffff);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                     "%s src_clk freq_diff:%d baud:%d clk_rate:%lu clk_div:%d\n",
                     "msm_geni_serial_config_baud_rate",uVar15 - uVar17,param_3,local_70,
                     uVar6 & 0xffffffff);
      }
      *(int *)(param_1 + 0xb0) = (int)local_70;
      iVar8 = clk_set_rate(*(undefined8 *)(param_1 + 0x278),local_70);
      if (iVar8 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x150),"Error setting clock rate\n");
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: SE clock set_rate error:%d\n",
                       "msm_geni_serial_config_baud_rate",iVar8);
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: SE clock set_rate error:%d\n",
                     "msm_geni_serial_config_baud_rate",iVar8);
      }
      lVar13 = (long)(int)(iVar7 << 4 | 1);
      if (param_3 != 0) {
        uart_update_timeout(param_1,*(undefined4 *)(param_2 + 8),param_3);
      }
      *(long *)(param_1 + 0x458) = lVar13;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                     "msm_geni_enable_disable_se_clk",1,lVar13);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                   "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(param_1 + 0x458));
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48) = *(undefined4 *)(param_1 + 0x458);
      *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x4c) = *(undefined4 *)(param_1 + 0x458);
      uVar12 = *(uint *)(*(long *)(param_1 + 0x10) + 0x25c);
      uVar17 = *(uint *)(*(long *)(param_1 + 0x10) + 0x2a4);
      uVar15 = *(uint *)(*(long *)(param_1 + 0x10) + 0x280);
      uVar16 = *(uint *)(*(long *)(param_1 + 0x10) + 0x2a8);
      uVar1 = *(uint *)(param_2 + 8);
      if ((uVar1 >> 8 & 1) == 0) {
        uVar12 = uVar12 & 0xfffffffe;
        uVar15 = uVar15 & 0xffffffef;
        uVar17 = uVar17 & 0xfffffffe;
        uVar16 = uVar16 & 0xfffffffe;
      }
      else {
        uVar12 = uVar12 | 1;
        uVar15 = uVar15 | 0x10;
        uVar17 = uVar17 & 0xfffffff8;
        uVar16 = uVar16 & 0xfffffff8;
        if ((uVar1 >> 9 & 1) == 0) {
          if ((uVar1 >> 0x1e & 1) == 0) {
            uVar16 = uVar16 | 1;
            uVar17 = uVar17 | 1;
          }
          else {
            uVar17 = uVar17 | 5;
            uVar16 = uVar16 | 5;
          }
        }
        else {
          uVar17 = uVar17 | 3;
          uVar16 = uVar16 | 3;
        }
      }
      uVar2 = *(uint *)(param_1 + 0x110);
      uVar5 = uVar1 >> 4 & 3;
      iVar8 = uVar5 + 5;
      *(uint *)(param_1 + 0x110) = uVar2 & 0xfffffff7;
      uVar3 = *(uint *)(param_2 + 8);
      uVar1 = uVar3 >> 5 & 2;
      if ((int)uVar3 < 0) {
        uVar12 = uVar12 & 0xfffffffd;
        *(uint *)(param_1 + 0x110) = uVar2 | 8;
      }
      else {
        uVar12 = uVar12 | 2;
      }
      msm_geni_serial_set_manual_flow(uVar3 >> 0x1f,param_1);
      if (*(char *)(param_1 + 0x460) == '\0') {
        *(uint *)(*(long *)(param_1 + 0x10) + 0x22c) = *(uint *)(param_1 + 0x380);
        *(uint *)(*(long *)(param_1 + 0x10) + 0x25c) = uVar12;
        *(uint *)(*(long *)(param_1 + 0x10) + 0x2a4) = uVar17;
        *(uint *)(*(long *)(param_1 + 0x10) + 0x280) = uVar15;
        *(uint *)(*(long *)(param_1 + 0x10) + 0x2a8) = uVar16;
        *(int *)(*(long *)(param_1 + 0x10) + 0x268) = iVar8;
        *(int *)(*(long *)(param_1 + 0x10) + 0x28c) = iVar8;
        *(uint *)(*(long *)(param_1 + 0x10) + 0x26c) = uVar1;
        geni_se_config_packing(lVar11,iVar8,4,0,1,0);
        geni_se_config_packing(lVar11,iVar8,4,0,0,1);
        iVar7 = *(int *)(param_2 + 8);
      }
      else {
        uVar2 = (*(uint *)(param_1 + 0x380) & 1) << 8 | uVar1 << 3 | uVar5 | 0x1000480;
        iVar4 = *(int *)(param_1 + 0x220);
        lVar11 = *(long *)(param_1 + 0x468);
        *(uint *)(lVar11 + 0x10) = uVar2;
        *(undefined4 *)(lVar11 + 0x14) = 0;
        *(int *)(lVar11 + 0x18) = iVar7;
        *(undefined4 *)(lVar11 + 0x1c) = 0x220001;
        *(uint *)(lVar11 + 0x20) = uVar2;
        *(int *)(lVar11 + 0x24) = iVar4 * 0x1000000 + -0x1ffff60;
        *(int *)(lVar11 + 0x28) = iVar7;
        *(undefined4 *)(lVar11 + 0x2c) = 0x220001;
        *(long *)(*(long *)(param_1 + 0x468) + 0x280) = param_1;
        *(long *)(*(long *)(param_1 + 0x468) + 0x2b0) = param_1;
        iVar7 = *(int *)(param_2 + 8);
      }
      if (iVar7 < 0) {
        *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x2ac) = 0;
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: Manual flow Disabled, HW Flow ON\n",
                       "msm_geni_serial_termios_cfg");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: Manual flow Disabled, HW Flow ON\n",
                     "msm_geni_serial_termios_cfg");
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"Tx: trans_cfg%d parity %d\n",uVar12,uVar17);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"Tx: trans_cfg%d parity %d\n",uVar12,uVar17);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"Rx: trans_cfg%d parity %d\n",uVar15,uVar16);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"Rx: trans_cfg%d parity %d\n",uVar15,uVar16);
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"BitsChar%d stop bit%d\n",iVar8,uVar1);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"BitsChar%d stop bit%d\n",iVar8,uVar1);
      if ((uVar12 >> 1 & 1) != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),
                       "Check : MSM CTS line signal is being ignored during Tx\n");
        __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),
                     "Check : MSM CTS line signal is being ignored during Tx\n");
      }
      lVar11 = *(long *)(param_1 + 0x3b8);
      if (lVar11 != 0) {
        uVar10 = 0;
        if ((uVar9 == 0) || (*(int *)(param_1 + 900) == 0)) goto LAB_0010a990;
        lVar13 = sched_clock(0);
        ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_config_baud_rate",
                       lVar13 - uVar9,(lVar13 - uVar9) / 1000);
      }
      uVar10 = 0;
      goto LAB_0010a990;
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x150),"%s: Failed(%d) to find src clk for 0x%x\n",
             "msm_geni_serial_config_baud_rate",iVar7,param_3);
    if (*(char *)(param_1 + 0x3fc) == '\0') {
      *(undefined4 *)(param_1 + 0x450) = 3;
      ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s uart_error_code %d",
                     "msm_geni_update_uart_error_code",3);
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s uart_error_code %d",
                   "msm_geni_update_uart_error_code",*(undefined4 *)(param_1 + 0x450));
      uVar10 = 0xffffffea;
      goto LAB_0010a990;
    }
  }
  uVar10 = 0xffffffea;
LAB_0010a990:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_cons_set_mctrl @ 0010aa68 size=4
// signature: undefined msm_geni_cons_set_mctrl(void)
// callers: []
//------------------------------------------------------------

void msm_geni_cons_set_mctrl(void)

{
  return;
}



//------------------------------------------------------------
// msm_geni_cons_get_mctrl @ 0010aa70 size=8
// signature: undefined msm_geni_cons_get_mctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_geni_cons_get_mctrl(void)

{
  return 0x160;
}



//------------------------------------------------------------
// msm_geni_serial_cons_pm @ 0010aa7c size=308
// signature: undefined msm_geni_serial_cons_pm(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_cons_pm(long param_1,int param_2,int param_3)

{
  if ((param_2 == 0) && (param_3 == 3)) {
    msm_geni_serial_resources_on(param_1);
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                   "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(param_1 + 0x458));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                 "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(param_1 + 0x458));
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48) = *(undefined4 *)(param_1 + 0x458);
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x4c) = *(undefined4 *)(param_1 + 0x458);
    *(undefined4 *)(param_1 + 0x44c) = 0;
  }
  else if ((param_2 == 3) && (param_3 == 0)) {
    *(undefined4 *)(param_1 + 0x44c) = 1;
    ipc_log_string(*(undefined8 *)(param_1 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                   "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(param_1 + 0x458));
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                 "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(param_1 + 0x458));
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48) = 1;
    *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x4c) = 1;
    msm_geni_serial_resources_off(*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x48),param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_serial_probe @ 0010abb4 size=4364
// signature: undefined msm_geni_serial_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_geni_serial_probe(long param_1)

{
  long *plVar1;
  undefined1 *puVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  long *plVar12;
  undefined8 uVar13;
  long lVar14;
  undefined8 uVar15;
  undefined1 *puVar16;
  long lVar17;
  char *pcVar18;
  ulong uVar19;
  undefined8 uVar20;
  ulong local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  long local_68;
  
  lVar10 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = of_match_device(&msm_geni_device_tbl,plVar1);
  bVar5 = uart_line_id;
  if (lVar10 == 0) {
    _dev_err(plVar1,"%s: No matching device found\n","msm_geni_serial_probe");
    uVar19 = 0xffffffed;
    goto LAB_0010ada0;
  }
  lVar17 = *(long *)(lVar10 + 0xc0);
  lVar10 = *(long *)(param_1 + 0x2f8);
  if (lVar10 == 0) {
    uVar6 = *(uint *)(param_1 + 8);
  }
  else if (*(long *)(lVar17 + 0x28) == 0) {
    if (0x3e < uart_line_id) {
      _dev_err(plVar1,"All UART ports already initialized\n");
      uVar19 = 0xffffffed;
      goto LAB_0010ada0;
    }
    uVar6 = of_alias_get_id(lVar10,"hsuart");
    if ((int)uVar6 < 0) {
      if ((uart_line_id >> 5 & 1) == 0) {
        uVar6 = 5;
      }
      else if ((uart_line_id >> 4 & 1) == 0) {
        uVar6 = 4;
      }
      else if ((uart_line_id >> 3 & 1) == 0) {
        uVar6 = 3;
      }
      else if ((uart_line_id >> 2 & 1) == 0) {
        uVar6 = 2;
      }
      else if ((uart_line_id >> 1 & 1) == 0) {
        uVar6 = 1;
      }
      else {
        uVar6 = -(uart_line_id & 1) & uVar6;
      }
    }
    uVar9 = 1 << (ulong)(uVar6 & 0x1f);
    if ((uVar9 & uart_line_id) != 0) {
      _dev_err(plVar1,"Already used line %d\n",uVar6);
      uVar19 = 0xffffffed;
      goto LAB_0010ada0;
    }
    if (uVar6 < 6) {
      uart_line_id = uart_line_id | (byte)uVar9;
    }
  }
  else {
    uVar6 = of_alias_get_id(lVar10,"serial");
    if ((int)uVar6 < 1) {
      uVar6 = 0;
    }
  }
  lVar10 = *(long *)(lVar17 + 0x28);
  if (lVar10 == 0) {
    if (uVar6 < 6) {
      puVar16 = &msm_geni_serial_ports + (ulong)uVar6 * 0x8c8;
      if (puVar16 != (undefined1 *)0x0) goto LAB_0010ad38;
    }
    else {
      puVar16 = (undefined1 *)0xfffffffffffffffa;
    }
LAB_0010aed4:
    _dev_err(plVar1,"Invalid line %d(%d)\n",uVar6,(ulong)puVar16 & 0xffffffff);
    uVar19 = (ulong)puVar16 & 0xffffffff;
    iVar7 = (int)puVar16;
joined_r0x0010aef0:
    if (iVar7 != 0) goto LAB_0010ad64;
  }
  else {
    puVar16 = msm_geni_console_port;
    if (uVar6 != 0) {
      puVar16 = (undefined1 *)0xfffffffffffffffa;
    }
    if (puVar16 == (undefined1 *)0x0) goto LAB_0010aed4;
LAB_0010ad38:
    if ((undefined1 *)0xfffffffffffff000 < puVar16) goto LAB_0010aed4;
    *(undefined4 *)(puVar16 + 0x808) = 0;
    puVar16[0x3fc] = lVar10 != 0;
    if (*(long *)(lVar17 + 0x28) != 0) {
      _dev_err(plVar1,"%s, Console Disabled\n","msm_geni_serial_probe");
      iVar7 = pinctrl_pm_select_sleep_state(plVar1);
      if (iVar7 != 0) {
        _dev_err(plVar1,"failed to set pinctrl state to sleep %d\n",iVar7);
      }
      uVar19 = 0;
      *(undefined1 **)(param_1 + 0xa8) = puVar16;
      goto LAB_0010ada0;
    }
    if (*(long *)(puVar16 + 0x1f8) == 0) {
      *(long **)(puVar16 + 0x150) = plVar1;
      *(long *)(puVar16 + 0x1f8) = lVar17;
      local_80 = local_80 & 0xffffffff00000000;
      *(undefined8 *)(puVar16 + 0x260) = *(undefined8 *)(param_1 + 0x70);
      uVar13 = *(undefined8 *)(param_1 + 0x70);
      *(long **)(puVar16 + 0x268) = plVar1;
      *(long **)(puVar16 + 0x2c0) = plVar1;
      *(undefined8 *)(puVar16 + 0x270) = uVar13;
      lVar14 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
      *(long *)(puVar16 + 0x2c8) = lVar14;
      if (lVar14 == 0) {
        _dev_err(plVar1,"SE Wrapper is NULL, deferring probe\n");
        uVar19 = 0xfffffdfb;
        goto LAB_0010ad64;
      }
      puVar2 = puVar16 + 0x2b8;
      *(long **)(puVar16 + 0x848) = plVar1;
      *(undefined1 **)(puVar16 + 0x858) = puVar2;
      lVar14 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,ssr-enable",0);
      puVar16[0x880] = lVar14 != 0;
      uVar19 = devm_clk_get(plVar1,"se-clk");
      *(ulong *)(puVar16 + 0x2d0) = uVar19;
      if (uVar19 < 0xfffffffffffff001) {
        iVar7 = of_device_is_compatible
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,msm-geni-one-wire-serial");
        if (iVar7 == 0) {
          if (lVar10 == 0) goto LAB_0010afac;
LAB_0010ae70:
          uVar11 = geni_icc_get(puVar2,"qup-memory");
          uVar19 = uVar11 & 0xffffffff;
          if ((int)uVar11 == 0) {
            *(undefined4 *)(puVar16 + 0x2f0) = 1;
            *(undefined4 *)(puVar16 + 0x300) = 1;
            *(undefined4 *)(puVar16 + 0x310) = 1;
LAB_0010aff0:
            lVar14 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rumi_platform",0);
            puVar16[0x3fd] = lVar14 != 0;
            iVar7 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,wakeup-byte",&local_80,1,0);
            if (-1 < iVar7) {
              puVar16[0x38c] = (char)local_80;
              _dev_info(plVar1,"Wakeup byte 0x%x\n",(uint)local_80 & 0xff);
            }
            uVar19 = devm_clk_get(plVar1,"se-clk");
            *(ulong *)(puVar16 + 0x278) = uVar19;
            if (uVar19 < 0xfffffffffffff001) {
              uVar19 = devm_clk_get(*(undefined8 *)(param_1 + 0x70),"m-ahb");
              *(ulong *)(puVar16 + 0x280) = uVar19;
              if (0xfffffffffffff000 < uVar19) {
                _dev_err(plVar1,"Err getting M AHB clk %d\n",uVar19 & 0xffffffff);
                cVar3 = puVar16[0x3fc];
                goto joined_r0x0010b3ac;
              }
              uVar19 = devm_clk_get(*(undefined8 *)(param_1 + 0x70),"s-ahb");
              *(ulong *)(puVar16 + 0x288) = uVar19;
              if (0xfffffffffffff000 < uVar19) {
                _dev_err(plVar1,"Err getting S AHB clk %d\n",uVar19 & 0xffffffff);
                cVar3 = puVar16[0x3fc];
                goto joined_r0x0010b3ac;
              }
            }
            else {
              _dev_err(plVar1,"Err getting SE Core clk %d\n",uVar19 & 0xffffffff);
              cVar3 = puVar16[0x3fc];
joined_r0x0010b3ac:
              if (cVar3 == '\0') {
                *(undefined4 *)(puVar16 + 0x450) = 2;
                ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s uart_error_code %d",
                               "msm_geni_update_uart_error_code",2);
                __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s uart_error_code %d",
                             "msm_geni_update_uart_error_code",*(undefined4 *)(puVar16 + 0x450));
              }
              if ((int)uVar19 != 0) goto LAB_0010ad64;
            }
            plVar12 = (long *)platform_get_resource_byname(param_1,0x200,"se_phys");
            if (plVar12 == (long *)0x0) {
              _dev_err(plVar1,"Err getting IO region\n");
              uVar19 = 0xfffffffa;
              goto LAB_0010ad64;
            }
            *(long *)(puVar16 + 0x140) = *plVar12;
            lVar14 = devm_ioremap(plVar1,*plVar12,(plVar12[1] - *plVar12) + 1);
            *(long *)(puVar16 + 0x10) = lVar14;
            if (lVar14 == 0) {
              pcVar18 = "Err IO mapping serial iomem\n";
            }
            else {
              *(long *)(puVar16 + 0x2b8) = lVar14;
              iVar7 = platform_get_irq(param_1,1);
              *(int *)(puVar16 + 0x388) = iVar7;
              if ((iVar7 < 0) && (puVar16[0x3fc] == '\0')) {
                _dev_info(plVar1,"No wakeup IRQ configured\n");
              }
              uVar19 = devm_pinctrl_get(plVar1);
              *(ulong *)(puVar16 + 0x290) = uVar19;
              if ((uVar19 == 0) || (0xfffffffffffff000 < uVar19)) {
                _dev_err(plVar1,"No pinctrl config specified!\n");
                uVar19 = (ulong)*(uint *)(puVar16 + 0x290);
              }
              else {
                if (puVar16[0x3fc] == '\0') {
                  uVar19 = pinctrl_lookup_state(uVar19,"shutdown");
                  if ((uVar19 == 0) || (0xfffffffffffff000 < uVar19)) {
                    _dev_info(plVar1,"No Shutdown config specified\n");
                  }
                  else {
                    uVar13 = pinctrl_lookup_state(*(undefined8 *)(puVar16 + 0x290),"shutdown");
                    *(undefined8 *)(puVar16 + 0x298) = uVar13;
                  }
                }
                uVar19 = pinctrl_lookup_state(*(undefined8 *)(puVar16 + 0x290),"active");
                *(ulong *)(puVar16 + 0x2a0) = uVar19;
                if ((uVar19 == 0) || (0xfffffffffffff000 < uVar19)) {
                  uVar19 = pinctrl_lookup_state(*(undefined8 *)(puVar16 + 0x290),"default");
                  *(ulong *)(puVar16 + 0x2a0) = uVar19;
                  if ((uVar19 == 0) || (0xfffffffffffff000 < uVar19)) {
                    _dev_err(plVar1,"No default config specified!\n");
                    uVar19 = (ulong)*(uint *)(puVar16 + 0x2a0);
                    goto LAB_0010b31c;
                  }
                }
                uVar19 = pinctrl_lookup_state(*(undefined8 *)(puVar16 + 0x290),"sleep");
                *(ulong *)(puVar16 + 0x2a8) = uVar19;
                if ((uVar19 != 0) && (uVar19 < 0xfffffffffffff001)) {
                  uVar8 = platform_get_irq(param_1,0);
                  *(undefined4 *)(puVar16 + 0xa0) = uVar8;
                  uVar13 = devm_kasprintf(*(undefined8 *)(puVar16 + 0x150),0xcc0,"msm_serial_geni%d"
                                          ,*(undefined4 *)(puVar16 + 0x134));
                  *(undefined8 *)(puVar16 + 0x210) = uVar13;
                  irq_modify_status(*(undefined4 *)(puVar16 + 0xa0),0,0x1000);
                  uVar9 = devm_request_threaded_irq
                                    (*(undefined8 *)(puVar16 + 0x150),
                                     *(undefined4 *)(puVar16 + 0xa0),msm_geni_serial_isr,0,4,
                                     *(undefined8 *)(puVar16 + 0x210),puVar16);
                  if (uVar9 == 0) {
                    if (*(int *)(puVar16 + 0x388) < 1) {
                      uVar19 = 0;
                      goto LAB_0010b31c;
                    }
                    lVar14 = (*(long **)(puVar16 + 0x150))[0xe];
                    if (lVar14 == 0) {
                      lVar14 = **(long **)(puVar16 + 0x150);
                    }
                    lVar14 = alloc_workqueue(&DAT_0011010d,0x12,1,lVar14);
                    *(long *)(puVar16 + 0x560) = lVar14;
                    if (lVar14 == 0) {
                      _dev_err(*(undefined8 *)(puVar16 + 0x150),
                               "%s:WQ alloc failed for Wakeup IRQ\n",
                               "msm_geni_serial_get_irq_pinctrl");
                      uVar19 = 0xfffffff4;
                    }
                    else {
                      *(undefined8 *)(puVar16 + 0x568) = 0xfffffffe0;
                      *(undefined1 **)(puVar16 + 0x570) = puVar16 + 0x570;
                      *(undefined1 **)(puVar16 + 0x578) = puVar16 + 0x570;
                      *(code **)(puVar16 + 0x580) = msm_geni_wakeup_work;
                      init_timer_key(puVar16 + 0x598,&delayed_work_timer_fn,0x200000,0,0);
                      irq_modify_status(*(undefined4 *)(puVar16 + 0x388),0,0x1000);
                      uVar11 = devm_request_threaded_irq
                                         (*(undefined8 *)(puVar16 + 0x150),
                                          *(undefined4 *)(puVar16 + 0x388),msm_geni_wakeup_isr,0,
                                          0x2002,"hs_uart_wakeup",puVar16);
                      uVar19 = uVar11 & 0xffffffff;
                      if ((int)uVar11 == 0) {
                        puVar16[0x402] = 0;
                        goto LAB_0010b31c;
                      }
                      _dev_err(*(undefined8 *)(puVar16 + 0x150),"%s:Failed to get WakeIRQ ret%d\n",
                               "msm_geni_serial_get_irq_pinctrl",uVar19);
                      destroy_workqueue(*(undefined8 *)(puVar16 + 0x560));
                    }
                  }
                  else {
                    uVar19 = (ulong)uVar9;
                    _dev_err(*(undefined8 *)(puVar16 + 0x150),"%s: Failed to get IRQ ret %d\n",
                             "msm_geni_serial_get_irq_pinctrl",uVar19);
                  }
                  goto LAB_0010ad64;
                }
                _dev_err(plVar1,"No sleep config specified!\n");
                uVar19 = (ulong)*(uint *)(puVar16 + 0x2a8);
              }
LAB_0010b31c:
              if ((lVar10 != 0) || ((int)uVar19 != 0)) goto LAB_0010b324;
              lVar14 = *(long *)(param_1 + 0x80);
              if (lVar14 == 0) {
                lVar14 = *plVar1;
              }
              lVar14 = wakeup_source_register(*(undefined8 *)(puVar16 + 0x150),lVar14);
              *(long *)(puVar16 + 0x390) = lVar14;
              if (lVar14 != 0) goto LAB_0010b498;
              pcVar18 = "Failed to register wakeup_source\n";
            }
            _dev_err(plVar1,pcVar18);
            uVar19 = 0xfffffff4;
            goto LAB_0010ad64;
          }
        }
        else {
          puVar16[0x8c1] = 1;
          *(undefined4 *)(puVar16 + 0x8bc) = 2;
          iVar7 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,qup-lane",puVar16 + 0x8bc,1,0);
          if ((-1 < iVar7) && ((*(uint *)(puVar16 + 0x8bc) & 0xfffffffe) != 2)) {
            *(undefined4 *)(puVar16 + 0x8bc) = 2;
          }
          _dev_info(param_1 + 0x10,"Lane:0x%x used for one wire uart usecase\n");
          lVar14 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,push-pull",0);
          puVar16[0x8c0] = lVar14 != 0;
          if (lVar10 != 0) goto LAB_0010ae70;
LAB_0010afac:
          lVar14 = *(long *)(puVar16 + 0x858);
          if (lVar14 != 0) {
            uVar11 = geni_icc_get(lVar14,"qup-memory");
            uVar19 = uVar11 & 0xffffffff;
            if ((int)uVar11 != 0) goto LAB_0010b2c0;
            *(undefined4 *)(lVar14 + 0x38) = 50000;
            *(undefined4 *)(lVar14 + 0x48) = 140000;
            *(undefined4 *)(lVar14 + 0x58) = 0x12c00;
            goto LAB_0010aff0;
          }
          uVar19 = 0xffffffea;
        }
LAB_0010b2c0:
        if (puVar16[0x3fc] == '\0') {
          *(undefined4 *)(puVar16 + 0x450) = 4;
          ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s uart_error_code %d",
                         "msm_geni_update_uart_error_code",4);
          __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s uart_error_code %d",
                       "msm_geni_update_uart_error_code",*(undefined4 *)(puVar16 + 0x450));
        }
        goto LAB_0010ad64;
      }
      _dev_err(plVar1,"Err getting SE Core clk %d\n",uVar19 & 0xffffffff);
LAB_0010b324:
      if ((int)uVar19 != 0) goto LAB_0010ad64;
LAB_0010b498:
      local_70 = 0;
      local_80 = 0;
      uStack_78 = 0;
      if (puVar16[0x3fc] == '\0') {
        *(undefined8 *)(puVar16 + 0x458) = 0x21;
        uVar9 = geni_icc_enable(puVar2);
        if (uVar9 == 0) {
          uVar9 = geni_icc_set_bw(puVar2);
          if (uVar9 == 0) {
            geni_se_common_clks_on
                      (*(undefined8 *)(puVar16 + 0x278),*(undefined8 *)(puVar16 + 0x280),
                       *(undefined8 *)(puVar16 + 0x288));
            ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                           "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(puVar16 + 0x458));
            __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                         "msm_geni_enable_disable_se_clk",1,*(undefined8 *)(puVar16 + 0x458));
            *(undefined4 *)(*(long *)(puVar16 + 0x10) + 0x48) = *(undefined4 *)(puVar16 + 0x458);
            *(undefined4 *)(*(long *)(puVar16 + 0x10) + 0x4c) = *(undefined4 *)(puVar16 + 0x458);
            goto LAB_0010b554;
          }
          uVar13 = *(undefined8 *)(puVar16 + 0x3b0);
          pcVar18 = "%s: Error %d ICC BW voting failed\n";
        }
        else {
          uVar13 = *(undefined8 *)(puVar16 + 0x3b0);
          pcVar18 = "%s: Error %d geni_icc_enable failed\n";
        }
        uVar19 = (ulong)uVar9;
        ipc_log_string(uVar13,pcVar18,"msm_geni_serial_get_ver_info",uVar19);
        __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),pcVar18,"msm_geni_serial_get_ver_info",uVar19)
        ;
LAB_0010ba70:
        _dev_err(plVar1,"Failed to Read FW ver: %d\n",uVar19);
        goto LAB_0010ad64;
      }
LAB_0010b554:
      if ((puVar16[0x8c1] == '\0') ||
         ((*(uint *)(*(long *)(puVar16 + 0x10) + 0xe2c) >> 0x13 & 1) != 0)) {
        if ((*(uint *)(*(long *)(puVar16 + 0x10) + 0x68) & 0xff00) == 0x200) {
          *(undefined4 *)(puVar16 + 0x2b0) = 2;
          *(uint *)(puVar16 + 0x3f0) = *(uint *)(*(long *)(puVar16 + 0x10) + 0x68) & 0xff;
          *(uint *)(puVar16 + 0x3f4) = *(uint *)(*(long *)(puVar16 + 0x10) + 0x6c) & 0xff;
          scnprintf(&local_80,0x28,"FW Ver:0x%x%x",*(undefined4 *)(puVar16 + 0x3f0));
          ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: FW Ver: %s\n",
                         "msm_geni_serial_get_ver_info",&local_80);
          __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s: FW Ver: %s\n",
                       "msm_geni_serial_get_ver_info",&local_80);
          uVar9 = geni_se_get_qup_hw_version(puVar2);
          ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: HW Ver: 0x%x\n",
                         "msm_geni_serial_get_ver_info",uVar9);
          __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s: HW Ver: 0x%x\n",
                       "msm_geni_serial_get_ver_info",uVar9);
          *(uint *)(puVar16 + 0x3e4) = uVar9 >> 0x1c;
          *(uint *)(puVar16 + 1000) = uVar9 >> 0x10 & 0xfff;
          *(uint *)(puVar16 + 0x3ec) = uVar9 & 0xffff;
          puVar16[0x460] = (byte)*(undefined4 *)(*(long *)(puVar16 + 0x10) + 100) & 1;
          _dev_info(*(undefined8 *)(puVar16 + 0x150),"gsi_mode:%d\n");
          if (puVar16[0x460] != '\0') {
            uVar13 = devm_kmalloc(*(undefined8 *)(puVar16 + 0x150),0x2c0,0xdc0);
            *(undefined8 *)(puVar16 + 0x468) = uVar13;
            *(undefined4 *)(puVar16 + 0x238) = 3;
            lVar14 = (*(long **)(puVar16 + 0x150))[0xe];
            if (lVar14 == 0) {
              lVar14 = **(long **)(puVar16 + 0x150);
            }
            uVar13 = alloc_workqueue(&DAT_0011010d,0x12,1,lVar14);
            *(undefined8 *)(puVar16 + 0x500) = uVar13;
            lVar14 = (*(long **)(puVar16 + 0x150))[0xe];
            if (lVar14 == 0) {
              lVar14 = **(long **)(puVar16 + 0x150);
            }
            uVar13 = alloc_workqueue(&DAT_0011010d,0x12,1,lVar14);
            *(undefined8 *)(puVar16 + 0x508) = uVar13;
            *(undefined8 *)(puVar16 + 0x470) = 0xfffffffe0;
            *(undefined1 **)(puVar16 + 0x478) = puVar16 + 0x478;
            *(undefined1 **)(puVar16 + 0x480) = puVar16 + 0x478;
            *(code **)(puVar16 + 0x488) = msm_geni_uart_gsi_xfer_tx;
            *(undefined8 *)(puVar16 + 0x4a0) = 0xfffffffe0;
            *(undefined1 **)(puVar16 + 0x4a8) = puVar16 + 0x4a8;
            *(undefined1 **)(puVar16 + 0x4b0) = puVar16 + 0x4a8;
            *(undefined8 *)(puVar16 + 0x4d0) = 0xfffffffe0;
            *(code **)(puVar16 + 0x4b8) = msm_geni_uart_gsi_cancel_rx;
            *(undefined1 **)(puVar16 + 0x4d8) = puVar16 + 0x4d8;
            *(undefined1 **)(puVar16 + 0x4e0) = puVar16 + 0x4d8;
            *(code **)(puVar16 + 0x4e8) = msm_geni_uart_gsi_cancel_tx;
          }
          msm_geni_serial_enable_interrupts(puVar16);
          uVar19 = 0;
          bVar4 = true;
          cVar3 = puVar16[0x3fc];
        }
        else {
          _dev_err(*(undefined8 *)(puVar16 + 0x150),"%s: Invalid FW %d loaded.\n",
                   "msm_geni_serial_get_ver_info",
                   *(uint *)(*(long *)(puVar16 + 0x10) + 0x68) >> 8 & 0xff);
          bVar4 = false;
          uVar19 = 0xfffffffa;
          cVar3 = puVar16[0x3fc];
        }
      }
      else {
        _dev_err(*(undefined8 *)(puVar16 + 0x150),"%s: SE doesn\'t support one wire uart mode\n",
                 "msm_geni_serial_get_ver_info");
        bVar4 = false;
        uVar19 = 0xffffffea;
        cVar3 = puVar16[0x3fc];
      }
      if (cVar3 == '\0') {
        ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                       "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(puVar16 + 0x458));
        __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                     "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(puVar16 + 0x458));
        *(undefined4 *)(*(long *)(puVar16 + 0x10) + 0x48) = 1;
        *(undefined4 *)(*(long *)(puVar16 + 0x10) + 0x4c) = 1;
        uVar20 = *(undefined8 *)(puVar16 + 0x278);
        uVar15 = *(undefined8 *)(puVar16 + 0x280);
        uVar13 = *(undefined8 *)(puVar16 + 0x288);
        clk_disable(uVar20);
        clk_unprepare(uVar20);
        clk_disable(uVar15);
        clk_unprepare(uVar15);
        clk_disable(uVar13);
        clk_unprepare(uVar13);
        uVar9 = geni_icc_disable(puVar2);
        if (uVar9 != 0) {
          uVar19 = (ulong)uVar9;
          ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: Error %d geni_icc_disable failed\n",
                         "msm_geni_serial_get_ver_info",uVar19);
          __ftrace_dbg(*(undefined8 *)(puVar16 + 0x150),"%s: Error %d geni_icc_disable failed\n",
                       "msm_geni_serial_get_ver_info",uVar19);
          goto LAB_0010ba70;
        }
      }
      if (!bVar4) goto LAB_0010ba70;
      *(undefined8 *)(puVar16 + 0x218) = 0x2000000010;
      *(undefined4 *)(puVar16 + 0x220) = 0x10;
      *(undefined4 *)(puVar16 + 0xb4) = 0x40;
      *(undefined4 *)(puVar16 + 0x408) = 0;
      __init_swait_queue_head(puVar16 + 0x410,"&x->wait",&init_completion___key);
      *(undefined4 *)(puVar16 + 0x428) = 0;
      __init_swait_queue_head(puVar16 + 0x430,"&x->wait",&init_completion___key);
      *(undefined4 *)(puVar16 + 0x510) = 0;
      __init_swait_queue_head(puVar16 + 0x518,"&x->wait",&init_completion___key);
      *(undefined4 *)(puVar16 + 0x530) = 0;
      __init_swait_queue_head(puVar16 + 0x538,"&x->wait",&init_completion___key);
      *(undefined4 *)(puVar16 + 0x5f0) = 0;
      __init_swait_queue_head(puVar16 + 0x5f8,"&x->wait",&init_completion___key);
      *(undefined1 **)(param_1 + 0xa8) = puVar16;
      lVar14 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,auto-suspend-disable",0);
      puVar16[0x558] = lVar14 != 0;
      if (puVar16[0x3fc] == '\0') {
        *(code **)(puVar16 + 600) = handle_rx_hs;
        lVar14 = devm_kmalloc(*(undefined8 *)(puVar16 + 0x150),
                              (ulong)*(uint *)(puVar16 + 0x220) << 2,0xdc0);
        *(long *)(puVar16 + 0x250) = lVar14;
        if (lVar14 == 0) goto LAB_0010ba2c;
        if (puVar16[0x558] == '\0') {
          __pm_runtime_set_status(plVar1,2);
          pm_runtime_set_autosuspend_delay(plVar1,0x96);
          __pm_runtime_use_autosuspend(plVar1,1);
          pm_runtime_enable(plVar1);
        }
        else {
          __pm_runtime_set_status(plVar1,0);
          pm_runtime_forbid(plVar1);
        }
      }
      else {
        *(code **)(puVar16 + 600) = handle_rx_console;
        lVar14 = devm_kmalloc(*(undefined8 *)(puVar16 + 0x150),4,0xdc0);
        *(long *)(puVar16 + 0x250) = lVar14;
        if (lVar14 == 0) {
LAB_0010ba2c:
          uVar19 = 0xfffffff4;
          goto LAB_0010ad64;
        }
      }
      if (puVar16[0x880] != '\0') {
        *(code **)(puVar16 + 0x870) = msm_geni_serial_ssr_down;
        *(code **)(puVar16 + 0x878) = msm_geni_serial_ssr_up;
      }
      __mutex_init(puVar16 + 0x810,"&dev_port->uart_ssr.ssr_lock",&msm_geni_serial_port_init___key);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_loopback);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_xfer_mode);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_ver_info);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_capture_kpi);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_hs_uart_operation);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_hs_uart_version);
      device_create_file(*(undefined8 *)(puVar16 + 0x150),&dev_attr_one_wire_uart_error);
      _dev_info(plVar1,"Serial port: %d added.FifoSize: %d is_console: %d\n",uVar6,
                *(undefined4 *)(puVar16 + 0xb4),lVar10 != 0);
      msm_geni_serial_debug_init(puVar16,lVar10 != 0);
      puVar16[0x248] = 0;
      *(undefined4 *)(puVar16 + 0x450) = 0;
      if (puVar16[0x3fc] == '\0') {
        *(undefined4 *)(puVar16 + 0x448) = 0;
      }
      __mutex_init(puVar16 + 0x888,"&dev_port->suspend_resume_lock",&msm_geni_serial_probe___key);
      uVar11 = uart_add_one_port(lVar17,puVar16);
      uVar19 = uVar11 & 0xffffffff;
      iVar7 = (int)uVar11;
      if (iVar7 != 0) {
        _dev_err(plVar1,"Failed to register uart_port: %d\n",uVar19);
      }
      msm_geni_check_stop_engine(puVar16);
      goto joined_r0x0010aef0;
    }
    uVar19 = 0xffffffed;
LAB_0010ad64:
    uart_line_id = bVar5;
  }
  ipc_log_string(*(undefined8 *)(puVar16 + 0x3b0),"%s: ret:%d\n","msm_geni_serial_probe",
                 uVar19 & 0xffffffff);
  __ftrace_dbg(plVar1,"%s: ret:%d\n","msm_geni_serial_probe",uVar19 & 0xffffffff);
LAB_0010ada0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar19 & 0xffffffff;
}



//------------------------------------------------------------
// msm_geni_serial_remove @ 0010bcc4 size=372
// signature: undefined msm_geni_serial_remove(void)
// callers: [msm_geni_serial_driver_shutdown]
//------------------------------------------------------------

undefined8 msm_geni_serial_remove(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(char *)(lVar1 + 0x3fc) == '\0') {
    uVar2 = *(undefined8 *)(lVar1 + 0x1f8);
    if (0 < *(int *)(lVar1 + 0x388)) {
      destroy_workqueue(*(undefined8 *)(lVar1 + 0x560));
    }
    if ((*(long *)(lVar1 + 0x100) == 0) ||
       (*(int *)(lVar1 + 0x134) != (int)*(short *)(*(long *)(lVar1 + 0x100) + 0x4a))) {
      wakeup_source_unregister(*(undefined8 *)(lVar1 + 0x390));
      *(undefined8 *)(lVar1 + 0x390) = 0;
    }
    if (*(char *)(lVar1 + 0x558) != '\0') {
      pm_runtime_allow(param_1 + 0x10);
    }
    uart_remove_one_port(uVar2,lVar1);
    if (*(char *)(lVar1 + 0x460) != '\0') {
      destroy_workqueue(*(undefined8 *)(lVar1 + 0x500));
      destroy_workqueue(*(undefined8 *)(lVar1 + 0x508));
    }
    if (*(long *)(lVar1 + 0x358) != 0) {
      if ((((undefined8 *)(lVar1 + 0x358) != (undefined8 *)0x0) && (*(long *)(lVar1 + 0x260) != 0))
         && (*(long *)(lVar1 + 0x328) != 0)) {
        dma_free_attrs(*(long *)(lVar1 + 0x260),0x800,*(long *)(lVar1 + 0x328),
                       *(long *)(lVar1 + 0x358),0);
      }
      *(undefined8 *)(lVar1 + 0x358) = 0;
    }
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_loopback);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_xfer_mode);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_ver_info);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_capture_kpi);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_hs_uart_version);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_hs_uart_operation);
    device_remove_file(*(undefined8 *)(lVar1 + 0x150),&dev_attr_one_wire_uart_error);
    debugfs_remove(*(undefined8 *)(lVar1 + 0x240));
    _dev_info(param_1 + 0x10,"%s driver removed %d\n","msm_geni_serial_remove",1);
  }
  return 0;
}



//------------------------------------------------------------
// msm_geni_serial_driver_shutdown @ 0010be3c size=72
// signature: undefined msm_geni_serial_driver_shutdown(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_driver_shutdown(long param_1)

{
  _dev_info(param_1 + 0x10,"%s called %d\n","msm_geni_serial_driver_shutdown",1);
  msm_geni_serial_remove(param_1);
  return;
}



//------------------------------------------------------------
// msm_geni_serial_debug_init @ 0010be84 size=896
// signature: undefined msm_geni_serial_debug_init(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

void msm_geni_serial_debug_init(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined7 uStack_38;
  undefined4 local_31;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  uStack_38 = 0;
  local_31 = 0;
  local_50 = 0;
  uStack_48 = 0;
  lVar1 = (*(long **)(param_1 + 0x150))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1 + 0x150);
  }
  uVar2 = debugfs_create_dir(lVar1,0);
  *(ulong *)(param_1 + 0x240) = uVar2;
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    _dev_err(*(undefined8 *)(param_1 + 0x150),"Failed to create dbg dir\n");
  }
  local_40 = 0;
  uStack_38 = 0;
  local_31 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if ((param_2 & 1) == 0) {
    if (*(long *)(param_1 + 0x3a0) == 0) {
      lVar1 = (*(long **)(param_1 + 0x150))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x150);
      }
      scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,&DAT_0010f6dc);
      lVar1 = ipc_log_context_create(0x1e,&local_50,0);
      *(long *)(param_1 + 0x3a0) = lVar1;
      if (lVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + 0x150),"Err in Rx IPC Log\n");
      }
    }
    local_40 = 0;
    uStack_38 = 0;
    local_31 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*(long *)(param_1 + 0x398) == 0) {
      lVar1 = (*(long **)(param_1 + 0x150))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x150);
      }
      scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,&DAT_00110542);
      lVar1 = ipc_log_context_create(0x1e,&local_50,0);
      *(long *)(param_1 + 0x398) = lVar1;
      if (lVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + 0x150),"Err in Tx IPC Log\n");
      }
    }
    local_40 = 0;
    uStack_38 = 0;
    local_31 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*(long *)(param_1 + 0x3a8) == 0) {
      lVar1 = (*(long **)(param_1 + 0x150))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x150);
      }
      scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,&DAT_001112d4);
      lVar1 = ipc_log_context_create(10,&local_50,0);
      *(long *)(param_1 + 0x3a8) = lVar1;
      if (lVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + 0x150),"Err in Pwr IPC Log\n");
      }
    }
    local_40 = 0;
    uStack_38 = 0;
    local_31 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*(long *)(param_1 + 0x3b0) == 0) {
      lVar1 = (*(long **)(param_1 + 0x150))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x150);
      }
      scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,"_misc");
      lVar1 = ipc_log_context_create(0x1e,&local_50,0);
      *(long *)(param_1 + 0x3b0) = lVar1;
      if (lVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + 0x150),"Err in Misc IPC Log\n");
      }
    }
    local_40 = 0;
    uStack_38 = 0;
    local_31 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*(long *)(param_1 + 0x3d0) == 0) {
      lVar1 = (*(long **)(param_1 + 0x150))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x150);
      }
      scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,"_irqstatus");
      lVar1 = ipc_log_context_create(0x1e,&local_50,0);
      *(long *)(param_1 + 0x3d0) = lVar1;
      if (lVar1 == 0) {
        _dev_info(*(undefined8 *)(param_1 + 0x150),"Err in irqstatus IPC Log\n");
      }
    }
    local_40 = 0;
    uStack_38 = 0;
    local_31 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*(long *)(param_1 + 0x3c0) != 0) goto LAB_0010c14c;
    lVar1 = (*(long **)(param_1 + 0x150))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x150);
    }
    scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,&DAT_001111bb);
    lVar1 = ipc_log_context_create(0x1e,&local_50,0);
    *(long *)(param_1 + 0x3c0) = lVar1;
    if (lVar1 != 0) goto LAB_0010c14c;
    pcVar3 = "Err with New IPC Log\n";
  }
  else {
    if (*(long *)(param_1 + 0x3c8) != 0) goto LAB_0010c14c;
    lVar1 = (*(long **)(param_1 + 0x150))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x150);
    }
    scnprintf(&local_50,0x23,&DAT_001103d5,lVar1,"_console");
    lVar1 = ipc_log_context_create(0x1e,&local_50,0);
    *(long *)(param_1 + 0x3c8) = lVar1;
    if (lVar1 != 0) goto LAB_0010c14c;
    pcVar3 = "Err in Misc IPC Log\n";
  }
  _dev_info(*(undefined8 *)(param_1 + 0x150),pcVar3);
LAB_0010c14c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_geni_check_stop_engine @ 0010c204 size=648
// signature: undefined msm_geni_check_stop_engine(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

void msm_geni_check_stop_engine(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0x40);
  if ((uVar2 & 1) == 0) {
    if ((uVar2 >> 0xc & 1) == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x3ff) = 0;
    *(undefined4 *)(param_1 + 0x428) = 0;
    *(undefined1 *)(param_1 + 0x401) = 1;
    uVar2 = msm_serial_try_disable_interrupts(param_1);
    *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x634) = 4;
    uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
    uVar4 = *(undefined8 *)(param_1 + 0x3b0);
    if ((uVar3 & 1) == 0) {
      pcVar5 = "%s: RX cancel cmd done\n";
    }
    else {
      ipc_log_string(uVar4,"%s: RX Cancel cmd failed, geni_status:0x%x\n",
                     "msm_geni_check_stop_engine",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40))
      ;
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: RX Cancel cmd failed, geni_status:0x%x\n",
                   "msm_geni_check_stop_engine",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
      *(undefined1 *)(param_1 + 0x3ff) = 0;
      *(undefined4 *)(param_1 + 0x428) = 0;
      *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x634) = 2;
      uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
      uVar4 = *(undefined8 *)(param_1 + 0x3b0);
      if ((uVar3 & 1) != 0) {
        pcVar5 = "%s: RX abort cmd failed, geni_status:0x%x\n";
        ipc_log_string(uVar4,"%s: RX abort cmd failed, geni_status:0x%x\n",
                       "msm_geni_check_stop_engine",
                       *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
        uVar4 = *(undefined8 *)(param_1 + 0x150);
        uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
LAB_0010c418:
        __ftrace_dbg(uVar4,pcVar5,"msm_geni_check_stop_engine",uVar1);
        return;
      }
      pcVar5 = "%s: RX abort cmd done\n";
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x3fe) = 0;
    *(undefined4 *)(param_1 + 0x408) = 0;
    *(undefined1 *)(param_1 + 0x400) = 1;
    uVar2 = msm_serial_try_disable_interrupts(param_1);
    *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 4;
    uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
    uVar4 = *(undefined8 *)(param_1 + 0x3b0);
    if ((uVar3 & 1) == 0) {
      pcVar5 = "%s: TX Cancel cmd done\n";
    }
    else {
      ipc_log_string(uVar4,"%s: TX Cancel cmd failed, geni_status:0x%x\n",
                     "msm_geni_check_stop_engine",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40))
      ;
      __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s: TX Cancel cmd failed, geni_status:0x%x\n",
                   "msm_geni_check_stop_engine",*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
      *(undefined1 *)(param_1 + 0x3fe) = 0;
      *(undefined4 *)(param_1 + 0x408) = 0;
      *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x604) = 2;
      uVar3 = geni_wait_for_cmd_done(param_1,uVar2 & 1);
      uVar4 = *(undefined8 *)(param_1 + 0x3b0);
      if ((uVar3 & 1) != 0) {
        pcVar5 = "%s: TX abort cmd failed, geni_status:0x%x\n";
        ipc_log_string(uVar4,"%s: TX abort cmd failed, geni_status:0x%x\n",
                       "msm_geni_check_stop_engine",
                       *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40));
        uVar4 = *(undefined8 *)(param_1 + 0x150);
        uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x40);
        goto LAB_0010c418;
      }
      pcVar5 = "%s: TX abort cmd done\n";
    }
  }
  ipc_log_string(uVar4,pcVar5,"msm_geni_check_stop_engine");
  __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),pcVar5,"msm_geni_check_stop_engine");
  return;
}



//------------------------------------------------------------
// msm_geni_serial_isr @ 0010c490 size=124
// signature: undefined msm_geni_serial_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_geni_serial_isr(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = _raw_spin_lock_irqsave(param_2);
  msm_geni_serial_handle_isr(param_2,&local_30,0);
  _raw_spin_unlock_irqrestore(param_2,local_30);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// msm_geni_wakeup_work @ 0010c510 size=316
// signature: undefined msm_geni_wakeup_work(void)
// callers: []
//------------------------------------------------------------

void msm_geni_wakeup_work(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  long *plVar6;
  
  if (*(int *)(param_1 + -0xc) != 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    iVar1 = msm_geni_serial_power_on(param_1 + -0x568);
    if (iVar1 == 0) {
      lVar2 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x88),500);
      if (lVar2 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + -0x1c8),
                       "%s completion of wakeup_comp task timedout %dmsec\n","msm_geni_wakeup_work",
                       2000);
        __ftrace_dbg(*(undefined8 *)(param_1 + -0x418),
                     "%s completion of wakeup_comp task timedout %dmsec\n","msm_geni_wakeup_work",
                     2000);
      }
      plVar6 = (long *)(param_1 + -0x418);
      lVar2 = *plVar6;
      if (*(int *)(lVar2 + 0x1f8) != 0) {
        if ((*(ushort *)(lVar2 + 0x200) & 7) == 0) {
          uVar3 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar2 + 0x220) = uVar3;
          __pm_runtime_suspend(*plVar6,0xd);
          return;
        }
        return;
      }
      ipc_log_string(*(undefined8 *)(param_1 + -0x1c0),"%s: Usage Count is already 0\n",
                     "msm_geni_serial_power_off");
      lVar2 = *plVar6;
      pcVar4 = "%s: Usage Count is already 0\n";
      pcVar5 = "msm_geni_serial_power_off";
    }
    else {
      *(undefined4 *)(param_1 + -0xc) = 0;
      ipc_log_string(*(undefined8 *)(param_1 + -0x1c8),"%s:Failed to power on\n",
                     "msm_geni_wakeup_work");
      pcVar4 = "%s:Failed to power on\n";
      pcVar5 = "msm_geni_wakeup_work";
      lVar2 = *(long *)(param_1 + -0x418);
    }
    __ftrace_dbg(lVar2,pcVar4,pcVar5);
  }
  return;
}



//------------------------------------------------------------
// msm_geni_wakeup_isr @ 0010c650 size=460
// signature: undefined msm_geni_wakeup_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_geni_wakeup_isr(undefined8 param_1,long param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_2 + 0x3b8);
  if (lVar4 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_2 + 900) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","msm_geni_wakeup_isr",uVar1,
                   uVar1 / 1000);
  }
  ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s %d\n","msm_geni_wakeup_isr",1);
  __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s %d\n","msm_geni_wakeup_isr",1);
  uVar2 = _raw_spin_lock_irqsave(param_2);
  if (*(int *)(param_2 + 0x55c) == 0) {
    if (*(long *)(*(long *)(param_2 + 200) + 0xa8) != 0) {
      *(undefined4 *)(param_2 + 0x55c) = 1;
      queue_delayed_work_on(0x20,*(undefined8 *)(param_2 + 0x560),param_2 + 0x568,0);
      _raw_spin_unlock_irqrestore(param_2,uVar2);
      ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s: End %d\n","msm_geni_wakeup_isr",1);
      __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: End %d\n","msm_geni_wakeup_isr",1);
      lVar4 = *(long *)(param_2 + 0x3b8);
      if (lVar4 == 0) {
        return 1;
      }
      if (uVar1 == 0) {
        return 1;
      }
      if (*(int *)(param_2 + 900) == 0) {
        return 1;
      }
      lVar3 = sched_clock();
      ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","msm_geni_wakeup_isr",lVar3 - uVar1,
                     (lVar3 - uVar1) / 1000);
      return 1;
    }
    ipc_log_string(*(undefined8 *)(param_2 + 0x3a0),"%s: Unexpected wakeup ISR\n",
                   "msm_geni_wakeup_isr");
    __ftrace_dbg(*(undefined8 *)(param_2 + 0x150),"%s: Unexpected wakeup ISR\n",
                 "msm_geni_wakeup_isr");
  }
  _raw_spin_unlock_irqrestore(param_2,uVar2);
  return 1;
}



//------------------------------------------------------------
// handle_rx_console @ 0010c820 size=8
// signature: undefined handle_rx_console(void)
// callers: []
//------------------------------------------------------------

undefined8 handle_rx_console(void)

{
  return 0xffffffff;
}



//------------------------------------------------------------
// handle_rx_hs @ 0010c82c size=456
// signature: undefined handle_rx_hs(void)
// callers: []
//------------------------------------------------------------

int handle_rx_hs(long param_1,int param_2,uint param_3,int param_4,ulong param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
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
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  uVar1 = *(uint *)(param_1 + 0x21c);
  uVar7 = *(undefined8 *)(param_1 + 200);
  if (param_4 == 0 || param_3 == 0) {
    param_3 = uVar1 >> 3;
  }
  if (param_2 != 0) {
    lVar4 = *(long *)(param_1 + 0x10);
    puVar5 = *(undefined4 **)(param_1 + 0x250);
    iVar6 = param_2;
    do {
      iVar6 = iVar6 + -1;
      *puVar5 = *(undefined4 *)(lVar4 + 0x780);
      puVar5 = puVar5 + 1;
    } while (iVar6 != 0);
  }
  if ((param_5 & 1) == 0) {
    iVar6 = param_3 + (uVar1 * (param_2 + -1) >> 3);
    iVar2 = tty_insert_flip_string_fixed_flag(uVar7,*(undefined8 *)(param_1 + 0x250),0,(long)iVar6);
    if (iVar2 != iVar6) {
      _dev_err(*(undefined8 *)(param_1 + 0x150),"%s: ret %d rx_bytes %d\n","handle_rx_hs",iVar2,
               iVar6);
    }
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + iVar2;
    tty_flip_buffer_push(uVar7);
    iVar3 = iVar6;
    if (0x1f < iVar6) {
      iVar3 = 0x20;
    }
    uVar7 = *(undefined8 *)(param_1 + 0x3a0);
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
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    hex_dump_to_buffer(*(undefined8 *)(param_1 + 0x250),(long)iVar3,0x20,1,&local_88,0x40,0);
    scnprintf(&local_e8,0x60,"%s[0x%.10x:%d] : %s",&DAT_0010f957,0,iVar6,&local_88);
    ipc_log_string(uVar7,"%s : %s\n","dump_ipc",&local_e8);
    __ftrace_dbg(*(undefined8 *)(param_1 + 0x150),"%s : %s\n","dump_ipc",&local_e8);
  }
  else {
    iVar2 = 0;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_geni_serial_ssr_down @ 0010c9f8 size=292
// signature: undefined msm_geni_serial_ssr_down(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_ssr_down(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar6 + 0x810);
  *(undefined1 *)(lVar6 + 0x840) = 1;
  iVar5 = pm_runtime_force_suspend(*(undefined8 *)(lVar6 + 0x150));
  if (iVar5 == 0) {
    piVar1 = (int *)(*(long *)(lVar6 + 0x150) + 0x1f8);
    iVar5 = *(int *)(*(long *)(lVar6 + 0x150) + 0x1f8);
    do {
      if (iVar5 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar5) goto LAB_0010caa4;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar5 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010caa4:
      bVar4 = iVar5 != iVar2;
      iVar5 = iVar2;
    } while (bVar4);
    pm_runtime_enable(*(undefined8 *)(lVar6 + 0x150));
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s:force suspend failed %d\n",iVar5,
                   "msm_geni_serial_ssr_down");
    __ftrace_dbg(param_1,"%s:force suspend failed %d\n",iVar5,"msm_geni_serial_ssr_down");
  }
  mutex_unlock(lVar6 + 0x810);
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: Force suspend done\n",
                 "msm_geni_serial_ssr_down");
  __ftrace_dbg(param_1,"%s: Force suspend done\n","msm_geni_serial_ssr_down");
  return;
}



//------------------------------------------------------------
// msm_geni_serial_ssr_up @ 0010cb34 size=124
// signature: undefined msm_geni_serial_ssr_up(void)
// callers: []
//------------------------------------------------------------

void msm_geni_serial_ssr_up(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar1 + 0x810);
  *(undefined1 *)(lVar1 + 0x840) = 0;
  *(undefined1 *)(lVar1 + 0x248) = 0;
  mutex_unlock(lVar1 + 0x810);
  ipc_log_string(*(undefined8 *)(lVar1 + 0x3b0),"%s: Force resume done\n","msm_geni_serial_ssr_up");
  __ftrace_dbg(param_1,"%s: Force resume done\n","msm_geni_serial_ssr_up");
  return;
}



//------------------------------------------------------------
// msm_geni_uart_gsi_xfer_tx @ 0010cbb4 size=1408
// signature: undefined msm_geni_uart_gsi_xfer_tx(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_gsi_xfer_tx(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  code *pcVar10;
  char *pcVar11;
  long lVar12;
  long lVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  long *plVar16;
  long lVar17;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar12 = sp_el0;
  local_70 = *(long *)(lVar12 + 0x638);
  lVar13 = *(long *)(param_1 + -8);
  lVar12 = param_1 + -0x470;
  plVar6 = *(long **)(param_1 + -0x210);
  lVar17 = *(long *)(param_1 + -0x3a8);
  ipc_log_string(*(undefined8 *)(param_1 + -0xc0),"%s: Start\n","msm_geni_uart_gsi_xfer_tx");
  puVar15 = (undefined8 *)(param_1 + -800);
  __ftrace_dbg(*puVar15,"%s: Start\n","msm_geni_uart_gsi_xfer_tx");
  iVar2 = *(int *)(lVar17 + 0x1d4);
  uVar5 = *(int *)(lVar17 + 0x1d0) - iVar2 & 0xfff;
  if (uVar5 < 0x100) {
    uart_write_wakeup(lVar12);
    iVar2 = *(int *)(lVar17 + 0x1d4);
  }
  uVar9 = 0x1000 - (long)iVar2;
  uVar1 = (uint)uVar9;
  if (uVar5 <= uVar9) {
    uVar1 = uVar5;
  }
  if ((uVar1 != 0) && (plVar16 = (long *)(param_1 + -0x158), *plVar16 == 0)) {
    uVar5 = uVar1;
    if (0x1f < (int)uVar1) {
      uVar5 = 0x20;
    }
    uVar14 = *(undefined8 *)(param_1 + -0xd8);
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    local_f0 = 0;
    uStack_e8 = 0;
    local_100 = 0;
    uStack_f8 = 0;
    local_110 = 0;
    uStack_108 = 0;
    hex_dump_to_buffer(*(long *)(lVar17 + 0x1c8) + (long)iVar2,(long)(int)uVar5,0x20,1,&local_b0,
                       0x40,0);
    scnprintf(&local_110,0x60,"%s[0x%.10x:%d] : %s","DMA Tx",0,uVar1,&local_b0);
    ipc_log_string(uVar14,"%s : %s\n","dump_ipc",&local_110);
    __ftrace_dbg(*puVar15,"%s : %s\n","dump_ipc",&local_110);
    iVar2 = msm_geni_allocate_chan(lVar12);
    if (iVar2 == 0) {
      sg_init_table(*(long *)(param_1 + -8) + 0xf0,3);
      lVar7 = *(long *)(param_1 + -8);
      *(uint *)(lVar7 + 0xf8) = (uint)(lVar7 + 0x10) & 0xfff;
      *(undefined4 *)(lVar7 + 0xfc) = 0x10;
      *(ulong *)(lVar7 + 0xf0) =
           (*(ulong *)(lVar7 + 0xf0) & 3 |
           (((lVar7 + 0x10) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000;
      *(undefined8 *)(lVar13 + 0x30) = 1;
      *(undefined8 *)(lVar13 + 0x38) = 0x20000100000000;
      lVar7 = *(long *)(param_1 + -8);
      *(uint *)(lVar7 + 0x118) = (uint)(lVar13 + 0x30) & 0xfff;
      *(undefined4 *)(lVar7 + 0x11c) = 0x10;
      *(ulong *)(lVar7 + 0x110) =
           (*(ulong *)(lVar7 + 0x110) & 3 |
           (((lVar13 + 0x30) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000;
      if (plVar6 != (long *)0x0) {
        uVar9 = *(long *)(lVar17 + 0x1c8) + (long)*(int *)(lVar17 + 0x1d4);
        uVar3 = is_vmalloc_addr(uVar9);
        if (((uVar3 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar14 = dev_driver_string(plVar6);
          lVar12 = plVar6[0xe];
          if (lVar12 == 0) {
            lVar12 = *plVar6;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar14,lVar12);
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10d104);
          (*pcVar10)();
        }
        if ((uVar3 & 1) == 0) {
          lVar13 = dma_map_page_attrs(plVar6,(((long)(uVar9 * 0x100) >> 8) + 0x8000000000U >> 0xc) *
                                             0x40 + -0x200000000,uVar9 & 0xfff,uVar1,1,0);
          *plVar16 = lVar13;
          if (lVar13 != -1) {
            *(uint *)(param_1 + -0x150) = uVar1;
            *(int *)(*(long *)(param_1 + -8) + 0x50) = (int)lVar13;
            *(undefined4 *)(*(long *)(param_1 + -8) + 0x54) = *(undefined4 *)(param_1 + -0x154);
            *(uint *)(*(long *)(param_1 + -8) + 0x58) = uVar1 & 0xffffff;
            *(undefined4 *)(*(long *)(param_1 + -8) + 0x5c) = 0x100200;
            lVar13 = *(long *)(param_1 + -8);
            *(uint *)(lVar13 + 0x138) = (uint)(lVar13 + 0x50) & 0xfff;
            *(undefined4 *)(lVar13 + 0x13c) = 0x10;
            *(ulong *)(lVar13 + 0x130) =
                 (*(ulong *)(lVar13 + 0x130) & 3 |
                 (((lVar13 + 0x50) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000;
            plVar8 = *(long **)(param_1 + -8);
            plVar4 = (long *)*plVar8;
            lVar13 = 0;
            if (plVar4 != (long *)0x0) {
              if ((*plVar4 == 0) || (pcVar10 = *(code **)(*plVar4 + 0x108), pcVar10 == (code *)0x0))
              {
                lVar13 = 0;
              }
              else {
                if (*(int *)(pcVar10 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x10cefc);
                  (*pcVar10)();
                }
                lVar13 = (*pcVar10)(plVar4,plVar8 + 0x1e,3,1,3,0);
                plVar8 = *(long **)(param_1 + -8);
              }
            }
            plVar8[0x4a] = lVar13;
            lVar13 = *(long *)(*(long *)(param_1 + -8) + 0x250);
            if (lVar13 == 0) {
              _dev_err(*puVar15,"%s:TX descriptor prep failed\n","msm_geni_uart_gsi_xfer_tx");
              if (*plVar16 != -1) {
                dma_unmap_page_attrs(plVar6,*plVar16,*(uint *)(param_1 + -0x150),1,0);
              }
              msm_geni_deallocate_chan(lVar12);
              uVar14 = *(undefined8 *)(param_1 + -0xc0);
              pcVar11 = "%s: Failed to prep Tx descriptor";
            }
            else {
              *(code **)(lVar13 + 0x28) = msm_geni_uart_gsi_tx_cb;
              *(long *)(*(long *)(*(long *)(param_1 + -8) + 0x250) + 0x38) =
                   *(long *)(param_1 + -8) + 0x260;
              pcVar10 = *(code **)(*(long *)(*(long *)(param_1 + -8) + 0x250) + 0x18);
              if (*(int *)(pcVar10 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10cf5c);
                (*pcVar10)();
              }
              iVar2 = (*pcVar10)();
              if (iVar2 < 0) {
                _printk(&DAT_0011163d,"msm_geni_uart_gsi_xfer_tx",iVar2);
                pcVar10 = *(code **)(*(long *)**(undefined8 **)(param_1 + -8) + 0x148);
                if (pcVar10 != (code *)0x0) {
                  if (*(int *)(pcVar10 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10d0c0);
                    (*pcVar10)();
                  }
                  (*pcVar10)();
                }
                goto LAB_0010cfd4;
              }
              *(undefined4 *)(param_1 + 0xc0) = 0;
              pcVar10 = *(code **)(*(long *)**(undefined8 **)(param_1 + -8) + 0x160);
              if (*(int *)(pcVar10 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10cf90);
                (*pcVar10)();
              }
              (*pcVar10)();
              wait_for_completion_timeout((undefined4 *)(param_1 + 0xc0),0x19);
              pcVar11 = "%s: End\n";
              uVar14 = *(undefined8 *)(param_1 + -0xc0);
            }
            ipc_log_string(uVar14,pcVar11,"msm_geni_uart_gsi_xfer_tx");
            __ftrace_dbg(*puVar15,pcVar11,"msm_geni_uart_gsi_xfer_tx");
            goto LAB_0010cfd4;
          }
        }
        else {
          *plVar16 = -1;
        }
      }
      _dev_err(*puVar15,"%s:Failed to allocate memory\n","msm_geni_uart_gsi_xfer_tx");
      msm_geni_deallocate_chan(lVar12);
    }
    else {
      _dev_err(*puVar15,"%s: Allocation of Channel failed:%d\n","msm_geni_uart_gsi_xfer_tx",iVar2);
    }
  }
LAB_0010cfd4:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_geni_uart_gsi_cancel_rx @ 0010d144 size=296
// signature: undefined msm_geni_uart_gsi_cancel_rx(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_gsi_cancel_rx(long param_1)

{
  int iVar1;
  long *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  ipc_log_string(*(undefined8 *)(param_1 + -0xf0),"%s: Start\n","msm_geni_uart_gsi_cancel_rx");
  puVar4 = (undefined8 *)(param_1 + -0x350);
  __ftrace_dbg(*puVar4,"%s: Start\n","msm_geni_uart_gsi_cancel_rx");
  if (*(char *)(param_1 + 0xb9) == '\0') {
    ipc_log_string(*(undefined8 *)(param_1 + -0xf0),"%s: gsi_rx not yet done\n",
                   "msm_geni_uart_gsi_cancel_rx");
    __ftrace_dbg(*puVar4,"%s: gsi_rx not yet done\n","msm_geni_uart_gsi_cancel_rx");
    *(undefined4 *)(param_1 + 0xb4) = 0;
    return;
  }
  plVar2 = *(long **)(*(long *)(param_1 + -0x38) + 8);
  if (plVar2 != (long *)0x0) {
    pcVar3 = *(code **)(*plVar2 + 0x148);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10d1c8);
        (*pcVar3)();
      }
      iVar1 = (*pcVar3)();
      if (iVar1 == 0) goto LAB_0010d1e8;
    }
    ipc_log_string(*(undefined8 *)(param_1 + -0xf0),"%s: dmaengine_terminate_all failed for Rx ch\n"
                   ,"msm_geni_uart_gsi_cancel_rx");
  }
LAB_0010d1e8:
  complete(param_1 + 0x70);
  *(undefined1 *)(param_1 + 0xb9) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  ipc_log_string(*(undefined8 *)(param_1 + -0xf0),"%s: End\n","msm_geni_uart_gsi_cancel_rx");
  __ftrace_dbg(*puVar4,"%s: End\n","msm_geni_uart_gsi_cancel_rx");
  return;
}



//------------------------------------------------------------
// msm_geni_uart_gsi_cancel_tx @ 0010d270 size=120
// signature: undefined msm_geni_uart_gsi_cancel_tx(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_gsi_cancel_tx(long param_1)

{
  int iVar1;
  code *pcVar2;
  
  if ((long *)**(long **)(param_1 + -0x68) != (long *)0x0) {
    pcVar2 = *(code **)(*(long *)**(long **)(param_1 + -0x68) + 0x148);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10d2b4);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)();
      if (iVar1 == 0) {
        return;
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + -0x120),
                   "%s: dmaengine_terminate_all failed for Tx ch\n","msm_geni_uart_gsi_cancel_tx");
  }
  return;
}



//------------------------------------------------------------
// msm_geni_uart_gsi_tx_cb @ 0010d2ec size=456
// signature: undefined msm_geni_uart_gsi_tx_cb(void)
// callers: []
//------------------------------------------------------------

void msm_geni_uart_gsi_tx_cb(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x20);
  lVar4 = *(long *)(lVar3 + 200);
  ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s: Start\n","msm_geni_uart_gsi_tx_cb");
  __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s: Start\n","msm_geni_uart_gsi_tx_cb");
  *(uint *)(lVar4 + 0x1d4) = *(int *)(lVar3 + 800) + *(int *)(lVar4 + 0x1d4) & 0xfff;
  geni_se_tx_dma_unprep(lVar3 + 0x2b8,*(undefined8 *)(lVar3 + 0x318),*(undefined4 *)(lVar3 + 800));
  iVar1 = *(int *)(lVar3 + 800);
  *(undefined8 *)(lVar3 + 0x318) = 0;
  *(undefined4 *)(lVar3 + 800) = 0;
  *(int *)(lVar3 + 0xe4) = *(int *)(lVar3 + 0xe4) + iVar1;
  complete(lVar3 + 0x530);
  if (*(int *)(lVar4 + 0x1d0) == *(int *)(lVar4 + 0x1d4)) {
    if ((*(long *)(lVar3 + 0x100) == 0) ||
       (*(int *)(lVar3 + 0x134) != (int)*(short *)(*(long *)(lVar3 + 0x100) + 0x4a))) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s.Tx sent out, Power off\n",
                     "msm_geni_uart_gsi_tx_cb");
      __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s.Tx sent out, Power off\n",
                   "msm_geni_uart_gsi_tx_cb");
      lVar4 = *(long *)(lVar3 + 0x150);
      if (*(int *)(lVar4 + 0x1f8) == 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s: Usage Count is already 0\n",
                       "msm_geni_serial_power_off");
        __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s: Usage Count is already 0\n",
                     "msm_geni_serial_power_off");
      }
      else if ((*(ushort *)(lVar4 + 0x200) & 7) == 0) {
        uVar2 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar4 + 0x220) = uVar2;
        __pm_runtime_suspend(*(undefined8 *)(lVar3 + 0x150),0xd);
      }
    }
    uart_write_wakeup(lVar3);
  }
  else {
    queue_work_on(0x20,*(undefined8 *)(lVar3 + 0x500),lVar3 + 0x470);
    ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s: End\n","msm_geni_uart_gsi_tx_cb");
    __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s: End\n","msm_geni_uart_gsi_tx_cb");
  }
  ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s:End\n","msm_geni_uart_gsi_tx_cb");
  __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s:End\n","msm_geni_uart_gsi_tx_cb");
  return;
}



//------------------------------------------------------------
// loopback_show @ 0010d4b8 size=60
// signature: undefined loopback_show(void)
// callers: []
//------------------------------------------------------------

long loopback_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,4,&DAT_0010ff05,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x380));
  return (long)iVar1;
}



//------------------------------------------------------------
// loopback_store @ 0010d4f8 size=96
// signature: undefined loopback_store(void)
// callers: []
//------------------------------------------------------------

undefined8 loopback_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = kstrtoint(param_3,0,*(long *)(param_1 + 0x98) + 0x380);
  if (iVar1 != 0) {
    _dev_err(param_1,"Invalid input\n");
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// xfer_mode_show @ 0010d55c size=104
// signature: undefined xfer_mode_show(void)
// callers: []
//------------------------------------------------------------

long xfer_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x98) + 0x238);
  if (iVar1 == 2) {
    pcVar3 = "SE_DMA\n";
    uVar2 = 8;
  }
  else {
    if (iVar1 != 1) {
      return 0;
    }
    pcVar3 = "FIFO\n";
    uVar2 = 6;
  }
  iVar1 = scnprintf(param_3,uVar2,pcVar3);
  return (long)iVar1;
}



//------------------------------------------------------------
// xfer_mode_store @ 0010d5c8 size=600
// signature: undefined xfer_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 xfer_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if ((*(long *)(lVar3 + 0x100) != 0) &&
     (*(int *)(lVar3 + 0x134) == (int)*(short *)(*(long *)(lVar3 + 0x100) + 0x4a))) {
    return 0xffffffffffffffa1;
  }
  lVar1 = strnstr(param_3,&DAT_00111e35,4);
  if (lVar1 == 0) {
    lVar1 = strnstr(param_3,"SE_DMA",6);
    if (lVar1 == 0) {
      _dev_err(param_1,"%s: Invalid input %s\n","xfer_mode_store",param_3);
      return 0xffffffffffffffea;
    }
    iVar4 = 2;
  }
  else {
    iVar4 = 1;
  }
  if (iVar4 == *(int *)(lVar3 + 0x238)) {
    return param_4;
  }
  msm_geni_serial_power_on(lVar3);
  if ((*(long *)(lVar3 + 0x100) == 0) ||
     (*(int *)(lVar3 + 0x134) != (int)*(short *)(*(long *)(lVar3 + 0x100) + 0x4a))) {
    lVar1 = *(long *)(lVar3 + 0x150);
    if ((*(int *)(lVar1 + 0x20c) != 2) || (*(int *)(lVar1 + 0x1f8) != 0)) goto LAB_0010d690;
    _dev_err(lVar1,"%s.Device is suspended.\n","msm_geni_serial_stop_tx");
    ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s.Device is suspended.\n",
                   "msm_geni_serial_stop_tx");
    __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s.Device is suspended.\n",
                 "msm_geni_serial_stop_tx");
  }
  else {
LAB_0010d690:
    stop_tx_sequencer(lVar3);
  }
  msm_geni_serial_stop_rx(lVar3);
  uVar2 = _raw_spin_lock_irqsave(lVar3);
  *(int *)(lVar3 + 0x238) = iVar4;
  geni_se_select_mode(lVar3 + 0x2b8,iVar4);
  _raw_spin_unlock_irqrestore(lVar3,uVar2);
  if ((*(long *)(lVar3 + 0x100) == 0) ||
     (*(int *)(lVar3 + 0x134) != (int)*(short *)(*(long *)(lVar3 + 0x100) + 0x4a))) {
    lVar1 = *(long *)(lVar3 + 0x150);
    if ((*(int *)(lVar1 + 0x20c) == 2) && (*(int *)(lVar1 + 0x1f8) == 0)) {
      _dev_err(lVar1,"%s.Device is suspended.\n","msm_geni_serial_start_rx");
      ipc_log_string(*(undefined8 *)(lVar3 + 0x3b0),"%s.Device is suspended.\n",
                     "msm_geni_serial_start_rx");
      __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s.Device is suspended.\n",
                   "msm_geni_serial_start_rx");
      goto LAB_0010d700;
    }
  }
  start_rx_sequencer(lVar3);
LAB_0010d700:
  lVar1 = *(long *)(lVar3 + 0x150);
  if (*(int *)(lVar1 + 0x1f8) == 0) {
    ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s: Usage Count is already 0\n",
                   "msm_geni_serial_power_off");
    __ftrace_dbg(*(undefined8 *)(lVar3 + 0x150),"%s: Usage Count is already 0\n",
                 "msm_geni_serial_power_off");
  }
  else if ((*(ushort *)(lVar1 + 0x200) & 7) == 0) {
    uVar2 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar1 + 0x220) = uVar2;
    __pm_runtime_suspend(*(undefined8 *)(lVar3 + 0x150),0xd);
  }
  return param_4;
}



//------------------------------------------------------------
// ver_info_show @ 0010d824 size=76
// signature: undefined ver_info_show(void)
// callers: []
//------------------------------------------------------------

long ver_info_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = scnprintf(param_3,0x28,"FW ver=0x%x%x, HW ver=%d.%d.%d\n",*(undefined4 *)(lVar2 + 0x3f0),
                    *(undefined4 *)(lVar2 + 0x3f0),*(undefined4 *)(lVar2 + 0x3e4),
                    *(undefined4 *)(lVar2 + 1000),*(undefined4 *)(lVar2 + 0x3ec));
  return (long)iVar1;
}



//------------------------------------------------------------
// capture_kpi_show @ 0010d874 size=60
// signature: undefined capture_kpi_show(void)
// callers: []
//------------------------------------------------------------

long capture_kpi_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,4,&DAT_0010ff05,*(undefined4 *)(*(long *)(param_1 + 0x98) + 900));
  return (long)iVar1;
}



//------------------------------------------------------------
// capture_kpi_store @ 0010d8b4 size=260
// signature: undefined capture_kpi_store(void)
// callers: []
//------------------------------------------------------------

undefined8 capture_kpi_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined7 uStack_48;
  undefined4 local_41;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  iVar1 = kstrtoint(param_3,0,(int *)(lVar3 + 900));
  if (iVar1 == 0) {
    if ((*(int *)(lVar3 + 900) != 0) && (*(long *)(lVar3 + 0x3b8) == 0)) {
      local_50 = 0;
      uStack_48 = 0;
      local_41 = 0;
      local_60 = 0;
      uStack_58 = 0;
      lVar2 = (*(long **)(lVar3 + 0x150))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(lVar3 + 0x150);
      }
      scnprintf(&local_60,0x23,&DAT_001103d5,lVar2,&DAT_0010fd45);
      lVar2 = ipc_log_context_create(4,&local_60,0);
      *(long *)(lVar3 + 0x3b8) = lVar2;
      if (lVar2 == 0) {
        _dev_info(*(undefined8 *)(lVar3 + 0x150),"Err in KPI IPC Log\n");
      }
    }
  }
  else {
    _dev_err(param_1,"Invalid input\n");
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hs_uart_operation_show @ 0010d9bc size=60
// signature: undefined hs_uart_operation_show(void)
// callers: []
//------------------------------------------------------------

long hs_uart_operation_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010ff05,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x80c))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// hs_uart_operation_store @ 0010d9fc size=348
// signature: undefined hs_uart_operation_store(void)
// callers: []
//------------------------------------------------------------

undefined8
hs_uart_operation_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  short local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c[0] = 0;
  iVar1 = kstrtou16(param_3,0x10,local_3c);
  if (iVar1 == 0) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x3b0),"%s: cmd: %u\n","hs_uart_operation_store",
                   local_3c[0]);
    __ftrace_dbg(*(undefined8 *)(lVar2 + 0x150),"%s: cmd: %u\n","hs_uart_operation_store",
                 local_3c[0]);
    iVar1 = msm_geni_serial_ioctl(lVar2,local_3c[0]);
    if (((local_3c[0] == 0x54ec) || (local_3c[0] == 0x54ef)) || (iVar1 == 0)) {
      *(int *)(lVar2 + 0x80c) = iVar1;
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x3b0),
                     "%s: Can not perform operation cmd: 0x%x ret: %d\n","hs_uart_operation_store",
                     local_3c[0],iVar1);
      __ftrace_dbg(*(undefined8 *)(lVar2 + 0x150),
                   "%s: Can not perform operation cmd: 0x%x ret: %d\n","hs_uart_operation_store",
                   local_3c[0],iVar1);
      param_4 = 0xffffffffffffffea;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x3b0),"%s: Invalid input\n","hs_uart_operation_store");
    __ftrace_dbg(*(undefined8 *)(lVar2 + 0x150),"%s: Invalid input\n","hs_uart_operation_store");
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hs_uart_version_show @ 0010db5c size=148
// signature: undefined hs_uart_version_show(void)
// callers: []
//------------------------------------------------------------

long hs_uart_version_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  ipc_log_string(*(undefined8 *)(lVar2 + 0x3b0),"%s: Version: %s\n","hs_uart_version_show",
                 &DAT_0010f6d8);
  __ftrace_dbg(*(undefined8 *)(lVar2 + 0x150),"%s: Version: %s\n","hs_uart_version_show",
               &DAT_0010f6d8);
  iVar1 = scnprintf(param_3,0x1000,&DAT_00111190,&DAT_0010f6d8);
  return (long)iVar1;
}



//------------------------------------------------------------
// one_wire_uart_error_show @ 0010dbf4 size=72
// signature: undefined one_wire_uart_error_show(void)
// callers: []
//------------------------------------------------------------

long one_wire_uart_error_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = scnprintf(param_3,4,&DAT_0010ff05,*(undefined4 *)(lVar2 + 0x8b8));
  *(undefined4 *)(lVar2 + 0x8b8) = 0;
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_geni_serial_sys_suspend @ 0010dc40 size=688
// signature: undefined msm_geni_serial_sys_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_geni_serial_sys_suspend(long param_1)

{
  char cVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar4 = *(long *)(lVar3 + 0x3b8);
  if (lVar4 == 0) {
    uVar2 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar3 + 0x3fc);
  }
  else if (*(int *)(lVar3 + 900) == 0) {
    uVar2 = 0;
    cVar1 = *(char *)(lVar3 + 0x3fc);
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_sys_suspend",uVar2,
                   uVar2 / 1000);
    cVar1 = *(char *)(lVar3 + 0x3fc);
  }
  if (cVar1 == '\0') {
    if ((*(long *)(lVar3 + 0x100) == 0) ||
       (*(int *)(lVar3 + 0x134) != (int)*(short *)(*(long *)(lVar3 + 0x100) + 0x4a))) {
      if (*(char *)(lVar3 + 0x558) == '\0') {
        lVar4 = *(long *)(lVar3 + 200) + 0x120;
        mutex_lock(lVar4);
        if (*(int *)(param_1 + 0x20c) != 2) {
          _dev_err(param_1,"%s:Active userspace vote; ioctl_cnt %d\n","msm_geni_serial_sys_suspend",
                   *(undefined4 *)(lVar3 + 0x3dc));
          ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s:Active userspace vote; ioctl_cnt %d\n",
                         "msm_geni_serial_sys_suspend",*(undefined4 *)(lVar3 + 0x3dc));
          __ftrace_dbg(param_1,"%s:Active userspace vote; ioctl_cnt %d\n",
                       "msm_geni_serial_sys_suspend",*(undefined4 *)(lVar3 + 0x3dc));
          mutex_unlock(lVar4);
          return 0xfffffff0;
        }
        ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s end %d\n","msm_geni_serial_sys_suspend",1)
        ;
        __ftrace_dbg(param_1,"%s end %d\n","msm_geni_serial_sys_suspend",1);
        mutex_unlock(lVar4);
        lVar4 = *(long *)(lVar3 + 0x3b8);
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s start %d\n","msm_geni_serial_sys_suspend",
                       1);
        __ftrace_dbg(param_1,"%s start %d\n","msm_geni_serial_sys_suspend",1);
        uart_suspend_port(*(undefined8 *)(lVar3 + 0x1f8),lVar3);
        ipc_log_string(*(undefined8 *)(lVar3 + 0x3a8),"%s end %d\n","msm_geni_serial_sys_suspend",1)
        ;
        __ftrace_dbg(param_1,"%s end %d\n","msm_geni_serial_sys_suspend",1);
        lVar4 = *(long *)(lVar3 + 0x3b8);
      }
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x3c8),"%s start %d\n","msm_geni_serial_sys_suspend",1)
      ;
      uart_suspend_port(*(undefined8 *)(lVar3 + 0x1f8),lVar3);
      ipc_log_string(*(undefined8 *)(lVar3 + 0x3c8),"%s end %d\n","msm_geni_serial_sys_suspend",1);
      lVar4 = *(long *)(lVar3 + 0x3b8);
    }
    if (lVar4 != 0) {
      if (uVar2 == 0) {
        return 0;
      }
      if (*(int *)(lVar3 + 900) == 0) {
        return 0;
      }
      lVar3 = sched_clock(0);
      ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_sys_suspend",
                     lVar3 - uVar2,(lVar3 - uVar2) / 1000);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_geni_serial_sys_resume @ 0010def4 size=604
// signature: undefined msm_geni_serial_sys_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_geni_serial_sys_resume(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar3 = *(long *)(lVar2 + 0x3b8);
  if (lVar3 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar2 + 900) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar3,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_sys_resume",uVar1,
                   uVar1 / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar2 + 0x3a8),"%s: System resume Start %d\n",
                 "msm_geni_serial_sys_resume",1);
  __ftrace_dbg(param_1,"%s: System resume Start %d\n","msm_geni_serial_sys_resume",1);
  if (_pm_suspend_target_state == 3) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x3a8),"deepsleep: %s\n","msm_geni_serial_sys_resume");
    __ftrace_dbg(param_1,"deepsleep: %s\n","msm_geni_serial_sys_resume");
    if ((*(long *)(lVar2 + 0x100) == 0) ||
       (*(int *)(lVar2 + 0x134) != (int)*(short *)(*(long *)(lVar2 + 0x100) + 0x4a))) {
      *(undefined1 *)(lVar2 + 0x620) = 1;
    }
    lVar3 = *(long *)(lVar2 + 0x3b8);
    if (((lVar3 != 0) && (uVar1 != 0)) && (*(int *)(lVar2 + 900) != 0)) {
      lVar2 = sched_clock();
      ipc_log_string(lVar3,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_sys_resume",
                     lVar2 - uVar1,(lVar2 - uVar1) / 1000);
    }
    msm_geni_serial_sys_hib_resume(param_1);
  }
  else if (*(char *)(lVar2 + 0x3fc) == '\0') {
    if (((((*(long *)(lVar2 + 0x100) != 0) &&
          (*(int *)(lVar2 + 0x134) == (int)*(short *)(*(long *)(lVar2 + 0x100) + 0x4a))) &&
         (console_suspend_enabled != '\0')) && (*(char *)(lVar2 + 0x167) != '\0')) ||
       (*(char *)(lVar2 + 0x558) != '\0')) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x3c8),"%s start %d\n","msm_geni_serial_sys_resume",1);
      uart_resume_port(*(undefined8 *)(lVar2 + 0x1f8),lVar2);
      ipc_log_string(*(undefined8 *)(lVar2 + 0x3c8),"%s end %d","msm_geni_serial_sys_resume",1);
    }
    lVar3 = *(long *)(lVar2 + 0x3b8);
    if (((lVar3 != 0) && (uVar1 != 0)) && (*(int *)(lVar2 + 900) != 0)) {
      lVar2 = sched_clock();
      ipc_log_string(lVar3,"%s:took %llu nsec(%llu usec)\n","msm_geni_serial_sys_resume",
                     lVar2 - uVar1,(lVar2 - uVar1) / 1000);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_geni_serial_sys_hib_resume @ 0010e154 size=180
// signature: undefined msm_geni_serial_sys_hib_resume(void)
// callers: [msm_geni_serial_sys_resume]
//------------------------------------------------------------

undefined8 msm_geni_serial_sys_hib_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((*(long *)(lVar1 + 0x100) == 0) ||
     (*(int *)(lVar1 + 0x134) != (int)*(short *)(*(long *)(lVar1 + 0x100) + 0x4a))) {
    *(undefined1 *)(lVar1 + 0x248) = 0;
    if (*(char *)(lVar1 + 0x558) != '\0') {
      uart_resume_port(*(undefined8 *)(lVar1 + 0x1f8),lVar1);
    }
  }
  else {
    uart_resume_port(*(undefined8 *)(lVar1 + 0x1f8),lVar1);
    msm_geni_serial_port_setup(lVar1);
  }
  ipc_log_string(*(undefined8 *)(lVar1 + 0x3a8),"%s: End %d\n","msm_geni_serial_sys_hib_resume",1);
  __ftrace_dbg(param_1,"%s: End %d\n","msm_geni_serial_sys_hib_resume",1);
  return 0;
}



//------------------------------------------------------------
// msm_geni_serial_runtime_suspend @ 0010e20c size=1464
// signature: undefined msm_geni_serial_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

int msm_geni_serial_runtime_suspend(long param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  undefined4 uVar7;
  long lVar8;
  
  lVar6 = *(long *)(param_1 + 0x98);
  uVar7 = *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x40);
  mutex_lock(lVar6 + 0x888);
  ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: Start geni_status : 0x%x\n",
                 "msm_geni_serial_runtime_suspend",uVar7);
  __ftrace_dbg(param_1,"%s: Start geni_status : 0x%x\n","msm_geni_serial_runtime_suspend",uVar7);
  lVar8 = *(long *)(lVar6 + 0x3b8);
  if (lVar8 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar6 + 0x38c);
  }
  else if (*(int *)(lVar6 + 900) == 0) {
    uVar4 = 0;
    cVar1 = *(char *)(lVar6 + 0x38c);
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar8,"%s:start at %llu nsec(%llu usec)\n","msm_geni_serial_runtime_suspend",
                   uVar4,uVar4 / 1000);
    cVar1 = *(char *)(lVar6 + 0x38c);
  }
  if ((cVar1 != '\0') && (*(int *)(lVar6 + 0x388) != 0)) {
    msm_geni_serial_set_manual_flow(0,lVar6);
  }
  if ((*(int *)(lVar6 + 0x808) == 2) && (iVar2 = wait_for_transfers_inflight(lVar6), iVar2 != 0)) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: wait_for_transfer_inflight return ret:%d\n",
                   "msm_geni_serial_runtime_suspend",iVar2);
    __ftrace_dbg(param_1,"%s: wait_for_transfer_inflight return ret:%d\n",
                 "msm_geni_serial_runtime_suspend",iVar2);
    if ((*(char *)(lVar6 + 0x38c) != '\0') && (*(int *)(lVar6 + 0x388) != 0)) {
      *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac) = 0x80000001;
      DataSynchronizationBarrier(3,3,0);
      uVar7 = *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac);
LAB_0010e3fc:
      ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s(): rfr = 0x%x\n","msm_geni_serial_allow_rx",
                     uVar7);
      __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s(): rfr = 0x%x\n","msm_geni_serial_allow_rx",
                   uVar7);
      msm_geni_serial_set_manual_flow(1,lVar6);
      iVar2 = -0x10;
      goto LAB_0010e5b4;
    }
  }
  else {
    iVar2 = stop_rx_sequencer(lVar6);
    if (iVar2 == 0) {
      if ((*(uint *)(*(long *)(lVar6 + 0x10) + 0x40) & 1) != 0) {
        stop_tx_sequencer(lVar6);
      }
      disable_irq(*(undefined4 *)(lVar6 + 0xa0));
      if (((*(char *)(lVar6 + 0x38c) != '\0') && (*(int *)(lVar6 + 0x388) != 0)) &&
         (*(int *)(lVar6 + 0x808) == 2)) {
        *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac) = 0x80000001;
        DataSynchronizationBarrier(3,3,0);
        uVar7 = *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac);
        ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s(): rfr = 0x%x\n",
                       "msm_geni_serial_allow_rx",uVar7);
        __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s(): rfr = 0x%x\n","msm_geni_serial_allow_rx",
                     uVar7);
        msm_geni_serial_set_manual_flow(1,lVar6);
      }
      iVar2 = 0;
      do {
        if (*(int *)(lVar6 + 0x554) == 0) {
          if (iVar2 != 0) {
            ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: count=%d\n",
                           "msm_geni_serial_runtime_suspend",iVar2);
            __ftrace_dbg(param_1,"%s: count=%d\n","msm_geni_serial_runtime_suspend",iVar2);
          }
          ipc_log_string(*(undefined8 *)(lVar6 + 0x3b0),"%s: enable:%d ser_clk_cfg:0x%x\n",
                         "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(lVar6 + 0x458));
          __ftrace_dbg(*(undefined8 *)(lVar6 + 0x150),"%s: enable:%d ser_clk_cfg:0x%x\n",
                       "msm_geni_enable_disable_se_clk",0,*(undefined8 *)(lVar6 + 0x458));
          *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x48) = 1;
          *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x4c) = 1;
          iVar2 = msm_geni_serial_resources_off
                            (*(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x48),lVar6);
          if (iVar2 == 0) {
            if (((*(int *)(lVar6 + 0x808) == 2) && (0 < *(int *)(lVar6 + 0x388))) &&
               (*(long *)(*(long *)(lVar6 + 200) + 0xa8) != 0)) {
              *(undefined4 *)(lVar6 + 0x55c) = 0;
              enable_irq();
              *(undefined1 *)(lVar6 + 0x402) = 1;
              iVar3 = irq_set_irq_wake(*(undefined4 *)(lVar6 + 0x388),1);
              iVar2 = 0;
              if (iVar3 != 0) {
                _dev_err(param_1,"%s:Failed to set IRQ wake:%d\n","msm_geni_serial_runtime_suspend",
                         iVar3);
                iVar2 = iVar3;
              }
            }
            else {
              iVar2 = 0;
            }
            lVar8 = *(long *)(lVar6 + 0x3b8);
            if (((lVar8 != 0) && (uVar4 != 0)) && (*(int *)(lVar6 + 900) != 0)) {
              lVar5 = sched_clock();
              ipc_log_string(lVar8,"%s:took %llu nsec(%llu usec)\n",
                             "msm_geni_serial_runtime_suspend",lVar5 - uVar4,(lVar5 - uVar4) / 1000)
              ;
            }
            ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: End %d\n",
                           "msm_geni_serial_runtime_suspend",iVar2);
            __ftrace_dbg(param_1,"%s: End %d\n","msm_geni_serial_runtime_suspend",iVar2);
            __pm_relax(*(undefined8 *)(lVar6 + 0x390));
          }
          else {
            _dev_err(param_1,"%s: Error ret %d\n","msm_geni_serial_runtime_suspend",iVar2);
            msm_geni_update_uart_error_code(lVar6,6);
          }
          goto LAB_0010e5b4;
        }
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        __const_udelay(0x418958);
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0xb);
      ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: return, stop_rx_seq busy\n",
                     "msm_geni_serial_runtime_suspend");
      __ftrace_dbg(param_1,"%s: return, stop_rx_seq busy\n","msm_geni_serial_runtime_suspend");
      enable_irq(*(undefined4 *)(lVar6 + 0xa0));
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x3a8),"%s: stop rx failed %d\n",
                     "msm_geni_serial_runtime_suspend",iVar2);
      __ftrace_dbg(param_1,"%s: stop rx failed %d\n","msm_geni_serial_runtime_suspend",iVar2);
      if ((*(char *)(lVar6 + 0x38c) != '\0') && (*(int *)(lVar6 + 0x388) != 0)) {
        *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac) = 0x80000001;
        DataSynchronizationBarrier(3,3,0);
        uVar7 = *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x2ac);
        goto LAB_0010e3fc;
      }
    }
  }
  iVar2 = -0x10;
LAB_0010e5b4:
  mutex_unlock(lVar6 + 0x888);
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 0010eb60 size=196
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  
  lVar2 = 0;
  puVar3 = &DAT_00112184;
  do {
    *(undefined1 *)((long)puVar3 + -0x7a) = 2;
    *puVar3 = (int)lVar2;
    lVar2 = lVar2 + 1;
    *(undefined ***)(puVar3 + -3) = &msm_geni_serial_pops;
    *(undefined8 *)(puVar3 + -0xb) = 0x10000000;
    puVar3 = puVar3 + 0x232;
  } while (lVar2 != 6);
  msm_geni_console_port[0xba] = 2;
  msm_geni_console_port._296_8_ = &msm_geni_console_pops;
  msm_geni_console_port._264_8_ = 0x10000000;
  msm_geni_console_port._308_4_ = 0;
  iVar1 = uart_register_driver(&msm_geni_serial_hs_driver);
  if (iVar1 == 0) {
    iVar1 = __platform_driver_register(&msm_geni_serial_platform_driver,&__this_module);
    if (iVar1 != 0) {
      uart_unregister_driver(&msm_geni_serial_hs_driver);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010ec28 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_geni_serial_platform_driver);
  uart_unregister_driver(&msm_geni_serial_hs_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 00119000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_serial_info, perf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00119008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00119010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_serial_info, perf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 00119018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [trace_event_raw_event_serial_info, perf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00119020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00119028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00119030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [geni_wait_for_cmd_done, msm_geni_serial_isr, handle_rx_hs, capture_kpi_store, msm_geni_serial_config_baud_rate, msm_geni_uart_gsi_rx_cb, handle_rx_dma_xfer, msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_xfer_tx, trace_event_raw_event_serial_info, msm_geni_serial_debug_init, hs_uart_operation_store, msm_geni_serial_port_setup, __ftrace_dbg, msm_geni_serial_probe, perf_trace_serial_info, stop_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00119038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00119040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00119048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00119050 size=1
// signature: undefined ipc_log_string(void)
// callers: [msm_geni_serial_ssr_up, msm_geni_serial_set_manual_flow, msm_geni_serial_flush, geni_se_dump_dbg_regs, msm_geni_serial_enable_interrupts, msm_geni_serial_handle_dma_tx, msm_geni_uart_gsi_rx_cb, msm_geni_serial_break_ctl, hs_uart_operation_store, msm_geni_serial_sys_hib_resume, xfer_mode_store, msm_geni_serial_get_mctrl, wait_for_transfers_inflight, msm_geni_update_uart_error_code, msm_geni_serial_config_baud_rate, msm_geni_serial_sys_suspend, msm_geni_serial_ssr_down, msm_geni_serial_cons_pm, msm_geni_serial_stop_rx, msm_geni_check_stop_engine, msm_geni_serial_resources_off, msm_geni_serial_set_mctrl, msm_geni_serial_probe, msm_geni_serial_start_tx, msm_serial_try_disable_interrupts, geni_wait_for_cmd_done, handle_rx_hs, msm_geni_serial_handle_isr, msm_geni_serial_set_termios, msm_geni_serial_sys_resume, msm_geni_wakeup_isr, msm_geni_serial_resources_on, stop_tx_sequencer, msm_geni_allocate_chan, start_rx_sequencer, hs_uart_version_show, msm_geni_serial_startup, msm_geni_serial_stop_tx, msm_geni_uart_gsi_cancel_tx, msm_geni_uart_gsi_tx_cb, handle_rx_dma_xfer, msm_geni_serial_hs_pm, msm_geni_serial_power_on, msm_geni_serial_ioctl, msm_geni_serial_runtime_suspend, msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_xfer_tx, msm_geni_serial_shutdown, msm_geni_serial_port_setup, msm_geni_wakeup_work, msm_geni_uart_gsi_cancel_rx, msm_geni_uart_ev_cb, msm_geni_serial_runtime_resume, stop_rx_sequencer, msm_geni_serial_allow_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00119070 size=1
// signature: undefined sched_clock(void)
// callers: [msm_geni_serial_startup, msm_geni_serial_config_baud_rate, msm_geni_serial_handle_isr, msm_geni_serial_sys_suspend, msm_geni_serial_set_termios, msm_geni_serial_handle_dma_tx, handle_rx_dma_xfer, msm_geni_serial_sys_resume, msm_geni_serial_ioctl, msm_geni_serial_runtime_suspend, msm_geni_serial_prep_dma_tx, msm_geni_serial_shutdown, msm_geni_serial_port_setup, msm_geni_serial_start_tx, msm_geni_wakeup_isr, msm_geni_serial_resources_on, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00119078 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [msm_geni_serial_shutdown, msm_geni_serial_resources_off, msm_geni_serial_resources_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_enable @ 00119080 size=1
// signature: undefined geni_icc_enable(void)
// callers: [msm_geni_serial_probe, msm_geni_serial_resources_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_set_bw @ 00119088 size=1
// signature: undefined geni_icc_set_bw(void)
// callers: [msm_geni_serial_probe, msm_geni_serial_resources_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00119090 size=1
// signature: undefined __const_udelay(void)
// callers: [geni_wait_for_cmd_done, msm_geni_serial_set_manual_flow, msm_geni_serial_runtime_suspend, msm_geni_serial_port_setup, msm_geni_serial_resources_on, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00119098 size=1
// signature: undefined clk_prepare(void)
// callers: [geni_se_common_clks_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001190a0 size=1
// signature: undefined clk_enable(void)
// callers: [geni_se_common_clks_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001190a8 size=1
// signature: undefined clk_unprepare(void)
// callers: [geni_se_common_clks_on, msm_geni_serial_resources_off, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001190b0 size=1
// signature: undefined clk_disable(void)
// callers: [geni_se_common_clks_on, msm_geni_serial_resources_off, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_disable @ 001190b8 size=1
// signature: undefined geni_icc_disable(void)
// callers: [msm_geni_serial_resources_off, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_register_driver @ 001190c0 size=1
// signature: undefined uart_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001190c8 size=1
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
// uart_unregister_driver @ 001190d0 size=1
// signature: undefined uart_unregister_driver(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_unregister_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 001190d8 size=1
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
// trace_raw_output_prep @ 001190e0 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 001190e8 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 001190f0 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_serial_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 001190f8 size=1
// signature: undefined mutex_trylock(void)
// callers: [msm_geni_serial_power_on, msm_geni_serial_get_mctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00119100 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_geni_serial_ssr_up, msm_geni_serial_power_on, msm_geni_serial_runtime_suspend, msm_geni_serial_get_mctrl, msm_geni_serial_sys_suspend, msm_geni_serial_set_termios, msm_geni_serial_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00119108 size=1
// signature: undefined _dev_err(void)
// callers: [msm_geni_serial_flush, handle_rx_hs, msm_geni_serial_startup, msm_geni_serial_stop_tx, capture_kpi_store, msm_geni_serial_config_baud_rate, msm_geni_serial_sys_suspend, loopback_store, msm_geni_serial_set_termios, msm_geni_uart_gsi_rx_cb, msm_geni_serial_ioctl, msm_geni_serial_runtime_suspend, msm_geni_uart_gsi_xfer_tx, msm_geni_serial_debug_init, msm_geni_serial_shutdown, xfer_mode_store, msm_geni_serial_probe, msm_geni_serial_runtime_resume, msm_geni_allocate_chan, start_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00119110 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [msm_geni_serial_power_on, msm_geni_serial_start_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00119118 size=1
// signature: undefined queue_work_on(void)
// callers: [msm_geni_uart_gsi_tx_cb, msm_geni_serial_start_tx, stop_tx_sequencer, stop_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00119120 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [msm_geni_serial_ioctl, msm_geni_serial_startup, xfer_mode_store, msm_geni_wakeup_work, msm_geni_uart_gsi_tx_cb, msm_geni_serial_start_tx, msm_geni_serial_set_termios, stop_tx_sequencer, msm_geni_serial_handle_dma_tx, msm_geni_serial_runtime_resume, stop_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 00119128 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [msm_geni_serial_ioctl, msm_geni_serial_startup, msm_geni_serial_shutdown, xfer_mode_store, msm_geni_wakeup_work, msm_geni_uart_gsi_tx_cb, msm_geni_serial_start_tx, msm_geni_serial_set_termios, stop_tx_sequencer, msm_geni_serial_handle_dma_tx, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00119130 size=1
// signature: undefined complete(void)
// callers: [msm_geni_serial_ioctl, msm_geni_serial_stop_rx, msm_geni_uart_gsi_cancel_rx, msm_geni_uart_gsi_tx_cb, msm_geni_serial_handle_isr, stop_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_get_qup_hw_version @ 00119138 size=1
// signature: undefined geni_se_get_qup_hw_version(void)
// callers: [msm_geni_serial_startup, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_get_qup_hw_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00119140 size=1
// signature: undefined enable_irq(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_startup, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// console_stop @ 00119148 size=1
// signature: undefined console_stop(void)
// callers: [msm_geni_serial_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void console_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00119150 size=1
// signature: undefined disable_irq(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_shutdown, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00119158 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [geni_wait_for_cmd_done, msm_geni_uart_gsi_xfer_tx, msm_geni_serial_shutdown, msm_geni_wakeup_work, msm_geni_serial_set_termios, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_release_channel @ 00119160 size=1
// signature: undefined dma_release_channel(void)
// callers: [msm_geni_serial_shutdown, msm_geni_allocate_chan, start_rx_sequencer, msm_geni_deallocate_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_release_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00119168 size=1
// signature: undefined dma_free_attrs(void)
// callers: [msm_geni_serial_shutdown, msm_geni_serial_remove, start_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 00119170 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [msm_geni_uart_gsi_xfer_tx, msm_geni_serial_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00119178 size=1
// signature: undefined usleep_range_state(void)
// callers: [wait_for_transfers_inflight, msm_geni_serial_shutdown, msm_geni_serial_port_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00119180 size=1
// signature: undefined __flush_workqueue(void)
// callers: [msm_geni_serial_set_termios, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00119188 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_geni_serial_ssr_up, msm_geni_serial_power_on, msm_geni_serial_runtime_suspend, msm_geni_serial_sys_suspend, msm_geni_serial_set_termios, msm_geni_serial_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_get_baud_rate @ 00119190 size=1
// signature: undefined uart_get_baud_rate(void)
// callers: [msm_geni_serial_set_termios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_get_baud_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00119198 size=1
// signature: undefined _dev_warn(void)
// callers: [msm_geni_serial_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_unprep @ 001191a0 size=1
// signature: undefined geni_se_tx_dma_unprep(void)
// callers: [msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_tx_cb, stop_tx_sequencer, msm_geni_serial_handle_dma_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_trylock @ 001191b0 size=1
// signature: undefined _raw_spin_trylock(void)
// callers: [msm_serial_try_disable_interrupts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001191b8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [msm_geni_serial_isr, xfer_mode_store, msm_geni_serial_handle_isr, msm_geni_wakeup_isr, msm_serial_try_disable_interrupts, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tty_insert_flip_char @ 001191c0 size=1
// signature: undefined __tty_insert_flip_char(void)
// callers: [msm_geni_serial_handle_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tty_insert_flip_char(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_write_wakeup @ 001191c8 size=1
// signature: undefined uart_write_wakeup(void)
// callers: [msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_xfer_tx, msm_geni_uart_gsi_tx_cb, msm_geni_serial_handle_isr, msm_geni_serial_handle_dma_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_write_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tty_flip_buffer_push @ 001191d0 size=1
// signature: undefined tty_flip_buffer_push(void)
// callers: [handle_rx_hs, msm_geni_serial_handle_isr, msm_geni_uart_gsi_rx_cb, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tty_flip_buffer_push(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001191d8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [msm_geni_serial_isr, xfer_mode_store, msm_geni_serial_handle_isr, msm_geni_wakeup_isr, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tty_insert_flip_string_fixed_flag @ 001191e0 size=1
// signature: undefined tty_insert_flip_string_fixed_flag(void)
// callers: [handle_rx_hs, msm_geni_uart_gsi_rx_cb, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tty_insert_flip_string_fixed_flag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hex_dump_to_buffer @ 001191e8 size=1
// signature: undefined hex_dump_to_buffer(void)
// callers: [handle_rx_hs, msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_xfer_tx, msm_geni_uart_gsi_rx_cb, handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hex_dump_to_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001191f0 size=1
// signature: undefined scnprintf(void)
// callers: [handle_rx_hs, hs_uart_version_show, capture_kpi_store, capture_kpi_show, loopback_show, msm_geni_uart_gsi_rx_cb, handle_rx_dma_xfer, ver_info_show, msm_geni_serial_prep_dma_tx, msm_geni_uart_gsi_xfer_tx, one_wire_uart_error_show, msm_geni_serial_debug_init, msm_geni_serial_probe, hs_uart_operation_show, xfer_mode_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001191f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [handle_rx_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_prep @ 00119200 size=1
// signature: undefined geni_se_tx_dma_prep(void)
// callers: [msm_geni_serial_prep_dma_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 00119208 size=1
// signature: undefined __udelay(void)
// callers: [stop_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00119210 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [msm_geni_serial_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00119220 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [msm_geni_serial_power_on, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00119228 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [msm_geni_serial_power_on, msm_geni_serial_probe, msm_geni_serial_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_config_packing @ 00119230 size=1
// signature: undefined geni_se_config_packing(void)
// callers: [msm_geni_serial_port_setup, msm_geni_serial_config_baud_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_config_packing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00119238 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [msm_geni_serial_port_setup, start_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_init @ 00119240 size=1
// signature: undefined geni_se_init(void)
// callers: [msm_geni_serial_port_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_select_mode @ 00119248 size=1
// signature: undefined geni_se_select_mode(void)
// callers: [xfer_mode_store, msm_geni_serial_port_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_select_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 00119250 size=1
// signature: undefined __pm_relax(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 00119258 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00119260 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [msm_geni_serial_runtime_suspend, msm_geni_serial_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 00119268 size=1
// signature: undefined sg_init_table(void)
// callers: [msm_geni_uart_gsi_xfer_tx, msm_geni_uart_gsi_rx_cb, start_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00119270 size=1
// signature: undefined _printk(void)
// callers: [msm_geni_uart_gsi_xfer_tx, msm_geni_uart_gsi_rx_cb, start_rx_sequencer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_request_chan @ 00119278 size=1
// signature: undefined dma_request_chan(void)
// callers: [msm_geni_allocate_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_request_chan(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_clk_freq_match @ 00119280 size=1
// signature: undefined geni_se_clk_freq_match(void)
// callers: [msm_geni_serial_config_baud_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_clk_freq_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00119288 size=1
// signature: undefined clk_set_rate(void)
// callers: [msm_geni_serial_config_baud_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_update_timeout @ 00119290 size=1
// signature: undefined uart_update_timeout(void)
// callers: [msm_geni_serial_config_baud_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_update_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 00119298 size=1
// signature: undefined of_match_device(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_alias_get_id @ 001192a0 size=1
// signature: undefined of_alias_get_id(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_alias_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001192a8 size=1
// signature: undefined of_find_property(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001192b0 size=1
// signature: undefined devm_clk_get(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 001192b8 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_get @ 001192c0 size=1
// signature: undefined geni_icc_get(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_pm_select_sleep_state @ 001192c8 size=1
// signature: undefined pinctrl_pm_select_sleep_state(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_pm_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001192d0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001192d8 size=1
// signature: undefined _dev_info(void)
// callers: [msm_geni_serial_debug_init, capture_kpi_store, msm_geni_serial_remove, msm_geni_serial_driver_shutdown, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001192e0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001192e8 size=1
// signature: undefined devm_ioremap(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001192f0 size=1
// signature: undefined platform_get_irq(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 001192f8 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00119300 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 00119308 size=1
// signature: undefined devm_kasprintf(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 00119310 size=1
// signature: undefined irq_modify_status(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00119318 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00119320 size=1
// signature: undefined alloc_workqueue(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00119330 size=1
// signature: undefined init_timer_key(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 00119338 size=1
// signature: undefined wakeup_source_register(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00119340 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00119348 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00119350 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 00119358 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_forbid @ 00119360 size=1
// signature: undefined pm_runtime_forbid(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_forbid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00119368 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00119370 size=1
// signature: undefined device_create_file(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_add_one_port @ 00119378 size=1
// signature: undefined uart_add_one_port(void)
// callers: [msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_add_one_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00119380 size=1
// signature: undefined destroy_workqueue(void)
// callers: [msm_geni_serial_remove, msm_geni_serial_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 00119388 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [msm_geni_serial_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_allow @ 00119390 size=1
// signature: undefined pm_runtime_allow(void)
// callers: [msm_geni_serial_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_allow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_remove_one_port @ 00119398 size=1
// signature: undefined uart_remove_one_port(void)
// callers: [msm_geni_serial_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_remove_one_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 001193a0 size=1
// signature: undefined device_remove_file(void)
// callers: [msm_geni_serial_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001193a8 size=1
// signature: undefined debugfs_remove(void)
// callers: [msm_geni_serial_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001193b0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [msm_geni_serial_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001193b8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [msm_geni_serial_debug_init, capture_kpi_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001193c0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [msm_geni_wakeup_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_force_suspend @ 001193c8 size=1
// signature: undefined pm_runtime_force_suspend(void)
// callers: [msm_geni_serial_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_force_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 001193d0 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 001193d8 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 001193e0 size=1
// signature: undefined dev_driver_string(void)
// callers: [msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001193e8 size=1
// signature: undefined __warn_printk(void)
// callers: [msm_geni_uart_gsi_xfer_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001193f0 size=1
// signature: undefined kstrtoint(void)
// callers: [capture_kpi_store, loopback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001193f8 size=1
// signature: undefined strnstr(void)
// callers: [xfer_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 00119400 size=1
// signature: undefined kstrtou16(void)
// callers: [hs_uart_operation_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_suspend_port @ 00119408 size=1
// signature: undefined uart_suspend_port(void)
// callers: [msm_geni_serial_sys_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_suspend_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_resume_port @ 00119420 size=1
// signature: undefined uart_resume_port(void)
// callers: [msm_geni_serial_sys_resume, msm_geni_serial_sys_hib_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_resume_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



