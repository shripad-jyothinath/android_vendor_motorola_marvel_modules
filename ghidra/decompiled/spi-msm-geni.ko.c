// Decompiled by Ghidra 12.2
// Program: spi-msm-geni.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_spi_log_info @ 00100b1c size=116
// signature: undefined __traceiter_spi_log_info(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_spi_log_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001080a8;
  plVar2 = DAT_001080a8;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100b6c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_spi_log_info @ 00100b94 size=308
// signature: undefined trace_event_raw_event_spi_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_spi_log_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100cc4);
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
// perf_trace_spi_log_info @ 00100cd0 size=384
// signature: undefined perf_trace_spi_log_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_spi_log_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100e4c);
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
// __bpf_trace_spi_log_info @ 00100e58 size=28
// signature: undefined __bpf_trace_spi_log_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_spi_log_info(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// spi_trace_log @ 00100e78 size=136
// signature: undefined spi_trace_log(void)
// callers: [spi_geni_hib_suspend, spi_geni_runtime_suspend, spi_geni_mas_setup, spi_geni_prepare_transfer_hardware, spi_geni_prepare_message, spi_geni_gpi_pause_resume, spi_setup_word_len, spi_geni_runtime_resume, spi_geni_probe, spi_gsi_ch_cb, spi_geni_unprepare_message, spi_geni_transfer_one, spi_geni_remove, spi_gsi_tx_callback, geni_spi_se_dump_dbg_regs, spi_geni_unprepare_transfer_hardware, spi_geni_suspend, spi_geni_unlock_bus, ssr_spi_force_resume, geni_spi_irq, spi_gsi_rx_callback, ssr_spi_force_suspend, spi_geni_lock_bus]
//------------------------------------------------------------

void spi_trace_log(void)

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
// geni_spi_se_dump_dbg_regs @ 00100fa4 size=1340
// signature: undefined geni_spi_se_dump_dbg_regs(void)
// callers: [spi_geni_unlock_bus, handle_fifo_timeout, spi_geni_lock_bus, spi_geni_transfer_one]
//------------------------------------------------------------

void geni_spi_se_dump_dbg_regs(long param_1,long param_2,undefined8 param_3)

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
                 "geni_spi_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                  "geni_spi_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  }
  ipc_log_string(param_3,"dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",
                 uVar7,uVar6,uVar8,uVar9);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",uVar7,
                  uVar6,uVar8,uVar9);
  }
  ipc_log_string(param_3,"se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",
                 uVar10,uVar11,uVar12,uVar13);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",uVar10,
                  uVar11,uVar12,uVar13);
  }
  ipc_log_string(param_3,"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",uVar14,uVar15,uVar3
                );
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",
                  uVar14,uVar15,uVar3);
  }
  ipc_log_string(param_3,
                 "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                 uVar18,uVar19,uVar16,uVar17);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                  uVar18,uVar19,uVar16,uVar17);
  }
  ipc_log_string(param_3,"geni_dma_tx_irq_en:0x%x, geni_dma_rx_irq_en:0x%x, geni_general_cfg:0x%x\n"
                 ,uVar18,uVar19,uVar20);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "geni_dma_tx_irq_en:0x%x, geni_dma_rx_irq_en:0x%x, geni_general_cfg:0x%x\n",uVar18
                  ,uVar19,uVar20);
  }
  ipc_log_string(param_3,
                 "geni_clk_ctrl_ro:0x%x, fifo_if_disable_ro:0x%x, geni_fw_multilock_msa_ro:0x%x\n",
                 uVar22,uVar23,uVar24);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "geni_clk_ctrl_ro:0x%x, fifo_if_disable_ro:0x%x, geni_fw_multilock_msa_ro:0x%x\n",
                  uVar22,uVar23,uVar24);
  }
  ipc_log_string(param_3,
                 "m_irq_en:0x%x, se_dma_tx_attr:0x%x se_dma_tx_irq_stat:0x%x, geni_output_ctrl:0x%x\n"
                 ,uVar26,uVar27,uVar28,uVar21);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "m_irq_en:0x%x, se_dma_tx_attr:0x%x se_dma_tx_irq_stat:0x%x, geni_output_ctrl:0x%x\n"
                  ,uVar26,uVar27,uVar28,uVar21);
  }
  ipc_log_string(param_3,
                 "se_dma_rx_attr:0x%x, se_dma_rx_irq_stat:0x%x se_gsi_event_en:0x%x se_irq_en:0x%x\n"
                 ,uVar29,uVar30,uVar31,uVar32);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "se_dma_rx_attr:0x%x, se_dma_rx_irq_stat:0x%x se_gsi_event_en:0x%x se_irq_en:0x%x\n"
                  ,uVar29,uVar30,uVar31,uVar32);
  }
  ipc_log_string(param_3,
                 "dma_if_en_ro:0x%x, dma_general_cfg:0x%x dma_debug_reg0:0x%x\n, geni_clk_sel:0x%x",
                 uVar33,uVar34,uVar35,uVar25);
  if (*(long *)(param_1 + 8) != 0) {
    spi_trace_log(*(long *)(param_1 + 8),
                  "dma_if_en_ro:0x%x, dma_general_cfg:0x%x dma_debug_reg0:0x%x\n, geni_clk_sel:0x%x"
                  ,uVar33,uVar34,uVar35,uVar25);
  }
  return;
}



//------------------------------------------------------------
// spi_geni_deep_sleep_enable_check @ 001014e4 size=4
// signature: undefined spi_geni_deep_sleep_enable_check(void)
// callers: []
//------------------------------------------------------------

void spi_geni_deep_sleep_enable_check(void)

{
  return;
}



//------------------------------------------------------------
// trace_raw_output_spi_log_info @ 001014ec size=112
// signature: undefined trace_raw_output_spi_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_spi_log_info(long param_1,undefined8 param_2,undefined8 param_3)

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
// readl_relaxed @ 0010155c size=124
// signature: undefined readl_relaxed(void)
// callers: [geni_spi_se_dump_dbg_regs, geni_spi_irq, spi_geni_mas_setup, spi_geni_prepare_message, spi_setup_word_len, handle_fifo_timeout, spi_geni_transfer_one]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1015a4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// spi_geni_probe @ 001015dc size=2280
// signature: undefined spi_geni_probe(void)
// callers: []
//------------------------------------------------------------

ulong spi_geni_probe(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  long *plVar9;
  char *pcVar10;
  long *plVar11;
  long *plVar12;
  ulong uVar13;
  
  lVar1 = param_1 + 0x10;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,slv-ctrl",0);
  lVar6 = __spi_alloc_controller(lVar1,0x260,lVar5 != 0);
  if (lVar6 == 0) {
    _dev_err(lVar1,"Failed to alloc spi struct\n");
    pcVar10 = "%s: ret:%d\n";
    uVar13 = 0xfffffff4;
LAB_0010165c:
    _dev_info(lVar1,pcVar10,"spi_geni_probe",uVar13);
    goto LAB_00101bec;
  }
  if (lVar5 != 0) {
    *(code **)(lVar6 + 0x588) = spi_slv_abort;
  }
  *(long *)(param_1 + 0xa8) = lVar6;
  plVar11 = *(long **)(lVar6 + 0x98);
  plVar11[0x15] = lVar1;
  plVar11[1] = lVar1;
  plVar11[2] = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
  *(undefined8 *)(lVar6 + 0x2e8) = *(undefined8 *)(param_1 + 0x2f8);
  plVar11[0x46] = (long)plVar11;
  plVar11[0x44] = lVar1;
  if (plVar11[2] == 0) {
    _dev_err(lVar1,"SE Wrapper is NULL, deferring probe\n");
    uVar13 = 0xfffffdfb;
    goto LAB_00101bec;
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,le-vm",0);
  if (lVar5 != 0) {
    *(undefined1 *)((long)plVar11 + 0x1cf) = 1;
    _dev_info(lVar1,"LE-VM usecase\n");
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,la-vm",0);
  if (lVar5 != 0) {
    *(undefined1 *)(plVar11 + 0x3a) = 1;
    _dev_info(lVar1,"LA-VM usecase\n");
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rt",0);
  *(bool *)(lVar6 + 0x52c) = lVar5 != 0;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,disable-autosuspend",0);
  *(bool *)((long)plVar11 + 0x1d1) = lVar5 != 0;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,shared_se",0);
  if (lVar5 == 0) {
    lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,shared_ee",0);
    bVar2 = lVar5 != 0;
  }
  else {
    bVar2 = true;
    *(undefined1 *)((long)plVar11 + 0x1ce) = 1;
  }
  *(bool *)((long)plVar11 + 0x1cd) = bVar2;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,set-miso-sampling",0);
  *(bool *)((long)plVar11 + 0x1d3) = lVar5 != 0;
  if (lVar5 != 0) {
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,miso-sampling-ctrl-val",
                       (undefined4 *)((long)plVar11 + 0x1d4),1,0);
    if (-1 < iVar3) {
      _dev_info(lVar1,"MISO_SAMPLING_SET: %d\n",*(undefined4 *)((long)plVar11 + 0x1d4));
    }
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,disable-dma",0);
  *(bool *)((long)plVar11 + 0x1d9) = lVar5 != 0;
  of_property_read_variable_u32_array
            (*(undefined8 *)(param_1 + 0x2f8),"qcom,xfer-timeout-offset",plVar11 + 0x3c,1,0);
  if ((int)plVar11[0x3c] != 0) {
    _dev_info(lVar1,"%s: DT based xfer timeout offset: %d\n","spi_get_dt_property");
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,master-cross-connect",0);
  if (lVar5 != 0) {
    *(undefined1 *)((long)plVar11 + 0x1dd) = 1;
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"slv-cross-connected",0);
  *(bool *)((long)plVar11 + 0x1dc) = lVar5 != 0;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,ssr-enable",0);
  *(bool *)(plVar11 + 0x4b) = lVar5 != 0;
  plVar11[0x20] = *(long *)(param_1 + 0x70);
  plVar12 = (long *)0x0;
  if (*(char *)((long)plVar11 + 0x1cf) == '\0') {
    if ((plVar11 == (long *)0xfffffffffffffde0) || (lVar5 = plVar11[0x46], lVar5 == 0)) {
      uVar13 = 0xffffffea;
    }
    else {
      uVar7 = geni_icc_get(lVar5,"qup-memory");
      uVar13 = uVar7 & 0xffffffff;
      if ((int)uVar7 == 0) {
        *(undefined4 *)(lVar5 + 0x38) = 51000;
        *(undefined4 *)(lVar5 + 0x48) = 140000;
        *(undefined4 *)(lVar5 + 0x58) = 0x12c00;
        uVar4 = geni_icc_set_bw(plVar11);
        if (uVar4 != 0) {
          uVar13 = (ulong)uVar4;
          pcVar10 = "%s: icc set bw failed ret:%d\n";
LAB_00101e8c:
          _dev_err(lVar1,pcVar10,"spi_geni_probe",uVar13);
          goto LAB_00101bec;
        }
        uVar4 = geni_icc_enable(plVar11);
        if (uVar4 != 0) {
          uVar13 = (ulong)uVar4;
          pcVar10 = "%s: icc enable failed ret:%d\n";
          goto LAB_00101e8c;
        }
        uVar7 = devm_pinctrl_get(lVar1);
        plVar11[0xe] = uVar7;
        if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
          _dev_err(lVar1,"No pinctrl config specified!\n");
          uVar13 = (ulong)*(uint *)(plVar11 + 0xe);
        }
        else {
          uVar7 = pinctrl_lookup_state(uVar7,"default");
          plVar11[0xf] = uVar7;
          if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
            _dev_err(lVar1,"No default config specified!\n");
            uVar13 = (ulong)*(uint *)(plVar11 + 0xf);
          }
          else {
            uVar7 = pinctrl_lookup_state(plVar11[0xe],"sleep");
            plVar11[0x10] = uVar7;
            if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
              _dev_err(lVar1,"No sleep config specified!\n");
              uVar13 = (ulong)*(uint *)(plVar11 + 0x10);
            }
            else {
              uVar4 = pinctrl_select_state(plVar11[0xe],uVar7);
              if (uVar4 != 0) {
                uVar13 = (ulong)uVar4;
                pcVar10 = "Failed to set sleep configuration\n";
                goto LAB_00101bc0;
              }
              uVar13 = devm_clk_get(lVar1,"se-clk");
              plVar11[3] = uVar13;
              if (uVar13 < 0xfffffffffffff001) {
                uVar13 = devm_clk_get(*(undefined8 *)(param_1 + 0x70),"m-ahb");
                plVar11[0xc] = uVar13;
                if (uVar13 < 0xfffffffffffff001) {
                  uVar13 = devm_clk_get(*(undefined8 *)(param_1 + 0x70),"s-ahb");
                  plVar11[0xd] = uVar13;
                  if (uVar13 < 0xfffffffffffff001) {
                    uVar8 = platform_get_irq(param_1,0);
                    *(int *)(plVar11 + 0x14) = (int)uVar8;
                    if ((int)uVar8 < 0) {
                      _dev_err(lVar1,"Err getting IRQ\n");
                      uVar13 = (ulong)*(uint *)(plVar11 + 0x14);
                    }
                    else {
                      irq_modify_status(uVar8,0,0x1000);
                      uVar4 = devm_request_threaded_irq
                                        (lVar1,(int)plVar11[0x14],geni_spi_irq,0,4,"spi_geni",
                                         plVar11);
                      plVar12 = plVar11;
                      if (uVar4 == 0) goto LAB_00101b24;
                      uVar13 = (ulong)uVar4;
                      _dev_err(lVar1,"Request_irq failed:%d: err:%d\n",(int)plVar11[0x14],uVar13);
                    }
                    goto LAB_00101bc8;
                  }
                  pcVar10 = "Err getting S AHB clk %d\n";
                }
                else {
                  pcVar10 = "Err getting M AHB clk %d\n";
                }
                _dev_err(lVar1,pcVar10,uVar13 & 0xffffffff);
              }
              else {
                _dev_err(lVar1,"Err getting SE Core clk %d\n",uVar13 & 0xffffffff);
              }
            }
          }
        }
        goto LAB_00101bc8;
      }
    }
    pcVar10 = "Error geni_se_resources_init\n";
LAB_00101bc0:
    _dev_err(lVar1,pcVar10);
  }
  else {
LAB_00101b24:
    uVar8 = 0xffffffffffffffff;
    iVar3 = dma_set_mask(lVar1,0xffffffffffffffff);
    if (iVar3 != 0) {
      uVar8 = 0xffffffff;
      uVar4 = dma_set_mask(lVar1,0xffffffff);
      if (uVar4 == 0) goto LAB_00101b4c;
      uVar13 = (ulong)uVar4;
      pcVar10 = "could not set DMA mask\n";
      goto LAB_00101bc0;
    }
LAB_00101b4c:
    dma_set_coherent_mask(lVar1,uVar8);
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"spi-max-frequency",lVar6 + 0x3b8,1,0);
    if (iVar3 < 0) {
      pcVar10 = "Max frequency not specified.\n";
    }
    else {
      plVar9 = (long *)platform_get_resource_byname(param_1,0x200,"se_phys");
      if (plVar9 != (long *)0x0) {
        plVar11[0x11] = *plVar9;
        plVar11[0x12] = (plVar9[1] - *plVar9) + 1;
        lVar5 = devm_ioremap(lVar1,*plVar9,(plVar9[1] - *plVar9) + 1);
        plVar11[0x13] = lVar5;
        if (lVar5 == 0) {
          _dev_err(lVar1,"Err IO mapping iomem\n");
          uVar13 = 0xfffffff4;
          goto LAB_00101bc8;
        }
        *plVar11 = lVar5;
        *(undefined1 *)((long)plVar11 + 0x1e4) = 0;
        *(undefined4 *)(lVar6 + 0x3a8) = 0x27;
        *(undefined4 *)(lVar6 + 0x3b0) = 0xfffffff8;
        *(code **)(lVar6 + 0x560) = spi_geni_prepare_transfer_hardware;
        *(undefined2 *)(lVar6 + 0x3a2) = 4;
        *(code **)(lVar6 + 0x578) = spi_geni_prepare_message;
        *(code **)(lVar6 + 0x570) = spi_geni_unprepare_transfer_hardware;
        *(undefined1 *)(lVar6 + 0x52d) = 0;
        *(code **)(lVar6 + 0x580) = spi_geni_unprepare_message;
        *(code **)(lVar6 + 0x598) = spi_geni_transfer_one;
        *(undefined1 *)(lVar6 + 0x5c0) = 1;
        *(undefined4 *)(plVar11 + 0x1c) = 0;
        __init_swait_queue_head(plVar11 + 0x1d,"&x->wait",&init_completion___key);
        *(undefined4 *)(plVar11 + 0x2c) = 0;
        __init_swait_queue_head(plVar11 + 0x2d,"&x->wait",&init_completion___key);
        *(undefined4 *)(plVar11 + 0x30) = 0;
        __init_swait_queue_head(plVar11 + 0x31,"&x->wait",&init_completion___key);
        __mutex_init(plVar11 + 0x3d,"&geni_mas->spi_ssr.ssr_lock",&spi_geni_probe___key);
        if ((char)plVar11[0x4b] != '\0') {
          plVar11[0x49] = (long)ssr_spi_force_suspend;
          plVar11[0x4a] = (long)ssr_spi_force_resume;
        }
        __pm_runtime_set_status(lVar1,2);
        if ((*(char *)((long)plVar11 + 0x1cf) == '\0') && (*(char *)((long)plVar11 + 0x1d1) == '\0')
           ) {
          pm_runtime_set_autosuspend_delay(lVar1,0xfa);
          __pm_runtime_use_autosuspend(lVar1,1);
        }
        pm_runtime_enable(lVar1);
        lVar5 = ((long *)plVar11[0x15])[0xe];
        if (lVar5 == 0) {
          lVar5 = *(long *)plVar11[0x15];
        }
        lVar5 = ipc_log_context_create(4,lVar5,0);
        plVar11[0x37] = lVar5;
        if (lVar5 == 0) {
          _dev_err(lVar1,"Error creating IPC logs\n");
        }
        if (*(char *)((long)plVar11 + 0x1cf) == '\0') {
          ipc_log_string(plVar11[0x37],"%s: GENI_TO_CORE:%d CPU_TO_GENI:%d GENI_TO_DDR:%d\n",
                         "spi_geni_probe",(int)plVar12[7],(int)plVar12[9],(int)plVar12[0xb]);
          if (plVar11[0x15] != 0) {
            spi_trace_log(plVar11[0x15],"%s: GENI_TO_CORE:%d CPU_TO_GENI:%d GENI_TO_DDR:%d\n",
                          "spi_geni_probe",(int)plVar12[7],(int)plVar12[9],(int)plVar12[0xb]);
          }
          if ((*(char *)((long)plVar11 + 0x1cf) == '\0') &&
             (uVar4 = geni_icc_disable(plVar12), uVar4 != 0)) {
            uVar13 = (ulong)uVar4;
            pcVar10 = "%s: icc disable failed ret:%d\n";
            goto LAB_00101e8c;
          }
        }
        uVar4 = spi_register_controller(lVar6);
        if (uVar4 == 0) {
          uVar13 = sysfs_create_file_ns(plVar11[0x15],&dev_attr_spi_slave_state,0);
          uVar13 = uVar13 & 0xffffffff;
          device_create_file(plVar11[0x15],&dev_attr_capture_kpi);
          *(undefined1 *)((long)plVar11 + 0x1de) = 0;
          pcVar10 = "%s: completed %d\n";
          goto LAB_0010165c;
        }
        uVar13 = (ulong)uVar4;
        pcVar10 = "Failed to register SPI master\n";
        goto LAB_00101bc0;
      }
      pcVar10 = "Err getting IO region\n";
    }
    _dev_err(lVar1,pcVar10);
    uVar13 = 0xfffffffa;
  }
LAB_00101bc8:
  _dev_info(lVar1,"%s: ret:%d\n","spi_geni_probe",uVar13 & 0xffffffff);
  put_device(lVar6);
LAB_00101bec:
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// spi_geni_remove @ 00101ec8 size=360
// signature: undefined spi_geni_remove(void)
// callers: []
//------------------------------------------------------------

int spi_geni_remove(long param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0xa8);
  lVar9 = *(long *)(lVar11 + 0x98);
  sysfs_remove_file_ns(param_1 + 0x10,&dev_attr_spi_slave_state,0);
  device_remove_file(*(undefined8 *)(lVar9 + 0xa8),&dev_attr_capture_kpi);
  uVar10 = *(undefined8 *)(lVar9 + 0x18);
  uVar2 = *(undefined8 *)(lVar9 + 0x60);
  uVar3 = *(undefined8 *)(lVar9 + 0x68);
  clk_disable(uVar10);
  clk_unprepare(uVar10);
  clk_disable(uVar2);
  clk_unprepare(uVar2);
  clk_disable(uVar3);
  clk_unprepare(uVar3);
  iVar7 = geni_icc_disable(lVar9);
  if (iVar7 != 0) {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x1b8),"%s failing at geni_icc_disable ret=%d\n",
                   "spi_geni_remove",iVar7);
    if (*(long *)(lVar9 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar9 + 0xa8),"%s failing at geni_icc_disable ret=%d\n",
                    "spi_geni_remove",iVar7);
    }
  }
  spi_unregister_controller(lVar11);
  piVar1 = (int *)(param_1 + 0x208);
  iVar8 = *(int *)(param_1 + 0x208);
  do {
    if (iVar8 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      if (iVar4 != iVar8) goto LAB_00101fcc;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = iVar8 + -1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
LAB_00101fcc:
    bVar6 = iVar8 != iVar4;
    iVar8 = iVar4;
  } while (bVar6);
  __pm_runtime_disable(param_1 + 0x10,1);
  if (*(long *)(lVar9 + 0x1b8) != 0) {
    ipc_log_context_destroy();
  }
  if (*(long *)(lVar9 + 0x1c0) != 0) {
    ipc_log_context_destroy();
  }
  return iVar7;
}



//------------------------------------------------------------
// spi_slv_abort @ 00102048 size=56
// signature: undefined spi_slv_abort(void)
// callers: []
//------------------------------------------------------------

undefined8 spi_slv_abort(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  complete_all(lVar1 + 0x160);
  complete_all(lVar1 + 0x180);
  return 0;
}



//------------------------------------------------------------
// geni_spi_irq @ 00102084 size=1664
// signature: undefined geni_spi_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_spi_irq(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  code *pcVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  ulong uVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  ulong uVar17;
  long *plVar18;
  uint uVar19;
  long lVar20;
  int iVar21;
  
  lVar20 = *(long *)(param_2 + 0x1c0);
  if (lVar20 == 0) {
    uVar13 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_2 + 0x1c8) == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = sched_clock();
    ipc_log_string(lVar20,"%s:start at %llu nsec(%llu usec)\n","geni_spi_irq",uVar13,uVar13 / 1000);
  }
  if (*(int *)(*(long *)(param_2 + 0xa8) + 0x20c) == 2) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x1b8),"%s: device is suspended\n","geni_spi_irq");
    if (*(long *)(param_2 + 0xa8) == 0) {
      uVar9 = 0;
    }
    else {
      spi_trace_log(*(long *)(param_2 + 0xa8),"%s: device is suspended\n","geni_spi_irq");
      uVar9 = 0;
    }
    goto LAB_00102660;
  }
  if (*(char *)(param_2 + 0x218) != '\0') {
    *(undefined1 *)(param_2 + 0x1d2) = 0;
    complete(param_2 + 0xe0);
    _dev_err(*(undefined8 *)(param_2 + 0xa8),"IRQ at SSR down\n");
    return 1;
  }
  uVar9 = readl_relaxed(*(long *)(param_2 + 0x98) + 0x610);
  if (*(int *)(param_2 + 0x1a4) != 2) {
    if (*(int *)(param_2 + 0x1a4) == 1) {
      if ((uVar9 & 0xc000000) != 0) {
        iVar3 = *(int *)(param_2 + 0xb8);
        uVar10 = readl_relaxed(*(long *)(param_2 + 0x98) + 0x804);
        if ((*(char *)(param_2 + 0x218) == '\0') &&
           (lVar20 = *(long *)(param_2 + 0xd8), lVar20 != 0)) {
          iVar3 = iVar3 >> 3;
          uVar11 = uVar10 & 0x1ffffff;
          if ((int)uVar10 < 0) {
            uVar10 = uVar10 >> 0x1c & 7;
            bVar8 = uVar10 - 1 < 3;
            if (!bVar8) {
              uVar10 = 0;
            }
            uVar11 = uVar11 - bVar8;
          }
          else {
            uVar10 = 0;
          }
          iVar4 = *(int *)(param_2 + 200);
          iVar15 = 0;
          if (iVar4 != 0) {
            iVar15 = *(int *)(param_2 + 0xb8) / iVar4;
          }
          iVar21 = iVar3;
          if (*(int *)(param_2 + 0xb8) != iVar15 * iVar4) {
            iVar15 = iVar4 + 7;
            if (-1 < iVar4) {
              iVar15 = iVar4;
            }
            iVar21 = (iVar15 >> 3) + 1;
          }
          iVar15 = *(int *)(param_2 + 0xd0);
          iVar21 = uVar10 + iVar21 * uVar11;
          iVar4 = iVar15;
          if (iVar21 <= iVar15) {
            iVar4 = iVar21;
          }
          if (0 < iVar4) {
            lVar20 = *(long *)(lVar20 + 8) + (ulong)(uint)(*(int *)(lVar20 + 0x10) - iVar15);
            uVar17 = 0;
            do {
              if (*(char *)(param_2 + 0x218) != '\0') break;
              iVar15 = *(int *)(param_2 + 200);
              iVar21 = 0;
              if (iVar15 != 0) {
                iVar21 = *(int *)(param_2 + 0xb8) / iVar15;
              }
              iVar1 = iVar3;
              if (*(int *)(param_2 + 0xb8) != iVar21 * iVar15) {
                iVar21 = iVar15 + 7;
                if (-1 < iVar15) {
                  iVar21 = iVar15;
                }
                iVar1 = (iVar21 >> 3) + 1;
              }
              iVar21 = (int)uVar17;
              iVar15 = iVar4 - iVar21;
              if (iVar1 <= iVar4 - iVar21) {
                iVar15 = iVar1;
              }
              uVar12 = readl_relaxed(*(long *)(param_2 + 0x98) + 0x780);
              if (0 < iVar15) {
                uVar2 = (long)iVar21 + 1;
                *(char *)(lVar20 + iVar21) = (char)uVar12;
                uVar17 = uVar2;
                if (iVar15 != 1) {
                  uVar17 = (ulong)(iVar21 + 2U);
                  *(char *)(lVar20 + uVar2) = (char)((uint)uVar12 >> 8);
                  if (iVar15 != 2) {
                    *(char *)(lVar20 + (int)(iVar21 + 2U)) = (char)((uint)uVar12 >> 0x10);
                    if (iVar15 == 3) {
                      uVar17 = (ulong)(iVar21 + 3U);
                    }
                    else {
                      *(char *)(lVar20 + (int)(iVar21 + 3U)) = (char)((uint)uVar12 >> 0x18);
                      if (iVar15 != 4) goto LAB_00102700;
                      uVar17 = (ulong)(iVar21 + 4);
                    }
                  }
                }
              }
              iVar15 = (int)uVar17;
              uVar17 = uVar17 & 0xffffffff;
            } while (iVar15 < iVar4);
          }
          *(int *)(param_2 + 0xd0) = *(int *)(param_2 + 0xd0) - iVar4;
        }
      }
      if (((uVar9 >> 0x1e & 1) != 0) &&
         (plVar18 = *(long **)(param_2 + 0xd8), plVar18 != (long *)0x0)) {
        iVar3 = *(int *)(param_2 + 0xb8);
        iVar4 = *(int *)(param_2 + 200);
        iVar15 = 0;
        if (iVar4 != 0) {
          iVar15 = iVar3 / iVar4;
        }
        iVar21 = iVar3 >> 3;
        if (iVar3 != iVar15 * iVar4) {
          iVar15 = iVar4 + 7;
          if (-1 < iVar4) {
            iVar15 = iVar4;
          }
          iVar21 = (iVar15 >> 3) + 1;
        }
        iVar15 = *(int *)(param_2 + 0xcc);
        iVar21 = iVar21 * (*(int *)(param_2 + 0xb4) - *(int *)(param_2 + 0xbc));
        iVar4 = iVar15;
        if (iVar21 <= iVar15) {
          iVar4 = iVar21;
        }
        if (0 < iVar4) {
          iVar21 = 0;
          lVar20 = *plVar18 + (ulong)(uint)((int)plVar18[2] - iVar15);
          do {
            if (*(char *)(param_2 + 0x218) != '\0') break;
            iVar15 = *(int *)(param_2 + 200);
            iVar1 = 0;
            if (iVar15 != 0) {
              iVar1 = *(int *)(param_2 + 0xb8) / iVar15;
            }
            iVar16 = iVar3 >> 3;
            if (*(int *)(param_2 + 0xb8) != iVar1 * iVar15) {
              iVar1 = iVar15 + 7;
              if (-1 < iVar15) {
                iVar1 = iVar15;
              }
              iVar16 = (iVar1 >> 3) + 1;
            }
            iVar15 = iVar4 - iVar21;
            if (iVar16 <= iVar4 - iVar21) {
              iVar15 = iVar16;
            }
            if (iVar15 < 1) {
              uVar10 = 0;
            }
            else {
              lVar14 = (long)iVar21;
              uVar17 = lVar14 + 1;
              if (iVar15 == 1) {
                uVar10 = 0;
LAB_00102540:
                uVar6 = 0;
                iVar1 = (int)uVar17;
LAB_00102544:
                iVar21 = iVar1;
                uVar11 = uVar10;
                uVar19 = uVar6;
                uVar10 = 0;
              }
              else {
                uVar10 = (uint)*(byte *)(lVar20 + uVar17);
                uVar11 = (uint)*(byte *)(lVar20 + uVar17);
                uVar17 = (ulong)(iVar21 + 2U);
                if (iVar15 == 2) goto LAB_00102540;
                bVar5 = *(byte *)(lVar20 + (int)(iVar21 + 2U));
                uVar19 = (uint)bVar5;
                uVar6 = (uint)bVar5;
                iVar1 = iVar21 + 3;
                if (iVar15 == 3) goto LAB_00102544;
                if (iVar15 != 4) {
LAB_00102700:
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(1,0x102704);
                  (*pcVar7)();
                }
                uVar10 = (uint)*(byte *)(lVar20 + (iVar21 + 3));
                iVar21 = iVar21 + 4;
              }
              uVar10 = uVar19 << 0x10 | uVar10 << 0x18 | uVar11 << 8 |
                       (uint)*(byte *)(lVar20 + lVar14);
            }
            writel_relaxed(uVar10,*(long *)(param_2 + 0x98) + 0x700);
            DataSynchronizationBarrier(3,3,0);
          } while (iVar21 < iVar4);
        }
        iVar4 = *(int *)(param_2 + 0xcc) - iVar4;
        *(int *)(param_2 + 0xcc) = iVar4;
        if ((iVar4 == 0) && (*(char *)(param_2 + 0x218) == '\0')) {
          writel_relaxed(0,*(long *)(param_2 + 0x98) + 0x80c);
          DataSynchronizationBarrier(3,3,0);
        }
      }
      if ((uVar9 & 0x31) != 0) {
        *(undefined1 *)(param_2 + 0x1d2) = 1;
        if (*(int *)(param_2 + 0xcc) != 0) {
          writel_relaxed(0,*(long *)(param_2 + 0x98) + 0x80c);
          ipc_log_string(*(undefined8 *)(param_2 + 0x1b8),"%s:Premature Done.tx_rem%d bpw%d\n",
                         "geni_spi_irq",*(undefined4 *)(param_2 + 0xcc),
                         *(undefined4 *)(param_2 + 200));
          if (*(long *)(param_2 + 0xa8) != 0) {
            spi_trace_log(*(long *)(param_2 + 0xa8),"%s:Premature Done.tx_rem%d bpw%d\n",
                          "geni_spi_irq",*(undefined4 *)(param_2 + 0xcc),
                          *(undefined4 *)(param_2 + 200));
          }
        }
        if (*(int *)(param_2 + 0xd0) != 0) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x1b8),"%s:Premature Done.rx_rem%d bpw%d\n",
                         "geni_spi_irq",*(int *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 200));
          if (*(long *)(param_2 + 0xa8) != 0) {
            spi_trace_log(*(long *)(param_2 + 0xa8),"%s:Premature Done.rx_rem%d bpw%d\n",
                          "geni_spi_irq",*(undefined4 *)(param_2 + 0xd0),
                          *(undefined4 *)(param_2 + 200));
          }
        }
      }
    }
    goto LAB_00102660;
  }
  uVar10 = readl_relaxed(*(long *)(param_2 + 0x98) + 0xc40);
  uVar11 = readl_relaxed(*(long *)(param_2 + 0x98) + 0xd40);
  if (uVar10 != 0) {
    writel_relaxed(uVar10,*(long *)(param_2 + 0x98) + 0xc44);
  }
  if (uVar11 != 0) {
    writel_relaxed(uVar11,*(long *)(param_2 + 0x98) + 0xd44);
  }
  if ((uVar10 & 1) == 0) {
    if ((uVar11 & 1) == 0) goto LAB_00102218;
LAB_0010222c:
    *(undefined4 *)(param_2 + 0xd0) = 0;
    plVar18 = *(long **)(param_2 + 0xd8);
  }
  else {
    *(undefined4 *)(param_2 + 0xcc) = 0;
    if ((uVar11 & 1) != 0) goto LAB_0010222c;
LAB_00102218:
    plVar18 = *(long **)(param_2 + 0xd8);
  }
  if (plVar18 != (long *)0x0) {
    if (*plVar18 == 0) {
      if (((uVar11 & 1) != 0) && (plVar18[1] != 0)) {
LAB_00102264:
        iVar3 = *(int *)(param_2 + 0xd0);
joined_r0x00102298:
        if (iVar3 == 0) {
          *(undefined1 *)(param_2 + 0x1d2) = 1;
        }
      }
    }
    else if (plVar18[1] == 0) {
      if ((uVar10 & 1) != 0) {
        iVar3 = *(int *)(param_2 + 0xcc);
        goto joined_r0x00102298;
      }
    }
    else if (((uVar11 & uVar10 & 1) != 0) && (*(int *)(param_2 + 0xcc) == 0)) goto LAB_00102264;
  }
  if ((uVar9 & 0x30) == 0) {
    if (*(char *)(param_2 + 0x1d2) == '\0') {
      ipc_log_string(*(undefined8 *)(param_2 + 0x1b8),"Spurious IRQ!! DMA_TX:0x%x, DMA_RX:0x%x\n",
                     uVar10,uVar11);
      if (*(long *)(param_2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(param_2 + 0xa8),"Spurious IRQ!! DMA_TX:0x%x, DMA_RX:0x%x\n",uVar10,
                      uVar11);
      }
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x1d2) = 1;
  }
LAB_00102660:
  if (*(char *)(param_2 + 0x218) == '\0') {
    writel_relaxed(uVar9,*(long *)(param_2 + 0x98) + 0x618);
  }
  if (*(char *)(param_2 + 0x1d2) != '\0') {
    *(undefined1 *)(param_2 + 0x1d2) = 0;
    complete(param_2 + 0xe0);
  }
  lVar20 = *(long *)(param_2 + 0x1c0);
  if (((lVar20 != 0) && (uVar13 != 0)) && (*(int *)(param_2 + 0x1c8) != 0)) {
    lVar14 = sched_clock();
    ipc_log_string(lVar20,"%s:took %llu nsec(%llu usec)\n","geni_spi_irq",lVar14 - uVar13,
                   (lVar14 - uVar13) / 1000);
  }
  return 1;
}



//------------------------------------------------------------
// spi_geni_prepare_transfer_hardware @ 00102708 size=876
// signature: undefined spi_geni_prepare_transfer_hardware(void)
// callers: []
//------------------------------------------------------------

int spi_geni_prepare_transfer_hardware(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar4 = *(long *)(lVar5 + 0x1c0);
  if (lVar4 == 0) {
    uVar3 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar5 + 0x1c8) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","spi_geni_prepare_transfer_hardware",
                   uVar3,uVar3 / 1000);
  }
  lVar4 = lVar5 + 0x1e8;
  mutex_lock(lVar4);
  if (*(char *)(lVar5 + 0x218) == '\0') {
    if (*(char *)(lVar5 + 0x1cf) == '\0') {
      *(undefined1 *)(lVar5 + 0x1de) = 1;
      if ((*(ushort *)(*(long *)(lVar5 + 0xa8) + 0x200) & 7) != 0) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: System suspended\n",
                       "spi_geni_prepare_transfer_hardware");
        if (*(long *)(lVar5 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: System suspended\n",
                        "spi_geni_prepare_transfer_hardware");
        }
        *(undefined1 *)(lVar5 + 0x1de) = 0;
        mutex_unlock(lVar4);
        return -0xd;
      }
      if ((((*(char *)(lVar5 + 0x1cc) != '\0') && (*(char *)(lVar5 + 0x1cd) == '\0')) &&
          (*(char *)(lVar5 + 0x1d0) == '\0')) &&
         (iVar2 = pinctrl_select_state(*(undefined8 *)(lVar5 + 0x70),*(undefined8 *)(lVar5 + 0x78)),
         iVar2 != 0)) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: Error %d pinctrl_select_state\n",
                       "spi_geni_prepare_transfer_hardware",iVar2);
        if (*(long *)(lVar5 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: Error %d pinctrl_select_state\n",
                        "spi_geni_prepare_transfer_hardware",iVar2);
        }
      }
      if ((*(char *)(lVar5 + 0xc0) == '\0') || (*(char *)(lVar5 + 0x1cd) == '\0')) {
        iVar2 = __pm_runtime_resume(*(undefined8 *)(lVar5 + 0xa8),4);
        if (iVar2 < 0) {
          _dev_err(*(undefined8 *)(lVar5 + 0xa8),"%s:pm_runtime_get_sync failed %d\n",
                   "spi_geni_prepare_transfer_hardware",iVar2);
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1029e8);
          (*pcVar1)();
        }
        if ((*(char *)(lVar5 + 0xc0) == '\0') && (iVar2 = spi_geni_mas_setup(param_1), iVar2 != 0))
        {
          *(undefined1 *)(lVar5 + 0x1de) = 0;
          mutex_unlock(lVar4);
          ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s mas_setup failed: %d\n",
                         "spi_geni_prepare_transfer_hardware",iVar2);
          if (*(long *)(lVar5 + 0xa8) == 0) {
            _printk(&DAT_00108c2d,"spi_geni_prepare_transfer_hardware",iVar2);
          }
          else {
            _dev_err(*(long *)(lVar5 + 0xa8),"%s mas_setup failed: %d\n",
                     "spi_geni_prepare_transfer_hardware",iVar2);
          }
          if (*(long *)(lVar5 + 0xa8) == 0) {
            return iVar2;
          }
          spi_trace_log(*(long *)(lVar5 + 0xa8),"%s mas_setup failed: %d\n",
                        "spi_geni_prepare_transfer_hardware",iVar2);
          return iVar2;
        }
        if ((*(char *)(lVar5 + 0x1d1) != '\0') &&
           (iVar2 = *(int *)(*(long *)(lVar5 + 0xa8) + 0x1f8), iVar2 < 1)) {
          ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"resume usage count mismatch:%d",iVar2);
          if (*(long *)(lVar5 + 0xa8) != 0) {
            spi_trace_log(*(long *)(lVar5 + 0xa8),"resume usage count mismatch:%d",iVar2);
          }
        }
      }
      *(undefined1 *)(lVar5 + 0x219) = 1;
      mutex_unlock(lVar4);
      lVar4 = *(long *)(lVar5 + 0x1c0);
      if (lVar4 == 0) {
        return 0;
      }
      if (uVar3 == 0) {
        return 0;
      }
      if (*(int *)(lVar5 + 0x1c8) == 0) {
        return 0;
      }
      lVar5 = sched_clock();
      ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","spi_geni_prepare_transfer_hardware",
                     lVar5 - uVar3,(lVar5 - uVar3) / 1000);
      return 0;
    }
    *(undefined1 *)(lVar5 + 0x219) = 1;
    mutex_unlock(lVar4);
  }
  else {
    *(undefined1 *)(lVar5 + 0x219) = 0;
    mutex_unlock(lVar4);
    ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: bail out during SSR\n",
                   "spi_geni_prepare_transfer_hardware");
    if (*(long *)(lVar5 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: bail out during SSR\n",
                    "spi_geni_prepare_transfer_hardware");
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// spi_geni_prepare_message @ 00102a94 size=2268
// signature: undefined spi_geni_prepare_message(void)
// callers: []
//------------------------------------------------------------

int spi_geni_prepare_message(long param_1,long *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  char *pcVar16;
  char *pcVar17;
  uint *puVar18;
  undefined4 uVar19;
  long lVar20;
  long lVar21;
  long *plVar22;
  uint uVar23;
  long *plVar24;
  long lVar25;
  ulong local_78;
  undefined8 local_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  lVar20 = *(long *)(param_1 + 0x98);
  lVar21 = *(long *)(lVar20 + 0x1c0);
  if (lVar21 == 0) {
    uVar11 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar20 + 0x1c8) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = sched_clock();
    ipc_log_string(lVar21,"%s:start at %llu nsec(%llu usec)\n","spi_geni_prepare_message",uVar11,
                   uVar11 / 1000);
  }
  lVar21 = lVar20 + 0x1e8;
  mutex_lock(lVar21);
  if ((*(char *)(lVar20 + 0x218) != '\0') || (*(char *)(lVar20 + 0x219) == '\0')) {
    mutex_unlock(lVar21);
    ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"%s: bail out during SSR\n",
                   "spi_geni_prepare_message");
    if (*(long *)(lVar20 + 0xa8) == 0) {
      iVar7 = -0x16;
    }
    else {
      spi_trace_log(*(long *)(lVar20 + 0xa8),"%s: bail out during SSR\n","spi_geni_prepare_message")
      ;
      iVar7 = -0x16;
    }
    goto LAB_001030fc;
  }
  if (*(char *)(lVar20 + 0x1cd) == '\0') {
LAB_00102c44:
    lVar12 = *(long *)(lVar20 + 0xa8);
    if ((*(int *)(lVar12 + 0x20c) == 2) && (*(char *)(lVar20 + 0x1cf) == '\0')) {
      if ((*(ushort *)(lVar12 + 0x200) & 7) != 0) goto LAB_0010306c;
      iVar7 = __pm_runtime_resume(lVar12,4);
      if (iVar7 < 0) {
        _dev_err(*(undefined8 *)(lVar20 + 0xa8),"%s:pm_runtime_get_sync failed %d\n",
                 "spi_geni_prepare_message",iVar7);
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x103168);
        (*pcVar3)();
      }
    }
    lVar12 = *(long *)(param_1 + 0x98);
    uVar13 = readl_relaxed(*(long *)(lVar12 + 0x98) + 100);
    if ((*(ulong *)(lVar12 + 0x120) == 0) || (0xfffffffffffff000 < *(ulong *)(lVar12 + 0x120))) {
      if ((uVar13 & 1) != 0) {
        *(undefined4 *)(lVar20 + 0x1a4) = 0xffffffea;
LAB_001031a8:
        iVar7 = -0x16;
        _dev_err(*(undefined8 *)(lVar20 + 0xa8),"%s: Couldn\'t select mode %d\n",
                 "spi_geni_prepare_message",0xffffffea);
        goto LAB_001030a4;
      }
      *(undefined4 *)(lVar20 + 0x1a4) = 2;
    }
    else {
      bVar5 = *(ulong *)(lVar12 + 0x128) != 0;
      bVar4 = *(ulong *)(lVar12 + 0x128) < 0xfffffffffffff001;
      if (((uVar13 & 1) == 0) || (!bVar5 || !bVar4)) {
        bVar6 = (uVar13 & 1) != 0;
        uVar19 = 2;
        if (bVar6 && (!bVar5 || !bVar4)) {
          uVar19 = 0xffffffea;
        }
        *(undefined4 *)(lVar20 + 0x1a4) = uVar19;
        if (bVar6 && (!bVar5 || !bVar4)) goto LAB_001031a8;
      }
      else {
        uVar19 = 2;
        if (bVar5 && bVar4) {
          uVar19 = 3;
        }
        *(undefined4 *)(lVar20 + 0x1a4) = uVar19;
        if (bVar5 && bVar4) {
          memset(*(void **)(lVar20 + 0x110),0,0xb40);
          geni_se_select_mode(lVar20,3);
          plVar24 = (long *)*param_2;
          if (plVar24 == param_2) {
            iVar7 = 0;
          }
          else {
            do {
              uVar13 = plVar24[-0xe];
              if (uVar13 != 0) {
                plVar22 = *(long **)(lVar20 + 0x100);
                if (plVar22 == (long *)0x0) {
                  iVar7 = -0x16;
                }
                else {
                  lVar12 = plVar24[-0xd];
                  uVar14 = is_vmalloc_addr(uVar13);
                  if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
                    dma_map_single_attrs___already_done = 1;
                    uVar15 = dev_driver_string(plVar22);
                    lVar20 = plVar22[0xe];
                    if (lVar20 == 0) {
                      lVar20 = *plVar22;
                    }
                    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar15,lVar20);
                    /* WARNING: Does not return */
                    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102df8);
                    (*pcVar3)();
                  }
                  if ((uVar14 & 1) == 0) {
                    lVar12 = dma_map_page_attrs(plVar22,(((long)(uVar13 << 8) >> 8) + 0x8000000000U
                                                        >> 0xc) * 0x40 + -0x200000000,uVar13 & 0xfff
                                                ,(int)lVar12,2,0);
                    plVar24[-0xb] = lVar12;
                    if (lVar12 != -1) goto LAB_00102d58;
                    iVar7 = -5;
                  }
                  else {
                    iVar7 = -5;
                    plVar24[-0xb] = -1;
                  }
                }
                ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"%s: Mapping Rx buffer %d\n",
                               "spi_geni_map_buf",iVar7);
                if (*(long *)(lVar20 + 0xa8) == 0) {
                  _printk(&DAT_0010967a,"spi_geni_map_buf",iVar7);
                }
                else {
                  _dev_err(*(long *)(lVar20 + 0xa8),"%s: Mapping Rx buffer %d\n","spi_geni_map_buf",
                           iVar7);
                }
                lVar12 = *(long *)(lVar20 + 0xa8);
                if (lVar12 == 0) goto LAB_001030a4;
                pcVar16 = "%s: Mapping Rx buffer %d\n";
LAB_00103380:
                pcVar17 = "spi_geni_map_buf";
                goto LAB_00103388;
              }
LAB_00102d58:
              uVar13 = plVar24[-0xf];
              if (uVar13 != 0) {
                plVar22 = *(long **)(lVar20 + 0x100);
                if (plVar22 == (long *)0x0) {
                  iVar7 = -0x16;
                }
                else {
                  lVar12 = plVar24[-0xd];
                  uVar14 = is_vmalloc_addr(uVar13);
                  if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
                    dma_map_single_attrs___already_done = 1;
                    uVar15 = dev_driver_string(plVar22);
                    lVar20 = plVar22[0xe];
                    if (lVar20 == 0) {
                      lVar20 = *plVar22;
                    }
                    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar15,lVar20);
                    /* WARNING: Does not return */
                    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102e34);
                    (*pcVar3)();
                  }
                  if ((uVar14 & 1) == 0) {
                    lVar12 = dma_map_page_attrs(plVar22,(((long)(uVar13 << 8) >> 8) + 0x8000000000U
                                                        >> 0xc) * 0x40 + -0x200000000,uVar13 & 0xfff
                                                ,(int)lVar12,1,0);
                    plVar24[-0xc] = lVar12;
                    if (lVar12 != -1) goto LAB_00102ce4;
                    iVar7 = -5;
                  }
                  else {
                    iVar7 = -5;
                    plVar24[-0xc] = -1;
                  }
                }
                ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"%s: Mapping Tx buffer %d\n",
                               "spi_geni_map_buf",iVar7);
                if (*(long *)(lVar20 + 0xa8) == 0) {
                  _printk(&DAT_001094e0,"spi_geni_map_buf",iVar7);
                }
                else {
                  _dev_err(*(long *)(lVar20 + 0xa8),"%s: Mapping Tx buffer %d\n","spi_geni_map_buf",
                           iVar7);
                }
                lVar12 = *(long *)(lVar20 + 0xa8);
                if (lVar12 != 0) {
                  pcVar16 = "%s: Mapping Tx buffer %d\n";
                  goto LAB_00103380;
                }
                goto LAB_001030a4;
              }
LAB_00102ce4:
              plVar24 = (long *)*plVar24;
            } while (plVar24 != param_2);
            iVar7 = 0;
          }
          goto LAB_001030a4;
        }
      }
    }
    geni_se_select_mode(lVar20,2);
    lVar12 = *(long *)(param_1 + 0x98);
    lVar25 = param_2[2];
    uVar1 = *(uint *)(lVar25 + 0x3a8);
    uVar8 = readl_relaxed(*(long *)(lVar12 + 0x98) + 0x22c);
    uVar9 = readl_relaxed(*(long *)(lVar12 + 0x98) + 0x230);
    uVar10 = readl_relaxed(*(long *)(lVar12 + 0x98) + 0x224);
    local_78 = 0;
    local_70 = 0;
    if ((*(byte *)(lVar25 + 0x3a8) >> 2 & 1) != 0) {
      local_78 = 1L << ((ulong)*(byte *)(lVar25 + 0x3a4) & 0x3f);
    }
    puVar18 = *(uint **)(lVar25 + 0x3b8);
    if (puVar18 == (uint *)0x0) {
      uVar23 = 0;
    }
    else {
      uVar23 = puVar18[1] & 0x3ff | (*puVar18 & 0x3ff) << 10;
    }
    uVar19 = *(undefined4 *)(lVar25 + 0x3a0);
    uVar2 = *(undefined1 *)(lVar25 + 0x3a4);
    *(undefined4 *)(lVar12 + 0xc4) = uVar19;
    *(uint *)(lVar12 + 200) = (uint)*(byte *)(lVar25 + 0x3a5);
    iVar7 = get_spi_clk_cfg(uVar19,lVar12,(long)&local_70 + 4,&local_70);
    if (iVar7 == 0) {
      uVar9 = uVar9 & 0xfffffff8 | uVar9 & 3 | (uVar1 >> 1 & 1) << 2;
      uVar8 = uVar8 & 0xfffffffc | uVar1 >> 5 & 1;
      uVar1 = uVar10 & 0xfffffffe | uVar1 & 1;
      spi_setup_word_len(lVar12,*(undefined4 *)(lVar25 + 0x3a8),*(undefined1 *)(lVar25 + 0x3a5));
      writel_relaxed(uVar8,*(long *)(lVar12 + 0x98) + 0x22c);
      writel_relaxed(uVar2,*(long *)(lVar12 + 0x98) + 0x250);
      writel_relaxed(uVar1,*(long *)(lVar12 + 0x98) + 0x224);
      writel_relaxed(uVar9,*(long *)(lVar12 + 0x98) + 0x230);
      writel_relaxed(local_78 & 0xffffffff,*(long *)(lVar12 + 0x98) + 0x24c);
      writel_relaxed(uVar23,*(long *)(lVar12 + 0x98) + 0x278);
      ipc_log_string(*(undefined8 *)(lVar12 + 0x1b8),
                     "%s: Loopback:%d demux_sel:0x%x demux_op_inv:0x%x\n","setup_fifo_params",uVar8,
                     uVar2,local_78 & 0xffffffff);
      if (*(long *)(lVar12 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar12 + 0xa8),"%s: Loopback:%d demux_sel:0x%x demux_op_inv:0x%x\n",
                      "setup_fifo_params",uVar8,uVar2,local_78 & 0xffffffff);
      }
      ipc_log_string(*(undefined8 *)(lVar12 + 0x1b8),"%s:cpol %d cpha %d delay 0x%x\n",
                     "setup_fifo_params",uVar9,uVar1,uVar23);
      if (*(long *)(lVar12 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar12 + 0xa8),"%s:cpol %d cpha %d delay 0x%x\n","setup_fifo_params"
                      ,uVar9,uVar1,uVar23);
      }
      DataSynchronizationBarrier(3,3,0);
    }
    else {
      _dev_err(*(undefined8 *)(lVar12 + 0xa8),"Err setting clks ret(%d) for %d\n",iVar7,
               *(undefined4 *)(lVar12 + 0xc4));
    }
  }
  else if (*(char *)(lVar20 + 0xc0) == '\0') {
    *(undefined1 *)(lVar20 + 0xc0) = 1;
LAB_00102c14:
    if (*(char *)(lVar20 + 0x1ce) == '\0') goto LAB_00102c44;
    mutex_unlock(lVar21);
    iVar7 = spi_geni_lock_bus(param_1);
    mutex_lock(lVar21);
    if (*(char *)(lVar20 + 0x218) == '\0') {
      if (iVar7 == 0) goto LAB_00102c44;
      ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"%s failed: %d\n","spi_geni_prepare_message",
                     iVar7);
      if (*(long *)(lVar20 + 0xa8) == 0) {
        _printk(&DAT_00109141,"spi_geni_prepare_message",iVar7);
      }
      else {
        _dev_err(*(long *)(lVar20 + 0xa8),"%s failed: %d\n","spi_geni_prepare_message",iVar7);
      }
      lVar12 = *(long *)(lVar20 + 0xa8);
      if (lVar12 != 0) {
        pcVar16 = "%s failed: %d\n";
        pcVar17 = "spi_geni_prepare_message";
LAB_00103388:
        spi_trace_log(lVar12,pcVar16,pcVar17,iVar7);
      }
    }
  }
  else {
    if ((*(ushort *)(*(long *)(lVar20 + 0xa8) + 0x200) & 7) == 0) {
      iVar7 = __pm_runtime_resume(*(long *)(lVar20 + 0xa8),4);
      if (iVar7 < 0) {
        _dev_err(*(undefined8 *)(lVar20 + 0xa8),"%s:pm_runtime_get_sync failed %d\n",
                 "spi_geni_prepare_message",iVar7);
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1031f0);
        (*pcVar3)();
      }
      if ((*(char *)(lVar20 + 0x1d1) != '\0') &&
         (iVar7 = *(int *)(*(long *)(lVar20 + 0xa8) + 0x1f8), iVar7 < 1)) {
        ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"resume usage count mismatch:%d",iVar7);
        if (*(long *)(lVar20 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar20 + 0xa8),"resume usage count mismatch:%d",iVar7);
        }
      }
      goto LAB_00102c14;
    }
LAB_0010306c:
    ipc_log_string(*(undefined8 *)(lVar20 + 0x1b8),"%s: System suspended\n",
                   "spi_geni_prepare_message");
    if (*(long *)(lVar20 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar20 + 0xa8),"%s: System suspended\n","spi_geni_prepare_message");
    }
    iVar7 = -0xd;
  }
LAB_001030a4:
  mutex_unlock(lVar21);
  lVar21 = *(long *)(lVar20 + 0x1c0);
  if (((lVar21 != 0) && (uVar11 != 0)) && (*(int *)(lVar20 + 0x1c8) != 0)) {
    lVar20 = sched_clock();
    ipc_log_string(lVar21,"%s:took %llu nsec(%llu usec)\n","spi_geni_prepare_message",
                   lVar20 - uVar11,(lVar20 - uVar11) / 1000);
  }
LAB_001030fc:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// spi_geni_unprepare_message @ 0010339c size=512
// signature: undefined spi_geni_unprepare_message(void)
// callers: []
//------------------------------------------------------------

undefined8 spi_geni_unprepare_message(long param_1,undefined8 *param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  lVar4 = *(long *)(lVar6 + 0x1c0);
  if (lVar4 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar6 + 0x1c8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","spi_geni_unprepare_message",uVar2,
                   uVar2 / 1000);
  }
  *(undefined8 *)(lVar6 + 0xc4) = 0;
  if (*(int *)(lVar6 + 0x1a4) == 3) {
    for (puVar5 = (undefined8 *)*param_2; puVar5 != param_2; puVar5 = (undefined8 *)*puVar5) {
      if ((puVar5[-0xe] != 0) && (puVar5[-0xb] != -1)) {
        dma_unmap_page_attrs
                  (*(undefined8 *)(lVar6 + 0x100),puVar5[-0xb],*(undefined4 *)(puVar5 + -0xd),2,0);
      }
      if ((puVar5[-0xf] != 0) && (puVar5[-0xc] != -1)) {
        dma_unmap_page_attrs
                  (*(undefined8 *)(lVar6 + 0x100),puVar5[-0xc],*(undefined4 *)(puVar5 + -0xd),1,0);
      }
    }
  }
  if (*(char *)(lVar6 + 0x1cd) != '\0') {
    if (*(char *)(lVar6 + 0x1ce) != '\0') {
      spi_geni_unlock_bus(param_1);
    }
    lVar4 = *(long *)(lVar6 + 0xa8);
    if (*(char *)(lVar6 + 0x1d1) == '\0') {
      if ((*(int *)(lVar4 + 0x20c) != 2) && ((*(ushort *)(lVar4 + 0x200) & 7) == 0)) {
        uVar3 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar4 + 0x220) = uVar3;
        __pm_runtime_suspend(*(undefined8 *)(lVar6 + 0xa8),0xd);
      }
    }
    else {
      __pm_runtime_idle(lVar4,4);
      iVar1 = *(int *)(*(long *)(lVar6 + 0xa8) + 0x1f8);
      if (iVar1 < 0) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"suspend usage count mismatch:%d",iVar1);
        if (*(long *)(lVar6 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar6 + 0xa8),"suspend usage count mismatch:%d",iVar1);
        }
      }
    }
  }
  lVar4 = *(long *)(lVar6 + 0x1c0);
  if (((lVar4 != 0) && (uVar2 != 0)) && (*(int *)(lVar6 + 0x1c8) != 0)) {
    lVar6 = sched_clock();
    ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","spi_geni_unprepare_message",lVar6 - uVar2
                   ,(lVar6 - uVar2) / 1000);
  }
  return 0;
}



//------------------------------------------------------------
// spi_geni_transfer_one @ 001035a0 size=5336
// signature: undefined spi_geni_transfer_one(void)
// callers: []
//------------------------------------------------------------

ulong spi_geni_transfer_one(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  ulong *puVar2;
  uint *puVar3;
  ulong *puVar4;
  byte bVar5;
  undefined2 uVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long *plVar14;
  char *pcVar15;
  ulong uVar16;
  uint uVar17;
  int *piVar18;
  long lVar19;
  code *pcVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  long lVar25;
  long *plVar26;
  long lVar27;
  long lVar28;
  uint *puVar29;
  bool bVar30;
  ulong *puVar31;
  uint local_8c;
  undefined8 local_70;
  long local_68;
  
  lVar27 = sp_el0;
  local_68 = *(long *)(lVar27 + 0x638);
  plVar26 = *(long **)(param_1 + 0x98);
  lVar27 = plVar26[0x38];
  if (lVar27 == 0) {
    uVar12 = 0xffffffffffffffea;
    lVar27 = *param_3;
joined_r0x00103644:
    if (lVar27 != 0) goto LAB_00103660;
LAB_00103658:
    if (param_3[1] != 0) goto LAB_00103660;
    lVar27 = plVar26[0x15];
    pcVar15 = "Invalid xfer both tx rx are NULL\n";
  }
  else {
    if ((int)plVar26[0x39] == 0) {
      uVar12 = 0;
      lVar27 = *param_3;
      goto joined_r0x00103644;
    }
    uVar12 = sched_clock();
    ipc_log_string(lVar27,"%s:start at %llu nsec(%llu usec)\n","spi_geni_transfer_one",uVar12,
                   uVar12 / 1000);
    if (*param_3 == 0) goto LAB_00103658;
LAB_00103660:
    if ((int)param_3[2] != 0) {
      plVar1 = plVar26 + 0x3d;
      mutex_lock(plVar1);
      if (((char)plVar26[0x43] != '\0') || (*(char *)((long)plVar26 + 0x219) == '\0')) {
        mutex_unlock(plVar1);
        ipc_log_string(plVar26[0x37],"%s: bail out during SSR\n","spi_geni_transfer_one");
        if (plVar26[0x15] == 0) {
          puVar29 = (uint *)0xffffffea;
        }
        else {
          spi_trace_log(plVar26[0x15],"%s: bail out during SSR\n","spi_geni_transfer_one");
          puVar29 = (uint *)0xffffffea;
        }
        goto LAB_00104a0c;
      }
      if (*(int *)(plVar26[0x15] + 0x20c) == 2) {
        mutex_unlock(plVar1);
        ipc_log_string(plVar26[0x37],"%s: device is PM suspended\n","spi_geni_transfer_one");
        if (plVar26[0x15] == 0) {
          _printk(&DAT_00109843,"spi_geni_transfer_one");
        }
        else {
          _dev_err(plVar26[0x15],"%s: device is PM suspended\n","spi_geni_transfer_one");
        }
        if (plVar26[0x15] == 0) {
          puVar29 = (uint *)0xfffffff3;
        }
        else {
          spi_trace_log(plVar26[0x15],"%s: device is PM suspended\n","spi_geni_transfer_one");
          puVar29 = (uint *)0xfffffff3;
        }
        goto LAB_00104a0c;
      }
      uVar8 = 0;
      if (*(uint *)(param_3 + 0xb) != 0) {
        uVar8 = (uint)((int)param_3[2] * 8000) / *(uint *)(param_3 + 0xb);
      }
      iVar21 = (int)plVar26[0x3c];
      if ((iVar21 == 0) && (iVar21 = 0xfa, *(char *)(param_1 + 0x3bf) != '\0')) {
        iVar21 = 0x32;
      }
      iVar21 = iVar21 + uVar8;
      ipc_log_string(plVar26[0x37],"current xfer_timeout:%lu ms.\n",iVar21);
      if (plVar26[0x15] != 0) {
        spi_trace_log(plVar26[0x15],"current xfer_timeout:%lu ms.\n",iVar21);
      }
      uVar13 = __msecs_to_jiffies(iVar21);
      if (*(int *)((long)plVar26 + 0x1a4) == 3) {
        plVar26[0x35] = 0;
        *(undefined4 *)(plVar26 + 0x36) = 0;
        *(undefined1 *)(plVar26 + 0x34) = 0;
        *(undefined4 *)(plVar26 + 0x2c) = 0;
        *(undefined4 *)(plVar26 + 0x30) = 0;
        mutex_unlock(plVar1);
        lVar28 = plVar26[0x22];
        lVar27 = plVar26[0x36];
        if ((*(char *)((long)plVar26 + 0x1cf) == '\0') || ((char)plVar26[0x3b] == '\0')) {
LAB_00103bac:
          piVar18 = *(int **)(param_2 + 0x3b8);
          if (piVar18 == (int *)0x0) {
            iVar23 = 0;
            uVar8 = 0;
          }
          else {
            iVar23 = *piVar18;
            uVar8 = piVar18[1];
          }
          bVar5 = *(byte *)((long)param_3 + 0x4a);
          uVar17 = (uint)bVar5;
          if ((*(uint *)(plVar26 + 0x19) == (uint)bVar5) &&
             ((int)param_3[0xb] == *(int *)((long)plVar26 + 0xc4))) {
            puVar29 = (uint *)0x0;
            uVar8 = 0;
          }
          else {
            *(uint *)(plVar26 + 0x19) = (uint)bVar5;
            lVar25 = param_3[0xb];
            local_70 = 0;
            lVar19 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
            *(int *)((long)plVar26 + 0xc4) = (int)lVar25;
            uVar17 = *(uint *)(param_2 + 0x3a8);
            puVar29 = (uint *)(lVar19 + 0x20);
            if ((puVar29 != (uint *)0x0) &&
               (puVar29 < (uint *)0xfffffffffffff000 || lVar19 == -0x1020)) {
              bVar5 = *(byte *)((long)param_3 + 0x4a);
              if (*(char *)((long)plVar26 + 0x1cf) == '\0') {
                iVar10 = get_spi_clk_cfg((int)lVar25,plVar26,&local_70,(long)&local_70 + 4);
                if (iVar10 != 0) {
                  _dev_err(plVar26[0x15],"%s:Err setting clks:%d\n","setup_config0_tre",iVar10);
                  puVar29 = (uint *)(long)iVar10;
                  goto LAB_00103db0;
                }
                uVar9 = local_70._4_4_;
              }
              else {
                uVar11 = readl_relaxed(plVar26[0x13] + 0x7c);
                local_70 = CONCAT44(local_70._4_4_,uVar11);
                uVar9 = readl_relaxed(plVar26[0x13] + 0x48);
                uVar9 = uVar9 >> 4 & 0xfff;
              }
              uVar24 = uVar17 >> 5 & 1 | (uVar17 & 3) << 4;
              uVar17 = bVar5 - 4 & 0xff;
              *puVar29 = uVar17 | uVar24 << 8 | 0x3000000;
              *(uint *)(lVar19 + 0x24) = uVar8 | iVar23 << 8;
              *(uint *)(lVar19 + 0x28) = uVar9 | (int)local_70 << 0x10;
              *(undefined4 *)(lVar19 + 0x2c) = 0x220001;
              ipc_log_string(plVar26[0x37],"%s: flags 0x%x word %d pack %d freq %d idx %d div %d\n",
                             "setup_config0_tre",uVar24,uVar17,3,
                             *(undefined4 *)((long)plVar26 + 0xc4),local_70 & 0xffffffff,uVar9);
              if (plVar26[0x15] != 0) {
                spi_trace_log(plVar26[0x15],"%s: flags 0x%x word %d pack %d freq %d idx %d div %d\n"
                              ,"setup_config0_tre",uVar24,uVar17,3,
                              *(undefined4 *)((long)plVar26 + 0xc4),local_70 & 0xffffffff,uVar9);
              }
              ipc_log_string(plVar26[0x37],"%s: cs_clk_delay %d inter_words_delay %d\n",
                             "setup_config0_tre",iVar23,uVar8);
              if (plVar26[0x15] != 0) {
                spi_trace_log(plVar26[0x15],"%s: cs_clk_delay %d inter_words_delay %d\n",
                              "setup_config0_tre",iVar23,uVar8);
              }
            }
LAB_00103db0:
            if ((puVar29 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < puVar29)) {
              _dev_err(plVar26[0x15],"%s:Err setting c0tre:%d\n","setup_gsi_xfer",0);
              goto LAB_00104408;
            }
            uVar17 = *(uint *)(plVar26 + 0x19);
            uVar8 = 1;
          }
          if ((uVar17 & 3) == 0) {
            uVar9 = (int)param_3[2] << 3;
          }
          else {
            uVar24 = uVar17 + 7;
            if (-1 < (int)uVar17) {
              uVar24 = uVar17;
            }
            uVar9 = *(uint *)(param_3 + 2);
            uVar17 = ((int)uVar24 >> 3) + 1;
          }
          uVar24 = 0;
          if (uVar17 != 0) {
            uVar24 = uVar9 / uVar17;
          }
          lVar25 = lVar28 + (long)(int)lVar27 * 0x168;
          bVar7 = param_3[1] == 0;
          if (*param_3 == 0) {
            if (param_3[1] == 0) {
              bVar30 = false;
              uVar17 = 1;
              local_8c = 0;
              bVar7 = true;
            }
            else {
              uVar17 = 0;
              uVar8 = uVar8 + 1;
              bVar30 = true;
              local_8c = 2;
              bVar7 = false;
            }
          }
          else {
            bVar30 = !bVar7;
            local_8c = 3;
            if (bVar7) {
              local_8c = 1;
            }
            uVar8 = uVar8 | 2;
            uVar9 = 0;
            if (!bVar7) {
              uVar9 = uVar24;
            }
            uVar17 = 1;
            uVar24 = uVar9;
          }
          puVar2 = (ulong *)(lVar25 + 0x60);
          if ((*(long *)(param_1 + 0x5b8) == 0) && ((*(ushort *)(param_3 + 9) >> 2 & 1) == 0)) {
            iVar23 = (uint)(param_3[0xf] != *(long *)(param_1 + 0x500)) << 2;
          }
          else {
            iVar23 = 0;
          }
          lVar19 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
          puVar3 = (uint *)(lVar19 + 0x30);
          if ((puVar3 != (uint *)0x0) && (puVar3 < (uint *)0xfffffffffffff000 || lVar19 == -0x1030))
          {
            bVar5 = *(byte *)(param_2 + 0x3a4);
            uVar9 = 0x200000;
            if (!bVar7) {
              uVar9 = 0x200800;
            }
            uVar22 = uVar17;
            if (uVar17 == 0) {
              uVar22 = 0x100;
            }
            *puVar3 = (uint)bVar5 << 8 | iVar23 << 0x18 | local_8c;
            *(undefined4 *)(lVar19 + 0x34) = 0;
            *(uint *)(lVar19 + 0x38) = uVar24;
            *(uint *)(lVar19 + 0x3c) = uVar22 | uVar9;
            ipc_log_string(plVar26[0x37],
                           "%s: rx len %d flags 0x%x cs %d cmd %d eot %d eob %d chain %d\n",
                           "setup_go_tre",uVar24,iVar23,bVar5,local_8c,0,uVar17 ^ 1,uVar17);
            if (plVar26[0x15] != 0) {
              spi_trace_log(plVar26[0x15],
                            "%s: rx len %d flags 0x%x cs %d cmd %d eot %d eob %d chain %d\n",
                            "setup_go_tre",uVar24,iVar23,(uint)bVar5,local_8c,0,uVar17 ^ 1,uVar17);
            }
          }
          puVar4 = (ulong *)(lVar25 + 0xc0);
          sg_init_table(puVar2,uVar8);
          if (!bVar7) {
            sg_init_table(puVar4,1);
          }
          puVar31 = puVar2;
          if (puVar29 != (uint *)0x0) {
            puVar31 = (ulong *)(lVar25 + 0x80);
            *puVar2 = (*puVar2 & 3 | ((((long)puVar29 << 8) >> 8) + 0x8000000000U >> 0xc) << 6) -
                      0x200000000;
            *(uint *)(lVar25 + 0x68) = (uint)puVar29 & 0xfff;
            *(undefined4 *)(lVar25 + 0x6c) = 0x10;
          }
          *(uint *)(puVar31 + 1) = (uint)puVar3 & 0xfff;
          *(undefined4 *)((long)puVar31 + 0xc) = 0x10;
          *puVar31 = (*puVar31 & 3 | (((long)puVar3 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
                     0x200000000;
          *(long *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0x158) = param_1;
          *(long **)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0x160) = param_3;
          if (bVar7) {
LAB_001041a0:
            if ((local_8c & 1) != 0) {
              lVar27 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
              puVar29 = (uint *)(lVar27 + 0x40);
              if ((puVar29 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < puVar29)) {
                lVar27 = plVar26[0x15];
                pcVar15 = "Err setting up tx tre\n";
                goto LAB_00104720;
              }
              lVar28 = param_3[3];
              uVar17 = *(uint *)(param_3 + 2);
              *puVar29 = (uint)lVar28;
              *(int *)(lVar27 + 0x44) = (int)((ulong)lVar28 >> 0x20);
              *(uint *)(lVar27 + 0x48) = uVar17 & 0xffffff;
              *(undefined4 *)(lVar27 + 0x4c) = 0x100200;
              puVar31[4] = (puVar31[4] & 3 |
                           (((long)puVar29 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000
              ;
              *(uint *)(puVar31 + 5) = (uint)puVar29 & 0xfff;
              *(undefined4 *)((long)puVar31 + 0x2c) = 0x10;
              *(int *)(plVar26 + 0x35) = (int)plVar26[0x35] + 1;
            }
            plVar14 = (long *)plVar26[0x24];
            lVar27 = plVar26[0x22];
            iVar23 = (int)plVar26[0x36];
            uVar13 = 0;
            if (plVar14 != (long *)0x0) {
              if ((*plVar14 == 0) ||
                 (pcVar20 = *(code **)(*plVar14 + 0x108), pcVar20 == (code *)0x0)) {
                uVar13 = 0;
              }
              else {
                if (*(int *)(pcVar20 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(0x822a,0x10427c);
                  (*pcVar20)();
                }
                uVar13 = (*pcVar20)(plVar14,lVar27 + (long)iVar23 * 0x168 + 0x60,uVar8,1,3,0);
                lVar27 = plVar26[0x22];
                iVar23 = (int)plVar26[0x36];
              }
            }
            *(undefined8 *)(lVar27 + (long)iVar23 * 0x168 + 0x148) = uVar13;
            uVar16 = *(ulong *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0x148);
            if ((uVar16 == 0) || (0xfffffffffffff000 < uVar16)) {
              lVar27 = plVar26[0x15];
              pcVar15 = "Err setting up tx desc\n";
LAB_00104734:
              _dev_err(lVar27,pcVar15);
              puVar29 = (uint *)0xfffffffb;
            }
            else {
              *(code **)(uVar16 + 0x28) = spi_gsi_tx_callback;
              lVar27 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
              *(long *)(*(long *)(lVar27 + 0x148) + 0x38) = lVar27 + 0xe8;
              lVar27 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
              *(long *)(lVar27 + 0x108) = lVar27 + 0x158;
              pcVar20 = *(code **)(*(long *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 +
                                            0x148) + 0x18);
              if (*(int *)(pcVar20 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
                pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x104320);
                (*pcVar20)();
              }
              uVar11 = (*pcVar20)();
              *(undefined4 *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0xe0) = uVar11;
              if (*(int *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0xe0) < 0) {
                _dev_err(plVar26[0x15],"%s: dmaengine_submit failed (%d)\n","setup_gsi_xfer");
                plVar14 = (long *)plVar26[0x24];
LAB_001047b0:
                pcVar20 = *(code **)(*plVar14 + 0x148);
                if (pcVar20 == (code *)0x0) {
                  puVar29 = (uint *)0xffffffea;
                }
                else {
                  if (*(int *)(pcVar20 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x1047d4);
                    (*pcVar20)();
                  }
                  (*pcVar20)();
                  puVar29 = (uint *)0xffffffea;
                }
              }
              else {
                if (bVar7) {
                  plVar14 = plVar26 + 0x24;
                }
                else {
                  pcVar20 = *(code **)(*(long *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 +
                                                0x150) + 0x18);
                  if (*(int *)(pcVar20 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x10437c);
                    (*pcVar20)();
                  }
                  uVar11 = (*pcVar20)();
                  *(undefined4 *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0xe4) = uVar11;
                  if (*(int *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0xe4) < 0) {
                    _dev_err(plVar26[0x15],"%s: dmaengine_submit failed (%d)\n","setup_gsi_xfer");
                    plVar14 = (long *)plVar26[0x25];
                    goto LAB_001047b0;
                  }
                  if (*(int *)(*(code **)(*(long *)plVar26[0x24] + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x1043c8);
                    (*pcVar20)();
                  }
                  (**(code **)(*(long *)plVar26[0x24] + 0x160))();
                  plVar14 = plVar26 + 0x25;
                }
                if (*(int *)(*(code **)(*(long *)*plVar14 + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x1043f4);
                  (*pcVar20)();
                }
                (**(code **)(*(long *)*plVar14 + 0x160))();
                puVar29 = (uint *)0x0;
                *(int *)(plVar26 + 0x36) = (int)plVar26[0x36] + 1;
              }
            }
          }
          else {
            lVar25 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
            puVar29 = (uint *)(lVar25 + 0x50);
            if ((puVar29 != (uint *)0x0) && (puVar29 < (uint *)0xfffffffffffff001)) {
              lVar19 = param_3[4];
              uVar17 = *(uint *)(param_3 + 2);
              *puVar29 = (uint)lVar19;
              *(int *)(lVar25 + 0x54) = (int)((ulong)lVar19 >> 0x20);
              *(uint *)(lVar25 + 0x58) = uVar17 & 0xffffff;
              *(undefined4 *)(lVar25 + 0x5c) = 0x100000;
              uVar16 = *puVar4;
              lVar28 = lVar28 + (long)(int)lVar27 * 0x168;
              *(uint *)(lVar28 + 200) = (uint)puVar29 & 0xfff;
              *(undefined4 *)(lVar28 + 0xcc) = 0x10;
              *puVar4 = (uVar16 & 3 | (((long)puVar29 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
                        0x200000000;
              plVar14 = (long *)plVar26[0x25];
              lVar27 = plVar26[0x22];
              iVar23 = (int)plVar26[0x36];
              uVar13 = 0;
              if (plVar14 != (long *)0x0) {
                if ((*plVar14 == 0) ||
                   (pcVar20 = *(code **)(*plVar14 + 0x108), pcVar20 == (code *)0x0)) {
                  uVar13 = 0;
                }
                else {
                  if (*(int *)(pcVar20 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x822b,0x10411c);
                    (*pcVar20)();
                  }
                  uVar13 = (*pcVar20)(plVar14,lVar27 + (long)iVar23 * 0x168 + 0xc0,bVar30,2,3,0);
                  lVar27 = plVar26[0x22];
                  iVar23 = (int)plVar26[0x36];
                }
              }
              *(undefined8 *)(lVar27 + (long)iVar23 * 0x168 + 0x150) = uVar13;
              uVar16 = *(ulong *)(plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168 + 0x150);
              if ((uVar16 != 0) && (uVar16 < 0xfffffffffffff001)) {
                *(code **)(uVar16 + 0x28) = spi_gsi_rx_callback;
                lVar27 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
                *(long *)(*(long *)(lVar27 + 0x150) + 0x38) = lVar27 + 0x118;
                lVar27 = plVar26[0x22] + (long)(int)plVar26[0x36] * 0x168;
                *(long *)(lVar27 + 0x138) = lVar27 + 0x158;
                *(int *)((long)plVar26 + 0x1ac) = *(int *)((long)plVar26 + 0x1ac) + 1;
                goto LAB_001041a0;
              }
              lVar27 = plVar26[0x15];
              pcVar15 = "Err setting up rx desc\n";
              goto LAB_00104734;
            }
            lVar27 = plVar26[0x15];
            pcVar15 = "Err setting up rx tre\n";
LAB_00104720:
            _dev_err(lVar27,pcVar15);
          }
        }
        else {
          ipc_log_string(plVar26[0x37],"%s doing gsi lock, due to levm gsi reset\n","setup_gsi_xfer"
                        );
          if (plVar26[0x15] != 0) {
            spi_trace_log(plVar26[0x15],"%s doing gsi lock, due to levm gsi reset\n",
                          "setup_gsi_xfer");
          }
          uVar8 = spi_geni_lock_bus(param_1);
          if (uVar8 == 0) {
            *(undefined1 *)(plVar26 + 0x3b) = 0;
            goto LAB_00103bac;
          }
          puVar29 = (uint *)(ulong)uVar8;
          ipc_log_string(plVar26[0x37],"%s lock bus failed: %d\n","setup_gsi_xfer",puVar29);
          if (plVar26[0x15] != 0) {
            spi_trace_log(plVar26[0x15],"%s lock bus failed: %d\n","setup_gsi_xfer",puVar29);
          }
        }
LAB_00104408:
        mutex_lock(plVar1);
        if ((char)plVar26[0x43] == '\0') {
          if ((int)puVar29 != 0) {
            ipc_log_string(plVar26[0x37],"setup_gsi_xfer failed: %d\n",(ulong)puVar29 & 0xffffffff);
            if (plVar26[0x15] == 0) {
              _printk(&DAT_00109716,(ulong)puVar29 & 0xffffffff);
            }
            else {
              _dev_err(plVar26[0x15],"setup_gsi_xfer failed: %d\n",(ulong)puVar29 & 0xffffffff);
            }
            if (plVar26[0x15] != 0) {
              spi_trace_log(plVar26[0x15],"setup_gsi_xfer failed: %d\n",(ulong)puVar29 & 0xffffffff)
              ;
            }
            plVar26[0x1b] = 0;
LAB_001049b4:
            geni_spi_se_dump_dbg_regs(plVar26,plVar26[0x13],plVar26[0x37]);
            mutex_unlock(plVar1);
            *(undefined1 *)((long)plVar26 + 0x1de) = 0;
            pcVar20 = *(code **)(*(long *)plVar26[0x24] + 0x148);
            if (pcVar20 != (code *)0x0) {
              if (*(int *)(pcVar20 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
                pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x1049f8);
                (*pcVar20)();
              }
              (*pcVar20)();
            }
            if (*(char *)((long)plVar26 + 0x1cf) != '\0') {
              *(undefined1 *)(plVar26 + 0x3b) = 1;
            }
            goto LAB_00104a0c;
          }
          if (0 < (int)plVar26[0x35]) {
            iVar23 = 0;
            do {
              lVar27 = wait_for_completion_timeout(plVar26 + 0x2c,iVar21);
              if (lVar27 == 0) {
                ipc_log_string(plVar26[0x37],"Tx[%d] timeout%lu\n",iVar23,0);
                if (plVar26[0x15] == 0) {
                  _printk(&DAT_00108932,iVar23,0);
                }
                else {
                  _dev_err(plVar26[0x15],"Tx[%d] timeout%lu\n",iVar23,0);
                }
                if (plVar26[0x15] != 0) {
                  spi_trace_log(plVar26[0x15],"Tx[%d] timeout%lu\n",iVar23,0);
                }
                bVar7 = false;
                puVar29 = (uint *)0xffffff92;
                bVar30 = true;
                goto LAB_00104468;
              }
              iVar23 = iVar23 + 1;
            } while (iVar23 < (int)plVar26[0x35]);
          }
          bVar30 = false;
          puVar29 = (uint *)0x0;
          bVar7 = true;
LAB_00104468:
          if (0 < *(int *)((long)plVar26 + 0x1ac)) {
            iVar23 = 0;
            do {
              lVar27 = wait_for_completion_timeout(plVar26 + 0x30,iVar21);
              if (lVar27 == 0) {
                ipc_log_string(plVar26[0x37],"Rx[%d] timeout%lu\n",iVar23,0);
                if (plVar26[0x15] == 0) {
                  _printk(&DAT_00108a06,iVar23,0);
                }
                else {
                  _dev_err(plVar26[0x15],"Rx[%d] timeout%lu\n",iVar23,0);
                }
                if (plVar26[0x15] != 0) {
                  spi_trace_log(plVar26[0x15],"Rx[%d] timeout%lu\n",iVar23,0);
                }
                puVar29 = (uint *)0xffffff92;
                goto LAB_001049b4;
              }
              iVar23 = iVar23 + 1;
            } while (iVar23 < *(int *)((long)plVar26 + 0x1ac));
          }
          if ((!bVar30) && ((char)plVar26[0x34] != '\0')) {
            puVar29 = (uint *)0xfffffffb;
            *(undefined1 *)(plVar26 + 0x34) = 0;
            goto LAB_001049b4;
          }
          if (!bVar7) goto LAB_001049b4;
LAB_001044bc:
          mutex_unlock(plVar1);
          lVar27 = plVar26[0x38];
          if (lVar27 != 0) {
            puVar29 = (uint *)0x0;
            if ((uVar12 == 0) || ((int)plVar26[0x39] == 0)) goto LAB_00104a0c;
            iVar21 = (int)param_3[2];
            iVar23 = *(int *)((long)plVar26 + 0xc4);
            lVar28 = sched_clock();
            uVar12 = lVar28 - uVar12;
            uVar16 = uVar12 / 1000;
            if (iVar21 == 0) {
              ipc_log_string(lVar27,"%s:took %llu nsec(%llu usec)\n","spi_geni_transfer_one",uVar12,
                             uVar16);
            }
            else if (iVar23 == 0) {
              ipc_log_string(lVar27,"%s:took %llu nsec(%llu usec) for %u bytes\n",
                             "spi_geni_transfer_one",uVar12,uVar16,iVar21);
            }
            else {
              ipc_log_string(lVar27,"%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                             "spi_geni_transfer_one",uVar12,uVar16,iVar21,iVar23);
            }
          }
          puVar29 = (uint *)0x0;
          goto LAB_00104a0c;
        }
LAB_00104418:
        mutex_unlock(plVar1);
      }
      else {
        *(undefined4 *)(plVar26 + 0x1c) = 0;
        uVar6 = *(undefined2 *)(param_2 + 0x3a8);
        uVar8 = readl_relaxed(plVar26[0x13] + 0x25c);
        bVar5 = *(byte *)((long)param_3 + 0x4a);
        if (*(uint *)(plVar26 + 0x19) != (uint)bVar5) {
          spi_setup_word_len(plVar26,uVar6);
          bVar5 = *(byte *)((long)param_3 + 0x4a);
          *(uint *)(plVar26 + 0x19) = (uint)bVar5;
        }
        uVar17 = (uint)bVar5;
        if ((int)param_3[0xb] == *(int *)((long)plVar26 + 0xc4)) {
LAB_00103888:
          *(undefined8 *)((long)plVar26 + 0xcc) = 0;
          lVar27 = param_3[1];
          uVar9 = 3;
          if (lVar27 == 0) {
            uVar9 = 1;
          }
          uVar24 = (uint)(lVar27 != 0) << 1;
          if (*param_3 != 0) {
            uVar24 = uVar9;
          }
          uVar9 = uVar8 & 0xfffffffd;
          if (*(char *)(param_1 + 0x3bf) != '\0') {
            uVar9 = uVar8;
          }
          if ((uVar17 & 3) == 0) {
            uVar8 = 0;
            if (uVar17 != 0) {
              uVar8 = (uint)((int)param_3[2] << 3) / uVar17;
            }
          }
          else {
            uVar8 = uVar17 + 7;
            if (-1 < (int)uVar17) {
              uVar8 = uVar17;
            }
            uVar17 = ((int)uVar8 >> 3) + 1;
            uVar8 = 0;
            if (uVar17 != 0) {
              uVar8 = *(uint *)(param_3 + 2) / uVar17;
            }
          }
          uVar8 = uVar8 & 0xffffff;
          if ((*(long *)(param_1 + 0x5b8) == 0) && ((*(ushort *)(param_3 + 9) >> 2 & 1) == 0)) {
            uVar17 = (uint)(param_3[0xf] != *(long *)(param_1 + 0x500)) << 2;
          }
          else {
            uVar17 = 0;
          }
          plVar26[0x1b] = (long)param_3;
          if ((uVar24 & 1) != 0) {
            *(int *)((long)plVar26 + 0xcc) = (int)param_3[2];
            writel_relaxed(uVar8,plVar26[0x13] + 0x26c);
          }
          if (lVar27 != 0) {
            writel_relaxed(uVar8,plVar26[0x13] + 0x270);
            *(int *)(plVar26 + 0x1a) = (int)param_3[2];
          }
          *(undefined4 *)((long)plVar26 + 0x1a4) = 2;
          if (*(char *)(param_1 + 0x3bf) == '\0') {
            if (*(char *)((long)plVar26 + 0x1d9) == '\0') {
              uVar22 = 0;
              if ((int)plVar26[0x19] != 0) {
                uVar22 = ((int)plVar26[0x17] * *(int *)((long)plVar26 + 0xb4)) / (int)plVar26[0x19];
              }
              if (uVar22 < uVar8) goto LAB_001039b4;
            }
            *(undefined4 *)((long)plVar26 + 0x1a4) = 1;
          }
LAB_001039b4:
          geni_se_select_mode(plVar26);
          if (*(char *)(param_1 + 0x3bf) == '\0') {
            writel_relaxed(uVar9,plVar26[0x13] + 0x25c);
          }
          writel(uVar17 | uVar24 << 0x1b,*plVar26 + 0x600);
          ipc_log_string(plVar26[0x37],
                         "%s: trans_len %d xferlen%d tx_cfg 0x%x cmd 0x%x cs%d mode%d freq %d\n",
                         "setup_fifo_xfer",uVar8,(int)param_3[2],uVar9,uVar24,
                         *(ushort *)(param_3 + 9) >> 2 & 1,*(undefined4 *)((long)plVar26 + 0x1a4),
                         (int)param_3[0xb]);
          if (plVar26[0x15] != 0) {
            spi_trace_log(plVar26[0x15],
                          "%s: trans_len %d xferlen%d tx_cfg 0x%x cmd 0x%x cs%d mode%d freq %d\n",
                          "setup_fifo_xfer",uVar8,(int)param_3[2],uVar9,uVar24,
                          *(ushort *)(param_3 + 9) >> 2 & 1,*(undefined4 *)((long)plVar26 + 0x1a4),
                          (int)param_3[0xb]);
          }
          if ((lVar27 == 0) || (*(int *)((long)plVar26 + 0x1a4) != 2)) {
LAB_00103aa0:
            if ((uVar24 & 1) != 0) {
              if (*(int *)((long)plVar26 + 0x1a4) == 2) {
                plVar14 = param_3 + 3;
                uVar16 = geni_se_tx_dma_prep(plVar26,*param_3,(int)param_3[2],plVar14);
                puVar29 = (uint *)(uVar16 & 0xffffffff);
                if (((int)uVar16 != 0) || (*param_3 == 0)) {
                  ipc_log_string(plVar26[0x37],"Failed to setup tx dma %d\n",puVar29);
                  if (plVar26[0x15] == 0) {
                    _printk(&DAT_00108873,puVar29);
                  }
                  else {
                    _dev_err(plVar26[0x15],"Failed to setup tx dma %d\n",puVar29);
                  }
                  lVar27 = plVar26[0x15];
                  if (lVar27 != 0) {
                    pcVar15 = "Failed to setup tx dma %d\n";
                    goto LAB_00104928;
                  }
                  goto LAB_00104930;
                }
              }
              else if (*(int *)((long)plVar26 + 0x1a4) == 1) {
                writel_relaxed(*(undefined4 *)((long)plVar26 + 0xbc),plVar26[0x13] + 0x80c);
              }
            }
            DataSynchronizationBarrier(3,3,0);
          }
          else {
            plVar14 = param_3 + 4;
            uVar16 = geni_se_rx_dma_prep(plVar26,param_3[1],(int)param_3[2],plVar14);
            puVar29 = (uint *)(uVar16 & 0xffffffff);
            if (((int)uVar16 == 0) && (param_3[1] != 0)) goto LAB_00103aa0;
            ipc_log_string(plVar26[0x37],"Failed to setup Rx dma %d\n",puVar29);
            if (plVar26[0x15] == 0) {
              _printk(&DAT_001087d9,puVar29);
            }
            else {
              _dev_err(plVar26[0x15],"Failed to setup Rx dma %d\n",puVar29);
            }
            lVar27 = plVar26[0x15];
            if (lVar27 != 0) {
              pcVar15 = "Failed to setup Rx dma %d\n";
LAB_00104928:
              spi_trace_log(lVar27,pcVar15,puVar29);
            }
LAB_00104930:
            *plVar14 = 0;
            if ((int)puVar29 != 0) goto LAB_00104654;
          }
          if (*(char *)(param_1 + 0x3bf) != '\0') {
            *(undefined1 *)((long)plVar26 + 0x1db) = 1;
          }
          mutex_unlock(plVar1);
          lVar27 = wait_for_completion_timeout(plVar26 + 0x1c,uVar13);
          mutex_lock(plVar1);
          if ((char)plVar26[0x43] != '\0') {
            puVar29 = (uint *)0x0;
            goto LAB_00104418;
          }
          if (*(char *)(param_1 + 0x3bf) != '\0') {
            *(undefined1 *)((long)plVar26 + 0x1db) = 0;
          }
          if (lVar27 != 0) {
            if (*(int *)((long)plVar26 + 0x1a4) == 2) {
              if (*param_3 != 0) {
                geni_se_tx_dma_unprep(plVar26,param_3[3],(int)param_3[2]);
              }
              if (param_3[1] != 0) {
                geni_se_rx_dma_unprep(plVar26,param_3[4],(int)param_3[2]);
              }
            }
            goto LAB_001044bc;
          }
          ipc_log_string(plVar26[0x37],"Xfer[len %d tx %pK rx %pK n %d] timed out.\n",
                         (int)param_3[2],*param_3,param_3[1],*(undefined1 *)((long)param_3 + 0x4a));
          if (plVar26[0x15] == 0) {
            _printk(&DAT_00109901,(int)param_3[2],*param_3,param_3[1],
                    *(undefined1 *)((long)param_3 + 0x4a));
          }
          else {
            _dev_err(plVar26[0x15],"Xfer[len %d tx %pK rx %pK n %d] timed out.\n");
          }
          if (plVar26[0x15] != 0) {
            spi_trace_log(plVar26[0x15],"Xfer[len %d tx %pK rx %pK n %d] timed out.\n",
                          (int)param_3[2],*param_3,param_3[1],*(undefined1 *)((long)param_3 + 0x4a))
            ;
          }
          puVar29 = (uint *)0xffffff92;
        }
        else {
          local_70 = 0;
          uVar17 = get_spi_clk_cfg((int)param_3[0xb],plVar26,(long)&local_70 + 4,&local_70);
          if (uVar17 == 0) {
            uVar17 = *(uint *)(plVar26 + 0x19);
            *(int *)((long)plVar26 + 0xc4) = (int)param_3[0xb];
            goto LAB_00103888;
          }
          puVar29 = (uint *)(ulong)uVar17;
          _dev_err(plVar26[0x15],"%s: Err setting clks:%d\n","setup_fifo_xfer",puVar29);
LAB_00104654:
          ipc_log_string(plVar26[0x37],"setup_fifo_xfer failed: %d\n",puVar29);
          if (plVar26[0x15] == 0) {
            _printk(&DAT_001099e4,puVar29);
          }
          else {
            _dev_err(plVar26[0x15],"setup_fifo_xfer failed: %d\n",puVar29);
          }
          if (plVar26[0x15] != 0) {
            spi_trace_log(plVar26[0x15],"setup_fifo_xfer failed: %d\n",puVar29);
          }
        }
        plVar26[0x1b] = 0;
        mutex_unlock(plVar1);
        handle_fifo_timeout(param_1,param_3);
      }
      goto LAB_00104a0c;
    }
    lVar27 = plVar26[0x15];
    pcVar15 = "Zero length transfer\n";
  }
  _dev_err(lVar27,pcVar15);
  puVar29 = (uint *)0xffffffea;
LAB_00104a0c:
  lVar27 = sp_el0;
  if (*(long *)(lVar27 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar29 & 0xffffffff;
}



//------------------------------------------------------------
// spi_geni_unprepare_transfer_hardware @ 00104a7c size=672
// signature: undefined spi_geni_unprepare_transfer_hardware(void)
// callers: []
//------------------------------------------------------------

undefined8 spi_geni_unprepare_transfer_hardware(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  lVar10 = *(long *)(param_1 + 0x98);
  lVar8 = *(long *)(lVar10 + 0x1c0);
  if (lVar8 == 0) {
    uVar6 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar10 + 0x1c8) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = sched_clock();
    ipc_log_string(lVar8,"%s:start at %llu nsec(%llu usec)\n","spi_geni_unprepare_transfer_hardware"
                   ,uVar6,uVar6 / 1000);
  }
  lVar8 = lVar10 + 0x1e8;
  mutex_lock(lVar8);
  if ((*(char *)(lVar10 + 0x218) == '\0') && (*(char *)(lVar10 + 0x219) != '\0')) {
    if ((*(char *)(lVar10 + 0x1cd) == '\0') && (*(char *)(lVar10 + 0x1cf) == '\0')) {
      if (((*(char *)(lVar10 + 0x1cc) != '\0') && (*(char *)(lVar10 + 0x1d0) == '\0')) &&
         (iVar5 = pinctrl_select_state
                            (*(undefined8 *)(lVar10 + 0x70),*(undefined8 *)(lVar10 + 0x80)),
         iVar5 != 0)) {
        ipc_log_string(*(undefined8 *)(lVar10 + 0x1b8),"%s: Error %d pinctrl_select_state\n",
                       "spi_geni_unprepare_transfer_hardware",iVar5);
        if (*(long *)(lVar10 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar10 + 0xa8),"%s: Error %d pinctrl_select_state\n",
                        "spi_geni_unprepare_transfer_hardware",iVar5);
        }
      }
      lVar9 = *(long *)(lVar10 + 0xa8);
      if (*(char *)(lVar10 + 0x1d1) == '\0') {
        if ((*(int *)(lVar9 + 0x20c) != 2) && ((*(ushort *)(lVar9 + 0x200) & 7) == 0)) {
          uVar7 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar9 + 0x220) = uVar7;
          __pm_runtime_suspend(*(undefined8 *)(lVar10 + 0xa8),0xd);
        }
      }
      else {
        __pm_runtime_idle(lVar9,4);
        iVar5 = *(int *)(*(long *)(lVar10 + 0xa8) + 0x1f8);
        if (iVar5 < 0) {
          ipc_log_string(*(undefined8 *)(lVar10 + 0x1b8),"suspend usage count mismatch:%d",iVar5);
          if (*(long *)(lVar10 + 0xa8) != 0) {
            spi_trace_log(*(long *)(lVar10 + 0xa8),"suspend usage count mismatch:%d",iVar5);
          }
        }
      }
      *(undefined1 *)(lVar10 + 0x1de) = 0;
      mutex_unlock(lVar8);
      lVar8 = *(long *)(lVar10 + 0x1c0);
      if (lVar8 != 0) {
        if (uVar6 == 0) {
          return 0;
        }
        if (*(int *)(lVar10 + 0x1c8) == 0) {
          return 0;
        }
        lVar10 = sched_clock(0);
        ipc_log_string(lVar8,"%s:took %llu nsec(%llu usec)\n","spi_geni_unprepare_transfer_hardware"
                       ,lVar10 - uVar6,(lVar10 - uVar6) / 1000);
      }
    }
    else {
      *(undefined1 *)(lVar10 + 0x1de) = 0;
      mutex_unlock(lVar8);
    }
    uVar7 = 0;
  }
  else {
    piVar1 = (int *)(*(long *)(lVar10 + 0xa8) + 0x1f8);
    iVar5 = *(int *)(*(long *)(lVar10 + 0xa8) + 0x1f8);
    do {
      if (iVar5 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar5) goto LAB_00104b34;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar5 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00104b34:
      bVar4 = iVar5 != iVar2;
      iVar5 = iVar2;
    } while (bVar4);
    mutex_unlock(lVar8);
    ipc_log_string(*(undefined8 *)(lVar10 + 0x1b8),"%s: bail out during SSR\n",
                   "spi_geni_unprepare_transfer_hardware");
    if (*(long *)(lVar10 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar10 + 0xa8),"%s: bail out during SSR\n",
                    "spi_geni_unprepare_transfer_hardware");
    }
    uVar7 = 0xffffffea;
  }
  return uVar7;
}



//------------------------------------------------------------
// ssr_spi_force_suspend @ 00104d34 size=316
// signature: undefined ssr_spi_force_suspend(void)
// callers: []
//------------------------------------------------------------

void ssr_spi_force_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  mutex_lock(lVar2 + 0x1e8);
  *(undefined1 *)(lVar2 + 0x219) = 0;
  disable_irq(*(undefined4 *)(lVar2 + 0xa0));
  *(undefined1 *)(lVar2 + 0x218) = 1;
  complete(lVar2 + 0xe0);
  if (*(int *)(*(long *)(lVar2 + 0xa8) + 0x20c) != 2) {
    iVar1 = spi_geni_runtime_suspend();
    if (iVar1 == 0) {
      __pm_runtime_disable(*(undefined8 *)(lVar2 + 0xa8),1);
      __pm_runtime_set_status(*(undefined8 *)(lVar2 + 0xa8),2);
      pm_runtime_enable(*(undefined8 *)(lVar2 + 0xa8));
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"%s: pm runtime suspend failed %d\n",
                     "ssr_spi_force_suspend",iVar1);
      if (*(long *)(lVar2 + 0xa8) == 0) {
        _printk(&DAT_00108a1b,"ssr_spi_force_suspend",iVar1);
      }
      else {
        _dev_err(*(long *)(lVar2 + 0xa8),"%s: pm runtime suspend failed %d\n",
                 "ssr_spi_force_suspend",iVar1);
      }
      if (*(long *)(lVar2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar2 + 0xa8),"%s: pm runtime suspend failed %d\n",
                      "ssr_spi_force_suspend",iVar1);
      }
    }
  }
  mutex_unlock(lVar2 + 0x1e8);
  ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"SSR force suspend done\n");
  if (*(long *)(lVar2 + 0xa8) != 0) {
    spi_trace_log(*(long *)(lVar2 + 0xa8),"SSR force suspend done\n");
  }
  return;
}



//------------------------------------------------------------
// ssr_spi_force_resume @ 00104e74 size=456
// signature: undefined ssr_spi_force_resume(void)
// callers: []
//------------------------------------------------------------

void ssr_spi_force_resume(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  lVar1 = lVar5 + 0x1e8;
  mutex_lock(lVar1);
  *(undefined1 *)(lVar5 + 0x218) = 0;
  enable_irq(*(undefined4 *)(lVar5 + 0xa0));
  if (*(int *)(*(long *)(lVar5 + 0xa8) + 0x20c) == 2) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: the device is in suspended state\n",
                   "ssr_spi_force_resume");
    lVar4 = 0;
    if (*(long *)(lVar5 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: the device is in suspended state\n",
                    "ssr_spi_force_resume");
      lVar4 = *(long *)(lVar5 + 0xa8);
    }
    if ((*(ushort *)(lVar4 + 0x200) & 7) != 0) {
      mutex_unlock(lVar1);
      ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: System PM runtime is not enabled\n",
                     "ssr_spi_force_resume");
      if (*(long *)(lVar5 + 0xa8) == 0) {
        _printk(&DAT_00108704,"ssr_spi_force_resume");
      }
      else {
        _dev_err(*(long *)(lVar5 + 0xa8),"%s: System PM runtime is not enabled\n",
                 "ssr_spi_force_resume");
      }
      if (*(long *)(lVar5 + 0xa8) == 0) {
        return;
      }
      spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: System PM runtime is not enabled\n",
                    "ssr_spi_force_resume");
      return;
    }
    iVar3 = __pm_runtime_resume(lVar4,4);
    if (iVar3 < 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s:pm_runtime_get_sync failed %d\n",
                     "ssr_spi_force_resume",iVar3);
      if (*(long *)(lVar5 + 0xa8) == 0) {
        _printk(&DAT_00108eaa,"ssr_spi_force_resume",iVar3);
      }
      else {
        _dev_err(*(long *)(lVar5 + 0xa8),"%s:pm_runtime_get_sync failed %d\n","ssr_spi_force_resume"
                 ,iVar3);
      }
      if (*(long *)(lVar5 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar5 + 0xa8),"%s:pm_runtime_get_sync failed %d\n",
                      "ssr_spi_force_resume",iVar3);
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10503c);
      (*pcVar2)();
    }
  }
  mutex_unlock(lVar1);
  ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"SSR force resume done\n");
  if (*(long *)(lVar5 + 0xa8) != 0) {
    spi_trace_log(*(long *)(lVar5 + 0xa8),"SSR force resume done\n");
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 001050ac size=132
// signature: undefined writel_relaxed(void)
// callers: [spi_master_setup, spi_setup_word_len, spi_geni_runtime_resume, geni_spi_irq, spi_geni_mas_setup, spi_geni_prepare_message, spi_slv_setup, handle_fifo_timeout, get_spi_clk_cfg, spi_geni_transfer_one]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1050c4,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x105100,uVar1);
  return;
}



//------------------------------------------------------------
// pm_runtime_put_noidle @ 00105130 size=76
// signature: undefined pm_runtime_put_noidle(void)
// callers: []
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
      if (iVar2 != iVar5) goto LAB_00105158;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00105158:
    bVar4 = iVar5 == iVar2;
    iVar5 = iVar2;
    if (bVar4) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// spi_geni_mas_setup @ 00105190 size=1572
// signature: undefined spi_geni_mas_setup(void)
// callers: [spi_geni_runtime_suspend, spi_geni_prepare_transfer_hardware, spi_geni_runtime_resume]
//------------------------------------------------------------

int spi_geni_mas_setup(long param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  char *pcVar15;
  code *pcVar16;
  long *plVar17;
  
  plVar17 = *(long **)(param_1 + 0x98);
  uVar3 = readl_relaxed(*plVar17 + 0x68);
  uVar3 = uVar3 >> 8 & 0xff;
  if (*(char *)(param_1 + 0x3bf) != '\0') {
    if (*(char *)((long)plVar17 + 0x1da) == '\0') {
      if (uVar3 != 5) goto LAB_00105780;
      if ((char)plVar17[0x18] == '\0') {
        spi_slv_setup(plVar17);
        goto LAB_001057a0;
      }
      goto LAB_001051fc;
    }
    goto LAB_0010534c;
  }
  if ((char)plVar17[0x18] == '\0') {
    if (uVar3 != 1) {
LAB_00105780:
      _dev_err(plVar17[0x15],"Invalid proto %d\n");
      return -6;
    }
LAB_001057a0:
    if (*(char *)((long)plVar17 + 0x1dd) != '\0') {
      spi_master_setup(plVar17);
    }
  }
LAB_001051fc:
  *(undefined4 *)(plVar17 + 0x21) = 1;
  bVar2 = readl_relaxed(plVar17[0x13] + 100);
  *(byte *)((long)plVar17 + 0x1cc) = bVar2 & 1;
  if (((bVar2 & 1) == 0) || (*(char *)((long)plVar17 + 0x1e4) != '\0')) {
    uVar4 = geni_se_get_qup_hw_version(plVar17);
    uVar3 = 0xff0000;
    if (((uVar4 & 0xffe0000) < 0x90001 || uVar4 >> 0x1c != 3) && (uVar4 & 0xc0000000) == 0) {
      uVar3 = 0x3f0000;
    }
    uVar4 = readl_relaxed(*plVar17 + 0xe24);
    *(uint *)((long)plVar17 + 0xb4) = (uVar3 & uVar4) >> 0x10;
    uVar4 = geni_se_get_qup_hw_version(plVar17);
    uVar3 = 0xff0000;
    if (((uVar4 & 0xffe0000) < 0x90001 || uVar4 >> 0x1c != 3) && (uVar4 & 0xc0000000) == 0) {
      uVar3 = 0x3f0000;
    }
    uVar4 = readl_relaxed(*plVar17 + 0xe28);
    *(uint *)(plVar17 + 0x16) = (uVar3 & uVar4) >> 0x10;
    uVar3 = readl_relaxed(*plVar17 + 0xe24);
    *(uint *)(plVar17 + 0x17) = uVar3 >> 0x18 & 0x3f;
    geni_se_init(plVar17,0,*(int *)((long)plVar17 + 0xb4) + -2);
    iVar11 = 0;
    *(undefined4 *)((long)plVar17 + 0xbc) = 1;
  }
  else {
    uVar12 = dma_request_chan(plVar17[0x15],&DAT_001098fe);
    uVar13 = 0;
    if (uVar12 < 0xfffffffffffff001) {
      uVar13 = uVar12;
    }
    plVar17[0x24] = uVar13;
    if (uVar13 == 0) {
      _dev_info(plVar17[0x15],"Failed to get tx DMA ch %ld\n",0);
    }
    else {
      uVar12 = dma_request_chan(plVar17[0x15],&DAT_0010899c);
      uVar13 = 0;
      if (uVar12 < 0xfffffffffffff001) {
        uVar13 = uVar12;
      }
      plVar17[0x25] = uVar13;
      if (uVar13 != 0) {
        uVar13 = devm_kmalloc(plVar17[0x15],0xb40,0xdc0);
        plVar17[0x22] = uVar13;
        if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
          lVar14 = plVar17[0x15];
          pcVar15 = "Failed to get GSI mem\n";
LAB_001056a0:
          _dev_err(lVar14,pcVar15);
          dma_release_channel(plVar17[0x24]);
          dma_release_channel(plVar17[0x25]);
          iVar11 = 0;
        }
        else {
          if ((*(char *)((long)plVar17 + 0x1ce) != '\0') ||
             (*(char *)((long)plVar17 + 0x1cf) != '\0')) {
            uVar13 = devm_kmalloc(plVar17[0x15],0x168,0xdc0);
            plVar17[0x23] = uVar13;
            if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
              lVar14 = plVar17[0x15];
              pcVar15 = "Failed to get GSI lock mem\n";
              goto LAB_001056a0;
            }
          }
          plVar17[0x27] = (long)spi_gsi_ch_cb;
          plVar17[0x28] = param_1;
          *(undefined4 *)(plVar17 + 0x26) = 1;
          *(long **)(plVar17[0x24] + 0x68) = plVar17 + 0x26;
          plVar17[0x2a] = (long)spi_gsi_ch_cb;
          plVar17[0x2b] = param_1;
          *(undefined4 *)(plVar17 + 0x29) = 1;
          *(long **)(plVar17[0x25] + 0x68) = plVar17 + 0x29;
          pcVar16 = *(code **)(*(long *)plVar17[0x24] + 0x130);
          if (pcVar16 == (code *)0x0) {
            iVar11 = -0x26;
LAB_0010571c:
            lVar14 = plVar17[0x15];
            pcVar15 = "Failed to Config Tx, ret:%d\n";
          }
          else {
            if (*(int *)(pcVar16 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
              pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1056f8);
              (*pcVar16)();
            }
            iVar11 = (*pcVar16)((long *)plVar17[0x24],0);
            if (iVar11 != 0) goto LAB_0010571c;
            pcVar16 = *(code **)(*(long *)plVar17[0x25] + 0x130);
            if (pcVar16 == (code *)0x0) {
              iVar11 = -0x26;
            }
            else {
              if (*(int *)(pcVar16 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
                pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105764);
                (*pcVar16)();
              }
              iVar11 = (*pcVar16)((long *)plVar17[0x25],0);
              if (iVar11 == 0) goto LAB_00105350;
            }
            lVar14 = plVar17[0x15];
            pcVar15 = "Failed to Config Rx, ret:%d\n";
          }
          _dev_err(lVar14,pcVar15,iVar11);
          dma_release_channel(plVar17[0x24]);
          dma_release_channel(plVar17[0x25]);
        }
        plVar17[0x24] = 0;
        plVar17[0x25] = 0;
        goto LAB_00105350;
      }
      _dev_info(plVar17[0x15],"Failed to get rx DMA ch %ld\n",0);
      dma_release_channel(plVar17[0x24]);
    }
LAB_0010534c:
    iVar11 = 0;
  }
LAB_00105350:
  if (plVar17[0x37] == 0) {
    lVar14 = ((long *)plVar17[0x15])[0xe];
    if (lVar14 == 0) {
      lVar14 = *(long *)plVar17[0x15];
    }
    lVar14 = ipc_log_context_create(4,lVar14,0);
    plVar17[0x37] = lVar14;
  }
  _dev_info(plVar17[0x15],"tx_fifo %d rx_fifo %d tx_width %d\n",
            *(undefined4 *)((long)plVar17 + 0xb4),(int)plVar17[0x16],(int)plVar17[0x17]);
  if (*(char *)((long)plVar17 + 0x1cd) == '\0') {
    *(undefined1 *)(plVar17 + 0x18) = 1;
    cVar1 = *(char *)((long)plVar17 + 0x1cf);
  }
  else {
    cVar1 = *(char *)((long)plVar17 + 0x1cf);
  }
  if (cVar1 != '\0') {
    return iVar11;
  }
  if (*(char *)((long)plVar17 + 0x1e4) == '\0') {
    uVar3 = geni_se_get_qup_hw_version(plVar17);
    if (uVar3 != 0) {
      uVar4 = uVar3 >> 0x1c;
      uVar3 = uVar3 >> 0x10 & 0xfff;
      if ((uVar4 == 1) && (uVar3 == 0)) {
        uVar8 = 2;
        *(undefined4 *)(plVar17 + 0x21) = 2;
      }
      else {
        uVar8 = (undefined4)plVar17[0x21];
      }
      ipc_log_string(plVar17[0x37],"%s:Major:%d Minor:%d os%d\n","spi_geni_mas_setup",uVar4,uVar3,
                     uVar8);
      if (plVar17[0x15] != 0) {
        spi_trace_log(plVar17[0x15],"%s:Major:%d Minor:%d os%d\n","spi_geni_mas_setup",uVar4,uVar3,
                      (int)plVar17[0x21]);
      }
      goto LAB_00105440;
    }
    _dev_err(plVar17[0x15],"%s:Err getting HW version %d\n","spi_geni_mas_setup",0);
  }
  uVar4 = 0;
  uVar3 = 0;
LAB_00105440:
  if (*(char *)((long)plVar17 + 0x1d3) != '\0') {
    iVar5 = readl_relaxed(plVar17[0x13] + 0x230);
    iVar6 = readl_relaxed(plVar17[0x13] + 0x224);
    uVar7 = readl_relaxed(plVar17[0x13] + 0x2b0);
    uVar8 = readl_relaxed(plVar17[0x13] + 0x2b4);
    if (uVar4 != 1 || uVar3 != 0) {
      if ((uVar4 < 2) || ((uVar4 == 2 && (uVar3 < 5)))) {
        uVar7 = uVar7 & 0xfffff8fd;
      }
      else {
        uVar7 = uVar7 & 0xfffff8fd | *(int *)((long)plVar17 + 0x1d4) << 8;
      }
    }
    else {
      uVar7 = uVar7 & 0xffff8fed | 0x1000;
    }
    writel_relaxed(uVar7,plVar17[0x13] + 0x2b0);
    uVar9 = 0;
    if (iVar6 != 0 || iVar5 != 1) {
      uVar9 = uVar8;
    }
    if (iVar5 == 0 && iVar6 == 0) {
      uVar9 = 1;
    }
    writel_relaxed(uVar9,plVar17[0x13] + 0x2b4);
    if (uVar4 != 1 || uVar3 != 0) {
      writel_relaxed(1,plVar17[0x13] + 0x84);
    }
    uVar8 = readl_relaxed(plVar17[0x13] + 0x2b0);
    uVar9 = readl_relaxed(plVar17[0x13] + 0x2b4);
    uVar10 = readl_relaxed(plVar17[0x13] + 0x84);
    ipc_log_string(plVar17[0x37],"%s cfg108: 0x%x cfg109: 0x%x cfg_seq_start: 0x%x\n",
                   "spi_geni_set_sampling_rate",uVar8,uVar9,uVar10);
    if (plVar17[0x15] != 0) {
      spi_trace_log(plVar17[0x15],"%s cfg108: 0x%x cfg109: 0x%x cfg_seq_start: 0x%x\n",
                    "spi_geni_set_sampling_rate",uVar8,uVar9,uVar10);
    }
  }
  if (*(char *)((long)plVar17 + 0x1d1) != '\0') {
    ipc_log_string(plVar17[0x37],"Auto Suspend is disabled\n");
    if (plVar17[0x15] != 0) {
      spi_trace_log(plVar17[0x15],"Auto Suspend is disabled\n");
    }
  }
  *(undefined1 *)((long)plVar17 + 0x1e4) = 0;
  return iVar11;
}



//------------------------------------------------------------
// spi_slv_setup @ 001057b4 size=136
// signature: undefined spi_slv_setup(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

void spi_slv_setup(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  writel_relaxed(1,*(long *)(param_1 + 0x98) + 700);
  lVar2 = *(long *)(param_1 + 0x98) + 0x24;
  if (*(char *)(param_1 + 0x1dc) == '\0') {
    uVar1 = 1;
  }
  else {
    writel_relaxed(4,lVar2);
    uVar1 = 0x8c04;
    lVar2 = *(long *)(param_1 + 0x98) + 0x240;
  }
  writel_relaxed(uVar1,lVar2);
  writel_relaxed(1,*(long *)(param_1 + 0x98) + 0x84);
  DataSynchronizationBarrier(3,2,0);
  _dev_info(*(undefined8 *)(param_1 + 0xa8),"spi slave setup done\n");
  return;
}



//------------------------------------------------------------
// spi_master_setup @ 0010583c size=72
// signature: undefined spi_master_setup(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

void spi_master_setup(long param_1)

{
  writel_relaxed(0x19e1,*(long *)(param_1 + 0x98) + 0x240);
  writel_relaxed(1,*(long *)(param_1 + 0x98) + 0x84);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// spi_gsi_ch_cb @ 00105888 size=520
// signature: undefined spi_gsi_ch_cb(void)
// callers: []
//------------------------------------------------------------

void spi_gsi_ch_cb(undefined8 param_1,int *param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    _printk(&DAT_001099b0,"spi_gsi_ch_cb");
  }
  else {
    iVar1 = *param_2;
    lVar2 = *(long *)(param_3 + 0x98);
    if ((iVar1 == 0) || (iVar1 == 8)) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"%s:cb_ev%d status%llu ts%llu count%llu\n",
                     "spi_gsi_ch_cb",iVar1,*(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4)
                     ,*(undefined8 *)(param_2 + 6));
      if (*(long *)(lVar2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar2 + 0xa8),"%s:cb_ev%d status%llu ts%llu count%llu\n",
                      "spi_gsi_ch_cb",*param_2,*(undefined8 *)(param_2 + 2),
                      *(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6));
      }
    }
    else if (iVar1 - 1U < 6) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"%s: cb_ev %d status %llu ts %llu count %llu\n",
                     "spi_gsi_ch_cb",iVar1,*(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4)
                     ,*(undefined8 *)(param_2 + 6));
      if (*(long *)(lVar2 + 0xa8) == 0) {
        _printk(&DAT_001097e2,"spi_gsi_ch_cb",*param_2,*(undefined8 *)(param_2 + 2),
                *(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6));
      }
      else {
        _dev_err(*(long *)(lVar2 + 0xa8),"%s: cb_ev %d status %llu ts %llu count %llu\n",
                 "spi_gsi_ch_cb",*param_2);
      }
      if (*(long *)(lVar2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar2 + 0xa8),"%s: cb_ev %d status %llu ts %llu count %llu\n",
                      "spi_gsi_ch_cb",*param_2,*(undefined8 *)(param_2 + 2),
                      *(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6));
      }
      ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"err.routine %u, err.type %u, err.code %u\n",
                     param_2[8],param_2[9],param_2[10]);
      if (*(long *)(lVar2 + 0xa8) == 0) {
        _printk(&DAT_00109411,param_2[8],param_2[9],param_2[10]);
      }
      else {
        _dev_err(*(long *)(lVar2 + 0xa8),"err.routine %u, err.type %u, err.code %u\n",param_2[8],
                 param_2[9],param_2[10]);
      }
      if (*(long *)(lVar2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar2 + 0xa8),"err.routine %u, err.type %u, err.code %u\n",
                      param_2[8],param_2[9],param_2[10]);
      }
      *(undefined1 *)(lVar2 + 0x1a0) = 1;
      complete_all(lVar2 + 0x160);
      complete_all(lVar2 + 0x180);
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"%s: Unsupported event: %d\n","spi_gsi_ch_cb");
      if (*(long *)(lVar2 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar2 + 0xa8),"%s: Unsupported event: %d\n","spi_gsi_ch_cb",*param_2
                     );
      }
    }
  }
  return;
}



//------------------------------------------------------------
// spi_geni_lock_bus @ 00105a90 size=724
// signature: undefined spi_geni_lock_bus(void)
// callers: [spi_geni_runtime_resume, spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

undefined8 spi_geni_lock_bus(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  
  lVar7 = *(long *)(param_1 + 0x98);
  lVar8 = *(long *)(lVar7 + 0x118);
  *(undefined4 *)(lVar7 + 0x160) = 0;
  ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s %d\n","spi_geni_lock_bus",0);
  if (*(long *)(lVar7 + 0xa8) != 0) {
    spi_trace_log(*(long *)(lVar7 + 0xa8),"%s %d\n","spi_geni_lock_bus",0);
  }
  puVar9 = *(undefined8 **)(lVar7 + 0x118);
  *puVar9 = 0;
  puVar9[1] = 0x30010000000000;
  sg_init_table(lVar8 + 0x60,1);
  *(ulong *)(lVar8 + 0x60) =
       (*(ulong *)(lVar8 + 0x60) & 3 | ((((long)puVar9 << 8) >> 8) + 0x8000000000U >> 0xc) << 6) -
       0x200000000;
  *(uint *)(lVar8 + 0x68) = (uint)puVar9 & 0xfff;
  *(undefined4 *)(lVar8 + 0x6c) = 0x10;
  *(long *)(*(long *)(lVar7 + 0x118) + 0x158) = param_1;
  lVar8 = *(long *)(lVar7 + 0x118);
  plVar1 = *(long **)(lVar7 + 0x120);
  uVar4 = 0;
  if (plVar1 != (long *)0x0) {
    if ((*plVar1 == 0) || (pcVar6 = *(code **)(*plVar1 + 0x108), pcVar6 == (code *)0x0)) {
      uVar4 = 0;
    }
    else {
      if (*(int *)(pcVar6 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x105b94);
        (*pcVar6)();
      }
      uVar4 = (*pcVar6)(plVar1,lVar8 + 0x60,1,1,3,0);
      lVar8 = *(long *)(lVar7 + 0x118);
    }
  }
  *(undefined8 *)(lVar8 + 0x148) = uVar4;
  uVar5 = *(ulong *)(*(long *)(lVar7 + 0x118) + 0x148);
  if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
    _dev_err(*(undefined8 *)(lVar7 + 0xa8),"Err setting up tx desc\n");
    uVar4 = 0xfffffffb;
  }
  else {
    *(code **)(uVar5 + 0x28) = spi_gsi_tx_callback;
    *(long *)(*(long *)(*(long *)(lVar7 + 0x118) + 0x148) + 0x38) = *(long *)(lVar7 + 0x118) + 0xe8;
    *(long *)(*(long *)(lVar7 + 0x118) + 0x108) = *(long *)(lVar7 + 0x118) + 0x158;
    pcVar6 = *(code **)(*(long *)(*(long *)(lVar7 + 0x118) + 0x148) + 0x18);
    if (*(int *)(pcVar6 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x105c08);
      (*pcVar6)();
    }
    uVar2 = (*pcVar6)();
    *(undefined4 *)(*(long *)(lVar7 + 0x118) + 0xe0) = uVar2;
    if (*(int *)(*(long *)(lVar7 + 0x118) + 0xe0) < 0) {
      _dev_err(*(undefined8 *)(lVar7 + 0xa8),"%s: dmaengine_submit failed (%d)\n",
               "spi_geni_lock_bus");
      uVar4 = 0xffffffea;
    }
    else {
      pcVar6 = *(code **)(**(long **)(lVar7 + 0x120) + 0x160);
      if (*(int *)(pcVar6 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x105c48);
        (*pcVar6)();
      }
      (*pcVar6)();
      iVar3 = wait_for_completion_timeout(lVar7 + 0x160,0x3f);
      if (0 < iVar3) {
        return 0;
      }
      ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s failed\n","spi_geni_lock_bus");
      if (*(long *)(lVar7 + 0xa8) == 0) {
        _printk(&DAT_001099d7,"spi_geni_lock_bus");
      }
      else {
        _dev_err(*(long *)(lVar7 + 0xa8),"%s failed\n","spi_geni_lock_bus");
      }
      if (*(long *)(lVar7 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar7 + 0xa8),"%s failed\n","spi_geni_lock_bus");
      }
      geni_spi_se_dump_dbg_regs(lVar7,*(undefined8 *)(lVar7 + 0x98),*(undefined8 *)(lVar7 + 0x1b8));
      uVar4 = 0xffffff92;
    }
  }
  pcVar6 = *(code **)(**(long **)(lVar7 + 0x120) + 0x148);
  if (pcVar6 != (code *)0x0) {
    if (*(int *)(pcVar6 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x105d5c);
      (*pcVar6)();
    }
    (*pcVar6)();
  }
  return uVar4;
}



//------------------------------------------------------------
// spi_gsi_tx_callback @ 00105d68 size=468
// signature: undefined spi_gsi_tx_callback(void)
// callers: []
//------------------------------------------------------------

void spi_gsi_tx_callback(int *param_1)

{
  long *plVar1;
  long lVar2;
  char *pcVar3;
  long *plVar4;
  long lVar5;
  
  if ((param_1 == (int *)0x0) || (plVar4 = *(long **)(param_1 + 8), plVar4 == (long *)0x0)) {
    _printk(&DAT_00108bcb,"spi_gsi_tx_callback");
    return;
  }
  plVar1 = (long *)plVar4[1];
  lVar5 = *(long *)(*plVar4 + 0x98);
  if (plVar1 == (long *)0x0) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"Lock/unlock IEOB received %s\n",
                   "spi_gsi_tx_callback");
    lVar2 = *(long *)(lVar5 + 0xa8);
    if (lVar2 == 0) goto LAB_00105e1c;
    pcVar3 = "Lock/unlock IEOB received %s\n";
  }
  else {
    if (*plVar1 == 0) {
      return;
    }
    if (param_1[2] == 0x10) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: Unexpected GSI CB error\n",
                     "spi_gsi_tx_callback");
      if (*(long *)(lVar5 + 0xa8) == 0) {
        _printk(&DAT_00108c48,"spi_gsi_tx_callback");
      }
      else {
        _dev_err(*(long *)(lVar5 + 0xa8),"%s: Unexpected GSI CB error\n","spi_gsi_tx_callback");
      }
      if (*(long *)(lVar5 + 0xa8) == 0) {
        return;
      }
      spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: Unexpected GSI CB error\n","spi_gsi_tx_callback");
      return;
    }
    if (*param_1 != (int)plVar1[2]) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),"%s: Length mismatch. Expected %d Callback %d\n"
                     ,"spi_gsi_tx_callback");
      if (*(long *)(lVar5 + 0xa8) == 0) {
        _printk(&DAT_0010899f,"spi_gsi_tx_callback",(int)plVar1[2],*param_1);
      }
      else {
        _dev_err(*(long *)(lVar5 + 0xa8),"%s: Length mismatch. Expected %d Callback %d\n",
                 "spi_gsi_tx_callback",(int)plVar1[2],*param_1);
      }
      if (*(long *)(lVar5 + 0xa8) == 0) {
        return;
      }
      spi_trace_log(*(long *)(lVar5 + 0xa8),"%s: Length mismatch. Expected %d Callback %d\n",
                    "spi_gsi_tx_callback",(int)plVar1[2],*param_1);
      return;
    }
    ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),&DAT_00109676,"spi_gsi_tx_callback");
    lVar2 = *(long *)(lVar5 + 0xa8);
    if (lVar2 == 0) goto LAB_00105e1c;
    pcVar3 = "%s\n";
  }
  spi_trace_log(lVar2,pcVar3,"spi_gsi_tx_callback");
LAB_00105e1c:
  complete(lVar5 + 0x160);
  return;
}



//------------------------------------------------------------
// get_spi_clk_cfg @ 00105f3c size=372
// signature: undefined get_spi_clk_cfg(void)
// callers: [spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

int get_spi_clk_cfg(int param_1,long param_2,uint *param_3,int *param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  iVar2 = geni_se_clk_freq_match(param_2,*(int *)(param_2 + 0x108) * param_1,param_3,&local_50,0);
  if (iVar2 == 0) {
    uVar3 = (ulong)(uint)(*(int *)(param_2 + 0x108) * param_1);
    iVar2 = 0;
    if (uVar3 != 0) {
      iVar2 = (int)(((local_50 + uVar3) - 1) / uVar3);
    }
    *param_4 = iVar2;
    if (iVar2 == 0) {
      _dev_err(*(undefined8 *)(param_2 + 0xa8),"%s:Err:sclk:%lu oversampling:%d speed:%u\n",
               "get_spi_clk_cfg",local_50,*(undefined4 *)(param_2 + 0x108),param_1);
      iVar2 = -0x16;
    }
    else {
      if (*(int *)(param_2 + 0x1a4) != 3) {
        writel_relaxed(*param_3 & 7,*(long *)(param_2 + 0x98) + 0x7c);
        writel_relaxed(*param_4 << 4 | 1,*(long *)(param_2 + 0x98) + 0x48);
        DataSynchronizationBarrier(3,3,0);
      }
      iVar2 = clk_set_rate(*(undefined8 *)(param_2 + 0x18),local_50);
      if (iVar2 != 0) {
        _dev_err(*(undefined8 *)(param_2 + 0xa8),"%s: clk_set_rate failed %d\n","get_spi_clk_cfg",
                 iVar2);
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_2 + 0xa8),"%s: Failed(%d) to find src clk for 0x%x\n",
             "get_spi_clk_cfg",iVar2,param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// spi_setup_word_len @ 001060b0 size=228
// signature: undefined spi_setup_word_len(void)
// callers: [spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

void spi_setup_word_len(long param_1,ulong param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x98) + 0x268);
  iVar1 = 0;
  if (param_3 != 0) {
    iVar1 = *(int *)(param_1 + 0xb8) / param_3;
  }
  uVar2 = uVar2 & 0xfffffc00 | param_3 + 0x3fcU & 0x3ff;
  if (*(int *)(param_1 + 0xb8) != iVar1 * param_3) {
    iVar1 = 1;
  }
  geni_se_config_packing(param_1,param_3,iVar1,(param_2 & 8) == 0,1,1);
  writel_relaxed(uVar2,*(long *)(param_1 + 0x98) + 0x268);
  ipc_log_string(*(undefined8 *)(param_1 + 0x1b8),"%s: %lu bpw %d pack_words %d\n",
                 "spi_setup_word_len",uVar2,param_3,iVar1);
  if (*(long *)(param_1 + 0xa8) != 0) {
    spi_trace_log(*(long *)(param_1 + 0xa8),"%s: %lu bpw %d pack_words %d\n","spi_setup_word_len",
                  uVar2,param_3,iVar1);
  }
  return;
}



//------------------------------------------------------------
// spi_geni_unlock_bus @ 00106194 size=776
// signature: undefined spi_geni_unlock_bus(void)
// callers: [spi_geni_runtime_suspend, spi_geni_unprepare_message]
//------------------------------------------------------------

void spi_geni_unlock_bus(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 *puVar10;
  
  lVar7 = *(long *)(param_1 + 0x98);
  lVar8 = *(long *)(lVar7 + 0x118);
  if ((*(char *)(lVar7 + 0x1cf) == '\0') || (*(char *)(lVar7 + 0x1d8) == '\0')) {
    *(undefined4 *)(lVar7 + 0x160) = 0;
    ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s %d\n","spi_geni_unlock_bus",0);
    if (*(long *)(lVar7 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar7 + 0xa8),"%s %d\n","spi_geni_unlock_bus",0);
    }
    lVar9 = *(long *)(lVar7 + 0x118);
    puVar10 = (undefined8 *)(lVar9 + 0x10);
    *puVar10 = 0;
    *(undefined8 *)(lVar9 + 0x18) = 0x31010000000000;
    sg_init_table(lVar8 + 0x60,1);
    *(ulong *)(lVar8 + 0x60) =
         (*(ulong *)(lVar8 + 0x60) & 3 | (((long)puVar10 * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6)
         - 0x200000000;
    *(uint *)(lVar8 + 0x68) = (uint)puVar10 & 0xfff;
    *(undefined4 *)(lVar8 + 0x6c) = 0x10;
    *(long *)(*(long *)(lVar7 + 0x118) + 0x158) = param_1;
    lVar8 = *(long *)(lVar7 + 0x118);
    plVar1 = *(long **)(lVar7 + 0x120);
    uVar4 = 0;
    if (plVar1 != (long *)0x0) {
      if ((*plVar1 == 0) || (pcVar6 = *(code **)(*plVar1 + 0x108), pcVar6 == (code *)0x0)) {
        uVar4 = 0;
      }
      else {
        if (*(int *)(pcVar6 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x1062e0);
          (*pcVar6)();
        }
        uVar4 = (*pcVar6)(plVar1,lVar8 + 0x60,1,1,3,0);
        lVar8 = *(long *)(lVar7 + 0x118);
      }
    }
    *(undefined8 *)(lVar8 + 0x148) = uVar4;
    uVar5 = *(ulong *)(*(long *)(lVar7 + 0x118) + 0x148);
    if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
      _dev_err(*(undefined8 *)(lVar7 + 0xa8),"Err setting up tx desc\n");
    }
    else {
      *(code **)(uVar5 + 0x28) = spi_gsi_tx_callback;
      *(long *)(*(long *)(*(long *)(lVar7 + 0x118) + 0x148) + 0x38) =
           *(long *)(lVar7 + 0x118) + 0xe8;
      *(long *)(*(long *)(lVar7 + 0x118) + 0x108) = *(long *)(lVar7 + 0x118) + 0x158;
      pcVar6 = *(code **)(*(long *)(*(long *)(lVar7 + 0x118) + 0x148) + 0x18);
      if (*(int *)(pcVar6 + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106354);
        (*pcVar6)();
      }
      uVar2 = (*pcVar6)();
      *(undefined4 *)(*(long *)(lVar7 + 0x118) + 0xe0) = uVar2;
      if (*(int *)(*(long *)(lVar7 + 0x118) + 0xe0) < 0) {
        _dev_err(*(undefined8 *)(lVar7 + 0xa8),"%s: dmaengine_submit failed (%d)\n",
                 "spi_geni_unlock_bus");
      }
      else {
        pcVar6 = *(code **)(**(long **)(lVar7 + 0x120) + 0x160);
        if (*(int *)(pcVar6 + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106394);
          (*pcVar6)();
        }
        (*pcVar6)();
        iVar3 = wait_for_completion_timeout(lVar7 + 0x160,0x3f);
        if (0 < iVar3) {
          return;
        }
        ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s failed\n","spi_geni_unlock_bus");
        if (*(long *)(lVar7 + 0xa8) == 0) {
          _printk(&DAT_001099d7,"spi_geni_unlock_bus");
        }
        else {
          _dev_err(*(long *)(lVar7 + 0xa8),"%s failed\n","spi_geni_unlock_bus");
        }
        if (*(long *)(lVar7 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar7 + 0xa8),"%s failed\n","spi_geni_unlock_bus");
        }
        geni_spi_se_dump_dbg_regs
                  (lVar7,*(undefined8 *)(lVar7 + 0x98),*(undefined8 *)(lVar7 + 0x1b8));
      }
    }
    pcVar6 = *(code **)(**(long **)(lVar7 + 0x120) + 0x148);
    if (pcVar6 != (code *)0x0) {
      if (*(int *)(pcVar6 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106494);
        (*pcVar6)();
      }
      (*pcVar6)();
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),
                   "%s:gpi reset happened for levm, no need to do unlock\n","spi_geni_unlock_bus");
    if (*(long *)(lVar7 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar7 + 0xa8),"%s:gpi reset happened for levm, no need to do unlock\n"
                    ,"spi_geni_unlock_bus");
    }
  }
  return;
}



//------------------------------------------------------------
// handle_fifo_timeout @ 0010649c size=492
// signature: undefined handle_fifo_timeout(void)
// callers: [spi_geni_transfer_one]
//------------------------------------------------------------

void handle_fifo_timeout(long param_1,long *param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  
  plVar3 = *(long **)(param_1 + 0x98);
  geni_spi_se_dump_dbg_regs(plVar3,plVar3[0x13],plVar3[0x37]);
  if (*(int *)((long)plVar3 + 0x1a4) == 1) {
    writel_relaxed(0,plVar3[0x13] + 0x80c);
  }
  if (*(char *)(param_1 + 0x3bf) == '\0') {
    plVar4 = plVar3 + 0x1c;
    *(undefined4 *)plVar4 = 0;
    if (param_2[1] != 0) {
      uVar1 = readl_relaxed(plVar3[0x13] + 0x804);
      for (uVar1 = uVar1 & 0x1ffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        readl_relaxed(plVar3[0x13] + 0x780);
      }
    }
    writel_relaxed(4,*plVar3 + 0x604);
    DataSynchronizationBarrier(3,3,0);
    lVar2 = wait_for_completion_timeout(plVar4,0xfa);
    if (lVar2 == 0) {
      *(undefined4 *)(plVar3 + 0x1c) = 0;
      writel_relaxed(2,*plVar3 + 0x604);
      DataSynchronizationBarrier(3,3,0);
      lVar2 = wait_for_completion_timeout(plVar4,0xfa);
      if (lVar2 == 0) {
        _dev_err(plVar3[0x15],"Failed to cancel/abort m_cmd\n");
      }
    }
  }
  if (*(int *)((long)plVar3 + 0x1a4) == 2) {
    if ((*param_2 != 0) && (param_2[3] != 0)) {
      *(undefined4 *)(plVar3 + 0x1c) = 0;
      writel_relaxed(1,plVar3[0x13] + 0xc58);
      lVar2 = wait_for_completion_timeout(plVar3 + 0x1c,0xfa);
      if (lVar2 == 0) {
        _dev_err(plVar3[0x15],"DMA TX RESET failed\n");
      }
      geni_se_tx_dma_unprep(plVar3,param_2[3],(int)param_2[2]);
    }
    if ((param_2[1] != 0) && (param_2[4] != 0)) {
      *(undefined4 *)(plVar3 + 0x1c) = 0;
      writel_relaxed(1,plVar3[0x13] + 0xd58);
      lVar2 = wait_for_completion_timeout(plVar3 + 0x1c,0xfa);
      if (lVar2 == 0) {
        _dev_err(plVar3[0x15],"DMA RX RESET failed\n");
      }
      geni_se_rx_dma_unprep(plVar3,param_2[4],(int)param_2[2]);
    }
  }
  if ((*(char *)(param_1 + 0x3bf) != '\0') && (*(char *)((long)plVar3 + 0x1d1) == '\0')) {
    __pm_runtime_suspend(plVar3[0x15],4);
  }
  *(undefined1 *)((long)plVar3 + 0x1de) = 0;
  return;
}



//------------------------------------------------------------
// writel @ 00106688 size=136
// signature: undefined writel(void)
// callers: [spi_geni_transfer_one]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1066a0,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1066e0,uVar1);
  return;
}



//------------------------------------------------------------
// spi_gsi_rx_callback @ 00106714 size=424
// signature: undefined spi_gsi_rx_callback(void)
// callers: []
//------------------------------------------------------------

void spi_gsi_rx_callback(int *param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  if ((param_1 == (int *)0x0) || (plVar1 = *(long **)(param_1 + 8), plVar1 == (long *)0x0)) {
    _printk(&DAT_00109152,"spi_gsi_rx_callback");
  }
  else {
    lVar3 = plVar1[1];
    if (*(long *)(lVar3 + 8) != 0) {
      lVar2 = *(long *)(*plVar1 + 0x98);
      if (param_1[2] == 0x10) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),"%s: Unexpected GSI CB error\n",
                       "spi_gsi_rx_callback");
        if (*(long *)(lVar2 + 0xa8) == 0) {
          _printk(&DAT_00108c48,"spi_gsi_rx_callback");
        }
        else {
          _dev_err(*(long *)(lVar2 + 0xa8),"%s: Unexpected GSI CB error\n","spi_gsi_rx_callback");
        }
        if (*(long *)(lVar2 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar2 + 0xa8),"%s: Unexpected GSI CB error\n",
                        "spi_gsi_rx_callback");
        }
      }
      else if (*param_1 == *(int *)(lVar3 + 0x10)) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),&DAT_00109676,"spi_gsi_rx_callback");
        if (*(long *)(lVar2 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar2 + 0xa8),&DAT_00109676,"spi_gsi_rx_callback");
        }
        complete(lVar2 + 0x180);
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x1b8),
                       "%s: Length mismatch. Expected %d Callback %d\n","spi_gsi_rx_callback");
        if (*(long *)(lVar2 + 0xa8) == 0) {
          _printk(&DAT_0010899f,"spi_gsi_rx_callback",*(undefined4 *)(lVar3 + 0x10),*param_1);
        }
        else {
          _dev_err(*(long *)(lVar2 + 0xa8),"%s: Length mismatch. Expected %d Callback %d\n",
                   "spi_gsi_rx_callback",*(undefined4 *)(lVar3 + 0x10),*param_1);
        }
        if (*(long *)(lVar2 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar2 + 0xa8),"%s: Length mismatch. Expected %d Callback %d\n",
                        "spi_gsi_rx_callback",*(undefined4 *)(lVar3 + 0x10),*param_1);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// spi_geni_runtime_suspend @ 001068c0 size=960
// signature: undefined spi_geni_runtime_suspend(void)
// callers: [spi_geni_hib_suspend, ssr_spi_force_suspend, spi_geni_suspend]
//------------------------------------------------------------

int spi_geni_runtime_suspend(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  char *pcVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *(long *)(param_1 + 0x98);
  lVar7 = *(long *)(lVar9 + 0x98);
  lVar10 = *(long *)(lVar7 + 0x1c0);
  if (lVar10 == 0) {
    uVar4 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar7 + 0x1c8) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar10,"%s:start at %llu nsec(%llu usec)\n","spi_geni_runtime_suspend",uVar4,
                   uVar4 / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s: %d\n","spi_geni_runtime_suspend",0);
  if (*(long *)(lVar7 + 0xa8) != 0) {
    spi_trace_log(*(long *)(lVar7 + 0xa8),"%s: %d\n","spi_geni_runtime_suspend",0);
  }
  disable_irq(*(undefined4 *)(lVar7 + 0xa0));
  if (*(char *)(lVar7 + 0x1cf) == '\0') {
    if (*(char *)(lVar7 + 0x1cc) != '\0') {
      iVar3 = spi_geni_gpi_pause_resume(lVar7,1);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((*(char *)(lVar7 + 0x1d0) != '\0') ||
       (((*(char *)(lVar7 + 0x1cd) != '\0' && (*(char *)(lVar7 + 0x1ce) == '\0')) ||
        (*(char *)(lVar7 + 0x1cc) == '\0')))) {
      geni_se_resources_off(lVar7);
      iVar3 = geni_icc_disable(lVar7);
      if (iVar3 != 0) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s failing at geni_icc_disable ret=%d\n",
                       "spi_geni_runtime_suspend",iVar3);
        if (*(long *)(lVar7 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar7 + 0xa8),"%s failing at geni_icc_disable ret=%d\n",
                        "spi_geni_runtime_suspend",iVar3);
        }
      }
      lVar9 = *(long *)(lVar7 + 0x1c0);
      if (lVar9 == 0) {
        return iVar3;
      }
      if (uVar4 == 0) {
        return iVar3;
      }
      if (*(int *)(lVar7 + 0x1c8) == 0) {
        return iVar3;
      }
      lVar7 = sched_clock();
      ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","spi_geni_runtime_suspend",lVar7 - uVar4
                     ,(lVar7 - uVar4) / 1000);
      return iVar3;
    }
    uVar8 = *(undefined8 *)(lVar7 + 0x18);
    uVar1 = *(undefined8 *)(lVar7 + 0x60);
    uVar2 = *(undefined8 *)(lVar7 + 0x68);
    clk_disable(uVar8);
    clk_unprepare(uVar8);
    clk_disable(uVar1);
    clk_unprepare(uVar1);
    clk_disable(uVar2);
    clk_unprepare(uVar2);
    iVar3 = geni_icc_disable(lVar7);
    if (iVar3 == 0) {
      return 0;
    }
    ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s failing at geni_icc_disable ret=%d\n",
                   "spi_geni_runtime_suspend",iVar3);
    lVar7 = *(long *)(lVar7 + 0xa8);
    if (lVar7 == 0) {
      return iVar3;
    }
    pcVar5 = "%s failing at geni_icc_disable ret=%d\n";
    pcVar6 = "spi_geni_runtime_suspend";
  }
  else {
    spi_geni_unlock_bus(lVar9);
    if ((*(char *)(lVar7 + 0xc0) == '\0') && (iVar3 = spi_geni_mas_setup(lVar9), iVar3 != 0)) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s mas_setup failed: %d\n",
                     "spi_geni_levm_suspend_proc",iVar3);
      if (*(long *)(lVar7 + 0xa8) == 0) {
        _printk(&DAT_00108c2d,"spi_geni_levm_suspend_proc",iVar3);
      }
      else {
        _dev_err(*(long *)(lVar7 + 0xa8),"%s mas_setup failed: %d\n","spi_geni_levm_suspend_proc",
                 iVar3);
      }
      lVar7 = *(long *)(lVar7 + 0xa8);
      if (lVar7 == 0) {
        return iVar3;
      }
      pcVar5 = "%s mas_setup failed: %d\n";
    }
    else {
      if ((*(char *)(lVar7 + 0x1cc) == '\0') ||
         (iVar3 = spi_geni_gpi_pause_resume(lVar7,1), iVar3 == 0)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s: ret:%d\n","spi_geni_levm_suspend_proc",0)
        ;
        if (*(long *)(lVar7 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar7 + 0xa8),"%s: ret:%d\n","spi_geni_levm_suspend_proc",0);
        }
        lVar9 = *(long *)(lVar7 + 0x1c0);
        if (lVar9 != 0) {
          if (uVar4 == 0) {
            return 0;
          }
          if (*(int *)(lVar7 + 0x1c8) == 0) {
            return 0;
          }
          lVar7 = sched_clock();
          ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","spi_geni_levm_suspend_proc",
                         lVar7 - uVar4,(lVar7 - uVar4) / 1000);
        }
        return 0;
      }
      ipc_log_string(*(undefined8 *)(lVar7 + 0x1b8),"%s: ret:%d\n","spi_geni_levm_suspend_proc",
                     iVar3);
      lVar7 = *(long *)(lVar7 + 0xa8);
      if (lVar7 == 0) {
        return iVar3;
      }
      pcVar5 = "%s: ret:%d\n";
    }
    pcVar6 = "spi_geni_levm_suspend_proc";
  }
  spi_trace_log(lVar7,pcVar5,pcVar6,iVar3);
  return iVar3;
}



//------------------------------------------------------------
// spi_geni_gpi_pause_resume @ 00106c80 size=368
// signature: undefined spi_geni_gpi_pause_resume(void)
// callers: [spi_geni_runtime_suspend, spi_geni_runtime_resume]
//------------------------------------------------------------

undefined8 spi_geni_gpi_pause_resume(long param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  long *plVar3;
  code *pcVar4;
  
  plVar3 = *(long **)(param_1 + 0x120);
  if (plVar3 == (long *)0x0) {
    return 0;
  }
  cVar1 = *(char *)(param_1 + 0x1e4);
  if ((param_2 & 1) == 0) {
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x130) = 5;
    }
    pcVar4 = *(code **)(*plVar3 + 0x140);
    if (pcVar4 == (code *)0x0) {
      iVar2 = -0x26;
    }
    else {
      if (*(int *)(pcVar4 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x106d18);
        (*pcVar4)();
      }
      iVar2 = (*pcVar4)();
      cVar1 = *(char *)(param_1 + 0x1e4);
    }
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x130) = 0;
      *(undefined1 *)(param_1 + 0x1e4) = 0;
    }
  }
  else {
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x130) = 5;
    }
    pcVar4 = *(code **)(*plVar3 + 0x138);
    if (pcVar4 == (code *)0x0) {
      iVar2 = -0x26;
      goto LAB_00106d5c;
    }
    if (*(int *)(pcVar4 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x106cdc);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)();
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_00106d5c:
  param_2 = param_2 & 1;
  ipc_log_string(*(undefined8 *)(param_1 + 0x1b8),"%s failed: tx:%d status:%d\n",
                 "spi_geni_gpi_pause_resume",iVar2,param_2);
  if (*(long *)(param_1 + 0xa8) == 0) {
    _printk(&DAT_00109733,"spi_geni_gpi_pause_resume",iVar2,param_2);
  }
  else {
    _dev_err(*(long *)(param_1 + 0xa8),"%s failed: tx:%d status:%d\n","spi_geni_gpi_pause_resume",
             iVar2,param_2);
  }
  if (*(long *)(param_1 + 0xa8) != 0) {
    spi_trace_log(*(long *)(param_1 + 0xa8),"%s failed: tx:%d status:%d\n",
                  "spi_geni_gpi_pause_resume",iVar2,param_2);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// spi_slave_state_show @ 00106df4 size=76
// signature: undefined spi_slave_state_show(void)
// callers: []
//------------------------------------------------------------

long spi_slave_state_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_3,4,&DAT_00108947,*(undefined1 *)(lVar2 + 0x1db));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// spi_slave_state_store @ 00106e44 size=8
// signature: undefined spi_slave_state_store(void)
// callers: []
//------------------------------------------------------------

undefined8 spi_slave_state_store(void)

{
  return 1;
}



//------------------------------------------------------------
// capture_kpi_show @ 00106e50 size=76
// signature: undefined capture_kpi_show(void)
// callers: []
//------------------------------------------------------------

long capture_kpi_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  if (lVar2 == 0) {
    lVar2 = -0x16;
  }
  else {
    iVar1 = scnprintf(param_3,4,&DAT_00108947,*(undefined4 *)(lVar2 + 0x1c8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// capture_kpi_store @ 00106ea0 size=268
// signature: undefined capture_kpi_store(void)
// callers: []
//------------------------------------------------------------

undefined8 capture_kpi_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  if (lVar4 == 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_00106f60;
  }
  iVar1 = kstrtoint(param_3,0,(int *)(lVar4 + 0x1c8));
  if (iVar1 == 0) {
    if ((*(int *)(lVar4 + 0x1c8) == 0) || (*(long *)(lVar4 + 0x1c0) != 0)) goto LAB_00106f60;
    local_40 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_60 = 0;
    uStack_58 = 0;
    lVar3 = (*(long **)(lVar4 + 0xa8))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(lVar4 + 0xa8);
    }
    scnprintf(&local_60,0x24,&DAT_00108de5,lVar3,&DAT_0010881e);
    lVar3 = ipc_log_context_create(4,&local_60,0);
    *(long *)(lVar4 + 0x1c0) = lVar3;
    if (lVar3 != 0) goto LAB_00106f60;
    pcVar2 = "Error creating kpi IPC logs\n";
  }
  else {
    param_4 = 0xffffffffffffffea;
    pcVar2 = "Invalid input\n";
  }
  _dev_err(param_1,pcVar2);
LAB_00106f60:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// spi_geni_suspend @ 00106fb0 size=920
// signature: undefined spi_geni_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int spi_geni_suspend(long param_1)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x98);
  lVar6 = *(long *)(lVar7 + 0x98);
  lVar5 = *(long *)(lVar6 + 0x1c0);
  if (lVar5 == 0) {
    uVar3 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar6 + 0x1de);
  }
  else if (*(int *)(lVar6 + 0x1c8) == 0) {
    uVar3 = 0;
    cVar1 = *(char *)(lVar6 + 0x1de);
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","spi_geni_suspend",uVar3,uVar3 / 1000)
    ;
    cVar1 = *(char *)(lVar6 + 0x1de);
  }
  if (cVar1 == '\0') {
    if ((*(char *)(lVar6 + 0x1cf) == '\0') && (*(char *)(lVar6 + 0x1d0) == '\0')) {
      if (*(int *)(param_1 + 0x20c) == 2) {
        iVar2 = 0;
      }
      else if ((*(long *)(lVar7 + 0x4f0) == lVar7 + 0x4f0) && (*(long *)(lVar7 + 0x500) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"%s: Force suspend","spi_geni_suspend");
        if (*(long *)(lVar6 + 0xa8) == 0) {
          _printk(&DAT_00108c0a,"spi_geni_suspend");
        }
        else {
          _dev_err(*(long *)(lVar6 + 0xa8),"%s: Force suspend","spi_geni_suspend");
        }
        if (*(long *)(lVar6 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar6 + 0xa8),"%s: Force suspend","spi_geni_suspend");
        }
        iVar2 = spi_geni_runtime_suspend(param_1);
        if (iVar2 == 0) {
          __pm_runtime_disable(param_1,1);
          __pm_runtime_set_status(param_1,2);
          pm_runtime_enable(param_1);
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"Force suspend Failed:%d",iVar2);
          if (*(long *)(lVar6 + 0xa8) == 0) {
            _printk(&DAT_00108ece,iVar2);
          }
          else {
            _dev_err(*(long *)(lVar6 + 0xa8),"Force suspend Failed:%d",iVar2);
          }
          if (*(long *)(lVar6 + 0xa8) != 0) {
            spi_trace_log(*(long *)(lVar6 + 0xa8),"Force suspend Failed:%d",iVar2);
          }
        }
      }
      else {
        iVar2 = -0x10;
      }
      lVar5 = *(long *)(lVar6 + 0x1c0);
      if (lVar5 == 0) {
        return iVar2;
      }
      if (uVar3 == 0) {
        return iVar2;
      }
      if (*(int *)(lVar6 + 0x1c8) == 0) {
        return iVar2;
      }
      lVar6 = sched_clock();
      ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","spi_geni_suspend",lVar6 - uVar3,
                     (lVar6 - uVar3) / 1000);
      return iVar2;
    }
    if (*(int *)(param_1 + 0x20c) == 2) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"%s: System suspend bypassed due to le/la vm\n",
                     "spi_geni_suspend");
      if (*(long *)(lVar6 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar6 + 0xa8),"%s: System suspend bypassed due to le/la vm\n",
                      "spi_geni_suspend");
      }
      return 0;
    }
    ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),":%s: Client managed runtime PM is active\n",
                   "spi_geni_suspend");
    if (*(long *)(lVar6 + 0xa8) == 0) {
      _printk(&DAT_00109369,"spi_geni_suspend");
    }
    else {
      _dev_err(*(long *)(lVar6 + 0xa8),":%s: Client managed runtime PM is active\n",
               "spi_geni_suspend");
    }
    lVar5 = *(long *)(lVar6 + 0xa8);
    if (lVar5 == 0) {
      return -0x10;
    }
    pcVar4 = ":%s: Client managed runtime PM is active\n";
  }
  else {
    if (*(int *)(param_1 + 0x20c) == 2) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),
                     "%s System suspend not allowed while xfer in progress=%d\n","spi_geni_suspend",
                     0);
      if (*(long *)(lVar6 + 0xa8) == 0) {
        return -0x10;
      }
      spi_trace_log(*(long *)(lVar6 + 0xa8),
                    "%s System suspend not allowed while xfer in progress=%d\n","spi_geni_suspend",0
                   );
      return -0x10;
    }
    ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),":%s: runtime PM is active\n","spi_geni_suspend");
    if (*(long *)(lVar6 + 0xa8) == 0) {
      _printk(&DAT_00109571,"spi_geni_suspend");
    }
    else {
      _dev_err(*(long *)(lVar6 + 0xa8),":%s: runtime PM is active\n","spi_geni_suspend");
    }
    lVar5 = *(long *)(lVar6 + 0xa8);
    if (lVar5 == 0) {
      return -0x10;
    }
    pcVar4 = ":%s: runtime PM is active\n";
  }
  spi_trace_log(lVar5,pcVar4,"spi_geni_suspend");
  return -0x10;
}



//------------------------------------------------------------
// spi_geni_resume @ 0010734c size=8
// signature: undefined spi_geni_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 spi_geni_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// spi_geni_hib_suspend @ 00107358 size=808
// signature: undefined spi_geni_hib_suspend(void)
// callers: []
//------------------------------------------------------------

int spi_geni_hib_suspend(long param_1)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  lVar4 = *(long *)(lVar5 + 0x1c0);
  if (lVar4 == 0) {
    uVar3 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar5 + 0x1de);
  }
  else if (*(int *)(lVar5 + 0x1c8) == 0) {
    uVar3 = 0;
    cVar1 = *(char *)(lVar5 + 0x1de);
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","spi_geni_hib_suspend",uVar3,
                   uVar3 / 1000);
    cVar1 = *(char *)(lVar5 + 0x1de);
  }
  if (cVar1 == '\0') {
    if (*(char *)(lVar5 + 0x1cc) != '\0') {
      *(undefined1 *)(lVar5 + 0x1e4) = 1;
      ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),
                     "%s: GSI channels re-config required for hibernation","spi_geni_hib_suspend");
      if (param_1 == 0) {
        _printk(&DAT_00109196,"spi_geni_hib_suspend");
      }
      else {
        _dev_err(param_1,"%s: GSI channels re-config required for hibernation",
                 "spi_geni_hib_suspend");
        spi_trace_log(param_1,"%s: GSI channels re-config required for hibernation",
                      "spi_geni_hib_suspend");
      }
    }
    if (*(int *)(param_1 + 0x20c) == 2) {
      iVar2 = 0;
    }
    else {
      lVar4 = *(long *)(param_1 + 0x98);
      lVar6 = *(long *)(lVar4 + 0x98);
      if ((*(long *)(lVar4 + 0x4f0) == lVar4 + 0x4f0) && (*(long *)(lVar4 + 0x500) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"%s: Force suspend","spi_geni_hib_suspend");
        if (param_1 == 0) {
          _printk(&DAT_00108c0a,"spi_geni_hib_suspend");
        }
        else {
          _dev_err(param_1,"%s: Force suspend","spi_geni_hib_suspend");
          spi_trace_log(param_1,"%s: Force suspend","spi_geni_hib_suspend");
        }
        iVar2 = spi_geni_runtime_suspend(param_1);
        if (iVar2 == 0) {
          __pm_runtime_disable(param_1,1);
          __pm_runtime_set_status(param_1,2);
          pm_runtime_enable(param_1);
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar6 + 0x1b8),"Force suspend Failed:%d",iVar2);
          if (param_1 == 0) {
            _printk(&DAT_00108ece,iVar2);
          }
          else {
            _dev_err(param_1,"Force suspend Failed:%d",iVar2);
            spi_trace_log(param_1,"Force suspend Failed:%d",iVar2);
          }
        }
      }
      else {
        iVar2 = -0x10;
      }
    }
    lVar4 = *(long *)(lVar5 + 0x1c0);
    if (((lVar4 != 0) && (uVar3 != 0)) && (*(int *)(lVar5 + 0x1c8) != 0)) {
      lVar5 = sched_clock();
      ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","spi_geni_hib_suspend",lVar5 - uVar3,
                     (lVar5 - uVar3) / 1000);
    }
  }
  else if (*(int *)(param_1 + 0x20c) == 2) {
    iVar2 = 0;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x1b8),":%s: runtime PM is active\n",
                   "spi_geni_hib_suspend");
    if (param_1 == 0) {
      _printk(&DAT_00109571,"spi_geni_hib_suspend");
      iVar2 = -0x10;
    }
    else {
      _dev_err(param_1,":%s: runtime PM is active\n","spi_geni_hib_suspend");
      spi_trace_log(param_1,":%s: runtime PM is active\n","spi_geni_hib_suspend");
      iVar2 = -0x10;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// spi_geni_runtime_resume @ 00107684 size=1472
// signature: undefined spi_geni_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int spi_geni_runtime_resume(long param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  char *pcVar6;
  code *pcVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  lVar10 = *(long *)(param_1 + 0x98);
  lVar8 = *(long *)(lVar10 + 0x98);
  lVar9 = *(long *)(lVar8 + 0x1c0);
  if (lVar9 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar1 = *(char *)(lVar8 + 0x218);
  }
  else if (*(int *)(lVar8 + 0x1c8) == 0) {
    uVar4 = 0;
    cVar1 = *(char *)(lVar8 + 0x218);
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar9,"%s:start at %llu nsec(%llu usec)\n","spi_geni_runtime_resume",uVar4,
                   uVar4 / 1000);
    cVar1 = *(char *)(lVar8 + 0x218);
  }
  if (cVar1 != '\0') {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: Error runtime resume in SSR down\n",
                   "spi_geni_runtime_resume");
    return -0xb;
  }
  if (*(char *)(lVar8 + 0x1cf) != '\0') {
    if ((*(char *)(lVar8 + 0xc0) == '\0') && (iVar2 = spi_geni_mas_setup(lVar10), iVar2 != 0)) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s mas_setup failed: %d\n",
                     "spi_geni_levm_resume_proc",iVar2);
      if (*(long *)(lVar8 + 0xa8) == 0) {
        _printk(&DAT_00108c2d,"spi_geni_levm_resume_proc",iVar2);
      }
      else {
        _dev_err(*(long *)(lVar8 + 0xa8),"%s mas_setup failed: %d\n","spi_geni_levm_resume_proc",
                 iVar2);
      }
      lVar8 = *(long *)(lVar8 + 0xa8);
      if (lVar8 == 0) {
        return iVar2;
      }
      pcVar5 = "%s mas_setup failed: %d\n";
    }
    else if ((*(char *)(lVar8 + 0x1cc) == '\0') ||
            (iVar2 = spi_geni_gpi_pause_resume(lVar8,0), iVar2 == 0)) {
      iVar2 = spi_geni_lock_bus(lVar10);
      if (iVar2 == 0) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: ret:%d\n","spi_geni_levm_resume_proc",0);
        if (*(long *)(lVar8 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar8 + 0xa8),"%s: ret:%d\n","spi_geni_levm_resume_proc",0);
        }
        lVar9 = *(long *)(lVar8 + 0x1c0);
        if (lVar9 != 0) {
          if (uVar4 == 0) {
            return 0;
          }
          if (*(int *)(lVar8 + 0x1c8) == 0) {
            return 0;
          }
          lVar8 = sched_clock();
          ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","spi_geni_levm_resume_proc",
                         lVar8 - uVar4,(lVar8 - uVar4) / 1000);
        }
        return 0;
      }
      ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s lock_bus failed: %d\n",
                     "spi_geni_levm_resume_proc",iVar2);
      if (*(long *)(lVar8 + 0xa8) == 0) {
        _printk(&DAT_00108cf0,"spi_geni_levm_resume_proc",iVar2);
      }
      else {
        _dev_err(*(long *)(lVar8 + 0xa8),"%s lock_bus failed: %d\n","spi_geni_levm_resume_proc",
                 iVar2);
      }
      lVar8 = *(long *)(lVar8 + 0xa8);
      if (lVar8 == 0) {
        return iVar2;
      }
      pcVar5 = "%s lock_bus failed: %d\n";
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: ret:%d\n","spi_geni_levm_resume_proc",iVar2
                    );
      lVar8 = *(long *)(lVar8 + 0xa8);
      if (lVar8 == 0) {
        return iVar2;
      }
      pcVar5 = "%s: ret:%d\n";
    }
    pcVar6 = "spi_geni_levm_resume_proc";
    goto LAB_001078b8;
  }
  ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: %d\n","spi_geni_runtime_resume",0);
  if (*(long *)(lVar8 + 0xa8) != 0) {
    spi_trace_log(*(long *)(lVar8 + 0xa8),"%s: %d\n","spi_geni_runtime_resume",0);
  }
  if ((*(char *)(lVar8 + 0x1ce) != '\0') && (*(long **)(lVar8 + 0x120) != (long *)0x0)) {
    pcVar7 = *(code **)(**(long **)(lVar8 + 0x120) + 0x140);
    if (pcVar7 == (code *)0x0) {
      iVar2 = -0x26;
LAB_00107b9c:
      ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s dmaengine_resume failed: %d\n",
                     "spi_geni_runtime_resume",iVar2);
      if (*(long *)(lVar8 + 0xa8) == 0) {
        _printk(&DAT_00108ee8,"spi_geni_runtime_resume",iVar2);
      }
      else {
        _dev_err(*(long *)(lVar8 + 0xa8),"%s dmaengine_resume failed: %d\n",
                 "spi_geni_runtime_resume",iVar2);
      }
      if (*(long *)(lVar8 + 0xa8) != 0) {
        spi_trace_log(*(long *)(lVar8 + 0xa8),"%s dmaengine_resume failed: %d\n",
                      "spi_geni_runtime_resume",iVar2);
      }
    }
    else {
      if (*(int *)(pcVar7 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x107828);
        (*pcVar7)();
      }
      iVar2 = (*pcVar7)();
      if (iVar2 != 0) goto LAB_00107b9c;
    }
    ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: Shared_SE dma_resume call\n",
                   "spi_geni_runtime_resume");
    if (*(long *)(lVar8 + 0xa8) != 0) {
      spi_trace_log(*(long *)(lVar8 + 0xa8),"%s: Shared_SE dma_resume call\n",
                    "spi_geni_runtime_resume");
    }
  }
  if (((*(char *)(lVar8 + 0x1cd) == '\0') && (*(char *)(lVar8 + 0x1d0) == '\0')) &&
     (*(char *)(lVar8 + 0x1cc) != '\0')) {
    iVar2 = geni_icc_enable(lVar8);
    if (iVar2 == 0) {
      iVar2 = geni_se_common_clks_on
                        (*(undefined8 *)(lVar8 + 0x18),*(undefined8 *)(lVar8 + 0x60),
                         *(undefined8 *)(lVar8 + 0x68));
      if (iVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: Error %d turning on clocks\n",
                       "spi_geni_runtime_resume",iVar2);
        if (*(long *)(lVar8 + 0xa8) != 0) {
          spi_trace_log(*(long *)(lVar8 + 0xa8),"%s: Error %d turning on clocks\n",
                        "spi_geni_runtime_resume",iVar2);
        }
      }
      iVar2 = spi_geni_gpi_pause_resume(lVar8,0);
      return iVar2;
    }
LAB_00107880:
    ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s failing at geni icc enable ret=%d\n",
                   "spi_geni_runtime_resume",iVar2);
    lVar8 = *(long *)(lVar8 + 0xa8);
    if (lVar8 == 0) {
      return iVar2;
    }
    pcVar5 = "%s failing at geni icc enable ret=%d\n";
  }
  else {
    iVar2 = geni_icc_enable(lVar8);
    if (iVar2 != 0) goto LAB_00107880;
    iVar3 = geni_se_resources_on(lVar8);
    writel_relaxed(0x7f,*(long *)(lVar8 + 0x98) + 0x24);
    __const_udelay(0xa7c6);
    if ((*(char *)(lVar8 + 0x1e4) == '\0') || (*(char *)(lVar8 + 0xc0) != '\0')) {
LAB_001079a0:
      if (*(char *)(lVar8 + 0x1cc) != '\0') {
        iVar3 = spi_geni_gpi_pause_resume(lVar8,0);
      }
      enable_irq(*(undefined4 *)(lVar8 + 0xa0));
      if (*(char *)(lVar8 + 0x1cc) != '\0') {
        iVar3 = spi_geni_gpi_pause_resume(lVar8,0);
      }
      lVar9 = *(long *)(lVar8 + 0x1c0);
      if (lVar9 == 0) {
        return iVar3;
      }
      if (uVar4 == 0) {
        return iVar3;
      }
      if (*(int *)(lVar8 + 0x1c8) == 0) {
        return iVar3;
      }
      lVar8 = sched_clock();
      ipc_log_string(lVar9,"%s:took %llu nsec(%llu usec)\n","spi_geni_runtime_resume",lVar8 - uVar4,
                     (lVar8 - uVar4) / 1000);
      return iVar3;
    }
    iVar2 = spi_geni_mas_setup(lVar10);
    iVar3 = 0;
    if (iVar2 == 0) goto LAB_001079a0;
    ipc_log_string(*(undefined8 *)(lVar8 + 0x1b8),"%s: Error %d deep sleep mas setup\n",
                   "spi_geni_runtime_resume",iVar2);
    lVar8 = *(long *)(lVar8 + 0xa8);
    if (lVar8 == 0) {
      return iVar2;
    }
    pcVar5 = "%s: Error %d deep sleep mas setup\n";
  }
  pcVar6 = "spi_geni_runtime_resume";
LAB_001078b8:
  spi_trace_log(lVar8,pcVar5,pcVar6,iVar2);
  return iVar2;
}



//------------------------------------------------------------
// geni_se_common_clks_on @ 00107c44 size=192
// signature: undefined geni_se_common_clks_on(void)
// callers: [spi_geni_runtime_resume]
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
// init_module @ 00107d6c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&spi_geni_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00107d9c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&spi_geni_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 0010c000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_spi_log_info, perf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010c008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010c010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_spi_log_info, perf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 0010c018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [trace_event_raw_event_spi_log_info, perf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010c020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010c028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010c030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spi_trace_log, trace_event_raw_event_spi_log_info, spi_geni_prepare_message, perf_trace_spi_log_info, capture_kpi_store, get_spi_clk_cfg, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010c038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010c040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0010c048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010c068 size=1
// signature: undefined ipc_log_string(void)
// callers: [spi_geni_runtime_suspend, spi_geni_hib_suspend, spi_geni_unprepare_transfer_hardware, spi_geni_lock_bus, ssr_spi_force_suspend, spi_geni_runtime_resume, spi_geni_mas_setup, spi_geni_prepare_message, spi_geni_gpi_pause_resume, spi_gsi_rx_callback, spi_geni_probe, spi_gsi_ch_cb, spi_geni_transfer_one, spi_geni_remove, spi_gsi_tx_callback, geni_spi_se_dump_dbg_regs, spi_setup_word_len, spi_geni_prepare_transfer_hardware, ssr_spi_force_resume, spi_geni_unprepare_message, geni_spi_irq, spi_geni_unlock_bus, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010c070 size=1
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
// platform_driver_unregister @ 0010c078 size=1
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
// trace_raw_output_prep @ 0010c080 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010c088 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010c090 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_spi_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010c098 size=1
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
// log_post_read_mmio @ 0010c0a0 size=1
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
// of_find_property @ 0010c0a8 size=1
// signature: undefined of_find_property(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __spi_alloc_controller @ 0010c0b0 size=1
// signature: undefined __spi_alloc_controller(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __spi_alloc_controller(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010c0b8 size=1
// signature: undefined _dev_err(void)
// callers: [spi_geni_runtime_suspend, spi_geni_hib_suspend, spi_geni_lock_bus, ssr_spi_force_suspend, spi_geni_runtime_resume, spi_geni_mas_setup, spi_geni_prepare_message, handle_fifo_timeout, spi_geni_gpi_pause_resume, spi_gsi_rx_callback, capture_kpi_store, spi_geni_probe, spi_gsi_ch_cb, spi_geni_transfer_one, spi_gsi_tx_callback, spi_geni_prepare_transfer_hardware, ssr_spi_force_resume, geni_spi_irq, spi_geni_unlock_bus, get_spi_clk_cfg, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010c0c0 size=1
// signature: undefined _dev_info(void)
// callers: [spi_geni_mas_setup, spi_slv_setup, spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010c0c8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_get @ 0010c0d0 size=1
// signature: undefined geni_icc_get(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_set_bw @ 0010c0d8 size=1
// signature: undefined geni_icc_set_bw(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_enable @ 0010c0e0 size=1
// signature: undefined geni_icc_enable(void)
// callers: [spi_geni_runtime_resume, spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 0010c0e8 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 0010c0f0 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 0010c0f8 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_prepare_transfer_hardware, spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010c100 size=1
// signature: undefined devm_clk_get(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0010c108 size=1
// signature: undefined platform_get_irq(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 0010c110 size=1
// signature: undefined irq_modify_status(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010c118 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010c120 size=1
// signature: undefined dma_set_mask(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010c128 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0010c130 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 0010c138 size=1
// signature: undefined put_device(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010c140 size=1
// signature: undefined devm_ioremap(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010c148 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010c150 size=1
// signature: undefined __mutex_init(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010c158 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [spi_geni_hib_suspend, ssr_spi_force_suspend, spi_geni_probe, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010c160 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010c168 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010c170 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [spi_geni_hib_suspend, ssr_spi_force_suspend, spi_geni_probe, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010c178 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [spi_geni_mas_setup, capture_kpi_store, spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_disable @ 0010c180 size=1
// signature: undefined geni_icc_disable(void)
// callers: [spi_geni_remove, spi_geni_runtime_suspend, spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spi_register_controller @ 0010c188 size=1
// signature: undefined spi_register_controller(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spi_register_controller(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0010c190 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0010c198 size=1
// signature: undefined device_create_file(void)
// callers: [spi_geni_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 0010c1a0 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [spi_geni_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 0010c1a8 size=1
// signature: undefined device_remove_file(void)
// callers: [spi_geni_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0010c1b0 size=1
// signature: undefined clk_disable(void)
// callers: [spi_geni_remove, spi_geni_runtime_suspend, geni_se_common_clks_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0010c1b8 size=1
// signature: undefined clk_unprepare(void)
// callers: [spi_geni_remove, spi_geni_runtime_suspend, geni_se_common_clks_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spi_unregister_controller @ 0010c1c0 size=1
// signature: undefined spi_unregister_controller(void)
// callers: [spi_geni_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spi_unregister_controller(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010c1d0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [spi_geni_remove, spi_geni_hib_suspend, ssr_spi_force_suspend, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0010c1d8 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [spi_geni_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010c1e0 size=1
// signature: undefined complete_all(void)
// callers: [spi_gsi_ch_cb, spi_slv_abort]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 0010c1e8 size=1
// signature: undefined sched_clock(void)
// callers: [spi_geni_runtime_suspend, spi_geni_hib_suspend, spi_geni_unprepare_transfer_hardware, spi_geni_prepare_transfer_hardware, spi_geni_unprepare_message, spi_geni_runtime_resume, geni_spi_irq, spi_geni_prepare_message, spi_geni_transfer_one, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010c1f0 size=1
// signature: undefined complete(void)
// callers: [spi_gsi_tx_callback, ssr_spi_force_suspend, geni_spi_irq, spi_gsi_rx_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010c1f8 size=1
// signature: undefined mutex_lock(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_prepare_transfer_hardware, ssr_spi_force_suspend, ssr_spi_force_resume, spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010c200 size=1
// signature: undefined mutex_unlock(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_prepare_transfer_hardware, ssr_spi_force_suspend, ssr_spi_force_resume, spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010c208 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [spi_geni_prepare_transfer_hardware, ssr_spi_force_resume, spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010c210 size=1
// signature: undefined _printk(void)
// callers: [spi_geni_runtime_suspend, spi_geni_hib_suspend, spi_geni_lock_bus, ssr_spi_force_suspend, spi_geni_runtime_resume, spi_geni_prepare_message, spi_geni_gpi_pause_resume, spi_gsi_rx_callback, spi_gsi_ch_cb, spi_geni_transfer_one, spi_gsi_tx_callback, spi_geni_prepare_transfer_hardware, ssr_spi_force_resume, spi_geni_unlock_bus, spi_geni_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010c218 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_select_mode @ 0010c220 size=1
// signature: undefined geni_se_select_mode(void)
// callers: [spi_geni_prepare_message, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_select_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 0010c228 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 0010c230 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0010c238 size=1
// signature: undefined dev_driver_string(void)
// callers: [spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010c240 size=1
// signature: undefined __warn_printk(void)
// callers: [spi_geni_prepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 0010c248 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [spi_geni_unprepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010c250 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_unprepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010c258 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_unprepare_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010c260 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [spi_geni_unprepare_transfer_hardware, spi_geni_unprepare_message, handle_fifo_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010c268 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_prep @ 0010c270 size=1
// signature: undefined geni_se_rx_dma_prep(void)
// callers: [spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_prep @ 0010c278 size=1
// signature: undefined geni_se_tx_dma_prep(void)
// callers: [spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010c280 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [spi_geni_lock_bus, handle_fifo_timeout, spi_geni_unlock_bus, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_unprep @ 0010c288 size=1
// signature: undefined geni_se_tx_dma_unprep(void)
// callers: [handle_fifo_timeout, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_unprep @ 0010c290 size=1
// signature: undefined geni_se_rx_dma_unprep(void)
// callers: [handle_fifo_timeout, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 0010c298 size=1
// signature: undefined sg_init_table(void)
// callers: [spi_geni_lock_bus, spi_geni_unlock_bus, spi_geni_transfer_one]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0010c2a0 size=1
// signature: undefined disable_irq(void)
// callers: [spi_geni_runtime_suspend, ssr_spi_force_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0010c2a8 size=1
// signature: undefined enable_irq(void)
// callers: [ssr_spi_force_resume, spi_geni_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010c2b0 size=1
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
// log_post_write_mmio @ 0010c2b8 size=1
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
// dma_request_chan @ 0010c2c0 size=1
// signature: undefined dma_request_chan(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_request_chan(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_get_qup_hw_version @ 0010c2c8 size=1
// signature: undefined geni_se_get_qup_hw_version(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_get_qup_hw_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_init @ 0010c2d0 size=1
// signature: undefined geni_se_init(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_release_channel @ 0010c2d8 size=1
// signature: undefined dma_release_channel(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_release_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010c2e0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [spi_geni_mas_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_clk_freq_match @ 0010c2e8 size=1
// signature: undefined geni_se_clk_freq_match(void)
// callers: [get_spi_clk_cfg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_clk_freq_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 0010c2f0 size=1
// signature: undefined clk_set_rate(void)
// callers: [get_spi_clk_cfg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_config_packing @ 0010c2f8 size=1
// signature: undefined geni_se_config_packing(void)
// callers: [spi_setup_word_len]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_config_packing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_resources_off @ 0010c300 size=1
// signature: undefined geni_se_resources_off(void)
// callers: [spi_geni_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010c308 size=1
// signature: undefined scnprintf(void)
// callers: [spi_slave_state_show, capture_kpi_show, capture_kpi_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0010c310 size=1
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
// geni_se_resources_on @ 0010c318 size=1
// signature: undefined geni_se_resources_on(void)
// callers: [spi_geni_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010c320 size=1
// signature: undefined __const_udelay(void)
// callers: [spi_geni_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0010c328 size=1
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
// clk_enable @ 0010c330 size=1
// signature: undefined clk_enable(void)
// callers: [geni_se_common_clks_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



