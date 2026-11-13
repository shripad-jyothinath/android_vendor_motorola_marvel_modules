// Decompiled by Ghidra 12.2
// Program: phy-qcom-ufs.ko
// Image base: 00100000

//------------------------------------------------------------
// ufs_qcom_phy_write_tbl @ 0010063c size=88
// signature: undefined ufs_qcom_phy_write_tbl(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_write_tbl(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  undefined4 *puVar2;
  
  if (0 < (int)param_3) {
    uVar1 = (ulong)param_3;
    puVar2 = (undefined4 *)(param_2 + 4);
    do {
      writel_relaxed(*puVar2,*(long *)(param_1 + 0x18) + (ulong)(uint)puVar2[-1]);
      puVar2 = puVar2 + 2;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00100694 size=132
// signature: undefined writel_relaxed(void)
// callers: [ufs_qcom_phy_write_tbl, ufs_qcom_phy_calibrate]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1006ac,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1006e8,uVar1);
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_calibrate @ 0010071c size=460
// signature: undefined ufs_qcom_phy_calibrate(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_calibrate
              (long param_1,long param_2,uint param_3,long param_4,uint param_5,uint param_6)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulong uVar7;
  
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  uVar7 = (ulong)param_3;
  iVar1 = reset_control_assert(*(undefined8 *)(param_1 + 0x198));
  if (iVar1 != 0) {
    _dev_err(uVar5,"Failed to assert UFS PHY reset %d\n",iVar1);
    return iVar1;
  }
  if (param_2 == 0) {
    pcVar2 = "%s: tbl_A is NULL\n";
LAB_001008d0:
    _dev_err(uVar5,pcVar2,"ufs_qcom_phy_calibrate");
    iVar1 = 0x16;
  }
  else {
    if (0 < (int)param_3) {
      puVar6 = (undefined4 *)(param_2 + 4);
      do {
        writel_relaxed(*puVar6,*(long *)(param_1 + 0x18) + (ulong)(uint)puVar6[-1]);
        uVar7 = uVar7 - 1;
        puVar6 = puVar6 + 2;
      } while (uVar7 != 0);
    }
    if ((param_6 & 1) != 0) {
      if (param_4 == 0) {
        pcVar2 = "%s: tbl_B is NULL\n";
        goto LAB_001008d0;
      }
      if (0 < (int)param_5) {
        uVar7 = (ulong)param_5;
        puVar6 = (undefined4 *)(param_4 + 4);
        do {
          writel_relaxed(*puVar6,*(long *)(param_1 + 0x18) + (ulong)(uint)puVar6[-1]);
          uVar7 = uVar7 - 1;
          puVar6 = puVar6 + 2;
        } while (uVar7 != 0);
      }
    }
    DataSynchronizationBarrier(3,3,0);
    iVar1 = reset_control_deassert(*(undefined8 *)(param_1 + 0x198));
    if (iVar1 != 0) {
      _dev_err(uVar5,"Failed to deassert UFS PHY reset %d\n",iVar1);
    }
    pcVar4 = *(code **)(*(long *)(param_1 + 0x188) + 8);
    if (pcVar4 == (code *)0x0) {
      uVar5 = *(undefined8 *)(param_1 + 0x10);
      pcVar2 = "%s: start_serdes() callback is not supported\n";
      pcVar3 = "ufs_qcom_phy_start_serdes";
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x3efbd9e2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1007fc);
        (*pcVar4)();
      }
      (*pcVar4)(param_1);
      pcVar4 = *(code **)(*(long *)(param_1 + 0x188) + 0x10);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x1d9b93af) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100828);
          (*pcVar4)();
        }
        iVar1 = (*pcVar4)(param_1);
        return iVar1;
      }
      uVar5 = *(undefined8 *)(param_1 + 0x10);
      pcVar2 = "%s: is_physical_coding_sublayer_ready() callback is not supported\n";
      pcVar3 = "ufs_qcom_phy_is_pcs_ready";
    }
    _dev_err(uVar5,pcVar2,pcVar3);
    iVar1 = -0x5f;
  }
  return iVar1;
}



//------------------------------------------------------------
// get_ufs_qcom_phy @ 001008ec size=8
// signature: undefined get_ufs_qcom_phy(void)
// callers: []
//------------------------------------------------------------

undefined8 get_ufs_qcom_phy(long param_1)

{
  return *(undefined8 *)(param_1 + 0x98);
}



//------------------------------------------------------------
// ufs_qcom_phy_generic_probe @ 001008f8 size=384
// signature: undefined ufs_qcom_phy_generic_probe(void)
// callers: []
//------------------------------------------------------------

ulong ufs_qcom_phy_generic_probe(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  
  lVar1 = param_1 + 0x10;
  uVar3 = platform_get_resource_byname(param_1,0x200,"phy_mem");
  uVar4 = devm_ioremap_resource(lVar1,uVar3);
  *(ulong *)(param_2 + 0x18) = uVar4;
  if (0xfffffffffffff000 < uVar4) {
    *(undefined8 *)(param_2 + 0x18) = 0;
    _dev_err(lVar1,"%s: ioremap for phy_mem resource failed %d\n","ufs_qcom_phy_base_init",
             uVar4 & 0xffffffff);
    if ((int)uVar4 != 0) {
      pcVar6 = "%s: phy base init failed %d\n";
      goto LAB_00100a4c;
    }
  }
  uVar4 = devm_phy_create(lVar1,0,param_3);
  if (uVar4 < 0xfffffffffffff001) {
    uVar5 = __devm_of_phy_provider_register(lVar1,0,&__this_module,&of_phy_simple_xlate);
    if (0xfffffffffffff000 < uVar5) {
      _dev_err(lVar1,"%s: failed to register phy %d\n","ufs_qcom_phy_generic_probe",uVar5);
      return uVar4;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"lanes-per-direction",
                       (undefined4 *)(param_2 + 0x148),1,0);
    if (iVar2 < 0) {
      *(undefined4 *)(param_2 + 0x148) = 1;
    }
    pm_runtime_no_callbacks(uVar4);
    *(undefined8 *)(param_2 + 0x188) = param_4;
    *(long *)(param_2 + 0x10) = lVar1;
    *(long *)(param_2 + 0x1a0) = param_2 + 0x1a0;
    *(long *)(param_2 + 0x1a8) = param_2 + 0x1a0;
    return uVar4;
  }
  pcVar6 = "%s: failed to create phy %d\n";
LAB_00100a4c:
  _dev_err(lVar1,pcVar6,"ufs_qcom_phy_generic_probe",uVar4 & 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_get_reset @ 00100a7c size=88
// signature: undefined ufs_qcom_phy_get_reset(void)
// callers: []
//------------------------------------------------------------

ulong ufs_qcom_phy_get_reset(long param_1)

{
  ulong uVar1;
  
  if (*(long *)(param_1 + 0x198) == 0) {
    uVar1 = __devm_reset_control_get(*(undefined8 *)(param_1 + 0x10),0,0,0,0,1);
    if (0xfffffffffffff000 < uVar1) {
      return uVar1;
    }
    *(ulong *)(param_1 + 0x198) = uVar1;
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_init_clks @ 00100ad8 size=624
// signature: undefined ufs_qcom_phy_init_clks(void)
// callers: []
//------------------------------------------------------------

ulong ufs_qcom_phy_init_clks(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    _printk(&DAT_001025b7,"ufs_qcom_phy_init_clks");
    uVar2 = 0xfffffdfb;
  }
  else {
    iVar1 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x2e8),
                       "qcom,msm8996-ufs-phy-qmp-14nm");
    if (iVar1 == 0) {
      uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"tx_iface_clk");
      if (uVar2 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + 0x28) = uVar2;
      }
      uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"rx_iface_clk");
      if (uVar2 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + 0x30) = uVar2;
      }
    }
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    uVar2 = devm_clk_get(uVar3,"ref_clk_src");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x40) = uVar2;
    }
    else {
      _dev_err(uVar3,"failed get %s, %d\n","ref_clk_src",uVar2 & 0xffffffff);
      if ((int)uVar2 != 0) goto LAB_00100cf0;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"ref_clk_parent");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x48) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"ref_clk_pad_en");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x50) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"ref_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x58) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"ref_aux_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x60) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"qref_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x68) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"rx_sym0_mux_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x70) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"rx_sym1_mux_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x78) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"tx_sym0_mux_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x80) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"rx_sym0_phy_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x88) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"rx_sym1_phy_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x90) = uVar2;
    }
    uVar2 = devm_clk_get(*(undefined8 *)(param_1 + 0x10),"tx_sym0_phy_clk");
    if (uVar2 < 0xfffffffffffff001) {
      *(ulong *)(param_1 + 0x98) = uVar2;
    }
    if ((((*(long *)(param_1 + 0x70) == 0) || (*(long *)(param_1 + 0x78) == 0)) ||
        (*(long *)(param_1 + 0x80) == 0)) ||
       (((*(long *)(param_1 + 0x40) == 0 || (*(long *)(param_1 + 0x88) == 0)) ||
        ((*(long *)(param_1 + 0x90) == 0 || (*(long *)(param_1 + 0x98) == 0)))))) {
      _dev_err(*(undefined8 *)(param_1 + 0x10),"%s: null clock\n","ufs_qcom_phy_init_clks");
    }
    uVar2 = 0;
  }
LAB_00100cf0:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// ufs_qcom_phy_init_vregulators @ 00100d4c size=148
// signature: undefined ufs_qcom_phy_init_vregulators(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_init_vregulators(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = ufs_qcom_phy_init_vreg(*(undefined8 *)(param_1 + 0x10),param_1 + 0xa8,"vdda-pll");
  if (((int)uVar1 == 0) &&
     (uVar1 = ufs_qcom_phy_init_vreg(*(undefined8 *)(param_1 + 0x10),param_1 + 200,"vdda-phy"),
     (int)uVar1 == 0)) {
    ufs_qcom_phy_init_vreg(*(undefined8 *)(param_1 + 0x10),param_1 + 0xe8,"vddp-ref-clk");
    ufs_qcom_phy_init_vreg(*(undefined8 *)(param_1 + 0x10),param_1 + 0x108,"vdd-phy-gdsc");
    ufs_qcom_phy_init_vreg(*(undefined8 *)(param_1 + 0x10),param_1 + 0x128,"vdda-qref");
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_phy_init_vreg @ 00100de0 size=732
// signature: undefined ufs_qcom_phy_init_vreg(void)
// callers: [ufs_qcom_phy_init_vregulators]
//------------------------------------------------------------

ulong ufs_qcom_phy_init_vreg(long param_1,undefined8 *param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  int *piVar5;
  ulong uVar6;
  char local_b8 [32];
  long local_98 [11];
  
  lVar1 = sp_el0;
  local_98[10] = *(long *)(lVar1 + 0x638);
  local_b8[0x10] = '\0';
  local_b8[0x11] = '\0';
  local_b8[0x12] = '\0';
  local_b8[0x13] = '\0';
  local_b8[0x14] = '\0';
  local_b8[0x15] = '\0';
  local_b8[0x16] = '\0';
  local_b8[0x17] = '\0';
  local_b8[0x18] = '\0';
  local_b8[0x19] = '\0';
  local_b8[0x1a] = '\0';
  local_b8[0x1b] = '\0';
  local_b8[0x1c] = '\0';
  local_b8[0x1d] = '\0';
  local_b8[0x1e] = '\0';
  local_b8[0x1f] = '\0';
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  if (*(long *)(param_1 + 0x2e8) != 0) {
    snprintf(local_b8,0x20,"%s-supply",param_3);
    local_98[8] = 0;
    local_98[9] = 0;
    local_98[6] = 0;
    local_98[7] = 0;
    local_98[4] = 0;
    local_98[5] = 0;
    local_98[2] = 0;
    local_98[3] = 0;
    local_98[0] = 0;
    local_98[1] = 0;
    iVar2 = __of_parse_phandle_with_args(*(undefined8 *)(param_1 + 0x2e8),local_b8,0,0,0,local_98);
    uVar6 = 0xffffffc3;
    if ((iVar2 != 0) || (local_98[0] == 0)) goto LAB_00101014;
  }
  *param_2 = param_3;
  uVar6 = devm_regulator_get(param_1,param_3);
  param_2[1] = uVar6;
  if (0xfffffffffffff000 < uVar6) {
    _dev_err(param_1,"failed to get %s, %d\n",param_3,uVar6 & 0xffffffff);
    goto LAB_00101014;
  }
  if (*(long *)(param_1 + 0x2e8) != 0) {
    snprintf(local_b8,0x20,"%s-max-microamp",param_3);
    uVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2e8),local_b8,param_2 + 2,1,0);
    if (-1 < (int)uVar3) {
      uVar3 = 0;
    }
    uVar6 = (ulong)uVar3;
    if (uVar3 == 0xffffffea) {
      if ((*(int *)(param_2 + 2) != 0) && (iVar2 = regulator_count_voltages(param_2[1]), 0 < iVar2))
      {
        _dev_err(param_1,"%s: %s is mandatory\n","ufs_qcom_phy_init_vreg",local_b8);
        uVar6 = 0xffffffea;
        goto LAB_00101014;
      }
    }
    else if (uVar3 != 0) {
      _dev_err(param_1,"%s: failed to read %s\n","ufs_qcom_phy_init_vreg",local_b8);
      goto LAB_00101014;
    }
  }
  iVar2 = strcmp(param_3,"vdda-pll");
  if (iVar2 == 0) {
    uVar4 = 0x1b774000124f80;
  }
  else {
    iVar2 = strcmp(param_3,"vdda-phy");
    if (iVar2 == 0) {
      piVar5 = (int *)((long)param_2 + 0x14);
      piVar5[0] = 880000;
      piVar5[1] = 0xe1d48;
      snprintf(local_b8,0x20,"%s-min-microvolt",param_3);
      of_property_read_variable_u32_array(*(undefined8 *)(param_1 + 0x2e8),local_b8,piVar5,1,0);
      if (*piVar5 - 0xe1d49U < 0xffff5037) {
        _dev_err(param_1,"%s: ufs vdda-phy invalid min_uV=%duV\n","ufs_qcom_phy_init_vreg");
        uVar6 = 0;
        *piVar5 = 880000;
        goto LAB_00101014;
      }
LAB_00100ff4:
      uVar6 = 0;
      goto LAB_00101014;
    }
    iVar2 = strcmp(param_3,"vddp-ref-clk");
    if (iVar2 == 0) {
      uVar4 = 0x124f8000124f80;
    }
    else {
      iVar2 = strcmp(param_3,"vdda-qref");
      if (iVar2 != 0) goto LAB_00100ff4;
      uVar4 = 0xdea80000d6d80;
    }
  }
  uVar6 = 0;
  *(undefined8 *)((long)param_2 + 0x14) = uVar4;
LAB_00101014:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// ufs_qcom_phy_set_tx_lane_enable @ 001010c0 size=68
// signature: undefined ufs_qcom_phy_set_tx_lane_enable(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_set_tx_lane_enable(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x188) + 0x18);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x7937561b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1010f4);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_save_controller_version @ 00101108 size=36
// signature: undefined ufs_qcom_phy_save_controller_version(void)
// callers: []
//------------------------------------------------------------

undefined8
ufs_qcom_phy_save_controller_version
          (long param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (lVar1 == 0) {
    return 0xfffffdfb;
  }
  *(undefined1 *)(lVar1 + 0x150) = param_2;
  *(undefined2 *)(lVar1 + 0x152) = param_3;
  *(undefined2 *)(lVar1 + 0x154) = param_4;
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_set_src_clk_h8_enter @ 00101130 size=96
// signature: undefined ufs_qcom_phy_set_src_clk_h8_enter(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_set_src_clk_h8_enter(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((((*(long *)(lVar1 + 0x70) != 0) && (*(long *)(lVar1 + 0x78) != 0)) &&
      (*(long *)(lVar1 + 0x80) != 0)) && (*(long *)(lVar1 + 0x40) != 0)) {
    clk_set_parent();
    clk_set_parent(*(undefined8 *)(lVar1 + 0x78),*(undefined8 *)(lVar1 + 0x40));
    clk_set_parent(*(undefined8 *)(lVar1 + 0x80),*(undefined8 *)(lVar1 + 0x40));
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_set_src_clk_h8_exit @ 00101194 size=112
// signature: undefined ufs_qcom_phy_set_src_clk_h8_exit(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_set_src_clk_h8_exit(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((((*(long *)(lVar1 + 0x70) != 0) && (*(long *)(lVar1 + 0x78) != 0)) &&
      (*(long *)(lVar1 + 0x80) != 0)) &&
     (((*(long *)(lVar1 + 0x88) != 0 && (*(long *)(lVar1 + 0x90) != 0)) &&
      (*(long *)(lVar1 + 0x98) != 0)))) {
    clk_set_parent();
    clk_set_parent(*(undefined8 *)(lVar1 + 0x78),*(undefined8 *)(lVar1 + 0x90));
    clk_set_parent(*(undefined8 *)(lVar1 + 0x80),*(undefined8 *)(lVar1 + 0x98));
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_power_on @ 00101208 size=1808
// signature: undefined ufs_qcom_phy_power_on(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_power_on(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  
  lVar9 = *(long *)(param_1 + 0x98);
  uVar8 = *(undefined8 *)(lVar9 + 0x10);
  if ((*(long *)(lVar9 + 0x110) != 0 && lVar9 + 0x108 != 0) && (*(char *)(lVar9 + 0x124) == '\0')) {
    iVar3 = ufs_qcom_phy_cfg_vreg(uVar8,lVar9 + 0x108,1);
    if (iVar3 == 0) {
      iVar3 = regulator_enable(*(undefined8 *)(lVar9 + 0x110));
      if (iVar3 == 0) {
        *(undefined1 *)(lVar9 + 0x124) = 1;
        lVar6 = *(long *)(lVar9 + 0x130);
        goto joined_r0x001012ac;
      }
      pcVar5 = "%s: enable failed, err=%d\n";
    }
    else {
      pcVar5 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    _dev_err(uVar8,pcVar5,"ufs_qcom_phy_enable_vreg",iVar3);
    pcVar5 = "%s enable phy_gdsc failed, err=%d\n";
    goto LAB_0010173c;
  }
  lVar6 = *(long *)(lVar9 + 0x130);
joined_r0x001012ac:
  if (((lVar6 != 0) && (lVar9 + 0x128 != 0)) && (*(char *)(lVar9 + 0x144) == '\0')) {
    iVar3 = ufs_qcom_phy_cfg_vreg(uVar8,lVar9 + 0x128,1);
    if (iVar3 == 0) {
      iVar3 = regulator_enable(*(undefined8 *)(lVar9 + 0x130));
      if (iVar3 == 0) {
        *(undefined1 *)(lVar9 + 0x144) = 1;
        goto LAB_001012b0;
      }
      pcVar5 = "%s: enable failed, err=%d\n";
    }
    else {
      pcVar5 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    _dev_err(uVar8,pcVar5,"ufs_qcom_phy_enable_vreg",iVar3);
    pcVar5 = "%s enable vdda_qref failed, err=%d\n";
    goto LAB_0010173c;
  }
LAB_001012b0:
  puVar1 = (undefined8 *)(lVar9 + 200);
  if ((puVar1 != (undefined8 *)0x0) && (*(char *)(lVar9 + 0xe4) == '\0')) {
    iVar3 = ufs_qcom_phy_cfg_vreg(uVar8,puVar1,1);
    if (iVar3 == 0) {
      iVar3 = regulator_enable(*(undefined8 *)(lVar9 + 0xd0));
      if (iVar3 == 0) {
        *(undefined1 *)(lVar9 + 0xe4) = 1;
        goto LAB_001012e8;
      }
      pcVar5 = "%s: enable failed, err=%d\n";
    }
    else {
      pcVar5 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    _dev_err(uVar8,pcVar5,"ufs_qcom_phy_enable_vreg",iVar3);
    pcVar5 = "%s enable vdda_phy failed, err=%d\n";
LAB_0010173c:
    _dev_err(uVar8,pcVar5,"ufs_qcom_phy_power_on",iVar3);
    return iVar3;
  }
LAB_001012e8:
  pcVar7 = *(code **)(*(long *)(lVar9 + 0x188) + 0x20);
  if (*(int *)(pcVar7 + -4) != 0x4976a4f9) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101310);
    (*pcVar7)();
  }
  (*pcVar7)(lVar9,1);
  puVar2 = (undefined8 *)(lVar9 + 0xa8);
  if ((puVar2 != (undefined8 *)0x0) && (*(char *)(lVar9 + 0xc4) == '\0')) {
    iVar3 = ufs_qcom_phy_cfg_vreg(uVar8,puVar2,1);
    if (iVar3 == 0) {
      iVar3 = regulator_enable(*(undefined8 *)(lVar9 + 0xb0));
      if (iVar3 == 0) {
        *(undefined1 *)(lVar9 + 0xc4) = 1;
        if (*(char *)(lVar9 + 0x38) == '\0') goto LAB_0010132c;
        goto LAB_001013a4;
      }
      pcVar5 = "%s: enable failed, err=%d\n";
    }
    else {
      pcVar5 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
    }
    _dev_err(uVar8,pcVar5,"ufs_qcom_phy_enable_vreg",iVar3);
    _dev_err(uVar8,"%s enable vdda_pll failed, err=%d\n","ufs_qcom_phy_power_on",iVar3);
    goto joined_r0x00101910;
  }
  if (*(char *)(lVar9 + 0x38) == '\0') {
LAB_0010132c:
    lVar6 = *(long *)(lVar9 + 0x28);
    if (lVar6 == 0) goto LAB_001013a4;
    iVar3 = clk_prepare(lVar6);
    if (iVar3 == 0) {
      iVar3 = clk_enable(lVar6);
      if (iVar3 != 0) {
        clk_unprepare(lVar6);
        goto LAB_0010156c;
      }
      uVar10 = *(undefined8 *)(lVar9 + 0x30);
      iVar3 = clk_prepare(uVar10);
      if (iVar3 == 0) {
        iVar3 = clk_enable(uVar10);
        if (iVar3 == 0) {
          *(undefined1 *)(lVar9 + 0x38) = 1;
          goto LAB_001013a4;
        }
        clk_unprepare(uVar10);
      }
      uVar10 = *(undefined8 *)(lVar9 + 0x28);
      clk_disable(uVar10);
      clk_unprepare(uVar10);
      uVar10 = *(undefined8 *)(lVar9 + 0x10);
      pcVar5 = "%s: rx_iface_clk enable failed %d. disabling also tx_iface_clk\n";
    }
    else {
LAB_0010156c:
      uVar10 = *(undefined8 *)(lVar9 + 0x10);
      pcVar5 = "%s: tx_iface_clk enable failed %d\n";
    }
    _dev_err(uVar10,pcVar5,"ufs_qcom_phy_enable_iface_clk",iVar3);
    _dev_err(uVar8,"%s enable phy iface clock failed, err=%d\n","ufs_qcom_phy_power_on",iVar3);
  }
  else {
LAB_001013a4:
    if (*(char *)(lVar9 + 0xa0) == '\0') {
      lVar6 = *(long *)(lVar9 + 0x50);
      if (lVar6 == 0) {
LAB_001013d8:
        lVar6 = *(long *)(lVar9 + 0x68);
        if (((lVar6 != 0) && (iVar3 = clk_prepare(lVar6), iVar3 == 0)) &&
           (iVar3 = clk_enable(lVar6), iVar3 != 0)) {
          clk_unprepare(lVar6);
        }
        uVar10 = *(undefined8 *)(lVar9 + 0x40);
        iVar3 = clk_prepare(uVar10);
        if (iVar3 != 0) {
LAB_001014fc:
          uVar10 = *(undefined8 *)(lVar9 + 0x10);
          pcVar5 = "%s: ref_clk_src enable failed %d\n";
          goto LAB_001015e0;
        }
        iVar3 = clk_enable(uVar10);
        if (iVar3 != 0) {
          clk_unprepare(uVar10);
          goto LAB_001014fc;
        }
        lVar6 = *(long *)(lVar9 + 0x48);
        if (lVar6 == 0) {
LAB_0010143c:
          lVar6 = *(long *)(lVar9 + 0x58);
          if (lVar6 == 0) {
LAB_0010145c:
            lVar6 = *(long *)(lVar9 + 0x60);
            if (lVar6 == 0) {
LAB_0010147c:
              *(undefined1 *)(lVar9 + 0xa0) = 1;
              lVar6 = *(long *)(lVar9 + 0xf0);
              goto joined_r0x001013b0;
            }
            iVar3 = clk_prepare(lVar6);
            if (iVar3 == 0) {
              iVar3 = clk_enable(lVar6);
              if (iVar3 == 0) goto LAB_0010147c;
              clk_unprepare(lVar6);
            }
            _dev_err(*(undefined8 *)(lVar9 + 0x10),"%s: ref_aux_clk enable failed %d\n",
                     "ufs_qcom_phy_enable_ref_clk",iVar3);
            lVar6 = *(long *)(lVar9 + 0x58);
            if (lVar6 != 0) {
              clk_disable(lVar6);
              clk_unprepare(lVar6);
            }
          }
          else {
            iVar3 = clk_prepare(lVar6);
            if (iVar3 == 0) {
              iVar3 = clk_enable(lVar6);
              if (iVar3 == 0) goto LAB_0010145c;
              clk_unprepare(lVar6);
            }
            _dev_err(*(undefined8 *)(lVar9 + 0x10),"%s: ref_clk enable failed %d\n",
                     "ufs_qcom_phy_enable_ref_clk",iVar3);
          }
          lVar6 = *(long *)(lVar9 + 0x48);
          if (lVar6 != 0) {
            clk_disable(lVar6);
            clk_unprepare(lVar6);
          }
        }
        else {
          iVar3 = clk_prepare(lVar6);
          if (iVar3 == 0) {
            iVar3 = clk_enable(lVar6);
            if (iVar3 == 0) goto LAB_0010143c;
            clk_unprepare(lVar6);
          }
          _dev_err(*(undefined8 *)(lVar9 + 0x10),"%s: ref_clk_parent enable failed %d\n",
                   "ufs_qcom_phy_enable_ref_clk",iVar3);
        }
        uVar10 = *(undefined8 *)(lVar9 + 0x40);
        clk_disable(uVar10);
        clk_unprepare(uVar10);
      }
      else {
        iVar3 = clk_prepare(lVar6);
        if (iVar3 == 0) {
          iVar3 = clk_enable(lVar6);
          if (iVar3 == 0) goto LAB_001013d8;
          clk_unprepare(lVar6);
        }
        uVar10 = *(undefined8 *)(lVar9 + 0x10);
        pcVar5 = "%s: ref_clk_pad_en enable failed %d\n";
LAB_001015e0:
        _dev_err(uVar10,pcVar5,"ufs_qcom_phy_enable_ref_clk",iVar3);
      }
      _dev_err(uVar8,"%s enable phy ref clock failed, err=%d\n","ufs_qcom_phy_power_on",iVar3);
      lVar6 = *(long *)(lVar9 + 0x28);
    }
    else {
      lVar6 = *(long *)(lVar9 + 0xf0);
joined_r0x001013b0:
      if (((lVar6 == 0) || (lVar9 + 0xe8 == 0)) || (*(char *)(lVar9 + 0x104) != '\0')) {
        return 0;
      }
      iVar3 = ufs_qcom_phy_cfg_vreg(uVar8,lVar9 + 0xe8,1);
      if (iVar3 == 0) {
        iVar3 = regulator_enable(*(undefined8 *)(lVar9 + 0xf0));
        if (iVar3 == 0) {
          *(undefined1 *)(lVar9 + 0x104) = 1;
          return 0;
        }
        pcVar5 = "%s: enable failed, err=%d\n";
      }
      else {
        pcVar5 = "%s: ufs_qcom_phy_cfg_vreg() failed, err=%d\n";
      }
      _dev_err(uVar8,pcVar5,"ufs_qcom_phy_enable_vreg",iVar3);
      _dev_err(uVar8,"%s enable vddp_ref_clk failed, err=%d\n","ufs_qcom_phy_power_on",iVar3);
      ufs_qcom_phy_disable_ref_clk(lVar9);
      lVar6 = *(long *)(lVar9 + 0x28);
    }
    if ((lVar6 != 0) && (*(char *)(lVar9 + 0x38) != '\0')) {
      clk_disable(lVar6);
      clk_unprepare(lVar6);
      uVar10 = *(undefined8 *)(lVar9 + 0x30);
      clk_disable(uVar10);
      clk_unprepare(uVar10);
      *(undefined1 *)(lVar9 + 0x38) = 0;
    }
  }
  if ((puVar2 != (undefined8 *)0x0) && (*(char *)(lVar9 + 0xc4) != '\0')) {
    iVar4 = regulator_disable(*(undefined8 *)(lVar9 + 0xb0));
    if (iVar4 == 0) {
      ufs_qcom_phy_cfg_vreg(uVar8,puVar2,0);
      *(undefined1 *)(lVar9 + 0xc4) = 0;
    }
    else {
      _dev_err(uVar8,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",*puVar2,iVar4);
    }
  }
joined_r0x00101910:
  if (puVar1 == (undefined8 *)0x0) {
    return iVar3;
  }
  if (*(char *)(lVar9 + 0xe4) == '\0') {
    return iVar3;
  }
  iVar4 = regulator_disable(*(undefined8 *)(lVar9 + 0xd0));
  if (iVar4 == 0) {
    ufs_qcom_phy_cfg_vreg(uVar8,puVar1,0);
    *(undefined1 *)(lVar9 + 0xe4) = 0;
    return iVar3;
  }
  _dev_err(uVar8,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",*puVar1,iVar4);
  return iVar3;
}



//------------------------------------------------------------
// ufs_qcom_phy_disable_ref_clk @ 00101918 size=188
// signature: undefined ufs_qcom_phy_disable_ref_clk(void)
// callers: [ufs_qcom_phy_power_on, ufs_qcom_phy_power_off]
//------------------------------------------------------------

void ufs_qcom_phy_disable_ref_clk(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0xa0) != '\0') {
    lVar1 = *(long *)(param_1 + 0x60);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x58);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x48);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x40);
    clk_disable(uVar2);
    clk_unprepare(uVar2);
    lVar1 = *(long *)(param_1 + 0x50);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x68);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    *(undefined1 *)(param_1 + 0xa0) = 0;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_power_off @ 001019d8 size=524
// signature: undefined ufs_qcom_phy_power_off(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_power_off(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar4 = *(long *)(param_1 + 0x98);
  pcVar3 = *(code **)(*(long *)(lVar4 + 0x188) + 0x20);
  if (*(int *)(pcVar3 + -4) != 0x4976a4f9) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101a18);
    (*pcVar3)();
  }
  (*pcVar3)(lVar4,0);
  if (((*(long *)(lVar4 + 0xf0) != 0) &&
      (puVar1 = (undefined8 *)(lVar4 + 0xe8), puVar1 != (undefined8 *)0x0)) &&
     (*(char *)(lVar4 + 0x104) != '\0')) {
    uVar6 = *(undefined8 *)(lVar4 + 0x10);
    iVar2 = regulator_disable();
    if (iVar2 == 0) {
      ufs_qcom_phy_cfg_vreg(uVar6,puVar1,0);
      *(undefined1 *)(lVar4 + 0x104) = 0;
    }
    else {
      _dev_err(uVar6,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",*puVar1,iVar2);
    }
  }
  ufs_qcom_phy_disable_ref_clk(lVar4);
  lVar5 = *(long *)(lVar4 + 0x28);
  if ((lVar5 != 0) && (*(char *)(lVar4 + 0x38) != '\0')) {
    clk_disable(lVar5);
    clk_unprepare(lVar5);
    uVar6 = *(undefined8 *)(lVar4 + 0x30);
    clk_disable(uVar6);
    clk_unprepare(uVar6);
    *(undefined1 *)(lVar4 + 0x38) = 0;
  }
  puVar1 = (undefined8 *)(lVar4 + 0xa8);
  if ((puVar1 != (undefined8 *)0x0) && (*(char *)(lVar4 + 0xc4) != '\0')) {
    uVar6 = *(undefined8 *)(lVar4 + 0x10);
    iVar2 = regulator_disable(*(undefined8 *)(lVar4 + 0xb0));
    if (iVar2 == 0) {
      ufs_qcom_phy_cfg_vreg(uVar6,puVar1,0);
      *(undefined1 *)(lVar4 + 0xc4) = 0;
    }
    else {
      _dev_err(uVar6,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",*puVar1,iVar2);
    }
  }
  if ((lVar4 != -200) && (*(char *)(lVar4 + 0xe4) != '\0')) {
    uVar6 = *(undefined8 *)(lVar4 + 0x10);
    iVar2 = regulator_disable(*(undefined8 *)(lVar4 + 0xd0));
    if (iVar2 == 0) {
      ufs_qcom_phy_cfg_vreg(uVar6,(undefined8 *)(lVar4 + 200),0);
      *(undefined1 *)(lVar4 + 0xe4) = 0;
    }
    else {
      _dev_err(uVar6,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",
               *(undefined8 *)(lVar4 + 200),iVar2);
    }
  }
  if (((*(long *)(lVar4 + 0x130) != 0) &&
      (puVar1 = (undefined8 *)(lVar4 + 0x128), puVar1 != (undefined8 *)0x0)) &&
     (*(char *)(lVar4 + 0x144) != '\0')) {
    uVar6 = *(undefined8 *)(lVar4 + 0x10);
    iVar2 = regulator_disable();
    if (iVar2 == 0) {
      ufs_qcom_phy_cfg_vreg(uVar6,puVar1,0);
      *(undefined1 *)(lVar4 + 0x144) = 0;
    }
    else {
      _dev_err(uVar6,"%s: %s disable failed, err=%d\n","ufs_qcom_phy_disable_vreg",*puVar1,iVar2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_ctrl_rx_linecfg @ 00101be8 size=72
// signature: undefined ufs_qcom_phy_ctrl_rx_linecfg(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_ctrl_rx_linecfg(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x188) + 0x28);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x4976a4f9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101c20);
      (*pcVar1)();
    }
    (*pcVar1)(*(long *)(param_1 + 0x98),param_2 & 1);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_get_tx_hs_equalizer @ 00101c34 size=100
// signature: undefined ufs_qcom_phy_get_tx_hs_equalizer(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_get_tx_hs_equalizer(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x188) + 0x30);
  if (pcVar3 == (code *)0x0) {
    uVar2 = 0xffffffa1;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x3cc62e74) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101c70);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
    uVar2 = 0;
    *param_3 = uVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_phy_dump_regs @ 00101c9c size=256
// signature: undefined ufs_qcom_phy_dump_regs(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_dump_regs(long param_1,uint param_2,uint param_3,undefined8 param_4)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (((param_3 | param_2) & 3) == 0) {
    uVar6 = (ulong)(int)param_3;
    lVar5 = __kmalloc(uVar6,0xdc0);
    if (lVar5 == 0) {
      uVar4 = 0xfffffff4;
    }
    else {
      if (param_3 != 0) {
        uVar7 = 0;
        uVar8 = uVar6;
        do {
          uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (long)(int)param_2 + uVar7);
          if ((((long)uVar7 < 0) || (uVar6 < uVar7)) ||
             (bVar2 = uVar8 < 4, uVar8 = uVar8 - 4, bVar2)) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(1,0x101d9c);
            (*pcVar1)();
          }
          *(undefined4 *)(lVar5 + uVar7) = uVar3;
          uVar7 = uVar7 + 4;
        } while (uVar7 < uVar6);
      }
      print_hex_dump(&DAT_00102477,param_4,(ulong)(4 < (int)param_3) << 1,0x10,4,lVar5,uVar6,0);
      kfree(lVar5);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// readl_relaxed @ 00101d9c size=124
// signature: undefined readl_relaxed(void)
// callers: [ufs_qcom_phy_save_regs, ufs_qcom_phy_dump_regs]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101de4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_phy_save_regs @ 00101e1c size=364
// signature: undefined ufs_qcom_phy_save_regs(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_save_regs(long param_1,uint param_2,uint param_3,char *param_4)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  undefined8 *puVar10;
  
  if (((param_3 | param_2) & 3) == 0) {
    plVar1 = (long *)(param_1 + 0x1a0);
    for (plVar9 = (long *)*plVar1; plVar9 != plVar1; plVar9 = (long *)*plVar9) {
      if (((char *)plVar9[2] != (char *)0x0) &&
         (iVar4 = strcmp((char *)plVar9[2],param_4), iVar4 == 0)) goto LAB_00101f1c;
    }
    lVar3 = sp_el0;
    uVar2 = *(uint *)(lVar3 + 0x44) & 0x80000;
    *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) | 0x80000;
    plVar9 = (long *)devm_kmalloc(*(undefined8 *)(param_1 + 0x10),0x28,0xb20);
    if (plVar9 != (long *)0x0) {
      lVar7 = devm_kmalloc(*(undefined8 *)(param_1 + 0x10),(long)(int)param_3,0xb20);
      plVar9[3] = lVar7;
      if (lVar7 != 0) {
        *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) & 0xfff7ffff | uVar2;
        puVar10 = *(undefined8 **)(param_1 + 0x1a8);
        plVar9[2] = (long)param_4;
        plVar9[4] = (long)(int)param_3;
        uVar8 = __list_add_valid(plVar9,puVar10,plVar1);
        if ((uVar8 & 1) != 0) {
          *(long **)(param_1 + 0x1a8) = plVar9;
          *plVar9 = (long)plVar1;
          plVar9[1] = (long)puVar10;
          *puVar10 = plVar9;
        }
LAB_00101f1c:
        if (param_3 != 0) {
          uVar8 = 0;
          do {
            uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (long)(int)param_2 + uVar8);
            *(undefined4 *)(plVar9[3] + uVar8) = uVar5;
            uVar8 = uVar8 + 4;
          } while (uVar8 < (ulong)(long)(int)param_3);
        }
        return 0;
      }
    }
    uVar6 = 0xfffffff4;
    *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) & 0xfff7ffff | uVar2;
  }
  else {
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// ufs_qcom_phy_dbg_register_dump @ 00101f8c size=68
// signature: undefined ufs_qcom_phy_dbg_register_dump(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_dbg_register_dump(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x188) + 0x38);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x3efbd9e2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101fc0);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_dbg_register_save @ 00101fd4 size=68
// signature: undefined ufs_qcom_phy_dbg_register_save(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_dbg_register_save(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x188) + 0x40);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x3efbd9e2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102008);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_cfg_vreg @ 00102018 size=240
// signature: undefined ufs_qcom_phy_cfg_vreg(void)
// callers: [ufs_qcom_phy_power_on, ufs_qcom_phy_power_off]
//------------------------------------------------------------

int ufs_qcom_phy_cfg_vreg(undefined8 param_1,undefined8 *param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  iVar3 = regulator_count_voltages(uVar2);
  if (0 < iVar3) {
    if ((param_3 & 1) == 0) {
      iVar3 = regulator_set_voltage(uVar2,0,*(undefined4 *)(param_2 + 3));
      uVar4 = 0;
      if (iVar3 != 0) goto LAB_001020b4;
    }
    else {
      iVar3 = regulator_set_voltage
                        (uVar2,*(undefined4 *)((long)param_2 + 0x14),*(undefined4 *)(param_2 + 3));
      if (iVar3 != 0) {
LAB_001020b4:
        _dev_err(param_1,"%s: %s set voltage failed, err=%d\n","ufs_qcom_phy_cfg_vreg",uVar1,iVar3);
        return iVar3;
      }
      uVar4 = *(undefined4 *)(param_2 + 2);
    }
    iVar3 = regulator_set_load(uVar2,uVar4);
    if (iVar3 < 0) {
      _dev_err(param_1,"%s: %s set optimum mode(uA_load=%d) failed, err=%d\n",
               "ufs_qcom_phy_cfg_vreg",uVar1,uVar4,iVar3);
      return iVar3;
    }
  }
  return 0;
}



//------------------------------------------------------------
// log_write_mmio @ 00104000 size=1
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
// log_post_write_mmio @ 00104008 size=1
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
// reset_control_assert @ 00104010 size=1
// signature: undefined reset_control_assert(void)
// callers: [ufs_qcom_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 00104018 size=1
// signature: undefined reset_control_deassert(void)
// callers: [ufs_qcom_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104020 size=1
// signature: undefined _dev_err(void)
// callers: [ufs_qcom_phy_init_vreg, ufs_qcom_phy_calibrate, ufs_qcom_phy_power_on, ufs_qcom_phy_init_clks, ufs_qcom_phy_generic_probe, ufs_qcom_phy_cfg_vreg, ufs_qcom_phy_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00104028 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00104030 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_phy_create @ 00104038 size=1
// signature: undefined devm_phy_create(void)
// callers: [ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_phy_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_of_phy_provider_register @ 00104048 size=1
// signature: undefined __devm_of_phy_provider_register(void)
// callers: [ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_of_phy_provider_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [ufs_qcom_phy_init_vreg, ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_no_callbacks @ 00104058 size=1
// signature: undefined pm_runtime_no_callbacks(void)
// callers: [ufs_qcom_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_no_callbacks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 00104060 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [ufs_qcom_phy_get_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00104068 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [ufs_qcom_phy_init_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00104070 size=1
// signature: undefined devm_clk_get(void)
// callers: [ufs_qcom_phy_init_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104078 size=1
// signature: undefined _printk(void)
// callers: [ufs_qcom_phy_init_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00104080 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [ufs_qcom_phy_init_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104088 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [ufs_qcom_phy_init_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00104090 size=1
// signature: undefined devm_regulator_get(void)
// callers: [ufs_qcom_phy_init_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 00104098 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [ufs_qcom_phy_init_vreg, ufs_qcom_phy_cfg_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001040a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [ufs_qcom_phy_save_regs, ufs_qcom_phy_init_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ufs_qcom_phy_init_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_parent @ 001040b0 size=1
// signature: undefined clk_set_parent(void)
// callers: [ufs_qcom_phy_set_src_clk_h8_enter, ufs_qcom_phy_set_src_clk_h8_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001040b8 size=1
// signature: undefined regulator_enable(void)
// callers: [ufs_qcom_phy_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001040c0 size=1
// signature: undefined clk_prepare(void)
// callers: [ufs_qcom_phy_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001040c8 size=1
// signature: undefined clk_enable(void)
// callers: [ufs_qcom_phy_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001040d0 size=1
// signature: undefined clk_unprepare(void)
// callers: [ufs_qcom_phy_power_on, ufs_qcom_phy_power_off, ufs_qcom_phy_disable_ref_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001040d8 size=1
// signature: undefined clk_disable(void)
// callers: [ufs_qcom_phy_power_on, ufs_qcom_phy_power_off, ufs_qcom_phy_disable_ref_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001040e0 size=1
// signature: undefined regulator_disable(void)
// callers: [ufs_qcom_phy_power_on, ufs_qcom_phy_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001040e8 size=1
// signature: undefined __kmalloc(void)
// callers: [ufs_qcom_phy_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 001040f0 size=1
// signature: undefined print_hex_dump(void)
// callers: [ufs_qcom_phy_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040f8 size=1
// signature: undefined kfree(void)
// callers: [ufs_qcom_phy_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104100 size=1
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
// log_post_read_mmio @ 00104108 size=1
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
// devm_kmalloc @ 00104110 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ufs_qcom_phy_save_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104118 size=1
// signature: undefined __list_add_valid(void)
// callers: [ufs_qcom_phy_save_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00104120 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [ufs_qcom_phy_cfg_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00104128 size=1
// signature: undefined regulator_set_load(void)
// callers: [ufs_qcom_phy_cfg_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



