// Decompiled by Ghidra 12.2
// Program: clk-qcom.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_clk_crm_init @ 001059ec size=288
// signature: undefined qcom_clk_crm_init(void)
// callers: [clk_rcg2_crmc_determine_rate]
//------------------------------------------------------------

void qcom_clk_crm_init(long param_1,long *param_2)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  char local_48 [32];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_48[0x10] = '\0';
  local_48[0x11] = '\0';
  local_48[0x12] = '\0';
  local_48[0x13] = '\0';
  local_48[0x14] = '\0';
  local_48[0x15] = '\0';
  local_48[0x16] = '\0';
  local_48[0x17] = '\0';
  local_48[0x18] = '\0';
  local_48[0x19] = '\0';
  local_48[0x1a] = '\0';
  local_48[0x1b] = '\0';
  local_48[0x1c] = '\0';
  local_48[0x1d] = '\0';
  local_48[0x1e] = '\0';
  local_48[0x1f] = '\0';
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  local_48[0xb] = '\0';
  local_48[0xc] = '\0';
  local_48[0xd] = '\0';
  local_48[0xe] = '\0';
  local_48[0xf] = '\0';
  if (param_2 == (long *)0x0) {
    uVar1 = 0xffffffea;
  }
  else if ((char)param_2[3] == '\0') {
    snprintf(local_48,0x20,"qcom,%s-crmc",(char *)*param_2);
    lVar2 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),local_48,0);
    if (lVar2 != 0) {
      uVar3 = syscon_regmap_lookup_by_phandle(*(undefined8 *)(param_1 + 0x2e8),local_48);
      param_2[1] = uVar3;
      if (0xfffffffffffff000 < uVar3) {
        _dev_err(param_1,"%s regmap error\n",local_48);
        uVar1 = (undefined4)param_2[1];
        goto LAB_00105aa0;
      }
    }
    if (*param_2 != 0) {
      uVar3 = crm_get_device();
      param_2[2] = uVar3;
      if (0xfffffffffffff000 < uVar3) {
        _printk(&DAT_0011caa1,"qcom_clk_crm_init",*param_2,uVar3);
        uVar1 = (undefined4)param_2[2];
        goto LAB_00105aa0;
      }
    }
    uVar1 = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    uVar1 = 0;
  }
LAB_00105aa0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// qcom_find_crm_freq_index @ 00105b10 size=68
// signature: undefined qcom_find_crm_freq_index(void)
// callers: [clk_rcg2_vote_perf_level, clk_rcg2_crmc_hw_set_rate]
//------------------------------------------------------------

int qcom_find_crm_freq_index(ulong *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  if ((param_1 == (ulong *)0x0) || (uVar3 = *param_1, uVar3 == 0)) {
    return -0x16;
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = 1;
  do {
    iVar2 = iVar1;
    param_1 = param_1 + 3;
    if (param_2 <= uVar3) {
      return iVar2;
    }
    uVar3 = *param_1;
    iVar1 = iVar2 + 1;
  } while (uVar3 != 0);
  return iVar2;
}



//------------------------------------------------------------
// qcom_find_freq @ 00105b58 size=52
// signature: undefined qcom_find_freq(void)
// callers: [__clk_rcg2_recalc_rate, _freq_tbl_determine_rate, clk_rcg2_shared_set_rate, clk_rcg_lcc_set_rate, clk_dyn_rcg_set_rate_and_parent, _freq_tbl_determine_rate, clk_rcg_set_rate, clk_rcg2_enable, clk_dyn_rcg_set_rate, __clk_rcg2_set_rate]
//------------------------------------------------------------

ulong * qcom_find_freq(ulong *param_1,ulong param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  if (param_1 != (ulong *)0x0) {
    uVar2 = *param_1;
    puVar1 = param_1;
    if (uVar2 == 0) {
      return param_1;
    }
    do {
      param_1 = puVar1;
      if (param_2 <= uVar2) {
        return param_1;
      }
      uVar2 = param_1[3];
      puVar1 = param_1 + 3;
    } while (uVar2 != 0);
  }
  return param_1;
}



//------------------------------------------------------------
// qcom_find_freq_floor @ 00105b90 size=36
// signature: undefined qcom_find_freq_floor(void)
// callers: [_freq_tbl_determine_rate, clk_rcg_set_floor_rate, __clk_rcg2_set_rate]
//------------------------------------------------------------

long * qcom_find_freq_floor(long *param_1,ulong param_2)

{
  long *plVar1;
  long *plVar2;
  
  plVar1 = (long *)0x0;
  do {
    plVar2 = plVar1;
    plVar1 = param_1;
    param_1 = plVar1 + 3;
  } while (*plVar1 - 1U < param_2);
  return plVar2;
}



//------------------------------------------------------------
// qcom_find_src_index @ 00105bb8 size=100
// signature: undefined qcom_find_src_index(void)
// callers: [configure_bank, _freq_tbl_determine_rate, clk_rcg_bypass_determine_rate, __clk_rcg2_configure, clk_edp_pixel_determine_rate, clk_dyn_rcg_set_parent, clk_byte_determine_rate, _freq_tbl_determine_rate, __clk_rcg2_set_rate]
//------------------------------------------------------------

ulong qcom_find_src_index(undefined8 param_1,char *param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = clk_hw_get_num_parents();
  if (0 < (int)uVar1) {
    uVar2 = 0;
    do {
      if (*param_2 == param_3) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 2;
    } while (uVar1 != uVar2);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// qcom_find_cfg_index @ 00105c20 size=104
// signature: undefined qcom_find_cfg_index(void)
// callers: [mux_get_parent]
//------------------------------------------------------------

ulong qcom_find_cfg_index(undefined8 param_1,long param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = clk_hw_get_num_parents();
  if (0 < (int)uVar1) {
    uVar2 = 0;
    pcVar3 = (char *)(param_2 + 1);
    do {
      if (*pcVar3 == param_3) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      pcVar3 = pcVar3 + 2;
    } while (uVar1 != uVar2);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// qcom_cc_map @ 00105c8c size=92
// signature: undefined qcom_cc_map(void)
// callers: []
//------------------------------------------------------------

ulong qcom_cc_map(long param_1,undefined8 *param_2)

{
  ulong uVar1;
  
  uVar1 = devm_platform_ioremap_resource(param_1,0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = __devm_regmap_init_mmio_clk(param_1 + 0x10,0,uVar1,*param_2,0,0);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_pll_set_fsm_mode @ 00105cec size=156
// signature: undefined qcom_pll_set_fsm_mode(void)
// callers: [clk_pll_configure_sr, clk_pll_configure_sr_hpm_lp, clk_alpha_pll_configure]
//------------------------------------------------------------

void qcom_pll_set_fsm_mode(undefined8 param_1,ulong param_2,uint param_3,uint param_4)

{
  regmap_update_bits_base(param_1,param_2,0x200000,0,0,0,0);
  regmap_update_bits_base
            (param_1,param_2 & 0xffffffff,0xfff00,(param_4 & 0xff) << 8 | (param_3 & 0xff) << 0xe,0,
             0,0);
  regmap_update_bits_base(param_1,param_2 & 0xffffffff,0x100000,0x100000,0,0,0);
  return;
}



//------------------------------------------------------------
// qcom_cc_register_board_clk @ 00105d8c size=28
// signature: undefined qcom_cc_register_board_clk(void)
// callers: []
//------------------------------------------------------------

void qcom_cc_register_board_clk(void)

{
  _qcom_cc_register_board_clk();
  return;
}



//------------------------------------------------------------
// _qcom_cc_register_board_clk @ 00105da8 size=292
// signature: undefined _qcom_cc_register_board_clk(void)
// callers: [qcom_cc_register_board_clk, qcom_cc_register_sleep_clk]
//------------------------------------------------------------

void _qcom_cc_register_board_clk
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_78;
  undefined *local_70;
  undefined8 *puStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = (undefined *)0x0;
  puStack_68 = (undefined8 *)0x0;
  local_78 = 0;
  local_40 = param_2;
  lVar1 = of_find_node_opts_by_path("/clocks",0);
  if ((lVar1 == 0) || (lVar1 = of_get_child_by_name(lVar1,param_2), lVar1 == 0)) {
    lVar1 = devm_kmalloc(param_1,0x30,0xdc0);
    if (lVar1 != 0) {
      *(undefined8 **)(lVar1 + 0x10) = &local_78;
      *(undefined8 *)(lVar1 + 0x18) = param_4;
      local_70 = &clk_fixed_rate_ops;
      local_78 = param_2;
      uVar2 = devm_clk_hw_register(param_1,lVar1);
      if ((int)uVar2 != 0) goto LAB_00105e9c;
      goto LAB_00105e48;
    }
  }
  else {
LAB_00105e48:
    lVar1 = devm_kmalloc(param_1,0x20,0xdc0);
    if (lVar1 != 0) {
      puStack_68 = &local_40;
      local_48 = 0;
      *(undefined8 **)(lVar1 + 0x10) = &local_78;
      *(undefined8 *)(lVar1 + 0x18) = 0x100000001;
      local_50 = CONCAT71(local_50._1_7_,1);
      local_70 = &clk_fixed_factor_ops;
      local_78 = param_3;
      uVar2 = devm_clk_hw_register(param_1,lVar1);
      goto LAB_00105e9c;
    }
  }
  uVar2 = 0xffffffea;
LAB_00105e9c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_cc_register_sleep_clk @ 00105ed0 size=48
// signature: undefined qcom_cc_register_sleep_clk(void)
// callers: []
//------------------------------------------------------------

void qcom_cc_register_sleep_clk(undefined8 param_1)

{
  _qcom_cc_register_board_clk(param_1,"sleep_clk","sleep_clk_src",0x8000);
  return;
}



//------------------------------------------------------------
// qcom_cc_really_probe @ 00105f04 size=1140
// signature: undefined qcom_cc_really_probe(void)
// callers: [qcom_cc_probe, qcom_cc_probe_by_index]
//------------------------------------------------------------

int qcom_cc_really_probe(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  long lVar16;
  uint local_bc;
  ulong local_b8;
  ulong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_2 + 0x48);
  uVar13 = *(ulong *)(param_2 + 0x50);
  uVar15 = *(ulong *)(param_2 + 0x20);
  lVar16 = *(long *)(param_2 + 8);
  puVar6 = (undefined8 *)devm_kmalloc(lVar1,0x90,0xdc0);
  if (puVar6 == (undefined8 *)0x0) {
    iVar4 = -0xc;
    goto LAB_00106338;
  }
  uVar9 = *(undefined8 *)(param_1 + 0x2f8);
  lVar11 = *(long *)(param_1 + 0x98);
  puVar6[0xd] = lVar1;
  puVar6[9] = uVar9;
  puVar14 = puVar6 + 2;
  *puVar14 = &qcom_reset_ops;
  uVar9 = *(undefined8 *)(param_2 + 0x28);
  uVar3 = *(undefined8 *)(param_2 + 0x30);
  puVar6[3] = *(undefined8 *)(lVar11 + 0x10);
  *puVar6 = uVar9;
  puVar6[1] = param_3;
  *(int *)(puVar6 + 0xc) = (int)uVar3;
  iVar4 = clk_regulator_init(lVar1,param_2);
  if (iVar4 != 0) goto LAB_00106338;
  iVar4 = clk_vdd_proxy_vote(lVar1,param_2);
  if (iVar4 == 0) {
    if ((*(long *)(param_2 + 0x30) == 0) ||
       (iVar4 = devm_reset_controller_register(lVar1,puVar14), iVar4 == 0)) {
      if ((*(long *)(param_2 + 0x38) == 0) || (*(long *)(param_2 + 0x40) == 0)) {
LAB_00106044:
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        puVar6[0xe] = lVar16;
        puVar6[0xf] = uVar15;
        local_b8 = local_b8 & 0xffffffff00000000;
        puVar6[0x10] = lVar2;
        puVar6[0x11] = uVar13;
        uVar9 = of_find_property(uVar9,"protected-clocks",0);
        lVar11 = of_prop_next_u32(uVar9,0,&local_b8);
        if (lVar11 != 0) {
          do {
            if ((local_b8 & 0xffffffff) < (ulong)puVar6[0xf]) {
              *(undefined8 *)(puVar6[0xe] + (local_b8 & 0xffffffff) * 8) = 0;
            }
            lVar11 = of_prop_next_u32(uVar9,lVar11,&local_b8);
          } while (lVar11 != 0);
        }
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
        local_bc = 0;
        uVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,critical-clocks",0);
        lVar11 = of_prop_next_u32(uVar9,0,&local_bc);
        if (lVar11 != 0) {
          do {
            if (((ulong)local_bc < (ulong)puVar6[0xf]) &&
               (lVar10 = *(long *)(puVar6[0xe] + (ulong)local_bc * 8), lVar10 != 0)) {
              *(ulong *)(lVar10 + 0x88) = *(ulong *)(lVar10 + 0x88) | 1;
            }
            lVar11 = of_prop_next_u32(uVar9,lVar11,&local_bc);
          } while (lVar11 != 0);
        }
        uVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,critical-devices",0);
        lVar11 = of_prop_next_u32(uVar9,0,&local_bc);
        if (lVar11 != 0) {
          do {
            lVar10 = of_find_node_by_phandle(local_bc);
            if (lVar10 != 0) {
              do {
                lVar8 = of_find_property(lVar10,"clocks",0);
                if (lVar8 != 0) {
                  uVar5 = of_count_phandle_with_args(lVar10,"clocks","#clock-cells");
                  local_bc = 0;
                  if (uVar5 != 0) {
                    do {
                      __of_parse_phandle_with_args
                                (lVar10,"clocks","#clock-cells",0xffffffff,local_bc,&local_b8);
                      if (((local_b8 == *(ulong *)(param_1 + 0x2f8)) &&
                          (uStack_b0 >> 0x20 < (ulong)puVar6[0xf])) &&
                         (lVar8 = *(long *)(puVar6[0xe] + (uStack_b0 >> 0x20) * 8), lVar8 != 0)) {
                        *(ulong *)(lVar8 + 0x88) = *(ulong *)(lVar8 + 0x88) | 1;
                      }
                      local_bc = local_bc + 1;
                    } while (local_bc < uVar5);
                  }
                }
                lVar10 = of_get_parent(lVar10);
              } while (lVar10 != 0);
            }
            lVar11 = of_prop_next_u32(uVar9,lVar11,&local_bc);
          } while (lVar11 != 0);
        }
        if (uVar13 != 0) {
          uVar12 = 0;
          do {
            if ((*(long *)(lVar2 + uVar12 * 8) != 0) &&
               (iVar4 = devm_clk_hw_register(lVar1), iVar4 != 0)) goto LAB_00106324;
            uVar12 = (ulong)((int)uVar12 + 1);
          } while (uVar12 < uVar13);
        }
        if (uVar15 != 0) {
          uVar13 = 0;
          do {
            if (*(long *)(lVar16 + uVar13 * 8) != 0) {
              iVar4 = devm_clk_register_regmap(lVar1);
              if (iVar4 != 0) goto LAB_00106324;
              clk_hw_populate_clock_opp_table
                        (*(undefined8 *)(param_1 + 0x2f8),*(undefined8 *)(lVar16 + uVar13 * 8));
              if ((*(byte *)(*(long *)(lVar16 + uVar13 * 8) + 0x88) & 1) != 0) {
                *(undefined8 *)(lVar16 + uVar13 * 8) = 0;
              }
            }
            uVar13 = (ulong)((int)uVar13 + 1);
          } while (uVar13 < uVar15);
        }
        iVar4 = devm_of_clk_add_hw_provider(lVar1,qcom_cc_clk_hw_get,puVar6);
        if (iVar4 == 0) goto LAB_00106338;
      }
      else {
        plVar7 = (long *)devm_kmalloc(lVar1,0x18,0xdc0);
        if (plVar7 == (long *)0x0) {
          iVar4 = -0xc;
        }
        else {
          lVar11 = *(long *)(param_2 + 0x38);
          lVar10 = *(long *)(param_2 + 0x40);
          *plVar7 = lVar1;
          plVar7[1] = lVar11;
          plVar7[2] = lVar10;
          iVar4 = gdsc_register(plVar7,puVar14,param_3);
          if ((iVar4 == 0) && (iVar4 = devm_add_action_or_reset(lVar1,plVar7), iVar4 == 0))
          goto LAB_00106044;
        }
      }
    }
LAB_00106324:
    clk_vdd_proxy_unvote(lVar1,param_2);
  }
  clk_regulator_deinit(param_2);
LAB_00106338:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// devm_add_action_or_reset @ 00106378 size=72
// signature: undefined devm_add_action_or_reset(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

int devm_add_action_or_reset(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = devm_add_action(param_1,qcom_cc_gdsc_unregister,param_2);
  if (iVar1 != 0) {
    gdsc_unregister(param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_cc_gdsc_unregister @ 001063c4 size=28
// signature: undefined qcom_cc_gdsc_unregister(void)
// callers: []
//------------------------------------------------------------

void qcom_cc_gdsc_unregister(void)

{
  gdsc_unregister();
  return;
}



//------------------------------------------------------------
// qcom_cc_clk_hw_get @ 001063e4 size=100
// signature: undefined qcom_cc_clk_hw_get(void)
// callers: []
//------------------------------------------------------------

long qcom_cc_clk_hw_get(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)*(uint *)(param_1 + 0xc);
  if ((*(ulong *)(param_2 + 0x88) <= uVar2) ||
     (lVar1 = *(long *)(*(long *)(param_2 + 0x80) + uVar2 * 8), lVar1 == 0)) {
    if (uVar2 < *(ulong *)(param_2 + 0x78)) {
      lVar1 = *(long *)(*(long *)(param_2 + 0x70) + uVar2 * 8);
    }
    else {
      _printk(&DAT_0011d959,"qcom_cc_clk_hw_get");
      lVar1 = -0x16;
    }
  }
  return lVar1;
}



//------------------------------------------------------------
// qcom_cc_probe @ 0010644c size=116
// signature: undefined qcom_cc_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_cc_probe(long param_1,undefined8 *param_2)

{
  ulong uVar1;
  
  uVar1 = devm_platform_ioremap_resource(param_1,0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = __devm_regmap_init_mmio_clk(param_1 + 0x10,0,uVar1,*param_2,0,0);
  }
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = qcom_cc_really_probe(param_1,param_2);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_cc_probe_by_index @ 001064c4 size=120
// signature: undefined qcom_cc_probe_by_index(void)
// callers: []
//------------------------------------------------------------

ulong qcom_cc_probe_by_index(long param_1,undefined8 param_2,undefined8 *param_3)

{
  ulong uVar1;
  
  uVar1 = devm_platform_ioremap_resource();
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = __devm_regmap_init_mmio_clk(param_1 + 0x10,0,uVar1,*param_3,0,0);
    if (uVar1 < 0xfffffffffffff001) {
      uVar1 = qcom_cc_really_probe(param_1,param_3);
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  else {
    uVar1 = 0xfffffff4;
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_cc_sync_state @ 00106540 size=72
// signature: undefined qcom_cc_sync_state(void)
// callers: []
//------------------------------------------------------------

void qcom_cc_sync_state(undefined8 param_1,undefined8 param_2)

{
  _dev_info(param_1,"sync-state\n");
  clk_sync_state(param_1);
  clk_vdd_proxy_unvote(param_1,param_2);
  return;
}



//------------------------------------------------------------
// qcom_clk_crm_set_rate @ 0010658c size=172
// signature: undefined qcom_clk_crm_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_clk_crm_set_rate
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  while( true ) {
    if (param_1 == 0) {
      return 0xffffffea;
    }
    lVar1 = __clk_get_hw();
    uVar2 = clk_is_regmap_clk();
    if ((((uVar2 & 1) != 0) && (*(long *)(lVar1 + 0x58) != 0)) &&
       (pcVar4 = *(code **)(*(long *)(lVar1 + 0x58) + 0x20), pcVar4 != (code *)0x0)) break;
    param_1 = clk_get_parent(*(undefined8 *)(lVar1 + 8));
  }
  if (*(int *)(pcVar4 + -4) != -0x5f8a6d3a) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x106614);
    (*pcVar4)();
  }
  uVar3 = (*pcVar4)(lVar1,param_2,param_3,param_4,param_5);
  return uVar3;
}



//------------------------------------------------------------
// qcom_clk_get_voltage @ 0010663c size=112
// signature: undefined qcom_clk_get_voltage(void)
// callers: []
//------------------------------------------------------------

int qcom_clk_get_voltage(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = __clk_get_hw();
  uVar3 = clk_is_regmap_clk();
  if ((uVar3 & 1) == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = clk_find_vdd_level(lVar2,lVar2 + 0x30,param_2);
    if (-1 < iVar1) {
      iVar1 = clk_get_vdd_voltage(lVar2 + 0x30);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_clk_set_flags @ 001066b0 size=164
// signature: undefined qcom_clk_set_flags(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_clk_set_flags(ulong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    uVar2 = __clk_get_hw(param_1);
    uVar1 = 0xffffffea;
    if ((uVar2 != 0) && (uVar2 < 0xfffffffffffff001)) {
      uVar3 = clk_is_regmap_clk(uVar2);
      if ((uVar3 & 1) == 0) {
        uVar1 = 0xffffffea;
      }
      else if ((*(long *)(uVar2 + 0x58) == 0) ||
              (pcVar4 = *(code **)(*(long *)(uVar2 + 0x58) + 0x10), pcVar4 == (code *)0x0)) {
        uVar1 = 0;
      }
      else {
        if (*(int *)(pcVar4 + -4) != 0x79583a5e) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x106730);
          (*pcVar4)();
        }
        uVar1 = (*pcVar4)(uVar2,param_2);
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_cc_runtime_init @ 00106758 size=324
// signature: undefined qcom_cc_runtime_init(void)
// callers: [register_qcom_clks_pm]
//------------------------------------------------------------

ulong qcom_cc_runtime_init(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar1 = param_1 + 0x10;
  uVar3 = clk_get(lVar1,"iface");
  uVar4 = 0;
  if (uVar3 != 0xfffffffffffffffe) {
    uVar4 = uVar3;
  }
  if (uVar4 < 0xfffffffffffff001) {
    clk_put(uVar4);
    uVar3 = clk_regulator_init(lVar1,param_2);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 == 0) {
      uVar4 = of_icc_get(lVar1,0);
      *(ulong *)(param_2 + 0x68) = uVar4;
      if (uVar4 < 0xfffffffffffff001) {
        *(long *)(param_1 + 0xa8) = param_2;
        pm_runtime_enable(lVar1);
        uVar3 = pm_clk_create(lVar1);
        uVar4 = uVar3 & 0xffffffff;
        if ((int)uVar3 == 0) {
          uVar2 = pm_clk_add(lVar1,"iface");
          if (-1 < (int)uVar2) {
            uVar4 = 0;
            goto LAB_00106830;
          }
          uVar4 = (ulong)uVar2;
          _dev_err(lVar1,"failed to acquire iface clock\n");
          pm_clk_destroy(lVar1);
        }
        __pm_runtime_disable(lVar1,1);
        icc_put(*(undefined8 *)(param_2 + 0x68));
      }
      else if (uVar4 == 0xfffffffffffffdfb) {
        uVar4 = 0xfffffdfb;
      }
      else {
        _dev_err(lVar1,"error getting path\n");
        uVar4 = (ulong)*(uint *)(param_2 + 0x68);
      }
      clk_regulator_deinit(param_2);
    }
  }
  else if (uVar4 != 0xfffffffffffffdfb) {
    _dev_err(lVar1,"unable to get iface clock\n");
  }
LAB_00106830:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_cc_runtime_resume @ 001068a0 size=288
// signature: undefined qcom_cc_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int qcom_cc_runtime_resume(long param_1)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  long lVar4;
  ulong uVar5;
  long local_70 [6];
  
  lVar4 = sp_el0;
  local_70[5] = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[0] = 0;
  uVar2 = *(ulong *)(lVar4 + 0x60);
  if (uVar2 != 0) {
    uVar5 = 0;
    pcVar3 = "%s: failed to vote voltage\n";
    do {
      local_70[0] = *(long *)(*(long *)(lVar4 + 0x58) + uVar5 * 8);
      if (local_70[0] != 0) {
        iVar1 = clk_vote_vdd_level(local_70,1);
        if (iVar1 != 0) goto LAB_001069a4;
        uVar2 = *(ulong *)(lVar4 + 0x60);
      }
      uVar5 = (ulong)((int)uVar5 + 1);
    } while (uVar5 < uVar2);
  }
  if ((*(long *)(lVar4 + 0x68) == 0) ||
     (iVar1 = icc_set_bw(*(long *)(lVar4 + 0x68),0,1), iVar1 == 0)) {
    iVar1 = pm_clk_resume(param_1);
    if (iVar1 == 0) goto LAB_00106958;
    pcVar3 = "%s: failed to enable clocks\n";
  }
  else {
    pcVar3 = "%s: failed to vote bw\n";
  }
LAB_001069a4:
  _dev_warn(param_1,pcVar3,"qcom_cc_runtime_resume");
LAB_00106958:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_cc_runtime_suspend @ 001069c4 size=316
// signature: undefined qcom_cc_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cc_runtime_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  iVar1 = pm_clk_suspend();
  if (iVar1 == 0) {
    lVar2 = *(long *)(lVar3 + 0x68);
  }
  else {
    _dev_warn(param_1,"%s: failed to disable clocks\n","qcom_cc_runtime_suspend");
    lVar2 = *(long *)(lVar3 + 0x68);
  }
  if ((lVar2 != 0) && (iVar1 = icc_set_bw(lVar2,0,0), iVar1 != 0)) {
    _dev_warn(param_1,"%s: failed to unvote bw\n","qcom_cc_runtime_suspend");
  }
  if (*(long *)(lVar3 + 0x60) != 0) {
    uVar4 = 0;
    do {
      local_70 = *(long *)(*(long *)(lVar3 + 0x58) + uVar4 * 8);
      if ((local_70 != 0) && (iVar1 = clk_unvote_vdd_level(&local_70,1), iVar1 != 0)) {
        _dev_warn(param_1,"%s: failed to unvote voltage\n","qcom_cc_runtime_suspend");
      }
      uVar4 = (ulong)((int)uVar4 + 1);
    } while (uVar4 < *(ulong *)(lVar3 + 0x60));
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_get_vdd_voltage @ 00106b04 size=204
// signature: undefined clk_get_vdd_voltage(void)
// callers: [qcom_clk_get_voltage]
//------------------------------------------------------------

int clk_get_vdd_voltage(long *param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  
  uVar3 = *(uint *)(param_1 + 4);
  uVar7 = (ulong)uVar3;
  if ((int)uVar3 < 1) {
    iVar6 = -0x16;
  }
  else {
    if (uVar3 == 1) {
      uVar10 = 0;
      iVar6 = -0x16;
    }
    else {
      uVar10 = uVar7 & 0xfffffffe;
      plVar9 = (long *)(param_1[1] + 8);
      iVar6 = -0x16;
      lVar8 = (long)param_2 * 4;
      iVar12 = -0x16;
      uVar11 = uVar10;
      do {
        plVar1 = plVar9 + -1;
        lVar2 = *plVar9;
        plVar9 = plVar9 + 2;
        iVar4 = *(int *)(*(long *)(*plVar1 + 0x20) + lVar8);
        iVar5 = *(int *)(*(long *)(lVar2 + 0x20) + lVar8);
        if (iVar6 <= iVar4) {
          iVar6 = iVar4;
        }
        if (iVar12 <= iVar5) {
          iVar12 = iVar5;
        }
        uVar11 = uVar11 - 2;
      } while (uVar11 != 0);
      if (iVar6 <= iVar12) {
        iVar6 = iVar12;
      }
      if (uVar10 == uVar7) goto LAB_00106bb0;
    }
    lVar8 = uVar7 - uVar10;
    plVar9 = (long *)(param_1[1] + uVar10 * 8);
    do {
      iVar12 = *(int *)(*(long *)(*plVar9 + 0x20) + (long)param_2 * 4);
      if (iVar6 <= iVar12) {
        iVar6 = iVar12;
      }
      lVar8 = lVar8 + -1;
      plVar9 = plVar9 + 1;
    } while (lVar8 != 0);
  }
LAB_00106bb0:
  if (*param_1 != 0) {
    iVar12 = *(int *)(*(long *)(*param_1 + 0x20) + (long)param_2 * 4);
    if (iVar6 <= iVar12) {
      iVar6 = iVar12;
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// clk_vote_vdd_level @ 00106bd4 size=544
// signature: undefined clk_vote_vdd_level(void)
// callers: [clk_post_change_regmap, qcom_cc_runtime_resume, clk_prepare_regmap, clk_pre_change_regmap]
//------------------------------------------------------------

int clk_vote_vdd_level(long *param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  
  if ((int)param_1[4] < 1) {
    uVar9 = 0;
    lVar7 = *param_1;
  }
  else {
    uVar9 = 0;
    lVar7 = (long)(int)param_2 * 4;
    do {
      lVar6 = *(long *)(param_1[1] + uVar9 * 8);
      if (*(int *)(lVar6 + 0x30) <= (int)param_2) goto LAB_00106cd0;
      mutex_lock(&vdd_lock);
      *(int *)(*(long *)(lVar6 + 0x28) + lVar7) = *(int *)(*(long *)(lVar6 + 0x28) + lVar7) + 1;
      iVar3 = clk_aggregate_vdd(lVar6);
      if (iVar3 != 0) {
        *(int *)(*(long *)(lVar6 + 0x28) + lVar7) = *(int *)(*(long *)(lVar6 + 0x28) + lVar7) + -1;
        goto LAB_00106d08;
      }
      mutex_unlock(&vdd_lock);
      uVar9 = uVar9 + 1;
    } while ((long)uVar9 < (long)(int)param_1[4]);
    lVar7 = *param_1;
  }
  if (lVar7 == 0) {
    iVar3 = 0;
  }
  else {
    if ((int)param_2 < *(int *)(lVar7 + 0x30)) {
      mutex_lock(&vdd_lock);
      uVar5 = -(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2;
      *(int *)(*(long *)(lVar7 + 0x28) + uVar5) = *(int *)(*(long *)(lVar7 + 0x28) + uVar5) + 1;
      iVar3 = clk_aggregate_vdd(lVar7);
      if (iVar3 == 0) {
        mutex_unlock(&vdd_lock);
        return 0;
      }
      *(int *)(*(long *)(lVar7 + 0x28) + (long)(int)param_2 * 4) =
           *(int *)(*(long *)(lVar7 + 0x28) + (long)(int)param_2 * 4) + -1;
LAB_00106d08:
      mutex_unlock(&vdd_lock);
      iVar4 = (int)uVar9;
    }
    else {
LAB_00106cd0:
      iVar3 = -0x16;
      iVar4 = (int)uVar9;
    }
    if (-1 < (int)(iVar4 - 1U)) {
      lVar7 = (ulong)(iVar4 - 1U) << 3;
      lVar6 = (long)(int)param_2 * 4;
      do {
        puVar8 = *(undefined8 **)(param_1[1] + lVar7);
        if ((int)param_2 < *(int *)(puVar8 + 6)) {
          if (*(int *)(puVar8[5] + (long)(int)param_2 * 4) == 0) {
            __warn_printk("Reference counts are incorrect for %s level %d\n",*puVar8,(ulong)param_2)
            ;
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x106dc4);
            (*pcVar2)();
          }
          mutex_lock(&vdd_lock);
          *(int *)(puVar8[5] + lVar6) = *(int *)(puVar8[5] + lVar6) + -1;
          iVar4 = clk_aggregate_vdd(puVar8);
          if (iVar4 != 0) {
            *(int *)(puVar8[5] + lVar6) = *(int *)(puVar8[5] + lVar6) + 1;
          }
          mutex_unlock(&vdd_lock);
        }
        uVar1 = (int)uVar9 - 1;
        uVar9 = (ulong)uVar1;
        lVar7 = lVar7 + -8;
      } while (0 < (int)uVar1);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// clk_unvote_vdd_level @ 00106dfc size=564
// signature: undefined clk_unvote_vdd_level(void)
// callers: [clk_unprepare_regmap, clk_post_change_regmap, qcom_cc_runtime_suspend, clk_pre_change_regmap]
//------------------------------------------------------------

int clk_unvote_vdd_level(long *param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  
  if ((int)param_1[4] < 1) {
    uVar7 = 0;
    puVar5 = (undefined8 *)*param_1;
  }
  else {
    uVar7 = 0;
    lVar8 = (long)param_2 * 4;
    do {
      puVar5 = *(undefined8 **)(param_1[1] + uVar7 * 8);
      if (*(int *)(puVar5 + 6) <= param_2) goto LAB_00106f08;
      if (*(int *)(puVar5[5] + (long)param_2 * 4) == 0) {
        __warn_printk("Reference counts are incorrect for %s level %d\n",*puVar5,param_2);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107014);
        (*pcVar2)();
      }
      mutex_lock(&vdd_lock);
      *(int *)(puVar5[5] + lVar8) = *(int *)(puVar5[5] + lVar8) + -1;
      iVar3 = clk_aggregate_vdd(puVar5);
      if (iVar3 != 0) {
        *(int *)(puVar5[5] + lVar8) = *(int *)(puVar5[5] + lVar8) + 1;
        goto LAB_00106f38;
      }
      mutex_unlock(&vdd_lock);
      uVar7 = uVar7 + 1;
    } while ((long)uVar7 < (long)(int)param_1[4]);
    puVar5 = (undefined8 *)*param_1;
  }
  if (puVar5 == (undefined8 *)0x0) {
    iVar3 = 0;
  }
  else {
    if (param_2 < *(int *)(puVar5 + 6)) {
      if (*(int *)(puVar5[5] + (long)param_2 * 4) == 0) {
        __warn_printk("Reference counts are incorrect for %s level %d\n",*puVar5,param_2);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107034);
        (*pcVar2)();
      }
      mutex_lock(&vdd_lock);
      lVar8 = (long)param_2 * 4;
      *(int *)(puVar5[5] + lVar8) = *(int *)(puVar5[5] + lVar8) + -1;
      iVar3 = clk_aggregate_vdd(puVar5);
      if (iVar3 == 0) {
        mutex_unlock(&vdd_lock);
        return 0;
      }
      *(int *)(puVar5[5] + lVar8) = *(int *)(puVar5[5] + lVar8) + 1;
LAB_00106f38:
      mutex_unlock(&vdd_lock);
    }
    else {
LAB_00106f08:
      iVar3 = -0x16;
    }
    uVar1 = (int)uVar7 - 1;
    if (-1 < (int)uVar1) {
      lVar8 = (ulong)uVar1 << 3;
      lVar9 = (long)param_2 * 4;
      do {
        lVar6 = *(long *)(param_1[1] + lVar8);
        if (param_2 < *(int *)(lVar6 + 0x30)) {
          mutex_lock(&vdd_lock);
          *(int *)(*(long *)(lVar6 + 0x28) + lVar9) = *(int *)(*(long *)(lVar6 + 0x28) + lVar9) + 1;
          iVar4 = clk_aggregate_vdd(lVar6);
          if (iVar4 != 0) {
            *(int *)(*(long *)(lVar6 + 0x28) + lVar9) =
                 *(int *)(*(long *)(lVar6 + 0x28) + lVar9) + -1;
          }
          mutex_unlock(&vdd_lock);
        }
        uVar1 = (int)uVar7 - 1;
        uVar7 = (ulong)uVar1;
        lVar8 = lVar8 + -8;
      } while (0 < (int)uVar1);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// clk_find_vdd_level @ 0010703c size=192
// signature: undefined clk_find_vdd_level(void)
// callers: [clock_debug_trace, qcom_clk_get_voltage, clk_post_change_regmap, clk_hw_populate_clock_opp_table, clk_prepare_regmap, clock_debug_print_enabled_clocks, rate_max_show, clk_pre_change_regmap]
//------------------------------------------------------------

ulong clk_find_vdd_level(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 0) {
    uVar3 = 0xffffffc3;
  }
  else {
    if (iVar1 < 1) {
      uVar3 = 0;
LAB_001070c0:
      if ((int)uVar3 != iVar1) goto LAB_001070c8;
    }
    else {
      uVar3 = 0;
      do {
        lVar4 = *(long *)(*(long *)(param_2 + 0x10) + uVar3 * 8);
        if ((param_3 + 500U) / 1000 <= (lVar4 + 500U) / 1000 && lVar4 != 0) goto LAB_001070c0;
        uVar3 = uVar3 + 1;
      } while (iVar1 != (int)uVar3);
    }
    uVar2 = clk_hw_get_name();
    _printk(&DAT_0011cf63,param_3,uVar2);
    uVar3 = 0xffffffea;
  }
LAB_001070c8:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// clk_regulator_init @ 00107100 size=308
// signature: undefined clk_regulator_init(void)
// callers: [qcom_cc_really_probe, qcom_cc_runtime_init]
//------------------------------------------------------------

ulong clk_regulator_init(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  uVar2 = *(ulong *)(param_2 + 0x60);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      lVar5 = *(long *)(*(long *)(param_2 + 0x58) + uVar4 * 8);
      iVar1 = *(int *)(lVar5 + 0x18);
      if (0 < iVar1) {
        lVar6 = 0;
        do {
          if (*(long *)(*(long *)(lVar5 + 8) + lVar6 * 8) == 0) {
            uVar3 = *(undefined8 *)(*(long *)(lVar5 + 0x10) + lVar6 * 8);
            uVar2 = devm_regulator_get(param_1,uVar3);
            if (0xfffffffffffff000 < uVar2) {
              if (uVar2 != 0xfffffffffffffdfb) {
                _dev_err(param_1,"%s error %s regulator\n","clk_regulator_init",uVar3);
              }
              if (-1 < (int)uVar4) {
                uVar4 = uVar4 & 0xffffffff;
                do {
                  lVar5 = *(long *)(*(long *)(param_2 + 0x58) + uVar4 * 8);
                  memset(*(void **)(lVar5 + 8),0,(long)*(int *)(lVar5 + 0x18) << 3);
                  uVar4 = uVar4 - 1;
                } while (0 < (int)uVar4 + 1);
              }
              goto LAB_001071f0;
            }
            *(ulong *)(*(long *)(lVar5 + 8) + lVar6 * 8) = uVar2;
            iVar1 = *(int *)(lVar5 + 0x18);
          }
          lVar6 = lVar6 + 1;
        } while (lVar6 < iVar1);
        uVar2 = *(ulong *)(param_2 + 0x60);
      }
      uVar4 = (ulong)((int)uVar4 + 1);
    } while (uVar4 < uVar2);
  }
  uVar2 = 0;
LAB_001071f0:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// clk_regulator_deinit @ 00107238 size=96
// signature: undefined clk_regulator_deinit(void)
// callers: [qcom_cc_really_probe, qcom_cc_runtime_init]
//------------------------------------------------------------

void clk_regulator_deinit(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  if (*(long *)(param_1 + 0x60) != 0) {
    uVar2 = 0;
    do {
      lVar1 = *(long *)(*(long *)(param_1 + 0x58) + uVar2 * 8);
      memset(*(void **)(lVar1 + 8),0,(long)*(int *)(lVar1 + 0x18) << 3);
      uVar2 = (ulong)((int)uVar2 + 1);
    } while (uVar2 < *(ulong *)(param_1 + 0x60));
  }
  return;
}



//------------------------------------------------------------
// clk_vdd_proxy_vote @ 0010729c size=276
// signature: undefined clk_vdd_proxy_vote(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

undefined4 clk_vdd_proxy_vote(undefined8 param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  if (*(long *)(param_2 + 0x60) != 0) {
    uVar6 = 0;
    do {
      lVar5 = *(long *)(*(long *)(param_2 + 0x58) + uVar6 * 8);
      if (*(int *)(lVar5 + 0x30) == -0x80000000) {
        iVar3 = -0x16;
LAB_001072f0:
        __warn_printk("%s failed, ret=%d\n","clk_vdd_proxy_vote",iVar3);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107304);
        (*pcVar2)();
      }
      uVar1 = *(int *)(lVar5 + 0x30) - 1;
      mutex_lock(&vdd_lock);
      uVar4 = -(ulong)(uVar1 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar1 << 2;
      *(int *)(*(long *)(lVar5 + 0x28) + uVar4) = *(int *)(*(long *)(lVar5 + 0x28) + uVar4) + 1;
      iVar3 = clk_aggregate_vdd(lVar5);
      if (iVar3 != 0) {
        *(int *)(*(long *)(lVar5 + 0x28) + (long)(int)uVar1 * 4) =
             *(int *)(*(long *)(lVar5 + 0x28) + (long)(int)uVar1 * 4) + -1;
        mutex_unlock(&vdd_lock);
        goto LAB_001072f0;
      }
      mutex_unlock(&vdd_lock);
      uVar6 = (ulong)((int)uVar6 + 1);
    } while (uVar6 < *(ulong *)(param_2 + 0x60));
  }
  return 0;
}



//------------------------------------------------------------
// clk_vdd_proxy_unvote @ 001073b4 size=300
// signature: undefined clk_vdd_proxy_unvote(void)
// callers: [qcom_cc_really_probe, qcom_cc_sync_state]
//------------------------------------------------------------

undefined4 clk_vdd_proxy_unvote(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  long lVar5;
  
  if (*(long *)(param_2 + 0x60) != 0) {
    uVar4 = 0;
    do {
      puVar3 = *(undefined8 **)(*(long *)(param_2 + 0x58) + uVar4 * 8);
      if (*(int *)(puVar3 + 6) == -0x80000000) {
        iVar2 = -0x16;
LAB_00107408:
        __warn_printk("clk_unvote_vdd_level failed ret=%d\n",iVar2);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x107418);
        (*pcVar1)();
      }
      iVar2 = *(int *)(puVar3 + 6) + -1;
      if (*(int *)(puVar3[5] + (long)iVar2 * 4) == 0) {
        __warn_printk("Reference counts are incorrect for %s level %d\n",*puVar3);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1074b8);
        (*pcVar1)();
      }
      mutex_lock(&vdd_lock);
      lVar5 = (long)iVar2 * 4;
      *(int *)(puVar3[5] + lVar5) = *(int *)(puVar3[5] + lVar5) + -1;
      iVar2 = clk_aggregate_vdd(puVar3);
      if (iVar2 != 0) {
        *(int *)(puVar3[5] + lVar5) = *(int *)(puVar3[5] + lVar5) + 1;
        mutex_unlock(&vdd_lock);
        goto LAB_00107408;
      }
      mutex_unlock(&vdd_lock);
      uVar4 = (ulong)((int)uVar4 + 1);
    } while (uVar4 < *(ulong *)(param_2 + 0x60));
  }
  return 0;
}



//------------------------------------------------------------
// clk_aggregate_vdd @ 001074e4 size=404
// signature: undefined clk_aggregate_vdd(void)
// callers: [clk_unvote_vdd_level, clk_vdd_proxy_vote, clk_vote_vdd_level, clk_vdd_proxy_unvote]
//------------------------------------------------------------

int clk_aggregate_vdd(long param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  
  uVar7 = *(uint *)(param_1 + 0x30);
  uVar2 = *(uint *)(param_1 + 0x34);
  iVar3 = *(int *)(param_1 + 0x18);
  lVar8 = *(long *)(param_1 + 8);
  lVar9 = *(long *)(param_1 + 0x20);
  uVar4 = uVar7 - 1;
  if (-1 < (int)uVar4) {
    uVar4 = 0;
  }
  do {
    uVar7 = uVar7 - 1;
    uVar5 = uVar4;
    if ((int)uVar7 < 1) break;
    uVar5 = uVar7;
  } while (*(int *)(*(long *)(param_1 + 0x28) + (ulong)uVar7 * 4) == 0);
  if (uVar5 != uVar2) {
    if (0 < iVar3) {
      uVar11 = 0;
      do {
        iVar10 = (int)uVar11;
        iVar6 = regulator_set_voltage
                          (*(undefined8 *)(lVar8 + uVar11 * 8),
                           *(undefined4 *)(lVar9 + (long)(int)(uVar5 * iVar3 + iVar10) * 4),
                           0x7fffffff);
        if (iVar6 != 0) goto joined_r0x0010761c;
        if ((uVar2 == 0) || (uVar2 == *(uint *)(param_1 + 0x30))) {
          iVar6 = regulator_enable(*(undefined8 *)(lVar8 + uVar11 * 8));
joined_r0x001075b8:
          if (iVar6 != 0) {
            regulator_set_voltage
                      (*(undefined8 *)(lVar8 + uVar11 * 8),
                       *(undefined4 *)(lVar9 + (long)(int)(uVar2 * iVar3 + iVar10) * 4),0x7fffffff);
joined_r0x0010761c:
            if (iVar10 == 0) {
              return iVar6;
            }
            do {
              uVar12 = uVar11 - 1;
              regulator_set_voltage
                        (*(undefined8 *)(lVar8 + uVar12 * 8),
                         *(undefined4 *)(lVar9 + (long)(int)(uVar2 * iVar3 + (int)uVar12) * 4),
                         0x7fffffff);
              if ((uVar2 == 0) || (uVar2 == *(uint *)(param_1 + 0x30))) {
                regulator_disable(*(undefined8 *)(lVar8 + uVar12 * 8));
              }
              else if (uVar5 == 0) {
                regulator_enable(*(undefined8 *)(lVar8 + uVar12 * 8));
              }
              bVar1 = 1 < uVar11;
              uVar11 = uVar12;
            } while (bVar1);
            return iVar6;
          }
        }
        else if (uVar5 == 0) {
          iVar6 = regulator_disable(*(undefined8 *)(lVar8 + uVar11 * 8));
          goto joined_r0x001075b8;
        }
        uVar11 = uVar11 + 1;
      } while ((long)uVar11 < (long)*(int *)(param_1 + 0x18));
    }
    *(uint *)(param_1 + 0x34) = uVar5;
  }
  return 0;
}



//------------------------------------------------------------
// clk_is_enabled_regmap @ 0010767c size=140
// signature: undefined clk_is_enabled_regmap(void)
// callers: []
//------------------------------------------------------------

void clk_is_enabled_regmap(long param_1)

{
  long lVar1;
  bool bVar2;
  ulong uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),&local_2c);
  if ((int)uVar3 == 0) {
    bVar2 = (*(uint *)(param_1 + 0x24) & local_2c) == 0;
    if (*(char *)(param_1 + 0x28) == '\0') {
      uVar3 = (ulong)!bVar2;
    }
    else {
      uVar3 = (ulong)bVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_enable_regmap @ 0010770c size=60
// signature: undefined clk_enable_regmap(void)
// callers: [alpha_pll_fabia_enable, clk_branch2_enable, clk_trion_pll_enable, clk_pll_vote_enable, clk_branch2_mem_enable, clk_zonda_evo_pll_enable, clk_zonda_pll_enable, _alpha_pll_lucid_evo_enable, clk_branch_restore_context, clk_branch_enable, clk_alpha_pll_enable, clk_zonda_5lpe_pll_enable, clk_branch2_force_off_enable, clk_branch2_hw_ctl_enable, alpha_pll_lucid_5lpe_enable, clk_branch2_sreg_enable, clk_regera_pll_enable, clk_branch_restore_context_aon]
//------------------------------------------------------------

void clk_enable_regmap(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x28) != '\0') {
    uVar1 = 0;
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),
             *(undefined4 *)(param_1 + 0x24),uVar1,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_disable_regmap @ 0010774c size=60
// signature: undefined clk_disable_regmap(void)
// callers: [clk_regera_pll_disable, clk_branch2_disable, clk_zonda_pll_disable, clk_zonda_5lpe_pll_disable, clk_branch2_mem_disable, clk_branch2_hw_ctl_disable, clk_zonda_evo_pll_disable, alpha_pll_lucid_5lpe_disable, clk_alpha_pll_disable, clk_trion_pll_disable, _alpha_pll_lucid_evo_disable, clk_branch2_sreg_disable, clk_branch2_force_off_disable, clk_branch_disable, alpha_pll_fabia_disable]
//------------------------------------------------------------

void clk_disable_regmap(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x28) != '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),
             *(undefined4 *)(param_1 + 0x24),uVar1,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_pre_change_regmap @ 0010778c size=148
// signature: undefined clk_pre_change_regmap(void)
// callers: []
//------------------------------------------------------------

ulong clk_pre_change_regmap(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  if (*(long *)(param_1 + 0x40) != 0) {
    lVar1 = param_1 + 0x30;
    iVar2 = *(int *)(param_1 + 0x4c);
    uVar3 = clk_find_vdd_level(param_1,lVar1);
    if ((int)uVar3 < 0) {
      return (ulong)uVar3;
    }
    if (iVar2 < (int)uVar3) {
      uVar4 = clk_hw_is_prepared(param_1);
      if ((uVar4 & 1) != 0) {
        uVar4 = clk_vote_vdd_level(lVar1,uVar3);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        clk_unvote_vdd_level(lVar1,iVar2);
      }
      *(uint *)(param_1 + 0x4c) = uVar3;
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// clk_post_change_regmap @ 00107824 size=148
// signature: undefined clk_post_change_regmap(void)
// callers: []
//------------------------------------------------------------

ulong clk_post_change_regmap(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  if (*(long *)(param_1 + 0x40) != 0) {
    lVar1 = param_1 + 0x30;
    iVar2 = *(int *)(param_1 + 0x4c);
    uVar3 = clk_find_vdd_level(param_1,lVar1);
    if ((int)uVar3 < 0) {
      return (ulong)uVar3;
    }
    if ((int)uVar3 < iVar2) {
      uVar4 = clk_hw_is_prepared(param_1);
      if ((uVar4 & 1) != 0) {
        uVar4 = clk_vote_vdd_level(lVar1,uVar3);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        clk_unvote_vdd_level(lVar1,iVar2);
      }
      *(uint *)(param_1 + 0x4c) = uVar3;
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// clk_prepare_regmap @ 001078bc size=160
// signature: undefined clk_prepare_regmap(void)
// callers: [alpha_pll_trion_prepare, _alpha_pll_lucid_evo_prepare, alpha_pll_lucid_5lpe_prepare, alpha_pll_fabia_prepare, alpha_pll_lucid_prepare]
//------------------------------------------------------------

ulong clk_prepare_regmap(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar4 = clk_hw_get_rate();
  if (*(long *)(param_1 + 0x40) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = clk_find_vdd_level(param_1,param_1 + 0x30,uVar4);
    iVar3 = (int)uVar5;
    if (-1 < iVar3) {
      uVar1 = *(uint *)(param_1 + 0x4c);
      uVar6 = (ulong)uVar1;
      if (uVar1 == 0) {
        uVar6 = uVar5 & 0xffffffff;
        *(int *)(param_1 + 0x4c) = iVar3;
      }
      else if ((int)uVar1 < iVar3) {
        uVar4 = clk_hw_get_name(param_1);
        __warn_printk("%s level:%d > vdd_level:%d\n",uVar4,uVar5 & 0xffffffff,
                      *(undefined4 *)(param_1 + 0x4c));
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107930);
        (*pcVar2)();
      }
      uVar5 = clk_vote_vdd_level(param_1 + 0x30,uVar6);
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// clk_unprepare_regmap @ 00107968 size=48
// signature: undefined clk_unprepare_regmap(void)
// callers: [alpha_pll_lucid_evo_unprepare]
//------------------------------------------------------------

void clk_unprepare_regmap(long param_1)

{
  if (*(long *)(param_1 + 0x40) != 0) {
    clk_unvote_vdd_level(param_1 + 0x30,*(undefined4 *)(param_1 + 0x4c));
  }
  return;
}



//------------------------------------------------------------
// clk_is_regmap_clk @ 0010799c size=116
// signature: undefined clk_is_regmap_clk(void)
// callers: [enable_debug_clks, clock_debug_trace, clk_rcg2_crmc_populate_freq_table, clk_debug_measure_set, qcom_clk_get_voltage, clock_debug_print_enabled_clocks, clk_debug_mux_set_parent, clk_debug_print_hw, clk_debug_measure_get, disable_debug_clks, qcom_clk_crm_set_rate, qcom_clk_set_flags]
//------------------------------------------------------------

bool clk_is_regmap_clk(undefined **param_1)

{
  undefined **ppuVar1;
  bool bVar2;
  
  if (param_1 == (undefined **)0x0) {
    bVar2 = false;
  }
  else {
    _raw_spin_lock(&clk_regmap_lock);
    ppuVar1 = &clk_regmap_list;
    do {
      ppuVar1 = (undefined **)*ppuVar1;
      bVar2 = ppuVar1 != &clk_regmap_list;
      if (ppuVar1 == &clk_regmap_list) break;
    } while (ppuVar1 + -0xc != param_1);
    _raw_spin_unlock(&clk_regmap_lock);
  }
  return bVar2;
}



//------------------------------------------------------------
// devm_clk_register_regmap @ 00107a14 size=288
// signature: undefined devm_clk_register_regmap(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

undefined8 devm_clk_register_regmap(long param_1,long param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  code *pcVar7;
  
  *(long *)(param_2 + 0x70) = param_1;
  if ((param_1 != 0) &&
     ((lVar3 = dev_get_regmap(param_1,0), lVar4 = param_1, lVar3 != 0 ||
      (lVar4 = *(long *)(param_1 + 0x60), lVar4 != 0)))) {
    uVar5 = dev_get_regmap(lVar4,0);
    *(undefined8 *)(param_2 + 0x18) = uVar5;
  }
  uVar6 = *(ulong *)(param_2 + 0x88);
  if ((uVar6 & 3) != 0) {
    lVar4 = *(long *)(*(long *)(param_2 + 0x10) + 8);
    if ((lVar4 != 0) && (pcVar7 = *(code **)(lVar4 + 0x20), pcVar7 != (code *)0x0)) {
      if (*(int *)(pcVar7 + -4) != 0x4b2177f0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x107aa4);
        (*pcVar7)();
      }
      (*pcVar7)(param_2);
      uVar6 = *(ulong *)(param_2 + 0x88);
    }
    if ((uVar6 & 1) != 0) {
      return 0;
    }
  }
  uVar5 = devm_clk_hw_register(param_1,param_2);
  if ((int)uVar5 == 0) {
    _raw_spin_lock(&clk_regmap_lock);
    puVar2 = clk_regmap_list;
    puVar1 = (undefined *)(param_2 + 0x60);
    uVar6 = __list_add_valid(puVar1,&clk_regmap_list,clk_regmap_list);
    if ((uVar6 & 1) != 0) {
      *(undefined **)(puVar2 + 8) = puVar1;
      *(undefined **)(param_2 + 0x60) = puVar2;
      *(undefined ***)(param_2 + 0x68) = &clk_regmap_list;
      clk_regmap_list = puVar1;
    }
    _raw_spin_unlock(&clk_regmap_lock);
    uVar5 = clk_hw_debug_register(param_1,param_2);
  }
  return uVar5;
}



//------------------------------------------------------------
// devm_clk_regmap_list_node @ 00107b38 size=92
// signature: undefined devm_clk_regmap_list_node(void)
// callers: []
//------------------------------------------------------------

void devm_clk_regmap_list_node(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  
  puVar2 = clk_regmap_list;
  puVar1 = (undefined *)(param_2 + 0x60);
  uVar3 = __list_add_valid(puVar1,&clk_regmap_list,clk_regmap_list);
  if ((uVar3 & 1) != 0) {
    *(undefined **)(puVar2 + 8) = puVar1;
    *(undefined **)(param_2 + 0x60) = puVar2;
    *(undefined ***)(param_2 + 0x68) = &clk_regmap_list;
    clk_regmap_list = puVar1;
  }
  return;
}



//------------------------------------------------------------
// clk_runtime_get_regmap @ 00107b98 size=56
// signature: undefined clk_runtime_get_regmap(void)
// callers: [clk_regmap_div_list_rate, enable_debug_clks, clk_debug_measure_set, div_round_ro_rate, clk_rcg2_crmc_determine_rate, clk_debug_mux_set_parent, clk_debug_print_hw, clk_debug_measure_get, disable_debug_clks]
//------------------------------------------------------------

undefined8 clk_runtime_get_regmap(long param_1)

{
  undefined8 uVar1;
  
  if (((*(ushort *)(*(long *)(param_1 + 0x70) + 0x200) & 7) != 0) ||
     (uVar1 = __pm_runtime_resume(*(long *)(param_1 + 0x70),4), -1 < (int)uVar1)) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_runtime_put_regmap @ 00107bd4 size=48
// signature: undefined clk_runtime_put_regmap(void)
// callers: [clk_regmap_div_list_rate, enable_debug_clks, clk_debug_measure_set, div_round_ro_rate, clk_rcg2_crmc_determine_rate, clk_debug_mux_set_parent, clk_debug_print_hw, clk_debug_measure_get, disable_debug_clks]
//------------------------------------------------------------

void clk_runtime_put_regmap(long param_1)

{
  if ((*(ushort *)(*(long *)(param_1 + 0x70) + 0x200) & 7) == 0) {
    __pm_runtime_idle(*(long *)(param_1 + 0x70),4);
  }
  return;
}



//------------------------------------------------------------
// clk_restore_critical_clocks @ 00107c08 size=128
// signature: undefined clk_restore_critical_clocks(void)
// callers: [clock_pm_restore_early, clock_pm_resume_early]
//------------------------------------------------------------

void clk_restore_critical_clocks(long param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  lVar4 = *(long *)(param_1 + 0x98);
  lVar3 = dev_get_regmap(param_1,0);
  if ((lVar3 != 0) && (*(long *)(lVar4 + 0x18) != 0)) {
    uVar5 = 0;
    lVar6 = *(long *)(lVar4 + 0x10);
    do {
      puVar1 = (undefined4 *)(lVar6 + uVar5 * 8);
      uVar2 = puVar1[1];
      regmap_update_bits_base(lVar3,*puVar1,uVar2,uVar2,0,0,0);
      uVar5 = (ulong)((int)uVar5 + 1);
    } while (uVar5 < *(ulong *)(lVar4 + 0x18));
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_configure @ 00107c8c size=708
// signature: undefined clk_alpha_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_alpha_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  
  if (*param_3 != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
  }
  if (param_3[3] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
  }
  if (param_3[5] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
  }
  lVar5 = *(long *)(param_1 + 2);
  iVar3 = *param_1;
  iVar1 = iVar3 + (uint)*(byte *)(lVar5 + 9);
  if (iVar1 - (iVar3 + (uint)*(byte *)(lVar5 + 8)) == 4) {
    regmap_write(param_2,iVar1,param_3[6]);
    iVar3 = *param_1;
    lVar5 = *(long *)(param_1 + 2);
  }
  iVar1 = iVar3 + (uint)*(byte *)(lVar5 + 4);
  if (iVar1 - (iVar3 + (uint)*(byte *)(lVar5 + 3)) == 4) {
    regmap_write(param_2,iVar1,param_3[4]);
  }
  uVar4 = param_3[0x11];
  if (param_3[0x10] == 0 && uVar4 == 0) {
    if ((((param_3[0x12] == 0) && (param_3[0x13] == 0)) && (param_3[0x16] == 0)) &&
       ((param_3[0x1c] == 0 && (param_3[0x14] == 0)))) goto LAB_00107dfc;
    uVar4 = 0;
  }
  uVar4 = uVar4 | param_3[0x12] | param_3[0x13] | param_3[0x10];
  regmap_update_bits_base
            (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5),
             param_3[0x17] | param_3[0x1d] | param_3[0x14] | uVar4,
             param_3[0x16] | param_3[0x1c] | param_3[0x14] | uVar4,0,0,0);
LAB_00107dfc:
  if (param_3[0x19] != 0) {
    regmap_update_bits_base
              (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5),param_3[0x19],
               param_3[0x18],0,0,0);
  }
  bVar2 = *(byte *)(param_1 + 0x12);
  if ((bVar2 >> 4 & 1) != 0) {
    regmap_update_bits_base
              (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6),0x800,0xfffff7ff,0,0,0
              );
    bVar2 = *(byte *)(param_1 + 0x12);
  }
  if ((bVar2 >> 3 & 1) == 0) {
    iVar1 = param_3[0x1a];
  }
  else {
    regmap_update_bits_base(param_2,*param_1,0x800000,0x800000,0,0,0);
    iVar1 = param_3[0x1a];
  }
  if (iVar1 != 0) {
    regmap_update_bits_base
              (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc),iVar1,param_3[0xc],0
               ,0,0);
  }
  if (param_3[0x1b] != 0) {
    regmap_update_bits_base
              (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd),param_3[0x1b],
               param_3[0xd],0,0,0);
  }
  bVar2 = *(byte *)(param_1 + 0x12);
  if ((bVar2 >> 3 & 1) != 0) {
    regmap_update_bits_base(param_2,*param_1,0x800000,0x800000,0,0,0);
    bVar2 = *(byte *)(param_1 + 0x12);
  }
  if ((bVar2 >> 2 & 1) != 0) {
    qcom_pll_set_fsm_mode(param_2,*param_1,6,0);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_enable @ 00107f54 size=364
// signature: undefined clk_alpha_pll_enable(void)
// callers: [clk_alpha_pll_slew_enable, clk_alpha_pll_hwfsm_set_rate, alpha_pll_fabia_prepare, clk_alpha_pll_set_rate]
//------------------------------------------------------------

void clk_alpha_pll_enable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined4 *)(param_1 + -0x50);
  local_2c = 0;
  uVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*puVar3,&local_2c);
  if ((int)uVar2 != 0) goto LAB_00107f94;
  if ((local_2c >> 0x14 & 1) == 0) {
    if (((local_2c ^ 0xffffffff) & 7) != 0) {
      uVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),2,2,0,0,0)
      ;
      if ((int)uVar2 == 0) {
        DataSynchronizationBarrier(3,3,0);
        __const_udelay(0x53e3);
        uVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),4,4,0,0,
                           0);
        if (((int)uVar2 == 0) &&
           (uVar2 = wait_for_pll(puVar3,0x80000000,0,"enable"), (int)uVar2 == 0)) {
          uVar2 = regmap_update_bits_base
                            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,1,0,
                             0,0);
          DataSynchronizationBarrier(3,3,0);
        }
      }
      goto LAB_00107f94;
    }
  }
  else {
    uVar2 = clk_enable_regmap(param_1);
    if (((int)uVar2 != 0) || (uVar2 = wait_for_pll(puVar3,0x40000000,0,"enable"), (int)uVar2 != 0))
    goto LAB_00107f94;
    if ((*(byte *)(param_1 + -8) >> 2 & 1) != 0) {
      uVar2 = 0;
      **(uint **)(param_1 + -0x28) = **(uint **)(param_1 + -0x28) | *(uint *)(param_1 + -0x20);
      goto LAB_00107f94;
    }
  }
  uVar2 = 0;
LAB_00107f94:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_disable @ 001080c4 size=240
// signature: undefined clk_alpha_pll_disable(void)
// callers: [clk_alpha_pll_hwfsm_set_rate, alpha_pll_fabia_prepare, clk_alpha_pll_set_rate]
//------------------------------------------------------------

void clk_alpha_pll_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 4 & 1) == 0) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,0,0,0,0);
      DataSynchronizationBarrier(3,3,0);
      __const_udelay(0x10c7);
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),6,0,0,0,0);
    }
    else {
      if ((*(byte *)(param_1 + -8) >> 2 & 1) != 0) {
        **(uint **)(param_1 + -0x28) =
             **(uint **)(param_1 + -0x28) & (*(uint *)(param_1 + -0x20) ^ 0xffffffff);
        if (**(int **)(param_1 + -0x28) != 0) goto LAB_00108188;
      }
      clk_disable_regmap(param_1);
    }
  }
LAB_00108188:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_is_enabled @ 001081b8 size=108
// signature: undefined clk_alpha_pll_is_enabled(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_is_enabled(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint local_1c;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_1c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_1c);
  lVar2 = sp_el0;
  uVar1 = local_1c >> 0x1f;
  if (uVar3 != 0) {
    uVar1 = uVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// clk_pll_restore_context @ 00108228 size=292
// signature: undefined clk_pll_restore_context(void)
// callers: []
//------------------------------------------------------------

void clk_pll_restore_context(long param_1)

{
  uint uVar1;
  long lVar2;
  
  if (*(long *)(param_1 + -0x48) == 0) {
    uVar1 = 0xffffffea;
    lVar2 = *(long *)(param_1 + -0x40);
  }
  else {
    lVar2 = *(long *)(param_1 + -0x48) + -0x11e811;
    uVar1 = (int)((ulong)(lVar2 / 6 + (lVar2 >> 0x3f)) >> 2) - (int)(lVar2 >> 0x3f);
    lVar2 = *(long *)(param_1 + -0x40);
  }
  if (lVar2 == 0) {
    return;
  }
  if (uVar1 < 0x11) {
    lVar2 = param_1 + -0x50;
    switch(uVar1) {
    case 0:
    case 1:
      clk_alpha_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    default:
      goto switchD_001082a0_caseD_2;
    case 3:
      clk_fabia_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 4:
      clk_trion_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 5:
      clk_agera_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 6:
    case 8:
      clk_zonda_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 9:
      clk_regera_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 10:
    case 0xb:
      clk_lucid_evo_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 0xc:
    case 0xd:
      clk_rivian_evo_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
      break;
    case 0x10:
      clk_lucid_5lpe_pll_configure(lVar2,*(undefined8 *)(param_1 + 0x18));
    }
  }
  else {
switchD_001082a0_caseD_2:
    _printk(&DAT_0011d665);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_recalc_rate @ 00108350 size=404
// signature: undefined clk_alpha_pll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_recalc_rate(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined8 local_48;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + -0x48);
  local_3c = 0;
  local_40 = 0;
  local_48 = 0;
  iVar3 = (uint)*(byte *)(lVar4 + 4) - (uint)*(byte *)(lVar4 + 3);
  uVar6 = 0x28;
  if (iVar3 != 4) {
    uVar6 = 0x10;
  }
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(lVar4 + 1),&local_3c);
  if ((iVar2 == 0) &&
     (iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&local_48), iVar2 == 0)) {
    if ((local_48 & 0x1000000) == 0) {
      uVar5 = 0;
    }
    else {
      iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),&local_40);
      if (iVar2 != 0) goto LAB_001083e4;
      if (iVar3 == 4) {
        iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                            *(int *)(param_1 + -0x50) +
                            (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4),(long)&local_48 + 4);
        if (iVar3 != 0) goto LAB_001083e4;
        uVar5 = CONCAT44(local_48._4_4_,local_40) >> ((ulong)(uVar6 - 0x20) & 0x3f);
      }
      else {
        uVar5 = 0xffffffffffffffffU >> ((ulong)-uVar6 & 0x3f) & (ulong)local_40;
      }
    }
    if (0x1f < uVar6) {
      uVar6 = 0x20;
    }
    lVar4 = ((((uVar5 & 0xffffffff) * param_2 >> uVar6) + (ulong)local_3c * param_2 + 999) / 1000) *
            1000;
  }
  else {
LAB_001083e4:
    lVar4 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_init @ 001084e8 size=36
// signature: undefined clk_alpha_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_alpha_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_alpha_pll_round_rate @ 00108510 size=256
// signature: undefined clk_alpha_pll_round_rate(void)
// callers: []
//------------------------------------------------------------

ulong clk_alpha_pll_round_rate(long param_1,ulong param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong *puVar8;
  
  uVar5 = *(ulong *)(param_1 + 0x90);
  if (*(ulong *)(param_1 + 0x90) <= param_2) {
    uVar3 = *param_3;
    uVar6 = uVar3 & 0xffffffff;
    uVar5 = 0;
    if (uVar6 != 0) {
      uVar5 = param_2 / uVar6;
    }
    lVar7 = param_2 - uVar5 * uVar6;
    if (lVar7 != 0) {
      lVar1 = 0x20;
      if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
        lVar1 = 0x10;
      }
      uVar2 = 0;
      if (uVar6 != 0) {
        uVar2 = (ulong)(lVar7 << lVar1) / uVar6;
      }
      param_2 = ((((uVar2 & 0xffffffff) * uVar3 >> lVar1) + (uVar5 & 0xffffffff) * uVar3 + 999) /
                1000) * 1000;
    }
    puVar4 = *(ulong **)(param_1 + -0x38);
    if (puVar4 != (ulong *)0x0) {
      if (puVar4 < puVar4 + *(long *)(param_1 + -0x30) * 3) {
        puVar8 = puVar4;
        do {
          if ((*puVar8 <= param_2) && (param_2 <= puVar8[1])) {
            if (puVar8 != (ulong *)0x0) goto LAB_001085e0;
            break;
          }
          puVar8 = puVar8 + 3;
        } while (puVar8 < puVar4 + *(long *)(param_1 + -0x30) * 3);
      }
      uVar5 = param_2;
      if (param_2 <= *puVar4) {
        uVar5 = *puVar4;
      }
      if (puVar4[*(long *)(param_1 + -0x30) * 3 + -2] <= param_2) {
        uVar5 = puVar4[*(long *)(param_1 + -0x30) * 3 + -2];
      }
      return uVar5;
    }
LAB_001085e0:
    uVar5 = param_2;
  }
  return uVar5;
}



//------------------------------------------------------------
// clk_alpha_pll_set_rate @ 00108614 size=944
// signature: undefined clk_alpha_pll_set_rate(void)
// callers: [clk_alpha_pll_slew_set_rate]
//------------------------------------------------------------

void clk_alpha_pll_set_rate(long param_1,ulong param_2,ulong param_3)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined4 *puVar11;
  ulong uVar12;
  ulong *puVar13;
  int local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  uVar6 = param_3 & 0xffffffff;
  uVar10 = 0;
  if (uVar6 != 0) {
    uVar10 = param_2 / uVar6;
  }
  puVar11 = (undefined4 *)(param_1 + -0x50);
  iVar3 = (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3);
  lVar7 = param_2 - uVar10 * uVar6;
  uVar8 = 0x28;
  if (iVar3 != 4) {
    uVar8 = 0x10;
  }
  if (lVar7 == 0) {
    uVar12 = 0;
  }
  else {
    uVar9 = uVar8;
    if (0x1f < uVar8) {
      uVar9 = 0x20;
    }
    uVar12 = 0;
    if (uVar6 != 0) {
      uVar12 = (ulong)(lVar7 << uVar9) / uVar6;
    }
    if (((((uVar12 & 0xffffffff) * param_3 >> uVar9) + (uVar10 & 0xffffffff) * param_3 + 999) / 1000
        ) * 1000 != param_2) {
      _printk(&DAT_0011dbc4);
      uVar4 = 0xffffffea;
      goto LAB_0010896c;
    }
  }
  puVar1 = *(ulong **)(param_1 + -0x38);
  if (puVar1 < puVar1 + *(long *)(param_1 + -0x30) * 3) {
    puVar13 = puVar1;
    do {
      if ((*puVar13 <= param_2) && (param_2 <= puVar13[1])) goto joined_r0x00108730;
      puVar13 = puVar13 + 3;
    } while (puVar13 < puVar1 + *(long *)(param_1 + -0x30) * 3);
  }
  puVar13 = (ulong *)0x0;
joined_r0x00108730:
  if ((puVar1 == (ulong *)0x0) || (puVar13 != (ulong *)0x0)) {
    local_5c = 0;
    iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*puVar11,&local_5c);
    if (((iVar2 != 0) || (local_5c < 0)) && ((*(byte *)(param_1 + -8) >> 3 & 1) == 0)) {
      clk_alpha_pll_disable(param_1);
    }
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                 uVar10 & 0xffffffff);
    if (iVar3 == 4) {
      uVar12 = uVar12 << ((ulong)(uVar8 - 0x20) & 0x3f);
      regmap_write(*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4),
                   uVar12 >> 0x20);
    }
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                 uVar12 & 0xffffffff);
    if (puVar13 != (ulong *)0x0) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                 0x300000,(int)puVar13[2] << 0x14,0,0,0);
    }
    lVar7 = *(long *)(param_1 + -0x18);
    if (lVar7 != 0) {
      uVar10 = *(ulong *)(param_1 + -0x10);
      if (uVar10 == 0) {
        uVar6 = 0xffffffffffffffff;
        puVar1 = (ulong *)(lVar7 + -0x10);
      }
      else {
        uVar12 = 0;
        do {
          uVar6 = uVar12;
          uVar12 = (ulong)((int)uVar6 + 1);
        } while (*(ulong *)(lVar7 + uVar6 * 0x10) != param_2 && uVar12 < uVar10);
        puVar1 = (ulong *)(lVar7 + uVar6 * 0x10);
      }
      if (puVar1 != (ulong *)0x0) {
        lVar5 = 0;
        if (*puVar1 == param_2) {
          lVar5 = (ulong)*(byte *)(lVar7 + uVar6 * 0x10 + 8) << 8;
        }
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                   (int)(0xffffffffffffffff >> ((ulong)-((uint)(uVar10 >> 0x20) & 0xff) & 0x3f)) <<
                   8,lVar5,0,0,0);
      }
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0x1000000
               ,0x1000000,0,0,0);
    local_5c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if (((iVar3 != 0) || (local_5c < 0)) && ((*(byte *)(param_1 + -8) >> 3 & 1) != 0)) {
      clk_alpha_pll_dynamic_update(puVar11);
    }
    local_5c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if (((iVar3 == 0) && (-1 < local_5c)) && ((*(byte *)(param_1 + -8) >> 3 & 1) == 0)) {
      clk_alpha_pll_enable(param_1);
    }
    local_5c = 0;
    uVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if (((int)uVar4 != 0) || (local_5c < 0)) {
      if ((*(byte *)(param_1 + -8) >> 3 & 1) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = __clk_alpha_pll_update_latch(puVar11);
      }
    }
  }
  else {
    uVar4 = clk_hw_get_name(param_1,*puVar11);
    _printk(&DAT_0011d441,uVar4);
    uVar4 = 0xffffffea;
  }
LAB_0010896c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_huayra_recalc_rate @ 001089c8 size=372
// signature: undefined alpha_pll_huayra_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_huayra_recalc_rate(long param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  local_34 = 0;
  local_30 = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                      &local_2c);
  if ((iVar3 == 0) &&
     (iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&local_34), iVar3 == 0)) {
    if ((local_34 & 0x1000000) == 0) {
      param_2 = (ulong)local_2c * param_2;
    }
    else {
      regmap_read(*(undefined8 *)(param_1 + 0x18),
                  *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                  &local_30);
      if ((local_34._3_1_ >> 1 & 1) != 0) {
        uVar5 = (ulong)(local_30 >> 8) & 0xff;
        if ((uint)uVar5 < 0x80) {
          uVar1 = 0;
          if ((local_30 & 0xff) != 0) {
            uVar1 = (uVar5 * param_2) / ((ulong)local_30 & 0xff);
          }
          lVar4 = uVar1 + (ulong)local_2c * param_2;
        }
        else {
          uVar1 = 0;
          if ((local_30 & 0xff) != 0) {
            uVar1 = ((0x100 - uVar5) * param_2) / ((ulong)local_30 & 0xff);
          }
          lVar4 = (ulong)local_2c * param_2 - uVar1;
        }
        goto LAB_00108a3c;
      }
      param_2 = (ulong)(local_2c - ((local_30 & 0xffff8000) != 0)) * param_2 +
                ((ulong)local_30 * param_2 >> 0x10);
    }
    lVar4 = ((param_2 + 999U) / 1000) * 1000;
  }
  else {
    lVar4 = 0;
  }
LAB_00108a3c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_huayra_round_rate @ 00108b40 size=112
// signature: undefined alpha_pll_huayra_round_rate(void)
// callers: []
//------------------------------------------------------------

ulong alpha_pll_huayra_round_rate(undefined8 param_1,ulong param_2,ulong *param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  
  uVar3 = *param_3;
  uVar5 = uVar3 & 0xffffffff;
  uVar1 = 0;
  if (uVar5 != 0) {
    uVar1 = param_2 / uVar5;
  }
  lVar6 = param_2 - uVar1 * uVar5;
  if (lVar6 != 0) {
    uVar2 = 0;
    if (uVar5 != 0) {
      uVar2 = (ulong)(lVar6 * 0x10000) / uVar5;
    }
    iVar4 = (int)uVar1;
    if ((uVar2 & 0xffffffffffff8000) != 0) {
      iVar4 = iVar4 + 1;
    }
    param_2 = (((iVar4 - (uint)((uVar2 & 0xffff8000) != 0)) * uVar3 +
                ((uVar2 & 0xffffffff) * uVar3 >> 0x10) + 999) / 1000) * 1000;
  }
  return param_2;
}



//------------------------------------------------------------
// alpha_pll_huayra_set_rate @ 00108bb4 size=456
// signature: undefined alpha_pll_huayra_set_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_huayra_set_rate(long param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  int local_44;
  uint uStack_40;
  int local_3c;
  long local_38;
  
  param_3 = param_3 & 0xffffffff;
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  uVar6 = 0;
  if (param_3 != 0) {
    uVar6 = param_2 / param_3;
  }
  local_44 = 0;
  uStack_40 = 0;
  lVar4 = param_2 - uVar6 * param_3;
  if (lVar4 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
    if (param_3 != 0) {
      uVar7 = (ulong)(lVar4 * 0x10000) / param_3;
    }
    uVar5 = (uint)uVar6;
    if ((uVar7 & 0xffffffffffff8000) != 0) {
      uVar5 = uVar5 + 1;
    }
    uVar6 = (ulong)uVar5;
  }
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&uStack_40
             );
  if ((uStack_40 & 0x1000000) != 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                &local_44);
  }
  local_3c = 0;
  iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_3c);
  if ((iVar1 == 0) && (-1 < local_3c)) {
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                 uVar6 & 0xffffffff);
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                 uVar7 & 0xffffffff);
    if ((int)uVar7 == 0) {
      uVar2 = 0x1000000;
      uVar3 = 0;
    }
    else {
      uVar2 = 0x3000000;
      uVar3 = 0x1000000;
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),uVar2,
               uVar3,0,0,0);
    uVar2 = 0;
  }
  else if (local_44 == (int)uVar7) {
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                 uVar6 & 0xffffffff);
    DataSynchronizationBarrier(3,3,0);
    uVar2 = wait_for_pll(param_1 + -0x50,0x80000000,0,"enable");
  }
  else {
    uVar2 = clk_hw_get_name(param_1);
    _printk(&DAT_0011dc9e,uVar2);
    uVar2 = 0xfffffff0;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_huayra_init @ 00108d80 size=36
// signature: undefined clk_alpha_pll_huayra_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_huayra_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_alpha_pll_huayra_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_alpha_pll_hwfsm_enable @ 00108da8 size=180
// signature: undefined clk_alpha_pll_hwfsm_enable(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_hwfsm_enable(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (iVar2 == 0) {
    if ((*(byte *)(param_1 + -8) & 1) != 0) {
      local_2c = local_2c & 0xffffff7f;
    }
    local_2c = local_2c | 0x100000;
    iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50));
    if (iVar2 == 0) {
      DataSynchronizationBarrier(3,3,0);
      wait_for_pll((undefined4 *)(param_1 + -0x50),0x40000000,0,"enable");
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_hwfsm_disable @ 00108e60 size=248
// signature: undefined clk_alpha_pll_hwfsm_disable(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_hwfsm_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined4 *)(param_1 + -0x50);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*puVar3,&local_2c);
  if ((iVar2 == 0) &&
     ((((*(byte *)(param_1 + -8) & 1) == 0 ||
       ((iVar2 = regmap_update_bits_base
                           (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),0x80,
                            0x80,0,0,0), iVar2 == 0 &&
        (iVar2 = wait_for_pll(puVar3,0x10000000,0,"offline"), iVar2 == 0)))) &&
      (iVar2 = regmap_update_bits_base
                         (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),0x100000,
                          0,0,0,0), iVar2 == 0)))) {
    wait_for_pll(puVar3,0x40000000,1,"disable");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_hwfsm_is_enabled @ 00108f5c size=108
// signature: undefined clk_alpha_pll_hwfsm_is_enabled(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_hwfsm_is_enabled(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint local_1c;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_1c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_1c);
  lVar2 = sp_el0;
  uVar1 = local_1c >> 0x1e & 1;
  if (uVar3 != 0) {
    uVar1 = uVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_hwfsm_set_rate @ 00108fcc size=964
// signature: undefined clk_alpha_pll_hwfsm_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_hwfsm_set_rate(long param_1,ulong param_2,ulong param_3)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined4 *puVar11;
  ulong uVar12;
  ulong *puVar13;
  uint local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  uVar6 = param_3 & 0xffffffff;
  uVar10 = 0;
  if (uVar6 != 0) {
    uVar10 = param_2 / uVar6;
  }
  puVar11 = (undefined4 *)(param_1 + -0x50);
  iVar3 = (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3);
  lVar7 = param_2 - uVar10 * uVar6;
  uVar8 = 0x28;
  if (iVar3 != 4) {
    uVar8 = 0x10;
  }
  if (lVar7 == 0) {
    uVar12 = 0;
  }
  else {
    uVar9 = uVar8;
    if (0x1f < uVar8) {
      uVar9 = 0x20;
    }
    uVar12 = 0;
    if (uVar6 != 0) {
      uVar12 = (ulong)(lVar7 << uVar9) / uVar6;
    }
    if (((((uVar12 & 0xffffffff) * param_3 >> uVar9) + (uVar10 & 0xffffffff) * param_3 + 999) / 1000
        ) * 1000 != param_2) {
      _printk(&DAT_0011dbc4);
      uVar4 = 0xffffffea;
      goto LAB_00109338;
    }
  }
  puVar1 = *(ulong **)(param_1 + -0x38);
  if (puVar1 < puVar1 + *(long *)(param_1 + -0x30) * 3) {
    puVar13 = puVar1;
    do {
      if ((*puVar13 <= param_2) && (param_2 <= puVar13[1])) goto joined_r0x001090e8;
      puVar13 = puVar13 + 3;
    } while (puVar13 < puVar1 + *(long *)(param_1 + -0x30) * 3);
  }
  puVar13 = (ulong *)0x0;
joined_r0x001090e8:
  if ((puVar1 == (ulong *)0x0) || (puVar13 != (ulong *)0x0)) {
    local_5c = 0;
    iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*puVar11,&local_5c);
    if ((iVar2 != 0 || (local_5c & 0x40000000) != 0) && ((*(byte *)(param_1 + -8) >> 3 & 1) == 0)) {
      clk_alpha_pll_disable(param_1);
    }
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                 uVar10 & 0xffffffff);
    if (iVar3 == 4) {
      uVar12 = uVar12 << ((ulong)(uVar8 - 0x20) & 0x3f);
      regmap_write(*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4),
                   uVar12 >> 0x20);
    }
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                 uVar12 & 0xffffffff);
    if (puVar13 != (ulong *)0x0) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                 0x300000,(int)puVar13[2] << 0x14,0,0,0);
    }
    lVar7 = *(long *)(param_1 + -0x18);
    if (lVar7 != 0) {
      uVar10 = *(ulong *)(param_1 + -0x10);
      if (uVar10 == 0) {
        uVar6 = 0xffffffffffffffff;
        puVar1 = (ulong *)(lVar7 + -0x10);
      }
      else {
        uVar12 = 0;
        do {
          uVar6 = uVar12;
          uVar12 = (ulong)((int)uVar6 + 1);
        } while (*(ulong *)(lVar7 + uVar6 * 0x10) != param_2 && uVar12 < uVar10);
        puVar1 = (ulong *)(lVar7 + uVar6 * 0x10);
      }
      if (puVar1 != (ulong *)0x0) {
        lVar5 = 0;
        if (*puVar1 == param_2) {
          lVar5 = (ulong)*(byte *)(lVar7 + uVar6 * 0x10 + 8) << 8;
        }
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                   (int)(0xffffffffffffffff >> ((ulong)-((uint)(uVar10 >> 0x20) & 0xff) & 0x3f)) <<
                   8,lVar5,0,0,0);
      }
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0x1000000
               ,0x1000000,0,0,0);
    local_5c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if ((iVar3 != 0 || (local_5c & 0x40000000) != 0) && ((*(byte *)(param_1 + -8) >> 3 & 1) != 0)) {
      clk_alpha_pll_dynamic_update(puVar11);
    }
    local_5c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if ((iVar3 == 0 && (local_5c & 0x40000000) == 0) && ((*(byte *)(param_1 + -8) >> 3 & 1) == 0)) {
      clk_alpha_pll_enable(param_1);
    }
    local_5c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    uVar4 = 0;
    if (iVar3 != 0 || (local_5c & 0x40000000) != 0) {
      if ((*(byte *)(param_1 + -8) >> 3 & 1) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = __clk_alpha_pll_update_latch(puVar11);
      }
    }
  }
  else {
    uVar4 = clk_hw_get_name(param_1,*puVar11);
    _printk(&DAT_0011d441,uVar4);
    uVar4 = 0xffffffea;
  }
LAB_00109338:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_enable @ 00109394 size=308
// signature: undefined clk_trion_pll_enable(void)
// callers: [alpha_pll_trion_prepare, alpha_pll_lucid_prepare]
//------------------------------------------------------------

void clk_trion_pll_enable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  local_3c = 0;
  puVar3 = (undefined4 *)(param_1 + -0x50);
  iVar2 = regmap_read(uVar4,*puVar3,&local_3c);
  if (iVar2 == 0) {
    if ((local_3c._2_1_ >> 4 & 1) == 0) {
      regmap_write(uVar4,*(int *)(param_1 + -0x50) +
                         (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
      iVar2 = wait_for_pll(puVar3,0x80000000,0,"enable");
      if ((iVar2 == 0) &&
         (iVar2 = regmap_update_bits_base
                            (uVar4,*(int *)(param_1 + -0x50) +
                                   (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,7,0,0,0),
         iVar2 == 0)) {
        regmap_update_bits_base(uVar4,*puVar3,1,1,0,0,0);
      }
    }
    else {
      iVar2 = clk_enable_regmap(param_1);
      if (iVar2 == 0) {
        wait_for_pll(puVar3,0x40000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_disable @ 001094cc size=272
// signature: undefined clk_trion_pll_disable(void)
// callers: [alpha_pll_trion_prepare, alpha_pll_lucid_prepare]
//------------------------------------------------------------

void clk_trion_pll_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  local_2c = 0;
  iVar2 = regmap_read(uVar3,*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 4 & 1) == 0) {
      iVar2 = regmap_update_bits_base(uVar3,*(undefined4 *)(param_1 + -0x50),1,0,0,0,0);
      if ((iVar2 == 0) &&
         (iVar2 = regmap_update_bits_base
                            (uVar3,*(int *)(param_1 + -0x50) +
                                   (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,0,0,0,0),
         iVar2 == 0)) {
        regmap_write(uVar3,*(int *)(param_1 + -0x50) +
                           (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0);
        regmap_update_bits_base(uVar3,*(undefined4 *)(param_1 + -0x50),4,4,0,0,0);
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_is_enabled @ 001095e0 size=172
// signature: undefined clk_trion_pll_is_enabled(void)
// callers: []
//------------------------------------------------------------

void clk_trion_pll_is_enabled(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  local_40 = 0;
  iVar3 = regmap_read(uVar5,*(undefined4 *)(param_1 + -0x50),(long)&local_40 + 4);
  iVar4 = regmap_read(uVar5,*(int *)(param_1 + -0x50) +
                            (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
  bVar2 = 0;
  if (iVar4 == 0 && iVar3 == 0) {
    bVar2 = (byte)local_40 & local_40._4_1_ & 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_recalc_rate @ 00109690 size=252
// signature: undefined clk_trion_pll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_trion_pll_recalc_rate(long param_1,long param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + -0x48);
  local_40 = 0;
  bVar1 = *(byte *)(lVar5 + 4);
  bVar2 = *(byte *)(lVar5 + 3);
  iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(lVar5 + 1),(long)&local_40 + 4);
  if ((iVar4 == 0) &&
     (iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),&local_40), iVar4 == 0)) {
    lVar5 = 0x20;
    if ((uint)bVar1 - (uint)bVar2 != 4) {
      lVar5 = 0x10;
    }
    lVar5 = ((((local_40 & 0xffffffff) * param_2 >> lVar5) + (local_40 >> 0x20) * param_2 + 999) /
            1000) * 1000;
  }
  else {
    lVar5 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_init @ 00109790 size=36
// signature: undefined clk_trion_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_trion_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_trion_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_recalc_rate @ 001097b8 size=176
// signature: undefined clk_alpha_pll_postdiv_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_recalc_rate(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                      &local_2c);
  if (iVar3 == 0) {
    uVar4 = (uint)(0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(param_1 + -0xc) & 0x3f));
    uVar1 = 0;
    if ((uVar4 & local_2c >> 8) != 0) {
      uVar1 = 0x20 - (int)LZCOUNT(uVar4 & local_2c >> 8);
    }
    param_2 = param_2 >> ((ulong)uVar1 & 0x3f);
  }
  else {
    param_2 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_round_rate @ 0010986c size=124
// signature: undefined clk_alpha_pll_postdiv_round_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_round_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 *puVar1;
  char cVar2;
  undefined8 uVar3;
  
  cVar2 = *(char *)(param_1 + -0xc);
  puVar1 = clk_alpha_2bit_div_table;
  if (cVar2 != '\x02') {
    puVar1 = clk_alpha_div_table;
  }
  uVar3 = clk_hw_get_parent();
  divider_round_rate_parent(param_1,uVar3,param_2,param_3,puVar1,cVar2,2);
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_set_rate @ 001098ec size=104
// signature: undefined clk_alpha_pll_postdiv_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_set_rate(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_2 & 0xffffffff) != 0) {
    iVar1 = (int)(((param_2 + param_3) - 1) / (param_2 & 0xffffffff));
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),
             *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
             (int)(0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(param_1 + -0xc) & 0x3f)) << 8,
             iVar1 * 0x100 + -0x100,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_round_ro_rate @ 00109958 size=256
// signature: undefined clk_alpha_pll_postdiv_round_ro_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_round_ro_rate(long param_1,long param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),&local_4c);
  uVar2 = ~(uint)(-1L << ((ulong)*(byte *)(param_1 + -0xc) & 0x3f));
  uVar3 = local_4c >> 8;
  local_4c = uVar2 & local_4c >> 8;
  uVar1 = 0;
  if (local_4c != 0) {
    uVar1 = 0x20 - (int)LZCOUNT(uVar2 & uVar3);
  }
  uVar5 = (ulong)(uint)(1 << (ulong)(uVar1 & 0x1f));
  uVar3 = clk_hw_get_flags(param_1);
  if ((uVar3 >> 2 & 1) == 0) {
    lVar4 = *param_3;
  }
  else {
    lVar4 = clk_hw_get_parent(param_1);
    if (lVar4 == 0) {
      uVar5 = 0xffffffffffffffea;
      goto LAB_00109a1c;
    }
    lVar4 = clk_hw_round_rate(lVar4,uVar5 * param_2);
    *param_3 = lVar4;
  }
  uVar5 = (uVar5 + lVar4) - 1 >> ((ulong)uVar1 & 0x3f);
LAB_00109a1c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_fabia_pll_configure @ 00109a5c size=460
// signature: undefined clk_fabia_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_fabia_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  if (*param_3 != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
  }
  if (param_3[3] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x13));
  }
  if (param_3[5] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
  }
  if (param_3[6] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
  }
  if (param_3[9] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
  }
  if (param_3[10] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
  }
  if (param_3[0xc] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
  }
  if (param_3[0xd] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
  }
  if (param_3[0x19] != 0) {
    regmap_update_bits_base
              (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5),param_3[0x19],
               param_3[0x18],0,0,0);
  }
  if ((*(byte *)(param_1 + 0x12) >> 4 & 1) != 0) {
    regmap_update_bits_base(param_2,*param_1,0x1000000,0x1000000,0,0,0);
  }
  regmap_update_bits_base(param_2,*param_1,0x800000,0x800000,0,0,0);
  regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
  return;
}



//------------------------------------------------------------
// alpha_pll_fabia_prepare @ 00109c2c size=580
// signature: undefined alpha_pll_fabia_prepare(void)
// callers: []
//------------------------------------------------------------

int alpha_pll_fabia_prepare(long param_1)

{
  long lVar1;
  ulong *puVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong uVar13;
  undefined4 local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_4c = 0;
  bVar3 = *(byte *)(*(long *)(param_1 + -0x48) + 4);
  bVar4 = *(byte *)(*(long *)(param_1 + -0x48) + 3);
  uVar6 = clk_hw_get_name();
  iVar5 = clk_prepare_regmap(param_1);
  if (iVar5 == 0) {
    iVar5 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_4c);
    if (iVar5 == 0) {
      if (((byte)local_4c >> 2 & 1) == 0) {
        uVar7 = clk_hw_get_rate(param_1);
        puVar2 = *(ulong **)(param_1 + -0x38);
        if (puVar2 < puVar2 + *(long *)(param_1 + -0x30) * 3) {
          puVar11 = puVar2;
          do {
            if ((*puVar11 <= uVar7) && (uVar7 <= puVar11[1])) {
              if (puVar11 != (ulong *)0x0) {
                uVar7 = *puVar2;
                uVar9 = puVar2[1];
                lVar8 = clk_hw_get_parent(param_1);
                if (lVar8 == 0) goto LAB_00109df8;
                uVar12 = ((uVar9 + uVar7) * 0x36 + 0x32) / 100;
                uVar9 = clk_hw_get_rate();
                uVar10 = uVar9 & 0xffffffff;
                uVar7 = 0;
                if (uVar10 != 0) {
                  uVar7 = uVar12 / uVar10;
                }
                lVar8 = uVar12 - uVar7 * uVar10;
                uVar13 = uVar12;
                if (lVar8 != 0) {
                  lVar1 = 0x20;
                  if ((uint)bVar3 - (uint)bVar4 != 4) {
                    lVar1 = 0x10;
                  }
                  uVar13 = 0;
                  if (uVar10 != 0) {
                    uVar13 = (ulong)(lVar8 << lVar1) / uVar10;
                  }
                  uVar13 = ((((uVar13 & 0xffffffff) * uVar9 >> lVar1) + (uVar7 & 0xffffffff) * uVar9
                            + 999) / 1000) * 1000;
                }
                if ((uVar13 < uVar12) || (uVar12 + 500 < uVar13)) {
                  uVar6 = clk_hw_get_name(param_1);
                  _printk(&DAT_0011d689,uVar6,uVar13,uVar12,uVar12 + 500);
                  goto LAB_00109df8;
                }
                regmap_write(*(undefined8 *)(param_1 + 0x18),
                             *(int *)(param_1 + -0x50) +
                             (uint)*(byte *)(*(long *)(param_1 + -0x48) + 2));
                iVar5 = clk_alpha_pll_enable(param_1);
                if (iVar5 == 0) {
                  clk_alpha_pll_disable(param_1);
                }
                else {
                  _printk(&DAT_0011d51e,uVar6);
                }
                goto LAB_00109dfc;
              }
              break;
            }
            puVar11 = puVar11 + 3;
          } while (puVar11 < puVar2 + *(long *)(param_1 + -0x30) * 3);
        }
        _printk(&DAT_0011d441,uVar6);
LAB_00109df8:
        iVar5 = -0x16;
      }
      else {
        iVar5 = 0;
      }
    }
  }
LAB_00109dfc:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// alpha_pll_fabia_enable @ 00109e74 size=472
// signature: undefined alpha_pll_fabia_enable(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_fabia_enable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined4 *)(param_1 + -0x50);
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  local_40 = 0;
  uVar2 = regmap_read(uVar4,*puVar3,(long)&local_40 + 4);
  if ((int)uVar2 == 0) {
    if ((local_40._6_1_ >> 4 & 1) == 0) {
      uVar2 = regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                                (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
      if ((int)uVar2 == 0) {
        if (((local_40 & 1) == 0) || ((local_40 & 0x100000000) == 0)) {
          uVar2 = regmap_update_bits_base(uVar4,*puVar3,1,0,0,0,0);
          if (((((int)uVar2 == 0) &&
               (uVar2 = regmap_write(uVar4,*(int *)(param_1 + -0x50) +
                                           (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0),
               (int)uVar2 == 0)) &&
              (uVar2 = regmap_update_bits_base(uVar4,*puVar3,4,4,0,0,0), (int)uVar2 == 0)) &&
             (((uVar2 = regmap_write(uVar4,*(int *)(param_1 + -0x50) +
                                           (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1),
               (int)uVar2 == 0 &&
               (uVar2 = wait_for_pll(puVar3,0x80000000,0,"enable"), (int)uVar2 == 0)) &&
              (uVar2 = regmap_update_bits_base
                                 (uVar4,*(int *)(param_1 + -0x50) +
                                        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,7,0,0,0),
              (int)uVar2 == 0)))) {
            uVar2 = regmap_update_bits_base(uVar4,*puVar3,1,1,0,0,0);
          }
        }
        else {
          uVar2 = 0;
        }
      }
    }
    else {
      uVar2 = clk_enable_regmap(param_1);
      if ((int)uVar2 == 0) {
        uVar2 = wait_for_pll(puVar3,0x40000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_fabia_disable @ 0010a050 size=240
// signature: undefined alpha_pll_fabia_disable(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_fabia_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  local_2c = 0;
  iVar2 = regmap_read(uVar3,*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 4 & 1) == 0) {
      iVar2 = regmap_update_bits_base(uVar3,*(undefined4 *)(param_1 + -0x50),1,0,0,0,0);
      if ((iVar2 == 0) &&
         (iVar2 = regmap_update_bits_base
                            (uVar3,*(int *)(param_1 + -0x50) +
                                   (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,0,0,0,0),
         iVar2 == 0)) {
        regmap_write(uVar3,*(int *)(param_1 + -0x50) +
                           (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0);
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_fabia_recalc_rate @ 0010a144 size=252
// signature: undefined alpha_pll_fabia_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_fabia_recalc_rate(long param_1,long param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + -0x48);
  local_40 = 0;
  bVar1 = *(byte *)(lVar5 + 4);
  bVar2 = *(byte *)(lVar5 + 3);
  iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(lVar5 + 1),(long)&local_40 + 4);
  if ((iVar4 == 0) &&
     (iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x13),&local_40), iVar4 == 0)
     ) {
    lVar5 = 0x20;
    if ((uint)bVar1 - (uint)bVar2 != 4) {
      lVar5 = 0x10;
    }
    lVar5 = ((((local_40 & 0xffffffff) * param_2 >> lVar5) + (local_40 >> 0x20) * param_2 + 999) /
            1000) * 1000;
  }
  else {
    lVar5 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_fabia_set_rate @ 0010a244 size=316
// signature: undefined alpha_pll_fabia_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 alpha_pll_fabia_set_rate(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar3 = param_3 & 0xffffffff;
  uVar6 = 0;
  if (uVar3 != 0) {
    uVar6 = param_2 / uVar3;
  }
  lVar4 = param_2 - uVar6 * uVar3;
  if (lVar4 == 0) {
    uVar5 = 0;
    uVar6 = param_2;
  }
  else {
    lVar1 = 0x20;
    if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
      lVar1 = 0x10;
    }
    uVar5 = 0;
    if (uVar3 != 0) {
      uVar5 = (ulong)(lVar4 << lVar1) / uVar3;
    }
    uVar6 = ((((uVar5 & 0xffffffff) * param_3 >> lVar1) + (uVar6 & 0xffffffff) * param_3 + 999) /
            1000) * 1000;
  }
  if ((uVar6 < param_2) || (param_2 + 500 < uVar6)) {
    uVar2 = clk_hw_get_name(param_1);
    _printk(&DAT_0011d689,uVar2,uVar6,param_2,param_2 + 500);
    uVar2 = 0xffffffea;
  }
  else {
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1));
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x13),
                 uVar5 & 0xffffffff);
    uVar2 = __clk_alpha_pll_update_latch(param_1 + -0x50);
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_fabia_pll_init @ 0010a384 size=36
// signature: undefined clk_fabia_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_fabia_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_fabia_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_trion_pll_postdiv_recalc_rate @ 0010a3ac size=264
// signature: undefined clk_trion_pll_postdiv_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_trion_pll_postdiv_recalc_rate(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0011ccfd);
    uVar3 = 0xffffffffffffffea;
  }
  else {
    iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                        *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                        &local_2c);
    if (iVar2 == 0) {
      local_2c = local_2c >> (ulong)(*(uint *)(param_1 + 0x90) & 0x1f) &
                 (uint)(0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(param_1 + -0xc) & 0x3f));
      if (*(ulong *)(param_1 + 0xa0) == 0) {
        uVar4 = 1;
      }
      else {
        uVar3 = 0;
        uVar4 = 1;
        do {
          if (*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8) == local_2c) {
            uVar4 = (ulong)*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8 + 4);
            break;
          }
          uVar3 = (ulong)((int)uVar3 + 1);
        } while (uVar3 < *(ulong *)(param_1 + 0xa0));
      }
      uVar3 = 0;
      if (uVar4 != 0) {
        uVar3 = param_2 / uVar4;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_postdiv_round_rate @ 0010a4b8 size=104
// signature: undefined clk_trion_pll_postdiv_round_rate(void)
// callers: []
//------------------------------------------------------------

void clk_trion_pll_postdiv_round_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x98);
  uVar1 = *(undefined1 *)(param_1 + -0xc);
  uVar2 = clk_hw_get_parent();
  divider_round_rate_parent(param_1,uVar2,param_2,param_3,uVar3,uVar1,0x10);
  return;
}



//------------------------------------------------------------
// clk_trion_pll_postdiv_set_rate @ 0010a524 size=196
// signature: undefined clk_trion_pll_postdiv_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_trion_pll_postdiv_set_rate(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
    _printk(&DAT_0011ccfd);
    uVar1 = 0xffffffea;
  }
  else {
    if (*(ulong *)(param_1 + 0xa0) != 0) {
      iVar2 = 0;
      if ((param_2 & 0xffffffff) != 0) {
        iVar2 = (int)(((param_2 + param_3) - 1) / (param_2 & 0xffffffff));
      }
      uVar4 = 0;
      do {
        if (*(int *)(lVar3 + uVar4 * 8 + 4) == iVar2) {
          iVar2 = *(int *)(lVar3 + uVar4 * 8);
          goto LAB_0010a58c;
        }
        uVar4 = (ulong)((int)uVar4 + 1);
      } while (uVar4 < *(ulong *)(param_1 + 0xa0));
    }
    iVar2 = 0;
LAB_0010a58c:
    uVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                       (0xffffffffffffffffU >> ((ulong)-(uint)*(byte *)(param_1 + -0xc) & 0x3f)) <<
                       ((ulong)*(uint *)(param_1 + 0x90) & 0x3f),
                       iVar2 << (ulong)(*(uint *)(param_1 + 0x90) & 0x1f),0,0,0);
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_fabia_recalc_rate @ 0010a5ec size=232
// signature: undefined clk_alpha_pll_postdiv_fabia_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_fabia_recalc_rate(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                      &local_2c);
  if (iVar2 == 0) {
    local_2c = local_2c >> (ulong)(*(uint *)(param_1 + 0x90) & 0x1f) &
               ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0xc) & 0x3f)) ^ 0xffffffff);
    if (*(ulong *)(param_1 + 0xa0) == 0) {
      uVar4 = 1;
    }
    else {
      uVar3 = 0;
      uVar4 = 1;
      do {
        if (*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8) == local_2c) {
          uVar4 = (ulong)*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8 + 4);
          break;
        }
        uVar3 = (ulong)((int)uVar3 + 1);
      } while (uVar3 < *(ulong *)(param_1 + 0xa0));
    }
    uVar3 = 0;
    if (uVar4 != 0) {
      uVar3 = param_2 / uVar4;
    }
  }
  else {
    uVar3 = (ulong)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_fabia_round_rate @ 0010a6d8 size=104
// signature: undefined clk_alpha_pll_postdiv_fabia_round_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_fabia_round_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x98);
  uVar1 = *(undefined1 *)(param_1 + -0xc);
  uVar2 = clk_hw_get_parent();
  divider_round_rate_parent(param_1,uVar2,param_2,param_3,uVar3,uVar1,0x10);
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_postdiv_fabia_set_rate @ 0010a744 size=280
// signature: undefined clk_alpha_pll_postdiv_fabia_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_postdiv_fabia_set_rate(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x10),&local_3c);
  if ((int)uVar3 == 0) {
    if ((local_3c >> 0x14 & 1) == 0) {
      if (*(ulong *)(param_1 + 0xa0) != 0) {
        uVar4 = 0;
        iVar1 = 0;
        if ((param_2 & 0xffffffff) != 0) {
          iVar1 = (int)(((param_2 + param_3) - 1) / (param_2 & 0xffffffff));
        }
        do {
          if (*(int *)(*(long *)(param_1 + 0x98) + uVar4 * 8 + 4) == iVar1) {
            local_3c = *(uint *)(*(long *)(param_1 + 0x98) + uVar4 * 8);
            break;
          }
          uVar4 = (ulong)((int)uVar4 + 1);
        } while (uVar4 < *(ulong *)(param_1 + 0xa0));
      }
      uVar3 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                         (ulong)~(uint)(-1L << ((ulong)*(byte *)(param_1 + -0xc) & 0x3f)) <<
                         ((ulong)*(uint *)(param_1 + 0x90) & 0x3f),
                         local_3c << (ulong)(*(uint *)(param_1 + 0x90) & 0x1f),0,0,0);
    }
    else {
      uVar3 = 0;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_lucid_5lpe_pll_configure @ 0010a860 size=776
// signature: undefined clk_lucid_5lpe_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_lucid_5lpe_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = regmap_read(param_2,*param_1,(long)&local_40 + 4);
  iVar3 = regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),&local_40);
  if (((iVar3 == 0 && iVar2 == 0) && ((local_40 & 1) != 0)) && ((local_40 & 0x100000000) != 0)) {
    uVar7 = clk_hw_get_name(param_1 + 0x14);
    _printk(&DAT_0011cac8,uVar7);
    uVar8 = 0;
  }
  else {
    if (*param_3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
    }
    iVar2 = 0x44;
    if (param_3[1] != 0) {
      iVar2 = param_3[1];
    }
    uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 2),iVar2);
    uVar5 = uVar5 | uVar4;
    if (param_3[3] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[5] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[6] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[7] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[9] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[10] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[0xb] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 7));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[0xc] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[0xd] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
      uVar5 = uVar4 | uVar5;
    }
    if (param_3[0xe] != 0) {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
      uVar5 = uVar4 | uVar5;
    }
    iVar2 = regmap_update_bits_base(param_2,*param_1,1,0,0,0,0);
    iVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
    DataSynchronizationBarrier(3,2,0);
    iVar6 = regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
    uVar8 = 0;
    if ((iVar2 != 0 || iVar6 != 0) || (uVar5 != 0 || iVar3 != 0)) {
      uVar8 = 0xfffffffb;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_configure @ 0010ab6c size=732
// signature: undefined clk_trion_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_trion_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = regmap_read(param_2,*param_1,(long)&local_40 + 4);
  iVar3 = regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),&local_40);
  if (((iVar3 != 0 || iVar2 != 0) || ((local_40 & 1) == 0)) || ((local_40 & 0x100000000) == 0)) {
    if (*param_3 != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
    }
    iVar2 = 0x44;
    if (param_3[1] != 0) {
      iVar2 = param_3[1];
    }
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 2),iVar2);
    if (param_3[3] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
    }
    if (param_3[5] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
    }
    if (param_3[6] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
    }
    if (param_3[7] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
    }
    if (param_3[9] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
    }
    if (param_3[10] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
    }
    if (param_3[0xb] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 7));
    }
    if (param_3[0xc] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
    }
    if (param_3[0xd] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
    }
    if (param_3[0xe] != 0) {
      regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
    }
    regmap_update_bits_base(param_2,*param_1,0x800000,0x800000,0,0,0);
    if ((*(byte *)(param_1 + 0x12) >> 4 & 1) != 0) {
      regmap_update_bits_base(param_2,*param_1,0x1000000,0x1000000,0,0,0);
    }
    regmap_update_bits_base(param_2,*param_1,1,0,0,0,0);
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
    regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_trion_prepare @ 0010ae4c size=152
// signature: undefined alpha_pll_trion_prepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_trion_prepare(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar2 = clk_prepare_regmap();
  if ((int)uVar2 == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x11),
                &local_2c);
    if ((local_2c._3_1_ >> 2 & 1) == 0) {
      uVar2 = clk_trion_pll_enable(param_1);
      if ((int)uVar2 != 0) goto LAB_0010aeb8;
      clk_trion_pll_disable(param_1);
    }
    uVar2 = 0;
  }
LAB_0010aeb8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_trion_set_rate @ 0010aee8 size=36
// signature: undefined alpha_pll_trion_set_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_trion_set_rate(void)

{
  __alpha_pll_trion_set_rate();
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_prepare @ 0010af10 size=140
// signature: undefined alpha_pll_lucid_prepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_prepare(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar2 = clk_prepare_regmap();
  if ((int)uVar2 == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
    if ((local_2c._3_1_ >> 3 & 1) == 0) {
      uVar2 = clk_trion_pll_enable(param_1);
      if ((int)uVar2 != 0) goto LAB_0010af70;
      clk_trion_pll_disable(param_1);
    }
    uVar2 = 0;
  }
LAB_0010af70:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_lucid_pll_init @ 0010afa0 size=36
// signature: undefined clk_lucid_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_lucid_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_lucid_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_agera_pll_configure @ 0010afc8 size=276
// signature: undefined clk_agera_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_agera_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  if (*param_3 != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
  }
  if (param_3[3] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
  }
  if (param_3[9] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
  }
  if (param_3[5] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
  }
  if (param_3[6] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
  }
  if (param_3[0xc] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
  }
  if (param_3[0xd] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_agera_set_rate @ 0010b0e0 size=348
// signature: undefined clk_alpha_pll_agera_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_agera_set_rate(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar4 = param_3 & 0xffffffff;
  uVar2 = 0;
  if (uVar4 != 0) {
    uVar2 = param_2 / uVar4;
  }
  lVar5 = param_2 - uVar2 * uVar4;
  if (lVar5 == 0) {
    uVar6 = 0;
    uVar2 = param_2;
  }
  else {
    lVar1 = 0x20;
    if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
      lVar1 = 0x10;
    }
    uVar6 = 0;
    if (uVar4 != 0) {
      uVar6 = (ulong)(lVar5 << lVar1) / uVar4;
    }
    uVar2 = ((((uVar6 & 0xffffffff) * param_3 >> lVar1) + (uVar2 & 0xffffffff) * param_3 + 999) /
            1000) * 1000;
  }
  if ((uVar2 < param_2) || (param_2 + 500 < uVar2)) {
    uVar3 = clk_hw_get_name(param_1);
    _printk(&DAT_0011d689,uVar3,uVar2,param_2,param_2 + 500);
    uVar3 = 0xffffffea;
  }
  else {
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1));
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                 uVar6 & 0xffffffff);
    uVar2 = clk_hw_is_enabled(param_1);
    if ((uVar2 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = wait_for_pll(param_1 + -0x50,0x80000000,0,"enable");
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_agera_pll_init @ 0010b240 size=36
// signature: undefined clk_agera_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_agera_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_agera_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// alpha_pll_lucid_5lpe_prepare @ 0010b268 size=160
// signature: undefined alpha_pll_lucid_5lpe_prepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_5lpe_prepare(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  uVar1 = clk_prepare_regmap();
  if ((int)uVar1 != 0) goto LAB_0010b2dc;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
  if ((local_2c._1_1_ >> 3 & 1) == 0) {
    lVar2 = clk_hw_get_parent(param_1);
    if (lVar2 == 0) {
      uVar1 = 0xffffffea;
      goto LAB_0010b2dc;
    }
    uVar1 = alpha_pll_lucid_5lpe_enable(param_1);
    if ((int)uVar1 != 0) goto LAB_0010b2dc;
    alpha_pll_lucid_5lpe_disable(param_1);
  }
  uVar1 = 0;
LAB_0010b2dc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_5lpe_enable @ 0010b30c size=408
// signature: undefined alpha_pll_lucid_5lpe_enable(void)
// callers: [alpha_pll_lucid_5lpe_prepare]
//------------------------------------------------------------

void alpha_pll_lucid_5lpe_enable(long param_1)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  piVar3 = (int *)(param_1 + -0x50);
  local_44 = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *piVar3 + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&local_44);
  if (iVar2 == 0) {
    if ((local_44._2_1_ >> 5 & 1) == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x18);
      local_3c = 0;
      local_40 = 0;
      regmap_read(uVar4,*(undefined4 *)(param_1 + -0x50),&local_3c);
      regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),4,4,0,0,0)
      ;
      if (iVar2 == 0) {
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),
                     1);
        iVar2 = wait_for_pll(piVar3,0x80000000,0,"enable");
        if ((iVar2 == 0) &&
           (iVar2 = regmap_update_bits_base
                              (*(undefined8 *)(param_1 + 0x18),
                               *(int *)(param_1 + -0x50) +
                               (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,7,0,0,0),
           iVar2 == 0)) {
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,1,0,0,0);
        }
      }
    }
    else {
      iVar2 = clk_enable_regmap(param_1);
      if (iVar2 == 0) {
        wait_for_pll(piVar3,0x80000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_5lpe_disable @ 0010b4a8 size=248
// signature: undefined alpha_pll_lucid_5lpe_disable(void)
// callers: [alpha_pll_lucid_5lpe_prepare]
//------------------------------------------------------------

void alpha_pll_lucid_5lpe_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                      &local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 5 & 1) == 0) {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,0,0,0,0)
      ;
      if ((iVar2 == 0) &&
         (iVar2 = regmap_update_bits_base
                            (*(undefined8 *)(param_1 + 0x18),
                             *(int *)(param_1 + -0x50) +
                             (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,0,0,0,0), iVar2 == 0)
         ) {
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),
                     0);
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_5lpe_set_rate @ 0010b5a4 size=36
// signature: undefined alpha_pll_lucid_5lpe_set_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_5lpe_set_rate(void)

{
  __alpha_pll_trion_set_rate();
  return;
}



//------------------------------------------------------------
// clk_lucid_5lpe_pll_postdiv_set_rate @ 0010b5cc size=32
// signature: undefined clk_lucid_5lpe_pll_postdiv_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_lucid_5lpe_pll_postdiv_set_rate(void)

{
  __clk_lucid_pll_postdiv_set_rate();
  return;
}



//------------------------------------------------------------
// clk_zonda_pll_configure @ 0010b5f0 size=528
// signature: undefined clk_zonda_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_zonda_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  if (*param_3 != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
  }
  if (param_3[3] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
  }
  if (param_3[5] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
  }
  if (param_3[6] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
  }
  if (param_3[7] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
  }
  if (param_3[9] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
  }
  if (param_3[10] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
  }
  if (param_3[0xb] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 7));
  }
  if (param_3[0xc] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
  }
  if (param_3[0xd] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
  }
  if (param_3[0xe] != 0) {
    regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
  }
  regmap_update_bits_base(param_2,*param_1,2,0,0,0,0);
  regmap_update_bits_base(param_2,*param_1,1,0,0,0,0);
  regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
  regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_zonda_pll_enable @ 0010b804 size=428
// signature: undefined clk_zonda_pll_enable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_pll_enable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  local_3c = 0;
  puVar5 = (undefined4 *)(param_1 + -0x50);
  regmap_read(uVar4,*puVar5,&local_3c);
  if ((local_3c._2_1_ >> 4 & 1) == 0) {
    regmap_update_bits_base(uVar4,*(undefined4 *)(param_1 + -0x50),2,2,0,0,0);
    __const_udelay(0x10c7);
    regmap_update_bits_base(uVar4,*(undefined4 *)(param_1 + -0x50),4,4,0,0,0);
    regmap_write(uVar4,*(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
    regmap_read(uVar4,*(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0xc),
                &local_3c);
    if ((local_3c & 0x10000) == 0) {
      pcVar3 = "enable";
      uVar2 = 0x80000000;
    }
    else {
      pcVar3 = "freq enable";
      uVar2 = 0x20000000;
    }
    uVar2 = wait_for_pll(puVar5,uVar2,0,pcVar3);
    if ((int)uVar2 == 0) {
      regmap_update_bits_base
                (uVar4,*(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                 0xf,0xf,0,0,0);
      regmap_update_bits_base(uVar4,*(undefined4 *)(param_1 + -0x50),1,1,0,0,0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = clk_enable_regmap(param_1);
    if ((int)uVar2 == 0) {
      uVar2 = wait_for_pll(puVar5,0x40000000,0,"enable");
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_zonda_pll_disable @ 0010b9b4 size=260
// signature: undefined clk_zonda_pll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_pll_disable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  local_2c = 0;
  regmap_read(uVar2,*(undefined4 *)(param_1 + -0x50),&local_2c);
  if ((local_2c._2_1_ >> 4 & 1) == 0) {
    regmap_update_bits_base(uVar2,*(undefined4 *)(param_1 + -0x50),1,0,0,0,0);
    regmap_update_bits_base
              (uVar2,*(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf
               ,0,0,0,0);
    regmap_update_bits_base(uVar2,*(undefined4 *)(param_1 + -0x50),6,0,0,0,0);
    regmap_write(uVar2,*(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0);
  }
  else {
    clk_disable_regmap(param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_zonda_pll_set_rate @ 0010babc size=484
// signature: undefined clk_zonda_pll_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_pll_set_rate(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  uint local_3c;
  long local_38;
  
  uVar5 = param_3 & 0xffffffff;
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  uVar2 = 0;
  if (uVar5 != 0) {
    uVar2 = param_2 / uVar5;
  }
  local_3c = 0;
  lVar7 = param_2 - uVar2 * uVar5;
  if (lVar7 == 0) {
    uVar6 = 0;
    uVar5 = param_2;
  }
  else {
    lVar1 = 0x20;
    if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
      lVar1 = 0x10;
    }
    uVar6 = 0;
    if (uVar5 != 0) {
      uVar6 = (ulong)(lVar7 << lVar1) / uVar5;
    }
    uVar5 = ((((uVar6 & 0xffffffff) * param_3 >> lVar1) + (uVar2 & 0xffffffff) * param_3 + 999) /
            1000) * 1000;
  }
  if ((uVar5 < param_2) || (param_2 + 500 < uVar5)) {
    uVar3 = clk_hw_get_name(param_1);
    _printk(&DAT_0011d689,uVar3,uVar5,param_2,param_2 + 500);
    uVar3 = 0xffffffea;
  }
  else {
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                 uVar6 & 0xffffffff);
    regmap_write(*(undefined8 *)(param_1 + 0x18),
                 *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                 ((uint)(param_3 <= (ulong)(lVar7 * 2)) & (uint)uVar6 >> 0xf) + (int)uVar2);
    uVar2 = clk_hw_is_enabled(param_1);
    if ((uVar2 & 1) != 0) {
      __const_udelay(0x53e3);
      regmap_read(*(undefined8 *)(param_1 + 0x18),
                  *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0xc),
                  &local_3c);
      if ((local_3c & 0x10000) == 0) {
        pcVar4 = "enable";
        uVar3 = 0x80000000;
      }
      else {
        pcVar4 = "freq enable";
        uVar3 = 0x20000000;
      }
      uVar3 = wait_for_pll(param_1 + -0x50,uVar3,0,pcVar4);
      if ((int)uVar3 != 0) goto LAB_0010bc44;
      __const_udelay(0x68dbc);
    }
    uVar3 = 0;
  }
LAB_0010bc44:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_zonda_init @ 0010bca4 size=36
// signature: undefined clk_alpha_pll_zonda_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_zonda_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_alpha_pll_zonda_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_zonda_5lpe_pll_enable @ 0010bccc size=536
// signature: undefined clk_zonda_5lpe_pll_enable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_5lpe_pll_enable(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  int *piVar6;
  undefined8 local_48;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  piVar6 = (int *)(param_1 + -0x50);
  local_48 = 0;
  uVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *piVar6 + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),(long)&local_48 + 4)
  ;
  if ((int)uVar4 == 0) {
    if ((local_48._6_1_ >> 5 & 1) == 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x18);
      local_3c = 0;
      local_40 = 0;
      iVar2 = regmap_read(uVar4,*(undefined4 *)(param_1 + -0x50),&local_3c);
      iVar3 = regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                                (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
      if (((iVar3 == 0 && iVar2 == 0) && ((local_40 & 1) != 0)) && ((local_3c & 1) != 0)) {
        uVar4 = clk_hw_get_name(param_1);
        _printk(&DAT_0011cac8,uVar4);
        uVar4 = 0;
      }
      else {
        uVar4 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),6,6,0,0,
                           0);
        if ((int)uVar4 == 0) {
          regmap_write(*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
          uVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                              *(int *)(param_1 + -0x50) +
                              (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0xc),&local_48);
          if ((int)uVar4 == 0) {
            if ((local_48 & 0x10000) == 0) {
              pcVar5 = "enable";
              uVar4 = 0x80000000;
            }
            else {
              pcVar5 = "freq enable";
              uVar4 = 0x20000000;
            }
            uVar4 = wait_for_pll(piVar6,uVar4,0,pcVar5);
            if ((((int)uVar4 == 0) &&
                (uVar4 = regmap_update_bits_base
                                   (*(undefined8 *)(param_1 + 0x18),
                                    *(int *)(param_1 + -0x50) +
                                    (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf,0xf,0,0,0),
                (int)uVar4 == 0)) &&
               (uVar4 = regmap_update_bits_base
                                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),
                                   1,1,0,0,0), (int)uVar4 == 0)) {
              DataSynchronizationBarrier(3,3,0);
            }
          }
        }
      }
    }
    else {
      uVar4 = clk_enable_regmap(param_1);
      if ((int)uVar4 == 0) {
        uVar4 = wait_for_pll(piVar6,0x40000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_zonda_5lpe_pll_disable @ 0010bee8 size=280
// signature: undefined clk_zonda_5lpe_pll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_5lpe_pll_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                      &local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 5 & 1) == 0) {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,0,0,0,0)
      ;
      if ((iVar2 == 0) &&
         (iVar2 = regmap_update_bits_base
                            (*(undefined8 *)(param_1 + 0x18),
                             *(int *)(param_1 + -0x50) +
                             (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),7,0,0,0,0), iVar2 == 0)
         ) {
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),
                     0);
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),6,0,0,0,0);
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_regera_pll_configure @ 0010c004 size=488
// signature: undefined clk_regera_pll_configure(void)
// callers: [clk_regera_pll_set_rate, clk_pll_restore_context, clk_regera_pll_enable]
//------------------------------------------------------------

void clk_regera_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  undefined8 uVar2;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (param_3 == (int *)0x0) {
    _printk(&DAT_0011cd83);
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = regmap_read(param_2,*param_1,&local_3c);
    if ((int)uVar2 == 0) {
      if (local_3c < 0) {
        _printk(&DAT_0011d8a5);
      }
      else {
        if (param_3[3] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
        }
        if (*param_3 != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
        }
        if (param_3[5] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
        }
        if (param_3[6] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
        }
        if (param_3[7] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
        }
        if (param_3[9] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
        }
        if (param_3[0xc] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
        }
        if (param_3[0xd] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
        }
        if (param_3[0xe] != 0) {
          regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
        }
        regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
      }
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_regera_pll_enable @ 0010c1f0 size=544
// signature: undefined clk_regera_pll_enable(void)
// callers: []
//------------------------------------------------------------

int clk_regera_pll_enable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar4 = (undefined4 *)(param_1 + -0x50);
  local_40 = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*puVar4,(long)&local_40 + 4);
  if (iVar2 == 0) {
    if ((local_40._6_1_ >> 4 & 1) == 0) {
      iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),&local_40);
      if (iVar2 == 0) {
        if ((int)local_40 == 0) {
          iVar2 = clk_regera_pll_configure
                            (puVar4,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + -0x40)
                            );
          uVar3 = clk_hw_get_name(param_1);
          if (iVar2 != 0) {
            _printk(&DAT_0011cdb0,uVar3);
            goto LAB_0010c238;
          }
          _printk(&DAT_0011d2bc,uVar3);
        }
        iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),2,2,0,0,
                           0);
        if (iVar2 == 0) {
          DataSynchronizationBarrier(3,3,0);
          __const_udelay(0x10c7);
          iVar2 = regmap_update_bits_base
                            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),4,4,0,
                             0,0);
          if (iVar2 == 0) {
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) +
                         (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
            iVar2 = wait_for_pll(puVar4,0x80000000,0,"enable");
            if (iVar2 == 0) {
              iVar2 = regmap_update_bits_base
                                (*(undefined8 *)(param_1 + 0x18),
                                 *(int *)(param_1 + -0x50) +
                                 (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf,0xf,0,0,0);
              if (iVar2 == 0) {
                iVar2 = regmap_update_bits_base
                                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),
                                   1,1,0,0,0);
                if (iVar2 == 0) {
                  DataSynchronizationBarrier(3,3,0);
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar2 = clk_enable_regmap(param_1);
      if (iVar2 == 0) {
        iVar2 = wait_for_pll(puVar4,0x40000000,0,"enable");
      }
    }
  }
LAB_0010c238:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// clk_regera_pll_disable @ 0010c414 size=268
// signature: undefined clk_regera_pll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_regera_pll_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (iVar2 == 0) {
    if ((local_2c._2_1_ >> 4 & 1) == 0) {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,0,0,0,0)
      ;
      if (iVar2 == 0) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf,0
                   ,0,0,0);
        iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),6,0,0,0,
                           0);
        if (iVar2 == 0) {
          regmap_write(*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0);
        }
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_regera_pll_recalc_rate @ 0010c524 size=236
// signature: undefined clk_regera_pll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

long clk_regera_pll_recalc_rate(long param_1,long param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  long lVar4;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + -0x48);
  local_40 = 0;
  bVar1 = *(byte *)(lVar4 + 4);
  bVar2 = *(byte *)(lVar4 + 3);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x50) + (uint)*(byte *)(lVar4 + 1)
              ,(long)&local_40 + 4);
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),&local_40)
  ;
  lVar3 = sp_el0;
  lVar4 = 0x20;
  if ((uint)bVar1 - (uint)bVar2 != 4) {
    lVar4 = 0x10;
  }
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ((((local_40 & 0xffffffff) * param_2 >> lVar4) + (local_40 >> 0x20) * param_2 + 999) / 1000
         ) * 1000;
}



//------------------------------------------------------------
// clk_regera_pll_set_rate @ 0010c614 size=580
// signature: undefined clk_regera_pll_set_rate(void)
// callers: []
//------------------------------------------------------------

int clk_regera_pll_set_rate(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  ulong uVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  int *piVar11;
  int local_60;
  int iStack_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  piVar11 = (int *)(param_1 + -0x50);
  lVar8 = *(long *)(param_1 + -0x48);
  local_60 = 0;
  iStack_5c = 0;
  bVar2 = *(byte *)(lVar8 + 4);
  bVar3 = *(byte *)(lVar8 + 3);
  iVar5 = regmap_read(*(undefined8 *)(param_1 + 0x18),*piVar11 + (uint)*(byte *)(lVar8 + 1),
                      &iStack_5c);
  if (iVar5 == 0) {
    if (iStack_5c == 0) {
      iVar5 = clk_regera_pll_configure
                        (piVar11,*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + -0x40));
      uVar6 = clk_hw_get_name(param_1);
      if (iVar5 != 0) {
        _printk(&DAT_0011cdb0,uVar6);
        goto LAB_0010c77c;
      }
      _printk(&DAT_0011d2bc,uVar6);
    }
    uVar9 = param_3 & 0xffffffff;
    uVar10 = 0;
    if (uVar9 != 0) {
      uVar10 = param_2 / uVar9;
    }
    lVar8 = param_2 - uVar10 * uVar9;
    iStack_5c = (int)uVar10;
    if (lVar8 == 0) {
      uVar7 = 0;
      uVar10 = param_2;
    }
    else {
      lVar1 = 0x20;
      if ((uint)bVar2 - (uint)bVar3 != 4) {
        lVar1 = 0x10;
      }
      uVar4 = 0;
      if (uVar9 != 0) {
        uVar4 = (ulong)(lVar8 << lVar1) / uVar9;
      }
      uVar7 = (uint)uVar4;
      uVar10 = ((((uVar4 & 0xffffffff) * param_3 >> lVar1) + (uVar10 & 0xffffffff) * param_3 + 999)
               / 1000) * 1000;
    }
    if ((param_2 + 500 < uVar10) || (uVar10 < param_2)) {
      _printk(&DAT_0011cc60);
      iVar5 = -0x16;
    }
    else {
      if (((uVar7 >> 0xf & 1) != 0) && (param_3 <= (ulong)(lVar8 * 2))) {
        iStack_5c = iStack_5c + 1;
      }
      regmap_write(*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3));
      regmap_write(*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                   iStack_5c);
      iVar5 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                          *(int *)(param_1 + -0x50) +
                          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_60);
      if (iVar5 == 0) {
        if (local_60 == 0) {
          iVar5 = 0;
        }
        else {
          __const_udelay(0x53e3);
          iVar5 = wait_for_pll(piVar11,0x80000000,0,"enable");
          if (iVar5 == 0) {
            __const_udelay(0x68dbc);
          }
        }
      }
    }
  }
LAB_0010c77c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// clk_regera_pll_init @ 0010c85c size=36
// signature: undefined clk_regera_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_regera_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_regera_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_lucid_evo_pll_configure @ 0010c884 size=1040
// signature: undefined clk_lucid_evo_pll_configure(void)
// callers: [clk_pll_restore_context, _alpha_pll_lucid_evo_prepare]
//------------------------------------------------------------

void clk_lucid_evo_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_54 = 0;
  uVar8 = regmap_update_bits_base
                    (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5),7,7,0,0,0);
  if ((int)uVar8 != 0) goto LAB_0010cc60;
  local_4c = 0;
  local_50 = 0;
  iVar2 = regmap_read(param_2,*param_1,&local_4c);
  iVar3 = regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),&local_50);
  if (((iVar3 == 0 && iVar2 == 0) && ((local_50 & 1) != 0)) && ((local_4c & 1) != 0)) {
    uVar8 = 1;
    goto LAB_0010cc60;
  }
  regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1),&local_54);
  local_54 = local_54 & 0xffff;
  if (local_54 != 0) {
    uVar8 = 0;
    goto LAB_0010cc60;
  }
  if (*param_3 == 0) {
    uVar4 = 0;
    uVar5 = 0;
    if (param_3[2] == 0) goto LAB_0010ca28;
LAB_0010c9b0:
    uVar5 = regmap_update_bits_base
                      (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1),0xff0000,
                       param_3[1] << 0x10,0,0,0);
    uVar6 = regmap_update_bits_base
                      (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1),0xff000000,
                       param_3[2] << 0x18,0,0,0);
    uVar5 = uVar5 | uVar6;
  }
  else {
    uVar4 = regmap_update_bits_base
                      (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1),0xffff,
                       *param_3,0,0,0);
    uVar5 = uVar4;
    if (param_3[2] != 0) goto LAB_0010c9b0;
LAB_0010ca28:
    uVar4 = uVar5;
    if (param_3[1] == 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 2),0x440000);
    }
    else {
      uVar5 = regmap_update_bits_base
                        (param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1),0xffff0000,
                         param_3[1] << 0x10,0,0,0);
    }
  }
  uVar5 = uVar5 | uVar4;
  if (param_3[3] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[5] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[6] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[7] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[9] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5),
                         param_3[9] | 7);
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[10] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[0xc] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[0xd] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[0xe] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
    uVar5 = uVar4 | uVar5;
  }
  if (param_3[0xf] != 0) {
    uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xf));
    uVar5 = uVar4 | uVar5;
  }
  iVar2 = regmap_update_bits_base(param_2,*param_1,1,0,0,0,0);
  iVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
  DataSynchronizationBarrier(3,2,0);
  iVar7 = regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
  uVar4 = 0;
  if ((iVar2 != 0 || iVar7 != 0) || (uVar5 != 0 || iVar3 != 0)) {
    uVar4 = 0xfffffffb;
  }
  uVar8 = (ulong)uVar4;
LAB_0010cc60:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_enable @ 0010cc98 size=44
// signature: undefined alpha_pll_lucid_evo_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 alpha_pll_lucid_evo_enable(long param_1)

{
  undefined8 uVar1;
  
  if ((*(byte *)(param_1 + -8) >> 6 & 1) == 0) {
    uVar1 = _alpha_pll_lucid_evo_enable();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_disable @ 0010ccc8 size=40
// signature: undefined alpha_pll_lucid_evo_disable(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_evo_disable(long param_1)

{
  if ((*(byte *)(param_1 + -8) >> 6 & 1) == 0) {
    _alpha_pll_lucid_evo_disable(param_1,0);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_recalc_rate @ 0010ccf4 size=268
// signature: undefined alpha_pll_lucid_evo_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_evo_recalc_rate(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  iVar2 = regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                            (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),(long)&local_40 + 4);
  if (iVar2 == 0) {
    local_40 = local_40 & 0xffffffffffff;
    iVar2 = regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                              (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),&local_40);
    if (iVar2 == 0) {
      lVar3 = 0x20;
      if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
        lVar3 = 0x10;
      }
      lVar3 = ((((local_40 & 0xffffffff) * param_2 >> lVar3) + (local_40 >> 0x20) * param_2 + 999) /
              1000) * 1000;
      goto LAB_0010cd74;
    }
  }
  lVar3 = 0;
LAB_0010cd74:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_lucid_evo_pll_init @ 0010ce04 size=36
// signature: undefined clk_lucid_evo_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_lucid_evo_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_lucid_evo_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_lucid_evo_pll_postdiv_set_rate @ 0010ce2c size=32
// signature: undefined clk_lucid_evo_pll_postdiv_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_lucid_evo_pll_postdiv_set_rate(void)

{
  __clk_lucid_pll_postdiv_set_rate();
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_prepare @ 0010ce50 size=32
// signature: undefined alpha_pll_lucid_evo_prepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_evo_prepare(undefined8 param_1)

{
  _alpha_pll_lucid_evo_prepare(param_1,0);
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_unprepare @ 0010ce74 size=64
// signature: undefined alpha_pll_lucid_evo_unprepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_evo_unprepare(long param_1)

{
  if ((*(byte *)(param_1 + -8) >> 6 & 1) != 0) {
    _alpha_pll_lucid_evo_disable(param_1,0);
  }
  clk_unprepare_regmap(param_1);
  return;
}



//------------------------------------------------------------
// alpha_pll_lucid_evo_set_rate @ 0010ceb8 size=528
// signature: undefined alpha_pll_lucid_evo_set_rate(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_lucid_evo_set_rate(long param_1,ulong param_2,ulong param_3)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  undefined4 local_2c;
  long local_28;
  
  uVar4 = param_3 & 0xffffffff;
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  uVar2 = 0;
  if (uVar4 != 0) {
    uVar2 = param_2 / uVar4;
  }
  local_2c = 0;
  lVar5 = param_2 - uVar2 * uVar4;
  if (lVar5 == 0) {
    uVar6 = 0;
    uVar4 = param_2;
  }
  else {
    uVar6 = 0;
    if (uVar4 != 0) {
      uVar6 = (ulong)(lVar5 * 0x10000) / uVar4;
    }
    uVar4 = (((uVar2 & 0xffffffff) * param_3 + ((uVar6 & 0xffffffff) * param_3 >> 0x10) + 999) /
            1000) * 1000;
  }
  if ((param_2 + 500 < uVar4) || (uVar4 < param_2)) {
    _printk(&DAT_0011cc60);
    uVar3 = 0xffffffea;
    goto LAB_0010d09c;
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),
             *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),0xffff,
             uVar2,0,0,0);
  regmap_write(*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
               uVar6 & 0xffffffff);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
  if (((byte)local_2c >> 2 & 1) != 0) {
    uVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),0x4000,
                       0x4000,0,0,0);
    if ((int)uVar3 != 0) goto LAB_0010d09c;
    __const_udelay(0x10c7);
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_2c);
    if ((local_2c._1_1_ >> 5 & 1) == 0) {
      clk_debug_print_hw(param_1,0);
      if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
        uVar3 = clk_hw_get_name(param_1);
      }
      else {
        uVar3 = **(undefined8 **)(param_1 + 0x10);
      }
      __warn_printk("%s: PLL latch failed. Output may be unstable!\n",uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10d09c);
      (*pcVar1)();
    }
    uVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),0x4000,0,0,0
                       ,0);
    if ((int)uVar3 != 0) goto LAB_0010d09c;
  }
  uVar2 = clk_hw_is_enabled(param_1);
  if (((uVar2 & 1) == 0) ||
     (uVar3 = wait_for_pll(param_1 + -0x50,0x80000000,0,"enable"), (int)uVar3 == 0)) {
    uVar3 = 0;
  }
LAB_0010d09c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// alpha_pll_reset_lucid_evo_prepare @ 0010d0cc size=32
// signature: undefined alpha_pll_reset_lucid_evo_prepare(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_reset_lucid_evo_prepare(undefined8 param_1)

{
  _alpha_pll_lucid_evo_prepare(param_1,1);
  return;
}



//------------------------------------------------------------
// alpha_pll_reset_lucid_evo_disable @ 0010d0f0 size=32
// signature: undefined alpha_pll_reset_lucid_evo_disable(void)
// callers: []
//------------------------------------------------------------

void alpha_pll_reset_lucid_evo_disable(undefined8 param_1)

{
  _alpha_pll_lucid_evo_disable(param_1,1);
  return;
}



//------------------------------------------------------------
// lucid_evo_calc_pll @ 0010d114 size=112
// signature: undefined lucid_evo_calc_pll(void)
// callers: []
//------------------------------------------------------------

long lucid_evo_calc_pll(undefined8 param_1,uint param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  
  lVar1 = clk_hw_get_parent();
  lVar2 = 0;
  if (lVar1 != 0) {
    lVar2 = clk_hw_get_rate();
    lVar2 = ((lVar2 * (ulong)param_2 + (lVar2 * (param_3 & 0xffffffff) >> 0x10) + 999) / 1000) *
            1000;
  }
  return lVar2;
}



//------------------------------------------------------------
// lucid_evo_calc_pll_out @ 0010d188 size=332
// signature: undefined lucid_evo_calc_pll_out(void)
// callers: []
//------------------------------------------------------------

void lucid_evo_calc_pll_out(long param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = clk_hw_get_parent();
  uVar3 = 0;
  if (lVar2 != 0) {
    lVar2 = clk_hw_get_parent();
    if (lVar2 == 0) {
      uVar5 = 0;
    }
    else {
      lVar2 = clk_hw_get_rate();
      uVar5 = ((lVar2 * (param_2 & 0xffffffff) + (lVar2 * (param_3 & 0xffffffff) >> 0x10) + 999) /
              1000) * 1000;
    }
    local_3c = 0;
    iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                        *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                        &local_3c);
    if (iVar1 == 0) {
      local_3c = local_3c >> (ulong)(*(uint *)(param_1 + 0x90) & 0x1f) &
                 ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0xc) & 0x3f)) ^ 0xffffffff);
      if (*(ulong *)(param_1 + 0xa0) == 0) {
        uVar4 = 1;
      }
      else {
        uVar3 = 0;
        uVar4 = 1;
        do {
          if (*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8) == local_3c) {
            uVar4 = (ulong)*(uint *)(*(long *)(param_1 + 0x98) + uVar3 * 8 + 4);
            break;
          }
          uVar3 = (ulong)((int)uVar3 + 1);
        } while (uVar3 < *(ulong *)(param_1 + 0xa0));
      }
      uVar3 = 0;
      if (uVar4 != 0) {
        uVar3 = uVar5 / uVar4;
      }
    }
    else {
      uVar3 = (ulong)iVar1;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_lucid_evo_pll_crm_init @ 0010d2d8 size=36
// signature: undefined clk_lucid_evo_pll_crm_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_lucid_evo_pll_crm_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_lucid_evo_pll_crm_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_lucid_evo_pll_crm_postdiv_init @ 0010d300 size=36
// signature: undefined clk_lucid_evo_pll_crm_postdiv_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_lucid_evo_pll_crm_postdiv_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined1 **)(param_1 + 0x58) = clk_lucid_evo_pll_crm_postdiv_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_zonda_evo_pll_configure @ 0010d328 size=736
// signature: undefined clk_zonda_evo_pll_configure(void)
// callers: []
//------------------------------------------------------------

uint clk_zonda_evo_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  uVar2 = regmap_read(param_2,*param_1,(long)&local_40 + 4);
  uVar3 = regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),&local_40);
  uVar3 = uVar3 | uVar2;
  if (uVar3 == 0) {
    if (((local_40 & 1) == 0) || ((local_40 & 0x100000000) == 0)) {
      if (*param_3 == 0) {
        uVar2 = 0;
        iVar4 = param_3[3];
      }
      else {
        uVar2 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
        iVar4 = param_3[3];
      }
      if (iVar4 != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 3));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[5] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[6] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[7] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[9] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[10] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[0xc] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[0xd] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
        uVar2 = uVar3 | uVar2;
      }
      if (param_3[0xe] != 0) {
        uVar3 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xe));
        uVar2 = uVar3 | uVar2;
      }
      iVar4 = regmap_update_bits_base(param_2,*param_1,2,0,0,0,0);
      iVar5 = regmap_update_bits_base(param_2,*param_1,1,0,0,0,0);
      iVar6 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
      DataSynchronizationBarrier(3,2,0);
      iVar7 = regmap_update_bits_base(param_2,*param_1,4,4,0,0,0);
      uVar3 = 0;
      if ((((iVar4 != 0 || uVar2 != 0) || iVar5 != 0) || iVar7 != 0) || iVar6 != 0) {
        uVar3 = 0xfffffffb;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    _printk(&DAT_0011caf5);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_zonda_evo_pll_enable @ 0010d60c size=460
// signature: undefined clk_zonda_evo_pll_enable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_evo_pll_enable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  int *piVar5;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  piVar5 = (int *)(param_1 + -0x50);
  local_30 = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *piVar5 + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),(long)&local_30 + 4)
  ;
  if (iVar2 == 0) {
    if ((local_30._7_1_ >> 1 & 1) == 0) {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),2,2,0,0,0)
      ;
      if (iVar2 == 0) {
        DataSynchronizationBarrier(3,3,0);
        __const_udelay(0x10c7);
        iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),4,4,0,0,
                           0);
        if (iVar2 == 0) {
          regmap_write(*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
          iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                              *(int *)(param_1 + -0x50) +
                              (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0xc),&local_30);
          if (iVar2 == 0) {
            if ((local_30 & 0x10000) == 0) {
              pcVar4 = "enable";
              uVar3 = 0x80000000;
            }
            else {
              pcVar4 = "freq enable";
              uVar3 = 0x20000000;
            }
            iVar2 = wait_for_pll(piVar5,uVar3,0,pcVar4);
            if (((iVar2 == 0) &&
                (iVar2 = regmap_update_bits_base
                                   (*(undefined8 *)(param_1 + 0x18),
                                    *(int *)(param_1 + -0x50) +
                                    (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf,0xf,0,0,0),
                iVar2 == 0)) &&
               (iVar2 = regmap_update_bits_base
                                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),
                                   1,1,0,0,0), iVar2 == 0)) {
              DataSynchronizationBarrier(3,3,0);
            }
          }
        }
      }
    }
    else {
      iVar2 = clk_enable_regmap(param_1);
      if (iVar2 == 0) {
        wait_for_pll(piVar5,0x40000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_zonda_evo_pll_disable @ 0010d7dc size=280
// signature: undefined clk_zonda_evo_pll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_evo_pll_disable(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                      &local_2c);
  if (iVar2 == 0) {
    if ((local_2c._3_1_ >> 1 & 1) == 0) {
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),1,0,0,0,0)
      ;
      if (iVar2 == 0) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),
                   *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),0xf,0
                   ,0,0,0);
        iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),6,0,0,0,
                           0);
        if (iVar2 == 0) {
          regmap_write(*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) +
                       (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0);
        }
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_zonda_pll_is_enabled @ 0010d8f8 size=188
// signature: undefined clk_zonda_pll_is_enabled(void)
// callers: []
//------------------------------------------------------------

uint clk_zonda_pll_is_enabled(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  local_40 = 0;
  uVar2 = regmap_read(uVar4,*(undefined4 *)(param_1 + -0x50),(long)&local_40 + 4);
  uVar3 = regmap_read(uVar4,*(int *)(param_1 + -0x50) +
                            (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
  uVar3 = uVar3 | uVar2;
  if (uVar3 == 0) {
    uVar3 = ((byte)local_40 & local_40._4_1_) & 1;
  }
  else {
    _printk(&DAT_0011caf5);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_zonda_pll_recalc_rate @ 0010d9b8 size=320
// signature: undefined clk_zonda_pll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_zonda_pll_recalc_rate(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
              (long)&local_30 + 4);
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),&local_30)
  ;
  iVar2 = (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
          (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3);
  if (((uint)local_30 >> 0xf & 1) == 0) {
    lVar4 = 0x20;
    if (iVar2 != 4) {
      lVar4 = 0x10;
    }
    lVar4 = ((((local_30 & 0xffffffff) * param_2 >> lVar4) + (local_30 >> 0x20) * param_2 + 999) /
            1000) * 1000;
  }
  else {
    uVar1 = 0x10000000000;
    if (iVar2 != 4) {
      uVar1 = 0x10000;
    }
    iVar2 = 0;
    if ((uVar1 & 0x10000) != 0) {
      iVar2 = (int)((((uint)local_30 * 100 + uVar1) - 1) / (uVar1 & 0x10000));
    }
    lVar4 = (local_30 >> 0x20) * param_2 - ((ulong)(100 - iVar2) * param_2) / 100;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_zonda_evo_init @ 0010dafc size=36
// signature: undefined clk_alpha_pll_zonda_evo_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_zonda_evo_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_alpha_pll_zonda_evo_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_rivian_evo_pll_configure @ 0010db24 size=604
// signature: undefined clk_rivian_evo_pll_configure(void)
// callers: [clk_pll_restore_context]
//------------------------------------------------------------

void clk_rivian_evo_pll_configure(int *param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = regmap_read(param_2,*param_1,(long)&local_40 + 4);
  iVar3 = regmap_read(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),&local_40);
  if (((iVar3 == 0 && iVar2 == 0) && ((local_40 & 1) != 0)) && ((local_40 & 0x100000000) != 0)) {
    uVar6 = 1;
  }
  else {
    if (param_3[5] == 0) {
      uVar4 = 0;
      iVar2 = param_3[6];
    }
    else {
      uVar4 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 8));
      iVar2 = param_3[6];
    }
    if (iVar2 != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 9));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[7] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 10));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[8] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xb));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[0xc] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xc));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[0xd] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0xd));
      uVar4 = uVar5 | uVar4;
    }
    if (*param_3 != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 1));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[9] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 5));
      uVar4 = uVar5 | uVar4;
    }
    if (param_3[10] != 0) {
      uVar5 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 6));
      uVar4 = uVar5 | uVar4;
    }
    iVar2 = regmap_write(param_2,*param_1 + (uint)*(byte *)(*(long *)(param_1 + 2) + 0x12),0);
    iVar3 = regmap_update_bits_base(param_2,*param_1,6,6,0,0,0);
    uVar6 = 0;
    if (iVar2 != 0 || (uVar4 != 0 || iVar3 != 0)) {
      uVar6 = 0xfffffffb;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// clk_rivian_evo_pll_recalc_rate @ 0010dd84 size=128
// signature: undefined clk_rivian_evo_pll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rivian_evo_pll_recalc_rate(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                      &local_2c);
  lVar1 = sp_el0;
  param_2 = (ulong)local_2c * param_2;
  if (iVar2 != 0) {
    param_2 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2);
  }
  return;
}



//------------------------------------------------------------
// clk_rivian_evo_pll_round_rate @ 0010de08 size=192
// signature: undefined clk_rivian_evo_pll_round_rate(void)
// callers: []
//------------------------------------------------------------

ulong clk_rivian_evo_pll_round_rate(long param_1,ulong param_2,ulong *param_3)

{
  ulong uVar1;
  ulong *puVar2;
  ulong uVar3;
  ulong *puVar4;
  
  uVar3 = *param_3 & 0xffffffff;
  uVar1 = 0;
  if (uVar3 != 0) {
    uVar1 = param_2 / uVar3;
  }
  if (param_2 != uVar1 * uVar3) {
    param_2 = (((uVar1 & 0xffffffff) * *param_3 + 999) / 1000) * 1000;
  }
  puVar2 = *(ulong **)(param_1 + -0x38);
  if (puVar2 == (ulong *)0x0) {
    return param_2;
  }
  if (puVar2 < puVar2 + *(long *)(param_1 + -0x30) * 3) {
    puVar4 = puVar2;
    do {
      if ((*puVar4 <= param_2) && (param_2 <= puVar4[1])) {
        if (puVar4 != (ulong *)0x0) {
          return param_2;
        }
        break;
      }
      puVar4 = puVar4 + 3;
    } while (puVar4 < puVar2 + *(long *)(param_1 + -0x30) * 3);
  }
  uVar1 = param_2;
  if (param_2 <= *puVar2) {
    uVar1 = *puVar2;
  }
  if (puVar2[*(long *)(param_1 + -0x30) * 3 + -2] <= param_2) {
    uVar1 = puVar2[*(long *)(param_1 + -0x30) * 3 + -2];
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_rivian_evo_pll_init @ 0010decc size=36
// signature: undefined clk_rivian_evo_pll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rivian_evo_pll_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_rivian_evo_pll_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_alpha_pll_slew_enable @ 0010def4 size=812
// signature: undefined clk_alpha_pll_slew_enable(void)
// callers: []
//------------------------------------------------------------

int clk_alpha_pll_slew_enable(long param_1)

{
  ulong *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong uVar13;
  
  uVar7 = 0x28;
  if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
      (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
    uVar7 = 0x10;
  }
  lVar3 = clk_hw_get_parent();
  if (lVar3 == 0) {
    puVar6 = &DAT_0011cfdc;
  }
  else {
    uVar4 = clk_hw_get_rate(param_1);
    puVar1 = *(ulong **)(param_1 + -0x38);
    if (puVar1 < puVar1 + *(long *)(param_1 + -0x30) * 3) {
      puVar11 = puVar1;
      do {
        if ((*puVar11 <= uVar4) && (uVar4 <= puVar11[1])) {
          if (puVar11 != (ulong *)0x0) {
            uVar13 = puVar1[1] + *puVar1 >> 1;
            uVar5 = clk_hw_get_rate(lVar3);
            uVar8 = uVar5 & 0xffffffff;
            uVar4 = 0;
            if (uVar8 != 0) {
              uVar4 = uVar13 / uVar8;
            }
            lVar9 = uVar13 - uVar4 * uVar8;
            if (lVar9 == 0) {
              uVar12 = 0;
            }
            else {
              uVar10 = uVar7;
              if (0x1f < uVar7) {
                uVar10 = 0x20;
              }
              uVar12 = 0;
              if (uVar8 != 0) {
                uVar12 = (ulong)(lVar9 << uVar10) / uVar8;
              }
              if (((((uVar12 & 0xffffffff) * uVar5 >> uVar10) + (uVar4 & 0xffffffff) * uVar5 + 999)
                  / 1000) * 1000 != uVar13) {
                puVar6 = &DAT_0011c8ea;
                goto LAB_0010e1e4;
              }
            }
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1)
                        );
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3)
                         ,(int)uVar12 << 8);
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4)
                         ,uVar12 >> 0x18);
            regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                       0x300000,(int)puVar11[2] << 0x14,0,0,0);
            regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                       0x1000000,0x1000000,0,0,0);
            iVar2 = clk_alpha_pll_enable(param_1);
            if (iVar2 != 0) {
              _printk(&DAT_0011d9eb);
              return iVar2;
            }
            uVar5 = clk_hw_get_rate(param_1);
            uVar8 = clk_hw_get_rate(lVar3);
            uVar8 = uVar8 & 0xffffffff;
            uVar4 = 0;
            if (uVar8 != 0) {
              uVar4 = uVar5 / uVar8;
            }
            lVar3 = uVar5 - uVar4 * uVar8;
            if (lVar3 == 0) {
              uVar4 = 0;
            }
            else {
              if (0x1f < uVar7) {
                uVar7 = 0x20;
              }
              uVar4 = 0;
              if (uVar8 != 0) {
                uVar4 = (ulong)(lVar3 << uVar7) / uVar8;
              }
              uVar4 = uVar4 << 8;
            }
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1)
                        );
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3)
                         ,uVar4 & 0xffffffff);
            regmap_write(*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4)
                         ,uVar4 >> 0x20);
            regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),
                       0x1000000,0x1000000,0,0,0);
            if ((*(byte *)(param_1 + -8) >> 3 & 1) == 0) {
              iVar2 = clk_alpha_pll_slew_update(param_1 + -0x50);
            }
            else {
              iVar2 = clk_alpha_pll_dynamic_update(param_1 + -0x50);
            }
            if (iVar2 == 0) {
              iVar2 = clk_alpha_pll_enable(param_1);
              return iVar2;
            }
            return iVar2;
          }
          break;
        }
        puVar11 = puVar11 + 3;
      } while (puVar11 < puVar1 + *(long *)(param_1 + -0x30) * 3);
    }
    puVar6 = &DAT_0011d000;
  }
LAB_0010e1e4:
  _printk(puVar6);
  return -0x16;
}



//------------------------------------------------------------
// clk_alpha_pll_slew_set_rate @ 0010e224 size=512
// signature: undefined clk_alpha_pll_slew_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_alpha_pll_slew_set_rate(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  undefined *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong *puVar6;
  long lVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  
  uVar5 = param_3 & 0xffffffff;
  uVar3 = 0;
  if (uVar5 != 0) {
    uVar3 = param_2 / uVar5;
  }
  lVar7 = param_2 - uVar3 * uVar5;
  if (lVar7 == 0) {
    uVar10 = 0;
  }
  else {
    lVar1 = 0x20;
    if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
      lVar1 = 0x10;
    }
    uVar10 = 0;
    if (uVar5 != 0) {
      uVar10 = (ulong)(lVar7 << lVar1) / uVar5;
    }
    if (((((uVar10 & 0xffffffff) * param_3 >> lVar1) + (uVar3 & 0xffffffff) * param_3 + 999) / 1000)
        * 1000 != param_2) {
      puVar2 = &DAT_0011dbc4;
      goto LAB_0010e3e0;
    }
  }
  uVar5 = clk_hw_get_rate(param_1);
  puVar6 = *(ulong **)(param_1 + -0x38);
  puVar8 = puVar6 + *(long *)(param_1 + -0x30) * 3;
  if (puVar6 < puVar8) {
    puVar9 = puVar6;
    do {
      if ((*puVar9 <= uVar5) && (uVar5 <= puVar9[1])) {
        if (puVar9 != (ulong *)0x0) goto LAB_0010e334;
        break;
      }
      puVar9 = puVar9 + 3;
    } while (puVar9 < puVar8);
  }
  goto LAB_0010e3d8;
  while (puVar6 = puVar6 + 3, puVar6 < puVar8) {
LAB_0010e334:
    if ((*puVar6 <= param_2) && (param_2 <= puVar6[1])) {
      if (puVar6 != (ulong *)0x0) {
        if ((int)puVar9[2] != (int)puVar6[2]) {
          uVar4 = clk_alpha_pll_set_rate(param_1,param_2,param_3);
          return uVar4;
        }
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                     uVar3 & 0xffffffff);
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
                     (int)uVar10 << 8);
        regmap_write(*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 4),
                     uVar10 >> 0x18);
        DataSynchronizationBarrier(3,3,0);
        uVar3 = clk_hw_is_enabled(param_1);
        if ((uVar3 & 1) != 0) {
          if ((*(byte *)(param_1 + -8) >> 3 & 1) == 0) {
            clk_alpha_pll_slew_update(param_1 + -0x50);
          }
          else {
            clk_alpha_pll_dynamic_update(param_1 + -0x50);
          }
        }
        return 0;
      }
      break;
    }
  }
LAB_0010e3d8:
  puVar2 = &DAT_0011d000;
LAB_0010e3e0:
  _printk(puVar2);
  return 0xffffffea;
}



//------------------------------------------------------------
// wait_for_pll @ 0010e424 size=308
// signature: undefined wait_for_pll(void)
// callers: [alpha_pll_huayra_set_rate, _alpha_pll_lucid_evo_enable, clk_regera_pll_set_rate, clk_trion_pll_enable, clk_alpha_pll_slew_update, clk_alpha_pll_hwfsm_enable, clk_alpha_pll_hwfsm_disable, clk_alpha_pll_dynamic_update, alpha_pll_fabia_enable, alpha_pll_lucid_5lpe_enable, clk_alpha_pll_enable, __alpha_pll_trion_set_rate, clk_alpha_pll_agera_set_rate, clk_zonda_pll_enable, clk_zonda_5lpe_pll_enable, alpha_pll_lucid_evo_set_rate, __clk_alpha_pll_update_latch, clk_zonda_pll_set_rate, clk_zonda_evo_pll_enable, clk_regera_pll_enable]
//------------------------------------------------------------

void wait_for_pll(undefined4 *param_1,uint param_2,byte param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_5c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x1a),*param_1,&local_5c);
  if (iVar2 == 0) {
    uVar6 = 0xc9;
    lVar3 = sched_clock();
    while (iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x1a),*param_1,&local_5c), iVar2 == 0) {
      if (((param_3 & (local_5c & param_2) == 0) != 0) || ((local_5c & param_2) == param_2)) break;
      __const_udelay(0x10c7);
      uVar6 = uVar6 - 1;
      if (uVar6 < 2) {
        lVar4 = sched_clock();
        _printk(&DAT_0011db84,lVar4 - lVar3);
        clk_debug_print_hw(param_1 + 0x14,0);
        if (*(undefined8 **)(param_1 + 0x18) == (undefined8 *)0x0) {
          uVar5 = clk_hw_get_name(param_1 + 0x14);
        }
        else {
          uVar5 = **(undefined8 **)(param_1 + 0x18);
        }
        __warn_printk("%s: pll failed to %s!\n",uVar5,param_4);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10e554);
        (*pcVar1)();
      }
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_list_registers @ 0010e560 size=348
// signature: undefined clk_alpha_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_001204b8 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_alpha_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xa0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_dynamic_update @ 0010e6bc size=160
// signature: undefined clk_alpha_pll_dynamic_update(void)
// callers: [clk_alpha_pll_set_rate, clk_alpha_pll_hwfsm_set_rate, clk_alpha_pll_slew_set_rate, clk_alpha_pll_slew_enable]
//------------------------------------------------------------

void clk_alpha_pll_dynamic_update(undefined4 *param_1)

{
  int iVar1;
  
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x1a),*param_1,0x400000,0x400000,0,0,0);
  __const_udelay(0x10c7);
  iVar1 = wait_for_pll(param_1,0x20000000,0,"update_ack_set");
  if (iVar1 == 0) {
    regmap_update_bits_base(*(undefined8 *)(param_1 + 0x1a),*param_1,0x400000,0xffbfffff,0,0,0);
    wait_for_pll(param_1,0x80000000,0,"enable");
  }
  return;
}



//------------------------------------------------------------
// __clk_alpha_pll_update_latch @ 0010e75c size=324
// signature: undefined __clk_alpha_pll_update_latch(void)
// callers: [clk_alpha_pll_set_rate, clk_alpha_pll_hwfsm_set_rate, alpha_pll_fabia_set_rate]
//------------------------------------------------------------

void __clk_alpha_pll_update_latch(undefined4 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x1a),*param_1,&local_2c);
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x1a),*param_1,0x400000,0x400000,0,0,0);
  __const_udelay(0x10c7);
  if (local_2c._2_1_ < '\0') {
    uVar3 = wait_for_pll(param_1,0x20000000,0,"update_ack_set");
    if ((int)uVar3 != 0) goto LAB_0010e874;
    regmap_update_bits_base(*(undefined8 *)(param_1 + 0x1a),*param_1,0x400000,0,0,0,0);
    if ((*(byte *)(param_1 + 0x12) >> 3 & 1) != 0) goto LAB_0010e84c;
LAB_0010e7e8:
    uVar3 = wait_for_pll(param_1,0x20000000,1,"update_ack_clear");
    iVar2 = (int)uVar3;
  }
  else {
    uVar3 = wait_for_pll(param_1,0x400000,1,"update");
    if ((int)uVar3 != 0) goto LAB_0010e874;
    if ((*(byte *)(param_1 + 0x12) >> 3 & 1) == 0) goto LAB_0010e7e8;
LAB_0010e84c:
    uVar3 = wait_for_pll(param_1,0x80000000,0,"enable");
    iVar2 = (int)uVar3;
  }
  if (iVar2 == 0) {
    __const_udelay(0xa7c6);
    uVar3 = 0;
  }
LAB_0010e874:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_huayra_list_registers @ 0010e8a4 size=348
// signature: undefined clk_alpha_pll_huayra_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_huayra_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) +
                               (ulong)*(uint *)((long)&DAT_001209e8 + lVar2)),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_regera_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xc0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_trion_pll_list_registers @ 0010ea04 size=348
// signature: undefined clk_trion_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_trion_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120558 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_trion_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xf0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_fabia_pll_list_registers @ 0010eb64 size=348
// signature: undefined clk_fabia_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_fabia_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120698 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_fabia_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xc0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __alpha_pll_trion_set_rate @ 0010ecc0 size=764
// signature: undefined __alpha_pll_trion_set_rate(void)
// callers: [alpha_pll_trion_set_rate, alpha_pll_lucid_5lpe_set_rate]
//------------------------------------------------------------

int __alpha_pll_trion_set_rate
              (long param_1,ulong param_2,ulong param_3,undefined4 param_4,uint param_5)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  uint local_5c;
  long local_58;
  
  uVar7 = param_3 & 0xffffffff;
  lVar8 = sp_el0;
  uVar5 = 0;
  if (uVar7 != 0) {
    uVar5 = param_2 / uVar7;
  }
  local_58 = *(long *)(lVar8 + 0x638);
  local_5c = 0;
  lVar8 = param_2 - uVar5 * uVar7;
  if (lVar8 == 0) {
    uVar9 = 0;
    uVar7 = param_2;
  }
  else {
    lVar1 = 0x20;
    if ((uint)*(byte *)(*(long *)(param_1 + -0x48) + 4) -
        (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3) != 4) {
      lVar1 = 0x10;
    }
    uVar9 = 0;
    if (uVar7 != 0) {
      uVar9 = (ulong)(lVar8 << lVar1) / uVar7;
    }
    uVar7 = ((((uVar9 & 0xffffffff) * param_3 >> lVar1) + (uVar5 & 0xffffffff) * param_3 + 999) /
            1000) * 1000;
  }
  if ((uVar7 < param_2) || (param_2 + 500 < uVar7)) {
    uVar6 = clk_hw_get_name(param_1);
    _printk(&DAT_0011d689,uVar6,uVar7,param_2,param_2 + 500);
    iVar3 = -0x16;
    goto LAB_0010eec8;
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),
             *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),0xffff,
             uVar5,0,0,0);
  regmap_write(*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 3),
               uVar9 & 0xffffffff);
  if ((*(byte *)(param_1 + -8) >> 6 & 1) == 0) {
    iVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x50),param_4,param_4,0,0
                       ,0);
    if (iVar3 != 0) goto LAB_0010eec8;
    __const_udelay(0x10c7);
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_5c);
    if ((local_5c >> 0x17 & 1) == 0) {
      iVar4 = wait_for_pll(param_1 + -0x50,0x400000,1,"update");
      iVar3 = 0;
      if (iVar4 != 0) {
        clk_debug_print_hw(param_1,0);
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar6 = clk_hw_get_name(param_1);
        }
        else {
          uVar6 = **(undefined8 **)(param_1 + 0x10);
        }
        __warn_printk("%s: PLL Update clear failed\n",uVar6);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10ef98);
        (*pcVar2)();
      }
      goto LAB_0010eec8;
    }
    if ((local_5c & param_5) == 0) {
      clk_debug_print_hw(param_1,0);
      if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
        uVar6 = clk_hw_get_name(param_1);
      }
      else {
        uVar6 = **(undefined8 **)(param_1 + 0x10);
      }
      __warn_printk("%s: Lucid PLL latch failed. Output may be unstable!\n",uVar6);
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10efbc);
      (*pcVar2)();
    }
    iVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),param_4,0,0,
                       0,0);
    if (iVar3 != 0) goto LAB_0010eec8;
  }
  else {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),
               *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 6),0x400,
               0x400,0,0,0);
  }
  uVar5 = clk_hw_is_enabled(param_1);
  if ((uVar5 & 1) != 0) {
    iVar3 = wait_for_pll(param_1 + -0x50,0x80000000,0,"enable");
    if (iVar3 != 0) goto LAB_0010eec8;
  }
  __const_udelay(0x68dbc);
  iVar3 = 0;
LAB_0010eec8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// lucid_pll_list_registers @ 0010efc8 size=348
// signature: undefined lucid_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void lucid_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120758 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&lucid_pll_list_registers_data + lVar2),local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0x120);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_agera_pll_list_registers @ 0010f128 size=348
// signature: undefined clk_agera_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_agera_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120878 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_agera_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0x90);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __clk_lucid_pll_postdiv_set_rate @ 0010f284 size=344
// signature: undefined __clk_lucid_pll_postdiv_set_rate(void)
// callers: [clk_lucid_evo_pll_postdiv_set_rate, clk_lucid_5lpe_pll_postdiv_set_rate]
//------------------------------------------------------------

void __clk_lucid_pll_postdiv_set_rate(long param_1,ulong param_2,long param_3,ulong param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                      &local_3c);
  if ((int)uVar3 == 0) {
    if (((long)local_3c & param_4) == 0) {
      lVar4 = *(long *)(param_1 + 0x98);
      if (lVar4 == 0) {
        uVar3 = clk_hw_get_name(param_1);
        _printk(&DAT_0011d28f,uVar3);
        uVar3 = 0xffffffea;
      }
      else {
        if (*(ulong *)(param_1 + 0xa0) != 0) {
          iVar2 = 0;
          if ((param_2 & 0xffffffff) != 0) {
            iVar2 = (int)(((param_2 + param_3) - 1) / (param_2 & 0xffffffff));
          }
          uVar5 = 0;
          do {
            if (*(int *)(lVar4 + uVar5 * 8 + 4) == iVar2) {
              local_3c = *(int *)(lVar4 + uVar5 * 8);
              break;
            }
            uVar5 = (ulong)((int)uVar5 + 1);
          } while (uVar5 < *(ulong *)(param_1 + 0xa0));
        }
        uVar1 = *(uint *)(param_1 + 0x90);
        uVar3 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),
                           *(int *)(param_1 + -0x10) + (uint)*(byte *)(*(long *)(param_1 + -8) + 5),
                           (uint)(0xffffffffffffffff >>
                                 ((ulong)-(uVar1 + *(byte *)(param_1 + -0xc)) & 0x3f)) &
                           (uint)(-1L << ((ulong)uVar1 & 0x3f)),local_3c << (ulong)(uVar1 & 0x1f),0,
                           0,0);
      }
    }
    else {
      uVar3 = 0;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_zonda_list_registers @ 0010f3e0 size=348
// signature: undefined clk_alpha_pll_zonda_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_zonda_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120908 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_alpha_pll_zonda_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xe0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_regera_pll_list_registers @ 0010f540 size=348
// signature: undefined clk_regera_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_regera_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) +
                               (ulong)*(uint *)((long)&DAT_001209e8 + lVar2)),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_regera_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xc0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _alpha_pll_lucid_evo_enable @ 0010f69c size=428
// signature: undefined _alpha_pll_lucid_evo_enable(void)
// callers: [alpha_pll_lucid_evo_enable, _alpha_pll_lucid_evo_prepare]
//------------------------------------------------------------

void _alpha_pll_lucid_evo_enable(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  piVar5 = (int *)(param_1 + -0x50);
  local_44 = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  uVar4 = regmap_read(uVar6,*piVar5 + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&local_44);
  if ((int)uVar4 == 0) {
    if ((local_44._3_1_ >> 1 & 1) == 0) {
      local_3c = 0;
      local_40 = 0;
      iVar2 = regmap_read(uVar6,*(undefined4 *)(param_1 + -0x50),&local_3c);
      iVar3 = regmap_read(uVar6,*(int *)(param_1 + -0x50) +
                                (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),&local_40);
      if (((iVar3 == 0 && iVar2 == 0) && ((local_40 & 1) != 0)) && ((local_3c & 1) != 0)) {
        uVar4 = clk_hw_get_name(param_1);
        _printk(&DAT_0011cac8,uVar4);
        uVar4 = 0;
      }
      else {
        uVar4 = regmap_update_bits_base(uVar6,*piVar5,4,4,0,0,0);
        if ((int)uVar4 == 0) {
          regmap_write(uVar6,*(int *)(param_1 + -0x50) +
                             (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),1);
          uVar4 = wait_for_pll(piVar5,0x80000000,0,"enable");
          if (((int)uVar4 == 0) &&
             (uVar4 = regmap_update_bits_base(uVar6,*piVar5,1,1,0,0,0), (int)uVar4 == 0)) {
            DataSynchronizationBarrier(3,3,0);
          }
        }
      }
    }
    else {
      uVar4 = clk_enable_regmap(param_1);
      if ((int)uVar4 == 0) {
        uVar4 = wait_for_pll(piVar5,0x80000000,0,"enable");
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// _alpha_pll_lucid_evo_disable @ 0010f848 size=260
// signature: undefined _alpha_pll_lucid_evo_disable(void)
// callers: [_alpha_pll_lucid_evo_prepare, alpha_pll_reset_lucid_evo_disable, alpha_pll_lucid_evo_disable, alpha_pll_lucid_evo_unprepare]
//------------------------------------------------------------

void _alpha_pll_lucid_evo_disable(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  iVar2 = regmap_read(uVar3,*(int *)(param_1 + -0x50) +
                            (uint)*(byte *)(*(long *)(param_1 + -0x48) + 5),&local_3c);
  if (iVar2 == 0) {
    if ((local_3c._3_1_ >> 1 & 1) == 0) {
      iVar2 = regmap_update_bits_base(uVar3,*(undefined4 *)(param_1 + -0x50),1,0,0,0,0);
      if ((iVar2 == 0) &&
         ((regmap_write(uVar3,*(int *)(param_1 + -0x50) +
                              (uint)*(byte *)(*(long *)(param_1 + -0x48) + 0x12),0),
          (param_2 & 1) != 0 || ((*(byte *)(param_1 + -8) >> 5 & 1) != 0)))) {
        regmap_update_bits_base(uVar3,*(undefined4 *)(param_1 + -0x50),4,0,0,0,0);
      }
    }
    else {
      clk_disable_regmap(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lucid_evo_pll_list_registers @ 0010f950 size=348
// signature: undefined lucid_evo_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void lucid_evo_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120aa8 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&lucid_evo_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xd0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)*(byte *)(*(long *)(param_2 + -0x48) + 5),&local_5c)
  ;
  if ((local_5c._3_1_ >> 1 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _alpha_pll_lucid_evo_prepare @ 0010faac size=312
// signature: undefined _alpha_pll_lucid_evo_prepare(void)
// callers: [alpha_pll_reset_lucid_evo_prepare, alpha_pll_lucid_evo_prepare]
//------------------------------------------------------------

int _alpha_pll_lucid_evo_prepare(long param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  iVar3 = clk_prepare_regmap();
  if (iVar3 != 0) goto LAB_0010fb98;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50),&local_3c);
  if (((local_3c & 0x100) != 0) || ((*(byte *)(param_1 + -8) >> 6 & 1) != 0)) {
    if (*(long *)(param_1 + -0x40) != 0) {
      regmap_read(*(undefined8 *)(param_1 + 0x18),
                  *(int *)(param_1 + -0x50) + (uint)*(byte *)(*(long *)(param_1 + -0x48) + 1),
                  &local_3c);
      uVar2 = (uint)local_3c._2_2_;
      bVar1 = local_3c._2_2_ == 0;
      local_3c = uVar2 << 0x10;
      if ((bVar1) &&
         (iVar3 = clk_lucid_evo_pll_configure
                            (param_1 + -0x50,*(undefined8 *)(param_1 + 0x18),
                             *(undefined8 *)(param_1 + -0x40)), iVar3 != 0)) {
        _printk(&DAT_0011db16,iVar3);
        goto LAB_0010fb98;
      }
    }
    lVar4 = clk_hw_get_parent(param_1);
    if ((lVar4 == 0) || (lVar4 = clk_hw_get_rate(), lVar4 == 0)) {
      iVar3 = -0x16;
      goto LAB_0010fb98;
    }
    iVar3 = _alpha_pll_lucid_evo_enable(param_1);
    if (iVar3 != 0) goto LAB_0010fb98;
    if ((*(byte *)(param_1 + -8) >> 6 & 1) == 0) {
      _alpha_pll_lucid_evo_disable(param_1,param_2 & 1);
    }
  }
  iVar3 = 0;
LAB_0010fb98:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// clk_alpha_pll_zonda_evo_list_registers @ 0010fbe8 size=348
// signature: undefined clk_alpha_pll_zonda_evo_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_alpha_pll_zonda_evo_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120b78 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,
              *(undefined8 *)((long)&clk_alpha_pll_zonda_evo_list_registers_data + lVar2),local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xc0);
  regmap_read(*(undefined8 *)(param_2 + 0x18),
              *(int *)(param_2 + -0x50) + (uint)**(byte **)(param_2 + -0x48),&local_5c);
  if ((local_5c._2_1_ >> 4 & 1) != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"APSS_PLL_VOTE",local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","APSS_PLL_VOTE");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_rivian_evo_pll_list_registers @ 0010fd48 size=236
// signature: undefined clk_rivian_evo_pll_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_rivian_evo_pll_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  lVar2 = 0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  do {
    regmap_read(*(undefined8 *)(param_2 + 0x18),
                *(int *)(param_2 + -0x50) +
                (uint)*(byte *)(*(long *)(param_2 + -0x48) + (ulong)*(uint *)(&DAT_00120c38 + lVar2)
                               ),&local_5c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,*(undefined8 *)((long)&clk_rivian_evo_pll_list_registers_data + lVar2),
              local_5c);
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n");
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xb0);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_alpha_pll_slew_update @ 0010fe34 size=196
// signature: undefined clk_alpha_pll_slew_update(void)
// callers: [clk_alpha_pll_slew_set_rate, clk_alpha_pll_slew_enable]
//------------------------------------------------------------

void clk_alpha_pll_slew_update(undefined4 *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x1a),*param_1,0x400000,0x400000,0,0,0);
  regmap_read(*(undefined8 *)(param_1 + 0x1a),*param_1,&local_2c);
  iVar2 = wait_for_pll(param_1,0x400000,1,"update");
  if (iVar2 == 0) {
    DataSynchronizationBarrier(3,3,0);
    __const_udelay(0x10c7);
    wait_for_pll(param_1,0x80000000,0,"enable");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_hw_populate_clock_opp_table @ 0010fefc size=956
// signature: undefined clk_hw_populate_clock_opp_table(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

void clk_hw_populate_clock_opp_table(undefined8 param_1,long param_2)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  undefined8 *puVar13;
  undefined *puVar14;
  ulong uVar15;
  int *piVar16;
  long *plVar17;
  ulong uVar18;
  ulong uVar19;
  uint local_12c;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  long local_c0 [12];
  
  lVar10 = sp_el0;
  local_c0[10] = *(long *)(lVar10 + 0x638);
  plVar17 = (long *)(param_2 + 0x30);
  local_c8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_12c = 0;
  if ((*plVar17 != 0) && (*(int *)(param_2 + 0x48) != 0)) {
    pcVar7 = (char *)clk_hw_get_name(param_2);
    sVar8 = strlen(pcVar7);
    uVar9 = clk_hw_get_name(param_2);
    if (sVar8 + 0x10 < 100) {
      iVar3 = scnprintf(&local_128,100,"qcom,%s-opp-handle");
      pcVar7 = (char *)clk_hw_get_name(param_2);
      sVar8 = strlen(pcVar7);
      if ((ulong)(long)iVar3 < sVar8 + 0x10) {
        uVar9 = clk_hw_get_name(param_2);
        _printk(&DAT_0011dc08,uVar9);
      }
      else {
        lVar10 = of_find_property(param_1,&local_128,&local_12c);
        uVar5 = local_12c;
        if ((lVar10 != 0) && (-1 < (int)local_12c)) {
          uVar15 = (ulong)(uint)((int)local_12c >> 2);
          uVar18 = -(ulong)((uint)((int)local_12c >> 2) >> 0x1f) & 0xfffffff800000000 | uVar15 << 3;
          puVar11 = (undefined8 *)__kmalloc(uVar18,0xcc0);
          if (puVar11 != (undefined8 *)0x0) {
            bVar1 = 3 < uVar5;
            if (uVar5 < 4) {
              bVar1 = false;
            }
            else {
              iVar3 = 0;
              uVar19 = 0;
              do {
                if (((long)uVar19 < 0) || (uVar18 <= uVar19)) {
LAB_001102b0:
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(1,0x1102b4);
                  (*pcVar2)();
                }
                *(undefined8 *)((long)puVar11 + uVar19) = 0;
                local_c0[8] = 0;
                local_c0[9] = 0;
                local_c0[6] = 0;
                local_c0[7] = 0;
                local_c0[4] = 0;
                local_c0[5] = 0;
                local_c0[3] = 0;
                local_c0[1] = 0;
                local_c0[2] = 0;
                local_c0[0] = 0;
                iVar4 = __of_parse_phandle_with_args(param_1,&local_128,0,0,iVar3,local_c0);
                if ((iVar4 != 0) || (local_c0[0] == 0)) {
                  uVar9 = clk_hw_get_name(param_2);
                  _printk(&DAT_0011ca0c,uVar9,&local_128);
LAB_00110218:
                  puVar14 = &DAT_0011d82b;
                  puVar13 = &local_128;
                  goto LAB_00110224;
                }
                lVar10 = of_find_device_by_node();
                if (lVar10 == 0) {
                  uVar9 = clk_hw_get_name(param_2);
                  _printk(&DAT_0011dc2e,uVar9);
                  goto LAB_00110218;
                }
                if (((long)uVar19 < 0) || (uVar18 <= uVar19)) goto LAB_001102b0;
                iVar3 = iVar3 + 1;
                *(long *)((long)puVar11 + uVar19) = lVar10 + 0x10;
                uVar19 = uVar19 + 8;
              } while (uVar15 * 8 != uVar19);
            }
            if (0 < *(int *)(param_2 + 0x48)) {
              iVar3 = 0;
              lVar10 = 0;
LAB_001100e8:
              lVar12 = clk_hw_round_rate(param_2,lVar10 + 1);
              if (lVar12 == 0) {
                puVar13 = (undefined8 *)clk_hw_get_name(param_2);
                puVar14 = &DAT_0011c91e;
LAB_00110224:
                _printk(puVar14,puVar13);
                goto LAB_00110228;
              }
              if (lVar10 == lVar12) goto LAB_00110228;
              lVar10 = *plVar17;
              if (*(int *)(lVar10 + 0x18) < 2) {
                uVar5 = clk_find_vdd_level(param_2,plVar17,lVar12);
                if ((int)uVar5 < 0) {
                  _printk(&DAT_0011d39c);
                  goto LAB_00110228;
                }
                piVar16 = (int *)(*(long *)(lVar10 + 0x20) + (ulong)uVar5 * 4);
              }
              else {
                piVar16 = (int *)(*(long *)(lVar10 + 0x20) +
                                 (long)(*(int *)(lVar10 + 0x18) * iVar3) * 4);
              }
              iVar4 = *piVar16;
              if (iVar4 == 0) {
                uVar9 = clk_hw_get_name(param_2);
                _printk(&DAT_0011dcbd,uVar9,lVar12);
              }
              else if (-1 < iVar4) goto code_r0x0011014c;
            }
LAB_00110228:
            kfree(puVar11);
          }
        }
      }
    }
    else {
      _printk(&DAT_0011db4f,uVar9);
    }
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_c0[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
code_r0x0011014c:
  if (bVar1) {
    uVar18 = uVar15;
    puVar13 = puVar11;
    do {
      iVar6 = dev_pm_opp_add(*puVar13,lVar12,iVar4);
      uVar9 = clk_hw_get_name(param_2);
      if (iVar6 != 0) {
        _printk(&DAT_0011da0b,uVar9,lVar12,iVar6);
        _printk(&DAT_0011d2f8);
        break;
      }
      lVar10 = ((long *)*puVar13)[0xe];
      if (lVar10 == 0) {
        lVar10 = *(long *)*puVar13;
      }
      _printk(&DAT_0011d027,uVar9,lVar12,iVar4,lVar10);
      uVar18 = uVar18 - 1;
      puVar13 = puVar13 + 1;
    } while (uVar18 != 0);
  }
  iVar3 = iVar3 + 1;
  lVar10 = lVar12;
  if (*(int *)(param_2 + 0x48) <= iVar3) goto LAB_00110228;
  goto LAB_001100e8;
}



//------------------------------------------------------------
// clk_pll_enable @ 001102bc size=252
// signature: undefined clk_pll_enable(void)
// callers: [clk_pll_set_rate]
//------------------------------------------------------------

void clk_pll_enable(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
  if (iVar2 == 0) {
    if (((((local_2c ^ 0xffffffff) & 7) != 0) && ((local_2c >> 0x14 & 1) == 0)) &&
       (iVar2 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),2,2,0,0,
                           0), iVar2 == 0)) {
      __const_udelay(0xa7c6);
      iVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),4,4,0,0,0)
      ;
      if (iVar2 == 0) {
        __const_udelay(0x346de);
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),1,1,0,0,0);
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_pll_disable @ 001103bc size=140
// signature: undefined clk_pll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_pll_disable(long param_1)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
  if ((local_2c._2_1_ >> 4 & 1) == 0) {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),7,0,0,0,0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_pll_recalc_rate @ 0011044c size=264
// signature: undefined clk_pll_recalc_rate(void)
// callers: [clk_pll_determine_rate]
//------------------------------------------------------------

ulong clk_pll_recalc_rate(long param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 local_48;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  local_40 = 0;
  local_48 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x28),&local_3c);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x24),&local_40);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x20),(long)&local_48 + 4);
  uVar7 = (ulong)local_40;
  uVar6 = ((ulong)local_3c & 0x3ff) * param_2;
  uVar3 = local_48 & 0x7ffff00000000;
  uVar5 = local_48 >> 0x20 & 0x7ffff;
  local_3c = (uint)((ulong)local_3c & 0x3ff);
  iVar4 = (int)uVar5;
  local_40 = (uint)(uVar7 & 0x7ffff);
  local_48 = CONCAT44(iVar4,(uint)local_48);
  if (iVar4 != 0) {
    uVar1 = 0;
    if (uVar3 != 0) {
      uVar1 = ((uVar7 & 0x7ffff) * param_2) / uVar5;
    }
    uVar6 = uVar1 + uVar6;
  }
  uVar7 = uVar6;
  if (*(char *)(param_1 + -0xf) != '\0') {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x1c),&local_48);
    uVar3 = (ulong)(((uint)local_48 >> (ulong)(*(byte *)(param_1 + -0xe) & 0x1f) &
                    ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0xf) & 0x3f)) ^ 0xffffffff)) + 1);
    uVar7 = 0;
    if (uVar3 != 0) {
      uVar7 = uVar6 / uVar3;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// clk_pll_determine_rate @ 00110558 size=100
// signature: undefined clk_pll_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_pll_determine_rate(long param_1,ulong *param_2)

{
  ulong uVar1;
  ulong *puVar2;
  
  puVar2 = *(ulong **)(param_1 + -8);
  if ((puVar2 != (ulong *)0x0) && (uVar1 = *puVar2, uVar1 != 0)) {
    do {
      if (*param_2 <= uVar1) {
        if (puVar2 != (ulong *)0x0) goto LAB_001105a4;
        break;
      }
      puVar2 = puVar2 + 3;
      uVar1 = *puVar2;
    } while (uVar1 != 0);
  }
  uVar1 = clk_pll_recalc_rate(param_1,param_2[3]);
LAB_001105a4:
  *param_2 = uVar1;
  return 0;
}



//------------------------------------------------------------
// clk_pll_set_rate @ 001105c0 size=368
// signature: undefined clk_pll_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_pll_set_rate(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong *puVar5;
  uint local_40;
  byte bStack_3a;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = *(ulong **)(param_1 + -8);
  local_40 = 0;
  if (puVar5 != (ulong *)0x0) {
    uVar4 = *puVar5;
    while (uVar4 != 0) {
      if (param_2 <= uVar4) {
        if (puVar5 != (ulong *)0x0) {
          regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_40);
          uVar1 = local_40 & 7;
          if (uVar1 == 7) {
            local_3c = 0;
            regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),
                        &stack0xffffffffffffffc4);
            if ((bStack_3a >> 4 & 1) == 0) {
              regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),7,0,0,0,0)
              ;
            }
          }
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x28),0x3ff,
                     (short)puVar5[1],0,0,0);
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x24),0x7ffff,
                     *(undefined2 *)((long)puVar5 + 10),0,0,0);
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x20),0x7ffff,
                     *(undefined2 *)((long)puVar5 + 0xc),0,0,0);
          regmap_write(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x1c),
                       (int)puVar5[2]);
          uVar3 = 0;
          if (uVar1 == 7) {
            clk_pll_enable(param_1);
            uVar3 = 0;
          }
          goto LAB_00110700;
        }
        break;
      }
      puVar5 = puVar5 + 3;
      uVar4 = *puVar5;
    }
  }
  uVar3 = 0xffffffea;
LAB_00110700:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_pll_vote_enable @ 00110734 size=216
// signature: undefined clk_pll_vote_enable(void)
// callers: []
//------------------------------------------------------------

void clk_pll_vote_enable(undefined8 param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = clk_hw_get_parent();
  uVar3 = clk_enable_regmap(param_1);
  if ((int)uVar3 == 0) {
    local_3c = 0;
    uVar4 = clk_hw_get_name(lVar2);
    uVar5 = 0xc9;
    while (uVar3 = regmap_read(*(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + -0x14),
                               &local_3c), (int)uVar3 == 0) {
      if ((local_3c >> ((ulong)*(byte *)(lVar2 + -0x10) & 0x3f) & 1) != 0) {
        uVar3 = 0;
        break;
      }
      __const_udelay(0x10c7);
      uVar5 = uVar5 - 1;
      if (uVar5 < 2) {
        __warn_printk("%s didn\'t enable after voting for it!\n",uVar4);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x110800);
        (*pcVar1)();
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_pll_configure_sr @ 00110814 size=212
// signature: undefined clk_pll_configure_sr(void)
// callers: []
//------------------------------------------------------------

void clk_pll_configure_sr(undefined4 *param_1,undefined8 param_2,undefined2 *param_3,ulong param_4)

{
  regmap_write(param_2,*param_1,*param_3);
  regmap_write(param_2,param_1[1],*(undefined4 *)(param_3 + 2));
  regmap_write(param_2,param_1[2],*(undefined4 *)(param_3 + 4));
  regmap_update_bits_base
            (param_2,param_1[3],
             *(uint *)(param_3 + 8) | *(uint *)(param_3 + 0xc) |
             *(uint *)(param_3 + 0x10) | *(uint *)(param_3 + 0x12) |
             *(uint *)(param_3 + 0x14) | *(uint *)(param_3 + 0x16),
             *(uint *)(param_3 + 6) | *(uint *)(param_3 + 10) |
             *(uint *)(param_3 + 0xe) | *(uint *)(param_3 + 0x12) |
             *(uint *)(param_3 + 0x14) | *(uint *)(param_3 + 0x16),0,0,0);
  if ((param_4 & 1) != 0) {
    qcom_pll_set_fsm_mode(param_2,param_1[4],1,8);
  }
  return;
}



//------------------------------------------------------------
// clk_pll_configure_sr_hpm_lp @ 001108ec size=212
// signature: undefined clk_pll_configure_sr_hpm_lp(void)
// callers: []
//------------------------------------------------------------

void clk_pll_configure_sr_hpm_lp
               (undefined4 *param_1,undefined8 param_2,undefined2 *param_3,ulong param_4)

{
  regmap_write(param_2,*param_1,*param_3);
  regmap_write(param_2,param_1[1],*(undefined4 *)(param_3 + 2));
  regmap_write(param_2,param_1[2],*(undefined4 *)(param_3 + 4));
  regmap_update_bits_base
            (param_2,param_1[3],
             *(uint *)(param_3 + 8) | *(uint *)(param_3 + 0xc) |
             *(uint *)(param_3 + 0x10) | *(uint *)(param_3 + 0x12) |
             *(uint *)(param_3 + 0x14) | *(uint *)(param_3 + 0x16),
             *(uint *)(param_3 + 6) | *(uint *)(param_3 + 10) |
             *(uint *)(param_3 + 0xe) | *(uint *)(param_3 + 0x12) |
             *(uint *)(param_3 + 0x14) | *(uint *)(param_3 + 0x16),0,0,0);
  if ((param_4 & 1) != 0) {
    qcom_pll_set_fsm_mode(param_2,param_1[4],1,0);
  }
  return;
}



//------------------------------------------------------------
// clk_pll_sr2_enable @ 001109c4 size=328
// signature: undefined clk_pll_sr2_enable(void)
// callers: [clk_pll_sr2_set_rate]
//------------------------------------------------------------

void clk_pll_sr2_enable(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 local_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_40);
  if ((iVar3 == 0) &&
     (iVar3 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),2,2,0,0,0)
     , iVar3 == 0)) {
    __const_udelay(0xa7c6);
    iVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),4,4,0,0,0);
    if (iVar3 == 0) {
      local_3c = 0;
      uVar4 = clk_hw_get_name(param_1);
      uVar5 = 0xc9;
      while (iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x14),
                                 &local_3c), iVar3 == 0) {
        if ((local_3c >> ((ulong)*(byte *)(param_1 + -0x10) & 0x3f) & 1) != 0) {
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),1,1,0,0,0);
          break;
        }
        __const_udelay(0x10c7);
        uVar5 = uVar5 - 1;
        if (uVar5 < 2) {
          __warn_printk("%s didn\'t enable after voting for it!\n",uVar4);
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x110ae4);
          (*pcVar2)();
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_pll_sr2_set_rate @ 00110b14 size=352
// signature: undefined clk_pll_sr2_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_pll_sr2_set_rate(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong *puVar5;
  uint local_40;
  byte bStack_3a;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = *(ulong **)(param_1 + -8);
  local_40 = 0;
  if (puVar5 != (ulong *)0x0) {
    uVar4 = *puVar5;
    while (uVar4 != 0) {
      if (param_2 <= uVar4) {
        if (puVar5 != (ulong *)0x0) {
          regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_40);
          uVar1 = local_40 & 7;
          if (uVar1 == 7) {
            local_3c = 0;
            regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),
                        &stack0xffffffffffffffc4);
            if ((bStack_3a >> 4 & 1) == 0) {
              regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),7,0,0,0,0)
              ;
            }
          }
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x28),0x3ff,
                     (short)puVar5[1],0,0,0);
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x24),0x7ffff,
                     *(undefined2 *)((long)puVar5 + 10),0,0,0);
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x20),0x7ffff,
                     *(undefined2 *)((long)puVar5 + 0xc),0,0,0);
          uVar3 = 0;
          if (uVar1 == 7) {
            clk_pll_sr2_enable(param_1);
            uVar3 = 0;
          }
          goto LAB_00110c44;
        }
        break;
      }
      puVar5 = puVar5 + 3;
      uVar4 = *puVar5;
    }
  }
  uVar3 = 0xffffffea;
LAB_00110c44:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg_recalc_rate @ 00110c78 size=320
// signature: undefined clk_rcg_recalc_rate(void)
// callers: []
//------------------------------------------------------------

ulong clk_rcg_recalc_rate(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  local_54 = 0;
  local_50 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_4c);
  uVar1 = local_4c >> (ulong)(*(byte *)(param_1 + -0x21) & 0x1f) &
          ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0x20) & 0x3f)) ^ 0xffffffff);
  if (*(char *)(param_1 + -0x23) == '\0') {
    uVar3 = 0;
    uVar7 = 0;
    uVar8 = 0;
  }
  else {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x2c),&local_50);
    uVar5 = (uint)(-1L << ((ulong)*(byte *)(param_1 + -0x23) & 0x3f));
    uVar3 = local_50 >> ((ulong)*(byte *)(param_1 + -0x24) & 0x3f) & ~uVar5;
    uVar7 = (ulong)uVar3;
    uVar8 = (ulong)((~local_4c >> (ulong)(*(byte *)(param_1 + -0x25) & 0x1f) & (uVar5 ^ 0xffffffff))
                   + uVar3);
    uVar3 = local_4c;
    if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + -0x30)) {
      regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + 0x20),&local_54);
      uVar3 = local_54;
    }
    uVar3 = uVar3 >> (ulong)(*(byte *)(param_1 + -0x26) & 0x1f) & 3;
  }
  uVar6 = param_2;
  if (uVar1 != 0) {
    uVar4 = (ulong)(uVar1 + 1);
    uVar6 = 0;
    if (uVar4 != 0) {
      uVar6 = param_2 / uVar4;
    }
  }
  if (uVar3 != 0) {
    uVar7 = uVar6 * uVar7;
    uVar6 = 0;
    if (uVar8 != 0) {
      uVar6 = uVar7 / uVar8;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// clk_rcg_determine_rate @ 00110dbc size=36
// signature: undefined clk_rcg_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_determine_rate(long param_1,undefined8 param_2)

{
  _freq_tbl_determine_rate
            (param_1,*(undefined8 *)(param_1 + -8),param_2,*(undefined8 *)(param_1 + -0x10));
  return;
}



//------------------------------------------------------------
// clk_rcg_set_parent @ 00110de4 size=164
// signature: undefined clk_rcg_set_parent(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_set_parent(long param_1,byte param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_2c);
  local_2c = local_2c & (7 << (ulong)(*(byte *)(param_1 + -0x18) & 0x1f) ^ 0xffffffffU) |
             (uint)*(byte *)(*(long *)(param_1 + -0x10) + (ulong)param_2 * 2 + 1) <<
             (ulong)(*(byte *)(param_1 + -0x18) & 0x1f);
  regmap_write(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_rcg_get_parent @ 00110e8c size=196
// signature: undefined clk_rcg_get_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_get_parent(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  byte *pbVar5;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar2 = clk_hw_get_num_parents();
  local_2c = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_2c);
  uVar4 = 0;
  if (iVar3 == 0) {
    local_2c = local_2c >> (ulong)(*(byte *)(param_1 + -0x18) & 0x1f) & 7;
    if (0 < (int)uVar2) {
      uVar4 = 0;
      pbVar5 = (byte *)(*(long *)(param_1 + -0x10) + 1);
      do {
        if (local_2c == *pbVar5) goto LAB_00110f24;
        uVar4 = uVar4 + 1;
        pbVar5 = pbVar5 + 2;
      } while (uVar2 != uVar4);
    }
    uVar4 = 0;
  }
LAB_00110f24:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg_set_rate @ 00110f54 size=72
// signature: undefined clk_rcg_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_set_rate(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = qcom_find_freq(*(undefined8 *)(param_1 + -8));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    __clk_rcg_set_rate(param_1 + -0x30,lVar1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_rcg_set_floor_rate @ 00110fa0 size=72
// signature: undefined clk_rcg_set_floor_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_set_floor_rate(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = qcom_find_freq_floor(*(undefined8 *)(param_1 + -8));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    __clk_rcg_set_rate(param_1 + -0x30,lVar1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_rcg_bypass_determine_rate @ 00110fec size=104
// signature: undefined clk_rcg_bypass_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_bypass_determine_rate(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar1 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x10),
                              *(undefined1 *)(*(long *)(param_1 + -8) + 8));
  lVar2 = clk_hw_get_parent_by_index(param_1,uVar1);
  param_2[4] = lVar2;
  if (lVar2 == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar3 = clk_hw_round_rate(lVar2,*param_2);
    uVar4 = 0;
    param_2[3] = uVar3;
    *param_2 = uVar3;
  }
  return uVar4;
}



//------------------------------------------------------------
// clk_rcg_bypass_set_rate @ 00111058 size=44
// signature: undefined clk_rcg_bypass_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_bypass_set_rate(long param_1)

{
  __clk_rcg_set_rate(param_1 + -0x30,*(undefined8 *)(param_1 + -8));
  return 0;
}



//------------------------------------------------------------
// clk_rcg_bypass2_determine_rate @ 00111088 size=64
// signature: undefined clk_rcg_bypass2_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_bypass2_determine_rate(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = clk_hw_round_rate(param_2[4],*param_2);
  param_2[3] = uVar1;
  *param_2 = uVar1;
  return 0;
}



//------------------------------------------------------------
// clk_rcg_bypass2_set_rate @ 001110cc size=256
// signature: undefined clk_rcg_bypass2_set_rate(void)
// callers: [clk_rcg_bypass2_set_rate_and_parent]
//------------------------------------------------------------

void clk_rcg_bypass2_set_rate(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  byte *pbVar4;
  ulong uVar5;
  uint local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  local_54 = 0;
  uVar2 = clk_hw_get_num_parents();
  uVar5 = (ulong)uVar2;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_54);
  if ((int)uVar3 == 0) {
    local_48._0_2_ =
         CONCAT11(((byte)(local_54 >> (ulong)(*(byte *)(param_1 + -0x21) & 0x1f)) &
                  ((byte)(-1L << ((ulong)*(byte *)(param_1 + -0x20) & 0x3f)) ^ 0xff)) + 1,
                  (undefined1)local_48);
    if (0 < (int)uVar2) {
      pbVar4 = (byte *)(*(long *)(param_1 + -0x10) + 1);
      do {
        if ((local_54 >> (ulong)(*(byte *)(param_1 + -0x18) & 0x1f) & 7) == (uint)*pbVar4) {
          local_48 = CONCAT71(local_48._1_7_,pbVar4[-1]);
          __clk_rcg_set_rate((undefined4 *)(param_1 + -0x30),&local_50);
          uVar3 = 0;
          goto LAB_0011119c;
        }
        pbVar4 = pbVar4 + 2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    uVar3 = 0xffffffea;
  }
LAB_0011119c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg_bypass2_set_rate_and_parent @ 001111d0 size=28
// signature: undefined clk_rcg_bypass2_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_bypass2_set_rate_and_parent(void)

{
  clk_rcg_bypass2_set_rate();
  return;
}



//------------------------------------------------------------
// clk_rcg_pixel_determine_rate @ 001111f0 size=268
// signature: undefined clk_rcg_pixel_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_pixel_determine_rate(undefined8 param_1,ulong *param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *param_2 * 2;
  uVar2 = clk_hw_round_rate(param_2[4],lVar4);
  if ((uVar2 < lVar4 - 100000U) || (lVar4 + 100000U < uVar2)) {
    lVar4 = *param_2 * 3;
    uVar2 = clk_hw_round_rate(param_2[4],lVar4);
    if ((uVar2 < lVar4 - 100000U) || (lVar4 + 100000U < uVar2)) {
      uVar3 = (*param_2 << 4) / 3;
      uVar2 = clk_hw_round_rate(param_2[4],uVar3);
      if (uVar2 < uVar3 - 100000) {
        return 0xffffffea;
      }
      if (uVar3 + 100000 < uVar2) {
        return 0xffffffea;
      }
      uVar3 = 0x10;
      lVar4 = 3;
    }
    else {
      uVar3 = 3;
      lVar4 = 1;
    }
  }
  else {
    uVar3 = 2;
    lVar4 = 1;
  }
  param_2[3] = uVar2;
  uVar1 = 0;
  if (uVar3 != 0) {
    uVar1 = (uVar2 * lVar4) / uVar3;
  }
  *param_2 = uVar1;
  return 0;
}



//------------------------------------------------------------
// clk_rcg_pixel_set_rate @ 00111300 size=400
// signature: undefined clk_rcg_pixel_set_rate(void)
// callers: [clk_rcg_pixel_set_rate_and_parent]
//------------------------------------------------------------

void clk_rcg_pixel_set_rate(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  byte *pbVar7;
  ulong uVar8;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_64 = 0;
  uVar3 = clk_hw_get_num_parents();
  uVar8 = (ulong)uVar3;
  uVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_64);
  if ((int)uVar4 == 0) {
    if (0 < (int)uVar3) {
      pbVar7 = (byte *)(*(long *)(param_1 + -0x10) + 1);
      do {
        if ((local_64 >> (ulong)(*(byte *)(param_1 + -0x18) & 0x1f) & 7) == (uint)*pbVar7) {
          local_58 = CONCAT71(local_58._1_7_,pbVar7[-1]);
          break;
        }
        pbVar7 = pbVar7 + 2;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    uVar2 = local_58;
    uVar5 = 1;
    local_58._0_2_ = CONCAT11(1,(undefined1)local_58);
    if ((param_3 < param_2 * 2 - 100000U) || (param_2 * 2 + 100000U < param_3)) {
      if ((param_3 < param_2 * 3 - 100000U) || (param_2 * 3 + 100000U < param_3)) {
        uVar4 = 0xffffffea;
        uVar8 = (ulong)(param_2 << 4) / 3;
        if ((param_3 < uVar8 - 100000) || (uVar8 + 100000 < param_3)) goto LAB_0011145c;
        uVar6 = 0x10;
        uVar5 = 3;
      }
      else {
        uVar6 = 3;
        uVar5 = 1;
      }
    }
    else {
      uVar6 = 2;
    }
    local_58._6_2_ = SUB82(uVar2,6);
    local_58._0_6_ = CONCAT24(uVar6,CONCAT22(uVar5,(undefined2)local_58));
    __clk_rcg_set_rate((undefined4 *)(param_1 + -0x30),&local_60);
    uVar4 = 0;
  }
LAB_0011145c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg_pixel_set_rate_and_parent @ 00111494 size=28
// signature: undefined clk_rcg_pixel_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_pixel_set_rate_and_parent(void)

{
  clk_rcg_pixel_set_rate();
  return;
}



//------------------------------------------------------------
// clk_rcg_esc_determine_rate @ 001114b4 size=116
// signature: undefined clk_rcg_esc_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_esc_determine_rate(long param_1,ulong *param_2)

{
  byte bVar1;
  ulong uVar2;
  ulong uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ulong uVar7;
  int iVar8;
  int iVar9;
  
  if (*param_2 != 0) {
    bVar1 = *(byte *)(param_1 + -0x20);
    uVar7 = clk_hw_get_rate(param_2[4]);
    uVar2 = 0;
    if (*param_2 != 0) {
      uVar2 = uVar7 / *param_2;
    }
    iVar8 = (int)uVar2;
    bVar4 = false;
    bVar5 = false;
    bVar6 = false;
    if (0 < iVar8) {
      iVar9 = (int)(1L << ((ulong)bVar1 & 0x3f));
      bVar6 = SBORROW4(iVar8,iVar9);
      bVar4 = iVar8 - iVar9 < 0;
      bVar5 = iVar8 == iVar9;
    }
    if (bVar5 || bVar4 != bVar6) {
      uVar3 = 0;
      if ((uVar2 & 0xffffffff) != 0) {
        uVar3 = uVar7 / (uVar2 & 0xffffffff);
      }
      param_2[3] = uVar7;
      *param_2 = uVar3;
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// clk_rcg_esc_set_rate @ 0011152c size=280
// signature: undefined clk_rcg_esc_set_rate(void)
// callers: [clk_rcg_esc_set_rate_and_parent]
//------------------------------------------------------------

void clk_rcg_esc_set_rate(long param_1,ulong param_2,ulong param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  undefined8 uVar8;
  int iVar9;
  byte *pbVar10;
  ulong uVar11;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  bVar1 = *(byte *)(param_1 + -0x20);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_64 = 0;
  uVar7 = clk_hw_get_num_parents();
  if (param_2 != 0) {
    uVar11 = (ulong)uVar7;
    uVar8 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_64);
    if ((int)uVar8 != 0) goto LAB_001115f8;
    local_64 = local_64 >> (ulong)(*(byte *)(param_1 + -0x18) & 0x1f) & 7;
    if (0 < (int)uVar7) {
      pbVar10 = (byte *)(*(long *)(param_1 + -0x10) + 1);
      do {
        if (local_64 == *pbVar10) {
          local_58 = CONCAT71(local_58._1_7_,pbVar10[-1]);
          break;
        }
        pbVar10 = pbVar10 + 2;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    iVar2 = 0;
    if (param_2 != 0) {
      iVar2 = (int)(param_3 / param_2);
    }
    bVar4 = false;
    bVar5 = false;
    bVar6 = false;
    if (0 < iVar2) {
      iVar9 = (int)(1L << ((ulong)bVar1 & 0x3f));
      bVar6 = SBORROW4(iVar2,iVar9);
      bVar4 = iVar2 - iVar9 < 0;
      bVar5 = iVar2 == iVar9;
    }
    if (bVar5 || bVar4 != bVar6) {
      local_58._0_2_ = CONCAT11((char)iVar2,(undefined1)local_58);
      __clk_rcg_set_rate(param_1 + -0x30,&local_60);
      uVar8 = 0;
      goto LAB_001115f8;
    }
  }
  uVar8 = 0xffffffea;
LAB_001115f8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg_esc_set_rate_and_parent @ 00111648 size=28
// signature: undefined clk_rcg_esc_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_esc_set_rate_and_parent(void)

{
  clk_rcg_esc_set_rate();
  return;
}



//------------------------------------------------------------
// clk_rcg_lcc_enable @ 00111668 size=60
// signature: undefined clk_rcg_lcc_enable(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_lcc_enable(long param_1)

{
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),0x400,0x400,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_rcg_lcc_disable @ 001116a8 size=60
// signature: undefined clk_rcg_lcc_disable(void)
// callers: []
//------------------------------------------------------------

void clk_rcg_lcc_disable(long param_1)

{
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),0x400,0,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_rcg_lcc_set_rate @ 001116e8 size=172
// signature: undefined clk_rcg_lcc_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg_lcc_set_rate(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = qcom_find_freq(*(undefined8 *)(param_1 + -8));
  if (lVar1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),0x400,0,0,0,0);
    __clk_rcg_set_rate(param_1 + -0x30,lVar1);
    uVar2 = __clk_is_enabled(*(undefined8 *)(param_1 + 8));
    uVar3 = 0;
    if ((uVar2 & 1) != 0) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),0x400,0x400,0,0,0)
      ;
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_dyn_rcg_recalc_rate @ 00111798 size=380
// signature: undefined clk_dyn_rcg_recalc_rate(void)
// callers: []
//------------------------------------------------------------

ulong clk_dyn_rcg_recalc_rate(long param_1,ulong param_2)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  cVar3 = *(char *)(param_1 + -0x2a);
  local_4c = 0;
  cVar4 = *(char *)(param_1 + -0x2f);
  local_54 = 0;
  local_50 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x40),&local_54);
  uVar11 = (ulong)((local_54 & (uint)(1L << ((ulong)*(byte *)(param_1 + -0x3c) & 0x3f))) != 0);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + uVar11 * 4 + -0x50),
              &local_4c);
  if (cVar4 == '\0') {
    uVar5 = 0;
    uVar7 = 0;
    uVar9 = 0;
  }
  else {
    lVar6 = param_1 + uVar11 * 7;
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + uVar11 * 4 + -0x48),
                &local_50);
    uVar8 = (uint)(-1L << ((ulong)*(byte *)(lVar6 + -0x36) & 0x3f));
    uVar2 = local_50 >> ((ulong)*(byte *)(lVar6 + -0x37) & 0x3f) & ~uVar8;
    uVar5 = (ulong)uVar2;
    uVar9 = local_54;
    if (*(int *)(param_1 + -0x50) != *(int *)(param_1 + -0x4c)) {
      uVar9 = local_4c;
    }
    uVar7 = (ulong)((~local_4c >> (ulong)(*(byte *)(lVar6 + -0x38) & 0x1f) & (uVar8 ^ 0xffffffff)) +
                   uVar2);
    uVar9 = uVar9 >> (ulong)(*(byte *)(lVar6 + -0x39) & 0x1f) & 3;
  }
  if (cVar3 != '\0') {
    pbVar1 = (byte *)(param_1 + -0x2d + uVar11 * 2);
    uVar2 = local_4c >> (ulong)(*pbVar1 & 0x1f) &
            ((uint)(-1L << ((ulong)pbVar1[1] & 0x3f)) ^ 0xffffffff);
    if (uVar2 != 0) {
      uVar10 = (ulong)(uVar2 + 1);
      uVar11 = 0;
      if (uVar10 != 0) {
        uVar11 = param_2 / uVar10;
      }
      param_2 = uVar11;
    }
  }
  if (uVar9 != 0) {
    uVar5 = param_2 * uVar5;
    param_2 = 0;
    if (uVar7 != 0) {
      param_2 = uVar5 / uVar7;
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// clk_dyn_rcg_determine_rate @ 00111918 size=152
// signature: undefined clk_dyn_rcg_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_dyn_rcg_determine_rate(long param_1,undefined8 param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x40),&local_2c);
  _freq_tbl_determine_rate
            (param_1,*(undefined8 *)(param_1 + -8),param_2,
             *(undefined8 *)
              (param_1 + (ulong)((local_2c &
                                 (uint)(1L << ((ulong)*(byte *)(param_1 + -0x3c) & 0x3f))) != 0) *
                         0x10 + -0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_dyn_rcg_set_parent @ 001119b4 size=356
// signature: undefined clk_dyn_rcg_set_parent(void)
// callers: []
//------------------------------------------------------------

void clk_dyn_rcg_set_parent(long param_1,undefined4 param_2)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_54;
  undefined8 local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  cVar2 = *(char *)(param_1 + -0x2f);
  local_50 = 0;
  cVar3 = *(char *)(param_1 + -0x2a);
  local_54 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x40),&local_54);
  uVar9 = (ulong)((local_54 & (uint)(1L << ((ulong)*(byte *)(param_1 + -0x3c) & 0x3f))) != 0);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x50 + uVar9 * 4),
              (long)&local_50 + 4);
  if (cVar2 != '\0') {
    lVar8 = param_1 + uVar9 * 7;
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + uVar9 * 4 + -0x48),
                &local_50);
    uVar6 = local_68;
    uVar5 = (ushort)(-1L << ((ulong)*(byte *)(lVar8 + -0x36) & 0x3f));
    uVar4 = (ushort)((uint)local_50 >> (ulong)(*(byte *)(lVar8 + -0x37) & 0x1f)) & (uVar5 ^ 0xffff);
    local_68._6_2_ = SUB82(uVar6,6);
    local_68._0_6_ =
         CONCAT24(((ushort)(~local_50._4_4_ >> (ulong)(*(byte *)(lVar8 + -0x38) & 0x1f)) &
                  (uVar5 ^ 0xffff)) + uVar4,CONCAT22(uVar4,(undefined2)local_68));
  }
  if (cVar3 != '\0') {
    pbVar1 = (byte *)(param_1 + -0x2d + uVar9 * 2);
    local_68._0_2_ =
         CONCAT11(((byte)(local_50._4_4_ >> (ulong)(*pbVar1 & 0x1f)) &
                  ((byte)(-1L << ((ulong)pbVar1[1] & 0x3f)) ^ 0xff)) + 1,(undefined1)local_68);
  }
  uVar7 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + uVar9 * 0x10 + -0x20),param_2);
  local_68 = CONCAT71(local_68._1_7_,uVar7);
  configure_bank(param_1 + -0x50,&local_70);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_dyn_rcg_get_parent @ 00111b1c size=264
// signature: undefined clk_dyn_rcg_get_parent(void)
// callers: []
//------------------------------------------------------------

void clk_dyn_rcg_get_parent(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  byte *pbVar6;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar3 = clk_hw_get_num_parents();
  local_40 = 0;
  iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x40),&local_40);
  uVar5 = 0;
  if (iVar4 == 0) {
    uVar5 = (ulong)(((uint)local_40 & (uint)(1L << ((ulong)*(byte *)(param_1 + -0x3c) & 0x3f))) != 0
                   );
    iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + uVar5 * 4 + -0x50)
                        ,(long)&local_40 + 4);
    if (iVar4 == 0) {
      param_1 = param_1 + uVar5 * 0x10;
      uVar1 = local_40._4_4_ >> (ulong)(*(byte *)(param_1 + -0x28) & 0x1f);
      local_40 = CONCAT44(uVar1,(uint)local_40) & 0x7ffffffff;
      if (0 < (int)uVar3) {
        uVar5 = 0;
        pbVar6 = (byte *)(*(long *)(param_1 + -0x20) + 1);
        do {
          if ((uVar1 & 7) == (uint)*pbVar6) goto LAB_00111ba0;
          uVar5 = uVar5 + 1;
          pbVar6 = pbVar6 + 2;
        } while (uVar3 != uVar5);
      }
    }
    uVar5 = 0;
  }
LAB_00111ba0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_dyn_rcg_set_rate @ 00111c28 size=68
// signature: undefined clk_dyn_rcg_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_dyn_rcg_set_rate(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = qcom_find_freq(*(undefined8 *)(param_1 + -8));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = configure_bank(param_1 + -0x50,lVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_dyn_rcg_set_rate_and_parent @ 00111c70 size=68
// signature: undefined clk_dyn_rcg_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_dyn_rcg_set_rate_and_parent(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = qcom_find_freq(*(undefined8 *)(param_1 + -8));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = configure_bank(param_1 + -0x50,lVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// _freq_tbl_determine_rate @ 00111cb4 size=212
// signature: undefined _freq_tbl_determine_rate(void)
// callers: [clk_rcg_determine_rate, clk_dyn_rcg_determine_rate]
//------------------------------------------------------------

int _freq_tbl_determine_rate(undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  
  lVar7 = *param_3;
  plVar3 = (long *)qcom_find_freq(param_2,lVar7);
  if (plVar3 != (long *)0x0) {
    iVar1 = qcom_find_src_index(param_1,param_4,(char)plVar3[1]);
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar2 = clk_hw_get_flags(param_1);
    lVar4 = clk_hw_get_parent_by_index(param_1,iVar1);
    if (lVar4 != 0) {
      if ((uVar2 >> 2 & 1) == 0) {
        uVar5 = clk_hw_get_rate(lVar4);
      }
      else {
        uVar5 = lVar7 * (ulong)*(byte *)((long)plVar3 + 9);
        if ((ulong)*(ushort *)((long)plVar3 + 0xc) != 0) {
          uVar6 = uVar5 * *(ushort *)((long)plVar3 + 0xc);
          uVar5 = 0;
          if ((ulong)*(ushort *)((long)plVar3 + 10) != 0) {
            uVar5 = uVar6 / *(ushort *)((long)plVar3 + 10);
          }
        }
      }
      param_3[3] = uVar5;
      param_3[4] = lVar4;
      *param_3 = *plVar3;
      return 0;
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// __clk_rcg_set_rate @ 00111d88 size=648
// signature: undefined __clk_rcg_set_rate(void)
// callers: [clk_rcg_set_floor_rate, clk_rcg_set_rate, clk_rcg_bypass2_set_rate, clk_rcg_esc_set_rate, clk_rcg_lcc_set_rate, clk_rcg_bypass_set_rate, clk_rcg_pixel_set_rate]
//------------------------------------------------------------

void __clk_rcg_set_rate(int *param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  uint local_44;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  lVar1 = 0;
  if (*(char *)((long)param_1 + 0xe) != '\0') {
    lVar1 = 0x50;
  }
  uVar2 = *(undefined4 *)((long)param_1 + lVar1);
  if (*(char *)((long)param_1 + 0xd) == '\0') {
    regmap_read(*(undefined8 *)(param_1 + 0x12),*param_1,&local_3c);
    uVar6 = 0;
  }
  else {
    uVar6 = 1L << ((ulong)*(byte *)((long)param_1 + 9) & 0x3f);
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x12),uVar2,uVar6 & 0xffffffff,uVar6 & 0xffffffff,0,0,0);
    regmap_read(*(undefined8 *)(param_1 + 0x12),param_1[1],&local_40);
    uVar5 = (uint)(-1L << ((ulong)*(byte *)((long)param_1 + 0xd) & 0x3f));
    uVar4 = ~uVar5;
    local_40 = local_40 & (uVar4 << (ulong)(*(byte *)(param_1 + 3) & 0x1f) ^ 0xffffffff) & uVar5;
    if (*(ushort *)(param_2 + 0xc) != 0) {
      local_40 = uVar4 & (*(ushort *)(param_2 + 0xc) ^ 0xffffffff) |
                 (uint)*(ushort *)(param_2 + 10) << (ulong)(*(byte *)(param_1 + 3) & 0x1f) |
                 local_40;
    }
    regmap_write(*(undefined8 *)(param_1 + 0x12),param_1[1]);
    regmap_read(*(undefined8 *)(param_1 + 0x12),*param_1,&local_3c);
    if (param_1[0x14] == *param_1) {
      uVar3 = *(ushort *)(param_2 + 0xc);
      uVar5 = (uint)(1L << ((ulong)*(byte *)(param_1 + 2) & 0x3f));
      uVar4 = 0;
      if (uVar3 != 0) {
        uVar4 = 2 << (ulong)(*(byte *)((long)param_1 + 10) & 0x1f) | uVar5;
      }
      local_3c = local_3c &
                 ((3 << (ulong)(*(byte *)((long)param_1 + 10) & 0x1f) | uVar5) ^ 0xffffffff) | uVar4
      ;
    }
    else {
      regmap_read(*(undefined8 *)(param_1 + 0x12),param_1[0x14],&local_44);
      uVar5 = (uint)(1L << ((ulong)*(byte *)(param_1 + 2) & 0x3f));
      uVar4 = 0;
      if (*(short *)(param_2 + 0xc) != 0) {
        uVar4 = 2 << (ulong)(*(byte *)((long)param_1 + 10) & 0x1f) | uVar5;
      }
      local_44 = local_44 &
                 ((3 << (ulong)(*(byte *)((long)param_1 + 10) & 0x1f) | uVar5) ^ 0xffffffff) | uVar4
      ;
      regmap_write(*(undefined8 *)(param_1 + 0x12),param_1[0x14]);
      uVar3 = *(ushort *)(param_2 + 0xc);
    }
    uVar4 = ~(uint)(-1L << ((ulong)*(byte *)((long)param_1 + 0xd) & 0x3f));
    local_3c = local_3c & (uVar4 << (ulong)(*(byte *)((long)param_1 + 0xb) & 0x1f) ^ 0xffffffff);
    if (uVar3 != 0) {
      local_3c = ((uint)*(ushort *)(param_2 + 10) + ~(uint)uVar3 & uVar4) <<
                 (ulong)(*(byte *)((long)param_1 + 0xb) & 0x1f) | local_3c;
    }
  }
  local_3c = local_3c &
             (~(uint)(-1L << ((ulong)*(byte *)(param_1 + 4) & 0x3f)) <<
              (ulong)(*(byte *)((long)param_1 + 0xf) & 0x1f) ^ 0xffffffff) |
             (*(byte *)(param_2 + 9) - 1 & 0xff) << (ulong)(*(byte *)((long)param_1 + 0xf) & 0x1f);
  regmap_write(*(undefined8 *)(param_1 + 0x12),*param_1);
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x12),uVar2,uVar6 & 0xffffffff,0,0,0,0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// configure_bank @ 00112010 size=876
// signature: undefined configure_bank(void)
// callers: [clk_dyn_rcg_set_parent, clk_dyn_rcg_set_rate_and_parent, clk_dyn_rcg_set_rate]
//------------------------------------------------------------

void configure_bank(int *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint local_74;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  cVar3 = *(char *)((long)param_1 + 0x21);
  local_6c = 0;
  cVar4 = *(char *)((long)param_1 + 0x26);
  local_74 = 0;
  local_70 = 0;
  uVar6 = __clk_is_enabled(*(undefined8 *)(param_1 + 0x16));
  uVar7 = regmap_read(*(undefined8 *)(param_1 + 0x1a),param_1[4],&local_74);
  if ((int)uVar7 == 0) {
    uVar13 = (ulong)(uVar6 ^ (local_74 & (uint)(1L << ((ulong)*(byte *)(param_1 + 5) & 0x3f))) != 0)
             & 1;
    iVar2 = param_1[uVar13];
    uVar7 = regmap_read(*(undefined8 *)(param_1 + 0x1a),iVar2,&local_6c);
    if ((int)uVar7 == 0) {
      if (cVar3 != '\0') {
        pbVar14 = (byte *)((long)param_1 + uVar13 * 7 + 0x16);
        iVar1 = param_1[uVar13 + 2];
        local_6c = local_6c | (uint)(1L << ((ulong)*pbVar14 & 0x3f));
        uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),iVar2);
        if (((int)uVar7 != 0) ||
           (uVar7 = regmap_read(*(undefined8 *)(param_1 + 0x1a),iVar1,&local_70), (int)uVar7 != 0))
        goto LAB_001120b0;
        pbVar15 = (byte *)((long)param_1 + uVar13 * 7 + 0x1a);
        uVar10 = (uint)(-1L << ((ulong)*pbVar15 & 0x3f));
        uVar11 = ~uVar10;
        uVar9 = (uint)*(byte *)((long)param_1 + uVar13 * 7 + 0x19);
        local_70 = local_70 & (uVar11 << (ulong)(uVar9 & 0x1f) ^ 0xffffffff) & uVar10;
        if (*(ushort *)(param_2 + 0xc) != 0) {
          local_70 = uVar11 & (*(ushort *)(param_2 + 0xc) ^ 0xffffffff) |
                     (uint)*(ushort *)(param_2 + 10) << (ulong)(uVar9 & 0x1f) | local_70;
        }
        uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),iVar1);
        if ((int)uVar7 != 0) goto LAB_001120b0;
        uVar11 = ~(uint)(-1L << ((ulong)*pbVar15 & 0x3f));
        uVar9 = (uint)*(byte *)((long)param_1 + uVar13 * 7 + 0x18);
        local_6c = local_6c & (uVar11 << (ulong)(uVar9 & 0x1f) ^ 0xffffffff);
        if (*(ushort *)(param_2 + 0xc) != 0) {
          local_6c = ((uint)*(ushort *)(param_2 + 10) + ~(uint)*(ushort *)(param_2 + 0xc) & uVar11)
                     << (ulong)(uVar9 & 0x1f) | local_6c;
        }
        uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),iVar2);
        if ((int)uVar7 != 0) goto LAB_001120b0;
        uVar12 = (uint)*(byte *)((long)param_1 + uVar13 * 7 + 0x17);
        uVar10 = (uint)(1L << ((ulong)*(byte *)((long)param_1 + uVar13 * 7 + 0x15) & 0x3f));
        uVar9 = ~(3 << (ulong)(uVar12 & 0x1f) | uVar10);
        uVar11 = 0;
        if (*(short *)(param_2 + 0xc) != 0) {
          uVar11 = 2 << (ulong)(uVar12 & 0x1f) | uVar10;
        }
        if (*param_1 == param_1[1]) {
          uVar8 = *(undefined8 *)(param_1 + 0x1a);
          local_74 = local_74 & uVar9 | uVar11;
          iVar1 = param_1[4];
        }
        else {
          uVar8 = *(undefined8 *)(param_1 + 0x1a);
          local_6c = local_6c & uVar9 | uVar11;
          iVar1 = iVar2;
        }
        uVar7 = regmap_write(uVar8,iVar1);
        if ((int)uVar7 != 0) goto LAB_001120b0;
        local_6c = local_6c & ((uint)(1L << ((ulong)*pbVar14 & 0x3f)) ^ 0xffffffff);
        uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),iVar2);
        if ((int)uVar7 != 0) goto LAB_001120b0;
      }
      if (cVar4 != '\0') {
        uVar11 = (uint)*(byte *)((long)param_1 + uVar13 * 2 + 0x23);
        local_6c = local_6c &
                   (~(uint)(-1L << ((ulong)*(byte *)((long)param_1 + uVar13 * 2 + 0x24) & 0x3f)) <<
                    (ulong)(uVar11 & 0x1f) ^ 0xffffffff) |
                   (*(byte *)(param_2 + 9) - 1 & 0xff) << (ulong)(uVar11 & 0x1f);
      }
      uVar7 = qcom_find_src_index(param_1 + 0x14,*(long *)(param_1 + uVar13 * 4 + 0xc),
                                  *(undefined1 *)(param_2 + 8));
      if (-1 < (int)uVar7) {
        local_6c = local_6c &
                   (7 << (ulong)(*(byte *)(param_1 + uVar13 * 4 + 10) & 0x1f) ^ 0xffffffffU) |
                   (uint)*(byte *)(*(long *)(param_1 + uVar13 * 4 + 0xc) + (uVar7 & 0xffffffff) * 2
                                  + 1) << (ulong)(*(byte *)(param_1 + uVar13 * 4 + 10) & 0x1f);
        uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),iVar2);
        if ((int)uVar7 == 0) {
          if ((uVar6 & 1) != 0) {
            uVar7 = regmap_read(*(undefined8 *)(param_1 + 0x1a),param_1[4],&local_74);
            if ((int)uVar7 != 0) goto LAB_001120b0;
            local_74 = local_74 ^ (uint)(1L << ((ulong)*(byte *)(param_1 + 5) & 0x3f));
            uVar7 = regmap_write(*(undefined8 *)(param_1 + 0x1a),param_1[4]);
            if ((int)uVar7 != 0) goto LAB_001120b0;
          }
          uVar7 = 0;
        }
      }
    }
  }
LAB_001120b0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_enable @ 00112380 size=204
// signature: undefined clk_rcg2_enable(void)
// callers: []
//------------------------------------------------------------

undefined4 clk_rcg2_enable(long param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((*(byte *)(param_1 + 0x91) & 1) != 0) {
    clk_rcg2_set_force_enable(param_1);
  }
  if (*(char *)(param_1 + -8) == '\0') {
    uVar2 = 0;
  }
  else {
    lVar4 = *(long *)(param_1 + -0x10);
    puVar3 = (undefined8 *)qcom_find_freq(*(undefined8 *)(param_1 + -0x20),lVar4);
    if (puVar3 == (undefined8 *)0x0) {
      uVar2 = 0xffffffea;
    }
    else {
      puVar1 = &cxo_f;
      if (lVar4 != cxo_f) {
        puVar1 = puVar3;
      }
      if ((*(byte *)(param_1 + 0x91) & 1) == 0) {
        clk_rcg2_set_force_enable(param_1);
      }
      uVar2 = clk_rcg2_configure(param_1 + -0x30,puVar1);
      if ((*(byte *)(param_1 + 0x91) & 1) == 0) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,0,0,0,0);
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_rcg2_disable @ 00112450 size=144
// signature: undefined clk_rcg2_disable(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_disable(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + -8) == '\0') {
    if ((*(byte *)(param_1 + 0x91) & 1) == 0) {
      return;
    }
  }
  else {
    clk_rcg2_set_force_enable(param_1);
    iVar1 = clk_rcg2_configure(param_1 + -0x30,&cxo_f);
    if (iVar1 != 0) {
      uVar2 = clk_hw_get_name(param_1);
      _printk(&DAT_0011cd39,uVar2);
    }
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,0,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_rcg2_is_enabled @ 001124e4 size=112
// signature: undefined clk_rcg2_is_enabled(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_is_enabled(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint local_1c;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_1c = 0;
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_1c);
  lVar2 = sp_el0;
  uVar1 = ~local_1c >> 0x1f;
  if (uVar3 != 0) {
    uVar1 = uVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_recalc_rate @ 00112558 size=132
// signature: undefined clk_rcg2_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_recalc_rate(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),
              *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,&local_2c);
  __clk_rcg2_recalc_rate(param_1,param_2,local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_determine_rate @ 001125e0 size=40
// signature: undefined clk_rcg2_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_determine_rate(long param_1,undefined8 param_2)

{
  _freq_tbl_determine_rate(param_1,*(undefined8 *)(param_1 + -0x20),param_2,1);
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_parent @ 0011260c size=104
// signature: undefined clk_rcg2_set_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_parent(long param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),
                     *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,0x700,
                     (ulong)*(byte *)(*(long *)(param_1 + -0x28) + (ulong)param_2 * 2 + 1) << 8,0,0,
                     0);
  if (iVar1 == 0) {
    update_config((int *)(param_1 + -0x30));
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_get_parent @ 00112678 size=200
// signature: undefined clk_rcg2_get_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_get_parent(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  byte *pbVar6;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                      *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,&local_2c);
  uVar2 = local_2c;
  uVar5 = 0;
  if (iVar3 == 0) {
    uVar4 = clk_hw_get_num_parents(param_1);
    if (0 < (int)uVar4) {
      uVar5 = 0;
      pbVar6 = (byte *)(*(long *)(param_1 + -0x28) + 1);
      do {
        if ((uVar2 >> 8 & 7) == (uint)*pbVar6) goto LAB_00112714;
        uVar5 = uVar5 + 1;
        pbVar6 = pbVar6 + 2;
      } while (uVar4 != uVar5);
    }
    uVar5 = 0;
  }
LAB_00112714:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_rate @ 00112744 size=32
// signature: undefined clk_rcg2_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_rate(undefined8 param_1,undefined8 param_2)

{
  __clk_rcg2_set_rate(param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_rate_and_parent @ 00112768 size=32
// signature: undefined clk_rcg2_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_rate_and_parent(undefined8 param_1,undefined8 param_2)

{
  __clk_rcg2_set_rate(param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// clk_rcg2_get_duty_cycle @ 0011278c size=268
// signature: undefined clk_rcg2_get_duty_cycle(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_get_duty_cycle(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint local_34;
  int iStack_30;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  local_34 = 0;
  iStack_30 = 0;
  if (*(char *)(param_1 + -0x2c) != '\0') {
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 0x10,&local_34);
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 8,&iStack_30);
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 0xc,&local_2c);
    if (((local_34 != 0) || (iStack_30 != 0)) || (local_2c != 0)) {
      uVar3 = (uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2c) & 0x3f));
      uVar1 = iStack_30 + ~local_2c & (uVar3 ^ 0xffffffff);
      uVar3 = (~uVar3 & (local_34 ^ 0xffffffff)) + 1 >> 1;
      goto LAB_00112860;
    }
  }
  uVar1 = 2;
  uVar3 = 1;
LAB_00112860:
  *param_2 = uVar3;
  lVar2 = sp_el0;
  lVar2 = *(long *)(lVar2 + 0x638);
  param_2[1] = uVar1;
  if (lVar2 != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_rcg2_set_duty_cycle @ 0011289c size=388
// signature: undefined clk_rcg2_set_duty_cycle(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_duty_cycle(long param_1,int *param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint local_44;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  bVar2 = *(byte *)(param_1 + -0x2c);
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  if ((ulong)bVar2 != 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 0xc,&local_3c);
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 8,&local_40);
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,&local_44);
    if ((local_44 & 0x3000) != 0) {
      uVar8 = (uint)(-1L << ((ulong)bVar2 & 0x3f));
      uVar4 = 0;
      if (param_2[1] != 0) {
        uVar4 = (uint)(*param_2 * 100) / (uint)param_2[1];
      }
      uVar1 = local_40 + ~local_3c & (uVar8 ^ 0xffffffff);
      uVar3 = uVar1 - local_40;
      uVar4 = uVar1 * uVar4 * 2 + 0x32;
      uVar7 = uVar4 / 100;
      uVar1 = uVar7;
      if (uVar4 < 200) {
        uVar1 = 1;
      }
      if (~uVar8 <= uVar7) {
        uVar1 = ~uVar8;
      }
      uVar4 = local_40;
      if (local_40 >> 1 <= uVar1 >> 1) {
        uVar4 = uVar1;
      }
      uVar7 = uVar3 * 2;
      if (uVar1 >> 1 <= uVar3) {
        uVar7 = uVar4;
      }
      uVar6 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 0x10,~uVar8,
                         ~uVar7 & (uVar8 ^ 0xffffffff),0,0,0);
      if ((int)uVar6 == 0) {
        uVar6 = update_config(param_1 + -0x30);
      }
      goto LAB_001129f0;
    }
  }
  uVar6 = 0xffffffea;
LAB_001129f0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_init @ 00112a24 size=36
// signature: undefined clk_rcg2_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_rcg2_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_rcg2_determine_floor_rate @ 00112a4c size=40
// signature: undefined clk_rcg2_determine_floor_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_determine_floor_rate(long param_1,undefined8 param_2)

{
  _freq_tbl_determine_rate(param_1,*(undefined8 *)(param_1 + -0x20),param_2,0);
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_floor_rate @ 00112a78 size=32
// signature: undefined clk_rcg2_set_floor_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_floor_rate(undefined8 param_1,undefined8 param_2)

{
  __clk_rcg2_set_rate(param_1,param_2,0);
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_floor_rate_and_parent @ 00112a9c size=32
// signature: undefined clk_rcg2_set_floor_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_set_floor_rate_and_parent(undefined8 param_1,undefined8 param_2)

{
  __clk_rcg2_set_rate(param_1,param_2,0);
  return;
}



//------------------------------------------------------------
// clk_edp_pixel_determine_rate @ 00112ac0 size=376
// signature: undefined clk_edp_pixel_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_edp_pixel_determine_rate(long param_1,ulong *param_2)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  bVar3 = *(byte *)(param_1 + -0x2b);
  uVar8 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x28),
                              *(undefined1 *)(*(long *)(param_1 + -0x20) + 8));
  uVar9 = clk_hw_get_parent_by_index(param_1,uVar8);
  param_2[4] = uVar9;
  if (uVar9 != 0) {
    uVar9 = clk_hw_get_rate();
    param_2[3] = uVar9;
    puVar2 = &frac_table_810m;
    if (uVar9 != 810000000) {
      puVar2 = &frac_table_675m;
    }
    uVar12 = *puVar2;
    if (uVar12 != 0) {
      do {
        uVar4 = puVar2[1];
        lVar5 = 0;
        if ((long)(int)uVar12 != 0) {
          lVar5 = (long)(*param_2 * (long)(int)uVar4) / (long)(int)uVar12;
        }
        if (lVar5 - 100000U <= uVar9 && uVar9 <= lVar5 + 100000U) {
          uVar13 = (ulong)uVar4;
          regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_4c);
          uVar1 = local_4c & ~(uint)(-1L << ((ulong)bVar3 & 0x3f));
          uVar9 = param_2[3];
          if (uVar1 != 0) {
            uVar11 = (ulong)(uVar1 + 1);
            uVar6 = 0;
            if (uVar11 != 0) {
              uVar6 = uVar9 / uVar11;
            }
            uVar7 = 0;
            if (uVar11 != 0) {
              uVar7 = ((uVar9 - uVar6 * uVar11) * 2) / uVar11;
            }
            uVar9 = uVar7 + uVar6 * 2;
          }
          if (uVar4 != 0) {
            uVar6 = 0;
            if (uVar13 != 0) {
              uVar6 = uVar9 / uVar13;
            }
            uVar11 = 0;
            if (uVar13 != 0) {
              uVar11 = ((uVar9 - uVar6 * uVar13) * (ulong)uVar12) / uVar13;
            }
            uVar9 = uVar11 + uVar6 * uVar12;
          }
          uVar10 = 0;
          *param_2 = uVar9;
          goto LAB_00112b9c;
        }
        uVar12 = puVar2[2];
        puVar2 = puVar2 + 2;
      } while (uVar12 != 0);
    }
  }
  uVar10 = 0xffffffea;
LAB_00112b9c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// clk_edp_pixel_set_rate @ 00112c3c size=292
// signature: undefined clk_edp_pixel_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_edp_pixel_set_rate(long param_1,long param_2,long param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + -0x20);
  local_54 = 0;
  piVar1 = &frac_table_810m;
  if (param_3 != 810000000) {
    piVar1 = &frac_table_675m;
  }
  local_50 = *puVar6;
  uStack_48 = puVar6[1];
  local_40 = puVar6[2];
  iVar7 = *piVar1;
  bVar2 = *(byte *)(param_1 + -0x2b);
  if (iVar7 != 0) {
    do {
      iVar3 = piVar1[1];
      lVar4 = 0;
      if ((long)iVar7 != 0) {
        lVar4 = (iVar3 * param_2) / (long)iVar7;
      }
      if (lVar4 + -100000 <= param_3 && param_3 <= lVar4 + 100000) {
        regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_54);
        uVar5 = uStack_48;
        uStack_48._6_2_ = SUB82(uVar5,6);
        uStack_48._0_6_ = CONCAT24((short)iVar3,iVar7 << 0x10);
        uStack_48._0_2_ =
             CONCAT11((byte)local_54 & ~(byte)(-1L << ((ulong)bVar2 & 0x3f)),(char)uVar5);
        uVar5 = clk_rcg2_configure(param_1 + -0x30,&local_50);
        goto LAB_00112d30;
      }
      iVar7 = piVar1[2];
      piVar1 = piVar1 + 2;
    } while (iVar7 != 0);
  }
  uVar5 = 0xffffffea;
LAB_00112d30:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_edp_pixel_set_rate_and_parent @ 00112d64 size=292
// signature: undefined clk_edp_pixel_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_edp_pixel_set_rate_and_parent(long param_1,long param_2,long param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + -0x20);
  local_54 = 0;
  piVar1 = &frac_table_810m;
  if (param_3 != 810000000) {
    piVar1 = &frac_table_675m;
  }
  local_50 = *puVar6;
  uStack_48 = puVar6[1];
  local_40 = puVar6[2];
  iVar7 = *piVar1;
  bVar2 = *(byte *)(param_1 + -0x2b);
  if (iVar7 != 0) {
    do {
      iVar3 = piVar1[1];
      lVar4 = 0;
      if ((long)iVar7 != 0) {
        lVar4 = (iVar3 * param_2) / (long)iVar7;
      }
      if (lVar4 + -100000 <= param_3 && param_3 <= lVar4 + 100000) {
        regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_54);
        uVar5 = uStack_48;
        uStack_48._6_2_ = SUB82(uVar5,6);
        uStack_48._0_6_ = CONCAT24((short)iVar3,iVar7 << 0x10);
        uStack_48._0_2_ =
             CONCAT11((byte)local_54 & ~(byte)(-1L << ((ulong)bVar2 & 0x3f)),(char)uVar5);
        uVar5 = clk_rcg2_configure(param_1 + -0x30,&local_50);
        goto LAB_00112e58;
      }
      iVar7 = piVar1[2];
      piVar1 = piVar1 + 2;
    } while (iVar7 != 0);
  }
  uVar5 = 0xffffffea;
LAB_00112e58:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_byte_determine_rate @ 00112e8c size=192
// signature: undefined clk_byte_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_byte_determine_rate(long param_1,ulong *param_2)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  
  uVar4 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x28),
                              *(undefined1 *)(*(long *)(param_1 + -0x20) + 8));
  if (*param_2 != 0) {
    bVar1 = *(byte *)(param_1 + -0x2b);
    uVar5 = clk_hw_get_parent_by_index(param_1,uVar4);
    param_2[4] = uVar5;
    if (uVar5 != 0) {
      uVar5 = clk_hw_round_rate(uVar5,*param_2);
      uVar6 = *param_2;
      param_2[3] = uVar5;
      iVar2 = 0;
      if (uVar6 != 0) {
        iVar2 = (int)(((uVar6 + uVar5 * 2) - 1) / uVar6);
      }
      uVar8 = (uint)(-1L << ((ulong)bVar1 & 0x3f));
      if (uVar8 <= (uint)-iVar2) {
        uVar8 = -iVar2;
      }
      if (uVar8 != 0xffffffff) {
        uVar7 = (ulong)-uVar8;
        uVar6 = 0;
        if (uVar7 != 0) {
          uVar6 = uVar5 / uVar7;
        }
        uVar3 = 0;
        if (uVar7 != 0) {
          uVar3 = ((uVar5 - uVar6 * uVar7) * 2) / uVar7;
        }
        uVar5 = uVar3 + uVar6 * 2;
      }
      *param_2 = uVar5;
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// clk_byte_set_rate @ 00112f50 size=144
// signature: undefined clk_byte_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_byte_set_rate(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 local_30;
  undefined1 uStack_28;
  byte local_27;
  undefined6 uStack_26;
  undefined8 local_20;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = (int)(((param_2 + param_3 * 2) - 1) / param_2);
  }
  puVar4 = *(undefined8 **)(param_1 + -0x20);
  uVar3 = (uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f));
  local_30 = *puVar4;
  if (uVar3 <= (uint)-iVar1) {
    uVar3 = -iVar1;
  }
  local_20 = puVar4[2];
  uStack_26 = (undefined6)((ulong)puVar4[1] >> 0x10);
  _uStack_28 = CONCAT11(~(byte)uVar3,(char)puVar4[1]);
  clk_rcg2_configure(param_1 + -0x30,&local_30);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_byte_set_rate_and_parent @ 00112fe4 size=144
// signature: undefined clk_byte_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_byte_set_rate_and_parent(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 local_30;
  undefined1 uStack_28;
  byte local_27;
  undefined6 uStack_26;
  undefined8 local_20;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = (int)(((param_2 + param_3 * 2) - 1) / param_2);
  }
  puVar4 = *(undefined8 **)(param_1 + -0x20);
  uVar3 = (uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f));
  local_30 = *puVar4;
  if (uVar3 <= (uint)-iVar1) {
    uVar3 = -iVar1;
  }
  local_20 = puVar4[2];
  uStack_26 = (undefined6)((ulong)puVar4[1] >> 0x10);
  _uStack_28 = CONCAT11(~(byte)uVar3,(char)puVar4[1]);
  clk_rcg2_configure(param_1 + -0x30,&local_30);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_byte2_determine_rate @ 00113078 size=160
// signature: undefined clk_byte2_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_byte2_determine_rate(long param_1,ulong *param_2)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  
  uVar5 = 0xffffffea;
  if ((param_2[4] != 0) && (uVar7 = *param_2, uVar7 != 0)) {
    bVar1 = *(byte *)(param_1 + -0x2b);
    uVar4 = clk_hw_round_rate(param_2[4],uVar7);
    param_2[3] = uVar4;
    iVar2 = 0;
    if (uVar7 != 0) {
      iVar2 = (int)(((uVar7 + uVar4 * 2) - 1) / uVar7);
    }
    uVar8 = (uint)(-1L << ((ulong)bVar1 & 0x3f));
    if (uVar8 <= (uint)-iVar2) {
      uVar8 = -iVar2;
    }
    if (uVar8 != 0xffffffff) {
      uVar6 = (ulong)-uVar8;
      uVar7 = 0;
      if (uVar6 != 0) {
        uVar7 = uVar4 / uVar6;
      }
      uVar3 = 0;
      if (uVar6 != 0) {
        uVar3 = ((uVar4 - uVar7 * uVar6) * 2) / uVar6;
      }
      uVar4 = uVar3 + uVar7 * 2;
    }
    uVar5 = 0;
    *param_2 = uVar4;
  }
  return uVar5;
}



//------------------------------------------------------------
// clk_byte2_set_rate @ 0011311c size=268
// signature: undefined clk_byte2_set_rate(void)
// callers: [clk_byte2_set_rate_and_parent]
//------------------------------------------------------------

void clk_byte2_set_rate(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  byte *pbVar6;
  ulong uVar7;
  uint local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  uVar3 = clk_hw_get_num_parents();
  uVar7 = (ulong)uVar3;
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = (int)(((param_2 + param_3 * 2) - 1) / param_2);
  }
  local_54 = 0;
  uVar5 = (uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f));
  if (uVar5 <= (uint)-iVar1) {
    uVar5 = -iVar1;
  }
  local_48._0_2_ = CONCAT11(~(byte)uVar5,(undefined1)local_48);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_54);
  local_54 = local_54 >> 8 & 7;
  if (0 < (int)uVar3) {
    pbVar6 = (byte *)(*(long *)(param_1 + -0x28) + 1);
    do {
      if (local_54 == *pbVar6) {
        local_48 = CONCAT71(local_48._1_7_,pbVar6[-1]);
        uVar4 = clk_rcg2_configure((int *)(param_1 + -0x30),&local_50);
        goto LAB_001131f8;
      }
      pbVar6 = pbVar6 + 2;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  uVar4 = 0xffffffea;
LAB_001131f8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_byte2_set_rate_and_parent @ 0011322c size=28
// signature: undefined clk_byte2_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_byte2_set_rate_and_parent(void)

{
  clk_byte2_set_rate();
  return;
}



//------------------------------------------------------------
// clk_pixel_determine_rate @ 0011324c size=524
// signature: undefined clk_pixel_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_pixel_determine_rate(undefined8 param_1,ulong *param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  if (param_2[4] == 0) {
    return 0xffffffea;
  }
  uVar3 = (*param_2 << 3) / 3;
  uVar1 = clk_hw_round_rate(param_2[4],uVar3);
  if (uVar1 < uVar3 - 100000 || uVar3 + 100000 < uVar1) {
    uVar3 = *param_2 * 9 >> 1;
    uVar1 = clk_hw_round_rate(param_2[4],uVar3);
    if ((uVar1 < uVar3 - 100000) || (uVar3 + 100000 < uVar1)) {
      uVar3 = *param_2 * 9 >> 2;
      uVar1 = clk_hw_round_rate(param_2[4],uVar3);
      if ((uVar1 < uVar3 - 100000) || (uVar3 + 100000 < uVar1)) {
        uVar3 = *param_2;
        uVar1 = clk_hw_round_rate(param_2[4],uVar3);
        if ((uVar3 - 100000 <= uVar1) && (uVar1 <= uVar3 + 100000)) {
          lVar2 = 1;
          uVar3 = 1;
          goto LAB_001133e8;
        }
        uVar3 = *param_2 * 3 >> 1;
        uVar1 = clk_hw_round_rate(param_2[4],uVar3);
        if ((uVar3 - 100000 <= uVar1) && (uVar1 <= uVar3 + 100000)) {
          uVar3 = 3;
          lVar2 = 2;
          goto LAB_001133e8;
        }
        uVar3 = 0x23;
        uVar4 = *param_2 * 0x23 >> 4;
        uVar1 = clk_hw_round_rate(param_2[4],uVar4);
        if ((uVar4 - 100000 <= uVar1) && (uVar1 <= uVar4 + 100000)) {
          lVar2 = 0x10;
          goto LAB_001133e8;
        }
        uVar3 = *param_2 * 0xf >> 2;
        uVar1 = clk_hw_round_rate(param_2[4],uVar3);
        if (uVar1 < uVar3 - 100000) {
          return 0xffffffea;
        }
        if (uVar3 + 100000 < uVar1) {
          return 0xffffffea;
        }
        uVar3 = 0xf;
      }
      else {
        uVar3 = 9;
      }
      lVar2 = 4;
    }
    else {
      uVar3 = 9;
      lVar2 = 2;
    }
  }
  else {
    uVar3 = 8;
    lVar2 = 3;
  }
LAB_001133e8:
  param_2[3] = uVar1;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = (uVar1 * lVar2) / uVar3;
  }
  *param_2 = uVar4;
  return 0;
}



//------------------------------------------------------------
// clk_pixel_set_rate @ 0011345c size=604
// signature: undefined clk_pixel_set_rate(void)
// callers: [clk_pixel_set_rate_and_parent]
//------------------------------------------------------------

void clk_pixel_set_rate(long param_1,long param_2,ulong param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte *pbVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  ulong uVar9;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  bVar1 = *(byte *)(param_1 + -0x2b);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar4 = clk_hw_get_num_parents();
  uVar9 = (ulong)uVar4;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_68);
  uVar2 = (uint)local_68 >> 8;
  local_68 = CONCAT44(local_68._4_4_,uVar2) & 0xffffffff00000007;
  if (0 < (int)uVar4) {
    pbVar6 = (byte *)(*(long *)(param_1 + -0x28) + 1);
    do {
      if ((uVar2 & 7) == (uint)*pbVar6) {
        local_58 = CONCAT71(local_58._1_7_,pbVar6[-1]);
        break;
      }
      pbVar6 = pbVar6 + 2;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  uVar9 = (ulong)(param_2 << 3) / 3;
  if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) {
    uVar9 = (ulong)(param_2 * 9) >> 1;
    if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) {
      uVar9 = (ulong)(param_2 * 9) >> 2;
      if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) {
        if ((param_3 < param_2 - 100000U) || (param_2 + 100000U < param_3)) {
          uVar9 = (ulong)(param_2 * 3) >> 1;
          if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) {
            uVar8 = 0x23;
            uVar9 = (ulong)(param_2 * 0x23) >> 4;
            if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) {
              uVar5 = 0xffffffea;
              uVar9 = (ulong)(param_2 * 0xf) >> 2;
              if ((param_3 < uVar9 - 100000) || (uVar9 + 100000 < param_3)) goto LAB_00113654;
              uVar8 = 0xf;
              goto LAB_00113594;
            }
            uVar7 = 0x10;
          }
          else {
            uVar8 = 3;
            uVar7 = 2;
          }
        }
        else {
          uVar7 = 1;
          uVar8 = 1;
        }
      }
      else {
        uVar8 = 9;
LAB_00113594:
        uVar7 = 4;
      }
    }
    else {
      uVar8 = 9;
      uVar7 = 2;
    }
  }
  else {
    uVar8 = 8;
    uVar7 = 3;
  }
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,(long)&local_68 + 4);
  local_58 = CONCAT62(CONCAT24(local_58._6_2_,CONCAT22(uVar8,uVar7)),
                      CONCAT11((byte)(local_68 >> 0x20) & ~(byte)(-1L << ((ulong)bVar1 & 0x3f)),
                               (undefined1)local_58));
  uVar5 = clk_rcg2_configure((int *)(param_1 + -0x30),&uStack_60);
LAB_00113654:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_pixel_set_rate_and_parent @ 001136bc size=28
// signature: undefined clk_pixel_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_pixel_set_rate_and_parent(void)

{
  clk_pixel_set_rate();
  return;
}



//------------------------------------------------------------
// clk_gfx3d_determine_rate @ 001136dc size=400
// signature: undefined clk_gfx3d_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_gfx3d_determine_rate(long param_1,ulong *param_2)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong local_80;
  ulong local_78;
  ulong local_70 [4];
  
  lVar2 = sp_el0;
  local_70[3] = *(long *)(lVar2 + 0x638);
  puVar7 = *(ulong **)(param_1 + 0xa0);
  local_70[1] = 0;
  local_70[2] = 0;
  local_78 = 0;
  local_70[0] = 0xffffffffffffffff;
  uVar8 = *puVar7;
  if (((uVar8 == 0) || (uVar11 = puVar7[1], uVar11 == 0)) || (uVar9 = puVar7[2], uVar9 == 0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x113868);
    (*pcVar3)();
  }
  bVar1 = *(byte *)(param_1 + -0x38);
  uVar4 = clk_hw_get_parent_by_index(param_1,0);
  if (uVar4 == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    uVar12 = *param_2;
    uVar5 = clk_hw_get_rate();
    if (uVar12 == uVar5) {
      uVar6 = 0;
      param_2[4] = uVar4;
    }
    else {
      uVar10 = (uint)bVar1;
      if (uVar10 == 0) {
        uVar10 = 1;
      }
      uVar5 = (ulong)uVar10;
      uVar12 = *param_2 * uVar5;
      local_80 = uVar12;
      uVar4 = clk_hw_get_rate(uVar8);
      if (uVar12 == uVar4) {
        uVar6 = 0;
        *param_2 = uVar12;
        param_2[3] = uVar12;
        param_2[4] = uVar8;
      }
      else {
        if (param_2[4] == uVar8) {
          uVar4 = clk_hw_get_rate(uVar9);
          uVar8 = uVar9;
          if (uVar4 != uVar12) {
            uVar8 = uVar11;
          }
        }
        else {
          uVar8 = uVar11;
          if (param_2[4] != uVar9) {
            uVar8 = uVar9;
          }
        }
        param_2[4] = uVar8;
        clk_hw_get_rate_range(uVar8,&local_78,local_70);
        if (local_78 < param_2[1]) {
          local_78 = param_2[1];
        }
        if (param_2[2] < local_70[0]) {
          local_70[0] = param_2[2];
        }
        uVar6 = __clk_determine_rate(param_2[4],&local_80);
        if ((int)uVar6 == 0) {
          uVar8 = 0;
          if (uVar5 != 0) {
            uVar8 = local_80 / uVar5;
          }
          param_2[3] = local_80;
          *param_2 = uVar8;
        }
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_70[3]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// clk_gfx3d_set_rate @ 00113874 size=8
// signature: undefined clk_gfx3d_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_gfx3d_set_rate(void)

{
  return 0;
}



//------------------------------------------------------------
// clk_gfx3d_set_rate_and_parent @ 00113880 size=100
// signature: undefined clk_gfx3d_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_gfx3d_set_rate_and_parent(long param_1,undefined8 param_2,undefined8 param_3,byte param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(byte *)(param_1 + -0x38) * 2 - 1;
  if (*(byte *)(param_1 + -0x38) < 2) {
    uVar1 = 0;
  }
  iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,
                       uVar1 | (uint)*(byte *)(*(long *)(param_1 + -0x28) + (ulong)param_4 * 2 + 1)
                               << 8);
  if (iVar2 == 0) {
    update_config((int *)(param_1 + -0x30));
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_enable @ 001138e8 size=112
// signature: undefined clk_rcg2_shared_enable(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_shared_enable(long param_1)

{
  int iVar1;
  
  iVar1 = clk_rcg2_set_force_enable();
  if (((iVar1 == 0) &&
      (iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,
                            *(undefined4 *)(param_1 + 0x94)), iVar1 == 0)) &&
     (iVar1 = update_config(param_1 + -0x30), iVar1 == 0)) {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,0,0,0,0);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_disable @ 0011395c size=132
// signature: undefined clk_rcg2_shared_disable(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_shared_disable(long param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + -0x30);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*piVar1 + 4,param_1 + 0x94);
  clk_rcg2_set_force_enable(param_1);
  regmap_write(*(undefined8 *)(param_1 + 0x18),*piVar1 + 4,(ulong)*(byte *)(param_1 + -0x2a) << 8);
  update_config(piVar1);
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x18),*piVar1,2,0,0,0,0);
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_recalc_rate @ 001139e4 size=148
// signature: undefined clk_rcg2_shared_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_shared_recalc_rate(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uVar3 = clk_hw_is_enabled();
  if ((uVar3 & 1) == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x94);
  }
  else {
    local_2c = 0;
    regmap_read(*(undefined8 *)(param_1 + 0x18),
                *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,&local_2c);
    uVar1 = local_2c;
  }
  __clk_rcg2_recalc_rate(param_1,param_2,uVar1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_set_parent @ 00113a7c size=156
// signature: undefined clk_rcg2_shared_set_parent(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_shared_set_parent(long param_1,byte param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  uVar2 = clk_hw_is_enabled();
  if ((uVar2 & 1) == 0) {
    uVar3 = 0;
    uVar1 = *(uint *)(param_1 + 0x94) & 0xfffff8ff;
    *(uint *)(param_1 + 0x94) = uVar1;
    *(uint *)(param_1 + 0x94) =
         uVar1 | (uint)*(byte *)(*(long *)(param_1 + -0x28) + (ulong)param_2 * 2 + 1) << 8;
  }
  else {
    uVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),
                       *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,0x700,
                       (ulong)*(byte *)(*(long *)(param_1 + -0x28) + (ulong)param_2 * 2 + 1) << 8,0,
                       0,0);
    if ((int)uVar3 == 0) {
      uVar3 = update_config((int *)(param_1 + -0x30));
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_rcg2_shared_get_parent @ 00113b1c size=288
// signature: undefined clk_rcg2_shared_get_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_shared_get_parent(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  byte *pbVar6;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uVar5 = clk_hw_is_enabled();
  if ((uVar5 & 1) == 0) {
    uVar1 = *(uint *)(param_1 + 0x94);
    uVar4 = clk_hw_get_num_parents(param_1);
    if (0 < (int)uVar4) {
      uVar5 = 0;
      pbVar6 = (byte *)(*(long *)(param_1 + -0x28) + 1);
      do {
        if ((uVar1 >> 8 & 7) == (uint)*pbVar6) goto LAB_00113c08;
        uVar5 = uVar5 + 1;
        pbVar6 = pbVar6 + 2;
      } while (uVar4 != uVar5);
    }
  }
  else {
    local_2c = 0;
    iVar3 = regmap_read(*(undefined8 *)(param_1 + 0x18),
                        *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 4,&local_2c);
    uVar1 = local_2c;
    uVar5 = 0;
    if (iVar3 != 0) goto LAB_00113c08;
    uVar4 = clk_hw_get_num_parents(param_1);
    if (0 < (int)uVar4) {
      uVar5 = 0;
      pbVar6 = (byte *)(*(long *)(param_1 + -0x28) + 1);
      do {
        if ((uVar1 >> 8 & 7) == (uint)*pbVar6) {
          uVar5 = uVar5 & 0xffffffff;
          goto LAB_00113c08;
        }
        uVar5 = uVar5 + 1;
        pbVar6 = pbVar6 + 2;
      } while (uVar4 != uVar5);
    }
  }
  uVar5 = 0;
LAB_00113c08:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_set_rate @ 00113c40 size=164
// signature: undefined clk_rcg2_shared_set_rate(void)
// callers: [clk_rcg2_shared_set_rate_and_parent]
//------------------------------------------------------------

undefined8 clk_rcg2_shared_set_rate(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = qcom_find_freq(*(undefined8 *)(param_1 + -0x20));
  if (lVar1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar2 = clk_hw_is_enabled(param_1);
    if ((uVar2 & 1) == 0) {
      uVar3 = __clk_rcg2_configure(param_1 + -0x30,lVar1,param_1 + 0x94);
    }
    else {
      uVar3 = clk_rcg2_set_force_enable(param_1);
      if (((int)uVar3 == 0) && (uVar3 = clk_rcg2_configure(param_1 + -0x30,lVar1), (int)uVar3 == 0))
      {
        uVar3 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,0,0,0,
                           0);
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_rcg2_shared_set_rate_and_parent @ 00113ce8 size=28
// signature: undefined clk_rcg2_shared_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_shared_set_rate_and_parent(void)

{
  clk_rcg2_shared_set_rate();
  return;
}



//------------------------------------------------------------
// clk_rcg2_shared_init @ 00113d08 size=156
// signature: undefined clk_rcg2_shared_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_shared_init(long param_1)

{
  int *piVar1;
  
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_rcg2_regmap_ops;
  }
  piVar1 = (int *)(param_1 + -0x30);
  regmap_read(*(undefined8 *)(param_1 + 0x18),*piVar1 + 4,param_1 + 0x94);
  clk_rcg2_set_force_enable(param_1);
  regmap_write(*(undefined8 *)(param_1 + 0x18),*piVar1 + 4,(ulong)*(byte *)(param_1 + -0x2a) << 8);
  update_config(piVar1);
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x18),*piVar1,2,0,0,0,0);
  return 0;
}



//------------------------------------------------------------
// clk_rcg2_crmc_populate_freq_table @ 00113da8 size=668
// signature: undefined clk_rcg2_crmc_populate_freq_table(void)
// callers: [clk_rcg2_crmc_determine_rate]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clk_rcg2_crmc_populate_freq_table(long param_1)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  uint uVar12;
  byte *pbVar13;
  code *pcVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  byte *pbVar18;
  ulong *puVar19;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  lVar8 = kmalloc_trace(_clk_get_rate,0xdc0,0xd8);
  if (lVar8 == 0) {
    uVar10 = 0xfffffff4;
  }
  else {
    lVar1 = param_1 + 0x30;
    *(long *)(param_1 + 0x10) = lVar8;
    lVar16 = 0;
    uVar17 = 0;
    do {
      if (lVar16 == 8) {
        uVar10 = 0;
        goto LAB_00113fec;
      }
      lVar15 = *(long *)(param_1 + 0xa8);
      local_6c = 0;
      local_70 = 0;
      lVar9 = *(long *)(lVar15 + 8);
      if (lVar9 == 0) {
        _printk(&DAT_0011ca72,"clk_rcg2_crmc_populate_freq");
        uVar10 = 0xffffffed;
        goto LAB_00113fec;
      }
      iVar4 = (int)(lVar16 + 1) * 4;
      regmap_read(lVar9,iVar4 + (uint)*(byte *)(param_1 + 0xb0) * 0x200 + 0x110,&local_6c);
      regmap_read(*(undefined8 *)(lVar15 + 8),
                  iVar4 + (uint)*(byte *)(param_1 + 0xb0) * 0x200 + 0x138,&local_70);
      uVar6 = local_6c;
      uVar12 = local_70;
      uVar7 = local_6c & ((uint)(-1L << ((ulong)*(byte *)(param_1 + 5) & 0x3f)) ^ 0xffffffff);
      pbVar18 = (byte *)(lVar8 + lVar16 * 0x18 + 9);
      *pbVar18 = 1;
      if (uVar7 != 0) {
        *pbVar18 = (byte)uVar7;
      }
      uVar7 = clk_hw_get_num_parents(lVar1);
      if (uVar7 == 0) goto LAB_00113f9c;
      uVar11 = 0;
      uVar3 = uVar12 & 0xff;
      puVar19 = (ulong *)(lVar8 + lVar16 * 0x18);
      pbVar13 = (byte *)(*(long *)(param_1 + 8) + 1);
      while ((uVar6 >> 8 & 7) != (uint)*pbVar13) {
        uVar11 = uVar11 + 1;
        pbVar13 = pbVar13 + 2;
        if (uVar7 == uVar11) goto LAB_00113f9c;
      }
      *(byte *)(lVar8 + lVar16 * 0x18 + 8) = pbVar13[-1];
      lVar9 = clk_hw_get_parent_by_index(lVar1);
      if (lVar9 == 0) {
        uVar10 = 0xffffffea;
        goto LAB_00113fec;
      }
      if (uVar3 != 0) {
        uVar11 = clk_is_regmap_clk(lVar9);
        if ((((uVar11 & 1) != 0) && (*(long *)(lVar9 + 0x58) != 0)) &&
           (pcVar14 = *(code **)(*(long *)(lVar9 + 0x58) + 0x18), pcVar14 != (code *)0x0)) {
          if (*(int *)(pcVar14 + -4) != 0x365a432f) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x113f58);
            (*pcVar14)();
          }
          uVar11 = (*pcVar14)(lVar9,uVar3,uVar12 >> 0x10);
          if (uVar11 != 0) goto LAB_00113f70;
        }
LAB_00113f9c:
        if (*(undefined8 **)(param_1 + 0x40) == (undefined8 *)0x0) {
          uVar10 = clk_hw_get_name(lVar1);
        }
        else {
          uVar10 = **(undefined8 **)(param_1 + 0x40);
        }
        _printk(&DAT_0011d16b,"clk_rcg2_crmc_populate_freq",uVar10);
        uVar10 = 0xffffffea;
        goto LAB_00113fec;
      }
      uVar11 = clk_hw_get_rate(lVar9);
      if (uVar11 == 0) goto LAB_00113f9c;
LAB_00113f70:
      if ((ulong)*pbVar18 != 0) {
        uVar2 = (ulong)*pbVar18 + 1;
        uVar5 = 0;
        if (uVar2 != 0) {
          uVar5 = uVar11 / uVar2;
        }
        uVar12 = (uint)uVar2;
        uVar7 = 0;
        if (uVar12 != 0) {
          uVar7 = (((int)uVar11 - (int)uVar5 * uVar12) * 2 & 0xfffe) / uVar12;
        }
        uVar11 = (ulong)uVar7 + uVar5 * 2;
      }
      uVar2 = uVar17 & 0xffffffff;
      *puVar19 = uVar11;
      lVar16 = lVar16 + 1;
      uVar17 = uVar11;
    } while (uVar2 < uVar11);
    uVar10 = 0;
    *puVar19 = 0;
  }
LAB_00113fec:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_crmc_prepare @ 00114048 size=48
// signature: undefined clk_rcg2_crmc_prepare(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_crmc_prepare(long param_1)

{
  if (*(long *)(param_1 + -0x10) == 0) {
    *(undefined8 *)(param_1 + -0x10) = cxo_f;
  }
  clk_rcg2_vote_perf_level();
  return;
}



//------------------------------------------------------------
// clk_rcg2_vote_perf_level @ 00114078 size=548
// signature: undefined clk_rcg2_vote_perf_level(void)
// callers: [clk_rcg2_crmc_prepare, clk_rcg2_crmc_set_rate, clk_rcg2_crmc_unprepare]
//------------------------------------------------------------

void clk_rcg2_vote_perf_level(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 local_48;
  uint local_44;
  uint uStack_40;
  undefined4 local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c = 0;
  lVar5 = *(long *)(param_1 + 0x78);
  if ((*(long *)(param_1 + -0x20) == 0) || (*(char *)(lVar5 + 0x18) == '\0')) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar4 = clk_hw_get_name(param_1);
    }
    else {
      uVar4 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011cb9e,"clk_rcg2_vote_perf_level",uVar4,param_2);
    iVar2 = -0x16;
  }
  else {
    uVar1 = qcom_find_crm_freq_index(*(long *)(param_1 + -0x20),param_2);
    if (uVar1 < 8) {
      local_44 = (uint)*(byte *)(param_1 + 0x80);
      local_3c = CONCAT31(local_3c._1_3_,1);
      local_48 = 0;
      uStack_40 = uVar1;
      iVar2 = crm_write_perf_ol(*(undefined8 *)(lVar5 + 0x10),1,0,&local_48);
      if (iVar2 != 0) {
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar4 = clk_hw_get_name(param_1);
        }
        else {
          uVar4 = **(undefined8 **)(param_1 + 0x10);
        }
        _printk(&DAT_0011ce96,"clk_rcg2_vote_perf_level",uVar4,iVar2);
      }
      local_48 = 1;
      iVar2 = crm_write_perf_ol(*(undefined8 *)(lVar5 + 0x10),1,0,&local_48);
      if (iVar2 != 0) {
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar4 = clk_hw_get_name(param_1);
        }
        else {
          uVar4 = **(undefined8 **)(param_1 + 0x10);
        }
        _printk(&DAT_0011ce96,"clk_rcg2_vote_perf_level",uVar4,iVar2);
      }
      local_48 = 2;
      iVar3 = crm_write_perf_ol(*(undefined8 *)(lVar5 + 0x10),1,0,&local_48);
      iVar2 = 0;
      if (iVar3 != 0) {
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar4 = clk_hw_get_name(param_1);
        }
        else {
          uVar4 = **(undefined8 **)(param_1 + 0x10);
        }
        _printk(&DAT_0011ce96,"clk_rcg2_vote_perf_level",uVar4,iVar3);
        iVar2 = iVar3;
      }
    }
    else {
      if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
        uVar4 = clk_hw_get_name(param_1);
      }
      else {
        uVar4 = **(undefined8 **)(param_1 + 0x10);
      }
      _printk(&DAT_0011d594,"clk_rcg2_vote_perf_level",uVar4,uVar1);
      iVar2 = -0x16;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_crmc_unprepare @ 001142a0 size=108
// signature: undefined clk_rcg2_crmc_unprepare(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_crmc_unprepare(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = clk_rcg2_vote_perf_level(param_1,0);
  if (iVar1 != 0) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011d33a,"clk_rcg2_crmc_unprepare",uVar2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_crmc_hw_set_rate @ 00114310 size=308
// signature: undefined clk_rcg2_crmc_hw_set_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_crmc_hw_set_rate
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 local_58;
  uint local_54;
  uint uStack_50;
  undefined4 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x78);
  local_4c = 0;
  uVar2 = qcom_find_crm_freq_index(*(undefined8 *)(param_1 + -0x20),param_5);
  if (uVar2 < 8) {
    local_54 = (uint)*(byte *)(param_1 + 0x80);
    local_4c = CONCAT31(local_4c._1_3_,1);
    local_58 = param_4;
    uStack_50 = uVar2;
    iVar3 = crm_write_perf_ol(*(undefined8 *)(lVar5 + 0x10),param_2,param_3,&local_58);
    if (iVar3 != 0) {
      if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
        uVar4 = clk_hw_get_name(param_1);
      }
      else {
        uVar4 = **(undefined8 **)(param_1 + 0x10);
      }
      _printk(&DAT_0011ce96,"clk_rcg2_crmc_hw_set_rate",uVar4,iVar3);
    }
    lVar5 = (long)iVar3;
  }
  else {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar4 = clk_hw_get_name(param_1);
    }
    else {
      uVar4 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011d594,"clk_rcg2_crmc_hw_set_rate",uVar4,uVar2);
    lVar5 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_crmc_recalc_rate @ 00114448 size=8
// signature: undefined clk_rcg2_crmc_recalc_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_crmc_recalc_rate(long param_1)

{
  return *(undefined8 *)(param_1 + -0x10);
}



//------------------------------------------------------------
// clk_rcg2_crmc_determine_rate @ 00114454 size=260
// signature: undefined clk_rcg2_crmc_determine_rate(void)
// callers: [clk_rcg2_crmc_list_rate]
//------------------------------------------------------------

int clk_rcg2_crmc_determine_rate(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x78);
  iVar1 = clk_runtime_get_regmap();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = qcom_clk_crm_init(*(undefined8 *)(param_1 + 0x70),uVar2);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x98) == '\0') {
      iVar1 = clk_rcg2_crmc_populate_freq_table(param_1 + -0x30);
      if (iVar1 != 0) {
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar2 = clk_hw_get_name(param_1);
        }
        else {
          uVar2 = **(undefined8 **)(param_1 + 0x10);
        }
        _printk(&DAT_0011d495,"clk_rcg2_crmc_determine_rate",uVar2);
        goto LAB_001144c4;
      }
      *(undefined1 *)(param_1 + 0x98) = 1;
    }
    iVar1 = _freq_tbl_determine_rate(param_1,*(undefined8 *)(param_1 + -0x20),param_2,1);
  }
  else {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011d1d6,"clk_rcg2_crmc_determine_rate",iVar1,uVar2);
  }
LAB_001144c4:
  clk_runtime_put_regmap(param_1);
  return iVar1;
}



//------------------------------------------------------------
// clk_rcg2_crmc_set_rate @ 0011455c size=72
// signature: undefined clk_rcg2_crmc_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_crmc_set_rate(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  *(undefined8 *)(param_1 + -0x10) = param_2;
  uVar1 = clk_hw_is_prepared();
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = clk_rcg2_vote_perf_level(param_1,param_2);
  }
  return uVar2;
}



//------------------------------------------------------------
// clk_rcg2_crmc_init @ 001145a8 size=36
// signature: undefined clk_rcg2_crmc_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_crmc_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_rcg2_crmc_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_rcg2_crmb_prepare @ 001145d0 size=60
// signature: undefined clk_rcg2_crmb_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_crmb_prepare(long param_1)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + -0x20) == 0) || (*(char *)(*(long *)(param_1 + 0x78) + 0x18) == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = clk_rcg2_vote_bw(param_1,*(undefined8 *)(param_1 + -0x10));
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_rcg2_vote_bw @ 0011460c size=420
// signature: undefined clk_rcg2_vote_bw(void)
// callers: [clk_rcg2_crmb_prepare, clk_rcg2_crmb_unprepare, clk_rcg2_crmb_set_rate]
//------------------------------------------------------------

int clk_rcg2_vote_bw(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_48;
  uint local_40;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x78);
  if (param_2 == 0) {
    local_40 = 0x60000000;
  }
  else {
    local_40 = (uint)(param_2 / 1000000) & 0x3fff | 0x60000000;
  }
  local_3c = 1;
  local_48 = 0;
  iVar1 = crm_write_bw_vote(*(undefined8 *)(lVar3 + 0x10),1,0,&local_48);
  if (iVar1 != 0) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011cf1a,"clk_rcg2_vote_bw",uVar2,iVar1);
  }
  local_48 = CONCAT44(local_48._4_4_,1);
  iVar1 = crm_write_bw_vote(*(undefined8 *)(lVar3 + 0x10),1,0,&local_48);
  if (iVar1 != 0) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011cf1a,"clk_rcg2_vote_bw",uVar2,iVar1);
  }
  local_48 = CONCAT44(local_48._4_4_,2);
  iVar1 = crm_write_bw_vote(*(undefined8 *)(lVar3 + 0x10),1,0,&local_48);
  if (iVar1 != 0) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011cf1a,"clk_rcg2_vote_bw",uVar2,iVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// clk_rcg2_crmb_unprepare @ 001147b4 size=132
// signature: undefined clk_rcg2_crmb_unprepare(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_crmb_unprepare(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((*(long *)(param_1 + -0x20) != 0) && (*(char *)(*(long *)(param_1 + 0x78) + 0x18) != '\0'))
     && (iVar1 = clk_rcg2_vote_bw(param_1,0), iVar1 != 0)) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar2 = clk_hw_get_name(param_1);
    }
    else {
      uVar2 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011ce21,"clk_rcg2_crmb_unprepare",uVar2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_crmb_hw_set_bw @ 0011483c size=232
// signature: undefined clk_rcg2_crmb_hw_set_bw(void)
// callers: []
//------------------------------------------------------------

long clk_rcg2_crmb_hw_set_bw
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,ulong param_5)

{
  undefined1 auVar1 [16];
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_38;
  undefined4 uStack_34;
  uint local_30;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (param_5 == 0) {
    local_30 = 0x60000000;
  }
  else {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_5;
    local_30 = (uint)(SUB168(auVar1 * ZEXT816(0x431bde82d7b634db),8) >> 4) & 0xfffc000 | 0x60000000;
  }
  uStack_34 = 0;
  local_2c = 1;
  local_38 = param_4;
  iVar3 = crm_write_bw_vote(*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x10),param_2,param_3,
                            &local_38);
  if (iVar3 != 0) {
    if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
      uVar4 = clk_hw_get_name(param_1);
    }
    else {
      uVar4 = **(undefined8 **)(param_1 + 0x10);
    }
    _printk(&DAT_0011d6bd,"clk_rcg2_crmb_hw_set_bw",uVar4,local_30,iVar3);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// clk_rcg2_crmb_set_rate @ 00114928 size=172
// signature: undefined clk_rcg2_crmb_set_rate(void)
// callers: []
//------------------------------------------------------------

int clk_rcg2_crmb_set_rate(long param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x78);
  *(undefined8 *)(param_1 + -0x10) = param_2;
  uVar2 = clk_hw_is_prepared();
  if ((uVar2 & 1) == 0) {
    iVar1 = 0;
  }
  else if ((*(long *)(param_1 + -0x20) == 0) || (*(char *)(lVar4 + 0x18) == '\0')) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = clk_rcg2_vote_bw(param_1,param_2);
    if (iVar1 != 0) {
      if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
        uVar3 = clk_hw_get_name(param_1);
      }
      else {
        uVar3 = **(undefined8 **)(param_1 + 0x10);
      }
      _printk(&DAT_0011ce21,"clk_rcg2_crmb_set_rate",uVar3,iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// clk_rcg2_crmb_init @ 001149d8 size=36
// signature: undefined clk_rcg2_crmb_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_rcg2_crmb_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_rcg2_crmb_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// qcom_cc_register_rcg_dfs @ 00114a00 size=240
// signature: undefined qcom_cc_register_rcg_dfs(void)
// callers: []
//------------------------------------------------------------

void qcom_cc_register_rcg_dfs(undefined8 param_1,long param_2,ulong param_3)

{
  long *plVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  uint local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  if (param_3 != 0) {
    uVar6 = 0;
    do {
      plVar1 = (long *)(param_2 + uVar6 * 0x10);
      local_5c = 0;
      piVar2 = (int *)*plVar1;
      lVar3 = plVar1[1];
      *(byte *)((long)piVar2 + 0xc1) = *(byte *)((long)piVar2 + 0xc1) | 4;
      iVar4 = regmap_read(param_1,*piVar2 + 0x14,&local_5c);
      if (iVar4 != 0) {
        uVar5 = 0xffffffea;
        goto LAB_00114ab8;
      }
      if ((local_5c & 1) != 0) {
        *(undefined ***)(lVar3 + 8) = &clk_rcg2_dfs_ops;
        *(ulong *)(lVar3 + 0x30) = *(ulong *)(lVar3 + 0x30) | 0x40;
        piVar2[4] = 0;
        piVar2[5] = 0;
      }
      uVar6 = (ulong)((int)uVar6 + 1);
    } while (uVar6 < param_3);
  }
  uVar5 = 0;
LAB_00114ab8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_dp_determine_rate @ 00114af4 size=168
// signature: undefined clk_rcg2_dp_determine_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_dp_determine_rate(long param_1,ulong *param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong local_38;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_30 = 0;
  uVar3 = 0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(param_1 + -0x2c) & 0x3f);
  rational_best_approximation(param_2[3],*param_2,uVar3,uVar3,&local_38,&local_30);
  uVar2 = 0xffffffea;
  if ((local_30 != 0) && (local_38 != 0)) {
    uVar2 = 0;
    uVar3 = 0;
    if ((local_38 & 0xffffffff) != 0) {
      uVar3 = (param_2[3] * local_30) / (local_38 & 0xffffffff);
    }
    *param_2 = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_dp_set_rate @ 00114ba0 size=336
// signature: undefined clk_rcg2_dp_set_rate(void)
// callers: [clk_rcg2_dp_set_rate_and_parent]
//------------------------------------------------------------

void clk_rcg2_dp_set_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte *pbVar9;
  ulong uVar10;
  long local_78;
  long local_70;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  bVar1 = *(byte *)(param_1 + -0x2b);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_64 = 0;
  uVar4 = clk_hw_get_num_parents();
  uVar10 = (ulong)uVar4;
  local_78 = 0;
  local_70 = 0;
  uVar6 = 0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(param_1 + -0x2c) & 0x3f);
  rational_best_approximation(param_3,param_2,uVar6,uVar6,&local_78,&local_70);
  uVar5 = 0xffffffea;
  if ((local_70 != 0) && (local_78 != 0)) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 4,&local_64);
    uVar2 = local_64 >> 8 & 7;
    if (0 < (int)uVar4) {
      pbVar9 = (byte *)(*(long *)(param_1 + -0x28) + 1);
      do {
        if (uVar2 == *pbVar9) {
          local_58 = CONCAT71(local_58._1_7_,pbVar9[-1]);
          break;
        }
        pbVar9 = pbVar9 + 2;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    uVar5 = local_58;
    uVar7 = 0;
    if (local_70 != local_78) {
      uVar7 = (undefined2)local_70;
    }
    uVar8 = 0;
    if (local_70 != local_78) {
      uVar8 = (undefined2)local_78;
    }
    local_58._6_2_ = SUB82(uVar5,6);
    local_58._0_6_ =
         CONCAT24(uVar8,CONCAT22(uVar7,CONCAT11((byte)local_64 &
                                                ~(byte)(-1L << ((ulong)bVar1 & 0x3f)),
                                                (undefined1)local_58)));
    local_64 = uVar2;
    uVar5 = clk_rcg2_configure(param_1 + -0x30,&local_60);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_dp_set_rate_and_parent @ 00114cf4 size=28
// signature: undefined clk_rcg2_dp_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_dp_set_rate_and_parent(void)

{
  clk_rcg2_dp_set_rate();
  return;
}



//------------------------------------------------------------
// clk_rcg2_set_force_enable @ 00114d10 size=244
// signature: undefined clk_rcg2_set_force_enable(void)
// callers: [clk_rcg2_disable, __clk_rcg2_set_rate, clk_rcg2_shared_enable, clk_rcg2_shared_disable, clk_rcg2_shared_init, clk_rcg2_enable, clk_rcg2_shared_set_rate]
//------------------------------------------------------------

int clk_rcg2_set_force_enable(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  iVar3 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,2,0,0,0);
  if (iVar3 == 0) {
    uVar6 = 0x1f5;
    while( true ) {
      local_3c = 0;
      iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_3c
                         );
      if ((iVar4 != 0) || (-1 < local_3c)) break;
      __const_udelay(0x10c7);
      uVar6 = uVar6 - 1;
      if (uVar6 < 2) {
        clk_debug_print_hw(param_1,0);
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar5 = clk_hw_get_name(param_1);
        }
        else {
          uVar5 = **(undefined8 **)(param_1 + 0x10);
        }
        __warn_printk("%s: rcg didn\'t turn on.",uVar5);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x114dd0);
        (*pcVar2)();
      }
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
// clk_rcg2_configure @ 00114e04 size=188
// signature: undefined clk_rcg2_configure(void)
// callers: [clk_edp_pixel_set_rate, clk_rcg2_disable, __clk_rcg2_set_rate, clk_byte_set_rate, clk_byte_set_rate_and_parent, clk_byte2_set_rate, clk_edp_pixel_set_rate_and_parent, clk_pixel_set_rate, clk_rcg2_enable, clk_rcg2_shared_set_rate, clk_rcg2_dp_set_rate]
//------------------------------------------------------------

void clk_rcg2_configure(int *param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_read(*(undefined8 *)(param_1 + 0x12),*param_1 + (uint)*(byte *)(param_1 + 0x30) + 4
                      ,&local_2c);
  if (((iVar2 == 0) && (iVar2 = __clk_rcg2_configure(param_1,param_2,&local_2c), iVar2 == 0)) &&
     (iVar2 = regmap_write(*(undefined8 *)(param_1 + 0x12),
                           *param_1 + (uint)*(byte *)(param_1 + 0x30) + 4,local_2c), iVar2 == 0)) {
    *(undefined8 *)(param_1 + 6) = *param_2;
    update_config(param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __clk_rcg2_configure @ 00114ec0 size=436
// signature: undefined __clk_rcg2_configure(void)
// callers: [clk_rcg2_configure, clk_rcg2_shared_set_rate]
//------------------------------------------------------------

ulong __clk_rcg2_configure(int *param_1,long param_2,uint *param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  
  uVar7 = qcom_find_src_index(param_1 + 0xc,*(undefined8 *)(param_1 + 2),
                              *(undefined1 *)(param_2 + 8));
  if ((int)uVar7 < 0) {
    return (ulong)uVar7;
  }
  if ((ulong)*(byte *)(param_1 + 1) == 0) {
    bVar6 = true;
  }
  else if (*(short *)(param_2 + 0xc) == 0) {
    bVar6 = false;
  }
  else {
    uVar4 = ~(uint)(-1L << ((ulong)*(byte *)(param_1 + 1) & 0x3f));
    uVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x12),
                       *param_1 + (uint)*(byte *)(param_1 + 0x30) + 8,uVar4,
                       *(undefined2 *)(param_2 + 10),0,0,0);
    if ((int)uVar8 != 0) {
      return uVar8;
    }
    uVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x12),
                       *param_1 + (uint)*(byte *)(param_1 + 0x30) + 0xc,uVar4,
                       (uint)*(ushort *)(param_2 + 10) + ~(uint)*(ushort *)(param_2 + 0xc),0,0,0);
    if ((int)uVar8 != 0) {
      return uVar8;
    }
    uVar2 = *(ushort *)(param_2 + 0xc);
    uVar9 = (uint)*(ushort *)(param_2 + 10);
    iVar5 = uVar2 - uVar9;
    uVar3 = iVar5 * 2;
    uVar1 = (uint)uVar2;
    if (uVar2 < uVar9 || iVar5 == 0) {
      uVar1 = uVar9;
    }
    if (uVar3 <= uVar2) {
      uVar1 = uVar3;
    }
    uVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x12),
                       *param_1 + (uint)*(byte *)(param_1 + 0x30) + 0x10,uVar4,
                       uVar4 & (uVar1 ^ 0xffffffff),0,0,0);
    if ((int)uVar8 != 0) {
      return uVar8;
    }
    bVar6 = (char)param_1[1] == '\0';
  }
  uVar7 = (uint)CONCAT11(*(undefined1 *)(*(long *)(param_1 + 2) + (ulong)uVar7 * 2 + 1),
                         *(undefined1 *)(param_2 + 9));
  if ((!bVar6) && (*(short *)(param_2 + 0xc) != 0)) {
    if (*(short *)(param_2 + 10) != *(short *)(param_2 + 0xc)) {
      uVar7 = uVar7 | 0x2000;
    }
  }
  *param_3 = (uint)(-1L << ((ulong)*(byte *)((long)param_1 + 5) & 0x3f)) & 0xffefc8ff & *param_3 |
             uVar7 | (*(byte *)((long)param_1 + 0xc1) & 2) << 0x13;
  return 0;
}



//------------------------------------------------------------
// update_config @ 00115074 size=312
// signature: undefined update_config(void)
// callers: [clk_rcg2_set_parent, clk_rcg2_configure, clk_rcg2_shared_enable, clk_gfx3d_set_rate_and_parent, clk_rcg2_shared_disable, clk_rcg2_set_duty_cycle, clk_rcg2_shared_init, clk_rcg2_shared_set_parent]
//------------------------------------------------------------

void update_config(undefined4 *param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar3 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x12),*param_1,1,1,0,0,0);
  if ((int)uVar3 == 0) {
    uVar4 = *(ulong *)(param_1 + 8);
    uVar5 = 0;
    if (uVar4 != 0) {
      iVar6 = 0;
      if (uVar4 != 0) {
        iVar6 = (int)(1000000 / uVar4);
      }
      uVar5 = iVar6 * 3;
    }
    uVar4 = *(ulong *)(param_1 + 6);
    if (uVar4 != 0) {
      iVar6 = 0;
      if (uVar4 != 0) {
        iVar6 = (int)(1000000 / uVar4);
      }
      uVar5 = iVar6 * 3 + uVar5;
    }
    if (uVar5 < 0x1f5) {
      uVar5 = 500;
    }
    iVar6 = uVar5 + 1;
    while (uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x12),*param_1,&local_3c), (int)uVar3 == 0)
    {
      if ((local_3c & 1) == 0) {
        uVar3 = 0;
        break;
      }
      __const_udelay(0x10c7);
      iVar6 = iVar6 + -1;
      if (iVar6 < 2) {
        clk_debug_print_hw(param_1 + 0xc,0);
        if (*(undefined8 **)(param_1 + 0x10) == (undefined8 *)0x0) {
          uVar3 = clk_hw_get_name(param_1 + 0xc);
        }
        else {
          uVar3 = **(undefined8 **)(param_1 + 0x10);
        }
        __warn_printk("%s: rcg didn\'t update its configuration after %d us.",uVar3,uVar5);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1151a8);
        (*pcVar2)();
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __clk_rcg2_recalc_rate @ 001151b0 size=448
// signature: undefined __clk_rcg2_recalc_rate(void)
// callers: [clk_rcg2_recalc_rate, clk_rcg2_shared_recalc_rate]
//------------------------------------------------------------

ulong __clk_rcg2_recalc_rate(long param_1,ulong param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint local_50;
  uint uStack_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  uVar2 = param_3 >> 8 & 7;
  local_50 = 0;
  uStack_4c = 0;
  if (*(char *)(param_1 + -8) == '\0') {
LAB_00115228:
    bVar1 = *(byte *)(param_1 + -0x2c);
    if ((ulong)bVar1 == 0) {
      uVar8 = 0;
      uVar9 = 0;
      uVar5 = 0;
      if (uVar2 == 0) goto LAB_001152a8;
LAB_001152d0:
      param_3 = param_3 & ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f)) ^ 0xffffffff);
      if (param_3 != 0) {
LAB_001152e4:
        uVar7 = (ulong)(param_3 + 1);
        uVar3 = 0;
        if (uVar7 != 0) {
          uVar3 = param_2 / uVar7;
        }
        uVar4 = 0;
        if (uVar7 != 0) {
          uVar4 = ((param_2 - uVar3 * uVar7) * 2) / uVar7;
        }
        param_2 = uVar4 + uVar3 * 2;
      }
    }
    else {
      regmap_read(*(undefined8 *)(param_1 + 0x18),
                  *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 8,&uStack_4c);
      uVar8 = (uint)(-1L << ((ulong)bVar1 & 0x3f));
      uStack_4c = uStack_4c & (uVar8 ^ 0xffffffff);
      regmap_read(*(undefined8 *)(param_1 + 0x18),
                  *(int *)(param_1 + -0x30) + (uint)*(byte *)(param_1 + 0x90) + 0xc,&local_50);
      uVar5 = (ulong)uStack_4c;
      uVar9 = param_3 >> 0xc & 3;
      uVar8 = uStack_4c + (~local_50 & (uVar8 ^ 0xffffffff));
      local_50 = uVar8;
      if (uVar2 != 0) goto LAB_001152d0;
LAB_001152a8:
      if (*(char *)(param_1 + -8) == '\0') goto LAB_001152d0;
      lVar6 = qcom_find_freq(*(undefined8 *)(param_1 + -0x20),*(undefined8 *)(param_1 + -0x10));
      if (lVar6 == 0) {
        param_2 = 0xffffffffffffffea;
        goto LAB_00115338;
      }
      uVar5 = (ulong)uStack_4c;
      param_3 = (uint)*(byte *)(lVar6 + 9);
      uVar8 = local_50;
      if (*(byte *)(lVar6 + 9) != 0) goto LAB_001152e4;
    }
    if (uVar9 != 0) {
      uVar7 = (ulong)uVar8;
      uVar3 = 0;
      if (uVar7 != 0) {
        uVar3 = param_2 / uVar7;
      }
      uVar4 = 0;
      if (uVar7 != 0) {
        uVar4 = ((param_2 - uVar3 * uVar7) * uVar5) / uVar7;
      }
      param_2 = uVar4 + uVar3 * uVar5;
    }
    if ((*(char *)(param_1 + -8) == '\0') || (*(long *)(param_1 + -0x10) != 0)) goto LAB_00115338;
  }
  else {
    uVar5 = clk_hw_is_prepared(param_1);
    if ((uVar5 & 1) == 0) {
      if (uVar2 != 0) goto LAB_00115228;
    }
    else {
      uVar5 = clk_hw_is_enabled(param_1);
      if ((uVar2 != 0) || ((uVar5 & 1) != 0)) goto LAB_00115228;
    }
    param_2 = *(ulong *)(param_1 + -0x10);
    if (param_2 != 0) goto LAB_00115338;
    param_2 = cxo_f;
  }
  *(ulong *)(param_1 + -0x10) = param_2;
LAB_00115338:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// _freq_tbl_determine_rate @ 00115370 size=408
// signature: undefined _freq_tbl_determine_rate(void)
// callers: [clk_rcg2_dfs_determine_rate, clk_rcg2_determine_rate, clk_rcg2_determine_floor_rate, clk_rcg2_crmc_determine_rate]
//------------------------------------------------------------

int _freq_tbl_determine_rate(long param_1,undefined8 param_2,ulong *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_68 = 0;
  if (param_4 == 1) {
    puVar4 = (ulong *)qcom_find_freq(param_2,*param_3);
joined_r0x001153e0:
    if (puVar4 != (ulong *)0x0) {
      iVar2 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x28),(char)puVar4[1]);
      if (iVar2 < 0) goto LAB_00115434;
      uVar3 = clk_hw_get_flags(param_1);
      uVar5 = clk_hw_get_parent_by_index(param_1,iVar2);
      if (uVar5 != 0) {
        if ((uVar3 >> 2 & 1) == 0) {
          uVar6 = clk_hw_get_rate(uVar5);
        }
        else {
          uVar6 = *puVar4;
          if ((ulong)*(byte *)((long)puVar4 + 9) != 0) {
            if (uVar6 == 0) {
              uVar6 = *param_3;
            }
            uVar6 = (uVar6 >> 1) + (uVar6 >> 1) * (ulong)*(byte *)((long)puVar4 + 9);
          }
          if ((ulong)*(ushort *)((long)puVar4 + 0xc) != 0) {
            uVar7 = uVar6 * *(ushort *)((long)puVar4 + 0xc);
            uVar6 = 0;
            if ((ulong)*(ushort *)((long)puVar4 + 10) != 0) {
              uVar6 = uVar7 / *(ushort *)((long)puVar4 + 10);
            }
          }
        }
        param_3[4] = uVar5;
        uVar6 = clk_hw_round_rate(uVar5,uVar6);
        param_3[3] = uVar6;
        *param_3 = *puVar4;
        if (puVar4[2] == 0) {
          iVar2 = 0;
        }
        else {
          local_70 = puVar4[2];
          local_50 = uVar5;
          iVar2 = __clk_determine_rate(uVar5,&local_70);
          if ((iVar2 == 0) &&
             (iVar2 = clk_set_rate(*(undefined8 *)(uVar5 + 8),local_70), iVar2 != 0)) {
            _printk(&DAT_0011d6fa,local_70);
          }
        }
        goto LAB_00115434;
      }
    }
  }
  else if (param_4 == 0) {
    puVar4 = (ulong *)qcom_find_freq_floor(param_2,*param_3);
    goto joined_r0x001153e0;
  }
  iVar2 = -0x16;
LAB_00115434:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// __clk_rcg2_set_rate @ 00115508 size=584
// signature: undefined __clk_rcg2_set_rate(void)
// callers: [clk_rcg2_set_rate_and_parent, clk_rcg2_set_rate, clk_rcg2_set_floor_rate_and_parent, clk_rcg2_set_floor_rate]
//------------------------------------------------------------

int __clk_rcg2_set_rate(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  bool bVar10;
  
  if (param_3 == 1) {
    lVar4 = qcom_find_freq(*(undefined8 *)(param_1 + -0x20),param_2);
  }
  else {
    if (param_3 != 0) {
      return -0x16;
    }
    lVar4 = qcom_find_freq_floor(*(undefined8 *)(param_1 + -0x20),param_2);
  }
  if (lVar4 == 0) {
    return -0x16;
  }
  if ((*(char *)(param_1 + -8) != '\0') && (uVar5 = clk_hw_is_prepared(param_1), (uVar5 & 1) == 0))
  goto LAB_001155f4;
  if ((*(byte *)(param_1 + 0x91) & 1) == 0) {
    lVar7 = 0;
    lVar9 = 0;
LAB_00115588:
    bVar10 = false;
LAB_0011558c:
    iVar1 = clk_rcg2_configure(param_1 + -0x30,lVar4);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((*(byte *)(param_1 + 0x91) & 1) != 0) {
      if (!bVar10) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),2,0,0,0,0);
      }
      uVar6 = *(undefined8 *)(lVar7 + 8);
      uVar8 = *(undefined8 *)(lVar9 + 8);
      clk_disable(uVar8);
      clk_disable(uVar6);
      clk_unprepare(uVar8);
      clk_unprepare(uVar6);
    }
LAB_001155f4:
    *(undefined8 *)(param_1 + -0x10) = param_2;
    return 0;
  }
  lVar7 = clk_get_rate(*(undefined8 *)(param_1 + 8));
  lVar7 = ((lVar7 + 500U) / 1000) * 1000;
  *(long *)(param_1 + -0x10) = lVar7;
  if (lVar7 == cxo_f) {
    uVar2 = 0;
  }
  else {
    lVar7 = qcom_find_freq(*(undefined8 *)(param_1 + -0x20));
    if (lVar7 == 0) {
      return -0x16;
    }
    uVar2 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x28),*(undefined1 *)(lVar7 + 8))
    ;
  }
  uVar3 = qcom_find_src_index(param_1,*(undefined8 *)(param_1 + -0x28),*(undefined1 *)(lVar4 + 8));
  lVar7 = clk_hw_get_parent_by_index(param_1,uVar2);
  if (lVar7 == 0) {
    return -0x16;
  }
  lVar9 = clk_hw_get_parent_by_index(param_1,uVar3);
  if (lVar9 == 0) {
    return -0x16;
  }
  uVar6 = *(undefined8 *)(lVar7 + 8);
  uVar8 = *(undefined8 *)(lVar9 + 8);
  iVar1 = clk_prepare(uVar6);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = clk_prepare(uVar8);
  if (iVar1 != 0) goto LAB_00115700;
  iVar1 = clk_enable(uVar6);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar8);
    if (iVar1 == 0) {
      uVar5 = clk_rcg2_is_force_enabled(param_1);
      if ((uVar5 & 1) == 0) {
        clk_rcg2_set_force_enable(param_1);
        goto LAB_00115588;
      }
      bVar10 = true;
      goto LAB_0011558c;
    }
    clk_disable(uVar6);
  }
  clk_unprepare(uVar8);
LAB_00115700:
  clk_unprepare(uVar6);
  return iVar1;
}



//------------------------------------------------------------
// clk_rcg2_is_force_enabled @ 00115750 size=100
// signature: undefined clk_rcg2_is_force_enabled(void)
// callers: [__clk_rcg2_set_rate]
//------------------------------------------------------------

uint clk_rcg2_is_force_enabled(long param_1)

{
  long lVar1;
  uint local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x30),&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c >> 1 & 1;
}



//------------------------------------------------------------
// clk_rcg2_list_registers @ 001157b8 size=308
// signature: undefined clk_rcg2_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_list_registers(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined4 local_5c;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_5c = 0;
  if ((*(byte *)(param_2 + 0x91) >> 2 & 1) == 0) {
    clk_rcg2_list_registers_data = clk_rcg2_list_registers_data1;
    if (*(char *)(param_2 + -0x2c) != '\0') {
      clk_rcg2_list_registers_data = (undefined1 *)&clk_rcg2_list_registers_data2;
    }
  }
  else {
    clk_rcg2_list_registers_data = (undefined1 *)&clk_rcg2_list_registers_data3;
  }
  if (*(undefined **)clk_rcg2_list_registers_data != (undefined *)0x0) {
    lVar2 = 0;
    do {
      regmap_read(*(undefined8 *)(param_2 + 0x18),
                  *(int *)((long)clk_rcg2_list_registers_data + (lVar2 * 2 + 1) * 8) +
                  *(int *)(param_2 + -0x30),&local_5c);
      if (param_1 == 0) {
        _printk(&DAT_0011cae5,*(undefined **)((long)clk_rcg2_list_registers_data + lVar2 * 2 * 8),
                local_5c);
      }
      else {
        seq_printf(param_1,"%20s: 0x%.8x\n");
      }
      lVar1 = (lVar2 << 0x20) + 0x100000000;
      lVar2 = lVar1 >> 0x20;
    } while (*(long *)((long)clk_rcg2_list_registers_data + (lVar1 >> 0x1c)) != 0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_list_rate @ 001158f0 size=84
// signature: undefined clk_rcg2_list_rate(void)
// callers: []
//------------------------------------------------------------

long clk_rcg2_list_rate(long param_1,uint param_2)

{
  long *plVar1;
  ulong uVar2;
  long *plVar3;
  
  plVar1 = *(long **)(param_1 + -0x20);
  if (plVar1 == (long *)0x0) {
    return -6;
  }
  if (*plVar1 != 0) {
    uVar2 = 0xffffffffffffffff;
    plVar3 = plVar1;
    do {
      plVar3 = plVar3 + 3;
      uVar2 = uVar2 + 1;
    } while (*plVar3 != 0);
    if (uVar2 < param_2) {
      return -0x16;
    }
  }
  return plVar1[(ulong)param_2 * 3];
}



//------------------------------------------------------------
// clk_rcg2_crmc_list_rate @ 00115948 size=216
// signature: undefined clk_rcg2_crmc_list_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_crmc_list_rate(long param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  if ((**(long **)(param_1 + 0x78) == 0) || ((char)(*(long **)(param_1 + 0x78))[3] != '\0')) {
    plVar3 = *(long **)(param_1 + -0x20);
  }
  else {
    clk_rcg2_crmc_determine_rate(param_1,&local_50);
    plVar3 = *(long **)(param_1 + -0x20);
  }
  if (plVar3 == (long *)0x0) {
    lVar2 = -6;
  }
  else {
    if (*plVar3 != 0) {
      uVar4 = 0xffffffffffffffff;
      plVar5 = plVar3;
      do {
        plVar5 = plVar5 + 3;
        uVar4 = uVar4 + 1;
      } while (*plVar5 != 0);
      if (uVar4 < (param_2 & 0xffffffff)) {
        lVar2 = -0x16;
        goto LAB_001159f4;
      }
    }
    lVar2 = plVar3[(param_2 & 0xffffffff) * 3];
  }
LAB_001159f4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_dfs_recalc_rate @ 00115a24 size=380
// signature: undefined clk_rcg2_dfs_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void clk_rcg2_dfs_recalc_rate(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  uint local_58;
  uint uStack_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  local_50 = 0;
  local_58 = 0;
  uStack_54 = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + 0x14,&local_4c);
  uVar7 = (ulong)(local_4c >> 1) & 0xf;
  local_4c = (uint)uVar7;
  if (*(long *)(param_1 + -0x20) == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + local_4c * 4 + 0x1c,
                &local_50);
    uVar2 = local_50 & ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f)) ^ 0xffffffff);
    uVar1 = local_50 & 0x3000;
    if (uVar1 == 0) {
      uVar7 = 0;
      uVar8 = 0;
    }
    else {
      bVar3 = *(byte *)(param_1 + -0x2c);
      regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + local_4c * 4 + 0x5c,
                  &uStack_54);
      uVar9 = (uint)(-1L << ((ulong)bVar3 & 0x3f));
      uStack_54 = uStack_54 & (uVar9 ^ 0xffffffff);
      regmap_read(*(undefined8 *)(param_1 + 0x18),*(int *)(param_1 + -0x30) + local_4c * 4 + 0x9c,
                  &local_58);
      uVar7 = (ulong)uStack_54;
      uVar8 = (ulong)(uStack_54 + (~local_58 & (uVar9 ^ 0xffffffff)));
    }
    uVar9 = 2;
    if (uVar2 != 0) {
      uVar9 = uVar2 + 1;
    }
    uVar10 = (ulong)uVar9;
    uVar4 = 0;
    if (uVar10 != 0) {
      uVar4 = param_2 / uVar10;
    }
    uVar6 = 0;
    if (uVar10 != 0) {
      uVar6 = ((param_2 - uVar4 * uVar10) * 2) / uVar10;
    }
    uVar6 = uVar6 + uVar4 * 2;
    if (uVar1 != 0) {
      uVar4 = 0;
      if (uVar8 != 0) {
        uVar4 = uVar6 / uVar8;
      }
      uVar10 = 0;
      if (uVar8 != 0) {
        uVar10 = ((uVar6 - uVar4 * uVar8) * uVar7) / uVar8;
      }
      uVar6 = uVar10 + uVar4 * uVar7;
    }
  }
  else {
    uVar6 = *(ulong *)(*(long *)(param_1 + -0x20) + uVar7 * 0x18);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// clk_rcg2_dfs_determine_rate @ 00115ba4 size=700
// signature: undefined clk_rcg2_dfs_determine_rate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 clk_rcg2_dfs_determine_rate(long param_1,undefined8 param_2)

{
  ulong uVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  int iVar15;
  long lVar16;
  long lVar17;
  ulong *puVar18;
  byte *pbVar19;
  undefined8 local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + -0x20);
  if (lVar11 == 0) {
    lVar11 = kmalloc_trace(_clk_get_rate,0xdc0,0xd8);
    if (lVar11 == 0) {
      uVar8 = 0xfffffff4;
LAB_00115e38:
      uVar10 = clk_hw_get_name(param_1);
      _printk(&DAT_0011dab0,uVar10);
      goto LAB_00115df8;
    }
    lVar16 = 0;
    *(long *)(param_1 + -0x20) = lVar11;
    do {
      iVar4 = (int)lVar16 * 4;
      local_70 = 0;
      puVar18 = (ulong *)(lVar11 + lVar16 * 0x18);
      regmap_read(*(undefined8 *)(param_1 + 0x18),iVar4 + *(int *)(param_1 + -0x30) + 0x1c,&local_70
                 );
      uVar13 = (uint)local_70;
      uVar7 = (uint)local_70 &
              ((uint)(-1L << ((ulong)*(byte *)(param_1 + -0x2b) & 0x3f)) ^ 0xffffffff);
      pbVar19 = (byte *)((long)puVar18 + 9);
      *pbVar19 = 1;
      if (uVar7 != 0) {
        *pbVar19 = (byte)uVar7;
      }
      uVar7 = clk_hw_get_num_parents(param_1);
      if ((int)uVar7 < 1) {
        uVar14 = 0;
      }
      else {
        lVar17 = 0;
        iVar15 = 0;
        uVar14 = 0;
        do {
          if ((uVar13 >> 8 & 7) == (uint)*(byte *)(*(long *)(param_1 + -0x28) + lVar17 + 1)) {
            *(undefined1 *)(lVar11 + lVar16 * 0x18 + 8) =
                 *(undefined1 *)(*(long *)(param_1 + -0x28) + lVar17);
            lVar9 = clk_hw_get_parent_by_index(param_1,iVar15);
            if (lVar9 == 0) {
              uVar8 = 0xffffffea;
              goto LAB_00115e38;
            }
            uVar14 = clk_hw_get_rate();
          }
          iVar15 = iVar15 + 1;
          lVar17 = lVar17 + 2;
        } while ((ulong)uVar7 * 2 != lVar17);
      }
      uVar6 = local_70 & 0x3000;
      if ((local_70 & 0x3000) == 0) {
        lVar17 = lVar11 + lVar16 * 0x18;
        uVar2 = *(ushort *)(lVar17 + 10);
        uVar12 = (ulong)*(ushort *)(lVar17 + 0xc);
        bVar3 = *pbVar19;
      }
      else {
        bVar3 = *(byte *)(param_1 + -0x2c);
        regmap_read(*(undefined8 *)(param_1 + 0x18),iVar4 + *(int *)(param_1 + -0x30) + 0x5c,
                    (long)&local_70 + 4);
        iVar15 = *(int *)(param_1 + -0x30);
        uVar10 = *(undefined8 *)(param_1 + 0x18);
        lVar17 = lVar11 + lVar16 * 0x18;
        uVar13 = (uint)(-1L << ((ulong)bVar3 & 0x3f));
        uVar7 = local_70._4_4_ & (uVar13 ^ 0xffffffff);
        local_70 = CONCAT44(uVar7,(uint)local_70);
        *(short *)(lVar17 + 10) = (short)uVar7;
        regmap_read(uVar10,iVar4 + iVar15 + 0x9c,(long)&local_70 + 4);
        uVar2 = *(ushort *)(lVar17 + 10);
        uVar7 = (uint)uVar2 + (~local_70._4_4_ & (uVar13 ^ 0xffffffff));
        uVar12 = (ulong)uVar7;
        *(short *)(lVar17 + 0xc) = (short)uVar7;
        bVar3 = *pbVar19;
      }
      if ((ulong)bVar3 != 0) {
        uVar1 = (ulong)bVar3 + 1;
        uVar5 = 0;
        if (uVar1 != 0) {
          uVar5 = uVar14 / uVar1;
        }
        uVar13 = (uint)uVar1;
        uVar7 = 0;
        if (uVar13 != 0) {
          uVar7 = (((int)uVar14 - (int)uVar5 * uVar13) * 2 & 0xfffe) / uVar13;
        }
        uVar14 = (ulong)uVar7 + uVar5 * 2;
      }
      if (uVar6 != 0) {
        uVar7 = (uint)uVar12 & 0xffff;
        uVar6 = 0;
        if ((uVar12 & 0xffff) != 0) {
          uVar6 = uVar14 / (uVar12 & 0xffff);
        }
        uVar13 = 0;
        if ((uVar12 & 0xffff) != 0) {
          uVar13 = (((int)uVar14 - (int)uVar6 * uVar7) * (uint)uVar2) / uVar7;
        }
        uVar14 = (ulong)uVar13 + uVar6 * (uint)uVar2;
      }
      lVar16 = lVar16 + 1;
      *puVar18 = uVar14;
    } while (lVar16 != 8);
    lVar11 = *(long *)(param_1 + -0x20);
  }
  uVar8 = _freq_tbl_determine_rate(param_1,lVar11,param_2,1);
LAB_00115df8:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// clk_branch_enable @ 00115e64 size=80
// signature: undefined clk_branch_enable(void)
// callers: []
//------------------------------------------------------------

void clk_branch_enable(long param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + -8) == '\x05') || (iVar1 = clk_enable_regmap(param_1), iVar1 == 0)) {
    clk_branch_wait(param_1 + -0x20,1,clk_branch_check_halt);
  }
  return;
}



//------------------------------------------------------------
// clk_branch_disable @ 00115eb8 size=76
// signature: undefined clk_branch_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch_disable(long param_1)

{
  if (*(char *)(param_1 + -8) != '\x05') {
    clk_disable_regmap(param_1);
  }
  clk_branch_wait(param_1 + -0x20,0,clk_branch_check_halt);
  return;
}



//------------------------------------------------------------
// clk_branch_debug_init @ 00115f08 size=56
// signature: undefined clk_branch_debug_init(void)
// callers: []
//------------------------------------------------------------

void clk_branch_debug_init(undefined8 param_1,undefined8 param_2)

{
  clk_common_debug_init();
  clk_debug_measure_add(param_1,param_2);
  return;
}



//------------------------------------------------------------
// clk_branch2_enable @ 00115f44 size=80
// signature: undefined clk_branch2_enable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_enable(long param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + -8) == '\x05') || (iVar1 = clk_enable_regmap(param_1), iVar1 == 0)) {
    clk_branch_wait(param_1 + -0x20,1,clk_branch2_check_halt);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_disable @ 00115f98 size=76
// signature: undefined clk_branch2_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_disable(long param_1)

{
  if (*(char *)(param_1 + -8) != '\x05') {
    clk_disable_regmap(param_1);
  }
  clk_branch_wait(param_1 + -0x20,0,clk_branch2_check_halt);
  return;
}



//------------------------------------------------------------
// clk_branch_restore_context @ 00115fe8 size=84
// signature: undefined clk_branch_restore_context(void)
// callers: []
//------------------------------------------------------------

void clk_branch_restore_context(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar1 = clk_hw_get_flags();
  if (((uVar1 >> 0xb & 1) != 0) && (iVar2 = clk_enable_regmap(param_1), iVar2 != 0)) {
    uVar3 = clk_hw_get_name(param_1);
    _printk(&DAT_0011ced9,uVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_init @ 00116040 size=36
// signature: undefined clk_branch2_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_branch2_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_branch2_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_branch_restore_context_aon @ 00116068 size=72
// signature: undefined clk_branch_restore_context_aon(void)
// callers: []
//------------------------------------------------------------

void clk_branch_restore_context_aon(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = clk_enable_regmap();
  if (iVar1 != 0) {
    uVar2 = clk_hw_get_name(param_1);
    _printk(&DAT_0011ced9,uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_force_off_enable @ 001160b4 size=112
// signature: undefined clk_branch2_force_off_enable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_force_off_enable(long param_1)

{
  int iVar1;
  
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),0x400000,0,0,0,0);
  if ((*(char *)(param_1 + -8) == '\x05') || (iVar1 = clk_enable_regmap(param_1), iVar1 == 0)) {
    clk_branch_wait(param_1 + -0x20,1,clk_branch2_check_halt);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_force_off_disable @ 00116128 size=108
// signature: undefined clk_branch2_force_off_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_force_off_disable(long param_1)

{
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),0x400000,0x400000,0,0,0
            );
  if (*(char *)(param_1 + -8) != '\x05') {
    clk_disable_regmap(param_1);
  }
  clk_branch_wait(param_1 + -0x20,0,clk_branch2_check_halt);
  return;
}



//------------------------------------------------------------
// clk_branch2_mem_enable @ 00116198 size=436
// signature: undefined clk_branch2_mem_enable(void)
// callers: []
//------------------------------------------------------------

int clk_branch2_mem_enable(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_fc;
  undefined1 auStack_f8 [32];
  undefined1 auStack_d8 [24];
  undefined8 local_c0;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  memcpy(auStack_f8,(void *)(param_1 + -0x20),0xb0);
  local_fc = 0;
  if (*(char *)(param_1 + -0x28) == '\0') {
    uVar6 = *(undefined4 *)(param_1 + -0x30);
    uVar7 = uVar6;
  }
  else {
    uVar6 = *(undefined4 *)(param_1 + -0x2c);
    uVar7 = 0;
  }
  regmap_update_bits_base(local_c0,*(undefined4 *)(param_1 + -0x38),uVar6,uVar7,0,0,0);
  lVar3 = ktime_get();
  iVar2 = regmap_read(local_c0,*(undefined4 *)(param_1 + -0x34),&local_fc);
  if (iVar2 == 0) {
    do {
      if ((*(uint *)(param_1 + -0x30) & local_fc) != 0) {
LAB_00116308:
        if ((*(char *)(param_1 + -8) == '\x05') || (iVar2 = clk_enable_regmap(param_1), iVar2 == 0))
        {
          iVar2 = clk_branch_wait((void *)(param_1 + -0x20),1,clk_branch2_check_halt);
        }
        lVar3 = sp_el0;
        if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return iVar2;
      }
      lVar5 = ktime_get();
      if (lVar3 + 200000 < lVar5) {
        iVar2 = regmap_read(local_c0,*(undefined4 *)(param_1 + -0x34),&local_fc);
        if ((iVar2 == 0) && ((*(uint *)(param_1 + -0x30) & local_fc) != 0)) goto LAB_00116308;
        break;
      }
      Yield();
      iVar2 = regmap_read(local_c0,*(undefined4 *)(param_1 + -0x34),&local_fc);
    } while (iVar2 == 0);
  }
  uVar4 = clk_hw_get_name(auStack_d8);
  __warn_printk("%s mem enable failed\n",uVar4);
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11625c);
  (*pcVar1)();
}



//------------------------------------------------------------
// clk_branch2_mem_disable @ 00116350 size=128
// signature: undefined clk_branch2_mem_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_mem_disable(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + -0x28) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + -0x30);
    uVar2 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + -0x2c);
    uVar2 = uVar1;
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x38),uVar1,uVar2,0,0,0);
  if (*(char *)(param_1 + -8) != '\x05') {
    clk_disable_regmap(param_1);
  }
  clk_branch_wait(param_1 + -0x20,0,clk_branch2_check_halt);
  return;
}



//------------------------------------------------------------
// clk_branch2_mem_init @ 001163d4 size=36
// signature: undefined clk_branch2_mem_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_branch2_mem_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_branch2_mem_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_branch2_sreg_enable @ 001163fc size=180
// signature: undefined clk_branch2_sreg_enable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_sreg_enable(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar3 = clk_enable_regmap();
  if (iVar3 == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
    iVar3 = -200;
    do {
      if ((*(uint *)(param_1 + -0x10) & local_2c) == 0) {
        uVar4 = 0;
        goto LAB_00116484;
      }
      __const_udelay(0x10c7);
      regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
      bVar2 = iVar3 != -1;
      iVar3 = iVar3 + 1;
    } while (bVar2);
    uVar4 = 0xfffffff0;
  }
  else {
    uVar4 = 0xffffffea;
  }
LAB_00116484:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_sreg_disable @ 001164b4 size=156
// signature: undefined clk_branch2_sreg_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_sreg_disable(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  clk_disable_regmap();
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
  iVar3 = -200;
  do {
    if ((*(uint *)(param_1 + -0xc) & local_2c) != 0) break;
    __const_udelay(0x10c7);
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_hw_ctl_enable @ 00116554 size=68
// signature: undefined clk_branch2_hw_ctl_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_branch2_hw_ctl_enable(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = clk_hw_get_parent();
  if ((lVar1 == 0) || (uVar2 = clk_hw_is_prepared(), (uVar2 & 1) == 0)) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = clk_enable_regmap(param_1);
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_branch2_hw_ctl_disable @ 0011659c size=52
// signature: undefined clk_branch2_hw_ctl_disable(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_hw_ctl_disable(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = clk_hw_get_parent();
  if (lVar1 != 0) {
    clk_disable_regmap(param_1);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_hw_ctl_recalc_rate @ 001165d4 size=8
// signature: undefined clk_branch2_hw_ctl_recalc_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_branch2_hw_ctl_recalc_rate(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}



//------------------------------------------------------------
// clk_branch2_hw_ctl_determine_rate @ 001165e0 size=80
// signature: undefined clk_branch2_hw_ctl_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_branch2_hw_ctl_determine_rate(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = clk_hw_get_parent();
  if (lVar1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    param_2[4] = lVar1;
    uVar2 = clk_round_rate(*(undefined8 *)(lVar1 + 8),*param_2);
    uVar3 = 0;
    param_2[3] = uVar2;
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_branch_check_halt @ 00116634 size=160
// signature: undefined clk_branch_check_halt(void)
// callers: []
//------------------------------------------------------------

byte clk_branch_check_halt(long param_1,byte param_2)

{
  char cVar1;
  long lVar2;
  bool bVar3;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  cVar1 = *(char *)(param_1 + 0x18);
  local_3c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 4),&local_3c);
  lVar2 = sp_el0;
  bVar3 = (local_3c & (uint)(1L << ((ulong)*(byte *)(param_1 + 0xd) & 0x3f))) == 0;
  if (cVar1 != '\x01') {
    bVar3 = !bVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (bVar3 ^ param_2) & 1;
}



//------------------------------------------------------------
// clk_branch_wait @ 001166d4 size=444
// signature: undefined clk_branch_wait(void)
// callers: [clk_branch2_force_off_enable, clk_branch_disable, clk_branch2_mem_disable, clk_branch2_force_off_disable, clk_branch2_disable, clk_branch2_mem_enable, clk_branch_enable, clk_branch2_enable]
//------------------------------------------------------------

void clk_branch_wait(int *param_1,uint param_2,code *param_3)

{
  int *piVar1;
  undefined *puVar2;
  byte bVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  bVar3 = *(byte *)(param_1 + 6);
  uVar9 = (uint)bVar3;
  if (uVar9 != 3) {
    local_4c = 0;
    if (*param_1 != 0) {
      regmap_read(*(undefined8 *)(param_1 + 0xe),*param_1,&local_4c);
      if ((local_4c >> ((ulong)*(byte *)(param_1 + 3) & 0x3f) & 1) != 0) goto LAB_00116810;
      uVar9 = (uint)*(byte *)(param_1 + 6);
    }
    if ((uVar9 == 2) || ((param_2 & 1) == 0 && (char)bVar3 < '\0')) {
      __const_udelay(0xa7c6);
    }
    else if (((uVar9 < 6) && ((1 << (ulong)(uVar9 & 0x1f) & 0x23U) != 0)) ||
            (((param_2 & 1) != 0 && ((char)bVar3 < '\0')))) {
      piVar1 = param_1 + 8;
      iVar6 = clk_hw_get_rate(piVar1);
      iVar10 = 0;
      if (iVar6 != 0) {
        iVar10 = 1000000 / iVar6;
      }
      iVar10 = iVar10 * 3;
      if (iVar10 < 0xc9) {
        iVar10 = 200;
      }
      iVar6 = iVar10 + 1;
      while( true ) {
        if (*(int *)(param_3 + -4) != 0xd57f80c) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8235,0x1167cc);
          (*pcVar5)();
        }
        uVar7 = (*param_3)(param_1,param_2 & 1);
        if ((uVar7 & 1) != 0) break;
        __const_udelay(0x10c7);
        iVar6 = iVar6 + -1;
        if (iVar6 < 2) {
          clk_debug_print_hw(piVar1,0);
          if (*(undefined8 **)(param_1 + 0xc) == (undefined8 *)0x0) {
            uVar8 = clk_hw_get_name(piVar1);
          }
          else {
            uVar8 = **(undefined8 **)(param_1 + 0xc);
          }
          puVar2 = &DAT_0011cdca;
          if ((param_2 & 1) == 0) {
            puVar2 = &DAT_0011cca9;
          }
          __warn_printk("%s: status stuck at \'o%s\' after %d us",uVar8,puVar2,iVar10);
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11688c);
          (*pcVar5)();
        }
      }
    }
  }
LAB_00116810:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_check_halt @ 00116898 size=148
// signature: undefined clk_branch2_check_halt(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_check_halt(long param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 4),&local_2c);
  if (((param_2 & 1) == 0) || (*(char *)(param_1 + 0x18) == '\x04')) {
    uVar2 = local_2c >> 0x1f;
  }
  else {
    uVar2 = (uint)(-1 < (int)local_2c || local_2c >> 0x1c == 2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_list_registers @ 00116930 size=356
// signature: undefined clk_branch2_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_list_registers(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + -0x1c),&local_3c);
  if (param_1 == 0) {
    _printk(&DAT_0011cae5,&DAT_0011d195,local_3c);
    iVar1 = *(int *)(param_2 + -0x18);
  }
  else {
    seq_printf(param_1,"%20s: 0x%.8x\n",&DAT_0011d195);
    iVar1 = *(int *)(param_2 + -0x18);
  }
  if (iVar1 != 0) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),iVar1,&local_3c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"SREG_ENABLE_REG",local_3c);
      _printk(&DAT_0011cae5,"SREG_CORE_ACK_MASK",*(undefined4 *)(param_2 + -0x10));
      _printk(&DAT_0011cae5,"SREG_PERIPH_ACK_MASK",*(undefined4 *)(param_2 + -0xc));
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","SREG_ENABLE_REG");
      seq_printf(param_1,"%20s: 0x%.8x\n","SREG_CORE_ACK_MASK",*(undefined4 *)(param_2 + -0x10));
      seq_printf(param_1,"%20s: 0x%.8x\n","SREG_PERIPH_ACK_MASK",*(undefined4 *)(param_2 + -0xc));
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// clk_branch2_set_flags @ 00116a98 size=124
// signature: undefined clk_branch2_set_flags(void)
// callers: []
//------------------------------------------------------------

undefined4 clk_branch2_set_flags(long param_1,ulong param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 6) {
    uVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x1c),
                       *(undefined4 *)(&DAT_00122950 + param_2 * 4),
                       *(undefined4 *)(&DAT_00122938 + param_2 * 4),0,0,0);
    DataSynchronizationBarrier(3,3,0);
    __const_udelay(0x10c7);
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_branch2_mem_list_registers @ 00116b18 size=396
// signature: undefined clk_branch2_mem_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_branch2_mem_list_registers(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + -0x1c),&local_3c);
  if (param_1 == 0) {
    _printk(&DAT_0011cae5,&DAT_0011d195,local_3c);
    iVar1 = *(int *)(param_2 + -0x38);
  }
  else {
    seq_printf(param_1,"%20s: 0x%.8x\n",&DAT_0011d195);
    iVar1 = *(int *)(param_2 + -0x38);
  }
  if ((iVar1 != 0) && (*(int *)(param_2 + -0x34) != 0)) {
    regmap_read(*(undefined8 *)(param_2 + 0x18),iVar1,&local_3c);
    if (param_1 == 0) {
      _printk(&DAT_0011cae5,"MEM_ENABLE",local_3c);
      regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + -0x34),&local_3c);
      _printk(&DAT_0011cae5,"MEM_ENABLE_ACK",local_3c);
      _printk(&DAT_0011cae5,"MEM_ENABLE_ACK_MASK",*(undefined4 *)(param_2 + -0x30));
    }
    else {
      seq_printf(param_1,"%20s: 0x%.8x\n","MEM_ENABLE");
      regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + -0x34),&local_3c);
      seq_printf(param_1,"%20s: 0x%.8x\n","MEM_ENABLE_ACK",local_3c);
      seq_printf(param_1,"%20s: 0x%.8x\n","MEM_ENABLE_ACK_MASK",*(undefined4 *)(param_2 + -0x30));
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// div_recalc_rate @ 00116ca8 size=156
// signature: undefined div_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void div_recalc_rate(long param_1,undefined8 param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
  local_2c = local_2c >> (ulong)(*(uint *)(param_1 + -0x14) & 0x1f) &
             ((uint)(-1L << ((ulong)*(uint *)(param_1 + -0x10) & 0x3f)) ^ 0xffffffff);
  divider_recalc_rate(param_1,param_2,local_2c,*(undefined8 *)(param_1 + -8),
                      *(uint *)(param_1 + -0xc) | 0x10);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// div_round_rate @ 00116d48 size=108
// signature: undefined div_round_rate(void)
// callers: []
//------------------------------------------------------------

void div_round_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + -0x10);
  uVar2 = *(uint *)(param_1 + -0xc);
  uVar4 = *(undefined8 *)(param_1 + -8);
  uVar3 = clk_hw_get_parent();
  divider_round_rate_parent(param_1,uVar3,param_2,param_3,uVar4,uVar1,uVar2 | 0x10);
  return;
}



//------------------------------------------------------------
// div_set_rate @ 00116db8 size=116
// signature: undefined div_set_rate(void)
// callers: []
//------------------------------------------------------------

void div_set_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = divider_get_val(param_2,param_3,*(undefined8 *)(param_1 + -8),
                          *(undefined4 *)(param_1 + -0x10),*(uint *)(param_1 + -0xc) | 0x10);
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),
             (ulong)~(uint)(-1L << ((ulong)*(uint *)(param_1 + -0x10) & 0x3f)) <<
             ((ulong)*(uint *)(param_1 + -0x14) & 0x3f),
             iVar1 << (ulong)(*(uint *)(param_1 + -0x14) & 0x1f),0,0,0);
  return;
}



//------------------------------------------------------------
// div_round_ro_rate @ 00116e30 size=228
// signature: undefined div_round_ro_rate(void)
// callers: []
//------------------------------------------------------------

void div_round_ro_rate(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  iVar4 = clk_runtime_get_regmap();
  if (iVar4 == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_4c);
    local_4c = local_4c >> (ulong)(*(uint *)(param_1 + -0x14) & 0x1f) &
               ((uint)(-1L << ((ulong)*(uint *)(param_1 + -0x10) & 0x3f)) ^ 0xffffffff);
    clk_runtime_put_regmap(param_1);
    uVar3 = local_4c;
    uVar1 = *(undefined4 *)(param_1 + -0x10);
    uVar6 = clk_hw_get_parent(param_1);
    lVar5 = divider_ro_round_rate_parent(param_1,uVar6,param_2,param_3,0,uVar1,0x10,uVar3);
  }
  else {
    lVar5 = (long)iVar4;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// clk_regmap_div_init @ 00116f18 size=36
// signature: undefined clk_regmap_div_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_regmap_div_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined1 **)(param_1 + 0x58) = &clk_regmap_div_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_regmap_div_list_rate @ 00116f40 size=260
// signature: undefined clk_regmap_div_list_rate(void)
// callers: []
//------------------------------------------------------------

void clk_regmap_div_list_rate(long param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = clk_hw_get_parent();
  local_3c = 0;
  iVar1 = clk_runtime_get_regmap(param_1);
  if (iVar1 == 0) {
    regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_3c);
    local_3c = (local_3c >> (ulong)(*(uint *)(param_1 + -0x14) & 0x1f) &
               ((uint)(-1L << ((ulong)*(uint *)(param_1 + -0x10) & 0x3f)) ^ 0xffffffff)) + 1;
    clk_runtime_put_regmap(param_1);
    if (((lVar2 == 0) || (*(long *)(lVar2 + 0x58) == 0)) ||
       (pcVar4 = *(code **)(*(long *)(lVar2 + 0x58) + 8), pcVar4 == (code *)0x0)) {
      lVar2 = -0x16;
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x7b215f8f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x117000);
        (*pcVar4)();
      }
      lVar3 = (*pcVar4)(lVar2,param_2,param_3);
      lVar2 = 0;
      if ((ulong)local_3c != 0) {
        lVar2 = lVar3 / (long)(ulong)local_3c;
      }
    }
  }
  else {
    lVar2 = (long)iVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// mux_set_parent @ 00117048 size=104
// signature: undefined mux_set_parent(void)
// callers: []
//------------------------------------------------------------

void mux_set_parent(long param_1,byte param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + -0x14);
  if (*(long *)(param_1 + -8) != 0) {
    param_2 = *(byte *)(*(long *)(param_1 + -8) + (ulong)param_2 * 2 + 1);
  }
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),
             (uint)(0xffffffffffffffff >> ((ulong)-(uVar1 + *(int *)(param_1 + -0x10)) & 0x3f)) &
             (uint)(-1L << ((ulong)uVar1 & 0x3f)),(uint)param_2 << (ulong)(uVar1 & 0x1f),0,0,0);
  return;
}



//------------------------------------------------------------
// mux_get_parent @ 001170b4 size=160
// signature: undefined mux_get_parent(void)
// callers: []
//------------------------------------------------------------

uint mux_get_parent(long param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  iVar1 = *(int *)(param_1 + -0x10);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -0x18),&local_2c);
  local_2c = local_2c >> (ulong)(*(uint *)(param_1 + -0x14) & 0x1f) &
             (uint)(0xffffffffffffffff >> ((ulong)(uint)-iVar1 & 0x3f));
  uVar3 = local_2c;
  if (*(long *)(param_1 + -8) != 0) {
    uVar3 = qcom_find_cfg_index(param_1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_regmap_mux_init @ 00117158 size=36
// signature: undefined clk_regmap_mux_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_regmap_mux_init(long param_1)

{
  if (*(long *)(param_1 + 0x58) == 0) {
    *(undefined ***)(param_1 + 0x58) = &clk_regmap_mux_regmap_ops;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// clk_regmap_mux_list_registers @ 00117180 size=160
// signature: undefined clk_regmap_mux_list_registers(void)
// callers: []
//------------------------------------------------------------

void clk_regmap_mux_list_registers(long param_1,long param_2)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + -0x18),&local_2c);
  if (param_1 == 0) {
    _printk(&DAT_0011cae5,&DAT_0011d08b,local_2c);
  }
  else {
    seq_printf(param_1,"%20s: 0x%.8x\n",&DAT_0011d08b);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mux_div_set_src_div @ 00117224 size=316
// signature: undefined mux_div_set_src_div(void)
// callers: [mux_div_enable, mux_div_set_parent, __mux_div_set_rate_and_parent, mux_div_disable]
//------------------------------------------------------------

void mux_div_set_src_div(int *param_1,int param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar2 = clk_hw_get_name(param_1 + 0xe);
  local_3c = param_2 << (ulong)(param_1[4] & 0x1f) | param_3 << (ulong)(param_1[2] & 0x1f);
  uVar3 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x14),*param_1 + 4,
                     ~(uint)(-1L << ((ulong)(uint)param_1[3] & 0x3f)) <<
                     ((ulong)(uint)param_1[4] & 0x3f) |
                     ~(uint)(-1L << ((ulong)(uint)param_1[1] & 0x3f)) <<
                     ((ulong)(uint)param_1[2] & 0x3f),local_3c,0,0,0);
  if (((int)uVar3 == 0) &&
     (uVar3 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x14),*param_1,1,1,0,0,0),
     (int)uVar3 == 0)) {
    uVar4 = 0x1f5;
    do {
      uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x14),*param_1,&local_3c);
      if ((int)uVar3 != 0) goto LAB_00117330;
      if ((local_3c & 1) == 0) {
        uVar3 = 0;
        goto LAB_00117330;
      }
      __const_udelay(0x10c7);
      uVar4 = uVar4 - 1;
    } while (1 < uVar4);
    _printk(&DAT_0011c956,uVar2);
    uVar3 = 0xfffffff0;
  }
LAB_00117330:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mux_div_get_src_div @ 00117364 size=236
// signature: undefined mux_div_get_src_div(void)
// callers: [mux_div_get_parent, mux_div_recalc_rate]
//------------------------------------------------------------

void mux_div_get_src_div(int *param_1,uint *param_2,uint *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar2 = clk_hw_get_name(param_1 + 0xe);
  uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x14),*param_1,&local_3c);
  if ((int)uVar3 == 0) {
    if (((byte)local_3c >> 4 & 1) == 0) {
      uVar3 = regmap_read(*(undefined8 *)(param_1 + 0x14),*param_1 + 4,&local_3c);
      if ((int)uVar3 == 0) {
        *param_2 = local_3c >> (ulong)(param_1[4] & 0x1f) &
                   ((uint)(-1L << ((ulong)(uint)param_1[3] & 0x3f)) ^ 0xffffffff);
        *param_3 = local_3c >> (ulong)(param_1[2] & 0x1f) &
                   ((uint)(-1L << ((ulong)(uint)param_1[1] & 0x3f)) ^ 0xffffffff);
      }
    }
    else {
      _printk(&DAT_0011cb2d,uVar2);
      uVar3 = 0xfffffff0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mux_div_enable @ 00117454 size=40
// signature: undefined mux_div_enable(void)
// callers: []
//------------------------------------------------------------

void mux_div_enable(long param_1)

{
  mux_div_set_src_div(param_1 + -0x38,*(undefined4 *)(param_1 + -0x20),
                      *(undefined4 *)(param_1 + -0x24));
  return;
}



//------------------------------------------------------------
// mux_div_disable @ 00117480 size=40
// signature: undefined mux_div_disable(void)
// callers: []
//------------------------------------------------------------

void mux_div_disable(long param_1)

{
  mux_div_set_src_div(param_1 + -0x38,*(undefined4 *)(param_1 + -0x1c),
                      *(undefined4 *)(param_1 + -0x18));
  return;
}



//------------------------------------------------------------
// mux_div_recalc_rate @ 001174ac size=264
// signature: undefined mux_div_recalc_rate(void)
// callers: []
//------------------------------------------------------------

void mux_div_recalc_rate(long param_1)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  byte *pbVar9;
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_40 = 0;
  uVar3 = clk_hw_get_num_parents();
  uVar4 = clk_hw_get_name(param_1);
  mux_div_get_src_div(param_1 + -0x38,&local_40,(long)&local_40 + 4);
  if (0 < (int)uVar3) {
    uVar7 = 0;
    pbVar9 = (byte *)(*(long *)(param_1 + -8) + 1);
    do {
      if ((uint)local_40 == *pbVar9) {
        lVar5 = clk_hw_get_parent_by_index(param_1);
        if (lVar5 == 0) {
          lVar5 = -0x16;
        }
        else {
          uVar6 = clk_hw_get_rate();
          uVar8 = (ulong)(local_40._4_4_ + 1);
          uVar7 = 0;
          if (uVar8 != 0) {
            uVar7 = uVar6 / uVar8;
          }
          uVar1 = 0;
          if (uVar8 != 0) {
            uVar1 = ((uVar6 - uVar7 * uVar8) * 2) / uVar8;
          }
          lVar5 = uVar1 + uVar7 * 2;
        }
        goto LAB_00117584;
      }
      uVar7 = uVar7 + 1;
      pbVar9 = pbVar9 + 2;
    } while (uVar3 != uVar7);
  }
  _printk(&DAT_0011cb51,uVar4);
  lVar5 = 0;
LAB_00117584:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// mux_div_determine_rate @ 001175b8 size=320
// signature: undefined mux_div_determine_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 mux_div_determine_rate(long param_1,ulong *param_2)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  
  uVar9 = *param_2;
  iVar3 = clk_hw_get_num_parents();
  if (iVar3 != 0) {
    uVar8 = 0;
    uVar11 = 0;
    do {
      uVar5 = clk_hw_get_parent_by_index(param_1,uVar8);
      if (uVar5 == 0) {
        return 0xffffffea;
      }
      clk_hw_get_rate();
      uVar4 = (uint)(-1L << ((ulong)*(uint *)(param_1 + -0x34) & 0x3f));
      if (uVar4 < 0xfffffffe) {
        uVar7 = 1;
        uVar10 = uVar9 >> 1;
        do {
          uVar6 = clk_hw_round_rate(uVar5,(-(uVar9 & 1) & uVar7 >> 1) + uVar10);
          uVar1 = 0;
          if (uVar7 != 0) {
            uVar1 = uVar6 / uVar7;
          }
          uVar2 = 0;
          if (uVar7 != 0) {
            uVar2 = ((uVar6 - uVar1 * uVar7) * 2) / uVar7;
          }
          uVar2 = uVar2 + uVar1 * 2;
          if ((uVar9 <= uVar2 && uVar2 < uVar11) || ((uVar11 < uVar9 && (uVar11 < uVar2)))) {
            *param_2 = uVar2;
            param_2[3] = uVar6;
            param_2[4] = uVar5;
            uVar11 = uVar2;
          }
          uVar7 = uVar7 + 1;
          uVar10 = uVar10 + (uVar9 >> 1);
        } while ((uVar9 <= uVar2 && uVar9 < uVar11) && (uint)uVar7 < ~uVar4);
      }
      uVar8 = uVar8 + 1;
      uVar4 = clk_hw_get_num_parents(param_1);
    } while (uVar8 < uVar4);
    if (uVar11 != 0) {
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mux_div_set_parent @ 001176fc size=52
// signature: undefined mux_div_set_parent(void)
// callers: []
//------------------------------------------------------------

void mux_div_set_parent(long param_1,byte param_2)

{
  mux_div_set_src_div(param_1 + -0x38,
                      *(undefined1 *)(*(long *)(param_1 + -8) + (ulong)param_2 * 2 + 1),
                      *(undefined4 *)(param_1 + -0x24));
  return;
}



//------------------------------------------------------------
// mux_div_get_parent @ 00117734 size=220
// signature: undefined mux_div_get_parent(void)
// callers: []
//------------------------------------------------------------

ulong mux_div_get_parent(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  uint local_50;
  undefined1 auStack_4c [4];
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  uVar3 = clk_hw_get_name();
  local_50 = 0;
  mux_div_get_src_div(param_1 + -0x38,&local_50,auStack_4c);
  iVar2 = clk_hw_get_num_parents(param_1);
  uVar1 = local_50;
  if (iVar2 != 0) {
    uVar5 = 0;
    lVar6 = 1;
    do {
      if (uVar1 == *(byte *)(*(long *)(param_1 + -8) + lVar6)) goto LAB_001177d8;
      uVar5 = uVar5 + 1;
      uVar4 = clk_hw_get_num_parents(param_1);
      lVar6 = lVar6 + 2;
    } while (uVar5 < (uVar4 & 0xffffffff));
  }
  _printk(&DAT_0011d250,uVar3,uVar1);
  uVar5 = 0;
LAB_001177d8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// mux_div_set_rate @ 00117814 size=28
// signature: undefined mux_div_set_rate(void)
// callers: []
//------------------------------------------------------------

void mux_div_set_rate(void)

{
  __mux_div_set_rate_and_parent();
  return;
}



//------------------------------------------------------------
// mux_div_set_rate_and_parent @ 00117834 size=28
// signature: undefined mux_div_set_rate_and_parent(void)
// callers: []
//------------------------------------------------------------

void mux_div_set_rate_and_parent(void)

{
  __mux_div_set_rate_and_parent();
  return;
}



//------------------------------------------------------------
// __mux_div_set_rate_and_parent @ 00117850 size=364
// signature: undefined __mux_div_set_rate_and_parent(void)
// callers: [mux_div_set_rate, mux_div_set_rate_and_parent]
//------------------------------------------------------------

undefined8 __mux_div_set_rate_and_parent(long param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 local_70;
  
  iVar4 = clk_hw_get_num_parents();
  if (iVar4 == 0) {
    local_70 = 0;
  }
  else {
    uVar10 = 0;
    local_70 = 0;
    uVar12 = 0;
    do {
      lVar6 = clk_hw_get_parent_by_index(param_1,uVar10 & 0xffffffff);
      if (lVar6 == 0) {
        return 0xffffffea;
      }
      clk_hw_get_rate();
      uVar9 = (uint)(-1L << ((ulong)*(uint *)(param_1 + -0x34) & 0x3f));
      if (uVar9 < 0xfffffffe) {
        lVar11 = 0;
        uVar5 = param_2 >> 1;
        do {
          uVar1 = lVar11 + 1;
          uVar7 = clk_hw_round_rate(lVar6,(-(param_2 & 1) & uVar1 >> 1) + uVar5);
          uVar2 = 0;
          if (uVar1 != 0) {
            uVar2 = uVar7 / uVar1;
          }
          uVar3 = 0;
          if (uVar1 != 0) {
            uVar3 = ((uVar7 - uVar2 * uVar1) * 2) / uVar1;
          }
          uVar3 = uVar3 + uVar2 * 2;
          iVar4 = (int)lVar11;
          if ((param_2 <= uVar3 && uVar3 < uVar12) || ((uVar12 < param_2 && (uVar12 < uVar3)))) {
            local_70 = (ulong)CONCAT14(*(undefined1 *)(*(long *)(param_1 + -8) + uVar10 * 2 + 1),
                                       iVar4);
            uVar12 = uVar3;
          }
          lVar11 = lVar11 + 1;
          uVar5 = uVar5 + (param_2 >> 1);
        } while ((param_2 <= uVar3 && param_2 < uVar12) && iVar4 + 2U < ~uVar9);
      }
      uVar10 = uVar10 + 1;
      uVar5 = clk_hw_get_num_parents(param_1);
    } while (uVar10 < (uVar5 & 0xffffffff));
  }
  uVar8 = mux_div_set_src_div(param_1 + -0x38,local_70._4_4_,local_70 & 0xffffffff);
  if ((int)uVar8 == 0) {
    *(undefined4 *)(param_1 + -0x24) = (undefined4)local_70;
    *(undefined4 *)(param_1 + -0x20) = local_70._4_4_;
  }
  return uVar8;
}



//------------------------------------------------------------
// phy_mux_enable @ 001179c0 size=60
// signature: undefined phy_mux_enable(void)
// callers: []
//------------------------------------------------------------

void phy_mux_enable(long param_1)

{
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -8),3,0,0,0,0);
  return;
}



//------------------------------------------------------------
// phy_mux_disable @ 00117a00 size=60
// signature: undefined phy_mux_disable(void)
// callers: []
//------------------------------------------------------------

void phy_mux_disable(long param_1)

{
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -8),3,2,0,0,0);
  return;
}



//------------------------------------------------------------
// phy_mux_is_enabled @ 00117a40 size=120
// signature: undefined phy_mux_is_enabled(void)
// callers: []
//------------------------------------------------------------

void phy_mux_is_enabled(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  uint local_1c;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_1c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + -8),&local_1c);
  uVar1 = local_1c & 3;
  if ((local_1c & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x117ab4);
    local_1c = uVar1;
    (*pcVar3)();
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
    local_1c = uVar1;
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1 == 0);
  }
  return;
}



//------------------------------------------------------------
// clk_hfpll_enable @ 00117ac4 size=176
// signature: undefined clk_hfpll_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_hfpll_enable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined4 **)(param_1 + -0x10);
  local_4c = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x90);
  regmap_read(uVar3,*puVar4,&local_4c);
  if ((local_4c & 7) == 0) {
    __clk_hfpll_enable(param_1);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x90,uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_hfpll_disable @ 00117b78 size=108
// signature: undefined clk_hfpll_disable(void)
// callers: []
//------------------------------------------------------------

void clk_hfpll_disable(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x90);
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + 0x18),**(undefined4 **)(param_1 + -0x10),7,0,0,0,0);
  _raw_spin_unlock_irqrestore(param_1 + 0x90,uVar1);
  return;
}



//------------------------------------------------------------
// hfpll_is_enabled @ 00117be8 size=108
// signature: undefined hfpll_is_enabled(void)
// callers: []
//------------------------------------------------------------

void hfpll_is_enabled(long param_1)

{
  long lVar1;
  uint local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),**(undefined4 **)(param_1 + -0x10),&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(((local_1c ^ 0xffffffff) & 7) == 0);
  }
  return;
}



//------------------------------------------------------------
// clk_hfpll_recalc_rate @ 00117c58 size=112
// signature: undefined clk_hfpll_recalc_rate(void)
// callers: []
//------------------------------------------------------------

long clk_hfpll_recalc_rate(long param_1,long param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  regmap_read(*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(*(long *)(param_1 + -0x10) + 4),
              &local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)local_2c * param_2;
}



//------------------------------------------------------------
// clk_hfpll_round_rate @ 00117ccc size=60
// signature: undefined clk_hfpll_round_rate(void)
// callers: []
//------------------------------------------------------------

long clk_hfpll_round_rate(long param_1,ulong param_2,ulong *param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar3 = *param_3;
  uVar1 = *(ulong *)(*(long *)(param_1 + -0x10) + 0x40);
  uVar2 = *(ulong *)(*(long *)(param_1 + -0x10) + 0x48);
  if (uVar1 <= param_2) {
    uVar1 = param_2;
  }
  if (uVar2 <= param_2) {
    uVar1 = uVar2;
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = ((uVar3 + uVar1) - 1) / uVar3;
  }
  uVar4 = uVar4 * uVar3;
  if (uVar4 <= uVar2) {
    uVar3 = 0;
  }
  return uVar4 - uVar3;
}



//------------------------------------------------------------
// clk_hfpll_set_rate @ 00117d0c size=316
// signature: undefined clk_hfpll_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_hfpll_set_rate(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  uint local_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = param_2 / param_3;
  }
  lVar5 = *(long *)(param_1 + -0x10);
  local_5c = 0;
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x90);
  uVar3 = __clk_is_enabled(*(undefined8 *)(param_1 + 8));
  if ((uVar3 & 1) != 0) {
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x18),**(undefined4 **)(param_1 + -0x10),7,0,0,0,0);
  }
  if ((*(int *)(lVar5 + 0x10) != 0) && (*(int *)(lVar5 + 0x30) != 0)) {
    regmap_read(uVar4,*(int *)(lVar5 + 0x10),&local_5c);
    if (*(ulong *)(lVar5 + 0x38) < param_2) {
      local_5c = local_5c | *(uint *)(lVar5 + 0x30);
    }
    else {
      local_5c = local_5c & (*(uint *)(lVar5 + 0x30) ^ 0xffffffff);
    }
    regmap_write(uVar4,*(undefined4 *)(lVar5 + 0x10));
  }
  regmap_write(uVar4,*(undefined4 *)(lVar5 + 4),uVar1 & 0xffffffff);
  if ((uVar3 & 1) != 0) {
    __clk_hfpll_enable(param_1);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x90,uVar2);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// clk_hfpll_init @ 00117e4c size=208
// signature: undefined clk_hfpll_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_hfpll_init(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined4 **)(param_1 + -0x10);
  local_40 = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  regmap_read(uVar3,*puVar4,(long)&local_40 + 4);
  if (local_40._4_4_ == 7) {
    if (puVar4[7] != 0) {
      regmap_read(uVar3,puVar4[7],&local_40);
      if (((uint)local_40 >> ((ulong)*(byte *)(puVar4 + 8) & 0x3f) & 1) == 0) {
        uVar3 = __clk_get_name(*(undefined8 *)(param_1 + 8));
        __warn_printk("HFPLL %s is ON, but not locked!\n",uVar3);
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x117ee0);
        (*pcVar2)();
      }
    }
  }
  else {
    __clk_hfpll_init_once(param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// __clk_hfpll_enable @ 00117f58 size=340
// signature: undefined __clk_hfpll_enable(void)
// callers: [clk_hfpll_set_rate, clk_hfpll_enable]
//------------------------------------------------------------

void __clk_hfpll_enable(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = *(undefined4 **)(param_1 + -0x10);
  local_3c = 0;
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  __clk_hfpll_init_once();
  regmap_update_bits_base(uVar4,*puVar5,2,2,0,0,0);
  __const_udelay(0xa7c6);
  regmap_update_bits_base(uVar4,*puVar5,4,4,0,0,0);
  if (puVar5[7] == 0) {
    __const_udelay(0x3eea4);
  }
  else {
    lVar2 = ktime_get();
    iVar1 = regmap_read(uVar4,puVar5[7],&local_3c);
    if (iVar1 == 0) {
      do {
        if ((local_3c >> ((ulong)*(byte *)(puVar5 + 8) & 0x3f) & 1) == 0) break;
        lVar3 = ktime_get();
        if (lVar2 + 100000000 < lVar3) {
          regmap_read(uVar4,puVar5[7],&local_3c);
          break;
        }
        Yield();
        iVar1 = regmap_read(uVar4,puVar5[7],&local_3c);
      } while (iVar1 == 0);
    }
  }
  regmap_update_bits_base(uVar4,*puVar5,1,1,0,0,0);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __clk_hfpll_init_once @ 001180ac size=204
// signature: undefined __clk_hfpll_init_once(void)
// callers: [clk_hfpll_init, __clk_hfpll_enable]
//------------------------------------------------------------

void __clk_hfpll_init_once(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  if (*(int *)(param_1 + -8) == 0) {
    lVar5 = *(long *)(param_1 + -0x10);
    uVar3 = *(undefined8 *)(param_1 + 0x18);
    if (*(int *)(lVar5 + 0x28) != 0) {
      regmap_write(uVar3,*(undefined4 *)(lVar5 + 0x18));
    }
    regmap_write(uVar3,*(undefined4 *)(lVar5 + 8),0);
    regmap_write(uVar3,*(undefined4 *)(lVar5 + 0xc),1);
    if (*(int *)(lVar5 + 0x10) != 0) {
      uVar4 = *(uint *)(lVar5 + 0x2c);
      uVar2 = clk_hw_get_rate(param_1);
      uVar1 = *(uint *)(lVar5 + 0x30);
      if (uVar1 != 0) {
        if (uVar2 <= *(ulong *)(lVar5 + 0x38)) {
          uVar1 = 0;
        }
        uVar4 = uVar1 | uVar4;
      }
      regmap_write(uVar3,*(undefined4 *)(lVar5 + 0x10),uVar4);
    }
    if (*(int *)(lVar5 + 0x14) != 0) {
      regmap_write(uVar3,*(int *)(lVar5 + 0x14),*(undefined4 *)(lVar5 + 0x24));
    }
    *(undefined4 *)(param_1 + -8) = 1;
  }
  return;
}



//------------------------------------------------------------
// qcom_reset @ 0011817c size=176
// signature: undefined qcom_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_reset(long *param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  
  if (*(int *)(*(code **)(*param_1 + 8) + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1181b4);
    (*pcVar1)();
  }
  (**(code **)(*param_1 + 8))();
  uVar2 = (uint)*(byte *)(param_1[-2] + param_2 * 0xc + 5);
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  if (uVar2 < 0xb) {
    __udelay();
  }
  else {
    usleep_range_state((ulong)uVar2,(ulong)uVar2 << 1,2);
  }
  if (*(int *)(*(code **)(*param_1 + 0x10) + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x118214);
    (*pcVar1)();
  }
  (**(code **)(*param_1 + 0x10))(param_1,param_2);
  return 0;
}



//------------------------------------------------------------
// qcom_reset_assert @ 00118230 size=32
// signature: undefined qcom_reset_assert(void)
// callers: []
//------------------------------------------------------------

void qcom_reset_assert(undefined8 param_1,undefined8 param_2)

{
  qcom_reset_set(param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// qcom_reset_deassert @ 00118254 size=32
// signature: undefined qcom_reset_deassert(void)
// callers: []
//------------------------------------------------------------

void qcom_reset_deassert(undefined8 param_1,undefined8 param_2)

{
  qcom_reset_set(param_1,param_2,0);
  return;
}



//------------------------------------------------------------
// qcom_reset_set @ 00118274 size=388
// signature: undefined qcom_reset_set(void)
// callers: [qcom_reset_assert, qcom_reset_deassert]
//------------------------------------------------------------

int qcom_reset_set(long param_1,long param_2,ulong param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined4 *puVar9;
  undefined4 local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_4c = 0;
  puVar9 = (undefined4 *)(*(long *)(param_1 + -0x10) + param_2 * 0xc);
  iVar7 = puVar9[2];
  if (iVar7 == 0) {
    iVar7 = (int)(1L << ((ulong)*(byte *)(*(long *)(param_1 + -0x10) + param_2 * 0xc + 4) & 0x3f));
  }
  lVar8 = *(long *)(param_1 + 0x58);
  if (((*(ushort *)(lVar8 + 0x200) & 7) != 0) || (iVar6 = __pm_runtime_resume(lVar8,4), -1 < iVar6))
  {
    iVar6 = iVar7;
    if ((param_3 & 1) == 0) {
      iVar6 = 0;
    }
    iVar7 = regmap_update_bits_base(*(undefined8 *)(param_1 + -8),*puVar9,iVar7,iVar6,0,0,0);
    if (iVar7 == 0) {
      iVar7 = regmap_read(*(undefined8 *)(param_1 + -8),*puVar9,&local_4c);
    }
    if (((*(ushort *)(*(long *)(param_1 + 0x58) + 0x200) & 7) == 0) &&
       (iVar6 = __pm_runtime_idle(*(long *)(param_1 + 0x58),4), iVar6 < 0)) {
      __warn_printk("ret=%d\n",iVar6);
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x118360);
      (*pcVar4)();
    }
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar7;
  }
  piVar1 = (int *)(lVar8 + 0x1f8);
  iVar7 = *(int *)(lVar8 + 0x1f8);
  do {
    if (iVar7 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar7) goto LAB_00118390;
      cVar3 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar7 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00118390:
    bVar5 = iVar7 != iVar2;
    iVar7 = iVar2;
  } while (bVar5);
  __warn_printk("ret=%d\n",iVar6);
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1183d8);
  (*pcVar4)();
}



//------------------------------------------------------------
// register_qcom_clks_pm @ 00118414 size=132
// signature: undefined register_qcom_clks_pm(void)
// callers: []
//------------------------------------------------------------

ulong register_qcom_clks_pm(ulong param_1,ulong param_2,undefined8 param_3)

{
  ulong uVar1;
  
  if ((param_1 == 0) || (0xfffffffffffff000 < param_1)) {
    param_1 = param_1 & 0xffffffff;
  }
  else {
    if ((param_2 & 1) == 0) {
      *(undefined1 **)(*(long *)(param_1 + 0x98) + 0x78) = clock_pm_ops;
      *(undefined8 *)(param_1 + 0xa8) = param_3;
    }
    else {
      *(undefined1 **)(*(long *)(param_1 + 0x98) + 0x78) = &clock_pm_rt_ops;
      uVar1 = qcom_cc_runtime_init(param_1,param_3);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      uVar1 = __pm_runtime_resume(param_1 + 0x10,4);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
    }
    param_1 = 0;
  }
  return param_1;
}



//------------------------------------------------------------
// clock_pm_resume_early @ 0011849c size=120
// signature: undefined clock_pm_resume_early(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 clock_pm_resume_early(long param_1)

{
  undefined8 uVar1;
  
  if (_pm_suspend_target_state == 3) {
    if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
      uVar1 = __pm_runtime_resume(param_1,4);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      clk_restore_context();
    }
    clk_restore_critical_clocks(param_1);
    if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
      __pm_runtime_idle(param_1,4);
    }
  }
  return 0;
}



//------------------------------------------------------------
// clock_pm_restore_early @ 00118518 size=104
// signature: undefined clock_pm_restore_early(void)
// callers: []
//------------------------------------------------------------

undefined8 clock_pm_restore_early(long param_1)

{
  undefined8 uVar1;
  
  if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
    uVar1 = __pm_runtime_resume(param_1,4);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    clk_restore_context();
  }
  clk_restore_critical_clocks(param_1);
  if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
    __pm_runtime_idle(param_1,4);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_clk_state @ 00118584 size=148
// signature: undefined __traceiter_clk_state(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_clk_state
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001239e0;
  plVar2 = DAT_001239e0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x479ab3db) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1185f0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_clk_measure @ 0011861c size=116
// signature: undefined __traceiter_clk_measure(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_clk_measure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00123a28;
  plVar2 = _DAT_00123a28;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5fc0bda5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11866c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_clk_state_dump @ 00118694 size=276
// signature: undefined trace_event_raw_event_clk_state_dump(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_clk_state_dump
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,
               undefined4 param_6)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x28);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x24;
      strcpy((char *)(lVar3 + 0x24),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined8 *)(lVar3 + 0x18) = param_5;
      *(undefined4 *)(lVar3 + 0x20) = param_6;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_clk_state_dump @ 001187ac size=356
// signature: undefined perf_trace_clk_state_dump(void)
// callers: []
//------------------------------------------------------------

void perf_trace_clk_state_dump
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,
               undefined4 param_6)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [8];
  undefined4 local_78;
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
  local_78 = param_6;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x34U & 0xfffffff8) - 4;
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
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10024;
      strcpy((char *)(lVar5 + 0x24),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined8 *)(lVar5 + 0x18) = param_5;
      *(undefined4 *)(lVar5 + 0x20) = local_78;
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
// trace_event_raw_event_clk_measure_support @ 00118914 size=240
// signature: undefined trace_event_raw_event_clk_measure_support(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_clk_measure_support(long param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x18;
      strcpy((char *)(lVar3 + 0x18),__s);
      *(undefined8 *)(lVar3 + 0x10) = param_3;
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_clk_measure_support @ 00118a08 size=328
// signature: undefined perf_trace_clk_measure_support(void)
// callers: []
//------------------------------------------------------------

void perf_trace_clk_measure_support(long param_1,char *param_2,undefined8 param_3)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10018;
      strcpy((char *)(lVar5 + 0x18),__s);
      *(undefined8 *)(lVar5 + 0x10) = param_3;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_clk_state_dump @ 00118b54 size=40
// signature: undefined __bpf_trace_clk_state_dump(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_clk_state_dump
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_clk_measure_support @ 00118b80 size=28
// signature: undefined __bpf_trace_clk_measure_support(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_clk_measure_support(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// clk_debug_mux_set_parent @ 00118ba0 size=408
// signature: undefined clk_debug_mux_set_parent(void)
// callers: []
//------------------------------------------------------------

int clk_debug_mux_set_parent(long param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  uint uVar6;
  
  if (*(long *)(param_1 + -0x58) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = clk_hw_get_num_parents();
    if (iVar1 != 0) {
      uVar6 = 0;
      do {
        if ((*(int *)(param_1 + -0x50) <= (int)uVar6) ||
           (*(int *)(*(long *)(param_1 + -0x58) + (long)(int)uVar6 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar6);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            iVar1 = clk_runtime_get_regmap(uVar4);
            if (iVar1 != 0) {
              return iVar1;
            }
            break;
          }
        }
        uVar6 = uVar6 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar6 < uVar2);
    }
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + -0x38),*(undefined4 *)(param_1 + -0x24),
                       *(undefined4 *)(param_1 + -0x1c),
                       *(int *)(*(long *)(param_1 + -0x58) + (param_2 & 0xff) * 4) <<
                       (ulong)(*(uint *)(param_1 + -0x18) & 0x1f),0,0,0);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + -0x14) == -1) {
        iVar1 = 0;
      }
      else {
        iVar1 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + -0x38),*(int *)(param_1 + -0x14),
                           *(undefined4 *)(param_1 + -0x10),
                           *(int *)(param_1 + -8) + -1 << (ulong)(*(uint *)(param_1 + -0xc) & 0x1f),
                           0,0,0);
      }
    }
    iVar3 = clk_hw_get_num_parents(param_1);
    if (iVar3 != 0) {
      uVar6 = 0;
      do {
        if ((*(int *)(param_1 + -0x50) <= (int)uVar6) ||
           (*(int *)(*(long *)(param_1 + -0x58) + (long)(int)uVar6 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar6);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            clk_runtime_put_regmap(uVar4);
            return iVar1;
          }
        }
        uVar6 = uVar6 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar6 < uVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// clk_debug_mux_get_parent @ 00118d3c size=160
// signature: undefined clk_debug_mux_get_parent(void)
// callers: [get_mux_divs]
//------------------------------------------------------------

int clk_debug_mux_get_parent(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *__s1;
  char *__s2;
  int iVar5;
  
  iVar1 = clk_hw_get_num_parents();
  lVar3 = clk_hw_get_parent(param_1);
  if ((lVar3 != 0) && (0 < iVar1)) {
    iVar5 = 0;
    do {
      lVar4 = clk_hw_get_parent_by_index(param_1,iVar5);
      if (lVar4 == 0) {
        return 0xff;
      }
      __s1 = (char *)clk_hw_get_name();
      __s2 = (char *)clk_hw_get_name(lVar3);
      iVar2 = strcmp(__s1,__s2);
      if (iVar2 == 0) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar1 != iVar5);
  }
  return 0xff;
}



//------------------------------------------------------------
// clk_debug_mux_init @ 00118de0 size=132
// signature: undefined clk_debug_mux_init(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_debug_mux_init(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  iVar1 = clk_hw_get_num_parents();
  if (iVar1 != 0) {
    uVar4 = 0;
    do {
      lVar3 = clk_hw_get_parent_by_index(param_1,uVar4 & 0xffffffff);
      if ((lVar3 == 0) && (uVar4 < *(uint *)(param_1 + -0x50))) {
        *(undefined4 *)(*(long *)(param_1 + -0x58) + uVar4 * 4) = 0xdeadbeef;
      }
      uVar4 = uVar4 + 1;
      uVar2 = clk_hw_get_num_parents(param_1);
    } while (uVar4 < (uVar2 & 0xffffffff));
  }
  return 0;
}



//------------------------------------------------------------
// clk_debug_measure_add @ 00118e68 size=56
// signature: undefined clk_debug_measure_add(void)
// callers: [clk_branch_debug_init]
//------------------------------------------------------------

void clk_debug_measure_add(undefined8 param_1,undefined8 param_2)

{
  debugfs_create_file("clk_measure",0x124,param_2,param_1,&clk_measure_fops);
  return;
}



//------------------------------------------------------------
// devm_clk_register_debug_mux @ 00118ea4 size=148
// signature: undefined devm_clk_register_debug_mux(void)
// callers: []
//------------------------------------------------------------

ulong devm_clk_register_debug_mux(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = devm_clk_register(param_1,param_2 + 0x58);
    if (uVar3 < 0xfffffffffffff001) {
      mutex_lock(clk_debug_lock);
      puVar2 = clk_hw_debug_mux_list;
      puVar1 = (undefined *)(param_2 + 0x70);
      uVar3 = __list_add_valid(puVar1,&clk_hw_debug_mux_list,clk_hw_debug_mux_list);
      if ((uVar3 & 1) != 0) {
        *(undefined **)(puVar2 + 8) = puVar1;
        *(undefined **)(param_2 + 0x70) = puVar2;
        *(undefined ***)(param_2 + 0x78) = &clk_hw_debug_mux_list;
        clk_hw_debug_mux_list = puVar1;
      }
      mutex_unlock(clk_debug_lock);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// clk_debug_measure_register @ 00118f3c size=88
// signature: undefined clk_debug_measure_register(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_debug_measure_register(undefined **param_1)

{
  undefined **ppuVar1;
  
  if ((measure != (undefined **)0x0) && (measure < 0xfffffffffffff001)) {
    return 0;
  }
  if (param_1 != (undefined **)0x0) {
    ppuVar1 = &clk_hw_debug_mux_list;
    while (ppuVar1 = (undefined **)*ppuVar1, ppuVar1 != &clk_hw_debug_mux_list) {
      if (ppuVar1 + -3 == param_1) {
        measure = param_1;
        return 0;
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// map_debug_bases @ 00118f98 size=140
// signature: undefined map_debug_bases(void)
// callers: []
//------------------------------------------------------------

undefined4 map_debug_bases(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = of_get_property(*(undefined8 *)(param_1 + 0x2f8),param_2,0);
  if (lVar2 == 0) {
    uVar1 = 0xffffffcb;
  }
  else {
    uVar3 = syscon_regmap_lookup_by_phandle(*(undefined8 *)(param_1 + 0x2f8),param_2);
    *(ulong *)(param_3 + 0x20) = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      regmap_mmio_detach_clk(uVar3);
      uVar1 = 0;
    }
    else {
      _printk(&DAT_0011d14d,param_2);
      uVar1 = *(undefined4 *)(param_3 + 0x20);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// clk_debug_print_hw @ 00119028 size=212
// signature: undefined clk_debug_print_hw(void)
// callers: [clk_rcg2_set_force_enable, print_hw_show, clk_branch_wait, clk_debug_print_hw, __alpha_pll_trion_set_rate, update_config, alpha_pll_lucid_evo_set_rate, wait_for_pll, qcom_clk_dump]
//------------------------------------------------------------

void clk_debug_print_hw(long *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  code *pcVar4;
  
  if (((param_1 != (long *)0x0) && (param_1 < (long *)0xfffffffffffff001)) && (*param_1 != 0)) {
    uVar2 = clk_hw_get_parent(param_1);
    clk_debug_print_hw(uVar2,param_2);
    uVar2 = clk_hw_get_name(param_1);
    if (param_2 == 0) {
      _printk(&DAT_0011dc67,uVar2);
    }
    else {
      seq_printf(param_2,&DAT_0011d775);
    }
    uVar3 = clk_is_regmap_clk(param_1);
    if (((uVar3 & 1) != 0) && (iVar1 = clk_runtime_get_regmap(param_1), iVar1 == 0)) {
      if (((undefined8 *)param_1[0xb] != (undefined8 *)0x0) &&
         (pcVar4 = *(code **)param_1[0xb], pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != -0x3770eab4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1190cc);
          (*pcVar4)();
        }
        (*pcVar4)(param_2,param_1);
      }
      clk_runtime_put_regmap(param_1);
    }
  }
  return;
}



//------------------------------------------------------------
// clk_common_debug_init @ 00119100 size=184
// signature: undefined clk_common_debug_init(void)
// callers: [clk_branch_debug_init]
//------------------------------------------------------------

void clk_common_debug_init(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x40) != 0) {
    debugfs_create_file("clk_rate_max",0x124,param_2,param_1,rate_max_fops);
  }
  if ((*(long *)(param_1 + 0x58) != 0) && (*(long *)(*(long *)(param_1 + 0x58) + 8) != 0)) {
    debugfs_create_file("clk_list_rates",0x124,param_2,param_1,list_rates_fops);
  }
  debugfs_create_file("clk_print_regs",0x124,param_2,param_1,clock_print_hw_fops);
  if ((qcom_clk_debug_inited & 1) == 0) {
    clk_debug_init();
    qcom_clk_debug_inited = 1;
  }
  return;
}



//------------------------------------------------------------
// clk_debug_init @ 001191bc size=360
// signature: undefined clk_debug_init(void)
// callers: [clk_common_debug_init]
//------------------------------------------------------------

ulong clk_debug_init(void)

{
  ulong uVar1;
  ulong uVar2;
  
  clk_debug_init_rootdir = debugfs_lookup(&DAT_0011cef0,0);
  if ((clk_debug_init_rootdir == 0) || (0xfffffffffffff000 < clk_debug_init_rootdir)) {
    _printk(&DAT_0011d779,"clk_debug_init");
    uVar2 = 0;
  }
  else {
    debugfs_create_file("clk_enabled_list",0x124,clk_debug_init_rootdir,&clk_hw_debug_list,
                        clk_enabled_list_fops);
    debugfs_create_file("trace_clocks",0x124,clk_debug_init_rootdir,&clk_hw_debug_list,
                        clk_enabled_trace_fops);
    clk_debugfs_suspend =
         debugfs_create_file_unsafe
                   ("debug_suspend",0x1a4,clk_debug_init_rootdir,0,&clk_debug_suspend_enable_fops);
    clk_debugfs_suspend_atomic =
         debugfs_create_file_unsafe
                   ("debug_suspend_atomic",0x1a4,clk_debug_init_rootdir,0,
                    &clk_debug_suspend_atomic_enable_fops);
    dput(clk_debug_init_rootdir);
    uVar2 = clk_debugfs_suspend;
    if (clk_debugfs_suspend < 0xfffffffffffff001) {
      uVar2 = 0;
    }
    else {
      _printk(&DAT_0011d3d0,"clk_debug_init",clk_debugfs_suspend & 0xffffffff);
    }
    uVar1 = clk_debugfs_suspend_atomic;
    if (0xfffffffffffff000 < clk_debugfs_suspend_atomic) {
      _printk(&DAT_0011d5c5,"clk_debug_init",clk_debugfs_suspend_atomic & 0xffffffff);
      uVar2 = uVar1 & 0xffffffff;
    }
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// clk_hw_debug_register @ 00119328 size=196
// signature: undefined clk_hw_debug_register(void)
// callers: [devm_clk_register_regmap]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 clk_hw_debug_register(long param_1,long param_2)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    _printk(&DAT_0011ce4b,"clk_hw_debug_register");
    uVar4 = 0xffffffea;
  }
  else {
    puVar2 = (undefined8 *)kmalloc_trace(_clk_disable,0xdc0,0x20);
    if (puVar2 == (undefined8 *)0x0) {
      uVar4 = 0xfffffff4;
    }
    else {
      puVar2[2] = param_2;
      puVar2[3] = param_1;
      mutex_lock(clk_debug_lock);
      puVar1 = clk_hw_debug_list;
      uVar3 = __list_add_valid(puVar2,&clk_hw_debug_list,clk_hw_debug_list);
      if ((uVar3 & 1) != 0) {
        *(undefined8 **)(puVar1 + 8) = puVar2;
        *puVar2 = puVar1;
        puVar2[1] = &clk_hw_debug_list;
        clk_hw_debug_list = (undefined *)puVar2;
      }
      mutex_unlock(clk_debug_lock);
      uVar4 = 0;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// clk_debug_exit @ 001193f0 size=220
// signature: undefined clk_debug_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void clk_debug_exit(void)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  debugfs_remove(clk_debugfs_suspend);
  debugfs_remove(clk_debugfs_suspend_atomic);
  if (debug_suspend != '\0') {
    tracepoint_probe_unregister(&__tracepoint_suspend_resume,clk_debug_suspend_trace_probe,0);
  }
  mutex_lock(clk_debug_lock);
  ppuVar4 = (undefined **)clk_hw_debug_list;
  if ((undefined **)clk_hw_debug_list != &clk_hw_debug_list) {
    do {
      ppuVar5 = (undefined **)*ppuVar4;
      if (ppuVar4 != (undefined **)0x0) {
        uVar3 = __list_del_entry_valid(ppuVar4);
        if ((uVar3 & 1) != 0) {
          puVar1 = *ppuVar4;
          plVar2 = (long *)ppuVar4[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar4 = &DAT_dead000000000100;
        ppuVar4[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar4);
      }
      ppuVar4 = ppuVar5;
    } while (ppuVar5 != &clk_hw_debug_list);
  }
  mutex_unlock(clk_debug_lock);
  return;
}



//------------------------------------------------------------
// clk_debug_suspend_trace_probe @ 001194d0 size=76
// signature: undefined clk_debug_suspend_trace_probe(void)
// callers: []
//------------------------------------------------------------

void clk_debug_suspend_trace_probe(undefined8 param_1,char *param_2,int param_3,uint param_4)

{
  int iVar1;
  
  if (((0 < param_3) && ((param_4 & 1) != 0)) &&
     (iVar1 = strcmp("machine_suspend",param_2), iVar1 == 0)) {
    _printk(&DAT_0011d62e);
    clock_debug_print_enabled_clocks(0);
  }
  return;
}



//------------------------------------------------------------
// qcom_clk_dump @ 00119520 size=180
// signature: undefined qcom_clk_dump(void)
// callers: [qcom_clk_bulk_dump]
//------------------------------------------------------------

void qcom_clk_dump(ulong param_1,ulong param_2,uint param_3)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if ((param_2 != 0) && (param_2 < 0xfffffffffffff001)) {
    gdsc_debug_print_regs(param_2);
  }
  if ((((param_1 != 0) && (param_1 < 0xfffffffffffff001)) &&
      (uVar2 = __clk_get_hw(param_1), uVar2 != 0)) && (uVar2 < 0xfffffffffffff001)) {
    uVar3 = clk_hw_get_name(uVar2);
    _printk(&DAT_0011d353,uVar3);
    clk_debug_print_hw(uVar2,0);
    if ((param_3 & 1) != 0) {
      if (*(undefined8 **)(uVar2 + 0x10) == (undefined8 *)0x0) {
        uVar3 = clk_hw_get_name(uVar2);
      }
      else {
        uVar3 = **(undefined8 **)(uVar2 + 0x10);
      }
      __warn_printk(&DAT_0011ca8a,uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1195d4);
      (*pcVar1)();
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_clk_bulk_dump @ 001195dc size=128
// signature: undefined qcom_clk_bulk_dump(void)
// callers: []
//------------------------------------------------------------

void qcom_clk_bulk_dump(uint param_1,ulong param_2,ulong param_3,uint param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if ((param_3 != 0) && (param_3 < 0xfffffffffffff001)) {
    gdsc_debug_print_regs(param_3);
  }
  if (((param_2 != 0) && (param_2 < 0xfffffffffffff001)) && (0 < (int)param_1)) {
    uVar2 = (ulong)param_1;
    puVar1 = (undefined8 *)(param_2 + 8);
    do {
      qcom_clk_dump(*puVar1,0,param_4 & 1);
      uVar2 = uVar2 - 1;
      puVar1 = puVar1 + 2;
    } while (uVar2 != 0);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_clk_state_dump @ 00119660 size=116
// signature: undefined trace_raw_output_clk_state_dump(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_clk_state_dump(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s\tprepare:enable cnt [%u:%u]\trate: vdd_level [%lu:%u]\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18),
                       *(undefined4 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_clk_measure_support @ 001196d8 size=108
// signature: undefined trace_raw_output_clk_measure_support(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_clk_measure_support(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s rate: %lu\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// clk_measure_fops_open @ 00119748 size=52
// signature: undefined clk_measure_fops_open(void)
// callers: []
//------------------------------------------------------------

void clk_measure_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,clk_debug_measure_get,clk_debug_measure_set,"%lld\n");
  return;
}



//------------------------------------------------------------
// clk_debug_measure_get @ 00119780 size=896
// signature: undefined clk_debug_measure_get(void)
// callers: []
//------------------------------------------------------------

int clk_debug_measure_get(undefined8 param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar2 = measure;
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_70 = 0;
  if (measure == 0) {
    iVar3 = -0x16;
    goto LAB_00119a68;
  }
  iVar3 = clk_hw_get_num_parents(measure);
  if (iVar3 != 0) {
    uVar5 = 0;
    do {
      if ((*(int *)(lVar2 + -0x50) <= (int)uVar5) ||
         (*(int *)(*(long *)(lVar2 + -0x58) + (long)(int)uVar5 * 4) != -0x21524111)) {
        uVar9 = clk_hw_get_parent_by_index(lVar2,uVar5);
        uVar10 = clk_is_regmap_clk();
        if ((uVar10 & 1) != 0) {
          iVar3 = clk_runtime_get_regmap(uVar9);
          if (iVar3 != 0) goto LAB_00119a68;
          break;
        }
      }
      uVar5 = uVar5 + 1;
      uVar4 = clk_hw_get_num_parents(lVar2);
    } while (uVar5 < uVar4);
  }
  mutex_lock(clk_debug_lock);
  iVar3 = clk_find_and_set_parent(measure,param_1);
  if (iVar3 == 0) {
    ppuVar7 = (undefined **)clk_hw_get_parent(measure);
    if (ppuVar7 == (undefined **)0x0) {
LAB_001198a4:
      iVar3 = enable_debug_clks(measure);
      lVar1 = measure;
      if (iVar3 != 0) goto LAB_001199f4;
      local_6c = 0;
      puVar11 = *(undefined8 **)(measure + -0x30);
      uVar9 = *puVar11;
      iVar3 = clk_prepare(uVar9);
      if ((iVar3 == 0) && (iVar3 = clk_enable(uVar9), iVar3 != 0)) {
        clk_unprepare(uVar9);
      }
      uVar9 = _raw_spin_lock_irqsave(&clk_reg_lock);
      regmap_read(*(undefined8 *)(lVar1 + -0x38),*(undefined4 *)(puVar11 + 2),&local_6c);
      local_6c = local_6c | 1;
      regmap_write(*(undefined8 *)(lVar1 + -0x38),*(undefined4 *)(puVar11 + 2));
      uVar5 = run_measurement(0x1000,*(undefined8 *)(lVar1 + -0x38),*(undefined4 *)(puVar11 + 1),
                              *(undefined4 *)((long)puVar11 + 0xc));
      uVar4 = run_measurement(0x20000,*(undefined8 *)(lVar1 + -0x38),*(undefined4 *)(puVar11 + 1),
                              *(undefined4 *)((long)puVar11 + 0xc));
      local_6c = local_6c & 0xfffffffe;
      regmap_write(*(undefined8 *)(lVar1 + -0x38),*(undefined4 *)(puVar11 + 2));
      if (uVar4 == uVar5) {
        uVar10 = 0;
      }
      else {
        uVar10 = ((ulong)uVar4 * 48000000 + 72000000) / 0x140023;
      }
      _raw_spin_unlock_irqrestore(&clk_reg_lock,uVar9);
      uVar9 = *puVar11;
      clk_disable(uVar9);
      clk_unprepare(uVar9);
      *param_2 = uVar10;
      uVar10 = get_mux_divs(measure);
      *param_2 = *param_2 * (uVar10 & 0xffffffff);
      disable_debug_clks(measure);
LAB_001199e0:
      clk_hw_get_name(param_1);
    }
    else {
      ppuVar8 = &clk_hw_debug_mux_list;
      do {
        ppuVar8 = (undefined **)*ppuVar8;
        if (ppuVar8 == &clk_hw_debug_mux_list) goto LAB_001198a4;
      } while (ppuVar8 + -3 != ppuVar7);
      if ((ppuVar7 + -0xb == (undefined **)0x0) || (ppuVar7[-0xb] != (undefined *)0x0))
      goto LAB_001198a4;
      regmap_read(ppuVar7[-7],*(undefined4 *)((long)ppuVar7 + -4),&local_70);
      if (local_70 != 0) {
        uVar10 = 0;
        if ((ulong)local_70 != 0) {
          uVar10 = 1000000000000 / (ulong)local_70;
        }
        *param_2 = uVar10;
        goto LAB_001199e0;
      }
      _printk(&DAT_0011d910);
    }
    iVar3 = 0;
  }
  else {
    _printk(&DAT_0011d987);
  }
LAB_001199f4:
  mutex_unlock(clk_debug_lock);
  iVar6 = clk_hw_get_num_parents(lVar2);
  if (iVar6 != 0) {
    uVar5 = 0;
    do {
      if ((*(int *)(lVar2 + -0x50) <= (int)uVar5) ||
         (*(int *)(*(long *)(lVar2 + -0x58) + (long)(int)uVar5 * 4) != -0x21524111)) {
        uVar9 = clk_hw_get_parent_by_index(lVar2,uVar5);
        uVar10 = clk_is_regmap_clk();
        if ((uVar10 & 1) != 0) {
          clk_runtime_put_regmap(uVar9);
          break;
        }
      }
      uVar5 = uVar5 + 1;
      uVar4 = clk_hw_get_num_parents(lVar2);
    } while (uVar5 < uVar4);
  }
LAB_00119a68:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// clk_debug_measure_set @ 00119ba4 size=424
// signature: undefined clk_debug_measure_set(void)
// callers: []
//------------------------------------------------------------

int clk_debug_measure_set(undefined **param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined **ppuVar6;
  uint uVar7;
  
  if (param_1 == (undefined **)0x0) {
LAB_00119c54:
    iVar1 = 0;
  }
  else {
    ppuVar6 = &clk_hw_debug_mux_list;
    do {
      ppuVar6 = (undefined **)*ppuVar6;
      if (ppuVar6 == &clk_hw_debug_mux_list) goto LAB_00119c54;
    } while (ppuVar6 + -3 != param_1);
    iVar1 = clk_hw_get_num_parents(param_1);
    if (iVar1 != 0) {
      uVar7 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar7) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar7 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar7);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            iVar1 = clk_runtime_get_regmap(uVar4);
            if (iVar1 != 0) {
              return iVar1;
            }
            break;
          }
        }
        uVar7 = uVar7 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar7 < uVar2);
    }
    mutex_lock(clk_debug_lock);
    regmap_update_bits_base
              (param_1[-7],*(undefined4 *)((long)param_1 + -0x24),
               *(undefined4 *)((long)param_1 + -0x1c),
               param_2 << (ulong)(*(uint *)(param_1 + -3) & 0x1f),0,0,0);
    iVar1 = clk_set_parent(param_1[1],0);
    if (iVar1 != 0) {
      _printk(&DAT_0011dcf9);
    }
    mutex_unlock(clk_debug_lock);
    iVar3 = clk_hw_get_num_parents(param_1);
    if (iVar3 != 0) {
      uVar7 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar7) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar7 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar7);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            clk_runtime_put_regmap(uVar4);
            return iVar1;
          }
        }
        uVar7 = uVar7 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar7 < uVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// clk_find_and_set_parent @ 00119d4c size=272
// signature: undefined clk_find_and_set_parent(void)
// callers: [clk_find_and_set_parent, clk_debug_measure_get]
//------------------------------------------------------------

undefined8 clk_find_and_set_parent(undefined **param_1,undefined **param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined **ppuVar5;
  uint uVar6;
  
  uVar3 = 0xffffffea;
  if ((param_1 != (undefined **)0x0) && (param_2 != (undefined **)0x0)) {
    ppuVar5 = &clk_hw_debug_mux_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &clk_hw_debug_mux_list) goto LAB_00119e38;
    } while (ppuVar5 + -3 != param_1);
    if (param_1 == param_2) {
      uVar3 = 0;
    }
    else {
      uVar3 = clk_set_parent(param_1[1],param_2[1]);
      if ((int)uVar3 != 0) {
        iVar1 = clk_hw_get_num_parents(param_1);
        if (iVar1 == 0) {
LAB_00119e38:
          uVar3 = 0xffffffea;
        }
        else {
          uVar6 = 0;
          do {
            if ((*(int *)(param_1 + -10) <= (int)uVar6) ||
               (*(int *)(param_1[-0xb] + (long)(int)uVar6 * 4) != -0x21524111)) {
              lVar4 = clk_hw_get_parent_by_index(param_1,uVar6);
              if (lVar4 == 0) goto LAB_00119e38;
              iVar1 = clk_find_and_set_parent(lVar4,param_2);
              if (iVar1 == 0) {
                uVar3 = clk_set_parent(param_1[1],*(undefined8 *)(lVar4 + 8));
                return uVar3;
              }
            }
            uVar6 = uVar6 + 1;
            uVar2 = clk_hw_get_num_parents(param_1);
            uVar3 = 0xffffffea;
          } while (uVar6 < uVar2);
        }
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// enable_debug_clks @ 00119e5c size=400
// signature: undefined enable_debug_clks(void)
// callers: [enable_debug_clks, clk_debug_measure_get]
//------------------------------------------------------------

int enable_debug_clks(undefined **param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined **ppuVar6;
  uint uVar7;
  
  if (param_1 == (undefined **)0x0) {
LAB_00119f08:
    iVar1 = 0;
  }
  else {
    ppuVar6 = &clk_hw_debug_mux_list;
    do {
      ppuVar6 = (undefined **)*ppuVar6;
      if (ppuVar6 == &clk_hw_debug_mux_list) goto LAB_00119f08;
    } while (ppuVar6 + -3 != param_1);
    iVar1 = clk_hw_get_num_parents(param_1);
    if (iVar1 != 0) {
      uVar7 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar7) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar7 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar7);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            iVar1 = clk_runtime_get_regmap(uVar4);
            if (iVar1 != 0) {
              return iVar1;
            }
            break;
          }
        }
        uVar7 = uVar7 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar7 < uVar2);
    }
    clk_hw_get_parent(param_1);
    iVar1 = enable_debug_clks();
    if (iVar1 == 0) {
      iVar3 = *(int *)(param_1 + -5);
      if (iVar3 == 0) {
        iVar3 = 1;
      }
      *(int *)(param_1 + -5) = iVar3;
      if (*(int *)(param_1 + -4) != -1) {
        regmap_update_bits_base(param_1[-7],*(int *)(param_1 + -4),iVar3,iVar3,0,0,0);
      }
    }
    iVar3 = clk_hw_get_num_parents(param_1);
    if (iVar3 != 0) {
      uVar7 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar7) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar7 * 4) != -0x21524111)) {
          uVar4 = clk_hw_get_parent_by_index(param_1,uVar7);
          uVar5 = clk_is_regmap_clk();
          if ((uVar5 & 1) != 0) {
            clk_runtime_put_regmap(uVar4);
            return iVar1;
          }
        }
        uVar7 = uVar7 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar7 < uVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// get_mux_divs @ 00119fec size=144
// signature: undefined get_mux_divs(void)
// callers: [clk_debug_measure_get, get_mux_divs]
//------------------------------------------------------------

int get_mux_divs(undefined **param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined **ppuVar4;
  int iVar5;
  
  if (param_1 == (undefined **)0x0) {
LAB_0011a064:
    iVar2 = 1;
  }
  else {
    ppuVar4 = &clk_hw_debug_mux_list;
    do {
      ppuVar4 = (undefined **)*ppuVar4;
      if (ppuVar4 == &clk_hw_debug_mux_list) goto LAB_0011a064;
    } while (ppuVar4 + -3 != param_1);
    iVar5 = *(int *)(param_1 + -1);
    if (iVar5 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11a07c);
      (*pcVar1)();
    }
    if (param_1[-9] != (undefined *)0x0) {
      uVar3 = clk_debug_mux_get_parent(param_1);
      iVar5 = *(int *)(param_1[-9] + (uVar3 & 0xff) * 4) * iVar5;
    }
    clk_hw_get_parent(param_1);
    iVar2 = get_mux_divs();
    iVar2 = iVar2 * iVar5;
  }
  return iVar2;
}



//------------------------------------------------------------
// disable_debug_clks @ 0011a08c size=368
// signature: undefined disable_debug_clks(void)
// callers: [clk_debug_measure_get, disable_debug_clks]
//------------------------------------------------------------

void disable_debug_clks(undefined **param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  uint uVar6;
  
  if (param_1 != (undefined **)0x0) {
    ppuVar5 = &clk_hw_debug_mux_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &clk_hw_debug_mux_list) {
        return;
      }
    } while (ppuVar5 + -3 != param_1);
    iVar1 = clk_hw_get_num_parents(param_1);
    if (iVar1 != 0) {
      uVar6 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar6) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar6 * 4) != -0x21524111)) {
          uVar3 = clk_hw_get_parent_by_index(param_1,uVar6);
          uVar4 = clk_is_regmap_clk();
          if ((uVar4 & 1) != 0) {
            iVar1 = clk_runtime_get_regmap(uVar3);
            if (iVar1 != 0) {
              return;
            }
            break;
          }
        }
        uVar6 = uVar6 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar6 < uVar2);
    }
    iVar1 = *(int *)(param_1 + -5);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    *(int *)(param_1 + -5) = iVar1;
    if (*(int *)(param_1 + -4) != -1) {
      regmap_update_bits_base(param_1[-7],*(int *)(param_1 + -4),iVar1,0,0,0,0);
    }
    iVar1 = clk_hw_get_num_parents(param_1);
    if (iVar1 != 0) {
      uVar6 = 0;
      do {
        if ((*(int *)(param_1 + -10) <= (int)uVar6) ||
           (*(int *)(param_1[-0xb] + (long)(int)uVar6 * 4) != -0x21524111)) {
          uVar3 = clk_hw_get_parent_by_index(param_1,uVar6);
          uVar4 = clk_is_regmap_clk();
          if ((uVar4 & 1) != 0) {
            clk_runtime_put_regmap(uVar3);
            break;
          }
        }
        uVar6 = uVar6 + 1;
        uVar2 = clk_hw_get_num_parents(param_1);
      } while (uVar6 < uVar2);
    }
    clk_hw_get_parent(param_1);
    disable_debug_clks();
  }
  return;
}



//------------------------------------------------------------
// run_measurement @ 0011a1fc size=360
// signature: undefined run_measurement(void)
// callers: [clk_debug_measure_get]
//------------------------------------------------------------

uint run_measurement(uint param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  regmap_update_bits_base(param_2,param_3,0x100000,0,0,0,0);
  regmap_update_bits_base(param_2,param_3,0x200000,0x200000,0,0,0);
  __const_udelay(0x10c7);
  regmap_update_bits_base(param_2,param_3,0x200000,0,0,0,0);
  regmap_update_bits_base(param_2,param_3,0xfffff,param_1 & 0xfffff,0,0,0);
  regmap_update_bits_base(param_2,param_3,0x100000,0x100000,0,0,0);
  while( true ) {
    regmap_read(param_2,param_4,&local_3c);
    if ((local_3c._3_1_ >> 1 & 1) != 0) break;
    Yield();
  }
  regmap_update_bits_base(param_2,param_3,0x100000,0,0,0,0);
  regmap_read(param_2,param_4,&local_3c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_3c & 0x1ffffff;
}



//------------------------------------------------------------
// rate_max_open @ 0011a368 size=48
// signature: undefined rate_max_open(void)
// callers: []
//------------------------------------------------------------

void rate_max_open(long param_1,undefined8 param_2)

{
  single_open(param_2,rate_max_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// rate_max_show @ 0011a39c size=844
// signature: undefined rate_max_show(void)
// callers: []
//------------------------------------------------------------

undefined8 rate_max_show(long param_1)

{
  long *plVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  ulong uVar15;
  
  lVar11 = *(long *)(param_1 + 0x80);
  plVar1 = (long *)(lVar11 + 0x30);
  uVar5 = clk_get_rate(*(undefined8 *)(lVar11 + 8));
  iVar4 = clk_find_vdd_level(lVar11,plVar1,uVar5);
  if (iVar4 < 0) {
    uVar7 = clk_hw_get_name(lVar11);
    seq_printf(param_1,"could not find_vdd_level for %s, %ld\n",uVar7,uVar5);
  }
  else {
    uVar3 = *(uint *)(lVar11 + 0x50);
    if (*(long *)(lVar11 + 0x30) != 0) {
      uVar3 = uVar3 + 1;
    }
    uVar15 = (ulong)uVar3;
    if (((int)uVar3 < 0) ||
       (lVar6 = __kmalloc(-(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | uVar15 << 3,0xcc0),
       lVar6 == 0)) {
      return 0xfffffff4;
    }
    if (*(int *)(lVar11 + 0x50) < 1) {
      lVar9 = 0;
    }
    else {
      lVar9 = 0;
      do {
        lVar10 = lVar9 * 8;
        lVar9 = lVar9 + 1;
        *(undefined8 *)(lVar6 + lVar10) = *(undefined8 *)(*(long *)(lVar11 + 0x38) + lVar10);
      } while (lVar9 < *(int *)(lVar11 + 0x50));
    }
    if (*plVar1 != 0) {
      *(long *)(lVar6 + lVar9 * 8) = *plVar1;
    }
    seq_printf(param_1,&DAT_0011d893,&DAT_0011cfc8);
    if ((int)uVar3 < 1) {
      seq_printf(param_1,"\n%12s",&DAT_0011dad6);
    }
    else {
      uVar12 = 0;
      do {
        lVar9 = *(long *)(lVar6 + uVar12 * 8);
        if (0 < *(int *)(lVar9 + 0x18)) {
          lVar10 = 0;
          do {
            seq_printf(param_1,&DAT_0011cb7e,*(undefined8 *)(*(long *)(lVar9 + 0x10) + lVar10 * 8));
            lVar9 = *(long *)(lVar6 + uVar12 * 8);
            lVar10 = lVar10 + 1;
          } while (lVar10 < *(int *)(lVar9 + 0x18));
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 != uVar15);
      seq_printf(param_1,"\n%12s",&DAT_0011dad6);
      if (0 < (int)uVar3) {
        uVar12 = 0;
        do {
          if (0 < *(int *)(*(long *)(lVar6 + uVar12 * 8) + 0x18)) {
            iVar4 = 0;
            do {
              seq_printf(param_1,&DAT_0011cb7e,&DAT_0011d416);
              iVar4 = iVar4 + 1;
            } while (iVar4 < *(int *)(*(long *)(lVar6 + uVar12 * 8) + 0x18));
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 != uVar15);
      }
    }
    seq_puts(param_1,&DAT_0011d9b0);
    if (0 < *(int *)(lVar11 + 0x48)) {
      uVar12 = 0;
      do {
        uVar5 = clk_get_rate(*(undefined8 *)(lVar11 + 8));
        uVar8 = clk_find_vdd_level(lVar11,plVar1,uVar5);
        puVar2 = &DAT_0011c996;
        if (uVar12 != (uVar8 & 0xffffffff)) {
          puVar2 = &DAT_0011cfc8;
        }
        seq_printf(param_1,"%2s%10lu",puVar2,*(undefined8 *)(*(long *)(lVar11 + 0x40) + uVar12 * 8))
        ;
        if (0 < (int)uVar3) {
          uVar13 = 0;
          do {
            lVar9 = *(long *)(lVar6 + uVar13 * 8);
            iVar4 = *(int *)(lVar9 + 0x18);
            if (0 < iVar4) {
              iVar14 = 0;
              do {
                if (*(long *)(lVar9 + 0x20) != 0) {
                  seq_printf(param_1,&DAT_0011d7e6,
                             *(undefined4 *)
                              (*(long *)(lVar9 + 0x20) + (long)(iVar14 + (int)uVar12 * iVar4) * 4));
                  iVar4 = *(int *)(lVar9 + 0x18);
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 < iVar4);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 != uVar15);
        }
        if (uVar12 == (uVar8 & 0xffffffff)) {
          seq_puts(param_1,&DAT_0011cc1a);
        }
        seq_puts(param_1,&DAT_0011d9b0);
        uVar12 = uVar12 + 1;
      } while ((long)uVar12 < (long)*(int *)(lVar11 + 0x48));
    }
    kfree(lVar6);
  }
  return 0;
}



//------------------------------------------------------------
// list_rates_open @ 0011a6ec size=48
// signature: undefined list_rates_open(void)
// callers: []
//------------------------------------------------------------

void list_rates_open(long param_1,undefined8 param_2)

{
  single_open(param_2,list_rates_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// list_rates_show @ 0011a720 size=280
// signature: undefined list_rates_show(void)
// callers: []
//------------------------------------------------------------

undefined8 list_rates_show(long param_1)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  
  lVar5 = *(long *)(param_1 + 0x80);
  if (*(long *)(lVar5 + 0x30) == 0) {
    lVar6 = -1;
  }
  else {
    uVar2 = (ulong)*(uint *)(lVar5 + 0x48);
    if ((int)*(uint *)(lVar5 + 0x48) < 1) {
      lVar6 = 0;
    }
    else {
      lVar6 = 0;
      plVar4 = *(long **)(lVar5 + 0x40);
      do {
        if (*plVar4 != 0) {
          lVar6 = *plVar4;
        }
        uVar2 = uVar2 - 1;
        plVar4 = plVar4 + 1;
      } while (uVar2 != 0);
    }
  }
  pcVar3 = *(code **)(*(long *)(lVar5 + 0x58) + 8);
  if (*(int *)(pcVar3 + -4) != -0x7b215f8f) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11a7ac);
    (*pcVar3)();
  }
  lVar1 = (*pcVar3)(lVar5,0,lVar6);
  if (0xfff < lVar1 + 0xfffU) {
    iVar7 = 1;
    do {
      seq_printf(param_1,&DAT_0011cb83,lVar1);
      pcVar3 = *(code **)(*(long *)(lVar5 + 0x58) + 8);
      if (*(int *)(pcVar3 + -4) != -0x7b215f8f) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11a804);
        (*pcVar3)();
      }
      lVar1 = (*pcVar3)(lVar5,iVar7,lVar6);
      iVar7 = iVar7 + 1;
    } while (0xfff < lVar1 + 0xfffU);
  }
  return 0;
}



//------------------------------------------------------------
// print_hw_open @ 0011a83c size=48
// signature: undefined print_hw_open(void)
// callers: []
//------------------------------------------------------------

void print_hw_open(long param_1,undefined8 param_2)

{
  single_open(param_2,print_hw_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// print_hw_show @ 0011a870 size=40
// signature: undefined print_hw_show(void)
// callers: []
//------------------------------------------------------------

undefined8 print_hw_show(long param_1)

{
  clk_debug_print_hw(*(undefined8 *)(param_1 + 0x80),param_1);
  return 0;
}



//------------------------------------------------------------
// enabled_clocks_open @ 0011a89c size=48
// signature: undefined enabled_clocks_open(void)
// callers: []
//------------------------------------------------------------

void enabled_clocks_open(long param_1,undefined8 param_2)

{
  single_open(param_2,enabled_clocks_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// enabled_clocks_show @ 0011a8d0 size=72
// signature: undefined enabled_clocks_show(void)
// callers: []
//------------------------------------------------------------

undefined8 enabled_clocks_show(undefined8 param_1)

{
  mutex_lock(clk_debug_lock);
  clock_debug_print_enabled_clocks(param_1);
  mutex_unlock(clk_debug_lock);
  return 0;
}



//------------------------------------------------------------
// clock_debug_print_enabled_clocks @ 0011a918 size=908
// signature: undefined clock_debug_print_enabled_clocks(void)
// callers: [enabled_clocks_show, clk_debug_suspend_trace_probe]
//------------------------------------------------------------

void clock_debug_print_enabled_clocks(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  int iVar10;
  undefined **ppuVar11;
  
  if (param_1 == 0) {
    _printk(&DAT_0011c9a9);
  }
  else {
    seq_printf(param_1,"Enabled clocks:\n");
  }
  if ((undefined **)clk_hw_debug_list != &clk_hw_debug_list) {
    iVar10 = 0;
    ppuVar11 = (undefined **)clk_hw_debug_list;
    do {
      if ((ppuVar11 == (undefined **)0x0) || (ppuVar11[2] == (undefined *)0x0)) {
        _printk(&DAT_0011cfc9);
LAB_0011a980:
        iVar2 = 0;
      }
      else {
        uVar5 = clk_hw_is_prepared();
        if ((uVar5 & 1) == 0) goto LAB_0011a980;
        if (param_1 == 0) {
          _printk(&DAT_0011d624);
        }
        else {
          seq_printf(param_1,&DAT_0011ccab);
        }
        cVar1 = debug_suspend_atomic;
        lVar6 = __clk_get_hw(*(undefined8 *)(ppuVar11[2] + 8));
        if (lVar6 == 0) {
LAB_0011abd4:
          if (param_1 == 0) goto LAB_0011ac0c;
          seq_printf(param_1,&DAT_0011d9b0);
        }
        else {
          uVar5 = clk_hw_get_rate();
          if ((param_1 != 0) || (cVar1 == '\0')) {
            uVar7 = clk_is_regmap_clk(lVar6);
            if (((uVar7 & 1) == 0) || (*(long *)(lVar6 + 0x30) == 0)) {
              iVar2 = 0;
            }
            else {
              iVar2 = clk_find_vdd_level(lVar6,(long *)(lVar6 + 0x30),uVar5 & 0xffffffff);
            }
            if (param_1 != 0) {
              uVar3 = clk_hw_is_enabled(lVar6);
              uVar4 = clk_hw_is_prepared(lVar6);
              uVar8 = clk_hw_get_name(lVar6);
              uVar3 = uVar3 & 1;
              uVar4 = uVar4 & 1;
              if (iVar2 == 0) {
                puVar9 = &DAT_0011cb88;
                goto LAB_0011ab04;
              }
              puVar9 = &DAT_0011cb88;
              goto LAB_0011aaf4;
            }
            uVar8 = clk_hw_get_name();
            if (iVar2 != 0) {
              puVar9 = &DAT_0011cb88;
              goto LAB_0011abfc;
            }
            puVar9 = &DAT_0011cb88;
LAB_0011aae8:
            _printk(&DAT_0011cddb,puVar9,uVar8,uVar5);
            do {
              while( true ) {
                lVar6 = clk_get_parent(*(undefined8 *)(lVar6 + 8));
                if ((lVar6 == 0) || (lVar6 = __clk_get_hw(), lVar6 == 0)) goto LAB_0011abd4;
                uVar5 = clk_hw_get_rate();
                uVar7 = clk_is_regmap_clk(lVar6);
                if (((uVar7 & 1) != 0) && (*(long *)(lVar6 + 0x30) != 0)) break;
                iVar2 = 0;
                if (param_1 == 0) goto LAB_0011ab5c;
LAB_0011ab84:
                uVar3 = clk_hw_is_enabled(lVar6);
                uVar4 = clk_hw_is_prepared(lVar6);
                uVar8 = clk_hw_get_name(lVar6);
                uVar3 = uVar3 & 1;
                uVar4 = uVar4 & 1;
                if (iVar2 == 0) {
                  puVar9 = &DAT_0011ca9c;
LAB_0011ab04:
                  seq_printf(param_1,"%s%s:%u:%u [%ld]",puVar9,uVar8,uVar3,uVar4,uVar5);
                }
                else {
                  puVar9 = &DAT_0011ca9c;
LAB_0011aaf4:
                  seq_printf(param_1,"%s%s:%u:%u [%ld, %d]",puVar9,uVar8,uVar3,uVar4,uVar5,iVar2);
                }
              }
              iVar2 = clk_find_vdd_level(lVar6,(long *)(lVar6 + 0x30),uVar5 & 0xffffffff);
              if (param_1 != 0) goto LAB_0011ab84;
LAB_0011ab5c:
              uVar8 = clk_hw_get_name();
              if (iVar2 == 0) goto code_r0x0011ab68;
              puVar9 = &DAT_0011ca9c;
LAB_0011abfc:
              _printk(&DAT_0011ccb0,puVar9,uVar8,uVar5,iVar2);
            } while( true );
          }
          uVar8 = clk_hw_get_name(lVar6);
          _printk(&DAT_0011cddb,&DAT_0011cb88,uVar8,uVar5);
LAB_0011ac0c:
          _printk(&DAT_0011cefd);
        }
        iVar2 = 1;
      }
      ppuVar11 = (undefined **)*ppuVar11;
      iVar10 = iVar2 + iVar10;
    } while (ppuVar11 != &clk_hw_debug_list);
    if (iVar10 != 0) {
      if (param_1 == 0) {
        _printk(&DAT_0011dd18,iVar10);
        return;
      }
      seq_printf(param_1,"Enabled clock count: %d\n",iVar10);
      return;
    }
  }
  if (param_1 == 0) {
    _printk(&DAT_0011dc7a);
  }
  else {
    seq_printf(param_1,"No clocks enabled.\n");
  }
  return;
code_r0x0011ab68:
  puVar9 = &DAT_0011ca9c;
  goto LAB_0011aae8;
}



//------------------------------------------------------------
// clocks_trace_open @ 0011aca8 size=48
// signature: undefined clocks_trace_open(void)
// callers: []
//------------------------------------------------------------

void clocks_trace_open(long param_1,undefined8 param_2)

{
  single_open(param_2,clock_debug_trace,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// clock_debug_trace @ 0011acdc size=284
// signature: undefined clock_debug_trace(void)
// callers: []
//------------------------------------------------------------

undefined8 clock_debug_trace(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  
  mutex_lock(clk_debug_lock);
  if ((undefined **)clk_hw_debug_list != &clk_hw_debug_list) {
    uVar1 = sp_el0;
    ppuVar5 = (undefined **)clk_hw_debug_list;
    do {
      clk_hw_is_enabled(ppuVar5[2]);
      clk_hw_is_prepared(ppuVar5[2]);
      uVar2 = clk_hw_get_rate(ppuVar5[2]);
      puVar4 = ppuVar5[2];
      uVar3 = clk_is_regmap_clk(puVar4);
      if (((uVar3 & 1) != 0) && (*(long *)(puVar4 + 0x30) != 0)) {
        clk_find_vdd_level(puVar4,puVar4 + 0x30,uVar2);
      }
      if (*(long *)(ppuVar5[2] + 0x10) == 0) {
        clk_hw_get_name();
      }
      ppuVar5 = (undefined **)*ppuVar5;
    } while (ppuVar5 != &clk_hw_debug_list);
  }
  mutex_unlock(clk_debug_lock);
  return 0;
}



//------------------------------------------------------------
// clk_debug_suspend_enable_fops_open @ 0011ae9c size=52
// signature: undefined clk_debug_suspend_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void clk_debug_suspend_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,clk_debug_suspend_enable_get,clk_debug_suspend_enable_set,
                   "%llu\n");
  return;
}



//------------------------------------------------------------
// clk_debug_suspend_enable_get @ 0011aed4 size=20
// signature: undefined clk_debug_suspend_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_debug_suspend_enable_get(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)debug_suspend;
  return 0;
}



//------------------------------------------------------------
// clk_debug_suspend_enable_set @ 0011aeec size=196
// signature: undefined clk_debug_suspend_enable_set(void)
// callers: []
//------------------------------------------------------------

int clk_debug_suspend_enable_set(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  
  if ((bool)debug_suspend == (param_2 != 0)) {
    iVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = tracepoint_probe_unregister
                        (&__tracepoint_suspend_resume,clk_debug_suspend_trace_probe,0);
    }
    else {
      iVar2 = tracepoint_probe_register
                        (&__tracepoint_suspend_resume,clk_debug_suspend_trace_probe,0);
    }
    if (iVar2 == 0) {
      debug_suspend = param_2 != 0;
    }
    else {
      puVar1 = &DAT_0011cfc8;
      if (param_2 == 0) {
        puVar1 = &DAT_0011d62b;
      }
      _printk(&DAT_0011dadb,"clk_debug_suspend_enable_set",puVar1,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// clk_debug_suspend_atomic_enable_fops_open @ 0011afb4 size=52
// signature: undefined clk_debug_suspend_atomic_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void clk_debug_suspend_atomic_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,clk_debug_suspend_atomic_enable_get,
                   clk_debug_suspend_atomic_enable_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// clk_debug_suspend_atomic_enable_get @ 0011afec size=20
// signature: undefined clk_debug_suspend_atomic_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_debug_suspend_atomic_enable_get(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)debug_suspend_atomic;
  return 0;
}



//------------------------------------------------------------
// clk_debug_suspend_atomic_enable_set @ 0011b004 size=24
// signature: undefined clk_debug_suspend_atomic_enable_set(void)
// callers: []
//------------------------------------------------------------

undefined8 clk_debug_suspend_atomic_enable_set(undefined8 param_1,long param_2)

{
  debug_suspend_atomic = param_2 != 0;
  return 0;
}



//------------------------------------------------------------
// gdsc_register @ 0011b030 size=1344
// signature: undefined gdsc_register(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

ulong gdsc_register(long *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  ushort uVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  ulong uVar13;
  long lVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  uint local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  lVar1 = *param_1;
  lVar2 = param_1[1];
  uVar17 = param_1[2];
  plVar5 = (long *)devm_kmalloc(lVar1,0x18,0xdc0);
  if (plVar5 != (long *)0x0) {
    if (uVar17 >> 0x3d != 0) {
      uVar16 = 0xfffffff4;
      *plVar5 = 0;
      goto LAB_0011b46c;
    }
    lVar6 = devm_kmalloc(lVar1,uVar17 << 3,0xdc0);
    *plVar5 = lVar6;
    if (lVar6 != 0) {
      if (uVar17 == 0) {
        *(undefined4 *)(plVar5 + 1) = 0;
      }
      else {
        uVar13 = 0;
        do {
          lVar6 = *(long *)(lVar2 + uVar13 * 8);
          if ((lVar6 != 0) && (*(long *)(lVar6 + 0x650) != 0)) {
            uVar7 = devm_regulator_get(lVar1);
            *(undefined8 *)(*(long *)(lVar2 + uVar13 * 8) + 0x658) = uVar7;
            uVar16 = *(ulong *)(*(long *)(lVar2 + uVar13 * 8) + 0x658);
            if (0xfffffffffffff000 < uVar16) goto LAB_0011b46c;
          }
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (uVar13 < uVar17);
        uVar13 = 0;
        *(int *)(plVar5 + 1) = (int)uVar17;
        do {
          lVar6 = *(long *)(lVar2 + uVar13 * 8);
          if (lVar6 != 0) {
            lVar14 = uVar13 * 8;
            *(undefined8 *)(lVar6 + 0x5f8) = param_3;
            *(undefined8 *)(*(long *)(lVar2 + lVar14) + 0x638) = param_2;
            lVar6 = *(long *)(lVar2 + lVar14);
            iVar4 = *(int *)(lVar6 + 0x624);
            if (iVar4 == 0) {
              iVar4 = 2;
              *(undefined4 *)(lVar6 + 0x624) = 2;
              iVar10 = *(int *)(lVar6 + 0x628);
              if (iVar10 == 0) goto LAB_0011b208;
LAB_0011b158:
              iVar12 = *(int *)(lVar6 + 0x62c);
            }
            else {
              iVar10 = *(int *)(lVar6 + 0x628);
              if (iVar10 != 0) goto LAB_0011b158;
LAB_0011b208:
              iVar10 = 8;
              *(undefined4 *)(lVar6 + 0x628) = 8;
              iVar12 = *(int *)(lVar6 + 0x62c);
            }
            if (iVar12 == 0) {
              iVar12 = 2;
              *(undefined4 *)(lVar6 + 0x62c) = 2;
            }
            uVar16 = regmap_update_bits_base
                               (*(undefined8 *)(lVar6 + 0x5f8),*(undefined4 *)(lVar6 + 0x600),
                                0xfff006,iVar10 << 0x10 | iVar4 << 0x14 | iVar12 << 0xc,0,0,0);
            if (((int)uVar16 != 0) ||
               ((*(char *)(lVar6 + 0x630) == '\x04' &&
                (uVar16 = gdsc_toggle_logic(lVar6,1), (int)uVar16 != 0)))) goto LAB_0011b468;
            local_6c = 0;
            if ((*(ushort *)(lVar6 + 0x632) >> 5 & 1) == 0) {
              iVar4 = *(int *)(lVar6 + 0x60c);
              if (iVar4 == 0) {
                iVar4 = *(int *)(lVar6 + 0x600);
              }
            }
            else {
              iVar4 = *(int *)(lVar6 + 0x600) + 4;
            }
            uVar16 = regmap_read(*(undefined8 *)(lVar6 + 0x5f8),iVar4,&local_6c);
            iVar4 = (int)uVar16;
            if (iVar4 == 0) {
              uVar3 = *(ushort *)(lVar6 + 0x632);
              uVar15 = local_6c >> 0x1f;
              if ((uVar3 & 0x20) != 0) {
                uVar15 = local_6c >> 0x10 & 1;
              }
              if (uVar15 != 0) {
                iVar4 = 1;
                lVar8 = *(long *)(lVar6 + 0x658);
                goto joined_r0x0011b248;
              }
              if ((uVar3 >> 6 & 1) != 0) {
                gdsc_enable(lVar6);
                uVar7 = 0;
                iVar4 = 1;
                goto LAB_0011b2f4;
              }
              if ((*(byte *)(lVar6 + 0x630) >> 1 & 1) != 0) {
                iVar4 = 0;
                uVar7 = 1;
                goto LAB_0011b2f4;
              }
              uVar11 = 0x6000;
              if ((uVar3 & 0x100) != 0) {
                uVar11 = 0x4000;
              }
              if (*(int *)(lVar6 + 0x620) == 0) {
                iVar4 = 0;
                uVar7 = 1;
              }
              else {
                uVar15 = 0;
                do {
                  regmap_update_bits_base
                            (*(undefined8 *)(lVar6 + 0x5f8),
                             *(undefined4 *)(*(long *)(lVar6 + 0x618) + (long)(int)uVar15 * 4),
                             uVar11,0,0,0,0);
                  iVar4 = 0;
                  uVar15 = uVar15 + 1;
                  uVar7 = 1;
                } while (uVar15 < *(uint *)(lVar6 + 0x620));
              }
LAB_0011b348:
              if ((*(ushort *)(lVar6 + 0x632) >> 6 & 1) == 0) {
                if (*(long *)(lVar6 + 0x538) != 0) goto LAB_0011b358;
LAB_0011b3a0:
                *(code **)(lVar6 + 0x538) = gdsc_disable;
                lVar8 = *(long *)(lVar6 + 0x540);
              }
              else {
                *(uint *)(lVar6 + 0x588) = *(uint *)(lVar6 + 0x588) | 4;
                if (*(long *)(lVar6 + 0x538) == 0) goto LAB_0011b3a0;
LAB_0011b358:
                lVar8 = *(long *)(lVar6 + 0x540);
              }
              if (lVar8 == 0) {
                *(code **)(lVar6 + 0x540) = gdsc_enable;
              }
              uVar16 = pm_genpd_init(lVar6,0,uVar7);
              if ((int)uVar16 == 0) {
                *(undefined8 *)(*plVar5 + lVar14) = *(undefined8 *)(lVar2 + lVar14);
                goto LAB_0011b11c;
              }
              uVar16 = uVar16 & 0xffffffff;
              if (iVar4 == 0) goto LAB_0011b46c;
            }
            else {
              uVar16 = uVar16 & 0xffffffff;
              if (iVar4 < 0) goto LAB_0011b46c;
              lVar8 = *(long *)(lVar6 + 0x658);
joined_r0x0011b248:
              if ((lVar8 != 0) && (uVar16 = regulator_enable(), (int)uVar16 < 0)) goto LAB_0011b468;
              uVar3 = *(ushort *)(lVar6 + 0x632);
              if ((uVar3 & 1) == 0) {
LAB_0011b298:
                if ((uVar3 >> 7 & 1) != 0) {
                  regmap_update_bits_base
                            (*(undefined8 *)(lVar6 + 0x5f8),*(undefined4 *)(lVar6 + 0x600),0x800,
                             0x800,0,0,0);
                  uVar3 = *(ushort *)(lVar6 + 0x632);
                }
                if ((uVar3 >> 2 & 1) == 0) {
                  uVar7 = 0;
                }
                else {
                  uVar16 = regmap_update_bits_base
                                     (*(undefined8 *)(lVar6 + 0x5f8),*(undefined4 *)(lVar6 + 0x600),
                                      2,2,0,0,0);
                  uVar7 = 0;
                  if ((int)uVar16 < 0) goto LAB_0011b508;
                }
LAB_0011b2f4:
                uVar11 = 0x6000;
                if ((*(ushort *)(lVar6 + 0x632) & 0x100) != 0) {
                  uVar11 = 0x4000;
                }
                if (*(int *)(lVar6 + 0x620) != 0) {
                  uVar15 = 0;
                  do {
                    regmap_update_bits_base
                              (*(undefined8 *)(lVar6 + 0x5f8),
                               *(undefined4 *)(*(long *)(lVar6 + 0x618) + (long)(int)uVar15 * 4),
                               uVar11,uVar11,0,0,0);
                    uVar15 = uVar15 + 1;
                  } while (uVar15 < *(uint *)(lVar6 + 0x620));
                }
                goto LAB_0011b348;
              }
              iVar10 = *(int *)(lVar6 + 0x608);
              lVar8 = 0x600;
              if (iVar10 == 0) {
                iVar10 = 1;
              }
              else {
                lVar8 = 0x604;
              }
              uVar16 = regmap_update_bits_base
                                 (*(undefined8 *)(lVar6 + 0x5f8),*(undefined4 *)(lVar6 + lVar8),
                                  iVar10,0,0,0,0);
              if ((int)uVar16 == 0) {
                uVar3 = *(ushort *)(lVar6 + 0x632);
                goto LAB_0011b298;
              }
LAB_0011b508:
              uVar16 = uVar16 & 0xffffffff;
            }
            if (*(long *)(lVar6 + 0x658) != 0) {
              regulator_disable();
            }
            goto LAB_0011b46c;
          }
LAB_0011b11c:
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (uVar13 < uVar17);
        if (uVar17 != 0) {
          uVar13 = 0;
          do {
            lVar6 = *(long *)(lVar2 + uVar13 * 8);
            if (lVar6 != 0) {
              lVar6 = *(long *)(lVar6 + 0x5f0);
              if (lVar6 == 0) {
                uVar16 = *(ulong *)(lVar1 + 0x268);
                if ((uVar16 == 0) || (0xfffffffffffff000 < uVar16)) goto LAB_0011b4c8;
                lVar6 = uVar16 - 0x390;
              }
              uVar9 = pm_genpd_add_subdomain(lVar6);
              uVar16 = uVar9 & 0xffffffff;
              if ((int)uVar9 != 0) {
                uVar15 = (int)uVar13 - 1;
                if ((int)uVar15 < 0) goto LAB_0011b46c;
                lVar1 = *param_1;
                lVar2 = param_1[1];
                goto LAB_0011b53c;
              }
            }
LAB_0011b4c8:
            uVar13 = (ulong)((int)uVar13 + 1);
          } while (uVar13 < uVar17);
        }
      }
      uVar16 = of_genpd_add_provider_onecell(*(undefined8 *)(lVar1 + 0x2e8),plVar5);
LAB_0011b468:
      uVar16 = uVar16 & 0xffffffff;
      goto LAB_0011b46c;
    }
  }
  uVar16 = 0xfffffff4;
LAB_0011b46c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16 & 0xffffffff;
LAB_0011b53c:
  do {
    lVar6 = *(long *)(lVar2 + (ulong)uVar15 * 8);
    if (lVar6 != 0) {
      lVar6 = *(long *)(lVar6 + 0x5f0);
      if (lVar6 == 0) {
        uVar17 = *(ulong *)(lVar1 + 0x268);
        if ((uVar17 == 0) || (0xfffffffffffff000 < uVar17)) goto LAB_0011b534;
        lVar6 = uVar17 - 0x390;
      }
      pm_genpd_remove_subdomain(lVar6);
    }
LAB_0011b534:
    uVar15 = uVar15 - 1;
  } while (-1 < (int)uVar15);
  goto LAB_0011b46c;
}



//------------------------------------------------------------
// gdsc_unregister @ 0011b574 size=124
// signature: undefined gdsc_unregister(void)
// callers: [qcom_cc_gdsc_unregister, devm_add_action_or_reset]
//------------------------------------------------------------

void gdsc_unregister(long *param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  
  lVar3 = *param_1;
  uVar4 = (int)param_1[2] - 1;
  if (-1 < (int)uVar4) {
    lVar5 = param_1[1];
    do {
      lVar1 = *(long *)(lVar5 + (ulong)uVar4 * 8);
      if (lVar1 != 0) {
        lVar1 = *(long *)(lVar1 + 0x5f0);
        if (lVar1 == 0) {
          uVar2 = *(ulong *)(lVar3 + 0x268);
          if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) goto LAB_0011b5a4;
          lVar1 = uVar2 - 0x390;
        }
        pm_genpd_remove_subdomain(lVar1);
      }
LAB_0011b5a4:
      uVar4 = uVar4 - 1;
    } while (-1 < (int)uVar4);
  }
  of_genpd_del_provider(*(undefined8 *)(lVar3 + 0x2e8));
  return;
}



//------------------------------------------------------------
// gdsc_gx_do_nothing_enable @ 0011b5f4 size=8
// signature: undefined gdsc_gx_do_nothing_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 gdsc_gx_do_nothing_enable(void)

{
  return 0;
}



//------------------------------------------------------------
// gdsc_toggle_logic @ 0011b5fc size=268
// signature: undefined gdsc_toggle_logic(void)
// callers: [gdsc_register, gdsc_enable, gdsc_disable]
//------------------------------------------------------------

int gdsc_toggle_logic(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  
  if (((param_2 != 1) || (*(long *)(param_1 + 0x658) == 0)) ||
     (iVar5 = regulator_enable(), -1 < iVar5)) {
    iVar5 = *(int *)(param_1 + 0x608);
    lVar2 = 0x600;
    if (iVar5 == 0) {
      iVar5 = 1;
    }
    else {
      lVar2 = 0x604;
    }
    iVar1 = iVar5;
    if (param_2 != 0) {
      iVar1 = 0;
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + lVar2),iVar5,iVar1,0,0,0);
    if ((param_2 == 0) && ((*(ushort *)(param_1 + 0x632) & 1) != 0)) {
      __const_udelay(0x20c4ac);
    }
    else {
      if (*(int *)(param_1 + 0x60c) != 0) {
        __const_udelay(0x10c7);
      }
      iVar5 = gdsc_poll_status(param_1,param_2);
      if (iVar5 != 0) {
        puVar3 = &DAT_0011cca9;
        if (param_2 != 0) {
          puVar3 = &DAT_0011cdca;
        }
        __warn_printk("%s status stuck at \'o%s\'",*(undefined8 *)(param_1 + 0x510),puVar3);
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11b708);
        (*pcVar4)();
      }
      if (param_2 != 0) {
        return 0;
      }
      if (*(long *)(param_1 + 0x658) != 0) {
        iVar5 = regulator_disable();
        goto LAB_0011b6c4;
      }
    }
    iVar5 = 0;
  }
LAB_0011b6c4:
  return iVar5;
}



//------------------------------------------------------------
// gdsc_enable @ 0011b718 size=632
// signature: undefined gdsc_enable(void)
// callers: [gdsc_register]
//------------------------------------------------------------

undefined8 gdsc_enable(long param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 0x630) == '\x04') {
    if (*(int *)(param_1 + 0x648) != 0) {
      uVar5 = 0;
      do {
        pcVar4 = *(code **)(**(long **)(param_1 + 0x638) + 0x10);
        if (*(int *)(pcVar4 + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b774);
          (*pcVar4)();
        }
        (*pcVar4)(*(long **)(param_1 + 0x638),
                  *(undefined4 *)(*(long *)(param_1 + 0x640) + (long)(int)uVar5 * 4));
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x648));
    }
  }
  else {
    if ((*(ushort *)(param_1 + 0x632) >> 3 & 1) != 0) {
      if (*(int *)(param_1 + 0x648) != 0) {
        uVar5 = 0;
        do {
          pcVar4 = *(code **)(**(long **)(param_1 + 0x638) + 8);
          if (*(int *)(pcVar4 + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b7cc);
            (*pcVar4)();
          }
          (*pcVar4)(*(long **)(param_1 + 0x638),
                    *(undefined4 *)(*(long *)(param_1 + 0x640) + (long)(int)uVar5 * 4));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x648));
      }
      __const_udelay(0x10c7);
      if (*(int *)(param_1 + 0x648) != 0) {
        uVar5 = 0;
        do {
          pcVar4 = *(code **)(**(long **)(param_1 + 0x638) + 0x10);
          if (*(int *)(pcVar4 + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b820);
            (*pcVar4)();
          }
          (*pcVar4)(*(long **)(param_1 + 0x638),
                    *(undefined4 *)(*(long *)(param_1 + 0x640) + (long)(int)uVar5 * 4));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x648));
      }
    }
    if ((*(ushort *)(param_1 + 0x632) >> 1 & 1) != 0) {
      if ((*(ushort *)(param_1 + 0x632) >> 4 & 1) != 0) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x610),0x10,1,0,0,0);
        __const_udelay(0x10c7);
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x610),0x10,0,0,0,0);
      }
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x610),1,0,0,0,0);
    }
    uVar2 = gdsc_toggle_logic(param_1,1);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    if ((*(byte *)(param_1 + 0x630) & 1) != 0) {
      uVar3 = 0x6000;
      if ((*(ushort *)(param_1 + 0x632) & 0x100) != 0) {
        uVar3 = 0x4000;
      }
      if (*(int *)(param_1 + 0x620) != 0) {
        uVar5 = 0;
        do {
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x5f8),
                     *(undefined4 *)(*(long *)(param_1 + 0x618) + (long)(int)uVar5 * 4),uVar3,uVar3,
                     0,0,0);
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x620));
      }
    }
    __const_udelay(0x10c7);
    uVar1 = *(ushort *)(param_1 + 0x632);
    if ((uVar1 >> 7 & 1) != 0) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x600),0x800,0x800,0,0,0
                );
      uVar1 = *(ushort *)(param_1 + 0x632);
    }
    if ((uVar1 >> 2 & 1) != 0) {
      uVar2 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x600),2,2,0,0,0
                        );
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      __const_udelay(0x10c7);
    }
  }
  return 0;
}



//------------------------------------------------------------
// gdsc_disable @ 0011b994 size=380
// signature: undefined gdsc_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 gdsc_disable(long param_1)

{
  undefined8 uVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  
  bVar2 = *(byte *)(param_1 + 0x630);
  if (bVar2 == 4) {
    if (*(int *)(param_1 + 0x648) != 0) {
      uVar5 = 0;
      do {
        pcVar3 = *(code **)(**(long **)(param_1 + 0x638) + 8);
        if (*(int *)(pcVar3 + -4) != 0x3ef0e51c) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11b9f0);
          (*pcVar3)();
        }
        (*pcVar3)(*(long **)(param_1 + 0x638),
                  *(undefined4 *)(*(long *)(param_1 + 0x640) + (long)(int)uVar5 * 4));
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x648));
    }
  }
  else {
    if ((*(ushort *)(param_1 + 0x632) >> 2 & 1) != 0) {
      uVar1 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x600),2,0,0,0,0
                        );
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      __const_udelay(0x10c7);
      uVar1 = gdsc_poll_status(param_1,1);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      bVar2 = *(byte *)(param_1 + 0x630);
    }
    if ((bVar2 & 1) != 0) {
      uVar4 = 0x6000;
      if ((*(ushort *)(param_1 + 0x632) & 0x100) != 0) {
        uVar4 = 0x4000;
      }
      if (*(int *)(param_1 + 0x620) != 0) {
        uVar5 = 0;
        do {
          regmap_update_bits_base
                    (*(undefined8 *)(param_1 + 0x5f8),
                     *(undefined4 *)(*(long *)(param_1 + 0x618) + (long)(int)uVar5 * 4),uVar4,0,0,0,
                     0);
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x620));
        bVar2 = *(byte *)(param_1 + 0x630);
      }
    }
    if (bVar2 != 6) {
      uVar1 = gdsc_toggle_logic(param_1,0);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      if ((*(ushort *)(param_1 + 0x632) >> 1 & 1) != 0) {
        regmap_update_bits_base
                  (*(undefined8 *)(param_1 + 0x5f8),*(undefined4 *)(param_1 + 0x610),1,1,0,0,0);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// gdsc_poll_status @ 0011bb10 size=428
// signature: undefined gdsc_poll_status(void)
// callers: [gdsc_toggle_logic, gdsc_disable]
//------------------------------------------------------------

void gdsc_poll_status(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = ktime_get();
  do {
    local_3c = 0;
    if ((*(ushort *)(param_1 + 0x632) >> 5 & 1) == 0) {
      iVar1 = *(int *)(param_1 + 0x60c);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x600);
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x600) + 4;
    }
    iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x5f8),iVar1,&local_3c);
    if (iVar1 != 0) goto LAB_0011bc28;
    if ((*(ushort *)(param_1 + 0x632) >> 5 & 1) == 0) {
      if (param_2 == 0) {
        if (-1 < (int)local_3c) goto LAB_0011bc28;
      }
      else if ((param_2 != 1) || ((int)local_3c < 0)) goto LAB_0011bc28;
    }
    else {
      if (param_2 == 0) {
        uVar4 = local_3c >> 0xf;
      }
      else {
        if (param_2 != 1) goto LAB_0011bc28;
        uVar4 = local_3c >> 0x10;
      }
      if ((uVar4 & 1) != 0) goto LAB_0011bc28;
    }
    lVar3 = ktime_get();
  } while (lVar3 - lVar2 < 500000);
  local_3c = 0;
  if ((*(ushort *)(param_1 + 0x632) >> 5 & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x60c);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x600);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x600) + 4;
  }
  iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x5f8),iVar1,&local_3c);
  if (iVar1 == 0) {
    if ((*(ushort *)(param_1 + 0x632) >> 5 & 1) == 0) {
      if (param_2 == 0) {
        uVar4 = ~local_3c >> 0x1f;
      }
      else {
        if (param_2 != 1) goto LAB_0011bc28;
        uVar4 = local_3c >> 0x1f;
      }
    }
    else if (param_2 == 0) {
      uVar4 = local_3c >> 0xf & 1;
    }
    else {
      if (param_2 != 1) goto LAB_0011bc28;
      uVar4 = local_3c >> 0x10 & 1;
    }
    uVar5 = 0xffffff92;
    if (uVar4 != 0) {
      uVar5 = 0;
    }
  }
  else {
LAB_0011bc28:
    uVar5 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0011c8c0 size=28
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  clk_debug_exit();
  return;
}



//------------------------------------------------------------
// snprintf @ 00127000 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_clk_crm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00127008 size=1
// signature: undefined of_find_property(void)
// callers: [clk_hw_populate_clock_opp_table, qcom_cc_really_probe, qcom_clk_crm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_regmap_lookup_by_phandle @ 00127010 size=1
// signature: undefined syscon_regmap_lookup_by_phandle(void)
// callers: [map_debug_bases, qcom_clk_crm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_regmap_lookup_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_get_device @ 00127018 size=1
// signature: undefined crm_get_device(void)
// callers: [qcom_clk_crm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00127020 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_cc_runtime_init, clk_regulator_init, qcom_clk_crm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00127028 size=1
// signature: undefined _printk(void)
// callers: [clk_regera_pll_set_rate, clk_agera_pll_list_registers, clk_alpha_pll_set_rate, clk_rcg2_dfs_determine_rate, clk_regera_pll_configure, clock_debug_print_enabled_clocks, __clk_lucid_pll_postdiv_set_rate, clk_rcg2_disable, clk_alpha_pll_huayra_list_registers, map_debug_bases, mux_div_set_src_div, clk_branch2_mem_list_registers, clk_zonda_pll_set_rate, qcom_clk_dump, alpha_pll_huayra_set_rate, clk_trion_pll_postdiv_set_rate, clk_branch2_list_registers, lucid_evo_pll_list_registers, clk_debug_suspend_enable_set, mux_div_recalc_rate, clk_regera_pll_list_registers, clk_alpha_pll_zonda_list_registers, clk_alpha_pll_slew_set_rate, clk_alpha_pll_slew_enable, clk_hw_debug_register, clk_rcg2_crmc_unprepare, clk_rivian_evo_pll_list_registers, alpha_pll_fabia_prepare, clk_alpha_pll_zonda_evo_list_registers, alpha_pll_lucid_evo_set_rate, clk_debug_init, clk_find_vdd_level, clk_regera_pll_enable, clk_debug_print_hw, clk_rcg2_crmc_hw_set_rate, clk_regmap_mux_list_registers, alpha_pll_fabia_set_rate, clk_branch_restore_context, mux_div_get_src_div, clk_rcg2_crmc_determine_rate, mux_div_get_parent, __alpha_pll_trion_set_rate, clk_alpha_pll_agera_set_rate, clk_rcg2_vote_bw, clk_trion_pll_list_registers, clk_alpha_pll_list_registers, clk_debug_suspend_trace_probe, clk_rcg2_crmb_hw_set_bw, clk_rcg2_vote_perf_level, clk_branch_restore_context_aon, clk_lucid_5lpe_pll_configure, _alpha_pll_lucid_evo_enable, clk_alpha_pll_hwfsm_set_rate, clk_rcg2_list_registers, clk_hw_populate_clock_opp_table, _alpha_pll_lucid_evo_prepare, clk_fabia_pll_list_registers, clk_rcg2_crmb_unprepare, clk_debug_measure_set, clk_zonda_evo_pll_configure, qcom_clk_crm_init, qcom_cc_clk_hw_get, clk_rcg2_crmb_set_rate, clk_rcg2_crmc_populate_freq_table, clk_pll_restore_context, clk_trion_pll_postdiv_recalc_rate, clk_debug_measure_get, clk_zonda_5lpe_pll_enable, lucid_pll_list_registers, clk_zonda_pll_is_enabled, wait_for_pll, _freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00127030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [clk_alpha_pll_postdiv_fabia_recalc_rate, clk_edp_pixel_set_rate, clk_zonda_pll_recalc_rate, alpha_pll_lucid_5lpe_prepare, clk_regera_pll_configure, __clk_rcg_set_rate, phy_mux_is_enabled, clk_lucid_evo_pll_configure, clk_alpha_pll_huayra_list_registers, gdsc_register, clk_rcg2_is_force_enabled, clk_zonda_pll_set_rate, __clk_hfpll_enable, clk_rcg2_dp_set_rate, clk_pll_sr2_enable, qcom_reset_set, clk_rcg2_is_enabled, clk_branch2_sreg_disable, clk_rivian_evo_pll_list_registers, clk_rcg2_crmc_list_rate, alpha_pll_fabia_prepare, clk_zonda_5lpe_pll_disable, clk_alpha_pll_zonda_evo_list_registers, alpha_pll_lucid_evo_set_rate, clk_hfpll_set_rate, clk_alpha_pll_hwfsm_is_enabled, clk_regera_pll_enable, clk_rcg_set_parent, _alpha_pll_lucid_evo_disable, clk_gfx3d_determine_rate, clk_rcg2_crmc_hw_set_rate, clk_pll_vote_enable, clk_hfpll_init, clk_rcg_bypass2_set_rate, clk_alpha_pll_hwfsm_enable, clk_alpha_pll_hwfsm_disable, clk_pixel_set_rate, mux_div_get_src_div, mux_div_get_parent, clk_alpha_pll_is_enabled, alpha_pll_lucid_prepare, trace_event_raw_event_clk_measure_support, alpha_pll_huayra_recalc_rate, __alpha_pll_trion_set_rate, qcom_cc_really_probe, clk_rcg2_vote_bw, clk_pll_disable, clk_rcg2_crmb_hw_set_bw, clk_rcg2_vote_perf_level, clk_alpha_pll_recalc_rate, mux_get_parent, div_recalc_rate, clk_rivian_evo_pll_recalc_rate, clk_byte2_set_rate, clk_alpha_pll_hwfsm_set_rate, clk_rcg2_list_registers, clk_rcg2_shared_get_parent, _qcom_cc_register_board_clk, alpha_pll_lucid_5lpe_disable, perf_trace_clk_state_dump, qcom_clk_crm_init, clk_dyn_rcg_determine_rate, clk_dyn_rcg_set_parent, clk_trion_pll_postdiv_recalc_rate, clk_regera_pll_recalc_rate, lucid_evo_calc_pll_out, clk_debug_measure_get, clk_zonda_pll_enable, clk_zonda_5lpe_pll_enable, clk_trion_pll_configure, clk_rcg2_dfs_recalc_rate, clk_zonda_evo_pll_enable, clk_zonda_pll_is_enabled, clk_rcg2_set_duty_cycle, wait_for_pll, clk_trion_pll_disable, clk_branch2_sreg_enable, clk_regera_pll_set_rate, clk_rivian_evo_pll_configure, clk_agera_pll_list_registers, clk_alpha_pll_set_rate, clk_rcg2_dfs_determine_rate, clk_zonda_pll_disable, qcom_cc_register_rcg_dfs, clk_edp_pixel_set_rate_and_parent, clk_branch2_mem_enable, clk_regera_pll_disable, __clk_lucid_pll_postdiv_set_rate, clk_branch_wait, gdsc_poll_status, clk_regmap_div_list_rate, mux_div_set_src_div, clk_branch2_mem_list_registers, clk_rcg2_shared_recalc_rate, clk_hfpll_enable, __clk_rcg2_recalc_rate, clk_hfpll_recalc_rate, alpha_pll_huayra_set_rate, clk_branch2_list_registers, clk_rcg2_recalc_rate, lucid_evo_pll_list_registers, run_measurement, clk_trion_pll_recalc_rate, mux_div_recalc_rate, clk_regera_pll_list_registers, clk_alpha_pll_slew_update, clk_pll_recalc_rate, clk_alpha_pll_zonda_list_registers, clk_branch_check_halt, clk_rcg2_dp_determine_rate, alpha_pll_fabia_enable, clk_pll_sr2_set_rate, div_round_ro_rate, clk_pll_enable, clk_pll_set_rate, clk_alpha_pll_disable, trace_event_raw_event_clk_state_dump, alpha_pll_fabia_recalc_rate, __clk_alpha_pll_update_latch, qcom_cc_runtime_suspend, clk_rcg_pixel_set_rate, clk_dyn_rcg_get_parent, clk_byte_set_rate_and_parent, clk_regmap_mux_list_registers, clk_rcg2_set_force_enable, clk_byte_set_rate, clk_alpha_pll_postdiv_fabia_set_rate, clk_rcg2_get_duty_cycle, update_config, clk_is_enabled_regmap, clk_trion_pll_list_registers, clk_rcg_recalc_rate, clk_rcg2_configure, clk_alpha_pll_list_registers, clk_rcg_esc_set_rate, clk_edp_pixel_determine_rate, clk_dyn_rcg_recalc_rate, clk_lucid_5lpe_pll_configure, alpha_pll_trion_prepare, clk_rcg2_get_parent, clk_alpha_pll_postdiv_recalc_rate, _alpha_pll_lucid_evo_enable, hfpll_is_enabled, alpha_pll_fabia_disable, configure_bank, clk_trion_pll_enable, clk_rcg_get_parent, clk_hw_populate_clock_opp_table, _alpha_pll_lucid_evo_prepare, clk_branch2_check_halt, clk_trion_pll_is_enabled, clk_fabia_pll_list_registers, clk_alpha_pll_postdiv_round_ro_rate, clk_zonda_evo_pll_configure, clk_rcg2_crmc_populate_freq_table, clk_zonda_evo_pll_disable, alpha_pll_lucid_5lpe_enable, alpha_pll_lucid_evo_recalc_rate, clk_alpha_pll_enable, perf_trace_clk_measure_support, lucid_pll_list_registers, qcom_cc_runtime_resume, _freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_num_parents @ 00127038 size=1
// signature: undefined clk_hw_get_num_parents(void)
// callers: [clk_dyn_rcg_get_parent, mux_div_determine_rate, enable_debug_clks, clk_rcg2_dfs_determine_rate, clk_rcg_bypass2_set_rate, clk_pixel_set_rate, clk_debug_mux_set_parent, mux_div_get_parent, qcom_find_src_index, disable_debug_clks, clk_rcg_esc_set_rate, clk_rcg2_dp_set_rate, clk_rcg2_get_parent, clk_byte2_set_rate, mux_div_recalc_rate, clk_rcg_get_parent, __mux_div_set_rate_and_parent, clk_rcg2_shared_get_parent, clk_debug_measure_set, clk_rcg2_crmc_populate_freq_table, clk_debug_mux_get_parent, clk_find_and_set_parent, clk_debug_measure_get, qcom_find_cfg_index, clk_rcg_pixel_set_rate, clk_debug_mux_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_num_parents(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 00127040 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [qcom_cc_map, qcom_cc_probe, qcom_cc_probe_by_index]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 00127048 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [qcom_cc_map, qcom_cc_probe, qcom_cc_probe_by_index]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00127050 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [clk_restore_critical_clocks, clk_branch2_force_off_enable, clk_rivian_evo_pll_configure, clk_alpha_pll_set_rate, enable_debug_clks, clk_zonda_pll_disable, __clk_rcg_set_rate, div_set_rate, clk_branch2_mem_enable, clk_alpha_pll_dynamic_update, clk_debug_mux_set_parent, clk_regera_pll_disable, clk_lucid_evo_pll_configure, __clk_lucid_pll_postdiv_set_rate, clk_rcg2_disable, gdsc_register, mux_div_set_src_div, disable_debug_clks, clk_rcg2_shared_init, __clk_hfpll_enable, alpha_pll_huayra_set_rate, clk_trion_pll_postdiv_set_rate, run_measurement, clk_pll_sr2_enable, qcom_reset_set, clk_alpha_pll_slew_update, clk_fabia_pll_configure, clk_alpha_pll_slew_enable, alpha_pll_fabia_enable, mux_set_parent, clk_pll_sr2_set_rate, clk_pll_enable, clk_pll_configure_sr_hpm_lp, clk_zonda_5lpe_pll_disable, clk_pll_set_rate, clk_alpha_pll_disable, alpha_pll_lucid_evo_set_rate, __clk_alpha_pll_update_latch, clk_hfpll_set_rate, clk_rcg2_enable, clk_hfpll_disable, clk_regera_pll_enable, gdsc_toggle_logic, _alpha_pll_lucid_evo_disable, clk_enable_regmap, clk_branch2_force_off_disable, clk_rcg2_shared_disable, clk_alpha_pll_hwfsm_disable, clk_zonda_pll_configure, clk_rcg2_set_force_enable, clk_disable_regmap, clk_alpha_pll_postdiv_fabia_set_rate, __alpha_pll_trion_set_rate, update_config, clk_branch2_mem_disable, clk_pll_disable, clk_lucid_5lpe_pll_configure, _alpha_pll_lucid_evo_enable, clk_alpha_pll_postdiv_set_rate, alpha_pll_fabia_disable, clk_alpha_pll_hwfsm_set_rate, clk_trion_pll_enable, clk_alpha_pll_configure, __clk_rcg2_configure, clk_pll_configure_sr, phy_mux_disable, clk_debug_measure_set, alpha_pll_lucid_5lpe_disable, clk_zonda_evo_pll_configure, qcom_pll_set_fsm_mode, clk_rcg2_shared_set_rate, clk_rcg_lcc_disable, clk_rcg2_shared_set_parent, gdsc_disable, clk_rcg2_set_parent, clk_branch2_set_flags, clk_zonda_evo_pll_disable, __clk_rcg2_set_rate, alpha_pll_lucid_5lpe_enable, clk_alpha_pll_enable, phy_mux_enable, clk_zonda_pll_enable, clk_zonda_5lpe_pll_enable, clk_rcg2_shared_enable, clk_trion_pll_configure, clk_rcg_lcc_set_rate, clk_zonda_evo_pll_enable, clk_rcg_lcc_enable, clk_rcg2_set_duty_cycle, gdsc_enable, clk_trion_pll_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00127058 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [_qcom_cc_register_board_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 00127060 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [_qcom_cc_register_board_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00127068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_cc_really_probe, gdsc_register, _qcom_cc_register_board_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_hw_register @ 00127078 size=1
// signature: undefined devm_clk_hw_register(void)
// callers: [devm_clk_register_regmap, qcom_cc_really_probe, _qcom_cc_register_board_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_hw_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_reset_controller_register @ 00127088 size=1
// signature: undefined devm_reset_controller_register(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_reset_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_prop_next_u32 @ 00127090 size=1
// signature: undefined of_prop_next_u32(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_prop_next_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_by_phandle @ 00127098 size=1
// signature: undefined of_find_node_by_phandle(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_parent @ 001270a0 size=1
// signature: undefined of_get_parent(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 001270a8 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001270b0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [clk_hw_populate_clock_opp_table, qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_clk_add_hw_provider @ 001270b8 size=1
// signature: undefined devm_of_clk_add_hw_provider(void)
// callers: [qcom_cc_really_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_clk_add_hw_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_add_action @ 001270c0 size=1
// signature: undefined devm_add_action(void)
// callers: [devm_add_action_or_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_add_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001270c8 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_cc_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_sync_state @ 001270d0 size=1
// signature: undefined clk_sync_state(void)
// callers: [qcom_cc_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_sync_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_parent @ 001270d8 size=1
// signature: undefined clk_get_parent(void)
// callers: [qcom_clk_crm_set_rate, clock_debug_print_enabled_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_get_hw @ 001270e0 size=1
// signature: undefined __clk_get_hw(void)
// callers: [qcom_clk_crm_set_rate, qcom_clk_set_flags, clock_debug_print_enabled_clocks, qcom_clk_dump, qcom_clk_get_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_get_hw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 001270e8 size=1
// signature: undefined clk_get(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_put @ 001270f0 size=1
// signature: undefined clk_put(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 001270f8 size=1
// signature: undefined of_icc_get(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00127100 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_clk_create @ 00127108 size=1
// signature: undefined pm_clk_create(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_clk_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00127110 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 00127118 size=1
// signature: undefined icc_put(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_clk_add @ 00127120 size=1
// signature: undefined pm_clk_add(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_clk_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_clk_destroy @ 00127128 size=1
// signature: undefined pm_clk_destroy(void)
// callers: [qcom_cc_runtime_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_clk_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00127130 size=1
// signature: undefined icc_set_bw(void)
// callers: [qcom_cc_runtime_resume, qcom_cc_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_clk_resume @ 00127138 size=1
// signature: undefined pm_clk_resume(void)
// callers: [qcom_cc_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_clk_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00127140 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_cc_runtime_resume, qcom_cc_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_clk_suspend @ 00127148 size=1
// signature: undefined pm_clk_suspend(void)
// callers: [qcom_cc_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_clk_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00127150 size=1
// signature: undefined mutex_lock(void)
// callers: [clk_debug_exit, enabled_clocks_show, clock_debug_trace, clk_vdd_proxy_vote, clk_debug_measure_get, clk_vote_vdd_level, clk_unvote_vdd_level, devm_clk_register_debug_mux, clk_vdd_proxy_unvote, clk_debug_measure_set, clk_hw_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00127158 size=1
// signature: undefined mutex_unlock(void)
// callers: [clk_debug_exit, enabled_clocks_show, clock_debug_trace, clk_vdd_proxy_vote, clk_debug_measure_get, clk_vote_vdd_level, clk_unvote_vdd_level, devm_clk_register_debug_mux, clk_vdd_proxy_unvote, clk_debug_measure_set, clk_hw_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00127160 size=1
// signature: undefined __warn_printk(void)
// callers: [gdsc_toggle_logic, clk_pll_sr2_enable, qcom_reset_set, clk_vdd_proxy_vote, clk_pll_vote_enable, clk_prepare_regmap, clk_hfpll_init, clk_vote_vdd_level, clk_unvote_vdd_level, clk_branch2_mem_enable, clk_rcg2_set_force_enable, clk_branch_wait, __alpha_pll_trion_set_rate, update_config, alpha_pll_lucid_evo_set_rate, clk_vdd_proxy_unvote, wait_for_pll, qcom_clk_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_name @ 00127168 size=1
// signature: undefined clk_hw_get_name(void)
// callers: [clk_regera_pll_set_rate, clk_alpha_pll_set_rate, clk_rcg2_dfs_determine_rate, clock_debug_print_enabled_clocks, clk_branch2_mem_enable, __clk_lucid_pll_postdiv_set_rate, clk_rcg2_disable, clk_branch_wait, mux_div_set_src_div, clk_zonda_pll_set_rate, qcom_clk_dump, alpha_pll_huayra_set_rate, clk_pll_sr2_enable, mux_div_recalc_rate, clk_prepare_regmap, rate_max_show, clk_rcg2_crmc_unprepare, clk_debug_mux_get_parent, alpha_pll_fabia_prepare, alpha_pll_lucid_evo_set_rate, clk_find_vdd_level, clk_regera_pll_enable, clk_debug_print_hw, clk_rcg2_crmc_hw_set_rate, clock_debug_trace, clk_pll_vote_enable, alpha_pll_fabia_set_rate, clk_branch_restore_context, mux_div_get_src_div, clk_rcg2_crmc_determine_rate, clk_rcg2_set_force_enable, mux_div_get_parent, __alpha_pll_trion_set_rate, clk_alpha_pll_agera_set_rate, update_config, clk_rcg2_vote_bw, clk_rcg2_crmb_hw_set_bw, clk_rcg2_vote_perf_level, clk_branch_restore_context_aon, clk_lucid_5lpe_pll_configure, _alpha_pll_lucid_evo_enable, clk_alpha_pll_hwfsm_set_rate, clk_hw_populate_clock_opp_table, clk_rcg2_crmb_unprepare, clk_rcg2_crmb_set_rate, clk_rcg2_crmc_populate_freq_table, clk_debug_measure_get, clk_zonda_5lpe_pll_enable, wait_for_pll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00127170 size=1
// signature: undefined devm_regulator_get(void)
// callers: [gdsc_register, clk_regulator_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00127178 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [clk_regulator_init, clk_regulator_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00127180 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [clk_aggregate_vdd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00127188 size=1
// signature: undefined regulator_enable(void)
// callers: [gdsc_toggle_logic, gdsc_register, clk_aggregate_vdd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00127190 size=1
// signature: undefined regulator_disable(void)
// callers: [gdsc_toggle_logic, gdsc_register, clk_aggregate_vdd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00127198 size=1
// signature: undefined regmap_read(void)
// callers: [clk_alpha_pll_postdiv_fabia_recalc_rate, clk_edp_pixel_set_rate, clk_zonda_pll_recalc_rate, alpha_pll_lucid_5lpe_prepare, clk_regera_pll_configure, __clk_rcg_set_rate, phy_mux_is_enabled, clk_lucid_evo_pll_configure, clk_alpha_pll_huayra_list_registers, gdsc_register, clk_rcg2_is_force_enabled, clk_zonda_pll_set_rate, clk_rcg2_shared_init, __clk_hfpll_enable, clk_rcg2_dp_set_rate, clk_pll_sr2_enable, qcom_reset_set, clk_rcg2_is_enabled, clk_branch2_sreg_disable, clk_rivian_evo_pll_list_registers, alpha_pll_fabia_prepare, clk_zonda_5lpe_pll_disable, clk_alpha_pll_zonda_evo_list_registers, alpha_pll_lucid_evo_set_rate, clk_hfpll_set_rate, clk_alpha_pll_hwfsm_is_enabled, clk_regera_pll_enable, clk_rcg_set_parent, _alpha_pll_lucid_evo_disable, clk_pll_vote_enable, clk_hfpll_init, clk_rcg_bypass2_set_rate, clk_alpha_pll_hwfsm_enable, clk_rcg2_shared_disable, clk_alpha_pll_hwfsm_disable, clk_pixel_set_rate, mux_div_get_src_div, clk_alpha_pll_is_enabled, alpha_pll_lucid_prepare, alpha_pll_huayra_recalc_rate, __alpha_pll_trion_set_rate, clk_pll_disable, clk_alpha_pll_recalc_rate, mux_get_parent, div_recalc_rate, clk_rivian_evo_pll_recalc_rate, clk_byte2_set_rate, clk_alpha_pll_hwfsm_set_rate, clk_rcg2_list_registers, clk_rcg2_shared_get_parent, alpha_pll_lucid_5lpe_disable, clk_dyn_rcg_determine_rate, clk_dyn_rcg_set_parent, clk_trion_pll_postdiv_recalc_rate, clk_regera_pll_recalc_rate, lucid_evo_calc_pll_out, clk_debug_measure_get, clk_zonda_pll_enable, clk_zonda_5lpe_pll_enable, clk_trion_pll_configure, clk_rcg2_dfs_recalc_rate, clk_zonda_evo_pll_enable, clk_zonda_pll_is_enabled, clk_rcg2_set_duty_cycle, wait_for_pll, clk_trion_pll_disable, clk_branch2_sreg_enable, clk_regera_pll_set_rate, clk_rivian_evo_pll_configure, clk_agera_pll_list_registers, clk_alpha_pll_set_rate, clk_rcg2_dfs_determine_rate, clk_zonda_pll_disable, qcom_cc_register_rcg_dfs, clk_edp_pixel_set_rate_and_parent, clk_branch2_mem_enable, clk_regera_pll_disable, __clk_lucid_pll_postdiv_set_rate, clk_branch_wait, gdsc_poll_status, clk_regmap_div_list_rate, mux_div_set_src_div, clk_branch2_mem_list_registers, clk_rcg2_shared_recalc_rate, clk_hfpll_enable, __clk_rcg2_recalc_rate, clk_hfpll_recalc_rate, alpha_pll_huayra_set_rate, clk_branch2_list_registers, clk_rcg2_recalc_rate, lucid_evo_pll_list_registers, run_measurement, clk_trion_pll_recalc_rate, clk_regera_pll_list_registers, clk_alpha_pll_slew_update, clk_pll_recalc_rate, clk_alpha_pll_zonda_list_registers, clk_branch_check_halt, alpha_pll_fabia_enable, clk_pll_sr2_set_rate, div_round_ro_rate, clk_pll_enable, clk_pll_set_rate, clk_alpha_pll_disable, alpha_pll_fabia_recalc_rate, __clk_alpha_pll_update_latch, clk_rcg_pixel_set_rate, clk_dyn_rcg_get_parent, clk_regmap_mux_list_registers, clk_rcg2_set_force_enable, clk_alpha_pll_postdiv_fabia_set_rate, clk_rcg2_get_duty_cycle, update_config, clk_is_enabled_regmap, clk_trion_pll_list_registers, clk_rcg_recalc_rate, clk_rcg2_configure, clk_alpha_pll_list_registers, clk_rcg_esc_set_rate, clk_edp_pixel_determine_rate, clk_dyn_rcg_recalc_rate, clk_lucid_5lpe_pll_configure, alpha_pll_trion_prepare, clk_rcg2_get_parent, clk_alpha_pll_postdiv_recalc_rate, _alpha_pll_lucid_evo_enable, hfpll_is_enabled, alpha_pll_fabia_disable, configure_bank, clk_trion_pll_enable, clk_rcg_get_parent, _alpha_pll_lucid_evo_prepare, clk_branch2_check_halt, clk_trion_pll_is_enabled, clk_fabia_pll_list_registers, clk_alpha_pll_postdiv_round_ro_rate, clk_zonda_evo_pll_configure, clk_rcg2_crmc_populate_freq_table, clk_zonda_evo_pll_disable, alpha_pll_lucid_5lpe_enable, alpha_pll_lucid_evo_recalc_rate, clk_alpha_pll_enable, lucid_pll_list_registers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_is_prepared @ 001271a0 size=1
// signature: undefined clk_hw_is_prepared(void)
// callers: [clk_branch2_hw_ctl_enable, clk_pre_change_regmap, __clk_rcg2_set_rate, clock_debug_trace, clock_debug_print_enabled_clocks, clk_post_change_regmap, clk_rcg2_crmc_set_rate, __clk_rcg2_recalc_rate, clk_rcg2_crmb_set_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_is_prepared(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_rate @ 001271a8 size=1
// signature: undefined clk_hw_get_rate(void)
// callers: [mux_div_determine_rate, clk_gfx3d_determine_rate, mux_div_recalc_rate, _alpha_pll_lucid_evo_prepare, clock_debug_trace, clk_rcg2_dfs_determine_rate, clk_prepare_regmap, clk_rcg_esc_determine_rate, __mux_div_set_rate_and_parent, clock_debug_print_enabled_clocks, clk_alpha_pll_slew_set_rate, _freq_tbl_determine_rate, __clk_hfpll_init_once, clk_alpha_pll_slew_enable, lucid_evo_calc_pll, clk_rcg2_crmc_populate_freq_table, clk_branch_wait, alpha_pll_fabia_prepare, lucid_evo_calc_pll_out, clk_edp_pixel_determine_rate, _freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001271b0 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [devm_clk_register_regmap, clk_is_regmap_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001271b8 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [devm_clk_register_regmap, clk_is_regmap_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 001271c0 size=1
// signature: undefined dev_get_regmap(void)
// callers: [clk_restore_critical_clocks, devm_clk_register_regmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001271c8 size=1
// signature: undefined __list_add_valid(void)
// callers: [devm_clk_register_regmap, devm_clk_regmap_list_node, devm_clk_register_debug_mux, clk_hw_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001271d0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [qcom_reset_set, clock_pm_restore_early, register_qcom_clks_pm, clock_pm_resume_early, clk_runtime_get_regmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001271d8 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [qcom_reset_set, clock_pm_restore_early, clock_pm_resume_early, clk_runtime_put_regmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001271e0 size=1
// signature: undefined regmap_write(void)
// callers: [clk_regera_pll_set_rate, clk_rivian_evo_pll_configure, clk_alpha_pll_set_rate, clk_zonda_pll_disable, clk_regera_pll_configure, __clk_rcg_set_rate, clk_regera_pll_disable, clk_lucid_evo_pll_configure, clk_zonda_pll_set_rate, clk_rcg2_shared_init, alpha_pll_huayra_set_rate, clk_fabia_pll_configure, clk_alpha_pll_slew_set_rate, __clk_hfpll_init_once, clk_alpha_pll_slew_enable, alpha_pll_fabia_enable, alpha_pll_fabia_prepare, clk_pll_configure_sr_hpm_lp, clk_zonda_5lpe_pll_disable, clk_pll_set_rate, alpha_pll_lucid_evo_set_rate, clk_hfpll_set_rate, clk_regera_pll_enable, clk_rcg_set_parent, _alpha_pll_lucid_evo_disable, clk_agera_pll_configure, alpha_pll_fabia_set_rate, clk_alpha_pll_hwfsm_enable, clk_rcg2_shared_disable, clk_zonda_pll_configure, __alpha_pll_trion_set_rate, clk_alpha_pll_agera_set_rate, clk_rcg2_configure, clk_gfx3d_set_rate_and_parent, clk_lucid_5lpe_pll_configure, _alpha_pll_lucid_evo_enable, alpha_pll_fabia_disable, configure_bank, clk_alpha_pll_hwfsm_set_rate, clk_trion_pll_enable, clk_alpha_pll_configure, clk_pll_configure_sr, alpha_pll_lucid_5lpe_disable, clk_zonda_evo_pll_configure, clk_zonda_evo_pll_disable, alpha_pll_lucid_5lpe_enable, clk_debug_measure_get, clk_zonda_pll_enable, clk_zonda_5lpe_pll_enable, clk_rcg2_shared_enable, clk_trion_pll_configure, clk_zonda_evo_pll_enable, clk_trion_pll_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001271e8 size=1
// signature: undefined __const_udelay(void)
// callers: [gdsc_toggle_logic, clk_regera_pll_set_rate, clk_pll_vote_enable, clk_alpha_pll_dynamic_update, clk_rcg2_set_force_enable, clk_branch_wait, __alpha_pll_trion_set_rate, update_config, mux_div_set_src_div, clk_zonda_pll_set_rate, __clk_hfpll_enable, run_measurement, clk_pll_sr2_enable, clk_alpha_pll_slew_update, clk_branch2_sreg_disable, gdsc_disable, clk_branch2_set_flags, clk_pll_enable, clk_alpha_pll_enable, clk_alpha_pll_disable, clk_zonda_pll_enable, alpha_pll_lucid_evo_set_rate, __clk_alpha_pll_update_latch, clk_zonda_evo_pll_enable, gdsc_enable, wait_for_pll, clk_branch2_sreg_enable, clk_regera_pll_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_parent @ 001271f0 size=1
// signature: undefined clk_hw_get_parent(void)
// callers: [clk_trion_pll_postdiv_round_rate, clk_branch2_hw_ctl_enable, div_round_rate, clk_debug_print_hw, _alpha_pll_lucid_evo_prepare, enable_debug_clks, clk_pll_vote_enable, alpha_pll_lucid_5lpe_prepare, clk_branch2_hw_ctl_determine_rate, clk_alpha_pll_postdiv_round_rate, clk_branch2_hw_ctl_disable, clk_alpha_pll_slew_enable, clk_alpha_pll_postdiv_round_ro_rate, div_round_ro_rate, lucid_evo_calc_pll, clk_debug_mux_get_parent, alpha_pll_fabia_prepare, lucid_evo_calc_pll_out, clk_regmap_div_list_rate, clk_debug_measure_get, clk_alpha_pll_postdiv_fabia_round_rate, disable_debug_clks, get_mux_divs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// divider_round_rate_parent @ 001271f8 size=1
// signature: undefined divider_round_rate_parent(void)
// callers: [clk_trion_pll_postdiv_round_rate, div_round_rate, clk_alpha_pll_postdiv_fabia_round_rate, clk_alpha_pll_postdiv_round_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void divider_round_rate_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_flags @ 00127200 size=1
// signature: undefined clk_hw_get_flags(void)
// callers: [_freq_tbl_determine_rate, clk_alpha_pll_postdiv_round_ro_rate, _freq_tbl_determine_rate, clk_branch_restore_context]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_round_rate @ 00127208 size=1
// signature: undefined clk_hw_round_rate(void)
// callers: [clk_rcg_bypass2_determine_rate, mux_div_determine_rate, clk_rcg_bypass_determine_rate, clk_hw_populate_clock_opp_table, clk_pixel_determine_rate, __mux_div_set_rate_and_parent, clk_rcg_pixel_determine_rate, clk_byte_determine_rate, clk_byte2_determine_rate, clk_alpha_pll_postdiv_round_ro_rate, _freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_is_enabled @ 00127210 size=1
// signature: undefined clk_hw_is_enabled(void)
// callers: [__alpha_pll_trion_set_rate, clk_alpha_pll_agera_set_rate, clock_debug_trace, alpha_pll_lucid_evo_set_rate, clk_rcg2_shared_get_parent, clock_debug_print_enabled_clocks, clk_alpha_pll_slew_set_rate, clk_zonda_pll_set_rate, clk_rcg2_shared_recalc_rate, __clk_rcg2_recalc_rate, clk_rcg2_shared_set_rate, clk_rcg2_shared_set_parent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00127218 size=1
// signature: undefined sched_clock(void)
// callers: [wait_for_pll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00127220 size=1
// signature: undefined seq_printf(void)
// callers: [clk_branch2_list_registers, list_rates_show, clk_agera_pll_list_registers, lucid_evo_pll_list_registers, clk_debug_print_hw, clk_regera_pll_list_registers, clk_rcg2_list_registers, clk_regmap_mux_list_registers, clk_fabia_pll_list_registers, clk_alpha_pll_zonda_list_registers, clock_debug_print_enabled_clocks, rate_max_show, clk_rivian_evo_pll_list_registers, clk_alpha_pll_huayra_list_registers, clk_alpha_pll_zonda_evo_list_registers, clk_trion_pll_list_registers, clk_alpha_pll_list_registers, lucid_pll_list_registers, clk_branch2_mem_list_registers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00127228 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_clk_measure_support, clk_hw_populate_clock_opp_table, trace_event_raw_event_clk_state_dump, perf_trace_clk_measure_support, perf_trace_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00127230 size=1
// signature: undefined scnprintf(void)
// callers: [clk_hw_populate_clock_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00127238 size=1
// signature: undefined __kmalloc(void)
// callers: [clk_hw_populate_clock_opp_table, rate_max_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00127240 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [clk_hw_populate_clock_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_add @ 00127248 size=1
// signature: undefined dev_pm_opp_add(void)
// callers: [clk_hw_populate_clock_opp_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00127250 size=1
// signature: undefined kfree(void)
// callers: [clk_debug_exit, clk_hw_populate_clock_opp_table, rate_max_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_parent_by_index @ 00127258 size=1
// signature: undefined clk_hw_get_parent_by_index(void)
// callers: [mux_div_determine_rate, clk_gfx3d_determine_rate, mux_div_recalc_rate, enable_debug_clks, clk_rcg2_dfs_determine_rate, __mux_div_set_rate_and_parent, _freq_tbl_determine_rate, clk_debug_measure_set, clk_debug_mux_set_parent, clk_rcg2_crmc_populate_freq_table, clk_debug_mux_get_parent, __clk_rcg2_set_rate, clk_rcg_bypass_determine_rate, clk_find_and_set_parent, clk_debug_measure_get, disable_debug_clks, clk_edp_pixel_determine_rate, clk_byte_determine_rate, _freq_tbl_determine_rate, clk_debug_mux_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_parent_by_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_is_enabled @ 00127260 size=1
// signature: undefined __clk_is_enabled(void)
// callers: [configure_bank, clk_rcg_lcc_set_rate, clk_hfpll_set_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_rate_range @ 00127268 size=1
// signature: undefined clk_hw_get_rate_range(void)
// callers: [clk_gfx3d_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_rate_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_determine_rate @ 00127270 size=1
// signature: undefined __clk_determine_rate(void)
// callers: [clk_gfx3d_determine_rate, _freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_determine_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00127280 size=1
// signature: undefined kmalloc_trace(void)
// callers: [clk_rcg2_crmc_populate_freq_table, clk_rcg2_dfs_determine_rate, clk_hw_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_write_perf_ol @ 00127288 size=1
// signature: undefined crm_write_perf_ol(void)
// callers: [clk_rcg2_crmc_hw_set_rate, clk_rcg2_vote_perf_level]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_write_perf_ol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_write_bw_vote @ 00127290 size=1
// signature: undefined crm_write_bw_vote(void)
// callers: [clk_rcg2_vote_bw, clk_rcg2_crmb_hw_set_bw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_write_bw_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rational_best_approximation @ 00127298 size=1
// signature: undefined rational_best_approximation(void)
// callers: [clk_rcg2_dp_determine_rate, clk_rcg2_dp_set_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rational_best_approximation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 001272a0 size=1
// signature: undefined clk_set_rate(void)
// callers: [_freq_tbl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001272a8 size=1
// signature: undefined clk_disable(void)
// callers: [__clk_rcg2_set_rate, clk_debug_measure_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001272b0 size=1
// signature: undefined clk_unprepare(void)
// callers: [__clk_rcg2_set_rate, clk_debug_measure_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 001272b8 size=1
// signature: undefined clk_get_rate(void)
// callers: [__clk_rcg2_set_rate, rate_max_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001272c0 size=1
// signature: undefined clk_prepare(void)
// callers: [__clk_rcg2_set_rate, clk_debug_measure_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001272c8 size=1
// signature: undefined clk_enable(void)
// callers: [__clk_rcg2_set_rate, clk_debug_measure_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001272d8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [clk_branch2_mem_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001272e0 size=1
// signature: undefined ktime_get(void)
// callers: [gdsc_poll_status, clk_branch2_mem_enable, __clk_hfpll_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 001272e8 size=1
// signature: undefined clk_round_rate(void)
// callers: [clk_branch2_hw_ctl_determine_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// divider_recalc_rate @ 001272f0 size=1
// signature: undefined divider_recalc_rate(void)
// callers: [div_recalc_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void divider_recalc_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// divider_get_val @ 001272f8 size=1
// signature: undefined divider_get_val(void)
// callers: [div_set_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void divider_get_val(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// divider_ro_round_rate_parent @ 00127300 size=1
// signature: undefined divider_ro_round_rate_parent(void)
// callers: [div_round_ro_rate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void divider_ro_round_rate_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00127308 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [clk_debug_measure_get, clk_hfpll_set_rate, clk_hfpll_enable, clk_hfpll_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00127310 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [clk_debug_measure_get, clk_hfpll_set_rate, clk_hfpll_enable, clk_hfpll_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_get_name @ 00127318 size=1
// signature: undefined __clk_get_name(void)
// callers: [clk_hfpll_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 00127320 size=1
// signature: undefined __udelay(void)
// callers: [qcom_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00127328 size=1
// signature: undefined usleep_range_state(void)
// callers: [qcom_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_restore_context @ 00127340 size=1
// signature: undefined clk_restore_context(void)
// callers: [clock_pm_restore_early, clock_pm_resume_early]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_restore_context(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00127358 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_clk_measure_support, trace_event_raw_event_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00127360 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_clk_measure_support, trace_event_raw_event_clk_state_dump, perf_trace_clk_measure_support, perf_trace_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00127368 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_clk_measure_support, trace_event_raw_event_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00127370 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_clk_measure_support, trace_event_raw_event_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00127378 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_clk_measure_support, perf_trace_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00127380 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_clk_measure_support, perf_trace_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00127388 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 00127390 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_clk_measure_support]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00127398 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [clk_debug_mux_get_parent, clk_debug_suspend_trace_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001273a0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [clk_common_debug_init, clk_debug_measure_add, clk_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 001273a8 size=1
// signature: undefined devm_clk_register(void)
// callers: [devm_clk_register_debug_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001273b0 size=1
// signature: undefined of_get_property(void)
// callers: [map_debug_bases]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_mmio_detach_clk @ 001273b8 size=1
// signature: undefined regmap_mmio_detach_clk(void)
// callers: [map_debug_bases]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_mmio_detach_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 001273c0 size=1
// signature: undefined debugfs_lookup(void)
// callers: [clk_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 001273c8 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [clk_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dput @ 001273d0 size=1
// signature: undefined dput(void)
// callers: [clk_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001273d8 size=1
// signature: undefined debugfs_remove(void)
// callers: [clk_debug_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001273e8 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [clk_debug_suspend_enable_set, clk_debug_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001273f0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [clk_debug_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gdsc_debug_print_regs @ 001273f8 size=1
// signature: undefined gdsc_debug_print_regs(void)
// callers: [qcom_clk_bulk_dump, qcom_clk_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gdsc_debug_print_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00127400 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_clk_measure_support, trace_raw_output_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00127408 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_clk_measure_support, trace_raw_output_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00127410 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_clk_measure_support, trace_raw_output_clk_state_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00127418 size=1
// signature: undefined simple_attr_open(void)
// callers: [clk_measure_fops_open, clk_debug_suspend_enable_fops_open, clk_debug_suspend_atomic_enable_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_parent @ 00127438 size=1
// signature: undefined clk_set_parent(void)
// callers: [clk_find_and_set_parent, clk_debug_measure_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00127440 size=1
// signature: undefined single_open(void)
// callers: [rate_max_open, list_rates_open, enabled_clocks_open, clocks_trace_open, print_hw_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00127448 size=1
// signature: undefined seq_puts(void)
// callers: [rate_max_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00127450 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [clk_debug_suspend_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_genpd_init @ 00127498 size=1
// signature: undefined pm_genpd_init(void)
// callers: [gdsc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_genpd_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_genpd_add_provider_onecell @ 001274a0 size=1
// signature: undefined of_genpd_add_provider_onecell(void)
// callers: [gdsc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_genpd_add_provider_onecell(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_genpd_add_subdomain @ 001274a8 size=1
// signature: undefined pm_genpd_add_subdomain(void)
// callers: [gdsc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_genpd_add_subdomain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_genpd_remove_subdomain @ 001274b0 size=1
// signature: undefined pm_genpd_remove_subdomain(void)
// callers: [gdsc_register, gdsc_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_genpd_remove_subdomain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_genpd_del_provider @ 001274b8 size=1
// signature: undefined of_genpd_del_provider(void)
// callers: [gdsc_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_genpd_del_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



