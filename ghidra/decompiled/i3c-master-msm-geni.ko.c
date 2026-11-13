// Decompiled by Ghidra 12.2
// Program: i3c-master-msm-geni.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_i3c_log_info @ 0010101c size=116
// signature: undefined __traceiter_i3c_log_info(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_i3c_log_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0010b400;
  plVar2 = DAT_0010b400;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10106c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_i3c_log_info @ 00101094 size=308
// signature: undefined trace_event_raw_event_i3c_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_i3c_log_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1011c4);
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
// perf_trace_i3c_log_info @ 001011d0 size=384
// signature: undefined perf_trace_i3c_log_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_i3c_log_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10134c);
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
// __bpf_trace_i3c_log_info @ 00101358 size=28
// signature: undefined __bpf_trace_i3c_log_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_i3c_log_info(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// i3c_trace_log @ 00101378 size=136
// signature: undefined i3c_trace_log(void)
// callers: [geni_i3c_master_priv_xfers, gi3c_gsi_tx_cb, geni_i3c_master_enable_ibi, geni_i3c_master_attach_i2c_dev, geni_i3c_irq, geni_i3c_runtime_suspend, geni_i3c_resume_early, geni_i3c_se_dump_dbg_regs, i3c_ibi_rsrcs_init, i3c_geni_execute_write_command, geni_i3c_remove, gi3c_gsi_rx_cb, qcom_geni_i3c_conf, i3c_geni_execute_read_command, geni_i3c_master_disable_ibi, gi3c_gsi_cb_err, i3c_naon_ibi_clk_init, geni_i3c_get_ver_info, geni_i3c_enable_ibi_ctrl, i3c_setup_cfg0_tre, geni_i3c_runtime_resume, geni_i3c_enable_naon_ibi_clks, geni_i3c_err_prep_sg, i3c_geni_runtime_get_mutex_lock, geni_i3c_probe, geni_i3c_fifo_dma_xfer, geni_i3c_master_i2c_xfers, gi3c_ev_cb, geni_i3c_master_supports_ccc_cmd, geni_i3c_gsi_stop_on_bus, geni_i3c_enable_hotjoin_irq, geni_i3c_err, geni_i3c_gsi_se_init, geni_i3c_master_request_ibi, geni_i3c_master_bus_init, geni_i3c_master_attach_i3c_dev, geni_i3c_hotjoin, geni_i3c_dump_dbg_regs, geni_i3c_master_send_ccc_cmd, qcom_geni_i3c_ibi_unconf, geni_i3c_ibi_irq, geni_i3c_suspend_late, i3c_setup_go_tre, qcom_geni_i3c_ibi_conf]
//------------------------------------------------------------

void i3c_trace_log(void)

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
// geni_i3c_se_dump_dbg_regs @ 001014a4 size=808
// signature: undefined geni_i3c_se_dump_dbg_regs(void)
// callers: [geni_i3c_dump_dbg_regs]
//------------------------------------------------------------

void geni_i3c_se_dump_dbg_regs(long param_1,long param_2,undefined8 param_3)

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
  uVar20 = readl_relaxed(param_2 + 0xc30);
  uVar21 = readl_relaxed(param_2 + 0xc34);
  ipc_log_string(param_3,"%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                 "geni_i3c_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
                  "geni_i3c_se_dump_dbg_regs",uVar1,uVar2,uVar4,uVar5);
  }
  ipc_log_string(param_3,"dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",
                 uVar7,uVar6,uVar8,uVar9);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n",uVar7,
                  uVar6,uVar8,uVar9);
  }
  ipc_log_string(param_3,"se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",
                 uVar10,uVar11,uVar12,uVar13);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n",uVar10,
                  uVar11,uVar12,uVar13);
  }
  ipc_log_string(param_3,"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",uVar14,uVar15,uVar3
                );
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n",
                  uVar14,uVar15,uVar3);
  }
  ipc_log_string(param_3,
                 "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                 uVar18,uVar19,uVar16,uVar17);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
                  uVar18,uVar19,uVar16,uVar17);
  }
  ipc_log_string(param_3,"geni_dma_tx_ptr_l:0x%x, geni_dma_tx_ptr_h:0x%x\n",uVar20,uVar21);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"geni_dma_tx_ptr_l:0x%x, geni_dma_tx_ptr_h:0x%x\n",uVar20,
                  uVar21);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_i3c_log_info @ 001017d0 size=112
// signature: undefined trace_raw_output_i3c_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_i3c_log_info(long param_1,undefined8 param_2,undefined8 param_3)

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
// readl_relaxed @ 00101840 size=124
// signature: undefined readl_relaxed(void)
// callers: [geni_i3c_master_priv_xfers, geni_i3c_enable_hotjoin_irq, geni_i3c_irq, geni_i3c_se_dump_dbg_regs, i3c_ibi_rsrcs_init, geni_i3c_dump_dbg_regs, geni_se_get_tx_fifo_depth, qcom_geni_i3c_ibi_unconf, geni_i3c_get_ver_info, geni_i3c_ibi_irq, geni_i3c_enable_ibi_ctrl, geni_i3c_probe, qcom_geni_i3c_ibi_conf, geni_i3c_fifo_dma_xfer]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101888,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// geni_i3c_probe @ 001018c0 size=4252
// signature: undefined geni_i3c_probe(void)
// callers: []
//------------------------------------------------------------

ulong geni_i3c_probe(long param_1)

{
  ulong *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  char *pcVar10;
  ulong *puVar11;
  ulong *puVar12;
  ulong uVar13;
  undefined8 uVar14;
  
  plVar8 = (long *)(param_1 + 0x10);
  puVar6 = (ulong *)devm_kmalloc(plVar8,0x5408,0xdc0);
  if (puVar6 == (ulong *)0x0) {
    uVar7 = 0xfffffff4;
    goto LAB_001022f8;
  }
  lVar9 = *(long *)(param_1 + 0x80);
  puVar11 = puVar6 + 1;
  *puVar11 = (ulong)plVar8;
  if (lVar9 == 0) {
    lVar9 = *plVar8;
  }
  uVar7 = ipc_log_context_create(4,lVar9,0);
  puVar6[0x135] = uVar7;
  if (uVar7 == 0) {
    _dev_info(plVar8,"Error creating IPC Log\n");
  }
  uVar7 = (ulong)i3c_nos;
  if ((int)i3c_nos < 2) {
    if (2 < i3c_nos) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x10295c);
      i3c_nos = i3c_nos + 1;
      (*pcVar3)();
    }
    i3c_nos = i3c_nos + 1;
    *(ulong **)(i3c_geni_dev + uVar7 * 8) = puVar6;
  }
  lVar9 = 0;
  puVar1 = puVar6 + 0x135;
  do {
    uVar14 = *(undefined8 *)((long)&PTR_s_i3c_rgltr1_0010af00 + lVar9);
    uVar7 = devm_regulator_get(plVar8,uVar14);
    if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
      iVar4 = regulator_enable(uVar7);
      if (iVar4 == 0) {
        ipc_log_string(*puVar1,"%s regulator enabled: %d\n",uVar14,0);
        if (*puVar11 != 0) {
          i3c_trace_log(*puVar11,"%s regulator enabled: %d\n",uVar14,0);
        }
        iVar4 = regulator_set_voltage(uVar7,1800000,1800000);
        if (iVar4 == 0) {
          ipc_log_string(*puVar1,"%s:set_volt done:%d\n",uVar14,0);
          uVar7 = *puVar11;
          if (uVar7 != 0) {
            pcVar10 = "%s:set_volt done:%d\n";
            iVar4 = 0;
            goto LAB_001019a4;
          }
        }
        else {
          ipc_log_string(*puVar1,"%s:set_volt fail: %d\n",uVar14,iVar4);
          uVar7 = *puVar11;
          if (uVar7 != 0) {
            pcVar10 = "%s:set_volt fail: %d\n";
LAB_001019a4:
            i3c_trace_log(uVar7,pcVar10,uVar14,iVar4);
          }
        }
      }
      else {
        ipc_log_string(*puVar1,"%s regulator enable fail: %d\n",uVar14,iVar4);
        uVar7 = *puVar11;
        if (uVar7 != 0) {
          pcVar10 = "%s regulator enable fail: %d\n";
          goto LAB_001019a4;
        }
      }
    }
    lVar9 = lVar9 + 8;
  } while (lVar9 != 0x28);
  lVar9 = platform_get_resource(param_1,0x200,0);
  if (lVar9 == 0) {
    ipc_log_string(*puVar1,"Err getting IO region\n");
    if (*puVar11 == 0) {
      uVar7 = 0xffffffea;
    }
    else {
      i3c_trace_log(*puVar11,"Err getting IO region\n");
      uVar7 = 0xffffffea;
    }
LAB_001022a0:
    ipc_log_string(*puVar1,"Error:%d i3c_geni_rsrcs_init\n",uVar7 & 0xffffffff);
    uVar13 = *puVar11;
    if (uVar13 != 0) {
      pcVar10 = "Error:%d i3c_geni_rsrcs_init\n";
LAB_001022c8:
      i3c_trace_log(uVar13,pcVar10,uVar7 & 0xffffffff);
    }
  }
  else {
    uVar7 = devm_ioremap_resource(plVar8,lVar9);
    *puVar6 = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      uVar7 = *(ulong *)(param_1 + 0x70);
      puVar6[1] = (ulong)plVar8;
      uVar13 = *(ulong *)(uVar7 + 0x98);
      puVar6[0xa7f] = uVar7;
      puVar6[2] = uVar13;
      if (uVar13 == 0) {
        ipc_log_string(*puVar1,"SE Wrapper is NULL, deferring probe\n");
        if (*puVar11 == 0) {
          uVar7 = 0xfffffdfb;
        }
        else {
          i3c_trace_log(*puVar11,"SE Wrapper is NULL, deferring probe\n");
          uVar7 = 0xfffffdfb;
        }
      }
      else {
        iVar4 = device_property_read_u32_array(plVar8,"se-clock-frequency",puVar6 + 0xa4d,1);
        if (iVar4 != 0) {
          ipc_log_string(*puVar1,"SE clk freq not specified, default to 100 MHz.\n");
          if (*puVar11 != 0) {
            i3c_trace_log(*puVar11,"SE clk freq not specified, default to 100 MHz.\n");
          }
          *(undefined4 *)(puVar6 + 0xa4d) = 100000000;
        }
        uVar5 = geni_icc_get(puVar6,"qup-memory");
        if (uVar5 == 0) {
          uVar7 = puVar6[0x135];
          *(undefined4 *)(puVar6 + 7) = 50000;
          *(undefined4 *)(puVar6 + 9) = 1;
          *(undefined4 *)(puVar6 + 0xb) = 0x12c00;
          uVar5 = icc_set_bw(puVar6[6],500,50000);
          if (uVar5 == 0) {
            ipc_log_string(uVar7,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n","qup-core",
                           500,50000);
            uVar2 = (undefined4)puVar6[9];
            uVar5 = icc_set_bw(puVar6[8],uVar2,uVar2);
            if (uVar5 == 0) {
              ipc_log_string(uVar7,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n",
                             "qup-config",uVar2,uVar2);
              uVar2 = (undefined4)puVar6[0xb];
              uVar5 = icc_set_bw(puVar6[10],uVar2,uVar2);
              if (uVar5 == 0) {
                ipc_log_string(uVar7,"ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n",
                               "qup-memory",uVar2,uVar2);
                iVar4 = device_property_read_u32_array
                                  (plVar8,"dfs-index",(undefined4 *)((long)puVar6 + 0x526c),1);
                if (iVar4 != 0) {
                  *(undefined4 *)((long)puVar6 + 0x526c) = 0xf;
                }
                uVar7 = devm_pinctrl_get(plVar8);
                puVar6[0xa7b] = uVar7;
                if (uVar7 < 0xfffffffffffff001) {
                  uVar7 = pinctrl_lookup_state(uVar7,"default");
                  puVar6[0xa7c] = uVar7;
                  if (uVar7 < 0xfffffffffffff001) {
                    uVar7 = pinctrl_lookup_state(puVar6[0xa7b],"sleep");
                    puVar6[0xa7d] = uVar7;
                    if (uVar7 < 0xfffffffffffff001) {
                      uVar7 = pinctrl_lookup_state(puVar6[0xa7b],"disable");
                      puVar6[0xa73] = uVar7;
                      if (uVar7 < 0xfffffffffffff001) goto LAB_00101aec;
                      puVar12 = puVar6 + 0xa73;
                      ipc_log_string(*puVar1,"Error no pinctrl disable config specified\n");
                      uVar7 = *puVar11;
                      if (uVar7 != 0) {
                        pcVar10 = "Error no pinctrl disable config specified\n";
                        goto LAB_001020bc;
                      }
                    }
                    else {
                      puVar12 = puVar6 + 0xa7d;
                      ipc_log_string(*puVar1,"Error no pinctrl sleep config specified\n");
                      uVar7 = *puVar11;
                      if (uVar7 != 0) {
                        pcVar10 = "Error no pinctrl sleep config specified\n";
                        goto LAB_001020bc;
                      }
                    }
                  }
                  else {
                    puVar12 = puVar6 + 0xa7c;
                    ipc_log_string(*puVar1,"Error no pinctr default config specified\n");
                    uVar7 = *puVar11;
                    if (uVar7 != 0) {
                      pcVar10 = "Error no pinctr default config specified\n";
                      goto LAB_001020bc;
                    }
                  }
                }
                else {
                  puVar12 = puVar6 + 0xa7b;
                  ipc_log_string(*puVar1,"Error no pinctrl config specified\n");
                  uVar7 = *puVar11;
                  if (uVar7 != 0) {
                    pcVar10 = "Error no pinctrl config specified\n";
LAB_001020bc:
                    i3c_trace_log(uVar7,pcVar10);
                  }
                }
                uVar7 = *puVar12;
                if ((int)uVar7 == 0) goto LAB_00101aec;
                goto LAB_001022a0;
              }
              uVar7 = (ulong)uVar5;
              lVar9 = 2;
            }
            else {
              uVar7 = (ulong)uVar5;
              lVar9 = 1;
            }
          }
          else {
            uVar7 = (ulong)uVar5;
            lVar9 = 0;
          }
          iVar4 = ___ratelimit(geni_common_icc_set_bw__rs,"geni_common_icc_set_bw");
          if (iVar4 != 0) {
            _dev_err(*puVar11,"ICC BW voting failed on path \'%s\': %d\n",(&icc_path_names)[lVar9],
                     uVar7);
          }
          _dev_err(plVar8,"%s: icc set bw failed ret:%d\n","i3c_geni_rsrcs_init",uVar7);
        }
        else {
          uVar7 = (ulong)uVar5;
          ipc_log_string(*puVar1,"geni_se_common_resources_init Failed:%d\n",uVar7);
          if (*puVar11 != 0) {
            i3c_trace_log(*puVar11,"geni_se_common_resources_init Failed:%d\n",uVar7);
          }
        }
      }
      goto LAB_001022a0;
    }
    if ((int)uVar7 != 0) goto LAB_001022a0;
LAB_00101aec:
    uVar13 = puVar6[1];
    uVar7 = devm_clk_get(uVar13,"se-clk");
    puVar6[3] = uVar7;
    if (0xfffffffffffff000 < uVar7) {
      uVar7 = uVar7 & 0xffffffff;
      ipc_log_string(*puVar1,"Error getting SE Core clk %d\n",uVar7);
      if (*puVar11 == 0) {
        _printk(&DAT_0010cd50,uVar7);
      }
      else {
        _dev_err(*puVar11,"Error getting SE Core clk %d\n",uVar7);
      }
      uVar13 = *puVar11;
      if (uVar13 != 0) {
        pcVar10 = "Error getting SE Core clk %d\n";
LAB_00102340:
        i3c_trace_log(uVar13,pcVar10,uVar7);
      }
LAB_00102348:
      if ((int)uVar7 == 0) goto LAB_00101b44;
      ipc_log_string(*puVar1,"Error:%d i3c_geni_rsrcs_clk_init\n",uVar7);
      uVar13 = *puVar11;
      if (uVar13 == 0) goto LAB_001022d0;
      pcVar10 = "Error:%d i3c_geni_rsrcs_clk_init\n";
      goto LAB_001022c8;
    }
    uVar7 = devm_clk_get(*(undefined8 *)(uVar13 + 0x60),"m-ahb");
    puVar6[0xa79] = uVar7;
    if (0xfffffffffffff000 < uVar7) {
      uVar7 = uVar7 & 0xffffffff;
      ipc_log_string(*puVar1,"Error getting M AHB clk %d\n",uVar7);
      if (*puVar11 == 0) {
        _printk(&DAT_0010bb74,uVar7);
      }
      else {
        _dev_err(*puVar11,"Error getting M AHB clk %d\n",uVar7);
      }
      uVar13 = *puVar11;
      if (uVar13 != 0) {
        pcVar10 = "Error getting M AHB clk %d\n";
        goto LAB_00102340;
      }
      goto LAB_00102348;
    }
    uVar7 = devm_clk_get(*(undefined8 *)(uVar13 + 0x60),"s-ahb");
    puVar6[0xa7a] = uVar7;
    if (0xfffffffffffff000 < uVar7) {
      uVar7 = uVar7 & 0xffffffff;
      ipc_log_string(*puVar1,"Error getting S AHB clk %d\n",uVar7);
      if (*puVar11 == 0) {
        _printk(&DAT_0010bead,uVar7);
      }
      else {
        _dev_err(*puVar11,"Error getting S AHB clk %d\n",uVar7);
      }
      uVar13 = *puVar11;
      if (uVar13 != 0) {
        pcVar10 = "Error getting S AHB clk %d\n";
        goto LAB_00102340;
      }
      goto LAB_00102348;
    }
LAB_00101b44:
    uVar5 = platform_get_irq(param_1,0);
    *(uint *)((long)puVar6 + 100) = uVar5;
    if ((int)uVar5 < 0) {
      uVar7 = (ulong)uVar5;
      ipc_log_string(*puVar1,"IRQ error=%d for i3c-master-geni\n",uVar7);
      uVar13 = *puVar11;
      if (uVar13 != 0) {
        pcVar10 = "IRQ error=%d for i3c-master-geni\n";
        goto LAB_001022c8;
      }
    }
    else {
      *(undefined4 *)(puVar6 + 0x138) = 0;
      __init_swait_queue_head(puVar6 + 0x139,"&x->wait",&init_completion___key);
      __mutex_init(puVar6 + 0x13c,"&gi3c->lock",&geni_i3c_probe___key);
      __mutex_init(puVar6 + 0x142,"&gi3c->i3c_ibi_lock",&geni_i3c_probe___key_22);
      uVar2 = *(undefined4 *)((long)puVar6 + 100);
      *(ulong **)(param_1 + 0xa8) = puVar6;
      *(undefined4 *)((long)puVar6 + 0x5264) = 0;
      irq_modify_status(uVar2,0,0x1000);
      lVar9 = *(long *)(param_1 + 0x80);
      if (lVar9 == 0) {
        lVar9 = *plVar8;
      }
      uVar5 = devm_request_threaded_irq
                        (plVar8,*(undefined4 *)((long)puVar6 + 100),geni_i3c_irq,0,4,lVar9,puVar6);
      if (uVar5 == 0) {
        uVar5 = geni_icc_enable(puVar6);
        if (uVar5 == 0) {
          iVar4 = geni_se_resources_on(puVar6);
          if (iVar4 == 0) {
            uVar5 = readl_relaxed(*puVar6 + 0x68);
            uVar5 = uVar5 >> 8 & 0xff;
            if (uVar5 == 4) {
              geni_i3c_get_ver_info(puVar6);
              uVar14 = *(undefined8 *)(param_1 + 0x2f8);
              *(undefined4 *)(puVar6 + 0xa7e) = 4;
              lVar9 = of_find_property(uVar14,"qcom,shared",0);
              if (lVar9 != 0) {
                *(undefined1 *)(puVar6 + 0xa80) = 1;
                _dev_info(plVar8,"SE being used by two EEs.\n");
              }
              iVar4 = readl_relaxed(*puVar6 + 100);
              if ((iVar4 == 0) || (iVar4 = geni_i3c_gsi_se_init(puVar6), iVar4 == 0)) {
                ipc_log_string(*puVar1,"%s: i3c_ibi_rsrcs_init()\n","geni_i3c_probe");
                if (*puVar11 != 0) {
                  i3c_trace_log(*puVar11,"%s: i3c_ibi_rsrcs_init()\n","geni_i3c_probe");
                }
                iVar4 = i3c_ibi_rsrcs_init(puVar6,param_1);
                if (iVar4 == 0) {
                  if (*(int *)((long)puVar6 + 0x6c) == 3) {
                    ipc_log_string(*puVar1,"GSI mode, applying Force default\n");
                    if (*puVar11 != 0) {
                      i3c_trace_log(*puVar11,"GSI mode, applying Force default\n");
                    }
                    writel(1,*puVar6 + 0x20);
                    writel(0x7f,*puVar6 + 0x24);
                  }
                  else {
                    *(undefined1 *)(puVar6 + 0xa80) = 0;
                    iVar4 = geni_se_get_tx_fifo_depth(puVar6);
                    *(int *)(puVar6 + 0xc) = iVar4 + -1;
                    geni_se_init(puVar6,iVar4 + -1,iVar4);
                    geni_se_config_packing(puVar6,8,4,1,1,1);
                    ipc_log_string(puVar6[0x135],"i3c fifo/se-dma mode. fifo depth:%d mode=%d\n",
                                   iVar4,*(undefined4 *)((long)puVar6 + 0x6c));
                    if (puVar6[1] != 0) {
                      i3c_trace_log(puVar6[1],"i3c fifo/se-dma mode. fifo depth:%d mode=%d\n",iVar4,
                                    *(undefined4 *)((long)puVar6 + 0x6c));
                    }
                  }
                  uVar5 = readl_relaxed(*puVar6 + 0x908);
                  if (((uVar5 ^ 0xffffffff) & 3) != 0) {
                    ipc_log_string(*puVar1,"%s: IO lines:0x%x, Ensure bus power up\n",
                                   "geni_i3c_probe",uVar5);
                    if (*puVar11 != 0) {
                      i3c_trace_log(*puVar11,"%s: IO lines:0x%x, Ensure bus power up\n",
                                    "geni_i3c_probe",uVar5);
                    }
                  }
                  iVar4 = geni_se_resources_off(puVar6);
                  if (iVar4 != 0) {
                    ipc_log_string(*puVar1,"geni_se_resources_off failed %d\n",iVar4);
                    if (*puVar11 == 0) {
                      _printk(&DAT_0010c5c9,iVar4);
                    }
                    else {
                      _dev_err(*puVar11,"geni_se_resources_off failed %d\n",iVar4);
                    }
                    if (*puVar11 != 0) {
                      i3c_trace_log(*puVar11,"geni_se_resources_off failed %d\n",iVar4);
                    }
                  }
                  iVar4 = geni_icc_disable(puVar6);
                  if (iVar4 != 0) {
                    ipc_log_string(*puVar1,"geni_icc_disable failed %d\n",iVar4);
                    if (*puVar11 == 0) {
                      _printk(&DAT_0010b4e9,iVar4);
                    }
                    else {
                      _dev_err(*puVar11,"geni_icc_disable failed %d\n",iVar4);
                    }
                    if (*puVar11 != 0) {
                      i3c_trace_log(*puVar11,"geni_icc_disable failed %d\n",iVar4);
                    }
                  }
                  __pm_runtime_set_status(puVar6[1],2);
                  pm_runtime_set_autosuspend_delay(puVar6[1],0xfa);
                  __pm_runtime_use_autosuspend(puVar6[1],1);
                  pm_runtime_enable(puVar6[1]);
                  iVar4 = i3c_master_register(puVar6 + 0xe,plVar8,&geni_i3c_master_ops,0);
                  if (iVar4 != 0) {
                    ipc_log_string(*puVar1,"I3C master registration failed=%d, continue\n",iVar4);
                    if (*puVar11 == 0) {
                      _printk(&DAT_0010c46f,iVar4);
                    }
                    else {
                      _dev_err(*puVar11,"I3C master registration failed=%d, continue\n",iVar4);
                    }
                    if (*puVar11 != 0) {
                      i3c_trace_log(*puVar11,"I3C master registration failed=%d, continue\n",iVar4);
                    }
                  }
                  ipc_log_string(puVar6[0x135],"I3C bus freq:%ld, I2C bus freq:%ld\n",puVar6[0x126],
                                 puVar6[0x127]);
                  if (puVar6[1] != 0) {
                    i3c_trace_log(puVar6[1],"I3C bus freq:%ld, I2C bus freq:%ld\n",puVar6[0x126],
                                  puVar6[0x127]);
                  }
                  if ((*(int *)((long)puVar6 + 0x6c) == 3) &&
                     (iVar4 = geni_i3c_gsi_stop_on_bus(puVar6), iVar4 != 0)) {
                    ipc_log_string(*puVar1,"I3C gsi stop on bus failed\n");
                    if (*puVar11 == 0) {
                      uVar7 = 0xffffffea;
                    }
                    else {
                      i3c_trace_log(*puVar11,"I3C gsi stop on bus failed\n");
                      uVar7 = 0xffffffea;
                    }
                  }
                  else {
                    plVar8 = (long *)*puVar11;
                    lVar9 = plVar8[0xe];
                    if (lVar9 == 0) {
                      lVar9 = *plVar8;
                    }
                    uVar7 = wakeup_source_register(plVar8,lVar9);
                    puVar6[0xa72] = uVar7;
                    if (uVar7 == 0) {
                      ipc_log_string(*puVar1,"wakeup source registration failed\n");
                      if (*puVar11 != 0) {
                        i3c_trace_log(*puVar11,"wakeup source registration failed\n");
                      }
                      geni_se_resources_off(puVar6);
                      uVar7 = 0xfffffff4;
                    }
                    else {
                      puVar6[0xa6c] = 0xfffffffe0;
                      puVar6[0xa6d] = (ulong)(puVar6 + 0xa6d);
                      puVar6[0xa6e] = (ulong)(puVar6 + 0xa6d);
                      puVar6[0xa6f] = (ulong)geni_i3c_hotjoin;
                      lVar9 = ((long *)puVar6[1])[0xe];
                      if (lVar9 == 0) {
                        lVar9 = *(long *)puVar6[1];
                      }
                      uVar7 = alloc_workqueue(&DAT_0010bdc6,0x12,1,lVar9);
                      puVar6[0xa6b] = uVar7;
                      geni_i3c_enable_hotjoin_irq(puVar6,1);
                      device_create_file(puVar6[1],&dev_attr_capture_kpi);
                      ipc_log_string(puVar6[0x135],"I3C probed:%d\n",0);
                      if (puVar6[1] == 0) {
                        _printk(&DAT_0010ced4,0);
                      }
                      else {
                        _dev_err(puVar6[1],"I3C probed:%d\n",0);
                      }
                      if (*puVar11 != 0) {
                        i3c_trace_log(*puVar11,"I3C probed:%d\n",0);
                      }
                      uVar7 = 0;
                    }
                  }
                  goto LAB_001022f8;
                }
                ipc_log_string(*puVar1,"Error: %d, i3c_ibi_rsrcs_init\n",iVar4);
                if (*puVar11 != 0) {
                  i3c_trace_log(*puVar11,"Error: %d, i3c_ibi_rsrcs_init\n",iVar4);
                }
              }
            }
            else {
              ipc_log_string(*puVar1,"Invalid proto %d\n",uVar5);
              uVar7 = 0;
              if (*puVar11 != 0) {
                i3c_trace_log(*puVar11,"Invalid proto %d\n",uVar5);
                uVar7 = *puVar11;
              }
              _dev_err(uVar7,"Invalid proto %d\n",uVar5);
            }
            iVar4 = geni_se_resources_off(puVar6);
            if (iVar4 != 0) {
              ipc_log_string(*puVar1,"%s: geni_se_resources_off failed%d\n","geni_i3c_probe",iVar4);
              if (*puVar11 == 0) {
                _printk(&DAT_0010cee5,"geni_i3c_probe",iVar4);
              }
              else {
                _dev_err(*puVar11,"%s: geni_se_resources_off failed%d\n","geni_i3c_probe",iVar4);
              }
              if (*puVar11 != 0) {
                i3c_trace_log(*puVar11,"%s: geni_se_resources_off failed%d\n","geni_i3c_probe",iVar4
                             );
              }
            }
          }
          else {
            ipc_log_string(*puVar1,"Error turning on resources %d\n",iVar4);
            if (*puVar11 != 0) {
              i3c_trace_log(*puVar11,"Error turning on resources %d\n",iVar4);
            }
          }
          uVar13 = geni_icc_disable(puVar6);
          uVar7 = uVar13 & 0xffffffff;
          if ((int)uVar13 != 0) {
            ipc_log_string(*puVar1,"%s: geni_icc_disable failed%d\n","geni_i3c_probe",uVar7);
            if (*puVar11 == 0) {
              _printk(&DAT_0010b507,"geni_i3c_probe",uVar7);
            }
            else {
              _dev_err(*puVar11,"%s: geni_icc_disable failed%d\n","geni_i3c_probe",uVar7);
            }
            uVar13 = *puVar11;
            if (uVar13 != 0) {
              pcVar10 = "%s: geni_icc_disable failed%d\n";
              goto LAB_00101f60;
            }
          }
        }
        else {
          uVar7 = (ulong)uVar5;
          ipc_log_string(*puVar1,"%s geni_icc_enable failed %d\n","geni_i3c_probe",uVar7);
          uVar13 = *puVar11;
          if (uVar13 != 0) {
            pcVar10 = "%s geni_icc_enable failed %d\n";
LAB_00101f60:
            i3c_trace_log(uVar13,pcVar10,"geni_i3c_probe",uVar7);
          }
        }
      }
      else {
        uVar7 = (ulong)uVar5;
        ipc_log_string(puVar6[0x135],"i3c irq failed:%d: err:%d\n",
                       *(undefined4 *)((long)puVar6 + 100),uVar7);
        if (puVar6[1] != 0) {
          i3c_trace_log(puVar6[1],"i3c irq failed:%d: err:%d\n",*(undefined4 *)((long)puVar6 + 100),
                        uVar7);
        }
      }
    }
  }
LAB_001022d0:
  ipc_log_string(*puVar1,"I3C probe failed\n");
  if (*puVar11 != 0) {
    i3c_trace_log(*puVar11,"I3C probe failed\n");
  }
LAB_001022f8:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// geni_i3c_remove @ 00102960 size=196
// signature: undefined geni_i3c_remove(void)
// callers: []
//------------------------------------------------------------

undefined4 geni_i3c_remove(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xa8);
  geni_i3c_enable_hotjoin_irq(lVar3,0);
  destroy_workqueue(*(undefined8 *)(lVar3 + 0x5358));
  wakeup_source_unregister(*(undefined8 *)(lVar3 + 0x5390));
  if (*(char *)(lVar3 + 0x52b1) != '\0') {
    qcom_geni_i3c_ibi_unconf(lVar3);
  }
  pm_runtime_force_suspend(*(undefined8 *)(lVar3 + 8));
  iVar1 = pinctrl_select_state(*(undefined8 *)(lVar3 + 0x53d8),*(undefined8 *)(lVar3 + 0x5398));
  if (iVar1 != 0) {
    ipc_log_string(*(undefined8 *)(lVar3 + 0x9a8)," i3c: pinctrl_select_state failed\n");
    if (*(long *)(lVar3 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar3 + 8)," i3c: pinctrl_select_state failed\n");
    }
  }
  uVar2 = i3c_master_unregister(lVar3 + 0x70);
  if (*(long *)(lVar3 + 0x9a8) != 0) {
    ipc_log_context_destroy(*(long *)(lVar3 + 0x9a8));
  }
  if (*(long *)(lVar3 + 0x9b0) != 0) {
    ipc_log_context_destroy();
  }
  i3c_nos = 0;
  return uVar2;
}



//------------------------------------------------------------
// geni_i3c_irq @ 00102a28 size=1116
// signature: undefined geni_i3c_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_irq(undefined8 param_1,long *param_2)

{
  long lVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  
  lVar19 = param_2[0x136];
  if (lVar19 == 0) {
    uVar12 = 0xffffffffffffffea;
  }
  else if ((int)param_2[0x137] == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = sched_clock();
    ipc_log_string(lVar19,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_irq",uVar12,uVar12 / 1000);
  }
  uVar13 = _raw_spin_lock_irqsave((long)param_2 + 0x5264);
  uVar5 = readl_relaxed(*param_2 + 0x610);
  readl_relaxed(*param_2 + 0x614);
  uVar6 = readl_relaxed(*param_2 + 0x804);
  uVar7 = readl_relaxed(*param_2 + 0xc40);
  uVar8 = readl_relaxed(*param_2 + 0xd40);
  iVar9 = readl_relaxed(*param_2 + 600);
  if (((uVar5 & 0x3e2e) == 0) && ((uVar8 & 0x7e0) == 0)) {
    if (iVar9 == 0) {
      if ((((uVar5 & 0xc000000) == 0) || ((int)param_2[0xa50] != 1)) || (param_2[0xa4f] == 0)) {
        if ((((uVar5 >> 0x1e & 1) != 0) && ((int)param_2[0xa50] == 0)) &&
           ((param_2[0xa4f] != 0 && ((int)param_2[0xc] != 0)))) {
          iVar15 = *(int *)((long)param_2 + 0x5284);
          iVar16 = (int)param_2[0xa51];
          uVar6 = 0;
          do {
            if (iVar16 < iVar15) {
              lVar14 = (long)iVar16;
              lVar18 = param_2[0xa4f];
              lVar19 = lVar14 + 1;
              lVar17 = (long)iVar15;
              *(int *)(param_2 + 0xa51) = (int)lVar19;
              bVar2 = *(byte *)(lVar18 + lVar14);
              uVar11 = (uint)bVar2;
              if (lVar19 < lVar17) {
                lVar1 = lVar14 + 2;
                *(int *)(param_2 + 0xa51) = (int)lVar1;
                uVar3 = CONCAT11(*(undefined1 *)(lVar18 + lVar19),bVar2);
                uVar11 = (uint)uVar3;
                if (lVar1 < lVar17) {
                  lVar14 = lVar14 + 3;
                  *(int *)(param_2 + 0xa51) = (int)lVar14;
                  uVar4 = CONCAT12(*(undefined1 *)(lVar18 + lVar1),uVar3);
                  uVar11 = (uint)uVar4;
                  if (lVar14 < lVar17) {
                    *(int *)(param_2 + 0xa51) = iVar16 + 4;
                    uVar11 = CONCAT13(*(undefined1 *)(lVar18 + lVar14),uVar4);
                  }
                }
              }
            }
            else {
              uVar11 = 0;
            }
            writel_relaxed(uVar11,*param_2 + 0x700);
            iVar15 = *(int *)((long)param_2 + 0x5284);
            iVar16 = (int)param_2[0xa51];
            if (iVar16 == iVar15) goto LAB_00102b80;
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(param_2 + 0xc));
        }
      }
      else {
        uVar6 = uVar6 & 0x1ffffff;
joined_r0x00102bbc:
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          uVar10 = readl_relaxed(*param_2 + 0x780);
          iVar15 = *(int *)((long)param_2 + 0x5284);
          iVar16 = (int)param_2[0xa51];
          if (iVar16 < iVar15) {
            *(int *)(param_2 + 0xa51) = iVar16 + 1;
            *(char *)(param_2[0xa4f] + (long)iVar16) = (char)uVar10;
            iVar15 = *(int *)((long)param_2 + 0x5284);
            iVar16 = (int)param_2[0xa51];
            if (iVar16 < iVar15) {
              *(int *)(param_2 + 0xa51) = iVar16 + 1;
              *(char *)(param_2[0xa4f] + (long)iVar16) = (char)((uint)uVar10 >> 8);
              iVar15 = *(int *)((long)param_2 + 0x5284);
              iVar16 = (int)param_2[0xa51];
              if (iVar15 <= iVar16) goto LAB_00102c7c;
              *(int *)(param_2 + 0xa51) = iVar16 + 1;
              *(char *)(param_2[0xa4f] + (long)iVar16) = (char)((uint)uVar10 >> 0x10);
              iVar15 = *(int *)((long)param_2 + 0x5284);
              iVar16 = (int)param_2[0xa51];
              if (iVar16 < iVar15) {
                *(int *)(param_2 + 0xa51) = iVar16 + 1;
                *(char *)(param_2[0xa4f] + (long)iVar16) = (char)((uint)uVar10 >> 0x18);
                if ((int)param_2[0xa51] == *(int *)((long)param_2 + 0x5284)) break;
                goto joined_r0x00102bbc;
              }
            }
            if (iVar16 == iVar15) break;
            goto joined_r0x00102bbc;
          }
LAB_00102c7c:
        } while (iVar16 != iVar15);
      }
    }
    else {
      ipc_log_string(param_2[0x135],"i3c dma tx:0x%x, dma rx:0x%x\n",uVar7,uVar8);
      if (param_2[1] != 0) {
        i3c_trace_log(param_2[1],"i3c dma tx:0x%x, dma rx:0x%x\n",uVar7,uVar8);
      }
    }
  }
  else {
    geni_i3c_handle_err(param_2,uVar5);
    if (iVar9 == 0) {
LAB_00102b80:
      writel_relaxed(0,*param_2 + 0x80c);
    }
  }
  if (uVar5 != 0) {
    writel_relaxed(uVar5,*param_2 + 0x618);
  }
  if (iVar9 != 0) {
    if (uVar7 != 0) {
      writel_relaxed(uVar7,*param_2 + 0xc44);
    }
    if (uVar8 != 0) {
      writel_relaxed(uVar8,*param_2 + 0xd44);
    }
  }
  if ((uVar5 & 0x21) == 0) {
    if ((((uVar7 & 1) == 0) && ((uVar8 & 9) == 0)) && ((uVar7 >> 3 & 1) == 0)) goto LAB_00102d50;
    ipc_log_string(param_2[0x135],"%s: DMA mode xfer completed\n","geni_i3c_irq");
    if (param_2[1] != 0) {
      i3c_trace_log(param_2[1],"%s: DMA mode xfer completed\n","geni_i3c_irq");
    }
  }
  else {
    writel_relaxed(0,*param_2 + 0x80c);
  }
  complete(param_2 + 0x138);
LAB_00102d50:
  _raw_spin_unlock_irqrestore((long)param_2 + 0x5264,uVar13);
  lVar19 = param_2[0x136];
  if (((lVar19 != 0) && (uVar12 != 0)) && ((int)param_2[0x137] != 0)) {
    lVar14 = sched_clock();
    ipc_log_string(lVar19,"%s:took %llu nsec(%llu usec)\n","geni_i3c_irq",lVar14 - uVar12,
                   (lVar14 - uVar12) / 1000);
  }
  return 1;
}



//------------------------------------------------------------
// geni_i3c_get_ver_info @ 00102e84 size=276
// signature: undefined geni_i3c_get_ver_info(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

void geni_i3c_get_ver_info(long *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = geni_se_get_qup_hw_version();
  uVar2 = uVar3 >> 0x1c;
  uVar1 = uVar3 >> 0x10 & 0xfff;
  uVar4 = uVar3 & 0xffff;
  ipc_log_string(param_1[0x135],"%s hw_ver: 0x%x Major:%d Minor:%d step:%d\n",
                 "geni_i3c_get_ver_info",uVar3,uVar2,uVar1,uVar4);
  if (param_1[1] != 0) {
    i3c_trace_log(param_1[1],"%s hw_ver: 0x%x Major:%d Minor:%d step:%d\n","geni_i3c_get_ver_info",
                  uVar3,uVar2,uVar1,uVar4);
  }
  *(uint *)(param_1 + 0xa74) = uVar2;
  *(uint *)((long)param_1 + 0x53a4) = uVar1;
  *(uint *)(param_1 + 0xa75) = uVar4;
  uVar4 = readl_relaxed(*param_1 + 0x68);
  *(uint *)((long)param_1 + 0x53ac) = uVar4 & 0xff;
  uVar4 = readl_relaxed(*param_1 + 0x6c);
  *(uint *)(param_1 + 0xa76) = uVar4 & 0xff;
  ipc_log_string(param_1[0x135],"%s:FW Ver:0x%x%x\n","geni_i3c_get_ver_info",
                 *(undefined4 *)((long)param_1 + 0x53ac));
  if (param_1[1] != 0) {
    i3c_trace_log(param_1[1],"%s:FW Ver:0x%x%x\n","geni_i3c_get_ver_info",
                  *(undefined4 *)((long)param_1 + 0x53ac),(int)param_1[0xa76]);
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_gsi_se_init @ 00102f98 size=392
// signature: undefined geni_i3c_gsi_se_init(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

undefined8 geni_i3c_gsi_se_init(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  char *pcVar3;
  
  *(undefined4 *)(param_1 + 0x6c) = 3;
  geni_se_select_mode(param_1,3);
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"I3C in GSI ONLY mode\n");
  uVar1 = 0;
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"I3C in GSI ONLY mode\n");
    uVar1 = *(undefined8 *)(param_1 + 8);
  }
  lVar2 = devm_kmalloc(uVar1,0xa0,0xdc0);
  *(long *)(param_1 + 0xaa0) = lVar2;
  if (lVar2 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"could not allocate for tx_sg\n");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010c4a4);
      lVar2 = *(long *)(param_1 + 8);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"could not allocate for tx_sg\n");
      lVar2 = *(long *)(param_1 + 8);
    }
    if (lVar2 == 0) {
      return 0xfffffff4;
    }
    pcVar3 = "could not allocate for tx_sg\n";
  }
  else {
    lVar2 = devm_kmalloc(*(undefined8 *)(param_1 + 8),0x20,0xdc0);
    *(long *)(param_1 + 0x2e88) = lVar2;
    if (lVar2 != 0) {
      *(long *)(param_1 + 0xa58) = param_1;
      *(undefined1 *)(param_1 + 0xa40) = 4;
      *(undefined8 *)(param_1 + 0x5230) = *(undefined8 *)(param_1 + 0x9a8);
      *(undefined8 *)(param_1 + 0xa50) = *(undefined8 *)(param_1 + 8);
      *(long *)(param_1 + 0xa48) = param_1 + 0x9c0;
      *(code **)(param_1 + 0x2e40) = gi3c_gsi_tx_cb;
      *(code **)(param_1 + 0x5250) = gi3c_ev_cb;
      *(code **)(param_1 + 0x5228) = gi3c_gsi_rx_cb;
      *(long *)(param_1 + 0x5248) = param_1 + 0x68;
      *(long *)(param_1 + 0x5240) = param_1 + 0x5260;
      return 0;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"could not allocate for rx_sg\n");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010cb97);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"could not allocate for rx_sg\n");
    }
    lVar2 = *(long *)(param_1 + 8);
    if (lVar2 == 0) {
      return 0xfffffff4;
    }
    pcVar3 = "could not allocate for rx_sg\n";
  }
  i3c_trace_log(lVar2,pcVar3);
  return 0xfffffff4;
}



//------------------------------------------------------------
// i3c_ibi_rsrcs_init @ 00103120 size=1304
// signature: undefined i3c_ibi_rsrcs_init(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

ulong i3c_ibi_rsrcs_init(long *param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_2 + 0x2f8),"qcom,ibi-ctrl-id",
                     (undefined4 *)((long)param_1 + 0x532c),1,0);
  if (iVar2 < 0) {
    ipc_log_string(param_1[0x135],"IBI controller instance id is not defined\n");
    if (param_1[1] == 0) {
      _printk(&DAT_0010c238);
      lVar4 = param_1[1];
    }
    else {
      _dev_err(param_1[1],"IBI controller instance id is not defined\n");
      lVar4 = param_1[1];
    }
    if (lVar4 == 0) {
      uVar5 = 0xfffffffa;
    }
    else {
      i3c_trace_log(lVar4,"IBI controller instance id is not defined\n");
      uVar5 = 0xfffffffa;
    }
    goto LAB_00103594;
  }
  plVar1 = (long *)(param_2 + 0x10);
  lVar4 = of_find_property(*(undefined8 *)(param_2 + 0x2f8),"qcom,ibic-naon",0);
  if (lVar4 == 0) {
LAB_0010318c:
    msm_qup_write(*(undefined4 *)((long)param_1 + 0x532c),0x24);
    lVar4 = platform_get_resource(param_2,0x200,1);
    if (lVar4 != 0) {
      uVar5 = devm_ioremap_resource(plVar1,lVar4);
      param_1[0xa57] = uVar5;
      if (0xfffffffffffff000 < uVar5) goto LAB_00103594;
      uVar3 = readl_relaxed(*param_1 + 0xe24);
      *(byte *)(param_1 + 0xa56) = (byte)(uVar3 >> 7) & 1;
      if ((uVar3 >> 7 & 1) == 0) {
        ipc_log_string(param_1[0x135],"IBI controller support not present\n");
        if (param_1[1] == 0) {
          _printk(&DAT_0010c0ff);
        }
        else {
          _dev_err(param_1[1],"IBI controller support not present\n");
        }
        if (param_1[1] != 0) {
          i3c_trace_log(param_1[1],"IBI controller support not present\n");
        }
        uVar5 = 0xffffffed;
        goto LAB_00103594;
      }
      *(undefined4 *)(param_1 + 0xa5b) = 0;
      __init_swait_queue_head(param_1 + 0xa5c,"&x->wait",&init_completion___key);
      *(undefined4 *)(param_1 + 0xa5a) = 0;
      uVar3 = readl_relaxed(param_1[0xa57] + 0x1c);
      *(uint *)(param_1 + 0xa58) = uVar3 & 0x1f;
      if ((uVar3 & 0x1f) != 0) {
        lVar4 = devm_kmalloc(plVar1,(uVar3 & 0x1f) << 3,0xdc0);
        param_1[0xa59] = lVar4;
        if (lVar4 == 0) {
          uVar5 = 0xfffffff4;
        }
        else {
          lVar4 = of_find_property(*(undefined8 *)(param_2 + 0x2f8),"qcom,ibic-naon",0);
          if (lVar4 != 0) {
            *(undefined1 *)((long)param_1 + 0x533c) = 1;
            _dev_info(plVar1,"IBI is NAON controller\n");
            iVar2 = i3c_naon_ibi_clk_init(param_1);
            if (iVar2 != 0) {
              ipc_log_string(param_1[0x135],"NAON IBI clock failed to init:%d\n",iVar2);
              if (param_1[1] == 0) {
                _printk(&DAT_0010bff3,iVar2);
              }
              else {
                _dev_err(param_1[1],"NAON IBI clock failed to init:%d\n",iVar2);
              }
              if (param_1[1] != 0) {
                i3c_trace_log(param_1[1],"NAON IBI clock failed to init:%d\n",iVar2);
              }
            }
          }
          iVar2 = platform_get_irq(param_2,1);
          *(int *)((long)param_1 + 0x52d4) = iVar2;
          if (iVar2 < 0) {
            ipc_log_string(param_1[0x135],"IRQ error for ibi_c manager\n");
            if (param_1[1] != 0) {
              i3c_trace_log(param_1[1],"IRQ error for ibi_c manager\n");
            }
            uVar5 = (ulong)*(uint *)((long)param_1 + 0x52d4);
          }
          else {
            lVar4 = *(long *)(param_2 + 0x80);
            if (lVar4 == 0) {
              lVar4 = *plVar1;
            }
            uVar3 = devm_request_threaded_irq(plVar1,iVar2,geni_i3c_ibi_irq,0,4,lVar4,param_1);
            if (uVar3 == 0) {
              if ((*(char *)((long)param_1 + 0x533c) == '\0') &&
                 (uVar3 = irq_set_irq_wake(*(undefined4 *)((long)param_1 + 0x52d4),1), uVar3 != 0))
              {
                uVar5 = (ulong)uVar3;
                ipc_log_string(param_1[0x135],"Failed to set mngr IRQ(%d) wake: err:%d\n",
                               *(undefined4 *)((long)param_1 + 0x52d4),uVar5);
                lVar4 = param_1[1];
                if (lVar4 == 0) goto LAB_00103594;
                uVar7 = *(undefined4 *)((long)param_1 + 0x52d4);
                pcVar6 = "Failed to set mngr IRQ(%d) wake: err:%d\n";
              }
              else {
                iVar2 = platform_get_irq(param_2,2);
                *(int *)(param_1 + 0xa5f) = iVar2;
                if (iVar2 < 0) {
                  ipc_log_string(param_1[0x135],"IRQ error for ibi_c gpii\n");
                  if (param_1[1] != 0) {
                    i3c_trace_log(param_1[1],"IRQ error for ibi_c gpii\n");
                  }
                  uVar5 = (ulong)*(uint *)(param_1 + 0xa5f);
                  goto LAB_00103594;
                }
                lVar4 = *(long *)(param_2 + 0x80);
                if (lVar4 == 0) {
                  lVar4 = *plVar1;
                }
                uVar3 = devm_request_threaded_irq(plVar1,iVar2,geni_i3c_ibi_irq,0,4,lVar4,param_1);
                if (uVar3 == 0) {
                  if ((*(char *)((long)param_1 + 0x533c) != '\0') ||
                     (uVar3 = irq_set_irq_wake((int)param_1[0xa5f],1), uVar3 == 0)) {
                    qcom_geni_i3c_ibi_conf(param_1);
                    uVar5 = 0;
                    goto LAB_00103594;
                  }
                  uVar5 = (ulong)uVar3;
                  ipc_log_string(param_1[0x135],"Failed to set gpii IRQ(%d) wake: err:%d\n",
                                 (int)param_1[0xa5f],uVar5);
                  lVar4 = param_1[1];
                  if (lVar4 == 0) goto LAB_00103594;
                  uVar7 = (undefined4)param_1[0xa5f];
                  pcVar6 = "Failed to set gpii IRQ(%d) wake: err:%d\n";
                }
                else {
                  uVar5 = (ulong)uVar3;
                  ipc_log_string(param_1[0x135],"Request_irq failed:%d: err:%d\n",
                                 (int)param_1[0xa5f],uVar5);
                  lVar4 = param_1[1];
                  if (lVar4 == 0) goto LAB_00103594;
                  uVar7 = (undefined4)param_1[0xa5f];
                  pcVar6 = "Request_irq failed:%d: err:%d\n";
                }
              }
            }
            else {
              uVar5 = (ulong)uVar3;
              ipc_log_string(param_1[0x135],"Request_irq:%d: err:%d\n",
                             *(undefined4 *)((long)param_1 + 0x52d4),uVar5);
              lVar4 = param_1[1];
              if (lVar4 == 0) goto LAB_00103594;
              uVar7 = *(undefined4 *)((long)param_1 + 0x52d4);
              pcVar6 = "Request_irq:%d: err:%d\n";
            }
            i3c_trace_log(lVar4,pcVar6,uVar7,uVar5);
          }
        }
        goto LAB_00103594;
      }
      ipc_log_string(param_1[0x135],"Invalid num_slots:%d\n",0);
      if (param_1[1] == 0) {
        _printk(&DAT_0010ba88,(int)param_1[0xa58]);
      }
      else {
        _dev_err(param_1[1],"Invalid num_slots:%d\n");
      }
      if (param_1[1] != 0) {
        i3c_trace_log(param_1[1],"Invalid num_slots:%d\n",(int)param_1[0xa58]);
      }
    }
  }
  else {
    *(undefined1 *)((long)param_1 + 0x533c) = 1;
    _dev_info(plVar1,"%s:I3C IBI is NAON cntrl\n","i3c_ibi_rsrcs_init");
    iVar2 = i3c_naon_ibi_clk_init(param_1);
    if ((iVar2 == 0) && (iVar2 = geni_i3c_enable_naon_ibi_clks(param_1,1), iVar2 == 0))
    goto LAB_0010318c;
  }
  uVar5 = 0xffffffea;
LAB_00103594:
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// writel @ 00103638 size=136
// signature: undefined writel(void)
// callers: [geni_i3c_probe, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103650,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103690,uVar1);
  return;
}



//------------------------------------------------------------
// geni_se_get_tx_fifo_depth @ 001036c0 size=96
// signature: undefined geni_se_get_tx_fifo_depth(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

uint geni_se_get_tx_fifo_depth(long *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = geni_se_get_qup_hw_version();
  uVar2 = 0xff0000;
  if (((uVar1 & 0xffe0000) < 0x90001 || uVar1 >> 0x1c != 3) && (uVar1 & 0xc0000000) == 0) {
    uVar2 = 0x3f0000;
  }
  uVar1 = readl_relaxed(*param_1 + 0xe24);
  return (uVar2 & uVar1) >> 0x10;
}



//------------------------------------------------------------
// geni_i3c_gsi_stop_on_bus @ 00103720 size=432
// signature: undefined geni_i3c_gsi_stop_on_bus(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_priv_xfers, geni_i3c_runtime_suspend, geni_i3c_probe]
//------------------------------------------------------------

int geni_i3c_gsi_stop_on_bus(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x53a0) < 4) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined1 *)(param_1 + 0xb18) = 0;
    *(undefined4 *)(param_1 + 0x9c0) = 0;
    *(undefined1 *)(param_1 + 0x5260) = 0;
    *(undefined8 *)(param_1 + 0xad8) = 7;
    *(undefined8 *)(param_1 + 0xae0) = 0x20020000000000;
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                   "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                   "geni_i3c_gsi_stop_on_bus",7,0,0,0x200200);
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),
                    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                    "geni_i3c_gsi_stop_on_bus",*(undefined4 *)(param_1 + 0xad8),
                    *(undefined4 *)(param_1 + 0xadc),*(undefined4 *)(param_1 + 0xae0),
                    *(undefined4 *)(param_1 + 0xae4));
    }
    *(byte *)(param_1 + 0xb18) = *(byte *)(param_1 + 0xb18) | 4;
    uVar1 = gsi_common_fill_tre_buf(param_1 + 0xa40,1);
    iVar2 = gsi_common_prep_desc_and_submit(param_1 + 0xa40,uVar1,1,0);
    if (iVar2 < 0) {
      *(int *)(param_1 + 0x68) = iVar2;
    }
    iVar3 = wait_for_completion_timeout(param_1 + 0x9c0,0xfa);
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:wait_for_completion timed out\n",
                     "geni_i3c_gsi_stop_on_bus");
      if (*(long *)(param_1 + 8) != 0) {
        i3c_trace_log(*(long *)(param_1 + 8),"%s:wait_for_completion timed out\n",
                      "geni_i3c_gsi_stop_on_bus");
      }
      geni_i3c_err(param_1,9);
      *(undefined4 *)(param_1 + 0x9c0) = 0;
      *(undefined8 *)(param_1 + 0x5278) = 0;
      *(undefined8 *)(param_1 + 0x5280) = 0;
      *(undefined4 *)(param_1 + 0x5288) = 0;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: ret:%d\n","geni_i3c_gsi_stop_on_bus",iVar2)
    ;
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s: ret:%d\n","geni_i3c_gsi_stop_on_bus",iVar2);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// geni_i3c_hotjoin @ 001038d4 size=384
// signature: undefined geni_i3c_hotjoin(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_hotjoin(long param_1)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + -0x49b0);
  if (lVar5 == 0) {
    uVar3 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + -0x49a8) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_hotjoin",uVar3,uVar3 / 1000)
    ;
  }
  plVar1 = (long *)(param_1 + -0x5358);
  pm_stay_awake(*plVar1);
  iVar2 = i3c_master_do_daa(param_1 + -0x52f0);
  if (iVar2 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + -0x49b8),"hotjoin:daa failed %d\n",iVar2);
    if (*plVar1 == 0) {
      _printk(&DAT_0010d64e,iVar2);
    }
    else {
      _dev_err(*plVar1,"hotjoin:daa failed %d\n",iVar2);
    }
    if (*plVar1 != 0) {
      i3c_trace_log(*plVar1,"hotjoin:daa failed %d\n",iVar2);
    }
  }
  pm_relax(*plVar1);
  lVar5 = *(long *)(param_1 + -0x49b0);
  if (((lVar5 != 0) && (uVar3 != 0)) && (*(int *)(param_1 + -0x49a8) != 0)) {
    lVar4 = sched_clock();
    ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","geni_i3c_hotjoin",lVar4 - uVar3,
                   (lVar4 - uVar3) / 1000);
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_enable_hotjoin_irq @ 00103a54 size=232
// signature: undefined geni_i3c_enable_hotjoin_irq(void)
// callers: [geni_i3c_remove, geni_i3c_probe]
//------------------------------------------------------------

void geni_i3c_enable_hotjoin_irq(long param_1,ulong param_2)

{
  char *pcVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x52b8) + 0x14);
  bVar2 = (param_2 & 1) == 0;
  pcVar1 = "Enabled";
  if (bVar2) {
    pcVar1 = "Disabled";
  }
  uVar5 = 4;
  if (bVar2) {
    uVar5 = 0;
  }
  writel_relaxed(uVar3 & 0xfffffffb | uVar5,*(long *)(param_1 + 0x52b8) + 0x14);
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:%s\n","geni_i3c_enable_hotjoin_irq",pcVar1);
  if (*(long *)(param_1 + 8) == 0) {
    _printk(&DAT_0010d667,"geni_i3c_enable_hotjoin_irq",pcVar1);
    lVar4 = *(long *)(param_1 + 8);
  }
  else {
    _dev_err(*(long *)(param_1 + 8),"%s:%s\n","geni_i3c_enable_hotjoin_irq",pcVar1);
    lVar4 = *(long *)(param_1 + 8);
  }
  if (lVar4 != 0) {
    i3c_trace_log(lVar4,"%s:%s\n","geni_i3c_enable_hotjoin_irq",pcVar1);
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_handle_err @ 00103b3c size=220
// signature: undefined geni_i3c_handle_err(void)
// callers: [gi3c_ev_cb, geni_i3c_irq]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void geni_i3c_handle_err(undefined8 param_1,uint param_2)

{
  if ((param_2 >> 9 & 1) != 0) {
    geni_i3c_err(param_1,0);
  }
  if ((param_2 >> 10 & 1) != 0) {
    geni_i3c_err(param_1,1);
  }
  if ((param_2 >> 0xb & 1) != 0) {
    geni_i3c_err(param_1,2);
  }
  if ((param_2 >> 0xc & 1) != 0) {
    geni_i3c_err(param_1,3);
  }
  if ((param_2 >> 0xd & 1) != 0) {
    geni_i3c_err(param_1,4);
  }
  if ((param_2 >> 0xe & 1) != 0) {
    geni_i3c_err(param_1,5);
  }
  if ((param_2 >> 1 & 1) != 0) {
    geni_i3c_err(param_1,6);
  }
  if ((param_2 >> 2 & 1) != 0) {
    geni_i3c_err(param_1,7);
  }
  if ((param_2 >> 5 & 1) != 0) {
    geni_i3c_err(param_1,8);
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00103c18 size=132
// signature: undefined writel_relaxed(void)
// callers: [qcom_geni_i3c_conf, geni_i3c_dump_dbg_regs, qcom_geni_i3c_ibi_unconf, geni_i3c_ibi_irq, geni_i3c_enable_hotjoin_irq, geni_i3c_enable_ibi_ctrl, geni_i3c_runtime_resume, geni_i3c_irq, geni_i3c_master_request_ibi, geni_i3c_master_bus_init, qcom_geni_i3c_ibi_conf, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103c30,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103c6c,uVar1);
  return;
}



//------------------------------------------------------------
// geni_i3c_err @ 00103c9c size=284
// signature: undefined geni_i3c_err(void)
// callers: [i3c_geni_execute_read_command, gi3c_gsi_cb_err, geni_i3c_handle_err, geni_i3c_master_priv_xfers, geni_i3c_gsi_stop_on_bus, i3c_geni_execute_write_command, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

void geni_i3c_err(long param_1,uint param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  long lVar3;
  char *pcVar4;
  undefined *puVar5;
  ulong uVar6;
  
  if (*(int *)(param_1 + 0x5280) == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:Error: Write, len:%d\n","geni_i3c_err",
                   *(undefined4 *)(param_1 + 0x5284));
    lVar3 = *(long *)(param_1 + 8);
    if (lVar3 == 0) goto LAB_00103d30;
    uVar1 = *(undefined4 *)(param_1 + 0x5284);
    pcVar4 = "%s:Error: Write, len:%d\n";
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:Error: Read, len:%d\n","geni_i3c_err",
                   *(undefined4 *)(param_1 + 0x5284));
    lVar3 = *(long *)(param_1 + 8);
    if (lVar3 == 0) goto LAB_00103d30;
    uVar1 = *(undefined4 *)(param_1 + 0x5284);
    pcVar4 = "%s:Error: Read, len:%d\n";
  }
  i3c_trace_log(lVar3,pcVar4,"geni_i3c_err",uVar1);
LAB_00103d30:
  uVar6 = (ulong)param_2;
  if ((uVar6 << 4 | 8) < 0xa1) {
    puVar5 = (&PTR_s_I3C_slave_early_read_termination_0010afc0)[uVar6 * 2];
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),&DAT_0010cd70,puVar5);
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),&DAT_0010cd70,puVar5);
    }
    if (param_2 < 10) {
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(&gi3c_log + uVar6 * 0x10);
      geni_i3c_dump_dbg_regs(param_1);
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x103db8);
  (*pcVar2)();
}



//------------------------------------------------------------
// geni_i3c_dump_dbg_regs @ 00103db8 size=528
// signature: undefined geni_i3c_dump_dbg_regs(void)
// callers: [geni_i3c_err, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

void geni_i3c_dump_dbg_regs(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  geni_i3c_se_dump_dbg_regs(param_1,*param_1,param_1[0x135]);
  if ((*(char *)(param_1 + 0xa56) != '\0') || (*(char *)((long)param_1 + 0x52b1) != '\0')) {
    uVar1 = readl_relaxed(param_1[0xa57]);
    uVar2 = readl_relaxed(param_1[0xa57] + 0xc);
    uVar3 = readl_relaxed(param_1[0xa57] + 0x10);
    uVar4 = readl_relaxed(param_1[0xa57] + 0x28);
    uVar5 = readl_relaxed(param_1[0xa57] + 0x2c);
    uVar6 = readl_relaxed(param_1[0xa57] + 0x1004);
    ipc_log_string(param_1[0x135],"ibi_gen_config:0x%x, gpii_ibi_en:0x%x, ibi_gen_irq_status:0x%x\n"
                   ,uVar1,uVar2,uVar3);
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"ibi_gen_config:0x%x, gpii_ibi_en:0x%x, ibi_gen_irq_status:0x%x\n",
                    uVar1,uVar2,uVar3);
    }
    ipc_log_string(param_1[0x135],
                   "ibi_unexpect_ibi_info:0x%x, ibi_legacy_mode:0x%x, ibi_irq_status_0:0x%x\n",uVar4
                   ,uVar5,uVar6);
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],
                    "ibi_unexpect_ibi_info:0x%x, ibi_legacy_mode:0x%x, ibi_irq_status_0:0x%x\n",
                    uVar4,uVar5,uVar6);
    }
  }
  if ((*(char *)(param_1 + 0xa56) != '\0') || (*(char *)((long)param_1 + 0x52b1) != '\0')) {
    writel_relaxed(0x11,param_1[0xa57] + 0x104);
    writel_relaxed(0,param_1[0xa57] + 0x100);
    uVar1 = readl_relaxed(param_1[0xa57] + 0x104);
    uVar2 = readl_relaxed(param_1[0xa57] + 0x100);
    ipc_log_string(param_1[0x135],"ibi_test_bus_en:0x%x, ibi_test_bus_sel:0x%x\n",uVar1,uVar2);
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"ibi_test_bus_en:0x%x, ibi_test_bus_sel:0x%x\n",uVar1,uVar2);
    }
    uVar1 = readl_relaxed(param_1[0xa57] + 0x108);
    ipc_log_string(param_1[0x135],"ibi_test_bus_reg:0x%x\n",uVar1);
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"ibi_test_bus_reg:0x%x\n",uVar1);
    }
  }
  if ((*(int *)((long)param_1 + 0x6c) == 3) && (param_1[0x153] != 0)) {
    gpi_dump_for_geni();
  }
  return;
}



//------------------------------------------------------------
// gi3c_gsi_tx_cb @ 00103fcc size=204
// signature: undefined gi3c_gsi_tx_cb(void)
// callers: []
//------------------------------------------------------------

void gi3c_gsi_tx_cb(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x20) == 0)) {
    _printk(&DAT_0010bed8,"gi3c_gsi_tx_cb");
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x20) + 0x18);
    gi3c_gsi_cb_err(param_1,&DAT_0010ca0b);
    piVar1 = (int *)(lVar4 + 0x2e30);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s rnw:%d irq_cnt:%d\n","gi3c_gsi_tx_cb",
                   *(undefined4 *)(lVar4 + 0x5280),*(undefined4 *)(lVar4 + 0x2e30));
    if (*(long *)(lVar4 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar4 + 8),"%s rnw:%d irq_cnt:%d\n","gi3c_gsi_tx_cb",
                    *(undefined4 *)(lVar4 + 0x5280),*(undefined4 *)(lVar4 + 0x2e30));
    }
    complete_all(lVar4 + 0x9c0);
  }
  return;
}



//------------------------------------------------------------
// gi3c_gsi_rx_cb @ 001040ac size=240
// signature: undefined gi3c_gsi_rx_cb(void)
// callers: []
//------------------------------------------------------------

void gi3c_gsi_rx_cb(long param_1)

{
  byte *pbVar1;
  long lVar2;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x20) == 0)) {
    _printk(&DAT_0010c5fb,"gi3c_gsi_rx_cb");
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x20) + 0x18);
    pbVar1 = (byte *)(lVar2 + 0x5280);
    ipc_log_string(*(undefined8 *)(lVar2 + 0x9a8),"%s rnw:%d\n","gi3c_gsi_rx_cb",
                   *(undefined4 *)pbVar1);
    if (*(long *)(lVar2 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar2 + 8),"%s rnw:%d\n","gi3c_gsi_rx_cb",*(undefined4 *)pbVar1);
    }
    if ((*pbVar1 & 1) == 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x9a8),"%s:Unexpected gsi rx cb\n","gi3c_gsi_rx_cb");
      if (*(long *)(lVar2 + 8) != 0) {
        i3c_trace_log(*(long *)(lVar2 + 8),"%s:Unexpected gsi rx cb\n","gi3c_gsi_rx_cb");
      }
    }
    else {
      gi3c_gsi_cb_err(param_1,&DAT_0010c4c4);
      complete_all(lVar2 + 0x9c0);
    }
  }
  return;
}



//------------------------------------------------------------
// gi3c_ev_cb @ 001041a0 size=212
// signature: undefined gi3c_ev_cb(void)
// callers: []
//------------------------------------------------------------

void gi3c_ev_cb(undefined8 param_1,int *param_2,long param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_3 + 0x18);
  ipc_log_string(*(undefined8 *)(lVar1 + 0x9a8),"%s cb_str->cb_event=0x%x\n","gi3c_ev_cb",*param_2);
  if (*(long *)(lVar1 + 8) != 0) {
    i3c_trace_log(*(long *)(lVar1 + 8),"%s cb_str->cb_event=0x%x\n","gi3c_ev_cb",*param_2);
  }
  if (*param_2 == 0) {
    geni_i3c_handle_err(lVar1,param_2[2]);
    complete_all(lVar1 + 0x9c0);
    if (*param_2 == 0) {
      return;
    }
  }
  ipc_log_string(*(undefined8 *)(lVar1 + 0x9a8),"GSI QN err:0x%x, status:0x%x, err:%d\n",param_2[10]
                 ,*(undefined8 *)(param_2 + 2));
  if (*(long *)(lVar1 + 8) != 0) {
    i3c_trace_log(*(long *)(lVar1 + 8),"GSI QN err:0x%x, status:0x%x, err:%d\n",param_2[10],
                  *(undefined8 *)(param_2 + 2),*param_2);
  }
  *(undefined1 *)(lVar1 + 0x5260) = 1;
  complete_all(lVar1 + 0x9c0);
  return;
}



//------------------------------------------------------------
// gi3c_gsi_cb_err @ 00104274 size=260
// signature: undefined gi3c_gsi_cb_err(void)
// callers: [gi3c_gsi_rx_cb, gi3c_gsi_tx_cb]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void gi3c_gsi_cb_err(long param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  
  if ((*(uint *)(param_1 + 8) & 0x7e0) != 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x20) + 0x18);
    ipc_log_string(*(undefined8 *)(lVar2 + 0x9a8),"%s TCE Unexpected Err, stat:0x%x\n",param_2);
    if (*(long *)(lVar2 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar2 + 8),"%s TCE Unexpected Err, stat:0x%x\n",param_2,
                    *(undefined4 *)(param_1 + 8));
    }
    uVar1 = *(uint *)(param_1 + 8);
    if ((uVar1 >> 5 & 1) != 0) {
      geni_i3c_err(lVar2,0);
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 6 & 1) != 0) {
      geni_i3c_err(lVar2,1);
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 7 & 1) != 0) {
      geni_i3c_err(lVar2,2);
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 8 & 1) != 0) {
      geni_i3c_err(lVar2,3);
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 9 & 1) != 0) {
      geni_i3c_err(lVar2,4);
      uVar1 = *(uint *)(param_1 + 8);
    }
    if ((uVar1 >> 10 & 1) != 0) {
      geni_i3c_err(lVar2,5);
    }
  }
  return;
}



//------------------------------------------------------------
// i3c_naon_ibi_clk_init @ 00104378 size=560
// signature: undefined i3c_naon_ibi_clk_init(void)
// callers: [i3c_ibi_rsrcs_init]
//------------------------------------------------------------

ulong i3c_naon_ibi_clk_init(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  char *pcVar4;
  
  if (*(char *)(param_1 + 0x533c) == '\0') {
    uVar1 = 0;
    goto LAB_00104440;
  }
  uVar1 = devm_clk_get(*(undefined8 *)(param_1 + 8),"ibic-core-clk");
  *(ulong *)(param_1 + 0x5340) = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = clk_set_rate(uVar1,37500000);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:Error Setting the clock rate: %d\n",
                     "i3c_naon_ibi_clk_init",uVar1);
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010cc9c,"i3c_naon_ibi_clk_init",uVar1);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"%s:Error Setting the clock rate: %d\n",
                 "i3c_naon_ibi_clk_init",uVar1);
      }
      if (*(long *)(param_1 + 8) != 0) {
        i3c_trace_log(*(long *)(param_1 + 8),"%s:Error Setting the clock rate: %d\n",
                      "i3c_naon_ibi_clk_init",uVar1);
      }
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 8),"ibic-ahb-clk");
    *(ulong *)(param_1 + 0x5348) = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 8),"ibic-src-clk");
      *(ulong *)(param_1 + 0x5350) = uVar2;
      if (uVar2 < 0xfffffffffffff001) goto LAB_00104440;
      uVar1 = uVar2 & 0xffffffff;
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"Error getting NAON src clk %d\n",uVar1);
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010c2bd,uVar1);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"Error getting NAON src clk %d\n",uVar1);
      }
      lVar3 = *(long *)(param_1 + 8);
      if (lVar3 == 0) goto LAB_00104440;
      pcVar4 = "Error getting NAON src clk %d\n";
    }
    else {
      uVar1 = uVar2 & 0xffffffff;
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"Error getting NAON AHB clk %d\n",uVar1);
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010d916,uVar1);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"Error getting NAON AHB clk %d\n",uVar1);
      }
      lVar3 = *(long *)(param_1 + 8);
      if (lVar3 == 0) goto LAB_00104440;
      pcVar4 = "Error getting NAON AHB clk %d\n";
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"Error getting NAON IBI Core clk %d\n",
                   uVar1 & 0xffffffff);
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010d5e6,uVar1 & 0xffffffff);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"Error getting NAON IBI Core clk %d\n",uVar1 & 0xffffffff);
    }
    lVar3 = *(long *)(param_1 + 8);
    if (lVar3 == 0) goto LAB_00104440;
    pcVar4 = "Error getting NAON IBI Core clk %d\n";
  }
  i3c_trace_log(lVar3,pcVar4,uVar1 & 0xffffffff);
LAB_00104440:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// geni_i3c_enable_naon_ibi_clks @ 001045a8 size=816
// signature: undefined geni_i3c_enable_naon_ibi_clks(void)
// callers: [qcom_geni_i3c_ibi_unconf, geni_i3c_suspend_late, geni_i3c_resume_early, i3c_ibi_rsrcs_init, qcom_geni_i3c_ibi_conf]
//------------------------------------------------------------

int geni_i3c_enable_naon_ibi_clks(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + 0x533c) == '\0') {
    return -0x16;
  }
  if (((param_2 & 1) == 0) || (*(char *)(param_1 + 0x533d) != '\0')) {
    uVar4 = *(undefined8 *)(param_1 + 0x5340);
    clk_disable(uVar4);
    clk_unprepare(uVar4);
    uVar4 = *(undefined8 *)(param_1 + 0x5348);
    clk_disable(uVar4);
    clk_unprepare(uVar4);
    uVar4 = *(undefined8 *)(param_1 + 0x5350);
    clk_disable(uVar4);
    clk_unprepare(uVar4);
    *(undefined1 *)(param_1 + 0x533d) = 0;
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: Disable clock success\n",
                   "geni_i3c_enable_naon_ibi_clks");
    lVar2 = *(long *)(param_1 + 8);
    if (lVar2 == 0) {
      return 0;
    }
    pcVar3 = "%s: Disable clock success\n";
LAB_00104644:
    i3c_trace_log(lVar2,pcVar3,"geni_i3c_enable_naon_ibi_clks");
    return 0;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x5340);
  iVar1 = clk_prepare(uVar4);
  if (iVar1 != 0) {
LAB_00104710:
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s failed at NAON core clk enable ret=%d\n",
                   "geni_i3c_enable_naon_ibi_clks",iVar1);
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010bccd,"geni_i3c_enable_naon_ibi_clks",iVar1);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s failed at NAON core clk enable ret=%d\n",
               "geni_i3c_enable_naon_ibi_clks",iVar1);
    }
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s failed at NAON core clk enable ret=%d\n",
                    "geni_i3c_enable_naon_ibi_clks",iVar1);
    }
    return iVar1;
  }
  iVar1 = clk_enable(uVar4);
  if (iVar1 != 0) {
    clk_unprepare(uVar4);
    goto LAB_00104710;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x5348);
  iVar1 = clk_prepare(uVar4);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar4);
    if (iVar1 == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x5350);
      iVar1 = clk_prepare(uVar4);
      if (iVar1 == 0) {
        iVar1 = clk_enable(uVar4);
        if (iVar1 == 0) {
          *(undefined1 *)(param_1 + 0x533d) = 1;
          ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: Enable Clock success\n",
                         "geni_i3c_enable_naon_ibi_clks");
          lVar2 = *(long *)(param_1 + 8);
          if (lVar2 == 0) {
            return 0;
          }
          pcVar3 = "%s: Enable Clock success\n";
          goto LAB_00104644;
        }
        clk_unprepare(uVar4);
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s failed at NAON src clk enable ret=%d\n",
                     "geni_i3c_enable_naon_ibi_clks",iVar1);
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010d540,"geni_i3c_enable_naon_ibi_clks",iVar1);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"%s failed at NAON src clk enable ret=%d\n",
                 "geni_i3c_enable_naon_ibi_clks",iVar1);
      }
      if (*(long *)(param_1 + 8) != 0) {
        i3c_trace_log(*(long *)(param_1 + 8),"%s failed at NAON src clk enable ret=%d\n",
                      "geni_i3c_enable_naon_ibi_clks",iVar1);
      }
      uVar4 = *(undefined8 *)(param_1 + 0x5340);
      clk_disable(uVar4);
      clk_unprepare(uVar4);
      uVar4 = *(undefined8 *)(param_1 + 0x5348);
      goto LAB_001048c4;
    }
    clk_unprepare(uVar4);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s failed at NAON ahb clk enable ret=%d\n",
                 "geni_i3c_enable_naon_ibi_clks",iVar1);
  if (*(long *)(param_1 + 8) == 0) {
    _printk(&DAT_0010c64a,"geni_i3c_enable_naon_ibi_clks",iVar1);
  }
  else {
    _dev_err(*(long *)(param_1 + 8),"%s failed at NAON ahb clk enable ret=%d\n",
             "geni_i3c_enable_naon_ibi_clks",iVar1);
  }
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"%s failed at NAON ahb clk enable ret=%d\n",
                  "geni_i3c_enable_naon_ibi_clks",iVar1);
  }
  uVar4 = *(undefined8 *)(param_1 + 0x5340);
LAB_001048c4:
  clk_disable(uVar4);
  clk_unprepare(uVar4);
  return iVar1;
}



//------------------------------------------------------------
// geni_i3c_ibi_irq @ 001048dc size=1144
// signature: undefined geni_i3c_ibi_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_ibi_irq(int param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  
  lVar11 = *(long *)(param_2 + 0x9b0);
  if (lVar11 == 0) {
    uVar7 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_2 + 0x9b8) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = sched_clock();
    ipc_log_string(lVar11,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_ibi_irq",uVar7,uVar7 / 1000
                  );
  }
  uVar8 = _raw_spin_lock_irqsave(param_2 + 0x52d0);
  if (*(int *)(param_2 + 0x52d4) == param_1) {
    uVar4 = readl_relaxed(*(long *)(param_2 + 0x52b8) + 0x14);
    uVar5 = readl_relaxed(*(long *)(param_2 + 0x52b8) + 0x10);
    uVar5 = uVar5 & uVar4;
    ipc_log_string(*(undefined8 *)(param_2 + 0x9a8),"IBI MGR IRQ IBI_GEN_IRQ_STATUS:0x%x\n",uVar5);
    if (*(long *)(param_2 + 8) != 0) {
      i3c_trace_log(*(long *)(param_2 + 8),"IBI MGR IRQ IBI_GEN_IRQ_STATUS:0x%x\n",uVar5);
    }
    if ((uVar5 & 0x12) != 0) {
      *(uint *)(param_2 + 0x5328) = uVar5;
    }
    uVar4 = uVar5 & 9;
    bVar3 = (uVar5 & 9) != 0;
    if ((uVar5 >> 2 & 1) != 0) {
      queue_work_on(0x20,*(undefined8 *)(param_2 + 0x5358),param_2 + 0x5360);
    }
    if (uVar5 != 0) {
      writel_relaxed(uVar5,*(long *)(param_2 + 0x52b8) + 0x18);
      goto joined_r0x00104cb4;
    }
LAB_00104cc0:
    if (!bVar3) goto LAB_00104cd0;
  }
  else {
    if (*(int *)(param_2 + 0x52f8) != param_1) goto LAB_00104cd0;
    uVar4 = readl_relaxed(*(long *)(param_2 + 0x52b8) + 0x1004);
    ipc_log_string(*(undefined8 *)(param_2 + 0x9a8),"IBI GPII IRQ, IBI_IRQ_STATUS:0x%x\n",uVar4);
    if (*(long *)(param_2 + 8) != 0) {
      i3c_trace_log(*(long *)(param_2 + 8),"IBI GPII IRQ, IBI_IRQ_STATUS:0x%x\n",uVar4);
    }
    if ((uVar4 & 0x3f001e) != 0) {
      *(uint *)(param_2 + 0x5328) = uVar4;
    }
    if ((uVar4 >> 8 & 1) != 0) {
      uVar5 = readl_relaxed(*(long *)(param_2 + 0x52b8) + 0x1010);
      if (uVar5 != 0) {
        uVar13 = 0;
        lVar11 = 0x1828;
        uVar12 = uVar5;
        do {
          if ((uVar12 & 1) != 0) {
            lVar10 = *(long *)(*(long *)(param_2 + 0x52c8) + uVar13 * 8);
            if ((lVar10 == 0) || (*(long *)(lVar10 + 0x68) == 0)) {
              ipc_log_string(*(undefined8 *)(param_2 + 0x9a8),"Invalid IBI device\n");
              if (*(long *)(param_2 + 8) == 0) {
                _printk(&DAT_0010c301);
                lVar10 = *(long *)(param_2 + 8);
              }
              else {
                _dev_err(*(long *)(param_2 + 8),"Invalid IBI device\n");
                lVar10 = *(long *)(param_2 + 8);
              }
              if (lVar10 != 0) {
                i3c_trace_log(lVar10,"Invalid IBI device\n");
              }
            }
            else {
              lVar9 = i3c_generic_ibi_get_free_slot(*(undefined8 *)(*(long *)(lVar10 + 0x18) + 8));
              if (lVar9 == 0) {
                ipc_log_string(*(undefined8 *)(param_2 + 0x9a8),"no free slot\n");
                if (*(long *)(param_2 + 8) == 0) {
                  _printk(&DAT_0010b8f1);
                }
                else {
                  _dev_err(*(long *)(param_2 + 8),"no free slot\n");
                }
                if (*(long *)(param_2 + 8) != 0) {
                  i3c_trace_log(*(long *)(param_2 + 8),"no free slot\n");
                }
              }
              else {
                uVar6 = readl_relaxed(*(long *)(param_2 + 0x52b8) + lVar11 + -0x24);
                *(undefined4 *)(param_2 + 0x5330) = uVar6;
                uVar6 = readl_relaxed(*(long *)(param_2 + 0x52b8) + lVar11);
                *(undefined4 *)(param_2 + 0x5334) = uVar6;
                uVar6 = readl_relaxed(*(long *)(param_2 + 0x52b8) + lVar11 + -0x20);
                *(undefined4 *)(param_2 + 0x5338) = uVar6;
                if (*(long *)(lVar9 + 0x40) != 0) {
                  memcpy(*(void **)(lVar9 + 0x40),(void *)(param_2 + 0x5338),
                         (ulong)*(uint *)(*(long *)(lVar10 + 0x68) + 0x24));
                }
                uVar1 = *(uint *)(*(long *)(lVar10 + 0x68) + 0x24);
                uVar2 = *(uint *)(param_2 + 0x5330) >> 8 & 7;
                if (uVar1 <= uVar2) {
                  uVar2 = uVar1;
                }
                *(uint *)(lVar9 + 0x38) = uVar2;
                ipc_log_string(*(undefined8 *)(param_2 + 0x9a8),
                               "IBI: info: 0x%x, ts: 0x%x, Data: 0x%x slot_id: 0x%x\n",
                               *(undefined4 *)(param_2 + 0x5330),*(undefined4 *)(param_2 + 0x5334),
                               *(undefined4 *)(param_2 + 0x5338),uVar13 & 0xffffffff);
                if (*(long *)(param_2 + 8) != 0) {
                  i3c_trace_log(*(long *)(param_2 + 8),
                                "IBI: info: 0x%x, ts: 0x%x, Data: 0x%x slot_id: 0x%x\n",
                                *(undefined4 *)(param_2 + 0x5330),*(undefined4 *)(param_2 + 0x5334),
                                *(undefined4 *)(param_2 + 0x5338),uVar13 & 0xffffffff);
                }
                i3c_master_queue_ibi(lVar10,lVar9);
              }
            }
          }
          uVar13 = uVar13 + 1;
          lVar11 = lVar11 + 0x80;
          bVar3 = 1 < uVar12;
          uVar12 = uVar12 >> 1;
        } while (bVar3);
      }
      writel_relaxed(uVar5,*(long *)(param_2 + 0x52b8) + 0x1014);
    }
    if (uVar4 == 0) {
      bVar3 = false;
      goto LAB_00104cc0;
    }
    writel_relaxed(uVar4,*(long *)(param_2 + 0x52b8) + 0x100c);
    uVar4 = uVar4 & 1;
joined_r0x00104cb4:
    if (uVar4 == 0) goto LAB_00104cd0;
  }
  complete(param_2 + 0x52d8);
LAB_00104cd0:
  _raw_spin_unlock_irqrestore(param_2 + 0x52d0,uVar8);
  lVar11 = *(long *)(param_2 + 0x9b0);
  if (((lVar11 != 0) && (uVar7 != 0)) && (*(int *)(param_2 + 0x9b8) != 0)) {
    lVar10 = sched_clock();
    ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","geni_i3c_ibi_irq",lVar10 - uVar7,
                   (lVar10 - uVar7) / 1000);
  }
  return 1;
}



//------------------------------------------------------------
// qcom_geni_i3c_ibi_conf @ 00104d54 size=300
// signature: undefined qcom_geni_i3c_ibi_conf(void)
// callers: [geni_i3c_master_request_ibi, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

void qcom_geni_i3c_ibi_conf(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(param_1 + 0x5328) = 0;
  *(undefined4 *)(param_1 + 0x52d8) = 0;
  writel_relaxed(0x5fd74322,*(long *)(param_1 + 0x52b8) + 8);
  if (((*(char *)(param_1 + 0x533c) == '\0') || (*(char *)(param_1 + 0x533d) != '\0')) ||
     (iVar1 = geni_i3c_enable_naon_ibi_clks(param_1,1), iVar1 == 0)) {
    geni_i3c_enable_ibi_ctrl(param_1,1);
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x52b8) + 0x14);
    writel_relaxed(uVar2,*(long *)(param_1 + 0x52b8) + 0x14);
    writel_relaxed(1,*(long *)(param_1 + 0x52b8) + 0xc);
    writel_relaxed(0xffffffff,*(long *)(param_1 + 0x52b8) + 0x1008);
    *(undefined1 *)(param_1 + 0x52b1) = 1;
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:  NAON clock failure\n",
                   "qcom_geni_i3c_ibi_conf");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010b9fa,"qcom_geni_i3c_ibi_conf");
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s:  NAON clock failure\n","qcom_geni_i3c_ibi_conf");
    }
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s:  NAON clock failure\n","qcom_geni_i3c_ibi_conf");
    }
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_enable_ibi_ctrl @ 00104e80 size=552
// signature: undefined geni_i3c_enable_ibi_ctrl(void)
// callers: [qcom_geni_i3c_ibi_unconf, qcom_geni_i3c_ibi_conf]
//------------------------------------------------------------

void geni_i3c_enable_ibi_ctrl(long param_1,ulong param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  
  puVar1 = (undefined4 *)(param_1 + 0x52d8);
  if ((param_2 & 1) == 0) {
    iVar3 = readl_relaxed(*(long *)(param_1 + 0x52b8) + 0xc);
    if (iVar3 == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x5328) = 0;
    *puVar1 = 0;
    uVar2 = readl_relaxed(*(undefined8 *)(param_1 + 0x52b8));
    writel_relaxed(uVar2 & 0xfffffffe,*(undefined8 *)(param_1 + 0x52b8));
    iVar3 = wait_for_completion_timeout(puVar1,0xfa);
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"timeout disabling IBI: 0x%x\n",
                     *(undefined4 *)(param_1 + 0x5328));
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010cdd5,*(undefined4 *)(param_1 + 0x5328));
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"timeout disabling IBI: 0x%x\n");
      }
      if (*(long *)(param_1 + 8) == 0) {
        return;
      }
      i3c_trace_log(*(long *)(param_1 + 8),"timeout disabling IBI: 0x%x\n",
                    *(undefined4 *)(param_1 + 0x5328));
      return;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: IBI ctrl disabled\n",
                   "geni_i3c_enable_ibi_ctrl");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010c061,"geni_i3c_enable_ibi_ctrl");
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s: IBI ctrl disabled\n","geni_i3c_enable_ibi_ctrl");
    }
    lVar4 = *(long *)(param_1 + 8);
    if (lVar4 == 0) {
      return;
    }
    pcVar5 = "%s: IBI ctrl disabled\n";
  }
  else {
    *puVar1 = 0;
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x52b8) + 0x14);
    writel_relaxed(uVar2 | 1,*(long *)(param_1 + 0x52b8) + 0x14);
    uVar2 = readl_relaxed(*(undefined8 *)(param_1 + 0x52b8));
    if ((uVar2 & 1) != 0) {
      return;
    }
    writel_relaxed(uVar2 | 1,*(undefined8 *)(param_1 + 0x52b8));
    iVar3 = wait_for_completion_timeout(puVar1,0xfa);
    if (iVar3 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"timeout while ENABLE_CHANGE bit\n");
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010ccc3);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"timeout while ENABLE_CHANGE bit\n");
      }
      if (*(long *)(param_1 + 8) == 0) {
        return;
      }
      i3c_trace_log(*(long *)(param_1 + 8),"timeout while ENABLE_CHANGE bit\n");
      return;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: IBI ctrl enabled\n",
                   "geni_i3c_enable_ibi_ctrl");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010cf6f,"geni_i3c_enable_ibi_ctrl");
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s: IBI ctrl enabled\n","geni_i3c_enable_ibi_ctrl");
    }
    lVar4 = *(long *)(param_1 + 8);
    if (lVar4 == 0) {
      return;
    }
    pcVar5 = "%s: IBI ctrl enabled\n";
  }
  i3c_trace_log(lVar4,pcVar5,"geni_i3c_enable_ibi_ctrl");
  return;
}



//------------------------------------------------------------
// geni_i3c_master_bus_init @ 001050ac size=1728
// signature: undefined geni_i3c_master_bus_init(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_master_bus_init(long param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  char *pcVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x940);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  if (lVar11 == 0) {
    uVar7 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 0x948) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = sched_clock();
    ipc_log_string(lVar11,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_bus_init",uVar7,
                   uVar7 / 1000);
  }
  iVar6 = __pm_runtime_resume(*(undefined8 *)(param_1 + -0x68),4);
  if (-1 < iVar6) {
    lVar10 = *(long *)(param_1 + 0x8c0);
    lVar11 = *(long *)(param_1 + 0x8c8);
    piVar1 = (int *)(param_1 + 0x51f8);
    if ((lVar10 == 100000) && (*piVar1 == 19200000)) {
      *(undefined1 **)(param_1 + 0x5230) = geni_i3c_clk_map;
    }
    if (lVar11 == 100000) {
      *(undefined1 **)(param_1 + 0x5238) = geni_i3c_clk_map;
    }
    if ((lVar10 == 400000) && (*piVar1 == 19200000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b06c;
    }
    if (lVar11 == 400000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b06c;
    }
    if ((lVar10 == 1000000) && (*piVar1 == 19200000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b080;
    }
    if (lVar11 == 1000000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b080;
    }
    if ((lVar10 == 0x1d4c00) && (*piVar1 == 19200000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b094;
    }
    if (lVar11 == 0x1d4c00) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b094;
    }
    if ((lVar10 == 3500000) && (*piVar1 == 19200000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b0a8;
    }
    if (lVar11 == 3500000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b0a8;
    }
    if ((lVar10 == 370000) && (*piVar1 == 100000000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b0bc;
    }
    if (lVar11 == 370000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b0bc;
    }
    if ((lVar10 == 12500000) && (*piVar1 == 100000000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b0d0;
    }
    if (lVar11 == 12500000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b0d0;
    }
    if ((lVar10 == 8300000) && (*piVar1 == 64000000)) {
      *(undefined8 *)(param_1 + 0x5230) = 0x10b0e4;
    }
    if (lVar11 == 8300000) {
      *(undefined8 *)(param_1 + 0x5238) = 0x10b0e4;
    }
    if ((*(long *)(param_1 + 0x5230) == 0) || (*(long *)(param_1 + 0x5238) == 0)) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s : clk mapping failed",
                     "geni_i3c_clk_map_idx");
      if (*(long *)(param_1 + -0x68) == 0) {
        _printk(&DAT_0010c4e1,"geni_i3c_clk_map_idx");
        lVar11 = *(long *)(param_1 + -0x68);
      }
      else {
        _dev_err(*(long *)(param_1 + -0x68),"%s : clk mapping failed","geni_i3c_clk_map_idx");
        lVar11 = *(long *)(param_1 + -0x68);
      }
      if (lVar11 != 0) {
        i3c_trace_log(lVar11,"%s : clk mapping failed","geni_i3c_clk_map_idx");
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                     "Invalid clk frequency %d Hz src or %ld Hz bus: %d\n",*piVar1,
                     *(undefined8 *)(param_1 + 0x8c0),0xffffffea);
      if (*(long *)(param_1 + -0x68) == 0) {
        _printk(&DAT_0010da43,*piVar1,*(undefined8 *)(param_1 + 0x8c0),0xffffffea);
        lVar11 = *(long *)(param_1 + -0x68);
      }
      else {
        _dev_err(*(long *)(param_1 + -0x68),"Invalid clk frequency %d Hz src or %ld Hz bus: %d\n",
                 *piVar1,*(undefined8 *)(param_1 + 0x8c0),0xffffffea);
        lVar11 = *(long *)(param_1 + -0x68);
      }
      if (lVar11 != 0) {
        i3c_trace_log(lVar11,"Invalid clk frequency %d Hz src or %ld Hz bus: %d\n",*piVar1,
                      *(undefined8 *)(param_1 + 0x8c0),0xffffffea);
      }
LAB_00105410:
      iVar6 = __pm_runtime_idle(*(undefined8 *)(param_1 + -0x68),4);
      if (-1 < iVar6) {
        lVar11 = *(long *)(param_1 + 0x940);
        if (((lVar11 != 0) && (uVar7 != 0)) && (*(int *)(param_1 + 0x948) != 0)) {
          lVar10 = sched_clock();
          ipc_log_string(lVar11,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_bus_init",
                         lVar10 - uVar7,(lVar10 - uVar7) / 1000);
        }
        goto LAB_00105660;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: error turning SE resources:%d\n",
                     "geni_i3c_master_bus_init",iVar6);
      if (*(long *)(param_1 + -0x68) == 0) {
        _printk(&DAT_0010d2a2,"geni_i3c_master_bus_init",iVar6);
      }
      else {
        _dev_err(*(long *)(param_1 + -0x68),"%s: error turning SE resources:%d\n",
                 "geni_i3c_master_bus_init",iVar6);
      }
      lVar11 = *(long *)(param_1 + -0x68);
      if (lVar11 == 0) goto LAB_00105660;
      pcVar8 = "%s: error turning SE resources:%d\n";
    }
    else {
      iVar6 = qcom_geni_i3c_conf(param_1 + -0x70,0);
      if (iVar6 == 0) {
        uVar2 = 2;
        if (*(long *)(param_1 + 0x8c8) != 1000000) {
          uVar2 = *(long *)(param_1 + 0x8c8) == 400000;
        }
        writel_relaxed(uVar2,*(long *)(param_1 + 0x5248) + 4);
        iVar6 = i3c_master_get_free_addr(param_1,0);
        if (iVar6 < 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: error No free addr:%d\n",
                         "geni_i3c_master_bus_init",iVar6);
          if (*(long *)(param_1 + -0x68) == 0) {
            _printk(&DAT_0010bbe0,"geni_i3c_master_bus_init",iVar6);
          }
          else {
            _dev_err(*(long *)(param_1 + -0x68),"%s: error No free addr:%d\n",
                     "geni_i3c_master_bus_init",iVar6);
          }
          if (*(long *)(param_1 + -0x68) != 0) {
            i3c_trace_log(*(long *)(param_1 + -0x68),"%s: error No free addr:%d\n",
                          "geni_i3c_master_bus_init",iVar6);
          }
        }
        else {
          local_58._0_4_ = CONCAT13((char)iVar6,(undefined3)local_58);
          local_60 = 0;
          local_58 = CONCAT62(local_58._2_6_,0x60);
          i3c_master_set_info(param_1,&local_60);
        }
        goto LAB_00105410;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s:geni i3c config failed, ret:%d\n",
                     "geni_i3c_master_bus_init",iVar6);
      lVar11 = *(long *)(param_1 + -0x68);
      if (lVar11 == 0) goto LAB_00105660;
      pcVar8 = "%s:geni i3c config failed, ret:%d\n";
    }
    i3c_trace_log(lVar11,pcVar8,"geni_i3c_master_bus_init",iVar6);
    goto LAB_00105660;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: error turning SE resources:%d\n",
                 "geni_i3c_master_bus_init",iVar6);
  if (*(long *)(param_1 + -0x68) == 0) {
    _printk(&DAT_0010d2a2,"geni_i3c_master_bus_init",iVar6);
    lVar11 = *(long *)(param_1 + -0x68);
    if (lVar11 != 0) goto LAB_00105500;
LAB_001055f4:
    lVar11 = 0;
  }
  else {
    _dev_err(*(long *)(param_1 + -0x68),"%s: error turning SE resources:%d\n",
             "geni_i3c_master_bus_init",iVar6);
    lVar11 = *(long *)(param_1 + -0x68);
    if (lVar11 == 0) goto LAB_001055f4;
LAB_00105500:
    i3c_trace_log(lVar11,"%s: error turning SE resources:%d\n","geni_i3c_master_bus_init",iVar6);
    lVar11 = *(long *)(param_1 + -0x68);
  }
  piVar1 = (int *)(lVar11 + 0x1f8);
  iVar9 = *(int *)(lVar11 + 0x1f8);
  do {
    if (iVar9 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      if (iVar3 != iVar9) goto LAB_00105620;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar9 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
LAB_00105620:
    bVar5 = iVar9 != iVar3;
    iVar9 = iVar3;
  } while (bVar5);
  __pm_runtime_set_status(*(undefined8 *)(param_1 + -0x68),2);
LAB_00105660:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// geni_i3c_master_bus_cleanup @ 00105784 size=4
// signature: undefined geni_i3c_master_bus_cleanup(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_master_bus_cleanup(void)

{
  return;
}



//------------------------------------------------------------
// geni_i3c_master_attach_i3c_dev @ 0010578c size=448
// signature: undefined geni_i3c_master_attach_i3c_dev(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_master_attach_i3c_dev(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x10);
  lVar5 = *(long *)(lVar6 + 0x940);
  if (lVar5 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar6 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_attach_i3c_dev",uVar1
                   ,uVar1 / 1000);
  }
  lVar5 = devm_kmalloc(*(undefined8 *)(lVar6 + -0x68),0x10,0xdc0);
  if (lVar5 == 0) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"%s alloc fail return\n",
                   "geni_i3c_master_attach_i3c_dev");
    if (*(long *)(lVar6 + -0x68) != 0) {
      i3c_trace_log(*(long *)(lVar6 + -0x68),"%s alloc fail return\n",
                    "geni_i3c_master_attach_i3c_dev");
    }
    uVar2 = 0xfffffff4;
  }
  else {
    lVar4 = *(long *)(param_1 + 0x78);
    *(long *)(param_1 + 0x18) = lVar5;
    *(undefined2 *)(lVar5 + 2) = 0xffff;
    if (lVar4 == 0) {
      plVar3 = *(long **)(lVar6 + 0x868);
      if (plVar3 != (long *)(lVar6 + 0x868)) {
        do {
          if (*(long *)(param_1 + 0x20) == plVar3[3]) {
            *(long **)(param_1 + 0x78) = plVar3;
          }
          plVar3 = (long *)*plVar3;
        } while (plVar3 != (long *)(lVar6 + 0x868));
      }
    }
    ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"%s %d\n","geni_i3c_master_attach_i3c_dev",1);
    if (*(long *)(lVar6 + -0x68) != 0) {
      i3c_trace_log(*(long *)(lVar6 + -0x68),"%s %d\n","geni_i3c_master_attach_i3c_dev",1);
    }
    lVar5 = *(long *)(lVar6 + 0x940);
    if (lVar5 != 0) {
      if (uVar1 == 0) {
        return 0;
      }
      if (*(int *)(lVar6 + 0x948) == 0) {
        return 0;
      }
      lVar6 = sched_clock(0);
      ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_attach_i3c_dev",
                     lVar6 - uVar1,(lVar6 - uVar1) / 1000);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// geni_i3c_master_reattach_i3c_dev @ 00105950 size=308
// signature: undefined geni_i3c_master_reattach_i3c_dev(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_master_reattach_i3c_dev(long param_1)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x940);
  if (lVar3 == 0) {
    uVar1 = 0xffffffffffffffea;
    lVar3 = *(long *)(param_1 + 0x78);
  }
  else if (*(int *)(lVar4 + 0x948) == 0) {
    uVar1 = 0;
    lVar3 = *(long *)(param_1 + 0x78);
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar3,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_reattach_i3c_dev",
                   uVar1,uVar1 / 1000);
    lVar3 = *(long *)(param_1 + 0x78);
  }
  if (lVar3 == 0) {
    plVar2 = *(long **)(lVar4 + 0x868);
    if (plVar2 != (long *)(lVar4 + 0x868)) {
      do {
        if (*(long *)(param_1 + 0x20) == plVar2[3]) {
          *(long **)(param_1 + 0x78) = plVar2;
        }
        plVar2 = (long *)*plVar2;
      } while (plVar2 != (long *)(lVar4 + 0x868));
    }
  }
  lVar3 = *(long *)(lVar4 + 0x940);
  if (((lVar3 != 0) && (uVar1 != 0)) && (*(int *)(lVar4 + 0x948) != 0)) {
    lVar4 = sched_clock();
    ipc_log_string(lVar3,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_reattach_i3c_dev",
                   lVar4 - uVar1,(lVar4 - uVar1) / 1000);
  }
  return 0;
}



//------------------------------------------------------------
// geni_i3c_master_detach_i3c_dev @ 00105a88 size=228
// signature: undefined geni_i3c_master_detach_i3c_dev(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_master_detach_i3c_dev(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x10);
  lVar2 = *(long *)(lVar3 + 0x940);
  if (lVar2 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar3 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar2,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_detach_i3c_dev",uVar1
                   ,uVar1 / 1000);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  lVar2 = *(long *)(lVar3 + 0x940);
  if (((lVar2 != 0) && (uVar1 != 0)) && (*(int *)(lVar3 + 0x948) != 0)) {
    lVar3 = sched_clock();
    ipc_log_string(lVar2,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_detach_i3c_dev",
                   lVar3 - uVar1,(lVar3 - uVar1) / 1000);
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_master_do_daa @ 00105b70 size=168
// signature: undefined geni_i3c_master_do_daa(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_master_do_daa(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar2 = i3c_master_entdaa_locked();
  if (((int)uVar2 == 3) || ((int)uVar2 == 0)) {
    uVar4 = 0;
    do {
      uVar1 = 1 << (ulong)(uVar4 & 0x1f);
      uVar3 = *(ulong *)(param_1 + 0x5220 + (ulong)(uVar4 >> 6) * 8);
      if ((uVar3 & (long)(int)uVar1) != 0) {
        *(ulong *)(param_1 + 0x5220 + (ulong)(uVar4 >> 6) * 8) = uVar3 & (long)(int)~uVar1;
        i3c_master_add_i3c_dev_locked(param_1,uVar4);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0x80);
    i3c_master_enec_locked(param_1,0x7e,10);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// geni_i3c_master_supports_ccc_cmd @ 00105c1c size=388
// signature: undefined geni_i3c_master_supports_ccc_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_master_supports_ccc_cmd(long param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x940);
  if (lVar4 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(param_1 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_supports_ccc_cmd",
                   uVar1,uVar1 / 1000);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x938),"Enter %s cmd->id:0x%x\n",
                 "geni_i3c_master_supports_ccc_cmd",*(undefined1 *)(param_2 + 1));
  if (*(long *)(param_1 + -0x68) != 0) {
    i3c_trace_log(*(long *)(param_1 + -0x68),"Enter %s cmd->id:0x%x\n",
                  "geni_i3c_master_supports_ccc_cmd",*(undefined1 *)(param_2 + 1));
  }
  switch(*(undefined1 *)(param_2 + 1)) {
  case 0:
  case 1:
  case 2:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x94:
  case 0x95:
    lVar4 = *(long *)(param_1 + 0x940);
    if (lVar4 != 0) {
      if (uVar1 == 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x948) == 0) {
        return 1;
      }
      lVar2 = sched_clock(1);
      ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_supports_ccc_cmd",
                     lVar2 - uVar1,(lVar2 - uVar1) / 1000);
    }
    uVar3 = 1;
    break;
  default:
    ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: Unsupported cmd\n",
                   "geni_i3c_master_supports_ccc_cmd");
    uVar3 = 0;
    if (*(long *)(param_1 + -0x68) != 0) {
      i3c_trace_log(*(long *)(param_1 + -0x68),"%s: Unsupported cmd\n",
                    "geni_i3c_master_supports_ccc_cmd");
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// geni_i3c_master_send_ccc_cmd @ 00105da4 size=2292
// signature: undefined geni_i3c_master_send_ccc_cmd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int geni_i3c_master_send_ccc_cmd(long param_1,char *param_2)

{
  long *plVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  byte *pbVar7;
  byte *pbVar8;
  long lVar9;
  undefined8 uVar10;
  char *pcVar11;
  byte bVar12;
  bool bVar13;
  uint uVar14;
  long lVar15;
  long *plVar16;
  uint uVar17;
  undefined4 uVar18;
  long lVar19;
  ulong uVar20;
  uint uVar21;
  long *plVar22;
  ulong local_c0;
  undefined8 local_98;
  ulong local_90;
  uint local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  long local_68;
  
  lVar19 = sp_el0;
  local_68 = *(long *)(lVar19 + 0x638);
  lVar19 = *(long *)(param_1 + 0x940);
  if (lVar19 == 0) {
    uVar6 = 0xffffffffffffffea;
    cVar2 = param_2[1];
  }
  else if (*(int *)(param_1 + 0x948) == 0) {
    uVar6 = 0;
    cVar2 = param_2[1];
  }
  else {
    uVar6 = sched_clock();
    ipc_log_string(lVar19,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_send_ccc_cmd",uVar6,
                   uVar6 / 1000);
    cVar2 = param_2[1];
  }
  if ((cVar2 < '\0') || (*(int *)(param_2 + 4) == 1)) {
    lVar19 = param_1 + -0x70;
    iVar4 = i3c_geni_runtime_get_mutex_lock(lVar19);
    if (iVar4 == 0) {
      iVar4 = qcom_geni_i3c_conf(lVar19,0);
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0x521c) = *(undefined4 *)(param_2 + 4);
        uVar14 = *(uint *)(param_2 + 4);
        if (uVar14 == 0) {
          iVar4 = 0;
        }
        else {
          uVar21 = 0;
          plVar1 = (long *)(param_1 + 0x868);
          do {
            if (uVar21 < uVar14 - 1) {
              uVar14 = (uint)(byte)param_2[1];
LAB_00105fb0:
              uVar5 = 4;
            }
            else {
              uVar14 = (uint)(byte)param_2[1];
              if (param_2[1] == 7) {
                uVar14 = 7;
                goto LAB_00105fb0;
              }
              uVar5 = 0;
            }
            uVar5 = uVar5 | uVar14 << 0x10 | 0x1000000;
            lVar15 = *(long *)(param_2 + 8);
            local_90 = (ulong)uVar5;
            if (uVar14 >> 7 == 0) {
              uVar18 = 0xe;
              if (*(short *)(lVar15 + (long)(int)uVar21 * 0x18 + 8) != 0) {
                uVar18 = 0x10;
              }
              local_98 = CONCAT44(uVar18,1);
              if (uVar21 != 0) goto LAB_00106064;
LAB_0010605c:
              local_90 = (ulong)uVar5 | 0x2000000;
            }
            else {
              uVar5 = uVar5 | (*(byte *)(lVar15 + (long)(int)uVar21 * 0x18) & 0x7f) << 9;
              local_90 = (ulong)uVar5;
              if (*param_2 == '\0') {
                if (uVar21 == 0) {
                  uVar18 = 0xd;
                  if (*(short *)(lVar15 + 8) != 0) {
                    uVar18 = 0x11;
                  }
                  goto LAB_00106058;
                }
                local_98 = 0x900000001;
              }
              else {
                if (uVar21 == 0) {
                  uVar18 = 0x12;
LAB_00106058:
                  local_98 = CONCAT44(uVar18,1);
                  goto LAB_0010605c;
                }
                local_98 = 0xa00000001;
              }
            }
LAB_00106064:
            lVar15 = lVar15 + (long)(int)uVar21 * 0x18;
            local_88 = uVar21;
            if (*param_2 == '\0') {
              iVar4 = i3c_geni_execute_write_command
                                (lVar19,&local_98,*(undefined8 *)(lVar15 + 0x10),
                                 *(undefined2 *)(lVar15 + 8));
            }
            else {
              iVar4 = i3c_geni_execute_read_command();
            }
            if (iVar4 != 0) goto LAB_001065e8;
            if (param_2[1] == '\a') {
              lVar15 = *(long *)(param_1 + 0x940);
              if (lVar15 == 0) {
                local_c0 = 0xffffffffffffffea;
              }
              else if (*(int *)(param_1 + 0x948) == 0) {
                local_c0 = 0;
              }
              else {
                local_c0 = sched_clock();
                ipc_log_string(lVar15,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_perform_daa",
                               local_c0,local_c0 / 1000);
              }
              pbVar7 = (byte *)kmalloc_trace(_mutex_unlock,0x101,8);
              if (pbVar7 == (byte *)0x0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: rx no memory\n",
                               "geni_i3c_perform_daa");
                if (*(long *)(param_1 + -0x68) == 0) {
                  _printk(&DAT_0010d1c2,"geni_i3c_perform_daa");
                }
                else {
                  _dev_err(*(long *)(param_1 + -0x68),"%s: rx no memory\n","geni_i3c_perform_daa");
                }
                lVar15 = *(long *)(param_1 + -0x68);
                if (lVar15 != 0) {
                  pcVar11 = "%s: rx no memory\n";
LAB_00105f5c:
                  i3c_trace_log(lVar15,pcVar11,"geni_i3c_perform_daa");
                }
              }
              else {
                pbVar8 = (byte *)kmalloc_trace(_mutex_unlock,0x101,8);
                if (pbVar8 == (byte *)0x0) {
                  kfree(pbVar7);
                  ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s: tx no memory\n",
                                 "geni_i3c_perform_daa");
                  if (*(long *)(param_1 + -0x68) == 0) {
                    _printk(&DAT_0010bf65,"geni_i3c_perform_daa");
                  }
                  else {
                    _dev_err(*(long *)(param_1 + -0x68),"%s: tx no memory\n","geni_i3c_perform_daa")
                    ;
                  }
                  lVar15 = *(long *)(param_1 + -0x68);
                  if (lVar15 != 0) {
                    pcVar11 = "%s: tx no memory\n";
                    goto LAB_00105f5c;
                  }
                }
                else {
                  do {
                    local_70 = 0;
                    local_80 = 1;
                    uStack_7c = 0;
                    uStack_78 = 0;
                    uStack_74 = 0;
                    ipc_log_string(*(undefined8 *)(param_1 + 0x938),"i3c entdaa read\n");
                    if (*(long *)(param_1 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(param_1 + -0x68),"i3c entdaa read\n");
                    }
                    pbVar7[0] = 0;
                    pbVar7[1] = 0;
                    pbVar7[2] = 0;
                    pbVar7[3] = 0;
                    pbVar7[4] = 0;
                    pbVar7[5] = 0;
                    pbVar7[6] = 0;
                    pbVar7[7] = 0;
                    pbVar8[0] = 0;
                    pbVar8[1] = 0;
                    pbVar8[2] = 0;
                    pbVar8[3] = 0;
                    pbVar8[4] = 0;
                    pbVar8[5] = 0;
                    pbVar8[6] = 0;
                    pbVar8[7] = 0;
                    uStack_7c = 2;
                    uStack_78 = 0x3000104;
                    iVar4 = i3c_geni_execute_read_command(lVar19,&local_80,pbVar7,8);
                    if (iVar4 != 0) break;
                    uVar3 = CONCAT11(*pbVar7,pbVar7[1]);
                    uVar20 = (ulong)*pbVar7 << 0x28 | (ulong)pbVar7[1] << 0x20 |
                             (ulong)pbVar7[2] << 0x18 | (ulong)pbVar7[3] << 0x10 |
                             (ulong)pbVar7[4] << 8 | (ulong)pbVar7[5];
                    plVar22 = plVar1;
                    do {
                      plVar22 = (long *)*plVar22;
                      if (plVar22 == plVar1) {
                        plVar22 = plVar1;
                        goto LAB_0010629c;
                      }
                    } while (uVar20 != plVar22[3]);
                    ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                   "PID 0x:%x matched with boardinfo\n",uVar20);
                    if (*(long *)(param_1 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(param_1 + -0x68),"PID 0x:%x matched with boardinfo\n",
                                    uVar20);
                    }
LAB_0010629c:
                    if (plVar22 == (long *)0x0) {
                      ipc_log_string(*(undefined8 *)(param_1 + 0x938),"Invalid i3cboardinfo\n");
                      if (*(long *)(param_1 + -0x68) != 0) {
                        i3c_trace_log(*(long *)(param_1 + -0x68),"Invalid i3cboardinfo\n");
                      }
                      break;
                    }
                    uVar14 = (uint)*(byte *)(plVar22 + 2);
                    if (0x7d < uVar14 - 1) {
                      uVar14 = 0;
                    }
                    uVar5 = uVar14;
                    if (uVar14 < 9) {
                      uVar5 = 8;
                    }
                    uVar5 = i3c_master_get_free_addr(param_1,uVar5);
                    if ((int)uVar5 < 0) {
                      ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                     "error:%d during get_free_addr, pid:0x:%x, mid:0x%x\n",uVar5,
                                     uVar20,uVar3);
                      if (*(long *)(param_1 + -0x68) != 0) {
                        i3c_trace_log(*(long *)(param_1 + -0x68),
                                      "error:%d during get_free_addr, pid:0x:%x, mid:0x%x\n",uVar5,
                                      uVar20,uVar3);
                      }
                      break;
                    }
                    if (uVar5 == uVar14) {
                      ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                     "assign requested addr:0x%x for pid:0x:%x, mid:0x%x\n",uVar5,
                                     uVar20,uVar3);
                      if (*(long *)(param_1 + -0x68) != 0) {
                        i3c_trace_log(*(long *)(param_1 + -0x68),
                                      "assign requested addr:0x%x for pid:0x:%x, mid:0x%x\n",uVar5,
                                      uVar20,uVar3);
                      }
LAB_001063d0:
                      bVar13 = false;
                      cVar2 = (char)plVar22[2];
                    }
                    else {
                      if (uVar14 == 0) {
                        pcVar11 = "assigning addr:0x%x for pid:x:%x\n";
                        ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                       "assigning addr:0x%x for pid:x:%x\n",uVar5,uVar20);
                        lVar15 = *(long *)(param_1 + -0x68);
joined_r0x001063bc:
                        if (lVar15 != 0) {
                          i3c_trace_log(lVar15,pcVar11,uVar5,uVar20);
                        }
                        goto LAB_001063d0;
                      }
                      pcVar11 = "new dev: assigning addr:0x%x for pid:x:%x\n";
                      plVar16 = (long *)(param_1 + 0x8d0);
                      do {
                        plVar16 = (long *)*plVar16;
                        if (plVar16 == (long *)(param_1 + 0x8d0)) {
                          ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                         "new dev: assigning addr:0x%x for pid:x:%x\n",uVar5,uVar20)
                          ;
                          lVar15 = *(long *)(param_1 + -0x68);
                          goto joined_r0x001063bc;
                        }
                      } while (plVar16[4] != uVar20);
                      bVar12 = *(byte *)((long)plVar16 + 0x2b);
                      uVar5 = (uint)bVar12;
                      ipc_log_string(*(undefined8 *)(param_1 + 0x938),
                                     "assigning requested addr:0x%x for pid:0x:%x\n",bVar12,uVar20);
                      if (*(long *)(param_1 + -0x68) != 0) {
                        i3c_trace_log(*(long *)(param_1 + -0x68),
                                      "assigning requested addr:0x%x for pid:0x:%x\n",bVar12,uVar20)
                        ;
                      }
                      bVar13 = true;
                      cVar2 = (char)plVar22[2];
                    }
                    if (cVar2 == '\0') {
                      *(char *)(plVar22 + 2) = (char)uVar5;
                    }
                    uVar14 = uVar5 & 0xff;
                    if ((char)uVar5 < '\0') {
                      bVar13 = true;
                    }
                    if (!bVar13) {
                      lVar15 = (ulong)(uVar14 >> 6) * 8;
                      *(ulong *)(param_1 + 0x5220 + lVar15) =
                           *(ulong *)(param_1 + 0x5220 + lVar15) |
                           (long)(1 << (ulong)(uVar5 & 0x1f));
                    }
                    *pbVar8 = (byte)(uVar5 << 1);
                    __sw_hweight8(uVar5 & 0x7f);
                    uVar5 = uVar5 & 1;
                    bVar12 = (byte)uVar5;
                    if (uVar14 != 0) {
                      uVar17 = uVar14;
                      do {
                        uVar5 = uVar17 >> 1 & 1 ^ uVar5;
                        bVar12 = (byte)uVar5;
                        bVar13 = 1 < uVar17;
                        uVar17 = uVar17 >> 1;
                      } while (bVar13);
                    }
                    *pbVar8 = (bVar12 | (byte)(uVar14 << 1)) ^ 1;
                    uStack_7c = 1;
                    uStack_78 = 0x5000004;
                    iVar4 = i3c_geni_execute_write_command(lVar19,&local_80,pbVar8,1);
                  } while (iVar4 == 0);
                  kfree(pbVar8);
                  kfree(pbVar7);
                  lVar15 = *(long *)(param_1 + 0x940);
                  if (((lVar15 != 0) && (local_c0 != 0)) && (*(int *)(param_1 + 0x948) != 0)) {
                    lVar9 = sched_clock();
                    ipc_log_string(lVar15,"%s:took %llu nsec(%llu usec)\n","geni_i3c_perform_daa",
                                   lVar9 - local_c0,(lVar9 - local_c0) / 1000);
                  }
                }
              }
            }
            uVar14 = *(uint *)(param_2 + 4);
            uVar21 = uVar21 + 1;
          } while (uVar21 < uVar14);
          iVar4 = 0;
        }
LAB_001065e8:
        *(undefined4 *)(param_1 + 0x521c) = 0;
        ipc_log_string(*(undefined8 *)(param_1 + 0x938),"i3c ccc: txn ret:%d\n",iVar4);
        if (*(long *)(param_1 + -0x68) == 0) {
          lVar19 = 0;
        }
        else {
          i3c_trace_log(*(long *)(param_1 + -0x68),"i3c ccc: txn ret:%d\n",iVar4);
          lVar19 = *(long *)(param_1 + -0x68);
        }
        uVar10 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar19 + 0x220) = uVar10;
        __pm_runtime_suspend(*(undefined8 *)(param_1 + -0x68),0xd);
        mutex_unlock(param_1 + 0x970);
        lVar19 = *(long *)(param_1 + 0x940);
        if (((lVar19 != 0) && (uVar6 != 0)) && (*(int *)(param_1 + 0x948) != 0)) {
          lVar15 = sched_clock();
          ipc_log_string(lVar19,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_send_ccc_cmd",
                         lVar15 - uVar6,(lVar15 - uVar6) / 1000);
        }
      }
      else {
        ipc_log_string(*(undefined8 *)(param_1 + 0x938),"%s:geni i3c config failed, ret:%d\n",
                       "geni_i3c_master_send_ccc_cmd",iVar4);
        if (*(long *)(param_1 + -0x68) != 0) {
          i3c_trace_log(*(long *)(param_1 + -0x68),"%s:geni i3c config failed, ret:%d\n",
                        "geni_i3c_master_send_ccc_cmd",iVar4);
        }
      }
    }
  }
  else {
    iVar4 = -0x16;
  }
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// geni_i3c_master_priv_xfers @ 0010669c size=3656
// signature: undefined geni_i3c_master_priv_xfers(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_master_priv_xfers(long param_1,char *param_2,uint param_3)

{
  long lVar1;
  ulong *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  byte bVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  char cVar17;
  undefined1 *puVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  long *plVar22;
  char *pcVar23;
  long lVar24;
  ulong uVar25;
  undefined8 uVar26;
  uint uVar27;
  ulong uVar28;
  ulong uVar29;
  long *plVar30;
  int local_c4;
  int local_c0;
  undefined4 local_80;
  undefined4 uStack_7c;
  uint local_78;
  uint local_74;
  uint uStack_70;
  long local_68;
  
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  lVar21 = *(long *)(param_1 + 0x10);
  lVar24 = *(long *)(lVar21 + 0x940);
  if (lVar24 == 0) {
    uVar13 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar21 + 0x948) == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = sched_clock();
    ipc_log_string(lVar24,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_priv_xfers",uVar13,
                   uVar13 / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar21 + 0x938),"Enter %s num_xfer=%d\n",
                 "geni_i3c_master_priv_xfers",param_3);
  if (*(long *)(lVar21 + -0x68) != 0) {
    i3c_trace_log(*(long *)(lVar21 + -0x68),"Enter %s num_xfer=%d\n","geni_i3c_master_priv_xfers",
                  param_3);
  }
  uVar25 = (ulong)(param_3 - 1);
  if ((int)param_3 < 1) {
    iVar9 = 0;
  }
  else {
    plVar22 = (long *)(lVar21 + -0x70);
    iVar9 = i3c_geni_runtime_get_mutex_lock(plVar22);
    if (iVar9 == 0) {
      uVar10 = readl_relaxed(*plVar22 + 0x908);
      if (((uVar10 ^ 0xffffffff) & 3) != 0) {
        ipc_log_string(*(undefined8 *)(lVar21 + 0x938),"%s:IO lines:0x%x not in good state\n",
                       "geni_i3c_master_priv_xfers",uVar10);
        if (*(long *)(lVar21 + -0x68) != 0) {
          i3c_trace_log(*(long *)(lVar21 + -0x68),"%s:IO lines:0x%x not in good state\n",
                        "geni_i3c_master_priv_xfers",uVar10);
        }
      }
      *(uint *)(lVar21 + 0x521c) = param_3;
      iVar9 = qcom_geni_i3c_conf(plVar22,1);
      if (iVar9 == 0) {
        uVar19 = (ulong)param_3;
        bVar5 = *(byte *)(param_1 + 0x2b);
        if (*(int *)(lVar21 + -4) == 3) {
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          local_74 = 0;
          lVar24 = sched_clock();
          if (param_3 < 4) {
            cVar17 = *(char *)(lVar21 + 0xabc);
          }
          else {
            cVar17 = '\x01';
            *(undefined1 *)(lVar21 + 0xabc) = 1;
            pcVar23 = param_2;
            uVar25 = uVar19;
            do {
              if (*pcVar23 != '\0') {
                cVar17 = '\0';
                *(undefined1 *)(lVar21 + 0xabc) = 0;
              }
              uVar25 = uVar25 - 1;
              pcVar23 = pcVar23 + 0x18;
            } while (uVar25 != 0);
          }
          gpi_update_multi_desc_flag
                    (*(undefined8 *)(lVar21 + 0xa28),cVar17 != '\0',*(undefined4 *)(lVar21 + 0x521c)
                    );
          uVar25 = (ulong)(param_3 - 1);
          *(undefined4 *)(lVar21 + 0x2dc0) = 0;
          *(undefined8 *)(lVar21 + 0xab0) = 0;
          *(undefined4 *)(lVar21 + 0xab8) = 0;
          if (0 < (int)param_3) {
            uVar29 = 0;
            bVar7 = true;
            lVar15 = lVar21 + 0x9d0;
            do {
              pcVar23 = param_2 + uVar29 * 0x18;
              uVar10 = 0x2000000;
              if (!bVar7) {
                uVar10 = 0;
              }
              uVar27 = (uint)((long)uVar29 < (long)uVar25);
              uVar10 = (bVar5 & 0x7f) << 9 | uVar27 << 2 | uVar10;
              local_78 = uVar10;
              uStack_70 = (uint)uVar29;
              ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                             "%s: stall:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
                             "geni_i3c_master_gsi_priv_xfers",uVar27,bVar7,param_3,
                             uVar29 & 0xffffffff,uVar10,*pcVar23);
              if (*(long *)(lVar21 + -0x68) != 0) {
                i3c_trace_log(*(long *)(lVar21 + -0x68),
                              "%s: stall:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
                              "geni_i3c_master_gsi_priv_xfers",(long)uVar29 < (long)uVar25,bVar7,
                              param_3,uVar29 & 0xffffffff,uVar10,*pcVar23);
              }
              bVar7 = (long)uVar25 <= (long)uVar29;
              if (*pcVar23 == '\0') {
                uStack_7c = 9;
                if (*(char *)(lVar21 + 0xabc) == '\0') {
                  iVar9 = i3c_geni_execute_write_command
                                    (plVar22,&local_80,*(undefined8 *)(param_2 + uVar29 * 0x18 + 8),
                                     *(undefined2 *)(param_2 + uVar29 * 0x18 + 2));
                  goto joined_r0x0010723c;
                }
                *(undefined4 *)(lVar21 + 0x5210) = 0;
                uVar20 = (ulong)((uint)uVar29 % 0x1c0);
                uVar11 = *(undefined4 *)(lVar21 + 0x521c);
                lVar16 = lVar21 + 0xab0 + uVar20 * 8;
                lVar1 = lVar21 + 0xab0 + uVar20 * 4;
                uVar26 = *(undefined8 *)(lVar21 + 0x938);
                *(undefined8 *)(lVar16 + 0xe10) = *(undefined8 *)(param_2 + uVar29 * 0x18 + 8);
                puVar3 = (uint *)(lVar1 + 0x1c10);
                *(uint *)(lVar1 + 0x1c10) = (uint)*(ushort *)(param_2 + uVar29 * 0x18 + 2);
                ipc_log_string(uVar26,"%s Enter num_xfer=%d idx=%d len=%d\n",
                               "geni_i3c_gsi_multi_write",uVar11,uVar29 & 0xffffffff);
                if (*(long *)(lVar21 + -0x68) != 0) {
                  i3c_trace_log(*(long *)(lVar21 + -0x68),"%s Enter num_xfer=%d idx=%d len=%d\n",
                                "geni_i3c_gsi_multi_write",*(undefined4 *)(lVar21 + 0x521c),
                                uVar29 & 0xffffffff,*puVar3);
                }
                *(undefined4 *)(lVar21 + -8) = 0;
                *(undefined1 *)(lVar21 + 0x51f0) = 0;
                *(undefined1 *)(lVar21 + 0xaa8) = 0;
                if ((*(char *)(lVar21 + 0x51c8) == '\0') &&
                   (iVar9 = geni_gsi_common_request_channel(lVar15), iVar9 != 0)) goto LAB_001072fc;
                uVar10 = local_74 >> 8;
                local_74 = local_74 & 0xffffff00;
                if ((uVar29 + 1 & 0x3f) == 0) {
                  local_c4 = 0;
                  cVar17 = *(char *)(lVar21 + 0x5390);
joined_r0x00106ce4:
                  local_c0 = local_c4;
                  if (cVar17 != '\0') goto LAB_00106ce8;
LAB_00106d94:
                  local_c0 = local_c4;
                }
                else {
                  if (uVar29 != *(int *)(lVar21 + 0x521c) - 1) {
                    local_c4 = 1;
                    local_74 = CONCAT31((int3)uVar10,1);
                    cVar17 = *(char *)(lVar21 + 0x5390);
                    goto joined_r0x00106ce4;
                  }
                  local_c4 = 0;
                  local_c0 = 0;
                  if (*(char *)(lVar21 + 0x5390) == '\0') goto LAB_00106d94;
LAB_00106ce8:
                  local_c4 = local_c0;
                  if (uVar29 == *(int *)(lVar21 + 0x521c) - 1) {
                    local_c0 = 1;
                    local_c4 = 0;
                    local_74 = CONCAT31(local_74._1_3_,1);
                  }
                  if (uVar29 == 0) {
                    uVar11 = 0x300001;
                    if (*(char *)(lVar21 + 0xabc) != '\0') {
                      uVar11 = 0x300401;
                    }
                    *(undefined8 *)(lVar21 + 0xa58) = 0;
                    *(undefined4 *)(lVar21 + 0xa60) = 0;
                    *(undefined4 *)(lVar21 + 0xa64) = uVar11;
                    *(byte *)(lVar21 + 0xaa8) = *(byte *)(lVar21 + 0xaa8) | 1;
                    ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                   "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                                   "i3c_setup_lock_tre",0,0,0);
                    if (*(long *)(lVar21 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(lVar21 + -0x68),
                                    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                                    "i3c_setup_lock_tre",*(undefined4 *)(lVar21 + 0xa58),
                                    *(undefined4 *)(lVar21 + 0xa5c),*(undefined4 *)(lVar21 + 0xa60),
                                    *(undefined4 *)(lVar21 + 0xa64));
                    }
                  }
                }
                if (*(char *)(lVar21 + 0x51f1) == '\0') {
                  i3c_setup_cfg0_tre(plVar22,uVar29 & 0xffffffff,1,1);
                  *(byte *)(lVar21 + 0xaa8) = *(byte *)(lVar21 + 0xaa8) | 2;
                }
                puVar2 = (ulong *)(lVar16 + 0xe10);
                i3c_setup_go_tre(plVar22,&local_80,uVar29 & 0xffffffff,1,1);
                uVar10 = *puVar3;
                *(byte *)(lVar21 + 0xaa8) = *(byte *)(lVar21 + 0xaa8) | 4;
                if (8 < uVar10) {
                  plVar30 = *(long **)(lVar21 + 0x5388);
                  if (plVar30 == (long *)0x0) {
                    iVar9 = -0x16;
                  }
                  else {
                    uVar28 = *puVar2;
                    uVar14 = is_vmalloc_addr(uVar28);
                    if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
                      dma_map_single_attrs___already_done = 1;
                      uVar26 = dev_driver_string(plVar30);
                      lVar21 = plVar30[0xe];
                      if (lVar21 == 0) {
                        lVar21 = *plVar30;
                      }
                      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar26,lVar21);
                    /* WARNING: Does not return */
                      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1072f0);
                      (*pcVar6)();
                    }
                    if ((uVar14 & 1) == 0) {
                      lVar16 = dma_map_page_attrs(plVar30,(((long)(uVar28 << 8) >> 8) +
                                                           0x8000000000U >> 0xc) * 0x40 +
                                                          -0x200000000,uVar28 & 0xfff,uVar10,1,0);
                      plVar22[uVar20 + 0x166] = lVar16;
                      if (lVar16 != -1) {
                        uVar10 = *puVar3;
                        goto LAB_00106e94;
                      }
                      iVar9 = -5;
                    }
                    else {
                      iVar9 = -5;
                      plVar22[uVar20 + 0x166] = -1;
                    }
                  }
                  ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                 "%s:geni_se_common_iommu_map_buf fail ret:%d\n",
                                 "geni_i3c_gsi_multi_write",iVar9);
                  if (*(long *)(lVar21 + -0x68) == 0) {
                    _printk(&DAT_0010c931,"geni_i3c_gsi_multi_write",iVar9);
                  }
                  else {
                    _dev_err(*(long *)(lVar21 + -0x68),
                             "%s:geni_se_common_iommu_map_buf fail ret:%d\n",
                             "geni_i3c_gsi_multi_write",iVar9);
                  }
                  if (*(long *)(lVar21 + -0x68) != 0) {
                    i3c_trace_log(*(long *)(lVar21 + -0x68),
                                  "%s:geni_se_common_iommu_map_buf fail ret:%d\n",
                                  "geni_i3c_gsi_multi_write",iVar9);
                  }
                  goto LAB_001072fc;
                }
LAB_00106e94:
                if (uVar10 != 0) {
                  if (uVar10 < 9) {
                    puVar18 = (undefined1 *)*puVar2;
                    *(undefined8 *)(lVar21 + 0xa88) = 0;
                    *(undefined1 *)(lVar21 + 0xa88) = *puVar18;
                    if ((((uVar10 != 1) &&
                         (*(undefined1 *)(lVar21 + 0xa89) = puVar18[1], uVar10 != 2)) &&
                        (*(undefined1 *)(lVar21 + 0xa8a) = puVar18[2], uVar10 != 3)) &&
                       (((*(undefined1 *)(lVar21 + 0xa8b) = puVar18[3], uVar10 != 4 &&
                         (*(undefined1 *)(lVar21 + 0xa8c) = puVar18[4], uVar10 != 5)) &&
                        ((*(undefined1 *)(lVar21 + 0xa8d) = puVar18[5], uVar10 != 6 &&
                         (*(undefined1 *)(lVar21 + 0xa8e) = puVar18[6], uVar10 != 7)))))) {
                      *(undefined1 *)(lVar21 + 0xa8f) = puVar18[7];
                    }
                    uVar10 = uVar10 & 0xf;
                    *(uint *)(lVar21 + 0xa90) = uVar10;
                    bVar8 = false;
                    if (*(char *)(lVar21 + 0x5390) != '\0') {
                      bVar8 = uVar29 == *(int *)(lVar21 + 0x521c) - 1;
                    }
                    uVar11 = *(undefined4 *)(lVar21 + 0xa88);
                    uVar27 = 0x110200;
                    if (local_c0 != 0) {
                      uVar27 = 0x110600;
                    }
                    uVar4 = *(undefined4 *)(lVar21 + 0xa8c);
                  }
                  else {
                    uVar10 = uVar10 & 0xffffff;
                    *(uint *)(lVar21 + 0xa90) = uVar10;
                    uVar11 = (undefined4)plVar22[uVar20 + 0x166];
                    uVar4 = *(undefined4 *)((long)plVar22 + uVar20 * 8 + 0xb34);
                    *(undefined4 *)(lVar21 + 0xa88) = uVar11;
                    *(undefined4 *)(lVar21 + 0xa8c) = uVar4;
                    bVar8 = false;
                    if (*(char *)(lVar21 + 0x5390) != '\0') {
                      bVar8 = uVar29 == *(int *)(lVar21 + 0x521c) - 1;
                    }
                    uVar27 = 0x100200;
                    if (local_c0 != 0) {
                      uVar27 = 0x100600;
                    }
                  }
                  *(uint *)(lVar21 + 0xa94) = bVar8 | uVar27;
                  ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                 "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x tx_idx:%d gsi_bei:%d\n"
                                 ,"i3c_setup_tx_tre",uVar11,uVar4,uVar10,bVar8 | uVar27,
                                 uVar29 & 0xffffffff,local_c0);
                  if (*(long *)(lVar21 + -0x68) != 0) {
                    i3c_trace_log(*(long *)(lVar21 + -0x68),
                                  "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x tx_idx:%d gsi_bei:%d\n"
                                  ,"i3c_setup_tx_tre",*(undefined4 *)(lVar21 + 0xa88),
                                  *(undefined4 *)(lVar21 + 0xa8c),*(undefined4 *)(lVar21 + 0xa90),
                                  *(undefined4 *)(lVar21 + 0xa94),uVar29 & 0xffffffff,local_c0);
                  }
                  *(byte *)(lVar21 + 0xaa8) = *(byte *)(lVar21 + 0xaa8) | 8;
                }
                if ((*(char *)(lVar21 + 0x5390) != '\0') &&
                   (uVar29 == *(int *)(lVar21 + 0x521c) - 1)) {
                  *(undefined8 *)(lVar21 + 0xa98) = 0;
                  *(undefined4 *)(lVar21 + 0xaa0) = 0;
                  *(undefined4 *)(lVar21 + 0xaa4) = 0x310100;
                  *(byte *)(lVar21 + 0xaa8) = *(byte *)(lVar21 + 0xaa8) | 0x10;
                  ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                 "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                                 "i3c_setup_unlock_tre",0,0,0,0x310100);
                  if (*(long *)(lVar21 + -0x68) != 0) {
                    i3c_trace_log(*(long *)(lVar21 + -0x68),
                                  "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                                  "i3c_setup_unlock_tre",*(undefined4 *)(lVar21 + 0xa98),
                                  *(undefined4 *)(lVar21 + 0xa9c),*(undefined4 *)(lVar21 + 0xaa0),
                                  *(undefined4 *)(lVar21 + 0xaa4));
                  }
                }
                uVar11 = gsi_common_fill_tre_buf(lVar15,1);
                *(int *)(lVar21 + 0xab0) = *(int *)(lVar21 + 0xab0) + 1;
                iVar9 = gsi_common_prep_desc_and_submit(lVar15,uVar11,1,local_c4);
                if (iVar9 < 0) {
                  *(int *)(lVar21 + -8) = iVar9;
LAB_001071cc:
                  geni_i3c_err_prep_sg(plVar22);
                  if (*(int *)(lVar21 + -8) != 0) {
                    gsi_common_tre_process
                              (lVar15,*(undefined4 *)(lVar21 + 0x521c),0x40,
                               *(undefined8 *)(lVar21 + 0x5388));
                    iVar9 = 3;
                    if (*(int *)(lVar21 + -8) != -0x10) {
                      iVar9 = *(int *)(lVar21 + -8);
                    }
                    ipc_log_string(*(undefined8 *)(lVar21 + 0x938),"%s:I3C transaction error :%d\n",
                                   "geni_i3c_gsi_multi_write");
                    if (*(long *)(lVar21 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(lVar21 + -0x68),"%s:I3C transaction error :%d\n",
                                    "geni_i3c_gsi_multi_write",*(undefined4 *)(lVar21 + -8));
                    }
                  }
                  if (iVar9 == 0) {
                    iVar9 = *(int *)(lVar21 + -8);
                    goto joined_r0x0010723c;
                  }
                  goto LAB_001072fc;
                }
                if (*(char *)(lVar21 + 0x51f1) == '\0') {
                  *(undefined1 *)(lVar21 + 0x51f1) = 1;
                }
                if ((uVar29 == *(int *)(lVar21 + 0x521c) - 1) ||
                   (*(int *)(lVar21 + 0xab8) + 0x1c0U <= *(uint *)(lVar21 + 0xab0))) {
                  iVar12 = gsi_common_tx_tre_optimization
                                     (lVar15,*(int *)(lVar21 + 0x521c),0x40,0x3f,
                                      *(undefined8 *)(lVar21 + 0x5388));
                  if (iVar12 == 0) {
                    ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                   "%s:wait_for_completion timedout\n","geni_i3c_gsi_multi_write");
                    if (*(long *)(lVar21 + -0x68) == 0) {
                      _printk(&DAT_0010ccfd,"geni_i3c_gsi_multi_write");
                    }
                    else {
                      _dev_err(*(long *)(lVar21 + -0x68),"%s:wait_for_completion timedout\n",
                               "geni_i3c_gsi_multi_write");
                    }
                    if (*(long *)(lVar21 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(lVar21 + -0x68),"%s:wait_for_completion timedout\n",
                                    "geni_i3c_gsi_multi_write");
                    }
                    geni_i3c_err(plVar22,9);
                    *(undefined4 *)(lVar21 + 0x950) = 0;
                  }
                  else {
                    ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                                   "%s Completed xfer->tx_idx=%d num_xfers=%d gsi_bei=%d\n",
                                   "geni_i3c_gsi_multi_write",uVar29 & 0xffffffff,
                                   *(undefined4 *)(lVar21 + 0x521c),local_c0);
                    if (*(long *)(lVar21 + -0x68) != 0) {
                      i3c_trace_log(*(long *)(lVar21 + -0x68),
                                    "%s Completed xfer->tx_idx=%d num_xfers=%d gsi_bei=%d\n",
                                    "geni_i3c_gsi_multi_write",uVar29 & 0xffffffff,
                                    *(undefined4 *)(lVar21 + 0x521c),local_c0);
                    }
                  }
                  goto LAB_001071cc;
                }
              }
              else {
                uStack_7c = 10;
                iVar9 = i3c_geni_execute_read_command
                                  (plVar22,&local_80,*(undefined8 *)(param_2 + uVar29 * 0x18 + 8),
                                   *(undefined2 *)(param_2 + uVar29 * 0x18 + 2));
joined_r0x0010723c:
                if (iVar9 != 0) goto LAB_001072fc;
              }
              uVar29 = uVar29 + 1;
            } while (uVar29 != uVar19);
          }
          iVar9 = 0;
LAB_001072fc:
          uVar26 = *(undefined8 *)(lVar21 + 0x938);
          lVar15 = sched_clock();
          ipc_log_string(uVar26,"%s Time took for %d xfers = %llu nsecs\n",
                         "geni_i3c_master_gsi_priv_xfers",param_3,lVar15 - lVar24);
          lVar15 = *(long *)(lVar21 + -0x68);
          if (lVar15 != 0) {
            lVar16 = sched_clock();
            i3c_trace_log(lVar15,"%s Time took for %d xfers = %llu nsecs\n",
                          "geni_i3c_master_gsi_priv_xfers",param_3,lVar16 - lVar24);
          }
          geni_i3c_gsi_stop_on_bus(plVar22);
          gpi_update_multi_desc_flag(*(undefined8 *)(lVar21 + 0xa28),0,0);
          if (*(char *)(lVar21 + 0x5390) != '\0') {
            *(undefined1 *)(lVar21 + 0x51f1) = 0;
          }
        }
        else {
          bVar7 = true;
          local_74 = 0;
          uStack_70 = 0;
          uStack_7c = 0;
          uVar29 = 0;
          do {
            local_80 = 1;
            if (0x40 < *(ushort *)(param_2 + 2)) {
              local_80 = 2;
            }
            uVar27 = (uint)(uVar29 < uVar25);
            uVar10 = 0x2000000;
            if (bVar7 == false) {
              uVar10 = 0;
            }
            uVar10 = (bVar5 & 0x7f) << 9 | uVar27 << 2 | uVar10;
            local_78 = uVar10;
            ipc_log_string(*(undefined8 *)(lVar21 + 0x938),
                           "%s: stall:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
                           "geni_i3c_master_fifo_dma_priv_xfers",uVar27,bVar7,param_3,
                           uVar29 & 0xffffffff,uVar10,*param_2);
            if (*(long *)(lVar21 + -0x68) != 0) {
              i3c_trace_log(*(long *)(lVar21 + -0x68),
                            "%s: stall:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
                            "geni_i3c_master_fifo_dma_priv_xfers",uVar29 < uVar25,bVar7,uVar19,
                            uVar29 & 0xffffffff,uVar10,*param_2);
            }
            bVar7 = uVar25 <= uVar29;
            if (*param_2 == '\0') {
              uStack_7c = 9;
              iVar9 = i3c_geni_execute_write_command
                                (plVar22,&local_80,*(undefined8 *)(param_2 + 8),
                                 *(undefined2 *)(param_2 + 2));
            }
            else {
              uStack_7c = 10;
              iVar9 = i3c_geni_execute_read_command
                                (plVar22,&local_80,*(undefined8 *)(param_2 + 8),
                                 *(undefined2 *)(param_2 + 2));
            }
            if (iVar9 != 0) break;
            bVar8 = uVar19 - 1 != uVar29;
            param_2 = param_2 + 0x18;
            uVar29 = uVar29 + 1;
          } while (bVar8);
        }
        ipc_log_string(*(undefined8 *)(lVar21 + 0x938),"%s ret:%d\n","geni_i3c_master_priv_xfers",
                       iVar9);
        if (*(long *)(lVar21 + -0x68) == 0) {
          lVar24 = 0;
        }
        else {
          i3c_trace_log(*(long *)(lVar21 + -0x68),"%s ret:%d\n","geni_i3c_master_priv_xfers",iVar9);
          lVar24 = *(long *)(lVar21 + -0x68);
        }
        uVar26 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar24 + 0x220) = uVar26;
        __pm_runtime_suspend(*(undefined8 *)(lVar21 + -0x68),0xd);
        mutex_unlock(lVar21 + 0x970);
        lVar24 = *(long *)(lVar21 + 0x940);
        if (((lVar24 != 0) && (uVar13 != 0)) && (*(int *)(lVar21 + 0x948) != 0)) {
          lVar15 = sched_clock();
          ipc_log_string(lVar24,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_priv_xfers",
                         lVar15 - uVar13,(lVar15 - uVar13) / 1000);
        }
        *(undefined4 *)(lVar21 + 0x521c) = 0;
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar21 + 0x938),"%s:geni i3c config failed, ret:%d\n",
                       "geni_i3c_master_priv_xfers",iVar9);
        if (*(long *)(lVar21 + -0x68) != 0) {
          i3c_trace_log(*(long *)(lVar21 + -0x68),"%s:geni i3c config failed, ret:%d\n",
                        "geni_i3c_master_priv_xfers",iVar9);
        }
      }
    }
  }
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// geni_i3c_master_attach_i2c_dev @ 001074ec size=376
// signature: undefined geni_i3c_master_attach_i2c_dev(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_master_attach_i2c_dev(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(lVar4 + 0x940);
  if (lVar3 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar4 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar3,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_attach_i2c_dev",uVar1
                   ,uVar1 / 1000);
  }
  lVar3 = devm_kmalloc(*(undefined8 *)(lVar4 + -0x68),0x10,0xdc0);
  if (lVar3 == 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x938),"%s alloc fail return\n",
                   "geni_i3c_master_attach_i2c_dev");
    if (*(long *)(lVar4 + -0x68) != 0) {
      i3c_trace_log(*(long *)(lVar4 + -0x68),"%s alloc fail return\n",
                    "geni_i3c_master_attach_i2c_dev");
    }
    uVar2 = 0xfffffff4;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x938),"%s %d\n","geni_i3c_master_attach_i2c_dev",1);
    if (*(long *)(lVar4 + -0x68) != 0) {
      i3c_trace_log(*(long *)(lVar4 + -0x68),"%s %d\n","geni_i3c_master_attach_i2c_dev",1);
    }
    *(long *)(param_1 + 0x18) = lVar3;
    lVar3 = *(long *)(lVar4 + 0x940);
    if (lVar3 != 0) {
      if (uVar1 == 0) {
        return 0;
      }
      if (*(int *)(lVar4 + 0x948) == 0) {
        return 0;
      }
      lVar4 = sched_clock(0);
      ipc_log_string(lVar3,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_attach_i2c_dev",
                     lVar4 - uVar1,(lVar4 - uVar1) / 1000);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// geni_i3c_master_detach_i2c_dev @ 00107668 size=228
// signature: undefined geni_i3c_master_detach_i2c_dev(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_master_detach_i2c_dev(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x10);
  lVar2 = *(long *)(lVar3 + 0x940);
  if (lVar2 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar3 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar2,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_detach_i2c_dev",uVar1
                   ,uVar1 / 1000);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  lVar2 = *(long *)(lVar3 + 0x940);
  if (((lVar2 != 0) && (uVar1 != 0)) && (*(int *)(lVar3 + 0x948) != 0)) {
    lVar3 = sched_clock();
    ipc_log_string(lVar2,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_detach_i2c_dev",
                   lVar3 - uVar1,(lVar3 - uVar1) / 1000);
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_master_i2c_xfers @ 00107750 size=872
// signature: undefined geni_i3c_master_i2c_xfers(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_master_i2c_xfers(long param_1,long param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  ushort *puVar5;
  long lVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar6 = *(long *)(param_1 + 0x10);
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  lVar4 = *(long *)(lVar6 + 0x940);
  if (lVar4 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar6 + 0x948) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_i2c_xfers",uVar2,
                   uVar2 / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"Enter %s num xfers=%d\n",
                 "geni_i3c_master_i2c_xfers",param_3);
  if (*(long *)(lVar6 + -0x68) != 0) {
    i3c_trace_log(*(long *)(lVar6 + -0x68),"Enter %s num xfers=%d\n","geni_i3c_master_i2c_xfers",
                  param_3);
  }
  if (param_2 == 0) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"%s: client msg is NULL\n",
                   "geni_i3c_master_i2c_xfers");
    if (*(long *)(lVar6 + -0x68) != 0) {
      i3c_trace_log(*(long *)(lVar6 + -0x68),"%s: client msg is NULL\n","geni_i3c_master_i2c_xfers")
      ;
    }
    iVar1 = 0;
  }
  else {
    lVar4 = lVar6 + -0x70;
    iVar1 = i3c_geni_runtime_get_mutex_lock(lVar4);
    if (iVar1 == 0) {
      *(undefined1 *)(lVar6 + 0x51f1) = 0;
      *(undefined1 *)(lVar6 + 0x5391) = 1;
      iVar1 = qcom_geni_i3c_conf(lVar4,1);
      if (iVar1 == 0) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"i2c xfer:num:%d, msgs:len:%d,flg:%d\n",
                       param_3,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2));
        if (*(long *)(lVar6 + -0x68) != 0) {
          i3c_trace_log(*(long *)(lVar6 + -0x68),"i2c xfer:num:%d, msgs:len:%d,flg:%d\n",param_3,
                        *(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2));
        }
        *(uint *)(lVar6 + 0x521c) = param_3;
        if (0 < (int)param_3) {
          uVar7 = 0;
          puVar5 = (ushort *)(param_2 + 4);
          do {
            local_70 = (undefined4)uVar7;
            uVar8 = 1;
            if ((puVar5[-1] & 1) != 0) {
              uVar8 = 2;
            }
            uVar9 = 1;
            if (0x20 < *puVar5) {
              uVar9 = 2;
            }
            local_80 = CONCAT44(uVar8,uVar9);
            local_78 = CONCAT44(local_78._4_4_,
                                (puVar5[-2] & 0x7f) << 9 | (uint)(uVar7 < param_3 - 1) << 2);
            if ((puVar5[-1] & 1) == 0) {
              iVar1 = i3c_geni_execute_write_command();
            }
            else {
              iVar1 = i3c_geni_execute_read_command(lVar4,&local_80,*(undefined8 *)(puVar5 + 2));
            }
            if (iVar1 != 0) goto LAB_001079ec;
            uVar7 = uVar7 + 1;
            puVar5 = puVar5 + 8;
          } while (param_3 != uVar7);
        }
        iVar1 = 0;
LAB_001079ec:
        if (*(int *)(lVar6 + -4) == 3) {
          geni_i3c_gsi_stop_on_bus(lVar4);
        }
        ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"i2c: txn ret:%d\n",iVar1);
        if (*(long *)(lVar6 + -0x68) == 0) {
          lVar4 = 0;
        }
        else {
          i3c_trace_log(*(long *)(lVar6 + -0x68),"i2c: txn ret:%d\n",iVar1);
          lVar4 = *(long *)(lVar6 + -0x68);
        }
        *(undefined1 *)(lVar6 + 0x51f1) = 0;
        *(undefined1 *)(lVar6 + 0x5391) = 0;
        *(undefined4 *)(lVar6 + 0x521c) = 0;
        uVar3 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar4 + 0x220) = uVar3;
        __pm_runtime_suspend(*(undefined8 *)(lVar6 + -0x68),0xd);
        mutex_unlock(lVar6 + 0x970);
        lVar4 = *(long *)(lVar6 + 0x940);
        if (((lVar4 != 0) && (uVar2 != 0)) && (*(int *)(lVar6 + 0x948) != 0)) {
          lVar6 = sched_clock();
          ipc_log_string(lVar4,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_i2c_xfers",
                         lVar6 - uVar2,(lVar6 - uVar2) / 1000);
        }
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x938),"%s:geni i3c config failed, ret:%d\n",
                       "geni_i3c_master_i2c_xfers",iVar1);
        if (*(long *)(lVar6 + -0x68) != 0) {
          i3c_trace_log(*(long *)(lVar6 + -0x68),"%s:geni i3c config failed, ret:%d\n",
                        "geni_i3c_master_i2c_xfers",iVar1);
        }
        *(undefined1 *)(lVar6 + 0x5391) = 0;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// geni_i3c_master_request_ibi @ 00107abc size=920
// signature: undefined geni_i3c_master_request_ibi(void)
// callers: []
//------------------------------------------------------------

undefined4 geni_i3c_master_request_ibi(long param_1,uint *param_2)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined4 uVar11;
  long lVar12;
  long lVar13;
  
  lVar1 = *(long *)(param_1 + 0x10) + 0x9a0;
  mutex_lock(lVar1);
  lVar10 = *(long *)(param_1 + 0x10);
  lVar12 = *(long *)(param_1 + 0x18);
  uVar3 = *param_2;
  lVar13 = *(long *)(lVar10 + 0x940);
  pcVar2 = (char *)(lVar10 + 0x5240);
  if (lVar13 == 0) {
    uVar7 = 0xffffffffffffffea;
    cVar5 = *pcVar2;
  }
  else if (*(int *)(lVar10 + 0x948) == 0) {
    uVar7 = 0;
    cVar5 = *pcVar2;
  }
  else {
    uVar7 = sched_clock();
    ipc_log_string(lVar13,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_request_ibi",uVar7,
                   uVar7 / 1000);
    cVar5 = *pcVar2;
  }
  if (cVar5 == '\0') {
    uVar11 = 0xffffffff;
  }
  else {
    if (*(char *)(lVar10 + 0x5241) == '\0') {
      qcom_geni_i3c_ibi_conf(lVar10 + -0x70);
    }
    uVar8 = i3c_generic_ibi_alloc_pool(param_1,param_2);
    *(ulong *)(lVar12 + 8) = uVar8;
    if (uVar8 < 0xfffffffffffff001) {
      uVar9 = _raw_spin_lock_irqsave(lVar10 + 0x5260);
      uVar4 = *(uint *)(lVar10 + 0x5250);
      uVar8 = 0;
      if (uVar4 != 0) {
        do {
          if (*(long *)(*(long *)(lVar10 + 0x5258) + uVar8 * 8) == 0) {
            *(short *)(lVar12 + 2) = (short)uVar8;
            *(long *)(*(long *)(lVar10 + 0x5258) + uVar8 * 8) = param_1;
            goto LAB_00107bf4;
          }
          uVar8 = uVar8 + 1;
        } while (uVar4 != uVar8);
        uVar8 = (ulong)uVar4;
      }
LAB_00107bf4:
      _raw_spin_unlock_irqrestore(lVar10 + 0x5260,uVar9);
      if (uVar8 < *(uint *)(lVar10 + 0x5250)) {
        *(undefined4 *)(lVar10 + 0x5268) = 0;
        *(undefined4 *)(lVar10 + 0x52b8) = 0;
        writel_relaxed((uVar3 & 0x3f) << 0xd | (uint)*(byte *)(param_1 + 0x2b) << 5 | 0x1000,
                       *(long *)(lVar10 + 0x5248) + 0x1000);
        iVar6 = wait_for_completion_timeout((undefined4 *)(lVar10 + 0x5268),0xfa);
        if (iVar6 == 0) {
          *(undefined4 *)(lVar10 + 0x52b8) = 0xffffff92;
          ipc_log_string(*(undefined8 *)(lVar10 + 0x938),"timeout while adding slave IBI\n");
          if (*(long *)(lVar10 + -0x68) == 0) {
            _printk(&DAT_0010c806);
          }
          else {
            _dev_err(*(long *)(lVar10 + -0x68),"timeout while adding slave IBI\n");
          }
          if (*(long *)(lVar10 + -0x68) != 0) {
            i3c_trace_log(*(long *)(lVar10 + -0x68),"timeout while adding slave IBI\n");
          }
        }
        if (*(int *)(lVar10 + 0x52b8) == 0) {
          uVar11 = 0;
          goto LAB_00107c4c;
        }
        ipc_log_string(*(undefined8 *)(lVar10 + 0x938),"error while adding slave IBI 0x%x\n");
        if (*(long *)(lVar10 + -0x68) == 0) {
          _printk(&DAT_0010c828,*(undefined4 *)(lVar10 + 0x52b8));
        }
        else {
          _dev_err(*(long *)(lVar10 + -0x68),"error while adding slave IBI 0x%x\n");
        }
        if (*(long *)(lVar10 + -0x68) != 0) {
          i3c_trace_log(*(long *)(lVar10 + -0x68),"error while adding slave IBI 0x%x\n",
                        *(undefined4 *)(lVar10 + 0x52b8));
        }
      }
      ipc_log_string(*(undefined8 *)(lVar10 + 0x938),"ibi.num_slots ran out %d: %d\n",uVar8,
                     *(undefined4 *)(lVar10 + 0x5250));
      if (*(long *)(lVar10 + -0x68) == 0) {
        _printk(&DAT_0010caea,uVar8,*(undefined4 *)(lVar10 + 0x5250));
      }
      else {
        _dev_err(*(long *)(lVar10 + -0x68),"ibi.num_slots ran out %d: %d\n",uVar8,
                 *(undefined4 *)(lVar10 + 0x5250));
      }
      if (*(long *)(lVar10 + -0x68) != 0) {
        i3c_trace_log(*(long *)(lVar10 + -0x68),"ibi.num_slots ran out %d: %d\n",uVar8,
                      *(undefined4 *)(lVar10 + 0x5250));
      }
      i3c_generic_ibi_free_pool(*(undefined8 *)(lVar12 + 8));
      *(undefined8 *)(lVar12 + 8) = 0;
      lVar12 = *(long *)(lVar10 + 0x940);
      if (lVar12 == 0) {
        uVar11 = 0xffffffe4;
      }
      else {
        uVar11 = 0xffffffe4;
        if ((uVar7 != 0) && (*(int *)(lVar10 + 0x948) != 0)) {
          lVar10 = sched_clock();
          ipc_log_string(lVar12,"%s:took %llu nsec(%llu usec)\n","geni_i3c_request_ibi",
                         lVar10 - uVar7,(lVar10 - uVar7) / 1000);
        }
      }
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar10 + 0x938),"Error creating a generic IBI pool %d\n",uVar8)
      ;
      if (*(long *)(lVar10 + -0x68) == 0) {
        _printk(&DAT_0010c540,*(undefined8 *)(lVar12 + 8));
      }
      else {
        _dev_err(*(long *)(lVar10 + -0x68),"Error creating a generic IBI pool %d\n");
      }
      if (*(long *)(lVar10 + -0x68) != 0) {
        i3c_trace_log(*(long *)(lVar10 + -0x68),"Error creating a generic IBI pool %d\n",
                      *(undefined8 *)(lVar12 + 8));
      }
      uVar11 = *(undefined4 *)(lVar12 + 8);
    }
  }
LAB_00107c4c:
  mutex_unlock(lVar1);
  return uVar11;
}



//------------------------------------------------------------
// geni_i3c_master_free_ibi @ 00107e58 size=332
// signature: undefined geni_i3c_master_free_ibi(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_master_free_ibi(long param_1)

{
  char *pcVar1;
  char cVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar5 = *(long *)(param_1 + 0x10);
  lVar7 = *(long *)(param_1 + 0x18);
  lVar6 = *(long *)(lVar5 + 0x940);
  pcVar1 = (char *)(lVar5 + 0x5240);
  if (lVar6 == 0) {
    uVar3 = 0xffffffffffffffea;
    cVar2 = *pcVar1;
  }
  else if (*(int *)(lVar5 + 0x948) == 0) {
    uVar3 = 0;
    cVar2 = *pcVar1;
  }
  else {
    uVar3 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_free_ibi",uVar3,
                   uVar3 / 1000);
    cVar2 = *pcVar1;
  }
  if ((cVar2 != '\0') || (*(char *)(lVar5 + 0x5241) != '\0')) {
    qcom_geni_i3c_ibi_unconf(lVar5 + -0x70);
    uVar4 = _raw_spin_lock_irqsave(lVar5 + 0x5260);
    *(undefined8 *)(*(long *)(lVar5 + 0x5258) + (long)*(short *)(lVar7 + 2) * 8) = 0;
    *(undefined2 *)(lVar7 + 2) = 0xffff;
    _raw_spin_unlock_irqrestore(lVar5 + 0x5260,uVar4);
    i3c_generic_ibi_free_pool(*(undefined8 *)(lVar7 + 8));
    lVar7 = *(long *)(lVar5 + 0x940);
    if ((lVar7 != 0) && ((uVar3 != 0 && (*(int *)(lVar5 + 0x948) != 0)))) {
      lVar5 = sched_clock();
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_free_ibi",lVar5 - uVar3
                     ,(lVar5 - uVar3) / 1000);
    }
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_master_enable_ibi @ 00107fa8 size=416
// signature: undefined geni_i3c_master_enable_ibi(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_master_enable_ibi(long param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x10);
  lVar6 = *(long *)(lVar5 + 0x940);
  pcVar1 = (char *)(lVar5 + 0x5240);
  if (lVar6 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar2 = *pcVar1;
  }
  else if (*(int *)(lVar5 + 0x948) == 0) {
    uVar4 = 0;
    cVar2 = *pcVar1;
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_enable_ibi",uVar4,
                   uVar4 / 1000);
    cVar2 = *pcVar1;
  }
  if ((cVar2 == '\0') && (*(char *)(lVar5 + 0x5241) == '\0')) {
    iVar3 = -1;
  }
  else {
    iVar3 = i3c_master_enec_locked(lVar5,*(undefined1 *)(param_1 + 0x2b),1);
    if (iVar3 != 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x938),"%s: error while i3c_master_enec_locked\n",
                     "geni_i3c_master_enable_ibi");
      if (*(long *)(lVar5 + -0x68) == 0) {
        _printk(&DAT_0010d442,"geni_i3c_master_enable_ibi");
      }
      else {
        _dev_err(*(long *)(lVar5 + -0x68),"%s: error while i3c_master_enec_locked\n",
                 "geni_i3c_master_enable_ibi");
      }
      if (*(long *)(lVar5 + -0x68) != 0) {
        i3c_trace_log(*(long *)(lVar5 + -0x68),"%s: error while i3c_master_enec_locked\n",
                      "geni_i3c_master_enable_ibi");
      }
    }
    lVar6 = *(long *)(lVar5 + 0x940);
    if (((lVar6 != 0) && (uVar4 != 0)) && (*(int *)(lVar5 + 0x948) != 0)) {
      lVar5 = sched_clock();
      ipc_log_string(lVar6,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_enable_ibi",
                     lVar5 - uVar4,(lVar5 - uVar4) / 1000);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// geni_i3c_master_disable_ibi @ 0010814c size=416
// signature: undefined geni_i3c_master_disable_ibi(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_master_disable_ibi(long param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x10);
  lVar6 = *(long *)(lVar5 + 0x940);
  pcVar1 = (char *)(lVar5 + 0x5240);
  if (lVar6 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar2 = *pcVar1;
  }
  else if (*(int *)(lVar5 + 0x948) == 0) {
    uVar4 = 0;
    cVar2 = *pcVar1;
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_disable_ibi",uVar4,
                   uVar4 / 1000);
    cVar2 = *pcVar1;
  }
  if ((cVar2 == '\0') && (*(char *)(lVar5 + 0x5241) == '\0')) {
    iVar3 = -1;
  }
  else {
    iVar3 = i3c_master_disec_locked(lVar5,*(undefined1 *)(param_1 + 0x2b),1);
    if (iVar3 != 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x938),"%s: error while i3c_master_disec_locked\n",
                     "geni_i3c_master_disable_ibi");
      if (*(long *)(lVar5 + -0x68) == 0) {
        _printk(&DAT_0010bf79,"geni_i3c_master_disable_ibi");
      }
      else {
        _dev_err(*(long *)(lVar5 + -0x68),"%s: error while i3c_master_disec_locked\n",
                 "geni_i3c_master_disable_ibi");
      }
      if (*(long *)(lVar5 + -0x68) != 0) {
        i3c_trace_log(*(long *)(lVar5 + -0x68),"%s: error while i3c_master_disec_locked\n",
                      "geni_i3c_master_disable_ibi");
      }
    }
    lVar6 = *(long *)(lVar5 + 0x940);
    if (((lVar6 != 0) && (uVar4 != 0)) && (*(int *)(lVar5 + 0x948) != 0)) {
      lVar5 = sched_clock();
      ipc_log_string(lVar6,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_disable_ibi",
                     lVar5 - uVar4,(lVar5 - uVar4) / 1000);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// geni_i3c_master_recycle_ibi_slot @ 001082f0 size=244
// signature: undefined geni_i3c_master_recycle_ibi_slot(void)
// callers: []
//------------------------------------------------------------

void geni_i3c_master_recycle_ibi_slot(long param_1,undefined8 param_2)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_1 + 0x10);
  lVar3 = *(long *)(param_1 + 0x18);
  lVar4 = *(long *)(lVar2 + 0x940);
  if (lVar4 == 0) {
    uVar1 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar2 + 0x948) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sched_clock();
    ipc_log_string(lVar4,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_master_recycle_ibi_slot",
                   uVar1,uVar1 / 1000);
  }
  i3c_generic_ibi_recycle_slot(*(undefined8 *)(lVar3 + 8),param_2);
  lVar3 = *(long *)(lVar2 + 0x940);
  if (((lVar3 != 0) && (uVar1 != 0)) && (*(int *)(lVar2 + 0x948) != 0)) {
    lVar2 = sched_clock();
    ipc_log_string(lVar3,"%s:took %llu nsec(%llu usec)\n","geni_i3c_master_recycle_ibi_slot",
                   lVar2 - uVar1,(lVar2 - uVar1) / 1000);
  }
  return;
}



//------------------------------------------------------------
// qcom_geni_i3c_conf @ 001083e4 size=488
// signature: undefined qcom_geni_i3c_conf(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers, geni_i3c_master_bus_init]
//------------------------------------------------------------

int qcom_geni_i3c_conf(long *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = param_1[0xa54];
  local_40 = 0;
  if (param_2 == 0) {
    lVar3 = param_1[0xa55];
  }
  piVar1 = (int *)((long)param_1 + 0x526c);
  iVar2 = geni_se_clk_freq_match(param_1,*(int *)(lVar3 + 4) * 1000,piVar1,&local_40,0);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
  }
  else {
    iVar2 = 0;
    *piVar1 = 0;
  }
  if (iVar2 != (int)param_1[0xa4e]) {
    if (*(int *)((long)param_1 + 0x6c) == 3) {
      *(undefined1 *)((long)param_1 + 0x5261) = 0;
    }
    ipc_log_string(param_1[0x135],"%s:dfs index:%d, prev_dfs_idx:%d\n","qcom_geni_i3c_conf");
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"%s:dfs index:%d, prev_dfs_idx:%d\n","qcom_geni_i3c_conf",
                    *(undefined4 *)((long)param_1 + 0x526c),(int)param_1[0xa4e]);
    }
  }
  if (*(char *)((long)param_1 + 0x5401) != '\0') {
    local_40 = 19200000;
  }
  iVar2 = clk_set_rate(param_1[3],local_40);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0xa4e) = *(undefined4 *)((long)param_1 + 0x526c);
    if (*(int *)((long)param_1 + 0x6c) != 3) {
      writel_relaxed(*(undefined4 *)((long)param_1 + 0x526c),*param_1 + 0x7c);
      writel_relaxed((uint)*(byte *)(lVar3 + 8) << 4 | 1,*param_1 + 0x48);
      writel_relaxed(*(uint *)(lVar3 + 0x10) | (uint)*(byte *)(lVar3 + 9) << 0x14 |
                     (uint)*(byte *)(lVar3 + 10) << 10,*param_1 + 0x278);
      writel_relaxed(*(undefined1 *)(lVar3 + 0xc),*param_1 + 0x27c);
      writel_relaxed(*(undefined1 *)(lVar3 + 0xb),*param_1 + 0x268);
    }
  }
  else {
    ipc_log_string(param_1[0x135],"%s:clock set rate failed:%d\n","qcom_geni_i3c_conf",iVar2);
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"%s:clock set rate failed:%d\n","qcom_geni_i3c_conf",iVar2);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// i3c_geni_runtime_get_mutex_lock @ 001085cc size=380
// signature: undefined i3c_geni_runtime_get_mutex_lock(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers]
//------------------------------------------------------------

int i3c_geni_runtime_get_mutex_lock(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  
  mutex_lock(param_1 + 0x9e0);
  lVar6 = *(long *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x9c0) = 0;
  if ((*(ushort *)(lVar6 + 0x200) & 7) != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"PM runtime disabled\n");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010cce6);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"PM runtime disabled\n");
    }
    lVar6 = 0;
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"PM runtime disabled\n");
      lVar6 = *(long *)(param_1 + 8);
    }
  }
  iVar5 = __pm_runtime_resume(lVar6,4);
  if (-1 < iVar5) {
    return 0;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"error turning on SE resources:%d\n",iVar5);
  if (*(long *)(param_1 + 8) == 0) {
    _printk(&DAT_0010cf87,iVar5);
    lVar6 = *(long *)(param_1 + 8);
  }
  else {
    _dev_err(*(long *)(param_1 + 8),"error turning on SE resources:%d\n",iVar5);
    lVar6 = *(long *)(param_1 + 8);
  }
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  else {
    i3c_trace_log(lVar6,"error turning on SE resources:%d\n",iVar5);
    lVar6 = *(long *)(param_1 + 8);
  }
  piVar1 = (int *)(lVar6 + 0x1f8);
  iVar7 = *(int *)(lVar6 + 0x1f8);
  do {
    if (iVar7 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar7) goto LAB_00108710;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar7 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00108710:
    bVar4 = iVar7 != iVar2;
    iVar7 = iVar2;
  } while (bVar4);
  __pm_runtime_set_status(*(undefined8 *)(param_1 + 8),2);
  mutex_unlock(param_1 + 0x9e0);
  return iVar5;
}



//------------------------------------------------------------
// i3c_geni_execute_read_command @ 0010875c size=1384
// signature: undefined i3c_geni_execute_read_command(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers]
//------------------------------------------------------------

int i3c_geni_execute_read_command(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long *plVar11;
  ulong uVar12;
  
  *(undefined8 *)(param_1 + 0x5278) = param_3;
  *(undefined4 *)(param_1 + 0x5280) = 1;
  *(undefined4 *)(param_1 + 0x5284) = param_4;
  if (*(int *)(param_1 + 0x6c) != 3) {
    iVar5 = geni_i3c_fifo_dma_xfer(param_1,param_2);
    return iVar5;
  }
  lVar9 = param_1 + 0xa40;
  if ((*(char *)(param_1 + 0x5238) == '\0') &&
     (iVar5 = geni_gsi_common_request_channel(lVar9), iVar5 != 0)) {
    return iVar5;
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  pbVar1 = (byte *)(param_1 + 0x2f00);
  *(undefined1 *)(param_1 + 0x5260) = 0;
  *(undefined1 *)(param_1 + 0xb18) = 0;
  *pbVar1 = 0;
  *(undefined4 *)(param_1 + 0x9c0) = 0;
  if ((*(char *)(param_1 + 0x5400) != '\0') && (*(int *)(param_2 + 0x10) == 0)) {
    uVar4 = 0x300001;
    if (*(char *)(param_1 + 0xb2c) != '\0') {
      uVar4 = 0x300401;
    }
    *(undefined8 *)(param_1 + 0xac8) = 0;
    *(undefined4 *)(param_1 + 0xad0) = 0;
    *(undefined4 *)(param_1 + 0xad4) = uVar4;
    *(undefined1 *)(param_1 + 0xb18) = 1;
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                   "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                   "i3c_setup_lock_tre",0,0,0);
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),
                    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                    "i3c_setup_lock_tre",*(undefined4 *)(param_1 + 0xac8),
                    *(undefined4 *)(param_1 + 0xacc),*(undefined4 *)(param_1 + 0xad0),
                    *(undefined4 *)(param_1 + 0xad4));
    }
  }
  if (*(char *)(param_1 + 0x5261) == '\0') {
    i3c_setup_cfg0_tre(param_1,0,0,0);
    *(byte *)(param_1 + 0xb18) = *(byte *)(param_1 + 0xb18) | 2;
  }
  i3c_setup_go_tre(param_1,param_2,*(undefined4 *)(param_2 + 0x10),0,0);
  iVar5 = *(int *)(param_1 + 0x5284);
  *(byte *)(param_1 + 0xb18) = *(byte *)(param_1 + 0xb18) | 4;
  if (iVar5 == 0) {
    lVar7 = *(long *)(param_1 + 0x5258);
    uVar10 = 0;
  }
  else {
    plVar11 = *(long **)(param_1 + 0x53f8);
    if (plVar11 == (long *)0x0) {
      iVar5 = -0x16;
LAB_00108c50:
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                     "%s:geni_se_common_iommu_map_buf failed ret:%d\n","geni_i3c_gsi_read",iVar5);
      if (*(long *)(param_1 + 8) == 0) {
        _printk(&DAT_0010bf34,"geni_i3c_gsi_read",iVar5);
      }
      else {
        _dev_err(*(long *)(param_1 + 8),"%s:geni_se_common_iommu_map_buf failed ret:%d\n",
                 "geni_i3c_gsi_read",iVar5);
      }
      if (*(long *)(param_1 + 8) == 0) {
        return iVar5;
      }
      i3c_trace_log(*(long *)(param_1 + 8),"%s:geni_se_common_iommu_map_buf failed ret:%d\n",
                    "geni_i3c_gsi_read",iVar5);
      return iVar5;
    }
    uVar12 = *(ulong *)(param_1 + 0x5278);
    uVar6 = is_vmalloc_addr(uVar12);
    if (((uVar6 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar8 = dev_driver_string(plVar11);
      lVar9 = plVar11[0xe];
      if (lVar9 == 0) {
        lVar9 = *plVar11;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar8,lVar9);
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x108c3c);
      (*pcVar3)();
    }
    if ((uVar6 & 1) != 0) {
      iVar5 = -5;
      *(undefined8 *)(param_1 + 0x5258) = 0xffffffffffffffff;
      goto LAB_00108c50;
    }
    lVar7 = dma_map_page_attrs(plVar11,(((long)(uVar12 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                       -0x200000000,uVar12 & 0xfff,(long)iVar5,2,0);
    *(long *)(param_1 + 0x5258) = lVar7;
    if (lVar7 == -1) {
      iVar5 = -5;
      goto LAB_00108c50;
    }
    uVar10 = *(uint *)(param_1 + 0x5284) & 0xffffff;
  }
  *(int *)(param_1 + 12000) = (int)lVar7;
  *(uint *)(param_1 + 0x2ee8) = uVar10;
  *(int *)(param_1 + 0x2ee4) = (int)((ulong)lVar7 >> 0x20);
  *(undefined4 *)(param_1 + 0x2eec) = 0x100200;
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                 "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n","i3c_setup_rx_tre")
  ;
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n","i3c_setup_rx_tre"
                  ,*(undefined4 *)(param_1 + 12000),*(undefined4 *)(param_1 + 0x2ee4),
                  *(undefined4 *)(param_1 + 0x2ee8),*(undefined4 *)(param_1 + 0x2eec));
  }
  *pbVar1 = *pbVar1 | 8;
  if ((*(char *)(param_1 + 0x5400) != '\0') &&
     (*(int *)(param_2 + 0x10) == *(int *)(param_1 + 0x528c) + -1)) {
    *(undefined8 *)(param_1 + 0xb08) = 0;
    *(undefined8 *)(param_1 + 0xb10) = 0x31010000000000;
    *(byte *)(param_1 + 0xb18) = *(byte *)(param_1 + 0xb18) | 0x10;
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                   "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                   "i3c_setup_unlock_tre",0,0,0,0x310100);
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),
                    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                    "i3c_setup_unlock_tre",*(undefined4 *)(param_1 + 0xb08),
                    *(undefined4 *)(param_1 + 0xb0c),*(undefined4 *)(param_1 + 0xb10),
                    *(undefined4 *)(param_1 + 0xb14));
    }
  }
  uVar4 = gsi_common_fill_tre_buf(lVar9,0);
  iVar5 = gsi_common_prep_desc_and_submit(lVar9,uVar4,0,0);
  if (-1 < iVar5) {
    uVar4 = gsi_common_fill_tre_buf(lVar9,1);
    iVar5 = gsi_common_prep_desc_and_submit(lVar9,uVar4,1,0);
    if (-1 < iVar5) {
      iVar5 = wait_for_completion_timeout(param_1 + 0x9c0,0xfa);
      if (iVar5 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:wait_for_completion timed out\n",
                       "geni_i3c_gsi_read");
        if (*(long *)(param_1 + 8) == 0) {
          _printk(&DAT_0010b7f7,"geni_i3c_gsi_read");
        }
        else {
          _dev_err(*(long *)(param_1 + 8),"%s:wait_for_completion timed out\n","geni_i3c_gsi_read");
        }
        if (*(long *)(param_1 + 8) != 0) {
          i3c_trace_log(*(long *)(param_1 + 8),"%s:wait_for_completion timed out\n",
                        "geni_i3c_gsi_read");
        }
        geni_i3c_err(param_1,9);
        *(undefined8 *)(param_1 + 0x5278) = 0;
        *(undefined4 *)(param_1 + 0x5288) = 0;
        *(undefined4 *)(param_1 + 0x5280) = 0;
        *(undefined4 *)(param_1 + 0x9c0) = 0;
      }
      else if (*(char *)(param_1 + 0x5261) == '\0') {
        *(undefined1 *)(param_1 + 0x5261) = 1;
      }
      goto LAB_00108ac4;
    }
  }
  *(int *)(param_1 + 0x68) = iVar5;
LAB_00108ac4:
  iVar5 = geni_i3c_err_prep_sg(param_1);
  if ((*(int *)(param_1 + 0x5284) != 0) && (*(long *)(param_1 + 0x5258) != -1)) {
    dma_unmap_page_attrs
              (*(undefined8 *)(param_1 + 0x53f8),*(long *)(param_1 + 0x5258),
               (long)*(int *)(param_1 + 0x5284),2,0);
  }
  iVar2 = *(int *)(param_1 + 0x68);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x5284) = 0;
    iVar5 = 3;
    if (iVar2 != -0x10) {
      iVar5 = iVar2;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:I3C transaction error:%d\n",
                   "geni_i3c_gsi_read");
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s:I3C transaction error:%d\n","geni_i3c_gsi_read",
                    *(undefined4 *)(param_1 + 0x68));
    }
  }
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0x68);
  }
  return iVar5;
}



//------------------------------------------------------------
// i3c_geni_execute_write_command @ 00108ccc size=1348
// signature: undefined i3c_geni_execute_write_command(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers]
//------------------------------------------------------------

int i3c_geni_execute_write_command(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  byte bVar10;
  long *plVar11;
  ulong uVar12;
  
  *(undefined8 *)(param_1 + 0x5278) = param_3;
  *(undefined4 *)(param_1 + 0x5280) = 0;
  *(undefined4 *)(param_1 + 0x5284) = param_4;
  if (*(int *)(param_1 + 0x6c) != 3) {
    iVar5 = geni_i3c_fifo_dma_xfer(param_1,param_2);
    return iVar5;
  }
  lVar9 = param_1 + 0xa40;
  if ((*(char *)(param_1 + 0x5238) == '\0') &&
     (iVar5 = geni_gsi_common_request_channel(lVar9), iVar5 != 0)) {
    return iVar5;
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined1 *)(param_1 + 0x5260) = 0;
  *(undefined1 *)(param_1 + 0xb18) = 0;
  *(undefined4 *)(param_1 + 0x9c0) = 0;
  if ((*(char *)(param_1 + 0x5400) != '\0') && (*(int *)(param_2 + 0x10) == 0)) {
    uVar4 = 0x300001;
    if (*(char *)(param_1 + 0xb2c) != '\0') {
      uVar4 = 0x300401;
    }
    *(undefined8 *)(param_1 + 0xac8) = 0;
    *(undefined4 *)(param_1 + 0xad0) = 0;
    *(undefined4 *)(param_1 + 0xad4) = uVar4;
    *(undefined1 *)(param_1 + 0xb18) = 1;
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                   "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                   "i3c_setup_lock_tre",0,0,0);
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),
                    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                    "i3c_setup_lock_tre",*(undefined4 *)(param_1 + 0xac8),
                    *(undefined4 *)(param_1 + 0xacc),*(undefined4 *)(param_1 + 0xad0),
                    *(undefined4 *)(param_1 + 0xad4));
    }
  }
  if (*(char *)(param_1 + 0x5261) == '\0') {
    i3c_setup_cfg0_tre(param_1,0,0,0);
    *(byte *)(param_1 + 0xb18) = *(byte *)(param_1 + 0xb18) | 2;
  }
  i3c_setup_go_tre(param_1,param_2,*(undefined4 *)(param_2 + 0x10),0,0);
  iVar5 = *(int *)(param_1 + 0x5284);
  bVar10 = *(byte *)(param_1 + 0xb18) | 4;
  *(byte *)(param_1 + 0xb18) = bVar10;
  if (iVar5 == 0) {
LAB_00108f10:
    if ((*(char *)(param_1 + 0x5400) != '\0') &&
       (*(int *)(param_2 + 0x10) == *(int *)(param_1 + 0x528c) + -1)) {
      *(undefined8 *)(param_1 + 0xb08) = 0;
      *(undefined8 *)(param_1 + 0xb10) = 0x31010000000000;
      *(byte *)(param_1 + 0xb18) = bVar10 | 0x10;
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                     "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                     "i3c_setup_unlock_tre",0,0,0,0x310100);
      if (*(long *)(param_1 + 8) != 0) {
        i3c_trace_log(*(long *)(param_1 + 8),
                      "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                      "i3c_setup_unlock_tre",*(undefined4 *)(param_1 + 0xb08),
                      *(undefined4 *)(param_1 + 0xb0c),*(undefined4 *)(param_1 + 0xb10),
                      *(undefined4 *)(param_1 + 0xb14));
      }
    }
    uVar4 = gsi_common_fill_tre_buf(lVar9,1);
    iVar5 = gsi_common_prep_desc_and_submit(lVar9,uVar4,1,0);
    if (iVar5 < 0) {
      *(int *)(param_1 + 0x68) = iVar5;
    }
    else {
      iVar5 = wait_for_completion_timeout(param_1 + 0x9c0,0xfa);
      if (iVar5 == 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:wait_for_completion timed out\n",
                       "geni_i3c_gsi_write");
        if (*(long *)(param_1 + 8) == 0) {
          _printk(&DAT_0010b7f7,"geni_i3c_gsi_write");
        }
        else {
          _dev_err(*(long *)(param_1 + 8),"%s:wait_for_completion timed out\n","geni_i3c_gsi_write")
          ;
        }
        if (*(long *)(param_1 + 8) != 0) {
          i3c_trace_log(*(long *)(param_1 + 8),"%s:wait_for_completion timed out\n",
                        "geni_i3c_gsi_write");
        }
        geni_i3c_err(param_1,9);
        *(undefined8 *)(param_1 + 0x5278) = 0;
        *(undefined4 *)(param_1 + 0x5288) = 0;
        *(undefined4 *)(param_1 + 0x5280) = 0;
        *(undefined4 *)(param_1 + 0x9c0) = 0;
      }
      else if (*(char *)(param_1 + 0x5261) == '\0') {
        *(undefined1 *)(param_1 + 0x5261) = 1;
      }
    }
    iVar5 = geni_i3c_err_prep_sg(param_1);
    if ((*(int *)(param_1 + 0x5284) != 0) && (*(long *)(param_1 + 0xb30) != -1)) {
      dma_unmap_page_attrs
                (*(undefined8 *)(param_1 + 0x53f8),*(long *)(param_1 + 0xb30),
                 (long)*(int *)(param_1 + 0x5284),1,0);
    }
    iVar1 = *(int *)(param_1 + 0x68);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x5284) = 0;
      iVar5 = 3;
      if (iVar1 != -0x10) {
        iVar5 = iVar1;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:I3C transaction error :%d\n",
                     "geni_i3c_gsi_write");
      if (*(long *)(param_1 + 8) != 0) {
        i3c_trace_log(*(long *)(param_1 + 8),"%s:I3C transaction error :%d\n","geni_i3c_gsi_write",
                      *(undefined4 *)(param_1 + 0x68));
      }
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0x68);
    }
  }
  else {
    plVar11 = *(long **)(param_1 + 0x53f8);
    if (plVar11 == (long *)0x0) {
      iVar5 = -0x16;
    }
    else {
      uVar12 = *(ulong *)(param_1 + 0x5278);
      uVar6 = is_vmalloc_addr(uVar12);
      if (((uVar6 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar8 = dev_driver_string(plVar11);
        lVar9 = plVar11[0xe];
        if (lVar9 == 0) {
          lVar9 = *plVar11;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar8,lVar9);
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x109188);
        (*pcVar3)();
      }
      if ((uVar6 & 1) == 0) {
        lVar7 = dma_map_page_attrs(plVar11,(((long)(uVar12 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                           0x40 + -0x200000000,uVar12 & 0xfff,(long)iVar5,1,0);
        *(long *)(param_1 + 0xb30) = lVar7;
        if (lVar7 != -1) {
          uVar2 = 0x100200;
          *(int *)(param_1 + 0xaf8) = (int)lVar7;
          *(int *)(param_1 + 0xafc) = (int)((ulong)lVar7 >> 0x20);
          *(uint *)(param_1 + 0xb00) = *(uint *)(param_1 + 0x5284) & 0xffffff;
          if (*(char *)(param_1 + 0x5400) != '\0') {
            uVar2 = *(int *)(param_1 + 0x528c) == 1 | 0x100200;
          }
          *(uint *)(param_1 + 0xb04) = uVar2;
          ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                         "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x tx_idx:%d gsi_bei:%d\n"
                         ,"i3c_setup_tx_tre");
          if (*(long *)(param_1 + 8) != 0) {
            i3c_trace_log(*(long *)(param_1 + 8),
                          "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x tx_idx:%d gsi_bei:%d\n"
                          ,"i3c_setup_tx_tre",*(undefined4 *)(param_1 + 0xaf8),
                          *(undefined4 *)(param_1 + 0xafc),*(undefined4 *)(param_1 + 0xb00),
                          *(undefined4 *)(param_1 + 0xb04),0,0);
          }
          bVar10 = *(byte *)(param_1 + 0xb18) | 8;
          *(byte *)(param_1 + 0xb18) = bVar10;
          goto LAB_00108f10;
        }
        iVar5 = -5;
      }
      else {
        iVar5 = -5;
        *(undefined8 *)(param_1 + 0xb30) = 0xffffffffffffffff;
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                   "%s:geni_se_common_iommu_map_buf failed ret:%d\n","geni_i3c_gsi_write",iVar5);
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010bf34,"geni_i3c_gsi_write",iVar5);
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s:geni_se_common_iommu_map_buf failed ret:%d\n",
               "geni_i3c_gsi_write",iVar5);
    }
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s:geni_se_common_iommu_map_buf failed ret:%d\n",
                    "geni_i3c_gsi_write",iVar5);
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// geni_i3c_fifo_dma_xfer @ 00109218 size=1580
// signature: undefined geni_i3c_fifo_dma_xfer(void)
// callers: [i3c_geni_execute_read_command, i3c_geni_execute_write_command]
//------------------------------------------------------------

int geni_i3c_fifo_dma_xfer(long *param_1,int *param_2)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  plVar1 = param_1 + 0x138;
  *(undefined4 *)(param_1 + 0x138) = 0;
  iVar3 = (int)param_1[0xa50];
  iVar2 = *(int *)((long)param_1 + 0x5284);
  local_68 = 0;
  local_60 = 0;
  geni_se_select_mode(param_1,*param_2);
  *(undefined4 *)(param_1 + 0xd) = 0;
  *(undefined4 *)(param_1 + 0xa51) = 0;
  if (iVar3 == 1) {
    writel_relaxed(iVar2,*param_1 + 0x270);
    writel(param_2[2] & 0x7ffffffU | param_2[1] << 0x1b,*param_1 + 0x600);
    iVar5 = param_2[1];
    iVar6 = param_2[2];
    lVar8 = param_1[0x135];
    uVar4 = readl_relaxed(*param_1 + 0x600);
    ipc_log_string(lVar8,"I3C cmd:0x%x param:0x%x READ len:%d, m_cmd: 0x%x\n",iVar5,iVar6,iVar2,
                   uVar4);
    lVar8 = param_1[1];
    if (lVar8 != 0) {
      iVar5 = param_2[1];
      iVar6 = param_2[2];
      uVar4 = readl_relaxed(*param_1 + 0x600);
      i3c_trace_log(lVar8,"I3C cmd:0x%x param:0x%x READ len:%d, m_cmd: 0x%x\n",iVar5,iVar6,iVar2,
                    uVar4);
    }
    if (*param_2 == 2) {
      iVar5 = geni_se_rx_dma_prep(param_1,param_1[0xa4f],iVar2,&local_68);
      if (iVar5 != 0) {
        ipc_log_string(param_1[0x135],"DMA Err:%d FIFO mode enabled\n",iVar5);
        if (param_1[1] == 0) {
          _printk(&DAT_0010bd76,iVar5);
        }
        else {
          _dev_err(param_1[1],"DMA Err:%d FIFO mode enabled\n",iVar5);
        }
        if (param_1[1] != 0) {
          i3c_trace_log(param_1[1],"DMA Err:%d FIFO mode enabled\n",iVar5);
        }
        *param_2 = 1;
        geni_se_select_mode(param_1,1);
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    writel_relaxed(iVar2,*param_1 + 0x26c);
    writel(param_2[2] & 0x7ffffffU | param_2[1] << 0x1b,*param_1 + 0x600);
    iVar5 = param_2[1];
    iVar6 = param_2[2];
    lVar8 = param_1[0x135];
    uVar4 = readl_relaxed(*param_1 + 0x600);
    ipc_log_string(lVar8,"I3C cmd:0x%x param:0x%x WRITE len:%d, m_cmd: 0x%x\n",iVar5,iVar6,iVar2,
                   uVar4);
    lVar8 = param_1[1];
    if (lVar8 != 0) {
      iVar5 = param_2[1];
      iVar6 = param_2[2];
      uVar4 = readl_relaxed(*param_1 + 0x600);
      i3c_trace_log(lVar8,"I3C cmd:0x%x param:0x%x WRITE len:%d, m_cmd: 0x%x\n",iVar5,iVar6,iVar2,
                    uVar4);
    }
    if (*param_2 == 2) {
      iVar5 = geni_se_tx_dma_prep(param_1,param_1[0xa4f],iVar2,&local_60);
      if (iVar5 != 0) {
        ipc_log_string(param_1[0x135],"DMA Err:%d FIFO mode enabled\n",iVar5);
        if (param_1[1] == 0) {
          _printk(&DAT_0010bd76,iVar5);
        }
        else {
          _dev_err(param_1[1],"DMA Err:%d FIFO mode enabled\n",iVar5);
        }
        if (param_1[1] != 0) {
          i3c_trace_log(param_1[1],"DMA Err:%d FIFO mode enabled\n",iVar5);
        }
        *param_2 = 1;
        geni_se_select_mode(param_1,1);
      }
    }
    else {
      iVar5 = 0;
    }
    if ((*param_2 == 1) && (iVar2 != 0)) {
      writel_relaxed(1,*param_1 + 0x80c);
    }
  }
  iVar6 = wait_for_completion_timeout(plVar1,0xfa);
  if (iVar6 == 0) {
    ipc_log_string(param_1[0x135],"wait_for_completion timed out\n");
    if (param_1[1] == 0) {
      _printk(&DAT_0010bd96);
    }
    else {
      _dev_err(param_1[1],"wait_for_completion timed out\n");
    }
    if (param_1[1] != 0) {
      i3c_trace_log(param_1[1],"wait_for_completion timed out\n");
    }
    geni_i3c_err(param_1,9);
    lVar8 = (long)param_1 + 0x5264;
    *(undefined4 *)(param_1 + 0x138) = 0;
    param_1[0xa4f] = 0;
    param_1[0xa50] = 0;
    *(undefined4 *)(param_1 + 0xa51) = 0;
    uVar7 = _raw_spin_lock_irqsave(lVar8);
    writel_relaxed(4,*param_1 + 0x604);
    _raw_spin_unlock_irqrestore(lVar8,uVar7);
    iVar6 = wait_for_completion_timeout(plVar1,0xfa);
    if (iVar6 == 0) {
      ipc_log_string(param_1[0x135],"%s:Cancel failed: Aborting\n","geni_i3c_fifo_dma_xfer");
      if (param_1[1] == 0) {
        _printk(&DAT_0010d76b,"geni_i3c_fifo_dma_xfer");
      }
      else {
        _dev_err(param_1[1],"%s:Cancel failed: Aborting\n","geni_i3c_fifo_dma_xfer");
      }
      if (param_1[1] != 0) {
        i3c_trace_log(param_1[1],"%s:Cancel failed: Aborting\n","geni_i3c_fifo_dma_xfer");
      }
      geni_i3c_dump_dbg_regs(param_1);
      *(undefined4 *)(param_1 + 0x138) = 0;
      uVar7 = _raw_spin_lock_irqsave(lVar8);
      writel_relaxed(2,*param_1 + 0x604);
      _raw_spin_unlock_irqrestore(lVar8,uVar7);
      iVar6 = wait_for_completion_timeout(plVar1,0xfa);
      if (iVar6 == 0) {
        ipc_log_string(param_1[0x135],"%s:Abort Failed\n","geni_i3c_fifo_dma_xfer");
        if (param_1[1] == 0) {
          _printk(&DAT_0010c0ac,"geni_i3c_fifo_dma_xfer");
        }
        else {
          _dev_err(param_1[1],"%s:Abort Failed\n","geni_i3c_fifo_dma_xfer");
        }
        if (param_1[1] != 0) {
          i3c_trace_log(param_1[1],"%s:Abort Failed\n","geni_i3c_fifo_dma_xfer");
        }
        geni_i3c_dump_dbg_regs(param_1);
      }
    }
  }
  if (*param_2 == 2) {
    if ((int)param_1[0xd] != 0) {
      lVar8 = 0xd58;
      if (iVar3 != 1) {
        lVar8 = 0xc58;
      }
      *(undefined4 *)(param_1 + 0x138) = 0;
      writel_relaxed(1,*param_1 + lVar8);
      iVar6 = wait_for_completion_timeout(plVar1,0xfa);
      if (iVar6 == 0) {
        ipc_log_string(param_1[0x135],"Timeout:FSM Reset, rnw:%d\n",iVar3);
        if (param_1[1] == 0) {
          _printk(&DAT_0010d789,iVar3);
        }
        else {
          _dev_err(param_1[1],"Timeout:FSM Reset, rnw:%d\n",iVar3);
        }
        if (param_1[1] != 0) {
          i3c_trace_log(param_1[1],"Timeout:FSM Reset, rnw:%d\n",iVar3);
        }
        geni_i3c_dump_dbg_regs(param_1);
      }
    }
    if (iVar3 == 1) {
      geni_se_rx_dma_unprep(param_1,local_68,iVar2);
    }
    else {
      geni_se_tx_dma_unprep(param_1,local_60,iVar2);
    }
  }
  iVar3 = (int)param_1[0xd];
  if (iVar3 == -0x10) {
    iVar3 = 3;
  }
  else if (iVar3 == 0) goto LAB_00109688;
  iVar5 = iVar3;
  ipc_log_string(param_1[0x135],"I3C transaction error:%d\n");
  if (param_1[1] != 0) {
    i3c_trace_log(param_1[1],"I3C transaction error:%d\n",(int)param_1[0xd]);
  }
LAB_00109688:
  *(undefined4 *)(param_1 + 0xd) = 0;
  param_1[0xa4f] = 0;
  param_1[0xa50] = 0;
  *(undefined4 *)(param_1 + 0xa51) = 0;
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// i3c_setup_cfg0_tre @ 00109844 size=400
// signature: undefined i3c_setup_cfg0_tre(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

void i3c_setup_cfg0_tre(long param_1,int param_2,ulong param_3,ulong param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  long lVar8;
  
  piVar1 = (int *)(param_1 + 0x526c);
  lVar8 = *(long *)(param_1 + 0x52a0);
  if ((param_4 & 1) == 0) {
    puVar7 = (undefined4 *)(param_1 + 0x5284);
  }
  else {
    if (0x1bf < (uint)(param_2 % 0x1c0)) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1099d4);
      (*pcVar5)();
    }
    puVar7 = (undefined4 *)(param_1 + (ulong)(uint)(param_2 % 0x1c0) * 4 + 0x2730);
  }
  uVar3 = *puVar7;
  if (*(char *)(param_1 + 0x5401) == '\0') {
    iVar4 = *piVar1;
    *(uint *)(param_1 + 0xae8) =
         (uint)*(byte *)(lVar8 + 9) << 8 | *(int *)(lVar8 + 0x10) << 0x10 |
         (uint)*(byte *)(lVar8 + 10) | 0x3000000;
    *(uint *)(param_1 + 0xaec) = (uint)*(ushort *)(lVar8 + 0xb);
    uVar6 = (uint)*(byte *)(lVar8 + 8) | iVar4 << 0x10;
  }
  else {
    iVar4 = *piVar1;
    uVar6 = 1;
    *(undefined8 *)(param_1 + 0xae8) = 0x3120208;
  }
  *(uint *)(param_1 + 0xaf0) = uVar6;
  uVar2 = 0x220401;
  if ((param_3 & 1) == 0) {
    uVar2 = 0x220001;
  }
  *(undefined4 *)(param_1 + 0xaf4) = uVar2;
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s: dfs:%d div:%d len:%d\n","i3c_setup_cfg0_tre",
                 iVar4,*(undefined1 *)(lVar8 + 8),uVar3);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"%s: dfs:%d div:%d len:%d\n","i3c_setup_cfg0_tre",*piVar1,
                  *(undefined1 *)(lVar8 + 8),uVar3);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                 "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                 "i3c_setup_cfg0_tre",*(undefined4 *)(param_1 + 0xae8),
                 *(undefined4 *)(param_1 + 0xaec),*(undefined4 *)(param_1 + 0xaf0),
                 *(undefined4 *)(param_1 + 0xaf4));
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                  "i3c_setup_cfg0_tre",*(undefined4 *)(param_1 + 0xae8),
                  *(undefined4 *)(param_1 + 0xaec),*(undefined4 *)(param_1 + 0xaf0),
                  *(undefined4 *)(param_1 + 0xaf4));
  }
  return;
}



//------------------------------------------------------------
// i3c_setup_go_tre @ 001099d4 size=640
// signature: undefined i3c_setup_go_tre(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

void i3c_setup_go_tre(long param_1,long param_2,int param_3,uint param_4,ulong param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  
  uVar2 = *(uint *)(param_2 + 8);
  uVar1 = 0x4000000;
  if (3 < *(int *)(param_1 + 0x53a0)) {
    uVar1 = (uVar2 & 4) << 0x18;
  }
  if ((param_5 & 1) == 0) {
    piVar13 = (int *)(param_1 + 0x5284);
  }
  else {
    if (0x1bf < (uint)(param_3 % 0x1c0)) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x109c54);
      (*pcVar10)();
    }
    piVar13 = (int *)(param_1 + (ulong)(uint)(param_3 % 0x1c0) * 4 + 0x2730);
  }
  uVar4 = uVar2 >> 0x10 & 0xff;
  uVar5 = uVar2 >> 9 & 0x7f;
  uVar6 = uVar2 >> 0x18 & 1;
  uVar7 = uVar2 >> 8 & 1;
  uVar8 = uVar2 >> 0x19 & 1;
  iVar3 = *piVar13;
  uVar9 = uVar2 >> 0x1a & 1;
  *(uint *)(param_1 + 0xad8) =
       *(uint *)(param_2 + 4) | uVar1 | (uVar2 >> 0x1a) << 0x1f | uVar4 << 0x10 | uVar5 << 8;
  *(uint *)(param_1 + 0xadc) = uVar7 << 2 | uVar6 << 1 | uVar8;
  *(int *)(param_1 + 0xae0) = iVar3;
  if (*(int *)(param_1 + 0x5280) == 1) {
    iVar12 = 0x200900;
    if ((*(char *)(param_1 + 0x5400) != '\0') &&
       (iVar12 = 0x200800, *(int *)(param_1 + 0x528c) + -1 != param_3)) {
      iVar12 = 0x200900;
    }
  }
  else {
    iVar11 = -0x4ff;
    if ((param_4 & 1) == 0) {
      iVar11 = -0x8ff;
    }
    iVar12 = 0x200200;
    if (iVar3 != 0) {
      iVar12 = iVar11 + 0x200900;
    }
  }
  *(int *)(param_1 + 0xae4) = iVar12;
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s cmd:0x%x param0x%x ccc:0x%x addr:0x%x\n",
                 "i3c_setup_go_tre",*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),uVar4,
                 uVar5);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"%s cmd:0x%x param0x%x ccc:0x%x addr:0x%x\n",
                  "i3c_setup_go_tre",*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),uVar4
                  ,uVar5);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                 "%s:use_7e:%d nack_ibi:%d cont_mod:%d, bypass addrspace:%d idx:%d gsi_bei:%d\n",
                 "i3c_setup_go_tre",uVar8,uVar6,uVar7,uVar9,param_3,param_4 & 1);
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "%s:use_7e:%d nack_ibi:%d cont_mod:%d, bypass addrspace:%d idx:%d gsi_bei:%d\n",
                  "i3c_setup_go_tre",uVar8,uVar6,uVar7,uVar9,param_3,param_4 & 1);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),
                 "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n","i3c_setup_go_tre",
                 *(undefined4 *)(param_1 + 0xad8),*(undefined4 *)(param_1 + 0xadc),
                 *(undefined4 *)(param_1 + 0xae0),*(undefined4 *)(param_1 + 0xae4));
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),
                  "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n","i3c_setup_go_tre"
                  ,*(undefined4 *)(param_1 + 0xad8),*(undefined4 *)(param_1 + 0xadc),
                  *(undefined4 *)(param_1 + 0xae0),*(undefined4 *)(param_1 + 0xae4));
  }
  return;
}



//------------------------------------------------------------
// geni_i3c_err_prep_sg @ 00109c54 size=292
// signature: undefined geni_i3c_err_prep_sg(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

int geni_i3c_err_prep_sg(long param_1)

{
  char *pcVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar1 = (char *)(param_1 + 0x5260);
  if ((*(int *)(param_1 + 0x68) == 0) && (*pcVar1 == '\0')) {
    return 0;
  }
  pcVar3 = *(code **)(**(long **)(param_1 + 0xa98) + 0x148);
  if (pcVar3 == (code *)0x0) {
    iVar2 = -0x26;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x109cac);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)();
    if (iVar2 == 0) goto LAB_00109cb8;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:gpi dma terminate failed ret:%d\n",
                 "geni_i3c_err_prep_sg",iVar2);
  if (*(long *)(param_1 + 8) == 0) {
    _printk(&DAT_0010d19c,"geni_i3c_err_prep_sg",iVar2);
  }
  else {
    _dev_err(*(long *)(param_1 + 8),"%s:gpi dma terminate failed ret:%d\n","geni_i3c_err_prep_sg",
             iVar2);
  }
  if (*(long *)(param_1 + 8) != 0) {
    i3c_trace_log(*(long *)(param_1 + 8),"%s:gpi dma terminate failed ret:%d\n",
                  "geni_i3c_err_prep_sg",iVar2);
  }
LAB_00109cb8:
  *(undefined1 *)(param_1 + 0x5261) = 0;
  if (*pcVar1 != '\0') {
    if (*(int *)(param_1 + 0x68) == 0) {
      iVar2 = -5;
      *(undefined4 *)(param_1 + 0x68) = 0xfffffffb;
    }
    *pcVar1 = '\0';
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_geni_i3c_ibi_unconf @ 00109d78 size=656
// signature: undefined qcom_geni_i3c_ibi_unconf(void)
// callers: [geni_i3c_remove, geni_i3c_master_free_ibi]
//------------------------------------------------------------

void qcom_geni_i3c_ibi_unconf(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  
  iVar1 = readl_relaxed(*(long *)(param_1 + 0x52b8) + 0x1018);
  if (iVar1 != 0) {
    lVar6 = *(long *)(param_1 + 0x9b0);
    if (lVar6 == 0) {
      uVar4 = 0xffffffffffffffea;
      iVar1 = *(int *)(param_1 + 0x52c0);
    }
    else if (*(int *)(param_1 + 0x9b8) == 0) {
      uVar4 = 0;
      iVar1 = *(int *)(param_1 + 0x52c0);
    }
    else {
      uVar4 = sched_clock();
      ipc_log_string(lVar6,"%s:start at %llu nsec(%llu usec)\n","qcom_deallocate_ibi_table_entry",
                     uVar4,uVar4 / 1000);
      iVar1 = *(int *)(param_1 + 0x52c0);
    }
    if (iVar1 != 0) {
      uVar7 = 0;
      iVar1 = 0x1800;
      do {
        *(undefined4 *)(param_1 + 0x5328) = 0;
        *(undefined4 *)(param_1 + 0x52d8) = 0;
        uVar2 = readl_relaxed(*(long *)(param_1 + 0x52b8) + (long)iVar1);
        if ((uVar2 & 1) != 0) {
          writel_relaxed(uVar2 & 0xfffffffe,*(long *)(param_1 + 0x52b8) + 0x1000);
          iVar3 = wait_for_completion_timeout(param_1 + 0x52d8,0xfa);
          if (iVar3 == 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"timeout while adding slave IBI\n");
            if (*(long *)(param_1 + 8) == 0) {
              _printk(&DAT_0010c806);
            }
            else {
              _dev_err(*(long *)(param_1 + 8),"timeout while adding slave IBI\n");
            }
            if (*(long *)(param_1 + 8) == 0) {
              return;
            }
            i3c_trace_log(*(long *)(param_1 + 8),"timeout while adding slave IBI\n");
            return;
          }
        }
        uVar7 = uVar7 + 1;
        iVar1 = iVar1 + 0x80;
      } while (uVar7 < *(uint *)(param_1 + 0x52c0));
    }
    lVar6 = *(long *)(param_1 + 0x9b0);
    if (((lVar6 != 0) && (uVar4 != 0)) && (*(int *)(param_1 + 0x9b8) != 0)) {
      lVar5 = sched_clock();
      ipc_log_string(lVar6,"%s:took %llu nsec(%llu usec)\n","qcom_deallocate_ibi_table_entry",
                     lVar5 - uVar4,(lVar5 - uVar4) / 1000);
    }
  }
  geni_i3c_enable_ibi_ctrl(param_1,0);
  writel_relaxed(0,*(long *)(param_1 + 0x52b8) + 0xc);
  writel_relaxed(0,*(long *)(param_1 + 0x52b8) + 0x1008);
  writel_relaxed(0,*(long *)(param_1 + 0x52b8) + 0x14);
  if (((*(char *)(param_1 + 0x533c) == '\0') || (*(char *)(param_1 + 0x533d) == '\0')) ||
     (iVar1 = geni_i3c_enable_naon_ibi_clks(param_1,0), iVar1 == 0)) {
    *(undefined1 *)(param_1 + 0x52b1) = 0;
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x9a8),"%s:  NAON clock failure\n",
                   "qcom_geni_i3c_ibi_unconf");
    if (*(long *)(param_1 + 8) == 0) {
      _printk(&DAT_0010b9fa,"qcom_geni_i3c_ibi_unconf");
    }
    else {
      _dev_err(*(long *)(param_1 + 8),"%s:  NAON clock failure\n","qcom_geni_i3c_ibi_unconf");
    }
    if (*(long *)(param_1 + 8) != 0) {
      i3c_trace_log(*(long *)(param_1 + 8),"%s:  NAON clock failure\n","qcom_geni_i3c_ibi_unconf");
    }
  }
  return;
}



//------------------------------------------------------------
// capture_kpi_show @ 0010a00c size=72
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
    iVar1 = scnprintf(param_3,4,&DAT_0010bdc2,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x9b8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// capture_kpi_store @ 0010a058 size=264
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
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_0010a114;
  }
  iVar1 = kstrtoint(param_3,0,(int *)(lVar4 + 0x9b8));
  if (iVar1 == 0) {
    if ((*(int *)(lVar4 + 0x9b8) == 0) || (*(long *)(lVar4 + 0x9b0) != 0)) goto LAB_0010a114;
    local_40 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_60 = 0;
    uStack_58 = 0;
    lVar3 = (*(long **)(lVar4 + 8))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(lVar4 + 8);
    }
    scnprintf(&local_60,0x24,&DAT_0010c190,lVar3,&DAT_0010bb18);
    lVar3 = ipc_log_context_create(4,&local_60,0);
    *(long *)(lVar4 + 0x9b0) = lVar3;
    if (lVar3 != 0) goto LAB_0010a114;
    pcVar2 = "Error creating kpi IPC logs\n";
  }
  else {
    param_4 = 0xffffffffffffffea;
    pcVar2 = "Invalid input\n";
  }
  _dev_err(param_1,pcVar2);
LAB_0010a114:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// geni_i3c_suspend_late @ 0010a164 size=584
// signature: undefined geni_i3c_suspend_late(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_suspend_late(long param_1)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *(long *)(param_1 + 0x98);
  lVar10 = *(long *)(lVar9 + 0x9b0);
  pcVar2 = (char *)(lVar9 + 0x533c);
  if (lVar10 == 0) {
    uVar7 = 0xffffffffffffffea;
    cVar3 = *pcVar2;
  }
  else if (*(int *)(lVar9 + 0x9b8) == 0) {
    uVar7 = 0;
    cVar3 = *pcVar2;
  }
  else {
    uVar7 = sched_clock();
    ipc_log_string(lVar10,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_suspend_late",uVar7,
                   uVar7 / 1000);
    cVar3 = *pcVar2;
  }
  if (((cVar3 == '\0') || (*(char *)(lVar9 + 0x533d) == '\0')) ||
     (iVar6 = geni_i3c_enable_naon_ibi_clks(lVar9,0), iVar6 == 0)) {
    if (*(int *)(param_1 + 0x20c) != 2) {
      ipc_log_string(*(undefined8 *)(lVar9 + 0x9a8),"%s: Forced suspend\n","geni_i3c_suspend_late");
      if (*(long *)(lVar9 + 8) != 0) {
        i3c_trace_log(*(long *)(lVar9 + 8),"%s: Forced suspend\n","geni_i3c_suspend_late");
      }
      geni_i3c_runtime_suspend(param_1);
      __pm_runtime_disable(param_1,1);
      piVar1 = (int *)(param_1 + 0x1f8);
      iVar6 = *(int *)(param_1 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          if (iVar4 != iVar6) goto LAB_0010a298;
          cVar3 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010a298:
        bVar5 = iVar6 != iVar4;
        iVar6 = iVar4;
      } while (bVar5);
      __pm_runtime_set_status(param_1,2);
      pm_runtime_enable(param_1);
    }
    lVar10 = *(long *)(lVar9 + 0x9b0);
    if (lVar10 != 0) {
      if (uVar7 == 0) {
        return 0;
      }
      if (*(int *)(lVar9 + 0x9b8) == 0) {
        return 0;
      }
      lVar9 = sched_clock(0);
      ipc_log_string(lVar10,"%s:took %llu nsec(%llu usec)\n","geni_i3c_suspend_late",lVar9 - uVar7,
                     (lVar9 - uVar7) / 1000);
    }
    uVar8 = 0;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x9a8),"%s:  NAON clock failure\n",
                   "geni_i3c_suspend_late");
    if (*(long *)(lVar9 + 8) == 0) {
      _printk(&DAT_0010b9fa,"geni_i3c_suspend_late");
    }
    else {
      _dev_err(*(long *)(lVar9 + 8),"%s:  NAON clock failure\n","geni_i3c_suspend_late");
    }
    if (*(long *)(lVar9 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar9 + 8),"%s:  NAON clock failure\n","geni_i3c_suspend_late");
    }
    uVar8 = 0xfffffff5;
  }
  return uVar8;
}



//------------------------------------------------------------
// geni_i3c_resume_early @ 0010a3c4 size=396
// signature: undefined geni_i3c_resume_early(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_i3c_resume_early(long param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x98);
  lVar7 = *(long *)(lVar6 + 0x9b0);
  pcVar1 = (char *)(lVar6 + 0x533c);
  if (lVar7 == 0) {
    uVar4 = 0xffffffffffffffea;
    cVar2 = *pcVar1;
  }
  else if (*(int *)(lVar6 + 0x9b8) == 0) {
    uVar4 = 0;
    cVar2 = *pcVar1;
  }
  else {
    uVar4 = sched_clock();
    ipc_log_string(lVar7,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_resume_early",uVar4,
                   uVar4 / 1000);
    cVar2 = *pcVar1;
  }
  if (((cVar2 == '\0') || (*(char *)(lVar6 + 0x533d) != '\0')) ||
     (iVar3 = geni_i3c_enable_naon_ibi_clks(lVar6,1), iVar3 == 0)) {
    lVar7 = *(long *)(lVar6 + 0x9b0);
    if (lVar7 != 0) {
      if (uVar4 == 0) {
        return 0;
      }
      if (*(int *)(lVar6 + 0x9b8) == 0) {
        return 0;
      }
      lVar6 = sched_clock(0);
      ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","geni_i3c_resume_early",lVar6 - uVar4,
                     (lVar6 - uVar4) / 1000);
    }
    uVar5 = 0;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x9a8),"%s:  NAON clock failure\n",
                   "geni_i3c_resume_early");
    if (*(long *)(lVar6 + 8) == 0) {
      _printk(&DAT_0010b9fa,"geni_i3c_resume_early");
    }
    else {
      _dev_err(*(long *)(lVar6 + 8),"%s:  NAON clock failure\n","geni_i3c_resume_early");
    }
    if (*(long *)(lVar6 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar6 + 8),"%s:  NAON clock failure\n","geni_i3c_resume_early");
    }
    uVar5 = 0xfffffff5;
  }
  return uVar5;
}



//------------------------------------------------------------
// geni_i3c_runtime_suspend @ 0010a554 size=732
// signature: undefined geni_i3c_runtime_suspend(void)
// callers: [geni_i3c_suspend_late]
//------------------------------------------------------------

undefined8 geni_i3c_runtime_suspend(long param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x98);
  lVar5 = *(long *)(lVar4 + 0x9b0);
  if (lVar5 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else if (*(int *)(lVar4 + 0x9b8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar5,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_runtime_suspend",uVar2,
                   uVar2 / 1000);
  }
  ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s(): ret:%d start\n","geni_i3c_runtime_suspend",0)
  ;
  if (*(long *)(lVar4 + 8) != 0) {
    i3c_trace_log(*(long *)(lVar4 + 8),"%s(): ret:%d start\n","geni_i3c_runtime_suspend",0);
  }
  if (*(int *)(lVar4 + 0x6c) == 3) {
    geni_i3c_gsi_stop_on_bus(lVar4);
    if (*(long **)(lVar4 + 0xa98) != (long *)0x0) {
      pcVar3 = *(code **)(**(long **)(lVar4 + 0xa98) + 0x138);
      if (pcVar3 == (code *)0x0) {
        iVar1 = -0x26;
      }
      else {
        if (*(int *)(pcVar3 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10a648);
          (*pcVar3)();
        }
        iVar1 = (*pcVar3)();
        if (iVar1 == 0) goto LAB_0010a660;
      }
      ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s failed: tx:%d is_suspend:%d\n",
                     "geni_i3c_gpi_pause_resume",iVar1,1);
      if (*(long *)(lVar4 + 8) != 0) {
        i3c_trace_log(*(long *)(lVar4 + 8),"%s failed: tx:%d is_suspend:%d\n",
                      "geni_i3c_gpi_pause_resume",iVar1,1);
      }
      ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s: ret:%d\n","geni_i3c_runtime_suspend",
                     0xffffffea);
      if (*(long *)(lVar4 + 8) == 0) {
        return 0xffffffea;
      }
      i3c_trace_log(*(long *)(lVar4 + 8),"%s: ret:%d\n","geni_i3c_runtime_suspend",0xffffffea);
      return 0xffffffea;
    }
  }
  else {
    disable_irq(*(undefined4 *)(lVar4 + 100));
  }
LAB_0010a660:
  iVar1 = geni_se_resources_off(lVar4);
  if (iVar1 != 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s geni_se_resources_off failed %d\n",
                   "geni_i3c_runtime_suspend",iVar1);
    if (*(long *)(lVar4 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar4 + 8),"%s geni_se_resources_off failed %d\n",
                    "geni_i3c_runtime_suspend",iVar1);
    }
  }
  iVar1 = geni_icc_disable(lVar4);
  if (iVar1 != 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s geni_icc_disable failed %d\n",
                   "geni_i3c_runtime_suspend",iVar1);
    if (*(long *)(lVar4 + 8) != 0) {
      i3c_trace_log(*(long *)(lVar4 + 8),"%s geni_icc_disable failed %d\n",
                    "geni_i3c_runtime_suspend",iVar1);
    }
  }
  ipc_log_string(*(undefined8 *)(lVar4 + 0x9a8),"%s():ret:%d\n","geni_i3c_runtime_suspend",iVar1);
  if (*(long *)(lVar4 + 8) != 0) {
    i3c_trace_log(*(long *)(lVar4 + 8),"%s():ret:%d\n","geni_i3c_runtime_suspend",iVar1);
  }
  lVar5 = *(long *)(lVar4 + 0x9b0);
  if (lVar5 != 0) {
    if (uVar2 == 0) {
      return 0;
    }
    if (*(int *)(lVar4 + 0x9b8) == 0) {
      return 0;
    }
    lVar4 = sched_clock();
    ipc_log_string(lVar5,"%s:took %llu nsec(%llu usec)\n","geni_i3c_runtime_suspend",lVar4 - uVar2,
                   (lVar4 - uVar2) / 1000);
  }
  return 0;
}



//------------------------------------------------------------
// geni_i3c_runtime_resume @ 0010a834 size=676
// signature: undefined geni_i3c_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int geni_i3c_runtime_resume(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  char *pcVar4;
  code *pcVar5;
  long *plVar6;
  long lVar7;
  
  plVar6 = *(long **)(param_1 + 0x98);
  lVar7 = plVar6[0x136];
  if (lVar7 == 0) {
    uVar2 = 0xffffffffffffffea;
  }
  else if ((int)plVar6[0x137] == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = sched_clock();
    ipc_log_string(lVar7,"%s:start at %llu nsec(%llu usec)\n","geni_i3c_runtime_resume",uVar2,
                   uVar2 / 1000);
  }
  iVar1 = geni_icc_enable(plVar6);
  if (iVar1 == 0) {
    iVar1 = geni_se_resources_on(plVar6);
    if (iVar1 == 0) {
      writel_relaxed(0x7f,*plVar6 + 0x24);
      __const_udelay(0xa7c6);
      if (*(int *)((long)plVar6 + 0x6c) == 3) {
        if ((long *)plVar6[0x153] != (long *)0x0) {
          pcVar5 = *(code **)(*(long *)plVar6[0x153] + 0x140);
          if (pcVar5 == (code *)0x0) {
            iVar1 = -0x26;
          }
          else {
            if (*(int *)(pcVar5 + -4) != 0xa8cee02) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10a9a0);
              (*pcVar5)();
            }
            iVar1 = (*pcVar5)();
            if (iVar1 == 0) goto LAB_0010a9b8;
          }
          ipc_log_string(plVar6[0x135],"%s failed: tx:%d is_suspend:%d\n",
                         "geni_i3c_gpi_pause_resume",iVar1,0);
          if (plVar6[1] != 0) {
            i3c_trace_log(plVar6[1],"%s failed: tx:%d is_suspend:%d\n","geni_i3c_gpi_pause_resume",
                          iVar1,0);
          }
          iVar1 = -0x16;
          ipc_log_string(plVar6[0x135],"%s: ret:%d\n","geni_i3c_runtime_resume",0xffffffea);
          lVar7 = plVar6[1];
          if (lVar7 == 0) {
            return -0x16;
          }
          pcVar4 = "%s: ret:%d\n";
          goto LAB_0010a934;
        }
      }
      else {
        enable_irq(*(undefined4 *)((long)plVar6 + 100));
      }
LAB_0010a9b8:
      ipc_log_string(plVar6[0x135],"%s(): ret:%d\n","geni_i3c_runtime_resume",0);
      if (plVar6[1] != 0) {
        i3c_trace_log(plVar6[1],"%s(): ret:%d\n","geni_i3c_runtime_resume",0);
      }
      lVar7 = plVar6[0x136];
      if (lVar7 != 0) {
        if (uVar2 == 0) {
          return 0;
        }
        if ((int)plVar6[0x137] == 0) {
          return 0;
        }
        lVar3 = sched_clock();
        ipc_log_string(lVar7,"%s:took %llu nsec(%llu usec)\n","geni_i3c_runtime_resume",
                       lVar3 - uVar2,(lVar3 - uVar2) / 1000);
      }
      return 0;
    }
    ipc_log_string(plVar6[0x135],"%s geni_se_resources_on failed %d\n","geni_i3c_runtime_resume",
                   iVar1);
    lVar7 = plVar6[1];
    if (lVar7 == 0) {
      return iVar1;
    }
    pcVar4 = "%s geni_se_resources_on failed %d\n";
  }
  else {
    ipc_log_string(plVar6[0x135],"%s geni_icc_enable failed %d\n","geni_i3c_runtime_resume",iVar1);
    lVar7 = plVar6[1];
    if (lVar7 == 0) {
      return iVar1;
    }
    pcVar4 = "%s geni_icc_enable failed %d\n";
  }
LAB_0010a934:
  i3c_trace_log(lVar7,pcVar4,"geni_i3c_runtime_resume",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010ab2c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&geni_i3c_master,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010ab5c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&geni_i3c_master);
  return;
}



//------------------------------------------------------------
// strlen @ 00111000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_i3c_log_info, perf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00111008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00111010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_i3c_log_info, perf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 00111018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [trace_event_raw_event_i3c_log_info, perf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00111020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00111028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00111030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_i3c_log_info, qcom_geni_i3c_conf, geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers, capture_kpi_store, i3c_trace_log, perf_trace_i3c_log_info, geni_i3c_master_bus_init, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00111038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00111040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00111048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00111068 size=1
// signature: undefined ipc_log_string(void)
// callers: [geni_i3c_master_priv_xfers, geni_i3c_se_dump_dbg_regs, gi3c_gsi_cb_err, geni_i3c_get_ver_info, geni_i3c_enable_ibi_ctrl, i3c_setup_cfg0_tre, geni_i3c_enable_naon_ibi_clks, geni_i3c_err_prep_sg, geni_i3c_probe, geni_i3c_master_i2c_xfers, geni_i3c_master_reattach_i3c_dev, geni_i3c_master_supports_ccc_cmd, geni_i3c_gsi_stop_on_bus, geni_i3c_err, geni_i3c_master_request_ibi, geni_i3c_master_detach_i3c_dev, geni_i3c_master_send_ccc_cmd, geni_i3c_ibi_irq, qcom_geni_i3c_ibi_conf, gi3c_gsi_tx_cb, geni_i3c_master_enable_ibi, geni_i3c_master_attach_i2c_dev, geni_i3c_irq, geni_i3c_runtime_suspend, geni_i3c_resume_early, i3c_ibi_rsrcs_init, i3c_geni_execute_write_command, geni_i3c_remove, gi3c_gsi_rx_cb, qcom_geni_i3c_conf, i3c_geni_execute_read_command, geni_i3c_master_free_ibi, geni_i3c_master_disable_ibi, i3c_naon_ibi_clk_init, geni_i3c_master_detach_i2c_dev, geni_i3c_runtime_resume, i3c_geni_runtime_get_mutex_lock, geni_i3c_fifo_dma_xfer, gi3c_ev_cb, geni_i3c_enable_hotjoin_irq, geni_i3c_gsi_se_init, geni_i3c_master_bus_init, geni_i3c_master_attach_i3c_dev, geni_i3c_hotjoin, geni_i3c_dump_dbg_regs, qcom_geni_i3c_ibi_unconf, geni_i3c_suspend_late, i3c_setup_go_tre, geni_i3c_master_recycle_ibi_slot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00111070 size=1
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
// platform_driver_unregister @ 00111078 size=1
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
// trace_raw_output_prep @ 00111080 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00111088 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00111090 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_i3c_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00111098 size=1
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
// log_post_read_mmio @ 001110a0 size=1
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
// devm_kmalloc @ 001110a8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [geni_i3c_master_attach_i2c_dev, geni_i3c_gsi_se_init, geni_i3c_probe, i3c_ibi_rsrcs_init, geni_i3c_master_attach_i3c_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001110b0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [capture_kpi_store, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 001110b8 size=1
// signature: undefined devm_regulator_get(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001110c0 size=1
// signature: undefined regulator_enable(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001110c8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 001110d0 size=1
// signature: undefined platform_get_resource(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001110d8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001110e0 size=1
// signature: undefined devm_clk_get(void)
// callers: [i3c_naon_ibi_clk_init, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001110e8 size=1
// signature: undefined platform_get_irq(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001110f0 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001110f8 size=1
// signature: undefined __mutex_init(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 00111100 size=1
// signature: undefined irq_modify_status(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00111108 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_u32_array @ 00111110 size=1
// signature: undefined device_property_read_u32_array(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_get @ 00111118 size=1
// signature: undefined geni_icc_get(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00111120 size=1
// signature: undefined icc_set_bw(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00111128 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00111130 size=1
// signature: undefined _dev_info(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00111138 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_enable @ 00111140 size=1
// signature: undefined geni_icc_enable(void)
// callers: [geni_i3c_runtime_resume, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_resources_on @ 00111148 size=1
// signature: undefined geni_se_resources_on(void)
// callers: [geni_i3c_runtime_resume, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00111150 size=1
// signature: undefined _printk(void)
// callers: [geni_i3c_master_priv_xfers, gi3c_gsi_tx_cb, geni_i3c_master_enable_ibi, geni_i3c_resume_early, i3c_ibi_rsrcs_init, i3c_geni_execute_write_command, gi3c_gsi_rx_cb, i3c_geni_execute_read_command, geni_i3c_master_disable_ibi, i3c_naon_ibi_clk_init, geni_i3c_enable_ibi_ctrl, geni_i3c_enable_naon_ibi_clks, geni_i3c_err_prep_sg, i3c_geni_runtime_get_mutex_lock, geni_i3c_probe, geni_i3c_fifo_dma_xfer, geni_i3c_enable_hotjoin_irq, geni_i3c_gsi_se_init, geni_i3c_master_request_ibi, geni_i3c_master_bus_init, geni_i3c_hotjoin, geni_i3c_master_send_ccc_cmd, qcom_geni_i3c_ibi_unconf, geni_i3c_ibi_irq, geni_i3c_suspend_late, qcom_geni_i3c_ibi_conf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00111158 size=1
// signature: undefined of_find_property(void)
// callers: [geni_i3c_probe, i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00111160 size=1
// signature: undefined _dev_err(void)
// callers: [geni_i3c_master_priv_xfers, geni_i3c_master_enable_ibi, geni_i3c_resume_early, i3c_ibi_rsrcs_init, i3c_geni_execute_write_command, i3c_geni_execute_read_command, geni_i3c_master_disable_ibi, i3c_naon_ibi_clk_init, geni_i3c_enable_ibi_ctrl, geni_i3c_enable_naon_ibi_clks, geni_i3c_err_prep_sg, i3c_geni_runtime_get_mutex_lock, geni_i3c_probe, geni_i3c_fifo_dma_xfer, geni_i3c_enable_hotjoin_irq, geni_i3c_gsi_se_init, geni_i3c_master_request_ibi, geni_i3c_master_bus_init, geni_i3c_hotjoin, geni_i3c_master_send_ccc_cmd, qcom_geni_i3c_ibi_unconf, capture_kpi_store, geni_i3c_ibi_irq, geni_i3c_suspend_late, qcom_geni_i3c_ibi_conf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00111168 size=1
// signature: undefined ___ratelimit(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_init @ 00111170 size=1
// signature: undefined geni_se_init(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_config_packing @ 00111178 size=1
// signature: undefined geni_se_config_packing(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_config_packing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_resources_off @ 00111180 size=1
// signature: undefined geni_se_resources_off(void)
// callers: [geni_i3c_runtime_suspend, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_resources_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_icc_disable @ 00111188 size=1
// signature: undefined geni_icc_disable(void)
// callers: [geni_i3c_runtime_suspend, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_icc_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00111190 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [geni_i3c_suspend_late, i3c_geni_runtime_get_mutex_lock, geni_i3c_master_bus_init, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00111198 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 001111a0 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 001111a8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [geni_i3c_suspend_late, geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_register @ 001111b0 size=1
// signature: undefined i3c_master_register(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001111b8 size=1
// signature: undefined wakeup_source_register(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001111c0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001111c8 size=1
// signature: undefined device_create_file(void)
// callers: [geni_i3c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001111d0 size=1
// signature: undefined destroy_workqueue(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 001111d8 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_force_suspend @ 001111e0 size=1
// signature: undefined pm_runtime_force_suspend(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_force_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 001111e8 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_unregister @ 001111f0 size=1
// signature: undefined i3c_master_unregister(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001111f8 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [geni_i3c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00111200 size=1
// signature: undefined sched_clock(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_reattach_i3c_dev, geni_i3c_master_supports_ccc_cmd, geni_i3c_master_priv_xfers, geni_i3c_master_enable_ibi, geni_i3c_master_attach_i2c_dev, geni_i3c_irq, geni_i3c_master_request_ibi, geni_i3c_runtime_suspend, geni_i3c_resume_early, geni_i3c_master_bus_init, geni_i3c_master_attach_i3c_dev, geni_i3c_hotjoin, geni_i3c_master_detach_i3c_dev, geni_i3c_master_free_ibi, geni_i3c_master_disable_ibi, geni_i3c_master_send_ccc_cmd, qcom_geni_i3c_ibi_unconf, geni_i3c_ibi_irq, geni_i3c_master_detach_i2c_dev, geni_i3c_suspend_late, geni_i3c_runtime_resume, geni_i3c_master_recycle_ibi_slot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00111208 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [geni_i3c_master_free_ibi, geni_i3c_ibi_irq, geni_i3c_irq, geni_i3c_master_request_ibi, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00111210 size=1
// signature: undefined complete(void)
// callers: [geni_i3c_ibi_irq, geni_i3c_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00111218 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [geni_i3c_master_free_ibi, geni_i3c_ibi_irq, geni_i3c_irq, geni_i3c_master_request_ibi, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_get_qup_hw_version @ 00111220 size=1
// signature: undefined geni_se_get_qup_hw_version(void)
// callers: [geni_se_get_tx_fifo_depth, geni_i3c_get_ver_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_get_qup_hw_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_select_mode @ 00111228 size=1
// signature: undefined geni_se_select_mode(void)
// callers: [geni_i3c_gsi_se_init, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_select_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00111230 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_qup_write @ 00111238 size=1
// signature: undefined msm_qup_write(void)
// callers: [i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_qup_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00111240 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [i3c_ibi_rsrcs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00111248 size=1
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
// log_post_write_mmio @ 00111250 size=1
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
// gsi_common_fill_tre_buf @ 00111258 size=1
// signature: undefined gsi_common_fill_tre_buf(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, geni_i3c_gsi_stop_on_bus, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gsi_common_fill_tre_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gsi_common_prep_desc_and_submit @ 00111260 size=1
// signature: undefined gsi_common_prep_desc_and_submit(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, geni_i3c_gsi_stop_on_bus, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gsi_common_prep_desc_and_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00111268 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [i3c_geni_execute_read_command, qcom_geni_i3c_ibi_unconf, geni_i3c_gsi_stop_on_bus, geni_i3c_enable_ibi_ctrl, geni_i3c_master_request_ibi, i3c_geni_execute_write_command, geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00111270 size=1
// signature: undefined pm_stay_awake(void)
// callers: [geni_i3c_hotjoin]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_do_daa @ 00111278 size=1
// signature: undefined i3c_master_do_daa(void)
// callers: [geni_i3c_hotjoin]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_do_daa(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00111280 size=1
// signature: undefined pm_relax(void)
// callers: [geni_i3c_hotjoin]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpi_dump_for_geni @ 00111288 size=1
// signature: undefined gpi_dump_for_geni(void)
// callers: [geni_i3c_dump_dbg_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpi_dump_for_geni(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00111298 size=1
// signature: undefined complete_all(void)
// callers: [gi3c_gsi_rx_cb, gi3c_ev_cb, gi3c_gsi_tx_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 001112a0 size=1
// signature: undefined clk_set_rate(void)
// callers: [qcom_geni_i3c_conf, i3c_naon_ibi_clk_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001112a8 size=1
// signature: undefined clk_disable(void)
// callers: [geni_i3c_enable_naon_ibi_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001112b0 size=1
// signature: undefined clk_unprepare(void)
// callers: [geni_i3c_enable_naon_ibi_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001112b8 size=1
// signature: undefined clk_prepare(void)
// callers: [geni_i3c_enable_naon_ibi_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001112c0 size=1
// signature: undefined clk_enable(void)
// callers: [geni_i3c_enable_naon_ibi_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001112c8 size=1
// signature: undefined queue_work_on(void)
// callers: [geni_i3c_ibi_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_queue_ibi @ 001112d0 size=1
// signature: undefined i3c_master_queue_ibi(void)
// callers: [geni_i3c_ibi_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_queue_ibi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_generic_ibi_get_free_slot @ 001112d8 size=1
// signature: undefined i3c_generic_ibi_get_free_slot(void)
// callers: [geni_i3c_ibi_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_generic_ibi_get_free_slot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001112e0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [geni_i3c_ibi_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001112e8 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [i3c_geni_runtime_get_mutex_lock, geni_i3c_master_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_get_free_addr @ 001112f0 size=1
// signature: undefined i3c_master_get_free_addr(void)
// callers: [geni_i3c_master_send_ccc_cmd, geni_i3c_master_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_get_free_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_set_info @ 001112f8 size=1
// signature: undefined i3c_master_set_info(void)
// callers: [geni_i3c_master_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_set_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00111300 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [geni_i3c_master_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_entdaa_locked @ 00111308 size=1
// signature: undefined i3c_master_entdaa_locked(void)
// callers: [geni_i3c_master_do_daa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_entdaa_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_add_i3c_dev_locked @ 00111310 size=1
// signature: undefined i3c_master_add_i3c_dev_locked(void)
// callers: [geni_i3c_master_do_daa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_add_i3c_dev_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_enec_locked @ 00111318 size=1
// signature: undefined i3c_master_enec_locked(void)
// callers: [geni_i3c_master_enable_ibi, geni_i3c_master_do_daa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_enec_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00111328 size=1
// signature: undefined kmalloc_trace(void)
// callers: [geni_i3c_master_send_ccc_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00111330 size=1
// signature: undefined kfree(void)
// callers: [geni_i3c_master_send_ccc_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 00111338 size=1
// signature: undefined __sw_hweight8(void)
// callers: [geni_i3c_master_send_ccc_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00111340 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 00111348 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00111350 size=1
// signature: undefined mutex_unlock(void)
// callers: [geni_i3c_master_i2c_xfers, geni_i3c_master_send_ccc_cmd, geni_i3c_master_priv_xfers, i3c_geni_runtime_get_mutex_lock, geni_i3c_master_request_ibi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpi_update_multi_desc_flag @ 00111358 size=1
// signature: undefined gpi_update_multi_desc_flag(void)
// callers: [geni_i3c_master_priv_xfers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpi_update_multi_desc_flag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_gsi_common_request_channel @ 00111360 size=1
// signature: undefined geni_gsi_common_request_channel(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_gsi_common_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00111368 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00111370 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gsi_common_tx_tre_optimization @ 00111378 size=1
// signature: undefined gsi_common_tx_tre_optimization(void)
// callers: [geni_i3c_master_priv_xfers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gsi_common_tx_tre_optimization(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gsi_common_tre_process @ 00111380 size=1
// signature: undefined gsi_common_tre_process(void)
// callers: [geni_i3c_master_priv_xfers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gsi_common_tre_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 00111388 size=1
// signature: undefined dev_driver_string(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00111390 size=1
// signature: undefined __warn_printk(void)
// callers: [i3c_geni_execute_read_command, geni_i3c_master_priv_xfers, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00111398 size=1
// signature: undefined mutex_lock(void)
// callers: [i3c_geni_runtime_get_mutex_lock, geni_i3c_master_request_ibi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_generic_ibi_alloc_pool @ 001113a0 size=1
// signature: undefined i3c_generic_ibi_alloc_pool(void)
// callers: [geni_i3c_master_request_ibi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_generic_ibi_alloc_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_generic_ibi_free_pool @ 001113a8 size=1
// signature: undefined i3c_generic_ibi_free_pool(void)
// callers: [geni_i3c_master_free_ibi, geni_i3c_master_request_ibi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_generic_ibi_free_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_master_disec_locked @ 001113b0 size=1
// signature: undefined i3c_master_disec_locked(void)
// callers: [geni_i3c_master_disable_ibi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_master_disec_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i3c_generic_ibi_recycle_slot @ 001113b8 size=1
// signature: undefined i3c_generic_ibi_recycle_slot(void)
// callers: [geni_i3c_master_recycle_ibi_slot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i3c_generic_ibi_recycle_slot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_clk_freq_match @ 001113c0 size=1
// signature: undefined geni_se_clk_freq_match(void)
// callers: [qcom_geni_i3c_conf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_clk_freq_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 001113c8 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [i3c_geni_execute_read_command, i3c_geni_execute_write_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_prep @ 001113d0 size=1
// signature: undefined geni_se_rx_dma_prep(void)
// callers: [geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_prep @ 001113d8 size=1
// signature: undefined geni_se_tx_dma_prep(void)
// callers: [geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_rx_dma_unprep @ 001113e0 size=1
// signature: undefined geni_se_rx_dma_unprep(void)
// callers: [geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_rx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// geni_se_tx_dma_unprep @ 001113e8 size=1
// signature: undefined geni_se_tx_dma_unprep(void)
// callers: [geni_i3c_fifo_dma_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void geni_se_tx_dma_unprep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001113f0 size=1
// signature: undefined scnprintf(void)
// callers: [capture_kpi_store, capture_kpi_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001113f8 size=1
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
// __pm_runtime_disable @ 00111400 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [geni_i3c_suspend_late]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00111408 size=1
// signature: undefined disable_irq(void)
// callers: [geni_i3c_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00111410 size=1
// signature: undefined __const_udelay(void)
// callers: [geni_i3c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00111418 size=1
// signature: undefined enable_irq(void)
// callers: [geni_i3c_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



