// Decompiled by Ghidra 12.2
// Program: qcom-cpufreq-hw.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_dcvsh_freq @ 0010074c size=140
// signature: undefined __traceiter_dcvsh_freq(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_dcvsh_freq
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00102c20;
  plVar2 = DAT_00102c20;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x63ed4dc) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1007b0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dcvsh_throttle @ 001007dc size=116
// signature: undefined __traceiter_dcvsh_throttle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_dcvsh_throttle(undefined8 param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00102c68 != (long *)0x0) {
    plVar2 = _DAT_00102c68;
    do {
      if (*(int *)((code *)*plVar2 + -4) != 0x4f872789) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10082c);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// trace_event_raw_event_dcvsh_freq @ 00100854 size=196
// signature: undefined trace_event_raw_event_dcvsh_freq(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dcvsh_freq
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x28), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_4;
    *(undefined8 *)(lVar1 + 0x20) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dcvsh_freq @ 0010091c size=268
// signature: undefined perf_trace_dcvsh_freq(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dcvsh_freq
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined8 *)(lVar3 + 0x18) = param_4;
    *(undefined8 *)(lVar3 + 0x20) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dcvsh_throttle @ 00100a2c size=180
// signature: undefined trace_event_raw_event_dcvsh_throttle(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dcvsh_throttle(long param_1,undefined8 param_2,byte param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(byte *)(lVar1 + 0x10) = param_3 & 1;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dcvsh_throttle @ 00100ae4 size=256
// signature: undefined perf_trace_dcvsh_throttle(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dcvsh_throttle(long param_1,undefined8 param_2,byte param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(byte *)(lVar3 + 0x10) = param_3 & 1;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_dcvsh_freq @ 00100be8 size=28
// signature: undefined __bpf_trace_dcvsh_freq(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dcvsh_freq(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_dcvsh_throttle @ 00100c08 size=32
// signature: undefined __bpf_trace_dcvsh_throttle(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dcvsh_throttle(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  bpf_trace_run2(param_1,param_2,param_3 & 1);
  return;
}



//------------------------------------------------------------
// qcom_cpufreq_get_cpu_cycle_counter @ 00100c2c size=352
// signature: undefined qcom_cpufreq_get_cpu_cycle_counter(void)
// callers: []
//------------------------------------------------------------

long qcom_cpufreq_get_cpu_cycle_counter(uint param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  
  lVar5 = cpufreq_cpu_get_raw();
  if (lVar5 == 0) {
    return 0;
  }
  if (0x20 < param_1) {
LAB_00100d88:
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100d8c);
    (*pcVar3)();
  }
  lVar9 = (long)(int)param_1;
  uVar8 = lVar9 * 0x10;
  plVar10 = *(long **)(lVar5 + 0x2b8);
  lVar5 = plVar10[3];
  uVar6 = _raw_spin_lock_irqsave(&DAT_0010330c + uVar8);
  if (*(char *)(lVar5 + 0x29) == '\0') {
    uVar7 = 0;
  }
  else {
    if (0x1f < param_1) goto LAB_00100d88;
    uVar7 = (ulong)(*(int *)(&DAT_00106054 + (long)(int)param_1 * 0x38) * 4 + 4U & 0xfffc);
  }
  uVar4 = readl_relaxed(*plVar10 + uVar7 + (ulong)*(uint *)(lVar5 + 0x20));
  uVar7 = lVar9 << 4 | 8;
  if (uVar7 < 0x201) {
    uVar1 = *(uint *)(&DAT_00103308 + lVar9 * 0x10);
    uVar2 = -uVar1;
    if (uVar4 < uVar1) {
      if ((0x200 < uVar8) || (param_1 == 0x20)) goto LAB_00100d84;
      uVar2 = ~uVar1;
    }
    else if ((0x200 < uVar8) || (param_1 == 0x20)) goto LAB_00100d84;
    if ((uVar8 < 0x201) && (param_1 != 0x20)) {
      lVar5 = *(long *)(&qcom_cpufreq_counter + uVar8) + (ulong)(uVar4 + uVar2);
      *(long *)(&qcom_cpufreq_counter + uVar8) = lVar5;
      if (uVar7 < 0x201) {
        *(uint *)(&DAT_00103308 + lVar9 * 0x10) = uVar4;
        _raw_spin_unlock_irqrestore(&DAT_0010330c + uVar8,uVar6);
        return lVar5;
      }
    }
  }
LAB_00100d84:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x100d88);
  (*pcVar3)();
}



//------------------------------------------------------------
// readl_relaxed @ 00100d8c size=124
// signature: undefined readl_relaxed(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init, qcom_cpufreq_get_cpu_cycle_counter, qcom_cpufreq_hw_get]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100dd4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// trace_raw_output_dcvsh_freq @ 00100e0c size=104
// signature: undefined trace_raw_output_dcvsh_freq(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dcvsh_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "cpu:%lu requested_freq:%lu throttled_freq:%lu thermal_pressure_freq:%lu\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dcvsh_throttle @ 00100e78 size=128
// signature: undefined trace_raw_output_dcvsh_throttle(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dcvsh_throttle(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "end";
    if (*(char *)(lVar3 + 0x10) != '\0') {
      pcVar1 = "begin";
    }
    trace_event_printf(param_1,"cpu:%lu throttle_%s\n",*(undefined8 *)(lVar3 + 8),pcVar1);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_driver_probe @ 00100efc size=352
// signature: undefined qcom_cpufreq_hw_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_cpufreq_hw_driver_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar1 = param_1 + 0x10;
  uVar3 = clk_get(lVar1,&DAT_00103913);
  if (uVar3 < 0xfffffffffffff001) {
    xo_rate = clk_get_rate(uVar3);
    clk_put(uVar3);
    uVar3 = clk_get(lVar1,"alternate");
    if (uVar3 < 0xfffffffffffff001) {
      uVar4 = clk_get_rate(uVar3);
      cpu_hw_rate = uVar4 >> 1;
      clk_put(uVar3);
      _DAT_00102af0 = param_1;
      lVar5 = get_cpu_device(0);
      if (lVar5 == 0) {
        uVar3 = 0xfffffdfb;
      }
      else {
        uVar4 = dev_pm_opp_of_find_icc_paths(lVar5,0);
        uVar3 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          lVar5 = 0;
          uVar3 = (ulong)_nr_cpu_ids;
          while( true ) {
            uVar4 = _find_next_bit(&__cpu_possible_mask,uVar3,(long)(int)lVar5);
            uVar3 = (ulong)_nr_cpu_ids;
            if (uVar3 <= (uVar4 & 0xffffffff)) break;
            if ((uVar4 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101058);
              (*pcVar2)();
            }
            if (0x200 < ((uVar4 & 0xffffffff) << 4 | 0xc)) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(1,0x10105c);
              (*pcVar2)();
            }
            lVar5 = uVar4 + 1;
            *(undefined4 *)(&DAT_0010330c + (uVar4 & 0xffffffff) * 0x10) = 0;
          }
          uVar4 = cpufreq_register_driver(cpufreq_qcom_hw_driver);
          uVar3 = uVar4 & 0xffffffff;
          if ((int)uVar4 != 0) {
            _dev_err(lVar1,"CPUFreq HW driver failed to register\n");
          }
        }
      }
    }
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_driver_remove @ 00101060 size=36
// signature: undefined qcom_cpufreq_hw_driver_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_cpufreq_hw_driver_remove(void)

{
  cpufreq_unregister_driver(cpufreq_qcom_hw_driver);
  return;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_cpu_init @ 00101088 size=2488
// signature: undefined qcom_cpufreq_hw_cpu_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_cpufreq_hw_cpu_init(long param_1)

{
  char *param0;
  ulong *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  int param3;
  int iVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  uint *puVar14;
  long *plVar15;
  ulong uVar16;
  ulong uVar17;
  int *piVar18;
  undefined4 *puVar19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  int iVar23;
  long lVar24;
  int iVar25;
  ulong uVar26;
  long *local_140;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
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
  long local_c0;
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
  
  lVar11 = sp_el0;
  local_70 = *(long *)(lVar11 + 0x638);
  lVar11 = cpufreq_get_driver_data();
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
  local_118 = 0;
  local_128 = 0;
  uStack_120 = 0;
  lVar12 = get_cpu_device(*(undefined4 *)(param_1 + 0x1c));
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  if (lVar12 == 0) {
    _printk(&DAT_001039e0,"qcom_cpufreq_hw_cpu_init",uVar3);
    iVar8 = -0x13;
    goto LAB_00101994;
  }
  lVar13 = get_cpu_device(uVar3);
  if (lVar13 == 0) {
    lVar13 = of_get_cpu_node(uVar3,0);
  }
  else {
    lVar13 = *(long *)(lVar13 + 0x2e8);
  }
  if (lVar13 == 0) {
    iVar8 = -0x16;
    goto LAB_00101994;
  }
  iVar8 = __of_parse_phandle_with_args
                    (lVar13,"qcom,freq-domain","#freq-domain-cells",0xffffffff,0,&local_110);
  if (iVar8 != 0) goto LAB_00101994;
  local_140 = *(long **)(param_1 + 0x2b8);
  lVar13 = lVar11 + 0x10;
  param3 = uStack_108._4_4_;
  if (local_140 == (long *)0x0) {
    plVar15 = (long *)platform_get_resource(lVar11,0x200,uStack_108._4_4_);
    if (plVar15 == (long *)0x0) {
      _dev_err(lVar13,"failed to get mem resource %d\n",param3);
      iVar8 = -0x13;
      goto LAB_00101994;
    }
    lVar24 = __devm_request_region
                       (lVar13,&iomem_resource,*plVar15,(plVar15[1] - *plVar15) + 1,plVar15[2]);
    if (lVar24 == 0) {
      _dev_err(lVar13,"failed to request resource %pR\n",plVar15);
      iVar8 = -0x10;
      goto LAB_00101994;
    }
    lVar24 = devm_ioremap(lVar13,*plVar15,(plVar15[1] - *plVar15) + 1);
    if (lVar24 == 0) {
      _dev_err(lVar13,"failed to map resource %pR\n",plVar15);
      iVar8 = -0xc;
      goto LAB_00101994;
    }
    local_140 = (long *)devm_kmalloc(lVar13,0x130,0xdc0);
    if (local_140 == (long *)0x0) {
      iVar8 = -0xc;
      goto LAB_00101994;
    }
    iVar8 = sysfs_create_file_ns(param_1 + 0x1b0,&hw_clk_domain,0);
    if (iVar8 != 0) {
      _printk(&DAT_00103a6d,"qcom_cpufreq_hw_cpu_init");
      goto LAB_00101994;
    }
    puVar14 = (uint *)of_device_get_match_data(lVar13);
    *local_140 = lVar24;
    local_140[2] = (long)plVar15;
    local_140[3] = (long)puVar14;
    *(int *)(local_140 + 10) = param3;
  }
  else {
    lVar24 = *local_140;
    puVar14 = (uint *)local_140[3];
  }
  uVar16 = readl_relaxed(lVar24 + (ulong)*puVar14);
  if ((uVar16 & 1) == 0) {
    _dev_err(lVar13,"Domain-%d cpufreq hardware not enabled\n",param3);
LAB_0010192c:
    iVar8 = -0x13;
  }
  else {
    uVar16 = readl_relaxed(lVar24 + (ulong)*(uint *)(local_140[3] + 8));
    if ((uVar16 & 1) != 0) {
      *(undefined1 *)(local_140 + 0x20) = 1;
    }
    lVar24 = 0;
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
    while( true ) {
      uVar16 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar24);
      uVar20 = (ulong)_nr_cpu_ids;
      if (_nr_cpu_ids <= (uint)uVar16) break;
      lVar24 = get_cpu_device(uVar16 & 0xffffffff);
      if (lVar24 == 0) {
        lVar24 = of_get_cpu_node(uVar16 & 0xffffffff,0);
      }
      else {
        lVar24 = *(long *)(lVar24 + 0x2e8);
      }
      if (((lVar24 != 0) &&
          (iVar8 = __of_parse_phandle_with_args
                             (lVar24,"qcom,freq-domain","#freq-domain-cells",0xffffffff,0,&local_c0)
          , -1 < iVar8)) && (uStack_b8._4_4_ == param3)) {
        puVar1 = (ulong *)(param_1 + (uVar16 >> 6 & 0x3ffffff) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar6) {
            *puVar1 = *puVar1 | 1L << (uVar16 & 0x3f);
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      lVar24 = uVar16 + 1;
    }
    uVar16 = _find_first_bit(param_1,uVar20);
    if (uVar16 == uVar20) {
      _dev_err(lVar13,"Domain-%d failed to get related CPUs\n",param3);
      iVar8 = -2;
    }
    else {
      local_c0 = 0;
      *(long **)(param_1 + 0x2b8) = local_140;
      *(undefined1 *)(param_1 + 0x278) = 1;
      lVar22 = local_140[3];
      lVar24 = __kmalloc((ulong)(*(int *)(lVar22 + 0x24) + 1) * 0xc,0xdc0);
      if (lVar24 != 0) {
        iVar8 = dev_pm_opp_of_add_table(lVar12);
        if (iVar8 == -0x13) {
          icc_scaling_enabled = 0;
          *(undefined1 *)(param_1 + 0x270) = 1;
        }
        else {
          if (iVar8 != 0) {
            _dev_err(lVar12,"Invalid opp table in device tree\n");
            kfree(lVar24);
            goto LAB_0010197c;
          }
          local_c0 = 0;
          icc_scaling_enabled = 1;
          while (uVar16 = dev_pm_opp_find_freq_ceil(lVar12,&local_c0), uVar16 < 0xfffffffffffff001)
          {
            dev_pm_opp_put();
            dev_pm_opp_disable(lVar12,local_c0);
            local_c0 = local_c0 + 1;
          }
        }
        uVar16 = 0;
        if (*(int *)(lVar22 + 0x24) != 0) {
          uVar20 = 0;
          piVar18 = (int *)(lVar24 + 8);
          uVar9 = 0;
          do {
            iVar8 = (int)uVar16;
            uVar17 = readl_relaxed(*local_140 + (ulong)*(uint *)(lVar22 + 0xc) +
                                   (ulong)(iVar8 * (uint)*(byte *)(lVar22 + 0x28)));
            uVar7 = (uint)uVar17 >> 0x10 & 7;
            uVar2 = uVar7;
            if (uVar16 != 0) {
              uVar2 = uVar9;
            }
            uVar9 = readl_relaxed(*local_140 + (ulong)*(uint *)(lVar22 + 0x10) +
                                  (ulong)(iVar8 * (uint)*(byte *)(lVar22 + 0x28)));
            uVar26 = cpu_hw_rate;
            if ((uVar17 & 0xffffffff) >> 0x1e != 0) {
              uVar26 = xo_rate * (ulong)((uint)uVar17 & 0xff);
            }
            iVar4 = (uVar9 & 0xfff) * 1000;
            uVar26 = uVar26 / 1000;
            iVar23 = (int)uVar20;
            iVar25 = (int)uVar26;
            if ((uVar7 == 1) && (*(char *)(lVar22 + 0x2a) != '\0')) {
              *piVar18 = -1;
            }
            else if (iVar23 != iVar25) {
              lVar21 = (uVar26 & 0xffffffff) * 1000;
              if ((icc_scaling_enabled & 1) == 0) {
                iVar10 = dev_pm_opp_add(lVar12,lVar21,iVar4);
joined_r0x001015fc:
                if (iVar10 == 0) {
                  *piVar18 = iVar25;
                  if (uVar7 < uVar2) {
                    piVar18[-2] = 1;
                  }
                  goto joined_r0x0010166c;
                }
              }
              else {
                iVar10 = dev_pm_opp_adjust_voltage(lVar12,lVar21,iVar4,iVar4,iVar4);
                if (iVar10 == 0) {
                  iVar10 = dev_pm_opp_enable(lVar12,lVar21);
                  goto joined_r0x001015fc;
                }
                _dev_err(lVar12,"Voltage update failed freq=%ld\n",uVar26 & 0xffffffff);
              }
              _dev_warn(lVar12,"failed to update OPP for freq=%d\n",uVar26 & 0xffffffff);
              *piVar18 = -1;
            }
joined_r0x0010166c:
            if ((uVar16 != 0) && (iVar23 == iVar25)) {
              puVar19 = (undefined4 *)(lVar24 + (ulong)(iVar8 - 1) * 0xc);
              piVar18 = puVar19 + 2;
              if (*piVar18 != -1) break;
              lVar21 = uVar20 * 1000;
              if ((icc_scaling_enabled & 1) == 0) {
                iVar8 = dev_pm_opp_add(lVar12,lVar21,iVar4);
LAB_0010170c:
                if (iVar8 == 0) {
                  *piVar18 = iVar23;
                  *puVar19 = 1;
                  break;
                }
              }
              else {
                iVar8 = dev_pm_opp_adjust_voltage(lVar12,lVar21,iVar4,iVar4,iVar4);
                if (iVar8 == 0) {
                  iVar8 = dev_pm_opp_enable(lVar12,lVar21);
                  goto LAB_0010170c;
                }
                _dev_err(lVar12,"Voltage update failed freq=%ld\n",uVar20);
              }
              _dev_warn(lVar12,"failed to update OPP for freq=%d\n",uVar20);
              break;
            }
            uVar16 = uVar16 + 1;
            piVar18 = piVar18 + 3;
            uVar20 = uVar26 & 0xffffffff;
            uVar9 = uVar2;
          } while (uVar16 < *(uint *)(lVar22 + 0x24));
        }
        *(long *)(param_1 + 400) = lVar24;
        *(undefined4 *)(lVar24 + (uVar16 & 0xffffffff) * 0xc + 8) = 0xfffffffe;
        if (*(int *)(lVar22 + 0x24) != 0) {
          uVar16 = 0;
          puVar14 = (uint *)(lVar24 + 8);
          do {
            if ((*puVar14 == 0xfffffffe) || (puVar14[-2] == 1)) break;
            local_140[0x1f] = (ulong)*puVar14;
            uVar16 = uVar16 + 1;
            puVar14 = puVar14 + 3;
          } while (uVar16 < *(uint *)(lVar22 + 0x24));
        }
        dev_pm_opp_set_sharing_cpus(lVar12,param_1);
        if (*(char *)(local_140[3] + 0x2b) != '\0') {
          snprintf((char *)&local_128,0x14,"pdmem-domain%d",param3);
          lVar11 = platform_get_resource_byname(lVar11,0x200,&local_128);
          if (lVar11 == 0) {
            _dev_err(lVar13,"PDMEM domain-%d failed\n",param3);
          }
          uVar16 = devm_ioremap_resource(lVar13,lVar11);
          if (uVar16 < 0xfffffffffffff001) {
            local_140[1] = uVar16;
          }
          else {
            _dev_err(lVar13,"Failed to map PDMEM domain-%d\n",param3);
          }
        }
        iVar8 = dev_pm_opp_get_opp_count(lVar12);
        if (0 < iVar8) {
          uVar16 = policy_has_boost_freq(param_1);
          if (((uVar16 & 1) != 0) && (iVar8 = cpufreq_enable_boost_support(), iVar8 != 0)) {
            _dev_warn(lVar12,"failed to enable boost: %d\n",iVar8);
          }
          lVar13 = *(long *)(param_1 + 0x2b8);
          lVar11 = cpufreq_get_driver_data();
          iVar8 = platform_get_irq_optional(lVar11,param3);
          *(int *)(lVar13 + 0x54) = iVar8;
          if (iVar8 != -6) {
            if (iVar8 < 0) goto LAB_00101990;
            *(undefined1 *)(lVar13 + 0x67) = 0;
            *(long *)(lVar13 + 0xf0) = param_1;
            __mutex_init(lVar13 + 0x20,"&data->throttle_lock",&qcom_cpufreq_hw_lmh_init___key);
            *(undefined8 *)(lVar13 + 0x68) = 0xfffffffe0;
            *(long *)(lVar13 + 0x70) = lVar13 + 0x70;
            *(long *)(lVar13 + 0x78) = lVar13 + 0x70;
            *(code **)(lVar13 + 0x80) = qcom_lmh_dcvs_poll;
            init_timer_key(lVar13 + 0x98,&delayed_work_timer_fn,0x200000,0,0);
            param0 = (char *)(lVar13 + 0x58);
            snprintf(param0,0xf,"dcvsh-irq-%u",*(uint *)(param_1 + 0x1c));
            iVar8 = request_threaded_irq
                              (*(undefined4 *)(lVar13 + 0x54),0,qcom_lmh_dcvs_handle_irq,0x82000,
                               param0,lVar13);
            if (iVar8 == 0) {
              iVar8 = __irq_apply_affinity_hint(*(undefined4 *)(lVar13 + 0x54),param_1,1);
              if (iVar8 != 0) {
                _dev_err(lVar11 + 0x10,"Failed to set CPU affinity of %s[%d]\n",param0,
                         *(undefined4 *)(lVar13 + 0x54));
              }
              *(code **)(lVar13 + 0x120) = dcvsh_freq_limit_show;
              *(undefined2 *)(lVar13 + 0x118) = 0x124;
              *(undefined8 *)(lVar13 + 0x108) = 0xffffffff;
              *(char **)(lVar13 + 0x110) = "dcvsh_freq_limit";
              device_create_file(lVar12,lVar13 + 0x110);
            }
            else {
              _dev_err(lVar11 + 0x10,"Error registering %s: %d\n",param0,iVar8);
            }
          }
          iVar8 = 0;
          goto LAB_00101994;
        }
        _dev_err(lVar12,"Failed to add OPPs\n");
        goto LAB_0010192c;
      }
      iVar8 = -0xc;
LAB_0010197c:
      _dev_err(lVar13,"Domain-%d failed to read LUT\n",param3);
    }
  }
LAB_00101990:
  *(undefined8 *)(param_1 + 0x2b8) = 0;
LAB_00101994:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_target_index @ 00101a54 size=308
// signature: undefined qcom_cpufreq_hw_target_index(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_cpufreq_hw_target_index(long param_1,uint param_2)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  plVar3 = *(long **)(param_1 + 0x2b8);
  lVar4 = plVar3[3];
  uVar1 = *(uint *)(*(long *)(param_1 + 400) + (ulong)param_2 * 0xc + 8);
  if ((*(char *)(lVar4 + 0x2b) != '\0') && (plVar3[1] != 0)) {
    writel_relaxed(param_2);
  }
  writel_relaxed(param_2,*plVar3 + (ulong)*(uint *)(lVar4 + 0x1c));
  if ((char)plVar3[0x20] != '\0') {
    uVar6 = 4;
    for (uVar5 = 1; uVar2 = __bitmap_weight(param_1 + 8,_nr_cpu_ids), uVar5 < (uVar2 & 0xffffffff);
        uVar5 = uVar5 + 1) {
      writel_relaxed(param_2,*plVar3 + (ulong)*(uint *)(lVar4 + 0x1c) + (uVar6 & 0xfffffffc));
      uVar6 = uVar6 + 4;
    }
  }
  if (((icc_scaling_enabled == '\x01') &&
      (lVar4 = get_cpu_device(*(undefined4 *)(param_1 + 0x1c)), lVar4 != 0)) &&
     (uVar5 = dev_pm_opp_find_freq_exact(lVar4,(ulong)uVar1 * 1000,1), uVar5 < 0xfffffffffffff001))
  {
    dev_pm_opp_set_opp(lVar4,uVar5);
    dev_pm_opp_put(uVar5);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_fast_switch @ 00101b8c size=192
// signature: undefined qcom_cpufreq_hw_fast_switch(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 qcom_cpufreq_hw_fast_switch(long param_1)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  plVar3 = *(long **)(param_1 + 0x2b8);
  uVar1 = *(uint *)(param_1 + 0x280);
  lVar4 = plVar3[3];
  writel_relaxed(uVar1,*plVar3 + (ulong)*(uint *)(lVar4 + 0x1c));
  if ((char)plVar3[0x20] != '\0') {
    uVar6 = 4;
    for (uVar5 = 1; uVar2 = __bitmap_weight(param_1 + 8,_nr_cpu_ids), uVar5 < (uVar2 & 0xffffffff);
        uVar5 = uVar5 + 1) {
      writel_relaxed(uVar1,*plVar3 + (ulong)*(uint *)(lVar4 + 0x1c) + (uVar6 & 0xfffffffc));
      uVar6 = uVar6 + 4;
    }
  }
  return *(undefined4 *)(*(long *)(param_1 + 400) + (ulong)uVar1 * 0xc + 8);
}



//------------------------------------------------------------
// qcom_cpufreq_hw_get @ 00101c50 size=216
// signature: undefined qcom_cpufreq_hw_get(void)
// callers: []
//------------------------------------------------------------

ulong qcom_cpufreq_hw_get(undefined4 param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  uint uVar5;
  long lVar6;
  
  lVar2 = cpufreq_cpu_get_raw();
  uVar3 = 0;
  if (lVar2 != 0) {
    plVar4 = *(long **)(lVar2 + 0x2b8);
    if (*(int *)((long)plVar4 + 0x54) < 0) {
      lVar2 = cpufreq_cpu_get_raw(param_1);
      uVar3 = 0;
      if (lVar2 != 0) {
        lVar6 = (*(long **)(lVar2 + 0x2b8))[3];
        uVar1 = readl_relaxed(**(long **)(lVar2 + 0x2b8) + (ulong)*(uint *)(lVar6 + 0x1c));
        uVar5 = *(int *)(lVar6 + 0x24) - 1;
        if (uVar5 <= uVar1) {
          uVar1 = uVar5;
        }
        uVar3 = (ulong)*(uint *)(*(long *)(lVar2 + 400) + (ulong)uVar1 * 0xc + 8);
      }
    }
    else {
      uVar1 = *(uint *)(plVar4[3] + 0x18);
      if (uVar1 == 0) {
        uVar1 = *(uint *)(plVar4[3] + 4);
        uVar5 = 0xff;
      }
      else {
        uVar5 = 0x3ff;
      }
      uVar1 = readl_relaxed(*plVar4 + (ulong)uVar1);
      uVar3 = (xo_rate * (ulong)(uVar1 & uVar5)) / 1000;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_cpu_online @ 00101d2c size=156
// signature: undefined qcom_cpufreq_hw_cpu_online(void)
// callers: []
//------------------------------------------------------------

int qcom_cpufreq_hw_cpu_online(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x2b8);
  lVar3 = cpufreq_get_driver_data();
  if (*(int *)(lVar4 + 0x54) < 1) {
    iVar2 = 0;
  }
  else {
    mutex_lock(lVar4 + 0x20);
    *(undefined1 *)(lVar4 + 0x67) = 0;
    mutex_unlock(lVar4 + 0x20);
    iVar1 = __irq_apply_affinity_hint(*(undefined4 *)(lVar4 + 0x54),param_1,1);
    iVar2 = 0;
    if (iVar1 != 0) {
      _dev_err(lVar3 + 0x10,"Failed to set CPU affinity of %s[%d]\n",lVar4 + 0x58,
               *(undefined4 *)(lVar4 + 0x54));
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_cpu_offline @ 00101dcc size=164
// signature: undefined qcom_cpufreq_hw_cpu_offline(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_cpufreq_hw_cpu_offline(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x2b8);
  if (0 < *(int *)(lVar1 + 0x54)) {
    mutex_lock(lVar1 + 0x20);
    *(undefined1 *)(lVar1 + 0x67) = 1;
    mutex_unlock(lVar1 + 0x20);
    cancel_delayed_work_sync(lVar1 + 0x68);
    __irq_apply_affinity_hint(*(undefined4 *)(lVar1 + 0x54),0,1);
    disable_irq_nosync(*(undefined4 *)(lVar1 + 0x54));
    topology_update_thermal_pressure(param_1 + 8,0xffffffff);
    _find_first_bit(param_1 + 8,_nr_cpu_ids);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_cpu_exit @ 00101f10 size=100
// signature: undefined qcom_cpufreq_hw_cpu_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpufreq_hw_cpu_exit(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = get_cpu_device(*(undefined4 *)(param_1 + 0x1c));
  iVar1 = *(int *)(*(long *)(param_1 + 0x2b8) + 0x54);
  if (0 < iVar1) {
    free_irq(iVar1);
  }
  dev_pm_opp_remove_all_dynamic(uVar2);
  dev_pm_opp_of_cpumask_remove_table(param_1 + 8);
  kfree(*(undefined8 *)(param_1 + 400));
  return 0;
}



//------------------------------------------------------------
// qcom_cpufreq_ready @ 00101f78 size=40
// signature: undefined qcom_cpufreq_ready(void)
// callers: []
//------------------------------------------------------------

void qcom_cpufreq_ready(long param_1)

{
  if (-1 < *(int *)(*(long *)(param_1 + 0x2b8) + 0x54)) {
    enable_irq();
  }
  return;
}



//------------------------------------------------------------
// cpufreq_register_em_with_opp @ 00101fa4 size=52
// signature: undefined cpufreq_register_em_with_opp(void)
// callers: []
//------------------------------------------------------------

void cpufreq_register_em_with_opp(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = get_cpu_device(*(undefined4 *)(param_1 + 0x1c));
  dev_pm_opp_of_register_em(uVar1,param_1 + 8);
  return;
}



//------------------------------------------------------------
// show_hw_clk_domain @ 00101fdc size=68
// signature: undefined show_hw_clk_domain(void)
// callers: []
//------------------------------------------------------------

long show_hw_clk_domain(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x2b8) == 0) {
    lVar2 = -5;
  }
  else {
    iVar1 = scnprintf(param_2,4,&DAT_001037dc,*(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x50));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// qcom_lmh_dcvs_poll @ 00102024 size=596
// signature: undefined qcom_lmh_dcvs_poll(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_lmh_dcvs_poll(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  ulong local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  lVar6 = *(long *)(param_1 + 0x88);
  uVar1 = _find_first_bit(lVar6 + 8,_nr_cpu_ids);
  lVar3 = get_cpu_device();
  local_70 = 0;
  if (lVar3 == 0) goto LAB_00102228;
  uVar2 = *(uint *)(*(long *)(param_1 + -0x50) + 0x18);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(*(long *)(param_1 + -0x50) + 4);
    uVar5 = 0xff;
  }
  else {
    uVar5 = 0x3ff;
  }
  uVar2 = readl_relaxed(*(long *)(param_1 + -0x68) + (ulong)uVar2);
  local_70 = xo_rate * (ulong)(uVar2 & uVar5);
  uVar4 = dev_pm_opp_find_freq_floor(lVar3,&local_70);
  if (uVar4 == 0xffffffffffffffde) {
    uVar4 = dev_pm_opp_find_freq_ceil(lVar3,&local_70);
  }
  if (uVar4 < 0xfffffffffffff001) {
    dev_pm_opp_put(uVar4);
  }
  else {
    _dev_warn(lVar3,"Can\'t find the OPP for throttling: %pe!\n");
  }
  uVar4 = local_70;
  mutex_lock(param_1 + -0x48);
  if (*(char *)(param_1 + -1) == '\0') {
    uVar4 = uVar4 / 1000;
    lVar3 = cpufreq_cpu_get_raw(uVar1);
    if (lVar3 == 0) {
LAB_001021b0:
      uVar4 = (ulong)*(uint *)(lVar6 + 0x28);
      enable_irq(*(undefined4 *)(param_1 + -0x14));
    }
    else {
      lVar7 = (*(long **)(lVar3 + 0x2b8))[3];
      uVar2 = readl_relaxed(**(long **)(lVar3 + 0x2b8) + (ulong)*(uint *)(lVar7 + 0x1c));
      uVar5 = *(int *)(lVar7 + 0x24) - 1;
      if (uVar5 <= uVar2) {
        uVar2 = uVar5;
      }
      if (*(uint *)(*(long *)(lVar3 + 400) + (ulong)uVar2 * 0xc + 8) <= uVar4) goto LAB_001021b0;
      if (*(ulong *)(param_1 + 0x90) <= uVar4) {
        uVar4 = (ulong)*(uint *)(lVar6 + 0x28);
      }
      mod_delayed_work_on(0x20,_system_highpri_wq,param_1,3);
    }
    lVar3 = cpufreq_cpu_get_raw(uVar1);
    if (lVar3 != 0) {
      readl_relaxed(**(long **)(lVar3 + 0x2b8) +
                    (ulong)*(uint *)((*(long **)(lVar3 + 0x2b8))[3] + 0x1c));
    }
    topology_update_thermal_pressure(lVar6 + 8,uVar4);
    *(ulong *)(param_1 + 0xa0) = uVar4;
  }
  mutex_unlock(param_1 + -0x48);
LAB_00102228:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_lmh_dcvs_handle_irq @ 001023bc size=136
// signature: undefined qcom_lmh_dcvs_handle_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_lmh_dcvs_handle_irq(undefined8 param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = param_2[0x1e];
  disable_irq_nosync(*(undefined4 *)((long)param_2 + 0x54));
  _find_first_bit(lVar1,_nr_cpu_ids);
  queue_delayed_work_on(0x20,_system_wq,param_2 + 0xd,0);
  if (*(uint *)(param_2[3] + 0x14) != 0) {
    writel_relaxed(4,*param_2 + (ulong)*(uint *)(param_2[3] + 0x14));
  }
  return 1;
}



//------------------------------------------------------------
// dcvsh_freq_limit_show @ 001024e8 size=52
// signature: undefined dcvsh_freq_limit_show(void)
// callers: []
//------------------------------------------------------------

long dcvsh_freq_limit_show(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001037be,*(undefined8 *)(param_2 + -8));
  return (long)iVar1;
}



//------------------------------------------------------------
// writel_relaxed @ 0010251c size=132
// signature: undefined writel_relaxed(void)
// callers: [qcom_cpufreq_hw_target_index, qcom_lmh_dcvs_handle_irq, qcom_cpufreq_hw_fast_switch]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102534,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102570,uVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 001025ec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_cpufreq_hw_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010261c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_cpufreq_hw_driver);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00106000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_dcvsh_throttle, trace_event_raw_event_dcvsh_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00106008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_dcvsh_throttle, trace_event_raw_event_dcvsh_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00106010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_dcvsh_throttle, trace_event_raw_event_dcvsh_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_lmh_dcvs_poll, perf_trace_dcvsh_freq, qcom_cpufreq_hw_cpu_init, perf_trace_dcvsh_throttle, trace_event_raw_event_dcvsh_throttle, trace_event_raw_event_dcvsh_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00106020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_dcvsh_freq, perf_trace_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00106028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_dcvsh_freq, perf_trace_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00106030 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_dcvsh_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00106038 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get_raw @ 00106040 size=1
// signature: undefined cpufreq_cpu_get_raw(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_get_cpu_cycle_counter, qcom_cpufreq_hw_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00106048 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_cpufreq_get_cpu_cycle_counter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00106058 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_cpufreq_get_cpu_cycle_counter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00106060 size=1
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
// log_post_read_mmio @ 00106068 size=1
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
// __platform_driver_register @ 00106070 size=1
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
// platform_driver_unregister @ 00106078 size=1
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
// trace_raw_output_prep @ 00106080 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_dcvsh_freq, trace_raw_output_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00106088 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_dcvsh_freq, trace_raw_output_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00106090 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_dcvsh_freq, trace_raw_output_dcvsh_throttle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 00106098 size=1
// signature: undefined clk_get(void)
// callers: [qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 001060a0 size=1
// signature: undefined clk_get_rate(void)
// callers: [qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_put @ 001060a8 size=1
// signature: undefined clk_put(void)
// callers: [qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 001060b0 size=1
// signature: undefined get_cpu_device(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_driver_probe, qcom_cpufreq_hw_target_index, qcom_cpufreq_hw_cpu_exit, cpufreq_register_em_with_opp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_find_icc_paths @ 001060b8 size=1
// signature: undefined dev_pm_opp_of_find_icc_paths(void)
// callers: [qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_find_icc_paths(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001060d0 size=1
// signature: undefined _find_next_bit(void)
// callers: [qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_register_driver @ 001060d8 size=1
// signature: undefined cpufreq_register_driver(void)
// callers: [qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001060e0 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_cpufreq_hw_cpu_online, qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_unregister_driver @ 001060e8 size=1
// signature: undefined cpufreq_unregister_driver(void)
// callers: [qcom_cpufreq_hw_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_unregister_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_get_driver_data @ 001060f0 size=1
// signature: undefined cpufreq_get_driver_data(void)
// callers: [qcom_cpufreq_hw_cpu_online, qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_get_driver_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001060f8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_cpu_node @ 00106100 size=1
// signature: undefined of_get_cpu_node(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_cpu_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00106108 size=1
// signature: undefined platform_get_resource(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_request_region @ 00106118 size=1
// signature: undefined __devm_request_region(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_request_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00106120 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00106128 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00106130 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00106138 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106140 size=1
// signature: undefined _printk(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00106150 size=1
// signature: undefined _find_first_bit(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init, qcom_lmh_dcvs_handle_irq, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00106158 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_add_table @ 00106160 size=1
// signature: undefined dev_pm_opp_of_add_table(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_add_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_ceil @ 00106168 size=1
// signature: undefined dev_pm_opp_find_freq_ceil(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_ceil(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_put @ 00106170 size=1
// signature: undefined dev_pm_opp_put(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_target_index]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_disable @ 00106178 size=1
// signature: undefined dev_pm_opp_disable(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_adjust_voltage @ 00106180 size=1
// signature: undefined dev_pm_opp_adjust_voltage(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_adjust_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_enable @ 00106188 size=1
// signature: undefined dev_pm_opp_enable(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_add @ 00106190 size=1
// signature: undefined dev_pm_opp_add(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00106198 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_set_sharing_cpus @ 001061a0 size=1
// signature: undefined dev_pm_opp_set_sharing_cpus(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_set_sharing_cpus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001061a8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001061b0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001061b8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_get_opp_count @ 001061c0 size=1
// signature: undefined dev_pm_opp_get_opp_count(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_get_opp_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// policy_has_boost_freq @ 001061c8 size=1
// signature: undefined policy_has_boost_freq(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void policy_has_boost_freq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_enable_boost_support @ 001061d0 size=1
// signature: undefined cpufreq_enable_boost_support(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_enable_boost_support(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_optional @ 001061d8 size=1
// signature: undefined platform_get_irq_optional(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001061e0 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001061f0 size=1
// signature: undefined init_timer_key(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 001061f8 size=1
// signature: undefined request_threaded_irq(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_apply_affinity_hint @ 00106200 size=1
// signature: undefined __irq_apply_affinity_hint(void)
// callers: [qcom_cpufreq_hw_cpu_online, qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_apply_affinity_hint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00106208 size=1
// signature: undefined device_create_file(void)
// callers: [qcom_cpufreq_hw_cpu_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106210 size=1
// signature: undefined kfree(void)
// callers: [qcom_cpufreq_hw_cpu_init, qcom_cpufreq_hw_cpu_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00106218 size=1
// signature: undefined __bitmap_weight(void)
// callers: [qcom_cpufreq_hw_target_index, qcom_cpufreq_hw_fast_switch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_exact @ 00106220 size=1
// signature: undefined dev_pm_opp_find_freq_exact(void)
// callers: [qcom_cpufreq_hw_target_index]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_exact(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_set_opp @ 00106228 size=1
// signature: undefined dev_pm_opp_set_opp(void)
// callers: [qcom_cpufreq_hw_target_index]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_set_opp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00106230 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_online, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106238 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_online, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00106240 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00106248 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [qcom_lmh_dcvs_handle_irq, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// topology_update_thermal_pressure @ 00106250 size=1
// signature: undefined topology_update_thermal_pressure(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_hw_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void topology_update_thermal_pressure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00106270 size=1
// signature: undefined free_irq(void)
// callers: [qcom_cpufreq_hw_cpu_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_remove_all_dynamic @ 00106278 size=1
// signature: undefined dev_pm_opp_remove_all_dynamic(void)
// callers: [qcom_cpufreq_hw_cpu_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_remove_all_dynamic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_cpumask_remove_table @ 00106280 size=1
// signature: undefined dev_pm_opp_of_cpumask_remove_table(void)
// callers: [qcom_cpufreq_hw_cpu_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_cpumask_remove_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00106288 size=1
// signature: undefined enable_irq(void)
// callers: [qcom_lmh_dcvs_poll, qcom_cpufreq_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_register_em @ 00106290 size=1
// signature: undefined dev_pm_opp_of_register_em(void)
// callers: [cpufreq_register_em_with_opp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_register_em(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106298 size=1
// signature: undefined scnprintf(void)
// callers: [show_hw_clk_domain, dcvsh_freq_limit_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_floor @ 001062a0 size=1
// signature: undefined dev_pm_opp_find_freq_floor(void)
// callers: [qcom_lmh_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_floor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_delayed_work_on @ 001062b0 size=1
// signature: undefined mod_delayed_work_on(void)
// callers: [qcom_lmh_dcvs_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001062c0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [qcom_lmh_dcvs_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001062c8 size=1
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
// log_post_write_mmio @ 001062d0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



