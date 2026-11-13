// Decompiled by Ghidra 12.2
// Program: bam_dma.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_bam_dma_info @ 001007ec size=116
// signature: undefined __traceiter_bam_dma_info(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_bam_dma_info(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00103908;
  plVar2 = DAT_00103908;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10083c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_bam_dma_info @ 00100864 size=312
// signature: undefined trace_event_raw_event_bam_dma_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_bam_dma_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100998);
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
// perf_trace_bam_dma_info @ 001009a4 size=388
// signature: undefined perf_trace_bam_dma_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_bam_dma_info(long param_1,char *param_2,undefined8 *param_3)

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
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100b24);
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
// __bpf_trace_bam_dma_info @ 00100b30 size=28
// signature: undefined __bpf_trace_bam_dma_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_bam_dma_info(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// trace_raw_output_bam_dma_info @ 00100b50 size=112
// signature: undefined trace_raw_output_bam_dma_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_bam_dma_info(long param_1,undefined8 param_2,undefined8 param_3)

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
// bam_dma_probe @ 00100bc4 size=1788
// signature: undefined bam_dma_probe(void)
// callers: []
//------------------------------------------------------------

ulong bam_dma_probe(long param_1)

{
  ulong *puVar1;
  ulong *puVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  long lVar9;
  ulong uVar10;
  long *plVar11;
  ulong uVar12;
  undefined8 uVar13;
  char *pcVar14;
  ulong uVar15;
  
  uVar15 = param_1 + 0x10;
  puVar8 = (ulong *)devm_kmalloc(uVar15,0x218,0xdc0);
  if (puVar8 == (ulong *)0x0) {
    uVar10 = 0xfffffff4;
    goto LAB_00101158;
  }
  uVar13 = *(undefined8 *)(param_1 + 0x2f8);
  puVar8[1] = uVar15;
  lVar9 = of_match_node(&bam_of_match,uVar13);
  if (lVar9 == 0) {
    pcVar14 = "Unsupported BAM module\n";
  }
  else {
    puVar8[0x36] = *(ulong *)(lVar9 + 0xc0);
    uVar10 = ipc_log_context_create(1,"dma_bam_log",0);
    puVar8[0x42] = uVar10;
    if (uVar10 == 0) {
      _dev_err(puVar8[1],"Failed to create dma bam log\n");
      uVar10 = puVar8[0x42];
      if (uVar10 != 0) goto LAB_00100c40;
    }
    else {
LAB_00100c40:
      ipc_log_string(uVar10,"%s start %d\n","bam_dma_probe",1);
    }
    __ftrace_dbg(puVar8[1],"%s start %d\n","bam_dma_probe",1);
    uVar13 = platform_get_resource(param_1,0x200,0);
    uVar10 = devm_ioremap_resource(uVar15,uVar13);
    *puVar8 = uVar10;
    if (0xfffffffffffff000 < uVar10) goto LAB_00101158;
    *(undefined1 *)((long)puVar8 + 0x20c) = 0;
    plVar11 = (long *)platform_get_resource_byname(param_1,0x200,"bam_remote_mem");
    if (plVar11 != (long *)0x0) {
      *(undefined1 *)((long)puVar8 + 0x20c) = 1;
      *(int *)(puVar8 + 0x41) = (int)*plVar11;
      uVar10 = devm_ioremap(uVar15,*plVar11,(plVar11[1] - *plVar11) + 1);
      puVar8[0x3f] = uVar10;
      if (uVar10 == 0) {
        _dev_err(uVar15,"Remote mem ioremap failed\n");
        uVar10 = 0xfffffff4;
        goto LAB_00101158;
      }
      puVar8[0x40] = uVar10;
      puVar8[0x3e] = (ulong)plVar11;
    }
    iVar6 = dma_set_mask(uVar15,0xffffffff);
    if (iVar6 == 0) {
      dma_set_coherent_mask(uVar15,0xffffffff);
      uVar7 = platform_get_irq(param_1,0);
      *(uint *)(puVar8 + 0x38) = uVar7;
      if ((int)uVar7 < 0) {
        uVar10 = (ulong)uVar7;
        goto LAB_00101158;
      }
      uVar7 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,ee",puVar8 + 0x34,1,0);
      if ((int)uVar7 < 0) {
        uVar10 = (ulong)uVar7;
        _dev_err(puVar8[1],"Execution environment unspecified\n");
        goto LAB_00101158;
      }
      lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,controlled-remotely",0);
      uVar13 = *(undefined8 *)(param_1 + 0x2f8);
      *(bool *)((long)puVar8 + 0x1a4) = lVar9 != 0;
      lVar9 = of_find_property(uVar13,"qcom,powered-remotely",0);
      *(bool *)((long)puVar8 + 0x1a5) = lVar9 != 0;
      if ((*(char *)((long)puVar8 + 0x1a4) == '\0') && (lVar9 == 0)) {
LAB_00100da4:
        uVar10 = devm_clk_get(puVar8[1],"bam_clk");
      }
      else {
        uVar7 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"num-channels",puVar8 + 0x33,1,0);
        if ((int)uVar7 < 0) {
          uVar10 = (ulong)uVar7;
          _dev_err(puVar8[1],"num-channels unspecified in dt\n");
          goto LAB_00101158;
        }
        uVar7 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,num-ees",(long)puVar8 + 0x19c,1,0)
        ;
        if ((int)uVar7 < 0) {
          uVar10 = (ulong)uVar7;
          _dev_err(puVar8[1],"num-ees unspecified in dt\n");
          goto LAB_00101158;
        }
        if ((*(char *)((long)puVar8 + 0x1a4) == '\0') && (*(char *)((long)puVar8 + 0x1a5) == '\0'))
        goto LAB_00100da4;
        uVar10 = devm_clk_get_optional(puVar8[1],"bam_clk");
      }
      puVar8[0x37] = uVar10;
      if (uVar10 < 0xfffffffffffff001) {
        uVar7 = clk_prepare(uVar10);
        if (uVar7 == 0) {
          uVar7 = clk_enable(uVar10);
          if (uVar7 == 0) {
            uVar7 = *(uint *)((long)puVar8 + 0x19c);
            if (uVar7 == 0) {
              uVar7 = readl_relaxed(*puVar8 + (ulong)*(uint *)(puVar8[0x36] + 0x10) +
                                    (ulong)(uint)((int)puVar8[0x34] * *(int *)(puVar8[0x36] + 0x1c))
                                   );
              uVar7 = uVar7 >> 8 & 0xf;
              *(uint *)((long)puVar8 + 0x19c) = uVar7;
            }
            uVar3 = (uint)puVar8[0x34];
            if (uVar3 < uVar7) {
              if ((int)puVar8[0x33] == 0) {
                uVar7 = readl_relaxed(*puVar8 + (ulong)*(uint *)(puVar8[0x36] + 0x20) +
                                      (ulong)(*(int *)(puVar8[0x36] + 0x2c) * uVar3));
                *(uint *)(puVar8 + 0x33) = uVar7 & 0xff;
              }
              if ((*(char *)((long)puVar8 + 0x1a4) == '\0') &&
                 (*(char *)((long)puVar8 + 0x1a5) == '\0')) {
                bam_reset(puVar8);
              }
              if (puVar8[0x42] != 0) {
                ipc_log_string(puVar8[0x42],"%s ret:%d\n","bam_init",0);
              }
              __ftrace_dbg(puVar8[1],"%s ret:%d\n","bam_init",0);
              tasklet_setup(puVar8 + 0x39,dma_tasklet);
              uVar10 = devm_kmalloc(puVar8[1],(ulong)(uint)puVar8[0x33] * 0x198,0xdc0);
              puVar8[0x32] = uVar10;
              if (uVar10 == 0) {
                uVar10 = 0xfffffff4;
              }
              else {
                puVar1 = puVar8 + 2;
                puVar8[4] = (ulong)(puVar8 + 4);
                puVar8[5] = (ulong)(puVar8 + 4);
                if ((int)puVar8[0x33] != 0) {
                  uVar7 = 0;
                  do {
                    lVar9 = puVar8[0x32] + (long)(int)uVar7 * 0x198;
                    *(uint *)(lVar9 + 0x108) = uVar7;
                    *(ulong **)(lVar9 + 0x100) = puVar8;
                    vchan_init(lVar9,puVar1);
                    *(code **)(lVar9 + 0x98) = bam_dma_free_desc;
                    uVar7 = uVar7 + 1;
                    *(long *)(lVar9 + 0x178) = lVar9 + 0x178;
                    *(long *)(lVar9 + 0x180) = lVar9 + 0x178;
                  } while (uVar7 < (uint)puVar8[0x33]);
                }
                uVar12 = devm_request_threaded_irq
                                   (puVar8[1],(int)puVar8[0x38],bam_dma_irq,0,4,"bam_dma",puVar8);
                uVar10 = uVar12 & 0xffffffff;
                if ((int)uVar12 == 0) {
                  uVar10 = puVar8[1];
                  puVar8[0x10] = uVar10;
                  if (*(undefined4 **)(uVar10 + 0x2b8) == (undefined4 *)0x0) {
                    _dev_err(uVar10,"cannot set maximum segment size\n");
                    uVar10 = 0xfffffffb;
                  }
                  else {
                    **(undefined4 **)(uVar10 + 0x2b8) = 0x7ff8;
                    *(ulong **)(param_1 + 0xa8) = puVar8;
                    puVar8[0xb] = 0;
                    puVar2 = puVar8 + 0xb;
                    Hint_Prefetch(puVar2,2,0,1);
                    do {
                      cVar4 = '\x01';
                      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                      if (bVar5) {
                        *puVar2 = *puVar2 | 0x400;
                        cVar4 = ExclusiveMonitorsStatus();
                      }
                    } while (cVar4 != '\0');
                    *(undefined4 *)(puVar8 + 0x15) = 6;
                    *(undefined4 *)((long)puVar8 + 0xbc) = 1;
                    puVar8[0x14] = 0x400000004;
                    puVar8[0x1a] = (ulong)bam_free_chan;
                    puVar8[0x18] = (ulong)bam_alloc_chan;
                    puVar8[0x23] = (ulong)bam_prep_slave_sg;
                    puVar8[0x2d] = (ulong)bam_tx_status;
                    puVar8[0x2e] = (ulong)bam_issue_pending;
                    puVar8[0x28] = (ulong)bam_slave_config;
                    puVar8[0x29] = (ulong)bam_pause;
                    puVar8[0x2a] = (ulong)bam_resume;
                    puVar8[0x2b] = (ulong)bam_dma_terminate_all;
                    puVar8[0x10] = puVar8[1];
                    uVar7 = dma_async_device_register(puVar1);
                    if (uVar7 == 0) {
                      uVar7 = of_dma_controller_register
                                        (*(undefined8 *)(param_1 + 0x2f8),bam_dma_xlate,puVar1);
                      if (uVar7 == 0) {
                        pm_runtime_irq_safe(uVar15);
                        pm_runtime_set_autosuspend_delay(uVar15,100);
                        __pm_runtime_use_autosuspend(uVar15,1);
                        uVar13 = ktime_get_mono_fast_ns();
                        *(undefined8 *)(param_1 + 0x230) = uVar13;
                        __pm_runtime_set_status(uVar15,0);
                        pm_runtime_enable(uVar15);
                        if (puVar8[0x42] != 0) {
                          ipc_log_string(puVar8[0x42],"%s end ret:%d\n","bam_dma_probe",0);
                        }
                        __ftrace_dbg(puVar8[1],"%s end ret:%d\n","bam_dma_probe",0);
                        uVar10 = 0;
                        goto LAB_00101158;
                      }
                      uVar10 = (ulong)uVar7;
                      dma_async_device_unregister(puVar1);
                    }
                    else {
                      uVar10 = (ulong)uVar7;
                      _dev_err(puVar8[1],"failed to register dma async device\n");
                    }
                  }
                }
                if ((int)puVar8[0x33] != 0) {
                  uVar7 = 0;
                  do {
                    tasklet_kill(puVar8[0x32] + (long)(int)uVar7 * 0x198 + 0x70);
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < (uint)puVar8[0x33]);
                }
              }
              tasklet_kill(puVar8 + 0x39);
            }
            else {
              uVar10 = 0xffffffea;
            }
            uVar15 = puVar8[0x37];
            clk_disable(uVar15);
            clk_unprepare(uVar15);
            goto LAB_00101158;
          }
          clk_unprepare(uVar10);
        }
        uVar10 = (ulong)uVar7;
        _dev_err(puVar8[1],"failed to prepare/enable clock\n");
      }
      else {
        uVar10 = uVar10 & 0xffffffff;
      }
      goto LAB_00101158;
    }
    pcVar14 = "Could not set 32 bit mask\n";
  }
  _dev_err(uVar15,pcVar14);
  uVar10 = 0xffffffed;
LAB_00101158:
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// bam_dma_remove @ 001012d0 size=364
// signature: undefined bam_dma_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_dma_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  
  plVar3 = *(long **)(param_1 + 0xa8);
  if (plVar3[0x42] != 0) {
    ipc_log_string(plVar3[0x42],"%s ret:%d\n","bam_dma_remove",0);
  }
  __ftrace_dbg(plVar3[1],"%s ret:%d\n","bam_dma_remove",0);
  if (plVar3[0x42] != 0) {
    ipc_log_context_destroy();
  }
  pm_runtime_force_suspend(param_1 + 0x10);
  of_dma_controller_free(*(undefined8 *)(param_1 + 0x2f8));
  dma_async_device_unregister(plVar3 + 2);
  writel_relaxed(0,*plVar3 + (ulong)*(uint *)(plVar3[0x36] + 0xc0) +
                   (ulong)(uint)((int)plVar3[0x34] * *(int *)(plVar3[0x36] + 0xcc)));
  devm_free_irq(plVar3[1],(int)plVar3[0x38],plVar3);
  if ((int)plVar3[0x33] != 0) {
    lVar4 = 0;
    uVar5 = 0;
    do {
      bam_dma_terminate_all(plVar3[0x32] + lVar4);
      tasklet_kill(plVar3[0x32] + lVar4 + 0x70);
      lVar2 = *(long *)(plVar3[0x32] + lVar4 + 0x158);
      if (lVar2 != 0) {
        uVar1 = 0x8000;
        if (*(char *)((long)plVar3 + 0x20c) != '\0') {
          uVar1 = 0x100;
        }
        dma_free_attrs(plVar3[1],uVar1,lVar2,*(undefined8 *)(plVar3[0x32] + lVar4 + 0x160),4);
      }
      uVar5 = uVar5 + 1;
      lVar4 = lVar4 + 0x198;
    } while (uVar5 < *(uint *)(plVar3 + 0x33));
  }
  tasklet_kill(plVar3 + 0x39);
  lVar4 = plVar3[0x37];
  clk_disable(lVar4);
  clk_unprepare(lVar4);
  return 0;
}



//------------------------------------------------------------
// __ftrace_dbg @ 0010143c size=136
// signature: undefined __ftrace_dbg(void)
// callers: [bam_slave_config, bam_alloc_chan, bam_dma_suspend, bam_issue_pending, bam_start_dma, bam_chan_init_hw, bam_resume, bam_dma_resume, bam_dma_xlate, bam_pause, bam_prep_slave_sg, bam_dma_remove, bam_dma_terminate_all, bam_dma_probe, bam_free_chan, bam_tx_status]
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
// dma_tasklet @ 00101568 size=208
// signature: undefined dma_tasklet(void)
// callers: []
//------------------------------------------------------------

void dma_tasklet(long param_1)

{
  long lVar1;
  ushort uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  
  if (*(int *)(param_1 + -0x30) != 0) {
    lVar4 = 0;
    uVar5 = 0;
    do {
      lVar1 = *(long *)(param_1 + -0x38) + lVar4;
      uVar3 = _raw_spin_lock_irqsave(lVar1 + 0xa0);
      if ((long *)(lVar1 + 200) != *(long **)(lVar1 + 200)) {
        uVar2 = 0xfff;
        if (*(char *)(param_1 + 0x44) != '\0') {
          uVar2 = 0x1f;
        }
        if ((uVar2 & ~*(ushort *)(lVar1 + 0x16a) + *(short *)(lVar1 + 0x168)) != 0) {
          bam_start_dma(lVar1);
        }
      }
      _raw_spin_unlock_irqrestore(lVar1 + 0xa0,uVar3);
      uVar5 = uVar5 + 1;
      lVar4 = lVar4 + 0x198;
    } while (uVar5 < *(uint *)(param_1 + -0x30));
  }
  return;
}



//------------------------------------------------------------
// bam_dma_irq @ 0010163c size=1020
// signature: undefined bam_dma_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_dma_irq(undefined8 param_1,long *param_2)

{
  ushort *puVar1;
  long *plVar2;
  ulong *puVar3;
  char cVar4;
  bool bVar5;
  ushort uVar6;
  short sVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  ulong uVar13;
  long lVar14;
  uint uVar15;
  uint uVar16;
  long lVar17;
  long *plVar18;
  long lVar19;
  ulong uVar20;
  long *plVar21;
  long *plVar22;
  undefined8 *puVar23;
  
  uVar9 = readl_relaxed(*param_2 + (ulong)*(uint *)(param_2[0x36] + 0xb0) +
                        (ulong)(uint)((int)param_2[0x34] * *(int *)(param_2[0x36] + 0xbc)));
  if ((uVar9 & 0x7fffffff) != 0) {
    uVar13 = (ulong)*(uint *)(param_2 + 0x33);
    if (*(uint *)(param_2 + 0x33) != 0) {
      uVar20 = 0;
      do {
        if ((uVar9 >> (uVar20 & 0x3f) & 1) != 0) {
          lVar14 = param_2[0x36];
          iVar11 = (int)uVar20;
          lVar19 = param_2[0x32];
          lVar17 = lVar19 + uVar20 * 0x198;
          uVar12 = readl_relaxed(*param_2 + (ulong)*(uint *)(lVar14 + 0x100) +
                                 (ulong)(uint)(*(int *)(lVar14 + 0x104) * iVar11) +
                                 (ulong)(uint)(*(int *)(lVar14 + 0x108) * iVar11) +
                                 (ulong)(uint)((int)param_2[0x34] * *(int *)(lVar14 + 0x10c)));
          lVar14 = param_2[0x36];
          writel_relaxed(uVar12,*param_2 + (ulong)*(uint *)(lVar14 + 0x110) +
                                (ulong)(uint)(*(int *)(lVar14 + 0x114) * iVar11) +
                                (ulong)(uint)(*(int *)(lVar14 + 0x118) * iVar11) +
                                (ulong)(uint)((int)param_2[0x34] * *(int *)(lVar14 + 0x11c)));
          uVar12 = _raw_spin_lock_irqsave();
          lVar14 = param_2[0x36];
          uVar10 = readl_relaxed(*param_2 + (ulong)*(uint *)(lVar14 + 0x150) +
                                 (ulong)(uint)(*(int *)(lVar14 + 0x154) * iVar11) +
                                 (ulong)(uint)(*(int *)(lVar14 + 0x158) * iVar11) +
                                 (ulong)(uint)((int)param_2[0x34] * *(int *)(lVar14 + 0x15c)));
          lVar19 = lVar19 + uVar20 * 0x198;
          if (*(long **)(lVar19 + 0x178) != (long *)(lVar19 + 0x178)) {
            puVar1 = (ushort *)(lVar19 + 0x168);
            uVar15 = 0xfff;
            if (*(char *)((long)param_2 + 0x20c) != '\0') {
              uVar15 = 0x1f;
            }
            uVar10 = ((uVar10 >> 3) - (uint)*puVar1 & uVar15) -
                     (uint)((uVar10 >> 3 & 0x1fff) < (uint)*puVar1);
            plVar2 = (long *)(lVar17 + 200);
            plVar21 = *(long **)(lVar19 + 0x178);
            do {
              if (uVar10 < *(uint *)((long)plVar21 + -0x14)) break;
              plVar18 = (long *)*plVar21;
              uVar15 = (uint)*puVar1 + *(uint *)((long)plVar21 + -0x14);
              uVar6 = (ushort)uVar15;
              *puVar1 = uVar6;
              uVar16 = 0xfff;
              if (*(char *)((long)param_2 + 0x20c) != '\0') {
                uVar16 = 0x1f;
              }
              sVar7 = 0;
              if (uVar16 != 0) {
                sVar7 = (short)((uVar15 & 0xffff) / uVar16);
              }
              *puVar1 = uVar6 - sVar7 * (short)uVar16;
              uVar15 = *(uint *)((long)plVar21 + -0x14);
              iVar11 = (int)plVar21[-3] - uVar15;
              *(int *)(plVar21 + -3) = iVar11;
              plVar21[-1] = plVar21[-1] + (ulong)uVar15 * 8;
              if (iVar11 == 0) {
                if ((int)plVar21[-0x18] < 1) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x800,0x101a30);
                  (*pcVar8)();
                }
                lVar14 = plVar21[-0x16];
                plVar22 = plVar21 + -5;
                *(int *)(lVar14 + 0x14) = (int)plVar21[-0x18];
                *(undefined4 *)(plVar21 + -0x18) = 0;
                puVar23 = *(undefined8 **)(lVar14 + 0xe0);
                uVar13 = __list_add_valid(plVar22,puVar23,lVar14 + 0xd8);
                if ((uVar13 & 1) != 0) {
                  *(long **)(lVar14 + 0xe0) = plVar22;
                  plVar21[-5] = lVar14 + 0xd8;
                  plVar21[-4] = (long)puVar23;
                  *puVar23 = plVar22;
                }
                puVar3 = (ulong *)(lVar14 + 0x78);
                Hint_Prefetch(puVar3,2,0,1);
                do {
                  uVar13 = *puVar3;
                  cVar4 = '\x01';
                  bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                  if (bVar5) {
                    *puVar3 = uVar13 | 1;
                    cVar4 = ExclusiveMonitorsStatus();
                  }
                } while (cVar4 != '\0');
                DataMemoryBarrier(2,3);
                if ((uVar13 & 1) == 0) {
                  __tasklet_schedule(lVar14 + 0x70);
                }
              }
              else {
                plVar22 = plVar21 + -5;
                lVar14 = *plVar2;
                uVar13 = __list_add_valid(plVar22,plVar2,lVar14);
                if ((uVar13 & 1) != 0) {
                  *(long **)(lVar14 + 8) = plVar22;
                  plVar21[-5] = lVar14;
                  plVar21[-4] = (long)plVar2;
                  *plVar2 = (long)plVar22;
                }
              }
              uVar10 = uVar10 - uVar15;
              uVar13 = __list_del_entry_valid(plVar21);
              if ((uVar13 & 1) != 0) {
                lVar14 = *plVar21;
                plVar22 = (long *)plVar21[1];
                *(long **)(lVar14 + 8) = plVar22;
                *plVar22 = lVar14;
              }
              *plVar21 = -0x2152ffffffffff00;
              plVar21[1] = -0x2152fffffffffede;
              plVar21 = plVar18;
            } while (plVar18 != (long *)(lVar19 + 0x178));
          }
          _raw_spin_unlock_irqrestore(lVar17 + 0xa0,uVar12);
          uVar13 = (ulong)*(uint *)(param_2 + 0x33);
        }
        uVar20 = uVar20 + 1;
      } while (uVar20 < uVar13);
    }
    puVar3 = (ulong *)(param_2 + 0x3a);
    Hint_Prefetch(puVar3,2,0,1);
    do {
      uVar13 = *puVar3;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
      if (bVar5) {
        *puVar3 = uVar13 | 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar13 & 1) == 0) {
      __tasklet_schedule(param_2 + 0x39);
    }
  }
  iVar11 = __pm_runtime_resume(param_2[1],4);
  if (iVar11 < 0) {
    uVar12 = 0;
  }
  else {
    if ((int)uVar9 < 0) {
      uVar12 = readl_relaxed(*param_2 + (ulong)*(uint *)(param_2[0x36] + 0x70) +
                             (ulong)(uint)((int)param_2[0x34] * *(int *)(param_2[0x36] + 0x7c)));
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(uVar12,*param_2 + (ulong)*(uint *)(param_2[0x36] + 0x80) +
                            (ulong)(uint)((int)param_2[0x34] * *(int *)(param_2[0x36] + 0x8c)));
    }
    lVar14 = param_2[1];
    uVar12 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar14 + 0x220) = uVar12;
    __pm_runtime_suspend(param_2[1],0xd);
    uVar12 = 1;
  }
  return uVar12;
}



//------------------------------------------------------------
// bam_alloc_chan @ 00101a58 size=356
// signature: undefined bam_alloc_chan(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_alloc_chan(long param_1)

{
  int iVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x158) == 0) {
    lVar4 = *(long *)(param_1 + 0x100);
    if (*(char *)(lVar4 + 0x20c) == '\0') {
      lVar3 = dma_alloc_attrs(*(undefined8 *)(lVar4 + 8),0x8000,param_1 + 0x160,0xcc0,4);
      *(long *)(param_1 + 0x158) = lVar3;
      cVar2 = *(char *)(lVar4 + 0x20c);
    }
    else {
      lVar3 = *(long *)(lVar4 + 0x1f8);
      *(long *)(param_1 + 0x158) = lVar3;
      *(undefined8 *)(param_1 + 0x160) = **(undefined8 **)(lVar4 + 0x1f0);
      cVar2 = *(char *)(lVar4 + 0x20c);
    }
    if (cVar2 != '\0') {
      __memset_io(lVar3,0,0x100);
      *(long *)(lVar4 + 0x1f8) = *(long *)(lVar4 + 0x1f8) + 0x100;
      **(long **)(lVar4 + 0x1f0) = **(long **)(lVar4 + 0x1f0) + 0x100;
      if (*(long *)(lVar4 + 0x210) != 0) {
        ipc_log_string(*(long *)(lVar4 + 0x210),"dma_bam:%s: r_mem_virt_base:%x r_mem_start:%x\n",
                       "bam_alloc_chan",*(undefined8 *)(lVar4 + 0x1f8),
                       **(undefined8 **)(lVar4 + 0x1f0));
      }
      __ftrace_dbg(*(undefined8 *)(lVar4 + 8),"dma_bam:%s: r_mem_virt_base:%x r_mem_start:%x\n",
                   "bam_alloc_chan",*(undefined8 *)(lVar4 + 0x1f8),**(undefined8 **)(lVar4 + 0x1f0))
      ;
      lVar3 = *(long *)(param_1 + 0x158);
    }
    if (lVar3 == 0) {
      _dev_err(*(undefined8 *)(lVar4 + 8),"Failed to allocate desc fifo\n");
      return 0xfffffff4;
    }
    iVar1 = *(int *)(lVar4 + 0x1a8);
    *(int *)(lVar4 + 0x1a8) = iVar1 + 1;
    if ((iVar1 == 0) && (*(char *)(lVar4 + 0x1a5) != '\0')) {
      bam_reset(lVar4);
    }
    if (*(long *)(lVar4 + 0x210) != 0) {
      ipc_log_string(*(long *)(lVar4 + 0x210),"%s chan id:%d\n","bam_alloc_chan",
                     *(undefined4 *)(param_1 + 0x108));
    }
    __ftrace_dbg(*(undefined8 *)(lVar4 + 8),"%s chan id:%d\n","bam_alloc_chan",
                 *(undefined4 *)(param_1 + 0x108));
  }
  return 0;
}



//------------------------------------------------------------
// bam_free_chan @ 00101bc0 size=1068
// signature: undefined bam_free_chan(void)
// callers: []
//------------------------------------------------------------

void bam_free_chan(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  long **pplVar4;
  long lVar5;
  long lVar6;
  long **pplVar7;
  long ***ppplVar8;
  long *plVar9;
  long *plVar10;
  long ***local_58;
  long ***local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  plVar9 = *(long **)(param_1 + 0x100);
  if (plVar9[0x42] != 0) {
    ipc_log_string(plVar9[0x42],"%s chan id:%d\n","bam_free_chan",*(undefined4 *)(param_1 + 0x108));
  }
  __ftrace_dbg(plVar9[1],"%s chan id:%d\n","bam_free_chan",*(undefined4 *)(param_1 + 0x108));
  iVar1 = __pm_runtime_resume(plVar9[1],4);
  if (-1 < iVar1) {
    lVar6 = param_1 + 0xa0;
    local_58 = (long ***)&local_58;
    local_50 = (long ***)&local_58;
    uVar3 = _raw_spin_lock_irqsave(lVar6);
    pplVar4 = (long **)(param_1 + 0xa8);
    pplVar7 = (long **)*pplVar4;
    if (pplVar7 != pplVar4) {
      ppplVar8 = *(long ****)(param_1 + 0xb0);
      pplVar7[1] = (long *)local_50;
      *local_50 = pplVar7;
      *ppplVar8 = (long **)&local_58;
      *(long *)(param_1 + 0xa8) = param_1 + 0xa8;
      *(long ***)(param_1 + 0xb0) = pplVar4;
      local_50 = ppplVar8;
    }
    pplVar4 = (long **)(param_1 + 0xb8);
    pplVar7 = (long **)*pplVar4;
    if (pplVar7 != pplVar4) {
      ppplVar8 = *(long ****)(param_1 + 0xc0);
      pplVar7[1] = (long *)local_50;
      *local_50 = pplVar7;
      *ppplVar8 = (long **)&local_58;
      *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
      *(long ***)(param_1 + 0xc0) = pplVar4;
      local_50 = ppplVar8;
    }
    pplVar4 = (long **)(param_1 + 200);
    pplVar7 = (long **)*pplVar4;
    if (pplVar7 != pplVar4) {
      ppplVar8 = *(long ****)(param_1 + 0xd0);
      pplVar7[1] = (long *)local_50;
      *local_50 = pplVar7;
      *ppplVar8 = (long **)&local_58;
      *(long *)(param_1 + 200) = param_1 + 200;
      *(long ***)(param_1 + 0xd0) = pplVar4;
      local_50 = ppplVar8;
    }
    pplVar4 = (long **)(param_1 + 0xd8);
    pplVar7 = (long **)*pplVar4;
    if (pplVar7 != pplVar4) {
      ppplVar8 = *(long ****)(param_1 + 0xe0);
      pplVar7[1] = (long *)local_50;
      *local_50 = pplVar7;
      *ppplVar8 = (long **)&local_58;
      *(long *)(param_1 + 0xd8) = param_1 + 0xd8;
      *(long ***)(param_1 + 0xe0) = pplVar4;
      local_50 = ppplVar8;
    }
    pplVar4 = (long **)(param_1 + 0xe8);
    pplVar7 = (long **)*pplVar4;
    if (pplVar7 != pplVar4) {
      ppplVar8 = *(long ****)(param_1 + 0xf0);
      pplVar7[1] = (long *)local_50;
      *local_50 = pplVar7;
      *ppplVar8 = (long **)&local_58;
      *(long *)(param_1 + 0xe8) = param_1 + 0xe8;
      *(long ***)(param_1 + 0xf0) = pplVar4;
      local_50 = ppplVar8;
    }
    for (ppplVar8 = local_58; (long ****)ppplVar8 != &local_58; ppplVar8 = (long ***)*ppplVar8) {
      *(uint *)((long)ppplVar8 + -0x94) = *(uint *)((long)ppplVar8 + -0x94) & 0xffffffbf;
    }
    _raw_spin_unlock_irqrestore(lVar6,uVar3);
    vchan_dma_desc_free_list(param_1,&local_58);
    if (*(long *)(param_1 + 0x178) == param_1 + 0x178) {
      uVar3 = _raw_spin_lock_irqsave(lVar6);
      plVar10 = *(long **)(param_1 + 0x100);
      lVar5 = plVar10[0x36];
      writel_relaxed(1,*plVar10 + (ulong)*(uint *)(lVar5 + 0xe0) +
                       (ulong)(uint)(*(int *)(lVar5 + 0xe4) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)(*(int *)(lVar5 + 0xe8) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)((int)plVar10[0x34] * *(int *)(lVar5 + 0xec)));
      lVar5 = plVar10[0x36];
      writel_relaxed(0,*plVar10 + (ulong)*(uint *)(lVar5 + 0xe0) +
                       (ulong)(uint)(*(int *)(lVar5 + 0xe4) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)(*(int *)(lVar5 + 0xe8) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)((int)plVar10[0x34] * *(int *)(lVar5 + 0xec)));
      DataSynchronizationBarrier(3,2,0);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      _raw_spin_unlock_irqrestore(lVar6,uVar3);
      if (*(char *)((long)plVar9 + 0x20c) == '\0') {
        dma_free_attrs(plVar9[1],0x8000,*(undefined8 *)(param_1 + 0x158),
                       *(undefined8 *)(param_1 + 0x160),4);
      }
      else {
        plVar9[0x3f] = plVar9[0x40];
        *(ulong *)plVar9[0x3e] = (ulong)*(uint *)(plVar9 + 0x41);
      }
      *(undefined8 *)(param_1 + 0x158) = 0;
      *(undefined8 *)(param_1 + 0x160) = 0;
      uVar2 = readl_relaxed(*plVar9 + (ulong)*(uint *)(plVar9[0x36] + 0xc0) +
                            (ulong)(uint)((int)plVar9[0x34] * *(int *)(plVar9[0x36] + 0xcc)));
      writel_relaxed(uVar2 & ((uint)(1L << ((ulong)*(uint *)(param_1 + 0x108) & 0x3f)) ^ 0xffffffff)
                     ,*plVar9 + (ulong)*(uint *)(plVar9[0x36] + 0xc0) +
                      (ulong)(uint)((int)plVar9[0x34] * *(int *)(plVar9[0x36] + 0xcc)));
      lVar6 = plVar9[0x36];
      writel_relaxed(0,*plVar9 + (ulong)*(uint *)(lVar6 + 0x120) +
                       (ulong)(uint)(*(int *)(lVar6 + 0x124) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)(*(int *)(lVar6 + 0x128) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)((int)plVar9[0x34] * *(int *)(lVar6 + 300)));
      iVar1 = (int)plVar9[0x35] + -1;
      *(int *)(plVar9 + 0x35) = iVar1;
      if ((iVar1 == 0) && (*(char *)((long)plVar9 + 0x1a5) != '\0')) {
        uVar2 = readl_relaxed(*plVar9 + (ulong)*(uint *)plVar9[0x36] +
                              (ulong)((int)plVar9[0x34] * ((uint *)plVar9[0x36])[3]));
        writel_relaxed(uVar2 | 1,
                       *plVar9 + (ulong)*(uint *)plVar9[0x36] +
                       (ulong)((int)plVar9[0x34] * ((uint *)plVar9[0x36])[3]));
      }
    }
    else {
      _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),"Cannot free busy channel\n");
    }
    lVar6 = plVar9[1];
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar6 + 0x220) = uVar3;
    __pm_runtime_suspend(plVar9[1],0xd);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// bam_prep_slave_sg @ 00101ff0 size=724
// signature: undefined bam_prep_slave_sg(void)
// callers: []
//------------------------------------------------------------

long bam_prep_slave_sg(long param_1,long param_2,int param_3,int param_4,uint param_5)

{
  bool bVar1;
  ulong uVar2;
  ulong uVar3;
  int *piVar4;
  long lVar5;
  code *pcVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  
  lVar12 = *(long *)(param_1 + 0x100);
  if (*(long *)(lVar12 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar12 + 0x210),"%s DMA direction:%d\n","bam_prep_slave_sg",param_4);
  }
  __ftrace_dbg(*(undefined8 *)(lVar12 + 8),"%s DMA direction:%d\n","bam_prep_slave_sg",param_4);
  if (param_4 - 1U < 3) {
    uVar13 = 0;
    if (param_3 != 0) {
      lVar12 = param_2;
      iVar14 = param_3;
      do {
        uVar13 = (ulong)((*(int *)(lVar12 + 0x18) + 0x7ff7U) / 0x7ff8 + (int)uVar13);
        lVar12 = sg_next();
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
    }
    uVar2 = uVar13 * 8 + 0xe0;
    lVar12 = __kmalloc(uVar2,0x900);
    if (lVar12 != 0) {
      if ((param_5 >> 5 & 1) != 0) {
        *(ushort *)(lVar12 + 0xb0) = *(ushort *)(lVar12 + 0xb0) | 0x1000;
      }
      if ((param_5 & 1) != 0) {
        *(ushort *)(lVar12 + 0xb0) = *(ushort *)(lVar12 + 0xb0) | 0x4000;
      }
      lVar16 = lVar12 + 0xe0;
      *(int *)(lVar12 + 0xa8) = (int)uVar13;
      *(int *)(lVar12 + 0xd0) = param_4;
      *(long *)(lVar12 + 0xb8) = lVar16;
      if (param_3 != 0) {
        iVar14 = 0;
        lVar17 = 0xe0;
        do {
          lVar8 = 0;
          iVar10 = 0;
          uVar9 = (ulong)*(uint *)(param_2 + 0x18);
          uVar11 = (uVar13 * 8 + 0xda) - lVar17;
          while( true ) {
            uVar3 = lVar17 + lVar8;
            piVar4 = (int *)(lVar16 + lVar8);
            if ((param_5 >> 7 & 1) != 0) {
              if ((uVar2 < uVar3 + 6) || (uVar11 < 2)) goto LAB_001022c0;
              *(ushort *)((long)piVar4 + 6) = *(ushort *)((long)piVar4 + 6) | 0x800;
            }
            if ((uVar2 < uVar3) || (uVar11 + 6 < 4)) goto LAB_001022c0;
            bVar1 = 0xfffffffffffffffd < uVar11 || uVar2 < uVar3 + 4;
            *piVar4 = iVar10 + *(int *)(param_2 + 0x10);
            if ((uint)uVar9 < 0x7ff9) break;
            if (bVar1) goto LAB_001022c0;
            *(undefined2 *)(piVar4 + 1) = 0x7ff8;
            iVar10 = iVar10 + 0x7ff8;
            lVar8 = lVar8 + 8;
            uVar11 = uVar11 - 8;
            uVar9 = uVar9 - 0x7ff8;
            *(long *)(lVar12 + 0xd8) = *(long *)(lVar12 + 0xd8) + 0x7ff8;
          }
          if (bVar1) {
LAB_001022c0:
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x1022c4);
            (*pcVar6)();
          }
          lVar5 = lVar16 + lVar8;
          lVar16 = lVar5 + 8;
          lVar17 = lVar17 + lVar8 + 8;
          iVar14 = iVar14 + 1;
          *(short *)(lVar5 + 4) = (short)uVar9;
          *(ulong *)(lVar12 + 0xd8) = *(long *)(lVar12 + 0xd8) + uVar9;
          param_2 = sg_next(param_2);
        } while (iVar14 != param_3);
      }
      dma_async_tx_descriptor_init(lVar12,param_1);
      *(uint *)(lVar12 + 4) = param_5;
      *(undefined8 *)(lVar12 + 0x90) = 0;
      *(undefined **)(lVar12 + 0x18) = &vchan_tx_submit;
      *(undefined **)(lVar12 + 0x20) = &vchan_tx_desc_free;
      uVar7 = _raw_spin_lock_irqsave(param_1 + 0xa0);
      plVar15 = *(long **)(param_1 + 0xb0);
      lVar16 = lVar12 + 0x98;
      uVar13 = __list_add_valid(lVar16,plVar15,param_1 + 0xa8);
      if ((uVar13 & 1) != 0) {
        *(long *)(param_1 + 0xb0) = lVar16;
        *(long *)(lVar12 + 0x98) = param_1 + 0xa8;
        *(long **)(lVar12 + 0xa0) = plVar15;
        *plVar15 = lVar16;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar7);
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar12 + 8),"invalid dma direction\n");
    lVar12 = 0;
  }
  return lVar12;
}



//------------------------------------------------------------
// bam_slave_config @ 001022c8 size=192
// signature: undefined bam_slave_config(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_slave_config(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x100);
  if (*(long *)(lVar5 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar5 + 0x210),"%s chan id:%d\n","bam_slave_config",
                   *(undefined4 *)(param_1 + 0x108));
    lVar5 = *(long *)(param_1 + 0x100);
  }
  __ftrace_dbg(*(undefined8 *)(lVar5 + 8),"%s chan id:%d\n","bam_slave_config",
               *(undefined4 *)(param_1 + 0x108));
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  *(undefined8 *)(param_1 + 0x110) = *param_2;
  uVar2 = param_2[4];
  uVar1 = param_2[1];
  uVar3 = param_2[2];
  *(undefined8 *)(param_1 + 0x128) = param_2[3];
  *(undefined8 *)(param_1 + 0x130) = uVar2;
  *(undefined8 *)(param_1 + 0x118) = uVar1;
  *(undefined8 *)(param_1 + 0x120) = uVar3;
  uVar2 = param_2[8];
  uVar1 = param_2[5];
  uVar3 = param_2[6];
  *(undefined8 *)(param_1 + 0x148) = param_2[7];
  *(undefined8 *)(param_1 + 0x150) = uVar2;
  *(undefined8 *)(param_1 + 0x138) = uVar1;
  *(undefined8 *)(param_1 + 0x140) = uVar3;
  *(undefined4 *)(param_1 + 0x174) = 1;
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar4);
  return 0;
}



//------------------------------------------------------------
// bam_pause @ 0010238c size=256
// signature: undefined bam_pause(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_pause(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0x100);
  if (plVar3[0x42] != 0) {
    ipc_log_string(plVar3[0x42],"%s chan id:%d\n","bam_pause",*(undefined4 *)(param_1 + 0x108));
  }
  __ftrace_dbg(plVar3[1],"%s chan id:%d\n","bam_pause",*(undefined4 *)(param_1 + 0x108));
  uVar1 = __pm_runtime_resume(plVar3[1],4);
  if (-1 < (int)uVar1) {
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0xa0);
    lVar2 = plVar3[0x36];
    writel_relaxed(1,*plVar3 + (ulong)*(uint *)(lVar2 + 0xf0) +
                     (ulong)(uint)(*(int *)(lVar2 + 0xf4) * *(int *)(param_1 + 0x108)) +
                     (ulong)(uint)(*(int *)(lVar2 + 0xf8) * *(int *)(param_1 + 0x108)) +
                     (ulong)(uint)((int)plVar3[0x34] * *(int *)(lVar2 + 0xfc)));
    *(undefined4 *)(param_1 + 0x170) = 1;
    _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar1);
    lVar2 = plVar3[1];
    uVar1 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar2 + 0x220) = uVar1;
    __pm_runtime_suspend(plVar3[1],0xd);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// bam_resume @ 00102490 size=244
// signature: undefined bam_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0x100);
  if (plVar3[0x42] != 0) {
    ipc_log_string(plVar3[0x42],"%s chan id:%d\n","bam_resume",*(undefined4 *)(param_1 + 0x108));
  }
  __ftrace_dbg(plVar3[1],"%s chan id:%d\n","bam_resume",*(undefined4 *)(param_1 + 0x108));
  uVar1 = __pm_runtime_resume(plVar3[1],4);
  if (-1 < (int)uVar1) {
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0xa0);
    lVar2 = plVar3[0x36];
    writel_relaxed(0,*plVar3 + (ulong)*(uint *)(lVar2 + 0xf0) +
                     (ulong)(uint)(*(int *)(lVar2 + 0xf4) * *(int *)(param_1 + 0x108)) +
                     (ulong)(uint)(*(int *)(lVar2 + 0xf8) * *(int *)(param_1 + 0x108)) +
                     (ulong)(uint)((int)plVar3[0x34] * *(int *)(lVar2 + 0xfc)));
    *(undefined4 *)(param_1 + 0x170) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar1);
    lVar2 = plVar3[1];
    uVar1 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar2 + 0x220) = uVar1;
    __pm_runtime_suspend(plVar3[1],0xd);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// bam_dma_terminate_all @ 00102588 size=660
// signature: undefined bam_dma_terminate_all(void)
// callers: [bam_dma_remove]
//------------------------------------------------------------

undefined8 bam_dma_terminate_all(long param_1)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long **pplVar6;
  long **pplVar7;
  long ***ppplVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  long ***local_78;
  long ***local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_78 = (long ***)&local_78;
  lVar5 = *(long *)(param_1 + 0x100);
  local_70 = local_78;
  if (*(long *)(lVar5 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar5 + 0x210),"%s chan id:%d\n","bam_dma_terminate_all",
                   *(undefined4 *)(param_1 + 0x108));
    lVar5 = *(long *)(param_1 + 0x100);
  }
  __ftrace_dbg(*(undefined8 *)(lVar5 + 8),"%s chan id:%d\n","bam_dma_terminate_all",
               *(undefined4 *)(param_1 + 0x108));
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  plVar1 = (long *)(param_1 + 0x178);
  if (*(long **)(param_1 + 0x178) != plVar1) {
    bam_chan_init_hw(param_1,(int)(*(long **)(param_1 + 0x178))[2]);
    if (*(long **)(param_1 + 0x178) != plVar1) {
      plVar2 = (long *)(param_1 + 200);
      plVar9 = *(long **)(param_1 + 0x178);
      do {
        lVar5 = *plVar2;
        plVar10 = plVar9 + -5;
        plVar11 = (long *)*plVar9;
        uVar4 = __list_add_valid(plVar10,plVar2,lVar5);
        if ((uVar4 & 1) != 0) {
          *(long **)(lVar5 + 8) = plVar10;
          plVar9[-5] = lVar5;
          plVar9[-4] = (long)plVar2;
          *plVar2 = (long)plVar10;
        }
        uVar4 = __list_del_entry_valid(plVar9);
        if ((uVar4 & 1) != 0) {
          lVar5 = *plVar9;
          plVar10 = (long *)plVar9[1];
          *(long **)(lVar5 + 8) = plVar10;
          *plVar10 = lVar5;
        }
        *plVar9 = -0x2152ffffffffff00;
        plVar9[1] = -0x2152fffffffffede;
        plVar9 = plVar11;
      } while (plVar11 != plVar1);
    }
  }
  pplVar6 = (long **)(param_1 + 0xa8);
  pplVar7 = (long **)*pplVar6;
  if (pplVar7 != pplVar6) {
    ppplVar8 = *(long ****)(param_1 + 0xb0);
    pplVar7[1] = (long *)local_70;
    *local_70 = pplVar7;
    *ppplVar8 = (long **)&local_78;
    *(long *)(param_1 + 0xa8) = param_1 + 0xa8;
    *(long ***)(param_1 + 0xb0) = pplVar6;
    local_70 = ppplVar8;
  }
  pplVar6 = (long **)(param_1 + 0xb8);
  pplVar7 = (long **)*pplVar6;
  if (pplVar7 != pplVar6) {
    ppplVar8 = *(long ****)(param_1 + 0xc0);
    pplVar7[1] = (long *)local_70;
    *local_70 = pplVar7;
    *ppplVar8 = (long **)&local_78;
    *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
    *(long ***)(param_1 + 0xc0) = pplVar6;
    local_70 = ppplVar8;
  }
  pplVar6 = (long **)(param_1 + 200);
  pplVar7 = (long **)*pplVar6;
  if (pplVar7 != pplVar6) {
    ppplVar8 = *(long ****)(param_1 + 0xd0);
    pplVar7[1] = (long *)local_70;
    *local_70 = pplVar7;
    *ppplVar8 = (long **)&local_78;
    *(long *)(param_1 + 200) = param_1 + 200;
    *(long ***)(param_1 + 0xd0) = pplVar6;
    local_70 = ppplVar8;
  }
  pplVar6 = (long **)(param_1 + 0xd8);
  pplVar7 = (long **)*pplVar6;
  if (pplVar7 != pplVar6) {
    ppplVar8 = *(long ****)(param_1 + 0xe0);
    pplVar7[1] = (long *)local_70;
    *local_70 = pplVar7;
    *ppplVar8 = (long **)&local_78;
    *(long *)(param_1 + 0xd8) = param_1 + 0xd8;
    *(long ***)(param_1 + 0xe0) = pplVar6;
    local_70 = ppplVar8;
  }
  pplVar6 = (long **)(param_1 + 0xe8);
  pplVar7 = (long **)*pplVar6;
  if (pplVar7 != pplVar6) {
    ppplVar8 = *(long ****)(param_1 + 0xf0);
    pplVar7[1] = (long *)local_70;
    *local_70 = pplVar7;
    *ppplVar8 = (long **)&local_78;
    *(long *)(param_1 + 0xe8) = param_1 + 0xe8;
    *(long ***)(param_1 + 0xf0) = pplVar6;
    local_70 = ppplVar8;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar3);
  vchan_dma_desc_free_list(param_1,&local_78);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// bam_issue_pending @ 00102820 size=256
// signature: undefined bam_issue_pending(void)
// callers: []
//------------------------------------------------------------

void bam_issue_pending(long param_1)

{
  long *plVar1;
  ushort uVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x100);
  if (*(long *)(lVar8 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar8 + 0x210),"%s chan id:%d\n","bam_issue_pending",
                   *(undefined4 *)(param_1 + 0x108));
  }
  __ftrace_dbg(*(undefined8 *)(lVar8 + 8),"%s chan id:%d\n","bam_issue_pending",
               *(undefined4 *)(param_1 + 0x108));
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  plVar4 = (long *)(param_1 + 0xb8);
  plVar5 = (long *)*plVar4;
  plVar1 = (long *)(param_1 + 200);
  if (plVar5 != plVar4) {
    plVar6 = *(long **)(param_1 + 0xd0);
    plVar7 = *(long **)(param_1 + 0xc0);
    plVar5[1] = (long)plVar6;
    *plVar6 = (long)plVar5;
    *plVar7 = (long)plVar1;
    *(long **)(param_1 + 0xd0) = plVar7;
    *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
    *(long **)(param_1 + 0xc0) = plVar4;
  }
  if ((long *)*plVar1 != plVar1) {
    uVar2 = 0xfff;
    if (*(char *)(lVar8 + 0x20c) != '\0') {
      uVar2 = 0x1f;
    }
    if ((uVar2 & ~*(ushort *)(param_1 + 0x16a) + *(short *)(param_1 + 0x168)) != 0) {
      bam_start_dma(param_1);
    }
  }
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar3);
  return;
}



//------------------------------------------------------------
// bam_tx_status @ 00102924 size=436
// signature: undefined bam_tx_status(void)
// callers: []
//------------------------------------------------------------

undefined4 bam_tx_status(long param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  ulong uVar6;
  ushort *puVar7;
  ulong uVar8;
  int iVar9;
  ulong uVar10;
  int iVar11;
  
  lVar4 = *(long *)(param_1 + 0x100);
  if (*(long *)(lVar4 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar4 + 0x210),"%s chan id:%d\n","bam_tx_status",
                   *(undefined4 *)(param_1 + 0x108));
    lVar4 = *(long *)(param_1 + 0x100);
  }
  __ftrace_dbg(*(undefined8 *)(lVar4 + 8),"%s chan id:%d\n","bam_tx_status",
               *(undefined4 *)(param_1 + 0x108));
  iVar11 = *(int *)(param_1 + 0x10);
  iVar9 = *(int *)(param_1 + 0x14);
  if (param_3 != (int *)0x0) {
    *param_3 = iVar9;
    param_3[1] = iVar11;
    param_3[2] = 0;
    param_3[3] = 0;
  }
  if (iVar11 < iVar9) {
    if ((iVar11 < param_2) && (param_2 <= iVar9)) {
      return 0;
    }
  }
  else {
    if (iVar11 < param_2) {
      return 0;
    }
    if (param_2 <= iVar9) {
      return 0;
    }
  }
  if (param_3 != (int *)0x0) {
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0xa0);
    lVar4 = vchan_find_desc(param_1,param_2);
    if (lVar4 == 0) {
      plVar5 = *(long **)(param_1 + 0x178);
      if (plVar5 == (long *)(param_1 + 0x178)) {
        iVar11 = 0;
      }
      else {
        iVar11 = 0;
        do {
          if ((int)plVar5[-0x18] == param_2) {
            uVar1 = *(uint *)(plVar5 + -3);
            uVar6 = (ulong)uVar1;
            if (uVar1 != 0) {
              if (uVar1 == 1) {
                uVar8 = 0;
              }
              else {
                uVar8 = uVar6 & 0xfffffffe;
                iVar9 = 0;
                puVar7 = (ushort *)(plVar5[-1] + 0xc);
                uVar10 = uVar8;
                do {
                  uVar10 = uVar10 - 2;
                  iVar11 = iVar11 + (uint)puVar7[-4];
                  iVar9 = iVar9 + (uint)*puVar7;
                  puVar7 = puVar7 + 8;
                } while (uVar10 != 0);
                iVar11 = iVar9 + iVar11;
                if (uVar8 == uVar6) goto LAB_00102a48;
              }
              lVar4 = uVar6 - uVar8;
              puVar7 = (ushort *)(plVar5[-1] + uVar8 * 8 + 4);
              do {
                lVar4 = lVar4 + -1;
                iVar11 = iVar11 + (uint)*puVar7;
                puVar7 = puVar7 + 4;
              } while (lVar4 != 0);
            }
          }
LAB_00102a48:
          plVar5 = (long *)*plVar5;
        } while (plVar5 != (long *)(param_1 + 0x178));
      }
    }
    else {
      iVar11 = (int)*(undefined8 *)(lVar4 + 0xd8);
    }
    _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar2);
    param_3[2] = iVar11;
  }
  uVar3 = 1;
  if (*(int *)(param_1 + 0x170) != 0) {
    uVar3 = 2;
  }
  return uVar3;
}



//------------------------------------------------------------
// bam_dma_xlate @ 00102adc size=156
// signature: undefined bam_dma_xlate(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_dma_xlate(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_2 + 0x30);
  if (*(long *)(lVar2 + 0x200) != 0) {
    ipc_log_string(*(long *)(lVar2 + 0x200),"%s No of channels:%d\n","bam_dma_xlate",
                   *(undefined4 *)(lVar2 + 0x188));
  }
  __ftrace_dbg(*(undefined8 *)(lVar2 + -8),"%s No of channels:%d\n","bam_dma_xlate",
               *(undefined4 *)(lVar2 + 0x188));
  if ((*(int *)(param_1 + 8) == 1) && (*(uint *)(param_1 + 0xc) < *(uint *)(lVar2 + 0x188))) {
    uVar1 = dma_get_slave_channel
                      (*(long *)(lVar2 + 0x180) + (ulong)*(uint *)(param_1 + 0xc) * 0x198);
    return uVar1;
  }
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00102b78 size=124
// signature: undefined readl_relaxed(void)
// callers: [bam_dma_irq, bam_reset, bam_dma_probe, bam_chan_init_hw, bam_free_chan]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102bc0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// bam_reset @ 00102bf4 size=368
// signature: undefined bam_reset(void)
// callers: [bam_alloc_chan, bam_dma_probe]
//------------------------------------------------------------

void bam_reset(long *param_1)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(*param_1 + (ulong)*(uint *)param_1[0x36] +
                        (ulong)((int)param_1[0x34] * ((uint *)param_1[0x36])[3]));
  writel_relaxed(uVar1 | 1,
                 *param_1 + (ulong)*(uint *)param_1[0x36] +
                 (ulong)((int)param_1[0x34] * ((uint *)param_1[0x36])[3]));
  writel_relaxed(uVar1 & 0xfffffffe,
                 *param_1 + (ulong)*(uint *)param_1[0x36] +
                 (ulong)((int)param_1[0x34] * ((uint *)param_1[0x36])[3]));
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(uVar1 & 0xfffffffe | 2,
                 *param_1 + (ulong)*(uint *)param_1[0x36] +
                 (ulong)((int)param_1[0x34] * ((uint *)param_1[0x36])[3]));
  writel_relaxed(4,*param_1 + (ulong)*(uint *)(param_1[0x36] + 0x30) +
                   (ulong)(uint)((int)param_1[0x34] * *(int *)(param_1[0x36] + 0x3c)));
  writel_relaxed(0xffff004,
                 *param_1 + (ulong)*(uint *)(param_1[0x36] + 0xa0) +
                 (ulong)(uint)((int)param_1[0x34] * *(int *)(param_1[0x36] + 0xac)));
  writel_relaxed(6,*param_1 + (ulong)*(uint *)(param_1[0x36] + 0x90) +
                   (ulong)(uint)((int)param_1[0x34] * *(int *)(param_1[0x36] + 0x9c)));
  writel_relaxed(0x80000000,
                 *param_1 + (ulong)*(uint *)(param_1[0x36] + 0xc0) +
                 (ulong)(uint)((int)param_1[0x34] * *(int *)(param_1[0x36] + 0xcc)));
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00102d64 size=132
// signature: undefined writel_relaxed(void)
// callers: [bam_pause, bam_dma_irq, bam_dma_remove, bam_reset, bam_start_dma, bam_chan_init_hw, bam_resume, bam_free_chan]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102d7c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102db8,uVar1);
  return;
}



//------------------------------------------------------------
// bam_start_dma @ 00102de8 size=908
// signature: undefined bam_start_dma(void)
// callers: [dma_tasklet, bam_issue_pending]
//------------------------------------------------------------

void bam_start_dma(long param_1)

{
  long *plVar1;
  ushort uVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  ulong uVar6;
  void *__dest;
  undefined8 uVar7;
  void *pvVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  void *__src;
  uint uVar13;
  size_t __n;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  
  plVar16 = (long *)(param_1 + 200);
  plVar11 = (long *)*plVar16;
  plVar15 = *(long **)(param_1 + 0x100);
  lVar10 = *(long *)(param_1 + 0x158);
  if (plVar15[0x42] != 0) {
    ipc_log_string(plVar15[0x42],"%s chan id:%d\n","bam_start_dma",*(undefined4 *)(param_1 + 0x108))
    ;
  }
  __ftrace_dbg(plVar15[1],"%s chan id:%d\n","bam_start_dma",*(undefined4 *)(param_1 + 0x108));
  if (((plVar11 != plVar16) && (plVar11 = plVar11 + -0x13, plVar11 != (long *)0x0)) &&
     (iVar5 = __pm_runtime_resume(plVar15[1],4), -1 < iVar5)) {
    pvVar8 = (void *)(lVar10 + 7U & 0xfffffffffffffff8);
    do {
      uVar2 = 0xfff;
      if (*(char *)((long)plVar15 + 0x20c) != '\0') {
        uVar2 = 0x1f;
      }
      if ((uVar2 & ~*(ushort *)(param_1 + 0x16a) + *(short *)(param_1 + 0x168)) == 0) break;
      uVar6 = __list_del_entry_valid(plVar11 + 0x13);
      if ((uVar6 & 1) != 0) {
        lVar10 = plVar11[0x13];
        plVar9 = (long *)plVar11[0x14];
        *(long **)(lVar10 + 8) = plVar9;
        *plVar9 = lVar10;
      }
      plVar11[0x13] = -0x2152ffffffffff00;
      plVar11[0x14] = -0x2152fffffffffede;
      if (*(int *)(param_1 + 0x16c) == 0) {
        bam_chan_init_hw(param_1,(int)plVar11[0x1a]);
        iVar5 = *(int *)(param_1 + 0x174);
      }
      else {
        iVar5 = *(int *)(param_1 + 0x174);
      }
      if (iVar5 != 0) {
        plVar9 = *(long **)(param_1 + 0x100);
        if (*(char *)((long)plVar9 + 0x1a4) == '\0') {
          lVar10 = 0x130;
          if ((int)plVar11[0x1a] != 2) {
            lVar10 = 0x134;
          }
          writel_relaxed(*(undefined4 *)(param_1 + lVar10),
                         *plVar9 + (ulong)*(uint *)(plVar9[0x36] + 0x30) +
                         (ulong)(uint)((int)plVar9[0x34] * *(int *)(plVar9[0x36] + 0x3c)));
        }
        *(undefined4 *)(param_1 + 0x174) = 0;
      }
      uVar3 = *(uint *)(plVar11 + 0x15);
      __src = (void *)plVar11[0x17];
      uVar13 = 0xfff;
      if (*(char *)((long)plVar15 + 0x20c) != '\0') {
        uVar13 = 0x1f;
      }
      uVar13 = uVar13 & ~(uint)*(ushort *)(param_1 + 0x16a) + (uint)*(ushort *)(param_1 + 0x168);
      if (uVar13 < uVar3) {
        *(uint *)((long)plVar11 + 0xac) = uVar13;
        uVar3 = uVar13;
      }
      else {
        *(uint *)((long)plVar11 + 0xac) = uVar3;
        *(ushort *)((long)__src + (ulong)(uVar3 - 1) * 8 + 6) =
             *(ushort *)((long)__src + (ulong)(uVar3 - 1) * 8 + 6) | *(ushort *)(plVar11 + 0x16);
        uVar3 = *(uint *)((long)plVar11 + 0xac);
      }
      uVar6 = (ulong)uVar3;
      plVar9 = (long *)*plVar16;
      plVar12 = plVar9 + -0x13;
      if ((((uVar13 <= uVar3) || (plVar9 == plVar16 || plVar12 == (long *)0x0)) ||
          ((plVar11[5] != 0 || (plVar11[6] != 0)))) &&
         ((*(ushort *)(plVar11 + 0x16) >> 0xe & 1) == 0)) {
        *(ushort *)((long)__src + (ulong)(uVar3 - 1) * 8 + 6) =
             *(ushort *)((long)__src + (ulong)(uVar3 - 1) * 8 + 6) | 0x8000;
        uVar6 = (ulong)*(uint *)((long)plVar11 + 0xac);
      }
      uVar13 = 0xfff;
      if (*(char *)((long)plVar15 + 0x20c) != '\0') {
        uVar13 = 0x1f;
      }
      if (uVar13 < (int)uVar6 + (uint)*(ushort *)(param_1 + 0x16a)) {
        uVar13 = uVar13 - *(ushort *)(param_1 + 0x16a);
        __n = (ulong)uVar13 * 8;
        memcpy((void *)((long)pvVar8 + (ulong)*(ushort *)(param_1 + 0x16a) * 8),__src,__n);
        __src = (void *)((long)__src + __n);
        uVar6 = (ulong)(*(int *)((long)plVar11 + 0xac) - uVar13);
        __dest = pvVar8;
      }
      else {
        __dest = (void *)((long)pvVar8 + (ulong)*(ushort *)(param_1 + 0x16a) * 8);
      }
      memcpy(__dest,__src,uVar6 << 3);
      plVar1 = plVar11 + 0x18;
      uVar2 = *(short *)(param_1 + 0x16a) + *(short *)((long)plVar11 + 0xac);
      *(ushort *)(param_1 + 0x16a) = uVar2;
      uVar13 = 0xfff;
      if (*(char *)((long)plVar15 + 0x20c) != '\0') {
        uVar13 = 0x1f;
      }
      plVar14 = *(long **)(param_1 + 0x180);
      sVar4 = 0;
      if (uVar13 != 0) {
        sVar4 = (short)(uVar2 / uVar13);
      }
      *(ushort *)(param_1 + 0x16a) = uVar2 - sVar4 * (short)uVar13;
      uVar6 = __list_add_valid(plVar1,plVar14,param_1 + 0x178);
      if ((uVar6 & 1) != 0) {
        *(long **)(param_1 + 0x180) = plVar1;
        plVar11[0x18] = param_1 + 0x178;
        plVar11[0x19] = (long)plVar14;
        *plVar14 = (long)plVar1;
      }
      plVar11 = plVar12;
    } while (plVar9 != plVar16 && plVar12 != (long *)0x0);
    DataSynchronizationBarrier(3,2,0);
    lVar10 = plVar15[0x36];
    writel_relaxed((ulong)*(ushort *)(param_1 + 0x16a) << 3,
                   *plVar15 + (ulong)*(uint *)(lVar10 + 0x140) +
                   (ulong)(uint)(*(int *)(lVar10 + 0x144) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)(*(int *)(lVar10 + 0x148) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)((int)plVar15[0x34] * *(int *)(lVar10 + 0x14c)));
    lVar10 = plVar15[1];
    uVar7 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar10 + 0x220) = uVar7;
    __pm_runtime_suspend(plVar15[1],0xd);
  }
  return;
}



//------------------------------------------------------------
// bam_chan_init_hw @ 00103174 size=664
// signature: undefined bam_chan_init_hw(void)
// callers: [bam_dma_terminate_all, bam_start_dma]
//------------------------------------------------------------

void bam_chan_init_hw(long param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  long *plVar4;
  
  plVar4 = *(long **)(param_1 + 0x100);
  lVar2 = plVar4[0x36];
  writel_relaxed(1,*plVar4 + (ulong)*(uint *)(lVar2 + 0xe0) +
                   (ulong)(uint)(*(int *)(lVar2 + 0xe4) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)(*(int *)(lVar2 + 0xe8) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 0xec)));
  lVar2 = plVar4[0x36];
  writel_relaxed(0,*plVar4 + (ulong)*(uint *)(lVar2 + 0xe0) +
                   (ulong)(uint)(*(int *)(lVar2 + 0xe4) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)(*(int *)(lVar2 + 0xe8) * *(int *)(param_1 + 0x108)) +
                   (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 0xec)));
  DataSynchronizationBarrier(3,2,0);
  *(undefined4 *)(param_1 + 0x16c) = 0;
  lVar2 = plVar4[0x36];
  writel_relaxed(*(int *)(param_1 + 0x160) + 7U & 0xfffffff8,
                 *plVar4 + (ulong)*(uint *)(lVar2 + 0x170) +
                 (ulong)(uint)(*(int *)(lVar2 + 0x174) * *(int *)(param_1 + 0x108)) +
                 (ulong)(uint)(*(int *)(lVar2 + 0x178) * *(int *)(param_1 + 0x108)) +
                 (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 0x17c)));
  lVar2 = plVar4[0x36];
  uVar3 = 0x8000;
  if (*(char *)((long)plVar4 + 0x20c) != '\0') {
    uVar3 = 0x100;
  }
  writel_relaxed(uVar3,*plVar4 + (ulong)*(uint *)(lVar2 + 400) +
                       (ulong)(uint)(*(int *)(lVar2 + 0x194) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)(*(int *)(lVar2 + 0x198) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 0x19c)));
  lVar2 = plVar4[0x36];
  writel_relaxed(0x31,*plVar4 + (ulong)*(uint *)(lVar2 + 0x120) +
                      (ulong)(uint)(*(int *)(lVar2 + 0x124) * *(int *)(param_1 + 0x108)) +
                      (ulong)(uint)(*(int *)(lVar2 + 0x128) * *(int *)(param_1 + 0x108)) +
                      (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 300)));
  uVar1 = readl_relaxed(*plVar4 + (ulong)*(uint *)(plVar4[0x36] + 0xc0) +
                        (ulong)(uint)((int)plVar4[0x34] * *(int *)(plVar4[0x36] + 0xcc)));
  writel_relaxed(uVar1 | (uint)(1L << ((ulong)*(uint *)(param_1 + 0x108) & 0x3f)),
                 *plVar4 + (ulong)*(uint *)(plVar4[0x36] + 0xc0) +
                 (ulong)(uint)((int)plVar4[0x34] * *(int *)(plVar4[0x36] + 0xcc)));
  DataSynchronizationBarrier(3,2,0);
  lVar2 = plVar4[0x36];
  uVar3 = 0x2a;
  if (param_2 != 2) {
    uVar3 = 0x22;
  }
  writel_relaxed(uVar3,*plVar4 + (ulong)*(uint *)(lVar2 + 0xd0) +
                       (ulong)(uint)(*(int *)(lVar2 + 0xd4) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)(*(int *)(lVar2 + 0xd8) * *(int *)(param_1 + 0x108)) +
                       (ulong)(uint)((int)plVar4[0x34] * *(int *)(lVar2 + 0xdc)));
  *(undefined8 *)(param_1 + 0x168) = 0x100000000;
  if (plVar4[0x42] != 0) {
    uVar3 = 0x8000;
    if (*(char *)((long)plVar4 + 0x20c) != '\0') {
      uVar3 = 0x100;
    }
    ipc_log_string(plVar4[0x42],"%s: bam_desc_fifo:%d\n","bam_chan_init_hw",uVar3);
  }
  uVar3 = 0x8000;
  if (*(char *)((long)plVar4 + 0x20c) != '\0') {
    uVar3 = 0x100;
  }
  __ftrace_dbg(plVar4[1],"%s: bam_desc_fifo:%d\n","bam_chan_init_hw",uVar3);
  return;
}



//------------------------------------------------------------
// bam_dma_free_desc @ 00103410 size=28
// signature: undefined bam_dma_free_desc(void)
// callers: []
//------------------------------------------------------------

void bam_dma_free_desc(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// bam_dma_suspend @ 00103430 size=112
// signature: undefined bam_dma_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_dma_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  pm_runtime_force_suspend();
  clk_unprepare(*(undefined8 *)(lVar1 + 0x1b8));
  if (*(long *)(lVar1 + 0x210) != 0) {
    ipc_log_string(*(long *)(lVar1 + 0x210),"%s ret:%d\n","bam_dma_suspend",0);
  }
  __ftrace_dbg(*(undefined8 *)(lVar1 + 8),"%s ret:%d\n","bam_dma_suspend",0);
  return 0;
}



//------------------------------------------------------------
// bam_dma_resume @ 001034a4 size=136
// signature: undefined bam_dma_resume(void)
// callers: []
//------------------------------------------------------------

int bam_dma_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = clk_prepare(*(undefined8 *)(lVar2 + 0x1b8));
  if (iVar1 == 0) {
    pm_runtime_force_resume(param_1);
    if (*(long *)(lVar2 + 0x210) != 0) {
      ipc_log_string(*(long *)(lVar2 + 0x210),"%s ret:%d\n","bam_dma_resume",0);
    }
    __ftrace_dbg(*(undefined8 *)(lVar2 + 8),"%s ret:%d\n","bam_dma_resume",0);
  }
  return iVar1;
}



//------------------------------------------------------------
// bam_dma_runtime_suspend @ 00103530 size=40
// signature: undefined bam_dma_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 bam_dma_runtime_suspend(long param_1)

{
  clk_disable(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x1b8));
  return 0;
}



//------------------------------------------------------------
// bam_dma_runtime_resume @ 0010355c size=88
// signature: undefined bam_dma_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int bam_dma_runtime_resume(long param_1)

{
  int iVar1;
  
  iVar1 = clk_enable(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x1b8));
  if (iVar1 < 0) {
    _dev_err(param_1,"clk_enable failed: %d\n",iVar1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010360c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&bam_dma_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010363c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&bam_dma_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 00107000 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_bam_dma_info, trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00107008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00107010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_bam_dma_info, trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 00107018 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [perf_trace_bam_dma_info, trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00107020 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00107028 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [bam_dma_terminate_all, perf_trace_bam_dma_info, trace_event_raw_event_bam_dma_info, __ftrace_dbg, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00107038 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00107040 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00107048 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107050 size=1
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
// platform_driver_unregister @ 00107058 size=1
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
// trace_raw_output_prep @ 00107060 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00107068 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00107070 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_bam_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00107078 size=1
// signature: undefined devm_kmalloc(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00107080 size=1
// signature: undefined of_match_node(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00107088 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00107090 size=1
// signature: undefined ipc_log_string(void)
// callers: [bam_slave_config, bam_alloc_chan, bam_dma_suspend, bam_issue_pending, bam_start_dma, bam_chan_init_hw, bam_resume, bam_dma_resume, bam_dma_xlate, bam_pause, bam_prep_slave_sg, bam_dma_remove, bam_dma_terminate_all, bam_dma_probe, bam_free_chan, bam_tx_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00107098 size=1
// signature: undefined platform_get_resource(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001070a0 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001070a8 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001070b0 size=1
// signature: undefined devm_ioremap(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 001070b8 size=1
// signature: undefined dma_set_mask(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 001070c0 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001070c8 size=1
// signature: undefined platform_get_irq(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001070d0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001070d8 size=1
// signature: undefined of_find_property(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001070e0 size=1
// signature: undefined devm_clk_get(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get_optional @ 001070e8 size=1
// signature: undefined devm_clk_get_optional(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001070f0 size=1
// signature: undefined clk_prepare(void)
// callers: [bam_dma_probe, bam_dma_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001070f8 size=1
// signature: undefined clk_enable(void)
// callers: [bam_dma_runtime_resume, bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_setup @ 00107100 size=1
// signature: undefined tasklet_setup(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_setup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vchan_init @ 00107108 size=1
// signature: undefined vchan_init(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vchan_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00107110 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_device_register @ 00107120 size=1
// signature: undefined dma_async_device_register(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_controller_register @ 00107128 size=1
// signature: undefined of_dma_controller_register(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_device_unregister @ 00107130 size=1
// signature: undefined dma_async_device_unregister(void)
// callers: [bam_dma_remove, bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_kill @ 00107138 size=1
// signature: undefined tasklet_kill(void)
// callers: [bam_dma_remove, bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_kill(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107140 size=1
// signature: undefined _dev_err(void)
// callers: [bam_alloc_chan, bam_prep_slave_sg, bam_dma_runtime_resume, bam_dma_probe, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00107148 size=1
// signature: undefined clk_disable(void)
// callers: [bam_dma_remove, bam_dma_probe, bam_dma_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00107150 size=1
// signature: undefined clk_unprepare(void)
// callers: [bam_dma_suspend, bam_dma_remove, bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_irq_safe @ 00107158 size=1
// signature: undefined pm_runtime_irq_safe(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_irq_safe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00107160 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 00107168 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00107170 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [bam_pause, bam_dma_irq, bam_dma_probe, bam_start_dma, bam_resume, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00107178 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00107180 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [bam_dma_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00107188 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [bam_dma_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_force_suspend @ 00107190 size=1
// signature: undefined pm_runtime_force_suspend(void)
// callers: [bam_dma_suspend, bam_dma_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_force_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_controller_free @ 00107198 size=1
// signature: undefined of_dma_controller_free(void)
// callers: [bam_dma_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_controller_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 001071a0 size=1
// signature: undefined devm_free_irq(void)
// callers: [bam_dma_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001071a8 size=1
// signature: undefined dma_free_attrs(void)
// callers: [bam_dma_remove, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001071c8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [bam_slave_config, bam_pause, dma_tasklet, bam_dma_irq, bam_prep_slave_sg, bam_dma_terminate_all, bam_issue_pending, bam_resume, bam_free_chan, bam_tx_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001071d0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [bam_slave_config, bam_pause, dma_tasklet, bam_dma_irq, bam_prep_slave_sg, bam_dma_terminate_all, bam_issue_pending, bam_resume, bam_free_chan, bam_tx_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001071d8 size=1
// signature: undefined __list_add_valid(void)
// callers: [bam_dma_irq, bam_prep_slave_sg, bam_dma_terminate_all, bam_start_dma]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tasklet_schedule @ 001071e0 size=1
// signature: undefined __tasklet_schedule(void)
// callers: [bam_dma_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001071e8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [bam_dma_irq, bam_dma_terminate_all, bam_start_dma]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001071f0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [bam_pause, bam_dma_irq, bam_start_dma, bam_resume, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 001071f8 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [bam_pause, bam_dma_irq, bam_start_dma, bam_resume, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00107200 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [bam_alloc_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 00107208 size=1
// signature: undefined __memset_io(void)
// callers: [bam_alloc_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vchan_dma_desc_free_list @ 00107210 size=1
// signature: undefined vchan_dma_desc_free_list(void)
// callers: [bam_dma_terminate_all, bam_free_chan]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vchan_dma_desc_free_list(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 00107218 size=1
// signature: undefined sg_next(void)
// callers: [bam_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00107220 size=1
// signature: undefined __kmalloc(void)
// callers: [bam_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_tx_descriptor_init @ 00107228 size=1
// signature: undefined dma_async_tx_descriptor_init(void)
// callers: [bam_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_tx_descriptor_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vchan_find_desc @ 00107240 size=1
// signature: undefined vchan_find_desc(void)
// callers: [bam_tx_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vchan_find_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_slave_channel @ 00107248 size=1
// signature: undefined dma_get_slave_channel(void)
// callers: [bam_dma_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_slave_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00107250 size=1
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
// log_post_read_mmio @ 00107258 size=1
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
// log_write_mmio @ 00107260 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00107268 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00107270 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [bam_start_dma]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00107278 size=1
// signature: undefined kfree(void)
// callers: [bam_dma_free_desc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_force_resume @ 00107280 size=1
// signature: undefined pm_runtime_force_resume(void)
// callers: [bam_dma_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_force_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



