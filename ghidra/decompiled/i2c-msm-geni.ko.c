// Decompiled by Ghidra 12.2
// Program: i2c-msm-geni.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_i2c_log_info @ 00100b64 size=116
// signature: undefined __traceiter_i2c_log_info(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_i2c_log_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001094b8;
  plVar2 = DAT_001094b8;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100bb4);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_i2c_log_info @ 00100bdc size=308
// signature: undefined trace_event_raw_event_i2c_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_i2c_log_info(long param_1,char *param_2,undefined8 *param_3)

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
    lVar5 = trace_event_buffer_reserve(&local_78,param_1,(long)(iVar3 + 0x101) + 0x10);
    if (lVar5 != 0) {
      *(int *)(lVar5 + 8) = iVar3 * 0x10000 + 0x10010;
      *(uint *)(lVar5 + 0xc) = iVar3 + 0x11U | 0x1000000;
      strcpy((char *)(lVar5 + 0x10),__s);
      puVar1 = (undefined8 *)param_3[1];
      local_88 = puVar1[2];
      uStack_80 = puVar1[3];
      local_98 = *puVar1;
      uStack_90 = puVar1[1];
      iVar3 = vsnprintf((char *)(lVar5 + (ulong)(iVar3 + 0x11U & 0xffff)),0x100,(char *)*param_3,
                        &local_98);
      if (0xff < iVar3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100d0c);
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
// perf_trace_i2c_log_info @ 00100d18 size=384
// signature: undefined perf_trace_i2c_log_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_i2c_log_info(long param_1,char *param_2,undefined8 *param_3)

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
    iVar4 = (iVar6 + 0x11cU & 0xfffffff8) - 4;
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
      *(uint *)(lVar8 + 0xc) = iVar6 + 0x11U | 0x1000000;
      strcpy((char *)(lVar8 + 0x10),__s);
      puVar3 = (undefined8 *)param_3[1];
      local_78 = puVar3[2];
      uStack_70 = puVar3[3];
      local_88 = *puVar3;
      uStack_80 = puVar3[1];
      iVar6 = vsnprintf((char *)(lVar8 + (ulong)(iVar6 + 0x11U & 0xffff)),0x100,(char *)*param_3,
                        &local_88);
      if (0xff < iVar6) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100e94);
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
// __bpf_trace_i2c_log_info @ 00100ea0 size=28
// signature: undefined __bpf_trace_i2c_log_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_i2c_log_info(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// i2c_trace_log @ 00100ec0 size=136
// signature: undefined i2c_trace_log(void)
// callers: [geni_i2c_se_dump_dbg_regs, gi2c_gsi_rx_cb, geni_i2c_prep_desc, ssr_i2c_force_suspend, geni_i2c_bus_recovery, geni_i2c_suspend_late, gi2c_gsi_tx_cb, ssr_i2c_force_resume, geni_i2c_gpi_pause_resume, geni_i2c_irq, geni_i2c_gsi_xfer, geni_i2c_runtime_suspend, gi2c_ev_cb, geni_i2c_resume_early, geni_i2c_stop_on_bus, geni_i2c_prepare, geni_i2c_shutdown, gi2c_gsi_tre_process, geni_i2c_remove, geni_i2c_lock_bus, geni_i2c_stop_with_cancel, geni_i2c_runtime_resume, geni_i2c_hib_resume_noirq, gi2c_gsi_cb_err, geni_i2c_xfer, geni_i2c_gsi_request_channel, geni_i2c_check_addr_data_nack]
//------------------------------------------------------------

void i2c_trace_log(void)

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
// geni_i2c_se_dump_dbg_regs @ 00100fec size=1340
// signature: undefined geni_i2c_se_dump_dbg_regs(void)
// callers: [geni_i2c_irq, geni_i2c_lock_bus, gi2c_gsi_cb_err, gi2c_gsi_rx_cb, geni_i2c_xfer, geni_i2c_gsi_xfer, geni_i2c_stop_on_bus, geni_i2c_bus_recovery, geni_i2c_runtime_suspend, gi2c_ev_cb]
//------------------------------------------------------------

void geni_i2c_se_dump_dbg_regs(long param_1,long param_2,undefined8 param_3)

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
  
  uVar1 = readl_relaxed(param_2 + 0x600);
  uVar2 = readl_relaxed(param_2 + 0x610);
  readl_relaxed(param_2 + 0x630);
  uVar3 = readl_relaxed(param_2 + 0x640);
  uVar4 = readl_relaxed(param_2 + 0x40);
  uVar5 = readl_relaxed(param_2 + 0x908);
  uVar6 = readl_relaxed(param_2 + 0xc40);
  uVar7 = readl_relaxed(param_2 + 0xd40);
  uVar8 = readl_relaxed(param_2 + 0x804);
  uVar9 = readl_relaxed(param_2 + 0x800);
  uVar10 = readl_relaxed(param_2 + 0xe40);
  uVar11 = readl_relaxed(param_2 + 0x604);
  uVar12 = readl_relaxed(param_2 + 0xd3c);
  uVar13 = readl_relaxed(param_2 + 0xd54);
  uVar14 = readl_relaxed(param_2 + 0xc3c);
  uVar15 = readl_relaxed(param_2 + 0xc54);
  uVar16 = readl_relaxed(param_2 + 0x614);
  uVar17 = readl_relaxed(param_2 + 0x644);
  uVar18 = readl_relaxed(param_2 + 0xc48);
  uVar19 = readl_relaxed(param_2 + 0xd48);
  uVar20 = readl_relaxed(param_2 + 0x10);
  uVar21 = readl_relaxed(param_2 + 0x24);
  uVar22 = readl_relaxed(param_2 + 0x60);
  uVar23 = readl_relaxed(param_2 + 100);
  uVar24 = readl_relaxed(param_2 + 0x74);
  uVar25 = readl_relaxed(param_2 + 0x7c);
  uVar26 = readl_relaxed(param_2 + 0x614);
  uVar27 = readl_relaxed(param_2 + 0xc38);
  uVar28 = readl_relaxed(param_2 + 0xc40);
  uVar29 = readl_relaxed(param_2 + 0xd38);
  uVar30 = readl_relaxed(param_2 + 0xd40);
  uVar31 = readl_relaxed(param_2 + 0xe18);
  uVar32 = readl_relaxed(param_2 + 0xe1c);
  uVar33 = readl_relaxed(param_2 + 0xe20);
  uVar34 = readl_relaxed(param_2 + 0xe30);
  uVar35 = readl_relaxed(param_2 + 0xe40);
  ipc_log_string(param_3,"%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                 "geni_i2c_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                  "geni_i2c_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  }
  ipc_log_string(param_3,"dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",
                 uVar7,uVar6,uVar8,uVar9);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",uVar7,
                  uVar6,uVar8,uVar9);
  }
  ipc_log_string(param_3,"se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",
                 uVar10,uVar11,uVar12,uVar13);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",uVar10,
                  uVar11,uVar12,uVar13);
  }
  ipc_log_string(param_3,"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",uVar14,uVar15,uVar3
                );
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",
                  uVar14,uVar15,uVar3);
  }
  ipc_log_string(param_3,
                 "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                 uVar18,uVar19,uVar16,uVar17);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                  uVar18,uVar19,uVar16,uVar17);
  }
  ipc_log_string(param_3,"geni_dma_tx_irq_en:0x%x, geni_dma_rx_irq_en:0x%x, geni_general_cfg:0x%x\n"
                 ,uVar18,uVar19,uVar20);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "geni_dma_tx_irq_en:0x%x, geni_dma_rx_irq_en:0x%x, geni_general_cfg:0x%x\n",uVar18
                  ,uVar19,uVar20);
  }
  ipc_log_string(param_3,
                 "geni_clk_ctrl_ro:0x%x, fifo_if_disable_ro:0x%x, geni_fw_multilock_msa_ro:0x%x\n",
                 uVar22,uVar23,uVar24);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "geni_clk_ctrl_ro:0x%x, fifo_if_disable_ro:0x%x, geni_fw_multilock_msa_ro:0x%x\n",
                  uVar22,uVar23,uVar24);
  }
  ipc_log_string(param_3,
                 "m_irq_en:0x%x, se_dma_tx_attr:0x%x se_dma_tx_irq_stat:0x%x, geni_output_ctrl:0x%x\n"
                 ,uVar26,uVar27,uVar28,uVar21);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "m_irq_en:0x%x, se_dma_tx_attr:0x%x se_dma_tx_irq_stat:0x%x, geni_output_ctrl:0x%x\n"
                  ,uVar26,uVar27,uVar28,uVar21);
  }
  ipc_log_string(param_3,
                 "se_dma_rx_attr:0x%x, se_dma_rx_irq_stat:0x%x se_gsi_event_en:0x%x se_irq_en:0x%x\n"
                 ,uVar29,uVar30,uVar31,uVar32);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "se_dma_rx_attr:0x%x, se_dma_rx_irq_stat:0x%x se_gsi_event_en:0x%x se_irq_en:0x%x\n"
                  ,uVar29,uVar30,uVar31,uVar32);
  }
  ipc_log_string(param_3,
                 "dma_if_en_ro:0x%x, dma_general_cfg:0x%x dma_debug_reg0:0x%x\n, geni_clk_sel:0x%x",
                 uVar33,uVar34,uVar35,uVar25);
  if (*(long *)(param_1 + 8) != 0) {
    i2c_trace_log(*(long *)(param_1 + 8),
                  "dma_if_en_ro:0x%x, dma_general_cfg:0x%x dma_debug_reg0:0x%x\n, geni_clk_sel:0x%x"
                  ,uVar33,uVar34,uVar35,uVar25);
  }
  return;
}



//------------------------------------------------------------
// gi2c_gsi_tx_unmap @ 0010152c size=156
// signature: undefined gi2c_gsi_tx_unmap(void)
// callers: []
//------------------------------------------------------------

void gi2c_gsi_tx_unmap(long param_1,ulong param_2,uint param_3)

{
  ushort uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x528);
  uVar1 = *(ushort *)(lVar4 + (param_2 & 0xffffffff) * 0x10 + 4);
  if (8 < uVar1) {
    if (0x1c0 < param_3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1015c8);
      (*pcVar2)();
    }
    lVar3 = *(long *)(param_1 + (ulong)param_3 * 8 + 0x1458);
    if (lVar3 != -1) {
      dma_unmap_page_attrs(*(undefined8 *)(param_1 + 0x13c8),lVar3,uVar1,1,0);
      lVar4 = *(long *)(param_1 + 0x528);
    }
    i2c_put_dma_safe_msg_buf
              (*(undefined8 *)(param_1 + (ulong)param_3 * 8 + 0x548),
               lVar4 + (param_2 & 0xffffffff) * 0x10,*(int *)(param_1 + 0x18) == 0);
  }
  return;
}



//------------------------------------------------------------
// geni_i2c_get_immediate_dma_data @ 001015cc size=32
// signature: undefined geni_i2c_get_immediate_dma_data(void)
// callers: []
//------------------------------------------------------------

void geni_i2c_get_immediate_dma_data(undefined1 *param_1,uint param_2,undefined1 *param_3)

{
  ulong uVar1;
  
  if (0 < (int)param_2) {
    uVar1 = (ulong)param_2;
    do {
      uVar1 = uVar1 - 1;
      *param_1 = *param_3;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
    } while (uVar1 != 0);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_i2c_log_info @ 001015f0 size=112
// signature: undefined trace_raw_output_i2c_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_i2c_log_info(long param_1,undefined8 param_2,undefined8 param_3)

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
// readl_relaxed @ 00101660 size=124
// signature: undefined readl_relaxed(void)
// callers: [geni_i2c_irq, geni_i2c_se_dump_dbg_regs, geni_i2c_stop_with_cancel, test_bus_enable_per_qupv3, geni_i2c_xfer, geni_i2c_gsi_xfer, geni_i2c_stop_on_bus, geni_i2c_bus_recovery, geni_i2c_prepare, geni_i2c_check_addr_data_nack]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1016a8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// geni_i2c_probe @ 001016e0 size=1272
// signature: undefined geni_i2c_probe(void)
// callers: []
//------------------------------------------------------------

ulong geni_i2c_probe(long param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *pcVar9;
  undefined4 uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  
  lVar12 = param_1 + 0x10;
  plVar5 = (long *)devm_kmalloc(lVar12,0x23d0,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar11 = 0xfffffff4;
  }
  else {
    uVar11 = (ulong)arr_idx;
    if ((int)arr_idx < 0x14) {
      if (0x13 < arr_idx) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101bd8);
        arr_idx = arr_idx + 1;
        (*pcVar2)();
      }
      arr_idx = arr_idx + 1;
      *(long **)(gi2c_dev_dbg + uVar11 * 8) = plVar5;
    }
    *plVar5 = lVar12;
    lVar6 = platform_get_resource(param_1,0x200,0);
    if (lVar6 == 0) {
      uVar11 = 0xffffffea;
    }
    else {
      uVar11 = devm_ioremap_resource(*plVar5,lVar6);
      plVar5[1] = uVar11;
      if (uVar11 < 0xfffffffffffff001) {
        lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,le-vm",0);
        if (lVar6 != 0) {
          *(undefined1 *)((long)plVar5 + 0x2344) = 0;
          *(undefined1 *)(plVar5 + 0x468) = 1;
          _dev_info(lVar12,"LE-VM usecase\n");
        }
        lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,pm-ctrl-client",0);
        if (lVar6 != 0) {
          *(undefined1 *)((long)plVar5 + 0x2342) = 1;
          _dev_info(lVar12,"Client controls the I2C PM\n");
        }
        lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,leica-used-i2c",0);
        if (lVar6 != 0) {
          *(undefined1 *)((long)plVar5 + 0x234a) = 1;
        }
        uVar7 = *(undefined8 *)(param_1 + 0x2f8);
        *(undefined1 *)((long)plVar5 + 0x2351) = 0;
        lVar6 = of_find_property(uVar7,"qcom,i2c-test-dev",0);
        if (lVar6 != 0) {
          *(undefined1 *)((long)plVar5 + 0x2351) = 1;
          _dev_info(lVar12,"%s: This is I2C device under test\n","geni_i2c_probe");
        }
        lVar6 = *(long *)(param_1 + 0x70);
        plVar5[0x26a] = lVar12;
        lVar13 = *(long *)(lVar6 + 0x98);
        plVar5[0x279] = lVar6;
        plVar5[0x269] = plVar5[1];
        plVar5[0x474] = (long)(plVar5 + 0x269);
        plVar5[0x26b] = lVar13;
        plVar5[0x472] = lVar12;
        if (lVar13 == 0) {
          _dev_err(lVar12,"SE Wrapper is NULL, deferring probe\n");
          uVar11 = 0xfffffdfb;
        }
        else {
          puVar1 = (undefined4 *)((long)plVar5 + 0x22b4);
          iVar3 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,clk-freq-out",puVar1,1,0);
          if (iVar3 < 0) {
            uVar10 = 400000;
            *puVar1 = 400000;
          }
          else {
            uVar10 = *puVar1;
          }
          _dev_info(lVar12,"Bus frequency is set to %dHz.\n",uVar10);
          iVar3 = *(int *)((long)plVar5 + 0x22b4);
          *(undefined1 *)((long)plVar5 + 0x2352) = 0;
          if (iVar3 == 100000) {
            uVar10 = 0;
          }
          else if (iVar3 == 1000000) {
            uVar10 = 2;
          }
          else {
            if (iVar3 != 400000) {
              uVar11 = 0xffffffea;
              _dev_err(*plVar5,"Invalid clk frequency %d KHz: %d\n",iVar3,0xffffffea);
              goto LAB_00101788;
            }
            uVar10 = 1;
          }
          uVar7 = *(undefined8 *)(param_1 + 0x2f8);
          *(undefined4 *)((long)plVar5 + 0x13e4) = uVar10;
          lVar6 = of_find_property(uVar7,"qcom,ssr-enable",0);
          *(bool *)(plVar5 + 0x479) = lVar6 != 0;
          if (lVar6 != 0) {
            plVar5[0x477] = (long)ssr_i2c_force_suspend;
            plVar5[0x478] = (long)ssr_i2c_force_resume;
          }
          __mutex_init(plVar5 + 0x46b,"&gi2c->i2c_ssr.ssr_lock",&geni_i2c_probe___key);
          uVar8 = geni_i2c_resources_init(param_1,plVar5);
          uVar11 = uVar8 & 0xffffffff;
          if ((int)uVar8 == 0) {
            lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,shared",0);
            if (lVar6 != 0) {
              *(undefined1 *)((long)plVar5 + 0x232d) = 1;
              _dev_info(lVar12,"Multi-EE usecase\n");
            }
            lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,bus-recovery",0);
            if (lVar6 != 0) {
              *(undefined1 *)(plVar5 + 0x46a) = 1;
            }
            iVar3 = dma_set_mask_and_coherent(lVar12,0xffffffffffffffff);
            if ((iVar3 == 0) || (uVar4 = dma_set_mask_and_coherent(lVar12,0xffffffff), uVar4 == 0))
            {
              lVar6 = dmam_alloc_attrs(*plVar5,0xa0,plVar5 + 0x454,0xcc0,0);
              plVar5[0x452] = lVar6;
              if (lVar6 == 0) {
                pcVar9 = "could not allocate for tx_sg\n";
              }
              else {
                lVar6 = dmam_alloc_attrs(*plVar5,0x20,plVar5 + 0x455,0xcc0,0);
                plVar5[0x453] = lVar6;
                if (lVar6 != 0) {
                  plVar5[6] = (long)&geni_i2c_algo;
                  *(undefined4 *)(plVar5 + 0x9c) = 0;
                  __init_swait_queue_head(plVar5 + 0x9d,"&x->wait",&init_completion___key);
                  *(undefined4 *)(plVar5 + 0xa0) = 0;
                  __init_swait_queue_head(plVar5 + 0xa1,"&x->wait",&init_completion___key);
                  lVar12 = *plVar5;
                  lVar6 = *(long *)(param_1 + 0x2f8);
                  *(long **)(param_1 + 0xa8) = plVar5;
                  plVar5[0x25] = (long)plVar5;
                  plVar5[0x1e] = lVar12;
                  plVar5[0x6f] = lVar6;
                  strscpy((long)plVar5 + 0x42c,"Geni-I2C",9);
                  __pm_runtime_set_status(*plVar5,2);
                  if ((char)plVar5[0x468] == '\0') {
                    pm_runtime_set_autosuspend_delay(*plVar5,0xfa);
                    __pm_runtime_use_autosuspend(*plVar5,1);
                  }
                  pm_runtime_enable(*plVar5);
                  uVar8 = i2c_add_adapter(plVar5 + 4);
                  uVar11 = uVar8 & 0xffffffff;
                  if ((int)uVar8 == 0) {
                    device_create_file(*plVar5,&dev_attr_capture_kpi);
                    *(undefined4 *)((long)plVar5 + 0x234c) = 0;
                    if (*(char *)((long)plVar5 + 0x2351) != '\0') {
                      test_bus_enable_per_qupv3(plVar5[0x279],plVar5[0x27a]);
                    }
                    _dev_info(*plVar5,"I2C probed\n");
                    uVar11 = 0;
                  }
                  else {
                    _dev_err(*plVar5,"Add adapter failed, ret=%d\n",uVar8 & 0xffffffff);
                  }
                  goto LAB_00101788;
                }
                pcVar9 = "could not allocate for rx_sg\n";
              }
              _dev_err(lVar12,pcVar9);
              uVar11 = 0xfffffff4;
            }
            else {
              uVar11 = (ulong)uVar4;
              _dev_err(lVar12,"could not set DMA mask\n");
            }
          }
        }
      }
    }
  }
LAB_00101788:
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// geni_i2c_remove @ 00101bdc size=1048
// signature: undefined geni_i2c_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i2c_remove(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  
  plVar9 = *(long **)(param_1 + 0xa8);
  if (*(int *)((long)plVar9 + 0x234c) == 0) {
    if ((*(int *)(*plVar9 + 0x20c) != 2) && (iVar6 = geni_i2c_runtime_suspend(), iVar6 != 0)) {
      ipc_log_string(plVar9[0x27a],"%s: runtime suspend failed\n","geni_i2c_remove");
      if (*plVar9 == 0) {
        _printk(&DAT_0010b3b1,"geni_i2c_remove");
      }
      else {
        _dev_err(*plVar9,"%s: runtime suspend failed\n","geni_i2c_remove");
      }
      if (*plVar9 != 0) {
        i2c_trace_log(*plVar9,"%s: runtime suspend failed\n","geni_i2c_remove");
      }
    }
    if ((int)plVar9[0x465] == 2) {
      if (plVar9[0x27d] == 0) {
        lVar8 = plVar9[0x27e];
      }
      else {
        ipc_log_string(plVar9[0x27a],"%s: clearing tx dma resource\n","geni_i2c_remove");
        if (*plVar9 == 0) {
          _printk(&DAT_00109b44,"geni_i2c_remove");
        }
        else {
          _dev_err(*plVar9,"%s: clearing tx dma resource\n","geni_i2c_remove");
        }
        if (*plVar9 != 0) {
          i2c_trace_log(*plVar9,"%s: clearing tx dma resource\n","geni_i2c_remove");
        }
        dma_release_channel(plVar9[0x27d]);
        lVar8 = plVar9[0x27e];
      }
      if (lVar8 != 0) {
        ipc_log_string(plVar9[0x27a],"%s: clearing rx dma resource\n","geni_i2c_remove");
        if (*plVar9 == 0) {
          _printk(&DAT_0010a8e9,"geni_i2c_remove");
        }
        else {
          _dev_err(*plVar9,"%s: clearing rx dma resource\n","geni_i2c_remove");
        }
        if (*plVar9 != 0) {
          i2c_trace_log(*plVar9,"%s: clearing rx dma resource\n","geni_i2c_remove");
        }
        dma_release_channel(plVar9[0x27e]);
      }
    }
    piVar1 = (int *)(*plVar9 + 0x1f8);
    iVar6 = *(int *)(*plVar9 + 0x1f8);
    do {
      if (iVar6 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar6) goto LAB_00101c58;
        cVar3 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = iVar6 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00101c58:
      bVar5 = iVar6 != iVar2;
      iVar6 = iVar2;
    } while (bVar5);
    __pm_runtime_set_status(*plVar9,2);
    __pm_runtime_disable(*plVar9,1);
    i2c_del_adapter(plVar9 + 4);
    if (((((((1 < arr_idx) && (gi2c_dev_dbg._8_8_ = 0, arr_idx != 2)) &&
           (gi2c_dev_dbg._16_8_ = 0, arr_idx != 3)) &&
          ((gi2c_dev_dbg._24_8_ = 0, arr_idx != 4 && (gi2c_dev_dbg._32_8_ = 0, arr_idx != 5)))) &&
         (((gi2c_dev_dbg._40_8_ = 0, arr_idx != 6 &&
           ((gi2c_dev_dbg._48_8_ = 0, arr_idx != 7 && (gi2c_dev_dbg._56_8_ = 0, arr_idx != 8)))) &&
          (gi2c_dev_dbg._64_8_ = 0, arr_idx != 9)))) &&
        ((((gi2c_dev_dbg._72_8_ = 0, arr_idx != 10 && (gi2c_dev_dbg._80_8_ = 0, arr_idx != 0xb)) &&
          (gi2c_dev_dbg._88_8_ = 0, arr_idx != 0xc)) &&
         (((gi2c_dev_dbg._96_8_ = 0, arr_idx != 0xd && (gi2c_dev_dbg._104_8_ = 0, arr_idx != 0xe))
          && ((gi2c_dev_dbg._112_8_ = 0, arr_idx != 0xf &&
              ((gi2c_dev_dbg._120_8_ = 0, arr_idx != 0x10 &&
               (gi2c_dev_dbg._128_8_ = 0, arr_idx != 0x11)))))))))) &&
       ((gi2c_dev_dbg._136_8_ = 0, arr_idx != 0x12 &&
        ((gi2c_dev_dbg._144_8_ = 0, arr_idx != 0x13 && (gi2c_dev_dbg._152_8_ = 0, arr_idx != 0x14)))
        ))) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102008);
      (*pcVar4)();
    }
    arr_idx = 0;
    device_remove_file(*plVar9,&dev_attr_capture_kpi);
    if (plVar9[0x27b] != 0) {
      ipc_log_context_destroy();
    }
    uVar7 = 0;
    if (plVar9[0x27a] != 0) {
      ipc_log_context_destroy();
      uVar7 = 0;
    }
  }
  else {
    ipc_log_string(plVar9[0x27a],"%s: Xfer is in progress\n","geni_i2c_remove");
    if (*plVar9 == 0) {
      _printk(&DAT_0010a66b,"geni_i2c_remove");
      lVar8 = *plVar9;
    }
    else {
      _dev_err(*plVar9,"%s: Xfer is in progress\n","geni_i2c_remove");
      lVar8 = *plVar9;
    }
    if (lVar8 == 0) {
      uVar7 = 0xfffffff0;
    }
    else {
      i2c_trace_log(lVar8,"%s: Xfer is in progress\n","geni_i2c_remove");
      uVar7 = 0xfffffff0;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// geni_i2c_shutdown @ 0010200c size=220
// signature: undefined geni_i2c_shutdown(void)
// callers: []
//------------------------------------------------------------

void geni_i2c_shutdown(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0xa8);
  ipc_log_string(plVar5[0x27a],"Enter %s:%d\n","geni_i2c_shutdown",1);
  if (*plVar5 != 0) {
    i2c_trace_log(*plVar5,"Enter %s:%d\n","geni_i2c_shutdown",1);
  }
  if (*(int *)(*(code **)plVar5[8] + -4) != 0x21dd3032) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102088);
    (*pcVar4)();
  }
  (**(code **)plVar5[8])(plVar5 + 4,1);
  puVar1 = (ulong *)(plVar5 + 0x84);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (*(int *)(*(code **)(plVar5[8] + 0x10) + -4) != 0x21dd3032) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1020c4);
    (*pcVar4)();
  }
  (**(code **)(plVar5[8] + 0x10))(plVar5 + 4,1);
  return;
}



//------------------------------------------------------------
// ssr_i2c_force_suspend @ 001020f8 size=268
// signature: undefined ssr_i2c_force_suspend(void)
// callers: []
//------------------------------------------------------------

void ssr_i2c_force_suspend(long param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0x98);
  plVar1 = plVar3 + 0x46b;
  mutex_lock(plVar1);
  *(undefined1 *)(plVar3 + 0x471) = 1;
  if (*(int *)(*plVar3 + 0x20c) != 2) {
    mutex_unlock(plVar1);
    iVar2 = geni_i2c_runtime_suspend(*plVar3);
    mutex_lock(plVar1);
    if (iVar2 == 0) {
      __pm_runtime_disable(*plVar3,1);
      __pm_runtime_set_status(*plVar3,2);
      pm_runtime_enable(*plVar3);
    }
    else {
      ipc_log_string(plVar3[0x27a],"runtime suspend failed\n");
      if (*plVar3 == 0) {
        _printk(&DAT_00109894);
      }
      else {
        _dev_err(*plVar3,"runtime suspend failed\n");
      }
      if (*plVar3 != 0) {
        i2c_trace_log(*plVar3,"runtime suspend failed\n");
      }
    }
  }
  mutex_unlock(plVar1);
  ipc_log_string(plVar3[0x27a],"SSR force suspend done\n");
  if (*plVar3 != 0) {
    i2c_trace_log(*plVar3,"SSR force suspend done\n");
  }
  return;
}



//------------------------------------------------------------
// ssr_i2c_force_resume @ 00102208 size=104
// signature: undefined ssr_i2c_force_resume(void)
// callers: []
//------------------------------------------------------------

void ssr_i2c_force_resume(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x98);
  mutex_lock(plVar1 + 0x46b);
  *(undefined1 *)(plVar1 + 0x471) = 0;
  *(undefined4 *)(plVar1 + 0x465) = 0;
  mutex_unlock(plVar1 + 0x46b);
  ipc_log_string(plVar1[0x27a],"SSR force resume done\n");
  if (*plVar1 != 0) {
    i2c_trace_log(*plVar1,"SSR force resume done\n");
  }
  return;
}



//------------------------------------------------------------
// geni_i2c_resources_init @ 00102270 size=756
// signature: undefined geni_i2c_resources_init(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

ulong geni_i2c_resources_init(long param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  ulong uVar7;
  
  if ((char)param_2[0x468] != '\0') {
    uVar7 = 0;
    goto LAB_0010229c;
  }
  lVar1 = param_1 + 0x10;
  uVar7 = devm_clk_get(lVar1,"se-clk");
  param_2[0x26c] = uVar7;
  if (0xfffffffffffff000 < uVar7) {
    _dev_err(lVar1,"Err getting SE Core clk %d\n",uVar7 & 0xffffffff);
    goto LAB_0010229c;
  }
  uVar7 = devm_clk_get(*(undefined8 *)(*param_2 + 0x60),"m-ahb");
  param_2[0x275] = uVar7;
  if (uVar7 < 0xfffffffffffff001) {
    uVar7 = devm_clk_get(*(undefined8 *)(*param_2 + 0x60),"s-ahb");
    param_2[0x276] = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,i2c-hub",0);
      *(bool *)((long)param_2 + 0x2346) = lVar4 != 0;
      lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,high-perf",0);
      *(bool *)((long)param_2 + 0x232e) = lVar4 != 0;
      if (*(char *)((long)param_2 + 0x2346) == '\0') {
        if (lVar4 == 0) {
          if ((param_2 != (long *)0xffffffffffffdc70) && (lVar4 = param_2[0x474], lVar4 != 0)) {
            iVar2 = *(int *)((long)param_2 + 0x22b4);
            uVar7 = geni_icc_get(lVar4,"qup-memory");
            if ((int)uVar7 != 0) goto LAB_001024f0;
            *(undefined4 *)(lVar4 + 0x38) = 1;
            *(undefined4 *)(lVar4 + 0x48) = 1;
            *(int *)(lVar4 + 0x58) = iVar2 / 1000;
LAB_00102400:
            uVar5 = platform_get_irq(param_1,0);
            uVar7 = uVar5 & 0xffffffff;
            *(int *)((long)param_2 + 0x14) = (int)uVar5;
            if (-1 < (int)uVar5) {
              irq_modify_status(uVar7,0,0x1000);
              uVar5 = devm_request_threaded_irq
                                (*param_2,*(undefined4 *)((long)param_2 + 0x14),geni_i2c_irq,0,0,
                                 "i2c_geni",param_2);
              uVar7 = uVar5 & 0xffffffff;
              if ((int)uVar5 != 0) {
                _dev_err(*param_2,"Request_irq failed:%d: err:%d\n",
                         *(undefined4 *)((long)param_2 + 0x14),uVar7);
              }
            }
            goto LAB_0010229c;
          }
LAB_00102474:
          uVar7 = 0xffffffea;
        }
        else {
          if ((param_2 == (long *)0xffffffffffffdc70) || (lVar4 = param_2[0x474], lVar4 == 0))
          goto LAB_00102474;
          uVar7 = geni_icc_get(lVar4,"qup-memory");
          if ((int)uVar7 == 0) {
            *(undefined4 *)(lVar4 + 0x38) = 50000;
            *(undefined4 *)(lVar4 + 0x48) = 1;
            *(undefined4 *)(lVar4 + 0x58) = 0x12c00;
            goto LAB_00102400;
          }
LAB_001024f0:
          uVar7 = uVar7 & 0xffffffff;
        }
        pcVar6 = "%s: Error - resources_init ret:%d\n";
      }
      else {
        uVar7 = devm_clk_get(lVar1,"core-clk");
        param_2[0x277] = uVar7;
        if (0xfffffffffffff000 < uVar7) {
          pcVar6 = "Err getting core-clk %d\n";
          goto LAB_001024e0;
        }
        uVar3 = geni_icc_get(param_2 + 0x269,0);
        if (uVar3 == 0) {
          *(undefined4 *)(param_2 + 0x270) = 1;
          *(undefined4 *)(param_2 + 0x272) = 1;
          *(undefined1 *)((long)param_2 + 0x2349) = 1;
          _dev_info(*param_2,"%s: RTL based SE\n","geni_i2c_resources_init");
          goto LAB_00102400;
        }
        uVar7 = (ulong)uVar3;
        pcVar6 = "%s: Error - geni_icc_get ret:%d\n";
      }
      _dev_err(lVar1,pcVar6,"geni_i2c_resources_init",uVar7);
      goto LAB_0010229c;
    }
    pcVar6 = "Err getting S AHB clk %d\n";
  }
  else {
    pcVar6 = "Err getting M AHB clk %d\n";
  }
LAB_001024e0:
  _dev_err(lVar1,pcVar6,uVar7 & 0xffffffff);
LAB_0010229c:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// dma_set_mask_and_coherent @ 00102564 size=76
// signature: undefined dma_set_mask_and_coherent(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

int dma_set_mask_and_coherent(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = dma_set_mask();
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// test_bus_enable_per_qupv3 @ 001025b0 size=104
// signature: undefined test_bus_enable_per_qupv3(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

void test_bus_enable_per_qupv3(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x98);
  writel_relaxed(0x11,*plVar2 + 0x204);
  uVar1 = readl_relaxed(*plVar2 + 0x204);
  ipc_log_string(param_2,"%s: TEST_BUS_EN: 0x%x @address:0x%x\n","test_bus_enable_per_qupv3",uVar1,
                 *plVar2 + 0x204);
  return;
}



//------------------------------------------------------------
// geni_i2c_runtime_suspend @ 0010261c size=1560
// signature: undefined geni_i2c_runtime_suspend(void)
// callers: [geni_i2c_remove, ssr_i2c_force_suspend, geni_i2c_suspend_late]
//------------------------------------------------------------

int geni_i2c_runtime_suspend(long param_1)

{
  char *pcVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 uVar8;
  ulong *puVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  
  plVar10 = *(long **)(param_1 + 0x98);
  lVar11 = plVar10[0x27b];
  if (lVar11 == 0) {
    uVar6 = 0xffffffffffffffea;
  }
  else if ((int)plVar10[0x27c] == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = sched_clock();
    ipc_log_string(lVar11,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_runtime_suspend",uVar6,
                   uVar6 / 1000);
  }
  iVar5 = (int)plVar10[0x465];
  pcVar1 = (char *)((long)plVar10 + 0x232d);
  if (iVar5 == 1) {
    disable_irq(*(undefined4 *)((long)plVar10 + 0x14));
    iVar5 = (int)plVar10[0x465];
  }
  if (((iVar5 == 2) && ((char)plVar10[0x468] == '\0')) &&
     (iVar5 = geni_i2c_gpi_pause_resume(plVar10,1), iVar5 != 0)) goto LAB_00102a9c;
  plVar2 = plVar10 + 0x269;
  if (*(char *)((long)plVar10 + 0x234a) == '\0') {
    if ((char)plVar10[0x468] == '\0') {
      if (*pcVar1 == '\0') {
        geni_se_resources_off(plVar2);
      }
      else {
LAB_001027d8:
        lVar11 = plVar10[0x26c];
        lVar12 = plVar10[0x275];
        lVar13 = plVar10[0x276];
        clk_disable(lVar11);
        clk_unprepare(lVar11);
        clk_disable(lVar12);
        clk_unprepare(lVar12);
        clk_disable(lVar13);
        clk_unprepare(lVar13);
      }
      iVar4 = geni_icc_disable(plVar2);
      if (iVar4 != 0) {
        ipc_log_string(plVar10[0x27a],"%s failing at geni_icc_disable ret=%d\n",
                       "geni_i2c_runtime_suspend",iVar4);
        if (*plVar10 != 0) {
          i2c_trace_log(*plVar10,"%s failing at geni_icc_disable ret=%d\n",
                        "geni_i2c_runtime_suspend",iVar4);
        }
      }
      goto LAB_00102ae0;
    }
    if (*(char *)((long)plVar10 + 0x2344) == '\0') {
      if (*pcVar1 != '\0') goto LAB_001027d8;
      goto LAB_00102adc;
    }
    lVar11 = plVar10[0x27b];
    if (lVar11 == 0) {
      uVar7 = 0xffffffffffffffea;
LAB_00102868:
      if (*(char *)((long)plVar10 + 0x2345) == '\0') goto LAB_001028b4;
LAB_00102870:
      ipc_log_string(plVar10[0x27a],"%s:gpi reset happened for levm, no need to do unlock\n",
                     "geni_i2c_unlock_bus");
      if (*plVar10 != 0) {
        i2c_trace_log(*plVar10,"%s:gpi reset happened for levm, no need to do unlock\n",
                      "geni_i2c_unlock_bus");
      }
    }
    else {
      if ((int)plVar10[0x27c] == 0) {
        uVar7 = 0;
        if (*(char *)((long)plVar10 + 0x2345) != '\0') goto LAB_00102870;
      }
      else {
        uVar7 = sched_clock();
        ipc_log_string(lVar11,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_unlock_bus",uVar7,
                       uVar7 / 1000);
        if ((char)plVar10[0x468] != '\0') goto LAB_00102868;
      }
LAB_001028b4:
      plVar10[0x281] = 0;
      plVar10[0x282] = 0x31010000000000;
      sg_init_table(plVar10[0x452],1);
      puVar9 = (ulong *)plVar10[0x452];
      *puVar9 = (*puVar9 & 3 | (((long)(plVar10 + 0x281) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6)
                - 0x200000000;
      *(uint *)(puVar9 + 1) = (uint)(plVar10 + 0x281) & 0xfff;
      *(undefined4 *)((long)puVar9 + 0xc) = 0x10;
      lVar11 = geni_i2c_prep_desc(plVar10,1,1);
      plVar10[0x457] = lVar11;
      if (lVar11 == 0) {
        uVar8 = 0xfffffff4;
LAB_001029f0:
        *(undefined4 *)(plVar10 + 3) = uVar8;
LAB_001029f4:
        pcVar3 = *(code **)(*(long *)plVar10[0x27d] + 0x148);
        if (pcVar3 != (code *)0x0) {
          if (*(int *)(pcVar3 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102a1c);
            (*pcVar3)();
          }
          (*pcVar3)();
        }
        *(undefined4 *)(plVar10 + 0x456) = 0;
        *(undefined4 *)(plVar10 + 3) = 0;
      }
      else {
        *(undefined1 *)((long)plVar10 + 0x2341) = 1;
        *(undefined4 *)(plVar10 + 0x9c) = 0;
        if (*(int *)(*(code **)(lVar11 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102950);
          (*pcVar3)();
        }
        iVar5 = (**(code **)(lVar11 + 0x18))();
        if (iVar5 < 0) {
          ipc_log_string(plVar10[0x27a],"%s: dmaengine_submit failed (%d)\n","geni_i2c_unlock_bus",
                         iVar5);
          if (*plVar10 == 0) {
            _printk(&DAT_0010b073,"geni_i2c_unlock_bus",iVar5);
          }
          else {
            _dev_err(*plVar10,"%s: dmaengine_submit failed (%d)\n","geni_i2c_unlock_bus",iVar5);
          }
          if (*plVar10 != 0) {
            i2c_trace_log(*plVar10,"%s: dmaengine_submit failed (%d)\n","geni_i2c_unlock_bus",iVar5)
            ;
          }
          uVar8 = 0xffffffea;
          goto LAB_001029f0;
        }
        if (*(int *)(*(code **)(*(long *)plVar10[0x27d] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102980);
          (*pcVar3)();
        }
        (**(code **)(*(long *)plVar10[0x27d] + 0x160))();
        iVar5 = wait_for_completion_timeout(plVar10 + 0x9c,0xfa);
        if (iVar5 == 0) {
          ipc_log_string(plVar10[0x27a],"%s failed\n","geni_i2c_unlock_bus");
          if (*plVar10 != 0) {
            i2c_trace_log(*plVar10,"%s failed\n","geni_i2c_unlock_bus");
          }
          geni_i2c_se_dump_dbg_regs(plVar2,plVar10[1],plVar10[0x27a]);
          uVar8 = 0xffffff92;
          goto LAB_001029f0;
        }
        if ((int)plVar10[3] != 0) goto LAB_001029f4;
      }
      lVar11 = plVar10[0x27b];
      *(undefined1 *)((long)plVar10 + 0x2341) = 0;
      if (((lVar11 != 0) && (uVar7 != 0)) && ((int)plVar10[0x27c] != 0)) {
        lVar12 = sched_clock();
        ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","geni_i2c_unlock_bus",lVar12 - uVar7,
                       (lVar12 - uVar7) / 1000);
      }
    }
    if ((int)plVar10[0x465] == 2) {
      iVar5 = geni_i2c_gpi_pause_resume(plVar10,1);
      iVar4 = 0;
      if (iVar5 != 0) {
LAB_00102a9c:
        ipc_log_string(plVar10[0x27a],"%s: ret:%d\n","geni_i2c_runtime_suspend",iVar5);
        if (*plVar10 == 0) {
          return iVar5;
        }
        i2c_trace_log(*plVar10,"%s: ret:%d\n","geni_i2c_runtime_suspend",iVar5);
        return iVar5;
      }
      goto LAB_00102ae0;
    }
  }
  else if (*pcVar1 == '\0') {
    if ((char)plVar10[0x468] == '\0') {
      geni_se_resources_off(plVar2);
    }
  }
  else {
    lVar11 = plVar10[0x26c];
    lVar12 = plVar10[0x275];
    lVar13 = plVar10[0x276];
    clk_disable(lVar11);
    clk_unprepare(lVar11);
    clk_disable(lVar12);
    clk_unprepare(lVar12);
    clk_disable(lVar13);
    clk_unprepare(lVar13);
  }
LAB_00102adc:
  iVar4 = 0;
LAB_00102ae0:
  if (*(char *)((long)plVar10 + 0x2346) != '\0') {
    lVar11 = plVar10[0x277];
    clk_disable(lVar11);
    clk_unprepare(lVar11);
  }
  ipc_log_string(plVar10[0x27a],"%s ret=%d\n","geni_i2c_runtime_suspend",iVar4);
  if (*plVar10 != 0) {
    i2c_trace_log(*plVar10,"%s ret=%d\n","geni_i2c_runtime_suspend",iVar4);
  }
  lVar11 = plVar10[0x27b];
  if (lVar11 != 0) {
    if (uVar6 == 0) {
      return 0;
    }
    if ((int)plVar10[0x27c] == 0) {
      return 0;
    }
    lVar12 = sched_clock();
    ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","geni_i2c_runtime_suspend",lVar12 - uVar6
                   ,(lVar12 - uVar6) / 1000);
  }
  return 0;
}



//------------------------------------------------------------
// geni_i2c_gpi_pause_resume @ 00102c34 size=364
// signature: undefined geni_i2c_gpi_pause_resume(void)
// callers: [geni_i2c_runtime_resume, geni_i2c_runtime_suspend]
//------------------------------------------------------------

undefined8 geni_i2c_gpi_pause_resume(long *param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  
  plVar4 = (long *)param_1[0x27d];
  if (plVar4 == (long *)0x0) {
    return 0;
  }
  if ((param_2 & 1) == 0) {
    pcVar1 = (char *)((long)param_1 + 0x2352);
    cVar2 = *pcVar1;
    if (cVar2 != '\0') {
      *(undefined4 *)(param_1 + 0x44c) = 5;
    }
    pcVar5 = *(code **)(*plVar4 + 0x140);
    if (pcVar5 == (code *)0x0) {
      iVar3 = -0x26;
    }
    else {
      if (*(int *)(pcVar5 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x102cc8);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)();
      cVar2 = *pcVar1;
    }
    if (cVar2 != '\0') {
      *(undefined4 *)(param_1 + 0x44c) = 0;
      *pcVar1 = '\0';
    }
  }
  else {
    pcVar5 = *(code **)(*plVar4 + 0x138);
    if (pcVar5 == (code *)0x0) {
      iVar3 = -0x26;
      goto LAB_00102d0c;
    }
    if (*(int *)(pcVar5 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102c80);
      (*pcVar5)();
    }
    iVar3 = (*pcVar5)();
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_00102d0c:
  param_2 = param_2 & 1;
  ipc_log_string(param_1[0x27a],"%s failed: tx:%d status:%d\n","geni_i2c_gpi_pause_resume",iVar3,
                 param_2);
  if (*param_1 == 0) {
    _printk(&DAT_0010ae30,"geni_i2c_gpi_pause_resume",iVar3,param_2);
  }
  else {
    _dev_err(*param_1,"%s failed: tx:%d status:%d\n","geni_i2c_gpi_pause_resume",iVar3,param_2);
  }
  if (*param_1 != 0) {
    i2c_trace_log(*param_1,"%s failed: tx:%d status:%d\n","geni_i2c_gpi_pause_resume",iVar3,param_2)
    ;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// geni_i2c_prep_desc @ 00102da0 size=412
// signature: undefined geni_i2c_prep_desc(void)
// callers: [geni_i2c_lock_bus, geni_i2c_gsi_xfer, geni_i2c_stop_on_bus, geni_i2c_runtime_suspend]
//------------------------------------------------------------

long geni_i2c_prep_desc(long *param_1,undefined4 param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  code *pcVar5;
  
  if ((param_3 & 1) == 0) {
    plVar1 = (long *)param_1[0x27e];
    if (((plVar1 != (long *)0x0) && (*plVar1 != 0)) &&
       (pcVar5 = *(code **)(*plVar1 + 0x108), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102e5c);
        (*pcVar5)();
      }
      lVar2 = (*pcVar5)(plVar1,param_1[0x453],1,2,3,0);
      if (lVar2 != 0) {
        lVar4 = 0x22f8;
        pcVar5 = gi2c_gsi_rx_cb;
        goto LAB_00102e70;
      }
    }
    ipc_log_string(param_1[0x27a],"prep_slave_sg for rx failed\n");
    if (*param_1 == 0) {
      _printk(&DAT_0010b655);
      lVar2 = *param_1;
    }
    else {
      _dev_err(*param_1,"prep_slave_sg for rx failed\n");
      lVar2 = *param_1;
    }
    if (lVar2 == 0) goto LAB_00102f20;
    pcVar3 = "prep_slave_sg for rx failed\n";
  }
  else {
    plVar1 = (long *)param_1[0x27d];
    if (((plVar1 != (long *)0x0) && (*plVar1 != 0)) &&
       (pcVar5 = *(code **)(*plVar1 + 0x108), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x102e00);
        (*pcVar5)();
      }
      lVar2 = (*pcVar5)(plVar1,param_1[0x452],param_2,1,3,0);
      if (lVar2 != 0) {
        lVar4 = 0x22c8;
        pcVar5 = gi2c_gsi_tx_cb;
LAB_00102e70:
        *(code **)(lVar2 + 0x28) = pcVar5;
        *(long *)(lVar2 + 0x38) = (long)param_1 + lVar4;
        return lVar2;
      }
    }
    ipc_log_string(param_1[0x27a],"prep_slave_sg for tx failed\n");
    if (*param_1 == 0) {
      _printk(&DAT_0010a5d0);
      lVar2 = *param_1;
    }
    else {
      _dev_err(*param_1,"prep_slave_sg for tx failed\n");
      lVar2 = *param_1;
    }
    if (lVar2 == 0) goto LAB_00102f20;
    pcVar3 = "prep_slave_sg for tx failed\n";
  }
  i2c_trace_log(lVar2,pcVar3);
LAB_00102f20:
  *(undefined4 *)(param_1 + 3) = 0xfffffff4;
  return 0;
}



//------------------------------------------------------------
// gi2c_gsi_tx_cb @ 00102f40 size=228
// signature: undefined gi2c_gsi_tx_cb(void)
// callers: []
//------------------------------------------------------------

void gi2c_gsi_tx_cb(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long *plVar4;
  
  if ((param_1 == 0) || (plVar4 = *(long **)(param_1 + 0x20), plVar4 == (long *)0x0)) {
    _printk(&DAT_00109fac,"gi2c_gsi_tx_cb");
  }
  else {
    piVar1 = (int *)((long)plVar4 + 0x53c);
    if (*(char *)((long)plVar4 + 0x2341) == '\0') {
      gi2c_gsi_cb_err(param_1,&DAT_0010a95e);
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    ipc_log_string(plVar4[0x27a],"%s:tx_cnt:%d gsi_err:%d gi2c_err:%d irq_cnt:%d\n","gi2c_gsi_tx_cb"
                   ,(int)plVar4[0xa6],(char)plVar4[0x469],(int)plVar4[3],
                   *(undefined4 *)((long)plVar4 + 0x53c));
    if (*plVar4 != 0) {
      i2c_trace_log(*plVar4,"%s:tx_cnt:%d gsi_err:%d gi2c_err:%d irq_cnt:%d\n","gi2c_gsi_tx_cb",
                    (int)plVar4[0xa6],(char)plVar4[0x469],(int)plVar4[3],
                    *(undefined4 *)((long)plVar4 + 0x53c));
    }
    complete_all(plVar4 + 0x9c);
  }
  return;
}



//------------------------------------------------------------
// gi2c_gsi_rx_cb @ 00103030 size=192
// signature: undefined gi2c_gsi_rx_cb(void)
// callers: []
//------------------------------------------------------------

void gi2c_gsi_rx_cb(long param_1)

{
  long *plVar1;
  
  if ((param_1 == 0) || (plVar1 = *(long **)(param_1 + 0x20), plVar1 == (long *)0x0)) {
    _printk(&DAT_0010a5ef,"gi2c_gsi_rx_cb");
  }
  else {
    if (plVar1[0xa4] == 0) {
      ipc_log_string(plVar1[0x27a],&DAT_0010acbc,"Received unexpected interrupt");
      if (*plVar1 != 0) {
        i2c_trace_log(*plVar1,&DAT_0010acbc,"Received unexpected interrupt");
      }
      geni_i2c_se_dump_dbg_regs(plVar1 + 0x269,plVar1[1],plVar1[0x27a]);
      *(undefined4 *)(plVar1 + 3) = 0xffffffea;
    }
    else {
      if ((*(ushort *)(plVar1[0xa4] + 2) & 1) == 0) {
        return;
      }
      gi2c_gsi_cb_err(param_1,&DAT_0010a45a);
    }
    complete(plVar1 + 0x9c);
  }
  return;
}



//------------------------------------------------------------
// gi2c_gsi_cb_err @ 001030f0 size=500
// signature: undefined gi2c_gsi_cb_err(void)
// callers: [gi2c_gsi_rx_cb, gi2c_gsi_tx_cb]
//------------------------------------------------------------

void gi2c_gsi_cb_err(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x20);
  if (plVar2 == (long *)0x0) {
    _printk(&DAT_0010aee8,"gi2c_gsi_cb_err");
  }
  else if (plVar2[0xa4] == 0) {
    ipc_log_string(plVar2[0x27a],&DAT_0010acbc,"Received unexpected interrupt");
    if (*plVar2 != 0) {
      i2c_trace_log(*plVar2,&DAT_0010acbc,"Received unexpected interrupt");
    }
    geni_i2c_se_dump_dbg_regs(plVar2 + 0x269,plVar2[1],plVar2[0x27a]);
    *(undefined4 *)(plVar2 + 3) = 0xffffffea;
    ipc_log_string(plVar2[0x27a],"%s: Invalid gi2c dev\n","gi2c_gsi_cb_err");
    if (*plVar2 != 0) {
      i2c_trace_log(*plVar2,"%s: Invalid gi2c dev\n","gi2c_gsi_cb_err");
    }
  }
  else if ((*(uint *)(param_1 + 8) & 0x340) != 0) {
    ipc_log_string(plVar2[0x27a],"%s TCE Unexpected Err, stat:0x%x\n",param_2);
    if (*plVar2 != 0) {
      i2c_trace_log(*plVar2,"%s TCE Unexpected Err, stat:0x%x\n",param_2,
                    *(undefined4 *)(param_1 + 8));
    }
    uVar1 = *(uint *)(param_1 + 8);
    if ((uVar1 >> 6 & 1) != 0) {
      geni_i2c_check_addr_data_nack(plVar2,*(undefined2 *)(plVar2[0xa4] + 2));
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 8 & 1) != 0) {
      ipc_log_string(plVar2[0x27a],&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
      if (*plVar2 != 0) {
        i2c_trace_log(*plVar2,&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
      }
      geni_i2c_se_dump_dbg_regs(plVar2 + 0x269,plVar2[1],plVar2[0x27a]);
      *(undefined4 *)(plVar2 + 3) = 0xffffffb9;
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 9 & 1) != 0) {
      ipc_log_string(plVar2[0x27a],&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
      if (*plVar2 != 0) {
        i2c_trace_log(*plVar2,&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
      }
      geni_i2c_se_dump_dbg_regs(plVar2 + 0x269,plVar2[1],plVar2[0x27a]);
      *(undefined4 *)(plVar2 + 3) = 0xfffffff0;
    }
  }
  return;
}



//------------------------------------------------------------
// geni_i2c_check_addr_data_nack @ 001032e4 size=172
// signature: undefined geni_i2c_check_addr_data_nack(void)
// callers: [geni_i2c_irq, gi2c_gsi_cb_err, gi2c_ev_cb]
//------------------------------------------------------------

void geni_i2c_check_addr_data_nack(long *param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  iVar1 = readl_relaxed(param_1[1] + 0x910);
  if (iVar1 == 0) {
    ipc_log_string(param_1[0x27a],&DAT_0010acbc,
                   "Address NACK: slv unresponsive, check its power/reset-ln");
    lVar2 = *param_1;
    if (lVar2 == 0) goto LAB_00103378;
    pcVar3 = "Address NACK: slv unresponsive, check its power/reset-ln";
  }
  else {
    if ((param_2 & 1) != 0) {
      return;
    }
    ipc_log_string(param_1[0x27a],&DAT_0010acbc,"Data NACK: Device NACK before end of TX transfer");
    lVar2 = *param_1;
    if (lVar2 == 0) goto LAB_00103378;
    pcVar3 = "Data NACK: Device NACK before end of TX transfer";
  }
  i2c_trace_log(lVar2,&DAT_0010acbc,pcVar3);
LAB_00103378:
  *(undefined4 *)(param_1 + 3) = 0xffffff95;
  return;
}



//------------------------------------------------------------
// geni_i2c_irq @ 00103394 size=2092
// signature: undefined geni_i2c_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 geni_i2c_irq(undefined8 param_1,long *param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  bool bVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  
  pcVar2 = (char *)((long)param_2 + 0x232c);
  if ((char)param_2[0x471] == '\0') {
    lVar17 = param_2[0x27b];
    lVar10 = param_2[0xa4];
    if (lVar17 == 0) {
      uVar16 = 0xffffffffffffffea;
    }
    else if ((int)param_2[0x27c] == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = sched_clock();
      ipc_log_string(lVar17,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_irq",uVar16,uVar16 / 1000
                    );
    }
    uVar11 = readl_relaxed(param_2[1] + 0x610);
    uVar18 = (uint)uVar11;
    uVar5 = readl_relaxed(param_2[1] + 0xc40);
    uVar6 = readl_relaxed(param_2[1] + 0xd40);
    iVar7 = readl_relaxed(param_2[1] + 600);
    ipc_log_string(param_2[0x27a],"%s: m_irq_status:0x%x\n","geni_i2c_irq",uVar11 & 0xffffffff);
    if (*param_2 != 0) {
      i2c_trace_log(*param_2,"%s: m_irq_status:0x%x\n","geni_i2c_irq",uVar11 & 0xffffffff);
    }
    if (lVar10 == 0) {
      ipc_log_string(param_2[0x27a],"Spurious irq\n");
      if (*param_2 != 0) {
        i2c_trace_log(*param_2,"Spurious irq\n");
      }
      ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Received unexpected interrupt");
      if (*param_2 != 0) {
        i2c_trace_log(*param_2,&DAT_0010acbc,"Received unexpected interrupt");
      }
      geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
      bVar12 = false;
      uVar8 = 0;
      *(undefined4 *)(param_2 + 3) = 0xffffffea;
      *pcVar2 = '\x01';
      goto LAB_001033e4;
    }
    if (((((uVar18 >> 3 & 1) != 0) || ((uVar6 & 0x340) != 0)) || ((uVar18 >> 4 & 1) != 0)) ||
       ((((uVar18 >> 5 & 1) != 0 || ((uVar18 >> 10 & 1) != 0)) ||
        (((uVar18 >> 0xc & 1) != 0 || ((uVar18 >> 0xd & 1) != 0)))))) {
      if ((uVar18 >> 10 & 1) != 0) {
        geni_i2c_check_addr_data_nack(param_2,*(undefined2 *)(param_2[0xa4] + 2));
      }
      if ((uVar18 >> 0xc & 1) != 0) {
        ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
        }
        geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
        *(undefined4 *)(param_2 + 3) = 0xffffffb9;
      }
      if ((uVar18 >> 0xd & 1) != 0) {
        ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
        }
        geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
        *(undefined4 *)(param_2 + 3) = 0xfffffff0;
      }
      if ((uVar18 >> 1 & 1) != 0) {
        ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Cmd overrun, check GENI cmd-state machine");
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,&DAT_0010acbc,"Cmd overrun, check GENI cmd-state machine");
        }
        geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
        *(undefined4 *)(param_2 + 3) = 0xfffffffb;
      }
      if ((uVar18 >> 2 & 1) != 0) {
        ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Illegal cmd, check GENI cmd-state machine");
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,&DAT_0010acbc,"Illegal cmd, check GENI cmd-state machine");
        }
        geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
        *(undefined4 *)(param_2 + 3) = 0xffffffac;
      }
      if ((uVar18 >> 5 & 1) != 0) {
        ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Abort after timeout successful");
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,&DAT_0010acbc,"Abort after timeout successful");
        }
        *(undefined4 *)(param_2 + 3) = 0xffffff92;
      }
      if ((uVar18 >> 3 & 1) != 0) {
        if ((int)param_2[3] == 0) {
          ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Master command failure");
          if (*param_2 != 0) {
            i2c_trace_log(*param_2,&DAT_0010acbc,"Master command failure");
          }
          geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
          *(undefined4 *)(param_2 + 3) = 0xffffffea;
        }
        else {
          ipc_log_string(param_2[0x27a],"%s:GENI_M_CMD_FAILURE\n","geni_i2c_irq");
          if (*param_2 != 0) {
            i2c_trace_log(*param_2,"%s:GENI_M_CMD_FAILURE\n","geni_i2c_irq");
          }
        }
      }
      bVar12 = false;
      uVar8 = (uint)((uVar11 & 0xffffffff) >> 4) & 1;
      *pcVar2 = '\x01';
      goto LAB_001033e4;
    }
    lVar17 = param_2[0xa4];
    uVar8 = readl_relaxed(param_2[1] + 0x804);
    if (lVar17 == 0) {
      ipc_log_string(param_2[0x27a],"%s: Spurious irq\n","geni_i2c_irq_handle_watermark");
      if (*param_2 != 0) {
        i2c_trace_log(*param_2,"%s: Spurious irq\n","geni_i2c_irq_handle_watermark");
      }
      ipc_log_string(param_2[0x27a],&DAT_0010acbc,"Received unexpected interrupt");
      if (*param_2 != 0) {
        i2c_trace_log(*param_2,&DAT_0010acbc,"Received unexpected interrupt");
      }
      geni_i2c_se_dump_dbg_regs(param_2 + 0x269,param_2[1],param_2[0x27a]);
      uVar8 = 0;
      bVar12 = true;
      *(undefined4 *)(param_2 + 3) = 0xffffffea;
      goto LAB_001033e4;
    }
    if (((uVar11 & 0xc000000) == 0) || ((*(ushort *)(lVar17 + 2) & 1) == 0)) {
      if (((uVar18 >> 0x1e & 1) == 0) || ((*(ushort *)(lVar17 + 2) & 1) != 0)) {
        ipc_log_string(param_2[0x27a],"%s: m_irq_status:0x%x cur->flags:%d\n",
                       "geni_i2c_irq_handle_watermark",uVar11 & 0xffffffff);
        if (*param_2 != 0) {
          i2c_trace_log(*param_2,"%s: m_irq_status:0x%x cur->flags:%d\n",
                        "geni_i2c_irq_handle_watermark",uVar11 & 0xffffffff,
                        *(undefined2 *)(lVar17 + 2));
        }
      }
      else if ((int)param_2[2] != 0) {
        uVar8 = 0;
        uVar11 = (ulong)*(uint *)(param_2 + 0x278);
        uVar13 = (uint)*(ushort *)(lVar17 + 4);
        do {
          if ((int)uVar11 < (int)uVar13) {
            lVar10 = (long)(int)uVar11;
            lVar15 = *(long *)(lVar17 + 8);
            uVar14 = (ulong)uVar13;
            uVar11 = lVar10 + 1;
            uVar13 = (uint)*(byte *)(lVar15 + lVar10);
            if ((long)uVar11 < (long)uVar14) {
              puVar1 = (undefined1 *)(lVar15 + uVar11);
              uVar11 = lVar10 + 2;
              uVar3 = CONCAT11(*puVar1,*(byte *)(lVar15 + lVar10));
              uVar13 = (uint)uVar3;
              if ((long)uVar11 < (long)uVar14) {
                puVar1 = (undefined1 *)(lVar15 + uVar11);
                uVar11 = lVar10 + 3;
                uVar4 = CONCAT12(*puVar1,uVar3);
                uVar13 = (uint)uVar4;
                if ((long)uVar11 < (long)uVar14) {
                  puVar1 = (undefined1 *)(lVar15 + uVar11);
                  uVar11 = lVar10 + 4;
                  uVar13 = CONCAT13(*puVar1,uVar4);
                }
              }
            }
          }
          else {
            uVar13 = 0;
          }
          if ((char)param_2[0x471] != '\0') goto LAB_001033e0;
          writel_relaxed(uVar13,param_2[1] + 0x700);
          *(uint *)(param_2 + 0x278) = (uint)uVar11;
          uVar13 = (uint)*(ushort *)(lVar17 + 4);
          if ((uint)uVar11 == uVar13) {
            writel_relaxed(0,param_2[1] + 0x80c);
            goto LAB_001033e0;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_2 + 2));
LAB_00103afc:
        bVar12 = true;
        uVar8 = 0;
        goto LAB_001033e4;
      }
    }
    else {
      uVar13 = uVar8 & 0x1ffffff;
      if ((uVar8 & 0x1ffffff) != 0) {
        do {
          uVar13 = uVar13 - 1;
          if ((char)param_2[0x471] != '\0') goto LAB_001033e0;
          uVar9 = readl_relaxed(param_2[1] + 0x780);
          uVar8 = *(uint *)((long)param_2 + 0x13c4);
          uVar11 = (ulong)uVar8;
          if ((int)uVar8 < (int)(uint)*(ushort *)(lVar17 + 4)) {
            lVar10 = (long)(int)uVar8;
            *(char *)(*(long *)(lVar17 + 8) + lVar10) = (char)uVar9;
            uVar11 = lVar10 + 1;
            if ((long)uVar11 < (long)(ulong)*(ushort *)(lVar17 + 4)) {
              *(char *)(*(long *)(lVar17 + 8) + uVar11) = (char)((uint)uVar9 >> 8);
              uVar11 = lVar10 + 2;
              if ((long)uVar11 < (long)(ulong)*(ushort *)(lVar17 + 4)) {
                *(char *)(*(long *)(lVar17 + 8) + uVar11) = (char)((uint)uVar9 >> 0x10);
                uVar11 = lVar10 + 3;
                if ((long)uVar11 < (long)(ulong)*(ushort *)(lVar17 + 4)) {
                  *(char *)(*(long *)(lVar17 + 8) + uVar11) = (char)((uint)uVar9 >> 0x18);
                  uVar11 = lVar10 + 4;
                }
              }
            }
          }
          *(uint *)((long)param_2 + 0x13c4) = (uint)uVar11;
          bVar12 = true;
          if ((uint)uVar11 == (uint)*(ushort *)(lVar17 + 4)) goto LAB_00103afc;
        } while (uVar13 != 0);
        uVar8 = 0;
        goto LAB_001033e4;
      }
    }
  }
  else {
    uVar18 = 0;
    uVar5 = 0;
    uVar6 = 0;
    iVar7 = 0;
    uVar16 = 0;
  }
LAB_001033e0:
  uVar8 = 0;
  bVar12 = true;
LAB_001033e4:
  if ((char)param_2[0x471] == '\0') {
    if (iVar7 != 0) {
      bVar12 = true;
    }
    if (!bVar12) {
      writel_relaxed(0,param_2[1] + 0x80c);
    }
    if (uVar18 != 0) {
      writel_relaxed(uVar18,param_2[1] + 0x618);
    }
    if (iVar7 != 0) {
      if (uVar5 != 0) {
        writel_relaxed(uVar5,param_2[1] + 0xc44);
      }
      if (uVar6 != 0) {
        writel_relaxed(uVar6,param_2[1] + 0xd44);
      }
      DataSynchronizationBarrier(3,2,0);
      uVar18 = uVar5 | uVar6;
    }
    if ((uVar18 & 1) != 0) {
      *pcVar2 = '\x01';
    }
    if (*pcVar2 != '\0') {
      *pcVar2 = '\0';
      complete(param_2 + 0x9c);
    }
    if (uVar8 != 0) {
      complete(param_2 + 0xa0);
    }
    lVar17 = param_2[0x27b];
    if (((lVar17 != 0) && (uVar16 != 0)) && ((int)param_2[0x27c] != 0)) {
      lVar10 = sched_clock();
      ipc_log_string(lVar17,"%s:took %llu nsec(%llu usec)\n","geni_i2c_irq",lVar10 - uVar16,
                     (lVar10 - uVar16) / 1000);
    }
  }
  else {
    *pcVar2 = '\0';
    complete(param_2 + 0x9c);
    ipc_log_string(param_2[0x27a],"%s: SSR down\n","geni_i2c_irq");
    if (*param_2 != 0) {
      i2c_trace_log(*param_2,"%s: SSR down\n","geni_i2c_irq");
    }
  }
  return 1;
}



//------------------------------------------------------------
// writel_relaxed @ 00103bc0 size=132
// signature: undefined writel_relaxed(void)
// callers: [geni_i2c_irq, geni_i2c_stop_with_cancel, geni_i2c_runtime_resume, test_bus_enable_per_qupv3, geni_i2c_xfer, geni_i2c_bus_recovery, geni_i2c_prepare]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103bd8,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103c14,uVar1);
  return;
}



//------------------------------------------------------------
// geni_i2c_xfer @ 00103c48 size=5076
// signature: undefined geni_i2c_xfer(void)
// callers: []
//------------------------------------------------------------

ulong geni_i2c_xfer(long param_1,undefined2 *param_2,uint param_3)

{
  long *plVar1;
  long *plVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  char *pcVar11;
  code *pcVar12;
  ushort *puVar13;
  short *psVar14;
  long *plVar15;
  undefined1 *puVar16;
  long *plVar17;
  long lVar18;
  bool bVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  ulong local_a8;
  long local_98;
  long local_78;
  long local_70;
  long local_68;
  
  lVar18 = sp_el0;
  uVar23 = (ulong)param_3;
  local_68 = *(long *)(lVar18 + 0x638);
  plVar17 = *(long **)(param_1 + 0x108);
  lVar18 = plVar17[0x27b];
  if (lVar18 == 0) {
    uVar7 = 0xffffffffffffffea;
  }
  else if ((int)plVar17[0x27c] == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = sched_clock();
    ipc_log_string(lVar18,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_xfer",uVar7,uVar7 / 1000);
  }
  plVar1 = plVar17 + 0x46b;
  *(undefined4 *)(plVar17 + 3) = 0;
  *(undefined4 *)((long)plVar17 + 0x234c) = 1;
  mutex_lock(plVar1);
  if ((char)plVar17[0x471] != '\0') {
    mutex_unlock(plVar1);
    *(undefined4 *)((long)plVar17 + 0x234c) = 0;
    ipc_log_string(plVar17[0x27a],"%s: SSR Down\n","geni_i2c_xfer");
    if (*plVar17 == 0) {
LAB_001049b4:
      uVar22 = 0xffffffea;
    }
    else {
      i2c_trace_log(*plVar17,"%s: SSR Down\n","geni_i2c_xfer");
      uVar22 = 0xffffffea;
    }
    goto LAB_001049b8;
  }
  if ((*(ushort *)(*plVar17 + 0x200) & 7) != 0) {
    mutex_unlock(plVar1);
    *(undefined4 *)((long)plVar17 + 0x234c) = 0;
    ipc_log_string(plVar17[0x27a],"%s: System suspended\n","geni_i2c_xfer");
    if (*plVar17 == 0) {
      uVar22 = 0xfffffff3;
    }
    else {
      i2c_trace_log(*plVar17,"%s: System suspended\n","geni_i2c_xfer");
      uVar22 = 0xfffffff3;
    }
    goto LAB_001049b8;
  }
  if ((((char)plVar17[0x468] == '\0') && (*(char *)((long)plVar17 + 0x2342) == '\0')) &&
     (uVar4 = __pm_runtime_resume(*plVar17,4), (int)uVar4 < 0)) {
    uVar22 = (ulong)uVar4;
    pm_runtime_put_noidle(*plVar17);
    __pm_runtime_set_status(*plVar17,2);
    mutex_unlock(plVar1);
    *(undefined4 *)((long)plVar17 + 0x234c) = 0;
    ipc_log_string(plVar17[0x27a],"error turning SE resources:%d\n",uVar22);
    if (*plVar17 == 0) {
      _printk(&DAT_0010a02e,uVar22);
    }
    else {
      _dev_err(*plVar17,"error turning SE resources:%d\n",uVar22);
    }
    if (*plVar17 != 0) {
      i2c_trace_log(*plVar17,"error turning SE resources:%d\n",uVar22);
    }
    goto LAB_001049b8;
  }
  if (*(char *)((long)plVar17 + 0x2347) == '\0') {
LAB_00103f20:
    uVar4 = readl_relaxed(plVar17[1] + 0x908);
    if ((*(char *)((long)plVar17 + 0x232d) != '\0') || ((uVar4 & 3) == 3)) {
LAB_00103fc8:
      if (((char)plVar17[0x468] != '\0') && (*(char *)((long)plVar17 + 0x2344) == '\0')) {
        *(undefined1 *)((long)plVar17 + 0x2344) = 1;
        uVar4 = geni_i2c_prepare(plVar17);
        if (uVar4 == 0) {
          uVar8 = geni_i2c_lock_bus(plVar17);
          uVar22 = uVar8 & 0xffffffff;
          if ((int)uVar8 == 0) {
            ipc_log_string(plVar17[0x27a],"LE-VM first xfer\n");
            if (*plVar17 != 0) {
              i2c_trace_log(*plVar17,"LE-VM first xfer\n");
            }
            goto LAB_00104020;
          }
          ipc_log_string(plVar17[0x27a],"%s lock failed: %d\n","geni_i2c_xfer",uVar8 & 0xffffffff);
          if (*plVar17 == 0) {
            _printk(&DAT_00109a08,"geni_i2c_xfer",uVar8 & 0xffffffff);
          }
          else {
            _dev_err(*plVar17,"%s lock failed: %d\n","geni_i2c_xfer",uVar8 & 0xffffffff);
          }
          lVar18 = *plVar17;
          if (lVar18 != 0) {
            pcVar11 = "%s lock failed: %d\n";
            goto LAB_00104f88;
          }
        }
        else {
          uVar22 = (ulong)uVar4;
          ipc_log_string(plVar17[0x27a],"%s I2C prepare failed: %d\n","geni_i2c_xfer",uVar22);
          if (*plVar17 == 0) {
            _printk(&DAT_001098d0,"geni_i2c_xfer",uVar22);
          }
          else {
            _dev_err(*plVar17,"%s I2C prepare failed: %d\n","geni_i2c_xfer",uVar22);
          }
          lVar18 = *plVar17;
          if (lVar18 != 0) {
            pcVar11 = "%s I2C prepare failed: %d\n";
LAB_00104f88:
            i2c_trace_log(lVar18,pcVar11,"geni_i2c_xfer",uVar22);
          }
        }
        *(undefined4 *)((long)plVar17 + 0x234c) = 0;
        goto LAB_001049b8;
      }
LAB_00104020:
      ipc_log_string(plVar17[0x27a],"n:%d addr:0x%x\n",uVar23,*param_2);
      if (*plVar17 != 0) {
        i2c_trace_log(*plVar17,"n:%d addr:0x%x\n",uVar23,*param_2);
      }
      *(uint *)(plVar17 + 0x466) = param_3;
      kfree(plVar17[0x467]);
      if ((int)param_3 < 0) {
        plVar17[0x467] = 0;
LAB_00104078:
        ipc_log_string(plVar17[0x27a],"Buf logging pointer not available\n");
        if (*plVar17 != 0) {
          i2c_trace_log(*plVar17,"Buf logging pointer not available\n");
        }
      }
      else {
        lVar18 = __kmalloc(-(ulong)(param_3 >> 0x1f) & 0xfffffff000000000 | uVar23 << 4,0xdc0);
        plVar17[0x467] = lVar18;
        if (lVar18 == 0) goto LAB_00104078;
      }
      if ((int)plVar17[0x465] == 2) {
        mutex_unlock(plVar1);
        if (param_3 != 0) {
          uVar22 = 0;
          psVar14 = param_2 + 2;
          do {
            if (*psVar14 == 0) {
              ipc_log_string(plVar17[0x27a],"%s: I2C msg[%d] length is NULL\n","geni_i2c_xfer",
                             uVar22 & 0xffffffff);
              if (*plVar17 == 0) goto LAB_001049b4;
              i2c_trace_log(*plVar17,"%s: I2C msg[%d] length is NULL\n","geni_i2c_xfer",
                            uVar22 & 0xffffffff);
              uVar22 = 0xffffffea;
              goto LAB_001049b8;
            }
            uVar22 = uVar22 + 1;
            psVar14 = psVar14 + 8;
          } while (param_3 != uVar22);
        }
        uVar22 = geni_i2c_gsi_xfer(param_1,param_2,param_3);
        uVar22 = uVar22 & 0xffffffff;
        mutex_lock(plVar1);
      }
      else {
        *(char *)((long)plVar17 + 0x232d) = '\0';
        lVar18 = sched_clock();
        uVar8 = (ulong)(param_3 - 1);
        if ((int)param_3 < 1) {
          uVar22 = 0;
        }
        else {
          plVar2 = plVar17 + 0x269;
          uVar20 = 0;
          lVar10 = 4;
          do {
            lVar21 = plVar17[0x27b];
            local_78 = 0;
            local_70 = 0;
            if (lVar21 == 0) {
              local_a8 = 0xffffffffffffffea;
            }
            else if ((int)plVar17[0x27c] == 0) {
              local_a8 = 0;
            }
            else {
              local_a8 = sched_clock();
              ipc_log_string(lVar21,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_execute_xfer",
                             local_a8,local_a8 / 1000);
            }
            *(undefined4 *)(plVar17 + 0x9c) = 0;
            puVar13 = (ushort *)((long)param_2 + lVar10 + -4);
            uVar3 = *puVar13;
            plVar17[0xa4] = (long)puVar13;
            if (puVar13 == (ushort *)0x0) {
              ipc_log_string(plVar17[0x27a],"%s: Invalid buffer\n","geni_i2c_execute_xfer");
              if (*plVar17 == 0) {
                uVar22 = 0xfffffff4;
              }
              else {
                i2c_trace_log(*plVar17,"%s: Invalid buffer\n","geni_i2c_execute_xfer");
                uVar22 = 0xfffffff4;
              }
              goto LAB_00104cd4;
            }
            uVar4 = *(uint *)((long)plVar17 + 0x13e4);
            if (*(char *)((long)plVar17 + 0x2349) == '\0') {
              if (3 < uVar4) goto LAB_00105014;
              puVar16 = geni_i2c_clk_map;
            }
            else {
              if (3 < uVar4) {
LAB_00105014:
                    /* WARNING: Does not return */
                pcVar12 = (code *)SoftwareBreakpoint(0x5512,0x105018);
                (*pcVar12)();
              }
              puVar16 = geni_i2c_hub_clk_map;
            }
            if (2 < (ulong)uVar4) {
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(1,0x10501c);
              (*pcVar12)();
            }
            uVar22 = 0;
            if ((ulong)*(uint *)(puVar16 + (ulong)uVar4 * 8) != 0) {
              uVar22 = ((ulong)*(ushort *)((long)param_2 + lVar10) * 9000000) /
                       (ulong)*(uint *)(puVar16 + (ulong)uVar4 * 8);
            }
            uVar22 = uVar22 * 10 + 500000;
            uVar5 = __usecs_to_jiffies(uVar22 & 0xffffffff);
            *(undefined4 *)((long)plVar17 + 0x1c) = uVar5;
            ipc_log_string(plVar17[0x27a],"%s: us:%d jiffies:%d\n","qcom_geni_i2c_calc_timeout",
                           uVar22);
            if (*plVar17 != 0) {
              i2c_trace_log(*plVar17,"%s: us:%d jiffies:%d\n","qcom_geni_i2c_calc_timeout",uVar22,
                            *(undefined4 *)((long)plVar17 + 0x1c));
            }
            if ((*(char *)((long)plVar17 + 0x2346) == '\0') &&
               (0x20 < *(ushort *)((long)param_2 + lVar10))) {
              geni_se_select_mode(plVar2,2);
              bVar19 = true;
              local_98 = i2c_get_dma_safe_msg_buf(puVar13,1);
              if (local_98 == 0) {
                geni_i2c_stop_on_bus(plVar17);
                uVar22 = 0xfffffff4;
                goto LAB_00104cd4;
              }
            }
            else {
              geni_se_select_mode(plVar2,1);
              bVar19 = false;
              local_98 = 0;
            }
            uVar4 = (uVar3 & 0x7f) << 9 | (uint)(uVar20 < uVar8) << 2;
            ipc_log_string(plVar17[0x27a],"%s: stretch:%d, m_param:0x%x\n","geni_i2c_execute_xfer",
                           uVar20 < uVar8,uVar4);
            if (*plVar17 != 0) {
              i2c_trace_log(*plVar17,"%s: stretch:%d, m_param:0x%x\n","geni_i2c_execute_xfer",
                            uVar20 < uVar8,uVar4);
            }
            if ((*(ushort *)((long)param_2 + lVar10 + -2) & 1) == 0) {
              ipc_log_string(plVar17[0x27a],"msgs[%d].len:%d W\n",uVar20 & 0xffffffff,
                             *(undefined2 *)(plVar17[0xa4] + 4));
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,"msgs[%d].len:%d W\n",uVar20 & 0xffffffff,
                              *(undefined2 *)(plVar17[0xa4] + 4));
              }
              writel_relaxed(*(undefined2 *)((long)param_2 + lVar10),plVar17[1] + 0x26c);
              writel(uVar4 | 0x8000000,plVar17[0x269] + 0x600);
              if (bVar19) {
                uVar4 = geni_se_tx_dma_prep(plVar2,local_98,*(undefined2 *)((long)param_2 + lVar10),
                                            &local_70);
                if (uVar4 == 0) {
                  if (plVar17[0x467] != 0) {
                    *(long *)(plVar17[0x467] + lVar10 + -4) = local_98;
                    lVar21 = plVar17[0x467];
                    plVar15 = &local_70;
                    goto LAB_00104544;
                  }
LAB_00104550:
                  uVar22 = 0;
                  bVar19 = true;
                  goto LAB_0010455c;
                }
                uVar22 = (ulong)uVar4;
                i2c_put_dma_safe_msg_buf(local_98,puVar13,0);
                geni_se_select_mode(plVar2,1);
                geni_i2c_stop_on_bus(plVar17);
              }
              else {
                uVar22 = 0;
              }
              writel_relaxed(1,plVar17[1] + 0x80c);
              bVar19 = false;
            }
            else {
              ipc_log_string(plVar17[0x27a],"msgs[%d].len:%d R\n",uVar20 & 0xffffffff,
                             *(undefined2 *)(plVar17[0xa4] + 4));
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,"msgs[%d].len:%d R\n",uVar20 & 0xffffffff,
                              *(undefined2 *)(plVar17[0xa4] + 4));
              }
              writel_relaxed(*(undefined2 *)((long)param_2 + lVar10),plVar17[1] + 0x270);
              writel(uVar4 | 0x10000000,plVar17[0x269] + 0x600);
              if (bVar19) {
                uVar4 = geni_se_rx_dma_prep(plVar2,local_98,*(undefined2 *)((long)param_2 + lVar10),
                                            &local_78);
                if (uVar4 == 0) {
                  if (plVar17[0x467] == 0) goto LAB_00104550;
                  *(long *)(plVar17[0x467] + lVar10 + -4) = local_98;
                  lVar21 = plVar17[0x467];
                  plVar15 = &local_78;
LAB_00104544:
                  bVar19 = true;
                  uVar22 = 0;
                  *(long **)(lVar21 + lVar10 + 4) = plVar15;
                }
                else {
                  uVar22 = (ulong)uVar4;
                  i2c_put_dma_safe_msg_buf(local_98,puVar13,0);
                  geni_se_select_mode(plVar2,1);
                  geni_i2c_stop_on_bus(plVar17);
                  bVar19 = false;
                }
              }
              else {
                bVar19 = false;
                uVar22 = 0;
              }
            }
LAB_0010455c:
            DataSynchronizationBarrier(3,3,0);
            mutex_unlock(plVar1);
            iVar6 = wait_for_completion_timeout
                              (plVar17 + 0x9c,*(undefined4 *)((long)plVar17 + 0x1c));
            mutex_lock(plVar1);
            if ((char)plVar17[0x471] != '\0') {
LAB_001049f4:
              ipc_log_string(plVar17[0x27a],"%s: SSR Down\n","geni_i2c_execute_xfer");
              lVar18 = *plVar17;
joined_r0x00104a14:
              if (lVar18 != 0) {
                i2c_trace_log(lVar18,"%s: SSR Down\n","geni_i2c_execute_xfer");
              }
              goto LAB_00104d2c;
            }
            if (iVar6 == 0) {
              iVar6 = readl_relaxed(plVar17[1] + 0x610);
              writel_relaxed(0,plVar17[1] + 0x80c);
              if (iVar6 != 0) {
                writel_relaxed(iVar6,plVar17[1] + 0x618);
              }
              ipc_log_string(plVar17[0x27a],"I2C xfer timeout: %d\n",
                             *(undefined4 *)((long)plVar17 + 0x1c));
              if (*plVar17 == 0) {
                _printk(&DAT_0010a787,*(undefined4 *)((long)plVar17 + 0x1c));
              }
              else {
                _dev_err(*plVar17,"I2C xfer timeout: %d\n");
              }
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,"I2C xfer timeout: %d\n",
                              *(undefined4 *)((long)plVar17 + 0x1c));
              }
              ipc_log_string(plVar17[0x27a],&DAT_0010acbc,"I2C TXN timed out");
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,&DAT_0010acbc,"I2C TXN timed out");
              }
              geni_i2c_se_dump_dbg_regs(plVar2,plVar17[1],plVar17[0x27a]);
              *(undefined4 *)(plVar17 + 3) = 0xffffff92;
              uVar4 = readl_relaxed(plVar17[1] + 0x908);
              if (((uVar4 ^ 0xffffffff) & 3) == 0) goto LAB_00104604;
              ipc_log_string(plVar17[0x27a],"%s: IO lines not good: 0x%x\n","geni_i2c_execute_xfer",
                             uVar4);
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,"%s: IO lines not good: 0x%x\n","geni_i2c_execute_xfer",uVar4
                             );
              }
              if (*(char *)((long)plVar17 + 0x2349) == '\0') goto LAB_00104604;
LAB_00104cc4:
              *(undefined1 *)((long)plVar17 + 0x2347) = 1;
              goto LAB_00104cd4;
            }
            if ((*(ushort *)((long)param_2 + lVar10 + -2) & 1) == 0) {
              ipc_log_string(plVar17[0x27a],"%s:Write operation completed for len:%d\n",
                             "geni_i2c_execute_xfer",*(undefined2 *)((long)param_2 + lVar10));
              lVar21 = *plVar17;
              if (lVar21 != 0) {
                pcVar11 = "%s:Write operation completed for len:%d\n";
LAB_001045f8:
                i2c_trace_log(lVar21,pcVar11,"geni_i2c_execute_xfer",
                              *(undefined2 *)((long)param_2 + lVar10));
              }
            }
            else {
              ipc_log_string(plVar17[0x27a],"%s: Read operation completed for len:%d\n",
                             "geni_i2c_execute_xfer",*(undefined2 *)((long)param_2 + lVar10));
              lVar21 = *plVar17;
              if (lVar21 != 0) {
                pcVar11 = "%s: Read operation completed for len:%d\n";
                goto LAB_001045f8;
              }
            }
LAB_00104604:
            if ((int)plVar17[3] != 0) {
              if (*(char *)((long)plVar17 + 0x2349) != '\0') {
                uVar4 = readl_relaxed(plVar17[1] + 0x908);
                if (((uVar4 ^ 0xffffffff) & 3) != 0) {
                  ipc_log_string(plVar17[0x27a],"%s: IO lines not in good state\n",
                                 "geni_i2c_execute_xfer");
                  if (*plVar17 != 0) {
                    i2c_trace_log(*plVar17,"%s: IO lines not in good state\n",
                                  "geni_i2c_execute_xfer");
                  }
                  goto LAB_00104cc4;
                }
                if ((int)plVar17[3] == -0x10) {
                  ipc_log_string(plVar17[0x27a],"%s:run reg68 war\n","geni_i2c_execute_xfer");
                  if (*plVar17 != 0) {
                    i2c_trace_log(*plVar17,"%s:run reg68 war\n","geni_i2c_execute_xfer");
                  }
                  uVar4 = readl_relaxed(plVar17[1] + 0x600);
                  ipc_log_string(plVar17[0x27a],"%s: SE_GENI_M_CMD0:0x%x\n",
                                 "do_reg68_war_for_rtl_se",uVar4);
                  if (((uVar4 >> 2 & 1) != 0) && (*(char *)((long)plVar17 + 0x2349) != '\0')) {
                    uVar4 = readl_relaxed(plVar17[1] + 0x210);
                    ipc_log_string(plVar17[0x27a],"%s: Before WAR REG68:0x%x\n",
                                   "do_reg68_war_for_rtl_se",uVar4);
                    uVar5 = 0x100120;
                    if ((uVar4 & 0x20) != 0) {
                      uVar5 = 0x100110;
                    }
                    writel_relaxed(uVar5,plVar17[1] + 0x210);
                    uVar5 = readl_relaxed(plVar17[1] + 0x210);
                    ipc_log_string(plVar17[0x27a],"%s: After WAR REG68:0x%x\n",
                                   "do_reg68_war_for_rtl_se",uVar5);
                  }
                }
              }
              mutex_unlock(plVar1);
              geni_i2c_stop_with_cancel(plVar17);
              mutex_lock(plVar1);
              if ((char)plVar17[0x471] != '\0') goto LAB_001049f4;
            }
            plVar17[0x278] = 0;
            if (bVar19) {
              if ((int)plVar17[3] != 0) {
                *(undefined4 *)(plVar17 + 0x9c) = 0;
                lVar21 = 0xd58;
                if (*(short *)((long)param_2 + lVar10 + -2) != 1) {
                  lVar21 = 0xc58;
                }
                writel_relaxed(1,plVar17[1] + lVar21);
                mutex_unlock(plVar1);
                wait_for_completion_timeout(plVar17 + 0x9c,0xfa);
                mutex_lock(plVar1);
                if ((char)plVar17[0x471] != '\0') goto LAB_001049f4;
              }
              if (local_78 != 0) {
                geni_se_rx_dma_unprep(plVar2,local_78,*(undefined2 *)((long)param_2 + lVar10));
              }
              if (local_70 != 0) {
                geni_se_tx_dma_unprep(plVar2,local_70,*(undefined2 *)((long)param_2 + lVar10));
              }
              i2c_put_dma_safe_msg_buf(local_98,puVar13,(int)plVar17[3] == 0);
            }
            uVar4 = *(uint *)(plVar17 + 3);
            uVar22 = (ulong)uVar4;
            if (uVar4 != 0) {
              ipc_log_string(plVar17[0x27a],"i2c error :%d\n",uVar4);
              if (*plVar17 != 0) {
                i2c_trace_log(*plVar17,"i2c error :%d\n",(int)plVar17[3]);
              }
              mutex_unlock(plVar1);
              iVar6 = geni_i2c_bus_recovery(plVar17);
              if (iVar6 != 0) {
                ipc_log_string(plVar17[0x27a],"%s:Bus Recovery failed\n","geni_i2c_execute_xfer");
                if (*plVar17 == 0) {
                  _printk(&DAT_0010a989,"geni_i2c_execute_xfer");
                }
                else {
                  _dev_err(*plVar17,"%s:Bus Recovery failed\n","geni_i2c_execute_xfer");
                }
              }
              mutex_lock(plVar1);
              if ((char)plVar17[0x471] != '\0') {
                ipc_log_string(plVar17[0x27a],"%s: SSR Down\n","geni_i2c_execute_xfer");
                lVar18 = *plVar17;
                goto joined_r0x00104a14;
              }
              goto LAB_00104cd4;
            }
            geni_i2c_calc_xfer_time
                      (plVar17,param_2,local_a8,uVar20 & 0xffffffff,"geni_i2c_execute_xfer");
            uVar20 = uVar20 + 1;
            lVar10 = lVar10 + 0x10;
          } while (param_3 != uVar20);
          uVar22 = 0;
        }
LAB_00104cd4:
        lVar21 = plVar17[0x27a];
        lVar10 = sched_clock();
        ipc_log_string(lVar21,"%s Time took for %d xfers = %llu nsecs\n","geni_i2c_execute_xfer",
                       uVar23,lVar10 - lVar18);
        lVar10 = *plVar17;
        if (lVar10 != 0) {
          lVar21 = sched_clock();
          i2c_trace_log(lVar10,"%s Time took for %d xfers = %llu nsecs\n","geni_i2c_execute_xfer",
                        uVar23,lVar21 - lVar18);
        }
      }
      if ((int)uVar22 == 0) {
LAB_00104d2c:
        uVar22 = uVar23;
      }
      if (((char)plVar17[0x468] == '\0') && (*(char *)((long)plVar17 + 0x2342) == '\0')) {
        lVar18 = *plVar17;
        uVar9 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar18 + 0x220) = uVar9;
        __pm_runtime_suspend(*plVar17,0xd);
      }
      *(undefined4 *)((long)plVar17 + 0x234c) = 0;
      plVar17[0xa4] = 0;
      *(undefined4 *)(plVar17 + 3) = 0;
      mutex_unlock(plVar1);
      ipc_log_string(plVar17[0x27a],"i2c txn ret:%d freq=%dHz\n",uVar22,
                     *(undefined4 *)((long)plVar17 + 0x22b4));
      if (*plVar17 != 0) {
        i2c_trace_log(*plVar17,"i2c txn ret:%d freq=%dHz\n",uVar22,
                      *(undefined4 *)((long)plVar17 + 0x22b4));
      }
      lVar18 = plVar17[0x27b];
      if (((lVar18 != 0) && (uVar7 != 0)) && ((int)plVar17[0x27c] != 0)) {
        lVar10 = sched_clock();
        ipc_log_string(lVar18,"%s:took %llu nsec(%llu usec)\n","geni_i2c_xfer",lVar10 - uVar7,
                       (lVar10 - uVar7) / 1000);
      }
      goto LAB_001049b8;
    }
    ipc_log_string(plVar17[0x27a],"IO lines in bad state, Power the slave: geni_ios:%d\n",uVar4);
    if (*plVar17 != 0) {
      i2c_trace_log(*plVar17,"IO lines in bad state, Power the slave: geni_ios:%d\n",uVar4);
    }
    if ((int)plVar17[0x465] == 1) {
      uVar4 = readl_relaxed(plVar17[1] + 0x908);
      if ((uVar4 & 3) == 2) {
        *(undefined4 *)(plVar17 + 3) = 0xfffffff0;
        if ((char)plVar17[0x46a] == '\0') {
          ipc_log_string(plVar17[0x27a],"Bus Recovery not enabled\n");
          goto LAB_00104a2c;
        }
        uVar22 = geni_i2c_bus_recovery(plVar17);
        if ((int)uVar22 != 0) {
          uVar22 = uVar22 & 0xffffffff;
          ipc_log_string(plVar17[0x27a],"%s:Bus Recovery failed\n","i2c_initiate_bus_recovery");
          if (*plVar17 == 0) {
            _printk(&DAT_0010a989,"i2c_initiate_bus_recovery");
          }
          else {
            _dev_err(*plVar17,"%s:Bus Recovery failed\n","i2c_initiate_bus_recovery");
          }
          goto LAB_00104a30;
        }
        *(undefined4 *)(plVar17 + 3) = 0;
      }
      if ((int)plVar17[0x465] != 2) goto LAB_00103fc8;
      uVar22 = 0;
    }
    else {
      ipc_log_string(plVar17[0x27a],"Bus Recovery not supported for GSI\n");
      if (*plVar17 != 0) {
        i2c_trace_log(*plVar17,"Bus Recovery not supported for GSI\n");
      }
LAB_00104a2c:
      uVar22 = 0xfffffffa;
    }
  }
  else {
    mutex_unlock(plVar1);
    if (*(char *)((long)plVar17 + 0x2349) == '\0') {
LAB_00103ec0:
      uVar22 = 0;
      bVar19 = true;
    }
    else {
      uVar4 = readl_relaxed(plVar17[1] + 0x908);
      if (((uVar4 ^ 0xffffffff) & 3) == 0) {
LAB_00103e00:
        if ((int)plVar17[0x465] == 2) {
          pcVar12 = *(code **)(*(long *)plVar17[0x27d] + 0x148);
          if (pcVar12 != (code *)0x0) {
            if (*(int *)(pcVar12 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103e34);
              (*pcVar12)();
            }
            (*pcVar12)();
          }
          *(undefined4 *)(plVar17 + 0x456) = 0;
        }
        else {
          iVar6 = geni_i2c_stop_with_cancel(plVar17);
          if (iVar6 != 0) {
            ipc_log_string(plVar17[0x27a],"%s: geni_i2c_stop_with_cancel failed\n",
                           "do_pending_cancel");
            if (*plVar17 != 0) {
              i2c_trace_log(*plVar17,"%s: geni_i2c_stop_with_cancel failed\n","do_pending_cancel");
            }
          }
        }
        *(undefined1 *)((long)plVar17 + 0x2347) = 0;
        ipc_log_string(plVar17[0x27a],"%s: Pending Cancel done\n","do_pending_cancel");
        if (*plVar17 != 0) {
          i2c_trace_log(*plVar17,"%s: Pending Cancel done\n","do_pending_cancel");
        }
        goto LAB_00103ec0;
      }
      ipc_log_string(plVar17[0x27a],"%s: IOS:0x%x, bad state\n","do_pending_cancel",uVar4);
      if (*plVar17 == 0) {
        _printk(&DAT_0010b0b1,"do_pending_cancel",uVar4);
      }
      else {
        _dev_err(*plVar17,"%s: IOS:0x%x, bad state\n","do_pending_cancel",uVar4);
      }
      writel_relaxed(1,plVar17[1] + 0x20);
      uVar4 = readl_relaxed(plVar17[1] + 0x908);
      if (((uVar4 ^ 0xffffffff) & 3) == 0) {
        ipc_log_string(plVar17[0x27a],"%s: IOS:0x%x restored properly\n","do_pending_cancel",uVar4);
        if (*plVar17 == 0) {
          _printk(&DAT_0010a3d9,"do_pending_cancel",uVar4);
        }
        else {
          _dev_err(*plVar17,"%s: IOS:0x%x restored properly\n","do_pending_cancel",uVar4);
        }
        goto LAB_00103e00;
      }
      ipc_log_string(plVar17[0x27a],"%s: IOS:0x%x, Fix from Slave side\n","do_pending_cancel",uVar4)
      ;
      if (*plVar17 == 0) {
        _printk(&DAT_0010a3b4,"do_pending_cancel",uVar4);
      }
      else {
        _dev_err(*plVar17,"%s: IOS:0x%x, Fix from Slave side\n","do_pending_cancel",uVar4);
      }
      bVar19 = false;
      uVar22 = 0xffffffea;
    }
    mutex_lock(plVar1);
    if ((char)plVar17[0x471] != '\0') {
      ipc_log_string(plVar17[0x27a],"%s: SSR Down\n","geni_i2c_xfer");
      if (*plVar17 != 0) {
        i2c_trace_log(*plVar17,"%s: SSR Down\n","geni_i2c_xfer");
      }
      mutex_unlock(plVar1);
      uVar22 = 0;
      goto LAB_001049b8;
    }
    if (bVar19) goto LAB_00103f20;
  }
LAB_00104a30:
  if ((char)plVar17[0x468] == '\0') {
    lVar18 = *plVar17;
    uVar9 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar18 + 0x220) = uVar9;
    __pm_runtime_suspend(*plVar17,0xd);
  }
  mutex_unlock(plVar1);
  *(undefined4 *)((long)plVar17 + 0x234c) = 0;
LAB_001049b8:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar22;
}



//------------------------------------------------------------
// geni_i2c_func @ 00105020 size=12
// signature: undefined geni_i2c_func(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i2c_func(void)

{
  return 0xefe0009;
}



//------------------------------------------------------------
// pm_runtime_put_noidle @ 0010502c size=76
// signature: undefined pm_runtime_put_noidle(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

void pm_runtime_put_noidle(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 0x1f8);
  iVar5 = *(int *)(param_1 + 0x1f8);
  do {
    if (iVar5 == 0) {
      return;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar5) goto LAB_00105054;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00105054:
    bVar4 = iVar5 == iVar2;
    iVar5 = iVar2;
    if (bVar4) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// geni_i2c_prepare @ 0010508c size=804
// signature: undefined geni_i2c_prepare(void)
// callers: [geni_i2c_runtime_resume, geni_i2c_xfer]
//------------------------------------------------------------

undefined8 geni_i2c_prepare(long *param_1)

{
  long *plVar1;
  char cVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined1 *puVar8;
  long lVar9;
  
  if ((int)param_1[0x465] == 0) {
    plVar1 = param_1 + 0x269;
    uVar4 = readl_relaxed(param_1[0x269] + 0x68);
    if ((uVar4 >> 8 & 0xff) != 3) {
      _dev_err(*param_1,"Invalid proto %d\n");
      if ((char)param_1[0x468] == '\0') {
        geni_se_resources_off(plVar1);
        geni_icc_disable(plVar1);
        if (*(char *)((long)param_1 + 0x2346) != '\0') {
          lVar9 = param_1[0x277];
          clk_disable(lVar9);
          clk_unprepare(lVar9);
          return 0xfffffffa;
        }
      }
      return 0xfffffffa;
    }
    iVar5 = readl_relaxed(param_1[1] + 100);
    if (iVar5 == 0) {
      if (*(char *)((long)param_1 + 0x2346) == '\0') {
        uVar6 = geni_se_get_qup_hw_version(plVar1);
        uVar4 = 0xff0000;
        if (((uVar6 & 0xffe0000) < 0x90001 || uVar6 >> 0x1c != 3) && (uVar6 & 0xc0000000) == 0) {
          uVar4 = 0x3f0000;
        }
        uVar6 = readl_relaxed(*plVar1 + 0xe24);
        uVar4 = (uVar4 & uVar6) >> 0x10;
      }
      else {
        uVar4 = 0x10;
      }
      *(undefined4 *)(param_1 + 0x465) = 1;
      *(uint *)(param_1 + 2) = uVar4 - 1;
      geni_se_init(plVar1,uVar4 - 1,uVar4);
      uVar6 = *(uint *)((long)param_1 + 0x13e4);
      uVar7 = (ulong)uVar6;
      if (*(char *)((long)param_1 + 0x2349) == '\0') {
        if (3 < uVar6) goto LAB_001053ac;
        puVar8 = geni_i2c_clk_map;
      }
      else {
        if (3 < uVar6) {
LAB_001053ac:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1053b0);
          (*pcVar3)();
        }
        puVar8 = geni_i2c_hub_clk_map;
      }
      lVar9 = uVar7 * 8;
      if (*(char *)((long)param_1 + 0x2346) == '\0') {
        writel_relaxed(0,param_1[1] + 0x7c);
      }
      if (lVar9 - 0x15U < 0xffffffffffffffe7) {
LAB_001053a8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x1053ac);
        (*pcVar3)();
      }
      writel_relaxed((uint)(byte)puVar8[uVar7 * 8 + 4] << 4 | 1,param_1[1] + 0x48);
      if (((((lVar9 - 0x14U < 0xffffffffffffffe7) || (lVar9 - 0x13U < 0xffffffffffffffe7)) ||
           (lVar9 - 0x12U < 0xffffffffffffffe7)) ||
          ((lVar9 - 0x13U < 0xffffffffffffffe7 || (lVar9 - 0x14U < 0xffffffffffffffe7)))) ||
         (lVar9 - 0x12U < 0xffffffffffffffe7)) goto LAB_001053a8;
      writel_relaxed((uint)(byte)puVar8[uVar7 * 8 + 6] << 10 |
                     (uint)(byte)puVar8[uVar7 * 8 + 5] << 0x14 | (uint)(byte)puVar8[uVar7 * 8 + 7],
                     param_1[1] + 0x278);
      DataSynchronizationBarrier(3,3,0);
      geni_se_config_packing(plVar1,8,4,1,1,1);
      ipc_log_string(param_1[0x27a],"i2c fifo/se-dma mode. fifo depth:%d\n",uVar4);
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"i2c fifo/se-dma mode. fifo depth:%d\n",uVar4);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x465) = 2;
      geni_se_select_mode(plVar1,3);
      ipc_log_string(param_1[0x27a],"i2c in GSI ONLY mode\n");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"i2c in GSI ONLY mode\n");
      }
    }
    if ((*(char *)((long)param_1 + 0x2346) == '\0') &&
       (uVar4 = readl_relaxed(param_1[1] + 0xe2c), (uVar4 >> 0xf & 1) != 0)) {
      *(undefined1 *)((long)param_1 + 0x2349) = 1;
      _dev_info(*param_1,"%s: RTL based SE\n","geni_i2c_prepare");
      cVar2 = *(char *)((long)param_1 + 0x2342);
    }
    else {
      cVar2 = *(char *)((long)param_1 + 0x2342);
    }
    if (cVar2 != '\0') {
      ipc_log_string(param_1[0x27a],"%s: pm_runtime_get_sync bypassed\n","geni_i2c_prepare");
      if (*param_1 == 0) {
        return 0;
      }
      i2c_trace_log(*param_1,"%s: pm_runtime_get_sync bypassed\n","geni_i2c_prepare");
    }
  }
  return 0;
}



//------------------------------------------------------------
// geni_i2c_lock_bus @ 001053b0 size=832
// signature: undefined geni_i2c_lock_bus(void)
// callers: [geni_i2c_runtime_resume, geni_i2c_xfer, geni_i2c_gsi_xfer]
//------------------------------------------------------------

ulong geni_i2c_lock_bus(long *param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined4 uVar7;
  ulong *puVar8;
  long lVar9;
  
  lVar9 = param_1[0x27b];
  if (lVar9 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar1 = *(char *)((long)param_1 + 0x2343);
  }
  else if ((int)param_1[0x27c] == 0) {
    uVar4 = 0;
    cVar1 = *(char *)((long)param_1 + 0x2343);
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar9,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_lock_bus",uVar4,uVar4 / 1000
                  );
    cVar1 = *(char *)((long)param_1 + 0x2343);
  }
  if ((cVar1 == '\0') && (uVar5 = geni_i2c_gsi_request_channel(param_1), (int)uVar5 != 0)) {
    return uVar5;
  }
  param_1[0x27f] = 0;
  *(undefined4 *)(param_1 + 0x280) = 0;
  if (*(char *)((long)param_1 + 0x232d) == '\0') {
    if ((char)param_1[0x468] == '\0') goto LAB_0010549c;
    uVar7 = 0x300100;
  }
  else {
    uVar7 = 0x300001;
    if ((char)param_1[0xa7] != '\0') {
      uVar7 = 0x300401;
    }
  }
  *(undefined4 *)((long)param_1 + 0x1404) = uVar7;
LAB_0010549c:
  sg_init_table(param_1[0x452],1);
  puVar8 = (ulong *)param_1[0x452];
  *puVar8 = (*puVar8 & 3 | (((long)(param_1 + 0x27f) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
            0x200000000;
  *(uint *)(puVar8 + 1) = (uint)(param_1 + 0x27f) & 0xfff;
  *(undefined4 *)((long)puVar8 + 0xc) = 0x10;
  lVar9 = geni_i2c_prep_desc(param_1,1,1);
  param_1[0x457] = lVar9;
  if (lVar9 == 0) {
    uVar7 = 0xfffffff4;
  }
  else {
    *(undefined1 *)((long)param_1 + 0x2341) = 1;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    if (*(int *)(*(code **)(lVar9 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105520);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(lVar9 + 0x18))();
    if (iVar3 < 0) {
      ipc_log_string(param_1[0x27a],"%s: dmaengine_submit failed (%d)\n","geni_i2c_lock_bus",iVar3);
      if (*param_1 == 0) {
        _printk(&DAT_0010b073,"geni_i2c_lock_bus",iVar3);
      }
      else {
        _dev_err(*param_1,"%s: dmaengine_submit failed (%d)\n","geni_i2c_lock_bus",iVar3);
      }
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s: dmaengine_submit failed (%d)\n","geni_i2c_lock_bus",iVar3);
      }
      uVar7 = 0xffffffea;
    }
    else {
      if (*(int *)(*(code **)(*(long *)param_1[0x27d] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105550);
        (*pcVar2)();
      }
      (**(code **)(*(long *)param_1[0x27d] + 0x160))();
      iVar3 = wait_for_completion_timeout(param_1 + 0x9c,0xfa);
      if (iVar3 != 0) {
        *(undefined1 *)((long)param_1 + 0x2341) = 0;
        return 0;
      }
      ipc_log_string(param_1[0x27a],"%s timedout\n","geni_i2c_lock_bus");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s timedout\n","geni_i2c_lock_bus");
      }
      geni_i2c_se_dump_dbg_regs(param_1 + 0x269,param_1[1],param_1[0x27a]);
      uVar7 = 0xffffff92;
    }
  }
  *(undefined4 *)(param_1 + 3) = uVar7;
  pcVar2 = *(code **)(*(long *)param_1[0x27d] + 0x148);
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1055f4);
      (*pcVar2)();
    }
    (*pcVar2)();
  }
  lVar9 = param_1[0x27b];
  *(undefined4 *)(param_1 + 0x456) = 0;
  *(undefined1 *)((long)param_1 + 0x2341) = 0;
  if (((lVar9 != 0) && (uVar4 != 0)) && ((int)param_1[0x27c] != 0)) {
    lVar6 = sched_clock();
    ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","geni_i2c_lock_bus",lVar6 - uVar4,
                   (lVar6 - uVar4) / 1000);
  }
  return (ulong)*(uint *)(param_1 + 3);
}



//------------------------------------------------------------
// geni_i2c_gsi_xfer @ 001056f0 size=6888
// signature: undefined geni_i2c_gsi_xfer(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int geni_i2c_gsi_xfer(long param_1,long param_2,uint param_3)

{
  ushort *puVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  long *plVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  ushort uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  uint uVar15;
  int iVar16;
  code *pcVar17;
  bool bVar18;
  int iVar19;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  long lVar23;
  ulong uVar24;
  ulong uVar25;
  ulong uVar26;
  long lVar27;
  undefined8 uVar28;
  char *pcVar29;
  ushort uVar30;
  uint uVar31;
  undefined1 uVar32;
  ushort *puVar33;
  ulong *puVar34;
  uint uVar35;
  undefined1 *puVar36;
  ushort *puVar37;
  long *plVar38;
  long lVar39;
  ulong uVar40;
  ushort *puVar41;
  uint uVar42;
  long *plVar43;
  long *plVar44;
  ulong uVar45;
  long lVar46;
  int iVar47;
  ulong uVar48;
  long *plVar49;
  ulong local_f0;
  uint local_80;
  
  plVar38 = *(long **)(param_1 + 0x108);
  plVar3 = plVar38 + 0x287;
  lVar23 = sched_clock();
  *(undefined1 *)(plVar38 + 0x469) = 0;
  if ((*(char *)((long)plVar38 + 0x2343) == '\0') &&
     (iVar19 = geni_i2c_gsi_request_channel(plVar38), iVar19 != 0)) {
    return iVar19;
  }
  if (((char)plVar38[0x468] != '\0') && (*(char *)((long)plVar38 + 0x2345) != '\0')) {
    ipc_log_string(plVar38[0x27a],"%s doing gsi lock, due to levm gsi reset\n","geni_i2c_gsi_xfer");
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"%s doing gsi lock, due to levm gsi reset\n","geni_i2c_gsi_xfer");
    }
    iVar19 = geni_i2c_lock_bus(plVar38);
    if (iVar19 != 0) {
      ipc_log_string(plVar38[0x27a],"%s lock bus failed: %d\n","geni_i2c_gsi_xfer",iVar19);
      if (*plVar38 == 0) {
        _printk(&DAT_0010b69e,"geni_i2c_gsi_xfer",iVar19);
      }
      else {
        _dev_err(*plVar38,"%s lock bus failed: %d\n","geni_i2c_gsi_xfer",iVar19);
      }
      if (*plVar38 == 0) {
        return iVar19;
      }
      i2c_trace_log(*plVar38,"%s lock bus failed: %d\n","geni_i2c_gsi_xfer",iVar19);
      return iVar19;
    }
    *(undefined1 *)((long)plVar38 + 0x2345) = 0;
  }
  if (*(char *)((long)plVar38 + 0x232d) == '\0') {
    plVar43 = (long *)0x0;
    plVar49 = (long *)0x0;
    if (3 < (int)param_3) goto LAB_001057f0;
LAB_00105848:
    uVar32 = 0;
    *(undefined1 *)(plVar38 + 0xa7) = 0;
  }
  else {
    plVar38[0x27f] = 0;
    *(undefined4 *)(plVar38 + 0x280) = 0;
    uVar20 = 0x300001;
    if ((char)plVar38[0xa7] != '\0') {
      uVar20 = 0x300401;
    }
    plVar43 = plVar38 + 0x27f;
    plVar49 = plVar38 + 0x281;
    plVar38[0x281] = 0;
    *(undefined4 *)((long)plVar38 + 0x1404) = uVar20;
    plVar38[0x282] = 0x31010000000000;
    if ((int)param_3 < 4) goto LAB_00105848;
LAB_001057f0:
    uVar32 = 1;
    puVar33 = (ushort *)(param_2 + 2);
    *(undefined1 *)(plVar38 + 0xa7) = 1;
    uVar48 = (ulong)param_3;
    do {
      if ((*puVar33 & 1) != 0) {
        uVar32 = 0;
        *(undefined1 *)(plVar38 + 0xa7) = 0;
      }
      uVar48 = uVar48 - 1;
      puVar33 = puVar33 + 8;
    } while (uVar48 != 0);
  }
  gpi_update_multi_desc_flag(plVar38[0x27d],uVar32,(ulong)param_3);
  if ((int)plVar38[0x456] == 0) {
    uVar7 = *(uint *)((long)plVar38 + 0x13e4);
    uVar48 = (ulong)uVar7;
    if (*(char *)((long)plVar38 + 0x2349) == '\0') {
      if (3 < uVar7) goto LAB_001071dc;
      puVar36 = geni_i2c_clk_map;
    }
    else {
      if (3 < uVar7) {
LAB_001071dc:
                    /* WARNING: Does not return */
        pcVar17 = (code *)SoftwareBreakpoint(0x5512,0x1071e0);
        (*pcVar17)();
      }
      puVar36 = geni_i2c_hub_clk_map;
    }
    lVar39 = uVar48 * 8;
    if (((lVar39 - 0x12U < 0xffffffffffffffe7) || (lVar39 - 0x14U < 0xffffffffffffffe7)) ||
       (lVar39 - 0x13U < 0xffffffffffffffe7)) {
LAB_001071e0:
                    /* WARNING: Does not return */
      pcVar17 = (code *)SoftwareBreakpoint(1,0x1071e4);
      (*pcVar17)();
    }
    bVar8 = puVar36[uVar48 * 8 + 7];
    bVar9 = puVar36[uVar48 * 8 + 5];
    bVar10 = puVar36[uVar48 * 8 + 6];
    *(undefined4 *)((long)plVar38 + 0x141c) = 0;
    uVar7 = (uint)bVar8 << 0x10 | (uint)bVar9 << 8 | (uint)bVar10 | 0x3000000;
    *(uint *)(plVar38 + 0x283) = uVar7;
    if (lVar39 - 0x15U < 0xffffffffffffffe7) goto LAB_001071e0;
    plVar44 = plVar38 + 0x283;
    *(uint *)(plVar38 + 0x284) = (uint)(byte)puVar36[uVar48 * 8 + 4];
    *(uint *)((long)plVar38 + 0x1424) = (uint)*(byte *)(plVar38 + 0xa7) << 10 | 0x220001;
    ipc_log_string(plVar38[0x27a],"cfg_tre 0x%x 0x%x 0x%x 0x%x\n",uVar7,0);
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"cfg_tre 0x%x 0x%x 0x%x 0x%x\n",(int)plVar38[0x283],
                    *(undefined4 *)((long)plVar38 + 0x141c),(int)plVar38[0x284],
                    *(undefined4 *)((long)plVar38 + 0x1424));
    }
  }
  else {
    plVar44 = (long *)0x0;
  }
  plVar38[0xa5] = param_2;
  plVar38[0xa6] = 0;
  *(undefined4 *)(plVar38 + 0xa8) = 0;
  *(undefined4 *)((long)plVar38 + 0x53c) = 0;
  *(undefined4 *)(plVar38 + 0x9c) = 0;
  if (param_3 == 0) {
    iVar22 = 0;
    cVar11 = (char)plVar38[0xa7];
joined_r0x001071a8:
    if (cVar11 != '\0') {
      gpi_update_multi_desc_flag(plVar38[0x27d],0,0);
    }
    if (iVar22 == 0) {
      iVar22 = (int)plVar38[3];
    }
    lVar46 = plVar38[0x27a];
    lVar39 = sched_clock();
    ipc_log_string(lVar46,"%s Time took for %d xfers = %llu nsecs\n","geni_i2c_gsi_xfer",param_3,
                   lVar39 - lVar23);
    lVar39 = *plVar38;
    if (lVar39 != 0) {
      lVar46 = sched_clock();
      i2c_trace_log(lVar39,"%s Time took for %d xfers = %llu nsecs\n","geni_i2c_gsi_xfer",param_3,
                    lVar46 - lVar23);
    }
    return iVar22;
  }
  plVar2 = plVar38 + 0x9c;
  uVar48 = 0;
  local_80 = 0;
  local_f0 = 0;
  iVar16 = param_3 - 1;
  iVar19 = 1;
  if (param_3 == 1) {
    iVar19 = 2;
  }
  plVar4 = plVar38 + 1099;
  uVar5 = ((((long)plVar49 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
  uVar7 = (uint)plVar49 & 0xfff;
  uVar15 = param_3 >> 6;
  if ((param_3 & 0x3f) != 0) {
    uVar15 = uVar15 + 1;
  }
LAB_00105a9c:
  lVar39 = plVar38[0x27b];
  if (lVar39 == 0) {
    uVar24 = 0xffffffffffffffea;
  }
  else if ((int)plVar38[0x27c] == 0) {
    uVar24 = 0;
  }
  else {
    uVar24 = sched_clock();
    ipc_log_string(lVar39,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_gsi_xfer",uVar24,
                   uVar24 / 1000);
  }
  lVar39 = param_2 + uVar48 * 0x10;
  puVar33 = (ushort *)(lVar39 + 2);
  uVar30 = *puVar33;
  plVar38[0xa4] = lVar39;
  iVar22 = 1;
  if ((uVar30 & 1) == 0) {
    iVar22 = 2;
  }
  if (lVar39 == 0) {
    ipc_log_string(plVar38[0x27a],"%s: Invalid buffer\n","geni_i2c_gsi_xfer");
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"%s: Invalid buffer\n","geni_i2c_gsi_xfer");
      iVar22 = -0xc;
      cVar11 = (char)plVar38[0xa7];
      goto joined_r0x001071a8;
    }
    iVar22 = -0xc;
    goto LAB_00106ecc;
  }
  uVar42 = *(uint *)((long)plVar38 + 0x13e4);
  puVar37 = (ushort *)(param_2 + uVar48 * 0x10 + 4);
  if (*(char *)((long)plVar38 + 0x2349) == '\0') {
    if (3 < uVar42) goto LAB_001071dc;
    puVar36 = geni_i2c_clk_map;
  }
  else {
    if (3 < uVar42) goto LAB_001071dc;
    puVar36 = geni_i2c_hub_clk_map;
  }
  if (2 < (ulong)uVar42) goto LAB_001071e0;
  uVar40 = 0;
  if ((ulong)*(uint *)(puVar36 + (ulong)uVar42 * 8) != 0) {
    uVar40 = ((ulong)*puVar37 * 9000000) / (ulong)*(uint *)(puVar36 + (ulong)uVar42 * 8);
  }
  uVar40 = uVar40 * 10 + 500000;
  uVar20 = __usecs_to_jiffies(uVar40 & 0xffffffff);
  *(undefined4 *)((long)plVar38 + 0x1c) = uVar20;
  ipc_log_string(plVar38[0x27a],"%s: us:%d jiffies:%d\n","qcom_geni_i2c_calc_timeout",uVar40);
  if (*plVar38 != 0) {
    i2c_trace_log(*plVar38,"%s: us:%d jiffies:%d\n","qcom_geni_i2c_calc_timeout",uVar40,
                  *(undefined4 *)((long)plVar38 + 0x1c));
  }
  if ((int)plVar38[0x456] == 0) {
    iVar22 = iVar22 + 1;
  }
  iVar47 = (int)uVar48;
  if ((*(char *)((long)plVar38 + 0x232d) == '\0') || ((iVar47 != 0 && (iVar47 != iVar16)))) {
    sg_init_table(plVar38[0x452]);
    iVar21 = (int)plVar38[0x456];
joined_r0x00105c40:
    uVar40 = 0;
  }
  else {
    iVar22 = iVar22 + iVar19;
    sg_init_table(plVar38[0x452]);
    if (iVar47 != 0) {
      iVar21 = (int)plVar38[0x456];
      goto joined_r0x00105c40;
    }
    puVar34 = (ulong *)plVar38[0x452];
    uVar40 = 1;
    *puVar34 = *puVar34 & 3 |
               ((((long)plVar43 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
    *(uint *)(puVar34 + 1) = (uint)plVar43 & 0xfff;
    *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
    iVar21 = (int)plVar38[0x456];
  }
  if (iVar21 == 0) {
    puVar34 = (ulong *)(plVar38[0x452] + uVar40 * 0x20);
    *(uint *)(puVar34 + 1) = (uint)plVar44 & 0xfff;
    *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
    *puVar34 = *puVar34 & 3 |
               ((((long)plVar44 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
    *(undefined4 *)(plVar38 + 0x456) = 1;
    uVar40 = (ulong)((int)uVar40 + 1);
  }
  puVar1 = (ushort *)(param_2 + (long)iVar47 * 0x10);
  uVar30 = puVar1[1];
  uVar12 = *puVar1;
  *(undefined4 *)((long)plVar38 + 0x142c) = 0;
  uVar42 = 1;
  if ((uVar30 & 1) != 0) {
    uVar42 = 2;
  }
  uVar42 = (uint)(iVar47 < iVar16) << 0x1a | (uint)uVar12 << 8 | uVar42;
  lVar46 = (long)iVar47;
  *(uint *)(plVar38 + 0x285) = uVar42;
  if ((puVar1[1] & 1) == 0) {
    uVar30 = 0;
    uVar31 = (uint)*(byte *)(plVar38 + 0xa7) << 10 | 0x200001;
    *(undefined4 *)(plVar38 + 0x286) = 0;
  }
  else {
    uVar30 = *(ushort *)(param_2 + lVar46 * 0x10 + 4);
    iVar21 = 0x7ff;
    if (*(char *)((long)plVar38 + 0x232d) == '\0' || iVar16 != iVar47) {
      iVar21 = 0x8ff;
    }
    uVar31 = iVar21 + 0x200001;
    *(uint *)(plVar38 + 0x286) = (uint)uVar30;
  }
  *(uint *)((long)plVar38 + 0x1434) = uVar31;
  ipc_log_string(plVar38[0x27a],"go_tre 0x%x 0x%x 0x%x 0x%x\n",uVar42,0,uVar30);
  if (*plVar38 != 0) {
    i2c_trace_log(*plVar38,"go_tre 0x%x 0x%x 0x%x 0x%x\n",(int)plVar38[0x285],
                  *(undefined4 *)((long)plVar38 + 0x142c),(int)plVar38[0x286],
                  *(undefined4 *)((long)plVar38 + 0x1434));
  }
  uVar45 = (ulong)((int)uVar40 + 1);
  puVar34 = (ulong *)(plVar38[0x452] + uVar40 * 0x20);
  *puVar34 = *puVar34 & 3 |
             (((long)(plVar38 + 0x285) * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
  *(uint *)(puVar34 + 1) = (uint)(plVar38 + 0x285) & 0xfff;
  *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
  if ((*puVar33 & 1) != 0) {
    *(undefined4 *)(plVar38 + 0x9c) = 0;
    uVar40 = i2c_get_dma_safe_msg_buf(puVar1,1);
    if (uVar40 == 0) {
      ipc_log_string(plVar38[0x27a],"i2c_get_dma_safe_msg_buf failed :%d\n",0xfffffff4);
      if (*plVar38 == 0) {
        _printk(&DAT_00109907,0xfffffff4);
      }
      else {
        _dev_err(*plVar38,"i2c_get_dma_safe_msg_buf failed :%d\n",0xfffffff4);
      }
      if (*plVar38 != 0) {
        i2c_trace_log(*plVar38,"i2c_get_dma_safe_msg_buf failed :%d\n",0xfffffff4);
      }
      goto LAB_00107198;
    }
    ipc_log_string(plVar38[0x27a],"msg[%d].len:%d R\n",uVar48,*(undefined2 *)(plVar38[0xa4] + 4));
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"msg[%d].len:%d R\n",uVar48,*(undefined2 *)(plVar38[0xa4] + 4));
    }
    sg_init_table(plVar38[0x453],1);
    plVar49 = (long *)plVar38[0x279];
    if (plVar49 == (long *)0x0) {
      uVar28 = 0xffffffea;
    }
    else {
      puVar41 = (ushort *)(param_2 + lVar46 * 0x10 + 4);
      uVar30 = *puVar41;
      uVar25 = is_vmalloc_addr(uVar40);
      if (((uVar25 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar28 = dev_driver_string(plVar49);
        lVar23 = plVar49[0xe];
        if (lVar23 == 0) {
          lVar23 = *plVar49;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar28,lVar23);
                    /* WARNING: Does not return */
        pcVar17 = (code *)SoftwareBreakpoint(0x800,0x106df0);
        (*pcVar17)();
      }
      if ((uVar25 & 1) == 0) {
        lVar27 = dma_map_page_attrs(plVar49,(((long)(uVar40 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                            0x40 + -0x200000000,uVar40 & 0xfff,uVar30,2,0);
        *plVar4 = lVar27;
        if (lVar27 != -1) {
          if (plVar38[0x467] != 0) {
            *(ulong *)(plVar38[0x467] + lVar46 * 0x10) = uVar40;
            *(long **)(plVar38[0x467] + lVar46 * 0x10 + 8) = plVar4;
            lVar27 = plVar38[1099];
          }
          plVar38[0x289] = lVar27;
          uVar30 = *puVar41;
          puVar34 = (ulong *)plVar38[0x453];
          *(undefined4 *)((long)plVar38 + 0x1454) = 0x100200;
          *(uint *)(plVar38 + 0x28a) = (uint)uVar30;
          *puVar34 = *puVar34 & 3 |
                     (((long)(plVar38 + 0x289) * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 -
                     0x200000000;
          *(uint *)(puVar34 + 1) = (uint)(plVar38 + 0x289) & 0xfff;
          *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
          lVar46 = geni_i2c_prep_desc(plVar38,iVar22,0);
          plVar38[0x458] = lVar46;
          if (lVar46 == 0) {
            uVar20 = 0xfffffff4;
LAB_00106248:
            *(undefined4 *)(plVar38 + 3) = uVar20;
            goto LAB_00106254;
          }
          if (*(int *)(*(code **)(lVar46 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x106098);
            (*pcVar17)();
          }
          iVar21 = (**(code **)(lVar46 + 0x18))();
          if (iVar21 < 0) {
            _printk(&DAT_0010b073,"geni_i2c_gsi_read",iVar21);
            uVar20 = 0xffffffea;
            goto LAB_00106248;
          }
          if (*(int *)(*(code **)(*(long *)plVar38[0x27e] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x1060cc);
            (*pcVar17)();
          }
          (**(code **)(*(long *)plVar38[0x27e] + 0x160))();
          if ((iVar16 == iVar47) && (*(char *)((long)plVar38 + 0x232d) != '\0')) {
            puVar34 = (ulong *)(plVar38[0x452] + uVar45 * 0x20);
            *puVar34 = *puVar34 & 3 | uVar5;
            *(uint *)(puVar34 + 1) = uVar7;
            *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
          }
          lVar46 = geni_i2c_prep_desc(plVar38,iVar22,1);
          plVar38[0x457] = lVar46;
          if (lVar46 == 0) {
            *(undefined4 *)(plVar38 + 3) = 0xfffffff4;
            ipc_log_string(plVar38[0x27a],"geni_i2c_prep_desc failed\n");
            if (*plVar38 == 0) {
              _printk(&DAT_0010a3fb);
            }
            else {
              _dev_err(*plVar38,"geni_i2c_prep_desc failed\n");
            }
            lVar46 = *plVar38;
            goto joined_r0x001069cc;
          }
          if (*(int *)(*(code **)(lVar46 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x106154);
            (*pcVar17)();
          }
          iVar22 = (**(code **)(lVar46 + 0x18))();
          if (iVar22 < 0) {
            ipc_log_string(plVar38[0x27a],"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_read",
                           iVar22);
            if (*plVar38 == 0) {
              _printk(&DAT_0010b073,"geni_i2c_gsi_read",iVar22);
            }
            else {
              _dev_err(*plVar38,"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_read",iVar22);
            }
            lVar46 = *plVar38;
            if (lVar46 != 0) {
              pcVar29 = "geni_i2c_gsi_read";
              goto LAB_00106a00;
            }
            goto LAB_00106a08;
          }
          if (*(int *)(*(code **)(*(long *)plVar38[0x27d] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x106184);
            (*pcVar17)();
          }
          (**(code **)(*(long *)plVar38[0x27d] + 0x160))();
          iVar22 = wait_for_completion_timeout(plVar2,*(undefined4 *)((long)plVar38 + 0x1c));
          local_f0 = uVar40;
          goto LAB_00106ae4;
        }
      }
      else {
        *plVar4 = -1;
      }
      uVar28 = 0xfffffffb;
    }
    ipc_log_string(plVar38[0x27a],"geni_se_common_iommu_map_buf for rx failed :%d\n",uVar28);
    if (*plVar38 == 0) {
      _printk(&DAT_0010b263,uVar28);
    }
    else {
      _dev_err(*plVar38,"geni_se_common_iommu_map_buf for rx failed :%d\n",uVar28);
    }
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"geni_se_common_iommu_map_buf for rx failed :%d\n",uVar28);
    }
    i2c_put_dma_safe_msg_buf(uVar40,puVar1,0);
LAB_00107198:
    geni_i2c_stop_on_bus(plVar38);
    iVar22 = (int)plVar38[3];
    cVar11 = (char)plVar38[0xa7];
    goto joined_r0x001071a8;
  }
  puVar41 = (ushort *)(param_2 + lVar46 * 0x10 + 4);
  if (8 < *puVar41) {
    uVar25 = i2c_get_dma_safe_msg_buf(puVar1,1);
    plVar38[(ulong)local_80 + 0xa9] = uVar25;
    if (uVar25 == 0) {
      *(undefined4 *)(plVar38 + 3) = 0xfffffff4;
      ipc_log_string(plVar38[0x27a],"i2c_get_dma_safe_msg_buf failed :%d\n",0);
      if (*plVar38 == 0) {
        _printk(&DAT_00109907,0);
      }
      else {
        _dev_err(*plVar38,"i2c_get_dma_safe_msg_buf failed :%d\n",0);
      }
      if (*plVar38 != 0) {
        i2c_trace_log(*plVar38,"i2c_get_dma_safe_msg_buf failed :%d\n",0);
      }
      goto LAB_00107198;
    }
    if (0x1c0 < local_80) goto LAB_001071dc;
    plVar49 = (long *)plVar38[0x279];
    if (plVar49 == (long *)0x0) {
      uVar20 = 0xffffffea;
    }
    else {
      uVar30 = *puVar41;
      uVar26 = is_vmalloc_addr();
      if (((uVar26 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar28 = dev_driver_string(plVar49);
        lVar23 = plVar49[0xe];
        if (lVar23 == 0) {
          lVar23 = *plVar49;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar28,lVar23);
                    /* WARNING: Does not return */
        pcVar17 = (code *)SoftwareBreakpoint(0x800,0x106e2c);
        (*pcVar17)();
      }
      plVar6 = plVar38 + (ulong)local_80 + 0x28b;
      if ((uVar26 & 1) == 0) {
        lVar27 = dma_map_page_attrs(plVar49,(((long)(uVar25 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                            0x40 + -0x200000000,uVar25 & 0xfff,uVar30,1,0);
        *plVar6 = lVar27;
        if (lVar27 != -1) {
          if (plVar38[0x467] != 0) {
            lVar27 = (ulong)local_80 * 0x10;
            *(long *)(plVar38[0x467] + lVar27) = plVar38[(ulong)local_80 + 0xa9];
            *(long **)(plVar38[0x467] + lVar27 + 8) = plVar6;
          }
          goto LAB_00105e9c;
        }
      }
      else {
        *plVar6 = -1;
      }
      uVar20 = 0xfffffffb;
    }
    ipc_log_string(plVar38[0x27a],"geni iommu_map_buf for tx failed :%d\n",uVar20);
    if (*plVar38 == 0) {
      _printk(&DAT_00109ce8,uVar20);
    }
    else {
      _dev_err(*plVar38,"geni iommu_map_buf for tx failed :%d\n",uVar20);
    }
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"geni iommu_map_buf for tx failed :%d\n",uVar20);
    }
    i2c_put_dma_safe_msg_buf(plVar38[(ulong)local_80 + 0xa9],puVar1,0);
    *(undefined4 *)(plVar38 + 3) = uVar20;
    goto LAB_00107198;
  }
LAB_00105e9c:
  ipc_log_string(plVar38[0x27a],"msg[%d].len:%d W cnt:%d idx:%d\n",uVar48,
                 *(undefined2 *)(plVar38[0xa4] + 4),(int)plVar38[0xa6],local_80);
  if (*plVar38 != 0) {
    i2c_trace_log(*plVar38,"msg[%d].len:%d W cnt:%d idx:%d\n",uVar48,
                  *(undefined2 *)(plVar38[0xa4] + 4),(int)plVar38[0xa6],local_80);
  }
  uVar30 = *puVar41;
  if ((char)plVar38[0xa7] == '\0') {
    uVar42 = 0;
  }
  else {
    uVar42 = (uint)((iVar47 + 1U & 0x3f) != 0);
    if (iVar16 == iVar47) {
      uVar42 = (uint)*(byte *)((long)plVar38 + 0x232d);
    }
  }
  if (uVar30 < 9) {
    plVar38[0x287] = 0;
    uVar25 = (ulong)*puVar41;
    if (uVar25 == 0) {
      uVar31 = 0;
    }
    else {
      puVar36 = *(undefined1 **)(param_2 + lVar46 * 0x10 + 8);
      plVar49 = plVar3;
      do {
        uVar25 = uVar25 - 1;
        *(undefined1 *)plVar49 = *puVar36;
        puVar36 = puVar36 + 1;
        plVar49 = (long *)((long)plVar49 + 1);
      } while (uVar25 != 0);
      uVar31 = *puVar41 & 0xf;
    }
    *(uint *)(plVar38 + 0x288) = uVar31;
    if ((iVar16 == iVar47) && (*(char *)((long)plVar38 + 0x232d) != '\0')) {
      uVar35 = 0x110201;
    }
    else {
      uVar35 = 0x110200;
    }
  }
  else {
    if (0x1bf < local_80) goto LAB_001071dc;
    plVar38[0x287] = plVar38[(ulong)local_80 + 0x28b];
    uVar31 = (uint)*puVar41;
    *(uint *)(plVar38 + 0x288) = (uint)*puVar41;
    if ((iVar16 == iVar47) && (*(char *)((long)plVar38 + 0x232d) != '\0')) {
      uVar35 = 0x100201;
    }
    else {
      uVar35 = 0x100200;
    }
  }
  uVar35 = uVar42 << 10 | uVar35;
  *(uint *)((long)plVar38 + 0x1444) = uVar35;
  ipc_log_string(plVar38[0x27a],"tx_tre 0x%x 0x%x 0x%x 0x%x imm_dma:%d bei:%d\n",(int)plVar38[0x287]
                 ,*(undefined4 *)((long)plVar38 + 0x143c),uVar31,uVar35,uVar30 < 9,uVar42);
  if (*plVar38 != 0) {
    i2c_trace_log(*plVar38,"tx_tre 0x%x 0x%x 0x%x 0x%x imm_dma:%d bei:%d\n",(int)plVar38[0x287],
                  *(undefined4 *)((long)plVar38 + 0x143c),(int)plVar38[0x288],
                  *(undefined4 *)((long)plVar38 + 0x1444),uVar30 < 9,uVar42);
  }
  puVar34 = (ulong *)(plVar38[0x452] + uVar45 * 0x20);
  *puVar34 = *puVar34 & 3 |
             (((long)plVar3 * 0x100 >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
  *(uint *)(puVar34 + 1) = (uint)plVar3 & 0xfff;
  *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
  if ((iVar16 == iVar47) && (*(char *)((long)plVar38 + 0x232d) != '\0')) {
    puVar34 = (ulong *)(plVar38[0x452] + (ulong)((int)uVar40 + 2) * 0x20);
    *puVar34 = *puVar34 & 3 | uVar5;
    *(uint *)(puVar34 + 1) = uVar7;
    *(undefined4 *)((long)puVar34 + 0xc) = 0x10;
    if ((char)plVar38[0xa7] != '\0') {
      uVar42 = 0;
    }
  }
  local_80 = (iVar47 + 1) % 0x1c0;
  lVar46 = geni_i2c_prep_desc(plVar38,iVar22,1);
  plVar38[0x457] = lVar46;
  if (lVar46 != 0) {
    if (uVar42 != 0) {
      ipc_log_string(plVar38[0x27a],"geni tx desc call back null %d\n",uVar48);
      if (*plVar38 != 0) {
        i2c_trace_log(*plVar38,"geni tx desc call back null %d\n",uVar48);
      }
      *(undefined8 *)(plVar38[0x457] + 0x28) = 0;
      *(undefined8 *)(plVar38[0x457] + 0x38) = 0;
    }
    iVar22 = (int)plVar38[0xa6] + 1;
    *(int *)(plVar38 + 0xa6) = iVar22;
    ipc_log_string(plVar38[0x27a],"tx_cnt:%d wr_index: %d\n",iVar22,local_80);
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"tx_cnt:%d wr_index: %d\n",(int)plVar38[0xa6],local_80);
    }
    if (*(int *)(*(code **)(plVar38[0x457] + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x1064a0);
      (*pcVar17)();
    }
    iVar22 = (**(code **)(plVar38[0x457] + 0x18))();
    if (iVar22 < 0) {
      ipc_log_string(plVar38[0x27a],"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_write",iVar22
                    );
      if (*plVar38 == 0) {
        _printk(&DAT_0010b073,"geni_i2c_gsi_write",iVar22);
      }
      else {
        _dev_err(*plVar38,"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_write",iVar22);
      }
      lVar46 = *plVar38;
      if (lVar46 != 0) {
        pcVar29 = "geni_i2c_gsi_write";
LAB_00106a00:
        i2c_trace_log(lVar46,"%s: dmaengine_submit failed (%d)\n",pcVar29,iVar22);
      }
LAB_00106a08:
      *(undefined4 *)(plVar38 + 3) = 0xffffffea;
      goto LAB_00106254;
    }
    if (*(int *)(*(code **)(*(long *)plVar38[0x27d] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x1064cc);
      (*pcVar17)();
    }
    (**(code **)(*(long *)plVar38[0x27d] + 0x160))();
    if ((((char)plVar38[0xa7] != '\0') && (iVar16 != iVar47)) &&
       (*(uint *)(plVar38 + 0xa6) < *(int *)((long)plVar38 + 0x534) + 0x1c0U)) {
      iVar22 = 0;
      goto joined_r0x0010650c;
    }
    lVar46 = plVar38[0x27b];
    if (lVar46 == 0) {
      uVar40 = 0xffffffffffffffea;
joined_r0x00106668:
      if ((char)plVar38[0xa7] != '\0') goto LAB_00106578;
LAB_0010666c:
      uVar42 = local_80 - 1;
      uVar45 = (ulong)uVar42;
      iVar22 = wait_for_completion_timeout(plVar2,*(undefined4 *)((long)plVar38 + 0x1c));
      *(undefined4 *)(plVar38 + 0x9c) = 0;
      ipc_log_string(plVar38[0x27a],"%s: msg_idx:%d wr_idx:%d\n","geni_i2c_gsi_tx_tre_optimization",
                     uVar48,uVar45);
      if (*plVar38 != 0) {
        i2c_trace_log(*plVar38,"%s: msg_idx:%d wr_idx:%d\n","geni_i2c_gsi_tx_tre_optimization",
                      uVar48,uVar45);
      }
      if ((char)plVar38[0x469] != '\0') {
        ipc_log_string(plVar38[0x27a],"%s: gsi error\n","geni_i2c_gsi_tx_tre_optimization");
        if (*plVar38 != 0) {
          i2c_trace_log(*plVar38,"%s: gsi error\n","geni_i2c_gsi_tx_tre_optimization");
        }
        iVar22 = -5;
        goto LAB_00106adc;
      }
      if (iVar22 == 0) {
        iVar22 = 0;
        goto LAB_00106a50;
      }
      if ((int)plVar38[3] == 0) {
        lVar46 = plVar38[0xa5];
        uVar30 = *(ushort *)(lVar46 + uVar48 * 0x10 + 4);
        if (uVar30 < 9) goto LAB_00106a34;
        if (0x1c0 < uVar42) goto LAB_001071dc;
        if (plVar38[(ulong)uVar42 + 0x28b] == -1) {
          bVar18 = true;
        }
        else {
          dma_unmap_page_attrs(plVar38[0x279],plVar38[(ulong)uVar42 + 0x28b],uVar30,1,0);
          bVar18 = (int)plVar38[3] == 0;
          lVar46 = plVar38[0xa5];
        }
        i2c_put_dma_safe_msg_buf(plVar38[uVar45 + 0xa9],lVar46 + uVar48 * 0x10,bVar18);
      }
LAB_00106a34:
      if ((char)plVar38[0xa7] != '\0') goto LAB_00106a40;
    }
    else {
      if ((int)plVar38[0x27c] == 0) {
        uVar40 = 0;
        goto joined_r0x00106668;
      }
      uVar40 = sched_clock();
      ipc_log_string(lVar46,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_gsi_tx_tre_optimization",
                     uVar40,uVar40 / 1000);
      if ((char)plVar38[0xa7] == '\0') goto LAB_0010666c;
LAB_00106578:
      if (uVar15 == 0) {
        iVar22 = 1;
LAB_00106a40:
        gi2c_gsi_tre_process(plVar38,param_3);
      }
      else {
        uVar42 = 0;
        iVar22 = 1;
        do {
          if (uVar15 != *(uint *)((long)plVar38 + 0x53c)) {
            ipc_log_string(plVar38[0x27a],"%s: calling wait for_completion %d\n",
                           "geni_i2c_gsi_tx_tre_optimization",uVar42);
            if (*plVar38 != 0) {
              i2c_trace_log(*plVar38,"%s: calling wait for_completion %d\n",
                            "geni_i2c_gsi_tx_tre_optimization",uVar42);
            }
            iVar22 = wait_for_completion_timeout(plVar2,*(undefined4 *)((long)plVar38 + 0x1c));
            *(undefined4 *)(plVar38 + 0x9c) = 0;
            if (iVar22 == 0) {
              ipc_log_string(plVar38[0x27a],"%s: msg xfer timeout\n",
                             "geni_i2c_gsi_tx_tre_optimization");
              if (*plVar38 != 0) {
                i2c_trace_log(*plVar38,"%s: msg xfer timeout\n","geni_i2c_gsi_tx_tre_optimization");
              }
              iVar22 = 0;
              goto LAB_00106adc;
            }
          }
          ipc_log_string(plVar38[0x27a],"%s: maxirq_cnt:%d i:%d\n",
                         "geni_i2c_gsi_tx_tre_optimization",uVar15,uVar42);
          if (*plVar38 != 0) {
            i2c_trace_log(*plVar38,"%s: maxirq_cnt:%d i:%d\n","geni_i2c_gsi_tx_tre_optimization",
                          uVar15,uVar42);
          }
          if ((char)plVar38[0x469] != '\0') {
            ipc_log_string(plVar38[0x27a],"%s: gsi error\n","geni_i2c_gsi_tx_tre_optimization");
            if (*plVar38 != 0) {
              i2c_trace_log(*plVar38,"%s: gsi error\n","geni_i2c_gsi_tx_tre_optimization");
            }
            iVar22 = -5;
            goto LAB_00106ae4;
          }
          gi2c_gsi_tre_process(plVar38,param_3);
          if (*(uint *)(plVar38 + 0xa6) < param_3) goto LAB_00106adc;
          uVar42 = uVar42 + 1;
        } while (uVar15 != uVar42);
        if (iVar22 != 0) goto LAB_00106a34;
      }
    }
LAB_00106a50:
    ipc_log_string(plVar38[0x27a],"%s:  timeout :%d\n","geni_i2c_gsi_tx_tre_optimization",iVar22);
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"%s:  timeout :%d\n","geni_i2c_gsi_tx_tre_optimization",iVar22);
    }
    lVar46 = plVar38[0x27b];
    if (((lVar46 != 0) && (uVar40 != 0)) && ((int)plVar38[0x27c] != 0)) {
      lVar27 = sched_clock();
      ipc_log_string(lVar46,"%s:took %llu nsec(%llu usec)\n","geni_i2c_gsi_tx_tre_optimization",
                     lVar27 - uVar40,(lVar27 - uVar40) / 1000);
    }
LAB_00106adc:
LAB_00106ae4:
    if ((char)plVar38[0x471] != '\0') goto LAB_00106e40;
    if (iVar22 != 0) {
LAB_00106af0:
      if ((int)plVar38[3] == 0) goto LAB_00106b00;
      goto LAB_00106b08;
    }
    ipc_log_string(plVar38[0x27a],"I2C gsi xfer timeout:%u flags:%d addr:0x%x\n",
                   *(undefined4 *)((long)plVar38 + 0x1c),((undefined2 *)plVar38[0xa4])[1],
                   *(undefined2 *)plVar38[0xa4]);
    uVar13 = ((undefined2 *)plVar38[0xa4])[1];
    uVar14 = *(undefined2 *)plVar38[0xa4];
    if (*plVar38 == 0) {
      _printk(&DAT_0010b6b8,*(undefined4 *)((long)plVar38 + 0x1c),uVar13,uVar14);
      lVar46 = *plVar38;
    }
    else {
      _dev_err(*plVar38,"I2C gsi xfer timeout:%u flags:%d addr:0x%x\n",
               *(undefined4 *)((long)plVar38 + 0x1c),uVar13,uVar14);
      lVar46 = *plVar38;
    }
    if (lVar46 != 0) {
      i2c_trace_log(lVar46,"I2C gsi xfer timeout:%u flags:%d addr:0x%x\n",
                    *(undefined4 *)((long)plVar38 + 0x1c),((undefined2 *)plVar38[0xa4])[1],
                    *(undefined2 *)plVar38[0xa4]);
    }
    geni_i2c_se_dump_dbg_regs(plVar38 + 0x269,plVar38[1],plVar38[0x27a]);
    *(undefined4 *)(plVar38 + 3) = 0xffffff92;
    uVar42 = readl_relaxed(plVar38[1] + 0x908);
    if (((uVar42 ^ 0xffffffff) & 3) == 0) goto LAB_00106af0;
    ipc_log_string(plVar38[0x27a],"%s: IO lines not in good state\n","geni_i2c_gsi_xfer");
    if (*plVar38 != 0) {
      i2c_trace_log(*plVar38,"%s: IO lines not in good state\n","geni_i2c_gsi_xfer");
    }
    if (*(char *)((long)plVar38 + 0x2349) == '\0') goto LAB_00106af0;
    iVar22 = 0;
    *(undefined1 *)((long)plVar38 + 0x2347) = 1;
    goto LAB_00106bb8;
  }
  *(undefined4 *)(plVar38 + 3) = 0xfffffff4;
  ipc_log_string(plVar38[0x27a],"geni_i2c_prep_desc failed\n");
  if (*plVar38 == 0) {
    _printk(&DAT_0010a3fb);
  }
  else {
    _dev_err(*plVar38,"geni_i2c_prep_desc failed\n");
  }
  lVar46 = *plVar38;
joined_r0x001069cc:
  if (lVar46 != 0) {
    i2c_trace_log(lVar46,"geni_i2c_prep_desc failed\n");
  }
LAB_00106254:
  if ((int)plVar38[3] == 0) {
LAB_00106b00:
    iVar22 = 0;
    if ((char)plVar38[0x469] != '\0') goto LAB_00106b08;
  }
  else {
LAB_00106b08:
    pcVar17 = *(code **)(*(long *)plVar38[0x27d] + 0x148);
    if (pcVar17 == (code *)0x0) {
      if ((char)plVar38[0x471] != '\0') goto LAB_00106e40;
      iVar22 = -0x26;
LAB_00106b54:
      ipc_log_string(plVar38[0x27a],"%s: gpi terminate failed ret:%d\n","geni_i2c_gsi_xfer",iVar22);
      if (*plVar38 != 0) {
        i2c_trace_log(*plVar38,"%s: gpi terminate failed ret:%d\n","geni_i2c_gsi_xfer",iVar22);
      }
    }
    else {
      if (*(int *)(pcVar17 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x106b30);
        (*pcVar17)();
      }
      iVar22 = (*pcVar17)();
      if ((char)plVar38[0x471] != '\0') {
LAB_00106e40:
        ipc_log_string(plVar38[0x27a],"%s: SSR Down\n","geni_i2c_gsi_xfer");
        if (*plVar38 == 0) {
          return 0;
        }
        i2c_trace_log(*plVar38,"%s: SSR Down\n","geni_i2c_gsi_xfer");
        return 0;
      }
      if (iVar22 != 0) goto LAB_00106b54;
    }
    *(undefined4 *)(plVar38 + 0x456) = 0;
    if ((char)plVar38[0x468] != '\0') {
      *(undefined1 *)((long)plVar38 + 0x2345) = 1;
    }
    if ((char)plVar38[0x469] != '\0') {
      if ((int)plVar38[3] == 0) {
        iVar22 = -5;
        *(undefined4 *)(plVar38 + 3) = 0xfffffffb;
      }
      *(undefined1 *)(plVar38 + 0x469) = 0;
    }
  }
  if (*(char *)((long)plVar38 + 0x232d) != '\0') {
    *(undefined4 *)(plVar38 + 0x456) = 0;
  }
LAB_00106bb8:
  if ((*puVar33 & 1) == 0) {
    if ((int)plVar38[3] != 0) {
      if ((char)plVar38[0xa7] == '\0') {
        lVar39 = plVar38[0xa5];
        uVar30 = *(ushort *)(lVar39 + uVar48 * 0x10 + 4);
        if (uVar30 < 9) goto LAB_00106c24;
        uVar42 = local_80 - 1;
        if (uVar42 < 0x1c1) {
          if (plVar38[(ulong)uVar42 + 0x28b] == -1) {
            iVar21 = 1;
          }
          else {
            dma_unmap_page_attrs(plVar38[0x279],plVar38[(ulong)uVar42 + 0x28b],uVar30,1,0);
            lVar39 = plVar38[0xa5];
            iVar21 = (int)plVar38[3];
          }
          lVar39 = lVar39 + uVar48 * 0x10;
          uVar40 = plVar38[(ulong)uVar42 + 0xa9];
          goto LAB_00106c20;
        }
        goto LAB_001071dc;
      }
      gi2c_gsi_tre_process(plVar38,param_3);
      goto LAB_00106c24;
    }
  }
  else {
    if (*plVar4 != -1) {
      dma_unmap_page_attrs(plVar38[0x279],*plVar4,*puVar37,2,0);
    }
    iVar21 = (int)plVar38[3];
    uVar40 = local_f0;
LAB_00106c20:
    i2c_put_dma_safe_msg_buf(uVar40,lVar39,iVar21 == 0);
LAB_00106c24:
    if ((int)plVar38[3] != 0) goto LAB_00106ecc;
  }
  geni_i2c_calc_xfer_time(plVar38,param_2,uVar24,uVar48,"geni_i2c_gsi_xfer");
joined_r0x0010650c:
  uVar48 = (ulong)(iVar47 + 1U);
  if (iVar47 + 1U == param_3) goto LAB_00106ecc;
  goto LAB_00105a9c;
LAB_00106ecc:
  cVar11 = (char)plVar38[0xa7];
  goto joined_r0x001071a8;
}



//------------------------------------------------------------
// geni_i2c_stop_with_cancel @ 001071e4 size=668
// signature: undefined geni_i2c_stop_with_cancel(void)
// callers: [geni_i2c_xfer, geni_i2c_stop_on_bus, geni_i2c_bus_recovery]
//------------------------------------------------------------

undefined8 geni_i2c_stop_with_cancel(long *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  
  if (*(char *)((long)param_1 + 0x2351) != '\0') {
    ipc_log_string(param_1[0x27a],"%s: test_bus:%d\n","geni_se_select_test_bus",8);
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: test_bus:%d\n","geni_se_select_test_bus",8);
    }
    writel_relaxed(8,param_1[1] + 0x44);
    lVar4 = param_1[0x27a];
    plVar5 = *(long **)(param_1[0x279] + 0x98);
    writel_relaxed(5,*plVar5 + 0x200);
    uVar1 = readl_relaxed(*plVar5 + 0x200);
    ipc_log_string(lVar4,"%s: readback TEST_BUS_SEL: 0x%x @address:0x%x\n",
                   "test_bus_select_per_qupv3",uVar1,*plVar5 + 0x200);
    lVar4 = param_1[0x27a];
    uVar1 = readl_relaxed(**(long **)(param_1[0x279] + 0x98) + 0x208);
    ipc_log_string(lVar4,"%s: dump QUPV3_TEST_BUS_REG:0x%x\n","test_bus_read_per_qupv3",uVar1);
    ipc_log_string(param_1[0x27a],"%s: test_bus:%d\n","geni_se_select_test_bus",5);
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: test_bus:%d\n","geni_se_select_test_bus",5);
    }
    writel_relaxed(5,param_1[1] + 0x44);
    lVar4 = param_1[0x27a];
    plVar5 = *(long **)(param_1[0x279] + 0x98);
    writel_relaxed(5,*plVar5 + 0x200);
    uVar1 = readl_relaxed(*plVar5 + 0x200);
    ipc_log_string(lVar4,"%s: readback TEST_BUS_SEL: 0x%x @address:0x%x\n",
                   "test_bus_select_per_qupv3",uVar1,*plVar5 + 0x200);
    lVar4 = param_1[0x27a];
    uVar1 = readl_relaxed(**(long **)(param_1[0x279] + 0x98) + 0x208);
    ipc_log_string(lVar4,"%s: dump QUPV3_TEST_BUS_REG:0x%x\n","test_bus_read_per_qupv3",uVar1);
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  writel_relaxed(4,param_1[0x269] + 0x604);
  iVar2 = wait_for_completion_timeout(param_1 + 0xa0,0xfa);
  uVar3 = 0;
  if (iVar2 == 0) {
    ipc_log_string(param_1[0x27a],"%s:Cancel failed\n","geni_i2c_stop_with_cancel");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s:Cancel failed\n","geni_i2c_stop_with_cancel");
    }
    *(undefined4 *)(param_1 + 0x9c) = 0;
    writel_relaxed(2,param_1[0x269] + 0x604);
    iVar2 = wait_for_completion_timeout(param_1 + 0x9c,0xfa);
    uVar3 = 0;
    if (iVar2 == 0) {
      ipc_log_string(param_1[0x27a],"%s:Abort failed\n","geni_i2c_stop_with_cancel");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s:Abort failed\n","geni_i2c_stop_with_cancel");
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// geni_i2c_bus_recovery @ 00107480 size=1000
// signature: undefined geni_i2c_bus_recovery(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

undefined8 geni_i2c_bus_recovery(long *param_1)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = param_1[0x27b];
  if (lVar7 == 0) {
    uVar5 = 0xffffffffffffffea;
  }
  else if ((int)param_1[0x27c] == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = sched_clock();
    ipc_log_string(lVar7,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_bus_recovery",uVar5,
                   uVar5 / 1000);
  }
  if ((((char)param_1[0x46a] == '\0') ||
      (uVar3 = readl_relaxed(param_1[1] + 0x908), (uVar3 & 3) != 2)) ||
     ((iVar4 = (int)param_1[3], iVar4 != -0x6e && ((iVar4 != -0x10 && (iVar4 != -0x47)))))) {
    ipc_log_string(param_1[0x27a],"Bus Recovery not required/enabled\n");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"Bus Recovery not required/enabled\n");
    }
  }
  else {
    ipc_log_string(param_1[0x27a],"SDA Line stuck %d\n");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"SDA Line stuck %d\n",(int)param_1[3]);
    }
    ipc_log_string(param_1[0x27a],"%s: start recovery\n","geni_i2c_bus_recovery");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: start recovery\n","geni_i2c_bus_recovery");
    }
    plVar2 = param_1 + 0x269;
    uVar3 = readl_relaxed(param_1[1] + 0x614);
    if ((uVar3 & 1) == 0) {
      ipc_log_string(param_1[0x27a],"Set M_CMD_DONE_EN bit, geni_m_irq_en:0x%x\n",uVar3);
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"Set M_CMD_DONE_EN bit, geni_m_irq_en:0x%x\n",uVar3);
      }
      writel_relaxed(uVar3 | 1,param_1[1] + 0x614);
    }
    plVar1 = param_1 + 0x9c;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    writel(0x30000000,param_1[0x269] + 0x600);
    iVar4 = wait_for_completion_timeout(plVar1,0xfa);
    if (iVar4 == 0) {
      ipc_log_string(param_1[0x27a],"%s: Bus clear Failed\n","geni_i2c_bus_recovery");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s: Bus clear Failed\n","geni_i2c_bus_recovery");
      }
      ipc_log_string(param_1[0x27a],&DAT_0010acbc,"I2C TXN timed out");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,&DAT_0010acbc,"I2C TXN timed out");
      }
      geni_i2c_se_dump_dbg_regs(plVar2,param_1[1],param_1[0x27a]);
      param_1[0xa4] = 0;
      *(undefined4 *)(param_1 + 3) = 0xffffff92;
      iVar4 = geni_i2c_stop_with_cancel(param_1);
      if (iVar4 != 0) {
        return 0xffffff92;
      }
    }
    ipc_log_string(param_1[0x27a],"%s: BUS_CLEAR success\n","geni_i2c_bus_recovery");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: BUS_CLEAR success\n","geni_i2c_bus_recovery");
    }
    *(undefined4 *)plVar1 = 0;
    writel(0x38000000,*plVar2 + 0x600);
    iVar4 = wait_for_completion_timeout(plVar1,0xfa);
    if (iVar4 == 0) {
      ipc_log_string(param_1[0x27a],"%s:Bus Stop Failed\n","geni_i2c_bus_recovery");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s:Bus Stop Failed\n","geni_i2c_bus_recovery");
      }
      ipc_log_string(param_1[0x27a],&DAT_0010acbc,"I2C TXN timed out");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,&DAT_0010acbc,"I2C TXN timed out");
      }
      geni_i2c_se_dump_dbg_regs(plVar2,param_1[1],param_1[0x27a]);
      param_1[0xa4] = 0;
      *(undefined4 *)(param_1 + 3) = 0xffffff92;
      iVar4 = geni_i2c_stop_with_cancel(param_1);
      if (iVar4 != 0) {
        return 0xffffff92;
      }
    }
    ipc_log_string(param_1[0x27a],"%s: success\n","geni_i2c_bus_recovery");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: success\n","geni_i2c_bus_recovery");
    }
    lVar7 = param_1[0x27b];
    if (lVar7 != 0) {
      if (uVar5 == 0) {
        return 0;
      }
      if ((int)param_1[0x27c] == 0) {
        return 0;
      }
      lVar6 = sched_clock();
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","geni_i2c_bus_recovery",lVar6 - uVar5,
                     (lVar6 - uVar5) / 1000);
    }
  }
  return 0;
}



//------------------------------------------------------------
// writel @ 00107868 size=136
// signature: undefined writel(void)
// callers: [geni_i2c_xfer, geni_i2c_stop_on_bus, geni_i2c_bus_recovery]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x107880,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1078c0,uVar1);
  return;
}



//------------------------------------------------------------
// geni_i2c_gsi_request_channel @ 001078f0 size=756
// signature: undefined geni_i2c_gsi_request_channel(void)
// callers: [geni_i2c_lock_bus, geni_i2c_gsi_xfer]
//------------------------------------------------------------

int geni_i2c_gsi_request_channel(long *param_1)

{
  ulong *puVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  code *pcVar7;
  
  uVar3 = param_1[0x27d];
  if (uVar3 == 0) {
    uVar3 = dma_request_chan(*param_1,&DAT_0010afe7);
    uVar4 = 0;
    if (uVar3 < 0xfffffffffffff001) {
      uVar4 = uVar3;
    }
    param_1[0x27d] = uVar4;
    if (uVar4 == 0) {
      ipc_log_string(param_1[0x27a],"tx dma req slv chan ret :%d\n",0);
      if (*param_1 == 0) {
        _printk(&DAT_0010b597,0);
      }
      else {
        _dev_err(*param_1,"tx dma req slv chan ret :%d\n",0);
      }
      if (*param_1 == 0) {
        return -5;
      }
      i2c_trace_log(*param_1,"tx dma req slv chan ret :%d\n",0);
      return -5;
    }
  }
  puVar1 = (ulong *)(param_1 + 0x27d);
  if (param_1[0x27e] == 0) {
    uVar4 = dma_request_chan(*param_1,&DAT_00109f4c);
    uVar3 = 0;
    if (uVar4 < 0xfffffffffffff001) {
      uVar3 = uVar4;
    }
    param_1[0x27e] = uVar3;
    if (uVar3 == 0) {
      ipc_log_string(param_1[0x27a],"rx dma req slv chan ret :%d\n",0);
      if (*param_1 == 0) {
        _printk(&DAT_00109caa,0);
      }
      else {
        _dev_err(*param_1,"rx dma req slv chan ret :%d\n",0);
      }
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"rx dma req slv chan ret :%d\n",0);
      }
      dma_release_channel(*puVar1);
      return -5;
    }
    uVar3 = *puVar1;
  }
  param_1[0x44e] = (long)param_1;
  param_1[0x44d] = (long)gi2c_ev_cb;
  *(undefined4 *)(param_1 + 0x44c) = 1;
  *(long **)(uVar3 + 0x68) = param_1 + 0x44c;
  pcVar7 = *(code **)(*(long *)param_1[0x27d] + 0x130);
  if (pcVar7 == (code *)0x0) {
    iVar2 = -0x26;
LAB_00107a38:
    ipc_log_string(param_1[0x27a],"tx dma slave config ret :%d\n",iVar2);
    if (*param_1 == 0) {
      _printk(&DAT_0010a4d8,iVar2);
      lVar5 = *param_1;
    }
    else {
      _dev_err(*param_1,"tx dma slave config ret :%d\n",iVar2);
      lVar5 = *param_1;
    }
    if (lVar5 == 0) goto LAB_00107af0;
    pcVar6 = "tx dma slave config ret :%d\n";
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1079b4);
      (*pcVar7)();
    }
    iVar2 = (*pcVar7)((long *)param_1[0x27d],0);
    if (iVar2 != 0) goto LAB_00107a38;
    param_1[0x451] = (long)param_1;
    param_1[0x450] = (long)gi2c_ev_cb;
    *(undefined4 *)(param_1 + 0x44f) = 1;
    *(long **)(param_1[0x27e] + 0x68) = param_1 + 0x44f;
    pcVar7 = *(code **)(*(long *)param_1[0x27e] + 0x130);
    if (pcVar7 == (code *)0x0) {
      iVar2 = -0x26;
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x107a08);
        (*pcVar7)();
      }
      iVar2 = (*pcVar7)((long *)param_1[0x27e],0);
      if (iVar2 == 0) {
        param_1[0x45d] = (long)param_1;
        param_1[0x463] = (long)param_1;
        *(undefined1 *)((long)param_1 + 0x2343) = 1;
        return 0;
      }
    }
    ipc_log_string(param_1[0x27a],"rx dma slave config ret :%d\n",iVar2);
    if (*param_1 == 0) {
      _printk(&DAT_0010b48b,iVar2);
    }
    else {
      _dev_err(*param_1,"rx dma slave config ret :%d\n",iVar2);
    }
    lVar5 = *param_1;
    if (lVar5 == 0) goto LAB_00107af0;
    pcVar6 = "rx dma slave config ret :%d\n";
  }
  i2c_trace_log(lVar5,pcVar6,iVar2);
LAB_00107af0:
  dma_release_channel(param_1[0x27d]);
  dma_release_channel(param_1[0x27e]);
  *puVar1 = 0;
  param_1[0x27e] = 0;
  return iVar2;
}



//------------------------------------------------------------
// gi2c_ev_cb @ 00107be8 size=392
// signature: undefined gi2c_ev_cb(void)
// callers: []
//------------------------------------------------------------

void gi2c_ev_cb(undefined8 param_1,uint *param_2,long *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if ((param_2 == (uint *)0x0) || (param_3 == (long *)0x0)) {
    _printk(&DAT_0010b0ef,"gi2c_ev_cb");
  }
  else {
    uVar2 = *(ulong *)(param_2 + 2);
    uVar1 = (uint)uVar2;
    if ((*param_2 | 2) == 2) {
      if ((uVar1 >> 10 & 1) != 0) {
        geni_i2c_check_addr_data_nack(param_3,*(undefined2 *)(param_3[0xa4] + 2));
      }
      if ((uVar1 >> 0xc & 1) != 0) {
        ipc_log_string(param_3[0x27a],&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
        if (*param_3 != 0) {
          i2c_trace_log(*param_3,&DAT_0010acbc,"Bus proto err, noisy/unepxected start/stop");
        }
        geni_i2c_se_dump_dbg_regs(param_3 + 0x269,param_3[1],param_3[0x27a]);
        *(undefined4 *)(param_3 + 3) = 0xffffffb9;
      }
      if ((uVar1 >> 0xd & 1) != 0) {
        ipc_log_string(param_3[0x27a],&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
        if (*param_3 != 0) {
          i2c_trace_log(*param_3,&DAT_0010acbc,"Bus arbitration lost, clock line undriveable");
        }
        geni_i2c_se_dump_dbg_regs(param_3 + 0x269,param_3[1],param_3[0x27a]);
        *(undefined4 *)(param_3 + 3) = 0xfffffff0;
      }
      complete(param_3 + 0x9c);
      if (*param_2 == 0) {
        return;
      }
    }
    ipc_log_string(param_3[0x27a],"GSI QN err:0x%x, status:0x%x, err:%d\n",param_2[10],
                   uVar2 & 0xffffffff);
    if (*param_3 != 0) {
      i2c_trace_log(*param_3,"GSI QN err:0x%x, status:0x%x, err:%d\n",param_2[10],uVar2 & 0xffffffff
                    ,*param_2);
    }
    *(undefined1 *)(param_3 + 0x469) = 1;
    complete(param_3 + 0x9c);
  }
  return;
}



//------------------------------------------------------------
// geni_i2c_stop_on_bus @ 00107d70 size=1256
// signature: undefined geni_i2c_stop_on_bus(void)
// callers: [geni_i2c_xfer, geni_i2c_gsi_xfer]
//------------------------------------------------------------

void geni_i2c_stop_on_bus(long *param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  undefined4 uVar6;
  ulong *puVar7;
  
  uVar2 = readl_relaxed(param_1[1] + 0x908);
  if (*(char *)((long)param_1 + 0x232d) != '\0' || (uVar2 & 3) == 3) {
    if (*(char *)((long)param_1 + 0x232d) == '\0') {
      return;
    }
    *(undefined4 *)(param_1 + 0x456) = 0;
    return;
  }
  ipc_log_string(param_1[0x27a],"%s: IOS:0x%x, try I2C_STOP_ON_BUS\n","geni_i2c_stop_on_bus",uVar2);
  if (*param_1 != 0) {
    i2c_trace_log(*param_1,"%s: IOS:0x%x, try I2C_STOP_ON_BUS\n","geni_i2c_stop_on_bus",uVar2);
  }
  if ((int)param_1[0x465] != 2) {
    *(undefined4 *)(param_1 + 0x9c) = 0;
    writel(0x38000000,param_1[0x269] + 0x600);
    iVar3 = wait_for_completion_timeout(param_1 + 0x9c,0xfa);
    if (iVar3 == 0) {
      ipc_log_string(param_1[0x27a],&DAT_0010acbc,"I2C TXN timed out");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,&DAT_0010acbc,"I2C TXN timed out");
      }
      geni_i2c_se_dump_dbg_regs(param_1 + 0x269,param_1[1],param_1[0x27a]);
      param_1[0xa4] = 0;
      *(undefined4 *)(param_1 + 3) = 0xffffff92;
      iVar3 = geni_i2c_stop_with_cancel(param_1);
      if (iVar3 != 0) {
        ipc_log_string(param_1[0x27a],"%s:I2C Bus stop failed\n","geni_i2c_stop_on_bus");
        lVar4 = *param_1;
        if (lVar4 == 0) {
          return;
        }
        pcVar5 = "%s:I2C Bus stop failed\n";
        goto LAB_001081b8;
      }
    }
    ipc_log_string(param_1[0x27a],"%s: I2C Bus stop success\n","geni_i2c_stop_on_bus");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: I2C Bus stop success\n","geni_i2c_stop_on_bus");
    }
LAB_00108018:
    uVar2 = readl_relaxed(param_1[1] + 0x908);
    if (((uVar2 ^ 0xffffffff) & 3) != 0) {
      ipc_log_string(param_1[0x27a],"%s: IOS:0x%x, I2C lines in bad state\n","geni_i2c_stop_on_bus",
                     uVar2);
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s: IOS:0x%x, I2C lines in bad state\n","geni_i2c_stop_on_bus",uVar2
                     );
      }
      geni_i2c_se_dump_dbg_regs(param_1 + 0x269,param_1[1],param_1[0x27a]);
      return;
    }
    ipc_log_string(param_1[0x27a],"%s: IOS:0x%x, I2C lines in good state\n","geni_i2c_stop_on_bus",
                   uVar2);
    if (*param_1 == 0) {
      return;
    }
    i2c_trace_log(*param_1,"%s: IOS:0x%x, I2C lines in good state\n","geni_i2c_stop_on_bus",uVar2);
    return;
  }
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  param_1[0x285] = 7;
  param_1[0x286] = 0x20020000000000;
  ipc_log_string(param_1[0x27a],"%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                 "geni_i2c_gsi_stop_on_bus",7,0,0,0x200200);
  if (*param_1 != 0) {
    i2c_trace_log(*param_1,"%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                  "geni_i2c_gsi_stop_on_bus",(int)param_1[0x285],
                  *(undefined4 *)((long)param_1 + 0x142c),(int)param_1[0x286],
                  *(undefined4 *)((long)param_1 + 0x1434));
  }
  sg_init_table(param_1[0x452],1);
  puVar7 = (ulong *)param_1[0x452];
  *puVar7 = (*puVar7 & 3 | (((long)(param_1 + 0x285) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
            0x200000000;
  *(uint *)(puVar7 + 1) = (uint)(param_1 + 0x285) & 0xfff;
  *(undefined4 *)((long)puVar7 + 0xc) = 0x10;
  lVar4 = geni_i2c_prep_desc(param_1,1,1);
  param_1[0x457] = lVar4;
  if (lVar4 == 0) {
    ipc_log_string(param_1[0x27a],"%s: geni_i2c_prep_desc failed\n","geni_i2c_gsi_stop_on_bus");
    if (*param_1 != 0) {
      i2c_trace_log(*param_1,"%s: geni_i2c_prep_desc failed\n","geni_i2c_gsi_stop_on_bus");
    }
    uVar6 = 0xfffffff4;
  }
  else {
    if (*(int *)(*(code **)(lVar4 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107ef4);
      (*pcVar1)();
    }
    iVar3 = (**(code **)(lVar4 + 0x18))();
    if (iVar3 < 0) {
      ipc_log_string(param_1[0x27a],"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_stop_on_bus",
                     iVar3);
      if (*param_1 == 0) {
        _printk(&DAT_0010b073,"geni_i2c_gsi_stop_on_bus",iVar3);
      }
      else {
        _dev_err(*param_1,"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_stop_on_bus",iVar3);
      }
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s: dmaengine_submit failed (%d)\n","geni_i2c_gsi_stop_on_bus",iVar3
                     );
      }
      uVar6 = 0xffffffea;
    }
    else {
      if (*(int *)(*(code **)(*(long *)param_1[0x27d] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107f24);
        (*pcVar1)();
      }
      (**(code **)(*(long *)param_1[0x27d] + 0x160))();
      iVar3 = wait_for_completion_timeout(param_1 + 0x9c,0xfa);
      if (iVar3 != 0) goto LAB_00108018;
      ipc_log_string(param_1[0x27a],"%s:wait_for_completion timed out\n","geni_i2c_gsi_stop_on_bus")
      ;
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s:wait_for_completion timed out\n","geni_i2c_gsi_stop_on_bus");
      }
      ipc_log_string(param_1[0x27a],&DAT_0010acbc,"I2C TXN timed out");
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,&DAT_0010acbc,"I2C TXN timed out");
      }
      geni_i2c_se_dump_dbg_regs(param_1 + 0x269,param_1[1],param_1[0x27a]);
      uVar6 = 0xffffff92;
    }
  }
  *(undefined4 *)(param_1 + 3) = uVar6;
  ipc_log_string(param_1[0x27a],"%s: I2C Bus stop failed\n","geni_i2c_stop_on_bus");
  lVar4 = *param_1;
  if (lVar4 == 0) {
    return;
  }
  pcVar5 = "%s: I2C Bus stop failed\n";
LAB_001081b8:
  i2c_trace_log(lVar4,pcVar5,"geni_i2c_stop_on_bus");
  return;
}



//------------------------------------------------------------
// gi2c_gsi_tre_process @ 00108258 size=604
// signature: undefined gi2c_gsi_tre_process(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

void gi2c_gsi_tre_process(long *param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  
  lVar5 = param_1[0x27b];
  if (lVar5 == 0) {
    uVar3 = 0xffffffffffffffea;
    iVar1 = (int)param_1[3];
  }
  else if ((int)param_1[0x27c] == 0) {
    uVar3 = 0;
    iVar1 = (int)param_1[3];
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","gi2c_gsi_tre_process",uVar3,
                   uVar3 / 1000);
    iVar1 = (int)param_1[3];
  }
  if (iVar1 == 0) {
    uVar8 = *(int *)((long)param_1 + 0x53c) << 6;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0xa6);
  }
  uVar7 = *(uint *)(param_1 + 0xa8);
  if (uVar7 < uVar8) {
    uVar6 = 0;
    do {
      if (uVar7 == param_2) {
        ipc_log_string(param_1[0x27a],"%s:last %d msg unmapped\n","gi2c_gsi_tre_process",param_2);
        if (*param_1 != 0) {
          i2c_trace_log(*param_1,"%s:last %d msg unmapped\n","gi2c_gsi_tre_process",param_2);
        }
        break;
      }
      lVar5 = param_1[0xa5];
      iVar1 = *(int *)((long)param_1 + 0x534) + 1;
      *(int *)((long)param_1 + 0x534) = iVar1;
      uVar2 = *(ushort *)(lVar5 + (ulong)uVar7 * 0x10 + 4);
      if (8 < uVar2) {
        uVar6 = (ulong)(uVar7 % 0x1c0);
        if (param_1[uVar6 + 0x28b] != -1) {
          dma_unmap_page_attrs(param_1[0x279],param_1[uVar6 + 0x28b],uVar2,1,0);
          lVar5 = param_1[0xa5];
        }
        i2c_put_dma_safe_msg_buf
                  (param_1[uVar6 + 0xa9],lVar5 + (ulong)uVar7 * 0x10,(int)param_1[3] == 0);
        uVar7 = *(uint *)(param_1 + 0xa8);
        iVar1 = *(int *)((long)param_1 + 0x534);
      }
      ipc_log_string(param_1[0x27a],"%s:unmap_cnt %d freed_cnt:%d wr_idx:%d\n",
                     "gi2c_gsi_tre_process",uVar7,iVar1,uVar6);
      if (*param_1 != 0) {
        i2c_trace_log(*param_1,"%s:unmap_cnt %d freed_cnt:%d wr_idx:%d\n","gi2c_gsi_tre_process",
                      (int)param_1[0xa8],*(undefined4 *)((long)param_1 + 0x534),uVar6);
      }
      uVar7 = (int)param_1[0xa8] + 1;
      *(uint *)(param_1 + 0xa8) = uVar7;
    } while (uVar7 < uVar8);
  }
  lVar5 = param_1[0x27b];
  if (((lVar5 != 0) && (uVar3 != 0)) && ((int)param_1[0x27c] != 0)) {
    lVar4 = sched_clock();
    ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","gi2c_gsi_tre_process",lVar4 - uVar3,
                   (lVar4 - uVar3) / 1000);
  }
  return;
}



//------------------------------------------------------------
// geni_i2c_calc_xfer_time @ 001084b4 size=312
// signature: undefined geni_i2c_calc_xfer_time(void)
// callers: [geni_i2c_xfer, geni_i2c_gsi_xfer]
//------------------------------------------------------------

void geni_i2c_calc_xfer_time
               (long param_1,long param_2,long param_3,ulong param_4,undefined8 param_5)

{
  undefined *puVar1;
  int iVar2;
  short sVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar7 = sp_el0;
  param_2 = param_2 + (param_4 & 0xffffffff) * 0x10;
  local_38 = *(long *)(lVar7 + 0x638);
  puVar1 = &DAT_0010ad8f;
  if ((*(ushort *)(param_2 + 2) & 1) != 0) {
    puVar1 = &DAT_0010ac2a;
  }
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  scnprintf(&local_58,0x20,&DAT_0010a244,param_5,puVar1);
  lVar7 = *(long *)(param_1 + 0x13d8);
  if (((lVar7 != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0x13e0) != 0)) {
    sVar3 = *(short *)(param_2 + 4);
    iVar2 = *(int *)(param_1 + 0x22b4);
    lVar4 = sched_clock();
    uVar5 = lVar4 - param_3;
    uVar6 = uVar5 / 1000;
    if (sVar3 == 0) {
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n",&local_58,uVar5,uVar6);
    }
    else if (iVar2 == 0) {
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec) for %u bytes\n",&local_58,uVar5,uVar6,sVar3
                    );
    }
    else {
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",&local_58,
                     uVar5,uVar6,sVar3,iVar2);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// capture_kpi_show @ 001085f0 size=72
// signature: undefined capture_kpi_show(void)
// callers: []
//------------------------------------------------------------

long capture_kpi_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    lVar2 = -0x16;
  }
  else {
    iVar1 = scnprintf(param_3,4,&DAT_00109e6e,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x13e0));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// capture_kpi_store @ 0010863c size=268
// signature: undefined capture_kpi_store(void)
// callers: []
//------------------------------------------------------------

undefined8 capture_kpi_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_001086fc;
  }
  iVar1 = kstrtoint(param_3,0,puVar4 + 0x27c);
  if (iVar1 == 0) {
    if ((*(int *)(puVar4 + 0x27c) == 0) || (puVar4[0x27b] != 0)) goto LAB_001086fc;
    local_40 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_60 = 0;
    uStack_58 = 0;
    lVar3 = ((long *)*puVar4)[0xe];
    if (lVar3 == 0) {
      lVar3 = *(long *)*puVar4;
    }
    scnprintf(&local_60,0x24,&DAT_0010a244,lVar3,&DAT_00109d2e);
    lVar3 = ipc_log_context_create(4,&local_60,0);
    puVar4[0x27b] = lVar3;
    if (lVar3 != 0) goto LAB_001086fc;
    pcVar2 = "Error creating kpi IPC logs\n";
  }
  else {
    param_4 = 0xffffffffffffffea;
    pcVar2 = "Invalid input\n";
  }
  _dev_err(param_1,pcVar2);
LAB_001086fc:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// geni_i2c_suspend_late @ 0010874c size=840
// signature: undefined geni_i2c_suspend_late(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i2c_suspend_late(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  long *plVar7;
  
  plVar7 = *(long **)(param_1 + 0x98);
  lVar6 = plVar7[0x27b];
  if (lVar6 == 0) {
    uVar3 = 0xffffffffffffffea;
    iVar2 = *(int *)((long)plVar7 + 0x234c);
  }
  else if ((int)plVar7[0x27c] == 0) {
    uVar3 = 0;
    iVar2 = *(int *)((long)plVar7 + 0x234c);
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_suspend_late",uVar3,
                   uVar3 / 1000);
    iVar2 = *(int *)((long)plVar7 + 0x234c);
  }
  if (iVar2 == 0) {
    if (*(int *)(*(code **)(plVar7[8] + 8) + -4) != 0x296c3742) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1087f0);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(plVar7[8] + 8))(plVar7 + 4,2);
    if (iVar2 != 0) {
      if (*(int *)(param_1 + 0x20c) != 2) {
        ipc_log_string(plVar7[0x27a],"%s: Force suspend\n","geni_i2c_suspend_late");
        if (*plVar7 != 0) {
          i2c_trace_log(*plVar7,"%s: Force suspend\n","geni_i2c_suspend_late");
        }
        geni_i2c_runtime_suspend(param_1);
        __pm_runtime_disable(param_1,1);
        __pm_runtime_set_status(param_1,2);
        pm_runtime_enable(param_1);
      }
      if (*(int *)(*(code **)(plVar7[8] + 0x10) + -4) != 0x21dd3032) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10888c);
        (*pcVar1)();
      }
      (**(code **)(plVar7[8] + 0x10))(plVar7 + 4,2);
      ipc_log_string(plVar7[0x27a],"%s ret=%d\n","geni_i2c_suspend_late",iVar2);
      if (*plVar7 != 0) {
        i2c_trace_log(*plVar7,"%s ret=%d\n","geni_i2c_suspend_late",iVar2);
      }
      lVar6 = plVar7[0x27b];
      if (lVar6 != 0) {
        if (uVar3 == 0) {
          return 0;
        }
        if ((int)plVar7[0x27c] == 0) {
          return 0;
        }
        lVar4 = sched_clock(0);
        ipc_log_string(lVar6,"%s:took %llu nsec(%llu usec)\n","geni_i2c_suspend_late",lVar4 - uVar3,
                       (lVar4 - uVar3) / 1000);
      }
      return 0;
    }
    ipc_log_string(plVar7[0x27a],"late I2C transaction request\n");
    if (*plVar7 == 0) {
      _printk(&DAT_0010adcb);
      lVar6 = *plVar7;
    }
    else {
      _dev_err(*plVar7,"late I2C transaction request\n");
      lVar6 = *plVar7;
    }
    if (lVar6 != 0) {
      i2c_trace_log(lVar6,"late I2C transaction request\n");
      return 0xfffffff0;
    }
  }
  else if (*(int *)(*plVar7 + 0x20c) == 2) {
    ipc_log_string(plVar7[0x27a],"%s System suspend not allowed while xfer in progress\n",
                   "geni_i2c_suspend_late");
    if (*plVar7 == 0) {
      _printk(&DAT_0010ad93,"geni_i2c_suspend_late");
    }
    else {
      _dev_err(*plVar7,"%s System suspend not allowed while xfer in progress\n",
               "geni_i2c_suspend_late");
    }
    lVar6 = *plVar7;
    if (lVar6 != 0) {
      pcVar5 = "%s System suspend not allowed while xfer in progress\n";
LAB_00108a78:
      i2c_trace_log(lVar6,pcVar5,"geni_i2c_suspend_late");
      return 0xfffffff0;
    }
  }
  else {
    ipc_log_string(plVar7[0x27a],":%s: runtime PM is active\n","geni_i2c_suspend_late");
    if (*plVar7 == 0) {
      _printk(&DAT_0010ac2e,"geni_i2c_suspend_late");
    }
    else {
      _dev_err(*plVar7,":%s: runtime PM is active\n","geni_i2c_suspend_late");
    }
    lVar6 = *plVar7;
    if (lVar6 != 0) {
      pcVar5 = ":%s: runtime PM is active\n";
      goto LAB_00108a78;
    }
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// geni_i2c_hib_resume_noirq @ 00108a98 size=96
// signature: undefined geni_i2c_hib_resume_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i2c_hib_resume_noirq(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x98);
  ipc_log_string(plVar1[0x27a],&DAT_0010acbc,"geni_i2c_hib_resume_noirq");
  if (*plVar1 != 0) {
    i2c_trace_log(*plVar1,&DAT_0010acbc,"geni_i2c_hib_resume_noirq");
  }
  *(undefined4 *)(plVar1 + 0x465) = 0;
  return 0;
}



//------------------------------------------------------------
// geni_i2c_resume_early @ 00108afc size=144
// signature: undefined geni_i2c_resume_early(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 geni_i2c_resume_early(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x98);
  ipc_log_string(plVar1[0x27a],"%s ret=%d\n","geni_i2c_resume_early",1);
  if (*plVar1 != 0) {
    i2c_trace_log(*plVar1,"%s ret=%d\n","geni_i2c_resume_early",1);
  }
  if (((char)plVar1[0x468] == '\0') && (_pm_suspend_target_state == 3)) {
    *(undefined4 *)(plVar1 + 0x465) = 0;
    *(undefined1 *)((long)plVar1 + 0x2352) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// geni_i2c_runtime_resume @ 00108b90 size=1424
// signature: undefined geni_i2c_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int geni_i2c_runtime_resume(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  long *plVar9;
  long lVar10;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  plVar9 = *(long **)(param_1 + 0x98);
  lVar10 = plVar9[0x27b];
  if (lVar10 == 0) {
    uVar6 = 0xffffffffffffffea;
    lVar10 = plVar9[0x27a];
joined_r0x00108c2c:
    if (lVar10 != 0) goto LAB_00108c30;
LAB_00108d4c:
    local_60 = 0;
    local_70 = 0;
    uStack_68 = 0;
    lVar10 = ((long *)*plVar9)[0xe];
    if (lVar10 == 0) {
      lVar10 = *(long *)*plVar9;
    }
    snprintf((char *)&local_70,0x14,"%s",lVar10);
    lVar10 = ipc_log_context_create(2,&local_70,0);
    plVar9[0x27a] = lVar10;
    if ((char)plVar9[0x468] != '\0') goto LAB_00108c38;
LAB_00108d94:
    if (*(char *)((long)plVar9 + 0x234a) == '\0') {
      iVar4 = geni_icc_enable(plVar9 + 0x269);
      lVar10 = plVar9[0x27a];
      if (iVar4 == 0) {
        uVar1 = *(uint *)(plVar9 + 0x270);
        iVar4 = icc_set_bw(plVar9[0x26f],(ulong)uVar1 / 100,uVar1);
        if (iVar4 == 0) {
          ipc_log_string(lVar10,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n","qup-core",
                         (ulong)uVar1 / 100,uVar1);
          uVar2 = (undefined4)plVar9[0x272];
          iVar4 = icc_set_bw(plVar9[0x271],uVar2,uVar2);
          if (iVar4 == 0) {
            ipc_log_string(lVar10,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n",
                           "qup-config",uVar2,uVar2);
            uVar2 = (undefined4)plVar9[0x274];
            iVar4 = icc_set_bw(plVar9[0x273],uVar2,uVar2);
            if (iVar4 == 0) {
              ipc_log_string(lVar10,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n",
                             "qup-memory",uVar2,uVar2);
              cVar3 = *(char *)((long)plVar9 + 0x2346);
              goto joined_r0x00108f18;
            }
            lVar10 = 2;
          }
          else {
            lVar10 = 1;
          }
        }
        else {
          lVar10 = 0;
        }
        iVar5 = ___ratelimit(geni_common_icc_set_bw__rs,"geni_common_icc_set_bw");
        if (iVar5 != 0) {
          _dev_err(plVar9[0x26a],"ICC BW voting failed on path \'%s\': %d\n",
                   (&icc_path_names)[lVar10],iVar4);
        }
        ipc_log_string(plVar9[0x27a],"%s failing at icc set bw ret=%d\n","geni_i2c_runtime_resume",
                       iVar4);
        if (*plVar9 == 0) {
          _printk(&DAT_0010adeb,"geni_i2c_runtime_resume",iVar4);
        }
        else {
          _dev_err(*plVar9,"%s failing at icc set bw ret=%d\n","geni_i2c_runtime_resume",iVar4);
        }
        lVar10 = *plVar9;
        if (lVar10 == 0) goto LAB_00108f9c;
        pcVar8 = "%s failing at icc set bw ret=%d\n";
      }
      else {
        ipc_log_string(lVar10,"%s failing at geni icc enable ret=%d\n","geni_i2c_runtime_resume",
                       iVar4);
        lVar10 = *plVar9;
        if (lVar10 == 0) goto LAB_00108f9c;
        pcVar8 = "%s failing at geni icc enable ret=%d\n";
      }
    }
    else {
      cVar3 = *(char *)((long)plVar9 + 0x2346);
joined_r0x00108f18:
      if (cVar3 == '\0') {
LAB_00108f1c:
        iVar4 = geni_se_resources_on(plVar9 + 0x269);
        if (iVar4 != 0) goto LAB_00108f9c;
        iVar4 = geni_i2c_prepare(plVar9);
        if (iVar4 != 0) {
          lVar10 = *plVar9;
          pcVar8 = "I2C prepare failed: %d\n";
          goto LAB_00108f94;
        }
        writel_relaxed(0x7f,plVar9[1] + 0x24);
        __const_udelay(0xa7c6);
        iVar4 = (int)plVar9[0x465];
        if (iVar4 == 1) {
          enable_irq(*(undefined4 *)((long)plVar9 + 0x14));
          iVar4 = (int)plVar9[0x465];
        }
        if ((iVar4 == 2) && (iVar4 = geni_i2c_gpi_pause_resume(plVar9,0), iVar4 != 0))
        goto LAB_00108c68;
LAB_00108ca8:
        ipc_log_string(plVar9[0x27a],"%s ret=%d\n","geni_i2c_runtime_resume",0);
        if (*plVar9 != 0) {
          i2c_trace_log(*plVar9,"%s ret=%d\n","geni_i2c_runtime_resume",0);
        }
        lVar10 = plVar9[0x27b];
        if (lVar10 != 0) {
          iVar4 = 0;
          if ((uVar6 == 0) || ((int)plVar9[0x27c] == 0)) goto LAB_00108f9c;
          lVar7 = sched_clock();
          ipc_log_string(lVar10,"%s:took %llu nsec(%llu usec)\n","geni_i2c_runtime_resume",
                         lVar7 - uVar6,(lVar7 - uVar6) / 1000);
        }
        iVar4 = 0;
        goto LAB_00108f9c;
      }
      lVar10 = plVar9[0x277];
      iVar4 = clk_prepare(lVar10);
      if (iVar4 == 0) {
        iVar4 = clk_enable(lVar10);
        if (iVar4 == 0) goto LAB_00108f1c;
        clk_unprepare(lVar10);
      }
      ipc_log_string(plVar9[0x27a],"%s failing at core clk prepare enable ret=%d\n",
                     "geni_i2c_runtime_resume",iVar4);
      lVar10 = *plVar9;
      if (lVar10 == 0) goto LAB_00108f9c;
      pcVar8 = "%s failing at core clk prepare enable ret=%d\n";
    }
  }
  else {
    if ((int)plVar9[0x27c] == 0) {
      uVar6 = 0;
      lVar10 = plVar9[0x27a];
      goto joined_r0x00108c2c;
    }
    uVar6 = sched_clock();
    ipc_log_string(lVar10,"%s:start at %llu nsec(%llu usec)\n","geni_i2c_runtime_resume",uVar6,
                   uVar6 / 1000);
    if (plVar9[0x27a] == 0) goto LAB_00108d4c;
LAB_00108c30:
    if ((char)plVar9[0x468] == '\0') goto LAB_00108d94;
LAB_00108c38:
    if (*(char *)((long)plVar9 + 0x2344) == '\0') goto LAB_00108ca8;
    iVar4 = geni_i2c_prepare(plVar9);
    if (iVar4 != 0) {
      lVar10 = *plVar9;
      pcVar8 = "I2C prepare failed:%d\n";
LAB_00108f94:
      _dev_err(lVar10,pcVar8,iVar4);
      goto LAB_00108f9c;
    }
    if (((int)plVar9[0x465] != 2) || (iVar4 = geni_i2c_gpi_pause_resume(plVar9,0), iVar4 == 0)) {
      iVar4 = geni_i2c_lock_bus(plVar9);
      if (iVar4 == 0) goto LAB_00108ca8;
      ipc_log_string(plVar9[0x27a],"%s failed: %d\n","geni_i2c_runtime_resume",iVar4);
      if (*plVar9 == 0) {
        _printk(&DAT_0010a6bc,"geni_i2c_runtime_resume",iVar4);
      }
      else {
        _dev_err(*plVar9,"%s failed: %d\n","geni_i2c_runtime_resume",iVar4);
      }
      lVar10 = *plVar9;
      if (lVar10 == 0) goto LAB_00108f9c;
      pcVar8 = "%s failed: %d\n";
      goto LAB_00108e48;
    }
LAB_00108c68:
    ipc_log_string(plVar9[0x27a],"%s: ret:%d\n","geni_i2c_runtime_resume",iVar4);
    lVar10 = *plVar9;
    if (lVar10 == 0) goto LAB_00108f9c;
    pcVar8 = "%s: ret:%d\n";
  }
LAB_00108e48:
  i2c_trace_log(lVar10,pcVar8,"geni_i2c_runtime_resume",iVar4);
LAB_00108f9c:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// init_module @ 00109174 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&geni_i2c_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001091a4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&geni_i2c_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 0010e000 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_i2c_log_info, trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010e008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010e010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_i2c_log_info, trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 0010e018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [perf_trace_i2c_log_info, trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010e020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010e028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010e030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [i2c_trace_log, geni_i2c_runtime_resume, geni_i2c_xfer, capture_kpi_store, geni_i2c_calc_xfer_time, perf_trace_i2c_log_info, trace_event_raw_event_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010e038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010e040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0010e048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010e068 size=1
// signature: undefined ipc_log_string(void)
// callers: [geni_i2c_se_dump_dbg_regs, gi2c_gsi_rx_cb, geni_i2c_prep_desc, ssr_i2c_force_suspend, geni_i2c_bus_recovery, geni_i2c_suspend_late, gi2c_gsi_tx_cb, ssr_i2c_force_resume, geni_i2c_gpi_pause_resume, geni_i2c_irq, test_bus_enable_per_qupv3, geni_i2c_gsi_xfer, geni_i2c_runtime_suspend, geni_i2c_calc_xfer_time, gi2c_ev_cb, geni_i2c_resume_early, geni_i2c_stop_on_bus, geni_i2c_prepare, geni_i2c_shutdown, gi2c_gsi_tre_process, geni_i2c_remove, geni_i2c_lock_bus, geni_i2c_stop_with_cancel, geni_i2c_runtime_resume, geni_i2c_hib_resume_noirq, gi2c_gsi_cb_err, geni_i2c_xfer, geni_i2c_gsi_request_channel, geni_i2c_check_addr_data_nack]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 0010e070 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [geni_i2c_gsi_xfer, gi2c_gsi_tx_unmap, gi2c_gsi_tre_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_put_dma_safe_msg_buf @ 0010e078 size=1
// signature: undefined i2c_put_dma_safe_msg_buf(void)
// callers: [geni_i2c_xfer, geni_i2c_gsi_xfer, gi2c_gsi_tx_unmap, gi2c_gsi_tre_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_put_dma_safe_msg_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010e080 size=1
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
// platform_driver_unregister @ 0010e088 size=1
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
// trace_raw_output_prep @ 0010e090 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010e098 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010e0a0 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_i2c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010e0a8 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010e0b0 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010e0b8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 0010e0c0 size=1
// signature: undefined platform_get_resource(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0010e0c8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010e0d0 size=1
// signature: undefined of_find_property(void)
// callers: [geni_i2c_resources_init, geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010e0d8 size=1
// signature: undefined _dev_info(void)
// callers: [geni_i2c_prepare, geni_i2c_resources_init, geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010e0e0 size=1
// signature: undefined _dev_err(void)
// callers: [geni_i2c_prep_desc, ssr_i2c_force_suspend, geni_i2c_stop_on_bus, geni_i2c_suspend_late, geni_i2c_prepare, geni_i2c_probe, geni_i2c_remove, geni_i2c_gpi_pause_resume, geni_i2c_lock_bus, geni_i2c_runtime_resume, geni_i2c_xfer, geni_i2c_gsi_xfer, capture_kpi_store, geni_i2c_runtime_suspend, geni_i2c_gsi_request_channel, geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010e0e8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010e0f0 size=1
// signature: undefined __mutex_init(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 0010e0f8 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010e100 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 0010e108 size=1
// signature: undefined strscpy(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010e110 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [geni_i2c_remove, geni_i2c_xfer, ssr_i2c_force_suspend, geni_i2c_suspend_late, geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010e118 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010e120 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010e128 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [ssr_i2c_force_suspend, geni_i2c_suspend_late, geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_add_adapter @ 0010e130 size=1
// signature: undefined i2c_add_adapter(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_add_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0010e138 size=1
// signature: undefined device_create_file(void)
// callers: [geni_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010e148 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [geni_i2c_remove, ssr_i2c_force_suspend, geni_i2c_suspend_late]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_adapter @ 0010e150 size=1
// signature: undefined i2c_del_adapter(void)
// callers: [geni_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 0010e158 size=1
// signature: undefined device_remove_file(void)
// callers: [geni_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0010e160 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [geni_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010e168 size=1
// signature: undefined _printk(void)
// callers: [gi2c_gsi_rx_cb, geni_i2c_prep_desc, ssr_i2c_force_suspend, geni_i2c_stop_on_bus, geni_i2c_suspend_late, gi2c_gsi_tx_cb, geni_i2c_remove, geni_i2c_gpi_pause_resume, geni_i2c_lock_bus, geni_i2c_runtime_resume, gi2c_gsi_cb_err, geni_i2c_xfer, geni_i2c_gsi_xfer, geni_i2c_runtime_suspend, geni_i2c_gsi_request_channel, gi2c_ev_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_release_channel @ 0010e170 size=1
// signature: undefined dma_release_channel(void)
// callers: [geni_i2c_remove, geni_i2c_gsi_request_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_release_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010e178 size=1
// signature: undefined mutex_lock(void)
// callers: [geni_i2c_xfer, ssr_i2c_force_suspend, ssr_i2c_force_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010e180 size=1
// signature: undefined mutex_unlock(void)
// callers: [geni_i2c_xfer, ssr_i2c_force_suspend, ssr_i2c_force_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010e188 size=1
// signature: undefined devm_clk_get(void)
// callers: [geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_get @ 0010e190 size=1
// signature: undefined geni_icc_get(void)
// callers: [geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0010e198 size=1
// signature: undefined platform_get_irq(void)
// callers: [geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 0010e1a0 size=1
// signature: undefined irq_modify_status(void)
// callers: [geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010e1a8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [geni_i2c_resources_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010e1b0 size=1
// signature: undefined dma_set_mask(void)
// callers: [dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010e1b8 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 0010e1c0 size=1
// signature: undefined sched_clock(void)
// callers: [geni_i2c_irq, geni_i2c_lock_bus, geni_i2c_runtime_resume, geni_i2c_xfer, geni_i2c_gsi_xfer, geni_i2c_bus_recovery, geni_i2c_suspend_late, geni_i2c_runtime_suspend, geni_i2c_calc_xfer_time, gi2c_gsi_tre_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0010e1c8 size=1
// signature: undefined disable_irq(void)
// callers: [geni_i2c_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0010e1d0 size=1
// signature: undefined clk_disable(void)
// callers: [geni_i2c_runtime_suspend, geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0010e1d8 size=1
// signature: undefined clk_unprepare(void)
// callers: [geni_i2c_runtime_resume, geni_i2c_runtime_suspend, geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_resources_off @ 0010e1e0 size=1
// signature: undefined geni_se_resources_off(void)
// callers: [geni_i2c_runtime_suspend, geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_disable @ 0010e1e8 size=1
// signature: undefined geni_icc_disable(void)
// callers: [geni_i2c_runtime_suspend, geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 0010e1f0 size=1
// signature: undefined sg_init_table(void)
// callers: [geni_i2c_lock_bus, geni_i2c_gsi_xfer, geni_i2c_stop_on_bus, geni_i2c_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010e1f8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [geni_i2c_lock_bus, geni_i2c_stop_with_cancel, geni_i2c_xfer, geni_i2c_gsi_xfer, geni_i2c_stop_on_bus, geni_i2c_bus_recovery, geni_i2c_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010e200 size=1
// signature: undefined complete_all(void)
// callers: [gi2c_gsi_tx_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010e208 size=1
// signature: undefined complete(void)
// callers: [geni_i2c_irq, gi2c_gsi_rx_cb, gi2c_ev_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010e210 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010e218 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010e220 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010e228 size=1
// signature: undefined kfree(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010e230 size=1
// signature: undefined __kmalloc(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __usecs_to_jiffies @ 0010e238 size=1
// signature: undefined __usecs_to_jiffies(void)
// callers: [geni_i2c_xfer, geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __usecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_select_mode @ 0010e240 size=1
// signature: undefined geni_se_select_mode(void)
// callers: [geni_i2c_xfer, geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_select_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_get_dma_safe_msg_buf @ 0010e248 size=1
// signature: undefined i2c_get_dma_safe_msg_buf(void)
// callers: [geni_i2c_xfer, geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_get_dma_safe_msg_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_prep @ 0010e250 size=1
// signature: undefined geni_se_tx_dma_prep(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_prep @ 0010e258 size=1
// signature: undefined geni_se_rx_dma_prep(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_unprep @ 0010e260 size=1
// signature: undefined geni_se_rx_dma_unprep(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_unprep @ 0010e268 size=1
// signature: undefined geni_se_tx_dma_unprep(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010e270 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010e278 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [geni_i2c_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_get_qup_hw_version @ 0010e280 size=1
// signature: undefined geni_se_get_qup_hw_version(void)
// callers: [geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_get_qup_hw_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_init @ 0010e288 size=1
// signature: undefined geni_se_init(void)
// callers: [geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_config_packing @ 0010e290 size=1
// signature: undefined geni_se_config_packing(void)
// callers: [geni_i2c_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_config_packing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpi_update_multi_desc_flag @ 0010e298 size=1
// signature: undefined gpi_update_multi_desc_flag(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpi_update_multi_desc_flag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 0010e2a0 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 0010e2a8 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0010e2b0 size=1
// signature: undefined dev_driver_string(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010e2b8 size=1
// signature: undefined __warn_printk(void)
// callers: [geni_i2c_gsi_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_request_chan @ 0010e2c0 size=1
// signature: undefined dma_request_chan(void)
// callers: [geni_i2c_gsi_request_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_request_chan(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010e2c8 size=1
// signature: undefined scnprintf(void)
// callers: [capture_kpi_store, capture_kpi_show, geni_i2c_calc_xfer_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0010e2d0 size=1
// signature: undefined kstrtoint(void)
// callers: [capture_kpi_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010e2d8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [geni_i2c_runtime_resume, capture_kpi_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010e2e8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0010e2f0 size=1
// signature: undefined clk_prepare(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0010e2f8 size=1
// signature: undefined clk_enable(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_enable @ 0010e300 size=1
// signature: undefined geni_icc_enable(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0010e308 size=1
// signature: undefined icc_set_bw(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_resources_on @ 0010e310 size=1
// signature: undefined geni_se_resources_on(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010e318 size=1
// signature: undefined __const_udelay(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0010e320 size=1
// signature: undefined enable_irq(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010e328 size=1
// signature: undefined ___ratelimit(void)
// callers: [geni_i2c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



