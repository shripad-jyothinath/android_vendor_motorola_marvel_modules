// Decompiled by Ghidra 12.2
// Program: gdsc-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_gdsc_time @ 001004bc size=140
// signature: undefined __traceiter_gdsc_time(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_gdsc_time
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00102c70;
  plVar2 = DAT_00102c70;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x56cbd356) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100520);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_gdsc_time @ 0010054c size=260
// signature: undefined trace_event_raw_event_gdsc_time(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gdsc_time
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x18;
      strcpy((char *)(lVar3 + 0x18),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gdsc_time @ 00100654 size=348
// signature: undefined perf_trace_gdsc_time(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gdsc_time
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10018;
      strcpy((char *)(lVar5 + 0x18),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_gdsc_time @ 001007b4 size=40
// signature: undefined __bpf_trace_gdsc_time(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gdsc_time
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// gdsc_debug_print_regs @ 001007e0 size=368
// signature: undefined gdsc_debug_print_regs(void)
// callers: []
//------------------------------------------------------------

void gdsc_debug_print_regs(long param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  undefined4 uVar7;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  lVar5 = *(long *)(param_1 + 0x78);
  lVar4 = rdev_get_drvdata(lVar5);
  local_60 = 0;
  local_68 = 0;
  if (lVar4 == 0) {
    _printk(&DAT_0010359a);
  }
  else {
    ww_mutex_lock(lVar5 + 0x98,0);
    if (*(int *)(lVar5 + 0x10) != 0) {
      _printk(&DAT_00103660,"Device-Supply");
    }
    for (plVar6 = *(long **)(lVar5 + 0x28); plVar6 != (long *)(lVar5 + 0x28);
        plVar6 = (long *)*plVar6) {
      pcVar1 = "(null)-(null)";
      if ((char *)plVar6[9] != (char *)0x0) {
        pcVar1 = (char *)plVar6[9];
      }
      uVar7 = 0x4e;
      if (*(int *)(plVar6 + 3) != 0) {
        uVar7 = 0x59;
      }
      _printk(&DAT_001035b7,pcVar1,uVar7);
    }
    ww_mutex_unlock(lVar5 + 0x98);
    uVar2 = 3;
    if (gdsc_regmap_config._172_4_ == 0) {
      uVar2 = 1;
    }
    iVar3 = regmap_bulk_read(*(undefined8 *)(lVar4 + 0x148),0,&local_68,uVar2);
    if (iVar3 == 0) {
      _printk(&DAT_001034ac,*(undefined8 *)(lVar4 + 8));
      _printk(&DAT_001036f6,local_68 & 0xffffffff,local_68._4_4_,local_60);
    }
    else {
      _printk(&DAT_00103793,*(undefined8 *)(lVar4 + 8));
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_gdsc_time @ 00100954 size=112
// signature: undefined trace_raw_output_gdsc_time(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gdsc_time(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s enabling:%d time_us:%d timed_out:%d\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// gdsc_probe @ 001009c8 size=3284
// signature: undefined gdsc_probe(void)
// callers: []
//------------------------------------------------------------

ulong gdsc_probe(long param_1)

{
  ulong uVar1;
  ulong *puVar2;
  undefined8 *puVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulong *puVar9;
  undefined8 *puVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  long *plVar14;
  char *pcVar15;
  ulong uVar16;
  uint local_f0;
  uint uStack_ec;
  ulong local_e8;
  undefined8 *puStack_e0;
  ulong *local_d8;
  undefined8 uStack_d0;
  ulong local_c8;
  undefined8 uStack_c0;
  char *local_b8;
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
  
  lVar11 = sp_el0;
  uVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar11 + 0x638);
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = (ulong *)0x0;
  uStack_d0 = 0;
  local_e8 = 0;
  puStack_e0 = (undefined8 *)0x0;
  local_f0 = 0;
  uStack_ec = 0;
  puVar9 = (ulong *)devm_kmalloc(uVar1,0x210,0xdc0);
  if (puVar9 != (ulong *)0x0) {
    puVar2 = puVar9 + 1;
    puVar10 = (undefined8 *)
              of_get_regulator_init_data(uVar1,*(undefined8 *)(param_1 + 0x2f8),puVar2);
    if (puVar10 != (undefined8 *)0x0) {
      puVar3 = (undefined8 *)(param_1 + 0x2f8);
      lVar11 = of_get_property(*puVar3,"parent-supply",0);
      if (lVar11 != 0) {
        *puVar10 = "parent";
      }
      uVar12 = of_property_read_string(*puVar3,"regulator-name",puVar2);
      uVar16 = uVar12 & 0xffffffff;
      if ((int)uVar12 != 0) goto LAB_001010d8;
      lVar11 = of_find_property(*puVar3,"domain-addr",0);
      if (lVar11 == 0) {
LAB_00100abc:
        lVar11 = of_find_property(*puVar3,"sw-reset",0);
        if (lVar11 != 0) {
          uVar6 = of_count_phandle_with_args(*puVar3,"sw-reset",0);
          *(uint *)(puVar9 + 0x3f) = uVar6;
          if ((int)uVar6 < 0) {
            uVar16 = 0xfffffff4;
            puVar9[0x2c] = 0;
            goto LAB_001010d8;
          }
          uVar16 = devm_kmalloc(uVar1,(ulong)uVar6 << 3,0xcc0);
          puVar9[0x2c] = uVar16;
          if (uVar16 == 0) goto LAB_001010d4;
          if (0 < (int)puVar9[0x3f]) {
            uVar12 = 0;
            do {
              local_78 = 0;
              uStack_70 = 0;
              local_88 = 0;
              uStack_80 = 0;
              local_98 = 0;
              uStack_90 = 0;
              local_a8 = 0;
              uStack_a0 = 0;
              local_b8 = (char *)0x0;
              uStack_b0 = 0;
              iVar7 = __of_parse_phandle_with_args
                                (*puVar3,"sw-reset",0,0,uVar12 & 0xffffffff,&local_b8);
              uVar16 = 0xffffffed;
              if ((iVar7 != 0) || (local_b8 == (char *)0x0)) goto LAB_001010d8;
              uVar13 = syscon_node_to_regmap();
              *(undefined8 *)(puVar9[0x2c] + uVar12 * 8) = uVar13;
              uVar16 = *(ulong *)(puVar9[0x2c] + uVar12 * 8);
              if (0xfffffffffffff000 < uVar16) goto LAB_00100c00;
              uVar12 = uVar12 + 1;
            } while ((long)uVar12 < (long)(int)puVar9[0x3f]);
          }
        }
        lVar11 = of_find_property(*puVar3,"acd-reset",0);
        if (lVar11 == 0) {
LAB_00100bc8:
          lVar11 = of_find_property(*puVar3,"acd-misc-reset",0);
          if (lVar11 != 0) {
            uVar16 = syscon_regmap_lookup_by_phandle(*puVar3,"acd-misc-reset");
            puVar9[0x2e] = uVar16;
            if (0xfffffffffffff000 < uVar16) goto LAB_00100c00;
          }
        }
        else {
          uVar16 = syscon_regmap_lookup_by_phandle(*puVar3,"acd-reset");
          puVar9[0x2d] = uVar16;
          if (uVar16 < 0xfffffffffffff001) goto LAB_00100bc8;
LAB_00100c00:
          if ((int)uVar16 != 0) goto LAB_001010d8;
        }
        lVar11 = of_find_property(*puVar3,"hw-ctrl-addr",0);
        if (lVar11 != 0) {
          uVar16 = syscon_regmap_lookup_by_phandle(*puVar3,"hw-ctrl-addr");
          puVar9[0x2b] = uVar16;
          if (0xfffffffffffff000 < uVar16) goto LAB_00100c38;
        }
        uVar13 = *puVar3;
        *(undefined4 *)(puVar9 + 0x41) = 0x5dc;
        of_property_read_variable_u32_array(uVar13,"qcom,gds-timeout",puVar9 + 0x41,1,0);
        iVar7 = of_property_read_string_helper(*puVar3,"clock-names",0,0,0);
        *(int *)((long)puVar9 + 0x1ec) = iVar7;
        if (iVar7 == -0x16) {
          *(undefined4 *)((long)puVar9 + 0x1ec) = 0;
        }
        else if (iVar7 < 0) {
          _dev_err(uVar1,"Failed to get clock names, ret=%d\n");
          uVar16 = (ulong)*(uint *)((long)puVar9 + 0x1ec);
          goto LAB_00100c3c;
        }
        iVar7 = of_property_read_string_helper(*puVar3,"interconnect-names",0,0,0);
        *(int *)((long)puVar9 + 0x1fc) = iVar7;
        if (iVar7 == -0x16) {
          *(undefined4 *)((long)puVar9 + 0x1fc) = 0;
        }
        else if (iVar7 < 0) {
          _dev_err(uVar1,"Failed to get interconnect names, ret=%d\n");
          uVar16 = (ulong)*(uint *)((long)puVar9 + 0x1fc);
          goto LAB_00100c3c;
        }
        lVar11 = of_find_property(*puVar3,"qcom,enable-root-clk",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x1e3) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,force-enable-root-clk",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x1e4) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,reset-aon-logic",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x1e9) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,no-status-check-on-disable",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x1e5) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,retain-regs",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x1e1) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,skip-disable-before-sw-enable",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x20c) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,support-cfg-gdscr",0);
        uVar13 = *puVar3;
        *(bool *)((long)puVar9 + 0x20f) = lVar11 != 0;
        lVar11 = of_find_property(uVar13,"qcom,collapse-vote",0);
        if (lVar11 != 0) {
          iVar7 = of_property_count_elems_of_size(*puVar3,"qcom,collapse-vote",4);
          uVar6 = iVar7 - 1;
          *(uint *)(puVar9 + 0x40) = uVar6;
          if ((int)uVar6 < 0) {
            uVar16 = 0xfffffff4;
            puVar9[0x2f] = 0;
            goto LAB_001010d8;
          }
          uVar16 = devm_kmalloc(uVar1,(ulong)uVar6 << 3,0xcc0);
          puVar9[0x2f] = uVar16;
          if (uVar16 == 0) goto LAB_001010d4;
          uVar16 = (ulong)(uint)puVar9[0x40];
          if (0 < (int)(uint)puVar9[0x40]) {
            uVar12 = 0;
            do {
              local_78 = 0;
              uStack_70 = 0;
              local_88 = 0;
              uStack_80 = 0;
              local_98 = 0;
              uStack_90 = 0;
              local_a8 = 0;
              uStack_a0 = 0;
              local_b8 = (char *)0x0;
              uStack_b0 = 0;
              iVar7 = __of_parse_phandle_with_args
                                (*puVar3,"qcom,collapse-vote",0,0,uVar12 & 0xffffffff,&local_b8);
              uVar16 = 0xffffffed;
              if ((iVar7 != 0) || (local_b8 == (char *)0x0)) goto LAB_001010d8;
              uVar13 = syscon_node_to_regmap();
              *(undefined8 *)(puVar9[0x2f] + uVar12 * 8) = uVar13;
              uVar16 = *(ulong *)(puVar9[0x2f] + uVar12 * 8);
              if (0xfffffffffffff000 < uVar16) goto LAB_00100c3c;
              uVar16 = (ulong)(int)puVar9[0x40];
              uVar12 = uVar12 + 1;
            } while ((long)uVar12 < (long)uVar16);
          }
          uVar12 = of_property_read_u32_index(*puVar3,"qcom,collapse-vote",uVar16,puVar9 + 0x30);
          uVar16 = uVar12 & 0xffffffff;
          if (((int)uVar12 != 0) || (0x1f < (uint)puVar9[0x30])) {
            _dev_err(uVar1,"qcom,collapse-vote vote_bit error\n");
            goto LAB_00100c3c;
          }
        }
        lVar11 = of_find_property(*puVar3,"qcom,skip-disable",0);
        *(bool *)((long)puVar9 + 0x20d) = lVar11 != 0;
        if (lVar11 != 0) {
          *(undefined4 *)((long)puVar10 + 0x3c) = 6;
          *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) | 4;
        }
        lVar11 = of_find_property(*puVar3,"qcom,skip-logic-collapse",0);
        *(bool *)(puVar9 + 0x3c) = lVar11 == 0;
        if (lVar11 != 0) {
          iVar7 = of_property_read_string_helper(*puVar3,"reset-names",0,0,0);
          *(int *)(puVar9 + 0x3e) = iVar7;
          if (iVar7 == -0x16) {
            *(undefined4 *)(puVar9 + 0x3e) = 0;
          }
          else if (iVar7 < 0) {
            _dev_err(uVar1,"Failed to get reset clock names\n");
            uVar16 = (ulong)(uint)puVar9[0x3e];
            goto LAB_00100c3c;
          }
        }
        lVar11 = of_find_property(*puVar3,"qcom,support-hw-trigger",0);
        if (lVar11 != 0) {
          *(uint *)((long)puVar10 + 0x3c) = *(uint *)((long)puVar10 + 0x3c) | 3;
          *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) | 4;
          *(undefined1 *)((long)puVar9 + 0x1ea) = 1;
        }
      }
      else {
        uVar16 = syscon_regmap_lookup_by_phandle(*puVar3,"domain-addr");
        puVar9[0x2a] = uVar16;
        if (uVar16 < 0xfffffffffffff001) goto LAB_00100abc;
LAB_00100c38:
        uVar16 = uVar16 & 0xffffffff;
LAB_00100c3c:
        if ((int)uVar16 != 0) goto LAB_001010d8;
      }
      plVar14 = (long *)platform_get_resource(param_1,0x200,0);
      if (plVar14 == (long *)0x0) {
        pcVar15 = "Failed to get address resource\n";
LAB_0010112c:
        _dev_err(uVar1,pcVar15);
        uVar16 = 0xffffffea;
        goto LAB_001010d8;
      }
      uVar16 = devm_ioremap(uVar1,*plVar14,(plVar14[1] - *plVar14) + 1);
      puVar9[0x28] = uVar16;
      if (uVar16 == 0) goto LAB_001010d4;
      lVar11 = of_find_property(*puVar3,"qcom,no-config-gdscr",0);
      if (lVar11 != 0) {
        gdsc_regmap_config._172_4_ = 0;
      }
      uVar16 = __devm_regmap_init_mmio_clk(uVar1,0,puVar9[0x28],gdsc_regmap_config,0,0);
      puVar9[0x29] = uVar16;
      if (uVar16 == 0) {
        pcVar15 = "Couldn\'t get regmap\n";
        goto LAB_0010112c;
      }
      uVar6 = *(uint *)((long)puVar9 + 0x1ec);
      if ((int)uVar6 < 0) {
        uVar16 = 0;
        puVar9[0x31] = 0;
      }
      else {
        uVar16 = devm_kmalloc(uVar1,(ulong)uVar6 << 3,0xdc0);
        uVar6 = *(uint *)((long)puVar9 + 0x1ec);
        puVar9[0x31] = uVar16;
      }
      if ((uVar6 == 0) || (uVar16 != 0)) {
        *(undefined4 *)((long)puVar9 + 500) = 0xffffffff;
        if (0 < (int)uVar6) {
          uVar16 = 0;
          do {
            local_b8 = (char *)0x0;
            of_property_read_string_helper(*puVar3,"clock-names",&local_b8,1,uVar16 & 0xffffffff);
            uVar13 = devm_clk_get(uVar1,local_b8);
            *(undefined8 *)(puVar9[0x31] + uVar16 * 8) = uVar13;
            uVar12 = *(ulong *)(puVar9[0x31] + uVar16 * 8);
            if (0xfffffffffffff000 < uVar12) goto LAB_001012fc;
            iVar7 = strcmp(local_b8,"core_root_clk");
            if (iVar7 == 0) {
              *(int *)((long)puVar9 + 500) = (int)uVar16;
            }
            uVar16 = uVar16 + 1;
          } while ((long)uVar16 < (long)*(int *)((long)puVar9 + 0x1ec));
        }
        uVar6 = *(uint *)((long)puVar9 + 0x1fc);
        if ((int)uVar6 < 0) {
          uVar16 = 0;
          puVar9[0x3b] = 0;
        }
        else {
          uVar16 = devm_kmalloc(uVar1,(ulong)uVar6 << 3,0xdc0);
          uVar6 = *(uint *)((long)puVar9 + 0x1fc);
          puVar9[0x3b] = uVar16;
        }
        if ((uVar6 == 0) || (uVar16 != 0)) {
          if (0 < (int)uVar6) {
            uVar16 = 0;
            do {
              local_b8 = (char *)0x0;
              of_property_read_string_helper
                        (*puVar3,"interconnect-names",&local_b8,1,uVar16 & 0xffffffff);
              uVar13 = of_icc_get(uVar1,local_b8);
              *(undefined8 *)(puVar9[0x3b] + uVar16 * 8) = uVar13;
              uVar12 = *(ulong *)(puVar9[0x3b] + uVar16 * 8);
              if (0xfffffffffffff000 < uVar12) {
                uVar16 = uVar12 & 0xffffffff;
                if ((int)uVar12 == -0x205) goto LAB_00101324;
                pcVar15 = "Failed to get path %s, ret=%d\n";
                goto LAB_00101664;
              }
              uVar16 = uVar16 + 1;
            } while ((long)uVar16 < (long)*(int *)((long)puVar9 + 0x1fc));
          }
          if (((*(char *)((long)puVar9 + 0x1e3) != '\0') ||
              (*(char *)((long)puVar9 + 0x1e4) != '\0')) && (*(int *)((long)puVar9 + 500) == -1)) {
            pcVar15 = "Failed to get root clock name\n";
            goto LAB_0010112c;
          }
          if ((char)puVar9[0x3c] == '\0') {
            uVar6 = (uint)puVar9[0x3e];
            if ((int)uVar6 < 0) {
              uVar16 = 0;
              puVar9[0x3a] = 0;
            }
            else {
              uVar16 = devm_kmalloc(uVar1,(ulong)uVar6 << 3,0xdc0);
              uVar6 = (uint)puVar9[0x3e];
              puVar9[0x3a] = uVar16;
            }
            if ((uVar6 != 0) && (uVar16 == 0)) goto LAB_001010d4;
            if (0 < (int)uVar6) {
              uVar16 = 0;
              do {
                local_b8 = (char *)0x0;
                of_property_read_string_helper
                          (*puVar3,"reset-names",&local_b8,1,uVar16 & 0xffffffff);
                uVar13 = __devm_reset_control_get(uVar1,local_b8,0,0,0,1);
                *(undefined8 *)(puVar9[0x3a] + uVar16 * 8) = uVar13;
                uVar12 = *(ulong *)(puVar9[0x3a] + uVar16 * 8);
                if (0xfffffffffffff000 < uVar12) goto LAB_001012fc;
                uVar16 = uVar16 + 1;
              } while ((long)uVar16 < (long)(int)puVar9[0x3e]);
            }
          }
LAB_00101328:
          regmap_read(puVar9[0x29],0,&uStack_ec);
          uStack_ec = uStack_ec & 0xfffffff9;
          lVar11 = of_find_property(*puVar3,"mboxes",0);
          if (lVar11 == 0) {
LAB_0010138c:
            iVar7 = of_property_read_variable_u32_array
                              (*puVar3,"qcom,clk-dis-wait-val",&local_f0,1,0);
            if (-1 < iVar7) {
              *(undefined1 *)((long)puVar9 + 0x1ea) = 1;
              local_f0 = local_f0 << 0xc;
              uStack_ec = uStack_ec & 0xffff0fff | local_f0;
              *(uint *)((long)puVar9 + 0x204) = local_f0;
            }
            regmap_write(puVar9[0x29],0,uStack_ec);
            if ((char)puVar9[0x3c] == '\0') {
              uStack_ec = uStack_ec & 0xfffffffe;
              regmap_write(puVar9[0x29],0);
              uVar12 = check_gdsc_status(puVar9,uVar1,1);
              uVar16 = uVar12 & 0xffffffff;
              if ((int)uVar12 == 0) {
                local_b8 = (char *)((ulong)local_b8 & 0xffffffff00000000);
                if ((char)puVar9[0x3c] != '\0') goto LAB_001013ec;
                *(byte *)((long)puVar9 + 0x1e6) = *(byte *)((long)puVar9 + 0x1e2) ^ 1;
                goto LAB_001014bc;
              }
            }
            else {
              local_b8 = (char *)((ulong)local_b8 & 0xffffffff00000000);
LAB_001013ec:
              iVar7 = (int)puVar9[0x40];
              if (iVar7 == 0) {
                uVar16 = puVar9[0x29];
                uVar6 = 1;
              }
              else {
                if (iVar7 < 1) {
                  uVar16 = 0;
                }
                else {
                  uVar16 = *(ulong *)(puVar9[0x2f] + (ulong)(iVar7 - 1) * 8);
                }
                uVar6 = (uint)(1L << ((ulong)(uint)puVar9[0x30] & 0x3f));
              }
              uVar8 = regmap_read(uVar16,0,&local_b8);
              if ((int)uVar8 < 0) {
                uVar12 = *puVar2;
                pcVar15 = "%s failed to get initial enable state, ret=%d\n";
              }
              else {
                *(bool *)((long)puVar9 + 0x1e6) = ((uint)local_b8 & uVar6) == 0;
                if ((((uint)local_b8 & uVar6) == 0) && (*(char *)((long)puVar9 + 0x1e1) != '\0')) {
                  regmap_update_bits_base(puVar9[0x29],0,0x800,0x800,0,0,0);
                }
LAB_001014bc:
                local_b8 = (char *)((ulong)local_b8 & 0xffffffff00000000);
                uVar8 = regmap_read(puVar9[0x29],0,&local_b8);
                if (-1 < (int)uVar8) {
                  *(byte *)((long)puVar9 + 0x1e7) = (byte)local_b8 >> 1 & 1;
                  if (*(char *)((long)puVar9 + 0x1ea) != '\0') {
                    *(undefined1 **)(*(long *)(param_1 + 0x98) + 0x78) = gdsc_pm_ops;
                  }
                  Hint_Prefetch(0x102c28,2,0,1);
                  do {
                    iVar7 = gdsc_probe_gdsc_count + 1;
                    cVar4 = '\x01';
                    bVar5 = (bool)ExclusiveMonitorPass(0x102c28,0x10);
                    if (bVar5) {
                      cVar4 = ExclusiveMonitorsStatus();
                      gdsc_probe_gdsc_count = iVar7;
                    }
                  } while (cVar4 != '\0');
                  DataMemoryBarrier(2,3);
                  *(int *)(puVar9 + 7) = iVar7;
                  local_c8 = puVar9[0x29];
                  *(undefined4 *)((long)puVar9 + 0x54) = 0;
                  puVar9[9] = (ulong)gdsc_ops;
                  puVar9[0xb] = (ulong)&__this_module;
                  uStack_d0 = *puVar3;
                  local_e8 = uVar1;
                  puStack_e0 = puVar10;
                  local_d8 = puVar9;
                  uVar16 = devm_regulator_register(uVar1,puVar2,&local_e8);
                  *puVar9 = uVar16;
                  if (uVar16 < 0xfffffffffffff001) {
                    uVar6 = devm_regulator_proxy_consumer_register(uVar1,*puVar3);
                    if (uVar6 == 0) {
                      iVar7 = devm_regulator_debug_register(uVar1,*puVar9);
                      if (iVar7 != 0) {
                        _dev_err(uVar1,"failed to register debug regulator, ret=%d\n",iVar7);
                      }
                      uVar16 = 0;
                      *(ulong **)(param_1 + 0xa8) = puVar9;
                      goto LAB_001010d8;
                    }
                    uVar16 = (ulong)uVar6;
                    _dev_err(uVar1,"failed to register proxy consumer, ret=%d\n",uVar16);
                  }
                  else {
                    _dev_err(uVar1,"regulator_register(\"%s\") failed, ret=%d\n",*puVar2,
                             uVar16 & 0xffffffff);
                  }
                  goto LAB_00101624;
                }
                uVar12 = *puVar2;
                pcVar15 = "%s failed to get initial hw_ctrl state, ret=%d\n";
              }
              uVar16 = (ulong)uVar8;
              _dev_err(uVar1,pcVar15,uVar12,uVar16);
            }
          }
          else {
            puVar9[0x32] = uVar1;
            *(undefined1 *)(puVar9 + 0x33) = 1;
            puVar9[0x34] = 500;
            *(undefined1 *)(puVar9 + 0x35) = 0;
            uVar16 = mbox_request_channel(puVar9 + 0x32,0);
            puVar9[0x39] = uVar16;
            if (uVar16 < 0xfffffffffffff001) goto LAB_0010138c;
            _dev_err(uVar1,"mailbox channel request failed, ret=%d\n",uVar16 & 0xffffffff);
            uVar6 = 0xfffffdfb;
            if ((uint)uVar16 != 0xfffffff5) {
              uVar6 = (uint)uVar16;
            }
            uVar16 = (ulong)uVar6;
            puVar9[0x39] = 0;
          }
LAB_00101624:
          if (puVar9[0x39] != 0) {
            mbox_free_channel();
          }
          goto LAB_001010d8;
        }
      }
    }
  }
LAB_001010d4:
  uVar16 = 0xfffffff4;
LAB_001010d8:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16 & 0xffffffff;
LAB_001012fc:
  uVar16 = uVar12 & 0xffffffff;
  if ((int)uVar12 == -0x205) {
LAB_00101324:
    iVar7 = (int)uVar16;
  }
  else {
    pcVar15 = "Failed to get %s, ret=%d\n";
LAB_00101664:
    _dev_err(uVar1,pcVar15,local_b8,uVar16);
    iVar7 = (int)uVar16;
  }
  if (iVar7 != 0) goto LAB_001010d8;
  goto LAB_00101328;
}



//------------------------------------------------------------
// check_gdsc_status @ 001016b0 size=444
// signature: undefined check_gdsc_status(void)
// callers: [gdsc_disable, gdsc_probe, gdsc_enable, gdsc_set_mode]
//------------------------------------------------------------

int check_gdsc_status(long param_1,long param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if (param_1 == 0) {
    iVar3 = -0x16;
  }
  else {
    iVar3 = -0x16;
    if ((param_2 != 0) && (*(long *)(param_1 + 0x148) != 0)) {
      iVar3 = poll_gdsc_status(param_1,param_3);
      if (iVar3 != 0) {
        regmap_read(*(undefined8 *)(param_1 + 0x148),0,(long)&local_50 + 4);
        if (*(long *)(param_1 + 0x158) == 0) {
          if (1 < param_3) {
LAB_00101868:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x10186c);
            (*pcVar2)();
          }
          puVar4 = (&check_gdsc_status_gdsc_states)[param_3];
          _dev_err(param_2,"%s %s timed out: 0x%x\n",*(undefined8 *)(param_1 + 8),puVar4,
                   local_50._4_4_);
          __udelay(*(undefined4 *)(param_1 + 0x208));
          regmap_read(*(undefined8 *)(param_1 + 0x148),0,(long)&local_50 + 4);
          _dev_err(param_2,"%s %s final state: 0x%x (%d us timeout)\n",*(undefined8 *)(param_1 + 8),
                   puVar4,local_50._4_4_,*(undefined4 *)(param_1 + 0x208));
        }
        else {
          regmap_read(*(long *)(param_1 + 0x158),0,&local_50);
          if (1 < param_3) goto LAB_00101868;
          puVar4 = (&check_gdsc_status_gdsc_states)[param_3];
          _dev_warn(param_2,
                    "%s %s state (after %d us timeout): 0x%x, GDS_HW_CTRL: 0x%x. Re-polling.\n",
                    *(undefined8 *)(param_1 + 8),puVar4,*(undefined4 *)(param_1 + 0x208),
                    local_50._4_4_,local_50 & 0xffffffff);
          iVar3 = poll_gdsc_status(param_1,param_3);
          if (iVar3 != 0) {
            regmap_read(*(undefined8 *)(param_1 + 0x148),0,(long)&local_50 + 4);
            regmap_read(*(undefined8 *)(param_1 + 0x158),0,&local_50);
            _dev_err(param_2,
                     "%s %s final state (after additional %d us timeout): 0x%x, GDS_HW_CTRL: 0x%x\n"
                     ,*(undefined8 *)(param_1 + 8),puVar4,*(undefined4 *)(param_1 + 0x208),
                     local_50._4_4_,local_50 & 0xffffffff);
          }
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// poll_gdsc_status @ 0010186c size=388
// signature: undefined poll_gdsc_status(void)
// callers: [check_gdsc_status]
//------------------------------------------------------------

undefined8 poll_gdsc_status(long param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  lVar3 = *(long *)(param_1 + 0x158);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_1 + 0x148);
    if (*(char *)(param_1 + 0x20f) == '\0') goto LAB_001018e8;
  }
  else {
    if (*(char *)(param_1 + 0x20f) == '\0') {
LAB_001018e8:
      uVar4 = 0;
      goto joined_r0x001018dc;
    }
    lVar3 = *(long *)(param_1 + 0x148);
  }
  uVar4 = 4;
joined_r0x001018dc:
  iVar5 = *(int *)(param_1 + 0x208);
  if (0 < *(int *)(param_1 + 0x208)) {
    do {
      regmap_read(lVar3,uVar4,&local_4c);
      if (param_2 == 0) {
        if (*(char *)(param_1 + 0x20f) == '\0') {
          local_4c = -((int)~local_4c >> 0x1f);
        }
        else {
          local_4c = local_4c & 0x8000;
        }
      }
      else if (param_2 == 1) {
        if (*(char *)(param_1 + 0x20f) == '\0') {
          local_4c = local_4c & 0x80000000;
        }
        else {
          local_4c = local_4c & 0x10000;
        }
      }
      if (local_4c != 0) {
        uVar4 = 0;
        goto LAB_001019b8;
      }
      __const_udelay(0x10c7);
      iVar2 = iVar5 + -1;
      bVar1 = 0 < iVar5;
      iVar5 = iVar2;
    } while (iVar2 != 0 && bVar1);
  }
  uVar4 = 0xffffff92;
LAB_001019b8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// gdsc_pm_resume_early @ 00101b50 size=52
// signature: undefined gdsc_pm_resume_early(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gdsc_pm_resume_early(void)

{
  undefined8 uVar1;
  
  if (_pm_suspend_target_state == 3) {
    uVar1 = restore_hw_trig_clk_dis();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gdsc_pm_restore_early @ 00101b88 size=28
// signature: undefined gdsc_pm_restore_early(void)
// callers: []
//------------------------------------------------------------

void gdsc_pm_restore_early(void)

{
  restore_hw_trig_clk_dis();
  return;
}



//------------------------------------------------------------
// restore_hw_trig_clk_dis @ 00101ba4 size=232
// signature: undefined restore_hw_trig_clk_dis(void)
// callers: [gdsc_pm_resume_early, gdsc_pm_restore_early]
//------------------------------------------------------------

int restore_hw_trig_clk_dis(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  plVar3 = *(long **)(param_1 + 0x98);
  local_2c = 0;
  if ((*(long *)(*plVar3 + 0x480) == 0) || (iVar2 = regulator_enable(), iVar2 == 0)) {
    regmap_read(plVar3[0x29],0,&local_2c);
    if (*(char *)((long)plVar3 + 0x1e7) != '\0') {
      local_2c = local_2c | 2;
    }
    if (*(uint *)((long)plVar3 + 0x204) != 0) {
      local_2c = local_2c & 0xffff0fff | *(uint *)((long)plVar3 + 0x204);
    }
    iVar2 = regmap_write(plVar3[0x29],0);
    if (*(long *)(*plVar3 + 0x480) != 0) {
      regulator_disable(*(long *)(*plVar3 + 0x480));
    }
  }
  else {
    _dev_err(*plVar3 + 0xe8,"reg enable failed\n");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gdsc_enable @ 00101c90 size=1328
// signature: undefined gdsc_enable(void)
// callers: []
//------------------------------------------------------------

int gdsc_enable(long param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint local_b0;
  uint local_ac;
  undefined8 local_a8;
  undefined8 *local_a0;
  undefined8 local_98;
  char acStack_90 [8];
  char local_88 [8];
  char acStack_80 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  plVar2 = (long *)rdev_get_drvdata();
  iVar1 = 0;
  local_b0 = 0;
  if (*(char *)((long)plVar2 + 0x20c) == '\0') {
    if ((*(char *)((long)plVar2 + 0x1e3) != '\0') || (*(char *)((long)plVar2 + 0x1e4) != '\0')) {
      uVar4 = *(undefined8 *)(plVar2[0x31] + (long)*(int *)((long)plVar2 + 500) * 8);
      iVar1 = clk_prepare(uVar4);
      if ((iVar1 == 0) && (iVar1 = clk_enable(uVar4), iVar1 != 0)) {
        clk_unprepare(uVar4);
      }
      *(undefined1 *)(plVar2 + 0x3d) = 1;
    }
    regmap_read(plVar2[0x29],0,&local_b0);
    if (((byte)local_b0 >> 1 & 1) == 0) {
      if ((char)plVar2[0x3c] == '\0') {
        if (0 < (int)plVar2[0x3e]) {
          lVar5 = 0;
          do {
            reset_control_deassert(*(undefined8 *)(plVar2[0x3a] + lVar5 * 8));
            lVar5 = lVar5 + 1;
          } while (lVar5 < (int)plVar2[0x3e]);
        }
        *(undefined1 *)((long)plVar2 + 0x1e2) = 0;
      }
      else {
        if (0 < *(int *)((long)plVar2 + 0x1fc)) {
          uVar6 = 0;
          do {
            iVar1 = icc_set_bw(*(undefined8 *)(plVar2[0x3b] + uVar6 * 8),1,1);
            if (iVar1 != 0) {
              _dev_err(param_1 + 0xe8,"Failed to vote BW for %d, ret=%d\n",uVar6 & 0xffffffff,iVar1)
              ;
              goto LAB_00102128;
            }
            uVar6 = uVar6 + 1;
          } while ((long)uVar6 < (long)*(int *)((long)plVar2 + 0x1fc));
        }
        if ((int)plVar2[0x3f] != 0) {
          if (0 < (int)plVar2[0x3f]) {
            lVar5 = 0;
            do {
              regmap_update_bits_base(*(undefined8 *)(plVar2[0x2c] + lVar5 * 8),0,1,1,0,0,0);
              lVar5 = lVar5 + 1;
            } while (lVar5 < (int)plVar2[0x3f]);
          }
          if (plVar2[0x2d] != 0) {
            regmap_update_bits_base(plVar2[0x2d],0,1,1,0,0,0);
          }
          if (plVar2[0x2e] != 0) {
            regmap_update_bits_base(plVar2[0x2e],0,1,1,0,0,0);
          }
          local_98 = (ulong)local_98._4_4_ << 0x20;
          regmap_read(plVar2[0x29],0,&local_98);
          __const_udelay(0x68dbc);
          if (0 < (int)plVar2[0x3f]) {
            lVar5 = 0;
            do {
              regmap_update_bits_base(*(undefined8 *)(plVar2[0x2c] + lVar5 * 8),0,1,0,0,0,0);
              lVar5 = lVar5 + 1;
            } while (lVar5 < (int)plVar2[0x3f]);
          }
          if (plVar2[0x2d] != 0) {
            regmap_update_bits_base(plVar2[0x2d],0,1,0,0,0,0);
          }
          if (plVar2[0x2e] != 0) {
            regmap_update_bits_base(plVar2[0x2e],0,1,0,0,0,0);
          }
          local_98 = local_98 & 0xffffffff00000000;
          regmap_read(plVar2[0x29],0,&local_98);
        }
        lVar5 = plVar2[0x2a];
        if (lVar5 != 0) {
          if (*(char *)((long)plVar2 + 0x1e9) != '\0') {
            regmap_read(lVar5,0,&local_b0);
            local_b0 = local_b0 | 0x10;
            regmap_write(plVar2[0x2a],0);
            local_98 = local_98 & 0xffffffff00000000;
            regmap_read(plVar2[0x29],0,&local_98);
            __const_udelay(0x10c7);
            local_b0 = local_b0 & 0xffffffef;
            regmap_write(plVar2[0x2a],0);
            local_98 = local_98 & 0xffffffff00000000;
            regmap_read(plVar2[0x29],0,&local_98);
            lVar5 = plVar2[0x2a];
          }
          regmap_read(lVar5,0,&local_b0);
          local_b0 = local_b0 & 0xfffffffe;
          regmap_write(plVar2[0x2a],0);
          local_98 = local_98 & 0xffffffff00000000;
          regmap_read(plVar2[0x29],0,&local_98);
        }
        if (plVar2[0x39] == 0) {
          if ((int)plVar2[0x40] == 0) {
            regmap_read(plVar2[0x29],0,&local_b0);
            local_b0 = local_b0 & 0xfffffffe;
            regmap_write(plVar2[0x29],0);
          }
          else if (0 < (int)plVar2[0x40]) {
            lVar5 = 0;
            do {
              lVar3 = 1L << ((ulong)*(uint *)(plVar2 + 0x30) & 0x3f);
              regmap_update_bits_base
                        (*(undefined8 *)(plVar2[0x2f] + lVar5 * 8),0,lVar3,~(uint)lVar3,0,0,0);
              lVar5 = lVar5 + 1;
            } while (lVar5 < (int)plVar2[0x40]);
          }
        }
        else {
          local_48 = 0;
          uStack_40 = 0;
          local_58 = 0;
          uStack_50 = 0;
          local_68 = 0;
          uStack_60 = 0;
          local_78 = 0;
          uStack_70 = 0;
          local_98._0_1_ = s__class__clock__res__gpu_noc_wa__00103010[0];
          local_98._1_1_ = s__class__clock__res__gpu_noc_wa__00103010[1];
          local_98._2_1_ = s__class__clock__res__gpu_noc_wa__00103010[2];
          local_98._3_1_ = s__class__clock__res__gpu_noc_wa__00103010[3];
          local_98._4_1_ = s__class__clock__res__gpu_noc_wa__00103010[4];
          local_98._5_1_ = s__class__clock__res__gpu_noc_wa__00103010[5];
          local_98._6_1_ = s__class__clock__res__gpu_noc_wa__00103010[6];
          local_98._7_1_ = s__class__clock__res__gpu_noc_wa__00103010[7];
          acStack_90[0] = s__class__clock__res__gpu_noc_wa__00103010[8];
          acStack_90[1] = s__class__clock__res__gpu_noc_wa__00103010[9];
          acStack_90[2] = s__class__clock__res__gpu_noc_wa__00103010[10];
          acStack_90[3] = s__class__clock__res__gpu_noc_wa__00103010[0xb];
          acStack_90[4] = s__class__clock__res__gpu_noc_wa__00103010[0xc];
          acStack_90[5] = s__class__clock__res__gpu_noc_wa__00103010[0xd];
          acStack_90[6] = s__class__clock__res__gpu_noc_wa__00103010[0xe];
          acStack_90[7] = s__class__clock__res__gpu_noc_wa__00103010[0xf];
          local_ac = 0;
          local_88[0] = s__class__clock__res__gpu_noc_wa__00103010[0x10];
          local_88[1] = s__class__clock__res__gpu_noc_wa__00103010[0x11];
          local_88[2] = s__class__clock__res__gpu_noc_wa__00103010[0x12];
          local_88[3] = s__class__clock__res__gpu_noc_wa__00103010[0x13];
          local_88[4] = s__class__clock__res__gpu_noc_wa__00103010[0x14];
          local_88[5] = s__class__clock__res__gpu_noc_wa__00103010[0x15];
          local_88[6] = s__class__clock__res__gpu_noc_wa__00103010[0x16];
          local_88[7] = s__class__clock__res__gpu_noc_wa__00103010[0x17];
          acStack_80[0] = s__class__clock__res__gpu_noc_wa__00103010[0x18];
          acStack_80[1] = s__class__clock__res__gpu_noc_wa__00103010[0x19];
          acStack_80[2] = s__class__clock__res__gpu_noc_wa__00103010[0x1a];
          acStack_80[3] = s__class__clock__res__gpu_noc_wa__00103010[0x1b];
          acStack_80[4] = s__class__clock__res__gpu_noc_wa__00103010[0x1c];
          acStack_80[5] = s__class__clock__res__gpu_noc_wa__00103010[0x1d];
          acStack_80[6] = s__class__clock__res__gpu_noc_wa__00103010[0x1e];
          acStack_80[7] = s__class__clock__res__gpu_noc_wa__00103010[0x1f];
          local_a8 = 0x60;
          regmap_read(plVar2[0x29],0,&local_ac);
          if ((local_ac & 1) != 0) {
            local_a0 = &local_98;
            iVar1 = mbox_send_message(plVar2[0x39],&local_a8);
            if (iVar1 < 0) {
              _dev_err(*plVar2 + 0xe8,"qmp message send failed, ret=%d\n",iVar1);
              goto LAB_00102128;
            }
          }
        }
        local_98 = local_98 & 0xffffffff00000000;
        regmap_read(plVar2[0x29],0,&local_98);
        __const_udelay(0x10c7);
        iVar1 = check_gdsc_status(plVar2,param_1 + 0xe8,1);
        if (iVar1 != 0) goto LAB_00102128;
        if ((*(char *)((long)plVar2 + 0x1e1) != '\0') && ((local_b0 >> 0xb & 1) == 0)) {
          local_b0 = local_b0 | 0x800;
          regmap_write(plVar2[0x29],0);
        }
      }
      __const_udelay(0x10c7);
      __const_udelay(0x10c7);
      if (*(char *)((long)plVar2 + 0x1e4) != '\0') {
        uVar4 = *(undefined8 *)(plVar2[0x31] + (long)*(int *)((long)plVar2 + 500) * 8);
        clk_disable(uVar4);
        clk_unprepare(uVar4);
        *(undefined1 *)(plVar2 + 0x3d) = 0;
      }
      iVar1 = 0;
      *(undefined1 *)((long)plVar2 + 0x1e6) = 1;
    }
    else {
      _dev_warn(param_1 + 0xe8,"Invalid enable while %s is under HW control\n",plVar2[1]);
      iVar1 = -0x10;
    }
  }
LAB_00102128:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// gdsc_disable @ 001021c4 size=808
// signature: undefined gdsc_disable(void)
// callers: []
//------------------------------------------------------------

int gdsc_disable(long param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = rdev_get_drvdata();
  local_50 = 0;
  if (*(long *)(param_1 + 0x480) == 0) {
    lVar8 = 0;
    bVar2 = false;
    cVar1 = *(char *)(lVar4 + 0x1e4);
  }
  else {
    lVar8 = *(long *)(*(long *)(param_1 + 0x480) + 0x78);
    iVar3 = ww_mutex_trylock(lVar8 + 0x98,0);
    bVar2 = iVar3 != 0;
    if (*(int *)(lVar8 + 0xc) == 0) {
      _dev_err(param_1 + 0xe8,"%s cannot disable GDSC while parent is disabled\n",
               *(undefined8 *)(lVar4 + 8));
      iVar3 = -5;
      goto LAB_00102448;
    }
    cVar1 = *(char *)(lVar4 + 0x1e4);
  }
  if (cVar1 != '\0') {
    uVar7 = *(undefined8 *)(*(long *)(lVar4 + 0x188) + (long)*(int *)(lVar4 + 500) * 8);
    iVar3 = clk_prepare(uVar7);
    if ((iVar3 == 0) && (iVar3 = clk_enable(uVar7), iVar3 != 0)) {
      clk_unprepare(uVar7);
    }
    *(undefined1 *)(lVar4 + 0x1e8) = 1;
  }
  __const_udelay(0x10c7);
  if ((*(char *)(lVar4 + 0x20d) == '\0') || (*(char *)(lVar4 + 0x20e) != '\0')) {
    if (*(char *)(lVar4 + 0x1e0) == '\0') {
      iVar3 = *(int *)(lVar4 + 0x1f0);
      if (-1 < (int)(iVar3 - 1U)) {
        lVar6 = (ulong)(iVar3 - 1U) << 3;
        do {
          reset_control_assert(*(undefined8 *)(*(long *)(lVar4 + 0x1d0) + lVar6));
          iVar3 = iVar3 + -1;
          lVar6 = lVar6 + -8;
        } while (0 < iVar3);
      }
      *(undefined1 *)(lVar4 + 0x1e2) = 1;
    }
    else {
      if ((*(int *)(lVar4 + 0x1f8) != 0) && (*(long *)(lVar4 + 0x170) != 0)) {
        regmap_update_bits_base(*(long *)(lVar4 + 0x170),0,1,1,0,0,0);
      }
      if (*(int *)(lVar4 + 0x200) == 0) {
        regmap_read(*(undefined8 *)(lVar4 + 0x148),0,&local_50);
        local_50 = local_50 | 1;
        regmap_write(*(undefined8 *)(lVar4 + 0x148),0);
      }
      else if (0 < *(int *)(lVar4 + 0x200)) {
        lVar6 = 0;
        do {
          uVar5 = 1L << ((ulong)*(uint *)(lVar4 + 0x180) & 0x3f);
          regmap_update_bits_base
                    (*(undefined8 *)(*(long *)(lVar4 + 0x178) + lVar6 * 8),0,uVar5,
                     uVar5 & 0xffffffff,0,0,0);
          lVar6 = lVar6 + 1;
        } while (lVar6 < *(int *)(lVar4 + 0x200));
      }
      local_4c = 0;
      regmap_read(*(undefined8 *)(lVar4 + 0x148),0,&local_4c);
      __const_udelay(0x10c7);
      if (*(char *)(lVar4 + 0x1e5) == '\0') {
        iVar3 = check_gdsc_status(lVar4,param_1 + 0xe8,0);
        if (iVar3 != 0) goto LAB_00102448;
      }
      else {
        __const_udelay(0x68dbc);
      }
      if (*(long *)(lVar4 + 0x150) != 0) {
        regmap_read(*(long *)(lVar4 + 0x150),0,&local_50);
        local_50 = local_50 | 1;
        regmap_write(*(undefined8 *)(lVar4 + 0x150),0);
      }
      if (0 < *(int *)(lVar4 + 0x1fc)) {
        uVar5 = 0;
        do {
          iVar3 = icc_set_bw(*(undefined8 *)(*(long *)(lVar4 + 0x1d8) + uVar5 * 8),0,0);
          if (iVar3 != 0) {
            _dev_err(param_1 + 0xe8,"Failed to unvote BW for %d: %d\n",uVar5 & 0xffffffff,iVar3);
            goto LAB_00102448;
          }
          uVar5 = uVar5 + 1;
        } while ((long)uVar5 < (long)*(int *)(lVar4 + 0x1fc));
      }
    }
  }
  if (((*(char *)(lVar4 + 0x1e8) != '\0') && (*(char *)(lVar4 + 0x1e3) != '\0')) ||
     (*(char *)(lVar4 + 0x1e4) != '\0')) {
    uVar7 = *(undefined8 *)(*(long *)(lVar4 + 0x188) + (long)*(int *)(lVar4 + 500) * 8);
    clk_disable(uVar7);
    clk_unprepare(uVar7);
    *(undefined1 *)(lVar4 + 0x1e8) = 0;
  }
  iVar3 = 0;
  *(undefined1 *)(lVar4 + 0x1e6) = 0;
LAB_00102448:
  if ((*(long *)(param_1 + 0x480) != 0) && (bVar2)) {
    ww_mutex_unlock(lVar8 + 0x98);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// gdsc_is_enabled @ 001024f0 size=88
// signature: undefined gdsc_is_enabled(void)
// callers: []
//------------------------------------------------------------

bool gdsc_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  if (*(char *)(lVar1 + 0x20d) == '\0') {
    if (*(char *)(lVar1 + 0x1e0) == '\0') {
      return *(char *)(lVar1 + 0x1e2) == '\0';
    }
    if (*(char *)(lVar1 + 0x20c) != '\0') {
      return false;
    }
  }
  return *(char *)(lVar1 + 0x1e6) != '\0';
}



//------------------------------------------------------------
// gdsc_set_mode @ 0010254c size=476
// signature: undefined gdsc_set_mode(void)
// callers: []
//------------------------------------------------------------

int gdsc_set_mode(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint local_50 [2];
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar2 = rdev_get_drvdata();
  local_50[0] = 0;
  if (*(char *)(lVar2 + 0x20d) != '\0') {
    if (param_2 == 2) {
      iVar1 = 0;
      *(undefined1 *)(lVar2 + 0x20e) = 0;
    }
    else if (param_2 == 4) {
      iVar1 = 0;
      *(undefined1 *)(lVar2 + 0x20e) = 1;
    }
    else {
      iVar1 = -0x16;
    }
    goto LAB_001026f0;
  }
  if (*(long *)(param_1 + 0x480) == 0) {
    lVar3 = 0;
LAB_00102604:
    iVar1 = regmap_read(*(undefined8 *)(lVar2 + 0x148),0,local_50);
    if (-1 < iVar1) {
      if (param_2 == 2) {
        local_50[0] = local_50[0] & 0xfffffffd;
        iVar1 = regmap_write(*(undefined8 *)(lVar2 + 0x148),0);
        if (-1 < iVar1) {
          local_50[1] = 0;
          regmap_read(*(undefined8 *)(lVar2 + 0x148),0,local_50 + 1);
          __const_udelay(0x10c7);
          if ((*(char *)(lVar2 + 0x1e6) == '\0') ||
             (iVar1 = check_gdsc_status(lVar2,param_1 + 0xe8,1), iVar1 == 0)) {
            *(undefined1 *)(lVar2 + 0x1e7) = 0;
          }
        }
      }
      else if (param_2 == 1) {
        local_50[0] = local_50[0] | 2;
        iVar1 = regmap_write(*(undefined8 *)(lVar2 + 0x148),0);
        if (-1 < iVar1) {
          local_50[1] = 0;
          regmap_read(*(undefined8 *)(lVar2 + 0x148),0,local_50 + 1);
          __const_udelay(0x10c7);
          *(undefined1 *)(lVar2 + 0x1e7) = 1;
        }
      }
      else {
        iVar1 = -0x16;
      }
    }
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x480) + 0x78);
    ww_mutex_lock(lVar3 + 0x98,0);
    if (*(int *)(lVar3 + 0xc) != 0) goto LAB_00102604;
    _dev_err(param_1 + 0xe8,"%s cannot change GDSC HW/SW control mode while parent is disabled\n",
             *(undefined8 *)(lVar2 + 8));
    iVar1 = -5;
  }
  if (*(long *)(param_1 + 0x480) != 0) {
    ww_mutex_unlock(lVar3 + 0x98);
  }
LAB_001026f0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// gdsc_get_mode @ 0010272c size=72
// signature: undefined gdsc_get_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 gdsc_get_mode(void)

{
  undefined4 uVar1;
  long lVar2;
  bool bVar3;
  long lVar4;
  undefined4 uVar5;
  
  lVar4 = rdev_get_drvdata();
  bVar3 = *(char *)(lVar4 + 0x20d) != '\0';
  lVar2 = 0x1e7;
  if (bVar3) {
    lVar2 = 0x20e;
  }
  uVar5 = 4;
  if (!bVar3) {
    uVar5 = 1;
  }
  uVar1 = 2;
  if (*(char *)(lVar4 + lVar2) != '\0') {
    uVar1 = uVar5;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001027a0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gdsc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001027d0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gdsc_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 00105000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_gdsc_time, perf_trace_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00105008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00105010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_gdsc_time, perf_trace_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00105018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00105020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_gdsc_time, gdsc_debug_print_regs, restore_hw_trig_clk_dis, gdsc_disable, poll_gdsc_status, gdsc_probe, gdsc_enable, gdsc_set_mode, perf_trace_gdsc_time, check_gdsc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00105030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00105038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00105040 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00105048 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [gdsc_debug_print_regs, gdsc_disable, gdsc_is_enabled, gdsc_get_mode, gdsc_enable, gdsc_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105050 size=1
// signature: undefined _printk(void)
// callers: [gdsc_debug_print_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_lock @ 00105058 size=1
// signature: undefined ww_mutex_lock(void)
// callers: [gdsc_debug_print_regs, gdsc_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_unlock @ 00105060 size=1
// signature: undefined ww_mutex_unlock(void)
// callers: [gdsc_debug_print_regs, gdsc_disable, gdsc_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00105068 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [gdsc_debug_print_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105070 size=1
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
// platform_driver_unregister @ 00105078 size=1
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
// trace_raw_output_prep @ 00105080 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00105088 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00105090 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_gdsc_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00105098 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 001050a0 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001050a8 size=1
// signature: undefined of_get_property(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001050b0 size=1
// signature: undefined of_property_read_string(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001050b8 size=1
// signature: undefined of_find_property(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_regmap_lookup_by_phandle @ 001050c0 size=1
// signature: undefined syscon_regmap_lookup_by_phandle(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_regmap_lookup_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 001050c8 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001050d0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_node_to_regmap @ 001050d8 size=1
// signature: undefined syscon_node_to_regmap(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_node_to_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001050e0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001050e8 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001050f0 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001050f8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00105100 size=1
// signature: undefined platform_get_resource(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00105108 size=1
// signature: undefined devm_ioremap(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 00105110 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00105118 size=1
// signature: undefined devm_clk_get(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105120 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105128 size=1
// signature: undefined _dev_err(void)
// callers: [restore_hw_trig_clk_dis, gdsc_disable, gdsc_probe, gdsc_enable, gdsc_set_mode, check_gdsc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00105130 size=1
// signature: undefined of_icc_get(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 00105138 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00105140 size=1
// signature: undefined regmap_read(void)
// callers: [restore_hw_trig_clk_dis, gdsc_disable, poll_gdsc_status, gdsc_probe, gdsc_enable, gdsc_set_mode, check_gdsc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 00105148 size=1
// signature: undefined mbox_request_channel(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00105150 size=1
// signature: undefined regmap_write(void)
// callers: [restore_hw_trig_clk_dis, gdsc_disable, gdsc_probe, gdsc_enable, gdsc_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00105158 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [gdsc_disable, gdsc_probe, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00105168 size=1
// signature: undefined devm_regulator_register(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_register @ 00105170 size=1
// signature: undefined devm_regulator_proxy_consumer_register(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_proxy_consumer_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 00105178 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 00105180 size=1
// signature: undefined mbox_free_channel(void)
// callers: [gdsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 00105188 size=1
// signature: undefined __udelay(void)
// callers: [check_gdsc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00105190 size=1
// signature: undefined _dev_warn(void)
// callers: [gdsc_enable, check_gdsc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00105198 size=1
// signature: undefined __const_udelay(void)
// callers: [gdsc_disable, poll_gdsc_status, gdsc_enable, gdsc_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001051c0 size=1
// signature: undefined regulator_enable(void)
// callers: [restore_hw_trig_clk_dis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001051c8 size=1
// signature: undefined regulator_disable(void)
// callers: [restore_hw_trig_clk_dis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001051d0 size=1
// signature: undefined clk_prepare(void)
// callers: [gdsc_disable, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001051d8 size=1
// signature: undefined clk_enable(void)
// callers: [gdsc_disable, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001051e0 size=1
// signature: undefined clk_unprepare(void)
// callers: [gdsc_disable, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 001051e8 size=1
// signature: undefined icc_set_bw(void)
// callers: [gdsc_disable, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 001051f0 size=1
// signature: undefined mbox_send_message(void)
// callers: [gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 001051f8 size=1
// signature: undefined reset_control_deassert(void)
// callers: [gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00105200 size=1
// signature: undefined clk_disable(void)
// callers: [gdsc_disable, gdsc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_trylock @ 00105208 size=1
// signature: undefined ww_mutex_trylock(void)
// callers: [gdsc_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 00105210 size=1
// signature: undefined reset_control_assert(void)
// callers: [gdsc_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



